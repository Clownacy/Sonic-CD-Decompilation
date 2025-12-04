#include "..\EQU.H"
#include "TRAP_R83.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\RIDECHK.H"
#include "COLI8.H"

static void tr8_fout(sprite_status* trapwk);
static void togeita_ridechk(sprite_status* trapwk); static void togeita_init(sprite_status* trapwk); static void togeita_dataset(sprite_status* trapwk, sprite_status* new_actwk, unsigned char* togeita_data); static void setitano(sprite_status* trapwk); static void togeita_move1(sprite_status* trapwk); static unsigned char togeita_plchk_1(sprite_status* trapwk, short cal_x); static void togeita_move2(sprite_status* trapwk); static void itaset_chk(sprite_status* trapwk); static void togeita_move3(sprite_status* trapwk); static void togeitax(sprite_status* trapwk);
static void dair8_init(sprite_status* trapwk); static void dair8_move(sprite_status* trapwk);
static void harir8_init(sprite_status* trapwk); static void harir8_move(sprite_status* trapwk);





static void tr8_fout(sprite_status* trapwk) { /* Line 18, Address: 0x1027d20 */
  unsigned short status;

  if ((status = trapwk->cdsts) == 0) { frameout(trapwk); return; } /* Line 21, Address: 0x1027d30 */
  status = (unsigned short)time_flag + status * 3; /* Line 22, Address: 0x1027d64 */
  flagwork[status] &= 127; /* Line 23, Address: 0x1027d8c */
  frameout(trapwk); /* Line 24, Address: 0x1027da8 */
} /* Line 25, Address: 0x1027db4 */



































static unsigned char togeita_data0[12] = { 1, 204, 28, 8, 4, 188, 12, 8, 5, 220, 44, 8 };
static unsigned char togeita_data1[12] = { 3, 0, 24, 8, 3, 224, 24, 8, 3, 32, 24, 8 };
static unsigned char togeita_data2[12] = { 2, 52, 28, 8, 5, 36, 44, 8, 4, 68, 12, 8 };
static sprite_pattern tog00 = {
  6,
  { {
    { -80, -12, 0, 289 },
    { -56, -12, 0, 288 },
    { -24, -12, 0, 290 },
    { 0, -12, 0, 290 },
    { 24, -12, 0, 288 },
    { 56, -12, 0, 288 }
  } }
};
static sprite_pattern tog01 = {
  2,
  { {
    { -28, -8, 0, 289 },
    { -4, -8, 0, 288 }
  } }
};
static sprite_pattern tog02 = {
  2,
  { {
    { -28, -8, 0, 288 },
    { 4, -8, 0, 289 }
  } }
};
static sprite_pattern tog03 = {
  2,
  { {
    { -24, -8, 0, 290 },
    { 0, -8, 0, 290 }
  } }
};
static sprite_pattern tog04 = { 1, { { -12, -8, 0, 289 } } };
static sprite_pattern tog05 = {
  3,
  { {
    { -44, -8, 0, 288 },
    { -12, -8, 0, 288 },
    { 20, -8, 0, 289 }
  } }
};
static sprite_pattern tog06 = { 1, { { -16, -20, 0, 0 } } };
sprite_pattern* togeitapat[7] = {
  &tog00,
  &tog01,
  &tog02,
  &tog03,
  &tog04,
  &tog05,
  &tog06
};

void togeita(sprite_status* trapwk) { /* Line 116, Address: 0x1027dd0 */
  void(*tbl[4])(sprite_status*) = { &togeita_init, &togeita_move1, &togeita_move2, &togeita_move3 }; /* Line 117, Address: 0x1027ddc */


  if (trapwk->userflag.b.h < 0) { togeitax(trapwk); return; } /* Line 120, Address: 0x1027e08 */
  tbl[trapwk->r_no0 / 2](trapwk); /* Line 121, Address: 0x1027e34 */
  togeita_ridechk(trapwk); /* Line 122, Address: 0x1027e70 */
  actionsub(trapwk); /* Line 123, Address: 0x1027e7c */
  frameout_s00(trapwk, ((short*)trapwk)[29]); /* Line 124, Address: 0x1027e88 */
} /* Line 125, Address: 0x1027e9c */


static void togeita_ridechk(sprite_status* trapwk) { /* Line 128, Address: 0x1027eb0 */
  short cal_position;

  if (trapwk->patno == 3) return; /* Line 131, Address: 0x1027ec0 */
  if (!(trapwk->actflg & 128)) return; /* Line 132, Address: 0x1027ed8 */
  if ((cal_position = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) /* Line 133, Address: 0x1027ef0 */
    cal_position = -cal_position; /* Line 134, Address: 0x1027f3c */
  if (cal_position < 32) /* Line 135, Address: 0x1027f58 */
    ride_on_chk(trapwk, &actwk[0]); /* Line 136, Address: 0x1027f6c */
} /* Line 137, Address: 0x1027f80 */


static void togeita_init(sprite_status* trapwk) { /* Line 140, Address: 0x1027fa0 */
  unsigned char patchg_point;
  sprite_status* new_actwk;

  trapwk->r_no0 += 2; /* Line 144, Address: 0x1027fb0 */
  trapwk->actflg |= 4; /* Line 145, Address: 0x1027fc0 */
  trapwk->sprpri = 3; /* Line 146, Address: 0x1027fd0 */

  trapwk->patbase = togeitapat; /* Line 148, Address: 0x1027fdc */

  setitano(trapwk); /* Line 150, Address: 0x1027fec */

  if (trapwk->actfree[19] == 0) { /* Line 152, Address: 0x1027ff8 */

    patchg_point = trapwk->actfree[18] * 4; /* Line 154, Address: 0x102800c */
    trapwk->patno = togeita_data0[patchg_point]; /* Line 155, Address: 0x1028024 */
    trapwk->sprhsize = togeita_data0[patchg_point + 2]; /* Line 156, Address: 0x1028040 */
    trapwk->sprvsize = togeita_data0[patchg_point + 3]; /* Line 157, Address: 0x1028060 */
    ((short*)trapwk)[29] = trapwk->xposi.w.h; /* Line 158, Address: 0x1028080 */
    ((short*)trapwk)[27] = trapwk->yposi.w.h; /* Line 159, Address: 0x1028090 */
    trapwk->xposi.w.h += (char)togeita_data0[patchg_point + 1]; /* Line 160, Address: 0x10280a0 */
    trapwk->actfree[17] = 1; /* Line 161, Address: 0x10280d8 */

    if (actwkchk(&new_actwk) != 0) { tr8_fout(trapwk); return; } /* Line 163, Address: 0x10280e4 */
    new_actwk->actno = 51; /* Line 164, Address: 0x102810c */
    new_actwk->actfree[19] = 1; /* Line 165, Address: 0x1028118 */
    togeita_dataset(trapwk, new_actwk, togeita_data1); /* Line 166, Address: 0x1028124 */

    if (actwkchk(&new_actwk) != 0) { tr8_fout(trapwk); return; } /* Line 168, Address: 0x102813c */
    new_actwk->actno = 51; /* Line 169, Address: 0x1028164 */
    new_actwk->actfree[19] = 2; /* Line 170, Address: 0x1028170 */
    togeita_dataset(trapwk, new_actwk, togeita_data2); /* Line 171, Address: 0x102817c */
  }

  if (trapwk->patno == 3) return; /* Line 174, Address: 0x1028194 */
  if (actwkchk(&new_actwk) != 0) return; /* Line 175, Address: 0x10281ac */
  new_actwk->actno = 51; /* Line 176, Address: 0x10281c0 */
  new_actwk->userflag.b.h = -1; /* Line 177, Address: 0x10281cc */
  new_actwk->xposi.w.h = trapwk->xposi.w.h; /* Line 178, Address: 0x10281d8 */
  new_actwk->actfree[18] = trapwk->patno; /* Line 179, Address: 0x10281e8 */
  ((unsigned short*)new_actwk)[28] = trapwk - actwk; /* Line 180, Address: 0x10281f8 */
  ((unsigned short*)trapwk)[28] = new_actwk - actwk; /* Line 181, Address: 0x102822c */
} /* Line 182, Address: 0x1028260 */


static void togeita_dataset(sprite_status* trapwk, sprite_status* new_actwk, unsigned char* togeita_data) { /* Line 185, Address: 0x1028280 */
  unsigned char patchg_point;

  patchg_point = trapwk->actfree[18] * 4; /* Line 188, Address: 0x1028294 */
  new_actwk->patno = togeita_data[patchg_point]; /* Line 189, Address: 0x10282ac */
  new_actwk->sprhsize = togeita_data[patchg_point + 2]; /* Line 190, Address: 0x10282c4 */
  new_actwk->sprvsize = togeita_data[patchg_point + 3]; /* Line 191, Address: 0x10282e0 */
  ((short*)new_actwk)[29] = ((short*)trapwk)[29]; /* Line 192, Address: 0x10282fc */

  new_actwk->yposi.w.h = trapwk->yposi.w.h; /* Line 194, Address: 0x102830c */
  new_actwk->xposi.w.h = ((short*)trapwk)[29] + (short)(char)togeita_data[patchg_point + 1]; /* Line 195, Address: 0x102831c */

  new_actwk->userflag.b.h = trapwk->userflag.b.h; /* Line 197, Address: 0x102836c */
} /* Line 198, Address: 0x102837c */



static void setitano(sprite_status* trapwk) { /* Line 202, Address: 0x1028390 */
  unsigned char tbl[56] = { /* Line 203, Address: 0x1028398 */
    0, 1, 0, 2, 0, 0, 0, 0,
    1, 2, 1, 2, 1, 2, 1, 2,
    0, 2, 1, 2, 0, 1, 2, 1,
    1, 2, 1, 2, 2, 1, 2, 2,
    1, 2, 1, 1, 0, 1, 2, 0,
    1, 2, 2, 1, 0, 1, 2, 1,
    1, 0, 2, 1, 0, 1, 2, 2
};

  trapwk->actfree[18] = tbl[trapwk->userflag.b.h]; /* Line 213, Address: 0x10283cc */
} /* Line 214, Address: 0x10283ec */



static void togeita_move1(sprite_status* trapwk) { /* Line 218, Address: 0x1028400 */
  short position_check, cal_x;

  if ((position_check = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) return; /* Line 221, Address: 0x1028414 */
  if (position_check >= 256) return; /* Line 222, Address: 0x1028460 */

  if (trapwk->userflag.b.h == 0) cal_x = 48; /* Line 224, Address: 0x1028474 */
  else cal_x = 80; /* Line 225, Address: 0x10284a0 */
  if (togeita_plchk_1(trapwk, cal_x)) trapwk->r_no0 += 2; /* Line 226, Address: 0x10284ac */
} /* Line 227, Address: 0x10284d4 */



static unsigned char togeita_plchk_1(sprite_status* trapwk, short cal_x) { /* Line 231, Address: 0x10284f0 */
  short position_check;

  if ((position_check = actwk[0].xposi.w.h - ((short*)trapwk)[29] + cal_x) < 0) /* Line 234, Address: 0x1028500 */
    return 0; /* Line 235, Address: 0x102855c */
  if (position_check >= cal_x * 2) return 0; /* Line 236, Address: 0x1028568 */
  return 1; /* Line 237, Address: 0x1028598 */
} /* Line 238, Address: 0x102859c */



static void togeita_move2(sprite_status* trapwk) { /* Line 242, Address: 0x10285b0 */
  short col_data;
  int stack_yposi;
  short tbl[6] = { 8, 32, 56, 80, 104, 128 }; /* Line 245, Address: 0x10285c4 */


  if (trapwk->userflag.b.h == 0 && trapwk->actfree[19] == 0) /* Line 248, Address: 0x10285f8 */
    itaset_chk(trapwk); /* Line 249, Address: 0x1028624 */
  if (trapwk->actfree[21] != 0) return; /* Line 250, Address: 0x1028630 */
  stack_yposi = trapwk->yposi.l; /* Line 251, Address: 0x1028644 */
  trapwk->yposi.w.h += tbl[trapwk->userflag.b.h]; /* Line 252, Address: 0x102864c */
  col_data = emycol_d(trapwk); /* Line 253, Address: 0x1028678 */
  trapwk->yposi.l = stack_yposi; /* Line 254, Address: 0x102868c */
  if (col_data >= 0) { /* Line 255, Address: 0x1028694 */
    trapwk->yposi.l += 32768; /* Line 256, Address: 0x10286a4 */
    trapwk->yspeed.w = 128; /* Line 257, Address: 0x10286b8 */
  } else { /* Line 258, Address: 0x10286c4 */
    trapwk->yspeed.w = 0; /* Line 259, Address: 0x10286cc */
    trapwk->actfree[21] = 255; /* Line 260, Address: 0x10286d4 */
  }
} /* Line 262, Address: 0x10286e0 */



static void itaset_chk(sprite_status* trapwk) { /* Line 266, Address: 0x1028700 */
  short cal_position;
  sprite_status* new_actwk;

  if ((cal_position = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) { /* Line 270, Address: 0x1028710 */
    cal_position = -cal_position; /* Line 271, Address: 0x102875c */
    if (cal_position >= 128) return; /* Line 272, Address: 0x1028778 */
  }
  if (togeita_plchk_1(trapwk, 160) == 0) return; /* Line 274, Address: 0x102878c */
  switch (++((short*)trapwk)[26]) { /* Line 275, Address: 0x10287a8 */

    case 300:

    case 600:

    case 840:

    case 1080:
     break;

    default:
      return; /* Line 287, Address: 0x10287f8 */
  }

  if (trapwk->actfree[17] < 5) { /* Line 290, Address: 0x1028800 */
    if (actwkchk(&new_actwk) != 0) return; /* Line 291, Address: 0x1028818 */

    new_actwk->actno = 51; /* Line 293, Address: 0x102882c */
    new_actwk->xposi.w.h = ((short*)trapwk)[29]; /* Line 294, Address: 0x1028838 */
    new_actwk->yposi.w.h = ((short*)trapwk)[27] - (short)((char)trapwk->actfree[17] * 16); /* Line 295, Address: 0x1028848 */

    new_actwk->userflag.b.h = trapwk->actfree[17]; /* Line 297, Address: 0x1028898 */
    ++trapwk->actfree[17]; /* Line 298, Address: 0x10288a8 */
  }
} /* Line 300, Address: 0x10288b8 */



static void togeita_move3(sprite_status* trapwk) { /* Line 304, Address: 0x10288d0 */
  trapwk->actno = trapwk->actno; /* Line 305, Address: 0x10288d8 */
} /* Line 306, Address: 0x10288e8 */



static void togeitax(sprite_status* trapwk) { /* Line 310, Address: 0x1028900 */
  unsigned short ride_number;
  unsigned char colitbl[6] = { /* Line 312, Address: 0x1028910 */
    0,
    156,
    156,
    0,
    155,
    157
  };
  trapwk->actflg |= 4; /* Line 320, Address: 0x1028944 */
  trapwk->patbase = togeitapat; /* Line 321, Address: 0x1028954 */

  trapwk->patno = 6; /* Line 323, Address: 0x1028964 */


  ride_number = ((unsigned short*)trapwk)[28]; /* Line 326, Address: 0x1028970 */
  if (actwk[ride_number].actno != 51) /* Line 327, Address: 0x102897c */
  { frameout(trapwk); return; } /* Line 328, Address: 0x10289ac */
  trapwk->yspeed.w = actwk[ride_number].yspeed.w; /* Line 329, Address: 0x10289c0 */
  trapwk->yposi.w.h = actwk[ride_number].yposi.w.h + 12; /* Line 330, Address: 0x10289e8 */

  trapwk->colino = colitbl[trapwk->actfree[18]]; /* Line 332, Address: 0x1028a24 */
  actionsub(trapwk); /* Line 333, Address: 0x1028a40 */
} /* Line 334, Address: 0x1028a4c */




































static sprite_pattern dai00 = { 1, { { -16, -16, 0, 291 } } };
sprite_pattern* togedair8pat[1] = { &dai00 };

void togedair8(sprite_status* trapwk) { /* Line 374, Address: 0x1028a60 */
  void(*tbl[2])(sprite_status*) = { &dair8_init, &dair8_move }; /* Line 375, Address: 0x1028a6c */

  if (trapwk->userflag.b.h < 0) { harir8(trapwk); return; } /* Line 377, Address: 0x1028a88 */
  tbl[trapwk->r_no0 / 2](trapwk); /* Line 378, Address: 0x1028ab4 */
  actionsub(trapwk); /* Line 379, Address: 0x1028af0 */
  frameout_s00(trapwk, ((short*)trapwk)[29]); /* Line 380, Address: 0x1028afc */
} /* Line 381, Address: 0x1028b10 */



static void dair8_init(sprite_status* trapwk) { /* Line 385, Address: 0x1028b20 */
  sprite_status* new_actwk;

  trapwk->actflg |= 4; /* Line 388, Address: 0x1028b2c */

  trapwk->sprpri = 3; /* Line 390, Address: 0x1028b3c */
  trapwk->patbase = togedair8pat; /* Line 391, Address: 0x1028b48 */
  ((short*)trapwk)[29] = trapwk->xposi.w.h; /* Line 392, Address: 0x1028b58 */
  ((short*)trapwk)[27] = trapwk->yposi.w.h; /* Line 393, Address: 0x1028b68 */
  trapwk->sprhsize = trapwk->sprvsize = 16; /* Line 394, Address: 0x1028b78 */
  if (actwkchk(&new_actwk) != 0) { dair8_move(trapwk); return; } /* Line 395, Address: 0x1028b90 */

  trapwk->r_no0 += 2; /* Line 397, Address: 0x1028bb8 */
  if (trapwk->userflag.b.h != 1) { /* Line 398, Address: 0x1028bc8 */
    new_actwk->actno = 10; /* Line 399, Address: 0x1028be4 */
    new_actwk->xposi.w.h = trapwk->xposi.w.h; /* Line 400, Address: 0x1028bf0 */
    new_actwk->yposi.w.h = trapwk->yposi.w.h; /* Line 401, Address: 0x1028c00 */
    new_actwk->actfree[15] = 232; /* Line 402, Address: 0x1028c10 */
    ((unsigned short*)new_actwk)[28] = trapwk - actwk; /* Line 403, Address: 0x1028c1c */
    new_actwk->userflag.b.h = trapwk->userflag.b.h; /* Line 404, Address: 0x1028c50 */
    dair8_move(trapwk); /* Line 405, Address: 0x1028c60 */
  } else { /* Line 406, Address: 0x1028c6c */
    new_actwk->actno = 54; /* Line 407, Address: 0x1028c74 */
    new_actwk->userflag.b.h = -1; /* Line 408, Address: 0x1028c80 */
    new_actwk->xposi.w.h = trapwk->xposi.w.h; /* Line 409, Address: 0x1028c8c */
    new_actwk->yposi.w.h = trapwk->yposi.w.h; /* Line 410, Address: 0x1028c9c */
    new_actwk->actfree[15] = 232; /* Line 411, Address: 0x1028cac */
    ((unsigned short*)new_actwk)[28] = trapwk - actwk; /* Line 412, Address: 0x1028cb8 */
    dair8_move(trapwk); /* Line 413, Address: 0x1028cec */
  }
} /* Line 415, Address: 0x1028cf8 */



static void dair8_move(sprite_status* trapwk) { /* Line 419, Address: 0x1028d10 */
  short cal_position;

  if (!(trapwk->actflg & 128)) return; /* Line 422, Address: 0x1028d20 */

  if ((cal_position = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) /* Line 424, Address: 0x1028d38 */
    cal_position = -cal_position; /* Line 425, Address: 0x1028d84 */
  if (cal_position >= 32) return; /* Line 426, Address: 0x1028da0 */


  hitchk(trapwk, &actwk[0]); /* Line 429, Address: 0x1028db4 */
} /* Line 430, Address: 0x1028dc8 */



static sprite_pattern har00 = { 1, { { -16, -16, 0, 292 } } };
static sprite_pattern har01 = { 1, { { -16, -16, 16, 292 } } };
sprite_pattern* harir8pat[2] = { &har00, &har01 };

void harir8(sprite_status* trapwk) { /* Line 438, Address: 0x1028de0 */
  unsigned short master;
  void(*tbl[2])(sprite_status*) = { &harir8_init, &harir8_move }; /* Line 440, Address: 0x1028df0 */

  tbl[trapwk->r_no0 / 2](trapwk); /* Line 442, Address: 0x1028e0c */
  actionsub(trapwk); /* Line 443, Address: 0x1028e48 */
  if ((master = ((unsigned short*)trapwk)[28]) != 0) { /* Line 444, Address: 0x1028e54 */

    if (actwk[master].actno == 0) { frameout(trapwk); return; } /* Line 446, Address: 0x1028e6c */
    trapwk->xposi.w.h = actwk[master].xposi.w.h + (short)(char)trapwk->actfree[14]; /* Line 447, Address: 0x1028eac */

    trapwk->yposi.w.h = actwk[master].yposi.w.h + (short)(char)trapwk->actfree[15]; /* Line 449, Address: 0x1028f08 */
  }


  frameout_s00(trapwk, ((short*)trapwk)[29]); /* Line 453, Address: 0x1028f64 */
} /* Line 454, Address: 0x1028f78 */



static void harir8_init(sprite_status* trapwk) { /* Line 458, Address: 0x1028f90 */
  trapwk->r_no0 += 2; /* Line 459, Address: 0x1028f9c */
  trapwk->actflg |= 4; /* Line 460, Address: 0x1028fac */

  trapwk->sprpri = 3; /* Line 462, Address: 0x1028fbc */
  trapwk->patbase = harir8pat; /* Line 463, Address: 0x1028fc8 */
  ((short*)trapwk)[29] = trapwk->xposi.w.h; /* Line 464, Address: 0x1028fd8 */
  ((short*)trapwk)[27] = trapwk->yposi.w.h; /* Line 465, Address: 0x1028fe8 */

  trapwk->sprhsize = 16; /* Line 467, Address: 0x1028ff8 */
  trapwk->sprvsize = 8; /* Line 468, Address: 0x1029004 */
  if (trapwk->userflag.b.h != -1) { /* Line 469, Address: 0x1029010 */
    trapwk->patno = 1; /* Line 470, Address: 0x102902c */
    trapwk->colino = 131; /* Line 471, Address: 0x1029038 */
    trapwk->sprhsize = 18; /* Line 472, Address: 0x1029044 */
  }
  harir8_move(trapwk); /* Line 474, Address: 0x1029050 */
} /* Line 475, Address: 0x102905c */



static void harir8_move(sprite_status* trapwk) { /* Line 479, Address: 0x1029070 */
  short cal_position;

  if (trapwk->patno == 0) /* Line 482, Address: 0x1029080 */
  {
    if ((cal_position = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) /* Line 484, Address: 0x1029094 */
      cal_position = -cal_position; /* Line 485, Address: 0x10290e0 */
    if (cal_position >= 32) return; /* Line 486, Address: 0x10290fc */

    if (hitchk(trapwk, &actwk[0]) == 0) return; /* Line 488, Address: 0x1029110 */
    if (!(trapwk->cddat & 8)) return; /* Line 489, Address: 0x1029134 */
    if (plpower_a || plpower_m) return; /* Line 490, Address: 0x102914c */

    if (actwk[0].r_no0 >= 4) return; /* Line 492, Address: 0x1029174 */
    if (((short*)&actwk[0])[26] != 0) return; /* Line 493, Address: 0x102918c */
    actwk[0].yposi.l -= actwk[0].yspeed.w << 8; /* Line 494, Address: 0x10291a4 */
    playdamageset(&actwk[0], trapwk); /* Line 495, Address: 0x10291cc */
    return; /* Line 496, Address: 0x10291e0 */
  }


  if (!(trapwk->actflg & 128)) return; /* Line 500, Address: 0x10291e8 */

  if ((cal_position = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) /* Line 502, Address: 0x1029200 */
    cal_position = -cal_position; /* Line 503, Address: 0x102924c */
  if (cal_position >= 32) return; /* Line 504, Address: 0x1029268 */


  hitchk(trapwk, &actwk[0]); /* Line 507, Address: 0x102927c */
} /* Line 508, Address: 0x1029290 */
