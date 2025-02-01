#include "..\EQU.H"
#include "JETTOGE8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\PLAYSUB.H"

#if defined(R83)
  #define SPRITE_JETTOGE8_BASE 505
#else
  #define SPRITE_JETTOGE8_BASE 475
#endif

static char p00[4] = { 1, 0, 1, -1 };
static char* pchg[1] = { p00 };
static sprite_pattern pat00 =
{
  1,
  { { -16, -76, 0, SPRITE_JETTOGE8_BASE } }
};
static sprite_pattern pat01 =
{
  1,
  { { -16, -76, 0, SPRITE_JETTOGE8_BASE + 1 } }
};
sprite_pattern* pat_jettoge[2] =
{
  &pat00,
  &pat01
};




void jettoge(sprite_status* actionwk) { /* Line 34, Address: 0x1024800 */
  switch (actionwk->r_no0) /* Line 35, Address: 0x102480c */
  {
    case 0:
      a_init(actionwk); /* Line 38, Address: 0x1024834 */
    case 2:
      a_move(actionwk); /* Line 40, Address: 0x1024840 */
      break;
  }
} /* Line 43, Address: 0x102484c */

void a_init(sprite_status* actionwk) { /* Line 45, Address: 0x1024860 */
  actionwk->r_no0 += 2; /* Line 46, Address: 0x1024868 */
  actionwk->actflg |= 4; /* Line 47, Address: 0x1024878 */
  actionwk->patbase = pat_jettoge; /* Line 48, Address: 0x1024888 */
  actionwk->sproffset = 33856; /* Line 49, Address: 0x1024898 */
  ((short*)actionwk)[26] = actionwk->xposi.w.h; /* Line 50, Address: 0x10248a4 */
  actionwk->actfree[9] = 177; /* Line 51, Address: 0x10248b4 */
  ((int*)actionwk)[12] = 20480; /* Line 52, Address: 0x10248c0 */
  actionwk->sprvsize = 76; /* Line 53, Address: 0x10248cc */
  actionwk->sprpri = 1; /* Line 54, Address: 0x10248d8 */
  actionwk->sprhsize = 16; /* Line 55, Address: 0x10248e4 */
} /* Line 56, Address: 0x10248f0 */

void a_move(sprite_status* actionwk) { /* Line 58, Address: 0x1024900 */
  short t;

  actionwk->xposi.l += ((int*)actionwk)[12]; /* Line 61, Address: 0x1024910 */
  if (prio_flag == 0) /* Line 62, Address: 0x1024928 */
    actionwk->colino = actionwk->actfree[9]; /* Line 63, Address: 0x102493c */
  else
    actionwk->colino = 0; /* Line 65, Address: 0x1024954 */
  t = ((short*)actionwk)[23]--; /* Line 66, Address: 0x102495c */
  if (t <= 0) /* Line 67, Address: 0x1024974 */
  {
    ((short*)actionwk)[23] = 409; /* Line 69, Address: 0x1024984 */
    ((int*)actionwk)[12] = -((int*)actionwk)[12]; /* Line 70, Address: 0x1024990 */

    actionwk->actflg ^= 1; /* Line 72, Address: 0x10249a4 */
    actionwk->cddat ^= 1; /* Line 73, Address: 0x10249b4 */
  }
  patchg(actionwk, (unsigned char**)pchg); /* Line 75, Address: 0x10249c4 */
  actionsub(actionwk); /* Line 76, Address: 0x10249d8 */
  frameout_s00(actionwk, ((short*)actionwk)[26]); /* Line 77, Address: 0x10249e4 */

} /* Line 79, Address: 0x10249f8 */
