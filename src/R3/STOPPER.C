#include "..\EQU.H"
#include "STOPPER.H"
#include "..\ACTION.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"

static void act_init(sprite_status* actionwk);
static void act_move(sprite_status* actionwk);

static sprite_pattern patstop1 =
{
  1,
  { { -16, -8, 0, 567 } }
};
static sprite_pattern patstop2 =
{
  1,
  { { -16, -8, 0, 568 } }
};
static sprite_pattern patstop3 =
{
  1,
  { { -16, -8, 0, 569 } }
};
sprite_pattern* stopper_pat[3] =
{
  &patstop1,
  &patstop2,
  &patstop3
};
static char pchg0[5] = { 9, 0, 1, 2, -4 };
static char pchg1[5] = { 9, 2, 1, 0, -4 };
static char* pchg[2] =
{
  pchg0,
  pchg1
};







void stopper(sprite_status* actionwk) { /* Line 45, Address: 0x102f210 */
  sprite_status* a1;

  switch (actionwk->r_no0) /* Line 48, Address: 0x102f220 */
  {
    case 0:
      act_init(actionwk); /* Line 51, Address: 0x102f278 */
    case 2:
      act_move(actionwk); /* Line 53, Address: 0x102f284 */
      break; /* Line 54, Address: 0x102f290 */
    case 4:
      act_open(actionwk); /* Line 56, Address: 0x102f298 */
      break; /* Line 57, Address: 0x102f2a4 */
    case 6:
      act_close(actionwk); /* Line 59, Address: 0x102f2ac */
      break; /* Line 60, Address: 0x102f2b8 */
    case 8:
      act_move1(actionwk); /* Line 62, Address: 0x102f2c0 */
      break; /* Line 63, Address: 0x102f2cc */
    case 10:
      act_move(actionwk); /* Line 65, Address: 0x102f2d4 */
      break;
  }


  a1 = &actwk[((unsigned short*)actionwk)[29]]; /* Line 70, Address: 0x102f2e0 */
  if (a1->actno != 54) /* Line 71, Address: 0x102f304 */
  {
    frameout(actionwk); /* Line 73, Address: 0x102f318 */
    return; /* Line 74, Address: 0x102f324 */
  }
  actionsub(actionwk); /* Line 76, Address: 0x102f32c */

} /* Line 78, Address: 0x102f338 */

static void act_init(sprite_status* actionwk) { /* Line 80, Address: 0x102f350 */
  actionwk->r_no0 += 2; /* Line 81, Address: 0x102f358 */
  actionwk->actflg |= 4; /* Line 82, Address: 0x102f368 */
  actionwk->sprpri = 3; /* Line 83, Address: 0x102f378 */
  actionwk->sproffset = 1086; /* Line 84, Address: 0x102f384 */
  actionwk->patbase = stopper_pat; /* Line 85, Address: 0x102f390 */
  actionwk->sprhsize = 16; /* Line 86, Address: 0x102f3a0 */
  actionwk->sprvsize = 8; /* Line 87, Address: 0x102f3ac */
} /* Line 88, Address: 0x102f3b8 */

static void act_move(sprite_status* actionwk) { /* Line 90, Address: 0x102f3d0 */
  sprite_status* a1;

  if (actionwk->patno != 2) return; /* Line 93, Address: 0x102f3e0 */
  a1 = &actwk[0]; /* Line 94, Address: 0x102f3f8 */
  if (ridechk(actionwk, a1) == 0) return;; /* Line 95, Address: 0x102f400 */
  a1->cddat &= 247; /* Line 96, Address: 0x102f420 */
  a1->cddat |= 2; /* Line 97, Address: 0x102f42c */
  a1->cddat &= 239; /* Line 98, Address: 0x102f438 */
  a1->cddat &= 223; /* Line 99, Address: 0x102f444 */
  a1->xspeed.w = 0; /* Line 100, Address: 0x102f450 */
  a1->yspeed.w = -1024; /* Line 101, Address: 0x102f454 */
} /* Line 102, Address: 0x102f45c */

void act_open(sprite_status* actionwk) { /* Line 104, Address: 0x102f470 */
  actionwk->mstno.w = 255; /* Line 105, Address: 0x102f47c */
  actionwk->r_no0 += 4; /* Line 106, Address: 0x102f488 */
  act_move1(actionwk); /* Line 107, Address: 0x102f498 */
} /* Line 108, Address: 0x102f4a4 */

void act_close(sprite_status* actionwk) { /* Line 110, Address: 0x102f4c0 */
  actionwk->mstno.w = 511; /* Line 111, Address: 0x102f4cc */
  actionwk->r_no0 += 2; /* Line 112, Address: 0x102f4d8 */
  act_move1(actionwk); /* Line 113, Address: 0x102f4e8 */
} /* Line 114, Address: 0x102f4f4 */

void act_move1(sprite_status* actionwk) { /* Line 116, Address: 0x102f510 */
  patchg(actionwk, (unsigned char**)pchg); /* Line 117, Address: 0x102f51c */
} /* Line 118, Address: 0x102f530 */
