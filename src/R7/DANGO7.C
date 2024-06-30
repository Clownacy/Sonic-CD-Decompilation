#include "..\EQU.H"
#include "DANGO7.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\ETC.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static void a_init(sprite_status* pActwk);
static void a_fall(sprite_status* pActwk);
static void a_walk(sprite_status* pActwk);
static void a_walk1(sprite_status* pActwk);
static void a_patchg(sprite_status* pActwk);
static void a_walk_stop(sprite_status* pActwk);
static void a_to_roll(sprite_status* pActwk);
static void a_roll_stop(sprite_status* pActwk);
static void a_roll(sprite_status* pActwk);
static void a_roll1(sprite_status* pActwk);
static void a_to_walk(sprite_status* pActwk);
static void a_to_walk1(sprite_status* pActwk);
static void a_speedset(int new_speed, int old_speed, sprite_status* pActwk);
static short a_move(sprite_status* pActwk);

static unsigned char pat_chg_e00[4] = { 9, 0, 1, 255 };
static unsigned char pat_chg_e01[3] = { 0, 0, 252 };
static unsigned char pat_chg_e02[5] = { 3, 4, 4, 5, 252 };
static unsigned char pat_chg_e03[8] = { 4, 2, 3, 2, 3, 2, 3, 252 };
static unsigned char pat_chg_e04[4] = { 4, 2, 3, 255 };
static unsigned char pat_chg_e05[5] = { 4, 5, 4, 4, 252 };
static unsigned char* pchg_e[6] =
{
  pat_chg_e00,
  pat_chg_e01,
  pat_chg_e02,
  pat_chg_e03,
  pat_chg_e04,
  pat_chg_e05
};
static unsigned char pat_chg_b00[4] = { 29, 0, 1, 255 };
static unsigned char pat_chg_b01[3] = { 59, 0, 252 };
static unsigned char pat_chg_b02[5] = { 9, 4, 4, 5, 252 };
static unsigned char pat_chg_b03[14] = { 9, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 252 };
static unsigned char pat_chg_b04[4] = { 9, 2, 3, 255 };
static unsigned char pat_chg_b05[5] = { 9, 5, 4, 4, 252 };
static unsigned char* pchg_b[6] =
{
  pat_chg_b00,
  pat_chg_b01,
  pat_chg_b02,
  pat_chg_b03,
  pat_chg_b04,
  pat_chg_b05
};
static sprite_pattern spr_dango_e_00 =
{
  1,
  { { -16, -12, 0, 494 } }
};
static sprite_pattern spr_dango_e_01 =
{
  1,
  { { -16, -12, 0, 495 } }
};
static sprite_pattern spr_dango_e_02 =
{
  1,
  { { -16, -16, 0, 496 } }
};
static sprite_pattern spr_dango_e_03 =
{
  1,
  { { -16, -16, 0, 500 } }
};
static sprite_pattern spr_dango_e_04 =
{
  1,
  { { -16, -16, 0, 501 } }
};
static sprite_pattern spr_dango_e_05 =
{
  1,
  { { -16, -15, 0, 502 } }
};
sprite_pattern* pat_dango_e[6] =
{
  &spr_dango_e_00,
  &spr_dango_e_01,
  &spr_dango_e_02,
  &spr_dango_e_03,
  &spr_dango_e_04,
  &spr_dango_e_05
};
static sprite_pattern spr_dango_b_00 =
{
  1,
  { { -16, -12, 0, 497 } }
};
static sprite_pattern spr_dango_b_01 =
{
  1,
  { { -16, -12, 0, 498 } }
};
static sprite_pattern spr_dango_b_02 =
{
  1,
  { { -16, -17, 0, 499 } }
};
static sprite_pattern spr_dango_b_03 =
{
  1,
  { { -16, -16, 0, 500 } }
};
static sprite_pattern spr_dango_b_04 =
{
  1,
  { { -16, -16, 0, 501 } }
};
static sprite_pattern spr_dango_b_05 =
{
  1,
  { { -16, -15, 0, 502 } }
};
sprite_pattern* pat_dango_b[6] =
{
  &spr_dango_b_00,
  &spr_dango_b_01,
  &spr_dango_b_02,
  &spr_dango_b_03,
  &spr_dango_b_04,
  &spr_dango_b_05
};









































































































































void dango(sprite_status* pActwk) { /* Line 270, Address: 0x10225d0 */
  void(*tbl[15])(sprite_status*) = /* Line 271, Address: 0x10225dc */
  {
    &a_init,
    &a_fall,
    &a_walk,
    &a_walk1,
    &a_walk_stop,
    &a_patchg,
    &a_to_roll,
    &a_patchg,
    &a_roll_stop,
    &a_roll1,
    &a_roll,
    &a_roll1,
    &a_to_walk,
    &a_patchg,
    &a_to_walk1
  };

  if (enemy_suicide(pActwk)) return; /* Line 290, Address: 0x1022608 */
  tbl[pActwk->r_no0 / 2](pActwk); /* Line 291, Address: 0x102261c */
  actionsub(pActwk); /* Line 292, Address: 0x1022658 */
  frameout_s(pActwk); /* Line 293, Address: 0x1022664 */
} /* Line 294, Address: 0x1022670 */



static void a_init(sprite_status* pActwk) { /* Line 298, Address: 0x1022680 */
  pActwk->r_no0 += 2; /* Line 299, Address: 0x1022688 */
  pActwk->actflg = 4; /* Line 300, Address: 0x1022698 */
  pActwk->sprpri = 3; /* Line 301, Address: 0x10226a4 */
  pActwk->sprhs = 14; /* Line 302, Address: 0x10226b0 */
  pActwk->sprhsize = 14; /* Line 303, Address: 0x10226bc */
  pActwk->sprvsize = 9; /* Line 304, Address: 0x10226c8 */
  pActwk->colino = 44; /* Line 305, Address: 0x10226d4 */
  if (time_flag) /* Line 306, Address: 0x10226e0 */
    pActwk->sproffset = 9309; /* Line 307, Address: 0x10226f0 */
  else
    pActwk->sproffset = 9193; /* Line 309, Address: 0x1022704 */
  if (!pActwk->userflag.b.h) /* Line 310, Address: 0x1022710 */
  {
    pActwk->patbase = pat_dango_e; /* Line 312, Address: 0x1022720 */
    *(int*)&pActwk->actfree[4] = 0; /* Line 313, Address: 0x1022730 */
  } /* Line 314, Address: 0x102273c */
  else
  {
    pActwk->patbase = pat_dango_b; /* Line 317, Address: 0x1022744 */
    *(int*)&pActwk->actfree[4] = 1; /* Line 318, Address: 0x1022754 */
  }
} /* Line 320, Address: 0x1022764 */



static void a_fall(sprite_status* pActwk) { /* Line 324, Address: 0x1022770 */
  short wD1;

  pActwk->yposi.l += 65536; /* Line 327, Address: 0x1022780 */
  wD1 = emycol_d(pActwk); /* Line 328, Address: 0x1022794 */
  if (wD1 < 0) /* Line 329, Address: 0x10227a8 */
  {
    pActwk->yposi.w.h += wD1; /* Line 331, Address: 0x10227b8 */
    pActwk->r_no0 += 2; /* Line 332, Address: 0x10227c8 */
  }
} /* Line 334, Address: 0x10227d8 */



static void a_walk(sprite_status* pActwk) { /* Line 338, Address: 0x10227f0 */
  pActwk->r_no0 += 2; /* Line 339, Address: 0x10227fc */
  a_speedset(24576, 4096, pActwk); /* Line 340, Address: 0x102280c */
} /* Line 341, Address: 0x1022820 */



static void a_walk1(sprite_status* pActwk) { /* Line 345, Address: 0x1022830 */
  short wD0, wD1;

  if (!a_move(pActwk)) /* Line 348, Address: 0x1022844 */
  {

    *(int*)&pActwk->actfree[0] *= -1; /* Line 351, Address: 0x1022858 */


    pActwk->actflg ^= 1; /* Line 354, Address: 0x1022870 */
    pActwk->cddat ^= 1; /* Line 355, Address: 0x1022880 */
    return; /* Line 356, Address: 0x1022890 */
  }
  wD0 = actwk[0].xposi.w.h - pActwk->xposi.w.h; /* Line 358, Address: 0x1022898 */
  if (wD0 >= 0) /* Line 359, Address: 0x10228cc */
    wD1 = 255; /* Line 360, Address: 0x10228dc */
  else
    wD1 = 0; /* Line 362, Address: 0x10228f0 */
  if ((unsigned short)(wD0 + 128) < 256) /* Line 363, Address: 0x10228f4 */
  {
    wD0 = actwk[0].yposi.w.h - pActwk->yposi.w.h + 128; /* Line 365, Address: 0x1022914 */
    if ((unsigned short)wD0 < 256) /* Line 366, Address: 0x102294c */
    {
      if (pActwk->actflg & 1) /* Line 368, Address: 0x1022960 */
        wD0 = 255; /* Line 369, Address: 0x1022978 */
      else
        wD0 = 0; /* Line 371, Address: 0x102298c */
      if (!(wD0 ^ wD1)) /* Line 372, Address: 0x1022990 */
        pActwk->r_no0 += 2; /* Line 373, Address: 0x10229ac */
    }
  }
  a_patchg(pActwk); /* Line 376, Address: 0x10229bc */
} /* Line 377, Address: 0x10229c8 */



static void a_patchg(sprite_status* pActwk) { /* Line 381, Address: 0x10229e0 */
  if (*(int*)&pActwk->actfree[4] == 0) /* Line 382, Address: 0x10229ec */
    patchg(pActwk, pchg_e); /* Line 383, Address: 0x1022a00 */
  else
    patchg(pActwk, pchg_b); /* Line 385, Address: 0x1022a1c */
} /* Line 386, Address: 0x1022a30 */



static void a_walk_stop(sprite_status* pActwk) { /* Line 390, Address: 0x1022a40 */
  pActwk->r_no0 += 2; /* Line 391, Address: 0x1022a48 */
  ++pActwk->mstno.b.h; /* Line 392, Address: 0x1022a58 */

} /* Line 394, Address: 0x1022a68 */



static void a_to_roll(sprite_status* pActwk) { /* Line 398, Address: 0x1022a80 */
  pActwk->r_no0 += 2; /* Line 399, Address: 0x1022a88 */
  ++pActwk->mstno.b.h; /* Line 400, Address: 0x1022a98 */
  pActwk->yposi.w.h -= 6; /* Line 401, Address: 0x1022aa8 */
  pActwk->sprvsize = 16; /* Line 402, Address: 0x1022ab8 */

} /* Line 404, Address: 0x1022ac4 */



static void a_roll_stop(sprite_status* pActwk) { /* Line 408, Address: 0x1022ad0 */
  pActwk->r_no0 += 2; /* Line 409, Address: 0x1022ad8 */
  ++pActwk->mstno.b.h; /* Line 410, Address: 0x1022ae8 */
  pActwk->yposi.w.h += 3; /* Line 411, Address: 0x1022af8 */
  pActwk->sprvsize = 13; /* Line 412, Address: 0x1022b08 */
  pActwk->colino = 237; /* Line 413, Address: 0x1022b14 */
  *(int*)&pActwk->actfree[0] = 0; /* Line 414, Address: 0x1022b20 */

} /* Line 416, Address: 0x1022b2c */



static void a_roll(sprite_status* pActwk) { /* Line 420, Address: 0x1022b40 */
  pActwk->r_no0 += 2; /* Line 421, Address: 0x1022b4c */
  ++pActwk->mstno.b.h; /* Line 422, Address: 0x1022b5c */
  a_speedset(262144, 65536, pActwk); /* Line 423, Address: 0x1022b6c */
} /* Line 424, Address: 0x1022b80 */



static void a_roll1(sprite_status* pActwk) { /* Line 428, Address: 0x1022b90 */
  short wD0, wD1, wD2, sin, cos;
  int lD0, lD1;

  if (!pActwk->colicnt) /* Line 432, Address: 0x1022bb0 */
  {
    if (a_move(pActwk)) /* Line 434, Address: 0x1022bc0 */
    {
      if (*(int*)&pActwk->actfree[4] == 0) /* Line 436, Address: 0x1022bd4 */
        patchg(pActwk, pchg_e); /* Line 437, Address: 0x1022be8 */
      else
        patchg(pActwk, pchg_b); /* Line 439, Address: 0x1022c04 */
    } /* Line 440, Address: 0x1022c18 */
    else
    {

      pActwk->r_no0 += 2; /* Line 444, Address: 0x1022c20 */
    }
  } /* Line 446, Address: 0x1022c30 */
  else
  {

    wD1 = pActwk->xposi.w.h - actwk[0].xposi.w.h; /* Line 450, Address: 0x1022c38 */
    wD2 = pActwk->yposi.w.h - actwk[0].yposi.w.h; /* Line 451, Address: 0x1022c6c */
    wD0 = atan_sonic(wD1, wD2); /* Line 452, Address: 0x1022ca0 */
    sinset(wD0 & 255, &sin, &cos); /* Line 453, Address: 0x1022cb8 */
    lD1 = cos * -1792; /* Line 454, Address: 0x1022cd8 */
    lD1 >>= 8; /* Line 455, Address: 0x1022cf0 */
    actwk[0].xspeed.w = (unsigned short)(long int)lD1; /* Line 456, Address: 0x1022cf4 */
    lD0 = sin * -1792; /* Line 457, Address: 0x1022d10 */
    lD0 >>= 8; /* Line 458, Address: 0x1022d28 */
    actwk[0].yspeed.w = (unsigned short)(long int)lD0; /* Line 459, Address: 0x1022d2c */
    actwk[0].cddat |= 2; /* Line 460, Address: 0x1022d48 */
    actwk[0].cddat &= 239; /* Line 461, Address: 0x1022d5c */
    actwk[0].cddat &= 223; /* Line 462, Address: 0x1022d70 */
    actwk[0].actfree[18] = 0; /* Line 463, Address: 0x1022d84 */

    pActwk->colicnt = 0; /* Line 465, Address: 0x1022d8c */
    wD1 = (unsigned short)((long int)lD1 & 65535); /* Line 466, Address: 0x1022d94 */
    wD1 *= -1; /* Line 467, Address: 0x1022db4 */
    lD1 = wD1; /* Line 468, Address: 0x1022dc0 */


    lD1 <<= 8; /* Line 471, Address: 0x1022dc8 */
    *(int*)&pActwk->actfree[0] = lD1; /* Line 472, Address: 0x1022dcc */
    pActwk->mstno.b.h = 4; /* Line 473, Address: 0x1022dd8 */
    pActwk->r_no0 = 22; /* Line 474, Address: 0x1022de4 */
  }
} /* Line 476, Address: 0x1022df0 */



static void a_to_walk(sprite_status* pActwk) { /* Line 480, Address: 0x1022e20 */
  pActwk->r_no0 += 2; /* Line 481, Address: 0x1022e28 */
  ++pActwk->mstno.b.h; /* Line 482, Address: 0x1022e38 */
  pActwk->yposi.w.h -= 3; /* Line 483, Address: 0x1022e48 */
  pActwk->sprvsize = 16; /* Line 484, Address: 0x1022e58 */
  pActwk->colino = 44; /* Line 485, Address: 0x1022e64 */

} /* Line 487, Address: 0x1022e70 */



static void a_to_walk1(sprite_status* pActwk) { /* Line 491, Address: 0x1022e80 */
  pActwk->r_no0 = 4; /* Line 492, Address: 0x1022e88 */
  pActwk->mstno.b.h = 0; /* Line 493, Address: 0x1022e94 */
  pActwk->yposi.w.h += 6; /* Line 494, Address: 0x1022e9c */
  pActwk->sprvsize = 9; /* Line 495, Address: 0x1022eac */
} /* Line 496, Address: 0x1022eb8 */



static void a_speedset(int new_speed, int old_speed, sprite_status* pActwk) { /* Line 500, Address: 0x1022ed0 */
  if (pActwk->userflag.b.h) /* Line 501, Address: 0x1022ee0 */
    new_speed = old_speed; /* Line 502, Address: 0x1022ef0 */

  if (!(pActwk->actflg & 1)) /* Line 504, Address: 0x1022ef8 */
    new_speed = -new_speed; /* Line 505, Address: 0x1022f10 */

  *(int*)&pActwk->actfree[0] = new_speed; /* Line 507, Address: 0x1022f1c */
} /* Line 508, Address: 0x1022f2c */



static short a_move(sprite_status* pActwk) { /* Line 512, Address: 0x1022f40 */
  short temp1, temp2;
  short ret;

  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 516, Address: 0x1022f58 */
  if ((long int)*(int*)&pActwk->actfree[0] >= 0) /* Line 517, Address: 0x1022f74 */
    temp1 = emycol_r(pActwk, pActwk->sprhs); /* Line 518, Address: 0x1022f90 */
  else
  {
    temp1 = emycol_l(pActwk, -(char)pActwk->sprhs); /* Line 521, Address: 0x1022fb4 */
  }
  if (temp1 >= 0) /* Line 523, Address: 0x1022fe8 */
  {
    temp1 = emycol_d(pActwk); /* Line 525, Address: 0x1022ff8 */
    temp2 = temp1 + 7; /* Line 526, Address: 0x102300c */
    if ((unsigned short)temp2 < 14) /* Line 527, Address: 0x1023028 */
    {
      pActwk->yposi.w.h += temp1; /* Line 529, Address: 0x102303c */
      ret = -1; /* Line 530, Address: 0x102304c */
    } /* Line 531, Address: 0x1023058 */
    else
    {

      pActwk->xposi.l -= *(int*)&pActwk->actfree[0]; /* Line 535, Address: 0x1023060 */
      ret = 0; /* Line 536, Address: 0x102307c */
    }
  } /* Line 538, Address: 0x1023080 */
  else
  {

    pActwk->xposi.l -= *(int*)&pActwk->actfree[0]; /* Line 542, Address: 0x1023088 */
    ret = 0; /* Line 543, Address: 0x10230a4 */
  }
  return ret; /* Line 545, Address: 0x10230a8 */
} /* Line 546, Address: 0x10230ac */
