#include "..\EQU.H"
#include "GATE.H"

static sprite_pattern pat00 = { 1, { { 48, -16, 0, 619 } } };
static sprite_pattern pat01 = { 1, { { 32, -16, 0, 620 } } };
static sprite_pattern pat02 = { 1, { { 16, -16, 0, 621 } } };
static sprite_pattern pat03 = { 1, { { 0, -16, 0, 622 } } };
static sprite_pattern pat04 = { 1, { { -16, -16, 0, 623 } } };
static sprite_pattern pat05 = { 1, { { -32, -16, 0, 624 } } };
static sprite_pattern pat06 = { 1, { { -48, -16, 0, 625 } } };
static sprite_pattern pat07 = { 1, { { -64, -16, 0, 626 } } };
sprite_pattern* gate_pat[8] = {
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05,
  &pat06,
  &pat07
};
static char pchg0[10] = { 0, 0, 1, 2, 3, 4, 5, 6, 7, 7 };
static char* pchg[1] = { pchg0 };




















void gate(sprite_status* actionwk) { /* Line 44, Address: 0x102e550 */
  if (actionwk->r_no0 == 4) { /* Line 45, Address: 0x102e55c */

    act_move(actionwk); /* Line 47, Address: 0x102e574 */
  }

  switch (actionwk->r_no0) /* Line 50, Address: 0x102e580 */
  {
    case 0:
      act_init(actionwk); /* Line 53, Address: 0x102e5c0 */
      break; /* Line 54, Address: 0x102e5cc */
    case 2:
      act_open(actionwk); /* Line 56, Address: 0x102e5d4 */
    case 4:
      act_move(actionwk); /* Line 58, Address: 0x102e5e0 */
      break; /* Line 59, Address: 0x102e5ec */
    case 6:
      act_init(actionwk); /* Line 61, Address: 0x102e5f4 */
      break;
  }
} /* Line 64, Address: 0x102e600 */

void act_init6(sprite_status* actionwk) { /* Line 66, Address: 0x102e610 */
  actionwk->actfree[0] = 5; /* Line 67, Address: 0x102e61c */
  actionwk->r_no0 = 0; /* Line 68, Address: 0x102e628 */
  act_init10(actionwk); /* Line 69, Address: 0x102e630 */
} /* Line 70, Address: 0x102e63c */

static void act_init(sprite_status* actionwk) { /* Line 72, Address: 0x102e650 */
  actionwk->actfree[0] = 7; /* Line 73, Address: 0x102e65c */
  act_init10(actionwk); /* Line 74, Address: 0x102e668 */
} /* Line 75, Address: 0x102e674 */

void act_init10(sprite_status* actionwk) { /* Line 77, Address: 0x102e690 */
  actionwk->r_no0 += 2; /* Line 78, Address: 0x102e69c */
  actionwk->actflg |= 4; /* Line 79, Address: 0x102e6ac */
  actionwk->sprpri = 3; /* Line 80, Address: 0x102e6bc */
  actionwk->sproffset = 1140; /* Line 81, Address: 0x102e6c8 */
  actionwk->patbase = gate_pat; /* Line 82, Address: 0x102e6d4 */
  actionwk->sprhsize = 72; /* Line 83, Address: 0x102e6e4 */
  actionwk->sprvsize = 16; /* Line 84, Address: 0x102e6f0 */
  act_open(actionwk); /* Line 85, Address: 0x102e6fc */
} /* Line 86, Address: 0x102e708 */

static void act_open(sprite_status* actionwk) { /* Line 88, Address: 0x102e720 */
  patchg(actionwk, pchg); /* Line 89, Address: 0x102e72c */
  if (actionwk->patno == actionwk->actfree[0]) /* Line 90, Address: 0x102e740 */
  {
    actionwk->r_no0 += 2; /* Line 92, Address: 0x102e760 */
  }
} /* Line 94, Address: 0x102e770 */

static void act_move(sprite_status* actionwk) { /* Line 96, Address: 0x102e780 */
  if ((char)actionwk->actflg < 0) /* Line 97, Address: 0x102e78c */
    ridechk(actionwk, &actwk[0]); /* Line 98, Address: 0x102e7ac */
  actionsub(actionwk); /* Line 99, Address: 0x102e7c0 */
} /* Line 100, Address: 0x102e7cc */
