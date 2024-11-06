#include "EQU.H"
#include "ZONE.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "DUMMY.H"
#include "SCORE.H"

extern void sub_sync(short ReqNo);
extern void soundset(short ReqNo);

static sprite_pattern game0 = {
  1,
  { { -72, -8, 0, 379 } }
};
static sprite_pattern game1 = {
  1,
  { { 8, -8, 0, 380 } }
};
sprite_pattern* gamepat[2] = {
  &game0,
  &game1
};
static sprite_pattern time0 = {
  1,
  { { -68, -8, 0, 381 } }
};
static sprite_pattern time1 = {
  1,
  { { 4, -8, 0, 382 } }
};
sprite_pattern* timepat[2] = {
  &time0,
  &time1
};
static sprite_pattern gotpat0 = {
  1,
  { { -68, -20, 0, 383 } }
};
static sprite_pattern gotpat1 = {
  1,
  { { -100, 4, 0, 384 } }
};
static sprite_pattern gotpat2 = {
  1,
  { { -100, 4, 0, 385 } }
};
static sprite_pattern gotpat3 = {
  1,
  { { -100, 4, 0, 386 } }
};
static sprite_pattern madepat0 = {
  1,
  { { -128, -20, 0, 387 } }
};
static sprite_pattern madepat1 = {
  1,
  { { -112, 4, 0, 388 } }
};
static sprite_pattern madepat2 = {
  1,
  { { -112, 4, 0, 389 } }
};
static sprite_pattern madepat3 = {
  1,
  { { -112, 4, 0, 390 } }
};
sprite_pattern bonuspat = {
  18,
  {
  {
    { -44, -32, 0, 391 },
    { 72, -32, 0, 0 },
    { 80, -32, 0, 0 },
    { 88, -32, 0, 0 },
    { 96, -32, 0, 0 },
    { 104, -32, 0, 0 },
    { 112, -32, 0, 0 },
    { 120, -32, 0, 0 },
    { 88, -8, 0, 0 },
    { 96, -8, 0, 0 },
    { 104, -8, 0, 0 },
    { 112, -8, 0, 0 },
    { 120, -8, 0, 0 },
    { 88, 16, 0, 0 },
    { 96, 16, 0, 0 },
    { 104, 16, 0, 0 },
    { 112, 16, 0, 0 },
    { 120, 16, 0, 0 }
  }
  }
};
sprite_pattern bonuspat0 = {
  18,
  {
  {
    { -44, -32, 0, 392 },
    { 72, -32, 0, 0 },
    { 80, -32, 0, 0 },
    { 88, -32, 0, 0 },
    { 96, -32, 0, 0 },
    { 104, -32, 0, 0 },
    { 112, -32, 0, 0 },
    { 120, -32, 0, 0 },
    { 88, -8, 0, 0 },
    { 96, -8, 0, 0 },
    { 104, -8, 0, 0 },
    { 112, -8, 0, 0 },
    { 120, -8, 0, 0 },
    { 88, 16, 0, 0 },
    { 96, 16, 0, 0 },
    { 104, 16, 0, 0 },
    { 112, 16, 0, 0 },
    { 120, 16, 0, 0 }
  }
  }
};
sprite_pattern* gotpat[5] = {
  &gotpat0,
  &bonuspat,
  &gotpat1,
  &gotpat2,
  &gotpat3
};
sprite_pattern* gotpat_0[5] = {
  &gotpat0,
  &bonuspat0,
  &gotpat1,
  &gotpat2,
  &gotpat3
};
sprite_pattern* madepat[5] = {
  &madepat0,
  &bonuspat,
  &madepat1,
  &madepat2,
  &madepat3
};
sprite_pattern* madepat_0[5] = {
  &madepat0,
  &bonuspat0,
  &madepat1,
  &madepat2,
  &madepat3
};
extern sprite_pattern* title_pat[];
extern unsigned short title_tbl[];
static unsigned short ClearSountWait;
static short WaitCount;
static unsigned short cleartbl[12] = {
  204,   0, 288,   0,
  272, 512, 240,   1,
  204,   0, 288,   2
};
extern void(*WaveAllStop)();




















































































































void over(sprite_status* pAct) { /* Line 271, Address: 0x1012340 */
  switch (pAct->r_no0) { /* Line 272, Address: 0x101234c */
    case 0:
      over_init(pAct); /* Line 274, Address: 0x1012374 */
      break; /* Line 275, Address: 0x1012380 */
    case 2:
      over_move(pAct); /* Line 277, Address: 0x1012388 */
      break;
  }

} /* Line 281, Address: 0x1012394 */


static void over_init(sprite_status* pAct) { /* Line 284, Address: 0x10123b0 */
  sprite_status* pTmpAct;

  sub_sync(130); /* Line 287, Address: 0x10123bc */
  pAct->r_no0 = 2; /* Line 288, Address: 0x10123c8 */
  pAct->yposi.w.h = 224; /* Line 289, Address: 0x10123d4 */
  pAct->xposi.w.h = 128; /* Line 290, Address: 0x10123e0 */
  ((short*)pAct)[23] = 288; /* Line 291, Address: 0x10123ec */
  pAct->sproffset = 32768; /* Line 292, Address: 0x10123f8 */
  pAct->patbase = gamepat; /* Line 293, Address: 0x1012404 */
  plsubchg_flag = 8; /* Line 294, Address: 0x1012414 */
  if (pltimeover_f & 1) { /* Line 295, Address: 0x1012420 */
    pltimeover_f &= 254; /* Line 296, Address: 0x1012438 */
    if (pl_suu) { /* Line 297, Address: 0x101244c */
      pAct->patbase = timepat; /* Line 298, Address: 0x101245c */
      plsubchg_flag = 2; /* Line 299, Address: 0x101246c */
    }
  } /* Line 301, Address: 0x1012478 */
  else {

    pltimeover_f &= 254; /* Line 304, Address: 0x1012480 */
    if (pl_suu) { /* Line 305, Address: 0x1012494 */

      frameout(pAct); /* Line 307, Address: 0x10124a4 */
      return; /* Line 308, Address: 0x10124b0 */
    }
  }

  plsubchg_flag |= 128; /* Line 312, Address: 0x10124b8 */
  if (actwkchk(&pTmpAct) != 0) { /* Line 313, Address: 0x10124cc */

    frameout(pAct); /* Line 315, Address: 0x10124e0 */
    return; /* Line 316, Address: 0x10124ec */
  }

  pTmpAct->actno = 59; /* Line 319, Address: 0x10124f4 */
  pTmpAct->r_no0 = pAct->r_no0; /* Line 320, Address: 0x1012500 */
  pTmpAct->sproffset = pAct->sproffset; /* Line 321, Address: 0x1012510 */
  pTmpAct->patbase = pAct->patbase; /* Line 322, Address: 0x1012520 */
  pTmpAct->patno = 1; /* Line 323, Address: 0x1012530 */
  pTmpAct->yposi.w.h = 224; /* Line 324, Address: 0x101253c */
  pTmpAct->xposi.w.h = 448; /* Line 325, Address: 0x1012548 */
  ((short*)pTmpAct)[23] = 288; /* Line 326, Address: 0x1012554 */

  if (pl_suu) { /* Line 328, Address: 0x1012560 */
    over_move(pAct); /* Line 329, Address: 0x1012570 */
  } /* Line 330, Address: 0x101257c */
  else {
    sub_sync(110); /* Line 332, Address: 0x1012584 */
  }
} /* Line 334, Address: 0x1012590 */


static void over_move(sprite_status* pAct) { /* Line 337, Address: 0x10125a0 */
  if (pAct->xposi.w.h < (short)((unsigned short*)pAct)[23]) { /* Line 338, Address: 0x10125ac */
    pAct->xposi.w.h += 8; /* Line 339, Address: 0x10125e0 */
  } /* Line 340, Address: 0x10125f0 */
  else if (pAct->xposi.w.h > (short)((unsigned short*)pAct)[23]) { /* Line 341, Address: 0x10125f8 */
    pAct->xposi.w.h -= 8; /* Line 342, Address: 0x101262c */
  }
  actionsub(pAct); /* Line 344, Address: 0x101263c */

} /* Line 346, Address: 0x1012648 */



void title(sprite_status* pAct) { /* Line 350, Address: 0x1012660 */
  switch (pAct->r_no0) { /* Line 351, Address: 0x101266c */
    case 0:
      title_init(pAct); /* Line 353, Address: 0x10126c4 */
      break; /* Line 354, Address: 0x10126d0 */
    case 2:
      title_move0(pAct); /* Line 356, Address: 0x10126d8 */
      break; /* Line 357, Address: 0x10126e4 */
    case 4:
      title_move1(pAct); /* Line 359, Address: 0x10126ec */
      break; /* Line 360, Address: 0x10126f8 */
    case 6:
      title_back0(pAct); /* Line 362, Address: 0x1012700 */
      break; /* Line 363, Address: 0x101270c */
    case 8:
      title_back1(pAct); /* Line 365, Address: 0x1012714 */
      break; /* Line 366, Address: 0x1012720 */
    case 10:
      title_wait(pAct); /* Line 368, Address: 0x1012728 */
      break;
  }

} /* Line 372, Address: 0x1012734 */


static void title_init(sprite_status* pAct) { /* Line 375, Address: 0x1012750 */
  sprite_status* pTmpAct;
  unsigned short* wp;
  int i;

  pAct->r_no0 = 2; /* Line 380, Address: 0x1012764 */
  pAct->xposi.w.h = 280; /* Line 381, Address: 0x1012770 */
  pAct->yposi.w.h = 48; /* Line 382, Address: 0x101277c */
  ((short*)pAct)[26] = 48; /* Line 383, Address: 0x1012788 */
  ((short*)pAct)[25] = 240; /* Line 384, Address: 0x1012794 */
  pAct->pattim = 90; /* Line 385, Address: 0x10127a0 */
  pAct->sproffset = 32768; /* Line 386, Address: 0x10127ac */
  pAct->patbase = title_pat; /* Line 387, Address: 0x10127b8 */
  pAct->sprpri = 4; /* Line 388, Address: 0x10127c8 */



  wp = title_tbl; /* Line 392, Address: 0x10127d4 */
  for (i = 0; i < 8; ++i) { /* Line 393, Address: 0x10127dc */
    actwkchk(&pTmpAct); /* Line 394, Address: 0x10127e8 */
    pTmpAct->actno = 60; /* Line 395, Address: 0x10127f4 */
    pTmpAct->r_no0 = 4; /* Line 396, Address: 0x1012800 */
    pTmpAct->sproffset = 32768; /* Line 397, Address: 0x101280c */
    pTmpAct->patbase = title_pat; /* Line 398, Address: 0x1012818 */

    pTmpAct->yposi.w.h = *wp++; /* Line 400, Address: 0x1012828 */
    pTmpAct->xposi.w.h = *wp; /* Line 401, Address: 0x101283c */
    ((short*)pTmpAct)[24] = *wp++; /* Line 402, Address: 0x1012848 */
    ((short*)pTmpAct)[23] = *wp++; /* Line 403, Address: 0x101285c */
    pTmpAct->patno = (*wp & 65280) >> 8; /* Line 404, Address: 0x1012870 */
    if (i == 5) { /* Line 405, Address: 0x101288c */
      pTmpAct->patno = pTmpAct->patno + (unsigned char)stageno.b.l; /* Line 406, Address: 0x1012898 */
    }
    pTmpAct->pattim = *wp++ & 255; /* Line 408, Address: 0x10128c4 */
  } /* Line 409, Address: 0x10128e4 */

} /* Line 411, Address: 0x10128f4 */



static void title_move0(sprite_status* pAct) { /* Line 415, Address: 0x1012910 */
  if (pAct->yposi.w.h == (short)((unsigned short*)pAct)[25]) { /* Line 416, Address: 0x101291c */
    pAct->r_no0 += 4; /* Line 417, Address: 0x101294c */
  } /* Line 418, Address: 0x101295c */
  else if (pAct->yposi.w.h < (short)((unsigned short*)pAct)[25]) { /* Line 419, Address: 0x1012964 */
    pAct->yposi.w.h += 8; /* Line 420, Address: 0x1012998 */
  } /* Line 421, Address: 0x10129a8 */
  else {
    pAct->yposi.w.h -= 8; /* Line 423, Address: 0x10129b0 */
  }
  actionsub(pAct); /* Line 425, Address: 0x10129c0 */

} /* Line 427, Address: 0x10129cc */


static void title_move1(sprite_status* pAct) { /* Line 430, Address: 0x10129e0 */
  if (pAct->xposi.w.h == (short)((unsigned short*)pAct)[23]) { /* Line 431, Address: 0x10129ec */
    pAct->r_no0 += 4; /* Line 432, Address: 0x1012a1c */
  } /* Line 433, Address: 0x1012a2c */
  else if (pAct->xposi.w.h < (short)((unsigned short*)pAct)[23]) { /* Line 434, Address: 0x1012a34 */
    pAct->xposi.w.h += 8; /* Line 435, Address: 0x1012a68 */
  } /* Line 436, Address: 0x1012a78 */
  else {
    pAct->xposi.w.h -= 8; /* Line 438, Address: 0x1012a80 */
  }
  actionsub(pAct); /* Line 440, Address: 0x1012a90 */


} /* Line 443, Address: 0x1012a9c */


static void title_back0(sprite_status* pAct) { /* Line 446, Address: 0x1012ab0 */
  if (pAct->pattim) { /* Line 447, Address: 0x1012abc */
    --pAct->pattim; /* Line 448, Address: 0x1012acc */
  } /* Line 449, Address: 0x1012adc */
  else {
    if (pAct->yposi.w.h == (short)((unsigned short*)pAct)[26]) { /* Line 451, Address: 0x1012ae4 */
      pAct->r_no0 += 4; /* Line 452, Address: 0x1012b14 */
      scroll_start.b.h = 1; /* Line 453, Address: 0x1012b24 */
      return; /* Line 454, Address: 0x1012b30 */
    }
    if (pAct->yposi.w.h < (short)((unsigned short*)pAct)[26]) { /* Line 456, Address: 0x1012b38 */
      pAct->yposi.w.h += 16; /* Line 457, Address: 0x1012b6c */
    } /* Line 458, Address: 0x1012b7c */
    else {
      pAct->yposi.w.h -= 16; /* Line 460, Address: 0x1012b84 */
    }
  }
  actionsub(pAct); /* Line 463, Address: 0x1012b94 */

} /* Line 465, Address: 0x1012ba0 */


static void title_back1(sprite_status* pAct) { /* Line 468, Address: 0x1012bb0 */
  if (pAct->pattim) { /* Line 469, Address: 0x1012bbc */
    --pAct->pattim; /* Line 470, Address: 0x1012bcc */
  } /* Line 471, Address: 0x1012bdc */
  else {
    if (pAct->xposi.w.h == (short)((unsigned short*)pAct)[24]) { /* Line 473, Address: 0x1012be4 */
      frameout(pAct); /* Line 474, Address: 0x1012c14 */
      return; /* Line 475, Address: 0x1012c20 */
    }
    if (pAct->xposi.w.h < (short)((unsigned short*)pAct)[24]) { /* Line 477, Address: 0x1012c28 */
      pAct->xposi.w.h += 16; /* Line 478, Address: 0x1012c5c */
    } /* Line 479, Address: 0x1012c6c */
    else {
      pAct->xposi.w.h -= 16; /* Line 481, Address: 0x1012c74 */
    }
  }
  actionsub(pAct); /* Line 484, Address: 0x1012c84 */

} /* Line 486, Address: 0x1012c90 */


static void title_wait(sprite_status* pAct) { /* Line 489, Address: 0x1012ca0 */
  scroll_start.b.h = 0; /* Line 490, Address: 0x1012cac */
  plautoflag = 0; /* Line 491, Address: 0x1012cb4 */
  frameout(pAct); /* Line 492, Address: 0x1012cbc */

} /* Line 494, Address: 0x1012cc8 */






void clear(sprite_status* pAct) { /* Line 501, Address: 0x1012ce0 */
  switch (pAct->r_no0) { /* Line 502, Address: 0x1012cec */
    case 0:
      clear_init0(pAct); /* Line 504, Address: 0x1012d50 */
      ClearSountWait = systemtimer.w.l; /* Line 505, Address: 0x1012d5c */
      break; /* Line 506, Address: 0x1012d6c */
    case 2:
      clear_init(pAct); /* Line 508, Address: 0x1012d74 */
      ClearSountWait = systemtimer.w.l; /* Line 509, Address: 0x1012d80 */
      break; /* Line 510, Address: 0x1012d90 */
    case 4:
      clear_move0(pAct); /* Line 512, Address: 0x1012d98 */
      break; /* Line 513, Address: 0x1012da4 */
    case 6:
      clear_move1(pAct); /* Line 515, Address: 0x1012dac */
      break; /* Line 516, Address: 0x1012db8 */

    case 8:
      if ((unsigned short)((unsigned short)systemtimer.w.l - ClearSountWait) >= 720) { /* Line 519, Address: 0x1012dc0 */
        pAct->r_no0 += 2; /* Line 520, Address: 0x1012df4 */
      }
      actionsub(pAct); /* Line 522, Address: 0x1012e04 */
      break; /* Line 523, Address: 0x1012e10 */
    case 10:
      clear_move2(pAct); /* Line 525, Address: 0x1012e18 */
      break; /* Line 526, Address: 0x1012e24 */
    case 12:
      clear_wait(pAct); /* Line 528, Address: 0x1012e2c */
      break;
  }

} /* Line 532, Address: 0x1012e38 */

static void clear_init0(sprite_status* pAct) { /* Line 534, Address: 0x1012e50 */
  --pAct->actfree[8]; /* Line 535, Address: 0x1012e5c */
  if (!pAct->actfree[8]) { /* Line 536, Address: 0x1012e6c */
    pAct->r_no0 = 2; /* Line 537, Address: 0x1012e7c */
    clear_init(pAct); /* Line 538, Address: 0x1012e88 */
  }

  WaitCount = 1; pAct->r_no0 = 12; /* Line 541, Address: 0x1012e94 */

} /* Line 543, Address: 0x1012eac */








static void clear_init(sprite_status* pAct) { /* Line 552, Address: 0x1012ec0 */
  sprite_status* pTmpAct;
  unsigned short* wp;
  int i;

  if (stageno.w == 1282) goto label1; /* Line 557, Address: 0x1012ed4 */
  if (actwk[0].xposi.w.h > (short)(scra_h_posit.w.h + 336)) { /* Line 558, Address: 0x1012ef0 */



label1:
    pTmpAct = pAct; /* Line 563, Address: 0x1012f30 */
    wp = cleartbl; /* Line 564, Address: 0x1012f38 */
    for (i = 0; i < 3; ++i) { /* Line 565, Address: 0x1012f40 */
      ((short*)pTmpAct)[27] = 360; /* Line 566, Address: 0x1012f4c */
      pTmpAct->actno = 58; /* Line 567, Address: 0x1012f58 */
      pTmpAct->r_no0 = 4; /* Line 568, Address: 0x1012f64 */
      pTmpAct->sproffset = 32768; /* Line 569, Address: 0x1012f70 */
      if (stageno.w == 1282) { /* Line 570, Address: 0x1012f7c */
        pTmpAct->sproffset = 32768; /* Line 571, Address: 0x1012f98 */
        pTmpAct->patbase = gotpat_0; /* Line 572, Address: 0x1012fa4 */
        if (generate_flag) { /* Line 573, Address: 0x1012fb4 */
          pTmpAct->patbase = madepat_0; /* Line 574, Address: 0x1012fc4 */
        }
      } /* Line 576, Address: 0x1012fd4 */
      else {

        pTmpAct->patbase = gotpat; /* Line 579, Address: 0x1012fdc */
        if (generate_flag) { /* Line 580, Address: 0x1012fec */
          pTmpAct->patbase = madepat; /* Line 581, Address: 0x1012ffc */
        }
      }

      pTmpAct->yposi.w.h = *wp++; /* Line 585, Address: 0x101300c */
      pTmpAct->xposi.w.h = *wp++; /* Line 586, Address: 0x1013020 */
      ((short*)pTmpAct)[23] = *wp++; /* Line 587, Address: 0x1013034 */
      pTmpAct->patno = *wp++ & 255; /* Line 588, Address: 0x1013048 */

      if (i == 2) {  /* Line 590, Address: 0x1013068 */
        pTmpAct->patno = pTmpAct->patno + stageno.b.l; /* Line 591, Address: 0x1013074 */
      }
      actwkchk(&pTmpAct); /* Line 593, Address: 0x10130a0 */
    } /* Line 594, Address: 0x10130ac */
  }
} /* Line 596, Address: 0x10130bc */



static void clear_move0(sprite_status* pAct) { /* Line 600, Address: 0x10130e0 */
  if (((unsigned short*)pAct)[27]) { /* Line 601, Address: 0x10130ec */
    --((unsigned short*)pAct)[27]; /* Line 602, Address: 0x10130fc */
  }

  if (pAct->xposi.w.h == (short)((unsigned short*)pAct)[23]) { /* Line 605, Address: 0x101310c */

    if (!pAct->patno) { /* Line 607, Address: 0x101313c */
      pAct->r_no0 += 2; /* Line 608, Address: 0x101314c */
    }
  } /* Line 610, Address: 0x101315c */
  else if (pAct->xposi.w.h > (short)((unsigned short*)pAct)[23]) { /* Line 611, Address: 0x1013164 */
    pAct->xposi.w.h -= 8; /* Line 612, Address: 0x1013198 */
  } /* Line 613, Address: 0x10131a8 */
  else {
    pAct->xposi.w.h += 8; /* Line 615, Address: 0x10131b0 */
  }


  if (((unsigned short*)pAct)[27] < 352) { /* Line 619, Address: 0x10131c0 */
    actionsub(pAct); /* Line 620, Address: 0x10131d8 */
  }

} /* Line 623, Address: 0x10131e4 */



static void clear_move1(sprite_status* pAct) { // Line 627, Address: 0x1013200
  int_union lD0;

  lD0.l = 0; // Line 630, Address: 0x101320c
  bonus_f = 1; // Line 631, Address: 0x1013210
  if (!timebonus) { // Line 632, Address: 0x101321c
    if (!ringbonus) { // Line 633, Address: 0x101322c
      --((unsigned short*)pAct)[27]; // Line 634, Address: 0x101323c
      if (((short*)pAct)[27] < 0) { // Line 635, Address: 0x101324c
        pAct->r_no0 += 2; // Line 636, Address: 0x1013264
        if (systemtimer.w.l - ClearSountWait >= 540) { // Line 637, Address: 0x1013274
          ClearSountWait = systemtimer.w.l - 540; // Line 638, Address: 0x10132a0
        }
      }

      if (((short*)pAct)[27] == 30) { // Line 642, Address: 0x10132c0
        if (special_flag) { // Line 643, Address: 0x10132dc
          soundset(200); // Line 644, Address: 0x10132ec
        }
      }

      actionsub(pAct); // Line 648, Address: 0x10132f8
      return; // Line 649, Address: 0x1013304
    }
  }

  if (timebonus) { // Line 653, Address: 0x101330c
    lD0.w.l += 10; // Line 654, Address: 0x101331c
    timebonus -= 100; // Line 655, Address: 0x1013328
  }
  if (ringbonus) { // Line 657, Address: 0x101333c

    lD0.w.l += 10; // Line 659, Address: 0x101334c
    ringbonus -= 100; // Line 660, Address: 0x1013358
  }

  if (!timebonus && !ringbonus) { // Line 663, Address: 0x101336c
    WaveAllStop(); // Line 664, Address: 0x101338c
    soundset(154); // Line 665, Address: 0x101339c
    if (((unsigned short*)pAct)[27] >= 45) { // Line 666, Address: 0x10133a8
      ((unsigned short*)pAct)[27] = 45; // Line 667, Address: 0x10133c0
    }
  } // Line 669, Address: 0x10133cc
  else {

    if (((unsigned short*)pAct)[27]) { // Line 672, Address: 0x10133d4
      --((unsigned short*)pAct)[27]; // Line 673, Address: 0x10133e4
    }

    if (pAct->actfree[8] % 2 == 0) { // Line 676, Address: 0x10133f4
      soundset(189); // Line 677, Address: 0x1013424
    }
  }

  scoreup(lD0.l); // Line 681, Address: 0x1013430
  actionsub(pAct); // Line 682, Address: 0x101343c

} // Line 684, Address: 0x1013448


static void clear_move2(sprite_status* pAct) { // Line 687, Address: 0x1013460
  short_union wD0;

  gameflag.w = 2; // Line 690, Address: 0x101346c
  plflag = 0; // Line 691, Address: 0x1013478
  enecgflg = 0; // Line 692, Address: 0x1013480

  flowercnt[0] = 0; // Line 694, Address: 0x1013488
  flowercnt[1] = 0; // Line 695, Address: 0x1013490
  flowercnt[2] = 0; // Line 696, Address: 0x1013498
  tv_flag = 0; // Line 697, Address: 0x10134a0

  enkeino = 0; // Line 699, Address: 0x10134a8
  projector_flag = 0; // Line 700, Address: 0x10134b0
  markerno = 0; // Line 701, Address: 0x10134b8

  if (ta_flag) { // Line 703, Address: 0x10134c0
    play_start &= 254; // Line 704, Address: 0x10134d0
  }

  play_start &= 253; // Line 707, Address: 0x10134e4
  time_flag = 1; // Line 708, Address: 0x10134f8
  wD0.w = stageno.w; // Line 709, Address: 0x1013504
  ++wD0.b.l; // Line 710, Address: 0x1013510
  if (wD0.b.l == 2) { // Line 711, Address: 0x101351c
    time_flag = 2; // Line 712, Address: 0x1013534
  }
  if (wD0.b.l == 3) { // Line 714, Address: 0x1013540
    ++wD0.b.h; // Line 715, Address: 0x1013558
    wD0.b.l = 0; // Line 716, Address: 0x1013564
  }
  stageno.w = wD0.w; // Line 718, Address: 0x1013568

  flagwkclr(); // Line 720, Address: 0x1013574
  fadeout_s(); // Line 721, Address: 0x101357c
  actionsub(pAct); // Line 722, Address: 0x1013584
  if (stageno.b.l == 0) { // Line 723, Address: 0x1013590
    gf_flag = 0; // Line 724, Address: 0x10135a8
    return; // Line 725, Address: 0x10135b0
  }

  if (!ta_flag) { // Line 728, Address: 0x10135b8
    if (clrspflg_save != 127) { // Line 729, Address: 0x10135c8
      if (!generate_flag) return; // Line 730, Address: 0x10135e0
      generate_flag = 0; // Line 731, Address: 0x10135f0

      gf_flag |= 1 << stageno.b.l - 1; // Line 733, Address: 0x10135f8
      if (gf_flag != 3) return; // Line 734, Address: 0x101362c
    }

    generate_flag = 1; // Line 737, Address: 0x1013644
  }

} // Line 740, Address: 0x1013650


static void clear_wait(sprite_status* pAct) { /* Line 743, Address: 0x1013660 */
  if (!--WaitCount) pAct->r_no0 = 2; /* Line 744, Address: 0x1013668 */
} /* Line 745, Address: 0x1013698 */
