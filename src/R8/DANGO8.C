#include "..\EQU.H"
#include "DANGO8.H"
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
unsigned char* pchg_e[6] = {
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
unsigned char* pchg_b[6] = {
  pat_chg_b00,
  pat_chg_b01,
  pat_chg_b02,
  pat_chg_b03,
  pat_chg_b04,
  pat_chg_b05
};
static sprite_pattern spr_dango_e_00 = {
  1,
  { { -16, -12, 0, 466 } }
};
static sprite_pattern spr_dango_e_01 = {
  1,
  { { -16, -12, 0, 467 } }
};
static sprite_pattern spr_dango_e_02 = {
  2,
  { {
    { -5, -12, 0, 471 },
    { -16, -16, 0, 474 }
  } }
};
static sprite_pattern spr_dango_e_03 = {
  2,
  { {
    { -4, -12, 0, 471 },
    { -16, -16, 0, 474 }
  } }
};
static sprite_pattern spr_dango_e_04 = {
  1,
  { { -16, -16, 0, 472 } }
};
static sprite_pattern spr_dango_e_05 = {
  1,
  { { -16, -15, 0, 473 } }
};
sprite_pattern* pat_dango_e[6] = {
  &spr_dango_e_00,
  &spr_dango_e_01,
  &spr_dango_e_02,
  &spr_dango_e_03,
  &spr_dango_e_04,
  &spr_dango_e_05
};
static sprite_pattern spr_dango_b_00 = {
  1,
  { { -16, -12, 0, 468 } }
};
static sprite_pattern spr_dango_b_01 = {
  1,
  { { -16, -12, 0, 469 } }
};
static sprite_pattern spr_dango_b_02 = {
  1,
  { { -16, -17, 0, 470 } }
};
static sprite_pattern spr_dango_b_03 = {
  2,
  { {
    { -4, -12, 0, 471 },
    { -16, -16, 0, 474 }
  } }
};
static sprite_pattern spr_dango_b_04 = {
  1,
  { { -16, -16, 0, 472 } }
};
static sprite_pattern spr_dango_b_05 = {
  1,
  { { -16, -15, 0, 473 } }
};
sprite_pattern* pat_dango_b[6] = {
  &spr_dango_b_00,
  &spr_dango_b_01,
  &spr_dango_b_02,
  &spr_dango_b_03,
  &spr_dango_b_04,
  &spr_dango_b_05
};



















































































































































void dango(sprite_status* pActwk) { /* Line 273, Address: 0x1025690 */
  void(*tbl[15])(sprite_status*) = /* Line 274, Address: 0x102569c */
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

  if (enemy_suicide(pActwk)) return; /* Line 293, Address: 0x10256c8 */
  tbl[pActwk->r_no0 / 2](pActwk); /* Line 294, Address: 0x10256dc */
  actionsub(pActwk); /* Line 295, Address: 0x1025718 */
  frameout_s(pActwk); /* Line 296, Address: 0x1025724 */
} /* Line 297, Address: 0x1025730 */



static void a_init(sprite_status* pActwk) { /* Line 301, Address: 0x1025740 */
  pActwk->r_no0 += 2; /* Line 302, Address: 0x1025748 */
  pActwk->actflg = 4; /* Line 303, Address: 0x1025758 */
  pActwk->sprpri = 3; /* Line 304, Address: 0x1025764 */
  pActwk->sprhs = 14; /* Line 305, Address: 0x1025770 */
  pActwk->sprhsize = 14; /* Line 306, Address: 0x102577c */
  pActwk->sprvsize = 9; /* Line 307, Address: 0x1025788 */
  pActwk->colino = 44; /* Line 308, Address: 0x1025794 */
  pActwk->sproffset = 9263; /* Line 309, Address: 0x10257a0 */
  if (!pActwk->userflag.b.h) /* Line 310, Address: 0x10257ac */
  {
    pActwk->patbase = pat_dango_e; /* Line 312, Address: 0x10257bc */
    *(int*)&pActwk->actfree[4] = 0; /* Line 313, Address: 0x10257cc */
  } /* Line 314, Address: 0x10257d8 */
  else
  {
    pActwk->patbase = pat_dango_b; /* Line 317, Address: 0x10257e0 */
    *(int*)&pActwk->actfree[4] = 1; /* Line 318, Address: 0x10257f0 */
  }
} /* Line 320, Address: 0x1025800 */



static void a_fall(sprite_status* pActwk) { /* Line 324, Address: 0x1025810 */
  short wD1;

  pActwk->yposi.l += 65536; /* Line 327, Address: 0x1025820 */
  wD1 = emycol_d(pActwk); /* Line 328, Address: 0x1025834 */
  if (wD1 < 0) /* Line 329, Address: 0x1025848 */
  {
    pActwk->yposi.w.h += wD1; /* Line 331, Address: 0x1025858 */
    pActwk->r_no0 += 2; /* Line 332, Address: 0x1025868 */
  }
} /* Line 334, Address: 0x1025878 */



static void a_walk(sprite_status* pActwk) { /* Line 338, Address: 0x1025890 */
  pActwk->r_no0 += 2; /* Line 339, Address: 0x102589c */
  a_speedset(24576, 4096, pActwk); /* Line 340, Address: 0x10258ac */
} /* Line 341, Address: 0x10258c0 */



static void a_walk1(sprite_status* pActwk) { /* Line 345, Address: 0x10258d0 */
  short wD0, wD1;

  if (!a_move(pActwk)) /* Line 348, Address: 0x10258e4 */
  {

    *(int*)&pActwk->actfree[0] *= -1; /* Line 351, Address: 0x10258f8 */


    pActwk->actflg ^= 1; /* Line 354, Address: 0x1025910 */
    pActwk->cddat ^= 1; /* Line 355, Address: 0x1025920 */
    return; /* Line 356, Address: 0x1025930 */
  }
  wD0 = actwk[0].xposi.w.h - pActwk->xposi.w.h; /* Line 358, Address: 0x1025938 */
  if (wD0 >= 0) /* Line 359, Address: 0x102596c */
    wD1 = 255; /* Line 360, Address: 0x102597c */
  else
    wD1 = 0; /* Line 362, Address: 0x1025990 */
  if ((unsigned short)(wD0 + 128) < 256) /* Line 363, Address: 0x1025994 */
  {
    wD0 = actwk[0].yposi.w.h - pActwk->yposi.w.h + 128; /* Line 365, Address: 0x10259b4 */
    if ((unsigned short)wD0 < 256) /* Line 366, Address: 0x10259ec */
    {
      if (pActwk->actflg & 1) /* Line 368, Address: 0x1025a00 */
        wD0 = 255; /* Line 369, Address: 0x1025a18 */
      else
        wD0 = 0; /* Line 371, Address: 0x1025a2c */
      if (!(wD0 ^ wD1)) /* Line 372, Address: 0x1025a30 */
        pActwk->r_no0 += 2; /* Line 373, Address: 0x1025a4c */
    }
  }
  a_patchg(pActwk); /* Line 376, Address: 0x1025a5c */
} /* Line 377, Address: 0x1025a68 */



static void a_patchg(sprite_status* pActwk) { /* Line 381, Address: 0x1025a80 */
  if (*(int*)&pActwk->actfree[4] == 0) /* Line 382, Address: 0x1025a8c */
    patchg(pActwk, pchg_e); /* Line 383, Address: 0x1025aa0 */
  else
    patchg(pActwk, pchg_b); /* Line 385, Address: 0x1025abc */
} /* Line 386, Address: 0x1025ad0 */



static void a_walk_stop(sprite_status* pActwk) { /* Line 390, Address: 0x1025ae0 */
  pActwk->r_no0 += 2; /* Line 391, Address: 0x1025ae8 */
  ++pActwk->mstno.b.h; /* Line 392, Address: 0x1025af8 */

} /* Line 394, Address: 0x1025b08 */



static void a_to_roll(sprite_status* pActwk) { /* Line 398, Address: 0x1025b20 */
  pActwk->r_no0 += 2; /* Line 399, Address: 0x1025b28 */
  ++pActwk->mstno.b.h; /* Line 400, Address: 0x1025b38 */
  pActwk->yposi.w.h -= 6; /* Line 401, Address: 0x1025b48 */
  pActwk->sprvsize = 16; /* Line 402, Address: 0x1025b58 */

} /* Line 404, Address: 0x1025b64 */



static void a_roll_stop(sprite_status* pActwk) { /* Line 408, Address: 0x1025b70 */
  pActwk->r_no0 += 2; /* Line 409, Address: 0x1025b78 */
  ++pActwk->mstno.b.h; /* Line 410, Address: 0x1025b88 */
  pActwk->yposi.w.h += 3; /* Line 411, Address: 0x1025b98 */
  pActwk->sprvsize = 13; /* Line 412, Address: 0x1025ba8 */
  pActwk->colino = 237; /* Line 413, Address: 0x1025bb4 */
  *(int*)&pActwk->actfree[0] = 0; /* Line 414, Address: 0x1025bc0 */

} /* Line 416, Address: 0x1025bcc */



static void a_roll(sprite_status* pActwk) { /* Line 420, Address: 0x1025be0 */
  pActwk->r_no0 += 2; /* Line 421, Address: 0x1025bec */
  ++pActwk->mstno.b.h; /* Line 422, Address: 0x1025bfc */
  a_speedset(0x40000, 65536, pActwk); /* Line 423, Address: 0x1025c0c */
} /* Line 424, Address: 0x1025c20 */



static void a_roll1(sprite_status* pActwk) { /* Line 428, Address: 0x1025c30 */
  short wD0, wD1, wD2, sin, cos;
  int lD0, lD1;

  if (!pActwk->colicnt) /* Line 432, Address: 0x1025c50 */
  {
    if (a_move(pActwk)) /* Line 434, Address: 0x1025c60 */
    {
      if (*(int*)&pActwk->actfree[4] == 0) /* Line 436, Address: 0x1025c74 */
        patchg(pActwk, pchg_e); /* Line 437, Address: 0x1025c88 */
      else
        patchg(pActwk, pchg_b); /* Line 439, Address: 0x1025ca4 */
    } /* Line 440, Address: 0x1025cb8 */
    else
    {

      pActwk->r_no0 += 2; /* Line 444, Address: 0x1025cc0 */
    }
  } /* Line 446, Address: 0x1025cd0 */
  else
  {

    wD1 = pActwk->xposi.w.h - actwk[0].xposi.w.h; /* Line 450, Address: 0x1025cd8 */
    wD2 = pActwk->yposi.w.h - actwk[0].yposi.w.h; /* Line 451, Address: 0x1025d0c */
    wD0 = atan_sonic(wD1, wD2); /* Line 452, Address: 0x1025d40 */
    sinset(wD0 & 255, &sin, &cos); /* Line 453, Address: 0x1025d58 */
    lD1 = cos * -1792; /* Line 454, Address: 0x1025d78 */
    lD1 >>= 8; /* Line 455, Address: 0x1025d90 */
    actwk[0].xspeed.w = (unsigned short)(long int)lD1; /* Line 456, Address: 0x1025d94 */
    lD0 = sin * -1792; /* Line 457, Address: 0x1025db0 */
    lD0 >>= 8; /* Line 458, Address: 0x1025dc8 */
    actwk[0].yspeed.w = (unsigned short)(long int)lD0; /* Line 459, Address: 0x1025dcc */
    actwk[0].cddat |= 2; /* Line 460, Address: 0x1025de8 */
    actwk[0].cddat &= 239; /* Line 461, Address: 0x1025dfc */
    actwk[0].cddat &= 223; /* Line 462, Address: 0x1025e10 */
    actwk[0].actfree[18] = 0; /* Line 463, Address: 0x1025e24 */

    pActwk->colicnt = 0; /* Line 465, Address: 0x1025e2c */
    lD1 &= 65535; /* Line 466, Address: 0x1025e34 */
    lD1 = -lD1; /* Line 467, Address: 0x1025e38 */
    lD1 <<= 8; /* Line 468, Address: 0x1025e3c */
    *(int*)&pActwk->actfree[0] = lD1; /* Line 469, Address: 0x1025e40 */
    pActwk->mstno.b.h = 4; /* Line 470, Address: 0x1025e4c */
    pActwk->r_no0 = 22; /* Line 471, Address: 0x1025e58 */
  }
} /* Line 473, Address: 0x1025e64 */



static void a_to_walk(sprite_status* pActwk) { /* Line 477, Address: 0x1025e90 */
  pActwk->r_no0 += 2; /* Line 478, Address: 0x1025e98 */
  ++pActwk->mstno.b.h; /* Line 479, Address: 0x1025ea8 */
  pActwk->yposi.w.h -= 3; /* Line 480, Address: 0x1025eb8 */
  pActwk->sprvsize = 16; /* Line 481, Address: 0x1025ec8 */
  pActwk->colino = 44; /* Line 482, Address: 0x1025ed4 */

} /* Line 484, Address: 0x1025ee0 */



static void a_to_walk1(sprite_status* pActwk) { /* Line 488, Address: 0x1025ef0 */
  pActwk->r_no0 = 4; /* Line 489, Address: 0x1025ef8 */
  pActwk->mstno.b.h = 0; /* Line 490, Address: 0x1025f04 */
  pActwk->yposi.w.h += 6; /* Line 491, Address: 0x1025f0c */
  pActwk->sprvsize = 9; /* Line 492, Address: 0x1025f1c */
} /* Line 493, Address: 0x1025f28 */



static void a_speedset(int new_speed, int old_speed, sprite_status* pActwk) { /* Line 497, Address: 0x1025f40 */
  if (pActwk->userflag.b.h) /* Line 498, Address: 0x1025f50 */
    new_speed = old_speed; /* Line 499, Address: 0x1025f60 */

  if (!(pActwk->actflg & 1)) /* Line 501, Address: 0x1025f68 */
    new_speed = -new_speed; /* Line 502, Address: 0x1025f80 */

  *(int*)&pActwk->actfree[0] = new_speed; /* Line 504, Address: 0x1025f8c */
} /* Line 505, Address: 0x1025f9c */



static short a_move(sprite_status* pActwk) { /* Line 509, Address: 0x1025fb0 */
  short temp1, temp2;
  short ret;

  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 513, Address: 0x1025fc8 */
  if ((long int)*(int*)&pActwk->actfree[0] >= 0) /* Line 514, Address: 0x1025fe4 */
    temp1 = emycol_r(pActwk, pActwk->sprhs); /* Line 515, Address: 0x1026000 */
  else
  {
    temp1 = emycol_l(pActwk, -(char)pActwk->sprhs); /* Line 518, Address: 0x1026024 */
  }
  if (temp1 >= 0) /* Line 520, Address: 0x1026058 */
  {
    temp1 = emycol_d(pActwk); /* Line 522, Address: 0x1026068 */
    temp2 = temp1 + 7; /* Line 523, Address: 0x102607c */
    if ((unsigned short)temp2 < 14) /* Line 524, Address: 0x1026098 */
    {
      pActwk->yposi.w.h += temp1; /* Line 526, Address: 0x10260ac */
      ret = -1; /* Line 527, Address: 0x10260bc */
    } /* Line 528, Address: 0x10260c8 */
    else
    {

      pActwk->xposi.l -= *(int*)&pActwk->actfree[0]; /* Line 532, Address: 0x10260d0 */
      ret = 0; /* Line 533, Address: 0x10260ec */
    }
  } /* Line 535, Address: 0x10260f0 */
  else
  {

    pActwk->xposi.l -= *(int*)&pActwk->actfree[0]; /* Line 539, Address: 0x10260f8 */
    ret = 0; /* Line 540, Address: 0x1026114 */
  }
  return ret; /* Line 542, Address: 0x1026118 */
} /* Line 543, Address: 0x102611c */
