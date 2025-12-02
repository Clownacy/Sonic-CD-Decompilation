#include "..\EQU.H"
#include "SCR51A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL5A.H"

static void playposiset(void);
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
short playpositbl[1][2] = { { 64, 364 } };
unsigned char playmapnotbl[4] = { 127, 127, 21, 25 };
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;
extern unsigned char* zonemaptbl[];





























































































void enkeichg(void) { /* Line 154, Address: 0x10287f0 */
  short tbl[6] = { /* Line 155, Address: 0x1028810 */
    3584, 7168, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 159, Address: 0x1028844 */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  if (scrflaga.b.h) return; /* Line 165, Address: 0x1028868 */



  EnkeiNo = 0; /* Line 169, Address: 0x1028878 */
  pTbl = tbl; /* Line 170, Address: 0x102887c */

  while ((poswk = *pTbl++) >= 0) { /* Line 172, Address: 0x1028880 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 173, Address: 0x1028888 */


    ++EnkeiNo; /* Line 176, Address: 0x10288ac */
  } /* Line 177, Address: 0x10288b0 */


  if (enkeino == EnkeiNo) return; /* Line 180, Address: 0x10288d4 */




  enkeino = EnkeiNo; /* Line 185, Address: 0x10288e8 */


  TileNo = 523; /* Line 188, Address: 0x10288f4 */
  if (EnkeiNo == 1) { /* Line 189, Address: 0x10288f8 */
    i = 175; /* Line 190, Address: 0x1028904 */
    BmpNo = 168; /* Line 191, Address: 0x1028908 */
  } else { /* Line 192, Address: 0x102890c */
    i = 168; /* Line 193, Address: 0x1028914 */
    BmpNo = 0; /* Line 194, Address: 0x1028918 */
  }
  for ( ; i > 0; --i) { /* Line 196, Address: 0x102891c */
    ChangeTileBmp(TileNo++, BmpNo++); /* Line 197, Address: 0x1028924 */
  } /* Line 198, Address: 0x1028944 */

  colorset2((tbl0[EnkeiNo] >> 2) + 4); /* Line 200, Address: 0x1028950 */
  colorset((tbl0[EnkeiNo] >> 2) + 4); /* Line 201, Address: 0x1028970 */

  mapset2((unsigned char*)mapwkb, tbl0[EnkeiNo] / 2); /* Line 203, Address: 0x1028990 */
  scrbinit(scra_h_posit.w.h, scra_v_posit.w.h); /* Line 204, Address: 0x10289c8 */
  mapwrt_cnt = 1; /* Line 205, Address: 0x10289e0 */
} /* Line 206, Address: 0x10289ec */












sprite_status* main_chk(void) {
  if (main_play == 0) /* Line 220, Address: 0x1028a20 */
    return &actwk[0]; /* Line 221, Address: 0x1028a34 */
  else
    return &actwk[1]; /* Line 223, Address: 0x1028a44 */

} /* Line 225, Address: 0x1028a4c */





































void scr_set(void) { /* Line 263, Address: 0x1028a60 */
  short* pScrTbl;

  scrh_flag = scrv_flag = 0; /* Line 266, Address: 0x1028a6c */
  scr_die.b.h = zone_flag.b.h = 0; /* Line 267, Address: 0x1028a80 */
  scr_timer.b.h = 0; /* Line 268, Address: 0x1028a94 */

  pScrTbl = scr_dir_tbl; /* Line 270, Address: 0x1028a9c */
  scrar_no = *pScrTbl; /* Line 271, Address: 0x1028aa4 */
  ++pScrTbl; /* Line 272, Address: 0x1028ab0 */
  scralim_left = scralim_n_left = *pScrTbl; /* Line 273, Address: 0x1028ab4 */
  ++pScrTbl; /* Line 274, Address: 0x1028ac8 */
  scralim_right = scralim_n_right = *pScrTbl; /* Line 275, Address: 0x1028acc */
  ++pScrTbl; /* Line 276, Address: 0x1028ae0 */
  scralim_up = scralim_n_up = *pScrTbl; /* Line 277, Address: 0x1028ae4 */
  ++pScrTbl; /* Line 278, Address: 0x1028af8 */
  scralim_down = scralim_n_down = *pScrTbl; /* Line 279, Address: 0x1028afc */
  scra_h_keep = *pScrTbl + 576; /* Line 280, Address: 0x1028b10 */
  ++pScrTbl; /* Line 281, Address: 0x1028b30 */
  scra_h_count = 16; /* Line 282, Address: 0x1028b34 */
  scra_v_count = 16; /* Line 283, Address: 0x1028b40 */

  scra_vline = *pScrTbl; /* Line 285, Address: 0x1028b4c */
  scra_hline = 160; /* Line 286, Address: 0x1028b58 */

  playposiset(); /* Line 288, Address: 0x1028b64 */
} /* Line 289, Address: 0x1028b6c */






































static void playposiset(void) { /* Line 328, Address: 0x1028b80 */
  short xwk, ywk, *pPositbl;

  if (plflag) { /* Line 331, Address: 0x1028b94 */
    playload(); /* Line 332, Address: 0x1028ba4 */
    xwk = actwk[0].xposi.w.h; /* Line 333, Address: 0x1028bac */

    if (actwk[0].yposi.w.h > 0) { /* Line 335, Address: 0x1028bbc */
      ywk = actwk[0].yposi.w.h; /* Line 336, Address: 0x1028bd4 */
    } else { /* Line 337, Address: 0x1028be4 */
      ywk = 0; /* Line 338, Address: 0x1028bec */
    }
  } /* Line 340, Address: 0x1028bf0 */
  else {
    pPositbl = playpositbl[0]; /* Line 342, Address: 0x1028bf8 */


    actwk[0].xposi.w.h = xwk = pPositbl[0]; /* Line 345, Address: 0x1028c00 */
    actwk[0].yposi.w.h = ywk = pPositbl[1]; /* Line 346, Address: 0x1028c14 */
  }


  if (xwk > 160) { /* Line 350, Address: 0x1028c28 */
    xwk -= 160; /* Line 351, Address: 0x1028c3c */
  } else { /* Line 352, Address: 0x1028c48 */
    xwk = 0; /* Line 353, Address: 0x1028c50 */
  }


  if (xwk > scralim_right) { /* Line 357, Address: 0x1028c54 */
    xwk = scralim_right; /* Line 358, Address: 0x1028c78 */
  }


  scra_h_posit.w.h = xwk; /* Line 362, Address: 0x1028c88 */

  if (ywk > 96) { /* Line 364, Address: 0x1028c90 */
    ywk -= 96; /* Line 365, Address: 0x1028ca4 */
  } else { /* Line 366, Address: 0x1028cb0 */
    ywk = 0; /* Line 367, Address: 0x1028cb8 */
  }


  if (ywk > scralim_down) { /* Line 371, Address: 0x1028cbc */
    ywk = scralim_down; /* Line 372, Address: 0x1028ce0 */
  }


  scra_v_posit.w.h = ywk; /* Line 376, Address: 0x1028cf0 */

  scrbinit(xwk, ywk); /* Line 378, Address: 0x1028cf8 */


  loopmapno = playmapnotbl[0]; /* Line 381, Address: 0x1028d08 */
  loopmapno2 = playmapnotbl[1]; /* Line 382, Address: 0x1028d18 */
  ballmapno = playmapnotbl[2]; /* Line 383, Address: 0x1028d28 */
  ballmapno2 = playmapnotbl[3]; /* Line 384, Address: 0x1028d38 */
} /* Line 385, Address: 0x1028d48 */




















static void scrbinit(short sXpos, short sYpos) { /* Line 406, Address: 0x1028d70 */
  int_union lYwk;

  lYwk.w.h = sYpos; /* Line 409, Address: 0x1028d7c */
  lYwk.w.l = 0; /* Line 410, Address: 0x1028d84 */

  lYwk.l = (unsigned int)lYwk.l >> 3; /* Line 412, Address: 0x1028d88 */
  lYwk.l += lYwk.l >> 1; /* Line 413, Address: 0x1028d94 */

  scrb_v_posit.l = lYwk.l; /* Line 415, Address: 0x1028da8 */
  scrc_v_posit.w.h = lYwk.w.h; /* Line 416, Address: 0x1028db4 */
  scrz_v_posit.w.h = lYwk.w.h; /* Line 417, Address: 0x1028dc0 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 419, Address: 0x1028dcc */
  scrb_h_posit.w.h = sXpos + (sXpos >> 1); /* Line 420, Address: 0x1028de8 */

  sXpos = (unsigned short)sXpos >> 1; /* Line 422, Address: 0x1028e18 */
  scrc_h_posit.w.h = sXpos; /* Line 423, Address: 0x1028e34 */

  sXpos >>= 2; /* Line 425, Address: 0x1028e40 */
  scrz_h_posit.w.h = sXpos * 3; /* Line 426, Address: 0x1028e4c */
} /* Line 427, Address: 0x1028e70 */















void scroll(void) { /* Line 443, Address: 0x1028e80 */
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

  if (scroll_start.b.h) return; /* Line 455, Address: 0x1028e9c */




  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 460, Address: 0x1028eac */

  scrchk(); /* Line 462, Address: 0x1028ed8 */

  scroll_h(); /* Line 464, Address: 0x1028ee0 */
  scroll_v(); /* Line 465, Address: 0x1028ee8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 467, Address: 0x1028ef0 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 468, Address: 0x1028f00 */


  lXwk = scra_hz * 16 * 3; /* Line 471, Address: 0x1028f10 */
  scrollz_h(lXwk, 6); /* Line 472, Address: 0x1028f2c */

  lXwk = scra_hz * 64; /* Line 474, Address: 0x1028f3c */
  scrollc_h(lXwk, 4); /* Line 475, Address: 0x1028f50 */

  lXwk = scra_hz * 64; /* Line 477, Address: 0x1028f60 */
  lXwk += lXwk * 2; /* Line 478, Address: 0x1028f74 */
  scrollb_h(lXwk, 2); /* Line 479, Address: 0x1028f7c */

  lYwk = (unsigned int)scra_v_posit.l >> 3; /* Line 481, Address: 0x1028f8c */
  lYwk += lYwk >> 1; /* Line 482, Address: 0x1028f98 */
  lYwk = (unsigned int)lYwk >> 16 & 65535 | lYwk << 16 & -65536; /* Line 483, Address: 0x1028fa0 */


  scrollb_v(lYwk); /* Line 486, Address: 0x1028fb8 */

  scrc_v_posit.w.h = scrz_v_posit.w.h = vscroll.w.l = scrb_v_posit.w.h; /* Line 488, Address: 0x1028fc8 */
  scrflagb.b.h = scrflagb.b.h | scrflagz.b.h | scrflagc.b.h; /* Line 489, Address: 0x1028ff0 */
  scrflagz.b.h = scrflagc.b.h = 0; /* Line 490, Address: 0x1029028 */

  psHscw = hscrollwork; /* Line 492, Address: 0x102903c */

  if (enkeino & 1) { /* Line 494, Address: 0x1029048 */

    z51bline2(&psHscw); /* Line 496, Address: 0x1029060 */
    z51bline3(&psHscw); /* Line 497, Address: 0x102906c */
    ldwk.w.l = -scrb_h_posit.w.h; /* Line 498, Address: 0x1029078 */
    for (i = 0; i < 18; ++i) { /* Line 499, Address: 0x1029098 */

      *psHscw++ = ldwk.w.l; /* Line 501, Address: 0x10290a4 */
    } /* Line 502, Address: 0x10290b8 */
  } /* Line 503, Address: 0x10290c8 */
  else {
    z51bline0(&psHscw); /* Line 505, Address: 0x10290d0 */
    z51bline1(&psHscw); /* Line 506, Address: 0x10290dc */
  }


  pHscrbuf = lphscrollbuff; /* Line 510, Address: 0x10290e8 */
  sYnum = (unsigned short)(scrb_v_posit.w.h & 504) >> 2; /* Line 511, Address: 0x10290f4 */
  psHscr = &hscrollwork[sYnum / 2]; /* Line 512, Address: 0x1029124 */
  zonescrsetsub0(scrb_v_posit.w.h, 28, &pHscrbuf, psHscr); /* Line 513, Address: 0x1029154 */
} /* Line 514, Address: 0x1029170 */













static void z51bline0(short** ppHscw) { /* Line 528, Address: 0x10291a0 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51bscrtbl0[4] = { /* Line 533, Address: 0x10291b8 */
    7, 3, 1, 5
  };

  lHwk = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 537, Address: 0x10291e4 */
  lHwk = (unsigned int)lHwk * 64 / 8; /* Line 538, Address: 0x1029208 */
  lHwk *= 1024; /* Line 539, Address: 0x1029214 */

  ldHposwk.l = 0; /* Line 541, Address: 0x1029218 */
  ldHposwk.w.l = scrz_h_posit.w.h; /* Line 542, Address: 0x102921c */
  *ppHscw += 20; /* Line 543, Address: 0x1029228 */

  for (i = 3; i >= 0; --i) { /* Line 545, Address: 0x102923c */

    wk = -ldHposwk.w.l; /* Line 547, Address: 0x1029248 */

    for (j = z51bscrtbl0[i]; j >= 0; --j) { /* Line 549, Address: 0x1029268 */

      --*ppHscw; /* Line 551, Address: 0x1029280 */
      **ppHscw = wk; /* Line 552, Address: 0x1029294 */
    } /* Line 553, Address: 0x10292a0 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 555, Address: 0x10292ac */
    ldHposwk.l += lHwk; /* Line 556, Address: 0x10292d0 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 557, Address: 0x10292dc */
  } /* Line 558, Address: 0x1029300 */
  *ppHscw += 20; /* Line 559, Address: 0x102930c */
} /* Line 560, Address: 0x1029320 */













static void z51bline1(short** ppHscw) { /* Line 574, Address: 0x1029340 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51bscrtbl1[12] = { /* Line 579, Address: 0x1029358 */
    1, 1, 1, 1, 1, 1, 1, 2, 1, 0, 0, 6
  };


  lHwk = scra_h_posit.w.h - scrc_h_posit.w.h; /* Line 584, Address: 0x102938c */
  lHwk = (unsigned int)lHwk * 64 / 12; /* Line 585, Address: 0x10293b0 */
  lHwk *= 1024; /* Line 586, Address: 0x10293cc */

  ldHposwk.l = 0; /* Line 588, Address: 0x10293d0 */
  ldHposwk.w.l = scrc_h_posit.w.h; /* Line 589, Address: 0x10293d4 */

  for (i = 11; i >= 0; --i) { /* Line 591, Address: 0x10293e0 */

    wk = -ldHposwk.w.l; /* Line 593, Address: 0x10293ec */

    for (j = z51bscrtbl1[i]; j >= 0; --j) { /* Line 595, Address: 0x102940c */

      **ppHscw = wk; /* Line 597, Address: 0x1029424 */
      ++*ppHscw; /* Line 598, Address: 0x1029430 */
    } /* Line 599, Address: 0x1029444 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 601, Address: 0x1029450 */
    ldHposwk.l += lHwk; /* Line 602, Address: 0x1029474 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 603, Address: 0x1029480 */
  } /* Line 604, Address: 0x10294a4 */
} /* Line 605, Address: 0x10294b0 */













static void z51bline2(short** ppHscw) { /* Line 619, Address: 0x10294d0 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51bscrtbl2[4] = { /* Line 624, Address: 0x10294e8 */
    3, 1, 1, 4
  };

  lHwk = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 628, Address: 0x1029514 */
  lHwk = (unsigned int)lHwk * 64 / 8; /* Line 629, Address: 0x1029538 */
  lHwk *= 1024; /* Line 630, Address: 0x1029544 */

  ldHposwk.l = 0; /* Line 632, Address: 0x1029548 */
  ldHposwk.w.l = scrz_h_posit.w.h; /* Line 633, Address: 0x102954c */
  *ppHscw += 13; /* Line 634, Address: 0x1029558 */

  for (i = 3; i >= 0; --i) { /* Line 636, Address: 0x102956c */

    wk = -ldHposwk.w.l; /* Line 638, Address: 0x1029578 */

    for (j = z51bscrtbl2[i]; j >= 0; --j) { /* Line 640, Address: 0x1029598 */

      --*ppHscw; /* Line 642, Address: 0x10295b0 */
      **ppHscw = wk; /* Line 643, Address: 0x10295c4 */
    } /* Line 644, Address: 0x10295d0 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 646, Address: 0x10295dc */
    ldHposwk.l += lHwk; /* Line 647, Address: 0x1029600 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 648, Address: 0x102960c */
  } /* Line 649, Address: 0x1029630 */
  *ppHscw += 13; /* Line 650, Address: 0x102963c */
} /* Line 651, Address: 0x1029650 */













static void z51bline3(short** ppHscw) { /* Line 665, Address: 0x1029670 */
  int lHwk;
  int_union ldHposwk;
  int i, j;
  short wk;
  char z51bscrtbl3[10] = { /* Line 670, Address: 0x1029688 */
    0, 2, 0, 2, 0, 2, 1, 1, 1, 2
  };


  lHwk = scrb_h_posit.w.h - scrc_h_posit.w.h; /* Line 675, Address: 0x10296bc */
  lHwk = (unsigned int)lHwk * 64 / 14; /* Line 676, Address: 0x10296e0 */
  lHwk *= 1024; /* Line 677, Address: 0x10296fc */

  ldHposwk.l = 0; /* Line 679, Address: 0x1029700 */
  ldHposwk.w.l = scrc_h_posit.w.h; /* Line 680, Address: 0x1029704 */

  for (i = 9; i >= 0; --i) { /* Line 682, Address: 0x1029710 */

    wk = -ldHposwk.w.l; /* Line 684, Address: 0x102971c */

    for (j = z51bscrtbl3[i]; j >= 0; --j) { /* Line 686, Address: 0x102973c */

      **ppHscw = wk; /* Line 688, Address: 0x1029754 */
      ++*ppHscw; /* Line 689, Address: 0x1029760 */
    } /* Line 690, Address: 0x1029774 */

    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 692, Address: 0x1029780 */
    ldHposwk.l += lHwk; /* Line 693, Address: 0x10297a4 */
    ldHposwk.l = (unsigned int)ldHposwk.l >> 16 & 65535 | ldHposwk.l << 16 & -65536; /* Line 694, Address: 0x10297b0 */
  } /* Line 695, Address: 0x10297d4 */
} /* Line 696, Address: 0x10297e0 */




















static void zonescrsetsub0(short yoffs, short yline, int_union** pHscrbuf, short* pHscrwk) { /* Line 717, Address: 0x1029800 */
  int i, j;
  int_union ldwk;

  ldwk.l = 0; /* Line 721, Address: 0x102981c */

  for (i = 0, j = yoffs & 7 ; yline >= i; ++i, j = 0) { /* Line 723, Address: 0x1029820 */
    ldwk.w.l = *pHscrwk; /* Line 724, Address: 0x102983c */
    ++pHscrwk; /* Line 725, Address: 0x1029848 */

    for ( ; j < 8; ++j, ++*pHscrbuf) { /* Line 727, Address: 0x1029854 */
      (*pHscrbuf)->l = ldwk.l; /* Line 728, Address: 0x102985c */
    } /* Line 729, Address: 0x102986c */
  } /* Line 730, Address: 0x1029890 */
} /* Line 731, Address: 0x10298b0 */









































































































static void scrollb_v(short yPos) { /* Line 837, Address: 0x10298d0 */
  short ysv, ywk;

  ysv = scrb_v_posit.w.h; /* Line 840, Address: 0x10298e0 */
  scrb_v_posit.w.h = yPos; /* Line 841, Address: 0x10298f0 */
  ywk = (unsigned char)(yPos & 16) ^ scrb_v_count; /* Line 842, Address: 0x10298fc */

  if (!ywk) { /* Line 844, Address: 0x1029934 */
    scrb_v_count ^= 16; /* Line 845, Address: 0x102993c */
    if (yPos - ysv < 0) { /* Line 846, Address: 0x1029950 */
      scrflagb.b.h |= 1; /* Line 847, Address: 0x1029970 */
    } /* Line 848, Address: 0x1029984 */
    else {
      scrflagb.b.h |= 2; /* Line 850, Address: 0x102998c */
    }
  }


} /* Line 855, Address: 0x10299a0 */

















static void scrollb_h(int xoffs, int flgbit) { /* Line 873, Address: 0x10299c0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrb_h_posit.l; /* Line 877, Address: 0x10299d4 */
  lXwk = lXsv + xoffs; /* Line 878, Address: 0x10299dc */
  scrb_h_posit.l = lXwk; /* Line 879, Address: 0x10299e4 */
  ldXwk.l = lXwk; /* Line 880, Address: 0x10299ec */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 881, Address: 0x10299f0 */
  ldXwk.w.l &= 16; /* Line 882, Address: 0x1029a14 */
  ldXwk.b.b4 ^= scrb_h_count; /* Line 883, Address: 0x1029a20 */

  if (!ldXwk.b.b4) { /* Line 885, Address: 0x1029a3c */
    scrb_h_count ^= 16; /* Line 886, Address: 0x1029a48 */
    if (lXwk - lXsv < 0) { /* Line 887, Address: 0x1029a5c */
      scrflagb.b.h |= 1 << flgbit; /* Line 888, Address: 0x1029a68 */
    } /* Line 889, Address: 0x1029a8c */
    else {
      scrflagb.b.h |= 1 << flgbit + 1; /* Line 891, Address: 0x1029a94 */
    }
  }


} /* Line 896, Address: 0x1029abc */

















static void scrollc_h(int xoffs, int flgbit) { /* Line 914, Address: 0x1029ad0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrc_h_posit.l; /* Line 918, Address: 0x1029ae4 */
  lXwk = lXsv + xoffs; /* Line 919, Address: 0x1029aec */
  scrc_h_posit.l = lXwk; /* Line 920, Address: 0x1029af4 */
  ldXwk.l = lXwk; /* Line 921, Address: 0x1029afc */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 922, Address: 0x1029b00 */
  ldXwk.w.l &= 16; /* Line 923, Address: 0x1029b24 */
  ldXwk.b.b4 ^= scrc_h_count; /* Line 924, Address: 0x1029b30 */

  if (!ldXwk.b.b4) { /* Line 926, Address: 0x1029b4c */
    scrc_h_count ^= 16; /* Line 927, Address: 0x1029b58 */
    if (lXwk - lXsv < 0) { /* Line 928, Address: 0x1029b6c */
      scrflagc.b.h |= 1 << flgbit; /* Line 929, Address: 0x1029b78 */
    } /* Line 930, Address: 0x1029b9c */
    else {
      scrflagc.b.h |= 1 << flgbit + 1; /* Line 932, Address: 0x1029ba4 */
    }
  }


} /* Line 937, Address: 0x1029bcc */

















static void scrollz_h(int xoffs, int flgbit) { /* Line 955, Address: 0x1029be0 */
  int lXwk, lXsv;
  int_union ldXwk;

  lXsv = scrz_h_posit.l; /* Line 959, Address: 0x1029bf4 */
  lXwk = lXsv + xoffs; /* Line 960, Address: 0x1029bfc */
  scrz_h_posit.l = lXwk; /* Line 961, Address: 0x1029c04 */
  ldXwk.l = lXwk; /* Line 962, Address: 0x1029c0c */
  ldXwk.l = (unsigned int)ldXwk.l >> 16 & 65535 | ldXwk.l << 16 & -65536; /* Line 963, Address: 0x1029c10 */
  ldXwk.w.l &= 16; /* Line 964, Address: 0x1029c34 */
  ldXwk.b.b4 ^= scrz_h_count; /* Line 965, Address: 0x1029c40 */

  if (!ldXwk.b.b4) { /* Line 967, Address: 0x1029c5c */
    scrz_h_count ^= 16; /* Line 968, Address: 0x1029c68 */
    if (lXwk - lXsv < 0) { /* Line 969, Address: 0x1029c7c */
      scrflagz.b.h |= 1 << flgbit; /* Line 970, Address: 0x1029c88 */
    } /* Line 971, Address: 0x1029cac */
    else {
      scrflagz.b.h |= 1 << flgbit + 1; /* Line 973, Address: 0x1029cb4 */
    }
  }


} /* Line 978, Address: 0x1029cdc */














static void scroll_h(void) { /* Line 993, Address: 0x1029cf0 */
  short xwk;
  unsigned char bXwk;

  xwk = scra_h_posit.w.h; /* Line 997, Address: 0x1029d00 */

  scrh_move(); /* Line 999, Address: 0x1029d10 */
  bXwk = (unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count; /* Line 1000, Address: 0x1029d18 */
  if (!bXwk) { /* Line 1001, Address: 0x1029d4c */
    scra_h_count ^= 16; /* Line 1002, Address: 0x1029d54 */
    if (scra_h_posit.w.h - xwk < 0) { /* Line 1003, Address: 0x1029d68 */
      scrflaga.b.h |= 4; /* Line 1004, Address: 0x1029d8c */
    } else { /* Line 1005, Address: 0x1029da0 */
      scrflaga.b.h |= 8; /* Line 1006, Address: 0x1029da8 */
    }
  }


} /* Line 1011, Address: 0x1029dbc */
















static void scrh_move(void) { /* Line 1028, Address: 0x1029de0 */
  short xwk;

  xwk = actwk[0].xposi.w.h - scra_h_posit.w.h - scra_hline; /* Line 1031, Address: 0x1029de8 */
  if (xwk == 0) { /* Line 1032, Address: 0x1029e30 */

    scra_hz = 0; /* Line 1034, Address: 0x1029e40 */
    return; /* Line 1035, Address: 0x1029e48 */
  } else if (xwk < 0) { /* Line 1036, Address: 0x1029e50 */

    if (xwk < -16) { /* Line 1038, Address: 0x1029e60 */
      xwk = -16; /* Line 1039, Address: 0x1029e74 */
    }


    xwk += scra_h_posit.w.h; /* Line 1043, Address: 0x1029e80 */
    if (xwk < scralim_left) { /* Line 1044, Address: 0x1029e94 */
      xwk = scralim_left; /* Line 1045, Address: 0x1029eb8 */
    }
  } /* Line 1047, Address: 0x1029ec8 */
  else {
    if (xwk > 16) { /* Line 1049, Address: 0x1029ed0 */
      xwk = 16; /* Line 1050, Address: 0x1029ee4 */
    }


    xwk += scra_h_posit.w.h; /* Line 1054, Address: 0x1029ef0 */
    if (xwk > scralim_right) { /* Line 1055, Address: 0x1029f04 */
      xwk = scralim_right; /* Line 1056, Address: 0x1029f28 */
    }
  }


  scra_hz = (xwk - scra_h_posit.w.h) << 8; /* Line 1061, Address: 0x1029f38 */
  scra_h_posit.w.h = xwk; /* Line 1062, Address: 0x1029f68 */
} /* Line 1063, Address: 0x1029f70 */














static void scroll_v(void) { /* Line 1078, Address: 0x1029f80 */
  short ywk;

  ywk = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 1081, Address: 0x1029f8c */
  if (actwk[0].cddat & 4) { /* Line 1082, Address: 0x1029fc0 */
    ywk -= 5; /* Line 1083, Address: 0x1029fd8 */
  }


  if (actwk[0].cddat & 2) { /* Line 1087, Address: 0x1029fe4 */
    ywk += 32; /* Line 1088, Address: 0x1029ffc */
    if (ywk < scra_vline) { /* Line 1089, Address: 0x102a008 */
      ywk -= scra_vline; /* Line 1090, Address: 0x102a02c */
      sv_move_main2(ywk); /* Line 1091, Address: 0x102a040 */
      return; /* Line 1092, Address: 0x102a04c */
    } else if (ywk >= scra_vline + 64) { /* Line 1093, Address: 0x102a054 */
      ywk -= scra_vline + 64; /* Line 1094, Address: 0x102a07c */
      sv_move_main2(ywk); /* Line 1095, Address: 0x102a0a4 */
      return; /* Line 1096, Address: 0x102a0b0 */
    }
    ywk -= scra_vline + 64; /* Line 1098, Address: 0x102a0b8 */
    if (!limmoveflag) goto label1; /* Line 1099, Address: 0x102a0e0 */
    sv_move_sub2(); /* Line 1100, Address: 0x102a0f0 */
    return; /* Line 1101, Address: 0x102a0f8 */
  }



  if ((ywk -= scra_vline) != 0) { /* Line 1106, Address: 0x102a100 */
    sv_move_main(ywk); /* Line 1107, Address: 0x102a12c */
    return; /* Line 1108, Address: 0x102a138 */
  } else if (!limmoveflag) goto label1; /* Line 1109, Address: 0x102a140 */
  sv_move_sub2(); /* Line 1110, Address: 0x102a150 */
  return; /* Line 1111, Address: 0x102a158 */



label1:
  scra_vz = 0; /* Line 1116, Address: 0x102a160 */
} /* Line 1117, Address: 0x102a168 */













static void sv_move_main(short yPos) { /* Line 1131, Address: 0x102a180 */
  short spdwk;

  if (scra_vline == 96) { /* Line 1134, Address: 0x102a190 */
    if (actwk[0].mspeed.w < 0) { /* Line 1135, Address: 0x102a1ac */
      spdwk = -actwk[0].mspeed.w; /* Line 1136, Address: 0x102a1c4 */
    } else { /* Line 1137, Address: 0x102a1e8 */
      spdwk = actwk[0].mspeed.w; /* Line 1138, Address: 0x102a1f0 */
    }


    if (spdwk >= 2048) { /* Line 1142, Address: 0x102a200 */
      sv_move_main2(yPos); /* Line 1143, Address: 0x102a214 */
    } /* Line 1144, Address: 0x102a220 */
    else {

      if (yPos > 6) { /* Line 1147, Address: 0x102a228 */
        sv_move_plus(1536); /* Line 1148, Address: 0x102a240 */
      } else if (yPos < -6) { /* Line 1149, Address: 0x102a24c */
        sv_move_minus(1536); /* Line 1150, Address: 0x102a26c */
      } /* Line 1151, Address: 0x102a278 */
      else sv_move_sub(yPos); /* Line 1152, Address: 0x102a280 */
    }
  } /* Line 1154, Address: 0x102a28c */
  else {
    if (yPos > 2) { /* Line 1156, Address: 0x102a294 */
      sv_move_plus(512); /* Line 1157, Address: 0x102a2ac */
    } else if (yPos < -2) { /* Line 1158, Address: 0x102a2b8 */
      sv_move_minus(512); /* Line 1159, Address: 0x102a2d8 */
    } /* Line 1160, Address: 0x102a2e4 */
    else sv_move_sub(yPos); /* Line 1161, Address: 0x102a2ec */
  }

} /* Line 1164, Address: 0x102a2f8 */













static void sv_move_main2(short yPos) { /* Line 1178, Address: 0x102a310 */
  short spdwk;

  spdwk = 4096; /* Line 1181, Address: 0x102a320 */

  if (yPos > 16) { /* Line 1183, Address: 0x102a32c */
    sv_move_plus(spdwk); /* Line 1184, Address: 0x102a344 */
  } else if (yPos < -16) { /* Line 1185, Address: 0x102a350 */
    sv_move_minus(spdwk); /* Line 1186, Address: 0x102a370 */
  } else { /* Line 1187, Address: 0x102a37c */
    sv_move_sub(yPos); /* Line 1188, Address: 0x102a384 */
  }
} /* Line 1190, Address: 0x102a390 */














static void sv_move_sub(short yPos) { /* Line 1205, Address: 0x102a3b0 */
  int_union lSpd;

  lSpd.l = 0; /* Line 1208, Address: 0x102a3bc */
  lSpd.w.l = yPos + scra_v_posit.w.h; /* Line 1209, Address: 0x102a3c0 */
  if (yPos < 0) { /* Line 1210, Address: 0x102a3ec */
    scrv_up_ch(lSpd); /* Line 1211, Address: 0x102a400 */
  } else { /* Line 1212, Address: 0x102a40c */
    scrv_down_ch(lSpd); /* Line 1213, Address: 0x102a414 */
  }
} /* Line 1215, Address: 0x102a420 */



static void sv_move_sub2(void) { /* Line 1219, Address: 0x102a430 */
  limmoveflag = 0; /* Line 1220, Address: 0x102a438 */

  sv_move_sub(0); /* Line 1222, Address: 0x102a440 */
} /* Line 1223, Address: 0x102a44c */













static void sv_move_minus(short speed) { /* Line 1237, Address: 0x102a460 */
  int_union lSpd;

  lSpd.l = (-speed << 8) + scra_v_posit.l; /* Line 1240, Address: 0x102a46c */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1241, Address: 0x102a490 */
  scrv_up_ch(lSpd); /* Line 1242, Address: 0x102a4b4 */
} /* Line 1243, Address: 0x102a4c0 */














static void scrv_up_ch(int_union lSpd) { /* Line 1258, Address: 0x102a4d0 */
  if (lSpd.w.l <= scralim_up) { /* Line 1259, Address: 0x102a4dc */
    if (lSpd.w.l > -256) { /* Line 1260, Address: 0x102a504 */

      lSpd.w.l = scralim_up; /* Line 1262, Address: 0x102a51c */
    } else { /* Line 1263, Address: 0x102a528 */
      lSpd.w.l &= 2047; /* Line 1264, Address: 0x102a530 */
      actwk[0].yposi.w.h &= 2047; /* Line 1265, Address: 0x102a53c */
      scra_v_posit.w.h &= 2047; /* Line 1266, Address: 0x102a550 */
      scrb_v_posit.w.h &= 1023; /* Line 1267, Address: 0x102a564 */
    }
  }

  scrv_move(lSpd); /* Line 1271, Address: 0x102a578 */
} /* Line 1272, Address: 0x102a584 */













static void sv_move_plus(short sSpd) { /* Line 1286, Address: 0x102a5a0 */
  int_union lSpd;

  lSpd.l = (sSpd << 8) + scra_v_posit.l; /* Line 1289, Address: 0x102a5ac */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1290, Address: 0x102a5cc */
  scrv_down_ch(lSpd); /* Line 1291, Address: 0x102a5f0 */
} /* Line 1292, Address: 0x102a5fc */














static void scrv_down_ch(int_union lSpd) { /* Line 1307, Address: 0x102a610 */
  if (lSpd.w.l >= scralim_down) { /* Line 1308, Address: 0x102a61c */
    if (lSpd.w.l < 2048) { /* Line 1309, Address: 0x102a644 */

      lSpd.w.l = scralim_down; /* Line 1311, Address: 0x102a65c */
    } else { /* Line 1312, Address: 0x102a668 */
      lSpd.w.l -= 2048; /* Line 1313, Address: 0x102a670 */
      actwk[0].yposi.w.h &= 2047; /* Line 1314, Address: 0x102a67c */
      scra_v_posit.w.h -= 2048; /* Line 1315, Address: 0x102a690 */
      scrb_v_posit.w.h &= 1023; /* Line 1316, Address: 0x102a6a4 */
    }
  }

  scrv_move(lSpd); /* Line 1320, Address: 0x102a6b8 */
} /* Line 1321, Address: 0x102a6c4 */
















static void scrv_move(int_union lSpd) { /* Line 1338, Address: 0x102a6e0 */
  short ywk, ysv;
  uint_union spdwk;

  ysv = scra_v_posit.w.h; /* Line 1342, Address: 0x102a6f0 */
  lSpd.l = (unsigned int)lSpd.l >> 16 & 65535 | lSpd.l << 16 & -65536; /* Line 1343, Address: 0x102a700 */
  spdwk.l = lSpd.l - scra_v_posit.l; /* Line 1344, Address: 0x102a724 */
  spdwk.l = spdwk.l >> 8 | spdwk.l << 24; /* Line 1345, Address: 0x102a738 */
  scra_vz = spdwk.w.l; /* Line 1346, Address: 0x102a750 */

  scra_v_posit.l = lSpd.l; /* Line 1348, Address: 0x102a75c */

  ywk = (unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count; /* Line 1350, Address: 0x102a768 */
  if (!ywk) { /* Line 1351, Address: 0x102a7a4 */
    scra_v_count ^= 16; /* Line 1352, Address: 0x102a7ac */
    ywk = scra_v_posit.w.h - ysv; /* Line 1353, Address: 0x102a7c0 */
    if (ywk < 0) { /* Line 1354, Address: 0x102a7ec */
      scrflaga.b.h |= 1; /* Line 1355, Address: 0x102a7fc */
    } else { /* Line 1356, Address: 0x102a810 */
      scrflaga.b.h |= 2; /* Line 1357, Address: 0x102a818 */
    }
  }


} /* Line 1362, Address: 0x102a82c */

















void scrollwrt(void) { /* Line 1380, Address: 0x102a840 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1389, Address: 0x102a860 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1390, Address: 0x102a864 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1391, Address: 0x102a870 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1392, Address: 0x102a87c */
  pScrFlag = &scrflagbw.b.h; /* Line 1393, Address: 0x102a884 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1394, Address: 0x102a88c */

  VramBase = 16384; /* Line 1396, Address: 0x102a8a0 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1397, Address: 0x102a8a4 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1398, Address: 0x102a8b0 */
  pMapWk = (unsigned char*)mapwka; /* Line 1399, Address: 0x102a8bc */
  pScrFlag = &scrflagaw.b.h; /* Line 1400, Address: 0x102a8c4 */

  if (*pScrFlag) { /* Line 1402, Address: 0x102a8cc */
    if (*pScrFlag & 1) { /* Line 1403, Address: 0x102a8d8 */
      *pScrFlag &= 254; /* Line 1404, Address: 0x102a8ec */

      lD4.l = -16; /* Line 1406, Address: 0x102a8f8 */
      wD5 = 65520; /* Line 1407, Address: 0x102a900 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1409, Address: 0x102a908 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1411, Address: 0x102a928 */
    }




    if (*pScrFlag & 2) { /* Line 1417, Address: 0x102a954 */
      *pScrFlag &= 253; /* Line 1418, Address: 0x102a968 */

      lD4.l = 224; /* Line 1420, Address: 0x102a974 */
      wD5 = 65520; /* Line 1421, Address: 0x102a97c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1422, Address: 0x102a984 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1424, Address: 0x102a9a4 */
    }




    if (*pScrFlag & 4) { /* Line 1430, Address: 0x102a9d0 */
      *pScrFlag &= 251; /* Line 1431, Address: 0x102a9e4 */

      lD4.l = -16; /* Line 1433, Address: 0x102a9f0 */
      wD5 = 65520; /* Line 1434, Address: 0x102a9f8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1435, Address: 0x102aa00 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1437, Address: 0x102aa20 */
    }




    if (*pScrFlag & 8) { /* Line 1443, Address: 0x102aa4c */
      *pScrFlag &= 247; /* Line 1444, Address: 0x102aa60 */

      lD4.l = -16; /* Line 1446, Address: 0x102aa6c */
      wD5 = 320; /* Line 1447, Address: 0x102aa74 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1448, Address: 0x102aa7c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1450, Address: 0x102aa9c */
    }
  }






} /* Line 1459, Address: 0x102aac8 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1476, Address: 0x102aaf0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1487, Address: 0x102ab1c */

  if (*pScrFlag & 1) { /* Line 1489, Address: 0x102ab24 */
    *pScrFlag &= 254; /* Line 1490, Address: 0x102ab3c */
  } /* Line 1491, Address: 0x102ab50 */
  else {
    *pScrFlag &= 254; /* Line 1493, Address: 0x102ab58 */

    if (*pScrFlag & 2) { /* Line 1495, Address: 0x102ab6c */
      *pScrFlag &= 253; /* Line 1496, Address: 0x102ab84 */
      lD4.w.l = 224; /* Line 1497, Address: 0x102ab98 */
    } /* Line 1498, Address: 0x102aba0 */
    else {
      *pScrFlag &= 253; /* Line 1500, Address: 0x102aba8 */
      goto label1; /* Line 1501, Address: 0x102abbc */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1506, Address: 0x102abc4 */
  wD0 &= 127; /* Line 1507, Address: 0x102ac14 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1508, Address: 0x102ac1c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1514, Address: 0x102ac3c */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1515, Address: 0x102ac5c */
  if (wD0 != 0) { /* Line 1516, Address: 0x102ac80 */
    wD5 = 65520; /* Line 1517, Address: 0x102ac8c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1518, Address: 0x102ac94 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1520, Address: 0x102acb4 */



  } /* Line 1524, Address: 0x102ace0 */
  else {

    wD5 = 0; /* Line 1527, Address: 0x102ace8 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1528, Address: 0x102acec */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1532, Address: 0x102ad0c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1539, Address: 0x102ad38 */






    lD4.l = -16; /* Line 1546, Address: 0x102ad4c */
    wD5 = 65520; /* Line 1547, Address: 0x102ad54 */
    if (*pScrFlag & 168) { /* Line 1548, Address: 0x102ad5c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1549, Address: 0x102ad74 */
      wD5 = 320; /* Line 1550, Address: 0x102ad94 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1554, Address: 0x102ad9c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1556, Address: 0x102adcc */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1557, Address: 0x102add8 */



    for (i = 0; i < 16; ++i) { /* Line 1561, Address: 0x102ade8 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1562, Address: 0x102adf4 */

      if (wD0 != 0 && *pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1564, Address: 0x102ae14 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1565, Address: 0x102ae4c */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1566, Address: 0x102ae6c */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1568, Address: 0x102ae90 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1571, Address: 0x102aeb4 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1573, Address: 0x102aed4 */
      }
      lD4.w.l += 16; /* Line 1575, Address: 0x102aee8 */
    } /* Line 1576, Address: 0x102aef4 */
    *pScrFlag = 0; /* Line 1577, Address: 0x102af04 */
  }
} /* Line 1579, Address: 0x102af0c */





void scrollwrtc(void) {} /* Line 1585, Address: 0x102af40 */




void scrollwrtz(void) {} /* Line 1590, Address: 0x102af50 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1608, Address: 0x102af60 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1621, Address: 0x102af88 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1624, Address: 0x102afa8 */
    pTilePoint->x += 2; /* Line 1625, Address: 0x102afbc */
    if (pTilePoint->x >= 64) { /* Line 1626, Address: 0x102afd0 */
      pTilePoint->x -= 64; /* Line 1627, Address: 0x102afe4 */
    }
    xOffs += 16; /* Line 1629, Address: 0x102aff8 */
  } while (--lpcnt >= 0); /* Line 1630, Address: 0x102b004 */
} /* Line 1631, Address: 0x102b018 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1635, Address: 0x102b030 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1639, Address: 0x102b058 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1642, Address: 0x102b078 */
    pTilePoint->x += 2; /* Line 1643, Address: 0x102b08c */
    if (pTilePoint->x >= 64) { /* Line 1644, Address: 0x102b0a0 */
      pTilePoint->x -= 64; /* Line 1645, Address: 0x102b0b4 */
    }
    xOffs += 16; /* Line 1647, Address: 0x102b0c8 */
  } while (--lpcnt >= 0); /* Line 1648, Address: 0x102b0d4 */
} /* Line 1649, Address: 0x102b0e8 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1669, Address: 0x102b100 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1673, Address: 0x102b128 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1676, Address: 0x102b148 */
    pTilePoint->y += 2; /* Line 1677, Address: 0x102b15c */
    if (pTilePoint->y >= 32) { /* Line 1678, Address: 0x102b16c */
      pTilePoint->y -= 32; /* Line 1679, Address: 0x102b180 */
    }
    yOffs += 16; /* Line 1681, Address: 0x102b190 */
  } while (--lpcnt >= 0); /* Line 1682, Address: 0x102b19c */
} /* Line 1683, Address: 0x102b1b0 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1702, Address: 0x102b1c0 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1708, Address: 0x102b1f4 */

    base = 1; /* Line 1710, Address: 0x102b204 */
  } /* Line 1711, Address: 0x102b208 */
  else if (VramBase == 16384) { /* Line 1712, Address: 0x102b210 */

    base = 0; /* Line 1714, Address: 0x102b220 */
  }
  x = pTilePoint->x; /* Line 1716, Address: 0x102b224 */
  y = pTilePoint->y; /* Line 1717, Address: 0x102b22c */


  frip = BlkIndex & 6144; /* Line 1720, Address: 0x102b234 */
  BlkIndex &= 1023; /* Line 1721, Address: 0x102b23c */
  if (frip == 6144) { /* Line 1722, Address: 0x102b248 */

    p0 = 3, p1 = 2; /* Line 1724, Address: 0x102b254 */
    p2 = 1, p3 = 0; /* Line 1725, Address: 0x102b25c */
  } /* Line 1726, Address: 0x102b264 */
  else if (frip & 4096) { /* Line 1727, Address: 0x102b26c */

    p0 = 2, p1 = 3; /* Line 1729, Address: 0x102b278 */
    p2 = 0, p3 = 1; /* Line 1730, Address: 0x102b280 */
  } /* Line 1731, Address: 0x102b288 */
  else if (frip & 2048) { /* Line 1732, Address: 0x102b290 */

    p0 = 1, p1 = 0; /* Line 1734, Address: 0x102b29c */
    p2 = 3, p3 = 2; /* Line 1735, Address: 0x102b2a4 */
  } /* Line 1736, Address: 0x102b2ac */
  else {

    p0 = 0, p1 = 1; /* Line 1739, Address: 0x102b2b4 */
    p2 = 2, p3 = 3; /* Line 1740, Address: 0x102b2bc */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1743, Address: 0x102b2c4 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1744, Address: 0x102b308 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1745, Address: 0x102b34c */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1746, Address: 0x102b390 */

} /* Line 1748, Address: 0x102b3d4 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1766, Address: 0x102b410 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1767, Address: 0x102b430 */
} /* Line 1768, Address: 0x102b450 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1770, Address: 0x102b460 */
  wH_posiw = 0; /* Line 1771, Address: 0x102b480 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1772, Address: 0x102b484 */
} /* Line 1773, Address: 0x102b4a4 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1780, Address: 0x102b4c0 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1786, Address: 0x102b4f0 */
  yOffs += wV_posiw; /* Line 1787, Address: 0x102b500 */





  if ((short)xOffs < 0) /* Line 1793, Address: 0x102b510 */
    xOffs = 0; /* Line 1794, Address: 0x102b52c */
  if ((short)yOffs < 0) /* Line 1795, Address: 0x102b530 */
    yOffs = 0; /* Line 1796, Address: 0x102b54c */
  if ((short)xOffs >= 16384) /* Line 1797, Address: 0x102b550 */
    xOffs = 16383; /* Line 1798, Address: 0x102b570 */
  if ((short)yOffs >= 2048) /* Line 1799, Address: 0x102b578 */
    yOffs = 2047; /* Line 1800, Address: 0x102b598 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1801, Address: 0x102b5a0 */
  if (i < 0) i = 0; /* Line 1802, Address: 0x102b5e8 */

  ScreenNo = pMapWk[i] & 127; /* Line 1804, Address: 0x102b5f4 */

  if (ScreenNo) { /* Line 1806, Address: 0x102b610 */




    xOffs &= 32767; /* Line 1811, Address: 0x102b618 */
    yOffs &= 32767; /* Line 1812, Address: 0x102b624 */


    xBlk = xOffs; /* Line 1815, Address: 0x102b630 */
    xBlk %= 256; /* Line 1816, Address: 0x102b638 */
    xBlk /= 16; /* Line 1817, Address: 0x102b658 */
    yBlk = yOffs; /* Line 1818, Address: 0x102b674 */
    yBlk %= 256; /* Line 1819, Address: 0x102b67c */
    yBlk /= 16; /* Line 1820, Address: 0x102b69c */

    lpw = pmapwk; /* Line 1822, Address: 0x102b6b8 */
    lpw += xBlk; /* Line 1823, Address: 0x102b6c0 */
    lpw += yBlk * 16; /* Line 1824, Address: 0x102b6c8 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1825, Address: 0x102b6d4 */
    *pIndex = *lpw; /* Line 1826, Address: 0x102b6ec */

    return 1; /* Line 1828, Address: 0x102b6fc */
  }

  *pIndex = 0; /* Line 1831, Address: 0x102b708 */
  return 0; /* Line 1832, Address: 0x102b710 */
} /* Line 1833, Address: 0x102b714 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1853, Address: 0x102b740 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1861, Address: 0x102b768 */
  if (ScreenNo) { /* Line 1862, Address: 0x102b7cc */





    xBlk = xOffs; /* Line 1868, Address: 0x102b7d4 */
    xBlk %= 256; /* Line 1869, Address: 0x102b7dc */
    xBlk /= 16; /* Line 1870, Address: 0x102b7fc */
    yBlk = yOffs; /* Line 1871, Address: 0x102b818 */
    yBlk %= 256; /* Line 1872, Address: 0x102b820 */
    yBlk /= 16; /* Line 1873, Address: 0x102b840 */


    lpw = pmapwk; /* Line 1876, Address: 0x102b85c */
    lpw += xBlk; /* Line 1877, Address: 0x102b864 */
    lpw += yBlk * 16; /* Line 1878, Address: 0x102b86c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1879, Address: 0x102b878 */
    *ppBlockNo = lpw; /* Line 1880, Address: 0x102b890 */
    *pIndex = *lpw; /* Line 1881, Address: 0x102b898 */




    return 1; /* Line 1886, Address: 0x102b8a8 */
  }

  *pIndex = 0; /* Line 1889, Address: 0x102b8b4 */
  return 0; /* Line 1890, Address: 0x102b8bc */
} /* Line 1891, Address: 0x102b8c0 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1905, Address: 0x102b8e0 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1912, Address: 0x102b8fc */
  pMapWk = (unsigned char*)mapwka; /* Line 1913, Address: 0x102b900 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1914, Address: 0x102b908 */
    *pBlockIndex = BlockNo; /* Line 1915, Address: 0x102b92c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1916, Address: 0x102b938 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1917, Address: 0x102b950 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1918, Address: 0x102b964 */
    }
  }


} /* Line 1923, Address: 0x102b97c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1937, Address: 0x102b9a0 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1938, Address: 0x102b9ac */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1939, Address: 0x102b9d8 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1940, Address: 0x102ba24 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1941, Address: 0x102ba50 */

          return 0; /* Line 1943, Address: 0x102ba9c */
        }
      }
    }
  }

  return 1; /* Line 1949, Address: 0x102baa8 */
} /* Line 1950, Address: 0x102baac */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1967, Address: 0x102bac0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1968, Address: 0x102badc */

} /* Line 1970, Address: 0x102baf8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1972, Address: 0x102bb10 */
  wH_posiw = 0; /* Line 1973, Address: 0x102bb2c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1974, Address: 0x102bb30 */

} /* Line 1976, Address: 0x102bb4c */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1978, Address: 0x102bb60 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1979, Address: 0x102bb74 */

} /* Line 1981, Address: 0x102bb90 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1983, Address: 0x102bba0 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1984, Address: 0x102bbbc */

} /* Line 1986, Address: 0x102bbd8 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1988, Address: 0x102bbf0 */
  xOffs += wH_posiw; /* Line 1989, Address: 0x102bc08 */
  yOffs += wV_posiw; /* Line 1990, Address: 0x102bc18 */
  yOffs &= 240; /* Line 1991, Address: 0x102bc28 */
  xOffs &= 496; /* Line 1992, Address: 0x102bc34 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1994, Address: 0x102bc40 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1995, Address: 0x102bc6c */


} /* Line 1998, Address: 0x102bc98 */















void mapwrt(void) { /* Line 2014, Address: 0x102bcb0 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 2019, Address: 0x102bcc8 */
  wV_posiw = scra_v_posiw.w.h; /* Line 2020, Address: 0x102bcd4 */
  pMapWk = (unsigned char*)mapwka; /* Line 2021, Address: 0x102bce0 */
  VramBase = 16384; /* Line 2022, Address: 0x102bce8 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 2023, Address: 0x102bcec */
  mapwrtb(); /* Line 2024, Address: 0x102bd04 */
} /* Line 2025, Address: 0x102bd0c */


void mapwrtb(void) { /* Line 2028, Address: 0x102bd30 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scrb_h_posiw.w.h; /* Line 2033, Address: 0x102bd48 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 2034, Address: 0x102bd54 */
  pMapWk = (unsigned char*)mapwkb; /* Line 2035, Address: 0x102bd60 */
  VramBase = 24576; /* Line 2036, Address: 0x102bd68 */
  mapwrt_z81a(pMapWk, VramBase); /* Line 2037, Address: 0x102bd6c */

} /* Line 2039, Address: 0x102bd7c */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 2042, Address: 0x102bda0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 2043, Address: 0x102bdb8 */
} /* Line 2044, Address: 0x102bdd8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 2049, Address: 0x102bdf0 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 2053, Address: 0x102be10 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 2056, Address: 0x102be2c */



    wD4 += 16; /* Line 2060, Address: 0x102be54 */
  } while ((short)--wD6 >= 0); /* Line 2061, Address: 0x102be60 */

} /* Line 2063, Address: 0x102be88 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 2069, Address: 0x102bea0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 2072, Address: 0x102bebc */
  wD6 = 15; /* Line 2073, Address: 0x102bec4 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 1008; /* Line 2076, Address: 0x102becc */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 2078, Address: 0x102bef0 */
    wD4 += 16; /* Line 2079, Address: 0x102bf10 */
  } while ((short)--wD6 >= 0); /* Line 2080, Address: 0x102bf18 */
} /* Line 2081, Address: 0x102bf3c */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 2107, Address: 0x102bf60 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 2112, Address: 0x102bf88 */
  wD0 = pWrttbl[wD0]; /* Line 2113, Address: 0x102bf98 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2115, Address: 0x102bfb4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2116, Address: 0x102bfd8 */
  if (wD0) { /* Line 2117, Address: 0x102c000 */
    wD5 = 65520; /* Line 2118, Address: 0x102c00c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2119, Address: 0x102c014 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2122, Address: 0x102c030 */



  } /* Line 2126, Address: 0x102c058 */
  else {

    wD5 = 0; /* Line 2129, Address: 0x102c060 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2130, Address: 0x102c064 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2134, Address: 0x102c080 */
  }





} /* Line 2141, Address: 0x102c0a8 */










void mapinit(void) { /* Line 2152, Address: 0x102c0d0 */
  short tbl[9] = { /* Line 2153, Address: 0x102c0f0 */
    3584, 8960, -1,
    3584, 8960, -1,
    3584, 8960, -1
  };
  char tbl0[3] = { /* Line 2158, Address: 0x102c11c */
    2, 4, 2
  };
  int EnkeiNo, TileNo, BmpNo, i;
  short *pTbl, poswk;

  EnkeiNo = 0; /* Line 2164, Address: 0x102c140 */
  pTbl = tbl; /* Line 2165, Address: 0x102c144 */

  while ((poswk = *pTbl++) >= 0) { /* Line 2167, Address: 0x102c148 */
    if (actwk[0].xposi.w.h <= poswk) break; /* Line 2168, Address: 0x102c150 */


    ++EnkeiNo; /* Line 2171, Address: 0x102c174 */
  } /* Line 2172, Address: 0x102c178 */


  TileNo = 523; /* Line 2175, Address: 0x102c19c */
  if (EnkeiNo == 0) { /* Line 2176, Address: 0x102c1a0 */
    i = 168; /* Line 2177, Address: 0x102c1a8 */
    BmpNo = 0; /* Line 2178, Address: 0x102c1ac */

    for ( ; i > 0; --i) { /* Line 2180, Address: 0x102c1b0 */
      ChangeTileBmp(TileNo++, BmpNo++); /* Line 2181, Address: 0x102c1b8 */
    } /* Line 2182, Address: 0x102c1d8 */
  }


  colorset2(mapinittbl.colorno2); /* Line 2186, Address: 0x102c1e4 */
  colorset(mapinittbl.colorno2); /* Line 2187, Address: 0x102c1f8 */

  if (plflag) enecginit(); /* Line 2189, Address: 0x102c20c */
  if (play_start & 2) divdevset(); /* Line 2190, Address: 0x102c224 */
} /* Line 2191, Address: 0x102c244 */




void mapset(void) {} /* Line 2196, Address: 0x102c270 */



void divdevset() {} /* Line 2200, Address: 0x102c280 */



void enecginit(void) {} /* Line 2204, Address: 0x102c290 */















static void mapset2(unsigned char* pMapDst, int idx) { /* Line 2220, Address: 0x102c2a0 */
  int h, v, hwk;
  unsigned char *pZonetbl, *pMapwk;

  pZonetbl = zonemaptbl[idx]; /* Line 2224, Address: 0x102c2c0 */
  h = *pZonetbl++; /* Line 2225, Address: 0x102c2d8 */
  v = *pZonetbl++; /* Line 2226, Address: 0x102c2e8 */
  for ( ;v >= 0; --v) { /* Line 2227, Address: 0x102c2f8 */
    pMapwk = pMapDst; /* Line 2228, Address: 0x102c300 */

    for (hwk = h; hwk >= 0; --hwk) { /* Line 2230, Address: 0x102c304 */
      *pMapwk++ = *pZonetbl++; /* Line 2231, Address: 0x102c310 */
    } /* Line 2232, Address: 0x102c328 */

    pMapDst += 64; /* Line 2234, Address: 0x102c334 */
  } /* Line 2235, Address: 0x102c340 */
} /* Line 2236, Address: 0x102c34c */
