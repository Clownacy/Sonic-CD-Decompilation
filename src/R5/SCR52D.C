#include "..\EQU.H"
#include "SCR51A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL5A.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
static void z51dline(short** ppHscw);
static void z51dline0(short** ppHscw);
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
short playpositbl[1][2] = { { 64, 364 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;
extern unsigned char* zonemaptbl[];





























































































void enkeichg() { /* Line 152, Address: 0x1028870 */
  short tbl[6] = { /* Line 153, Address: 0x1028890 */
    3584, 7168, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 157, Address: 0x10288c4 */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  if (scrflaga.b.h) return; /* Line 163, Address: 0x10288e8 */



  EnkeiNo = 0; /* Line 167, Address: 0x10288f8 */
  pTbl = tbl; /* Line 168, Address: 0x10288fc */

  while ((poswk = *pTbl++) >= 0) { /* Line 170, Address: 0x1028900 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 171, Address: 0x1028908 */


    ++EnkeiNo; /* Line 174, Address: 0x102892c */
  } /* Line 175, Address: 0x1028930 */


  if (enkeino == EnkeiNo) return; /* Line 178, Address: 0x1028954 */




  enkeino = EnkeiNo; /* Line 183, Address: 0x1028968 */


  TileNo = 597; /* Line 186, Address: 0x1028974 */
  if (EnkeiNo == 1) { /* Line 187, Address: 0x1028978 */
    i = 88; /* Line 188, Address: 0x1028984 */
    BmpNo = 96; /* Line 189, Address: 0x1028988 */
  } else { /* Line 190, Address: 0x102898c */
    i = 96; /* Line 191, Address: 0x1028994 */
    BmpNo = 0; /* Line 192, Address: 0x1028998 */
  }
  for ( ; i > 0; --i) { /* Line 194, Address: 0x102899c */
    ChangeTileBmp(TileNo++, BmpNo++); /* Line 195, Address: 0x10289a4 */
  } /* Line 196, Address: 0x10289c4 */

  colorset2((tbl0[EnkeiNo] >> 2) + 4); /* Line 198, Address: 0x10289d0 */
  colorset((tbl0[EnkeiNo] >> 2) + 4); /* Line 199, Address: 0x10289f0 */

  mapset2((unsigned char*)mapwkb, tbl0[EnkeiNo] / 2); /* Line 201, Address: 0x1028a10 */
  scrbinit(scra_h_posit.w.h, scra_v_posit.w.h); /* Line 202, Address: 0x1028a48 */
  mapwrt_cnt = 1; /* Line 203, Address: 0x1028a60 */
} /* Line 204, Address: 0x1028a6c */












sprite_status* main_chk() {
  if (main_play == 0) /* Line 218, Address: 0x1028aa0 */
    return &actwk[0]; /* Line 219, Address: 0x1028ab4 */
  else
    return &actwk[1]; /* Line 221, Address: 0x1028ac4 */

} /* Line 223, Address: 0x1028acc */





































void scr_set() { /* Line 261, Address: 0x1028ae0 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 264, Address: 0x1028aec */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 265, Address: 0x1028b00 */
  scr_timer.b.h = 0; /* Line 266, Address: 0x1028b14 */

  pScrTbl = scr_dir_tbl; /* Line 268, Address: 0x1028b1c */
  scrar_no = *pScrTbl; /* Line 269, Address: 0x1028b24 */
  ++pScrTbl; /* Line 270, Address: 0x1028b30 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 271, Address: 0x1028b34 */
  ++pScrTbl; /* Line 272, Address: 0x1028b48 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 273, Address: 0x1028b4c */
  ++pScrTbl; /* Line 274, Address: 0x1028b60 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 275, Address: 0x1028b64 */
  ++pScrTbl; /* Line 276, Address: 0x1028b78 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 277, Address: 0x1028b7c */
  scra_h_keep = *pScrTbl + 576; /* Line 278, Address: 0x1028b90 */
  ++pScrTbl; /* Line 279, Address: 0x1028bb0 */
  scra_h_count = 16; /* Line 280, Address: 0x1028bb4 */
  scra_v_count = 16; /* Line 281, Address: 0x1028bc0 */

  scra_vline = *pScrTbl; /* Line 283, Address: 0x1028bcc */
  scra_hline = 160; /* Line 284, Address: 0x1028bd8 */

  playposiset(); /* Line 286, Address: 0x1028be4 */
} /* Line 287, Address: 0x1028bec */






































static void playposiset() { /* Line 326, Address: 0x1028c00 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 329, Address: 0x1028c14 */
    playload(); /* Line 330, Address: 0x1028c24 */
    xwk = actwk[0].xposi.w.h; /* Line 331, Address: 0x1028c2c */

    if (actwk[0].yposi.w.h > 0) { /* Line 333, Address: 0x1028c3c */
      ywk = actwk[0].yposi.w.h; /* Line 334, Address: 0x1028c54 */
    } else { /* Line 335, Address: 0x1028c64 */
      ywk = 0; /* Line 336, Address: 0x1028c6c */
    }
  } /* Line 338, Address: 0x1028c70 */
  else {
    pPositbl = playpositbl[0]; /* Line 340, Address: 0x1028c78 */


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 343, Address: 0x1028c80 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 344, Address: 0x1028c94 */
  }


  if (xwk > 160) { /* Line 348, Address: 0x1028ca8 */
    xwk -= 160; /* Line 349, Address: 0x1028cbc */
  } else { /* Line 350, Address: 0x1028cc8 */
    xwk = 0; /* Line 351, Address: 0x1028cd0 */
  }


  if (xwk > scralim_right) { /* Line 355, Address: 0x1028cd4 */
    xwk = scralim_right; /* Line 356, Address: 0x1028cf8 */
  }


  scra_h_posit.w.h = xwk; /* Line 360, Address: 0x1028d08 */

  if (ywk > 96) { /* Line 362, Address: 0x1028d10 */
    ywk -= 96; /* Line 363, Address: 0x1028d24 */
  } else { /* Line 364, Address: 0x1028d30 */
    ywk = 0; /* Line 365, Address: 0x1028d38 */
  }


  if (ywk > scralim_down) { /* Line 369, Address: 0x1028d3c */
    ywk = scralim_down; /* Line 370, Address: 0x1028d60 */
  }


  scra_v_posit.w.h = ywk; /* Line 374, Address: 0x1028d70 */

  scrbinit(xwk, ywk); /* Line 376, Address: 0x1028d78 */


  loopmapno = playmapnotbl[0]; /* Line 379, Address: 0x1028d88 */
  loopmapno2 = playmapnotbl[1]; /* Line 380, Address: 0x1028d98 */
  ballmapno = playmapnotbl[2]; /* Line 381, Address: 0x1028da8 */
  ballmapno2 = playmapnotbl[3]; /* Line 382, Address: 0x1028db8 */
} /* Line 383, Address: 0x1028dc8 */




















static void scrbinit(short sXpos, short sYpos) { /* Line 404, Address: 0x1028df0 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 407, Address: 0x1028dfc */
  lYwk.w.l = 0; /* Line 408, Address: 0x1028e04 */

  lYwk.l = (unsigned int)lYwk.l >> 3; /* Line 410, Address: 0x1028e08 */
  lYwk.l += (lYwk.l >> 2) * 3; /* Line 411, Address: 0x1028e14 */

  scrb_v_posit.l = lYwk.l; /* Line 413, Address: 0x1028e30 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 414, Address: 0x1028e3c */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 415, Address: 0x1028e48 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 417, Address: 0x1028e54 */
  scrb_h_posit.w.h = sXpos; /* Line 418, Address: 0x1028e70 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 420, Address: 0x1028e7c */
  scrc_h_posit.w.h = sXpos; /* Line 421, Address: 0x1028e98 */

  sXpos >>= 1; /* Line 423, Address: 0x1028ea4 */
  scrz_h_posit.w.h = sXpos; /* Line 424, Address: 0x1028eb0 */
} /* Line 425, Address: 0x1028ebc */















void scroll() { /* Line 441, Address: 0x1028ed0 */
  int_union ldwk;
  int_union* pHscrbuf;
  int_union ldwk2, ldwk3;
  int i;
  int lXwk, lYwk;
  short sYnum;
  short *psHscr, *psHscw;
  short sYline, sYnumsv;
  static int scaddtbl[5] = { 65536, 57344, 49152, 40960, 32768 };
  static unsigned char z12c_cnttbl[5] = { 1, 3, 3, 3, 1 };

  if (scroll_start.b.h) return; /* Line 453, Address: 0x1028ef4 */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 458, Address: 0x1028f04 */

  scrchk(); /* Line 460, Address: 0x1028f30 */

  scroll_h(); /* Line 462, Address: 0x1028f38 */
  scroll_v(); /* Line 463, Address: 0x1028f40 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 465, Address: 0x1028f48 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 466, Address: 0x1028f58 */


  lXwk = scra_hz * 32; /* Line 469, Address: 0x1028f68 */
  scrollz_h(lXwk, 6); /* Line 470, Address: 0x1028f7c */

  lXwk = scra_hz * 64; /* Line 472, Address: 0x1028f8c */
  scrollc_h(lXwk, 4); /* Line 473, Address: 0x1028fa0 */

  lXwk = scra_hz * 128; /* Line 475, Address: 0x1028fb0 */
  scrollb_h(lXwk, 2); /* Line 476, Address: 0x1028fc4 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 3; /* Line 478, Address: 0x1028fd4 */
  lYwk += (lYwk >> 2) * 3; /* Line 479, Address: 0x1028fe8 */


  scrollb_v(lYwk); /* Line 482, Address: 0x1028ff8 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 484, Address: 0x1029008 */
  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 485, Address: 0x1029030 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 486, Address: 0x1029068 */

  psHscw = hscrollwork; /* Line 488, Address: 0x102907c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 489, Address: 0x1029088 */

  if (enkeino & 1) { /* Line 491, Address: 0x10290a8 */

    ldwk.w.l = -scrc_h_posit.w.h; /* Line 493, Address: 0x10290c0 */
    for (i = 0; i < 11; ++i) { /* Line 494, Address: 0x10290e0 */

      *psHscw++ = ldwk.w.l; /* Line 496, Address: 0x10290ec */
    } /* Line 497, Address: 0x1029100 */
    z51dline0(&psHscw); /* Line 498, Address: 0x1029110 */
  } /* Line 499, Address: 0x102911c */
  else {
    z51dline(&psHscw); /* Line 501, Address: 0x1029124 */













    ldwk.w.l = -scrb_h_posit.w.h; /* Line 515, Address: 0x1029130 */
    for (i = 0; i < 16; ++i) { /* Line 516, Address: 0x1029150 */
      *psHscw++ = ldwk.w.l; /* Line 517, Address: 0x102915c */
    } /* Line 518, Address: 0x1029170 */
  }


  pHscrbuf = lphscrollbuff; /* Line 522, Address: 0x1029180 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 523, Address: 0x102918c */
  sYline = 39; /* Line 524, Address: 0x10291bc */
  sYnumsv = 29; /* Line 525, Address: 0x10291c8 */
  if (enkeino & 1) { /* Line 526, Address: 0x10291d4 */

    sYline = 28; /* Line 528, Address: 0x10291ec */

    sYnumsv -= sYline; /* Line 530, Address: 0x10291f8 */
    psHscr = &hscrollwork[sYnum / 2]; /* Line 531, Address: 0x1029204 */
    zonescrsetsub0(scrb_v_posit.w.h, sYline, &pHscrbuf, psHscr); /* Line 532, Address: 0x1029234 */
  } else { /* Line 533, Address: 0x1029250 */
    if (sYline >= sYnum >> 1) { /* Line 534, Address: 0x1029258 */
      sYline -= sYnum >> 1; /* Line 535, Address: 0x1029278 */

      if (sYline > 28) { /* Line 537, Address: 0x1029298 */
        sYline = 28; /* Line 538, Address: 0x10292ac */
      }


      sYnumsv -= sYline; /* Line 542, Address: 0x10292b8 */
      psHscr = &hscrollwork[sYnum / 2]; /* Line 543, Address: 0x10292c4 */
      zonescrsetsub0(scrb_v_posit.w.h, sYline, &pHscrbuf, psHscr); /* Line 544, Address: 0x10292f4 */
    }
  }



  if (!(enkeino & 1)) { /* Line 550, Address: 0x1029310 */
    ldwk.w.l = scrb_h_posit.w.h; /* Line 551, Address: 0x1029328 */
    ldwk2.w.l = scra_h_posit.w.h; /* Line 552, Address: 0x1029334 */
    ldwk2.w.l -= ldwk.w.l; /* Line 553, Address: 0x1029340 */
    ldwk2.l = ldwk2.w.l * 256 / 256 * 256; /* Line 554, Address: 0x1029350 */
    ldwk3.l = 0; /* Line 555, Address: 0x1029380 */
    ldwk3.w.l = ldwk.w.l; /* Line 556, Address: 0x1029384 */

    for (sYnumsv = (sYnumsv << 3) - 1; sYnumsv >= 0; --sYnumsv) { /* Line 558, Address: 0x102938c */

      ldwk.w.l = -ldwk3.w.l; /* Line 560, Address: 0x10293b4 */
      pHscrbuf->l = ldwk.l; /* Line 561, Address: 0x10293d0 */
      ++pHscrbuf; /* Line 562, Address: 0x10293dc */
      ldwk3.l = (unsigned int)ldwk3.l >> 16 & 65535 | ldwk3.l << 16 & -65536; /* Line 563, Address: 0x10293e8 */
      ldwk3.l += ldwk2.l; /* Line 564, Address: 0x102940c */
      ldwk3.l = (unsigned int)ldwk3.l >> 16 & 65535 | ldwk3.l << 16 & -65536; /* Line 565, Address: 0x102941c */
    } /* Line 566, Address: 0x1029440 */
  }


} /* Line 570, Address: 0x102945c */













static void z51dline(short** ppHscw) { /* Line 584, Address: 0x1029490 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51dscrtbl[3] = { /* Line 589, Address: 0x10294a8 */
    5, 11, 5
  };

  lHwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 593, Address: 0x10294cc */
  lHwk = (unsigned int)lHwk * 64 / 6; /* Line 594, Address: 0x10294f0 */
  lHwk *= 1024; /* Line 595, Address: 0x102950c */

  ldHposwk.l = 0; /* Line 597, Address: 0x1029510 */
  ldHposwk.w.l = scrb_h_posit.w.h; /* Line 598, Address: 0x1029514 */
  *ppHscw += 24; /* Line 599, Address: 0x1029520 */

  for (i = 2; i >= 0; --i) { /* Line 601, Address: 0x1029534 */

    wk = -ldHposwk.w.l; /* Line 603, Address: 0x1029540 */

    for (j = z51dscrtbl[i]; j >= 0; --j) { /* Line 605, Address: 0x1029560 */

      --*ppHscw; /* Line 607, Address: 0x1029578 */
      **ppHscw = wk; /* Line 608, Address: 0x102958c */
    } /* Line 609, Address: 0x1029598 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 611, Address: 0x10295a4 */
    ldHposwk.l += lHwk; /* Line 612, Address: 0x10295c8 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 613, Address: 0x10295d4 */
  } /* Line 614, Address: 0x10295f8 */

  *ppHscw += 24; /* Line 616, Address: 0x1029604 */
} /* Line 617, Address: 0x1029618 */













static void z51dline0(short** ppHscw) { /* Line 631, Address: 0x1029640 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51dscrtbl0[6] = { /* Line 636, Address: 0x1029658 */
    13, 7, 5, 3, 3, 0
  };

  lHwk = scra_h_posit.w.h - scrc_h_posit.w.h; /* Line 640, Address: 0x102968c */
  lHwk = (unsigned int)lHwk * 128 / 12; /* Line 641, Address: 0x10296b0 */
  lHwk *= 512; /* Line 642, Address: 0x10296cc */

  ldHposwk.l = 0; /* Line 644, Address: 0x10296d0 */
  ldHposwk.w.l = scrc_h_posit.w.h; /* Line 645, Address: 0x10296d4 */

  for (i = 5; i >= 0; --i) { /* Line 647, Address: 0x10296e0 */

    wk = -ldHposwk.w.l; /* Line 649, Address: 0x10296ec */

    for (j = z51dscrtbl0[i]; j >= 0; --j) { /* Line 651, Address: 0x102970c */

      **ppHscw = wk; /* Line 653, Address: 0x1029724 */
      ++*ppHscw; /* Line 654, Address: 0x1029730 */
    } /* Line 655, Address: 0x1029744 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 657, Address: 0x1029750 */
    ldHposwk.l += lHwk; /* Line 658, Address: 0x1029774 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 659, Address: 0x1029780 */
  } /* Line 660, Address: 0x10297a4 */
} /* Line 661, Address: 0x10297b0 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 682, Address: 0x10297d0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 686, Address: 0x10297ec */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 688, Address: 0x10297f0 */
    ldwk.w.l = *pHscrwk; /* Line 689, Address: 0x102980c */
    ++pHscrwk; /* Line 690, Address: 0x1029818 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 692, Address: 0x1029824 */
      (*pHscrbuf)->l = ldwk.l; /* Line 693, Address: 0x102982c */
    } /* Line 694, Address: 0x102983c */
  } /* Line 695, Address: 0x1029860 */
} /* Line 696, Address: 0x1029880 */









































































































static void scrollb_v(short yPos) { /* Line 802, Address: 0x10298a0 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 805, Address: 0x10298b0 */
  scrb_v_posit.w.h = yPos; /* Line 806, Address: 0x10298c0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 807, Address: 0x10298cc */

  if (!ywk) { /* Line 809, Address: 0x1029904 */
    scrb_v_count ^= 16; /* Line 810, Address: 0x102990c */
    if (yPos - ysv < 0) { /* Line 811, Address: 0x1029920 */
      scrflagb.b.h |= 1; /* Line 812, Address: 0x1029940 */
    } /* Line 813, Address: 0x1029954 */
    else {
      scrflagb.b.h |= 2; /* Line 815, Address: 0x102995c */
    }
  }


} /* Line 820, Address: 0x1029970 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 838, Address: 0x1029990 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 842, Address: 0x10299a4 */
  lXwk = lXsv + xoffs; /* Line 843, Address: 0x10299ac */
  scrb_h_posit.l = lXwk; /* Line 844, Address: 0x10299b4 */
  ldXwk.l = lXwk; /* Line 845, Address: 0x10299bc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 846, Address: 0x10299c0 */
  ldXwk.w.l &= 16; /* Line 847, Address: 0x10299e4 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 848, Address: 0x10299f0 */

  if (!ldXwk.b.b4) { /* Line 850, Address: 0x1029a0c */
    scrb_h_count ^= 16; /* Line 851, Address: 0x1029a18 */
    if (lXwk - lXsv < 0) { /* Line 852, Address: 0x1029a2c */
      scrflagb.b.h |= 1 << flgbit; /* Line 853, Address: 0x1029a38 */
    } /* Line 854, Address: 0x1029a5c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 856, Address: 0x1029a64 */
    }
  }


} /* Line 861, Address: 0x1029a8c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 879, Address: 0x1029aa0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 883, Address: 0x1029ab4 */
  lXwk = lXsv + xoffs; /* Line 884, Address: 0x1029abc */
  scrc_h_posit.l = lXwk; /* Line 885, Address: 0x1029ac4 */
  ldXwk.l = lXwk; /* Line 886, Address: 0x1029acc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 887, Address: 0x1029ad0 */
  ldXwk.w.l &= 16; /* Line 888, Address: 0x1029af4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 889, Address: 0x1029b00 */

  if (!ldXwk.b.b4) { /* Line 891, Address: 0x1029b1c */
    scrc_h_count ^= 16; /* Line 892, Address: 0x1029b28 */
    if (lXwk - lXsv < 0) { /* Line 893, Address: 0x1029b3c */
      scrflagc.b.h |= 1 << flgbit; /* Line 894, Address: 0x1029b48 */
    } /* Line 895, Address: 0x1029b6c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 897, Address: 0x1029b74 */
    }
  }


} /* Line 902, Address: 0x1029b9c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 920, Address: 0x1029bb0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 924, Address: 0x1029bc4 */
  lXwk = lXsv + xoffs; /* Line 925, Address: 0x1029bcc */
  scrz_h_posit.l = lXwk; /* Line 926, Address: 0x1029bd4 */
  ldXwk.l = lXwk; /* Line 927, Address: 0x1029bdc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 928, Address: 0x1029be0 */
  ldXwk.w.l &= 16; /* Line 929, Address: 0x1029c04 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 930, Address: 0x1029c10 */

  if (!ldXwk.b.b4) { /* Line 932, Address: 0x1029c2c */
    scrz_h_count ^= 16; /* Line 933, Address: 0x1029c38 */
    if (lXwk - lXsv < 0) { /* Line 934, Address: 0x1029c4c */
      scrflagz.b.h |= 1 << flgbit; /* Line 935, Address: 0x1029c58 */
    } /* Line 936, Address: 0x1029c7c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 938, Address: 0x1029c84 */
    }
  }


} /* Line 943, Address: 0x1029cac */














static void scroll_h() { /* Line 958, Address: 0x1029cc0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 962, Address: 0x1029cd0 */

  scrh_move(); /* Line 964, Address: 0x1029ce0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 965, Address: 0x1029ce8 */
  if (!bXwk) { /* Line 966, Address: 0x1029d1c */
    scra_h_count ^= 16; /* Line 967, Address: 0x1029d24 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 968, Address: 0x1029d38 */
      scrflaga.b.h |= 4; /* Line 969, Address: 0x1029d5c */
    } else { /* Line 970, Address: 0x1029d70 */
      scrflaga.b.h |= 8; /* Line 971, Address: 0x1029d78 */
    }
  }


} /* Line 976, Address: 0x1029d8c */
















static void scrh_move() { /* Line 993, Address: 0x1029db0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 996, Address: 0x1029db8 */
  if (xwk == 0) { /* Line 997, Address: 0x1029e00 */

    scra_hz = 0; /* Line 999, Address: 0x1029e10 */
    return; /* Line 1000, Address: 0x1029e18 */
  } else if (xwk < 0) { /* Line 1001, Address: 0x1029e20 */

    if (xwk < -16) { /* Line 1003, Address: 0x1029e30 */
      xwk = -16; /* Line 1004, Address: 0x1029e44 */
    }


    xwk += scra_h_posit.w.h; /* Line 1008, Address: 0x1029e50 */
    if (xwk < scralim_left) { /* Line 1009, Address: 0x1029e64 */
      xwk = scralim_left; /* Line 1010, Address: 0x1029e88 */
    }
  } /* Line 1012, Address: 0x1029e98 */
  else {
    if (xwk > 16) { /* Line 1014, Address: 0x1029ea0 */
      xwk = 16; /* Line 1015, Address: 0x1029eb4 */
    }


    xwk += scra_h_posit.w.h; /* Line 1019, Address: 0x1029ec0 */
    if (xwk > scralim_right) { /* Line 1020, Address: 0x1029ed4 */
      xwk = scralim_right; /* Line 1021, Address: 0x1029ef8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 1026, Address: 0x1029f08 */
  scra_h_posit.w.h = xwk; /* Line 1027, Address: 0x1029f38 */
} /* Line 1028, Address: 0x1029f40 */














static void scroll_v() { /* Line 1043, Address: 0x1029f50 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 1046, Address: 0x1029f5c */
  if (actwk[0].cddat & 4) { /* Line 1047, Address: 0x1029f90 */
    ywk -= 5; /* Line 1048, Address: 0x1029fa8 */
  }


  if (actwk[0].cddat & 2) { /* Line 1052, Address: 0x1029fb4 */
    ywk += 32; /* Line 1053, Address: 0x1029fcc */
    if (ywk < scra_vline) { /* Line 1054, Address: 0x1029fd8 */
      ywk -= scra_vline; /* Line 1055, Address: 0x1029ffc */
      sv_move_main2(ywk); /* Line 1056, Address: 0x102a010 */
      return; /* Line 1057, Address: 0x102a01c */
    } else if (ywk >= scra_vline + 64) { /* Line 1058, Address: 0x102a024 */
      ywk -= scra_vline + 64; /* Line 1059, Address: 0x102a04c */
      sv_move_main2(ywk); /* Line 1060, Address: 0x102a074 */
      return; /* Line 1061, Address: 0x102a080 */
    }
    ywk -= scra_vline + 64; /* Line 1063, Address: 0x102a088 */
    if (!limmoveflag) goto label1; /* Line 1064, Address: 0x102a0b0 */
    sv_move_sub2(); /* Line 1065, Address: 0x102a0c0 */
    return; /* Line 1066, Address: 0x102a0c8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 1071, Address: 0x102a0d0 */
    sv_move_main(ywk); /* Line 1072, Address: 0x102a0fc */
    return; /* Line 1073, Address: 0x102a108 */
  } else if (!limmoveflag) goto label1; /* Line 1074, Address: 0x102a110 */
  sv_move_sub2(); /* Line 1075, Address: 0x102a120 */
  return; /* Line 1076, Address: 0x102a128 */



label1:
  scra_vz = 0; /* Line 1081, Address: 0x102a130 */
} /* Line 1082, Address: 0x102a138 */













static void sv_move_main(short yPos) { /* Line 1096, Address: 0x102a150 */
  short spdwk;

  if (scra_vline == 96) { /* Line 1099, Address: 0x102a160 */
    if (actwk[0].mspeed.w < 0) { /* Line 1100, Address: 0x102a17c */
      spdwk = -actwk[0].mspeed.w; /* Line 1101, Address: 0x102a194 */
    } else { /* Line 1102, Address: 0x102a1b8 */
      spdwk = actwk[0].mspeed.w; /* Line 1103, Address: 0x102a1c0 */
    }


    if (spdwk >= 2048) { /* Line 1107, Address: 0x102a1d0 */
      sv_move_main2(yPos); /* Line 1108, Address: 0x102a1e4 */
    } /* Line 1109, Address: 0x102a1f0 */
    else {

      if (yPos > 6) { /* Line 1112, Address: 0x102a1f8 */
        sv_move_plus(1536); /* Line 1113, Address: 0x102a210 */
      } else if (yPos < -6) { /* Line 1114, Address: 0x102a21c */
        sv_move_minus(1536); /* Line 1115, Address: 0x102a23c */
      } /* Line 1116, Address: 0x102a248 */
      else sv_move_sub(yPos); /* Line 1117, Address: 0x102a250 */
    }
  } /* Line 1119, Address: 0x102a25c */
  else {
    if (yPos > 2) { /* Line 1121, Address: 0x102a264 */
      sv_move_plus(512); /* Line 1122, Address: 0x102a27c */
    } else if (yPos < -2) { /* Line 1123, Address: 0x102a288 */
      sv_move_minus(512); /* Line 1124, Address: 0x102a2a8 */
    } /* Line 1125, Address: 0x102a2b4 */
    else sv_move_sub(yPos); /* Line 1126, Address: 0x102a2bc */
  }

} /* Line 1129, Address: 0x102a2c8 */













static void sv_move_main2(short yPos) { /* Line 1143, Address: 0x102a2e0 */
  short spdwk;

  spdwk = 4096; /* Line 1146, Address: 0x102a2f0 */

  if (yPos > 16) { /* Line 1148, Address: 0x102a2fc */
    sv_move_plus(spdwk); /* Line 1149, Address: 0x102a314 */
  } else if (yPos < -16) { /* Line 1150, Address: 0x102a320 */
    sv_move_minus(spdwk); /* Line 1151, Address: 0x102a340 */
  } else { /* Line 1152, Address: 0x102a34c */
    sv_move_sub(yPos); /* Line 1153, Address: 0x102a354 */
  }
} /* Line 1155, Address: 0x102a360 */














static void sv_move_sub(short yPos) { /* Line 1170, Address: 0x102a380 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1173, Address: 0x102a38c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1174, Address: 0x102a390 */
  if (yPos < 0) { /* Line 1175, Address: 0x102a3bc */
    scrv_up_ch(lSpd); /* Line 1176, Address: 0x102a3d0 */
  } else { /* Line 1177, Address: 0x102a3dc */
    scrv_down_ch(lSpd); /* Line 1178, Address: 0x102a3e4 */
  }
} /* Line 1180, Address: 0x102a3f0 */



static void sv_move_sub2() { /* Line 1184, Address: 0x102a400 */
  limmoveflag = 0; /* Line 1185, Address: 0x102a408 */

  sv_move_sub(0); /* Line 1187, Address: 0x102a410 */
} /* Line 1188, Address: 0x102a41c */













static void sv_move_minus(short speed) { /* Line 1202, Address: 0x102a430 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1205, Address: 0x102a43c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1206, Address: 0x102a460 */
  scrv_up_ch(lSpd); /* Line 1207, Address: 0x102a484 */
} /* Line 1208, Address: 0x102a490 */














static void scrv_up_ch(int_union lSpd) { /* Line 1223, Address: 0x102a4a0 */
  if (lSpd.w.l <= scralim_up) { /* Line 1224, Address: 0x102a4ac */
    if (lSpd.w.l > -256) { /* Line 1225, Address: 0x102a4d4 */

      lSpd.w.l = scralim_up; /* Line 1227, Address: 0x102a4ec */
    } else { /* Line 1228, Address: 0x102a4f8 */
      lSpd.w.l &= 2047; /* Line 1229, Address: 0x102a500 */
      actwk[0].yposi.w.l &= 2047; /* Line 1230, Address: 0x102a50c */
      scra_v_posit.w.h &= 2047; /* Line 1231, Address: 0x102a520 */
      scrb_v_posit.w.h &= 1023; /* Line 1232, Address: 0x102a534 */
    }
  }

  scrv_move(lSpd); /* Line 1236, Address: 0x102a548 */
} /* Line 1237, Address: 0x102a554 */













static void sv_move_plus(short sSpd) { /* Line 1251, Address: 0x102a570 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1254, Address: 0x102a57c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1255, Address: 0x102a59c */
  scrv_down_ch(lSpd); /* Line 1256, Address: 0x102a5c0 */
} /* Line 1257, Address: 0x102a5cc */














static void scrv_down_ch(int_union lSpd) { /* Line 1272, Address: 0x102a5e0 */
  if (lSpd.w.l >= scralim_down) { /* Line 1273, Address: 0x102a5ec */
    if (lSpd.w.l < 2048) { /* Line 1274, Address: 0x102a614 */

      lSpd.w.l = scralim_down; /* Line 1276, Address: 0x102a62c */
    } else { /* Line 1277, Address: 0x102a638 */
      lSpd.w.l -= 2048; /* Line 1278, Address: 0x102a640 */
      actwk[0].yposi.w.l &= 2047; /* Line 1279, Address: 0x102a64c */
      scra_v_posit.w.h -= 2048; /* Line 1280, Address: 0x102a660 */
      scrb_v_posit.w.h &= 1023; /* Line 1281, Address: 0x102a674 */
    }
  }

  scrv_move(lSpd); /* Line 1285, Address: 0x102a688 */
} /* Line 1286, Address: 0x102a694 */
















static void scrv_move(int_union lSpd) { /* Line 1303, Address: 0x102a6b0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1307, Address: 0x102a6c0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1308, Address: 0x102a6d0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1309, Address: 0x102a6f4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1310, Address: 0x102a708 */
  scra_vz = spdwk.w.l; /* Line 1311, Address: 0x102a720 */

  scra_v_posit.l = lSpd.l; /* Line 1313, Address: 0x102a72c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1315, Address: 0x102a738 */
  if (!ywk) { /* Line 1316, Address: 0x102a774 */
    scra_v_count ^= 16; /* Line 1317, Address: 0x102a77c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1318, Address: 0x102a790 */
    if (ywk < 0) { /* Line 1319, Address: 0x102a7bc */
      scrflaga.b.h |= 1; /* Line 1320, Address: 0x102a7cc */
    } else { /* Line 1321, Address: 0x102a7e0 */
      scrflaga.b.h |= 2; /* Line 1322, Address: 0x102a7e8 */
    }
  }


} /* Line 1327, Address: 0x102a7fc */

















void scrollwrt() { /* Line 1345, Address: 0x102a810 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1354, Address: 0x102a830 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1355, Address: 0x102a834 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1356, Address: 0x102a840 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1357, Address: 0x102a84c */
  pScrFlag = &scrflagbw.b.h; /* Line 1358, Address: 0x102a854 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1359, Address: 0x102a85c */

  VramBase = 16384; /* Line 1361, Address: 0x102a870 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1362, Address: 0x102a874 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1363, Address: 0x102a880 */
  pMapWk = (unsigned char*)mapwka; /* Line 1364, Address: 0x102a88c */
  pScrFlag = &scrflagaw.b.h; /* Line 1365, Address: 0x102a894 */

  if (*pScrFlag) { /* Line 1367, Address: 0x102a89c */
    if (*pScrFlag & 1) { /* Line 1368, Address: 0x102a8a8 */
      *pScrFlag &= 254; /* Line 1369, Address: 0x102a8bc */

      lD4.l = -16; /* Line 1371, Address: 0x102a8c8 */
      wD5 = 65520; /* Line 1372, Address: 0x102a8d0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1374, Address: 0x102a8d8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1376, Address: 0x102a8f8 */
    }




    if (*pScrFlag & 2) { /* Line 1382, Address: 0x102a924 */
      *pScrFlag &= 253; /* Line 1383, Address: 0x102a938 */

      lD4.l = 224; /* Line 1385, Address: 0x102a944 */
      wD5 = 65520; /* Line 1386, Address: 0x102a94c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1387, Address: 0x102a954 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1389, Address: 0x102a974 */
    }




    if (*pScrFlag & 4) { /* Line 1395, Address: 0x102a9a0 */
      *pScrFlag &= 251; /* Line 1396, Address: 0x102a9b4 */

      lD4.l = -16; /* Line 1398, Address: 0x102a9c0 */
      wD5 = 65520; /* Line 1399, Address: 0x102a9c8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1400, Address: 0x102a9d0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1402, Address: 0x102a9f0 */
    }




    if (*pScrFlag & 8) { /* Line 1408, Address: 0x102aa1c */
      *pScrFlag &= 247; /* Line 1409, Address: 0x102aa30 */

      lD4.l = -16; /* Line 1411, Address: 0x102aa3c */
      wD5 = 320; /* Line 1412, Address: 0x102aa44 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1413, Address: 0x102aa4c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1415, Address: 0x102aa6c */
    }
  }






} /* Line 1424, Address: 0x102aa98 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1441, Address: 0x102aac0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1452, Address: 0x102aaec */

  if (*pScrFlag & 1) { /* Line 1454, Address: 0x102aaf4 */
    *pScrFlag &= 254; /* Line 1455, Address: 0x102ab0c */
  } /* Line 1456, Address: 0x102ab20 */
  else {
    *pScrFlag &= 254; /* Line 1458, Address: 0x102ab28 */

    if (*pScrFlag & 2) { /* Line 1460, Address: 0x102ab3c */
      *pScrFlag &= 253; /* Line 1461, Address: 0x102ab54 */
      lD4.w.l = 224; /* Line 1462, Address: 0x102ab68 */
    } /* Line 1463, Address: 0x102ab70 */
    else {
      *pScrFlag &= 253; /* Line 1465, Address: 0x102ab78 */
      goto label1; /* Line 1466, Address: 0x102ab8c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1471, Address: 0x102ab94 */
  wD0 &= 127; /* Line 1472, Address: 0x102abe4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1473, Address: 0x102abec */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1479, Address: 0x102ac0c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1480, Address: 0x102ac2c */
  if (wD0 != 0) { /* Line 1481, Address: 0x102ac50 */
    wD5 = 65520; /* Line 1482, Address: 0x102ac5c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1483, Address: 0x102ac64 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1485, Address: 0x102ac84 */



  } /* Line 1489, Address: 0x102acb0 */
  else {

    wD5 = 0; /* Line 1492, Address: 0x102acb8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1493, Address: 0x102acbc */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1497, Address: 0x102acdc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1504, Address: 0x102ad08 */






    lD4.l = -16; /* Line 1511, Address: 0x102ad1c */
    wD5 = 65520; /* Line 1512, Address: 0x102ad24 */
    if (*pScrFlag & 168) { /* Line 1513, Address: 0x102ad2c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1514, Address: 0x102ad44 */
      wD5 = 320; /* Line 1515, Address: 0x102ad64 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1519, Address: 0x102ad6c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1521, Address: 0x102ad9c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1522, Address: 0x102ada8 */



    for (i = 0; i < 16; ++i) { /* Line 1526, Address: 0x102adb8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1527, Address: 0x102adc4 */

      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1529, Address: 0x102ade4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1530, Address: 0x102ae1c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1531, Address: 0x102ae3c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1533, Address: 0x102ae60 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1536, Address: 0x102ae84 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1538, Address: 0x102aea4 */
      }
      lD4.w.l += 16; /* Line 1540, Address: 0x102aeb8 */
    } /* Line 1541, Address: 0x102aec4 */
    *pScrFlag = 0; /* Line 1542, Address: 0x102aed4 */
  }
} /* Line 1544, Address: 0x102aedc */





void scrollwrtc() {} /* Line 1550, Address: 0x102af10 */




void scrollwrtz() {} /* Line 1555, Address: 0x102af20 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1573, Address: 0x102af30 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1586, Address: 0x102af58 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1589, Address: 0x102af78 */
    pTilePoint->x += 2; /* Line 1590, Address: 0x102af8c */
    if (pTilePoint->x >= 64) { /* Line 1591, Address: 0x102afa0 */
      pTilePoint->x -= 64; /* Line 1592, Address: 0x102afb4 */
    }
    xOffs += 16; /* Line 1594, Address: 0x102afc8 */
  } while (--lpcnt >= 0); /* Line 1595, Address: 0x102afd4 */
} /* Line 1596, Address: 0x102afe8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1600, Address: 0x102b000 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1604, Address: 0x102b028 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1607, Address: 0x102b048 */
    pTilePoint->x += 2; /* Line 1608, Address: 0x102b05c */
    if (pTilePoint->x >= 64) { /* Line 1609, Address: 0x102b070 */
      pTilePoint->x -= 64; /* Line 1610, Address: 0x102b084 */
    }
    xOffs += 16; /* Line 1612, Address: 0x102b098 */
  } while (--lpcnt >= 0); /* Line 1613, Address: 0x102b0a4 */
} /* Line 1614, Address: 0x102b0b8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1634, Address: 0x102b0d0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1638, Address: 0x102b0f8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1641, Address: 0x102b118 */
    pTilePoint->y += 2; /* Line 1642, Address: 0x102b12c */
    if (pTilePoint->y >= 32) { /* Line 1643, Address: 0x102b13c */
      pTilePoint->y -= 32; /* Line 1644, Address: 0x102b150 */
    }
    yOffs += 16; /* Line 1646, Address: 0x102b160 */
  } while (--lpcnt >= 0); /* Line 1647, Address: 0x102b16c */
} /* Line 1648, Address: 0x102b180 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1667, Address: 0x102b190 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1673, Address: 0x102b1c4 */

    base = 1; /* Line 1675, Address: 0x102b1d4 */
  } /* Line 1676, Address: 0x102b1d8 */
  else if (VramBase == 16384) { /* Line 1677, Address: 0x102b1e0 */

    base = 0; /* Line 1679, Address: 0x102b1f0 */
  }
  x = pTilePoint->x; /* Line 1681, Address: 0x102b1f4 */
  y = pTilePoint->y; /* Line 1682, Address: 0x102b1fc */


  frip = BlkIndex & 6144; /* Line 1685, Address: 0x102b204 */
  BlkIndex &= 1023; /* Line 1686, Address: 0x102b20c */
  if (frip == 6144) { /* Line 1687, Address: 0x102b218 */

    p0 = 3, p1 = 2; /* Line 1689, Address: 0x102b224 */
    p2 = 1, p3 = 0; /* Line 1690, Address: 0x102b22c */
  } /* Line 1691, Address: 0x102b234 */
  else if (frip & 4096) { /* Line 1692, Address: 0x102b23c */

    p0 = 2, p1 = 3; /* Line 1694, Address: 0x102b248 */
    p2 = 0, p3 = 1; /* Line 1695, Address: 0x102b250 */
  } /* Line 1696, Address: 0x102b258 */
  else if (frip & 2048) { /* Line 1697, Address: 0x102b260 */

    p0 = 1, p1 = 0; /* Line 1699, Address: 0x102b26c */
    p2 = 3, p3 = 2; /* Line 1700, Address: 0x102b274 */
  } /* Line 1701, Address: 0x102b27c */
  else {

    p0 = 0, p1 = 1; /* Line 1704, Address: 0x102b284 */
    p2 = 2, p3 = 3; /* Line 1705, Address: 0x102b28c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1708, Address: 0x102b294 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1709, Address: 0x102b2d8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1710, Address: 0x102b31c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1711, Address: 0x102b360 */

} /* Line 1713, Address: 0x102b3a4 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1731, Address: 0x102b3e0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1732, Address: 0x102b400 */
} /* Line 1733, Address: 0x102b420 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1735, Address: 0x102b430 */
  wH_posiw = 0; /* Line 1736, Address: 0x102b450 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1737, Address: 0x102b454 */
} /* Line 1738, Address: 0x102b474 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1745, Address: 0x102b490 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1751, Address: 0x102b4c0 */
  yOffs += wV_posiw; /* Line 1752, Address: 0x102b4d0 */





  if ((short)xOffs < 0) /* Line 1758, Address: 0x102b4e0 */
    xOffs = 0; /* Line 1759, Address: 0x102b4fc */
  if ((short)yOffs < 0) /* Line 1760, Address: 0x102b500 */
    yOffs = 0; /* Line 1761, Address: 0x102b51c */
  if ((short)xOffs >= 16384) /* Line 1762, Address: 0x102b520 */
    xOffs = 16383; /* Line 1763, Address: 0x102b540 */
  if ((short)yOffs >= 2048) /* Line 1764, Address: 0x102b548 */
    yOffs = 2047; /* Line 1765, Address: 0x102b568 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1766, Address: 0x102b570 */
  if (i < 0) i = 0; /* Line 1767, Address: 0x102b5b8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1769, Address: 0x102b5c4 */

  if (ScreenNo) { /* Line 1771, Address: 0x102b5e0 */




    xOffs &= 32767; /* Line 1776, Address: 0x102b5e8 */
    yOffs &= 32767; /* Line 1777, Address: 0x102b5f4 */


    xBlk = xOffs; /* Line 1780, Address: 0x102b600 */
    xBlk %= 256; /* Line 1781, Address: 0x102b608 */
    xBlk /= 16; /* Line 1782, Address: 0x102b628 */
    yBlk = yOffs; /* Line 1783, Address: 0x102b644 */
    yBlk %= 256; /* Line 1784, Address: 0x102b64c */
    yBlk /= 16; /* Line 1785, Address: 0x102b66c */

    lpw = pmapwk; /* Line 1787, Address: 0x102b688 */
    lpw += xBlk; /* Line 1788, Address: 0x102b690 */
    lpw += yBlk * 16; /* Line 1789, Address: 0x102b698 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1790, Address: 0x102b6a4 */
    *pIndex = *lpw; /* Line 1791, Address: 0x102b6bc */

    return 1; /* Line 1793, Address: 0x102b6cc */
  }

  *pIndex = 0; /* Line 1796, Address: 0x102b6d8 */
  return 0; /* Line 1797, Address: 0x102b6e0 */
} /* Line 1798, Address: 0x102b6e4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1818, Address: 0x102b710 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1826, Address: 0x102b738 */
  if (ScreenNo) { /* Line 1827, Address: 0x102b79c */





    xBlk = xOffs; /* Line 1833, Address: 0x102b7a4 */
    xBlk %= 256; /* Line 1834, Address: 0x102b7ac */
    xBlk /= 16; /* Line 1835, Address: 0x102b7cc */
    yBlk = yOffs; /* Line 1836, Address: 0x102b7e8 */
    yBlk %= 256; /* Line 1837, Address: 0x102b7f0 */
    yBlk /= 16; /* Line 1838, Address: 0x102b810 */


    lpw = pmapwk; /* Line 1841, Address: 0x102b82c */
    lpw += xBlk; /* Line 1842, Address: 0x102b834 */
    lpw += yBlk * 16; /* Line 1843, Address: 0x102b83c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1844, Address: 0x102b848 */
    *ppBlockNo = lpw; /* Line 1845, Address: 0x102b860 */
    *pIndex = *lpw; /* Line 1846, Address: 0x102b868 */




    return 1; /* Line 1851, Address: 0x102b878 */
  }

  *pIndex = 0; /* Line 1854, Address: 0x102b884 */
  return 0; /* Line 1855, Address: 0x102b88c */
} /* Line 1856, Address: 0x102b890 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1870, Address: 0x102b8b0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1877, Address: 0x102b8cc */
  pMapWk = (unsigned char*)mapwka; /* Line 1878, Address: 0x102b8d0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1879, Address: 0x102b8d8 */
    *pBlockIndex = BlockNo; /* Line 1880, Address: 0x102b8fc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1881, Address: 0x102b908 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1882, Address: 0x102b920 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1883, Address: 0x102b934 */
    }
  }


} /* Line 1888, Address: 0x102b94c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1902, Address: 0x102b970 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1903, Address: 0x102b97c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1904, Address: 0x102b9a8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1905, Address: 0x102b9f4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1906, Address: 0x102ba20 */

          return 0; /* Line 1908, Address: 0x102ba6c */
        }
      }
    }
  }

  return 1; /* Line 1914, Address: 0x102ba78 */
} /* Line 1915, Address: 0x102ba7c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1932, Address: 0x102ba90 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1933, Address: 0x102baac */

} /* Line 1935, Address: 0x102bac8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1937, Address: 0x102bae0 */
  wH_posiw = 0; /* Line 1938, Address: 0x102bafc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1939, Address: 0x102bb00 */

} /* Line 1941, Address: 0x102bb1c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1943, Address: 0x102bb30 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1944, Address: 0x102bb44 */

} /* Line 1946, Address: 0x102bb60 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1948, Address: 0x102bb70 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1949, Address: 0x102bb8c */

} /* Line 1951, Address: 0x102bba8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1953, Address: 0x102bbc0 */
  xOffs += wH_posiw; /* Line 1954, Address: 0x102bbd8 */
  yOffs += wV_posiw; /* Line 1955, Address: 0x102bbe8 */
  yOffs &= 240; /* Line 1956, Address: 0x102bbf8 */
  xOffs &= 496; /* Line 1957, Address: 0x102bc04 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1959, Address: 0x102bc10 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1960, Address: 0x102bc3c */


} /* Line 1963, Address: 0x102bc68 */















void mapwrt() { /* Line 1979, Address: 0x102bc80 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1984, Address: 0x102bc98 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1985, Address: 0x102bca4 */
  pMapWk = (unsigned char*)mapwka; /* Line 1986, Address: 0x102bcb0 */
  VramBase = 16384; /* Line 1987, Address: 0x102bcb8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1988, Address: 0x102bcbc */
  mapwrtb(); /* Line 1989, Address: 0x102bcd4 */
} /* Line 1990, Address: 0x102bcdc */


void mapwrtb() { /* Line 1993, Address: 0x102bd00 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scrb_h_posiw.w.h; /* Line 1998, Address: 0x102bd18 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1999, Address: 0x102bd24 */
  pMapWk = (unsigned char*)mapwkb; /* Line 2000, Address: 0x102bd30 */
  VramBase = 24576; /* Line 2001, Address: 0x102bd38 */
  mapwrt_z81a(pMapWk, VramBase); /* Line 2002, Address: 0x102bd3c */

} /* Line 2004, Address: 0x102bd4c */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 2007, Address: 0x102bd70 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 2008, Address: 0x102bd88 */
} /* Line 2009, Address: 0x102bda8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 2014, Address: 0x102bdc0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 2018, Address: 0x102bde0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 2021, Address: 0x102bdfc */



    wD4 += 16; /* Line 2025, Address: 0x102be24 */
  } while ((short)--wD6 >= 0); /* Line 2026, Address: 0x102be30 */

} /* Line 2028, Address: 0x102be58 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 2034, Address: 0x102be70 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 2037, Address: 0x102be8c */
  wD6 = 15; /* Line 2038, Address: 0x102be94 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 1008; /* Line 2041, Address: 0x102be9c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 2043, Address: 0x102bec0 */
    wD4 += 16; /* Line 2044, Address: 0x102bee0 */
  } while ((short)--wD6 >= 0); /* Line 2045, Address: 0x102bee8 */
} /* Line 2046, Address: 0x102bf0c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2072, Address: 0x102bf30 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2077, Address: 0x102bf58 */
  wD0 = pWrttbl[wD0]; /* Line 2078, Address: 0x102bf68 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2080, Address: 0x102bf84 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2081, Address: 0x102bfa8 */
  if (wD0) { /* Line 2082, Address: 0x102bfd0 */
    wD5 = 65520; /* Line 2083, Address: 0x102bfdc */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2084, Address: 0x102bfe4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2087, Address: 0x102c000 */



  } /* Line 2091, Address: 0x102c028 */
  else {

    wD5 = 0; /* Line 2094, Address: 0x102c030 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2095, Address: 0x102c034 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2099, Address: 0x102c050 */
  }





} /* Line 2106, Address: 0x102c078 */










void mapinit() { /* Line 2117, Address: 0x102c0a0 */
  short tbl[9] = { /* Line 2118, Address: 0x102c0c0 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 2123, Address: 0x102c0ec */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  EnkeiNo = 0; /* Line 2129, Address: 0x102c110 */
  pTbl = tbl; /* Line 2130, Address: 0x102c114 */

  while ((poswk = *pTbl++) >= 0) { /* Line 2132, Address: 0x102c118 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 2133, Address: 0x102c120 */


    ++EnkeiNo; /* Line 2136, Address: 0x102c144 */
  } /* Line 2137, Address: 0x102c148 */


  TileNo = 597; /* Line 2140, Address: 0x102c16c */
  if (EnkeiNo == 0) { /* Line 2141, Address: 0x102c170 */
    i = 96; /* Line 2142, Address: 0x102c178 */
    BmpNo = 0; /* Line 2143, Address: 0x102c17c */

    for ( ; i > 0; --i) { /* Line 2145, Address: 0x102c180 */
      ChangeTileBmp(TileNo++, BmpNo++); /* Line 2146, Address: 0x102c188 */
    } /* Line 2147, Address: 0x102c1a8 */
  }


  colorset2(mapinittbl.colorno2); /* Line 2151, Address: 0x102c1b4 */
  colorset(mapinittbl.colorno2); /* Line 2152, Address: 0x102c1c8 */


  if (play_start & 2) divdevset(); /* Line 2155, Address: 0x102c1dc */
} /* Line 2156, Address: 0x102c1fc */




void mapset() {} /* Line 2161, Address: 0x102c230 */



void divdevset() {} /* Line 2165, Address: 0x102c240 */



void enecginit() {} /* Line 2169, Address: 0x102c250 */















static void mapset2(unsigned char* pMapDst, int idx) { /* Line 2185, Address: 0x102c260 */
  int h, v, hwk;
  unsigned char *pZonetbl, *pMapwk;

  pZonetbl = zonemaptbl[idx]; /* Line 2189, Address: 0x102c280 */
  h = *pZonetbl++; /* Line 2190, Address: 0x102c298 */
  v = *pZonetbl++; /* Line 2191, Address: 0x102c2a8 */
  for ( ;v >= 0; --v) { /* Line 2192, Address: 0x102c2b8 */
    pMapwk = pMapDst; /* Line 2193, Address: 0x102c2c0 */

    for (hwk = h; hwk >= 0; --hwk) { /* Line 2195, Address: 0x102c2c4 */
      *pMapwk++ = *pZonetbl++; /* Line 2196, Address: 0x102c2d0 */
    } /* Line 2197, Address: 0x102c2e8 */

    pMapDst += 64; /* Line 2199, Address: 0x102c2f4 */
  } /* Line 2200, Address: 0x102c300 */
} /* Line 2201, Address: 0x102c30c */
