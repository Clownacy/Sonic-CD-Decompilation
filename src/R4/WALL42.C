#include "..\EQU.H"
#include "WALL42.H"

void act_init(sprite_status* pActwk);
void act_wait(sprite_status* pActwk);
void act_move(sprite_status* pActwk);
void act_stop(sprite_status* pActwk);

static sprite_pattern pat00 = {
  1,
  { { -32, -64, 0, 531 } }
};
sprite_pattern* pat_wall42[1] = { &pat00 };






































void wall42(sprite_status* pActwk) { /* Line 52, Address: 0x102e010 */
  short d0, d1;
  unsigned char* a1;
  void(*tbl[4])(sprite_status*) = /* Line 55, Address: 0x102e028 */
  {
    &act_init,
    &act_wait,
    &act_move,
    &act_stop
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 63, Address: 0x102e054 */
  actionsub(pActwk); /* Line 64, Address: 0x102e090 */

  d0 = pActwk->xposi.w.h & -128; /* Line 66, Address: 0x102e09c */
  d1 = scra_h_posit.w.h - 128 & -128; /* Line 67, Address: 0x102e0c4 */
  d0 -= d1; /* Line 68, Address: 0x102e0f0 */
  if (d0 >= 641) /* Line 69, Address: 0x102e0fc */
  {
    a1 = ((unsigned char**)pActwk)[12]; /* Line 71, Address: 0x102e110 */
    *a1 &= 127; /* Line 72, Address: 0x102e118 */
    frameout(pActwk); /* Line 73, Address: 0x102e124 */
  }
} /* Line 75, Address: 0x102e130 */




static void act_init(sprite_status* pActwk) { /* Line 80, Address: 0x102e150 */
  short index;
  unsigned char* a1;

  pActwk->actflg |= 4; /* Line 84, Address: 0x102e160 */
  pActwk->sprpri = 3; /* Line 85, Address: 0x102e170 */
  pActwk->sprhsize = 32; /* Line 86, Address: 0x102e17c */
  pActwk->sprvsize = 64; /* Line 87, Address: 0x102e188 */
  pActwk->sproffset = 17514; /* Line 88, Address: 0x102e194 */
  pActwk->patbase = pat_wall42; /* Line 89, Address: 0x102e1a0 */

  index = pActwk->cdsts; /* Line 91, Address: 0x102e1b0 */
  index *= 3; /* Line 92, Address: 0x102e1cc */
  index += time_flag; /* Line 93, Address: 0x102e1dc */
  a1 = &flagwork[index]; /* Line 94, Address: 0x102e1fc */
  ((unsigned char**)pActwk)[12] = a1; /* Line 95, Address: 0x102e210 */

  if (!(*a1 & 1)) /* Line 97, Address: 0x102e218 */
  {
    *a1 |= 1; /* Line 99, Address: 0x102e22c */
    ((short*)pActwk)[23] = 60; /* Line 100, Address: 0x102e238 */
    pActwk->r_no0 += 2; /* Line 101, Address: 0x102e244 */
  } /* Line 102, Address: 0x102e254 */
  else
  {
    pActwk->xposi.w.h += 192; /* Line 105, Address: 0x102e25c */
    pActwk->r_no0 += 6; /* Line 106, Address: 0x102e26c */
  }
} /* Line 108, Address: 0x102e27c */




static void act_wait(sprite_status* pActwk) { /* Line 113, Address: 0x102e290 */
  if (((short*)pActwk)[23] == -1) /* Line 114, Address: 0x102e29c */
  {
    ((short*)pActwk)[23] = 384; /* Line 116, Address: 0x102e2b8 */
    pActwk->r_no0 += 2; /* Line 117, Address: 0x102e2c4 */
  }
  --((short*)pActwk)[23]; /* Line 119, Address: 0x102e2d4 */
  act_stop(pActwk); /* Line 120, Address: 0x102e2e4 */
} /* Line 121, Address: 0x102e2f0 */




static void act_move(sprite_status* pActwk) { /* Line 126, Address: 0x102e300 */
  int d0;

  if (hitchk(pActwk, &actwk[0]) != 0) /* Line 129, Address: 0x102e310 */
  {
    d0 = 32768; /* Line 131, Address: 0x102e32c */
    d0 <<= 8; /* Line 132, Address: 0x102e330 */
    actwk[0].mspeed.w = d0 & 65535; /* Line 133, Address: 0x102e334 */
  }
  pActwk->xposi.l += 32767 + 1; /* Line 135, Address: 0x102e348 */
  if (((short*)pActwk)[23] == -1) /* Line 136, Address: 0x102e35c */
  {
    pActwk->r_no0 += 2; /* Line 138, Address: 0x102e378 */
  }
  --((short*)pActwk)[23]; /* Line 140, Address: 0x102e388 */
} /* Line 141, Address: 0x102e398 */




static void act_stop(sprite_status* pActwk) { /* Line 146, Address: 0x102e3b0 */
  hitchk(pActwk, &actwk[0]); /* Line 147, Address: 0x102e3bc */
} /* Line 148, Address: 0x102e3d0 */
