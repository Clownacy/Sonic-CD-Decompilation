#include "..\EQU.H"
#include "SCR51A.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL5A.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
static void z51aline0(short** ppHscw);
static void z51aline1(short** ppHscw);
static void z51aline2(short** ppHscw);
static void z51aline3(short** ppHscw);
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

static unsigned char z81awrttbl[65] = {
  6, 6, 6, 6, 6, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 6, 6, 6, 6, 6,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4
};
static unsigned char z81awrttbl2[49];
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
extern void(*ChangeTileBmp)(int, int);
short scr_dir_tbl[6] = { 4, 0, 10903, 0, 784, 96 };
short endplpositbl[8][2] = {
  {   80,  944 },
  { 3744, 1132 },
  { 5968,  189 },
  { 2560, 1580 }
};
short playpositbl[1][2] = { { 64, 620 } };
unsigned char playmapnotbl[4] = { 127, 127, 21, 91 };
extern unsigned char mapwka[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;
extern unsigned char* zonemaptbl[];































































































void enkeichg() { /* Line 172, Address: 0x101afa0 */
  short tbl[9] = { /* Line 173, Address: 0x101afc0 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 178, Address: 0x101afec */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  if (scrflaga.b.h) return; /* Line 184, Address: 0x101b010 */



  EnkeiNo = 0; /* Line 188, Address: 0x101b020 */
  pTbl = tbl; /* Line 189, Address: 0x101b024 */

  while ((poswk = *pTbl++) >= 0) { /* Line 191, Address: 0x101b028 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 192, Address: 0x101b030 */


    ++EnkeiNo; /* Line 195, Address: 0x101b054 */
  } /* Line 196, Address: 0x101b058 */


  if (enkeino == EnkeiNo) return; /* Line 199, Address: 0x101b07c */




  enkeino = EnkeiNo; /* Line 204, Address: 0x101b090 */


  TileNo = 603; /* Line 207, Address: 0x101b09c */
  if (EnkeiNo == 1) { /* Line 208, Address: 0x101b0a0 */
    i = 84; /* Line 209, Address: 0x101b0ac */
    BmpNo = 114; /* Line 210, Address: 0x101b0b0 */
  } else { /* Line 211, Address: 0x101b0b4 */
    i = 113; /* Line 212, Address: 0x101b0bc */
    BmpNo = 0; /* Line 213, Address: 0x101b0c0 */
  }
  for ( ; i > 0; --i) { /* Line 215, Address: 0x101b0c4 */
    ChangeTileBmp(TileNo++, BmpNo++); /* Line 216, Address: 0x101b0cc */
  } /* Line 217, Address: 0x101b0ec */

  colorset2((tbl0[EnkeiNo] >> 2) + 4); /* Line 219, Address: 0x101b0f8 */
  colorset((tbl0[EnkeiNo] >> 2) + 4); /* Line 220, Address: 0x101b118 */

  mapset2((unsigned char*)mapwkb, tbl0[EnkeiNo] / 2); /* Line 222, Address: 0x101b138 */
  scrbinit(scra_h_posit.w.h, scra_v_posit.w.h); /* Line 223, Address: 0x101b170 */

  mapwrt_cnt = 1; /* Line 225, Address: 0x101b188 */
} /* Line 226, Address: 0x101b194 */












sprite_status* main_chk() {
  if (main_play == 0) /* Line 240, Address: 0x101b1c0 */
    return &actwk[0]; /* Line 241, Address: 0x101b1d4 */
  else
    return &actwk[1]; /* Line 243, Address: 0x101b1e4 */

} /* Line 245, Address: 0x101b1ec */





































void scr_set() { /* Line 283, Address: 0x101b200 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 286, Address: 0x101b20c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 287, Address: 0x101b220 */
  scr_timer.b.h = 0; /* Line 288, Address: 0x101b234 */

  pScrTbl = scr_dir_tbl; /* Line 290, Address: 0x101b23c */
  scrar_no = *pScrTbl; /* Line 291, Address: 0x101b244 */
  ++pScrTbl; /* Line 292, Address: 0x101b250 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 293, Address: 0x101b254 */
  ++pScrTbl; /* Line 294, Address: 0x101b268 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 295, Address: 0x101b26c */
  ++pScrTbl; /* Line 296, Address: 0x101b280 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 297, Address: 0x101b284 */
  ++pScrTbl; /* Line 298, Address: 0x101b298 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 299, Address: 0x101b29c */
  scra_h_keep = *pScrTbl + 576; /* Line 300, Address: 0x101b2b0 */
  ++pScrTbl; /* Line 301, Address: 0x101b2d0 */
  scra_h_count = 16; /* Line 302, Address: 0x101b2d4 */
  scra_v_count = 16; /* Line 303, Address: 0x101b2e0 */

  scra_vline = *pScrTbl; /* Line 305, Address: 0x101b2ec */
  scra_hline = 160; /* Line 306, Address: 0x101b2f8 */

  playposiset(); /* Line 308, Address: 0x101b304 */
} /* Line 309, Address: 0x101b30c */
















































static void playposiset() { /* Line 358, Address: 0x101b320 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 361, Address: 0x101b334 */
    playload(); /* Line 362, Address: 0x101b344 */
    xwk = actwk[0].xposi.w.h; /* Line 363, Address: 0x101b34c */

    if (actwk[0].yposi.w.h > 0) { /* Line 365, Address: 0x101b35c */
      ywk = actwk[0].yposi.w.h; /* Line 366, Address: 0x101b374 */
    } else { /* Line 367, Address: 0x101b384 */
      ywk = 0; /* Line 368, Address: 0x101b38c */
    }
  } /* Line 370, Address: 0x101b390 */
  else {
    if (demoflag.w & -32768) { /* Line 372, Address: 0x101b398 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 373, Address: 0x101b3b8 */
    } /* Line 374, Address: 0x101b3dc */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 376, Address: 0x101b3e4 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 380, Address: 0x101b404 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 381, Address: 0x101b418 */
  }


  if (xwk > 160) { /* Line 385, Address: 0x101b42c */
    xwk -= 160; /* Line 386, Address: 0x101b440 */
  } else { /* Line 387, Address: 0x101b44c */
    xwk = 0; /* Line 388, Address: 0x101b454 */
  }


  if (xwk > scralim_right) { /* Line 392, Address: 0x101b458 */
    xwk = scralim_right; /* Line 393, Address: 0x101b47c */
  }


  scra_h_posit.w.h = xwk; /* Line 397, Address: 0x101b48c */

  if (ywk > 96) { /* Line 399, Address: 0x101b494 */
    ywk -= 96; /* Line 400, Address: 0x101b4a8 */
  } else { /* Line 401, Address: 0x101b4b4 */
    ywk = 0; /* Line 402, Address: 0x101b4bc */
  }


  if (ywk > scralim_down) { /* Line 406, Address: 0x101b4c0 */
    ywk = scralim_down; /* Line 407, Address: 0x101b4e4 */
  }


  scra_v_posit.w.h = ywk; /* Line 411, Address: 0x101b4f4 */

  scrbinit(xwk, ywk); /* Line 413, Address: 0x101b4fc */


  loopmapno = playmapnotbl[0]; /* Line 416, Address: 0x101b50c */
  loopmapno2 = playmapnotbl[1]; /* Line 417, Address: 0x101b51c */
  ballmapno = playmapnotbl[2]; /* Line 418, Address: 0x101b52c */
  ballmapno2 = playmapnotbl[3]; /* Line 419, Address: 0x101b53c */
} /* Line 420, Address: 0x101b54c */




















static void scrbinit(short sXpos, short sYpos) { /* Line 441, Address: 0x101b570 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 444, Address: 0x101b57c */
  lYwk.w.l = 0; /* Line 445, Address: 0x101b584 */

  if (enkeino & 1) { /* Line 447, Address: 0x101b588 */
    lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 448, Address: 0x101b5a0 */
  } else { /* Line 449, Address: 0x101b5ac */
    lYwk.l = (unsigned int)lYwk.l >> 1; /* Line 450, Address: 0x101b5b4 */
    lYwk.l += (lYwk.l >> (lYwk.l + 2)) >> 3; /* Line 451, Address: 0x101b5c0 */
  }
  scrb_v_posit.l = lYwk.l; /* Line 453, Address: 0x101b5e0 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 454, Address: 0x101b5ec */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 455, Address: 0x101b5f8 */

  scrb_h_posit.w.h = (short)((unsigned short)sXpos >> 2) + sXpos; /* Line 457, Address: 0x101b604 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 459, Address: 0x101b644 */
  scrc_h_posit.w.h = sXpos; /* Line 460, Address: 0x101b660 */

  sXpos >>= 1; /* Line 462, Address: 0x101b66c */
  scrz_h_posit.w.h = sXpos; /* Line 463, Address: 0x101b678 */
} /* Line 464, Address: 0x101b684 */















void scroll() { /* Line 480, Address: 0x101b690 */
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

  if (scroll_start.b.h) return; /* Line 492, Address: 0x101b6ac */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 497, Address: 0x101b6bc */

  scrchk(); /* Line 499, Address: 0x101b6e8 */

  scroll_h(); /* Line 501, Address: 0x101b6f0 */
  scroll_v(); /* Line 502, Address: 0x101b6f8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 504, Address: 0x101b700 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 505, Address: 0x101b710 */


  lXwk = scra_hz * 64; /* Line 508, Address: 0x101b720 */
  scrollz_h(lXwk, 6); /* Line 509, Address: 0x101b734 */

  lXwk = scra_hz * 128; /* Line 511, Address: 0x101b744 */
  scrollc_h(lXwk, 4); /* Line 512, Address: 0x101b758 */

  lXwk = scra_hz * 64; /* Line 514, Address: 0x101b768 */
  lXwk += lXwk * 4; /* Line 515, Address: 0x101b77c */
  scrollb_h(lXwk, 2); /* Line 516, Address: 0x101b784 */

  lYwk = (unsigned short)scra_v_posit.w.h; /* Line 518, Address: 0x101b794 */
  if (enkeino & 1) { /* Line 519, Address: 0x101b7a4 */
    lYwk >>= 2; /* Line 520, Address: 0x101b7bc */
  } /* Line 521, Address: 0x101b7c0 */
  else {
    lYwk >>= 1; /* Line 523, Address: 0x101b7c8 */
    lYwk += (lYwk >> 2) + (lYwk >> 4); /* Line 524, Address: 0x101b7cc */
  }


  scrollb_v(lYwk); /* Line 528, Address: 0x101b7dc */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 530, Address: 0x101b7ec */
  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 531, Address: 0x101b814 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 532, Address: 0x101b84c */

  psHscw = hscrollwork; /* Line 534, Address: 0x101b860 */

  if (enkeino & 1) { /* Line 536, Address: 0x101b86c */
    z51aline2(&psHscw); /* Line 537, Address: 0x101b884 */
    z51aline3(&psHscw); /* Line 538, Address: 0x101b890 */
  } /* Line 539, Address: 0x101b89c */
  else {

    ldwk.w.l = -scrz_h_posit.w.h; /* Line 542, Address: 0x101b8a4 */




    for (i = 0; i < 8; ++i) { /* Line 547, Address: 0x101b8c4 */

      *psHscw++ = ldwk.w.l; /* Line 549, Address: 0x101b8d0 */
    } /* Line 550, Address: 0x101b8e4 */

    z51aline0(&psHscw); /* Line 552, Address: 0x101b8f4 */
    z51aline1(&psHscw); /* Line 553, Address: 0x101b900 */


    ldwk.w.l = -scrz_h_posit.w.h; /* Line 556, Address: 0x101b90c */



    for (i = 0; i < 8; ++i) { /* Line 560, Address: 0x101b92c */

      *psHscw++ = ldwk.w.l; /* Line 562, Address: 0x101b938 */
    } /* Line 563, Address: 0x101b94c */
  }


  pHscrbuf = lphscrollbuff; /* Line 567, Address: 0x101b95c */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 568, Address: 0x101b968 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 569, Address: 0x101b998 */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 570, Address: 0x101b9c8 */
} /* Line 571, Address: 0x101b9e4 */













static void z51aline0(short** ppHscw) { /* Line 585, Address: 0x101ba10 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51ascrtbl0[6] = { /* Line 590, Address: 0x101ba28 */
    13, 11, 1, 1, 1, 1
  };

  lHwk = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 594, Address: 0x101ba5c */
  lHwk = (unsigned int)lHwk * 64 / 12; /* Line 595, Address: 0x101ba80 */
  lHwk *= 1024; /* Line 596, Address: 0x101ba9c */

  ldHposwk.l = 0; /* Line 598, Address: 0x101baa0 */
  ldHposwk.w.l = scrz_h_posit.w.h; /* Line 599, Address: 0x101baa4 */

  *ppHscw += 34; /* Line 601, Address: 0x101bab0 */

  for (i = 5; i >= 0; --i) { /* Line 603, Address: 0x101bac4 */

    wk = -ldHposwk.w.l; /* Line 605, Address: 0x101bad0 */

    for (j = z51ascrtbl0[i]; j >= 0; --j) { /* Line 607, Address: 0x101baf0 */

      --*ppHscw; /* Line 609, Address: 0x101bb08 */
      **ppHscw = wk; /* Line 610, Address: 0x101bb1c */
    } /* Line 611, Address: 0x101bb28 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 613, Address: 0x101bb34 */
    ldHposwk.l += lHwk; /* Line 614, Address: 0x101bb58 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 615, Address: 0x101bb64 */
  } /* Line 616, Address: 0x101bb88 */
  *ppHscw += 34; /* Line 617, Address: 0x101bb94 */
} /* Line 618, Address: 0x101bba8 */













static void z51aline1(short** ppHscw) { /* Line 632, Address: 0x101bbd0 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51ascrtbl1[7] = { /* Line 637, Address: 0x101bbe8 */
    15, 19, 1, 1, 1, 1, 1
  };

  lHwk = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 641, Address: 0x101bc14 */
  lHwk = (unsigned int)lHwk * 64 / 14; /* Line 642, Address: 0x101bc38 */
  lHwk *= 1024; /* Line 643, Address: 0x101bc54 */

  ldHposwk.l = 0; /* Line 645, Address: 0x101bc58 */
  ldHposwk.w.l = scrz_h_posit.w.h; /* Line 646, Address: 0x101bc5c */

  for (i = 6; i >= 0; --i) { /* Line 648, Address: 0x101bc68 */

    wk = -ldHposwk.w.l; /* Line 650, Address: 0x101bc74 */

    for (j = z51ascrtbl1[i]; j >= 0; --j) { /* Line 652, Address: 0x101bc94 */

      **ppHscw = wk; /* Line 654, Address: 0x101bcac */
      ++*ppHscw; /* Line 655, Address: 0x101bcb8 */
    } /* Line 656, Address: 0x101bccc */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 658, Address: 0x101bcd8 */
    ldHposwk.l += lHwk; /* Line 659, Address: 0x101bcfc */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 660, Address: 0x101bd08 */
  } /* Line 661, Address: 0x101bd2c */
} /* Line 662, Address: 0x101bd38 */













static void z51aline2(short** ppHscw) { /* Line 676, Address: 0x101bd60 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51ascrtbl2[11] = { /* Line 681, Address: 0x101bd78 */
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
  };

  lHwk = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 685, Address: 0x101bda4 */
  lHwk = (unsigned int)lHwk * 128 / 22; /* Line 686, Address: 0x101bdc8 */
  lHwk *= 512; /* Line 687, Address: 0x101bde4 */

  ldHposwk.l = 0; /* Line 689, Address: 0x101bde8 */
  ldHposwk.w.l = scrz_h_posit.w.h; /* Line 690, Address: 0x101bdec */
  *ppHscw += 22; /* Line 691, Address: 0x101bdf8 */

  for (i = 10; i >= 0; --i) { /* Line 693, Address: 0x101be0c */

    wk = -ldHposwk.w.l; /* Line 695, Address: 0x101be18 */

    for (j = z51ascrtbl2[i]; j >= 0; --j) { /* Line 697, Address: 0x101be38 */

      --*ppHscw; /* Line 699, Address: 0x101be50 */
      **ppHscw = wk; /* Line 700, Address: 0x101be64 */
    } /* Line 701, Address: 0x101be70 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 703, Address: 0x101be7c */
    ldHposwk.l += lHwk; /* Line 704, Address: 0x101bea0 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 705, Address: 0x101beac */
  } /* Line 706, Address: 0x101bed0 */
  *ppHscw += 22; /* Line 707, Address: 0x101bedc */
} /* Line 708, Address: 0x101bef0 */













static void z51aline3(short** ppHscw) { /* Line 722, Address: 0x101bf10 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51ascrtbl3[3] = { /* Line 727, Address: 0x101bf28 */
    31, 3, 5
  };

  lHwk = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 731, Address: 0x101bf4c */
  lHwk = (unsigned int)lHwk * 64 / 12; /* Line 732, Address: 0x101bf70 */
  lHwk *= 1024; /* Line 733, Address: 0x101bf8c */

  ldHposwk.l = 0; /* Line 735, Address: 0x101bf90 */
  ldHposwk.w.l = scrz_h_posit.w.h; /* Line 736, Address: 0x101bf94 */

  for (i = 2; i >= 0; --i) { /* Line 738, Address: 0x101bfa0 */

    wk = -ldHposwk.w.l; /* Line 740, Address: 0x101bfac */

    for (j = z51ascrtbl3[i]; j >= 0; --j) { /* Line 742, Address: 0x101bfcc */

      **ppHscw = wk; /* Line 744, Address: 0x101bfe4 */
      ++*ppHscw; /* Line 745, Address: 0x101bff0 */
    } /* Line 746, Address: 0x101c004 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 748, Address: 0x101c010 */
    ldHposwk.l += lHwk; /* Line 749, Address: 0x101c034 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 750, Address: 0x101c040 */
  } /* Line 751, Address: 0x101c064 */
} /* Line 752, Address: 0x101c070 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 773, Address: 0x101c090 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 777, Address: 0x101c0ac */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 778, Address: 0x101c0b0 */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 780, Address: 0x101c0d0 */
    ldwk.w.l = *pHscrwk; /* Line 781, Address: 0x101c0ec */
    ++pHscrwk; /* Line 782, Address: 0x101c0f8 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 784, Address: 0x101c104 */
      (*pHscrbuf)->l = ldwk.l; /* Line 785, Address: 0x101c10c */
    } /* Line 786, Address: 0x101c11c */
  } /* Line 787, Address: 0x101c140 */
} /* Line 788, Address: 0x101c160 */









































































































static void scrollb_v(short yPos) { /* Line 894, Address: 0x101c180 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 897, Address: 0x101c190 */
  scrb_v_posit.w.h = yPos; /* Line 898, Address: 0x101c1a0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 899, Address: 0x101c1ac */

  if (!ywk) { /* Line 901, Address: 0x101c1e4 */
    scrb_v_count ^= 16; /* Line 902, Address: 0x101c1ec */
    if (yPos - ysv < 0) { /* Line 903, Address: 0x101c200 */
      scrflagb.b.h |= 1; /* Line 904, Address: 0x101c220 */
    } /* Line 905, Address: 0x101c234 */
    else {
      scrflagb.b.h |= 2; /* Line 907, Address: 0x101c23c */
    }
  }


} /* Line 912, Address: 0x101c250 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 930, Address: 0x101c270 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 934, Address: 0x101c284 */
  lXwk = lXsv + xoffs; /* Line 935, Address: 0x101c28c */
  scrb_h_posit.l = lXwk; /* Line 936, Address: 0x101c294 */
  ldXwk.l = lXwk; /* Line 937, Address: 0x101c29c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 938, Address: 0x101c2a0 */
  ldXwk.w.l &= 16; /* Line 939, Address: 0x101c2c4 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 940, Address: 0x101c2d0 */

  if (!ldXwk.b.b4) { /* Line 942, Address: 0x101c2ec */
    scrb_h_count ^= 16; /* Line 943, Address: 0x101c2f8 */
    if (lXwk - lXsv < 0) { /* Line 944, Address: 0x101c30c */
      scrflagb.b.h |= 1 << flgbit; /* Line 945, Address: 0x101c318 */
    } /* Line 946, Address: 0x101c33c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 948, Address: 0x101c344 */
    }
  }


} /* Line 953, Address: 0x101c36c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 971, Address: 0x101c380 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 975, Address: 0x101c394 */
  lXwk = lXsv + xoffs; /* Line 976, Address: 0x101c39c */
  scrc_h_posit.l = lXwk; /* Line 977, Address: 0x101c3a4 */
  ldXwk.l = lXwk; /* Line 978, Address: 0x101c3ac */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 979, Address: 0x101c3b0 */
  ldXwk.w.l &= 16; /* Line 980, Address: 0x101c3d4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 981, Address: 0x101c3e0 */

  if (!ldXwk.b.b4) { /* Line 983, Address: 0x101c3fc */
    scrc_h_count ^= 16; /* Line 984, Address: 0x101c408 */
    if (lXwk - lXsv < 0) { /* Line 985, Address: 0x101c41c */
      scrflagc.b.h |= 1 << flgbit; /* Line 986, Address: 0x101c428 */
    } /* Line 987, Address: 0x101c44c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 989, Address: 0x101c454 */
    }
  }


} /* Line 994, Address: 0x101c47c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 1012, Address: 0x101c490 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 1016, Address: 0x101c4a4 */
  lXwk = lXsv + xoffs; /* Line 1017, Address: 0x101c4ac */
  scrz_h_posit.l = lXwk; /* Line 1018, Address: 0x101c4b4 */
  ldXwk.l = lXwk; /* Line 1019, Address: 0x101c4bc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 1020, Address: 0x101c4c0 */
  ldXwk.w.l &= 16; /* Line 1021, Address: 0x101c4e4 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 1022, Address: 0x101c4f0 */

  if (!ldXwk.b.b4) { /* Line 1024, Address: 0x101c50c */
    scrz_h_count ^= 16; /* Line 1025, Address: 0x101c518 */
    if (lXwk - lXsv < 0) { /* Line 1026, Address: 0x101c52c */
      scrflagz.b.h |= 1 << flgbit; /* Line 1027, Address: 0x101c538 */
    } /* Line 1028, Address: 0x101c55c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 1030, Address: 0x101c564 */
    }
  }


} /* Line 1035, Address: 0x101c58c */














static void scroll_h() { /* Line 1050, Address: 0x101c5a0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 1054, Address: 0x101c5b0 */

  scrh_move(); /* Line 1056, Address: 0x101c5c0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 1057, Address: 0x101c5c8 */
  if (!bXwk) { /* Line 1058, Address: 0x101c5fc */
    scra_h_count ^= 16; /* Line 1059, Address: 0x101c604 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 1060, Address: 0x101c618 */
      scrflaga.b.h |= 4; /* Line 1061, Address: 0x101c63c */
    } else { /* Line 1062, Address: 0x101c650 */
      scrflaga.b.h |= 8; /* Line 1063, Address: 0x101c658 */
    }
  }


} /* Line 1068, Address: 0x101c66c */
















static void scrh_move() { /* Line 1085, Address: 0x101c690 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 1088, Address: 0x101c698 */
  if (xwk == 0) { /* Line 1089, Address: 0x101c6e0 */

    scra_hz = 0; /* Line 1091, Address: 0x101c6f0 */
    return; /* Line 1092, Address: 0x101c6f8 */
  } else if (xwk < 0) { /* Line 1093, Address: 0x101c700 */

    if (xwk < -16) { /* Line 1095, Address: 0x101c710 */
      xwk = -16; /* Line 1096, Address: 0x101c724 */
    }


    xwk += scra_h_posit.w.h; /* Line 1100, Address: 0x101c730 */
    if (xwk < scralim_left) { /* Line 1101, Address: 0x101c744 */
      xwk = scralim_left; /* Line 1102, Address: 0x101c768 */
    }
  } /* Line 1104, Address: 0x101c778 */
  else {
    if (xwk > 16) { /* Line 1106, Address: 0x101c780 */
      xwk = 16; /* Line 1107, Address: 0x101c794 */
    }


    xwk += scra_h_posit.w.h; /* Line 1111, Address: 0x101c7a0 */
    if (xwk > scralim_right) { /* Line 1112, Address: 0x101c7b4 */
      xwk = scralim_right; /* Line 1113, Address: 0x101c7d8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 1118, Address: 0x101c7e8 */
  scra_h_posit.w.h = xwk; /* Line 1119, Address: 0x101c818 */
} /* Line 1120, Address: 0x101c820 */














static void scroll_v() { /* Line 1135, Address: 0x101c830 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 1138, Address: 0x101c83c */
  if (actwk[0].cddat & 4) { /* Line 1139, Address: 0x101c870 */
    ywk -= 5; /* Line 1140, Address: 0x101c888 */
  }


  if (actwk[0].cddat & 2) { /* Line 1144, Address: 0x101c894 */
    ywk += 32; /* Line 1145, Address: 0x101c8ac */
    if (ywk < scra_vline) { /* Line 1146, Address: 0x101c8b8 */
      ywk -= scra_vline; /* Line 1147, Address: 0x101c8dc */
      sv_move_main2(ywk); /* Line 1148, Address: 0x101c8f0 */
      return; /* Line 1149, Address: 0x101c8fc */
    } else if (ywk >= scra_vline + 64) { /* Line 1150, Address: 0x101c904 */
      ywk -= scra_vline + 64; /* Line 1151, Address: 0x101c92c */
      sv_move_main2(ywk); /* Line 1152, Address: 0x101c954 */
      return; /* Line 1153, Address: 0x101c960 */
    }
    ywk -= scra_vline + 64; /* Line 1155, Address: 0x101c968 */
    if (!limmoveflag) goto label1; /* Line 1156, Address: 0x101c990 */
    sv_move_sub2(); /* Line 1157, Address: 0x101c9a0 */
    return; /* Line 1158, Address: 0x101c9a8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 1163, Address: 0x101c9b0 */
    sv_move_main(ywk); /* Line 1164, Address: 0x101c9dc */
    return; /* Line 1165, Address: 0x101c9e8 */
  } else if (!limmoveflag) goto label1; /* Line 1166, Address: 0x101c9f0 */
  sv_move_sub2(); /* Line 1167, Address: 0x101ca00 */
  return; /* Line 1168, Address: 0x101ca08 */



label1:
  scra_vz = 0; /* Line 1173, Address: 0x101ca10 */
} /* Line 1174, Address: 0x101ca18 */













static void sv_move_main(short yPos) { /* Line 1188, Address: 0x101ca30 */
  short spdwk;

  if (scra_vline == 96) { /* Line 1191, Address: 0x101ca40 */
    if (actwk[0].mspeed.w < 0) { /* Line 1192, Address: 0x101ca5c */
      spdwk = -actwk[0].mspeed.w; /* Line 1193, Address: 0x101ca74 */
    } else { /* Line 1194, Address: 0x101ca98 */
      spdwk = actwk[0].mspeed.w; /* Line 1195, Address: 0x101caa0 */
    }


    if (spdwk >= 2048) { /* Line 1199, Address: 0x101cab0 */
      sv_move_main2(yPos); /* Line 1200, Address: 0x101cac4 */
    } /* Line 1201, Address: 0x101cad0 */
    else {

      if (yPos > 6) { /* Line 1204, Address: 0x101cad8 */
        sv_move_plus(1536); /* Line 1205, Address: 0x101caf0 */
      } else if (yPos < -6) { /* Line 1206, Address: 0x101cafc */
        sv_move_minus(1536); /* Line 1207, Address: 0x101cb1c */
      } /* Line 1208, Address: 0x101cb28 */
      else sv_move_sub(yPos); /* Line 1209, Address: 0x101cb30 */
    }
  } /* Line 1211, Address: 0x101cb3c */
  else {
    if (yPos > 2) { /* Line 1213, Address: 0x101cb44 */
      sv_move_plus(512); /* Line 1214, Address: 0x101cb5c */
    } else if (yPos < -2) { /* Line 1215, Address: 0x101cb68 */
      sv_move_minus(512); /* Line 1216, Address: 0x101cb88 */
    } /* Line 1217, Address: 0x101cb94 */
    else sv_move_sub(yPos); /* Line 1218, Address: 0x101cb9c */
  }

} /* Line 1221, Address: 0x101cba8 */













static void sv_move_main2(short yPos) { /* Line 1235, Address: 0x101cbc0 */
  short spdwk;

  spdwk = 4096; /* Line 1238, Address: 0x101cbd0 */

  if (yPos > 16) { /* Line 1240, Address: 0x101cbdc */
    sv_move_plus(spdwk); /* Line 1241, Address: 0x101cbf4 */
  } else if (yPos < -16) { /* Line 1242, Address: 0x101cc00 */
    sv_move_minus(spdwk); /* Line 1243, Address: 0x101cc20 */
  } else { /* Line 1244, Address: 0x101cc2c */
    sv_move_sub(yPos); /* Line 1245, Address: 0x101cc34 */
  }
} /* Line 1247, Address: 0x101cc40 */














static void sv_move_sub(short yPos) { /* Line 1262, Address: 0x101cc60 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1265, Address: 0x101cc6c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1266, Address: 0x101cc70 */
  if (yPos < 0) { /* Line 1267, Address: 0x101cc9c */
    scrv_up_ch(lSpd); /* Line 1268, Address: 0x101ccb0 */
  } else { /* Line 1269, Address: 0x101ccbc */
    scrv_down_ch(lSpd); /* Line 1270, Address: 0x101ccc4 */
  }
} /* Line 1272, Address: 0x101ccd0 */



static void sv_move_sub2() { /* Line 1276, Address: 0x101cce0 */
  limmoveflag = 0; /* Line 1277, Address: 0x101cce8 */

  sv_move_sub(0); /* Line 1279, Address: 0x101ccf0 */
} /* Line 1280, Address: 0x101ccfc */













static void sv_move_minus(short speed) { /* Line 1294, Address: 0x101cd10 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1297, Address: 0x101cd1c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1298, Address: 0x101cd40 */
  scrv_up_ch(lSpd); /* Line 1299, Address: 0x101cd64 */
} /* Line 1300, Address: 0x101cd70 */














static void scrv_up_ch(int_union lSpd) { /* Line 1315, Address: 0x101cd80 */
  if (lSpd.w.l <= scralim_up) { /* Line 1316, Address: 0x101cd8c */
    if (lSpd.w.l > -256) { /* Line 1317, Address: 0x101cdb4 */

      lSpd.w.l = scralim_up; /* Line 1319, Address: 0x101cdcc */
    } else { /* Line 1320, Address: 0x101cdd8 */
      lSpd.w.l &= 2047; /* Line 1321, Address: 0x101cde0 */
      actwk[0].yposi.w.l &= 2047; /* Line 1322, Address: 0x101cdec */
      scra_v_posit.w.h &= 2047; /* Line 1323, Address: 0x101ce00 */
      scrb_v_posit.w.h &= 1023; /* Line 1324, Address: 0x101ce14 */
    }
  }

  scrv_move(lSpd); /* Line 1328, Address: 0x101ce28 */
} /* Line 1329, Address: 0x101ce34 */













static void sv_move_plus(short sSpd) { /* Line 1343, Address: 0x101ce50 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1346, Address: 0x101ce5c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1347, Address: 0x101ce7c */
  scrv_down_ch(lSpd); /* Line 1348, Address: 0x101cea0 */
} /* Line 1349, Address: 0x101ceac */














static void scrv_down_ch(int_union lSpd) { /* Line 1364, Address: 0x101cec0 */
  if (lSpd.w.l >= scralim_down) { /* Line 1365, Address: 0x101cecc */
    if (lSpd.w.l < 2048) { /* Line 1366, Address: 0x101cef4 */

      lSpd.w.l = scralim_down; /* Line 1368, Address: 0x101cf0c */
    } else { /* Line 1369, Address: 0x101cf18 */
      lSpd.w.l -= 2048; /* Line 1370, Address: 0x101cf20 */
      actwk[0].yposi.w.l &= 2047; /* Line 1371, Address: 0x101cf2c */
      scra_v_posit.w.h -= 2048; /* Line 1372, Address: 0x101cf40 */
      scrb_v_posit.w.h &= 1023; /* Line 1373, Address: 0x101cf54 */
    }
  }

  scrv_move(lSpd); /* Line 1377, Address: 0x101cf68 */
} /* Line 1378, Address: 0x101cf74 */
















static void scrv_move(int_union lSpd) { /* Line 1395, Address: 0x101cf90 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1399, Address: 0x101cfa0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1400, Address: 0x101cfb0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1401, Address: 0x101cfd4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1402, Address: 0x101cfe8 */
  scra_vz = spdwk.w.l; /* Line 1403, Address: 0x101d000 */

  scra_v_posit.l = lSpd.l; /* Line 1405, Address: 0x101d00c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1407, Address: 0x101d018 */
  if (!ywk) { /* Line 1408, Address: 0x101d054 */
    scra_v_count ^= 16; /* Line 1409, Address: 0x101d05c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1410, Address: 0x101d070 */
    if (ywk < 0) { /* Line 1411, Address: 0x101d09c */
      scrflaga.b.h |= 1; /* Line 1412, Address: 0x101d0ac */
    } else { /* Line 1413, Address: 0x101d0c0 */
      scrflaga.b.h |= 2; /* Line 1414, Address: 0x101d0c8 */
    }
  }


} /* Line 1419, Address: 0x101d0dc */

















void scrollwrt() { /* Line 1437, Address: 0x101d0f0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1446, Address: 0x101d110 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1447, Address: 0x101d114 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1448, Address: 0x101d120 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1449, Address: 0x101d12c */
  pScrFlag = &scrflagbw.b.h; /* Line 1450, Address: 0x101d134 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1451, Address: 0x101d13c */

  VramBase = 16384; /* Line 1453, Address: 0x101d150 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1454, Address: 0x101d154 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1455, Address: 0x101d160 */
  pMapWk = (unsigned char*)mapwka; /* Line 1456, Address: 0x101d16c */
  pScrFlag = &scrflagaw.b.h; /* Line 1457, Address: 0x101d174 */

  if (*pScrFlag) { /* Line 1459, Address: 0x101d17c */
    if (*pScrFlag & 1) { /* Line 1460, Address: 0x101d188 */
      *pScrFlag &= 254; /* Line 1461, Address: 0x101d19c */

      lD4.l = -16; /* Line 1463, Address: 0x101d1a8 */
      wD5 = 65520; /* Line 1464, Address: 0x101d1b0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1466, Address: 0x101d1b8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1468, Address: 0x101d1d8 */
    }




    if (*pScrFlag & 2) { /* Line 1474, Address: 0x101d204 */
      *pScrFlag &= 253; /* Line 1475, Address: 0x101d218 */

      lD4.l = 224; /* Line 1477, Address: 0x101d224 */
      wD5 = 65520; /* Line 1478, Address: 0x101d22c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1479, Address: 0x101d234 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1481, Address: 0x101d254 */
    }




    if (*pScrFlag & 4) { /* Line 1487, Address: 0x101d280 */
      *pScrFlag &= 251; /* Line 1488, Address: 0x101d294 */

      lD4.l = -16; /* Line 1490, Address: 0x101d2a0 */
      wD5 = 65520; /* Line 1491, Address: 0x101d2a8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1492, Address: 0x101d2b0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1494, Address: 0x101d2d0 */
    }




    if (*pScrFlag & 8) { /* Line 1500, Address: 0x101d2fc */
      *pScrFlag &= 247; /* Line 1501, Address: 0x101d310 */

      lD4.l = -16; /* Line 1503, Address: 0x101d31c */
      wD5 = 320; /* Line 1504, Address: 0x101d324 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1505, Address: 0x101d32c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1507, Address: 0x101d34c */
    }
  }






} /* Line 1516, Address: 0x101d378 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1533, Address: 0x101d3a0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1544, Address: 0x101d3cc */

  if (*pScrFlag & 1) { /* Line 1546, Address: 0x101d3d4 */
    *pScrFlag &= 254; /* Line 1547, Address: 0x101d3ec */
  } /* Line 1548, Address: 0x101d400 */
  else {
    *pScrFlag &= 254; /* Line 1550, Address: 0x101d408 */

    if (*pScrFlag & 2) { /* Line 1552, Address: 0x101d41c */
      *pScrFlag &= 253; /* Line 1553, Address: 0x101d434 */
      lD4.w.l = 224; /* Line 1554, Address: 0x101d448 */
    } /* Line 1555, Address: 0x101d450 */
    else {
      *pScrFlag &= 253; /* Line 1557, Address: 0x101d458 */
      goto label1; /* Line 1558, Address: 0x101d46c */
    }
  }

  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1562, Address: 0x101d474 */
  wD0 &= 127; /* Line 1563, Address: 0x101d4c4 */
  if (enkeino & 1) { /* Line 1564, Address: 0x101d4cc */

    wD0 = (z81awrttbl2 + (short)wD0)[1]; /* Line 1566, Address: 0x101d4e4 */
  } else { /* Line 1567, Address: 0x101d50c */
    wD0 = z81awrttbl[wD0 + 1]; /* Line 1568, Address: 0x101d514 */
  }





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1575, Address: 0x101d534 */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1576, Address: 0x101d554 */
  if (wD0 != 0) { /* Line 1577, Address: 0x101d578 */
    wD5 = 65520; /* Line 1578, Address: 0x101d584 */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1579, Address: 0x101d58c */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1581, Address: 0x101d5ac */



  } /* Line 1585, Address: 0x101d5d8 */
  else {

    wD5 = 0; /* Line 1588, Address: 0x101d5e0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1589, Address: 0x101d5e4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1593, Address: 0x101d604 */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1600, Address: 0x101d630 */






    lD4.l = -16; /* Line 1607, Address: 0x101d644 */
    wD5 = 65520; /* Line 1608, Address: 0x101d64c */
    if (*pScrFlag & 168) { /* Line 1609, Address: 0x101d654 */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1610, Address: 0x101d66c */
      wD5 = 320; /* Line 1611, Address: 0x101d68c */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1615, Address: 0x101d694 */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1617, Address: 0x101d6c4 */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1618, Address: 0x101d6d0 */



    for (i = 0; i < 16; ++i) { /* Line 1622, Address: 0x101d6e0 */
      if (enkeino & 1) { /* Line 1623, Address: 0x101d6ec */
        wD0 = z81awrttbl2[WrtTblCnt++]; /* Line 1624, Address: 0x101d704 */
      } else { /* Line 1625, Address: 0x101d724 */
        wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1626, Address: 0x101d72c */
      }

      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1629, Address: 0x101d74c */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1630, Address: 0x101d784 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1631, Address: 0x101d7a4 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1633, Address: 0x101d7c8 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1636, Address: 0x101d7ec */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1638, Address: 0x101d80c */
      }
      lD4.w.l += 16; /* Line 1640, Address: 0x101d820 */
    } /* Line 1641, Address: 0x101d82c */
    *pScrFlag = 0; /* Line 1642, Address: 0x101d83c */
  }
} /* Line 1644, Address: 0x101d844 */





void scrollwrtc() {} /* Line 1650, Address: 0x101d870 */




void scrollwrtz() {} /* Line 1655, Address: 0x101d880 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1673, Address: 0x101d890 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1686, Address: 0x101d8b8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1689, Address: 0x101d8d8 */
    pTilePoint->x += 2; /* Line 1690, Address: 0x101d8ec */
    if (pTilePoint->x >= 64) { /* Line 1691, Address: 0x101d900 */
      pTilePoint->x -= 64; /* Line 1692, Address: 0x101d914 */
    }
    xOffs += 16; /* Line 1694, Address: 0x101d928 */
  } while (--lpcnt >= 0); /* Line 1695, Address: 0x101d934 */
} /* Line 1696, Address: 0x101d948 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1700, Address: 0x101d960 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1704, Address: 0x101d988 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1707, Address: 0x101d9a8 */
    pTilePoint->x += 2; /* Line 1708, Address: 0x101d9bc */
    if (pTilePoint->x >= 64) { /* Line 1709, Address: 0x101d9d0 */
      pTilePoint->x -= 64; /* Line 1710, Address: 0x101d9e4 */
    }
    xOffs += 16; /* Line 1712, Address: 0x101d9f8 */
  } while (--lpcnt >= 0); /* Line 1713, Address: 0x101da04 */
} /* Line 1714, Address: 0x101da18 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1734, Address: 0x101da30 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1738, Address: 0x101da58 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1741, Address: 0x101da78 */
    pTilePoint->y += 2; /* Line 1742, Address: 0x101da8c */
    if (pTilePoint->y >= 32) { /* Line 1743, Address: 0x101da9c */
      pTilePoint->y -= 32; /* Line 1744, Address: 0x101dab0 */
    }
    yOffs += 16; /* Line 1746, Address: 0x101dac0 */
  } while (--lpcnt >= 0); /* Line 1747, Address: 0x101dacc */
} /* Line 1748, Address: 0x101dae0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1767, Address: 0x101daf0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1773, Address: 0x101db24 */

    base = 1; /* Line 1775, Address: 0x101db34 */
  } /* Line 1776, Address: 0x101db38 */
  else if (VramBase == 16384) { /* Line 1777, Address: 0x101db40 */

    base = 0; /* Line 1779, Address: 0x101db50 */
  }
  x = pTilePoint->x; /* Line 1781, Address: 0x101db54 */
  y = pTilePoint->y; /* Line 1782, Address: 0x101db5c */


  frip = BlkIndex & 6144; /* Line 1785, Address: 0x101db64 */
  BlkIndex &= 1023; /* Line 1786, Address: 0x101db6c */
  if (frip == 6144) { /* Line 1787, Address: 0x101db78 */

    p0 = 3, p1 = 2; /* Line 1789, Address: 0x101db84 */
    p2 = 1, p3 = 0; /* Line 1790, Address: 0x101db8c */
  } /* Line 1791, Address: 0x101db94 */
  else if (frip & 4096) { /* Line 1792, Address: 0x101db9c */

    p0 = 2, p1 = 3; /* Line 1794, Address: 0x101dba8 */
    p2 = 0, p3 = 1; /* Line 1795, Address: 0x101dbb0 */
  } /* Line 1796, Address: 0x101dbb8 */
  else if (frip & 2048) { /* Line 1797, Address: 0x101dbc0 */

    p0 = 1, p1 = 0; /* Line 1799, Address: 0x101dbcc */
    p2 = 3, p3 = 2; /* Line 1800, Address: 0x101dbd4 */
  } /* Line 1801, Address: 0x101dbdc */
  else {

    p0 = 0, p1 = 1; /* Line 1804, Address: 0x101dbe4 */
    p2 = 2, p3 = 3; /* Line 1805, Address: 0x101dbec */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1808, Address: 0x101dbf4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1809, Address: 0x101dc38 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1810, Address: 0x101dc7c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1811, Address: 0x101dcc0 */

} /* Line 1813, Address: 0x101dd04 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1831, Address: 0x101dd40 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1832, Address: 0x101dd60 */
} /* Line 1833, Address: 0x101dd80 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1835, Address: 0x101dd90 */
  wH_posiw = 0; /* Line 1836, Address: 0x101ddb0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1837, Address: 0x101ddb4 */
} /* Line 1838, Address: 0x101ddd4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1845, Address: 0x101ddf0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1851, Address: 0x101de20 */
  yOffs += wV_posiw; /* Line 1852, Address: 0x101de30 */





  if ((short)xOffs < 0) /* Line 1858, Address: 0x101de40 */
    xOffs = 0; /* Line 1859, Address: 0x101de5c */
  if ((short)yOffs < 0) /* Line 1860, Address: 0x101de60 */
    yOffs = 0; /* Line 1861, Address: 0x101de7c */
  if ((short)xOffs >= 16384) /* Line 1862, Address: 0x101de80 */
    xOffs = 16383; /* Line 1863, Address: 0x101dea0 */
  if ((short)yOffs >= 2048) /* Line 1864, Address: 0x101dea8 */
    yOffs = 2047; /* Line 1865, Address: 0x101dec8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1866, Address: 0x101ded0 */
  if (i < 0) i = 0; /* Line 1867, Address: 0x101df18 */

  ScreenNo = pMapWk[i] & 127; /* Line 1869, Address: 0x101df24 */

  if (ScreenNo) { /* Line 1871, Address: 0x101df40 */




    xOffs &= 32767; /* Line 1876, Address: 0x101df48 */
    yOffs &= 32767; /* Line 1877, Address: 0x101df54 */


    xBlk = xOffs; /* Line 1880, Address: 0x101df60 */
    xBlk %= 256; /* Line 1881, Address: 0x101df68 */
    xBlk /= 16; /* Line 1882, Address: 0x101df88 */
    yBlk = yOffs; /* Line 1883, Address: 0x101dfa4 */
    yBlk %= 256; /* Line 1884, Address: 0x101dfac */
    yBlk /= 16; /* Line 1885, Address: 0x101dfcc */

    lpw = pmapwk; /* Line 1887, Address: 0x101dfe8 */
    lpw += xBlk; /* Line 1888, Address: 0x101dff0 */
    lpw += yBlk * 16; /* Line 1889, Address: 0x101dff8 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1890, Address: 0x101e004 */
    *pIndex = *lpw; /* Line 1891, Address: 0x101e01c */

    return 1; /* Line 1893, Address: 0x101e02c */
  }

  *pIndex = 0; /* Line 1896, Address: 0x101e038 */
  return 0; /* Line 1897, Address: 0x101e040 */
} /* Line 1898, Address: 0x101e044 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1918, Address: 0x101e070 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1926, Address: 0x101e098 */
  if (ScreenNo) { /* Line 1927, Address: 0x101e0fc */





    xBlk = xOffs; /* Line 1933, Address: 0x101e104 */
    xBlk %= 256; /* Line 1934, Address: 0x101e10c */
    xBlk /= 16; /* Line 1935, Address: 0x101e12c */
    yBlk = yOffs; /* Line 1936, Address: 0x101e148 */
    yBlk %= 256; /* Line 1937, Address: 0x101e150 */
    yBlk /= 16; /* Line 1938, Address: 0x101e170 */


    lpw = pmapwk; /* Line 1941, Address: 0x101e18c */
    lpw += xBlk; /* Line 1942, Address: 0x101e194 */
    lpw += yBlk * 16; /* Line 1943, Address: 0x101e19c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1944, Address: 0x101e1a8 */
    *ppBlockNo = lpw; /* Line 1945, Address: 0x101e1c0 */
    *pIndex = *lpw; /* Line 1946, Address: 0x101e1c8 */




    return 1; /* Line 1951, Address: 0x101e1d8 */
  }

  *pIndex = 0; /* Line 1954, Address: 0x101e1e4 */
  return 0; /* Line 1955, Address: 0x101e1ec */
} /* Line 1956, Address: 0x101e1f0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1970, Address: 0x101e210 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1977, Address: 0x101e22c */
  pMapWk = (unsigned char*)mapwka; /* Line 1978, Address: 0x101e230 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1979, Address: 0x101e238 */
    *pBlockIndex = BlockNo; /* Line 1980, Address: 0x101e25c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1981, Address: 0x101e268 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1982, Address: 0x101e280 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1983, Address: 0x101e294 */
    }
  }


} /* Line 1988, Address: 0x101e2ac */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 2002, Address: 0x101e2d0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 2003, Address: 0x101e2dc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 2004, Address: 0x101e308 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 2005, Address: 0x101e354 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 2006, Address: 0x101e380 */

          return 0; /* Line 2008, Address: 0x101e3cc */
        }
      }
    }
  }

  return 1; /* Line 2014, Address: 0x101e3d8 */
} /* Line 2015, Address: 0x101e3dc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 2032, Address: 0x101e3f0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 2033, Address: 0x101e40c */

} /* Line 2035, Address: 0x101e428 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 2037, Address: 0x101e440 */
  wH_posiw = 0; /* Line 2038, Address: 0x101e45c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 2039, Address: 0x101e460 */

} /* Line 2041, Address: 0x101e47c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 2043, Address: 0x101e490 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 2044, Address: 0x101e4a4 */

} /* Line 2046, Address: 0x101e4c0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 2048, Address: 0x101e4d0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 2049, Address: 0x101e4ec */

} /* Line 2051, Address: 0x101e508 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 2053, Address: 0x101e520 */
  xOffs += wH_posiw; /* Line 2054, Address: 0x101e538 */
  yOffs += wV_posiw; /* Line 2055, Address: 0x101e548 */
  yOffs &= 240; /* Line 2056, Address: 0x101e558 */
  xOffs &= 496; /* Line 2057, Address: 0x101e564 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 2059, Address: 0x101e570 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 2060, Address: 0x101e59c */


} /* Line 2063, Address: 0x101e5c8 */















void mapwrt() { /* Line 2079, Address: 0x101e5e0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 2084, Address: 0x101e5f8 */
  wV_posiw = scra_v_posiw.w.h; /* Line 2085, Address: 0x101e604 */
  pMapWk = (unsigned char*)mapwka; /* Line 2086, Address: 0x101e610 */
  VramBase = 16384; /* Line 2087, Address: 0x101e618 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 2088, Address: 0x101e61c */

  mapwrtb(); /* Line 2090, Address: 0x101e634 */
} /* Line 2091, Address: 0x101e63c */



void mapwrtb() { /* Line 2095, Address: 0x101e660 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scrb_h_posiw.w.h; /* Line 2100, Address: 0x101e678 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 2101, Address: 0x101e684 */
  pMapWk = (unsigned char*)mapwkb; /* Line 2102, Address: 0x101e690 */
  VramBase = 24576; /* Line 2103, Address: 0x101e698 */
  mapwrt_z81a(pMapWk, VramBase); /* Line 2104, Address: 0x101e69c */

} /* Line 2106, Address: 0x101e6ac */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 2109, Address: 0x101e6d0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 2110, Address: 0x101e6e8 */
} /* Line 2111, Address: 0x101e708 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 2116, Address: 0x101e720 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 2120, Address: 0x101e740 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 2123, Address: 0x101e75c */



    wD4 += 16; /* Line 2127, Address: 0x101e784 */
  } while ((short)--wD6 >= 0); /* Line 2128, Address: 0x101e790 */

} /* Line 2130, Address: 0x101e7b8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 2136, Address: 0x101e7d0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 2139, Address: 0x101e7ec */
  wD6 = 15; /* Line 2140, Address: 0x101e7f4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 65520; /* Line 2143, Address: 0x101e7fc */

    if (enkeino & 1) { /* Line 2145, Address: 0x101e820 */
      mapwrt_sub(&z81awrttbl2[1], wD0, wD4, pMapWk, VramBase); /* Line 2146, Address: 0x101e838 */
    } else { /* Line 2147, Address: 0x101e858 */
      mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 2148, Address: 0x101e860 */
    }
    wD4 += 16; /* Line 2150, Address: 0x101e880 */
  } while ((short)--wD6 >= 0); /* Line 2151, Address: 0x101e888 */
} /* Line 2152, Address: 0x101e8ac */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2178, Address: 0x101e8d0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 = (short)wD0 / 16; /* Line 2183, Address: 0x101e8f8 */

  wD0 = pWrttbl[(short)wD0]; /* Line 2185, Address: 0x101e92c */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2187, Address: 0x101e954 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2188, Address: 0x101e978 */
  if (wD0) { /* Line 2189, Address: 0x101e9a0 */
    wD5 = 65520; /* Line 2190, Address: 0x101e9ac */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2191, Address: 0x101e9b4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2194, Address: 0x101e9d0 */



  } /* Line 2198, Address: 0x101e9f8 */
  else {

    wD5 = 0; /* Line 2201, Address: 0x101ea00 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2202, Address: 0x101ea04 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2206, Address: 0x101ea20 */
  }





} /* Line 2213, Address: 0x101ea48 */










void mapinit() { /* Line 2224, Address: 0x101ea70 */
  short tbl[9] = { /* Line 2225, Address: 0x101ea90 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 2230, Address: 0x101eabc */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  EnkeiNo = 0; /* Line 2236, Address: 0x101eae0 */
  pTbl = tbl; /* Line 2237, Address: 0x101eae4 */

  while ((poswk = *pTbl++) >= 0) { /* Line 2239, Address: 0x101eae8 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 2240, Address: 0x101eaf0 */


    ++EnkeiNo; /* Line 2243, Address: 0x101eb14 */
  } /* Line 2244, Address: 0x101eb18 */


  TileNo = 603; /* Line 2247, Address: 0x101eb3c */
  if (EnkeiNo == 0) { /* Line 2248, Address: 0x101eb40 */
    i = 113; /* Line 2249, Address: 0x101eb48 */
    BmpNo = 0; /* Line 2250, Address: 0x101eb4c */

    for ( ; i > 0; --i) { /* Line 2252, Address: 0x101eb50 */
      ChangeTileBmp(TileNo++, BmpNo++); /* Line 2253, Address: 0x101eb58 */
    } /* Line 2254, Address: 0x101eb78 */
  }


  colorset2(mapinittbl.colorno2); /* Line 2258, Address: 0x101eb84 */
  colorset(mapinittbl.colorno2); /* Line 2259, Address: 0x101eb98 */


  if (play_start & 2) divdevset(); /* Line 2262, Address: 0x101ebac */
} /* Line 2263, Address: 0x101ebcc */




void mapset() {} /* Line 2268, Address: 0x101ec00 */



void divdevset() {} /* Line 2272, Address: 0x101ec10 */



void enecginit() {} /* Line 2276, Address: 0x101ec20 */















static void mapset2(unsigned char* pMapDst, int idx) { /* Line 2292, Address: 0x101ec30 */
  int h, v, hwk;
  unsigned char *pZonetbl, *pMapwk;

  pZonetbl = zonemaptbl[idx]; /* Line 2296, Address: 0x101ec50 */
  h = *pZonetbl++; /* Line 2297, Address: 0x101ec68 */
  v = *pZonetbl++; /* Line 2298, Address: 0x101ec78 */
  for ( ;v >= 0; --v) { /* Line 2299, Address: 0x101ec88 */
    pMapwk = pMapDst; /* Line 2300, Address: 0x101ec90 */

    for (hwk = h; hwk >= 0; --hwk) { /* Line 2302, Address: 0x101ec94 */
      *pMapwk++ = *pZonetbl++; /* Line 2303, Address: 0x101eca0 */
    } /* Line 2304, Address: 0x101ecb8 */

    pMapDst += 64; /* Line 2306, Address: 0x101ecc4 */
  } /* Line 2307, Address: 0x101ecd0 */
} /* Line 2308, Address: 0x101ecdc */
