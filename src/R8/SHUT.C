#include "..\EQU.H"
#include "SHUT.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"
#include "SCR81A.H"

#if defined(R83)
  #define SPRITE_SHUT_BASE 495
#else
  #define SPRITE_SHUT_BASE 304
#endif

static void shut_init(sprite_status* shutwk);
static void shut_wait(sprite_status* shutwk);
static void shut_move(sprite_status* shutwk);
static void kaiten_init(sprite_status* loopwk);
static void kaiten_move0(sprite_status* loopwk);
static void kaiten_move1(sprite_status* loopwk);
static void kaiten_move2(sprite_status* loopwk);
static short ridechk_k(sprite_status* loopwk);
static void kaiten_bou0(sprite_status* loopwk);
static void kaiten_bou1(sprite_status* loopwk);

static unsigned char kaitenchg0[4] = { 2, 0, 1, 255 };
static unsigned char* kaitenchg[1] = { kaitenchg0 };
static sprite_pattern shu00 = { 6, { { { -8, -96, 8, SPRITE_SHUT_BASE + 4 }, { -8, -64, 8, SPRITE_SHUT_BASE + 4 }, { -8, -32, 8, SPRITE_SHUT_BASE + 4 }, { -8, 0, 8, SPRITE_SHUT_BASE + 4 }, { -8, 32, 8, SPRITE_SHUT_BASE + 4 }, { -8, 64, 8, SPRITE_SHUT_BASE + 4 } } } };
sprite_pattern* shutpat[1] = { &shu00 };
static sprite_pattern kai00 = { 3, { { { -40, -8, 0, SPRITE_SHUT_BASE }, { -24, -8, 0, SPRITE_SHUT_BASE + 1 }, { 8, -8, 0, SPRITE_SHUT_BASE + 2 } } } };
static sprite_pattern kai01 = { 3, { { { -40, -8, 0, SPRITE_SHUT_BASE }, { -24, -8, 8, SPRITE_SHUT_BASE + 1 }, { 8, -8, 0, SPRITE_SHUT_BASE + 2 } } } };
static sprite_pattern kai02 = { 5, { { { -4, -80, 0, SPRITE_SHUT_BASE + 3 }, { -4, -48, 0, SPRITE_SHUT_BASE + 3 }, { -4, -16, 0, SPRITE_SHUT_BASE + 3 }, { -4, 16, 0, SPRITE_SHUT_BASE + 3 }, { -4, 48, 0, SPRITE_SHUT_BASE + 3 } } } };
sprite_pattern* kaitenpat[3] = {
  &kai00,
  &kai01,
  &kai02
};













void shut(sprite_status* shutwk) { /* Line 52, Address: 0x1026e30 */
  void(*tbl[3])(sprite_status*) = { &shut_init, &shut_wait, &shut_move }; /* Line 53, Address: 0x1026e3c */

  tbl[shutwk->r_no0 / 2](shutwk); /* Line 55, Address: 0x1026e60 */
  actionsub(shutwk); /* Line 56, Address: 0x1026e9c */
  frameout_s(shutwk); /* Line 57, Address: 0x1026ea8 */
} /* Line 58, Address: 0x1026eb4 */



static void shut_init(sprite_status* shutwk) { /* Line 62, Address: 0x1026ed0 */
  sprite_status* new_actwk;

  ((short*)shutwk)[23] = shutwk->xposi.w.h; /* Line 65, Address: 0x1026edc */
  shutwk->userflag.b.h = 1; /* Line 66, Address: 0x1026eec */
  shutwk->actflg |= 1; /* Line 67, Address: 0x1026ef8 */

  if (shutwk->userflag.b.h) shutwk->xposi.w.h -= 8; /* Line 69, Address: 0x1026f08 */
  else shutwk->xposi.w.h += 8; /* Line 70, Address: 0x1026f30 */
  shutwk->r_no0 += 2; /* Line 71, Address: 0x1026f40 */
  shutwk->actflg |= 4; /* Line 72, Address: 0x1026f50 */
  shutwk->sprpri = 2; /* Line 73, Address: 0x1026f60 */
  shutwk->patbase = shutpat; /* Line 74, Address: 0x1026f6c */
  shutwk->sproffset = 32768; /* Line 75, Address: 0x1026f7c */

  if (actwkchk(&new_actwk) != 0) { frameout_s0(shutwk); return; } /* Line 77, Address: 0x1026f88 */
  new_actwk->actno = 61; /* Line 78, Address: 0x1026fb0 */
  new_actwk->xposi.w.h = ((short*)new_actwk)[23] = ((short*)shutwk)[23]; /* Line 79, Address: 0x1026fbc */

  new_actwk->yposi.w.h = shutwk->yposi.w.h; /* Line 81, Address: 0x1026fd4 */
  if (new_actwk->userflag.b.h) new_actwk->xposi.w.h -= 8; /* Line 82, Address: 0x1026fe4 */
  else new_actwk->xposi.w.h += 8; /* Line 83, Address: 0x102700c */
  new_actwk->r_no0 += 2; /* Line 84, Address: 0x102701c */
  new_actwk->actflg |= 4; /* Line 85, Address: 0x102702c */
  new_actwk->sprpri = 2; /* Line 86, Address: 0x102703c */
  new_actwk->patbase = shutpat; /* Line 87, Address: 0x1027048 */
  new_actwk->sproffset = 32768; /* Line 88, Address: 0x1027058 */
} /* Line 89, Address: 0x1027064 */


void shut_wait(sprite_status* shutwk) { /* Line 92, Address: 0x1027080 */
  if ((char)bossstart >= 0) return; /* Line 93, Address: 0x1027088 */
  shut_flag = 0; /* Line 94, Address: 0x10270a8 */
  shutwk->r_no0 += 2; /* Line 95, Address: 0x10270b0 */
} /* Line 96, Address: 0x10270c0 */


void shut_move(sprite_status* shutwk) { /* Line 99, Address: 0x10270d0 */
  unsigned short cal_xposi, block_wrt_x, block_wrt_y, i = 0; /* Line 100, Address: 0x10270ec */

  block_wrt_x = cal_xposi = shutwk->xposi.w.h - 8; /* Line 102, Address: 0x10270f0 */
  if (!(cal_xposi & 15)) { /* Line 103, Address: 0x1027114 */
    if (++shutwk->actfree[2] >= 17) { frameout_s0(shutwk); return; } /* Line 104, Address: 0x1027124 */
    block_wrt_y = shutwk->yposi.w.h - 96; /* Line 105, Address: 0x102715c */

    for ( ; i < 12; block_wrt_y += 16, ++i) block_wrt(0, block_wrt_x, block_wrt_y); /* Line 107, Address: 0x1027178 */
  }

  shutwk->xposi.w.h += 2; /* Line 110, Address: 0x10271b4 */
  if (shutwk->userflag.b.h) shutwk->xposi.w.h -= 4; /* Line 111, Address: 0x10271c4 */
} /* Line 112, Address: 0x10271e4 */



void kaiten(sprite_status* loopwk) { /* Line 116, Address: 0x1027210 */
  short i;
  void(*tbl[6])(sprite_status*) = { /* Line 118, Address: 0x1027220 */
    &kaiten_init,
    &kaiten_move0,
    &kaiten_move1,
    &kaiten_move2,
    &kaiten_bou0,
    &kaiten_bou1
  };
  if (loopwk->yposi.w.h - actwk[0].yposi.w.h > 22 /* Line 126, Address: 0x1027254 */
      && loopwk->yposi.w.h - actwk[0].yposi.w.h <= 156) {
    if (prio_flag) { /* Line 128, Address: 0x10272b4 */
      actwk[0].sproffset &= 32767; /* Line 129, Address: 0x10272c4 */
      if (actwk[6].actno) actwk[6].sproffset &= 32767; /* Line 130, Address: 0x10272d8 */
      for (i = 8; i < 12; ++i) /* Line 131, Address: 0x10272fc */
        if (actwk[i].actno) actwk[i].sproffset &= 32767; /* Line 132, Address: 0x1027310 */
    } else { /* Line 133, Address: 0x1027388 */
      actwk[0].sproffset |= 32768; /* Line 134, Address: 0x1027390 */
      if (actwk[6].actno) actwk[6].sproffset |= 32768; /* Line 135, Address: 0x10273a4 */
      for (i = 8; i < 12; ++i) /* Line 136, Address: 0x10273c8 */
        if (actwk[i].actno) actwk[i].sproffset |= 32768; /* Line 137, Address: 0x10273dc */
    }
  }

  tbl[loopwk->r_no0 / 2](loopwk); /* Line 141, Address: 0x1027454 */
  if (loopwk->r_no0 == 0) { frameout_s0(loopwk); return; } /* Line 142, Address: 0x1027490 */
  actionsub(loopwk); /* Line 143, Address: 0x10274b8 */
  if (loopwk->r_no0 < 8) { frameout_s(loopwk); return; } /* Line 144, Address: 0x10274c4 */
  frameout_s00(loopwk, ((short*)loopwk)[23]); /* Line 145, Address: 0x10274f0 */
} /* Line 146, Address: 0x1027504 */



static void kaiten_init(sprite_status* loopwk) { /* Line 150, Address: 0x1027520 */
  short i, sin_tmp, cos_tmp;
  int cos_data;
  sprite_status *old_actwk, *new_actwk;
  unsigned char tbl[3] = { 64, 149, 234 }; /* Line 154, Address: 0x1027538 */

  old_actwk = loopwk; /* Line 156, Address: 0x102755c */
  for (i = 0; i < 4; ++i) { /* Line 157, Address: 0x1027560 */
    if (actwkchk2(old_actwk, &new_actwk) != 0) return; /* Line 158, Address: 0x102756c */
    old_actwk = new_actwk; /* Line 159, Address: 0x1027584 */
  } /* Line 160, Address: 0x1027588 */
  loopwk->r_no0 += 2; /* Line 161, Address: 0x10275a8 */
  loopwk->actflg |= 4; /* Line 162, Address: 0x10275b8 */
  loopwk->sprpri = 1; /* Line 163, Address: 0x10275c8 */
  loopwk->sprhsize = 40; /* Line 164, Address: 0x10275d4 */
  loopwk->sprvsize = 8; /* Line 165, Address: 0x10275e0 */
  loopwk->patbase = kaitenpat; /* Line 166, Address: 0x10275ec */

  actwkchk2(loopwk, &new_actwk); /* Line 168, Address: 0x10275fc */
  new_actwk->actno = 62; /* Line 169, Address: 0x102760c */
  new_actwk->actflg |= 4; /* Line 170, Address: 0x1027618 */
  new_actwk->sprpri = 1; /* Line 171, Address: 0x1027628 */
  new_actwk->patbase = kaitenpat; /* Line 172, Address: 0x1027634 */

  new_actwk->sprhsize = 40; /* Line 174, Address: 0x1027644 */
  new_actwk->sprvsize = 8; /* Line 175, Address: 0x1027650 */
  new_actwk->xposi.w.h = loopwk->xposi.w.h; /* Line 176, Address: 0x102765c */
  new_actwk->yposi.w.h = loopwk->yposi.w.h - 176; /* Line 177, Address: 0x102766c */
  new_actwk->userflag.b.h = 1; /* Line 178, Address: 0x1027690 */
  new_actwk->r_no0 += 2; /* Line 179, Address: 0x102769c */

  for (i = 0; i < 3; ++i) { /* Line 181, Address: 0x10276ac */
    actwkchk2(loopwk, &new_actwk); /* Line 182, Address: 0x10276b8 */
    new_actwk->actno = 62; /* Line 183, Address: 0x10276c8 */
    new_actwk->actflg |= 4; /* Line 184, Address: 0x10276d4 */
    new_actwk->sprpri = 1; /* Line 185, Address: 0x10276e4 */
    new_actwk->patbase = kaitenpat; /* Line 186, Address: 0x10276f0 */

    new_actwk->sprhsize = 8; /* Line 188, Address: 0x1027700 */
    new_actwk->sprvsize = 80; /* Line 189, Address: 0x102770c */
    new_actwk->actfree[3] = tbl[2 - i]; /* Line 190, Address: 0x1027718 */
    new_actwk->patno = 2; /* Line 191, Address: 0x1027738 */
    new_actwk->r_no0 = 8; /* Line 192, Address: 0x1027744 */
    ((short*)new_actwk)[23] = loopwk->xposi.w.h; /* Line 193, Address: 0x1027750 */
    new_actwk->yposi.w.h = loopwk->yposi.w.h - 88; /* Line 194, Address: 0x1027760 */
    sinset(new_actwk->actfree[3], &sin_tmp, &cos_tmp); /* Line 195, Address: 0x1027784 */
    cos_data = cos_tmp << 5 >> 8; /* Line 196, Address: 0x102779c */
    new_actwk->xposi.w.h = ((short*)new_actwk)[23] + (short)cos_data; /* Line 197, Address: 0x10277b0 */

  } /* Line 199, Address: 0x10277e4 */
} /* Line 200, Address: 0x1027804 */


void kaiten_move0(sprite_status* loopwk) { /* Line 203, Address: 0x1027820 */
  short cal_xposi;

  if (loopwk->userflag.b.h) { /* Line 206, Address: 0x1027830 */
    if (actwk[0].mstno.b.h >= 51) patchg(loopwk, kaitenchg); /* Line 207, Address: 0x1027840 */
    return; /* Line 208, Address: 0x1027870 */
  }

  if (ridechk_k(loopwk) == 0) { loopwk->actfree[2] = 0; return; } /* Line 211, Address: 0x1027878 */
  cal_xposi = loopwk->xposi.w.h - actwk[0].xposi.w.h + 8; /* Line 212, Address: 0x10278a4 */
  if (cal_xposi < 0 || cal_xposi >= 16) /* Line 213, Address: 0x10278dc */
  { loopwk->actfree[2] = 0; return; } /* Line 214, Address: 0x1027900 */
  if (loopwk->actfree[2] & 1) return; /* Line 215, Address: 0x1027910 */
  loopwk->actfree[2] |= 1; /* Line 216, Address: 0x1027928 */
  actwk[0].actfree[2] |= 1; /* Line 217, Address: 0x1027938 */
  actwk[0].xposi.w.h = loopwk->xposi.w.h; /* Line 218, Address: 0x102794c */
  actwk[0].xspeed.w = actwk[0].mspeed.w = 0; /* Line 219, Address: 0x102795c */
  actwk[0].mstno.b.h = 51; /* Line 220, Address: 0x1027974 */
  if (prio_flag) actwk[0].mstno.b.h = 52; /* Line 221, Address: 0x1027980 */
  loopwk->r_no0 += 2; /* Line 222, Address: 0x102799c */
} /* Line 223, Address: 0x10279ac */


void kaiten_move1(sprite_status* loopwk) { /* Line 226, Address: 0x10279c0 */
  patchg(loopwk, kaitenchg); /* Line 227, Address: 0x10279cc */
  if (actwk[0].mstno.b.h != 5) { ridechk_k(loopwk); return; } /* Line 228, Address: 0x10279e0 */
  loopwk->r_no0 += 2; /* Line 229, Address: 0x1027a10 */
  kaiten_move2(loopwk); /* Line 230, Address: 0x1027a20 */
} /* Line 231, Address: 0x1027a2c */


void kaiten_move2(sprite_status* loopwk) { /* Line 234, Address: 0x1027a40 */
  actwk[0].actfree[2] &= 254; /* Line 235, Address: 0x1027a4c */
  ridechk_k(loopwk); /* Line 236, Address: 0x1027a60 */
  prio_flag ^= 1; /* Line 237, Address: 0x1027a6c */
  actwk[0].actflg ^= 1; /* Line 238, Address: 0x1027a80 */
  actwk[0].cddat ^= 1; /* Line 239, Address: 0x1027a94 */
  actwk[0].sproffset |= 32768; /* Line 240, Address: 0x1027aa8 */
  if (prio_flag) actwk[0].sproffset &= 32767; /* Line 241, Address: 0x1027abc */
  loopwk->r_no0 = 2; /* Line 242, Address: 0x1027ae0 */
} /* Line 243, Address: 0x1027aec */


short ridechk_k(sprite_status* loopwk) { /* Line 246, Address: 0x1027b00 */
  ridechk(loopwk, &actwk[0]); /* Line 247, Address: 0x1027b0c */

} /* Line 249, Address: 0x1027b20 */


void kaiten_bou0(sprite_status* loopwk) { /* Line 252, Address: 0x1027b30 */
  if (actwk[0].mstno.b.h < 51) return; /* Line 253, Address: 0x1027b38 */
  loopwk->r_no0 += 2; /* Line 254, Address: 0x1027b54 */
  loopwk->actfree[4] = loopwk->actfree[3] + 128; /* Line 255, Address: 0x1027b64 */
} /* Line 256, Address: 0x1027b80 */


void kaiten_bou1(sprite_status* loopwk) { /* Line 259, Address: 0x1027b90 */
  unsigned char cal_dir;
  short sin_tmp, cos_tmp;
  int cos_data;

  if (actwk[0].mstno.b.h < 51) { /* Line 264, Address: 0x1027ba4 */
    loopwk->r_no0 -= 2; /* Line 265, Address: 0x1027bc0 */
    loopwk->actfree[3] = loopwk->actfree[4]; /* Line 266, Address: 0x1027bd0 */
  } else { /* Line 267, Address: 0x1027be0 */
    cal_dir = 4; /* Line 268, Address: 0x1027be8 */
    if (!(actwk[0].cddat & 1)) { /* Line 269, Address: 0x1027bf0 */
      if (prio_flag) cal_dir = -cal_dir; /* Line 270, Address: 0x1027c08 */

    } else { /* Line 272, Address: 0x1027c28 */
      if (!prio_flag) /* Line 273, Address: 0x1027c30 */
        cal_dir = -cal_dir; /* Line 274, Address: 0x1027c40 */
    }
    loopwk->actfree[3] += cal_dir; /* Line 276, Address: 0x1027c50 */
  }
  sinset(loopwk->actfree[3], &sin_tmp, &cos_tmp); /* Line 278, Address: 0x1027c60 */
  cos_data = cos_tmp * 24 >> 8; /* Line 279, Address: 0x1027c78 */
  loopwk->xposi.w.h = ((short*)loopwk)[23] + (short)cos_data; /* Line 280, Address: 0x1027c94 */

  loopwk->sprpri = 1; /* Line 282, Address: 0x1027cc8 */
  if ((char)loopwk->actfree[3] >= 0) loopwk->sprpri = 4; /* Line 283, Address: 0x1027cd4 */
} /* Line 284, Address: 0x1027d00 */
