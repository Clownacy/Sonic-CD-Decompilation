#include "..\EQU.H"
#include "FRIEND8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\ETC.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static void t_init(sprite_status* actionwk);
static void t_move(sprite_status* actionwk);
static void t_roll(sprite_status* actionwk, short d2, short d3);
static void p_init(sprite_status* actionwk);
static void p_move(sprite_status* actionwk);
static void set_sproffset(sprite_status* actionwk);

static sprite_pattern pat00 =
{
  1,
  { { -8, -8, 0, 439 } }
};
static sprite_pattern pat01 =
{
  1,
  { { -8, -8, 0, 440 } }
};
static sprite_pattern pat02 =
{
  1,
  { { -12, -8, 0, 441 } }
};
static sprite_pattern pat03 =
{
  1,
  { { -12, -8, 0, 442 } }
};
sprite_pattern* pat_friend0[2] =
{
  &pat00,
  &pat01
};
sprite_pattern* pat_friend1[2] =
{
  &pat02,
  &pat03
};
static char p00[4] = { 3, 0, 1, -1 };
unsigned char p01[30] =
{
  0, 0, 0, 2, 0, 0, 2, 1, 1, 2,
  2, 1, 1, 2, 2, 0, 0, 2, 0, 0,
  2, 1, 1, 2, 2, 1, 1, 2, 2, 255
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
static char* pchg0[2] =
{
  p00,
  (char*)p01
};
static unsigned short tbl0sproffset[11] =
{
  1943, 986, 986, 0,
  1943, 986, 986, 0,
     0,   0, 986
};









































void friend(sprite_status* actionwk) { /* Line 115, Address: 0x1025160 */

  if (friend_suicide(actionwk) == -1) return; /* Line 117, Address: 0x102516c */


  if (actionwk->userflag.b.h & 127) /* Line 120, Address: 0x102518c */
    sheep(actionwk); /* Line 121, Address: 0x10251a8 */
  else
    hato(actionwk); /* Line 123, Address: 0x10251bc */
} /* Line 124, Address: 0x10251c8 */

void hato(sprite_status* actionwk) { /* Line 126, Address: 0x10251e0 */
  switch (actionwk->r_no0) /* Line 127, Address: 0x10251ec */
  {
    case 0:
      t_init(actionwk); /* Line 130, Address: 0x1025214 */
      break; /* Line 131, Address: 0x1025220 */
    case 2:
      t_move(actionwk); /* Line 133, Address: 0x1025228 */
      break;
  }
} /* Line 136, Address: 0x1025234 */

static void t_init(sprite_status* actionwk) { /* Line 138, Address: 0x1025250 */
  actionwk->r_no0 += 2; /* Line 139, Address: 0x102525c */
  actionwk->actflg = 4; /* Line 140, Address: 0x102526c */

  actionwk->sprvsize = 8; /* Line 142, Address: 0x1025278 */
  actionwk->sprhs = 8; /* Line 143, Address: 0x1025284 */
  actionwk->sprpri = 4; /* Line 144, Address: 0x1025290 */
  actionwk->sprhsize = 8; /* Line 145, Address: 0x102529c */
  actionwk->patbase = pat_friend0; /* Line 146, Address: 0x10252a8 */
  ((short*)actionwk)[23] = actionwk->xposi.w.h; /* Line 147, Address: 0x10252b8 */
  ((short*)actionwk)[24] = actionwk->yposi.w.h; /* Line 148, Address: 0x10252c8 */
  actionwk->actflg ^= 1, actionwk->cddat ^= 1; /* Line 149, Address: 0x10252d8 */
  set_sproffset(actionwk); /* Line 150, Address: 0x10252f8 */


  actionwk->actfree[4] = 1; /* Line 153, Address: 0x1025304 */
  actionwk->actfree[5] = 1; /* Line 154, Address: 0x1025310 */
} /* Line 155, Address: 0x102531c */

static void t_move(sprite_status* actionwk) { /* Line 157, Address: 0x1025330 */
  char d0, d1;

  t_roll(actionwk, 1, 1); /* Line 160, Address: 0x1025344 */
  d1 = d0 = (char)actionwk->actfree[4] + (char)actionwk->actfree[5]; /* Line 161, Address: 0x1025358 */
  d1 += 126; /* Line 162, Address: 0x10253ac */
  if (d1 >= 0) /* Line 163, Address: 0x10253b8 */
  {
    d0 = actionwk->actfree[4]; /* Line 165, Address: 0x10253c8 */
    actionwk->actfree[5] = -actionwk->actfree[5]; /* Line 166, Address: 0x10253d8 */
    actionwk->actflg ^= 1, actionwk->cddat ^= 1; /* Line 167, Address: 0x10253f4 */
  }

  actionwk->actfree[4] = d0; /* Line 170, Address: 0x1025414 */
  patchg(actionwk, (unsigned char**)pchg0); /* Line 171, Address: 0x102541c */
  actionsub(actionwk); /* Line 172, Address: 0x1025430 */
  frameout_s00(actionwk, ((short*)actionwk)[23]); /* Line 173, Address: 0x102543c */
} /* Line 174, Address: 0x1025450 */

static void t_roll(sprite_status* actionwk, short d2, short d3) { /* Line 176, Address: 0x1025470 */
  short sin, cos;

  sinset(actionwk->actfree[4], &sin, &cos); /* Line 179, Address: 0x1025484 */
  cos >>= d2; /* Line 180, Address: 0x102549c */
  sin >>= d3; /* Line 181, Address: 0x10254ac */
  actionwk->xposi.w.h = cos + ((short*)actionwk)[23]; /* Line 182, Address: 0x10254bc */
  actionwk->yposi.w.h = sin + ((short*)actionwk)[24]; /* Line 183, Address: 0x10254ec */
} /* Line 184, Address: 0x102551c */

void sheep(sprite_status* actionwk) { /* Line 186, Address: 0x1025530 */
  switch (actionwk->r_no0) /* Line 187, Address: 0x102553c */
  {
    case 0:
      p_init(actionwk); /* Line 190, Address: 0x1025564 */
      break; /* Line 191, Address: 0x1025570 */
    case 2:
      p_move(actionwk); /* Line 193, Address: 0x1025578 */
      break;
  }
} /* Line 196, Address: 0x1025584 */

static void p_init(sprite_status* actionwk) { /* Line 198, Address: 0x10255a0 */
  actionwk->r_no0 += 2; /* Line 199, Address: 0x10255ac */
  actionwk->actflg |= 4; /* Line 200, Address: 0x10255bc */
  actionwk->sprvsize = 7; /* Line 201, Address: 0x10255cc */
  actionwk->sprhs = 8; /* Line 202, Address: 0x10255d8 */
  actionwk->sprpri = 4; /* Line 203, Address: 0x10255e4 */
  actionwk->sprhsize = 8; /* Line 204, Address: 0x10255f0 */
  actionwk->patbase = pat_friend1; /* Line 205, Address: 0x10255fc */

  set_sproffset(actionwk); /* Line 207, Address: 0x102560c */

  ((int*)actionwk)[12] = 65536; /* Line 209, Address: 0x1025618 */
  ((int*)actionwk)[13] = -262144; /* Line 210, Address: 0x1025624 */
} /* Line 211, Address: 0x1025630 */

static void p_move(sprite_status* actionwk) { /* Line 213, Address: 0x1025640 */
  short d1;
  int spd;

  actionwk->xposi.l += ((int*)actionwk)[12]; /* Line 217, Address: 0x1025654 */
  actionwk->yposi.l += ((int*)actionwk)[13]; /* Line 218, Address: 0x102566c */

  ((int*)actionwk)[13] += 8192; /* Line 220, Address: 0x1025684 */
  spd = ((int*)actionwk)[13]; /* Line 221, Address: 0x1025694 */
  if (spd < 0) /* Line 222, Address: 0x102569c */
    actionwk->patno = 0; /* Line 223, Address: 0x10256a4 */
  else
    actionwk->patno = 1; /* Line 225, Address: 0x10256b4 */
  d1 = emycol_d(actionwk); /* Line 226, Address: 0x10256c0 */
  if (d1 < 0) /* Line 227, Address: 0x10256d4 */
  {

    actionwk->yposi.w.h += d1; /* Line 230, Address: 0x10256e4 */
    ((int*)actionwk)[13] = -262144; /* Line 231, Address: 0x10256f4 */
    ((int*)actionwk)[12] = -((int*)actionwk)[12]; /* Line 232, Address: 0x1025700 */

    actionwk->actflg ^= 1, actionwk->cddat ^= 1; /* Line 234, Address: 0x1025714 */
  }
  p_end(actionwk); /* Line 236, Address: 0x1025734 */
} /* Line 237, Address: 0x1025740 */

void p_end(sprite_status* actionwk) { /* Line 239, Address: 0x1025760 */
  actionsub(actionwk); /* Line 240, Address: 0x102576c */
  frameout_s(actionwk); /* Line 241, Address: 0x1025778 */
} /* Line 242, Address: 0x1025784 */

static void set_sproffset(sprite_status* actionwk) { /* Line 244, Address: 0x10257a0 */
  unsigned short* a1;
  unsigned short d0;

  a1 = tbl0sproffset; /* Line 248, Address: 0x10257b0 */
  d0 = ((stageno.w + 1) << 2) + (unsigned short)time_flag; /* Line 249, Address: 0x10257b8 */
  actionwk->sproffset = a1[d0]; /* Line 250, Address: 0x10257ec */
} /* Line 251, Address: 0x1025804 */
