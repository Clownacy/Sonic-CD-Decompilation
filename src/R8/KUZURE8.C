#include "..\EQU.H"
#include "KUZURE8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"

#if defined(R82)
  #define SPRITE_KUZURE8_BASE 422
#elif defined(R83)
  #define SPRITE_KUZURE8_BASE 423
#else
  #define SPRITE_KUZURE8_BASE 444
#endif

static sprite_pattern pat00 = { 1, { { -8, -16, 0, SPRITE_KUZURE8_BASE } } };
static sprite_pattern pat01 = { 1, { { -16, -16, 0, SPRITE_KUZURE8_BASE + 1 } } };
static sprite_pattern pat02 = { 1, { { -24, -16, 0, SPRITE_KUZURE8_BASE + 2 } } };
static sprite_pattern pat03 = { 1, { { -32, -16, 0, SPRITE_KUZURE8_BASE + 3 } } };
static sprite_pattern pat04 = { 1, { { -40, -16, 0, SPRITE_KUZURE8_BASE + 4 } } };
static sprite_pattern pat05 = { 1, { { -48, -16, 0, SPRITE_KUZURE8_BASE + 5 } } };
static sprite_pattern pat06 = { 1, { { -56, -16, 0, SPRITE_KUZURE8_BASE + 6 } } };
static sprite_pattern pat07 = { 1, { { -64, -16, 0, SPRITE_KUZURE8_BASE + 7 } } };
static sprite_pattern pat08 = { 1, { { -8, -8, 0, SPRITE_KUZURE8_BASE + 8 } } };
static sprite_pattern pat09 = { 1, { { -8, -8, 0, SPRITE_KUZURE8_BASE + 9 } } };
sprite_pattern* pat_kuzure_a[10] =
{
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05,
  &pat06,
  &pat07,
  &pat08,
  &pat09
};












void kuzure8(sprite_status* actionwk) { /* Line 51, Address: 0x1022a30 */
  if (actionwk->userflag.b.l != 0) /* Line 52, Address: 0x1022a3c */
  {
    parts(actionwk); /* Line 54, Address: 0x1022a54 */
    return; /* Line 55, Address: 0x1022a60 */
  }
  switch (actionwk->r_no0) /* Line 57, Address: 0x1022a68 */
  {
    case 0:
      main_ini(actionwk); /* Line 60, Address: 0x1022ab4 */
      break; /* Line 61, Address: 0x1022ac0 */
    case 2:
      main_check(actionwk); /* Line 63, Address: 0x1022ac8 */
      break; /* Line 64, Address: 0x1022ad4 */
    case 4:
      main_wait(actionwk); /* Line 66, Address: 0x1022adc */
      break; /* Line 67, Address: 0x1022ae8 */
    case 6:
      main_break(actionwk); /* Line 69, Address: 0x1022af0 */
      break; /* Line 70, Address: 0x1022afc */
    case 8:
      main_hitchk(actionwk); /* Line 72, Address: 0x1022b04 */
      break;
  }
} /* Line 75, Address: 0x1022b10 */

void main_ini(sprite_status* actionwk) { /* Line 77, Address: 0x1022b20 */
  char d0, d1;

  actionwk->actflg |= 4; /* Line 80, Address: 0x1022b30 */
  actionwk->patbase = pat_kuzure_a; /* Line 81, Address: 0x1022b40 */
  actionwk->sprvsize = 17; /* Line 82, Address: 0x1022b50 */
  if (stageno.b.l != 2) /* Line 83, Address: 0x1022b5c */
    actionwk->sproffset = 17624; /* Line 84, Address: 0x1022b78 */
  else
    actionwk->sproffset = 17274; /* Line 86, Address: 0x1022b8c */
  d0 = actionwk->userflag.b.h; /* Line 87, Address: 0x1022b98 */
  if (d0 < 0) d0 = -d0; /* Line 88, Address: 0x1022ba8 */

  d1 = d0; /* Line 90, Address: 0x1022bd4 */
  --d0; /* Line 91, Address: 0x1022bdc */
  actionwk->patno = d0; /* Line 92, Address: 0x1022be8 */
  d1 <<= 3; /* Line 93, Address: 0x1022bf0 */
  actionwk->sprhs = d1; /* Line 94, Address: 0x1022bfc */
  actionwk->sprhsize = d1; /* Line 95, Address: 0x1022c04 */
  d0 = 3; /* Line 96, Address: 0x1022c0c */
  d1 = 2; /* Line 97, Address: 0x1022c18 */
  if (actionwk->userflag.b.h < 0) /* Line 98, Address: 0x1022c24 */
  {
    d0 = 1; /* Line 100, Address: 0x1022c3c */
    d1 = 8; /* Line 101, Address: 0x1022c48 */
  }
  actionwk->sprpri = d0; /* Line 103, Address: 0x1022c54 */
  actionwk->r_no0 = d1; /* Line 104, Address: 0x1022c5c */
} /* Line 105, Address: 0x1022c64 */

void main_check(sprite_status* actionwk) { /* Line 107, Address: 0x1022c80 */
  if (ridechk(actionwk, &actwk[0]) != 0) /* Line 108, Address: 0x1022c8c */
  {
    actionwk->r_no0 += 2; /* Line 110, Address: 0x1022cb0 */
    actionwk->cdsts = 0; /* Line 111, Address: 0x1022cc0 */
    ((short*)actionwk)[23] = 8; /* Line 112, Address: 0x1022cc8 */
    if (actwk[0].xspeed.w < 0) /* Line 113, Address: 0x1022cd4 */
      ((short*)actionwk)[24] = -8; /* Line 114, Address: 0x1022cec */
    else
      ((short*)actionwk)[24] = 8; /* Line 116, Address: 0x1022d00 */
    soundset(163); /* Line 117, Address: 0x1022d0c */
  }
  actionsub(actionwk); /* Line 119, Address: 0x1022d18 */
  frameout_s(actionwk); /* Line 120, Address: 0x1022d24 */
} /* Line 121, Address: 0x1022d30 */

void main_wait(sprite_status* actionwk) { /* Line 123, Address: 0x1022d40 */
  short t;

  ridechk(actionwk, &actwk[0]); /* Line 126, Address: 0x1022d50 */
  --((short*)actionwk)[23]; /* Line 127, Address: 0x1022d64 */
  t = ((short*)actionwk)[23]; /* Line 128, Address: 0x1022d74 */
  if (t < 0) actionwk->r_no0 += 2; /* Line 129, Address: 0x1022d84 */
  actionsub(actionwk); /* Line 130, Address: 0x1022da4 */
} /* Line 131, Address: 0x1022db0 */





void main_break(sprite_status* actionwk) { /* Line 137, Address: 0x1022dd0 */
  short d1, d2, d3;
  char ride;
  sprite_status* a1;

  ride = 0; /* Line 142, Address: 0x1022dec */
  d1 = -1; /* Line 143, Address: 0x1022df0 */
  d2 = 8; /* Line 144, Address: 0x1022dfc */
  d3 = (actionwk->userflag.b.h - 1) << 3; /* Line 145, Address: 0x1022e08 */
  if (((short*)actionwk)[24] >= 0) d3 = -d3; /* Line 146, Address: 0x1022e30 */
  if (actwkchk(&a1) == 0) /* Line 147, Address: 0x1022e64 */
  {
    a1->actno = actionwk->actno; /* Line 149, Address: 0x1022e78 */
    a1->actflg = actionwk->actflg; /* Line 150, Address: 0x1022e88 */
    a1->sproffset = actionwk->sproffset; /* Line 151, Address: 0x1022e98 */
    a1->patbase = actionwk->patbase; /* Line 152, Address: 0x1022ea8 */
    a1->xposi.w.h = actionwk->xposi.w.h; /* Line 153, Address: 0x1022eb8 */
    a1->yposi.w.h = actionwk->yposi.w.h; /* Line 154, Address: 0x1022ec8 */

    a1->userflag.b.l = d1; /* Line 156, Address: 0x1022ed8 */
    a1->yposi.w.h -= d2; /* Line 157, Address: 0x1022ee8 */
    a1->xposi.w.h += d3; /* Line 158, Address: 0x1022ef8 */
    ((short*)a1)[23] = 4; /* Line 159, Address: 0x1022f08 */
    a1->patno = 8; /* Line 160, Address: 0x1022f14 */
    if (actwkchk(&a1) == 0) /* Line 161, Address: 0x1022f20 */
    {
      a1->actno = actionwk->actno; /* Line 163, Address: 0x1022f34 */
      a1->actflg = actionwk->actflg; /* Line 164, Address: 0x1022f44 */
      a1->sproffset = actionwk->sproffset; /* Line 165, Address: 0x1022f54 */
      a1->patbase = actionwk->patbase; /* Line 166, Address: 0x1022f64 */
      a1->xposi.w.h = actionwk->xposi.w.h; /* Line 167, Address: 0x1022f74 */
      a1->yposi.w.h = actionwk->yposi.w.h; /* Line 168, Address: 0x1022f84 */

      a1->userflag.b.l = d1; /* Line 170, Address: 0x1022f94 */
      a1->yposi.w.h += d2; /* Line 171, Address: 0x1022fa4 */
      a1->xposi.w.h += d3; /* Line 172, Address: 0x1022fb4 */
      ((short*)a1)[23] = 0; /* Line 173, Address: 0x1022fc4 */
      a1->patno = 9; /* Line 174, Address: 0x1022fcc */
    }
  }


  if (ridechk(actionwk, &actwk[0])) ride_on_clr(actionwk, &actwk[0]); /* Line 179, Address: 0x1022fd8 */

  --actionwk->userflag.b.h; /* Line 181, Address: 0x1023008 */
  ride = actionwk->userflag.b.h; /* Line 182, Address: 0x1023018 */
  if (ride <= 0) /* Line 183, Address: 0x1023028 */
  {
    frameout(actionwk); /* Line 185, Address: 0x1023038 */
    return; /* Line 186, Address: 0x1023044 */
  }
  actionwk->r_no0 -= 2; /* Line 188, Address: 0x102304c */
  --actionwk->patno; /* Line 189, Address: 0x102305c */
  actionwk->sprhs -= 8; /* Line 190, Address: 0x102306c */
  actionwk->sprhsize -= 8; /* Line 191, Address: 0x102307c */
  ((short*)actionwk)[23] = 7; /* Line 192, Address: 0x102308c */
  actionwk->xposi.w.h += ((short*)actionwk)[24]; /* Line 193, Address: 0x1023098 */

  ridechk(actionwk, &actwk[0]); /* Line 195, Address: 0x10230b0 */
  actionsub(actionwk); /* Line 196, Address: 0x10230c4 */
} /* Line 197, Address: 0x10230d0 */

void main_hitchk(sprite_status* actionwk) { /* Line 199, Address: 0x10230f0 */
  hitchk(actionwk, &actwk[0]); /* Line 200, Address: 0x10230fc */
  actionsub(actionwk); /* Line 201, Address: 0x1023110 */
  frameout_s(actionwk); /* Line 202, Address: 0x102311c */
} /* Line 203, Address: 0x1023128 */








void parts(sprite_status* actionwk) { /* Line 212, Address: 0x1023140 */
  switch (actionwk->r_no0) /* Line 213, Address: 0x102314c */
  {
    case 0:
      parts_ini(actionwk); /* Line 216, Address: 0x1023180 */
      break; /* Line 217, Address: 0x102318c */
    case 2:
      parts_wait(actionwk); /* Line 219, Address: 0x1023194 */
      break; /* Line 220, Address: 0x10231a0 */
    case 4:
      parts_fall(actionwk); /* Line 222, Address: 0x10231a8 */
      break;
  }
} /* Line 225, Address: 0x10231b4 */

void parts_ini(sprite_status* actionwk) { /* Line 227, Address: 0x10231d0 */
  actionwk->r_no0 += 2; /* Line 228, Address: 0x10231dc */
  actionwk->sprpri = 3; /* Line 229, Address: 0x10231ec */
  actionwk->sprhs = 8; /* Line 230, Address: 0x10231f8 */
  actionwk->sprhsize = 8; /* Line 231, Address: 0x1023204 */
  actionwk->sprvsize = 8; /* Line 232, Address: 0x1023210 */
  actionsub(actionwk); /* Line 233, Address: 0x102321c */
} /* Line 234, Address: 0x1023228 */

void parts_wait(sprite_status* actionwk) { /* Line 236, Address: 0x1023240 */
  short t;

  t = ((short*)actionwk)[23]--; /* Line 239, Address: 0x1023250 */
  if (t <= 0) actionwk->r_no0 += 2; /* Line 240, Address: 0x1023268 */
  actionsub(actionwk); /* Line 241, Address: 0x1023288 */
} /* Line 242, Address: 0x1023294 */

void parts_fall(sprite_status* actionwk) { /* Line 244, Address: 0x10232b0 */
  int d0;

  if ((char)actionwk->actflg >= 0) /* Line 247, Address: 0x10232c0 */
  {
    frameout(actionwk); /* Line 249, Address: 0x10232e0 */
    return; /* Line 250, Address: 0x10232ec */
  }
  d0 = ((int*)actionwk)[12] + 16384; /* Line 252, Address: 0x10232f4 */
  if (d0 > 1441792) d0 = 1441792; /* Line 253, Address: 0x1023300 */

  ((int*)actionwk)[12] = d0; /* Line 255, Address: 0x1023318 */
  actionwk->yposi.l += d0; /* Line 256, Address: 0x1023320 */
  actionsub(actionwk); /* Line 257, Address: 0x1023330 */
} /* Line 258, Address: 0x102333c */
