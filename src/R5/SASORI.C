#include "..\EQU.H"
#include "SASORI.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static void body_init(sprite_status* pActwk);
static void init_sub(sprite_status* pActwk0, sprite_status* pActwk1);
static void body_fall(sprite_status* pActwk);
static void body_move(sprite_status* pActwk);
static void body_waita(sprite_status* pActwk);
static void body_waita1(sprite_status* pActwk);
static void body_waitb(sprite_status* pActwk);
static void body_waitb1(sprite_status* pActwk);
static void body_waitc(sprite_status* pActwk);
static void body_waitc1(sprite_status* pActwk);
static void body_waitd(sprite_status* pActwk);
static void body_waitd1(sprite_status* pActwk);

static sprite_pattern pat00 =
{
  3,
  { {
    { -21, -3, 0, 493 },
    { -24, -16, 0, 494 },
    { -32, -4, 0, 495 }
  } }
};
static sprite_pattern pat01 =
{
  3,
  { {
    { -25, -3, 0, 496 },
    { -24, -16, 0, 497 },
    { -28, -4, 0, 498 }
  } }
};
static sprite_pattern pat02 =
{
  3,
  { {
    { -23, -3, 0, 499 },
    { -24, -16, 0, 500 },
    { -31, -4, 0, 501 }
  } }
};
static sprite_pattern pat03 =
{
  3,
  { {
    { -24, -3, 0, 502 },
    { -24, -16, 0, 503 },
    { -30, -4, 0, 504 }
  } }
};
static sprite_pattern pat04 =
{
  1,
  { { -12, -8, 0, 505 } }
};
static sprite_pattern pat05 =
{
  1,
  { { -8, -8, 0, 506 } }
};
static sprite_pattern pat06 =
{
  1,
  { { -8, -8, 0, 507 } }
};
static sprite_pattern pat07 =
{
  1,
  { { -8, -8, 0, 508 } }
};
sprite_pattern* pat_sasori_e[2] =
{
  &pat00,
  &pat01
};
sprite_pattern* pat_sasori_b[2] =
{
  &pat02,
  &pat03
};
sprite_pattern* pat_tail[2] =
{
  &pat04,
  &pat05
};
static sprite_pattern* pat_tama[2] =
{
  &pat06,
  &pat07
};
static unsigned char pchg00[4] = { 29, 0, 1, 255 };
static unsigned char* pchg[1] = { pchg00 };
static unsigned char pchg_tama00[4] = { 1, 0, 1, 255 };
static unsigned char* pchg_tama[1] = { pchg_tama00 };




































































void sasori(sprite_status* pActwk) { /* Line 171, Address: 0x1025840 */
  sprite_status* pMainwk;

  void(*tbl[11])(sprite_status*) = /* Line 174, Address: 0x1025850 */
  {
    &body_init,
    &body_fall,
    &body_move,
    &body_waita,
    &body_waita1,
    &body_waitb,
    &body_waitb1,
    &body_waitc,
    &body_waitc1,
    &body_waitd,
    &body_waitd1
  };

  if (pActwk->userflag.b.l == 0) /* Line 189, Address: 0x102587c */
  {
    if (enemy_suicide(pActwk)) return; /* Line 191, Address: 0x1025894 */
    tbl[pActwk->r_no0 / 2](pActwk); /* Line 192, Address: 0x10258a8 */
    patchg(pActwk, pchg); /* Line 193, Address: 0x10258e4 */
    actionsub(pActwk); /* Line 194, Address: 0x10258f8 */
    frameout_s00(pActwk, ((short*)pActwk)[23]); /* Line 195, Address: 0x1025904 */
  } /* Line 196, Address: 0x1025918 */
  else
  {
    pMainwk = &actwk[((short*)pActwk)[23]]; /* Line 199, Address: 0x1025920 */
    if (pMainwk->actno != 33) /* Line 200, Address: 0x1025948 */
    {
      frameout(pActwk); /* Line 202, Address: 0x102595c */
      return; /* Line 203, Address: 0x1025968 */
    }
    if (!(pActwk->userflag.b.l & 128)) /* Line 205, Address: 0x1025970 */
    {
      actionsub(pActwk); /* Line 207, Address: 0x102598c */
      return; /* Line 208, Address: 0x1025998 */
    }

    pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 211, Address: 0x10259a0 */
    patchg(pActwk, pchg_tama); /* Line 212, Address: 0x10259b8 */
    actionsub(pActwk); /* Line 213, Address: 0x10259cc */
    frameout_s(pActwk); /* Line 214, Address: 0x10259d8 */
  }

} /* Line 217, Address: 0x10259e4 */




static void body_init(sprite_status* pActwk) { /* Line 222, Address: 0x1025a00 */
  pActwk->r_no0 += 2; /* Line 223, Address: 0x1025a08 */
  pActwk->sprpri = 3; /* Line 224, Address: 0x1025a18 */
  pActwk->sprhs = 24; /* Line 225, Address: 0x1025a24 */
  pActwk->sprhsize = 24; /* Line 226, Address: 0x1025a30 */
  pActwk->sprvsize = 12; /* Line 227, Address: 0x1025a3c */
  pActwk->colino = 49; /* Line 228, Address: 0x1025a48 */
  ((short*)pActwk)[23] = pActwk->xposi.w.h; /* Line 229, Address: 0x1025a54 */
  pActwk->patbase = pat_sasori_e; /* Line 230, Address: 0x1025a64 */
  ((int*)pActwk)[12] = -65536; /* Line 231, Address: 0x1025a74 */
  ((short*)pActwk)[27] = 3; /* Line 232, Address: 0x1025a80 */
  if (pActwk->userflag.b.h) /* Line 233, Address: 0x1025a8c */
  {
    pActwk->patbase = pat_sasori_b; /* Line 235, Address: 0x1025a9c */
    ((int*)pActwk)[12] = -32768; /* Line 236, Address: 0x1025aac */
    ((short*)pActwk)[27] = 7; /* Line 237, Address: 0x1025ab8 */
  }

  pActwk->actflg |= 4; /* Line 240, Address: 0x1025ac4 */
  pActwk->sproffset = 9142; /* Line 241, Address: 0x1025ad4 */
} /* Line 242, Address: 0x1025ae0 */




static void init_sub(sprite_status* pActwk0, sprite_status* pActwk1) { /* Line 247, Address: 0x1025af0 */
  pActwk1->actno = pActwk0->actno; /* Line 248, Address: 0x1025afc */
  pActwk1->xposi.w.h = pActwk0->xposi.w.h; /* Line 249, Address: 0x1025b0c */
  pActwk1->yposi.w.h = pActwk0->yposi.w.h; /* Line 250, Address: 0x1025b1c */
  pActwk1->sprpri = pActwk0->sprpri;  /* Line 251, Address: 0x1025b2c */
  ((short*)pActwk1)[23] = (unsigned short)(pActwk0 - actwk); /* Line 252, Address: 0x1025b3c */

  pActwk1->actflg |= 4; /* Line 254, Address: 0x1025b78 */
  pActwk1->sproffset = 9142; /* Line 255, Address: 0x1025b88 */
} /* Line 256, Address: 0x1025b94 */




static void body_fall(sprite_status* pActwk) { /* Line 261, Address: 0x1025ba0 */
  sprite_status* pNewActwk;
  short d1;

  ++pActwk->yposi.w.h; /* Line 265, Address: 0x1025bb0 */
  d1 = emycol_d(pActwk); /* Line 266, Address: 0x1025bc0 */
  if (d1 < 0) /* Line 267, Address: 0x1025bd4 */
  {
    pActwk->yposi.w.h += d1; /* Line 269, Address: 0x1025be4 */
    pActwk->r_no0 += 2; /* Line 270, Address: 0x1025bf4 */
    if (actwkchk2(pActwk, &pNewActwk) != 0) /* Line 271, Address: 0x1025c04 */
    {
      frameout(pActwk); /* Line 273, Address: 0x1025c1c */
      return; /* Line 274, Address: 0x1025c28 */
    }
    ((short*)pActwk)[26] = (unsigned short)(pNewActwk - actwk); /* Line 276, Address: 0x1025c30 */
    pNewActwk->userflag.b.l = 1; /* Line 277, Address: 0x1025c6c */
    pNewActwk->sprhs = 24; /* Line 278, Address: 0x1025c78 */
    pNewActwk->sprhsize = 24; /* Line 279, Address: 0x1025c84 */
    pNewActwk->sprvsize = 16; /* Line 280, Address: 0x1025c90 */
    pNewActwk->patbase = pat_tail; /* Line 281, Address: 0x1025c9c */
    pNewActwk->patno = pActwk->userflag.b.h; /* Line 282, Address: 0x1025cac */
    init_sub(pActwk, pNewActwk); /* Line 283, Address: 0x1025cbc */
    --pNewActwk->sprpri; /* Line 284, Address: 0x1025ccc */
  }
} /* Line 286, Address: 0x1025cdc */




static void body_move(sprite_status* pActwk) { /* Line 291, Address: 0x1025cf0 */
  sprite_status* pTailwk;
  sprite_status* pPlayerwk;
  short d0, d1;
  short carry_flag;
  unsigned char bd0, bd1;

  pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 298, Address: 0x1025d18 */
  d0 = pActwk->xposi.w.h; /* Line 299, Address: 0x1025d30 */
  d0 -= ((short*)pActwk)[23]; /* Line 300, Address: 0x1025d40 */
  if (d0 < 0) /* Line 301, Address: 0x1025d54 */
  {
    d0 *= -1; /* Line 303, Address: 0x1025d64 */
  }
  if (d0 >= 80) goto label1; /* Line 305, Address: 0x1025d70 */
  d1 = emycol_d(pActwk); /* Line 306, Address: 0x1025d84 */
  d0 = d1; /* Line 307, Address: 0x1025d98 */
  d0 += 7; /* Line 308, Address: 0x1025da0 */
  if ((unsigned short)d0 >= 14) goto label1; /* Line 309, Address: 0x1025dac */
  d0 -= 14; /* Line 310, Address: 0x1025dc0 */
  pActwk->yposi.w.h += d1; /* Line 311, Address: 0x1025dcc */
  pTailwk = &actwk[((short*)pActwk)[26]]; /* Line 312, Address: 0x1025ddc */
  pTailwk->xposi.w.h = pActwk->xposi.w.h; /* Line 313, Address: 0x1025e04 */
  pTailwk->yposi.w.h = pActwk->yposi.w.h; /* Line 314, Address: 0x1025e10 */
  pTailwk->xposi.w.h += ((short*)pActwk)[27]; /* Line 315, Address: 0x1025e1c */
  pTailwk->yposi.w.h -= 16; /* Line 316, Address: 0x1025e30 */
  pPlayerwk = &actwk[0]; /* Line 317, Address: 0x1025e3c */

  d0 = pPlayerwk->yposi.w.h; /* Line 319, Address: 0x1025e44 */
  d0 -= pActwk->yposi.w.h; /* Line 320, Address: 0x1025e50 */
  d0 += 40; /* Line 321, Address: 0x1025e64 */
  if ((unsigned short)d0 >= 80) /* Line 322, Address: 0x1025e70 */
  {
    carry_flag = 0; /* Line 324, Address: 0x1025e84 */
    d0 -= 80; /* Line 325, Address: 0x1025e88 */
  } /* Line 326, Address: 0x1025e94 */
  else
  {
    carry_flag = 1; /* Line 329, Address: 0x1025e9c */
    d0 = pPlayerwk->xposi.w.h; /* Line 330, Address: 0x1025ea8 */
    d0 -= pActwk->xposi.w.h; /* Line 331, Address: 0x1025eb4 */
    d1 = d0; /* Line 332, Address: 0x1025ec8 */
    d1 += 80; /* Line 333, Address: 0x1025ed0 */
    if ((unsigned short)d1 >= 160) /* Line 334, Address: 0x1025edc */
    {
      carry_flag = 0; /* Line 336, Address: 0x1025ef0 */
    } /* Line 337, Address: 0x1025ef4 */
    else
    {
      carry_flag = 1; /* Line 340, Address: 0x1025efc */
    }
  }

  if (carry_flag) /* Line 344, Address: 0x1025f08 */
  {
    pActwk->r_no0 += 2; /* Line 346, Address: 0x1025f10 */
    if (d0 < 0) bd0 = 255; /* Line 347, Address: 0x1025f20 */
    else bd0 = 0; /* Line 348, Address: 0x1025f40 */
    if ((long int)((int*)pActwk)[12] < 0) bd1 = 255; /* Line 349, Address: 0x1025f44 */
    else bd1 = 0; /* Line 350, Address: 0x1025f6c */
    bd0 ^= bd1; /* Line 351, Address: 0x1025f70 */
    if (bd0) goto label1; /* Line 352, Address: 0x1025f78 */
  }
  return; /* Line 354, Address: 0x1025f80 */
label1:
  pActwk->xposi.l -= ((int*)pActwk)[12]; /* Line 356, Address: 0x1025f88 */
  ((int*)pActwk)[12] *= -1; /* Line 357, Address: 0x1025fa0 */
  ((short*)pActwk)[27] *= -1; /* Line 358, Address: 0x1025fb0 */
  pTailwk = &actwk[((short*)pActwk)[26]]; /* Line 359, Address: 0x1025fc0 */
  pActwk->actflg ^= 1; /* Line 360, Address: 0x1025fe8 */
  pTailwk->actflg ^= 1; /* Line 361, Address: 0x1025ff8 */
  pActwk->cddat ^= 1; /* Line 362, Address: 0x1026004 */
  pTailwk->cddat ^= 1; /* Line 363, Address: 0x1026014 */
} /* Line 364, Address: 0x1026020 */




static void body_waita(sprite_status* pActwk) { /* Line 369, Address: 0x1026050 */
  sprite_status* pTailwk;

  pActwk->r_no0 += 2; /* Line 372, Address: 0x1026060 */
  ((short*)pActwk)[28] = 30; /* Line 373, Address: 0x1026070 */
  pTailwk = &actwk[((short*)pActwk)[26]]; /* Line 374, Address: 0x102607c */
  pTailwk->xposi.w.h = pActwk->xposi.w.h; /* Line 375, Address: 0x10260a4 */
  pTailwk->yposi.w.h = pActwk->yposi.w.h; /* Line 376, Address: 0x10260b0 */
  pTailwk->xposi.w.h += ((short*)pActwk)[27]; /* Line 377, Address: 0x10260bc */
  pTailwk->yposi.w.h -= 16; /* Line 378, Address: 0x10260d0 */

  body_waita1(pActwk); /* Line 380, Address: 0x10260dc */
} /* Line 381, Address: 0x10260e8 */




static void body_waita1(sprite_status* pActwk) { /* Line 386, Address: 0x1026100 */
  sprite_status* pTailwk;
  short d0;

  --((short*)pActwk)[28]; /* Line 390, Address: 0x1026110 */
  if (((short*)pActwk)[28] == 0) /* Line 391, Address: 0x1026120 */
  {
    pActwk->r_no0 += 2; /* Line 393, Address: 0x1026138 */
    pTailwk = &actwk[((short*)pActwk)[26]]; /* Line 394, Address: 0x1026148 */
    pTailwk->yposi.w.h -= 5; /* Line 395, Address: 0x1026170 */
    d0 = 5; /* Line 396, Address: 0x102617c */
    if ((long int)((int*)pActwk)[12] >= 0) /* Line 397, Address: 0x1026188 */
    {
      d0 *= -1; /* Line 399, Address: 0x10261a0 */
    }
    pTailwk->xposi.w.h += d0; /* Line 401, Address: 0x10261ac */
  }
} /* Line 403, Address: 0x10261b8 */




static void body_waitb(sprite_status* pActwk) { /* Line 408, Address: 0x10261d0 */
  pActwk->r_no0 += 2; /* Line 409, Address: 0x10261dc */
  ((short*)pActwk)[28] = 10; /* Line 410, Address: 0x10261ec */

  body_waitb1(pActwk); /* Line 412, Address: 0x10261f8 */
} /* Line 413, Address: 0x1026204 */




static void body_waitb1(sprite_status* pActwk) { /* Line 418, Address: 0x1026220 */
  sprite_status* pNewActwk;
  int d1;
  short d0;

  --((short*)pActwk)[28]; /* Line 423, Address: 0x1026234 */
  if (((short*)pActwk)[28] == 0) /* Line 424, Address: 0x1026244 */
  {
    pActwk->r_no0 += 2; /* Line 426, Address: 0x102625c */
    if (pActwk->userflag.b.h == 0) /* Line 427, Address: 0x102626c */
    {
      if (actwkchk(&pNewActwk) == 0) /* Line 429, Address: 0x1026284 */
      {
        pNewActwk->userflag.b.l = -1; /* Line 431, Address: 0x1026298 */
        pNewActwk->sprhs = 16; /* Line 432, Address: 0x10262a4 */
        pNewActwk->sprhsize = 16; /* Line 433, Address: 0x10262b0 */
        pNewActwk->sprvsize = 16; /* Line 434, Address: 0x10262bc */
        pNewActwk->colino = 178; /* Line 435, Address: 0x10262c8 */
        pNewActwk->patbase = pat_tama; /* Line 436, Address: 0x10262d4 */
        init_sub(pActwk, pNewActwk); /* Line 437, Address: 0x10262e4 */
        pNewActwk->yposi.w.h -= 24; /* Line 438, Address: 0x10262f4 */
        d0 = -4; /* Line 439, Address: 0x1026304 */
        d1 = -196608; /* Line 440, Address: 0x1026310 */
        if ((long int)((int*)pActwk)[12] >= 0) /* Line 441, Address: 0x1026314 */
        {
          d0 *= -1; /* Line 443, Address: 0x102632c */
          d1 *= -1; /* Line 444, Address: 0x1026338 */
        }
        pNewActwk->xposi.w.h += d0; /* Line 446, Address: 0x102633c */
        ((int*)pNewActwk)[12] = d1; /* Line 447, Address: 0x102634c */
        if (pActwk->actflg & 128) /* Line 448, Address: 0x1026354 */
        {
          soundset(160); /* Line 450, Address: 0x102636c */
        }
      }
    }
  }
} /* Line 455, Address: 0x1026378 */




static void body_waitc(sprite_status* pActwk) { /* Line 460, Address: 0x1026390 */
  pActwk->r_no0 += 2; /* Line 461, Address: 0x102639c */
  ((short*)pActwk)[28] = 30; /* Line 462, Address: 0x10263ac */

  body_waitc1(pActwk); /* Line 464, Address: 0x10263b8 */
} /* Line 465, Address: 0x10263c4 */




static void body_waitc1(sprite_status* pActwk) { /* Line 470, Address: 0x10263e0 */
  sprite_status* pTailwk;
  short d0;

  --((short*)pActwk)[28]; /* Line 474, Address: 0x10263f0 */
  if (((short*)pActwk)[28] == 0) /* Line 475, Address: 0x1026400 */
  {
    pActwk->r_no0 += 2; /* Line 477, Address: 0x1026418 */
    pTailwk = &actwk[((short*)pActwk)[26]]; /* Line 478, Address: 0x1026428 */
    pTailwk->yposi.w.h += 5; /* Line 479, Address: 0x1026450 */
    d0 = 5; /* Line 480, Address: 0x102645c */
    if ((long int)((int*)pActwk)[12] >= 0) /* Line 481, Address: 0x1026468 */
    {
      d0 *= -1; /* Line 483, Address: 0x1026480 */
    }
    pTailwk->xposi.w.h -= d0; /* Line 485, Address: 0x102648c */
  }
} /* Line 487, Address: 0x1026498 */




static void body_waitd(sprite_status* pActwk) { /* Line 492, Address: 0x10264b0 */
  pActwk->r_no0 += 2; /* Line 493, Address: 0x10264bc */
  ((short*)pActwk)[28] = 30; /* Line 494, Address: 0x10264cc */

  body_waitd1(pActwk); /* Line 496, Address: 0x10264d8 */
} /* Line 497, Address: 0x10264e4 */




static void body_waitd1(sprite_status* pActwk) { /* Line 502, Address: 0x1026500 */
  --((short*)pActwk)[28]; /* Line 503, Address: 0x1026508 */
  if (((short*)pActwk)[28] == 0) /* Line 504, Address: 0x1026518 */
  {
    pActwk->r_no0 = 4; /* Line 506, Address: 0x1026530 */
  }
} /* Line 508, Address: 0x102653c */
