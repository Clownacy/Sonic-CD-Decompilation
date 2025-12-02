#include "..\EQU.H"
#include "AMENBO.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\SUICIDE.H"
#include "PLAYSUB4.H"

#if defined(R41A)
  #define SPRITE_AMENBO_BASE 479
#elif defined(R41B)
  #define SPRITE_AMENBO_BASE 440
#elif defined(R41C)
  #define SPRITE_AMENBO_BASE 457
#elif defined(R41D)
  #define SPRITE_AMENBO_BASE 447
#elif defined(R42A)
  #define SPRITE_AMENBO_BASE 485
#elif defined(R42B)
  #define SPRITE_AMENBO_BASE 438
#else
  #define SPRITE_AMENBO_BASE 442
#endif

static void act_init(sprite_status* pActwk);
static void act_accel(sprite_status* pActwk);
static void act_decel(sprite_status* pActwk);
static void act_stop(sprite_status* pActwk);
static void act_stop1(sprite_status* pActwk);
static void act_move0(sprite_status* pActwk);
static void act_tama(sprite_status* pActwk);
static int act_check(sprite_status* pActwk);

static unsigned char pchg_b0[4] = { 20, 0, 1, 255 };
static unsigned char pchg_e0[4] = { 10, 0, 1, 255 };
static unsigned char pchg_e1[4] = { 5, 2, 3, 255 };
static unsigned char* pchg_b[1] = { pchg_b0 };
static unsigned char* pchg_e[2] =
{
  pchg_e0,
  pchg_e1
};
static sprite_pattern spr_amenbo_b_00 =
{
  1,
  {
    { -20, -12, 0, SPRITE_AMENBO_BASE }
  }
};
static sprite_pattern spr_amenbo_b_01 =
{
  1,
  {
    { -20, -12, 0, SPRITE_AMENBO_BASE + 1 }
  }
};
static sprite_pattern spr_amenbo_e_00 =
{
  1,
  {
    { -20, -12, 0, SPRITE_AMENBO_BASE + 2 }
  }
};
static sprite_pattern spr_amenbo_e_01 =
{
  1,
  {
    { -20, -12, 0, SPRITE_AMENBO_BASE + 3 }
  }
};
static sprite_pattern spr_amenbo_e_02 =
{
  1,
  {
    { -4, -4, 0, SPRITE_AMENBO_BASE + 4 }
  }
};
static sprite_pattern spr_amenbo_e_03 =
{
  1,
  {
    { -4, -4, 0, SPRITE_AMENBO_BASE + 5 }
  }
};
sprite_pattern* pat_amenbo_b[2] =
{
  &spr_amenbo_b_00,
  &spr_amenbo_b_01
};
sprite_pattern* pat_amenbo_e[4] =
{
  &spr_amenbo_e_00,
  &spr_amenbo_e_01,
  &spr_amenbo_e_02,
  &spr_amenbo_e_03
};
















































































void amenbo(sprite_status* pActwk) { /* Line 177, Address: 0x101e950 */
  static void(*act_tbl[5])(sprite_status*) =
  {
    &act_init,
    &act_accel,
    &act_decel,
    &act_stop,
    &act_stop1
  };

  if (pActwk->userflag.b.h < 0) /* Line 187, Address: 0x101e95c */
  {

    pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 190, Address: 0x101e974 */
    if (((int*)pActwk)[15] == 0) /* Line 191, Address: 0x101e98c */
      patchg(pActwk, pchg_b); /* Line 192, Address: 0x101e99c */
    else
      patchg(pActwk, pchg_e); /* Line 194, Address: 0x101e9b8 */
    actionsub(pActwk); /* Line 195, Address: 0x101e9cc */
    frameout_s(pActwk); /* Line 196, Address: 0x101e9d8 */
    return; /* Line 197, Address: 0x101e9e4 */
  }
  if (enemy_suicide(pActwk)) return; /* Line 199, Address: 0x101e9ec */
  act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 200, Address: 0x101ea00 */
  actionsub(pActwk); /* Line 201, Address: 0x101ea44 */
  frameout_s(pActwk); /* Line 202, Address: 0x101ea50 */
} /* Line 203, Address: 0x101ea5c */



static void act_init(sprite_status* pActwk) { /* Line 207, Address: 0x101ea70 */
  pActwk->r_no0 += 2; /* Line 208, Address: 0x101ea7c */
  pActwk->actflg |= 4; /* Line 209, Address: 0x101ea8c */
  pActwk->sprpri = 3; /* Line 210, Address: 0x101ea9c */
  pActwk->sproffset = 9136; /* Line 211, Address: 0x101eaa8 */
  pActwk->sprhs = 20; /* Line 212, Address: 0x101eab4 */
  pActwk->sprhsize = 20; /* Line 213, Address: 0x101eac0 */
  pActwk->sprvsize = 12; /* Line 214, Address: 0x101eacc */
  pActwk->colino = 49; /* Line 215, Address: 0x101ead8 */
  ((short*)pActwk)[32] = 120; /* Line 216, Address: 0x101eae4 */
  ((short*)pActwk)[33] = pActwk->xposi.w.h; /* Line 217, Address: 0x101eaf0 */
  if (!pActwk->userflag.b.h) /* Line 218, Address: 0x101eb00 */
  {
    pActwk->patbase = pat_amenbo_e; /* Line 220, Address: 0x101eb10 */
    ((int*)pActwk)[15] = 1; /* Line 221, Address: 0x101eb20 */
    ((int*)pActwk)[13] = -1536; /* Line 222, Address: 0x101eb2c */
    ((int*)pActwk)[14] = 256; /* Line 223, Address: 0x101eb38 */
  } /* Line 224, Address: 0x101eb44 */
  else
  {
    pActwk->patbase = pat_amenbo_b; /* Line 227, Address: 0x101eb4c */
    ((int*)pActwk)[15] = 0; /* Line 228, Address: 0x101eb5c */
    ((int*)pActwk)[13] = -512; /* Line 229, Address: 0x101eb64 */
    ((int*)pActwk)[14] = 192; /* Line 230, Address: 0x101eb70 */
  }
  act_accel(pActwk); /* Line 232, Address: 0x101eb7c */
} /* Line 233, Address: 0x101eb88 */



static void act_accel(sprite_status* pActwk) { /* Line 237, Address: 0x101eba0 */
  int lD5, lD6;

  lD6 = ((int*)pActwk)[12] + ((int*)pActwk)[13]; /* Line 240, Address: 0x101ebb4 */
  if (!pActwk->userflag.b.h) /* Line 241, Address: 0x101ebc8 */
    lD5 = -98304; /* Line 242, Address: 0x101ebd8 */
  else
    lD5 = -49152; /* Line 244, Address: 0x101ebe8 */

  if (lD6 <= lD5) /* Line 246, Address: 0x101ebf0 */
  {
    lD6 = lD5; /* Line 248, Address: 0x101ebfc */

    pActwk->r_no0 += 2; /* Line 250, Address: 0x101ec00 */
    ((int*)pActwk)[13] *= -1; /* Line 251, Address: 0x101ec10 */
  } /* Line 252, Address: 0x101ec20 */
  else
  {

    lD5 = -lD5; /* Line 256, Address: 0x101ec28 */
    if (lD6 < lD5) goto label1; /* Line 257, Address: 0x101ec2c */

    lD6 = lD5; /* Line 259, Address: 0x101ec38 */

    pActwk->r_no0 += 2; /* Line 261, Address: 0x101ec3c */
    ((int*)pActwk)[13] *= -1; /* Line 262, Address: 0x101ec4c */
  }

label1:
  ((int*)pActwk)[12] = lD6; /* Line 266, Address: 0x101ec5c */
  if (!pActwk->userflag.b.h) /* Line 267, Address: 0x101ec64 */
    act_tama(pActwk); /* Line 268, Address: 0x101ec74 */

  if (((int*)pActwk)[15] == 0) /* Line 270, Address: 0x101ec80 */
    patchg(pActwk, pchg_b); /* Line 271, Address: 0x101ec90 */
  else
    patchg(pActwk, pchg_e); /* Line 273, Address: 0x101ecac */
  act_move0(pActwk); /* Line 274, Address: 0x101ecc0 */
} /* Line 275, Address: 0x101eccc */



static void act_decel(sprite_status* pActwk) { /* Line 279, Address: 0x101ecf0 */
  int lD6;
  unsigned char temp0, temp1;

  lD6 = ((int*)pActwk)[12] + ((int*)pActwk)[14]; /* Line 283, Address: 0x101ed08 */
  temp0 = temp1 = 0; /* Line 284, Address: 0x101ed1c */
  if (((int*)pActwk)[12] < 0) /* Line 285, Address: 0x101ed28 */
    temp0 = 255; /* Line 286, Address: 0x101ed38 */
  if (lD6 < 0) /* Line 287, Address: 0x101ed40 */
    temp1 = 255; /* Line 288, Address: 0x101ed48 */
  if (temp0 ^ temp1) /* Line 289, Address: 0x101ed50 */
  {
    pActwk->r_no0 += 2; /* Line 291, Address: 0x101ed64 */
    ((int*)pActwk)[14] *= -1; /* Line 292, Address: 0x101ed74 */
    lD6 = 0; /* Line 293, Address: 0x101ed84 */
    if (!pActwk->userflag.b.h) /* Line 294, Address: 0x101ed88 */
      ((short*)pActwk)[23] = 60; /* Line 295, Address: 0x101ed98 */
    else
      ((short*)pActwk)[23] = 60; /* Line 297, Address: 0x101edac */
  }

  ((int*)pActwk)[12] = lD6; /* Line 300, Address: 0x101edb8 */
  if (!pActwk->userflag.b.h) /* Line 301, Address: 0x101edc0 */
    act_tama(pActwk); /* Line 302, Address: 0x101edd0 */

  act_move0(pActwk); /* Line 304, Address: 0x101eddc */
} /* Line 305, Address: 0x101ede8 */



static void act_stop(sprite_status* pActwk) { /* Line 309, Address: 0x101ee10 */
  --((short*)pActwk)[23]; /* Line 310, Address: 0x101ee1c */
  if (((short*)pActwk)[23] <= 0) /* Line 311, Address: 0x101ee2c */
  {
    pActwk->r_no0 += 2; /* Line 313, Address: 0x101ee44 */
    pActwk->actflg ^= 1; /* Line 314, Address: 0x101ee54 */
    pActwk->cddat ^= 1; /* Line 315, Address: 0x101ee64 */
    if (!pActwk->userflag.b.h) /* Line 316, Address: 0x101ee74 */
      ((short*)pActwk)[23] = 60; /* Line 317, Address: 0x101ee84 */
    else
      ((short*)pActwk)[23] = 60; /* Line 319, Address: 0x101ee98 */
  }

  if (!pActwk->userflag.b.h) /* Line 322, Address: 0x101eea4 */
    act_tama(pActwk); /* Line 323, Address: 0x101eeb4 */

  act_move0(pActwk); /* Line 325, Address: 0x101eec0 */
} /* Line 326, Address: 0x101eecc */



static void act_stop1(sprite_status* pActwk) { /* Line 330, Address: 0x101eee0 */
  --((short*)pActwk)[23]; /* Line 331, Address: 0x101eeec */
  if (((short*)pActwk)[23] <= 0) /* Line 332, Address: 0x101eefc */
    pActwk->r_no0 = 2; /* Line 333, Address: 0x101ef14 */

  act_move0(pActwk); /* Line 335, Address: 0x101ef20 */
} /* Line 336, Address: 0x101ef2c */



static void act_move0(sprite_status* pActwk) { /* Line 340, Address: 0x101ef40 */
  pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 341, Address: 0x101ef48 */
  pActwk->yposi.w.h = waterposi - 8; /* Line 342, Address: 0x101ef60 */
} /* Line 343, Address: 0x101ef84 */



static void act_tama(sprite_status* pActwk) { /* Line 347, Address: 0x101ef90 */
  sprite_status* subActwk;

  --((short*)pActwk)[32]; /* Line 350, Address: 0x101ef9c */
  if (((short*)pActwk)[32] <= 0) /* Line 351, Address: 0x101efac */
  {
    ((short*)pActwk)[32] = 120; /* Line 353, Address: 0x101efc4 */
    if (act_check(pActwk) != 0) /* Line 354, Address: 0x101efd0 */
    {

      if (actwkchk(&subActwk) == 0) /* Line 357, Address: 0x101efe4 */
      {
        subActwk->actno = pActwk->actno; /* Line 359, Address: 0x101eff8 */
        subActwk->userflag.b.h = -1; /* Line 360, Address: 0x101f008 */
        ((short*)subActwk)[44] = (unsigned char)(pActwk - actwk); /* Line 361, Address: 0x101f014 */
        subActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 362, Address: 0x101f04c */
        subActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 363, Address: 0x101f05c */
        subActwk->actflg = pActwk->actflg; /* Line 364, Address: 0x101f06c */
        subActwk->sprpri = pActwk->sprpri + 1; /* Line 365, Address: 0x101f07c */
        subActwk->sproffset = pActwk->sproffset; /* Line 366, Address: 0x101f098 */
        subActwk->sprhs = 4; /* Line 367, Address: 0x101f0a8 */
        subActwk->sprhsize = 4; /* Line 368, Address: 0x101f0b4 */
        subActwk->sprvsize = 4; /* Line 369, Address: 0x101f0c0 */
        subActwk->colino = 178; /* Line 370, Address: 0x101f0cc */
        subActwk->patbase = pActwk->patbase; /* Line 371, Address: 0x101f0d8 */
        ((int*)subActwk)[15] = ((int*)pActwk)[15]; /* Line 372, Address: 0x101f0e8 */
        subActwk->mstno.b.h = 1; /* Line 373, Address: 0x101f0f8 */
        if (!(subActwk->actflg & 1)) /* Line 374, Address: 0x101f104 */
          ((int*)subActwk)[12] = -0x20000; /* Line 375, Address: 0x101f11c */
        else
          ((int*)subActwk)[12] = 0x20000; /* Line 377, Address: 0x101f130 */
        if ((char)pActwk->actflg < 0) /* Line 378, Address: 0x101f13c */
          soundset(160); /* Line 379, Address: 0x101f15c */
      }
    }
  }
} /* Line 383, Address: 0x101f168 */



static int act_check(sprite_status* pActwk) { /* Line 387, Address: 0x101f180 */
  short tmp;
  unsigned char bD0;
  unsigned char bD1;
  int ret;


  ret = 0; /* Line 394, Address: 0x101f198 */

  tmp = actwk[0].yposi.w.h - pActwk->yposi.w.h + 96; /* Line 396, Address: 0x101f19c */
  if ((unsigned short)tmp < 192) /* Line 397, Address: 0x101f1d4 */
  {
    tmp -= 192; /* Line 399, Address: 0x101f1e8 */
    bD0 = bD1 = 0; /* Line 400, Address: 0x101f1f4 */
    tmp = actwk[0].xposi.w.h - pActwk->xposi.w.h; /* Line 401, Address: 0x101f200 */
    if (tmp < 0) /* Line 402, Address: 0x101f234 */
      bD1 = 255; /* Line 403, Address: 0x101f244 */
    tmp += 96; /* Line 404, Address: 0x101f24c */
    if ((unsigned short)tmp < 192) /* Line 405, Address: 0x101f258 */
    {
      if (!(pActwk->actflg & 1)) /* Line 407, Address: 0x101f26c */
        bD0 = 255; /* Line 408, Address: 0x101f284 */
      if (!(bD1 ^ bD0)) /* Line 409, Address: 0x101f28c */
        ret = -1; /* Line 410, Address: 0x101f2a0 */
    }
  }
  return ret; /* Line 413, Address: 0x101f2a4 */
} /* Line 414, Address: 0x101f2a8 */
