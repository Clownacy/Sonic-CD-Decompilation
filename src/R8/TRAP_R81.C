#include "..\EQU.H"
#include "TRAP_R81.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"
#include "COLI8.H"

static void dair8_init(sprite_status* trapwk);
static void dair8_move(sprite_status* trapwk);
static void harir8_init(sprite_status* trapwk);
static void harir8_move(sprite_status* trapwk);
static void anar8_ridechk(sprite_status* trapwk);
static void anar8_rideclr(sprite_status* trapwk);
static void anar8_init(sprite_status* trapwk);
static void anar8_move1(sprite_status* trapwk);
static void anar8_move2(sprite_status* trapwk);
static void futagor8_ridechk(sprite_status* trapwk);
static void futagor8_init(sprite_status* trapwk);
static void futagor8_move1(sprite_status* trapwk);
































static sprite_pattern dai00 = { 1, { { -16, -16, 0, 288 } } };
sprite_pattern* togedair8pat[1] = { &dai00 };

void togedair8(sprite_status* trapwk) { /* Line 56, Address: 0x101c4d0 */
  void(*tbl[2])(sprite_status*) = { &dair8_init, &dair8_move }; /* Line 57, Address: 0x101c4dc */

  if (trapwk->userflag.b.h < 0) { harir8(trapwk); return; } /* Line 59, Address: 0x101c4f8 */
  tbl[trapwk->r_no0 / 2](trapwk); /* Line 60, Address: 0x101c524 */
  actionsub(trapwk); /* Line 61, Address: 0x101c560 */
  frameout_s00(trapwk, ((short*)trapwk)[29]); /* Line 62, Address: 0x101c56c */
} /* Line 63, Address: 0x101c580 */



static void dair8_init(sprite_status* trapwk) { /* Line 67, Address: 0x101c590 */
  sprite_status* new_actwk;

  trapwk->r_no0 += 2; /* Line 70, Address: 0x101c59c */
  trapwk->actflg |= 4; /* Line 71, Address: 0x101c5ac */

  trapwk->sprpri = 3; /* Line 73, Address: 0x101c5bc */
  trapwk->patbase = togedair8pat; /* Line 74, Address: 0x101c5c8 */
  ((short*)trapwk)[29] = trapwk->xposi.w.h; /* Line 75, Address: 0x101c5d8 */
  ((short*)trapwk)[27] = trapwk->yposi.w.h; /* Line 76, Address: 0x101c5e8 */
  trapwk->sprhsize = trapwk->sprvsize = 16; /* Line 77, Address: 0x101c5f8 */
  if (actwkchk(&new_actwk) != 0) { frameout(trapwk); return; } /* Line 78, Address: 0x101c610 */

  if (trapwk->userflag.b.h != 1) { /* Line 80, Address: 0x101c638 */
    new_actwk->actno = 10; /* Line 81, Address: 0x101c654 */
    new_actwk->xposi.w.h = trapwk->xposi.w.h; /* Line 82, Address: 0x101c660 */
    new_actwk->yposi.w.h = trapwk->yposi.w.h; /* Line 83, Address: 0x101c670 */
    new_actwk->actfree[15] = 232; /* Line 84, Address: 0x101c680 */
    ((unsigned short*)new_actwk)[28] = trapwk - actwk; /* Line 85, Address: 0x101c68c */
    new_actwk->userflag.b.h = trapwk->userflag.b.h; /* Line 86, Address: 0x101c6c0 */
    dair8_move(trapwk); /* Line 87, Address: 0x101c6d0 */
  } else { /* Line 88, Address: 0x101c6dc */
    new_actwk->actno = 54; /* Line 89, Address: 0x101c6e4 */
    new_actwk->userflag.b.h = -1; /* Line 90, Address: 0x101c6f0 */
    new_actwk->xposi.w.h = trapwk->xposi.w.h; /* Line 91, Address: 0x101c6fc */
    new_actwk->yposi.w.h = trapwk->yposi.w.h; /* Line 92, Address: 0x101c70c */
    new_actwk->actfree[15] = 232; /* Line 93, Address: 0x101c71c */
    ((unsigned short*)new_actwk)[28] = trapwk - actwk; /* Line 94, Address: 0x101c728 */
    dair8_move(trapwk); /* Line 95, Address: 0x101c75c */
  }
} /* Line 97, Address: 0x101c768 */



static void dair8_move(sprite_status* trapwk) { /* Line 101, Address: 0x101c780 */
  short cal_position;

  if (!(trapwk->actflg & 128)) return; /* Line 104, Address: 0x101c790 */

  if ((cal_position = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) /* Line 106, Address: 0x101c7a8 */
    cal_position = -cal_position; /* Line 107, Address: 0x101c7f4 */
  if (cal_position >= 32) return; /* Line 108, Address: 0x101c810 */


  hitchk(trapwk, &actwk[0]); /* Line 111, Address: 0x101c824 */
} /* Line 112, Address: 0x101c838 */



static sprite_pattern har00 = { 1, { { -16, -16, 0, 289 } } };
static sprite_pattern har01 = { 1, { { -16, -16, 16, 289 } } };
sprite_pattern* harir8pat[2] = { &har00, &har01 };

void harir8(sprite_status* trapwk) { /* Line 120, Address: 0x101c850 */
  unsigned short master;
  void(*tbl[2])(sprite_status*) = { &harir8_init, &harir8_move }; /* Line 122, Address: 0x101c860 */

  tbl[trapwk->r_no0 / 2](trapwk); /* Line 124, Address: 0x101c87c */
  actionsub(trapwk); /* Line 125, Address: 0x101c8b8 */
  if ((master = ((unsigned short*)trapwk)[28]) != 0) { /* Line 126, Address: 0x101c8c4 */

    if (actwk[master].actno == 0) { frameout(trapwk); return; } /* Line 128, Address: 0x101c8dc */
    trapwk->xposi.w.h = actwk[master].xposi.w.h + (short)(char)trapwk->actfree[14]; /* Line 129, Address: 0x101c91c */

    trapwk->yposi.w.h = actwk[master].yposi.w.h + (short)(char)trapwk->actfree[15]; /* Line 131, Address: 0x101c978 */
  }


  frameout_s00(trapwk, ((short*)trapwk)[29]); /* Line 135, Address: 0x101c9d4 */
} /* Line 136, Address: 0x101c9e8 */



static void harir8_init(sprite_status* trapwk) { /* Line 140, Address: 0x101ca00 */
  trapwk->r_no0 += 2; /* Line 141, Address: 0x101ca0c */
  trapwk->actflg |= 4; /* Line 142, Address: 0x101ca1c */

  trapwk->sprpri = 4; /* Line 144, Address: 0x101ca2c */
  trapwk->patbase = harir8pat; /* Line 145, Address: 0x101ca38 */
  ((short*)trapwk)[29] = trapwk->xposi.w.h; /* Line 146, Address: 0x101ca48 */
  ((short*)trapwk)[27] = trapwk->yposi.w.h; /* Line 147, Address: 0x101ca58 */

  trapwk->sprhsize = 16; /* Line 149, Address: 0x101ca68 */
  trapwk->sprvsize = 8; /* Line 150, Address: 0x101ca74 */
  if (trapwk->userflag.b.h != -1) { /* Line 151, Address: 0x101ca80 */
    trapwk->patno = 1; /* Line 152, Address: 0x101ca9c */
    trapwk->colino = 131; /* Line 153, Address: 0x101caa8 */
    trapwk->sprhsize = 18; /* Line 154, Address: 0x101cab4 */
  }
  harir8_move(trapwk); /* Line 156, Address: 0x101cac0 */
} /* Line 157, Address: 0x101cacc */



static void harir8_move(sprite_status* trapwk) { /* Line 161, Address: 0x101cae0 */
  short cal_position;

  if (trapwk->patno == 0) { /* Line 164, Address: 0x101caf0 */

    if ((cal_position = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) /* Line 166, Address: 0x101cb04 */
      cal_position = -cal_position; /* Line 167, Address: 0x101cb50 */
    if (cal_position >= 32) return; /* Line 168, Address: 0x101cb6c */

    if (hitchk(trapwk, &actwk[0]) == 0) return; /* Line 170, Address: 0x101cb80 */
    if (!(trapwk->cddat & 8)) return; /* Line 171, Address: 0x101cba4 */
    if (plpower_a || plpower_m) return; /* Line 172, Address: 0x101cbbc */

    if (actwk[0].r_no0 >= 4) return; /* Line 174, Address: 0x101cbe4 */
    if (((short*)&actwk[0])[26] != 0) return; /* Line 175, Address: 0x101cbfc */
    actwk[0].yposi.l -= actwk[0].yspeed.w << 8; /* Line 176, Address: 0x101cc14 */
    playdamageset(&actwk[0], trapwk); /* Line 177, Address: 0x101cc3c */
    return; /* Line 178, Address: 0x101cc50 */
  }


  if (!(trapwk->actflg & 128)) return; /* Line 182, Address: 0x101cc58 */

  if ((cal_position = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) /* Line 184, Address: 0x101cc70 */
    cal_position = -cal_position; /* Line 185, Address: 0x101ccbc */
  if (cal_position >= 32) return; /* Line 186, Address: 0x101ccd8 */


  hitchk(trapwk, &actwk[0]); /* Line 189, Address: 0x101ccec */
} /* Line 190, Address: 0x101cd00 */






























static unsigned char anar8pchgl[16] = {
  7, 32,
  6, 28,
  5, 24,
  4, 20,
  3, 16,
  2, 12,
  1,  8,
  0,  4
};
static unsigned char anar8pchgr[16] = {
  15, 32,
  14, 28,
  13, 24,
  12, 20,
  11, 16,
  10, 12,
   9,  8,
   8,  4
};
static unsigned char gater8pchgl[16] = { 0, 4, 1, 8, 2, 12, 3, 16, 4, 20, 5, 24, 6, 28, 7, 32 };
static unsigned char gater8pchgr[16] = { 8, 4, 9, 8, 10, 12, 11, 16, 12, 20, 13, 24, 14, 28, 15, 32 };
static sprite_pattern anal0 = { 1, { { -4, -8, 0, 290 } } };
static sprite_pattern anal1 = { 1, { { -8, -8, 0, 291 } } };
static sprite_pattern anal2 = { 1, { { -12, -8, 0, 292 } } };
static sprite_pattern anal3 = { 1, { { -16, -8, 0, 293 } } };
static sprite_pattern anal4 = { 1, { { -20, -8, 0, 294 } } };
static sprite_pattern anal5 = { 1, { { -24, -8, 0, 295 } } };
static sprite_pattern anal6 = { 1, { { -28, -8, 0, 296 } } };
static sprite_pattern anal7 = { 1, { { -32, -8, 0, 297 } } };
static sprite_pattern anar0 = { 1, { { -4, -8, 8, 290 } } };
static sprite_pattern anar1 = { 1, { { -8, -8, 8, 291 } } };
static sprite_pattern anar2 = { 1, { { -12, -8, 8, 292 } } };
static sprite_pattern anar3 = { 1, { { -16, -8, 8, 293 } } };
static sprite_pattern anar4 = { 1, { { -20, -8, 8, 294 } } };
static sprite_pattern anar5 = { 1, { { -24, -8, 8, 295 } } };
static sprite_pattern anar6 = { 1, { { -28, -8, 8, 296 } } };
static sprite_pattern anar7 = { 1, { { -32, -8, 8, 297 } } };
static sprite_pattern ana00 = { 1, { { -16, -20, 0, 0 } } };
static sprite_pattern ana01 = {
  2,
  { {
    { -64, -8, 0, 297 },
    { 0, -8, 8, 297 }
  } }
};
sprite_pattern* anar8pat[18] = {
  &anal0,
  &anal1,
  &anal2,
  &anal3,
  &anal4,
  &anal5,
  &anal6,
  &anal7,
  &anar0,
  &anar1,
  &anar2,
  &anar3,
  &anar4,
  &anar5,
  &anar6,
  &anar7,
  &ana00,
  &ana01
};

void anar8(sprite_status* trapwk) { /* Line 288, Address: 0x101cd20 */
  void(*tbl[3])(sprite_status*) = { &anar8_init, &anar8_move1, &anar8_move2 }; /* Line 289, Address: 0x101cd2c */

  tbl[trapwk->r_no0 / 2](trapwk); /* Line 291, Address: 0x101cd50 */
  actionsub(trapwk); /* Line 292, Address: 0x101cd8c */
  frameout_s00(trapwk, ((short*)trapwk)[29]); /* Line 293, Address: 0x101cd98 */
} /* Line 294, Address: 0x101cdac */


static void anar8_ridechk(sprite_status* trapwk) { /* Line 297, Address: 0x101cdc0 */
  ridechk(trapwk, &actwk[0]); /* Line 298, Address: 0x101cdcc */
} /* Line 299, Address: 0x101cde0 */


static void anar8_rideclr(sprite_status* trapwk) { /* Line 302, Address: 0x101cdf0 */
  ride_on_clr(trapwk, &actwk[0]); /* Line 303, Address: 0x101cdfc */
} /* Line 304, Address: 0x101ce10 */



static void anar8_init(sprite_status* trapwk) { /* Line 308, Address: 0x101ce20 */
  sprite_status* new_actwk;

  trapwk->r_no0 += 2; /* Line 311, Address: 0x101ce2c */
  trapwk->actflg |= 4; /* Line 312, Address: 0x101ce3c */
  trapwk->sprpri = 2; /* Line 313, Address: 0x101ce4c */

  trapwk->patbase = anar8pat; /* Line 315, Address: 0x101ce58 */
  trapwk->sprvsize = 8; /* Line 316, Address: 0x101ce68 */
  trapwk->sprhsize = 4; /* Line 317, Address: 0x101ce74 */
  trapwk->patno = 16; /* Line 318, Address: 0x101ce80 */

  if (trapwk->actfree[20] != 0) { anar8_move1(trapwk); return; } /* Line 320, Address: 0x101ce8c */

  trapwk->xposi.w.h -= 4; /* Line 322, Address: 0x101ceb4 */
  ((short*)trapwk)[29] = trapwk->xposi.w.h; /* Line 323, Address: 0x101cec4 */
  if (actwkchk(&new_actwk) != 0) { frameout(trapwk); return; } /* Line 324, Address: 0x101ced4 */
  new_actwk->actno = 55; /* Line 325, Address: 0x101cefc */
  new_actwk->xposi.w.h = trapwk->xposi.w.h + 128; /* Line 326, Address: 0x101cf08 */
  new_actwk->yposi.w.h = trapwk->yposi.w.h; /* Line 327, Address: 0x101cf2c */
  ((short*)new_actwk)[29] = ((short*)trapwk)[29]; /* Line 328, Address: 0x101cf3c */

  new_actwk->mstno.w = 1; /* Line 330, Address: 0x101cf4c */
  new_actwk->actfree[20] = 1; /* Line 331, Address: 0x101cf58 */
  anar8_move1(trapwk); /* Line 332, Address: 0x101cf64 */
} /* Line 333, Address: 0x101cf70 */



static void anar8_move1(sprite_status* trapwk) { /* Line 337, Address: 0x101cf80 */
  short x_adder;
  unsigned char* patchg_data;

  if (trapwk->actfree[16] != 0) { /* Line 341, Address: 0x101cf94 */
    --trapwk->actfree[16]; /* Line 342, Address: 0x101cfa8 */
    anar8_rideclr(trapwk); /* Line 343, Address: 0x101cfb8 */
    return; /* Line 344, Address: 0x101cfc4 */
  }

  if (trapwk->actfree[20] == 0) { /* Line 347, Address: 0x101cfcc */
    patchg_data = gater8pchgl; /* Line 348, Address: 0x101cfe0 */
    x_adder = 4; /* Line 349, Address: 0x101cfe8 */
  } else { /* Line 350, Address: 0x101cff4 */
    patchg_data = gater8pchgr; /* Line 351, Address: 0x101cffc */
    x_adder = -4; /* Line 352, Address: 0x101d004 */
  }

  if (trapwk->actflg & 128) soundset(164); /* Line 355, Address: 0x101d010 */

  trapwk->patno = patchg_data[trapwk->actfree[19] * 2]; /* Line 357, Address: 0x101d034 */
  trapwk->sprhsize = patchg_data[trapwk->actfree[19] * 2 + 1]; /* Line 358, Address: 0x101d054 */
  trapwk->xposi.w.h += x_adder; /* Line 359, Address: 0x101d078 */
  if (++trapwk->actfree[19] == 8) { /* Line 360, Address: 0x101d088 */
    trapwk->actfree[16] = 60; /* Line 361, Address: 0x101d0ac */
    trapwk->actfree[19] = 0; /* Line 362, Address: 0x101d0b8 */
    trapwk->r_no0 += 2; /* Line 363, Address: 0x101d0c0 */
  }
  anar8_ridechk(trapwk); /* Line 365, Address: 0x101d0d0 */
} /* Line 366, Address: 0x101d0dc */



static void anar8_move2(sprite_status* trapwk) { /* Line 370, Address: 0x101d100 */
  short x_adder;
  unsigned char* patchg_data;

  if (trapwk->actfree[16] != 0) { /* Line 374, Address: 0x101d114 */
    --trapwk->actfree[16]; /* Line 375, Address: 0x101d128 */
    anar8_ridechk(trapwk); /* Line 376, Address: 0x101d138 */
    return; /* Line 377, Address: 0x101d144 */
  }

  if (trapwk->actfree[20] == 0) { /* Line 380, Address: 0x101d14c */
    patchg_data = anar8pchgl; /* Line 381, Address: 0x101d160 */
    x_adder = -4; /* Line 382, Address: 0x101d168 */
  } else { /* Line 383, Address: 0x101d174 */
    patchg_data = anar8pchgr; /* Line 384, Address: 0x101d17c */
    x_adder = 4; /* Line 385, Address: 0x101d184 */
  }

  if (trapwk->actflg & 128) soundset(164); /* Line 388, Address: 0x101d190 */

  trapwk->patno = patchg_data[trapwk->actfree[19] * 2]; /* Line 390, Address: 0x101d1b4 */
  trapwk->sprhsize = patchg_data[trapwk->actfree[19] * 2 + 1]; /* Line 391, Address: 0x101d1d4 */
  trapwk->xposi.w.h += x_adder; /* Line 392, Address: 0x101d1f8 */
  if (++trapwk->actfree[19] == 8) { /* Line 393, Address: 0x101d208 */
    trapwk->actfree[16] = 60; /* Line 394, Address: 0x101d22c */
    trapwk->actfree[19] = 0; /* Line 395, Address: 0x101d238 */
    trapwk->patno = 16; /* Line 396, Address: 0x101d240 */
    trapwk->sprhsize = 0; /* Line 397, Address: 0x101d24c */
    trapwk->r_no0 -= 2; /* Line 398, Address: 0x101d254 */
    anar8_rideclr(trapwk); /* Line 399, Address: 0x101d264 */
    return; /* Line 400, Address: 0x101d270 */
  }
  anar8_ridechk(trapwk); /* Line 402, Address: 0x101d278 */
} /* Line 403, Address: 0x101d284 */







static unsigned char futagor8_pchg[48] = {
  0, 120,  8, 56,
  1,   4,  8, 40,
  2,   4,  8, 24,
  3,  32,  8,  8,
  4,   4, 24,  8,
  5,   4, 40,  8,
  6, 120, 56,  8,
  5,   4, 40,  8,
  4,   4, 24,  8,
  3,  32,  8,  8,
  2,   4, 24,  8,
  1,   4, 40,  8
};
static sprite_pattern fut00 = {
  7,
  { {
    { -8, -56, 0, 299 },
    { -8, -40, 0, 299 },
    { -8, -24, 0, 299 },
    { -8, -8, 0, 298 },
    { -8, 8, 0, 299 },
    { -8, 24, 0, 299 },
    { -8, 40, 0, 299 }
  } }
};
static sprite_pattern fut01 = {
  5,
  { {
    { -8, -40, 0, 299 },
    { -8, -24, 0, 299 },
    { -8, -8, 0, 298 },
    { -8, 8, 0, 299 },
    { -8, 24, 0, 299 }
  } }
};
static sprite_pattern fut02 = {
  3,
  { {
    { -8, -24, 0, 299 },
    { -8, -8, 0, 298 },
    { -8, 8, 0, 299 }
  } }
};
static sprite_pattern fut03 = { 1, { { -8, -8, 0, 298 } } };
static sprite_pattern fut04 = {
  3,
  { {
    { -24, -8, 0, 299 },
    { -8, -8, 0, 298 },
    { 8, -8, 0, 299 }
  } }
};
static sprite_pattern fut05 = {
  5,
  { {
    { -40, -8, 0, 299 },
    { -24, -8, 0, 299 },
    { -8, -8, 0, 298 },
    { 8, -8, 0, 299 },
    { 24, -8, 0, 299 }
  } }
};
static sprite_pattern fut06 = {
  7,
  { {
    { -56, -8, 0, 299 },
    { -40, -8, 0, 299 },
    { -24, -8, 0, 299 },
    { -8, -8, 0, 298 },
    { 8, -8, 0, 299 },
    { 24, -8, 0, 299 },
    { 40, -8, 0, 299 }
  } }
};
sprite_pattern* futagor8pat[7] = { &fut00, &fut01, &fut02, &fut03, &fut04, &fut05, &fut06 };

void futagor8(sprite_status* trapwk) { /* Line 488, Address: 0x101d2a0 */
  void(*tbl[2])(sprite_status*) = { &futagor8_init, &futagor8_move1 }; /* Line 489, Address: 0x101d2ac */

  tbl[trapwk->r_no0 / 2](trapwk); /* Line 491, Address: 0x101d2c8 */
  futagor8_ridechk(trapwk); /* Line 492, Address: 0x101d304 */
  actionsub(trapwk); /* Line 493, Address: 0x101d310 */
  frameout_s00(trapwk, ((short*)trapwk)[29]); /* Line 494, Address: 0x101d31c */
} /* Line 495, Address: 0x101d330 */


static void futagor8_ridechk(sprite_status* trapwk) { /* Line 498, Address: 0x101d340 */
  ride_on_chk(trapwk, &actwk[0]); /* Line 499, Address: 0x101d34c */
} /* Line 500, Address: 0x101d360 */



static void futagor8_init(sprite_status* trapwk) { /* Line 504, Address: 0x101d370 */
  trapwk->r_no0 += 2; /* Line 505, Address: 0x101d37c */
  trapwk->actflg |= 4; /* Line 506, Address: 0x101d38c */
  trapwk->sprpri = 3; /* Line 507, Address: 0x101d39c */

  trapwk->patbase = futagor8pat; /* Line 509, Address: 0x101d3a8 */
  ((short*)trapwk)[29] = trapwk->xposi.w.h; /* Line 510, Address: 0x101d3b8 */
  ((short*)trapwk)[27] = trapwk->yposi.w.h; /* Line 511, Address: 0x101d3c8 */
  futagor8_move1(trapwk); /* Line 512, Address: 0x101d3d8 */
} /* Line 513, Address: 0x101d3e4 */



static void futagor8_move1(sprite_status* trapwk) { /* Line 517, Address: 0x101d400 */
  unsigned char patchg_point;

  if (trapwk->actfree[16] == 0) { /* Line 520, Address: 0x101d40c */
    patchg_point = trapwk->actfree[18] * 4; /* Line 521, Address: 0x101d420 */
    trapwk->patno = futagor8_pchg[patchg_point]; /* Line 522, Address: 0x101d438 */
    trapwk->actfree[16] = futagor8_pchg[patchg_point + 1]; /* Line 523, Address: 0x101d454 */
    trapwk->sprhsize = futagor8_pchg[patchg_point + 2]; /* Line 524, Address: 0x101d474 */
    trapwk->sprvsize = futagor8_pchg[patchg_point + 3]; /* Line 525, Address: 0x101d494 */
  } /* Line 526, Address: 0x101d4b4 */
  else if (--trapwk->actfree[16] == 0) { /* Line 527, Address: 0x101d4bc */
    if (++trapwk->actfree[18] >= 12) trapwk->actfree[18] = 0; /* Line 528, Address: 0x101d4dc */
  }

  if (trapwk->patno != 0) trapwk->yspeed.w = 0; /* Line 531, Address: 0x101d508 */
  else trapwk->yspeed.w = 256; /* Line 532, Address: 0x101d52c */
} /* Line 533, Address: 0x101d538 */
