#include "..\EQU.H"
#include "FRIEND1.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\ETC.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static unsigned char pchg00[4] = { 29, 0, 1, 255 };
static unsigned char pchg01[30] =
{
  0,
  0, 0, 2,
  0, 0, 2,
  1, 1, 2, 2,
  1, 1, 2, 2,
  0, 0, 2,
  0, 0, 2,
  1, 1, 2, 2,
  1, 1, 2, 2,
  255
};
static unsigned char pchg10[58] =
{
  0,
  3, 3, 2, 3,
  3, 2, 3, 3,
  2, 3, 3, 2,
  3, 3, 2, 2,
  3, 3, 2, 2,
  3, 3, 2, 2,
  3, 3, 2, 2,
  5, 5, 2, 5,
  5, 2, 5, 5,
  2, 5, 5, 2,
  5, 5, 2, 2,
  5, 5, 2, 2,
  5, 5, 2, 2,
  5, 5, 2, 2,
  255
};
static unsigned char* pchg0[2] = { pchg00, pchg01 };
static unsigned char* pchg1[1] = { pchg10 };
static spr_array spr_flicky1 =
{
  1,
  { { -8, -8, 0, 491 } }
};
static spr_array spr_flicky2 =
{
  1,
  { { -8, -8, 0, 492 } }
};
static spr_array spr_ricky1 =
{
  1,
  { { -12, -8, 0, 492 } }
};
static spr_array spr_ricky2 =
{
  1,
  { { -12, -8, 0, 493 } }
};
static spr_array spr_ricky3 =
{
  1,
  { { -12, -8, 0, 494 } }
};
static spr_array spr_ricky4 =
{
  1,
  { { -12, -8, 0, 495 } }
};
static spr_array spr_friend0 =
{
  1,
  { { -12, -8, 0, 495 } }
};
static spr_array spr_ricky5 =
{
  1,
  { { -12, -8, 0, 496 } }
};
spr_array* pat_friend0[3] =
{
  &spr_flicky1,
  &spr_flicky2,
  &spr_friend0
};
spr_array* pat_friend1[6] =
{
  &spr_ricky1,
  &spr_ricky2,
  &spr_friend0,
  &spr_ricky3,
  &spr_ricky4,
  &spr_ricky5
};
static unsigned short tbl0sproffset[11] =
{
  1271,  904, 1123,    0,
  1271,  911, 1121,    0,
     0,    0,  975
};




































































































static void t_roll(int cos_shift, int sin_shift, act_info* pActwk) { /* Line 206, Address: 0x1031900 */
  unsigned short sin, cos;

  sinset(pActwk->actfree[4], (short*)&sin, (short*)&cos); /* Line 209, Address: 0x1031914 */
  cos = (short)cos >> cos_shift; /* Line 210, Address: 0x103192c */
  sin = (short)sin >> sin_shift; /* Line 211, Address: 0x1031950 */
  cos += ((unsigned short*)pActwk)[23]; /* Line 212, Address: 0x1031974 */
  sin += ((unsigned short*)pActwk)[24]; /* Line 213, Address: 0x1031988 */
  pActwk->xposi.w.h = cos; /* Line 214, Address: 0x103199c */
  pActwk->yposi.w.h = sin; /* Line 215, Address: 0x10319a8 */
} /* Line 216, Address: 0x10319b4 */


static void rev_h(act_info* pActwk) { /* Line 219, Address: 0x10319d0 */
  pActwk->actflg ^= 1; /* Line 220, Address: 0x10319d8 */
  pActwk->cddat ^= 1; /* Line 221, Address: 0x10319e8 */
} /* Line 222, Address: 0x10319f8 */


static void set_sproffset(act_info* pActwk) { /* Line 225, Address: 0x1031a10 */
  int temp;

  temp = stageno.b.l; /* Line 228, Address: 0x1031a1c */
  temp *= 4; /* Line 229, Address: 0x1031a2c */
  temp += time_flag; /* Line 230, Address: 0x1031a30 */
  temp &= 255; /* Line 231, Address: 0x1031a40 */
  pActwk->sproffset = tbl0sproffset[temp]; /* Line 232, Address: 0x1031a44 */
} /* Line 233, Address: 0x1031a60 */



void friend(act_info* pActwk) { /* Line 237, Address: 0x1031a70 */
  void(*tbl_f[3])(act_info*) = /* Line 238, Address: 0x1031a7c */
  {
    &t_init,
    &t_move,
    &t_movie
  };
  void(*tbl_r[3])(act_info*) = /* Line 244, Address: 0x1031aa0 */
  {
    &p_init,
    &p_move,
    &p_movie
  };

  if (friend_suicide(pActwk)) return; /* Line 251, Address: 0x1031ac4 */
  if ((pActwk->userflag.b.h & 127) == 0) /* Line 252, Address: 0x1031ad8 */
    tbl_f[pActwk->r_no0 / 2](pActwk); /* Line 253, Address: 0x1031af4 */
  else
    tbl_f[pActwk->r_no0 / 2](pActwk); /* Line 255, Address: 0x1031b38 */
} /* Line 256, Address: 0x1031b74 */




static void t_init(act_info* pActwk) { /* Line 261, Address: 0x1031b90 */
  pActwk->r_no0 += 2; /* Line 262, Address: 0x1031b9c */
  pActwk->actflg = 4; /* Line 263, Address: 0x1031bac */
  pActwk->sprvsize = 8; /* Line 264, Address: 0x1031bb8 */
  pActwk->sprhs = 8; /* Line 265, Address: 0x1031bc4 */
  pActwk->sprpri = 4; /* Line 266, Address: 0x1031bd0 */
  pActwk->sprhsize = 8; /* Line 267, Address: 0x1031bdc */
  pActwk->patbase = pat_friend0; /* Line 268, Address: 0x1031be8 */
  ((short*)pActwk)[23] = pActwk->xposi.w.h; /* Line 269, Address: 0x1031bf8 */
  ((short*)pActwk)[24] = pActwk->yposi.w.h; /* Line 270, Address: 0x1031c08 */
  rev_h(pActwk); /* Line 271, Address: 0x1031c18 */
  set_sproffset(pActwk); /* Line 272, Address: 0x1031c24 */

  if (pActwk->userflag.b.h >= 0) /* Line 274, Address: 0x1031c30 */
  {
    pActwk->sprpri = 4; /* Line 276, Address: 0x1031c48 */
    pActwk->sproffset |= 32768; /* Line 277, Address: 0x1031c54 */
    pActwk->actfree[4] = 1; /* Line 278, Address: 0x1031c64 */
    pActwk->actfree[5] = 1; /* Line 279, Address: 0x1031c70 */
  } /* Line 280, Address: 0x1031c7c */
  else
  {
    pActwk->r_no0 += 2; /* Line 283, Address: 0x1031c84 */
    pActwk->mstno.b.h = 1; /* Line 284, Address: 0x1031c94 */
    pActwk->sprpri = 3; /* Line 285, Address: 0x1031ca0 */
  }
} /* Line 287, Address: 0x1031cac */



static void t_move(act_info* pActwk) { /* Line 291, Address: 0x1031cc0 */
  unsigned char temp;

  t_roll(1, 1, pActwk); /* Line 294, Address: 0x1031cd0 */
  temp = pActwk->actfree[4] + pActwk->actfree[5]; /* Line 295, Address: 0x1031ce4 */
  if ((unsigned char)(temp - 1) < 127) goto label1; /* Line 296, Address: 0x1031d08 */
  temp = pActwk->actfree[4]; /* Line 297, Address: 0x1031d24 */
  ((char*)pActwk)[51] *= -1; /* Line 298, Address: 0x1031d30 */
  rev_h(pActwk); /* Line 299, Address: 0x1031d50 */
label1:
  pActwk->actfree[4] = temp; /* Line 301, Address: 0x1031d5c */
  patchg(pActwk, pchg0); /* Line 302, Address: 0x1031d64 */
  actionsub(pActwk); /* Line 303, Address: 0x1031d78 */
  frameout_s00(pActwk, ((short*)pActwk)[23]); /* Line 304, Address: 0x1031d84 */
} /* Line 305, Address: 0x1031d98 */



static void t_movie(act_info* pActwk) { /* Line 309, Address: 0x1031db0 */
  act_info* tempact;

  tempact = &actwk[((short*)pActwk)[33]]; /* Line 312, Address: 0x1031dc0 */
  if (tempact->actno != 46) /* Line 313, Address: 0x1031de8 */
  {
    frameout(pActwk); /* Line 315, Address: 0x1031dfc */
    return; /* Line 316, Address: 0x1031e08 */
  }
  if (((char*)tempact)[67]) /* Line 318, Address: 0x1031e10 */
  {
    frameout(pActwk); /* Line 320, Address: 0x1031e1c */
    return; /* Line 321, Address: 0x1031e28 */
  }

  t_roll(3, 4, pActwk); /* Line 324, Address: 0x1031e30 */

  pActwk->actfree[4] += 4; /* Line 326, Address: 0x1031e44 */
  if ((pActwk->actfree[4] & 127) == 0) /* Line 327, Address: 0x1031e54 */
    rev_h(pActwk); /* Line 328, Address: 0x1031e6c */
  else
  {
    patchg(pActwk, pchg0); /* Line 331, Address: 0x1031e80 */
    actionsub(pActwk); /* Line 332, Address: 0x1031e94 */
  }
} /* Line 334, Address: 0x1031ea0 */




static void p_init(act_info* pActwk) { /* Line 339, Address: 0x1031ec0 */
  pActwk->r_no0 += 2; /* Line 340, Address: 0x1031ecc */
  pActwk->actflg = 4; /* Line 341, Address: 0x1031edc */
  pActwk->sprvsize = 8; /* Line 342, Address: 0x1031ee8 */
  pActwk->sprhs = 8; /* Line 343, Address: 0x1031ef4 */
  pActwk->sprpri = 4; /* Line 344, Address: 0x1031f00 */
  pActwk->sprhsize = 8; /* Line 345, Address: 0x1031f0c */
  pActwk->patbase = pat_friend1; /* Line 346, Address: 0x1031f18 */
  ((short*)pActwk)[23] = pActwk->xposi.w.h; /* Line 347, Address: 0x1031f28 */
  set_sproffset(pActwk); /* Line 348, Address: 0x1031f38 */

  if (pActwk->userflag.b.h >= 0) /* Line 350, Address: 0x1031f44 */
  {
    ((int*)pActwk)[12] = 1; /* Line 352, Address: 0x1031f5c */
    ((int*)pActwk)[13] = -4; /* Line 353, Address: 0x1031f68 */
  } /* Line 354, Address: 0x1031f74 */
  else
  {
    pActwk->r_no0 = 4; /* Line 357, Address: 0x1031f7c */
    rev_h(pActwk); /* Line 358, Address: 0x1031f88 */
  }
} /* Line 360, Address: 0x1031f94 */



static void p_move(act_info* pActwk) { /* Line 364, Address: 0x1031fb0 */
  short temp;

  pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 367, Address: 0x1031fc0 */
  pActwk->yposi.l += ((int*)pActwk)[13]; /* Line 368, Address: 0x1031fd8 */

  if ((((int*)pActwk)[13] += 8192) < 0) /* Line 370, Address: 0x1031ff0 */
    pActwk->patno = 0; /* Line 371, Address: 0x1032008 */
  else
    pActwk->patno = 1; /* Line 373, Address: 0x1032018 */

  if ((temp = emycol_d(pActwk)) <= 0) /* Line 375, Address: 0x1032024 */
  {
    pActwk->yposi.w.h += temp; /* Line 377, Address: 0x1032050 */
    ((int*)pActwk)[13] = -4; /* Line 378, Address: 0x1032060 */
    ((int*)pActwk)[12] = -((int*)pActwk)[12]; /* Line 379, Address: 0x103206c */
    rev_h(pActwk); /* Line 380, Address: 0x103207c */
  }
  actionsub(pActwk); /* Line 382, Address: 0x1032088 */
  frameout_s(pActwk); /* Line 383, Address: 0x1032094 */
} /* Line 384, Address: 0x10320a0 */



static void p_movie(act_info* pActwk) { /* Line 388, Address: 0x10320c0 */
  act_info* tempact;

  tempact = &actwk[((short*)pActwk)[33]]; /* Line 391, Address: 0x10320d0 */
  if (tempact->actno != 46) /* Line 392, Address: 0x10320f8 */
  {
    frameout(pActwk); /* Line 394, Address: 0x103210c */
    return; /* Line 395, Address: 0x1032118 */
  }
  if (tempact->actfree[21] != 0) /* Line 397, Address: 0x1032120 */
  {
    frameout(pActwk); /* Line 399, Address: 0x103212c */
    return; /* Line 400, Address: 0x1032138 */
  }
  patchg(pActwk, pchg1); /* Line 402, Address: 0x1032140 */
  actionsub(pActwk); /* Line 403, Address: 0x1032154 */
} /* Line 404, Address: 0x1032160 */
