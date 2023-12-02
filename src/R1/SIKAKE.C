#include "..\EQU.H"
#include "SIKAKE.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DUMMY.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"

extern short playdamageset(act_info* pActwk, act_info* pColliAct);

static unsigned char tobita1chg0[16] = { 2, 0, 1, 0, 2, 0, 1, 0, 3, 4, 3, 5, 3, 4, 3, 255 };
static unsigned char tobita1chg1[9] = { 2, 0, 1, 0, 2, 0, 1, 0, 255 };
static unsigned char tobita1chg2[9] = { 2, 3, 4, 3, 5, 3, 4, 3, 255 };
static unsigned char tobitastop1[3] = { 0, 0, 255 };
static unsigned char tobitastop2[3] = { 0, 3, 255 };
unsigned char* tobita1chg[5] =
{
  tobita1chg0,
  tobita1chg1,
  tobita1chg2,
  tobitastop1,
  tobitastop2
};
static spr_array tobita_a =
{
  1,
  { { -8, -4, 0, 488 } }
};
static spr_array tobita_b =
{
  1,
  { { -8, -4, 0, 489 } }
};
static spr_array tobita_c =
{
  1,
  { { -8, -16, 0, 490 } }
};
static spr_array tobita_r_a =
{
  1,
  { { -24, -4, 0, 491 } }
};
static spr_array tobita_r_b =
{
  1,
  { { -24, -4, 0, 492 } }
};
static spr_array tobita_r_c =
{
  1,
  { { -24, -16, 0, 493 } }
};
spr_array* tobita1_pat[6] =
{
  &tobita_a,
  &tobita_b,
  &tobita_c,
  &tobita_r_a,
  &tobita_r_b,
  &tobita_r_c
};
static spr_array pat0 =
{
  1,
  { { -16, -16, 0, 494 } }
};
spr_array* hari12pat[1] = { &pat0 };





















































































short colli_pl_sikake_d(act_info* pActwk, act_info* pPlayerwk, short collinum) { /* Line 154, Address: 0x101e0d0 */
  if (editmode.b.h == 0) /* Line 155, Address: 0x101e0e4 */
  {
    if (pPlayerwk->r_no0 < 6) /* Line 157, Address: 0x101e0fc */
    {
      if (pPlayerwk->yspeed.w >= 0) /* Line 159, Address: 0x101e114 */
      {
        return colli_pl_sikake(pActwk, pPlayerwk, collinum); /* Line 161, Address: 0x101e12c */
      }
    }
  }
  pActwk->cddat &= 247; /* Line 165, Address: 0x101e148 */
  return 0; /* Line 166, Address: 0x101e158 */
} /* Line 167, Address: 0x101e15c */










short colli_pl_sikake(act_info* pActwk, act_info* pPlayerwk, short collnum) { /* Line 178, Address: 0x101e170 */
  short xe;
  short xe_w;
  short xp;
  short xp_w;
  short hp;
  short ye;
  short ye_w;
  short yp;
  short yp_w;
  short vp;
  short right, left;
  short up, down;
  char* pPs_colli;
  char ps_colli_tbl[32] = /* Line 192, Address: 0x101e1a4 */
  {
     16, -16,  16, -16,
     16, -16,   4,  -4,
      9,  -9,  56,  16,
      0, -24,   4,  -4,
      0, -24,  12,   0,
     24,   0,   4,  -4,
     24,   0,  12,   0,
     32, -32,  32, -32
  };




  collnum &= 7; /* Line 207, Address: 0x101e1d8 */
  collnum *= 4; /* Line 208, Address: 0x101e1e4 */
  pPs_colli = &ps_colli_tbl[collnum]; /* Line 209, Address: 0x101e1f0 */

  xe = pActwk->xposi.w.h; /* Line 211, Address: 0x101e204 */
  xp = pPlayerwk->xposi.w.h; /* Line 212, Address: 0x101e210 */
  hp = (char)pPlayerwk->sprhs; /* Line 213, Address: 0x101e21c */

  right = pPs_colli[0]; /* Line 215, Address: 0x101e238 */
  xe_w = xe; /* Line 216, Address: 0x101e248 */
  xp_w = xp; /* Line 217, Address: 0x101e254 */
  xe_w += right; /* Line 218, Address: 0x101e260 */
  xp_w += hp; /* Line 219, Address: 0x101e270 */
  if (xp_w - xe_w >= 0) goto label1; /* Line 220, Address: 0x101e280 */


  left = pPs_colli[1]; /* Line 223, Address: 0x101e29c */
  left = -left; /* Line 224, Address: 0x101e2b0 */
  xe_w = xe; /* Line 225, Address: 0x101e2bc */
  xp_w = xp; /* Line 226, Address: 0x101e2c8 */
  xe_w -= left; /* Line 227, Address: 0x101e2d4 */
  xp_w += hp; /* Line 228, Address: 0x101e2e0 */
  if (xe_w - xp_w >= 0) goto label1; /* Line 229, Address: 0x101e2f0 */


  ye = pActwk->yposi.w.h; /* Line 232, Address: 0x101e30c */
  yp = pPlayerwk->yposi.w.h; /* Line 233, Address: 0x101e318 */
  vp = (char)pPlayerwk->sprvsize; /* Line 234, Address: 0x101e328 */

  down = pPs_colli[2]; /* Line 236, Address: 0x101e348 */
  ye_w = ye; /* Line 237, Address: 0x101e358 */
  yp_w = ye_w; /* Line 238, Address: 0x101e364 */
  ye_w += down; /* Line 239, Address: 0x101e36c */
  yp_w -= vp; /* Line 240, Address: 0x101e37c */
  if (yp_w - ye_w >= 0) goto label1; /* Line 241, Address: 0x101e388 */


  up = pPs_colli[3]; /* Line 244, Address: 0x101e3a4 */
  up = -up; /* Line 245, Address: 0x101e3b8 */
  ye_w = ye; /* Line 246, Address: 0x101e3c4 */
  yp_w = yp; /* Line 247, Address: 0x101e3d0 */
  ye_w -= up; /* Line 248, Address: 0x101e3d8 */
  yp_w += vp; /* Line 249, Address: 0x101e3e4 */
  if (ye_w - yp_w >= 0) goto label1; /* Line 250, Address: 0x101e3f0 */



  pActwk->cddat |= 8; /* Line 254, Address: 0x101e40c */
  return -1; /* Line 255, Address: 0x101e41c */

label1:
  pActwk->cddat &= 247; /* Line 258, Address: 0x101e428 */
  return 0; /* Line 259, Address: 0x101e438 */
} /* Line 260, Address: 0x101e43c */
































void tobita1(act_info* pActwk) { /* Line 293, Address: 0x101e470 */
  void(*tobita_tbl[7])(act_info*) = /* Line 294, Address: 0x101e47c */
  {
    &tobita_init,
    &tobita_stop_r,
    &tobita_stop_l,
    &tobita_ride_r,
    &tobita_ride_l,
    &tobita_yure_r,
    &tobita_yure_l
  };

  tobita_tbl[pActwk->r_no0 / 2](pActwk); /* Line 305, Address: 0x101e4a8 */
  frameout_s(pActwk); /* Line 306, Address: 0x101e4e4 */
} /* Line 307, Address: 0x101e4f0 */




void tobita_init(act_info* pActwk) { /* Line 312, Address: 0x101e500 */
  unsigned char d0, d1;

  pActwk->patbase = tobita1_pat; /* Line 315, Address: 0x101e514 */
  pActwk->actflg |= 4; /* Line 316, Address: 0x101e524 */
  pActwk->sprpri = 3; /* Line 317, Address: 0x101e534 */
  pActwk->sprhsize = 16; /* Line 318, Address: 0x101e540 */
  pActwk->sprhs = 24; /* Line 319, Address: 0x101e54c */
  pActwk->sprvsize = 4; /* Line 320, Address: 0x101e558 */

  pa_set(pActwk, 7); /* Line 322, Address: 0x101e564 */

  d0 = 3; /* Line 324, Address: 0x101e574 */
  d1 = 2; /* Line 325, Address: 0x101e57c */

  if (pActwk->userflag.b.h) goto label1; /* Line 327, Address: 0x101e584 */
  if (!(pActwk->actflg & 1)) goto label2; /* Line 328, Address: 0x101e594 */
label1:
  d0 = 4; /* Line 330, Address: 0x101e5ac */
  d1 = 4; /* Line 331, Address: 0x101e5b4 */
  pActwk->actflg &= 254; /* Line 332, Address: 0x101e5bc */
  pActwk->cddat &= 254; /* Line 333, Address: 0x101e5cc */
label2:
  pActwk->mstno.b.h = d0; /* Line 335, Address: 0x101e5dc */
  pActwk->r_no0 = d1; /* Line 336, Address: 0x101e5e4 */
} /* Line 337, Address: 0x101e5ec */




void tobita_stop_r(act_info* pActwk) { /* Line 342, Address: 0x101e610 */
  act_info* pPlayerwk;
  int d0;
  int_union d1;
  short tmp;

  pPlayerwk = &actwk[0]; /* Line 348, Address: 0x101e628 */

  if (colli_pl_sikake_d(pActwk, pPlayerwk, 5)) /* Line 350, Address: 0x101e630 */
  {
    d0 = pActwk->yposi.l; /* Line 352, Address: 0x101e64c */
    d1.l = 0; /* Line 353, Address: 0x101e654 */
    d1.b.b4 = pPlayerwk->sprvsize; /* Line 354, Address: 0x101e658 */
    tmp = d1.w.l; /* Line 355, Address: 0x101e660 */
    d1.w.l = d1.w.h; /* Line 356, Address: 0x101e66c */
    d1.w.h = tmp; /* Line 357, Address: 0x101e674 */
    d0 -= d1.l; /* Line 358, Address: 0x101e678 */
    pPlayerwk->yposi.l = d0; /* Line 359, Address: 0x101e680 */
    pActwk->r_no0 = 10; /* Line 360, Address: 0x101e684 */
    pActwk->mstno.b.h = 3; /* Line 361, Address: 0x101e690 */
  }

  patchg(pActwk, tobita1chg); /* Line 364, Address: 0x101e69c */
  actionsub(pActwk); /* Line 365, Address: 0x101e6b0 */
} /* Line 366, Address: 0x101e6bc */




void tobita_stop_l(act_info* pActwk) { /* Line 371, Address: 0x101e6e0 */
  act_info* pPlayerwk;
  int d0;
  int_union d1;
  short tmp;

  pPlayerwk = &actwk[0]; /* Line 377, Address: 0x101e6f8 */

  if (colli_pl_sikake_d(pActwk, pPlayerwk, 3)) /* Line 379, Address: 0x101e700 */
  {
    d0 = pActwk->yposi.l; /* Line 381, Address: 0x101e71c */
    d1.l = 0; /* Line 382, Address: 0x101e724 */
    d1.b.b4 = pPlayerwk->sprvsize; /* Line 383, Address: 0x101e728 */
    tmp = d1.w.l; /* Line 384, Address: 0x101e730 */
    d1.w.l = d1.w.h; /* Line 385, Address: 0x101e73c */
    d1.w.h = tmp; /* Line 386, Address: 0x101e744 */
    d0 -= d1.l; /* Line 387, Address: 0x101e748 */
    pPlayerwk->yposi.l = d0; /* Line 388, Address: 0x101e750 */
    pActwk->r_no0 = 12; /* Line 389, Address: 0x101e754 */
    pActwk->mstno.b.h = 4; /* Line 390, Address: 0x101e760 */
  }

  patchg(pActwk, tobita1chg); /* Line 393, Address: 0x101e76c */
  actionsub(pActwk); /* Line 394, Address: 0x101e780 */
} /* Line 395, Address: 0x101e78c */




void tobita_ride_r(act_info* pActwk) { /* Line 400, Address: 0x101e7b0 */
  act_info* pPlayerwk;

  pPlayerwk = &actwk[0]; /* Line 403, Address: 0x101e7c0 */

  if (colli_pl_sikake_d(pActwk, pPlayerwk, 5) == 0) /* Line 405, Address: 0x101e7c8 */
  {
    pActwk->r_no0 = 2; /* Line 407, Address: 0x101e7ec */
    if (pPlayerwk->cddat & 2) pActwk->r_no0 = 10; /* Line 408, Address: 0x101e7f8 */
    if (pActwk->r_no0 == 10) pActwk->actfree[0] = 64; /* Line 409, Address: 0x101e818 */
  }

  patchg(pActwk, tobita1chg); /* Line 412, Address: 0x101e83c */
  actionsub(pActwk); /* Line 413, Address: 0x101e850 */
} /* Line 414, Address: 0x101e85c */




void tobita_ride_l(act_info* pActwk) { /* Line 419, Address: 0x101e870 */
  act_info* pPlayerwk;

  pPlayerwk = &actwk[0]; /* Line 422, Address: 0x101e880 */

  if (colli_pl_sikake_d(pActwk, pPlayerwk, 3) == 0) /* Line 424, Address: 0x101e888 */
  {
    pActwk->r_no0 = 4; /* Line 426, Address: 0x101e8ac */
    if (pPlayerwk->cddat & 2) pActwk->r_no0 = 12; /* Line 427, Address: 0x101e8b8 */
    if (pActwk->r_no0 == 12) pActwk->actfree[0] = 64; /* Line 428, Address: 0x101e8d8 */
  }

  patchg(pActwk, tobita1chg); /* Line 431, Address: 0x101e8fc */
  actionsub(pActwk); /* Line 432, Address: 0x101e910 */
} /* Line 433, Address: 0x101e91c */




void tobita_yure_r(act_info* pActwk) { /* Line 438, Address: 0x101e930 */
  act_info* pPlayerwk;
  int zflag;
  short d0;
  char cnt;

  pActwk->mstno.b.h = 1; /* Line 444, Address: 0x101e950 */

  pPlayerwk = &actwk[0]; /* Line 446, Address: 0x101e95c */

  if (colli_pl_sikake_d(pActwk, pPlayerwk, 6)) /* Line 448, Address: 0x101e964 */
  {
    d0 = pPlayerwk->yspeed.w; /* Line 450, Address: 0x101e980 */
    d0 += 256; /* Line 451, Address: 0x101e98c */
    if (d0 >= 2561) d0 = 2560; /* Line 452, Address: 0x101e998 */
    d0 = -d0; /* Line 453, Address: 0x101e9b8 */
    pPlayerwk->yspeed.w = d0; /* Line 454, Address: 0x101e9c4 */
    pActwk->actfree[0] = 64; /* Line 455, Address: 0x101e9c8 */
    zflag = (pPlayerwk->cddat & 2) ? 0 : 1; /* Line 456, Address: 0x101e9d4 */
    pPlayerwk->cddat |= 2; /* Line 457, Address: 0x101e9fc */
    if (zflag == 0) pPlayerwk->actfree[18] = 0; /* Line 458, Address: 0x101ea08 */
    pPlayerwk->cddat &= 223; /* Line 459, Address: 0x101ea14 */
    pPlayerwk->actfree[14] = 0; /* Line 460, Address: 0x101ea20 */

    pPlayerwk->sprvsize = 19; /* Line 462, Address: 0x101ea24 */
    pPlayerwk->sprhs = 9; /* Line 463, Address: 0x101ea2c */
    if ((pPlayerwk->cddat & 4) == 0) /* Line 464, Address: 0x101ea34 */
    {
      pPlayerwk->sprvsize = 14; /* Line 466, Address: 0x101ea48 */
      pPlayerwk->sprhs = 7; /* Line 467, Address: 0x101ea50 */
      pPlayerwk->yposi.w.h += 5; /* Line 468, Address: 0x101ea58 */
      pPlayerwk->cddat |= 4; /* Line 469, Address: 0x101ea64 */
      pPlayerwk->mstno.b.h = 2; /* Line 470, Address: 0x101ea70 */
    } /* Line 471, Address: 0x101ea78 */
    else
    {
      pPlayerwk->cddat |= 16; /* Line 474, Address: 0x101ea80 */
    }
  }

  cnt = pActwk->actfree[0]; /* Line 478, Address: 0x101ea8c */
  --cnt; /* Line 479, Address: 0x101ea9c */
  pActwk->actfree[0] = cnt; /* Line 480, Address: 0x101eaa8 */
  if (cnt == 0) /* Line 481, Address: 0x101eab0 */
  {
    pActwk->r_no0 = 2; /* Line 483, Address: 0x101eac0 */
    pActwk->mstno.b.h = 3; /* Line 484, Address: 0x101eacc */
    pActwk->actfree[0] = 64; /* Line 485, Address: 0x101ead8 */
  }

  patchg(pActwk, tobita1chg); /* Line 488, Address: 0x101eae4 */
  actionsub(pActwk); /* Line 489, Address: 0x101eaf8 */
} /* Line 490, Address: 0x101eb04 */




void tobita_yure_l(act_info* pActwk) { /* Line 495, Address: 0x101eb30 */
  act_info* pPlayerwk;
  int zflag;
  short d0;
  char cnt;

  pActwk->mstno.b.h = 2; /* Line 501, Address: 0x101eb50 */

  pPlayerwk = &actwk[0]; /* Line 503, Address: 0x101eb5c */

  if (colli_pl_sikake_d(pActwk, pPlayerwk, 4)) /* Line 505, Address: 0x101eb64 */
  {
    d0 = pPlayerwk->yspeed.w; /* Line 507, Address: 0x101eb80 */
    d0 += 256; /* Line 508, Address: 0x101eb8c */
    if (d0 >= 2561) d0 = 2560; /* Line 509, Address: 0x101eb98 */
    d0 = -d0; /* Line 510, Address: 0x101ebb8 */
    pPlayerwk->yspeed.w = d0; /* Line 511, Address: 0x101ebc4 */
    pActwk->actfree[0] = 64; /* Line 512, Address: 0x101ebc8 */
    zflag = (pPlayerwk->cddat & 2) ? 0 : 1; /* Line 513, Address: 0x101ebd4 */
    pPlayerwk->cddat |= 2; /* Line 514, Address: 0x101ebfc */
    if (zflag == 0) pPlayerwk->actfree[18] = 0; /* Line 515, Address: 0x101ec08 */
    pPlayerwk->cddat &= 223; /* Line 516, Address: 0x101ec14 */
    pPlayerwk->actfree[14] = 0; /* Line 517, Address: 0x101ec20 */

    pPlayerwk->sprvsize = 19; /* Line 519, Address: 0x101ec24 */
    pPlayerwk->sprhs = 9; /* Line 520, Address: 0x101ec2c */
    if ((pPlayerwk->cddat & 4) == 0) /* Line 521, Address: 0x101ec34 */
    {
      pPlayerwk->sprvsize = 14; /* Line 523, Address: 0x101ec48 */
      pPlayerwk->sprhs = 7; /* Line 524, Address: 0x101ec50 */
      pPlayerwk->yposi.w.h += 5; /* Line 525, Address: 0x101ec58 */
      pPlayerwk->cddat |= 4; /* Line 526, Address: 0x101ec64 */
      pPlayerwk->mstno.b.h = 2; /* Line 527, Address: 0x101ec70 */
    } /* Line 528, Address: 0x101ec78 */
    else
    {
      pPlayerwk->cddat |= 16; /* Line 531, Address: 0x101ec80 */
    }
  }

  cnt = pActwk->actfree[0]; /* Line 535, Address: 0x101ec8c */
  --cnt; /* Line 536, Address: 0x101ec9c */
  pActwk->actfree[0] = cnt; /* Line 537, Address: 0x101eca8 */
  if (cnt == 0) /* Line 538, Address: 0x101ecb0 */
  {
    pActwk->actfree[0] = 64; /* Line 540, Address: 0x101ecc0 */
    pActwk->r_no0 = 4; /* Line 541, Address: 0x101eccc */
    pActwk->mstno.b.h = 4; /* Line 542, Address: 0x101ecd8 */
  }

  patchg(pActwk, tobita1chg); /* Line 545, Address: 0x101ece4 */
  actionsub(pActwk); /* Line 546, Address: 0x101ecf8 */
} /* Line 547, Address: 0x101ed04 */










void hariyama(act_info* pActwk) { /* Line 558, Address: 0x101ed30 */
  void(*hari_tbl[2])(act_info*) = /* Line 559, Address: 0x101ed3c */
  {
    &hari_normal,
    0
  };

  hari_tbl[pActwk->r_no0 / 2]; /* Line 565, Address: 0x101ed58 */
} /* Line 566, Address: 0x101ed94 */




void hari_init(act_info* pActwk) { /* Line 571, Address: 0x101edb0 */
  pActwk->r_no0 += 2; /* Line 572, Address: 0x101edbc */
  pActwk->patbase = hari12pat; /* Line 573, Address: 0x101edcc */
  pActwk->actflg |= 4; /* Line 574, Address: 0x101eddc */
  pActwk->sprpri = 3; /* Line 575, Address: 0x101edec */
  pa_set(pActwk, 10); /* Line 576, Address: 0x101edf8 */
  pActwk->sprhsize = 16; /* Line 577, Address: 0x101ee08 */
  pActwk->sprvsize = 8; /* Line 578, Address: 0x101ee14 */

  if (pActwk->actflg & 2) /* Line 580, Address: 0x101ee20 */
  {
    pActwk->sprhsize = 18; /* Line 582, Address: 0x101ee38 */
    pActwk->colino = 131; /* Line 583, Address: 0x101ee44 */
  }
  hari_normal(pActwk); /* Line 585, Address: 0x101ee50 */
} /* Line 586, Address: 0x101ee5c */




void hari_normal(act_info* pActwk) { /* Line 591, Address: 0x101ee70 */
  act_info* pPlayerwk;
  short py;

  pPlayerwk = &actwk[0]; /* Line 595, Address: 0x101ee84 */
  py = pPlayerwk->yposi.w.h; /* Line 596, Address: 0x101ee8c */
  py -= pActwk->yposi.w.h; /* Line 597, Address: 0x101ee98 */
  if (py < 0) py = -py; /* Line 598, Address: 0x101eeac */
  if (py >= 32) goto label1; /* Line 599, Address: 0x101eec8 */
  if (pActwk->actflg & 2) /* Line 600, Address: 0x101eedc */
  {
    hitchk(pActwk, pPlayerwk); /* Line 602, Address: 0x101eef4 */
    goto label1; /* Line 603, Address: 0x101ef04 */
  }
  if (hitchk(pActwk, pPlayerwk) == 0) goto label1; /* Line 605, Address: 0x101ef0c */
  if (!(pActwk->cddat & 8)) goto label1; /* Line 606, Address: 0x101ef2c */

  if (plpower_a) goto label1; /* Line 608, Address: 0x101ef44 */
  if (plpower_m) goto label1; /* Line 609, Address: 0x101ef54 */

  if (pPlayerwk->r_no0 < 4) /* Line 611, Address: 0x101ef64 */
  {
    if (pPlayerwk->actfree[6] == 0) /* Line 613, Address: 0x101ef78 */
    {
      pPlayerwk->yposi.w.h -= pPlayerwk->yspeed.w; /* Line 615, Address: 0x101ef88 */
      playdamageset(pPlayerwk, pActwk); /* Line 616, Address: 0x101ef98 */
    }
  }
label1:
  actionsub(pActwk); /* Line 620, Address: 0x101efa8 */
  frameout_s(pActwk); /* Line 621, Address: 0x101efb4 */
} /* Line 622, Address: 0x101efc0 */
