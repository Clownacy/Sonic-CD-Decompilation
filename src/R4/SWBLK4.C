#include "..\EQU.H"
#include "SWBLK4.H"

void switchr4_init(sprite_status* pActwk);
void switchr4_move(sprite_status* pActwk);
unsigned int switchr4_colichk(sprite_status* pActwk, sprite_status* pPlayerwk);
void swblkr4_init(sprite_status* pActwk);
void swblkr4_move(sprite_status* pActwk);

static sprite_pattern switchr4_pat0 = {
  1,
  { { -16, -12, 0, 438 } }
};
static sprite_pattern switchr4_pat1 = {
  1,
  { { -16, -4, 0, 439 } }
};
sprite_pattern* switchr4pat[2] = {
  &switchr4_pat0,
  &switchr4_pat1
};
static void(*switchr4_jmp_tbl[2])(sprite_status*) = {
  &switchr4_init,
  &switchr4_move
};
static sprite_pattern swblkr4_pat0 = {
  1,
  { { -32, -64, 0, 440 } }
};
static sprite_pattern swblkr4_pat1 = {
  1,
  { { -16, -64, 0, 441 } }
};
static sprite_pattern swblkr4_pat2 = {
  1,
  { { -16, -32, 0, 442 } }
};
sprite_pattern* swblkr4pat[3] = {
  &swblkr4_pat0,
  &swblkr4_pat1,
  &swblkr4_pat2
};
static void(*swblkr4_jmp_tbl[2])(sprite_status*) = {
  &swblkr4_init,
  &swblkr4_move
};






























































void switchr4(sprite_status* pActwk) { /* Line 109, Address: 0x1016f30 */
  sprite_status* pRideact;
  short actidx;

  switchr4_jmp_tbl[pActwk->r_no0 / 2](pActwk); /* Line 113, Address: 0x1016f44 */
  ride_on_chk(pActwk, &actwk[0]); /* Line 114, Address: 0x1016f88 */
  if ((actidx = ((short*)pActwk)[28]) != 0) { /* Line 115, Address: 0x1016f9c */
    pRideact = &actwk[actidx]; /* Line 116, Address: 0x1016fbc */
    pActwk->xposi.w.h = (char)pActwk->actfree[14] /* Line 117, Address: 0x1016fdc */
                      + pRideact->xposi.w.h;
    pActwk->yposi.w.h = (char)pActwk->actfree[15] /* Line 119, Address: 0x101701c */
                      + pRideact->yposi.w.h;
  }


  actionsub(pActwk); /* Line 124, Address: 0x101705c */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 125, Address: 0x1017068 */
} /* Line 126, Address: 0x101707c */






static void switchr4_init(sprite_status* pActwk) { /* Line 133, Address: 0x10170a0 */
  pActwk->r_no0 += 2; /* Line 134, Address: 0x10170ac */
  pActwk->actflg |= 4; /* Line 135, Address: 0x10170bc */
  pActwk->sproffset = 1290; /* Line 136, Address: 0x10170cc */
  pActwk->sprpri = 3; /* Line 137, Address: 0x10170d8 */
  pActwk->patbase = switchr4pat; /* Line 138, Address: 0x10170e4 */

  if (!((short*)pActwk)[29]) { /* Line 140, Address: 0x10170f4 */
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 141, Address: 0x1017104 */
  }


  pActwk->sprhsize = 14; /* Line 145, Address: 0x1017114 */
  pActwk->sprvsize = 5; /* Line 146, Address: 0x1017120 */

  switchr4_move(pActwk); /* Line 148, Address: 0x101712c */
} /* Line 149, Address: 0x1017138 */





static void switchr4_move(sprite_status* pActwk) { /* Line 155, Address: 0x1017150 */
  if (switchr4_colichk(pActwk, &actwk[0]) != 0) { /* Line 156, Address: 0x101715c */

    pActwk->userflag.b.h |= 1; /* Line 158, Address: 0x1017178 */
  } else { /* Line 159, Address: 0x1017188 */
    pActwk->userflag.b.h &= -2; /* Line 160, Address: 0x1017190 */
  }


  if (pActwk->userflag.b.h) { /* Line 164, Address: 0x10171a4 */
    pActwk->patno = 1; /* Line 165, Address: 0x10171b4 */
  } else { /* Line 166, Address: 0x10171c0 */
    pActwk->patno = 0; /* Line 167, Address: 0x10171c8 */
  }
} /* Line 169, Address: 0x10171d0 */

















static unsigned int switchr4_colichk(sprite_status* pActwk, sprite_status* pPlayerwk) { /* Line 187, Address: 0x10171e0 */
  short szwk;
  short poswk;

  szwk = (char)pActwk->sprhsize + 8; /* Line 191, Address: 0x10171f4 */
  poswk = szwk + (pPlayerwk->xposi.w.h - pActwk->xposi.w.h); /* Line 192, Address: 0x1017228 */
  if (poswk < 0 || poswk >= szwk * 2) { /* Line 193, Address: 0x1017268 */
    return 0; /* Line 194, Address: 0x1017298 */
  }


  poswk = (char)pPlayerwk->sprvsize + pPlayerwk->yposi.w.h; /* Line 198, Address: 0x10172a4 */
  szwk = pActwk->yposi.w.h - 16 - poswk; /* Line 199, Address: 0x10172e8 */
  if (szwk > 0 || szwk < -16) { /* Line 200, Address: 0x1017318 */
    return 0; /* Line 201, Address: 0x101733c */
  }

  return 1; /* Line 204, Address: 0x1017348 */
} /* Line 205, Address: 0x101734c */








































void swblkr4(sprite_status* pActwk) { /* Line 246, Address: 0x1017360 */
  short actidx, xwk, hwk;
  sprite_status* pRideact;

  swblkr4_jmp_tbl[pActwk->r_no0 / 2](pActwk); /* Line 250, Address: 0x101737c */
  ride_on_chk(pActwk, &actwk[0]); /* Line 251, Address: 0x10173c0 */

  if (pActwk->actfree[18]) { /* Line 253, Address: 0x10173d4 */
    if ((actidx = ((short*)pActwk)[28]) != 0) { /* Line 254, Address: 0x10173e4 */
      pRideact = &actwk[actidx]; /* Line 255, Address: 0x1017404 */
      if (pRideact->actno != 48) { /* Line 256, Address: 0x1017424 */

        frameout(pActwk); /* Line 258, Address: 0x1017438 */
        return; /* Line 259, Address: 0x1017444 */
      }

      pActwk->xposi.w.h = pRideact->xposi.w.h - 32; /* Line 262, Address: 0x101744c */
      pActwk->yposi.w.h = pRideact->yposi.w.h + 32; /* Line 263, Address: 0x101746c */
    }
  }


  actionsub(pActwk); /* Line 268, Address: 0x101748c */

  xwk = ((short*)pActwk)[29] & -128; /* Line 270, Address: 0x1017498 */
  hwk = scra_h_posit.w.h - 128 & -128; /* Line 271, Address: 0x10174c0 */
  if ((unsigned short)(xwk - hwk) >= 641) { /* Line 272, Address: 0x10174ec */
    frameout(pActwk); /* Line 273, Address: 0x1017514 */
  }
} /* Line 275, Address: 0x1017520 */





static void swblkr4_init(sprite_status* pActwk) { /* Line 281, Address: 0x1017540 */
  sprite_status* pNewact;

  pActwk->r_no0 += 2; /* Line 284, Address: 0x101754c */
  pActwk->actflg |= 4; /* Line 285, Address: 0x101755c */
  pActwk->sproffset = 17514; /* Line 286, Address: 0x101756c */
  pActwk->sprpri = 3; /* Line 287, Address: 0x1017578 */
  pActwk->patbase = swblkr4pat; /* Line 288, Address: 0x1017584 */

  if (!pActwk->actfree[18]) { /* Line 290, Address: 0x1017594 */
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 291, Address: 0x10175a4 */
    ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 292, Address: 0x10175b4 */
    pActwk->xposi.w.h += 16; /* Line 293, Address: 0x10175c4 */
    pActwk->sprhsize = 16; /* Line 294, Address: 0x10175d4 */
    pActwk->sprvsize = 64; /* Line 295, Address: 0x10175e0 */
    pActwk->patno = 1; /* Line 296, Address: 0x10175ec */

    if (actwkchk2(pActwk, &pNewact) != 0) { /* Line 298, Address: 0x10175f8 */
      frameout(pActwk); /* Line 299, Address: 0x1017610 */
      return; /* Line 300, Address: 0x101761c */
    }



    pNewact->actno = pActwk->actno; /* Line 305, Address: 0x1017624 */
    ((short*)pNewact)[29] = ((short*)pActwk)[29]; /* Line 306, Address: 0x1017634 */

    ((short*)pNewact)[27] = ((short*)pActwk)[27]; /* Line 308, Address: 0x1017644 */

    pNewact->sprhsize = 16; /* Line 310, Address: 0x1017654 */
    pNewact->sprvsize = 32; /* Line 311, Address: 0x1017660 */
    pNewact->actfree[18] = 1; /* Line 312, Address: 0x101766c */
    pNewact->yposi.w.h = pActwk->yposi.w.h + 32; /* Line 313, Address: 0x1017678 */
    pNewact->xposi.w.h = pActwk->xposi.w.h - 32; /* Line 314, Address: 0x101769c */
    ((short*)pNewact)[28] = pActwk - actwk; /* Line 315, Address: 0x10176c0 */
    ((short*)pActwk)[28] = pNewact - actwk; /* Line 316, Address: 0x10176f8 */
    pNewact->patno = 2; /* Line 317, Address: 0x1017730 */

    if (actwkchk2(pActwk, &pNewact) != 0) { /* Line 319, Address: 0x101773c */
      frameout(pActwk); /* Line 320, Address: 0x1017754 */
      return; /* Line 321, Address: 0x1017760 */
    }



    pNewact->actno = 49; /* Line 326, Address: 0x1017768 */
    ((short*)pNewact)[28] = pActwk - actwk; /* Line 327, Address: 0x1017774 */
    ((short*)pActwk)[26] = pNewact - actwk; /* Line 328, Address: 0x10177ac */
    pNewact->actfree[15] = 188; /* Line 329, Address: 0x10177e4 */
    ((short*)pNewact)[29] = ((short*)pActwk)[29]; /* Line 330, Address: 0x10177f0 */

    ((short*)pNewact)[27] = ((short*)pActwk)[27]; /* Line 332, Address: 0x1017800 */
  }



  swblkr4_move(pActwk); /* Line 337, Address: 0x1017810 */
} /* Line 338, Address: 0x101781c */





static void swblkr4_move(sprite_status* pActwk) { /* Line 344, Address: 0x1017830 */
  int ysv;
  sprite_status* pRideact;

  if (pActwk->actfree[18]) return; /* Line 348, Address: 0x1017844 */




  ysv = pActwk->yposi.l; /* Line 353, Address: 0x1017854 */

  if (pActwk->yspeed.w < 0) { /* Line 355, Address: 0x101785c */

    pActwk->yposi.w.h -= 64; /* Line 357, Address: 0x1017874 */
    if (emycol_u(pActwk) < 0) { /* Line 358, Address: 0x1017884 */
      pActwk->yspeed.w = 0; /* Line 359, Address: 0x10178a0 */
    }
  } /* Line 361, Address: 0x10178a8 */
  else if (emycol_d(pActwk) < 0) { /* Line 362, Address: 0x10178b0 */
    pActwk->yspeed.w = 0; /* Line 363, Address: 0x10178cc */
  }



  pActwk->yposi.l = ysv; /* Line 368, Address: 0x10178d4 */
  pActwk->yposi.l += pActwk->yspeed.w << 8; /* Line 369, Address: 0x10178dc */
  pRideact = &actwk[((short*)pActwk)[28]]; /* Line 370, Address: 0x1017900 */





  if (pRideact->actno == 48) { /* Line 376, Address: 0x1017928 */
    pRideact->yspeed.w = pActwk->yspeed.w; /* Line 377, Address: 0x101793c */
  }


  pRideact = &actwk[((short*)pActwk)[26]]; /* Line 381, Address: 0x1017948 */





  if (pRideact->actno != 49) return; /* Line 387, Address: 0x1017970 */



  if (pRideact->userflag.b.h & 3) { /* Line 391, Address: 0x1017984 */


    if ((pActwk->yspeed.w -= 8) < -256) { /* Line 394, Address: 0x101799c */
      pActwk->yspeed.w = -256; /* Line 395, Address: 0x10179c8 */
    }
  } /* Line 397, Address: 0x10179d4 */
  else {
    if ((pActwk->yspeed.w += 8) >= 257) { /* Line 399, Address: 0x10179dc */
      pActwk->yspeed.w = 256; /* Line 400, Address: 0x1017a08 */
    }
  }
} /* Line 403, Address: 0x1017a14 */
