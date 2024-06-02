#include "..\EQU.H"
#include "SCREW_A.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "PLAYSUB4.H"

static unsigned char pchg_00[7] = { 1, 0, 1, 2, 3, 4, 255 };
static unsigned char* pchg[1] = { pchg_00 };
static sprite_pattern screw0_pat00 = {
  1,
  { { -16, -8, 0, 457 } }
};
static sprite_pattern screw0_pat01 = {
  1,
  { { -12, -8, 0, 458 } }
};
static sprite_pattern screw0_pat02 = {
  1,
  { { -8, -8, 0, 459 } }
};
static sprite_pattern screw0_pat03 = {
  1,
  { { -12, -8, 0, 460 } }
};
static sprite_pattern screw0_pat04 = {
  1,
  { { -16, -8, 0, 461 } }
};
sprite_pattern* pat_screw0[5] = {
  &screw0_pat00,
  &screw0_pat01,
  &screw0_pat02,
  &screw0_pat03,
  &screw0_pat04
};
static sprite_pattern screw1_pat00 = {
  1,
  { { -8, -16, 0, 462 } }
};
static sprite_pattern screw1_pat01 = {
  1,
  { { -8, -12, 0, 463 } }
};
static sprite_pattern screw1_pat02 = {
  1,
  { { -8, -8, 0, 464 } }
};
static sprite_pattern screw1_pat03 = {
  1,
  { { -8, -12, 0, 465 } }
};
static sprite_pattern screw1_pat04 = {
  1,
  { { -8, -16, 0, 466 } }
};
sprite_pattern* pat_screw1[5] = {
  &screw1_pat00,
  &screw1_pat01,
  &screw1_pat02,
  &screw1_pat03,
  &screw1_pat04
};





























































void screw(sprite_status* pActwk) { /* Line 124, Address: 0x101e270 */
  if (!pActwk->r_no0) { /* Line 125, Address: 0x101e27c */

    pActwk->r_no0 += 2; /* Line 127, Address: 0x101e28c */
    pActwk->actflg |= 4; /* Line 128, Address: 0x101e29c */
    pActwk->sprpri = 3; /* Line 129, Address: 0x101e2ac */
    pActwk->sproffset = 17280; /* Line 130, Address: 0x101e2b8 */

    if (pActwk->userflag.b.h & 128) { /* Line 132, Address: 0x101e2c4 */
      pActwk->actfree[21] = 255; /* Line 133, Address: 0x101e2e0 */
    }


    if (!(pActwk->userflag.b.h & 2)) { /* Line 137, Address: 0x101e2ec */
      pActwk->patbase = pat_screw0; /* Line 138, Address: 0x101e308 */
      pActwk->sprhsize = 16; /* Line 139, Address: 0x101e318 */
      pActwk->sprvsize = 8; /* Line 140, Address: 0x101e324 */
    } else { /* Line 141, Address: 0x101e330 */
      pActwk->patbase = pat_screw1; /* Line 142, Address: 0x101e338 */
      pActwk->sprhsize = 8; /* Line 143, Address: 0x101e348 */
      pActwk->sprvsize = 16; /* Line 144, Address: 0x101e354 */
    }

    if (pActwk->userflag.b.h & 1) { /* Line 147, Address: 0x101e360 */
      pActwk->actflg |= 3; /* Line 148, Address: 0x101e37c */
      pActwk->cddat |= 3; /* Line 149, Address: 0x101e38c */
    }
  }


  if (!(pActwk->userflag.b.l & 128) && !pActwk->actfree[20] && switchflag[pActwk->userflag.b.l]) { /* Line 154, Address: 0x101e39c */

    pActwk->actfree[20] = 1; /* Line 156, Address: 0x101e3f0 */
    pActwk->actfree[21] = ~pActwk->actfree[21]; /* Line 157, Address: 0x101e3fc */
  }


  if (!pActwk->actfree[21]) { /* Line 161, Address: 0x101e418 */
    pActwk->patno = 0; /* Line 162, Address: 0x101e428 */
  } /* Line 163, Address: 0x101e430 */
  else {
    patchg(pActwk, pchg); /* Line 165, Address: 0x101e438 */
  }
  actionsub(pActwk); /* Line 167, Address: 0x101e44c */
  frameout_s(pActwk); /* Line 168, Address: 0x101e458 */
} /* Line 169, Address: 0x101e464 */
