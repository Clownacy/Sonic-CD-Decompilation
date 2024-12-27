#include "EQU.H"
#include "SCORE.H"
#include "ACTION.H"
#include "IMPFUNCS.H"
#include "LOADER2.H"

static void tensuu(sprite_status* pAct);
static void ten_init(sprite_status* pAct);
static void ten_move(sprite_status* pAct);
static void score_init(sprite_status* pAct);
static void score_move(sprite_status* pAct);
static void ringinit();
static void scoreinit();
static void posiwrt();
static void bonuswrt(sprite_data* pSprdat, unsigned int lDispVal);
static void ringwrt(sprite_data* pSprdat, unsigned int lDispVal);
static void scorewrt(sprite_data* pSprdat, unsigned int lDispVal);
static void scorewrt2(sprite_data* pSprdat, unsigned int lDispVal, unsigned int* subval, short sD6, short zero_disp);
static void posiwrt0(sprite_data* pSprdat, unsigned int lDispVal);
static void playsuuwrt(sprite_data* pSprdat);
static void timewrt1(sprite_data* pSprdat, unsigned int lDispVal);
static void timewrt(sprite_data* pSprdat, unsigned int lDispVal);
static void timewrt0(sprite_data* pSprdat, unsigned int lDispVal, unsigned int* subval, short sD6);

extern short playdieset(sprite_status* pActwk);

#if defined(R31) || defined(R32)
  #define SPRITE_LIFEICON_PAST 359
  #define SPRITE_LIFEICON_PRESENT 358
  #define SPRITE_LIFEICON_FUTURE 357
  #define SPRITE_RINGS_NORMAL 355
  #define SPRITE_RINGS_DANGER 356
  #define SPRITE_DIGIT_0 329
  #define SPRITE_TEN_BASE 345
  #define SPRITE_SCORE_BASE 350
#elif defined(R33)
  #define SPRITE_LIFEICON_PAST 363
  #define SPRITE_LIFEICON_PRESENT 362
  #define SPRITE_LIFEICON_FUTURE 361
  #define SPRITE_RINGS_NORMAL 359
  #define SPRITE_RINGS_DANGER 360
  #define SPRITE_DIGIT_0 333
  #define SPRITE_TEN_BASE 349
  #define SPRITE_SCORE_BASE 354
#elif defined(R6)
  #define SPRITE_LIFEICON_PAST 358
  #define SPRITE_LIFEICON_PRESENT 357
  #define SPRITE_LIFEICON_FUTURE 356
  #define SPRITE_RINGS_NORMAL 354
  #define SPRITE_RINGS_DANGER 355
  #define SPRITE_DIGIT_0 328
  #define SPRITE_TEN_BASE 344
  #define SPRITE_SCORE_BASE 349
#elif defined(R81)
  #define SPRITE_LIFEICON_PAST 348
  #define SPRITE_LIFEICON_PRESENT 347
  #define SPRITE_LIFEICON_FUTURE 346
  #define SPRITE_RINGS_NORMAL 344
  #define SPRITE_RINGS_DANGER 345
  #define SPRITE_DIGIT_0 318
  #define SPRITE_TEN_BASE 334
  #define SPRITE_SCORE_BASE 339
#elif defined(R82)
  #define SPRITE_LIFEICON_PAST 357
  #define SPRITE_LIFEICON_PRESENT 356
  #define SPRITE_LIFEICON_FUTURE 355
  #define SPRITE_RINGS_NORMAL 353
  #define SPRITE_RINGS_DANGER 354
  #define SPRITE_DIGIT_0 327
  #define SPRITE_TEN_BASE 343
  #define SPRITE_SCORE_BASE 348
#elif defined(R83)
  #define SPRITE_LIFEICON_PAST 350
  #define SPRITE_LIFEICON_PRESENT 349
  #define SPRITE_LIFEICON_FUTURE 348
  #define SPRITE_RINGS_NORMAL 346
  #define SPRITE_RINGS_DANGER 347
  #define SPRITE_DIGIT_0 320
  #define SPRITE_TEN_BASE 336
  #define SPRITE_SCORE_BASE 341
#else
  #define SPRITE_LIFEICON_PAST 338
  #define SPRITE_LIFEICON_PRESENT 337
  #define SPRITE_LIFEICON_FUTURE 336
  #define SPRITE_RINGS_NORMAL 334
  #define SPRITE_RINGS_DANGER 335
  #define SPRITE_DIGIT_0 308
  #define SPRITE_TEN_BASE 324
  #define SPRITE_SCORE_BASE 329
#endif

static unsigned int subtbl[6] = { 100000, 10000, 1000, 100, 10, 1 };
static unsigned int subtblh4[4] = { 4096, 256, 16, 1 };
static sprite_pattern tenpat0 = {
  2,
  {
    { -8, 0, 0, SPRITE_TEN_BASE },
    { 0, 0, 0, SPRITE_TEN_BASE + 3 }
  }
};
static sprite_pattern tenpat1 = {
  2,
  {
    { -8, 0, 0, SPRITE_TEN_BASE + 1 },
    { 0, 0, 0, SPRITE_TEN_BASE + 3 }
  }
};
static sprite_pattern tenpat2 = {
  2,
  {
    { -8, 0, 0, SPRITE_TEN_BASE + 2 },
    { 0, 0, 0, SPRITE_TEN_BASE + 3 }
  }
};
static sprite_pattern tenpat3 = {
  2,
  {
    { -8, 0, 0, SPRITE_TEN_BASE + 4 },
    { 0, 0, 0, SPRITE_TEN_BASE + 3 }
  }
};
static sprite_pattern tenpat4 = {
  1,
  { { -4, 0, 0, SPRITE_TEN_BASE + 4 } }
};
static sprite_pattern tenpat5 = {
  3,
  {
    { -12, 0, 0, SPRITE_TEN_BASE },
    { -4, 0, 0, SPRITE_TEN_BASE + 3 },
    { 4, 0, 0, SPRITE_TEN_BASE + 3 }
  }
};
static sprite_pattern* tenpat[6] = {
  &tenpat0,
  &tenpat1,
  &tenpat2,
  &tenpat3,
  &tenpat4,
  &tenpat5
};
sprite_pattern scorepat0 = {
  19,
  {
    { 0, 0, 0, SPRITE_SCORE_BASE },
    { 40, 0, 0, 0 },
    { 48, 0, 0, 0 },
    { 56, 0, 0, 0 },
    { 64, 0, 0, 0 },
    { 72, 0, 0, 0 },
    { 80, 0, 0, 0 },
    { 88, 0, 0, SPRITE_DIGIT_0 },
    { 0, 16, 0, SPRITE_SCORE_BASE + 1 },
    { 40, 16, 0, SPRITE_DIGIT_0 },
    { 48, 16, 0, SPRITE_SCORE_BASE + 2 },
    { 56, 16, 0, SPRITE_DIGIT_0 },
    { 64, 16, 0, SPRITE_DIGIT_0 },
    { 72, 16, 0, SPRITE_SCORE_BASE + 3 },
    { 80, 16, 0, SPRITE_DIGIT_0 },
    { 88, 16, 0, SPRITE_DIGIT_0 },
    { 48, 32, 0, 0 },
    { 56, 32, 0, 0 },
    { 64, 32, 0, SPRITE_DIGIT_0 }
  }
};
sprite_pattern scorepat1 = {
  3,
  {
    { 0, 0, 0, SPRITE_SCORE_BASE + 8 },
    { 16, 8, 0, SPRITE_SCORE_BASE + 4 },
    { 24, 4, 0, SPRITE_DIGIT_0 }
  }
};
sprite_pattern scorepat2 = {
  15,
  {
    { 0, 0, 0, SPRITE_SCORE_BASE },
    { 40, 0, 0, 0 },
    { 48, 0, 0, 0 },
    { 56, 0, 0, 0 },
    { 64, 0, 0, 0 },
    { 72, 0, 0, 0 },
    { 80, 0, 0, SPRITE_DIGIT_0 },
    { 0, 16, 0, SPRITE_SCORE_BASE + 1 },
    { 56, 16, 0, 0 },
    { 64, 16, 0, 0 },
    { 72, 16, 0, 0 },
    { 80, 16, 0, SPRITE_DIGIT_0 },
    { 48, 32, 0, 0 },
    { 56, 32, 0, 0 },
    { 64, 32, 0, SPRITE_DIGIT_0 }
  }
};
sprite_pattern scorepat3 = {
  1,
  { { 0, 32, 0, SPRITE_SCORE_BASE + 5 } }
};
static sprite_pattern* scorepat[4] = {
  &scorepat0,
  &scorepat1,
  &scorepat2,
  &scorepat3
};
extern sprite_pattern bonuspat;
extern sprite_pattern bonuspat0;
unsigned char scoreinittbl[7] = { 255, 255, 255, 255, 255, 255, 0 };
unsigned char ringinittbl[3] = { 255, 255, 0 };























































































static void tensuu(sprite_status* pAct) { /* Line 295, Address: 0x10050b0 */
  if (!pAct->r_no0) ten_init(pAct); /* Line 296, Address: 0x10050bc */
  ten_move(pAct); /* Line 297, Address: 0x10050d8 */
  actionsub(pAct); /* Line 298, Address: 0x10050e4 */


} /* Line 301, Address: 0x10050f0 */


static void ten_init(sprite_status* pAct) { /* Line 304, Address: 0x1005100 */
  pAct->r_no0 = 2; /* Line 305, Address: 0x1005108 */
  pAct->actflg = 4; /* Line 306, Address: 0x1005114 */
  pAct->patbase = tenpat; /* Line 307, Address: 0x1005120 */
  pAct->patno = pAct->userflag.b.h & 127; /* Line 308, Address: 0x1005130 */
  pAct->actfree[0] = 24; /* Line 309, Address: 0x1005150 */


} /* Line 312, Address: 0x100515c */


static void ten_move(sprite_status* pAct) { /* Line 315, Address: 0x1005170 */
  --pAct->actfree[0]; /* Line 316, Address: 0x100517c */


  if (!pAct->actfree[0]) /* Line 319, Address: 0x100518c */
    frameout(pAct); /* Line 320, Address: 0x100519c */
  pAct->yposi.w.h -= 2; /* Line 321, Address: 0x10051a8 */


} /* Line 324, Address: 0x10051b8 */


void score(sprite_status* pAct) { /* Line 327, Address: 0x10051d0 */
  if ((unsigned char)pAct->userflag.b.h & 128) { /* Line 328, Address: 0x10051dc */
    tensuu(pAct); /* Line 329, Address: 0x10051f8 */
    return; /* Line 330, Address: 0x1005204 */
  }
  if (!pAct->r_no0) score_init(pAct); /* Line 332, Address: 0x100520c */
  score_move(pAct); /* Line 333, Address: 0x1005228 */

} /* Line 335, Address: 0x1005234 */


static void score_init(sprite_status* pAct) { /* Line 338, Address: 0x1005250 */
  pAct->r_no0 = 2; /* Line 339, Address: 0x1005258 */
  pAct->patbase = scorepat; /* Line 340, Address: 0x1005264 */
  pAct->sproffset = 32768; /* Line 341, Address: 0x1005274 */
  pAct->xposi.w.h = 144; /* Line 342, Address: 0x1005280 */
  pAct->yposi.w.h = 136; /* Line 343, Address: 0x100528c */
  if (pAct->userflag.b.l) { /* Line 344, Address: 0x1005298 */
    pAct->patno = 3; /* Line 345, Address: 0x10052a8 */
    return; /* Line 346, Address: 0x10052b4 */
  }

  if (debugflag.w) { /* Line 349, Address: 0x10052bc */
    pAct->patno = 2; /* Line 350, Address: 0x10052cc */
  }

  if (pAct->userflag.b.h) { /* Line 353, Address: 0x10052d8 */
    pAct->yposi.w.h = 328; /* Line 354, Address: 0x10052e8 */
    pAct->patno = 1; /* Line 355, Address: 0x10052f4 */

    switch (time_flag & 3) { /* Line 357, Address: 0x1005300 */
      case 0:
        scorepat1.spra[0].index = SPRITE_LIFEICON_PAST; /* Line 359, Address: 0x100532c */
        break; /* Line 360, Address: 0x1005338 */
      case 1:
        scorepat1.spra[0].index = SPRITE_LIFEICON_PRESENT; /* Line 362, Address: 0x1005340 */
        break; /* Line 363, Address: 0x100534c */
      default:
        scorepat1.spra[0].index = SPRITE_LIFEICON_FUTURE; /* Line 365, Address: 0x1005354 */
        break;
    }
  }


} /* Line 371, Address: 0x1005360 */

static void score_move(sprite_status* pAct) { /* Line 373, Address: 0x1005370 */
  if (!pAct->userflag.b.h) { /* Line 374, Address: 0x100537c */
    if (pAct->userflag.b.l) { /* Line 375, Address: 0x100538c */
      if (plring) { /* Line 376, Address: 0x100539c */
        pAct->sproffset = 32768; /* Line 377, Address: 0x10053ac */
        scorepat3.spra[0].index = SPRITE_RINGS_NORMAL; /* Line 378, Address: 0x10053b8 */

      } /* Line 380, Address: 0x10053c4 */
      else {

        if (!(systemtimer.b.b4 & 15)) { /* Line 383, Address: 0x10053cc */
          if (scorepat3.spra[0].index == SPRITE_RINGS_NORMAL) /* Line 384, Address: 0x10053e8 */
            scorepat3.spra[0].index = SPRITE_RINGS_DANGER; /* Line 385, Address: 0x1005400 */
          else
            scorepat3.spra[0].index = SPRITE_RINGS_NORMAL; /* Line 387, Address: 0x1005414 */
        }
      }
    } /* Line 390, Address: 0x1005420 */
    else {

      pAct->patno = 0; /* Line 393, Address: 0x1005428 */
      if (debugflag.w) { /* Line 394, Address: 0x1005430 */
        pAct->patno = 2; /* Line 395, Address: 0x1005440 */
      }
    }
  }

  actionsub(pAct); /* Line 400, Address: 0x100544c */


} /* Line 403, Address: 0x1005458 */




void scoreup(unsigned int updata) { /* Line 408, Address: 0x1005470 */
  plscore_f = 1; /* Line 409, Address: 0x100547c */

  plscore += updata; /* Line 411, Address: 0x1005488 */
  if ((unsigned int)plscore > 999999) { /* Line 412, Address: 0x10054a0 */

    plscore = 999999; /* Line 414, Address: 0x10054bc */
  }
  if (extrascore > (unsigned int)plscore) return; /* Line 416, Address: 0x10054cc */


  extrascore += 5000; /* Line 419, Address: 0x10054e8 */
  ++pl_suu; /* Line 420, Address: 0x10054fc */
  ++pl_suu_f; /* Line 421, Address: 0x1005510 */
  WaveAllStop(); /* Line 422, Address: 0x1005524 */
  sub_sync(122); /* Line 423, Address: 0x1005534 */


} /* Line 426, Address: 0x1005540 */





void scoreset() { /* Line 432, Address: 0x1005550 */
  sprite_data* pSprdat;
  sprite_pattern* pSprpat;

  pSprdat = &scorepat2.spra[3]; /* Line 436, Address: 0x1005560 */
  if (debugflag.w) { /* Line 437, Address: 0x1005568 */
    posiwrt(); /* Line 438, Address: 0x1005578 */

    pSprdat = &scorepat2.spra[12]; /* Line 440, Address: 0x1005580 */
    timewrt0(pSprdat, blkno & 2047, &subtbl[3], 2); /* Line 441, Address: 0x1005588 */
  } /* Line 442, Address: 0x10055b4 */
  else {

    if (plscore_f) { /* Line 445, Address: 0x10055bc */
      if (plscore_f & 128) { /* Line 446, Address: 0x10055cc */
        scoreinit(); /* Line 447, Address: 0x10055e4 */
      }

      plscore_f = 0; /* Line 450, Address: 0x10055ec */
      pSprdat = &scorepat0.spra[1]; /* Line 451, Address: 0x10055f4 */
      scorewrt(pSprdat, plscore); /* Line 452, Address: 0x10055fc */
    }

    if (plring_f) { /* Line 455, Address: 0x1005610 */
      if (plring_f & 128) { /* Line 456, Address: 0x1005620 */
        ringinit(); /* Line 457, Address: 0x1005638 */
      }

      plring_f = 0; /* Line 460, Address: 0x1005640 */
      if (plring > 999) plring = 999; /* Line 461, Address: 0x1005648 */

      pSprdat = &scorepat0.spra[16]; /* Line 463, Address: 0x1005670 */
      ringwrt(pSprdat, plring); /* Line 464, Address: 0x1005678 */
    }
  }

  if (!debugflag.w && pltime_f && !pauseflag.b.h) { /* Line 468, Address: 0x1005694 */
    if (pltime.l == 604987) { /* Line 469, Address: 0x10056c4 */

      if (time_flag & 128) return; /* Line 471, Address: 0x10056dc */



      pltime_f = 0; /* Line 475, Address: 0x10056f4 */
      pltime.l = 0; /* Line 476, Address: 0x10056fc */
      playdieset(&actwk[0]); /* Line 477, Address: 0x1005704 */
      pltimeover_f = 1; /* Line 478, Address: 0x1005714 */

      return; /* Line 480, Address: 0x1005720 */
    }
    if (pltime.l != 604987) { /* Line 482, Address: 0x1005728 */
      if (!plautoflag) { /* Line 483, Address: 0x1005740 */

        ++pltime.b.b4; /* Line 485, Address: 0x1005750 */
        if ((unsigned char)pltime.b.b4 >= 60) { /* Line 486, Address: 0x1005764 */
          pltime.b.b4 = 0; /* Line 487, Address: 0x1005780 */
          ++pltime.b.b3; /* Line 488, Address: 0x1005788 */
          if ((unsigned char)pltime.b.b3 >= 60) { /* Line 489, Address: 0x100579c */
            pltime.b.b3 = 0; /* Line 490, Address: 0x10057b8 */
            ++pltime.b.b2; /* Line 491, Address: 0x10057c0 */
            if ((unsigned char)pltime.b.b2 >= 9) { /* Line 492, Address: 0x10057d4 */
              pltime.b.b2 = 9; /* Line 493, Address: 0x10057f0 */
            }
          }
        }
      }
    }

    pSprdat = &scorepat0.spra[9]; /* Line 500, Address: 0x10057fc */
    timewrt1(pSprdat, pltime.b.b2); /* Line 501, Address: 0x1005804 */

    pSprdat = &scorepat0.spra[11]; /* Line 503, Address: 0x1005820 */
    timewrt(pSprdat, pltime.b.b3); /* Line 504, Address: 0x1005828 */

    pSprdat = &scorepat0.spra[14]; /* Line 506, Address: 0x1005844 */
    if (pltime.l == 604987) { /* Line 507, Address: 0x100584c */
      timewrt(pSprdat, 99); /* Line 508, Address: 0x1005864 */
    } /* Line 509, Address: 0x1005874 */
    else {
      timewrt(pSprdat, (pltime.b.b4 * 100) / 60); /* Line 511, Address: 0x100587c */
    }
  }


  if (pl_suu_f) { /* Line 516, Address: 0x10058c4 */
    pl_suu_f = 0; /* Line 517, Address: 0x10058d4 */
    pSprdat = &scorepat1.spra[2]; /* Line 518, Address: 0x10058dc */
    playsuuwrt(pSprdat); /* Line 519, Address: 0x10058e4 */
  }

  if (bonus_f) { /* Line 522, Address: 0x10058f0 */
    bonus_f = 0; /* Line 523, Address: 0x1005900 */
    if (stageno.w == 1282) pSprpat = &bonuspat0; /* Line 524, Address: 0x1005908 */
    else pSprpat = &bonuspat; /* Line 525, Address: 0x1005934 */
    bonuswrt(&pSprpat->spra[8], (unsigned short)ringbonus); /* Line 526, Address: 0x100593c */
    bonuswrt(&pSprpat->spra[13], (unsigned short)timebonus); /* Line 527, Address: 0x1005958 */
    scorewrt(&pSprpat->spra[1], plscore); /* Line 528, Address: 0x1005974 */
    pSprpat->spra[7].index = SPRITE_DIGIT_0; /* Line 529, Address: 0x1005988 */
  }


} /* Line 533, Address: 0x1005990 */








static void ringinit() {} /* Line 542, Address: 0x10059b0 */

static void scoreinit() { /* Line 544, Address: 0x10059c0 */
  sprite_data* pSprdat;

  pSprdat = &scorepat1.spra[2]; /* Line 547, Address: 0x10059cc */
  playsuuwrt(pSprdat); /* Line 548, Address: 0x10059d4 */


} /* Line 551, Address: 0x10059e0 */













static void posiwrt() { /* Line 565, Address: 0x1005a00 */
  sprite_data* pSprdat;
  int_union lwk;

  lwk.l = 0; /* Line 569, Address: 0x1005a0c */
  lwk.w.l = actwk[0].xposi.w.h; /* Line 570, Address: 0x1005a10 */
  pSprdat = &scorepat2.spra[3]; /* Line 571, Address: 0x1005a1c */
  posiwrt0(pSprdat, lwk.l); /* Line 572, Address: 0x1005a24 */

  lwk.w.l = actwk[0].xposi.w.h; /* Line 574, Address: 0x1005a34 */
  pSprdat = &scorepat2.spra[8]; /* Line 575, Address: 0x1005a40 */
  posiwrt0(pSprdat, lwk.l); /* Line 576, Address: 0x1005a48 */
} /* Line 577, Address: 0x1005a58 */



static void bonuswrt(sprite_data* pSprdat, unsigned int lDispVal) { /* Line 581, Address: 0x1005a70 */
  scorewrt2(pSprdat, lDispVal, &subtbl[1], 4, 1); /* Line 582, Address: 0x1005a80 */

} /* Line 584, Address: 0x1005aa0 */

static void ringwrt(sprite_data* pSprdat, unsigned int lDispVal) { /* Line 586, Address: 0x1005ab0 */
  scorewrt2(pSprdat, lDispVal, &subtbl[3], 2, 1); /* Line 587, Address: 0x1005ac0 */

} /* Line 589, Address: 0x1005ae0 */


static void scorewrt(sprite_data* pSprdat, unsigned int lDispVal) { /* Line 592, Address: 0x1005af0 */
  scorewrt2(pSprdat, lDispVal, &subtbl[0], 5, 0); /* Line 593, Address: 0x1005b00 */

} /* Line 595, Address: 0x1005b20 */

static void scorewrt2(sprite_data* pSprdat, unsigned int lDispVal, unsigned int* subval, short sD6, short zero_disp) { /* Line 597, Address: 0x1005b30 */
  unsigned int lDisp1;
  int wrt = 0; /* Line 599, Address: 0x1005b50 */

  do {
    lDisp1 = lDispVal / *subval; /* Line 602, Address: 0x1005b54 */
    lDispVal -= lDisp1 * *subval; /* Line 603, Address: 0x1005b74 */
    ++subval; /* Line 604, Address: 0x1005b8c */
    if (lDisp1 != 0) { /* Line 605, Address: 0x1005b98 */
      wrt = 1; /* Line 606, Address: 0x1005ba0 */
    }
    if (wrt != 0 || (sD6 == 0 && zero_disp)) { /* Line 608, Address: 0x1005ba4 */
      pSprdat->index = (unsigned short)lDisp1 + SPRITE_DIGIT_0; /* Line 609, Address: 0x1005bcc */
    } /* Line 610, Address: 0x1005be4 */
    else {
      pSprdat->index = 0; /* Line 612, Address: 0x1005bec */
    }
    ++pSprdat; /* Line 614, Address: 0x1005bf4 */
  } while (--sD6 >= 0); /* Line 615, Address: 0x1005c00 */


} /* Line 618, Address: 0x1005c24 */





static void posiwrt0(sprite_data* pSprdat, unsigned int lDispVal) { /* Line 624, Address: 0x1005c40 */
  timewrt0(pSprdat, lDispVal, &subtblh4[0], 3); /* Line 625, Address: 0x1005c50 */

} /* Line 627, Address: 0x1005c6c */


static void playsuuwrt(sprite_data* pSprdat) { /* Line 630, Address: 0x1005c80 */
  unsigned int lDispVal;

  if (pl_suu > 9) /* Line 633, Address: 0x1005c90 */
    lDispVal = 9; /* Line 634, Address: 0x1005ca8 */
  else
    lDispVal = pl_suu; /* Line 636, Address: 0x1005cb4 */

  timewrt0(pSprdat, lDispVal, &subtbl[5], 0); /* Line 638, Address: 0x1005cc0 */

} /* Line 640, Address: 0x1005cdc */



static void timewrt1(sprite_data* pSprdat, unsigned int lDispVal) { /* Line 644, Address: 0x1005cf0 */
  timewrt0(pSprdat, lDispVal, &subtbl[5], 0); /* Line 645, Address: 0x1005d00 */

} /* Line 647, Address: 0x1005d1c */

static void timewrt(sprite_data* pSprdat, unsigned int lDispVal) { /* Line 649, Address: 0x1005d30 */
  timewrt0(pSprdat, lDispVal, &subtbl[4], 1); /* Line 650, Address: 0x1005d40 */

} /* Line 652, Address: 0x1005d5c */







static void timewrt0(sprite_data* pSprdat, unsigned int lDispVal, unsigned int* subval, short sD6) { /* Line 660, Address: 0x1005d70 */
  unsigned short lDisp1;

  do {
    lDisp1 = lDispVal / *subval; /* Line 664, Address: 0x1005d88 */
    lDispVal -= lDisp1 * *subval; /* Line 665, Address: 0x1005db0 */
    ++subval; /* Line 666, Address: 0x1005dcc */
    pSprdat->index = lDisp1 + SPRITE_DIGIT_0; /* Line 667, Address: 0x1005dd8 */
    ++pSprdat; /* Line 668, Address: 0x1005dec */
  } while (--sD6 >= 0); /* Line 669, Address: 0x1005df8 */













} /* Line 683, Address: 0x1005e1c */
