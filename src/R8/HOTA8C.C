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

static unsigned char pchg0[6] = { 1, 5, 0, 5, 0, 255 };
static unsigned char pchg1[5] = { 0, 4, 10, 10, 255 };
static unsigned char pchg2[4] = { 7, 11, 12, 255 };
static unsigned char pchg3[4] = { 3, 6, 15, 255 };
static unsigned char pchg4[4] = { 0, 4, 10, 255 };
static unsigned char pchg5[4] = { 7, 4, 10, 255 };
static unsigned char pchg8[4] = { 0, 6, 10, 255 };
static unsigned char pchg9[6] = { 0, 9, 10, 16, 10, 255 };
static unsigned char* hotaru8_pchg[10] = { pchg0, pchg1, pchg2, pchg3, pchg4, pchg5, pchg8, pchg8, pchg8, pchg9 };
static sprite_pattern hotaru00 = { 2, { { -12, -26, 0, 293 }, { -12, -10, 0, 295 } } };
static sprite_pattern hotaru01 = { 2, { { -12, -26, 0, 294 }, { -12, -10, 0, 295 } } };
static sprite_pattern hotaru04 = { 1, { { -12, -12, 0, 296 } } };
static sprite_pattern hotaru05 = { 1, { { -12, -12, 0, 297 } } };
static sprite_pattern hotaru06 = { 2, { { -4, -16, 0, 298 }, { -4, 0, 0, 298 } } };
static sprite_pattern hotaru07 = { 2, { { -4, -16, 0, 299 }, { -4, 0, 0, 299 } } };
static sprite_pattern hotaru08 = { 2, { { -4, -16, 0, 300 }, { -4, 0, 0, 300 } } };
static sprite_pattern hotaru09 = { 3, { { -12, 0, 0, 301 }, { -4, -16, 0, 298 }, { -4, 0, 0, 298 } } };
static sprite_pattern hotaru0b = { 3, { { -12, -12, 0, 297 }, { -12, -26, 0, 293 }, { -12, -10, 0, 295 } } };
static sprite_pattern hotaru0c = { 3, { { -12, -12, 0, 297 }, { -12, -26, 0, 294 }, { -12, -10, 0, 295 } } };
static sprite_pattern hotaru0f = { 1, { { -12, -8, 0, 301 } } };
static sprite_pattern hotaru10 = { 1, { { -12, -8, 8, 301 } } };
static sprite_pattern hotaru = { 1, { { -16, -20, 0, 0 } } };
sprite_pattern* hotaru8pat[17] = { &hotaru00, &hotaru01, &hotaru, &hotaru, &hotaru04, &hotaru05, &hotaru06, &hotaru07, &hotaru08, &hotaru09, &hotaru, &hotaru0b, &hotaru0c, &hotaru, &hotaru, &hotaru0f, &hotaru10 };
static unsigned char clrchgtbl1[16] = { 84, 64, 72, 4, 60, 5, 48, 6, 36, 7, 24, 8, 12, 9, 0, 0 };
static unsigned char clrchgtbl2[16] = { 0, 64, 12, 9, 24, 8, 36, 7, 48, 6, 60, 5, 72, 4, 84, 32 };
static PALETTEENTRY clrtblC1[48] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,  32, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,  32, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,  64, 1 }, {   0,   0,   0, 1 }, {   0,   0,  32, 1 },
  {   0,   0,  64, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,  96, 1 },
  {   0,   0,   0, 1 }, {   0,   0,  64, 1 }, {   0,   0,  96, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {   0,   0,  32, 1 }, {   0,   0,  96, 1 },
  {   0,   0, 128, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,  64, 160, 1 },
  {   0,   0,  64, 1 }, {   0,   0, 128, 1 }, {  32,   0, 160, 1 }, {   0,   0,  32, 1 },
  {   0,   0,   0, 1 }, {  96,  96, 192, 1 }, {   0,   0,  96, 1 }, {  32,   0, 160, 1 },
  {  64,  32, 192, 1 }, {   0,   0,  64, 1 }, {   0,   0,  32, 1 }, { 128, 128, 224, 1 },
  {   0,  32, 128, 1 }, {  64,  32, 192, 1 }, {  96,  64, 224, 1 }, {   0,   0,  96, 1 }
};
static PALETTEENTRY clrtblD[108];














void hotaru8(sprite_status* hotaru) { /* Line 89, Address: 0x102ec60 */
  void(*tbl[7])(sprite_status*) = { /* Line 90, Address: 0x102ec6c */
    &hotaru8_init,
    &hotaru8_dspin,
    &hotaru8_setup,
    &hotaru8_idou,
    &hotaru8_move2,
    &hotaru8_move3,
    &hotaru8_move4
  };
  if (hotaru->userflag.b.h == -3) { hotaru8_zanact(hotaru); return; } /* Line 99, Address: 0x102ec98 */
  if (hotaru->userflag.b.h == -2) { hotaru8_main(hotaru); return; } /* Line 100, Address: 0x102ecc8 */
  if (hotaru->userflag.b.h == -1) { hotaru8_beem(hotaru); return; } /* Line 101, Address: 0x102ecf8 */

  hotaru->userflag.b.h = (unsigned char)hotaru->userflag.b.h & 127; /* Line 103, Address: 0x102ed28 */
  tbl[hotaru->r_no0 / 2](hotaru); /* Line 104, Address: 0x102ed4c */
  actionsub(hotaru); /* Line 105, Address: 0x102ed88 */
} /* Line 106, Address: 0x102ed94 */


static void hotaru8_initx(sprite_status* hotaru, unsigned char pr_data) { /* Line 109, Address: 0x102edb0 */
  hotaru->actflg |= 4; /* Line 110, Address: 0x102edbc */
  hotaru->sprpri = pr_data; /* Line 111, Address: 0x102edcc */
  hotaru->patbase = hotaru8pat; /* Line 112, Address: 0x102edd8 */
  ((short*)hotaru)[29] = hotaru->xposi.w.h; /* Line 113, Address: 0x102ede8 */
  ((short*)hotaru)[27] = hotaru->yposi.w.h; /* Line 114, Address: 0x102edf8 */
} /* Line 115, Address: 0x102ee08 */


static void hotaru8_init(sprite_status* hotaru) { /* Line 118, Address: 0x102ee20 */
  hotaru8_initx(hotaru, 1); /* Line 119, Address: 0x102ee2c */
  hotaru->sprvsize = hotaru->sprhsize = 8; /* Line 120, Address: 0x102ee3c */
  hotaru->r_no0 += 2; /* Line 121, Address: 0x102ee54 */
  hotaru->actfree[16] = 60; /* Line 122, Address: 0x102ee64 */
} /* Line 123, Address: 0x102ee70 */


static void hotaru8_dspin(sprite_status* hotaru) { /* Line 126, Address: 0x102ee80 */
  hotaru->mstno.b.h = 4; /* Line 127, Address: 0x102ee8c */
  patchg(hotaru, hotaru8_pchg); /* Line 128, Address: 0x102ee98 */
  if (--hotaru->actfree[16] != 0) return; /* Line 129, Address: 0x102eeac */
  hotaru->mstno.b.h = 1; /* Line 130, Address: 0x102eecc */
  hotaru->actfree[1] = hotaru->userflag.b.h; /* Line 131, Address: 0x102eed8 */
  hotaru->r_no0 += 2; /* Line 132, Address: 0x102eee8 */
} /* Line 133, Address: 0x102eef8 */


static void hotaru8_setup(sprite_status* hotaru) { /* Line 136, Address: 0x102ef10 */
  short next_position, speed_calc;

  if (!(hotaru->actfree[1] & 1)) goto label1; /* Line 139, Address: 0x102ef20 */


  next_position = actwk[0].xposi.w.h & 32760; /* Line 142, Address: 0x102ef38 */
  if (next_position < 3008) goto label1; /* Line 143, Address: 0x102ef5c */
  if (next_position >= 3232) goto label1; /* Line 144, Address: 0x102ef70 */
  ((short*)hotaru)[24] = next_position; /* Line 145, Address: 0x102ef84 */
  ((short*)hotaru)[25] = 344; /* Line 146, Address: 0x102ef8c */
  goto label2; /* Line 147, Address: 0x102ef98 */

label1:
  next_position = (gametimer.w & 127) + 3056; /* Line 150, Address: 0x102efa0 */
  ((short*)hotaru)[24] = next_position; /* Line 151, Address: 0x102efc8 */
  next_position = (actwk[0].xposi.w.h * 5 & 31) + 352; /* Line 152, Address: 0x102efd0 */
  ((short*)hotaru)[25] = next_position; /* Line 153, Address: 0x102f000 */

label2:
  hotaru->yspeed.w = 0; /* Line 156, Address: 0x102f008 */
  speed_calc = ((short*)hotaru)[25] - hotaru->yposi.w.h; /* Line 157, Address: 0x102f010 */
  if (speed_calc != 0) hotaru->yspeed.w = speed_calc * 8; /* Line 158, Address: 0x102f044 */

  hotaru->xspeed.w = 0; /* Line 160, Address: 0x102f070 */
  speed_calc = ((short*)hotaru)[24] - hotaru->xposi.w.h; /* Line 161, Address: 0x102f078 */
  if (speed_calc != 0) hotaru->xspeed.w = speed_calc * 8; /* Line 162, Address: 0x102f0ac */

  ++hotaru->actfree[1]; /* Line 164, Address: 0x102f0d8 */
  hotaru->actfree[17] = 32; /* Line 165, Address: 0x102f0e8 */
  hotaru->r_no0 += 2; /* Line 166, Address: 0x102f0f4 */
  hotaru->colino = 0; /* Line 167, Address: 0x102f104 */
} /* Line 168, Address: 0x102f10c */



static void hotaru8_idou(sprite_status* hotaru) { /* Line 172, Address: 0x102f120 */
  hotaru->xposi.l += hotaru->xspeed.w << 8; /* Line 173, Address: 0x102f12c */
  hotaru->yposi.l += hotaru->yspeed.w << 8; /* Line 174, Address: 0x102f150 */

  hota8_zanzou(hotaru); /* Line 176, Address: 0x102f174 */
  if (--hotaru->actfree[17] == 0) hotaru->r_no0 += 2; /* Line 177, Address: 0x102f180 */
  patchg(hotaru, hotaru8_pchg); /* Line 178, Address: 0x102f1b0 */
} /* Line 179, Address: 0x102f1c4 */


static void hota8_zanzou(sprite_status* hotaru) { /* Line 182, Address: 0x102f1e0 */
  sprite_status* shadowwk;

  if ((hotaru->actfree[17] & 3) != 3) return; /* Line 185, Address: 0x102f1ec */
  if (actwkchk(&shadowwk) != 0) return; /* Line 186, Address: 0x102f208 */
  shadowwk->actno = 57; /* Line 187, Address: 0x102f21c */
  shadowwk->xposi.w.h = hotaru->xposi.w.h; /* Line 188, Address: 0x102f228 */
  shadowwk->yposi.w.h = hotaru->yposi.w.h; /* Line 189, Address: 0x102f238 */
  shadowwk->userflag.b.h = -3; /* Line 190, Address: 0x102f248 */
} /* Line 191, Address: 0x102f254 */


static void hotaru8_move2(sprite_status* hotaru) { /* Line 194, Address: 0x102f270 */
  char color_change_number;
  char tbl[32] = { /* Line 196, Address: 0x102f280 */
     0,  0,  0, 12,
    12, 12, 36, 36,
    36,  0,  0,  0,
    12, 12, 12, 36,
    36, 36,  0,  0,
     0, 12, 12, 12,
    36, 36, 36, 48,
    60, 72, 84, -1
  };






  hotaru->mstno.b.h = 0; /* Line 212, Address: 0x102f2b4 */
  patchg(hotaru, hotaru8_pchg); /* Line 213, Address: 0x102f2bc */

  if ((color_change_number = tbl[hotaru->actfree[18]++]) != -1) /* Line 215, Address: 0x102f2d0 */
    colchg2(color_change_number); /* Line 216, Address: 0x102f308 */
  else {
    hotaru->r_no0 += 2; /* Line 218, Address: 0x102f31c */
    hotaru->actfree[18] = 0; /* Line 219, Address: 0x102f32c */
  }
} /* Line 221, Address: 0x102f334 */


static void hotaru8_move3(sprite_status* hotaru) { /* Line 224, Address: 0x102f350 */
  if (hotaru->actfree[18] == 0) { /* Line 225, Address: 0x102f35c */
    hotaru->actfree[18] = 20; /* Line 226, Address: 0x102f370 */
    hotaru->mstno.b.h = 2; /* Line 227, Address: 0x102f37c */
    hotaru->colino = 11; /* Line 228, Address: 0x102f388 */
  }

  if ((hotaru->actfree[21] += 64) < 64) hotaru8_beemset(hotaru); /* Line 231, Address: 0x102f394 */

  patchg(hotaru, hotaru8_pchg); /* Line 233, Address: 0x102f3c4 */
  if (--hotaru->actfree[18] == 0) hotaru->r_no0 += 2; /* Line 234, Address: 0x102f3d8 */
} /* Line 235, Address: 0x102f408 */


static void hotaru8_beemset(sprite_status* hotaru) { /* Line 238, Address: 0x102f420 */
  sprite_status* beemwk;

  if (actwkchk(&beemwk) != 0) return; /* Line 241, Address: 0x102f42c */
  beemwk->actno = 57; /* Line 242, Address: 0x102f440 */
  beemwk->userflag.b.h = -1; /* Line 243, Address: 0x102f44c */
  beemwk->xposi.w.h = hotaru->xposi.w.h; /* Line 244, Address: 0x102f458 */
  beemwk->yposi.w.h = hotaru->yposi.w.h; /* Line 245, Address: 0x102f468 */
} /* Line 246, Address: 0x102f478 */


static void hotaru8_move4(sprite_status* hotaru) { /* Line 249, Address: 0x102f490 */
  if (hotaru->actfree[18] == 0) { /* Line 250, Address: 0x102f49c */
    hotaru->actfree[18] = 16; /* Line 251, Address: 0x102f4b0 */
    hotaru->mstno.b.h = 0; /* Line 252, Address: 0x102f4bc */
  }

  patchg(hotaru, hotaru8_pchg); /* Line 255, Address: 0x102f4c4 */

  if (--hotaru->actfree[18] != 0) return; /* Line 257, Address: 0x102f4d8 */

  hotaru->r_no0 = 4; /* Line 259, Address: 0x102f4f8 */
  hotaru->mstno.b.h = 1; /* Line 260, Address: 0x102f504 */
  colchg2(0); /* Line 261, Address: 0x102f510 */
} /* Line 262, Address: 0x102f51c */


static void hotaru8_beem(sprite_status* beemwk) { /* Line 265, Address: 0x102f530 */
  void(*tbl[3])(sprite_status*) = { &h8bem_init, &h8bem_move1, &h8bem_move2 }; /* Line 266, Address: 0x102f53c */
  tbl[beemwk->r_no0 / 2](beemwk); /* Line 267, Address: 0x102f560 */
  actionsub(beemwk); /* Line 268, Address: 0x102f59c */
} /* Line 269, Address: 0x102f5a8 */


static void h8bem_init(sprite_status* beemwk) { /* Line 272, Address: 0x102f5c0 */
  hotaru8_initx(beemwk, 3); /* Line 273, Address: 0x102f5cc */
  beemwk->r_no0 += 2; /* Line 274, Address: 0x102f5dc */
  beemwk->sprvsize = 16; /* Line 275, Address: 0x102f5ec */
  beemwk->sprhsize = 4; /* Line 276, Address: 0x102f5f8 */
  beemwk->colino = 152; /* Line 277, Address: 0x102f604 */
} /* Line 278, Address: 0x102f610 */


static void h8bem_move1(sprite_status* beemwk) { /* Line 281, Address: 0x102f620 */
  beemwk->mstno.b.h = 8; /* Line 282, Address: 0x102f62c */
  beemwk->yposi.w.h += 8; /* Line 283, Address: 0x102f638 */
  patchg(beemwk, hotaru8_pchg); /* Line 284, Address: 0x102f648 */
  if (emycol_d(beemwk) < 0) { /* Line 285, Address: 0x102f65c */
    beemwk->r_no0 += 2; /* Line 286, Address: 0x102f678 */
    beemwk->actfree[16] = beemwk->actfree[17] = 0; /* Line 287, Address: 0x102f688 */
  }
} /* Line 289, Address: 0x102f69c */


static void h8bem_move2(sprite_status* beemwk) { /* Line 292, Address: 0x102f6b0 */
  if (beemwk->actfree[16] == 0) { /* Line 293, Address: 0x102f6bc */
    beemwk->actfree[16] = 2; /* Line 294, Address: 0x102f6d0 */
    beemwk->mstno.b.h = 9; /* Line 295, Address: 0x102f6dc */
    if (beemwk->actfree[17] != 0) return; /* Line 296, Address: 0x102f6e8 */
  }
  patchg(beemwk, hotaru8_pchg); /* Line 298, Address: 0x102f6fc */
  if (--beemwk->actfree[16] != 0) return; /* Line 299, Address: 0x102f710 */
  if (++beemwk->actfree[17] >= 2) frameout(beemwk); /* Line 300, Address: 0x102f730 */
} /* Line 301, Address: 0x102f760 */


static void hotaru8_zanact(sprite_status* shadowwk) { /* Line 304, Address: 0x102f770 */
  if (shadowwk->r_no0 == 0) { /* Line 305, Address: 0x102f77c */
    hotaru8_initx(shadowwk, 4); /* Line 306, Address: 0x102f790 */
    shadowwk->actfree[16] = 24; /* Line 307, Address: 0x102f7a0 */
    shadowwk->mstno.b.h = 4; /* Line 308, Address: 0x102f7ac */
    shadowwk->r_no0 += 2; /* Line 309, Address: 0x102f7b8 */
  }
  patchg(shadowwk, hotaru8_pchg); /* Line 311, Address: 0x102f7c8 */
  if (--shadowwk->actfree[16]) actionsub(shadowwk); /* Line 312, Address: 0x102f7dc */
  else frameout(shadowwk); /* Line 313, Address: 0x102f80c */
} /* Line 314, Address: 0x102f818 */


static void hotaru8_main(sprite_status* roomwk) { /* Line 317, Address: 0x102f830 */
  void(*tbl[7])(sprite_status*) = { &ht8main_init, &ht8main_move1, &ht8main_move2, &ht8main_move3, &ht8main_move4, &ht8main_move5, &ht8main_move6 }; /* Line 318, Address: 0x102f83c */

  tbl[roomwk->r_no0 / 2](roomwk); /* Line 320, Address: 0x102f868 */
} /* Line 321, Address: 0x102f8a4 */


static void ht8main_init(sprite_status* roomwk) { /* Line 324, Address: 0x102f8c0 */
  sprite_status* doorwk;

  hotaru8_initx(roomwk, 1); /* Line 327, Address: 0x102f8cc */

  if (actwk[0].xposi.w.h < 3024) return; /* Line 329, Address: 0x102f8dc */

  shut_flag = 1; /* Line 331, Address: 0x102f8f8 */
  if (actwkchk(&doorwk) != 0) return; /* Line 332, Address: 0x102f904 */
  doorwk->actno = 41; /* Line 333, Address: 0x102f918 */
  doorwk->yposi.w.h = 464; /* Line 334, Address: 0x102f924 */
  doorwk->xposi.w.h = 3240; /* Line 335, Address: 0x102f930 */
  ((unsigned short*)roomwk)[33] = doorwk - actwk; /* Line 336, Address: 0x102f93c */
  roomwk->r_no0 += 2; /* Line 337, Address: 0x102f970 */
} /* Line 338, Address: 0x102f980 */


static void ht8main_move1(sprite_status* roomwk) { /* Line 341, Address: 0x102f990 */
  if (actwk[0].xposi.w.h < 3024) return; /* Line 342, Address: 0x102f998 */
  if (scra_vline >= 204) bossflag = 8; /* Line 343, Address: 0x102f9b4 */
  scra_vline += 6; /* Line 344, Address: 0x102f9dc */
  if (bossflag == 8) { /* Line 345, Address: 0x102f9f0 */
    roomwk->r_no0 += 2; /* Line 346, Address: 0x102fa08 */
    roomwk->actfree[16] = roomwk->actfree[17] = 0; /* Line 347, Address: 0x102fa18 */
  }
} /* Line 349, Address: 0x102fa2c */


static void ht8main_move2(sprite_status* roomwk) { /* Line 352, Address: 0x102fa40 */
  sprite_status* hotaru;

  colchg(roomwk, clrchgtbl1); /* Line 355, Address: 0x102fa4c */
  if (roomwk->actfree[16] != 16) return; /* Line 356, Address: 0x102fa60 */
  roomwk->actfree[16] = roomwk->actfree[17] = 0; /* Line 357, Address: 0x102fa78 */
  if (actwkchk(&hotaru) != 0) return; /* Line 358, Address: 0x102fa8c */
  hotaru->actno = 57; /* Line 359, Address: 0x102faa0 */
  hotaru->yposi.w.h = 400; /* Line 360, Address: 0x102faac */
  hotaru->xposi.w.h = 3040; /* Line 361, Address: 0x102fab8 */
  ((unsigned short*)roomwk)[28] = hotaru - actwk; /* Line 362, Address: 0x102fac4 */
  roomwk->actfree[16] = 60; /* Line 363, Address: 0x102faf8 */
  roomwk->r_no0 += 2; /* Line 364, Address: 0x102fb04 */
} /* Line 365, Address: 0x102fb14 */


static void ht8main_move3(sprite_status* roomwk) { /* Line 368, Address: 0x102fb30 */
  sprite_status* hotaru;

  if (actwk[((unsigned short*)roomwk)[28]].actno == 57) return; /* Line 371, Address: 0x102fb3c */


  colchg2(0); /* Line 374, Address: 0x102fb74 */
  if (--roomwk->actfree[16]) return; /* Line 375, Address: 0x102fb80 */

  if (actwkchk(&hotaru) != 0) return; /* Line 377, Address: 0x102fb9c */
  hotaru->actno = 57; /* Line 378, Address: 0x102fbb0 */
  hotaru->yposi.w.h = 392; /* Line 379, Address: 0x102fbbc */
  hotaru->xposi.w.h = 3040; /* Line 380, Address: 0x102fbc8 */
  ((unsigned short*)roomwk)[28] = hotaru - actwk; /* Line 381, Address: 0x102fbd4 */
  hotaru->userflag.b.h = 1; /* Line 382, Address: 0x102fc08 */
  roomwk->r_no0 += 2; /* Line 383, Address: 0x102fc14 */
  ht8main_move4(roomwk); /* Line 384, Address: 0x102fc24 */
} /* Line 385, Address: 0x102fc30 */


static void ht8main_move4(sprite_status* roomwk) { /* Line 388, Address: 0x102fc40 */
  sprite_status* hotaru;

  if (actwkchk(&hotaru) != 0) return; /* Line 391, Address: 0x102fc4c */
  hotaru->actno = 57; /* Line 392, Address: 0x102fc60 */
  hotaru->yposi.w.h = 392; /* Line 393, Address: 0x102fc6c */
  hotaru->xposi.w.h = 3200; /* Line 394, Address: 0x102fc78 */
  ((unsigned short*)roomwk)[5] = hotaru - actwk; /* Line 395, Address: 0x102fc84 */
  hotaru->userflag.b.h = 0; /* Line 396, Address: 0x102fcb8 */
  roomwk->actfree[16] = roomwk->actfree[17] = 0; /* Line 397, Address: 0x102fcc0 */
  roomwk->r_no0 += 2; /* Line 398, Address: 0x102fcd4 */
} /* Line 399, Address: 0x102fce4 */


static void ht8main_move5(sprite_status* roomwk) { /* Line 402, Address: 0x102fd00 */
  if (actwk[((unsigned short*)roomwk)[28]].actno == 57) return; /* Line 403, Address: 0x102fd08 */

  if (actwk[((unsigned short*)roomwk)[5]].actno == 57) return; /* Line 405, Address: 0x102fd40 */

  roomwk->r_no0 += 2; /* Line 407, Address: 0x102fd78 */
} /* Line 408, Address: 0x102fd88 */


static void ht8main_move6(sprite_status* roomwk) { /* Line 411, Address: 0x102fda0 */
  sprite_status* eggwk;

  colchg(roomwk, clrchgtbl2); /* Line 414, Address: 0x102fdac */
  if (roomwk->actfree[16] != 16) return; /* Line 415, Address: 0x102fdc0 */
  actwk[((unsigned short*)roomwk)[33]].actfree[21] = 255; /* Line 416, Address: 0x102fdd8 */
  if (actwkchk(&eggwk) != 0) return; /* Line 417, Address: 0x102fe04 */
  eggwk->actno = 63; /* Line 418, Address: 0x102fe18 */
  eggwk->xposi.w.h = 3840; /* Line 419, Address: 0x102fe24 */
  eggwk->yposi.w.h = 316; /* Line 420, Address: 0x102fe30 */
  frameout(roomwk); /* Line 421, Address: 0x102fe3c */
} /* Line 422, Address: 0x102fe48 */


static void colchg2(unsigned char tbl_number) { /* Line 425, Address: 0x102fe60 */
  clrtrn(&clrtblC1[tbl_number / 2]); /* Line 426, Address: 0x102fe6c */
} /* Line 427, Address: 0x102fea4 */


static void clrtrn(PALETTEENTRY* color_tbl) { /* Line 430, Address: 0x102fec0 */
  PALETTEENTRY* colorwk;

  colorwk = &lpcolorwk[49]; /* Line 433, Address: 0x102fecc */
  *colorwk++ = *color_tbl++; /* Line 434, Address: 0x102fed8 */
  *colorwk++ = *color_tbl++; /* Line 435, Address: 0x102ff0c */
  colorwk = &lpcolorwk[60]; /* Line 436, Address: 0x102ff40 */
  *colorwk++ = *color_tbl++; /* Line 437, Address: 0x102ff4c */
  *colorwk++ = *color_tbl++; /* Line 438, Address: 0x102ff80 */
  *colorwk++ = *color_tbl++; /* Line 439, Address: 0x102ffb4 */
  *colorwk++ = *color_tbl++; /* Line 440, Address: 0x102ffe8 */
} /* Line 441, Address: 0x103001c */


static void colchg(sprite_status* roomwk, unsigned char* chgtbl) { /* Line 444, Address: 0x1030030 */
  unsigned char clrtbl_index;

  if (roomwk->actfree[16] == 16) return; /* Line 447, Address: 0x1030044 */

  if (roomwk->actfree[17] != 0) { --roomwk->actfree[17]; return; } /* Line 449, Address: 0x103005c */
  clrtbl_index = chgtbl[roomwk->actfree[16]]; /* Line 450, Address: 0x1030088 */
  roomwk->actfree[17] = chgtbl[roomwk->actfree[16] + 1]; /* Line 451, Address: 0x10300a4 */
  clrtrn(&clrtblC1[clrtbl_index / 2]); /* Line 452, Address: 0x10300c8 */
  roomwk->actfree[16] += 2; /* Line 453, Address: 0x10300fc */
} /* Line 454, Address: 0x103010c */
