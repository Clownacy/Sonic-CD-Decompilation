#include "..\EQU.H"
#include "SCREW_A.H"

sprite_pattern pat_screw00 = {
  1,
  { { -16, -8, 0, 441 } }
};
sprite_pattern pat_screw01 = {
  1,
  { { -16, -8, 0, 442 } }
};
sprite_pattern pat_screw02 = {
  1,
  { { -8, -16, 0, 443 } }
};
sprite_pattern pat_screw03 = {
  1,
  { { -8, -16, 0, 444 } }
};
sprite_pattern* pat_screw0[2] = {
  &pat_screw00,
  &pat_screw01
};
sprite_pattern* pat_screw1[2] = {
  &pat_screw02,
  &pat_screw03
};





















































void screw(sprite_status* pActwk) { /* Line 81, Address: 0x102b2b0 */
  sprite_status* pCallactwk;

  if (!pActwk->r_no0) { /* Line 84, Address: 0x102b2c0 */

    pCallactwk = &actwk[((short*)pActwk)[23]]; /* Line 86, Address: 0x102b2d0 */
    pActwk->actfree[2] = pCallactwk->actno; /* Line 87, Address: 0x102b2f8 */
    pActwk->r_no0 += 2; /* Line 88, Address: 0x102b304 */
    pActwk->actflg |= 4; /* Line 89, Address: 0x102b314 */
    pActwk->sprpri = 3; /* Line 90, Address: 0x102b324 */
    pActwk->sproffset = 17280; /* Line 91, Address: 0x102b330 */

    if (pActwk->userflag.b.h & 128) /* Line 93, Address: 0x102b33c */
      ++pActwk->patno; /* Line 94, Address: 0x102b358 */
    if (pActwk->userflag.b.h & 2) { /* Line 95, Address: 0x102b368 */
      pActwk->sprhsize = 8; /* Line 96, Address: 0x102b384 */
      pActwk->sprvsize = 16; /* Line 97, Address: 0x102b390 */
      pActwk->patbase = pat_screw1; /* Line 98, Address: 0x102b39c */
    } else { /* Line 99, Address: 0x102b3ac */
      pActwk->sprhsize = 16; /* Line 100, Address: 0x102b3b4 */
      pActwk->sprvsize = 8; /* Line 101, Address: 0x102b3c0 */
      pActwk->patbase = pat_screw0; /* Line 102, Address: 0x102b3cc */
    }
    if (pActwk->userflag.b.h & 1) { /* Line 104, Address: 0x102b3dc */
      pActwk->actflg |= 3; /* Line 105, Address: 0x102b3f8 */
      pActwk->cddat |= 3; /* Line 106, Address: 0x102b408 */
    }
  }

  pCallactwk = &actwk[((short*)pActwk)[23]]; /* Line 110, Address: 0x102b418 */

  if (pActwk->actfree[2] == pCallactwk->actno) { /* Line 112, Address: 0x102b440 */
    if (!(pActwk->userflag.b.l & 128)) { /* Line 113, Address: 0x102b45c */
      if (!pActwk->actfree[20]) { /* Line 114, Address: 0x102b478 */
        if (switchflag[pActwk->userflag.b.l]) { /* Line 115, Address: 0x102b488 */
          pActwk->actfree[20] = 255; /* Line 116, Address: 0x102b4b0 */
          pActwk->patno ^= 1; /* Line 117, Address: 0x102b4bc */
        }
      }
    }

    actionsub(pActwk); /* Line 122, Address: 0x102b4cc */
    return; /* Line 123, Address: 0x102b4d8 */
  }

  frameout(pActwk); /* Line 126, Address: 0x102b4e0 */
} /* Line 127, Address: 0x102b4ec */
