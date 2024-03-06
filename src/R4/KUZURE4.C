#include "..\EQU.H"
#include "KUZURE4.H"

void main_ini(sprite_status* pActwk);
void main_check(sprite_status* pActwk);
void main_wait(sprite_status* pActwk);
void main_break(sprite_status* pActwk);
void parts(sprite_status* pActwk);
void parts_ini(sprite_status* pActwk);
void parts_wait(sprite_status* pActwk);
void parts_fall(sprite_status* pActwk);

static sprite_pattern pat_kuzure_00 = {
  1,
  { { -8, -16, 0, 515 } }
};
static sprite_pattern pat_kuzure_01 = {
  1,
  { { -16, -16, 0, 516 } }
};
static sprite_pattern pat_kuzure_02 = {
  1,
  { { -24, -16, 0, 517 } }
};
static sprite_pattern pat_kuzure_03 = {
  1,
  { { -32, -16, 0, 518 } }
};
static sprite_pattern pat_kuzure_04 = {
  1,
  { { -40, -16, 0, 519 } }
};
static sprite_pattern pat_kuzure_05 = {
  1,
  { { -48, -16, 0, 520 } }
};
static sprite_pattern pat_kuzure_06 = {
  1,
  { { -56, -16, 0, 521 } }
};
static sprite_pattern pat_kuzure_07 = {
  1,
  { { -64, -16, 0, 522 } }
};
static sprite_pattern pat_kuzure_08 = {
  1,
  { { -8, -8, 0, 523 } }
};
sprite_pattern* pat_kuzure_a[9] = {
  &pat_kuzure_00,
  &pat_kuzure_01,
  &pat_kuzure_02,
  &pat_kuzure_03,
  &pat_kuzure_04,
  &pat_kuzure_05,
  &pat_kuzure_06,
  &pat_kuzure_07,
  &pat_kuzure_08
};
static void(*kuzure4_act_tbl[4])(sprite_status*) = {
  &main_ini,
  &main_check,
  &main_wait,
  &main_break
};
static void(*parts_act_tbl[3])(sprite_status*) = {
  &parts_ini,
  &parts_wait,
  parts_fall
};






































































void kuzure4(sprite_status* pActwk) { /* Line 141, Address: 0x102a0c0 */
  if (pActwk->userflag.b.l) { /* Line 142, Address: 0x102a0cc */
    parts(pActwk); /* Line 143, Address: 0x102a0dc */
  } else { /* Line 144, Address: 0x102a0e8 */
    kuzure4_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 145, Address: 0x102a0f0 */
  }
} /* Line 147, Address: 0x102a134 */





static void main_ini(sprite_status* pActwk) { /* Line 153, Address: 0x102a150 */
  pActwk->r_no0 += 2; /* Line 154, Address: 0x102a15c */
  pActwk->actflg = 4; /* Line 155, Address: 0x102a16c */
  pActwk->sproffset = 17252; /* Line 156, Address: 0x102a178 */
  pActwk->patbase = pat_kuzure_a; /* Line 157, Address: 0x102a184 */
  pActwk->sprpri = 3; /* Line 158, Address: 0x102a194 */
  pActwk->sprvsize = 17; /* Line 159, Address: 0x102a1a0 */

  pActwk->patno = pActwk->userflag.b.h - 1; /* Line 161, Address: 0x102a1ac */
  pActwk->sprhs = pActwk->sprhsize = pActwk->userflag.b.h * 8; /* Line 162, Address: 0x102a1cc */
  main_check(pActwk); /* Line 163, Address: 0x102a1f8 */
} /* Line 164, Address: 0x102a204 */





static void main_check(sprite_status* pActwk) { /* Line 170, Address: 0x102a220 */
  if (ridechk(pActwk, &actwk[0]) != 0) { /* Line 171, Address: 0x102a22c */
    pActwk->r_no0 += 2; /* Line 172, Address: 0x102a248 */
    pActwk->cdsts = 0; /* Line 173, Address: 0x102a258 */
    ((short*)pActwk)[23] = 8; /* Line 174, Address: 0x102a260 */

    if (actwk[0].xspeed.w < 0) { /* Line 176, Address: 0x102a26c */
      ((short*)pActwk)[24] = -8; /* Line 177, Address: 0x102a284 */
    } else { /* Line 178, Address: 0x102a290 */
      ((short*)pActwk)[24] = 8; /* Line 179, Address: 0x102a298 */
    }

    soundset(163); /* Line 182, Address: 0x102a2a4 */
  }


  actionsub(pActwk); /* Line 186, Address: 0x102a2b0 */
  frameout_s(pActwk); /* Line 187, Address: 0x102a2bc */
} /* Line 188, Address: 0x102a2c8 */





static void main_wait(sprite_status* pActwk) { /* Line 194, Address: 0x102a2e0 */
  ridechk(pActwk, &actwk[0]); /* Line 195, Address: 0x102a2ec */

  if (--((short*)pActwk)[23] < 0) { /* Line 197, Address: 0x102a300 */
    pActwk->r_no0 += 2; /* Line 198, Address: 0x102a328 */
  }

  actionsub(pActwk); /* Line 201, Address: 0x102a338 */
} /* Line 202, Address: 0x102a344 */





static void main_break(sprite_status* pActwk) { /* Line 208, Address: 0x102a360 */
  unsigned char flagwk;
  short xwk;
  short ywk;
  sprite_status* pNewact;



  flagwk = 255; /* Line 216, Address: 0x102a378 */
  ywk = 8; /* Line 217, Address: 0x102a380 */
  xwk = (pActwk->userflag.b.h - 1) * 8; /* Line 218, Address: 0x102a38c */

  if (((short*)pActwk)[24] >= 0) { /* Line 220, Address: 0x102a3bc */
    xwk = -xwk; /* Line 221, Address: 0x102a3d4 */
  }


  if (actwkchk(&pNewact) == 0) { /* Line 225, Address: 0x102a3e0 */


    pNewact->actno = pActwk->actno; /* Line 228, Address: 0x102a3f4 */
    pNewact->actflg = pActwk->actflg; /* Line 229, Address: 0x102a404 */
    pNewact->sproffset = pActwk->sproffset; /* Line 230, Address: 0x102a414 */
    pNewact->patbase = pActwk->patbase; /* Line 231, Address: 0x102a424 */
    pNewact->xposi.l = pActwk->xposi.l; /* Line 232, Address: 0x102a434 */
    pNewact->yposi.l = pActwk->yposi.l; /* Line 233, Address: 0x102a444 */


    pNewact->userflag.b.l = flagwk; /* Line 236, Address: 0x102a454 */
    pNewact->yposi.w.h -= ywk; /* Line 237, Address: 0x102a45c */
    pNewact->xposi.w.h += xwk; /* Line 238, Address: 0x102a46c */
    ((short*)pNewact)[23] = 4; /* Line 239, Address: 0x102a47c */

    if (actwkchk(&pNewact) == 0) { /* Line 241, Address: 0x102a488 */


      pNewact->actno = pActwk->actno; /* Line 244, Address: 0x102a49c */
      pNewact->actflg = pActwk->actflg; /* Line 245, Address: 0x102a4ac */
      pNewact->sproffset = pActwk->sproffset; /* Line 246, Address: 0x102a4bc */
      pNewact->patbase = pActwk->patbase; /* Line 247, Address: 0x102a4cc */
      pNewact->xposi.l = pActwk->xposi.l; /* Line 248, Address: 0x102a4dc */
      pNewact->yposi.l = pActwk->yposi.l; /* Line 249, Address: 0x102a4ec */


      pNewact->userflag.b.l = flagwk; /* Line 252, Address: 0x102a4fc */
      pNewact->yposi.w.h += ywk; /* Line 253, Address: 0x102a504 */
      pNewact->xposi.w.h += xwk; /* Line 254, Address: 0x102a514 */
    }
  }


  if (ridechk(pActwk, &actwk[0])) { /* Line 259, Address: 0x102a524 */
    ride_on_clr(pActwk, &actwk[0]); /* Line 260, Address: 0x102a540 */
  }


  if (--pActwk->userflag.b.h <= 0) { /* Line 264, Address: 0x102a554 */
    frameout(pActwk); /* Line 265, Address: 0x102a57c */
  } else { /* Line 266, Address: 0x102a588 */
    pActwk->r_no0 -= 2; /* Line 267, Address: 0x102a590 */
    --pActwk->patno; /* Line 268, Address: 0x102a5a0 */
    pActwk->sprhs -= 8; /* Line 269, Address: 0x102a5b0 */
    pActwk->sprhsize -= 8; /* Line 270, Address: 0x102a5c0 */
    ((short*)pActwk)[23] = 7; /* Line 271, Address: 0x102a5d0 */
    pActwk->xposi.w.h += ((short*)pActwk)[24]; /* Line 272, Address: 0x102a5dc */
    ridechk(pActwk, &actwk[0]); /* Line 273, Address: 0x102a5f4 */
    actionsub(pActwk); /* Line 274, Address: 0x102a608 */
  }
} /* Line 276, Address: 0x102a614 */
























static void parts(sprite_status* pActwk) { /* Line 301, Address: 0x102a630 */
  parts_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 302, Address: 0x102a63c */
} /* Line 303, Address: 0x102a680 */





static void parts_ini(sprite_status* pActwk) { /* Line 309, Address: 0x102a690 */
  pActwk->r_no0 += 2; /* Line 310, Address: 0x102a69c */
  pActwk->patno = 8; /* Line 311, Address: 0x102a6ac */
  pActwk->sprpri = 3; /* Line 312, Address: 0x102a6b8 */
  pActwk->sprhs = pActwk->sprhsize = 8; /* Line 313, Address: 0x102a6c4 */
  pActwk->sprvsize = 8; /* Line 314, Address: 0x102a6dc */
  actionsub(pActwk); /* Line 315, Address: 0x102a6e8 */
} /* Line 316, Address: 0x102a6f4 */





static void parts_wait(sprite_status* pActwk) { /* Line 322, Address: 0x102a710 */
  if (--((short*)pActwk)[23] < 0) { /* Line 323, Address: 0x102a71c */
    pActwk->r_no0 += 2; /* Line 324, Address: 0x102a744 */
  }


  actionsub(pActwk); /* Line 328, Address: 0x102a754 */
} /* Line 329, Address: 0x102a760 */





static void parts_fall(sprite_status* pActwk) { /* Line 335, Address: 0x102a770 */
  int spdwk;

  if (!(pActwk->actflg & 128)) { /* Line 338, Address: 0x102a780 */
    frameout(pActwk); /* Line 339, Address: 0x102a798 */
  } else { /* Line 340, Address: 0x102a7a4 */
    spdwk = ((int*)pActwk)[12] + 16384; /* Line 341, Address: 0x102a7ac */
    if (spdwk >= 1441793) { /* Line 342, Address: 0x102a7c8 */
      spdwk = 1441792; /* Line 343, Address: 0x102a7e4 */
    }
    ((int*)pActwk)[12] = spdwk; /* Line 345, Address: 0x102a7e8 */
    pActwk->yposi.l += spdwk; /* Line 346, Address: 0x102a7f0 */
    actionsub(pActwk); /* Line 347, Address: 0x102a800 */
  }
} /* Line 349, Address: 0x102a80c */
