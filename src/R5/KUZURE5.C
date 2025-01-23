#include "..\EQU.H"
#include "KUZURE5.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"

#if defined(R53C) || defined(R53D)
  #define SPRITE_KUZURE5_BASE 403
#else
  #define SPRITE_KUZURE5_BASE 477
#endif

static void main_ini(sprite_status* pActwk);
static void main_check(sprite_status* pActwk);
static void main_wait(sprite_status* pActwk);
static void main_break(sprite_status* pActwk);
static void parts_ini(sprite_status* pActwk);
static void parts_wait(sprite_status* pActwk);
static void parts_fall(sprite_status* pActwk);

static sprite_pattern pat_00 = {
  1,
  { { -8, -16, 0, SPRITE_KUZURE5_BASE } }
};
static sprite_pattern pat_01 = {
  1,
  { { -16, -16, 0, SPRITE_KUZURE5_BASE + 1 } }
};
static sprite_pattern pat_02 = {
  1,
  { { -24, -16, 0, SPRITE_KUZURE5_BASE + 2 } }
};
static sprite_pattern pat_03 = {
  1,
  { { -32, -16, 0, SPRITE_KUZURE5_BASE + 3 } }
};
static sprite_pattern pat_04 = {
  1,
  { { -40, -16, 0, SPRITE_KUZURE5_BASE + 4 } }
};
static sprite_pattern pat_05 = {
  1,
  { { -48, -16, 0, SPRITE_KUZURE5_BASE + 5 } }
};
static sprite_pattern pat_06 = {
  1,
  { { -56, -16, 0, SPRITE_KUZURE5_BASE + 6 } }
};
static sprite_pattern pat_07 = {
  1,
  { { -64, -16, 0, SPRITE_KUZURE5_BASE + 7 } }
};
static sprite_pattern pat_08 = {
  1,
  { { -8, -8, 0, SPRITE_KUZURE5_BASE + 8 } }
};
static sprite_pattern pat_09 = {
  1,
  { { -8, -8, 0, SPRITE_KUZURE5_BASE + 9 } }
};
sprite_pattern* pat_kuzure_a[10] = {
  &pat_00,
  &pat_01,
  &pat_02,
  &pat_03,
  &pat_04,
  &pat_05,
  &pat_06,
  &pat_07,
  &pat_08,
  &pat_09
};
static void(*kuzure5_act_tbl[4])(sprite_status*) = {
  &main_ini,
  &main_check,
  &main_wait,
  &main_break
};
static void(*parts_act_tbl[3])(sprite_status*) = {
  &parts_ini,
  &parts_wait,
  &parts_fall
};





























































void kuzure5(sprite_status* pActwk) { /* Line 146, Address: 0x101b940 */
  if (pActwk->userflag.b.l) /* Line 147, Address: 0x101b94c */
  {
    parts_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 149, Address: 0x101b95c */
  } /* Line 150, Address: 0x101b9a0 */
  else {
    kuzure5_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 152, Address: 0x101b9a8 */
  }
} /* Line 154, Address: 0x101b9ec */





static void main_ini(sprite_status* pActwk) { /* Line 160, Address: 0x101ba00 */
  pActwk->r_no0 += 2; /* Line 161, Address: 0x101ba0c */
  pActwk->actflg = 4; /* Line 162, Address: 0x101ba1c */
  pActwk->patbase = pat_kuzure_a; /* Line 163, Address: 0x101ba28 */
  pActwk->sprpri = 3; /* Line 164, Address: 0x101ba38 */
  pActwk->sprvsize = 17; /* Line 165, Address: 0x101ba44 */

  if (stageno.b.l != 2) { /* Line 167, Address: 0x101ba50 */
    pActwk->sproffset = 17232; /* Line 168, Address: 0x101ba6c */
  } else { /* Line 169, Address: 0x101ba78 */
    pActwk->sproffset = 17312; /* Line 170, Address: 0x101ba80 */
  }

  pActwk->patno = pActwk->userflag.b.h - 1; /* Line 173, Address: 0x101ba8c */
  pActwk->sprhs = pActwk->sprhsize = pActwk->userflag.b.h * 8; /* Line 174, Address: 0x101baac */
  main_check(pActwk); /* Line 175, Address: 0x101bad8 */
} /* Line 176, Address: 0x101bae4 */





static void main_check(sprite_status* pActwk) { /* Line 182, Address: 0x101bb00 */
  if (ridechk(pActwk, &actwk[0])) { /* Line 183, Address: 0x101bb0c */
    pActwk->r_no0 += 2; /* Line 184, Address: 0x101bb28 */
    pActwk->cdsts = 0; /* Line 185, Address: 0x101bb38 */
    ((short*)pActwk)[23] = 8; /* Line 186, Address: 0x101bb40 */

    if (actwk[0].xspeed.w >= 0) { /* Line 188, Address: 0x101bb4c */
      ((short*)pActwk)[24] = 8; /* Line 189, Address: 0x101bb64 */
    } /* Line 190, Address: 0x101bb70 */
    else ((short*)pActwk)[24] = -8; /* Line 191, Address: 0x101bb78 */


    soundset(163); /* Line 194, Address: 0x101bb84 */
  }


  actionsub(pActwk); /* Line 198, Address: 0x101bb90 */
  frameout_s(pActwk); /* Line 199, Address: 0x101bb9c */
} /* Line 200, Address: 0x101bba8 */





static void main_wait(sprite_status* pActwk) { /* Line 206, Address: 0x101bbc0 */
  ridechk(pActwk, &actwk[0]); /* Line 207, Address: 0x101bbcc */

  if (--((short*)pActwk)[23] < 0) { /* Line 209, Address: 0x101bbe0 */
    pActwk->r_no0 += 2; /* Line 210, Address: 0x101bc08 */
  }


  actionsub(pActwk); /* Line 214, Address: 0x101bc18 */
} /* Line 215, Address: 0x101bc24 */





static void main_break(sprite_status* pActwk) { /* Line 221, Address: 0x101bc40 */
  unsigned char flagwk;
  short xwk;
  short ywk;
  sprite_status* pNewact;



  flagwk = 255; /* Line 229, Address: 0x101bc58 */
  ywk = 8; /* Line 230, Address: 0x101bc60 */
  xwk = ((short)pActwk->userflag.b.h - 1) * 8; /* Line 231, Address: 0x101bc6c */

  if (((short*)pActwk)[24] >= 0) { /* Line 233, Address: 0x101bc9c */
    xwk *= -1; /* Line 234, Address: 0x101bcb4 */
  }


  if (actwkchk(&pNewact) == 0) { /* Line 238, Address: 0x101bcc0 */


    pNewact->actno = pActwk->actno; /* Line 241, Address: 0x101bcd4 */
    pNewact->actflg = pActwk->actflg; /* Line 242, Address: 0x101bce4 */
    pNewact->sproffset = pActwk->sproffset; /* Line 243, Address: 0x101bcf4 */
    pNewact->patbase = pActwk->patbase; /* Line 244, Address: 0x101bd04 */
    pNewact->xposi.l = pActwk->xposi.l; /* Line 245, Address: 0x101bd14 */
    pNewact->yposi.l = pActwk->yposi.l; /* Line 246, Address: 0x101bd24 */


    pNewact->userflag.b.l = flagwk; /* Line 249, Address: 0x101bd34 */
    pNewact->yposi.w.h -= ywk; /* Line 250, Address: 0x101bd3c */
    pNewact->xposi.w.h += xwk; /* Line 251, Address: 0x101bd4c */
    ((short*)pNewact)[23] = 4; /* Line 252, Address: 0x101bd5c */
    pNewact->patno = 8; /* Line 253, Address: 0x101bd68 */

    if (actwkchk(&pNewact) == 0) { /* Line 255, Address: 0x101bd74 */


      pNewact->actno = pActwk->actno; /* Line 258, Address: 0x101bd88 */
      pNewact->actflg = pActwk->actflg; /* Line 259, Address: 0x101bd98 */
      pNewact->sproffset = pActwk->sproffset; /* Line 260, Address: 0x101bda8 */
      pNewact->patbase = pActwk->patbase; /* Line 261, Address: 0x101bdb8 */
      pNewact->xposi.l = pActwk->xposi.l; /* Line 262, Address: 0x101bdc8 */
      pNewact->yposi.l = pActwk->yposi.l; /* Line 263, Address: 0x101bdd8 */


      pNewact->userflag.b.l = flagwk; /* Line 266, Address: 0x101bde8 */
      pNewact->yposi.w.h += ywk; /* Line 267, Address: 0x101bdf0 */
      pNewact->xposi.w.h += xwk; /* Line 268, Address: 0x101be00 */
      pNewact->patno = 9; /* Line 269, Address: 0x101be10 */
    }
  }


  if (ridechk(pActwk, &actwk[0])) { /* Line 274, Address: 0x101be1c */
    ride_on_clr(pActwk, &actwk[0]); /* Line 275, Address: 0x101be38 */
  }


  if (--pActwk->userflag.b.h <= 0) { /* Line 279, Address: 0x101be4c */
    frameout(pActwk); /* Line 280, Address: 0x101be74 */
  } else { /* Line 281, Address: 0x101be80 */
    pActwk->r_no0 -= 2; /* Line 282, Address: 0x101be88 */
    --pActwk->patno; /* Line 283, Address: 0x101be98 */
    pActwk->sprhs -= 8; /* Line 284, Address: 0x101bea8 */
    pActwk->sprhsize -= 8; /* Line 285, Address: 0x101beb8 */
    ((short*)pActwk)[23] = 7; /* Line 286, Address: 0x101bec8 */
    pActwk->xposi.w.h += ((short*)pActwk)[24]; /* Line 287, Address: 0x101bed4 */
    ridechk(pActwk, &actwk[0]); /* Line 288, Address: 0x101beec */
    actionsub(pActwk); /* Line 289, Address: 0x101bf00 */
  }
} /* Line 291, Address: 0x101bf0c */









static void parts_ini(sprite_status* pActwk) { /* Line 301, Address: 0x101bf30 */
  pActwk->r_no0 += 2; /* Line 302, Address: 0x101bf3c */
  pActwk->sprpri = 3; /* Line 303, Address: 0x101bf4c */
  pActwk->sprhs = pActwk->sprhsize = 8; /* Line 304, Address: 0x101bf58 */
  pActwk->sprvsize = 8; /* Line 305, Address: 0x101bf70 */
  actionsub(pActwk); /* Line 306, Address: 0x101bf7c */
} /* Line 307, Address: 0x101bf88 */





static void parts_wait(sprite_status* pActwk) { /* Line 313, Address: 0x101bfa0 */
  if (--((short*)pActwk)[23] < 0) { /* Line 314, Address: 0x101bfac */
    pActwk->r_no0 += 2; /* Line 315, Address: 0x101bfd4 */
  }


  actionsub(pActwk); /* Line 319, Address: 0x101bfe4 */
} /* Line 320, Address: 0x101bff0 */





static void parts_fall(sprite_status* pActwk) { /* Line 326, Address: 0x101c000 */
  int spdwk;

  if (!(pActwk->actflg & 128)) { /* Line 329, Address: 0x101c010 */
    frameout(pActwk); /* Line 330, Address: 0x101c028 */
  } else { /* Line 331, Address: 0x101c034 */
    spdwk = (long int)((int*)pActwk)[12] + 16384; /* Line 332, Address: 0x101c03c */
    if ((long int)spdwk > 1441792) { /* Line 333, Address: 0x101c058 */
      spdwk = 1441792; /* Line 334, Address: 0x101c074 */
    }
    ((int*)pActwk)[12] = spdwk; /* Line 336, Address: 0x101c078 */
    pActwk->yposi.l += spdwk; /* Line 337, Address: 0x101c080 */
    actionsub(pActwk); /* Line 338, Address: 0x101c090 */
  }
} /* Line 340, Address: 0x101c09c */
