#include "..\EQU.H"
#include "TOGEBL6A.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"

static void act_init(sprite_status* actionwk);
static void act_move(sprite_status* actionwk);

static sprite_pattern spat_chg0 = {
  1,
  { { -8, -8, 0, 491 } }
};
static sprite_pattern spat_chg1 = {
  1,
  { { -8, -8, 0, 492 } }
};
sprite_pattern* pat_chg[1] = { &spat_chg0 };
sprite_pattern* pat_togeball[1] = { &spat_chg1 };

































void togeball(sprite_status* actionwk) { /* Line 53, Address: 0x102e7f0 */
  if (actionwk->userflag.b.h >= 0) /* Line 54, Address: 0x102e7fc */
    togeball_main(actionwk); /* Line 55, Address: 0x102e814 */
  else
    togeball_opt(actionwk); /* Line 57, Address: 0x102e828 */
} /* Line 58, Address: 0x102e834 */

void togeball_main(sprite_status* actionwk) { /* Line 60, Address: 0x102e850 */
  switch (actionwk->r_no0) /* Line 61, Address: 0x102e85c */
  {
    case 0:
      act_init(actionwk); /* Line 64, Address: 0x102e884 */
      break; /* Line 65, Address: 0x102e890 */
    case 2:
      act_move(actionwk); /* Line 67, Address: 0x102e898 */
      break;
  }
  actionsub(actionwk); /* Line 70, Address: 0x102e8a4 */
  frameout_s(actionwk); /* Line 71, Address: 0x102e8b0 */
} /* Line 72, Address: 0x102e8bc */

static void act_init(sprite_status* actionwk) { /* Line 74, Address: 0x102e8d0 */
  sprite_status* a1;

  actionwk->r_no0 += 2; /* Line 77, Address: 0x102e8dc */
  actionwk->actflg |= 4; /* Line 78, Address: 0x102e8ec */
  actionwk->sprpri = 1; /* Line 79, Address: 0x102e8fc */
  actionwk->sprhsize = 8; /* Line 80, Address: 0x102e908 */
  actionwk->sprvsize = 8; /* Line 81, Address: 0x102e914 */
  actionwk->patbase = pat_chg; /* Line 82, Address: 0x102e920 */
  actionwk->sproffset = 1016; /* Line 83, Address: 0x102e930 */
  ((short*)actionwk)[24] = 256; /* Line 84, Address: 0x102e93c */
  if (actionwk->userflag.b.h != 0) /* Line 85, Address: 0x102e948 */
    ((short*)actionwk)[24] = -((short*)actionwk)[24]; /* Line 86, Address: 0x102e960 */


  if (actwkchk2(actionwk, &a1) != 0) /* Line 89, Address: 0x102e984 */
  {
    frameout(actionwk); /* Line 91, Address: 0x102e99c */
    return; /* Line 92, Address: 0x102e9a8 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 94, Address: 0x102e9b0 */
  ((unsigned short*)actionwk)[25] = a1 - actwk; /* Line 95, Address: 0x102e9e4 */
  a1->actno = actionwk->actno; /* Line 96, Address: 0x102ea18 */
  a1->userflag.b.h = -1; /* Line 97, Address: 0x102ea28 */
  a1->sprhsize = 8; /* Line 98, Address: 0x102ea34 */
  a1->sprvsize = 8; /* Line 99, Address: 0x102ea40 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 101, Address: 0x102ea4c */
  {
    frameout(actionwk); /* Line 103, Address: 0x102ea64 */
    return; /* Line 104, Address: 0x102ea70 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 106, Address: 0x102ea78 */
  ((unsigned short*)actionwk)[26] = a1 - actwk; /* Line 107, Address: 0x102eaac */
  a1->actno = actionwk->actno; /* Line 108, Address: 0x102eae0 */
  a1->userflag.b.h = -1; /* Line 109, Address: 0x102eaf0 */
  a1->sprhsize = 8; /* Line 110, Address: 0x102eafc */
  a1->sprvsize = 8; /* Line 111, Address: 0x102eb08 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 113, Address: 0x102eb14 */
  {
    frameout(actionwk); /* Line 115, Address: 0x102eb2c */
    return; /* Line 116, Address: 0x102eb38 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 118, Address: 0x102eb40 */
  ((unsigned short*)actionwk)[27] = a1 - actwk; /* Line 119, Address: 0x102eb74 */
  a1->actno = actionwk->actno; /* Line 120, Address: 0x102eba8 */
  a1->userflag.b.h = -1; /* Line 121, Address: 0x102ebb8 */
  a1->sprhsize = 8; /* Line 122, Address: 0x102ebc4 */
  a1->sprvsize = 8; /* Line 123, Address: 0x102ebd0 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 125, Address: 0x102ebdc */
  {
    frameout(actionwk); /* Line 127, Address: 0x102ebf4 */
    return; /* Line 128, Address: 0x102ec00 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 130, Address: 0x102ec08 */
  ((unsigned short*)actionwk)[27] = a1 - actwk; /* Line 131, Address: 0x102ec3c */
  a1->actno = actionwk->actno; /* Line 132, Address: 0x102ec70 */
  a1->userflag.b.h = -1; /* Line 133, Address: 0x102ec80 */
  a1->sprhsize = 8; /* Line 134, Address: 0x102ec8c */
  a1->sprvsize = 8; /* Line 135, Address: 0x102ec98 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 137, Address: 0x102eca4 */
  {
    frameout(actionwk); /* Line 139, Address: 0x102ecbc */
    return; /* Line 140, Address: 0x102ecc8 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 142, Address: 0x102ecd0 */
  ((unsigned short*)actionwk)[28] = a1 - actwk; /* Line 143, Address: 0x102ed04 */
  a1->actno = actionwk->actno; /* Line 144, Address: 0x102ed38 */
  a1->userflag.b.h = -1; /* Line 145, Address: 0x102ed48 */
  a1->sprhsize = 8; /* Line 146, Address: 0x102ed54 */
  a1->sprvsize = 8; /* Line 147, Address: 0x102ed60 */

} /* Line 149, Address: 0x102ed6c */

static void act_move(sprite_status* actionwk) { /* Line 151, Address: 0x102ed80 */
  short d0;
  unsigned short sin, cos;
  int d0l, d1l, d2l, d3l, d4l, d5l;
  sprite_status* a1;

  d0 = ((short*)actionwk)[24]; /* Line 157, Address: 0x102edac */
  ((short*)actionwk)[23] += d0; /* Line 158, Address: 0x102edbc */
  d0 = ((short*)actionwk)[23]; /* Line 159, Address: 0x102edcc */
  d0 >>= 8; /* Line 160, Address: 0x102eddc */

  sinset(d0, (short*)&sin, (short*)&cos); /* Line 162, Address: 0x102ede8 */
  d0l = d1l = 0; /* Line 163, Address: 0x102edfc */
  d0l = sin << 16; /* Line 164, Address: 0x102ee04 */
  d1l = cos << 16; /* Line 165, Address: 0x102ee10 */
  d0l >>= 2; /* Line 166, Address: 0x102ee1c */
  d1l >>= 2; /* Line 167, Address: 0x102ee20 */
  d4l = d0l; /* Line 168, Address: 0x102ee24 */
  d5l = d1l; /* Line 169, Address: 0x102ee28 */
  d0l >>= 1; /* Line 170, Address: 0x102ee2c */
  d1l >>= 1; /* Line 171, Address: 0x102ee30 */
  d2l = d0l; /* Line 172, Address: 0x102ee34 */
  d3l = d1l; /* Line 173, Address: 0x102ee38 */
  d0l >>= 1; /* Line 174, Address: 0x102ee3c */
  d1l >>= 1; /* Line 175, Address: 0x102ee40 */
  a1 = &actwk[((unsigned short*)actionwk)[25]]; /* Line 176, Address: 0x102ee44 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d0l; /* Line 177, Address: 0x102ee68 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d1l; /* Line 178, Address: 0x102ee7c */
  a1 = &actwk[((unsigned short*)actionwk)[26]]; /* Line 179, Address: 0x102ee90 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d2l; /* Line 180, Address: 0x102eeb4 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d3l; /* Line 181, Address: 0x102eec8 */
  a1 = &actwk[((unsigned short*)actionwk)[27]]; /* Line 182, Address: 0x102eedc */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d0l + d2l; /* Line 183, Address: 0x102ef00 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d1l + d3l; /* Line 184, Address: 0x102ef18 */

  a1 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 186, Address: 0x102ef30 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d4l; /* Line 187, Address: 0x102ef54 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d5l; /* Line 188, Address: 0x102ef68 */
} /* Line 189, Address: 0x102ef7c */

void togeball_opt(sprite_status* actionwk) { /* Line 191, Address: 0x102efb0 */
  sprite_status* a1;

  switch (actionwk->r_no0) /* Line 194, Address: 0x102efc0 */
  {
    case 0:
      act_init2(actionwk); /* Line 197, Address: 0x102efe8 */
    case 2:
      act_move2(actionwk); /* Line 199, Address: 0x102eff4 */
      break;
  }
  a1 = &actwk[((unsigned short*)actionwk)[33]]; /* Line 202, Address: 0x102f000 */
  if (a1->actno != 45) /* Line 203, Address: 0x102f024 */
  {
    frameout(actionwk); /* Line 205, Address: 0x102f038 */
    return; /* Line 206, Address: 0x102f044 */
  }
  actionsub(actionwk); /* Line 208, Address: 0x102f04c */
} /* Line 209, Address: 0x102f058 */

void act_init2(sprite_status* actionwk) { /* Line 211, Address: 0x102f070 */
  actionwk->r_no0 += 2; /* Line 212, Address: 0x102f078 */
  actionwk->actflg |= 4; /* Line 213, Address: 0x102f088 */
  actionwk->sprpri = 1; /* Line 214, Address: 0x102f098 */
  actionwk->patbase = pat_togeball; /* Line 215, Address: 0x102f0a4 */
  actionwk->sproffset = 1016; /* Line 216, Address: 0x102f0b4 */
  actionwk->colino = 185; /* Line 217, Address: 0x102f0c0 */
} /* Line 218, Address: 0x102f0cc */

void act_move2(sprite_status* actionwk) { /* Line 220, Address: 0x102f0e0 */
  actionwk->xposi.w.h = ((short*)actionwk)[24]; /* Line 221, Address: 0x102f0e8 */
  actionwk->yposi.w.h = ((short*)actionwk)[26]; /* Line 222, Address: 0x102f0f8 */
} /* Line 223, Address: 0x102f108 */
