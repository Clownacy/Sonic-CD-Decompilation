#include "..\EQU.H"
#include "TAGAMEB4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\SUICIDE.H"
#include "PLAYSUB4.H"

#if defined(R41A)
  #define SPRITE_TAGAMEB4_BASE 485
#elif defined(R41B)
  #define SPRITE_TAGAMEB4_BASE 446
#elif defined(R41C)
  #define SPRITE_TAGAMEB4_BASE 463
#elif defined(R41D)
  #define SPRITE_TAGAMEB4_BASE 453
#elif defined(R41A)
  #define SPRITE_TAGAMEB4_BASE 491
#elif defined(R41B)
  #define SPRITE_TAGAMEB4_BASE 444
#else
  #define SPRITE_TAGAMEB4_BASE 448
#endif

static void tagameb0(sprite_status* pActwk);
static void a_init(sprite_status* pActwk);
static void make_toge(sprite_status* pActwk);
static void a_init_sub(short subact, sprite_status* pActwk);
static void a_move(sprite_status* pActwk);
static int a_check(sprite_status* pActwk);
static void a_stop(sprite_status* pActwk);
static void a_stop1(sprite_status* pActwk);
static void a_dash(sprite_status* pActwk);
static void tagameb1(sprite_status* pActwk);
static void b_init(sprite_status* pActwk);
static void b_follow(sprite_status* pActwk);
static void b_move(sprite_status* pActwk);

static unsigned char pchg0[4] = { 30, 0, 1, 255 };
static unsigned char* pchg[1] = { pchg0 };
static sprite_pattern spr_tagame_b_00 =
{
  1,
  { { -20, -12, 0, SPRITE_TAGAMEB4_BASE } }
};
static sprite_pattern spr_tagame_b_01 =
{
  1,
  { { -20, -12, 0, SPRITE_TAGAMEB4_BASE + 1 } }
};
static sprite_pattern spr_tagame_e_00 =
{
  1,
  { { -20, -12, 0, SPRITE_TAGAMEB4_BASE + 2 } }
};
static sprite_pattern spr_tagame_e_01 =
{
  1,
  { { -20, -12, 0, SPRITE_TAGAMEB4_BASE + 3 } }
};
static sprite_pattern spr_tagame_99 =
{
  1,
  { { 0, 0, 0, SPRITE_TAGAMEB4_BASE + 4 } }
};
sprite_pattern* pat_tagameb_b[2] =
{
  &spr_tagame_b_00,
  &spr_tagame_b_01
};
sprite_pattern* pat_tagameb_e[2] =
{
  &spr_tagame_e_00,
  &spr_tagame_e_01
};
static sprite_pattern* pat[1] = { &spr_tagame_99 };

































































































void tagameb(sprite_status* pActwk) { /* Line 174, Address: 0x101f2d0 */
  if (pActwk->userflag.b.h >= 0) /* Line 175, Address: 0x101f2dc */
    tagameb0(pActwk); /* Line 176, Address: 0x101f2f4 */
  else
    tagameb1(pActwk); /* Line 178, Address: 0x101f308 */
} /* Line 179, Address: 0x101f314 */




static void tagameb0(sprite_status* pActwk) { /* Line 184, Address: 0x101f330 */
  static void(*tbl[5])(sprite_status*) =
  {
    &a_init,
    &a_move,
    &a_stop,
    &a_stop1,
    &a_dash
  };

  if (enemy_suicide(pActwk)) return; /* Line 194, Address: 0x101f33c */
  tbl[pActwk->r_no0 / 2](pActwk); /* Line 195, Address: 0x101f350 */
  actionsub(pActwk); /* Line 196, Address: 0x101f394 */
  frameout_s(pActwk); /* Line 197, Address: 0x101f3a0 */
} /* Line 198, Address: 0x101f3ac */



static void a_init(sprite_status* pActwk) { /* Line 202, Address: 0x101f3c0 */
  ((short*)pActwk)[30] = pActwk->xposi.w.h; /* Line 203, Address: 0x101f3cc */
  pActwk->actflg |= 4; /* Line 204, Address: 0x101f3dc */
  pActwk->sprpri = 3; /* Line 205, Address: 0x101f3ec */
  pActwk->sproffset = 9168; /* Line 206, Address: 0x101f3f8 */
  pActwk->sprhs = 20; /* Line 207, Address: 0x101f404 */
  pActwk->sprhsize = 20; /* Line 208, Address: 0x101f410 */
  pActwk->sprvsize = 8; /* Line 209, Address: 0x101f41c */
  pActwk->colino = 45; /* Line 210, Address: 0x101f428 */
  pActwk->r_no0 += 2; /* Line 211, Address: 0x101f434 */

  if (!pActwk->userflag.b.h) /* Line 213, Address: 0x101f444 */
  {
    pActwk->patbase = pat_tagameb_e; /* Line 215, Address: 0x101f454 */
    ((int*)pActwk)[12] = -65536; /* Line 216, Address: 0x101f464 */
    ((short*)pActwk)[29] = 200; /* Line 217, Address: 0x101f470 */
  } /* Line 218, Address: 0x101f47c */
  else
  {
    pActwk->patbase = pat_tagameb_b; /* Line 221, Address: 0x101f484 */
    ((int*)pActwk)[12] = -32768; /* Line 222, Address: 0x101f494 */
    ((short*)pActwk)[29] = 400; /* Line 223, Address: 0x101f4a0 */
    return; /* Line 224, Address: 0x101f4ac */
  }
  make_toge(pActwk); /* Line 226, Address: 0x101f4b4 */
} /* Line 227, Address: 0x101f4c0 */


static void make_toge(sprite_status* pActwk) { /* Line 230, Address: 0x101f4d0 */
  sprite_status* subActwk;

  if (actwkchk(&subActwk) == 0) /* Line 233, Address: 0x101f4dc */
  {
    subActwk->actno = pActwk->actno; /* Line 235, Address: 0x101f4f0 */
    subActwk->userflag.b.h = -1; /* Line 236, Address: 0x101f500 */
    subActwk->actfree[19] = pActwk->cdsts; /* Line 237, Address: 0x101f50c */
    ((short*)subActwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 238, Address: 0x101f51c */
    ((short*)pActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 239, Address: 0x101f55c */
  } /* Line 240, Address: 0x101f59c */
  else
  {
    frameout(pActwk); /* Line 243, Address: 0x101f5a4 */
    return; /* Line 244, Address: 0x101f5b0 */
  }
  if (actwkchk(&subActwk) == 0) /* Line 246, Address: 0x101f5b8 */
  {
    subActwk->actno = pActwk->actno; /* Line 248, Address: 0x101f5cc */
    subActwk->userflag.b.h = -1; /* Line 249, Address: 0x101f5dc */
    subActwk->actfree[19] = pActwk->cdsts; /* Line 250, Address: 0x101f5e8 */
    ((short*)subActwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 251, Address: 0x101f5f8 */
    ((short*)pActwk)[27] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 252, Address: 0x101f638 */
  } /* Line 253, Address: 0x101f678 */
  else
  {
    frameout(pActwk); /* Line 256, Address: 0x101f680 */
    return; /* Line 257, Address: 0x101f68c */
  }
  if (actwkchk(&subActwk) == 0) /* Line 259, Address: 0x101f694 */
  {
    subActwk->actno = pActwk->actno; /* Line 261, Address: 0x101f6a8 */
    subActwk->userflag.b.h = -1; /* Line 262, Address: 0x101f6b8 */
    subActwk->actfree[19] = pActwk->cdsts; /* Line 263, Address: 0x101f6c4 */
    ((short*)subActwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 264, Address: 0x101f6d4 */
    ((short*)pActwk)[28] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 265, Address: 0x101f714 */
  } /* Line 266, Address: 0x101f754 */
  else
  {
    frameout(pActwk); /* Line 269, Address: 0x101f75c */
    return; /* Line 270, Address: 0x101f768 */
  }

  a_init_sub(((short*)pActwk)[26], pActwk); /* Line 273, Address: 0x101f770 */
  actwk[((short*)pActwk)[26]].xposi.w.h += 2; /* Line 274, Address: 0x101f784 */
  actwk[((short*)pActwk)[26]].yposi.w.h -= 10; /* Line 275, Address: 0x101f7b8 */
  a_init_sub(((short*)pActwk)[27], pActwk); /* Line 276, Address: 0x101f7ec */
  actwk[((short*)pActwk)[27]].xposi.w.h -= 3; /* Line 277, Address: 0x101f800 */
  actwk[((short*)pActwk)[27]].yposi.w.h -= 10; /* Line 278, Address: 0x101f834 */
  a_init_sub(((short*)pActwk)[28], pActwk); /* Line 279, Address: 0x101f868 */
  actwk[((short*)pActwk)[28]].xposi.w.h -= 7; /* Line 280, Address: 0x101f87c */
  actwk[((short*)pActwk)[28]].yposi.w.h -= 9; /* Line 281, Address: 0x101f8b0 */
} /* Line 282, Address: 0x101f8e4 */


static void a_init_sub(short subact, sprite_status* pActwk) { /* Line 285, Address: 0x101f900 */
  actwk[subact].xposi.w.h = pActwk->xposi.w.h; /* Line 286, Address: 0x101f90c */
  actwk[subact].yposi.w.h = pActwk->yposi.w.h; /* Line 287, Address: 0x101f93c */
  actwk[subact].actflg |= 4; /* Line 288, Address: 0x101f96c */
  actwk[subact].sproffset = 9168; /* Line 289, Address: 0x101f99c */
  actwk[subact].sprpri = 3; /* Line 290, Address: 0x101f9c8 */
  actwk[subact].sprhs = 2; /* Line 291, Address: 0x101f9f4 */
  actwk[subact].sprhsize = 2; /* Line 292, Address: 0x101fa20 */
  actwk[subact].sprvsize = 2; /* Line 293, Address: 0x101fa4c */
} /* Line 294, Address: 0x101fa78 */



static void a_move(sprite_status* pActwk) { /* Line 298, Address: 0x101fa90 */
  if (!pActwk->userflag.b.h) /* Line 299, Address: 0x101fa9c */
  {
    if (a_check(pActwk) != 0) /* Line 301, Address: 0x101faac */
    {

      pActwk->r_no0 += 2; /* Line 304, Address: 0x101fac0 */
      ((short*)pActwk)[23] = 60; /* Line 305, Address: 0x101fad0 */
      return; /* Line 306, Address: 0x101fadc */
    }
  }

  pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 310, Address: 0x101fae4 */

  if (!pActwk->userflag.b.h) /* Line 312, Address: 0x101fafc */
  {
    actwk[((short*)pActwk)[26]].xposi.l += ((int*)pActwk)[12]; /* Line 314, Address: 0x101fb0c */
    actwk[((short*)pActwk)[27]].xposi.l += ((int*)pActwk)[12]; /* Line 315, Address: 0x101fb48 */
    actwk[((short*)pActwk)[28]].xposi.l += ((int*)pActwk)[12]; /* Line 316, Address: 0x101fb84 */
  }

  --((short*)pActwk)[23]; /* Line 319, Address: 0x101fbc0 */
  if (((short*)pActwk)[23] < 0) /* Line 320, Address: 0x101fbd0 */
  {
    ((short*)pActwk)[23] = ((short*)pActwk)[29]; /* Line 322, Address: 0x101fbe8 */
    ((int*)pActwk)[12] *= -1; /* Line 323, Address: 0x101fbf8 */
    pActwk->actflg ^= 1; /* Line 324, Address: 0x101fc08 */
    pActwk->cddat ^= 1; /* Line 325, Address: 0x101fc18 */

    if (!pActwk->userflag.b.h) /* Line 327, Address: 0x101fc28 */
    {
      actwk[((short*)pActwk)[26]].xposi.w.h = pActwk->xposi.w.h; /* Line 329, Address: 0x101fc38 */
      actwk[((short*)pActwk)[27]].xposi.w.h = pActwk->xposi.w.h; /* Line 330, Address: 0x101fc6c */
      actwk[((short*)pActwk)[28]].xposi.w.h = pActwk->xposi.w.h; /* Line 331, Address: 0x101fca0 */
      if (!(pActwk->actflg & 1)) /* Line 332, Address: 0x101fcd4 */
      {
        actwk[((short*)pActwk)[26]].xposi.w.h -= 2; /* Line 334, Address: 0x101fcec */
        actwk[((short*)pActwk)[27]].xposi.w.h += 3; /* Line 335, Address: 0x101fd20 */
        actwk[((short*)pActwk)[28]].xposi.w.h += 7; /* Line 336, Address: 0x101fd54 */
      } /* Line 337, Address: 0x101fd88 */
      else
      {
        actwk[((short*)pActwk)[26]].xposi.w.h -= 1; /* Line 340, Address: 0x101fd90 */
        actwk[((short*)pActwk)[27]].xposi.w.h -= 6; /* Line 341, Address: 0x101fdc4 */
        actwk[((short*)pActwk)[28]].xposi.w.h -= 10; /* Line 342, Address: 0x101fdf8 */
      }
    }
  }

  patchg(pActwk, pchg); /* Line 347, Address: 0x101fe2c */
} /* Line 348, Address: 0x101fe40 */


static int a_check(sprite_status* pActwk) { /* Line 351, Address: 0x101fe50 */
  short wD0;
  int ret;



  ret = 0; /* Line 357, Address: 0x101fe60 */

  wD0 = actwk[0].yposi.w.h - pActwk->yposi.w.h; /* Line 359, Address: 0x101fe64 */
  if (wD0 < 0) /* Line 360, Address: 0x101fe9c */
  {
    wD0 = actwk[0].xposi.w.h - pActwk->xposi.w.h; /* Line 362, Address: 0x101feac */
    if (!(pActwk->actflg & 1)) /* Line 363, Address: 0x101fee0 */
      wD0 *= -1; /* Line 364, Address: 0x101fef8 */
    wD0 += 80; /* Line 365, Address: 0x101ff04 */
    if (wD0 >= 0) /* Line 366, Address: 0x101ff10 */
      ret = -1; /* Line 367, Address: 0x101ff20 */
  }
  return ret; /* Line 369, Address: 0x101ff24 */
} /* Line 370, Address: 0x101ff28 */



static void a_stop(sprite_status* pActwk) { /* Line 374, Address: 0x101ff40 */
  short subact;

  --((short*)pActwk)[23]; /* Line 377, Address: 0x101ff50 */
  if (((short*)pActwk)[23] < 0) /* Line 378, Address: 0x101ff60 */
  {
    if (pActwk->actflg < 0) /* Line 380, Address: 0x101ff78 */
      soundset(179); /* Line 381, Address: 0x101ff8c */


    ((short*)pActwk)[23] = 60; /* Line 384, Address: 0x101ff98 */
    pActwk->r_no0 += 2; /* Line 385, Address: 0x101ffa4 */

    if (!pActwk->userflag.b.h) /* Line 387, Address: 0x101ffb4 */
    {
      subact = ((short*)pActwk)[26]; /* Line 389, Address: 0x101ffc4 */
      *(int*)&actwk[subact].actfree[0] = -0x20000; /* Line 390, Address: 0x101ffd4 */
      *(int*)&actwk[subact].actfree[4] = -196608; /* Line 391, Address: 0x1020000 */
      *(int*)&actwk[subact].actfree[8] = 0; /* Line 392, Address: 0x102002c */
      *(int*)&actwk[subact].actfree[12] = 8192; /* Line 393, Address: 0x1020054 */
      actwk[subact].r_no0 += 2; /* Line 394, Address: 0x1020080 */
      subact = ((short*)pActwk)[27]; /* Line 395, Address: 0x10200ac */
      *(int*)&actwk[subact].actfree[0] = 65536; /* Line 396, Address: 0x10200bc */
      *(int*)&actwk[subact].actfree[4] = -196608; /* Line 397, Address: 0x10200e8 */
      *(int*)&actwk[subact].actfree[8] = 0; /* Line 398, Address: 0x1020114 */
      *(int*)&actwk[subact].actfree[12] = 8192; /* Line 399, Address: 0x102013c */
      actwk[subact].r_no0 += 2; /* Line 400, Address: 0x1020168 */
      subact = ((short*)pActwk)[28]; /* Line 401, Address: 0x1020194 */
      *(int*)&actwk[subact].actfree[0] = 0x20000; /* Line 402, Address: 0x10201a4 */
      *(int*)&actwk[subact].actfree[4] = -196608; /* Line 403, Address: 0x10201d0 */
      *(int*)&actwk[subact].actfree[8] = 0; /* Line 404, Address: 0x10201fc */
      *(int*)&actwk[subact].actfree[12] = 8192; /* Line 405, Address: 0x1020224 */
      actwk[subact].r_no0 += 2; /* Line 406, Address: 0x1020250 */
    }
  }
} /* Line 409, Address: 0x102027c */



static void a_stop1(sprite_status* pActwk) { /* Line 413, Address: 0x1020290 */
  --((short*)pActwk)[23]; /* Line 414, Address: 0x1020298 */
  if (((short*)pActwk)[23] < 0) /* Line 415, Address: 0x10202a8 */
  {
    pActwk->r_no0 += 2; /* Line 417, Address: 0x10202c0 */

    if (!pActwk->userflag.b.h) /* Line 419, Address: 0x10202d0 */
      ((int*)pActwk)[12] = 0x40000; /* Line 420, Address: 0x10202e0 */
    else
      ((int*)pActwk)[12] = 98304; /* Line 422, Address: 0x10202f4 */

    if (!(pActwk->actflg & 1)) /* Line 424, Address: 0x1020304 */
      ((int*)pActwk)[12] *= -1; /* Line 425, Address: 0x102031c */
  }

} /* Line 428, Address: 0x102032c */



static void a_dash(sprite_status* pActwk) { /* Line 432, Address: 0x1020340 */
  pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 433, Address: 0x1020348 */
} /* Line 434, Address: 0x1020360 */















static void tagameb1(sprite_status* pActwk) { /* Line 450, Address: 0x1020370 */
  short subact;
  static void(*tbl[3])(sprite_status*) =
  {
    &b_init,
    &b_follow,
    &b_move
  };

  subact = ((short*)pActwk)[33]; /* Line 459, Address: 0x1020380 */
  if (actwk[subact].actno != 45) /* Line 460, Address: 0x1020390 */
  {
    frameout(pActwk); /* Line 462, Address: 0x10203c4 */
    return; /* Line 463, Address: 0x10203d0 */
  }
  if (pActwk->actfree[19] != actwk[subact].cdsts) /* Line 465, Address: 0x10203d8 */
  {
    frameout(pActwk); /* Line 467, Address: 0x1020414 */
    return; /* Line 468, Address: 0x1020420 */
  }
  tbl[pActwk->r_no0 / 2](pActwk); /* Line 470, Address: 0x1020428 */
} /* Line 471, Address: 0x102046c */



static void b_init(sprite_status* pActwk) { /* Line 475, Address: 0x1020480 */
  pActwk->r_no0 += 2; /* Line 476, Address: 0x102048c */
  pActwk->patbase = pat; /* Line 477, Address: 0x102049c */
  b_follow(pActwk); /* Line 478, Address: 0x10204ac */
} /* Line 479, Address: 0x10204b8 */



static void b_follow(sprite_status* pActwk) { /* Line 483, Address: 0x10204d0 */
  actionsub(pActwk); /* Line 484, Address: 0x10204dc */
} /* Line 485, Address: 0x10204e8 */



static void b_move(sprite_status* pActwk) { /* Line 489, Address: 0x1020500 */
  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 490, Address: 0x102050c */
  pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 491, Address: 0x1020528 */
  *(int*)&pActwk->actfree[0] += *(int*)&pActwk->actfree[8]; /* Line 492, Address: 0x1020544 */
  *(int*)&pActwk->actfree[4] += *(int*)&pActwk->actfree[12]; /* Line 493, Address: 0x1020568 */

  if (pActwk->yposi.w.h - actwk[0].yposi.w.h > 224) /* Line 495, Address: 0x102058c */
  {
    frameout(pActwk); /* Line 497, Address: 0x10205bc */
    return; /* Line 498, Address: 0x10205c8 */
  }
  actionsub(pActwk); /* Line 500, Address: 0x10205d0 */
} /* Line 501, Address: 0x10205dc */
