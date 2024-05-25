#include "..\EQU.H"
#include "HARI5F.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"

static void f_init(sprite_status* pActwk);
static void f_wait(sprite_status* pActwk);
static void f_fall(sprite_status* pActwk);

static sprite_pattern hari5f_pat0 = {
  1,
  { { -8, -24, 0, 421 } }
};
sprite_pattern* pat_hari5f[1] = { &hari5f_pat0 };


















































void hari5f(sprite_status* pActwk) { /* Line 66, Address: 0x1023be0 */
  void(*hari5f_move_tbl[3])(sprite_status*) = { /* Line 67, Address: 0x1023bec */
    &f_init,
    &f_wait,
    &f_fall
  };

  hari5f_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 73, Address: 0x1023c10 */
  actionsub(pActwk); /* Line 74, Address: 0x1023c4c */
  frameout_s(pActwk); /* Line 75, Address: 0x1023c58 */
} /* Line 76, Address: 0x1023c64 */







static void f_init(sprite_status* pActwk) { /* Line 84, Address: 0x1023c80 */
  pActwk->r_no0 += 2; /* Line 85, Address: 0x1023c8c */
  pActwk->actflg |= 4; /* Line 86, Address: 0x1023c9c */
  pActwk->sprpri = 3; /* Line 87, Address: 0x1023cac */
  pActwk->sprhs = 8; /* Line 88, Address: 0x1023cb8 */
  pActwk->sprhsize = 8; /* Line 89, Address: 0x1023cc4 */
  pActwk->sprvsize = 24; /* Line 90, Address: 0x1023cd0 */
  pActwk->patbase = pat_hari5f; /* Line 91, Address: 0x1023cdc */
  pActwk->sproffset = 834; /* Line 92, Address: 0x1023cec */

  if (time_flag == 0) /* Line 94, Address: 0x1023cf8 */
    pActwk->sproffset = 17218; /* Line 95, Address: 0x1023d0c */
  else if (time_flag == 1) /* Line 96, Address: 0x1023d20 */
    pActwk->sproffset = 834; /* Line 97, Address: 0x1023d38 */
  else if (generate_flag) /* Line 98, Address: 0x1023d4c */
    pActwk->sproffset = 834; /* Line 99, Address: 0x1023d5c */
  else
    pActwk->sproffset = 17218; /* Line 101, Address: 0x1023d70 */

  f_wait(pActwk); /* Line 103, Address: 0x1023d7c */
} /* Line 104, Address: 0x1023d88 */








static void f_wait(sprite_status* pActwk) { /* Line 113, Address: 0x1023da0 */
  if ((unsigned short)(actwk[0].yposi.w.h - pActwk->yposi.w.h - 24) < 104) { /* Line 114, Address: 0x1023da8 */
    if ((unsigned short)(actwk[0].xposi.w.h - pActwk->xposi.w.h + 8) < 16) { /* Line 115, Address: 0x1023de4 */
      pActwk->r_no0 += 2; /* Line 116, Address: 0x1023e20 */
      pActwk->colino = 185; /* Line 117, Address: 0x1023e30 */
    }
  }
} /* Line 120, Address: 0x1023e3c */








static void f_fall(sprite_status* pActwk) { /* Line 129, Address: 0x1023e50 */
  unsigned char bD0;
  short wD1;

  if (!(pActwk->actflg & 128)) { /* Line 133, Address: 0x1023e64 */
    if (pActwk->yposi.w.h >= actwk[0].yposi.w.h) { /* Line 134, Address: 0x1023e7c */
      frameout(pActwk); /* Line 135, Address: 0x1023ea8 */
      return; /* Line 136, Address: 0x1023eb4 */
    }
  }


  wD1 = emycol_d3(pActwk, pActwk->xposi.w.h, pActwk->yposi.w.h - (unsigned short)pActwk->sprvsize); /* Line 141, Address: 0x1023ebc */

  if (wD1 >= 0) { /* Line 143, Address: 0x1023f04 */
    bD0 = 0; /* Line 144, Address: 0x1023f14 */
    if (pActwk->actfree[21] & 128) { /* Line 145, Address: 0x1023f18 */
      frameout(pActwk); /* Line 146, Address: 0x1023f30 */
      return; /* Line 147, Address: 0x1023f3c */
    }


  }
  else
    bD0 = 255; /* Line 153, Address: 0x1023f44 */
  pActwk->actfree[21] = bD0; /* Line 154, Address: 0x1023f4c */

  pActwk->yposi.l += *(int*)((char*)&pActwk->actfree[0]); /* Line 156, Address: 0x1023f54 */
  *(int*)&pActwk->actfree[0] += 16384; /* Line 157, Address: 0x1023f70 */
} /* Line 158, Address: 0x1023f88 */
