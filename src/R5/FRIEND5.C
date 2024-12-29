#include "..\EQU.H"
#include "FRIEND5.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\ETC.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static void t_init(sprite_status* pActwk);
static void t_move(sprite_status* pActwk);
static void t_movie(sprite_status* pActwk);
static void p_init(sprite_status* pActwk);
static void p_move(sprite_status* pActwk);
static void p_movie(sprite_status* pActwk);
static void set_sproffset(sprite_status* pActwk);
static void t_roll(sprite_status* pActwk, int xsft, int ysft);

static unsigned char pchg0_00[4] = { 19, 0, 1, 255 };
unsigned char pchg0_01[30] = {
  0, 0, 0, 2, 0, 0, 2, 1, 1, 2,
  2, 1, 1, 2, 2, 0, 0, 2, 0, 0,
  2, 1, 1, 2, 2, 1, 1, 2, 2, 255
};
static unsigned char* pchg0[2] = {
  pchg0_00,
  pchg0_01
};
static unsigned char pchg1_00[58] = {
  0, 3, 3, 2, 3, 3, 2, 3, 3, 2,
  3, 3, 2, 3, 3, 2, 2, 3, 3, 2,
  2, 3, 3, 2, 2, 3, 3, 2, 2, 4,
  4, 2, 4, 4, 2, 4, 4, 2, 4, 4,
  2, 4, 4, 2, 2, 4, 4, 2, 2, 4,
  4, 2, 2, 4, 4, 2, 2, 255
};
static unsigned char* pchg1[1] = { pchg1_00 };
static sprite_pattern friend0_pat00 = {
  1,
  { { -8, -8, 0, 435 } }
};
static sprite_pattern friend0_pat01 = {
  1,
  { { -8, -8, 0, 436 } }
};
static sprite_pattern friend0_pat02;
sprite_pattern* pat_friend0[3] = {
  &friend0_pat00,
  &friend0_pat01,
  &friend0_pat02
};
static sprite_pattern friend1_pat00 = {
  1,
  { { -12, -8, 1, 437 } }
};
static sprite_pattern friend1_pat01 = {
  1,
  { { -12, -8, 1, 438 } }
};
static sprite_pattern friend1_pat02;
static sprite_pattern friend1_pat03 = {
  1,
  { { -12, -8, 1, 439 } }
};
static sprite_pattern friend1_pat04 = {
  1,
  { { -12, -7, 1, 440 } }
};
sprite_pattern* pat_friend1[5] = {
  &friend1_pat00,
  &friend1_pat01,
  &friend1_pat02,
  &friend1_pat03,
  &friend1_pat04
};
static sprite_pattern friend2_pat00 = {
  1,
  { { -12, -8, 1, 441 } }
};
static sprite_pattern friend2_pat01 = {
  1,
  { { -12, -8, 1, 442 } }
};
static sprite_pattern friend2_pat02;
static sprite_pattern friend2_pat03 = {
  1,
  { { -12, -8, 1, 443 } }
};
static sprite_pattern friend2_pat04 = {
  1,
  { { -12, -7, 1, 444 } }
};
static sprite_pattern* pat_friend2[5] = {
  &friend2_pat00,
  &friend2_pat01,
  &friend2_pat02,
  &friend2_pat03,
  &friend2_pat04
};
static void(*flicky_act_tbl[3])(sprite_status*) = {
  &t_init,
  &t_move,
  &t_movie
};
static void(*ricky_act_tbl[3])(sprite_status*) = {
  &p_init,
  &p_move,
  &p_movie
};













































































































void friend(sprite_status* pActwk) { /* Line 219, Address: 0x101e220 */
  if (!friend_suicide(pActwk)) { /* Line 220, Address: 0x101e22c */



    if (pActwk->userflag.b.h & 127) { /* Line 224, Address: 0x101e240 */

      ricky_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 226, Address: 0x101e25c */
      return; /* Line 227, Address: 0x101e2a0 */
    }
    flicky_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 229, Address: 0x101e2a8 */
  }
} /* Line 231, Address: 0x101e2ec */





static void t_init(sprite_status* pActwk) { /* Line 237, Address: 0x101e300 */
  pActwk->r_no0 += 2; /* Line 238, Address: 0x101e30c */
  pActwk->actflg = 4; /* Line 239, Address: 0x101e31c */
  pActwk->sprvsize = 8; /* Line 240, Address: 0x101e328 */
  pActwk->sprhs = 8; /* Line 241, Address: 0x101e334 */
  pActwk->sprhsize = 8; /* Line 242, Address: 0x101e340 */
  pActwk->sprpri = 4; /* Line 243, Address: 0x101e34c */
  pActwk->patbase = pat_friend0; /* Line 244, Address: 0x101e358 */
  ((short*)pActwk)[23] = pActwk->xposi.w.h; /* Line 245, Address: 0x101e368 */
  ((short*)pActwk)[24] = pActwk->yposi.w.h; /* Line 246, Address: 0x101e378 */
  pActwk->actflg ^= 1, pActwk->cddat ^= 1; /* Line 247, Address: 0x101e388 */
  set_sproffset(pActwk); /* Line 248, Address: 0x101e3a8 */

  if (pActwk->userflag.b.h & 128) { /* Line 250, Address: 0x101e3b4 */

    pActwk->r_no0 += 2; /* Line 252, Address: 0x101e3d0 */
    pActwk->mstno.b.h = 1; /* Line 253, Address: 0x101e3e0 */
    pActwk->sprpri = 3; /* Line 254, Address: 0x101e3ec */
  } /* Line 255, Address: 0x101e3f8 */
  else {
    pActwk->sproffset |= 32768; /* Line 257, Address: 0x101e400 */
    pActwk->actfree[4] = 1; /* Line 258, Address: 0x101e410 */
    pActwk->actfree[5] = 1; /* Line 259, Address: 0x101e41c */
  }
} /* Line 261, Address: 0x101e428 */





static void t_move(sprite_status* pActwk) { /* Line 267, Address: 0x101e440 */
  char anglewk;

  t_roll(pActwk, 1, 1); /* Line 270, Address: 0x101e450 */

  anglewk = ((char*)pActwk)[50] + ((char*)pActwk)[51]; /* Line 272, Address: 0x101e464 */

  if ((unsigned char)(anglewk - 1) >= 127) { /* Line 274, Address: 0x101e498 */
    anglewk = ((char*)pActwk)[50]; /* Line 275, Address: 0x101e4b8 */
    ((char*)pActwk)[51] *= -1; /* Line 276, Address: 0x101e4c8 */
    pActwk->actflg ^= 1, pActwk->cddat ^= 1; /* Line 277, Address: 0x101e4e8 */
  }


  pActwk->actfree[4] = anglewk; /* Line 281, Address: 0x101e508 */
  patchg(pActwk, pchg0); /* Line 282, Address: 0x101e510 */
  actionsub(pActwk); /* Line 283, Address: 0x101e524 */
  frameout_s00(pActwk, ((short*)pActwk)[23]); /* Line 284, Address: 0x101e530 */
} /* Line 285, Address: 0x101e544 */





static void t_movie(sprite_status* pActwk) { /* Line 291, Address: 0x101e560 */
  sprite_status* pMoviewk;

  pMoviewk = &actwk[((short*)pActwk)[33]]; /* Line 294, Address: 0x101e570 */
  if (pMoviewk->actno != 44 || pMoviewk->actfree[21]) { /* Line 295, Address: 0x101e598 */
    frameout(pActwk); /* Line 296, Address: 0x101e5b8 */
    return; /* Line 297, Address: 0x101e5c4 */
  }

  t_roll(pActwk, 3, 4); /* Line 300, Address: 0x101e5cc */
  ((char*)pActwk)[50] += 4; /* Line 301, Address: 0x101e5e0 */
  if (!(pActwk->actfree[4] & 127)) { /* Line 302, Address: 0x101e5f0 */
    pActwk->actflg ^= 1, pActwk->cddat ^= 1; /* Line 303, Address: 0x101e608 */
  } else { /* Line 304, Address: 0x101e628 */
    patchg(pActwk, pchg0); /* Line 305, Address: 0x101e630 */
    actionsub(pActwk); /* Line 306, Address: 0x101e644 */
  }
} /* Line 308, Address: 0x101e650 */





static void p_init(sprite_status* pActwk) { /* Line 314, Address: 0x101e670 */
  pActwk->r_no0 += 2; /* Line 315, Address: 0x101e67c */
  pActwk->actflg = 4; /* Line 316, Address: 0x101e68c */
  pActwk->sprvsize = 8; /* Line 317, Address: 0x101e698 */
  pActwk->sprhs = 8; /* Line 318, Address: 0x101e6a4 */
  pActwk->sprhsize = 8; /* Line 319, Address: 0x101e6b0 */
  pActwk->sprpri = 4; /* Line 320, Address: 0x101e6bc */
  pActwk->patbase = pat_friend1; /* Line 321, Address: 0x101e6c8 */
  ((short*)pActwk)[23] = pActwk->xposi.w.h; /* Line 322, Address: 0x101e6d8 */
  set_sproffset(pActwk); /* Line 323, Address: 0x101e6e8 */

  if (pActwk->userflag.b.h & 128) { /* Line 325, Address: 0x101e6f4 */

    pActwk->patbase = pat_friend2; /* Line 327, Address: 0x101e710 */
    pActwk->r_no0 += 2; /* Line 328, Address: 0x101e720 */
    pActwk->actflg ^= 1, pActwk->cddat ^= 1; /* Line 329, Address: 0x101e730 */
  } /* Line 330, Address: 0x101e750 */
  else {
    ((int*)pActwk)[12] = 65536; /* Line 332, Address: 0x101e758 */
    ((int*)pActwk)[13] = -0x40000; /* Line 333, Address: 0x101e764 */
  }
} /* Line 335, Address: 0x101e770 */





static void p_move(sprite_status* pActwk) { /* Line 341, Address: 0x101e780 */
  short colval;

  pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 344, Address: 0x101e790 */
  pActwk->yposi.l += ((int*)pActwk)[13]; /* Line 345, Address: 0x101e7a8 */
  if ((((int*)pActwk)[13] += 8192) < 0) { /* Line 346, Address: 0x101e7c0 */
    pActwk->patno = 0; /* Line 347, Address: 0x101e7d8 */
  } /* Line 348, Address: 0x101e7e0 */
  else pActwk->patno = 1; /* Line 349, Address: 0x101e7e8 */


  if ((colval = emycol_d(pActwk)) < 0) { /* Line 352, Address: 0x101e7f4 */
    pActwk->yposi.w.h += colval; /* Line 353, Address: 0x101e820 */
    ((int*)pActwk)[13] = -0x40000; /* Line 354, Address: 0x101e830 */
    ((int*)pActwk)[12] *= -1; /* Line 355, Address: 0x101e83c */
    pActwk->actflg ^= 1, pActwk->cddat ^= 1; /* Line 356, Address: 0x101e84c */
  }



  actionsub(pActwk); /* Line 361, Address: 0x101e86c */
  frameout_s(pActwk); /* Line 362, Address: 0x101e878 */
} /* Line 363, Address: 0x101e884 */





static void p_movie(sprite_status* pActwk) { /* Line 369, Address: 0x101e8a0 */
  sprite_status* pMoviewk;

  pMoviewk = &actwk[((short*)pActwk)[33]]; /* Line 372, Address: 0x101e8b0 */
  if (pMoviewk->actno != 44 || pMoviewk->actfree[21]) { /* Line 373, Address: 0x101e8d8 */
    frameout(pActwk); /* Line 374, Address: 0x101e8f8 */
    return; /* Line 375, Address: 0x101e904 */
  }

  patchg(pActwk, pchg1); /* Line 378, Address: 0x101e90c */
  actionsub(pActwk); /* Line 379, Address: 0x101e920 */
} /* Line 380, Address: 0x101e92c */
















static void set_sproffset(sprite_status* pActwk) { /* Line 397, Address: 0x101e940 */
  short tbl0sproffset[11] = { /* Line 398, Address: 0x101e948 */
    1210,
    1210,
    1210,
       0,
    1210,
    1210,
    1210,
       0,
       0,
       0,
    1210
  };

  pActwk->sproffset = tbl0sproffset[time_flag + stageno.b.l * 4]; /* Line 412, Address: 0x101e974 */
} /* Line 413, Address: 0x101e9ac */















static void t_roll(sprite_status* pActwk, int xsft, int ysft) { /* Line 429, Address: 0x101e9c0 */
  short sinwk, coswk;

  sinset(pActwk->actfree[4], &sinwk, &coswk); /* Line 432, Address: 0x101e9d4 */
  coswk >>= xsft; /* Line 433, Address: 0x101e9ec */
  sinwk >>= ysft; /* Line 434, Address: 0x101ea04 */
  coswk += ((short*)pActwk)[23]; /* Line 435, Address: 0x101ea1c */
  sinwk += ((short*)pActwk)[24]; /* Line 436, Address: 0x101ea30 */
  pActwk->xposi.w.h = coswk; /* Line 437, Address: 0x101ea44 */
  pActwk->yposi.w.h = sinwk; /* Line 438, Address: 0x101ea50 */
} /* Line 439, Address: 0x101ea5c */
