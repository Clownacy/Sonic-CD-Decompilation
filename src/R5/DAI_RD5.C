#include "..\EQU.H"
#include "DAI_RD5.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\ETC.H"
#include "..\RIDECHK.H"

static void dair5_init(sprite_status* pActwk);
static void dair5_move(sprite_status* pActwk);
static void type01(sprite_status* pActwk);
static void type02(sprite_status* pActwk);
static void type03(sprite_status* pActwk);
static void type04(sprite_status* pActwk);
static void type05(sprite_status* pActwk);
static void type06(sprite_status* pActwk);
static void type06_00(sprite_status* pActwk);
static void type06_01(sprite_status* pActwk);
static void type06_02(sprite_status* pActwk);
static void dodai_sub(sprite_status* pActwk, unsigned char d4);
static void dai5sub(sprite_status* pActwk);
static void banesetsub(sprite_status* pActwk, char d2);
static void belttask(sprite_status* pActwk);

static sprite_pattern pat00 =
{
  1,
  { { -16, -16, 0, 413 } }
};
static sprite_pattern pat01 =
{
  2,
  {
    { -16, -16, 0, 414 },
    { -16, -16, 0, 415 }
  }
};
static sprite_pattern pat02 =
{
  1,
  { { -32, -16, 0, 416 } }
};
static sprite_pattern pat03 =
{
  2,
  {
    { -32, -16, 0, 417 },
    { -32, -16, 0, 418 }
  }
};
static sprite_pattern pat04 =
{
  1,
  { { -48, -16, 0, 419 } }
};
static sprite_pattern pat05 =
{
  2,
  {
    { -48, -16, 0, 420 },
    { -48, -16, 0, 421 }
  }
};
sprite_pattern* dair5pat[6] =
{
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05
};















































void dair5(sprite_status* pActwk) { /* Line 120, Address: 0x101e690 */
  void(*tbl[2])(sprite_status*) = /* Line 121, Address: 0x101e69c */
  {
    &dair5_init,
    &dair5_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 127, Address: 0x101e6b8 */
  actionsub(pActwk); /* Line 128, Address: 0x101e6f4 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 129, Address: 0x101e700 */
} /* Line 130, Address: 0x101e714 */




static void dair5_init(sprite_status* pActwk) { /* Line 135, Address: 0x101e730 */
  unsigned char* a2;
  short d0;
  unsigned char bd0;
  unsigned char bd1;
  unsigned char ini_tbl[50] = /* Line 140, Address: 0x101e74c */
  {
    0, 16,
    1, 16,
    0, 16,
    0, 16,
    1, 16,
    0, 16,
    0, 16,
    2, 32,
    2, 32,
    3, 32,
    2, 32,
    3, 32,
    2, 32,
    3, 32,
    2, 32,
    2, 32,
    2, 32,
    4, 48,
    5, 48,
    4, 48,
    4, 48,
    5, 48,
    4, 48,
    4, 48,
    4, 48
  };



  unsigned char belt_flag[50] = /* Line 171, Address: 0x101e780 */
  {
      0,   1,   0,   0,   1,   0,   0,   0,   0,   1,
      0,   1,   0,   1,   0,   0,   0,   0,   1,   0,
      0,   1,   0,   0,   0,   0, 192, 192, 192, 192,
      0,   0,   0,  64,  64, 192, 192, 192, 192, 192,
      0,   0,   0,   0, 192, 192, 192, 192,   0,   0
  };



  unsigned char bane_flag[25] = /* Line 182, Address: 0x101e7b4 */
  {
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 2, 0, 0, 0, 0, 0,
    0, 0, 3, 0, 0
  };

  pActwk->r_no0 += 2; /* Line 189, Address: 0x101e7e0 */
  pActwk->actflg |= 4; /* Line 190, Address: 0x101e7f0 */
  pActwk->sprpri = 3; /* Line 191, Address: 0x101e800 */

  d0 = 17156; /* Line 193, Address: 0x101e80c */
  if (stageno.b.l == 2) /* Line 194, Address: 0x101e818 */
  {
    d0 = 17272; /* Line 196, Address: 0x101e834 */
  }
  pActwk->sproffset = d0; /* Line 198, Address: 0x101e840 */

  pActwk->patbase = dair5pat; /* Line 200, Address: 0x101e848 */
  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 201, Address: 0x101e858 */
  ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 202, Address: 0x101e868 */
  pActwk->sprvsize = 16; /* Line 203, Address: 0x101e878 */
  bd0 = 0; /* Line 204, Address: 0x101e884 */
  bd1 = 0; /* Line 205, Address: 0x101e888 */

  bd0 = pActwk->userflag.b.h; /* Line 207, Address: 0x101e88c */
  bd0 &= 31; /* Line 208, Address: 0x101e898 */
  bd1 = bd0; /* Line 209, Address: 0x101e8a0 */
  bd1 = bd1 + bd1; /* Line 210, Address: 0x101e8a4 */
  a2 = &ini_tbl[bd1]; /* Line 211, Address: 0x101e8b8 */
  pActwk->patno = *a2++; /* Line 212, Address: 0x101e8c4 */
  pActwk->sprhsize = *a2++; /* Line 213, Address: 0x101e8d8 */

  a2 = &belt_flag[bd0]; /* Line 215, Address: 0x101e8ec */
  pActwk->actfree[21] = *a2; /* Line 216, Address: 0x101e8f8 */

  a2 = &bane_flag[bd0]; /* Line 218, Address: 0x101e904 */
  bd1 = *a2; /* Line 219, Address: 0x101e910 */
  switch (bd1) { /* Line 220, Address: 0x101e918 */


    case 0:
      break;


    case 1:
      banesetsub(pActwk, 0); /* Line 228, Address: 0x101e950 */
      break; /* Line 229, Address: 0x101e960 */


    case 2:
      banesetsub(pActwk, -16); /* Line 233, Address: 0x101e968 */
      banesetsub(pActwk, 16); /* Line 234, Address: 0x101e978 */
      break; /* Line 235, Address: 0x101e988 */


    case 3:
      banesetsub(pActwk, -32); /* Line 239, Address: 0x101e990 */
      banesetsub(pActwk, 0); /* Line 240, Address: 0x101e9a0 */
      banesetsub(pActwk, 32); /* Line 241, Address: 0x101e9b0 */
      break;
  }





  dair5_move(pActwk); /* Line 249, Address: 0x101e9c0 */
} /* Line 250, Address: 0x101e9cc */




static void dair5_move(sprite_status* pActwk) { /* Line 255, Address: 0x101e9f0 */
  void(*tbl[25])(sprite_status*) = /* Line 256, Address: 0x101e9fc */
  {
    &type01,
    &type02,
    &type02,
    &type03,
    &type03,
    &type06,
    &type05,
    &type01,
    &type04,
    &type04,
    &type03,
    &type03,
    &type02,
    &type02,
    &type02,
    &type06,
    &type05,
    &type01,
    &type01,
    &type03,
    &type02,
    &type02,
    &type02,
    &type06,
    &type05,
  };



  tbl[pActwk->userflag.b.h & 31](pActwk); /* Line 287, Address: 0x101ea28 */
  dai5sub(pActwk); /* Line 288, Address: 0x101ea54 */
  belttask(pActwk); /* Line 289, Address: 0x101ea60 */
  ridechk(pActwk, &actwk[0]); /* Line 290, Address: 0x101ea6c */
} /* Line 291, Address: 0x101ea80 */





static void type01(sprite_status* pActwk) { /* Line 297, Address: 0x101ea90 */
  pActwk->actfree[21] |= 128; /* Line 298, Address: 0x101ea98 */
} /* Line 299, Address: 0x101eaa8 */




static void type02(sprite_status* pActwk) { /* Line 304, Address: 0x101eac0 */
  short d0;

  pActwk->actfree[21] |= 128; /* Line 307, Address: 0x101ead0 */
  ((short*)pActwk)[26] = 4; /* Line 308, Address: 0x101eae0 */
  dodai_sub(pActwk, 48); /* Line 309, Address: 0x101eaec */

  d0 = ((short*)pActwk)[25]; /* Line 311, Address: 0x101eafc */
  if (pActwk->userflag.b.h & 128) /* Line 312, Address: 0x101eb0c */
  {
    d0 *= -1; /* Line 314, Address: 0x101eb28 */
  }
  pActwk->xspeed.w = d0; /* Line 316, Address: 0x101eb34 */
  pActwk->xposi.l += d0 << 8; /* Line 317, Address: 0x101eb3c */
} /* Line 318, Address: 0x101eb58 */




static void type03(sprite_status* pActwk) { /* Line 323, Address: 0x101eb70 */
  int ld0;
  short d0;

  ((short*)pActwk)[26] = 4; /* Line 327, Address: 0x101eb84 */
  dodai_sub(pActwk, 48); /* Line 328, Address: 0x101eb90 */
  d0 = ((short*)pActwk)[25]; /* Line 329, Address: 0x101eba0 */
  if (pActwk->userflag.b.h & 128) /* Line 330, Address: 0x101ebb0 */
  {
    d0 *= -1; /* Line 332, Address: 0x101ebcc */
  }
  ld0 = d0; /* Line 334, Address: 0x101ebd8 */
  ld0 <<= 8; /* Line 335, Address: 0x101ebe0 */
  pActwk->yposi.l += ld0; /* Line 336, Address: 0x101ebe4 */
} /* Line 337, Address: 0x101ebf4 */




static void type04(sprite_status* pActwk) { /* Line 342, Address: 0x101ec10 */
  short d0;

  pActwk->actfree[21] |= 128; /* Line 345, Address: 0x101ec20 */
  ((short*)pActwk)[26] = 4; /* Line 346, Address: 0x101ec30 */
  dodai_sub(pActwk, 32); /* Line 347, Address: 0x101ec3c */

  d0 = ((short*)pActwk)[25]; /* Line 349, Address: 0x101ec4c */
  if (pActwk->userflag.b.h & 128) /* Line 350, Address: 0x101ec5c */
  {
    d0 *= -1; /* Line 352, Address: 0x101ec78 */
  }
  pActwk->xspeed.w = d0; /* Line 354, Address: 0x101ec84 */
  pActwk->xposi.l += d0 << 8; /* Line 355, Address: 0x101ec8c */
} /* Line 356, Address: 0x101eca8 */




static void type05(sprite_status* pActwk) { /* Line 361, Address: 0x101ecc0 */
  int ld0;
  short d0;

  if (pActwk->actfree[19] == 0) /* Line 365, Address: 0x101ecd4 */
  {
    pActwk->actfree[21] |= 128; /* Line 367, Address: 0x101ece8 */
    if (pActwk->cddat & 8) /* Line 368, Address: 0x101ecf8 */
    {
      pActwk->actfree[17] = 30; /* Line 370, Address: 0x101ed10 */
      pActwk->actfree[19] = 1; /* Line 371, Address: 0x101ed1c */
    }
  } /* Line 373, Address: 0x101ed28 */
  else
  {
    if (pActwk->actfree[17]) /* Line 376, Address: 0x101ed30 */
    {
      --pActwk->actfree[17]; /* Line 378, Address: 0x101ed40 */
      if (pActwk->actfree[17]) return; /* Line 379, Address: 0x101ed50 */
      pActwk->actfree[21] &= 127; /* Line 380, Address: 0x101ed60 */
    }
    pActwk->sprvsize = 16; /* Line 382, Address: 0x101ed70 */
    if (pActwk->yspeed.w >= 512) /* Line 383, Address: 0x101ed7c */
    {
      pActwk->sprvsize = 18; /* Line 385, Address: 0x101ed98 */
      if (pActwk->yspeed.w >= 768) /* Line 386, Address: 0x101eda4 */
      {
        pActwk->sprvsize = 20; /* Line 388, Address: 0x101edc0 */
      }
    }
    d0 = pActwk->yspeed.w; /* Line 391, Address: 0x101edcc */
    if (d0 < 1024) /* Line 392, Address: 0x101eddc */
    {
      pActwk->yspeed.w += 32; /* Line 394, Address: 0x101edf0 */
    }
    ld0 = pActwk->yspeed.w; /* Line 396, Address: 0x101ee00 */
    ld0 <<= 8; /* Line 397, Address: 0x101ee10 */
    pActwk->yposi.l += ld0; /* Line 398, Address: 0x101ee14 */
    d0 = scra_v_posit.w.h; /* Line 399, Address: 0x101ee24 */
    d0 += 224; /* Line 400, Address: 0x101ee34 */
    if (d0 < pActwk->yposi.w.h) /* Line 401, Address: 0x101ee40 */
    {
      ride_on_clr(pActwk, &actwk[0]); /* Line 403, Address: 0x101ee64 */
      frameout(pActwk); /* Line 404, Address: 0x101ee78 */
    }
  }
} /* Line 407, Address: 0x101ee84 */




static void type06(sprite_status* pActwk) { /* Line 412, Address: 0x101eea0 */
  void(*tbl[3])(sprite_status*) = /* Line 413, Address: 0x101eeac */
  {
    &type06_00,
    &type06_01,
    &type06_02
  };

  tbl[pActwk->actfree[19] / 2](pActwk); /* Line 420, Address: 0x101eed0 */
} /* Line 421, Address: 0x101ef0c */


static void type06_00(sprite_status* pActwk) { /* Line 424, Address: 0x101ef20 */
  pActwk->actfree[21] |= 128; /* Line 425, Address: 0x101ef2c */
  if (pActwk->cddat & 8) /* Line 426, Address: 0x101ef3c */
  {
    pActwk->actfree[19] += 2; /* Line 428, Address: 0x101ef54 */
    pActwk->actfree[17] = 30; /* Line 429, Address: 0x101ef64 */
    type06_01(pActwk); /* Line 430, Address: 0x101ef70 */
  }
} /* Line 432, Address: 0x101ef7c */


static void type06_01(sprite_status* pActwk) { /* Line 435, Address: 0x101ef90 */
  int stk;
  short d0, d1;

  if (pActwk->actfree[17]) /* Line 439, Address: 0x101efa8 */
  {
    --pActwk->actfree[17]; /* Line 441, Address: 0x101efb8 */
    if (pActwk->actfree[17]) return; /* Line 442, Address: 0x101efc8 */
    pActwk->actfree[21] &= 127; /* Line 443, Address: 0x101efd8 */
    pActwk->sprvsize = 14; /* Line 444, Address: 0x101efe8 */
  }
  d0 = pActwk->yspeed.w; /* Line 446, Address: 0x101eff4 */
  d0 -= 8; /* Line 447, Address: 0x101f004 */
  if (d0 < -768) /* Line 448, Address: 0x101f010 */
  {
    d0 = -768; /* Line 450, Address: 0x101f024 */
  }
  pActwk->yspeed.w = d0; /* Line 452, Address: 0x101f030 */
  speedset2(pActwk); /* Line 453, Address: 0x101f038 */
  stk = pActwk->yposi.l; /* Line 454, Address: 0x101f044 */
  pActwk->yposi.w.h -= 48; /* Line 455, Address: 0x101f04c */
  d1 = emycol_u(pActwk); /* Line 456, Address: 0x101f05c */
  pActwk->yposi.l = stk; /* Line 457, Address: 0x101f070 */
  if (d1 < 0) /* Line 458, Address: 0x101f078 */
  {
    pActwk->sprvsize = 16; /* Line 460, Address: 0x101f088 */
    pActwk->yspeed.w = 0; /* Line 461, Address: 0x101f094 */
    ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 462, Address: 0x101f09c */
    pActwk->actfree[21] |= 128; /* Line 463, Address: 0x101f0ac */
    pActwk->actfree[19] += 2; /* Line 464, Address: 0x101f0bc */
  }
} /* Line 466, Address: 0x101f0cc */


static void type06_02(sprite_status* pActwk) { /* Line 469, Address: 0x101f0f0 */

} /* Line 471, Address: 0x101f0f4 */




static void dodai_sub(sprite_status* pActwk, unsigned char d4) { /* Line 476, Address: 0x101f100 */
  short d0, d2;

  d2 = ((short*)pActwk)[26]; /* Line 479, Address: 0x101f114 */
  if (pActwk->actfree[18] == 0) /* Line 480, Address: 0x101f124 */
  {
    d0 = ((short*)pActwk)[25]; /* Line 482, Address: 0x101f138 */
    d0 += d2; /* Line 483, Address: 0x101f148 */
    ((short*)pActwk)[25] = d0; /* Line 484, Address: 0x101f154 */
    ((short*)pActwk)[24] += d0; /* Line 485, Address: 0x101f15c */
    if (d4 <= pActwk->actfree[3]) /* Line 486, Address: 0x101f16c */
    {
      pActwk->actfree[18] = 255; /* Line 488, Address: 0x101f18c */
    }
  } /* Line 490, Address: 0x101f198 */
  else
  {
    d0 = ((short*)pActwk)[25]; /* Line 493, Address: 0x101f1a0 */
    d0 -= d2; /* Line 494, Address: 0x101f1b0 */
    ((short*)pActwk)[25] = d0; /* Line 495, Address: 0x101f1bc */
    ((short*)pActwk)[24] += d0; /* Line 496, Address: 0x101f1c4 */
    if (d4 > pActwk->actfree[3]) /* Line 497, Address: 0x101f1d4 */
    {
      pActwk->actfree[18] = 0; /* Line 499, Address: 0x101f1f4 */
    }
  }
} /* Line 502, Address: 0x101f1fc */




static void dai5sub(sprite_status* pActwk) { /* Line 507, Address: 0x101f210 */
  int_union ld0;
  short d0, d1;

  if (pActwk->actfree[21] & 128) /* Line 511, Address: 0x101f21c */
  {
    if (!(pActwk->cddat & 8)) /* Line 513, Address: 0x101f234 */
    {
      if (pActwk->actfree[20] == 0) return; /* Line 515, Address: 0x101f24c */



      ((char*)pActwk)[66] -= 8; /* Line 519, Address: 0x101f260 */
    } /* Line 520, Address: 0x101f270 */
    else
    {
      if (pActwk->actfree[20] == 64) return; /* Line 523, Address: 0x101f278 */



      ((char*)pActwk)[66] += 8; /* Line 527, Address: 0x101f290 */
    }
    sinset(pActwk->actfree[20], &d0, &d1); /* Line 529, Address: 0x101f2a0 */
    d1 = 1024; /* Line 530, Address: 0x101f2b8 */
    ld0.l = d0 * d1; /* Line 531, Address: 0x101f2c0 */
    d0 = ld0.w.h; /* Line 532, Address: 0x101f2e0 */
    d0 += ((short*)pActwk)[27]; /* Line 533, Address: 0x101f2e8 */
    pActwk->yposi.w.h = d0; /* Line 534, Address: 0x101f2fc */
  }
} /* Line 536, Address: 0x101f308 */




static void banesetsub(sprite_status* pActwk, char d2) { /* Line 541, Address: 0x101f320 */
  sprite_status* pNewActwk;


  if (actwkchk2(pActwk, &pNewActwk) == 0) /* Line 545, Address: 0x101f330 */
  {
    pNewActwk->actno = 10; /* Line 547, Address: 0x101f348 */
    pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 548, Address: 0x101f354 */
    pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 549, Address: 0x101f364 */
    ((char*)pNewActwk)[60] = d2; /* Line 550, Address: 0x101f374 */
    ((char*)pNewActwk)[61] = -24; /* Line 551, Address: 0x101f380 */
    ((short*)pNewActwk)[28] = (unsigned short)(pActwk - actwk); /* Line 552, Address: 0x101f38c */
    pNewActwk->userflag.b.h = 2; /* Line 553, Address: 0x101f3c8 */
  }
} /* Line 555, Address: 0x101f3d4 */




static void belttask(sprite_status* pActwk) { /* Line 560, Address: 0x101f3f0 */
  sprite_status* pPlayerwk;
  int ld0;
  short d0;
  unsigned char bd1;

  if (!(pActwk->actfree[21] & 1)) return; /* Line 566, Address: 0x101f408 */
  if (!(pActwk->cddat & 8)) return; /* Line 567, Address: 0x101f420 */

  pPlayerwk = &actwk[0]; /* Line 569, Address: 0x101f438 */

  if (pPlayerwk->actno == 0) return; /* Line 571, Address: 0x101f440 */

  if (!(pPlayerwk->cddat & 8)) return; /* Line 573, Address: 0x101f450 */
  d0 = (unsigned short)pPlayerwk->actfree[19]; /* Line 574, Address: 0x101f464 */

  if (d0 != (short)(unsigned short)(pActwk - actwk)) return; /* Line 576, Address: 0x101f47c */

  bd1 = time_flag; /* Line 578, Address: 0x101f4c8 */
  ld0 = 32768; /* Line 579, Address: 0x101f4d4 */
  if (bd1) /* Line 580, Address: 0x101f4d8 */
  {
    ld0 = 65536; /* Line 582, Address: 0x101f4e0 */
    --bd1; /* Line 583, Address: 0x101f4e4 */
    if (bd1) /* Line 584, Address: 0x101f4ec */
    {
      ld0 = 131072; /* Line 586, Address: 0x101f4f4 */
    }
  }
  if (colrevflag) /* Line 589, Address: 0x101f4f8 */
  {
    ld0 = -ld0; /* Line 591, Address: 0x101f508 */
  }
  pPlayerwk->xposi.l += ld0; /* Line 593, Address: 0x101f50c */
} /* Line 594, Address: 0x101f518 */
