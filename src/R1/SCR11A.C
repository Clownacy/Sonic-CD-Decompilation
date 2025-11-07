#include "..\EQU.H"
#include "SCR11A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL1A.H"

static void scr11a_test(void);

static unsigned char z81awrttbl[129] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0
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
extern unsigned char mapwka[8][64];
extern unsigned char mapwkb[8][64];



































































void enecginit(void) {} /* Line 114, Address: 0x1023810 */



void divdevset() {} /* Line 118, Address: 0x1023820 */

























































sprite_status* main_chk(void) {
  if (main_play == 0) { /* Line 177, Address: 0x1023830 */
    return &actwk[0]; /* Line 178, Address: 0x1023844 */
  }
  return &actwk[1]; /* Line 180, Address: 0x1023854 */
} /* Line 181, Address: 0x102385c */












void scr_set(void) { /* Line 194, Address: 0x1023870 */





  unsigned short scr_dir_tbl[6] = { /* Line 200, Address: 0x102387c */
    4, 0, 10391, 0, 1808, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 205, Address: 0x10238b0 */

  i = 0; /* Line 207, Address: 0x10238f8 */
  scrar_no = scr_dir_tbl[i++]; /* Line 208, Address: 0x10238fc */
  scralim_left = scr_dir_tbl[i]; /* Line 209, Address: 0x1023918 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 210, Address: 0x102392c */
  scralim_right = scr_dir_tbl[i]; /* Line 211, Address: 0x1023948 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 212, Address: 0x102395c */
  scralim_up = scr_dir_tbl[i]; /* Line 213, Address: 0x1023978 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 214, Address: 0x102398c */
  scralim_down = scr_dir_tbl[i]; /* Line 215, Address: 0x10239a8 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 216, Address: 0x10239bc */

  scra_h_keep = scralim_left + 576; /* Line 218, Address: 0x10239d8 */
  scra_h_count = 16; /* Line 219, Address: 0x10239fc */
  scra_v_count = 16; /* Line 220, Address: 0x1023a08 */

  scra_vline = scr_dir_tbl[i++]; /* Line 222, Address: 0x1023a14 */
  scra_hline = 160; /* Line 223, Address: 0x1023a30 */

  playposiset(); /* Line 225, Address: 0x1023a3c */
} /* Line 226, Address: 0x1023a44 */











void playposiset(void) { /* Line 238, Address: 0x1023a60 */
  unsigned short playpositbl[2] = { /* Line 239, Address: 0x1023a74 */
    64,
    1899
  };
  unsigned char playmapnotbl[4] = { /* Line 243, Address: 0x1023a90 */
    127,
    127,
    127,
    127
  };
  short xWk, yWk;
  int i;

  if (plflag != 0) { /* Line 252, Address: 0x1023abc */
    playload(); /* Line 253, Address: 0x1023ad0 */
    xWk = actwk[0].xposi.w.h; /* Line 254, Address: 0x1023ad8 */
    yWk = actwk[0].yposi.w.h; /* Line 255, Address: 0x1023ae8 */

    if (yWk < 0) yWk = 0; /* Line 257, Address: 0x1023af8 */

  } /* Line 259, Address: 0x1023b0c */
  else {

    i = 0; /* Line 262, Address: 0x1023b14 */
    xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 263, Address: 0x1023b18 */
    yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 264, Address: 0x1023b3c */
  }


  if ((unsigned short)xWk > 160) { /* Line 268, Address: 0x1023b60 */
    xWk -= 160; /* Line 269, Address: 0x1023b74 */
  } /* Line 270, Address: 0x1023b80 */
  else {
    xWk = 0; /* Line 272, Address: 0x1023b88 */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 276, Address: 0x1023b8c */
    xWk = scralim_right; /* Line 277, Address: 0x1023bb0 */
  }
  scra_h_posit.w.h = xWk; /* Line 279, Address: 0x1023bc0 */

  if ((unsigned short)yWk > 96) { /* Line 281, Address: 0x1023bc8 */
    yWk -= 96; /* Line 282, Address: 0x1023bdc */
  } /* Line 283, Address: 0x1023be8 */
  else {
    yWk = 0; /* Line 285, Address: 0x1023bf0 */
  }

  if (scralim_down < yWk) { /* Line 288, Address: 0x1023bf4 */
    yWk = scralim_down; /* Line 289, Address: 0x1023c18 */
  }

  scra_v_posit.w.h = yWk; /* Line 292, Address: 0x1023c28 */

  scrbinit(xWk, yWk); /* Line 294, Address: 0x1023c30 */

  i = 0; /* Line 296, Address: 0x1023c40 */
  loopmapno = playmapnotbl[i++]; /* Line 297, Address: 0x1023c44 */
  loopmapno2 = playmapnotbl[i++]; /* Line 298, Address: 0x1023c5c */
  ballmapno = playmapnotbl[i++]; /* Line 299, Address: 0x1023c74 */
  ballmapno2 = playmapnotbl[i++]; /* Line 300, Address: 0x1023c8c */


} /* Line 303, Address: 0x1023ca4 */











void scrbinit(short xWk, short yWk) { /* Line 315, Address: 0x1023cc0 */
  int i;


  if ((unsigned short)actwk[0].xposi.w.h >= 2048) { /* Line 319, Address: 0x1023cd0 */
    if ((unsigned short)yWk >= 480) { /* Line 320, Address: 0x1023cec */
      yWk = (yWk - 480) / 2 + 480; /* Line 321, Address: 0x1023d04 */
    }
  }

  scrb_v_posit.w.h = yWk; /* Line 325, Address: 0x1023d3c */
  scrb_v_posit.w.l = 0; /* Line 326, Address: 0x1023d48 */
  scrc_v_posit.w.h = yWk; /* Line 327, Address: 0x1023d50 */
  scrz_v_posit.w.h = yWk; /* Line 328, Address: 0x1023d5c */

  scrb_h_posit.w.h = (unsigned short)(xWk / 2); /* Line 330, Address: 0x1023d68 */
  scrz_h_posit.w.h = (unsigned short)(xWk / 8 * 3); /* Line 331, Address: 0x1023da0 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 16 * 3); /* Line 332, Address: 0x1023de0 */

  for (i = 0; i < 19; ++i) { /* Line 334, Address: 0x1023e20 */
    linework[i] = 0; /* Line 335, Address: 0x1023e2c */
  } /* Line 336, Address: 0x1023e40 */

} /* Line 338, Address: 0x1023e50 */












void scroll(void) { /* Line 351, Address: 0x1023e60 */
  int LineSpdTbl[19] = { /* Line 352, Address: 0x1023e8c */
    65536, 57344, 49152,
    40960, 32768, 24576,
    18432, 16384, 10240,
     8192,  8192, 16384,
    32768, 49152, 65536,
    49152, 32768, 16384,
    8192
  };
  unsigned char z11a_cnttbl[10] = { /* Line 361, Address: 0x1023eb8 */
    3, 5, 5, 3,
    7, 7, 7, 5,
    3, 1
  };
  unsigned char z11a_cnttbl2[9] = { /* Line 366, Address: 0x1023eec */
    1, 3, 9, 3, 15,
    7, 5, 3, 1
  };
  unsigned short lposi_tbl[6] = { /* Line 370, Address: 0x1023f18 */
    640, 224, 1920, 128, 32767, 864
  };
  int HspdWk;
  int* pLinework;
  short* pHScrollWork;
  short wWk;
  int_union* pHScrollBuff;
  short yWk;
  int i, j;
  int Lposi_TblCnt;
  unsigned short wD1, wD4, wD5, wD6;
  int_union lD0, lD2, lD3;

  if (scroll_start.b.h != 0) return; /* Line 384, Address: 0x1023f4c */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 387, Address: 0x1023f64 */
  scrchk(); /* Line 388, Address: 0x1023f90 */
  scroll_h(); /* Line 389, Address: 0x1023f9c */
  scroll_v(); /* Line 390, Address: 0x1023fa8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 392, Address: 0x1023fb4 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 393, Address: 0x1023fc4 */

  if ((actwk[0].actfree[2] & 2) != 0 && scra_hz != 0) { /* Line 395, Address: 0x1023fd4 */
    HspdWk = actwk[0].xspeed.w << 8; /* Line 396, Address: 0x1024004 */
  } /* Line 397, Address: 0x102401c */
  else {
    HspdWk = 0; /* Line 399, Address: 0x1024024 */
  }

  scrollz_h((scra_hz << 5) + HspdWk, 64); /* Line 402, Address: 0x1024028 */
  scrollc_h((long int)(scra_hz << 4) * 3 + (long int)HspdWk * 2, 16); /* Line 403, Address: 0x1024054 */
  scrollb_h((scra_hz << 7) + HspdWk, 4); /* Line 404, Address: 0x10240a4 */

  yWk = scra_v_posit.w.h; /* Line 406, Address: 0x10240d0 */
  if ((unsigned short)actwk[0].xposi.w.h >= 2048) { /* Line 407, Address: 0x10240dc */
    if ((unsigned short)yWk >= 480) { /* Line 408, Address: 0x10240f8 */
      yWk = (yWk - 480) / 2 + 480; /* Line 409, Address: 0x1024110 */
    }
  }

  scrollb_v(yWk); /* Line 413, Address: 0x1024148 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 414, Address: 0x102415c */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 415, Address: 0x102416c */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 416, Address: 0x102417c */

  scrflagb.b.h |= scrflagz.b.h; /* Line 418, Address: 0x102418c */
  scrflagb.b.h |= scrflagc.b.h; /* Line 419, Address: 0x10241a8 */
  scrflagz.b.h = 0; /* Line 420, Address: 0x10241c4 */
  scrflagc.b.h = 0; /* Line 421, Address: 0x10241cc */


  for (i = 0; i < 19; ++i) { /* Line 424, Address: 0x10241d4 */
    linework[i] += LineSpdTbl[i]; /* Line 425, Address: 0x10241e0 */
  } /* Line 426, Address: 0x1024208 */

  lD0.w.h = (unsigned short)-scra_h_posit.w.h; /* Line 428, Address: 0x1024218 */

  pHScrollWork = hscrollwork; /* Line 430, Address: 0x102423c */
  pLinework = linework; /* Line 431, Address: 0x1024248 */


  for (i = 0; i < 10; ++i) { /* Line 434, Address: 0x1024254 */

    wWk = (((unsigned int)(*pLinework++ & -65536) >> 16) + scrz_h_posit.w.h) * -1; /* Line 436, Address: 0x1024260 */


    for (j = 0; z11a_cnttbl[i] >= j; ++j) { /* Line 439, Address: 0x10242a4 */
      *pHScrollWork++ = wWk; /* Line 440, Address: 0x10242b0 */
    } /* Line 441, Address: 0x10242c4 */
  } /* Line 442, Address: 0x10242e0 */



  for (i = 0; i < 20; ++i) { /* Line 446, Address: 0x10242f0 */
    *pHScrollWork++ = -scrc_h_posit.w.h; /* Line 447, Address: 0x10242fc */
  } /* Line 448, Address: 0x1024328 */



  for (i = 0; i < 4; ++i) { /* Line 452, Address: 0x1024338 */
    *pHScrollWork++ = -scrb_h_posit.w.h; /* Line 453, Address: 0x1024344 */
  } /* Line 454, Address: 0x1024370 */



  for (i = 0; i < 56; ++i) { /* Line 458, Address: 0x1024380 */
    *pHScrollWork++ = -scrb_h_posit.w.h; /* Line 459, Address: 0x102438c */
  } /* Line 460, Address: 0x10243b8 */



  for (i = 0; i < 4; ++i) { /* Line 464, Address: 0x10243c8 */
    *pHScrollWork++ = -scrb_h_posit.w.h; /* Line 465, Address: 0x10243d4 */
  } /* Line 466, Address: 0x1024400 */



  for (i = 0; i < 20; ++i) { /* Line 470, Address: 0x1024410 */
    *pHScrollWork++ = -scrc_h_posit.w.h; /* Line 471, Address: 0x102441c */
  } /* Line 472, Address: 0x1024448 */



  for (i = 0; i < 9; ++i) { /* Line 476, Address: 0x1024458 */
    wWk = (((unsigned int)(*pLinework++ & -65536) >> 16) + scrz_h_posit.w.h) * -1; /* Line 477, Address: 0x1024464 */

    for (j = 0; z11a_cnttbl2[i] >= j; ++j) { /* Line 479, Address: 0x10244a8 */
      *pHScrollWork++ = wWk; /* Line 480, Address: 0x10244b4 */
    } /* Line 481, Address: 0x10244c4 */
  } /* Line 482, Address: 0x10244e0 */



  for (i = 0; i < 20; ++i) { /* Line 486, Address: 0x10244f0 */
    *pHScrollWork++ = -scrc_h_posit.w.h; /* Line 487, Address: 0x10244fc */
  } /* Line 488, Address: 0x1024524 */



  for (i = 0; i < 4; ++i) { /* Line 492, Address: 0x1024534 */
    *pHScrollWork++ = -scrb_h_posit.w.h; /* Line 493, Address: 0x1024540 */
  } /* Line 494, Address: 0x1024568 */



  for (i = 0; i < 16; ++i) { /* Line 498, Address: 0x1024578 */
    *pHScrollWork++ = -scrb_h_posit.w.h; /* Line 499, Address: 0x1024584 */
  } /* Line 500, Address: 0x10245ac */

  pHScrollBuff = lphscrollbuff; /* Line 502, Address: 0x10245bc */
  pHScrollWork = hscrollwork; /* Line 503, Address: 0x10245c8 */
  Lposi_TblCnt = 0; /* Line 504, Address: 0x10245d0 */
  lD2.w.l = wD4 = scrb_v_posit.w.h; /* Line 505, Address: 0x10245d4 */
  pHScrollWork += (scrb_v_posit.w.h & 2040) / 8; /* Line 506, Address: 0x10245ec */
  wD1 = 29; /* Line 507, Address: 0x102462c */


  if (lposi_tbl[Lposi_TblCnt] > wD4) { /* Line 510, Address: 0x1024634 */



label1:
    lD2.w.l &= 7; /* Line 515, Address: 0x1024654 */
    wD4 -= lD2.w.l; /* Line 516, Address: 0x1024660 */
    wD4 += 8; /* Line 517, Address: 0x1024670 */
    lD0.w.l = *pHScrollWork++; /* Line 518, Address: 0x1024678 */

    i = 8 - lD2.w.l; /* Line 520, Address: 0x1024688 */
    goto label3; /* Line 521, Address: 0x102469c */

label2:
    do {
      if ((short)wD1 < 0) break; /* Line 525, Address: 0x10246a4 */


      if (lposi_tbl[Lposi_TblCnt] <= wD4) goto label4; /* Line 528, Address: 0x10246bc */


      wD4 += 8; /* Line 531, Address: 0x10246dc */
      lD0.l = *pHScrollWork++; /* Line 532, Address: 0x10246e4 */

      i = 8; /* Line 534, Address: 0x10246fc */
label3:
      for ( ; i > 0; --i) { /* Line 536, Address: 0x1024704 */
        pHScrollBuff->l = lD0.l; /* Line 537, Address: 0x102470c */
        ++pHScrollBuff; /* Line 538, Address: 0x1024714 */
      } /* Line 539, Address: 0x1024718 */
    } while ((short)--wD1 >= 0); /* Line 540, Address: 0x1024728 */




      return; /* Line 545, Address: 0x102474c */
  }

label4:
  wD5 = wD4 - lposi_tbl[Lposi_TblCnt]; /* Line 549, Address: 0x1024754 */
  wD6 = lposi_tbl[Lposi_TblCnt + 1]; /* Line 550, Address: 0x1024774 */
  if (wD5 > wD6) { /* Line 551, Address: 0x1024788 */
    wD6 -= wD5; /* Line 552, Address: 0x102479c */
  } /* Line 553, Address: 0x10247a4 */
  else {
    if (wD5 == wD6) { /* Line 555, Address: 0x10247ac */
      wD6 -= wD5; /* Line 556, Address: 0x10247bc */
    } /* Line 557, Address: 0x10247c4 */
    else {
      wD6 -= wD5; /* Line 559, Address: 0x10247cc */


      lD2.l = (short)(scra_h_posit.w.h - scrb_h_posit.w.h); /* Line 562, Address: 0x10247d4 */
      lD2.l = lD2.l << 8; /* Line 563, Address: 0x102480c */

      lD2.w.l = (unsigned short)(lD2.l / 224); /* Line 565, Address: 0x1024818 */
      lD2.l = lD2.w.l; /* Line 566, Address: 0x1024844 */
      lD2.l = lD2.l << 8; /* Line 567, Address: 0x1024854 */

      lD3.l = 0; /* Line 569, Address: 0x1024860 */
      lD3.w.l = scrb_h_posit.w.h; /* Line 570, Address: 0x1024864 */
      if ((short)--wD5 >= 0) { /* Line 571, Address: 0x1024870 */




        do {
          lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 577, Address: 0x1024894 */
          lD3.l += lD2.l; /* Line 578, Address: 0x10248b8 */
          lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 579, Address: 0x10248c8 */
        } while ((short)--wD5 >= 0); /* Line 580, Address: 0x10248ec */
      }


      wD5 = wD6; /* Line 584, Address: 0x1024910 */
      wD5 >>= 3; /* Line 585, Address: 0x1024914 */
      if (wD5 > wD1) { /* Line 586, Address: 0x102491c */

        wD1 -= wD5; /* Line 588, Address: 0x1024930 */
        wD5 = -(short)wD1; /* Line 589, Address: 0x102493c */
        wD5 <<= 3; /* Line 590, Address: 0x1024958 */
        wD6 -= wD5; /* Line 591, Address: 0x1024960 */
        if (wD6 == 0) goto label5; /* Line 592, Address: 0x1024968 */


      } /* Line 595, Address: 0x1024974 */
      else {
        wD1 -= wD5; /* Line 597, Address: 0x102497c */
      }

      --wD6; /* Line 600, Address: 0x1024988 */

      do {
        pHScrollBuff->w.h = 0; /* Line 603, Address: 0x1024990 */
        pHScrollBuff->w.l = (unsigned short)-lD3.w.l; /* Line 604, Address: 0x1024994 */
        ++pHScrollBuff; /* Line 605, Address: 0x10249b4 */
        lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 606, Address: 0x10249bc */
        lD3.l += lD2.l; /* Line 607, Address: 0x10249e0 */
        lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 608, Address: 0x10249f0 */
        ++wD4; /* Line 609, Address: 0x1024a14 */
        if ((wD4 & 7) == 0) { /* Line 610, Address: 0x1024a1c */
          ++pHScrollWork; /* Line 611, Address: 0x1024a2c */
        }

      } while ((short)--wD6 >= 0); /* Line 614, Address: 0x1024a34 */
    }
label5:
    Lposi_TblCnt += 2; /* Line 617, Address: 0x1024a58 */
    goto label2; /* Line 618, Address: 0x1024a5c */
  }


  Lposi_TblCnt += 2; /* Line 622, Address: 0x1024a64 */
  lD2.w.l = wD4; /* Line 623, Address: 0x1024a68 */
  goto label1; /* Line 624, Address: 0x1024a6c */

} /* Line 626, Address: 0x1024a74 */










void scroll_h(void) { /* Line 637, Address: 0x1024ab0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 640, Address: 0x1024abc */
  scrh_move(); /* Line 641, Address: 0x1024ac8 */
  if ((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) { /* Line 642, Address: 0x1024ad0 */
    scra_h_count ^= 16; /* Line 643, Address: 0x1024b04 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 644, Address: 0x1024b18 */
      scrflaga.b.h |= 4; /* Line 645, Address: 0x1024b44 */
    } /* Line 646, Address: 0x1024b58 */
    else {

      scrflaga.b.h |= 8; /* Line 649, Address: 0x1024b60 */
    }
  }


} /* Line 654, Address: 0x1024b74 */

void scrh_move(void) { /* Line 656, Address: 0x1024b90 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 659, Address: 0x1024b9c */
  wD0 -= scra_h_posit.w.h; /* Line 660, Address: 0x1024ba8 */
  wD0 -= scra_hline; /* Line 661, Address: 0x1024bbc */
  if (wD0 == 0) { /* Line 662, Address: 0x1024bd0 */

    scra_hz = 0; /* Line 664, Address: 0x1024bdc */
  } /* Line 665, Address: 0x1024be4 */
  else if ((short)wD0 < 0) { /* Line 666, Address: 0x1024bec */
    left_check(wD0); /* Line 667, Address: 0x1024c04 */
  } /* Line 668, Address: 0x1024c10 */
  else {
    right_check(wD0); /* Line 670, Address: 0x1024c18 */
  }

} /* Line 673, Address: 0x1024c24 */


void right_check(unsigned short wD0) { /* Line 676, Address: 0x1024c40 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 679, Address: 0x1024c4c */
    wD0 = 16; /* Line 680, Address: 0x1024c6c */
  }

  wD0 += scra_h_posit.w.h; /* Line 683, Address: 0x1024c74 */
  if (scralim_right < (short)wD0) { /* Line 684, Address: 0x1024c8c */
    wD0 = scralim_right; /* Line 685, Address: 0x1024cbc */
  }

  wD1 = wD0; /* Line 688, Address: 0x1024cc8 */
  wD1 -= scra_h_posit.w.h; /* Line 689, Address: 0x1024cd0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 690, Address: 0x1024ce4 */
  scra_h_posit.w.h = wD0; /* Line 691, Address: 0x1024d14 */
  scra_hz = wD1; /* Line 692, Address: 0x1024d20 */

} /* Line 694, Address: 0x1024d28 */


void left_check(unsigned short wD0) { /* Line 697, Address: 0x1024d40 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 700, Address: 0x1024d4c */
    wD0 = 65520; /* Line 701, Address: 0x1024d6c */
  }

  wD0 += scra_h_posit.w.h; /* Line 704, Address: 0x1024d74 */
  if (scralim_left > (short)wD0) { /* Line 705, Address: 0x1024d8c */
    wD0 = scralim_left; /* Line 706, Address: 0x1024dbc */
  }

  wD1 = wD0; /* Line 709, Address: 0x1024dc8 */
  wD1 -= scra_h_posit.w.h; /* Line 710, Address: 0x1024dd0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 711, Address: 0x1024de4 */
  scra_h_posit.w.h = wD0; /* Line 712, Address: 0x1024e14 */
  scra_hz = wD1; /* Line 713, Address: 0x1024e20 */

} /* Line 715, Address: 0x1024e28 */


















void scroll_v(void) { /* Line 734, Address: 0x1024e40 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 737, Address: 0x1024e4c */
  if (actwk[0].cddat & 4) { /* Line 738, Address: 0x1024e78 */
    wD0 -= 5; /* Line 739, Address: 0x1024e90 */
  }

  if (actwk[0].cddat & 2) { /* Line 742, Address: 0x1024e98 */
    wD0 += 32; /* Line 743, Address: 0x1024eb0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 744, Address: 0x1024eb8 */
      wD0 -= scra_vline; /* Line 745, Address: 0x1024ed8 */
      sv_move_main2(wD0); /* Line 746, Address: 0x1024eec */
      return; /* Line 747, Address: 0x1024ef8 */
    }
    wD0 -= scra_vline; /* Line 749, Address: 0x1024f00 */
    if (wD0 >= 64) { /* Line 750, Address: 0x1024f14 */
      wD0 -= 64; /* Line 751, Address: 0x1024f24 */
      sv_move_main2(wD0); /* Line 752, Address: 0x1024f2c */
      return; /* Line 753, Address: 0x1024f38 */
    }
    wD0 -= 64; /* Line 755, Address: 0x1024f40 */
    if (limmoveflag == 0) goto label1; /* Line 756, Address: 0x1024f48 */
    sv_move_sub2(); /* Line 757, Address: 0x1024f5c */
    return; /* Line 758, Address: 0x1024f64 */
  }




  wD0 -= scra_vline; /* Line 764, Address: 0x1024f6c */
  if (wD0) { /* Line 765, Address: 0x1024f80 */
    sv_move_main(wD0); /* Line 766, Address: 0x1024f88 */
    return; /* Line 767, Address: 0x1024f94 */
  }
  if (limmoveflag == 0) { /* Line 769, Address: 0x1024f9c */
    sv_move_sub2(); /* Line 770, Address: 0x1024fb0 */
    return; /* Line 771, Address: 0x1024fb8 */
  }


label1:
  scra_vz = 0; /* Line 776, Address: 0x1024fc0 */

} /* Line 778, Address: 0x1024fc8 */





void sv_move_main(unsigned short wD0) { /* Line 784, Address: 0x1024fe0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 787, Address: 0x1024ff0 */
    sv_move_main1(wD0); /* Line 788, Address: 0x102500c */
    return; /* Line 789, Address: 0x1025018 */
  }

  wD1 = actwk[0].mspeed.w; /* Line 792, Address: 0x1025020 */
  if ((short)wD1 < 0) { /* Line 793, Address: 0x102502c */
    wD1 = -(short)wD1; /* Line 794, Address: 0x1025044 */
  }

  if (wD1 >= 2048) { /* Line 797, Address: 0x1025060 */
    sv_move_main2(wD0); /* Line 798, Address: 0x1025070 */
    return; /* Line 799, Address: 0x102507c */
  }
  if ((short)wD0 > 6) { /* Line 801, Address: 0x1025084 */
    sv_move_plus(1536); /* Line 802, Address: 0x10250a4 */
  } /* Line 803, Address: 0x10250b0 */
  else if ((short)wD0 < -6) { /* Line 804, Address: 0x10250b8 */
    sv_move_minus(1536); /* Line 805, Address: 0x10250d8 */
  } /* Line 806, Address: 0x10250e4 */
  else {
    sv_move_sub(wD0); /* Line 808, Address: 0x10250ec */
  }


} /* Line 812, Address: 0x10250f8 */



void sv_move_main1(unsigned short wD0) { /* Line 816, Address: 0x1025110 */

  if ((short)wD0 > 2) { /* Line 818, Address: 0x102511c */
    sv_move_plus(512); /* Line 819, Address: 0x102513c */
  } /* Line 820, Address: 0x1025148 */
  else if ((short)wD0 < -2) { /* Line 821, Address: 0x1025150 */
    sv_move_minus(512); /* Line 822, Address: 0x1025170 */
  } /* Line 823, Address: 0x102517c */
  else {
    sv_move_sub(wD0); /* Line 825, Address: 0x1025184 */
  }

} /* Line 828, Address: 0x1025190 */


void sv_move_main2(unsigned short wD0) { /* Line 831, Address: 0x10251a0 */

  if ((short)wD0 > 16) { /* Line 833, Address: 0x10251ac */
    sv_move_plus(4096); /* Line 834, Address: 0x10251cc */
  } /* Line 835, Address: 0x10251d8 */
  else if ((short)wD0 < -16) { /* Line 836, Address: 0x10251e0 */
    sv_move_minus(4096); /* Line 837, Address: 0x1025200 */
  } /* Line 838, Address: 0x102520c */
  else {
    sv_move_sub(wD0); /* Line 840, Address: 0x1025214 */
  }

} /* Line 843, Address: 0x1025220 */


void sv_move_sub2(void) { /* Line 846, Address: 0x1025230 */
  limmoveflag = 0; /* Line 847, Address: 0x1025238 */
  sv_move_sub(0); /* Line 848, Address: 0x1025240 */
} /* Line 849, Address: 0x102524c */


void sv_move_sub(unsigned short wD0) { /* Line 852, Address: 0x1025260 */
  int_union lD1;

  lD1.w.h = 0; /* Line 855, Address: 0x102526c */
  lD1.w.l = wD0; /* Line 856, Address: 0x1025270 */
  lD1.l += scra_v_posit.w.h; /* Line 857, Address: 0x1025278 */
  if ((short)wD0 > 0) { /* Line 858, Address: 0x1025294 */
    scrv_down_ch(lD1); /* Line 859, Address: 0x10252b0 */
  } /* Line 860, Address: 0x10252bc */
  else {
    scrv_up_ch(lD1); /* Line 862, Address: 0x10252c4 */
  }

} /* Line 865, Address: 0x10252d0 */




void sv_move_minus(unsigned short wD1) { /* Line 870, Address: 0x10252e0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 874, Address: 0x10252f0 */
  lD1.l = lD1.l << 8; /* Line 875, Address: 0x102530c */
  lD1.l += scra_v_posit.l; /* Line 876, Address: 0x1025318 */

  wk = lD1.w.h; /* Line 878, Address: 0x102532c */
  lD1.w.h = lD1.w.l; /* Line 879, Address: 0x1025334 */
  lD1.w.l = wk; /* Line 880, Address: 0x102533c */
  scrv_up_ch(lD1); /* Line 881, Address: 0x1025340 */
} /* Line 882, Address: 0x102534c */



void scrv_up_ch(int_union lD1) { /* Line 886, Address: 0x1025360 */
  if (scralim_up >= lD1.w.l) { /* Line 887, Address: 0x102536c */
    if (lD1.w.l < -255) { /* Line 888, Address: 0x1025394 */
      lD1.w.l &= 2047; /* Line 889, Address: 0x10253ac */
      actwk[0].yposi.w.h &= 32767; /* Line 890, Address: 0x10253b8 */
      scra_v_posit.w.h &= 2047; /* Line 891, Address: 0x10253cc */
      scrb_v_posit.w.h &= 1023; /* Line 892, Address: 0x10253e0 */
    } /* Line 893, Address: 0x10253f4 */
    else {

      lD1.w.l = scralim_up; /* Line 896, Address: 0x10253fc */
    }
  }
  scrv_move(lD1); /* Line 899, Address: 0x1025408 */

} /* Line 901, Address: 0x1025414 */





void sv_move_plus(unsigned short wD1) { /* Line 907, Address: 0x1025430 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 911, Address: 0x1025440 */
  lD1.w.l = wD1; /* Line 912, Address: 0x1025444 */
  lD1.l = lD1.l << 8; /* Line 913, Address: 0x102544c */
  lD1.l += scra_v_posit.l; /* Line 914, Address: 0x1025458 */

  wk = lD1.w.h; /* Line 916, Address: 0x102546c */
  lD1.w.h = lD1.w.l; /* Line 917, Address: 0x1025474 */
  lD1.w.l = wk; /* Line 918, Address: 0x102547c */

  scrv_down_ch(lD1); /* Line 920, Address: 0x1025480 */

} /* Line 922, Address: 0x102548c */



void scrv_down_ch(int_union lD1) { /* Line 926, Address: 0x10254a0 */
  if (scralim_down <= lD1.w.l) { /* Line 927, Address: 0x10254ac */
    lD1.w.l -= 2048; /* Line 928, Address: 0x10254d4 */
    if (lD1.w.l > 0) { /* Line 929, Address: 0x10254e0 */

      actwk[0].yposi.w.h &= 2047; /* Line 931, Address: 0x10254f4 */
      scra_v_posit.w.h -= 2048; /* Line 932, Address: 0x1025508 */
      scrb_v_posit.w.h &= 1023; /* Line 933, Address: 0x102551c */
    } /* Line 934, Address: 0x1025530 */
    else {
      lD1.w.l = scralim_down; /* Line 936, Address: 0x1025538 */
    }
  }
  scrv_move(lD1); /* Line 939, Address: 0x1025544 */

} /* Line 941, Address: 0x1025550 */


void scrv_move(int_union lD1) { /* Line 944, Address: 0x1025560 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 947, Address: 0x1025570 */

  wk = lD1.w.h; /* Line 949, Address: 0x102557c */
  lD1.w.h = lD1.w.l; /* Line 950, Address: 0x1025584 */
  lD1.w.l = wk; /* Line 951, Address: 0x102558c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 953, Address: 0x1025590 */
  scra_v_posit.l = lD1.l; /* Line 954, Address: 0x10255b8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 957, Address: 0x10255c4 */
    scra_v_count ^= 16; /* Line 958, Address: 0x10255f8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 959, Address: 0x102560c */

      scrflaga.b.h |= 2; /* Line 961, Address: 0x1025638 */
    } /* Line 962, Address: 0x102564c */
    else {
      scrflaga.b.h |= 1; /* Line 964, Address: 0x1025654 */
    }
  }


} /* Line 969, Address: 0x1025668 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 973, Address: 0x1025680 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 976, Address: 0x102568c */
  lD0.l += lD4.l; /* Line 977, Address: 0x102569c */
  scrb_h_posit.l = lD0.l; /* Line 978, Address: 0x10256ac */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 980, Address: 0x10256b8 */

    scrb_h_count ^= 16; /* Line 982, Address: 0x10256ec */
    lD0.l -= lD2.l; /* Line 983, Address: 0x1025700 */
    if ((long int)lD0.l < 0) { /* Line 984, Address: 0x1025710 */
      scrflagb.b.h |= 4; /* Line 985, Address: 0x1025724 */
    } /* Line 986, Address: 0x1025738 */
    else {

      scrflagb.b.h |= 8; /* Line 989, Address: 0x1025740 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 994, Address: 0x1025754 */
  lD0.l += lD5.l; /* Line 995, Address: 0x1025764 */
  scrb_h_posit.l = lD0.l; /* Line 996, Address: 0x1025774 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 998, Address: 0x1025780 */

    scrb_v_count ^= 16; /* Line 1000, Address: 0x10257b4 */
    lD0.l -= lD3.l; /* Line 1001, Address: 0x10257c8 */
    if ((long int)lD0.l < 0) { /* Line 1002, Address: 0x10257d8 */
      scrflagb.b.h |= 1; /* Line 1003, Address: 0x10257ec */
    } /* Line 1004, Address: 0x1025800 */
    else {

      scrflagb.b.h |= 2; /* Line 1007, Address: 0x1025808 */
    }
  }


} /* Line 1012, Address: 0x102581c */






void scrollb_v(unsigned short wD0) { /* Line 1019, Address: 0x1025830 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 1022, Address: 0x102583c */
  scrb_v_posit.w.h = wD0; /* Line 1023, Address: 0x1025848 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 1025, Address: 0x1025854 */
    scrb_v_count ^= 16; /* Line 1026, Address: 0x1025880 */
    if ((short)wD3 > (short)wD0) { /* Line 1027, Address: 0x1025894 */
      scrflagb.b.h |= 1; /* Line 1028, Address: 0x10258c4 */
    } /* Line 1029, Address: 0x10258d8 */
    else {

      scrflagb.b.h |= 2; /* Line 1032, Address: 0x10258e0 */
    }
  }


} /* Line 1037, Address: 0x10258f4 */



void scrollb_h(int lD4, int flagb) { /* Line 1041, Address: 0x1025910 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 1045, Address: 0x1025920 */
  lD0.l = lD2.l + lD4; /* Line 1046, Address: 0x102592c */
  scrb_h_posit.l = lD0.l; /* Line 1047, Address: 0x102593c */

  lD1.w.h = lD0.w.l; /* Line 1049, Address: 0x1025948 */
  lD1.w.l = lD0.w.h; /* Line 1050, Address: 0x1025950 */
  lD1.w.l &= 16; /* Line 1051, Address: 0x1025958 */

  bD3 = scrb_h_count; /* Line 1053, Address: 0x1025964 */
  lD1.b.b4 ^= bD3; /* Line 1054, Address: 0x1025970 */
  if (!lD1.b.b4) { /* Line 1055, Address: 0x1025984 */
    scrb_h_count ^= 16; /* Line 1056, Address: 0x1025990 */
    lD0.l -= lD2.l; /* Line 1057, Address: 0x10259a4 */
    if ((long int)lD0.l < 0) { /* Line 1058, Address: 0x10259b4 */
      scrflagb.b.h |= flagb; /* Line 1059, Address: 0x10259c8 */
    } /* Line 1060, Address: 0x10259e4 */
    else {

      scrflagb.b.h |= flagb * 2; /* Line 1063, Address: 0x10259ec */
    }
  }


} /* Line 1068, Address: 0x1025a0c */


void scrollc_h(int lD4, int flagc) { /* Line 1071, Address: 0x1025a20 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 1075, Address: 0x1025a30 */
  lD0.l = lD2.l + lD4; /* Line 1076, Address: 0x1025a3c */
  scrc_h_posit.l = lD0.l; /* Line 1077, Address: 0x1025a4c */

  lD1.w.h = lD0.w.l; /* Line 1079, Address: 0x1025a58 */
  lD1.w.l = lD0.w.h; /* Line 1080, Address: 0x1025a60 */
  lD1.w.l &= 16; /* Line 1081, Address: 0x1025a68 */

  bD3 = scrc_h_count; /* Line 1083, Address: 0x1025a74 */
  lD1.b.b4 ^= bD3; /* Line 1084, Address: 0x1025a80 */
  if (!lD1.b.b4) { /* Line 1085, Address: 0x1025a94 */
    scrc_h_count ^= 16; /* Line 1086, Address: 0x1025aa0 */
    lD0.l -= lD2.l; /* Line 1087, Address: 0x1025ab4 */
    if ((long int)lD0.l < 0) { /* Line 1088, Address: 0x1025ac4 */
      scrflagc.b.h |= flagc; /* Line 1089, Address: 0x1025ad8 */
    } /* Line 1090, Address: 0x1025af4 */
    else {

      scrflagc.b.h |= flagc * 2; /* Line 1093, Address: 0x1025afc */
    }
  }


} /* Line 1098, Address: 0x1025b1c */











void scrollz_h(int lD4, int flagz) { /* Line 1110, Address: 0x1025b30 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 1114, Address: 0x1025b40 */
  lD0.l = lD2.l + lD4; /* Line 1115, Address: 0x1025b4c */
  scrz_h_posit.l = lD0.l; /* Line 1116, Address: 0x1025b5c */

  lD1.w.h = lD0.w.l; /* Line 1118, Address: 0x1025b68 */
  lD1.w.l = lD0.w.h; /* Line 1119, Address: 0x1025b70 */
  lD1.w.l &= 16; /* Line 1120, Address: 0x1025b78 */

  bD3 = scrz_h_count; /* Line 1122, Address: 0x1025b84 */
  lD1.b.b4 ^= bD3; /* Line 1123, Address: 0x1025b90 */
  if (!lD1.b.b4) { /* Line 1124, Address: 0x1025ba4 */
    scrz_h_count ^= 16; /* Line 1125, Address: 0x1025bb0 */
    lD0.l -= lD2.l; /* Line 1126, Address: 0x1025bc4 */
    if ((long int)lD0.l < 0) { /* Line 1127, Address: 0x1025bd4 */
      scrflagz.b.h |= flagz; /* Line 1128, Address: 0x1025be8 */
    } /* Line 1129, Address: 0x1025c04 */
    else {

      scrflagz.b.h |= flagz * 2; /* Line 1132, Address: 0x1025c0c */
    }
  }


} /* Line 1137, Address: 0x1025c2c */













void scrollwrtadva(void) { /* Line 1151, Address: 0x1025c40 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1157, Address: 0x1025c5c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1158, Address: 0x1025c60 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1159, Address: 0x1025c6c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1160, Address: 0x1025c78 */
  pScrFlag = &scrflagb.b.h; /* Line 1161, Address: 0x1025c80 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1162, Address: 0x1025c88 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1164, Address: 0x1025c9c */
  wV_posiw = scrc_v_posit.w.h; /* Line 1165, Address: 0x1025ca8 */
  pScrFlag = &scrflagc.b.h; /* Line 1166, Address: 0x1025cb4 */
  scrollwrtc(); /* Line 1167, Address: 0x1025cbc */

} /* Line 1169, Address: 0x1025cc4 */












void scrollwrt(void) { /* Line 1182, Address: 0x1025cf0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1191, Address: 0x1025d10 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1192, Address: 0x1025d14 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1193, Address: 0x1025d20 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1194, Address: 0x1025d2c */
  pScrFlag = &scrflagbw.b.h; /* Line 1195, Address: 0x1025d34 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1196, Address: 0x1025d3c */

  VramBase = 16384; /* Line 1198, Address: 0x1025d50 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1199, Address: 0x1025d54 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1200, Address: 0x1025d60 */
  pMapWk = (unsigned char*)mapwka; /* Line 1201, Address: 0x1025d6c */
  pScrFlag = &scrflagaw.b.h; /* Line 1202, Address: 0x1025d74 */

  if (*pScrFlag) { /* Line 1204, Address: 0x1025d7c */
    if (*pScrFlag & 1) { /* Line 1205, Address: 0x1025d88 */
      *pScrFlag &= 254; /* Line 1206, Address: 0x1025d9c */

      lD4.l = -16; /* Line 1208, Address: 0x1025da8 */
      wD5 = 65520; /* Line 1209, Address: 0x1025db0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1211, Address: 0x1025db8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1213, Address: 0x1025dd8 */
    }




    if (*pScrFlag & 2) { /* Line 1219, Address: 0x1025e04 */
      *pScrFlag &= 253; /* Line 1220, Address: 0x1025e18 */

      lD4.l = 224; /* Line 1222, Address: 0x1025e24 */
      wD5 = 65520; /* Line 1223, Address: 0x1025e2c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1224, Address: 0x1025e34 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1226, Address: 0x1025e54 */
    }




    if (*pScrFlag & 4) { /* Line 1232, Address: 0x1025e80 */
      *pScrFlag &= 251; /* Line 1233, Address: 0x1025e94 */

      lD4.l = -16; /* Line 1235, Address: 0x1025ea0 */
      wD5 = 65520; /* Line 1236, Address: 0x1025ea8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1237, Address: 0x1025eb0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1239, Address: 0x1025ed0 */
    }




    if (*pScrFlag & 8) { /* Line 1245, Address: 0x1025efc */
      *pScrFlag &= 247; /* Line 1246, Address: 0x1025f10 */

      lD4.l = -16; /* Line 1248, Address: 0x1025f1c */
      wD5 = 320; /* Line 1249, Address: 0x1025f24 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1250, Address: 0x1025f2c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1252, Address: 0x1025f4c */
    }
  }






} /* Line 1261, Address: 0x1025f78 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1278, Address: 0x1025fa0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1289, Address: 0x1025fcc */

  if (*pScrFlag & 1) { /* Line 1291, Address: 0x1025fd4 */
    *pScrFlag &= 254; /* Line 1292, Address: 0x1025fec */
  } /* Line 1293, Address: 0x1026000 */
  else {
    *pScrFlag &= 254; /* Line 1295, Address: 0x1026008 */

    if (*pScrFlag & 2) { /* Line 1297, Address: 0x102601c */
      *pScrFlag &= 253; /* Line 1298, Address: 0x1026034 */
      lD4.w.l = 224; /* Line 1299, Address: 0x1026048 */
    } /* Line 1300, Address: 0x1026050 */
    else {
      *pScrFlag &= 253; /* Line 1302, Address: 0x1026058 */
      goto label1; /* Line 1303, Address: 0x102606c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1308, Address: 0x1026074 */
  wD0 &= 127; /* Line 1309, Address: 0x10260c4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1310, Address: 0x10260cc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1316, Address: 0x10260ec */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1317, Address: 0x102610c */
  if (wD0 != 0) { /* Line 1318, Address: 0x1026130 */
    wD5 = 65520; /* Line 1319, Address: 0x102613c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1320, Address: 0x1026144 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1322, Address: 0x1026164 */



  } /* Line 1326, Address: 0x1026190 */
  else {

    wD5 = 0; /* Line 1329, Address: 0x1026198 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1330, Address: 0x102619c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1334, Address: 0x10261bc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1341, Address: 0x10261e8 */






    lD4.l = -16; /* Line 1348, Address: 0x10261fc */
    wD5 = 65520; /* Line 1349, Address: 0x1026204 */
    if (*pScrFlag & 168) { /* Line 1350, Address: 0x102620c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1351, Address: 0x1026224 */
      wD5 = 320; /* Line 1352, Address: 0x1026244 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1356, Address: 0x102624c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1358, Address: 0x102627c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1359, Address: 0x1026288 */



    for (i = 0; i < 16; ++i) { /* Line 1363, Address: 0x1026298 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1364, Address: 0x10262a4 */
      if (wD0 != 0) { /* Line 1365, Address: 0x10262c4 */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1366, Address: 0x10262d0 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1367, Address: 0x10262fc */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1368, Address: 0x102631c */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1370, Address: 0x1026340 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1373, Address: 0x1026364 */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1375, Address: 0x1026384 */
        }
      }
      lD4.w.l += 16; /* Line 1378, Address: 0x1026398 */
    } /* Line 1379, Address: 0x10263a4 */
    *pScrFlag = 0; /* Line 1380, Address: 0x10263b4 */
  }
} /* Line 1382, Address: 0x10263bc */





void scrollwrtc(void) {} /* Line 1388, Address: 0x10263f0 */




void scrollwrtz(void) {} /* Line 1393, Address: 0x1026400 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1411, Address: 0x1026410 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1424, Address: 0x1026438 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1427, Address: 0x1026458 */
    pTilePoint->x += 2; /* Line 1428, Address: 0x102646c */
    if (pTilePoint->x >= 64) { /* Line 1429, Address: 0x1026480 */
      pTilePoint->x -= 64; /* Line 1430, Address: 0x1026494 */
    }
    xOffs += 16; /* Line 1432, Address: 0x10264a8 */
  } while (--lpcnt >= 0); /* Line 1433, Address: 0x10264b4 */
} /* Line 1434, Address: 0x10264c8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1438, Address: 0x10264e0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1442, Address: 0x1026508 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1445, Address: 0x1026528 */
    pTilePoint->x += 2; /* Line 1446, Address: 0x102653c */
    if (pTilePoint->x >= 64) { /* Line 1447, Address: 0x1026550 */
      pTilePoint->x -= 64; /* Line 1448, Address: 0x1026564 */
    }
    xOffs += 16; /* Line 1450, Address: 0x1026578 */
  } while (--lpcnt >= 0); /* Line 1451, Address: 0x1026584 */
} /* Line 1452, Address: 0x1026598 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1472, Address: 0x10265b0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1476, Address: 0x10265d8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1479, Address: 0x10265f8 */
    pTilePoint->y += 2; /* Line 1480, Address: 0x102660c */
    if (pTilePoint->y >= 32) { /* Line 1481, Address: 0x102661c */
      pTilePoint->y -= 32; /* Line 1482, Address: 0x1026630 */
    }
    yOffs += 16; /* Line 1484, Address: 0x1026640 */
  } while (--lpcnt >= 0); /* Line 1485, Address: 0x102664c */
} /* Line 1486, Address: 0x1026660 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1505, Address: 0x1026670 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1511, Address: 0x10266a4 */

    base = 1; /* Line 1513, Address: 0x10266b4 */
  } /* Line 1514, Address: 0x10266b8 */
  else if (VramBase == 16384) { /* Line 1515, Address: 0x10266c0 */

    base = 0; /* Line 1517, Address: 0x10266d0 */
  }
  x = pTilePoint->x; /* Line 1519, Address: 0x10266d4 */
  y = pTilePoint->y; /* Line 1520, Address: 0x10266dc */


  frip = BlkIndex & 6144; /* Line 1523, Address: 0x10266e4 */
  BlkIndex &= 1023; /* Line 1524, Address: 0x10266ec */
  if (frip == 6144) { /* Line 1525, Address: 0x10266f8 */

    p0 = 3, p1 = 2; /* Line 1527, Address: 0x1026704 */
    p2 = 1, p3 = 0; /* Line 1528, Address: 0x102670c */
  } /* Line 1529, Address: 0x1026714 */
  else if (frip & 4096) { /* Line 1530, Address: 0x102671c */

    p0 = 2, p1 = 3; /* Line 1532, Address: 0x1026728 */
    p2 = 0, p3 = 1; /* Line 1533, Address: 0x1026730 */
  } /* Line 1534, Address: 0x1026738 */
  else if (frip & 2048) { /* Line 1535, Address: 0x1026740 */

    p0 = 1, p1 = 0; /* Line 1537, Address: 0x102674c */
    p2 = 3, p3 = 2; /* Line 1538, Address: 0x1026754 */
  } /* Line 1539, Address: 0x102675c */
  else {

    p0 = 0, p1 = 1; /* Line 1542, Address: 0x1026764 */
    p2 = 2, p3 = 3; /* Line 1543, Address: 0x102676c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1546, Address: 0x1026774 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1547, Address: 0x10267b8 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1548, Address: 0x10267fc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1549, Address: 0x1026840 */

} /* Line 1551, Address: 0x1026884 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1569, Address: 0x10268c0 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1570, Address: 0x10268e0 */
} /* Line 1571, Address: 0x1026900 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1573, Address: 0x1026910 */
  wH_posiw = 0; /* Line 1574, Address: 0x1026930 */
  return mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1575, Address: 0x1026934 */
} /* Line 1576, Address: 0x1026954 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1583, Address: 0x1026970 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1589, Address: 0x10269a0 */
  yOffs += wV_posiw; /* Line 1590, Address: 0x10269b0 */





  if ((short)xOffs < 0) /* Line 1596, Address: 0x10269c0 */
    xOffs = 0; /* Line 1597, Address: 0x10269dc */
  if ((short)yOffs < 0) /* Line 1598, Address: 0x10269e0 */
    yOffs = 0; /* Line 1599, Address: 0x10269fc */
  if ((short)xOffs >= 16384) /* Line 1600, Address: 0x1026a00 */
    xOffs = 16383; /* Line 1601, Address: 0x1026a20 */
  if ((short)yOffs >= 2048) /* Line 1602, Address: 0x1026a28 */
    yOffs = 2047; /* Line 1603, Address: 0x1026a48 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1604, Address: 0x1026a50 */
  if (i < 0) i = 0; /* Line 1605, Address: 0x1026a98 */

  ScreenNo = pMapWk[i]; /* Line 1607, Address: 0x1026aa4 */

  if (ScreenNo) { /* Line 1609, Address: 0x1026ab4 */




    xOffs &= 32767; /* Line 1614, Address: 0x1026abc */
    yOffs &= 32767; /* Line 1615, Address: 0x1026ac8 */


    xBlk = xOffs; /* Line 1618, Address: 0x1026ad4 */
    xBlk %= 256; /* Line 1619, Address: 0x1026adc */
    xBlk /= 16; /* Line 1620, Address: 0x1026afc */
    yBlk = yOffs; /* Line 1621, Address: 0x1026b18 */
    yBlk %= 256; /* Line 1622, Address: 0x1026b20 */
    yBlk /= 16; /* Line 1623, Address: 0x1026b40 */

    lpw = pmapwk; /* Line 1625, Address: 0x1026b5c */
    lpw += xBlk; /* Line 1626, Address: 0x1026b64 */
    lpw += yBlk * 16; /* Line 1627, Address: 0x1026b6c */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1628, Address: 0x1026b78 */
    *pIndex = *lpw; /* Line 1629, Address: 0x1026b90 */

    return 1; /* Line 1631, Address: 0x1026ba0 */
  }

  *pIndex = 0; /* Line 1634, Address: 0x1026bac */
  return 0; /* Line 1635, Address: 0x1026bb4 */
} /* Line 1636, Address: 0x1026bb8 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1656, Address: 0x1026be0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64]; /* Line 1664, Address: 0x1026c08 */
  if (ScreenNo) { /* Line 1665, Address: 0x1026c60 */





    xBlk = xOffs; /* Line 1671, Address: 0x1026c68 */
    xBlk %= 256; /* Line 1672, Address: 0x1026c70 */
    xBlk /= 16; /* Line 1673, Address: 0x1026c90 */
    yBlk = yOffs; /* Line 1674, Address: 0x1026cac */
    yBlk %= 256; /* Line 1675, Address: 0x1026cb4 */
    yBlk /= 16; /* Line 1676, Address: 0x1026cd4 */


    lpw = pmapwk; /* Line 1679, Address: 0x1026cf0 */
    lpw += xBlk; /* Line 1680, Address: 0x1026cf8 */
    lpw += yBlk * 16; /* Line 1681, Address: 0x1026d00 */
    lpw += (ScreenNo - 1 << 4) << 4; /* Line 1682, Address: 0x1026d0c */
    *ppBlockNo = lpw; /* Line 1683, Address: 0x1026d24 */
    *pIndex = *lpw; /* Line 1684, Address: 0x1026d2c */




    return 1; /* Line 1689, Address: 0x1026d3c */
  }

  *pIndex = 0; /* Line 1692, Address: 0x1026d48 */
  return 0; /* Line 1693, Address: 0x1026d50 */
} /* Line 1694, Address: 0x1026d54 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1708, Address: 0x1026d70 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1715, Address: 0x1026d8c */
  pMapWk = (unsigned char*)mapwka; /* Line 1716, Address: 0x1026d90 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1717, Address: 0x1026d98 */
    *pBlockIndex = BlockNo; /* Line 1718, Address: 0x1026dbc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1719, Address: 0x1026dc8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1720, Address: 0x1026de0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1721, Address: 0x1026df4 */
    }
  }


} /* Line 1726, Address: 0x1026e0c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1740, Address: 0x1026e30 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1741, Address: 0x1026e3c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1742, Address: 0x1026e68 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1743, Address: 0x1026eb4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1744, Address: 0x1026ee0 */

          return 0; /* Line 1746, Address: 0x1026f2c */
        }
      }
    }
  }

  return 1; /* Line 1752, Address: 0x1026f38 */
} /* Line 1753, Address: 0x1026f3c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1770, Address: 0x1026f50 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1771, Address: 0x1026f6c */

} /* Line 1773, Address: 0x1026f88 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1775, Address: 0x1026fa0 */
  wH_posiw = 0; /* Line 1776, Address: 0x1026fbc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1777, Address: 0x1026fc0 */

} /* Line 1779, Address: 0x1026fdc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1781, Address: 0x1026ff0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1782, Address: 0x1027004 */

} /* Line 1784, Address: 0x1027020 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1786, Address: 0x1027030 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1787, Address: 0x102704c */

} /* Line 1789, Address: 0x1027068 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1791, Address: 0x1027080 */
  xOffs += wH_posiw; /* Line 1792, Address: 0x1027098 */
  yOffs += wV_posiw; /* Line 1793, Address: 0x10270a8 */
  yOffs &= 240; /* Line 1794, Address: 0x10270b8 */
  xOffs &= 496; /* Line 1795, Address: 0x10270c4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1797, Address: 0x10270d0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1798, Address: 0x10270fc */


} /* Line 1801, Address: 0x1027128 */


static void scr11a_test(void) { /* Line 1804, Address: 0x1027140 */
  sOutputDebugString("?\n"); /* Line 1805, Address: 0x1027148 */
} /* Line 1806, Address: 0x1027160 */














void mapwrt(void) { /* Line 1821, Address: 0x1027170 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1826, Address: 0x1027188 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1827, Address: 0x1027194 */
  pMapWk = (unsigned char*)mapwka; /* Line 1828, Address: 0x10271a0 */
  VramBase = 16384; /* Line 1829, Address: 0x10271a8 */
  scr11a_test(); /* Line 1830, Address: 0x10271ac */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1831, Address: 0x10271b4 */



  pMapWk = (unsigned char*)mapwkb; /* Line 1835, Address: 0x10271cc */
  VramBase = 24576; /* Line 1836, Address: 0x10271d4 */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1837, Address: 0x10271d8 */

} /* Line 1839, Address: 0x10271e8 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1842, Address: 0x1027210 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1843, Address: 0x1027228 */
} /* Line 1844, Address: 0x1027248 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1849, Address: 0x1027260 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1853, Address: 0x1027280 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1856, Address: 0x102729c */



    wD4 += 16; /* Line 1860, Address: 0x10272c4 */
  } while ((short)--wD6 >= 0); /* Line 1861, Address: 0x10272d0 */

} /* Line 1863, Address: 0x10272f8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1869, Address: 0x1027310 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1872, Address: 0x102732c */
  wD6 = 15; /* Line 1873, Address: 0x1027334 */

  do {
    wD0 = scrb_v_posit.w.h + wD4 & 2032; /* Line 1876, Address: 0x102733c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1878, Address: 0x1027360 */
    wD4 += 16; /* Line 1879, Address: 0x1027380 */
  } while ((short)--wD6 >= 0); /* Line 1880, Address: 0x1027388 */
} /* Line 1881, Address: 0x10273ac */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1907, Address: 0x10273d0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1912, Address: 0x10273f8 */
  wD0 = pWrttbl[wD0]; /* Line 1913, Address: 0x1027408 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1915, Address: 0x1027424 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1916, Address: 0x1027448 */
  if (wD0) { /* Line 1917, Address: 0x1027470 */
    wD5 = 65520; /* Line 1918, Address: 0x102747c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1919, Address: 0x1027484 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1922, Address: 0x10274a0 */



  } /* Line 1926, Address: 0x10274c8 */
  else {

    wD5 = 0; /* Line 1929, Address: 0x10274d0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1930, Address: 0x10274d4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1934, Address: 0x10274f0 */
  }





} /* Line 1941, Address: 0x1027518 */




void mapinit(void) { /* Line 1946, Address: 0x1027540 */





  mapset(); /* Line 1952, Address: 0x1027548 */


  colorset2(5); /* Line 1955, Address: 0x1027550 */
  colorset(5); /* Line 1956, Address: 0x102755c */





  if (plflag != 0) { /* Line 1962, Address: 0x1027568 */
    enecginit(); /* Line 1963, Address: 0x102757c */
  }

  if (play_start & 2) { /* Line 1966, Address: 0x1027584 */

    divdevset(); /* Line 1968, Address: 0x102759c */
  }


} /* Line 1972, Address: 0x10275a4 */









void mapset(void) {} /* Line 1982, Address: 0x10275c0 */
