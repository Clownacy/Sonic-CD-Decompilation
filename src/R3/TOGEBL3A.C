#include "..\EQU.H"
#include "TOGEBL3A.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"

#if defined (R32A)
  #define SPRITE_TOGEBL3A_BASE 550
#else
  #define SPRITE_TOGEBL3A_BASE 556
#endif

static sprite_pattern spat_chg0 = {
  1,
  { { -8, -8, 0, SPRITE_TOGEBL3A_BASE } }
};
static sprite_pattern spat_chg1 = {
  1,
  { { -8, -8, 0, SPRITE_TOGEBL3A_BASE + 1 } }
};
sprite_pattern* pat_chg[1] = { &spat_chg0 };
sprite_pattern* togeball_pat[1] = { &spat_chg1 };





























void togeball(sprite_status* actionwk) { /* Line 52, Address: 0x1020080 */
  if (actionwk->userflag.b.h >= 0) /* Line 53, Address: 0x102008c */
    togeball_main(actionwk); /* Line 54, Address: 0x10200a4 */
  else
    togeball_opt(actionwk); /* Line 56, Address: 0x10200b8 */
} /* Line 57, Address: 0x10200c4 */

void togeball_main(sprite_status* actionwk) { /* Line 59, Address: 0x10200e0 */
  switch (actionwk->r_no0) { /* Line 60, Address: 0x10200ec */

    case 0:
      act_init(actionwk); /* Line 63, Address: 0x1020114 */
      break; /* Line 64, Address: 0x1020120 */
    case 2:
      act_move(actionwk); /* Line 66, Address: 0x1020128 */
      break;
  }
  actionsub(actionwk); /* Line 69, Address: 0x1020134 */
  frameout_s(actionwk); /* Line 70, Address: 0x1020140 */
} /* Line 71, Address: 0x102014c */

void act_init(sprite_status* actionwk) { /* Line 73, Address: 0x1020160 */
  sprite_status* a1;

  actionwk->r_no0 += 2; /* Line 76, Address: 0x102016c */
  actionwk->actflg |= 4; /* Line 77, Address: 0x102017c */
  actionwk->sprpri = 1; /* Line 78, Address: 0x102018c */
  actionwk->sprhsize = 8; /* Line 79, Address: 0x1020198 */
  actionwk->sprvsize = 8; /* Line 80, Address: 0x10201a4 */
  actionwk->patbase = pat_chg; /* Line 81, Address: 0x10201b0 */
  actionwk->sproffset = 957; /* Line 82, Address: 0x10201c0 */
  ((short*)actionwk)[24] = 256; /* Line 83, Address: 0x10201cc */
  if (actionwk->userflag.b.h != 0) /* Line 84, Address: 0x10201d8 */
    ((short*)actionwk)[24] = -((short*)actionwk)[24]; /* Line 85, Address: 0x10201f0 */


  if (actwkchk2(actionwk, &a1) != 0) { /* Line 88, Address: 0x1020214 */

    frameout(actionwk); /* Line 90, Address: 0x102022c */
    return; /* Line 91, Address: 0x1020238 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 93, Address: 0x1020240 */
  ((unsigned short*)actionwk)[25] = a1 - actwk; /* Line 94, Address: 0x1020274 */
  a1->actno = actionwk->actno; /* Line 95, Address: 0x10202a8 */
  a1->userflag.b.h = -1; /* Line 96, Address: 0x10202b8 */
  a1->sprhsize = 8; /* Line 97, Address: 0x10202c4 */
  a1->sprvsize = 8; /* Line 98, Address: 0x10202d0 */

  if (actwkchk2(actionwk, &a1) != 0) { /* Line 100, Address: 0x10202dc */

    frameout(actionwk); /* Line 102, Address: 0x10202f4 */
    return; /* Line 103, Address: 0x1020300 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 105, Address: 0x1020308 */
  ((unsigned short*)actionwk)[26] = a1 - actwk; /* Line 106, Address: 0x102033c */
  a1->actno = actionwk->actno; /* Line 107, Address: 0x1020370 */
  a1->userflag.b.h = -1; /* Line 108, Address: 0x1020380 */
  a1->sprhsize = 8; /* Line 109, Address: 0x102038c */
  a1->sprvsize = 8; /* Line 110, Address: 0x1020398 */

  if (actwkchk2(actionwk, &a1) != 0) { /* Line 112, Address: 0x10203a4 */

    frameout(actionwk); /* Line 114, Address: 0x10203bc */
    return; /* Line 115, Address: 0x10203c8 */
  }
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 117, Address: 0x10203d0 */
  ((unsigned short*)actionwk)[27] = a1 - actwk; /* Line 118, Address: 0x1020404 */
  a1->actno = actionwk->actno; /* Line 119, Address: 0x1020438 */
  a1->userflag.b.h = -1; /* Line 120, Address: 0x1020448 */
  a1->sprhsize = 8; /* Line 121, Address: 0x1020454 */
  a1->sprvsize = 8; /* Line 122, Address: 0x1020460 */
} /* Line 123, Address: 0x102046c */

void act_move(sprite_status* actionwk) { /* Line 125, Address: 0x1020480 */
  short d0;
  unsigned short sin, cos;
  int d0l, d1l, d2l, d3l, d4l, d5l;
  sprite_status* a1;

  d0 = ((short*)actionwk)[24]; /* Line 131, Address: 0x10204ac */
  ((short*)actionwk)[23] += d0; /* Line 132, Address: 0x10204bc */
  d0 = ((short*)actionwk)[23]; /* Line 133, Address: 0x10204cc */
  d0 >>= 8; /* Line 134, Address: 0x10204dc */

  sinset(d0, (short*)&sin, (short*)&cos); /* Line 136, Address: 0x10204e8 */
  d0l = d1l = 0; /* Line 137, Address: 0x10204fc */
  d0l = sin << 16; /* Line 138, Address: 0x1020504 */
  d1l = cos << 16; /* Line 139, Address: 0x1020510 */
  d0l >>= 2; /* Line 140, Address: 0x102051c */
  d1l >>= 2; /* Line 141, Address: 0x1020520 */
  d4l = d0l; /* Line 142, Address: 0x1020524 */
  d5l = d1l; /* Line 143, Address: 0x1020528 */
  d0l >>= 1; /* Line 144, Address: 0x102052c */
  d1l >>= 1; /* Line 145, Address: 0x1020530 */
  d2l = d0l; /* Line 146, Address: 0x1020534 */
  d3l = d1l; /* Line 147, Address: 0x1020538 */
  d0l >>= 1; /* Line 148, Address: 0x102053c */
  d1l >>= 1; /* Line 149, Address: 0x1020540 */
  a1 = &actwk[((unsigned short*)actionwk)[25]]; /* Line 150, Address: 0x1020544 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d0l; /* Line 151, Address: 0x1020568 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d1l; /* Line 152, Address: 0x102057c */
  a1 = &actwk[((unsigned short*)actionwk)[26]]; /* Line 153, Address: 0x1020590 */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d2l; /* Line 154, Address: 0x10205b4 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d3l; /* Line 155, Address: 0x10205c8 */
  a1 = &actwk[((unsigned short*)actionwk)[27]]; /* Line 156, Address: 0x10205dc */
  *(int*)&a1->actfree[4] = actionwk->yposi.l + d0l + d2l; /* Line 157, Address: 0x1020600 */
  *(int*)&a1->actfree[0] = actionwk->xposi.l + d1l + d3l; /* Line 158, Address: 0x1020618 */
} /* Line 159, Address: 0x1020630 */

void togeball_opt(sprite_status* actionwk) { /* Line 161, Address: 0x1020660 */
  sprite_status* a1;

  switch (actionwk->r_no0) { /* Line 164, Address: 0x1020670 */

    case 0:
      act_init2(actionwk); /* Line 167, Address: 0x1020698 */
    case 2:
      act_move2(actionwk); /* Line 169, Address: 0x10206a4 */
      break;
  }
  a1 = &actwk[((unsigned short*)actionwk)[33]]; /* Line 172, Address: 0x10206b0 */
  if (a1->actno != 44) { /* Line 173, Address: 0x10206d4 */

    frameout(actionwk); /* Line 175, Address: 0x10206e8 */
    return; /* Line 176, Address: 0x10206f4 */
  }
  actionsub(actionwk); /* Line 178, Address: 0x10206fc */
} /* Line 179, Address: 0x1020708 */

void act_init2(sprite_status* actionwk) { /* Line 181, Address: 0x1020720 */
  actionwk->r_no0 += 2; /* Line 182, Address: 0x1020728 */
  actionwk->actflg |= 4; /* Line 183, Address: 0x1020738 */
  actionwk->sprpri = 1; /* Line 184, Address: 0x1020748 */
  actionwk->patbase = togeball_pat; /* Line 185, Address: 0x1020754 */
  actionwk->sproffset = 957; /* Line 186, Address: 0x1020764 */
  actionwk->colino = 139; /* Line 187, Address: 0x1020770 */
} /* Line 188, Address: 0x102077c */

void act_move2(sprite_status* actionwk) { /* Line 190, Address: 0x1020790 */
  actionwk->xposi.w.h = ((short*)actionwk)[24]; /* Line 191, Address: 0x1020798 */
  actionwk->yposi.w.h = ((short*)actionwk)[26]; /* Line 192, Address: 0x10207a8 */
} /* Line 193, Address: 0x10207b8 */
