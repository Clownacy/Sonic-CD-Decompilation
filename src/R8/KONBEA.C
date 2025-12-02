#include "..\EQU.H"
#include "KONBEA.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"
#include "..\PLAYSUB.H"

static void a_init(sprite_status* pActwk);
static void a_init_sub(sprite_status* pActwk, sprite_status* pNewact);
static void a_stop(sprite_status* pActwk);
static void a_stop1(sprite_status* pActwk);
static void a_move(sprite_status* pActwk);
static void move_version(sprite_status* pActwk);
static void b_init(sprite_status* pActwk);
static void b_init_sub(sprite_status* pActwk, sprite_status* pNewact);
static void b_stop(sprite_status* pActwk);
static void b_stop1(sprite_status* pActwk);
static void b_roll(sprite_status* pActwk);
static void b_move(sprite_status* pActwk);

char konbea8tbl[892] = {
  0, 26,
  -1, 25,
  -2, 25,
  -3, 24,
  -4, 24,
  -5, 23,
  -6, 23,
  -7, 22,
  -8, 22,
  -9, 21,
  -10, 21,
  -11, 20,
  -12, 20,
  -13, 19,
  -14, 19,
  -15, 18,
  -16, 18,
  -17, 17,
  -18, 17,
  -19, 16,
  -20, 16,
  -21, 15,
  -22, 15,
  -23, 14,
  -24, 14,
  -25, 13,
  -26, 13,
  -27, 12,
  -28, 12,
  -29, 11,
  -30, 11,
  -31, 10,
  -32, 10,
  -33, 9,
  -34, 9,
  -35, 8,
  -36, 8,
  -37, 7,
  -38, 7,
  -39, 6,
  -40, 6,
  -41, 5,
  -42, 5,
  -43, 4,
  -44, 4,
  -45, 3,
  -46, 3,
  -47, 2,
  -48, 2,
  -49, 1,
  -50, 1,
  -51, 0,
  -52, 0,
  -53, -1,
  -54, -1,
  -55, -2,
  -56, -2,
  -57, -3,
  -58, -3,
  -59, -4,
  -60, -4,
  -61, -5,
  -62, -5,
  -63, -6,
  -64, -6,
  -65, -7,
  -66, -7,
  -67, -8,
  -68, -8,
  -69, -9,
  -70, -9,
  -71, -10,
  -72, -10,
  -73, -11,
  -74, -11,
  -75, -12,
  -76, -12,
  -77, -13,
  -78, -13,
  -79, -14,
  -80, -14,
  -81, -15,
  -82, -15,
  -83, -16,
  -84, -16,
  -85, -17,
  -86, -17,
  -87, -18,
  -88, -18,
  -89, -19,
  -90, -19,
  -91, -20,
  -92, -21,
  -93, -22,
  -94, -23,
  -95, -24,
  -96, -25,
  -97, -26,
  -98, -27,
  -99, -28,
  -99, -29,
  -100, -30,
  -100, -31,
  -100, -32,
  -101, -33,
  -101, -34,
  -101, -35,
  -102, -36,
  -102, -37,
  -102, -38,
  -102, -39,
  -102, -40,
  -102, -41,
  -102, -42,
  -102, -43,
  -102, -44,
  -102, -45,
  -101, -46,
  -101, -47,
  -101, -48,
  -100, -49,
  -100, -50,
  -100, -51,
  -99, -52,
  -98, -53,
  -98, -54,
  -97, -55,
  -96, -56,
  -95, -57,
  -94, -58,
  -93, -59,
  -92, -60,
  -91, -60,
  -90, -61,
  -89, -61,
  -88, -61,
  -87, -62,
  -86, -62,
  -85, -62,
  -84, -63,
  -83, -63,
  -82, -63,
  -81, -63,
  -80, -63,
  -79, -63,
  -78, -63,
  -77, -63,
  -76, -63,
  -75, -63,
  -74, -63,
  -73, -63,
  -72, -62,
  -71, -62,
  -70, -62,
  -69, -61,
  -68, -61,
  -67, -60,
  -66, -60,
  -65, -59,
  -64, -59,
  -63, -58,
  -62, -58,
  -61, -57,
  -60, -57,
  -59, -56,
  -58, -56,
  -57, -55,
  -56, -55,
  -55, -54,
  -54, -54,
  -53, -53,
  -52, -53,
  -51, -52,
  -50, -52,
  -49, -51,
  -48, -51,
  -47, -50,
  -46, -50,
  -45, -49,
  -44, -49,
  -43, -48,
  -42, -48,
  -41, -47,
  -40, -47,
  -39, -46,
  -38, -46,
  -37, -45,
  -36, -45,
  -35, -44,
  -34, -44,
  -33, -43,
  -32, -43,
  -31, -42,
  -30, -42,
  -29, -41,
  -28, -41,
  -27, -40,
  -26, -40,
  -25, -39,
  -24, -39,
  -23, -38,
  -22, -38,
  -21, -37,
  -20, -37,
  -19, -36,
  -18, -36,
  -17, -35,
  -16, -35,
  -15, -34,
  -14, -34,
  -13, -33,
  -12, -33,
  -11, -32,
  -10, -32,
  -9, -31,
  -8, -31,
  -7, -30,
  -6, -30,
  -5, -29,
  -4, -29,
  -3, -28,
  -2, -28,
  -1, -27,
  0, -26,
  1, -25,
  2, -25,
  3, -24,
  4, -24,
  5, -23,
  6, -23,
  7, -22,
  8, -22,
  9, -21,
  10, -21,
  11, -20,
  12, -20,
  13, -19,
  14, -19,
  15, -18,
  16, -18,
  17, -17,
  18, -17,
  19, -16,
  20, -16,
  21, -15,
  22, -15,
  23, -14,
  24, -14,
  25, -13,
  26, -13,
  27, -12,
  28, -12,
  29, -11,
  30, -11,
  31, -10,
  32, -10,
  33, -9,
  34, -9,
  35, -8,
  36, -8,
  37, -7,
  38, -7,
  39, -6,
  40, -6,
  41, -5,
  42, -5,
  43, -4,
  44, -4,
  45, -3,
  46, -3,
  47, -2,
  48, -2,
  49, -1,
  50, -1,
  51, 0,
  52, 0,
  53, 1,
  54, 1,
  55, 2,
  56, 2,
  57, 3,
  58, 3,
  59, 4,
  60, 4,
  61, 5,
  62, 5,
  63, 6,
  64, 6,
  65, 7,
  66, 7,
  67, 8,
  68, 8,
  69, 9,
  70, 9,
  71, 10,
  72, 10,
  73, 11,
  74, 11,
  75, 12,
  76, 12,
  77, 13,
  78, 13,
  79, 14,
  80, 14,
  81, 15,
  82, 15,
  83, 16,
  84, 16,
  85, 17,
  86, 17,
  87, 18,
  88, 18,
  89, 19,
  90, 19,
  91, 20,
  92, 21,
  93, 22,
  94, 23,
  95, 24,
  96, 25,
  97, 26,
  98, 27,
  99, 28,
  99, 29,
  100, 30,
  100, 31,
  100, 32,
  101, 33,
  101, 34,
  101, 35,
  102, 36,
  102, 37,
  102, 38,
  102, 39,
  102, 40,
  102, 41,
  102, 42,
  102, 43,
  102, 44,
  102, 45,
  101, 46,
  101, 47,
  101, 48,
  100, 49,
  100, 50,
  100, 51,
  99, 52,
  98, 53,
  98, 54,
  97, 55,
  96, 56,
  95, 57,
  94, 58,
  93, 59,
  92, 60,
  91, 60,
  90, 61,
  89, 61,
  88, 61,
  87, 62,
  86, 62,
  85, 62,
  84, 63,
  83, 63,
  82, 63,
  81, 63,
  80, 63,
  79, 63,
  78, 63,
  77, 63,
  76, 63,
  75, 63,
  74, 63,
  73, 63,
  72, 62,
  71, 62,
  70, 62,
  69, 61,
  68, 61,
  67, 60,
  66, 60,
  65, 59,
  64, 59,
  63, 58,
  62, 58,
  61, 57,
  60, 57,
  59, 56,
  58, 56,
  57, 55,
  56, 55,
  55, 54,
  54, 54,
  53, 53,
  52, 53,
  51, 52,
  50, 52,
  49, 51,
  48, 51,
  47, 50,
  46, 50,
  45, 49,
  44, 49,
  43, 48,
  42, 48,
  41, 47,
  40, 47,
  39, 46,
  38, 46,
  37, 45,
  36, 45,
  35, 44,
  34, 44,
  33, 43,
  32, 43,
  31, 42,
  30, 42,
  29, 41,
  28, 41,
  27, 40,
  26, 40,
  25, 39,
  24, 39,
  23, 38,
  22, 38,
  21, 37,
  20, 37,
  19, 36,
  18, 36,
  17, 35,
  16, 35,
  15, 34,
  14, 34,
  13, 33,
  12, 33,
  11, 32,
  10, 32,
  9, 31,
  8, 31,
  7, 30,
  6, 30,
  5, 29,
  4, 29,
  3, 28,
  2, 28,
  1, 27
};
static short a_tbl_00[2] = { 60, 0 };
static short a_tbl_01[5] = { 60, 1, 60, 32, 0 };
static short* a_tbl0[2] = {
  a_tbl_00,
  a_tbl_01
};
static unsigned char pchg_00[14] = { 1, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 0, 255 };
static unsigned char* pchg[1] = { pchg_00 };
static sprite_pattern pat_00 = {
  1,
  { { -16, -8, 0, 408 } }
};
static sprite_pattern pat_01 = {
  1,
  { { -16, -12, 0, 409 } }
};
static sprite_pattern pat_02 = {
  1,
  { { -12, -16, 0, 410 } }
};
static sprite_pattern pat_03 = {
  1,
  { { -8, -16, 0, 411 } }
};
static sprite_pattern pat_04 = {
  1,
  { { -12, -16, 0, 412 } }
};
static sprite_pattern pat_05 = {
  1,
  { { -16, -12, 0, 413 } }
};
sprite_pattern* pat_konbea[7] = {
  &pat_00,
  &pat_01,
  &pat_02,
  &pat_03,
  &pat_04,
  &pat_05,
  &pat_00
};
static void(*a_act_tbl[4])(sprite_status*) = {
  &a_init,
  &a_stop,
  &a_stop1,
  &a_move
};
static void(*b_act_tbl[4])(sprite_status*) = {
  &b_init,
  &b_stop,
  &b_stop1,
  &b_roll
};






















































































void konbea(sprite_status* pActwk) { /* Line 608, Address: 0x101fb90 */
  sprite_status* pMainwk;

  if (!pActwk->userflag.b.h) { /* Line 611, Address: 0x101fba0 */

    if (pActwk->userflag.b.l) { /* Line 613, Address: 0x101fbb0 */
      pMainwk = &actwk[((short*)pActwk)[23]]; /* Line 614, Address: 0x101fbc0 */

      if (pMainwk->actno != 42) { /* Line 616, Address: 0x101fbe8 */
        frameout(pActwk); return; /* Line 617, Address: 0x101fbfc */
      }

      if (((short*)pActwk)[25] != ((short*)pMainwk)[25]) { /* Line 620, Address: 0x101fc10 */

        frameout(pActwk); return; /* Line 622, Address: 0x101fc34 */
      }

      if (((short*)pActwk)[26] != ((short*)pMainwk)[26]) { /* Line 625, Address: 0x101fc48 */

        frameout(pActwk); return; /* Line 627, Address: 0x101fc6c */
      }
    }


    a_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 632, Address: 0x101fc80 */
    actionsub(pActwk); /* Line 633, Address: 0x101fcc4 */

    if (!(pActwk->userflag.b.l & 128)) { /* Line 635, Address: 0x101fcd0 */
      frameout_s00(pActwk, ((short*)pActwk)[25]); /* Line 636, Address: 0x101fcec */
    }


  } /* Line 640, Address: 0x101fd00 */
  else {
    move_version(pActwk); /* Line 642, Address: 0x101fd08 */
  }
} /* Line 644, Address: 0x101fd14 */





static void a_init(sprite_status* pActwk) { /* Line 650, Address: 0x101fd30 */
  short *pTbl, i;
  sprite_status* pNewact;

  pTbl = a_tbl0[pActwk->userflag.b.l]; /* Line 654, Address: 0x101fd44 */

  ((short*)pActwk)[24] = *pTbl++; /* Line 656, Address: 0x101fd68 */
  pNewact = pActwk; /* Line 657, Address: 0x101fd7c */
  a_init_sub(pActwk, pNewact); /* Line 658, Address: 0x101fd84 */

  for (i = *pTbl++ - 1; i >= 0; --i) { /* Line 660, Address: 0x101fd94 */

    if (actwkchk(&pNewact) != 0) { /* Line 662, Address: 0x101fdc4 */
      frameout(pActwk); /* Line 663, Address: 0x101fdd8 */
      break; /* Line 664, Address: 0x101fde4 */
    }


    pNewact->actno = pActwk->actno; /* Line 668, Address: 0x101fdec */
    ((short*)pNewact)[23] = pActwk - actwk; /* Line 669, Address: 0x101fdfc */
    pNewact->userflag.b.h = pActwk->userflag.b.h; /* Line 670, Address: 0x101fe34 */
    pNewact->userflag.b.l = -1; /* Line 671, Address: 0x101fe44 */
    ((short*)pNewact)[24] = *pTbl++; /* Line 672, Address: 0x101fe50 */
    pNewact->xposi.w.h = pActwk->xposi.w.h + *pTbl++; /* Line 673, Address: 0x101fe64 */
    pNewact->yposi.w.h = pActwk->yposi.w.h + *pTbl++; /* Line 674, Address: 0x101fe9c */
    a_init_sub(pActwk, pNewact); /* Line 675, Address: 0x101fed4 */
  } /* Line 676, Address: 0x101fee4 */
} /* Line 677, Address: 0x101ff00 */





static void a_init_sub(sprite_status* pActwk, sprite_status* pNewact) { /* Line 683, Address: 0x101ff20 */
  pNewact->r_no0 = 2; /* Line 684, Address: 0x101ff2c */
  pNewact->actflg |= 4; /* Line 685, Address: 0x101ff38 */
  pNewact->sprpri = 3; /* Line 686, Address: 0x101ff48 */
  pNewact->sprhs = pNewact->sprhsize = 16; /* Line 687, Address: 0x101ff54 */
  pNewact->sprvsize = 5; /* Line 688, Address: 0x101ff6c */
  pNewact->sproffset = 844; /* Line 689, Address: 0x101ff78 */
  pNewact->patbase = pat_konbea; /* Line 690, Address: 0x101ff84 */
  ((short*)pNewact)[25] = pActwk->xposi.w.h; /* Line 691, Address: 0x101ff94 */
  ((short*)pNewact)[26] = pActwk->yposi.w.h; /* Line 692, Address: 0x101ffa4 */
} /* Line 693, Address: 0x101ffb4 */





static void a_stop(sprite_status* pActwk) { /* Line 699, Address: 0x101ffc0 */
  pActwk->sprvsize = 5; /* Line 700, Address: 0x101ffcc */
  ((short*)pActwk)[24] = 120; /* Line 701, Address: 0x101ffd8 */
  pActwk->r_no0 += 2; /* Line 702, Address: 0x101ffe4 */
  a_stop1(pActwk); /* Line 703, Address: 0x101fff4 */
} /* Line 704, Address: 0x1020000 */





static void a_stop1(sprite_status* pActwk) { /* Line 710, Address: 0x1020010 */
  if (ridechk(pActwk, &actwk[0])) { /* Line 711, Address: 0x102001c */
    pActwk->actfree[20] = 255; /* Line 712, Address: 0x1020038 */
  } else { /* Line 713, Address: 0x1020044 */
    pActwk->actfree[20] = 0; /* Line 714, Address: 0x102004c */
  }

  if (!(--((short*)pActwk)[24])) { /* Line 717, Address: 0x1020054 */
    pActwk->sprvsize = 16; /* Line 718, Address: 0x1020074 */
    pActwk->mstno.w = 255; /* Line 719, Address: 0x1020080 */
    pActwk->r_no0 += 2; /* Line 720, Address: 0x102008c */

    if (pActwk->actfree[20]) { /* Line 722, Address: 0x102009c */
      ride_on_clr(pActwk, &actwk[0]); /* Line 723, Address: 0x10200ac */
    }
  }




} /* Line 730, Address: 0x10200c0 */





static void a_move(sprite_status* pActwk) { /* Line 736, Address: 0x10200d0 */
  patchg(pActwk, pchg); /* Line 737, Address: 0x10200dc */

  if (!pActwk->patno) { /* Line 739, Address: 0x10200f0 */
    pActwk->r_no0 = 2; /* Line 740, Address: 0x1020100 */
  }


} /* Line 744, Address: 0x102010c */














































static void move_version(sprite_status* pActwk) { /* Line 791, Address: 0x1020120 */
  sprite_status* pMainwk;

  if (pActwk->userflag.b.l) { /* Line 794, Address: 0x1020130 */
    pMainwk = &actwk[((short*)pActwk)[23]]; /* Line 795, Address: 0x1020140 */

    if (pMainwk->actno != 42) { /* Line 797, Address: 0x1020168 */
      frameout(pActwk); return; /* Line 798, Address: 0x102017c */
    }

    if (((short*)pActwk)[24] != ((short*)pMainwk)[24]) { /* Line 801, Address: 0x1020190 */

      frameout(pActwk); return; /* Line 803, Address: 0x10201b4 */
    }

    if (((short*)pActwk)[25] != ((short*)pMainwk)[25]) { /* Line 806, Address: 0x10201c8 */

      frameout(pActwk); return; /* Line 808, Address: 0x10201ec */
    }
  }


  b_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 813, Address: 0x1020200 */
  actionsub(pActwk); /* Line 814, Address: 0x1020244 */

  if (!(pActwk->userflag.b.l & 128)) { /* Line 816, Address: 0x1020250 */
    frameout_s00(pActwk, ((short*)pActwk)[24]); /* Line 817, Address: 0x102026c */
  }


} /* Line 821, Address: 0x1020280 */





static void b_init(sprite_status* pActwk) { /* Line 827, Address: 0x10202a0 */
  sprite_status* pNewact;
  int lp;
  short wk1, wk2;

  pNewact = pActwk; /* Line 832, Address: 0x10202b8 */
  b_init_sub(pActwk, pNewact); /* Line 833, Address: 0x10202c0 */

  wk1 = wk2 = 89; /* Line 835, Address: 0x10202d0 */
  for (lp = 3; lp >= 0; --lp) { /* Line 836, Address: 0x10202ec */

    if (actwkchk(&pNewact) != 0) { /* Line 838, Address: 0x10202f8 */
      frameout_s(pActwk); /* Line 839, Address: 0x102030c */
      return; /* Line 840, Address: 0x1020318 */
    }


    pNewact->actno = pActwk->actno; /* Line 844, Address: 0x1020320 */
    ((short*)pNewact)[23] = pActwk - actwk; /* Line 845, Address: 0x1020330 */
    pNewact->userflag.b.h = pActwk->userflag.b.h; /* Line 846, Address: 0x1020368 */
    pNewact->userflag.b.l = -1; /* Line 847, Address: 0x1020378 */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 848, Address: 0x1020384 */
    pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 849, Address: 0x1020394 */
    ((short*)pNewact)[28] = wk2; /* Line 850, Address: 0x10203a4 */
    wk2 += wk1; /* Line 851, Address: 0x10203ac */
    b_init_sub(pActwk, pNewact); /* Line 852, Address: 0x10203b8 */
  } /* Line 853, Address: 0x10203c8 */
} /* Line 854, Address: 0x10203d4 */





static void b_init_sub(sprite_status* pActwk, sprite_status* pNewact) { /* Line 860, Address: 0x10203f0 */
  pNewact->r_no0 = 2; /* Line 861, Address: 0x10203fc */
  pNewact->actflg |= 4; /* Line 862, Address: 0x1020408 */
  pNewact->sprpri = 3; /* Line 863, Address: 0x1020418 */
  pNewact->sprhs = pNewact->sprhsize = 16; /* Line 864, Address: 0x1020424 */
  pNewact->sprvsize = 5; /* Line 865, Address: 0x102043c */
  pNewact->sproffset = 844; /* Line 866, Address: 0x1020448 */
  pNewact->patbase = pat_konbea; /* Line 867, Address: 0x1020454 */
  ((short*)pNewact)[24] = pActwk->xposi.w.h; /* Line 868, Address: 0x1020464 */
  ((short*)pNewact)[25] = pActwk->yposi.w.h; /* Line 869, Address: 0x1020474 */
} /* Line 870, Address: 0x1020484 */





static void b_stop(sprite_status* pActwk) { /* Line 876, Address: 0x1020490 */
  pActwk->sprvsize = 5; /* Line 877, Address: 0x102049c */
  pActwk->r_no0 += 2; /* Line 878, Address: 0x10204a8 */
  b_stop1(pActwk); /* Line 879, Address: 0x10204b8 */
} /* Line 880, Address: 0x10204c4 */






static void b_stop1(sprite_status* pActwk) { /* Line 887, Address: 0x10204e0 */
  b_move(pActwk); /* Line 888, Address: 0x10204ec */

  if (ridechk(pActwk, &actwk[0])) { /* Line 890, Address: 0x10204f8 */
    pActwk->actfree[20] = 255; /* Line 891, Address: 0x1020514 */
  } else { /* Line 892, Address: 0x1020520 */
    pActwk->actfree[20] = 0; /* Line 893, Address: 0x1020528 */
  }

  if (((short*)pActwk)[28] == 344) { /* Line 896, Address: 0x1020530 */
    pActwk->r_no0 += 2; /* Line 897, Address: 0x102054c */
    pActwk->sprvsize = 16; /* Line 898, Address: 0x102055c */
    ((short*)pActwk)[29] = 216; /* Line 899, Address: 0x1020568 */

    if (pActwk->actfree[20]) { /* Line 901, Address: 0x1020574 */
      ride_on_clr(pActwk, &actwk[0]); /* Line 902, Address: 0x1020584 */
    }
  }




} /* Line 909, Address: 0x1020598 */





static void b_roll(sprite_status* pActwk) { /* Line 915, Address: 0x10205b0 */
  short_union patnowk;

  b_move(pActwk); /* Line 918, Address: 0x10205bc */

  if (--((short*)pActwk)[29] < 0) { /* Line 920, Address: 0x10205c8 */
    pActwk->patno = 0; /* Line 921, Address: 0x10205f0 */
    pActwk->r_no0 = 2; /* Line 922, Address: 0x10205f8 */
  } /* Line 923, Address: 0x1020604 */
  else {
    patnowk.b.h = pActwk->patno; /* Line 925, Address: 0x102060c */
    patnowk.b.l = pActwk->patcnt; /* Line 926, Address: 0x1020618 */

    if ((patnowk.w += 128) > 1280) { /* Line 928, Address: 0x1020624 */
      patnowk.w = 0; /* Line 929, Address: 0x102064c */
    }


    pActwk->patno = patnowk.b.h; /* Line 933, Address: 0x1020650 */
    pActwk->patcnt = patnowk.b.l; /* Line 934, Address: 0x102065c */
  }
} /* Line 936, Address: 0x1020668 */





static void b_move(sprite_status* pActwk) { /* Line 942, Address: 0x1020680 */
  short xsav, idx, xwk, ywk;
  char* pKonbeaTbl;

  xsav = pActwk->xposi.w.h; /* Line 946, Address: 0x102069c */
  idx = ((short*)pActwk)[28]; /* Line 947, Address: 0x10206ac */
  pKonbeaTbl = &konbea8tbl[idx * 2]; /* Line 948, Address: 0x10206bc */

  xwk = ((short*)pActwk)[24] + (short)*pKonbeaTbl++; /* Line 950, Address: 0x10206d4 */
  ywk = ((short*)pActwk)[25] + (short)*pKonbeaTbl++; /* Line 951, Address: 0x1020714 */
  pActwk->xposi.w.h = xwk; /* Line 952, Address: 0x1020754 */
  pActwk->yposi.w.h = ywk; /* Line 953, Address: 0x102075c */
  pActwk->xspeed.w = xwk - xsav << 8; /* Line 954, Address: 0x1020764 */

  if ((*(int*)&pActwk->actfree[8] += 65536) >= 29229056) { /* Line 956, Address: 0x102078c */
    *(int*)&pActwk->actfree[8] = 0; /* Line 957, Address: 0x10207b8 */
  }


} /* Line 961, Address: 0x10207c4 */
