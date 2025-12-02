#include "..\EQU.H"
#include "POCKET.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SCORE.H"

#if defined(R31A)
  #define SPRITE_POCKET_BASE 558
#elif defined(R31B) || defined(R32A)
  #define SPRITE_POCKET_BASE 552
#elif defined(R33C) || defined(R33D)
  #define SPRITE_POCKET_BASE 556
#else
  #define SPRITE_POCKET_BASE 505
#endif

static sprite_pattern pat_pocket1 =
{
  1,
  { { 0, 0, 0, 0 } }
};
static sprite_pattern pat_pocket2 =
{
  1,
  { { -24, -8, 0, SPRITE_POCKET_BASE } }
};
static sprite_pattern pat_pocket3 =
{
  1,
  { { -16, -24, 0, SPRITE_POCKET_BASE + 1 } }
};
static sprite_pattern pat_pocket4 =
{
  1,
  { { -8, -16, 0, SPRITE_POCKET_BASE + 2 } }
};
static sprite_pattern pat_pocket5 =
{
  1,
  { { -24, -8, 0, SPRITE_POCKET_BASE + 3 } }
};
sprite_pattern* pat[4] =
{
  &pat_pocket1,
  &pat_pocket2,
  &pat_pocket3,
  &pat_pocket4
};
sprite_pattern* pat_pocket[2] =
{
  &pat_pocket5,
  &pat_pocket1
};
static char pchg0[4] = { 3, 0, 1, -1 };
static char* pchg[1] = { pchg0 };
void(*pocket_move_tbl[11])(sprite_status*) =
{
  &a_init,
  &a_move0,
  &a_move00,
  &a_move1,
  &a_move2,
  &a_move3,
  &a_move4,
  &a_move5,
  &a_move6,
  &a_move7,
  &a_move8
};















void pocket(sprite_status* actionwk) { /* Line 87, Address: 0x101f4c0 */
  if (actionwk->userflag.b.h < 0) /* Line 88, Address: 0x101f4cc */
    pocket0(actionwk); /* Line 89, Address: 0x101f4e4 */
  else
    pocket1(actionwk); /* Line 91, Address: 0x101f4f8 */
} /* Line 92, Address: 0x101f504 */















void pocket0(sprite_status* actionwk) { /* Line 108, Address: 0x101f520 */
  pocket_move_tbl[actionwk->r_no0 / 2](actionwk); /* Line 109, Address: 0x101f52c */
  actionsub(actionwk); /* Line 110, Address: 0x101f570 */
  frameout_s(actionwk); /* Line 111, Address: 0x101f57c */
} /* Line 112, Address: 0x101f588 */

void a_init(sprite_status* actionwk) { /* Line 114, Address: 0x101f5a0 */
  if (time_flag == 2 && generate_flag != 0) /* Line 115, Address: 0x101f5ac */
  {
    frameout(actionwk); /* Line 117, Address: 0x101f5d8 */
    return; /* Line 118, Address: 0x101f5e4 */
  }

  actionwk->r_no0 += 2; /* Line 121, Address: 0x101f5ec */
  actionwk->actflg |= 4; /* Line 122, Address: 0x101f5fc */
  actionwk->sprpri = 0; /* Line 123, Address: 0x101f60c */
  actionwk->sproffset = 943; /* Line 124, Address: 0x101f614 */
  actionwk->patbase = pat; /* Line 125, Address: 0x101f620 */

  ((short*)actionwk)[26] = 7; /* Line 127, Address: 0x101f630 */
  a_move0(actionwk); /* Line 128, Address: 0x101f63c */
} /* Line 129, Address: 0x101f648 */

void a_move0(sprite_status* actionwk) { /* Line 131, Address: 0x101f660 */
  sprite_status* a6;

  if (editmode.w) return; /* Line 134, Address: 0x101f670 */
  a6 = &actwk[0]; /* Line 135, Address: 0x101f680 */
  a_check(actionwk, a6); /* Line 136, Address: 0x101f688 */
  if (actionwk->actfree[20] != 0) to_a_move1(actionwk); /* Line 137, Address: 0x101f698 */
} /* Line 138, Address: 0x101f6b8 */

void a_check(sprite_status* actionwk, sprite_status* a6) { /* Line 140, Address: 0x101f6d0 */
  short d0;

  if (a6->yspeed.w < 0) return; /* Line 143, Address: 0x101f6e0 */
  if (a6->r_no0 == 4 || a6->r_no0 == 6) return; /* Line 144, Address: 0x101f6f8 */
  d0 = a6->yposi.w.h - actionwk->yposi.w.h; /* Line 145, Address: 0x101f730 */
  d0 += 24; /* Line 146, Address: 0x101f764 */
  if (d0 < 0 || d0 >= 16) return; /* Line 147, Address: 0x101f770 */
  d0 = a6->xposi.w.h - actionwk->xposi.w.h; /* Line 148, Address: 0x101f79c */
  d0 += 24; /* Line 149, Address: 0x101f7d0 */
  if (d0 < 0 || d0 >= 48) return; /* Line 150, Address: 0x101f7dc */

  actionwk->actfree[20] = 255; /* Line 152, Address: 0x101f808 */
  a6->actfree[2] |= 1; /* Line 153, Address: 0x101f814 */
  a6->cddat |= 4; /* Line 154, Address: 0x101f824 */
  a6->sprvsize = 14; /* Line 155, Address: 0x101f834 */
  a6->sprhs = 7; /* Line 156, Address: 0x101f840 */
  a6->mstno.b.h = 2; /* Line 157, Address: 0x101f84c */
  a6->xspeed.w = 0; /* Line 158, Address: 0x101f858 */
  a6->yspeed.w = -2048; /* Line 159, Address: 0x101f860 */
  a6->xposi.w.h = actionwk->xposi.w.h; /* Line 160, Address: 0x101f86c */
  a6->yposi.w.h = actionwk->yposi.w.h - 16; /* Line 161, Address: 0x101f87c */
} /* Line 162, Address: 0x101f8a0 */

void to_a_move1(sprite_status* actionwk) { /* Line 164, Address: 0x101f8b0 */
  actionwk->r_no0 += 2; /* Line 165, Address: 0x101f8bc */
  ((short*)actionwk)[23] = 8; /* Line 166, Address: 0x101f8cc */
  actionwk->patno = 1; /* Line 167, Address: 0x101f8d8 */
  soundset(215); /* Line 168, Address: 0x101f8e4 */
  a_move00(actionwk); /* Line 169, Address: 0x101f8f0 */
} /* Line 170, Address: 0x101f8fc */

void a_move00(sprite_status* actionwk) { /* Line 172, Address: 0x101f910 */
  sprite_status* a1;

  if (--((short*)actionwk)[23] >= 0) return; /* Line 175, Address: 0x101f91c */
  actionwk->r_no0 += 2; /* Line 176, Address: 0x101f944 */
  actionwk->patno = 2; /* Line 177, Address: 0x101f954 */
  ((short*)actionwk)[23] = 6; /* Line 178, Address: 0x101f960 */
  if (actwkchk(&a1) != 0) /* Line 179, Address: 0x101f96c */
  {
    frameout(actionwk); /* Line 181, Address: 0x101f980 */
    return; /* Line 182, Address: 0x101f98c */
  }
  ((unsigned short*)actionwk)[24] = a1 - actwk; /* Line 184, Address: 0x101f994 */
  ((unsigned short*)a1)[25] = actionwk - actwk; /* Line 185, Address: 0x101f9c8 */
  a1->actno = actionwk->actno; /* Line 186, Address: 0x101f9fc */

  a1->xposi.w.h = actionwk->xposi.w.h; /* Line 188, Address: 0x101fa0c */
  a1->yposi.w.h = actionwk->yposi.w.h; /* Line 189, Address: 0x101fa1c */
  actwk[0].actfree[2] |= 64; /* Line 190, Address: 0x101fa2c */
} /* Line 191, Address: 0x101fa40 */

void a_move1(sprite_status* actionwk) { /* Line 193, Address: 0x101fa50 */
  if (--((short*)actionwk)[23] >= 0) return; /* Line 194, Address: 0x101fa58 */
  actionwk->r_no0 += 2; /* Line 195, Address: 0x101fa80 */
  ((short*)actionwk)[23] = 2; /* Line 196, Address: 0x101fa90 */
  actionwk->patno = 3; /* Line 197, Address: 0x101fa9c */

} /* Line 199, Address: 0x101faa8 */

void a_move2(sprite_status* actionwk) { /* Line 201, Address: 0x101fac0 */
  if (--((short*)actionwk)[23] >= 0) return; /* Line 202, Address: 0x101fac8 */
  actionwk->r_no0 += 2; /* Line 203, Address: 0x101faf0 */
  ((short*)actionwk)[23] = 30; /* Line 204, Address: 0x101fb00 */
  actionwk->patno = 0; /* Line 205, Address: 0x101fb0c */
} /* Line 206, Address: 0x101fb14 */

void a_move3(sprite_status* actionwk) { /* Line 208, Address: 0x101fb20 */
  if (--((short*)actionwk)[23] >= 0) return; /* Line 209, Address: 0x101fb2c */
  actionwk->r_no0 += 2; /* Line 210, Address: 0x101fb54 */
  ((short*)actionwk)[23] = 30; /* Line 211, Address: 0x101fb64 */
  if (((unsigned short*)actionwk)[26] == 0) return; /* Line 212, Address: 0x101fb70 */
  --((unsigned short*)actionwk)[26]; /* Line 213, Address: 0x101fb84 */
  scoreup(10); /* Line 214, Address: 0x101fb94 */
  tensuu0(actionwk, 0); /* Line 215, Address: 0x101fba0 */
} /* Line 216, Address: 0x101fbb0 */

void a_move4(sprite_status* actionwk) { /* Line 218, Address: 0x101fbc0 */
  if (--((short*)actionwk)[23] >= 0) return; /* Line 219, Address: 0x101fbcc */
  actionwk->r_no0 += 2; /* Line 220, Address: 0x101fbf4 */
  ((short*)actionwk)[23] = 30; /* Line 221, Address: 0x101fc04 */
  if (((unsigned short*)actionwk)[26] == 0) return; /* Line 222, Address: 0x101fc10 */
  --((unsigned short*)actionwk)[26]; /* Line 223, Address: 0x101fc24 */
  scoreup(10); /* Line 224, Address: 0x101fc34 */
  tensuu0(actionwk, 0); /* Line 225, Address: 0x101fc40 */
} /* Line 226, Address: 0x101fc50 */

void a_move5(sprite_status* actionwk) { /* Line 228, Address: 0x101fc60 */
  if (--((short*)actionwk)[23] >= 0) return; /* Line 229, Address: 0x101fc68 */
  actionwk->r_no0 += 2; /* Line 230, Address: 0x101fc90 */
  ((short*)actionwk)[23] = 4; /* Line 231, Address: 0x101fca0 */
  actionwk->patno = 3; /* Line 232, Address: 0x101fcac */
} /* Line 233, Address: 0x101fcb8 */

void a_move6(sprite_status* actionwk) { /* Line 235, Address: 0x101fcd0 */
  if (--((short*)actionwk)[23] >= 0) return; /* Line 236, Address: 0x101fcd8 */
  actionwk->r_no0 += 2; /* Line 237, Address: 0x101fd00 */
  ((short*)actionwk)[23] = 6; /* Line 238, Address: 0x101fd10 */
  actionwk->patno = 2; /* Line 239, Address: 0x101fd1c */
} /* Line 240, Address: 0x101fd28 */

void a_move7(sprite_status* actionwk) { /* Line 242, Address: 0x101fd40 */
  sprite_status* a1;

  if (--((short*)actionwk)[23] >= 0) return; /* Line 245, Address: 0x101fd50 */
  soundset(159); /* Line 246, Address: 0x101fd78 */
  actionwk->r_no0 += 2; /* Line 247, Address: 0x101fd84 */
  actionwk->patno = 0; /* Line 248, Address: 0x101fd94 */

  ((short*)actionwk)[23] = 120; /* Line 250, Address: 0x101fd9c */
  a1 = &actwk[((unsigned short*)actionwk)[24]]; /* Line 251, Address: 0x101fda8 */
  a1->r_no0 = 4; /* Line 252, Address: 0x101fdcc */
  if (actionwk->actfree[20] == 0) return; /* Line 253, Address: 0x101fdd4 */
  actionwk->actfree[20] = 0; /* Line 254, Address: 0x101fde8 */
  actwk[0].actfree[2] &= 254; /* Line 255, Address: 0x101fdf0 */
  actwk[0].actfree[2] &= 191; /* Line 256, Address: 0x101fe04 */
} /* Line 257, Address: 0x101fe18 */

void a_move8(sprite_status* actionwk) { /* Line 259, Address: 0x101fe30 */
  if (--((short*)actionwk)[23] >= 0) return; /* Line 260, Address: 0x101fe38 */
  actionwk->r_no0 = 2; /* Line 261, Address: 0x101fe60 */
  actionwk->actfree[20] = 0; /* Line 262, Address: 0x101fe6c */
} /* Line 263, Address: 0x101fe74 */

void pocket1(sprite_status* actionwk) { /* Line 265, Address: 0x101fe80 */
  switch (actionwk->r_no0) /* Line 266, Address: 0x101fe8c */
  {
    case 0:
      b_init(actionwk); /* Line 269, Address: 0x101fec0 */
      break; /* Line 270, Address: 0x101fecc */
    case 2:
      b_move(actionwk); /* Line 272, Address: 0x101fed4 */
      break; /* Line 273, Address: 0x101fee0 */
    case 4:
      b_die(actionwk); /* Line 275, Address: 0x101fee8 */
      break;
  }
} /* Line 278, Address: 0x101fef4 */

void b_init(sprite_status* actionwk) { /* Line 280, Address: 0x101ff10 */
  actionwk->r_no0 += 2; /* Line 281, Address: 0x101ff1c */
  actionwk->actflg |= 4; /* Line 282, Address: 0x101ff2c */
  actionwk->sprpri = 0; /* Line 283, Address: 0x101ff3c */
  actionwk->sprhsize = 24; /* Line 284, Address: 0x101ff44 */
  actionwk->sprvsize = 8; /* Line 285, Address: 0x101ff50 */
  actionwk->sproffset = 17327; /* Line 286, Address: 0x101ff5c */
  actionwk->patbase = pat_pocket; /* Line 287, Address: 0x101ff68 */
  b_move(actionwk); /* Line 288, Address: 0x101ff78 */
} /* Line 289, Address: 0x101ff84 */

void b_move(sprite_status* actionwk) { /* Line 291, Address: 0x101ffa0 */
  sprite_status* a1;

  a1 = &actwk[((unsigned short*)actionwk)[25]]; /* Line 294, Address: 0x101ffb0 */
  if (a1->actno != 47) /* Line 295, Address: 0x101ffd4 */
  {
    frameout(actionwk); /* Line 297, Address: 0x101ffe8 */
    return; /* Line 298, Address: 0x101fff4 */
  }
  patchg(actionwk, (unsigned char**)pchg); /* Line 300, Address: 0x101fffc */
  actionsub(actionwk); /* Line 301, Address: 0x1020010 */
} /* Line 302, Address: 0x102001c */

void b_die(sprite_status* actionwk) { /* Line 304, Address: 0x1020030 */
  frameout(actionwk); /* Line 305, Address: 0x102003c */
} /* Line 306, Address: 0x1020048 */
