#include "..\EQU.H"
#include "SCR51A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL5A.H"

static void playposiset();
static void scrbinit(short sXpos, short sYpos);
static void z51cline(short** ppHscw);
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
unsigned char playmapnotbl[4] = { 127, 127, 21, 127 };
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;
extern unsigned char* zonemaptbl[];





























































































void enkeichg() { /* Line 151, Address: 0x10287a0 */
  short tbl[6] = { /* Line 152, Address: 0x10287c0 */
    3584, 7168, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 156, Address: 0x10287f4 */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  if (scrflaga.b.h) return; /* Line 162, Address: 0x1028818 */



  EnkeiNo = 0; /* Line 166, Address: 0x1028828 */
  pTbl = tbl; /* Line 167, Address: 0x102882c */

  while ((poswk = *pTbl++) >= 0) { /* Line 169, Address: 0x1028830 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 170, Address: 0x1028838 */


    ++EnkeiNo; /* Line 173, Address: 0x102885c */
  } /* Line 174, Address: 0x1028860 */


  if (enkeino == EnkeiNo) return; /* Line 177, Address: 0x1028884 */




  enkeino = EnkeiNo; /* Line 182, Address: 0x1028898 */


  TileNo = 592; /* Line 185, Address: 0x10288a4 */
  if (EnkeiNo == 1) { /* Line 186, Address: 0x10288a8 */
    i = 99; /* Line 187, Address: 0x10288b4 */
    BmpNo = 95; /* Line 188, Address: 0x10288b8 */
  } else { /* Line 189, Address: 0x10288bc */
    i = 95; /* Line 190, Address: 0x10288c4 */
    BmpNo = 0; /* Line 191, Address: 0x10288c8 */
  }
  for ( ; i > 0; --i) { /* Line 193, Address: 0x10288cc */
    ChangeTileBmp(TileNo++, BmpNo++); /* Line 194, Address: 0x10288d4 */
  } /* Line 195, Address: 0x10288f4 */

  colorset2((tbl0[EnkeiNo] >> 2) + 4); /* Line 197, Address: 0x1028900 */
  colorset((tbl0[EnkeiNo] >> 2) + 4); /* Line 198, Address: 0x1028920 */

  mapset2((unsigned char*)mapwkb, tbl0[EnkeiNo] / 2); /* Line 200, Address: 0x1028940 */
  scrbinit(scra_h_posit.w.h, scra_v_posit.w.h); /* Line 201, Address: 0x1028978 */
  mapwrt_cnt = 1; /* Line 202, Address: 0x1028990 */
} /* Line 203, Address: 0x102899c */












sprite_status* main_chk() {
  if (main_play == 0) /* Line 217, Address: 0x10289d0 */
    return &actwk[0]; /* Line 218, Address: 0x10289e4 */
  else
    return &actwk[1]; /* Line 220, Address: 0x10289f4 */

} /* Line 222, Address: 0x10289fc */





































void scr_set() { /* Line 260, Address: 0x1028a10 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 263, Address: 0x1028a1c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 264, Address: 0x1028a30 */
  scr_timer.b.h = 0; /* Line 265, Address: 0x1028a44 */

  pScrTbl = scr_dir_tbl; /* Line 267, Address: 0x1028a4c */
  scrar_no = *pScrTbl; /* Line 268, Address: 0x1028a54 */
  ++pScrTbl; /* Line 269, Address: 0x1028a60 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 270, Address: 0x1028a64 */
  ++pScrTbl; /* Line 271, Address: 0x1028a78 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 272, Address: 0x1028a7c */
  ++pScrTbl; /* Line 273, Address: 0x1028a90 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 274, Address: 0x1028a94 */
  ++pScrTbl; /* Line 275, Address: 0x1028aa8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 276, Address: 0x1028aac */
  scra_h_keep = *pScrTbl + 576; /* Line 277, Address: 0x1028ac0 */
  ++pScrTbl; /* Line 278, Address: 0x1028ae0 */
  scra_h_count = 16; /* Line 279, Address: 0x1028ae4 */
  scra_v_count = 16; /* Line 280, Address: 0x1028af0 */

  scra_vline = *pScrTbl; /* Line 282, Address: 0x1028afc */
  scra_hline = 160; /* Line 283, Address: 0x1028b08 */

  playposiset(); /* Line 285, Address: 0x1028b14 */
} /* Line 286, Address: 0x1028b1c */






































static void playposiset() { /* Line 325, Address: 0x1028b30 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 328, Address: 0x1028b44 */
    playload(); /* Line 329, Address: 0x1028b54 */
    xwk = actwk[0].xposi.w.h; /* Line 330, Address: 0x1028b5c */

    if (actwk[0].yposi.w.h > 0) { /* Line 332, Address: 0x1028b6c */
      ywk = actwk[0].yposi.w.h; /* Line 333, Address: 0x1028b84 */
    } else { /* Line 334, Address: 0x1028b94 */
      ywk = 0; /* Line 335, Address: 0x1028b9c */
    }
  } /* Line 337, Address: 0x1028ba0 */
  else {
    pPositbl = playpositbl[0]; /* Line 339, Address: 0x1028ba8 */


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 342, Address: 0x1028bb0 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 343, Address: 0x1028bc4 */
  }


  if (xwk > 160) { /* Line 347, Address: 0x1028bd8 */
    xwk -= 160; /* Line 348, Address: 0x1028bec */
  } else { /* Line 349, Address: 0x1028bf8 */
    xwk = 0; /* Line 350, Address: 0x1028c00 */
  }


  if (xwk > scralim_right) { /* Line 354, Address: 0x1028c04 */
    xwk = scralim_right; /* Line 355, Address: 0x1028c28 */
  }


  scra_h_posit.w.h = xwk; /* Line 359, Address: 0x1028c38 */

  if (ywk > 96) { /* Line 361, Address: 0x1028c40 */
    ywk -= 96; /* Line 362, Address: 0x1028c54 */
  } else { /* Line 363, Address: 0x1028c60 */
    ywk = 0; /* Line 364, Address: 0x1028c68 */
  }


  if (ywk > scralim_down) { /* Line 368, Address: 0x1028c6c */
    ywk = scralim_down; /* Line 369, Address: 0x1028c90 */
  }


  scra_v_posit.w.h = ywk; /* Line 373, Address: 0x1028ca0 */

  scrbinit(xwk, ywk); /* Line 375, Address: 0x1028ca8 */


  loopmapno = playmapnotbl[0]; /* Line 378, Address: 0x1028cb8 */
  loopmapno2 = playmapnotbl[1]; /* Line 379, Address: 0x1028cc8 */
  ballmapno = playmapnotbl[2]; /* Line 380, Address: 0x1028cd8 */
  ballmapno2 = playmapnotbl[3]; /* Line 381, Address: 0x1028ce8 */
} /* Line 382, Address: 0x1028cf8 */




















static void scrbinit(short sXpos, short sYpos) { /* Line 403, Address: 0x1028d20 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 406, Address: 0x1028d2c */
  lYwk.w.l = 0; /* Line 407, Address: 0x1028d34 */

  lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 409, Address: 0x1028d38 */

  scrb_v_posit.l = lYwk.l; /* Line 411, Address: 0x1028d44 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 412, Address: 0x1028d50 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 413, Address: 0x1028d5c */

  sXpos = (unsigned short)sXpos >> 1; /* Line 415, Address: 0x1028d68 */
  scrb_h_posit.w.h = sXpos; /* Line 416, Address: 0x1028d84 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 418, Address: 0x1028d90 */
  scrc_h_posit.w.h = sXpos; /* Line 419, Address: 0x1028dac */

  sXpos >>= 2; /* Line 421, Address: 0x1028db8 */
  scrz_h_posit.w.h = sXpos * 3; /* Line 422, Address: 0x1028dc4 */
} /* Line 423, Address: 0x1028de8 */















void scroll() { /* Line 439, Address: 0x1028e00 */
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

  if (scroll_start.b.h) return; /* Line 451, Address: 0x1028e1c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 456, Address: 0x1028e2c */

  scrchk(); /* Line 458, Address: 0x1028e58 */

  scroll_h(); /* Line 460, Address: 0x1028e60 */
  scroll_v(); /* Line 461, Address: 0x1028e68 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 463, Address: 0x1028e70 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 464, Address: 0x1028e80 */


  lXwk = scra_hz * 16 * 3; /* Line 467, Address: 0x1028e90 */
  scrollz_h(lXwk, 6); /* Line 468, Address: 0x1028eac */

  lXwk = scra_hz * 64; /* Line 470, Address: 0x1028ebc */
  scrollc_h(lXwk, 4); /* Line 471, Address: 0x1028ed0 */

  lXwk = scra_hz * 128; /* Line 473, Address: 0x1028ee0 */
  scrollb_h(lXwk, 2); /* Line 474, Address: 0x1028ef4 */

  lYwk = (unsigned short)scra_v_posit.w.h >> 2; /* Line 476, Address: 0x1028f04 */


  scrollb_v(lYwk); /* Line 479, Address: 0x1028f18 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 481, Address: 0x1028f28 */
  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 482, Address: 0x1028f50 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 483, Address: 0x1028f88 */

  psHscw = hscrollwork; /* Line 485, Address: 0x1028f9c */

  if (enkeino & 1) { /* Line 487, Address: 0x1028fa8 */

    ldwk.w.l = -scrz_h_posit.w.h; /* Line 489, Address: 0x1028fc0 */
    for (i = 0; i < 14; ++i) { /* Line 490, Address: 0x1028fe0 */

      *psHscw++ = ldwk.w.l; /* Line 492, Address: 0x1028fec */
    } /* Line 493, Address: 0x1029000 */
    z51cline(&psHscw); /* Line 494, Address: 0x1029010 */
  } /* Line 495, Address: 0x102901c */
  else {
    ldwk.w.l = -scrb_h_posit.w.h; /* Line 497, Address: 0x1029024 */
    for (i = 0; i < 10; ++i) { /* Line 498, Address: 0x1029044 */

      *psHscw++ = ldwk.w.l; /* Line 500, Address: 0x1029050 */
    } /* Line 501, Address: 0x1029064 */

    ldwk.w.l = -scrz_h_posit.w.h; /* Line 503, Address: 0x1029074 */
    for (i = 0; i < 22; ++i) { /* Line 504, Address: 0x1029094 */

      *psHscw++ = ldwk.w.l; /* Line 506, Address: 0x10290a0 */
    } /* Line 507, Address: 0x10290b4 */

    ldwk.w.l = -scrc_h_posit.w.h; /* Line 509, Address: 0x10290c4 */
    for (i = 0; i < 4; ++i) { /* Line 510, Address: 0x10290e4 */

      *psHscw++ = ldwk.w.l; /* Line 512, Address: 0x10290f0 */
    } /* Line 513, Address: 0x1029104 */

    ldwk.w.l = -scrb_h_posit.w.h; /* Line 515, Address: 0x1029114 */
    for (i = 0; i < 12; ++i) { /* Line 516, Address: 0x1029134 */

      *psHscw++ = ldwk.w.l; /* Line 518, Address: 0x1029140 */
    } /* Line 519, Address: 0x1029154 */
  }


  pHscrbuf = lphscrollbuff; /* Line 523, Address: 0x1029164 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 524, Address: 0x1029170 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 525, Address: 0x10291a0 */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 526, Address: 0x10291d0 */
} /* Line 527, Address: 0x10291ec */













static void z51cline(short** ppHscw) { /* Line 541, Address: 0x1029210 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51cscrtbl[3] = { /* Line 546, Address: 0x1029228 */
    39, 3, 9
  };

  lHwk = scra_h_posit.w.h - scrc_h_posit.w.h; /* Line 550, Address: 0x102924c */
  lHwk = (unsigned int)lHwk * 128 / 12; /* Line 551, Address: 0x1029270 */
  lHwk *= 512; /* Line 552, Address: 0x102928c */

  ldHposwk.l = 0; /* Line 554, Address: 0x1029290 */
  ldHposwk.w.l = scrc_h_posit.w.h; /* Line 555, Address: 0x1029294 */

  for (i = 2; i >= 0; --i) { /* Line 557, Address: 0x10292a0 */

    wk = -ldHposwk.w.l; /* Line 559, Address: 0x10292ac */

    for (j = z51cscrtbl[i]; j >= 0; --j) { /* Line 561, Address: 0x10292cc */

      **ppHscw = wk; /* Line 563, Address: 0x10292e4 */
      ++*ppHscw; /* Line 564, Address: 0x10292f0 */
    } /* Line 565, Address: 0x1029304 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 567, Address: 0x1029310 */
    ldHposwk.l += lHwk; /* Line 568, Address: 0x1029334 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 569, Address: 0x1029340 */
  } /* Line 570, Address: 0x1029364 */
} /* Line 571, Address: 0x1029370 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 592, Address: 0x1029390 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 596, Address: 0x10293ac */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 598, Address: 0x10293b0 */
    ldwk.w.l = *pHscrwk; /* Line 599, Address: 0x10293cc */
    ++pHscrwk; /* Line 600, Address: 0x10293d8 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 602, Address: 0x10293e4 */
      (*pHscrbuf)->l = ldwk.l; /* Line 603, Address: 0x10293ec */
    } /* Line 604, Address: 0x10293fc */
  } /* Line 605, Address: 0x1029420 */
} /* Line 606, Address: 0x1029440 */









































































































static void scrollb_v(short yPos) { /* Line 712, Address: 0x1029460 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 715, Address: 0x1029470 */
  scrb_v_posit.w.h = yPos; /* Line 716, Address: 0x1029480 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 717, Address: 0x102948c */

  if (!ywk) { /* Line 719, Address: 0x10294c4 */
    scrb_v_count ^= 16; /* Line 720, Address: 0x10294cc */
    if (yPos - ysv < 0) { /* Line 721, Address: 0x10294e0 */
      scrflagb.b.h |= 1; /* Line 722, Address: 0x1029500 */
    } /* Line 723, Address: 0x1029514 */
    else {
      scrflagb.b.h |= 2; /* Line 725, Address: 0x102951c */
    }
  }


} /* Line 730, Address: 0x1029530 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 748, Address: 0x1029550 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 752, Address: 0x1029564 */
  lXwk = lXsv + xoffs; /* Line 753, Address: 0x102956c */
  scrb_h_posit.l = lXwk; /* Line 754, Address: 0x1029574 */
  ldXwk.l = lXwk; /* Line 755, Address: 0x102957c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 756, Address: 0x1029580 */
  ldXwk.w.l &= 16; /* Line 757, Address: 0x10295a4 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 758, Address: 0x10295b0 */

  if (!ldXwk.b.b4) { /* Line 760, Address: 0x10295cc */
    scrb_h_count ^= 16; /* Line 761, Address: 0x10295d8 */
    if (lXwk - lXsv < 0) { /* Line 762, Address: 0x10295ec */
      scrflagb.b.h |= 1 << flgbit; /* Line 763, Address: 0x10295f8 */
    } /* Line 764, Address: 0x102961c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 766, Address: 0x1029624 */
    }
  }


} /* Line 771, Address: 0x102964c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 789, Address: 0x1029660 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 793, Address: 0x1029674 */
  lXwk = lXsv + xoffs; /* Line 794, Address: 0x102967c */
  scrc_h_posit.l = lXwk; /* Line 795, Address: 0x1029684 */
  ldXwk.l = lXwk; /* Line 796, Address: 0x102968c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 797, Address: 0x1029690 */
  ldXwk.w.l &= 16; /* Line 798, Address: 0x10296b4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 799, Address: 0x10296c0 */

  if (!ldXwk.b.b4) { /* Line 801, Address: 0x10296dc */
    scrc_h_count ^= 16; /* Line 802, Address: 0x10296e8 */
    if (lXwk - lXsv < 0) { /* Line 803, Address: 0x10296fc */
      scrflagc.b.h |= 1 << flgbit; /* Line 804, Address: 0x1029708 */
    } /* Line 805, Address: 0x102972c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 807, Address: 0x1029734 */
    }
  }


} /* Line 812, Address: 0x102975c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 830, Address: 0x1029770 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 834, Address: 0x1029784 */
  lXwk = lXsv + xoffs; /* Line 835, Address: 0x102978c */
  scrz_h_posit.l = lXwk; /* Line 836, Address: 0x1029794 */
  ldXwk.l = lXwk; /* Line 837, Address: 0x102979c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 838, Address: 0x10297a0 */
  ldXwk.w.l &= 16; /* Line 839, Address: 0x10297c4 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 840, Address: 0x10297d0 */

  if (!ldXwk.b.b4) { /* Line 842, Address: 0x10297ec */
    scrz_h_count ^= 16; /* Line 843, Address: 0x10297f8 */
    if (lXwk - lXsv < 0) { /* Line 844, Address: 0x102980c */
      scrflagz.b.h |= 1 << flgbit; /* Line 845, Address: 0x1029818 */
    } /* Line 846, Address: 0x102983c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 848, Address: 0x1029844 */
    }
  }


} /* Line 853, Address: 0x102986c */














static void scroll_h() { /* Line 868, Address: 0x1029880 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 872, Address: 0x1029890 */

  scrh_move(); /* Line 874, Address: 0x10298a0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 875, Address: 0x10298a8 */
  if (!bXwk) { /* Line 876, Address: 0x10298dc */
    scra_h_count ^= 16; /* Line 877, Address: 0x10298e4 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 878, Address: 0x10298f8 */
      scrflaga.b.h |= 4; /* Line 879, Address: 0x102991c */
    } else { /* Line 880, Address: 0x1029930 */
      scrflaga.b.h |= 8; /* Line 881, Address: 0x1029938 */
    }
  }


} /* Line 886, Address: 0x102994c */
















static void scrh_move() { /* Line 903, Address: 0x1029970 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 906, Address: 0x1029978 */
  if (xwk == 0) { /* Line 907, Address: 0x10299c0 */

    scra_hz = 0; /* Line 909, Address: 0x10299d0 */
    return; /* Line 910, Address: 0x10299d8 */
  } else if (xwk < 0) { /* Line 911, Address: 0x10299e0 */

    if (xwk < -16) { /* Line 913, Address: 0x10299f0 */
      xwk = -16; /* Line 914, Address: 0x1029a04 */
    }


    xwk += scra_h_posit.w.h; /* Line 918, Address: 0x1029a10 */
    if (xwk < scralim_left) { /* Line 919, Address: 0x1029a24 */
      xwk = scralim_left; /* Line 920, Address: 0x1029a48 */
    }
  } /* Line 922, Address: 0x1029a58 */
  else {
    if (xwk > 16) { /* Line 924, Address: 0x1029a60 */
      xwk = 16; /* Line 925, Address: 0x1029a74 */
    }


    xwk += scra_h_posit.w.h; /* Line 929, Address: 0x1029a80 */
    if (xwk > scralim_right) { /* Line 930, Address: 0x1029a94 */
      xwk = scralim_right; /* Line 931, Address: 0x1029ab8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 936, Address: 0x1029ac8 */
  scra_h_posit.w.h = xwk; /* Line 937, Address: 0x1029af8 */
} /* Line 938, Address: 0x1029b00 */














static void scroll_v() { /* Line 953, Address: 0x1029b10 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 956, Address: 0x1029b1c */
  if (actwk[0].cddat & 4) { /* Line 957, Address: 0x1029b50 */
    ywk -= 5; /* Line 958, Address: 0x1029b68 */
  }


  if (actwk[0].cddat & 2) { /* Line 962, Address: 0x1029b74 */
    ywk += 32; /* Line 963, Address: 0x1029b8c */
    if (ywk < scra_vline) { /* Line 964, Address: 0x1029b98 */
      ywk -= scra_vline; /* Line 965, Address: 0x1029bbc */
      sv_move_main2(ywk); /* Line 966, Address: 0x1029bd0 */
      return; /* Line 967, Address: 0x1029bdc */
    } else if (ywk >= scra_vline + 64) { /* Line 968, Address: 0x1029be4 */
      ywk -= scra_vline + 64; /* Line 969, Address: 0x1029c0c */
      sv_move_main2(ywk); /* Line 970, Address: 0x1029c34 */
      return; /* Line 971, Address: 0x1029c40 */
    }
    ywk -= scra_vline + 64; /* Line 973, Address: 0x1029c48 */
    if (!limmoveflag) goto label1; /* Line 974, Address: 0x1029c70 */
    sv_move_sub2(); /* Line 975, Address: 0x1029c80 */
    return; /* Line 976, Address: 0x1029c88 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 981, Address: 0x1029c90 */
    sv_move_main(ywk); /* Line 982, Address: 0x1029cbc */
    return; /* Line 983, Address: 0x1029cc8 */
  } else if (!limmoveflag) goto label1; /* Line 984, Address: 0x1029cd0 */
  sv_move_sub2(); /* Line 985, Address: 0x1029ce0 */
  return; /* Line 986, Address: 0x1029ce8 */



label1:
  scra_vz = 0; /* Line 991, Address: 0x1029cf0 */
} /* Line 992, Address: 0x1029cf8 */













static void sv_move_main(short yPos) { /* Line 1006, Address: 0x1029d10 */
  short spdwk;

  if (scra_vline == 96) { /* Line 1009, Address: 0x1029d20 */
    if (actwk[0].mspeed.w < 0) { /* Line 1010, Address: 0x1029d3c */
      spdwk = -actwk[0].mspeed.w; /* Line 1011, Address: 0x1029d54 */
    } else { /* Line 1012, Address: 0x1029d78 */
      spdwk = actwk[0].mspeed.w; /* Line 1013, Address: 0x1029d80 */
    }


    if (spdwk >= 2048) { /* Line 1017, Address: 0x1029d90 */
      sv_move_main2(yPos); /* Line 1018, Address: 0x1029da4 */
    } /* Line 1019, Address: 0x1029db0 */
    else {

      if (yPos > 6) { /* Line 1022, Address: 0x1029db8 */
        sv_move_plus(1536); /* Line 1023, Address: 0x1029dd0 */
      } else if (yPos < -6) { /* Line 1024, Address: 0x1029ddc */
        sv_move_minus(1536); /* Line 1025, Address: 0x1029dfc */
      } /* Line 1026, Address: 0x1029e08 */
      else sv_move_sub(yPos); /* Line 1027, Address: 0x1029e10 */
    }
  } /* Line 1029, Address: 0x1029e1c */
  else {
    if (yPos > 2) { /* Line 1031, Address: 0x1029e24 */
      sv_move_plus(512); /* Line 1032, Address: 0x1029e3c */
    } else if (yPos < -2) { /* Line 1033, Address: 0x1029e48 */
      sv_move_minus(512); /* Line 1034, Address: 0x1029e68 */
    } /* Line 1035, Address: 0x1029e74 */
    else sv_move_sub(yPos); /* Line 1036, Address: 0x1029e7c */
  }

} /* Line 1039, Address: 0x1029e88 */













static void sv_move_main2(short yPos) { /* Line 1053, Address: 0x1029ea0 */
  short spdwk;

  spdwk = 4096; /* Line 1056, Address: 0x1029eb0 */

  if (yPos > 16) { /* Line 1058, Address: 0x1029ebc */
    sv_move_plus(spdwk); /* Line 1059, Address: 0x1029ed4 */
  } else if (yPos < -16) { /* Line 1060, Address: 0x1029ee0 */
    sv_move_minus(spdwk); /* Line 1061, Address: 0x1029f00 */
  } else { /* Line 1062, Address: 0x1029f0c */
    sv_move_sub(yPos); /* Line 1063, Address: 0x1029f14 */
  }
} /* Line 1065, Address: 0x1029f20 */














static void sv_move_sub(short yPos) { /* Line 1080, Address: 0x1029f40 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1083, Address: 0x1029f4c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1084, Address: 0x1029f50 */
  if (yPos < 0) { /* Line 1085, Address: 0x1029f7c */
    scrv_up_ch(lSpd); /* Line 1086, Address: 0x1029f90 */
  } else { /* Line 1087, Address: 0x1029f9c */
    scrv_down_ch(lSpd); /* Line 1088, Address: 0x1029fa4 */
  }
} /* Line 1090, Address: 0x1029fb0 */



static void sv_move_sub2() { /* Line 1094, Address: 0x1029fc0 */
  limmoveflag = 0; /* Line 1095, Address: 0x1029fc8 */

  sv_move_sub(0); /* Line 1097, Address: 0x1029fd0 */
} /* Line 1098, Address: 0x1029fdc */













static void sv_move_minus(short speed) { /* Line 1112, Address: 0x1029ff0 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1115, Address: 0x1029ffc */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1116, Address: 0x102a020 */
  scrv_up_ch(lSpd); /* Line 1117, Address: 0x102a044 */
} /* Line 1118, Address: 0x102a050 */














static void scrv_up_ch(int_union lSpd) { /* Line 1133, Address: 0x102a060 */
  if (lSpd.w.l <= scralim_up) { /* Line 1134, Address: 0x102a06c */
    if (lSpd.w.l > -256) { /* Line 1135, Address: 0x102a094 */

      lSpd.w.l = scralim_up; /* Line 1137, Address: 0x102a0ac */
    } else { /* Line 1138, Address: 0x102a0b8 */
      lSpd.w.l &= 2047; /* Line 1139, Address: 0x102a0c0 */
      actwk[0].yposi.w.l &= 2047; /* Line 1140, Address: 0x102a0cc */
      scra_v_posit.w.h &= 2047; /* Line 1141, Address: 0x102a0e0 */
      scrb_v_posit.w.h &= 1023; /* Line 1142, Address: 0x102a0f4 */
    }
  }

  scrv_move(lSpd); /* Line 1146, Address: 0x102a108 */
} /* Line 1147, Address: 0x102a114 */













static void sv_move_plus(short sSpd) { /* Line 1161, Address: 0x102a130 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1164, Address: 0x102a13c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1165, Address: 0x102a15c */
  scrv_down_ch(lSpd); /* Line 1166, Address: 0x102a180 */
} /* Line 1167, Address: 0x102a18c */














static void scrv_down_ch(int_union lSpd) { /* Line 1182, Address: 0x102a1a0 */
  if (lSpd.w.l >= scralim_down) { /* Line 1183, Address: 0x102a1ac */
    if (lSpd.w.l < 2048) { /* Line 1184, Address: 0x102a1d4 */

      lSpd.w.l = scralim_down; /* Line 1186, Address: 0x102a1ec */
    } else { /* Line 1187, Address: 0x102a1f8 */
      lSpd.w.l -= 2048; /* Line 1188, Address: 0x102a200 */
      actwk[0].yposi.w.l &= 2047; /* Line 1189, Address: 0x102a20c */
      scra_v_posit.w.h -= 2048; /* Line 1190, Address: 0x102a220 */
      scrb_v_posit.w.h &= 1023; /* Line 1191, Address: 0x102a234 */
    }
  }

  scrv_move(lSpd); /* Line 1195, Address: 0x102a248 */
} /* Line 1196, Address: 0x102a254 */
















static void scrv_move(int_union lSpd) { /* Line 1213, Address: 0x102a270 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1217, Address: 0x102a280 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1218, Address: 0x102a290 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1219, Address: 0x102a2b4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1220, Address: 0x102a2c8 */
  scra_vz = spdwk.w.l; /* Line 1221, Address: 0x102a2e0 */

  scra_v_posit.l = lSpd.l; /* Line 1223, Address: 0x102a2ec */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1225, Address: 0x102a2f8 */
  if (!ywk) { /* Line 1226, Address: 0x102a334 */
    scra_v_count ^= 16; /* Line 1227, Address: 0x102a33c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1228, Address: 0x102a350 */
    if (ywk < 0) { /* Line 1229, Address: 0x102a37c */
      scrflaga.b.h |= 1; /* Line 1230, Address: 0x102a38c */
    } else { /* Line 1231, Address: 0x102a3a0 */
      scrflaga.b.h |= 2; /* Line 1232, Address: 0x102a3a8 */
    }
  }


} /* Line 1237, Address: 0x102a3bc */

















void scrollwrt() { /* Line 1255, Address: 0x102a3d0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1264, Address: 0x102a3f0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1265, Address: 0x102a3f4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1266, Address: 0x102a400 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1267, Address: 0x102a40c */
  pScrFlag = &scrflagbw.b.h; /* Line 1268, Address: 0x102a414 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1269, Address: 0x102a41c */

  VramBase = 16384; /* Line 1271, Address: 0x102a430 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1272, Address: 0x102a434 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1273, Address: 0x102a440 */
  pMapWk = (unsigned char*)mapwka; /* Line 1274, Address: 0x102a44c */
  pScrFlag = &scrflagaw.b.h; /* Line 1275, Address: 0x102a454 */

  if (*pScrFlag) { /* Line 1277, Address: 0x102a45c */
    if (*pScrFlag & 1) { /* Line 1278, Address: 0x102a468 */
      *pScrFlag &= 254; /* Line 1279, Address: 0x102a47c */

      lD4.l = -16; /* Line 1281, Address: 0x102a488 */
      wD5 = 65520; /* Line 1282, Address: 0x102a490 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1284, Address: 0x102a498 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1286, Address: 0x102a4b8 */
    }




    if (*pScrFlag & 2) { /* Line 1292, Address: 0x102a4e4 */
      *pScrFlag &= 253; /* Line 1293, Address: 0x102a4f8 */

      lD4.l = 224; /* Line 1295, Address: 0x102a504 */
      wD5 = 65520; /* Line 1296, Address: 0x102a50c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1297, Address: 0x102a514 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1299, Address: 0x102a534 */
    }




    if (*pScrFlag & 4) { /* Line 1305, Address: 0x102a560 */
      *pScrFlag &= 251; /* Line 1306, Address: 0x102a574 */

      lD4.l = -16; /* Line 1308, Address: 0x102a580 */
      wD5 = 65520; /* Line 1309, Address: 0x102a588 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1310, Address: 0x102a590 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1312, Address: 0x102a5b0 */
    }




    if (*pScrFlag & 8) { /* Line 1318, Address: 0x102a5dc */
      *pScrFlag &= 247; /* Line 1319, Address: 0x102a5f0 */

      lD4.l = -16; /* Line 1321, Address: 0x102a5fc */
      wD5 = 320; /* Line 1322, Address: 0x102a604 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1323, Address: 0x102a60c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1325, Address: 0x102a62c */
    }
  }






} /* Line 1334, Address: 0x102a658 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1351, Address: 0x102a680 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1362, Address: 0x102a6ac */

  if (*pScrFlag & 1) { /* Line 1364, Address: 0x102a6b4 */
    *pScrFlag &= 254; /* Line 1365, Address: 0x102a6cc */
  } /* Line 1366, Address: 0x102a6e0 */
  else {
    *pScrFlag &= 254; /* Line 1368, Address: 0x102a6e8 */

    if (*pScrFlag & 2) { /* Line 1370, Address: 0x102a6fc */
      *pScrFlag &= 253; /* Line 1371, Address: 0x102a714 */
      lD4.w.l = 224; /* Line 1372, Address: 0x102a728 */
    } /* Line 1373, Address: 0x102a730 */
    else {
      *pScrFlag &= 253; /* Line 1375, Address: 0x102a738 */
      goto label1; /* Line 1376, Address: 0x102a74c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1381, Address: 0x102a754 */
  wD0 &= 127; /* Line 1382, Address: 0x102a7a4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1383, Address: 0x102a7ac */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1389, Address: 0x102a7cc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1390, Address: 0x102a7ec */
  if (wD0 != 0) { /* Line 1391, Address: 0x102a810 */
    wD5 = 65520; /* Line 1392, Address: 0x102a81c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1393, Address: 0x102a824 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1395, Address: 0x102a844 */



  } /* Line 1399, Address: 0x102a870 */
  else {

    wD5 = 0; /* Line 1402, Address: 0x102a878 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1403, Address: 0x102a87c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1407, Address: 0x102a89c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1414, Address: 0x102a8c8 */






    lD4.l = -16; /* Line 1421, Address: 0x102a8dc */
    wD5 = 65520; /* Line 1422, Address: 0x102a8e4 */
    if (*pScrFlag & 168) { /* Line 1423, Address: 0x102a8ec */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1424, Address: 0x102a904 */
      wD5 = 320; /* Line 1425, Address: 0x102a924 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1429, Address: 0x102a92c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1431, Address: 0x102a95c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1432, Address: 0x102a968 */



    for (i = 0; i < 16; ++i) { /* Line 1436, Address: 0x102a978 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1437, Address: 0x102a984 */

      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1439, Address: 0x102a9a4 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1440, Address: 0x102a9dc */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1441, Address: 0x102a9fc */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1443, Address: 0x102aa20 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1446, Address: 0x102aa44 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1448, Address: 0x102aa64 */
      }
      lD4.w.l += 16; /* Line 1450, Address: 0x102aa78 */
    } /* Line 1451, Address: 0x102aa84 */
    *pScrFlag = 0; /* Line 1452, Address: 0x102aa94 */
  }
} /* Line 1454, Address: 0x102aa9c */





void scrollwrtc() {} /* Line 1460, Address: 0x102aad0 */




void scrollwrtz() {} /* Line 1465, Address: 0x102aae0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1483, Address: 0x102aaf0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1496, Address: 0x102ab18 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1499, Address: 0x102ab38 */
    pTilePoint->x += 2; /* Line 1500, Address: 0x102ab4c */
    if (pTilePoint->x >= 64) { /* Line 1501, Address: 0x102ab60 */
      pTilePoint->x -= 64; /* Line 1502, Address: 0x102ab74 */
    }
    xOffs += 16; /* Line 1504, Address: 0x102ab88 */
  } while (--lpcnt >= 0); /* Line 1505, Address: 0x102ab94 */
} /* Line 1506, Address: 0x102aba8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1510, Address: 0x102abc0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1514, Address: 0x102abe8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1517, Address: 0x102ac08 */
    pTilePoint->x += 2; /* Line 1518, Address: 0x102ac1c */
    if (pTilePoint->x >= 64) { /* Line 1519, Address: 0x102ac30 */
      pTilePoint->x -= 64; /* Line 1520, Address: 0x102ac44 */
    }
    xOffs += 16; /* Line 1522, Address: 0x102ac58 */
  } while (--lpcnt >= 0); /* Line 1523, Address: 0x102ac64 */
} /* Line 1524, Address: 0x102ac78 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1544, Address: 0x102ac90 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1548, Address: 0x102acb8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1551, Address: 0x102acd8 */
    pTilePoint->y += 2; /* Line 1552, Address: 0x102acec */
    if (pTilePoint->y >= 32) { /* Line 1553, Address: 0x102acfc */
      pTilePoint->y -= 32; /* Line 1554, Address: 0x102ad10 */
    }
    yOffs += 16; /* Line 1556, Address: 0x102ad20 */
  } while (--lpcnt >= 0); /* Line 1557, Address: 0x102ad2c */
} /* Line 1558, Address: 0x102ad40 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1577, Address: 0x102ad50 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1583, Address: 0x102ad84 */

    base = 1; /* Line 1585, Address: 0x102ad94 */
  } /* Line 1586, Address: 0x102ad98 */
  else if (VramBase == 16384) { /* Line 1587, Address: 0x102ada0 */

    base = 0; /* Line 1589, Address: 0x102adb0 */
  }
  x = pTilePoint->x; /* Line 1591, Address: 0x102adb4 */
  y = pTilePoint->y; /* Line 1592, Address: 0x102adbc */


  frip = BlkIndex & 6144; /* Line 1595, Address: 0x102adc4 */
  BlkIndex &= 1023; /* Line 1596, Address: 0x102adcc */
  if (frip == 6144) { /* Line 1597, Address: 0x102add8 */

    p0 = 3, p1 = 2; /* Line 1599, Address: 0x102ade4 */
    p2 = 1, p3 = 0; /* Line 1600, Address: 0x102adec */
  } /* Line 1601, Address: 0x102adf4 */
  else if (frip & 4096) { /* Line 1602, Address: 0x102adfc */

    p0 = 2, p1 = 3; /* Line 1604, Address: 0x102ae08 */
    p2 = 0, p3 = 1; /* Line 1605, Address: 0x102ae10 */
  } /* Line 1606, Address: 0x102ae18 */
  else if (frip & 2048) { /* Line 1607, Address: 0x102ae20 */

    p0 = 1, p1 = 0; /* Line 1609, Address: 0x102ae2c */
    p2 = 3, p3 = 2; /* Line 1610, Address: 0x102ae34 */
  } /* Line 1611, Address: 0x102ae3c */
  else {

    p0 = 0, p1 = 1; /* Line 1614, Address: 0x102ae44 */
    p2 = 2, p3 = 3; /* Line 1615, Address: 0x102ae4c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1618, Address: 0x102ae54 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1619, Address: 0x102ae98 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1620, Address: 0x102aedc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1621, Address: 0x102af20 */

} /* Line 1623, Address: 0x102af64 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1641, Address: 0x102afa0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1642, Address: 0x102afc0 */
} /* Line 1643, Address: 0x102afe0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1645, Address: 0x102aff0 */
  wH_posiw = 0; /* Line 1646, Address: 0x102b010 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1647, Address: 0x102b014 */
} /* Line 1648, Address: 0x102b034 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1655, Address: 0x102b050 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1661, Address: 0x102b080 */
  yOffs += wV_posiw; /* Line 1662, Address: 0x102b090 */





  if ((short)xOffs < 0) /* Line 1668, Address: 0x102b0a0 */
    xOffs = 0; /* Line 1669, Address: 0x102b0bc */
  if ((short)yOffs < 0) /* Line 1670, Address: 0x102b0c0 */
    yOffs = 0; /* Line 1671, Address: 0x102b0dc */
  if ((short)xOffs >= 16384) /* Line 1672, Address: 0x102b0e0 */
    xOffs = 16383; /* Line 1673, Address: 0x102b100 */
  if ((short)yOffs >= 2048) /* Line 1674, Address: 0x102b108 */
    yOffs = 2047; /* Line 1675, Address: 0x102b128 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1676, Address: 0x102b130 */
  if (i < 0) i = 0; /* Line 1677, Address: 0x102b178 */

  ScreenNo = pMapWk[i] & 127; /* Line 1679, Address: 0x102b184 */

  if (ScreenNo) { /* Line 1681, Address: 0x102b1a0 */




    xOffs &= 32767; /* Line 1686, Address: 0x102b1a8 */
    yOffs &= 32767; /* Line 1687, Address: 0x102b1b4 */


    xBlk = xOffs; /* Line 1690, Address: 0x102b1c0 */
    xBlk %= 256; /* Line 1691, Address: 0x102b1c8 */
    xBlk /= 16; /* Line 1692, Address: 0x102b1e8 */
    yBlk = yOffs; /* Line 1693, Address: 0x102b204 */
    yBlk %= 256; /* Line 1694, Address: 0x102b20c */
    yBlk /= 16; /* Line 1695, Address: 0x102b22c */

    lpw = pmapwk; /* Line 1697, Address: 0x102b248 */
    lpw += xBlk; /* Line 1698, Address: 0x102b250 */
    lpw += yBlk * 16; /* Line 1699, Address: 0x102b258 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1700, Address: 0x102b264 */
    *pIndex = *lpw; /* Line 1701, Address: 0x102b27c */

    return 1; /* Line 1703, Address: 0x102b28c */
  }

  *pIndex = 0; /* Line 1706, Address: 0x102b298 */
  return 0; /* Line 1707, Address: 0x102b2a0 */
} /* Line 1708, Address: 0x102b2a4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1728, Address: 0x102b2d0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1736, Address: 0x102b2f8 */
  if (ScreenNo) { /* Line 1737, Address: 0x102b35c */





    xBlk = xOffs; /* Line 1743, Address: 0x102b364 */
    xBlk %= 256; /* Line 1744, Address: 0x102b36c */
    xBlk /= 16; /* Line 1745, Address: 0x102b38c */
    yBlk = yOffs; /* Line 1746, Address: 0x102b3a8 */
    yBlk %= 256; /* Line 1747, Address: 0x102b3b0 */
    yBlk /= 16; /* Line 1748, Address: 0x102b3d0 */


    lpw = pmapwk; /* Line 1751, Address: 0x102b3ec */
    lpw += xBlk; /* Line 1752, Address: 0x102b3f4 */
    lpw += yBlk * 16; /* Line 1753, Address: 0x102b3fc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1754, Address: 0x102b408 */
    *ppBlockNo = lpw; /* Line 1755, Address: 0x102b420 */
    *pIndex = *lpw; /* Line 1756, Address: 0x102b428 */




    return 1; /* Line 1761, Address: 0x102b438 */
  }

  *pIndex = 0; /* Line 1764, Address: 0x102b444 */
  return 0; /* Line 1765, Address: 0x102b44c */
} /* Line 1766, Address: 0x102b450 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1780, Address: 0x102b470 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1787, Address: 0x102b48c */
  pMapWk = (unsigned char*)mapwka; /* Line 1788, Address: 0x102b490 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1789, Address: 0x102b498 */
    *pBlockIndex = BlockNo; /* Line 1790, Address: 0x102b4bc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1791, Address: 0x102b4c8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1792, Address: 0x102b4e0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1793, Address: 0x102b4f4 */
    }
  }


} /* Line 1798, Address: 0x102b50c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1812, Address: 0x102b530 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1813, Address: 0x102b53c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1814, Address: 0x102b568 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1815, Address: 0x102b5b4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1816, Address: 0x102b5e0 */

          return 0; /* Line 1818, Address: 0x102b62c */
        }
      }
    }
  }

  return 1; /* Line 1824, Address: 0x102b638 */
} /* Line 1825, Address: 0x102b63c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1842, Address: 0x102b650 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1843, Address: 0x102b66c */

} /* Line 1845, Address: 0x102b688 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1847, Address: 0x102b6a0 */
  wH_posiw = 0; /* Line 1848, Address: 0x102b6bc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1849, Address: 0x102b6c0 */

} /* Line 1851, Address: 0x102b6dc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1853, Address: 0x102b6f0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1854, Address: 0x102b704 */

} /* Line 1856, Address: 0x102b720 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1858, Address: 0x102b730 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1859, Address: 0x102b74c */

} /* Line 1861, Address: 0x102b768 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1863, Address: 0x102b780 */
  xOffs += wH_posiw; /* Line 1864, Address: 0x102b798 */
  yOffs += wV_posiw; /* Line 1865, Address: 0x102b7a8 */
  yOffs &= 240; /* Line 1866, Address: 0x102b7b8 */
  xOffs &= 496; /* Line 1867, Address: 0x102b7c4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1869, Address: 0x102b7d0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1870, Address: 0x102b7fc */


} /* Line 1873, Address: 0x102b828 */















void mapwrt() { /* Line 1889, Address: 0x102b840 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1894, Address: 0x102b858 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1895, Address: 0x102b864 */
  pMapWk = (unsigned char*)mapwka; /* Line 1896, Address: 0x102b870 */
  VramBase = 16384; /* Line 1897, Address: 0x102b878 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1898, Address: 0x102b87c */
  mapwrtb(); /* Line 1899, Address: 0x102b894 */
} /* Line 1900, Address: 0x102b89c */


void mapwrtb() { /* Line 1903, Address: 0x102b8c0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scrb_h_posiw.w.h; /* Line 1908, Address: 0x102b8d8 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1909, Address: 0x102b8e4 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1910, Address: 0x102b8f0 */
  VramBase = 24576; /* Line 1911, Address: 0x102b8f8 */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1912, Address: 0x102b8fc */

} /* Line 1914, Address: 0x102b90c */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1917, Address: 0x102b930 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1918, Address: 0x102b948 */
} /* Line 1919, Address: 0x102b968 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1924, Address: 0x102b980 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1928, Address: 0x102b9a0 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1931, Address: 0x102b9bc */



    wD4 += 16; /* Line 1935, Address: 0x102b9e4 */
  } while ((short)--wD6 >= 0); /* Line 1936, Address: 0x102b9f0 */

} /* Line 1938, Address: 0x102ba18 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1944, Address: 0x102ba30 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1947, Address: 0x102ba4c */
  wD6 = 15; /* Line 1948, Address: 0x102ba54 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 1008; /* Line 1951, Address: 0x102ba5c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1953, Address: 0x102ba80 */
    wD4 += 16; /* Line 1954, Address: 0x102baa0 */
  } while ((short)--wD6 >= 0); /* Line 1955, Address: 0x102baa8 */
} /* Line 1956, Address: 0x102bacc */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1982, Address: 0x102baf0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1987, Address: 0x102bb18 */
  wD0 = pWrttbl[wD0]; /* Line 1988, Address: 0x102bb28 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1990, Address: 0x102bb44 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1991, Address: 0x102bb68 */
  if (wD0) { /* Line 1992, Address: 0x102bb90 */
    wD5 = 65520; /* Line 1993, Address: 0x102bb9c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1994, Address: 0x102bba4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1997, Address: 0x102bbc0 */



  } /* Line 2001, Address: 0x102bbe8 */
  else {

    wD5 = 0; /* Line 2004, Address: 0x102bbf0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2005, Address: 0x102bbf4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2009, Address: 0x102bc10 */
  }





} /* Line 2016, Address: 0x102bc38 */










void mapinit() { /* Line 2027, Address: 0x102bc60 */
  short tbl[9] = { /* Line 2028, Address: 0x102bc80 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 2033, Address: 0x102bcac */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  EnkeiNo = 0; /* Line 2039, Address: 0x102bcd0 */
  pTbl = tbl; /* Line 2040, Address: 0x102bcd4 */

  while ((poswk = *pTbl++) >= 0) { /* Line 2042, Address: 0x102bcd8 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 2043, Address: 0x102bce0 */


    ++EnkeiNo; /* Line 2046, Address: 0x102bd04 */
  } /* Line 2047, Address: 0x102bd08 */


  TileNo = 592; /* Line 2050, Address: 0x102bd2c */
  if (EnkeiNo == 0) { /* Line 2051, Address: 0x102bd30 */
    i = 95; /* Line 2052, Address: 0x102bd38 */
    BmpNo = 0; /* Line 2053, Address: 0x102bd3c */

    for ( ; i > 0; --i) { /* Line 2055, Address: 0x102bd40 */
      ChangeTileBmp(TileNo++, BmpNo++); /* Line 2056, Address: 0x102bd48 */
    } /* Line 2057, Address: 0x102bd68 */
  }


  colorset2(mapinittbl.colorno2); /* Line 2061, Address: 0x102bd74 */
  colorset(mapinittbl.colorno2); /* Line 2062, Address: 0x102bd88 */


  if (play_start & 2) divdevset(); /* Line 2065, Address: 0x102bd9c */
} /* Line 2066, Address: 0x102bdbc */




void mapset() {} /* Line 2071, Address: 0x102bdf0 */



void divdevset() {} /* Line 2075, Address: 0x102be00 */



void enecginit() {} /* Line 2079, Address: 0x102be10 */















static void mapset2(unsigned char* pMapDst, int idx) { /* Line 2095, Address: 0x102be20 */
  int h, v, hwk;
  unsigned char *pZonetbl, *pMapwk;

  pZonetbl = zonemaptbl[idx]; /* Line 2099, Address: 0x102be40 */
  h = *pZonetbl++; /* Line 2100, Address: 0x102be58 */
  v = *pZonetbl++; /* Line 2101, Address: 0x102be68 */
  for ( ;v >= 0; --v) { /* Line 2102, Address: 0x102be78 */
    pMapwk = pMapDst; /* Line 2103, Address: 0x102be80 */

    for (hwk = h; hwk >= 0; --hwk) { /* Line 2105, Address: 0x102be84 */
      *pMapwk++ = *pZonetbl++; /* Line 2106, Address: 0x102be90 */
    } /* Line 2107, Address: 0x102bea8 */

    pMapDst += 64; /* Line 2109, Address: 0x102beb4 */
  } /* Line 2110, Address: 0x102bec0 */
} /* Line 2111, Address: 0x102becc */
