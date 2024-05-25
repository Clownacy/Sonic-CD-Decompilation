#include "..\EQU.H"
#include "KEMUSI.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\SUICIDE.H"

static void kemusi_init(sprite_status* pActwk);
static void kemusi_com(sprite_status* pActwk, sprite_status* pNewactwk);
static void kemusi_fall(sprite_status* pActwk);
static void kemusi_stop(sprite_status* pActwk);
static void kemusi_move(sprite_status* pActwk);
static void kemusi_move1(sprite_status* pActwk);
static void kemusi_move1_rev(sprite_status* pActwk);
static void kemusi_move1_move(sprite_status* pActwk);

static sprite_pattern kemusi_pat0 = {
  1,
  { { -8, -12, 0, 431 } }
};
static sprite_pattern kemusi_pat1 = {
  1,
  { { -8, -12, 0, 432 } }
};
static sprite_pattern kemusi_pat2 = {
  1,
  { { -8, -12, 0, 433 } }
};
static sprite_pattern kemusi_pat3 = {
  1,
  { { -8, -8, 0, 434 } }
};
sprite_pattern* pat_kemusi[4] = {
  &kemusi_pat0,
  &kemusi_pat1,
  &kemusi_pat2,
  &kemusi_pat3
};
























































void kemusi(sprite_status* pActwk) { /* Line 95, Address: 0x101ea70 */
  sprite_status *pActwk1, *pActwk2, *pActwk3;

  void(*kemusi_move_tbl[5])(sprite_status*) = { /* Line 98, Address: 0x101ea88 */
    &kemusi_init,
    &kemusi_fall,
    &kemusi_stop,
    &kemusi_move,
    &kemusi_move1
  };

  if (!pActwk->userflag.b.l) { /* Line 106, Address: 0x101eab4 */
    if (enemy_suicide(pActwk)) return; /* Line 107, Address: 0x101eac4 */
  }

  if (pActwk->r_no0) { /* Line 110, Address: 0x101ead8 */
    pActwk1 = &actwk[((short*)pActwk)[31]]; /* Line 111, Address: 0x101eae8 */
    pActwk2 = &actwk[((short*)pActwk)[32]]; /* Line 112, Address: 0x101eb10 */
    pActwk3 = &actwk[((short*)pActwk)[33]]; /* Line 113, Address: 0x101eb38 */
    if (pActwk1->actno != 34 || pActwk2->actno != 34 || pActwk3->actno != 34) { /* Line 114, Address: 0x101eb60 */
      frameout(pActwk); /* Line 115, Address: 0x101eb9c */
      return; /* Line 116, Address: 0x101eba8 */
    }
  }

  kemusi_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 120, Address: 0x101ebb0 */
  actionsub(pActwk); /* Line 121, Address: 0x101ebec */
  if (!pActwk->userflag.b.l) { /* Line 122, Address: 0x101ebf8 */
    frameout_s00(pActwk, ((short*)pActwk)[28]); /* Line 123, Address: 0x101ec08 */
  }
} /* Line 125, Address: 0x101ec1c */








static void kemusi_init(sprite_status* pActwk) { /* Line 134, Address: 0x101ec40 */
  sprite_status* pNewactwk;
  sprite_status *pActwk1, *pActwk2, *pActwk3;
  unsigned char bD2, bD3, bD4;
  short wD0, wD1, wD5, wD6;
  short i;

  ((short*)pActwk)[23] = 3; /* Line 141, Address: 0x101ec70 */
  pActwk->patno = 1; /* Line 142, Address: 0x101ec7c */
  pActwk->sprvsize = 12; /* Line 143, Address: 0x101ec88 */
  pActwk->colino = 51; /* Line 144, Address: 0x101ec94 */

  pNewactwk = pActwk; /* Line 146, Address: 0x101eca0 */
  kemusi_com(pActwk, pNewactwk); /* Line 147, Address: 0x101eca8 */
  if (!pActwk->userflag.b.h) { /* Line 148, Address: 0x101ecb8 */
    wD0 = 36; /* Line 149, Address: 0x101ecc8 */
    wD1 = 6; /* Line 150, Address: 0x101ecd4 */
  } /* Line 151, Address: 0x101ece0 */
  else {

    wD0 = 36; /* Line 154, Address: 0x101ece8 */
    wD1 = 12; /* Line 155, Address: 0x101ecf4 */
  }

  ((short*)pActwk)[24] = wD0; /* Line 158, Address: 0x101ed00 */
  ((short*)pActwk)[26] = wD1; /* Line 159, Address: 0x101ed08 */

  i = 16; /* Line 161, Address: 0x101ed10 */
  wD6 = 2; /* Line 162, Address: 0x101ed1c */
  wD5 = pActwk->xposi.w.h; /* Line 163, Address: 0x101ed28 */
  if (!pActwk->userflag.b.h) { /* Line 164, Address: 0x101ed38 */
    bD4 = 2; /* Line 165, Address: 0x101ed48 */
    bD3 = 11; /* Line 166, Address: 0x101ed50 */
    bD2 = 180; /* Line 167, Address: 0x101ed58 */
  } /* Line 168, Address: 0x101ed60 */
  else {

    bD4 = 3; /* Line 171, Address: 0x101ed68 */
    bD3 = 7; /* Line 172, Address: 0x101ed70 */
    bD2 = 51; /* Line 173, Address: 0x101ed78 */
  }

  for ( ; wD6 >= 0; --wD6, i += 2) { /* Line 176, Address: 0x101ed80 */
    if (actwkchk2(pActwk, &pNewactwk) != 0) { /* Line 177, Address: 0x101ed88 */
      frameout(pActwk); /* Line 178, Address: 0x101eda0 */
      return; /* Line 179, Address: 0x101edac */
    }
    ((short*)((char*)pActwk + i))[23] = pNewactwk - actwk; /* Line 181, Address: 0x101edb4 */
    ((short*)pNewactwk)[23] = wD6; /* Line 182, Address: 0x101edf8 */
    wD5 += 12; /* Line 183, Address: 0x101ee00 */
    pNewactwk->xposi.w.h = wD5; /* Line 184, Address: 0x101ee0c */
    pNewactwk->patno = bD4; /* Line 185, Address: 0x101ee14 */
    pNewactwk->sprvsize = bD3; /* Line 186, Address: 0x101ee1c */
    pNewactwk->colino = bD2; /* Line 187, Address: 0x101ee28 */
    pNewactwk->actno = pActwk->actno; /* Line 188, Address: 0x101ee34 */
    pNewactwk->userflag.b.h = pActwk->userflag.b.h; /* Line 189, Address: 0x101ee44 */
    pNewactwk->yposi.w.h = pActwk->yposi.w.h; /* Line 190, Address: 0x101ee54 */
    ((short*)pNewactwk)[24] = ((short*)pActwk)[24]; /* Line 191, Address: 0x101ee64 */
    ((short*)pNewactwk)[26] = ((short*)pActwk)[26]; /* Line 192, Address: 0x101ee74 */
    pNewactwk->userflag.b.l = -1; /* Line 193, Address: 0x101ee84 */
    kemusi_com(pActwk, pNewactwk); /* Line 194, Address: 0x101ee90 */
  } /* Line 195, Address: 0x101eea0 */
  pActwk1 = &actwk[((short*)pActwk)[31]]; /* Line 196, Address: 0x101eec8 */
  pActwk2 = &actwk[((short*)pActwk)[32]]; /* Line 197, Address: 0x101eef0 */
  pActwk3 = &actwk[((short*)pActwk)[33]]; /* Line 198, Address: 0x101ef18 */


  ((short*)pActwk1)[31] = pActwk - actwk; /* Line 201, Address: 0x101ef40 */
  ((short*)pActwk1)[32] = pActwk2 - actwk; /* Line 202, Address: 0x101ef74 */
  ((short*)pActwk1)[33] = pActwk3 - actwk; /* Line 203, Address: 0x101efa4 */


  ((short*)pActwk2)[31] = pActwk - actwk; /* Line 206, Address: 0x101efd4 */
  ((short*)pActwk2)[32] = pActwk1 - actwk; /* Line 207, Address: 0x101f008 */
  ((short*)pActwk2)[33] = pActwk3 - actwk; /* Line 208, Address: 0x101f038 */


  ((short*)pActwk3)[31] = pActwk - actwk; /* Line 211, Address: 0x101f068 */
  ((short*)pActwk3)[32] = pActwk1 - actwk; /* Line 212, Address: 0x101f09c */
  ((short*)pActwk3)[33] = pActwk2 - actwk; /* Line 213, Address: 0x101f0cc */
} /* Line 214, Address: 0x101f0fc */


static void kemusi_com(sprite_status* pActwk, sprite_status* pNewactwk) { /* Line 217, Address: 0x101f130 */
  pNewactwk->r_no0 = 2; /* Line 218, Address: 0x101f13c */
  pNewactwk->actflg |= 4; /* Line 219, Address: 0x101f148 */
  pNewactwk->sprpri = 3; /* Line 220, Address: 0x101f158 */
  pNewactwk->sprhs = 8; /* Line 221, Address: 0x101f164 */
  pNewactwk->sprhsize = 8; /* Line 222, Address: 0x101f170 */
  pNewactwk->sproffset = 9214; /* Line 223, Address: 0x101f17c */
  pNewactwk->patbase = pat_kemusi; /* Line 224, Address: 0x101f188 */
  ((short*)pNewactwk)[28] = pActwk->xposi.w.h; /* Line 225, Address: 0x101f198 */
} /* Line 226, Address: 0x101f1a8 */








static void kemusi_fall(sprite_status* pActwk) { /* Line 235, Address: 0x101f1c0 */
  short wD1;
  sprite_status* pSubactwk;

  ++pActwk->yposi.w.h; /* Line 239, Address: 0x101f1d4 */
  if ((wD1 = emycol_d(pActwk)) < 0) { /* Line 240, Address: 0x101f1e4 */
    pActwk->yposi.w.h += wD1; /* Line 241, Address: 0x101f210 */
    pActwk->r_no0 += 2; /* Line 242, Address: 0x101f220 */
    pSubactwk = pActwk; /* Line 243, Address: 0x101f230 */
    if (pActwk->userflag.b.l) { /* Line 244, Address: 0x101f234 */
      pSubactwk = &actwk[((short*)pActwk)[31]]; /* Line 245, Address: 0x101f244 */
    }
    ++((short*)pSubactwk)[29]; /* Line 247, Address: 0x101f26c */
  }

} /* Line 250, Address: 0x101f278 */








static void kemusi_stop(sprite_status* pActwk) { /* Line 259, Address: 0x101f290 */
  if (!pActwk->userflag.b.l) { /* Line 260, Address: 0x101f29c */
    if (((short*)pActwk)[29] == 4) { /* Line 261, Address: 0x101f2ac */
      pActwk->r_no0 += 2; /* Line 262, Address: 0x101f2c8 */
      actwk[((short*)pActwk)[31]].r_no0 += 2; /* Line 263, Address: 0x101f2d8 */
      actwk[((short*)pActwk)[32]].r_no0 += 2; /* Line 264, Address: 0x101f30c */
      actwk[((short*)pActwk)[33]].r_no0 += 2; /* Line 265, Address: 0x101f340 */
      kemusi_move(pActwk); /* Line 266, Address: 0x101f374 */
    }
  }

} /* Line 270, Address: 0x101f380 */








static void kemusi_move(sprite_status* pActwk) { /* Line 279, Address: 0x101f390 */
  pActwk->r_no0 += 2; /* Line 280, Address: 0x101f39c */
  ((short*)pActwk)[23] ^= 3; /* Line 281, Address: 0x101f3ac */
  ((short*)pActwk)[25] = ((short*)pActwk)[24]; /* Line 282, Address: 0x101f3bc */
  ((short*)pActwk)[27] = ((short*)pActwk)[26]; /* Line 283, Address: 0x101f3cc */
  if (!pActwk->userflag.b.l) { /* Line 284, Address: 0x101f3dc */
    pActwk->patno ^= 1; /* Line 285, Address: 0x101f3ec */
  }
  kemusi_move1(pActwk); /* Line 287, Address: 0x101f3fc */
} /* Line 288, Address: 0x101f408 */








static void kemusi_move1(sprite_status* pActwk) { /* Line 297, Address: 0x101f420 */
  short wD0;

  if (!(((short*)pActwk)[27] -= ((short*)pActwk)[23])) { /* Line 300, Address: 0x101f430 */
    ((short*)pActwk)[27] = ((short*)pActwk)[26]; /* Line 301, Address: 0x101f458 */
    kemusi_move1_move(pActwk); /* Line 302, Address: 0x101f468 */
    wD0 = ((short*)pActwk)[28] - pActwk->xposi.w.h; /* Line 303, Address: 0x101f474 */
    if (wD0 < 0) /* Line 304, Address: 0x101f4a8 */
      wD0 *= -1; /* Line 305, Address: 0x101f4b8 */
    if (wD0 >= 80) { /* Line 306, Address: 0x101f4c4 */
      kemusi_move1_rev(pActwk); /* Line 307, Address: 0x101f4d8 */
      return; /* Line 308, Address: 0x101f4e4 */
    }
    wD0 = emycol_d(pActwk); /* Line 310, Address: 0x101f4ec */

    if (wD0 + 7 >= 14) { /* Line 312, Address: 0x101f500 */
      kemusi_move1_rev(pActwk); /* Line 313, Address: 0x101f518 */
      return; /* Line 314, Address: 0x101f524 */
    }
    pActwk->yposi.w.h += wD0; /* Line 316, Address: 0x101f52c */
  }

  if (!(--((short*)pActwk)[25])) { /* Line 319, Address: 0x101f53c */
    pActwk->r_no0 -= 2; /* Line 320, Address: 0x101f55c */
  }
} /* Line 322, Address: 0x101f56c */


static void kemusi_move1_rev(sprite_status* pActwk) { /* Line 325, Address: 0x101f580 */
  pActwk->actflg ^= 1; /* Line 326, Address: 0x101f58c */
  pActwk->cddat ^= 1; /* Line 327, Address: 0x101f59c */
  kemusi_move1_move(pActwk); /* Line 328, Address: 0x101f5ac */
  kemusi_move1(pActwk); /* Line 329, Address: 0x101f5b8 */
} /* Line 330, Address: 0x101f5c4 */


static void kemusi_move1_move(sprite_status* pActwk) { /* Line 333, Address: 0x101f5e0 */
  if (!(pActwk->actflg & 1)) /* Line 334, Address: 0x101f5e8 */
    --pActwk->xposi.w.h; /* Line 335, Address: 0x101f600 */
  else
    ++pActwk->xposi.w.h; /* Line 337, Address: 0x101f618 */
} /* Line 338, Address: 0x101f628 */
