#include "..\EQU.H"
#include "TONBO.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\SUICIDE.H"
#include "PLAYSUB4.H"

static void act_init(sprite_status* pActwk);
static void act_lr(sprite_status* pActwk);

static unsigned char pchg0[4] = { 2, 0, 1, 255 };
static unsigned char pchg1[4] = { 4, 0, 2, 255 };
static unsigned char* pchg[2] =
{
  pchg0,
  pchg1
};
static sprite_pattern spr_tonbo_e_00 =
{
  1,
  { { -29, -17, 0, 476 } }
};
static sprite_pattern spr_tonbo_e_01 =
{
  1,
  { { -29, -13, 0, 477 } }
};
static sprite_pattern spr_tonbo_e_02 =
{
  1,
  { { -29, -17, 0, 478 } }
};
static sprite_pattern spr_tonbo_b_00 =
{
  1,
  { { -29, -17, 0, 473 } }
};
static sprite_pattern spr_tonbo_b_01 =
{
  1,
  { { -29, -13, 0, 474 } }
};
static sprite_pattern spr_tonbo_b_02 =
{
  1,
  { { -29, -17, 0, 475 } }
};
sprite_pattern* pat_tonbo_e[3] =
{
  &spr_tonbo_e_00,
  &spr_tonbo_e_01,
  &spr_tonbo_e_02
};
sprite_pattern* pat_tonbo_b[3] =
{
  &spr_tonbo_b_00,
  &spr_tonbo_b_01,
  &spr_tonbo_b_02
};























































































void tonbo(sprite_status* pActwk) { /* Line 148, Address: 0x101e480 */
  short temp;
  static void(*act_tbl[2])(sprite_status*) =
  {
    &act_init,
    &act_lr
  };

  if (enemy_suicide(pActwk)) return; /* Line 156, Address: 0x101e490 */
  act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 157, Address: 0x101e4a4 */
  actionsub(pActwk); /* Line 158, Address: 0x101e4e8 */
  temp = ((short*)pActwk)[33]; /* Line 159, Address: 0x101e4f4 */
  frameout_s00(pActwk, temp); /* Line 160, Address: 0x101e504 */
} /* Line 161, Address: 0x101e514 */



static void act_init(sprite_status* pActwk) { /* Line 165, Address: 0x101e530 */
  pActwk->r_no0 += 2; /* Line 166, Address: 0x101e538 */
  pActwk->actflg = 4; /* Line 167, Address: 0x101e548 */
  pActwk->colino = 44; /* Line 168, Address: 0x101e554 */
  pActwk->sprpri = 1; /* Line 169, Address: 0x101e560 */
  pActwk->sprhs = 28; /* Line 170, Address: 0x101e56c */
  pActwk->sprhsize = 28; /* Line 171, Address: 0x101e578 */
  pActwk->sprvsize = 16; /* Line 172, Address: 0x101e584 */
  pActwk->sproffset = 9238; /* Line 173, Address: 0x101e590 */
  ((short*)pActwk)[33] = pActwk->xposi.w.h; /* Line 174, Address: 0x101e59c */
  *(int*)&pActwk->actfree[0] = pActwk->yposi.l; /* Line 175, Address: 0x101e5ac */

  if (!pActwk->userflag.b.h) /* Line 177, Address: 0x101e5c0 */
  {
    pActwk->patbase = pat_tonbo_e; /* Line 179, Address: 0x101e5d0 */
    ((int*)pActwk)[13] = -65536; /* Line 180, Address: 0x101e5e0 */
    ((short*)pActwk)[28] = 4; /* Line 181, Address: 0x101e5ec */
    ((short*)pActwk)[30] = 256; /* Line 182, Address: 0x101e5f8 */
  } /* Line 183, Address: 0x101e604 */
  else
  {
    pActwk->patbase = pat_tonbo_b; /* Line 186, Address: 0x101e60c */
    ((int*)pActwk)[13] = -32768; /* Line 187, Address: 0x101e61c */
    ((short*)pActwk)[28] = 1; /* Line 188, Address: 0x101e628 */
    ((short*)pActwk)[30] = 512; /* Line 189, Address: 0x101e634 */
  }
  ((short*)pActwk)[29] = ((short*)pActwk)[30]; /* Line 191, Address: 0x101e640 */
  ((short*)pActwk)[29] >>= 1; /* Line 192, Address: 0x101e650 */
} /* Line 193, Address: 0x101e660 */



static void act_lr(sprite_status* pActwk) { /* Line 197, Address: 0x101e670 */
  short sin;
  short cos;
  int_union sinl;


  pActwk->xposi.l += ((int*)pActwk)[13]; /* Line 203, Address: 0x101e67c */
  sinset(pActwk->actfree[4], &sin, &cos); /* Line 204, Address: 0x101e694 */
  sinl.l = 0; /* Line 205, Address: 0x101e6ac */
  sinl.w.h = sin; /* Line 206, Address: 0x101e6b0 */



  sinl.l >>= 4; /* Line 210, Address: 0x101e6b8 */
  pActwk->yposi.l = *(int*)&pActwk->actfree[0] + sinl.l; /* Line 211, Address: 0x101e6c4 */

  ((short*)pActwk)[25] += ((short*)pActwk)[28]; /* Line 213, Address: 0x101e6e0 */

  --((short*)pActwk)[29]; /* Line 215, Address: 0x101e6f8 */
  if (!((short*)pActwk)[29]) /* Line 216, Address: 0x101e708 */
  {
    ((short*)pActwk)[29] = ((short*)pActwk)[30]; /* Line 218, Address: 0x101e718 */
    ((int*)pActwk)[13] *= -1; /* Line 219, Address: 0x101e728 */
    pActwk->actflg ^= 1; /* Line 220, Address: 0x101e738 */
    pActwk->cddat ^= 1; /* Line 221, Address: 0x101e748 */
  }

  patchg(pActwk, pchg); /* Line 224, Address: 0x101e758 */
} /* Line 225, Address: 0x101e76c */
