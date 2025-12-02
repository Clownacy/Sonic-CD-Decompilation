#include "..\EQU.H"
#include "MINOMUSI.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

#if defined(R61B) || defined(R62B)
  #define SPRITE_MINOMUSI_BASE 451
#else
  #define SPRITE_MINOMUSI_BASE 457
#endif

static short act_check(sprite_status* actionwk, sprite_status* pw);

static sprite_pattern nullpat =
{
  1,
  { { 0, 0, 0, 0 } }
};
static sprite_pattern ito01 =
{
  1,
  { { -4, -12, 0, SPRITE_MINOMUSI_BASE } }
};
static sprite_pattern ito02 =
{
  1,
  { { -4, -16, 0, SPRITE_MINOMUSI_BASE + 1 } }
};
static sprite_pattern ito03 =
{
  1,
  { { -4, -20, 0, SPRITE_MINOMUSI_BASE + 2 } }
};
static sprite_pattern ito04 =
{
  1,
  { { -4, -24, 0, SPRITE_MINOMUSI_BASE + 3 } }
};
static sprite_pattern ito05 =
{
  1,
  { { -4, -28, 0, SPRITE_MINOMUSI_BASE + 4 } }
};
static sprite_pattern ito06 =
{
  1,
  { { -4, -32, 0, SPRITE_MINOMUSI_BASE + 5 } }
};
static sprite_pattern ito07 =
{
  1,
  { { -4, -36, 0, SPRITE_MINOMUSI_BASE + 6 } }
};
static sprite_pattern ito08 =
{
  1,
  { { -4, -40, 0, SPRITE_MINOMUSI_BASE + 7 } }
};
static sprite_pattern mino1 =
{
  1,
  { { -8, -16, 0, SPRITE_MINOMUSI_BASE + 8 } }
};
static sprite_pattern mino2 =
{
  1,
  { { -12, -16, 0, SPRITE_MINOMUSI_BASE + 9 } }
};
static sprite_pattern mino3 =
{
  1,
  { { -16, -16, 0, SPRITE_MINOMUSI_BASE + 10 } }
};
static sprite_pattern mino4 =
{
  1,
  { { -8, -16, 0, SPRITE_MINOMUSI_BASE + 11 } }
};
static sprite_pattern mino5 =
{
  1,
  { { -8, -16, 0, SPRITE_MINOMUSI_BASE + 12 } }
};
sprite_pattern* pat_minomusi_e[12] = { &nullpat, &ito01, &ito02, &ito03, &ito04, &ito05, &ito06, &ito07, &ito08, &mino1, &mino2, &mino3 };
sprite_pattern* pat_minomusi_b[11] = { &nullpat, &ito01, &ito02, &ito03, &ito04, &ito05, &ito06, &ito07, &ito08, &mino4, &mino5 };
static char pchg0[36] = { 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10, -1 };
static char pchg1[4] = { 9, 9, 10, -1 };
char* pchg[2] = { pchg0, pchg1 };












void minomusi(sprite_status* actionwk) { /* Line 104, Address: 0x101cc30 */
  if (actionwk->userflag.b.l == 0) { body(actionwk); return; } /* Line 105, Address: 0x101cc3c */
  if (actionwk->userflag.b.l < 0) { ito(actionwk); return; } /* Line 106, Address: 0x101cc68 */
  hari(actionwk); /* Line 107, Address: 0x101cc94 */
} /* Line 108, Address: 0x101cca0 */

void body(sprite_status* actionwk) { /* Line 110, Address: 0x101ccb0 */
  void(*body_tbl[9])(sprite_status*) = /* Line 111, Address: 0x101ccbc */
  {
    &body_init,
    &body_wait,
    &body_wait1,
    &body_down,
    &body_down1,
    &body_up,
    &body_up1,
    &body_stay,
    &body_stay1
  };
  if (enemy_suicide(actionwk) == -1) return; /* Line 123, Address: 0x101cce8 */
  body_tbl[actionwk->r_no0 / 2](actionwk); /* Line 124, Address: 0x101cd08 */
  actionsub(actionwk); /* Line 125, Address: 0x101cd44 */
  frameout_s(actionwk); /* Line 126, Address: 0x101cd50 */
} /* Line 127, Address: 0x101cd5c */





void body_init(sprite_status* actionwk) { /* Line 133, Address: 0x101cd70 */
  sprite_status* a1;

  actionwk->r_no0 += 2; /* Line 136, Address: 0x101cd7c */
  actionwk->actflg |= 4; /* Line 137, Address: 0x101cd8c */
  actionwk->sprpri = 3; /* Line 138, Address: 0x101cd9c */

  actionwk->sprvsize = 16; /* Line 140, Address: 0x101cda8 */
  actionwk->sprhs = 16; /* Line 141, Address: 0x101cdb4 */
  actionwk->sprhsize = 16; /* Line 142, Address: 0x101cdc0 */
  actionwk->sproffset = 9352; /* Line 143, Address: 0x101cdcc */
  actionwk->colino = 52; /* Line 144, Address: 0x101cdd8 */
  actionwk->yposi.w.h += 8; /* Line 145, Address: 0x101cde4 */
  ((short*)actionwk)[28] = actionwk->yposi.w.h; /* Line 146, Address: 0x101cdf4 */
  ((short*)actionwk)[29] = actionwk->yposi.w.h + 95; /* Line 147, Address: 0x101ce04 */
  if (actionwk->userflag.b.h == 0) /* Line 148, Address: 0x101ce28 */
    actionwk->patbase = pat_minomusi_e; /* Line 149, Address: 0x101ce40 */
  else
    actionwk->patbase = pat_minomusi_b; /* Line 151, Address: 0x101ce58 */
  if (actwkchk2(actionwk, &a1) != 0) /* Line 152, Address: 0x101ce68 */
  {
    frameout(actionwk); /* Line 154, Address: 0x101ce80 */
    return; /* Line 155, Address: 0x101ce8c */
  }

  a1->actno = actionwk->actno; /* Line 158, Address: 0x101ce94 */
  a1->userflag.b.l = -1; /* Line 159, Address: 0x101cea4 */
  a1->xposi.w.h = actionwk->xposi.w.h; /* Line 160, Address: 0x101ceb0 */
  a1->yposi.w.h = actionwk->yposi.w.h; /* Line 161, Address: 0x101cec0 */
  a1->actflg = actionwk->actflg; /* Line 162, Address: 0x101ced0 */
  a1->sprpri = actionwk->sprpri; /* Line 163, Address: 0x101cee0 */
  ++a1->sprpri; /* Line 164, Address: 0x101cef0 */
  a1->sproffset = actionwk->sproffset; /* Line 165, Address: 0x101cf00 */
  a1->patbase = actionwk->patbase; /* Line 166, Address: 0x101cf10 */

  a1->sprvsize = 32; /* Line 168, Address: 0x101cf20 */
  a1->sprhs = 1; /* Line 169, Address: 0x101cf2c */
  a1->sprhsize = 1; /* Line 170, Address: 0x101cf38 */
  ((unsigned short*)a1)[30] = actionwk - actwk; /* Line 171, Address: 0x101cf44 */
} /* Line 172, Address: 0x101cf78 */

void body_wait(sprite_status* actionwk) { /* Line 174, Address: 0x101cf90 */
  actionwk->r_no0 += 2; /* Line 175, Address: 0x101cf9c */
  actionwk->patno = 9; /* Line 176, Address: 0x101cfac */
  ((short*)actionwk)[23] = 121; /* Line 177, Address: 0x101cfb8 */
  body_wait1(actionwk); /* Line 178, Address: 0x101cfc4 */
} /* Line 179, Address: 0x101cfd0 */

void body_wait1(sprite_status* actionwk) { /* Line 181, Address: 0x101cfe0 */
  if (--((short*)actionwk)[23] != 0) return; /* Line 182, Address: 0x101cfec */
  if (act_check(actionwk, &actwk[0])) /* Line 183, Address: 0x101d014 */
    actionwk->r_no0 += 2; /* Line 184, Address: 0x101d030 */
  else
    actionwk->r_no0 -= 2; /* Line 186, Address: 0x101d048 */
} /* Line 187, Address: 0x101d058 */

static short act_check(sprite_status* actionwk, sprite_status* pw) { /* Line 189, Address: 0x101d070 */
  short d0w;

  d0w = pw->yposi.w.h; /* Line 192, Address: 0x101d080 */
  d0w -= actionwk->yposi.w.h; /* Line 193, Address: 0x101d090 */
  d0w -= 40; /* Line 194, Address: 0x101d0a4 */

  if (d0w < 0 || d0w > 120) return 0; /* Line 196, Address: 0x101d0b0 */
  d0w = pw->xposi.w.h; /* Line 197, Address: 0x101d0e0 */
  d0w -= actionwk->xposi.w.h; /* Line 198, Address: 0x101d0f0 */
  d0w += 168; /* Line 199, Address: 0x101d104 */

  if (d0w >= 0 && d0w < 336) return 1; /* Line 201, Address: 0x101d110 */
  return 0; /* Line 202, Address: 0x101d140 */
} /* Line 203, Address: 0x101d144 */

void body_down(sprite_status* actionwk) { /* Line 205, Address: 0x101d160 */
  actionwk->r_no0 += 2; /* Line 206, Address: 0x101d16c */
  ((int*)actionwk)[13] = 524288; /* Line 207, Address: 0x101d17c */
  body_down1(actionwk); /* Line 208, Address: 0x101d188 */
} /* Line 209, Address: 0x101d194 */

void body_down1(sprite_status* actionwk) { /* Line 211, Address: 0x101d1b0 */
  short d0;

  actionwk->yposi.l += ((int*)actionwk)[13]; /* Line 214, Address: 0x101d1bc */
  d0 = ((short*)actionwk)[29] - actionwk->yposi.w.h; /* Line 215, Address: 0x101d1d4 */
  if (d0 <= 0) /* Line 216, Address: 0x101d208 */
  {
    actionwk->yposi.w.h += d0; /* Line 218, Address: 0x101d218 */
    actionwk->r_no0 = 14; /* Line 219, Address: 0x101d228 */
  }
} /* Line 221, Address: 0x101d234 */

void body_up(sprite_status* actionwk) { /* Line 223, Address: 0x101d250 */
  actionwk->r_no0 += 2; /* Line 224, Address: 0x101d25c */
  if (actionwk->userflag.b.h != 0) /* Line 225, Address: 0x101d26c */
    ((int*)actionwk)[13] = 0x20000; /* Line 226, Address: 0x101d284 */
  else
    ((int*)actionwk)[13] = 458752; /* Line 228, Address: 0x101d298 */
  body_up1(actionwk); /* Line 229, Address: 0x101d2a4 */
} /* Line 230, Address: 0x101d2b0 */

void body_up1(sprite_status* actionwk) { /* Line 232, Address: 0x101d2c0 */
  short d0;

  actionwk->yposi.l -= ((int*)actionwk)[13]; /* Line 235, Address: 0x101d2cc */
  d0 = ((short*)actionwk)[28] - actionwk->yposi.w.h; /* Line 236, Address: 0x101d2e4 */
  if (d0 >= 0) /* Line 237, Address: 0x101d318 */
  {
    actionwk->yposi.w.h += d0; /* Line 239, Address: 0x101d328 */
    actionwk->r_no0 = 2; /* Line 240, Address: 0x101d338 */
  }
} /* Line 242, Address: 0x101d344 */

void body_stay(sprite_status* actionwk) { /* Line 244, Address: 0x101d360 */
  short d0, d1;

  actionwk->r_no0 += 2; /* Line 247, Address: 0x101d370 */
  if (actionwk->userflag.b.h == 0) /* Line 248, Address: 0x101d380 */
  {
    d0 = 230; /* Line 250, Address: 0x101d398 */
    d1 = 255; /* Line 251, Address: 0x101d3a4 */
  } /* Line 252, Address: 0x101d3b0 */
  else
  {
    d0 = 61; /* Line 255, Address: 0x101d3b8 */
    d1 = 511; /* Line 256, Address: 0x101d3c4 */
  }
  ((short*)actionwk)[23] = d0; /* Line 258, Address: 0x101d3d0 */
  actionwk->mstno.w = d1; /* Line 259, Address: 0x101d3d8 */
} /* Line 260, Address: 0x101d3e0 */

void body_stay1(sprite_status* actionwk) { /* Line 262, Address: 0x101d400 */
  sprite_status* a1;

  if (--((short*)actionwk)[23] == 0) actionwk->r_no0 = 10; /* Line 265, Address: 0x101d40c */

  patchg(actionwk, (unsigned char**)pchg); /* Line 267, Address: 0x101d440 */
  if (actionwk->userflag.b.h != 0) return; /* Line 268, Address: 0x101d454 */

  if (actionwk->patcnt != 15) return; /* Line 270, Address: 0x101d46c */
  if (actwkchk2(actionwk, &a1) != 0) return; /* Line 271, Address: 0x101d484 */

  a1->actno = actionwk->actno; /* Line 273, Address: 0x101d49c */
  a1->userflag.b.l = 1; /* Line 274, Address: 0x101d4ac */
  a1->xposi.w.h = actionwk->xposi.w.h; /* Line 275, Address: 0x101d4b8 */
  a1->yposi.w.h = actionwk->yposi.w.h; /* Line 276, Address: 0x101d4c8 */
  a1->yposi.w.h += 4; /* Line 277, Address: 0x101d4d8 */
  a1->actflg = actionwk->actflg; /* Line 278, Address: 0x101d4e8 */
  a1->sprpri = actionwk->sprpri; /* Line 279, Address: 0x101d4f8 */
  a1->sproffset = actionwk->sproffset; /* Line 280, Address: 0x101d508 */
  a1->patbase = actionwk->patbase; /* Line 281, Address: 0x101d518 */

  a1->sprvsize = actionwk->sprvsize; /* Line 283, Address: 0x101d528 */
  a1->sprhs = actionwk->sprhs; /* Line 284, Address: 0x101d538 */
  a1->sprhsize = actionwk->sprhsize; /* Line 285, Address: 0x101d548 */
  ((unsigned short*)a1)[30] = actionwk - actwk; /* Line 286, Address: 0x101d558 */

  a1->colino = 181; /* Line 288, Address: 0x101d58c */
  if ((char)actionwk->actflg < 0) /* Line 289, Address: 0x101d598 */
    soundset(183); /* Line 290, Address: 0x101d5b8 */
} /* Line 291, Address: 0x101d5c4 */

void hari(sprite_status* actionwk) { /* Line 293, Address: 0x101d5e0 */
  sprite_status* a1;

  a1 = &actwk[((unsigned short*)actionwk)[30]]; /* Line 296, Address: 0x101d5f0 */
  if (a1->patcnt == 1) /* Line 297, Address: 0x101d614 */
    frameout(actionwk); /* Line 298, Address: 0x101d628 */
  else
    actionsub(actionwk); /* Line 300, Address: 0x101d63c */
} /* Line 301, Address: 0x101d648 */



void ito(sprite_status* actionwk) { /* Line 305, Address: 0x101d660 */
  sprite_status* a1;
  short d0;

  a1 = &actwk[((unsigned short*)actionwk)[30]]; /* Line 309, Address: 0x101d674 */
  if (a1->actno != 51) /* Line 310, Address: 0x101d698 */
  {
    frameout(actionwk); /* Line 312, Address: 0x101d6ac */
    return; /* Line 313, Address: 0x101d6b8 */
  }

  d0 = (a1->yposi.w.h - ((short*)a1)[28] - 24) >> 3; /* Line 316, Address: 0x101d6c0 */
  if (d0 < 0) d0 = 0; /* Line 317, Address: 0x101d6f4 */

  actionwk->patno = d0; /* Line 319, Address: 0x101d708 */
  d0 <<= 2; /* Line 320, Address: 0x101d714 */
  d0 += ((short*)a1)[28] + 16; /* Line 321, Address: 0x101d720 */
  actionwk->yposi.w.h = d0; /* Line 322, Address: 0x101d744 */
  actionsub(actionwk); /* Line 323, Address: 0x101d74c */
} /* Line 324, Address: 0x101d758 */
