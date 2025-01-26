#include "..\EQU.H"
#include "PISTON6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

#if defined(R61B) || defined(R62B)
  #define SPRITE_PISTON6_BASE 464
#elif defined(R63C) || defined(R63D)
  #define SPRITE_PISTON6_BASE 447
#else
  #define SPRITE_PISTON6_BASE 470
#endif

static sprite_pattern nullpat =
{
  1,
  { { 0, 0, 0, 0 } }
};
static sprite_pattern piston6pat0 =
{
  1,
  { { -32, -40, 0, SPRITE_PISTON6_BASE } }
};
sprite_pattern* piston6pat[2] =
{
  &piston6pat0,
  &nullpat
};












void piston6(sprite_status* actionwk) { /* Line 42, Address: 0x101c9a0 */
  if (actionwk->userflag.b.h < 0) /* Line 43, Address: 0x101c9ac */
  {
    piston6_side(actionwk); /* Line 45, Address: 0x101c9c4 */
    return; /* Line 46, Address: 0x101c9d0 */
  }
  switch (actionwk->r_no0) /* Line 48, Address: 0x101c9d8 */
  {
    case 0:
      piston6_init(actionwk); /* Line 51, Address: 0x101ca00 */
    case 2:
      piston6_move(actionwk); /* Line 53, Address: 0x101ca0c */
      break;
  }
  actionsub(actionwk); /* Line 56, Address: 0x101ca18 */
  frameout_s(actionwk); /* Line 57, Address: 0x101ca24 */
} /* Line 58, Address: 0x101ca30 */

void piston6_ridechk(sprite_status* actionwk) { /* Line 60, Address: 0x101ca40 */
  ridechk(actionwk, &actwk[0]); /* Line 61, Address: 0x101ca4c */
} /* Line 62, Address: 0x101ca60 */

void piston6_init(sprite_status* actionwk) { /* Line 64, Address: 0x101ca70 */
  sprite_status* a1;

  actionwk->r_no0 += 2; /* Line 67, Address: 0x101ca7c */
  actionwk->actflg |= 4; /* Line 68, Address: 0x101ca8c */

  actionwk->sproffset = 832; /* Line 70, Address: 0x101ca9c */
  actionwk->patbase = piston6pat; /* Line 71, Address: 0x101caa8 */
  actionwk->sprvsize = 40; /* Line 72, Address: 0x101cab8 */
  actionwk->sprhsize = 32; /* Line 73, Address: 0x101cac4 */
  ((short*)actionwk)[29] = actionwk->xposi.w.h; /* Line 74, Address: 0x101cad0 */
  ((short*)actionwk)[27] = actionwk->yposi.w.h; /* Line 75, Address: 0x101cae0 */
  if (actwkchk(&a1) == 0) pis6_setdata(actionwk, a1, 32); /* Line 76, Address: 0x101caf0 */
  if (actwkchk(&a1) == 0) pis6_setdata(actionwk, a1, -32); /* Line 77, Address: 0x101cb18 */
} /* Line 78, Address: 0x101cb40 */

void piston6_move(sprite_status* actionwk) { /* Line 80, Address: 0x101cb50 */
  short d0;

  piston6_sub(actionwk); /* Line 83, Address: 0x101cb60 */
  d0 = actionwk->actfree[17]; /* Line 84, Address: 0x101cb6c */
  d0 = -d0; /* Line 85, Address: 0x101cb80 */
  d0 += ((short*)actionwk)[27]; /* Line 86, Address: 0x101cb9c */
  actionwk->yposi.w.h = d0; /* Line 87, Address: 0x101cbb0 */

  if (actionwk->actfree[18] != 0) /* Line 89, Address: 0x101cbb8 */
  {
    if (actionwk->actfree[16] == 0) goto label1; /* Line 91, Address: 0x101cbcc */
  }

  if (actionwk->actfree[17] >= 33) /* Line 94, Address: 0x101cbe0 */
  {
    ride_on_clr(actionwk, &actwk[0]); /* Line 96, Address: 0x101cbf8 */
    return; /* Line 97, Address: 0x101cc0c */
  }
label1:
  piston6_ridechk(actionwk); /* Line 100, Address: 0x101cc14 */
} /* Line 101, Address: 0x101cc20 */

void piston6_sub(sprite_status* actionwk) { /* Line 103, Address: 0x101cc40 */
  if (actionwk->actfree[16] != 0) /* Line 104, Address: 0x101cc48 */
  {
    if (--actionwk->actfree[16] != 0) return; /* Line 106, Address: 0x101cc5c */
  }

  if (actionwk->actfree[18] != 0) /* Line 109, Address: 0x101cc7c */
  {
    --actionwk->actfree[17]; /* Line 111, Address: 0x101cc90 */
    if ((char)actionwk->actfree[17] > 0) return; /* Line 112, Address: 0x101cca0 */
    actionwk->actfree[17] = actionwk->actfree[18] = 0; /* Line 113, Address: 0x101ccc0 */

    actionwk->actfree[16] = 60; /* Line 115, Address: 0x101ccd4 */
  } /* Line 116, Address: 0x101cce0 */
  else
  {

    actionwk->actfree[17] += 8; /* Line 120, Address: 0x101cce8 */
    if (actionwk->actfree[17] < 80) return; /* Line 121, Address: 0x101ccf8 */
    actionwk->actfree[17] = 80; /* Line 122, Address: 0x101cd10 */
    actionwk->actfree[18] = 1; /* Line 123, Address: 0x101cd1c */
    actionwk->actfree[16] = 60; /* Line 124, Address: 0x101cd28 */
  }
} /* Line 126, Address: 0x101cd34 */


void pis6_setdata(sprite_status* actionwk, sprite_status* a1, short d0) { /* Line 129, Address: 0x101cd40 */
  a1->actno = 32; /* Line 130, Address: 0x101cd50 */
  ((unsigned short*)a1)[28] = actionwk - actwk; /* Line 131, Address: 0x101cd5c */
  a1->userflag.b.h = -1; /* Line 132, Address: 0x101cd90 */
  a1->xposi.w.h = actionwk->xposi.w.h + d0; /* Line 133, Address: 0x101cd9c */
  a1->yposi.w.h = actionwk->yposi.w.h; /* Line 134, Address: 0x101cdcc */
  a1->actflg |= 4; /* Line 135, Address: 0x101cddc */
  a1->patbase = piston6pat; /* Line 136, Address: 0x101cdec */
  a1->sprvsize = 40; /* Line 137, Address: 0x101cdfc */

  a1->patno = 1; /* Line 139, Address: 0x101ce08 */
} /* Line 140, Address: 0x101ce14 */


void piston6_side(sprite_status* actionwk) { /* Line 143, Address: 0x101ce20 */
  sprite_status* a1;

  a1 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 146, Address: 0x101ce30 */
  if (a1->actno != 32) /* Line 147, Address: 0x101ce54 */
  {
    frameout(actionwk); /* Line 149, Address: 0x101ce68 */
    return; /* Line 150, Address: 0x101ce74 */
  }
  actionwk->yposi.w.h = a1->yposi.w.h; /* Line 152, Address: 0x101ce7c */

  hitchk(actionwk, &actwk[0]); /* Line 154, Address: 0x101ce88 */
  actionsub(actionwk); /* Line 155, Address: 0x101ce9c */
} /* Line 156, Address: 0x101cea8 */
