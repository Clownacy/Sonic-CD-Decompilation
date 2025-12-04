#include "..\EQU.H"
#include "HOTA8C.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\PLAYSUB.H"

static void hotaru8_initx(sprite_status* hotaru, unsigned char pr_data);
static void hotaru8_init(sprite_status* hotaru);
static void hotaru8_dspin(sprite_status* hotaru);
static void hotaru8_setup(sprite_status* hotaru);
static void hotaru8_idou(sprite_status* hotaru);
static void hota8_zanzou(sprite_status* hotaru);
static void hotaru8_move2(sprite_status* hotaru);
static void hotaru8_move3(sprite_status* hotaru);
static void hotaru8_beemset(sprite_status* hotaru);
static void hotaru8_move4(sprite_status* hotaru);
static void hotaru8_beem(sprite_status* beemwk);
static void h8bem_init(sprite_status* beemwk);
static void h8bem_move1(sprite_status* beemwk);
static void h8bem_move2(sprite_status* beemwk);
static void hotaru8_zanact(sprite_status* shadowwk);
static void hotaru8_main(sprite_status* roomwk);
static void ht8main_init(sprite_status* roomwk);
static void ht8main_move1(sprite_status* roomwk);
static void ht8main_move2(sprite_status* roomwk);
static void ht8main_move3(sprite_status* roomwk);
static void ht8main_move4(sprite_status* roomwk);
static void ht8main_move5(sprite_status* roomwk);
static void ht8main_move6(sprite_status* roomwk);
static void colchg2(unsigned char tbl_number);
static void clrtrn(PALETTEENTRY* color_tbl);
static void colchg(sprite_status* roomwk, unsigned char* chgtbl);

static unsigned char pchg0[6] = { 1, 5, 0, 5, 0, 255 }, pchg1[5] = { 0, 4, 10, 10, 255 }, pchg2[4] = { 7, 11, 12, 255 }, pchg3[4] = { 3, 6, 15, 255 }, pchg4[4] = { 0, 4, 10, 255 }, pchg5[4] = { 7, 4, 10, 255 }, pchg8[4] = { 0, 6, 10, 255 }, pchg9[6] = { 0, 9, 10, 16, 10, 255 };
static unsigned char* hotaru8_pchg[10] = { pchg0, pchg1, pchg2, pchg3, pchg4, pchg5, pchg8, pchg8, pchg8, pchg9 };
static sprite_pattern hotaru00 = { 2, { { { -12, -26, 0, 293 }, { -12, -10, 0, 295 } } } };
static sprite_pattern hotaru01 = { 2, { { { -12, -26, 0, 294 }, { -12, -10, 0, 295 } } } };
static sprite_pattern hotaru04 = { 1, { { -12, -12, 0, 296 } } };
static sprite_pattern hotaru05 = { 1, { { -12, -12, 0, 297 } } };
static sprite_pattern hotaru06 = { 2, { { { -4, -16, 0, 298 }, { -4, 0, 0, 298 } } } };
static sprite_pattern hotaru07 = { 2, { { { -4, -16, 0, 299 }, { -4, 0, 0, 299 } } } };
static sprite_pattern hotaru08 = { 2, { { { -4, -16, 0, 300 }, { -4, 0, 0, 300 } } } };
static sprite_pattern hotaru09 = { 3, { { { -12, 0, 0, 301 }, { -4, -16, 0, 298 }, { -4, 0, 0, 298 } } } };
static sprite_pattern hotaru0b = { 3, { { { -12, -12, 0, 297 }, { -12, -26, 0, 293 }, { -12, -10, 0, 295 } } } };
static sprite_pattern hotaru0c = { 3, { { { -12, -12, 0, 297 }, { -12, -26, 0, 294 }, { -12, -10, 0, 295 } } } };
static sprite_pattern hotaru0f = { 1, { { -12, -8, 0, 301 } } };
static sprite_pattern hotaru10 = { 1, { { -12, -8, 8, 301 } } };
static sprite_pattern hotaru = { 1, { { -16, -20, 0, 0 } } };
sprite_pattern* hotaru8pat[17] = { &hotaru00, &hotaru01, &hotaru, &hotaru, &hotaru04, &hotaru05, &hotaru06, &hotaru07, &hotaru08, &hotaru09, &hotaru, &hotaru0b, &hotaru0c, &hotaru, &hotaru, &hotaru0f, &hotaru10 };
static unsigned char clrchgtbl1[16] = { 168, 64, 144, 4, 120, 5, 96, 6, 72, 7, 48, 8, 24, 9, 0, 0 };
static PALETTEENTRY clrtblD[108] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,  32,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,  32, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,  64,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,  64, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,  32,   0, 1 }, {   0,  96,  32, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,  32, 1 }, {   0,  32,  96, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,  64,   0, 1 }, {   0, 128,  64, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,  32, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  32,   0,  64, 1 }, {  32,  64, 128, 1 },
  {   0,   0,   0, 1 }, {   0,  32,   0, 1 }, {  32,  96,   0, 1 }, {   0, 160,  96, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,  64, 1 }, {   0,   0,  32, 1 },
  {   0,   0,   0, 1 }, {   0,   0,  32, 1 }, {  32,  32,  96, 1 }, {  32,  96, 160, 1 },
  {   0,  32,   0, 1 }, {   0,  64,   0, 1 }, {  32, 128,  32, 1 }, {   0, 192, 128, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,  32,  96, 1 }, {   0,  32,  64, 1 },
  {   0,   0,  32, 1 }, {   0,  32,  64, 1 }, {  32,  64, 128, 1 }, {  32, 128, 192, 1 },
  {  32,  32,   0, 1 }, {  32,  64,   0, 1 }, {  64, 128,  32, 1 }, {  32, 192, 128, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,  32,  96, 1 }, {   0,  32,  64, 1 },
  {   0,   0,  32, 1 }, {  32,  32,  64, 1 }, {  64,  64, 128, 1 }, {  64, 128, 192, 1 },
  {  64,  32,   0, 1 }, {  64,  64,   0, 1 }, {  96, 128,  32, 1 }, {  64, 192, 128, 1 },
  {  32,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,  32,  96, 1 }, {   0,  32,  64, 1 },
  {  32,   0,  32, 1 }, {  64,  32,  64, 1 }, {  96,  64, 128, 1 }, {  96, 128, 192, 1 }
};
static PALETTEENTRY clrtblC1[48];
static unsigned char clrchgtbl2[16];






void hotaru8(sprite_status* hotaru) { /* Line 89, Address: 0x102eaf0 */
  void(*tbl[7])(sprite_status*) = { /* Line 90, Address: 0x102eafc */
    &hotaru8_init,
    &hotaru8_dspin,
    &hotaru8_setup,
    &hotaru8_idou,
    &hotaru8_move2,
    &hotaru8_move3,
    &hotaru8_move4
  };
  if (hotaru->userflag.b.h == -3) { hotaru8_zanact(hotaru); return; } /* Line 99, Address: 0x102eb28 */
  if (hotaru->userflag.b.h == -2) { hotaru8_main(hotaru); return; } /* Line 100, Address: 0x102eb58 */
  if (hotaru->userflag.b.h == -1) { hotaru8_beem(hotaru); return; } /* Line 101, Address: 0x102eb88 */

  hotaru->userflag.b.h = (unsigned char)hotaru->userflag.b.h & 127; /* Line 103, Address: 0x102ebb8 */
  tbl[hotaru->r_no0 / 2](hotaru); /* Line 104, Address: 0x102ebdc */
  actionsub(hotaru); /* Line 105, Address: 0x102ec18 */
} /* Line 106, Address: 0x102ec24 */


static void hotaru8_initx(sprite_status* hotaru, unsigned char pr_data) { /* Line 109, Address: 0x102ec40 */
  hotaru->actflg |= 4; /* Line 110, Address: 0x102ec4c */
  hotaru->sprpri = pr_data; /* Line 111, Address: 0x102ec5c */
  hotaru->patbase = hotaru8pat; /* Line 112, Address: 0x102ec68 */
  ((short*)hotaru)[29] = hotaru->xposi.w.h; /* Line 113, Address: 0x102ec78 */
  ((short*)hotaru)[27] = hotaru->yposi.w.h; /* Line 114, Address: 0x102ec88 */
} /* Line 115, Address: 0x102ec98 */


static void hotaru8_init(sprite_status* hotaru) { /* Line 118, Address: 0x102ecb0 */
  hotaru8_initx(hotaru, 1); /* Line 119, Address: 0x102ecbc */
  hotaru->sprvsize = hotaru->sprhsize = 8; /* Line 120, Address: 0x102eccc */
  hotaru->r_no0 += 2; /* Line 121, Address: 0x102ece4 */
  hotaru->actfree[16] = 60; /* Line 122, Address: 0x102ecf4 */
} /* Line 123, Address: 0x102ed00 */


static void hotaru8_dspin(sprite_status* hotaru) { /* Line 126, Address: 0x102ed10 */
  hotaru->mstno.b.h = 4; /* Line 127, Address: 0x102ed1c */
  patchg(hotaru, hotaru8_pchg); /* Line 128, Address: 0x102ed28 */
  if (--hotaru->actfree[16] != 0) return; /* Line 129, Address: 0x102ed3c */
  hotaru->mstno.b.h = 1; /* Line 130, Address: 0x102ed5c */
  hotaru->actfree[1] = hotaru->userflag.b.h; /* Line 131, Address: 0x102ed68 */
  hotaru->r_no0 += 2; /* Line 132, Address: 0x102ed78 */
} /* Line 133, Address: 0x102ed88 */


static void hotaru8_setup(sprite_status* hotaru) { /* Line 136, Address: 0x102eda0 */
  short next_position, speed_calc;

  if (!(hotaru->actfree[1] & 1)) goto label1; /* Line 139, Address: 0x102edb0 */


  next_position = actwk[0].xposi.w.h & 32760; /* Line 142, Address: 0x102edc8 */
  if (next_position < 3008) goto label1; /* Line 143, Address: 0x102edec */
  if (next_position >= 3232) goto label1; /* Line 144, Address: 0x102ee00 */
  ((short*)hotaru)[24] = next_position; /* Line 145, Address: 0x102ee14 */
  ((short*)hotaru)[25] = 344; /* Line 146, Address: 0x102ee1c */
  goto label2; /* Line 147, Address: 0x102ee28 */

label1:
  next_position = (gametimer.w & 127) + 3056; /* Line 150, Address: 0x102ee30 */
  ((short*)hotaru)[24] = next_position; /* Line 151, Address: 0x102ee58 */
  next_position = (actwk[0].xposi.w.h * 5 & 31) + 352; /* Line 152, Address: 0x102ee60 */
  ((short*)hotaru)[25] = next_position; /* Line 153, Address: 0x102ee90 */

label2:
  hotaru->yspeed.w = 0; /* Line 156, Address: 0x102ee98 */
  speed_calc = ((short*)hotaru)[25] - hotaru->yposi.w.h; /* Line 157, Address: 0x102eea0 */
  if (speed_calc != 0) hotaru->yspeed.w = speed_calc * 8; /* Line 158, Address: 0x102eed4 */

  hotaru->xspeed.w = 0; /* Line 160, Address: 0x102ef00 */
  speed_calc = ((short*)hotaru)[24] - hotaru->xposi.w.h; /* Line 161, Address: 0x102ef08 */
  if (speed_calc != 0) hotaru->xspeed.w = speed_calc * 8; /* Line 162, Address: 0x102ef3c */

  ++hotaru->actfree[1]; /* Line 164, Address: 0x102ef68 */
  hotaru->actfree[17] = 32; /* Line 165, Address: 0x102ef78 */
  hotaru->r_no0 += 2; /* Line 166, Address: 0x102ef84 */
  hotaru->colino = 0; /* Line 167, Address: 0x102ef94 */
} /* Line 168, Address: 0x102ef9c */



static void hotaru8_idou(sprite_status* hotaru) { /* Line 172, Address: 0x102efb0 */
  hotaru->xposi.l += hotaru->xspeed.w << 8; /* Line 173, Address: 0x102efbc */
  hotaru->yposi.l += hotaru->yspeed.w << 8; /* Line 174, Address: 0x102efe0 */

  hota8_zanzou(hotaru); /* Line 176, Address: 0x102f004 */
  if (--hotaru->actfree[17] == 0) hotaru->r_no0 += 2; /* Line 177, Address: 0x102f010 */
  patchg(hotaru, hotaru8_pchg); /* Line 178, Address: 0x102f040 */
} /* Line 179, Address: 0x102f054 */


static void hota8_zanzou(sprite_status* hotaru) { /* Line 182, Address: 0x102f070 */
  sprite_status* shadowwk;

  if ((hotaru->actfree[17] & 3) != 3) return; /* Line 185, Address: 0x102f07c */
  if (actwkchk(&shadowwk) != 0) return; /* Line 186, Address: 0x102f098 */
  shadowwk->actno = 57; /* Line 187, Address: 0x102f0ac */
  shadowwk->xposi.w.h = hotaru->xposi.w.h; /* Line 188, Address: 0x102f0b8 */
  shadowwk->yposi.w.h = hotaru->yposi.w.h; /* Line 189, Address: 0x102f0c8 */
  shadowwk->userflag.b.h = -3; /* Line 190, Address: 0x102f0d8 */
} /* Line 191, Address: 0x102f0e4 */


static void hotaru8_move2(sprite_status* hotaru) { /* Line 194, Address: 0x102f100 */
  unsigned char color_change_number;
  unsigned char tbl[32] = { /* Line 196, Address: 0x102f110 */
      0,   0,   0,
     24,  24,  24,
     72,  72,  72,
      0,   0,   0,
     24,  24,  24,
     72,  72,  72,
      0,   0,   0,
     24,  24,  24,
     72,  72,  72,
     96, 120, 144,
    168, 255
  };



  hotaru->mstno.b.h = 0; /* Line 212, Address: 0x102f144 */
  patchg(hotaru, hotaru8_pchg); /* Line 213, Address: 0x102f14c */

  if ((color_change_number = tbl[hotaru->actfree[18]++]) != 255) /* Line 215, Address: 0x102f160 */
    colchg2(color_change_number); /* Line 216, Address: 0x102f190 */
  else {
    hotaru->r_no0 += 2; /* Line 218, Address: 0x102f1a4 */
    hotaru->actfree[18] = 0; /* Line 219, Address: 0x102f1b4 */
  }
} /* Line 221, Address: 0x102f1bc */


static void hotaru8_move3(sprite_status* hotaru) { /* Line 224, Address: 0x102f1d0 */
  if (hotaru->actfree[18] == 0) { /* Line 225, Address: 0x102f1dc */
    hotaru->actfree[18] = 20; /* Line 226, Address: 0x102f1f0 */
    hotaru->mstno.b.h = 2; /* Line 227, Address: 0x102f1fc */
    hotaru->colino = 11; /* Line 228, Address: 0x102f208 */
  }

  if ((hotaru->actfree[21] += 64) < 64) hotaru8_beemset(hotaru); /* Line 231, Address: 0x102f214 */

  patchg(hotaru, hotaru8_pchg); /* Line 233, Address: 0x102f244 */
  if (--hotaru->actfree[18] == 0) hotaru->r_no0 += 2; /* Line 234, Address: 0x102f258 */
} /* Line 235, Address: 0x102f288 */


static void hotaru8_beemset(sprite_status* hotaru) { /* Line 238, Address: 0x102f2a0 */
  sprite_status* beemwk;

  if (actwkchk(&beemwk) != 0) return; /* Line 241, Address: 0x102f2ac */
  beemwk->actno = 57; /* Line 242, Address: 0x102f2c0 */
  beemwk->userflag.b.h = -1; /* Line 243, Address: 0x102f2cc */
  beemwk->xposi.w.h = hotaru->xposi.w.h; /* Line 244, Address: 0x102f2d8 */
  beemwk->yposi.w.h = hotaru->yposi.w.h; /* Line 245, Address: 0x102f2e8 */
} /* Line 246, Address: 0x102f2f8 */


static void hotaru8_move4(sprite_status* hotaru) { /* Line 249, Address: 0x102f310 */
  if (hotaru->actfree[18] == 0) { /* Line 250, Address: 0x102f31c */
    hotaru->actfree[18] = 16; /* Line 251, Address: 0x102f330 */
    hotaru->mstno.b.h = 0; /* Line 252, Address: 0x102f33c */
  }

  patchg(hotaru, hotaru8_pchg); /* Line 255, Address: 0x102f344 */

  if (--hotaru->actfree[18] != 0) return; /* Line 257, Address: 0x102f358 */

  hotaru->r_no0 = 4; /* Line 259, Address: 0x102f378 */
  hotaru->mstno.b.h = 1; /* Line 260, Address: 0x102f384 */
  colchg2(0); /* Line 261, Address: 0x102f390 */
} /* Line 262, Address: 0x102f39c */


static void hotaru8_beem(sprite_status* beemwk) { /* Line 265, Address: 0x102f3b0 */
  void(*tbl[3])(sprite_status*) = { &h8bem_init, &h8bem_move1, &h8bem_move2 }; /* Line 266, Address: 0x102f3bc */
  tbl[beemwk->r_no0 / 2](beemwk); /* Line 267, Address: 0x102f3e0 */
  actionsub(beemwk); /* Line 268, Address: 0x102f41c */
} /* Line 269, Address: 0x102f428 */


static void h8bem_init(sprite_status* beemwk) { /* Line 272, Address: 0x102f440 */
  hotaru8_initx(beemwk, 3); /* Line 273, Address: 0x102f44c */
  beemwk->r_no0 += 2; /* Line 274, Address: 0x102f45c */
  beemwk->sprvsize = 16; /* Line 275, Address: 0x102f46c */
  beemwk->sprhsize = 4; /* Line 276, Address: 0x102f478 */
  beemwk->colino = 152; /* Line 277, Address: 0x102f484 */
} /* Line 278, Address: 0x102f490 */


static void h8bem_move1(sprite_status* beemwk) { /* Line 281, Address: 0x102f4a0 */
  beemwk->mstno.b.h = 8; /* Line 282, Address: 0x102f4ac */
  beemwk->yposi.w.h += 8; /* Line 283, Address: 0x102f4b8 */
  patchg(beemwk, hotaru8_pchg); /* Line 284, Address: 0x102f4c8 */
  if (emycol_d(beemwk) < 0) { /* Line 285, Address: 0x102f4dc */
    beemwk->r_no0 += 2; /* Line 286, Address: 0x102f4f8 */
    beemwk->actfree[16] = beemwk->actfree[17] = 0; /* Line 287, Address: 0x102f508 */
  }
} /* Line 289, Address: 0x102f51c */


static void h8bem_move2(sprite_status* beemwk) { /* Line 292, Address: 0x102f530 */
  if (beemwk->actfree[16] == 0) { /* Line 293, Address: 0x102f53c */
    beemwk->actfree[16] = 2; /* Line 294, Address: 0x102f550 */
    beemwk->mstno.b.h = 9; /* Line 295, Address: 0x102f55c */
    if (beemwk->actfree[17] != 0) return; /* Line 296, Address: 0x102f568 */
  }
  patchg(beemwk, hotaru8_pchg); /* Line 298, Address: 0x102f57c */
  if (--beemwk->actfree[16] != 0) return; /* Line 299, Address: 0x102f590 */
  if (++beemwk->actfree[17] >= 2) frameout(beemwk); /* Line 300, Address: 0x102f5b0 */
} /* Line 301, Address: 0x102f5e0 */


static void hotaru8_zanact(sprite_status* shadowwk) { /* Line 304, Address: 0x102f5f0 */
  if (shadowwk->r_no0 == 0) { /* Line 305, Address: 0x102f5fc */
    hotaru8_initx(shadowwk, 4); /* Line 306, Address: 0x102f610 */
    shadowwk->actfree[16] = 24; /* Line 307, Address: 0x102f620 */
    shadowwk->mstno.b.h = 4; /* Line 308, Address: 0x102f62c */
    shadowwk->r_no0 += 2; /* Line 309, Address: 0x102f638 */
  }
  patchg(shadowwk, hotaru8_pchg); /* Line 311, Address: 0x102f648 */
  if (--shadowwk->actfree[16]) actionsub(shadowwk); /* Line 312, Address: 0x102f65c */
  else frameout(shadowwk); /* Line 313, Address: 0x102f68c */
} /* Line 314, Address: 0x102f698 */


static void hotaru8_main(sprite_status* roomwk) { /* Line 317, Address: 0x102f6b0 */
  void(*tbl[7])(sprite_status*) = { &ht8main_init, &ht8main_move1, &ht8main_move2, &ht8main_move3, &ht8main_move4, &ht8main_move5, &ht8main_move6 }; /* Line 318, Address: 0x102f6bc */

  tbl[roomwk->r_no0 / 2](roomwk); /* Line 320, Address: 0x102f6e8 */
} /* Line 321, Address: 0x102f724 */


static void ht8main_init(sprite_status* roomwk) { /* Line 324, Address: 0x102f740 */
  sprite_status* doorwk;

  hotaru8_initx(roomwk, 1); /* Line 327, Address: 0x102f74c */

  if (actwk[0].xposi.w.h < 3024) return; /* Line 329, Address: 0x102f75c */

  shut_flag = 1; /* Line 331, Address: 0x102f778 */
  if (actwkchk(&doorwk) != 0) return; /* Line 332, Address: 0x102f784 */
  doorwk->actno = 41; /* Line 333, Address: 0x102f798 */
  doorwk->yposi.w.h = 464; /* Line 334, Address: 0x102f7a4 */
  doorwk->xposi.w.h = 3240; /* Line 335, Address: 0x102f7b0 */
  ((unsigned short*)roomwk)[33] = doorwk - actwk; /* Line 336, Address: 0x102f7bc */
  roomwk->r_no0 += 2; /* Line 337, Address: 0x102f7f0 */
} /* Line 338, Address: 0x102f800 */


static void ht8main_move1(sprite_status* roomwk) { /* Line 341, Address: 0x102f810 */
  if (actwk[0].xposi.w.h < 3024) return; /* Line 342, Address: 0x102f818 */
  if (scra_vline >= 204) bossflag = 8; /* Line 343, Address: 0x102f834 */
  scra_vline += 6; /* Line 344, Address: 0x102f85c */
  if (bossflag == 8) { /* Line 345, Address: 0x102f870 */
    roomwk->r_no0 += 2; /* Line 346, Address: 0x102f888 */
    roomwk->actfree[16] = roomwk->actfree[17] = 0; /* Line 347, Address: 0x102f898 */
  }
} /* Line 349, Address: 0x102f8ac */


static void ht8main_move2(sprite_status* roomwk) { /* Line 352, Address: 0x102f8c0 */
  sprite_status* hotaru;

  colchg(roomwk, clrchgtbl1); /* Line 355, Address: 0x102f8cc */
  if (roomwk->actfree[16] != 16) return; /* Line 356, Address: 0x102f8e0 */
  roomwk->actfree[16] = roomwk->actfree[17] = 0; /* Line 357, Address: 0x102f8f8 */
  if (actwkchk(&hotaru) != 0) return; /* Line 358, Address: 0x102f90c */
  hotaru->actno = 57; /* Line 359, Address: 0x102f920 */
  hotaru->yposi.w.h = 400; /* Line 360, Address: 0x102f92c */
  hotaru->xposi.w.h = 3040; /* Line 361, Address: 0x102f938 */
  ((unsigned short*)roomwk)[28] = hotaru - actwk; /* Line 362, Address: 0x102f944 */
  roomwk->actfree[16] = 60; /* Line 363, Address: 0x102f978 */
  roomwk->r_no0 += 2; /* Line 364, Address: 0x102f984 */
} /* Line 365, Address: 0x102f994 */


static void ht8main_move3(sprite_status* roomwk) { /* Line 368, Address: 0x102f9b0 */
  sprite_status* hotaru;

  if (actwk[((unsigned short*)roomwk)[28]].actno == 57) return; /* Line 371, Address: 0x102f9bc */


  colchg2(0); /* Line 374, Address: 0x102f9f4 */
  if (--roomwk->actfree[16]) return; /* Line 375, Address: 0x102fa00 */

  if (actwkchk(&hotaru) != 0) return; /* Line 377, Address: 0x102fa1c */
  hotaru->actno = 57; /* Line 378, Address: 0x102fa30 */
  hotaru->yposi.w.h = 392; /* Line 379, Address: 0x102fa3c */
  hotaru->xposi.w.h = 3040; /* Line 380, Address: 0x102fa48 */
  ((unsigned short*)roomwk)[28] = hotaru - actwk; /* Line 381, Address: 0x102fa54 */
  hotaru->userflag.b.h = 1; /* Line 382, Address: 0x102fa88 */
  roomwk->r_no0 += 2; /* Line 383, Address: 0x102fa94 */
  ht8main_move4(roomwk); /* Line 384, Address: 0x102faa4 */
} /* Line 385, Address: 0x102fab0 */


static void ht8main_move4(sprite_status* roomwk) { /* Line 388, Address: 0x102fac0 */
  sprite_status* hotaru;

  if (actwkchk(&hotaru) != 0) return; /* Line 391, Address: 0x102facc */
  hotaru->actno = 57; /* Line 392, Address: 0x102fae0 */
  hotaru->yposi.w.h = 392; /* Line 393, Address: 0x102faec */
  hotaru->xposi.w.h = 3200; /* Line 394, Address: 0x102faf8 */
  ((unsigned short*)roomwk)[5] = hotaru - actwk; /* Line 395, Address: 0x102fb04 */
  hotaru->userflag.b.h = 0; /* Line 396, Address: 0x102fb38 */
  roomwk->actfree[16] = roomwk->actfree[17] = 0; /* Line 397, Address: 0x102fb40 */
  roomwk->r_no0 += 2; /* Line 398, Address: 0x102fb54 */
} /* Line 399, Address: 0x102fb64 */


static void ht8main_move5(sprite_status* roomwk) { /* Line 402, Address: 0x102fb80 */
  if (actwk[((unsigned short*)roomwk)[28]].actno == 57) return; /* Line 403, Address: 0x102fb88 */

  if (actwk[((unsigned short*)roomwk)[5]].actno == 57) return; /* Line 405, Address: 0x102fbc0 */

  roomwk->r_no0 += 2; /* Line 407, Address: 0x102fbf8 */
} /* Line 408, Address: 0x102fc08 */


static void ht8main_move6(sprite_status* roomwk) { /* Line 411, Address: 0x102fc20 */
  sprite_status* eggwk;

  colchg2(0); /* Line 414, Address: 0x102fc2c */
  actwk[((unsigned short*)roomwk)[33]].actfree[21] = 255; /* Line 415, Address: 0x102fc38 */
  if (actwkchk(&eggwk) != 0) return; /* Line 416, Address: 0x102fc64 */
  eggwk->actno = 63; /* Line 417, Address: 0x102fc78 */
  eggwk->xposi.w.h = 3840; /* Line 418, Address: 0x102fc84 */
  eggwk->yposi.w.h = 316; /* Line 419, Address: 0x102fc90 */
  frameout(roomwk); /* Line 420, Address: 0x102fc9c */
} /* Line 421, Address: 0x102fca8 */


static void colchg2(unsigned char tbl_number) { /* Line 424, Address: 0x102fcc0 */
  clrtrn(&clrtblD[tbl_number / 2]); /* Line 425, Address: 0x102fccc */
} /* Line 426, Address: 0x102fd04 */


static void clrtrn(PALETTEENTRY* color_tbl) { /* Line 429, Address: 0x102fd20 */
  short i;
  PALETTEENTRY* colorwk;

  colorwk = &lpcolorwk[52]; /* Line 433, Address: 0x102fd30 */
  for (i = 4; i < 16; ++i) *colorwk++ = *color_tbl++; /* Line 434, Address: 0x102fd3c */
} /* Line 435, Address: 0x102fda4 */


static void colchg(sprite_status* roomwk, unsigned char* chgtbl) { /* Line 438, Address: 0x102fdc0 */
  unsigned char clrtbl_index;

  if (roomwk->actfree[16] == 16) return; /* Line 441, Address: 0x102fdd4 */

  if (roomwk->actfree[17] != 0) { --roomwk->actfree[17]; return; } /* Line 443, Address: 0x102fdec */
  clrtbl_index = chgtbl[roomwk->actfree[16]]; /* Line 444, Address: 0x102fe18 */
  roomwk->actfree[17] = chgtbl[roomwk->actfree[16] + 1]; /* Line 445, Address: 0x102fe34 */
  clrtrn(&clrtblD[clrtbl_index / 2]); /* Line 446, Address: 0x102fe58 */
  roomwk->actfree[16] += 2; /* Line 447, Address: 0x102fe8c */
} /* Line 448, Address: 0x102fe9c */
