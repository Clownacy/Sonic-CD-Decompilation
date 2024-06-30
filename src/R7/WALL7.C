#include "..\EQU.H"
#include "WALL7.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

static sprite_pattern wall7_pat0 = {
  1,
  { { -16, -16, 0, 411 } }
};
static sprite_pattern wall7_pat1 = {
  1,
  { { -32, -16, 0, 412 } }
};
static sprite_pattern wall7_pat2 = {
  1,
  { { -48, -16, 0, 413 } }
};
static sprite_pattern wall7_pat3 = {
  1,
  { { -64, -16, 0, 414 } }
};
static sprite_pattern wall7_pat4 = {
  1,
  { { -16, -32, 0, 415 } }
};
static sprite_pattern wall7_pat5 = {
  1,
  { { -16, -48, 0, 416 } }
};
sprite_pattern* pat_wall7[6] = {
  &wall7_pat0,
  &wall7_pat1,
  &wall7_pat2,
  &wall7_pat3,
  &wall7_pat4,
  &wall7_pat5
};





























void wall7(sprite_status* pActwk) { /* Line 68, Address: 0x101f9e0¨*/
  unsigned char wall7_tbl0[12] = { /* Line 69, Address: 0x101f9ec¨*/
    12, 17,
    28, 17,
    44, 17,
    60, 17,
    12, 33,
    12, 49
  };

  if (!pActwk->r_no0) { /* Line 78, Address: 0x101fa20¨*/

    pActwk->r_no0 += 2; /* Line 80, Address: 0x101fa30¨*/
    pActwk->actflg |= 4; /* Line 81, Address: 0x101fa40¨*/
    pActwk->sprpri = 3; /* Line 82, Address: 0x101fa50¨*/
    pActwk->sproffset = 17270; /* Line 83, Address: 0x101fa5c¨*/
    pActwk->patbase = pat_wall7; /* Line 84, Address: 0x101fa68¨*/
    pActwk->patno = pActwk->userflag.b.h; /* Line 85, Address: 0x101fa78¨*/

    pActwk->sprhs = wall7_tbl0[pActwk->userflag.b.h * 2]; /* Line 87, Address: 0x101fa88¨*/
    pActwk->sprhsize = wall7_tbl0[pActwk->userflag.b.h * 2]; /* Line 88, Address: 0x101faac¨*/
    pActwk->sprvsize = wall7_tbl0[pActwk->userflag.b.h * 2 + 1]; /* Line 89, Address: 0x101fad0¨*/
  }

  hitchk(pActwk, &actwk[0]); /* Line 92, Address: 0x101faf8¨*/
  actionsub(pActwk); /* Line 93, Address: 0x101fb0c¨*/
  frameout_s(pActwk); /* Line 94, Address: 0x101fb18¨*/
} /* Line 95, Address: 0x101fb24¨*/
