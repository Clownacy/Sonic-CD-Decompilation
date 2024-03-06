#include "..\EQU.H"
#include "TEKKYU1.H"

static sprite_pattern pat0 = {
  1,
  { { -16, -16, 0, 532 } }
};
static sprite_pattern* pat_tekkyu1[1] = { &pat0 };































void tekkyu1(sprite_status* pActwk) { /* Line 40, Address: 0x102b500 */
  if (pActwk->r_no0 == 0) { /* Line 41, Address: 0x102b50c */

    pActwk->r_no0 += 2; /* Line 43, Address: 0x102b520 */
    pActwk->actflg |= 4; /* Line 44, Address: 0x102b530 */
    pActwk->sprpri = 3; /* Line 45, Address: 0x102b540 */
    pActwk->colino = 169; /* Line 46, Address: 0x102b54c */
    pActwk->sprhs = 16; /* Line 47, Address: 0x102b558 */
    pActwk->sprhsize = 16; /* Line 48, Address: 0x102b564 */
    pActwk->sprvsize = 16; /* Line 49, Address: 0x102b570 */
    pActwk->sproffset = 880; /* Line 50, Address: 0x102b57c */
    pActwk->patbase = pat_tekkyu1; /* Line 51, Address: 0x102b588 */
  }
  actionsub(pActwk); /* Line 53, Address: 0x102b598 */
  frameout_s(pActwk); /* Line 54, Address: 0x102b5a4 */
} /* Line 55, Address: 0x102b5b0 */
