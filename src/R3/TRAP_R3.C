#include "..\EQU.H"
#include "TRAP_R3.H"

static sprite_pattern har00 = { 1, { { -16, -16, 0, 288 } } };
static sprite_pattern har01 = { 1, { { -16, -16, 0, 289 } } };
static sprite_pattern har02 = { 1, { { -16, -16, 0, 290 } } };
static sprite_pattern har03 = { 1, { { -16, -16, 0, 291 } } };
sprite_pattern* harir3pat[4] = { &har00, &har01, &har02, &har03 };
static sprite_pattern frd00 = { 1, { { -16, -16, 0, 292 } } };
sprite_pattern* frdr3pat[1] = { &frd00 };
static sprite_pattern trd00 = { 1, { { -16, -16, 0, 293 } } };
static sprite_pattern trd01 = { 1, { { -16, -16, 0, 294 } } };
sprite_pattern* trapdr3pat[2] = { &trd00, &trd01 };
static sprite_pattern fo00 = { 1, { { -32, -16, 0, 295 } } };
sprite_pattern* for3pat[1] = { &fo00 };
static sprite_pattern gtd00 = { 1, { { -32, -8, 0, 296 } } };
sprite_pattern* getdair3pat[1] = { &gtd00 };
static unsigned char pchg1[4] = { 2, 1, 2, 255 };
static unsigned char pchg2[4] = { 2, 3, 5, 255 };
static unsigned char pchg3[4] = { 2, 4, 5, 255 };
static unsigned char pchg4[6] = { 0, 3, 6, 5, 6, 255 };
static unsigned char pchg5[6] = { 0, 4, 6, 5, 6, 255 };
unsigned char* gandair3_pchg[5] = { pchg1, pchg2, pchg3, pchg4, pchg5 };
static sprite_pattern gnd00 = { 1, { { -16, -4, 0, 297 } } };
static sprite_pattern gnd01 = { 1, { { -16, -20, 0, 298 } } };
static sprite_pattern gnd02 = { 1, { { -16, -20, 0, 299 } } };
static sprite_pattern gnd03 = { 1, { { -8, -8, 0, 300 } } };
static sprite_pattern gnd04 = { 1, { { -8, -8, 0, 301 } } };
static sprite_pattern gnd05 = { 1, { { -16, -20, 0, 0 } } };
sprite_pattern* gandair3pat[7] = { &gnd00, &gnd01, &gnd02, &gnd03, &gnd04, &gnd05, &gnd05 };
static sprite_pattern drm00 = { 1, { { -24, -16, 0, 302 } } };
static sprite_pattern drm01 = { 1, { { -24, -12, 0, 303 } } };
static sprite_pattern drm02 = { 1, { { -24, -8, 0, 304 } } };
static sprite_pattern drm03 = { 1, { { -24, -4, 0, 305 } } };
static sprite_pattern drm04 = { 1, { { -24, -4, 0, 306 } } };
static sprite_pattern drm05 = { 1, { { -24, -4, 0, 307 } } };
static sprite_pattern drm06 = { 1, { { -24, -4, 0, 308 } } };
static sprite_pattern drm07 = { 1, { { -24, -4, 0, 309 } } };
static sprite_pattern drm08 = { 1, { { -24, 0, 0, 310 } } };
static sprite_pattern drm09 = { 1, { { -24, 0, 0, 311 } } };
static sprite_pattern drm0a = { 1, { { -16, -20, 0, 0 } } };
static sprite_pattern drm0b = { 1, { { -24, -8, 0, 312 } } };
sprite_pattern* drumr3pat[12] = {
  &drm00, &drm01, &drm02, &drm03, &drm04, &drm05,
  &drm06, &drm07, &drm08, &drm09, &drm0a, &drm0b
};


















void harir3(sprite_status* hariwk) { /* Line 65, Address: 0x1020060 */
  void(*harir3_acttbl[2])(sprite_status*) = { /* Line 66, Address: 0x1020074 */
    &harir3_init,
    &harir3_move
  };
  unsigned short ride_no, cal_x;

  harir3_acttbl[hariwk->r_no0 / 2](hariwk); /* Line 72, Address: 0x1020090 */
  actionsub(hariwk); /* Line 73, Address: 0x10200cc */

  if ((ride_no = ((unsigned short*)hariwk)[28]) != 0) { /* Line 75, Address: 0x10200d8 */
    hariwk->xposi.w.h = hariwk->actfree[14] + actwk[ride_no].xposi.w.h; /* Line 76, Address: 0x10200f0 */

    hariwk->yposi.w.h = hariwk->actfree[15] + actwk[ride_no].yposi.w.h; /* Line 78, Address: 0x1020140 */
  }

  cal_x = (((unsigned short*)hariwk)[29] & 65408) - ((unsigned short)(scra_h_posit.w.h - 128) & 65408); /* Line 81, Address: 0x1020190 */

  if (cal_x >= 641) tr3_fout(hariwk); /* Line 83, Address: 0x10201cc */
} /* Line 84, Address: 0x10201e8 */



void harir3_init(sprite_status* hariwk) { /* Line 88, Address: 0x1020200 */
  unsigned char harir3sztbl[12] = { /* Line 89, Address: 0x1020210 */
     16,   8,   0,
     18,  12, 131,
     12,  16, 130,
     12,  16, 130
  };
  unsigned char cal_index;

  hariwk->r_no0 += 2; /* Line 97, Address: 0x1020244 */
  hariwk->actflg |= 4; /* Line 98, Address: 0x1020254 */



  hariwk->sprpri = 3; /* Line 102, Address: 0x1020264 */
  hariwk->patbase = harir3pat; /* Line 103, Address: 0x1020270 */

  ((short*)hariwk)[29] = hariwk->xposi.w.h; /* Line 105, Address: 0x1020280 */
  ((short*)hariwk)[27] = hariwk->yposi.w.h; /* Line 106, Address: 0x1020290 */


  cal_index = hariwk->patno = (unsigned char)hariwk->userflag.b.h & 3; /* Line 109, Address: 0x10202a0 */
  cal_index *= 3; /* Line 110, Address: 0x10202c8 */
  hariwk->sprhsize = harir3sztbl[cal_index]; /* Line 111, Address: 0x10202dc */
  hariwk->sprvsize = harir3sztbl[cal_index + 1]; /* Line 112, Address: 0x10202f0 */
  hariwk->colino = harir3sztbl[cal_index + 2]; /* Line 113, Address: 0x1020308 */
  harir3_move(hariwk); /* Line 114, Address: 0x1020320 */
} /* Line 115, Address: 0x102032c */


void harir3_move(sprite_status* hariwk) { /* Line 118, Address: 0x1020340 */
  harir3_kind(hariwk); /* Line 119, Address: 0x102034c */

  if (hariwk->patno != 0) { hitchk(hariwk, &actwk[0]); return; } /* Line 121, Address: 0x1020358 */

  if (hitchk(hariwk, &actwk[0]) == 0) return; /* Line 123, Address: 0x1020388 */
  if (!(hariwk->cddat & 8)) return; /* Line 124, Address: 0x10203ac */

  if (plpower_a != 0) return; /* Line 126, Address: 0x10203c4 */
  if (plpower_m != 0) return; /* Line 127, Address: 0x10203d8 */


  if (actwk[0].r_no0 >= 4) return; /* Line 130, Address: 0x10203ec */

  if (((short*)&actwk[0])[26] != 0) return; /* Line 132, Address: 0x1020404 */

  actwk[0].yposi.l -= actwk[0].yspeed.w << 8; /* Line 134, Address: 0x1020418 */
  playdamageset(&actwk[0], hariwk); /* Line 135, Address: 0x1020440 */
} /* Line 136, Address: 0x1020454 */



void harir3_kind(sprite_status* hariwk) { /* Line 140, Address: 0x1020470 */
  void(*harir3_kndtbl[4])(sprite_status*) = { /* Line 141, Address: 0x102047c */
    &harir3_ymv1,
    &harir3_ymv2,
    &harir3_xmv1,
    &harir3_xmv2
  };
  if (!(hariwk->userflag.b.h & 4)) return; /* Line 147, Address: 0x10204a8 */
  harir3_kndtbl[hariwk->userflag.b.h & 3](hariwk); /* Line 148, Address: 0x10204c4 */
} /* Line 149, Address: 0x10204f0 */



void harir3_ymv1(sprite_status* hariwk) { /* Line 153, Address: 0x1020500 */
  harir3_sub(hariwk); /* Line 154, Address: 0x102050c */
  hariwk->yposi.w.h = ((short*)hariwk)[27] + hariwk->actfree[17]; /* Line 155, Address: 0x1020518 */

} /* Line 157, Address: 0x1020550 */



void harir3_ymv2(sprite_status* hariwk) { /* Line 161, Address: 0x1020560 */
  harir3_sub(hariwk); /* Line 162, Address: 0x102056c */
  hariwk->yposi.w.h = ((short*)hariwk)[27] - hariwk->actfree[17]; /* Line 163, Address: 0x1020578 */

} /* Line 165, Address: 0x10205b0 */



void harir3_xmv1(sprite_status* hariwk) { /* Line 169, Address: 0x10205c0 */
  harir3_sub(hariwk); /* Line 170, Address: 0x10205cc */
  hariwk->xposi.w.h = ((short*)hariwk)[29] - hariwk->actfree[17]; /* Line 171, Address: 0x10205d8 */

} /* Line 173, Address: 0x1020610 */



void harir3_xmv2(sprite_status* hariwk) { /* Line 177, Address: 0x1020620 */
  harir3_sub(hariwk); /* Line 178, Address: 0x102062c */
  hariwk->xposi.w.h = ((short*)hariwk)[29] + hariwk->actfree[17]; /* Line 179, Address: 0x1020638 */

} /* Line 181, Address: 0x1020670 */



void harir3_sub(sprite_status* hariwk) { /* Line 185, Address: 0x1020680 */
  if (hariwk->actfree[16] != 0) { /* Line 186, Address: 0x102068c */
    if (--hariwk->actfree[16] != 0) return; /* Line 187, Address: 0x10206a0 */
    if (hariwk->actflg & 128) soundset(183); /* Line 188, Address: 0x10206c0 */
  }

  if (hariwk->actfree[18] != 0) { /* Line 191, Address: 0x10206e4 */
    if ((char)(hariwk->actfree[17] -= 8) >= 0) return; /* Line 192, Address: 0x10206f8 */

    hariwk->actfree[17] = hariwk->actfree[18] = 0; /* Line 194, Address: 0x1020724 */
    hariwk->actfree[16] = 60; /* Line 195, Address: 0x1020738 */
    return; /* Line 196, Address: 0x1020744 */
  }

  if ((hariwk->actfree[17] += 8) < 32) return; /* Line 199, Address: 0x102074c */
  hariwk->actfree[17] = 32; /* Line 200, Address: 0x1020770 */
  hariwk->actfree[18] = 1; /* Line 201, Address: 0x102077c */
  hariwk->actfree[16] = 60; /* Line 202, Address: 0x1020788 */
} /* Line 203, Address: 0x1020794 */












































void frdr3(sprite_status* floorwk) { /* Line 248, Address: 0x10207b0 */
  void(*frdr3_acttbl[2])(sprite_status*) = { /* Line 249, Address: 0x10207c0 */
    &frdr3_init,
    &frdr3_move
  };
  unsigned short cal_x;
  frdr3_acttbl[floorwk->r_no0 / 2](floorwk); /* Line 254, Address: 0x10207dc */
  actionsub(floorwk); /* Line 255, Address: 0x1020818 */
  cal_x = (((unsigned short*)floorwk)[27] & 65408) - ((unsigned short)(scra_h_posit.w.h - 128) & 65408); /* Line 256, Address: 0x1020824 */

  if (cal_x >= 641) tr3_fout(floorwk); /* Line 258, Address: 0x1020860 */
} /* Line 259, Address: 0x102087c */



void frdr3_init(sprite_status* floorwk) { /* Line 263, Address: 0x1020890 */
  sprite_status* new_actwk;

  floorwk->r_no0 += 2; /* Line 266, Address: 0x102089c */
  floorwk->actflg |= 4; /* Line 267, Address: 0x10208ac */

  floorwk->sprpri = 3; /* Line 269, Address: 0x10208bc */
  floorwk->patbase = frdr3pat; /* Line 270, Address: 0x10208c8 */
  floorwk->sprhsize = floorwk->sprvsize = 16; /* Line 271, Address: 0x10208d8 */
  ((short*)floorwk)[27] = floorwk->xposi.w.h; /* Line 272, Address: 0x10208f0 */
  ((short*)floorwk)[26] = floorwk->yposi.w.h; /* Line 273, Address: 0x1020900 */

  if (floorwk->userflag.b.h < 2) { frdr3_move(floorwk); return; } /* Line 275, Address: 0x1020910 */
  if (actwkchk2(floorwk, &new_actwk) != 0) /* Line 276, Address: 0x1020940 */
  { frameout(floorwk); return; } /* Line 277, Address: 0x1020958 */
  new_actwk->actno = 10; /* Line 278, Address: 0x102096c */
  new_actwk->xposi.w.h = floorwk->xposi.w.h; /* Line 279, Address: 0x1020978 */
  new_actwk->yposi.w.h = floorwk->yposi.w.h; /* Line 280, Address: 0x1020988 */
  new_actwk->actfree[15] = 234; /* Line 281, Address: 0x1020998 */
  ((unsigned short*)new_actwk)[28] = floorwk - actwk; /* Line 282, Address: 0x10209a4 */
  new_actwk->userflag.b.h = (floorwk->userflag.b.h & 1) << 1; /* Line 283, Address: 0x10209d8 */
  frdr3_move(floorwk); /* Line 284, Address: 0x1020a00 */
} /* Line 285, Address: 0x1020a0c */



void frdr3_move(sprite_status* floorwk) { /* Line 289, Address: 0x1020a20 */

  char frdr3_mvtbl0[8] = { /* Line 291, Address: 0x1020a2c */
    64, -8, 64, -8,
    64,  8, 64,  8
  };

  short frdr3_mvtbl1[4] = { 512, 0, -512, 0 }; /* Line 296, Address: 0x1020a60 */

  ride_on_chk(floorwk, &actwk[0]); /* Line 298, Address: 0x1020a8c */
  if (time_flag == 0) return; /* Line 299, Address: 0x1020aa0 */

  do {
    if (floorwk->userflag.b.h == 1) return; /* Line 302, Address: 0x1020ab4 */
    if (floorwk->actfree[16] == 0) { /* Line 303, Address: 0x1020ad0 */
      floorwk->actfree[16] = frdr3_mvtbl0[floorwk->actfree[17] * 2]; /* Line 304, Address: 0x1020ae4 */
      ((short*)floorwk)[30] = frdr3_mvtbl0[floorwk->actfree[17] * 2 + 1]; /* Line 305, Address: 0x1020b04 */

      ((short*)floorwk)[29] = frdr3_mvtbl1[floorwk->actfree[17]]; /* Line 307, Address: 0x1020b30 */
      return; /* Line 308, Address: 0x1020b50 */
    }

    ((short*)floorwk)[29] += ((short*)floorwk)[30]; /* Line 311, Address: 0x1020b58 */
    floorwk->xspeed.w = ((short*)floorwk)[29]; /* Line 312, Address: 0x1020b70 */
    floorwk->xposi.l += floorwk->xspeed.w << 8; /* Line 313, Address: 0x1020b80 */





    if (--floorwk->actfree[16] != 0) return; /* Line 319, Address: 0x1020ba4 */
    floorwk->actfree[17] = floorwk->actfree[17] + 1 & 3; /* Line 320, Address: 0x1020bc4 */
  } while (1); /* Line 321, Address: 0x1020be4 */
} /* Line 322, Address: 0x1020bec */















































void trapdr3(sprite_status* floorwk) { /* Line 370, Address: 0x1020c00 */
  void(*trapdr3_acttbl[2])(sprite_status*) = { &trapdr3_init, &trapdr3_move }; /* Line 371, Address: 0x1020c10 */
  unsigned short cal_x;

  trapdr3_acttbl[floorwk->r_no0 / 2](floorwk); /* Line 374, Address: 0x1020c2c */
  actionsub(floorwk); /* Line 375, Address: 0x1020c68 */
  cal_x = (((unsigned short*)floorwk)[29] & 65408) - ((unsigned short)(scra_h_posit.w.h - 128) & 65408); /* Line 376, Address: 0x1020c74 */

  if (cal_x >= 641) tr3_fout(floorwk); /* Line 378, Address: 0x1020cb0 */
} /* Line 379, Address: 0x1020ccc */


void trapdr3_init(sprite_status* floorwk) { /* Line 382, Address: 0x1020ce0 */
  sprite_status* new_actwk;

  floorwk->actflg |= 4; /* Line 385, Address: 0x1020cec */

  floorwk->sprpri = 3; /* Line 387, Address: 0x1020cfc */
  floorwk->patbase = trapdr3pat; /* Line 388, Address: 0x1020d08 */
  floorwk->patno = floorwk->userflag.b.h >> 2; /* Line 389, Address: 0x1020d18 */

  floorwk->sprhsize = 16; /* Line 391, Address: 0x1020d38 */
  floorwk->sprvsize = 14; /* Line 392, Address: 0x1020d44 */
  ((short*)floorwk)[29] = floorwk->xposi.w.h; /* Line 393, Address: 0x1020d50 */
  ((short*)floorwk)[27] = floorwk->yposi.w.h; /* Line 394, Address: 0x1020d60 */
  floorwk->r_no0 += 2; /* Line 395, Address: 0x1020d70 */

  if ((floorwk->userflag.b.h & 3) == 0) { trapdr3_move(floorwk); return; } /* Line 397, Address: 0x1020d80 */

  if (actwkchk2(floorwk, &new_actwk) != 0) /* Line 399, Address: 0x1020db0 */
  { trapdr3_move(floorwk); return; } /* Line 400, Address: 0x1020dc8 */

  if ((floorwk->userflag.b.h & 3) == 1) new_actwk->actno = 32; /* Line 402, Address: 0x1020ddc */
  else new_actwk->actno = 10; /* Line 403, Address: 0x1020e10 */
  new_actwk->xposi.w.h = floorwk->xposi.w.h; /* Line 404, Address: 0x1020e1c */
  new_actwk->yposi.w.h = floorwk->yposi.w.h; /* Line 405, Address: 0x1020e2c */
  ((unsigned short*)new_actwk)[28] = floorwk - actwk; /* Line 406, Address: 0x1020e3c */
  if (new_actwk->actno == 32) { /* Line 407, Address: 0x1020e70 */
    new_actwk->actfree[14] = 32; /* Line 408, Address: 0x1020e88 */
    new_actwk->userflag.b.h = 2; /* Line 409, Address: 0x1020e94 */
  } else { /* Line 410, Address: 0x1020ea0 */
    new_actwk->actfree[14] = 24; /* Line 411, Address: 0x1020ea8 */
    new_actwk->userflag.b.h = (floorwk->userflag.b.h & 1) << 1 | 4; /* Line 412, Address: 0x1020eb4 */
  }
  trapdr3_move(floorwk); /* Line 414, Address: 0x1020ee0 */
} /* Line 415, Address: 0x1020eec */


void trapdr3_move(sprite_status* floorwk) { /* Line 418, Address: 0x1020f00 */
  trapdr3_kind(floorwk); /* Line 419, Address: 0x1020f0c */
  hitchk(floorwk, &actwk[0]); /* Line 420, Address: 0x1020f18 */
} /* Line 421, Address: 0x1020f2c */


void trapdr3_kind(sprite_status* floorwk) { /* Line 424, Address: 0x1020f40 */
  if (!(floorwk->userflag.b.h & 4)) { /* Line 425, Address: 0x1020f4c */

    trapdr3_updown(floorwk); /* Line 427, Address: 0x1020f68 */
    floorwk->yposi.w.h = ((short*)floorwk)[27] + floorwk->actfree[17]; /* Line 428, Address: 0x1020f74 */

  } /* Line 430, Address: 0x1020fac */
  else {
    trapdr3_updown(floorwk); /* Line 432, Address: 0x1020fb4 */
    floorwk->yposi.w.h = ((short*)floorwk)[27] - floorwk->actfree[17]; /* Line 433, Address: 0x1020fc0 */
  }

} /* Line 436, Address: 0x1020ff8 */



void trapdr3_updown(sprite_status* floorwk) { /* Line 440, Address: 0x1021010 */
  short cal_x;

  cal_x = actwk[0].xposi.w.h - (floorwk->xposi.w.h - floorwk->sprhsize); /* Line 443, Address: 0x102101c */
  if (cal_x >= 0) { /* Line 444, Address: 0x1021068 */
    if (cal_x < 80) return; /* Line 445, Address: 0x1021078 */



    if ((char)(floorwk->actfree[17] -= 8) < 0) floorwk->actfree[17] = 0; /* Line 449, Address: 0x102108c */
    return; /* Line 450, Address: 0x10210c0 */
  }

  if ((floorwk->actfree[17] += 8) >= 32) floorwk->actfree[17] = 32; /* Line 453, Address: 0x10210c8 */

} /* Line 455, Address: 0x10210f8 */










































void for3(sprite_status* floorwk) { /* Line 498, Address: 0x1021110 */
  void(*tbl[2])(sprite_status*) = { &for3_init, &for3_move }; /* Line 499, Address: 0x102111c */

  tbl[floorwk->r_no0 / 2](floorwk); /* Line 501, Address: 0x1021138 */
  actionsub(floorwk); /* Line 502, Address: 0x1021174 */
} /* Line 503, Address: 0x1021180 */


void for3_init(sprite_status* floorwk) { /* Line 506, Address: 0x1021190 */
  floorwk->actflg |= 4; /* Line 507, Address: 0x102119c */

  floorwk->sprpri = 3; /* Line 509, Address: 0x10211ac */
  floorwk->patbase = for3pat; /* Line 510, Address: 0x10211b8 */
  floorwk->sprhsize = 32; /* Line 511, Address: 0x10211c8 */
  floorwk->sprvsize = 16; /* Line 512, Address: 0x10211d4 */

  ((short*)floorwk)[27] = floorwk->xposi.w.h; /* Line 514, Address: 0x10211e0 */
  ((short*)floorwk)[26] = floorwk->yposi.w.h; /* Line 515, Address: 0x10211f0 */
  floorwk->r_no0 += 2; /* Line 516, Address: 0x1021200 */
  for3_move(floorwk); /* Line 517, Address: 0x1021210 */
} /* Line 518, Address: 0x102121c */


void for3_move(sprite_status* floorwk) { /* Line 521, Address: 0x1021230 */
  void(*for3_kndtbl[8])(sprite_status*) = { /* Line 522, Address: 0x1021240 */
    &for3_fix,
    &for3_rmv,
    &for3_lmv,
    &for3_umv,
    &for3_dmv,
    &for3_rup,
    &for3_rup,
    &for3_rup
  };
  unsigned short cal_x;
  for3_kndtbl[floorwk->userflag.b.h](floorwk); /* Line 533, Address: 0x1021274 */
  dai3sub(floorwk); /* Line 534, Address: 0x102129c */
  cal_x = (((unsigned short*)floorwk)[27] & 65408) - ((unsigned short)(scra_h_posit.w.h - 128) & 65408); /* Line 535, Address: 0x10212a8 */

  if (cal_x >= 641) tr3_fout(floorwk); /* Line 537, Address: 0x10212e4 */
} /* Line 538, Address: 0x1021300 */


void for3_ridechk(sprite_status* thingwk) { /* Line 541, Address: 0x1021320 */
  ridechk(thingwk, &actwk[0]); /* Line 542, Address: 0x102132c */
} /* Line 543, Address: 0x1021340 */



void dai3sub(sprite_status* floorwk) { /* Line 547, Address: 0x1021350 */
  short tmp_sin, tmp_cos;
  int_union cal_sin;

  if (floorwk->actfree[21] == 0) return; /* Line 551, Address: 0x102135c */

  if (!(floorwk->cddat & 8)) { /* Line 553, Address: 0x1021370 */
    if (floorwk->actfree[20] == 0) return; /* Line 554, Address: 0x1021388 */
    floorwk->actfree[20] -= 8; /* Line 555, Address: 0x102139c */
  } /* Line 556, Address: 0x10213ac */
  else {
    if (floorwk->actfree[20] == 64) return; /* Line 558, Address: 0x10213b4 */
    floorwk->actfree[20] += 8; /* Line 559, Address: 0x10213cc */
  }
  sinset(floorwk->actfree[20], &tmp_sin, &tmp_cos); /* Line 561, Address: 0x10213dc */
  cal_sin.l = tmp_sin << 10; /* Line 562, Address: 0x10213f4 */
  floorwk->yposi.w.h = ((short*)floorwk)[26] + cal_sin.w.h; /* Line 563, Address: 0x1021408 */
} /* Line 564, Address: 0x1021438 */



void for3_fix(sprite_status* floorwk) { /* Line 568, Address: 0x1021450 */
  floorwk->actfree[21] = 1; /* Line 569, Address: 0x102145c */
  for3_ridechk(floorwk); /* Line 570, Address: 0x1021468 */
} /* Line 571, Address: 0x1021474 */



void for3_lmv(sprite_status* floorwk) { /* Line 575, Address: 0x1021490 */
  for3_rmv(floorwk); /* Line 576, Address: 0x102149c */
} /* Line 577, Address: 0x10214a8 */


void for3_rmv(sprite_status* floorwk) { /* Line 580, Address: 0x10214c0 */

  char for3_rmvtbl0[16] = { /* Line 582, Address: 0x10214cc */
     28,   0,
      8, -48,
      8, -48,
     56,   0,
      8,  48,
      8,  48,
     56,   0,
      8, -48
  };
  short for3_rmvtbl1[8] = { 768, 768, 0, -768, -768, 0, 768, 768 }; /* Line 592, Address: 0x1021500 */

  char for3_lmvtbl0[16] = { /* Line 594, Address: 0x1021534 */
     28,   0,
      8,  48,
      8,  48,
     56,   0,
      8, -48,
      8, -48,
     56,   0,
      8,  48
  };
  short for3_lmvtbl1[8] = { -768, -768, 0, 768, 768, 0, -768, -768 }; /* Line 604, Address: 0x1021568 */

  do {
    if (floorwk->actfree[14] == 0) { /* Line 607, Address: 0x102159c */

      floorwk->actfree[21] = 1; /* Line 609, Address: 0x10215b0 */
      if (floorwk->userflag.b.h == 1) { /* Line 610, Address: 0x10215bc */
        floorwk->actfree[14] = for3_rmvtbl0[floorwk->actfree[15] * 2]; /* Line 611, Address: 0x10215d8 */
        ((short*)floorwk)[29] = for3_rmvtbl0[floorwk->actfree[15] * 2 + 1]; /* Line 612, Address: 0x10215f8 */

        ((short*)floorwk)[28] = for3_rmvtbl1[floorwk->actfree[15]]; /* Line 614, Address: 0x1021624 */

        for3_ridechk(floorwk); /* Line 616, Address: 0x1021644 */
      } else { /* Line 617, Address: 0x1021650 */
        floorwk->actfree[14] = for3_lmvtbl0[floorwk->actfree[15] * 2]; /* Line 618, Address: 0x1021658 */
        ((short*)floorwk)[29] = for3_lmvtbl0[floorwk->actfree[15] * 2 + 1]; /* Line 619, Address: 0x1021678 */

        ((short*)floorwk)[28] = for3_lmvtbl1[floorwk->actfree[15]]; /* Line 621, Address: 0x10216a4 */

        for3_ridechk(floorwk); /* Line 623, Address: 0x10216c4 */
      }
      return; /* Line 625, Address: 0x10216d0 */
    }
    floorwk->xposi.l += (floorwk->xspeed.w = ((short*)floorwk)[28]) << 8; /* Line 627, Address: 0x10216d8 */

    ((short*)floorwk)[28] += ((short*)floorwk)[29]; /* Line 629, Address: 0x1021704 */

    if (--floorwk->actfree[14] != 0) { for3_ridechk(floorwk); break; } /* Line 631, Address: 0x102171c */
    if (++floorwk->actfree[15] == 8) floorwk->actfree[15] = 2; /* Line 632, Address: 0x1021750 */
  } while (1); /* Line 633, Address: 0x1021780 */
} /* Line 634, Address: 0x1021788 */


void for3_umv(sprite_status* floorwk) { /* Line 637, Address: 0x10217a0 */
  for3_dmv(floorwk); /* Line 638, Address: 0x10217ac */
} /* Line 639, Address: 0x10217b8 */


void for3_dmv(sprite_status* floorwk) { /* Line 642, Address: 0x10217d0 */

  char for3_umvtbl0[16] = { /* Line 644, Address: 0x10217dc */
     35,   0,
      8,  64,
      8,  64,
     70,   0,
      8, -64,
      8, -64,
     70,   0,
      8,  64 };
  short for3_umvtbl1[8] = { -512, -512, 0, 512, 512, 0, -512, -512 }; /* Line 653, Address: 0x1021810 */

  char for3_dmvtbl0[16] = { /* Line 655, Address: 0x1021844 */
     35,   0,
      8, -64,
      8, -64,
     70,   0,
      8,  64,
      8,  64,
     70,   0,
      8, -64 };
  short for3_dmvtbl1[8] = { 512, 512, 0, -512, -512, 0, 512, 512 }; /* Line 664, Address: 0x1021878 */

  do {
    for3_ridechk(floorwk); /* Line 667, Address: 0x10218ac */

    if (floorwk->actfree[14] == 0) { /* Line 669, Address: 0x10218b8 */
      floorwk->actfree[21] = 0; /* Line 670, Address: 0x10218cc */
      if (floorwk->userflag.b.h == 3) { /* Line 671, Address: 0x10218d4 */
        floorwk->actfree[14] = for3_umvtbl0[floorwk->actfree[15] * 2]; /* Line 672, Address: 0x10218f0 */
        ((short*)floorwk)[29] = for3_umvtbl0[floorwk->actfree[15] * 2 + 1]; /* Line 673, Address: 0x1021910 */

        ((short*)floorwk)[28] = for3_umvtbl1[floorwk->actfree[15]]; /* Line 675, Address: 0x102193c */

      } else { /* Line 677, Address: 0x102195c */
        floorwk->actfree[14] = for3_dmvtbl0[floorwk->actfree[15] * 2]; /* Line 678, Address: 0x1021964 */
        ((short*)floorwk)[29] = for3_dmvtbl0[floorwk->actfree[15] * 2 + 1]; /* Line 679, Address: 0x1021984 */

        ((short*)floorwk)[28] = for3_dmvtbl1[floorwk->actfree[15]]; /* Line 681, Address: 0x10219b0 */
      }

      return; /* Line 684, Address: 0x10219d0 */
    }
    floorwk->yposi.l += ((short*)floorwk)[28] << 8; /* Line 686, Address: 0x10219d8 */
    ((short*)floorwk)[28] += ((short*)floorwk)[29]; /* Line 687, Address: 0x10219fc */
    floorwk->yspeed.w = ((unsigned short*)floorwk)[28] & 65280; /* Line 688, Address: 0x1021a14 */
    if (--floorwk->actfree[14] != 0) break; /* Line 689, Address: 0x1021a34 */
    if (++floorwk->actfree[15] == 8) floorwk->actfree[15] = 2; /* Line 690, Address: 0x1021a54 */
  } while (1); /* Line 691, Address: 0x1021a84 */
} /* Line 692, Address: 0x1021a8c */













void for3_rup(sprite_status* floorwk) { /* Line 706, Address: 0x1021aa0 */
  void(*tbl[3])(sprite_status*) = { &for3_rup1, &for3_rup2, &for3_rup3 }; /* Line 707, Address: 0x1021aac */

  for3_ridechk(floorwk); /* Line 709, Address: 0x1021ad0 */

  tbl[floorwk->actfree[16] / 2](floorwk); /* Line 711, Address: 0x1021adc */
} /* Line 712, Address: 0x1021b18 */



void for3_rup1(sprite_status* floorwk) { /* Line 716, Address: 0x1021b30 */
  if (floorwk->actfree[14] == 0) { /* Line 717, Address: 0x1021b3c */

    floorwk->actfree[21] = 1; /* Line 719, Address: 0x1021b50 */
    if (ridechk(floorwk, &actwk[0]) != 0) floorwk->actfree[14] = 30; /* Line 720, Address: 0x1021b5c */
    return; /* Line 721, Address: 0x1021b8c */
  }
  if (--floorwk->actfree[14] != 0) return; /* Line 723, Address: 0x1021b94 */
  floorwk->actfree[21] = 0; /* Line 724, Address: 0x1021bb4 */
  floorwk->actfree[16] += 2; /* Line 725, Address: 0x1021bbc */
} /* Line 726, Address: 0x1021bcc */



void for3_rup2(sprite_status* floorwk) { /* Line 730, Address: 0x1021be0 */

  char for3_8btbl0[6] = { /* Line 732, Address: 0x1021be8 */
     16, -16,  48,
      0,  16,  16
  };
  short for3_8btbl1[3] = { 0, -512, -512 }; /* Line 736, Address: 0x1021c1c */

  char for3_16btbl0[6] = { /* Line 738, Address: 0x1021c40 */
     16, -48,  69,
      0,  16,  48
  };
  short for3_16btbl1[3] = { 0, -768, -768 }; /* Line 742, Address: 0x1021c74 */

  char for3_28btbl0[6] = { /* Line 744, Address: 0x1021c98 */
     16, -64,  88,
      0,  16,  64
  };
  short for3_28btbl1[3] = { 0, -1024, -1024 }; /* Line 748, Address: 0x1021ccc */

  do {
    if (floorwk->actfree[14] == 0) { /* Line 751, Address: 0x1021cf0 */

      if (floorwk->userflag.b.h == 5) { /* Line 753, Address: 0x1021d04 */
        floorwk->actfree[14] = for3_8btbl0[floorwk->actfree[15] * 2]; /* Line 754, Address: 0x1021d20 */
        ((short*)floorwk)[29] = for3_8btbl0[floorwk->actfree[15] * 2 + 1]; /* Line 755, Address: 0x1021d40 */

        ((short*)floorwk)[28] = for3_8btbl1[floorwk->actfree[15]]; /* Line 757, Address: 0x1021d6c */

      } else if (floorwk->userflag.b.h == 6) { /* Line 759, Address: 0x1021d8c */
        floorwk->actfree[14] = for3_16btbl0[floorwk->actfree[15] * 2]; /* Line 760, Address: 0x1021db0 */
        ((short*)floorwk)[29] = for3_16btbl0[floorwk->actfree[15] * 2 + 1]; /* Line 761, Address: 0x1021dd0 */

        ((short*)floorwk)[28] = for3_16btbl1[floorwk->actfree[15]]; /* Line 763, Address: 0x1021dfc */

      } else { /* Line 765, Address: 0x1021e1c */
        floorwk->actfree[14] = for3_28btbl0[floorwk->actfree[15] * 2]; /* Line 766, Address: 0x1021e24 */
        ((short*)floorwk)[29] = for3_28btbl0[floorwk->actfree[15] * 2 + 1]; /* Line 767, Address: 0x1021e44 */

        ((short*)floorwk)[28] = for3_28btbl1[floorwk->actfree[15]]; /* Line 769, Address: 0x1021e70 */
      }

      return; /* Line 772, Address: 0x1021e90 */
    }
    ((short*)floorwk)[28] += ((short*)floorwk)[29]; /* Line 774, Address: 0x1021e98 */
    floorwk->yspeed.w = ((unsigned short*)floorwk)[28] & 65280; /* Line 775, Address: 0x1021eb0 */
    floorwk->yposi.l += floorwk->yspeed.w << 8; /* Line 776, Address: 0x1021ed0 */

    if (--floorwk->actfree[14] != 0) break; /* Line 778, Address: 0x1021ef4 */
  } while (++floorwk->actfree[15] != 3); /* Line 779, Address: 0x1021f14 */

  floorwk->yspeed.w = 0; /* Line 781, Address: 0x1021f38 */
  floorwk->actfree[21] = 1; /* Line 782, Address: 0x1021f40 */
  ((short*)floorwk)[26] = floorwk->yposi.w.h; /* Line 783, Address: 0x1021f4c */
  floorwk->actfree[16] += 2; /* Line 784, Address: 0x1021f5c */
} /* Line 785, Address: 0x1021f6c */


void for3_rup3(sprite_status* floorwk) { /* Line 788, Address: 0x1021f80 */
  floorwk->actno = floorwk->actno; /* Line 789, Address: 0x1021f88 */
} /* Line 790, Address: 0x1021f98 */








































void getdair3(sprite_status* floorwk) { /* Line 831, Address: 0x1021fb0 */
  void(*tbl[2])(sprite_status*) = { /* Line 832, Address: 0x1021fc0 */
    &getdair3_init,
    &getdair3_move
  };
  unsigned short cal_x;
  tbl[floorwk->r_no0 / 2](floorwk); /* Line 837, Address: 0x1021fdc */
  actionsub(floorwk); /* Line 838, Address: 0x1022018 */

  cal_x = (((unsigned short*)floorwk)[29] & 65408) - ((unsigned short)scra_h_posit.w.h - 128 & 65408); /* Line 840, Address: 0x1022024 */

  if (cal_x >= 641) tr3_fout(floorwk); /* Line 842, Address: 0x1022058 */
} /* Line 843, Address: 0x1022074 */


void getdair3_init(sprite_status* floorwk) { /* Line 846, Address: 0x1022090 */
  unsigned char getdair3_cnttbl[3] = { 0, 30, 60 }; /* Line 847, Address: 0x102209c */

  floorwk->actflg |= 4; /* Line 849, Address: 0x10220c0 */

  floorwk->sprpri = 3; /* Line 851, Address: 0x10220d0 */
  floorwk->patbase = getdair3pat; /* Line 852, Address: 0x10220dc */
  floorwk->sprhsize = 28; /* Line 853, Address: 0x10220ec */
  floorwk->sprvsize = 8; /* Line 854, Address: 0x10220f8 */

  ((short*)floorwk)[29] = floorwk->xposi.w.h; /* Line 856, Address: 0x1022104 */
  ((short*)floorwk)[27] = floorwk->yposi.w.h; /* Line 857, Address: 0x1022114 */

  floorwk->actfree[16] = getdair3_cnttbl[floorwk->userflag.b.h & 15]; /* Line 859, Address: 0x1022124 */

  floorwk->r_no0 += 2; /* Line 861, Address: 0x1022148 */
  getdair3_move(floorwk); /* Line 862, Address: 0x1022158 */
} /* Line 863, Address: 0x1022164 */


void getdair3_move(sprite_status* floorwk) { /* Line 866, Address: 0x1022180 */
  if (floorwk->userflag.b.h < 0) { /* Line 867, Address: 0x102218c */

    getdair3_move_sub(floorwk); /* Line 869, Address: 0x10221a4 */
    floorwk->xposi.w.h = ((short*)floorwk)[29] + floorwk->actfree[17]; /* Line 870, Address: 0x10221b0 */

  } /* Line 872, Address: 0x10221e8 */
  else {
    getdair3_move_sub(floorwk); /* Line 874, Address: 0x10221f0 */
    floorwk->xposi.w.h = ((short*)floorwk)[29] - floorwk->actfree[17]; /* Line 875, Address: 0x10221fc */
  }


  ridechk(floorwk, &actwk[0]); /* Line 879, Address: 0x1022234 */
} /* Line 880, Address: 0x1022248 */


void getdair3_move_sub(sprite_status* floorwk) { /* Line 883, Address: 0x1022260 */
  if (actwk[0].yposi.w.h < floorwk->yposi.w.h) { /* Line 884, Address: 0x1022268 */

    if ((char)(floorwk->actfree[17] -= 16) >= 0) return; /* Line 886, Address: 0x1022294 */
    floorwk->actfree[17] = 0; /* Line 887, Address: 0x10222c0 */

    if (floorwk->userflag.b.h & 15) return; /* Line 889, Address: 0x10222c8 */
    if (floorwk->actfree[18] != 0) return; /* Line 890, Address: 0x10222e4 */
    floorwk->actfree[16] = 60; /* Line 891, Address: 0x10222f8 */
    floorwk->actfree[18] = 255; /* Line 892, Address: 0x1022304 */
    return; /* Line 893, Address: 0x1022310 */
  }

  if ((floorwk->actfree[17] += 16) < 64) return; /* Line 896, Address: 0x1022318 */
  floorwk->actfree[17] = 64; /* Line 897, Address: 0x102233c */
  floorwk->actfree[16] = 8; /* Line 898, Address: 0x1022348 */
} /* Line 899, Address: 0x1022354 */












































































void gandair3(sprite_status* floorwk) { /* Line 976, Address: 0x1022360 */
  void(*tbl[2])(sprite_status*) = { &gandair3_daii, &gandair3_daim }; /* Line 977, Address: 0x1022370 */
  unsigned short cal_x;

  if (floorwk->userflag.b.h == 1) { gandair3_core(floorwk); return; } /* Line 980, Address: 0x102238c */
  else if (floorwk->userflag.b.h == 2) { gandair3_tama(floorwk); return; } /* Line 981, Address: 0x10223bc */

  tbl[floorwk->r_no0 / 2](floorwk); /* Line 983, Address: 0x10223ec */
  actionsub(floorwk); /* Line 984, Address: 0x1022428 */

  cal_x = (((unsigned short*)floorwk)[29] & 65408) - ((unsigned short)(scra_h_posit.w.h - 128) & 65408); /* Line 986, Address: 0x1022434 */

  if (cal_x >= 641) tr3_fout(floorwk); /* Line 988, Address: 0x1022470 */
} /* Line 989, Address: 0x102248c */



void gandair3_daii(sprite_status* floorwk) { /* Line 993, Address: 0x10224a0 */
  sprite_status* new_actwk;

  floorwk->actflg |= 4; /* Line 996, Address: 0x10224ac */

  floorwk->sprpri = 2; /* Line 998, Address: 0x10224bc */
  floorwk->patbase = gandair3pat; /* Line 999, Address: 0x10224c8 */
  ((short*)floorwk)[29] = floorwk->xposi.w.h; /* Line 1000, Address: 0x10224d8 */
  ((short*)floorwk)[27] = floorwk->yposi.w.h; /* Line 1001, Address: 0x10224e8 */
  floorwk->sprhsize = 16; /* Line 1002, Address: 0x10224f8 */

  if (actwkchk(&new_actwk) != 0) return; /* Line 1004, Address: 0x1022504 */

  new_actwk->actno = 39; /* Line 1006, Address: 0x1022518 */
  new_actwk->xposi.w.h = floorwk->xposi.w.h; /* Line 1007, Address: 0x1022524 */
  new_actwk->yposi.w.h = floorwk->yposi.w.h + 8; /* Line 1008, Address: 0x1022534 */
  new_actwk->userflag.b.h = 1; /* Line 1009, Address: 0x1022558 */

  floorwk->r_no0 += 2; /* Line 1011, Address: 0x1022564 */
  gandair3_daim(floorwk); /* Line 1012, Address: 0x1022574 */
} /* Line 1013, Address: 0x1022580 */


void gandair3_daim(sprite_status* floorwk) { /* Line 1016, Address: 0x1022590 */
  floorwk->actno = floorwk->actno; /* Line 1017, Address: 0x1022598 */
} /* Line 1018, Address: 0x10225a8 */



void gandair3_core(sprite_status* corewk) { /* Line 1022, Address: 0x10225c0 */
  void(*tbl[5])(sprite_status*) = { &gandair3_init, &gandair3_wait, &gandair3_fire, &gandair3_end, &gandair3_wait2 }; /* Line 1023, Address: 0x10225d0 */
  unsigned short cal_x;


  tbl[corewk->r_no0 / 2](corewk); /* Line 1027, Address: 0x10225fc */
  actionsub(corewk); /* Line 1028, Address: 0x1022638 */
  cal_x = (((unsigned short*)corewk)[29] & 65408) - ((unsigned short)(scra_h_posit.w.h - 128) & 65408); /* Line 1029, Address: 0x1022644 */

  if (cal_x >= 641) tr3_fout(corewk); /* Line 1031, Address: 0x1022680 */
} /* Line 1032, Address: 0x102269c */


void gandair3_ridechk(sprite_status* floorwk) { /* Line 1035, Address: 0x10226b0 */
  ride_on_chk(floorwk, &actwk[0]); /* Line 1036, Address: 0x10226bc */
} /* Line 1037, Address: 0x10226d0 */



void gandair3_init(sprite_status* corewk) { /* Line 1041, Address: 0x10226e0 */
  corewk->actflg |= 4; /* Line 1042, Address: 0x10226e8 */

  corewk->sprpri = 3; /* Line 1044, Address: 0x10226f8 */
  corewk->patbase = gandair3pat; /* Line 1045, Address: 0x1022704 */
  corewk->sprhsize = 16; /* Line 1046, Address: 0x1022714 */
  corewk->sprvsize = 20; /* Line 1047, Address: 0x1022720 */
  ((short*)corewk)[29] = corewk->xposi.w.h; /* Line 1048, Address: 0x102272c */
  ((short*)corewk)[27] = corewk->yposi.w.h; /* Line 1049, Address: 0x102273c */
  corewk->patno = 1; /* Line 1050, Address: 0x102274c */
  corewk->r_no0 += 2; /* Line 1051, Address: 0x1022758 */
} /* Line 1052, Address: 0x1022768 */



void gandair3_wait(sprite_status* corewk) { /* Line 1056, Address: 0x1022780 */
  short cal_x;

  if (corewk->actfree[16] == 0) { /* Line 1059, Address: 0x1022790 */

    if ((cal_x = corewk->xposi.w.h - actwk[0].xposi.w.h) < 0) cal_x = -cal_x; /* Line 1061, Address: 0x10227a4 */
    if (cal_x >= 120) { gandair3_ridechk(corewk); return; } /* Line 1062, Address: 0x102280c */

    corewk->actfree[16] = 60; /* Line 1064, Address: 0x1022834 */
  }

  if (--corewk->actfree[16] != 0) { /* Line 1067, Address: 0x1022840 */

    if (time_flag != 0) /* Line 1069, Address: 0x1022860 */
      if (time_flag == 1 || generate_flag == 0) /* Line 1070, Address: 0x1022874 */
        patchg(corewk, gandair3_pchg); /* Line 1071, Address: 0x10228a0 */
    gandair3_ridechk(corewk); /* Line 1072, Address: 0x10228b4 */
    return; /* Line 1073, Address: 0x10228c0 */
  }

  corewk->actfree[16] = corewk->actfree[17] = 0; /* Line 1076, Address: 0x10228c8 */
  corewk->patno = 1; /* Line 1077, Address: 0x10228dc */
  corewk->r_no0 += 2; /* Line 1078, Address: 0x10228e8 */
} /* Line 1079, Address: 0x10228f8 */



void gandair3_fire(sprite_status* corewk) { /* Line 1083, Address: 0x1022910 */
  if ((corewk->actfree[17] += 8) >= 32) corewk->actfree[17] = 32; /* Line 1084, Address: 0x102291c */
  corewk->yposi.w.h = ((short*)corewk)[27] - corewk->actfree[17]; /* Line 1085, Address: 0x102294c */


  if (corewk->actfree[17] != 32) { gandair3_ridechk(corewk); return; } /* Line 1088, Address: 0x1022984 */

  gandair3_tamaset(corewk); /* Line 1090, Address: 0x10229b0 */
  if (ride_on_chk(corewk, &actwk[0]) == 0) { /* Line 1091, Address: 0x10229bc */
    corewk->actfree[16] = 8; /* Line 1092, Address: 0x10229e0 */
    corewk->r_no0 += 2; /* Line 1093, Address: 0x10229ec */
    return; /* Line 1094, Address: 0x10229fc */
  }


  actwk[0].yspeed.w = -1792; /* Line 1098, Address: 0x1022a04 */
  actwk[0].cddat |= 2; /* Line 1099, Address: 0x1022a10 */
  actwk[0].cddat &= 247; /* Line 1100, Address: 0x1022a24 */
  actwk[0].mstno.b.h = 16; /* Line 1101, Address: 0x1022a38 */
  corewk->cddat &= 247; /* Line 1102, Address: 0x1022a44 */
} /* Line 1103, Address: 0x1022a54 */



void gandair3_end(sprite_status* corewk) { /* Line 1107, Address: 0x1022a70 */
  if (corewk->actfree[16] != 0) { /* Line 1108, Address: 0x1022a7c */
    --corewk->actfree[16]; /* Line 1109, Address: 0x1022a90 */
    gandair3_ridechk(corewk); /* Line 1110, Address: 0x1022aa0 */
    return; /* Line 1111, Address: 0x1022aac */
  }
  if ((char)(corewk->actfree[17] -= 4) < 0) corewk->actfree[16] = 0; /* Line 1113, Address: 0x1022ab4 */
  corewk->yposi.w.h = ((short*)corewk)[27] - corewk->actfree[17]; /* Line 1114, Address: 0x1022ae8 */

  if (corewk->actfree[17] == 0) { /* Line 1116, Address: 0x1022b20 */
    corewk->actfree[16] = 60; /* Line 1117, Address: 0x1022b34 */
    corewk->r_no0 += 2; /* Line 1118, Address: 0x1022b40 */
  }
  gandair3_ridechk(corewk); /* Line 1120, Address: 0x1022b50 */
} /* Line 1121, Address: 0x1022b5c */



void gandair3_wait2(sprite_status* corewk) { /* Line 1125, Address: 0x1022b70 */
  if (corewk->actfree[16] == 0) { corewk->r_no0 = 2; return; } /* Line 1126, Address: 0x1022b7c */
  --corewk->actfree[16]; /* Line 1127, Address: 0x1022ba4 */
  gandair3_ridechk(corewk); /* Line 1128, Address: 0x1022bb4 */
} /* Line 1129, Address: 0x1022bc0 */



void gandair3_tamaset(sprite_status* corewk) { /* Line 1133, Address: 0x1022bd0 */
  sprite_status* new_actwk;

  if (time_flag == 0) return; /* Line 1136, Address: 0x1022bdc */
  if (time_flag != 1 && generate_flag != 0) return; /* Line 1137, Address: 0x1022bf0 */

  if (actwkchk(&new_actwk) == 0) { /* Line 1139, Address: 0x1022c1c */

    new_actwk->actno = 39; /* Line 1141, Address: 0x1022c30 */
    new_actwk->userflag.b.h = 2; /* Line 1142, Address: 0x1022c3c */
    new_actwk->yposi.w.h = corewk->yposi.w.h + 8; /* Line 1143, Address: 0x1022c48 */
    new_actwk->xposi.w.h = corewk->xposi.w.h - 24; /* Line 1144, Address: 0x1022c6c */
  }
  if (actwkchk(&new_actwk) == 0) { /* Line 1146, Address: 0x1022c90 */

    new_actwk->actno = 39; /* Line 1148, Address: 0x1022ca4 */
    new_actwk->userflag.b.h = 2; /* Line 1149, Address: 0x1022cb0 */
    new_actwk->yposi.w.h = corewk->yposi.w.h + 8; /* Line 1150, Address: 0x1022cbc */
    new_actwk->xposi.w.h = corewk->xposi.w.h + 24; /* Line 1151, Address: 0x1022ce0 */
    new_actwk->actfree[16] = 1; /* Line 1152, Address: 0x1022d04 */
  }
} /* Line 1154, Address: 0x1022d10 */



void gandair3_tama(sprite_status* bulletwk) { /* Line 1158, Address: 0x1022d20 */
  void(*tbl[2])(sprite_status*) = { &gandair3_tami, &gandair3_tamm }; /* Line 1159, Address: 0x1022d2c */

  tbl[bulletwk->r_no0 / 2](bulletwk); /* Line 1161, Address: 0x1022d48 */
  actionsub(bulletwk); /* Line 1162, Address: 0x1022d84 */
  frameout_s(bulletwk); /* Line 1163, Address: 0x1022d90 */
} /* Line 1164, Address: 0x1022d9c */



void gandair3_tami(sprite_status* bulletwk) { /* Line 1168, Address: 0x1022db0 */
  bulletwk->actflg |= 4; /* Line 1169, Address: 0x1022dbc */

  bulletwk->sprpri = 4; /* Line 1171, Address: 0x1022dcc */
  bulletwk->colino = 152; /* Line 1172, Address: 0x1022dd8 */
  bulletwk->patbase = gandair3pat; /* Line 1173, Address: 0x1022de4 */
  ((short*)bulletwk)[29] = bulletwk->xposi.w.h; /* Line 1174, Address: 0x1022df4 */
  if (bulletwk->actfree[16] != 0) { /* Line 1175, Address: 0x1022e04 */
    bulletwk->xspeed.w = 256; /* Line 1176, Address: 0x1022e18 */
    ((short*)bulletwk)[33] = 16; /* Line 1177, Address: 0x1022e24 */
    bulletwk->mstno.b.h = 2; /* Line 1178, Address: 0x1022e30 */
  } else { /* Line 1179, Address: 0x1022e3c */
    bulletwk->xspeed.w = -256; /* Line 1180, Address: 0x1022e44 */
    ((short*)bulletwk)[33] = -16; /* Line 1181, Address: 0x1022e50 */
    bulletwk->mstno.b.h = 1; /* Line 1182, Address: 0x1022e5c */
  }
  bulletwk->r_no0 += 2; /* Line 1184, Address: 0x1022e68 */
  patchg(bulletwk, gandair3_pchg); /* Line 1185, Address: 0x1022e78 */
  gandair3_tamm(bulletwk); /* Line 1186, Address: 0x1022e8c */
} /* Line 1187, Address: 0x1022e98 */


void gandair3_tamm(sprite_status* bulletwk) { /* Line 1190, Address: 0x1022eb0 */
  short cal_x;

  bulletwk->xspeed.w += ((short*)bulletwk)[33]; /* Line 1193, Address: 0x1022ec0 */
  bulletwk->xposi.l += bulletwk->xspeed.w << 8; /* Line 1194, Address: 0x1022ed8 */
  patchg(bulletwk, gandair3_pchg); /* Line 1195, Address: 0x1022efc */

  cal_x = bulletwk->xposi.w.h - ((short*)bulletwk)[29]; /* Line 1197, Address: 0x1022f10 */
  if (cal_x < 0) cal_x = -cal_x; /* Line 1198, Address: 0x1022f44 */
  if (cal_x < 64) return; /* Line 1199, Address: 0x1022f70 */

  bulletwk->colino = 0; /* Line 1201, Address: 0x1022f84 */
  if (bulletwk->actfree[17] == 0) { /* Line 1202, Address: 0x1022f8c */
    bulletwk->mstno.b.h += 2; /* Line 1203, Address: 0x1022fa0 */
    bulletwk->actfree[17] = 30; /* Line 1204, Address: 0x1022fb0 */
  }

  if (--bulletwk->actfree[17] != 0) return; /* Line 1207, Address: 0x1022fbc */

  frameout(bulletwk); /* Line 1209, Address: 0x1022fdc */
} /* Line 1210, Address: 0x1022fe8 */














































void drumr3(sprite_status* drumwk) { /* Line 1257, Address: 0x1023000 */
  unsigned short cal_x;
  void(*tbl[4])(sprite_status*) = { /* Line 1259, Address: 0x1023010 */
    &drumr3_init,
    &drumr3_move1,
    &drumr3_move2,
    &drumr3_move3
  };
  tbl[drumwk->r_no0 / 2](drumwk); /* Line 1265, Address: 0x102303c */
  actionsub(drumwk); /* Line 1266, Address: 0x1023078 */

  cal_x = (((unsigned short*)drumwk)[27] & 65408) - ((unsigned short)(scra_h_posit.w.h - 128) & 65408); /* Line 1268, Address: 0x1023084 */

  if (cal_x >= 641) tr3_fout(drumwk); /* Line 1270, Address: 0x10230c0 */
} /* Line 1271, Address: 0x10230dc */


void drumr3_ridechk(sprite_status* drumwk) { /* Line 1274, Address: 0x10230f0 */
  if (!(drumwk->actflg & 128)) return; /* Line 1275, Address: 0x10230fc */

  if (time_flag == 0) { /* Line 1277, Address: 0x1023114 */
    if (drumwk->patno == 2) drumwk->sprvsize = 8; /* Line 1278, Address: 0x1023128 */
    if (drumwk->patno >= 3 && drumwk->patno < 7) drumwk->sprvsize = 5; /* Line 1279, Address: 0x102314c */
  }
  ridechk(drumwk, &actwk[0]); /* Line 1281, Address: 0x1023188 */
} /* Line 1282, Address: 0x102319c */



void drumr3_init(sprite_status* drumwk) { /* Line 1286, Address: 0x10231b0 */
  drumwk->actflg |= 4; /* Line 1287, Address: 0x10231b8 */

  drumwk->sprpri = 3; /* Line 1289, Address: 0x10231c8 */
  drumwk->patbase = drumr3pat; /* Line 1290, Address: 0x10231d4 */
  drumwk->sprhsize = 24; /* Line 1291, Address: 0x10231e4 */
  ((short*)drumwk)[27] = drumwk->xposi.w.h; /* Line 1292, Address: 0x10231f0 */
  ((short*)drumwk)[26] = drumwk->yposi.w.h; /* Line 1293, Address: 0x1023200 */
  drumwk->r_no0 += 2; /* Line 1294, Address: 0x1023210 */
  drumwk->actfree[17] = drumwk->userflag.b.h; /* Line 1295, Address: 0x1023220 */
  if (drumwk->userflag.b.h >= 2) drumwk->r_no0 += 2; /* Line 1296, Address: 0x1023230 */
  if (drumwk->userflag.b.h >= 6) drumwk->r_no0 += 2; /* Line 1297, Address: 0x102325c */
} /* Line 1298, Address: 0x1023288 */



void drumr3_move1(sprite_status* drumwk) { /* Line 1302, Address: 0x10232a0 */
  do {
    if (drumwk->actfree[16] == 0) { /* Line 1304, Address: 0x10232ac */
      ride_on_clr(drumwk, &actwk[0]); /* Line 1305, Address: 0x10232c0 */
      drumr3_cntset(drumwk); /* Line 1306, Address: 0x10232d4 */
      return; /* Line 1307, Address: 0x10232e0 */
    }
    if (time_flag == 0) return; /* Line 1309, Address: 0x10232e8 */
    if (gametimer.w % 10 != 0) return; /* Line 1310, Address: 0x10232fc */

    drumr3_addspd(drumwk); /* Line 1312, Address: 0x1023320 */
    if (--drumwk->actfree[16] != 0) return; /* Line 1313, Address: 0x102332c */

  } while (++drumwk->actfree[17] < 2); /* Line 1315, Address: 0x102334c */
  drumwk->r_no0 += 2; /* Line 1316, Address: 0x1023370 */
} /* Line 1317, Address: 0x1023380 */



void drumr3_move2(sprite_status* drumwk) { /* Line 1321, Address: 0x1023390 */
  do {
    drumr3_ridechk(drumwk); /* Line 1323, Address: 0x102339c */
    if (drumwk->actfree[16] == 0) /* Line 1324, Address: 0x10233a8 */
    { drumr3_cntset(drumwk); return; } /* Line 1325, Address: 0x10233bc */

    if (time_flag == 0) return; /* Line 1327, Address: 0x10233d0 */
    if (gametimer.w % 10 != 0) return; /* Line 1328, Address: 0x10233e4 */

    drumr3_addspd(drumwk); /* Line 1330, Address: 0x1023408 */
    if (--drumwk->actfree[16] != 0) return; /* Line 1331, Address: 0x1023414 */

  } while (++drumwk->actfree[17] < 6); /* Line 1333, Address: 0x1023434 */
  drumwk->r_no0 += 2; /* Line 1334, Address: 0x1023458 */
} /* Line 1335, Address: 0x1023468 */



void drumr3_move3(sprite_status* drumwk) { /* Line 1339, Address: 0x1023480 */
  do {
    if (drumwk->actfree[16] == 0) { /* Line 1341, Address: 0x102348c */
      ride_on_clr(drumwk, &actwk[0]); /* Line 1342, Address: 0x10234a0 */
      drumr3_cntset(drumwk); /* Line 1343, Address: 0x10234b4 */
      return; /* Line 1344, Address: 0x10234c0 */
    }
    if (time_flag == 0) return; /* Line 1346, Address: 0x10234c8 */
    if (gametimer.w % 10 != 0) return; /* Line 1347, Address: 0x10234dc */

    drumr3_addspd(drumwk); /* Line 1349, Address: 0x1023500 */
    if (--drumwk->actfree[16] != 0) return; /* Line 1350, Address: 0x102350c */
  } while (++drumwk->actfree[17] < 18); /* Line 1351, Address: 0x102352c */
  drumwk->actfree[16] = drumwk->actfree[17] = 0; /* Line 1352, Address: 0x1023550 */
  drumwk->r_no0 = 2; /* Line 1353, Address: 0x1023564 */
} /* Line 1354, Address: 0x1023570 */



void drumr3_addspd(sprite_status* drumwk) { /* Line 1358, Address: 0x1023580 */
  drumwk->yspeed.w = ((short*)drumwk)[29]; /* Line 1359, Address: 0x1023588 */
  drumwk->yposi.l += drumwk->yspeed.w << 8; /* Line 1360, Address: 0x1023598 */
} /* Line 1361, Address: 0x10235bc */



void drumr3_cntset(sprite_status* drumwk) { /* Line 1365, Address: 0x10235d0 */

  unsigned char drumr3_mvtbl[54] = { /* Line 1367, Address: 0x10235dc */
      1,   8,   0,
      5,   8,   1,
      6,  12,   2,
      8,  11,   3,
      8,  11,   4,
      8,  11,   5,
      6,  11,   6,
      5,   8,   7,
      1,   8,   8,
    255,   4,   9,
    251,   4,  10,
    250,   8,  10,
    248,   8,  10,
    248,   8,  10,
    248,   8,  10,
    250,   8,  10,
    251,   8,  10,
    255,   4,  11
  };

  drumwk->actfree[13] = drumr3_mvtbl[drumwk->actfree[17] * 3]; /* Line 1388, Address: 0x1023610 */

  drumwk->sprvsize = drumr3_mvtbl[drumwk->actfree[17] * 3 + 1]; /* Line 1390, Address: 0x1023634 */
  drumwk->patno = drumr3_mvtbl[drumwk->actfree[17] * 3 + 2]; /* Line 1391, Address: 0x102365c */
  drumwk->actfree[16] = 4; /* Line 1392, Address: 0x1023684 */
  drumr3_priset(drumwk); /* Line 1393, Address: 0x1023690 */
} /* Line 1394, Address: 0x102369c */



void drumr3_priset(sprite_status* drumwk) { /* Line 1398, Address: 0x10236b0 */
  unsigned char tbl[12] = { 5, 4, 3, 2, 2, 2, 3, 4, 5, 6, 6, 6 }; /* Line 1399, Address: 0x10236b8 */

  drumwk->sprpri = tbl[drumwk->patno]; /* Line 1401, Address: 0x10236ec */
} /* Line 1402, Address: 0x1023708 */







void tr3_fout(sprite_status* thingwk) { /* Line 1410, Address: 0x1023720 */
  unsigned short flagwork_no;

  if ((flagwork_no = thingwk->cdsts) != 0) { /* Line 1413, Address: 0x1023730 */
    flagwork_no = time_flag + flagwork_no * 3; /* Line 1414, Address: 0x1023750 */
    flagwork[flagwork_no] &= 127; /* Line 1415, Address: 0x1023778 */
  }

  frameout(thingwk); /* Line 1418, Address: 0x1023794 */
} /* Line 1419, Address: 0x10237a0 */
