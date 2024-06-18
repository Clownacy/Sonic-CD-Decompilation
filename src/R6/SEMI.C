#include "..\EQU.H"
#include "SEMI.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static void act_init(sprite_status* actionwk);
static short act_check(sprite_status* actionwk, sprite_status* pw);
static void bomb(sprite_status* actionwk);

static char pchg0[6] = { 3, 1, 2, 3, 2, -1 };
char pchg_bomb0[4] = { 1, 0, 1, -1 };
static char* pchg[1] = { pchg0 };
char* pchg_bomb[1] = { pchg_bomb0 };
static sprite_pattern pat00 =
{
  1,
  { { -16, -16, 0, 465 } }
};
static sprite_pattern pat01 =
{
  1,
  { { -16, -16, 0, 466 } }
};
static sprite_pattern pat02 =
{
  1,
  { { -20, -16, 0, 467 } }
};
static sprite_pattern pat03 =
{
  1,
  { { -16, -16, 0, 468 } }
};
static sprite_pattern pat04 =
{
  1,
  { { -16, -16, 0, 469 } }
};
static sprite_pattern pat05 =
{
  1,
  { { -16, -16, 0, 470 } }
};
static sprite_pattern pat06 =
{
  1,
  { { -20, -16, 0, 471 } }
};
static sprite_pattern pat07 =
{
  1,
  { { -16, -16, 0, 472 } }
};
static sprite_pattern pat08 =
{
  1,
  { { -8, -8, 0, 473 } }
};
static sprite_pattern pat09 =
{
  1,
  { { -8, -8, 0, 474 } }
};
sprite_pattern* pat_semi_e[4] = { &pat00, &pat01, &pat02, &pat03 };
sprite_pattern* pat_semi_b[4] = { &pat04, &pat05, &pat06, &pat07 };
static sprite_pattern* pat_bomb[2] = { &pat08, &pat09 };
















void semi(sprite_status* actionwk) { /* Line 87, Address: 0x101e650 */
  if (actionwk->userflag.b.l < 0) /* Line 88, Address: 0x101e65c */
  {
    bomb(actionwk); /* Line 90, Address: 0x101e674 */
    return; /* Line 91, Address: 0x101e680 */
  }
  if (enemy_suicide(actionwk) == -1) return; /* Line 93, Address: 0x101e688 */
  switch (actionwk->r_no0) { /* Line 94, Address: 0x101e6a8 */

    case 0:
      act_init(actionwk); /* Line 97, Address: 0x101e70c */
    case 2:
      act_wait(actionwk); /* Line 99, Address: 0x101e718 */
      break; /* Line 100, Address: 0x101e724 */
    case 4:
      act_wait1(actionwk); /* Line 102, Address: 0x101e72c */
      break; /* Line 103, Address: 0x101e738 */
    case 6:
      act_movea(actionwk); /* Line 105, Address: 0x101e740 */
    case 8:
      act_movea1(actionwk); /* Line 107, Address: 0x101e74c */
      break; /* Line 108, Address: 0x101e758 */
    case 10:
      act_moveb(actionwk); /* Line 110, Address: 0x101e760 */
    case 12:
      act_moveb1(actionwk); /* Line 112, Address: 0x101e76c */
      break;
  }
  actionsub(actionwk); /* Line 115, Address: 0x101e778 */
  frameout_s(actionwk); /* Line 116, Address: 0x101e784 */
} /* Line 117, Address: 0x101e790 */

static void act_init(sprite_status* actionwk) { /* Line 119, Address: 0x101e7a0 */
  actionwk->r_no0 += 2; /* Line 120, Address: 0x101e7a8 */
  actionwk->actflg |= 4; /* Line 121, Address: 0x101e7b8 */
  actionwk->sprpri = 1; /* Line 122, Address: 0x101e7c8 */
  actionwk->sprvsize = 16; /* Line 123, Address: 0x101e7d4 */

  actionwk->sprhs = 19; /* Line 125, Address: 0x101e7e0 */
  actionwk->sprhsize = 19; /* Line 126, Address: 0x101e7ec */
  actionwk->sproffset = 42152; /* Line 127, Address: 0x101e7f8 */
  actionwk->colino = 54; /* Line 128, Address: 0x101e804 */


  actionwk->actfree[8] = actionwk->userflag.b.l; /* Line 131, Address: 0x101e810 */
  if (actionwk->userflag.b.h != 0) /* Line 132, Address: 0x101e820 */
    actionwk->patbase = pat_semi_b; /* Line 133, Address: 0x101e838 */
  else
    actionwk->patbase = pat_semi_e; /* Line 135, Address: 0x101e850 */
} /* Line 136, Address: 0x101e860 */

void act_wait(sprite_status* actionwk) { /* Line 138, Address: 0x101e870 */
  if (--((short*)actionwk)[27] > 0) return; /* Line 139, Address: 0x101e878 */
  actionwk->r_no0 += 2; /* Line 140, Address: 0x101e8a0 */
} /* Line 141, Address: 0x101e8b0 */

void act_wait1(sprite_status* actionwk) { /* Line 143, Address: 0x101e8c0 */
  if (!act_check(actionwk, &actwk[0])) return; /* Line 144, Address: 0x101e8cc */
  actionwk->r_no0 += 2; /* Line 145, Address: 0x101e8e8 */
} /* Line 146, Address: 0x101e8f8 */

static short act_check(sprite_status* actionwk, sprite_status* pw) { /* Line 148, Address: 0x101e910 */
  short d0w;

  d0w = pw->yposi.w.h; /* Line 151, Address: 0x101e920 */
  d0w -= actionwk->yposi.w.h; /* Line 152, Address: 0x101e930 */
  if (d0w < -96 || d0w > 96) return 0; /* Line 153, Address: 0x101e944 */
  ((short*)actionwk)[28] = pw->xposi.w.h - actionwk->xposi.w.h; /* Line 154, Address: 0x101e978 */

  d0w = pw->xposi.w.h; /* Line 156, Address: 0x101e9ac */
  d0w -= actionwk->xposi.w.h; /* Line 157, Address: 0x101e9bc */
  if (d0w >= -120 && d0w <= 120) return 1; /* Line 158, Address: 0x101e9d0 */
  return 0; /* Line 159, Address: 0x101ea04 */

} /* Line 161, Address: 0x101ea08 */

void act_movea(sprite_status* actionwk) { /* Line 163, Address: 0x101ea20 */
  int d0, d1;
  short d2;

  actionwk->r_no0 += 2; /* Line 167, Address: 0x101ea34 */
  d0 = 65536; /* Line 168, Address: 0x101ea44 */
  d1 = -32768; /* Line 169, Address: 0x101ea48 */
  d2 = 96; /* Line 170, Address: 0x101ea4c */
  if (actionwk->userflag.b.h != 0) /* Line 171, Address: 0x101ea58 */
  {
    d0 = 49152; /* Line 173, Address: 0x101ea70 */
    d1 = 24576; /* Line 174, Address: 0x101ea74 */
    d2 = 42; /* Line 175, Address: 0x101ea78 */
  }

  if (((short*)actionwk)[28] >= 0) /* Line 178, Address: 0x101ea84 */
  {
    d0 = -d0; /* Line 180, Address: 0x101ea9c */
  }
  *(int*)&actionwk->actfree[0] = d0; /* Line 182, Address: 0x101eaa0 */
  *(int*)&actionwk->actfree[4] = d1; /* Line 183, Address: 0x101eaac */
  ((short*)actionwk)[27] = d2; /* Line 184, Address: 0x101eab8 */
} /* Line 185, Address: 0x101eac0 */

void act_movea1(sprite_status* actionwk) { /* Line 187, Address: 0x101eae0 */
  if (--((short*)actionwk)[27] <= 0) actionwk->r_no0 += 2; /* Line 188, Address: 0x101eaec */

  actionwk->xposi.l += *(int*)&actionwk->actfree[0]; /* Line 190, Address: 0x101eb24 */
  actionwk->yposi.l += *(int*)&actionwk->actfree[4]; /* Line 191, Address: 0x101eb40 */
  patchg(actionwk, (unsigned char**)pchg); /* Line 192, Address: 0x101eb5c */
} /* Line 193, Address: 0x101eb70 */

void act_moveb(sprite_status* actionwk) { /* Line 195, Address: 0x101eb80 */
  int d0;

  actionwk->r_no0 += 2; /* Line 198, Address: 0x101eb8c */
  ((short*)actionwk)[27] = 0; /* Line 199, Address: 0x101eb9c */
  d0 = 65536; /* Line 200, Address: 0x101eba4 */
  if (actionwk->userflag.b.h != 0) /* Line 201, Address: 0x101eba8 */
    d0 = 49152; /* Line 202, Address: 0x101ebc0 */

  if (((short*)actionwk)[28] >= 0) /* Line 204, Address: 0x101ebc4 */
  {
    d0 = -d0; /* Line 206, Address: 0x101ebdc */
  }
  *(int*)&actionwk->actfree[0] = d0; /* Line 208, Address: 0x101ebe0 */
} /* Line 209, Address: 0x101ebec */

void act_moveb1(sprite_status* actionwk) { /* Line 211, Address: 0x101ec00 */
  sprite_status* a1;

  if (actionwk->userflag.b.h == 0) /* Line 214, Address: 0x101ec0c */
  {
    ((short*)actionwk)[27] &= 63; /* Line 216, Address: 0x101ec24 */
    if (((short*)actionwk)[27] == 0) /* Line 217, Address: 0x101ec34 */
    {
      if (act_check(actionwk, &actwk[0]) != 0) /* Line 219, Address: 0x101ec4c */
      {
        if (actwkchk(&a1) == 0) /* Line 221, Address: 0x101ec70 */
        {
          a1->actno = actionwk->actno; /* Line 223, Address: 0x101ec84 */
          a1->xposi.l = actionwk->xposi.l; /* Line 224, Address: 0x101ec94 */
          a1->yposi.l = actionwk->yposi.l; /* Line 225, Address: 0x101eca4 */
          a1->yposi.w.h += 10; /* Line 226, Address: 0x101ecb4 */
          a1->userflag.b.l = -1; /* Line 227, Address: 0x101ecc4 */
          a1->actflg = actionwk->actflg; /* Line 228, Address: 0x101ecd0 */
          a1->sprpri = actionwk->sprpri; /* Line 229, Address: 0x101ece0 */
          ++a1->sprpri; /* Line 230, Address: 0x101ecf0 */
        }
      }
    }
    ++((short*)actionwk)[27]; /* Line 234, Address: 0x101ed00 */
  }

  actionwk->xposi.l += *(int*)&actionwk->actfree[0]; /* Line 237, Address: 0x101ed10 */
  patchg(actionwk, (unsigned char**)pchg); /* Line 238, Address: 0x101ed2c */
} /* Line 239, Address: 0x101ed40 */





static void bomb(sprite_status* actionwk) { /* Line 245, Address: 0x101ed50 */
  switch (actionwk->r_no0) /* Line 246, Address: 0x101ed5c */
  {
    case 0:
      bomb_init(actionwk); /* Line 249, Address: 0x101eda8 */
    case 2:
      bomb_fall(actionwk); /* Line 251, Address: 0x101edb4 */
      break; /* Line 252, Address: 0x101edc0 */
    case 4:
      bomb_wait(actionwk); /* Line 254, Address: 0x101edc8 */
      break; /* Line 255, Address: 0x101edd4 */
    case 6:
      bomb_blink(actionwk); /* Line 257, Address: 0x101eddc */
      break; /* Line 258, Address: 0x101ede8 */
    case 8:
      bomb_die(actionwk); /* Line 260, Address: 0x101edf0 */
      break;
  }
  actionsub(actionwk); /* Line 263, Address: 0x101edfc */
  frameout_s(actionwk); /* Line 264, Address: 0x101ee08 */
} /* Line 265, Address: 0x101ee14 */

void bomb_init(sprite_status* actionwk) { /* Line 267, Address: 0x101ee30 */
  actionwk->r_no0 += 2; /* Line 268, Address: 0x101ee38 */
  actionwk->colino = 183; /* Line 269, Address: 0x101ee48 */

  actionwk->sprvsize = 6; /* Line 271, Address: 0x101ee54 */
  actionwk->sprhs = 6; /* Line 272, Address: 0x101ee60 */
  actionwk->sprhsize = 6; /* Line 273, Address: 0x101ee6c */
  actionwk->sproffset = 33992; /* Line 274, Address: 0x101ee78 */
  actionwk->patbase = pat_bomb; /* Line 275, Address: 0x101ee84 */
  *(int*)&actionwk->actfree[4] = 32768; /* Line 276, Address: 0x101ee94 */
} /* Line 277, Address: 0x101eea4 */

void bomb_fall(sprite_status* actionwk) { /* Line 279, Address: 0x101eeb0 */
  short d1;

  actionwk->yposi.l += *(int*)&actionwk->actfree[4]; /* Line 282, Address: 0x101eec0 */
  *(int*)&actionwk->actfree[4] += 16384; /* Line 283, Address: 0x101eedc */
  d1 = emycol_d(actionwk); /* Line 284, Address: 0x101eef4 */
  if (d1 < 0) /* Line 285, Address: 0x101ef08 */
  {
    actionwk->r_no0 += 2; /* Line 287, Address: 0x101ef18 */
    actionwk->yposi.w.h += d1; /* Line 288, Address: 0x101ef28 */
    ((short*)actionwk)[27] = 120; /* Line 289, Address: 0x101ef38 */
  }
} /* Line 291, Address: 0x101ef44 */

void bomb_wait(sprite_status* actionwk) { /* Line 293, Address: 0x101ef60 */
  short t;

  --((short*)actionwk)[27]; /* Line 296, Address: 0x101ef6c */
  t = ((short*)actionwk)[27]; /* Line 297, Address: 0x101ef7c */
  if (t < 0) /* Line 298, Address: 0x101ef8c */
  {
    actionwk->r_no0 += 2; /* Line 300, Address: 0x101ef9c */
    ((short*)actionwk)[27] = 120; /* Line 301, Address: 0x101efac */
  }
} /* Line 303, Address: 0x101efb8 */

void bomb_blink(sprite_status* actionwk) { /* Line 305, Address: 0x101efd0 */
  short t;

  --((short*)actionwk)[27]; /* Line 308, Address: 0x101efe0 */
  t = ((short*)actionwk)[27]; /* Line 309, Address: 0x101eff0 */
  if (t < 0) /* Line 310, Address: 0x101f000 */
  {
    actionwk->r_no0 += 2; /* Line 312, Address: 0x101f010 */
  }

  patchg(actionwk, (unsigned char**)pchg_bomb); /* Line 315, Address: 0x101f020 */
} /* Line 316, Address: 0x101f034 */

void bomb_die(sprite_status* actionwk) { /* Line 318, Address: 0x101f050 */
  actionwk->actno = 24; /* Line 319, Address: 0x101f05c */
  actionwk->r_no0 = 0; /* Line 320, Address: 0x101f068 */
  actionwk->r_no1 = 1; /* Line 321, Address: 0x101f070 */
  if ((char)actionwk->actflg < 0) /* Line 322, Address: 0x101f07c */
    soundset(158); /* Line 323, Address: 0x101f09c */
} /* Line 324, Address: 0x101f0a8 */
