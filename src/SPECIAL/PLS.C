#include "..\TYPES.H"
#include "COMMON.H"
#include "SPS_EQU.H"
#include "PLS.H"
#include "ACT_S.H"
#include "COLI_S.H"
#include "ETC_S.H"
#include "GAME.H"
#include "SIN.H"

void(*pl_acttbl[24])(sprite_status_sp*) = {
  &play0, &play1, &play2, &play3, &play4, &play5, &play6, &play7,
  &play8, &play9, &play10, &play11, &play12, &play13, &play14, &play15,
  &play16, &play17, &play18, &play19, &play20, &play21, &play22, &play23
};
extern sprite_patterns_sp* mpplayer[];
extern sprite_patterns_sp* mpsibuki[];
static sprite_pattern kem00 = { 1, { { -4, -4, 0, 111 } } };
static sprite_pattern kem01 = { 1, { { -4, -4, 0, 112 } } };
static sprite_pattern kem02 = { 1, { { -4, -4, 0, 113 } } };
static sprite_patterns_sp kemuri00 = { 3, 1, { &kem00, &kem01, &kem02 } };
static sprite_patterns_sp* mpkemuri[1] = { &kemuri00 };
static sprite_pattern stn00 = { 1, { { -10, -24, 0, 114 } } };
static sprite_pattern stn01 = { 1, { { -10, -24, 0, 115 } } };
static sprite_pattern stn02 = { 1, { { -10, -24, 8, 115 } } };
static sprite_pattern stn03 = { 1, { { -10, -24, 0, 116 } } };
static sprite_pattern stn04 = { 1, { { -12, -24, 0, 117 } } };
static sprite_pattern stn05 = { 1, { { -12, -24, 16, 117 } } };
static sprite_pattern stn06 = { 1, { { -12, -24, 24, 117 } } };
static sprite_pattern stn07 = { 1, { { -12, -24, 8, 117 } } };
static sprite_pattern stn08 = { 1, { { -8, -16, 0, 118 } } };
static sprite_pattern stn09 = { 1, { { -8, -16, 16, 118 } } };
static sprite_pattern stn0a = { 1, { { -8, -16, 24, 118 } } };
static sprite_pattern stn0b = { 1, { { -8, -16, 8, 118 } } };
static sprite_patterns_sp stone00 = { 4, 3, { &stn00, &stn01, &stn03, &stn02 } };
static sprite_patterns_sp stone01 = { 4, 1, { &stn04, &stn05, &stn06, &stn07 } };
static sprite_patterns_sp stone02 = { 4, 1, { &stn0b, &stn0a, &stn09, &stn08 } };
static sprite_patterns_sp* mpstone[3] = { &stone00, &stone01, &stone02 };










void player(sprite_status_sp* plwk) { /* Line 49, Address: 0x1009ec0 */



  swdata_pl.w = swdata1.w; /* Line 53, Address: 0x1009ecc */
  speed_ud(plwk); /* Line 54, Address: 0x1009edc */
  plwk->actflg &= 219; /* Line 55, Address: 0x1009ee8 */
  plwk->spdcnt_max = 2560; /* Line 56, Address: 0x1009ef8 */
  pl_acttbl[plwk->exeno](plwk); /* Line 57, Address: 0x1009f04 */
  if (!(plwk->actflg & 8)) { /* Line 58, Address: 0x1009f30 */
    if (!(plwk->actflg & 192)) /* Line 59, Address: 0x1009f48 */

      if (game_start == 0) { /* Line 61, Address: 0x1009f60 */
        plcolli(plwk); /* Line 62, Address: 0x1009f74 */
        colli_evt(plwk); /* Line 63, Address: 0x1009f80 */
      }
    if (!(plwk->actflg & 32)) go_down(plwk); /* Line 65, Address: 0x1009f8c */
    if (plwk->x_posi.w.h < 832) plwk->x_posi.w.h = 832; /* Line 66, Address: 0x1009fb0 */
  }
  if (plwk->x_posi.w.h >= 3264) plwk->x_posi.w.h = 3264; /* Line 68, Address: 0x1009fd8 */
  if (plwk->y_posi.w.h < 832) plwk->y_posi.w.h = 832; /* Line 69, Address: 0x100a000 */
  if (plwk->y_posi.w.h >= 3264) plwk->y_posi.w.h = 3264; /* Line 70, Address: 0x100a028 */
  zoomwk.x = plwk->x_posi.w.h; /* Line 71, Address: 0x100a050 */
  zoomwk.y = plwk->y_posi.w.h; /* Line 72, Address: 0x100a060 */
  zoomwk.z = plwk->z_posi.w.h; /* Line 73, Address: 0x100a070 */
  zoomwk.ax = ((short*)plwk)[37]; /* Line 74, Address: 0x100a080 */
  zoomwk.az = ((short*)plwk)[39]; /* Line 75, Address: 0x100a090 */
  if (plwk->exeno != 7 && plwk->exeno != 19) { /* Line 76, Address: 0x100a0a0 */
    ptrlget(plwk); /* Line 77, Address: 0x100a0d0 */
    plptsel(plwk); /* Line 78, Address: 0x100a0dc */
  }
  patset(plwk); /* Line 80, Address: 0x100a0e8 */
  plcgchg(plwk); /* Line 81, Address: 0x100a0f4 */
  plwk->colliflg = 0; /* Line 82, Address: 0x100a100 */
} /* Line 83, Address: 0x100a108 */



void play0(sprite_status_sp* plwk) { /* Line 87, Address: 0x100a120 */

  plwk->pattbl = mpplayer; /* Line 89, Address: 0x100a12c */
  plwk->sx_posi.w.h = 256; /* Line 90, Address: 0x100a13c */
  plwk->sy_posi.w.h = 344; /* Line 91, Address: 0x100a148 */
  patinit(plwk, 9); /* Line 92, Address: 0x100a154 */
  plwk->exeno = 20; /* Line 93, Address: 0x100a164 */
  plwk->spdcnt = 0; /* Line 94, Address: 0x100a170 */
  init_xyget(plwk); /* Line 95, Address: 0x100a178 */
  plwk->z_posi.w.h = 352; /* Line 96, Address: 0x100a184 */
  ((short*)plwk)[37] = 128; /* Line 97, Address: 0x100a190 */
} /* Line 98, Address: 0x100a19c */


void play20(sprite_status_sp* plwk) { /* Line 101, Address: 0x100a1b0 */
  plwk->actno = plwk->actno; /* Line 102, Address: 0x100a1b8 */
} /* Line 103, Address: 0x100a1c8 */


void play21(sprite_status_sp* plwk) { /* Line 106, Address: 0x100a1e0 */
  patinit(plwk, 44); /* Line 107, Address: 0x100a1ec */
  plwk->exeno = 22; /* Line 108, Address: 0x100a1fc */
  plwk->actfree[17] = 5; /* Line 109, Address: 0x100a208 */
} /* Line 110, Address: 0x100a214 */


void play22(sprite_status_sp* plwk) { /* Line 113, Address: 0x100a230 */
  if (--plwk->actfree[17] == 0) { /* Line 114, Address: 0x100a23c */
    patinit(plwk, 10); /* Line 115, Address: 0x100a25c */
    plwk->exeno = 23; /* Line 116, Address: 0x100a26c */
  }
} /* Line 118, Address: 0x100a278 */


void play23(sprite_status_sp* plwk) { /* Line 121, Address: 0x100a290 */
  plwk->actno = plwk->actno; /* Line 122, Address: 0x100a298 */
} /* Line 123, Address: 0x100a2a8 */



void play1(sprite_status_sp* plwk) { /* Line 127, Address: 0x100a2c0 */
  rlmove(plwk); /* Line 128, Address: 0x100a2cc */
  jumpset(plwk); /* Line 129, Address: 0x100a2d8 */
  clear_chk(); /* Line 130, Address: 0x100a2e4 */
} /* Line 131, Address: 0x100a2ec */


void play2(sprite_status_sp* plwk) { /* Line 134, Address: 0x100a300 */
  plwk->sy_posi.l += plwk->sy_speed.l; /* Line 135, Address: 0x100a30c */
  plwk->sy_speed.l += 32767 + 8193; /* Line 136, Address: 0x100a324 */
  if (jmpswcnt != 0) { /* Line 137, Address: 0x100a338 */
    plwk->sy_speed.l += 32767 + 8193; /* Line 138, Address: 0x100a350 */
    --jmpswcnt; /* Line 139, Address: 0x100a364 */
    if (swdata_pl.b.h & 112) plwk->sy_speed.l -= 40960; /* Line 140, Address: 0x100a378 */
  }
  if (plwk->sy_posi.w.h >= 344) { /* Line 142, Address: 0x100a3a4 */
    plwk->exeno = 1; /* Line 143, Address: 0x100a3c0 */
    plwk->sy_posi.l = 22544384; /* Line 144, Address: 0x100a3cc */
    plwk->sy_speed.l = 0; /* Line 145, Address: 0x100a3d8 */
    plwk->actflg &= 127; /* Line 146, Address: 0x100a3e0 */
    plwk->z_posi.w.h = 352; /* Line 147, Address: 0x100a3f0 */
  }
  rlmove(plwk); /* Line 149, Address: 0x100a3fc */
  plwk->z_posi.w.h = (344 - plwk->sy_posi.w.h << 2) + 352; /* Line 150, Address: 0x100a408 */
} /* Line 151, Address: 0x100a438 */


void play3(sprite_status_sp* plwk) { /* Line 154, Address: 0x100a450 */
  plwk->sy_posi.l += plwk->sy_speed.l; /* Line 155, Address: 0x100a45c */
  plwk->sy_speed.l += 8192; /* Line 156, Address: 0x100a474 */
  if (plwk->sy_posi.w.h >= 344) { /* Line 157, Address: 0x100a484 */
    plwk->exeno = 1; /* Line 158, Address: 0x100a4a0 */
    plwk->sy_posi.l = 22544384; /* Line 159, Address: 0x100a4ac */
    plwk->sy_speed.l = 0; /* Line 160, Address: 0x100a4b8 */
    plwk->actflg &= 191; /* Line 161, Address: 0x100a4c0 */
    plwk->z_posi.w.h = 352; /* Line 162, Address: 0x100a4d0 */
  }
  rlmove(plwk); /* Line 164, Address: 0x100a4dc */
  plwk->z_posi.w.h = (344 - plwk->sy_posi.w.h << 2) + 352; /* Line 165, Address: 0x100a4e8 */
} /* Line 166, Address: 0x100a518 */


void play4(sprite_status_sp* plwk) { /* Line 169, Address: 0x100a530 */
  if (--plwk->spdcnt_shock == 0) { /* Line 170, Address: 0x100a53c */
    plwk->exeno = 1; /* Line 171, Address: 0x100a564 */
    plwk->x_speed.l = plwk->y_speed.l = 0; /* Line 172, Address: 0x100a570 */
  } else { /* Line 173, Address: 0x100a580 */
    plwk->x_posi.l += plwk->x_speed.l; /* Line 174, Address: 0x100a588 */
    plwk->y_posi.l += plwk->y_speed.l; /* Line 175, Address: 0x100a5a0 */
  }
  rlmove(plwk); /* Line 177, Address: 0x100a5b8 */
  jumpset(plwk); /* Line 178, Address: 0x100a5c4 */
  clear_chk(); /* Line 179, Address: 0x100a5d0 */
} /* Line 180, Address: 0x100a5d8 */


void play5(sprite_status_sp* plwk) { /* Line 183, Address: 0x100a5f0 */
  plwk->sy_posi.w.h += 4; /* Line 184, Address: 0x100a5f8 */
  if (plwk->sy_posi.w.h >= 448) plwk->exeno = 6; /* Line 185, Address: 0x100a608 */
} /* Line 186, Address: 0x100a630 */


void play6(sprite_status_sp* plwk) { /* Line 189, Address: 0x100a640 */
  plwk->actno = plwk->actno; /* Line 190, Address: 0x100a648 */
} /* Line 191, Address: 0x100a658 */


void play7(sprite_status_sp* plwk) { /* Line 194, Address: 0x100a670 */
  if (--plwk->actfree[17] == 0) { /* Line 195, Address: 0x100a67c */
    plwk->exeno = 1; /* Line 196, Address: 0x100a69c */
    patinit(plwk, 0); /* Line 197, Address: 0x100a6a8 */
  }
} /* Line 199, Address: 0x100a6b8 */


void play8(sprite_status_sp* plwk) { /* Line 202, Address: 0x100a6d0 */
  if (plwk->sy_posi.w.h >= 344) { /* Line 203, Address: 0x100a6dc */
    plwk->actfree[17] = 60; /* Line 204, Address: 0x100a6f8 */
    patinit(plwk, 10); /* Line 205, Address: 0x100a704 */
    plwk->exeno = 9; /* Line 206, Address: 0x100a714 */
    game_start = 1; /* Line 207, Address: 0x100a720 */
    plwk->spdcnt = 0; /* Line 208, Address: 0x100a72c */
  } else { /* Line 209, Address: 0x100a734 */
    rlmove(plwk); /* Line 210, Address: 0x100a73c */
    jumpset(plwk); /* Line 211, Address: 0x100a748 */
  }
} /* Line 213, Address: 0x100a754 */


void play9(sprite_status_sp* plwk) { /* Line 216, Address: 0x100a770 */
  if (--plwk->actfree[17] == 0) { /* Line 217, Address: 0x100a778 */
    actwk[5].actno = 14; /* Line 218, Address: 0x100a798 */
    actwk[6].actno = 15; /* Line 219, Address: 0x100a7a4 */
    actwk[7].actno = 16; /* Line 220, Address: 0x100a7b0 */
    plwk->exeno = 10; /* Line 221, Address: 0x100a7bc */
    plwk->actfree[17] = 6; /* Line 222, Address: 0x100a7c8 */
  }
} /* Line 224, Address: 0x100a7d4 */


void play10(sprite_status_sp* plwk) { /* Line 227, Address: 0x100a7e0 */
  rlscrflg |= 4; /* Line 228, Address: 0x100a7ec */
  ((unsigned short*)plwk)[39] -= 8; /* Line 229, Address: 0x100a800 */
  ((unsigned short*)plwk)[39] &= 511; /* Line 230, Address: 0x100a810 */
  if (--plwk->actfree[17] == 0) { /* Line 231, Address: 0x100a820 */
    plwk->exeno = 11; /* Line 232, Address: 0x100a840 */
    plwk->actfree[17] = 4; /* Line 233, Address: 0x100a84c */
    patinit(plwk, 36); /* Line 234, Address: 0x100a858 */
  }
} /* Line 236, Address: 0x100a868 */


void play11(sprite_status_sp* plwk) { /* Line 239, Address: 0x100a880 */
  rlscrflg |= 4; /* Line 240, Address: 0x100a88c */
  ((unsigned short*)plwk)[39] -= 8; /* Line 241, Address: 0x100a8a0 */
  ((unsigned short*)plwk)[39] &= 511; /* Line 242, Address: 0x100a8b0 */
  if (--plwk->actfree[17] == 0) { /* Line 243, Address: 0x100a8c0 */
    plwk->exeno = 12; /* Line 244, Address: 0x100a8e0 */
    plwk->actfree[17] = 5; /* Line 245, Address: 0x100a8ec */
    patinit(plwk, 37); /* Line 246, Address: 0x100a8f8 */
  }
} /* Line 248, Address: 0x100a908 */


void play12(sprite_status_sp* plwk) { /* Line 251, Address: 0x100a920 */
  rlscrflg |= 4; /* Line 252, Address: 0x100a92c */
  ((unsigned short*)plwk)[39] -= 8; /* Line 253, Address: 0x100a940 */
  ((unsigned short*)plwk)[39] &= 511; /* Line 254, Address: 0x100a950 */
  if (--plwk->actfree[17] == 0) { /* Line 255, Address: 0x100a960 */
    plwk->exeno = 13; /* Line 256, Address: 0x100a980 */
    plwk->actfree[17] = 4; /* Line 257, Address: 0x100a98c */
    patinit(plwk, 38); /* Line 258, Address: 0x100a998 */
  }
} /* Line 260, Address: 0x100a9a8 */


void play13(sprite_status_sp* plwk) { /* Line 263, Address: 0x100a9c0 */
  rlscrflg |= 4; /* Line 264, Address: 0x100a9cc */
  ((unsigned short*)plwk)[39] -= 8; /* Line 265, Address: 0x100a9e0 */
  ((unsigned short*)plwk)[39] &= 511; /* Line 266, Address: 0x100a9f0 */
  if (--plwk->actfree[17] == 0) { /* Line 267, Address: 0x100aa00 */
    plwk->exeno = 14; /* Line 268, Address: 0x100aa20 */
    plwk->actfree[17] = 5; /* Line 269, Address: 0x100aa2c */
    patinit(plwk, 39); /* Line 270, Address: 0x100aa38 */
  }
} /* Line 272, Address: 0x100aa48 */


void play14(sprite_status_sp* plwk) { /* Line 275, Address: 0x100aa60 */
  rlscrflg |= 4; /* Line 276, Address: 0x100aa6c */
  ((unsigned short*)plwk)[39] -= 8; /* Line 277, Address: 0x100aa80 */
  ((unsigned short*)plwk)[39] &= 511; /* Line 278, Address: 0x100aa90 */
  if (--plwk->actfree[17] == 0) { /* Line 279, Address: 0x100aaa0 */
    plwk->exeno = 15; /* Line 280, Address: 0x100aac0 */
    plwk->actfree[17] = 4; /* Line 281, Address: 0x100aacc */
    patinit(plwk, 40); /* Line 282, Address: 0x100aad8 */
  }
} /* Line 284, Address: 0x100aae8 */


void play15(sprite_status_sp* plwk) { /* Line 287, Address: 0x100ab00 */
  rlscrflg |= 4; /* Line 288, Address: 0x100ab0c */
  ((unsigned short*)plwk)[39] -= 8; /* Line 289, Address: 0x100ab20 */
  ((unsigned short*)plwk)[39] &= 511; /* Line 290, Address: 0x100ab30 */
  if (--plwk->actfree[17] == 0) { /* Line 291, Address: 0x100ab40 */
    plwk->exeno = 16; /* Line 292, Address: 0x100ab60 */
    plwk->actfree[17] = 5; /* Line 293, Address: 0x100ab6c */
    patinit(plwk, 41); /* Line 294, Address: 0x100ab78 */
  }
} /* Line 296, Address: 0x100ab88 */


void play16(sprite_status_sp* plwk) { /* Line 299, Address: 0x100aba0 */
  rlscrflg |= 4; /* Line 300, Address: 0x100abac */
  ((unsigned short*)plwk)[39] -= 8; /* Line 301, Address: 0x100abc0 */
  ((unsigned short*)plwk)[39] &= 511; /* Line 302, Address: 0x100abd0 */
  if (--plwk->actfree[17] == 0) { /* Line 303, Address: 0x100abe0 */
    plwk->exeno = 17; /* Line 304, Address: 0x100ac00 */
    patinit(plwk, 42); /* Line 305, Address: 0x100ac0c */
  }
} /* Line 307, Address: 0x100ac1c */


void play17(sprite_status_sp* plwk) { /* Line 310, Address: 0x100ac30 */
  plwk->actno = plwk->actno; /* Line 311, Address: 0x100ac38 */
} /* Line 312, Address: 0x100ac48 */


void play18(sprite_status_sp* plwk) { /* Line 315, Address: 0x100ac60 */
  patinit(plwk, 43); /* Line 316, Address: 0x100ac6c */
} /* Line 317, Address: 0x100ac7c */


void play19(sprite_status_sp* plwk) { /* Line 320, Address: 0x100ac90 */
  if (--plwk->spdcnt_shock == 0) { /* Line 321, Address: 0x100ac9c */
    plwk->exeno = 1; /* Line 322, Address: 0x100acc4 */
    plwk->x_speed.l = plwk->y_speed.l = 0; /* Line 323, Address: 0x100acd0 */
    patinit(plwk, 0); /* Line 324, Address: 0x100ace0 */
  } else { /* Line 325, Address: 0x100acf0 */
    plwk->x_posi.l += plwk->x_speed.l; /* Line 326, Address: 0x100acf8 */
    plwk->y_posi.l += plwk->y_speed.l; /* Line 327, Address: 0x100ad10 */
  }
  rlmove(plwk); /* Line 329, Address: 0x100ad28 */
  jumpset(plwk); /* Line 330, Address: 0x100ad34 */
} /* Line 331, Address: 0x100ad40 */





void init_xyget(sprite_status_sp* plwk) { /* Line 337, Address: 0x100ad50 */
  short tbl[24] = { /* Line 338, Address: 0x100ad58 */
    1344, 1312, 128,
    1280, 1280, 128,
    1280, 1280, 128,
    1280, 1280, 128,
    1280, 1280, 128,
    1216, 1216, 128,
    1280, 1280, 128,
    1024, 1152, 128
  };

  plwk->x_posi.w.h = tbl[stagenm * 3]; /* Line 349, Address: 0x100ad8c */
  plwk->y_posi.w.h = tbl[stagenm * 3 + 1]; /* Line 350, Address: 0x100adb4 */
  ((short*)plwk)[39] = tbl[stagenm * 3 + 2]; /* Line 351, Address: 0x100ade0 */
} /* Line 352, Address: 0x100ae0c */





void clear_chk(void) {
  if (ufoleft != 0) return; /* Line 359, Address: 0x100ae20 */
  actwk[0].exeno = 8; /* Line 360, Address: 0x100ae34 */
  if (actwk[39].actno != 0) actwk[39].actflg |= 1; /* Line 361, Address: 0x100ae40 */
  if (actwk[47].actno != 0) actwk[47].actflg |= 1; /* Line 362, Address: 0x100ae68 */
} /* Line 363, Address: 0x100ae90 */





void colli_evt(sprite_status_sp* plwk) { /* Line 369, Address: 0x100aea0 */
  unsigned char cal_jump_no;
  void(*jmptbl[10])(sprite_status_sp*) = { /* Line 371, Address: 0x100aeb0 */
    &noevt,
    &noevt,
    &evt01,
    &evt02,
    &evt03,
    &evt04,
    &evt05,
    &evt06,
    &evt07,
    &evt08
  };

  boundchk(plwk); /* Line 384, Address: 0x100aee4 */
  if (ufoleft == 0) return; /* Line 385, Address: 0x100aef0 */
  if ((cal_jump_no = plwk->scno_ce) >= 10) cal_jump_no = 0; /* Line 386, Address: 0x100af04 */
  jmptbl[cal_jump_no](plwk); /* Line 387, Address: 0x100af24 */
} /* Line 388, Address: 0x100af40 */


void noevt(sprite_status_sp* plwk) { /* Line 391, Address: 0x100af60 */
  plwk->actno = plwk->actno; /* Line 392, Address: 0x100af68 */
} /* Line 393, Address: 0x100af78 */


void evt08(sprite_status_sp* plwk) { /* Line 396, Address: 0x100af90 */
  plwk->actno = plwk->actno; /* Line 397, Address: 0x100af98 */
} /* Line 398, Address: 0x100afa8 */


void evt01(sprite_status_sp* plwk) { /* Line 401, Address: 0x100afc0 */
  plwk->exeno = 3; /* Line 402, Address: 0x100afcc */
  plwk->sy_speed.l = -0x40000; /* Line 403, Address: 0x100afd8 */
  plwk->actflg |= 64; /* Line 404, Address: 0x100afe4 */
  key_set(184); /* Line 405, Address: 0x100aff4 */
  sibuki_clr(); /* Line 406, Address: 0x100b000 */
} /* Line 407, Address: 0x100b008 */


void evt02(sprite_status_sp* plwk) { /* Line 410, Address: 0x100b020 */
  if (time_stop != 0) return; /* Line 411, Address: 0x100b028 */
  actwk[2].actno = 8; /* Line 412, Address: 0x100b03c */
  if (spgmmode & 2) plwk->spdcnt_max = 1280; /* Line 413, Address: 0x100b048 */
} /* Line 414, Address: 0x100b06c */



void evt03(sprite_status_sp* plwk) { /* Line 418, Address: 0x100b080 */
  sprite_status_sp* new_actwk;

  plwk->spdcnt_max = 1280; /* Line 421, Address: 0x100b08c */
  if (plwk->spdcnt < 256) return; /* Line 422, Address: 0x100b098 */
  if (k_search(&new_actwk) == 0) new_actwk->actno = 7; /* Line 423, Address: 0x100b0b4 */

  key_set(214); /* Line 425, Address: 0x100b0dc */
} /* Line 426, Address: 0x100b0e8 */


void evt04(sprite_status_sp* plwk) { /* Line 429, Address: 0x100b100 */
  plwk->exeno = 2; /* Line 430, Address: 0x100b10c */
  plwk->sy_speed.l = -0x100000; /* Line 431, Address: 0x100b118 */
  plwk->actflg |= 128; /* Line 432, Address: 0x100b124 */
  key_set(152); /* Line 433, Address: 0x100b134 */
  sibuki_clr(); /* Line 434, Address: 0x100b140 */
} /* Line 435, Address: 0x100b148 */


void evt05(sprite_status_sp* plwk) { /* Line 438, Address: 0x100b160 */
  short cal_ring;

  if (plwk->exeno == 4 || plwk->exeno == 7) return; /* Line 441, Address: 0x100b170 */
  plwk->actfree[17] = 46; /* Line 442, Address: 0x100b1a8 */
  plwk->exeno = 7; /* Line 443, Address: 0x100b1b4 */
  patinit(plwk, 13); /* Line 444, Address: 0x100b1c0 */
  cal_ring = ringno - (ringno >> 1); /* Line 445, Address: 0x100b1d0 */
  ringno >>= 1; /* Line 446, Address: 0x100b200 */
  if (cal_ring > 7) cal_ring = 7; /* Line 447, Address: 0x100b214 */
  if (cal_ring > 0) { /* Line 448, Address: 0x100b234 */
    key_set(148); /* Line 449, Address: 0x100b244 */
  }
  for ( ; cal_ring > 0; --cal_ring) actwk[24 - cal_ring].actno = 13; /* Line 451, Address: 0x100b250 */
} /* Line 452, Address: 0x100b2a4 */


void evt06(sprite_status_sp* plwk) { /* Line 455, Address: 0x100b2c0 */
  void(*tbl[8])(sprite_status_sp*) = { /* Line 456, Address: 0x100b2cc */
    &tobi_b0, &tobi_b2, &tobi_b4, &tobi_b6,
    &tobi_b0, &tobi_b6, &tobi_b4, &tobi_b2
  };

  key_set(206); /* Line 461, Address: 0x100b300 */
  patinit(plwk, 14); /* Line 462, Address: 0x100b30c */

  tbl[(plwk->scno_sdir & 14) / 2](plwk); /* Line 464, Address: 0x100b31c */
} /* Line 465, Address: 0x100b35c */


void tobi_b0(sprite_status_sp* plwk) { /* Line 468, Address: 0x100b370 */
  tobi_b(plwk, 0, -24); /* Line 469, Address: 0x100b37c */
} /* Line 470, Address: 0x100b390 */


void tobi_b2(sprite_status_sp* plwk) { /* Line 473, Address: 0x100b3a0 */
  tobi_b(plwk, -24, 0); /* Line 474, Address: 0x100b3ac */
} /* Line 475, Address: 0x100b3c0 */


void tobi_b4(sprite_status_sp* plwk) { /* Line 478, Address: 0x100b3d0 */
  tobi_b(plwk, 0, 24); /* Line 479, Address: 0x100b3dc */
} /* Line 480, Address: 0x100b3f0 */


void tobi_b6(sprite_status_sp* plwk) { /* Line 483, Address: 0x100b400 */
  tobi_b(plwk, 24, 0); /* Line 484, Address: 0x100b40c */
} /* Line 485, Address: 0x100b420 */


void tobi_b(sprite_status_sp* plwk, short cal_x, short cal_y) { /* Line 488, Address: 0x100b430 */
  plwk->x_speed.w.h = cal_x; /* Line 489, Address: 0x100b440 */
  plwk->y_speed.w.h = cal_y; /* Line 490, Address: 0x100b44c */
  plwk->spdcnt_shock = 20; /* Line 491, Address: 0x100b458 */
  plwk->exeno = 19; /* Line 492, Address: 0x100b464 */
} /* Line 493, Address: 0x100b470 */


void evt07(sprite_status_sp* plwk) { /* Line 496, Address: 0x100b480 */
  void(*tbl[8])(sprite_status_sp*) = { /* Line 497, Address: 0x100b48c */
    &tobi_s0, &tobi_s2, &tobi_s4, &tobi_s6,
    &tobi_s0, &tobi_s6, &tobi_s4, &tobi_s2
  };

  key_set(195); /* Line 502, Address: 0x100b4c0 */

  tbl[(plwk->scno_sdir & 14) / 2](plwk); /* Line 504, Address: 0x100b4cc */
} /* Line 505, Address: 0x100b50c */


void tobi_s0(sprite_status_sp* plwk) { /* Line 508, Address: 0x100b520 */
  tobi_s(plwk, 0, -16); /* Line 509, Address: 0x100b52c */
} /* Line 510, Address: 0x100b540 */


void tobi_s2(sprite_status_sp* plwk) { /* Line 513, Address: 0x100b550 */
  tobi_s(plwk, -16, 0); /* Line 514, Address: 0x100b55c */
} /* Line 515, Address: 0x100b570 */


void tobi_s4(sprite_status_sp* plwk) { /* Line 518, Address: 0x100b580 */
  tobi_s(plwk, 0, 16); /* Line 519, Address: 0x100b58c */
} /* Line 520, Address: 0x100b5a0 */


void tobi_s6(sprite_status_sp* plwk) { /* Line 523, Address: 0x100b5b0 */
  tobi_s(plwk, 16, 0); /* Line 524, Address: 0x100b5bc */
} /* Line 525, Address: 0x100b5d0 */


void tobi_s(sprite_status_sp* plwk, short cal_x, short cal_y) { /* Line 528, Address: 0x100b5e0 */
  plwk->x_speed.w.h = cal_x; /* Line 529, Address: 0x100b5f0 */
  plwk->y_speed.w.h = cal_y; /* Line 530, Address: 0x100b5fc */
  plwk->spdcnt_shock = 8; /* Line 531, Address: 0x100b608 */
  plwk->exeno = 4; /* Line 532, Address: 0x100b614 */
} /* Line 533, Address: 0x100b620 */


void boundchk(sprite_status_sp* plwk) { /* Line 536, Address: 0x100b630 */
  short branch_d0;
  int speed_d1, speed_d2, speed_d3;

  speed_d1 = (plwk->spdcnt << 8) + 0x20000; /* Line 540, Address: 0x100b64c */
  speed_d2 = -speed_d1; /* Line 541, Address: 0x100b668 */
  speed_d3 = 0; /* Line 542, Address: 0x100b66c */

  branch_d0 = 0; /* Line 544, Address: 0x100b670 */
  if (plwk->scno_ul == 1) branch_d0 |= 1; /* Line 545, Address: 0x100b674 */
  if (plwk->scno_ur == 1) branch_d0 |= 2; /* Line 546, Address: 0x100b698 */
  if (plwk->scno_dr == 1) branch_d0 |= 4; /* Line 547, Address: 0x100b6bc */
  if (plwk->scno_dl == 1) branch_d0 |= 8; /* Line 548, Address: 0x100b6e0 */

  switch (branch_d0) { /* Line 550, Address: 0x100b704 */
    case 1:
      plwk->x_speed.l = plwk->y_speed.l = speed_d1; /* Line 552, Address: 0x100b734 */
      break; /* Line 553, Address: 0x100b744 */
    case 2:
      plwk->x_speed.l = speed_d2; /* Line 555, Address: 0x100b74c */
      plwk->y_speed.l = speed_d1; /* Line 556, Address: 0x100b754 */
      break; /* Line 557, Address: 0x100b75c */
    case 3:
      plwk->x_speed.l = speed_d3; /* Line 559, Address: 0x100b764 */
      plwk->y_speed.l = speed_d1; /* Line 560, Address: 0x100b76c */
      break; /* Line 561, Address: 0x100b774 */
    case 4:
      plwk->x_speed.l = plwk->y_speed.l = speed_d2; /* Line 563, Address: 0x100b77c */
      break; /* Line 564, Address: 0x100b78c */
    case 5:
      plwk->x_speed.l = speed_d1; /* Line 566, Address: 0x100b794 */
      plwk->y_speed.l = speed_d2; /* Line 567, Address: 0x100b79c */
      break; /* Line 568, Address: 0x100b7a4 */
    case 6:
      plwk->x_speed.l = speed_d2; /* Line 570, Address: 0x100b7ac */
      plwk->y_speed.l = speed_d3; /* Line 571, Address: 0x100b7b4 */
      break; /* Line 572, Address: 0x100b7bc */
    case 7:
      plwk->x_speed.l = speed_d2; /* Line 574, Address: 0x100b7c4 */
      plwk->y_speed.l = speed_d1; /* Line 575, Address: 0x100b7cc */
      break; /* Line 576, Address: 0x100b7d4 */
    case 8:
      plwk->x_speed.l = speed_d1; /* Line 578, Address: 0x100b7dc */
      plwk->y_speed.l = speed_d2; /* Line 579, Address: 0x100b7e4 */
      break; /* Line 580, Address: 0x100b7ec */
    case 9:
      plwk->x_speed.l = speed_d1; /* Line 582, Address: 0x100b7f4 */
      plwk->y_speed.l = speed_d3; /* Line 583, Address: 0x100b7fc */
      break; /* Line 584, Address: 0x100b804 */
    case 10:
      plwk->x_speed.l = plwk->y_speed.l = speed_d2; /* Line 586, Address: 0x100b80c */
      break; /* Line 587, Address: 0x100b81c */
    case 11:
      plwk->x_speed.l = plwk->y_speed.l = speed_d1; /* Line 589, Address: 0x100b824 */
      break; /* Line 590, Address: 0x100b834 */
    case 12:
      plwk->x_speed.l = speed_d3; /* Line 592, Address: 0x100b83c */
      plwk->y_speed.l = speed_d2; /* Line 593, Address: 0x100b844 */
      break; /* Line 594, Address: 0x100b84c */
    case 13:
      plwk->x_speed.l = speed_d1; /* Line 596, Address: 0x100b854 */
      plwk->y_speed.l = speed_d2; /* Line 597, Address: 0x100b85c */
      break; /* Line 598, Address: 0x100b864 */
    case 14:
      plwk->x_speed.l = plwk->y_speed.l = speed_d2; /* Line 600, Address: 0x100b86c */
      break; /* Line 601, Address: 0x100b87c */
    case 15:
      plwk->x_speed.l = plwk->y_speed.l = speed_d2; /* Line 603, Address: 0x100b884 */
      break;
  }


  if (branch_d0 == 0) return; /* Line 608, Address: 0x100b894 */

  plwk->spdcnt_shock = 16; /* Line 610, Address: 0x100b8a4 */
  plwk->exeno = 4; /* Line 611, Address: 0x100b8b0 */
  plwk->actflg |= 32; /* Line 612, Address: 0x100b8bc */
  key_set(181); /* Line 613, Address: 0x100b8cc */
  patinit(plwk, 0); /* Line 614, Address: 0x100b8d8 */
} /* Line 615, Address: 0x100b8e8 */





short k_search(sprite_status_sp** new_actwk) { /* Line 621, Address: 0x100b910 */
  short i;

  for (i = 8; i < 16; ++i) /* Line 624, Address: 0x100b91c */
    if ((*new_actwk = &actwk[i])->actno == 0) return 0; /* Line 625, Address: 0x100b930 */
  return -1; /* Line 626, Address: 0x100b994 */
} /* Line 627, Address: 0x100b998 */





void jumpset(sprite_status_sp* plwk) { /* Line 633, Address: 0x100b9b0 */
  if (game_start != 0) return; /* Line 634, Address: 0x100b9bc */
  if (!(swdata_pl.b.l & 112)) return; /* Line 635, Address: 0x100b9d0 */
  plwk->exeno = 2; /* Line 636, Address: 0x100b9e8 */
  plwk->sy_speed.l = -524288; /* Line 637, Address: 0x100b9f4 */
  jmpswcnt = 20; /* Line 638, Address: 0x100ba00 */
  plwk->actflg |= 128; /* Line 639, Address: 0x100ba0c */
  plwk->spdcnt_shock = 0; /* Line 640, Address: 0x100ba1c */
  key_set(146); /* Line 641, Address: 0x100ba24 */
  sibuki_clr(); /* Line 642, Address: 0x100ba30 */
} /* Line 643, Address: 0x100ba38 */





void rlmove(sprite_status_sp* plwk) { /* Line 649, Address: 0x100ba50 */
  if (game_start != 0) return; /* Line 650, Address: 0x100ba58 */
  if (swdata_pl.b.h & 8) { /* Line 651, Address: 0x100ba6c */
    ((int*)plwk)[19] -= 393216; /* Line 652, Address: 0x100ba84 */
    ((int*)plwk)[19] &= 33554431; /* Line 653, Address: 0x100ba98 */
    rlscrflg |= 8; /* Line 654, Address: 0x100baac */
  }
  if (swdata_pl.b.h & 4) { /* Line 656, Address: 0x100bac0 */
    ((int*)plwk)[19] += 393216; /* Line 657, Address: 0x100bad8 */
    ((int*)plwk)[19] &= 33554431; /* Line 658, Address: 0x100baec */
    rlscrflg |= 4; /* Line 659, Address: 0x100bb00 */
  }
} /* Line 661, Address: 0x100bb14 */


void rlmove_j(sprite_status_sp* plwk) { /* Line 664, Address: 0x100bb20 */
  if (game_start != 0) return; /* Line 665, Address: 0x100bb28 */
  if (swdata_pl.b.h & 8) { /* Line 666, Address: 0x100bb3c */
    ((int*)plwk)[19] -= 0x40000; /* Line 667, Address: 0x100bb54 */
    ((int*)plwk)[19] &= 33554431; /* Line 668, Address: 0x100bb68 */
    rlscrflg |= 8; /* Line 669, Address: 0x100bb7c */
  }
  if (swdata_pl.b.h & 4) { /* Line 671, Address: 0x100bb90 */
    ((int*)plwk)[19] += 0x40000; /* Line 672, Address: 0x100bba8 */
    ((int*)plwk)[19] &= 33554431; /* Line 673, Address: 0x100bbbc */
    rlscrflg |= 4; /* Line 674, Address: 0x100bbd0 */
  }
} /* Line 676, Address: 0x100bbe4 */





void speed_ud(sprite_status_sp* plwk) { /* Line 682, Address: 0x100bbf0 */
  short max_speed;

  if (game_start != 0) return; /* Line 685, Address: 0x100bbfc */
  if ((swdata_pl.b.h & 15) != 2) { /* Line 686, Address: 0x100bc10 */
    if (((short*)plwk)[45] != 0) { /* Line 687, Address: 0x100bc2c */
      --((short*)plwk)[45]; /* Line 688, Address: 0x100bc44 */
      max_speed = 3584; /* Line 689, Address: 0x100bc54 */
    } else { /* Line 690, Address: 0x100bc60 */
      if (plwk->exeno == 7) max_speed = 512; /* Line 691, Address: 0x100bc68 */
      else max_speed = plwk->spdcnt_max; /* Line 692, Address: 0x100bc94 */
    }
    plwk->spdcnt += 32; /* Line 694, Address: 0x100bca4 */
    if (max_speed < plwk->spdcnt) plwk->spdcnt = max_speed; /* Line 695, Address: 0x100bcb4 */
    return; /* Line 696, Address: 0x100bce0 */
  }

  plwk->spdcnt -= 64; /* Line 699, Address: 0x100bce8 */
  if (plwk->spdcnt < 512) plwk->spdcnt = 512; /* Line 700, Address: 0x100bcf8 */
} /* Line 701, Address: 0x100bd20 */


void go_down(sprite_status_sp* plwk) { /* Line 704, Address: 0x100bd30 */
  go_x_plus(plwk, 384, plwk->spdcnt); /* Line 705, Address: 0x100bd3c */

} /* Line 707, Address: 0x100bd54 */


void go_up(sprite_status_sp* plwk) { /* Line 710, Address: 0x100bd70 */
  go_x_plus(plwk, 128, plwk->spdcnt_shock); /* Line 711, Address: 0x100bd7c */
} /* Line 712, Address: 0x100bd94 */


void go_right(sprite_status_sp* plwk) { /* Line 715, Address: 0x100bdb0 */
  go_x_plus(plwk, 0, plwk->spdcnt_shock); /* Line 716, Address: 0x100bdbc */
} /* Line 717, Address: 0x100bdd4 */


void go_left(sprite_status_sp* plwk) { /* Line 720, Address: 0x100bdf0 */
  go_x_plus(plwk, 256, plwk->spdcnt_shock); /* Line 721, Address: 0x100bdfc */
} /* Line 722, Address: 0x100be14 */


void go_x_plus(sprite_status_sp* plwk, unsigned short cal_plus, short cal_speed) { /* Line 725, Address: 0x100be30 */
  short cal_z_kaku;
  int cal_plus_position;

  cal_z_kaku = ((unsigned short*)plwk)[39] + cal_plus; /* Line 729, Address: 0x100be4c */
  cal_z_kaku &= 511; /* Line 730, Address: 0x100be74 */
  cal_plus_position = sp_cos(cal_z_kaku); /* Line 731, Address: 0x100be80 */
  cal_plus_position *= cal_speed; /* Line 732, Address: 0x100be94 */
  plwk->x_posi.l += cal_plus_position; /* Line 733, Address: 0x100bea4 */
  plwk->x_posi.l = plwk->x_posi.l & 0xFFFFFFF; /* Line 734, Address: 0x100beb4 */
  cal_plus_position = sp_sin(cal_z_kaku); /* Line 735, Address: 0x100becc */
  cal_plus_position *= cal_speed; /* Line 736, Address: 0x100bee0 */
  plwk->y_posi.l += cal_plus_position; /* Line 737, Address: 0x100bef0 */
  plwk->y_posi.l = plwk->y_posi.l & 0xFFFFFFF; /* Line 738, Address: 0x100bf00 */
} /* Line 739, Address: 0x100bf18 */





void ptrlget(sprite_status_sp* plwk) { /* Line 745, Address: 0x100bf30 */
  if (swdata_pl.b.h & 4) { /* Line 746, Address: 0x100bf38 */
    if ((char)--plwk->actfree[16] < 0) plwk->actfree[16] = 0; /* Line 747, Address: 0x100bf50 */
    return; /* Line 748, Address: 0x100bf84 */
  }
  if (swdata_pl.b.h & 8) { /* Line 750, Address: 0x100bf8c */
    if (++plwk->actfree[16] >= 10) plwk->actfree[16] = 9; /* Line 751, Address: 0x100bfa4 */
    return; /* Line 752, Address: 0x100bfd4 */
  }








  plwk->actfree[16] = 5; /* Line 762, Address: 0x100bfdc */
} /* Line 763, Address: 0x100bfe8 */





void plptsel(sprite_status_sp* plwk) { /* Line 769, Address: 0x100c000 */
  unsigned char cal_pattblno;
  unsigned char tbl[20] = { /* Line 771, Address: 0x100c010 */
    4, 25, 26, 27,
    3, 22, 23, 24,
    0, 16, 17, 18,
    2, 19, 20, 21,
    5, 28, 29, 30
  };

  if (game_start != 0) return; /* Line 779, Address: 0x100c044 */
  cal_pattblno = 6; /* Line 780, Address: 0x100c058 */
  if (plwk->actflg & 128) goto label1; /* Line 781, Address: 0x100c060 */
  cal_pattblno = 11; /* Line 782, Address: 0x100c078 */
  if (plwk->actflg & 64) goto label1; /* Line 783, Address: 0x100c080 */
  cal_pattblno = 10; /* Line 784, Address: 0x100c098 */
  if (plwk->spdcnt == 0) goto label1; /* Line 785, Address: 0x100c0a0 */
  cal_pattblno = tbl[(plwk->actfree[16] * 2 & 28) + 3]; /* Line 786, Address: 0x100c0b8 */
  if (plwk->spdcnt < 768) goto label3; /* Line 787, Address: 0x100c0dc */
  cal_pattblno = tbl[(plwk->actfree[16] * 2 & 28) + 2]; /* Line 788, Address: 0x100c0f8 */
  if (plwk->spdcnt < 1344) goto label3; /* Line 789, Address: 0x100c11c */
  cal_pattblno = tbl[(plwk->actfree[16] * 2 & 28) + 1]; /* Line 790, Address: 0x100c138 */
  if (plwk->spdcnt < 1920) goto label3; /* Line 791, Address: 0x100c15c */
  cal_pattblno = tbl[plwk->actfree[16] * 2 & 28]; /* Line 792, Address: 0x100c178 */
  if (plwk->spdcnt < 2816) goto label3; /* Line 793, Address: 0x100c198 */
  cal_pattblno = 1; /* Line 794, Address: 0x100c1b4 */
  goto label2; /* Line 795, Address: 0x100c1bc */

label1:
  plwk->actflg &= 239; /* Line 798, Address: 0x100c1c4 */
label2:
  if (cal_pattblno != plwk->pattblno) patinit(plwk, cal_pattblno); /* Line 800, Address: 0x100c1d4 */
  return; /* Line 801, Address: 0x100c1fc */
label3:
  if (!(plwk->actflg & 16)) { /* Line 803, Address: 0x100c204 */
    plwk->actflg |= 16; /* Line 804, Address: 0x100c21c */
    goto label2; /* Line 805, Address: 0x100c22c */
  }
  if (cal_pattblno != plwk->pattblno) patinit1(plwk, cal_pattblno); /* Line 807, Address: 0x100c234 */
} /* Line 808, Address: 0x100c25c */







void plcgchg(sprite_status_sp* plwk) { /* Line 816, Address: 0x100c270 */
  plwk->actno = plwk->actno; /* Line 817, Address: 0x100c278 */
} /* Line 818, Address: 0x100c288 */







void sibuki(sprite_status_sp* sibukiwk) { /* Line 826, Address: 0x100c2a0 */
  void(*acttbl[3])(sprite_status_sp*) = { /* Line 827, Address: 0x100c2ac */
    &sibuki0,
    &sibuki1,
    &sibuki2
  };

  acttbl[sibukiwk->exeno](sibukiwk); /* Line 833, Address: 0x100c2d0 */
  patset(sibukiwk); /* Line 834, Address: 0x100c2f4 */
  if (time_stop != 0) sibukiwk->actflg |= 1; /* Line 835, Address: 0x100c300 */
} /* Line 836, Address: 0x100c324 */



void sibuki0(sprite_status_sp* sibukiwk) { /* Line 840, Address: 0x100c340 */

  sibukiwk->pattbl = mpsibuki; /* Line 842, Address: 0x100c34c */
  sibukiwk->sx_posi.w.h = 256; /* Line 843, Address: 0x100c35c */
  sibukiwk->sy_posi.w.h = 344; /* Line 844, Address: 0x100c368 */
  patinit(sibukiwk, 0); /* Line 845, Address: 0x100c374 */
  ((short*)sibukiwk)[36] = 14; /* Line 846, Address: 0x100c384 */
  ++sibukiwk->exeno; /* Line 847, Address: 0x100c390 */
  key_set(162); /* Line 848, Address: 0x100c3a0 */
  if (!(spgmmode & 2)) tdecflg = 10; /* Line 849, Address: 0x100c3ac */
  sibuki1(sibukiwk); /* Line 850, Address: 0x100c3d0 */
} /* Line 851, Address: 0x100c3dc */


void sibuki1(sprite_status_sp* sibukiwk) { /* Line 854, Address: 0x100c3f0 */
  if (--((short*)sibukiwk)[36] != 0) return; /* Line 855, Address: 0x100c3fc */
  if (actwk[0].scno_ce != 3) { sibukiwk->actflg |= 1; return; } /* Line 856, Address: 0x100c424 */
  patinit(sibukiwk, 1); /* Line 857, Address: 0x100c454 */
  sibukiwk->exeno = 2; /* Line 858, Address: 0x100c464 */
} /* Line 859, Address: 0x100c470 */


void sibuki2(sprite_status_sp* sibukiwk) { /* Line 862, Address: 0x100c480 */
  if (actwk[0].scno_ce != 3) sibukiwk->actflg |= 1; /* Line 863, Address: 0x100c488 */
  else if (sibukiwk->patno == 0) tdecflg = 2; /* Line 864, Address: 0x100c4b8 */
} /* Line 865, Address: 0x100c4d8 */


void sibuki_clr(void) {
  if (actwk[2].actno != 0) actwk[2].actflg |= 1; /* Line 869, Address: 0x100c4f0 */
} /* Line 870, Address: 0x100c518 */
















void kemuri(sprite_status_sp* kemuriwk) { /* Line 887, Address: 0x100c520 */
  void(*acttbl[2])(sprite_status_sp*) = { /* Line 888, Address: 0x100c52c */
    &kemuri0,
    &kemuri1
  };

  acttbl[kemuriwk->exeno](kemuriwk); /* Line 893, Address: 0x100c548 */
  patset(kemuriwk); /* Line 894, Address: 0x100c56c */
} /* Line 895, Address: 0x100c578 */



void kemuri0(sprite_status_sp* kemuriwk) { /* Line 899, Address: 0x100c590 */
  uint_union cal_random;


  kemuriwk->pattbl = mpkemuri; /* Line 903, Address: 0x100c59c */
  kemuriwk->sx_posi.w.h = 240; /* Line 904, Address: 0x100c5ac */
  kemuriwk->sy_posi.w.h = 340; /* Line 905, Address: 0x100c5b8 */
  patinit(kemuriwk, 0); /* Line 906, Address: 0x100c5c4 */
  ((short*)kemuriwk)[36] = 6; /* Line 907, Address: 0x100c5d4 */
  ++kemuriwk->exeno; /* Line 908, Address: 0x100c5e0 */
  cal_random.l = random(); /* Line 909, Address: 0x100c5f0 */
  kemuriwk->sx_posi.w.h += cal_random.w.l & 31; /* Line 910, Address: 0x100c5fc */
  kemuriwk->sy_posi.w.h += cal_random.w.l & 7; /* Line 911, Address: 0x100c620 */
  if (swdata_pl.b.h & 4) kemuriwk->sx_speed.w.h = 3; /* Line 912, Address: 0x100c644 */
  else if (swdata_pl.b.h & 8) kemuriwk->sx_speed.w.h = -3; /* Line 913, Address: 0x100c670 */
  else kemuriwk->sx_speed.w.h = 0; /* Line 914, Address: 0x100c69c */
  kemuri1(kemuriwk); /* Line 915, Address: 0x100c6a4 */
} /* Line 916, Address: 0x100c6b0 */


void kemuri1(sprite_status_sp* kemuriwk) { /* Line 919, Address: 0x100c6c0 */
  if (--((short*)kemuriwk)[36] == 0) kemuriwk->actflg |= 1; /* Line 920, Address: 0x100c6c8 */
  kemuriwk->sx_posi.l += kemuriwk->sx_speed.l; /* Line 921, Address: 0x100c700 */
  --kemuriwk->sy_posi.l; /* Line 922, Address: 0x100c718 */
} /* Line 923, Address: 0x100c728 */































void time_stone(sprite_status_sp* stonewk) { /* Line 955, Address: 0x100c740 */
  void(*acttbl[4])(sprite_status_sp*) = { /* Line 956, Address: 0x100c74c */
    &t_stone0,
    &t_stone1,
    &t_stone2,
    &t_stone3
  };

  acttbl[stonewk->exeno](stonewk); /* Line 963, Address: 0x100c778 */
  patset(stonewk); /* Line 964, Address: 0x100c79c */
} /* Line 965, Address: 0x100c7a8 */



void t_stone0(sprite_status_sp* stonewk) { /* Line 969, Address: 0x100c7c0 */

  stonewk->pattbl = mpstone; /* Line 971, Address: 0x100c7cc */
  stonewk->sx_posi.w.h = 257; /* Line 972, Address: 0x100c7dc */
  stonewk->sy_posi.w.h = 112; /* Line 973, Address: 0x100c7e8 */
  patinit(stonewk, 0); /* Line 974, Address: 0x100c7f4 */
  ((short*)stonewk)[36] = 30; /* Line 975, Address: 0x100c804 */
  ++stonewk->exeno; /* Line 976, Address: 0x100c810 */
  t_stone1(stonewk); /* Line 977, Address: 0x100c820 */
} /* Line 978, Address: 0x100c82c */


void t_stone1(sprite_status_sp* stonewk) { /* Line 981, Address: 0x100c840 */
  if (--((short*)stonewk)[36] == 0) ++stonewk->exeno; /* Line 982, Address: 0x100c848 */
} /* Line 983, Address: 0x100c880 */


void t_stone2(sprite_status_sp* stonewk) { /* Line 986, Address: 0x100c890 */
  stonewk->sy_posi.w.h += 4; /* Line 987, Address: 0x100c89c */
  if (stonewk->sy_posi.w.h < 336) return; /* Line 988, Address: 0x100c8ac */
  ++stonewk->exeno; /* Line 989, Address: 0x100c8c8 */
  actwk[6].actflg |= 1; actwk[7].actflg |= 1; /* Line 990, Address: 0x100c8d8 */
  ((short*)stonewk)[36] = 60; /* Line 991, Address: 0x100c900 */
  actwk[0].exeno = 18; /* Line 992, Address: 0x100c90c */
  key_set(217); /* Line 993, Address: 0x100c918 */
} /* Line 994, Address: 0x100c924 */


void t_stone3(sprite_status_sp* stonewk) { /* Line 997, Address: 0x100c940 */
  if (--((short*)stonewk)[36] == 0) gmclrflg = 1; /* Line 998, Address: 0x100c948 */
} /* Line 999, Address: 0x100c97c */





void tskira0(sprite_status_sp* kirawk) { /* Line 1005, Address: 0x100c990 */
  void(*acttbl[2])(sprite_status_sp*) = { /* Line 1006, Address: 0x100c99c */
    &tskira00,
    &tskira01
  };

  acttbl[kirawk->exeno](kirawk); /* Line 1011, Address: 0x100c9b8 */
  patset(kirawk); /* Line 1012, Address: 0x100c9dc */
} /* Line 1013, Address: 0x100c9e8 */



void tskira00(sprite_status_sp* kirawk) { /* Line 1017, Address: 0x100ca00 */

  kirawk->pattbl = mpstone; /* Line 1019, Address: 0x100ca0c */
  patinit(kirawk, 1); /* Line 1020, Address: 0x100ca1c */
  ++kirawk->exeno; /* Line 1021, Address: 0x100ca2c */
  tskira01(kirawk); /* Line 1022, Address: 0x100ca3c */
} /* Line 1023, Address: 0x100ca48 */


void tskira01(sprite_status_sp* kirawk) { /* Line 1026, Address: 0x100ca60 */
  kirawk->sx_posi.w.h = actwk[5].sx_posi.w.h; /* Line 1027, Address: 0x100ca68 */
  kirawk->sy_posi.w.h = actwk[5].sy_posi.w.h - 16; /* Line 1028, Address: 0x100ca78 */
} /* Line 1029, Address: 0x100ca9c */





void tskira1(sprite_status_sp* kirawk) { /* Line 1035, Address: 0x100cab0 */
  void(*acttbl[2])(sprite_status_sp*) = { /* Line 1036, Address: 0x100cabc */
    &tskira10,
    &tskira11
  };

  acttbl[kirawk->exeno](kirawk); /* Line 1041, Address: 0x100cad8 */
  patset(kirawk); /* Line 1042, Address: 0x100cafc */
} /* Line 1043, Address: 0x100cb08 */


void tskira10(sprite_status_sp* kirawk) { /* Line 1046, Address: 0x100cb20 */

  kirawk->pattbl = mpstone; /* Line 1048, Address: 0x100cb2c */
  patinit(kirawk, 2); /* Line 1049, Address: 0x100cb3c */
  ++kirawk->exeno; /* Line 1050, Address: 0x100cb4c */
  tskira11(kirawk); /* Line 1051, Address: 0x100cb5c */
} /* Line 1052, Address: 0x100cb68 */


void tskira11(sprite_status_sp* kirawk) { /* Line 1055, Address: 0x100cb80 */
  kirawk->sx_posi.w.h = actwk[5].sx_posi.w.h; /* Line 1056, Address: 0x100cb88 */
  kirawk->sy_posi.w.h = actwk[5].sy_posi.w.h - 32; /* Line 1057, Address: 0x100cb98 */
} /* Line 1058, Address: 0x100cbbc */
