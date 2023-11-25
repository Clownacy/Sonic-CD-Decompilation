#include "EQU.H"
#include "DAI_RD1.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "DIRCOL.H"
#include "DUMMY.H"
#include "ETC.H"
#include "RIDECHK.H"

extern void soundset(short ReqNo);

spr_array dai11a_pat1 = {
  1,
  { { -16, -16, 0, 488 } }
};
spr_array dai11a_pat2 = {
  1,
  { { -32, -16, 0, 489 } }
};
spr_array dai11a_pat3 = {
  1,
  { { -48, -16, 0, 490 } }
};
spr_array* dai11a_pattbl[3] = {
  &dai11a_pat1,
  &dai11a_pat2,
  &dai11a_pat3
};
void(*dodai_acttbl[2])(act_info*) = {
  &dodai_init,
  &dodai_move
};
void(*dodai_mtype[10])(act_info*) = {
  &dodai_ud,
  &dodai_lr,
  &dodai_nA,
  &dodai_nB,
  (void(*)(act_info*))&dodai_fix,
  &dodai_fal,
  &dodai_up,
  &dodai_upx,
  &dodai_rm,
  &dodai_lm
};
spr_array vfuta_pat0 = {
  1,
  { { -4, -24, 0, 524 } }
};
spr_array vfuta_pat1 = {
  1,
  { { -4, -24, 0, 525 } }
};
spr_array* vfutapat[2] = {
  &vfuta_pat0,
  &vfuta_pat1
};
void(*vfuta_tbl[3])(act_info*) = {
  &vfuta_init,
  &vfuta_move1,
  &vfuta_move2
};























































































void dodai(act_info* pActwk) { /* Line 149, Address: 0x1002090 */
  dodai_acttbl[pActwk->r_no0 / 2](pActwk); /* Line 150, Address: 0x100209c */
  actionsub(pActwk); /* Line 151, Address: 0x10020e0 */
} /* Line 152, Address: 0x10020ec */





void dodai_init(act_info* pActwk) { /* Line 158, Address: 0x1002100 */
  char wk;
  act_info* pNewact;
  static unsigned char dai_mcnttbl[4] = { 0, 3, 4, 6 };
  static unsigned char dai_hstbl[3] = { 16, 32, 48 };




  pActwk->actflg |= 4; /* Line 167, Address: 0x1002110 */
  pActwk->sproffset = 17598; /* Line 168, Address: 0x1002120 */
  pActwk->sprpri = 2; /* Line 169, Address: 0x100212c */


  ((short*)pActwk)[30] = pActwk->xposi.w.h; /* Line 172, Address: 0x1002138 */
  ((short*)pActwk)[31] = pActwk->yposi.w.h; /* Line 173, Address: 0x1002148 */
  ((short*)pActwk)[29] = pActwk->yposi.w.h; /* Line 174, Address: 0x1002158 */

  pActwk->patbase = dai11a_pattbl; /* Line 176, Address: 0x1002168 */
  wk = pActwk->userflag.b.h & 3; /* Line 177, Address: 0x1002178 */
  pActwk->patno = wk; /* Line 178, Address: 0x100219c */


  pActwk->sprhsize = dai_hstbl[wk]; /* Line 181, Address: 0x10021a4 */
  pActwk->sprvsize = 8; /* Line 182, Address: 0x10021c4 */

  wk = (pActwk->userflag.b.h >> 2) & 3; /* Line 184, Address: 0x10021d0 */
  pActwk->actfree[3] = dai_mcnttbl[wk]; /* Line 185, Address: 0x10021f8 */


  pActwk->r_no0 += 2; /* Line 188, Address: 0x1002218 */
  if ((wk = pActwk->userflag.b.l) != 0) { /* Line 189, Address: 0x1002228 */

    if (actwkchk(&pNewact) != 0) { /* Line 191, Address: 0x1002248 */

      dai_fout(pActwk); /* Line 193, Address: 0x100225c */
    } /* Line 194, Address: 0x1002268 */
    else {
      pNewact->actno = 10; /* Line 196, Address: 0x1002270 */
      pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 197, Address: 0x100227c */
      pNewact->yposi.w.h = pActwk->yposi.w.h + -16; /* Line 198, Address: 0x100228c */
      ((char*)(pNewact))[61] = -16; /* Line 199, Address: 0x10022b0 */



      ((unsigned short*)pNewact)[28] = pActwk - actwk; /* Line 203, Address: 0x10022bc */


      pNewact->userflag.b.h = pActwk->userflag.b.l & 2; /* Line 206, Address: 0x10022f0 */
      wk = pActwk->userflag.b.l & 255 & 248; /* Line 207, Address: 0x1002314 */
      pNewact->actfree[14] = wk; /* Line 208, Address: 0x1002338 */
      pNewact->xposi.w.h += wk; /* Line 209, Address: 0x1002340 */
    }
  }
} /* Line 212, Address: 0x1002360 */





















void dodai_move(act_info* pActwk) { /* Line 234, Address: 0x1002380 */
  unsigned char mtype;
  unsigned short xlen;

  if (time_stop) { /* Line 238, Address: 0x1002394 */
    ridechk(pActwk, &actwk[0]); /* Line 239, Address: 0x10023a4 */
    return; /* Line 240, Address: 0x10023b8 */
  }



  mtype = (pActwk->userflag.b.h >> 4) & 15; /* Line 245, Address: 0x10023c0 */
  dodai_mtype[mtype](pActwk); /* Line 246, Address: 0x10023e0 */

  xlen = ((unsigned short*)pActwk)[30] & 65408; /* Line 248, Address: 0x1002404 */
  xlen -= (scra_h_posit.w.h + -128) & -128; /* Line 249, Address: 0x100241c */
  if (xlen >= 641) { /* Line 250, Address: 0x1002444 */
    ride_on_clr(pActwk, &actwk[0]); /* Line 251, Address: 0x1002454 */
    dai_fout(pActwk); /* Line 252, Address: 0x1002468 */
  }
} /* Line 254, Address: 0x1002474 */



void dodai_ud(act_info* pActwk) { /* Line 258, Address: 0x1002490 */
  ++pActwk->actfree[0]; /* Line 259, Address: 0x100249c */
  pActwk->yposi.w.h = ((short*)pActwk)[31] + dodai_sub(pActwk); /* Line 260, Address: 0x10024ac */

  ridechk(pActwk, &actwk[0]); /* Line 262, Address: 0x10024e4 */
} /* Line 263, Address: 0x10024f8 */



void dodai_lr(act_info* pActwk) { /* Line 267, Address: 0x1002510 */
  int xsav;

  xsav = pActwk->xposi.l; /* Line 270, Address: 0x1002520 */
  pActwk->xposi.w.h = ((short*)pActwk)[30] + dodai_sub(pActwk); /* Line 271, Address: 0x1002528 */

  ++pActwk->actfree[0]; /* Line 273, Address: 0x1002560 */

  pActwk->yposi.w.h = ((char)(((unsigned char*)pActwk)[48]) >> 1) + ((short*)pActwk)[31]; /* Line 275, Address: 0x1002570 */



  dodai_ride1(pActwk, xsav); /* Line 279, Address: 0x10025b0 */
} /* Line 280, Address: 0x10025c0 */


unsigned char dodai_ride1(act_info* pActwk, int xpos) { /* Line 283, Address: 0x10025e0 */
  pActwk->xspeed.w = (pActwk->xposi.l - xpos) >> 8; /* Line 284, Address: 0x10025f0 */
  dodai_ride2(pActwk); /* Line 285, Address: 0x1002614 */
} /* Line 286, Address: 0x1002620 */


unsigned char dodai_ride2(act_info* pActwk) { /* Line 289, Address: 0x1002630 */
  if (!ridechk(pActwk, &actwk[0])) { /* Line 290, Address: 0x100263c */

    if (pActwk->actfree[2]) { /* Line 292, Address: 0x1002658 */
      --pActwk->actfree[2]; /* Line 293, Address: 0x1002668 */
    }
    return 0; /* Line 295, Address: 0x1002678 */
  }

  if (pActwk->actfree[2] < 8) { /* Line 298, Address: 0x1002684 */
    ++pActwk->actfree[2]; /* Line 299, Address: 0x100269c */
  }

  return 1; /* Line 302, Address: 0x10026ac */
} /* Line 303, Address: 0x10026b0 */



void dodai_nA(act_info* pActwk) { /* Line 307, Address: 0x10026c0 */
  int xsav;

  xsav = pActwk->xposi.l; /* Line 310, Address: 0x10026d0 */
  ++pActwk->actfree[0]; /* Line 311, Address: 0x10026d8 */
  pActwk->yposi.w.h = ((short*)pActwk)[31] + dodai_sub(pActwk); /* Line 312, Address: 0x10026e8 */

  pActwk->xposi.w.h = ((short*)pActwk)[30] + dodai_sub(pActwk); /* Line 314, Address: 0x1002720 */
  dodai_ride1(pActwk, xsav); /* Line 316, Address: 0x1002758 */
} /* Line 317, Address: 0x1002768 */




void dodai_nB(act_info* pActwk) { /* Line 321, Address: 0x1002780 */
  int xsav;

  xsav = pActwk->xposi.l; /* Line 324, Address: 0x1002790 */
  ++pActwk->actfree[0]; /* Line 325, Address: 0x1002798 */
  pActwk->yposi.w.h = ((short*)pActwk)[31] + dodai_sub(pActwk); /* Line 326, Address: 0x10027a8 */

  pActwk->xposi.w.h = ((short*)pActwk)[30] - dodai_sub(pActwk); /* Line 328, Address: 0x10027e0 */

  dodai_ride1(pActwk, xsav); /* Line 330, Address: 0x1002818 */
} /* Line 331, Address: 0x1002828 */



unsigned char dodai_fix(act_info* pActwk) { /* Line 335, Address: 0x1002840 */
  pActwk->yposi.w.h = ((char)pActwk->actfree[2] >> 1) + ((short*)pActwk)[31]; /* Line 336, Address: 0x100284c */

  return dodai_ride2(pActwk); /* Line 338, Address: 0x100288c */
} /* Line 339, Address: 0x1002898 */



void dodai_fal(act_info* pActwk) { /* Line 343, Address: 0x10028b0 */
  if (!pActwk->actfree[1]) { /* Line 344, Address: 0x10028bc */
    if (!dodai_fix(pActwk)) return; /* Line 345, Address: 0x10028cc */




    pActwk->actfree[4] = 30; /* Line 350, Address: 0x10028e0 */
    pActwk->actfree[1] += 2; /* Line 351, Address: 0x10028ec */
  }


  if (pActwk->actfree[4]) { /* Line 355, Address: 0x10028fc */
    --pActwk->actfree[4]; /* Line 356, Address: 0x100290c */
    dodai_fix(pActwk); /* Line 357, Address: 0x100291c */
    return; /* Line 358, Address: 0x1002928 */
  }


  ridechk(pActwk, &actwk[0]); /* Line 362, Address: 0x1002930 */
  pActwk->yposi.l += pActwk->yspeed.w << 8; /* Line 363, Address: 0x1002944 */

  if (pActwk->yspeed.w < 1024) { /* Line 365, Address: 0x1002968 */
    pActwk->yspeed.w += 64; /* Line 366, Address: 0x1002984 */
  }



  if ((scra_v_posit.w.h + 256) < pActwk->yposi.w.h) { /* Line 371, Address: 0x1002994 */

    ride_on_clr(pActwk, &actwk[0]); /* Line 373, Address: 0x10029c4 */
    frameout(pActwk); /* Line 374, Address: 0x10029d8 */
  }
} /* Line 376, Address: 0x10029e4 */



void dodai_up(act_info* pActwk) { /* Line 380, Address: 0x1002a00 */
  switch (pActwk->actfree[1]) { /* Line 381, Address: 0x1002a0c */
    case 0:
      if (!dodai_fix(pActwk)) break; /* Line 383, Address: 0x1002a40 */



      pActwk->actfree[1] += 2; /* Line 387, Address: 0x1002a54 */
    case 2:
      if (pActwk->actfree[0] < 64) { /* Line 389, Address: 0x1002a64 */
        pActwk->yposi.w.h = ((short*)pActwk)[31] - dodai_sub(pActwk); /* Line 390, Address: 0x1002a7c */

        pActwk->actfree[0] += 2; /* Line 392, Address: 0x1002ab4 */
        ridechk(pActwk, &actwk[0]); /* Line 393, Address: 0x1002ac4 */
        break; /* Line 394, Address: 0x1002ad8 */
      }

      ((short*)pActwk)[31] = pActwk->yposi.w.h; /* Line 397, Address: 0x1002ae0 */
      pActwk->actfree[1] += 2; /* Line 398, Address: 0x1002af0 */
    case 4:
      dodai_fix(pActwk); /* Line 400, Address: 0x1002b00 */
      break;
  }

} /* Line 404, Address: 0x1002b0c */



void dodai_upx(act_info* pActwk) { /* Line 408, Address: 0x1002b20 */
  short coli;

  switch (pActwk->actfree[1]) { /* Line 411, Address: 0x1002b30 */
    case 0:
      if (!dodai_fix(pActwk)) break; /* Line 413, Address: 0x1002b64 */



      pActwk->actfree[1] += 2; /* Line 417, Address: 0x1002b78 */
      pActwk->actfree[4] = 60; /* Line 418, Address: 0x1002b88 */
    case 2:
      if (pActwk->actfree[4]) { /* Line 420, Address: 0x1002b94 */
        --pActwk->actfree[4]; /* Line 421, Address: 0x1002ba4 */
        dodai_fix(pActwk); /* Line 422, Address: 0x1002bb4 */
        break; /* Line 423, Address: 0x1002bc0 */
      }

      speedset2(pActwk); /* Line 426, Address: 0x1002bc8 */
      pActwk->yspeed.w -= 8; /* Line 427, Address: 0x1002bd4 */

      if ((coli = emycol_u(pActwk)) >= 0) { /* Line 429, Address: 0x1002be4 */
        dodai_ride2(pActwk); /* Line 430, Address: 0x1002c10 */
        break; /* Line 431, Address: 0x1002c1c */
      }

      pActwk->yposi.w.h -= coli; /* Line 434, Address: 0x1002c24 */
      ((short*)pActwk)[31] = pActwk->yposi.w.h; /* Line 435, Address: 0x1002c34 */
      pActwk->actfree[1] += 2; /* Line 436, Address: 0x1002c44 */
    case 4:
      dodai_fix(pActwk); /* Line 438, Address: 0x1002c54 */
      break;
  }

} /* Line 442, Address: 0x1002c60 */



void dodai_rm(act_info* pActwk) { /* Line 446, Address: 0x1002c80 */
  int xsav;

  switch (pActwk->actfree[1]) { /* Line 449, Address: 0x1002c90 */
    case 0:
      if (!dodai_fix(pActwk)) break; /* Line 451, Address: 0x1002cc4 */



      pActwk->actfree[1] += 2; /* Line 455, Address: 0x1002cd8 */
      pActwk->actfree[4] = 60; /* Line 456, Address: 0x1002ce8 */
    case 2:
      if (pActwk->actfree[4]) { /* Line 458, Address: 0x1002cf4 */
        --pActwk->actfree[4]; /* Line 459, Address: 0x1002d04 */
        dodai_fix(pActwk); /* Line 460, Address: 0x1002d14 */
        break; /* Line 461, Address: 0x1002d20 */
      }

      if (pActwk->actfree[0] < 64) { /* Line 464, Address: 0x1002d28 */
        xsav = pActwk->xposi.l; /* Line 465, Address: 0x1002d40 */
        pActwk->xposi.w.h = ((short*)pActwk)[30] + dodai_sub(pActwk); /* Line 466, Address: 0x1002d48 */

        ++pActwk->actfree[0]; /* Line 468, Address: 0x1002d80 */
        pActwk->yposi.w.h = ((char)pActwk->actfree[2] >> 1) + ((short*)pActwk)[31]; /* Line 469, Address: 0x1002d90 */

        dodai_ride1(pActwk, xsav); /* Line 471, Address: 0x1002dd0 */
        break; /* Line 472, Address: 0x1002de0 */
      }

      ((short*)pActwk)[30] = pActwk->xposi.w.h; /* Line 475, Address: 0x1002de8 */
      pActwk->actfree[1] += 2; /* Line 476, Address: 0x1002df8 */
    case 4:
      dodai_fix(pActwk); /* Line 478, Address: 0x1002e08 */
      break;
  }

} /* Line 482, Address: 0x1002e14 */



void dodai_lm(act_info* pActwk) { /* Line 486, Address: 0x1002e30 */
  int xsav;

  switch (pActwk->actfree[1]) { /* Line 489, Address: 0x1002e40 */
    case 0:
      if (!dodai_fix(pActwk)) break; /* Line 491, Address: 0x1002e74 */



      pActwk->actfree[1] += 2; /* Line 495, Address: 0x1002e88 */
      pActwk->actfree[4] = 60; /* Line 496, Address: 0x1002e98 */
    case 2:
      if (pActwk->actfree[4]) { /* Line 498, Address: 0x1002ea4 */
        --pActwk->actfree[4]; /* Line 499, Address: 0x1002eb4 */
        dodai_fix(pActwk); /* Line 500, Address: 0x1002ec4 */
        break; /* Line 501, Address: 0x1002ed0 */
      }

      if (pActwk->actfree[0] < 64) { /* Line 504, Address: 0x1002ed8 */
        xsav = pActwk->xposi.l; /* Line 505, Address: 0x1002ef0 */
        pActwk->xposi.w.h = ((short*)pActwk)[30] - dodai_sub(pActwk); /* Line 506, Address: 0x1002ef8 */

        ++pActwk->actfree[0]; /* Line 508, Address: 0x1002f30 */
        pActwk->yposi.w.h = ((char)pActwk->actfree[2] >> 1) + ((short*)pActwk)[31]; /* Line 509, Address: 0x1002f40 */

        dodai_ride1(pActwk, xsav); /* Line 511, Address: 0x1002f80 */
        break; /* Line 512, Address: 0x1002f90 */
      }

      ((short*)pActwk)[30] = pActwk->xposi.w.h; /* Line 515, Address: 0x1002f98 */
      pActwk->actfree[1] += 2; /* Line 516, Address: 0x1002fa8 */
    case 4:
      dodai_fix(pActwk); /* Line 518, Address: 0x1002fb8 */
      break;
  }

} /* Line 522, Address: 0x1002fc4 */














short dodai_sub(act_info* pActwk) { /* Line 537, Address: 0x1002fe0 */
  short sinwk, coswk;

  sinset((unsigned char)(char)pActwk->actfree[0], &sinwk, &coswk); /* Line 540, Address: 0x1002fec */
  return (sinwk * (short)((char*)pActwk)[49]) >> 4; /* Line 541, Address: 0x1003010 */
} /* Line 542, Address: 0x1003044 */











void dai_fout(act_info* pActwk) { /* Line 554, Address: 0x1003060 */
  short s;

  if (pActwk->cdsts) { /* Line 557, Address: 0x1003070 */
    s = time_flag + pActwk->cdsts * 3; /* Line 558, Address: 0x1003080 */
    flagwork[s] &= 127; /* Line 559, Address: 0x10030b4 */
  }

  frameout(pActwk); /* Line 562, Address: 0x10030d4 */
} /* Line 563, Address: 0x10030e0 */































































void vfuta(act_info* pActwk) { /* Line 627, Address: 0x1003100 */
  vfuta_tbl[pActwk->r_no0 / 2](pActwk); /* Line 628, Address: 0x100310c */
  actionsub(pActwk); /* Line 629, Address: 0x1003150 */
  frameout_s(pActwk); /* Line 630, Address: 0x100315c */
} /* Line 631, Address: 0x1003168 */





void vfuta_init(act_info* pActwk) { /* Line 637, Address: 0x1003180 */
  pActwk->r_no0 += 2; /* Line 638, Address: 0x100318c */
  pActwk->patbase = vfutapat; /* Line 639, Address: 0x100319c */
  pActwk->sprpri = 1; /* Line 640, Address: 0x10031ac */
  pActwk->actflg |= 4; /* Line 641, Address: 0x10031b8 */
  pActwk->sprhsize = 4; /* Line 642, Address: 0x10031c8 */
  pActwk->sprvsize = 24; /* Line 643, Address: 0x10031d4 */

  pa_set(); /* Line 645, Address: 0x10031e0 */
  vfuta_move1(pActwk); /* Line 646, Address: 0x10031e8 */
} /* Line 647, Address: 0x10031f4 */





void vfuta_move1(act_info* pActwk) { /* Line 653, Address: 0x1003210 */
  short wk;

  if ((wk = pActwk->yposi.w.h - actwk[0].yposi.w.h) < 0) {; /* Line 656, Address: 0x1003220 */
    wk = -wk; /* Line 657, Address: 0x100326c */
  }

  if (wk < 32) { /* Line 660, Address: 0x1003288 */
    wk = pActwk->xposi.w.h - actwk[0].xposi.w.h; /* Line 661, Address: 0x100329c */

    if (0 <= wk && wk < 49) { /* Line 663, Address: 0x10032d0 */
      pActwk->actfree[16] = pActwk->actfree[17] = 0; /* Line 664, Address: 0x10032f8 */
      pActwk->r_no0 = 4; /* Line 665, Address: 0x100330c */

      if (pActwk->actflg & 128) { /* Line 667, Address: 0x1003318 */
        soundset(164); /* Line 668, Address: 0x1003330 */
        pActwk->patno = 1; /* Line 669, Address: 0x100333c */
      }
    }
  }

  ride_on_chk(pActwk, &actwk[0]); /* Line 674, Address: 0x1003348 */
} /* Line 675, Address: 0x100335c */





void vfuta_move2(act_info* pActwk) { /* Line 681, Address: 0x1003370 */
  short wk;

  wk = pActwk->actfree[16]; /* Line 684, Address: 0x100337c */
  wk += 8; /* Line 685, Address: 0x1003390 */
  pActwk->actfree[16] += 8; /* Line 686, Address: 0x100339c */

  if (wk >= 256) { /* Line 688, Address: 0x10033ac */
    pActwk->r_no0 -= 2; /* Line 689, Address: 0x10033c0 */
    pActwk->patno = 0; /* Line 690, Address: 0x10033d0 */
  }
} /* Line 692, Address: 0x10033d8 */
