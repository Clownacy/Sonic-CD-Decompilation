#include "..\EQU.H"
#include "BEEM6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"

static sprite_pattern beem6pat0 = {
  1,
  { { -24, -24, 0, 417 } }
};
static sprite_pattern nullpat = {
  1,
  { { 0, 0, 0, 0 } }
};
sprite_pattern* beem6pat[2] = {
  &beem6pat0,
  &nullpat
};
short clrtblA[15] = {
  0, 0, 3808, 3808,
  0, 0,  238,  238,
  0, 0, 3598, 3598,
  0, 0, -1
};
short clrtblA2[9] = { 2656, 2656, 2720, 2720, 2656, 2656, 2720, 2720, -1 };
short clrtblB[15] = {
  0, 0, 3808, 3808,
  0, 0,  238,  238,
  0, 0, 3598, 3598,
  0, 0, -1
};
short clrtblB2[9] = { 2118, 2118, 2122, 2122, 2118, 2118, 2122, 2122, -1 };
short clrtblD[15] = {
  0, 0, 3808, 3808,
  0, 0,  238,  238,
  0, 0, 3598, 3598,
  0, 0, -1
};
short clrtblD2[9] = { 580, 580, 584, 584, 580, 580, 584, 584, -1 };










void beem6(sprite_status* actionwk) { /* Line 50, Address: 0x10187a0 */
  switch (actionwk->r_no0) /* Line 51, Address: 0x10187ac */
  {
    case 0:
      beem6_init(actionwk); /* Line 54, Address: 0x10187e0 */
    case 2:
      beem6_wait(actionwk); /* Line 56, Address: 0x10187ec */
      break; /* Line 57, Address: 0x10187f8 */
    case 4:
      beem6_move(actionwk); /* Line 59, Address: 0x1018800 */
  }

  actionsub(actionwk); /* Line 62, Address: 0x101880c */
  frameout_s(actionwk); /* Line 63, Address: 0x1018818 */
} /* Line 64, Address: 0x1018824 */


void beem6_init(sprite_status* actionwk) { /* Line 67, Address: 0x1018840 */
  actionwk->r_no0 += 2; /* Line 68, Address: 0x101884c */
  actionwk->actflg |= 4; /* Line 69, Address: 0x101885c */
  actionwk->sprpri = 4; /* Line 70, Address: 0x101886c */
  actionwk->sproffset = 25432; /* Line 71, Address: 0x1018878 */
  actionwk->patbase = beem6pat; /* Line 72, Address: 0x1018884 */
  actionwk->sprvsize = 16; /* Line 73, Address: 0x1018894 */
  actionwk->sprhsize = 16; /* Line 74, Address: 0x10188a0 */
  actionwk->patno = actionwk->userflag.b.h; /* Line 75, Address: 0x10188ac */
  beem6_actsch(); /* Line 76, Address: 0x10188bc */

  clrset0_2(); /* Line 78, Address: 0x10188c4 */
} /* Line 79, Address: 0x10188cc */

void beem6_wait(sprite_status* actionwk) { /* Line 81, Address: 0x10188e0 */
  short d0;

  if (actionwk->userflag.b.h == 0) return; /* Line 84, Address: 0x10188f0 */
  beem6_posiset(actionwk); /* Line 85, Address: 0x1018908 */
  if (((short*)actionwk)[31] != 0) /* Line 86, Address: 0x1018914 */
  {
    cntdwn(actionwk); /* Line 88, Address: 0x101892c */
    return; /* Line 89, Address: 0x1018938 */
  }
  clrset0(); /* Line 91, Address: 0x1018940 */
  if (time_flag == 2) /* Line 92, Address: 0x1018948 */
  {
    if (generate_flag) return; /* Line 94, Address: 0x1018960 */
  }

  if (stageno.b.l + 1 == 0) /* Line 97, Address: 0x1018970 */
  {
    if (scra_v_posit.w.h >= 1024) return; /* Line 99, Address: 0x101898c */
  }

  d0 = 360; /* Line 102, Address: 0x10189a8 */
  if (time_flag != 0) /* Line 103, Address: 0x10189b4 */
  {
    d0 = 480; /* Line 105, Address: 0x10189c8 */
    if (time_flag - 1 != 0) d0 = 240; /* Line 106, Address: 0x10189d4 */
  }

  ((short*)actionwk)[31] = d0; /* Line 109, Address: 0x10189f8 */
} /* Line 110, Address: 0x1018a00 */

void cntdwn(sprite_status* actionwk) { /* Line 112, Address: 0x1018a20 */
  if (--((short*)actionwk)[31]) return; /* Line 113, Address: 0x1018a2c */
  actionwk->r_no0 += 2; /* Line 114, Address: 0x1018a4c */
  ((short*)actionwk)[31] = 120; /* Line 115, Address: 0x1018a5c */
  ((short*)actionwk)[26] = 90; /* Line 116, Address: 0x1018a68 */
  actionwk->actfree[4] = 0; /* Line 117, Address: 0x1018a74 */

  if (!(actionwk->actflg & 128)) /* Line 119, Address: 0x1018a7c */
  {
    beem6_move(actionwk); /* Line 121, Address: 0x1018a94 */
    return; /* Line 122, Address: 0x1018aa0 */
  }
  soundset(178); /* Line 124, Address: 0x1018aa8 */
  beem6_move(actionwk); /* Line 125, Address: 0x1018ab4 */
} /* Line 126, Address: 0x1018ac0 */


void beem6_move(sprite_status* actionwk) { /* Line 129, Address: 0x1018ad0 */
  beem6_posiset(actionwk); /* Line 130, Address: 0x1018adc */
  if (((short*)actionwk)[26] != 0) /* Line 131, Address: 0x1018ae8 */
  {
    maeclrset(actionwk, actionwk->actfree[18]); /* Line 133, Address: 0x1018b00 */
    if (--((short*)actionwk)[26]) return; /* Line 134, Address: 0x1018b1c */
    clrset0(); /* Line 135, Address: 0x1018b3c */
  }

  st6clrchg = actionwk->actfree[18] + 1; /* Line 138, Address: 0x1018b44 */
  clrset1(actionwk, actionwk->actfree[18]); /* Line 139, Address: 0x1018b60 */
  if (--((short*)actionwk)[31]) return; /* Line 140, Address: 0x1018b7c */
  actionwk->r_no0 -= 2; /* Line 141, Address: 0x1018b9c */
  st6clrchg = 0; /* Line 142, Address: 0x1018bac */
  if (++actionwk->actfree[18] < 3) return; /* Line 143, Address: 0x1018bb4 */
  actionwk->actfree[18] = 0; /* Line 144, Address: 0x1018bd8 */
  ((short*)actionwk)[33] = 0; /* Line 145, Address: 0x1018be0 */
} /* Line 146, Address: 0x1018be8 */


void beem6_posiset(sprite_status* actionwk) { /* Line 149, Address: 0x1018c00 */
  actionwk->xposi.w.h = actwk[0].xposi.w.h; /* Line 150, Address: 0x1018c08 */
  actionwk->yposi.w.h = actwk[0].yposi.w.h; /* Line 151, Address: 0x1018c18 */
} /* Line 152, Address: 0x1018c28 */


void beem6_actsch() { /* Line 155, Address: 0x1018c40 */
  sprite_status* a1;
  short d0;

  a1 = &actwk[32]; /* Line 159, Address: 0x1018c4c */

  for (d0 = 0; d0 < 96; ++d0, ++a1) /* Line 161, Address: 0x1018c58 */
  {
    if (a1->actno == 33) /* Line 163, Address: 0x1018c64 */
      if (a1->userflag.b.h) return; /* Line 164, Address: 0x1018c7c */
  } /* Line 165, Address: 0x1018c8c */
  if (actwkchk(&a1) != 0) return; /* Line 166, Address: 0x1018cb8 */
  a1->actno = 33; /* Line 167, Address: 0x1018ccc */
  a1->userflag.b.h = 1; /* Line 168, Address: 0x1018cd8 */
  a1->xposi.w.h = actwk[0].xposi.w.h; /* Line 169, Address: 0x1018ce4 */
  a1->yposi.w.h = actwk[0].yposi.w.h; /* Line 170, Address: 0x1018cf4 */
} /* Line 171, Address: 0x1018d04 */


void clrset0() { /* Line 174, Address: 0x1018d20 */
  PALETTEENTRY *lpPe_a2, *lpPe_a3;
  PALETTEENTRY dummy;
  short d0, d2;

  lpPe_a3 = &lpcolorwk[32]; /* Line 179, Address: 0x1018d34 */
  d0 = 1574; /* Line 180, Address: 0x1018d40 */
  d2 = 1606; /* Line 181, Address: 0x1018d4c */
  if (time_flag == 0) goto label1; /* Line 182, Address: 0x1018d58 */
  lpPe_a3 = &lpcolorwk[61]; /* Line 183, Address: 0x1018d6c */
  d0 = 546; /* Line 184, Address: 0x1018d78 */
  d2 = 1664; /* Line 185, Address: 0x1018d84 */
  if (time_flag - 1 == 0) goto label1; /* Line 186, Address: 0x1018d90 */
  d0 = 1026; /* Line 187, Address: 0x1018da8 */
  d2 = 582; /* Line 188, Address: 0x1018db4 */
  if (generate_flag != 0) return; /* Line 189, Address: 0x1018dc0 */

label1:
  lpPe_a2 = &lpcolorwk[50]; /* Line 192, Address: 0x1018dd4 */
  dummy.peRed = (d0 & 15) * 16; /* Line 193, Address: 0x1018de0 */
  dummy.peGreen = d0 & 240; /* Line 194, Address: 0x1018df8 */
  dummy.peBlue = (d0 & 3840) >> 4; /* Line 195, Address: 0x1018e0c */
  dummy.peFlags = 1; /* Line 196, Address: 0x1018e24 */
  *lpPe_a2++ = dummy; /* Line 197, Address: 0x1018e2c */
  *lpPe_a2++ = dummy; /* Line 198, Address: 0x1018e58 */
  *lpPe_a2++ = dummy; /* Line 199, Address: 0x1018e84 */

  dummy.peRed = (d2 & 15) * 16; /* Line 201, Address: 0x1018eb0 */
  dummy.peGreen = d2 & 240; /* Line 202, Address: 0x1018ec8 */
  dummy.peBlue = (d2 & 3840) >> 4; /* Line 203, Address: 0x1018edc */
  dummy.peFlags = 1; /* Line 204, Address: 0x1018ef4 */
  *lpPe_a3++ = dummy; /* Line 205, Address: 0x1018efc */
} /* Line 206, Address: 0x1018f28 */

void clrset0_2() { /* Line 208, Address: 0x1018f50 */
  PALETTEENTRY *lpPe_a2, *lpPe_a3;
  PALETTEENTRY dummy;
  short d0, d2;

  lpPe_a3 = &lpcolorwk2[32]; /* Line 213, Address: 0x1018f64 */
  d0 = 1574; /* Line 214, Address: 0x1018f70 */
  d2 = 1606; /* Line 215, Address: 0x1018f7c */
  if (time_flag == 0) goto label1; /* Line 216, Address: 0x1018f88 */
  lpPe_a3 = &lpcolorwk2[61]; /* Line 217, Address: 0x1018f9c */
  d0 = 546; /* Line 218, Address: 0x1018fa8 */
  d2 = 1664; /* Line 219, Address: 0x1018fb4 */
  if (time_flag - 1 == 0) goto label1; /* Line 220, Address: 0x1018fc0 */
  d0 = 1026; /* Line 221, Address: 0x1018fd8 */
  d2 = 582; /* Line 222, Address: 0x1018fe4 */
  if (generate_flag != 0) return; /* Line 223, Address: 0x1018ff0 */

label1:
  lpPe_a2 = &lpcolorwk2[50]; /* Line 226, Address: 0x1019004 */
  dummy.peRed = (d0 & 15) * 16; /* Line 227, Address: 0x1019010 */
  dummy.peGreen = d0 & 240; /* Line 228, Address: 0x1019028 */
  dummy.peBlue = (d0 & 3840) >> 4; /* Line 229, Address: 0x101903c */
  dummy.peFlags = 1; /* Line 230, Address: 0x1019054 */
  *lpPe_a2++ = dummy; /* Line 231, Address: 0x101905c */
  *lpPe_a2++ = dummy; /* Line 232, Address: 0x1019088 */
  *lpPe_a2++ = dummy; /* Line 233, Address: 0x10190b4 */

  dummy.peRed = (d2 & 15) * 16; /* Line 235, Address: 0x10190e0 */
  dummy.peGreen = d2 & 240; /* Line 236, Address: 0x10190f8 */
  dummy.peBlue = (d2 & 3840) >> 4; /* Line 237, Address: 0x101910c */
  dummy.peFlags = 1; /* Line 238, Address: 0x1019124 */
  *lpPe_a3++ = dummy; /* Line 239, Address: 0x101912c */
} /* Line 240, Address: 0x1019158 */





















































void clrset1(sprite_status* actionwk, char d0) { /* Line 294, Address: 0x1019180 */

  char clrsel[3] = { 0, 2, 4 }; /* Line 296, Address: 0x1019198 */
  PALETTEENTRY* lpPe_a2;
  PALETTEENTRY dummy;
  short* a1;
  short col;

  d0 = clrsel[d0] >> 1; /* Line 302, Address: 0x10191bc */
  lpPe_a2 = &lpcolorwk[d0 + 50]; /* Line 303, Address: 0x10191e8 */
  a1 = clrtblB; /* Line 304, Address: 0x1019208 */
  if (time_flag != 0) /* Line 305, Address: 0x1019210 */
  {
    a1 = clrtblA; /* Line 307, Address: 0x1019224 */
    if (time_flag - 1 != 0) /* Line 308, Address: 0x101922c */
      a1 = clrtblD; /* Line 309, Address: 0x1019244 */
  }

  col = a1[actionwk->actfree[20]]; /* Line 312, Address: 0x101924c */
  dummy.peRed = (col & 15) * 16; /* Line 313, Address: 0x101926c */
  dummy.peGreen = col & 240; /* Line 314, Address: 0x1019284 */
  dummy.peBlue = (col & 3840) >> 4; /* Line 315, Address: 0x1019298 */
  dummy.peFlags = 1; /* Line 316, Address: 0x10192b0 */
  *lpPe_a2++ = dummy; /* Line 317, Address: 0x10192b8 */
  col = a1[++actionwk->actfree[20]]; /* Line 318, Address: 0x10192e4 */
  if (col == -1) actionwk->actfree[20] = 0; /* Line 319, Address: 0x1019310 */

  lpPe_a2 = &lpcolorwk[32]; /* Line 321, Address: 0x101932c */
  a1 = clrtblB2; /* Line 322, Address: 0x1019338 */
  if (time_flag != 0) /* Line 323, Address: 0x1019340 */
  {
    lpPe_a2 = &lpcolorwk[61]; /* Line 325, Address: 0x1019354 */
    a1 = clrtblA2; /* Line 326, Address: 0x1019360 */
    if (time_flag - 1 != 0) /* Line 327, Address: 0x1019368 */
      a1 = clrtblD2; /* Line 328, Address: 0x1019380 */
  }

  col = a1[actionwk->actfree[21]]; /* Line 331, Address: 0x1019388 */
  dummy.peRed = (col & 15) * 16; /* Line 332, Address: 0x10193a8 */
  dummy.peGreen = col & 240; /* Line 333, Address: 0x10193c0 */
  dummy.peBlue = (col & 3840) >> 4; /* Line 334, Address: 0x10193d4 */
  dummy.peFlags = 1; /* Line 335, Address: 0x10193ec */
  *lpPe_a2++ = dummy; /* Line 336, Address: 0x10193f4 */
  col = a1[++actionwk->actfree[21]]; /* Line 337, Address: 0x1019420 */
  if (col == -1) actionwk->actfree[21] = 0; /* Line 338, Address: 0x101944c */
} /* Line 339, Address: 0x1019468 */



void maeclrset(sprite_status* actionwk, char d0) { /* Line 343, Address: 0x1019480 */
  char clrsel[3] = { 0, 2, 4 }; /* Line 344, Address: 0x1019494 */
  PALETTEENTRY* lpPe_a2;
  PALETTEENTRY dummy;
  short col;

  col = clrsel[d0] >> 1; /* Line 349, Address: 0x10194b8 */
  lpPe_a2 = &lpcolorwk[col + 50]; /* Line 350, Address: 0x10194e8 */

  col = 128; /* Line 352, Address: 0x1019504 */

  if (actionwk->actfree[4] & 2) col = 0; /* Line 354, Address: 0x1019510 */

  dummy.peRed = (col & 15) * 16; /* Line 356, Address: 0x101952c */
  dummy.peGreen = col & 240; /* Line 357, Address: 0x1019544 */
  dummy.peBlue = (col & 3840) >> 4; /* Line 358, Address: 0x1019558 */
  dummy.peFlags = 1; /* Line 359, Address: 0x1019570 */
  *lpPe_a2++ = dummy; /* Line 360, Address: 0x1019578 */

  ++actionwk->actfree[4]; /* Line 362, Address: 0x10195a4 */
  actionwk->actfree[4] &= 3; /* Line 363, Address: 0x10195b4 */
} /* Line 364, Address: 0x10195c4 */
