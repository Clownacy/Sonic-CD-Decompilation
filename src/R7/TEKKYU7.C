#include "..\EQU.H"
#include "TEKKYU7.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"

static void tekkyu7_init(sprite_status* pActwk);
static void tekkyu7_move(sprite_status* pActwk);
static void tekkyu7_stop(sprite_status* pActwk);

static sprite_pattern tekkyu7_pat0 = {
  1,
  { { -16, -16, 0, 410 } }
};
sprite_pattern* pat_tekkyu7[1] = { &tekkyu7_pat0 };
























































void tekkyu7(sprite_status* pActwk) { /* Line 71, Address: 0x101fb40 */
  void(*tekkyu7_acttbl[3])(sprite_status*) = { /* Line 72, Address: 0x101fb4c */
    &tekkyu7_init,
    &tekkyu7_move,
    &tekkyu7_stop
  };

  tekkyu7_acttbl[pActwk->r_no0 / 2](pActwk); /* Line 78, Address: 0x101fb70 */
  actionsub(pActwk); /* Line 79, Address: 0x101fbac */
  frameout_s00(pActwk, ((short*)pActwk)[23]); /* Line 80, Address: 0x101fbb8 */
} /* Line 81, Address: 0x101fbcc */








void tekkyu7_init(sprite_status* pActwk) { /* Line 90, Address: 0x101fbe0 */
  short tekkyu7_tbl0[24] = { /* Line 91, Address: 0x101fbec */
    1024,    0, 24, 12,
       0, 1024, 16,  8,
     512,    0, 48, 24,
       0,  512, 32, 16,
     256,    0, 96, 48,
       0,  256, 64, 32
  };

  short tekkyu7_tbl1[3] = { /* Line 100, Address: 0x101fc20 */
    60,
    40,
    20
  };

  pActwk->r_no0 += 2; /* Line 106, Address: 0x101fc44 */
  pActwk->actflg |= 4; /* Line 107, Address: 0x101fc54 */
  pActwk->sprpri = 3; /* Line 108, Address: 0x101fc64 */
  pActwk->colino = 181; /* Line 109, Address: 0x101fc70 */
  pActwk->sprhs = 16; /* Line 110, Address: 0x101fc7c */
  pActwk->sprhsize = 16; /* Line 111, Address: 0x101fc88 */
  pActwk->sprvsize = 16; /* Line 112, Address: 0x101fc94 */
  pActwk->sproffset = 902; /* Line 113, Address: 0x101fca0 */
  pActwk->patbase = pat_tekkyu7; /* Line 114, Address: 0x101fcac */
  ((short*)pActwk)[23] = pActwk->xposi.w.h; /* Line 115, Address: 0x101fcbc */
  ((short*)pActwk)[25] = tekkyu7_tbl1[time_flag]; /* Line 116, Address: 0x101fccc */

  *(int*)&pActwk->actfree[8] = tekkyu7_tbl0[time_flag * 8 + pActwk->userflag.b.h * 4] << 8; /* Line 118, Address: 0x101fcec */
  *(int*)&pActwk->actfree[12] = tekkyu7_tbl0[time_flag * 8 + pActwk->userflag.b.h * 4 + 1] << 8; /* Line 119, Address: 0x101fd38 */
  ((short*)pActwk)[24] = tekkyu7_tbl0[time_flag * 8 + pActwk->userflag.b.h * 4 + 2]; /* Line 120, Address: 0x101fd88 */
  ((short*)pActwk)[26] = tekkyu7_tbl0[time_flag * 8 + pActwk->userflag.b.h * 4 + 3]; /* Line 121, Address: 0x101fdc8 */

  tekkyu7_move(pActwk); /* Line 123, Address: 0x101fe08 */
} /* Line 124, Address: 0x101fe14 */








void tekkyu7_move(sprite_status* pActwk) { /* Line 133, Address: 0x101fe30 */
  pActwk->xposi.l += *(int*)&pActwk->actfree[8]; /* Line 134, Address: 0x101fe38 */
  pActwk->yposi.l += *(int*)&pActwk->actfree[12]; /* Line 135, Address: 0x101fe54 */
  if (!(--((short*)pActwk)[26])) { /* Line 136, Address: 0x101fe70 */
    pActwk->r_no0 += 2; /* Line 137, Address: 0x101fe90 */
    ((short*)pActwk)[26] = ((short*)pActwk)[25]; /* Line 138, Address: 0x101fea0 */
    *(int*)&pActwk->actfree[8] *= -1; /* Line 139, Address: 0x101feb0 */
    *(int*)&pActwk->actfree[12] *= -1; /* Line 140, Address: 0x101fec8 */
  }
} /* Line 142, Address: 0x101fee0 */








void tekkyu7_stop(sprite_status* pActwk) { /* Line 151, Address: 0x101fef0 */
  if (!(--((short*)pActwk)[26])) { /* Line 152, Address: 0x101fef8 */
    pActwk->r_no0 -= 2; /* Line 153, Address: 0x101ff18 */
    ((short*)pActwk)[26] = ((short*)pActwk)[24]; /* Line 154, Address: 0x101ff28 */
  }
} /* Line 156, Address: 0x101ff38 */
