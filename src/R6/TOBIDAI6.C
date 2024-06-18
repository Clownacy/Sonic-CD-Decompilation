#include "..\EQU.H"
#include "TOBIDAI6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"

static sprite_pattern tobidai6pat0 =
{
  1,
  { { -32, -16, 0, 449 } }
};
sprite_pattern* tobidai6pat[1] = { &tobidai6pat0 };












































void tobidai6(sprite_status* actionwk) { /* Line 59, Address: 0x101f140 */
  switch (actionwk->r_no0) /* Line 60, Address: 0x101f14c */
  {
    case 0:
      tobidai6_init(actionwk); /* Line 63, Address: 0x101f18c */
    case 2:
      tobidai6_move0(actionwk); /* Line 65, Address: 0x101f198 */
      break; /* Line 66, Address: 0x101f1a4 */
    case 4:
      tobidai6_move1(actionwk); /* Line 68, Address: 0x101f1ac */
      break; /* Line 69, Address: 0x101f1b8 */
    case 6:
      tobidai6_move2(actionwk); /* Line 71, Address: 0x101f1c0 */
      break;
  }
  actionsub(actionwk); /* Line 74, Address: 0x101f1cc */
  frameout_s(actionwk); /* Line 75, Address: 0x101f1d8 */
} /* Line 76, Address: 0x101f1e4 */

void tobidai6_ridechk(sprite_status* actionwk) { /* Line 78, Address: 0x101f200 */
  yuka_ridechk(actionwk); /* Line 79, Address: 0x101f20c */
} /* Line 80, Address: 0x101f218 */


void tobidai6_init(sprite_status* actionwk) { /* Line 83, Address: 0x101f230 */
  actionwk->r_no0 += 2; /* Line 84, Address: 0x101f238 */
  actionwk->actflg |= 4; /* Line 85, Address: 0x101f248 */
  actionwk->sprpri = 3; /* Line 86, Address: 0x101f258 */
  actionwk->sproffset = 17384; /* Line 87, Address: 0x101f264 */
  actionwk->patbase = tobidai6pat; /* Line 88, Address: 0x101f270 */
  actionwk->sprvsize = 16; /* Line 89, Address: 0x101f280 */
  actionwk->sprhsize = 32; /* Line 90, Address: 0x101f28c */
} /* Line 91, Address: 0x101f298 */

void tobidai6_move0(sprite_status* actionwk) { /* Line 93, Address: 0x101f2b0 */
  if (yuka_chk() == 0) /* Line 94, Address: 0x101f2bc */
  {
    actionwk->yspeed.w = -1536; /* Line 96, Address: 0x101f2cc */
    ((short*)actionwk)[33] = 16; /* Line 97, Address: 0x101f2d8 */
    actionwk->r_no0 += 2; /* Line 98, Address: 0x101f2e4 */
  }

  tobidai6_ridechk(actionwk); /* Line 101, Address: 0x101f2f4 */
} /* Line 102, Address: 0x101f300 */

void tobidai6_move1(sprite_status* actionwk) { /* Line 104, Address: 0x101f310 */
  short d1;

  tobidai6_speedset(actionwk); /* Line 107, Address: 0x101f320 */
  d1 = emycol_u(actionwk); /* Line 108, Address: 0x101f32c */
  if (d1 < 0) actionwk->yspeed.w = 0; /* Line 109, Address: 0x101f340 */

  d1 = emycol_d(actionwk); /* Line 111, Address: 0x101f358 */
  if (d1 < 0) /* Line 112, Address: 0x101f36c */
  {
    if (yuka_chk() == 0) /* Line 114, Address: 0x101f37c */
    {
      actionwk->yspeed.w = -1536; /* Line 116, Address: 0x101f38c */
      ((short*)actionwk)[33] = 16; /* Line 117, Address: 0x101f398 */
      if (actionwk->actflg & 128) /* Line 118, Address: 0x101f3a4 */
      {
        soundset(180); /* Line 120, Address: 0x101f3bc */
        goto label1; /* Line 121, Address: 0x101f3c8 */
      }
    }

    actionwk->yspeed.w = -384; /* Line 125, Address: 0x101f3d0 */
    ((short*)actionwk)[33] = 16; /* Line 126, Address: 0x101f3dc */
    actionwk->r_no0 += 2; /* Line 127, Address: 0x101f3e8 */
  }
label1:
  tobidai6_ridechk(actionwk); /* Line 130, Address: 0x101f3f8 */
} /* Line 131, Address: 0x101f404 */

void tobidai6_move2(sprite_status* actionwk) { /* Line 133, Address: 0x101f420 */
  short d1;

  tobidai6_speedset(actionwk); /* Line 136, Address: 0x101f430 */
  if (actionwk->yspeed.w >= 0) /* Line 137, Address: 0x101f43c */
  {
    d1 = emycol_d(actionwk); /* Line 139, Address: 0x101f454 */
    if (d1 < 0) /* Line 140, Address: 0x101f468 */
    {
      actionwk->yspeed.w = 0; /* Line 142, Address: 0x101f478 */
      ((short*)actionwk)[33] = 0; /* Line 143, Address: 0x101f480 */
      actionwk->r_no0 -= 4; /* Line 144, Address: 0x101f488 */
    }
  }

  tobidai6_ridechk(actionwk); /* Line 148, Address: 0x101f498 */
} /* Line 149, Address: 0x101f4a4 */

void tobidai6_speedset(sprite_status* actionwk) { /* Line 151, Address: 0x101f4c0 */
  short d0;

  d0 = actionwk->yspeed.w + ((short*)actionwk)[33]; /* Line 154, Address: 0x101f4cc */
  if (d0 >= 0) /* Line 155, Address: 0x101f500 */
  {
    if (d0 >= 1536) d0 = 1536; /* Line 157, Address: 0x101f510 */
  }

  actionwk->yspeed.w = d0; /* Line 160, Address: 0x101f530 */
  actionwk->yposi.l += d0 << 8; /* Line 161, Address: 0x101f538 */
} /* Line 162, Address: 0x101f554 */



int yuka_chk() { /* Line 166, Address: 0x101f570 */
  unsigned char d0;

  if (time_flag < 2) /* Line 169, Address: 0x101f578 */
  {
    d0 = 60; /* Line 171, Address: 0x101f590 */
    if (time_flag != 0) d0 += 30; /* Line 172, Address: 0x101f598 */
    if (clchgcnt[3] == d0) return -1; /* Line 173, Address: 0x101f5b4 */
  }

  return 0; /* Line 176, Address: 0x101f5d8 */
} /* Line 177, Address: 0x101f5dc */


void yuka_ridechk(sprite_status* actionwk) { /* Line 180, Address: 0x101f5f0 */
  short d0;

  d0 = actwk[0].yspeed.w; /* Line 183, Address: 0x101f600 */
  if (d0 >= 0) goto label1; /* Line 184, Address: 0x101f610 */
  d0 = -d0; /* Line 185, Address: 0x101f620 */
  if (d0 > 1536) return; /* Line 186, Address: 0x101f63c */

label1:
  if (actionwk->yspeed.w == 0) /* Line 189, Address: 0x101f650 */
    actionwk->actfree[4] = 0; /* Line 190, Address: 0x101f668 */
  else
    actionwk->actfree[4] = 4; /* Line 192, Address: 0x101f678 */

  actionwk->sprvsize += actionwk->actfree[4]; /* Line 194, Address: 0x101f684 */
  chk(actionwk, &actwk[0]); /* Line 195, Address: 0x101f69c */
  actionwk->sprvsize -= actionwk->actfree[4]; /* Line 196, Address: 0x101f6b0 */
} /* Line 197, Address: 0x101f6c8 */


void chk(sprite_status* actionwk, sprite_status* pw) { /* Line 200, Address: 0x101f6e0 */
  ((short*)actionwk)[26] = pw->yspeed.w; /* Line 201, Address: 0x101f6f0 */
  if (pw->cddat & 8) /* Line 202, Address: 0x101f700 */
  {
    if (!(pw->cddat & 2)) /* Line 204, Address: 0x101f718 */
      pw->yspeed.w = 0; /* Line 205, Address: 0x101f730 */
  }

  if (ride_on_chk(actionwk, pw)) /* Line 208, Address: 0x101f738 */
  {
    yuka_ride_on(actionwk, pw); /* Line 210, Address: 0x101f750 */
    return; /* Line 211, Address: 0x101f760 */
  }
  pw->yspeed.w = ((short*)actionwk)[26]; /* Line 213, Address: 0x101f768 */
} /* Line 214, Address: 0x101f778 */

void yuka_ride_on(sprite_status* actionwk, sprite_status* pw) { /* Line 216, Address: 0x101f790 */
  if (pw->r_no0 >= 6) /* Line 217, Address: 0x101f79c */
  {
    pw->yspeed.w = 0; /* Line 219, Address: 0x101f7b4 */
  } /* Line 220, Address: 0x101f7bc */
  else
  {
    pw->yposi.l = actionwk->yposi.l; /* Line 223, Address: 0x101f7c4 */
    pw->yposi.w.h -= (short)pw->sprvsize + 16; /* Line 224, Address: 0x101f7d4 */
    if (actionwk->yspeed.w >= 0) /* Line 225, Address: 0x101f804 */
    {
      pw->yspeed.w = 0; /* Line 227, Address: 0x101f81c */
      return; /* Line 228, Address: 0x101f824 */
    }


    pw->yspeed.w = actionwk->yspeed.w; /* Line 232, Address: 0x101f82c */
  }
} /* Line 234, Address: 0x101f83c */
