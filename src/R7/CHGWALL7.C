#include "..\EQU.H"
#include "CHGWALL7.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

#if defined(R73C) || defined(R73D)
  #define SPRITE_CHGWALL7_BASE 452
#else
  #define SPRITE_CHGWALL7_BASE 403
#endif

sprite_pattern pat00;
sprite_pattern pat01 = {
  1,
  { { -32, -16, 0, SPRITE_CHGWALL7_BASE } }
};
sprite_pattern* pat_chgwall7[2] = {
  &pat00,
  &pat01
};












































void chgwall7(sprite_status* pActwk) { /* Line 66, Address: 0x101c9f0 */
  if (!pActwk->r_no0) { /* Line 67, Address: 0x101c9fc */

    pActwk->r_no0 += 2; /* Line 69, Address: 0x101ca0c */
    pActwk->actflg |= 4; /* Line 70, Address: 0x101ca1c */
    pActwk->sprhs = pActwk->sprhsize = 32; /* Line 71, Address: 0x101ca2c */
    pActwk->sprvsize = 17; /* Line 72, Address: 0x101ca44 */
    pActwk->patbase = pat_chgwall7; /* Line 73, Address: 0x101ca50 */
  }



  pActwk->patno = 0; /* Line 78, Address: 0x101ca60 */
  if (prio_flag) { /* Line 79, Address: 0x101ca68 */

    if (hitchk(pActwk, &actwk[0])) { /* Line 81, Address: 0x101ca78 */
      pActwk->actfree[0] = 1; /* Line 82, Address: 0x101ca94 */
    }
  } /* Line 84, Address: 0x101caa0 */
  else {
    if (pActwk->actfree[0]) { /* Line 86, Address: 0x101caa8 */
      pActwk->actfree[0] = 0; /* Line 87, Address: 0x101cab8 */
      ride_on_clr(pActwk, &actwk[0]); /* Line 88, Address: 0x101cac0 */
    }
  }


  actionsub(pActwk); /* Line 93, Address: 0x101cad4 */
  frameout_s(pActwk); /* Line 94, Address: 0x101cae0 */
} /* Line 95, Address: 0x101caec */
