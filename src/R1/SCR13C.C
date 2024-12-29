#include "..\EQU.H"
#include "SCR13C.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL1C.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk);
static void scrollb_hv(int xOffs, int yOffs);
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

static unsigned char z12cwrttbl[33] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 6,
  6, 6, 2, 4, 4, 4, 4, 0, 0, 0,
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
short scr_dir_tbl[6] = { 4, 0, 3479, 0, 784, 96 };
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
short playpositbl[1][2] = {
  { 64, 674 }
};
unsigned char playmapnotbl[4] = { 145, 127, 30, 30 };
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];
extern map_init_data mapinittbl;

















































































sprite_status* main_chk() {
  if (main_play == 0) { /* Line 153, Address: 0x1022300 */
    return &actwk[0]; /* Line 154, Address: 0x1022314 */
  }
  return &actwk[1]; /* Line 156, Address: 0x1022324 */

} /* Line 158, Address: 0x102232c */





































void scr_set() { /* Line 196, Address: 0x1022340 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 199, Address: 0x102234c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 200, Address: 0x1022360 */
  scr_timer.b.h = 0; /* Line 201, Address: 0x1022374 */

  pScrTbl = scr_dir_tbl; /* Line 203, Address: 0x102237c */
  scrar_no = *pScrTbl; /* Line 204, Address: 0x1022384 */
  ++pScrTbl; /* Line 205, Address: 0x1022390 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 206, Address: 0x1022394 */
  ++pScrTbl; /* Line 207, Address: 0x10223a8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 208, Address: 0x10223ac */
  ++pScrTbl; /* Line 209, Address: 0x10223c0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 210, Address: 0x10223c4 */
  ++pScrTbl; /* Line 211, Address: 0x10223d8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 212, Address: 0x10223dc */
  scra_h_keep = *pScrTbl + 576; /* Line 213, Address: 0x10223f0 */
  ++pScrTbl; /* Line 214, Address: 0x1022410 */
  scra_h_count = 16; /* Line 215, Address: 0x1022414 */
  scra_v_count = 16; /* Line 216, Address: 0x1022420 */

  scra_vline = *pScrTbl; /* Line 218, Address: 0x102242c */
  scra_hline = 160; /* Line 219, Address: 0x1022438 */

  playposiset(); /* Line 221, Address: 0x1022444 */
} /* Line 222, Address: 0x102244c */
















































static void playposiset() { /* Line 271, Address: 0x1022460 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 274, Address: 0x1022474 */
    playload(); /* Line 275, Address: 0x1022484 */
    xwk = actwk[0].xposi.w.h; /* Line 276, Address: 0x102248c */

    if (actwk[0].yposi.w.h > 0) { /* Line 278, Address: 0x102249c */
      ywk = actwk[0].yposi.w.h; /* Line 279, Address: 0x10224b4 */
    } /* Line 280, Address: 0x10224c4 */
    else ywk = 0; /* Line 281, Address: 0x10224cc */

  } /* Line 283, Address: 0x10224d0 */
  else {
    if (demoflag.w & -32768) { /* Line 285, Address: 0x10224d8 */
      pPositbl = endplpositbl[enddemono - 1]; /* Line 286, Address: 0x10224f8 */
    } /* Line 287, Address: 0x102251c */
    else {
      pPositbl = playpositbl[demoflag.w]; /* Line 289, Address: 0x1022524 */
    }


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 293, Address: 0x1022544 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 294, Address: 0x1022558 */
  }


  if (xwk > 160) { /* Line 298, Address: 0x102256c */
    xwk -= 160; /* Line 299, Address: 0x1022580 */
  } /* Line 300, Address: 0x102258c */
  else xwk = 0; /* Line 301, Address: 0x1022594 */



  if (xwk > scralim_right) { /* Line 305, Address: 0x1022598 */
    xwk = scralim_right; /* Line 306, Address: 0x10225bc */
  }


  scra_h_posit.w.h = xwk; /* Line 310, Address: 0x10225cc */

  if (ywk > 96) { /* Line 312, Address: 0x10225d4 */
    ywk -= 96; /* Line 313, Address: 0x10225e8 */
  } /* Line 314, Address: 0x10225f4 */
  else ywk = 0; /* Line 315, Address: 0x10225fc */



  if (ywk > scralim_down) { /* Line 319, Address: 0x1022600 */
    ywk = scralim_down; /* Line 320, Address: 0x1022624 */
  }


  scra_v_posit.w.h = ywk; /* Line 324, Address: 0x1022634 */

  scrbinit(xwk, ywk); /* Line 326, Address: 0x102263c */


  loopmapno = playmapnotbl[0]; /* Line 329, Address: 0x102264c */
  loopmapno2 = playmapnotbl[1]; /* Line 330, Address: 0x102265c */
  ballmapno = playmapnotbl[2]; /* Line 331, Address: 0x102266c */
  ballmapno2 = playmapnotbl[3]; /* Line 332, Address: 0x102267c */
} /* Line 333, Address: 0x102268c */




















static void scrbinit(short sXpos, short sYpos) { /* Line 354, Address: 0x10226b0 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 357, Address: 0x10226c0 */
  lYwk.w.l = 0; /* Line 358, Address: 0x10226c8 */

  lYwk.l = (lYwk.l >> 4) * 3; /* Line 360, Address: 0x10226cc */
  scrb_v_posit.l = lYwk.l; /* Line 361, Address: 0x10226e0 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 362, Address: 0x10226ec */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 363, Address: 0x10226f8 */

  sXpos >>= 3; /* Line 365, Address: 0x1022704 */
  scrb_h_posit.w.h = sXpos; /* Line 366, Address: 0x1022710 */

  sXpos >>= 1; /* Line 368, Address: 0x102271c */
  scrc_h_posit.w.h = sXpos * 3; /* Line 369, Address: 0x1022728 */

  sXpos >>= 1; /* Line 371, Address: 0x102274c */
  scrz_h_posit.w.h = sXpos * 3; /* Line 372, Address: 0x1022758 */
  sMemSet(hscrollwork, 0, 20); /* Line 373, Address: 0x102277c */
} /* Line 374, Address: 0x102279c */















void scroll() { /* Line 390, Address: 0x10227b0 */
  int_union ldwk, ldwk2, ldwk3;
  int_union* pHscrbuf;
  int i, j;
  int lXwk, lYwk;
  short sYline;
  short sYnum, sYnumsv;
  short *psHscr, *psHscw;
  short temp;
  static unsigned char z12c_cnttbl[5] = { 1, 3, 3, 3, 1 };
  static int scaddtbl[5] = { 65536, 57344, 49152, 40960, 32768 };

  if (scroll_start.b.h) return; /* Line 402, Address: 0x10227dc */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 407, Address: 0x10227ec */

  scrchk(); /* Line 409, Address: 0x1022818 */

  scroll_h(); /* Line 411, Address: 0x1022820 */
  scroll_v(); /* Line 412, Address: 0x1022828 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 414, Address: 0x1022830 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 415, Address: 0x1022840 */


  lXwk = (scra_hz << 3) * 3; /* Line 418, Address: 0x1022850 */
  scrollz_h(lXwk, 6); /* Line 419, Address: 0x102286c */

  lXwk = (scra_hz << 4) * 3; /* Line 421, Address: 0x102287c */
  scrollc_h(lXwk, 4); /* Line 422, Address: 0x1022898 */

  lXwk = scra_hz << 5; /* Line 424, Address: 0x10228a8 */
  lYwk = (scra_vz << 4) * 3; /* Line 425, Address: 0x10228bc */
  scrollb_hv(lXwk, lYwk); /* Line 426, Address: 0x10228dc */
  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 427, Address: 0x10228ec */

  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 429, Address: 0x1022914 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 430, Address: 0x102294c */

  for (i = 0, psHscr = hscrollwork; i < 5; ++i) { /* Line 432, Address: 0x1022960 */
    ldwk.w.l = psHscr[0]; /* Line 433, Address: 0x1022974 */
    ldwk.w.h = psHscr[1]; /* Line 434, Address: 0x102297c */
    ldwk.l += scaddtbl[i]; /* Line 435, Address: 0x1022984 */
    psHscr[0] = ldwk.w.l; /* Line 436, Address: 0x10229a4 */
    psHscr[1] = ldwk.w.h; /* Line 437, Address: 0x10229ac */
    psHscr += 2; /* Line 438, Address: 0x10229b4 */
  } /* Line 439, Address: 0x10229b8 */

  ldwk.w.l = -scra_h_posit.w.h; /* Line 441, Address: 0x10229c8 */
  { short wk = ldwk.w.l; ldwk.w.l = ldwk.w.h; ldwk.w.h = wk; } /* Line 442, Address: 0x10229e8 */
  psHscr = &hscrollwork[0]; /* Line 443, Address: 0x1022a00 */
  psHscw = &hscrollwork[10]; /* Line 444, Address: 0x1022a08 */

  for (i = 4; i >= 0; --i) { /* Line 446, Address: 0x1022a10 */

    ldwk2.w.l = *psHscr; /* Line 448, Address: 0x1022a1c */
    ++psHscr; /* Line 449, Address: 0x1022a24 */
    ldwk2.w.h = *psHscr; /* Line 450, Address: 0x1022a28 */
    ++psHscr; /* Line 451, Address: 0x1022a30 */
    { short wk = ldwk2.w.l; ldwk2.w.l = ldwk2.w.h; ldwk2.w.h = wk; } /* Line 452, Address: 0x1022a34 */
    ldwk2.w.l = -(ldwk2.w.l + scrz_h_posit.w.h); /* Line 453, Address: 0x1022a4c */

    for (j = z12c_cnttbl[i]; j >= 0; --j) { /* Line 455, Address: 0x1022a7c */

      *psHscw = ldwk2.w.l; /* Line 457, Address: 0x1022a98 */
      ++psHscw; /* Line 458, Address: 0x1022aa0 */
    } /* Line 459, Address: 0x1022aa4 */
  } /* Line 460, Address: 0x1022ab4 */

  ldwk.w.l = -scrz_h_posit.w.h; /* Line 462, Address: 0x1022ac0 */

  for (i = 0; i < 6; ++i) { /* Line 464, Address: 0x1022ae0 */

    *psHscw = ldwk.w.l; /* Line 466, Address: 0x1022aec */
    ++psHscw; /* Line 467, Address: 0x1022af4 */
  } /* Line 468, Address: 0x1022af8 */

  ldwk.w.l = -scrb_h_posit.w.h; /* Line 470, Address: 0x1022b08 */
  for (i = 0; i < 2; ++i) { /* Line 471, Address: 0x1022b28 */

    *psHscw = ldwk.w.l; /* Line 473, Address: 0x1022b34 */
    ++psHscw; /* Line 474, Address: 0x1022b3c */
  } /* Line 475, Address: 0x1022b40 */

  ldwk.w.l = -scrc_h_posit.w.h; /* Line 477, Address: 0x1022b50 */
  for (i = 0; i < 8; ++i) { /* Line 478, Address: 0x1022b70 */

    *psHscw = ldwk.w.l; /* Line 480, Address: 0x1022b7c */
    ++psHscw; /* Line 481, Address: 0x1022b84 */
  } /* Line 482, Address: 0x1022b88 */

  pHscrbuf = lphscrollbuff; /* Line 484, Address: 0x1022b98 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 485, Address: 0x1022ba4 */
  psHscr = &hscrollwork[sYnum / 2] + 10; /* Line 486, Address: 0x1022bd4 */
  sYnum = (unsigned short)sYnum >> 1; /* Line 487, Address: 0x1022c08 */
  sYnumsv = 28; /* Line 488, Address: 0x1022c24 */

  if ((sYline = 31 - sYnum) >= 0) { /* Line 490, Address: 0x1022c30 */
    if (sYline > 27) { /* Line 491, Address: 0x1022c68 */
      sYline = 27; /* Line 492, Address: 0x1022c7c */
    }
    sYnumsv -= sYline; /* Line 494, Address: 0x1022c88 */

    temp = sYline; /* Line 496, Address: 0x1022c94 */
    if (temp == 27) /* Line 497, Address: 0x1022c9c */
      ++temp; /* Line 498, Address: 0x1022cb0 */
    zonescrsetsub0(scrb_v_posit.w.h, temp, &pHscrbuf, psHscr); /* Line 499, Address: 0x1022cbc */
  }


  ldwk.w.l = scrc_h_posit.w.h; /* Line 503, Address: 0x1022cd8 */
  ldwk2.l = (scra_h_posit.w.h - ldwk.w.l) * 256 / 256 * 256; /* Line 504, Address: 0x1022ce4 */
  ldwk3.l = 0; /* Line 505, Address: 0x1022d28 */
  ldwk3.w.l = ldwk.w.l; /* Line 506, Address: 0x1022d2c */
  for (i = sYnumsv * 8 - 1; i >= 0; --i) { /* Line 507, Address: 0x1022d34 */

    ldwk.w.l = -ldwk3.w.l; /* Line 509, Address: 0x1022d4c */
    pHscrbuf->l = ldwk.l; /* Line 510, Address: 0x1022d68 */
    ++pHscrbuf; /* Line 511, Address: 0x1022d74 */
    { short wk = ldwk3.w.l; ldwk3.w.l = ldwk3.w.h; ldwk3.w.h = wk; } /* Line 512, Address: 0x1022d80 */
    ldwk3.l += ldwk2.l; /* Line 513, Address: 0x1022d98 */
    { short wk = ldwk3.w.l; ldwk3.w.l = ldwk3.w.h; ldwk3.w.h = wk; } /* Line 514, Address: 0x1022da8 */
  } /* Line 515, Address: 0x1022dc0 */
} /* Line 516, Address: 0x1022dcc */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 537, Address: 0x1022e00 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 541, Address: 0x1022e1c */

  for (i = 0, j = yoffs & 7; yline >= i; ++i, j = 0) { /* Line 543, Address: 0x1022e20 */
    ldwk.w.l = *pHscrwk; /* Line 544, Address: 0x1022e3c */
    ++pHscrwk; /* Line 545, Address: 0x1022e48 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 547, Address: 0x1022e54 */
      (*pHscrbuf)->l = ldwk.l; /* Line 548, Address: 0x1022e5c */
    } /* Line 549, Address: 0x1022e6c */
  } /* Line 550, Address: 0x1022e90 */
} /* Line 551, Address: 0x1022eb0 */





















static void scrollb_hv(int xOffs, int yOffs) { /* Line 573, Address: 0x1022ed0 */
  int lwk, lsv;
  int_union ldwk;

  lsv = scrb_h_posit.l; /* Line 577, Address: 0x1022ee4 */
  ldwk.l = scrb_h_posit.l = lwk = lsv + xOffs; /* Line 578, Address: 0x1022eec */
  if (((unsigned char)(ldwk.w.h & 16) ^ scrb_h_count) == 0) { /* Line 579, Address: 0x1022f00 */
    scrb_h_count ^= 16; /* Line 580, Address: 0x1022f30 */
    if (lwk - lsv < 0) { /* Line 581, Address: 0x1022f44 */
      scrflagb.b.h |= 4; /* Line 582, Address: 0x1022f50 */
    } /* Line 583, Address: 0x1022f64 */
    else {
      scrflagb.b.h |= 8; /* Line 585, Address: 0x1022f6c */
    }
  }


  lsv = scrb_v_posit.l; /* Line 590, Address: 0x1022f80 */
  ldwk.l = scrb_v_posit.l = lwk = lsv + yOffs; /* Line 591, Address: 0x1022f88 */
  if (((unsigned char)(ldwk.w.h & 16) ^ scrb_v_count) == 0) { /* Line 592, Address: 0x1022f9c */
    scrb_v_count ^= 16; /* Line 593, Address: 0x1022fcc */
    if (lwk - lsv < 0) { /* Line 594, Address: 0x1022fe0 */
      scrflagb.b.h |= 1; /* Line 595, Address: 0x1022fec */
    } /* Line 596, Address: 0x1023000 */
    else {
      scrflagb.b.h |= 2; /* Line 598, Address: 0x1023008 */
    }
  }


} /* Line 603, Address: 0x102301c */


































































































































static void scrollc_h(int xoffs, int flgbit) { /* Line 734, Address: 0x1023030 */
  int lXwk, lXsv;
  int_union ldXwk;
  short wk;
  lXsv = scrc_h_posit.l; /* Line 738, Address: 0x1023048 */
  lXwk = lXsv + xoffs; /* Line 739, Address: 0x1023050 */
  scrc_h_posit.l = lXwk; /* Line 740, Address: 0x1023058 */
  ldXwk.l = lXwk; /* Line 741, Address: 0x1023060 */
  wk = ldXwk.w.l, ldXwk.w.l = ldXwk.w.h, ldXwk.w.h = wk; /* Line 742, Address: 0x1023064 */
  ldXwk.w.l &= 16; /* Line 743, Address: 0x102307c */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 744, Address: 0x1023088 */

  if (!ldXwk.b.b4) { /* Line 746, Address: 0x10230a4 */
    scrc_h_count ^= 16; /* Line 747, Address: 0x10230b0 */
    if (lXwk - lXsv < 0) { /* Line 748, Address: 0x10230c4 */
      scrflagc.b.h |= 1 << flgbit; /* Line 749, Address: 0x10230d0 */
    } /* Line 750, Address: 0x10230f4 */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 752, Address: 0x10230fc */
    }
  }


} /* Line 757, Address: 0x1023124 */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 775, Address: 0x1023140 */
  int lXwk, lXsv;
  int_union ldXwk;
  short wk;
  lXsv = scrz_h_posit.l; /* Line 779, Address: 0x1023158 */
  lXwk = lXsv + xoffs; /* Line 780, Address: 0x1023160 */
  scrz_h_posit.l = lXwk; /* Line 781, Address: 0x1023168 */
  ldXwk.l = lXwk; /* Line 782, Address: 0x1023170 */
  wk = ldXwk.w.l, ldXwk.w.l = ldXwk.w.h, ldXwk.w.h = wk; /* Line 783, Address: 0x1023174 */
  ldXwk.w.l &= 16; /* Line 784, Address: 0x102318c */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 785, Address: 0x1023198 */

  if (!ldXwk.b.b4) { /* Line 787, Address: 0x10231b4 */
    scrz_h_count ^= 16; /* Line 788, Address: 0x10231c0 */
    if (lXwk - lXsv < 0) { /* Line 789, Address: 0x10231d4 */
      scrflagz.b.h |= 1 << flgbit; /* Line 790, Address: 0x10231e0 */
    } /* Line 791, Address: 0x1023204 */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 793, Address: 0x102320c */
    }
  }


} /* Line 798, Address: 0x1023234 */














static void scroll_h() { /* Line 813, Address: 0x1023250 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 817, Address: 0x1023260 */

  scrh_move(); /* Line 819, Address: 0x1023270 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 820, Address: 0x1023278 */
  if (!bXwk) { /* Line 821, Address: 0x10232ac */
    scra_h_count ^= 16; /* Line 822, Address: 0x10232b4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 823, Address: 0x10232c8 */
      scrflaga.b.h |= 4; /* Line 824, Address: 0x10232ec */
    } /* Line 825, Address: 0x1023300 */
    else scrflaga.b.h |= 8; /* Line 826, Address: 0x1023308 */
  }



} /* Line 831, Address: 0x102331c */
















static void scrh_move() { /* Line 848, Address: 0x1023340 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 851, Address: 0x1023348 */
  if (xwk == 0) { /* Line 852, Address: 0x1023390 */

    scra_hz = 0; /* Line 854, Address: 0x10233a0 */
    return; /* Line 855, Address: 0x10233a8 */
  } else if (xwk < 0) { /* Line 856, Address: 0x10233b0 */

    if (xwk < -16) { /* Line 858, Address: 0x10233c0 */
      xwk = -16; /* Line 859, Address: 0x10233d4 */
    }


    xwk += scra_h_posit.w.h; /* Line 863, Address: 0x10233e0 */
    if (xwk < scralim_left) { /* Line 864, Address: 0x10233f4 */
      xwk = scralim_left; /* Line 865, Address: 0x1023418 */
    }
  } /* Line 867, Address: 0x1023428 */
  else {
    if (xwk > 16) { /* Line 869, Address: 0x1023430 */
      xwk = 16; /* Line 870, Address: 0x1023444 */
    }


    xwk += scra_h_posit.w.h; /* Line 874, Address: 0x1023450 */
    if (xwk > scralim_right) { /* Line 875, Address: 0x1023464 */
      xwk = scralim_right; /* Line 876, Address: 0x1023488 */
    }
  }


  scra_hz = xwk - scra_h_posit.w.h << 8; /* Line 881, Address: 0x1023498 */
  scra_h_posit.w.h = xwk; /* Line 882, Address: 0x10234c8 */
} /* Line 883, Address: 0x10234d0 */














static void scroll_v() { /* Line 898, Address: 0x10234e0 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 901, Address: 0x10234ec */
  if (actwk[0].cddat & 4) { /* Line 902, Address: 0x1023520 */
    ywk -= 5; /* Line 903, Address: 0x1023538 */
  }


  if (actwk[0].cddat & 2) { /* Line 907, Address: 0x1023544 */
    ywk += 32; /* Line 908, Address: 0x102355c */
    if (ywk < scra_vline) { /* Line 909, Address: 0x1023568 */
      ywk -= scra_vline; /* Line 910, Address: 0x102358c */
      sv_move_main2(ywk); /* Line 911, Address: 0x10235a0 */
      return; /* Line 912, Address: 0x10235ac */
    } else if (ywk >= scra_vline + 64) { /* Line 913, Address: 0x10235b4 */
      ywk -= scra_vline + 64; /* Line 914, Address: 0x10235dc */
      sv_move_main2(ywk); /* Line 915, Address: 0x1023604 */
      return; /* Line 916, Address: 0x1023610 */
    }
    ywk -= scra_vline + 64; /* Line 918, Address: 0x1023618 */
    if (!limmoveflag) goto label1; /* Line 919, Address: 0x1023640 */
    sv_move_sub2(); /* Line 920, Address: 0x1023650 */
    return; /* Line 921, Address: 0x1023658 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 926, Address: 0x1023660 */
    sv_move_main(ywk); /* Line 927, Address: 0x102368c */
    return; /* Line 928, Address: 0x1023698 */
  } else if (limmoveflag) { /* Line 929, Address: 0x10236a0 */
    sv_move_sub2(); /* Line 930, Address: 0x10236b0 */
    return; /* Line 931, Address: 0x10236b8 */
  }


label1:
  scra_vz = 0; /* Line 936, Address: 0x10236c0 */
} /* Line 937, Address: 0x10236c8 */













static void sv_move_main(short yPos) { /* Line 951, Address: 0x10236e0 */
  short spdwk;

  if (scra_vline == 96) { /* Line 954, Address: 0x10236f0 */
    if (actwk[0].mspeed.w < 0) { /* Line 955, Address: 0x102370c */
      spdwk = -actwk[0].mspeed.w; /* Line 956, Address: 0x1023724 */
    } else { /* Line 957, Address: 0x1023748 */
      spdwk = actwk[0].mspeed.w; /* Line 958, Address: 0x1023750 */
    }


    if (spdwk >= 2048) { /* Line 962, Address: 0x1023760 */
      sv_move_main2(yPos); /* Line 963, Address: 0x1023774 */
    } /* Line 964, Address: 0x1023780 */
    else {

      if (yPos > 6) { /* Line 967, Address: 0x1023788 */
        sv_move_plus(1536); /* Line 968, Address: 0x10237a0 */
      } else if (yPos < -6) { /* Line 969, Address: 0x10237ac */
        sv_move_minus(1536); /* Line 970, Address: 0x10237cc */
      } else /* Line 971, Address: 0x10237d8 */
        sv_move_sub(yPos); /* Line 972, Address: 0x10237e0 */
    }
  } /* Line 974, Address: 0x10237ec */
  else {
    if (yPos > 2) { /* Line 976, Address: 0x10237f4 */
      sv_move_plus(512); /* Line 977, Address: 0x102380c */
    } else if (yPos < -2) { /* Line 978, Address: 0x1023818 */
      sv_move_minus(512); /* Line 979, Address: 0x1023838 */
    } else { /* Line 980, Address: 0x1023844 */
      sv_move_sub(yPos); /* Line 981, Address: 0x102384c */
    }
  }
} /* Line 984, Address: 0x1023858 */













static void sv_move_main2(short yPos) { /* Line 998, Address: 0x1023870 */
  short spdwk;

  spdwk = 4096; /* Line 1001, Address: 0x1023880 */

  if (yPos > 16) { /* Line 1003, Address: 0x102388c */
    sv_move_plus(spdwk); /* Line 1004, Address: 0x10238a4 */
  } else if (yPos < -16) { /* Line 1005, Address: 0x10238b0 */
    sv_move_minus(spdwk); /* Line 1006, Address: 0x10238d0 */
  } else { /* Line 1007, Address: 0x10238dc */
    sv_move_sub(yPos); /* Line 1008, Address: 0x10238e4 */
  }
} /* Line 1010, Address: 0x10238f0 */














static void sv_move_sub(short yPos) { /* Line 1025, Address: 0x1023910 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1028, Address: 0x102391c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1029, Address: 0x1023920 */
  if (yPos < 0) { /* Line 1030, Address: 0x102394c */
    scrv_up_ch(lSpd); /* Line 1031, Address: 0x1023960 */
  } else { /* Line 1032, Address: 0x102396c */
    scrv_down_ch(lSpd); /* Line 1033, Address: 0x1023974 */
  }
} /* Line 1035, Address: 0x1023980 */



static void sv_move_sub2() { /* Line 1039, Address: 0x1023990 */
  limmoveflag = 0; /* Line 1040, Address: 0x1023998 */

  sv_move_sub(0); /* Line 1042, Address: 0x10239a0 */
} /* Line 1043, Address: 0x10239ac */













static void sv_move_minus(short speed) { /* Line 1057, Address: 0x10239c0 */
  int_union lSpd;
  short wk;
  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1060, Address: 0x10239d0 */
  wk = lSpd.w.l, lSpd.w.l = lSpd.w.h, lSpd.w.h = wk; /* Line 1061, Address: 0x10239f4 */
  scrv_up_ch(lSpd); /* Line 1062, Address: 0x1023a0c */
} /* Line 1063, Address: 0x1023a18 */














static void scrv_up_ch(int_union lSpd) { /* Line 1078, Address: 0x1023a30 */
  if (lSpd.w.l <= scralim_up) { /* Line 1079, Address: 0x1023a3c */
    if (lSpd.w.l > -256) { /* Line 1080, Address: 0x1023a64 */

      lSpd.w.l = scralim_up; /* Line 1082, Address: 0x1023a7c */
    } else { /* Line 1083, Address: 0x1023a88 */
      lSpd.w.l &= 2047; /* Line 1084, Address: 0x1023a90 */
      actwk[0].yposi.w.h &= 2047; /* Line 1085, Address: 0x1023a9c */
      scra_v_posit.w.h &= 2047; /* Line 1086, Address: 0x1023ab0 */
      scrb_v_posit.w.h &= 1023; /* Line 1087, Address: 0x1023ac4 */
    }
  }

  scrv_move(lSpd); /* Line 1091, Address: 0x1023ad8 */
} /* Line 1092, Address: 0x1023ae4 */













static void sv_move_plus(short sSpd) { /* Line 1106, Address: 0x1023b00 */
  int_union lSpd;
  short wk;
  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1109, Address: 0x1023b10 */
  wk = lSpd.w.l, lSpd.w.l = lSpd.w.h, lSpd.w.h = wk; /* Line 1110, Address: 0x1023b30 */
  scrv_down_ch(lSpd); /* Line 1111, Address: 0x1023b48 */
} /* Line 1112, Address: 0x1023b54 */














static void scrv_down_ch(int_union lSpd) { /* Line 1127, Address: 0x1023b70 */
  if (lSpd.w.l >= scralim_down) { /* Line 1128, Address: 0x1023b7c */
    if (lSpd.w.l < 2048) { /* Line 1129, Address: 0x1023ba4 */

      lSpd.w.l = scralim_down; /* Line 1131, Address: 0x1023bbc */
    } else { /* Line 1132, Address: 0x1023bc8 */
      lSpd.w.l -= 2048; /* Line 1133, Address: 0x1023bd0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1134, Address: 0x1023bdc */
      scra_v_posit.w.h -= 2048; /* Line 1135, Address: 0x1023bf0 */
      scrb_v_posit.w.h &= 1023; /* Line 1136, Address: 0x1023c04 */
    }
  }

  scrv_move(lSpd); /* Line 1140, Address: 0x1023c18 */
} /* Line 1141, Address: 0x1023c24 */
















static void scrv_move(int_union lSpd) { /* Line 1158, Address: 0x1023c40 */
  short ywk, ysv;
  uint_union spdwk;
  short wk;
  ysv = scra_v_posit.w.h; /* Line 1162, Address: 0x1023c54 */
  wk = lSpd.w.l, lSpd.w.l = lSpd.w.h, lSpd.w.h = wk; /* Line 1163, Address: 0x1023c64 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1164, Address: 0x1023c7c */
  spdwk.l = (spdwk.l >> 8) | (spdwk.l << 24); /* Line 1165, Address: 0x1023c90 */
  scra_vz = spdwk.w.l; /* Line 1166, Address: 0x1023ca8 */

  scra_v_posit.l = lSpd.l; /* Line 1168, Address: 0x1023cb4 */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1170, Address: 0x1023cc0 */
  if (!ywk) { /* Line 1171, Address: 0x1023cfc */
    scra_v_count ^= 16; /* Line 1172, Address: 0x1023d04 */
    ywk = scra_v_posit.w.h - ysv; /* Line 1173, Address: 0x1023d18 */
    if (ywk < 0) { /* Line 1174, Address: 0x1023d44 */
      scrflaga.b.h |= 1; /* Line 1175, Address: 0x1023d54 */
    } else { /* Line 1176, Address: 0x1023d68 */
      scrflaga.b.h |= 2; /* Line 1177, Address: 0x1023d70 */
    }
  }


} /* Line 1182, Address: 0x1023d84 */

















void scrollwrt() { /* Line 1200, Address: 0x1023da0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1209, Address: 0x1023dc0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1210, Address: 0x1023dc4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1211, Address: 0x1023dd0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1212, Address: 0x1023ddc */
  pScrFlag = &scrflagbw.b.h; /* Line 1213, Address: 0x1023de4 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1214, Address: 0x1023dec */

  VramBase = 16384; /* Line 1216, Address: 0x1023e00 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1217, Address: 0x1023e04 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1218, Address: 0x1023e10 */
  pMapWk = (unsigned char*)mapwka; /* Line 1219, Address: 0x1023e1c */
  pScrFlag = &scrflagaw.b.h; /* Line 1220, Address: 0x1023e24 */

  if (*pScrFlag) { /* Line 1222, Address: 0x1023e2c */
    if (*pScrFlag & 1) { /* Line 1223, Address: 0x1023e38 */
      *pScrFlag &= 254; /* Line 1224, Address: 0x1023e4c */

      lD4.l = -16; /* Line 1226, Address: 0x1023e58 */
      wD5 = 65520; /* Line 1227, Address: 0x1023e60 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1229, Address: 0x1023e68 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1231, Address: 0x1023e88 */
    }




    if (*pScrFlag & 2) { /* Line 1237, Address: 0x1023eb4 */
      *pScrFlag &= 253; /* Line 1238, Address: 0x1023ec8 */

      lD4.l = 224; /* Line 1240, Address: 0x1023ed4 */
      wD5 = 65520; /* Line 1241, Address: 0x1023edc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1242, Address: 0x1023ee4 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1244, Address: 0x1023f04 */
    }




    if (*pScrFlag & 4) { /* Line 1250, Address: 0x1023f30 */
      *pScrFlag &= 251; /* Line 1251, Address: 0x1023f44 */

      lD4.l = -16; /* Line 1253, Address: 0x1023f50 */
      wD5 = 65520; /* Line 1254, Address: 0x1023f58 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1255, Address: 0x1023f60 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1257, Address: 0x1023f80 */
    }




    if (*pScrFlag & 8) { /* Line 1263, Address: 0x1023fac */
      *pScrFlag &= 247; /* Line 1264, Address: 0x1023fc0 */

      lD4.l = -16; /* Line 1266, Address: 0x1023fcc */
      wD5 = 320; /* Line 1267, Address: 0x1023fd4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1268, Address: 0x1023fdc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1270, Address: 0x1023ffc */
    }
  }






} /* Line 1279, Address: 0x1024028 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1296, Address: 0x1024050 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1307, Address: 0x102407c */

  if (*pScrFlag & 1) { /* Line 1309, Address: 0x1024084 */
    *pScrFlag &= 254; /* Line 1310, Address: 0x102409c */
  } /* Line 1311, Address: 0x10240b0 */
  else {
    *pScrFlag &= 254; /* Line 1313, Address: 0x10240b8 */

    if (*pScrFlag & 2) { /* Line 1315, Address: 0x10240cc */
      *pScrFlag &= 253; /* Line 1316, Address: 0x10240e4 */
      lD4.w.l = 224; /* Line 1317, Address: 0x10240f8 */
    } /* Line 1318, Address: 0x1024100 */
    else {
      *pScrFlag &= 253; /* Line 1320, Address: 0x1024108 */
      goto label1; /* Line 1321, Address: 0x102411c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1326, Address: 0x1024124 */
  wD0 &= 127; /* Line 1327, Address: 0x1024174 */
  wD0 = z12cwrttbl[wD0 + 1]; /* Line 1328, Address: 0x102417c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1334, Address: 0x102419c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1335, Address: 0x10241bc */
  if (wD0 != 0) { /* Line 1336, Address: 0x10241e0 */
    wD5 = 65520; /* Line 1337, Address: 0x10241ec */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1338, Address: 0x10241f4 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1340, Address: 0x1024214 */



  } /* Line 1344, Address: 0x1024240 */
  else {

    wD5 = 0; /* Line 1347, Address: 0x1024248 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1348, Address: 0x102424c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1352, Address: 0x102426c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1359, Address: 0x1024298 */






    lD4.l = -16; /* Line 1366, Address: 0x10242ac */
    wD5 = 65520; /* Line 1367, Address: 0x10242b4 */
    if (*pScrFlag & 168) { /* Line 1368, Address: 0x10242bc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1369, Address: 0x10242d4 */
      wD5 = 320; /* Line 1370, Address: 0x10242f4 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1374, Address: 0x10242fc */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1376, Address: 0x102432c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1377, Address: 0x1024338 */



    for (i = 0; i < 16; ++i) { /* Line 1381, Address: 0x1024348 */
      wD0 = z12cwrttbl[WrtTblCnt++]; /* Line 1382, Address: 0x1024354 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1383, Address: 0x1024374 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1384, Address: 0x10243a0 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1385, Address: 0x10243c0 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1387, Address: 0x10243e4 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1390, Address: 0x1024408 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1392, Address: 0x1024428 */
      }
      lD4.w.l += 16; /* Line 1394, Address: 0x102443c */
    } /* Line 1395, Address: 0x1024448 */
    *pScrFlag = 0; /* Line 1396, Address: 0x1024458 */
  }
} /* Line 1398, Address: 0x1024460 */





void scrollwrtc() {} /* Line 1404, Address: 0x1024490 */




void scrollwrtz() {} /* Line 1409, Address: 0x10244a0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1427, Address: 0x10244b0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1440, Address: 0x10244d8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1443, Address: 0x10244f8 */
    pTilePoint->x += 2; /* Line 1444, Address: 0x102450c */
    if (pTilePoint->x >= 64) { /* Line 1445, Address: 0x1024520 */
      pTilePoint->x -= 64; /* Line 1446, Address: 0x1024534 */
    }
    xOffs += 16; /* Line 1448, Address: 0x1024548 */
  } while (--lpcnt >= 0); /* Line 1449, Address: 0x1024554 */
} /* Line 1450, Address: 0x1024568 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1454, Address: 0x1024580 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1458, Address: 0x10245a8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1461, Address: 0x10245c8 */
    pTilePoint->x += 2; /* Line 1462, Address: 0x10245dc */
    if (pTilePoint->x >= 64) { /* Line 1463, Address: 0x10245f0 */
      pTilePoint->x -= 64; /* Line 1464, Address: 0x1024604 */
    }
    xOffs += 16; /* Line 1466, Address: 0x1024618 */
  } while (--lpcnt >= 0); /* Line 1467, Address: 0x1024624 */
} /* Line 1468, Address: 0x1024638 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1488, Address: 0x1024650 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1492, Address: 0x1024678 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1495, Address: 0x1024698 */
    pTilePoint->y += 2; /* Line 1496, Address: 0x10246ac */
    if (pTilePoint->y >= 32) { /* Line 1497, Address: 0x10246bc */
      pTilePoint->y -= 32; /* Line 1498, Address: 0x10246d0 */
    }
    yOffs += 16; /* Line 1500, Address: 0x10246e0 */
  } while (--lpcnt >= 0); /* Line 1501, Address: 0x10246ec */
} /* Line 1502, Address: 0x1024700 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1521, Address: 0x1024710 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) /* Line 1527, Address: 0x1024744 */
  {
    base = 1; /* Line 1529, Address: 0x1024754 */
  } /* Line 1530, Address: 0x1024758 */
  else if (VramBase == 16384) /* Line 1531, Address: 0x1024760 */
  {
    base = 0; /* Line 1533, Address: 0x1024770 */
  }
  x = pTilePoint->x; /* Line 1535, Address: 0x1024774 */
  y = pTilePoint->y; /* Line 1536, Address: 0x102477c */


  frip = BlkIndex & 6144; /* Line 1539, Address: 0x1024784 */
  BlkIndex &= 1023; /* Line 1540, Address: 0x102478c */
  if (frip == 6144) /* Line 1541, Address: 0x1024798 */
  {
    p0 = 3, p1 = 2; /* Line 1543, Address: 0x10247a4 */
    p2 = 1, p3 = 0; /* Line 1544, Address: 0x10247ac */
  } /* Line 1545, Address: 0x10247b4 */
  else if (frip & 4096) /* Line 1546, Address: 0x10247bc */
  {
    p0 = 2, p1 = 3; /* Line 1548, Address: 0x10247c8 */
    p2 = 0, p3 = 1; /* Line 1549, Address: 0x10247d0 */
  } /* Line 1550, Address: 0x10247d8 */
  else if (frip & 2048) /* Line 1551, Address: 0x10247e0 */
  {
    p0 = 1, p1 = 0; /* Line 1553, Address: 0x10247ec */
    p2 = 3, p3 = 2; /* Line 1554, Address: 0x10247f4 */
  } /* Line 1555, Address: 0x10247fc */
  else
  {
    p0 = 0, p1 = 1; /* Line 1558, Address: 0x1024804 */
    p2 = 2, p3 = 3; /* Line 1559, Address: 0x102480c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1562, Address: 0x1024814 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1563, Address: 0x1024858 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1564, Address: 0x102489c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1565, Address: 0x10248e0 */

} /* Line 1567, Address: 0x1024924 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1585, Address: 0x1024960 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1586, Address: 0x1024980 */
} /* Line 1587, Address: 0x10249a0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1589, Address: 0x10249b0 */
  wH_posiw = 0; /* Line 1590, Address: 0x10249d0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1591, Address: 0x10249d4 */
} /* Line 1592, Address: 0x10249f4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1599, Address: 0x1024a10 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1605, Address: 0x1024a40 */
  yOffs += wV_posiw; /* Line 1606, Address: 0x1024a50 */





  if ((short)xOffs < 0) /* Line 1612, Address: 0x1024a60 */
    xOffs = 0; /* Line 1613, Address: 0x1024a7c */
  if ((short)yOffs < 0) /* Line 1614, Address: 0x1024a80 */
    yOffs = 0; /* Line 1615, Address: 0x1024a9c */
  if ((short)xOffs >= 16384) /* Line 1616, Address: 0x1024aa0 */
    xOffs = 16383; /* Line 1617, Address: 0x1024ac0 */
  if ((short)yOffs >= 2048) /* Line 1618, Address: 0x1024ac8 */
    yOffs = 2047; /* Line 1619, Address: 0x1024ae8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1620, Address: 0x1024af0 */
  if (i < 0) i = 0; /* Line 1621, Address: 0x1024b38 */

  ScreenNo = pMapWk[i] & 127; /* Line 1623, Address: 0x1024b44 */

  if (ScreenNo) { /* Line 1625, Address: 0x1024b60 */




    xOffs &= 32767; /* Line 1630, Address: 0x1024b68 */
    yOffs &= 32767; /* Line 1631, Address: 0x1024b74 */


    xBlk = xOffs; /* Line 1634, Address: 0x1024b80 */
    xBlk %= 256; /* Line 1635, Address: 0x1024b88 */
    xBlk /= 16; /* Line 1636, Address: 0x1024ba8 */
    yBlk = yOffs; /* Line 1637, Address: 0x1024bc4 */
    yBlk %= 256; /* Line 1638, Address: 0x1024bcc */
    yBlk /= 16; /* Line 1639, Address: 0x1024bec */

    lpw = pmapwk; /* Line 1641, Address: 0x1024c08 */
    lpw += xBlk; /* Line 1642, Address: 0x1024c10 */
    lpw += yBlk * 16; /* Line 1643, Address: 0x1024c18 */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1644, Address: 0x1024c24 */
    *pIndex = *lpw; /* Line 1645, Address: 0x1024c3c */

    return 1; /* Line 1647, Address: 0x1024c4c */
  }

  *pIndex = 0; /* Line 1650, Address: 0x1024c58 */
  return 0; /* Line 1651, Address: 0x1024c60 */
} /* Line 1652, Address: 0x1024c64 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1672, Address: 0x1024c90 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1680, Address: 0x1024cb8 */
  if (ScreenNo) { /* Line 1681, Address: 0x1024d1c */





    xBlk = xOffs; /* Line 1687, Address: 0x1024d24 */
    xBlk %= 256; /* Line 1688, Address: 0x1024d2c */
    xBlk /= 16; /* Line 1689, Address: 0x1024d4c */
    yBlk = yOffs; /* Line 1690, Address: 0x1024d68 */
    yBlk %= 256; /* Line 1691, Address: 0x1024d70 */
    yBlk /= 16; /* Line 1692, Address: 0x1024d90 */


    lpw = pmapwk; /* Line 1695, Address: 0x1024dac */
    lpw += xBlk; /* Line 1696, Address: 0x1024db4 */
    lpw += yBlk * 16; /* Line 1697, Address: 0x1024dbc */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1698, Address: 0x1024dc8 */
    *ppBlockNo = lpw; /* Line 1699, Address: 0x1024de0 */
    *pIndex = *lpw; /* Line 1700, Address: 0x1024de8 */




    return 1; /* Line 1705, Address: 0x1024df8 */
  }

  *pIndex = 0; /* Line 1708, Address: 0x1024e04 */
  return 0; /* Line 1709, Address: 0x1024e0c */
} /* Line 1710, Address: 0x1024e10 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1724, Address: 0x1024e30 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1731, Address: 0x1024e4c */
  pMapWk = (unsigned char*)mapwka; /* Line 1732, Address: 0x1024e50 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1733, Address: 0x1024e58 */
    *pBlockIndex = BlockNo; /* Line 1734, Address: 0x1024e7c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1735, Address: 0x1024e88 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1736, Address: 0x1024ea0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1737, Address: 0x1024eb4 */
    }
  }


} /* Line 1742, Address: 0x1024ecc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1756, Address: 0x1024ef0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1757, Address: 0x1024efc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1758, Address: 0x1024f28 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1759, Address: 0x1024f74 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1760, Address: 0x1024fa0 */

          return 0; /* Line 1762, Address: 0x1024fec */
        }
      }
    }
  }

  return 1; /* Line 1768, Address: 0x1024ff8 */
} /* Line 1769, Address: 0x1024ffc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1786, Address: 0x1025010 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1787, Address: 0x102502c */

} /* Line 1789, Address: 0x1025048 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1791, Address: 0x1025060 */
  wH_posiw = 0; /* Line 1792, Address: 0x102507c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1793, Address: 0x1025080 */

} /* Line 1795, Address: 0x102509c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1797, Address: 0x10250b0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1798, Address: 0x10250c4 */

} /* Line 1800, Address: 0x10250e0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1802, Address: 0x10250f0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1803, Address: 0x102510c */

} /* Line 1805, Address: 0x1025128 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1807, Address: 0x1025140 */
  xOffs += wH_posiw; /* Line 1808, Address: 0x1025158 */
  yOffs += wV_posiw; /* Line 1809, Address: 0x1025168 */
  yOffs &= 240; /* Line 1810, Address: 0x1025178 */
  xOffs &= 496; /* Line 1811, Address: 0x1025184 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1813, Address: 0x1025190 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1814, Address: 0x10251bc */


} /* Line 1817, Address: 0x10251e8 */















void mapwrt() { /* Line 1833, Address: 0x1025200 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1838, Address: 0x1025218 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1839, Address: 0x1025224 */
  pMapWk = (unsigned char*)mapwka; /* Line 1840, Address: 0x1025230 */
  VramBase = 16384; /* Line 1841, Address: 0x1025238 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1842, Address: 0x102523c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1846, Address: 0x1025254 */
  VramBase = 24576; /* Line 1847, Address: 0x102525c */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1848, Address: 0x1025260 */

} /* Line 1850, Address: 0x1025270 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1853, Address: 0x1025290 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1854, Address: 0x10252a8 */
} /* Line 1855, Address: 0x10252c8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1860, Address: 0x10252e0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1864, Address: 0x1025300 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1867, Address: 0x102531c */



    wD4 += 16; /* Line 1871, Address: 0x1025344 */
  } while ((short)--wD6 >= 0); /* Line 1872, Address: 0x1025350 */

} /* Line 1874, Address: 0x1025378 */





void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1880, Address: 0x1025390 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1883, Address: 0x10253ac */
  wD6 = 15; /* Line 1884, Address: 0x10253b4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 496; /* Line 1887, Address: 0x10253bc */

    mapwrt_sub(&z12cwrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1889, Address: 0x10253e0 */
    wD4 += 16; /* Line 1890, Address: 0x1025400 */
  } while ((short)--wD6 >= 0); /* Line 1891, Address: 0x1025408 */
} /* Line 1892, Address: 0x102542c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1918, Address: 0x1025450 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1923, Address: 0x1025478 */
  wD0 = pWrttbl[wD0]; /* Line 1924, Address: 0x1025488 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1926, Address: 0x10254a4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1927, Address: 0x10254c8 */
  if (wD0) { /* Line 1928, Address: 0x10254f0 */
    wD5 = 65520; /* Line 1929, Address: 0x10254fc */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1930, Address: 0x1025504 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1933, Address: 0x1025520 */



  } /* Line 1937, Address: 0x1025548 */
  else {

    wD5 = 0; /* Line 1940, Address: 0x1025550 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1941, Address: 0x1025554 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1945, Address: 0x1025570 */
  }





} /* Line 1952, Address: 0x1025598 */










void mapinit() { /* Line 1963, Address: 0x10255c0 */

  colorset2(mapinittbl.colorno2); /* Line 1965, Address: 0x10255c8 */
  colorset(mapinittbl.colorno2); /* Line 1966, Address: 0x10255dc */


  if (play_start & 2) divdevset(); /* Line 1969, Address: 0x10255f0 */
} /* Line 1970, Address: 0x1025610 */




void mapset() {} /* Line 1975, Address: 0x1025620 */



void divdevset() {} /* Line 1979, Address: 0x1025630 */



void enecginit() {} /* Line 1983, Address: 0x1025640 */
