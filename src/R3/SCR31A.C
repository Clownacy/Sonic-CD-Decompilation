#include "..\EQU.H"
#include "SCR31A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "..\SCRCHK.H"
#include "COL3A.H"

static unsigned char z31awrttbl[49] = {
  0, 0, 0, 0, 0, 0, 6, 6, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
  2, 2, 6, 6, 4, 4, 4, 4, 2, 0,
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
extern unsigned char awasintbl[];
extern unsigned char mapwkb[8][64];
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;








































































void enecginit() {} /* Line 111, Address: 0x1025680 */



void divdevset() {} /* Line 115, Address: 0x1025690 */




















































sprite_status* main_chk() {
  if (main_play == 0) { /* Line 169, Address: 0x10256a0 */
    return &actwk[0]; /* Line 170, Address: 0x10256b4 */
  }
  return &actwk[1]; /* Line 172, Address: 0x10256c4 */
} /* Line 173, Address: 0x10256cc */












void scr_set() { /* Line 186, Address: 0x10256e0 */





  unsigned short scr_dir_tbl[6] = { /* Line 192, Address: 0x10256ec */
    4, 0, 11927, 0, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 197, Address: 0x1025720 */

  i = 0; /* Line 199, Address: 0x1025768 */
  scrar_no = scr_dir_tbl[i++]; /* Line 200, Address: 0x102576c */
  scralim_left = scr_dir_tbl[i]; /* Line 201, Address: 0x1025788 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 202, Address: 0x102579c */
  scralim_right = scr_dir_tbl[i]; /* Line 203, Address: 0x10257b8 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 204, Address: 0x10257cc */
  scralim_up = scr_dir_tbl[i]; /* Line 205, Address: 0x10257e8 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 206, Address: 0x10257fc */
  scralim_down = scr_dir_tbl[i]; /* Line 207, Address: 0x1025818 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 208, Address: 0x102582c */

  scra_h_keep = scralim_left + 576; /* Line 210, Address: 0x1025848 */
  scra_h_count = 16; /* Line 211, Address: 0x102586c */
  scra_v_count = 16; /* Line 212, Address: 0x1025878 */

  scra_vline = scr_dir_tbl[i++]; /* Line 214, Address: 0x1025884 */
  scra_hline = 160; /* Line 215, Address: 0x10258a0 */

  playposiset(); /* Line 217, Address: 0x10258ac */
} /* Line 218, Address: 0x10258b4 */











void playposiset() { /* Line 230, Address: 0x10258d0 */
  unsigned short playpositbl[2] = { /* Line 231, Address: 0x10258e8 */
    96,
    1004
  };
  unsigned short endplpositbl[16] = { /* Line 235, Address: 0x1025904 */
      80,  944,
    3744, 1132,
    5968,  189,
    2560, 1580,
    2992,   76,
    5488,  364,
     432, 1836,
    5120,  684
  };
  unsigned char playmapnotbl[4] = { /* Line 245, Address: 0x1025938 */
    127,
    127,
    127,
    127
  };
  short xWk, yWk;
  int i;
  unsigned short* wp;

  if (plflag != 0) { /* Line 255, Address: 0x1025964 */
    playload(); /* Line 256, Address: 0x1025978 */
    xWk = actwk[0].xposi.w.h; /* Line 257, Address: 0x1025980 */
    yWk = actwk[0].yposi.w.h; /* Line 258, Address: 0x1025990 */

    if (yWk < 0) yWk = 0; /* Line 260, Address: 0x10259a0 */

  } /* Line 262, Address: 0x10259b4 */
  else {

    if (demoflag.w < 0) { /* Line 265, Address: 0x10259bc */
      wp = &endplpositbl[((enddemono & 16383) - 1) * 2]; /* Line 266, Address: 0x10259d4 */
    } /* Line 267, Address: 0x10259fc */
    else {

      wp = &playpositbl[demoflag.w * 2]; /* Line 270, Address: 0x1025a04 */
    }

    xWk = actwk[0].xposi.w.h = *wp++; /* Line 273, Address: 0x1025a24 */
    yWk = actwk[0].yposi.w.h = *wp; /* Line 274, Address: 0x1025a40 */
  }


  if ((unsigned short)xWk > 160) { /* Line 278, Address: 0x1025a54 */
    xWk -= 160; /* Line 279, Address: 0x1025a68 */
  } /* Line 280, Address: 0x1025a74 */
  else {
    xWk = 0; /* Line 282, Address: 0x1025a7c */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 286, Address: 0x1025a80 */
    xWk = scralim_right; /* Line 287, Address: 0x1025aa4 */
  }
  scra_h_posit.w.h = xWk; /* Line 289, Address: 0x1025ab4 */

  if ((unsigned short)yWk > 96) { /* Line 291, Address: 0x1025abc */
    yWk -= 96; /* Line 292, Address: 0x1025ad0 */
  } /* Line 293, Address: 0x1025adc */
  else {
    yWk = 0; /* Line 295, Address: 0x1025ae4 */
  }

  if (scralim_down < yWk) { /* Line 298, Address: 0x1025ae8 */
    yWk = scralim_down; /* Line 299, Address: 0x1025b0c */
  }

  scra_v_posit.w.h = yWk; /* Line 302, Address: 0x1025b1c */

  scrbinit(xWk, yWk); /* Line 304, Address: 0x1025b24 */

  i = 0; /* Line 306, Address: 0x1025b34 */
  loopmapno = playmapnotbl[i++]; /* Line 307, Address: 0x1025b38 */
  loopmapno2 = playmapnotbl[i++]; /* Line 308, Address: 0x1025b50 */
  ballmapno = playmapnotbl[i++]; /* Line 309, Address: 0x1025b68 */
  ballmapno2 = playmapnotbl[i++]; /* Line 310, Address: 0x1025b80 */


} /* Line 313, Address: 0x1025b98 */











void scrbinit(short xWk, short yWk) { /* Line 325, Address: 0x1025bc0 */
  int i;
  short wD2;


  yWk = 536; /* Line 330, Address: 0x1025bd4 */
  wD2 = 1312 - scra_v_posit.w.h; /* Line 331, Address: 0x1025bdc */
  if ((unsigned short)scra_v_posit.w.h <= 1312) { /* Line 332, Address: 0x1025c04 */
    yWk -= wD2 / 2; /* Line 333, Address: 0x1025c20 */
    if (yWk < 0) { /* Line 334, Address: 0x1025c54 */
      yWk = 0; /* Line 335, Address: 0x1025c68 */
    }
  }

  scrb_v_posit.w.h = yWk; /* Line 339, Address: 0x1025c6c */
  scrb_v_posit.w.l = 0; /* Line 340, Address: 0x1025c78 */
  scrc_v_posit.w.h = yWk; /* Line 341, Address: 0x1025c80 */
  scrz_v_posit.w.h = yWk; /* Line 342, Address: 0x1025c8c */

  scrz_h_posit.w.h = (unsigned short)(xWk / 16); /* Line 344, Address: 0x1025c98 */
  scrc_h_posit.w.h = (unsigned short)(xWk / 32 * 3); /* Line 345, Address: 0x1025cd0 */
  scrb_h_posit.w.h = (unsigned short)(xWk / 64 * 3); /* Line 346, Address: 0x1025d10 */


  for (i = 0; i < 15; ++i) { /* Line 349, Address: 0x1025d50 */
    ((int*)hscrollwork)[i] = 0; /* Line 350, Address: 0x1025d5c */
  } /* Line 351, Address: 0x1025d70 */

} /* Line 353, Address: 0x1025d80 */












void scroll() { /* Line 366, Address: 0x1025da0 */
  int LineSpdTbl[15] = { /* Line 367, Address: 0x1025dc4 */
    49152, 32768, 24576,
    16384, 12288,  8192,
     4096,  2048,  4096,
     8192, 12288, 16384,
    24576, 32768, 49152
  };
  unsigned char z31a_cnttbl[15] = { /* Line 374, Address: 0x1025df0 */
    1, 3, 1, 1, 1, 1, 1, 1,
    3, 1, 3, 3, 3, 3, 1
  };
  unsigned short z31a_kawatbl[3] = { /* Line 378, Address: 0x1025e1c */
    56, 592, 32767
  };
  unsigned short lposi_tbl[6] = { /* Line 381, Address: 0x1025e40 */
    640, 224, 1920, 128, 32767, 864
  };
  short* pHScrollWork;
  int_union* pHScrollBuff;
  int_union* pHscrWk;
  int i, j;
  unsigned short wD1, wD3, wD4, wD5, wD6;
  int_union lD0, lD2, lD3;

  if (scroll_start.b.h) return; /* Line 391, Address: 0x1025e74 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 394, Address: 0x1025e84 */
  scrchk(); /* Line 395, Address: 0x1025eb0 */
  scroll_h(); /* Line 396, Address: 0x1025ebc */
  scroll_v(); /* Line 397, Address: 0x1025ec8 */

  vscroll.w.h = scra_v_posit.w.h; /* Line 399, Address: 0x1025ed4 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 400, Address: 0x1025ee4 */


  scrollz_h(scra_hz << 4, 64); /* Line 403, Address: 0x1025ef4 */
  scrollc_h((long int)(scra_hz << 3) * 3, 16); /* Line 404, Address: 0x1025f18 */
  scrollb_h((long int)(scra_hz << 2) * 3, 4); /* Line 405, Address: 0x1025f54 */

  lD0.w.l = 536; /* Line 407, Address: 0x1025f90 */
  wD1 = 1312; /* Line 408, Address: 0x1025f98 */
  if ((unsigned short)scra_v_posit.w.h <= wD1) { /* Line 409, Address: 0x1025fa0 */

    wD1 -= scra_v_posit.w.h; /* Line 411, Address: 0x1025fc0 */
    wD1 >>= 1; /* Line 412, Address: 0x1025fd4 */
    lD0.w.l -= wD1; /* Line 413, Address: 0x1025fdc */
    if (lD0.w.l < 0) { /* Line 414, Address: 0x1025ff0 */
      lD0.w.l = 0; /* Line 415, Address: 0x1026004 */
    }
  } /* Line 417, Address: 0x1026008 */
  else {
    wD1 -= scra_v_posit.w.h; /* Line 419, Address: 0x1026010 */
  }

  scrollb_v(lD0.w.l); /* Line 422, Address: 0x1026024 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 423, Address: 0x1026038 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 424, Address: 0x1026048 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 425, Address: 0x1026058 */

  scrflagb.b.h |= scrflagz.b.h; /* Line 427, Address: 0x1026068 */
  scrflagb.b.h |= scrflagc.b.h; /* Line 428, Address: 0x1026084 */
  scrflagz.b.h = 0; /* Line 429, Address: 0x10260a0 */
  scrflagc.b.h = 0; /* Line 430, Address: 0x10260a8 */


  pHscrWk = (int_union*)hscrollwork; /* Line 433, Address: 0x10260b0 */
  for (i = 0; i < 15; ++i) { /* Line 434, Address: 0x10260b8 */
    pHscrWk->l += LineSpdTbl[i]; /* Line 435, Address: 0x10260c4 */
    ++pHscrWk; /* Line 436, Address: 0x10260dc */
  } /* Line 437, Address: 0x10260e0 */
  wD1 = 0; /* Line 438, Address: 0x10260f0 */
  for (i = 0; i < 64; ++i) { /* Line 439, Address: 0x10260f4 */
    lD2.l = ((long int)(int)wD1 << 10) + 32768; /* Line 440, Address: 0x1026100 */
    pHscrWk->l += lD2.l; /* Line 441, Address: 0x1026124 */
    ++pHscrWk; /* Line 442, Address: 0x1026134 */
    ++wD1; /* Line 443, Address: 0x1026138 */
  } /* Line 444, Address: 0x1026140 */






  lD2.l = scra_h_posit.w.h - scrb_h_posit.w.h; /* Line 451, Address: 0x1026150 */
  lD2.l <<= 8; /* Line 452, Address: 0x1026178 */
  lD2.l /= 28; /* Line 453, Address: 0x1026184 */
  lD2.l <<= 10; /* Line 454, Address: 0x10261a4 */

  lD3.l = 0; /* Line 456, Address: 0x10261b0 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 457, Address: 0x10261b4 */

  pHScrollWork = &hscrollwork[165]; /* Line 459, Address: 0x10261c0 */
  for (i = 0; i < 7; ++i) { /* Line 460, Address: 0x10261cc */
    lD0.w.l = -lD3.w.l; /* Line 461, Address: 0x10261d8 */
    --pHScrollWork; /* Line 462, Address: 0x10261f4 */
    *pHScrollWork = lD0.w.l; /* Line 463, Address: 0x1026200 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 464, Address: 0x102620c */
    lD3.l += lD2.l; /* Line 465, Address: 0x1026230 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 466, Address: 0x1026240 */
  } /* Line 467, Address: 0x1026264 */

  pHScrollWork = &hscrollwork[165]; /* Line 469, Address: 0x1026274 */
  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 470, Address: 0x1026280 */

  for (i = 0; i < 3; ++i) { /* Line 472, Address: 0x10262a4 */
    *pHScrollWork++ = lD0.w.l; /* Line 473, Address: 0x10262b0 */
  } /* Line 474, Address: 0x10262c4 */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 476, Address: 0x10262d4 */

  for (i = 0; i < 4; ++i) { /* Line 478, Address: 0x10262f8 */
    *pHScrollWork++ = lD0.w.l; /* Line 479, Address: 0x1026304 */
  } /* Line 480, Address: 0x1026318 */


  pHscrWk = (int_union*)hscrollwork; /* Line 483, Address: 0x1026328 */
  for (i = 14; i >= 0; --i) { /* Line 484, Address: 0x1026334 */
    wD1 = -(pHscrWk->w.h + scrb_h_posit.w.h); /* Line 485, Address: 0x1026340 */
    ++pHscrWk; /* Line 486, Address: 0x102636c */
    for (j = z31a_cnttbl[i]; j >= 0; --j) { /* Line 487, Address: 0x1026370 */
      *pHScrollWork++ = wD1; /* Line 488, Address: 0x1026384 */
    } /* Line 489, Address: 0x1026394 */
  } /* Line 490, Address: 0x10263a0 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 492, Address: 0x10263ac */

  for (i = 0; i < 6; ++i) { /* Line 494, Address: 0x10263d0 */
    *pHScrollWork++ = lD0.w.l; /* Line 495, Address: 0x10263dc */
  } /* Line 496, Address: 0x10263f0 */

  lD0.w.l = (unsigned short)-scrz_h_posit.w.h; /* Line 498, Address: 0x1026400 */

  for (i = 0; i < 4; ++i) { /* Line 500, Address: 0x1026424 */
    *pHScrollWork++ = lD0.w.l; /* Line 501, Address: 0x1026430 */
  } /* Line 502, Address: 0x1026444 */

  lD0.w.l = (unsigned short)-scrc_h_posit.w.h; /* Line 504, Address: 0x1026454 */

  for (i = 0; i < 8; ++i) { /* Line 506, Address: 0x1026478 */
    *pHScrollWork++ = lD0.w.l; /* Line 507, Address: 0x1026484 */
  } /* Line 508, Address: 0x1026498 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 510, Address: 0x10264a8 */

  for (i = 0; i < 4; ++i) { /* Line 512, Address: 0x10264cc */
    *pHScrollWork++ = lD0.w.l; /* Line 513, Address: 0x10264d8 */
  } /* Line 514, Address: 0x10264ec */


  lD2.l = (short)(scra_h_posit.w.h - scrb_h_posit.w.h); /* Line 517, Address: 0x10264fc */
  lD2.l <<= 6; /* Line 518, Address: 0x1026534 */
  lD2.l /= 40; /* Line 519, Address: 0x1026540 */
  lD2.l <<= 10; /* Line 520, Address: 0x1026560 */
  lD3.w.l = scrb_h_posit.w.h; /* Line 521, Address: 0x102656c */

  for (i = 0; i < 10; ++i) { /* Line 523, Address: 0x1026578 */
    *pHScrollWork++ = (unsigned short)-lD3.w.l; /* Line 524, Address: 0x1026584 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 525, Address: 0x10265b0 */
    lD3.l += lD2.l; /* Line 526, Address: 0x10265d4 */
    lD3.l = (unsigned int)lD3.l >> 16 & 65535 | lD3.l << 16 & -65536; /* Line 527, Address: 0x10265e4 */
  } /* Line 528, Address: 0x1026608 */

  lD0.w.l = (unsigned short)-scrb_h_posit.w.h; /* Line 530, Address: 0x1026618 */

  for (i = 0; i < 8; ++i) { /* Line 532, Address: 0x102663c */
    *pHScrollWork++ = lD0.w.l; /* Line 533, Address: 0x1026648 */
  } /* Line 534, Address: 0x102665c */

  pHScrollBuff = lphscrollbuff; /* Line 536, Address: 0x102666c */
  pHScrollWork = &hscrollwork[158]; /* Line 537, Address: 0x1026678 */
  lD0.w.l = scrb_v_posit.w.h; /* Line 538, Address: 0x1026684 */
  lD2.w.l = lD0.w.l; /* Line 539, Address: 0x1026690 */
  wD4 = lD0.w.l; /* Line 540, Address: 0x1026698 */
  lD0.w.l = (unsigned short)((lD0.w.l & 1016) >> 2); /* Line 541, Address: 0x10266a0 */
  wD3 = lD0.w.l >> 1; /* Line 542, Address: 0x10266c4 */
  wD1 = 87; /* Line 543, Address: 0x10266e0 */
  wD5 = 29; /* Line 544, Address: 0x10266ec */
  if (wD3 <= wD1) { /* Line 545, Address: 0x10266f4 */

    wD1 -= wD3; /* Line 547, Address: 0x1026708 */
    if (wD1 >= 27) { /* Line 548, Address: 0x1026710 */
      wD1 = 28; /* Line 549, Address: 0x1026720 */
    }

    wD5 -= wD1; /* Line 552, Address: 0x1026728 */
    pHScrollWork += (unsigned int)lD0.w.l / 2; /* Line 553, Address: 0x1026730 */
    waterdirec.w += 64; /* Line 554, Address: 0x1026754 */

    zonescrsetsub0(&pHScrollBuff, (unsigned short**)&pHScrollWork, z31a_kawatbl, awasintbl, wD1, (unsigned short*)&lD2.w.l, &wD4); /* Line 556, Address: 0x1026768 */


  } /* Line 559, Address: 0x1026794 */
  else {
    wD1 -= wD3; /* Line 561, Address: 0x102679c */
  }



  wD1 = (wD5 << 3) - 1; /* Line 566, Address: 0x10267a4 */
  pHscrWk = (int_union*)&hscrollwork[30]; /* Line 567, Address: 0x10267b8 */
  wD5 = (unsigned char)waterdirec.b.h; /* Line 568, Address: 0x10267c0 */
  wD4 -= (unsigned short)scrb_v_posit.w.h; /* Line 569, Address: 0x10267d4 */

  do {
    lD2.l = pHscrWk->l; /* Line 572, Address: 0x10267ec */
    ++pHscrWk; /* Line 573, Address: 0x10267f4 */
    lD2.l = (unsigned int)lD2.l >> 16 & 65535 | lD2.l << 16 & -65536; /* Line 574, Address: 0x10267f8 */
    lD2.w.l += scrb_h_posit.w.h; /* Line 575, Address: 0x102681c */
    lD2.w.l *= -1; /* Line 576, Address: 0x1026830 */
    lD0.w.l = lD2.w.l; /* Line 577, Address: 0x102683c */
    wD3 = 1472 - scra_v_posit.w.h; /* Line 578, Address: 0x1026844 */
    if (wD3 <= wD4) { /* Line 579, Address: 0x1026864 */
      wD5 &= 127; /* Line 580, Address: 0x102687c */
      wD6 = wD5 << 1; /* Line 581, Address: 0x1026884 */
      wD3 = (short)(char)awasintbl[wD6]; /* Line 582, Address: 0x1026898 */
      wD3 += scra_h_posit.w.h; /* Line 583, Address: 0x10268c4 */
      wD3 = -(short)wD3; /* Line 584, Address: 0x10268d8 */
      lD0.w.h = wD3; /* Line 585, Address: 0x10268f4 */
    }

    pHScrollBuff->l = lD0.l; /* Line 588, Address: 0x10268f8 */
    ++pHScrollBuff; /* Line 589, Address: 0x1026904 */
    ++wD4; /* Line 590, Address: 0x1026910 */
    ++wD5; /* Line 591, Address: 0x102691c */
  } while ((short)--wD1 >= 0); /* Line 592, Address: 0x1026924 */

} /* Line 594, Address: 0x1026948 */




void zonescrsetsub0(int_union** ppA1, unsigned short** ppA2, unsigned short* pA3, unsigned char* pA4, unsigned short wD1, unsigned short* pwD2, unsigned short* pwD4) { /* Line 599, Address: 0x1026980 */
  int_union* pA1;
  unsigned short* pA2;
  unsigned short wD3, wD6;
  int_union lD0;
  int i;

  pA1 = *ppA1; /* Line 606, Address: 0x10269b4 */
  pA2 = *ppA2; /* Line 607, Address: 0x10269bc */

  lD0.w.h = -scra_h_posit.w.h; /* Line 609, Address: 0x10269c4 */
  if (*pA3 <= *pwD4) goto label6; /* Line 610, Address: 0x10269e4 */



label1:
  *pwD2 &= 7; /* Line 615, Address: 0x1026a08 */
  *pwD4 = *pwD4 + 8 - *pwD2; /* Line 616, Address: 0x1026a1c */

  lD0.w.l = *pA2++; /* Line 618, Address: 0x1026a48 */
  i = 8 - *pwD2; /* Line 619, Address: 0x1026a58 */
  goto label4; /* Line 620, Address: 0x1026a6c */

label2:
  if ((short)wD1 < 0) goto label5; /* Line 623, Address: 0x1026a74 */


  if (*pA3 <= *pwD4) goto label7; /* Line 626, Address: 0x1026a90 */



label3:
  lD0.w.l = *pA2++; /* Line 631, Address: 0x1026ab4 */
  *pwD4 += 8; /* Line 632, Address: 0x1026ac4 */


  i = 8; /* Line 635, Address: 0x1026ad8 */
label4:
  for ( ; i > 0; --i) { /* Line 637, Address: 0x1026adc */


    pA1->l = lD0.l; /* Line 640, Address: 0x1026ae4 */
    ++pA1; /* Line 641, Address: 0x1026aec */
  } /* Line 642, Address: 0x1026af0 */
  if ((short)--wD1 >= 0) goto label2; /* Line 643, Address: 0x1026b00 */



label5:
  *ppA1 = pA1; /* Line 648, Address: 0x1026b28 */
  *ppA2 = pA2; /* Line 649, Address: 0x1026b30 */
  return; /* Line 650, Address: 0x1026b38 */


label6:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 654, Address: 0x1026b40 */
  if ((short)wD3 > 0) goto label8; /* Line 655, Address: 0x1026b70 */


  if (*pA3 > *pwD4) goto label1; /* Line 658, Address: 0x1026b88 */


  wD3 = *pA3++ + 24 - *pwD4; /* Line 661, Address: 0x1026bac */
  if ((short)wD3 > 0) goto label8; /* Line 662, Address: 0x1026bdc */
  goto label1; /* Line 663, Address: 0x1026bf4 */






label7:
  wD3 = *pA3++ + 24 - *pwD4; /* Line 671, Address: 0x1026bfc */
  if ((short)wD3 <= 0) goto label3; /* Line 672, Address: 0x1026c2c */



label8:
  --wD3; /* Line 677, Address: 0x1026c44 */
  wD6 = wD3; /* Line 678, Address: 0x1026c4c */
  *pwD2 = (unsigned char)waterdirec.b.h; /* Line 679, Address: 0x1026c50 */

  do {
    *pwD2 &= 255; /* Line 682, Address: 0x1026c68 */
    lD0.w.l = (char)pA4[*pwD2]; /* Line 683, Address: 0x1026c7c */
    lD0.w.l += scrb_h_posit.w.h; /* Line 684, Address: 0x1026ca8 */
    lD0.w.l = -lD0.w.l; /* Line 685, Address: 0x1026cbc */
    pA1->w.h = lD0.w.h; /* Line 686, Address: 0x1026cd8 */
    pA1->w.l = lD0.w.l; /* Line 687, Address: 0x1026ce0 */
    ++pA1; /* Line 688, Address: 0x1026ce8 */
    ++*pwD4; /* Line 689, Address: 0x1026cec */
    ++*pwD2; /* Line 690, Address: 0x1026d00 */
  } while ((short)--wD3 >= 0); /* Line 691, Address: 0x1026d14 */

  wD6 >>= 3; /* Line 693, Address: 0x1026d38 */

  do {
    lD0.w.l = *pA2++; /* Line 696, Address: 0x1026d40 */
    --wD1; /* Line 697, Address: 0x1026d50 */
  } while ((short)--wD6 >= 0); /* Line 698, Address: 0x1026d5c */
  goto label2; /* Line 699, Address: 0x1026d80 */
} /* Line 700, Address: 0x1026d88 */















void scroll_h() { /* Line 716, Address: 0x1026db0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 719, Address: 0x1026dbc */
  scrh_move(); /* Line 720, Address: 0x1026dc8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 721, Address: 0x1026dd0 */
    scra_h_count ^= 16; /* Line 722, Address: 0x1026e04 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 723, Address: 0x1026e18 */
      scrflaga.b.h |= 4; /* Line 724, Address: 0x1026e44 */
    } /* Line 725, Address: 0x1026e58 */
    else {

      scrflaga.b.h |= 8; /* Line 728, Address: 0x1026e60 */
    }
  }


} /* Line 733, Address: 0x1026e74 */

void scrh_move() { /* Line 735, Address: 0x1026e90 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 738, Address: 0x1026e9c */
  wD0 -= scra_h_posit.w.h; /* Line 739, Address: 0x1026ea8 */
  wD0 -= scra_hline; /* Line 740, Address: 0x1026ebc */
  if (wD0 == 0) { /* Line 741, Address: 0x1026ed0 */

    scra_hz = 0; /* Line 743, Address: 0x1026edc */
  } /* Line 744, Address: 0x1026ee4 */
  else if ((short)wD0 < 0) { /* Line 745, Address: 0x1026eec */
    left_check(wD0); /* Line 746, Address: 0x1026f04 */
  } /* Line 747, Address: 0x1026f10 */
  else {
    right_check(wD0); /* Line 749, Address: 0x1026f18 */
  }

} /* Line 752, Address: 0x1026f24 */


void right_check(unsigned short wD0) { /* Line 755, Address: 0x1026f40 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 758, Address: 0x1026f4c */
    wD0 = 16; /* Line 759, Address: 0x1026f6c */
  }

  wD0 += scra_h_posit.w.h; /* Line 762, Address: 0x1026f74 */
  if (scralim_right < (short)wD0) { /* Line 763, Address: 0x1026f8c */
    wD0 = scralim_right; /* Line 764, Address: 0x1026fbc */
  }

  wD1 = wD0; /* Line 767, Address: 0x1026fc8 */
  wD1 -= scra_h_posit.w.h; /* Line 768, Address: 0x1026fd0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 769, Address: 0x1026fe4 */
  scra_h_posit.w.h = wD0; /* Line 770, Address: 0x1027014 */
  scra_hz = wD1; /* Line 771, Address: 0x1027020 */

} /* Line 773, Address: 0x1027028 */


void left_check(unsigned short wD0) { /* Line 776, Address: 0x1027040 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 779, Address: 0x102704c */
    wD0 = -16; /* Line 780, Address: 0x102706c */
  }

  wD0 += scra_h_posit.w.h; /* Line 783, Address: 0x1027074 */
  if (scralim_left > (short)wD0) { /* Line 784, Address: 0x102708c */
    wD0 = scralim_left; /* Line 785, Address: 0x10270bc */
  }

  wD1 = wD0; /* Line 788, Address: 0x10270c8 */
  wD1 -= scra_h_posit.w.h; /* Line 789, Address: 0x10270d0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 790, Address: 0x10270e4 */
  scra_h_posit.w.h = wD0; /* Line 791, Address: 0x1027114 */
  scra_hz = wD1; /* Line 792, Address: 0x1027120 */

} /* Line 794, Address: 0x1027128 */


















void scroll_v() { /* Line 813, Address: 0x1027140 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 816, Address: 0x102714c */
  if (actwk[0].cddat & 4) { /* Line 817, Address: 0x1027178 */
    wD0 -= 5; /* Line 818, Address: 0x1027190 */
  }

  if (actwk[0].cddat & 2) { /* Line 821, Address: 0x1027198 */
    wD0 += 32; /* Line 822, Address: 0x10271b0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 823, Address: 0x10271b8 */
      wD0 -= scra_vline; /* Line 824, Address: 0x10271d8 */
      sv_move_main2(wD0); /* Line 825, Address: 0x10271ec */
      return; /* Line 826, Address: 0x10271f8 */
    }
    wD0 -= scra_vline; /* Line 828, Address: 0x1027200 */
    if (wD0 >= 64) { /* Line 829, Address: 0x1027214 */
      wD0 -= 64; /* Line 830, Address: 0x1027224 */
      sv_move_main2(wD0); /* Line 831, Address: 0x102722c */
      return; /* Line 832, Address: 0x1027238 */
    }
    wD0 -= 64; /* Line 834, Address: 0x1027240 */
    if (limmoveflag == 0) goto label1; /* Line 835, Address: 0x1027248 */
    sv_move_sub2(); /* Line 836, Address: 0x102725c */
    return; /* Line 837, Address: 0x1027264 */
  }




  wD0 -= scra_vline; /* Line 843, Address: 0x102726c */
  if (wD0) { /* Line 844, Address: 0x1027280 */
    sv_move_main(wD0); /* Line 845, Address: 0x1027288 */
    return; /* Line 846, Address: 0x1027294 */
  }
  if (limmoveflag == 0) { /* Line 848, Address: 0x102729c */
    sv_move_sub2(); /* Line 849, Address: 0x10272b0 */
    return; /* Line 850, Address: 0x10272b8 */
  }


label1:
  scra_vz = 0; /* Line 855, Address: 0x10272c0 */

} /* Line 857, Address: 0x10272c8 */





void sv_move_main(unsigned short wD0) { /* Line 863, Address: 0x10272e0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 866, Address: 0x10272f0 */
    sv_move_main1(wD0); /* Line 867, Address: 0x102730c */
  } /* Line 868, Address: 0x1027318 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 871, Address: 0x1027320 */
    if ((short)wD1 < 0) { /* Line 872, Address: 0x102732c */
      wD1 = -(short)wD1; /* Line 873, Address: 0x1027344 */
    }

    if (wD1 >= 2048) { /* Line 876, Address: 0x1027360 */
      sv_move_main2(wD0); /* Line 877, Address: 0x1027370 */
    } /* Line 878, Address: 0x102737c */
    else {
      if ((short)wD0 > 6) { /* Line 880, Address: 0x1027384 */
        sv_move_plus(1536); /* Line 881, Address: 0x10273a4 */
      } /* Line 882, Address: 0x10273b0 */
      else if ((short)wD0 < -6) { /* Line 883, Address: 0x10273b8 */
        sv_move_minus(1536); /* Line 884, Address: 0x10273d8 */
      } /* Line 885, Address: 0x10273e4 */
      else {
        sv_move_sub(wD0); /* Line 887, Address: 0x10273ec */
      }
    }
  }
} /* Line 891, Address: 0x10273f8 */



void sv_move_main1(unsigned short wD0) { /* Line 895, Address: 0x1027410 */

  if ((short)wD0 > 2) { /* Line 897, Address: 0x102741c */
    sv_move_plus(512); /* Line 898, Address: 0x102743c */
  } /* Line 899, Address: 0x1027448 */
  else if ((short)wD0 < -2) { /* Line 900, Address: 0x1027450 */
    sv_move_minus(512); /* Line 901, Address: 0x1027470 */
  } /* Line 902, Address: 0x102747c */
  else {
    sv_move_sub(wD0); /* Line 904, Address: 0x1027484 */
  }

} /* Line 907, Address: 0x1027490 */


void sv_move_main2(unsigned short wD0) { /* Line 910, Address: 0x10274a0 */

  if ((short)wD0 > 16) { /* Line 912, Address: 0x10274ac */
    sv_move_plus(4096); /* Line 913, Address: 0x10274cc */
  } /* Line 914, Address: 0x10274d8 */
  else if ((short)wD0 < -16) { /* Line 915, Address: 0x10274e0 */
    sv_move_minus(4096); /* Line 916, Address: 0x1027500 */
  } /* Line 917, Address: 0x102750c */
  else {
    sv_move_sub(wD0); /* Line 919, Address: 0x1027514 */
  }

} /* Line 922, Address: 0x1027520 */


void sv_move_sub2() { /* Line 925, Address: 0x1027530 */
  limmoveflag = 0; /* Line 926, Address: 0x1027538 */
  sv_move_sub(0); /* Line 927, Address: 0x1027540 */
} /* Line 928, Address: 0x102754c */


void sv_move_sub(unsigned short wD0) { /* Line 931, Address: 0x1027560 */
  int_union lD1;

  lD1.w.h = 0; /* Line 934, Address: 0x102756c */
  lD1.w.l = wD0; /* Line 935, Address: 0x1027570 */
  lD1.l += scra_v_posit.w.h; /* Line 936, Address: 0x1027578 */
  if ((short)wD0 > 0) { /* Line 937, Address: 0x1027594 */
    scrv_down_ch(lD1); /* Line 938, Address: 0x10275b0 */
  } /* Line 939, Address: 0x10275bc */
  else {
    scrv_up_ch(lD1); /* Line 941, Address: 0x10275c4 */
  }

} /* Line 944, Address: 0x10275d0 */




void sv_move_minus(unsigned short wD1) { /* Line 949, Address: 0x10275e0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 953, Address: 0x10275f0 */
  lD1.l <<= 8; /* Line 954, Address: 0x102760c */
  lD1.l += scra_v_posit.l; /* Line 955, Address: 0x1027618 */

  wk = lD1.w.h; /* Line 957, Address: 0x102762c */
  lD1.w.h = lD1.w.l; /* Line 958, Address: 0x1027634 */
  lD1.w.l = wk; /* Line 959, Address: 0x102763c */
  scrv_up_ch(lD1); /* Line 960, Address: 0x1027640 */
} /* Line 961, Address: 0x102764c */



void scrv_up_ch(int_union lD1) { /* Line 965, Address: 0x1027660 */
  if (scralim_up >= lD1.w.l) { /* Line 966, Address: 0x102766c */
    if (lD1.w.l < -255) { /* Line 967, Address: 0x1027694 */
      lD1.w.l &= 2047; /* Line 968, Address: 0x10276ac */
      actwk[0].yposi.w.h &= 32767; /* Line 969, Address: 0x10276b8 */
      scra_v_posit.w.h &= 2047; /* Line 970, Address: 0x10276cc */
      scrb_v_posit.w.h &= 1023; /* Line 971, Address: 0x10276e0 */
    } /* Line 972, Address: 0x10276f4 */
    else {

      lD1.w.l = scralim_up; /* Line 975, Address: 0x10276fc */
    }
  }
  scrv_move(lD1); /* Line 978, Address: 0x1027708 */

} /* Line 980, Address: 0x1027714 */





void sv_move_plus(unsigned short wD1) { /* Line 986, Address: 0x1027730 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 990, Address: 0x1027740 */
  lD1.w.l = wD1; /* Line 991, Address: 0x1027744 */
  lD1.l <<= 8; /* Line 992, Address: 0x102774c */
  lD1.l += scra_v_posit.l; /* Line 993, Address: 0x1027758 */

  wk = lD1.w.h; /* Line 995, Address: 0x102776c */
  lD1.w.h = lD1.w.l; /* Line 996, Address: 0x1027774 */
  lD1.w.l = wk; /* Line 997, Address: 0x102777c */

  scrv_down_ch(lD1); /* Line 999, Address: 0x1027780 */

} /* Line 1001, Address: 0x102778c */



void scrv_down_ch(int_union lD1) { /* Line 1005, Address: 0x10277a0 */
  if (scralim_down <= lD1.w.l) { /* Line 1006, Address: 0x10277ac */
    lD1.w.l -= 2048; /* Line 1007, Address: 0x10277d4 */
    if (lD1.w.l > 0) { /* Line 1008, Address: 0x10277e0 */
      actwk[0].yposi.w.h &= 2047; /* Line 1009, Address: 0x10277f4 */
      scra_v_posit.w.h -= 2048; /* Line 1010, Address: 0x1027808 */
      scrb_v_posit.w.h &= 1023; /* Line 1011, Address: 0x102781c */
    } /* Line 1012, Address: 0x1027830 */
    else {
      lD1.w.l = scralim_down; /* Line 1014, Address: 0x1027838 */
    }
  }
  scrv_move(lD1); /* Line 1017, Address: 0x1027844 */

} /* Line 1019, Address: 0x1027850 */


void scrv_move(int_union lD1) { /* Line 1022, Address: 0x1027860 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 1025, Address: 0x1027870 */

  wk = lD1.w.h; /* Line 1027, Address: 0x102787c */
  lD1.w.h = lD1.w.l; /* Line 1028, Address: 0x1027884 */
  lD1.w.l = wk; /* Line 1029, Address: 0x102788c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 1031, Address: 0x1027890 */
  scra_v_posit.l = lD1.l; /* Line 1032, Address: 0x10278b8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 1035, Address: 0x10278c4 */
    scra_v_count ^= 16; /* Line 1036, Address: 0x10278f8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 1037, Address: 0x102790c */

      scrflaga.b.h |= 2; /* Line 1039, Address: 0x1027938 */
    } /* Line 1040, Address: 0x102794c */
    else {
      scrflaga.b.h |= 1; /* Line 1042, Address: 0x1027954 */
    }
  }


} /* Line 1047, Address: 0x1027968 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 1051, Address: 0x1027980 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 1054, Address: 0x102798c */
  lD0.l += lD4.l; /* Line 1055, Address: 0x102799c */
  scrb_h_posit.l = lD0.l; /* Line 1056, Address: 0x10279ac */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 1058, Address: 0x10279b8 */

    scrb_h_count ^= 16; /* Line 1060, Address: 0x10279ec */
    lD0.l -= lD2.l; /* Line 1061, Address: 0x1027a00 */
    if ((long int)lD0.l < 0) { /* Line 1062, Address: 0x1027a10 */
      scrflagb.b.h |= 4; /* Line 1063, Address: 0x1027a24 */
    } /* Line 1064, Address: 0x1027a38 */
    else {

      scrflagb.b.h |= 8; /* Line 1067, Address: 0x1027a40 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 1072, Address: 0x1027a54 */
  lD0.l += lD5.l; /* Line 1073, Address: 0x1027a64 */
  scrb_h_posit.l = lD0.l; /* Line 1074, Address: 0x1027a74 */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 1076, Address: 0x1027a80 */

    scrb_v_count ^= 16; /* Line 1078, Address: 0x1027ab4 */
    lD0.l -= lD3.l; /* Line 1079, Address: 0x1027ac8 */
    if ((long int)lD0.l < 0) { /* Line 1080, Address: 0x1027ad8 */
      scrflagb.b.h |= 1; /* Line 1081, Address: 0x1027aec */
    } /* Line 1082, Address: 0x1027b00 */
    else {

      scrflagb.b.h |= 2; /* Line 1085, Address: 0x1027b08 */
    }
  }


} /* Line 1090, Address: 0x1027b1c */






void scrollb_v(unsigned short wD0) { /* Line 1097, Address: 0x1027b30 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 1100, Address: 0x1027b3c */
  scrb_v_posit.w.h = wD0; /* Line 1101, Address: 0x1027b48 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 1103, Address: 0x1027b54 */
    scrb_v_count ^= 16; /* Line 1104, Address: 0x1027b80 */
    if ((short)wD3 > (short)wD0) { /* Line 1105, Address: 0x1027b94 */
      scrflagb.b.h |= 1; /* Line 1106, Address: 0x1027bc4 */
    } /* Line 1107, Address: 0x1027bd8 */
    else {

      scrflagb.b.h |= 2; /* Line 1110, Address: 0x1027be0 */
    }
  }


} /* Line 1115, Address: 0x1027bf4 */



void scrollb_h(int lD4, int flagb) { /* Line 1119, Address: 0x1027c10 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 1123, Address: 0x1027c20 */
  lD0.l = lD2.l + lD4; /* Line 1124, Address: 0x1027c2c */
  scrb_h_posit.l = lD0.l; /* Line 1125, Address: 0x1027c3c */

  lD1.w.h = lD0.w.l; /* Line 1127, Address: 0x1027c48 */
  lD1.w.l = lD0.w.h; /* Line 1128, Address: 0x1027c50 */
  lD1.w.l &= 16; /* Line 1129, Address: 0x1027c58 */

  bD3 = scrb_h_count; /* Line 1131, Address: 0x1027c64 */
  lD1.b.b4 ^= bD3; /* Line 1132, Address: 0x1027c70 */
  if (!lD1.b.b4) { /* Line 1133, Address: 0x1027c84 */
    scrb_h_count ^= 16; /* Line 1134, Address: 0x1027c90 */
    lD0.l -= lD2.l; /* Line 1135, Address: 0x1027ca4 */
    if ((long int)lD0.l < 0) { /* Line 1136, Address: 0x1027cb4 */
      scrflagb.b.h |= flagb; /* Line 1137, Address: 0x1027cc8 */
    } /* Line 1138, Address: 0x1027ce4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 1141, Address: 0x1027cec */
    }
  }


} /* Line 1146, Address: 0x1027d0c */



void scrollc_h(int lD4, int flagc) { /* Line 1150, Address: 0x1027d20 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 1154, Address: 0x1027d30 */
  lD0.l = lD2.l + lD4; /* Line 1155, Address: 0x1027d3c */
  scrc_h_posit.l = lD0.l; /* Line 1156, Address: 0x1027d4c */

  lD1.w.h = lD0.w.l; /* Line 1158, Address: 0x1027d58 */
  lD1.w.l = lD0.w.h; /* Line 1159, Address: 0x1027d60 */
  lD1.w.l &= 16; /* Line 1160, Address: 0x1027d68 */

  bD3 = scrc_h_count; /* Line 1162, Address: 0x1027d74 */
  lD1.b.b4 ^= bD3; /* Line 1163, Address: 0x1027d80 */
  if (!lD1.b.b4) { /* Line 1164, Address: 0x1027d94 */
    scrc_h_count ^= 16; /* Line 1165, Address: 0x1027da0 */
    lD0.l -= lD2.l; /* Line 1166, Address: 0x1027db4 */
    if ((long int)lD0.l < 0) { /* Line 1167, Address: 0x1027dc4 */
      scrflagc.b.h |= flagc; /* Line 1168, Address: 0x1027dd8 */
    } /* Line 1169, Address: 0x1027df4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 1172, Address: 0x1027dfc */
    }
  }


} /* Line 1177, Address: 0x1027e1c */











void scrollz_h(int lD4, int flagz) { /* Line 1189, Address: 0x1027e30 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 1193, Address: 0x1027e40 */
  lD0.l = lD2.l + lD4; /* Line 1194, Address: 0x1027e4c */
  scrz_h_posit.l = lD0.l; /* Line 1195, Address: 0x1027e5c */

  lD1.w.h = lD0.w.l; /* Line 1197, Address: 0x1027e68 */
  lD1.w.l = lD0.w.h; /* Line 1198, Address: 0x1027e70 */
  lD1.w.l &= 16; /* Line 1199, Address: 0x1027e78 */

  bD3 = scrz_h_count; /* Line 1201, Address: 0x1027e84 */
  lD1.b.b4 ^= bD3; /* Line 1202, Address: 0x1027e90 */
  if (!lD1.b.b4) { /* Line 1203, Address: 0x1027ea4 */
    scrz_h_count ^= 16; /* Line 1204, Address: 0x1027eb0 */
    lD0.l -= lD2.l; /* Line 1205, Address: 0x1027ec4 */
    if ((long int)lD0.l < 0) { /* Line 1206, Address: 0x1027ed4 */
      scrflagz.b.h |= flagz; /* Line 1207, Address: 0x1027ee8 */
    } /* Line 1208, Address: 0x1027f04 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 1211, Address: 0x1027f0c */
    }
  }


} /* Line 1216, Address: 0x1027f2c */














void scrollwrtadva() { /* Line 1231, Address: 0x1027f40 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1237, Address: 0x1027f5c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1238, Address: 0x1027f60 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1239, Address: 0x1027f6c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1240, Address: 0x1027f78 */
  pScrFlag = &scrflagb.b.h; /* Line 1241, Address: 0x1027f80 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1242, Address: 0x1027f88 */







} /* Line 1250, Address: 0x1027f9c */












void scrollwrt() { /* Line 1263, Address: 0x1027fc0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1272, Address: 0x1027fe0 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1273, Address: 0x1027fe4 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1274, Address: 0x1027ff0 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1275, Address: 0x1027ffc */
  pScrFlag = &scrflagbw.b.h; /* Line 1276, Address: 0x1028004 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1277, Address: 0x102800c */

  VramBase = 16384; /* Line 1279, Address: 0x1028020 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1280, Address: 0x1028024 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1281, Address: 0x1028030 */
  pMapWk = (unsigned char*)mapwka; /* Line 1282, Address: 0x102803c */
  pScrFlag = &scrflagaw.b.h; /* Line 1283, Address: 0x1028044 */

  if (*pScrFlag) { /* Line 1285, Address: 0x102804c */
    if (*pScrFlag & 1) { /* Line 1286, Address: 0x1028058 */
      *pScrFlag &= 254; /* Line 1287, Address: 0x102806c */

      lD4.l = -16; /* Line 1289, Address: 0x1028078 */
      wD5 = 65520; /* Line 1290, Address: 0x1028080 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1292, Address: 0x1028088 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1294, Address: 0x10280a8 */
    }




    if (*pScrFlag & 2) { /* Line 1300, Address: 0x10280d4 */
      *pScrFlag &= 253; /* Line 1301, Address: 0x10280e8 */

      lD4.l = 224; /* Line 1303, Address: 0x10280f4 */
      wD5 = 65520; /* Line 1304, Address: 0x10280fc */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1305, Address: 0x1028104 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1307, Address: 0x1028124 */
    }




    if (*pScrFlag & 4) { /* Line 1313, Address: 0x1028150 */
      *pScrFlag &= 251; /* Line 1314, Address: 0x1028164 */

      lD4.l = -16; /* Line 1316, Address: 0x1028170 */
      wD5 = 65520; /* Line 1317, Address: 0x1028178 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1318, Address: 0x1028180 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1320, Address: 0x10281a0 */
    }




    if (*pScrFlag & 8) { /* Line 1326, Address: 0x10281cc */
      *pScrFlag &= 247; /* Line 1327, Address: 0x10281e0 */

      lD4.l = -16; /* Line 1329, Address: 0x10281ec */
      wD5 = 320; /* Line 1330, Address: 0x10281f4 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1331, Address: 0x10281fc */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1333, Address: 0x102821c */
    }
  }






} /* Line 1342, Address: 0x1028248 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1359, Address: 0x1028270 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1370, Address: 0x102829c */

  if (*pScrFlag & 1) { /* Line 1372, Address: 0x10282a4 */
    *pScrFlag &= 254; /* Line 1373, Address: 0x10282bc */
  } /* Line 1374, Address: 0x10282d0 */
  else {
    *pScrFlag &= 254; /* Line 1376, Address: 0x10282d8 */

    if (*pScrFlag & 2) { /* Line 1378, Address: 0x10282ec */
      *pScrFlag &= 253; /* Line 1379, Address: 0x1028304 */
      lD4.w.l = 224; /* Line 1380, Address: 0x1028318 */
    } /* Line 1381, Address: 0x1028320 */
    else {
      *pScrFlag &= 253; /* Line 1383, Address: 0x1028328 */
      goto label1; /* Line 1384, Address: 0x102833c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1389, Address: 0x1028344 */
  wD0 &= 127; /* Line 1390, Address: 0x1028394 */
  wD0 = z31awrttbl[wD0 + 1]; /* Line 1391, Address: 0x102839c */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1397, Address: 0x10283bc */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1398, Address: 0x10283dc */
  if (wD0 != 0) { /* Line 1399, Address: 0x1028400 */
    wD5 = 65520; /* Line 1400, Address: 0x102840c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1401, Address: 0x1028414 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1403, Address: 0x1028434 */



  } /* Line 1407, Address: 0x1028460 */
  else {

    wD5 = 0; /* Line 1410, Address: 0x1028468 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1411, Address: 0x102846c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1415, Address: 0x102848c */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1422, Address: 0x10284b8 */






    lD4.l = -16; /* Line 1429, Address: 0x10284cc */
    wD5 = 65520; /* Line 1430, Address: 0x10284d4 */
    if (*pScrFlag & 168) { /* Line 1431, Address: 0x10284dc */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1432, Address: 0x10284f4 */
      wD5 = 320; /* Line 1433, Address: 0x1028514 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1437, Address: 0x102851c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1439, Address: 0x102854c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1440, Address: 0x1028558 */



    for (i = 0; i < 16; ++i) { /* Line 1444, Address: 0x1028568 */
      wD0 = z31awrttbl[WrtTblCnt++]; /* Line 1445, Address: 0x1028574 */
      if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1446, Address: 0x1028594 */
        wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1447, Address: 0x10285c0 */
        wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1448, Address: 0x10285e0 */

        mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1450, Address: 0x1028604 */


        vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1453, Address: 0x1028628 */

        blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1455, Address: 0x1028648 */
      }
      lD4.w.l += 16; /* Line 1457, Address: 0x102865c */
    } /* Line 1458, Address: 0x1028668 */
    *pScrFlag = 0; /* Line 1459, Address: 0x1028678 */
  }
} /* Line 1461, Address: 0x1028680 */







void scrollwrtc() {} /* Line 1469, Address: 0x10286b0 */




void scrollwrtz() {} /* Line 1474, Address: 0x10286c0 */




















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1495, Address: 0x10286d0 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1508, Address: 0x10286f8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1511, Address: 0x1028718 */
    pTilePoint->x += 2; /* Line 1512, Address: 0x102872c */
    if (pTilePoint->x >= 64) { /* Line 1513, Address: 0x1028740 */
      pTilePoint->x -= 64; /* Line 1514, Address: 0x1028754 */
    }
    xOffs += 16; /* Line 1516, Address: 0x1028768 */
  } while (--lpcnt >= 0); /* Line 1517, Address: 0x1028774 */
} /* Line 1518, Address: 0x1028788 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1522, Address: 0x10287a0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1526, Address: 0x10287c8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1529, Address: 0x10287e8 */
    pTilePoint->x += 2; /* Line 1530, Address: 0x10287fc */
    if (pTilePoint->x >= 64) { /* Line 1531, Address: 0x1028810 */
      pTilePoint->x -= 64; /* Line 1532, Address: 0x1028824 */
    }
    xOffs += 16; /* Line 1534, Address: 0x1028838 */
  } while (--lpcnt >= 0); /* Line 1535, Address: 0x1028844 */
} /* Line 1536, Address: 0x1028858 */


















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1555, Address: 0x1028870 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1559, Address: 0x1028898 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1562, Address: 0x10288b8 */
    pTilePoint->y += 2; /* Line 1563, Address: 0x10288cc */
    if (pTilePoint->y >= 32) { /* Line 1564, Address: 0x10288dc */
      pTilePoint->y -= 32; /* Line 1565, Address: 0x10288f0 */
    }
    yOffs += 16; /* Line 1567, Address: 0x1028900 */
  } while (--lpcnt >= 0); /* Line 1568, Address: 0x102890c */
} /* Line 1569, Address: 0x1028920 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1588, Address: 0x1028930 */
  int base;
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1594, Address: 0x1028964 */

    base = 1; /* Line 1596, Address: 0x1028974 */
  } /* Line 1597, Address: 0x1028978 */
  else if (VramBase == 16384) { /* Line 1598, Address: 0x1028980 */

    base = 0; /* Line 1600, Address: 0x1028990 */
  }
  x = pTilePoint->x; /* Line 1602, Address: 0x1028994 */
  y = pTilePoint->y; /* Line 1603, Address: 0x102899c */


  frip = BlkIndex & 6144; /* Line 1606, Address: 0x10289a4 */
  BlkIndex &= 1023; /* Line 1607, Address: 0x10289ac */
  if (frip == 6144) { /* Line 1608, Address: 0x10289b8 */

    p0 = 3, p1 = 2; /* Line 1610, Address: 0x10289c4 */
    p2 = 1, p3 = 0; /* Line 1611, Address: 0x10289cc */
  } /* Line 1612, Address: 0x10289d4 */
  else if (frip & 4096) { /* Line 1613, Address: 0x10289dc */

    p0 = 2, p1 = 3; /* Line 1615, Address: 0x10289e8 */
    p2 = 0, p3 = 1; /* Line 1616, Address: 0x10289f0 */
  } /* Line 1617, Address: 0x10289f8 */
  else if (frip & 2048) { /* Line 1618, Address: 0x1028a00 */

    p0 = 1, p1 = 0; /* Line 1620, Address: 0x1028a0c */
    p2 = 3, p3 = 2; /* Line 1621, Address: 0x1028a14 */
  } /* Line 1622, Address: 0x1028a1c */
  else {

    p0 = 0, p1 = 1; /* Line 1625, Address: 0x1028a24 */
    p2 = 2, p3 = 3; /* Line 1626, Address: 0x1028a2c */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1629, Address: 0x1028a34 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1630, Address: 0x1028a78 */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1631, Address: 0x1028abc */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1632, Address: 0x1028b00 */

} /* Line 1634, Address: 0x1028b44 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1652, Address: 0x1028b80 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1653, Address: 0x1028ba0 */
} /* Line 1654, Address: 0x1028bc0 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1656, Address: 0x1028bd0 */
  wH_posiw = 0; /* Line 1657, Address: 0x1028bf0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1658, Address: 0x1028bf4 */
} /* Line 1659, Address: 0x1028c14 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1666, Address: 0x1028c30 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1672, Address: 0x1028c60 */
  yOffs += wV_posiw; /* Line 1673, Address: 0x1028c70 */





  if ((short)xOffs < 0) /* Line 1679, Address: 0x1028c80 */
    xOffs = 0; /* Line 1680, Address: 0x1028c9c */
  if ((short)yOffs < 0) /* Line 1681, Address: 0x1028ca0 */
    yOffs = 0; /* Line 1682, Address: 0x1028cbc */
  if ((short)xOffs >= 16384) /* Line 1683, Address: 0x1028cc0 */
    xOffs = 16383; /* Line 1684, Address: 0x1028ce0 */
  if ((short)yOffs >= 2048) /* Line 1685, Address: 0x1028ce8 */
    yOffs = 2047; /* Line 1686, Address: 0x1028d08 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1687, Address: 0x1028d10 */
  if (i < 0) i = 0; /* Line 1688, Address: 0x1028d58 */

  ScreenNo = pMapWk[i] & 127; /* Line 1690, Address: 0x1028d64 */

  if (ScreenNo) { /* Line 1692, Address: 0x1028d80 */




    xOffs &= 32767; /* Line 1697, Address: 0x1028d88 */
    yOffs &= 32767; /* Line 1698, Address: 0x1028d94 */


    xBlk = xOffs; /* Line 1701, Address: 0x1028da0 */
    xBlk %= 256; /* Line 1702, Address: 0x1028da8 */
    xBlk /= 16; /* Line 1703, Address: 0x1028dc8 */
    yBlk = yOffs; /* Line 1704, Address: 0x1028de4 */
    yBlk %= 256; /* Line 1705, Address: 0x1028dec */
    yBlk /= 16; /* Line 1706, Address: 0x1028e0c */

    lpw = pmapwk; /* Line 1708, Address: 0x1028e28 */
    lpw += xBlk; /* Line 1709, Address: 0x1028e30 */
    lpw += yBlk * 16; /* Line 1710, Address: 0x1028e38 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1711, Address: 0x1028e44 */
    *pIndex = *lpw; /* Line 1712, Address: 0x1028e5c */

    return 1; /* Line 1714, Address: 0x1028e6c */
  }

  *pIndex = 0; /* Line 1717, Address: 0x1028e78 */
  return 0; /* Line 1718, Address: 0x1028e80 */
} /* Line 1719, Address: 0x1028e84 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1739, Address: 0x1028eb0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1747, Address: 0x1028ed8 */
  if (ScreenNo) { /* Line 1748, Address: 0x1028f3c */





    xBlk = xOffs; /* Line 1754, Address: 0x1028f44 */
    xBlk %= 256; /* Line 1755, Address: 0x1028f4c */
    xBlk /= 16; /* Line 1756, Address: 0x1028f6c */
    yBlk = yOffs; /* Line 1757, Address: 0x1028f88 */
    yBlk %= 256; /* Line 1758, Address: 0x1028f90 */
    yBlk /= 16; /* Line 1759, Address: 0x1028fb0 */


    lpw = pmapwk; /* Line 1762, Address: 0x1028fcc */
    lpw += xBlk; /* Line 1763, Address: 0x1028fd4 */
    lpw += yBlk * 16; /* Line 1764, Address: 0x1028fdc */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1765, Address: 0x1028fe8 */
    *ppBlockNo = lpw; /* Line 1766, Address: 0x1029000 */
    *pIndex = *lpw; /* Line 1767, Address: 0x1029008 */




    return 1; /* Line 1772, Address: 0x1029018 */
  }

  *pIndex = 0; /* Line 1775, Address: 0x1029024 */
  return 0; /* Line 1776, Address: 0x102902c */
} /* Line 1777, Address: 0x1029030 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1791, Address: 0x1029050 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1798, Address: 0x102906c */
  pMapWk = (unsigned char*)mapwka; /* Line 1799, Address: 0x1029070 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1800, Address: 0x1029078 */
    *pBlockIndex = BlockNo; /* Line 1801, Address: 0x102909c */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1802, Address: 0x10290a8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1803, Address: 0x10290c0 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1804, Address: 0x10290d4 */
    }
  }


} /* Line 1809, Address: 0x10290ec */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1823, Address: 0x1029110 */
  if ((scra_v_posit.w.h & 65520) - 16 < yOffs) { /* Line 1824, Address: 0x102911c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 >= (short)yOffs) { /* Line 1825, Address: 0x1029148 */
      if ((scra_h_posit.w.h & 65520) - 16 < xOffs) { /* Line 1826, Address: 0x1029194 */
        if ((short)(scra_h_posit.w.h + 336 & 65520) - 16 >= (short)xOffs) { /* Line 1827, Address: 0x10291c0 */

          return 0; /* Line 1829, Address: 0x102920c */
        }
      }
    }
  }

  return 1; /* Line 1835, Address: 0x1029218 */
} /* Line 1836, Address: 0x102921c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1853, Address: 0x1029230 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1854, Address: 0x102924c */

} /* Line 1856, Address: 0x1029268 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1858, Address: 0x1029280 */
  wH_posiw = 0; /* Line 1859, Address: 0x102929c */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1860, Address: 0x10292a0 */

} /* Line 1862, Address: 0x10292bc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1864, Address: 0x10292d0 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1865, Address: 0x10292e4 */

} /* Line 1867, Address: 0x1029300 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1869, Address: 0x1029310 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1870, Address: 0x102932c */

} /* Line 1872, Address: 0x1029348 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1874, Address: 0x1029360 */
  xOffs += wH_posiw; /* Line 1875, Address: 0x1029378 */
  yOffs += wV_posiw; /* Line 1876, Address: 0x1029388 */
  yOffs &= 240; /* Line 1877, Address: 0x1029398 */
  xOffs &= 496; /* Line 1878, Address: 0x10293a4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1880, Address: 0x10293b0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1881, Address: 0x10293dc */


} /* Line 1884, Address: 0x1029408 */















void mapwrt() { /* Line 1900, Address: 0x1029420 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1905, Address: 0x1029438 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1906, Address: 0x1029444 */
  pMapWk = (unsigned char*)mapwka; /* Line 1907, Address: 0x1029450 */
  VramBase = 16384; /* Line 1908, Address: 0x1029458 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1909, Address: 0x102945c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1913, Address: 0x1029474 */
  VramBase = 24576; /* Line 1914, Address: 0x102947c */
  mapwrt_z11a(pMapWk, VramBase); /* Line 1915, Address: 0x1029480 */

} /* Line 1917, Address: 0x1029490 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1920, Address: 0x10294b0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1921, Address: 0x10294c8 */
} /* Line 1922, Address: 0x10294e8 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1927, Address: 0x1029500 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1931, Address: 0x1029520 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1934, Address: 0x102953c */



    wD4 += 16; /* Line 1938, Address: 0x1029564 */
  } while ((short)--wD6 >= 0); /* Line 1939, Address: 0x1029570 */

} /* Line 1941, Address: 0x1029598 */




void mapwrt_z11a(unsigned char* pMapWk, int VramBase) { /* Line 1946, Address: 0x10295b0 */
  unsigned short wD0, wD4, wD6;

  wD4 = 65520; /* Line 1949, Address: 0x10295cc */
  wD6 = 15; /* Line 1950, Address: 0x10295d4 */






  do {
    if (actwk[0].xposi.w.h == 96) /* Line 1958, Address: 0x10295dc */
      wD0 = scrb_v_posit.w.h + wD4 & 1008; /* Line 1959, Address: 0x10295f8 */
    else
      wD0 = scrb_v_posit.w.h + wD4 & 752; /* Line 1961, Address: 0x1029624 */

    mapwrt_sub(&z31awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1963, Address: 0x1029648 */
    wD4 += 16; /* Line 1964, Address: 0x1029668 */
  } while ((short)--wD6 >= 0); /* Line 1965, Address: 0x1029670 */
} /* Line 1966, Address: 0x1029694 */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1992, Address: 0x10296b0 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1997, Address: 0x10296d8 */
  wD0 = pWrttbl[wD0]; /* Line 1998, Address: 0x10296e8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 2000, Address: 0x1029704 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 2001, Address: 0x1029728 */
  if (wD0) { /* Line 2002, Address: 0x1029750 */
    wD5 = 65520; /* Line 2003, Address: 0x102975c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2004, Address: 0x1029764 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 2007, Address: 0x1029780 */



  } /* Line 2011, Address: 0x10297a8 */
  else {

    wD5 = 0; /* Line 2014, Address: 0x10297b0 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 2015, Address: 0x10297b4 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 2019, Address: 0x10297d0 */
  }





} /* Line 2026, Address: 0x10297f8 */




void mapinit() { /* Line 2031, Address: 0x1029820 */





  mapset(); /* Line 2037, Address: 0x1029828 */


  colorset2(mapinittbl.colorno2); /* Line 2040, Address: 0x1029830 */
  colorset(mapinittbl.colorno2); /* Line 2041, Address: 0x1029844 */






  if (plflag != 0) { /* Line 2048, Address: 0x1029858 */
    enecginit(); /* Line 2049, Address: 0x102986c */
  }

  if (play_start & 2) { /* Line 2052, Address: 0x1029874 */

    divdevset(); /* Line 2054, Address: 0x102988c */
  }


} /* Line 2058, Address: 0x1029894 */









void mapset() {} /* Line 2068, Address: 0x10298b0 */
