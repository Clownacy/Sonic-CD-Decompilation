#include "EQU.H"
#include "BLOCK.H"
#include "ACTION.H"
#include "DUMMY.H"
#include "PLAYSUB.H"
#include "RIDECHK.H"

void(*block_tbl[7])(sprite_status*) =
{
  &block_init,
  &block_move,
  &block_move2,
  &block_move3,
  &block_move4,
  &block_move5,
  &block_move6
};
unsigned char blockchg0[3] = { 2, 5, 255 };
unsigned char blockchg1[10] = { 2, 1, 5, 2, 5, 3, 5, 4, 5, 252 };
unsigned char blockchg2[10] = { 2, 1, 0, 2, 0, 3, 0, 4, 0, 252 };
unsigned char* blockchg[3] = { blockchg0, blockchg1, blockchg2 };
spr_array block0 =
{
  0,
  { { -12, -12, 0, 403 } }
};
spr_array block1 =
{
  1,
  { { -12, -12, 0, 403 } }
};
spr_array block2 =
{
  1,
  { { -12, -12, 0, 404 } }
};
spr_array block3 =
{
  1,
  { { -12, -12, 0, 405 } }
};
spr_array block4 =
{
  1,
  { { -12, -12, 0, 406 } }
};
spr_array block5 =
{
  1,
  { { -12, -12, 0, 407 } }
};
spr_array* blockpat[6] = { &block0, &block1, &block2, &block3, &block4, &block5 };

void block(sprite_status* pActwk) { /* Line 54, Address: 0x10150b0 */
  short iD0, iD1;

  block_tbl[pActwk->r_no0 / 2](pActwk); /* Line 57, Address: 0x10150c4 */
  iD0 = pActwk->xposi.w.h & 65408; /* Line 58, Address: 0x1015108 */
  iD1 = scra_h_posit.w.h - 128; /* Line 59, Address: 0x101512c */
  iD1 &= -128; /* Line 60, Address: 0x1015150 */
  iD0 -= iD1; /* Line 61, Address: 0x1015160 */
  if ((unsigned short)iD0 >= 641) /* Line 62, Address: 0x101516c */
    frameout(pActwk); /* Line 63, Address: 0x1015180 */
} /* Line 64, Address: 0x101518c */











void block_init(sprite_status* pActwk) { /* Line 76, Address: 0x10151b0 */
  pActwk->r_no0 += 2; /* Line 77, Address: 0x10151bc */
  pActwk->actflg |= 4; /* Line 78, Address: 0x10151cc */
  pActwk->patbase = blockpat; /* Line 79, Address: 0x10151dc */

  pa_set(pActwk, 5); /* Line 81, Address: 0x10151ec */

  pActwk->sprpri = 1; /* Line 83, Address: 0x10151fc */
  pActwk->sprhsize = 12; /* Line 84, Address: 0x1015208 */
  pActwk->sprvsize = 12; /* Line 85, Address: 0x1015214 */
  pActwk->patno = 5; /* Line 86, Address: 0x1015220 */
  block_move(pActwk); /* Line 87, Address: 0x101522c */
} /* Line 88, Address: 0x1015238 */











void block_move(sprite_status* pActwk) { /* Line 100, Address: 0x1015250 */
  block_ride(pActwk); /* Line 101, Address: 0x101525c */
  if (time_flag != 0) /* Line 102, Address: 0x1015268 */
    if (time_flag == 2) /* Line 103, Address: 0x101527c */
    {
      if (pActwk->cddat & 8) goto label1; /* Line 105, Address: 0x1015294 */
    } /* Line 106, Address: 0x10152ac */
    else
    {

      pActwk->patno = 0; /* Line 110, Address: 0x10152b4 */
      if (pActwk->cddat & 8) /* Line 111, Address: 0x10152bc */
      {
        pActwk->r_no0 = 6; /* Line 113, Address: 0x10152d4 */
        pActwk->mstno.b.h = 1; /* Line 114, Address: 0x10152e0 */
      }
    }

  actionsub(pActwk); /* Line 118, Address: 0x10152ec */
  return; /* Line 119, Address: 0x10152f8 */
label1:
  pActwk->r_no0 += 2; /* Line 121, Address: 0x1015300 */
  block_move2(pActwk); /* Line 122, Address: 0x1015310 */
} /* Line 123, Address: 0x101531c */











void block_move2(sprite_status* pActwk) { /* Line 135, Address: 0x1015330 */
  short iD0;

  block_ride(pActwk); /* Line 138, Address: 0x1015340 */
  pActwk->yposi.w.h += 2; /* Line 139, Address: 0x101534c */
  iD0 = scra_v_posit.w.h; /* Line 140, Address: 0x101535c */
  iD0 += 224; /* Line 141, Address: 0x101536c */
  if (iD0 < pActwk->yposi.w.h) /* Line 142, Address: 0x1015378 */
  {
    frameout(pActwk); /* Line 144, Address: 0x101539c */
  } else /* Line 145, Address: 0x10153a8 */
  {
    actionsub(pActwk); /* Line 147, Address: 0x10153b0 */
  }
} /* Line 149, Address: 0x10153bc */











void block_move3(sprite_status* pActwk) { /* Line 161, Address: 0x10153d0 */
  block_ride(pActwk); /* Line 162, Address: 0x10153dc */
  if (!(pActwk->cddat & 8)) /* Line 163, Address: 0x10153e8 */
  {
    pActwk->r_no0 = 2; /* Line 165, Address: 0x1015400 */
    return; /* Line 166, Address: 0x101540c */
  }

  patchg(pActwk, blockchg); /* Line 169, Address: 0x1015414 */
  actionsub(pActwk); /* Line 170, Address: 0x1015428 */
} /* Line 171, Address: 0x1015434 */











void block_move4(sprite_status* pActwk) { /* Line 183, Address: 0x1015450 */
  pActwk->mstno.b.h = 0; /* Line 184, Address: 0x101545c */
  block_ride(pActwk); /* Line 185, Address: 0x1015464 */
  if (!(pActwk->cddat & 8)) /* Line 186, Address: 0x1015470 */
  {
    pActwk->r_no0 += 2; /* Line 188, Address: 0x1015488 */
    pActwk->mstno.b.h = 2; /* Line 189, Address: 0x1015498 */
    return; /* Line 190, Address: 0x10154a4 */
  }

  patchg(pActwk, blockchg); /* Line 193, Address: 0x10154ac */
  actionsub(pActwk); /* Line 194, Address: 0x10154c0 */
} /* Line 195, Address: 0x10154cc */











void block_move5(sprite_status* pActwk) { /* Line 207, Address: 0x10154e0 */
  block_ride(pActwk); /* Line 208, Address: 0x10154ec */
  patchg(pActwk, blockchg); /* Line 209, Address: 0x10154f8 */
  actionsub(pActwk); /* Line 210, Address: 0x101550c */
} /* Line 211, Address: 0x1015518 */











void block_move6(sprite_status* pActwk) { /* Line 223, Address: 0x1015530 */
  pActwk->r_no0 = 2; /* Line 224, Address: 0x1015538 */
} /* Line 225, Address: 0x1015544 */











void block_ride(sprite_status* pActwk) { /* Line 237, Address: 0x1015550 */
  ride_on_chk_b(pActwk, actwk); /* Line 238, Address: 0x101555c */
  ride_on_chk_b(pActwk, actwk); /* Line 239, Address: 0x1015570 */
} /* Line 240, Address: 0x1015584 */












void ride_on_chk_b(sprite_status* pActwk, sprite_status* pPlaywk) { /* Line 253, Address: 0x10155a0 */
  ridechk(pActwk, pPlaywk); /* Line 254, Address: 0x10155b0 */
} /* Line 255, Address: 0x10155c0 */
