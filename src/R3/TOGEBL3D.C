#include "..\EQU.H"
#include "TOGEBL3A.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"

#if defined(R33C) || defined(R33D)
  #define SPRITE_TOGEBL3D_BASE 554
#else
  #define SPRITE_TOGEBL3D_BASE 503
#endif

static sprite_pattern spat_chg0 = {
  1,
  { { -8, -8, 0, SPRITE_TOGEBL3D_BASE } }
};
static sprite_pattern spat_chg1 = {
  1,
  { { -8, -8, 0, SPRITE_TOGEBL3D_BASE + 1 } }
};
sprite_pattern* pat_chg[1] = { &spat_chg0 };
sprite_pattern* togeball_pat[1] = { &spat_chg1 };






























void togeball(sprite_status* actionwk) { /* Line 53, Address: 0x102b230 */
  if (actionwk->userflag.b.h >= 0) /* Line 54, Address: 0x102b23c */
    togeball_main(actionwk); /* Line 55, Address: 0x102b254 */
  else
    togeball_opt(actionwk); /* Line 57, Address: 0x102b268 */
} /* Line 58, Address: 0x102b274 */

void togeball_main(sprite_status* actionwk) { /* Line 60, Address: 0x102b290 */
  switch (actionwk->r_no0) { /* Line 61, Address: 0x102b29c */

    case 0:
      act_init(actionwk); /* Line 64, Address: 0x102b2c4 */
      break; /* Line 65, Address: 0x102b2d0 */
    case 2:
      act_move(actionwk); /* Line 67, Address: 0x102b2d8 */
      break;
  }
  actionsub(actionwk); /* Line 70, Address: 0x102b2e4 */
  frameout_s(actionwk); /* Line 71, Address: 0x102b2f0 */
} /* Line 72, Address: 0x102b2fc */

void act_init(sprite_status* actionwk) { /* Line 74, Address: 0x102b310 */
  sprite_status* a1;

  actionwk->r_no0 += 2; /* Line 77, Address: 0x102b31c */
  actionwk->actflg |= 4; /* Line 78, Address: 0x102b32c */
  actionwk->sprpri = 1; /* Line 79, Address: 0x102b33c */
  actionwk->sprhsize = 8; /* Line 80, Address: 0x102b348 */
  actionwk->sprvsize = 8; /* Line 81, Address: 0x102b354 */
  actionwk->patbase = pat_chg; /* Line 82, Address: 0x102b360 */
  actionwk->sproffset = 957; /* Line 83, Address: 0x102b370 */
  ((short*)actionwk)[24] = 256; /* Line 84, Address: 0x102b37c */
  if (actionwk->userflag.b.h != 0) /* Line 85, Address: 0x102b388 */
    ((short*)actionwk)[24] = -((short*)actionwk)[24]; /* Line 86, Address: 0x102b3a0 */


  if (actwkchk2(actionwk, &a1) != 0) { /* Line 89, Address: 0x102b3c4 */

    frameout(actionwk); /* Line 91, Address: 0x102b3dc */
    return; /* Line 92, Address: 0x102b3e8 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 94, Address: 0x102b3f0 */
  ((unsigned short*)actionwk)[25] = a1 - actwk; /* Line 95, Address: 0x102b424 */
  a1->actno = actionwk->actno; /* Line 96, Address: 0x102b458 */
  a1->userflag.b.h = -1; /* Line 97, Address: 0x102b468 */
  a1->sprhsize = 8; /* Line 98, Address: 0x102b474 */
  a1->sprvsize = 8; /* Line 99, Address: 0x102b480 */

  if (actwkchk2(actionwk, &a1) != 0) { /* Line 101, Address: 0x102b48c */

    frameout(actionwk); /* Line 103, Address: 0x102b4a4 */
    return; /* Line 104, Address: 0x102b4b0 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 106, Address: 0x102b4b8 */
  ((unsigned short*)actionwk)[26] = a1 - actwk; /* Line 107, Address: 0x102b4ec */
  a1->actno = actionwk->actno; /* Line 108, Address: 0x102b520 */
  a1->userflag.b.h = -1; /* Line 109, Address: 0x102b530 */
  a1->sprhsize = 8; /* Line 110, Address: 0x102b53c */
  a1->sprvsize = 8; /* Line 111, Address: 0x102b548 */

  if (actwkchk2(actionwk, &a1) != 0) { /* Line 113, Address: 0x102b554 */

    frameout(actionwk); /* Line 115, Address: 0x102b56c */
    return; /* Line 116, Address: 0x102b578 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 118, Address: 0x102b580 */
  ((unsigned short*)actionwk)[27] = a1 - actwk; /* Line 119, Address: 0x102b5b4 */
  a1->actno = actionwk->actno; /* Line 120, Address: 0x102b5e8 */
  a1->userflag.b.h = -1; /* Line 121, Address: 0x102b5f8 */
  a1->sprhsize = 8; /* Line 122, Address: 0x102b604 */
  a1->sprvsize = 8; /* Line 123, Address: 0x102b610 */

  if (actwkchk2(actionwk, &a1) != 0) { /* Line 125, Address: 0x102b61c */

    frameout(actionwk); /* Line 127, Address: 0x102b634 */
    return; /* Line 128, Address: 0x102b640 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 130, Address: 0x102b648 */
  ((unsigned short*)actionwk)[28] = a1 - actwk; /* Line 131, Address: 0x102b67c */
  a1->actno = actionwk->actno; /* Line 132, Address: 0x102b6b0 */
  a1->userflag.b.h = -1; /* Line 133, Address: 0x102b6c0 */
  a1->sprhsize = 8; /* Line 134, Address: 0x102b6cc */
  a1->sprvsize = 8; /* Line 135, Address: 0x102b6d8 */
} /* Line 136, Address: 0x102b6e4 */

void act_move(sprite_status* actionwk) { /* Line 138, Address: 0x102b700 */
  short d0;
  unsigned short sin, cos;
  int d0l, d1l, d2l, d3l, d4l, d5l;
  sprite_status* a1;

  d0 = ((short*)actionwk)[24]; /* Line 144, Address: 0x102b72c */
  ((short*)actionwk)[23] += d0; /* Line 145, Address: 0x102b73c */
  d0 = ((short*)actionwk)[23]; /* Line 146, Address: 0x102b74c */
  d0 >>= 8; /* Line 147, Address: 0x102b75c */

  sinset(d0, (short*)&sin, (short*)&cos); /* Line 149, Address: 0x102b768 */
  d0l = d1l = 0; /* Line 150, Address: 0x102b77c */
  d0l = sin << 16; /* Line 151, Address: 0x102b784 */
  d1l = cos << 16; /* Line 152, Address: 0x102b790 */
  d0l >>= 2; /* Line 153, Address: 0x102b79c */
  d1l >>= 2; /* Line 154, Address: 0x102b7a0 */
  d4l = d0l; /* Line 155, Address: 0x102b7a4 */
  d5l = d1l; /* Line 156, Address: 0x102b7a8 */
  d0l >>= 1; /* Line 157, Address: 0x102b7ac */
  d1l >>= 1; /* Line 158, Address: 0x102b7b0 */
  d2l = d0l; /* Line 159, Address: 0x102b7b4 */
  d3l = d1l; /* Line 160, Address: 0x102b7b8 */
  d0l >>= 1; /* Line 161, Address: 0x102b7bc */
  d1l >>= 1; /* Line 162, Address: 0x102b7c0 */
  a1 = &actwk[((unsigned short*)actionwk)[25]]; /* Line 163, Address: 0x102b7c4 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d0l; /* Line 164, Address: 0x102b7e8 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d1l; /* Line 165, Address: 0x102b7fc */
  a1 = &actwk[((unsigned short*)actionwk)[26]]; /* Line 166, Address: 0x102b810 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d2l; /* Line 167, Address: 0x102b834 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d3l; /* Line 168, Address: 0x102b848 */
  a1 = &actwk[((unsigned short*)actionwk)[27]]; /* Line 169, Address: 0x102b85c */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d0l + d2l; /* Line 170, Address: 0x102b880 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d1l + d3l; /* Line 171, Address: 0x102b898 */
  a1 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 172, Address: 0x102b8b0 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d4l; /* Line 173, Address: 0x102b8d4 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d5l; /* Line 174, Address: 0x102b8e8 */
} /* Line 175, Address: 0x102b8fc */

void togeball_opt(sprite_status* actionwk) { /* Line 177, Address: 0x102b930 */
  sprite_status* a1;

  switch (actionwk->r_no0) { /* Line 180, Address: 0x102b940 */

    case 0:
      act_init2(actionwk); /* Line 183, Address: 0x102b968 */
    case 2:
      act_move2(actionwk); /* Line 185, Address: 0x102b974 */
      break;
  }
  a1 = &actwk[((unsigned short*)actionwk)[33]]; /* Line 188, Address: 0x102b980 */
  if (a1->actno != 44) { /* Line 189, Address: 0x102b9a4 */

    frameout(actionwk); /* Line 191, Address: 0x102b9b8 */
    return; /* Line 192, Address: 0x102b9c4 */
  }
  actionsub(actionwk); /* Line 194, Address: 0x102b9cc */
} /* Line 195, Address: 0x102b9d8 */

void act_init2(sprite_status* actionwk) { /* Line 197, Address: 0x102b9f0 */
  actionwk->r_no0 += 2; /* Line 198, Address: 0x102b9f8 */
  actionwk->actflg |= 4; /* Line 199, Address: 0x102ba08 */
  actionwk->sprpri = 1; /* Line 200, Address: 0x102ba18 */
  actionwk->patbase = togeball_pat; /* Line 201, Address: 0x102ba24 */
  actionwk->sproffset = 957; /* Line 202, Address: 0x102ba34 */
  actionwk->colino = 139; /* Line 203, Address: 0x102ba40 */
} /* Line 204, Address: 0x102ba4c */

void act_move2(sprite_status* actionwk) { /* Line 206, Address: 0x102ba60 */
  actionwk->xposi.w.h = ((short*)actionwk)[24]; /* Line 207, Address: 0x102ba68 */
  actionwk->yposi.w.h = ((short*)actionwk)[26]; /* Line 208, Address: 0x102ba78 */
} /* Line 209, Address: 0x102ba88 */
