#include "..\EQU.H"
#include "KONBEA83.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"
#include "..\PLAYSUB.H"

static void a_init(sprite_status* pActwk);
static void a_init_sub(sprite_status* pActwk, sprite_status* pNewact);
static void a_stop(sprite_status* pActwk);
static void a_stop1(sprite_status* pActwk);
static void a_move(sprite_status* pActwk);

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
  { { -16, -8, 0, 507 } }
};
static sprite_pattern pat_01 = {
  1,
  { { -16, -12, 0, 508 } }
};
static sprite_pattern pat_02 = {
  1,
  { { -12, -16, 0, 509 } }
};
static sprite_pattern pat_03 = {
  1,
  { { -8, -16, 0, 510 } }
};
static sprite_pattern pat_04 = {
  1,
  { { -12, -16, 0, 511 } }
};
static sprite_pattern pat_05 = {
  1,
  { { -16, -12, 0, 512 } }
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






















































































void konbea(sprite_status* pActwk) { /* Line 147, Address: 0x10292b0 */
  sprite_status* pMainwk;


  if (pActwk->userflag.b.l) { /* Line 151, Address: 0x10292c0 */
    pMainwk = &actwk[((short*)pActwk)[23]]; /* Line 152, Address: 0x10292d0 */

    if (pMainwk->actno != 42) { /* Line 154, Address: 0x10292f8 */
      frameout(pActwk); return; /* Line 155, Address: 0x102930c */
    }

    if (((short*)pActwk)[25] != ((short*)pMainwk)[25]) { /* Line 158, Address: 0x1029320 */

      frameout(pActwk); return; /* Line 160, Address: 0x1029344 */
    }

    if (((short*)pActwk)[26] != ((short*)pMainwk)[26]) { /* Line 163, Address: 0x1029358 */

      frameout(pActwk); return; /* Line 165, Address: 0x102937c */
    }
  }


  a_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 170, Address: 0x1029390 */
  actionsub(pActwk); /* Line 171, Address: 0x10293d4 */

  if (!(pActwk->userflag.b.l & 128)) { /* Line 173, Address: 0x10293e0 */
    frameout_s00(pActwk, ((short*)pActwk)[25]); /* Line 174, Address: 0x10293fc */
  }
} /* Line 176, Address: 0x1029410 */





static void a_init(sprite_status* pActwk) { /* Line 182, Address: 0x1029430 */
  short *pTbl, i;
  sprite_status* pNewact;

  pTbl = a_tbl0[pActwk->userflag.b.l]; /* Line 186, Address: 0x1029444 */

  ((short*)pActwk)[24] = *pTbl++; /* Line 188, Address: 0x1029468 */
  pNewact = pActwk; /* Line 189, Address: 0x102947c */
  a_init_sub(pActwk, pNewact); /* Line 190, Address: 0x1029484 */

  for (i = *pTbl++ - 1; i >= 0; --i) { /* Line 192, Address: 0x1029494 */

    if (actwkchk(&pNewact) != 0) { /* Line 194, Address: 0x10294c4 */
      frameout(pActwk); /* Line 195, Address: 0x10294d8 */
      break; /* Line 196, Address: 0x10294e4 */
    }


    pNewact->actno = pActwk->actno; /* Line 200, Address: 0x10294ec */
    ((short*)pNewact)[23] = pActwk - actwk; /* Line 201, Address: 0x10294fc */
    pNewact->userflag.b.h = pActwk->userflag.b.h; /* Line 202, Address: 0x1029534 */
    pNewact->userflag.b.l = -1; /* Line 203, Address: 0x1029544 */
    ((short*)pNewact)[24] = *pTbl++; /* Line 204, Address: 0x1029550 */
    pNewact->xposi.w.h = pActwk->xposi.w.h + *pTbl++; /* Line 205, Address: 0x1029564 */
    pNewact->yposi.w.h = pActwk->yposi.w.h + *pTbl++; /* Line 206, Address: 0x102959c */
    a_init_sub(pActwk, pNewact); /* Line 207, Address: 0x10295d4 */
  } /* Line 208, Address: 0x10295e4 */
} /* Line 209, Address: 0x1029600 */





static void a_init_sub(sprite_status* pActwk, sprite_status* pNewact) { /* Line 215, Address: 0x1029620 */
  pNewact->r_no0 = 2; /* Line 216, Address: 0x102962c */
  pNewact->actflg |= 4; /* Line 217, Address: 0x1029638 */
  pNewact->sprpri = 3; /* Line 218, Address: 0x1029648 */
  pNewact->sprhs = pNewact->sprhsize = 16; /* Line 219, Address: 0x1029654 */
  pNewact->sprvsize = 5; /* Line 220, Address: 0x102966c */
  pNewact->sproffset = 844; /* Line 221, Address: 0x1029678 */
  pNewact->patbase = pat_konbea; /* Line 222, Address: 0x1029684 */
  ((short*)pNewact)[25] = pActwk->xposi.w.h; /* Line 223, Address: 0x1029694 */
  ((short*)pNewact)[26] = pActwk->yposi.w.h; /* Line 224, Address: 0x10296a4 */
} /* Line 225, Address: 0x10296b4 */





static void a_stop(sprite_status* pActwk) { /* Line 231, Address: 0x10296c0 */
  pActwk->sprvsize = 5; /* Line 232, Address: 0x10296cc */
  ((short*)pActwk)[24] = 120; /* Line 233, Address: 0x10296d8 */
  pActwk->r_no0 += 2; /* Line 234, Address: 0x10296e4 */
  a_stop1(pActwk); /* Line 235, Address: 0x10296f4 */
} /* Line 236, Address: 0x1029700 */





static void a_stop1(sprite_status* pActwk) { /* Line 242, Address: 0x1029710 */
  if (ridechk(pActwk, &actwk[0])) { /* Line 243, Address: 0x102971c */
    pActwk->actfree[20] = 255; /* Line 244, Address: 0x1029738 */
  } else { /* Line 245, Address: 0x1029744 */
    pActwk->actfree[20] = 0; /* Line 246, Address: 0x102974c */
  }

  if (!(--((short*)pActwk)[24])) { /* Line 249, Address: 0x1029754 */
    pActwk->sprvsize = 16; /* Line 250, Address: 0x1029774 */
    pActwk->mstno.w = 255; /* Line 251, Address: 0x1029780 */
    pActwk->r_no0 += 2; /* Line 252, Address: 0x102978c */

    if (pActwk->actfree[20]) { /* Line 254, Address: 0x102979c */
      ride_on_clr(pActwk, &actwk[0]); /* Line 255, Address: 0x10297ac */
    }
  }




} /* Line 262, Address: 0x10297c0 */





static void a_move(sprite_status* pActwk) { /* Line 268, Address: 0x10297d0 */
  patchg(pActwk, pchg); /* Line 269, Address: 0x10297dc */

  if (!pActwk->patno) { /* Line 271, Address: 0x10297f0 */
    pActwk->r_no0 = 2; /* Line 272, Address: 0x1029800 */
  }


} /* Line 276, Address: 0x102980c */
