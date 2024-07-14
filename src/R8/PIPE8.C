#include "..\EQU.H"
#include "PIPE8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"

static char p00[5] = { 0, 1, 3, 5, -1 };
static char p01[6] = { 0, 4, 3, 2, 1, -1 };
static char* pchg[2] =
{
  p00,
  p01
};
static sprite_pattern pat00 =
{
  1,
  { { -8, -4, 0, 477 } }
};
static sprite_pattern pat01 =
{
  1,
  { { -16, -4, 0, 478 } }
};
static sprite_pattern pat02 =
{
  1,
  { { -20, -4, 0, 479 } }
};
static sprite_pattern pat03 =
{
  1,
  { { -24, -4, 0, 480 } }
};
static sprite_pattern pat04 =
{
  1,
  { { -28, -4, 0, 481 } }
};
static sprite_pattern pat05 =
{
  1,
  { { 0, 0, 0, 0 } }
};
sprite_pattern* pat_pipe8[6] =
{
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05
};





void pipe8(sprite_status* actionwk) { /* Line 59, Address: 0x1028ca0 */
  short ano;

  if (actionwk->userflag.b.l < 0) /* Line 62, Address: 0x1028cb0 */
  {
    shatter(actionwk); /* Line 64, Address: 0x1028cc8 */
    return; /* Line 65, Address: 0x1028cd4 */
  }

  if (actionwk->userflag.b.h < 0) /* Line 68, Address: 0x1028cdc */
  {
    ano = ((short*)actionwk)[33]; /* Line 70, Address: 0x1028cf4 */
    if (actwk[ano].actno != 32) /* Line 71, Address: 0x1028d04 */
    {
      frameout(actionwk); /* Line 73, Address: 0x1028d38 */
      return; /* Line 74, Address: 0x1028d44 */
    }
  }

  switch (actionwk->r_no0) /* Line 78, Address: 0x1028d4c */
  {
    case 0:
      act0wait(actionwk); /* Line 81, Address: 0x1028d8c */
    case 2:
      act0wait1(actionwk); /* Line 83, Address: 0x1028d98 */
      break; /* Line 84, Address: 0x1028da4 */
    case 4:
      act0init(actionwk); /* Line 86, Address: 0x1028dac */
    case 6:
      act0move(actionwk); /* Line 88, Address: 0x1028db8 */
      break;
  }
  actionsub(actionwk); /* Line 91, Address: 0x1028dc4 */
  if (actionwk->userflag.b.h < 0) return; /* Line 92, Address: 0x1028dd0 */
  frameout_s00(actionwk, ((short*)actionwk)[23]); /* Line 93, Address: 0x1028de8 */
} /* Line 94, Address: 0x1028dfc */

void act0wait(sprite_status* actionwk) { /* Line 96, Address: 0x1028e10 */
  ((short*)actionwk)[23] = actionwk->xposi.w.h; /* Line 97, Address: 0x1028e1c */
  act0init_sub(actionwk, actionwk); /* Line 98, Address: 0x1028e2c */
  actionwk->r_no0 = 2; /* Line 99, Address: 0x1028e3c */
  actionwk->patno = 5; /* Line 100, Address: 0x1028e48 */
} /* Line 101, Address: 0x1028e54 */

void act0wait1(sprite_status* actionwk) { /* Line 103, Address: 0x1028e70 */
  short d0;

  d0 = actwk[0].xposi.w.h - actionwk->xposi.w.h + 320; /* Line 106, Address: 0x1028e7c */
  if ((unsigned short)d0 >= 640) return; /* Line 107, Address: 0x1028eb4 */
  actionwk->r_no0 += 2; /* Line 108, Address: 0x1028ec8 */
  actionwk->patno = 0; /* Line 109, Address: 0x1028ed8 */
} /* Line 110, Address: 0x1028ee0 */

void act0init(sprite_status* actionwk) { /* Line 112, Address: 0x1028ef0 */
  sprite_status* a1;

  if (actwkchk(&a1) != 0) /* Line 115, Address: 0x1028efc */
  {
    frameout(actionwk); /* Line 117, Address: 0x1028f10 */
    return; /* Line 118, Address: 0x1028f1c */
  }
  a1->actno = actionwk->actno; /* Line 120, Address: 0x1028f24 */
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 121, Address: 0x1028f34 */
  a1->userflag.b.h = -1; /* Line 122, Address: 0x1028f68 */
  a1->xposi.w.h = actionwk->xposi.w.h + 48; /* Line 123, Address: 0x1028f74 */
  a1->actflg ^= 1; /* Line 124, Address: 0x1028f98 */
  a1->cddat ^= 1; /* Line 125, Address: 0x1028fa8 */

  act0init_sub(actionwk, actionwk); /* Line 127, Address: 0x1028fb8 */
  act0init_sub(actionwk, a1); /* Line 128, Address: 0x1028fc8 */

  if (actwkchk(&a1) != 0) /* Line 130, Address: 0x1028fd8 */
  {
    frameout(actionwk); /* Line 132, Address: 0x1028fec */
    return; /* Line 133, Address: 0x1028ff8 */
  }
  a1->actno = actionwk->actno; /* Line 135, Address: 0x1029000 */
  a1->userflag.b.h = actionwk->userflag.b.h; /* Line 136, Address: 0x1029010 */
  a1->userflag.b.l = -1; /* Line 137, Address: 0x1029020 */
  a1->xposi.w.h = actionwk->xposi.w.h + 24; /* Line 138, Address: 0x102902c */
  a1->yposi.w.h = actionwk->yposi.w.h; /* Line 139, Address: 0x1029050 */
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 140, Address: 0x1029060 */
} /* Line 141, Address: 0x1029094 */

void act0init_sub(sprite_status* actionwk, sprite_status* a6) { /* Line 143, Address: 0x10290b0 */
  a6->r_no0 = 6; /* Line 144, Address: 0x10290bc */
  a6->actflg |= 4; /* Line 145, Address: 0x10290c8 */
  a6->sprpri = 3; /* Line 146, Address: 0x10290d8 */
  a6->sproffset = 828; /* Line 147, Address: 0x10290e4 */
  a6->sprhs = 8; /* Line 148, Address: 0x10290f0 */
  a6->sprhsize = 8; /* Line 149, Address: 0x10290fc */
  a6->sprvsize = 4; /* Line 150, Address: 0x1029108 */
  a6->patbase = pat_pipe8; /* Line 151, Address: 0x1029114 */
  a6->yposi.w.h = actionwk->yposi.w.h; /* Line 152, Address: 0x1029124 */
} /* Line 153, Address: 0x1029134 */

void act0move(sprite_status* actionwk) { /* Line 155, Address: 0x1029140 */
  ridechk(actionwk, &actwk[0]); /* Line 156, Address: 0x102914c */
} /* Line 157, Address: 0x1029160 */



















void shatter(sprite_status* actionwk) { /* Line 177, Address: 0x1029170 */
  short ano;

  ano = ((unsigned short*)actionwk)[33]; /* Line 180, Address: 0x1029180 */
  if (actwk[ano].actno != 32) /* Line 181, Address: 0x1029190 */
  {
    frameout(actionwk); /* Line 183, Address: 0x10291c4 */
    return; /* Line 184, Address: 0x10291d0 */
  }
  switch (actionwk->r_no0) /* Line 186, Address: 0x10291d8 */
  {
    case 0:
      act1init(actionwk); /* Line 189, Address: 0x102923c */
      break; /* Line 190, Address: 0x1029248 */
    case 2:
      act1closed(actionwk); /* Line 192, Address: 0x1029250 */
      break; /* Line 193, Address: 0x102925c */
    case 4:
      act1closed1(actionwk); /* Line 195, Address: 0x1029264 */
      break; /* Line 196, Address: 0x1029270 */
    case 6:
      act1open_a(actionwk); /* Line 198, Address: 0x1029278 */
      break; /* Line 199, Address: 0x1029284 */
    case 8:
      act1opend_a(actionwk); /* Line 201, Address: 0x102928c */
      break; /* Line 202, Address: 0x1029298 */
    case 10:
      act1opend_b(actionwk); /* Line 204, Address: 0x10292a0 */
      break; /* Line 205, Address: 0x10292ac */
    case 12:
      act1close_b(actionwk); /* Line 207, Address: 0x10292b4 */
      break;
  }
  actionsub(actionwk); /* Line 210, Address: 0x10292c0 */
} /* Line 211, Address: 0x10292cc */

void act1init(sprite_status* actionwk) { /* Line 213, Address: 0x10292e0 */
  actionwk->r_no0 += 2; /* Line 214, Address: 0x10292e8 */
  actionwk->actflg |= 4; /* Line 215, Address: 0x10292f8 */
  actionwk->sprpri = 4; /* Line 216, Address: 0x1029308 */
  actionwk->sproffset = 828; /* Line 217, Address: 0x1029314 */
  actionwk->sprhs = 16; /* Line 218, Address: 0x1029320 */
  actionwk->sprhsize = 16; /* Line 219, Address: 0x102932c */
  actionwk->sprvsize = 4; /* Line 220, Address: 0x1029338 */
  actionwk->patbase = pat_pipe8; /* Line 221, Address: 0x1029344 */
} /* Line 222, Address: 0x1029354 */

void act1closed(sprite_status* actionwk) { /* Line 224, Address: 0x1029360 */
  actionwk->r_no0 += 2; /* Line 225, Address: 0x1029368 */
  actionwk->patno = 1; /* Line 226, Address: 0x1029378 */
  switchflag[actionwk->userflag.b.h] &= 191; /* Line 227, Address: 0x1029384 */
} /* Line 228, Address: 0x10293ac */

void act1closed1(sprite_status* actionwk) { /* Line 230, Address: 0x10293c0 */
  ridechk(actionwk, &actwk[0]); /* Line 231, Address: 0x10293cc */
  if ((char)switchflag[actionwk->userflag.b.h] < 0) /* Line 232, Address: 0x10293e0 */
  {
    to_act1open_a(actionwk); /* Line 234, Address: 0x1029418 */
    return; /* Line 235, Address: 0x1029424 */
  }

  if (!act1check2(actionwk, &actwk[0], -8, 16, -3, 123)) return; /* Line 238, Address: 0x102942c */

  to_act1opend_b(actionwk); /* Line 240, Address: 0x1029458 */
} /* Line 241, Address: 0x1029464 */

void to_act1open_a(sprite_status* actionwk) { /* Line 243, Address: 0x1029480 */
  actionwk->r_no0 += 2; /* Line 244, Address: 0x1029488 */
  ((short*)actionwk)[23] = 5; /* Line 245, Address: 0x1029498 */
} /* Line 246, Address: 0x10294a4 */

void to_act1opend_b(sprite_status* actionwk) { /* Line 248, Address: 0x10294b0 */
  actionwk->r_no0 += 6; /* Line 249, Address: 0x10294b8 */
  actionwk->patno = 5; /* Line 250, Address: 0x10294c8 */
} /* Line 251, Address: 0x10294d4 */

void act1open_a(sprite_status* actionwk) { /* Line 253, Address: 0x10294e0 */
  short t;

  --((short*)actionwk)[23]; /* Line 256, Address: 0x10294f0 */
  t = ((short*)actionwk)[23]; /* Line 257, Address: 0x1029500 */
  if (t < 0) /* Line 258, Address: 0x1029510 */
  {
    actionwk->r_no0 += 2; /* Line 260, Address: 0x1029520 */
    actionwk->patno = 5; /* Line 261, Address: 0x1029530 */
    return; /* Line 262, Address: 0x102953c */
  }

  patchg(actionwk, (unsigned char**)pchg); /* Line 265, Address: 0x1029544 */
} /* Line 266, Address: 0x1029558 */

void act1opend_a(sprite_status* actionwk) { /* Line 268, Address: 0x1029570 */
  if (act1check1(actionwk, &actwk[0], -256, 512, -160, 320) != 0) return; /* Line 269, Address: 0x102957c */

  to_act1closed_a(actionwk); /* Line 271, Address: 0x10295b0 */
} /* Line 272, Address: 0x10295bc */

void to_act1closed_a(sprite_status* actionwk) { /* Line 274, Address: 0x10295d0 */
  actionwk->r_no0 -= 6; /* Line 275, Address: 0x10295d8 */
} /* Line 276, Address: 0x10295e8 */

void act1opend_b(sprite_status* actionwk) { /* Line 278, Address: 0x1029600 */
  if (act1check2(actionwk, &actwk[0], -8, 16, -120, 116)) /* Line 279, Address: 0x102960c */
  {
    to_act1close_b(actionwk); /* Line 281, Address: 0x1029638 */
  }
} /* Line 283, Address: 0x1029644 */

void to_act1close_b(sprite_status* actionwk) { /* Line 285, Address: 0x1029660 */
  actionwk->r_no0 += 2; /* Line 286, Address: 0x1029668 */
  actionwk->mstno.b.h = 1; /* Line 287, Address: 0x1029678 */
  ((short*)actionwk)[23] = 7; /* Line 288, Address: 0x1029684 */
} /* Line 289, Address: 0x1029690 */

void act1close_b(sprite_status* actionwk) { /* Line 291, Address: 0x10296a0 */
  short t;
  --((short*)actionwk)[23]; /* Line 293, Address: 0x10296b0 */
  t = ((short*)actionwk)[23]; /* Line 294, Address: 0x10296c0 */
  if (t < 0) /* Line 295, Address: 0x10296d0 */
  {
    actionwk->r_no0 -= 10; /* Line 297, Address: 0x10296e0 */
    actionwk->mstno.b.h = 0; /* Line 298, Address: 0x10296f0 */
    actionwk->patno = 1; /* Line 299, Address: 0x10296f8 */
  } /* Line 300, Address: 0x1029704 */
  else
  {
    patchg(actionwk, (unsigned char**)pchg); /* Line 303, Address: 0x102970c */
  }
} /* Line 305, Address: 0x1029720 */


short act1check2(sprite_status* actionwk, sprite_status* a6, short d0, short d1, short d2, short d3) { /* Line 308, Address: 0x1029740 */
  if (a6->yspeed.w >= 0) return 0; /* Line 309, Address: 0x1029760 */
  else return act1check1(actionwk, a6, d0, d1, d2, d3); /* Line 310, Address: 0x1029784 */
} /* Line 311, Address: 0x10297a4 */



short act1check1(sprite_status* actionwk, sprite_status* a6, short d0, short d1, short d2, short d3) { /* Line 315, Address: 0x10297c0 */
  short d4;

  d4 = a6->yposi.w.h - actionwk->yposi.w.h; /* Line 318, Address: 0x10297e0 */
  d4 -= d2; /* Line 319, Address: 0x1029814 */
  if ((unsigned short)d3 <= (unsigned short)d4) return 0; /* Line 320, Address: 0x1029824 */
  d4 = a6->xposi.w.h - actionwk->xposi.w.h; /* Line 321, Address: 0x1029850 */
  d4 -= d0; /* Line 322, Address: 0x1029884 */
  if ((unsigned short)d1 <= (unsigned short)d4) return 0; /* Line 323, Address: 0x1029894 */
  return 1; /* Line 324, Address: 0x10298c0 */
} /* Line 325, Address: 0x10298c4 */
