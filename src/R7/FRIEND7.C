#include "..\EQU.H"
#include "FRIEND7.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\ETC.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

#if defined(R73C) || defined(R73D)
  #define SPRITE_FRIEND7_BASE 441
#else
  #define SPRITE_FRIEND7_BASE 462
#endif

static void t_roll(int cos_shift, int sin_shift, sprite_status* pActwk);
static void rev_h(sprite_status* pActwk);
static void set_sproffset(sprite_status* pActwk);
static void t_init(sprite_status* pActwk);
static void t_move(sprite_status* pActwk);
static void t_movie(sprite_status* pActwk);
static void p_init(sprite_status* pActwk);
static void p_move(sprite_status* pActwk);
static void p_rev(sprite_status* pActwk);
static void p_movie(sprite_status* pActwk);

unsigned char pchg00[4] = { 3, 0, 1, 255 };
unsigned char pchg01[30] =
{
  0, 0, 0, 2, 0, 0, 2, 1, 1, 2,
  2, 1, 1, 2, 2, 0, 0, 2, 0, 0,
  2, 1, 1, 2, 2, 1, 1, 2, 2, 255
};
unsigned char pchg10[58] =
{
  0, 3, 3, 2, 3, 3, 2, 3, 3, 2,
  3, 3, 2, 3, 3, 2, 2, 3, 3, 2,
  2, 3, 3, 2, 2, 3, 3, 2, 2, 4,
  4, 2, 4, 4, 2, 4, 4, 2, 4, 4,
  2, 4, 4, 2, 2, 4, 4, 2, 2, 4,
  4, 2, 2, 4, 4, 2, 2, 255
};
unsigned char* pchg0[2] =
{
  pchg00,
  pchg01
};
unsigned char* pchg1[1] = { pchg10 };
sprite_pattern spr_flicky1 =
{
  1,
  { { -8, -8, 0, SPRITE_FRIEND7_BASE } }
};
sprite_pattern spr_flicky2 =
{
  1,
  { { -8, -8, 0, SPRITE_FRIEND7_BASE + 1 } }
};
sprite_pattern spr_ricky1 =
{
  1,
  { { -8, -12, 0, SPRITE_FRIEND7_BASE + 2 } }
};
sprite_pattern spr_ricky2 =
{
  1,
  { { -8, -12, 0, SPRITE_FRIEND7_BASE + 3 } }
};
sprite_pattern spr_ricky3 =
{
  1,
  { { -8, -12, 0, SPRITE_FRIEND7_BASE + 4 } }
};
sprite_pattern spr_ricky4 =
{
  1,
  { { -8, -4, 0, SPRITE_FRIEND7_BASE + 5 } }
};
sprite_pattern spr_friend0 =
{
  0,
  { { -8, -4, 0, SPRITE_FRIEND7_BASE + 5 } }
};
sprite_pattern* pat_friend0[3] =
{
  &spr_flicky1,
  &spr_flicky2,
  &spr_friend0
};
sprite_pattern* pat_friend1[5] =
{
  &spr_ricky1,
  &spr_ricky2,
  &spr_friend0,
  &spr_ricky3,
  &spr_ricky4
};
unsigned short tbl0sproffset[11] =
{
  918, 918, 918, 0,
  918, 918, 918, 0,
    0,   0, 918
};




































































































static void t_roll(int cos_shift, int sin_shift, sprite_status* pActwk) { /* Line 204, Address: 0x1020500 */
  unsigned short sin, cos;

  sinset(pActwk->actfree[4], (short*)&sin, (short*)&cos); /* Line 207, Address: 0x1020514 */
  cos = (short)cos >> cos_shift; /* Line 208, Address: 0x102052c */
  sin = (short)sin >> sin_shift; /* Line 209, Address: 0x1020550 */
  cos += ((unsigned short*)pActwk)[23]; /* Line 210, Address: 0x1020574 */
  sin += ((unsigned short*)pActwk)[24]; /* Line 211, Address: 0x1020588 */
  pActwk->xposi.w.h = cos; /* Line 212, Address: 0x102059c */
  pActwk->yposi.w.h = sin; /* Line 213, Address: 0x10205a8 */
} /* Line 214, Address: 0x10205b4 */


static void rev_h(sprite_status* pActwk) { /* Line 217, Address: 0x10205d0 */
  pActwk->actflg ^= 1; /* Line 218, Address: 0x10205d8 */
  pActwk->cddat ^= 1; /* Line 219, Address: 0x10205e8 */
} /* Line 220, Address: 0x10205f8 */


static void set_sproffset(sprite_status* pActwk) { /* Line 223, Address: 0x1020610 */
  int temp;

  temp = stageno.b.l; /* Line 226, Address: 0x102061c */
  temp *= 4; /* Line 227, Address: 0x102062c */
  temp += time_flag; /* Line 228, Address: 0x1020630 */
  temp &= 255; /* Line 229, Address: 0x1020640 */
  pActwk->sproffset = tbl0sproffset[temp]; /* Line 230, Address: 0x1020644 */
} /* Line 231, Address: 0x1020660 */



void friend(sprite_status* pActwk) { /* Line 235, Address: 0x1020670 */
  void(*tbl_f[3])(sprite_status*) = /* Line 236, Address: 0x102067c */
  {
    &t_init,
    &t_move,
    &t_movie
  };
  void(*tbl_r[5])(sprite_status*) = /* Line 242, Address: 0x10206a0 */
  {
    &p_init,
    &p_move,
    &p_move,
    &p_rev,
    &p_movie
  };

  if (friend_suicide(pActwk)) return; /* Line 251, Address: 0x10206cc */
  if (!(pActwk->userflag.b.h & 127)) /* Line 252, Address: 0x10206e0 */
    tbl_f[pActwk->r_no0 / 2](pActwk); /* Line 253, Address: 0x10206fc */
  else
    tbl_r[pActwk->r_no0 / 2](pActwk); /* Line 255, Address: 0x1020740 */
} /* Line 256, Address: 0x102077c */




static void t_init(sprite_status* pActwk) { /* Line 261, Address: 0x1020790 */
  pActwk->r_no0 += 2; /* Line 262, Address: 0x102079c */
  pActwk->actflg = 4; /* Line 263, Address: 0x10207ac */
  pActwk->sprvsize = 8; /* Line 264, Address: 0x10207b8 */
  pActwk->sprhs = 8; /* Line 265, Address: 0x10207c4 */
  pActwk->sprpri = 4; /* Line 266, Address: 0x10207d0 */
  pActwk->sprhsize = 8; /* Line 267, Address: 0x10207dc */
  pActwk->patbase = pat_friend0; /* Line 268, Address: 0x10207e8 */
  ((short*)pActwk)[23] = pActwk->xposi.w.h; /* Line 269, Address: 0x10207f8 */
  ((short*)pActwk)[24] = pActwk->yposi.w.h; /* Line 270, Address: 0x1020808 */
  rev_h(pActwk); /* Line 271, Address: 0x1020818 */
  set_sproffset(pActwk); /* Line 272, Address: 0x1020824 */

  if (pActwk->userflag.b.h >= 0) /* Line 274, Address: 0x1020830 */
  {


    pActwk->actfree[4] = 1; /* Line 278, Address: 0x1020848 */
    pActwk->actfree[5] = 1; /* Line 279, Address: 0x1020854 */
  } /* Line 280, Address: 0x1020860 */
  else
  {
    pActwk->r_no0 += 2; /* Line 283, Address: 0x1020868 */
    pActwk->mstno.b.h = 1; /* Line 284, Address: 0x1020878 */
    pActwk->sprpri = 3; /* Line 285, Address: 0x1020884 */
  }
} /* Line 287, Address: 0x1020890 */



static void t_move(sprite_status* pActwk) { /* Line 291, Address: 0x10208a0 */
  unsigned char temp;

  t_roll(1, 1, pActwk); /* Line 294, Address: 0x10208b0 */
  temp = pActwk->actfree[4] + pActwk->actfree[5]; /* Line 295, Address: 0x10208c4 */
  if ((unsigned char)(temp - 1) < 127) goto label1; /* Line 296, Address: 0x10208e8 */
  temp = pActwk->actfree[4]; /* Line 297, Address: 0x1020904 */
  ((char*)pActwk)[51] *= -1; /* Line 298, Address: 0x1020910 */
  rev_h(pActwk); /* Line 299, Address: 0x1020930 */
label1:
  pActwk->actfree[4] = temp; /* Line 301, Address: 0x102093c */
  patchg(pActwk, pchg0); /* Line 302, Address: 0x1020944 */
  actionsub(pActwk); /* Line 303, Address: 0x1020958 */
  frameout_s00(pActwk, ((short*)pActwk)[23]); /* Line 304, Address: 0x1020964 */
} /* Line 305, Address: 0x1020978 */



static void t_movie(sprite_status* pActwk) { /* Line 309, Address: 0x1020990 */
  sprite_status* tempact;

  tempact = &actwk[((short*)pActwk)[33]]; /* Line 312, Address: 0x10209a0 */
  if (tempact->actno != 39) /* Line 313, Address: 0x10209c8 */
  {
    frameout(pActwk); /* Line 315, Address: 0x10209dc */
    return; /* Line 316, Address: 0x10209e8 */
  }
  if (((char*)tempact)[67]) /* Line 318, Address: 0x10209f0 */
  {
    frameout(pActwk); /* Line 320, Address: 0x10209fc */
    return; /* Line 321, Address: 0x1020a08 */
  }

  t_roll(3, 4, pActwk); /* Line 324, Address: 0x1020a10 */

  pActwk->actfree[4] += 4; /* Line 326, Address: 0x1020a24 */
  if (!(pActwk->actfree[4] & 127)) /* Line 327, Address: 0x1020a34 */
    rev_h(pActwk); /* Line 328, Address: 0x1020a4c */
  else
  {
    patchg(pActwk, pchg0); /* Line 331, Address: 0x1020a60 */
    actionsub(pActwk); /* Line 332, Address: 0x1020a74 */
  }
} /* Line 334, Address: 0x1020a80 */




static void p_init(sprite_status* pActwk) { /* Line 339, Address: 0x1020aa0 */
  pActwk->r_no0 += 2; /* Line 340, Address: 0x1020aac */
  pActwk->actflg = 4; /* Line 341, Address: 0x1020abc */
  pActwk->sprvsize = 12; /* Line 342, Address: 0x1020ac8 */
  pActwk->sprhs = 8; /* Line 343, Address: 0x1020ad4 */
  pActwk->sprpri = 4; /* Line 344, Address: 0x1020ae0 */
  pActwk->sprhsize = 8; /* Line 345, Address: 0x1020aec */
  pActwk->patbase = pat_friend1; /* Line 346, Address: 0x1020af8 */

  set_sproffset(pActwk); /* Line 348, Address: 0x1020b08 */

  if (pActwk->userflag.b.h >= 0) /* Line 350, Address: 0x1020b14 */
  {
    ((int*)pActwk)[12] = 65536; /* Line 352, Address: 0x1020b2c */
    ((int*)pActwk)[13] = -0x40000; /* Line 353, Address: 0x1020b38 */
  } /* Line 354, Address: 0x1020b44 */
  else
  {
    pActwk->r_no0 = 8; /* Line 357, Address: 0x1020b4c */
    rev_h(pActwk); /* Line 358, Address: 0x1020b58 */
  }
} /* Line 360, Address: 0x1020b64 */



static void p_move(sprite_status* pActwk) { /* Line 364, Address: 0x1020b80 */
  short temp;

  pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 367, Address: 0x1020b90 */
  pActwk->yposi.l += ((int*)pActwk)[13]; /* Line 368, Address: 0x1020ba8 */

  if ((((int*)pActwk)[13] += 8192) < 0) /* Line 370, Address: 0x1020bc0 */
    pActwk->patno = 0; /* Line 371, Address: 0x1020bd8 */
  else
    pActwk->patno = 1; /* Line 373, Address: 0x1020be8 */

  if ((temp = emycol_d(pActwk)) <= 0) /* Line 375, Address: 0x1020bf4 */
  {
    pActwk->r_no0 += 2; /* Line 377, Address: 0x1020c20 */
    pActwk->yposi.w.h += temp; /* Line 378, Address: 0x1020c30 */
    ((int*)pActwk)[13] = -0x40000; /* Line 379, Address: 0x1020c40 */
  }
  actionsub(pActwk); /* Line 381, Address: 0x1020c4c */
  frameout_s(pActwk); /* Line 382, Address: 0x1020c58 */
} /* Line 383, Address: 0x1020c64 */



static void p_rev(sprite_status* pActwk) { /* Line 387, Address: 0x1020c80 */
  pActwk->r_no0 = 2; /* Line 388, Address: 0x1020c8c */
  ((int*)pActwk)[12] *= -1; /* Line 389, Address: 0x1020c98 */
  rev_h(pActwk); /* Line 390, Address: 0x1020ca8 */

  actionsub(pActwk); /* Line 392, Address: 0x1020cb4 */
  frameout_s(pActwk); /* Line 393, Address: 0x1020cc0 */
} /* Line 394, Address: 0x1020ccc */


static void p_movie(sprite_status* pActwk) { /* Line 397, Address: 0x1020ce0 */
  sprite_status* tempact;

  tempact = &actwk[((short*)pActwk)[33]]; /* Line 400, Address: 0x1020cf0 */
  if (tempact->actno != 39) /* Line 401, Address: 0x1020d18 */
  {
    frameout(pActwk); /* Line 403, Address: 0x1020d2c */
    return; /* Line 404, Address: 0x1020d38 */
  }
  if (((char*)tempact)[67]) /* Line 406, Address: 0x1020d40 */
  {
    frameout(pActwk); /* Line 408, Address: 0x1020d4c */
    return; /* Line 409, Address: 0x1020d58 */
  }
  patchg(pActwk, pchg1); /* Line 411, Address: 0x1020d60 */
  actionsub(pActwk); /* Line 412, Address: 0x1020d74 */
} /* Line 413, Address: 0x1020d80 */
