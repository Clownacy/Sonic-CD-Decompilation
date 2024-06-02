#include "..\EQU.H"
#include "UKIDAI.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\RIDECHK.H"

static void a_init(sprite_status* pActwk);
static void a_moving(sprite_status* pActwk);
static void a_wait(sprite_status* pActwk);
static void a_move(sprite_status* pActwk);
static void a_move1(sprite_status* pActwk);

static sprite_pattern pat00 =
{
  1,
  { { -16, -8, 0, 530 } }
};
sprite_pattern* pat_ukidai[1] = { &pat00 };



































void ukidai(sprite_status* pActwk) { /* Line 55, Address: 0x102d1b0 */
  void(*tbl[5])(sprite_status*) = /* Line 56, Address: 0x102d1bc */
  {
    &a_init,
    &a_moving,
    &a_wait,
    &a_move,
    &a_move1
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 65, Address: 0x102d1e8 */
  actionsub(pActwk); /* Line 66, Address: 0x102d224 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 67, Address: 0x102d230 */
} /* Line 68, Address: 0x102d244 */




static void a_init(sprite_status* pActwk) { /* Line 73, Address: 0x102d260 */
  pActwk->r_no0 += 2; /* Line 74, Address: 0x102d26c */
  pActwk->actflg |= 4; /* Line 75, Address: 0x102d27c */
  pActwk->sprpri = 3; /* Line 76, Address: 0x102d28c */
  pActwk->sprhs = 16; /* Line 77, Address: 0x102d298 */
  pActwk->sprhsize = 16; /* Line 78, Address: 0x102d2a4 */
  pActwk->sprvsize = 8; /* Line 79, Address: 0x102d2b0 */
  pActwk->sproffset = 848; /* Line 80, Address: 0x102d2bc */
  pActwk->patbase = pat_ukidai; /* Line 81, Address: 0x102d2c8 */
  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 82, Address: 0x102d2d8 */

  if (watermoveposi != 1920) /* Line 84, Address: 0x102d2e8 */
  {
    if (watermoveposi != 1504) /* Line 86, Address: 0x102d304 */
    {
      frameout(pActwk); /* Line 88, Address: 0x102d320 */
      return; /* Line 89, Address: 0x102d32c */
    }
  }
  a_moving(pActwk); /* Line 92, Address: 0x102d334 */
} /* Line 93, Address: 0x102d340 */




static void a_moving(sprite_status* pActwk) { /* Line 98, Address: 0x102d350 */
  short d0;

  pActwk->yposi.w.h = waterposi; /* Line 101, Address: 0x102d360 */

  d0 = waterposi_m; /* Line 103, Address: 0x102d370 */
  if (watermoveposi == d0) /* Line 104, Address: 0x102d380 */
  {
    if (d0 == 1920) /* Line 106, Address: 0x102d3a0 */
    {
      pActwk->r_no0 = 4; /* Line 108, Address: 0x102d3b4 */
      a_wait(pActwk); /* Line 109, Address: 0x102d3c0 */
      return; /* Line 110, Address: 0x102d3cc */
    }
    if (d0 == 1504) /* Line 112, Address: 0x102d3d4 */
    {
      pActwk->r_no0 = 6; /* Line 114, Address: 0x102d3e8 */
      a_move(pActwk); /* Line 115, Address: 0x102d3f4 */
      return; /* Line 116, Address: 0x102d400 */
    }
    frameout(pActwk); /* Line 118, Address: 0x102d408 */
  }
} /* Line 120, Address: 0x102d414 */




static void a_wait(sprite_status* pActwk) { /* Line 125, Address: 0x102d430 */
  pActwk->yposi.w.h = waterposi; /* Line 126, Address: 0x102d43c */

  if (ridechk(pActwk, &actwk[0])) /* Line 128, Address: 0x102d44c */
  {
    pActwk->r_no0 += 2; /* Line 130, Address: 0x102d468 */
    pActwk->xposi.w.h = actwk[0].xposi.w.h; /* Line 131, Address: 0x102d478 */
    watermoveposi = 1504; /* Line 132, Address: 0x102d488 */
  }
} /* Line 134, Address: 0x102d494 */




static void a_move(sprite_status* pActwk) { /* Line 139, Address: 0x102d4b0 */
  ushort_union d0;

  pActwk->r_no0 += 2; /* Line 142, Address: 0x102d4bc */
  d0.b.h = waterspeed; /* Line 143, Address: 0x102d4cc */
  d0.b.l = water_flag; /* Line 144, Address: 0x102d4d8 */
  pActwk->yspeed.w = -(short)d0.w; /* Line 145, Address: 0x102d4e4 */

  a_move1(pActwk); /* Line 147, Address: 0x102d50c */
} /* Line 148, Address: 0x102d518 */




static void a_move1(sprite_status* pActwk) { /* Line 153, Address: 0x102d530 */
  sprite_status* pPlayerwk;
  int a6;
  short d1;
  short d2;
  short d3;
  short d4, d5, d6;

  pActwk->yposi.w.h = waterposi; /* Line 161, Address: 0x102d55c */

  pPlayerwk = &actwk[0]; /* Line 163, Address: 0x102d56c */
  d4 = pPlayerwk->xspeed.b.h; /* Line 164, Address: 0x102d574 */
  d4 += pPlayerwk->xposi.w.h; /* Line 165, Address: 0x102d588 */
  d4 -= pActwk->xposi.w.h; /* Line 166, Address: 0x102d598 */
  if (pActwk->xposi.w.h) /* Line 167, Address: 0x102d5ac */
  {
    a6 = 2; /* Line 169, Address: 0x102d5bc */
    d6 = 1; /* Line 170, Address: 0x102d5c0 */
    d5 = 0; /* Line 171, Address: 0x102d5cc */
    d5 = (unsigned short)pActwk->sprhs; /* Line 172, Address: 0x102d5d0 */
    if (d4 < 0) /* Line 173, Address: 0x102d5ec */
    {
      a6 = 1; /* Line 175, Address: 0x102d5fc */
      d6 *= -1; /* Line 176, Address: 0x102d600 */
      d5 *= -1; /* Line 177, Address: 0x102d60c */
      d4 *= -1; /* Line 178, Address: 0x102d618 */
    }
    *(int*)&pActwk->actfree[0] = a6; /* Line 180, Address: 0x102d624 */
    ((short*)pActwk)[25] = d6; /* Line 181, Address: 0x102d630 */
    ((short*)pActwk)[26] = d5; /* Line 182, Address: 0x102d638 */
    ((short*)pActwk)[27] = d4; /* Line 183, Address: 0x102d640 */
    ((short*)pActwk)[28] = pActwk->yposi.w.h; /* Line 184, Address: 0x102d648 */
    ((short*)pActwk)[28] += 7; /* Line 185, Address: 0x102d658 */
    do
    {
      a6 = *(int*)&pActwk->actfree[0]; /* Line 188, Address: 0x102d668 */
      d3 = pActwk->xposi.w.h; /* Line 189, Address: 0x102d674 */
      d3 += ((short*)pActwk)[26]; /* Line 190, Address: 0x102d684 */
      if ((long int)a6 != 2) /* Line 191, Address: 0x102d698 */
      {
        d3 ^= 15; /* Line 193, Address: 0x102d6ac */
      }
      d2 = ((short*)pActwk)[28]; /* Line 195, Address: 0x102d6b8 */

      if ((long int)a6 == 1) d1 = emycol_l3(pActwk, d3, d2); /* Line 197, Address: 0x102d6c8 */
      else d1 = emycol_r3(pActwk, d3, d2); /* Line 198, Address: 0x102d700 */
      if (d1 < 0) break; /* Line 199, Address: 0x102d71c */
      if (((short*)pActwk)[27] < 2) /* Line 200, Address: 0x102d72c */
      {
        --((short*)pActwk)[27]; /* Line 202, Address: 0x102d748 */
        break; /* Line 203, Address: 0x102d758 */
      }
      --((short*)pActwk)[27]; /* Line 205, Address: 0x102d760 */
      pActwk->xposi.w.h += ((short*)pActwk)[25]; /* Line 206, Address: 0x102d770 */
    } while (1); /* Line 207, Address: 0x102d788 */
  }
  if (ridechk(pActwk, pPlayerwk)) /* Line 209, Address: 0x102d790 */
  {
    pPlayerwk->xposi.w.h = pActwk->xposi.w.h; /* Line 211, Address: 0x102d7a8 */
  }
} /* Line 213, Address: 0x102d7b4 */
