#include "..\EQU.H"
#include "SHOOT6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\IO.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"
#include "COLI6.H"

static void m_init(sprite_status* megamiwk); static void m_move0(sprite_status* megamiwk); static void m_move1(sprite_status* megamiwk); static void m_move2(sprite_status* megamiwk); static void ring_set(sprite_status* megamiwk);
static void gas_init(sprite_status* gaswk); static void gas_move0(sprite_status* gaswk); static void gas_move1(sprite_status* gaswk); static void gas_move2(sprite_status* gaswk); static void gas_move3(sprite_status* gaswk); static void gas_move4(sprite_status* gaswk); static void gas_move5(sprite_status* gaswk); static short gas_coli_colig(sprite_status* gaswk, sprite_status* plwk);
static void cata_init(sprite_status* catawk); static void cata_wait(sprite_status* catawk); static void cata_move0(sprite_status* catawk); static void cata_move1(sprite_status* catawk); static void cata_move2(sprite_status* catawk);
static void shooterinit(sprite_status* shootwk); static void shootermove(sprite_status* shootwk); static void shootermove2(sprite_status* shootwk); static void shootermove3(sprite_status* shootwk);

extern sprite_pattern* ringpat[9]; static short stackpointer; extern sprite_pattern* bariapat[13];

void megami(sprite_status* megamiwk) { /* Line 19, Address: 0x101cec0 */
  void(*tbl[4])(sprite_status*) = { &m_init, &m_move0, &m_move1, &m_move2 }; /* Line 20, Address: 0x101cecc */

  tbl[megamiwk->r_no0 / 2](megamiwk); /* Line 22, Address: 0x101cef8 */
  frameout_s(megamiwk); /* Line 23, Address: 0x101cf34 */
} /* Line 24, Address: 0x101cf40 */



static void m_init(sprite_status* megamiwk) { /* Line 28, Address: 0x101cf50 */
  megamiwk->r_no0 += 2; /* Line 29, Address: 0x101cf5c */
  megamiwk->actflg |= 4; /* Line 30, Address: 0x101cf6c */
  megamiwk->actfree[1] = 50; /* Line 31, Address: 0x101cf7c */
  m_move0(megamiwk); /* Line 32, Address: 0x101cf88 */
} /* Line 33, Address: 0x101cf94 */


static void m_move0(sprite_status* megamiwk) { /* Line 36, Address: 0x101cfb0 */
  short cal_position;

  cal_position = actwk[0].xposi.w.h - megamiwk->xposi.w.h + 16; /* Line 39, Address: 0x101cfbc */
  if (cal_position < 0 || cal_position >= 32) return; /* Line 40, Address: 0x101cff4 */
  cal_position = actwk[0].yposi.w.h - megamiwk->yposi.w.h + 32; /* Line 41, Address: 0x101d020 */
  if (cal_position < 0 || cal_position >= 64) return; /* Line 42, Address: 0x101d058 */

  megamiwk->r_no0 += 2; /* Line 44, Address: 0x101d084 */
} /* Line 45, Address: 0x101d094 */


static void m_move1(sprite_status* megamiwk) { /* Line 48, Address: 0x101d0b0 */
  if ((char)--megamiwk->actfree[0] >= 0) return; /* Line 49, Address: 0x101d0bc */
  megamiwk->actfree[0] = 10; /* Line 50, Address: 0x101d0e8 */
  if ((char)--megamiwk->actfree[1] >= 0) /* Line 51, Address: 0x101d0f4 */
    ring_set(megamiwk); /* Line 52, Address: 0x101d120 */
  else megamiwk->r_no0 += 2; /* Line 53, Address: 0x101d134 */
} /* Line 54, Address: 0x101d144 */


static void m_move2(sprite_status* megamiwk) { /* Line 57, Address: 0x101d160 */
  megamiwk->actno = megamiwk->actno; /* Line 58, Address: 0x101d168 */
} /* Line 59, Address: 0x101d178 */


static void ring_set(sprite_status* megamiwk) { /* Line 62, Address: 0x101d190 */
  short random_data;
  sprite_status* new_actwk;
  short tbl[8] = { -256, -128, 0, 128, 256, 384, 512, 640 }; /* Line 65, Address: 0x101d1a0 */

  if (actwkchk(&new_actwk) != 0) return; /* Line 67, Address: 0x101d1d4 */
  new_actwk->actno = 17; /* Line 68, Address: 0x101d1e8 */
  new_actwk->r_no0 += 2; /* Line 69, Address: 0x101d1f4 */
  new_actwk->mstno.b.h = 2; /* Line 70, Address: 0x101d204 */
  new_actwk->sprvsize = new_actwk->sprhs = 8; /* Line 71, Address: 0x101d210 */
  new_actwk->xposi.w.h = megamiwk->xposi.w.h + 24; /* Line 72, Address: 0x101d228 */
  new_actwk->yposi.w.h = megamiwk->yposi.w.h - 16; /* Line 73, Address: 0x101d24c */
  new_actwk->patbase = ringpat; /* Line 74, Address: 0x101d270 */
  new_actwk->sproffset = 32768; /* Line 75, Address: 0x101d280 */
  new_actwk->sprpri = 3; /* Line 76, Address: 0x101d28c */
  new_actwk->actflg = 4; /* Line 77, Address: 0x101d298 */
  new_actwk->colino = 71; /* Line 78, Address: 0x101d2a4 */
  new_actwk->sprhsize = new_actwk->sprvsize = 8; /* Line 79, Address: 0x101d2b0 */
  sys_pattim4 = 255; /* Line 80, Address: 0x101d2c8 */
  new_actwk->yspeed.w = -512; /* Line 81, Address: 0x101d2d4 */
  random_data = random() & 7; /* Line 82, Address: 0x101d2e0 */
  new_actwk->xspeed.w = tbl[random_data]; /* Line 83, Address: 0x101d2fc */
} /* Line 84, Address: 0x101d318 */








static unsigned char gaschg0[7] = { 1, 3, 7, 6, 7, 253, 1 };
static unsigned char gaschg1[90] = {
  1, 2, 7, 4, 7, 5, 7, 1, 7, 2,
  7, 4, 7, 5, 7, 1, 7, 2, 7, 4,
  7, 5, 7, 1, 7, 2, 7, 4, 7, 5,
  7, 1, 7, 2, 7, 4, 7, 5, 7, 1,
  7, 2, 7, 4, 7, 5, 7, 1, 7, 2,
  7, 4, 7, 5, 7, 1, 7, 2, 7, 4,
  7, 5, 7, 1, 7, 2, 7, 4, 7, 5,
  7, 1, 7, 2, 7, 4, 7, 5, 7, 1,
  7, 2, 7, 7, 4, 7, 7, 5, 253, 2
};
static unsigned char gaschg2[19] = {
  7, 7, 7, 2, 7, 7, 7, 5, 7, 7,
  7, 7, 2, 7, 7, 7, 7, 5, 252
};
static unsigned char* gaschg[3] = { gaschg0, gaschg1, gaschg2 };
static sprite_pattern gas00 = { 1, { { -32, -8, 0, 288 } } };
static sprite_pattern gas01 = { 1, { { -16, -32, 0, 289 } } };
static sprite_pattern gas02 = { 1, { { -16, -40, 0, 289 } } };
static sprite_pattern gas03 = { 1, { { -16, -32, 0, 290 } } };
static sprite_pattern gas04 = { 1, { { -16, -32, 0, 291 } } };
static sprite_pattern gas05 = { 1, { { -16, -40, 0, 291 } } };
static sprite_pattern gas06 = { 1, { { -16, -32, 0, 292 } } };
static sprite_pattern gas07 = { 1, { { -16, -20, 0, 0 } } };
static sprite_pattern ice00 = { 1, { { -24, -24, 0, 293 } } };
static sprite_pattern ice01 = { 1, { { -8, -12, 0, 294 } } };
static sprite_pattern ice02 = { 1, { { -8, -8, 0, 295 } } };
static sprite_pattern ice03 = { 1, { { -4, -4, 0, 296 } } };
sprite_pattern* gaspat[12] = { &gas00, &gas01, &gas02, &gas03, &gas04, &gas05, &gas06, &gas07, &ice00, &ice01, &ice02, &ice03 };

void gas(sprite_status* gaswk) { /* Line 124, Address: 0x101d330 */
  void(*tbl[7])(sprite_status*) = { /* Line 125, Address: 0x101d33c */
    &gas_init,
    &gas_move0,
    &gas_move1,
    &gas_move2,
    &gas_move3,
    &gas_move4,
    &gas_move5
  };
  tbl[gaswk->r_no0 / 2](gaswk); /* Line 134, Address: 0x101d368 */
  actionsub(gaswk); /* Line 135, Address: 0x101d3a4 */
  frameout_s(gaswk); /* Line 136, Address: 0x101d3b0 */
} /* Line 137, Address: 0x101d3bc */


static void gas_init(sprite_status* gaswk) { /* Line 140, Address: 0x101d3d0 */
  gaswk->actflg |= 4; /* Line 141, Address: 0x101d3dc */

  gaswk->patbase = gaspat; /* Line 143, Address: 0x101d3ec */
  gaswk->actfree[0] = 120; /* Line 144, Address: 0x101d3fc */
  gaswk->r_no0 += 2; /* Line 145, Address: 0x101d408 */
  gas_move0(gaswk); /* Line 146, Address: 0x101d418 */
} /* Line 147, Address: 0x101d424 */


static void gas_move0(sprite_status* gaswk) { /* Line 150, Address: 0x101d440 */
  sprite_status *new_actwk, **parent;

  if (gaswk->actfree[0] == 0) return; /* Line 153, Address: 0x101d450 */
  if (--gaswk->actfree[0] != 0) return; /* Line 154, Address: 0x101d464 */
  if (actwkchk(&new_actwk) != 0) return; /* Line 155, Address: 0x101d484 */
  parent = &((sprite_status**)new_actwk)[12]; /* Line 156, Address: 0x101d498 */

  *parent = gaswk; /* Line 158, Address: 0x101d4a0 */
  new_actwk->actno = 5; /* Line 159, Address: 0x101d4a8 */
  new_actwk->sprpri = 3; /* Line 160, Address: 0x101d4b4 */
  new_actwk->actflg |= 4; /* Line 161, Address: 0x101d4c0 */
  new_actwk->sproffset = gaswk->sproffset; /* Line 162, Address: 0x101d4d0 */
  new_actwk->patbase = gaswk->patbase; /* Line 163, Address: 0x101d4e0 */
  new_actwk->xposi.w.h = gaswk->xposi.w.h; /* Line 164, Address: 0x101d4f0 */
  new_actwk->yposi.w.h = gaswk->yposi.w.h + 36; /* Line 165, Address: 0x101d500 */
  new_actwk->r_no0 = 4; /* Line 166, Address: 0x101d524 */
} /* Line 167, Address: 0x101d530 */


static void gas_move1(sprite_status* gaswk) { /* Line 170, Address: 0x101d550 */
  gas_coli(gaswk); /* Line 171, Address: 0x101d55c */
  patchg(gaswk, gaschg); /* Line 172, Address: 0x101d568 */
} /* Line 173, Address: 0x101d57c */


static void gas_move2(sprite_status* gaswk) { /* Line 176, Address: 0x101d590 */
  sprite_status **parent, *new_actwk;

  parent = &((sprite_status**)gaswk)[12]; /* Line 179, Address: 0x101d5a4 */
  new_actwk = *parent; /* Line 180, Address: 0x101d5ac */
  new_actwk->actfree[0] = 120; /* Line 181, Address: 0x101d5b0 */
  frameout(gaswk); /* Line 182, Address: 0x101d5b8 */
} /* Line 183, Address: 0x101d5c4 */


static void gas_move3(sprite_status* gaswk) { /* Line 186, Address: 0x101d5e0 */
  short collision_data;
  sprite_status **parent, *new_actwk;

  gaswk->yspeed.w += 56; /* Line 190, Address: 0x101d5f8 */
  gaswk->yposi.l += gaswk->yspeed.w << 8; /* Line 191, Address: 0x101d608 */
  if ((collision_data = emycol_d(gaswk)) < 0) { /* Line 192, Address: 0x101d62c */
    sub_sync(146); /* Line 193, Address: 0x101d658 */
    gaswk->actfree[6] = 15; /* Line 194, Address: 0x101d664 */
    gaswk->yposi.w.h += collision_data; /* Line 195, Address: 0x101d670 */
    gaswk->r_no0 += 2; /* Line 196, Address: 0x101d680 */
  }
  parent = &((sprite_status**)gaswk)[12]; /* Line 198, Address: 0x101d690 */
  new_actwk = *parent; /* Line 199, Address: 0x101d698 */
  new_actwk->yposi.l = gaswk->yposi.l; /* Line 200, Address: 0x101d69c */
} /* Line 201, Address: 0x101d6a8 */


static void gas_move4(sprite_status* gaswk) { /* Line 204, Address: 0x101d6d0 */
  sprite_status **parent, *new_actwk;

  parent = &((sprite_status**)gaswk)[12]; /* Line 207, Address: 0x101d6e4 */
  new_actwk = *parent; /* Line 208, Address: 0x101d6ec */
  if (gaswk->actfree[6] != 0) { /* Line 209, Address: 0x101d6f0 */
    --gaswk->actfree[6]; /* Line 210, Address: 0x101d704 */
    if (!(swdata.b.l & 112)) return; /* Line 211, Address: 0x101d714 */
    new_actwk->actfree[2] &= 190; /* Line 212, Address: 0x101d72c */
    new_actwk->yspeed.w = -1664; /* Line 213, Address: 0x101d738 */
    new_actwk->sprvsize = 14; /* Line 214, Address: 0x101d740 */
    new_actwk->sprhs = 7; /* Line 215, Address: 0x101d748 */
    new_actwk->yposi.w.h += 5; /* Line 216, Address: 0x101d750 */
    new_actwk->cddat |= 4; /* Line 217, Address: 0x101d75c */
    new_actwk->cddat &= 223; /* Line 218, Address: 0x101d768 */
    new_actwk->mstno.b.h = 2; /* Line 219, Address: 0x101d774 */
    soundset(146); /* Line 220, Address: 0x101d77c */
  } /* Line 221, Address: 0x101d788 */
  else {
    new_actwk->actfree[2] &= 190; /* Line 223, Address: 0x101d790 */
    playdamageset(new_actwk, gaswk); /* Line 224, Address: 0x101d79c */
  }
  gaswk->r_no0 += 2; /* Line 226, Address: 0x101d7ac */
  gaswk->patno = 10; /* Line 227, Address: 0x101d7bc */
  gaswk->actfree[6] = 20; /* Line 228, Address: 0x101d7c8 */
  gaswk->actfree[7] = 2; /* Line 229, Address: 0x101d7d4 */
  ice_sub_set(gaswk); /* Line 230, Address: 0x101d7e0 */

} /* Line 232, Address: 0x101d7ec */

static char tbl0[32] = {
   0,  0, 10, 11,  0,  0, -1,  0,
   0,  0, 10, 11,  0,  1,  0,  0,
   0,  0, 10, 11,  0,  0,  1,  0,
   0,  0, 10, 11,  0, -1,  0,  0
};
static char tbl1[32] = {
   0,  0, 10, 11,  0, -1, -1,  0,
   0,  0, 10, 11,  0,  1, -1,  0,
   0,  0, 10, 11,  0,  0,  1,  0,
   0,  0,  1, 11,  0, -1,  0,  0
};
static char tbl2[32] = {
   0,  0, 10, 11,  0, -1, -1,  0,
   0,  0, 10, 11,  0,  1, -1,  0,
   0,  0, 10, 11,  0,  1,  1,  0,
   0,  0, 10, 11,  0, -1,  1,  0
};

static void gas_move5(sprite_status* gaswk) { /* Line 253, Address: 0x101d810 */
  char* tbl[3] = { tbl0, tbl1, tbl2 }; /* Line 254, Address: 0x101d81c */

  if (--gaswk->actfree[6] == 0) { /* Line 256, Address: 0x101d840 */
    if (gaswk->patno == 11) { frameout(gaswk); return; } /* Line 257, Address: 0x101d860 */
    ice_sub0(gaswk, tbl[gaswk->actfree[7]], 3); /* Line 258, Address: 0x101d88c */
    frameout(gaswk); /* Line 259, Address: 0x101d8b4 */
    return; /* Line 260, Address: 0x101d8c0 */
  }
  gaswk->xposi.w.h += gaswk->xspeed.w; /* Line 262, Address: 0x101d8c8 */
  gaswk->yposi.w.h += gaswk->yspeed.w; /* Line 263, Address: 0x101d8e0 */
} /* Line 264, Address: 0x101d8f8 */


static char ice_tbl0[48] = {
  -16, -12,  10,   9,   0,  -1,  -1,   0,
  -16,  12,  10,   9,   2,  -1,   1,   0,
   16, -12,  10,   9,   1,   1,  -1,   0,
   16,  12,  10,   9,   3,   1,   1,   0,
    0, -16,  15,  10,   1,   0,  -1,   1,
    0,  16,  15,  10,   3,   0,   1,   1
};

void ice_sub_set(sprite_status* gaswk) { /* Line 276, Address: 0x101d910 */
  ice_sub0(gaswk, ice_tbl0, 5); /* Line 277, Address: 0x101d91c */
} /* Line 278, Address: 0x101d934 */


void ice_sub0(sprite_status* gaswk, char* tbl, short loop) { /* Line 281, Address: 0x101d950 */
  short i, index;
  sprite_status* new_actwk;

  index = 0; /* Line 285, Address: 0x101d96c */
  for (i = 0; i <= loop; ++i) { /* Line 286, Address: 0x101d970 */
    if (actwkchk(&new_actwk) != 0) break; /* Line 287, Address: 0x101d97c */
    new_actwk->actno = 5; /* Line 288, Address: 0x101d990 */
    new_actwk->r_no0 = 12; /* Line 289, Address: 0x101d99c */
    new_actwk->actflg |= 4; /* Line 290, Address: 0x101d9a8 */
    new_actwk->xposi.w.h = gaswk->xposi.w.h; /* Line 291, Address: 0x101d9b8 */
    new_actwk->yposi.w.h = gaswk->yposi.w.h; /* Line 292, Address: 0x101d9c8 */

    new_actwk->patbase = gaspat; /* Line 294, Address: 0x101d9d8 */
    new_actwk->xposi.w.h += tbl[index]; /* Line 295, Address: 0x101d9e8 */
    new_actwk->yposi.w.h += tbl[index + 1]; /* Line 296, Address: 0x101da14 */
    new_actwk->actfree[6] = tbl[index + 2]; /* Line 297, Address: 0x101da44 */
    new_actwk->patno = tbl[index + 3]; /* Line 298, Address: 0x101da64 */
    new_actwk->actflg |= tbl[index + 4]; /* Line 299, Address: 0x101da84 */
    new_actwk->xspeed.w = tbl[index + 5]; /* Line 300, Address: 0x101dab0 */
    new_actwk->yspeed.w = tbl[index + 6]; /* Line 301, Address: 0x101dad8 */
    new_actwk->actfree[7] = tbl[index + 7]; /* Line 302, Address: 0x101db00 */
    index += 8; /* Line 303, Address: 0x101db20 */
  } /* Line 304, Address: 0x101db2c */
} /* Line 305, Address: 0x101db58 */



void ice_set(sprite_status* plwk) { /* Line 309, Address: 0x101db70 */
  sprite_status *new_actwk, **parent;

  if (actwkchk(&new_actwk) != 0) return; /* Line 312, Address: 0x101db80 */
  plwk->actfree[2] |= 65; /* Line 313, Address: 0x101db94 */
  parent = &((sprite_status**)new_actwk)[12]; /* Line 314, Address: 0x101dba4 */
  *parent = plwk; /* Line 315, Address: 0x101dbac */
  new_actwk->actno = 5; /* Line 316, Address: 0x101dbb4 */
  new_actwk->actflg |= 4; /* Line 317, Address: 0x101dbc0 */
  new_actwk->xposi.w.h = plwk->xposi.w.h; /* Line 318, Address: 0x101dbd0 */
  new_actwk->yposi.w.h = plwk->yposi.w.h; /* Line 319, Address: 0x101dbe0 */

  new_actwk->patbase = gaspat; /* Line 321, Address: 0x101dbf0 */
  new_actwk->sprhs = new_actwk->sprhsize = new_actwk->sprvsize = 24; /* Line 322, Address: 0x101dc00 */
  new_actwk->patno = 8; /* Line 323, Address: 0x101dc24 */
  new_actwk->r_no0 = 8; /* Line 324, Address: 0x101dc30 */
} /* Line 325, Address: 0x101dc3c */



void gas_coli(sprite_status* gaswk) { /* Line 329, Address: 0x101dc50 */
  if (gaswk->mstno.b.h != 1) return; /* Line 330, Address: 0x101dc5c */
  if (actwk[0].mstno.b.h == 43) return; /* Line 331, Address: 0x101dc78 */
  if (gas_coli_colig(gaswk, &actwk[0])) ice_set(&actwk[0]); /* Line 332, Address: 0x101dc94 */
} /* Line 333, Address: 0x101dcc0 */


static short gas_coli_colig(sprite_status* gaswk, sprite_status* plwk) { /* Line 336, Address: 0x101dcd0 */
  short cal_posi, cal_size;

  if (plpower_m) return 0; /* Line 339, Address: 0x101dce4 */
  if (plpower_a) return 0; /* Line 340, Address: 0x101dd00 */
  if (plwk->r_no0 >= 4) return 0; /* Line 341, Address: 0x101dd1c */
  if (plwk->actfree[2]) return 0; /* Line 342, Address: 0x101dd40 */
  cal_posi = plwk->xposi.w.h - gaswk->xposi.w.h + (cal_size = (short)plwk->sprhs + 16); /* Line 343, Address: 0x101dd5c */

  if (cal_posi < 0 || cal_posi >= cal_size * 2) return 0; /* Line 345, Address: 0x101ddcc */
  cal_posi = plwk->yposi.w.h - gaswk->yposi.w.h + (cal_size = (short)plwk->sprvsize + 32); /* Line 346, Address: 0x101de08 */

  if (cal_posi < 0 || cal_posi >= cal_size * 2) return 0; /* Line 348, Address: 0x101de78 */
  return 1; /* Line 349, Address: 0x101deb4 */
} /* Line 350, Address: 0x101deb8 */




static sprite_pattern cata00 = { 1, { { -28, -28, 0, 297 } } };
static sprite_pattern cata01 = { 1, { { -16, -20, 0, 0 } } };
sprite_pattern* cata_pat[2] = { &cata00, &cata01 };

void catapalt(sprite_status* catawk) { /* Line 359, Address: 0x101ded0 */
  void(*tbl[5])(sprite_status*) = { &cata_init, &cata_wait, &cata_move0, &cata_move1, &cata_move2 }; /* Line 360, Address: 0x101dedc */


  tbl[catawk->r_no0 / 2](catawk); /* Line 363, Address: 0x101df08 */
  actionsub(catawk); /* Line 364, Address: 0x101df44 */
  frameout_s(catawk); /* Line 365, Address: 0x101df50 */
} /* Line 366, Address: 0x101df5c */



static void cata_init(sprite_status* catawk) { /* Line 370, Address: 0x101df70 */
  sprite_status *new_actwk, **parent;

  catawk->actflg |= 4; /* Line 373, Address: 0x101df80 */

  catawk->patbase = cata_pat; /* Line 375, Address: 0x101df90 */
  ((short*)catawk)[25] = catawk->xposi.w.h; /* Line 376, Address: 0x101dfa0 */
  catawk->sprhs = catawk->sprhsize = 28; /* Line 377, Address: 0x101dfb0 */
  catawk->sprvsize = 4; /* Line 378, Address: 0x101dfc8 */
  catawk->r_no0 += 2; /* Line 379, Address: 0x101dfd4 */
  if (actwkchk2(catawk, &new_actwk) != 0) return; /* Line 380, Address: 0x101dfe4 */
  new_actwk->actno = 4; /* Line 381, Address: 0x101dffc */
  new_actwk->actflg |= 4; /* Line 382, Address: 0x101e008 */

  new_actwk->patbase = cata_pat; /* Line 384, Address: 0x101e018 */
  new_actwk->sprhs = 4; /* Line 385, Address: 0x101e028 */
  new_actwk->sprvsize = 12; /* Line 386, Address: 0x101e034 */
  new_actwk->patno = 1; /* Line 387, Address: 0x101e040 */
  parent = &((sprite_status**)new_actwk)[12]; /* Line 388, Address: 0x101e04c */
  *parent = catawk; /* Line 389, Address: 0x101e054 */
  new_actwk->r_no0 = 8; /* Line 390, Address: 0x101e05c */
  cata_wait(catawk); /* Line 391, Address: 0x101e068 */
} /* Line 392, Address: 0x101e074 */


static void cata_wait(sprite_status* catawk) { /* Line 395, Address: 0x101e090 */
  if (ridechk(catawk, &actwk[0]) == 0) return; /* Line 396, Address: 0x101e09c */
  actwk[0].actfree[2] |= 1; /* Line 397, Address: 0x101e0c0 */
  actwk[0].xposi.w.h = catawk->xposi.w.h; /* Line 398, Address: 0x101e0d4 */
  actwk[0].cddat &= 254; /* Line 399, Address: 0x101e0e4 */
  actwk[0].mstno.b.h = 58; /* Line 400, Address: 0x101e0f8 */
  catawk->r_no0 += 2; /* Line 401, Address: 0x101e104 */
  catawk->xspeed.w = 3072; /* Line 402, Address: 0x101e114 */
} /* Line 403, Address: 0x101e120 */


static void cata_move0(sprite_status* catawk) { /* Line 406, Address: 0x101e130 */
  short cal_position;

  catawk->xposi.l += catawk->xspeed.w << 8; /* Line 409, Address: 0x101e140 */
  ridechk(catawk, &actwk[0]); /* Line 410, Address: 0x101e164 */
  if ((swdata1.b.h & 112) && (actwk[0].actfree[2] & 1)) { /* Line 411, Address: 0x101e178 */


    actwk[0].actfree[2] &= 254; /* Line 414, Address: 0x101e1a8 */

    actwk[0].yspeed.w = -1664; /* Line 416, Address: 0x101e1bc */
    actwk[0].xspeed.w = catawk->xspeed.w; /* Line 417, Address: 0x101e1c8 */
    actwk[0].sprvsize = 14; /* Line 418, Address: 0x101e1d8 */
    actwk[0].sprhs = 7; /* Line 419, Address: 0x101e1e4 */
    actwk[0].yposi.w.h += 5; /* Line 420, Address: 0x101e1f0 */
    actwk[0].cddat |= 4; /* Line 421, Address: 0x101e204 */
    actwk[0].cddat |= 2; /* Line 422, Address: 0x101e218 */

    actwk[0].cddat &= 223; /* Line 424, Address: 0x101e22c */
    actwk[0].mstno.b.h = 2; /* Line 425, Address: 0x101e240 */
    soundset(146); /* Line 426, Address: 0x101e24c */
  }
  cal_position = ((short*)catawk)[25] + 912; /* Line 428, Address: 0x101e258 */
  if (cal_position >= catawk->xposi.w.h) return; /* Line 429, Address: 0x101e27c */
  catawk->xposi.w.h = cal_position; /* Line 430, Address: 0x101e2a0 */
  catawk->r_no0 += 2; /* Line 431, Address: 0x101e2a8 */
  if (!(catawk->cddat & 8)) return; /* Line 432, Address: 0x101e2b8 */
  actwk[0].actfree[2] &= 254; /* Line 433, Address: 0x101e2d0 */
  actwk[0].xspeed.w = catawk->xspeed.w; /* Line 434, Address: 0x101e2e4 */
  actwk[0].mstno.b.h = 0; /* Line 435, Address: 0x101e2f4 */
  actwk[0].cddat |= 2; /* Line 436, Address: 0x101e2fc */
  actwk[0].cddat &= 247; /* Line 437, Address: 0x101e310 */
} /* Line 438, Address: 0x101e324 */


static void cata_move1(sprite_status* catawk) { /* Line 441, Address: 0x101e340 */
  short cal_position;

  catawk->xposi.w.h -= 4; /* Line 444, Address: 0x101e34c */
  cal_position = ((short*)catawk)[25]; /* Line 445, Address: 0x101e35c */
  if (cal_position < catawk->xposi.w.h) return; /* Line 446, Address: 0x101e36c */
  catawk->xposi.w.h = cal_position; /* Line 447, Address: 0x101e390 */
  catawk->r_no0 = 2; /* Line 448, Address: 0x101e398 */
} /* Line 449, Address: 0x101e3a4 */


static void cata_move2(sprite_status* catawk) { /* Line 452, Address: 0x101e3c0 */
  sprite_status *new_actwk, **parent;

  parent = &((sprite_status**)catawk)[12]; /* Line 455, Address: 0x101e3d4 */
  new_actwk = *parent; /* Line 456, Address: 0x101e3dc */
  if (new_actwk->r_no0 >= 4) return; /* Line 457, Address: 0x101e3e0 */
  catawk->xposi.w.h = new_actwk->xposi.w.h - 24; /* Line 458, Address: 0x101e3f4 */
  catawk->yposi.w.h = new_actwk->yposi.w.h - 16; /* Line 459, Address: 0x101e414 */
  hitchk(catawk, &actwk[0]); /* Line 460, Address: 0x101e434 */
} /* Line 461, Address: 0x101e448 */















































































































static unsigned short shooterposi_0[46] = {
  78, 0, 0, 0, 8, 32, 0, 0, 72, 0,
  65512, 96, 0, 65464, 112, 0, 65416, 96, 0, 65392,
  72, 0, 65384, 32, 0, 65392, 0, 0, 65416, 65504,
  32769, 65464, 65488, 0, 65512, 65504, 32768, 0, 0, 32768,
  80, 65504, 0, 65416, 65432, 0
};
static unsigned short shooterposi_1[16] = {
  24, 0, 0, 0, 48, 65520, 0, 96, 0, 32768,
  120, 32, 32768, 200, 0, 0
};
static unsigned short shooterposi_2[85] = {
  150, 0, 0, 0, 8, 32, 0, 0, 64, 0,
  65512, 96, 0, 65464, 112, 0, 65416, 128, 0, 65392,
  160, 0, 65384, 192, 0, 65392, 224, 32770, 65416, 256,
  32770, 65464, 272, 0, 65512, 256, 0, 0, 224, 0,
  8, 192, 0, 0, 160, 0, 65512, 128, 0, 65464,
  112, 0, 65416, 96, 0, 65392, 64, 0, 65384, 32,
  0, 65392, 0, 32769, 65416, 65504, 32769, 65464, 65488, 0,
  65512, 65504, 32768, 0, 0, 32768, 64, 65504, 0, 65320,
  65504, 0, 65352, 240, 0
};
static unsigned short shooterposi_3[22] = {
  30, 0, 0, 32769, 24, 65504, 32769, 72, 65488, 0,
  120, 65504, 32768, 144, 0, 32768, 208, 65504, 0, 65464,
  65504, 0
};
static unsigned short shooterposi_4[49] = {
  78, 0, 0, 32770, 24, 32, 32770, 72, 48, 0,
  120, 32, 0, 144, 0, 0, 152, 65504, 0, 144,
  65472, 0, 120, 65440, 0, 72, 65424, 0, 24, 65408,
  0, 0, 65376, 0, 65528, 65344, 0, 0, 65312, 32769,
  208, 65280, 0, 65464, 65280, 0, 65496, 16, 0
};
static unsigned short shooterposi_5[31] = {
  60, 0, 0, 0, 0, 336, 0, 65432, 336, 0,
  65432, 512, 0, 65528, 512, 0, 65480, 512, 0, 65480,
  808, 0, 536, 808, 0, 536, 880, 0, 960, 880,
  0
};
static unsigned short shooterposi_6[7] = { 12, 0, 0, 0, 56, 0, 0 };
static unsigned short shooterposi_7[10] = { 18, 0, 0, 0, 0, 680, 0, 80, 680, 0 };
static unsigned short shooterposi_8[13] = {
  24, 0, 0, 0, 8, 0, 0, 8, 65280, 0,
  56, 65280, 0
};
static unsigned short shooterposi_9[13] = {
  24, 0, 0, 0, 8, 0, 0, 8, 256, 0,
  56, 256, 0
};
static unsigned short shooterposi_0a[13] = {
  24, 0, 0, 0, 8, 0, 0, 8, 65280, 0,
  56, 65280, 0
};
static unsigned short shooterposi_0b[7] = { 12, 0, 0, 0, 96, 0, 0 };
static unsigned short shooterposi_0c[13] = {
  24, 0, 0, 0, 432, 0, 0, 432, 256, 0,
  992, 256, 0
};
static unsigned short shooterposi_0d[16] = {
  30, 0, 0, 0, 0, 680, 0, 960, 680, 0,
  960, 424, 0, 400, 424, 0
};
static unsigned short shooterposi_0e[7] = { 12, 0, 0, 0, 352, 0, 0 };
static unsigned short shooterposi_0f[40] = {
  78, 0, 0, 0, 0, 696, 0, 65416, 696, 0,
  65416, 872, 0, 65512, 872, 0, 65464, 952, 0, 65368,
  952, 0, 65464, 952, 0, 65464, 1016, 0, 24, 1016,
  0, 24, 1112, 0, 65480, 1112, 0, 65480, 1248, 0
};
static unsigned short shooterposi_10[22] = {
  42, 0, 0, 0, 0, 680, 0, 65416, 680, 0,
  65416, 856, 0, 65512, 856, 0, 65464, 856, 0, 65464,
  1232, 0
};
static unsigned short shooterposi_11[25] = {
  48, 0, 0, 0, 0, 520, 0, 65416, 520, 0,
  65416, 696, 0, 65512, 696, 0, 65480, 696, 0, 65480,
  792, 0, 592, 792, 0
};
static unsigned short shooterposi_12[7] = { 12, 0, 0, 0, 296, 0, 0 };
static unsigned short* shooterpositbl[19] = {
  shooterposi_0,
  shooterposi_1,
  shooterposi_2,
  shooterposi_3,
  shooterposi_4,
  shooterposi_5,
  shooterposi_6,
  shooterposi_7,
  shooterposi_8,
  shooterposi_9,
  shooterposi_0a,
  shooterposi_0b,
  shooterposi_0c,
  shooterposi_0d,
  shooterposi_0e,
  shooterposi_0f,
  shooterposi_10,
  shooterposi_11,
  shooterposi_12
};

void shooter(sprite_status* shootwk) { /* Line 676, Address: 0x101e460 */
  short flag_no, addition;

  if (!(time_flag & 128)) goto label1; /* Line 679, Address: 0x101e474 */
  if ((flag_no = shootwk->cdsts) == 0) goto label1; /* Line 680, Address: 0x101e48c */
  flag_no *= 3; /* Line 681, Address: 0x101e4b8 */
  addition = (short)(time_flag & 127) - (short)time_item; /* Line 682, Address: 0x101e4c8 */
  if (addition < 0) addition = 0; /* Line 683, Address: 0x101e514 */
  else if (addition >= 3) addition = 2; /* Line 684, Address: 0x101e530 */
  flagwork[flag_no + addition] &= 127; /* Line 685, Address: 0x101e550 */
label1:
  if (actwk[0].mstno.b.h == 43) return; /* Line 687, Address: 0x101e57c */
  if (actwk[0].r_no0 >= 6) return; /* Line 688, Address: 0x101e598 */
  stackpointer = 0; /* Line 689, Address: 0x101e5b0 */
  switch (shootwk->r_no0) { /* Line 690, Address: 0x101e5b8 */
    case 0:
      shooterinit(shootwk); /* Line 692, Address: 0x101e5f8 */
      break; /* Line 693, Address: 0x101e604 */
    case 2:
      shootermove(shootwk); /* Line 695, Address: 0x101e60c */
      break; /* Line 696, Address: 0x101e618 */
    case 4:
      shootermove2(shootwk); /* Line 698, Address: 0x101e620 */
      break; /* Line 699, Address: 0x101e62c */
    case 6:
      shootermove3(shootwk); /* Line 701, Address: 0x101e634 */
      break;
  }


  (int)stackpointer; /* Line 706, Address: 0x101e640 */

} /* Line 708, Address: 0x101e650 */


static void shooterinit(sprite_status* shootwk) { /* Line 711, Address: 0x101e670 */
  unsigned short** move;
  unsigned short* movetbl;

  shootwk->patbase = bariapat; /* Line 715, Address: 0x101e684 */
  shootwk->actflg = 4; /* Line 716, Address: 0x101e694 */
  shootwk->sprpri = 1; /* Line 717, Address: 0x101e6a0 */
  shootwk->sprhsize = 16; /* Line 718, Address: 0x101e6ac */


  shootwk->r_no0 += 2; /* Line 721, Address: 0x101e6b8 */
  movetbl = shooterpositbl[shootwk->userflag.b.h & 127]; /* Line 722, Address: 0x101e6c8 */
  shootwk->actfree[16] = movetbl[0] >> 8; /* Line 723, Address: 0x101e6f0 */
  shootwk->actfree[17] = movetbl[0] & 255; /* Line 724, Address: 0x101e708 */
  move = &((unsigned short**)shootwk)[16]; /* Line 725, Address: 0x101e720 */
  *move = movetbl + 1; /* Line 726, Address: 0x101e728 */
  ((unsigned short*)shootwk)[29] = movetbl[1]; /* Line 727, Address: 0x101e730 */
  ((unsigned short*)shootwk)[30] = movetbl[2]; /* Line 728, Address: 0x101e73c */
  shootermove(shootwk); /* Line 729, Address: 0x101e748 */
} /* Line 730, Address: 0x101e754 */


static void shootermove(sprite_status* shootwk) { /* Line 733, Address: 0x101e770 */
  short cal_position;

  if (actwk[0].r_no0 >= 6) return; /* Line 736, Address: 0x101e780 */
  cal_position = actwk[0].xposi.w.h - shootwk->xposi.w.h + 32; /* Line 737, Address: 0x101e798 */
  if (cal_position >= 64 || cal_position < 0) return; /* Line 738, Address: 0x101e7d0 */
  cal_position = actwk[0].yposi.w.h - shootwk->yposi.w.h + 48; /* Line 739, Address: 0x101e7fc */
  if (cal_position >= 96 || cal_position < 0) return; /* Line 740, Address: 0x101e834 */
  if (actwk[0].actfree[2] != 0) return; /* Line 741, Address: 0x101e860 */
  if (actwk[0].r_no0 == 4) { /* Line 742, Address: 0x101e874 */
    actwk[0].r_no0 -= 2; /* Line 743, Address: 0x101e88c */
    ((short*)&actwk[0])[26] = 120; /* Line 744, Address: 0x101e8a0 */
  }
  shootwk->r_no0 += 2; /* Line 746, Address: 0x101e8ac */
  actwk[0].actfree[2] = 129; /* Line 747, Address: 0x101e8bc */
  if (shootwk->userflag.b.l != 0) actwk[0].actfree[2] |= 64; /* Line 748, Address: 0x101e8c8 */
  actwk[0].mstno.b.h = 2; /* Line 749, Address: 0x101e8f4 */
  actwk[0].mspeed.w = 2048; /* Line 750, Address: 0x101e900 */
  if (shootwk->userflag.b.h >= 0) actwk[0].actflg &= 191; /* Line 751, Address: 0x101e90c */
  else actwk[0].actflg |= 64; /* Line 752, Address: 0x101e940 */
  if (actwk[0].r_no0 == 4) actwk[0].r_no0 -= 2; /* Line 753, Address: 0x101e954 */
  actwk[0].xspeed.w = actwk[0].yspeed.w = 0; /* Line 754, Address: 0x101e980 */
  shootwk->cddat &= 223; /* Line 755, Address: 0x101e998 */
  actwk[0].cddat &= 223; /* Line 756, Address: 0x101e9a8 */
  actwk[0].cddat |= 2; /* Line 757, Address: 0x101e9bc */
  actwk[0].xposi.w.h = shootwk->xposi.w.h; /* Line 758, Address: 0x101e9d0 */
  actwk[0].yposi.w.h = shootwk->yposi.w.h; /* Line 759, Address: 0x101e9e0 */
  shootwk->actfree[8] = 0; /* Line 760, Address: 0x101e9f0 */
  soundset(145); /* Line 761, Address: 0x101e9f8 */
} /* Line 762, Address: 0x101ea04 */


static void shootermove2(sprite_status* shootwk) { /* Line 765, Address: 0x101ea20 */
  actwk[0].mstno.b.h = 2; /* Line 766, Address: 0x101ea2c */
  shooterspdset(shootwk); /* Line 767, Address: 0x101ea38 */
  shootwk->r_no0 += 2; /* Line 768, Address: 0x101ea44 */
  soundset(145); /* Line 769, Address: 0x101ea54 */
} /* Line 770, Address: 0x101ea60 */


static void shootermove3(sprite_status* shootwk) { /* Line 773, Address: 0x101ea70 */
  unsigned char move_counter;
  short movetbl_data;
  unsigned short** move;
  unsigned short* movetbl;

  actwk[0].mstno.b.h = 2; /* Line 779, Address: 0x101ea8c */
  stackpointer = 4; /* Line 780, Address: 0x101ea98 */
  if ((char)--shootwk->actfree[4] < 0) { /* Line 781, Address: 0x101eaa4 */
    actwk[0].xposi.w.h = ((short*)shootwk)[29] /* Line 782, Address: 0x101ead0 */
                       + shootwk->xposi.w.h;
    actwk[0].yposi.w.h = ((short*)shootwk)[30] /* Line 784, Address: 0x101eb04 */
                       + shootwk->yposi.w.h;
    move_counter = shootwk->actfree[16] + 6; /* Line 786, Address: 0x101eb38 */
    if (move_counter >= shootwk->actfree[17]) goto label2; /* Line 787, Address: 0x101eb50 */

    shootwk->actfree[16] = move_counter; /* Line 789, Address: 0x101eb6c */
label1:
    move = &((unsigned short**)shootwk)[16]; /* Line 791, Address: 0x101eb74 */
    movetbl = *move; /* Line 792, Address: 0x101eb7c */
    ((unsigned short*)shootwk)[29] = movetbl[move_counter / 2]; /* Line 793, Address: 0x101eb80 */
    ((unsigned short*)shootwk)[30] = movetbl[move_counter / 2 + 1]; /* Line 794, Address: 0x101ebb0 */
    shooterspdset(shootwk); /* Line 795, Address: 0x101ebe4 */
    return; /* Line 796, Address: 0x101ebf0 */
  }

  actwk[0].xposi.l += actwk[0].xspeed.w << 8; /* Line 799, Address: 0x101ebf8 */
  actwk[0].yposi.l += actwk[0].yspeed.w << 8; /* Line 800, Address: 0x101ec20 */
  move = &((unsigned short**)shootwk)[16]; /* Line 801, Address: 0x101ec48 */
  movetbl = *move; /* Line 802, Address: 0x101ec50 */
  movetbl_data = movetbl[shootwk->actfree[16] / 2 + 2]; /* Line 803, Address: 0x101ec54 */
  if (movetbl_data >= 0) return; /* Line 804, Address: 0x101ec90 */
  if (!(swdata1.b.h & 112)) return; /* Line 805, Address: 0x101eca0 */
  movetbl_data &= 32767; /* Line 806, Address: 0x101ecb8 */
  move_counter = movetbl_data; /* Line 807, Address: 0x101ecc4 */
  move_counter = shootwk->actfree[17] + move_counter * 6; /* Line 808, Address: 0x101eccc */
  shootwk->actfree[16] = move_counter; /* Line 809, Address: 0x101ecf4 */
  goto label1; /* Line 810, Address: 0x101ecfc */


label2:
  actwk[0].yposi.w.h &= 2047; /* Line 814, Address: 0x101ed04 */
  shootwk->r_no0 = 0; /* Line 815, Address: 0x101ed18 */
  actwk[0].actfree[2] = 0; /* Line 816, Address: 0x101ed20 */
} /* Line 817, Address: 0x101ed28 */


void shooterspdset(sprite_status* shootwk) { /* Line 820, Address: 0x101ed50 */
  short ms_work0, ms_work1, cal_position_x, cal_position_y;
  int cal_long_x, cal_long_y;

  ms_work0 = ms_work1 = actwk[0].mspeed.w; /* Line 824, Address: 0x101ed70 */
  cal_position_x = ((short*)shootwk)[29] /* Line 825, Address: 0x101ed88 */
                 + shootwk->xposi.w.h;
  cal_position_x -= actwk[0].xposi.w.h; /* Line 827, Address: 0x101edbc */
  if (cal_position_x < 0) { /* Line 828, Address: 0x101edd0 */
    cal_position_x = -cal_position_x; /* Line 829, Address: 0x101ede0 */
    ms_work0 = -ms_work0; /* Line 830, Address: 0x101edfc */
  }
  cal_position_y = ((short*)shootwk)[30] /* Line 832, Address: 0x101ee18 */
                 + shootwk->yposi.w.h;
  cal_position_y -= actwk[0].yposi.w.h; /* Line 834, Address: 0x101ee4c */
  if (cal_position_y < 0) { /* Line 835, Address: 0x101ee60 */
    cal_position_y = -cal_position_y; /* Line 836, Address: 0x101ee70 */
    ms_work1 = -ms_work1; /* Line 837, Address: 0x101ee8c */
  }
  if (cal_position_x <= cal_position_y) { /* Line 839, Address: 0x101eea8 */

    cal_position_y = ((short*)shootwk)[30] /* Line 841, Address: 0x101eec4 */
                   + shootwk->yposi.w.h;
    cal_position_y -= actwk[0].yposi.w.h; /* Line 843, Address: 0x101eef8 */
    cal_long_y = cal_position_y << 16; /* Line 844, Address: 0x101ef0c */
    cal_long_y /= ms_work1; /* Line 845, Address: 0x101ef18 */

    cal_position_x = ((short*)shootwk)[29] /* Line 847, Address: 0x101ef34 */
                   + shootwk->xposi.w.h;
    cal_position_x -= actwk[0].xposi.w.h; /* Line 849, Address: 0x101ef68 */
    cal_long_x = cal_position_x << 16; /* Line 850, Address: 0x101ef7c */
    if (cal_long_x != 0) cal_long_x /= cal_long_y; /* Line 851, Address: 0x101ef88 */

    actwk[0].xspeed.w = cal_long_x; /* Line 853, Address: 0x101efa4 */
    actwk[0].yspeed.w = ms_work1; /* Line 854, Address: 0x101efb4 */
    if (cal_long_y < 0) cal_long_y = -cal_long_y; /* Line 855, Address: 0x101efbc */
    shootwk->actfree[4] = cal_long_y >> 8; /* Line 856, Address: 0x101efc8 */
    shootwk->actfree[5] = cal_long_y & 255; /* Line 857, Address: 0x101efd8 */
    return; /* Line 858, Address: 0x101efe8 */
  }


  cal_position_x = ((short*)shootwk)[29] /* Line 862, Address: 0x101eff0 */
                 + shootwk->xposi.w.h;
  cal_position_x -= actwk[0].xposi.w.h; /* Line 864, Address: 0x101f024 */
  cal_long_x = cal_position_x << 16; /* Line 865, Address: 0x101f038 */
  cal_long_x /= ms_work0; /* Line 866, Address: 0x101f044 */

  cal_position_y = ((short*)shootwk)[30] /* Line 868, Address: 0x101f060 */
                 + shootwk->yposi.w.h;
  cal_position_y -= actwk[0].yposi.w.h; /* Line 870, Address: 0x101f094 */
  cal_long_y = cal_position_y << 16; /* Line 871, Address: 0x101f0a8 */
  if (cal_long_y != 0) cal_long_y /= cal_long_x; /* Line 872, Address: 0x101f0b4 */

  actwk[0].yspeed.w = cal_long_y; /* Line 874, Address: 0x101f0d0 */
  actwk[0].xspeed.w = ms_work0; /* Line 875, Address: 0x101f0e0 */
  if (cal_long_x < 0) cal_long_x = -cal_long_x; /* Line 876, Address: 0x101f0e8 */
  shootwk->actfree[4] = cal_long_x >> 8; /* Line 877, Address: 0x101f0f4 */
  shootwk->actfree[5] = cal_long_x & 255; /* Line 878, Address: 0x101f104 */
} /* Line 879, Address: 0x101f114 */
