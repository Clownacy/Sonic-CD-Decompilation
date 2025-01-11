#include "..\EQU.H"
#include "FRIEND3.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\ETC.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

#if defined(R31A) || defined(R31B) || defined(R32A)
  #define SPRITE_FRIEND3_BASE 538
#elif defined(R33C) || defined(R33D)
  #define SPRITE_FRIEND3_BASE 542
#else
  #define SPRITE_FRIEND3_BASE 491
#endif

static void t_init(sprite_status* actionwk);
static void t_move(sprite_status* actionwk);
static void t_movie(sprite_status* actionwk);
static void t_roll(sprite_status* actionwk, short d2, short d3);
static void p_init(sprite_status* actionwk);
static void p_move(sprite_status* actionwk);
static void p_movie(sprite_status* actionwk);
static void set_sproffset(sprite_status* actionwk);

static sprite_pattern patnull =
{
  1,
  { { 0, 0, 0, 0 } }
};
static sprite_pattern pat00 =
{
  1,
  { { -8, -8, 0, SPRITE_FRIEND3_BASE } }
};
static sprite_pattern pat01 =
{
  1,
  { { -8, -8, 0, SPRITE_FRIEND3_BASE + 1 } }
};
static sprite_pattern pat02 =
{
  1,
  { { -8, -12, 0, SPRITE_FRIEND3_BASE + 2 } }
};
static sprite_pattern pat03 =
{
  1,
  { { -8, -12, 0, SPRITE_FRIEND3_BASE + 3 } }
};
static sprite_pattern pat04 =
{
  1,
  { { -8, -12, 0, SPRITE_FRIEND3_BASE + 4 } }
};
static sprite_pattern pat05 =
{
  1,
  { { -8, -4, 0, SPRITE_FRIEND3_BASE + 5 } }
};
static sprite_pattern* pat_friend0[3] =
{
  &pat00,
  &pat01,
  &patnull
};
static sprite_pattern* pat_friend1[5] =
{
  &pat02,
  &pat03,
  &patnull,
  &pat04,
  &pat05
};
static char p00[4] = { 3, 0, 1, -1 };
static char p01[30] =
{
  0, 0, 0, 2, 0, 0, 2, 1, 1, 2,
  2, 1, 1, 2, 2, 0, 0, 2, 0, 0,
  2, 1, 1, 2, 2, 1, 1, 2, 2, -1
};
static char p10[58] =
{
  0, 3, 3, 2, 3, 3, 2, 3, 3, 2,
  3, 3, 2, 3, 3, 2, 2, 3, 3, 2,
  2, 3, 3, 2, 2, 3, 3, 2, 2, 4,
  4, 2, 4, 4, 2, 4, 4, 2, 4, 4,
  2, 4, 4, 2, 2, 4, 4, 2, 2, 4,
  4, 2, 2, 4, 4, 2, 2, -1
};
static char* pchg0[2] = { p00, p01 };
static char* pchg1[1] = { p10 };
static unsigned short tbl0sproffset[11] = { 1943, 986, 986, 0, 1943, 986, 986, 0, 0, 0, 986 };























void friend(sprite_status* actionwk) { /* Line 118, Address: 0x101cf40 */

  if (friend_suicide(actionwk) == -1) return; /* Line 120, Address: 0x101cf4c */


  if (actionwk->userflag.b.h & 127) /* Line 123, Address: 0x101cf6c */
    pocky(actionwk); /* Line 124, Address: 0x101cf88 */
  else
    inco(actionwk); /* Line 126, Address: 0x101cf9c */
} /* Line 127, Address: 0x101cfa8 */

void inco(sprite_status* actionwk) { /* Line 129, Address: 0x101cfc0 */
  switch (actionwk->r_no0) /* Line 130, Address: 0x101cfcc */
  {
    case 0:
      t_init(actionwk); /* Line 133, Address: 0x101d000 */
      break; /* Line 134, Address: 0x101d00c */
    case 2:
      t_move(actionwk); /* Line 136, Address: 0x101d014 */
      break; /* Line 137, Address: 0x101d020 */
    case 4:
      t_movie(actionwk); /* Line 139, Address: 0x101d028 */
      break;
  }
} /* Line 142, Address: 0x101d034 */

static void t_init(sprite_status* actionwk) { /* Line 144, Address: 0x101d050 */
  actionwk->r_no0 += 2; /* Line 145, Address: 0x101d05c */
  actionwk->actflg = 4; /* Line 146, Address: 0x101d06c */

  actionwk->sprvsize = 8; /* Line 148, Address: 0x101d078 */
  actionwk->sprhs = 8; /* Line 149, Address: 0x101d084 */
  actionwk->sprpri = 1; /* Line 150, Address: 0x101d090 */
  actionwk->sprhsize = 8; /* Line 151, Address: 0x101d09c */
  actionwk->patbase = pat_friend0; /* Line 152, Address: 0x101d0a8 */
  ((short*)actionwk)[23] = actionwk->xposi.w.h; /* Line 153, Address: 0x101d0b8 */
  ((short*)actionwk)[24] = actionwk->yposi.w.h; /* Line 154, Address: 0x101d0c8 */
  actionwk->actflg ^= 1, actionwk->cddat ^= 1; /* Line 155, Address: 0x101d0d8 */
  set_sproffset(actionwk); /* Line 156, Address: 0x101d0f8 */

  if (actionwk->userflag.b.h < 0) /* Line 158, Address: 0x101d104 */
  {
    actionwk->r_no0 += 2; /* Line 160, Address: 0x101d11c */
    actionwk->mstno.b.h = 1; /* Line 161, Address: 0x101d12c */
    actionwk->sprpri = 3; /* Line 162, Address: 0x101d138 */
  } /* Line 163, Address: 0x101d144 */
  else
  {
    actionwk->sprpri = 1; /* Line 166, Address: 0x101d14c */
    actionwk->sproffset |= 32768; /* Line 167, Address: 0x101d158 */
    actionwk->actfree[4] = 1; /* Line 168, Address: 0x101d168 */
    actionwk->actfree[5] = 1; /* Line 169, Address: 0x101d174 */
  }
} /* Line 171, Address: 0x101d180 */

static void t_move(sprite_status* actionwk) { /* Line 173, Address: 0x101d190 */
  char d0, d1;

  t_roll(actionwk, 1, 1); /* Line 176, Address: 0x101d1a4 */
  d1 = d0 = (char)actionwk->actfree[4] + (char)actionwk->actfree[5]; /* Line 177, Address: 0x101d1b8 */
  d1 += 126; /* Line 178, Address: 0x101d20c */
  if (d1 >= 0) /* Line 179, Address: 0x101d218 */
  {
    d0 = actionwk->actfree[4]; /* Line 181, Address: 0x101d228 */
    actionwk->actfree[5] = -actionwk->actfree[5]; /* Line 182, Address: 0x101d238 */
    actionwk->actflg ^= 1, actionwk->cddat ^= 1; /* Line 183, Address: 0x101d254 */
  }

  actionwk->actfree[4] = d0; /* Line 186, Address: 0x101d274 */
  patchg(actionwk, (unsigned char**)pchg0); /* Line 187, Address: 0x101d27c */
  actionsub(actionwk); /* Line 188, Address: 0x101d290 */
  frameout_s00(actionwk, ((short*)actionwk)[23]); /* Line 189, Address: 0x101d29c */
} /* Line 190, Address: 0x101d2b0 */

static void t_movie(sprite_status* actionwk) { /* Line 192, Address: 0x101d2d0 */
  sprite_status* a1;

  a1 = &actwk[((unsigned short*)actionwk)[33]]; /* Line 195, Address: 0x101d2e0 */
  if (a1->actno != 56 || a1->actfree[21]) /* Line 196, Address: 0x101d304 */
  {
    frameout(actionwk); /* Line 198, Address: 0x101d324 */
    return; /* Line 199, Address: 0x101d330 */
  }
  t_roll(actionwk, 3, 4); /* Line 201, Address: 0x101d338 */
  actionwk->actfree[4] += 4; /* Line 202, Address: 0x101d34c */
  if (!(actionwk->actfree[4] & 127)) actionwk->actflg ^= 1, actionwk->cddat ^= 1; /* Line 203, Address: 0x101d35c */

  patchg(actionwk, (unsigned char**)pchg0); /* Line 205, Address: 0x101d394 */
  actionsub(actionwk); /* Line 206, Address: 0x101d3a8 */
} /* Line 207, Address: 0x101d3b4 */

static void t_roll(sprite_status* actionwk, short d2, short d3) { /* Line 209, Address: 0x101d3d0 */
  short sin, cos;

  sinset(actionwk->actfree[4], &sin, &cos); /* Line 212, Address: 0x101d3e4 */
  cos >>= d2; /* Line 213, Address: 0x101d3fc */
  sin >>= d3; /* Line 214, Address: 0x101d40c */
  actionwk->xposi.w.h = cos + ((short*)actionwk)[23]; /* Line 215, Address: 0x101d41c */
  actionwk->yposi.w.h = sin + ((short*)actionwk)[24]; /* Line 216, Address: 0x101d44c */
} /* Line 217, Address: 0x101d47c */

void pocky(sprite_status* actionwk) { /* Line 219, Address: 0x101d490 */
  switch (actionwk->r_no0) /* Line 220, Address: 0x101d49c */
  {
    case 0:
      p_init(actionwk); /* Line 223, Address: 0x101d4e8 */
      break; /* Line 224, Address: 0x101d4f4 */
    case 2:
      p_move(actionwk); /* Line 226, Address: 0x101d4fc */
      break; /* Line 227, Address: 0x101d508 */
    case 4:
      p_move(actionwk); /* Line 229, Address: 0x101d510 */
      break; /* Line 230, Address: 0x101d51c */
    case 6:
      p_rev(actionwk); /* Line 232, Address: 0x101d524 */
      break; /* Line 233, Address: 0x101d530 */
    case 8:
      p_movie(actionwk); /* Line 235, Address: 0x101d538 */
      break;
  }
} /* Line 238, Address: 0x101d544 */

static void p_init(sprite_status* actionwk) { /* Line 240, Address: 0x101d560 */
  actionwk->r_no0 += 2; /* Line 241, Address: 0x101d56c */
  actionwk->actflg |= 4; /* Line 242, Address: 0x101d57c */
  actionwk->sprvsize = 12; /* Line 243, Address: 0x101d58c */
  actionwk->sprhs = 8; /* Line 244, Address: 0x101d598 */
  actionwk->sprpri = 4; /* Line 245, Address: 0x101d5a4 */
  actionwk->sprhsize = 8; /* Line 246, Address: 0x101d5b0 */
  actionwk->patbase = pat_friend1; /* Line 247, Address: 0x101d5bc */

  set_sproffset(actionwk); /* Line 249, Address: 0x101d5cc */
  if (actionwk->userflag.b.h < 0) /* Line 250, Address: 0x101d5d8 */
  {
    actionwk->r_no0 = 8; /* Line 252, Address: 0x101d5f0 */
    actionwk->actflg ^= 1, actionwk->cddat ^= 1; /* Line 253, Address: 0x101d5fc */
  } /* Line 254, Address: 0x101d61c */
  else
  {
    ((int*)actionwk)[12] = 65536; /* Line 257, Address: 0x101d624 */
    ((int*)actionwk)[13] = -0x40000; /* Line 258, Address: 0x101d630 */
  }
} /* Line 260, Address: 0x101d63c */

static void p_move(sprite_status* actionwk) { /* Line 262, Address: 0x101d650 */
  short d1;

  actionwk->xposi.l += ((int*)actionwk)[12]; /* Line 265, Address: 0x101d660 */
  actionwk->yposi.l += ((int*)actionwk)[13]; /* Line 266, Address: 0x101d678 */

  ((int*)actionwk)[13] += 8192; /* Line 268, Address: 0x101d690 */
  if (((int*)actionwk)[13] < 0) /* Line 269, Address: 0x101d6a0 */
    actionwk->patno = 0; /* Line 270, Address: 0x101d6b0 */
  else
    actionwk->patno = 1; /* Line 272, Address: 0x101d6c0 */
  d1 = emycol_d(actionwk); /* Line 273, Address: 0x101d6cc */
  if (d1 < 0) /* Line 274, Address: 0x101d6e0 */
  {
    actionwk->r_no0 += 2; /* Line 276, Address: 0x101d6f0 */
    actionwk->yposi.w.h += d1; /* Line 277, Address: 0x101d700 */
    ((int*)actionwk)[13] = -0x40000; /* Line 278, Address: 0x101d710 */
  }
  p_end(actionwk); /* Line 280, Address: 0x101d71c */
} /* Line 281, Address: 0x101d728 */

void p_end(sprite_status* actionwk) { /* Line 283, Address: 0x101d740 */
  actionsub(actionwk); /* Line 284, Address: 0x101d74c */
  frameout_s(actionwk); /* Line 285, Address: 0x101d758 */
} /* Line 286, Address: 0x101d764 */

void p_rev(sprite_status* actionwk) { /* Line 288, Address: 0x101d780 */
  actionwk->r_no0 = 2; /* Line 289, Address: 0x101d78c */
  ((int*)actionwk)[12] = -((int*)actionwk)[12]; /* Line 290, Address: 0x101d798 */

  actionwk->actflg ^= 1, actionwk->cddat ^= 1; /* Line 292, Address: 0x101d7ac */
  p_end(actionwk); /* Line 293, Address: 0x101d7cc */
} /* Line 294, Address: 0x101d7d8 */

static void p_movie(sprite_status* actionwk) { /* Line 296, Address: 0x101d7f0 */
  sprite_status* a1;

  a1 = &actwk[((unsigned short*)actionwk)[33]]; /* Line 299, Address: 0x101d800 */
  if (a1->actno != 56 || a1->actfree[21]) /* Line 300, Address: 0x101d824 */
  {
    frameout(actionwk); /* Line 302, Address: 0x101d844 */
    return; /* Line 303, Address: 0x101d850 */
  }
  patchg(actionwk, (unsigned char**)pchg1); /* Line 305, Address: 0x101d858 */
  actionsub(actionwk); /* Line 306, Address: 0x101d86c */
} /* Line 307, Address: 0x101d878 */

static void set_sproffset(sprite_status* actionwk) { /* Line 309, Address: 0x101d890 */
  unsigned short* a1;
  unsigned short d0;

  a1 = tbl0sproffset; /* Line 313, Address: 0x101d8a0 */
  d0 = (stageno.w + 1 << 2) + (unsigned short)time_flag; /* Line 314, Address: 0x101d8a8 */
  actionwk->sproffset = a1[d0]; /* Line 315, Address: 0x101d8dc */
} /* Line 316, Address: 0x101d8f4 */
