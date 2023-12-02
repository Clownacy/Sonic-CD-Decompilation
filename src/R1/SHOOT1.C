#include "..\EQU.H"
#include "SHOOT1.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"

extern void soundset(short ReqNo);

static spr_array eda00 = { 1, { { -16, -12, 0, 288 } } };
static spr_array eda01 = { 1, { { -20, -16, 0, 289 } } };
static spr_array eda02 = { 1, { { -12, -16, 0, 290 } } };
spr_array* edapat[3] = { &eda00, &eda01, &eda02 };
static spr_array kag00 = { 1, { { -16, -16, 0, 291 } } };
static spr_array kag01 = { 1, { { -16, -8, 0, 292 } } };
spr_array* kagepat[2] = { &kag00, &kag01 };
static spr_array ana00 = { 1, { { -16, -16, 0, 293 } } };
spr_array* kage1pat[1] = { &ana00 };
static unsigned short shooterposi_0[69] = { 136, 5184, 240, 5240, 264, 5264, 320, 5264, 480, 5184, 504, 5120, 480, 5104, 448, 5104, 384, 5120, 368, 5152, 360, 5184, 368, 5224, 424, 5728, 536, 5792, 528, 5824, 504, 5840, 456, 5824, 424, 5760, 408, 5720, 416, 5696, 456, 5712, 496, 5760, 512, 5824, 512, 5840, 528, 5840, 648, 5824, 704, 5760, 728, 5712, 704, 5712, 672, 5760, 656, 5888, 656, 5928, 672, 5928, 736, 5888, 752 };
static unsigned short shooterposi_1[35] = { 68, 3848, 416, 3984, 416, 4040, 440, 4064, 496, 4064, 608, 4096, 656, 4144, 672, 4200, 648, 4224, 592, 4200, 536, 4144, 512, 4080, 544, 4064, 608, 4096, 656, 4144, 672, 4200, 648, 4400, 456 };
static unsigned short shooterposi_2[35] = { 68, 5680, 656, 5680, 792, 5688, 824, 5840, 976, 5888, 992, 5944, 968, 5976, 912, 5944, 856, 5880, 832, 5824, 864, 5800, 912, 5840, 976, 5888, 992, 5944, 968, 6072, 840, 6096, 800, 6096, 616 };
unsigned short* shooterpositbl[3] = { shooterposi_0, shooterposi_1, shooterposi_2 };
extern spr_array* bariapat[];


void eda(act_info* edawk) { /* Line 24, Address: 0x101cf50 */
  switch (edawk->r_no0) { /* Line 25, Address: 0x101cf5c */
    case 0:
      eda_init(edawk); /* Line 27, Address: 0x101cf84 */
      break; /* Line 28, Address: 0x101cf90 */
    case 2:
      eda_move(edawk); /* Line 30, Address: 0x101cf98 */
      break;
  }


  actionsub(edawk); /* Line 35, Address: 0x101cfa4 */
  frameout_s(edawk); /* Line 36, Address: 0x101cfb0 */
} /* Line 37, Address: 0x101cfbc */


void eda_init(act_info* edawk) { /* Line 40, Address: 0x101cfd0 */
  edawk->r_no0 += 2; /* Line 41, Address: 0x101cfdc */
  edawk->actflg |= 4; /* Line 42, Address: 0x101cfec */
  edawk->patbase = edapat; /* Line 43, Address: 0x101cffc */
  edawk->patno = edawk->userflag.b.h; /* Line 44, Address: 0x101d00c */
  edawk->sprhsize = 16; /* Line 45, Address: 0x101d01c */
  edawk->sprvsize = 16; /* Line 46, Address: 0x101d028 */


  eda_move(edawk); /* Line 49, Address: 0x101d034 */
} /* Line 50, Address: 0x101d040 */


void eda_move(act_info* edawk) { /* Line 53, Address: 0x101d050 */
  unsigned char action_no;
  action_no = edawk->actno; /* Line 55, Address: 0x101d05c */
} /* Line 56, Address: 0x101d068 */







void kage(act_info* kagewk) { /* Line 64, Address: 0x101d080 */
  switch (kagewk->r_no0) { /* Line 65, Address: 0x101d08c */
    case 0:
      kage_init(kagewk); /* Line 67, Address: 0x101d0b4 */
      break; /* Line 68, Address: 0x101d0c0 */
    case 2:
      kage_move(kagewk); /* Line 70, Address: 0x101d0c8 */
      break;
  }


  actionsub(kagewk); /* Line 75, Address: 0x101d0d4 */
  frameout_s(kagewk); /* Line 76, Address: 0x101d0e0 */
} /* Line 77, Address: 0x101d0ec */


void kage_init(act_info* kagewk) { /* Line 80, Address: 0x101d100 */
  kagewk->r_no0 += 2; /* Line 81, Address: 0x101d10c */
  kagewk->actflg |= 4; /* Line 82, Address: 0x101d11c */
  kagewk->sprpri = 6; /* Line 83, Address: 0x101d12c */
  kagewk->patbase = kagepat; /* Line 84, Address: 0x101d138 */
  kagewk->patno = kagewk->userflag.b.h; /* Line 85, Address: 0x101d148 */
  kagewk->sprhsize = 16; /* Line 86, Address: 0x101d158 */
  kagewk->sprvsize = 16; /* Line 87, Address: 0x101d164 */


  kage_move(kagewk); /* Line 90, Address: 0x101d170 */
} /* Line 91, Address: 0x101d17c */


void kage_move(act_info* kagewk) { /* Line 94, Address: 0x101d190 */
  unsigned char action_no;
  action_no = kagewk->actno; /* Line 96, Address: 0x101d19c */
} /* Line 97, Address: 0x101d1a8 */






void ana(act_info* anawk) { /* Line 104, Address: 0x101d1c0 */
  switch (anawk->r_no0) { /* Line 105, Address: 0x101d1cc */
    case 0:
      kage1_init(anawk); /* Line 107, Address: 0x101d200 */
      break; /* Line 108, Address: 0x101d20c */
    case 2:
      kage1_move0(anawk); /* Line 110, Address: 0x101d214 */
      break; /* Line 111, Address: 0x101d220 */
    case 4:
      kage1_move1(anawk); /* Line 113, Address: 0x101d228 */
      break;
  }


  frameout_s(anawk); /* Line 118, Address: 0x101d234 */
} /* Line 119, Address: 0x101d240 */


void kage1_init(act_info* anawk) { /* Line 122, Address: 0x101d250 */
  anawk->r_no0 += 2; /* Line 123, Address: 0x101d25c */
  anawk->actflg |= 4; /* Line 124, Address: 0x101d26c */

  anawk->patbase = kage1pat; /* Line 126, Address: 0x101d27c */
  anawk->sprhsize = 16; /* Line 127, Address: 0x101d28c */
  anawk->sprvsize = 16; /* Line 128, Address: 0x101d298 */
  anawk->sprpri = 6; /* Line 129, Address: 0x101d2a4 */
  if (kage1_chk(anawk) != 0) { /* Line 130, Address: 0x101d2b0 */
    anawk->r_no0 += 2; /* Line 131, Address: 0x101d2c8 */
    kage1_move1(anawk); /* Line 132, Address: 0x101d2d8 */
  } else { /* Line 133, Address: 0x101d2e4 */
    kage1_clr(anawk); /* Line 134, Address: 0x101d2ec */
    kage1_move0(anawk); /* Line 135, Address: 0x101d2f8 */
  }
} /* Line 137, Address: 0x101d304 */


void kage1_move0(act_info* anawk) { /* Line 140, Address: 0x101d320 */
  short cal_position;

  if (actwk[0].actfree[2] == 0) return; /* Line 143, Address: 0x101d330 */
  cal_position = actwk[0].xposi.w.h - anawk->xposi.w.h + 32; /* Line 144, Address: 0x101d344 */
  if (cal_position < 0 || cal_position >= 64) return; /* Line 145, Address: 0x101d37c */
  cal_position = actwk[0].yposi.w.h - anawk->yposi.w.h + 32; /* Line 146, Address: 0x101d3a8 */
  if (cal_position < 0 || cal_position >= 64) return; /* Line 147, Address: 0x101d3e0 */
  kage1_chk(anawk); /* Line 148, Address: 0x101d40c */
  soundset(163); /* Line 149, Address: 0x101d418 */
  anawk->r_no0 += 2; /* Line 150, Address: 0x101d424 */
  kage1_move1(anawk); /* Line 151, Address: 0x101d434 */
} /* Line 152, Address: 0x101d440 */


void kage1_move1(act_info* anawk) { /* Line 155, Address: 0x101d460 */
  actionsub(anawk); /* Line 156, Address: 0x101d46c */
} /* Line 157, Address: 0x101d478 */


unsigned char kage1_chk(act_info* anawk) { /* Line 160, Address: 0x101d490 */
  short flag_no;
  unsigned char zero_flag;

  flag_no = time_flag + anawk->cdsts * 3; /* Line 164, Address: 0x101d4a0 */
  zero_flag = flagwork[flag_no] & 64; /* Line 165, Address: 0x101d4e4 */
  flagwork[flag_no] |= 64; /* Line 166, Address: 0x101d50c */
  return zero_flag; /* Line 167, Address: 0x101d52c */
} /* Line 168, Address: 0x101d530 */


void kage1_clr(act_info* anawk) { /* Line 171, Address: 0x101d550 */
  short flag_no;

  flag_no = time_flag + anawk->cdsts * 3; /* Line 174, Address: 0x101d55c */
  flagwork[flag_no] &= 191; /* Line 175, Address: 0x101d5a0 */
} /* Line 176, Address: 0x101d5c0 */





















































































void shooter(act_info* shootwk) { /* Line 262, Address: 0x101d5d0 */
  short flag_no, addition;

  if (!(time_flag & 128)) goto label1; /* Line 265, Address: 0x101d5e4 */
  if ((flag_no = shootwk->cdsts) == 0) goto label1; /* Line 266, Address: 0x101d5fc */
  flag_no *= 3; /* Line 267, Address: 0x101d628 */
  addition = (time_flag & 127) - time_item; /* Line 268, Address: 0x101d638 */
  if (addition < 0) addition = 0; /* Line 269, Address: 0x101d684 */
  else if (addition >= 3) addition = 2; /* Line 270, Address: 0x101d6a0 */
  flagwork[flag_no + addition] &= 127; /* Line 271, Address: 0x101d6c0 */
label1:
  if (actwk[0].mstno.b.h != 43) { /* Line 273, Address: 0x101d6ec */
    if (actwk[0].cddat < 6) { /* Line 274, Address: 0x101d708 */
      switch (shootwk->r_no0) { /* Line 275, Address: 0x101d720 */
        case 0:
          shooterinit(shootwk); /* Line 277, Address: 0x101d760 */
          break; /* Line 278, Address: 0x101d76c */
        case 2:
          shootermove(shootwk); /* Line 280, Address: 0x101d774 */
          break; /* Line 281, Address: 0x101d780 */
        case 4:
          shootermove2(shootwk); /* Line 283, Address: 0x101d788 */
          break; /* Line 284, Address: 0x101d794 */
        case 6:
          shootermove3(shootwk); /* Line 286, Address: 0x101d79c */
          break;
      }
    }
  }

} /* Line 292, Address: 0x101d7a8 */


void shooterinit(act_info* shootwk) { /* Line 295, Address: 0x101d7c0 */
  unsigned short** move;
  unsigned short* movetbl;

  shootwk->patbase = bariapat; /* Line 299, Address: 0x101d7d4 */
  shootwk->actflg = 4; /* Line 300, Address: 0x101d7e4 */
  shootwk->sprpri = 1; /* Line 301, Address: 0x101d7f0 */
  shootwk->sprhsize = 16; /* Line 302, Address: 0x101d7fc */


  shootwk->r_no0 += 2; /* Line 305, Address: 0x101d808 */
  movetbl = shooterpositbl[shootwk->userflag.b.h & 127]; /* Line 306, Address: 0x101d818 */
  shootwk->actfree[16] = *movetbl >> 8; /* Line 307, Address: 0x101d840 */
  shootwk->actfree[17] = *movetbl; /* Line 308, Address: 0x101d858 */
  move = ((unsigned short**)shootwk + 16); /* Line 309, Address: 0x101d870 */
  *move = movetbl + 1; /* Line 310, Address: 0x101d878 */
  ((short*)shootwk)[29] = movetbl[1]; /* Line 311, Address: 0x101d880 */
  ((short*)shootwk)[30] = movetbl[2]; /* Line 312, Address: 0x101d88c */
  shootermove(shootwk); /* Line 313, Address: 0x101d898 */
} /* Line 314, Address: 0x101d8a4 */


void shootermove(act_info* shootwk) { /* Line 317, Address: 0x101d8c0 */
  short cal_position;

  cal_position = actwk[0].xposi.w.h - shootwk->xposi.w.h + 16; /* Line 320, Address: 0x101d8d0 */
  if (cal_position >= 32 || cal_position < 0) return; /* Line 321, Address: 0x101d908 */
  cal_position = actwk[0].yposi.w.h - shootwk->yposi.w.h + 16; /* Line 322, Address: 0x101d934 */
  if (cal_position >= 32 || cal_position < 0) return; /* Line 323, Address: 0x101d96c */
  if (actwk[0].actfree[2] != 0) return; /* Line 324, Address: 0x101d998 */
  if (actwk[0].cddat == 4) { /* Line 325, Address: 0x101d9ac */
    actwk[0].cddat -= 2; /* Line 326, Address: 0x101d9c4 */
    *(short*)&actwk[0].actfree[6] = 120; /* Line 327, Address: 0x101d9d8 */
  }
  shootwk->r_no0 += 2; /* Line 329, Address: 0x101d9e4 */
  actwk[0].actfree[2] = 129; /* Line 330, Address: 0x101d9f4 */
  if (shootwk->userflag.b.l != 0) actwk[0].actfree[2] |= 64; /* Line 331, Address: 0x101da00 */
  actwk[0].mstno.b.h = 2; /* Line 332, Address: 0x101da2c */
  mspd_set(shootwk); /* Line 333, Address: 0x101da38 */
  actwk[0].xspeed.w = actwk[0].yspeed.w = 0; /* Line 334, Address: 0x101da44 */
  shootwk->cddat &= 223; /* Line 335, Address: 0x101da5c */
  actwk[0].cddat &= 223; /* Line 336, Address: 0x101da6c */
  actwk[0].cddat |= 2; /* Line 337, Address: 0x101da80 */
  actwk[0].actfree[18] = 0; /* Line 338, Address: 0x101da94 */
  actwk[0].xposi.w.h = shootwk->xposi.w.h; /* Line 339, Address: 0x101da9c */
  actwk[0].yposi.w.h = shootwk->yposi.w.h; /* Line 340, Address: 0x101daac */
  shootwk->actfree[8] = 0; /* Line 341, Address: 0x101dabc */
  soundset(145); /* Line 342, Address: 0x101dac4 */
} /* Line 343, Address: 0x101dad0 */


void shootermove2(act_info* shootwk) { /* Line 346, Address: 0x101daf0 */
  shooterspdset(shootwk); /* Line 347, Address: 0x101dafc */
  shootwk->r_no0 += 2; /* Line 348, Address: 0x101db08 */
  soundset(145); /* Line 349, Address: 0x101db18 */
} /* Line 350, Address: 0x101db24 */


void shootermove3(act_info* shootwk) { /* Line 353, Address: 0x101db40 */
  unsigned char move_counter;
  unsigned short** move;
  unsigned short* movetbl;

  if ((char)--shootwk->actfree[4] < 0) { /* Line 358, Address: 0x101db58 */
    actwk[0].xposi.w.h = ((unsigned short*)shootwk)[29]; /* Line 359, Address: 0x101db84 */
    actwk[0].yposi.w.h = ((unsigned short*)shootwk)[30]; /* Line 360, Address: 0x101db94 */
    move_counter = shootwk->actfree[16] + 4; /* Line 361, Address: 0x101dba4 */
    if (move_counter < shootwk->actfree[17]) { /* Line 362, Address: 0x101dbbc */

      shootwk->actfree[16] = move_counter; /* Line 364, Address: 0x101dbd8 */
      move = ((unsigned short**)shootwk + 16); /* Line 365, Address: 0x101dbe0 */
      movetbl = *move; /* Line 366, Address: 0x101dbe8 */
      ((unsigned short*)shootwk)[29] = movetbl[move_counter / 2]; /* Line 367, Address: 0x101dbec */
      ((unsigned short*)shootwk)[30] = movetbl[move_counter / 2 + 1]; /* Line 368, Address: 0x101dc1c */
      shooterspdset(shootwk); /* Line 369, Address: 0x101dc50 */
      return; /* Line 370, Address: 0x101dc5c */
    }
  } else {
    actwk[0].xposi.l += actwk[0].xspeed.w << 8; /* Line 373, Address: 0x101dc64 */
    actwk[0].yposi.l += actwk[0].yspeed.w << 8; /* Line 374, Address: 0x101dc8c */
    return; /* Line 375, Address: 0x101dcb4 */
  }

  actwk[0].yposi.w.h &= 2047; /* Line 378, Address: 0x101dcbc */
  shootwk->r_no0 = 0; /* Line 379, Address: 0x101dcd0 */
  actwk[0].actfree[2] = 0; /* Line 380, Address: 0x101dcd8 */
} /* Line 381, Address: 0x101dce0 */


void shooterspdset(act_info* shootwk) { /* Line 384, Address: 0x101dd00 */
  short ms_work0, ms_work1, cal_position_x, cal_position_y;
  int cal_long_x, cal_long_y;

  ms_work0 = ms_work1 = actwk[0].mspeed.w; /* Line 388, Address: 0x101dd20 */
  cal_position_x = ((short*)shootwk)[29]; /* Line 389, Address: 0x101dd38 */
  cal_position_x -= actwk[0].xposi.w.h; /* Line 390, Address: 0x101dd48 */
  if (cal_position_x < 0) { /* Line 391, Address: 0x101dd5c */
    cal_position_x = -cal_position_x; /* Line 392, Address: 0x101dd6c */
    ms_work0 = -ms_work0; /* Line 393, Address: 0x101dd88 */
  }
  cal_position_y = ((short*)shootwk)[30]; /* Line 395, Address: 0x101dda4 */
  cal_position_y -= actwk[0].yposi.w.h; /* Line 396, Address: 0x101ddb4 */
  if (cal_position_y < 0) { /* Line 397, Address: 0x101ddc8 */
    cal_position_y = -cal_position_y; /* Line 398, Address: 0x101ddd8 */
    ms_work1 = -ms_work1; /* Line 399, Address: 0x101ddf4 */
  }
  if (cal_position_y <= cal_position_x) { /* Line 401, Address: 0x101de10 */

    cal_position_y = ((short*)shootwk)[30]; /* Line 403, Address: 0x101de2c */
    cal_position_y -= actwk[0].yposi.w.h; /* Line 404, Address: 0x101de3c */
    cal_long_y = cal_position_y << 16; /* Line 405, Address: 0x101de50 */
    cal_long_y /= ms_work1; /* Line 406, Address: 0x101de5c */

    cal_position_x = ((short*)shootwk)[29]; /* Line 408, Address: 0x101de78 */
    cal_position_x -= actwk[0].xposi.w.h; /* Line 409, Address: 0x101de88 */
    cal_long_x = cal_position_x << 16; /* Line 410, Address: 0x101de9c */
    if (cal_long_x != 0) cal_long_x /= cal_long_y; /* Line 411, Address: 0x101dea8 */

    actwk[0].xspeed.w = cal_long_x; /* Line 413, Address: 0x101dec4 */
    actwk[0].yspeed.w = ms_work1; /* Line 414, Address: 0x101ded4 */
    if (cal_long_y < 0) cal_long_y = -cal_long_y; /* Line 415, Address: 0x101dedc */
    shootwk->actfree[4] = cal_long_y >> 8; /* Line 416, Address: 0x101dee8 */
    shootwk->actfree[5] = cal_long_y & 255; /* Line 417, Address: 0x101def8 */
    return; /* Line 418, Address: 0x101df08 */
  }


  cal_position_x = ((short*)shootwk)[29]; /* Line 422, Address: 0x101df10 */
  cal_position_x -= actwk[0].xposi.w.h; /* Line 423, Address: 0x101df20 */
  cal_long_x = cal_position_x << 16; /* Line 424, Address: 0x101df34 */
  cal_long_x /= ms_work0; /* Line 425, Address: 0x101df40 */

  cal_position_y = ((short*)shootwk)[30]; /* Line 427, Address: 0x101df5c */
  cal_position_y -= actwk[0].yposi.w.h; /* Line 428, Address: 0x101df6c */
  cal_long_y = cal_position_y << 16; /* Line 429, Address: 0x101df80 */
  if (cal_long_y != 0) cal_long_y /= cal_long_x; /* Line 430, Address: 0x101df8c */

  actwk[0].yspeed.w = cal_long_y; /* Line 432, Address: 0x101dfa8 */
  actwk[0].xspeed.w = ms_work0; /* Line 433, Address: 0x101dfb8 */
  if (cal_long_x < 0) cal_long_x = -cal_long_x; /* Line 434, Address: 0x101dfc0 */
  shootwk->actfree[4] = cal_long_x >> 8; /* Line 435, Address: 0x101dfcc */
  shootwk->actfree[5] = cal_long_x & 255; /* Line 436, Address: 0x101dfdc */
} /* Line 437, Address: 0x101dfec */


void mspd_set(act_info* shootwk) { /* Line 440, Address: 0x101e010 */
  short mspdtbl[4] = { 4096, 3072, 3072, 2048 }; /* Line 441, Address: 0x101e01c */
  short cal_mspeed;

  actwk[0].mspeed.w = 4096; /* Line 444, Address: 0x101e048 */
  if (shootwk->userflag.b.h < 0) return; /* Line 445, Address: 0x101e054 */
  cal_mspeed = mspdtbl[shootwk->userflag.b.h & 15]; /* Line 446, Address: 0x101e06c */
  if (cal_mspeed > actwk[0].mspeed.w) actwk[0].mspeed.w = cal_mspeed; /* Line 447, Address: 0x101e094 */
} /* Line 448, Address: 0x101e0c0 */
