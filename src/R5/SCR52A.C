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
  0, 0, 0, 0, 0, 6, 6, 6, 6, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0
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
short scr_dir_tbl[6] = { 4, 0, 10903, 0, 800, 96 };
short playpositbl[1][2] = { { 64, 364 } };
unsigned char playmapnotbl[4] = { 127, 127, 21, 91 };
extern unsigned char mapwka[8][64];
extern int(*SetGrid)(int, int, int, int, int);
extern map_init_data mapinittbl;
extern unsigned char* zonemaptbl[];





































































































void enkeichg() { /* Line 172, Address: 0x1028830 */
  short tbl[6] = { /* Line 173, Address: 0x1028850 */
    3584, 7168, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 177, Address: 0x1028884 */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  if (scrflaga.b.h) return; /* Line 183, Address: 0x10288a8 */



  EnkeiNo = 0; /* Line 187, Address: 0x10288b8 */
  pTbl = tbl; /* Line 188, Address: 0x10288bc */

  while ((poswk = *pTbl++) >= 0) { /* Line 190, Address: 0x10288c0 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 191, Address: 0x10288c8 */


    ++EnkeiNo; /* Line 194, Address: 0x10288ec */
  } /* Line 195, Address: 0x10288f0 */


  if (enkeino == EnkeiNo) return; /* Line 198, Address: 0x1028914 */




  enkeino = EnkeiNo; /* Line 203, Address: 0x1028928 */


  TileNo = 603; /* Line 206, Address: 0x1028934 */
  if (EnkeiNo == 1) { /* Line 207, Address: 0x1028938 */
    i = 84; /* Line 208, Address: 0x1028944 */
    BmpNo = 114; /* Line 209, Address: 0x1028948 */
  } else { /* Line 210, Address: 0x102894c */
    i = 113; /* Line 211, Address: 0x1028954 */
    BmpNo = 0; /* Line 212, Address: 0x1028958 */
  }
  for ( ; i > 0; --i) { /* Line 214, Address: 0x102895c */
    ChangeTileBmp(TileNo++, BmpNo++); /* Line 215, Address: 0x1028964 */
  } /* Line 216, Address: 0x1028984 */

  colorset2((tbl0[EnkeiNo] >> 2) + 4); /* Line 218, Address: 0x1028990 */
  colorset((tbl0[EnkeiNo] >> 2) + 4); /* Line 219, Address: 0x10289b0 */

  mapset2((unsigned char*)mapwkb, tbl0[EnkeiNo] / 2); /* Line 221, Address: 0x10289d0 */
  scrbinit(scra_h_posit.w.h, scra_v_posit.w.h); /* Line 222, Address: 0x1028a08 */
  mapwrt_cnt = 1; /* Line 223, Address: 0x1028a20 */
} /* Line 224, Address: 0x1028a2c */












sprite_status* main_chk() {
  if (main_play == 0) /* Line 238, Address: 0x1028a60 */
    return &actwk[0]; /* Line 239, Address: 0x1028a74 */
  else
    return &actwk[1]; /* Line 241, Address: 0x1028a84 */

} /* Line 243, Address: 0x1028a8c */





































void scr_set() { /* Line 281, Address: 0x1028aa0 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 284, Address: 0x1028aac */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 285, Address: 0x1028ac0 */
  scr_timer.b.h = 0; /* Line 286, Address: 0x1028ad4 */

  pScrTbl = scr_dir_tbl; /* Line 288, Address: 0x1028adc */
  scrar_no = *pScrTbl; /* Line 289, Address: 0x1028ae4 */
  ++pScrTbl; /* Line 290, Address: 0x1028af0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 291, Address: 0x1028af4 */
  ++pScrTbl; /* Line 292, Address: 0x1028b08 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 293, Address: 0x1028b0c */
  ++pScrTbl; /* Line 294, Address: 0x1028b20 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 295, Address: 0x1028b24 */
  ++pScrTbl; /* Line 296, Address: 0x1028b38 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 297, Address: 0x1028b3c */
  scra_h_keep = *pScrTbl + 576; /* Line 298, Address: 0x1028b50 */
  ++pScrTbl; /* Line 299, Address: 0x1028b70 */
  scra_h_count = 16; /* Line 300, Address: 0x1028b74 */
  scra_v_count = 16; /* Line 301, Address: 0x1028b80 */

  scra_vline = *pScrTbl; /* Line 303, Address: 0x1028b8c */
  scra_hline = 160; /* Line 304, Address: 0x1028b98 */

  playposiset(); /* Line 306, Address: 0x1028ba4 */
} /* Line 307, Address: 0x1028bac */





































static void playposiset() { /* Line 345, Address: 0x1028bc0 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 348, Address: 0x1028bd4 */
    playload(); /* Line 349, Address: 0x1028be4 */
    xwk = actwk[0].xposi.w.h; /* Line 350, Address: 0x1028bec */

    if (actwk[0].yposi.w.h > 0) { /* Line 352, Address: 0x1028bfc */
      ywk = actwk[0].yposi.w.h; /* Line 353, Address: 0x1028c14 */
    } else { /* Line 354, Address: 0x1028c24 */
      ywk = 0; /* Line 355, Address: 0x1028c2c */
    }
  } /* Line 357, Address: 0x1028c30 */
  else {
    pPositbl = playpositbl[0]; /* Line 359, Address: 0x1028c38 */


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 362, Address: 0x1028c40 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 363, Address: 0x1028c54 */
  }


  if (xwk > 160) { /* Line 367, Address: 0x1028c68 */
    xwk -= 160; /* Line 368, Address: 0x1028c7c */
  } else { /* Line 369, Address: 0x1028c88 */
    xwk = 0; /* Line 370, Address: 0x1028c90 */
  }


  if (xwk > scralim_right) { /* Line 374, Address: 0x1028c94 */
    xwk = scralim_right; /* Line 375, Address: 0x1028cb8 */
  }


  scra_h_posit.w.h = xwk; /* Line 379, Address: 0x1028cc8 */

  if (ywk > 96) { /* Line 381, Address: 0x1028cd0 */
    ywk -= 96; /* Line 382, Address: 0x1028ce4 */
  } else { /* Line 383, Address: 0x1028cf0 */
    ywk = 0; /* Line 384, Address: 0x1028cf8 */
  }


  if (ywk > scralim_down) { /* Line 388, Address: 0x1028cfc */
    ywk = scralim_down; /* Line 389, Address: 0x1028d20 */
  }


  scra_v_posit.w.h = ywk; /* Line 393, Address: 0x1028d30 */

  scrbinit(xwk, ywk); /* Line 395, Address: 0x1028d38 */


  loopmapno = playmapnotbl[0]; /* Line 398, Address: 0x1028d48 */
  loopmapno2 = playmapnotbl[1]; /* Line 399, Address: 0x1028d58 */
  ballmapno = playmapnotbl[2]; /* Line 400, Address: 0x1028d68 */
  ballmapno2 = playmapnotbl[3]; /* Line 401, Address: 0x1028d78 */
} /* Line 402, Address: 0x1028d88 */




















static void scrbinit(short sXpos, short sYpos) { /* Line 423, Address: 0x1028db0 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 426, Address: 0x1028dbc */
  lYwk.w.l = 0; /* Line 427, Address: 0x1028dc4 */

  if (enkeino & 1) { /* Line 429, Address: 0x1028dc8 */
    lYwk.l = (unsigned int)lYwk.l >> 2; /* Line 430, Address: 0x1028de0 */
  } else { /* Line 431, Address: 0x1028dec */
    lYwk.l = (unsigned int)lYwk.l >> 1; /* Line 432, Address: 0x1028df4 */
    lYwk.l += (lYwk.l >> 2) + (lYwk.l >> 3); /* Line 433, Address: 0x1028e00 */
  }
  scrb_v_posit.l = lYwk.l; /* Line 435, Address: 0x1028e20 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 436, Address: 0x1028e2c */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 437, Address: 0x1028e38 */

  scrb_h_posit.w.h = (short)((unsigned short)sXpos >> 2) + sXpos; /* Line 439, Address: 0x1028e44 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 441, Address: 0x1028e84 */
  scrc_h_posit.w.h = sXpos; /* Line 442, Address: 0x1028ea0 */

  sXpos >>= 1; /* Line 444, Address: 0x1028eac */
  scrz_h_posit.w.h = sXpos; /* Line 445, Address: 0x1028eb8 */
} /* Line 446, Address: 0x1028ec4 */















void scroll() { /* Line 462, Address: 0x1028ed0 */
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

  if (scroll_start.b.h) return; /* Line 474, Address: 0x1028eec */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 479, Address: 0x1028efc */

  scrchk(); /* Line 481, Address: 0x1028f28 */

  scroll_h(); /* Line 483, Address: 0x1028f30 */
  scroll_v(); /* Line 484, Address: 0x1028f38 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 486, Address: 0x1028f40 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 487, Address: 0x1028f50 */


  lXwk = scra_hz * 64; /* Line 490, Address: 0x1028f60 */
  scrollz_h(lXwk, 6); /* Line 491, Address: 0x1028f74 */

  lXwk = scra_hz * 128; /* Line 493, Address: 0x1028f84 */
  scrollc_h(lXwk, 4); /* Line 494, Address: 0x1028f98 */

  lXwk = scra_hz * 64; /* Line 496, Address: 0x1028fa8 */
  lXwk += lXwk * 4; /* Line 497, Address: 0x1028fbc */
  scrollb_h(lXwk, 2); /* Line 498, Address: 0x1028fc4 */

  lYwk = (unsigned short)scra_v_posit.w.h; /* Line 500, Address: 0x1028fd4 */
  if (enkeino & 1) { /* Line 501, Address: 0x1028fe4 */
    lYwk >>= 2; /* Line 502, Address: 0x1028ffc */
  } /* Line 503, Address: 0x1029000 */
  else {
    lYwk >>= 1; /* Line 505, Address: 0x1029008 */
    lYwk += (lYwk >> 2) + (lYwk >> 3); /* Line 506, Address: 0x102900c */
  }


  scrollb_v(lYwk); /* Line 510, Address: 0x102901c */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 512, Address: 0x102902c */
  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 513, Address: 0x1029054 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 514, Address: 0x102908c */

  psHscw = hscrollwork; /* Line 516, Address: 0x10290a0 */

  if (enkeino & 1) { /* Line 518, Address: 0x10290ac */
    z51aline2(&psHscw); /* Line 519, Address: 0x10290c4 */
    z51aline3(&psHscw); /* Line 520, Address: 0x10290d0 */
  } /* Line 521, Address: 0x10290dc */
  else {

    ldwk.w.l = -scrz_h_posit.w.h; /* Line 524, Address: 0x10290e4 */




    for (i = 0; i < 8; ++i) { /* Line 529, Address: 0x1029104 */

      *psHscw++ = ldwk.w.l; /* Line 531, Address: 0x1029110 */
    } /* Line 532, Address: 0x1029124 */

    z51aline0(&psHscw); /* Line 534, Address: 0x1029134 */
    z51aline1(&psHscw); /* Line 535, Address: 0x1029140 */


    ldwk.w.l = -scrz_h_posit.w.h; /* Line 538, Address: 0x102914c */



    for (i = 0; i < 8; ++i) { /* Line 542, Address: 0x102916c */

      *psHscw++ = ldwk.w.l; /* Line 544, Address: 0x1029178 */
    } /* Line 545, Address: 0x102918c */
  }


  pHscrbuf = lphscrollbuff; /* Line 549, Address: 0x102919c */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 1016) >> 2; /* Line 550, Address: 0x10291a8 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 551, Address: 0x10291d8 */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 552, Address: 0x1029208 */
} /* Line 553, Address: 0x1029224 */













static void z51aline0(short** ppHscw) { /* Line 567, Address: 0x1029250 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51ascrtbl0[6] = { /* Line 572, Address: 0x1029268 */
    13, 11, 1, 1, 1, 1
  };

  lHwk = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 576, Address: 0x102929c */
  lHwk = (unsigned int)lHwk * 64 / 12; /* Line 577, Address: 0x10292c0 */
  lHwk *= 1024; /* Line 578, Address: 0x10292dc */

  ldHposwk.l = 0; /* Line 580, Address: 0x10292e0 */
  ldHposwk.w.l = scrz_h_posit.w.h; /* Line 581, Address: 0x10292e4 */

  *ppHscw += 34; /* Line 583, Address: 0x10292f0 */

  for (i = 5; i >= 0; --i) { /* Line 585, Address: 0x1029304 */

    wk = -ldHposwk.w.l; /* Line 587, Address: 0x1029310 */

    for (j = z51ascrtbl0[i]; j >= 0; --j) { /* Line 589, Address: 0x1029330 */

      --*ppHscw; /* Line 591, Address: 0x1029348 */
      **ppHscw = wk; /* Line 592, Address: 0x102935c */
    } /* Line 593, Address: 0x1029368 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 595, Address: 0x1029374 */
    ldHposwk.l += lHwk; /* Line 596, Address: 0x1029398 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 597, Address: 0x10293a4 */
  } /* Line 598, Address: 0x10293c8 */
  *ppHscw += 34; /* Line 599, Address: 0x10293d4 */
} /* Line 600, Address: 0x10293e8 */













static void z51aline1(short** ppHscw) { /* Line 614, Address: 0x1029410 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51ascrtbl1[7] = { /* Line 619, Address: 0x1029428 */
    15, 19, 1, 1, 1, 1, 1
  };

  lHwk = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 623, Address: 0x1029454 */
  lHwk = (unsigned int)lHwk * 64 / 14; /* Line 624, Address: 0x1029478 */
  lHwk *= 1024; /* Line 625, Address: 0x1029494 */

  ldHposwk.l = 0; /* Line 627, Address: 0x1029498 */
  ldHposwk.w.l = scrz_h_posit.w.h; /* Line 628, Address: 0x102949c */

  for (i = 6; i >= 0; --i) { /* Line 630, Address: 0x10294a8 */

    wk = -ldHposwk.w.l; /* Line 632, Address: 0x10294b4 */

    for (j = z51ascrtbl1[i]; j >= 0; --j) { /* Line 634, Address: 0x10294d4 */

      **ppHscw = wk; /* Line 636, Address: 0x10294ec */
      ++*ppHscw; /* Line 637, Address: 0x10294f8 */
    } /* Line 638, Address: 0x102950c */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 640, Address: 0x1029518 */
    ldHposwk.l += lHwk; /* Line 641, Address: 0x102953c */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 642, Address: 0x1029548 */
  } /* Line 643, Address: 0x102956c */
} /* Line 644, Address: 0x1029578 */













static void z51aline2(short** ppHscw) { /* Line 658, Address: 0x10295a0 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51ascrtbl2[11] = { /* Line 663, Address: 0x10295b8 */
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
  };

  lHwk = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 667, Address: 0x10295e4 */
  lHwk = (unsigned int)lHwk * 128 / 22; /* Line 668, Address: 0x1029608 */
  lHwk *= 512; /* Line 669, Address: 0x1029624 */

  ldHposwk.l = 0; /* Line 671, Address: 0x1029628 */
  ldHposwk.w.l = scrz_h_posit.w.h; /* Line 672, Address: 0x102962c */
  *ppHscw += 22; /* Line 673, Address: 0x1029638 */

  for (i = 10; i >= 0; --i) { /* Line 675, Address: 0x102964c */

    wk = -ldHposwk.w.l; /* Line 677, Address: 0x1029658 */

    for (j = z51ascrtbl2[i]; j >= 0; --j) { /* Line 679, Address: 0x1029678 */

      --*ppHscw; /* Line 681, Address: 0x1029690 */
      **ppHscw = wk; /* Line 682, Address: 0x10296a4 */
    } /* Line 683, Address: 0x10296b0 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 685, Address: 0x10296bc */
    ldHposwk.l += lHwk; /* Line 686, Address: 0x10296e0 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 687, Address: 0x10296ec */
  } /* Line 688, Address: 0x1029710 */
  *ppHscw += 22; /* Line 689, Address: 0x102971c */
} /* Line 690, Address: 0x1029730 */













static void z51aline3(short** ppHscw) { /* Line 704, Address: 0x1029750 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51ascrtbl3[3] = { /* Line 709, Address: 0x1029768 */
    31, 3, 5
  };

  lHwk = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 713, Address: 0x102978c */
  lHwk = (unsigned int)lHwk * 64 / 12; /* Line 714, Address: 0x10297b0 */
  lHwk *= 1024; /* Line 715, Address: 0x10297cc */

  ldHposwk.l = 0; /* Line 717, Address: 0x10297d0 */
  ldHposwk.w.l = scrz_h_posit.w.h; /* Line 718, Address: 0x10297d4 */

  for (i = 2; i >= 0; --i) { /* Line 720, Address: 0x10297e0 */

    wk = -ldHposwk.w.l; /* Line 722, Address: 0x10297ec */

    for (j = z51ascrtbl3[i]; j >= 0; --j) { /* Line 724, Address: 0x102980c */

      **ppHscw = wk; /* Line 726, Address: 0x1029824 */
      ++*ppHscw; /* Line 727, Address: 0x1029830 */
    } /* Line 728, Address: 0x1029844 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 730, Address: 0x1029850 */
    ldHposwk.l += lHwk; /* Line 731, Address: 0x1029874 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 732, Address: 0x1029880 */
  } /* Line 733, Address: 0x10298a4 */
} /* Line 734, Address: 0x10298b0 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 755, Address: 0x10298d0 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 759, Address: 0x10298ec */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 761, Address: 0x10298f0 */
    ldwk.w.l = *pHscrwk; /* Line 762, Address: 0x102990c */
    ++pHscrwk; /* Line 763, Address: 0x1029918 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 765, Address: 0x1029924 */
      (*pHscrbuf)->l = ldwk.l; /* Line 766, Address: 0x102992c */
    } /* Line 767, Address: 0x102993c */
  } /* Line 768, Address: 0x1029960 */
} /* Line 769, Address: 0x1029980 */









































































































static void scrollb_v(short yPos) { /* Line 875, Address: 0x10299a0 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 878, Address: 0x10299b0 */
  scrb_v_posit.w.h = yPos; /* Line 879, Address: 0x10299c0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 880, Address: 0x10299cc */

  if (!ywk) { /* Line 882, Address: 0x1029a04 */
    scrb_v_count ^= 16; /* Line 883, Address: 0x1029a0c */
    if (yPos - ysv < 0) { /* Line 884, Address: 0x1029a20 */
      scrflagb.b.h |= 1; /* Line 885, Address: 0x1029a40 */
    } /* Line 886, Address: 0x1029a54 */
    else {
      scrflagb.b.h |= 2; /* Line 888, Address: 0x1029a5c */
    }
  }


} /* Line 893, Address: 0x1029a70 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 911, Address: 0x1029a90 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 915, Address: 0x1029aa4 */
  lXwk = lXsv + xoffs; /* Line 916, Address: 0x1029aac */
  scrb_h_posit.l = lXwk; /* Line 917, Address: 0x1029ab4 */
  ldXwk.l = lXwk; /* Line 918, Address: 0x1029abc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 919, Address: 0x1029ac0 */
  ldXwk.w.l &= 16; /* Line 920, Address: 0x1029ae4 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 921, Address: 0x1029af0 */

  if (!ldXwk.b.b4) { /* Line 923, Address: 0x1029b0c */
    scrb_h_count ^= 16; /* Line 924, Address: 0x1029b18 */
    if (lXwk - lXsv < 0) { /* Line 925, Address: 0x1029b2c */
      scrflagb.b.h |= 1 << flgbit; /* Line 926, Address: 0x1029b38 */
    } /* Line 927, Address: 0x1029b5c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 929, Address: 0x1029b64 */
    }
  }


} /* Line 934, Address: 0x1029b8c */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 952, Address: 0x1029ba0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 956, Address: 0x1029bb4 */
  lXwk = lXsv + xoffs; /* Line 957, Address: 0x1029bbc */
  scrc_h_posit.l = lXwk; /* Line 958, Address: 0x1029bc4 */
  ldXwk.l = lXwk; /* Line 959, Address: 0x1029bcc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 960, Address: 0x1029bd0 */
  ldXwk.w.l &= 16; /* Line 961, Address: 0x1029bf4 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 962, Address: 0x1029c00 */

  if (!ldXwk.b.b4) { /* Line 964, Address: 0x1029c1c */
    scrc_h_count ^= 16; /* Line 965, Address: 0x1029c28 */
    if (lXwk - lXsv < 0) { /* Line 966, Address: 0x1029c3c */
      scrflagc.b.h |= 1 << flgbit; /* Line 967, Address: 0x1029c48 */
    } /* Line 968, Address: 0x1029c6c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 970, Address: 0x1029c74 */
    }
  }


} /* Line 975, Address: 0x1029c9c */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 993, Address: 0x1029cb0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 997, Address: 0x1029cc4 */
  lXwk = lXsv + xoffs; /* Line 998, Address: 0x1029ccc */
  scrz_h_posit.l = lXwk; /* Line 999, Address: 0x1029cd4 */
  ldXwk.l = lXwk; /* Line 1000, Address: 0x1029cdc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 1001, Address: 0x1029ce0 */
  ldXwk.w.l &= 16; /* Line 1002, Address: 0x1029d04 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 1003, Address: 0x1029d10 */

  if (!ldXwk.b.b4) { /* Line 1005, Address: 0x1029d2c */
    scrz_h_count ^= 16; /* Line 1006, Address: 0x1029d38 */
    if (lXwk - lXsv < 0) { /* Line 1007, Address: 0x1029d4c */
      scrflagz.b.h |= 1 << flgbit; /* Line 1008, Address: 0x1029d58 */
    } /* Line 1009, Address: 0x1029d7c */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 1011, Address: 0x1029d84 */
    }
  }


} /* Line 1016, Address: 0x1029dac */














static void scroll_h() { /* Line 1031, Address: 0x1029dc0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 1035, Address: 0x1029dd0 */

  scrh_move(); /* Line 1037, Address: 0x1029de0 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 1038, Address: 0x1029de8 */
  if (!bXwk) { /* Line 1039, Address: 0x1029e1c */
    scra_h_count ^= 16; /* Line 1040, Address: 0x1029e24 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 1041, Address: 0x1029e38 */
      scrflaga.b.h |= 4; /* Line 1042, Address: 0x1029e5c */
    } else { /* Line 1043, Address: 0x1029e70 */
      scrflaga.b.h |= 8; /* Line 1044, Address: 0x1029e78 */
    }
  }


} /* Line 1049, Address: 0x1029e8c */
















static void scrh_move() { /* Line 1066, Address: 0x1029eb0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 1069, Address: 0x1029eb8 */
  if (xwk == 0) { /* Line 1070, Address: 0x1029f00 */

    scra_hz = 0; /* Line 1072, Address: 0x1029f10 */
    return; /* Line 1073, Address: 0x1029f18 */
  } else if (xwk < 0) { /* Line 1074, Address: 0x1029f20 */

    if (xwk < -16) { /* Line 1076, Address: 0x1029f30 */
      xwk = -16; /* Line 1077, Address: 0x1029f44 */
    }


    xwk += scra_h_posit.w.h; /* Line 1081, Address: 0x1029f50 */
    if (xwk < scralim_left) { /* Line 1082, Address: 0x1029f64 */
      xwk = scralim_left; /* Line 1083, Address: 0x1029f88 */
    }
  } /* Line 1085, Address: 0x1029f98 */
  else {
    if (xwk > 16) { /* Line 1087, Address: 0x1029fa0 */
      xwk = 16; /* Line 1088, Address: 0x1029fb4 */
    }


    xwk += scra_h_posit.w.h; /* Line 1092, Address: 0x1029fc0 */
    if (xwk > scralim_right) { /* Line 1093, Address: 0x1029fd4 */
      xwk = scralim_right; /* Line 1094, Address: 0x1029ff8 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 1099, Address: 0x102a008 */
  scra_h_posit.w.h = xwk; /* Line 1100, Address: 0x102a038 */
} /* Line 1101, Address: 0x102a040 */














static void scroll_v() { /* Line 1116, Address: 0x102a050 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 1119, Address: 0x102a05c */
  if (actwk[0].cddat & 4) { /* Line 1120, Address: 0x102a090 */
    ywk -= 5; /* Line 1121, Address: 0x102a0a8 */
  }


  if (actwk[0].cddat & 2) { /* Line 1125, Address: 0x102a0b4 */
    ywk += 32; /* Line 1126, Address: 0x102a0cc */
    if (ywk < scra_vline) { /* Line 1127, Address: 0x102a0d8 */
      ywk -= scra_vline; /* Line 1128, Address: 0x102a0fc */
      sv_move_main2(ywk); /* Line 1129, Address: 0x102a110 */
      return; /* Line 1130, Address: 0x102a11c */
    } else if (ywk >= scra_vline + 64) { /* Line 1131, Address: 0x102a124 */
      ywk -= scra_vline + 64; /* Line 1132, Address: 0x102a14c */
      sv_move_main2(ywk); /* Line 1133, Address: 0x102a174 */
      return; /* Line 1134, Address: 0x102a180 */
    }
    ywk -= scra_vline + 64; /* Line 1136, Address: 0x102a188 */
    if (!limmoveflag) goto label1; /* Line 1137, Address: 0x102a1b0 */
    sv_move_sub2(); /* Line 1138, Address: 0x102a1c0 */
    return; /* Line 1139, Address: 0x102a1c8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 1144, Address: 0x102a1d0 */
    sv_move_main(ywk); /* Line 1145, Address: 0x102a1fc */
    return; /* Line 1146, Address: 0x102a208 */
  } else if (!limmoveflag) goto label1; /* Line 1147, Address: 0x102a210 */
  sv_move_sub2(); /* Line 1148, Address: 0x102a220 */
  return; /* Line 1149, Address: 0x102a228 */



label1:
  scra_vz = 0; /* Line 1154, Address: 0x102a230 */
} /* Line 1155, Address: 0x102a238 */













static void sv_move_main(short yPos) { /* Line 1169, Address: 0x102a250 */
  short spdwk;

  if (scra_vline == 96) { /* Line 1172, Address: 0x102a260 */
    if (actwk[0].mspeed.w < 0) { /* Line 1173, Address: 0x102a27c */
      spdwk = -actwk[0].mspeed.w; /* Line 1174, Address: 0x102a294 */
    } else { /* Line 1175, Address: 0x102a2b8 */
      spdwk = actwk[0].mspeed.w; /* Line 1176, Address: 0x102a2c0 */
    }


    if (spdwk >= 2048) { /* Line 1180, Address: 0x102a2d0 */
      sv_move_main2(yPos); /* Line 1181, Address: 0x102a2e4 */
    } /* Line 1182, Address: 0x102a2f0 */
    else {

      if (yPos > 6) { /* Line 1185, Address: 0x102a2f8 */
        sv_move_plus(1536); /* Line 1186, Address: 0x102a310 */
      } else if (yPos < -6) { /* Line 1187, Address: 0x102a31c */
        sv_move_minus(1536); /* Line 1188, Address: 0x102a33c */
      } /* Line 1189, Address: 0x102a348 */
      else sv_move_sub(yPos); /* Line 1190, Address: 0x102a350 */
    }
  } /* Line 1192, Address: 0x102a35c */
  else {
    if (yPos > 2) { /* Line 1194, Address: 0x102a364 */
      sv_move_plus(512); /* Line 1195, Address: 0x102a37c */
    } else if (yPos < -2) { /* Line 1196, Address: 0x102a388 */
      sv_move_minus(512); /* Line 1197, Address: 0x102a3a8 */
    } /* Line 1198, Address: 0x102a3b4 */
    else sv_move_sub(yPos); /* Line 1199, Address: 0x102a3bc */
  }

} /* Line 1202, Address: 0x102a3c8 */













static void sv_move_main2(short yPos) { /* Line 1216, Address: 0x102a3e0 */
  short spdwk;

  spdwk = 4096; /* Line 1219, Address: 0x102a3f0 */

  if (yPos > 16) { /* Line 1221, Address: 0x102a3fc */
    sv_move_plus(spdwk); /* Line 1222, Address: 0x102a414 */
  } else if (yPos < -16) { /* Line 1223, Address: 0x102a420 */
    sv_move_minus(spdwk); /* Line 1224, Address: 0x102a440 */
  } else { /* Line 1225, Address: 0x102a44c */
    sv_move_sub(yPos); /* Line 1226, Address: 0x102a454 */
  }
} /* Line 1228, Address: 0x102a460 */














static void sv_move_sub(short yPos) { /* Line 1243, Address: 0x102a480 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1246, Address: 0x102a48c */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1247, Address: 0x102a490 */
  if (yPos < 0) { /* Line 1248, Address: 0x102a4bc */
    scrv_up_ch(lSpd); /* Line 1249, Address: 0x102a4d0 */
  } else { /* Line 1250, Address: 0x102a4dc */
    scrv_down_ch(lSpd); /* Line 1251, Address: 0x102a4e4 */
  }
} /* Line 1253, Address: 0x102a4f0 */



static void sv_move_sub2() { /* Line 1257, Address: 0x102a500 */
  limmoveflag = 0; /* Line 1258, Address: 0x102a508 */

  sv_move_sub(0); /* Line 1260, Address: 0x102a510 */
} /* Line 1261, Address: 0x102a51c */













static void sv_move_minus(short speed) { /* Line 1275, Address: 0x102a530 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1278, Address: 0x102a53c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1279, Address: 0x102a560 */
  scrv_up_ch(lSpd); /* Line 1280, Address: 0x102a584 */
} /* Line 1281, Address: 0x102a590 */














static void scrv_up_ch(int_union lSpd) { /* Line 1296, Address: 0x102a5a0 */
  if (lSpd.w.l <= scralim_up) { /* Line 1297, Address: 0x102a5ac */
    if (lSpd.w.l > -256) { /* Line 1298, Address: 0x102a5d4 */

      lSpd.w.l = scralim_up; /* Line 1300, Address: 0x102a5ec */
    } else { /* Line 1301, Address: 0x102a5f8 */
      lSpd.w.l &= 2047; /* Line 1302, Address: 0x102a600 */
      actwk[0].yposi.w.l &= 2047; /* Line 1303, Address: 0x102a60c */
      scra_v_posit.w.h &= 2047; /* Line 1304, Address: 0x102a620 */
      scrb_v_posit.w.h &= 1023; /* Line 1305, Address: 0x102a634 */
    }
  }

  scrv_move(lSpd); /* Line 1309, Address: 0x102a648 */
} /* Line 1310, Address: 0x102a654 */













static void sv_move_plus(short sSpd) { /* Line 1324, Address: 0x102a670 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1327, Address: 0x102a67c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1328, Address: 0x102a69c */
  scrv_down_ch(lSpd); /* Line 1329, Address: 0x102a6c0 */
} /* Line 1330, Address: 0x102a6cc */














static void scrv_down_ch(int_union lSpd) { /* Line 1345, Address: 0x102a6e0 */
  if (lSpd.w.l >= scralim_down) { /* Line 1346, Address: 0x102a6ec */
    if (lSpd.w.l < 2048) { /* Line 1347, Address: 0x102a714 */

      lSpd.w.l = scralim_down; /* Line 1349, Address: 0x102a72c */
    } else { /* Line 1350, Address: 0x102a738 */
      lSpd.w.l -= 2048; /* Line 1351, Address: 0x102a740 */
      actwk[0].yposi.w.l &= 2047; /* Line 1352, Address: 0x102a74c */
      scra_v_posit.w.h -= 2048; /* Line 1353, Address: 0x102a760 */
      scrb_v_posit.w.h &= 1023; /* Line 1354, Address: 0x102a774 */
    }
  }

  scrv_move(lSpd); /* Line 1358, Address: 0x102a788 */
} /* Line 1359, Address: 0x102a794 */
















static void scrv_move(int_union lSpd) { /* Line 1376, Address: 0x102a7b0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1380, Address: 0x102a7c0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1381, Address: 0x102a7d0 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1382, Address: 0x102a7f4 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1383, Address: 0x102a808 */
  scra_vz = spdwk.w.l; /* Line 1384, Address: 0x102a820 */

  scra_v_posit.l = lSpd.l; /* Line 1386, Address: 0x102a82c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1388, Address: 0x102a838 */
  if (!ywk) { /* Line 1389, Address: 0x102a874 */
    scra_v_count ^= 16; /* Line 1390, Address: 0x102a87c */
    ywk = scra_v_posit.w.h - ysv; /* Line 1391, Address: 0x102a890 */
    if (ywk < 0) { /* Line 1392, Address: 0x102a8bc */
      scrflaga.b.h |= 1; /* Line 1393, Address: 0x102a8cc */
    } else { /* Line 1394, Address: 0x102a8e0 */
      scrflaga.b.h |= 2; /* Line 1395, Address: 0x102a8e8 */
    }
  }


} /* Line 1400, Address: 0x102a8fc */

















void scrollwrt() { /* Line 1418, Address: 0x102a910 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1427, Address: 0x102a930 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1428, Address: 0x102a934 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1429, Address: 0x102a940 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1430, Address: 0x102a94c */
  pScrFlag = &scrflagbw.b.h; /* Line 1431, Address: 0x102a954 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1432, Address: 0x102a95c */

  VramBase = 16384; /* Line 1434, Address: 0x102a970 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1435, Address: 0x102a974 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1436, Address: 0x102a980 */
  pMapWk = (unsigned char*)mapwka; /* Line 1437, Address: 0x102a98c */
  pScrFlag = &scrflagaw.b.h; /* Line 1438, Address: 0x102a994 */

  if (*pScrFlag) { /* Line 1440, Address: 0x102a99c */
    if (*pScrFlag & 1) { /* Line 1441, Address: 0x102a9a8 */
      *pScrFlag &= 254; /* Line 1442, Address: 0x102a9bc */

      lD4.l = -16; /* Line 1444, Address: 0x102a9c8 */
      wD5 = 65520; /* Line 1445, Address: 0x102a9d0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1447, Address: 0x102a9d8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1449, Address: 0x102a9f8 */
    }




    if (*pScrFlag & 2) { /* Line 1455, Address: 0x102aa24 */
      *pScrFlag &= 253; /* Line 1456, Address: 0x102aa38 */

      lD4.l = 224; /* Line 1458, Address: 0x102aa44 */
      wD5 = 65520; /* Line 1459, Address: 0x102aa4c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1460, Address: 0x102aa54 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1462, Address: 0x102aa74 */
    }




    if (*pScrFlag & 4) { /* Line 1468, Address: 0x102aaa0 */
      *pScrFlag &= 251; /* Line 1469, Address: 0x102aab4 */

      lD4.l = -16; /* Line 1471, Address: 0x102aac0 */
      wD5 = 65520; /* Line 1472, Address: 0x102aac8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1473, Address: 0x102aad0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1475, Address: 0x102aaf0 */
    }




    if (*pScrFlag & 8) { /* Line 1481, Address: 0x102ab1c */
      *pScrFlag &= 247; /* Line 1482, Address: 0x102ab30 */

      lD4.l = -16; /* Line 1484, Address: 0x102ab3c */
      wD5 = 320; /* Line 1485, Address: 0x102ab44 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1486, Address: 0x102ab4c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1488, Address: 0x102ab6c */
    }
  }






} /* Line 1497, Address: 0x102ab98 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1514, Address: 0x102abc0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1525, Address: 0x102abec */

  if (*pScrFlag & 1) { /* Line 1527, Address: 0x102abf4 */
    *pScrFlag &= 254; /* Line 1528, Address: 0x102ac0c */
  } /* Line 1529, Address: 0x102ac20 */
  else {
    *pScrFlag &= 254; /* Line 1531, Address: 0x102ac28 */

    if (*pScrFlag & 2) { /* Line 1533, Address: 0x102ac3c */
      *pScrFlag &= 253; /* Line 1534, Address: 0x102ac54 */
      lD4.w.l = 224; /* Line 1535, Address: 0x102ac68 */
    } /* Line 1536, Address: 0x102ac70 */
    else {
      *pScrFlag &= 253; /* Line 1538, Address: 0x102ac78 */
      goto label1; /* Line 1539, Address: 0x102ac8c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1544, Address: 0x102ac94 */
  wD0 &= 127; /* Line 1545, Address: 0x102ace4 */
  if (enkeino & 1) { /* Line 1546, Address: 0x102acec */

    wD0 = (z81awrttbl2 + (short)wD0)[1]; /* Line 1548, Address: 0x102ad04 */
  } else { /* Line 1549, Address: 0x102ad2c */
    wD0 = z81awrttbl[wD0 + 1]; /* Line 1550, Address: 0x102ad34 */
  }





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1557, Address: 0x102ad54 */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1558, Address: 0x102ad74 */
  if (wD0 != 0) { /* Line 1559, Address: 0x102ad98 */
    wD5 = 65520; /* Line 1560, Address: 0x102ada4 */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1561, Address: 0x102adac */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1563, Address: 0x102adcc */



  } /* Line 1567, Address: 0x102adf8 */
  else {

    wD5 = 0; /* Line 1570, Address: 0x102ae00 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1571, Address: 0x102ae04 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1575, Address: 0x102ae24 */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1582, Address: 0x102ae50 */






    lD4.l = -16; /* Line 1589, Address: 0x102ae64 */
    wD5 = 65520; /* Line 1590, Address: 0x102ae6c */
    if (*pScrFlag & 168) { /* Line 1591, Address: 0x102ae74 */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1592, Address: 0x102ae8c */
      wD5 = 320; /* Line 1593, Address: 0x102aeac */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1597, Address: 0x102aeb4 */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1599, Address: 0x102aee4 */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1600, Address: 0x102aef0 */



    for (i = 0; i < 16; ++i) { /* Line 1604, Address: 0x102af00 */
      if (enkeino & 1) { /* Line 1605, Address: 0x102af0c */
        wD0 = z81awrttbl2[WrtTblCnt++]; /* Line 1606, Address: 0x102af24 */
      } else { /* Line 1607, Address: 0x102af44 */
        wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1608, Address: 0x102af4c */
      }

      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1611, Address: 0x102af6c */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1612, Address: 0x102afa4 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1613, Address: 0x102afc4 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1615, Address: 0x102afe8 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1618, Address: 0x102b00c */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1620, Address: 0x102b02c */
      }
      lD4.w.l += 16; /* Line 1622, Address: 0x102b040 */
    } /* Line 1623, Address: 0x102b04c */
    *pScrFlag = 0; /* Line 1624, Address: 0x102b05c */
  }
} /* Line 1626, Address: 0x102b064 */





void scrollwrtc() {} /* Line 1632, Address: 0x102b090 */




void scrollwrtz() {} /* Line 1637, Address: 0x102b0a0 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1655, Address: 0x102b0b0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1668, Address: 0x102b0d8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1671, Address: 0x102b0f8 */
    pTilePoint->x += 2; /* Line 1672, Address: 0x102b10c */
    if (pTilePoint->x >= 64) { /* Line 1673, Address: 0x102b120 */
      pTilePoint->x -= 64; /* Line 1674, Address: 0x102b134 */
    }
    xOffs += 16; /* Line 1676, Address: 0x102b148 */
  } while (--lpcnt >= 0); /* Line 1677, Address: 0x102b154 */
} /* Line 1678, Address: 0x102b168 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1682, Address: 0x102b180 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1686, Address: 0x102b1a8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1689, Address: 0x102b1c8 */
    pTilePoint->x += 2; /* Line 1690, Address: 0x102b1dc */
    if (pTilePoint->x >= 64) { /* Line 1691, Address: 0x102b1f0 */
      pTilePoint->x -= 64; /* Line 1692, Address: 0x102b204 */
    }
    xOffs += 16; /* Line 1694, Address: 0x102b218 */
  } while (--lpcnt >= 0); /* Line 1695, Address: 0x102b224 */
} /* Line 1696, Address: 0x102b238 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1716, Address: 0x102b250 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1720, Address: 0x102b278 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1723, Address: 0x102b298 */
    pTilePoint->y += 2; /* Line 1724, Address: 0x102b2ac */
    if (pTilePoint->y >= 32) { /* Line 1725, Address: 0x102b2bc */
      pTilePoint->y -= 32; /* Line 1726, Address: 0x102b2d0 */
    }
    yOffs += 16; /* Line 1728, Address: 0x102b2e0 */
  } while (--lpcnt >= 0); /* Line 1729, Address: 0x102b2ec */
} /* Line 1730, Address: 0x102b300 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1749, Address: 0x102b310 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1755, Address: 0x102b344 */

    base = 1; /* Line 1757, Address: 0x102b354 */
  } /* Line 1758, Address: 0x102b358 */
  else if (VramBase == 16384) { /* Line 1759, Address: 0x102b360 */

    base = 0; /* Line 1761, Address: 0x102b370 */
  }
  x = pTilePoint->x; /* Line 1763, Address: 0x102b374 */
  y = pTilePoint->y; /* Line 1764, Address: 0x102b37c */


  frip = BlkIndex & 6144; /* Line 1767, Address: 0x102b384 */
  BlkIndex &= 1023; /* Line 1768, Address: 0x102b38c */
  if (frip == 6144) { /* Line 1769, Address: 0x102b398 */

    p0 = 3, p1 = 2; /* Line 1771, Address: 0x102b3a4 */
    p2 = 1, p3 = 0; /* Line 1772, Address: 0x102b3ac */
  } /* Line 1773, Address: 0x102b3b4 */
  else if (frip & 4096) { /* Line 1774, Address: 0x102b3bc */

    p0 = 2, p1 = 3; /* Line 1776, Address: 0x102b3c8 */
    p2 = 0, p3 = 1; /* Line 1777, Address: 0x102b3d0 */
  } /* Line 1778, Address: 0x102b3d8 */
  else if (frip & 2048) { /* Line 1779, Address: 0x102b3e0 */

    p0 = 1, p1 = 0; /* Line 1781, Address: 0x102b3ec */
    p2 = 3, p3 = 2; /* Line 1782, Address: 0x102b3f4 */
  } /* Line 1783, Address: 0x102b3fc */
  else {

    p0 = 0, p1 = 1; /* Line 1786, Address: 0x102b404 */
    p2 = 2, p3 = 3; /* Line 1787, Address: 0x102b40c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1790, Address: 0x102b414 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1791, Address: 0x102b458 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1792, Address: 0x102b49c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1793, Address: 0x102b4e0 */

} /* Line 1795, Address: 0x102b524 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1813, Address: 0x102b560 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1814, Address: 0x102b580 */
} /* Line 1815, Address: 0x102b5a0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1817, Address: 0x102b5b0 */
  wH_posiw = 0; /* Line 1818, Address: 0x102b5d0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1819, Address: 0x102b5d4 */
} /* Line 1820, Address: 0x102b5f4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1827, Address: 0x102b610 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1833, Address: 0x102b640 */
  yOffs += wV_posiw; /* Line 1834, Address: 0x102b650 */





  if ((short)xOffs < 0) /* Line 1840, Address: 0x102b660 */
    xOffs = 0; /* Line 1841, Address: 0x102b67c */
  if ((short)yOffs < 0) /* Line 1842, Address: 0x102b680 */
    yOffs = 0; /* Line 1843, Address: 0x102b69c */
  if ((short)xOffs >= 16384) /* Line 1844, Address: 0x102b6a0 */
    xOffs = 16383; /* Line 1845, Address: 0x102b6c0 */
  if ((short)yOffs >= 2048) /* Line 1846, Address: 0x102b6c8 */
    yOffs = 2047; /* Line 1847, Address: 0x102b6e8 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1848, Address: 0x102b6f0 */
  if (i < 0) i = 0; /* Line 1849, Address: 0x102b738 */

  ScreenNo = pMapWk[i] & 127; /* Line 1851, Address: 0x102b744 */

  if (ScreenNo) { /* Line 1853, Address: 0x102b760 */




    xOffs &= 32767; /* Line 1858, Address: 0x102b768 */
    yOffs &= 32767; /* Line 1859, Address: 0x102b774 */


    xBlk = xOffs; /* Line 1862, Address: 0x102b780 */
    xBlk %= 256; /* Line 1863, Address: 0x102b788 */
    xBlk /= 16; /* Line 1864, Address: 0x102b7a8 */
    yBlk = yOffs; /* Line 1865, Address: 0x102b7c4 */
    yBlk %= 256; /* Line 1866, Address: 0x102b7cc */
    yBlk /= 16; /* Line 1867, Address: 0x102b7ec */

    lpw = pmapwk; /* Line 1869, Address: 0x102b808 */
    lpw += xBlk; /* Line 1870, Address: 0x102b810 */
    lpw += yBlk * 16; /* Line 1871, Address: 0x102b818 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1872, Address: 0x102b824 */
    *pIndex = *lpw; /* Line 1873, Address: 0x102b83c */

    return 1; /* Line 1875, Address: 0x102b84c */
  }

  *pIndex = 0; /* Line 1878, Address: 0x102b858 */
  return 0; /* Line 1879, Address: 0x102b860 */
} /* Line 1880, Address: 0x102b864 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1900, Address: 0x102b890 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1908, Address: 0x102b8b8 */
  if (ScreenNo) { /* Line 1909, Address: 0x102b91c */





    xBlk = xOffs; /* Line 1915, Address: 0x102b924 */
    xBlk %= 256; /* Line 1916, Address: 0x102b92c */
    xBlk /= 16; /* Line 1917, Address: 0x102b94c */
    yBlk = yOffs; /* Line 1918, Address: 0x102b968 */
    yBlk %= 256; /* Line 1919, Address: 0x102b970 */
    yBlk /= 16; /* Line 1920, Address: 0x102b990 */


    lpw = pmapwk; /* Line 1923, Address: 0x102b9ac */
    lpw += xBlk; /* Line 1924, Address: 0x102b9b4 */
    lpw += yBlk * 16; /* Line 1925, Address: 0x102b9bc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1926, Address: 0x102b9c8 */
    *ppBlockNo = lpw; /* Line 1927, Address: 0x102b9e0 */
    *pIndex = *lpw; /* Line 1928, Address: 0x102b9e8 */




    return 1; /* Line 1933, Address: 0x102b9f8 */
  }

  *pIndex = 0; /* Line 1936, Address: 0x102ba04 */
  return 0; /* Line 1937, Address: 0x102ba0c */
} /* Line 1938, Address: 0x102ba10 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1952, Address: 0x102ba30 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1959, Address: 0x102ba4c */
  pMapWk = (unsigned char*)mapwka; /* Line 1960, Address: 0x102ba50 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1961, Address: 0x102ba58 */
    *pBlockIndex = BlockNo; /* Line 1962, Address: 0x102ba7c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1963, Address: 0x102ba88 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1964, Address: 0x102baa0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1965, Address: 0x102bab4 */
    }
  }


} /* Line 1970, Address: 0x102bacc */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1984, Address: 0x102baf0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1985, Address: 0x102bafc */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1986, Address: 0x102bb28 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1987, Address: 0x102bb74 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1988, Address: 0x102bba0 */

          return 0; /* Line 1990, Address: 0x102bbec */
        }
      }
    }
  }

  return 1; /* Line 1996, Address: 0x102bbf8 */
} /* Line 1997, Address: 0x102bbfc */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 2014, Address: 0x102bc10 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 2015, Address: 0x102bc2c */

} /* Line 2017, Address: 0x102bc48 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 2019, Address: 0x102bc60 */
  wH_posiw = 0; /* Line 2020, Address: 0x102bc7c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 2021, Address: 0x102bc80 */

} /* Line 2023, Address: 0x102bc9c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 2025, Address: 0x102bcb0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 2026, Address: 0x102bcc4 */

} /* Line 2028, Address: 0x102bce0 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 2030, Address: 0x102bcf0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 2031, Address: 0x102bd0c */

} /* Line 2033, Address: 0x102bd28 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 2035, Address: 0x102bd40 */
  xOffs += wH_posiw; /* Line 2036, Address: 0x102bd58 */
  yOffs += wV_posiw; /* Line 2037, Address: 0x102bd68 */
  yOffs &= 240; /* Line 2038, Address: 0x102bd78 */
  xOffs &= 496; /* Line 2039, Address: 0x102bd84 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 2041, Address: 0x102bd90 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 2042, Address: 0x102bdbc */


} /* Line 2045, Address: 0x102bde8 */















void mapwrt() { /* Line 2061, Address: 0x102be00 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 2066, Address: 0x102be18 */
  wV_posiw = scra_v_posiw.w.h; /* Line 2067, Address: 0x102be24 */
  pMapWk = (unsigned char*)mapwka; /* Line 2068, Address: 0x102be30 */
  VramBase = 16384; /* Line 2069, Address: 0x102be38 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 2070, Address: 0x102be3c */
  mapwrtb(); /* Line 2071, Address: 0x102be54 */
} /* Line 2072, Address: 0x102be5c */


void mapwrtb() { /* Line 2075, Address: 0x102be80 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scrb_h_posiw.w.h; /* Line 2080, Address: 0x102be98 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 2081, Address: 0x102bea4 */
  pMapWk = (unsigned char*)mapwkb; /* Line 2082, Address: 0x102beb0 */
  VramBase = 24576; /* Line 2083, Address: 0x102beb8 */
  mapwrt_z81a(pMapWk, VramBase); /* Line 2084, Address: 0x102bebc */

} /* Line 2086, Address: 0x102becc */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 2089, Address: 0x102bef0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 2090, Address: 0x102bf08 */
} /* Line 2091, Address: 0x102bf28 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 2096, Address: 0x102bf40 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 2100, Address: 0x102bf60 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 2103, Address: 0x102bf7c */



    wD4 += 16; /* Line 2107, Address: 0x102bfa4 */
  } while ((short)--wD6 >= 0); /* Line 2108, Address: 0x102bfb0 */

} /* Line 2110, Address: 0x102bfd8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 2116, Address: 0x102bff0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 2119, Address: 0x102c00c */
  wD6 = 15; /* Line 2120, Address: 0x102c014 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 65520; /* Line 2123, Address: 0x102c01c */

    if (enkeino & 1) { /* Line 2125, Address: 0x102c040 */
      mapwrt_sub(&z81awrttbl2[1], wD0, wD4, pMapWk, VramBase); /* Line 2126, Address: 0x102c058 */
    } else { /* Line 2127, Address: 0x102c078 */
      mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 2128, Address: 0x102c080 */
    }
    wD4 += 16; /* Line 2130, Address: 0x102c0a0 */
  } while ((short)--wD6 >= 0); /* Line 2131, Address: 0x102c0a8 */
} /* Line 2132, Address: 0x102c0cc */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2158, Address: 0x102c0f0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 = (short)wD0 / 16; /* Line 2163, Address: 0x102c118 */

  wD0 = pWrttbl[(short)wD0]; /* Line 2165, Address: 0x102c14c */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2167, Address: 0x102c174 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2168, Address: 0x102c198 */
  if (wD0) { /* Line 2169, Address: 0x102c1c0 */
    wD5 = 65520; /* Line 2170, Address: 0x102c1cc */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2171, Address: 0x102c1d4 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2174, Address: 0x102c1f0 */



  } /* Line 2178, Address: 0x102c218 */
  else {

    wD5 = 0; /* Line 2181, Address: 0x102c220 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2182, Address: 0x102c224 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2186, Address: 0x102c240 */
  }





} /* Line 2193, Address: 0x102c268 */










void mapinit() { /* Line 2204, Address: 0x102c290 */
  short tbl[9] = { /* Line 2205, Address: 0x102c2b0 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 2210, Address: 0x102c2dc */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  EnkeiNo = 0; /* Line 2216, Address: 0x102c300 */
  pTbl = tbl; /* Line 2217, Address: 0x102c304 */

  while ((poswk = *pTbl++) >= 0) { /* Line 2219, Address: 0x102c308 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 2220, Address: 0x102c310 */


    ++EnkeiNo; /* Line 2223, Address: 0x102c334 */
  } /* Line 2224, Address: 0x102c338 */


  TileNo = 603; /* Line 2227, Address: 0x102c35c */
  if (EnkeiNo == 0) { /* Line 2228, Address: 0x102c360 */
    i = 113; /* Line 2229, Address: 0x102c368 */
    BmpNo = 0; /* Line 2230, Address: 0x102c36c */

    for ( ; i > 0; --i) { /* Line 2232, Address: 0x102c370 */
      ChangeTileBmp(TileNo++, BmpNo++); /* Line 2233, Address: 0x102c378 */
    } /* Line 2234, Address: 0x102c398 */
  }


  colorset2(mapinittbl.colorno2); /* Line 2238, Address: 0x102c3a4 */
  colorset(mapinittbl.colorno2); /* Line 2239, Address: 0x102c3b8 */


  if (play_start & 2) divdevset(); /* Line 2242, Address: 0x102c3cc */
} /* Line 2243, Address: 0x102c3ec */




void mapset() {} /* Line 2248, Address: 0x102c420 */



void divdevset() {} /* Line 2252, Address: 0x102c430 */



void enecginit() {} /* Line 2256, Address: 0x102c440 */















static void mapset2(unsigned char* pMapDst, int idx) { /* Line 2272, Address: 0x102c450 */
  int h, v, hwk;
  unsigned char *pZonetbl, *pMapwk;

  pZonetbl = zonemaptbl[idx]; /* Line 2276, Address: 0x102c470 */
  h = *pZonetbl++; /* Line 2277, Address: 0x102c488 */
  v = *pZonetbl++; /* Line 2278, Address: 0x102c498 */
  for ( ;v >= 0; --v) { /* Line 2279, Address: 0x102c4a8 */
    pMapwk = pMapDst; /* Line 2280, Address: 0x102c4b0 */

    for (hwk = h; hwk >= 0; --hwk) { /* Line 2282, Address: 0x102c4b4 */
      *pMapwk++ = *pZonetbl++; /* Line 2283, Address: 0x102c4c0 */
    } /* Line 2284, Address: 0x102c4d8 */

    pMapDst += 64; /* Line 2286, Address: 0x102c4e4 */
  } /* Line 2287, Address: 0x102c4f0 */
} /* Line 2288, Address: 0x102c4fc */
