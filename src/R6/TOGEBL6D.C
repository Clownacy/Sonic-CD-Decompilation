#include "..\EQU.H"
#include "TOGEBL6A.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"

static void act_init(sprite_status* actionwk);
static void act_move(sprite_status* actionwk);

static sprite_pattern spat_chg0 = {
  1,
  { { -8, -8, 0, 497 } }
};
static sprite_pattern spat_chg1 = {
  1,
  { { -8, -8, 0, 498 } }
};
sprite_pattern* pat_chg[1] = { &spat_chg0 };
sprite_pattern* pat_togeball[1] = { &spat_chg1 };



































void togeball(sprite_status* actionwk) { /* Line 55, Address: 0x10273b0 */
  if (actionwk->userflag.b.h >= 0) /* Line 56, Address: 0x10273bc */
    togeball_main(actionwk); /* Line 57, Address: 0x10273d4 */
  else
    togeball_opt(actionwk); /* Line 59, Address: 0x10273e8 */
} /* Line 60, Address: 0x10273f4 */

void togeball_main(sprite_status* actionwk) { /* Line 62, Address: 0x1027410 */
  switch (actionwk->r_no0) /* Line 63, Address: 0x102741c */
  {
    case 0:
      act_init(actionwk); /* Line 66, Address: 0x1027444 */
      break; /* Line 67, Address: 0x1027450 */
    case 2:
      act_move(actionwk); /* Line 69, Address: 0x1027458 */
      break;
  }
  actionsub(actionwk); /* Line 72, Address: 0x1027464 */
  frameout_s(actionwk); /* Line 73, Address: 0x1027470 */
} /* Line 74, Address: 0x102747c */

void act_init(sprite_status* actionwk) { /* Line 76, Address: 0x1027490 */
  sprite_status* a1;

  actionwk->r_no0 += 2; /* Line 79, Address: 0x102749c */
  actionwk->actflg |= 4; /* Line 80, Address: 0x10274ac */
  actionwk->sprpri = 1; /* Line 81, Address: 0x10274bc */
  actionwk->sprhsize = 8; /* Line 82, Address: 0x10274c8 */
  actionwk->sprvsize = 8; /* Line 83, Address: 0x10274d4 */
  actionwk->patbase = pat_chg; /* Line 84, Address: 0x10274e0 */
  actionwk->sproffset = 1016; /* Line 85, Address: 0x10274f0 */
  ((short*)actionwk)[24] = 256; /* Line 86, Address: 0x10274fc */
  if (actionwk->userflag.b.h != 0) /* Line 87, Address: 0x1027508 */
    ((short*)actionwk)[24] = -((short*)actionwk)[24]; /* Line 88, Address: 0x1027520 */


  if (actwkchk2(actionwk, &a1) != 0) /* Line 91, Address: 0x1027544 */
  {
    frameout(actionwk); /* Line 93, Address: 0x102755c */
    return; /* Line 94, Address: 0x1027568 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 96, Address: 0x1027570 */
  ((unsigned short*)actionwk)[25] = a1 - actwk; /* Line 97, Address: 0x10275a4 */
  a1->actno = actionwk->actno; /* Line 98, Address: 0x10275d8 */
  a1->userflag.b.h = -1; /* Line 99, Address: 0x10275e8 */
  a1->sprhsize = 8; /* Line 100, Address: 0x10275f4 */
  a1->sprvsize = 8; /* Line 101, Address: 0x1027600 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 103, Address: 0x102760c */
  {
    frameout(actionwk); /* Line 105, Address: 0x1027624 */
    return; /* Line 106, Address: 0x1027630 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 108, Address: 0x1027638 */
  ((unsigned short*)actionwk)[26] = a1 - actwk; /* Line 109, Address: 0x102766c */
  a1->actno = actionwk->actno; /* Line 110, Address: 0x10276a0 */
  a1->userflag.b.h = -1; /* Line 111, Address: 0x10276b0 */
  a1->sprhsize = 8; /* Line 112, Address: 0x10276bc */
  a1->sprvsize = 8; /* Line 113, Address: 0x10276c8 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 115, Address: 0x10276d4 */
  {
    frameout(actionwk); /* Line 117, Address: 0x10276ec */
    return; /* Line 118, Address: 0x10276f8 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 120, Address: 0x1027700 */
  ((unsigned short*)actionwk)[27] = a1 - actwk; /* Line 121, Address: 0x1027734 */
  a1->actno = actionwk->actno; /* Line 122, Address: 0x1027768 */
  a1->userflag.b.h = -1; /* Line 123, Address: 0x1027778 */
  a1->sprhsize = 8; /* Line 124, Address: 0x1027784 */
  a1->sprvsize = 8; /* Line 125, Address: 0x1027790 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 127, Address: 0x102779c */
  {
    frameout(actionwk); /* Line 129, Address: 0x10277b4 */
    return; /* Line 130, Address: 0x10277c0 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 132, Address: 0x10277c8 */
  ((unsigned short*)actionwk)[28] = a1 - actwk; /* Line 133, Address: 0x10277fc */
  a1->actno = actionwk->actno; /* Line 134, Address: 0x1027830 */
  a1->userflag.b.h = -1; /* Line 135, Address: 0x1027840 */
  a1->sprhsize = 8; /* Line 136, Address: 0x102784c */
  a1->sprvsize = 8; /* Line 137, Address: 0x1027858 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 139, Address: 0x1027864 */
  {
    frameout(actionwk); /* Line 141, Address: 0x102787c */
    return; /* Line 142, Address: 0x1027888 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 144, Address: 0x1027890 */
  ((unsigned short*)actionwk)[29] = a1 - actwk; /* Line 145, Address: 0x10278c4 */
  a1->actno = actionwk->actno; /* Line 146, Address: 0x10278f8 */
  a1->userflag.b.h = -1; /* Line 147, Address: 0x1027908 */
  a1->sprhsize = 8; /* Line 148, Address: 0x1027914 */
  a1->sprvsize = 8; /* Line 149, Address: 0x1027920 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 151, Address: 0x102792c */
  {
    frameout(actionwk); /* Line 153, Address: 0x1027944 */
    return; /* Line 154, Address: 0x1027950 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 156, Address: 0x1027958 */
  ((unsigned short*)actionwk)[30] = a1 - actwk; /* Line 157, Address: 0x102798c */
  a1->actno = actionwk->actno; /* Line 158, Address: 0x10279c0 */
  a1->userflag.b.h = -1; /* Line 159, Address: 0x10279d0 */
  a1->sprhsize = 8; /* Line 160, Address: 0x10279dc */
  a1->sprvsize = 8; /* Line 161, Address: 0x10279e8 */
} /* Line 162, Address: 0x10279f4 */

void act_move(sprite_status* actionwk) { /* Line 164, Address: 0x1027a10 */
  short d0, ano;
  unsigned short sin, cos;
  int d0l, d1l, d2l, d3l, d4l, d5l;
  sprite_status* adr1;

  d0 = ((short*)actionwk)[24]; /* Line 170, Address: 0x1027a40 */
  ((short*)actionwk)[23] += d0; /* Line 171, Address: 0x1027a50 */
  d0 = ((short*)actionwk)[23]; /* Line 172, Address: 0x1027a60 */
  d0 >>= 8; /* Line 173, Address: 0x1027a70 */

  sinset(d0, (short*)&sin, (short*)&cos); /* Line 175, Address: 0x1027a7c */
  d0l = d1l = 0; /* Line 176, Address: 0x1027a90 */
  d0l = sin << 16; /* Line 177, Address: 0x1027a98 */
  d1l = cos << 16; /* Line 178, Address: 0x1027aa4 */
  d0l >>= 2; /* Line 179, Address: 0x1027ab0 */
  d1l >>= 2; /* Line 180, Address: 0x1027ab4 */
  d4l = d0l; /* Line 181, Address: 0x1027ab8 */
  d5l = d1l; /* Line 182, Address: 0x1027abc */
  d0l >>= 1; /* Line 183, Address: 0x1027ac0 */
  d1l >>= 1; /* Line 184, Address: 0x1027ac4 */
  d2l = d0l; /* Line 185, Address: 0x1027ac8 */
  d3l = d1l; /* Line 186, Address: 0x1027acc */
  d0l >>= 1; /* Line 187, Address: 0x1027ad0 */
  d1l >>= 1; /* Line 188, Address: 0x1027ad4 */
  ano = actionwk->actfree[4]; /* Line 189, Address: 0x1027ad8 */
  *(int*)&actwk[ano].actfree[4] = actionwk->yposi.l + d0l; /* Line 190, Address: 0x1027aec */
  *(int*)&actwk[ano].actfree[0] = actionwk->xposi.l + d1l; /* Line 191, Address: 0x1027b20 */

  adr1 = &actwk[((unsigned short*)actionwk)[25]]; /* Line 193, Address: 0x1027b54 */
  *(int*)&adr1->actfree[4] = actionwk->yposi.l + d0l; /* Line 194, Address: 0x1027b78 */
  *(int*)&adr1->actfree[0] = actionwk->xposi.l + d1l; /* Line 195, Address: 0x1027b8c */
  adr1 = &actwk[((unsigned short*)actionwk)[26]]; /* Line 196, Address: 0x1027ba0 */
  *(int*)&adr1->actfree[4] = actionwk->yposi.l + d2l; /* Line 197, Address: 0x1027bc4 */
  *(int*)&adr1->actfree[0] = actionwk->xposi.l + d3l; /* Line 198, Address: 0x1027bd8 */
  adr1 = &actwk[((unsigned short*)actionwk)[27]]; /* Line 199, Address: 0x1027bec */
  *(int*)&adr1->actfree[4] = actionwk->yposi.l + d0l + d2l; /* Line 200, Address: 0x1027c10 */
  *(int*)&adr1->actfree[0] = actionwk->xposi.l + d1l + d3l; /* Line 201, Address: 0x1027c28 */

  adr1 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 203, Address: 0x1027c40 */
  *(int*)&adr1->actfree[4] = actionwk->yposi.l + d4l; /* Line 204, Address: 0x1027c64 */
  *(int*)&adr1->actfree[0] = actionwk->xposi.l + d5l; /* Line 205, Address: 0x1027c78 */
  adr1 = &actwk[((unsigned short*)actionwk)[29]]; /* Line 206, Address: 0x1027c8c */
  *(int*)&adr1->actfree[4] = actionwk->yposi.l + d0l + d4l; /* Line 207, Address: 0x1027cb0 */
  *(int*)&adr1->actfree[0] = actionwk->xposi.l + d1l + d5l; /* Line 208, Address: 0x1027cc8 */
  adr1 = &actwk[((unsigned short*)actionwk)[30]]; /* Line 209, Address: 0x1027ce0 */
  *(int*)&adr1->actfree[4] = actionwk->yposi.l + d2l + d4l; /* Line 210, Address: 0x1027d04 */
  *(int*)&adr1->actfree[0] = actionwk->xposi.l + d3l + d5l; /* Line 211, Address: 0x1027d1c */

} /* Line 213, Address: 0x1027d34 */

void togeball_opt(sprite_status* actionwk) { /* Line 215, Address: 0x1027d70 */
  short ano;

  switch (actionwk->r_no0) /* Line 218, Address: 0x1027d80 */
  {
    case 0:
      act_init2(actionwk); /* Line 221, Address: 0x1027da8 */
    case 2:
      act_move2(actionwk); /* Line 223, Address: 0x1027db4 */
      break;
  }
  ano = actionwk->actfree[20]; /* Line 226, Address: 0x1027dc0 */
  if (actwk[ano].actno != 45) /* Line 227, Address: 0x1027dd4 */
  {
    frameout(actionwk); /* Line 229, Address: 0x1027e08 */
    return; /* Line 230, Address: 0x1027e14 */
  }
  actionsub(actionwk); /* Line 232, Address: 0x1027e1c */
} /* Line 233, Address: 0x1027e28 */

void act_init2(sprite_status* actionwk) { /* Line 235, Address: 0x1027e40 */
  actionwk->r_no0 += 2; /* Line 236, Address: 0x1027e48 */
  actionwk->actflg |= 4; /* Line 237, Address: 0x1027e58 */
  actionwk->sprpri = 1; /* Line 238, Address: 0x1027e68 */
  actionwk->patbase = pat_togeball; /* Line 239, Address: 0x1027e74 */
  actionwk->sproffset = 1016; /* Line 240, Address: 0x1027e84 */
  actionwk->colino = 185; /* Line 241, Address: 0x1027e90 */
} /* Line 242, Address: 0x1027e9c */

void act_move2(sprite_status* actionwk) { /* Line 244, Address: 0x1027eb0 */
  actionwk->xposi.w.h = ((short*)actionwk)[24]; /* Line 245, Address: 0x1027eb8 */
  actionwk->yposi.w.h = ((short*)actionwk)[26]; /* Line 246, Address: 0x1027ec8 */
} /* Line 247, Address: 0x1027ed8 */
