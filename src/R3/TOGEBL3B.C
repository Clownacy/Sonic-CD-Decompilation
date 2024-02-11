#include "..\EQU.H"
#include "TOGEBL3A.H"

static sprite_pattern spat_chg0 = {
  1,
  { { -8, -8, 0, 550 } }
};
static sprite_pattern spat_chg1 = {
  1,
  { { -8, -8, 0, 551 } }
};
sprite_pattern* pat_chg[1] = { &spat_chg0 };
sprite_pattern* togeball_pat[1] = { &spat_chg1 };





































void togeball(sprite_status* actionwk) { /* Line 51, Address: 0x102bcc0 */
  if (actionwk->userflag.b.h >= 0) /* Line 52, Address: 0x102bccc */
    togeball_main(actionwk); /* Line 53, Address: 0x102bce4 */
  else
    togeball_opt(actionwk); /* Line 55, Address: 0x102bcf8 */
} /* Line 56, Address: 0x102bd04 */

void togeball_main(sprite_status* actionwk) { /* Line 58, Address: 0x102bd20 */
  switch (actionwk->r_no0) { /* Line 59, Address: 0x102bd2c */

    case 0:
      act_init(actionwk); /* Line 62, Address: 0x102bd54 */
      break; /* Line 63, Address: 0x102bd60 */
    case 2:
      act_move(actionwk); /* Line 65, Address: 0x102bd68 */
      break;
  }
  actionsub(actionwk); /* Line 68, Address: 0x102bd74 */
  frameout_s(actionwk); /* Line 69, Address: 0x102bd80 */
} /* Line 70, Address: 0x102bd8c */

void act_init(sprite_status* actionwk) { /* Line 72, Address: 0x102bda0 */
  sprite_status* a1;

  actionwk->r_no0 += 2; /* Line 75, Address: 0x102bdac */
  actionwk->actflg |= 4; /* Line 76, Address: 0x102bdbc */
  actionwk->sprpri = 1; /* Line 77, Address: 0x102bdcc */
  actionwk->sprhsize = 8; /* Line 78, Address: 0x102bdd8 */
  actionwk->sprvsize = 8; /* Line 79, Address: 0x102bde4 */
  actionwk->patbase = pat_chg; /* Line 80, Address: 0x102bdf0 */
  actionwk->sproffset = 957; /* Line 81, Address: 0x102be00 */
  ((short*)actionwk)[24] = 256; /* Line 82, Address: 0x102be0c */
  if (actionwk->userflag.b.h != 0) /* Line 83, Address: 0x102be18 */
    ((short*)actionwk)[24] = -((short*)actionwk)[24]; /* Line 84, Address: 0x102be30 */


  if (actwkchk2(actionwk, &a1) != 0) { /* Line 87, Address: 0x102be54 */

    frameout(actionwk); /* Line 89, Address: 0x102be6c */
    return; /* Line 90, Address: 0x102be78 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 92, Address: 0x102be80 */
  ((unsigned short*)actionwk)[25] = a1 - actwk; /* Line 93, Address: 0x102beb4 */
  a1->actno = actionwk->actno; /* Line 94, Address: 0x102bee8 */
  a1->userflag.b.h = -1; /* Line 95, Address: 0x102bef8 */
  a1->sprhsize = 8; /* Line 96, Address: 0x102bf04 */
  a1->sprvsize = 8; /* Line 97, Address: 0x102bf10 */

  if (actwkchk2(actionwk, &a1) != 0) { /* Line 99, Address: 0x102bf1c */

    frameout(actionwk); /* Line 101, Address: 0x102bf34 */
    return; /* Line 102, Address: 0x102bf40 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 104, Address: 0x102bf48 */
  ((unsigned short*)actionwk)[26] = a1 - actwk; /* Line 105, Address: 0x102bf7c */
  a1->actno = actionwk->actno; /* Line 106, Address: 0x102bfb0 */
  a1->userflag.b.h = -1; /* Line 107, Address: 0x102bfc0 */
  a1->sprhsize = 8; /* Line 108, Address: 0x102bfcc */
  a1->sprvsize = 8; /* Line 109, Address: 0x102bfd8 */

} /* Line 111, Address: 0x102bfe4 */

void act_move(sprite_status* actionwk) { /* Line 113, Address: 0x102c000 */
  short d0;
  unsigned short sin, cos;
  int d0l, d1l, d2l, d3l, d4l, d5l;
  sprite_status* a1;

  d0 = ((short*)actionwk)[24]; /* Line 119, Address: 0x102c02c */
  ((short*)actionwk)[23] += d0; /* Line 120, Address: 0x102c03c */
  d0 = ((short*)actionwk)[23]; /* Line 121, Address: 0x102c04c */
  d0 >>= 8; /* Line 122, Address: 0x102c05c */

  sinset(d0, &sin, &cos); /* Line 124, Address: 0x102c068 */
  d0l = d1l = 0; /* Line 125, Address: 0x102c07c */
  d0l = sin << 16; /* Line 126, Address: 0x102c084 */
  d1l = cos << 16; /* Line 127, Address: 0x102c090 */
  d0l >>= 2; /* Line 128, Address: 0x102c09c */
  d1l >>= 2; /* Line 129, Address: 0x102c0a0 */
  d4l = d0l; /* Line 130, Address: 0x102c0a4 */
  d5l = d1l; /* Line 131, Address: 0x102c0a8 */
  d0l >>= 1; /* Line 132, Address: 0x102c0ac */
  d1l >>= 1; /* Line 133, Address: 0x102c0b0 */
  d2l = d0l; /* Line 134, Address: 0x102c0b4 */
  d3l = d1l; /* Line 135, Address: 0x102c0b8 */
  d0l >>= 1; /* Line 136, Address: 0x102c0bc */
  d1l >>= 1; /* Line 137, Address: 0x102c0c0 */
  a1 = &actwk[((unsigned short*)actionwk)[25]]; /* Line 138, Address: 0x102c0c4 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d0l; /* Line 139, Address: 0x102c0e8 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d1l; /* Line 140, Address: 0x102c0fc */
  a1 = &actwk[((unsigned short*)actionwk)[26]]; /* Line 141, Address: 0x102c110 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d2l; /* Line 142, Address: 0x102c134 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d3l; /* Line 143, Address: 0x102c148 */
} /* Line 144, Address: 0x102c15c */

void togeball_opt(sprite_status* actionwk) { /* Line 146, Address: 0x102c190 */
  sprite_status* a1;

  switch (actionwk->r_no0) { /* Line 149, Address: 0x102c1a0 */

    case 0:
      act_init2(actionwk); /* Line 152, Address: 0x102c1c8 */
    case 2:
      act_move2(actionwk); /* Line 154, Address: 0x102c1d4 */
      break;
  }
  a1 = &actwk[((unsigned short*)actionwk)[33]]; /* Line 157, Address: 0x102c1e0 */
  if (a1->actno != 44) { /* Line 158, Address: 0x102c204 */

    frameout(actionwk); /* Line 160, Address: 0x102c218 */
    return; /* Line 161, Address: 0x102c224 */
  }
  actionsub(actionwk); /* Line 163, Address: 0x102c22c */
} /* Line 164, Address: 0x102c238 */

void act_init2(sprite_status* actionwk) { /* Line 166, Address: 0x102c250 */
  actionwk->r_no0 += 2; /* Line 167, Address: 0x102c258 */
  actionwk->actflg |= 4; /* Line 168, Address: 0x102c268 */
  actionwk->sprpri = 1; /* Line 169, Address: 0x102c278 */
  actionwk->patbase = togeball_pat; /* Line 170, Address: 0x102c284 */
  actionwk->sproffset = 957; /* Line 171, Address: 0x102c294 */
  actionwk->colino = 139; /* Line 172, Address: 0x102c2a0 */
} /* Line 173, Address: 0x102c2ac */

void act_move2(sprite_status* actionwk) { /* Line 175, Address: 0x102c2c0 */
  actionwk->xposi.w.h = ((short*)actionwk)[24]; /* Line 176, Address: 0x102c2c8 */
  actionwk->yposi.w.h = ((short*)actionwk)[26]; /* Line 177, Address: 0x102c2d8 */
} /* Line 178, Address: 0x102c2e8 */
