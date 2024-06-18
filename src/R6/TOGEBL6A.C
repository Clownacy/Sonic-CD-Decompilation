#include "..\EQU.H"
#include "TOGEBL6A.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"

static void act_init(sprite_status* actionwk);
static void act_move(sprite_status* actionwk);

static sprite_pattern spat_chg0 =
{
  1,
  { { -8, -8, 0, 497 } }
};
static sprite_pattern spat_chg1 =
{
  1,
  { { -8, -8, 0, 498 } }
};
sprite_pattern* pat_chg[1] = { &spat_chg0 };
sprite_pattern* pat_togeball[1] = { &spat_chg1 };
































void togeball(sprite_status* actionwk) { /* Line 54, Address: 0x102b070 */
  if (actionwk->userflag.b.h >= 0) /* Line 55, Address: 0x102b07c */
    togeball_main(actionwk); /* Line 56, Address: 0x102b094 */
  else
    togeball_opt(actionwk); /* Line 58, Address: 0x102b0a8 */
} /* Line 59, Address: 0x102b0b4 */

void togeball_main(sprite_status* actionwk) { /* Line 61, Address: 0x102b0d0 */
  switch (actionwk->r_no0) /* Line 62, Address: 0x102b0dc */
  {
    case 0:
      act_init(actionwk); /* Line 65, Address: 0x102b104 */
      break; /* Line 66, Address: 0x102b110 */
    case 2:
      act_move(actionwk); /* Line 68, Address: 0x102b118 */
      break;
  }
  actionsub(actionwk); /* Line 71, Address: 0x102b124 */
  frameout_s(actionwk); /* Line 72, Address: 0x102b130 */
} /* Line 73, Address: 0x102b13c */

static void act_init(sprite_status* actionwk) { /* Line 75, Address: 0x102b150 */
  sprite_status* a1;

  actionwk->r_no0 += 2; /* Line 78, Address: 0x102b15c */
  actionwk->actflg |= 4; /* Line 79, Address: 0x102b16c */
  actionwk->sprpri = 1; /* Line 80, Address: 0x102b17c */
  actionwk->sprhsize = 8; /* Line 81, Address: 0x102b188 */
  actionwk->sprvsize = 8; /* Line 82, Address: 0x102b194 */
  actionwk->patbase = pat_chg; /* Line 83, Address: 0x102b1a0 */
  actionwk->sproffset = 1016; /* Line 84, Address: 0x102b1b0 */
  ((short*)actionwk)[24] = 256; /* Line 85, Address: 0x102b1bc */
  if (actionwk->userflag.b.h != 0) /* Line 86, Address: 0x102b1c8 */
    ((short*)actionwk)[24] = -((short*)actionwk)[24]; /* Line 87, Address: 0x102b1e0 */


  if (actwkchk2(actionwk, &a1) != 0) /* Line 90, Address: 0x102b204 */
  {
    frameout(actionwk); /* Line 92, Address: 0x102b21c */
    return; /* Line 93, Address: 0x102b228 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 95, Address: 0x102b230 */
  ((unsigned short*)actionwk)[25] = a1 - actwk; /* Line 96, Address: 0x102b264 */
  a1->actno = actionwk->actno; /* Line 97, Address: 0x102b298 */
  a1->userflag.b.h = -1; /* Line 98, Address: 0x102b2a8 */
  a1->sprhsize = 8; /* Line 99, Address: 0x102b2b4 */
  a1->sprvsize = 8; /* Line 100, Address: 0x102b2c0 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 102, Address: 0x102b2cc */
  {
    frameout(actionwk); /* Line 104, Address: 0x102b2e4 */
    return; /* Line 105, Address: 0x102b2f0 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 107, Address: 0x102b2f8 */
  ((unsigned short*)actionwk)[26] = a1 - actwk; /* Line 108, Address: 0x102b32c */
  a1->actno = actionwk->actno; /* Line 109, Address: 0x102b360 */
  a1->userflag.b.h = -1; /* Line 110, Address: 0x102b370 */
  a1->sprhsize = 8; /* Line 111, Address: 0x102b37c */
  a1->sprvsize = 8; /* Line 112, Address: 0x102b388 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 114, Address: 0x102b394 */
  {
    frameout(actionwk); /* Line 116, Address: 0x102b3ac */
    return; /* Line 117, Address: 0x102b3b8 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 119, Address: 0x102b3c0 */
  ((unsigned short*)actionwk)[27] = a1 - actwk; /* Line 120, Address: 0x102b3f4 */
  a1->actno = actionwk->actno; /* Line 121, Address: 0x102b428 */
  a1->userflag.b.h = -1; /* Line 122, Address: 0x102b438 */
  a1->sprhsize = 8; /* Line 123, Address: 0x102b444 */
  a1->sprvsize = 8; /* Line 124, Address: 0x102b450 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 126, Address: 0x102b45c */
  {
    frameout(actionwk); /* Line 128, Address: 0x102b474 */
    return; /* Line 129, Address: 0x102b480 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 131, Address: 0x102b488 */
  ((unsigned short*)actionwk)[27] = a1 - actwk; /* Line 132, Address: 0x102b4bc */
  a1->actno = actionwk->actno; /* Line 133, Address: 0x102b4f0 */
  a1->userflag.b.h = -1; /* Line 134, Address: 0x102b500 */
  a1->sprhsize = 8; /* Line 135, Address: 0x102b50c */
  a1->sprvsize = 8; /* Line 136, Address: 0x102b518 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 138, Address: 0x102b524 */
  {
    frameout(actionwk); /* Line 140, Address: 0x102b53c */
    return; /* Line 141, Address: 0x102b548 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 143, Address: 0x102b550 */
  ((unsigned short*)actionwk)[28] = a1 - actwk; /* Line 144, Address: 0x102b584 */
  a1->actno = actionwk->actno; /* Line 145, Address: 0x102b5b8 */
  a1->userflag.b.h = -1; /* Line 146, Address: 0x102b5c8 */
  a1->sprhsize = 8; /* Line 147, Address: 0x102b5d4 */
  a1->sprvsize = 8; /* Line 148, Address: 0x102b5e0 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 150, Address: 0x102b5ec */
  {
    frameout(actionwk); /* Line 152, Address: 0x102b604 */
    return; /* Line 153, Address: 0x102b610 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 155, Address: 0x102b618 */
  ((unsigned short*)actionwk)[29] = a1 - actwk; /* Line 156, Address: 0x102b64c */
  a1->actno = actionwk->actno; /* Line 157, Address: 0x102b680 */
  a1->userflag.b.h = -1; /* Line 158, Address: 0x102b690 */
  a1->sprhsize = 8; /* Line 159, Address: 0x102b69c */
  a1->sprvsize = 8; /* Line 160, Address: 0x102b6a8 */
} /* Line 161, Address: 0x102b6b4 */

static void act_move(sprite_status* actionwk) { /* Line 163, Address: 0x102b6d0 */
  short d0;
  unsigned short sin, cos;
  int d0l, d1l, d2l, d3l, d4l, d5l;
  sprite_status* a1;

  d0 = ((short*)actionwk)[24]; /* Line 169, Address: 0x102b6fc */
  ((short*)actionwk)[23] += d0; /* Line 170, Address: 0x102b70c */
  d0 = ((short*)actionwk)[23]; /* Line 171, Address: 0x102b71c */
  d0 >>= 8; /* Line 172, Address: 0x102b72c */

  sinset(d0, (short*)&sin, (short*)&cos); /* Line 174, Address: 0x102b738 */
  d0l = d1l = 0; /* Line 175, Address: 0x102b74c */
  d0l = sin << 16; /* Line 176, Address: 0x102b754 */
  d1l = cos << 16; /* Line 177, Address: 0x102b760 */
  d0l >>= 2; /* Line 178, Address: 0x102b76c */
  d1l >>= 2; /* Line 179, Address: 0x102b770 */
  d4l = d0l; /* Line 180, Address: 0x102b774 */
  d5l = d1l; /* Line 181, Address: 0x102b778 */
  d0l >>= 1; /* Line 182, Address: 0x102b77c */
  d1l >>= 1; /* Line 183, Address: 0x102b780 */
  d2l = d0l; /* Line 184, Address: 0x102b784 */
  d3l = d1l; /* Line 185, Address: 0x102b788 */
  d0l >>= 1; /* Line 186, Address: 0x102b78c */
  d1l >>= 1; /* Line 187, Address: 0x102b790 */
  a1 = &actwk[((unsigned short*)actionwk)[25]]; /* Line 188, Address: 0x102b794 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d0l; /* Line 189, Address: 0x102b7b8 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d1l; /* Line 190, Address: 0x102b7cc */
  a1 = &actwk[((unsigned short*)actionwk)[26]]; /* Line 191, Address: 0x102b7e0 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d2l; /* Line 192, Address: 0x102b804 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d3l; /* Line 193, Address: 0x102b818 */
  a1 = &actwk[((unsigned short*)actionwk)[27]]; /* Line 194, Address: 0x102b82c */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d0l + d2l; /* Line 195, Address: 0x102b850 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d1l + d3l; /* Line 196, Address: 0x102b868 */

  a1 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 198, Address: 0x102b880 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d4l; /* Line 199, Address: 0x102b8a4 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d5l; /* Line 200, Address: 0x102b8b8 */
  a1 = &actwk[((unsigned short*)actionwk)[29]]; /* Line 201, Address: 0x102b8cc */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d0l + d4l; /* Line 202, Address: 0x102b8f0 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d1l + d5l; /* Line 203, Address: 0x102b908 */
} /* Line 204, Address: 0x102b920 */

void togeball_opt(sprite_status* actionwk) { /* Line 206, Address: 0x102b950 */
  sprite_status* a1;

  switch (actionwk->r_no0) /* Line 209, Address: 0x102b960 */
  {
    case 0:
      act_init2(actionwk); /* Line 212, Address: 0x102b988 */
    case 2:
      act_move2(actionwk); /* Line 214, Address: 0x102b994 */
      break;
  }
  a1 = &actwk[((unsigned short*)actionwk)[33]]; /* Line 217, Address: 0x102b9a0 */
  if (a1->actno != 45) /* Line 218, Address: 0x102b9c4 */
  {
    frameout(actionwk); /* Line 220, Address: 0x102b9d8 */
    return; /* Line 221, Address: 0x102b9e4 */
  }
  actionsub(actionwk); /* Line 223, Address: 0x102b9ec */
} /* Line 224, Address: 0x102b9f8 */

void act_init2(sprite_status* actionwk) { /* Line 226, Address: 0x102ba10 */
  actionwk->r_no0 += 2; /* Line 227, Address: 0x102ba18 */
  actionwk->actflg |= 4; /* Line 228, Address: 0x102ba28 */
  actionwk->sprpri = 1; /* Line 229, Address: 0x102ba38 */
  actionwk->patbase = pat_togeball; /* Line 230, Address: 0x102ba44 */
  actionwk->sproffset = 1016; /* Line 231, Address: 0x102ba54 */
  actionwk->colino = 185; /* Line 232, Address: 0x102ba60 */
} /* Line 233, Address: 0x102ba6c */

void act_move2(sprite_status* actionwk) { /* Line 235, Address: 0x102ba80 */
  actionwk->xposi.w.h = ((short*)actionwk)[24]; /* Line 236, Address: 0x102ba88 */
  actionwk->yposi.w.h = ((short*)actionwk)[26]; /* Line 237, Address: 0x102ba98 */
} /* Line 238, Address: 0x102baa8 */
