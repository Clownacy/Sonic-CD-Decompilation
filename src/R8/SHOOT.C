#include "..\EQU.H"
#include "SHOOT.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"

static void shoot_init(sprite_status* shootwk); static void shoot_move1(sprite_status* shootwk);

static unsigned short shooterposi_d[11] = {
  20,
  896, 1744,
  896, 1920,
  640, 1920,
  640, 896,
  1144, 896
};
static unsigned short shooterposi_e[11] = {
  20,
  1120, 896,
  640, 896,
  640, 1920,
  896, 1920,
  896, 1720
};
static unsigned short shooterposi_f[5] = {
  8,
  1152, 720,
  1152, 888
};
static unsigned short shooterposi_10[5] = {
  8,
  1152, 864,
  1152, 696
};
static unsigned short shooterposi_11[13] = {
  24,
  1152, 928,
  1152, 1152,
  1280, 1152,
  1536, 896,
  1664, 896,
  1664, 696
};
static unsigned short shooterposi_12[13] = {
  24,
  1664, 720,
  1664, 896,
  1536, 896,
  1280, 1152,
  1152, 1152,
  1152, 904
 };
static unsigned short shooterposi_13[15] = {
  28,
  1184, 896,
  1280, 896,
  1536, 1152,
  1664, 1152,
  1664, 1664,
  1920, 1664,
  1920, 1464
};
static unsigned short shooterposi_14[15] = {
  28,
  1920, 1488,
  1920, 1664,
  1664, 1664,
  1664, 1152,
  1536, 1152,
  1280, 896,
  1160, 896
};
static unsigned short shooterposi_15[7] = {
  12,
  3712, 208,
  3712, 384,
  4216, 384
};
static unsigned short shooterposi_16[7] = {
  12,
  4192, 384,
  3712, 384,
  3712, 184
};
static unsigned short shooterposi_17[5] = {
  8,
  4224, 208,
  4224, 376
};
static unsigned short shooterposi_18[5] = {
  8,
  4224, 352,
  4224, 184
};
static unsigned short shooterposi_19[9] = {
  16,
  4224, 416,
  4224, 896,
  3968, 896,
  3968, 696
};
static unsigned short shooterposi_1a[9] = {
  16,
  3968, 720,
  3968, 896,
  4224, 896,
  4224, 392
};
static unsigned short shooterposi_1b[11] = {
  20,
  4256, 384,
  4480, 384,
  4480, 1152,
  4992, 1152,
  4992, 952
};
static unsigned short shooterposi_1c[11] = {
  20,
  4992, 976,
  4992, 1152,
  4480, 1152,
  4480, 384,
  4232, 384
};
static unsigned short shooterposi_1d[9] = {
  16,
  6272, 720,
  6272, 1152,
  6528, 1152,
  6528, 952
};
static unsigned short shooterposi_1e[9] = {
  16,
  6528, 976,
  6528, 1152,
  6272, 1152,
  6272, 696
};
static unsigned short shooterposi_25[11] = {
  20,
  896, 1488,
  896, 1664,
  640, 1664,
  640, 896,
  1144, 896
};
static unsigned short shooterposi_26[11] = {
  20,
  1120, 896,
  640, 896,
  640, 1664,
  896, 1664,
  896, 1464
};
static unsigned short shooterposi_27[13] = {
  24,
  1152, 864,
  1152, 640,
  1280, 640,
  1536, 384,
  1664, 384,
  1664, 184
};
static unsigned short shooterposi_28[13] = {
  24, 1664, 208, 1664, 384, 1536, 384, 1280, 640, 1152, 640, 1152, 888
};
static unsigned short shooterposi_29[21] = {
  40,
  1152, 928,
  1152, 1152,
  1280, 1152,
  1536, 896,
  1664, 896,
  1664, 640,
  1536, 640,
  1280, 384,
  1152, 384,
  1152, 184
};
static unsigned short shooterposi_2a[21] = {
  40,
  1152, 208,
  1152, 384,
  1280, 384,
  1536, 640,
  1664, 640,
  1664, 896,
  1536, 896,
  1280, 1152,
  1152, 1152,
  1152, 904
};
static unsigned short shooterposi_2b[35] = {
  68,
  2176, 720,
  2176, 896,
  2560, 896,
  3072, 384,
  3328, 384,
  3584, 640,
  3712, 640,
  3712, 896,
  3328, 896,
  2816, 384,
  2432, 384,
  2432, 640,
  2560, 640,
  2816, 896,
  3072, 896,
  3584, 384,
  4216, 384
};
static unsigned short shooterposi_2c[35] = {
  68,
  4192, 384,
  3584, 384,
  3072, 896,
  2816, 896,
  2560, 640,
  2432, 640,
  2432, 384,
  2816, 384,
  3328, 896,
  3712, 896,
  3712, 640,
  3584, 640,
  3328, 384,
  3072, 384,
  2560, 896,
  2176, 896,
  2176, 696
};
static unsigned short shooterposi_2d[9] = {
  16,
  4224, 416,
  4224, 1664,
  3968, 1664,
  3968, 1464
};
static unsigned short shooterposi_2e[9] = {
  16,
  3968, 1488,
  3968, 1664,
  4224, 1664,
  4224, 392
};
static unsigned short shooterposi_2f[11] = {
  20,
  4256, 384,
  4480, 384,
  4480, 1152,
  4736, 1152,
  4736, 952
};
static unsigned short shooterposi_30[11] = {
  20,
  4736, 976,
  4736, 1152,
  4480, 1152,
  4480, 384,
  4232, 384
};
static unsigned short shooterposi_35[5] = {
  8,
  1152, 928,
  1152, 1144
};
static unsigned short shooterposi_36[5] = {
  8,
  1152, 1120,
  1152, 904
};
static unsigned short shooterposi_37[11] = {
  20,
  1152, 1184,
  1152, 1408,
  896, 1408,
  896, 1152,
  1144, 1152
};
static unsigned short shooterposi_38[11] = {
  20,
  1120, 1152,
  896, 1152,
  896, 1408,
  1152, 1408,
  1152, 1160
};
static unsigned short shooterposi_39[11] = {
  20,
  1184, 1152,
  1280, 1152,
  1536, 896,
  1664, 896,
  1664, 696
};
static unsigned short shooterposi_3a[11] = {
  20,
  1664, 720,
  1664, 896,
  1536, 896,
  1280, 1152,
  1160, 1152
};
static unsigned short shooterposi_3b[33] = {
  64,
  2176, 720,
  2176, 896,
  2560, 896,
  2816, 640,
  3072, 896,
  3328, 640,
  3584, 896,
  3712, 896,
  3712, 640,
  3584, 640,
  3328, 896,
  3072, 640,
  2816, 896,
  2560, 640,
  2432, 640,
  2432, 440
};
static unsigned short shooterposi_3c[33] = {
  64,
  2432, 464,
  2432, 640,
  2560, 640,
  2816, 896,
  3072, 640,
  3328, 896,
  3584, 640,
  3712, 640,
  3712, 896,
  3584, 896,
  3328, 640,
  3072, 896,
  2816, 640,
  2560, 896,
  2176, 896,
  2176, 696
};
static unsigned short* shooterpositbl[61] = {
  shooterposi_d, shooterposi_d,
  shooterposi_d, shooterposi_d,
  shooterposi_d, shooterposi_d,
  shooterposi_d, shooterposi_d,
  shooterposi_d, shooterposi_d,
  shooterposi_d, shooterposi_d,
  shooterposi_d, shooterposi_d,
  shooterposi_e, shooterposi_f,
  shooterposi_10, shooterposi_11,
  shooterposi_12, shooterposi_13,
  shooterposi_14, shooterposi_15,
  shooterposi_16, shooterposi_17,
  shooterposi_18, shooterposi_19,
  shooterposi_1a, shooterposi_1b,
  shooterposi_1c, shooterposi_1d,
  shooterposi_1e, shooterposi_25,
  shooterposi_25, shooterposi_25,
  shooterposi_25, shooterposi_25,
  shooterposi_25, shooterposi_25,
  shooterposi_26, shooterposi_27,
  shooterposi_28, shooterposi_29,
  shooterposi_2a, shooterposi_2b,
  shooterposi_2c, shooterposi_2d,
  shooterposi_2e, shooterposi_2f,
  shooterposi_30, shooterposi_35,
  shooterposi_35, shooterposi_35,
  shooterposi_35, shooterposi_35,
  shooterposi_36, shooterposi_37,
  shooterposi_38, shooterposi_39,
  shooterposi_3a, shooterposi_3b,
  shooterposi_3c
};
extern sprite_pattern* bariapat[13];





























void shoot_s(sprite_status* shootwk) { /* Line 405, Address: 0x1024950 */
  void(*shoot_s_tbl[4])(sprite_status*) = { &shoot_init, &shootermove, &shoot_move1, &shootermove3 }; /* Line 406, Address: 0x102495c */


  if (actwk[0].r_no0 >= 6) return; /* Line 409, Address: 0x1024988 */

  swdata.w = swdata1.w; /* Line 411, Address: 0x10249a0 */
  shoot_s_tbl[shootwk->r_no0 / 2](shootwk); /* Line 412, Address: 0x10249b0 */
  frameout_s(shootwk); /* Line 413, Address: 0x10249ec */
} /* Line 414, Address: 0x10249f8 */



static void shoot_init(sprite_status* shootwk) { /* Line 418, Address: 0x1024a10 */
  shootwk->actflg |= 4; /* Line 419, Address: 0x1024a18 */
  ((short*)shootwk)[31] = 4; /* Line 420, Address: 0x1024a28 */
  ((short*)shootwk)[29] = shootwk->xposi.w.h; /* Line 421, Address: 0x1024a34 */
  ((short*)shootwk)[30] = shootwk->yposi.w.h; /* Line 422, Address: 0x1024a44 */
  shootwk->r_no0 += 2; /* Line 423, Address: 0x1024a54 */
} /* Line 424, Address: 0x1024a64 */


static void shoot_move1(sprite_status* shootwk) { /* Line 427, Address: 0x1024a70 */
  if (swdata.b.l & 1) ((short*)shootwk)[30] -= 16; /* Line 428, Address: 0x1024a7c */
  else if (swdata.b.l & 2) ((short*)shootwk)[30] += 16; /* Line 429, Address: 0x1024aac */
  else if (swdata.b.l & 4) ((short*)shootwk)[29] -= 16; /* Line 430, Address: 0x1024adc */
  else if (swdata.b.l & 8) ((short*)shootwk)[29] += 16; /* Line 431, Address: 0x1024b0c */
  else return; /* Line 432, Address: 0x1024b3c */

  shootwk->r_no0 += 2; /* Line 434, Address: 0x1024b44 */
  actwk[0].mspeed.w = 4096; /* Line 435, Address: 0x1024b54 */
  shooterspdset(shootwk); /* Line 436, Address: 0x1024b60 */
} /* Line 437, Address: 0x1024b6c */



void shooter(sprite_status* shootwk) { /* Line 441, Address: 0x1024b80 */
  short flag_no, addition;

  if (!(time_flag & 128)) goto label1; /* Line 444, Address: 0x1024b94 */
  if ((flag_no = shootwk->cdsts) == 0) goto label1; /* Line 445, Address: 0x1024bac */
  flag_no *= 3; /* Line 446, Address: 0x1024bd8 */
  addition = (short)(time_flag & 127) - (short)time_item; /* Line 447, Address: 0x1024be8 */
  if (addition < 0) addition = 0; /* Line 448, Address: 0x1024c34 */
  else if (addition >= 3) addition = 2; /* Line 449, Address: 0x1024c50 */
  flagwork[flag_no + addition] &= 127; /* Line 450, Address: 0x1024c70 */
label1:
  if (actwk[0].mstno.b.h != 43) { /* Line 452, Address: 0x1024c9c */
    if (actwk[0].r_no0 < 6) { /* Line 453, Address: 0x1024cb8 */
      if ((unsigned char)shootwk->userflag.b.h == 128) { shoot_s(shootwk); return; } /* Line 454, Address: 0x1024cd0 */
      switch (shootwk->r_no0) { /* Line 455, Address: 0x1024d00 */
        case 0:
          shooterinit(shootwk); /* Line 457, Address: 0x1024d40 */
          break; /* Line 458, Address: 0x1024d4c */
        case 2:
          shootermove(shootwk); /* Line 460, Address: 0x1024d54 */
          break; /* Line 461, Address: 0x1024d60 */
        case 4:
          shootermove2(shootwk); /* Line 463, Address: 0x1024d68 */
          break; /* Line 464, Address: 0x1024d74 */
        case 6:
          shootermove3(shootwk); /* Line 466, Address: 0x1024d7c */
          break;
      }
    }
  }

} /* Line 472, Address: 0x1024d88 */


void shooterinit(sprite_status* shootwk) { /* Line 475, Address: 0x1024da0 */
  unsigned short** move;
  unsigned short* movetbl;

  shootwk->patbase = bariapat; /* Line 479, Address: 0x1024db4 */
  shootwk->actflg = 4; /* Line 480, Address: 0x1024dc4 */
  shootwk->sprpri = 1; /* Line 481, Address: 0x1024dd0 */
  shootwk->sprhsize = 16; /* Line 482, Address: 0x1024ddc */


  shootwk->r_no0 += 2; /* Line 485, Address: 0x1024de8 */
  movetbl = shooterpositbl[shootwk->userflag.b.h & 127]; /* Line 486, Address: 0x1024df8 */
  shootwk->actfree[16] = *movetbl >> 8; /* Line 487, Address: 0x1024e20 */
  shootwk->actfree[17] = *movetbl & 255; /* Line 488, Address: 0x1024e38 */
  move = &((unsigned short**)shootwk)[16]; /* Line 489, Address: 0x1024e50 */
  *move = &movetbl[1]; /* Line 490, Address: 0x1024e58 */
  ((short*)shootwk)[29] = movetbl[1]; /* Line 491, Address: 0x1024e60 */
  ((short*)shootwk)[30] = movetbl[2]; /* Line 492, Address: 0x1024e6c */
  shootermove(shootwk); /* Line 493, Address: 0x1024e78 */
} /* Line 494, Address: 0x1024e84 */


void shootermove(sprite_status* shootwk) { /* Line 497, Address: 0x1024ea0 */
  short cal_position;

  cal_position = actwk[0].xposi.w.h - shootwk->xposi.w.h + 16; /* Line 500, Address: 0x1024eb0 */
  if (cal_position >= 32 || cal_position < 0) return; /* Line 501, Address: 0x1024ee8 */
  cal_position = actwk[0].yposi.w.h - shootwk->yposi.w.h + 16; /* Line 502, Address: 0x1024f14 */
  if (cal_position >= 32 || cal_position < 0) return; /* Line 503, Address: 0x1024f4c */
  if (actwk[0].actfree[2] != 0) return; /* Line 504, Address: 0x1024f78 */
  if (actwk[0].r_no0 == 4) { /* Line 505, Address: 0x1024f8c */
    actwk[0].r_no0 -= 2; /* Line 506, Address: 0x1024fa4 */
    ((short*)&actwk[0])[26] = 120; /* Line 507, Address: 0x1024fb8 */
  }
  shootwk->r_no0 += 2; /* Line 509, Address: 0x1024fc4 */
  actwk[0].actfree[2] = 129; /* Line 510, Address: 0x1024fd4 */
  actwk[0].sproffset &= 32767; /* Line 511, Address: 0x1024fe0 */
  actwk[0].mstno.b.h = 2; /* Line 512, Address: 0x1024ff4 */
  mspd_set(shootwk); /* Line 513, Address: 0x1025000 */
  actwk[0].xspeed.w = actwk[0].yspeed.w = 0; /* Line 514, Address: 0x102500c */
  shootwk->cddat &= 223; /* Line 515, Address: 0x1025024 */
  actwk[0].cddat &= 223; /* Line 516, Address: 0x1025034 */
  actwk[0].cddat |= 2; /* Line 517, Address: 0x1025048 */
  actwk[0].xposi.w.h = shootwk->xposi.w.h; /* Line 518, Address: 0x102505c */
  actwk[0].yposi.w.h = shootwk->yposi.w.h; /* Line 519, Address: 0x102506c */
  shootwk->actfree[8] = 0; /* Line 520, Address: 0x102507c */
  soundset(145); /* Line 521, Address: 0x1025084 */
} /* Line 522, Address: 0x1025090 */


void shootermove2(sprite_status* shootwk) { /* Line 525, Address: 0x10250b0 */
  shooterspdset(shootwk); /* Line 526, Address: 0x10250bc */
  shootwk->r_no0 += 2; /* Line 527, Address: 0x10250c8 */
  soundset(145); /* Line 528, Address: 0x10250d8 */
} /* Line 529, Address: 0x10250e4 */


void shootermove3(sprite_status* shootwk) { /* Line 532, Address: 0x1025100 */
  unsigned char move_counter;
  unsigned short** move;
  unsigned short* movetbl;

  if ((char)--shootwk->actfree[4] < 0) { /* Line 537, Address: 0x1025118 */
    actwk[0].xposi.w.h = ((unsigned short*)shootwk)[29]; /* Line 538, Address: 0x1025144 */
    actwk[0].yposi.w.h = ((unsigned short*)shootwk)[30]; /* Line 539, Address: 0x1025154 */
    move_counter = shootwk->actfree[16] + 4; /* Line 540, Address: 0x1025164 */
    if (move_counter >= shootwk->actfree[17]) goto label1; /* Line 541, Address: 0x102517c */

    shootwk->actfree[16] = move_counter; /* Line 543, Address: 0x1025198 */
    move = &((unsigned short**)shootwk)[16]; /* Line 544, Address: 0x10251a0 */
    movetbl = *move; /* Line 545, Address: 0x10251a8 */
    ((short*)shootwk)[29] = movetbl[move_counter / 2]; /* Line 546, Address: 0x10251ac */
    ((short*)shootwk)[30] = movetbl[move_counter / 2 + 1]; /* Line 547, Address: 0x10251dc */
    shooterspdset(shootwk); /* Line 548, Address: 0x1025210 */
    return; /* Line 549, Address: 0x102521c */
  }

  actwk[0].xposi.l += actwk[0].xspeed.w << 8; /* Line 552, Address: 0x1025224 */
  actwk[0].yposi.l += actwk[0].yspeed.w << 8; /* Line 553, Address: 0x102524c */
  return; /* Line 554, Address: 0x1025274 */

label1:
  actwk[0].yposi.w.h &= 2047; /* Line 557, Address: 0x102527c */
  shootwk->r_no0 = 0; /* Line 558, Address: 0x1025290 */
  actwk[0].actfree[2] = 0; /* Line 559, Address: 0x1025298 */
} /* Line 560, Address: 0x10252a0 */


void shooterspdset(sprite_status* shootwk) { /* Line 563, Address: 0x10252c0 */
  short ms_work0, ms_work1, cal_position_x, cal_position_y;
  int cal_long_x, cal_long_y;

  ms_work0 = ms_work1 = actwk[0].mspeed.w; /* Line 567, Address: 0x10252e0 */
  cal_position_x = ((short*)shootwk)[29]; /* Line 568, Address: 0x10252f8 */
  cal_position_x -= actwk[0].xposi.w.h; /* Line 569, Address: 0x1025308 */
  if (cal_position_x < 0) { /* Line 570, Address: 0x102531c */
    cal_position_x = -cal_position_x; /* Line 571, Address: 0x102532c */
    ms_work0 = -ms_work0; /* Line 572, Address: 0x1025348 */
  }
  cal_position_y = ((short*)shootwk)[30]; /* Line 574, Address: 0x1025364 */
  cal_position_y -= actwk[0].yposi.w.h; /* Line 575, Address: 0x1025374 */
  if (cal_position_y < 0) { /* Line 576, Address: 0x1025388 */
    cal_position_y = -cal_position_y; /* Line 577, Address: 0x1025398 */
    ms_work1 = -ms_work1; /* Line 578, Address: 0x10253b4 */
  }
  if (cal_position_x <= cal_position_y) { /* Line 580, Address: 0x10253d0 */

    cal_position_y = ((short*)shootwk)[30]; /* Line 582, Address: 0x10253ec */
    cal_position_y -= actwk[0].yposi.w.h; /* Line 583, Address: 0x10253fc */
    cal_long_y = cal_position_y << 16; /* Line 584, Address: 0x1025410 */
    cal_long_y /= ms_work1; /* Line 585, Address: 0x102541c */

    cal_position_x = ((short*)shootwk)[29]; /* Line 587, Address: 0x1025438 */
    cal_position_x -= actwk[0].xposi.w.h; /* Line 588, Address: 0x1025448 */
    cal_long_x = cal_position_x << 16; /* Line 589, Address: 0x102545c */
    if (cal_long_x != 0) cal_long_x /= cal_long_y; /* Line 590, Address: 0x1025468 */

    actwk[0].xspeed.w = cal_long_x; /* Line 592, Address: 0x1025484 */
    actwk[0].yspeed.w = ms_work1; /* Line 593, Address: 0x1025494 */
    if (cal_long_y < 0) cal_long_y = -cal_long_y; /* Line 594, Address: 0x102549c */
    shootwk->actfree[4] = cal_long_y >> 8; /* Line 595, Address: 0x10254a8 */
    shootwk->actfree[5] = cal_long_y & 255; /* Line 596, Address: 0x10254b8 */
    return; /* Line 597, Address: 0x10254c8 */
  }


  cal_position_x = ((short*)shootwk)[29]; /* Line 601, Address: 0x10254d0 */
  cal_position_x -= actwk[0].xposi.w.h; /* Line 602, Address: 0x10254e0 */
  cal_long_x = cal_position_x << 16; /* Line 603, Address: 0x10254f4 */
  cal_long_x /= ms_work0; /* Line 604, Address: 0x1025500 */

  cal_position_y = ((short*)shootwk)[30]; /* Line 606, Address: 0x102551c */
  cal_position_y -= actwk[0].yposi.w.h; /* Line 607, Address: 0x102552c */
  cal_long_y = cal_position_y << 16; /* Line 608, Address: 0x1025540 */
  if (cal_long_y != 0) cal_long_y /= cal_long_x; /* Line 609, Address: 0x102554c */

  actwk[0].yspeed.w = cal_long_y; /* Line 611, Address: 0x1025568 */
  actwk[0].xspeed.w = ms_work0; /* Line 612, Address: 0x1025578 */
  if (cal_long_x < 0) cal_long_x = -cal_long_x; /* Line 613, Address: 0x1025580 */
  shootwk->actfree[4] = cal_long_x >> 8; /* Line 614, Address: 0x102558c */
  shootwk->actfree[5] = cal_long_x & 255; /* Line 615, Address: 0x102559c */
} /* Line 616, Address: 0x10255ac */


void mspd_set(sprite_status* shootwk) { /* Line 619, Address: 0x10255d0 */
  short mspdtbl[4] = { 4096, 3072, 3072, 2048 }; /* Line 620, Address: 0x10255dc */
  short cal_mspeed;

  actwk[0].mspeed.w = 4096; /* Line 623, Address: 0x1025608 */
  if (shootwk->userflag.b.h < 0) return; /* Line 624, Address: 0x1025614 */
  cal_mspeed = mspdtbl[shootwk->userflag.b.h & 15]; /* Line 625, Address: 0x102562c */
  if (cal_mspeed > actwk[0].mspeed.w) actwk[0].mspeed.w = cal_mspeed; /* Line 626, Address: 0x1025654 */
} /* Line 627, Address: 0x1025680 */
