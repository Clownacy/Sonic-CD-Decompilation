#include "..\EQU.H"
#include "BOBINB.H"
#include "..\ACTION.H"
#include "..\PLAYSUB.H"
#include "..\SCORE.H"

static void a_init(sprite_status* bobinwk);
static void a_move(sprite_status* bobinwk);
static void a_die(sprite_status* bobinwk);

static unsigned char pat00[7] = { 2, 0, 0, 0, 1, 1, 252 };
static unsigned char* pchg[1] = { pat00 };
static sprite_pattern bbb00 = {
  1,
  { { -16, -16, 0, 313 } }
};
static sprite_pattern bbb01 = {
  1,
  { { -16, -16, 0, 314 } }
};
sprite_pattern* pat_bobinbreak[2] = {
  &bbb00,
  &bbb01
};





void bobinbreak(sprite_status* bobinwk) { /* Line 30, Address: 0x101b370 */
  void(*tbl[3])(sprite_status*) = { &a_init, &a_move, &a_die }; /* Line 31, Address: 0x101b37c */

  tbl[bobinwk->r_no0 / 2](bobinwk); /* Line 33, Address: 0x101b3a0 */
  actionsub(bobinwk); /* Line 34, Address: 0x101b3dc */
} /* Line 35, Address: 0x101b3e8 */



static void a_init(sprite_status* bobinwk) { /* Line 39, Address: 0x101b400 */
  bobinwk->r_no0 += 2; /* Line 40, Address: 0x101b40c */
  bobinwk->actflg |= 4; /* Line 41, Address: 0x101b41c */
  bobinwk->sprpri = 3; /* Line 42, Address: 0x101b42c */
  bobinwk->sprhs = 16; /* Line 43, Address: 0x101b438 */
  bobinwk->sprhsize = 16; /* Line 44, Address: 0x101b444 */
  bobinwk->sprvsize = 16; /* Line 45, Address: 0x101b450 */

  bobinwk->patbase = pat_bobinbreak; /* Line 47, Address: 0x101b45c */

  scoreup(10); /* Line 49, Address: 0x101b46c */
  tensuu0(bobinwk,0); /* Line 50, Address: 0x101b478 */
} /* Line 51, Address: 0x101b488 */



static void a_move(sprite_status* bobinwk) { /* Line 55, Address: 0x101b4a0 */
  patchg(bobinwk, pchg); /* Line 56, Address: 0x101b4ac */
} /* Line 57, Address: 0x101b4c0 */



static void a_die(sprite_status* bobinwk) { /* Line 61, Address: 0x101b4d0 */
  frameout(bobinwk); /* Line 62, Address: 0x101b4dc */
} /* Line 63, Address: 0x101b4e8 */
