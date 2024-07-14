#include "..\EQU.H"
#include "DAI8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"

static void act_init(sprite_status* actionwk);

static char p00[47] =
{
  0, 5, 5, 5, 5, 5, 4, 4, 4, 5,
  5, 5, 5, 5, 4, 4, 4, 3, 3, 3,
  3, 3, 2, 2, 2, 3, 3, 3, 3, 3,
  2, 2, 2, 1, 1, 1, 1, 1, 7, 7,
  7, 1, 1, 1, 1, 1, 0
};
static char p01[152] =
{
  0, 1, 1, 1, 1, 1, 7, 7, 7, 1,
  1, 1, 1, 1, 2, 2, 2, 3, 3, 3,
  3, 3, 2, 2, 2, 3, 3, 3, 3, 3,
  4, 4, 4, 5, 5, 5, 5, 5, 4, 4,
  4, 5, 5, 5, 5, 5, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 5, 5, 5, 5,
  5, 4, 4, 4, 5, 5, 5, 5, 5, 4,
  4, 4, 3, 3, 3, 3, 3, 2, 2, 2,
  3, 3, 3, 3, 3, 2, 2, 2, 1, 1,
  1, 1, 1, 7, 7, 7, 1, 1, 1, 1,
  1, 0
};
static char* pchg[2] =
{
  p00,
  p01
};
static sprite_pattern pat00 =
{
  1,
  { { -16, -16, 0, 433 } }
};
static sprite_pattern pat01 =
{
  1,
  { { -16, -16, 0, 434 } }
};
static sprite_pattern pat02 =
{
  1,
  { { -8, -16, 0, 435 } }
};
static sprite_pattern pat03 =
{
  1,
  { { -8, -16, 0, 436 } }
};
static sprite_pattern pat04 =
{
  1,
  { { -4, -16, 0, 437 } }
};
static sprite_pattern pat05 =
{
  1,
  { { -4, -16, 0, 438 } }
};
static sprite_pattern patnull =
{
  1,
  { { 0, 0, 0, 0 } }
};
sprite_pattern* pat_dai8[8] =
{
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05,
  &patnull,
  &pat00
};


void dai8(sprite_status* actionwk) { /* Line 90, Address: 0x1024a10 */
  short ano;

  if (actionwk->userflag.b.h < 0) /* Line 93, Address: 0x1024a20 */
  {
    ano = ((short*)actionwk)[24]; /* Line 95, Address: 0x1024a38 */
    if (actwk[ano].actno != 44) /* Line 96, Address: 0x1024a48 */
    {
      frameout(actionwk); /* Line 98, Address: 0x1024a7c */
      return; /* Line 99, Address: 0x1024a88 */
    }
    if (((short*)actionwk)[25] != ((short*)&actwk[ano])[25]) /* Line 101, Address: 0x1024a90 */
    {

      frameout(actionwk); /* Line 104, Address: 0x1024ad4 */
      return; /* Line 105, Address: 0x1024ae0 */
    }
    if (((short*)actionwk)[26] != ((short*)&actwk[ano])[26]) /* Line 107, Address: 0x1024ae8 */
    {

      frameout(actionwk); /* Line 110, Address: 0x1024b2c */
      return; /* Line 111, Address: 0x1024b38 */
    }
  }

  switch (actionwk->r_no0) /* Line 115, Address: 0x1024b40 */
  {
    case 0:
      act_init(actionwk); /* Line 118, Address: 0x1024b8c */
      break; /* Line 119, Address: 0x1024b98 */
    case 2:
      act_wait(actionwk); /* Line 121, Address: 0x1024ba0 */
      break; /* Line 122, Address: 0x1024bac */
    case 4:
      act_appear(actionwk); /* Line 124, Address: 0x1024bb4 */
      break; /* Line 125, Address: 0x1024bc0 */
    case 6:
      act_on(actionwk); /* Line 127, Address: 0x1024bc8 */
      break; /* Line 128, Address: 0x1024bd4 */
    case 8:
      act_off(actionwk); /* Line 130, Address: 0x1024bdc */
      break;
  }
  actionsub(actionwk); /* Line 133, Address: 0x1024be8 */
  if (actionwk->userflag.b.h >= 0) /* Line 134, Address: 0x1024bf4 */
  {
    frameout_s00(actionwk, ((short*)actionwk)[25]); /* Line 136, Address: 0x1024c0c */
  }
} /* Line 138, Address: 0x1024c20 */

static void act_init(sprite_status* actionwk) { /* Line 140, Address: 0x1024c40 */
  short tbl00[2] = { 60, 0 }; /* Line 141, Address: 0x1024c58 */
  short tbl01[5] = { 60, 1, 60, 32, 0 }; /* Line 142, Address: 0x1024c74 */
  short tbl02[8] = { 90, 2, 180, 32, 16, 270, 64, 32 }; /* Line 143, Address: 0x1024ca0 */
  sprite_status* a1;
  short *a5tbl, i, d6;

  switch (actionwk->userflag.b.h) /* Line 147, Address: 0x1024cd4 */
  {
    case 0:
      a5tbl = tbl00; /* Line 150, Address: 0x1024d0c */
      break; /* Line 151, Address: 0x1024d10 */
    case 1:
      a5tbl = tbl01; /* Line 153, Address: 0x1024d18 */
      break; /* Line 154, Address: 0x1024d1c */
    case 2:
      a5tbl = tbl02; /* Line 156, Address: 0x1024d24 */
      break;
  }
  ((short*)actionwk)[23] = *a5tbl++; /* Line 159, Address: 0x1024d28 */
  act_init_sub(actionwk, actionwk); /* Line 160, Address: 0x1024d3c */

  d6 = *a5tbl++; /* Line 162, Address: 0x1024d4c */
  for (i = 0; i < d6; ++i) /* Line 163, Address: 0x1024d60 */
  {
    if (actwkchk(&a1) != 0) /* Line 165, Address: 0x1024d6c */
    {
      frameout(actionwk); /* Line 167, Address: 0x1024d80 */
      break; /* Line 168, Address: 0x1024d8c */
    }
    a1->actno = actionwk->actno; /* Line 170, Address: 0x1024d94 */
    ((short*)a1)[24] = (unsigned short)(actionwk - actwk); /* Line 171, Address: 0x1024da4 */
    a1->userflag.b.h = -1; /* Line 172, Address: 0x1024de0 */
    ((short*)a1)[23] = *a5tbl++; /* Line 173, Address: 0x1024dec */
    a1->xposi.w.h = actionwk->xposi.w.h + *a5tbl++; /* Line 174, Address: 0x1024e00 */
    a1->yposi.w.h = actionwk->yposi.w.h + *a5tbl++; /* Line 175, Address: 0x1024e38 */
    act_init_sub(actionwk, a1); /* Line 176, Address: 0x1024e70 */
  } /* Line 177, Address: 0x1024e80 */
} /* Line 178, Address: 0x1024ea8 */

void act_init_sub(sprite_status* actionwk, sprite_status* a6) { /* Line 180, Address: 0x1024ed0 */
  a6->actflg |= 4; /* Line 181, Address: 0x1024edc */
  a6->sprpri = 3; /* Line 182, Address: 0x1024eec */
  a6->sprhs = 16; /* Line 183, Address: 0x1024ef8 */
  a6->sprhsize = 16; /* Line 184, Address: 0x1024f04 */
  a6->sprvsize = 16; /* Line 185, Address: 0x1024f10 */
  a6->sproffset = 920; /* Line 186, Address: 0x1024f1c */
  a6->patbase = pat_dai8; /* Line 187, Address: 0x1024f28 */
  a6->patno = 6; /* Line 188, Address: 0x1024f38 */
  a6->r_no0 = 2; /* Line 189, Address: 0x1024f44 */
  ((short*)a6)[25] = actionwk->xposi.w.h; /* Line 190, Address: 0x1024f50 */
  ((short*)a6)[26] = actionwk->yposi.w.h; /* Line 191, Address: 0x1024f60 */
} /* Line 192, Address: 0x1024f70 */

void act_wait(sprite_status* actionwk) { /* Line 194, Address: 0x1024f80 */
  if (--((short*)actionwk)[23] != 0) return; /* Line 195, Address: 0x1024f88 */
  actionwk->r_no0 += 2; /* Line 196, Address: 0x1024fb0 */
} /* Line 197, Address: 0x1024fc0 */

void act_appear(sprite_status* actionwk) { /* Line 199, Address: 0x1024fd0 */
  patchg(actionwk, (unsigned char**)pchg); /* Line 200, Address: 0x1024fdc */
  if (actionwk->patno == 0) /* Line 201, Address: 0x1024ff0 */
  {
    ((short*)actionwk)[23] = 120; /* Line 203, Address: 0x1025004 */
    actionwk->r_no0 += 2; /* Line 204, Address: 0x1025010 */
  }

} /* Line 207, Address: 0x1025020 */

void act_on(sprite_status* actionwk) { /* Line 209, Address: 0x1025030 */
  if (ridechk(actionwk, &actwk[0]) != 0) actionwk->actfree[21] = 255; /* Line 210, Address: 0x102503c */
  else actionwk->actfree[21] = 0; /* Line 211, Address: 0x1025074 */

  if (--((short*)actionwk)[23] != 0) return; /* Line 213, Address: 0x102507c */
  actionwk->mstno.w = 511; /* Line 214, Address: 0x10250a4 */
  actionwk->r_no0 += 2; /* Line 215, Address: 0x10250b0 */
  if (actionwk->actfree[21] != 0) /* Line 216, Address: 0x10250c0 */
  {
    ride_on_clr(actionwk, &actwk[0]); /* Line 218, Address: 0x10250d4 */
  }
} /* Line 220, Address: 0x10250e8 */

void act_off(sprite_status* actionwk) { /* Line 222, Address: 0x1025100 */
  patchg(actionwk, (unsigned char**)pchg); /* Line 223, Address: 0x102510c */

  if (actionwk->patno == 0) /* Line 225, Address: 0x1025120 */
  {
    ((short*)actionwk)[23] = 120; /* Line 227, Address: 0x1025134 */
    actionwk->r_no0 -= 2; /* Line 228, Address: 0x1025140 */
  }

} /* Line 231, Address: 0x1025150 */
