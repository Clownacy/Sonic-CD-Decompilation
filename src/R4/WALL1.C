#include "..\EQU.H"
#include "WALL1.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

static void act_init(sprite_status* pActwk);
static void act_move(sprite_status* pActwk);

static sprite_pattern pat00 = {
  1,
  { { -16, -16, 0, 450 } }
};
static sprite_pattern pat01 = {
  1,
  { { -16, -16, 0, 451 } }
};
static sprite_pattern pat02 = {
  1,
  { { -32, -16, 0, 452 } }
};
static sprite_pattern pat03 = {
  1,
  { { -16, -32, 0, 453 } }
};
static sprite_pattern pat04 = {
  1,
  { { -32, -32, 0, 454 } }
};
static sprite_pattern pat05 = {
  1,
  { { -64, -16, 0, 455 } }
};
static sprite_pattern pat06 = {
  1,
  { { -16, -64, 0, 456 } }
};
sprite_pattern* pat_wall1[7] = {
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05,
  &pat06
};
static unsigned char tbl0[14] = {
  16, 16,
  16, 16,
  32, 16,
  16, 32,
  32, 32,
  64, 16,
  16, 64
};


















































void wall1(sprite_status* pActwk) { /* Line 105, Address: 0x101e0e0 */
  if (pActwk->r_no0) { /* Line 106, Address: 0x101e0ec */
    act_move(pActwk); /* Line 107, Address: 0x101e0fc */
  } else { /* Line 108, Address: 0x101e108 */
    act_init(pActwk); /* Line 109, Address: 0x101e110 */
  }
} /* Line 111, Address: 0x101e11c */





static void act_init(sprite_status* pActwk) { /* Line 117, Address: 0x101e130 */
  pActwk->r_no0 += 2; /* Line 118, Address: 0x101e13c */
  pActwk->actflg |= 4; /* Line 119, Address: 0x101e14c */
  pActwk->sprpri = 1; /* Line 120, Address: 0x101e15c */
  pActwk->sproffset = 17514; /* Line 121, Address: 0x101e168 */
  pActwk->patbase = pat_wall1; /* Line 122, Address: 0x101e174 */
  pActwk->patno = pActwk->userflag.b.h; /* Line 123, Address: 0x101e184 */
  pActwk->sprhs = pActwk->sprhsize = tbl0[pActwk->userflag.b.h * 2]; /* Line 124, Address: 0x101e194 */
  pActwk->sprvsize = tbl0[pActwk->userflag.b.h * 2 + 1]; /* Line 125, Address: 0x101e1c8 */

  act_move(pActwk); /* Line 127, Address: 0x101e1f8 */
} /* Line 128, Address: 0x101e204 */





static void act_move(sprite_status* pActwk) { /* Line 134, Address: 0x101e220 */
  hitchk(pActwk, &actwk[0]); /* Line 135, Address: 0x101e22c */
  actionsub(pActwk); /* Line 136, Address: 0x101e240 */
  frameout_s(pActwk); /* Line 137, Address: 0x101e24c */
} /* Line 138, Address: 0x101e258 */
