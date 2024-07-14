#include "..\EQU.H"
#include "TRAP_R82.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\RIDECHK.H"
#include "COLI8.H"

static void tr8_fout(sprite_status* trapwk);
static void togeita_ridechk(sprite_status* trapwk); static void togeita_init(sprite_status* trapwk); static void togeita_dataset(sprite_status* trapwk, sprite_status* new_actwk, unsigned char* togeita_data); static void setitano(sprite_status* trapwk); static void togeita_move1(sprite_status* trapwk); static unsigned char togeita_plchk_1(sprite_status* trapwk, short cal_x); static void togeita_move2(sprite_status* trapwk); static void itaset_chk(sprite_status* trapwk); static void togeita_move3(sprite_status* trapwk); static void togeitax(sprite_status* trapwk);
static void dair8_init(sprite_status* trapwk); static void dair8_move(sprite_status* trapwk);
static void harir8_init(sprite_status* trapwk); static void harir8_move(sprite_status* trapwk); static void harir8_ridechk(sprite_status* trapwk);
static void tokusyu_init(sprite_status* trapwk); static void tokusyu_move(sprite_status* trapwk);





static void tr8_fout(sprite_status* trapwk) { /* Line 19, Address: 0x1021910 */
  unsigned short status;

  if ((status = trapwk->cdsts) == 0) { frameout(trapwk); return; } /* Line 22, Address: 0x1021920 */
  status = (unsigned short)time_flag + status * 3; /* Line 23, Address: 0x1021954 */
  flagwork[status] &= 127; /* Line 24, Address: 0x102197c */
  frameout(trapwk); /* Line 25, Address: 0x1021998 */
} /* Line 26, Address: 0x10219a4 */



















void gater8(sprite_status* trapwk) { /* Line 46, Address: 0x10219c0 */
  frameout(trapwk); /* Line 47, Address: 0x10219cc */
} /* Line 48, Address: 0x10219d8 */





































static unsigned char togeita_data0[12] = { 1, 204, 28, 8, 4, 188, 12, 8, 5, 220, 44, 8 };
static unsigned char togeita_data1[12] = { 3, 0, 24, 8, 3, 224, 24, 8, 3, 32, 24, 8 };
static unsigned char togeita_data2[12] = { 2, 52, 28, 8, 5, 36, 44, 8, 4, 68, 12, 8 };
static sprite_pattern tog00 = {
  6,
  {
    { -80, -12, 0, 289 },
    { -56, -12, 0, 288 },
    { -24, -12, 0, 290 },
    { 0, -12, 0, 290 },
    { 24, -12, 0, 288 },
    { 56, -12, 0, 288 }
  }
};
static sprite_pattern tog01 = {
  2,
  {
    { -28, -8, 0, 289 },
    { -4, -8, 0, 288 }
  }
};
static sprite_pattern tog02 = {
  2,
  {
    { -28, -8, 0, 288 },
    { 4, -8, 0, 289 }
  }
};
static sprite_pattern tog03 = {
  2,
  {
    { -24, -8, 0, 290 },
    { 0, -8, 0, 290 }
  }
};
static sprite_pattern tog04 = { 1, { { -12, -8, 0, 289 } } };
static sprite_pattern tog05 = {
  3,
  {
    { -44, -8, 0, 288 },
    { -12, -8, 0, 288 },
    { 20, -8, 0, 289 }
  }
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

void togeita(sprite_status* trapwk) { /* Line 141, Address: 0x10219f0 */
  void(*tbl[4])(sprite_status*) = { &togeita_init, &togeita_move1, &togeita_move2, &togeita_move3 }; /* Line 142, Address: 0x10219fc */


  if (trapwk->userflag.b.h < 0) { togeitax(trapwk); return; } /* Line 145, Address: 0x1021a28 */
  tbl[trapwk->r_no0 / 2](trapwk); /* Line 146, Address: 0x1021a54 */
  togeita_ridechk(trapwk); /* Line 147, Address: 0x1021a90 */
  actionsub(trapwk); /* Line 148, Address: 0x1021a9c */
  frameout_s00(trapwk, ((short*)trapwk)[29]); /* Line 149, Address: 0x1021aa8 */
} /* Line 150, Address: 0x1021abc */


static void togeita_ridechk(sprite_status* trapwk) { /* Line 153, Address: 0x1021ad0 */
  short cal_position;

  if (trapwk->patno == 3) return; /* Line 156, Address: 0x1021ae0 */
  if (!(trapwk->actflg & 128)) return; /* Line 157, Address: 0x1021af8 */
  if ((cal_position = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) /* Line 158, Address: 0x1021b10 */
    cal_position = -cal_position; /* Line 159, Address: 0x1021b5c */
  if (cal_position < 32) /* Line 160, Address: 0x1021b78 */
    ride_on_chk(trapwk, &actwk[0]); /* Line 161, Address: 0x1021b8c */
} /* Line 162, Address: 0x1021ba0 */


static void togeita_init(sprite_status* trapwk) { /* Line 165, Address: 0x1021bc0 */
  unsigned char patchg_point;
  sprite_status* new_actwk;

  trapwk->r_no0 += 2; /* Line 169, Address: 0x1021bd0 */
  trapwk->actflg |= 4; /* Line 170, Address: 0x1021be0 */
  trapwk->sprpri = 3; /* Line 171, Address: 0x1021bf0 */

  trapwk->patbase = togeitapat; /* Line 173, Address: 0x1021bfc */

  setitano(trapwk); /* Line 175, Address: 0x1021c0c */

  if (trapwk->actfree[19] == 0) { /* Line 177, Address: 0x1021c18 */

    patchg_point = trapwk->actfree[18] * 4; /* Line 179, Address: 0x1021c2c */
    trapwk->patno = togeita_data0[patchg_point]; /* Line 180, Address: 0x1021c44 */
    trapwk->sprhsize = togeita_data0[patchg_point + 2]; /* Line 181, Address: 0x1021c60 */
    trapwk->sprvsize = togeita_data0[patchg_point + 3]; /* Line 182, Address: 0x1021c80 */
    ((short*)trapwk)[29] = trapwk->xposi.w.h; /* Line 183, Address: 0x1021ca0 */
    ((short*)trapwk)[27] = trapwk->yposi.w.h; /* Line 184, Address: 0x1021cb0 */
    trapwk->xposi.w.h += (char)togeita_data0[patchg_point + 1]; /* Line 185, Address: 0x1021cc0 */
    trapwk->actfree[17] = 1; /* Line 186, Address: 0x1021cf8 */

    if (actwkchk(&new_actwk) != 0) { tr8_fout(trapwk); return; } /* Line 188, Address: 0x1021d04 */
    new_actwk->actno = 51; /* Line 189, Address: 0x1021d2c */
    new_actwk->actfree[19] = 1; /* Line 190, Address: 0x1021d38 */
    togeita_dataset(trapwk, new_actwk, togeita_data1); /* Line 191, Address: 0x1021d44 */

    if (actwkchk(&new_actwk) != 0) { tr8_fout(trapwk); return; } /* Line 193, Address: 0x1021d5c */
    new_actwk->actno = 51; /* Line 194, Address: 0x1021d84 */
    new_actwk->actfree[19] = 2; /* Line 195, Address: 0x1021d90 */
    togeita_dataset(trapwk, new_actwk, togeita_data2); /* Line 196, Address: 0x1021d9c */
  }

  if (trapwk->patno == 3) return; /* Line 199, Address: 0x1021db4 */
  if (actwkchk(&new_actwk) != 0) return; /* Line 200, Address: 0x1021dcc */
  new_actwk->actno = 51; /* Line 201, Address: 0x1021de0 */
  new_actwk->userflag.b.h = -1; /* Line 202, Address: 0x1021dec */
  new_actwk->xposi.w.h = trapwk->xposi.w.h; /* Line 203, Address: 0x1021df8 */
  new_actwk->actfree[18] = trapwk->patno; /* Line 204, Address: 0x1021e08 */
  ((unsigned short*)new_actwk)[28] = trapwk - actwk; /* Line 205, Address: 0x1021e18 */
  ((unsigned short*)trapwk)[28] = new_actwk - actwk; /* Line 206, Address: 0x1021e4c */
} /* Line 207, Address: 0x1021e80 */


static void togeita_dataset(sprite_status* trapwk, sprite_status* new_actwk, unsigned char* togeita_data) { /* Line 210, Address: 0x1021ea0 */
  unsigned char patchg_point;

  patchg_point = trapwk->actfree[18] * 4; /* Line 213, Address: 0x1021eb4 */
  new_actwk->patno = togeita_data[patchg_point]; /* Line 214, Address: 0x1021ecc */
  new_actwk->sprhsize = togeita_data[patchg_point + 2]; /* Line 215, Address: 0x1021ee4 */
  new_actwk->sprvsize = togeita_data[patchg_point + 3]; /* Line 216, Address: 0x1021f00 */
  ((short*)new_actwk)[29] = ((short*)trapwk)[29]; /* Line 217, Address: 0x1021f1c */

  new_actwk->yposi.w.h = trapwk->yposi.w.h; /* Line 219, Address: 0x1021f2c */
  new_actwk->xposi.w.h = ((short*)trapwk)[29] + (short)(char)togeita_data[patchg_point + 1]; /* Line 220, Address: 0x1021f3c */

  new_actwk->userflag.b.h = trapwk->userflag.b.h; /* Line 222, Address: 0x1021f8c */
} /* Line 223, Address: 0x1021f9c */



static void setitano(sprite_status* trapwk) { /* Line 227, Address: 0x1021fb0 */
  unsigned char tbl[56] = { /* Line 228, Address: 0x1021fb8 */
    0, 1, 2, 1, 0, 2, 0, 0,
    1, 2, 1, 2, 1, 2, 1, 2,
    0, 2, 1, 2, 0, 1, 2, 1,
    1, 2, 1, 2, 2, 1, 2, 2,
    1, 2, 1, 1, 0, 1, 2, 0,
    1, 2, 2, 1, 0, 1, 2, 1,
    1, 0, 2, 1, 0, 1, 2, 2
  };

  trapwk->actfree[18] = tbl[trapwk->userflag.b.h]; /* Line 238, Address: 0x1021fec */
} /* Line 239, Address: 0x102200c */



static void togeita_move1(sprite_status* trapwk) { /* Line 243, Address: 0x1022020 */
  short position_check, cal_x;

  if ((position_check = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) return; /* Line 246, Address: 0x1022034 */
  if (position_check >= 256) return; /* Line 247, Address: 0x1022080 */

  if (trapwk->userflag.b.h == 0) cal_x = 48; /* Line 249, Address: 0x1022094 */
  else cal_x = 80; /* Line 250, Address: 0x10220c0 */
  if (togeita_plchk_1(trapwk, cal_x)) trapwk->r_no0 += 2; /* Line 251, Address: 0x10220cc */
} /* Line 252, Address: 0x10220f4 */



static unsigned char togeita_plchk_1(sprite_status* trapwk, short cal_x) { /* Line 256, Address: 0x1022110 */
  short position_check;

  if ((position_check = actwk[0].xposi.w.h - ((short*)trapwk)[29] + cal_x) < 0) /* Line 259, Address: 0x1022120 */
    return 0; /* Line 260, Address: 0x102217c */
  if (position_check >= cal_x * 2) return 0; /* Line 261, Address: 0x1022188 */
  return 1; /* Line 262, Address: 0x10221b8 */
} /* Line 263, Address: 0x10221bc */



static void togeita_move2(sprite_status* trapwk) { /* Line 267, Address: 0x10221d0 */
  short col_data;
  int stack_yposi;
  short tbl[6] = { 8, 32, 56, 80, 104, 128 }; /* Line 270, Address: 0x10221e4 */


  if (trapwk->userflag.b.h == 0 && trapwk->actfree[19] == 0) /* Line 273, Address: 0x1022218 */
    itaset_chk(trapwk); /* Line 274, Address: 0x1022244 */
  if (trapwk->actfree[21] != 0) return; /* Line 275, Address: 0x1022250 */
  stack_yposi = trapwk->yposi.l; /* Line 276, Address: 0x1022264 */
  trapwk->yposi.w.h += tbl[trapwk->userflag.b.h]; /* Line 277, Address: 0x102226c */
  col_data = emycol_d(trapwk); /* Line 278, Address: 0x1022298 */
  trapwk->yposi.l = stack_yposi; /* Line 279, Address: 0x10222ac */
  if (col_data >= 0) { /* Line 280, Address: 0x10222b4 */
    trapwk->yposi.l += 32768; /* Line 281, Address: 0x10222c4 */
    trapwk->yspeed.w = 128; /* Line 282, Address: 0x10222d8 */
  } else { /* Line 283, Address: 0x10222e4 */
    trapwk->yspeed.w = 0; /* Line 284, Address: 0x10222ec */
    ((short*)trapwk)[28] = 0; /* Line 285, Address: 0x10222f4 */
    trapwk->actfree[21] = 255; /* Line 286, Address: 0x10222fc */
  }
} /* Line 288, Address: 0x1022308 */



static void itaset_chk(sprite_status* trapwk) { /* Line 292, Address: 0x1022320 */
  short cal_position;
  sprite_status* new_actwk;

  if ((cal_position = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) { /* Line 296, Address: 0x1022330 */
    cal_position = -cal_position; /* Line 297, Address: 0x102237c */
    if (cal_position >= 128) return; /* Line 298, Address: 0x1022398 */
  }
  if (togeita_plchk_1(trapwk, 160) == 0) return; /* Line 300, Address: 0x10223ac */
  switch (++((short*)trapwk)[26]) { /* Line 301, Address: 0x10223c8 */

    case 300:

    case 600:

    case 840:

    case 1080:
     break;

    default:
      return; /* Line 313, Address: 0x1022418 */
  }

  if (trapwk->actfree[17] < 5) { /* Line 316, Address: 0x1022420 */
    if (actwkchk(&new_actwk) != 0) return; /* Line 317, Address: 0x1022438 */

    new_actwk->actno = 51; /* Line 319, Address: 0x102244c */
    new_actwk->xposi.w.h = ((short*)trapwk)[29]; /* Line 320, Address: 0x1022458 */
    new_actwk->yposi.w.h = ((short*)trapwk)[27] - (short)((char)trapwk->actfree[17] * 16); /* Line 321, Address: 0x1022468 */

    new_actwk->userflag.b.h = trapwk->actfree[17]; /* Line 323, Address: 0x10224b8 */
    ++trapwk->actfree[17]; /* Line 324, Address: 0x10224c8 */
  }
} /* Line 326, Address: 0x10224d8 */



static void togeita_move3(sprite_status* trapwk) { /* Line 330, Address: 0x10224f0 */
  trapwk->actno = trapwk->actno; /* Line 331, Address: 0x10224f8 */
} /* Line 332, Address: 0x1022508 */



static void togeitax(sprite_status* trapwk) { /* Line 336, Address: 0x1022520 */
  unsigned short ride_number;
  unsigned char colitbl[6] = { /* Line 338, Address: 0x1022530 */
    0,
    156,
    156,
    0,
    155,
    157
  };
  trapwk->actflg |= 4; /* Line 346, Address: 0x1022564 */
  trapwk->patbase = togeitapat; /* Line 347, Address: 0x1022574 */

  trapwk->patno = 6; /* Line 349, Address: 0x1022584 */


  ride_number = ((unsigned short*)trapwk)[28]; /* Line 352, Address: 0x1022590 */
  if (actwk[ride_number].actno != 51) /* Line 353, Address: 0x102259c */
  { frameout(trapwk); return; } /* Line 354, Address: 0x10225cc */
  if (actwk[ride_number].actno != 51) /* Line 355, Address: 0x10225e0 */
  { frameout(trapwk); return; } /* Line 356, Address: 0x1022610 */
  trapwk->yspeed.w = actwk[ride_number].yspeed.w; /* Line 357, Address: 0x1022624 */
  trapwk->yposi.w.h = actwk[ride_number].yposi.w.h + 12; /* Line 358, Address: 0x102264c */

  trapwk->colino = colitbl[trapwk->actfree[18]]; /* Line 360, Address: 0x1022688 */
  actionsub(trapwk); /* Line 361, Address: 0x10226a4 */
} /* Line 362, Address: 0x10226b0 */




































static sprite_pattern dai00 = { 1, { { -16, -16, 0, 291 } } };
sprite_pattern* togedair8pat[1] = { &dai00 };

void togedair8(sprite_status* trapwk) { /* Line 402, Address: 0x10226d0 */
  void(*tbl[2])(sprite_status*) = { &dair8_init, &dair8_move }; /* Line 403, Address: 0x10226dc */

  if (trapwk->userflag.b.h == -8) { tokusyu_block(trapwk); return; } /* Line 405, Address: 0x10226f8 */

  if (trapwk->userflag.b.h < 0) { harir8(trapwk); return; } /* Line 407, Address: 0x1022728 */

  tbl[trapwk->r_no0 / 2](trapwk); /* Line 409, Address: 0x1022754 */
  actionsub(trapwk); /* Line 410, Address: 0x1022790 */
  frameout_s00(trapwk, ((short*)trapwk)[29]); /* Line 411, Address: 0x102279c */
} /* Line 412, Address: 0x10227b0 */



static void dair8_init(sprite_status* trapwk) { /* Line 416, Address: 0x10227c0 */
  sprite_status* new_actwk;

  trapwk->actflg |= 4; /* Line 419, Address: 0x10227cc */

  trapwk->sprpri = 3; /* Line 421, Address: 0x10227dc */
  trapwk->patbase = togedair8pat; /* Line 422, Address: 0x10227e8 */
  ((short*)trapwk)[29] = trapwk->xposi.w.h; /* Line 423, Address: 0x10227f8 */
  ((short*)trapwk)[27] = trapwk->yposi.w.h; /* Line 424, Address: 0x1022808 */
  trapwk->sprhsize = trapwk->sprvsize = 16; /* Line 425, Address: 0x1022818 */
  if (actwkchk(&new_actwk) != 0) { dair8_move(trapwk); return; } /* Line 426, Address: 0x1022830 */

  trapwk->r_no0 += 2; /* Line 428, Address: 0x1022858 */
  if (trapwk->userflag.b.h != 1) { /* Line 429, Address: 0x1022868 */
    new_actwk->actno = 10; /* Line 430, Address: 0x1022884 */
    new_actwk->xposi.w.h = trapwk->xposi.w.h; /* Line 431, Address: 0x1022890 */
    new_actwk->yposi.w.h = trapwk->yposi.w.h; /* Line 432, Address: 0x10228a0 */
    new_actwk->actfree[15] = 232; /* Line 433, Address: 0x10228b0 */
    ((unsigned short*)new_actwk)[28] = trapwk - actwk; /* Line 434, Address: 0x10228bc */
    new_actwk->userflag.b.h = trapwk->userflag.b.h; /* Line 435, Address: 0x10228f0 */
    dair8_move(trapwk); /* Line 436, Address: 0x1022900 */
  } else { /* Line 437, Address: 0x102290c */
    new_actwk->actno = 54; /* Line 438, Address: 0x1022914 */
    new_actwk->userflag.b.h = -1; /* Line 439, Address: 0x1022920 */
    new_actwk->xposi.w.h = trapwk->xposi.w.h; /* Line 440, Address: 0x102292c */
    new_actwk->yposi.w.h = trapwk->yposi.w.h; /* Line 441, Address: 0x102293c */
    new_actwk->actfree[15] = 232; /* Line 442, Address: 0x102294c */
    ((unsigned short*)new_actwk)[28] = trapwk - actwk; /* Line 443, Address: 0x1022958 */
    dair8_move(trapwk); /* Line 444, Address: 0x102298c */
  }
} /* Line 446, Address: 0x1022998 */



static void dair8_move(sprite_status* trapwk) { /* Line 450, Address: 0x10229b0 */
  short cal_position;

  if (!(trapwk->actflg & 128)) return; /* Line 453, Address: 0x10229c0 */

  if ((cal_position = actwk[0].yposi.w.h - trapwk->yposi.w.h) < 0) /* Line 455, Address: 0x10229d8 */
    cal_position = -cal_position; /* Line 456, Address: 0x1022a24 */
  if (cal_position >= 32) return; /* Line 457, Address: 0x1022a40 */


  hitchk(trapwk, &actwk[0]); /* Line 460, Address: 0x1022a54 */
} /* Line 461, Address: 0x1022a68 */


static sprite_pattern har00 = { 1, { { -16, -16, 0, 292 } } };
static sprite_pattern har01 = { 1, { { -16, -16, 16, 292 } } };
sprite_pattern* harir8pat[2] = { &har00, &har01 };

void harir8(sprite_status* trapwk) { /* Line 468, Address: 0x1022a80 */
  unsigned short master;
  void(*tbl[2])(sprite_status*) = { &harir8_init, &harir8_move }; /* Line 470, Address: 0x1022a90 */

  tbl[trapwk->r_no0 / 2](trapwk); /* Line 472, Address: 0x1022aac */
  actionsub(trapwk); /* Line 473, Address: 0x1022ae8 */
  if ((master = ((unsigned short*)trapwk)[28]) != 0) { /* Line 474, Address: 0x1022af4 */

    if (actwk[master].actno == 0) { frameout(trapwk); return; } /* Line 476, Address: 0x1022b0c */
    trapwk->xposi.w.h = actwk[master].xposi.w.h + (short)(char)trapwk->actfree[14]; /* Line 477, Address: 0x1022b4c */

    trapwk->yposi.w.h = actwk[master].yposi.w.h + (short)(char)trapwk->actfree[15]; /* Line 479, Address: 0x1022ba8 */
  }


  frameout_s00(trapwk, ((short*)trapwk)[29]); /* Line 483, Address: 0x1022c04 */
} /* Line 484, Address: 0x1022c18 */



static void harir8_init(sprite_status* trapwk) { /* Line 488, Address: 0x1022c30 */
  trapwk->r_no0 += 2; /* Line 489, Address: 0x1022c3c */
  trapwk->actflg |= 4; /* Line 490, Address: 0x1022c4c */
  trapwk->sproffset = 0; /* Line 491, Address: 0x1022c5c */
  trapwk->sprpri = 1; /* Line 492, Address: 0x1022c64 */
  trapwk->patbase = harir8pat; /* Line 493, Address: 0x1022c70 */
  ((short*)trapwk)[29] = trapwk->xposi.w.h; /* Line 494, Address: 0x1022c80 */
  ((short*)trapwk)[27] = trapwk->yposi.w.h; /* Line 495, Address: 0x1022c90 */

  trapwk->sprhsize = 16; /* Line 497, Address: 0x1022ca0 */
  trapwk->sprvsize = 8; /* Line 498, Address: 0x1022cac */
  if (!(trapwk->userflag.b.h & 1)) { /* Line 499, Address: 0x1022cb8 */
    trapwk->patno = 1; /* Line 500, Address: 0x1022cd4 */
    trapwk->colino = 131; /* Line 501, Address: 0x1022ce0 */
    trapwk->sprhsize = 18; /* Line 502, Address: 0x1022cec */
  }
  harir8_move(trapwk); /* Line 504, Address: 0x1022cf8 */
} /* Line 505, Address: 0x1022d04 */



static void harir8_move(sprite_status* trapwk) { /* Line 509, Address: 0x1022d20 */
  char needle_type;

  if ((needle_type = -trapwk->userflag.b.h) < 3) { /* Line 512, Address: 0x1022d30 */

    harir8_ridechk(trapwk); /* Line 514, Address: 0x1022d70 */
  } else if (needle_type < 5) { /* Line 515, Address: 0x1022d7c */

    trapwk->sproffset = 32768; /* Line 517, Address: 0x1022d98 */

    trapwk->colino = 131; /* Line 519, Address: 0x1022da4 */
    if (prio_flag == 0) { harir8_ridechk(trapwk); return; } /* Line 520, Address: 0x1022db0 */
    trapwk->colino = 0; /* Line 521, Address: 0x1022dd8 */
    ride_on_clr(trapwk, &actwk[0]); /* Line 522, Address: 0x1022de0 */
  } else { /* Line 523, Address: 0x1022df4 */

    trapwk->sprpri = 3; /* Line 525, Address: 0x1022dfc */

    trapwk->colino = 131; /* Line 527, Address: 0x1022e08 */
    if (prio_flag != 0) { harir8_ridechk(trapwk); return; } /* Line 528, Address: 0x1022e14 */
    trapwk->colino = 0; /* Line 529, Address: 0x1022e3c */
    ride_on_clr(trapwk, &actwk[0]); /* Line 530, Address: 0x1022e44 */
  }
} /* Line 532, Address: 0x1022e58 */


static void harir8_ridechk(sprite_status* trapwk) { /* Line 535, Address: 0x1022e70 */
  if (trapwk->patno == 0) { /* Line 536, Address: 0x1022e7c */

    trapwk->colino = 0; /* Line 538, Address: 0x1022e90 */
    if (hitchk(trapwk, &actwk[0]) == 0) return; /* Line 539, Address: 0x1022e98 */
    if (!(trapwk->cddat & 8)) return; /* Line 540, Address: 0x1022ebc */

    if (plpower_a || plpower_m) return; /* Line 542, Address: 0x1022ed4 */

    if (actwk[0].r_no0 >= 4) return; /* Line 544, Address: 0x1022efc */
    if (((short*)&actwk[0])[26] != 0) return; /* Line 545, Address: 0x1022f14 */
    actwk[0].yposi.l -= actwk[0].yspeed.w << 8; /* Line 546, Address: 0x1022f2c */
    playdamageset(&actwk[0], trapwk); /* Line 547, Address: 0x1022f54 */
    return; /* Line 548, Address: 0x1022f68 */
  }


  if (trapwk->actflg & 128) /* Line 552, Address: 0x1022f70 */
    hitchk(trapwk, &actwk[0]); /* Line 553, Address: 0x1022f88 */
} /* Line 554, Address: 0x1022f9c */




static sprite_pattern tok00 = {
  1,
  { { -24, -16, 0, 293 } }
};
sprite_pattern* tokusyupat[1] = { &tok00 };

void tokusyu_block(sprite_status* trapwk) { /* Line 565, Address: 0x1022fb0 */
  void(*tbl[2])(sprite_status*) = { &tokusyu_init, &tokusyu_move }; /* Line 566, Address: 0x1022fbc */

  tbl[trapwk->r_no0 / 2](trapwk); /* Line 568, Address: 0x1022fd8 */
  actionsub(trapwk); /* Line 569, Address: 0x1023014 */
  frameout_s(trapwk); /* Line 570, Address: 0x1023020 */
} /* Line 571, Address: 0x102302c */


static void tokusyu_init(sprite_status* trapwk) { /* Line 574, Address: 0x1023040 */
  trapwk->actflg |= 4; /* Line 575, Address: 0x102304c */

  trapwk->sprpri = 3; /* Line 577, Address: 0x102305c */
  trapwk->patbase = tokusyupat; /* Line 578, Address: 0x1023068 */
  trapwk->sprhsize = 24; /* Line 579, Address: 0x1023078 */
  trapwk->sprvsize = 16; /* Line 580, Address: 0x1023084 */
  tokusyu_move(trapwk); /* Line 581, Address: 0x1023090 */
} /* Line 582, Address: 0x102309c */


static void tokusyu_move(sprite_status* trapwk) { /* Line 585, Address: 0x10230b0 */
  if (prio_flag == 0) ride_on_clr(trapwk, &actwk[0]); /* Line 586, Address: 0x10230bc */
  else ride_on_chk(trapwk, &actwk[0]); /* Line 587, Address: 0x10230ec */
} /* Line 588, Address: 0x1023100 */
