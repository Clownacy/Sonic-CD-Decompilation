#include "..\EQU.H"
#include "DAIR6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\RIDECHK.H"

static sprite_pattern dair6pat0 = {
  1,
  { { -24, -16, 0, 418 } }
};
sprite_pattern* dair6pat[1] = { &dair6pat0 };






































void dair6(sprite_status* actionwk) { /* Line 51, Address: 0x101a270 */
  switch (actionwk->r_no0) { /* Line 52, Address: 0x101a27c */

    case 0:
      dair6_init(actionwk); /* Line 55, Address: 0x101a2a4 */
    case 2:
      dair6_move(actionwk); /* Line 57, Address: 0x101a2b0 */
      break;
  }
  actionsub(actionwk); /* Line 60, Address: 0x101a2bc */
  frameout_s00(actionwk, ((short*)actionwk)[29]); /* Line 61, Address: 0x101a2c8 */
} /* Line 62, Address: 0x101a2dc */

void dair6_ridechk(sprite_status* actionwk) { /* Line 64, Address: 0x101a2f0 */
  ridechk(actionwk, &actwk[0]); /* Line 65, Address: 0x101a2fc */
} /* Line 66, Address: 0x101a310 */


void dair6_init(sprite_status* actionwk) { /* Line 69, Address: 0x101a320 */
  actionwk->actflg |= 4; /* Line 70, Address: 0x101a328 */
  actionwk->sprpri = 1; /* Line 71, Address: 0x101a338 */
  actionwk->sproffset = 17384; /* Line 72, Address: 0x101a344 */
  actionwk->patbase = dair6pat; /* Line 73, Address: 0x101a350 */
  ((short*)actionwk)[29] = actionwk->xposi.w.h; /* Line 74, Address: 0x101a360 */
  ((short*)actionwk)[27] = actionwk->yposi.w.h; /* Line 75, Address: 0x101a370 */
  actionwk->sprvsize = 12; /* Line 76, Address: 0x101a380 */
  actionwk->sprhsize = 24; /* Line 77, Address: 0x101a38c */
  actionwk->r_no0 += 2; /* Line 78, Address: 0x101a398 */
} /* Line 79, Address: 0x101a3a8 */


void dair6_move(sprite_status* actionwk) { /* Line 82, Address: 0x101a3c0 */
  switch (actionwk->userflag.b.h) { /* Line 83, Address: 0x101a3cc */

    case 0:
      mv_right(actionwk); /* Line 86, Address: 0x101a410 */
      break; /* Line 87, Address: 0x101a41c */
    case 1:
      mv_left(actionwk); /* Line 89, Address: 0x101a424 */
      break; /* Line 90, Address: 0x101a430 */
    case 2:
      mv_up(actionwk); /* Line 92, Address: 0x101a438 */
      break; /* Line 93, Address: 0x101a444 */
    case 3:
      mv_down(actionwk); /* Line 95, Address: 0x101a44c */
      break;
  }
} /* Line 98, Address: 0x101a458 */


void mv_up(sprite_status* actionwk) { /* Line 101, Address: 0x101a470 */
  short d0;

  d0 = dair6_sub2(actionwk); /* Line 104, Address: 0x101a480 */
  d0 = -d0; /* Line 105, Address: 0x101a494 */
  actionwk->yposi.w.h = d0 + ((short*)actionwk)[27]; /* Line 106, Address: 0x101a4b0 */
  dair6_ridechk(actionwk); /* Line 107, Address: 0x101a4dc */
} /* Line 108, Address: 0x101a4e8 */


void mv_down(sprite_status* actionwk) { /* Line 111, Address: 0x101a500 */
  short d0;

  d0 = dair6_sub2(actionwk); /* Line 114, Address: 0x101a510 */
  actionwk->yposi.w.h = d0 + ((short*)actionwk)[27]; /* Line 115, Address: 0x101a524 */
  dair6_ridechk(actionwk); /* Line 116, Address: 0x101a550 */
} /* Line 117, Address: 0x101a55c */


void mv_right(sprite_status* actionwk) { /* Line 120, Address: 0x101a570 */
  int_union wk, d0l;
  short d0;

  wk.l = actionwk->xposi.l; /* Line 124, Address: 0x101a580 */
  d0 = dair6_sub2(actionwk); /* Line 125, Address: 0x101a58c */
  actionwk->xposi.w.h = d0 + ((short*)actionwk)[29]; /* Line 126, Address: 0x101a5a0 */
  d0l.l = actionwk->xposi.l - wk.l; /* Line 127, Address: 0x101a5cc */
  d0l.l >>= 8; /* Line 128, Address: 0x101a5e0 */
  actionwk->xspeed.w = d0l.w.l; /* Line 129, Address: 0x101a5ec */
  dair6_ridechk(actionwk); /* Line 130, Address: 0x101a5f8 */
} /* Line 131, Address: 0x101a604 */


void mv_left(sprite_status* actionwk) { /* Line 134, Address: 0x101a620 */
  short d0;
  int_union d0l, wk;

  wk.l = actionwk->xposi.l; /* Line 138, Address: 0x101a630 */
  d0 = dair6_sub2(actionwk); /* Line 139, Address: 0x101a63c */
  d0 = -d0; /* Line 140, Address: 0x101a650 */
  actionwk->xposi.w.h = d0 + ((short*)actionwk)[29]; /* Line 141, Address: 0x101a66c */
  d0l.l = actionwk->xposi.l - wk.l; /* Line 142, Address: 0x101a698 */
  d0l.l >>= 8; /* Line 143, Address: 0x101a6ac */
  actionwk->xspeed.w = d0l.w.l; /* Line 144, Address: 0x101a6b8 */
  dair6_ridechk(actionwk); /* Line 145, Address: 0x101a6c4 */
} /* Line 146, Address: 0x101a6d0 */

short dair6_sub2(sprite_status* actionwk) { /* Line 148, Address: 0x101a6f0 */
  short sin, cos;

  sinset(gametimer.w & 255, &sin, &cos); /* Line 151, Address: 0x101a6fc */
  sin = sin + sin + sin + sin >> 4; /* Line 152, Address: 0x101a724 */
  ++actionwk->actfree[16]; /* Line 153, Address: 0x101a770 */
  return sin; /* Line 154, Address: 0x101a780 */
} /* Line 155, Address: 0x101a784 */
