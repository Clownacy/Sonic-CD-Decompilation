#include "EQU.H"
#include "RING.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "DIRCOL.H"
#include "ETC.H"
#include "PLAYSUB.H"

extern void soundset(short ReqNo);
extern void sub_sync(short ReqNo);

spr_array ringsp0 = {
  1,
  { { -8, -8, 0, 310 } }
};
spr_array ringsp1 = {
  1,
  { { -8, -8, 0, 311 } }
};
spr_array ringsp2 = {
  1,
  { { -4, -8, 0, 312 } }
};
spr_array ringsp3 = {
  1,
  { { -8, -8, 0, 313 } }
};
spr_array ringsp4 = {
  1,
  { { -8, -8, 0, 314 } }
};
spr_array ringsp5 = {
  1,
  { { -8, -8, 0, 315 } }
};
spr_array ringsp6 = {
  1,
  { { -8, -8, 0, 316 } }
};
spr_array ringsp7 = {
  1,
  { { -8, -8, 0, 317 } }
};
spr_array ringsp8;
spr_array* ringpat[9] = {
  &ringsp0,
  &ringsp1,
  &ringsp2,
  &ringsp3,
  &ringsp4,
  &ringsp5,
  &ringsp6,
  &ringsp7,
  &ringsp8
};
unsigned char ringchg0[6] = { 5, 4, 5, 6, 7, 252 };
unsigned char ringchg1[6] = { 7, 0, 1, 2, 3, 255 };
unsigned char ringchg2[6] = { 7, 0, 1, 2, 3, 255 };
unsigned char* ringchg[3] = {
  ringchg0,
  ringchg1,
  ringchg2
};




































































void ring(act_info* pActwk) { /* Line 132, Address: 0x10062a0 */
  void(*ring_move_tbl[5])(act_info*) = { /* Line 133, Address: 0x10062ac */
    &ringinit,
    &ringmove,
    &ringget,
    &ringdie,
    &ringerase
  };

  ring_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 141, Address: 0x10062d8 */
} /* Line 142, Address: 0x1006314 */





void ringinit(act_info* pActwk) { /* Line 148, Address: 0x1006330 */
  char ringtbl[32] = { /* Line 149, Address: 0x1006360 */
     16,   0,
     24,   0,
     32,   0,
      0,  16,
      0,  24,
      0,  32,
     16,  16,
     24,  24,
     32,  32,
    -16,  16,
    -24,  24,
    -32,  32,
     16,   8,
     24,  16,
    -16,   8,
    -24,  16
  };
  int fw_index;
  int i;
  char ring_counter;
  short d0, d1, d2, d3, d5, d6;
  char d4;
  act_info* new_actwk;

  d1 = time_flag % 128; /* Line 174, Address: 0x1006394 */
  if (time_flag & 128) { /* Line 175, Address: 0x10063b4 */
    d1 += -time_item; /* Line 176, Address: 0x10063cc */
    if (d1 < 0) d1 = 0; /* Line 177, Address: 0x10063f4 */
    else if (d1 >= 3) d1 = 2; /* Line 178, Address: 0x1006410 */
  }
  fw_index = d1 + pActwk->cdsts * 3; /* Line 180, Address: 0x1006430 */

  d4 = flagwork[fw_index]; /* Line 182, Address: 0x1006450 */
  d1 = pActwk->userflag.b.h % 8; /* Line 183, Address: 0x1006464 */
  if (d1 == 7) d1 = 6; /* Line 184, Address: 0x1006488 */
  ring_counter = 1; /* Line 185, Address: 0x10064a8 */
  d0 = ((unsigned char)pActwk->userflag.b.h >> 4) * 2; /* Line 186, Address: 0x10064b4 */
  d5 = ringtbl[d0]; /* Line 187, Address: 0x10064dc */
  d6 = ringtbl[d0 + 1]; /* Line 188, Address: 0x10064fc */
  new_actwk = pActwk; /* Line 189, Address: 0x1006520 */
  d2 = pActwk->xposi.w.h; /* Line 190, Address: 0x1006528 */
  d3 = pActwk->yposi.w.h; /* Line 191, Address: 0x1006538 */

  d0 = time_flag % 128; /* Line 193, Address: 0x1006548 */
  if (time_flag & 128) { /* Line 194, Address: 0x1006568 */
    d0 += -time_item; /* Line 195, Address: 0x1006580 */
    if (d0 < 0) d0 = 0; /* Line 196, Address: 0x10065a8 */
    else if (d0 >= 3) d0 = 2; /* Line 197, Address: 0x10065c4 */
  }
  i = fw_index + 1; /* Line 199, Address: 0x10065e4 */
  do {
    if (flagwork[--i] & (1 << (ring_counter + -1))) goto label3; /* Line 201, Address: 0x10065e8 */
  } while (--d0 != -1); /* Line 202, Address: 0x1006620 */

  flagwork[fw_index] %= 128; /* Line 204, Address: 0x1006648 */
  goto label2; /* Line 205, Address: 0x1006660 */

label1:
  d0 = time_flag % 128; /* Line 208, Address: 0x1006668 */
  if (time_flag & 128) { /* Line 209, Address: 0x1006688 */
    d0 += -time_item; /* Line 210, Address: 0x10066a0 */
    if (d0 < 0) d0 = 0; /* Line 211, Address: 0x10066c8 */
    else if (d0 >= 3) d0 = 2; /* Line 212, Address: 0x10066e4 */
  }
  i = fw_index + 1; /* Line 214, Address: 0x1006704 */
  do {
    if (flagwork[--i] & (1 << (ring_counter + -1))) goto label3; /* Line 216, Address: 0x1006708 */
  } while (--d0 != -1); /* Line 217, Address: 0x1006740 */

  flagwork[fw_index] %= 128; /* Line 219, Address: 0x1006768 */
  if (actwkchk2(pActwk, &new_actwk) == 0) { /* Line 220, Address: 0x1006780 */
label2:
    new_actwk->actno = 16; /* Line 222, Address: 0x1006798 */
    new_actwk->r_no0 = 2; /* Line 223, Address: 0x10067a4 */
    new_actwk->xposi.w.h = d6; /* Line 224, Address: 0x10067b0 */
    *(short*)&new_actwk->actfree[8] = pActwk->xposi.w.h; /* Line 225, Address: 0x10067b8 */
    new_actwk->yposi.w.h = d5; /* Line 226, Address: 0x10067c8 */
    new_actwk->patbase = ringpat; /* Line 227, Address: 0x10067d0 */
    new_actwk->sproffset = 42926; /* Line 228, Address: 0x10067e0 */
    new_actwk->sprpri = 2; /* Line 229, Address: 0x10067ec */
    if (stageno.b.h == 6) { /* Line 230, Address: 0x10067f8 */
      new_actwk->sprpri = 0; /* Line 231, Address: 0x1006814 */
      new_actwk->userflag.b.l = pActwk->userflag.b.l; /* Line 232, Address: 0x100681c */
      if (new_actwk->userflag.b.l) { /* Line 233, Address: 0x100682c */
        new_actwk->sproffset %= 128; /* Line 234, Address: 0x100683c */
        new_actwk->sprpri = 2; /* Line 235, Address: 0x100684c */
      }
    }
    new_actwk->actflg = 4; /* Line 238, Address: 0x1006858 */
    new_actwk->colino = 71; /* Line 239, Address: 0x1006864 */
    new_actwk->sprhsize = 8; /* Line 240, Address: 0x1006870 */
    new_actwk->sprvsize = 8; /* Line 241, Address: 0x100687c */
    new_actwk->cdsts = pActwk->cdsts; /* Line 242, Address: 0x1006888 */
    new_actwk->actfree[10] = ring_counter; /* Line 243, Address: 0x1006898 */
    new_actwk->mstno.b.h = 1; /* Line 244, Address: 0x10068a0 */
label3:
    ++ring_counter; /* Line 246, Address: 0x10068ac */
    d2 += d5; /* Line 247, Address: 0x10068b8 */
    d3 += d6; /* Line 248, Address: 0x10068c4 */
    if (--d1 != -1) goto label1; /* Line 249, Address: 0x10068d0 */
  }
  d0 = time_flag % 128; /* Line 251, Address: 0x10068f8 */
  if (time_flag & 128) { /* Line 252, Address: 0x1006918 */
    d0 += -time_item; /* Line 253, Address: 0x1006930 */
    if (d0 < 0) d0 = 0; /* Line 254, Address: 0x1006958 */
    else if ((i = d0) >= 3) d0 = 2; /* Line 255, Address: 0x1006974 */
  }
  i = fw_index + 1; /* Line 257, Address: 0x1006994 */
  do {
    if (flagwork[i--] & 1) { /* Line 259, Address: 0x1006998 */
      frameout(pActwk); d1 = 0; /* Line 260, Address: 0x10069c0 */
      return; /* Line 261, Address: 0x10069d0 */
    }
  } while (--d0 != -1); /* Line 263, Address: 0x10069d8 */

  ringmove(pActwk); /* Line 265, Address: 0x1006a00 */
} /* Line 266, Address: 0x1006a0c */





void ringmove(act_info* pActwk) { /* Line 272, Address: 0x1006a40 */
  unsigned short d0;

  if (pActwk->actflg >= 0) { /* Line 275, Address: 0x1006a50 */
    d0 = (((unsigned short*)pActwk)[27] & 65408) - (scra_h_posit.w.h + -128 & 65408); /* Line 276, Address: 0x1006a64 */
    if (d0 >= 641) { /* Line 277, Address: 0x1006a94 */
      ringerase(pActwk); /* Line 278, Address: 0x1006aa4 */
      return; /* Line 279, Address: 0x1006ab0 */
    }
  }

  pActwk->pattim = systemtimer.b.b4 % 8; /* Line 284, Address: 0x1006ae8 */
  pActwk->patcnt = (unsigned char)((systemtimer.b.b4 >> 3) & 3) + 1; /* Line 283, Address: 0x1006ab8 */
  patchg(pActwk, ringchg); /* Line 285, Address: 0x1006b08 */
  actionsub(pActwk); /* Line 286, Address: 0x1006b1c */
} /* Line 287, Address: 0x1006b28 */





void ringget(act_info* pActwk) { /* Line 293, Address: 0x1006b40 */
  short d0, d1;

  pActwk->r_no0 += 2; /* Line 296, Address: 0x1006b54 */
  pActwk->colino = 0; /* Line 297, Address: 0x1006b64 */
  pActwk->sprpri = 1; /* Line 298, Address: 0x1006b6c */
  pActwk->mstno.b.h = 0; /* Line 299, Address: 0x1006b78 */
  ringgetsub(); /* Line 300, Address: 0x1006b80 */

  d0 = pActwk->cdsts * 3; /* Line 302, Address: 0x1006b88 */
  d1 = time_flag % 128; /* Line 303, Address: 0x1006bac */
  if (time_flag & 128) { /* Line 304, Address: 0x1006bcc */
    d1 += -time_item; /* Line 305, Address: 0x1006be4 */
    if (d1 < 0) d1 = 0; /* Line 306, Address: 0x1006c0c */
    else if (d1 >= 3) d1 = 2; /* Line 307, Address: 0x1006c28 */
  }
  flagwork[d0 + d1] |= 1 << (pActwk->actfree[10] + -1); /* Line 310, Address: 0x1006c48 */
  ringdie(pActwk); /* Line 311, Address: 0x1006c90 */
} /* Line 312, Address: 0x1006c9c */






void ringgetsub() { /* Line 318, Address: 0x1006cc0 */
  ++plring; /* Line 319, Address: 0x1006cc8 */
  plring_f |= 1; /* Line 320, Address: 0x1006cdc */
  if (plring >= 100) { /* Line 321, Address: 0x1006cf0 */
    if (plring_f2 & 2) { /* Line 322, Address: 0x1006d0c */
      if (plring < 200) { /* Line 323, Address: 0x1006d24 */
        soundset(149); /* Line 324, Address: 0x1006d40 */
        return; /* Line 325, Address: 0x1006d4c */
      }
      if (plring_f2 & 4) { /* Line 327, Address: 0x1006d54 */
        soundset(149); /* Line 328, Address: 0x1006d6c */
        return; /* Line 329, Address: 0x1006d78 */
      }
      plring_f2 |= 4; /* Line 331, Address: 0x1006d80 */
    }
    plring_f2 |= 2; /* Line 333, Address: 0x1006d94 */
    ++pl_suu; /* Line 334, Address: 0x1006da8 */
    ++pl_suu_f; /* Line 335, Address: 0x1006dbc */
    sub_sync(122); /* Line 336, Address: 0x1006dd0 */
  } /* Line 337, Address: 0x1006ddc */
  else {
    soundset(149); /* Line 339, Address: 0x1006de4 */
  }

} /* Line 342, Address: 0x1006df0 */





void ringdie(act_info* pActwk) { /* Line 348, Address: 0x1006e00 */
  patchg(pActwk, ringchg); /* Line 349, Address: 0x1006e0c */
  actionsub(pActwk); /* Line 350, Address: 0x1006e20 */
} /* Line 351, Address: 0x1006e2c */





void ringerase(act_info* pActwk) { /* Line 357, Address: 0x1006e40 */
  frameout(pActwk); /* Line 358, Address: 0x1006e4c */
} /* Line 359, Address: 0x1006e58 */








void flyring(act_info* pActwk) { /* Line 368, Address: 0x1006e70 */
  void(*flyring_move_tbl[5])(act_info*) = { /* Line 369, Address: 0x1006e7c */
    &flyringinit,
    &flyringmove,
    &flyringget,
    &flyringdie,
    &flyringerase
  };

  flyring_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 377, Address: 0x1006ea8 */
} /* Line 378, Address: 0x1006ee4 */





void flyringinit(act_info* pActwk) { /* Line 384, Address: 0x1006f00 */
  short d2, d3, d5;
  act_info* new_actwk;
  unsigned short d0, d1;
  short_union d4;

  new_actwk = pActwk; /* Line 390, Address: 0x1006f18 */
  if ((d5 = plring) >= 33) d5 = 32; /* Line 391, Address: 0x1006f20 */
  --d5; /* Line 392, Address: 0x1006f50 */
  d4.w = 648; /* Line 393, Address: 0x1006f5c */
  goto label1; /* Line 394, Address: 0x1006f64 */

  do {
    if (actwkchk(&new_actwk) != 0) break; /* Line 397, Address: 0x1006f6c */
label1:
    new_actwk->actno = 17; /* Line 399, Address: 0x1006f80 */
    new_actwk->r_no0 += 2; /* Line 400, Address: 0x1006f8c */
    new_actwk->sprvsize = 8; /* Line 401, Address: 0x1006f9c */
    new_actwk->sprhs = 8; /* Line 402, Address: 0x1006fa8 */
    new_actwk->xposi.w.h = pActwk->xposi.w.h; /* Line 403, Address: 0x1006fb4 */
    new_actwk->yposi.w.h = pActwk->yposi.w.h; /* Line 404, Address: 0x1006fc4 */
    new_actwk->patbase = ringpat; /* Line 405, Address: 0x1006fd4 */
    new_actwk->userflag.b.l = pActwk->userflag.b.l; /* Line 406, Address: 0x1006fe4 */
    new_actwk->sproffset = 42926; /* Line 407, Address: 0x1006ff4 */
    new_actwk->sprpri = 3; /* Line 408, Address: 0x1007000 */
    if (stageno.b.h == 6) { /* Line 409, Address: 0x100700c */
      new_actwk->sprpri = 0; /* Line 410, Address: 0x1007028 */
      if (pActwk->userflag.b.l) { /* Line 411, Address: 0x1007030 */
        new_actwk->sprpri = 3; /* Line 412, Address: 0x1007040 */
        new_actwk->sproffset %= 128; /* Line 413, Address: 0x100704c */
      }
    }
    new_actwk->actflg = 4; /* Line 416, Address: 0x100705c */
    new_actwk->colino = 71; /* Line 417, Address: 0x1007068 */
    new_actwk->sprhsize = 8; /* Line 418, Address: 0x1007074 */
    new_actwk->sprvsize = 8; /* Line 419, Address: 0x1007080 */
    sys_pattim4 = 255; /* Line 420, Address: 0x100708c */
    new_actwk->mstno.b.h = 2; /* Line 421, Address: 0x1007098 */

    if (d4.w >= 0) { /* Line 423, Address: 0x10070a4 */
      sinset(d4.b.l, (short*)&d0, (short*)&d1); /* Line 424, Address: 0x10070b8 */
      d2 = d0 << (d4.w >> 8); /* Line 425, Address: 0x10070d0 */
      d3 = d1 << (d4.w >> 8); /* Line 426, Address: 0x10070fc */
      if ((d4.b.l += 16) > 0) /* Line 427, Address: 0x1007128 */
        if ((d4.w -= 128) < 0) d4.w = 648; /* Line 428, Address: 0x100714c */
    }
    new_actwk->xspeed.w = d2; /* Line 430, Address: 0x1007178 */
    new_actwk->yspeed.w = d3; /* Line 431, Address: 0x1007180 */
    d2 = -d2; /* Line 432, Address: 0x1007188 */
    d4.w = -d4.w; /* Line 433, Address: 0x1007194 */
  } while (--d5 != -1); /* Line 434, Address: 0x10071a0 */

  if (lpKeepWork->User & 1) { /* Line 436, Address: 0x10071c8 */


    plring /= 2; /* Line 439, Address: 0x10071e4 */
  } /* Line 440, Address: 0x100720c */
  else {
    plring = 0; /* Line 442, Address: 0x1007214 */
  }
  plring_f = 128; /* Line 444, Address: 0x100721c */
  plring_f2 = 0; /* Line 445, Address: 0x1007228 */
  soundset(148); /* Line 446, Address: 0x1007230 */
  flyringmove(pActwk); /* Line 447, Address: 0x100723c */
} /* Line 448, Address: 0x1007248 */





void flyringmove(act_info* pActwk) { /* Line 454, Address: 0x1007270 */
  short d1;



  speedset2(pActwk); /* Line 459, Address: 0x1007280 */
  if ((pActwk->yspeed.w += 24) >= 0) { /* Line 460, Address: 0x100728c */
    if (((systemtimer.b.b4 + ((pActwk - actwk) / 68U)) & 3) == 0) { /* Line 461, Address: 0x10072b4 */
      if ((d1 = emycol_d(pActwk)) < 0) { /* Line 462, Address: 0x1007314 */
        pActwk->yposi.w.h += d1; /* Line 463, Address: 0x1007340 */
        pActwk->yspeed.w -= pActwk->yspeed.w / 4; /* Line 464, Address: 0x1007350 */
        pActwk->yspeed.w *= -1; /* Line 465, Address: 0x1007390 */
      }
    }
  }
  if (sys_pattim4) { /* Line 469, Address: 0x10073a0 */
    if (pActwk->yposi.w.h < scralim_down + 224) { /* Line 470, Address: 0x10073b0 */
      patchg(pActwk, ringchg); /* Line 471, Address: 0x10073e0 */
      actionsub(pActwk); /* Line 472, Address: 0x10073f4 */
      return; /* Line 473, Address: 0x1007400 */
    }
  }
  flyringerase(pActwk); /* Line 476, Address: 0x1007408 */
} /* Line 477, Address: 0x1007414 */





void flyringget(act_info* pActwk) { /* Line 483, Address: 0x1007430 */
  pActwk->r_no0 += 2; /* Line 484, Address: 0x100743c */
  pActwk->colino = 0; /* Line 485, Address: 0x100744c */
  pActwk->sprpri = 1; /* Line 486, Address: 0x1007454 */
  pActwk->mstno.b.h = 0; /* Line 487, Address: 0x1007460 */
  ringgetsub(); /* Line 488, Address: 0x1007468 */
  flyringdie(pActwk); /* Line 489, Address: 0x1007470 */
} /* Line 490, Address: 0x100747c */





void flyringdie(act_info* pActwk) { /* Line 496, Address: 0x1007490 */
  patchg(pActwk, ringchg); /* Line 497, Address: 0x100749c */
  actionsub(pActwk); /* Line 498, Address: 0x10074b0 */
} /* Line 499, Address: 0x10074bc */





void flyringerase(act_info* pActwk) { /* Line 505, Address: 0x10074d0 */
  frameout(pActwk); /* Line 506, Address: 0x10074dc */
} /* Line 507, Address: 0x10074e8 */
