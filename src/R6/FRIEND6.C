#include "..\EQU.H"
#include "FRIEND6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\ETC.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

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
  { { -12, -8, 0, 435 } }
};
static sprite_pattern pat01 =
{
  1,
  { { -12, -8, 0, 436 } }
};
static sprite_pattern pat02 =
{
  1,
  { { -8, -12, 0, 437 } }
};
static sprite_pattern pat03 =
{
  1,
  { { -8, -12, 0, 438 } }
};
static sprite_pattern pat04 =
{
  1,
  { { -12, -8, 0, 439 } }
};
static sprite_pattern pat05 =
{
  1,
  { { -12, -8, 0, 440 } }
};
sprite_pattern* pat_friend0[3] =
{
  &pat00,
  &pat01,
  &patnull
};
sprite_pattern* pat_friend1[5] =
{
  &pat02,
  &pat03,
  &patnull,
  &pat04,
  &pat05
};
static char p00[4] = { 19, 0, 1, -1 };
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
static char* pchg1[1] = { p10 };
static unsigned short tbl0sproffset[11] =
{
  1943, 986, 986, 0,
  1943, 986, 986, 0,
     0,   0, 986
};
































void friend(sprite_status* actionwk) { /* Line 128, Address: 0x101b630 */

  if (friend_suicide(actionwk) == -1) return; /* Line 130, Address: 0x101b63c */


  if (actionwk->userflag.b.h & 127) /* Line 133, Address: 0x101b65c */
    pecky(actionwk); /* Line 134, Address: 0x101b678 */
  else
    tsubame(actionwk); /* Line 136, Address: 0x101b68c */
} /* Line 137, Address: 0x101b698 */

void tsubame(sprite_status* actionwk) { /* Line 139, Address: 0x101b6b0 */
  switch (actionwk->r_no0) /* Line 140, Address: 0x101b6bc */
  {
    case 0:
      t_init(actionwk); /* Line 143, Address: 0x101b6f0 */
      break; /* Line 144, Address: 0x101b6fc */
    case 2:
      t_move(actionwk); /* Line 146, Address: 0x101b704 */
      break; /* Line 147, Address: 0x101b710 */
    case 4:
      t_movie(actionwk); /* Line 149, Address: 0x101b718 */
      break;
  }
} /* Line 152, Address: 0x101b724 */

static void t_init(sprite_status* actionwk) { /* Line 154, Address: 0x101b740 */
  actionwk->r_no0 += 2; /* Line 155, Address: 0x101b74c */
  actionwk->actflg = 4; /* Line 156, Address: 0x101b75c */

  actionwk->sprvsize = 8; /* Line 158, Address: 0x101b768 */
  actionwk->sprhs = 8; /* Line 159, Address: 0x101b774 */
  actionwk->sprpri = 1; /* Line 160, Address: 0x101b780 */
  actionwk->sprhsize = 8; /* Line 161, Address: 0x101b78c */
  actionwk->patbase = pat_friend0; /* Line 162, Address: 0x101b798 */
  ((short*)actionwk)[23] = actionwk->xposi.w.h; /* Line 163, Address: 0x101b7a8 */
  ((short*)actionwk)[24] = (actionwk->yposi).w.h; /* Line 164, Address: 0x101b7b8 */
  actionwk->actflg ^= 1, actionwk->cddat ^= 1; /* Line 165, Address: 0x101b7c8 */
  set_sproffset(actionwk); /* Line 166, Address: 0x101b7e8 */

  if (actionwk->userflag.b.h < 0) /* Line 168, Address: 0x101b7f4 */
  {
    actionwk->r_no0 += 2; /* Line 170, Address: 0x101b80c */
    actionwk->mstno.b.h = 1; /* Line 171, Address: 0x101b81c */
    actionwk->sprpri = 3; /* Line 172, Address: 0x101b828 */
  } /* Line 173, Address: 0x101b834 */
  else
  {
    actionwk->sprpri = 1; /* Line 176, Address: 0x101b83c */
    actionwk->sproffset |= 32768; /* Line 177, Address: 0x101b848 */
    actionwk->actfree[4] = 1; /* Line 178, Address: 0x101b858 */
    actionwk->actfree[5] = 1; /* Line 179, Address: 0x101b864 */
  }
} /* Line 181, Address: 0x101b870 */

static void t_move(sprite_status* actionwk) { /* Line 183, Address: 0x101b880 */
  char d0, d1;

  t_roll(actionwk, 1, 1); /* Line 186, Address: 0x101b894 */
  d1 = d0 = (char)actionwk->actfree[4] + (char)actionwk->actfree[5]; /* Line 187, Address: 0x101b8a8 */
  d1 += 126; /* Line 188, Address: 0x101b8fc */
  if (d1 >= 0) /* Line 189, Address: 0x101b908 */
  {
    d0 = actionwk->actfree[4]; /* Line 191, Address: 0x101b918 */
    actionwk->actfree[5] = -actionwk->actfree[5]; /* Line 192, Address: 0x101b928 */
    actionwk->actflg ^= 1, actionwk->cddat ^= 1; /* Line 193, Address: 0x101b944 */
  }

  actionwk->actfree[4] = d0; /* Line 196, Address: 0x101b964 */
  patchg(actionwk, (unsigned char**)pchg0); /* Line 197, Address: 0x101b96c */
  actionsub(actionwk); /* Line 198, Address: 0x101b980 */
  frameout_s00(actionwk, ((short*)actionwk)[23]); /* Line 199, Address: 0x101b98c */
} /* Line 200, Address: 0x101b9a0 */

static void t_movie(sprite_status* actionwk) { /* Line 202, Address: 0x101b9c0 */
  sprite_status* a1;

  a1 = &actwk[((unsigned short*)actionwk)[33]]; /* Line 205, Address: 0x101b9d0 */
  if (a1->actno != 47 || a1->actfree[21]) /* Line 206, Address: 0x101b9f4 */
  {
    frameout(actionwk); /* Line 208, Address: 0x101ba14 */
    return; /* Line 209, Address: 0x101ba20 */
  }
  t_roll(actionwk, 3, 4); /* Line 211, Address: 0x101ba28 */
  actionwk->actfree[4] += 4; /* Line 212, Address: 0x101ba3c */
  if (!(actionwk->actfree[4] & 127)) actionwk->actflg ^= 1, actionwk->cddat ^= 1; /* Line 213, Address: 0x101ba4c */

  patchg(actionwk, (unsigned char**)pchg0); /* Line 215, Address: 0x101ba84 */
  actionsub(actionwk); /* Line 216, Address: 0x101ba98 */
} /* Line 217, Address: 0x101baa4 */

static void t_roll(sprite_status* actionwk, short d2, short d3) { /* Line 219, Address: 0x101bac0 */
  short sin, cos;

  sinset(actionwk->actfree[4], &sin, &cos); /* Line 222, Address: 0x101bad4 */
  cos >>= d2; /* Line 223, Address: 0x101baec */
  sin >>= d3; /* Line 224, Address: 0x101bafc */
  actionwk->xposi.w.h = cos + ((short*)actionwk)[23]; /* Line 225, Address: 0x101bb0c */
  actionwk->yposi.w.h = sin + ((short*)actionwk)[24]; /* Line 226, Address: 0x101bb3c */
} /* Line 227, Address: 0x101bb6c */

void pecky(sprite_status* actionwk) { /* Line 229, Address: 0x101bb80 */
  switch (actionwk->r_no0) /* Line 230, Address: 0x101bb8c */
  {
    case 0:
      p_init(actionwk); /* Line 233, Address: 0x101bbd8 */
      break; /* Line 234, Address: 0x101bbe4 */
    case 2:
      p_move(actionwk); /* Line 236, Address: 0x101bbec */
      break; /* Line 237, Address: 0x101bbf8 */
    case 4:
      p_move(actionwk); /* Line 239, Address: 0x101bc00 */
      break; /* Line 240, Address: 0x101bc0c */
    case 6:
      p_rev(actionwk); /* Line 242, Address: 0x101bc14 */
      break; /* Line 243, Address: 0x101bc20 */
    case 8:
      p_movie(actionwk); /* Line 245, Address: 0x101bc28 */
      break;
  }
} /* Line 248, Address: 0x101bc34 */

static void p_init(sprite_status* actionwk) { /* Line 250, Address: 0x101bc50 */
  actionwk->r_no0 += 2; /* Line 251, Address: 0x101bc5c */
  actionwk->actflg |= 4; /* Line 252, Address: 0x101bc6c */
  actionwk->sprvsize = 8; /* Line 253, Address: 0x101bc7c */
  actionwk->sprhs = 8; /* Line 254, Address: 0x101bc88 */
  actionwk->sprpri = 4; /* Line 255, Address: 0x101bc94 */
  actionwk->sprhsize = 8; /* Line 256, Address: 0x101bca0 */
  actionwk->patbase = pat_friend1; /* Line 257, Address: 0x101bcac */

  set_sproffset(actionwk); /* Line 259, Address: 0x101bcbc */
  if (actionwk->userflag.b.h < 0) /* Line 260, Address: 0x101bcc8 */
  {
    actionwk->r_no0 = 8; /* Line 262, Address: 0x101bce0 */

  } /* Line 264, Address: 0x101bcec */
  else
  {
    ((int*)actionwk)[12] = 65536; /* Line 267, Address: 0x101bcf4 */
    ((int*)actionwk)[13] = -262144; /* Line 268, Address: 0x101bd00 */
  }
} /* Line 270, Address: 0x101bd0c */

static void p_move(sprite_status* actionwk) { /* Line 272, Address: 0x101bd20 */
  short d1;

  actionwk->xposi.l += ((int*)actionwk)[12]; /* Line 275, Address: 0x101bd30 */
  actionwk->yposi.l += ((int*)actionwk)[13]; /* Line 276, Address: 0x101bd48 */

  ((int*)actionwk)[13] += 8192; /* Line 278, Address: 0x101bd60 */
  if (((int*)actionwk)[13] < 0) /* Line 279, Address: 0x101bd70 */
    actionwk->patno = 0; /* Line 280, Address: 0x101bd80 */
  else
    actionwk->patno = 1; /* Line 282, Address: 0x101bd90 */
  d1 = emycol_d(actionwk); /* Line 283, Address: 0x101bd9c */
  if (d1 < 0) /* Line 284, Address: 0x101bdb0 */
  {
    actionwk->r_no0 += 2; /* Line 286, Address: 0x101bdc0 */
    actionwk->yposi.w.h += d1; /* Line 287, Address: 0x101bdd0 */
    ((int*)actionwk)[13] = -262144; /* Line 288, Address: 0x101bde0 */
  }
  p_end(actionwk); /* Line 290, Address: 0x101bdec */
} /* Line 291, Address: 0x101bdf8 */

void p_end(sprite_status* actionwk) { /* Line 293, Address: 0x101be10 */
  actionsub(actionwk); /* Line 294, Address: 0x101be1c */
  frameout_s(actionwk); /* Line 295, Address: 0x101be28 */
} /* Line 296, Address: 0x101be34 */

void p_rev(sprite_status* actionwk) { /* Line 298, Address: 0x101be50 */
  actionwk->r_no0 = 2; /* Line 299, Address: 0x101be5c */
  ((int*)actionwk)[12] = -((int*)actionwk)[12]; /* Line 300, Address: 0x101be68 */

  actionwk->actflg ^= 1, actionwk->cddat ^= 1; /* Line 302, Address: 0x101be7c */
  p_end(actionwk); /* Line 303, Address: 0x101be9c */
} /* Line 304, Address: 0x101bea8 */

static void p_movie(sprite_status* actionwk) { /* Line 306, Address: 0x101bec0 */
  sprite_status* a1;

  a1 = &actwk[((unsigned short*)actionwk)[33]]; /* Line 309, Address: 0x101bed0 */
  if (a1->actno != 47 || a1->actfree[21]) /* Line 310, Address: 0x101bef4 */
  {
    frameout(actionwk); /* Line 312, Address: 0x101bf14 */
    return; /* Line 313, Address: 0x101bf20 */
  }
  patchg(actionwk, (unsigned char**)pchg1); /* Line 315, Address: 0x101bf28 */
  actionsub(actionwk); /* Line 316, Address: 0x101bf3c */
} /* Line 317, Address: 0x101bf48 */

static void set_sproffset(sprite_status* actionwk) { /* Line 319, Address: 0x101bf60 */
  unsigned short* a1;
  unsigned short d0;

  a1 = tbl0sproffset; /* Line 323, Address: 0x101bf70 */
  d0 = ((stageno.w + 1) << 2) + (unsigned short)time_flag; /* Line 324, Address: 0x101bf78 */
  actionwk->sproffset = a1[d0]; /* Line 325, Address: 0x101bfac */
} /* Line 326, Address: 0x101bfc4 */
