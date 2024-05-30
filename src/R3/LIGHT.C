#include "..\EQU.H"
#include "LIGHT.H"
#include "..\ACTION.H"

static void act_init(sprite_status* actionwk);

static sprite_pattern light_pat0 =
{
  1,
  { { -8, -8, 0, 570 } }
};
static sprite_pattern* light_pat[1] = { &light_pat0 };










void light(sprite_status* actionwk) { /* Line 23, Address: 0x102f540 */
  sprite_status* a1;

  switch (actionwk->r_no0) /* Line 26, Address: 0x102f550 */
  {
    case 0:
      act_init(actionwk); /* Line 29, Address: 0x102f584 */
    case 2:

      break; /* Line 32, Address: 0x102f590 */
    case 4:
      act_die(actionwk); /* Line 34, Address: 0x102f598 */
  }


  a1 = &actwk[((unsigned short*)actionwk)[29]]; /* Line 38, Address: 0x102f5a4 */
  if (a1->actno != 54) /* Line 39, Address: 0x102f5c8 */
  {
    frameout(actionwk); /* Line 41, Address: 0x102f5dc */
    return; /* Line 42, Address: 0x102f5e8 */
  }
  actionsub(actionwk); /* Line 44, Address: 0x102f5f0 */

} /* Line 46, Address: 0x102f5fc */

static void act_init(sprite_status* actionwk) { /* Line 48, Address: 0x102f610 */
  actionwk->r_no0 += 2; /* Line 49, Address: 0x102f618 */
  actionwk->actflg |= 4; /* Line 50, Address: 0x102f628 */
  actionwk->sprpri = 3; /* Line 51, Address: 0x102f638 */
  actionwk->sprhsize = 8; /* Line 52, Address: 0x102f644 */
  actionwk->sprvsize = 8; /* Line 53, Address: 0x102f650 */
  actionwk->sproffset = 25662; /* Line 54, Address: 0x102f65c */
  actionwk->patbase = light_pat; /* Line 55, Address: 0x102f668 */
} /* Line 56, Address: 0x102f678 */

void act_die(sprite_status* actionwk) { /* Line 58, Address: 0x102f690 */
  frameout(actionwk); /* Line 59, Address: 0x102f69c */
} /* Line 60, Address: 0x102f6a8 */
