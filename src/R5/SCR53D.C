#include "..\EQU.H"
#include "SCR53C.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL5A.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
static void z51dline(short** ppHscw);
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
short scr_dir_tbl[6] = { 4, 0, 3735, 0, 800, 96 };
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
short playpositbl[1][2] = { { 64, 620 } };
unsigned char playmapnotbl[4] = { 127, 127, 127, 127 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;



















































































sprite_status* main_chk() {
  if (main_play == 0) /* Line 150, Address: 0x1020840 */
    return &actwk[0]; /* Line 151, Address: 0x1020854 */
  else
    return &actwk[1]; /* Line 153, Address: 0x1020864 */

} /* Line 155, Address: 0x102086c */





































void scr_set() { /* Line 193, Address: 0x1020880 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 196, Address: 0x102088c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 197, Address: 0x10208a0 */
  scr_timer.b.h = 0; /* Line 198, Address: 0x10208b4 */

  pScrTbl = scr_dir_tbl; /* Line 200, Address: 0x10208bc */
  scrar_no = *pScrTbl; /* Line 201, Address: 0x10208c4 */
  ++pScrTbl; /* Line 202, Address: 0x10208d0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 203, Address: 0x10208d4 */
  ++pScrTbl; /* Line 204, Address: 0x10208e8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 205, Address: 0x10208ec */
  ++pScrTbl; /* Line 206, Address: 0x1020900 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 207, Address: 0x1020904 */
  ++pScrTbl; /* Line 208, Address: 0x1020918 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 209, Address: 0x102091c */
  scra_h_keep = *pScrTbl + 576; /* Line 210, Address: 0x1020930 */
  ++pScrTbl; /* Line 211, Address: 0x1020950 */
  scra_h_count = 16; /* Line 212, Address: 0x1020954 */
  scra_v_count = 16; /* Line 213, Address: 0x1020960 */

  scra_vline = *pScrTbl; /* Line 215, Address: 0x102096c */
  scra_hline = 160; /* Line 216, Address: 0x1020978 */

  playposiset(); /* Line 218, Address: 0x1020984 */
} /* Line 219, Address: 0x102098c */
















































static void playposiset() { /* Line 268, Address: 0x10209a0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 271, Address: 0x10209b4 */
    playload(); /* Line 272, Address: 0x10209c4 */
    xwk = actwk[0].xposi.w.h; /* Line 273, Address: 0x10209cc */

    if (actwk[0].yposi.w.h > 0) { /* Line 275, Address: 0x10209dc */
      ywk = actwk[0].yposi.w.h; /* Line 276, Address: 0x10209f4 */
    } else { /* Line 277, Address: 0x1020a04 */
      ywk = 0; /* Line 278, Address: 0x1020a0c */
    }
  } /* Line 280, Address: 0x1020a10 */
  else {
    if (demoflag.w & -32768) { /* Line 282, Address: 0x1020a18 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 283, Address: 0x1020a38 */
    } /* Line 284, Address: 0x1020a5c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 286, Address: 0x1020a64 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 290, Address: 0x1020a84 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 291, Address: 0x1020a98 */
  }


  if (xwk > 160) { /* Line 295, Address: 0x1020aac */
    xwk -= 160; /* Line 296, Address: 0x1020ac0 */
  } else { /* Line 297, Address: 0x1020acc */
    xwk = 0; /* Line 298, Address: 0x1020ad4 */
  }


  if (xwk > scralim_right) { /* Line 302, Address: 0x1020ad8 */
    xwk = scralim_right; /* Line 303, Address: 0x1020afc */
  }


  scra_h_posit.w.h = xwk; /* Line 307, Address: 0x1020b0c */

  if (ywk > 96) { /* Line 309, Address: 0x1020b14 */
    ywk -= 96; /* Line 310, Address: 0x1020b28 */
  } else { /* Line 311, Address: 0x1020b34 */
    ywk = 0; /* Line 312, Address: 0x1020b3c */
  }


  if (ywk > scralim_down) { /* Line 316, Address: 0x1020b40 */
    ywk = scralim_down; /* Line 317, Address: 0x1020b64 */
  }


  scra_v_posit.w.h = ywk; /* Line 321, Address: 0x1020b74 */

  scrbinit(xwk, ywk); /* Line 323, Address: 0x1020b7c */


  loopmapno = playmapnotbl[0]; /* Line 326, Address: 0x1020b8c */
  loopmapno2 = playmapnotbl[1]; /* Line 327, Address: 0x1020b9c */
  ballmapno = playmapnotbl[2]; /* Line 328, Address: 0x1020bac */
  ballmapno2 = playmapnotbl[3]; /* Line 329, Address: 0x1020bbc */
} /* Line 330, Address: 0x1020bcc */




















static void scrbinit(short sXpos, short sYpos) { /* Line 351, Address: 0x1020bf0 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 354, Address: 0x1020bfc */
  lYwk.w.l = 0; /* Line 355, Address: 0x1020c04 */

  lYwk.l = (unsigned int)lYwk.l >> 3; /* Line 357, Address: 0x1020c08 */
  lYwk.l += (lYwk.l >> 2) * 3; /* Line 358, Address: 0x1020c14 */

  scrb_v_posit.l = lYwk.l; /* Line 360, Address: 0x1020c30 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 361, Address: 0x1020c3c */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 362, Address: 0x1020c48 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 364, Address: 0x1020c54 */
  scrb_h_posit.w.h = sXpos; /* Line 365, Address: 0x1020c70 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 367, Address: 0x1020c7c */
  scrc_h_posit.w.h = sXpos; /* Line 368, Address: 0x1020c98 */

  sXpos >>= 1; /* Line 370, Address: 0x1020ca4 */
  scrz_h_posit.w.h = sXpos; /* Line 371, Address: 0x1020cb0 */
} /* Line 372, Address: 0x1020cbc */















void scroll() { /* Line 388, Address: 0x1020cd0 */
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

  if (scroll_start.b.h) return; /* Line 400, Address: 0x1020cf4 */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 405, Address: 0x1020d04 */

  scrchk(); /* Line 407, Address: 0x1020d30 */

  scroll_h(); /* Line 409, Address: 0x1020d38 */
  scroll_v(); /* Line 410, Address: 0x1020d40 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 412, Address: 0x1020d48 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 413, Address: 0x1020d58 */


  lXwk = scra_hz * 32; /* Line 416, Address: 0x1020d68 */
  scrollz_h(lXwk, 6); /* Line 417, Address: 0x1020d7c */

  lXwk = scra_hz * 64; /* Line 419, Address: 0x1020d8c */
  scrollc_h(lXwk, 4); /* Line 420, Address: 0x1020da0 */

  lXwk = scra_hz * 128; /* Line 422, Address: 0x1020db0 */
  scrollb_h(lXwk, 2); /* Line 423, Address: 0x1020dc4 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 3; /* Line 425, Address: 0x1020dd4 */
  lYwk += (lYwk >> 2) * 3; /* Line 426, Address: 0x1020de8 */


  scrollb_v(lYwk); /* Line 429, Address: 0x1020df8 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 431, Address: 0x1020e08 */
  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 432, Address: 0x1020e30 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 433, Address: 0x1020e68 */

  psHscw = hscrollwork; /* Line 435, Address: 0x1020e7c */
  ldwk.w.h = -scra_h_posit.w.h; /* Line 436, Address: 0x1020e88 */


  z51dline(&psHscw); /* Line 439, Address: 0x1020ea8 */













  ldwk.w.l = -scrb_h_posit.w.h; /* Line 453, Address: 0x1020eb4 */
  for (i = 0; i < 16; ++i) { /* Line 454, Address: 0x1020ed4 */
    *psHscw++ = ldwk.w.l; /* Line 455, Address: 0x1020ee0 */
  } /* Line 456, Address: 0x1020ef4 */


  pHscrbuf = lphscrollbuff; /* Line 459, Address: 0x1020f04 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 460, Address: 0x1020f10 */
  sYline = 39; /* Line 461, Address: 0x1020f40 */
  sYnumsv = 29; /* Line 462, Address: 0x1020f4c */
  if (enkeino & 1) { /* Line 463, Address: 0x1020f58 */

    sYline = 28; /* Line 465, Address: 0x1020f70 */

    sYnumsv -= sYline; /* Line 467, Address: 0x1020f7c */
    psHscr = &hscrollwork[sYnum / 2]; /* Line 468, Address: 0x1020f88 */
    zonescrsetsub0(scrb_v_posit.w.h, sYline, &pHscrbuf, psHscr); /* Line 469, Address: 0x1020fb8 */
  } else { /* Line 470, Address: 0x1020fd4 */
    if ((sYline -= sYnum >> 1) >= 0) { /* Line 471, Address: 0x1020fdc */
      if (sYline > 28) { /* Line 472, Address: 0x1021014 */
        sYline = 28; /* Line 473, Address: 0x1021028 */
      }


      sYnumsv -= sYline; /* Line 477, Address: 0x1021034 */
      psHscr = &hscrollwork[sYnum / 2]; /* Line 478, Address: 0x1021040 */
      zonescrsetsub0(scrb_v_posit.w.h, sYline, &pHscrbuf, psHscr); /* Line 479, Address: 0x1021070 */
    }
  }



  if (!(enkeino & 1)) { /* Line 485, Address: 0x102108c */
    ldwk.w.l = scrb_h_posit.w.h; /* Line 486, Address: 0x10210a4 */
    ldwk2.w.l = scra_h_posit.w.h; /* Line 487, Address: 0x10210b0 */
    ldwk2.w.l -= ldwk.w.l; /* Line 488, Address: 0x10210bc */
    ldwk2.l = ldwk2.w.l * 256 / 256 * 256; /* Line 489, Address: 0x10210cc */
    ldwk3.l = 0; /* Line 490, Address: 0x10210fc */
    ldwk3.w.l = ldwk.w.l; /* Line 491, Address: 0x1021100 */

    for (sYnumsv = (sYnumsv >> 3) - 1; sYnumsv >= 0; --sYnumsv) { /* Line 493, Address: 0x1021108 */

      ldwk.w.l = -ldwk3.w.l; /* Line 495, Address: 0x1021130 */
      pHscrbuf->l = ldwk.l; /* Line 496, Address: 0x102114c */
      ++pHscrbuf; /* Line 497, Address: 0x1021158 */
      ldwk3.l = (unsigned int)ldwk3.l >> 16 & 65535 | ldwk3.l << 16 & -65536; /* Line 498, Address: 0x1021164 */
      ldwk3.l += ldwk2.l; /* Line 499, Address: 0x1021188 */
      ldwk3.l = (unsigned int)ldwk3.l >> 16 & 65535 | ldwk3.l << 16 & -65536; /* Line 500, Address: 0x1021198 */
    } /* Line 501, Address: 0x10211bc */
  }


} /* Line 505, Address: 0x10211d8 */













static void z51dline(short** ppHscw) { /* Line 519, Address: 0x1021210 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51dscrtbl[3] = { /* Line 524, Address: 0x1021228 */
    5, 11, 5
  };

  lHwk = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 528, Address: 0x102124c */
  lHwk = (unsigned int)lHwk * 128 / 6; /* Line 529, Address: 0x1021270 */
  lHwk *= 512; /* Line 530, Address: 0x102128c */

  ldHposwk.l = 0; /* Line 532, Address: 0x1021290 */
  ldHposwk.w.l = scrb_h_posit.w.h; /* Line 533, Address: 0x1021294 */
  *ppHscw += 24; /* Line 534, Address: 0x10212a0 */

  for (i = 2; i >= 0; --i) { /* Line 536, Address: 0x10212b4 */

    wk = -ldHposwk.w.l; /* Line 538, Address: 0x10212c0 */

    for (j = z51dscrtbl[i]; j >= 0; --j) { /* Line 540, Address: 0x10212e0 */

      --*ppHscw; /* Line 542, Address: 0x10212f8 */
      **ppHscw = wk; /* Line 543, Address: 0x102130c */
    } /* Line 544, Address: 0x1021318 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 546, Address: 0x1021324 */
    ldHposwk.l += lHwk; /* Line 547, Address: 0x1021348 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 548, Address: 0x1021354 */
  } /* Line 549, Address: 0x1021378 */

  *ppHscw += 24; /* Line 551, Address: 0x1021384 */
} /* Line 552, Address: 0x1021398 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 573, Address: 0x10213c0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 577, Address: 0x10213dc */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 579, Address: 0x10213e0 */
    ldwk.w.l = *pHscrwk; /* Line 580, Address: 0x10213fc */
    ++pHscrwk; /* Line 581, Address: 0x1021408 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 583, Address: 0x1021414 */
      (*pHscrbuf)->l = ldwk.l; /* Line 584, Address: 0x102141c */
    } /* Line 585, Address: 0x102142c */
  } /* Line 586, Address: 0x1021450 */
} /* Line 587, Address: 0x1021470 */









































































































static void scrollb_v(short yPos) { /* Line 693, Address: 0x1021490 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 696, Address: 0x10214a0 */
  scrb_v_posit.w.h = yPos; /* Line 697, Address: 0x10214b0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 698, Address: 0x10214bc */

  if (!ywk) { /* Line 700, Address: 0x10214f4 */
    scrb_v_count ^= 16; /* Line 701, Address: 0x10214fc */
    if (yPos - ysv < 0) { /* Line 702, Address: 0x1021510 */
      scrflagb.b.h |= 1; /* Line 703, Address: 0x1021530 */
    } /* Line 704, Address: 0x1021544 */
    else {
      scrflagb.b.h |= 2; /* Line 706, Address: 0x102154c */
    }
  }


} /* Line 711, Address: 0x1021560 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 729, Address: 0x1021580 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 733, Address: 0x1021594 */
  lXwk = lXsv + xoffs; /* Line 734, Address: 0x102159c */
  scrb_h_posit.l = lXwk; /* Line 735, Address: 0x10215a4 */
  ldXwk.l = lXwk; /* Line 736, Address: 0x10215ac */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 737, Address: 0x10215b0 */
  ldXwk.w.l &= 16; /* Line 738, Address: 0x10215d4 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 739, Address: 0x10215e0 */

  if (!ldXwk.b.b4) { /* Line 741, Address: 0x10215fc */
    scrb_h_count ^= 16; /* Line 742, Address: 0x1021608 */
    if (lXwk - lXsv < 0) { /* Line 743, Address: 0x102161c */
      scrflagb.b.h |= 1 << flgbit; /* Line 744, Address: 0x1021628 */
    } /* Line 745, Address: 0x102164c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 747, Address: 0x1021654 */
    }
  }


} /* Line 752, Address: 0x102167c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 770, Address: 0x1021690 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 774, Address: 0x10216a4 */
  lXwk = lXsv + xoffs; /* Line 775, Address: 0x10216ac */
  scrc_h_posit.l = lXwk; /* Line 776, Address: 0x10216b4 */
  ldXwk.l = lXwk; /* Line 777, Address: 0x10216bc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 778, Address: 0x10216c0 */
  ldXwk.w.l &= 16; /* Line 779, Address: 0x10216e4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 780, Address: 0x10216f0 */

  if (!ldXwk.b.b4) { /* Line 782, Address: 0x102170c */
    scrc_h_count ^= 16; /* Line 783, Address: 0x1021718 */
    if (lXwk - lXsv < 0) { /* Line 784, Address: 0x102172c */
      scrflagc.b.h |= 1 << flgbit; /* Line 785, Address: 0x1021738 */
    } /* Line 786, Address: 0x102175c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 788, Address: 0x1021764 */
    }
  }


} /* Line 793, Address: 0x102178c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 811, Address: 0x10217a0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 815, Address: 0x10217b4 */
  lXwk = lXsv + xoffs; /* Line 816, Address: 0x10217bc */
  scrz_h_posit.l = lXwk; /* Line 817, Address: 0x10217c4 */
  ldXwk.l = lXwk; /* Line 818, Address: 0x10217cc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 819, Address: 0x10217d0 */
  ldXwk.w.l &= 16; /* Line 820, Address: 0x10217f4 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 821, Address: 0x1021800 */

  if (!ldXwk.b.b4) { /* Line 823, Address: 0x102181c */
    scrz_h_count ^= 16; /* Line 824, Address: 0x1021828 */
    if (lXwk - lXsv < 0) { /* Line 825, Address: 0x102183c */
      scrflagz.b.h |= 1 << flgbit; /* Line 826, Address: 0x1021848 */
    } /* Line 827, Address: 0x102186c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 829, Address: 0x1021874 */
    }
  }


} /* Line 834, Address: 0x102189c */














static void scroll_h() { /* Line 849, Address: 0x10218b0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 853, Address: 0x10218c0 */

  scrh_move(); /* Line 855, Address: 0x10218d0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 856, Address: 0x10218d8 */
  if (!bXwk) { /* Line 857, Address: 0x102190c */
    scra_h_count ^= 16; /* Line 858, Address: 0x1021914 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 859, Address: 0x1021928 */
      scrflaga.b.h |= 4; /* Line 860, Address: 0x102194c */
    } else { /* Line 861, Address: 0x1021960 */
      scrflaga.b.h |= 8; /* Line 862, Address: 0x1021968 */
    }
  }


} /* Line 867, Address: 0x102197c */
















static void scrh_move() { /* Line 884, Address: 0x10219a0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 887, Address: 0x10219a8 */
  if (xwk == 0) { /* Line 888, Address: 0x10219f0 */

    scra_hz = 0; /* Line 890, Address: 0x1021a00 */
    return; /* Line 891, Address: 0x1021a08 */
  } else if (xwk < 0) { /* Line 892, Address: 0x1021a10 */

    if (xwk < -16) { /* Line 894, Address: 0x1021a20 */
      xwk = -16; /* Line 895, Address: 0x1021a34 */
    }


    xwk += scra_h_posit.w.h; /* Line 899, Address: 0x1021a40 */
    if (xwk < scralim_left) { /* Line 900, Address: 0x1021a54 */
      xwk = scralim_left; /* Line 901, Address: 0x1021a78 */
    }
  } /* Line 903, Address: 0x1021a88 */
  else {
    if (xwk > 16) { /* Line 905, Address: 0x1021a90 */
      xwk = 16; /* Line 906, Address: 0x1021aa4 */
    }


    xwk += scra_h_posit.w.h; /* Line 910, Address: 0x1021ab0 */
    if (xwk > scralim_right) { /* Line 911, Address: 0x1021ac4 */
      xwk = scralim_right; /* Line 912, Address: 0x1021ae8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 917, Address: 0x1021af8 */
  scra_h_posit.w.h = xwk; /* Line 918, Address: 0x1021b28 */
} /* Line 919, Address: 0x1021b30 */














static void scroll_v() { /* Line 934, Address: 0x1021b40 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 937, Address: 0x1021b4c */
  if (actwk[0].cddat & 4) { /* Line 938, Address: 0x1021b80 */
    ywk -= 5; /* Line 939, Address: 0x1021b98 */
  }


  if (actwk[0].cddat & 2) { /* Line 943, Address: 0x1021ba4 */
    ywk += 32; /* Line 944, Address: 0x1021bbc */
    if (ywk < scra_vline) { /* Line 945, Address: 0x1021bc8 */
      ywk -= scra_vline; /* Line 946, Address: 0x1021bec */
      sv_move_main2(ywk); /* Line 947, Address: 0x1021c00 */
      return; /* Line 948, Address: 0x1021c0c */
    } else if (ywk >= scra_vline + 64) { /* Line 949, Address: 0x1021c14 */
      ywk -= scra_vline + 64; /* Line 950, Address: 0x1021c3c */
      sv_move_main2(ywk); /* Line 951, Address: 0x1021c64 */
      return; /* Line 952, Address: 0x1021c70 */
    }
    ywk -= scra_vline + 64; /* Line 954, Address: 0x1021c78 */
    if (!limmoveflag) goto label1; /* Line 955, Address: 0x1021ca0 */
    sv_move_sub2(); /* Line 956, Address: 0x1021cb0 */
    return; /* Line 957, Address: 0x1021cb8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 962, Address: 0x1021cc0 */
    sv_move_main(ywk); /* Line 963, Address: 0x1021cec */
    return; /* Line 964, Address: 0x1021cf8 */
  } else if (!limmoveflag) goto label1; /* Line 965, Address: 0x1021d00 */
  sv_move_sub2(); /* Line 966, Address: 0x1021d10 */
  return; /* Line 967, Address: 0x1021d18 */



label1:
  scra_vz = 0; /* Line 972, Address: 0x1021d20 */
} /* Line 973, Address: 0x1021d28 */













static void sv_move_main(short yPos) { /* Line 987, Address: 0x1021d40 */
  short spdwk;

  if (scra_vline == 96) { /* Line 990, Address: 0x1021d50 */
    if (actwk[0].mspeed.w < 0) { /* Line 991, Address: 0x1021d6c */
      spdwk = -actwk[0].mspeed.w; /* Line 992, Address: 0x1021d84 */
    } else { /* Line 993, Address: 0x1021da8 */
      spdwk = actwk[0].mspeed.w; /* Line 994, Address: 0x1021db0 */
    }


    if (spdwk >= 2048) { /* Line 998, Address: 0x1021dc0 */
      sv_move_main2(yPos); /* Line 999, Address: 0x1021dd4 */
    } /* Line 1000, Address: 0x1021de0 */
    else {

      if (yPos > 6) { /* Line 1003, Address: 0x1021de8 */
        sv_move_plus(1536); /* Line 1004, Address: 0x1021e00 */
      } else if (yPos < -6) { /* Line 1005, Address: 0x1021e0c */
        sv_move_minus(1536); /* Line 1006, Address: 0x1021e2c */
      } /* Line 1007, Address: 0x1021e38 */
      else sv_move_sub(yPos); /* Line 1008, Address: 0x1021e40 */
    }
  } /* Line 1010, Address: 0x1021e4c */
  else {
    if (yPos > 2) { /* Line 1012, Address: 0x1021e54 */
      sv_move_plus(512); /* Line 1013, Address: 0x1021e6c */
    } else if (yPos < -2) { /* Line 1014, Address: 0x1021e78 */
      sv_move_minus(512); /* Line 1015, Address: 0x1021e98 */
    } /* Line 1016, Address: 0x1021ea4 */
    else sv_move_sub(yPos); /* Line 1017, Address: 0x1021eac */
  }

} /* Line 1020, Address: 0x1021eb8 */













static void sv_move_main2(short yPos) { /* Line 1034, Address: 0x1021ed0 */
  short spdwk;

  spdwk = 4096; /* Line 1037, Address: 0x1021ee0 */

  if (yPos > 16) { /* Line 1039, Address: 0x1021eec */
    sv_move_plus(spdwk); /* Line 1040, Address: 0x1021f04 */
  } else if (yPos < -16) { /* Line 1041, Address: 0x1021f10 */
    sv_move_minus(spdwk); /* Line 1042, Address: 0x1021f30 */
  } else { /* Line 1043, Address: 0x1021f3c */
    sv_move_sub(yPos); /* Line 1044, Address: 0x1021f44 */
  }
} /* Line 1046, Address: 0x1021f50 */














static void sv_move_sub(short yPos) { /* Line 1061, Address: 0x1021f70 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1064, Address: 0x1021f7c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1065, Address: 0x1021f80 */
  if (yPos < 0) { /* Line 1066, Address: 0x1021fac */
    scrv_up_ch(lSpd); /* Line 1067, Address: 0x1021fc0 */
  } else { /* Line 1068, Address: 0x1021fcc */
    scrv_down_ch(lSpd); /* Line 1069, Address: 0x1021fd4 */
  }
} /* Line 1071, Address: 0x1021fe0 */



static void sv_move_sub2() { /* Line 1075, Address: 0x1021ff0 */
  limmoveflag = 0; /* Line 1076, Address: 0x1021ff8 */

  sv_move_sub(0); /* Line 1078, Address: 0x1022000 */
} /* Line 1079, Address: 0x102200c */













static void sv_move_minus(short speed) { /* Line 1093, Address: 0x1022020 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1096, Address: 0x102202c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1097, Address: 0x1022050 */
  scrv_up_ch(lSpd); /* Line 1098, Address: 0x1022074 */
} /* Line 1099, Address: 0x1022080 */














static void scrv_up_ch(int_union lSpd) { /* Line 1114, Address: 0x1022090 */
  if (lSpd.w.l <= scralim_up) { /* Line 1115, Address: 0x102209c */
    if (lSpd.w.l > -256) { /* Line 1116, Address: 0x10220c4 */

      lSpd.w.l = scralim_up; /* Line 1118, Address: 0x10220dc */
    } else { /* Line 1119, Address: 0x10220e8 */
      lSpd.w.l &= 2047; /* Line 1120, Address: 0x10220f0 */
      actwk[0].yposi.w.l &= 2047; /* Line 1121, Address: 0x10220fc */
      scra_v_posit.w.h &= 2047; /* Line 1122, Address: 0x1022110 */
      scrb_v_posit.w.h &= 1023; /* Line 1123, Address: 0x1022124 */
    }
  }

  scrv_move(lSpd); /* Line 1127, Address: 0x1022138 */
} /* Line 1128, Address: 0x1022144 */













static void sv_move_plus(short sSpd) { /* Line 1142, Address: 0x1022160 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1145, Address: 0x102216c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1146, Address: 0x102218c */
  scrv_down_ch(lSpd); /* Line 1147, Address: 0x10221b0 */
} /* Line 1148, Address: 0x10221bc */














static void scrv_down_ch(int_union lSpd) { /* Line 1163, Address: 0x10221d0 */
  if (lSpd.w.l >= scralim_down) { /* Line 1164, Address: 0x10221dc */
    if (lSpd.w.l < 2048) { /* Line 1165, Address: 0x1022204 */

      lSpd.w.l = scralim_down; /* Line 1167, Address: 0x102221c */
    } else { /* Line 1168, Address: 0x1022228 */
      lSpd.w.l -= 2048; /* Line 1169, Address: 0x1022230 */
      actwk[0].yposi.w.l &= 2047; /* Line 1170, Address: 0x102223c */
      scra_v_posit.w.h -= 2048; /* Line 1171, Address: 0x1022250 */
      scrb_v_posit.w.h &= 1023; /* Line 1172, Address: 0x1022264 */
    }
  }

  scrv_move(lSpd); /* Line 1176, Address: 0x1022278 */
} /* Line 1177, Address: 0x1022284 */
















static void scrv_move(int_union lSpd) { /* Line 1194, Address: 0x10222a0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1198, Address: 0x10222b0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1199, Address: 0x10222c0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1200, Address: 0x10222e4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1201, Address: 0x10222f8 */
  scra_vz = spdwk.w.l; /* Line 1202, Address: 0x1022310 */

  scra_v_posit.l = lSpd.l; /* Line 1204, Address: 0x102231c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1206, Address: 0x1022328 */
  if (!ywk) { /* Line 1207, Address: 0x1022364 */
    scra_v_count ^= 16; /* Line 1208, Address: 0x102236c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1209, Address: 0x1022380 */
    if (ywk < 0) { /* Line 1210, Address: 0x10223ac */
      scrflaga.b.h |= 1; /* Line 1211, Address: 0x10223bc */
    } else { /* Line 1212, Address: 0x10223d0 */
      scrflaga.b.h |= 2; /* Line 1213, Address: 0x10223d8 */
    }
  }


} /* Line 1218, Address: 0x10223ec */

















void scrollwrt() { /* Line 1236, Address: 0x1022400 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1245, Address: 0x1022420 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1246, Address: 0x1022424 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1247, Address: 0x1022430 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1248, Address: 0x102243c */
  pScrFlag = &scrflagbw.b.h; /* Line 1249, Address: 0x1022444 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1250, Address: 0x102244c */

  VramBase = 16384; /* Line 1252, Address: 0x1022460 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1253, Address: 0x1022464 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1254, Address: 0x1022470 */
  pMapWk = (unsigned char*)mapwka; /* Line 1255, Address: 0x102247c */
  pScrFlag = &scrflagaw.b.h; /* Line 1256, Address: 0x1022484 */

  if (*pScrFlag) { /* Line 1258, Address: 0x102248c */
    if (*pScrFlag & 1) { /* Line 1259, Address: 0x1022498 */
      *pScrFlag &= 254; /* Line 1260, Address: 0x10224ac */

      lD4.l = -16; /* Line 1262, Address: 0x10224b8 */
      wD5 = 65520; /* Line 1263, Address: 0x10224c0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1265, Address: 0x10224c8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1267, Address: 0x10224e8 */
    }




    if (*pScrFlag & 2) { /* Line 1273, Address: 0x1022514 */
      *pScrFlag &= 253; /* Line 1274, Address: 0x1022528 */

      lD4.l = 224; /* Line 1276, Address: 0x1022534 */
      wD5 = 65520; /* Line 1277, Address: 0x102253c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1278, Address: 0x1022544 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1280, Address: 0x1022564 */
    }




    if (*pScrFlag & 4) { /* Line 1286, Address: 0x1022590 */
      *pScrFlag &= 251; /* Line 1287, Address: 0x10225a4 */

      lD4.l = -16; /* Line 1289, Address: 0x10225b0 */
      wD5 = 65520; /* Line 1290, Address: 0x10225b8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1291, Address: 0x10225c0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1293, Address: 0x10225e0 */
    }




    if (*pScrFlag & 8) { /* Line 1299, Address: 0x102260c */
      *pScrFlag &= 247; /* Line 1300, Address: 0x1022620 */

      lD4.l = -16; /* Line 1302, Address: 0x102262c */
      wD5 = 320; /* Line 1303, Address: 0x1022634 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1304, Address: 0x102263c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1306, Address: 0x102265c */
    }
  }






} /* Line 1315, Address: 0x1022688 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1332, Address: 0x10226b0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1343, Address: 0x10226dc */

  if (*pScrFlag & 1) { /* Line 1345, Address: 0x10226e4 */
    *pScrFlag &= 254; /* Line 1346, Address: 0x10226fc */
  } /* Line 1347, Address: 0x1022710 */
  else {
    *pScrFlag &= 254; /* Line 1349, Address: 0x1022718 */

    if (*pScrFlag & 2) { /* Line 1351, Address: 0x102272c */
      *pScrFlag &= 253; /* Line 1352, Address: 0x1022744 */
      lD4.w.l = 224; /* Line 1353, Address: 0x1022758 */
    } /* Line 1354, Address: 0x1022760 */
    else {
      *pScrFlag &= 253; /* Line 1356, Address: 0x1022768 */
      goto label1; /* Line 1357, Address: 0x102277c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1362, Address: 0x1022784 */
  wD0 &= 127; /* Line 1363, Address: 0x10227d4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1364, Address: 0x10227dc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1370, Address: 0x10227fc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1371, Address: 0x102281c */
  if (wD0 != 0) { /* Line 1372, Address: 0x1022840 */
    wD5 = 65520; /* Line 1373, Address: 0x102284c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1374, Address: 0x1022854 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1376, Address: 0x1022874 */



  } /* Line 1380, Address: 0x10228a0 */
  else {

    wD5 = 0; /* Line 1383, Address: 0x10228a8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1384, Address: 0x10228ac */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1388, Address: 0x10228cc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1395, Address: 0x10228f8 */






    lD4.l = -16; /* Line 1402, Address: 0x102290c */
    wD5 = 65520; /* Line 1403, Address: 0x1022914 */
    if (*pScrFlag & 168) { /* Line 1404, Address: 0x102291c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1405, Address: 0x1022934 */
      wD5 = 320; /* Line 1406, Address: 0x1022954 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1410, Address: 0x102295c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1412, Address: 0x102298c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1413, Address: 0x1022998 */



    for (i = 0; i < 16; ++i) { /* Line 1417, Address: 0x10229a8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1418, Address: 0x10229b4 */

      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1420, Address: 0x10229d4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1421, Address: 0x1022a0c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1422, Address: 0x1022a2c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1424, Address: 0x1022a50 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1427, Address: 0x1022a74 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1429, Address: 0x1022a94 */
      }
      lD4.w.l += 16; /* Line 1431, Address: 0x1022aa8 */
    } /* Line 1432, Address: 0x1022ab4 */
    *pScrFlag = 0; /* Line 1433, Address: 0x1022ac4 */
  }
} /* Line 1435, Address: 0x1022acc */





void scrollwrtc() {} /* Line 1441, Address: 0x1022b00 */




void scrollwrtz() {} /* Line 1446, Address: 0x1022b10 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1464, Address: 0x1022b20 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1477, Address: 0x1022b48 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1480, Address: 0x1022b68 */
    pTilePoint->x += 2; /* Line 1481, Address: 0x1022b7c */
    if (pTilePoint->x >= 64) { /* Line 1482, Address: 0x1022b90 */
      pTilePoint->x -= 64; /* Line 1483, Address: 0x1022ba4 */
    }
    xOffs += 16; /* Line 1485, Address: 0x1022bb8 */
  } while (--lpcnt >= 0); /* Line 1486, Address: 0x1022bc4 */
} /* Line 1487, Address: 0x1022bd8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1491, Address: 0x1022bf0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1495, Address: 0x1022c18 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1498, Address: 0x1022c38 */
    pTilePoint->x += 2; /* Line 1499, Address: 0x1022c4c */
    if (pTilePoint->x >= 64) { /* Line 1500, Address: 0x1022c60 */
      pTilePoint->x -= 64; /* Line 1501, Address: 0x1022c74 */
    }
    xOffs += 16; /* Line 1503, Address: 0x1022c88 */
  } while (--lpcnt >= 0); /* Line 1504, Address: 0x1022c94 */
} /* Line 1505, Address: 0x1022ca8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1525, Address: 0x1022cc0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1529, Address: 0x1022ce8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1532, Address: 0x1022d08 */
    pTilePoint->y += 2; /* Line 1533, Address: 0x1022d1c */
    if (pTilePoint->y >= 32) { /* Line 1534, Address: 0x1022d2c */
      pTilePoint->y -= 32; /* Line 1535, Address: 0x1022d40 */
    }
    yOffs += 16; /* Line 1537, Address: 0x1022d50 */
  } while (--lpcnt >= 0); /* Line 1538, Address: 0x1022d5c */
} /* Line 1539, Address: 0x1022d70 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1558, Address: 0x1022d80 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1564, Address: 0x1022db4 */

    base = 1; /* Line 1566, Address: 0x1022dc4 */
  } /* Line 1567, Address: 0x1022dc8 */
  else if (VramBase == 16384) { /* Line 1568, Address: 0x1022dd0 */

    base = 0; /* Line 1570, Address: 0x1022de0 */
  }
  x = pTilePoint->x; /* Line 1572, Address: 0x1022de4 */
  y = pTilePoint->y; /* Line 1573, Address: 0x1022dec */


  frip = BlkIndex & 6144; /* Line 1576, Address: 0x1022df4 */
  BlkIndex &= 1023; /* Line 1577, Address: 0x1022dfc */
  if (frip == 6144) { /* Line 1578, Address: 0x1022e08 */

    p0 = 3, p1 = 2; /* Line 1580, Address: 0x1022e14 */
    p2 = 1, p3 = 0; /* Line 1581, Address: 0x1022e1c */
  } /* Line 1582, Address: 0x1022e24 */
  else if (frip & 4096) { /* Line 1583, Address: 0x1022e2c */

    p0 = 2, p1 = 3; /* Line 1585, Address: 0x1022e38 */
    p2 = 0, p3 = 1; /* Line 1586, Address: 0x1022e40 */
  } /* Line 1587, Address: 0x1022e48 */
  else if (frip & 2048) { /* Line 1588, Address: 0x1022e50 */

    p0 = 1, p1 = 0; /* Line 1590, Address: 0x1022e5c */
    p2 = 3, p3 = 2; /* Line 1591, Address: 0x1022e64 */
  } /* Line 1592, Address: 0x1022e6c */
  else {

    p0 = 0, p1 = 1; /* Line 1595, Address: 0x1022e74 */
    p2 = 2, p3 = 3; /* Line 1596, Address: 0x1022e7c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1599, Address: 0x1022e84 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1600, Address: 0x1022ec8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1601, Address: 0x1022f0c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1602, Address: 0x1022f50 */

} /* Line 1604, Address: 0x1022f94 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1622, Address: 0x1022fd0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1623, Address: 0x1022ff0 */
} /* Line 1624, Address: 0x1023010 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1626, Address: 0x1023020 */
  wH_posiw = 0; /* Line 1627, Address: 0x1023040 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1628, Address: 0x1023044 */
} /* Line 1629, Address: 0x1023064 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1636, Address: 0x1023080 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1642, Address: 0x10230b0 */
  yOffs += wV_posiw; /* Line 1643, Address: 0x10230c0 */





  if ((short)xOffs < 0) /* Line 1649, Address: 0x10230d0 */
    xOffs = 0; /* Line 1650, Address: 0x10230ec */
  if ((short)yOffs < 0) /* Line 1651, Address: 0x10230f0 */
    yOffs = 0; /* Line 1652, Address: 0x102310c */
  if ((short)xOffs >= 16384) /* Line 1653, Address: 0x1023110 */
    xOffs = 16383; /* Line 1654, Address: 0x1023130 */
  if ((short)yOffs >= 2048) /* Line 1655, Address: 0x1023138 */
    yOffs = 2047; /* Line 1656, Address: 0x1023158 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1657, Address: 0x1023160 */
  if (i < 0) i = 0; /* Line 1658, Address: 0x10231a8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1660, Address: 0x10231b4 */

  if (ScreenNo) { /* Line 1662, Address: 0x10231d0 */




    xOffs &= 32767; /* Line 1667, Address: 0x10231d8 */
    yOffs &= 32767; /* Line 1668, Address: 0x10231e4 */


    xBlk = xOffs; /* Line 1671, Address: 0x10231f0 */
    xBlk %= 256; /* Line 1672, Address: 0x10231f8 */
    xBlk /= 16; /* Line 1673, Address: 0x1023218 */
    yBlk = yOffs; /* Line 1674, Address: 0x1023234 */
    yBlk %= 256; /* Line 1675, Address: 0x102323c */
    yBlk /= 16; /* Line 1676, Address: 0x102325c */

    lpw = pmapwk; /* Line 1678, Address: 0x1023278 */
    lpw += xBlk; /* Line 1679, Address: 0x1023280 */
    lpw += yBlk * 16; /* Line 1680, Address: 0x1023288 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1681, Address: 0x1023294 */
    *pIndex = *lpw; /* Line 1682, Address: 0x10232ac */

    return 1; /* Line 1684, Address: 0x10232bc */
  }

  *pIndex = 0; /* Line 1687, Address: 0x10232c8 */
  return 0; /* Line 1688, Address: 0x10232d0 */
} /* Line 1689, Address: 0x10232d4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1709, Address: 0x1023300 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1717, Address: 0x1023328 */
  if (ScreenNo) { /* Line 1718, Address: 0x102338c */





    xBlk = xOffs; /* Line 1724, Address: 0x1023394 */
    xBlk %= 256; /* Line 1725, Address: 0x102339c */
    xBlk /= 16; /* Line 1726, Address: 0x10233bc */
    yBlk = yOffs; /* Line 1727, Address: 0x10233d8 */
    yBlk %= 256; /* Line 1728, Address: 0x10233e0 */
    yBlk /= 16; /* Line 1729, Address: 0x1023400 */


    lpw = pmapwk; /* Line 1732, Address: 0x102341c */
    lpw += xBlk; /* Line 1733, Address: 0x1023424 */
    lpw += yBlk * 16; /* Line 1734, Address: 0x102342c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1735, Address: 0x1023438 */
    *ppBlockNo = lpw; /* Line 1736, Address: 0x1023450 */
    *pIndex = *lpw; /* Line 1737, Address: 0x1023458 */




    return 1; /* Line 1742, Address: 0x1023468 */
  }

  *pIndex = 0; /* Line 1745, Address: 0x1023474 */
  return 0; /* Line 1746, Address: 0x102347c */
} /* Line 1747, Address: 0x1023480 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1761, Address: 0x10234a0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1768, Address: 0x10234bc */
  pMapWk = (unsigned char*)mapwka; /* Line 1769, Address: 0x10234c0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1770, Address: 0x10234c8 */
    *pBlockIndex = BlockNo; /* Line 1771, Address: 0x10234ec */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1772, Address: 0x10234f8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1773, Address: 0x1023510 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1774, Address: 0x1023524 */
    }
  }


} /* Line 1779, Address: 0x102353c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1793, Address: 0x1023560 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1794, Address: 0x102356c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1795, Address: 0x1023598 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1796, Address: 0x10235e4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1797, Address: 0x1023610 */

          return 0; /* Line 1799, Address: 0x102365c */
        }
      }
    }
  }

  return 1; /* Line 1805, Address: 0x1023668 */
} /* Line 1806, Address: 0x102366c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1823, Address: 0x1023680 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1824, Address: 0x102369c */

} /* Line 1826, Address: 0x10236b8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1828, Address: 0x10236d0 */
  wH_posiw = 0; /* Line 1829, Address: 0x10236ec */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1830, Address: 0x10236f0 */

} /* Line 1832, Address: 0x102370c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1834, Address: 0x1023720 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1835, Address: 0x1023734 */

} /* Line 1837, Address: 0x1023750 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1839, Address: 0x1023760 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1840, Address: 0x102377c */

} /* Line 1842, Address: 0x1023798 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1844, Address: 0x10237b0 */
  xOffs += wH_posiw; /* Line 1845, Address: 0x10237c8 */
  yOffs += wV_posiw; /* Line 1846, Address: 0x10237d8 */
  yOffs &= 240; /* Line 1847, Address: 0x10237e8 */
  xOffs &= 496; /* Line 1848, Address: 0x10237f4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1850, Address: 0x1023800 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1851, Address: 0x102382c */


} /* Line 1854, Address: 0x1023858 */















void mapwrt() { /* Line 1870, Address: 0x1023870 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1875, Address: 0x1023888 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1876, Address: 0x1023894 */
  pMapWk = (unsigned char*)mapwka; /* Line 1877, Address: 0x10238a0 */
  VramBase = 16384; /* Line 1878, Address: 0x10238a8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1879, Address: 0x10238ac */
  mapwrtb(); /* Line 1880, Address: 0x10238c4 */
} /* Line 1881, Address: 0x10238cc */


void mapwrtb() { /* Line 1884, Address: 0x10238f0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scrb_h_posiw.w.h; /* Line 1889, Address: 0x1023908 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1890, Address: 0x1023914 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1891, Address: 0x1023920 */
  VramBase = 24576; /* Line 1892, Address: 0x1023928 */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1893, Address: 0x102392c */

} /* Line 1895, Address: 0x102393c */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1898, Address: 0x1023960 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1899, Address: 0x1023978 */
} /* Line 1900, Address: 0x1023998 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1905, Address: 0x10239b0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1909, Address: 0x10239d0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1912, Address: 0x10239ec */



    wD4 += 16; /* Line 1916, Address: 0x1023a14 */
  } while ((short)--wD6 >= 0); /* Line 1917, Address: 0x1023a20 */

} /* Line 1919, Address: 0x1023a48 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1925, Address: 0x1023a60 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1928, Address: 0x1023a7c */
  wD6 = 15; /* Line 1929, Address: 0x1023a84 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 1008; /* Line 1932, Address: 0x1023a8c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1934, Address: 0x1023ab0 */
    wD4 += 16; /* Line 1935, Address: 0x1023ad0 */
  } while ((short)--wD6 >= 0); /* Line 1936, Address: 0x1023ad8 */
} /* Line 1937, Address: 0x1023afc */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1963, Address: 0x1023b20 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1968, Address: 0x1023b48 */
  wD0 = pWrttbl[wD0]; /* Line 1969, Address: 0x1023b58 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1971, Address: 0x1023b74 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1972, Address: 0x1023b98 */
  if (wD0) { /* Line 1973, Address: 0x1023bc0 */
    wD5 = 65520; /* Line 1974, Address: 0x1023bcc */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1975, Address: 0x1023bd4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1978, Address: 0x1023bf0 */



  } /* Line 1982, Address: 0x1023c18 */
  else {

    wD5 = 0; /* Line 1985, Address: 0x1023c20 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1986, Address: 0x1023c24 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1990, Address: 0x1023c40 */
  }





} /* Line 1997, Address: 0x1023c68 */










void mapinit() { /* Line 2008, Address: 0x1023c90 */
  short tbl[9] = { /* Line 2009, Address: 0x1023cb0 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 2014, Address: 0x1023cdc */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  EnkeiNo = 0; /* Line 2020, Address: 0x1023d00 */
  pTbl = tbl; /* Line 2021, Address: 0x1023d04 */

  while ((poswk = *pTbl++) >= 0) { /* Line 2023, Address: 0x1023d08 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 2024, Address: 0x1023d10 */


    ++EnkeiNo; /* Line 2027, Address: 0x1023d34 */
  } /* Line 2028, Address: 0x1023d38 */


  TileNo = 597; /* Line 2031, Address: 0x1023d5c */
  if (EnkeiNo == 0) { /* Line 2032, Address: 0x1023d60 */
    i = 96; /* Line 2033, Address: 0x1023d68 */
    BmpNo = 0; /* Line 2034, Address: 0x1023d6c */

    for ( ; i > 0; --i) { /* Line 2036, Address: 0x1023d70 */
      ChangeTileBmp(TileNo++, BmpNo++); /* Line 2037, Address: 0x1023d78 */
    } /* Line 2038, Address: 0x1023d98 */
  }


  colorset2(mapinittbl.colorno2); /* Line 2042, Address: 0x1023da4 */
  colorset(mapinittbl.colorno2); /* Line 2043, Address: 0x1023db8 */


  if (play_start & 2) divdevset(); /* Line 2046, Address: 0x1023dcc */
} /* Line 2047, Address: 0x1023dec */




void mapset() {} /* Line 2052, Address: 0x1023e20 */



void divdevset() {} /* Line 2056, Address: 0x1023e30 */



void enecginit() {} /* Line 2060, Address: 0x1023e40 */
