#include "..\EQU.H"
#include "BEAM.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"

static void beam_init(sprite_status* beamwk);
static void beam_mast(sprite_status* beamwk);
static void beam_move0(sprite_status* beamwk);
static void beam_move1(sprite_status* beamwk);
static void beam_move2(sprite_status* beamwk);
static void beam_coli0(sprite_status* beamwk);
static void beam_coli(sprite_status* beamwk);

static sprite_pattern bea00 = {
  2,
  { {
    { -8, -12, 0, 294 },
    { 0, -12, 8, 294 }
  } }
};
static sprite_pattern bea01 = {
  2,
  { {
    { -8, -12, 0, 295 },
    { 0, -12, 8, 295 }
  } }
};
static sprite_pattern bea02 = {
  2,
  { {
    { -8, -12, 0, 295 },
    { 0, -12, 8, 295 }
  } }
};
static sprite_pattern bea03 = {
  2,
  { {
    { -8, -4, 0, 300 },
    { 0, -4, 8, 300 }
  } }
};
static sprite_pattern bea04 = {
  2,
  { {
    { -8, -4, 0, 301 },
    { 0, -4, 8, 301 }
  } }
};
static sprite_pattern bea05 = {
  2,
  { {
    { -4, -4, 0, 297 },
    { -4, -12, 0, 297 }
  } }
};
static sprite_pattern bea06 = {
  4,
  { {
    { -4, -4, 0, 297 },
    { -4, -12, 0, 297 },
    { -4, -20, 0, 297 },
    { -4, -28, 0, 297 }
  } }
};
static sprite_pattern bea07 = {
  6,
  { {
    { -4, -4, 0, 297 },
    { -4, -12, 0, 297 },
    { -4, -20, 0, 297 },
    { -4, -28, 0, 297 },
    { -4, -36, 0, 297 },
    { -4, -44, 0, 297 }
  } }
};
static sprite_pattern bea08 = {
  8,
  { {
    { -4, -4, 0, 297 },
    { -4, -12, 0, 297 },
    { -4, -20, 0, 297 },
    { -4, -28, 0, 297 },
    { -4, -36, 0, 297 },
    { -4, -44, 0, 297 },
    { -4, -52, 0, 297 },
    { -4, -60, 0, 297 }
  } }
};
static sprite_pattern bea09 = {
  10,
  { {
    { -4, -4, 0, 297 },
    { -4, -12, 0, 297 },
    { -4, -20, 0, 297 },
    { -4, -28, 0, 297 },
    { -4, -36, 0, 297 },
    { -4, -44, 0, 297 },
    { -4, -52, 0, 297 },
    { -4, -60, 0, 297 },
    { -4, -68, 0, 297 },
    { -4, -76, 0, 297 }
  } }
};
static sprite_pattern bea0a = {
  12,
  { {
    { -4, -4, 0, 297 },
    { -4, -12, 0, 297 },
    { -4, -20, 0, 297 },
    { -4, -28, 0, 297 },
    { -4, -36, 0, 297 },
    { -4, -44, 0, 297 },
    { -4, -52, 0, 297 },
    { -4, -60, 0, 297 },
    { -4, -68, 0, 297 },
    { -4, -76, 0, 297 },
    { -4, -84, 0, 297 },
    { -4, -92, 0, 297 }
  } }
};
static sprite_pattern bea0b = {
  14,
  { {
    { -4, -4, 0, 297 },
    { -4, -12, 0, 297 },
    { -4, -20, 0, 297 },
    { -4, -28, 0, 297 },
    { -4, -36, 0, 297 },
    { -4, -44, 0, 297 },
    { -4, -52, 0, 297 },
    { -4, -60, 0, 297 },
    { -4, -68, 0, 297 },
    { -4, -76, 0, 297 },
    { -4, -84, 0, 297 },
    { -4, -92, 0, 297 },
    { -4, -100, 0, 297 },
    { -4, -108, 0, 297 }
  } }
};
static sprite_pattern bea0c = {
  16,
  { {
    { -4, -4, 0, 297 },
    { -4, -12, 0, 297 },
    { -4, -20, 0, 297 },
    { -4, -28, 0, 297 },
    { -4, -36, 0, 297 },
    { -4, -44, 0, 297 },
    { -4, -52, 0, 297 },
    { -4, -60, 0, 297 },
    { -4, -68, 0, 297 },
    { -4, -76, 0, 297 },
    { -4, -84, 0, 297 },
    { -4, -92, 0, 297 },
    { -4, -100, 0, 297 },
    { -4, -108, 0, 297 },
    { -4, -116, 0, 297 },
    { -4, -124, 0, 297 }
  } }
};
static sprite_pattern bea0d = {
  2,
  { {
    { -4, -4, 0, 298 },
    { -4, -12, 0, 298 }
  } }
};
static sprite_pattern bea0e = {
  4,
  { {
    { -4, -4, 0, 298 },
    { -4, -12, 0, 298 },
    { -4, -20, 0, 298 },
    { -4, -28, 0, 298 }
  } }
};
static sprite_pattern bea0f = {
  6,
  { {
    { -4, -4, 0, 298 },
    { -4, -12, 0, 298 },
    { -4, -20, 0, 298 },
    { -4, -28, 0, 298 },
    { -4, -36, 0, 298 },
    { -4, -44, 0, 298 }
  } }
};
static sprite_pattern bea10 = {
  8,
  { {
    { -4, -4, 0, 298 },
    { -4, -12, 0, 298 },
    { -4, -20, 0, 298 },
    { -4, -28, 0, 298 },
    { -4, -36, 0, 298 },
    { -4, -44, 0, 298 },
    { -4, -52, 0, 298 },
    { -4, -60, 0, 298 }
  } }
};
static sprite_pattern bea11 = {
  10,
  { {
    { -4, -4, 0, 298 },
    { -4, -12, 0, 298 },
    { -4, -20, 0, 298 },
    { -4, -28, 0, 298 },
    { -4, -36, 0, 298 },
    { -4, -44, 0, 298 },
    { -4, -52, 0, 298 },
    { -4, -60, 0, 298 },
    { -4, -68, 0, 298 },
    { -4, -76, 0, 298 }
  } }
};
static sprite_pattern bea12 = {
  12,
  { {
    { -4, -4, 0, 298 },
    { -4, -12, 0, 298 },
    { -4, -20, 0, 298 },
    { -4, -28, 0, 298 },
    { -4, -36, 0, 298 },
    { -4, -44, 0, 298 },
    { -4, -52, 0, 298 },
    { -4, -60, 0, 298 },
    { -4, -68, 0, 298 },
    { -4, -76, 0, 298 },
    { -4, -84, 0, 298 },
    { -4, -92, 0, 298 }
  } }
};
static sprite_pattern bea13 = {
  14,
  { {
    { -4, -4, 0, 298 },
    { -4, -12, 0, 298 },
    { -4, -20, 0, 298 },
    { -4, -28, 0, 298 },
    { -4, -36, 0, 298 },
    { -4, -44, 0, 298 },
    { -4, -52, 0, 298 },
    { -4, -60, 0, 298 },
    { -4, -68, 0, 298 },
    { -4, -76, 0, 298 },
    { -4, -84, 0, 298 },
    { -4, -92, 0, 298 },
    { -4, -100, 0, 298 },
    { -4, -108, 0, 298 }
  } }
};
static sprite_pattern bea14 = {
  16,
  { {
    { -4, -4, 0, 298 },
    { -4, -12, 0, 298 },
    { -4, -20, 0, 298 },
    { -4, -28, 0, 298 },
    { -4, -36, 0, 298 },
    { -4, -44, 0, 298 },
    { -4, -52, 0, 298 },
    { -4, -60, 0, 298 },
    { -4, -68, 0, 298 },
    { -4, -76, 0, 298 },
    { -4, -84, 0, 298 },
    { -4, -92, 0, 298 },
    { -4, -100, 0, 298 },
    { -4, -108, 0, 298 },
    { -4, -116, 0, 298 },
    { -4, -124, 0, 298 }
  } }
};
static sprite_pattern bea15 = {
  2,
  { {
    { -4, -4, 0, 299 },
    { -4, -12, 0, 299 }
  } }
};
static sprite_pattern bea16 = {
  4,
  { {
    { -4, -4, 0, 299 },
    { -4, -12, 0, 299 },
    { -4, -20, 0, 299 },
    { -4, -28, 0, 299 }
  } }
};
static sprite_pattern bea17 = {
  6,
  { {
    { -4, -4, 0, 299 },
    { -4, -12, 0, 299 },
    { -4, -20, 0, 299 },
    { -4, -28, 0, 299 },
    { -4, -36, 0, 299 },
    { -4, -44, 0, 299 }
  } }
};
static sprite_pattern bea18 = {
  8,
  { {
    { -4, -4, 0, 299 },
    { -4, -12, 0, 299 },
    { -4, -20, 0, 299 },
    { -4, -28, 0, 299 },
    { -4, -36, 0, 299 },
    { -4, -44, 0, 299 },
    { -4, -52, 0, 299 },
    { -4, -60, 0, 299 }
  } }
};
static sprite_pattern bea19 = {
  10,
  { {
    { -4, -4, 0, 299 },
    { -4, -12, 0, 299 },
    { -4, -20, 0, 299 },
    { -4, -28, 0, 299 },
    { -4, -36, 0, 299 },
    { -4, -44, 0, 299 },
    { -4, -52, 0, 299 },
    { -4, -60, 0, 299 },
    { -4, -68, 0, 299 },
    { -4, -76, 0, 299 }
  } }
};
static sprite_pattern bea1a = {
  12,
  { {
    { -4, -4, 0, 299 },
    { -4, -12, 0, 299 },
    { -4, -20, 0, 299 },
    { -4, -28, 0, 299 },
    { -4, -36, 0, 299 },
    { -4, -44, 0, 299 },
    { -4, -52, 0, 299 },
    { -4, -60, 0, 299 },
    { -4, -68, 0, 299 },
    { -4, -76, 0, 299 },
    { -4, -84, 0, 299 },
    { -4, -92, 0, 299 }
  } }
};
static sprite_pattern bea1b = {
  14,
  { {
    { -4, -4, 0, 299 },
    { -4, -12, 0, 299 },
    { -4, -20, 0, 299 },
    { -4, -28, 0, 299 },
    { -4, -36, 0, 299 },
    { -4, -44, 0, 299 },
    { -4, -52, 0, 299 },
    { -4, -60, 0, 299 },
    { -4, -68, 0, 299 },
    { -4, -76, 0, 299 },
    { -4, -84, 0, 299 },
    { -4, -92, 0, 299 },
    { -4, -100, 0, 299 },
    { -4, -108, 0, 299 }
  } }
};
static sprite_pattern bea1c = {
  16,
  { {
    { -4, -4, 0, 299 },
    { -4, -12, 0, 299 },
    { -4, -20, 0, 299 },
    { -4, -28, 0, 299 },
    { -4, -36, 0, 299 },
    { -4, -44, 0, 299 },
    { -4, -52, 0, 299 },
    { -4, -60, 0, 299 },
    { -4, -68, 0, 299 },
    { -4, -76, 0, 299 },
    { -4, -84, 0, 299 },
    { -4, -92, 0, 299 },
    { -4, -100, 0, 299 },
    { -4, -108, 0, 299 },
    { -4, -116, 0, 299 },
    { -4, -124, 0, 299 }
  } }
};
static sprite_pattern bea1d = {
  2,
  { {
    { -8, -4, 0, 302 },
    { 0, -4, 0, 303 }
  } }
};
sprite_pattern* beampat[21] = { &bea00, &bea01, &bea02, &bea03, &bea04, &bea05, &bea06, &bea07, &bea08, &bea09, &bea0a, &bea0b, &bea0c, &bea0d, &bea0e, &bea0f, &bea10, &bea11, &bea12, &bea13, &bea14 };
sprite_pattern* beampat0[21] = { &bea00, &bea01, &bea02, &bea03, &bea1d, &bea05, &bea06, &bea07, &bea08, &bea09, &bea0a, &bea0b, &bea0c, &bea15, &bea16, &bea17, &bea18, &bea19, &bea1a, &bea1b, &bea1c };
static unsigned char beamchg0[4] = { 2, 5, 13, 255 };
static unsigned char beamchg1[4] = { 2, 14, 6, 255 };
static unsigned char beamchg2[4] = { 2, 7, 15, 255 };
static unsigned char beamchg3[4] = { 2, 16, 8, 255 };
static unsigned char beamchg4[4] = { 2, 9, 17, 255 };
static unsigned char beamchg5[4] = { 2, 18, 10, 255 };
static unsigned char beamchg6[4] = { 2, 11, 19, 255 };
static unsigned char beamchg7[4] = { 2, 20, 12, 255 };
static unsigned char beamchg8[4] = { 2, 3, 4, 255 };
static unsigned char* beamchg[9] = { beamchg0, beamchg1, beamchg2, beamchg3, beamchg4, beamchg5, beamchg6, beamchg7, beamchg8 };







void beam(sprite_status* beamwk) { /* Line 414, Address: 0x1023110 */
  void(*tbl[5])(sprite_status*) = { &beam_init, &beam_mast, &beam_move0, &beam_move1, &beam_move2 }; /* Line 415, Address: 0x102311c */


  tbl[beamwk->r_no0 / 2](beamwk); /* Line 418, Address: 0x1023148 */
  actionsub(beamwk); /* Line 419, Address: 0x1023184 */
  frameout_s(beamwk); /* Line 420, Address: 0x1023190 */
} /* Line 421, Address: 0x102319c */



static void beam_init(sprite_status* beamwk) { /* Line 425, Address: 0x10231b0 */
  beamwk->r_no0 += 2; /* Line 426, Address: 0x10231bc */
  beamwk->actflg |= 4; /* Line 427, Address: 0x10231cc */

  beamwk->patbase = beampat; /* Line 429, Address: 0x10231dc */
  beamwk->patno = 1; /* Line 430, Address: 0x10231ec */
  if (beamwk->userflag.b.h) { /* Line 431, Address: 0x10231f8 */
    beamwk->patno = 2; /* Line 432, Address: 0x1023208 */
    beamwk->patbase= beampat0; /* Line 433, Address: 0x1023214 */
  }
  beamwk->actfree[0] = 1; /* Line 435, Address: 0x1023224 */
  beam_mast(beamwk); /* Line 436, Address: 0x1023230 */
} /* Line 437, Address: 0x102323c */


static void beam_mast(sprite_status* beamwk) { /* Line 440, Address: 0x1023250 */
  sprite_status* new_actwk;

  if (--beamwk->actfree[0]) return; /* Line 443, Address: 0x102325c */

  if (actwkchk2(beamwk, &new_actwk) != 0) { /* Line 445, Address: 0x1023278 */
    if (actwkchk(&new_actwk) != 0) return; /* Line 446, Address: 0x1023290 */
  }
  new_actwk->actno = 29; /* Line 448, Address: 0x10232a4 */
  new_actwk->r_no0 = 4; /* Line 449, Address: 0x10232b0 */

  new_actwk->patbase = beamwk->patbase; /* Line 451, Address: 0x10232bc */
  new_actwk->actflg |= 4; /* Line 452, Address: 0x10232cc */
  new_actwk->sprpri = 2; /* Line 453, Address: 0x10232dc */
  new_actwk->xposi.w.h = beamwk->xposi.w.h; /* Line 454, Address: 0x10232e8 */
  new_actwk->yposi.w.h = beamwk->yposi.w.h & 65520; /* Line 455, Address: 0x10232f8 */
  new_actwk->userflag.b.h = beamwk->userflag.b.h; /* Line 456, Address: 0x102331c */

  new_actwk->sprvsize = 4; /* Line 458, Address: 0x102332c */

  beamwk->actfree[0] = 30; /* Line 460, Address: 0x1023338 */
  if ((char)beamwk->actflg < 0) { /* Line 461, Address: 0x1023344 */
    if (beamwk->userflag.b.h == 0) soundset(197); /* Line 462, Address: 0x1023364 */
    else soundset(188); /* Line 463, Address: 0x1023390 */
  }
} /* Line 465, Address: 0x102339c */


static void beam_move0(sprite_status* beamwk) { /* Line 468, Address: 0x10233b0 */
  sprite_status *new_actwk, **parent;

  beamwk->yposi.w.h += 4; /* Line 471, Address: 0x10233c0 */
  if (!(beamwk->yposi.w.h & 15)) { /* Line 472, Address: 0x10233d0 */
    if (++beamwk->mstno.b.h >= 7) beamwk->mstno.b.h = 7; /* Line 473, Address: 0x10233ec */
  }
  patchg(beamwk, beamchg); /* Line 475, Address: 0x1023424 */

  if (emycol_d(beamwk) >= 0) goto label1; /* Line 477, Address: 0x1023438 */
  beamwk->r_no0 += 2; /* Line 478, Address: 0x1023454 */
  if (actwkchk2(beamwk, &new_actwk) != 0) { /* Line 479, Address: 0x1023464 */
    beamwk->actfree[21] = 255; /* Line 480, Address: 0x102347c */
    goto label1; /* Line 481, Address: 0x1023488 */
  }
  new_actwk->actno = 29; /* Line 483, Address: 0x1023490 */

  new_actwk->patbase = beamwk->patbase; /* Line 485, Address: 0x102349c */
  new_actwk->actflg |= 4; /* Line 486, Address: 0x10234ac */
  new_actwk->xposi.w.h = beamwk->xposi.w.h; /* Line 487, Address: 0x10234bc */
  new_actwk->yposi.w.h = beamwk->yposi.w.h; /* Line 488, Address: 0x10234cc */
  new_actwk->r_no0 = 8; /* Line 489, Address: 0x10234dc */
  new_actwk->mstno.b.h = 8; /* Line 490, Address: 0x10234e8 */
  parent = &((sprite_status**)beamwk)[12]; /* Line 491, Address: 0x10234f4 */
  *parent = new_actwk; /* Line 492, Address: 0x10234fc */
label1:
  beam_coli0(beamwk); /* Line 494, Address: 0x1023504 */
} /* Line 495, Address: 0x1023510 */


static void beam_move1(sprite_status* beamwk) { /* Line 498, Address: 0x1023530 */
  short cal_yposi;
  sprite_status **parent, *new_actwk;

  cal_yposi = beamwk->yposi.w.h + 4; /* Line 502, Address: 0x1023548 */
  if (!(cal_yposi & 15)) { /* Line 503, Address: 0x102356c */
    cal_yposi -= 16; /* Line 504, Address: 0x1023580 */
    if (beamwk->mstno.b.h - 1 < 0) goto label1; /* Line 505, Address: 0x102358c */
    --beamwk->mstno.b.h; /* Line 506, Address: 0x10235a8 */
  }
  beamwk->yposi.w.h = cal_yposi; /* Line 508, Address: 0x10235b8 */
  patchg(beamwk, beamchg); /* Line 509, Address: 0x10235c0 */
  beam_coli0(beamwk); /* Line 510, Address: 0x10235d4 */
  return; /* Line 511, Address: 0x10235e0 */
label1:
  if (beamwk->actfree[21] == 0) { /* Line 513, Address: 0x10235e8 */
    parent = &((sprite_status**)beamwk)[12]; /* Line 514, Address: 0x10235fc */
    new_actwk = *parent; /* Line 515, Address: 0x1023604 */
    new_actwk->actfree[0] = 1; /* Line 516, Address: 0x1023608 */
  }
  frameout(beamwk); /* Line 518, Address: 0x1023610 */
} /* Line 519, Address: 0x102361c */


static void beam_move2(sprite_status* beamwk) { /* Line 522, Address: 0x1023640 */
  if (beamwk->actfree[0]) { frameout(beamwk); return; } /* Line 523, Address: 0x102364c */
  patchg(beamwk, beamchg); /* Line 524, Address: 0x1023670 */
} /* Line 525, Address: 0x1023684 */



static void beam_coli0(sprite_status* beamwk) { /* Line 529, Address: 0x10236a0 */
  if (actwk[0].mstno.b.h != 43) { /* Line 530, Address: 0x10236ac */
    if (beamwk->userflag.b.h == 0) { /* Line 531, Address: 0x10236c8 */
      if (chibi_flag == 0) beam_coli(beamwk); /* Line 532, Address: 0x10236e0 */
    } /* Line 533, Address: 0x1023700 */
    else if (chibi_flag != 0) beam_coli(beamwk); /* Line 534, Address: 0x1023708 */
  }
} /* Line 536, Address: 0x1023728 */


static void beam_coli(sprite_status* beamwk) { /* Line 539, Address: 0x1023740 */
  short cal_size, cal_posi, cal_tbl;
  char tbl[8] = { -12, -28, -44, -60, -76, -92, -108, -124 }; /* Line 541, Address: 0x1023754 */

  if (editmode.b.h) return; /* Line 543, Address: 0x1023788 */
  cal_size = (char)actwk[0].sprhs + 4; /* Line 544, Address: 0x1023798 */
  cal_posi = beamwk->xposi.w.h - actwk[0].xposi.w.h + cal_size; /* Line 545, Address: 0x10237c4 */
  if (cal_posi < 0 || cal_posi >= cal_size * 2) return; /* Line 546, Address: 0x1023804 */
  cal_size = (char)actwk[0].sprvsize; /* Line 547, Address: 0x102383c */
  cal_posi = actwk[0].yposi.w.h + cal_size; /* Line 548, Address: 0x102385c */
  cal_tbl = tbl[beamwk->mstno.b.h]; /* Line 549, Address: 0x1023888 */
  cal_tbl += beamwk->yposi.w.h; /* Line 550, Address: 0x10238b0 */
  if (cal_tbl >= cal_posi) return; /* Line 551, Address: 0x10238c4 */
  cal_posi = actwk[0].yposi.w.h - cal_size; /* Line 552, Address: 0x10238e0 */
  cal_tbl = beamwk->yposi.w.h + 4; /* Line 553, Address: 0x102390c */
  if (cal_posi >= cal_tbl) return; /* Line 554, Address: 0x1023930 */

  actwk[0].r_no0 = 4; /* Line 556, Address: 0x102394c */
  actwk[0].cddat |= 2; /* Line 557, Address: 0x1023958 */
  actwk[0].yspeed.w = -1024; /* Line 558, Address: 0x102396c */
  actwk[0].xspeed.w = -512; /* Line 559, Address: 0x1023978 */
  if (actwk[0].xposi.w.h >= beamwk->xposi.w.h) /* Line 560, Address: 0x1023984 */
    actwk[0].xspeed.w = -actwk[0].xspeed.w; /* Line 561, Address: 0x10239b0 */
  actwk[0].mspeed.w = 0; /* Line 562, Address: 0x10239d4 */
  actwk[0].mstno.b.h = 56; /* Line 563, Address: 0x10239dc */
  actwk[0].sprvsize = 10; /* Line 564, Address: 0x10239e8 */
  actwk[0].sprhs = 5; /* Line 565, Address: 0x10239f4 */
  chibi_flag ^= 1; /* Line 566, Address: 0x1023a00 */
  if (chibi_flag == 0) { /* Line 567, Address: 0x1023a14 */
    actwk[0].sprvsize = 19; /* Line 568, Address: 0x1023a28 */
    actwk[0].sprhs = 9; /* Line 569, Address: 0x1023a34 */
  }
} /* Line 571, Address: 0x1023a40 */
