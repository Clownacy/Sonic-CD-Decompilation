#include "..\EQU.H"
#include "LEGMECA8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\ETC.H"
#include "..\RIDECHK.H"

static void m_init(sprite_status* pActwk);
static void m0move(sprite_status* pActwk);
static void m_move_com(sprite_status* pActwk);
static void m1reset(sprite_status* pActwk);
static void m1move(sprite_status* pActwk);
static void m0reset(sprite_status* pActwk);
static void m_init_leg(sprite_status* pActwk);
static void leg_center(sprite_status* pActwk);
static void c_wait(sprite_status* pActwk);
static void c_roll(sprite_status* pActwk);
static void c_roll1(sprite_status* pActwk);
static void leg_radius(sprite_status* pActwk);
static void r_wait(sprite_status* pActwk);
static void r_roll(sprite_status* pActwk);
static void _ridechk(sprite_status* pActwk, sprite_status* pPlayerwk);
static void slave(sprite_status* pActwk);

static sprite_pattern pat00 =
{
  2,
  { {
    { -4, -4, 0, 463 },
    { -24, -40, 0, 464 }
  } }
};
static sprite_pattern pat01 =
{
  1,
  { { -4, -4, 0, 465 } }
};
sprite_pattern* pat_legmeca[2] =
{
  &pat00,
  &pat01
};















































void legmeca(sprite_status* pActwk) { /* Line 91, Address: 0x1026140 */
  void(*tbl[5])(sprite_status*) = /* Line 92, Address: 0x102614c */
  {
    &m_init,
    &m0move,
    &m1reset,
    &m1move,
    &m0reset
  };

  if (pActwk->userflag.b.h) /* Line 101, Address: 0x1026178 */
  {
    slave(pActwk); /* Line 103, Address: 0x1026188 */
  } /* Line 104, Address: 0x1026194 */
  else
  {
    tbl[pActwk->actfree[0] / 2](pActwk); /* Line 107, Address: 0x102619c */
  }
} /* Line 109, Address: 0x10261d8 */




static void m_init(sprite_status* pActwk) { /* Line 114, Address: 0x10261f0 */
  sprite_status* pNewActwk;
  short a6;
  short d4;
  short d5;
  short d6;
  short i;









  a6 = 4; /* Line 130, Address: 0x1026210 */
  d4 = pActwk->xposi.w.h; /* Line 131, Address: 0x102621c */
  d5 = 8; /* Line 132, Address: 0x102622c */
  d6 = 8; /* Line 133, Address: 0x1026238 */
  pNewActwk = pActwk; /* Line 134, Address: 0x1026244 */
  for (i = 0; i <= d6; ++i) /* Line 135, Address: 0x102624c */
  {
    if (i) /* Line 137, Address: 0x1026258 */
    {
      if (actwkchk(&pNewActwk) != 0) /* Line 139, Address: 0x1026260 */
      {
        frameout(pActwk); /* Line 141, Address: 0x1026274 */
        return; /* Line 142, Address: 0x1026280 */
      }
      pNewActwk->actno = pActwk->actno; /* Line 144, Address: 0x1026288 */
      pNewActwk->userflag.b.h = 1; /* Line 145, Address: 0x1026298 */
      pNewActwk->sprpri = 3; /* Line 146, Address: 0x10262a4 */
      pNewActwk->patno = 1; /* Line 147, Address: 0x10262b0 */
      pNewActwk->sprhs = 4; /* Line 148, Address: 0x10262bc */
      pNewActwk->sprhsize = 4; /* Line 149, Address: 0x10262c8 */
      pNewActwk->sprvsize = 4; /* Line 150, Address: 0x10262d4 */
      pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 151, Address: 0x10262e0 */
      d4 += d5; /* Line 152, Address: 0x10262f0 */
      pNewActwk->xposi.w.h = d4; /* Line 153, Address: 0x10262fc */
    }

    *(short*)&pActwk->actfree[a6] = (unsigned short)(pNewActwk - actwk); /* Line 156, Address: 0x1026304 */
    a6 += 2; /* Line 157, Address: 0x102634c */
    ((short*)pNewActwk)[25] = (unsigned short)(pActwk - actwk); /* Line 158, Address: 0x1026358 */
    pNewActwk->actflg |= 4; /* Line 159, Address: 0x1026394 */
    pNewActwk->sproffset = 792; /* Line 160, Address: 0x10263a4 */
    pNewActwk->patbase = pat_legmeca; /* Line 161, Address: 0x10263b0 */
  } /* Line 162, Address: 0x10263c0 */
  m_init_leg(pNewActwk); /* Line 163, Address: 0x10263e8 */
  m_init_leg(pActwk); /* Line 164, Address: 0x10263f4 */

  pActwk->actfree[0] += 2; /* Line 166, Address: 0x1026400 */
  pActwk->actfree[1] = 12; /* Line 167, Address: 0x1026410 */
  ((short*)pActwk)[24] = -32768; /* Line 168, Address: 0x102641c */

  m0move(pActwk); /* Line 170, Address: 0x1026428 */
} /* Line 171, Address: 0x1026434 */




static void m0move(sprite_status* pActwk) { /* Line 176, Address: 0x1026460 */

  leg_center(&actwk[((short*)pActwk)[33]]); /* Line 178, Address: 0x102646c */


  leg_radius(pActwk); /* Line 181, Address: 0x102649c */

  m_move_com(pActwk); /* Line 183, Address: 0x10264a8 */
} /* Line 184, Address: 0x10264b4 */


static void m_move_com(sprite_status* pActwk) { /* Line 187, Address: 0x10264d0 */

  actionsub(&actwk[((short*)pActwk)[26]]); /* Line 189, Address: 0x10264dc */
  actionsub(&actwk[((short*)pActwk)[27]]); /* Line 190, Address: 0x102650c */
  actionsub(&actwk[((short*)pActwk)[28]]); /* Line 191, Address: 0x102653c */
  actionsub(&actwk[((short*)pActwk)[29]]); /* Line 192, Address: 0x102656c */
  actionsub(&actwk[((short*)pActwk)[30]]); /* Line 193, Address: 0x102659c */
  actionsub(&actwk[((short*)pActwk)[31]]); /* Line 194, Address: 0x10265cc */
  actionsub(&actwk[((short*)pActwk)[32]]); /* Line 195, Address: 0x10265fc */


  frameout_s(pActwk); /* Line 198, Address: 0x102662c */
} /* Line 199, Address: 0x1026638 */




static void m1reset(sprite_status* pActwk) { /* Line 204, Address: 0x1026650 */
  pActwk->actfree[0] = 6; /* Line 205, Address: 0x102665c */

  m1move(pActwk); /* Line 207, Address: 0x1026668 */
} /* Line 208, Address: 0x1026674 */




static void m1move(sprite_status* pActwk) { /* Line 213, Address: 0x1026690 */

  leg_center(pActwk); /* Line 215, Address: 0x102669c */

  leg_radius(&actwk[((short*)pActwk)[33]]); /* Line 217, Address: 0x10266a8 */

  m_move_com(pActwk); /* Line 219, Address: 0x10266d8 */
} /* Line 220, Address: 0x10266e4 */




static void m0reset(sprite_status* pActwk) { /* Line 225, Address: 0x1026700 */
  pActwk->actfree[0] = 2; /* Line 226, Address: 0x102670c */
  m0move(pActwk); /* Line 227, Address: 0x1026718 */
} /* Line 228, Address: 0x1026724 */





static void m_init_leg(sprite_status* pActwk) { /* Line 234, Address: 0x1026740 */
  pActwk->patno = 0; /* Line 235, Address: 0x1026748 */
  pActwk->sprpri = 4; /* Line 236, Address: 0x1026750 */
  pActwk->sprhs = 24; /* Line 237, Address: 0x102675c */
  pActwk->sprhsize = 24; /* Line 238, Address: 0x1026768 */
  pActwk->sprvsize = 41; /* Line 239, Address: 0x1026774 */
} /* Line 240, Address: 0x1026780 */




static void leg_center(sprite_status* pActwk) { /* Line 245, Address: 0x1026790 */
  void(*tbl[3])(sprite_status*) = /* Line 246, Address: 0x102679c */
  {
    &c_wait,
    &c_roll,
    &c_roll1
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 253, Address: 0x10267c0 */
} /* Line 254, Address: 0x10267fc */




static void c_wait(sprite_status* pActwk) { /* Line 259, Address: 0x1026810 */
  ridechk(pActwk, &actwk[0]); /* Line 260, Address: 0x102681c */
  actionsub(pActwk); /* Line 261, Address: 0x1026830 */
} /* Line 262, Address: 0x102683c */




static void c_roll(sprite_status* pActwk) { /* Line 267, Address: 0x1026850 */
  pActwk->r_no0 += 2; /* Line 268, Address: 0x1026858 */
  pActwk->xposi.w.l = -32768; /* Line 269, Address: 0x1026868 */
  pActwk->yposi.w.l = -32768; /* Line 270, Address: 0x1026874 */
} /* Line 271, Address: 0x1026880 */




static void c_roll1(sprite_status* pActwk) { /* Line 276, Address: 0x1026890 */
  sprite_status* pMasterwk;
  sprite_status* pLegwk;
  sprite_status* pKusariwk;
  int_union ld0, ld1, ld3, ld4, ld5;
  short d0, d1, d6, a6;



  pMasterwk = &actwk[((short*)pActwk)[25]]; /* Line 285, Address: 0x10268b0 */
  ((short*)pMasterwk)[24] += 512; /* Line 286, Address: 0x10268d8 */


  a6 = 6; /* Line 289, Address: 0x10268e4 */
  d6 = 6; /* Line 290, Address: 0x10268f0 */
  ld5.l = pActwk->xposi.l; /* Line 291, Address: 0x10268fc */
  ld4.l = pActwk->yposi.l; /* Line 292, Address: 0x1026908 */
  ld1.l = 0; /* Line 293, Address: 0x1026914 */
  ld0.l = 0; /* Line 294, Address: 0x1026918 */
  sinset(pMasterwk->actfree[3], &d0, &d1); /* Line 295, Address: 0x102691c */
  ld1.w.h = d1; /* Line 296, Address: 0x1026930 */
  ld0.w.h = d0; /* Line 297, Address: 0x1026938 */
  ld1.l >>= 5; /* Line 298, Address: 0x1026940 */
  ld0.l >>= 5; /* Line 299, Address: 0x102694c */
  do
  {
    pKusariwk = &actwk[*(short*)&pMasterwk->actfree[a6]]; /* Line 302, Address: 0x1026958 */
    a6 += 2; /* Line 303, Address: 0x1026988 */
    ld5.l += ld1.l; /* Line 304, Address: 0x1026994 */
    ld4.l += ld0.l; /* Line 305, Address: 0x10269a4 */
    pKusariwk->xposi.l = ld5.l; /* Line 306, Address: 0x10269b4 */
    pKusariwk->yposi.l = ld4.l; /* Line 307, Address: 0x10269bc */
  } while (d6--); /* Line 308, Address: 0x10269c4 */



  pLegwk = &actwk[((short*)pMasterwk)[33]]; /* Line 312, Address: 0x10269dc */
  if (pActwk->userflag.b.h) /* Line 313, Address: 0x1026a00 */
  {
    pLegwk = &actwk[((short*)pMasterwk)[25]]; /* Line 315, Address: 0x1026a10 */
  }
  ld3.l = pLegwk->xposi.l; /* Line 317, Address: 0x1026a34 */
  ld5.l += ld1.l; /* Line 318, Address: 0x1026a3c */
  ld4.l += ld0.l; /* Line 319, Address: 0x1026a4c */
  pLegwk->xposi.l = ld5.l; /* Line 320, Address: 0x1026a5c */
  pLegwk->yposi.l = ld4.l; /* Line 321, Address: 0x1026a64 */
  ld5.l -= ld3.l; /* Line 322, Address: 0x1026a6c */
  ld5.l >>= 8; /* Line 323, Address: 0x1026a7c */
  pLegwk->xspeed.w = ld5.w.l; /* Line 324, Address: 0x1026a88 */

  c_wait(pActwk); /* Line 326, Address: 0x1026a90 */
} /* Line 327, Address: 0x1026a9c */




static void leg_radius(sprite_status* pActwk) { /* Line 332, Address: 0x1026ac0 */
  void(*tbl[2])(sprite_status*) = /* Line 333, Address: 0x1026acc */
  {
    &r_wait,
    &r_roll
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 339, Address: 0x1026ae8 */
} /* Line 340, Address: 0x1026b24 */




static void r_wait(sprite_status* pActwk) { /* Line 345, Address: 0x1026b40 */
  sprite_status* pMasterwk;
  sprite_status* pLegwk0;
  sprite_status* pLegwk1;

  if (ridechk(pActwk, &actwk[0])) /* Line 350, Address: 0x1026b58 */
  {
    pMasterwk = &actwk[((short*)pActwk)[25]]; /* Line 352, Address: 0x1026b74 */
    if (pMasterwk->actfree[1]) /* Line 353, Address: 0x1026b9c */
    {
      --pMasterwk->actfree[1]; /* Line 355, Address: 0x1026ba8 */
      pLegwk0 = &actwk[((short*)pMasterwk)[25]]; /* Line 356, Address: 0x1026bb4 */
      pLegwk1 = &actwk[((short*)pMasterwk)[33]]; /* Line 357, Address: 0x1026bd8 */
      pLegwk0->r_no0 += 2; /* Line 358, Address: 0x1026bfc */
      pLegwk1->r_no0 += 2; /* Line 359, Address: 0x1026c08 */
    }
  }
  actionsub(pActwk); /* Line 362, Address: 0x1026c14 */
} /* Line 363, Address: 0x1026c20 */




static void r_roll(sprite_status* pActwk) { /* Line 368, Address: 0x1026c40 */
  sprite_status* pMasterwk;
  sprite_status* pLegwk0;
  sprite_status* pLegwk1;
  short d0, d1;

  _ridechk(pActwk, &actwk[0]); /* Line 374, Address: 0x1026c60 */
  actionsub(pActwk); /* Line 375, Address: 0x1026c74 */


  pMasterwk = &actwk[((short*)pActwk)[25]]; /* Line 378, Address: 0x1026c80 */
  d0 = ((short*)pMasterwk)[24]; /* Line 379, Address: 0x1026ca8 */
  d0 += 16384; /* Line 380, Address: 0x1026cb4 */
  if (d0 >= 0) /* Line 381, Address: 0x1026cc0 */
  {
    d1 = emycol_d(pActwk); /* Line 383, Address: 0x1026cd0 */
    if (d1 < 0) /* Line 384, Address: 0x1026ce4 */
    {
      d1 += 2; /* Line 386, Address: 0x1026cf4 */
      pActwk->yposi.w.h += d1; /* Line 387, Address: 0x1026d00 */


      pMasterwk = &actwk[((short*)pActwk)[25]]; /* Line 390, Address: 0x1026d10 */
      pMasterwk->actfree[0] += 2; /* Line 391, Address: 0x1026d38 */

      ((short*)pMasterwk)[24] += 32768; /* Line 393, Address: 0x1026d44 */
      pLegwk0 = &actwk[((short*)pMasterwk)[25]]; /* Line 394, Address: 0x1026d50 */
      pLegwk1 = &actwk[((short*)pMasterwk)[33]]; /* Line 395, Address: 0x1026d74 */
      pLegwk0->r_no0 = 0; /* Line 396, Address: 0x1026d98 */
      pLegwk1->r_no0 = 0; /* Line 397, Address: 0x1026d9c */
      pLegwk0->xspeed.w = 0; /* Line 398, Address: 0x1026da0 */
      pLegwk1->xspeed.w = 0; /* Line 399, Address: 0x1026da4 */
      pLegwk0->yspeed.w = 0; /* Line 400, Address: 0x1026da8 */
      pLegwk1->yspeed.w = 0; /* Line 401, Address: 0x1026dac */
    }
  }
} /* Line 404, Address: 0x1026db0 */




static void _ridechk(sprite_status* pActwk, sprite_status* pPlayerwk) { /* Line 409, Address: 0x1026de0 */
  short stack;
  unsigned char d0;

  stack = pActwk->xspeed.w; /* Line 413, Address: 0x1026df8 */
  pActwk->xspeed.w = 0; /* Line 414, Address: 0x1026e08 */
  pActwk->sprvsize = 43; /* Line 415, Address: 0x1026e10 */
  if (ridechk(pActwk, pPlayerwk)) d0 = 255; /* Line 416, Address: 0x1026e1c */
  else d0 = 0; /* Line 417, Address: 0x1026e44 */
  pActwk->xspeed.w = stack; /* Line 418, Address: 0x1026e48 */
  pActwk->sprvsize = 41; /* Line 419, Address: 0x1026e50 */
  if (d0) /* Line 420, Address: 0x1026e5c */
  {
    ridechk(pActwk, pPlayerwk); /* Line 422, Address: 0x1026e64 */
  }
} /* Line 424, Address: 0x1026e74 */




static void slave(sprite_status* pActwk) { /* Line 429, Address: 0x1026e90 */
  sprite_status* pMasterwk;

  pMasterwk = &actwk[((short*)pActwk)[25]]; /* Line 432, Address: 0x1026ea0 */
  if (pMasterwk->actno != 38) /* Line 433, Address: 0x1026ec8 */
  {
    frameout(pActwk); /* Line 435, Address: 0x1026edc */
  }
} /* Line 437, Address: 0x1026ee8 */
