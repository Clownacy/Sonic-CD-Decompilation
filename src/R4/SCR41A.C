#include "..\EQU.H"
#include "SCR41A.H"
#include "..\IMPFUNCS.H"
#include "..\SAVE.H"
#include "COL4A.H"
#include "SCRCHK4.H"

static int z41aline(int hsCount);
static void zonescrsetsub0(short HPosi, short VPosi, unsigned short offs);

static unsigned char z81awrttbl[129] = {
  0, 2, 2, 2, 2, 2, 2, 2, 2, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4
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
extern unsigned char awasintbl[256];
extern unsigned char mapwkb[8][64];
extern unsigned char mapwka[8][64];
extern map_init_data mapinittbl;














































































void enecginit() {} /* Line 128, Address: 0x1018660 */



void divdevset() {} /* Line 132, Address: 0x1018670 */














































void scr_set() { /* Line 179, Address: 0x1018680 */






  unsigned short scr_dir_tbl[6] = { /* Line 186, Address: 0x101868c */
    4, 0, 7319, 0, 1296, 96
  };
  int i;

  scrh_flag = scrv_flag = scr_die.b.h = scr_timer.b.h = zone_flag.b.h = 0; /* Line 191, Address: 0x10186c0 */

  i = 0; /* Line 193, Address: 0x1018708 */
  scrar_no = scr_dir_tbl[i++]; /* Line 194, Address: 0x101870c */
  scralim_left = scr_dir_tbl[i]; /* Line 195, Address: 0x1018728 */
  scralim_n_left = scr_dir_tbl[i++]; /* Line 196, Address: 0x101873c */
  scralim_right = scr_dir_tbl[i]; /* Line 197, Address: 0x1018758 */
  scralim_n_right = scr_dir_tbl[i++]; /* Line 198, Address: 0x101876c */
  scralim_up = scr_dir_tbl[i]; /* Line 199, Address: 0x1018788 */
  scralim_n_up = scr_dir_tbl[i++]; /* Line 200, Address: 0x101879c */
  scralim_down = scr_dir_tbl[i]; /* Line 201, Address: 0x10187b8 */
  scralim_n_down = scr_dir_tbl[i++]; /* Line 202, Address: 0x10187cc */

  scra_h_keep = scralim_left + 576; /* Line 204, Address: 0x10187e8 */
  scra_h_count = 16; /* Line 205, Address: 0x101880c */
  scra_v_count = 16; /* Line 206, Address: 0x1018818 */

  scra_vline = scr_dir_tbl[i++]; /* Line 208, Address: 0x1018824 */
  scra_hline = 160; /* Line 209, Address: 0x1018840 */

  playposiset(); /* Line 211, Address: 0x101884c */
} /* Line 212, Address: 0x1018854 */



void playposiset() { /* Line 216, Address: 0x1018870 */

  unsigned short playpositbl[2] = { /* Line 218, Address: 0x1018884 */
    80,
    64
  };
  unsigned char playmapnotbl[4] = { /* Line 222, Address: 0x10188a0 */
    127, 127, 127, 127
  };
  short xWk;
  short yWk;
  int i;


  if (plflag != 0) { /* Line 230, Address: 0x10188cc */

    playload(); /* Line 232, Address: 0x10188e0 */
    xWk = actwk[0].xposi.w.h; /* Line 233, Address: 0x10188e8 */
    yWk = actwk[0].yposi.w.h; /* Line 234, Address: 0x10188f8 */

  } /* Line 236, Address: 0x1018908 */
  else {


    i = 0; /* Line 240, Address: 0x1018910 */
    xWk = actwk[0].xposi.w.h = playpositbl[i++]; /* Line 241, Address: 0x1018914 */
    yWk = actwk[0].yposi.w.h = playpositbl[i++]; /* Line 242, Address: 0x1018938 */
  }

  if ((unsigned short)xWk > 160) { /* Line 245, Address: 0x101895c */
    xWk -= 160; /* Line 246, Address: 0x1018970 */
  } /* Line 247, Address: 0x101897c */
  else {
    xWk = 0; /* Line 249, Address: 0x1018984 */
  }


  if ((unsigned short)scralim_right < (unsigned short)xWk) { /* Line 253, Address: 0x1018988 */
    xWk = scralim_right; /* Line 254, Address: 0x10189ac */
  }
  scra_h_posit.w.h = xWk; /* Line 256, Address: 0x10189bc */

  if ((unsigned short)yWk > 96) { /* Line 258, Address: 0x10189c4 */
    yWk -= 96; /* Line 259, Address: 0x10189d8 */
  } /* Line 260, Address: 0x10189e4 */
  else {
    yWk = 0; /* Line 262, Address: 0x10189ec */
  }

  if (scralim_down < yWk) { /* Line 265, Address: 0x10189f0 */
    yWk = scralim_down; /* Line 266, Address: 0x1018a14 */
  }

  scra_v_posit.w.h = yWk; /* Line 269, Address: 0x1018a24 */


  scrbinit(xWk); /* Line 272, Address: 0x1018a2c */

  i = 0; /* Line 274, Address: 0x1018a38 */
  loopmapno = playmapnotbl[i++]; /* Line 275, Address: 0x1018a3c */
  loopmapno2 = playmapnotbl[i++]; /* Line 276, Address: 0x1018a54 */
  ballmapno = playmapnotbl[i++]; /* Line 277, Address: 0x1018a6c */
  ballmapno2 = playmapnotbl[i++]; /* Line 278, Address: 0x1018a84 */


} /* Line 281, Address: 0x1018a9c */



void scrbinit(short yWk) { /* Line 285, Address: 0x1018ac0 */
  uint_union data;
  int i;

  data.l = 0; /* Line 289, Address: 0x1018acc */
  data.w.l = scra_v_posit.w.h; /* Line 290, Address: 0x1018ad0 */
  if ((unsigned short)scra_v_posit.w.h < 512) { /* Line 291, Address: 0x1018adc */

    if ((unsigned short)scra_h_posit.w.h >= 640) { /* Line 293, Address: 0x1018af8 */
      data.w.l = 512; /* Line 294, Address: 0x1018b14 */
    }
    scrb_v_posit.w.h = data.w.l; /* Line 296, Address: 0x1018b1c */
    scrb_v_posit.w.l = 0; /* Line 297, Address: 0x1018b28 */
  } /* Line 298, Address: 0x1018b30 */
  else {


    data.w.l -= 512; /* Line 302, Address: 0x1018b38 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 303, Address: 0x1018b44 */
    data.l >>= 2; /* Line 304, Address: 0x1018b68 */
    data.l *= 3; /* Line 305, Address: 0x1018b74 */
    data.l += 0x2000000; /* Line 306, Address: 0x1018b84 */
    scrb_v_posit.w.h = data.w.h; /* Line 307, Address: 0x1018b94 */
    scrb_v_posit.w.l = data.w.l; /* Line 308, Address: 0x1018ba0 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 309, Address: 0x1018bac */
  }

  scrc_v_posit.w.h = data.w.l; /* Line 312, Address: 0x1018bd0 */
  scrz_v_posit.w.h = data.w.l; /* Line 313, Address: 0x1018bdc */

  scrz_h_posit.w.h = (unsigned short)(yWk >> 4); /* Line 315, Address: 0x1018be8 */
  scrc_h_posit.w.h = (unsigned short)((yWk >> 5) * 3); /* Line 316, Address: 0x1018c0c */
  scrb_h_posit.w.h = (unsigned short)((yWk >> 6) * 3); /* Line 317, Address: 0x1018c38 */
  for (i = 0; i < 30; ++i) { /* Line 318, Address: 0x1018c64 */

    hscrollwork[i] = 0; /* Line 320, Address: 0x1018c70 */
  } /* Line 321, Address: 0x1018c84 */
} /* Line 322, Address: 0x1018c94 */



void scroll() { /* Line 326, Address: 0x1018cb0 */
  uint_union data;
  int hsCount;
  int i;

  if (scroll_start.b.h) return; /* Line 331, Address: 0x1018cc0 */


  scrflaga.w = scrflagb.w = scrflagc.w = scrflagz.w = 0; /* Line 334, Address: 0x1018cd0 */
  scrchk(); /* Line 335, Address: 0x1018cfc */
  scroll_h(); /* Line 336, Address: 0x1018d04 */
  scroll_v(); /* Line 337, Address: 0x1018d0c */

  vscroll.w.h = scra_v_posit.w.h; /* Line 339, Address: 0x1018d14 */
  vscroll.w.l = scrb_v_posit.w.h; /* Line 340, Address: 0x1018d24 */



  scrollz_h(scra_hz << 4, 64); /* Line 344, Address: 0x1018d34 */
  scrollc_h((long int)(scra_hz << 3) * 3, 16); /* Line 345, Address: 0x1018d54 */
  scrollb_h((long int)(scra_hz << 2) * 3, 4); /* Line 346, Address: 0x1018d8c */

  data.l = 0; /* Line 348, Address: 0x1018dc4 */
  data.w.l = scra_v_posit.w.h; /* Line 349, Address: 0x1018dc8 */
  if ((unsigned short)scra_v_posit.w.h < 512) { /* Line 350, Address: 0x1018dd4 */

    if ((unsigned short)scra_h_posit.w.h >= 640) /* Line 352, Address: 0x1018df0 */
      data.w.l = 512; /* Line 353, Address: 0x1018e0c */
  } /* Line 354, Address: 0x1018e14 */
  else {


    data.w.l -= 512; /* Line 358, Address: 0x1018e1c */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 359, Address: 0x1018e28 */
    data.l >>= 2; /* Line 360, Address: 0x1018e4c */
    data.l *= 3; /* Line 361, Address: 0x1018e58 */
    data.l += 0x2000000; /* Line 362, Address: 0x1018e68 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 363, Address: 0x1018e78 */
  }

  scrollb_v(data.w.l); /* Line 366, Address: 0x1018e9c */

  vscroll.w.l = scrb_v_posit.w.h; /* Line 368, Address: 0x1018ea8 */
  scrc_v_posit.w.h = scrb_v_posit.w.h; /* Line 369, Address: 0x1018eb8 */
  scrz_v_posit.w.h = scrb_v_posit.w.h; /* Line 370, Address: 0x1018ec8 */
  scrflagb.b.h |= scrflagz.b.h | scrflagc.b.h; /* Line 371, Address: 0x1018ed8 */
  scrflagz.b.h = 0; /* Line 372, Address: 0x1018f0c */
  scrflagc.b.h = 0; /* Line 373, Address: 0x1018f14 */

  hsCount = 0; /* Line 375, Address: 0x1018f1c */
  for (i = 0; i < 16; ++i) { /* Line 376, Address: 0x1018f20 */

    hscrollwork[hsCount] = -scrb_h_posit.w.h; /* Line 378, Address: 0x1018f2c */
    ++hsCount; /* Line 379, Address: 0x1018f5c */
  } /* Line 380, Address: 0x1018f60 */

  hsCount = z41aline(hsCount); /* Line 382, Address: 0x1018f70 */

  for (i = 0; i < 144; ++i) { /* Line 384, Address: 0x1018f80 */

    hscrollwork[hsCount] = -scrc_h_posit.w.h; /* Line 386, Address: 0x1018f8c */
    ++hsCount; /* Line 387, Address: 0x1018fbc */
  } /* Line 388, Address: 0x1018fc0 */

  data.w.l = -scra_h_posit.w.h; /* Line 390, Address: 0x1018fd0 */
  data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 391, Address: 0x1018fec */
  data.w.l = scrb_v_posit.w.h; /* Line 392, Address: 0x1019010 */
  data.w.l &= 2040; /* Line 393, Address: 0x101901c */
  data.w.l >>= 2; /* Line 394, Address: 0x1019028 */
  zonescrsetsub0(-scra_h_posit.w.h, scrb_v_posit.w.h, data.w.l / 2); /* Line 395, Address: 0x1019034 */

} /* Line 397, Address: 0x1019084 */



static int z41aline(int hsCount) { /* Line 401, Address: 0x10190a0 */
  int temp;
  int_union data;
  int i, j;
  int z41ascrtbl[5] = { /* Line 405, Address: 0x10190b4 */
    14, 10, 4, 2, 2
  };


  temp = scra_h_posit.w.h - scrz_h_posit.w.h; /* Line 410, Address: 0x10190e0 */
  temp <<= 7; /* Line 411, Address: 0x1019104 */
  temp /= 5; /* Line 412, Address: 0x1019108 */
  temp <<= 9; /* Line 413, Address: 0x1019120 */
  data.l = 0; /* Line 414, Address: 0x1019124 */
  data.w.l = scrz_h_posit.w.h; /* Line 415, Address: 0x1019128 */
  for (i = 0; i < 5; ++i) { /* Line 416, Address: 0x1019134 */


    for (j = 0; j < z41ascrtbl[4 - i]; ++j) { /* Line 419, Address: 0x1019140 */


      hscrollwork[hsCount] = -data.w.l; /* Line 422, Address: 0x101914c */
      ++hsCount; /* Line 423, Address: 0x101917c */
    } /* Line 424, Address: 0x1019188 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 425, Address: 0x10191ac */
    data.l += temp; /* Line 426, Address: 0x10191d0 */
    data.l = (unsigned int)data.l >> 16 & 65535 | data.l << 16 & -65536; /* Line 427, Address: 0x10191dc */
  } /* Line 428, Address: 0x1019200 */
  return hsCount; /* Line 429, Address: 0x1019210 */
} /* Line 430, Address: 0x1019214 */



static void zonescrsetsub0(short HPosi, short VPosi, unsigned short offs) { /* Line 434, Address: 0x1019230 */
  int_union* pHScrollBuff;
  int_union hsw;
  short_union data1, data2;
  short avp;
  int i;

  pHScrollBuff = lphscrollbuff; /* Line 441, Address: 0x101924c */
  data1.b.l = waterdirec.b.h; /* Line 442, Address: 0x1019254 */
  data2.b.l = waterdirec.b.h; /* Line 443, Address: 0x1019260 */
  waterdirec.w += 128; /* Line 444, Address: 0x101926c */
  data1.w += scrb_v_posit.w.h; /* Line 445, Address: 0x1019280 */
  data1.b.h = 0; /* Line 446, Address: 0x1019294 */
  data2.w += scra_v_posit.w.h; /* Line 447, Address: 0x1019298 */
  data2.b.h = 0; /* Line 448, Address: 0x10192ac */

  VPosi &= 7; /* Line 450, Address: 0x10192b0 */
  hsw.w.l = hscrollwork[offs++]; /* Line 451, Address: 0x10192bc */
  avp = scra_v_posit.w.h; /* Line 452, Address: 0x10192e4 */
  i = 232; /* Line 453, Address: 0x10192f4 */


  do {
    if (avp > waterposi) { /* Line 457, Address: 0x10192f8 */



      do {
        pHScrollBuff->w.h = HPosi; /* Line 462, Address: 0x101931c */
        pHScrollBuff->w.l = (short)(char)awasintbl[data1.w] + hsw.w.l; /* Line 463, Address: 0x1019324 */
        ++pHScrollBuff; /* Line 464, Address: 0x1019374 */
        ++data1.b.l; /* Line 465, Address: 0x1019378 */
        ++data2.b.l; /* Line 466, Address: 0x1019384 */
        ++VPosi; /* Line 467, Address: 0x1019390 */
        if (VPosi == 8) { /* Line 468, Address: 0x101939c */

          VPosi = 0; /* Line 470, Address: 0x10193b4 */
          hsw.w.l = hscrollwork[offs++]; /* Line 471, Address: 0x10193b8 */
        }
      } while (--i > 0); /* Line 473, Address: 0x10193e0 */

      return; /* Line 475, Address: 0x10193ec */
    }
    pHScrollBuff->l = hsw.l; /* Line 477, Address: 0x10193f4 */
    ++pHScrollBuff; /* Line 478, Address: 0x10193fc */
    ++avp; /* Line 479, Address: 0x1019400 */
    ++data1.b.l; /* Line 480, Address: 0x101940c */
    ++data2.b.l; /* Line 481, Address: 0x1019418 */
    ++VPosi; /* Line 482, Address: 0x1019424 */
    if (VPosi == 8) { /* Line 483, Address: 0x1019430 */

      VPosi = 0; /* Line 485, Address: 0x1019448 */
      hsw.w.l = hscrollwork[offs++]; /* Line 486, Address: 0x101944c */
    }
  } while (--i > 0); /* Line 488, Address: 0x1019474 */

} /* Line 490, Address: 0x1019480 */











void scroll_h() { /* Line 502, Address: 0x10194a0 */
  unsigned short wD4;

  wD4 = scra_h_posit.w.h; /* Line 505, Address: 0x10194ac */
  scrh_move(); /* Line 506, Address: 0x10194b8 */
  if (((unsigned char)(scra_h_posit.w.h & 16) ^ scra_h_count) != 0) { /* Line 507, Address: 0x10194c0 */
    scra_h_count ^= 16; /* Line 508, Address: 0x10194f4 */
    if ((short)wD4 > scra_h_posit.w.h) { /* Line 509, Address: 0x1019508 */
      scrflaga.b.h |= 4; /* Line 510, Address: 0x1019534 */
    } /* Line 511, Address: 0x1019548 */
    else {

      scrflaga.b.h |= 8; /* Line 514, Address: 0x1019550 */
    }
  }


} /* Line 519, Address: 0x1019564 */

void scrh_move() { /* Line 521, Address: 0x1019580 */
  unsigned short wD0;

  wD0 = actwk[0].xposi.w.h; /* Line 524, Address: 0x101958c */
  wD0 -= scra_h_posit.w.h; /* Line 525, Address: 0x1019598 */
  wD0 -= scra_hline; /* Line 526, Address: 0x10195ac */
  if (wD0 == 0) { /* Line 527, Address: 0x10195c0 */

    scra_hz = 0; /* Line 529, Address: 0x10195cc */
  } /* Line 530, Address: 0x10195d4 */
  else if ((short)wD0 < 0) { /* Line 531, Address: 0x10195dc */
    left_check(wD0); /* Line 532, Address: 0x10195f4 */
  } /* Line 533, Address: 0x1019600 */
  else {
    right_check(wD0); /* Line 535, Address: 0x1019608 */
  }

} /* Line 538, Address: 0x1019614 */


void right_check(unsigned short wD0) { /* Line 541, Address: 0x1019630 */
  unsigned short wD1;

  if ((short)wD0 > 16) { /* Line 544, Address: 0x101963c */
    wD0 = 16; /* Line 545, Address: 0x101965c */
  }

  wD0 += scra_h_posit.w.h; /* Line 548, Address: 0x1019664 */
  if (scralim_right < (short)wD0) { /* Line 549, Address: 0x101967c */
    wD0 = scralim_right; /* Line 550, Address: 0x10196ac */
  }

  wD1 = wD0; /* Line 553, Address: 0x10196b8 */
  wD1 -= scra_h_posit.w.h; /* Line 554, Address: 0x10196c0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 555, Address: 0x10196d4 */
  scra_h_posit.w.h = wD0; /* Line 556, Address: 0x1019704 */
  scra_hz = wD1; /* Line 557, Address: 0x1019710 */

} /* Line 559, Address: 0x1019718 */


void left_check(unsigned short wD0) { /* Line 562, Address: 0x1019730 */
  unsigned short wD1;

  if ((short)wD0 < -16) { /* Line 565, Address: 0x101973c */
    wD0 = -16; /* Line 566, Address: 0x101975c */
  }

  wD0 += scra_h_posit.w.h; /* Line 569, Address: 0x1019764 */
  if (scralim_left > (short)wD0) { /* Line 570, Address: 0x101977c */
    wD0 = scralim_left; /* Line 571, Address: 0x10197ac */
  }

  wD1 = wD0; /* Line 574, Address: 0x10197b8 */
  wD1 -= scra_h_posit.w.h; /* Line 575, Address: 0x10197c0 */
  if (wD1 & 32768) wD1 <<= 8, wD1 |= 32768; else wD1 <<= 8; /* Line 576, Address: 0x10197d4 */
  scra_h_posit.w.h = wD0; /* Line 577, Address: 0x1019804 */
  scra_hz = wD1; /* Line 578, Address: 0x1019810 */

} /* Line 580, Address: 0x1019818 */


















void scroll_v() { /* Line 599, Address: 0x1019830 */
  unsigned short wD0;

  wD0 = actwk[0].yposi.w.h - scra_v_posit.w.h; /* Line 602, Address: 0x101983c */
  if (actwk[0].cddat & 4) { /* Line 603, Address: 0x1019868 */
    wD0 -= 5; /* Line 604, Address: 0x1019880 */
  }

  if (actwk[0].cddat & 2) { /* Line 607, Address: 0x1019888 */
    wD0 += 32; /* Line 608, Address: 0x10198a0 */
    if ((unsigned short)scra_vline > wD0) { /* Line 609, Address: 0x10198a8 */
      wD0 -= scra_vline; /* Line 610, Address: 0x10198c8 */
      sv_move_main2(wD0); /* Line 611, Address: 0x10198dc */
      return; /* Line 612, Address: 0x10198e8 */
    }
    wD0 -= scra_vline; /* Line 614, Address: 0x10198f0 */
    if (wD0 >= 64) { /* Line 615, Address: 0x1019904 */
      wD0 -= 64; /* Line 616, Address: 0x1019914 */
      sv_move_main2(wD0); /* Line 617, Address: 0x101991c */
      return; /* Line 618, Address: 0x1019928 */
    }
    wD0 -= 64; /* Line 620, Address: 0x1019930 */
    if (limmoveflag == 0) goto label1; /* Line 621, Address: 0x1019938 */
    sv_move_sub2(); /* Line 622, Address: 0x101994c */
    return; /* Line 623, Address: 0x1019954 */
  }




  wD0 -= scra_vline; /* Line 629, Address: 0x101995c */
  if (wD0) { /* Line 630, Address: 0x1019970 */
    sv_move_main(wD0); /* Line 631, Address: 0x1019978 */
    return; /* Line 632, Address: 0x1019984 */
  }
  if (limmoveflag == 0) { /* Line 634, Address: 0x101998c */
    sv_move_sub2(); /* Line 635, Address: 0x10199a0 */
    return; /* Line 636, Address: 0x10199a8 */
  }


label1:
  scra_vz = 0; /* Line 641, Address: 0x10199b0 */

} /* Line 643, Address: 0x10199b8 */





void sv_move_main(unsigned short wD0) { /* Line 649, Address: 0x10199d0 */
  unsigned short wD1;

  if (scra_vline != 96) { /* Line 652, Address: 0x10199e0 */
    sv_move_main1(wD0); /* Line 653, Address: 0x10199fc */
  } /* Line 654, Address: 0x1019a08 */
  else {

    wD1 = actwk[0].mspeed.w; /* Line 657, Address: 0x1019a10 */
    if ((short)wD1 < 0) { /* Line 658, Address: 0x1019a1c */
      wD1 = -(short)wD1; /* Line 659, Address: 0x1019a34 */
    }

    if (wD1 >= 2048) { /* Line 662, Address: 0x1019a50 */
      sv_move_main2(wD0); /* Line 663, Address: 0x1019a60 */
    } /* Line 664, Address: 0x1019a6c */
    else {
      if ((short)wD0 > 6) { /* Line 666, Address: 0x1019a74 */
        sv_move_plus(1536); /* Line 667, Address: 0x1019a94 */
      } /* Line 668, Address: 0x1019aa0 */
      else if ((short)wD0 < -6) { /* Line 669, Address: 0x1019aa8 */
        sv_move_minus(1536); /* Line 670, Address: 0x1019ac8 */
      } /* Line 671, Address: 0x1019ad4 */
      else {
        sv_move_sub(wD0); /* Line 673, Address: 0x1019adc */
      }
    }
  }
} /* Line 677, Address: 0x1019ae8 */



void sv_move_main1(unsigned short wD0) { /* Line 681, Address: 0x1019b00 */

  if ((short)wD0 > 2) { /* Line 683, Address: 0x1019b0c */
    sv_move_plus(512); /* Line 684, Address: 0x1019b2c */
  } /* Line 685, Address: 0x1019b38 */
  else if ((short)wD0 < -2) { /* Line 686, Address: 0x1019b40 */
    sv_move_minus(512); /* Line 687, Address: 0x1019b60 */
  } /* Line 688, Address: 0x1019b6c */
  else {
    sv_move_sub(wD0); /* Line 690, Address: 0x1019b74 */
  }

} /* Line 693, Address: 0x1019b80 */


void sv_move_main2(unsigned short wD0) { /* Line 696, Address: 0x1019b90 */

  if ((short)wD0 > 16) { /* Line 698, Address: 0x1019b9c */
    sv_move_plus(4096); /* Line 699, Address: 0x1019bbc */
  } /* Line 700, Address: 0x1019bc8 */
  else if ((short)wD0 < -16) { /* Line 701, Address: 0x1019bd0 */
    sv_move_minus(4096); /* Line 702, Address: 0x1019bf0 */
  } /* Line 703, Address: 0x1019bfc */
  else {
    sv_move_sub(wD0); /* Line 705, Address: 0x1019c04 */
  }

} /* Line 708, Address: 0x1019c10 */


void sv_move_sub2() { /* Line 711, Address: 0x1019c20 */
  limmoveflag = 0; /* Line 712, Address: 0x1019c28 */
  sv_move_sub(0); /* Line 713, Address: 0x1019c30 */
} /* Line 714, Address: 0x1019c3c */


void sv_move_sub(unsigned short wD0) { /* Line 717, Address: 0x1019c50 */
  int_union lD1;

  lD1.w.h = 0; /* Line 720, Address: 0x1019c5c */
  lD1.w.l = wD0; /* Line 721, Address: 0x1019c60 */
  lD1.l += scra_v_posit.w.h; /* Line 722, Address: 0x1019c68 */
  if ((short)wD0 > 0) { /* Line 723, Address: 0x1019c84 */
    scrv_down_ch(lD1); /* Line 724, Address: 0x1019ca0 */
  } /* Line 725, Address: 0x1019cac */
  else {
    scrv_up_ch(lD1); /* Line 727, Address: 0x1019cb4 */
  }

} /* Line 730, Address: 0x1019cc0 */




void sv_move_minus(unsigned short wD1) { /* Line 735, Address: 0x1019cd0 */
  int_union lD1;
  unsigned short wk;

  lD1.l = -(short)wD1; /* Line 739, Address: 0x1019ce0 */
  lD1.l <<= 8; /* Line 740, Address: 0x1019cfc */
  lD1.l += scra_v_posit.l; /* Line 741, Address: 0x1019d08 */

  wk = lD1.w.h; /* Line 743, Address: 0x1019d1c */
  lD1.w.h = lD1.w.l; /* Line 744, Address: 0x1019d24 */
  lD1.w.l = wk; /* Line 745, Address: 0x1019d2c */
  scrv_up_ch(lD1); /* Line 746, Address: 0x1019d30 */
} /* Line 747, Address: 0x1019d3c */



void scrv_up_ch(int_union lD1) { /* Line 751, Address: 0x1019d50 */
  if (scralim_up >= lD1.w.l) { /* Line 752, Address: 0x1019d5c */
    if (lD1.w.l < -255) { /* Line 753, Address: 0x1019d84 */
      lD1.w.l &= 2047; /* Line 754, Address: 0x1019d9c */
      actwk[0].yposi.w.h &= 2047; /* Line 755, Address: 0x1019da8 */
      scra_v_posit.w.h &= 2047; /* Line 756, Address: 0x1019dbc */
      scrb_v_posit.w.h &= 1023; /* Line 757, Address: 0x1019dd0 */
    } /* Line 758, Address: 0x1019de4 */
    else {

      lD1.w.l = scralim_up; /* Line 761, Address: 0x1019dec */
    }
  }
  scrv_move(lD1); /* Line 764, Address: 0x1019df8 */

} /* Line 766, Address: 0x1019e04 */





void sv_move_plus(unsigned short wD1) { /* Line 772, Address: 0x1019e20 */
  int_union lD1;
  unsigned short wk;

  lD1.w.h = 0; /* Line 776, Address: 0x1019e30 */
  lD1.w.l = wD1; /* Line 777, Address: 0x1019e34 */
  lD1.l <<= 8; /* Line 778, Address: 0x1019e3c */
  lD1.l += scra_v_posit.l; /* Line 779, Address: 0x1019e48 */

  wk = lD1.w.h; /* Line 781, Address: 0x1019e5c */
  lD1.w.h = lD1.w.l; /* Line 782, Address: 0x1019e64 */
  lD1.w.l = wk; /* Line 783, Address: 0x1019e6c */

  scrv_down_ch(lD1); /* Line 785, Address: 0x1019e70 */

} /* Line 787, Address: 0x1019e7c */



void scrv_down_ch(int_union lD1) { /* Line 791, Address: 0x1019e90 */
  if (scralim_down <= lD1.w.l) { /* Line 792, Address: 0x1019e9c */
    lD1.w.l -= 2048; /* Line 793, Address: 0x1019ec4 */
    if (lD1.w.l > 0) { /* Line 794, Address: 0x1019ed0 */
      actwk[0].yposi.w.h &= 2047; /* Line 795, Address: 0x1019ee4 */
      scra_v_posit.w.h -= 2048; /* Line 796, Address: 0x1019ef8 */
      scrb_v_posit.w.h &= 1023; /* Line 797, Address: 0x1019f0c */
    } /* Line 798, Address: 0x1019f20 */
    else {
      lD1.w.l = scralim_down; /* Line 800, Address: 0x1019f28 */
    }
  }
  scrv_move(lD1); /* Line 803, Address: 0x1019f34 */

} /* Line 805, Address: 0x1019f40 */


void scrv_move(int_union lD1) { /* Line 808, Address: 0x1019f50 */
  unsigned short wD4, wk;

  wD4 = scra_v_posit.w.h; /* Line 811, Address: 0x1019f60 */

  wk = lD1.w.h; /* Line 813, Address: 0x1019f6c */
  lD1.w.h = lD1.w.l; /* Line 814, Address: 0x1019f74 */
  lD1.w.l = wk; /* Line 815, Address: 0x1019f7c */

  scra_vz = (unsigned short)((lD1.l - scra_v_posit.l) >> 8); /* Line 817, Address: 0x1019f80 */
  scra_v_posit.l = lD1.l; /* Line 818, Address: 0x1019fa8 */


  if (((unsigned char)(scra_v_posit.w.h & 16) ^ scra_v_count) == 0) { /* Line 821, Address: 0x1019fb4 */
    scra_v_count ^= 16; /* Line 822, Address: 0x1019fe8 */
    if (scra_v_posit.w.h >= (short)wD4) { /* Line 823, Address: 0x1019ffc */

      scrflaga.b.h |= 2; /* Line 825, Address: 0x101a028 */
    } /* Line 826, Address: 0x101a03c */
    else {
      scrflaga.b.h |= 1; /* Line 828, Address: 0x101a044 */
    }
  }


} /* Line 833, Address: 0x101a058 */



void scrollb_hv(int_union lD4, int_union lD5) { /* Line 837, Address: 0x101a070 */
  int_union lD0, lD2, lD3;

  lD0.l = lD2.l = scrb_h_posit.l; /* Line 840, Address: 0x101a07c */
  lD0.l += lD4.l; /* Line 841, Address: 0x101a08c */
  scrb_h_posit.l = lD0.l; /* Line 842, Address: 0x101a09c */

  if (((unsigned char)(scrb_h_posit.w.h & 16) ^ scrb_h_count) == 0) { /* Line 844, Address: 0x101a0a8 */

    scrb_h_count ^= 16; /* Line 846, Address: 0x101a0dc */
    lD0.l -= lD2.l; /* Line 847, Address: 0x101a0f0 */
    if ((long int)lD0.l < 0) { /* Line 848, Address: 0x101a100 */
      scrflagb.b.h |= 4; /* Line 849, Address: 0x101a114 */
    } /* Line 850, Address: 0x101a128 */
    else {

      scrflagb.b.h |= 8; /* Line 853, Address: 0x101a130 */
    }
  }


  lD0.l = lD3.l = scrb_v_posit.l; /* Line 858, Address: 0x101a144 */
  lD0.l += lD5.l; /* Line 859, Address: 0x101a154 */
  if ((long int)lD0.l < 0) lD0.l = 0; /* Line 860, Address: 0x101a164 */
  scrb_v_posit.l = lD0.l; /* Line 861, Address: 0x101a17c */

  if (((unsigned char)(scrb_v_posit.w.h & 16) ^ scrb_v_count) == 0) { /* Line 863, Address: 0x101a188 */

    scrb_v_count ^= 16; /* Line 865, Address: 0x101a1bc */
    lD0.l -= lD3.l; /* Line 866, Address: 0x101a1d0 */
    if ((long int)lD0.l < 0) { /* Line 867, Address: 0x101a1e0 */
      scrflagb.b.h |= 1; /* Line 868, Address: 0x101a1f4 */
    } /* Line 869, Address: 0x101a208 */
    else {

      scrflagb.b.h |= 2; /* Line 872, Address: 0x101a210 */
    }
  }


} /* Line 877, Address: 0x101a224 */






void scrollb_v(unsigned short wD0) { /* Line 884, Address: 0x101a230 */
  unsigned short wD3;

  wD3 = scrb_v_posit.w.h; /* Line 887, Address: 0x101a23c */
  scrb_v_posit.w.h = wD0; /* Line 888, Address: 0x101a248 */

  if (((unsigned char)(wD0 & 16) ^ scrb_v_count) == 0) { /* Line 890, Address: 0x101a254 */
    scrb_v_count ^= 16; /* Line 891, Address: 0x101a280 */
    if ((short)wD3 > (short)wD0) { /* Line 892, Address: 0x101a294 */
      scrflagb.b.h |= 1; /* Line 893, Address: 0x101a2c4 */
    } /* Line 894, Address: 0x101a2d8 */
    else {

      scrflagb.b.h |= 2; /* Line 897, Address: 0x101a2e0 */
    }
  }


} /* Line 902, Address: 0x101a2f4 */



void scrollb_h(int lD4, int flagb) { /* Line 906, Address: 0x101a310 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrb_h_posit.l; /* Line 910, Address: 0x101a320 */
  lD0.l = lD2.l + lD4; /* Line 911, Address: 0x101a32c */
  scrb_h_posit.l = lD0.l; /* Line 912, Address: 0x101a33c */

  lD1.w.h = lD0.w.l; /* Line 914, Address: 0x101a348 */
  lD1.w.l = lD0.w.h; /* Line 915, Address: 0x101a350 */
  lD1.w.l &= 16; /* Line 916, Address: 0x101a358 */

  bD3 = scrb_h_count; /* Line 918, Address: 0x101a364 */
  lD1.b.b4 ^= bD3; /* Line 919, Address: 0x101a370 */
  if (!lD1.b.b4) { /* Line 920, Address: 0x101a384 */
    scrb_h_count ^= 16; /* Line 921, Address: 0x101a390 */
    lD0.l -= lD2.l; /* Line 922, Address: 0x101a3a4 */
    if ((long int)lD0.l < 0) { /* Line 923, Address: 0x101a3b4 */
      scrflagb.b.h |= flagb; /* Line 924, Address: 0x101a3c8 */
    } /* Line 925, Address: 0x101a3e4 */
    else {

      scrflagb.b.h |= flagb << 1; /* Line 928, Address: 0x101a3ec */
    }
  }


} /* Line 933, Address: 0x101a40c */


void scrollc_h(int lD4, int flagc) { /* Line 936, Address: 0x101a420 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrc_h_posit.l; /* Line 940, Address: 0x101a430 */
  lD0.l = lD2.l + lD4; /* Line 941, Address: 0x101a43c */
  scrc_h_posit.l = lD0.l; /* Line 942, Address: 0x101a44c */

  lD1.w.h = lD0.w.l; /* Line 944, Address: 0x101a458 */
  lD1.w.l = lD0.w.h; /* Line 945, Address: 0x101a460 */
  lD1.w.l &= 16; /* Line 946, Address: 0x101a468 */

  bD3 = scrc_h_count; /* Line 948, Address: 0x101a474 */
  lD1.b.b4 ^= bD3; /* Line 949, Address: 0x101a480 */
  if (!lD1.b.b4) { /* Line 950, Address: 0x101a494 */
    scrc_h_count ^= 16; /* Line 951, Address: 0x101a4a0 */
    lD0.l -= lD2.l; /* Line 952, Address: 0x101a4b4 */
    if ((long int)lD0.l < 0) { /* Line 953, Address: 0x101a4c4 */
      scrflagc.b.h |= flagc; /* Line 954, Address: 0x101a4d8 */
    } /* Line 955, Address: 0x101a4f4 */
    else {

      scrflagc.b.h |= flagc << 1; /* Line 958, Address: 0x101a4fc */
    }
  }


} /* Line 963, Address: 0x101a51c */











void scrollz_h(int lD4, int flagz) { /* Line 975, Address: 0x101a530 */
  int_union lD0, lD1, lD2;
  unsigned char bD3;

  lD2.l = scrz_h_posit.l; /* Line 979, Address: 0x101a540 */
  lD0.l = lD2.l + lD4; /* Line 980, Address: 0x101a54c */
  scrz_h_posit.l = lD0.l; /* Line 981, Address: 0x101a55c */

  lD1.w.h = lD0.w.l; /* Line 983, Address: 0x101a568 */
  lD1.w.l = lD0.w.h; /* Line 984, Address: 0x101a570 */
  lD1.w.l &= 16; /* Line 985, Address: 0x101a578 */

  bD3 = scrz_h_count; /* Line 987, Address: 0x101a584 */
  lD1.b.b4 ^= bD3; /* Line 988, Address: 0x101a590 */
  if (!lD1.b.b4) { /* Line 989, Address: 0x101a5a4 */
    scrz_h_count ^= 16; /* Line 990, Address: 0x101a5b0 */
    lD0.l -= lD2.l; /* Line 991, Address: 0x101a5c4 */
    if ((long int)lD0.l < 0) { /* Line 992, Address: 0x101a5d4 */
      scrflagz.b.h |= flagz; /* Line 993, Address: 0x101a5e8 */
    } /* Line 994, Address: 0x101a604 */
    else {

      scrflagz.b.h |= flagz << 1; /* Line 997, Address: 0x101a60c */
    }
  }


} /* Line 1002, Address: 0x101a62c */













void scrollwrtadva() { /* Line 1016, Address: 0x101a640 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;

  VramBase = 24576; /* Line 1022, Address: 0x101a65c */
  wH_posiw = scrb_h_posit.w.h; /* Line 1023, Address: 0x101a660 */
  wV_posiw = scrb_v_posit.w.h; /* Line 1024, Address: 0x101a66c */
  pMapWk = (unsigned char*)mapwkb; /* Line 1025, Address: 0x101a678 */
  pScrFlag = &scrflagb.b.h; /* Line 1026, Address: 0x101a680 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1027, Address: 0x101a688 */

  wH_posiw = scrc_h_posit.w.h; /* Line 1029, Address: 0x101a69c */
  wV_posiw = scrc_v_posit.w.h; /* Line 1030, Address: 0x101a6a8 */
  pScrFlag = &scrflagc.b.h; /* Line 1031, Address: 0x101a6b4 */
  scrollwrtc(); /* Line 1032, Address: 0x101a6bc */

} /* Line 1034, Address: 0x101a6c4 */












void scrollwrt() { /* Line 1047, Address: 0x101a6f0 */
  unsigned short wH_posiw, wV_posiw;
  int VramBase;
  POINT TilePoint;
  unsigned char* pScrFlag;
  unsigned char* pMapWk;
  int_union lD4;
  unsigned short wD5;

  VramBase = 24576; /* Line 1056, Address: 0x101a710 */
  wH_posiw = scrb_h_posiw.w.h; /* Line 1057, Address: 0x101a714 */
  wV_posiw = scrb_v_posiw.w.h; /* Line 1058, Address: 0x101a720 */
  pMapWk = (unsigned char*)mapwkb; /* Line 1059, Address: 0x101a72c */
  pScrFlag = &scrflagbw.b.h; /* Line 1060, Address: 0x101a734 */
  scrollwrtb(pScrFlag, pMapWk, VramBase); /* Line 1061, Address: 0x101a73c */

  VramBase = 16384; /* Line 1063, Address: 0x101a750 */
  wH_posiw = scra_h_posiw.w.h; /* Line 1064, Address: 0x101a754 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1065, Address: 0x101a760 */
  pMapWk = (unsigned char*)mapwka; /* Line 1066, Address: 0x101a76c */
  pScrFlag = &scrflagaw.b.h; /* Line 1067, Address: 0x101a774 */

  if (*pScrFlag) { /* Line 1069, Address: 0x101a77c */
    if (*pScrFlag & 1) { /* Line 1070, Address: 0x101a788 */
      *pScrFlag &= 254; /* Line 1071, Address: 0x101a79c */

      lD4.l = -16; /* Line 1073, Address: 0x101a7a8 */
      wD5 = 65520; /* Line 1074, Address: 0x101a7b0 */

      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1076, Address: 0x101a7b8 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1078, Address: 0x101a7d8 */
    }




    if (*pScrFlag & 2) { /* Line 1084, Address: 0x101a804 */
      *pScrFlag &= 253; /* Line 1085, Address: 0x101a818 */

      lD4.l = 224; /* Line 1087, Address: 0x101a824 */
      wD5 = 65520; /* Line 1088, Address: 0x101a82c */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1089, Address: 0x101a834 */

      hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1091, Address: 0x101a854 */
    }




    if (*pScrFlag & 4) { /* Line 1097, Address: 0x101a880 */
      *pScrFlag &= 251; /* Line 1098, Address: 0x101a894 */

      lD4.l = -16; /* Line 1100, Address: 0x101a8a0 */
      wD5 = 65520; /* Line 1101, Address: 0x101a8a8 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1102, Address: 0x101a8b0 */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1104, Address: 0x101a8d0 */
    }




    if (*pScrFlag & 8) { /* Line 1110, Address: 0x101a8fc */
      *pScrFlag &= 247; /* Line 1111, Address: 0x101a910 */

      lD4.l = -16; /* Line 1113, Address: 0x101a91c */
      wD5 = 320; /* Line 1114, Address: 0x101a924 */
      vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1115, Address: 0x101a92c */

      vblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 15); /* Line 1117, Address: 0x101a94c */
    }
  }






} /* Line 1126, Address: 0x101a978 */
















void scrollwrtb(unsigned char* pScrFlag, unsigned char* pMapWk, int VramBase) { /* Line 1143, Address: 0x101a9a0 */
  int_union lD4;
  int WrtTblCnt;
  unsigned short wD0;
  unsigned short wD5;
  unsigned short wH_posiw;
  unsigned short wV_posiw;
  POINT TilePoint;
  int BlkIndex;
  int i;

  lD4.l = -16; /* Line 1154, Address: 0x101a9cc */

  if (*pScrFlag & 1) { /* Line 1156, Address: 0x101a9d4 */
    *pScrFlag &= 254; /* Line 1157, Address: 0x101a9ec */
  } /* Line 1158, Address: 0x101aa00 */
  else {
    *pScrFlag &= 254; /* Line 1160, Address: 0x101aa08 */

    if (*pScrFlag & 2) { /* Line 1162, Address: 0x101aa1c */
      *pScrFlag &= 253; /* Line 1163, Address: 0x101aa34 */
      lD4.w.l = 224; /* Line 1164, Address: 0x101aa48 */
    } /* Line 1165, Address: 0x101aa50 */
    else {
      *pScrFlag &= 253; /* Line 1167, Address: 0x101aa58 */
      goto label1; /* Line 1168, Address: 0x101aa6c */
    }
  }


  wD0 = (short)(scrb_v_posit.w.h + lD4.w.l) / 16; /* Line 1173, Address: 0x101aa74 */
  wD0 &= 127; /* Line 1174, Address: 0x101aac4 */
  wD0 = z81awrttbl[wD0 + 1]; /* Line 1175, Address: 0x101aacc */





  wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1181, Address: 0x101aaec */
  wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1182, Address: 0x101ab0c */
  if (wD0 != 0) { /* Line 1183, Address: 0x101ab30 */
    wD5 = 65520; /* Line 1184, Address: 0x101ab3c */
    vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1185, Address: 0x101ab44 */

    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 21); /* Line 1187, Address: 0x101ab64 */



  } /* Line 1191, Address: 0x101ab90 */
  else {

    wD5 = 0; /* Line 1194, Address: 0x101ab98 */
    vramadrset1(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1195, Address: 0x101ab9c */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, 31); /* Line 1199, Address: 0x101abbc */
  }




label1:
  if (*pScrFlag != 0) { /* Line 1206, Address: 0x101abe8 */






    lD4.l = -16; /* Line 1213, Address: 0x101abfc */
    wD5 = 65520; /* Line 1214, Address: 0x101ac04 */
    if (*pScrFlag & 168) { /* Line 1215, Address: 0x101ac0c */
      *pScrFlag = (*pScrFlag & 168) >> 1; /* Line 1216, Address: 0x101ac24 */
      wD5 = 320; /* Line 1217, Address: 0x101ac44 */
    }


    WrtTblCnt = (unsigned short)(scrb_v_posit.w.h / 16); /* Line 1221, Address: 0x101ac4c */

    if (WrtTblCnt < 0) WrtTblCnt = 0; /* Line 1223, Address: 0x101ac7c */
    if (WrtTblCnt > 113) WrtTblCnt = 113; /* Line 1224, Address: 0x101ac88 */



    for (i = 0; i < 16; ++i) { /* Line 1228, Address: 0x101ac98 */
      wD0 = z81awrttbl[WrtTblCnt++]; /* Line 1229, Address: 0x101aca4 */
      if (wD0 != 0) { /* Line 1230, Address: 0x101acc4 */
        if (*pScrFlag & (unsigned char)(1 << wD0)) { /* Line 1231, Address: 0x101acd0 */
          wH_posiw = vblockwrtbtbl[wD0]->w.h; /* Line 1232, Address: 0x101acfc */
          wV_posiw = vblockwrtbtbl[wD0 + 1]->w.h; /* Line 1233, Address: 0x101ad1c */

          mapadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, pMapWk, &BlkIndex); /* Line 1235, Address: 0x101ad40 */


          vramadrset(wH_posiw, wV_posiw, wD5, lD4.w.l, &TilePoint); /* Line 1238, Address: 0x101ad64 */

          blockwrt(VramBase, &TilePoint, BlkIndex); /* Line 1240, Address: 0x101ad84 */
        }
      }
      lD4.w.l += 16; /* Line 1243, Address: 0x101ad98 */
    } /* Line 1244, Address: 0x101ada4 */
    *pScrFlag = 0; /* Line 1245, Address: 0x101adb4 */
  }
} /* Line 1247, Address: 0x101adbc */





void scrollwrtc() {} /* Line 1253, Address: 0x101adf0 */




void scrollwrtz() {} /* Line 1258, Address: 0x101ae00 */

















void hblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1276, Address: 0x101ae10 */
  int BlkIndex;










  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1289, Address: 0x101ae38 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1292, Address: 0x101ae58 */
    pTilePoint->x += 2; /* Line 1293, Address: 0x101ae6c */
    if (pTilePoint->x >= 64) { /* Line 1294, Address: 0x101ae80 */
      pTilePoint->x -= 64; /* Line 1295, Address: 0x101ae94 */
    }
    xOffs += 16; /* Line 1297, Address: 0x101aea8 */
  } while (--lpcnt >= 0); /* Line 1298, Address: 0x101aeb4 */
} /* Line 1299, Address: 0x101aec8 */



void hblockwrt1(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1303, Address: 0x101aee0 */
  int BlkIndex;

  do {
    mapadrset1(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1307, Address: 0x101af08 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1310, Address: 0x101af28 */
    pTilePoint->x += 2; /* Line 1311, Address: 0x101af3c */
    if (pTilePoint->x >= 64) { /* Line 1312, Address: 0x101af50 */
      pTilePoint->x -= 64; /* Line 1313, Address: 0x101af64 */
    }
    xOffs += 16; /* Line 1315, Address: 0x101af78 */
  } while (--lpcnt >= 0); /* Line 1316, Address: 0x101af84 */
} /* Line 1317, Address: 0x101af98 */



















void vblockwrt(POINT* pTilePoint, int VramBase, unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int lpcnt) { /* Line 1337, Address: 0x101afb0 */
  int BlkIndex;

  do {
    mapadrset(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, &BlkIndex); /* Line 1341, Address: 0x101afd8 */


    blockwrt(VramBase, pTilePoint, BlkIndex); /* Line 1344, Address: 0x101aff8 */
    pTilePoint->y += 2; /* Line 1345, Address: 0x101b00c */
    if (pTilePoint->y >= 32) { /* Line 1346, Address: 0x101b01c */
      pTilePoint->y -= 32; /* Line 1347, Address: 0x101b030 */
    }
    yOffs += 16; /* Line 1349, Address: 0x101b040 */
  } while (--lpcnt >= 0); /* Line 1350, Address: 0x101b04c */
} /* Line 1351, Address: 0x101b060 */


















void blockwrt(int VramBase, POINT* pTilePoint, int BlkIndex) { /* Line 1370, Address: 0x101b070 */
  int base = 0; /* Line 1371, Address: 0x101b0a4 */
  int frip;
  int p0, p1, p2, p3;
  int x, y;

  if (VramBase == 24576) { /* Line 1376, Address: 0x101b0a8 */

    base = 1; /* Line 1378, Address: 0x101b0b8 */
  } /* Line 1379, Address: 0x101b0bc */
  else if (VramBase == 16384) { /* Line 1380, Address: 0x101b0c4 */

    base = 0; /* Line 1382, Address: 0x101b0d4 */
  }
  x = pTilePoint->x; /* Line 1384, Address: 0x101b0d8 */
  y = pTilePoint->y; /* Line 1385, Address: 0x101b0e0 */


  frip = BlkIndex & 6144; /* Line 1388, Address: 0x101b0e8 */
  BlkIndex &= 1023; /* Line 1389, Address: 0x101b0f0 */
  if (frip == 6144) { /* Line 1390, Address: 0x101b0fc */

    p0 = 3, p1 = 2; /* Line 1392, Address: 0x101b108 */
    p2 = 1, p3 = 0; /* Line 1393, Address: 0x101b110 */
  } /* Line 1394, Address: 0x101b118 */
  else if (frip & 4096) { /* Line 1395, Address: 0x101b120 */

    p0 = 2, p1 = 3; /* Line 1397, Address: 0x101b12c */
    p2 = 0, p3 = 1; /* Line 1398, Address: 0x101b134 */
  } /* Line 1399, Address: 0x101b13c */
  else if (frip & 2048) { /* Line 1400, Address: 0x101b144 */

    p0 = 1, p1 = 0; /* Line 1402, Address: 0x101b150 */
    p2 = 3, p3 = 2; /* Line 1403, Address: 0x101b158 */
  } /* Line 1404, Address: 0x101b160 */
  else {

    p0 = 0, p1 = 1; /* Line 1407, Address: 0x101b168 */
    p2 = 2, p3 = 3; /* Line 1408, Address: 0x101b170 */
  }

  SetGrid(base, x, y, blockwk[BlkIndex][p0], frip); /* Line 1411, Address: 0x101b178 */
  SetGrid(base, x + 1, y, blockwk[BlkIndex][p1], frip); /* Line 1412, Address: 0x101b1bc */
  SetGrid(base, x, y + 1, blockwk[BlkIndex][p2], frip); /* Line 1413, Address: 0x101b200 */
  SetGrid(base, x + 1, y + 1, blockwk[BlkIndex][p3], frip); /* Line 1414, Address: 0x101b244 */

} /* Line 1416, Address: 0x101b288 */

















int mapadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1434, Address: 0x101b2c0 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1435, Address: 0x101b2e0 */
} /* Line 1436, Address: 0x101b300 */

int mapadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1438, Address: 0x101b310 */
  wH_posiw = 0; /* Line 1439, Address: 0x101b330 */
  mapadrset99(wH_posiw, wV_posiw, xOffs, yOffs, pMapWk, pIndex); /* Line 1440, Address: 0x101b334 */
} /* Line 1441, Address: 0x101b354 */






int mapadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex) { /* Line 1448, Address: 0x101b370 */
  int xBlk, yBlk;
  int i;
  unsigned char ScreenNo;
  unsigned short* lpw;

  xOffs += wH_posiw; /* Line 1454, Address: 0x101b3a0 */
  yOffs += wV_posiw; /* Line 1455, Address: 0x101b3b0 */





  if ((short)xOffs < 0) /* Line 1461, Address: 0x101b3c0 */
    xOffs = 0; /* Line 1462, Address: 0x101b3dc */
  if ((short)yOffs < 0) /* Line 1463, Address: 0x101b3e0 */
    yOffs = 0; /* Line 1464, Address: 0x101b3fc */
  if ((short)xOffs >= 16384) /* Line 1465, Address: 0x101b400 */
    xOffs = 16383; /* Line 1466, Address: 0x101b420 */
  if ((short)yOffs >= 2048) /* Line 1467, Address: 0x101b428 */
    yOffs = 2047; /* Line 1468, Address: 0x101b448 */
  i = xOffs / 256 + yOffs / 256 * 64; /* Line 1469, Address: 0x101b450 */
  if (i < 0) i = 0; /* Line 1470, Address: 0x101b498 */

  ScreenNo = pMapWk[i] & 127; /* Line 1472, Address: 0x101b4a4 */

  if (ScreenNo) { /* Line 1474, Address: 0x101b4c0 */




    xOffs &= 32767; /* Line 1479, Address: 0x101b4c8 */
    yOffs &= 32767; /* Line 1480, Address: 0x101b4d4 */


    xBlk = xOffs; /* Line 1483, Address: 0x101b4e0 */
    xBlk %= 256; /* Line 1484, Address: 0x101b4e8 */
    xBlk /= 16; /* Line 1485, Address: 0x101b508 */
    yBlk = yOffs; /* Line 1486, Address: 0x101b524 */
    yBlk %= 256; /* Line 1487, Address: 0x101b52c */
    yBlk /= 16; /* Line 1488, Address: 0x101b54c */

    lpw = pmapwk; /* Line 1490, Address: 0x101b568 */
    lpw += xBlk; /* Line 1491, Address: 0x101b570 */
    lpw += yBlk * 16; /* Line 1492, Address: 0x101b578 */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1493, Address: 0x101b584 */
    *pIndex = *lpw; /* Line 1494, Address: 0x101b59c */

    return 1; /* Line 1496, Address: 0x101b5ac */
  }

  *pIndex = 0; /* Line 1499, Address: 0x101b5b8 */
  return 0; /* Line 1500, Address: 0x101b5c0 */
} /* Line 1501, Address: 0x101b5c4 */



















int mapadrset2(unsigned short xOffs, unsigned short yOffs, unsigned char* pMapWk, int* pIndex, unsigned short** ppBlockNo) { /* Line 1521, Address: 0x101b5f0 */
  int xBlk;
  int yBlk;
  unsigned char ScreenNo;
  unsigned short* lpw;



  ScreenNo = pMapWk[xOffs / 256 + yOffs / 256 * 64] & 127; /* Line 1529, Address: 0x101b618 */
  if (ScreenNo) { /* Line 1530, Address: 0x101b67c */





    xBlk = xOffs; /* Line 1536, Address: 0x101b684 */
    xBlk %= 256; /* Line 1537, Address: 0x101b68c */
    xBlk /= 16; /* Line 1538, Address: 0x101b6ac */
    yBlk = yOffs; /* Line 1539, Address: 0x101b6c8 */
    yBlk %= 256; /* Line 1540, Address: 0x101b6d0 */
    yBlk /= 16; /* Line 1541, Address: 0x101b6f0 */


    lpw = pmapwk; /* Line 1544, Address: 0x101b70c */
    lpw += xBlk; /* Line 1545, Address: 0x101b714 */
    lpw += yBlk * 16; /* Line 1546, Address: 0x101b71c */
    lpw += (ScreenNo - 1) * 16 * 16; /* Line 1547, Address: 0x101b728 */
    *ppBlockNo = lpw; /* Line 1548, Address: 0x101b740 */
    *pIndex = *lpw; /* Line 1549, Address: 0x101b748 */




    return 1; /* Line 1554, Address: 0x101b758 */
  }

  *pIndex = 0; /* Line 1557, Address: 0x101b764 */
  return 0; /* Line 1558, Address: 0x101b76c */
} /* Line 1559, Address: 0x101b770 */













void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs) { /* Line 1573, Address: 0x101b790 */
  int VramBase;
  POINT TilePoint;
  unsigned char* pMapWk;
  unsigned short* pBlockIndex;
  int Index;

  VramBase = 16384; /* Line 1580, Address: 0x101b7ac */
  pMapWk = (unsigned char*)mapwka; /* Line 1581, Address: 0x101b7b0 */
  if (mapadrset2(xOffs, yOffs, pMapWk, &Index, &pBlockIndex) != 0) { /* Line 1582, Address: 0x101b7b8 */
    *pBlockIndex = BlockNo; /* Line 1583, Address: 0x101b7dc */
    if (block_chk(xOffs, yOffs) == 0) { /* Line 1584, Address: 0x101b7e8 */
      vramadrset0(xOffs, yOffs, &TilePoint); /* Line 1585, Address: 0x101b800 */
      blockwrt(VramBase, &TilePoint, BlockNo); /* Line 1586, Address: 0x101b814 */
    }
  }


} /* Line 1591, Address: 0x101b82c */













int block_chk(unsigned short xOffs, unsigned short yOffs) { /* Line 1605, Address: 0x101b850 */
  if ((scra_v_posit.w.h & 65520) - 16 > yOffs) { /* Line 1606, Address: 0x101b85c */
    if ((short)(scra_v_posit.w.h + 240 & 65520) - 16 <= (short)yOffs) { /* Line 1607, Address: 0x101b888 */
      if ((scra_h_posit.w.h & 65520) - 16 > xOffs) { /* Line 1608, Address: 0x101b8d4 */
        if ((short)(scra_v_posit.w.h + 336 & 65520) - 16 <= (short)xOffs) { /* Line 1609, Address: 0x101b900 */

          return 0; /* Line 1611, Address: 0x101b94c */
        }
      }
    }
  }

  return 1; /* Line 1617, Address: 0x101b958 */
} /* Line 1618, Address: 0x101b95c */
















void vramadrset(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1635, Address: 0x101b970 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1636, Address: 0x101b98c */

} /* Line 1638, Address: 0x101b9a8 */

void vramadrset1(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1640, Address: 0x101b9c0 */
  wH_posiw = 0; /* Line 1641, Address: 0x101b9dc */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1642, Address: 0x101b9e0 */

} /* Line 1644, Address: 0x101b9fc */

void vramadrset0(unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1646, Address: 0x101ba10 */
  vramadrset99(0, 0, xOffs, yOffs, lpTilePoint); /* Line 1647, Address: 0x101ba24 */

} /* Line 1649, Address: 0x101ba40 */

void vramadrset2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1651, Address: 0x101ba50 */
  vramadrset99(wH_posiw, wV_posiw, xOffs, yOffs, lpTilePoint); /* Line 1652, Address: 0x101ba6c */

} /* Line 1654, Address: 0x101ba88 */

void vramadrset99(unsigned short wH_posiw, unsigned short wV_posiw, unsigned short xOffs, unsigned short yOffs, POINT* lpTilePoint) { /* Line 1656, Address: 0x101baa0 */
  xOffs += wH_posiw; /* Line 1657, Address: 0x101bab8 */
  yOffs += wV_posiw; /* Line 1658, Address: 0x101bac8 */
  yOffs &= 240; /* Line 1659, Address: 0x101bad8 */
  xOffs &= 496; /* Line 1660, Address: 0x101bae4 */

  lpTilePoint->x = xOffs / 16 * 2; /* Line 1662, Address: 0x101baf0 */
  lpTilePoint->y = yOffs / 16 * 2; /* Line 1663, Address: 0x101bb1c */


} /* Line 1666, Address: 0x101bb48 */















void mapwrt() { /* Line 1682, Address: 0x101bb60 */
  int VramBase;
  unsigned short wH_posiw, wV_posiw;
  unsigned char* pMapWk;

  wH_posiw = scra_h_posiw.w.h; /* Line 1687, Address: 0x101bb78 */
  wV_posiw = scra_v_posiw.w.h; /* Line 1688, Address: 0x101bb84 */
  pMapWk = (unsigned char*)mapwka; /* Line 1689, Address: 0x101bb90 */
  VramBase = 16384; /* Line 1690, Address: 0x101bb98 */
  mapwrt2(wH_posiw, wV_posiw, pMapWk, VramBase); /* Line 1691, Address: 0x101bb9c */



  pMapWk = (unsigned char*)mapwkb; /* Line 1695, Address: 0x101bbb4 */
  VramBase = 24576; /* Line 1696, Address: 0x101bbbc */
  mapwrt_z81a(pMapWk, VramBase); /* Line 1697, Address: 0x101bbc0 */

} /* Line 1699, Address: 0x101bbd0 */


void mapwrt2(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase) { /* Line 1702, Address: 0x101bbf0 */
  mapwrt3(wH_posiw, wV_posiw, pMapWk, VramBase, 65520, 15); /* Line 1703, Address: 0x101bc08 */
} /* Line 1704, Address: 0x101bc28 */




void mapwrt3(unsigned short wH_posiw, unsigned short wV_posiw, unsigned char* pMapWk, int VramBase, unsigned short wD4, unsigned short wD6) { /* Line 1709, Address: 0x101bc40 */
  POINT TilePoint;

  do {
    vramadrset(wH_posiw, wV_posiw, 0, wD4, &TilePoint); /* Line 1713, Address: 0x101bc60 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, 0, wD4, pMapWk, 31); /* Line 1716, Address: 0x101bc7c */



    wD4 += 16; /* Line 1720, Address: 0x101bca4 */
  } while ((short)--wD6 >= 0); /* Line 1721, Address: 0x101bcb0 */

} /* Line 1723, Address: 0x101bcd8 */





void mapwrt_z81a(unsigned char* pMapWk, int VramBase) { /* Line 1729, Address: 0x101bcf0 */
  unsigned short wD0, wD4, wD6;
  int_union temp;
  uint_union temp2;

  wD4 = 65520; /* Line 1734, Address: 0x101bd0c */
  wD6 = 15; /* Line 1735, Address: 0x101bd14 */

  do {
    temp.l = 0; /* Line 1738, Address: 0x101bd1c */
    temp.w.l = scrb_v_posit.w.h; /* Line 1739, Address: 0x101bd20 */
    wD0 = scrb_v_posit.w.h; /* Line 1740, Address: 0x101bd2c */
    if ((long int)temp.l >= 512) { /* Line 1741, Address: 0x101bd38 */


      wD0 -= 512; /* Line 1744, Address: 0x101bd50 */
      temp2.l = 0; /* Line 1745, Address: 0x101bd58 */
      temp2.w.l = wD0; /* Line 1746, Address: 0x101bd5c */
      temp2.l = (unsigned int)temp2.l >> 16 & 65535 | temp2.l << 16 & -65536; /* Line 1747, Address: 0x101bd60 */
      temp2.l >>= 2; /* Line 1748, Address: 0x101bd84 */
      temp2.l *= 3; /* Line 1749, Address: 0x101bd90 */
      temp2.l += 0x2000000; /* Line 1750, Address: 0x101bda0 */
      temp2.l = (unsigned int)temp2.l >> 16 & 65535 | temp2.l << 16 & -65536; /* Line 1751, Address: 0x101bdb0 */
      wD0 = temp2.w.l; /* Line 1752, Address: 0x101bdd4 */
    } /* Line 1753, Address: 0x101bddc */
    else {

      temp.l = 0; /* Line 1756, Address: 0x101bde4 */
      temp.w.l = scra_h_posit.w.h; /* Line 1757, Address: 0x101bde8 */
      if ((long int)temp.l >= 640) { /* Line 1758, Address: 0x101bdf4 */
        wD0 = 512; /* Line 1759, Address: 0x101be0c */
      }
    }
    wD0 += wD4; /* Line 1762, Address: 0x101be14 */
    wD0 &= 2032; /* Line 1763, Address: 0x101be1c */

    mapwrt_sub(&z81awrttbl[1], wD0, wD4, pMapWk, VramBase); /* Line 1765, Address: 0x101be24 */
    wD4 += 16; /* Line 1766, Address: 0x101be44 */
  } while ((short)--wD6 >= 0); /* Line 1767, Address: 0x101be4c */
} /* Line 1768, Address: 0x101be70 */

























void mapwrt_sub(unsigned char* pWrttbl, unsigned short wD0, unsigned short wD4, unsigned char* pMapWk, int VramBase) { /* Line 1794, Address: 0x101be90 */
  POINT TilePoint;
  unsigned short wH_posiw, wV_posiw;
  unsigned short wD5;

  wD0 /= 16; /* Line 1799, Address: 0x101beb8 */
  wD0 = pWrttbl[wD0]; /* Line 1800, Address: 0x101bec8 */

  wH_posiw = mapwrt_tbl[wD0]->w.h; /* Line 1802, Address: 0x101bee4 */
  wV_posiw = mapwrt_tbl[wD0 + 1]->w.h; /* Line 1803, Address: 0x101bf08 */
  if (wD0) { /* Line 1804, Address: 0x101bf30 */
    wD5 = 65520; /* Line 1805, Address: 0x101bf3c */
    vramadrset(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1806, Address: 0x101bf44 */


    hblockwrt(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 21); /* Line 1809, Address: 0x101bf60 */



  } /* Line 1813, Address: 0x101bf88 */
  else {

    wD5 = 0; /* Line 1816, Address: 0x101bf90 */
    vramadrset1(wH_posiw, wV_posiw, wD5, wD4, &TilePoint); /* Line 1817, Address: 0x101bf94 */



    hblockwrt1(&TilePoint, VramBase, wH_posiw, wV_posiw, wD5, wD4, pMapWk, 31); /* Line 1821, Address: 0x101bfb0 */
  }





} /* Line 1828, Address: 0x101bfd8 */



void mapinit() { /* Line 1832, Address: 0x101c000 */

  colorset2(mapinittbl.colorno2); /* Line 1834, Address: 0x101c008 */
  colorset(mapinittbl.colorno2); /* Line 1835, Address: 0x101c01c */

  if (plflag) enecginit(); /* Line 1837, Address: 0x101c030 */
  if (play_start & 2) divdevset(); /* Line 1838, Address: 0x101c048 */
} /* Line 1839, Address: 0x101c068 */










void mapset() {} /* Line 1850, Address: 0x101c080 */
