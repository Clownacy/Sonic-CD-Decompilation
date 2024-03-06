#include "..\EQU.H"
#include "BANEIWA.H"

typedef struct {
  unsigned char a;
  char b;
  short c;
}
move_data;

void baneiwa_init(sprite_status* pActwk);
void baneiwa_move(sprite_status* pActwk);

static sprite_pattern pat0 =
{
  1,
  { { -16, -32, 0, 500 } }
};
sprite_pattern* baneiwapat[1] = { &pat0 };





































void baneiwa(sprite_status* pActwk) { /* Line 57, Address: 0x1029c90 */
  sprite_status* pRideAct;
  void(*tbl[2])(sprite_status*) = /* Line 59, Address: 0x1029ca0 */
  {
    &baneiwa_init,
    &baneiwa_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 65, Address: 0x1029cbc */
  actionsub(pActwk); /* Line 66, Address: 0x1029cf8 */
  if (pActwk->actfree[18]) /* Line 67, Address: 0x1029d04 */
  {
    pRideAct = &actwk[((short*)pActwk)[28]]; /* Line 69, Address: 0x1029d14 */
    if (pRideAct->actno != 72) /* Line 70, Address: 0x1029d3c */
    {
      frameout(pActwk); /* Line 72, Address: 0x1029d50 */
    }
  } /* Line 74, Address: 0x1029d5c */
  else
  {
    frameout_s(pActwk); /* Line 77, Address: 0x1029d64 */
  }
} /* Line 79, Address: 0x1029d70 */




static void baneiwa_init(sprite_status* pActwk) { /* Line 84, Address: 0x1029d90 */
  sprite_status* pNewActwk;

  pActwk->r_no0 += 2; /* Line 87, Address: 0x1029d9c */
  pActwk->actflg |= 4; /* Line 88, Address: 0x1029dac */
  pActwk->sproffset = 17514; /* Line 89, Address: 0x1029dbc */
  pActwk->sprpri = 3; /* Line 90, Address: 0x1029dc8 */
  pActwk->patbase = baneiwapat; /* Line 91, Address: 0x1029dd4 */
  pActwk->sprhsize = 16; /* Line 92, Address: 0x1029de4 */
  pActwk->sprvsize = 32; /* Line 93, Address: 0x1029df0 */

  if (pActwk->actfree[18] == 0) /* Line 95, Address: 0x1029dfc */
  {
    if (actwkchk(&pNewActwk) == 0) /* Line 97, Address: 0x1029e10 */
    {
      pNewActwk->actno = 72; /* Line 99, Address: 0x1029e24 */
      pNewActwk->xposi.w.h = pActwk->xposi.w.h + 32; /* Line 100, Address: 0x1029e30 */
      pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 101, Address: 0x1029e54 */
      pNewActwk->actfree[18] = 1; /* Line 102, Address: 0x1029e64 */

      ((short*)pNewActwk)[28] = (unsigned short)(pActwk - actwk); /* Line 104, Address: 0x1029e70 */
    }
  }
} /* Line 107, Address: 0x1029eac */




static void baneiwa_move(sprite_status* pActwk) { /* Line 112, Address: 0x1029ec0 */
  short d0;
  short d1;
  unsigned char index;







  move_data baneiwa_mvtbl[4] = /* Line 123, Address: 0x1029ed8 */
  {
    { 128, -4,  512 },
    { 128, -4,    0 },
    { 128,  4, -512 },
    { 128,  4,    0 }
  };





  if (pActwk->yspeed.w < 0) /* Line 135, Address: 0x1029f0c */
  {

    ride_on_chk(pActwk, &actwk[0]); /* Line 138, Address: 0x1029f24 */
  }
  if (pActwk->actfree[16]) /* Line 140, Address: 0x1029f38 */
  {
    pActwk->yposi.l += pActwk->yspeed.w << 8; /* Line 142, Address: 0x1029f48 */
    pActwk->yspeed.w += ((short*)pActwk)[33]; /* Line 143, Address: 0x1029f6c */
    --pActwk->actfree[16]; /* Line 144, Address: 0x1029f84 */
    if (pActwk->actfree[16]) goto label1; /* Line 145, Address: 0x1029f94 */



    ++pActwk->actfree[17]; /* Line 149, Address: 0x1029fa4 */
    if (pActwk->actfree[17] != 4) goto label1; /* Line 150, Address: 0x1029fb4 */



    pActwk->actfree[17] = 0; /* Line 154, Address: 0x1029fcc */
    goto label1; /* Line 155, Address: 0x1029fd4 */
  }

  index = pActwk->actfree[17]; /* Line 158, Address: 0x1029fdc */
  pActwk->actfree[16] = baneiwa_mvtbl[index].a; /* Line 159, Address: 0x1029fe8 */
  d0 = baneiwa_mvtbl[index].b; /* Line 160, Address: 0x102a000 */
  d1 = baneiwa_mvtbl[index].c; /* Line 161, Address: 0x102a020 */
  if (pActwk->actfree[18]) /* Line 162, Address: 0x102a038 */
  {
    d0 = -d0; /* Line 164, Address: 0x102a048 */
    d1 = -d1; /* Line 165, Address: 0x102a054 */
  }
  ((short*)pActwk)[33] = d0; /* Line 167, Address: 0x102a060 */
  pActwk->yspeed.w = d1; /* Line 168, Address: 0x102a068 */
label1:
  if (pActwk->yspeed.w >= 0) /* Line 170, Address: 0x102a070 */
  {

    ride_on_chk(pActwk, &actwk[0]); /* Line 173, Address: 0x102a088 */
  }
} /* Line 175, Address: 0x102a09c */
