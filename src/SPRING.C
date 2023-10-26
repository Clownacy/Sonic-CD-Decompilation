#include "EQU.H"
#include "SPRING.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "DIRCOL.H"
#include "DUMMY.H"
#include "ETC.H"
#include "PLAYSUB.H"
#include "RIDECHK.H"

extern void soundset(short ReqNo);

spr_array spat00 = {
  1,
  { { -16, -8, 0, 358 } }
};
spr_array spat01 = {
  1,
  { { -16, 0, 0, 359 } }
};
spr_array spat02 = {
  1,
  { { -16, -32, 0, 360 } }
};
spr_array spat03 = {
  1,
  { { -8, -16, 0, 361 } }
};
spr_array spat04 = {
  1,
  { { -8, -16, 0, 362 } }
};
spr_array spat05 = {
  1,
  { { -8, -16, 0, 363 } }
};
spr_array spat06 = {
  1,
  { { -16, -16, 0, 364 } }
};
spr_array spat07 = {
  1,
  { { -16, -16, 0, 365 } }
};
spr_array spat08 = {
  1,
  { { -16, -32, 0, 366 } }
};
spr_array kpat00 = {
  1,
  { { -8, -8, 0, 367 } }
};
spr_array kpat01 = {
  1,
  { { -8, -8, 0, 368 } }
};
spr_array ipat00 = {
  1,
  { { -20, -16, 0, 369 } }
};
spr_array spat10 = {
  1,
  { { -16, -8, 0, 370 } }
};
spr_array spat11 = {
  1,
  { { -16, 0, 0, 371 } }
};
spr_array spat12 = {
  1,
  { { -16, -32, 0, 372 } }
};
spr_array spat13 = {
  1,
  { { -8, -16, 0, 373 } }
};
spr_array spat14 = {
  1,
  { { -8, -16, 0, 374 } }
};
spr_array spat15 = {
  1,
  { { -8, -16, 0, 375 } }
};
spr_array spat16 = {
  1,
  { { -16, -16, 0, 376 } }
};
spr_array spat17 = {
  1,
  { { -16, -16, 0, 377 } }
};
spr_array spat18 = {
  1,
  { { -16, -32, 0, 378 } }
};
spr_array* springpat[3] = {
  &spat00,
  &spat01,
  &spat02
};
spr_array* spring90pat[3] = {
  &spat03,
  &spat04,
  &spat05
};
spr_array* spring45pat[3] = {
  &spat06,
  &spat07,
  &spat08
};
spr_array* springpat2[3] = {
  &spat10,
  &spat11,
  &spat12
};
spr_array* spring90pat2[3] = {
  &spat13,
  &spat14,
  &spat15
};
spr_array* spring45pat2[3] = {
  &spat16,
  &spat17,
  &spat18
};
spr_array* komapat[2] = {
  &kpat00,
  &kpat01
};
spr_array* iwapat[1] = { &ipat00 };
char springchg0[12] = {
   0,  0,  1,  1,
   2,  2,  2,  2,
   2,  2,  1, -4
};
char* springchg[1] = { springchg0 };
char komachg0[4] = { 8, 0, 1, -1 };
char* komachg[1] = { komachg0 };
void(*sjump_move_tbl[13])(act_info*) = {
  &sjumpinit,
  &sjumpmove,
  &sjumpmove2,
  &sjumpmove3,
  &sdushmove,
  &sdushmove2,
  &sdushmove3,
  &sjump2move,
  &sjump2move2,
  &sjump2move3,
  &sjump3move,
  &sjump3move2,
  &sjump3move3
};
































































void iwa(act_info* actionwk) { /* Line 219, Address: 0x1003de0 */
  switch (actionwk->r_no0) { /* Line 220, Address: 0x1003dec */

    case 0:
      iwa_init(actionwk); /* Line 223, Address: 0x1003e14 */
    case 2:
      iwa_move(actionwk); /* Line 225, Address: 0x1003e20 */
      break;
  }
  actionsub(actionwk); /* Line 228, Address: 0x1003e2c */
  frameout_s(actionwk); /* Line 229, Address: 0x1003e38 */
} /* Line 230, Address: 0x1003e44 */

void iwa_init(act_info* actionwk) { /* Line 232, Address: 0x1003e60 */
  unsigned char d0;

  actionwk->r_no0 += 2; /* Line 235, Address: 0x1003e70 */
  actionwk->actflg |= 4; /* Line 236, Address: 0x1003e80 */
  actionwk->sprpri |= 4; /* Line 237, Address: 0x1003e90 */
  actionwk->patbase = iwapat; /* Line 238, Address: 0x1003ea0 */
  actionwk->sprhsize = 16; /* Line 239, Address: 0x1003eb0 */
  actionwk->sprvsize = 16; /* Line 240, Address: 0x1003ebc */
  actionwk->patno = 0; /* Line 241, Address: 0x1003ec8 */
  d0 = 11; /* Line 242, Address: 0x1003ed0 */
  pa_set(); /* Line 243, Address: 0x1003ed8 */
} /* Line 244, Address: 0x1003ee0 */

void iwa_move(act_info* actionwk) { /* Line 246, Address: 0x1003f00 */
  act_info* a1;

  if ((actionwk->actflg & 128) == 0) return; /* Line 249, Address: 0x1003f10 */

  a1 = &actwk[0]; /* Line 251, Address: 0x1003f28 */
  ride_on_chk(actionwk, a1); /* Line 252, Address: 0x1003f30 */
} /* Line 253, Address: 0x1003f40 */

void koma(act_info* actionwk) { /* Line 255, Address: 0x1003f60 */
  unsigned short d0, d1;

  switch (actionwk->r_no0) { /* Line 258, Address: 0x1003f74 */

    case 0:
      koma_init(actionwk); /* Line 261, Address: 0x1003fa8 */
    case 2:
      koma_move(actionwk); /* Line 263, Address: 0x1003fb4 */
      break; /* Line 264, Address: 0x1003fc0 */
    case 4:
      koma_move2(actionwk); break; /* Line 266, Address: 0x1003fc8 */
      break;
  }
  d0 = *(short*)&actionwk->actfree[12]; /* Line 269, Address: 0x1003fd4 */
  d0 &= -128; /* Line 270, Address: 0x1003fe0 */
  d1 = (unsigned short)(scra_h_posit.w.h + -128) & 65408; /* Line 271, Address: 0x1003fe8 */
  d0 -= d1; /* Line 272, Address: 0x1004010 */
  if (d0 >= 641) frameout(actionwk); /* Line 273, Address: 0x1004018 */
} /* Line 274, Address: 0x1004034 */

void koma_init(act_info* actionwk) { /* Line 276, Address: 0x1004050 */
  act_info* a1;


  actionwk->r_no0 += 2; /* Line 280, Address: 0x100405c */
  actionwk->actflg |= 4; /* Line 281, Address: 0x100406c */
  actionwk->sprpri = 4; /* Line 282, Address: 0x100407c */
  actionwk->patbase = komapat; /* Line 283, Address: 0x1004088 */
  actionwk->sproffset = 848; /* Line 284, Address: 0x1004098 */
  actionwk->sprhsize = 8; /* Line 285, Address: 0x10040a4 */
  actionwk->sprvsize = 7; /* Line 286, Address: 0x10040b0 */
  ((short*)actionwk)[27] = actionwk->xposi.w.h; /* Line 287, Address: 0x10040bc */
  actionwk->xspeed.w = 384; /* Line 288, Address: 0x10040cc */

  pa_set(); /* Line 290, Address: 0x10040d8 */
  patchg(actionwk, (unsigned char**)komachg); /* Line 291, Address: 0x10040e0 */

  if (actwkchk(&a1) != 0) { /* Line 293, Address: 0x10040f4 */

    frameout(actionwk); /* Line 295, Address: 0x1004108 */
    return; /* Line 296, Address: 0x1004114 */
  }
  a1->actno = 10; /* Line 298, Address: 0x100411c */
  a1->xposi.w.h = actionwk->xposi.w.h; /* Line 299, Address: 0x1004128 */
  a1->yposi.w.h = actionwk->yposi.w.h; /* Line 300, Address: 0x1004138 */
  a1->yposi.w.h -= 16; /* Line 301, Address: 0x1004148 */
  a1->actfree[15] = -16; /* Line 302, Address: 0x1004158 */
  ((unsigned short*)a1)[28] = actionwk - actwk; /* Line 303, Address: 0x1004164 */
  a1->userflag.w = actwk[((unsigned short*)a1)[28]].userflag.w; /* Line 304, Address: 0x1004198 */
} /* Line 305, Address: 0x10041c8 */

void koma_move(act_info* actionwk) { /* Line 307, Address: 0x10041e0 */
  short d1;

  d1 = emycol_d(actionwk); /* Line 310, Address: 0x10041f0 */
  if (d1 >= 0) { /* Line 311, Address: 0x1004204 */

    ++actionwk->yposi.w.h; /* Line 313, Address: 0x1004214 */
    return; /* Line 314, Address: 0x1004224 */
  }
  actionwk->yposi.w.h += d1; /* Line 316, Address: 0x100422c */
  *(short*)&actionwk->actfree[8] = actionwk->yposi.w.h; /* Line 317, Address: 0x100423c */
  actionwk->r_no0 += 2; /* Line 318, Address: 0x100424c */

} /* Line 320, Address: 0x100425c */

void koma_move2(act_info* actionwk) { /* Line 322, Address: 0x1004270 */
  short d0, d1;

  if (!time_stop) { /* Line 325, Address: 0x1004284 */
    d1 = emycol_d(actionwk); /* Line 326, Address: 0x1004294 */
    actionwk->yposi.w.h += d1; /* Line 327, Address: 0x10042a8 */
    d0 = *(short*)&actionwk->actfree[8]; /* Line 328, Address: 0x10042b8 */
    d0 -= actionwk->yposi.w.h; /* Line 329, Address: 0x10042c8 */
    if (d0 >= 12) actionwk->xspeed.w = -actionwk->xspeed.w; /* Line 330, Address: 0x10042dc */
    speedset2(actionwk); /* Line 331, Address: 0x1004314 */
    patchg(actionwk, (unsigned char**)komachg); /* Line 332, Address: 0x1004320 */
  }
  actionsub(actionwk); /* Line 334, Address: 0x1004334 */
} /* Line 335, Address: 0x1004340 */

void spring_d(act_info* actionwk) { /* Line 337, Address: 0x1004360 */
  switch (actionwk->r_no0) { /* Line 338, Address: 0x100436c */

    case 0:
      spr_d_init(actionwk); /* Line 341, Address: 0x1004394 */
    case 2:
      spr_d_move(actionwk); /* Line 343, Address: 0x10043a0 */
      break;
  }
} /* Line 346, Address: 0x10043ac */

void spr_d_init(act_info* actionwk) { /* Line 348, Address: 0x10043c0 */
  if (actionwk->userflag.b.h & 2) /* Line 349, Address: 0x10043cc */
    actionwk->patbase = springpat; /* Line 350, Address: 0x10043e8 */
  else
    actionwk->patbase = springpat2; /* Line 352, Address: 0x1004400 */

  actionwk->sproffset = 34080; /* Line 354, Address: 0x1004410 */
  actionwk->actflg |= 4; /* Line 355, Address: 0x100441c */
  actionwk->sprhsize = 16; /* Line 356, Address: 0x100442c */
  actionwk->sprvsize = 8; /* Line 357, Address: 0x1004438 */
  actionwk->sprpri = 4; /* Line 358, Address: 0x1004444 */
  actionwk->r_no0 += 2; /* Line 359, Address: 0x1004450 */
  spr_d_move(actionwk); /* Line 360, Address: 0x1004460 */
} /* Line 361, Address: 0x100446c */

void spr_d_move(act_info* actionwk) { /* Line 363, Address: 0x1004480 */
  actionwk->xposi.l = actwk[0].xposi.l; /* Line 364, Address: 0x100448c */
  actionwk->yposi.l = actwk[0].yposi.l; /* Line 365, Address: 0x100449c */
  actionsub(actionwk); /* Line 366, Address: 0x10044ac */
} /* Line 367, Address: 0x10044b8 */

















void spring(act_info* actionwk) { /* Line 385, Address: 0x10044d0 */
  unsigned short d1;
  act_info* a1;
  unsigned short d0;






  if (actionwk->r_no1 == 5) { /* Line 395, Address: 0x10044e8 */

    spring_d(actionwk); /* Line 397, Address: 0x1004500 */
  }
  if (actionwk->r_no0 == 0 /* Line 399, Address: 0x100450c */
      || actionwk->actflg & 128) { /* Line 400, Address: 0x1004520 */

    sjump_move_tbl[actionwk->r_no0 / 2](actionwk); /* Line 402, Address: 0x1004538 */
  }
  actionsub(actionwk); /* Line 404, Address: 0x100457c */

  d1 = *(short*)&actionwk->actfree[10]; /* Line 406, Address: 0x1004588 */
  if (d1 != 0) { /* Line 407, Address: 0x1004594 */
    a1 = &actwk[d1]; /* Line 408, Address: 0x10045a0 */
    actionwk->xposi.w.h = a1->xposi.w.h; /* Line 409, Address: 0x10045bc */
    actionwk->yposi.w.h = a1->yposi.w.h; /* Line 410, Address: 0x10045c8 */
    actionwk->xposi.w.h += actionwk->actfree[14]; /* Line 411, Address: 0x10045d4 */
    actionwk->yposi.w.h += actionwk->actfree[15]; /* Line 412, Address: 0x10045f4 */
  }

  d0 = *(short*)&actionwk->actfree[12]; /* Line 415, Address: 0x1004614 */
  d0 &= -128; /* Line 416, Address: 0x1004620 */
  d1 = (unsigned short)(scra_h_posit.w.h + -128) & 65408; /* Line 417, Address: 0x1004628 */
  d0 += d1; /* Line 418, Address: 0x1004650 */
  if (d0 >= 641) frameout(actionwk); /* Line 419, Address: 0x1004658 */
} /* Line 420, Address: 0x1004674 */

void sjumpinit(act_info* actionwk) { /* Line 422, Address: 0x1004690 */
  short sjumptbl[2] = { -4096, -2560 }; /* Line 423, Address: 0x10046a0 */
  unsigned char d0;


  actionwk->r_no0 += 2; /* Line 427, Address: 0x10046bc */
  if (actionwk->userflag.b.h & 2) /* Line 428, Address: 0x10046cc */
    actionwk->patbase = springpat; /* Line 429, Address: 0x10046e8 */
  else
    actionwk->patbase = springpat2; /* Line 431, Address: 0x1004700 */

  actionwk->sproffset = 1312; /* Line 433, Address: 0x1004710 */
  actionwk->actflg |= 4; /* Line 434, Address: 0x100471c */
  actionwk->sprhsize = 16; /* Line 435, Address: 0x100472c */
  actionwk->sprvsize = 8; /* Line 436, Address: 0x1004738 */
  *(short*)&actionwk->actfree[12] = actionwk->xposi.w.h; /* Line 437, Address: 0x1004744 */
  actionwk->sprpri = 4; /* Line 438, Address: 0x1004754 */

  d0 = actionwk->userflag.b.h; /* Line 440, Address: 0x1004760 */
  if (d0 & 4) { /* Line 441, Address: 0x100476c */
    actionwk->r_no0 = 8; /* Line 442, Address: 0x100477c */
    actionwk->sprhsize = 8; /* Line 443, Address: 0x1004788 */
    actionwk->sprvsize = 16; /* Line 444, Address: 0x1004794 */
    if (actionwk->userflag.b.h & 2) /* Line 445, Address: 0x10047a0 */
      actionwk->patbase = spring90pat; /* Line 446, Address: 0x10047bc */
    else
      actionwk->patbase = spring90pat2; /* Line 448, Address: 0x10047d4 */
    goto label1; /* Line 449, Address: 0x10047e4 */
  }
  if (d0 & 8) { /* Line 451, Address: 0x10047ec */
    actionwk->r_no0 = 20; /* Line 452, Address: 0x10047fc */
    actionwk->sprhsize = 24; /* Line 453, Address: 0x1004808 */
    actionwk->sprvsize = 12; /* Line 454, Address: 0x1004814 */
    if (actionwk->userflag.b.h & 2) /* Line 455, Address: 0x1004820 */
      actionwk->patbase = spring45pat; /* Line 456, Address: 0x100483c */
    else
      actionwk->patbase = spring45pat2; /* Line 458, Address: 0x1004854 */
    pa_set(); goto label1; /* Line 459, Address: 0x1004864 */
  } /* Line 460, Address: 0x100486c */
  else {
    if (actionwk->actflg & 2) { /* Line 462, Address: 0x1004874 */
      actionwk->r_no0 = 14; /* Line 463, Address: 0x100488c */
      actionwk->cddat |= 1; /* Line 464, Address: 0x1004898 */
    }
label1:  if (d0 & 2) /* Line 466, Address: 0x10048a8 */
      actionwk->sproffset |= 8192; /* Line 467, Address: 0x10048b8 */

    *(short*)&actionwk->actfree[6] = sjumptbl[(d0 & 2) / 2]; /* Line 469, Address: 0x10048c8 */
  }
} /* Line 471, Address: 0x10048fc */

int ride_on_chk_s(act_info* actionwk, act_info* a1) { /* Line 473, Address: 0x1004910 */
  return ride_on_chk(actionwk, a1); /* Line 474, Address: 0x1004920 */
} /* Line 475, Address: 0x1004938 */

void sjumpmove(act_info* actionwk) { /* Line 477, Address: 0x1004950 */
  act_info* a1;

  if ((actionwk->actflg & 128) == 0) return; /* Line 480, Address: 0x1004960 */

  a1 = &actwk[0]; /* Line 482, Address: 0x1004978 */
  if (ride_on_chk_s(actionwk, a1) == 0) return; /* Line 483, Address: 0x1004980 */

  actionwk->r_no0 = 4; /* Line 485, Address: 0x1004998 */
  a1->yposi.w.h += 8; /* Line 486, Address: 0x10049a4 */
  a1->yspeed.w = *(short*)&actionwk->actfree[6]; /* Line 487, Address: 0x10049b0 */
  a1->cddat |= 2; /* Line 488, Address: 0x10049bc */
  a1->cddat &= -9; /* Line 489, Address: 0x10049c8 */
  a1->mstno.b.h = 16; /* Line 490, Address: 0x10049d4 */
  actionwk->cddat &= -9; /* Line 491, Address: 0x10049dc */
  soundset(152); /* Line 492, Address: 0x10049ec */
} /* Line 493, Address: 0x10049f8 */

void sjumpmove2(act_info* actionwk) { /* Line 495, Address: 0x1004a10 */
  patchg(actionwk, (unsigned char**)springchg); /* Line 496, Address: 0x1004a1c */
} /* Line 497, Address: 0x1004a30 */

void sjumpmove3(act_info* actionwk) { /* Line 499, Address: 0x1004a40 */
  actionwk->cddat &= 247; /* Line 500, Address: 0x1004a48 */
  actionwk->mstno.b.l = 1; /* Line 501, Address: 0x1004a58 */
  actionwk->r_no0 -= 4; /* Line 502, Address: 0x1004a64 */
  actionwk->patno = 0; /* Line 503, Address: 0x1004a74 */
} /* Line 504, Address: 0x1004a7c */

int ride_on_chk_s1(act_info* actionwk, act_info* a1) { /* Line 506, Address: 0x1004a90 */
  return ride_on_chk(actionwk, a1); /* Line 507, Address: 0x1004aa0 */
} /* Line 508, Address: 0x1004ab8 */


void sdushmove(act_info* actionwk) { /* Line 511, Address: 0x1004ad0 */
  act_info* a1;

  if ((actionwk->actflg & 128) == 0) return; /* Line 514, Address: 0x1004ae0 */

  a1 = &actwk[0]; /* Line 516, Address: 0x1004af8 */
  ride_on_chk_s1(actionwk, a1); /* Line 517, Address: 0x1004b00 */
  if ((actionwk->cddat & 32) == 0) return; /* Line 518, Address: 0x1004b10 */

  actionwk->r_no0 = 10; /* Line 520, Address: 0x1004b28 */
  a1->xspeed.w = *(short*)&actionwk->actfree[6]; /* Line 521, Address: 0x1004b34 */
  a1->xposi.w.h += 8; /* Line 522, Address: 0x1004b40 */
  a1->cddat |= 1; /* Line 523, Address: 0x1004b4c */
  if ((actionwk->cddat & 1) == 0) { /* Line 524, Address: 0x1004b58 */
    a1->xposi.w.h -= 16; /* Line 525, Address: 0x1004b70 */
    a1->xspeed.w = -a1->xspeed.w; /* Line 526, Address: 0x1004b7c */
    a1->cddat &= 254; /* Line 527, Address: 0x1004b98 */
  }
  *(short*)&a1->actfree[20] = 15; /* Line 529, Address: 0x1004ba4 */
  a1->mspeed.w = a1->xspeed.w; /* Line 530, Address: 0x1004bac */
  if ((a1->cddat & 4) == 0) /* Line 531, Address: 0x1004bb4 */
    a1->mstno.b.h = 0; /* Line 532, Address: 0x1004bc8 */

  a1->direc.b.h = 0; /* Line 534, Address: 0x1004bcc */
  actionwk->cddat &= 223; /* Line 535, Address: 0x1004bd0 */
  a1->cddat &= 223; /* Line 536, Address: 0x1004be0 */
  soundset(152); /* Line 537, Address: 0x1004bec */
} /* Line 538, Address: 0x1004bf8 */

void sdushmove2(act_info* actionwk) { /* Line 540, Address: 0x1004c10 */
  patchg(actionwk, (unsigned char**)springchg); /* Line 541, Address: 0x1004c1c */
} /* Line 542, Address: 0x1004c30 */

void sdushmove3(act_info* actionwk) { /* Line 544, Address: 0x1004c40 */
  actionwk->mstno.b.l = 1; /* Line 545, Address: 0x1004c48 */
  actionwk->r_no0 -= 4; /* Line 546, Address: 0x1004c54 */
  actionwk->patno = 0; /* Line 547, Address: 0x1004c64 */
} /* Line 548, Address: 0x1004c6c */

int ride_on_chk_s2(act_info* actionwk, act_info* a1) { /* Line 550, Address: 0x1004c80 */
  return hitchk_u(actionwk, a1); /* Line 551, Address: 0x1004c90 */
} /* Line 552, Address: 0x1004ca8 */

void sjump2move(act_info* actionwk) { /* Line 554, Address: 0x1004cc0 */
  act_info* a1;

  if ((actionwk->actflg & 128) == 0) return; /* Line 557, Address: 0x1004cd0 */

  a1 = &actwk[0]; /* Line 559, Address: 0x1004ce8 */
  if (ride_on_chk_s2(actionwk, a1) == 0) return; /* Line 560, Address: 0x1004cf0 */

  actionwk->r_no0 = 16; /* Line 562, Address: 0x1004d08 */
  a1->yposi.w.h -= 8; /* Line 563, Address: 0x1004d14 */
  a1->yspeed.w = *(short*)&actionwk->actfree[6]; /* Line 564, Address: 0x1004d20 */
  a1->yspeed.w = -a1->yspeed.w; /* Line 565, Address: 0x1004d2c */
  a1->cddat |= 2; /* Line 566, Address: 0x1004d48 */
  a1->cddat &= 247; /* Line 567, Address: 0x1004d54 */
  actionwk->cddat &= 247; /* Line 568, Address: 0x1004d60 */
  soundset(152); /* Line 569, Address: 0x1004d70 */
} /* Line 570, Address: 0x1004d7c */

void sjump2move2(act_info* actionwk) { /* Line 572, Address: 0x1004d90 */
  patchg(actionwk, (unsigned char**)springchg); /* Line 573, Address: 0x1004d9c */
} /* Line 574, Address: 0x1004db0 */

void sjump2move3(act_info* actionwk) { /* Line 576, Address: 0x1004dc0 */
  actionwk->mstno.b.l = 1; /* Line 577, Address: 0x1004dc8 */
  actionwk->r_no0 -= 4; /* Line 578, Address: 0x1004dd4 */
  actionwk->patno = 0; /* Line 579, Address: 0x1004de4 */
} /* Line 580, Address: 0x1004dec */

void sjump3move(act_info* actionwk) { /* Line 582, Address: 0x1004e00 */
  act_info* a1;
  unsigned short sin, cos;
  int sinl, cosl;
  unsigned char d0;
  short d2;

  if ((actionwk->actflg & 128) == 0) return; /* Line 589, Address: 0x1004e20 */

  a1 = &actwk[0]; /* Line 591, Address: 0x1004e38 */
  if (ride_on_chk_s(actionwk, a1) == 0) /* Line 592, Address: 0x1004e40 */
    if ((actionwk->cddat & 32) == 0) return; /* Line 593, Address: 0x1004e58 */

  actionwk->r_no0 = 22; /* Line 595, Address: 0x1004e70 */
  d0 = 224; /* Line 596, Address: 0x1004e7c */
  sinset(d0, (short*)&sin, (short*)&cos); /* Line 597, Address: 0x1004e84 */
  d2 = actionwk->actfree[6]; /* Line 598, Address: 0x1004e98 */
  d2 = -d2; /* Line 599, Address: 0x1004ea8 */
  sinl = sin * d2; /* Line 600, Address: 0x1004ec4 */
  cosl = cos * d2; /* Line 601, Address: 0x1004ed8 */
  sinl >>= 8; /* Line 602, Address: 0x1004eec */
  cosl >>= 8; /* Line 603, Address: 0x1004ef0 */
  a1->yspeed.w = sinl; /* Line 604, Address: 0x1004ef4 */
  a1->xspeed.w = cosl; /* Line 605, Address: 0x1004f00 */
  a1->yposi.w.h += 8; /* Line 606, Address: 0x1004f0c */
  if (actionwk->actflg & 2) { /* Line 607, Address: 0x1004f18 */
    a1->yposi.w.h -= 16; /* Line 608, Address: 0x1004f30 */
    a1->yspeed.w = -a1->yspeed.w; /* Line 609, Address: 0x1004f3c */
  }
  a1->cddat &= 254; /* Line 611, Address: 0x1004f58 */
  a1->xposi.w.h -= 8; /* Line 612, Address: 0x1004f64 */
  if (actionwk->cddat & 1) { /* Line 613, Address: 0x1004f70 */
    a1->xposi.w.h += 16; /* Line 614, Address: 0x1004f88 */
    a1->cddat |= 1; /* Line 615, Address: 0x1004f94 */
    a1->xspeed.w = -a1->xspeed.w; /* Line 616, Address: 0x1004fa0 */
  }
  a1->cddat |= 2; /* Line 618, Address: 0x1004fbc */
  a1->cddat &= 247; /* Line 619, Address: 0x1004fc8 */
  a1->cddat &= 223; /* Line 620, Address: 0x1004fd4 */
  actionwk->cddat &= 247; /* Line 621, Address: 0x1004fe0 */
  actionwk->cddat &= 223; /* Line 622, Address: 0x1004ff0 */
  soundset(152); /* Line 623, Address: 0x1005000 */
  sjump3move2(actionwk); /* Line 624, Address: 0x100500c */
} /* Line 625, Address: 0x1005018 */

void sjump3move2(act_info* actionwk) { /* Line 627, Address: 0x1005040 */
  patchg(actionwk, (unsigned char**)springchg); /* Line 628, Address: 0x100504c */
} /* Line 629, Address: 0x1005060 */

void sjump3move3(act_info* actionwk) { /* Line 631, Address: 0x1005070 */
  actionwk->mstno.b.l = 1; /* Line 632, Address: 0x1005078 */
  actionwk->r_no0 -= 4; /* Line 633, Address: 0x1005084 */
  actionwk->patno = 0; /* Line 634, Address: 0x1005094 */
} /* Line 635, Address: 0x100509c */
