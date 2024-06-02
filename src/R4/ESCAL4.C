#include "..\EQU.H"
#include "ESCAL4.H"
#include "..\ACTION.H"
#include "..\RIDECHK.H"

sprite_pattern escal4_pat0 = {
  1,
  { { -16, -16, 0, 429 } }
};
sprite_pattern escal4_pat1 = {
  1,
  { { -16, -16, 0, 430 } }
};
sprite_pattern* escal4pat[2] = {
  &escal4_pat0,
  &escal4_pat1
};






















































void escal4(sprite_status* pActwk) { /* Line 72, Address: 0x1021c90 */
  void(*escal4_acttbl[3])(sprite_status*) = { /* Line 73, Address: 0x1021c9c */
    &escal4_init,
    &escal4_wait,
    &escal4_moveup
  };

  escal4_acttbl[pActwk->r_no0 / 2](pActwk); /* Line 79, Address: 0x1021cc0 */
  actionsub(pActwk); /* Line 80, Address: 0x1021cfc */

  if ((pActwk->xposi.w.h & 65408) - ((scra_h_posit.w.h - 128) & 65408) <= 640) return; /* Line 82, Address: 0x1021d08 */



  if (pActwk->cdsts) flagwork[time_flag + pActwk->cdsts * 3] &= 127; /* Line 86, Address: 0x1021d44 */

  frameout(pActwk); /* Line 88, Address: 0x1021d90 */
} /* Line 89, Address: 0x1021d9c */









short escal4_ridechk(sprite_status* pActwk) { /* Line 99, Address: 0x1021db0 */
  hitchk(pActwk, &actwk[0]); /* Line 100, Address: 0x1021dbc */
} /* Line 101, Address: 0x1021dd0 */








void escal4_init(sprite_status* pActwk) { /* Line 110, Address: 0x1021de0 */
  pActwk->r_no0 += 2; /* Line 111, Address: 0x1021de8 */
  pActwk->actflg |= 4; /* Line 112, Address: 0x1021df8 */
  pActwk->sproffset = 17244; /* Line 113, Address: 0x1021e08 */
  pActwk->sprpri = 3; /* Line 114, Address: 0x1021e14 */
  pActwk->patbase = escal4pat; /* Line 115, Address: 0x1021e20 */
  pActwk->sprhsize = 16; /* Line 116, Address: 0x1021e30 */
  pActwk->sprvsize = 16; /* Line 117, Address: 0x1021e3c */
} /* Line 118, Address: 0x1021e48 */








void escal4_wait(sprite_status* pActwk) { /* Line 127, Address: 0x1021e60 */
  short escal4_tbl[9] = { /* Line 128, Address: 0x1021e6c */
     256, -256, 160,
     256, -256, 160,
     512, -512,  80
  };


  if (pActwk->actflg & 128) { /* Line 135, Address: 0x1021e98 */
    if (escal4_ridechk(pActwk)) { /* Line 136, Address: 0x1021eb0 */
      pActwk->r_no0 += 2; /* Line 137, Address: 0x1021ec4 */
      pActwk->xspeed.w = escal4_tbl[(time_flag & 3) * 6 / 2]; /* Line 138, Address: 0x1021ed4 */
      pActwk->yspeed.w = escal4_tbl[(time_flag & 3) * 6 / 2 + 1]; /* Line 139, Address: 0x1021f1c */
      ((short*)pActwk)[33] = escal4_tbl[(time_flag & 3) * 6 / 2 + 2]; /* Line 140, Address: 0x1021f68 */
    }
  }
} /* Line 143, Address: 0x1021fb4 */








void escal4_moveup(sprite_status* pActwk) { /* Line 152, Address: 0x1021fd0 */
  escal4_ridechk(pActwk); /* Line 153, Address: 0x1021fdc */

  if (((short*)pActwk)[33]) { /* Line 155, Address: 0x1021fe8 */
    pActwk->xposi.l += pActwk->xspeed.w << 8; /* Line 156, Address: 0x1021ff8 */
    pActwk->yposi.l += pActwk->yspeed.w << 8; /* Line 157, Address: 0x102201c */

    if (!(--((short*)pActwk)[33])) { /* Line 159, Address: 0x1022040 */
      pActwk->xspeed.w = 0; /* Line 160, Address: 0x1022060 */
      pActwk->yspeed.w = 0; /* Line 161, Address: 0x1022068 */
    }
  }

} /* Line 165, Address: 0x1022070 */
