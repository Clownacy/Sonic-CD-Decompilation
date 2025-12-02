#include "..\EQU.H"
#include "BOSS_6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\ETC.H"
#include "..\GOAL.H"
#include "..\IO.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"
#include "..\SCORE.H"
#include "COL6C.H"
#include "COLI6.H"

static unsigned char stbStx;
static unsigned char stbPatOff;
static char stbRad;
void(*boss6_tbl[11])(sprite_status*) =
{
  &egg6_start,
  &egg6_ini,
  &egg6_down,
  &egg6_hover,
  &egg6_up,
  &egg6_event,
  &egg6_dead1,
  &egg6_dead2,
  &egg6_dead3,
  &egg6_dead4,
  &egg6_none
};
unsigned char e6pat_pchg0[22] = { 4, 0, 0, 1, 1, 0, 2, 3, 3, 2, 2, 1, 1, 0, 0, 1, 3, 2, 2, 3, 3, 255 };
unsigned char e6pat_pchg1[6] = { 4, 6, 4, 7, 5, 255 };
unsigned char e6pat_pchg2[3] = { 255, 8, 255 };
unsigned char e6pat_pchg3[4] = { 20, 9, 10, 255 };
unsigned char e6pat_pchg4[10] = { 2, 11, 14, 13, 16, 12, 15, 13, 16, 255 };
unsigned char* egg6_pchg[5] =
{
  e6pat_pchg0,
  e6pat_pchg1,
  e6pat_pchg2,
  e6pat_pchg3,
  e6pat_pchg4
};
sprite_pattern e6spr_pat00 = { 1, { { -24, -20, 0, 462 } } };
sprite_pattern e6spr_pat01 = { 1, { { -24, -20, 0, 463 } } };
sprite_pattern e6spr_pat02 = { 1, { { -24, -20, 0, 464 } } };
sprite_pattern e6spr_pat03 = { 1, { { -24, -20, 0, 465 } } };
sprite_pattern e6spr_pat04 = { 1, { { -24, -20, 0, 466 } } };
sprite_pattern e6spr_pat05 = { 1, { { -24, -20, 0, 467 } } };
sprite_pattern e6spr_pat06 = { 1, { { -24, -36, 0, 468 } } };
sprite_pattern e6spr_pat07 = { 1, { { -24, -36, 0, 469 } } };
sprite_pattern e6spr_pat08 = { 1, { { -28, -36, 0, 470 } } };
sprite_pattern e6spr_pat09 = { 1, { { -24, -28, 0, 471 } } };
sprite_pattern e6spr_pat10 = { 1, { { -24, -28, 0, 472 } } };
sprite_pattern e6spr_pat11 = { 1, { { -32, -36, 0, 473 } } };
sprite_pattern e6spr_pat12 = { 1, { { -32, -32, 0, 474 } } };
sprite_pattern e6spr_pat13 = { 1, { { -32, -34, 0, 475 } } };
sprite_pattern e6spr_pat14 = { 1, { { -32, -52, 0, 476 } } };
sprite_pattern e6spr_pat15 = { 1, { { -32, -52, 0, 477 } } };
sprite_pattern e6spr_pat16 = { 1, { { -32, -50, 0, 478 } } };
sprite_pattern* egg6_pat[17] = { &e6spr_pat00, &e6spr_pat01, &e6spr_pat02, &e6spr_pat03, &e6spr_pat04, &e6spr_pat05, &e6spr_pat06, &e6spr_pat07, &e6spr_pat08, &e6spr_pat09, &e6spr_pat10, &e6spr_pat11, &e6spr_pat12, &e6spr_pat13, &e6spr_pat14, &e6spr_pat15, &e6spr_pat16 };
extern short scr_dir_tbl[];
sprite_pattern e6meca_pat00 = { 1, { { -64, -32, 0, 479 } } };
sprite_pattern e6meca_pat01 = { 1, { { -64, -16, 0, 480 } } };
sprite_pattern* egg6meca0_pat[2] = { &e6meca_pat00, &e6meca_pat01 };
sprite_pattern e6hari_pat00 = { 1, { { -16, -16, 0, 481 } } };
sprite_pattern e6hari_pat01 = { 1, { { -16, -16, 0, 482 } } };
sprite_pattern e6hari_pat02 = { 1, { { -16, -16, 0, 483 } } };
sprite_pattern e6hari_pat03 = { 1, { { -16, -16, 0, 484 } } };
sprite_pattern* egg6meca1_pat[4] = { &e6hari_pat00, &e6hari_pat01, &e6hari_pat02, &e6hari_pat03 };
unsigned char egg6_fire_pchg00[6] = { 2, 0, 2, 1, 3, 255 };
unsigned char egg6_fire_pchg01[4] = { 1, 2, 3, 255 };
unsigned char* egg6meca2_pchg[2] =
{
  egg6_fire_pchg00,
  egg6_fire_pchg01
};
sprite_pattern e6fire_pat00 = { 1, { { -16, -16, 0, 485 } } };
sprite_pattern e6fire_pat01 = { 1, { { -16, -16, 0, 486 } } };
sprite_pattern e6fire_pat02 = { 1, { { -16, -16, 0, 487 } } };
sprite_pattern e6fire_pat03 = { 1, { { -16, -16, 0, 488 } } };
sprite_pattern* egg6meca2_pat[4] = { &e6fire_pat00, &e6fire_pat01, &e6fire_pat02, &e6fire_pat03 };
sprite_pattern e6bakuha_pat00 = { 1, { { -12, -12, 0, 490 } } };
sprite_pattern e6bakuha_pat01 = { 1, { { -16, -16, 0, 491 } } };
sprite_pattern e6bakuha_pat02 = { 1, { { -16, -16, 0, 492 } } };
sprite_pattern e6bakuha_pat03 = { 1, { { -12, -16, 0, 493 } } };
sprite_pattern e6bakuha_pat04 = { 1, { { -12, -16, 0, 494 } } };
sprite_pattern e6bakuha_pat05 = { 1, { { -12, -16, 0, 495 } } };
sprite_pattern e6bakuha_pat06 = { 1, { { -12, -16, 0, 496 } } };
sprite_pattern* egg6bakuha_pat[8] = { &e6bakuha_pat00, &e6bakuha_pat01, &e6bakuha_pat02, &e6bakuha_pat03, &e6bakuha_pat04, &e6bakuha_pat05, &e6bakuha_pat06, &e6bakuha_pat06 };
unsigned char egg6bakuha_pchg00[5] = { 8, 0, 1, 2, 255 };
unsigned char egg6bakuha_pchg01[12] = { 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 7, 255 };
unsigned char* egg6bakuha_pchg[2] =
{
  egg6bakuha_pchg00,
  egg6bakuha_pchg01
};
sprite_pattern e6toge_pat00 = { 1, { { -4, -12, 0, 489 } } };
sprite_pattern* egg6toge_pat[1] = { &e6toge_pat00 };
sprite_pattern e6gareki_pat00 = { 1, { { -8, -8, 0, 501 } } };
sprite_pattern e6gareki_pat01 = { 1, { { -8, -8, 0, 502 } } };
sprite_pattern* egg6gareki_pat[2] = { &e6gareki_pat00, &e6gareki_pat01 };
unsigned char egg6gareki_pchg00[4] = { 8, 0, 1, 255 };
unsigned char* egg6gareki_pchg[1] = { egg6gareki_pchg00 };
sprite_pattern e6beam_pat00 = { 1, { { -8, -8, 0, 509 } } };
sprite_pattern e6beam_pat01 = { 1, { { -8, -8, 0, 510 } } };
sprite_pattern e6beam_pat02 = { 1, { { -8, -8, 0, 511 } } };
sprite_pattern e6beam_pat03 = { 1, { { -8, -8, 0, 512 } } };
sprite_pattern e6beam_pat04 = { 1, { { -8, -8, 0, 513 } } };
sprite_pattern* egg6beam_pat[5] = { &e6beam_pat00, &e6beam_pat01, &e6beam_pat02, &e6beam_pat03, &e6beam_pat04 };
sprite_pattern e6beam2_pat00 = { 1, { { -8, -8, 0, 514 } } };
sprite_pattern e6beam2_pat01 = { 1, { { -8, -8, 0, 515 } } };
sprite_pattern e6beam2_pat02 = { 1, { { -8, -8, 0, 516 } } };
sprite_pattern e6beam2_pat03 = { 1, { { -8, -8, 0, 517 } } };
sprite_pattern e6beam2_pat04 = { 1, { { -8, -8, 0, 518 } } };
sprite_pattern* egg6beam2_pat[5] = { &e6beam2_pat00, &e6beam2_pat01, &e6beam2_pat02, &e6beam2_pat03, &e6beam2_pat04 };
sprite_pattern e6beam3_pat00 = { 1, { { -8, -8, 0, 519 } } };
sprite_pattern e6beam3_pat01 = { 1, { { -8, -8, 0, 520 } } };
sprite_pattern e6beam3_pat02 = { 1, { { -8, -8, 0, 521 } } };
sprite_pattern e6beam3_pat03 = { 1, { { -8, -8, 0, 522 } } };
sprite_pattern e6beam3_pat04 = { 1, { { -8, -8, 0, 523 } } };
sprite_pattern* egg6beam3_pat[5] = { &e6beam3_pat00, &e6beam3_pat01, &e6beam3_pat02, &e6beam3_pat03, &e6beam3_pat04 };
sprite_pattern e6yuka_pat00 =
{
  2,
  {
    { -16, -16, 0, 507 },
    { -16, 0, 0, 508 }
  }
};
sprite_pattern* egg6yuka_pat[1] = { &e6yuka_pat00 };
sprite_pattern e6beamer_pat00 = { 1, { { -8, -16, 0, 497 } } };
sprite_pattern e6beamer_pat01 = { 1, { { -8, -16, 0, 498 } } };
sprite_pattern* egg6beamer_pat[2] = { &e6beamer_pat00, &e6beamer_pat01 };
sprite_pattern e6door_pat00 = { 1, { { -40, -42, 0, 499 } } };
sprite_pattern e6door_pat01 = { 1, { { -8, -74, 0, 500 } } };
sprite_pattern* egg6door_pat[2] = { &e6door_pat00, &e6door_pat01 };
sprite_pattern e6gareki4_pat00 = { 1, { { -8, -8, 0, 503 } } };
sprite_pattern e6gareki4_pat01 = { 1, { { -8, -8, 0, 504 } } };
sprite_pattern e6gareki4_pat02 = { 1, { { -8, -8, 0, 505 } } };
sprite_pattern e6gareki4_pat03 = { 1, { { -8, -8, 0, 506 } } };
sprite_pattern* egg6gareki4_pat[4] = { &e6gareki4_pat00, &e6gareki4_pat01, &e6gareki4_pat02, &e6gareki4_pat03 };
sprite_pattern* egg6_pat_yarare[6] = { &e6spr_pat11, &e6spr_pat12, &e6spr_pat13, &e6spr_pat14, &e6spr_pat15, &e6spr_pat16 };
unsigned char egg6beam_pchg00[18] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5 };
unsigned char* egg6beam_pchg[1] = { egg6beam_pchg00 };



























































































































































































void egg6boss(sprite_status* pActwk) { /* Line 335, Address: 0x1027f20 */
  egg6_jisin(pActwk); /* Line 336, Address: 0x1027f2c */
  egg6_hitchk(pActwk); /* Line 337, Address: 0x1027f38 */

  stbStx = 0; /* Line 339, Address: 0x1027f44 */
  boss6_tbl[pActwk->r_no0 / 2](pActwk); /* Line 340, Address: 0x1027f4c */
  if (stbStx != 0) return; /* Line 341, Address: 0x1027f90 */
  egg6_beam_ctrl(); /* Line 342, Address: 0x1027fa4 */
  patchg(pActwk, egg6_pchg); /* Line 343, Address: 0x1027fac */
  actionsub(pActwk); /* Line 344, Address: 0x1027fc0 */
} /* Line 345, Address: 0x1027fcc */











void egg6_hitchk(sprite_status* pActwk) { /* Line 357, Address: 0x1027fe0 */
  sprite_status* pActbp;


  if (!(pActwk->actfree[2] & 1)) return; /* Line 361, Address: 0x1027ff0 */


  if (pActwk->actfree[13] != 0) /* Line 364, Address: 0x1028008 */
  {
    --pActwk->actfree[13]; /* Line 366, Address: 0x102801c */
    if (pActwk->actfree[13] == 0) /* Line 367, Address: 0x102802c */
      egg6_coliset(pActwk); /* Line 368, Address: 0x1028040 */
    return; /* Line 369, Address: 0x102804c */
  }

  pActbp = &actwk[((unsigned short*)pActwk)[25]]; /* Line 372, Address: 0x1028054 */
  if (pActwk->colino != 0) /* Line 373, Address: 0x1028078 */
  {
    if (pActbp->colino != 0) return; /* Line 375, Address: 0x102808c */
  }


  ++pActwk->actfree[15]; /* Line 379, Address: 0x102809c */
  pActwk->colino = 0; /* Line 380, Address: 0x10280ac */
  pActbp->colino = 0; /* Line 381, Address: 0x10280b4 */
  pActwk->mstno.b.h = 1; /* Line 382, Address: 0x10280b8 */
  pActwk->patno = 0; /* Line 383, Address: 0x10280c4 */
  pActwk->actfree[13] = 30; /* Line 384, Address: 0x10280cc */

  soundset(172); /* Line 386, Address: 0x10280d8 */
} /* Line 387, Address: 0x10280e4 */











void egg6_coliset(sprite_status* pActwk) { /* Line 399, Address: 0x1028100 */
  sprite_status* pActbp;

  pActbp = &actwk[((unsigned short*)pActwk)[25]]; /* Line 402, Address: 0x102810c */
  pActwk->colino = 60; /* Line 403, Address: 0x1028130 */
  pActwk->colicnt = 2; /* Line 404, Address: 0x102813c */
  pActbp->colino = 61; /* Line 405, Address: 0x1028148 */
  pActbp->colicnt = 2; /* Line 406, Address: 0x1028150 */
} /* Line 407, Address: 0x1028158 */











void egg6_beam_ctrl(void) { /* Line 419, Address: 0x1028170 */
  unsigned char byD0;

  byD0 = get_beam_pos(); /* Line 422, Address: 0x102817c */
  byD0 = 1 << byD0; /* Line 423, Address: 0x102818c */
  if (!(bossstart & byD0)) /* Line 424, Address: 0x10281a0 */
  {

    if (bossflag & 128) return; /* Line 427, Address: 0x10281bc */

    bossflag |= 64; /* Line 429, Address: 0x10281d4 */
    return; /* Line 430, Address: 0x10281e8 */
  }

  bossflag &= 127; /* Line 433, Address: 0x10281f0 */
} /* Line 434, Address: 0x1028204 */











void egg6_start(sprite_status* pActwk) { /* Line 446, Address: 0x1028220 */
  if (actwk[0].xposi.w.h < 2688) /* Line 447, Address: 0x102822c */
  {
    stbStx = 1; /* Line 449, Address: 0x1028248 */
    return; /* Line 450, Address: 0x1028254 */
  }
  pActwk->r_no0 = 2; /* Line 452, Address: 0x102825c */
  egg6_ini(pActwk); /* Line 453, Address: 0x1028268 */
} /* Line 454, Address: 0x1028274 */











void egg6_ini(sprite_status* pActwk) { /* Line 466, Address: 0x1028290 */
  if (!(bossflag & 15)) /* Line 467, Address: 0x102829c */
  {

    colorset(6); /* Line 470, Address: 0x10282b4 */
    colorset2(6); /* Line 471, Address: 0x10282c0 */




    make_meca(pActwk); /* Line 476, Address: 0x10282cc */

    pActwk->actflg |= 4; /* Line 478, Address: 0x10282d8 */
    pActwk->sprpri = 4; /* Line 479, Address: 0x10282e8 */
    pActwk->sprhsize = 24; /* Line 480, Address: 0x10282f4 */
    pActwk->sprvsize = 24; /* Line 481, Address: 0x1028300 */
    pActwk->sproffset = 1004; /* Line 482, Address: 0x102830c */
    pActwk->patbase = egg6_pat; /* Line 483, Address: 0x1028318 */

    pActwk->actfree[2] |= 1; /* Line 485, Address: 0x1028328 */
    egg6_coliset(pActwk); /* Line 486, Address: 0x1028338 */

    bossflag &= 240; /* Line 488, Address: 0x1028344 */
    bossflag += 6; /* Line 489, Address: 0x1028358 */
    bossflag |= 16; /* Line 490, Address: 0x102836c */
    bossstart = 6; /* Line 491, Address: 0x1028380 */
    scralim_left = 2528; /* Line 492, Address: 0x102838c */
    scralim_n_left = 2528; /* Line 493, Address: 0x1028398 */
    scralim_right = 2656; /* Line 494, Address: 0x10283a4 */
    scralim_n_right = 2656; /* Line 495, Address: 0x10283b0 */
    return; /* Line 496, Address: 0x10283bc */
  }

  ++((short*)pActwk)[23]; /* Line 499, Address: 0x10283c4 */
  if (((short*)pActwk)[23] != 120) return; /* Line 500, Address: 0x10283d4 */


  ((short*)pActwk)[23] = 0; /* Line 503, Address: 0x10283f0 */
  pActwk->r_no0 = 4; /* Line 504, Address: 0x10283f8 */
  pActwk->xspeed.w = 0; /* Line 505, Address: 0x1028404 */
  pActwk->yspeed.w = 768; /* Line 506, Address: 0x102840c */
  ((short*)pActwk)[27] = -1; /* Line 507, Address: 0x1028418 */

  sub_sync(103); /* Line 509, Address: 0x1028424 */
} /* Line 510, Address: 0x1028430 */











void egg6_none(sprite_status* pActwk) { /* Line 522, Address: 0x1028440 */
  pActwk->actno = pActwk->actno; /* Line 523, Address: 0x1028448 */
} /* Line 524, Address: 0x1028458 */











void egg6_down(sprite_status* pActwk) { /* Line 536, Address: 0x1028470 */
  ushort_union wD0;
  unsigned short down_pos[3] = { 1568, 1064, 552 }; /* Line 538, Address: 0x102847c */

  wD0.w = 0; /* Line 540, Address: 0x10284a0 */
  add_spd2(pActwk); /* Line 541, Address: 0x10284a4 */
  wD0.b.l = pActwk->actfree[3]; /* Line 542, Address: 0x10284b0 */
  wD0.w = down_pos[wD0.b.l]; /* Line 543, Address: 0x10284bc */
  if ((short)wD0.w > pActwk->yposi.w.h) return; /* Line 544, Address: 0x10284d4 */


  pActwk->yposi.w.h = wD0.w; /* Line 547, Address: 0x1028504 */
  pActwk->r_no0 = 6; /* Line 548, Address: 0x1028510 */
  ((short*)pActwk)[23] = 0; /* Line 549, Address: 0x102851c */
  pActwk->actfree[11] = 1; /* Line 550, Address: 0x1028524 */
  pActwk->actfree[10] = 1; /* Line 551, Address: 0x1028530 */

  soundset(177); /* Line 553, Address: 0x102853c */
} /* Line 554, Address: 0x1028548 */











void egg6_hover(sprite_status* pActwk) { /* Line 566, Address: 0x1028560 */
  ushort_union wD0;

  wD0.w = get_snc_floor(); /* Line 569, Address: 0x102856c */
  if (wD0.b.l < pActwk->actfree[3]) /* Line 570, Address: 0x102857c */
  {

    egg6_event_retry(pActwk); /* Line 573, Address: 0x102859c */
    return; /* Line 574, Address: 0x10285a8 */
  }
  fuwafuwa(pActwk); /* Line 576, Address: 0x10285b0 */
  if (pActwk->actfree[15] == 0) /* Line 577, Address: 0x10285bc */
  {
    ++((short*)pActwk)[23]; /* Line 579, Address: 0x10285d0 */
    if (((short*)pActwk)[23] < 300) return; /* Line 580, Address: 0x10285e0 */
  }



  pActwk->actfree[11] = 0; /* Line 585, Address: 0x10285fc */

  pActwk->r_no0 = 8; /* Line 587, Address: 0x1028604 */
  pActwk->xspeed.w = 0; /* Line 588, Address: 0x1028610 */
  pActwk->yspeed.w = -256; /* Line 589, Address: 0x1028618 */
  ((short*)pActwk)[27] = -16; /* Line 590, Address: 0x1028624 */

  ((short*)pActwk)[23] = 0; /* Line 592, Address: 0x1028630 */
} /* Line 593, Address: 0x1028638 */











void fuwafuwa(sprite_status* pActwk) { /* Line 605, Address: 0x1028650 */
  short iSin;
  short iCos;
  unsigned char bRad;

  if (pActwk->actfree[3] == 3) /* Line 610, Address: 0x1028660 */
  {
    ++pActwk->actfree[18]; /* Line 612, Address: 0x1028678 */
    bRad = pActwk->actfree[18]; /* Line 613, Address: 0x1028688 */

    if ((bRad % 4) == 0) /* Line 615, Address: 0x1028694 */
      stbRad = -stbRad; /* Line 616, Address: 0x10286bc */
    pActwk->xposi.w.h += stbRad; /* Line 617, Address: 0x10286e0 */







    return; /* Line 625, Address: 0x1028700 */
  }

  pActwk->yposi.w.h -= ((short*)pActwk)[31]; /* Line 628, Address: 0x1028708 */

  sinset(pActwk->actfree[18], &iSin, &iCos); /* Line 630, Address: 0x1028720 */
  pActwk->actfree[18] += 2; /* Line 631, Address: 0x1028738 */
  iSin <<= 2; /* Line 632, Address: 0x1028748 */
  iSin >>= 8; /* Line 633, Address: 0x1028754 */
  ((short*)pActwk)[31] = iSin; /* Line 634, Address: 0x1028760 */
  pActwk->yposi.w.h += iSin; /* Line 635, Address: 0x102876c */
} /* Line 636, Address: 0x1028780 */











void egg6_up(sprite_status* pActwk) { /* Line 648, Address: 0x10287a0 */
  ushort_union wD0;
  short up_pos[3] = { 1064, 552, 304 }; /* Line 650, Address: 0x10287ac */

  add_spd2(pActwk); /* Line 652, Address: 0x10287d0 */
  wD0.w = pActwk->actfree[3]; /* Line 653, Address: 0x10287dc */
  if (up_pos[wD0.w] < pActwk->yposi.w.h) return; /* Line 654, Address: 0x10287ec */


  pActwk->yposi.w.h = up_pos[wD0.w]; /* Line 657, Address: 0x1028824 */
  pActwk->actfree[10] = 0; /* Line 658, Address: 0x1028840 */
  pActwk->r_no0 = 10; /* Line 659, Address: 0x1028848 */
  pActwk->actfree[14] = 240; /* Line 660, Address: 0x1028854 */
  ++pActwk->actfree[3]; /* Line 661, Address: 0x1028860 */

  if (pActwk->actfree[3] != 3) /* Line 663, Address: 0x1028870 */
  {
    pActwk->actfree[11] = 1; /* Line 665, Address: 0x1028888 */
    soundset(163); /* Line 666, Address: 0x1028894 */
  }

  pActwk->actfree[15] = 0; /* Line 669, Address: 0x10288a0 */
  pActwk->mstno.b.h = 0; /* Line 670, Address: 0x10288a8 */
  pActwk->patno = 0; /* Line 671, Address: 0x10288b0 */
} /* Line 672, Address: 0x10288b8 */











void egg6_event(sprite_status* pActwk) { /* Line 684, Address: 0x10288d0 */
  unsigned short wDemoNo;

  fuwafuwa(pActwk); /* Line 687, Address: 0x10288e0 */

  ++((short*)pActwk)[23]; /* Line 689, Address: 0x10288ec */
  wDemoNo = ((short*)pActwk)[23]; /* Line 690, Address: 0x10288fc */

  switch (wDemoNo) /* Line 692, Address: 0x1028908 */
  {
    case 498:
      beamdemo_start(pActwk); /* Line 695, Address: 0x102895c */
      rakkabutu(pActwk); /* Line 696, Address: 0x1028968 */
      break; /* Line 697, Address: 0x1028974 */
    case 540:
      beam_start(pActwk); /* Line 699, Address: 0x102897c */
      break; /* Line 700, Address: 0x1028988 */
    case 570:
      bossflag &= 223; /* Line 702, Address: 0x1028990 */
      rakkabutu(pActwk); /* Line 703, Address: 0x10289a4 */
      break; /* Line 704, Address: 0x10289b0 */
    case 600:
      pActwk->actfree[12] = 1; /* Line 706, Address: 0x10289b8 */
      rakkabutu(pActwk); /* Line 707, Address: 0x10289c4 */
      break; /* Line 708, Address: 0x10289d0 */
    case 630:
      bossflag |= 32; /* Line 710, Address: 0x10289d8 */
      pActwk->actfree[12] = 0; /* Line 711, Address: 0x10289ec */
      rakkabutu(pActwk); /* Line 712, Address: 0x10289f4 */
      break; /* Line 713, Address: 0x1028a00 */
    case 840:
      event_end(pActwk); /* Line 715, Address: 0x1028a08 */
      break; /* Line 716, Address: 0x1028a14 */
    default:
      rakkabutu(pActwk); /* Line 718, Address: 0x1028a1c */
      break;
  }
} /* Line 721, Address: 0x1028a28 */











void beamdemo_start(sprite_status* pActwk) { /* Line 733, Address: 0x1028a40 */
  short iD0;
  soundset(178); /* Line 735, Address: 0x1028a50 */

  iD0 = get_snc_floor(); /* Line 737, Address: 0x1028a5c */
  make_beam(iD0); /* Line 738, Address: 0x1028a6c */
  rakkabutu(pActwk); /* Line 739, Address: 0x1028a78 */
} /* Line 740, Address: 0x1028a84 */











void beam_start(sprite_status* pActwk) { /* Line 752, Address: 0x1028aa0 */
  unsigned char byFloor;
  unsigned char byD1;


  byD1 = bossstart & 31; /* Line 757, Address: 0x1028ab4 */
  byFloor = get_snc_floor(); /* Line 758, Address: 0x1028acc */
  switch (byFloor) /* Line 759, Address: 0x1028adc */
  {
    case 0:
      byD1 |= 32; /* Line 762, Address: 0x1028b08 */
      break; /* Line 763, Address: 0x1028b10 */
    case 1:
      byD1 |= 64; /* Line 765, Address: 0x1028b18 */
      break; /* Line 766, Address: 0x1028b20 */
    case 2:
      byD1 |= 128; /* Line 768, Address: 0x1028b28 */
      break;
  }
  bossstart = byD1; /* Line 771, Address: 0x1028b30 */
  rakkabutu(pActwk); /* Line 772, Address: 0x1028b38 */
} /* Line 773, Address: 0x1028b44 */











void rakkabutu(sprite_status* pActwk) { /* Line 785, Address: 0x1028b60 */
  unsigned short wD0;
  short iD0;
  if (((short*)pActwk)[23] <= 360) /* Line 788, Address: 0x1028b74 */
  {
    wD0 = ((short*)pActwk)[23] - 360; /* Line 790, Address: 0x1028b90 */
    make_gareki(pActwk, wD0); /* Line 791, Address: 0x1028bac */
  }


  if (((short*)pActwk)[23] >= 180) /* Line 795, Address: 0x1028bc0 */
  {
    wD0 = ((short*)pActwk)[23] - 180; /* Line 797, Address: 0x1028bdc */
    make_yuka(pActwk, wD0); /* Line 798, Address: 0x1028bf8 */
  }

  if (pActwk->actfree[3] != 3) return; /* Line 801, Address: 0x1028c0c */



  if (pActwk->colino != 0) /* Line 805, Address: 0x1028c24 */
  {

    if (((short*)pActwk)[23] > 180) return; /* Line 808, Address: 0x1028c38 */

    iD0 = ((short*)pActwk)[23] - 1; /* Line 810, Address: 0x1028c54 */
    make_toge(pActwk, iD0); /* Line 811, Address: 0x1028c78 */
    return; /* Line 812, Address: 0x1028c88 */
  }



  pActwk->actfree[2] &= 254; /* Line 817, Address: 0x1028c90 */
  ((short*)pActwk)[23] = 0; /* Line 818, Address: 0x1028ca0 */
  pActwk->r_no0 = 12; /* Line 819, Address: 0x1028ca8 */
  soundset(199); /* Line 820, Address: 0x1028cb4 */
  pActwk->xspeed.w = 768; /* Line 821, Address: 0x1028cc0 */
  pActwk->yspeed.w = 256; /* Line 822, Address: 0x1028ccc */
  ((short*)pActwk)[27] = 16; /* Line 823, Address: 0x1028cd8 */

  make_bakuha(pActwk); /* Line 825, Address: 0x1028ce4 */
  pActwk->mstno.b.h = 2; /* Line 826, Address: 0x1028cf0 */
  pActwk->patno = 0; /* Line 827, Address: 0x1028cfc */
  pActwk->actfree[11] = 255; /* Line 828, Address: 0x1028d04 */
  pActwk->actfree[10] = 255; /* Line 829, Address: 0x1028d10 */
} /* Line 830, Address: 0x1028d1c */











void event_end(sprite_status* pActwk) { /* Line 842, Address: 0x1028d40 */

  if (pActwk->actfree[3] == 3) /* Line 844, Address: 0x1028d4c */
  {
    egg6_event_retry(pActwk); /* Line 846, Address: 0x1028d64 */
    return; /* Line 847, Address: 0x1028d70 */
  }

  ((short*)pActwk)[23] = 0; /* Line 850, Address: 0x1028d78 */
  pActwk->r_no0 = 4; /* Line 851, Address: 0x1028d80 */
  pActwk->xspeed.w = 0; /* Line 852, Address: 0x1028d8c */
  pActwk->yspeed.w = 768; /* Line 853, Address: 0x1028d94 */
  ((short*)pActwk)[27] = -1; /* Line 854, Address: 0x1028da0 */
} /* Line 855, Address: 0x1028dac */











void egg6_event_retry(sprite_status* pActwk) { /* Line 867, Address: 0x1028dc0 */
  ((short*)pActwk)[23] = 360; /* Line 868, Address: 0x1028dc8 */
  pActwk->actfree[10] = 0; /* Line 869, Address: 0x1028dd4 */
  pActwk->r_no0 = 10; /* Line 870, Address: 0x1028ddc */
} /* Line 871, Address: 0x1028de8 */











void egg6_dead1(sprite_status* pActwk) { /* Line 883, Address: 0x1028e00 */
  dead_snc_pos(); /* Line 884, Address: 0x1028e0c */
  if (pActwk->yposi.w.h < 672) /* Line 885, Address: 0x1028e14 */
  {
    add_spd2(pActwk); /* Line 887, Address: 0x1028e30 */
    pActwk->xspeed.w = -pActwk->xspeed.w; /* Line 888, Address: 0x1028e3c */
    return; /* Line 889, Address: 0x1028e60 */
  }

  pActwk->r_no0 = 14; /* Line 892, Address: 0x1028e68 */
  pActwk->mstno.b.h = 3; /* Line 893, Address: 0x1028e74 */
  pActwk->patno = 0; /* Line 894, Address: 0x1028e80 */
  pActwk->yposi.w.h = 672; /* Line 895, Address: 0x1028e88 */
  ((short*)pActwk)[23] = 0; /* Line 896, Address: 0x1028e94 */
} /* Line 897, Address: 0x1028e9c */











void egg6_dead2(sprite_status* pActwk) { /* Line 909, Address: 0x1028eb0 */
  short sUsr_tm;
  if (((short*)pActwk)[23] == 120) /* Line 911, Address: 0x1028ec0 */
    bossstart &= 31; /* Line 912, Address: 0x1028edc */

  if (((short*)pActwk)[23] <= 326) /* Line 914, Address: 0x1028ef0 */
    dead_snc_pos(); /* Line 915, Address: 0x1028f0c */
  else
    dead_snc_pos2(); /* Line 917, Address: 0x1028f1c */


  ++((short*)pActwk)[23]; /* Line 920, Address: 0x1028f24 */
  sUsr_tm = ((short*)pActwk)[23]; /* Line 921, Address: 0x1028f34 */
  if (sUsr_tm == 180) /* Line 922, Address: 0x1028f44 */
  {
    door_open(pActwk); /* Line 924, Address: 0x1028f58 */
    return; /* Line 925, Address: 0x1028f64 */
  }

  if (sUsr_tm >= 240) /* Line 928, Address: 0x1028f6c */
  {
    colchg_stop(); /* Line 930, Address: 0x1028f80 */
    if (sUsr_tm < 325) /* Line 931, Address: 0x1028f88 */
    {
      enkei_out(pActwk); /* Line 933, Address: 0x1028f9c */
      return; /* Line 934, Address: 0x1028fa8 */
    }
  }


  if (sUsr_tm == 325) /* Line 939, Address: 0x1028fb0 */
  {
    egg6_flashout(); /* Line 941, Address: 0x1028fc4 */
    return; /* Line 942, Address: 0x1028fcc */
  }

  if (sUsr_tm == 326) /* Line 945, Address: 0x1028fd4 */
  {
    egg6_cgchg(pActwk); /* Line 947, Address: 0x1028fe8 */
    return; /* Line 948, Address: 0x1028ff4 */
  }

  if (sUsr_tm == 383) /* Line 951, Address: 0x1028ffc */
  {
    egg6_flashin(); /* Line 953, Address: 0x1029010 */
    return; /* Line 954, Address: 0x1029018 */
  }

  if (sUsr_tm >= 384) /* Line 957, Address: 0x1029020 */
  {
    if (sUsr_tm < 469) /* Line 959, Address: 0x1029034 */
    {
      enkei_in(pActwk); /* Line 961, Address: 0x1029048 */
      return; /* Line 962, Address: 0x1029054 */
    }
  }
  if (sUsr_tm == 469) /* Line 965, Address: 0x102905c */
    dead2_end(pActwk); /* Line 966, Address: 0x1029070 */
} /* Line 967, Address: 0x102907c */











void enkei_in(sprite_status* pActwk) { /* Line 979, Address: 0x1029090 */
  unsigned char byTimer, byCnt;

  byTimer = pActwk->actfree[20]; /* Line 982, Address: 0x102909c */
  byCnt = pActwk->actfree[21]; /* Line 983, Address: 0x10290a8 */
  fin_boss6(&byTimer, &byCnt); /* Line 984, Address: 0x10290b4 */
  pActwk->actfree[20] = byTimer; /* Line 985, Address: 0x10290c4 */
  pActwk->actfree[21] = byCnt; /* Line 986, Address: 0x10290d0 */
} /* Line 987, Address: 0x10290dc */











void enkei_out(sprite_status* pActwk) { /* Line 999, Address: 0x10290f0 */
  unsigned char byTimer, byCnt;

  byTimer = pActwk->actfree[20]; /* Line 1002, Address: 0x10290fc */
  byCnt = pActwk->actfree[21]; /* Line 1003, Address: 0x1029108 */
  fout_boss6(&byTimer, &byCnt); /* Line 1004, Address: 0x1029114 */
  pActwk->actfree[20] = byTimer; /* Line 1005, Address: 0x1029124 */
  pActwk->actfree[21] = byCnt; /* Line 1006, Address: 0x1029130 */
} /* Line 1007, Address: 0x102913c */











void egg6_flashout(void) { /* Line 1019, Address: 0x1029150 */
  colchg_stop(); /* Line 1020, Address: 0x1029158 */
  flashout(); /* Line 1021, Address: 0x1029160 */
} /* Line 1022, Address: 0x1029168 */











void egg6_flashin(void) { /* Line 1034, Address: 0x1029180 */
  colchg_stop(); /* Line 1035, Address: 0x1029188 */
  flashin_boss6(); /* Line 1036, Address: 0x1029190 */
} /* Line 1037, Address: 0x1029198 */











void egg6_cgchg(sprite_status* pActwk) { /* Line 1049, Address: 0x10291b0 */
  sprite_status* pActbp;


  pActwk->mstno.b.h = 4; /* Line 1053, Address: 0x10291bc */
  pActwk->patno = 0; /* Line 1054, Address: 0x10291c8 */
  pActwk->sproffset = 768; /* Line 1055, Address: 0x10291d0 */
  pActwk->xposi.w.h = 2864; /* Line 1056, Address: 0x10291dc */
  pActwk->yposi.w.h = 648; /* Line 1057, Address: 0x10291e8 */


  pActbp = &actwk[((unsigned short*)pActwk)[25]]; /* Line 1060, Address: 0x10291f4 */
  pActbp->yposi.w.h += 16; /* Line 1061, Address: 0x1029218 */
  pActbp->sprpri = 1; /* Line 1062, Address: 0x1029224 */
  pActbp->r_no0 += 2; /* Line 1063, Address: 0x102922c */
} /* Line 1064, Address: 0x1029238 */











void dead2_end(sprite_status* pActwk) { /* Line 1076, Address: 0x1029250 */
  colchg_start(); /* Line 1077, Address: 0x102925c */
  pActwk->yspeed.w = 0; /* Line 1078, Address: 0x1029264 */
  ((short*)pActwk)[27] = 0; /* Line 1079, Address: 0x102926c */
  pActwk->xspeed.w = 256; /* Line 1080, Address: 0x1029274 */
  ((short*)pActwk)[26] = 12; /* Line 1081, Address: 0x1029280 */

  pActwk->r_no0 = 16; /* Line 1083, Address: 0x102928c */
  ((short*)pActwk)[23] = 0; /* Line 1084, Address: 0x1029298 */
  scralim_right = scr_dir_tbl[2]; /* Line 1085, Address: 0x10292a0 */
  scralim_n_right = scr_dir_tbl[2]; /* Line 1086, Address: 0x10292b0 */
  if (generate_flag == 0) /* Line 1087, Address: 0x10292c0 */
    sub_sync(29); /* Line 1088, Address: 0x10292d4 */
  else
    sub_sync(28); /* Line 1090, Address: 0x10292e8 */

  scoreup(100); /* Line 1092, Address: 0x10292f4 */
} /* Line 1093, Address: 0x1029300 */











void door_open(sprite_status* pActwk) { /* Line 1105, Address: 0x1029310 */
  unsigned char byActoff = 2; /* Line 1106, Address: 0x1029318 */
  sprite_status* pActDoor;

  do
  {
    act_search(62, &byActoff, &pActDoor); /* Line 1111, Address: 0x1029320 */
  } while (pActDoor->r_no0 != 4); /* Line 1112, Address: 0x1029334 */


  pActDoor->r_no0 = 8; /* Line 1115, Address: 0x102934c */
} /* Line 1116, Address: 0x1029358 */











void egg6_dead3(sprite_status* pActwk) { /* Line 1128, Address: 0x1029370 */
  genecolor_setchk(pActwk); /* Line 1129, Address: 0x102937c */
  add_spd2(pActwk); /* Line 1130, Address: 0x1029388 */
  if (pActwk->xposi.w.h >= 3824) /* Line 1131, Address: 0x1029394 */
  {

    pActwk->r_no0 = 18; /* Line 1134, Address: 0x10293b0 */
    bossstart = 0; /* Line 1135, Address: 0x10293bc */
    egg6_dead4(pActwk); /* Line 1136, Address: 0x10293c4 */
  }
} /* Line 1138, Address: 0x10293d0 */











void egg6_dead4(sprite_status* pActwk) { /* Line 1150, Address: 0x10293e0 */
  genecolor_setchk(pActwk); /* Line 1151, Address: 0x10293ec */
  stbStx = 1; /* Line 1152, Address: 0x10293f8 */
} /* Line 1153, Address: 0x1029404 */











void genecolor_setchk(sprite_status* pActwk) { /* Line 1165, Address: 0x1029420 */
  if (pActwk->actfree[2] & 2) return; /* Line 1166, Address: 0x102942c */

  if (actwk[0].xposi.w.h >= 3072) /* Line 1168, Address: 0x1029444 */
  {
    pActwk->actfree[2] |= 2; /* Line 1170, Address: 0x1029460 */
    genecolor(); /* Line 1171, Address: 0x1029470 */
  }
} /* Line 1173, Address: 0x1029478 */











void dead_snc_pos2(void) {
  actwk[0].xspeed.w = 0; /* Line 1186, Address: 0x1029490 */
  actwk[0].mspeed.w = 0; /* Line 1187, Address: 0x1029498 */
  actwk[0].xposi.w.h = 2752; /* Line 1188, Address: 0x10294a0 */
} /* Line 1189, Address: 0x10294ac */











void dead_snc_pos(void) {
  if (actwk[0].cddat & 128) return; /* Line 1202, Address: 0x10294c0 */


  actwk[0].xspeed.w = 0; /* Line 1205, Address: 0x10294d8 */
  actwk[0].mspeed.w = 0; /* Line 1206, Address: 0x10294e0 */

  if (actwk[0].yposi.w.h > 652) /* Line 1208, Address: 0x10294e8 */
    actwk[0].yposi.w.h = 652; /* Line 1209, Address: 0x1029504 */
  if (actwk[0].xposi.w.h < 2752) /* Line 1210, Address: 0x1029510 */
    actwk[0].xposi.w.h = 2672; /* Line 1211, Address: 0x102952c */
  else
    actwk[0].xposi.w.h = 2832; /* Line 1213, Address: 0x1029540 */
} /* Line 1214, Address: 0x102954c */











void(*egg6meca0_tbl[3])(sprite_status*) =
{
  &egg6meca0_ini,
  &egg6meca0_01,
  &egg6meca0_02
};

void egg6meca0(sprite_status* pActwk) { /* Line 1233, Address: 0x1029560 */
  egg6meca0_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1234, Address: 0x102956c */
  actionsub(pActwk); /* Line 1235, Address: 0x10295b0 */
} /* Line 1236, Address: 0x10295bc */











void egg6meca0_ini(sprite_status* pActwk) { /* Line 1248, Address: 0x10295d0 */
  pActwk->r_no0 = 2; /* Line 1249, Address: 0x10295d8 */
  pActwk->actflg = 4; /* Line 1250, Address: 0x10295e4 */
  pActwk->sprpri = 5; /* Line 1251, Address: 0x10295f0 */
  pActwk->sprhsize = 64; /* Line 1252, Address: 0x10295fc */
  pActwk->sprvsize = 48; /* Line 1253, Address: 0x1029608 */
  pActwk->sproffset = 8960; /* Line 1254, Address: 0x1029614 */
  pActwk->patbase = egg6meca0_pat; /* Line 1255, Address: 0x1029620 */
} /* Line 1256, Address: 0x1029630 */











void egg6meca0_01(sprite_status* pActwk) { /* Line 1268, Address: 0x1029640 */
  sprite_status* pActbp;

  pActbp = &actwk[((unsigned short*)pActwk)[25]]; /* Line 1271, Address: 0x102964c */
  pActwk->xposi.w.h = pActbp->xposi.w.h; /* Line 1272, Address: 0x1029670 */
  pActwk->yposi.w.h = pActbp->yposi.w.h - 16; /* Line 1273, Address: 0x102967c */
} /* Line 1274, Address: 0x102969c */











void egg6meca0_02(sprite_status* pActwk) { /* Line 1286, Address: 0x10296b0 */
  pActwk->patno = 1; /* Line 1287, Address: 0x10296bc */
  pActwk->sprhsize = 64; /* Line 1288, Address: 0x10296c8 */
  pActwk->sprvsize = 16; /* Line 1289, Address: 0x10296d4 */
  pActwk->sproffset = 9107; /* Line 1290, Address: 0x10296e0 */
  ride_on_chk(pActwk, &actwk[0]); /* Line 1291, Address: 0x10296ec */
} /* Line 1292, Address: 0x1029700 */











void(*egg6meca1_tbl[2])(sprite_status*) =
{
  &egg6meca1_ini,
  &egg6meca1_01
};

void egg6meca1(sprite_status* pActwk) { /* Line 1310, Address: 0x1029710 */
  egg6meca1_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1311, Address: 0x102971c */
  actionsub(pActwk); /* Line 1312, Address: 0x1029760 */
} /* Line 1313, Address: 0x102976c */











void egg6meca1_ini(sprite_status* pActwk) { /* Line 1325, Address: 0x1029780 */
  pActwk->r_no0 = 2; /* Line 1326, Address: 0x1029788 */
  pActwk->actflg = 4; /* Line 1327, Address: 0x1029794 */
  pActwk->sprpri = 5; /* Line 1328, Address: 0x10297a0 */
  pActwk->sprhsize = 16; /* Line 1329, Address: 0x10297ac */
  pActwk->sprvsize = 16; /* Line 1330, Address: 0x10297b8 */
  pActwk->sproffset = 8960; /* Line 1331, Address: 0x10297c4 */
  pActwk->patbase = egg6meca1_pat; /* Line 1332, Address: 0x10297d0 */
} /* Line 1333, Address: 0x10297e0 */











void egg6meca1_01(sprite_status* pActwk) { /* Line 1345, Address: 0x10297f0 */
  unsigned char byD0;
  char egg6meca1_pchg[5] = { 0, 2, 1, 3, -1 }; /* Line 1347, Address: 0x1029804 */
  sprite_status* pActbp;

  pActbp = &actwk[((unsigned short*)pActwk)[25]]; /* Line 1350, Address: 0x1029830 */
  pActwk->xposi.w.h = pActbp->xposi.w.h; /* Line 1351, Address: 0x1029854 */
  pActwk->yposi.w.h = pActbp->yposi.w.h; /* Line 1352, Address: 0x1029860 */
  pActwk->yposi.w.h -= 64; /* Line 1353, Address: 0x102986c */

  if (((char*)pActbp)[56] == 0) return; /* Line 1355, Address: 0x102987c */

  if (((char*)pActbp)[56] < 0) /* Line 1357, Address: 0x1029890 */
  {

    stbStx = 1; /* Line 1360, Address: 0x10298a4 */
    frameout(pActwk); /* Line 1361, Address: 0x10298b0 */
    return; /* Line 1362, Address: 0x10298bc */
  }
  if (((char*)pActbp)[56] == 1) /* Line 1364, Address: 0x10298c4 */
  {

    pActwk->pattimm = 20; /* Line 1367, Address: 0x10298dc */

    pActwk->pattim = 2; /* Line 1369, Address: 0x10298e8 */
    ++((char*)pActbp)[56]; /* Line 1370, Address: 0x10298f4 */
    return; /* Line 1371, Address: 0x1029900 */
  }


  if (--pActwk->pattim != 0) return; /* Line 1375, Address: 0x1029908 */


  ++pActwk->patno; /* Line 1378, Address: 0x1029928 */
  if (egg6meca1_pchg[pActwk->patno] < 0) /* Line 1379, Address: 0x1029938 */
    pActwk->patno = 0; /* Line 1380, Address: 0x102995c */
  byD0 = pActwk->pattimm; /* Line 1381, Address: 0x1029964 */
  byD0 -= 3; /* Line 1382, Address: 0x1029970 */


  if ((char)byD0 < 2) /* Line 1385, Address: 0x1029978 */
    byD0 = 2; /* Line 1386, Address: 0x1029994 */
  pActwk->pattimm = byD0; /* Line 1387, Address: 0x102999c */
  pActwk->pattim = byD0; /* Line 1388, Address: 0x10299a4 */
} /* Line 1389, Address: 0x10299ac */










void(*egg6meca2_tbl[2])(sprite_status*) =
{
  &egg6meca2_ini,
  &egg6meca2_01
};

void egg6meca2(sprite_status* pActwk) { /* Line 1406, Address: 0x10299d0 */
  pActwk->colino = 190; /* Line 1407, Address: 0x10299dc */
  pActwk->colicnt = 2; /* Line 1408, Address: 0x10299e8 */
  stbStx = 0; /* Line 1409, Address: 0x10299f4 */
  egg6meca2_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1410, Address: 0x10299fc */
  if (stbStx != 0) return; /* Line 1411, Address: 0x1029a40 */

  patchg(pActwk, egg6meca2_pchg); /* Line 1413, Address: 0x1029a54 */
  actionsub(pActwk); /* Line 1414, Address: 0x1029a68 */
} /* Line 1415, Address: 0x1029a74 */











void egg6meca2_ini(sprite_status* pActwk) { /* Line 1427, Address: 0x1029a90 */
  pActwk->r_no0 = 2; /* Line 1428, Address: 0x1029a98 */
  pActwk->actflg = 4; /* Line 1429, Address: 0x1029aa4 */
  pActwk->sprpri = 5; /* Line 1430, Address: 0x1029ab0 */
  pActwk->sprhsize = 16; /* Line 1431, Address: 0x1029abc */
  pActwk->sprvsize = 16; /* Line 1432, Address: 0x1029ac8 */
  pActwk->sproffset = 8960; /* Line 1433, Address: 0x1029ad4 */
  pActwk->patbase = egg6meca2_pat; /* Line 1434, Address: 0x1029ae0 */
} /* Line 1435, Address: 0x1029af0 */











void egg6meca2_01(sprite_status* pActwk) { /* Line 1447, Address: 0x1029b00 */
  sprite_status* pActbp;

  pActbp = &actwk[((unsigned short*)pActwk)[25]]; /* Line 1450, Address: 0x1029b10 */
  pActwk->xposi.w.h = pActbp->xposi.w.h; /* Line 1451, Address: 0x1029b34 */
  pActwk->yposi.w.h = pActbp->yposi.w.h; /* Line 1452, Address: 0x1029b40 */
  pActwk->yposi.w.h += 64; /* Line 1453, Address: 0x1029b4c */
  pActwk->mstno.b.h = pActbp->actfree[11]; /* Line 1454, Address: 0x1029b5c */
  if (pActwk->mstno.b.h < 0) /* Line 1455, Address: 0x1029b68 */
  {
    stbStx = 1; /* Line 1457, Address: 0x1029b80 */
    frameout(pActwk); /* Line 1458, Address: 0x1029b8c */
  }
} /* Line 1460, Address: 0x1029b98 */











void(*egg6bakuha_tbl[3])(sprite_status*) =
{
  &egg6bakuha_ini,
  &egg6bakuha_01,
  &egg6bakuha_02
};

void egg6bakuha(sprite_status* pActwk) { /* Line 1479, Address: 0x1029bb0 */
  egg6bakuha_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1480, Address: 0x1029bbc */
} /* Line 1481, Address: 0x1029c00 */











void egg6bakuha_ini(sprite_status* pActwk) { /* Line 1493, Address: 0x1029c10 */
  pActwk->actflg = 4; /* Line 1494, Address: 0x1029c1c */
  pActwk->sproffset = 8960; /* Line 1495, Address: 0x1029c28 */
  pActwk->patbase = egg6bakuha_pat; /* Line 1496, Address: 0x1029c34 */
  if (pActwk->mstno.b.h != 0) /* Line 1497, Address: 0x1029c44 */
  {

    pActwk->sprpri = 3; /* Line 1500, Address: 0x1029c5c */
    pActwk->sprhsize = 12; /* Line 1501, Address: 0x1029c68 */
    pActwk->sprvsize = 16; /* Line 1502, Address: 0x1029c74 */
    pActwk->r_no0 = 2; /* Line 1503, Address: 0x1029c80 */
    egg6bakuha_01(pActwk); /* Line 1504, Address: 0x1029c8c */
  } /* Line 1505, Address: 0x1029c98 */
  else
  {

    pActwk->sprpri = 2; /* Line 1509, Address: 0x1029ca0 */
    pActwk->sprhsize = 16; /* Line 1510, Address: 0x1029cac */
    pActwk->sprvsize = 16; /* Line 1511, Address: 0x1029cb8 */
    pActwk->r_no0 = 4; /* Line 1512, Address: 0x1029cc4 */
    egg6bakuha_02(pActwk); /* Line 1513, Address: 0x1029cd0 */
  }
} /* Line 1515, Address: 0x1029cdc */











void egg6bakuha_01(sprite_status* pActwk) { /* Line 1527, Address: 0x1029cf0 */
  sprite_status* pActbp;

  pActbp = &actwk[((unsigned short*)pActwk)[25]]; /* Line 1530, Address: 0x1029d00 */
  ++((short*)pActwk)[23]; /* Line 1531, Address: 0x1029d24 */
  if (((short*)pActwk)[23] == 420) /* Line 1532, Address: 0x1029d34 */
  {
    frameout(pActwk); /* Line 1534, Address: 0x1029d50 */
    return; /* Line 1535, Address: 0x1029d5c */
  }
  pActwk->xposi.w.h = pActbp->xposi.w.h; /* Line 1537, Address: 0x1029d64 */
  pActwk->yposi.w.h = pActbp->yposi.w.h; /* Line 1538, Address: 0x1029d70 */
  pActwk->yposi.w.h -= 64; /* Line 1539, Address: 0x1029d7c */

  patchg(pActwk, egg6bakuha_pchg); /* Line 1541, Address: 0x1029d8c */
  if (pActwk->patno < 7) /* Line 1542, Address: 0x1029da0 */
  {
    make_bakuha2(pActwk); /* Line 1544, Address: 0x1029db8 */
    actionsub(pActwk); /* Line 1545, Address: 0x1029dc4 */
  }
} /* Line 1547, Address: 0x1029dd0 */











void egg6bakuha_02(sprite_status* pActwk) { /* Line 1559, Address: 0x1029df0 */
  ++((short*)pActwk)[23]; /* Line 1560, Address: 0x1029dfc */
  if (((short*)pActwk)[23] == 24) /* Line 1561, Address: 0x1029e0c */
  {
    frameout(pActwk); /* Line 1563, Address: 0x1029e28 */
    return; /* Line 1564, Address: 0x1029e34 */
  }
  add_spd(pActwk); /* Line 1566, Address: 0x1029e3c */
  patchg(pActwk, egg6bakuha_pchg); /* Line 1567, Address: 0x1029e48 */
  actionsub(pActwk); /* Line 1568, Address: 0x1029e5c */
} /* Line 1569, Address: 0x1029e68 */











void(*egg6toge_tbl[3])(sprite_status*) =
{
  &egg6toge_ini,
  &egg6toge_01,
  &egg6toge_02
};

void egg6toge(sprite_status* pActwk) { /* Line 1588, Address: 0x1029e80 */
  egg6toge_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1589, Address: 0x1029e8c */
} /* Line 1590, Address: 0x1029ed0 */











void egg6toge_ini(sprite_status* pActwk) { /* Line 1602, Address: 0x1029ee0 */
  pActwk->r_no0 = 2; /* Line 1603, Address: 0x1029eec */
  pActwk->actflg = 4; /* Line 1604, Address: 0x1029ef8 */
  pActwk->sprpri = 3; /* Line 1605, Address: 0x1029f04 */
  pActwk->sprhsize = 4; /* Line 1606, Address: 0x1029f10 */
  pActwk->sprvsize = 12; /* Line 1607, Address: 0x1029f1c */
  pActwk->sproffset = 8960; /* Line 1608, Address: 0x1029f28 */
  pActwk->patbase = egg6toge_pat; /* Line 1609, Address: 0x1029f34 */
  pActwk->colino = 191; /* Line 1610, Address: 0x1029f44 */
  pActwk->colicnt = 2; /* Line 1611, Address: 0x1029f50 */
  egg6toge_01(pActwk); /* Line 1612, Address: 0x1029f5c */
} /* Line 1613, Address: 0x1029f68 */











void egg6toge_01(sprite_status* pActwk) { /* Line 1625, Address: 0x1029f80 */
  short iD1;

  pActwk->yposi.l += 229376; /* Line 1628, Address: 0x1029f90 */
  iD1 = emycol_d(pActwk); /* Line 1629, Address: 0x1029fa8 */
  iD1 -= 3; /* Line 1630, Address: 0x1029fbc */
  if (iD1 <= 0) /* Line 1631, Address: 0x1029fc8 */
  {
    pActwk->yposi.w.h -= iD1; /* Line 1633, Address: 0x1029fd8 */
    pActwk->r_no0 += 2; /* Line 1634, Address: 0x1029fe8 */
    pActwk->colino = 0; /* Line 1635, Address: 0x1029ff8 */
    pActwk->colicnt = 0; /* Line 1636, Address: 0x102a000 */
  }

  actionsub(pActwk); /* Line 1639, Address: 0x102a008 */
} /* Line 1640, Address: 0x102a014 */











void egg6toge_02(sprite_status* pActwk) { /* Line 1652, Address: 0x102a030 */
  ++((char*)pActwk)[47]; /* Line 1653, Address: 0x102a03c */
  if (((char*)pActwk)[47] < 5) /* Line 1654, Address: 0x102a04c */
  {
    actionsub(pActwk); /* Line 1656, Address: 0x102a068 */
    return; /* Line 1657, Address: 0x102a074 */
  }

  if (((char*)pActwk)[47] != 10) return; /* Line 1660, Address: 0x102a07c */


  ++((char*)pActwk)[46]; /* Line 1663, Address: 0x102a098 */
  if (((char*)pActwk)[46] != 7) /* Line 1664, Address: 0x102a0a8 */
    ((char*)pActwk)[47] = 0; /* Line 1665, Address: 0x102a0c4 */
  else
    frameout(pActwk); /* Line 1667, Address: 0x102a0d4 */
} /* Line 1668, Address: 0x102a0e0 */











void(*egg6gareki_tbl[3])(sprite_status*) =
{
  &egg6gareki_ini,
  &egg6gareki_01,
  &egg6gareki_02
};

void egg6gareki(sprite_status* pActwk) { /* Line 1687, Address: 0x102a0f0 */
  egg6gareki_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1688, Address: 0x102a0fc */
  actionsub(pActwk); /* Line 1689, Address: 0x102a140 */
  frameout_chk(pActwk); /* Line 1690, Address: 0x102a14c */
} /* Line 1691, Address: 0x102a158 */











void egg6gareki_ini(sprite_status* pActwk) { /* Line 1703, Address: 0x102a170 */
  pActwk->r_no0 = 2; /* Line 1704, Address: 0x102a178 */
  pActwk->actflg = 4; /* Line 1705, Address: 0x102a184 */
  pActwk->sprpri = 3; /* Line 1706, Address: 0x102a190 */




  pActwk->sprhsize = 4; /* Line 1711, Address: 0x102a19c */
  pActwk->sprvsize = 4; /* Line 1712, Address: 0x102a1a8 */

  pActwk->sproffset = 17472; /* Line 1714, Address: 0x102a1b4 */
  pActwk->patbase = egg6gareki_pat; /* Line 1715, Address: 0x102a1c0 */
} /* Line 1716, Address: 0x102a1d0 */











void egg6gareki_01(sprite_status* pActwk) { /* Line 1728, Address: 0x102a1e0 */
  short iD1;

  patchg(pActwk, egg6gareki_pchg); /* Line 1731, Address: 0x102a1f0 */

  add_spd2(pActwk); /* Line 1733, Address: 0x102a204 */
  iD1 = emycol_d(pActwk); /* Line 1734, Address: 0x102a210 */
  --iD1; /* Line 1735, Address: 0x102a224 */
  if (iD1 <= 0) /* Line 1736, Address: 0x102a230 */
  {

    pActwk->yposi.w.h -= iD1; /* Line 1739, Address: 0x102a240 */
    pActwk->r_no0 += 2; /* Line 1740, Address: 0x102a250 */
    make_gareki4(pActwk); /* Line 1741, Address: 0x102a260 */
  }
} /* Line 1743, Address: 0x102a26c */











void egg6gareki_02(sprite_status* pActwk) { /* Line 1755, Address: 0x102a280 */
  add_spd2(pActwk); /* Line 1756, Address: 0x102a28c */
} /* Line 1757, Address: 0x102a298 */











void(*egg6beam_tbl[2])(sprite_status*) =
{
  &egg6beam_ini,
  &egg6beam_01
};

void egg6beam(sprite_status* pActwk) { /* Line 1775, Address: 0x102a2b0 */




  egg6beam_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1780, Address: 0x102a2bc */

} /* Line 1782, Address: 0x102a300 */
















static sprite_pattern** e6beam_tbl[3] = { egg6beam_pat, egg6beam2_pat, egg6beam3_pat };

void egg6beam_ini(sprite_status* pActwk) { /* Line 1801, Address: 0x102a310 */
  pActwk->actfree[10] = 4; /* Line 1802, Address: 0x102a31c */
  pActwk->actfree[11] = 0; /* Line 1803, Address: 0x102a328 */

  pActwk->r_no0 = 2; /* Line 1805, Address: 0x102a330 */
  pActwk->actflg = 4; /* Line 1806, Address: 0x102a33c */
  pActwk->sprpri = 1; /* Line 1807, Address: 0x102a348 */
  pActwk->sprhsize = 208; /* Line 1808, Address: 0x102a354 */
  pActwk->sprvsize = 8; /* Line 1809, Address: 0x102a360 */
  pActwk->sproffset = 17520; /* Line 1810, Address: 0x102a36c */
  pActwk->patbase = egg6beam_pat; /* Line 1811, Address: 0x102a378 */
  egg6beam_01(pActwk); /* Line 1812, Address: 0x102a388 */
} /* Line 1813, Address: 0x102a394 */











void egg6beam_01(sprite_status* pActwk) { /* Line 1825, Address: 0x102a3b0 */
  unsigned char byD0;
  unsigned char bywk;

  if (--pActwk->actfree[10] == 0) /* Line 1829, Address: 0x102a3c4 */
  {

    pActwk->actfree[10] = 4; /* Line 1832, Address: 0x102a3e4 */
    if (++pActwk->actfree[11] > 2) /* Line 1833, Address: 0x102a3f0 */
      pActwk->actfree[11] = 0; /* Line 1834, Address: 0x102a414 */
    bywk = pActwk->actfree[11]; /* Line 1835, Address: 0x102a41c */
    pActwk->patbase = e6beam_tbl[bywk]; /* Line 1836, Address: 0x102a428 */
  }




  ++((char*)pActwk)[47]; /* Line 1842, Address: 0x102a448 */
  byD0 = ((char*)pActwk)[47]; /* Line 1843, Address: 0x102a458 */
  byD0 -= 30; /* Line 1844, Address: 0x102a464 */
  if ((char)byD0 >= 0) /* Line 1845, Address: 0x102a46c */
  {
    byD0 /= 3; /* Line 1847, Address: 0x102a484 */
    if (byD0 == 5) /* Line 1848, Address: 0x102a4a8 */
    {
      frameout(pActwk); /* Line 1850, Address: 0x102a4b8 */
      return; /* Line 1851, Address: 0x102a4c4 */
    }
    pActwk->patno = byD0; /* Line 1853, Address: 0x102a4cc */
  }

  if (pActwk->userflag.b.h != 0) /* Line 1856, Address: 0x102a4d4 */
    pActwk->actflg |= 1; /* Line 1857, Address: 0x102a4ec */
  actionsub(pActwk); /* Line 1858, Address: 0x102a4fc */
} /* Line 1859, Address: 0x102a508 */











void(*egg6yuka_tbl[3])(sprite_status*) =
{
  &egg6yuka_ini,
  &egg6yuka_01,
  &egg6yuka_02
};

void egg6yuka(sprite_status* pActwk) { /* Line 1878, Address: 0x102a520 */
  egg6yuka_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1879, Address: 0x102a52c */
  egg6_yuka_ridechk(pActwk); /* Line 1880, Address: 0x102a570 */
  actionsub(pActwk); /* Line 1881, Address: 0x102a57c */
} /* Line 1882, Address: 0x102a588 */


























void egg6yuka_ini(sprite_status* pActwk) { /* Line 1909, Address: 0x102a5a0 */
  short_union iD0;

  pActwk->r_no0 = 2; /* Line 1912, Address: 0x102a5a8 */
  pActwk->actflg = 4; /* Line 1913, Address: 0x102a5b4 */
  pActwk->sprpri = 3; /* Line 1914, Address: 0x102a5c0 */
  pActwk->sprhsize = 14; /* Line 1915, Address: 0x102a5cc */

  pActwk->sprhs = 14; /* Line 1917, Address: 0x102a5d8 */

  pActwk->sprvsize = 16; /* Line 1919, Address: 0x102a5e4 */
  pActwk->sproffset = 1088; /* Line 1920, Address: 0x102a5f0 */
  pActwk->patbase = egg6yuka_pat; /* Line 1921, Address: 0x102a5fc */

  iD0.w = 0; /* Line 1923, Address: 0x102a60c */
  iD0.b.l = pActwk->userflag.b.l; /* Line 1924, Address: 0x102a610 */
  iD0.w <<= 3; /* Line 1925, Address: 0x102a61c */
  ((short*)pActwk)[28] = iD0.w; /* Line 1926, Address: 0x102a628 */

  pActwk->yspeed.w = 0; /* Line 1928, Address: 0x102a634 */
  ((short*)pActwk)[27] = 11; /* Line 1929, Address: 0x102a63c */
} /* Line 1930, Address: 0x102a648 */

static short yuka_tbl[24] =
{
  1680, 1024, -1536, 11,
  1680, 1024, -1536, 14,
  1168,  736, -1536, 11,
  1168,  736, -1536, 14,
   656,  272, -1536, 11,
   656,  272, -1536, 14
};

void egg6yuka_01(sprite_status* pActwk) { /* Line 1942, Address: 0x102a660 */
  short iD0, iD1;

  add_spd2(pActwk); /* Line 1945, Address: 0x102a674 */

  iD1 = ((short*)pActwk)[28]; /* Line 1947, Address: 0x102a680 */
  iD1 += ((short*)pActwk)[30]; /* Line 1948, Address: 0x102a690 */
  iD0 = yuka_tbl[iD1]; /* Line 1949, Address: 0x102a6a4 */
  if (iD0 > pActwk->yposi.w.h) /* Line 1950, Address: 0x102a6c8 */
  {
    iD0 = yuka_tbl[iD1 + 1]; /* Line 1952, Address: 0x102a6ec */
    if (iD0 >= pActwk->yposi.w.h) /* Line 1953, Address: 0x102a714 */
      pActwk->yposi.w.h = iD0; /* Line 1954, Address: 0x102a738 */
    return; /* Line 1955, Address: 0x102a740 */
  }

  pActwk->xspeed.w = 0; /* Line 1958, Address: 0x102a748 */
  pActwk->yspeed.w = 0; /* Line 1959, Address: 0x102a750 */
  pActwk->yposi.w.h = iD0; /* Line 1960, Address: 0x102a758 */
  pActwk->r_no0 = 4; /* Line 1961, Address: 0x102a760 */
  soundset(180); /* Line 1962, Address: 0x102a76c */
} /* Line 1963, Address: 0x102a778 */











void egg6yuka_02(sprite_status* pActwk) { /* Line 1975, Address: 0x102a790 */
  short iD0, iD1;
  sprite_status* pActbp;

  pActbp = &actwk[((unsigned short*)pActwk)[25]]; /* Line 1979, Address: 0x102a7a4 */
  if (pActbp->actfree[12] == 0) return; /* Line 1980, Address: 0x102a7c8 */


  pActwk->r_no0 = 2; /* Line 1983, Address: 0x102a7d8 */


  iD0 = pActwk->xposi.w.h - actwk[0].xposi.w.h; /* Line 1986, Address: 0x102a7e4 */
  if (iD0 < 0) /* Line 1987, Address: 0x102a818 */
    iD0 = -iD0; /* Line 1988, Address: 0x102a828 */

  ((unsigned short*)pActwk)[30] = 0; /* Line 1990, Address: 0x102a844 */
  if (iD0 < 24) /* Line 1991, Address: 0x102a84c */
    ((unsigned short*)pActwk)[30] = 4; /* Line 1992, Address: 0x102a860 */

  iD1 = ((unsigned short*)pActwk)[28]; /* Line 1994, Address: 0x102a86c */
  iD1 += ((unsigned short*)pActwk)[30]; /* Line 1995, Address: 0x102a87c */
  pActwk->yspeed.w = yuka_tbl[iD1 + 2]; /* Line 1996, Address: 0x102a898 */
  ((short*)pActwk)[27] = yuka_tbl[iD1 + 3]; /* Line 1997, Address: 0x102a8c0 */
} /* Line 1998, Address: 0x102a8e8 */











void egg6_yuka_ridechk(sprite_status* pActwk) { /* Line 2010, Address: 0x102a900 */
  short iSpd_sav;


  if (pActwk->yspeed.w == 0) /* Line 2014, Address: 0x102a910 */

    pActwk->actfree[18] = 0; /* Line 2016, Address: 0x102a928 */
  else
  {
    pActwk->actfree[18] = 4; /* Line 2019, Address: 0x102a938 */
  }
  pActwk->sprvsize = pActwk->sprvsize + pActwk->actfree[18]; /* Line 2021, Address: 0x102a944 */


  if (actwk[0].actno != 0) /* Line 2024, Address: 0x102a96c */
  {
    if (egg6_yuka_hasami_chk(pActwk) == 0) /* Line 2026, Address: 0x102a980 */
    {
      iSpd_sav = actwk[0].yspeed.w; /* Line 2028, Address: 0x102a99c */
      if ((actwk[0].cddat & 8) && !(actwk[0].cddat & 2)) /* Line 2029, Address: 0x102a9ac */
      {

        actwk[0].yspeed.w = 0; /* Line 2032, Address: 0x102a9dc */
      }

      if (ride_on_chk(pActwk, &actwk[0]) != 0) /* Line 2035, Address: 0x102a9e4 */
        egg6_yuka_ride_on(pActwk); /* Line 2036, Address: 0x102aa08 */
      else
        actwk[0].yspeed.w = iSpd_sav; /* Line 2038, Address: 0x102aa1c */
    }
  }
  pActwk->sprvsize = pActwk->sprvsize - pActwk->actfree[18]; /* Line 2041, Address: 0x102aa24 */
} /* Line 2042, Address: 0x102aa4c */











void egg6_yuka_ride_on(sprite_status* pActwk) { /* Line 2054, Address: 0x102aa60 */
  short iD0;

  actwk[0].yposi.l = pActwk->yposi.l; /* Line 2057, Address: 0x102aa6c */
  iD0 = actwk[0].sprvsize; /* Line 2058, Address: 0x102aa7c */
  iD0 += 16; /* Line 2059, Address: 0x102aa90 */
  actwk[0].yposi.w.h -= iD0; /* Line 2060, Address: 0x102aa9c */
  if (pActwk->yspeed.w < 0) /* Line 2061, Address: 0x102aab0 */

    actwk[0].yspeed.w = pActwk->yspeed.w; /* Line 2063, Address: 0x102aac8 */
  else
    actwk[0].yspeed.w = 0; /* Line 2065, Address: 0x102aae0 */
} /* Line 2066, Address: 0x102aae8 */











short egg6_yuka_hasami_chk(sprite_status* pActwk) { /* Line 2078, Address: 0x102ab00 */
  short iD0, iD1;

  iD1 = pActwk->xposi.w.h - actwk[0].xposi.w.h; /* Line 2081, Address: 0x102ab14 */
  if (iD1 < 0) /* Line 2082, Address: 0x102ab48 */
    iD1 = -iD1; /* Line 2083, Address: 0x102ab58 */

  if (iD1 < 23) /* Line 2085, Address: 0x102ab74 */
  {
    if (actwk[0].yposi.w.h < 265) /* Line 2087, Address: 0x102ab88 */
    {

      mydamage(pActwk); /* Line 2090, Address: 0x102aba4 */
      actwk[0].yspeed.w = 512; /* Line 2091, Address: 0x102abb0 */
      return -1; /* Line 2092, Address: 0x102abbc */
    }
    if (pActwk->yspeed.w > 0) /* Line 2094, Address: 0x102abc8 */
    {
      iD0 = (char)actwk[0].sprvsize; /* Line 2096, Address: 0x102abe0 */
      iD1 = actwk[0].yposi.w.h - iD0; /* Line 2097, Address: 0x102ac00 */

      iD1 -= pActwk->yposi.w.h; /* Line 2099, Address: 0x102ac2c */
      if (iD1 >= 0 && iD1 < 33) /* Line 2100, Address: 0x102ac40 */
      {
        return mydamage(pActwk); /* Line 2102, Address: 0x102ac64 */
      }
    }
  }


  if (actwk[0].yposi.w.h < pActwk->yposi.w.h) /* Line 2108, Address: 0x102ac78 */
    return 0; /* Line 2109, Address: 0x102aca4 */

  return -1; /* Line 2111, Address: 0x102acb0 */
} /* Line 2112, Address: 0x102acb4 */











short mydamage(sprite_status* pActwk) { /* Line 2124, Address: 0x102acd0 */

  if (!(actwk[0].cddat & 128)) /* Line 2126, Address: 0x102acdc */
  {
    pcole(&actwk[0], pActwk); /* Line 2128, Address: 0x102acf4 */
    if (actwk[0].mstno.b.h == 24) /* Line 2129, Address: 0x102ad08 */
    {
      actwk[0].cddat |= 128; /* Line 2131, Address: 0x102ad24 */
    }
  }
  return -1; /* Line 2134, Address: 0x102ad38 */
} /* Line 2135, Address: 0x102ad3c */













void(*egg6door_tbl[6])(sprite_status*) =
{
  &egg6door_ini,
  &egg6door_closewait,
  &egg6door_openwait,
  &egg6door_closed,
  &egg6door_move,
  &egg6door_beamer
};

void egg6door(sprite_status* pActwk) { /* Line 2159, Address: 0x102ad50 */
  egg6door_tbl[pActwk->r_no0 / 2](pActwk); /* Line 2160, Address: 0x102ad64 */

  if (pActwk->userflag.b.h >= 0) /* Line 2162, Address: 0x102ada8 */
  {
    short xwk, ywk;

    xwk = ((short*)pActwk)[29]; /* Line 2166, Address: 0x102adc0 */
    ywk = ((short*)pActwk)[30]; /* Line 2167, Address: 0x102add0 */
    pActwk->xposi.w.h += xwk; /* Line 2168, Address: 0x102ade0 */
    pActwk->yposi.w.h += ywk; /* Line 2169, Address: 0x102adf0 */
    ride_on_chk(pActwk, &actwk[0]); /* Line 2170, Address: 0x102ae00 */


    pActwk->xposi.w.h -= xwk; /* Line 2173, Address: 0x102ae14 */
    pActwk->yposi.w.h -= ywk; /* Line 2174, Address: 0x102ae24 */
  }

  actionsub(pActwk); /* Line 2177, Address: 0x102ae34 */
} /* Line 2178, Address: 0x102ae40 */











void egg6door_ini(sprite_status* pActwk) { /* Line 2190, Address: 0x102ae60 */
  pActwk->actflg = 4; /* Line 2191, Address: 0x102ae68 */
  pActwk->sprpri = 2; /* Line 2192, Address: 0x102ae74 */
  pActwk->sproffset = 17496; /* Line 2193, Address: 0x102ae80 */

  pActwk->patno = pActwk->userflag.b.h & 15; /* Line 2195, Address: 0x102ae8c */
  if (pActwk->userflag.b.h >= 0) /* Line 2196, Address: 0x102aeac */
  {

    pActwk->patbase = egg6door_pat; /* Line 2199, Address: 0x102aec4 */
    if (pActwk->userflag.b.h & 1) /* Line 2200, Address: 0x102aed4 */
    {

      pActwk->yspeed.w = -512; /* Line 2203, Address: 0x102aef0 */
      pActwk->r_no0 = 4; /* Line 2204, Address: 0x102aefc */

      ((short*)pActwk)[28] = -24576; /* Line 2206, Address: 0x102af08 */
      ((short*)pActwk)[29] = 20; /* Line 2207, Address: 0x102af14 */
      ((short*)pActwk)[30] = -26; /* Line 2208, Address: 0x102af20 */
      pActwk->sprhsize = 8; /* Line 2209, Address: 0x102af2c */
      pActwk->sprvsize = 80; /* Line 2210, Address: 0x102af38 */
      return; /* Line 2211, Address: 0x102af44 */
    }



    pActwk->sprhsize = 8; /* Line 2216, Address: 0x102af4c */
    pActwk->sprvsize = 16; /* Line 2217, Address: 0x102af58 */
    pActwk->yspeed.w = 512; /* Line 2218, Address: 0x102af64 */
    pActwk->r_no0 = 2; /* Line 2219, Address: 0x102af70 */

    ((short*)pActwk)[28] = 16384; /* Line 2221, Address: 0x102af7c */
    ((short*)pActwk)[29] = -20; /* Line 2222, Address: 0x102af88 */
    ((short*)pActwk)[30] = -10; /* Line 2223, Address: 0x102af94 */
  } /* Line 2224, Address: 0x102afa0 */
  else
  {



    pActwk->sprhsize = 8; /* Line 2230, Address: 0x102afa8 */
    pActwk->sprvsize = 16; /* Line 2231, Address: 0x102afb4 */
    pActwk->patbase = egg6beamer_pat; /* Line 2232, Address: 0x102afc0 */
    pActwk->r_no0 = 10; /* Line 2233, Address: 0x102afd0 */
  }

} /* Line 2236, Address: 0x102afdc */











void egg6door_closewait(sprite_status* pActwk) { /* Line 2248, Address: 0x102aff0 */
  bossflag &= 127; /* Line 2249, Address: 0x102aff8 */
  bossflag &= 223; /* Line 2250, Address: 0x102b00c */

  if (actwk[0].xposi.w.h >= 2352) /* Line 2252, Address: 0x102b020 */
    bossflag |= 64; /* Line 2253, Address: 0x102b03c */

  if (actwk[0].xposi.w.h >= 2480) /* Line 2255, Address: 0x102b050 */
    bossflag |= 32; /* Line 2256, Address: 0x102b06c */


  if (actwk[0].xposi.w.h >= 2656) /* Line 2259, Address: 0x102b080 */
    pActwk->r_no0 = 8; /* Line 2260, Address: 0x102b09c */
} /* Line 2261, Address: 0x102b0a8 */











void egg6door_move(sprite_status* pActwk) { /* Line 2273, Address: 0x102b0c0 */
  short_union iD0;
  add_spd(pActwk); /* Line 2275, Address: 0x102b0cc */
  ((short*)pActwk)[23] += pActwk->yspeed.w; /* Line 2276, Address: 0x102b0d8 */

  iD0.w = ((short*)pActwk)[28]; /* Line 2278, Address: 0x102b0f0 */
  if (iD0.w >= 0) /* Line 2279, Address: 0x102b0fc */
  {

    if (iD0.w > ((short*)pActwk)[23]) return; /* Line 2282, Address: 0x102b110 */


    pActwk->r_no0 = 6; /* Line 2285, Address: 0x102b138 */
  } /* Line 2286, Address: 0x102b144 */
  else
  {

    if (iD0.w < ((short*)pActwk)[23]) return; /* Line 2290, Address: 0x102b14c */


    pActwk->r_no0 = 10; /* Line 2293, Address: 0x102b174 */
  }

  if (pActwk->userflag.b.h & 1) /* Line 2296, Address: 0x102b180 */
  {

    pActwk->sprhsize = 9; /* Line 2299, Address: 0x102b19c */
    pActwk->sprvsize = 16; /* Line 2300, Address: 0x102b1a8 */
  } /* Line 2301, Address: 0x102b1b4 */
  else
  {
    pActwk->sprhsize = 9; /* Line 2304, Address: 0x102b1bc */
    pActwk->sprvsize = 32; /* Line 2305, Address: 0x102b1c8 */
  }
} /* Line 2307, Address: 0x102b1d4 */











void egg6door_closed(sprite_status* pActwk) { /* Line 2319, Address: 0x102b1f0 */
  if (actwk[0].actno != 0) /* Line 2320, Address: 0x102b1fc */
  {
    if (actwk[0].xposi.w.h < 2560) /* Line 2322, Address: 0x102b210 */
      actwk[0].xposi.w.h = 2560; /* Line 2323, Address: 0x102b22c */
  }
  egg6door_beamer(pActwk); /* Line 2325, Address: 0x102b238 */
} /* Line 2326, Address: 0x102b244 */











void egg6door_openwait(sprite_status* pActwk) { /* Line 2338, Address: 0x102b260 */
  if (actwk[0].actno != 0) /* Line 2339, Address: 0x102b26c */
  {
    if (actwk[0].xposi.w.h > 2944) /* Line 2341, Address: 0x102b280 */
      actwk[0].xposi.w.h = 2944; /* Line 2342, Address: 0x102b29c */
  }
  egg6door_beamer(pActwk); /* Line 2344, Address: 0x102b2a8 */
} /* Line 2345, Address: 0x102b2b4 */












void egg6door_beamer(sprite_status* pActwk) { /* Line 2358, Address: 0x102b2d0 */
  short_union iD0;
  sprite_status* pPlaywk;

  pPlaywk = &actwk[0]; /* Line 2362, Address: 0x102b2e0 */
  iD0.b.l = (unsigned char)(1 << pActwk->userflag.b.l); /* Line 2363, Address: 0x102b2e8 */
  if (!(bossstart & iD0.b.l)) return; /* Line 2364, Address: 0x102b310 */



  if (pPlaywk->actno != 0) /* Line 2368, Address: 0x102b334 */
  {
    iD0.w = pActwk->yposi.w.h - pPlaywk->yposi.w.h; /* Line 2370, Address: 0x102b344 */
    if (iD0.w < 0) /* Line 2371, Address: 0x102b370 */
      iD0.w = -iD0.w; /* Line 2372, Address: 0x102b384 */
    if (iD0.w >= 8) return; /* Line 2373, Address: 0x102b3a0 */


    if (((short*)pPlaywk)[26] != 0) return; /* Line 2376, Address: 0x102b3b8 */

    if (actwk[0].r_no0 != 6 && !(actwk[0].cddat & 128)) /* Line 2378, Address: 0x102b3cc */
      mydamage(pActwk); /* Line 2379, Address: 0x102b3fc */
  }
} /* Line 2381, Address: 0x102b408 */











void add_spd2(sprite_status* pActwk) { /* Line 2393, Address: 0x102b420 */
  int_union lD0;

  pActwk->xspeed.w += ((short*)pActwk)[26]; /* Line 2396, Address: 0x102b428 */
  pActwk->yspeed.w += ((short*)pActwk)[27]; /* Line 2397, Address: 0x102b440 */

  lD0.l = pActwk->xspeed.w; /* Line 2399, Address: 0x102b458 */
  pActwk->xposi.l += lD0.l << 8; /* Line 2400, Address: 0x102b46c */
  lD0.l = pActwk->yspeed.w; /* Line 2401, Address: 0x102b484 */
  pActwk->yposi.l += lD0.l << 8; /* Line 2402, Address: 0x102b498 */
} /* Line 2403, Address: 0x102b4b0 */

void add_spd(sprite_status* pActwk) { /* Line 2405, Address: 0x102b4c0 */
  int_union lD0;

  lD0.l = pActwk->xspeed.w; /* Line 2408, Address: 0x102b4c8 */
  pActwk->xposi.l += lD0.l << 8; /* Line 2409, Address: 0x102b4dc */
  lD0.l = pActwk->yspeed.w; /* Line 2410, Address: 0x102b4f4 */
  pActwk->yposi.l += lD0.l << 8; /* Line 2411, Address: 0x102b508 */
} /* Line 2412, Address: 0x102b520 */














short act_search(unsigned char wActNo, unsigned char* bpActoff, sprite_status** ppActAdr) { /* Line 2427, Address: 0x102b530 */
  while (*bpActoff < 128) /* Line 2428, Address: 0x102b540 */
  {
    if (wActNo == actwk[(*bpActoff)++].actno) /* Line 2430, Address: 0x102b548 */
    {
      *ppActAdr = &actwk[*bpActoff - 1]; /* Line 2432, Address: 0x102b58c */
      return 0; /* Line 2433, Address: 0x102b5bc */
    }
  } /* Line 2435, Address: 0x102b5c8 */
  return -1; /* Line 2436, Address: 0x102b5e0 */
} /* Line 2437, Address: 0x102b5e4 */























static short yuka_xini[12] =
{
  2712, 2792,
  2632, 2872,
  2608, 2680,
  2800, 2896,
  2832, 2904,
  2672, 2600
};
static short gareki_yini[3] =
{
  1420,
   908,
   396
};

short get_gareki_y(sprite_status* pActwk) { /* Line 2477, Address: 0x102b5f0 */
  short iD0;
  iD0 = pActwk->actfree[3]; /* Line 2479, Address: 0x102b5fc */
  --iD0; /* Line 2480, Address: 0x102b610 */
  return gareki_yini[iD0]; /* Line 2481, Address: 0x102b61c */
} /* Line 2482, Address: 0x102b638 */












void make_toge(sprite_status* pActwk, short iD0) { /* Line 2495, Address: 0x102b650 */
  short iD1, iD2;
  sprite_status* pActfree;

  iD2 = iD0 / 35; /* Line 2499, Address: 0x102b668 */
  iD0 = iD0 % 35; /* Line 2500, Address: 0x102b69c */
  if (iD0 != 0) return; /* Line 2501, Address: 0x102b6c0 */

  if (actwkchk(&pActfree) != 0) return; /* Line 2503, Address: 0x102b6d4 */

  ((unsigned short*)pActfree)[25] = pActwk - actwk; /* Line 2505, Address: 0x102b6e8 */
  pActfree->actno = 56; /* Line 2506, Address: 0x102b71c */

  pActfree->yposi.w.h = get_gareki_y(pActwk); /* Line 2508, Address: 0x102b728 */


  if ((iD2 & 65535) == 0) /* Line 2511, Address: 0x102b73c */
  {
    if (actwk[0].xposi.w.h < 2752) /* Line 2513, Address: 0x102b750 */
      pActwk->actfree[19] = 1; /* Line 2514, Address: 0x102b76c */
    else
      pActwk->actfree[19] = 0; /* Line 2516, Address: 0x102b780 */
  }

  iD1 = 32; /* Line 2519, Address: 0x102b788 */
  if (pActwk->actfree[19] != 0) /* Line 2520, Address: 0x102b794 */
    iD0 = 2592; /* Line 2521, Address: 0x102b7a8 */
  else
  {
    iD1 = -iD1; /* Line 2524, Address: 0x102b7b8 */
    iD0 = 2912; /* Line 2525, Address: 0x102b7d4 */
  }
  iD0 += iD2 * iD1; /* Line 2527, Address: 0x102b7dc */
  pActfree->xposi.w.h = iD0; /* Line 2528, Address: 0x102b804 */
} /* Line 2529, Address: 0x102b810 */












void make_yuka(sprite_status* pActwk, short iD0) { /* Line 2542, Address: 0x102b830 */
  short iD1, iD2, iSav;
  sprite_status* pActfree;

  iSav = iD0; /* Line 2546, Address: 0x102b84c */
  iD2 = iD0 / 20; /* Line 2547, Address: 0x102b858 */
  iD0 = iD0 % 20; /* Line 2548, Address: 0x102b88c */
  if (iD0 != 0) return; /* Line 2549, Address: 0x102b8b0 */

  if (iD2 >= 4) return; /* Line 2551, Address: 0x102b8c4 */


  if (actwkchk(&pActfree) != 0) return; /* Line 2554, Address: 0x102b8d8 */

  pActfree->userflag.b.h = (unsigned char)iD2; /* Line 2556, Address: 0x102b8ec */

  ((unsigned short*)pActfree)[25] = pActwk - actwk; /* Line 2558, Address: 0x102b900 */
  pActfree->actno = 61; /* Line 2559, Address: 0x102b934 */

  pActfree->yposi.w.h = get_gareki_y(pActwk); /* Line 2561, Address: 0x102b940 */

  iD1 = pActwk->actfree[3] - 1; /* Line 2563, Address: 0x102b954 */
  pActfree->userflag.b.l = (unsigned char)iD1; /* Line 2564, Address: 0x102b974 */


  iD1 <<= 2; /* Line 2567, Address: 0x102b988 */
  iD1 += iD2; /* Line 2568, Address: 0x102b994 */
  pActfree->xposi.w.h = yuka_xini[iD1]; /* Line 2569, Address: 0x102b9a0 */
} /* Line 2570, Address: 0x102b9c4 */












void make_gareki(sprite_status* pActwk, short iD0) { /* Line 2583, Address: 0x102b9e0 */
  short iD2;
  int_union lD0;
  sprite_status* pActfree;

  iD2 = iD0 / 16; /* Line 2588, Address: 0x102b9f4 */
  iD0 = iD0 % 16; /* Line 2589, Address: 0x102ba28 */
  if (iD0 != 0) return; /* Line 2590, Address: 0x102ba5c */

  if (actwkchk(&pActfree) != 0) return; /* Line 2592, Address: 0x102ba70 */

  ((unsigned short*)pActfree)[25] = pActwk - actwk; /* Line 2594, Address: 0x102ba84 */
  pActfree->actno = 57; /* Line 2595, Address: 0x102bab8 */

  pActfree->yposi.w.h = get_gareki_y(pActwk); /* Line 2597, Address: 0x102bac4 */

  lD0.l = random(); /* Line 2599, Address: 0x102bad8 */
  lD0.l = lD0.w.l; /* Line 2600, Address: 0x102bae4 */


  iD0 = lD0.l % 80; /* Line 2603, Address: 0x102baf4 */
  iD0 += 2752; /* Line 2604, Address: 0x102bb10 */
  pActfree->xposi.w.h = iD0; /* Line 2605, Address: 0x102bb1c */


  iD0 = lD0.l % 640; /* Line 2608, Address: 0x102bb28 */
  pActfree->xspeed.w = iD0; /* Line 2609, Address: 0x102bb44 */


  pActfree->yspeed.w = 256; /* Line 2612, Address: 0x102bb50 */

  ((short*)pActfree)[27] = 8; /* Line 2614, Address: 0x102bb5c */
  iD0 = lD0.w.l & 15; /* Line 2615, Address: 0x102bb68 */
  ((short*)pActfree)[27] += iD0; /* Line 2616, Address: 0x102bb84 */
} /* Line 2617, Address: 0x102bb98 */











void make_gareki4(sprite_status* pActwk) { /* Line 2629, Address: 0x102bbb0 */
  short i, offs;
  short para[16] = /* Line 2631, Address: 0x102bbc4 */
  {
     512, -448, 0, 48,
    -512, -448, 0, 48,
     256, -640, 0, 48,
    -256, -640, 0, 48
  };
  sprite_status* pActfree;


  pActfree = pActwk; /* Line 2641, Address: 0x102bbf8 */
  offs = 0; /* Line 2642, Address: 0x102bc00 */
  for (i = 3; i >= 0; --i) /* Line 2643, Address: 0x102bc04 */
  {
    if (i != 3) /* Line 2645, Address: 0x102bc18 */
    {
      if (actwkchk(&pActfree) != 0) return; /* Line 2647, Address: 0x102bc2c */

      pActfree->actno = pActwk->actno; /* Line 2649, Address: 0x102bc40 */
      pActfree->r_no0 = pActwk->r_no0; /* Line 2650, Address: 0x102bc50 */
      pActfree->actflg = pActwk->actflg; /* Line 2651, Address: 0x102bc60 */
      pActfree->sprpri = pActwk->sprpri; /* Line 2652, Address: 0x102bc70 */
      pActfree->sprhsize = pActwk->sprhsize; /* Line 2653, Address: 0x102bc80 */
      pActfree->sprvsize = pActwk->sprvsize; /* Line 2654, Address: 0x102bc90 */
      pActfree->sproffset = pActwk->sproffset; /* Line 2655, Address: 0x102bca0 */

      pActfree->xposi.w.h = pActwk->xposi.w.h; /* Line 2657, Address: 0x102bcb0 */
      pActfree->yposi.w.h = pActwk->yposi.w.h; /* Line 2658, Address: 0x102bcc0 */
    }
    pActfree->patbase = egg6gareki4_pat; /* Line 2660, Address: 0x102bcd0 */
    pActfree->patno = i; /* Line 2661, Address: 0x102bce0 */
    pActfree->xspeed.w = para[offs++]; /* Line 2662, Address: 0x102bcec */
    pActfree->yspeed.w = para[offs++]; /* Line 2663, Address: 0x102bd18 */
    ((short*)pActfree)[26] = para[offs++]; /* Line 2664, Address: 0x102bd44 */
    ((short*)pActfree)[27] = para[offs++]; /* Line 2665, Address: 0x102bd70 */
  } /* Line 2666, Address: 0x102bd9c */
} /* Line 2667, Address: 0x102bdb8 */











void make_beam(short iD0) { /* Line 2679, Address: 0x102bdd0 */
  short beam_ytbl[3] = { 1672, 1160, 648 }; /* Line 2680, Address: 0x102bde8 */
  short xposi_tbl[2] = { 2584, 2920 }; /* Line 2681, Address: 0x102be0c */
  short iD2, iD3, iD4;
  sprite_status* pActfree;

  iD3 = beam_ytbl[iD0]; /* Line 2685, Address: 0x102be28 */

  for (iD4 = 0; iD4 < 2; ++iD4) /* Line 2687, Address: 0x102be48 */
  {
    if (actwkchk(&pActfree) != 0) return; /* Line 2689, Address: 0x102be54 */
    iD2 = xposi_tbl[iD4]; /* Line 2690, Address: 0x102be68 */
    pActfree->actno = 64; /* Line 2691, Address: 0x102be84 */
    pActfree->xposi.w.h = iD2; /* Line 2692, Address: 0x102be90 */
    pActfree->yposi.w.h = iD3; /* Line 2693, Address: 0x102be98 */
    pActfree->userflag.b.h = (unsigned char)iD4; /* Line 2694, Address: 0x102bea0 */
  } /* Line 2695, Address: 0x102beb4 */
} /* Line 2696, Address: 0x102bed4 */











void make_bakuha(sprite_status* pActwk) { /* Line 2708, Address: 0x102bef0 */
  sprite_status* pActfree;

  if (actwkchk(&pActfree) != 0) return; /* Line 2711, Address: 0x102befc */
  soundset(158); /* Line 2712, Address: 0x102bf10 */
  pActfree->actno = 63; /* Line 2713, Address: 0x102bf1c */
  pActfree->mstno.b.h = 1; /* Line 2714, Address: 0x102bf28 */
  ((unsigned short*)pActfree)[25] = pActwk - actwk; /* Line 2715, Address: 0x102bf34 */
  pActwk->actno = pActwk->actno; /* Line 2716, Address: 0x102bf68 */
} /* Line 2717, Address: 0x102bf78 */











void make_bakuha2(sprite_status* pActwk) { /* Line 2729, Address: 0x102bf90 */
  sprite_status* pActfree;
  int_union lD0, lD1;

  if (actwkchk(&pActfree) != 0) return; /* Line 2733, Address: 0x102bf9c */
  soundset(158); /* Line 2734, Address: 0x102bfb0 */
  pActfree->actno = 63; /* Line 2735, Address: 0x102bfbc */

  pActfree->xposi.w.h = pActwk->xposi.w.h; /* Line 2737, Address: 0x102bfc8 */
  pActfree->yposi.w.h = pActwk->yposi.w.h - 8; /* Line 2738, Address: 0x102bfd8 */
  lD0.l = random(); /* Line 2739, Address: 0x102bffc */
  lD1.l = lD0.l; /* Line 2740, Address: 0x102c008 */
  lD0.l = lD0.w.l & 65535; /* Line 2741, Address: 0x102c010 */
  lD0.l = lD0.w.l; /* Line 2742, Address: 0x102c024 */

  lD1.l = lD1.w.h & 32767; /* Line 2744, Address: 0x102c034 */
  lD1.l = -(long int)lD1.l; /* Line 2745, Address: 0x102c048 */


  pActfree->xspeed.w = lD0.l % 1024; /* Line 2748, Address: 0x102c064 */
  pActfree->yspeed.w = lD1.l % 1024; /* Line 2749, Address: 0x102c094 */
} /* Line 2750, Address: 0x102c0c4 */











void make_meca(sprite_status* pActwk) { /* Line 2762, Address: 0x102c0e0 */
  sprite_status* pActfree;

  if (actwkchk(&pActfree) != 0) return; /* Line 2765, Address: 0x102c0ec */
  ((unsigned short*)pActfree)[25] = pActwk - actwk; /* Line 2766, Address: 0x102c100 */
  pActfree->actno = 53; /* Line 2767, Address: 0x102c134 */
  ((unsigned short*)pActwk)[25] = pActfree - actwk; /* Line 2768, Address: 0x102c140 */

  if (actwkchk(&pActfree) != 0) return; /* Line 2770, Address: 0x102c174 */
  ((unsigned short*)pActfree)[25] = pActwk - actwk; /* Line 2771, Address: 0x102c188 */
  pActfree->actno = 54; /* Line 2772, Address: 0x102c1bc */

  if (actwkchk(&pActfree) != 0) return; /* Line 2774, Address: 0x102c1c8 */
  ((unsigned short*)pActfree)[25] = pActwk - actwk; /* Line 2775, Address: 0x102c1dc */
  pActfree->actno = 55; /* Line 2776, Address: 0x102c210 */
} /* Line 2777, Address: 0x102c21c */











void frameout_chk(sprite_status* pActwk) { /* Line 2789, Address: 0x102c230 */
  if (pActwk->yposi.w.h > 1776) /* Line 2790, Address: 0x102c23c */
  {
    frameout(pActwk); /* Line 2792, Address: 0x102c258 */
  }
} /* Line 2794, Address: 0x102c264 */











short get_snc_floor(void) {
  if (actwk[0].yposi.w.h <= 664) /* Line 2807, Address: 0x102c280 */
    return 2; /* Line 2808, Address: 0x102c29c */
  if (actwk[0].yposi.w.h <= 1176) /* Line 2809, Address: 0x102c2a8 */
    return 1; /* Line 2810, Address: 0x102c2c4 */

  return 0; /* Line 2812, Address: 0x102c2d0 */
} /* Line 2813, Address: 0x102c2d4 */











short get_beam_pos(void) {
  if (actwk[0].yposi.w.h <= 864) /* Line 2826, Address: 0x102c2e0 */
    return 7; /* Line 2827, Address: 0x102c2fc */
  if (actwk[0].yposi.w.h <= 1376) /* Line 2828, Address: 0x102c308 */
    return 6; /* Line 2829, Address: 0x102c324 */

  return 5; /* Line 2831, Address: 0x102c330 */

} /* Line 2833, Address: 0x102c334 */











void egg6_jisin(sprite_status* pActwk) { /* Line 2845, Address: 0x102c340 */
  short iD0;

  if (pActwk->actfree[14] != 0) /* Line 2848, Address: 0x102c34c */
  {
    --pActwk->actfree[14]; /* Line 2850, Address: 0x102c360 */
    if (!(pActwk->actfree[14] & 1)) /* Line 2851, Address: 0x102c370 */
      iD0 = -2; /* Line 2852, Address: 0x102c388 */
    else
    {
      iD0 = -6; /* Line 2855, Address: 0x102c39c */
    }
    scralim_down += iD0; /* Line 2857, Address: 0x102c3a8 */
    scralim_n_down += iD0; /* Line 2858, Address: 0x102c3bc */
  }







} /* Line 2867, Address: 0x102c3d0 */











void colchg_set(unsigned char byD0) { /* Line 2879, Address: 0x102c3e0 */
  short i;
  for (i = 0; i < 6; ++i) /* Line 2881, Address: 0x102c3ec */
  {
    clchgtim[i] = byD0; /* Line 2883, Address: 0x102c3f8 */
  } /* Line 2884, Address: 0x102c414 */
} /* Line 2885, Address: 0x102c434 */

void colchg_stop(void) { /* Line 2887, Address: 0x102c450 */
  colchg_set(128); /* Line 2888, Address: 0x102c458 */
} /* Line 2889, Address: 0x102c464 */

void colchg_start(void) { /* Line 2891, Address: 0x102c480 */
  colchg_set(0); /* Line 2892, Address: 0x102c488 */
} /* Line 2893, Address: 0x102c494 */
