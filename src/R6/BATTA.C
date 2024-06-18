#include "..\EQU.H"
#include "BATTA.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\SUICIDE.H"

void(*batta_tbl[4])(sprite_status*) =
{
  &batta_init,
  &batta_down,
  &batta_wait,
  &batta_up
};
sprite_pattern ep_batta0 =
{
  1,
  { { -16, -18, 0, 477 } }
};
sprite_pattern ep_batta1 =
{
  1,
  { { -16, -29, 0, 478 } }
};
sprite_pattern* pat_batta_e[2] =
{
  &ep_batta0,
  &ep_batta1
};
sprite_pattern bp_batta0 =
{
  1,
  { { -16, -18, 0, 479 } }
};
sprite_pattern bp_batta1 =
{
  1,
  { { -16, -29, 0, 480 } }
};
sprite_pattern* pat_batta_b[2] =
{
  &bp_batta0,
  &bp_batta1
};













































void batta(sprite_status* pActwk) { /* Line 90, Address: 0x10220d0 */
  if (enemy_suicide(pActwk)) return; /* Line 91, Address: 0x10220dc */
  batta_tbl[pActwk->r_no0 / 2](pActwk); /* Line 92, Address: 0x10220f0 */
  actionsub(pActwk); /* Line 93, Address: 0x1022134 */
  frameout_s(pActwk); /* Line 94, Address: 0x1022140 */
} /* Line 95, Address: 0x102214c */











void batta_init(sprite_status* pActwk) { /* Line 107, Address: 0x1022160 */
  pActwk->r_no0 += 2; /* Line 108, Address: 0x102216c */
  pActwk->actflg |= 4; /* Line 109, Address: 0x102217c */
  pActwk->sprpri = 3; /* Line 110, Address: 0x102218c */
  pActwk->sproffset = 9272; /* Line 111, Address: 0x1022198 */
  pActwk->sprhs = 16; /* Line 112, Address: 0x10221a4 */
  pActwk->sprhsize = 16; /* Line 113, Address: 0x10221b0 */
  *(int*)&pActwk->actfree[4] = 458752; /* Line 114, Address: 0x10221bc */
  pActwk->actfree[12] = 255; /* Line 115, Address: 0x10221cc */
  ((short*)pActwk)[28] = -16; /* Line 116, Address: 0x10221d8 */
  pActwk->patno = 1; /* Line 117, Address: 0x10221e4 */

  batta_patexg(pActwk); /* Line 119, Address: 0x10221f0 */
  if (pActwk->userflag.b.h == 0) /* Line 120, Address: 0x10221fc */
  {
    pActwk->patbase = pat_batta_e; /* Line 122, Address: 0x1022214 */
    *(int*)&pActwk->actfree[0] = -40960; /* Line 123, Address: 0x1022224 */
    pActwk->actfree[8] = 7; /* Line 124, Address: 0x1022238 */
    pActwk->actfree[9] = 7; /* Line 125, Address: 0x1022244 */
  } /* Line 126, Address: 0x1022250 */
  else
  {
    pActwk->patbase = pat_batta_b; /* Line 129, Address: 0x1022258 */
    *(int*)&pActwk->actfree[0] = -32768; /* Line 130, Address: 0x1022268 */
    pActwk->actfree[8] = 3; /* Line 131, Address: 0x1022278 */
    pActwk->actfree[9] = 3; /* Line 132, Address: 0x1022284 */
  }

  ++pActwk->actfree[8]; /* Line 135, Address: 0x1022290 */
} /* Line 136, Address: 0x10222a0 */



short emylr_jump(sprite_status* pActwk, unsigned char byD3) { /* Line 140, Address: 0x10222b0 */
  if (pActwk->actfree[12] == 255) /* Line 141, Address: 0x10222c0 */
    emycol_r(pActwk, byD3); /* Line 142, Address: 0x10222d8 */
  else
    emycol_l(pActwk, byD3); /* Line 144, Address: 0x10222f0 */
} /* Line 145, Address: 0x1022300 */










void batta_down(sprite_status* pActwk) { /* Line 156, Address: 0x1022310 */
  short iD1, iD3;

  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 159, Address: 0x1022324 */
  pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 160, Address: 0x1022340 */

  iD1 = emycol_d(pActwk); /* Line 162, Address: 0x102235c */
  ((short*)pActwk)[33] = iD1; /* Line 163, Address: 0x1022370 */
  iD3 = ((short*)pActwk)[28]; /* Line 164, Address: 0x1022378 */
  iD1 = emylr_jump(pActwk, iD3); /* Line 165, Address: 0x1022388 */
  if (iD1 < 0) /* Line 166, Address: 0x10223a0 */
  {
    if (((short*)pActwk)[33] >= 0) /* Line 168, Address: 0x10223b0 */
    {
      batta_wall(pActwk); /* Line 170, Address: 0x10223c8 */
      return; /* Line 171, Address: 0x10223d4 */
    }
    if (iD1 <= ((short*)pActwk)[33]) /* Line 173, Address: 0x10223dc */
      batta_wall(pActwk); /* Line 174, Address: 0x1022400 */
    else
      batta_floor(pActwk); /* Line 176, Address: 0x1022414 */
    return; /* Line 177, Address: 0x1022420 */
  }

  if (((short*)pActwk)[33] < 0) /* Line 180, Address: 0x1022428 */
  {
    batta_floor(pActwk); /* Line 182, Address: 0x1022440 */
    return; /* Line 183, Address: 0x102244c */
  }
  *(int*)&pActwk->actfree[4] += 8192; /* Line 185, Address: 0x1022454 */
  if (*(int*)&pActwk->actfree[4] >= 458752) /* Line 186, Address: 0x102246c */
    *(int*)&pActwk->actfree[4] = 458752; /* Line 187, Address: 0x1022488 */

} /* Line 189, Address: 0x1022498 */











void batta_floor(sprite_status* pActwk) { /* Line 201, Address: 0x10224b0 */
  pActwk->r_no0 += 2; /* Line 202, Address: 0x10224b8 */
  pActwk->yposi.w.h += ((short*)pActwk)[33]; /* Line 203, Address: 0x10224c8 */
  if (pActwk->userflag.b.h == 0) /* Line 204, Address: 0x10224e0 */
    ((short*)pActwk)[31] = 1; /* Line 205, Address: 0x10224f8 */
  else
    ((short*)pActwk)[31] = 20; /* Line 207, Address: 0x102250c */
} /* Line 208, Address: 0x1022518 */











void batta_wait(sprite_status* pActwk) { /* Line 220, Address: 0x1022530 */
  short iD6;

  if (pActwk->userflag.b.h != 0) /* Line 223, Address: 0x1022540 */
  {
    iD6 = 7; /* Line 225, Address: 0x1022558 */
    switch (((short*)pActwk)[31]) /* Line 226, Address: 0x1022564 */
    {
      case 11:
      case 18:
        iD6 = -iD6; /* Line 230, Address: 0x10225ac */
      case 6:
      case 15:
        pActwk->yposi.w.h += iD6; /* Line 233, Address: 0x10225c8 */
        batta_patexg(pActwk); /* Line 234, Address: 0x10225d8 */
        break;
    }
  }



  --((short*)pActwk)[31]; /* Line 241, Address: 0x10225e4 */
  if (((short*)pActwk)[31] == 0) /* Line 242, Address: 0x10225f4 */
  {
    pActwk->r_no0 += 2; /* Line 244, Address: 0x102260c */
    pActwk->yposi.w.h -= 7; /* Line 245, Address: 0x102261c */
    batta_patexg(pActwk); /* Line 246, Address: 0x102262c */
    if (pActwk->userflag.b.h == 0) /* Line 247, Address: 0x1022638 */
      *(int*)&pActwk->actfree[4] = -393216; /* Line 248, Address: 0x1022650 */
    else
      *(int*)&pActwk->actfree[4] = -327680; /* Line 250, Address: 0x1022668 */
    --((char*)pActwk)[54]; /* Line 251, Address: 0x1022678 */
    if (((char*)pActwk)[54] < 0) /* Line 252, Address: 0x1022688 */
      batta_wall(pActwk); /* Line 253, Address: 0x10226a0 */
  }
} /* Line 255, Address: 0x10226ac */











void batta_up(sprite_status* pActwk) { /* Line 267, Address: 0x10226c0 */
  short iD1, iD3;

  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 270, Address: 0x10226d4 */
  pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 271, Address: 0x10226f0 */
  iD1 = emycol_u(pActwk); /* Line 272, Address: 0x102270c */
  ((short*)pActwk)[33] = iD1; /* Line 273, Address: 0x1022720 */
  iD3 = ((short*)pActwk)[28]; /* Line 274, Address: 0x1022728 */
  iD1 = emylr_jump(pActwk, iD3); /* Line 275, Address: 0x1022738 */
  if (iD1 < 0) /* Line 276, Address: 0x1022750 */
  {
    if (((short*)pActwk)[33] >= 0 || iD1 <= ((short*)pActwk)[33]) /* Line 278, Address: 0x1022760 */
    {

      batta_wall(pActwk); /* Line 281, Address: 0x102279c */
    } /* Line 282, Address: 0x10227a8 */
    else
      batta_ceiling(pActwk); /* Line 284, Address: 0x10227b0 */
    return; /* Line 285, Address: 0x10227bc */
  }

  if (((short*)pActwk)[33] < 0) /* Line 288, Address: 0x10227c4 */
  {
    batta_ceiling(pActwk); /* Line 290, Address: 0x10227dc */
    return; /* Line 291, Address: 0x10227e8 */
  }
  *(int*)&pActwk->actfree[4] += 8192; /* Line 293, Address: 0x10227f0 */
  if (*(int*)&pActwk->actfree[4] >= 0) /* Line 294, Address: 0x1022808 */
    batta_fall(pActwk); /* Line 295, Address: 0x102281c */
} /* Line 296, Address: 0x1022828 */











void batta_ceiling(sprite_status* pActwk) { /* Line 308, Address: 0x1022840 */
  pActwk->yposi.w.h -= ((short*)pActwk)[33]; /* Line 309, Address: 0x102284c */
  *(int*)&pActwk->actfree[4] = 0; /* Line 310, Address: 0x1022864 */
  batta_fall(pActwk); /* Line 311, Address: 0x1022870 */
} /* Line 312, Address: 0x102287c */











void batta_fall(sprite_status* pActwk) { /* Line 324, Address: 0x1022890 */
  pActwk->r_no0 -= 4; /* Line 325, Address: 0x102289c */
  pActwk->yposi.w.h -= 11; /* Line 326, Address: 0x10228ac */
  batta_patexg(pActwk); /* Line 327, Address: 0x10228bc */
} /* Line 328, Address: 0x10228c8 */











void batta_wall(sprite_status* pActwk) { /* Line 340, Address: 0x10228e0 */
  pActwk->actfree[8] = pActwk->actfree[9]; /* Line 341, Address: 0x10228e8 */
  pActwk->actflg ^= 1; /* Line 342, Address: 0x10228f8 */
  pActwk->cddat ^= 1; /* Line 343, Address: 0x1022908 */
  *(int*)&pActwk->actfree[0] = -(long int)*(int*)&pActwk->actfree[0]; /* Line 344, Address: 0x1022918 */
  ((short*)pActwk)[28] = -((short*)pActwk)[28]; /* Line 345, Address: 0x1022944 */
  if (pActwk->actfree[12] == 255) /* Line 346, Address: 0x1022968 */
    pActwk->actfree[12] = 1; /* Line 347, Address: 0x1022980 */
  else
    pActwk->actfree[12] = 255; /* Line 349, Address: 0x1022994 */
} /* Line 350, Address: 0x10229a0 */











void batta_patexg(sprite_status* pActwk) { /* Line 362, Address: 0x10229b0 */
  if (pActwk->patno != 0) /* Line 363, Address: 0x10229b8 */
  {
    pActwk->patno = 0; /* Line 365, Address: 0x10229cc */
    pActwk->sprvsize = 19; /* Line 366, Address: 0x10229d4 */
    pActwk->colino = 47; /* Line 367, Address: 0x10229e0 */
  } /* Line 368, Address: 0x10229ec */
  else
  {
    pActwk->patno = 1; /* Line 371, Address: 0x10229f4 */
    pActwk->sprvsize = 28; /* Line 372, Address: 0x1022a00 */
    pActwk->colino = 48; /* Line 373, Address: 0x1022a0c */
  }
} /* Line 375, Address: 0x1022a18 */
