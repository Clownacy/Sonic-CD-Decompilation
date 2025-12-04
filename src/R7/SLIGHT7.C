#include "..\EQU.H"
#include "SLIGHT7.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"

static void slight7_init(sprite_status* pActwk);
static void slight7_move(sprite_status* pActwk);
static void type0(sprite_status* pActwk);
static void slight7_pchgsub(sprite_status* pActwk, char* pA2);
static void type1(sprite_status* pActwk);
static void type2(sprite_status* pActwk);
static void type3(sprite_status* pActwk);
static void type4(sprite_status* pActwk);
static void type7(sprite_status* pActwk);

static sprite_pattern slight_pat0 = {
  1,
  { { -12, -112, 0, 434 } }
};
static sprite_pattern slight_pat1 = {
  1,
  { { -40, -112, 0, 435 } }
};
static sprite_pattern slight_pat2 = {
  2,
  { {
    { -8, -112, 0, 436 },
    { -64, 0, 0, 437 }
  } }
};
static sprite_pattern slight_pat3;
static sprite_pattern slight_pat4 = {
  1,
  { { -12, -112, 0, 438 } }
};
static sprite_pattern slight_pat5 = {
  1,
  { { -40, -112, 0, 439 } }
};
static sprite_pattern slight_pat6 = {
  2,
  { {
    { -8, -112, 0, 440 },
    { -64, 0, 0, 441 }
  } }
};
sprite_pattern* slight7pat[4] = {
  &slight_pat0,
  &slight_pat1,
  &slight_pat2,
  &slight_pat3
};
sprite_pattern* slight7patb[4] = {
  &slight_pat4,
  &slight_pat5,
  &slight_pat6,
  &slight_pat3
};















































void slight7(sprite_status* pActwk) { /* Line 106, Address: 0x10205b0 */
  void(*slight_acttbl[2])(sprite_status*) = { /* Line 107, Address: 0x10205bc */
    &slight7_init,
    &slight7_move
  };

  slight_acttbl[pActwk->r_no0 / 2](pActwk); /* Line 112, Address: 0x10205d8 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 113, Address: 0x1020614 */
} /* Line 114, Address: 0x1020628 */








void slight7_init(sprite_status* pActwk) { /* Line 123, Address: 0x1020640 */
  pActwk->r_no0 += 2; /* Line 124, Address: 0x102064c */
  pActwk->actflg |= 4; /* Line 125, Address: 0x102065c */
  pActwk->patbase = slight7pat; /* Line 126, Address: 0x102066c */
  pActwk->sprhsize = 127; /* Line 127, Address: 0x102067c */
  pActwk->sprvsize = 127; /* Line 128, Address: 0x1020688 */
  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 129, Address: 0x1020694 */

  pActwk->actfree[6] = pActwk->userflag.b.l & 6; /* Line 131, Address: 0x10206a4 */

  pActwk->sprpri = 1; /* Line 133, Address: 0x10206c4 */
  pActwk->sproffset = 42159; /* Line 134, Address: 0x10206d0 */
  if (pActwk->userflag.b.l & 8) { /* Line 135, Address: 0x10206dc */
    pActwk->sprpri = 3; /* Line 136, Address: 0x10206f8 */
    pActwk->sproffset = 9391; /* Line 137, Address: 0x1020704 */

    if (time_flag != 1) { /* Line 139, Address: 0x1020710 */
      pActwk->sproffset += 8192; /* Line 140, Address: 0x1020728 */
      pActwk->patbase = slight7patb; /* Line 141, Address: 0x1020738 */
    }
  }
  slight7_move(pActwk); /* Line 144, Address: 0x1020748 */
} /* Line 145, Address: 0x1020754 */








void slight7_move(sprite_status* pActwk) { /* Line 154, Address: 0x1020770 */
  unsigned char bD0;

  void(*slight_move_tbl[9])(sprite_status*) = { /* Line 157, Address: 0x1020780 */
    &type0,
    &type1,
    &type2,
    &type3,
    &type4,
    &type4,
    &type4,
    &type7,
    &type7
  };

  pActwk->yposi.w.h = scra_v_posit.w.h + 112; /* Line 169, Address: 0x10207ac */

  slight_move_tbl[pActwk->userflag.b.h](pActwk); /* Line 171, Address: 0x10207d0 */

  bD0 = gametimer.w & 6; /* Line 173, Address: 0x10207f8 */
  if (pActwk->userflag.b.l & 4) { /* Line 174, Address: 0x1020814 */

    if (pActwk->actfree[6] == bD0) { /* Line 176, Address: 0x1020830 */
      actionsub(pActwk); /* Line 177, Address: 0x1020848 */
    }
  } /* Line 179, Address: 0x1020854 */
  else {

    if (pActwk->actfree[6] == (bD0 & 2)) { /* Line 182, Address: 0x102085c */
      actionsub(pActwk); /* Line 183, Address: 0x1020878 */
    }
  }
} /* Line 186, Address: 0x1020884 */








void type0(sprite_status* pActwk) { /* Line 195, Address: 0x10208a0 */
  char type0_pchgtbl[44] = { /* Line 196, Address: 0x10208ac */
    0, 10, 0,   0,
    3, 20, 0,   0,
    2, 20, 0,  68,
    1, 20, 0,  12,
    3, 10, 0,   0,
    2, 30, 1,  -4,
    1, 20, 0,  12,
    3, 20, 0,   0,
    1, 10, 1,  64,
    3, 20, 0,   0,
    2, 20, 1, -16
  };


  pActwk->actfree[19] = 11; /* Line 211, Address: 0x10208e0 */
  slight7_pchgsub(pActwk, type0_pchgtbl); /* Line 212, Address: 0x10208ec */
} /* Line 213, Address: 0x10208fc */










void slight7_pchgsub(sprite_status* pActwk, char* pA2) { /* Line 224, Address: 0x1020910 */
  unsigned char bD1;

  if (!pActwk->actfree[16]) { /* Line 227, Address: 0x1020920 */
    pA2 += pActwk->actfree[18] << 2; /* Line 228, Address: 0x1020930 */
    pActwk->patno = *pA2++; /* Line 229, Address: 0x102094c */
    pActwk->actfree[16] = *pA2++; /* Line 230, Address: 0x1020964 */
    bD1 = *pA2++; /* Line 231, Address: 0x102097c */
    pActwk->xposi.w.h = ((short*)pActwk)[29] + (short)*pA2++; /* Line 232, Address: 0x1020990 */

    pActwk->actflg &= 254; /* Line 234, Address: 0x10209d4 */
    pActwk->cddat &= 254; /* Line 235, Address: 0x10209e4 */
    if (bD1) { /* Line 236, Address: 0x10209f4 */
      pActwk->actflg |= 1; /* Line 237, Address: 0x10209fc */
      pActwk->cddat |= 1; /* Line 238, Address: 0x1020a0c */
    }
  }

  if (--pActwk->actfree[16]) return; /* Line 242, Address: 0x1020a1c */
  if (++pActwk->actfree[18] >= pActwk->actfree[19]) { /* Line 243, Address: 0x1020a38 */
    pActwk->actfree[18] = 0; /* Line 244, Address: 0x1020a68 */
  }
} /* Line 246, Address: 0x1020a70 */








void type1(sprite_status* pActwk) { /* Line 255, Address: 0x1020a80 */
  char type1_pchgtbl[32] = { /* Line 256, Address: 0x1020a8c */
    0, 30, 0,   0,
    1, 30, 0,  48,
    2, 30, 0,  92,
    1, 30, 0,  48,
    0, 30, 0,   0,
    1, 30, 1, -48,
    2, 30, 1, -92,
    1, 30, 1, -48
  };

  pActwk->actfree[19] = 8; /* Line 267, Address: 0x1020ac0 */
  slight7_pchgsub(pActwk, type1_pchgtbl); /* Line 268, Address: 0x1020acc */
} /* Line 269, Address: 0x1020adc */








void type2(sprite_status* pActwk) { /* Line 278, Address: 0x1020af0 */
  char type2_pchgtbl[16] = { /* Line 279, Address: 0x1020afc */
    0, 30, 0,  0,
    1, 30, 0, 48,
    2, 30, 0, 92,
    1, 30, 0, 48
  };

  pActwk->actfree[19] = 4; /* Line 286, Address: 0x1020b30 */
  slight7_pchgsub(pActwk, type2_pchgtbl); /* Line 287, Address: 0x1020b3c */
} /* Line 288, Address: 0x1020b4c */








void type3(sprite_status* pActwk) { /* Line 297, Address: 0x1020b60 */
  char type3_pchgtbl[16] = { /* Line 298, Address: 0x1020b6c */
    0, 30, 0,   0,
    1, 30, 1, -48,
    2, 30, 1, -92,
    1, 30, 1, -48
  };

  pActwk->actfree[19] = 4; /* Line 305, Address: 0x1020ba0 */
  slight7_pchgsub(pActwk, type3_pchgtbl); /* Line 306, Address: 0x1020bac */
} /* Line 307, Address: 0x1020bbc */








void type4(sprite_status* pActwk) { /* Line 316, Address: 0x1020bd0 */
  if (pActwk->userflag.b.h < 4) /* Line 317, Address: 0x1020bd8 */
    pActwk->patno = 0; /* Line 318, Address: 0x1020bf4 */
  else
    pActwk->patno = pActwk->userflag.b.h - 4; /* Line 320, Address: 0x1020c04 */
} /* Line 321, Address: 0x1020c24 */







void type7(sprite_status* pActwk) { /* Line 329, Address: 0x1020c30 */
  if (pActwk->userflag.b.h < 6) /* Line 330, Address: 0x1020c38 */
    pActwk->patno = 0; /* Line 331, Address: 0x1020c54 */
  else
    pActwk->patno = pActwk->userflag.b.h - 6; /* Line 333, Address: 0x1020c64 */
  pActwk->actflg |= 1; /* Line 334, Address: 0x1020c84 */
  pActwk->cddat |= 1; /* Line 335, Address: 0x1020c94 */
} /* Line 336, Address: 0x1020ca4 */
