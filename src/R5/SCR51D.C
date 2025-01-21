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
short playpositbl[1][2] = { { 64, 620 } };
unsigned char playmapnotbl[4] = { 127, 127, 24, 98 };
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;
extern unsigned char* zonemaptbl[];





























































































void enkeichg() { /* Line 152, Address: 0x1023be0 */
  short tbl[9] = { /* Line 153, Address: 0x1023c00 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 158, Address: 0x1023c2c */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  if (scrflaga.b.h) return; /* Line 164, Address: 0x1023c50 */



  EnkeiNo = 0; /* Line 168, Address: 0x1023c60 */
  pTbl = tbl; /* Line 169, Address: 0x1023c64 */

  while ((poswk = *pTbl++) >= 0) { /* Line 171, Address: 0x1023c68 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 172, Address: 0x1023c70 */


    ++EnkeiNo; /* Line 175, Address: 0x1023c94 */
  } /* Line 176, Address: 0x1023c98 */


  if (enkeino == EnkeiNo) return; /* Line 179, Address: 0x1023cbc */




  enkeino = EnkeiNo; /* Line 184, Address: 0x1023cd0 */


  TileNo = 597; /* Line 187, Address: 0x1023cdc */
  if (EnkeiNo == 1) { /* Line 188, Address: 0x1023ce0 */
    i = 88; /* Line 189, Address: 0x1023cec */
    BmpNo = 96; /* Line 190, Address: 0x1023cf0 */
  } else { /* Line 191, Address: 0x1023cf4 */
    i = 96; /* Line 192, Address: 0x1023cfc */
    BmpNo = 0; /* Line 193, Address: 0x1023d00 */
  }
  for ( ; i > 0; --i) { /* Line 195, Address: 0x1023d04 */
    ChangeTileBmp(TileNo++, BmpNo++); /* Line 196, Address: 0x1023d0c */
  } /* Line 197, Address: 0x1023d2c */

  colorset2((tbl0[EnkeiNo] >> 2) + 4); /* Line 199, Address: 0x1023d38 */
  colorset((tbl0[EnkeiNo] >> 2) + 4); /* Line 200, Address: 0x1023d58 */

  mapset2((unsigned char*)mapwkb, tbl0[EnkeiNo] / 2); /* Line 202, Address: 0x1023d78 */
  scrbinit(scra_h_posit.w.h, scra_v_posit.w.h); /* Line 203, Address: 0x1023db0 */
  mapwrt_cnt = 1; /* Line 204, Address: 0x1023dc8 */
} /* Line 205, Address: 0x1023dd4 */












sprite_status* main_chk() {
  if (main_play == 0) /* Line 219, Address: 0x1023e00 */
    return &actwk[0]; /* Line 220, Address: 0x1023e14 */
  else
    return &actwk[1]; /* Line 222, Address: 0x1023e24 */

} /* Line 224, Address: 0x1023e2c */





































void scr_set() { /* Line 262, Address: 0x1023e40 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 265, Address: 0x1023e4c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 266, Address: 0x1023e60 */
  scr_timer.b.h = 0; /* Line 267, Address: 0x1023e74 */

  pScrTbl = scr_dir_tbl; /* Line 269, Address: 0x1023e7c */
  scrar_no = *pScrTbl; /* Line 270, Address: 0x1023e84 */
  ++pScrTbl; /* Line 271, Address: 0x1023e90 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 272, Address: 0x1023e94 */
  ++pScrTbl; /* Line 273, Address: 0x1023ea8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 274, Address: 0x1023eac */
  ++pScrTbl; /* Line 275, Address: 0x1023ec0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 276, Address: 0x1023ec4 */
  ++pScrTbl; /* Line 277, Address: 0x1023ed8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 278, Address: 0x1023edc */
  scra_h_keep = *pScrTbl + 576; /* Line 279, Address: 0x1023ef0 */
  ++pScrTbl; /* Line 280, Address: 0x1023f10 */
  scra_h_count = 16; /* Line 281, Address: 0x1023f14 */
  scra_v_count = 16; /* Line 282, Address: 0x1023f20 */

  scra_vline = *pScrTbl; /* Line 284, Address: 0x1023f2c */
  scra_hline = 160; /* Line 285, Address: 0x1023f38 */

  playposiset(); /* Line 287, Address: 0x1023f44 */
} /* Line 288, Address: 0x1023f4c */






































static void playposiset() { /* Line 327, Address: 0x1023f60 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 330, Address: 0x1023f74 */
    playload(); /* Line 331, Address: 0x1023f84 */
    xwk = actwk[0].xposi.w.h; /* Line 332, Address: 0x1023f8c */

    if (actwk[0].yposi.w.h > 0) { /* Line 334, Address: 0x1023f9c */
      ywk = actwk[0].yposi.w.h; /* Line 335, Address: 0x1023fb4 */
    } else { /* Line 336, Address: 0x1023fc4 */
      ywk = 0; /* Line 337, Address: 0x1023fcc */
    }
  } /* Line 339, Address: 0x1023fd0 */
  else {
    pPositbl = playpositbl[0]; /* Line 341, Address: 0x1023fd8 */


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 344, Address: 0x1023fe0 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 345, Address: 0x1023ff4 */
  }


  if (xwk > 160) { /* Line 349, Address: 0x1024008 */
    xwk -= 160; /* Line 350, Address: 0x102401c */
  } else { /* Line 351, Address: 0x1024028 */
    xwk = 0; /* Line 352, Address: 0x1024030 */
  }


  if (xwk > scralim_right) { /* Line 356, Address: 0x1024034 */
    xwk = scralim_right; /* Line 357, Address: 0x1024058 */
  }


  scra_h_posit.w.h = xwk; /* Line 361, Address: 0x1024068 */

  if (ywk > 96) { /* Line 363, Address: 0x1024070 */
    ywk -= 96; /* Line 364, Address: 0x1024084 */
  } else { /* Line 365, Address: 0x1024090 */
    ywk = 0; /* Line 366, Address: 0x1024098 */
  }


  if (ywk > scralim_down) { /* Line 370, Address: 0x102409c */
    ywk = scralim_down; /* Line 371, Address: 0x10240c0 */
  }


  scra_v_posit.w.h = ywk; /* Line 375, Address: 0x10240d0 */

  scrbinit(xwk, ywk); /* Line 377, Address: 0x10240d8 */


  loopmapno = playmapnotbl[0]; /* Line 380, Address: 0x10240e8 */
  loopmapno2 = playmapnotbl[1]; /* Line 381, Address: 0x10240f8 */
  ballmapno = playmapnotbl[2]; /* Line 382, Address: 0x1024108 */
  ballmapno2 = playmapnotbl[3]; /* Line 383, Address: 0x1024118 */
} /* Line 384, Address: 0x1024128 */




















static void scrbinit(short sXpos, short sYpos) { /* Line 405, Address: 0x1024150 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 408, Address: 0x102415c */
  lYwk.w.l = 0; /* Line 409, Address: 0x1024164 */

  lYwk.l = (unsigned int)lYwk.l >> 3; /* Line 411, Address: 0x1024168 */
  lYwk.l += (lYwk.l >> 2) * 3; /* Line 412, Address: 0x1024174 */

  scrb_v_posit.l = lYwk.l; /* Line 414, Address: 0x1024190 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 415, Address: 0x102419c */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 416, Address: 0x10241a8 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 418, Address: 0x10241b4 */
  scrb_h_posit.w.h = sXpos; /* Line 419, Address: 0x10241d0 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 421, Address: 0x10241dc */
  scrc_h_posit.w.h = sXpos; /* Line 422, Address: 0x10241f8 */

  sXpos >>= 1; /* Line 424, Address: 0x1024204 */
  scrz_h_posit.w.h = sXpos; /* Line 425, Address: 0x1024210 */
} /* Line 426, Address: 0x102421c */















void scroll() { /* Line 442, Address: 0x1024230 */
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

  if (scroll_start.b.h) return; /* Line 454, Address: 0x1024254 */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 459, Address: 0x1024264 */

  scrchk(); /* Line 461, Address: 0x1024290 */

  scroll_h(); /* Line 463, Address: 0x1024298 */
  scroll_v(); /* Line 464, Address: 0x10242a0 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 466, Address: 0x10242a8 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 467, Address: 0x10242b8 */


  lXwk = scra_hz * 32; /* Line 470, Address: 0x10242c8 */
  scrollz_h(lXwk, 6); /* Line 471, Address: 0x10242dc */

  lXwk = scra_hz * 64; /* Line 473, Address: 0x10242ec */
  scrollc_h(lXwk, 4); /* Line 474, Address: 0x1024300 */

  lXwk = scra_hz * 128; /* Line 476, Address: 0x1024310 */
  scrollb_h(lXwk, 2); /* Line 477, Address: 0x1024324 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 3; /* Line 479, Address: 0x1024334 */
  lYwk += (lYwk >> 2) * 3; /* Line 480, Address: 0x1024348 */


  scrollb_v(lYwk); /* Line 483, Address: 0x1024358 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 485, Address: 0x1024368 */
  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 486, Address: 0x1024390 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 487, Address: 0x10243c8 */

  psHscw = hscrollwork; /* Line 489, Address: 0x10243dc */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 490, Address: 0x10243e8 */

  if (enkeino & 1) { /* Line 492, Address: 0x1024408 */

    ldwk.w.l = -scrc_h_posit.w.h; /* Line 494, Address: 0x1024420 */
    for (i = 0; i < 11; ++i) { /* Line 495, Address: 0x1024440 */

      *psHscw++ = ldwk.w.l; /* Line 497, Address: 0x102444c */
    } /* Line 498, Address: 0x1024460 */
    z51dline0(&psHscw); /* Line 499, Address: 0x1024470 */
  } /* Line 500, Address: 0x102447c */
  else {
    z51dline(&psHscw); /* Line 502, Address: 0x1024484 */













    ldwk.w.l = -scrb_h_posit.w.h; /* Line 516, Address: 0x1024490 */
    for (i = 0; i < 16; ++i) { /* Line 517, Address: 0x10244b0 */
      *psHscw++ = ldwk.w.l; /* Line 518, Address: 0x10244bc */
    } /* Line 519, Address: 0x10244d0 */
  }


  pHscrbuf = lphscrollbuff; /* Line 523, Address: 0x10244e0 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 524, Address: 0x10244ec */
  sYline = 39; /* Line 525, Address: 0x102451c */
  sYnumsv = 29; /* Line 526, Address: 0x1024528 */
  if (enkeino & 1) { /* Line 527, Address: 0x1024534 */

    sYline = 28; /* Line 529, Address: 0x102454c */

    sYnumsv -= sYline; /* Line 531, Address: 0x1024558 */
    psHscr = &hscrollwork[sYnum / 2]; /* Line 532, Address: 0x1024564 */
    zonescrsetsub0(scrb_v_posit.w.h, sYline, &pHscrbuf, psHscr); /* Line 533, Address: 0x1024594 */
  } else { /* Line 534, Address: 0x10245b0 */
    if (sYline >= sYnum >> 1) { /* Line 535, Address: 0x10245b8 */
      sYline -= sYnum >> 1; /* Line 536, Address: 0x10245d8 */

      if (sYline > 28) { /* Line 538, Address: 0x10245f8 */
        sYline = 28; /* Line 539, Address: 0x102460c */
      }


      sYnumsv -= sYline; /* Line 543, Address: 0x1024618 */
      psHscr = &hscrollwork[sYnum / 2]; /* Line 544, Address: 0x1024624 */
      zonescrsetsub0(scrb_v_posit.w.h, sYline, &pHscrbuf, psHscr); /* Line 545, Address: 0x1024654 */
    }
  }



  if (!(enkeino & 1)) { /* Line 551, Address: 0x1024670 */
    ldwk.w.l = scrb_h_posit.w.h; /* Line 552, Address: 0x1024688 */
    ldwk2.w.l = scra_h_posit.w.h; /* Line 553, Address: 0x1024694 */
    ldwk2.w.l -= ldwk.w.l; /* Line 554, Address: 0x10246a0 */
    ldwk2.l = ldwk2.w.l * 256 / 256 * 256; /* Line 555, Address: 0x10246b0 */
    ldwk3.l = 0; /* Line 556, Address: 0x10246e0 */
    ldwk3.w.l = ldwk.w.l; /* Line 557, Address: 0x10246e4 */

    for (sYnumsv = sYnumsv * 8 - 1; sYnumsv >= 0; --sYnumsv) { /* Line 559, Address: 0x10246ec */

      ldwk.w.l = -ldwk3.w.l; /* Line 561, Address: 0x1024714 */
      pHscrbuf->l = ldwk.l; /* Line 562, Address: 0x1024730 */
      ++pHscrbuf; /* Line 563, Address: 0x102473c */
      ldwk3.l = (unsigned int)ldwk3.l >> 16 & 65535 | ldwk3.l << 16 & -65536; /* Line 564, Address: 0x1024748 */
      ldwk3.l += ldwk2.l; /* Line 565, Address: 0x102476c */
      ldwk3.l = (unsigned int)ldwk3.l >> 16 & 65535 | ldwk3.l << 16 & -65536; /* Line 566, Address: 0x102477c */
    } /* Line 567, Address: 0x10247a0 */
  }


} /* Line 571, Address: 0x10247bc */













static void z51dline(short** ppHscw) { /* Line 585, Address: 0x10247f0 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51dscrtbl[3] = { /* Line 590, Address: 0x1024808 */
    5, 11, 5
  };

  lHwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 594, Address: 0x102482c */
  lHwk = (unsigned int)lHwk * 64 / 6; /* Line 595, Address: 0x1024850 */
  lHwk *= 1024; /* Line 596, Address: 0x102486c */

  ldHposwk.l = 0; /* Line 598, Address: 0x1024870 */
  ldHposwk.w.l = scrb_h_posit.w.h; /* Line 599, Address: 0x1024874 */
  *ppHscw += 24; /* Line 600, Address: 0x1024880 */

  for (i = 2; i >= 0; --i) { /* Line 602, Address: 0x1024894 */

    wk = -ldHposwk.w.l; /* Line 604, Address: 0x10248a0 */

    for (j = z51dscrtbl[i]; j >= 0; --j) { /* Line 606, Address: 0x10248c0 */

      --*ppHscw; /* Line 608, Address: 0x10248d8 */
      **ppHscw = wk; /* Line 609, Address: 0x10248ec */
    } /* Line 610, Address: 0x10248f8 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 612, Address: 0x1024904 */
    ldHposwk.l += lHwk; /* Line 613, Address: 0x1024928 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 614, Address: 0x1024934 */
  } /* Line 615, Address: 0x1024958 */

  *ppHscw += 24; /* Line 617, Address: 0x1024964 */
} /* Line 618, Address: 0x1024978 */













static void z51dline0(short** ppHscw) { /* Line 632, Address: 0x10249a0 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51dscrtbl0[6] = { /* Line 637, Address: 0x10249b8 */
    13, 7, 5, 3, 3, 0
  };

  lHwk = scra_h_posit.w.h - scrc_h_posit.w.h; /* Line 641, Address: 0x10249ec */
  lHwk = (unsigned int)lHwk * 128 / 12; /* Line 642, Address: 0x1024a10 */
  lHwk *= 512; /* Line 643, Address: 0x1024a2c */

  ldHposwk.l = 0; /* Line 645, Address: 0x1024a30 */
  ldHposwk.w.l = scrc_h_posit.w.h; /* Line 646, Address: 0x1024a34 */

  for (i = 5; i >= 0; --i) { /* Line 648, Address: 0x1024a40 */

    wk = -ldHposwk.w.l; /* Line 650, Address: 0x1024a4c */

    for (j = z51dscrtbl0[i]; j >= 0; --j) { /* Line 652, Address: 0x1024a6c */

      **ppHscw = wk; /* Line 654, Address: 0x1024a84 */
      ++*ppHscw; /* Line 655, Address: 0x1024a90 */
    } /* Line 656, Address: 0x1024aa4 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 658, Address: 0x1024ab0 */
    ldHposwk.l += lHwk; /* Line 659, Address: 0x1024ad4 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 660, Address: 0x1024ae0 */
  } /* Line 661, Address: 0x1024b04 */
} /* Line 662, Address: 0x1024b10 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 683, Address: 0x1024b30 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 687, Address: 0x1024b4c */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 689, Address: 0x1024b50 */
    ldwk.w.l = *pHscrwk; /* Line 690, Address: 0x1024b6c */
    ++pHscrwk; /* Line 691, Address: 0x1024b78 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 693, Address: 0x1024b84 */
      (*pHscrbuf)->l = ldwk.l; /* Line 694, Address: 0x1024b8c */
    } /* Line 695, Address: 0x1024b9c */
  } /* Line 696, Address: 0x1024bc0 */
} /* Line 697, Address: 0x1024be0 */









































































































static void scrollb_v(short yPos) { /* Line 803, Address: 0x1024c00 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 806, Address: 0x1024c10 */
  scrb_v_posit.w.h = yPos; /* Line 807, Address: 0x1024c20 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 808, Address: 0x1024c2c */

  if (!ywk) { /* Line 810, Address: 0x1024c64 */
    scrb_v_count ^= 16; /* Line 811, Address: 0x1024c6c */
    if (yPos - ysv < 0) { /* Line 812, Address: 0x1024c80 */
      scrflagb.b.h |= 1; /* Line 813, Address: 0x1024ca0 */
    } /* Line 814, Address: 0x1024cb4 */
    else {
      scrflagb.b.h |= 2; /* Line 816, Address: 0x1024cbc */
    }
  }


} /* Line 821, Address: 0x1024cd0 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 839, Address: 0x1024cf0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 843, Address: 0x1024d04 */
  lXwk = lXsv + xoffs; /* Line 844, Address: 0x1024d0c */
  scrb_h_posit.l = lXwk; /* Line 845, Address: 0x1024d14 */
  ldXwk.l = lXwk; /* Line 846, Address: 0x1024d1c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 847, Address: 0x1024d20 */
  ldXwk.w.l &= 16; /* Line 848, Address: 0x1024d44 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 849, Address: 0x1024d50 */

  if (!ldXwk.b.b4) { /* Line 851, Address: 0x1024d6c */
    scrb_h_count ^= 16; /* Line 852, Address: 0x1024d78 */
    if (lXwk - lXsv < 0) { /* Line 853, Address: 0x1024d8c */
      scrflagb.b.h |= 1 << flgbit; /* Line 854, Address: 0x1024d98 */
    } /* Line 855, Address: 0x1024dbc */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 857, Address: 0x1024dc4 */
    }
  }


} /* Line 862, Address: 0x1024dec */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 880, Address: 0x1024e00 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 884, Address: 0x1024e14 */
  lXwk = lXsv + xoffs; /* Line 885, Address: 0x1024e1c */
  scrc_h_posit.l = lXwk; /* Line 886, Address: 0x1024e24 */
  ldXwk.l = lXwk; /* Line 887, Address: 0x1024e2c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 888, Address: 0x1024e30 */
  ldXwk.w.l &= 16; /* Line 889, Address: 0x1024e54 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 890, Address: 0x1024e60 */

  if (!ldXwk.b.b4) { /* Line 892, Address: 0x1024e7c */
    scrc_h_count ^= 16; /* Line 893, Address: 0x1024e88 */
    if (lXwk - lXsv < 0) { /* Line 894, Address: 0x1024e9c */
      scrflagc.b.h |= 1 << flgbit; /* Line 895, Address: 0x1024ea8 */
    } /* Line 896, Address: 0x1024ecc */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 898, Address: 0x1024ed4 */
    }
  }


} /* Line 903, Address: 0x1024efc */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 921, Address: 0x1024f10 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 925, Address: 0x1024f24 */
  lXwk = lXsv + xoffs; /* Line 926, Address: 0x1024f2c */
  scrz_h_posit.l = lXwk; /* Line 927, Address: 0x1024f34 */
  ldXwk.l = lXwk; /* Line 928, Address: 0x1024f3c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 929, Address: 0x1024f40 */
  ldXwk.w.l &= 16; /* Line 930, Address: 0x1024f64 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 931, Address: 0x1024f70 */

  if (!ldXwk.b.b4) { /* Line 933, Address: 0x1024f8c */
    scrz_h_count ^= 16; /* Line 934, Address: 0x1024f98 */
    if (lXwk - lXsv < 0) { /* Line 935, Address: 0x1024fac */
      scrflagz.b.h |= 1 << flgbit; /* Line 936, Address: 0x1024fb8 */
    } /* Line 937, Address: 0x1024fdc */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 939, Address: 0x1024fe4 */
    }
  }


} /* Line 944, Address: 0x102500c */














static void scroll_h() { /* Line 959, Address: 0x1025020 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 963, Address: 0x1025030 */

  scrh_move(); /* Line 965, Address: 0x1025040 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 966, Address: 0x1025048 */
  if (!bXwk) { /* Line 967, Address: 0x102507c */
    scra_h_count ^= 16; /* Line 968, Address: 0x1025084 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 969, Address: 0x1025098 */
      scrflaga.b.h |= 4; /* Line 970, Address: 0x10250bc */
    } else { /* Line 971, Address: 0x10250d0 */
      scrflaga.b.h |= 8; /* Line 972, Address: 0x10250d8 */
    }
  }


} /* Line 977, Address: 0x10250ec */
















static void scrh_move() { /* Line 994, Address: 0x1025110 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 997, Address: 0x1025118 */
  if (xwk == 0) { /* Line 998, Address: 0x1025160 */

    scra_hz = 0; /* Line 1000, Address: 0x1025170 */
    return; /* Line 1001, Address: 0x1025178 */
  } else if (xwk < 0) { /* Line 1002, Address: 0x1025180 */

    if (xwk < -16) { /* Line 1004, Address: 0x1025190 */
      xwk = -16; /* Line 1005, Address: 0x10251a4 */
    }


    xwk += scra_h_posit.w.h; /* Line 1009, Address: 0x10251b0 */
    if (xwk < scralim_left) { /* Line 1010, Address: 0x10251c4 */
      xwk = scralim_left; /* Line 1011, Address: 0x10251e8 */
    }
  } /* Line 1013, Address: 0x10251f8 */
  else {
    if (xwk > 16) { /* Line 1015, Address: 0x1025200 */
      xwk = 16; /* Line 1016, Address: 0x1025214 */
    }


    xwk += scra_h_posit.w.h; /* Line 1020, Address: 0x1025220 */
    if (xwk > scralim_right) { /* Line 1021, Address: 0x1025234 */
      xwk = scralim_right; /* Line 1022, Address: 0x1025258 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 1027, Address: 0x1025268 */
  scra_h_posit.w.h = xwk; /* Line 1028, Address: 0x1025298 */
} /* Line 1029, Address: 0x10252a0 */














static void scroll_v() { /* Line 1044, Address: 0x10252b0 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 1047, Address: 0x10252bc */
  if (actwk[0].cddat & 4) { /* Line 1048, Address: 0x10252f0 */
    ywk -= 5; /* Line 1049, Address: 0x1025308 */
  }


  if (actwk[0].cddat & 2) { /* Line 1053, Address: 0x1025314 */
    ywk += 32; /* Line 1054, Address: 0x102532c */
    if (ywk < scra_vline) { /* Line 1055, Address: 0x1025338 */
      ywk -= scra_vline; /* Line 1056, Address: 0x102535c */
      sv_move_main2(ywk); /* Line 1057, Address: 0x1025370 */
      return; /* Line 1058, Address: 0x102537c */
    } else if (ywk >= scra_vline + 64) { /* Line 1059, Address: 0x1025384 */
      ywk -= scra_vline + 64; /* Line 1060, Address: 0x10253ac */
      sv_move_main2(ywk); /* Line 1061, Address: 0x10253d4 */
      return; /* Line 1062, Address: 0x10253e0 */
    }
    ywk -= scra_vline + 64; /* Line 1064, Address: 0x10253e8 */
    if (!limmoveflag) goto label1; /* Line 1065, Address: 0x1025410 */
    sv_move_sub2(); /* Line 1066, Address: 0x1025420 */
    return; /* Line 1067, Address: 0x1025428 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 1072, Address: 0x1025430 */
    sv_move_main(ywk); /* Line 1073, Address: 0x102545c */
    return; /* Line 1074, Address: 0x1025468 */
  } else if (!limmoveflag) goto label1; /* Line 1075, Address: 0x1025470 */
  sv_move_sub2(); /* Line 1076, Address: 0x1025480 */
  return; /* Line 1077, Address: 0x1025488 */



label1:
  scra_vz = 0; /* Line 1082, Address: 0x1025490 */
} /* Line 1083, Address: 0x1025498 */













static void sv_move_main(short yPos) { /* Line 1097, Address: 0x10254b0 */
  short spdwk;

  if (scra_vline == 96) { /* Line 1100, Address: 0x10254c0 */
    if (actwk[0].mspeed.w < 0) { /* Line 1101, Address: 0x10254dc */
      spdwk = -actwk[0].mspeed.w; /* Line 1102, Address: 0x10254f4 */
    } else { /* Line 1103, Address: 0x1025518 */
      spdwk = actwk[0].mspeed.w; /* Line 1104, Address: 0x1025520 */
    }


    if (spdwk >= 2048) { /* Line 1108, Address: 0x1025530 */
      sv_move_main2(yPos); /* Line 1109, Address: 0x1025544 */
    } /* Line 1110, Address: 0x1025550 */
    else {

      if (yPos > 6) { /* Line 1113, Address: 0x1025558 */
        sv_move_plus(1536); /* Line 1114, Address: 0x1025570 */
      } else if (yPos < -6) { /* Line 1115, Address: 0x102557c */
        sv_move_minus(1536); /* Line 1116, Address: 0x102559c */
      } /* Line 1117, Address: 0x10255a8 */
      else sv_move_sub(yPos); /* Line 1118, Address: 0x10255b0 */
    }
  } /* Line 1120, Address: 0x10255bc */
  else {
    if (yPos > 2) { /* Line 1122, Address: 0x10255c4 */
      sv_move_plus(512); /* Line 1123, Address: 0x10255dc */
    } else if (yPos < -2) { /* Line 1124, Address: 0x10255e8 */
      sv_move_minus(512); /* Line 1125, Address: 0x1025608 */
    } /* Line 1126, Address: 0x1025614 */
    else sv_move_sub(yPos); /* Line 1127, Address: 0x102561c */
  }

} /* Line 1130, Address: 0x1025628 */













static void sv_move_main2(short yPos) { /* Line 1144, Address: 0x1025640 */
  short spdwk;

  spdwk = 4096; /* Line 1147, Address: 0x1025650 */

  if (yPos > 16) { /* Line 1149, Address: 0x102565c */
    sv_move_plus(spdwk); /* Line 1150, Address: 0x1025674 */
  } else if (yPos < -16) { /* Line 1151, Address: 0x1025680 */
    sv_move_minus(spdwk); /* Line 1152, Address: 0x10256a0 */
  } else { /* Line 1153, Address: 0x10256ac */
    sv_move_sub(yPos); /* Line 1154, Address: 0x10256b4 */
  }
} /* Line 1156, Address: 0x10256c0 */














static void sv_move_sub(short yPos) { /* Line 1171, Address: 0x10256e0 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1174, Address: 0x10256ec */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1175, Address: 0x10256f0 */
  if (yPos < 0) { /* Line 1176, Address: 0x102571c */
    scrv_up_ch(lSpd); /* Line 1177, Address: 0x1025730 */
  } else { /* Line 1178, Address: 0x102573c */
    scrv_down_ch(lSpd); /* Line 1179, Address: 0x1025744 */
  }
} /* Line 1181, Address: 0x1025750 */



static void sv_move_sub2() { /* Line 1185, Address: 0x1025760 */
  limmoveflag = 0; /* Line 1186, Address: 0x1025768 */

  sv_move_sub(0); /* Line 1188, Address: 0x1025770 */
} /* Line 1189, Address: 0x102577c */













static void sv_move_minus(short speed) { /* Line 1203, Address: 0x1025790 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1206, Address: 0x102579c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1207, Address: 0x10257c0 */
  scrv_up_ch(lSpd); /* Line 1208, Address: 0x10257e4 */
} /* Line 1209, Address: 0x10257f0 */














static void scrv_up_ch(int_union lSpd) { /* Line 1224, Address: 0x1025800 */
  if (lSpd.w.l <= scralim_up) { /* Line 1225, Address: 0x102580c */
    if (lSpd.w.l > -256) { /* Line 1226, Address: 0x1025834 */

      lSpd.w.l = scralim_up; /* Line 1228, Address: 0x102584c */
    } else { /* Line 1229, Address: 0x1025858 */
      lSpd.w.l &= 2047; /* Line 1230, Address: 0x1025860 */
      actwk[0].yposi.w.h &= 2047; /* Line 1231, Address: 0x102586c */
      scra_v_posit.w.h &= 2047; /* Line 1232, Address: 0x1025880 */
      scrb_v_posit.w.h &= 1023; /* Line 1233, Address: 0x1025894 */
    }
  }

  scrv_move(lSpd); /* Line 1237, Address: 0x10258a8 */
} /* Line 1238, Address: 0x10258b4 */













static void sv_move_plus(short sSpd) { /* Line 1252, Address: 0x10258d0 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1255, Address: 0x10258dc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1256, Address: 0x10258fc */
  scrv_down_ch(lSpd); /* Line 1257, Address: 0x1025920 */
} /* Line 1258, Address: 0x102592c */














static void scrv_down_ch(int_union lSpd) { /* Line 1273, Address: 0x1025940 */
  if (lSpd.w.l >= scralim_down) { /* Line 1274, Address: 0x102594c */
    if (lSpd.w.l < 2048) { /* Line 1275, Address: 0x1025974 */

      lSpd.w.l = scralim_down; /* Line 1277, Address: 0x102598c */
    } else { /* Line 1278, Address: 0x1025998 */
      lSpd.w.l -= 2048; /* Line 1279, Address: 0x10259a0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1280, Address: 0x10259ac */
      scra_v_posit.w.h -= 2048; /* Line 1281, Address: 0x10259c0 */
      scrb_v_posit.w.h &= 1023; /* Line 1282, Address: 0x10259d4 */
    }
  }

  scrv_move(lSpd); /* Line 1286, Address: 0x10259e8 */
} /* Line 1287, Address: 0x10259f4 */
















static void scrv_move(int_union lSpd) { /* Line 1304, Address: 0x1025a10 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1308, Address: 0x1025a20 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1309, Address: 0x1025a30 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1310, Address: 0x1025a54 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1311, Address: 0x1025a68 */
  scra_vz = spdwk.w.l; /* Line 1312, Address: 0x1025a80 */

  scra_v_posit.l = lSpd.l; /* Line 1314, Address: 0x1025a8c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1316, Address: 0x1025a98 */
  if (!ywk) { /* Line 1317, Address: 0x1025ad4 */
    scra_v_count ^= 16; /* Line 1318, Address: 0x1025adc */
    ywk = scra_v_posit.w.h - ysv; /* Line 1319, Address: 0x1025af0 */
    if (ywk < 0) { /* Line 1320, Address: 0x1025b1c */
      scrflaga.b.h |= 1; /* Line 1321, Address: 0x1025b2c */
    } else { /* Line 1322, Address: 0x1025b40 */
      scrflaga.b.h |= 2; /* Line 1323, Address: 0x1025b48 */
    }
  }


} /* Line 1328, Address: 0x1025b5c */

















void scrollwrt() { /* Line 1346, Address: 0x1025b70 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1355, Address: 0x1025b90 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1356, Address: 0x1025b94 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1357, Address: 0x1025ba0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1358, Address: 0x1025bac */
  pScrFlag = &scrflagbw.b.h; /* Line 1359, Address: 0x1025bb4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1360, Address: 0x1025bbc */

  VramBase = 16384; /* Line 1362, Address: 0x1025bd0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1363, Address: 0x1025bd4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1364, Address: 0x1025be0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1365, Address: 0x1025bec */
  pScrFlag = &scrflagaw.b.h; /* Line 1366, Address: 0x1025bf4 */

  if (*pScrFlag) { /* Line 1368, Address: 0x1025bfc */
    if (*pScrFlag & 1) { /* Line 1369, Address: 0x1025c08 */
      *pScrFlag &= 254; /* Line 1370, Address: 0x1025c1c */

      lD4.l = -16; /* Line 1372, Address: 0x1025c28 */
      wD5 = 65520; /* Line 1373, Address: 0x1025c30 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1375, Address: 0x1025c38 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1377, Address: 0x1025c58 */
    }




    if (*pScrFlag & 2) { /* Line 1383, Address: 0x1025c84 */
      *pScrFlag &= 253; /* Line 1384, Address: 0x1025c98 */

      lD4.l = 224; /* Line 1386, Address: 0x1025ca4 */
      wD5 = 65520; /* Line 1387, Address: 0x1025cac */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1388, Address: 0x1025cb4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1390, Address: 0x1025cd4 */
    }




    if (*pScrFlag & 4) { /* Line 1396, Address: 0x1025d00 */
      *pScrFlag &= 251; /* Line 1397, Address: 0x1025d14 */

      lD4.l = -16; /* Line 1399, Address: 0x1025d20 */
      wD5 = 65520; /* Line 1400, Address: 0x1025d28 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1401, Address: 0x1025d30 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1403, Address: 0x1025d50 */
    }




    if (*pScrFlag & 8) { /* Line 1409, Address: 0x1025d7c */
      *pScrFlag &= 247; /* Line 1410, Address: 0x1025d90 */

      lD4.l = -16; /* Line 1412, Address: 0x1025d9c */
      wD5 = 320; /* Line 1413, Address: 0x1025da4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1414, Address: 0x1025dac */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1416, Address: 0x1025dcc */
    }
  }






} /* Line 1425, Address: 0x1025df8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1442, Address: 0x1025e20 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1453, Address: 0x1025e4c */

  if (*pScrFlag & 1) { /* Line 1455, Address: 0x1025e54 */
    *pScrFlag &= 254; /* Line 1456, Address: 0x1025e6c */
  } /* Line 1457, Address: 0x1025e80 */
  else {
    *pScrFlag &= 254; /* Line 1459, Address: 0x1025e88 */

    if (*pScrFlag & 2) { /* Line 1461, Address: 0x1025e9c */
      *pScrFlag &= 253; /* Line 1462, Address: 0x1025eb4 */
      lD4.w.l = 224; /* Line 1463, Address: 0x1025ec8 */
    } /* Line 1464, Address: 0x1025ed0 */
    else {
      *pScrFlag &= 253; /* Line 1466, Address: 0x1025ed8 */
      goto label1; /* Line 1467, Address: 0x1025eec */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1472, Address: 0x1025ef4 */
  wD0 &= 127; /* Line 1473, Address: 0x1025f44 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1474, Address: 0x1025f4c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1480, Address: 0x1025f6c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1481, Address: 0x1025f8c */
  if (wD0 != 0) { /* Line 1482, Address: 0x1025fb0 */
    wD5 = 65520; /* Line 1483, Address: 0x1025fbc */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1484, Address: 0x1025fc4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1486, Address: 0x1025fe4 */



  } /* Line 1490, Address: 0x1026010 */
  else {

    wD5 = 0; /* Line 1493, Address: 0x1026018 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1494, Address: 0x102601c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1498, Address: 0x102603c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1505, Address: 0x1026068 */






    lD4.l = -16; /* Line 1512, Address: 0x102607c */
    wD5 = 65520; /* Line 1513, Address: 0x1026084 */
    if (*pScrFlag & 168) { /* Line 1514, Address: 0x102608c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1515, Address: 0x10260a4 */
      wD5 = 320; /* Line 1516, Address: 0x10260c4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1520, Address: 0x10260cc */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1522, Address: 0x10260fc */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1523, Address: 0x1026108 */



    for (i = 0; i < 16; ++i) { /* Line 1527, Address: 0x1026118 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1528, Address: 0x1026124 */

      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1530, Address: 0x1026144 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1531, Address: 0x102617c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1532, Address: 0x102619c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1534, Address: 0x10261c0 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1537, Address: 0x10261e4 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1539, Address: 0x1026204 */
      }
      lD4.w.l += 16; /* Line 1541, Address: 0x1026218 */
    } /* Line 1542, Address: 0x1026224 */
    *pScrFlag = 0; /* Line 1543, Address: 0x1026234 */
  }
} /* Line 1545, Address: 0x102623c */





void scrollwrtc() {} /* Line 1551, Address: 0x1026270 */




void scrollwrtz() {} /* Line 1556, Address: 0x1026280 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1574, Address: 0x1026290 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1587, Address: 0x10262b8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1590, Address: 0x10262d8 */
    pTilePoint->x += 2; /* Line 1591, Address: 0x10262ec */
    if (pTilePoint->x >= 64) { /* Line 1592, Address: 0x1026300 */
      pTilePoint->x -= 64; /* Line 1593, Address: 0x1026314 */
    }
    xOffs += 16; /* Line 1595, Address: 0x1026328 */
  } while (--lpcnt >= 0); /* Line 1596, Address: 0x1026334 */
} /* Line 1597, Address: 0x1026348 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1601, Address: 0x1026360 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1605, Address: 0x1026388 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1608, Address: 0x10263a8 */
    pTilePoint->x += 2; /* Line 1609, Address: 0x10263bc */
    if (pTilePoint->x >= 64) { /* Line 1610, Address: 0x10263d0 */
      pTilePoint->x -= 64; /* Line 1611, Address: 0x10263e4 */
    }
    xOffs += 16; /* Line 1613, Address: 0x10263f8 */
  } while (--lpcnt >= 0); /* Line 1614, Address: 0x1026404 */
} /* Line 1615, Address: 0x1026418 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1635, Address: 0x1026430 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1639, Address: 0x1026458 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1642, Address: 0x1026478 */
    pTilePoint->y += 2; /* Line 1643, Address: 0x102648c */
    if (pTilePoint->y >= 32) { /* Line 1644, Address: 0x102649c */
      pTilePoint->y -= 32; /* Line 1645, Address: 0x10264b0 */
    }
    yOffs += 16; /* Line 1647, Address: 0x10264c0 */
  } while (--lpcnt >= 0); /* Line 1648, Address: 0x10264cc */
} /* Line 1649, Address: 0x10264e0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1668, Address: 0x10264f0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1674, Address: 0x1026524 */

    base = 1; /* Line 1676, Address: 0x1026534 */
  } /* Line 1677, Address: 0x1026538 */
  else if (VramBase == 16384) { /* Line 1678, Address: 0x1026540 */

    base = 0; /* Line 1680, Address: 0x1026550 */
  }
  x = pTilePoint->x; /* Line 1682, Address: 0x1026554 */
  y = pTilePoint->y; /* Line 1683, Address: 0x102655c */


  frip = BlkIndex & 6144; /* Line 1686, Address: 0x1026564 */
  BlkIndex &= 1023; /* Line 1687, Address: 0x102656c */
  if (frip == 6144) { /* Line 1688, Address: 0x1026578 */

    p0 = 3, p1 = 2; /* Line 1690, Address: 0x1026584 */
    p2 = 1, p3 = 0; /* Line 1691, Address: 0x102658c */
  } /* Line 1692, Address: 0x1026594 */
  else if (frip & 4096) { /* Line 1693, Address: 0x102659c */

    p0 = 2, p1 = 3; /* Line 1695, Address: 0x10265a8 */
    p2 = 0, p3 = 1; /* Line 1696, Address: 0x10265b0 */
  } /* Line 1697, Address: 0x10265b8 */
  else if (frip & 2048) { /* Line 1698, Address: 0x10265c0 */

    p0 = 1, p1 = 0; /* Line 1700, Address: 0x10265cc */
    p2 = 3, p3 = 2; /* Line 1701, Address: 0x10265d4 */
  } /* Line 1702, Address: 0x10265dc */
  else {

    p0 = 0, p1 = 1; /* Line 1705, Address: 0x10265e4 */
    p2 = 2, p3 = 3; /* Line 1706, Address: 0x10265ec */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1709, Address: 0x10265f4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1710, Address: 0x1026638 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1711, Address: 0x102667c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1712, Address: 0x10266c0 */

} /* Line 1714, Address: 0x1026704 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1732, Address: 0x1026740 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1733, Address: 0x1026760 */
} /* Line 1734, Address: 0x1026780 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1736, Address: 0x1026790 */
  wH_posiw = 0; /* Line 1737, Address: 0x10267b0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1738, Address: 0x10267b4 */
} /* Line 1739, Address: 0x10267d4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1746, Address: 0x10267f0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1752, Address: 0x1026820 */
  yOffs += wV_posiw; /* Line 1753, Address: 0x1026830 */





  if ((short)xOffs < 0) /* Line 1759, Address: 0x1026840 */
    xOffs = 0; /* Line 1760, Address: 0x102685c */
  if ((short)yOffs < 0) /* Line 1761, Address: 0x1026860 */
    yOffs = 0; /* Line 1762, Address: 0x102687c */
  if ((short)xOffs >= 16384) /* Line 1763, Address: 0x1026880 */
    xOffs = 16383; /* Line 1764, Address: 0x10268a0 */
  if ((short)yOffs >= 2048) /* Line 1765, Address: 0x10268a8 */
    yOffs = 2047; /* Line 1766, Address: 0x10268c8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1767, Address: 0x10268d0 */
  if (i < 0) i = 0; /* Line 1768, Address: 0x1026918 */

  ScreenNo = pMapWk[i] & 127; /* Line 1770, Address: 0x1026924 */

  if (ScreenNo) { /* Line 1772, Address: 0x1026940 */




    xOffs &= 32767; /* Line 1777, Address: 0x1026948 */
    yOffs &= 32767; /* Line 1778, Address: 0x1026954 */


    xBlk = xOffs; /* Line 1781, Address: 0x1026960 */
    xBlk %= 256; /* Line 1782, Address: 0x1026968 */
    xBlk /= 16; /* Line 1783, Address: 0x1026988 */
    yBlk = yOffs; /* Line 1784, Address: 0x10269a4 */
    yBlk %= 256; /* Line 1785, Address: 0x10269ac */
    yBlk /= 16; /* Line 1786, Address: 0x10269cc */

    lpw = pmapwk; /* Line 1788, Address: 0x10269e8 */
    lpw += xBlk; /* Line 1789, Address: 0x10269f0 */
    lpw += yBlk * 16; /* Line 1790, Address: 0x10269f8 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1791, Address: 0x1026a04 */
    *pIndex = *lpw; /* Line 1792, Address: 0x1026a1c */

    return 1; /* Line 1794, Address: 0x1026a2c */
  }

  *pIndex = 0; /* Line 1797, Address: 0x1026a38 */
  return 0; /* Line 1798, Address: 0x1026a40 */
} /* Line 1799, Address: 0x1026a44 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1819, Address: 0x1026a70 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1827, Address: 0x1026a98 */
  if (ScreenNo) { /* Line 1828, Address: 0x1026afc */





    xBlk = xOffs; /* Line 1834, Address: 0x1026b04 */
    xBlk %= 256; /* Line 1835, Address: 0x1026b0c */
    xBlk /= 16; /* Line 1836, Address: 0x1026b2c */
    yBlk = yOffs; /* Line 1837, Address: 0x1026b48 */
    yBlk %= 256; /* Line 1838, Address: 0x1026b50 */
    yBlk /= 16; /* Line 1839, Address: 0x1026b70 */


    lpw = pmapwk; /* Line 1842, Address: 0x1026b8c */
    lpw += xBlk; /* Line 1843, Address: 0x1026b94 */
    lpw += yBlk * 16; /* Line 1844, Address: 0x1026b9c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1845, Address: 0x1026ba8 */
    *ppBlockNo = lpw; /* Line 1846, Address: 0x1026bc0 */
    *pIndex = *lpw; /* Line 1847, Address: 0x1026bc8 */




    return 1; /* Line 1852, Address: 0x1026bd8 */
  }

  *pIndex = 0; /* Line 1855, Address: 0x1026be4 */
  return 0; /* Line 1856, Address: 0x1026bec */
} /* Line 1857, Address: 0x1026bf0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1871, Address: 0x1026c10 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1878, Address: 0x1026c2c */
  pMapWk = (unsigned char*)mapwka; /* Line 1879, Address: 0x1026c30 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1880, Address: 0x1026c38 */
    *pBlockIndex = BlockNo; /* Line 1881, Address: 0x1026c5c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1882, Address: 0x1026c68 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1883, Address: 0x1026c80 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1884, Address: 0x1026c94 */
    }
  }


} /* Line 1889, Address: 0x1026cac */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1903, Address: 0x1026cd0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1904, Address: 0x1026cdc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1905, Address: 0x1026d08 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1906, Address: 0x1026d54 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1907, Address: 0x1026d80 */

          return 0; /* Line 1909, Address: 0x1026dcc */
        }
      }
    }
  }

  return 1; /* Line 1915, Address: 0x1026dd8 */
} /* Line 1916, Address: 0x1026ddc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1933, Address: 0x1026df0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1934, Address: 0x1026e0c */

} /* Line 1936, Address: 0x1026e28 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1938, Address: 0x1026e40 */
  wH_posiw = 0; /* Line 1939, Address: 0x1026e5c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1940, Address: 0x1026e60 */

} /* Line 1942, Address: 0x1026e7c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1944, Address: 0x1026e90 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1945, Address: 0x1026ea4 */

} /* Line 1947, Address: 0x1026ec0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1949, Address: 0x1026ed0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1950, Address: 0x1026eec */

} /* Line 1952, Address: 0x1026f08 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1954, Address: 0x1026f20 */
  xOffs += wH_posiw; /* Line 1955, Address: 0x1026f38 */
  yOffs += wV_posiw; /* Line 1956, Address: 0x1026f48 */
  yOffs &= 240; /* Line 1957, Address: 0x1026f58 */
  xOffs &= 496; /* Line 1958, Address: 0x1026f64 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1960, Address: 0x1026f70 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1961, Address: 0x1026f9c */


} /* Line 1964, Address: 0x1026fc8 */















void mapwrt() { /* Line 1980, Address: 0x1026fe0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1985, Address: 0x1026ff8 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1986, Address: 0x1027004 */
  pMapWk = (unsigned char*)mapwka; /* Line 1987, Address: 0x1027010 */
  VramBase = 16384; /* Line 1988, Address: 0x1027018 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1989, Address: 0x102701c */
  mapwrtb(); /* Line 1990, Address: 0x1027034 */
} /* Line 1991, Address: 0x102703c */


void mapwrtb() { /* Line 1994, Address: 0x1027060 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scrb_h_posiw.w.h; /* Line 1999, Address: 0x1027078 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 2000, Address: 0x1027084 */
  pMapWk = (unsigned char*)mapwkb; /* Line 2001, Address: 0x1027090 */
  VramBase = 24576; /* Line 2002, Address: 0x1027098 */
  mapwrt_z81a(pMapWk, VramBase); /* Line 2003, Address: 0x102709c */

} /* Line 2005, Address: 0x10270ac */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 2008, Address: 0x10270d0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 2009, Address: 0x10270e8 */
} /* Line 2010, Address: 0x1027108 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 2015, Address: 0x1027120 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 2019, Address: 0x1027140 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 2022, Address: 0x102715c */



    wD4 += 16; /* Line 2026, Address: 0x1027184 */
  } while ((short)--wD6 >= 0); /* Line 2027, Address: 0x1027190 */

} /* Line 2029, Address: 0x10271b8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 2035, Address: 0x10271d0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 2038, Address: 0x10271ec */
  wD6 = 15; /* Line 2039, Address: 0x10271f4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 1008; /* Line 2042, Address: 0x10271fc */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 2044, Address: 0x1027220 */
    wD4 += 16; /* Line 2045, Address: 0x1027240 */
  } while ((short)--wD6 >= 0); /* Line 2046, Address: 0x1027248 */
} /* Line 2047, Address: 0x102726c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2073, Address: 0x1027290 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2078, Address: 0x10272b8 */
  wD0 = pWrttbl[wD0]; /* Line 2079, Address: 0x10272c8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2081, Address: 0x10272e4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2082, Address: 0x1027308 */
  if (wD0) { /* Line 2083, Address: 0x1027330 */
    wD5 = 65520; /* Line 2084, Address: 0x102733c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2085, Address: 0x1027344 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2088, Address: 0x1027360 */



  } /* Line 2092, Address: 0x1027388 */
  else {

    wD5 = 0; /* Line 2095, Address: 0x1027390 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2096, Address: 0x1027394 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2100, Address: 0x10273b0 */
  }





} /* Line 2107, Address: 0x10273d8 */










void mapinit() { /* Line 2118, Address: 0x1027400 */
  short tbl[9] = { /* Line 2119, Address: 0x1027420 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 2124, Address: 0x102744c */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  EnkeiNo = 0; /* Line 2130, Address: 0x1027470 */
  pTbl = tbl; /* Line 2131, Address: 0x1027474 */

  while ((poswk = *pTbl++) >= 0) { /* Line 2133, Address: 0x1027478 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 2134, Address: 0x1027480 */


    ++EnkeiNo; /* Line 2137, Address: 0x10274a4 */
  } /* Line 2138, Address: 0x10274a8 */


  TileNo = 597; /* Line 2141, Address: 0x10274cc */
  if (EnkeiNo == 0) { /* Line 2142, Address: 0x10274d0 */
    i = 96; /* Line 2143, Address: 0x10274d8 */
    BmpNo = 0; /* Line 2144, Address: 0x10274dc */

    for ( ; i > 0; --i) { /* Line 2146, Address: 0x10274e0 */
      ChangeTileBmp(TileNo++, BmpNo++); /* Line 2147, Address: 0x10274e8 */
    } /* Line 2148, Address: 0x1027508 */
  }


  colorset2(mapinittbl.colorno2); /* Line 2152, Address: 0x1027514 */
  colorset(mapinittbl.colorno2); /* Line 2153, Address: 0x1027528 */


  if (play_start & 2) divdevset(); /* Line 2156, Address: 0x102753c */
} /* Line 2157, Address: 0x102755c */




void mapset() {} /* Line 2162, Address: 0x1027590 */



void divdevset() {} /* Line 2166, Address: 0x10275a0 */



void enecginit() {} /* Line 2170, Address: 0x10275b0 */















static void mapset2(unsigned char* pMapDst, int idx) { /* Line 2186, Address: 0x10275c0 */
  int h, v, hwk;
  unsigned char *pZonetbl, *pMapwk;

  pZonetbl = zonemaptbl[idx]; /* Line 2190, Address: 0x10275e0 */
  h = *pZonetbl++; /* Line 2191, Address: 0x10275f8 */
  v = *pZonetbl++; /* Line 2192, Address: 0x1027608 */
  for ( ;v >= 0; --v) { /* Line 2193, Address: 0x1027618 */
    pMapwk = pMapDst; /* Line 2194, Address: 0x1027620 */

    for (hwk = h; hwk >= 0; --hwk) { /* Line 2196, Address: 0x1027624 */
      *pMapwk++ = *pZonetbl++; /* Line 2197, Address: 0x1027630 */
    } /* Line 2198, Address: 0x1027648 */

    pMapDst += 64; /* Line 2200, Address: 0x1027654 */
  } /* Line 2201, Address: 0x1027660 */
} /* Line 2202, Address: 0x102766c */
