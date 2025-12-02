#include "..\EQU.H"
#include "BOBIN.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"
#include "..\SCORE.H"

#if defined(R31A)
  #define SPRITE_BOBIN_BASE 550
#elif defined(R31B) || defined(R32A)
  #define SPRITE_BOBIN_BASE 544
#elif defined(R33C) || defined(R33D)
  #define SPRITE_BOBIN_BASE 548
#else
  #define SPRITE_BOBIN_BASE 497
#endif

static sprite_pattern bobinsp0 = {
  1,
  { { -16, -16, 0, SPRITE_BOBIN_BASE } }
};
static sprite_pattern bobinsp1 = {
  1,
  { { -12, -12, 0, SPRITE_BOBIN_BASE + 1 } }
};
static sprite_pattern bobinsp2 = {
  1,
  { { -24, -20, 0, SPRITE_BOBIN_BASE + 2 } }
};
static sprite_pattern fripsp0 = {
  1,
  { { -32, -12, 0, SPRITE_BOBIN_BASE + 3 } }
};
static sprite_pattern fripsp1 = {
  1,
  { { -32, -12, 0, SPRITE_BOBIN_BASE + 4 } }
};
static sprite_pattern fripsp2 = {
  1,
  { { -32, -20, 0, SPRITE_BOBIN_BASE + 4 } }
};
sprite_pattern* bobinpat[3] = { &bobinsp0, &bobinsp1, &bobinsp2 };
sprite_pattern* frippat[3] = { &fripsp0, &fripsp1, &fripsp2 };
static char bobinchg0[3] = { 15, 0, -1 };
static char bobinchg1[7] = { 4, 1, 2, 1, 2, -3, 0 };
static char* bobinchg[2] = { bobinchg0, bobinchg1 };
static char fripchg0[3] = { 15, 0, -1 };
static char fripchg1[6] = { 1, 1, 2, 1, -3, 0 };
static char* fripchg[2] = { fripchg0, fripchg1 };
char frip_posi[64] = {
   14,  13,  12,  11,
   11,  10,  10,   9,
    9,   8,   8,   7,
    7,   6,   6,   5,
    5,   4,   4,   3,
    3,   2,   2,   1,
    1,   0,   0,  -1,
   -1,  -2,  -2,  -3,
   -3,  -4,  -4,  -5,
   -5,  -6,  -6,  -7,
   -7,  -8,  -8,  -9,
   -9, -10, -10, -11,
  -11, -11, -12, -12,
  -12, -12, -12, -12,
  -11, -11, -10, -10,
   -9,  -8,  -6,  -4
};
char frip_posi_r[64] = {
  18, 19, 20, 20,
  20, 20, 20, 20,
  20, 19, 19, 19,
  19, 19, 19, 19,
  18, 18, 18, 18,
  18, 18, 17, 17,
  17, 17, 17, 17,
  16, 16, 16, 16,
  16, 16, 16, 15,
  15, 15, 15, 15,
  14, 14, 14, 14,
  14, 14, 13, 13,
  13, 13, 13, 13,
  12, 12, 12, 12,
  11, 11, 10, 10,
   9,  8,  6,  4
};















void bobin(sprite_status* actionwk) { /* Line 104, Address: 0x10264a0 */
  switch (actionwk->r_no0) { /* Line 105, Address: 0x10264ac */

    case 0:
      bobininit(actionwk); /* Line 108, Address: 0x10264d4 */
    case 2:
      bobinmove(actionwk); /* Line 110, Address: 0x10264e0 */
      break;
  }
} /* Line 113, Address: 0x10264ec */

void bobininit(sprite_status* actionwk) { /* Line 115, Address: 0x1026500 */
  short d0;
  char d6;

  actionwk->r_no0 += 2; /* Line 119, Address: 0x1026510 */
  actionwk->patbase = bobinpat; /* Line 120, Address: 0x1026520 */
  actionwk->sproffset = 1230; /* Line 121, Address: 0x1026530 */


  if (actionwk->xposi.w.h == 10624 && actionwk->yposi.w.h == 1024) { /* Line 124, Address: 0x102653c */

    actionwk->sproffset |= 32768; /* Line 126, Address: 0x1026574 */
  }

  actionwk->actflg |= 4; /* Line 129, Address: 0x1026584 */
  actionwk->sprhs = 16; /* Line 130, Address: 0x1026594 */
  actionwk->sprhsize = 16; /* Line 131, Address: 0x10265a0 */
  actionwk->sprvsize = 16; /* Line 132, Address: 0x10265ac */
  actionwk->sprpri = 1; /* Line 133, Address: 0x10265b8 */
  actionwk->colino = 215; /* Line 134, Address: 0x10265c4 */

  ((short*)actionwk)[27] = actionwk->xposi.w.h; /* Line 136, Address: 0x10265d0 */
  ((short*)actionwk)[28] = 5; /* Line 137, Address: 0x10265e0 */
  d0 = 0; /* Line 138, Address: 0x10265ec */
  d6 = actionwk->userflag.b.h; /* Line 139, Address: 0x10265f0 */
  if (d6 & 2) d0 += 64; /* Line 140, Address: 0x1026600 */
  if (d6 & 1) d0 += 32; /* Line 141, Address: 0x1026620 */
  ((short*)actionwk)[26] = d0; /* Line 142, Address: 0x1026640 */
  d0 >>= 1; /* Line 143, Address: 0x1026648 */
  ((short*)actionwk)[25] = d0; /* Line 144, Address: 0x1026654 */
  if (d0 > 0) { /* Line 145, Address: 0x102665c */

    *(int*)&actionwk->actfree[0] = 65536; /* Line 147, Address: 0x102666c */
    if (!(d6 & 64)) { /* Line 148, Address: 0x102667c */

      *(int*)&actionwk->actfree[0] = -*(int*)&actionwk->actfree[0]; /* Line 150, Address: 0x1026690 */
    }
  }

} /* Line 154, Address: 0x10266ac */

void bobinmove(sprite_status* actionwk) { /* Line 156, Address: 0x10266c0 */
  int *a, d0l, d1l;
  sprite_status* a1;
  unsigned char d;
  short d0, d1, d2;

  if (*(int*)&actionwk->actfree[0] != 0) { /* Line 162, Address: 0x10266e4 */
    a = &actionwk->xposi.l; /* Line 163, Address: 0x10266f8 */
    if (actionwk->userflag.w >= 0) { /* Line 164, Address: 0x1026700 */
      a = &actionwk->yposi.l; /* Line 165, Address: 0x1026718 */
    }
    *a += *(int*)&actionwk->actfree[0]; /* Line 167, Address: 0x1026720 */
    if (!--((short*)actionwk)[25]) { /* Line 168, Address: 0x1026738 */
      ((short*)actionwk)[25] = ((short*)actionwk)[26]; /* Line 169, Address: 0x1026758 */

      *(int*)&actionwk->actfree[0] = -*(int*)&actionwk->actfree[0]; /* Line 171, Address: 0x1026768 */
    }
  }


  if (actionwk->colicnt != 0) { /* Line 176, Address: 0x1026784 */
    if (((short*)actionwk)[28]) { /* Line 177, Address: 0x1026798 */

      --((short*)actionwk)[28]; /* Line 179, Address: 0x10267a8 */
      scoreup(10); /* Line 180, Address: 0x10267b8 */
      tensuu0(actionwk, 0); /* Line 181, Address: 0x10267c4 */
    }

    if ((char)actionwk->actflg < 0) { /* Line 184, Address: 0x10267d4 */

      d0 = 127; /* Line 186, Address: 0x10267f4 */
      sub_sync(d0); /* Line 187, Address: 0x10267fc */
    }
    a1 = &actwk[0]; /* Line 189, Address: 0x1026808 */
    actionwk->colicnt = 0; /* Line 190, Address: 0x1026810 */
    d1 = actionwk->xposi.w.h - a1->xposi.w.h; /* Line 191, Address: 0x1026818 */
    d2 = actionwk->yposi.w.h - a1->yposi.w.h; /* Line 192, Address: 0x1026844 */
    d = atan_sonic(d1, d2); /* Line 193, Address: 0x1026874 */
    sinset(d, &d0, &d1); /* Line 194, Address: 0x102688c */
    d1l = d1 * -1792; /* Line 195, Address: 0x10268a0 */
    a1->xspeed.w = d1l >> 8; /* Line 196, Address: 0x10268b8 */
    d0l = d0 * -1792; /* Line 197, Address: 0x10268c8 */
    a1->yspeed.w = d0l >> 8; /* Line 198, Address: 0x10268e0 */
    a1->cddat |= 2; /* Line 199, Address: 0x10268f0 */
    a1->cddat &= 239; /* Line 200, Address: 0x10268fc */
    a1->cddat &= 223; /* Line 201, Address: 0x1026908 */
    a1->actfree[18] = 0; /* Line 202, Address: 0x1026914 */
    actionwk->mstno.b.h = 1; /* Line 203, Address: 0x1026918 */

    if (actionwk->cdsts) /* Line 205, Address: 0x1026924 */
      if (flagwork[actionwk->cdsts] < 138) /* Line 206, Address: 0x1026934 */
        ++flagwork[actionwk->cdsts]; /* Line 207, Address: 0x1026960 */
  }
  patchg(actionwk, (unsigned char**)bobinchg); /* Line 209, Address: 0x1026984 */
  actionsub(actionwk); /* Line 210, Address: 0x1026998 */
  frameout_s00(actionwk, ((short*)actionwk)[27]); /* Line 211, Address: 0x10269a4 */
} /* Line 212, Address: 0x10269b8 */

void frip(sprite_status* actionwk) { /* Line 214, Address: 0x10269e0 */
  switch (actionwk->r_no0) { /* Line 215, Address: 0x10269ec */

    case 0:
      frip_init(actionwk); /* Line 218, Address: 0x1026a14 */
    case 2:
      frip_move(actionwk); /* Line 220, Address: 0x1026a20 */
      break;
  }
} /* Line 223, Address: 0x1026a2c */

void frip_init(sprite_status* actionwk) { /* Line 225, Address: 0x1026a40 */
  actionwk->r_no0 += 2; /* Line 226, Address: 0x1026a48 */
  actionwk->patbase = frippat; /* Line 227, Address: 0x1026a58 */
  actionwk->sproffset = 1181; /* Line 228, Address: 0x1026a68 */
  actionwk->actflg |= 4; /* Line 229, Address: 0x1026a74 */
  actionwk->sprpri = 1; /* Line 230, Address: 0x1026a84 */
  actionwk->sprhsize = 32; /* Line 231, Address: 0x1026a90 */
  actionwk->sprvsize = 16; /* Line 232, Address: 0x1026a9c */
} /* Line 233, Address: 0x1026aa8 */

void frip_move(sprite_status* actionwk) { /* Line 235, Address: 0x1026ac0 */
  if (actionwk->mstno.b.h == 0) { /* Line 236, Address: 0x1026acc */

    frip_chk(actionwk); /* Line 238, Address: 0x1026ae4 */
  }

  patchg(actionwk, (unsigned char**)fripchg); /* Line 241, Address: 0x1026af0 */
  actionsub(actionwk); /* Line 242, Address: 0x1026b04 */
  frameout_s(actionwk); /* Line 243, Address: 0x1026b10 */
} /* Line 244, Address: 0x1026b1c */

void frip_chk(sprite_status* actionwk) { /* Line 246, Address: 0x1026b30 */
  sprite_status* a1;
  short d0, d1, d2, d3;

  a1 = &actwk[0]; /* Line 250, Address: 0x1026b50 */
  if (a1->mstno.b.h == 43) goto label1; /* Line 251, Address: 0x1026b58 */

  d0 = a1->xposi.w.h - actionwk->xposi.w.h; /* Line 253, Address: 0x1026b70 */
  d1 = actionwk->sprhsize; /* Line 254, Address: 0x1026ba0 */
  d0 += d1; /* Line 255, Address: 0x1026bb4 */
  if (d0 < 0) goto label1; /* Line 256, Address: 0x1026bc0 */
  d1 += d1; /* Line 257, Address: 0x1026bd0 */
  if (d0 >= d1) goto label1; /* Line 258, Address: 0x1026bdc */

  d0 = a1->xposi.w.h; /* Line 260, Address: 0x1026bf8 */
  d3 = actionwk->sprhsize; /* Line 261, Address: 0x1026c04 */
  d2 = actionwk->xposi.w.h - d3; /* Line 262, Address: 0x1026c18 */
  d0 -= d2; /* Line 263, Address: 0x1026c44 */
  if (actionwk->cddat & 1) { /* Line 264, Address: 0x1026c50 */

    d2 = 64 - d0; /* Line 266, Address: 0x1026c68 */
    d0 = d2; /* Line 267, Address: 0x1026c88 */
  }
  d2 = d0; /* Line 269, Address: 0x1026c90 */

  d0 = frip_posi[d2]; /* Line 271, Address: 0x1026c98 */
  if (a1->yspeed.w < 0) d0 = frip_posi_r[d2]; /* Line 272, Address: 0x1026cc0 */
  d0 += actionwk->yposi.w.h; /* Line 273, Address: 0x1026cfc */
  d1 = d0; /* Line 274, Address: 0x1026d10 */
  d3 = a1->sprvsize; /* Line 275, Address: 0x1026d18 */
  if (a1->yspeed.w < 0) d3 = -d3; /* Line 276, Address: 0x1026d28 */

  d1 -= d3; /* Line 278, Address: 0x1026d58 */
  d3 += a1->yposi.w.h; /* Line 279, Address: 0x1026d64 */
  d3 -= d0; /* Line 280, Address: 0x1026d74 */
  d3 += 8; /* Line 281, Address: 0x1026d80 */
  if (d3 < 0 || d3 >= 16) goto label1; /* Line 282, Address: 0x1026d8c */

  a1->yposi.w.h = d1; /* Line 284, Address: 0x1026db0 */
  if (a1->yspeed.w >= 0) { /* Line 285, Address: 0x1026db4 */

    ride_on_set(actionwk, a1); /* Line 287, Address: 0x1026dc8 */
  } /* Line 288, Address: 0x1026dd8 */
  else {

    a1->yspeed.w = 0; /* Line 291, Address: 0x1026de0 */
    a1->mspeed.w = a1->xspeed.w; /* Line 292, Address: 0x1026de4 */
  }

  return; /* Line 295, Address: 0x1026dec */
label1:
  ride_on_clr(actionwk, a1); /* Line 297, Address: 0x1026df4 */


} /* Line 300, Address: 0x1026e04 */
