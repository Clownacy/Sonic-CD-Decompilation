#include "..\EQU.H"
#include "OSUMIZU.H"

sprite_pattern osumizu_pat0 = {
  1,
  { { -8, -16, 0, 471 } }
};
sprite_pattern osumizu_pat1 = {
  1,
  { { -16, -8, 0, 472 } }
};
sprite_pattern osumizu_pat2 = {
  1,
  { { -16, -8, 0, 473 } }
};
sprite_pattern osumizu_pat3 = {
  1,
  { { -16, -8, 0, 474 } }
};
sprite_pattern osumizu_pat4 = {
  1,
  { { -16, -8, 0, 475 } }
};
sprite_pattern* pat_osumizu[1] = { &osumizu_pat0 };
sprite_pattern* pat_osumizu1[4] = {
  &osumizu_pat1,
  &osumizu_pat2,
  &osumizu_pat3,
  &osumizu_pat4
};
unsigned char osumizu_chg0[6] = { 9, 0, 1, 2, 3, 255 };
unsigned char* osumizu_chg[1] = { osumizu_chg0 };


























































void osumizu(sprite_status* pActwk) { /* Line 91, Address: 0x102c980 */
  sprite_status* pNewactwk;

  if (!(pActwk->userflag.b.h & 128)) { /* Line 94, Address: 0x102c98c */

    if (!pActwk->r_no0) { /* Line 96, Address: 0x102c9a8 */

      pActwk->r_no0 += 2; /* Line 98, Address: 0x102c9b8 */

      pActwk->actflg |= 4; /* Line 100, Address: 0x102c9c8 */
      pActwk->sprpri = 3; /* Line 101, Address: 0x102c9d8 */
      pActwk->sprhsize = 8; /* Line 102, Address: 0x102c9e4 */
      pActwk->sprvsize = 16; /* Line 103, Address: 0x102c9f0 */
      pActwk->sproffset = 17176; /* Line 104, Address: 0x102c9fc */
      pActwk->patbase = pat_osumizu; /* Line 105, Address: 0x102ca08 */

      if (pActwk->userflag.b.h) { /* Line 107, Address: 0x102ca18 */
        pActwk->actflg |= 1; /* Line 108, Address: 0x102ca28 */
        pActwk->cddat |= 1; /* Line 109, Address: 0x102ca38 */

        ((int*)pActwk)[12] = 196608; /* Line 111, Address: 0x102ca48 */
        ((short*)pActwk)[26] = -32; /* Line 112, Address: 0x102ca54 */
      } /* Line 113, Address: 0x102ca60 */
      else {
        ((int*)pActwk)[12] = -196608; /* Line 115, Address: 0x102ca68 */
        ((short*)pActwk)[26] = 32; /* Line 116, Address: 0x102ca74 */
      }
      ((short*)pActwk)[26] += pActwk->xposi.w.h; /* Line 118, Address: 0x102ca80 */
    }

    if (--((short*)pActwk)[23] < 0) { /* Line 121, Address: 0x102ca98 */
      ((short*)pActwk)[23] = 30; /* Line 122, Address: 0x102cac0 */

      if (actwkchk(&pNewactwk) == 0) { /* Line 124, Address: 0x102cacc */

        pNewactwk->actno = pActwk->actno; /* Line 126, Address: 0x102cae0 */
        pNewactwk->userflag.b.h = -1; /* Line 127, Address: 0x102caf0 */
        pNewactwk->xposi.w.h = ((short*)pActwk)[26]; /* Line 128, Address: 0x102cafc */
        pNewactwk->yposi.w.h = pActwk->yposi.w.h + 4; /* Line 129, Address: 0x102cb0c */
        ((int*)pNewactwk)[12] = ((int*)pActwk)[12]; /* Line 130, Address: 0x102cb30 */
        pNewactwk->actflg = pActwk->actflg; /* Line 131, Address: 0x102cb40 */
        pNewactwk->sprpri = pActwk->sprpri + 1; /* Line 132, Address: 0x102cb50 */
        pNewactwk->sprhsize = 32; /* Line 133, Address: 0x102cb6c */
        pNewactwk->sprvsize = 6; /* Line 134, Address: 0x102cb78 */
        pNewactwk->sproffset = 792; /* Line 135, Address: 0x102cb84 */
        pNewactwk->patbase = pat_osumizu1; /* Line 136, Address: 0x102cb90 */
        pNewactwk->cddat = pActwk->cddat; /* Line 137, Address: 0x102cba0 */
      }
    }
    actionsub(pActwk); /* Line 140, Address: 0x102cbb0 */
    frameout_s(pActwk); /* Line 141, Address: 0x102cbbc */
  } /* Line 142, Address: 0x102cbc8 */
  else {


    if ((unsigned short)(actwk[0].yposi.w.h - pActwk->yposi.w.h + 12) < 24) { /* Line 146, Address: 0x102cbd0 */
      if ((unsigned short)(actwk[0].xposi.w.h - pActwk->xposi.w.h + 20) < 40) { /* Line 147, Address: 0x102cc0c */
        actwk[0].mspeed.w = ((int*)pActwk)[12] >> 8; /* Line 148, Address: 0x102cc48 */
      }
    }
    pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 151, Address: 0x102cc64 */

    patchg(pActwk, osumizu_chg); /* Line 153, Address: 0x102cc7c */
    actionsub(pActwk); /* Line 154, Address: 0x102cc90 */
    frameout_s(pActwk); /* Line 155, Address: 0x102cc9c */
  }
} /* Line 157, Address: 0x102cca8 */
