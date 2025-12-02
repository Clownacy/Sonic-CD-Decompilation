#include "..\EQU.H"
#include "BOSS_7.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\GOAL.H"
#include "..\IO.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SCORE.H"
#include "COL7A.H"
#include "COLI7.H"

static void msnc_ini(sprite_status* pActwk);
static void msnc_demo1(sprite_status* pActwk);
static void msnc_demo2(sprite_status* pActwk);
static void msnc_demo2_ini(sprite_status* pActwk);
static void kamae_anime(sprite_status* pActwk);
static void fire_start(sprite_status* pActwk);
static void door_open(sprite_status* pActwk);
static void msnc_demo2_next(sprite_status* pActwk);
static void msnc_egg_chk(sprite_status* pActwk);
static void goal_chk(sprite_status* pActwk);
static void goal_chk_snc_win(sprite_status* pActwk);
static void goal_chk_msnc_win(sprite_status* pActwk);
static void loser_posiset(sprite_status* pActwk);
static void msnc_low_move(sprite_status* pActwk);
static void msnc_atc_move(sprite_status* pActwk);
static void baisoku_mode(sprite_status* pActwk);
static void msnc_normal_move(sprite_status* pActwk);
static void msnc_hi_set(sprite_status* pActwk);
static void msnc_low_set(sprite_status* pActwk);
static void msnc_wk_clr(sprite_status* pActwk);
static void msnc_wk_clr2(sprite_status* pActwk);
static void msnc_atc(sprite_status* pActwk);
static void msnc_act_ini(sprite_status* pActwk);
static void msnc_act_next(sprite_status* pActwk);
static void msnc_f_atc(sprite_status* pActwk);
static void msnc_f_atc_tobi(sprite_status* pActwk);
static void msnc_f_atc_atack(sprite_status* pActwk);
static void msnc_f_atc_coli(sprite_status* pActwk);
static void msnc_f_atc_end(sprite_status* pActwk);
static void msnc_b_atc(sprite_status* pActwk);
static void msnc_b_atc_atack(sprite_status* pActwk);
static void msnc_b_atc_coli(sprite_status* pActwk);
static void msnc_b_atc_kill(sprite_status* pActwk);
static void msnc_ele_ini(sprite_status* pActwk);
static void msnc_ele_01(sprite_status* pActwk);
static void msnc_win(sprite_status* pActwk);
static void msnc_win_ini(sprite_status* pActwk);
static void msnc_win_wait(sprite_status* pActwk);
static void msnc_win_timer(sprite_status* pActwk);
static void msnc_win_chichi(sprite_status* pActwk);
static void msnc_lose(sprite_status* pActwk);
static void egg7_ini(sprite_status* pActwk);
static void egg7_demo1(sprite_status* pActwk);
static void snc_wait(sprite_status* pActwk);
static void r_l(sprite_status* pActwk);
static void l_r(sprite_status* pActwk);
static void r_l2(sprite_status* pActwk);
static void egg7_demo2(sprite_status* pActwk);
static void msnc_turn(sprite_status* pActwk);
static void beam_on(sprite_status* pActwk);
static void beam_on2(sprite_status* pActwk);
static void beam_off(sprite_status* pActwk);
static void move_start(sprite_status* pActwk);
static void beam_next(sprite_status* pActwk);
static void egg7_move(sprite_status* pActwk);
static void egg7_goal(sprite_status* pActwk);
static void egg7_goal_ini(sprite_status* pActwk);
static void egg7_goal_msnc_win(sprite_status* pActwk);
static void egg7_goal_snc_win(sprite_status* pActwk);
static void egg7_goal0(sprite_status* pActwk);
static void egg7_goal1(sprite_status* pActwk);
static void egg7_goal2(sprite_status* pActwk);
static void egg7_goal3(sprite_status* pActwk);
static void emie7clrset(void);
static void egg7_spdset(sprite_status* pActwk);
static void egg7_maxspdset(sprite_status* pActwk, short d1);
static void egg_beamchk(sprite_status* pActwk);
static void egg7_hscr(sprite_status* pActwk);
static void egg7_hscr_pat0(void);
static void egg7_hscr_pat1(void);
static void egg7_hscr_pat2(void);
static void egg7_hscr_pat3(void);
static void egg_hight(sprite_status* pActwk);
static void msnc_hight(sprite_status* pActwk);
static void hight_set2(sprite_status* pActwk);
static void hight_set(sprite_status* pActwk);
static short hight_set_retry(sprite_status* pActwk, short* d1);
static void egg7beam_ini(sprite_status* pActwk, sprite_status* a2);
static void egg7beam_01(sprite_status* pActwk, sprite_status* a2);
static short beam_posi(sprite_status* pActwk, sprite_status* a2);
static void egg7beam_kemuri1(sprite_status* pActwk, sprite_status* a2);
static void egg7beam_kemuri2(sprite_status* pActwk, sprite_status* a2);
static void kemuri_disp(sprite_status* pActwk);
static void egg7jet_ini(sprite_status* pActwk);
static void egg7jet_01(sprite_status* pActwk);
static void msnc_bara_ini(sprite_status* pActwk);
static void msnc_bara_01(sprite_status* pActwk);
static void add_spd3(sprite_status* pActwk);
static void add_spd2(sprite_status* pActwk);
static void add_spd(sprite_status* pActwk);
static void w_timer(sprite_status* pActwk);
static void b_timer(sprite_status* pActwk);
static void event_timer(sprite_status* pActwk, short* pTimer, void(**func)(sprite_status*));
static void make_bara(sprite_status* pActwk);
static void make_ele(sprite_status* pActwk);
static void make_msnc(sprite_status* pActwk);
static void make_jet(sprite_status* pActwk);
static void make_beam(sprite_status* pActwk);
static void make_kemuri(sprite_status* pActwk);
static void make_bakuha(sprite_status* pActwk);
static void make_hahen(sprite_status* pActwk);

static unsigned char egg7_pchg0[4] = { 5, 0, 1, 255 };
static unsigned char* egg7_pchg[1] = { egg7_pchg0 };
static sprite_pattern egg7_pat00 = {
  1,
  { { -40, -36, 0, 466 } }
};
static sprite_pattern egg7_pat01 = {
  4,
  {
    { 22, 15, 0, 467 },
    { -24, -21, 0, 468 },
    { -32, -4, 0, 469 },
    { -40, -36, 0, 470 }
  }
};
sprite_pattern* egg7_pat[2] = {
  &egg7_pat00,
  &egg7_pat01
};
static unsigned char egg7beam_pchg0[4] = { 1, 0, 1, 255 };
static unsigned char* egg7beam_pchg[1] = { egg7beam_pchg0 };
static sprite_pattern egg7b_pat00 = {
  1,
  { { -8, -16, 0, 471 } }
};
static sprite_pattern egg7b_pat01 = {
  1,
  { { -8, -16, 0, 472 } }
};
sprite_pattern* egg7beam_pat[2] = {
  &egg7b_pat00,
  &egg7b_pat01
};
static unsigned char egg7jet_pchg0[6] = { 1, 0, 1, 3, 4, 255 };
static unsigned char egg7jet_pchg1[6] = { 1, 0, 2, 3, 5, 255 };
static unsigned char* egg7jet_pchg[2] = {
  egg7jet_pchg0,
  egg7jet_pchg1
};
static sprite_pattern egg7j_pat00 = {
  1,
  { { -12, -8, 0, 473 } }
};
static sprite_pattern egg7j_pat01 = {
  1,
  { { -4, -8, 0, 474 } }
};
static sprite_pattern egg7j_pat02 = {
  1,
  { { -20, -8, 0, 475 } }
};
static sprite_pattern egg7j_pat03 = {
  1,
  { { -12, -8, 0, 476 } }
};
static sprite_pattern egg7j_pat04 = {
  1,
  { { -4, -8, 0, 477 } }
};
static sprite_pattern egg7j_pat05 = {
  1,
  { { -20, -8, 0, 478 } }
};
sprite_pattern* egg7jet_pat[6] = {
  &egg7j_pat00,
  &egg7j_pat01,
  &egg7j_pat02,
  &egg7j_pat03,
  &egg7j_pat04,
  &egg7j_pat05
};
static unsigned char msnc_pchg00[3] = { 19, 0, 255 };
static unsigned char msnc_pchg01[10] = { 19, 2, 1, 2, 1, 2, 1, 2, 0, 255 };
static unsigned char msnc_pchg02[5] = { 9, 4, 5, 6, 255 };
static unsigned char msnc_pchg03[3] = { 9, 6, 255 };
static unsigned char msnc_pchg04[6] = { 1, 7, 6, 8, 6, 255 };
static unsigned char msnc_pchg05[6] = { 1, 10, 9, 11, 9, 255 };
static unsigned char msnc_pchg06[6] = { 1, 13, 12, 14, 12, 255 };
static unsigned char msnc_pchg07[6] = { 1, 16, 15, 17, 15, 255 };
static unsigned char msnc_pchg08[3] = { 19, 18, 255 };
static unsigned char msnc_pchg09[4] = { 1, 19, 20, 255 };
static unsigned char msnc_pchg10[4] = { 1, 21, 12, 255 };
static unsigned char msnc_pchg11[3] = { 254, 22, 255 };
static unsigned char msnc_pchg12[4] = { 19, 2, 1, 255 };
static unsigned char msnc_pchg13[3] = { 254, 23, 255 };
static unsigned char* msnc_pchg[14] = {
  msnc_pchg00,
  msnc_pchg01,
  msnc_pchg02,
  msnc_pchg03,
  msnc_pchg04,
  msnc_pchg05,
  msnc_pchg06,
  msnc_pchg07,
  msnc_pchg08,
  msnc_pchg09,
  msnc_pchg10,
  msnc_pchg11,
  msnc_pchg12,
  msnc_pchg13
};
static sprite_pattern msnc_pat00 = {
  1,
  { { -20, -20, 0, 479 } }
};
static sprite_pattern msnc_pat01 = {
  1,
  { { -20, -20, 0, 480 } }
};
static sprite_pattern msnc_pat02 = {
  1,
  { { -20, -20, 0, 481 } }
};
static sprite_pattern msnc_pat03 = {
  1,
  { { -20, -20, 0, 482 } }
};
static sprite_pattern msnc_pat04 = {
  1,
  { { -20, -20, 0, 483 } }
};
static sprite_pattern msnc_pat05 = {
  1,
  { { -20, -20, 0, 484 } }
};
static sprite_pattern msnc_pat06 = {
  1,
  { { -16, -16, 0, 485 } }
};
static sprite_pattern msnc_pat07 = {
  2,
  {
    { -16, -16, 0, 486 },
    { -16, 4, 0, 487 }
  }
};
static sprite_pattern msnc_pat08 = {
  2,
  {
    { -16, -16, 0, 488 },
    { -16, 4, 0, 489 }
  }
};
static sprite_pattern msnc_pat09 = {
  1,
  { { -20, -24, 0, 490 } }
};
static sprite_pattern msnc_pat10 = {
  2,
  {
    { -20, -24, 0, 491 },
    { -16, -4, 0, 492 }
  }
};
static sprite_pattern msnc_pat11 = {
  2,
  {
    { -20, -24, 0, 493 },
    { -20, -8, 0, 494 }
  }
};
static sprite_pattern msnc_pat12 = {
  1,
  { { -20, -24, 0, 495 } }
};
static sprite_pattern msnc_pat13 = {
  2,
  {
    { -20, -24, 0, 496 },
    { -20, -8, 0, 497 }
  }
};
static sprite_pattern msnc_pat14 = {
  2,
  {
    { -20, -24, 0, 498 },
    { -24, -12, 0, 499 }
  }
};
static sprite_pattern msnc_pat15 = {
  1,
  { { -20, -24, 0, 500 } }
};
static sprite_pattern msnc_pat16 = {
  2,
  {
    { -4, -8, 0, 501 },
    { -20, -24, 0, 502 }
  }
};
static sprite_pattern msnc_pat17 = {
  2,
  {
    { -4, -8, 0, 503 },
    { -20, -24, 0, 504 }
  }
};
static sprite_pattern msnc_pat18 = {
  1,
  { { -24, -4, 0, 505 } }
};
static sprite_pattern msnc_pat19 = {
  1,
  { { -24, -12, 0, 506 } }
};
static sprite_pattern msnc_pat20 = {
  1,
  { { -24, -12, 0, 507 } }
};
static sprite_pattern msnc_pat21 = {
  1,
  { { -16, -24, 0, 508 } }
};
static sprite_pattern msnc_pat22 = {
  1,
  { { -20, -20, 0, 509 } }
};
static sprite_pattern msnc_pat23 = {
  1,
  { { -20, -24, 0, 510 } }
};
sprite_pattern* msnc_pat[24] = {
  &msnc_pat00,
  &msnc_pat01,
  &msnc_pat02,
  &msnc_pat03,
  &msnc_pat04,
  &msnc_pat05,
  &msnc_pat06,
  &msnc_pat07,
  &msnc_pat08,
  &msnc_pat09,
  &msnc_pat10,
  &msnc_pat11,
  &msnc_pat12,
  &msnc_pat13,
  &msnc_pat14,
  &msnc_pat15,
  &msnc_pat16,
  &msnc_pat17,
  &msnc_pat18,
  &msnc_pat19,
  &msnc_pat20,
  &msnc_pat21,
  &msnc_pat22,
  &msnc_pat23
};
static sprite_pattern msnc_ele_pat0 = {
  1,
  { { -24, -24, 0, 511 } }
};
static sprite_pattern msnc_ele_pat1 = {
  1,
  { { -24, -24, 0, 512 } }
};
sprite_pattern* msnc_ele_pat[2] = {
  &msnc_ele_pat0,
  &msnc_ele_pat1
};
static sprite_pattern msnc_bara_pat0 = {
  1,
  { { -4, -4, 0, 513 } }
};
static sprite_pattern msnc_bara_pat1 = {
  1,
  { { -4, -4, 0, 514 } }
};
static sprite_pattern msnc_bara_pat2 = {
  1,
  { { -4, -4, 0, 515 } }
};
static sprite_pattern msnc_bara_pat3 = {
  1,
  { { -4, -4, 0, 516 } }
};
static sprite_pattern msnc_bara_pat4 = {
  1,
  { { -8, -8, 0, 517 } }
};
sprite_pattern* msnc_bara_pat[5] = {
  &msnc_bara_pat0,
  &msnc_bara_pat1,
  &msnc_bara_pat2,
  &msnc_bara_pat3,
  &msnc_bara_pat4
};
static sprite_pattern hahen73_pat0 = {
  1,
  { { -4, -4, 0, 518 } }
};
static sprite_pattern hahen73_pat1 = {
  1,
  { { -4, -4, 0, 519 } }
};
static sprite_pattern hahen73_pat2 = {
  1,
  { { -4, -4, 0, 520 } }
};
static sprite_pattern hahen73_pat3 = {
  1,
  { { -4, -4, 0, 521 } }
};
sprite_pattern* hahen73_pat[4] = {
  &hahen73_pat0,
  &hahen73_pat1,
  &hahen73_pat2,
  &hahen73_pat3
};
short QuickReturn;
sprite_status* pEggman;
sprite_status* pPlayerwk;
short GL_d5;
sprite_status* pMsnc;
extern unsigned short scr_dir_tbl[];
extern sprite_pattern* bakupat[7];


























































































































































































































































































































void msnc(sprite_status* pActwk) { /* Line 745, Address: 0x1029190 */
  void(*tbl[10])(sprite_status*) = /* Line 746, Address: 0x102919c */
  {
    &msnc_ini,
    &msnc_demo1,
    &msnc_demo2,
    &msnc_low_move,
    &msnc_low_move,
    &msnc_atc,
    &msnc_f_atc,
    &msnc_b_atc,
    &msnc_win,
    &msnc_lose
  };


  pEggman = &actwk[((short*)pActwk)[25]]; /* Line 761, Address: 0x10291d0 */
  goal_chk(pActwk); /* Line 762, Address: 0x1029200 */
  msnc_egg_chk(pActwk); /* Line 763, Address: 0x102920c */

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 765, Address: 0x1029218 */
  if (QuickReturn) /* Line 766, Address: 0x1029254 */
  {
    QuickReturn = 0; /* Line 768, Address: 0x1029264 */
    return; /* Line 769, Address: 0x102926c */
  }
  patchg(pActwk, msnc_pchg); /* Line 771, Address: 0x1029274 */
  actionsub(pActwk); /* Line 772, Address: 0x1029288 */
} /* Line 773, Address: 0x1029294 */




static void msnc_ini(sprite_status* pActwk) { /* Line 778, Address: 0x10292b0 */
  pActwk->actflg = 4; /* Line 779, Address: 0x10292bc */
  pActwk->sprpri = 5; /* Line 780, Address: 0x10292c8 */
  pActwk->sprhsize = 20; /* Line 781, Address: 0x10292d4 */
  pActwk->sprvsize = 24; /* Line 782, Address: 0x10292e0 */
  pActwk->sproffset = 892; /* Line 783, Address: 0x10292ec */
  pActwk->patbase = msnc_pat; /* Line 784, Address: 0x10292f8 */
  pActwk->r_no0 += 2; /* Line 785, Address: 0x1029308 */

  msnc_demo1(pActwk); /* Line 787, Address: 0x1029318 */
} /* Line 788, Address: 0x1029324 */




static void msnc_demo1(sprite_status* pActwk) { /* Line 793, Address: 0x1029340 */
  if (pActwk->mstno.b.h == 1) /* Line 794, Address: 0x1029348 */
  {
    if (pActwk->patcnt != 7) return; /* Line 796, Address: 0x1029364 */
    pActwk->mstno.b.h = 0; /* Line 797, Address: 0x102937c */
  }

  if (!(pPlayerwk->cddat & 2)) goto label1; /* Line 800, Address: 0x1029384 */
  if (!(pPlayerwk->cddat & 4)) goto label1; /* Line 801, Address: 0x10293a0 */
  if (pActwk->actfree[3]) return; /* Line 802, Address: 0x10293bc */
  pActwk->actfree[3] = 1; /* Line 803, Address: 0x10293cc */
  pActwk->mstno.b.h = 1; /* Line 804, Address: 0x10293d8 */
  return; /* Line 805, Address: 0x10293e4 */

label1:
  pActwk->actfree[3] = 0; /* Line 808, Address: 0x10293ec */
} /* Line 809, Address: 0x10293f4 */




static void msnc_demo2(sprite_status* pActwk) { /* Line 814, Address: 0x1029400 */
  void(*demo2_jmp[8])(sprite_status*) = /* Line 815, Address: 0x102940c */
  {
    &msnc_demo2_ini,
    &kamae_anime,
    &w_timer,
    &fire_start,
    &w_timer,
    &door_open,
    &w_timer,
    &msnc_demo2_next
  };

  demo2_jmp[pActwk->actfree[3]](pActwk); /* Line 827, Address: 0x1029440 */
} /* Line 828, Address: 0x1029464 */


static void msnc_demo2_ini(sprite_status* pActwk) { /* Line 831, Address: 0x1029480 */
  pActwk->mstno.b.h = 2; /* Line 832, Address: 0x102948c */
  ++pActwk->actfree[3]; /* Line 833, Address: 0x1029498 */
  pActwk->patno = 0; /* Line 834, Address: 0x10294a8 */

  kamae_anime(pActwk); /* Line 836, Address: 0x10294b0 */
} /* Line 837, Address: 0x10294bc */


static void kamae_anime(sprite_status* pActwk) { /* Line 840, Address: 0x10294d0 */
  if (pActwk->patno == 6) /* Line 841, Address: 0x10294d8 */
  {
    pActwk->mstno.b.h = 3; /* Line 843, Address: 0x10294f0 */
    ++pActwk->actfree[3]; /* Line 844, Address: 0x10294fc */
    ((short*)pActwk)[23] = 120; /* Line 845, Address: 0x102950c */
  }
} /* Line 847, Address: 0x1029518 */


static void fire_start(sprite_status* pActwk) { /* Line 850, Address: 0x1029530 */
  ++pActwk->actfree[3]; /* Line 851, Address: 0x1029538 */
  pActwk->mstno.b.h = 4; /* Line 852, Address: 0x1029548 */
  ((short*)pActwk)[23] = 150; /* Line 853, Address: 0x1029554 */
} /* Line 854, Address: 0x1029560 */


static void door_open(sprite_status* pActwk) { /* Line 857, Address: 0x1029570 */
  short d0;

  pEggman->actfree[14] = 130; /* Line 860, Address: 0x1029580 */

  bossflag |= 128; /* Line 862, Address: 0x1029590 */
  ++pActwk->actfree[3]; /* Line 863, Address: 0x10295a4 */
  ((short*)pActwk)[23] = 60; /* Line 864, Address: 0x10295b4 */
  d0 = 32; /* Line 865, Address: 0x10295c0 */
  if (generate_flag) /* Line 866, Address: 0x10295cc */
  {
    d0 = 31; /* Line 868, Address: 0x10295dc */
  }
  sub_sync(d0); /* Line 870, Address: 0x10295e8 */
} /* Line 871, Address: 0x10295f4 */


static void msnc_demo2_next(sprite_status* pActwk) { /* Line 874, Address: 0x1029610 */
  pActwk->actfree[2] |= 32; /* Line 875, Address: 0x102961c */
  msnc_low_set(pActwk); /* Line 876, Address: 0x102962c */
} /* Line 877, Address: 0x1029638 */




static void msnc_egg_chk(sprite_status* pActwk) { /* Line 882, Address: 0x1029650 */
  short d0;

  if (!(pActwk->actfree[2] & 32)) return; /* Line 885, Address: 0x1029660 */
  d0 = pActwk->xposi.w.h; /* Line 886, Address: 0x1029678 */
  d0 -= pEggman->xposi.w.h; /* Line 887, Address: 0x1029688 */
  if (d0 > 88) return; /* Line 888, Address: 0x10296a0 */

  if (pActwk->xposi.w.h >= 13568) /* Line 890, Address: 0x10296b4 */
  {
    pActwk->xspeed.w = pEggman->xspeed.w; /* Line 892, Address: 0x10296d0 */
    ((short*)pActwk)[26] = 8; /* Line 893, Address: 0x10296e4 */
    ((short*)pActwk)[28] = 1536; /* Line 894, Address: 0x10296f0 */
    return; /* Line 895, Address: 0x10296fc */
  }

  d0 = pActwk->xspeed.w; /* Line 898, Address: 0x1029704 */
  if (d0 < pEggman->xspeed.w) /* Line 899, Address: 0x1029714 */
  {
    pActwk->xspeed.w = pEggman->xspeed.w; /* Line 901, Address: 0x102973c */
    ((short*)pActwk)[26] = 8; /* Line 902, Address: 0x1029750 */
    ((short*)pActwk)[28] = 1536; /* Line 903, Address: 0x102975c */
  }

  pActwk->r_no0 = 12; /* Line 906, Address: 0x1029768 */
  msnc_wk_clr(pActwk); /* Line 907, Address: 0x1029774 */
} /* Line 908, Address: 0x1029780 */




static void goal_chk(sprite_status* pActwk) { /* Line 913, Address: 0x10297a0 */
  short d0;

  if (pEggman->actfree[15] & 128) return; /* Line 916, Address: 0x10297b0 */
  if (pEggman->actfree[15]) /* Line 917, Address: 0x10297cc */
  {
    goal_chk_snc_win(pActwk); /* Line 919, Address: 0x10297e0 */
    return; /* Line 920, Address: 0x10297ec */
  }

  d0 = 16016; /* Line 923, Address: 0x10297f4 */
  if (d0 <= pActwk->xposi.w.h) /* Line 924, Address: 0x1029800 */
  {
    goal_chk_msnc_win(pActwk); /* Line 926, Address: 0x1029824 */
  } /* Line 927, Address: 0x1029830 */
  else
  {
    if (d0 <= pPlayerwk->xposi.w.h) /* Line 930, Address: 0x1029838 */
    {
      goal_chk_snc_win(pActwk); /* Line 932, Address: 0x1029860 */
    }
  }
} /* Line 935, Address: 0x102986c */


static void goal_chk_snc_win(sprite_status* pActwk) { /* Line 938, Address: 0x1029880 */
  if (pEggman->actfree[15] == 0) /* Line 939, Address: 0x102988c */
  {
    pEggman->actfree[15] = 1; /* Line 941, Address: 0x10298a4 */
    bossflag |= 128; /* Line 942, Address: 0x10298b4 */
    soundset(187); /* Line 943, Address: 0x10298c8 */
    loser_posiset(pActwk); /* Line 944, Address: 0x10298d4 */
    ((short*)pActwk)[28] = 2048; /* Line 945, Address: 0x10298e0 */
    ((short*)pActwk)[26] = 16; /* Line 946, Address: 0x10298ec */
  }
  if (pActwk->xposi.w.h >= 15944) /* Line 948, Address: 0x10298f8 */
  {
    pEggman->actfree[15] |= 128; /* Line 950, Address: 0x1029914 */
    pActwk->actfree[2] &= 223; /* Line 951, Address: 0x1029928 */
    pActwk->r_no0 = 18; /* Line 952, Address: 0x1029938 */
    make_bara(pActwk); /* Line 953, Address: 0x1029944 */
    ((short*)pActwk)[23] = 0; /* Line 954, Address: 0x1029950 */
    pActwk->actfree[3] = 0; /* Line 955, Address: 0x1029958 */
  }
} /* Line 957, Address: 0x1029960 */


static void goal_chk_msnc_win(sprite_status* pActwk) { /* Line 960, Address: 0x1029970 */
  pActwk->xposi.w.h = 16016; /* Line 961, Address: 0x102997c */
  pEggman->actfree[15] = 130; /* Line 962, Address: 0x1029988 */
  bossflag |= 128; /* Line 963, Address: 0x1029998 */

  soundset(187); /* Line 965, Address: 0x10299ac */

  loser_posiset(pPlayerwk); /* Line 967, Address: 0x10299b8 */

  pActwk->actfree[2] &= 223; /* Line 969, Address: 0x10299c8 */
  pActwk->r_no0 = 16; /* Line 970, Address: 0x10299d8 */
  ((short*)pActwk)[23] = 0; /* Line 971, Address: 0x10299e4 */
  pActwk->actfree[3] = 0; /* Line 972, Address: 0x10299ec */
} /* Line 973, Address: 0x10299f4 */


static void loser_posiset(sprite_status* pActwk) { /* Line 976, Address: 0x1029a10 */
  short d1;

  if (pActwk->actno) /* Line 979, Address: 0x1029a1c */
  {
    d1 = 15944; /* Line 981, Address: 0x1029a2c */
    if (d1 < pActwk->xposi.w.h) /* Line 982, Address: 0x1029a38 */
    {
      pActwk->xposi.w.h = d1; /* Line 984, Address: 0x1029a5c */
    }
  }
} /* Line 987, Address: 0x1029a64 */




static void msnc_low_move(sprite_status* pActwk) { /* Line 992, Address: 0x1029a80 */
  short d4;

  add_spd3(pActwk); /* Line 995, Address: 0x1029a90 */
  msnc_hight(pActwk); /* Line 996, Address: 0x1029a9c */
  if (pEggman->actfree[15]) return; /* Line 997, Address: 0x1029aa8 */



  ++((short*)pActwk)[30]; /* Line 1001, Address: 0x1029abc */
  if (pActwk->actfree[12]) /* Line 1002, Address: 0x1029acc */
  {
    baisoku_mode(pActwk); /* Line 1004, Address: 0x1029adc */
    return; /* Line 1005, Address: 0x1029ae8 */
  }

  GL_d5 = pPlayerwk->xposi.w.h; /* Line 1008, Address: 0x1029af0 */
  GL_d5 -= pActwk->xposi.w.h; /* Line 1009, Address: 0x1029b04 */
  d4 = GL_d5; /* Line 1010, Address: 0x1029b20 */
  if (d4 >= 0) /* Line 1011, Address: 0x1029b30 */
  {
    pActwk->actfree[2] |= 64; /* Line 1013, Address: 0x1029b40 */
  } /* Line 1014, Address: 0x1029b50 */
  else
  {
    pActwk->actfree[2] &= 191; /* Line 1017, Address: 0x1029b58 */
    d4 *= -1; /* Line 1018, Address: 0x1029b68 */
  }


  if (d4 < 160) /* Line 1022, Address: 0x1029b74 */
  {
    if (((short*)pActwk)[31] < 0) /* Line 1024, Address: 0x1029b88 */
    {
      ((short*)pActwk)[31] = 0; /* Line 1026, Address: 0x1029ba0 */
    }

    ++((short*)pActwk)[31]; /* Line 1029, Address: 0x1029ba8 */
    if (d4 < 16) /* Line 1030, Address: 0x1029bb8 */
    {
      ((short*)pActwk)[32] = 0; /* Line 1032, Address: 0x1029bcc */
    } /* Line 1033, Address: 0x1029bd4 */
    else
    {
      ++((short*)pActwk)[32]; /* Line 1036, Address: 0x1029bdc */
    }
  } /* Line 1038, Address: 0x1029bec */
  else
  {
    if (((short*)pActwk)[31] >= 0) /* Line 1041, Address: 0x1029bf4 */
    {
      ((short*)pActwk)[31] = 0; /* Line 1043, Address: 0x1029c0c */
    }

    --((short*)pActwk)[31]; /* Line 1046, Address: 0x1029c14 */
  }

  if (((short*)pActwk)[32] >= 50) /* Line 1049, Address: 0x1029c24 */
  {
    msnc_atc_move(pActwk); /* Line 1051, Address: 0x1029c40 */
  } /* Line 1052, Address: 0x1029c4c */
  else
  {
    msnc_normal_move(pActwk); /* Line 1055, Address: 0x1029c54 */
  }
} /* Line 1057, Address: 0x1029c60 */


static void msnc_atc_move(sprite_status* pActwk) { /* Line 1060, Address: 0x1029c80 */
  if (pActwk->xposi.w.h < 13568) /* Line 1061, Address: 0x1029c8c */
  {
    pActwk->r_no0 = 10; /* Line 1063, Address: 0x1029ca8 */
    msnc_wk_clr(pActwk); /* Line 1064, Address: 0x1029cb4 */
    return; /* Line 1065, Address: 0x1029cc0 */
  }

  if (!(pActwk->actfree[2] & 64)) /* Line 1068, Address: 0x1029cc8 */
  {
    msnc_wk_clr(pActwk); /* Line 1070, Address: 0x1029ce0 */
    pActwk->actfree[12] = 2; /* Line 1071, Address: 0x1029cec */

    ((short*)pActwk)[33] = 240; /* Line 1073, Address: 0x1029cf8 */
    msnc_normal_move(pActwk); /* Line 1074, Address: 0x1029d04 */
  } /* Line 1075, Address: 0x1029d10 */
  else
  {
    msnc_wk_clr(pActwk); /* Line 1078, Address: 0x1029d18 */
    pActwk->actfree[12] = 1; /* Line 1079, Address: 0x1029d24 */

    ((short*)pActwk)[33] = 240; /* Line 1081, Address: 0x1029d30 */
    msnc_normal_move(pActwk); /* Line 1082, Address: 0x1029d3c */
  }
} /* Line 1084, Address: 0x1029d48 */


static void baisoku_mode(sprite_status* pActwk) { /* Line 1087, Address: 0x1029d60 */

  if (((short*)pActwk)[33] < 2) /* Line 1089, Address: 0x1029d6c */
  {
    --((short*)pActwk)[33]; /* Line 1091, Address: 0x1029d88 */
    pActwk->actfree[12] = 0; /* Line 1092, Address: 0x1029d98 */
    ((short*)pActwk)[33] = 0; /* Line 1093, Address: 0x1029da0 */
  } /* Line 1094, Address: 0x1029da8 */
  else
  {
    --((short*)pActwk)[33]; /* Line 1097, Address: 0x1029db0 */
  }

  msnc_normal_move(pActwk); /* Line 1100, Address: 0x1029dc0 */
} /* Line 1101, Address: 0x1029dcc */


static void msnc_normal_move(sprite_status* pActwk) { /* Line 1104, Address: 0x1029de0 */
  short d0;

  if (((short*)pActwk)[33]) goto label1; /* Line 1107, Address: 0x1029df0 */
  if (((short*)pActwk)[31] > -120) goto label1; /* Line 1108, Address: 0x1029e00 */

  if (GL_d5 < 0) goto label2; /* Line 1110, Address: 0x1029e1c */
  msnc_atc_move(pActwk); /* Line 1111, Address: 0x1029e34 */
  return; /* Line 1112, Address: 0x1029e40 */
label1:
  d0 = ((short*)pActwk)[30]; /* Line 1114, Address: 0x1029e48 */
  d0 = (unsigned short)d0 % 60; /* Line 1115, Address: 0x1029e58 */
  if (d0 >= 30) goto label2; /* Line 1116, Address: 0x1029e7c */

  if (pActwk->r_no0 != 8) /* Line 1118, Address: 0x1029e90 */
  {
    msnc_hi_set(pActwk); /* Line 1120, Address: 0x1029ea8 */
  }
  return; /* Line 1122, Address: 0x1029eb4 */
label2:
  if (pActwk->r_no0 != 6) /* Line 1124, Address: 0x1029ebc */
  {
    msnc_low_set(pActwk); /* Line 1126, Address: 0x1029ed4 */
  }

} /* Line 1129, Address: 0x1029ee0 */


static void msnc_hi_set(sprite_status* pActwk) { /* Line 1132, Address: 0x1029f00 */
  short d0;

  if (pActwk->actfree[12] == 1) d0 = 2048; /* Line 1135, Address: 0x1029f10 */
  else if (pActwk->actfree[12] == 2) d0 = 682; /* Line 1136, Address: 0x1029f3c */
  else d0 = 1024; /* Line 1137, Address: 0x1029f68 */

  ((short*)pActwk)[28] = d0; /* Line 1139, Address: 0x1029f74 */
  if (d0 >= pActwk->xspeed.w) /* Line 1140, Address: 0x1029f7c */
  {
    d0 *= -1; /* Line 1142, Address: 0x1029fa0 */
  }
  ((short*)pActwk)[26] = d0; /* Line 1144, Address: 0x1029fac */
  pActwk->r_no0 = 8; /* Line 1145, Address: 0x1029fb4 */
  pActwk->mstno.b.h = 6; /* Line 1146, Address: 0x1029fc0 */
  msnc_wk_clr2(pActwk); /* Line 1147, Address: 0x1029fcc */
} /* Line 1148, Address: 0x1029fd8 */


static void msnc_low_set(sprite_status* pActwk) { /* Line 1151, Address: 0x1029ff0 */
  short d0;

  if (pActwk->actfree[12] == 1) d0 = 1280; /* Line 1154, Address: 0x102a000 */
  else if (pActwk->actfree[12] == 2) d0 = 426; /* Line 1155, Address: 0x102a02c */
  else d0 = 640; /* Line 1156, Address: 0x102a058 */

  ((short*)pActwk)[28] = d0; /* Line 1158, Address: 0x102a064 */
  if (d0 >= pActwk->xspeed.w) /* Line 1159, Address: 0x102a06c */
  {
    d0 *= -1; /* Line 1161, Address: 0x102a090 */
  }
  ((short*)pActwk)[26] = d0; /* Line 1163, Address: 0x102a09c */
  pActwk->r_no0 = 6; /* Line 1164, Address: 0x102a0a4 */
  pActwk->mstno.b.h = 5; /* Line 1165, Address: 0x102a0b0 */
  msnc_wk_clr2(pActwk); /* Line 1166, Address: 0x102a0bc */
} /* Line 1167, Address: 0x102a0c8 */


static void msnc_wk_clr(sprite_status* pActwk) { /* Line 1170, Address: 0x102a0e0 */
  ((short*)pActwk)[32] = 0; /* Line 1171, Address: 0x102a0ec */
  msnc_wk_clr2(pActwk); /* Line 1172, Address: 0x102a0f4 */
} /* Line 1173, Address: 0x102a100 */


static void msnc_wk_clr2(sprite_status* pActwk) { /* Line 1176, Address: 0x102a110 */
  pActwk->actfree[3] = 0; /* Line 1177, Address: 0x102a118 */
  ((short*)pActwk)[23] = 0; /* Line 1178, Address: 0x102a120 */
} /* Line 1179, Address: 0x102a128 */




static void msnc_atc(sprite_status* pActwk) { /* Line 1184, Address: 0x102a140 */
  short event_tbl_t[2] = /* Line 1185, Address: 0x102a14c */
  {
    0,
    60
  };
  void(*event_tbl_f[2])(sprite_status*) = /* Line 1190, Address: 0x102a168 */
  {
    &msnc_act_ini,
    &msnc_act_next
  };

  add_spd3(pActwk); /* Line 1196, Address: 0x102a184 */
  msnc_hight(pActwk); /* Line 1197, Address: 0x102a190 */
  event_timer(pActwk, event_tbl_t, event_tbl_f); /* Line 1198, Address: 0x102a19c */
} /* Line 1199, Address: 0x102a1b0 */


static void msnc_act_ini(sprite_status* pActwk) { /* Line 1202, Address: 0x102a1c0 */
  pActwk->mstno.b.h = 4; /* Line 1203, Address: 0x102a1cc */
  if (pActwk->xposi.w.h > scra_h_posit.w.h - 160 && pActwk->xposi.w.h < scra_h_posit.w.h + 320) /* Line 1204, Address: 0x102a1d8 */
    soundset(201); /* Line 1205, Address: 0x102a238 */
} /* Line 1206, Address: 0x102a244 */


static void msnc_act_next(sprite_status* pActwk) { /* Line 1209, Address: 0x102a260 */
  GL_d5 = pPlayerwk->xposi.w.h; /* Line 1210, Address: 0x102a26c */
  GL_d5 -= pActwk->xposi.w.h; /* Line 1211, Address: 0x102a280 */
  if (GL_d5 >= 0) /* Line 1212, Address: 0x102a29c */
  {
    pActwk->actfree[2] |= 64; /* Line 1214, Address: 0x102a2b4 */

    pActwk->r_no0 = 12; /* Line 1216, Address: 0x102a2c4 */
    msnc_wk_clr(pActwk); /* Line 1217, Address: 0x102a2d0 */
  } /* Line 1218, Address: 0x102a2dc */
  else
  {
    pActwk->actfree[2] &= 191; /* Line 1221, Address: 0x102a2e4 */

    pActwk->r_no0 = 14; /* Line 1223, Address: 0x102a2f4 */
    msnc_wk_clr(pActwk); /* Line 1224, Address: 0x102a300 */
  }
} /* Line 1226, Address: 0x102a30c */




static void msnc_f_atc(sprite_status* pActwk) { /* Line 1231, Address: 0x102a320 */
  short event_tbl_t[4] = /* Line 1232, Address: 0x102a32c */
  {
    0,
    30,
    40,
    180
  };
  void(*event_tbl_f[4])(sprite_status*) = /* Line 1239, Address: 0x102a358 */
  {
    &msnc_f_atc_tobi,
    &msnc_f_atc_atack,
    &msnc_f_atc_coli,
    &msnc_f_atc_end
  };

  add_spd3(pActwk); /* Line 1247, Address: 0x102a384 */
  msnc_hight(pActwk); /* Line 1248, Address: 0x102a390 */
  event_timer(pActwk, event_tbl_t, event_tbl_f); /* Line 1249, Address: 0x102a39c */
} /* Line 1250, Address: 0x102a3b0 */


static void msnc_f_atc_tobi(sprite_status* pActwk) { /* Line 1253, Address: 0x102a3c0 */
  if (pActwk->xposi.w.h > scra_h_posit.w.h - 160 && pActwk->xposi.w.h < scra_h_posit.w.h + 320) /* Line 1254, Address: 0x102a3cc */
    soundset(202); /* Line 1255, Address: 0x102a42c */

  ((short*)pActwk)[26] = 8; /* Line 1257, Address: 0x102a438 */
  ((short*)pActwk)[28] = 1536; /* Line 1258, Address: 0x102a444 */
  pActwk->mstno.b.h = 8; /* Line 1259, Address: 0x102a450 */
} /* Line 1260, Address: 0x102a45c */


static void msnc_f_atc_atack(sprite_status* pActwk) { /* Line 1263, Address: 0x102a470 */
  pActwk->mstno.b.h = 9; /* Line 1264, Address: 0x102a478 */
} /* Line 1265, Address: 0x102a484 */


static void msnc_f_atc_coli(sprite_status* pActwk) { /* Line 1268, Address: 0x102a490 */
  pActwk->colino = 188; /* Line 1269, Address: 0x102a498 */
  pActwk->colicnt = 2; /* Line 1270, Address: 0x102a4a4 */
} /* Line 1271, Address: 0x102a4b0 */


static void msnc_f_atc_end(sprite_status* pActwk) { /* Line 1274, Address: 0x102a4c0 */
  short d0;

  pActwk->colino = 0; /* Line 1277, Address: 0x102a4d0 */
  pActwk->colicnt = 0; /* Line 1278, Address: 0x102a4d8 */
  d0 = pEggman->xposi.w.h; /* Line 1279, Address: 0x102a4e0 */
  if (d0 < pActwk->xposi.w.h) msnc_hi_set(pActwk); /* Line 1280, Address: 0x102a4f4 */
  else msnc_low_set(pActwk); /* Line 1281, Address: 0x102a52c */
} /* Line 1282, Address: 0x102a538 */




static void msnc_b_atc(sprite_status* pActwk) { /* Line 1287, Address: 0x102a550 */
  short event_tbl_t[3] = /* Line 1288, Address: 0x102a55c */
  {
    0,
    10,
    150
  };
  void(*event_tbl_f[3])(sprite_status*) = /* Line 1294, Address: 0x102a580 */
  {
    &msnc_b_atc_atack,
    &msnc_b_atc_coli,
    &msnc_b_atc_kill
  };

  add_spd3(pActwk); /* Line 1301, Address: 0x102a5a4 */
  msnc_hight(pActwk); /* Line 1302, Address: 0x102a5b0 */
  event_timer(pActwk, event_tbl_t, event_tbl_f); /* Line 1303, Address: 0x102a5bc */
} /* Line 1304, Address: 0x102a5d0 */


static void msnc_b_atc_atack(sprite_status* pActwk) { /* Line 1307, Address: 0x102a5e0 */
  ((short*)pActwk)[26] = -8; /* Line 1308, Address: 0x102a5ec */
  ((short*)pActwk)[28] = 512; /* Line 1309, Address: 0x102a5f8 */
  make_ele(pActwk); /* Line 1310, Address: 0x102a604 */
  pActwk->mstno.b.h = 10; /* Line 1311, Address: 0x102a610 */

  soundset(208); /* Line 1313, Address: 0x102a61c */
} /* Line 1314, Address: 0x102a628 */


static void msnc_b_atc_coli(sprite_status* pActwk) { /* Line 1317, Address: 0x102a640 */
  pActwk->colino = 189; /* Line 1318, Address: 0x102a648 */
  pActwk->colicnt = 2; /* Line 1319, Address: 0x102a654 */
} /* Line 1320, Address: 0x102a660 */


static void msnc_b_atc_kill(sprite_status* pActwk) { /* Line 1323, Address: 0x102a670 */
  pActwk->colino = 0; /* Line 1324, Address: 0x102a67c */
  pActwk->colicnt = 0; /* Line 1325, Address: 0x102a684 */
  msnc_hi_set(pActwk); /* Line 1326, Address: 0x102a68c */
} /* Line 1327, Address: 0x102a698 */


void msnc_ele(sprite_status* pActwk) { /* Line 1330, Address: 0x102a6b0 */
  void(*act_tbl[2])(sprite_status*) = /* Line 1331, Address: 0x102a6bc */
  {
    &msnc_ele_ini,
    &msnc_ele_01
  };

  pMsnc = &actwk[((short*)pActwk)[25]]; /* Line 1337, Address: 0x102a6d8 */
  act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1338, Address: 0x102a708 */
} /* Line 1339, Address: 0x102a744 */


static void msnc_ele_ini(sprite_status* pActwk) { /* Line 1342, Address: 0x102a760 */
  pActwk->actflg = 4; /* Line 1343, Address: 0x102a76c */
  pActwk->sprpri = 5; /* Line 1344, Address: 0x102a778 */
  pActwk->sprhsize = 24; /* Line 1345, Address: 0x102a784 */
  pActwk->sprvsize = 24; /* Line 1346, Address: 0x102a790 */
  pActwk->sproffset = 892; /* Line 1347, Address: 0x102a79c */
  pActwk->patbase = msnc_ele_pat; /* Line 1348, Address: 0x102a7a8 */
  pActwk->r_no0 += 2; /* Line 1349, Address: 0x102a7b8 */

  msnc_ele_01(pActwk); /* Line 1351, Address: 0x102a7c8 */
} /* Line 1352, Address: 0x102a7d4 */


static void msnc_ele_01(sprite_status* pActwk) { /* Line 1355, Address: 0x102a7f0 */
  if (pMsnc->mstno.b.h != 10) /* Line 1356, Address: 0x102a7fc */
  {
    frameout(pActwk); /* Line 1358, Address: 0x102a81c */
    return; /* Line 1359, Address: 0x102a828 */
  }
  pActwk->xposi.w.h = pMsnc->xposi.w.h; /* Line 1361, Address: 0x102a830 */
  pActwk->yposi.w.h = pMsnc->yposi.w.h; /* Line 1362, Address: 0x102a844 */

  ++pActwk->actfree[1]; /* Line 1364, Address: 0x102a858 */
  if (pActwk->actfree[1] != 5) /* Line 1365, Address: 0x102a868 */
  {
    actionsub(pActwk); /* Line 1367, Address: 0x102a880 */
    return; /* Line 1368, Address: 0x102a88c */
  }
  pActwk->actfree[1] = 0; /* Line 1370, Address: 0x102a894 */
  ++pActwk->patno; /* Line 1371, Address: 0x102a89c */
  if (pActwk->patno == 2) /* Line 1372, Address: 0x102a8ac */
  {
    pActwk->patno = 0; /* Line 1374, Address: 0x102a8c4 */
  }
} /* Line 1376, Address: 0x102a8cc */




static void msnc_win(sprite_status* pActwk) { /* Line 1381, Address: 0x102a8e0 */
  void(*jmp[4])(sprite_status*) = /* Line 1382, Address: 0x102a8ec */
  {
    &msnc_win_ini,
    &msnc_win_wait,
    &msnc_win_timer,
    &msnc_win_chichi
  };

  loser_posiset(pPlayerwk); /* Line 1390, Address: 0x102a918 */

  jmp[pActwk->actfree[3]](pActwk); /* Line 1392, Address: 0x102a928 */
} /* Line 1393, Address: 0x102a94c */


static void msnc_win_ini(sprite_status* pActwk) { /* Line 1396, Address: 0x102a960 */
  pActwk->mstno.b.h = 11; /* Line 1397, Address: 0x102a968 */
  pActwk->xposi.w.h = 16016; /* Line 1398, Address: 0x102a974 */
  pActwk->yposi.w.h = 460; /* Line 1399, Address: 0x102a980 */
  ++pActwk->actfree[3]; /* Line 1400, Address: 0x102a98c */
} /* Line 1401, Address: 0x102a99c */


static void msnc_win_wait(sprite_status* pActwk) { /* Line 1404, Address: 0x102a9b0 */
  if (pPlayerwk->xposi.w.h >= 15824) /* Line 1405, Address: 0x102a9b8 */
  {
    ++pActwk->actfree[3]; /* Line 1407, Address: 0x102a9d8 */
    pActwk->actfree[1] = 30; /* Line 1408, Address: 0x102a9e8 */
  }
} /* Line 1410, Address: 0x102a9f4 */


static void msnc_win_timer(sprite_status* pActwk) { /* Line 1413, Address: 0x102aa00 */
  b_timer(pActwk); /* Line 1414, Address: 0x102aa0c */
} /* Line 1415, Address: 0x102aa18 */


static void msnc_win_chichi(sprite_status* pActwk) { /* Line 1418, Address: 0x102aa30 */
  pActwk->mstno.b.h = 12; /* Line 1419, Address: 0x102aa38 */
} /* Line 1420, Address: 0x102aa44 */




static void msnc_lose(sprite_status* pActwk) { /* Line 1425, Address: 0x102aa50 */
  if (pActwk->actfree[3] == 0) /* Line 1426, Address: 0x102aa5c */
  {
    scoreup(100); /* Line 1428, Address: 0x102aa70 */

    pActwk->actfree[3] = 1; /* Line 1430, Address: 0x102aa7c */
    pActwk->mstno.b.h = 13; /* Line 1431, Address: 0x102aa88 */
    pActwk->xspeed.w = 0; /* Line 1432, Address: 0x102aa94 */
    ((short*)pActwk)[26] = 0; /* Line 1433, Address: 0x102aa9c */
    pActwk->yspeed.w = -1280; /* Line 1434, Address: 0x102aaa4 */
    ((short*)pActwk)[27] = 40; /* Line 1435, Address: 0x102aab0 */
    make_bakuha(pActwk); /* Line 1436, Address: 0x102aabc */
  }
  if (((short*)pActwk)[23] == 240) /* Line 1438, Address: 0x102aac8 */
  {
    QuickReturn = 1; /* Line 1440, Address: 0x102aae4 */
    frameout(pActwk); /* Line 1441, Address: 0x102aaf0 */
    return; /* Line 1442, Address: 0x102aafc */
  }
  add_spd2(pActwk); /* Line 1444, Address: 0x102ab04 */
  ++((short*)pActwk)[23]; /* Line 1445, Address: 0x102ab10 */
} /* Line 1446, Address: 0x102ab20 */




void egg7(sprite_status* pActwk) { /* Line 1451, Address: 0x102ab30 */
  void(*tbl[5])(sprite_status*) = /* Line 1452, Address: 0x102ab3c */
  {
    &egg7_ini,
    &egg7_demo1,
    &egg7_demo2,
    &egg7_move,
    &egg7_goal
  };

  pPlayerwk = &actwk[0]; /* Line 1461, Address: 0x102ab68 */
  tbl[pActwk->r_no0 / 2](pActwk); /* Line 1462, Address: 0x102ab78 */
  if (QuickReturn) /* Line 1463, Address: 0x102abb4 */
  {
    QuickReturn = 0; /* Line 1465, Address: 0x102abc4 */
    return; /* Line 1466, Address: 0x102abcc */
  }
  egg7_hscr(pActwk); /* Line 1468, Address: 0x102abd4 */
  egg_beamchk(pActwk); /* Line 1469, Address: 0x102abe0 */
  patchg(pActwk, egg7_pchg); /* Line 1470, Address: 0x102abec */
  actionsub(pActwk); /* Line 1471, Address: 0x102ac00 */
} /* Line 1472, Address: 0x102ac0c */




static void egg7_ini(sprite_status* pActwk) { /* Line 1477, Address: 0x102ac20 */
  pActwk->actflg = 4; /* Line 1478, Address: 0x102ac2c */
  pActwk->sprpri = 1; /* Line 1479, Address: 0x102ac38 */
  pActwk->sprhsize = 36; /* Line 1480, Address: 0x102ac44 */
  pActwk->sprvsize = 36; /* Line 1481, Address: 0x102ac50 */
  pActwk->sproffset = 768; /* Line 1482, Address: 0x102ac5c */
  pActwk->patbase = egg7_pat; /* Line 1483, Address: 0x102ac68 */

  bossflag += 7; /* Line 1485, Address: 0x102ac78 */
  bossstart = 7; /* Line 1486, Address: 0x102ac8c */

  colorset2(6); /* Line 1488, Address: 0x102ac98 */
  pActwk->r_no0 = 2; /* Line 1489, Address: 0x102aca4 */
  make_jet(pActwk); /* Line 1490, Address: 0x102acb0 */
  pActwk->actfree[2] |= 8; /* Line 1491, Address: 0x102acbc */

  make_msnc(pActwk); /* Line 1493, Address: 0x102accc */
  make_beam(pActwk); /* Line 1494, Address: 0x102acd8 */
} /* Line 1495, Address: 0x102ace4 */




static void egg7_demo1(sprite_status* pActwk) { /* Line 1500, Address: 0x102ad00 */
  void(*demo1_jmp[6])(sprite_status*) = /* Line 1501, Address: 0x102ad0c */
  {
    &snc_wait,
    &r_l,
    &w_timer,
    &l_r,
    &w_timer,
    &r_l2
  };

  egg_hight(pActwk); /* Line 1511, Address: 0x102ad40 */

  demo1_jmp[pActwk->actfree[3]](pActwk); /* Line 1513, Address: 0x102ad4c */
} /* Line 1514, Address: 0x102ad70 */


static void snc_wait(sprite_status* pActwk) { /* Line 1517, Address: 0x102ad80 */
  short d0;

  pActwk->actfree[14] &= 240; /* Line 1520, Address: 0x102ad90 */
  ++pActwk->actfree[14]; /* Line 1521, Address: 0x102ada0 */
  if (pPlayerwk->xposi.w.h >= 3040) /* Line 1522, Address: 0x102adb0 */
  {
    pActwk->xspeed.w = -1536; /* Line 1524, Address: 0x102add0 */
    ((short*)pActwk)[26] = 0; /* Line 1525, Address: 0x102addc */
    ++pActwk->actfree[3]; /* Line 1526, Address: 0x102ade4 */
    pActwk->cddat |= 1; /* Line 1527, Address: 0x102adf4 */

    d0 = 2880; /* Line 1529, Address: 0x102ae04 */
    scralim_left = d0; /* Line 1530, Address: 0x102ae10 */
    scralim_n_left = d0; /* Line 1531, Address: 0x102ae18 */

    sub_sync(103); /* Line 1533, Address: 0x102ae20 */
    return; /* Line 1534, Address: 0x102ae2c */
  }

  d0 = pPlayerwk->xposi.w.h; /* Line 1537, Address: 0x102ae34 */
  d0 -= 160; /* Line 1538, Address: 0x102ae48 */

  if (d0 < scralim_left) return; /* Line 1540, Address: 0x102ae54 */
  if (d0 <= 2880) /* Line 1541, Address: 0x102ae78 */
  {
    scralim_left = d0; /* Line 1543, Address: 0x102ae8c */
    scralim_n_left = d0; /* Line 1544, Address: 0x102ae94 */
  }
} /* Line 1546, Address: 0x102ae9c */


static void r_l(sprite_status* pActwk) { /* Line 1549, Address: 0x102aeb0 */
  short d0;

  add_spd2(pActwk); /* Line 1552, Address: 0x102aec0 */
  d0 = 2840; /* Line 1553, Address: 0x102aecc */
  if (d0 < pActwk->xposi.w.h) return; /* Line 1554, Address: 0x102aed8 */
  pActwk->xposi.w.h = d0; /* Line 1555, Address: 0x102aefc */
  pActwk->xspeed.w = 1536; /* Line 1556, Address: 0x102af04 */
  ((short*)pActwk)[26] = 0; /* Line 1557, Address: 0x102af10 */
  ++pActwk->actfree[3]; /* Line 1558, Address: 0x102af18 */
  pActwk->cddat &= 254; /* Line 1559, Address: 0x102af28 */
  ((short*)pActwk)[23] = 120; /* Line 1560, Address: 0x102af38 */
} /* Line 1561, Address: 0x102af44 */


static void l_r(sprite_status* pActwk) { /* Line 1564, Address: 0x102af60 */
  short d0;

  add_spd2(pActwk); /* Line 1567, Address: 0x102af70 */
  d0 = 3240; /* Line 1568, Address: 0x102af7c */
  if (d0 > pActwk->xposi.w.h) return; /* Line 1569, Address: 0x102af88 */
  pActwk->xposi.w.h = d0; /* Line 1570, Address: 0x102afac */
  pActwk->xspeed.w = -1536; /* Line 1571, Address: 0x102afb4 */
  ((short*)pActwk)[26] = 0; /* Line 1572, Address: 0x102afc0 */
  pActwk->cddat |= 1; /* Line 1573, Address: 0x102afc8 */
  ++pActwk->actfree[3]; /* Line 1574, Address: 0x102afd8 */
  ((short*)pActwk)[23] = 120; /* Line 1575, Address: 0x102afe8 */
} /* Line 1576, Address: 0x102aff4 */


static void r_l2(sprite_status* pActwk) { /* Line 1579, Address: 0x102b010 */
  short d0;

  add_spd2(pActwk); /* Line 1582, Address: 0x102b020 */
  d0 = 3104; /* Line 1583, Address: 0x102b02c */
  if (d0 < pActwk->xposi.w.h) return; /* Line 1584, Address: 0x102b038 */
  pActwk->xposi.w.h = d0; /* Line 1585, Address: 0x102b05c */
  pActwk->xspeed.w = 0; /* Line 1586, Address: 0x102b064 */
  ((short*)pActwk)[26] = 0; /* Line 1587, Address: 0x102b06c */
  pActwk->actfree[3] = 0; /* Line 1588, Address: 0x102b074 */
  ((short*)pActwk)[23] = 0; /* Line 1589, Address: 0x102b07c */
  pActwk->actfree[2] &= 247; /* Line 1590, Address: 0x102b084 */
  pActwk->r_no0 = 4; /* Line 1591, Address: 0x102b094 */
} /* Line 1592, Address: 0x102b0a0 */




static void egg7_demo2(sprite_status* pActwk) { /* Line 1597, Address: 0x102b0c0 */
  short event_tbl_t[12] = /* Line 1598, Address: 0x102b0d0 */
  {
    120,
    180,
    184,
    185,
    190,
    220,
    224,
    230,
    260,
    264,
    270,
    420
  };




  void(*event_tbl_f[12])(sprite_status*) = /* Line 1617, Address: 0x102b104 */
  {
    &msnc_turn,
    &beam_on2,
    &beam_on,
    &move_start,
    &beam_off,
    &beam_on2,
    &beam_on,
    &beam_off,
    &beam_on2,
    &beam_on,
    &beam_off,
    &beam_next
  };
  short d0;





  add_spd2(pActwk); /* Line 1638, Address: 0x102b138 */
  d0 = 2816; /* Line 1639, Address: 0x102b144 */
  if (d0 >= pActwk->xposi.w.h) /* Line 1640, Address: 0x102b150 */
  {
    pActwk->xposi.w.h = d0; /* Line 1642, Address: 0x102b174 */
  }
  egg_hight(pActwk); /* Line 1644, Address: 0x102b17c */

  event_timer(pActwk, event_tbl_t, event_tbl_f); /* Line 1646, Address: 0x102b188 */
} /* Line 1647, Address: 0x102b19c */


static void msnc_turn(sprite_status* pActwk) { /* Line 1650, Address: 0x102b1b0 */
  sprite_status* a2;

  a2 = &actwk[((short*)pActwk)[25]]; /* Line 1653, Address: 0x102b1bc */
  a2->r_no0 = 4; /* Line 1654, Address: 0x102b1e4 */
  ((short*)a2)[23] = 0; /* Line 1655, Address: 0x102b1ec */
  a2->actfree[3] = 0; /* Line 1656, Address: 0x102b1f0 */
} /* Line 1657, Address: 0x102b1f4 */


static void beam_on(sprite_status* pActwk) { /* Line 1660, Address: 0x102b210 */
  pActwk->actfree[2] |= 64; /* Line 1661, Address: 0x102b218 */
  pActwk->actfree[2] |= 32; /* Line 1662, Address: 0x102b228 */
} /* Line 1663, Address: 0x102b238 */


static void beam_on2(sprite_status* pActwk) { /* Line 1666, Address: 0x102b250 */
  pActwk->actfree[2] |= 64; /* Line 1667, Address: 0x102b258 */
  pActwk->actfree[2] &= 223; /* Line 1668, Address: 0x102b268 */
} /* Line 1669, Address: 0x102b278 */


static void beam_off(sprite_status* pActwk) { /* Line 1672, Address: 0x102b290 */
  pActwk->actfree[2] &= 191; /* Line 1673, Address: 0x102b298 */
  pActwk->actfree[2] &= 223; /* Line 1674, Address: 0x102b2a8 */
} /* Line 1675, Address: 0x102b2b8 */


static void move_start(sprite_status* pActwk) { /* Line 1678, Address: 0x102b2d0 */
  pActwk->actfree[2] |= 8; /* Line 1679, Address: 0x102b2d8 */
  pActwk->xspeed.w = -512; /* Line 1680, Address: 0x102b2e8 */
  ((short*)pActwk)[26] = 0; /* Line 1681, Address: 0x102b2f4 */
} /* Line 1682, Address: 0x102b2fc */


static void beam_next(sprite_status* pActwk) { /* Line 1685, Address: 0x102b310 */
  beam_on2(pActwk); /* Line 1686, Address: 0x102b31c */

  pActwk->r_no0 = 6; /* Line 1688, Address: 0x102b328 */
  pActwk->actfree[2] |= 16; /* Line 1689, Address: 0x102b334 */

  pActwk->xspeed.w = 512; /* Line 1691, Address: 0x102b344 */
  ((short*)pActwk)[28] = 512; /* Line 1692, Address: 0x102b350 */
  ((short*)pActwk)[26] = 2; /* Line 1693, Address: 0x102b35c */
  pActwk->xspeed.w = 0; /* Line 1694, Address: 0x102b368 */
  ((short*)pActwk)[27] = 0; /* Line 1695, Address: 0x102b370 */

  pActwk->cddat &= 254; /* Line 1697, Address: 0x102b378 */
  pActwk->actfree[3] = 0; /* Line 1698, Address: 0x102b388 */
  ((short*)pActwk)[23] = 0; /* Line 1699, Address: 0x102b390 */
} /* Line 1700, Address: 0x102b398 */




static void egg7_move(sprite_status* pActwk) { /* Line 1705, Address: 0x102b3b0 */
  short d0;

  d0 = 15952; /* Line 1708, Address: 0x102b3c0 */
  if (d0 > pActwk->xposi.w.h) /* Line 1709, Address: 0x102b3cc */
  {
    add_spd3(pActwk); /* Line 1711, Address: 0x102b3f0 */
    egg7_spdset(pActwk); /* Line 1712, Address: 0x102b3fc */
    egg_hight(pActwk); /* Line 1713, Address: 0x102b408 */
  } /* Line 1714, Address: 0x102b414 */
  else
  {
    pActwk->xposi.w.h = d0; /* Line 1717, Address: 0x102b41c */
    pActwk->r_no0 = 8; /* Line 1718, Address: 0x102b424 */
    pActwk->actfree[3] = 0; /* Line 1719, Address: 0x102b430 */
    pActwk->xspeed.w = 0; /* Line 1720, Address: 0x102b438 */
    pActwk->yspeed.w = 0; /* Line 1721, Address: 0x102b440 */
  }
} /* Line 1723, Address: 0x102b448 */




static void egg7_goal(sprite_status* pActwk) { /* Line 1728, Address: 0x102b460 */
  void(*jmp[10])(sprite_status*) = /* Line 1729, Address: 0x102b46c */
  {
    &egg7_goal_ini,
    &egg7_goal_msnc_win,
    &w_timer,
    &egg7_goal0,
    &w_timer,
    &egg7_goal1,
    &w_timer,
    &egg7_goal2,
    &w_timer,
    &egg7_goal3
  };

  jmp[pActwk->actfree[3]](pActwk); /* Line 1743, Address: 0x102b4a0 */
} /* Line 1744, Address: 0x102b4c4 */


static void egg7_goal_ini(sprite_status* pActwk) { /* Line 1747, Address: 0x102b4e0 */
  unsigned char d0;

  d0 = pActwk->actfree[15]; /* Line 1750, Address: 0x102b4f0 */
  d0 &= 15; /* Line 1751, Address: 0x102b4fc */
  if (d0 == 1) /* Line 1752, Address: 0x102b504 */
  {
    egg7_goal_snc_win(pActwk); /* Line 1754, Address: 0x102b514 */
    return; /* Line 1755, Address: 0x102b520 */
  }
  if (d0 == 2) /* Line 1757, Address: 0x102b528 */
  {
    egg7_goal_msnc_win(pActwk); /* Line 1759, Address: 0x102b538 */
  }

} /* Line 1762, Address: 0x102b544 */


static void egg7_goal_msnc_win(sprite_status* pActwk) { /* Line 1765, Address: 0x102b560 */
  pActwk->actfree[3] = 1; /* Line 1766, Address: 0x102b568 */
} /* Line 1767, Address: 0x102b574 */


static void egg7_goal_snc_win(sprite_status* pActwk) { /* Line 1770, Address: 0x102b580 */
  pActwk->actfree[2] &= 223; /* Line 1771, Address: 0x102b588 */
  pActwk->actfree[2] &= 239; /* Line 1772, Address: 0x102b598 */
  pActwk->actfree[14] &= 15; /* Line 1773, Address: 0x102b5a8 */

  pActwk->actfree[3] = 2; /* Line 1775, Address: 0x102b5b8 */
  ((short*)pActwk)[23] = 30; /* Line 1776, Address: 0x102b5c4 */
} /* Line 1777, Address: 0x102b5d0 */


static void egg7_goal0(sprite_status* pActwk) { /* Line 1780, Address: 0x102b5e0 */
  short d0;

  ++((short*)pActwk)[23]; /* Line 1783, Address: 0x102b5f0 */
  if (((short*)pActwk)[23] < 120) /* Line 1784, Address: 0x102b600 */
  {
    d0 = ((short*)pActwk)[23]; /* Line 1786, Address: 0x102b61c */
    d0 = (unsigned short)d0 % 20; /* Line 1787, Address: 0x102b62c */
    if (d0 == 0) /* Line 1788, Address: 0x102b650 */
    {
      pActwk->actfree[2] ^= 64; /* Line 1790, Address: 0x102b660 */
    }
  } /* Line 1792, Address: 0x102b670 */
  else
  {
    pActwk->actfree[2] &= 191; /* Line 1795, Address: 0x102b678 */
    ++pActwk->actfree[3]; /* Line 1796, Address: 0x102b688 */
    ((short*)pActwk)[23] = 30; /* Line 1797, Address: 0x102b698 */
    pActwk->xspeed.w = 0; /* Line 1798, Address: 0x102b6a4 */
    pActwk->yspeed.w = 512; /* Line 1799, Address: 0x102b6ac */

    divdevset(); /* Line 1801, Address: 0x102b6b8 */
  }
} /* Line 1803, Address: 0x102b6c0 */


static void egg7_goal1(sprite_status* pActwk) { /* Line 1806, Address: 0x102b6e0 */
  add_spd(pActwk); /* Line 1807, Address: 0x102b6ec */
  if (pActwk->yposi.w.h >= 400) /* Line 1808, Address: 0x102b6f8 */
  {
    pActwk->xspeed.w = 1536; /* Line 1810, Address: 0x102b714 */
    pActwk->yspeed.w = 0; /* Line 1811, Address: 0x102b720 */
    ++pActwk->actfree[3]; /* Line 1812, Address: 0x102b728 */
    ((short*)pActwk)[23] = 60; /* Line 1813, Address: 0x102b738 */
  }
} /* Line 1815, Address: 0x102b744 */


static void egg7_goal2(sprite_status* pActwk) { /* Line 1818, Address: 0x102b760 */
  add_spd(pActwk); /* Line 1819, Address: 0x102b76c */
  if (pActwk->xposi.w.h >= 16224) /* Line 1820, Address: 0x102b778 */
  {
    ++pActwk->actfree[3]; /* Line 1822, Address: 0x102b794 */
    ((short*)pActwk)[23] = 60; /* Line 1823, Address: 0x102b7a4 */
  }
} /* Line 1825, Address: 0x102b7b0 */


static void egg7_goal3(sprite_status* pActwk) { /* Line 1828, Address: 0x102b7c0 */
  short d0;

  d0 = 32; /* Line 1831, Address: 0x102b7d0 */
  if (generate_flag) /* Line 1832, Address: 0x102b7dc */
  {
    d0 = 31; /* Line 1834, Address: 0x102b7ec */
  }
  sub_sync(d0); /* Line 1836, Address: 0x102b7f8 */

  pActwk->actfree[14] = 3; /* Line 1838, Address: 0x102b804 */
  egg7_hscr(pActwk); /* Line 1839, Address: 0x102b810 */

  genecolor(); /* Line 1841, Address: 0x102b81c */
  emie7clrset(); /* Line 1842, Address: 0x102b824 */

  QuickReturn = 1; /* Line 1844, Address: 0x102b82c */
  frameout(pActwk); /* Line 1845, Address: 0x102b838 */
} /* Line 1846, Address: 0x102b844 */


static void emie7clrset(void) { /* Line 1849, Address: 0x102b860 */
  short i;
  PALETTEENTRY *a3, *a4, *a5;

  PALETTEENTRY emie7_clr[16] = /* Line 1853, Address: 0x102b874 */
  {
    {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 128,  32,  96, 1 }, { 160,  64, 128, 1 },
    { 224,  96, 224, 1 }, { 224, 160, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
    { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 192,  96,   0, 1 },
    {  32, 192,   0, 1 }, {   0, 128,   0, 1 }, {  96,   0, 128, 1 }, { 224,   0,   0, 1 }
  };

  a3 = emie7_clr; /* Line 1861, Address: 0x102b8a8 */
  a4 = &lpcolorwk[16]; /* Line 1862, Address: 0x102b8ac */
  a5 = &lpcolorwk3[16]; /* Line 1863, Address: 0x102b8b8 */
  for (i = 0; i < 16; ++i) /* Line 1864, Address: 0x102b8c4 */
  {
    *a5 = *a4 = *a3; /* Line 1866, Address: 0x102b8d0 */
    ++a3; /* Line 1867, Address: 0x102b910 */
    ++a4; /* Line 1868, Address: 0x102b914 */
    ++a5; /* Line 1869, Address: 0x102b918 */
  } /* Line 1870, Address: 0x102b91c */
} /* Line 1871, Address: 0x102b93c */


static void egg7_spdset(sprite_status* pActwk) { /* Line 1874, Address: 0x102b960 */
  short d0, d1;

  d0 = (unsigned short)pActwk->sprhsize; /* Line 1877, Address: 0x102b974 */
  d1 = pActwk->xposi.w.h; /* Line 1878, Address: 0x102b990 */
  d1 -= scra_h_posit.w.h; /* Line 1879, Address: 0x102b9a0 */
  d1 += d0; /* Line 1880, Address: 0x102b9b4 */
  if (d1 < 0) /* Line 1881, Address: 0x102b9c0 */
  {

    ++((short*)pActwk)[32]; /* Line 1884, Address: 0x102b9d0 */
    egg7_maxspdset(pActwk, d1); /* Line 1885, Address: 0x102b9e0 */
    if (((short*)pActwk)[31]) /* Line 1886, Address: 0x102b9f0 */
    {
      --((short*)pActwk)[31]; /* Line 1888, Address: 0x102ba00 */
      return; /* Line 1889, Address: 0x102ba10 */
    }

    pActwk->actfree[2] &= 251; /* Line 1892, Address: 0x102ba18 */

  } /* Line 1894, Address: 0x102ba28 */
  else
  {
    ((short*)pActwk)[32] = 0; /* Line 1897, Address: 0x102ba30 */

    egg7_maxspdset(pActwk, d1); /* Line 1899, Address: 0x102ba38 */

    if (!(pActwk->actfree[2] & 4)) /* Line 1901, Address: 0x102ba48 */
    {
      pActwk->actfree[2] |= 4; /* Line 1903, Address: 0x102ba60 */
      ((short*)pActwk)[31] = 240; /* Line 1904, Address: 0x102ba70 */


      d1 = 256; /* Line 1907, Address: 0x102ba7c */
      d0 = pPlayerwk->xspeed.w; /* Line 1908, Address: 0x102ba88 */
      if (d0 < d1) /* Line 1909, Address: 0x102ba9c */
      {
        d0 = d1; /* Line 1911, Address: 0x102bab8 */
      }
      pActwk->xspeed.w = d0; /* Line 1913, Address: 0x102bac0 */
    } /* Line 1914, Address: 0x102bac8 */
    else
    {
      pActwk->actfree[2] |= 4; /* Line 1917, Address: 0x102bad0 */
    }
  }
} /* Line 1920, Address: 0x102bae0 */


static void egg7_maxspdset(sprite_status* pActwk, short d1) { /* Line 1923, Address: 0x102bb00 */
  short d0;

  short spd_tbl[8] = /* Line 1926, Address: 0x102bb10 */
  {
     512, 2,
     768, 2,
    1088, 8,
    1536, 4
  };

  if (d1 > -160) /* Line 1934, Address: 0x102bb44 */
  {
    if (pPlayerwk->xposi.w.h >= 12544) /* Line 1936, Address: 0x102bb5c */
    {
      d0 = 8; /* Line 1938, Address: 0x102bb7c */
    } /* Line 1939, Address: 0x102bb88 */
    else if (pPlayerwk->xposi.w.h >= 3520) /* Line 1940, Address: 0x102bb90 */
    {
      d0 = 4; /* Line 1942, Address: 0x102bbb0 */
    } /* Line 1943, Address: 0x102bbbc */
    else
    {
      d0 = 0; /* Line 1946, Address: 0x102bbc4 */
    }
  } /* Line 1948, Address: 0x102bbc8 */
  else
  {
    d0 = 12; /* Line 1951, Address: 0x102bbd0 */
  }

  ((short*)pActwk)[28] = spd_tbl[d0 / 2]; /* Line 1954, Address: 0x102bbdc */
  ((short*)pActwk)[26] = spd_tbl[d0 / 2 + 1]; /* Line 1955, Address: 0x102bc10 */
} /* Line 1956, Address: 0x102bc48 */




static void egg_beamchk(sprite_status* pActwk) { /* Line 1961, Address: 0x102bc60 */
  sprite_status* a0;
  short d0;

  if (!(pActwk->actfree[2] & 16)) return; /* Line 1965, Address: 0x102bc74 */
  if (pPlayerwk->actno == 0) return; /* Line 1966, Address: 0x102bc8c */
  if (pPlayerwk->r_no0 >= 6) return; /* Line 1967, Address: 0x102bca4 */
  d0 = pPlayerwk->xposi.w.h; /* Line 1968, Address: 0x102bcc0 */
  d0 -= pActwk->xposi.w.h; /* Line 1969, Address: 0x102bcd4 */
  if (d0 > 16) return; /* Line 1970, Address: 0x102bce8 */
  a0 = pPlayerwk; /* Line 1971, Address: 0x102bcfc */
  a0->cddat |= 128; /* Line 1972, Address: 0x102bd04 */
  playdieset(a0); /* Line 1973, Address: 0x102bd10 */
} /* Line 1974, Address: 0x102bd1c */




static void egg7_hscr(sprite_status* pActwk) { /* Line 1979, Address: 0x102bd40 */
  void(*rlim_jmpd0[4])(void) = /* Line 1980, Address: 0x102bd50 */
  {
    &egg7_hscr_pat0,
    &egg7_hscr_pat1,
    &egg7_hscr_pat2,
    &egg7_hscr_pat3
  };
  short d0;

  if (pActwk->actfree[14] & 128) /* Line 1989, Address: 0x102bd7c */
  {
    d0 = pActwk->xposi.w.h; /* Line 1991, Address: 0x102bd94 */
    d0 -= 8; /* Line 1992, Address: 0x102bda4 */
    if (d0 > 15776) /* Line 1993, Address: 0x102bdb0 */
    {
      d0 = 15776; /* Line 1995, Address: 0x102bdc4 */
    }
    scralim_left = d0; /* Line 1997, Address: 0x102bdd0 */
    scralim_n_left = d0; /* Line 1998, Address: 0x102bdd8 */

    d0 = pPlayerwk->xposi.w.h; /* Line 2000, Address: 0x102bde0 */
    d0 -= scralim_left; /* Line 2001, Address: 0x102bdf4 */
    if (d0 < 160) /* Line 2002, Address: 0x102be08 */
    {
      d0 -= 160; /* Line 2004, Address: 0x102be1c */
      d0 += 160; /* Line 2005, Address: 0x102be28 */
      d0 &= -2; /* Line 2006, Address: 0x102be34 */
      scra_hline = d0; /* Line 2007, Address: 0x102be44 */
    }
  }
  rlim_jmpd0[pActwk->actfree[14] & 15](); /* Line 2010, Address: 0x102be4c */
} /* Line 2011, Address: 0x102be70 */




static void egg7_hscr_pat0(void) {} /* Line 2016, Address: 0x102be90 */


static void egg7_hscr_pat1(void) { /* Line 2019, Address: 0x102bea0 */
  short d0;

  d0 = 2880; /* Line 2022, Address: 0x102bea8 */
  scralim_right = d0; /* Line 2023, Address: 0x102beb4 */
  scralim_n_right = d0; /* Line 2024, Address: 0x102bebc */
} /* Line 2025, Address: 0x102bec4 */


static void egg7_hscr_pat2(void) { /* Line 2028, Address: 0x102bee0 */
  short d0;

  d0 = 15776; /* Line 2031, Address: 0x102bee8 */
  scralim_right = d0; /* Line 2032, Address: 0x102bef4 */
  scralim_n_right = d0; /* Line 2033, Address: 0x102befc */
} /* Line 2034, Address: 0x102bf04 */


static void egg7_hscr_pat3(void) {
  scralim_right = scr_dir_tbl[2]; /* Line 2038, Address: 0x102bf20 */
  scralim_n_right = scr_dir_tbl[2]; /* Line 2039, Address: 0x102bf30 */
} /* Line 2040, Address: 0x102bf40 */




static void egg_hight(sprite_status* pActwk) { /* Line 2045, Address: 0x102bf50 */
  pActwk->yposi.w.h += 128; /* Line 2046, Address: 0x102bf5c */
  hight_set(pActwk); /* Line 2047, Address: 0x102bf6c */
  pActwk->yposi.w.h -= 128; /* Line 2048, Address: 0x102bf78 */
} /* Line 2049, Address: 0x102bf88 */




static void msnc_hight(sprite_status* pActwk) { /* Line 2054, Address: 0x102bfa0 */
  pActwk + 1; /* Line 2055, Address: 0x102bfac */
  hight_set2(pActwk); /* Line 2056, Address: 0x102bfb0 */
  pActwk + 1; /* Line 2057, Address: 0x102bfbc */
} /* Line 2058, Address: 0x102bfc0 */




static void hight_set2(sprite_status* pActwk) { /* Line 2063, Address: 0x102bfd0 */
  int ld1;
  short d1;

  d1 = emycol_d(pActwk); /* Line 2067, Address: 0x102bfe0 */
  if (d1 <= 8) goto label1; /* Line 2068, Address: 0x102bff0 */
  if (hight_set_retry(pActwk, &d1) != 0) /* Line 2069, Address: 0x102c008 */
  {
    pActwk->userflag.w += 48; /* Line 2071, Address: 0x102c028 */
    ld1 = pActwk->userflag.w; /* Line 2072, Address: 0x102c038 */
    ld1 <<= 8; /* Line 2073, Address: 0x102c048 */
    pActwk->yposi.l += ld1; /* Line 2074, Address: 0x102c04c */
    return; /* Line 2075, Address: 0x102c05c */
  }
label1:
  pActwk->userflag.w = 0; /* Line 2078, Address: 0x102c064 */
  pActwk->yposi.w.h += d1; /* Line 2079, Address: 0x102c06c */
} /* Line 2080, Address: 0x102c080 */




static void hight_set(sprite_status* pActwk) { /* Line 2085, Address: 0x102c0a0 */
  short d1;
  short bne;

  d1 = emycol_d(pActwk); /* Line 2089, Address: 0x102c0b0 */
  if (d1 <= 8) goto label1; /* Line 2090, Address: 0x102c0c0 */
  bne = hight_set_retry(pActwk, &d1); /* Line 2091, Address: 0x102c0d8 */
  goto label2; /* Line 2092, Address: 0x102c0f0 */

label1:
  if (d1 >= -8) goto label2; /* Line 2095, Address: 0x102c0f8 */
  bne = hight_set_retry(pActwk, &d1); /* Line 2096, Address: 0x102c110 */

label2:
  pActwk->yposi.w.h += d1; /* Line 2099, Address: 0x102c128 */
} /* Line 2100, Address: 0x102c13c */




static short hight_set_retry(sprite_status* pActwk, short* d1) { /* Line 2105, Address: 0x102c150 */
  short egg_move_tbl[43] = /* Line 2106, Address: 0x102c16c */
  {
     3120, 0,   0,
     5648, 0,  -2,
     6232, 0, -16,
     8736, 0,  -2,
     9360, 0, -16,
    10272, 0,  -2,
    10873, 0, -16,
    11360, 0, -16,
    11872, 0, -16,
    12224, 0,   0,
    12320, 0,  -2,
    12336, 0,  -2,
    15920, 0,   0,
    16304, 0,   0,
    -1
  };
  short d2;
  short d3;
  short d4;
  short* a2;

  a2 = egg_move_tbl; /* Line 2129, Address: 0x102c198 */
  do
  {
    d2 = *a2++; /* Line 2132, Address: 0x102c19c */
    if (d2 < 0) return -1; /* Line 2133, Address: 0x102c1b0 */
    d3 = *a2++; /* Line 2134, Address: 0x102c1cc */
    d4 = *a2++; /* Line 2135, Address: 0x102c1e0 */

    if (d2 <= pActwk->xposi.w.h) /* Line 2137, Address: 0x102c1f4 */
    {
      d2 -= pActwk->xposi.w.h; /* Line 2139, Address: 0x102c218 */
      d2 *= -1; /* Line 2140, Address: 0x102c22c */
    } /* Line 2141, Address: 0x102c238 */
    else
    {
      d2 -= pActwk->xposi.w.h; /* Line 2144, Address: 0x102c240 */
    }
  } while (d2 > 64); /* Line 2146, Address: 0x102c254 */


  pActwk->xposi.w.h += d3; /* Line 2149, Address: 0x102c268 */
  pActwk->yposi.w.h += d4; /* Line 2150, Address: 0x102c278 */
  *d1 = 0; /* Line 2151, Address: 0x102c288 */
  return 0; /* Line 2152, Address: 0x102c290 */
} /* Line 2153, Address: 0x102c294 */




void egg7beam(sprite_status* pActwk) { /* Line 2158, Address: 0x102c2b0 */
  void(*tbl[4])(sprite_status*, sprite_status*) = /* Line 2159, Address: 0x102c2c0 */
  {
    &egg7beam_ini,
    &egg7beam_01,
    &egg7beam_kemuri1,
    &egg7beam_kemuri2
  };
  sprite_status* a2;

  a2 = &actwk[((short*)pActwk)[25]]; /* Line 2168, Address: 0x102c2ec */
  if (a2->actno == 0) /* Line 2169, Address: 0x102c314 */
  {
    frameout(pActwk); /* Line 2171, Address: 0x102c324 */
    return; /* Line 2172, Address: 0x102c330 */
  }
  tbl[pActwk->r_no0 / 2](pActwk, a2); /* Line 2174, Address: 0x102c338 */
} /* Line 2175, Address: 0x102c378 */




static void egg7beam_ini(sprite_status* pActwk, sprite_status* a2) { /* Line 2180, Address: 0x102c390 */
  if (pActwk->userflag.b.h == 0) /* Line 2181, Address: 0x102c398 */
  {
    pActwk->actflg = 4; /* Line 2183, Address: 0x102c3b0 */
    pActwk->sprpri = 2; /* Line 2184, Address: 0x102c3bc */
    pActwk->sprhsize = 8; /* Line 2185, Address: 0x102c3c8 */
    pActwk->sprvsize = 16; /* Line 2186, Address: 0x102c3d4 */
    pActwk->sproffset = 8960; /* Line 2187, Address: 0x102c3e0 */
    pActwk->patbase = egg7beam_pat; /* Line 2188, Address: 0x102c3ec */
    pActwk->r_no0 = 2; /* Line 2189, Address: 0x102c3fc */
  } /* Line 2190, Address: 0x102c408 */
  else
  {
    pActwk->actflg = 4; /* Line 2193, Address: 0x102c410 */
    pActwk->sprpri = 1; /* Line 2194, Address: 0x102c41c */
    pActwk->sprhsize = 16; /* Line 2195, Address: 0x102c428 */
    pActwk->sprvsize = 16; /* Line 2196, Address: 0x102c434 */
    pActwk->sproffset = 1664; /* Line 2197, Address: 0x102c440 */
    pActwk->patbase = bakupat; /* Line 2198, Address: 0x102c44c */

    if (pActwk->userflag.b.h != 2) /* Line 2200, Address: 0x102c45c */
    {
      pActwk->r_no0 = 4; /* Line 2202, Address: 0x102c478 */

      pActwk->actfree[1] = 15; /* Line 2204, Address: 0x102c484 */
    } /* Line 2205, Address: 0x102c490 */
    else
    {
      pActwk->r_no0 = 6; /* Line 2208, Address: 0x102c498 */

      pActwk->actfree[1] = 30; /* Line 2210, Address: 0x102c4a4 */
    }
  }
} /* Line 2213, Address: 0x102c4b0 */




static void egg7beam_01(sprite_status* pActwk, sprite_status* a2) { /* Line 2218, Address: 0x102c4c0 */
  pActwk->colino = 0; /* Line 2219, Address: 0x102c4d0 */
  pActwk->colicnt = 0; /* Line 2220, Address: 0x102c4d8 */
  if (a2->actfree[2] & 32) /* Line 2221, Address: 0x102c4e0 */
  {
    pActwk->colino = 190; /* Line 2223, Address: 0x102c4f8 */
    pActwk->colicnt = 2; /* Line 2224, Address: 0x102c504 */
  }
  if (beam_posi(pActwk, a2)) /* Line 2226, Address: 0x102c510 */
  {
    if (pActwk->userflag.b.l) /* Line 2228, Address: 0x102c528 */
    {
      if (pActwk->actfree[1] <= 0) /* Line 2230, Address: 0x102c538 */
      {
        --pActwk->actfree[1]; /* Line 2232, Address: 0x102c54c */
        make_kemuri(pActwk); /* Line 2233, Address: 0x102c55c */
        pActwk->actfree[1] = 10; /* Line 2234, Address: 0x102c568 */
      } /* Line 2235, Address: 0x102c574 */
      else
      {
        --pActwk->actfree[1]; /* Line 2238, Address: 0x102c57c */
      }

      if (pActwk->actfree[0] <= 0) /* Line 2241, Address: 0x102c58c */
      {
        --pActwk->actfree[0]; /* Line 2243, Address: 0x102c5a0 */
        make_hahen(pActwk); /* Line 2244, Address: 0x102c5b0 */
        pActwk->actfree[0] = 9; /* Line 2245, Address: 0x102c5bc */
      } /* Line 2246, Address: 0x102c5c8 */
      else
      {
        --pActwk->actfree[0]; /* Line 2249, Address: 0x102c5d0 */
      }
    }


    patchg(pActwk, egg7beam_pchg); /* Line 2254, Address: 0x102c5e0 */
    actionsub(pActwk); /* Line 2255, Address: 0x102c5f4 */
  } /* Line 2256, Address: 0x102c600 */
  else
  {
    ((short*)pActwk)[23] = 0; /* Line 2259, Address: 0x102c608 */
  }
} /* Line 2261, Address: 0x102c610 */


static short beam_posi(sprite_status* pActwk, sprite_status* a2) { /* Line 2264, Address: 0x102c620 */
  short d0, d1;

  pActwk->xposi.w.h = a2->xposi.w.h; /* Line 2267, Address: 0x102c634 */
  pActwk->yposi.w.h = a2->yposi.w.h; /* Line 2268, Address: 0x102c644 */
  d0 = ((short*)pActwk)[29]; /* Line 2269, Address: 0x102c654 */
  d1 = ((short*)pActwk)[30]; /* Line 2270, Address: 0x102c664 */
  pActwk->yposi.w.h += d1; /* Line 2271, Address: 0x102c674 */

  if (!(a2->cddat & 1)) /* Line 2273, Address: 0x102c684 */
  {
    pActwk->cddat &= 254; /* Line 2275, Address: 0x102c69c */
    pActwk->xposi.w.h += d0; /* Line 2276, Address: 0x102c6ac */
  } /* Line 2277, Address: 0x102c6bc */
  else
  {
    pActwk->cddat |= 1; /* Line 2280, Address: 0x102c6c4 */
    pActwk->xposi.w.h -= d0; /* Line 2281, Address: 0x102c6d4 */
  }

  pActwk->actfree[2] &= 223; /* Line 2284, Address: 0x102c6e4 */

  if (a2->actfree[2] & 32) /* Line 2286, Address: 0x102c6f4 */
  {
    pActwk->actfree[2] |= 32; /* Line 2288, Address: 0x102c70c */
  }
  if (a2->actfree[2] & 64) /* Line 2290, Address: 0x102c71c */
  {
    pActwk->actfree[2] |= 64; /* Line 2292, Address: 0x102c734 */
    return -1; /* Line 2293, Address: 0x102c744 */
  }


  pActwk->actfree[2] &= 191; /* Line 2297, Address: 0x102c750 */
  return 0; /* Line 2298, Address: 0x102c760 */

} /* Line 2300, Address: 0x102c764 */




static void egg7beam_kemuri1(sprite_status* pActwk, sprite_status* a2) { /* Line 2305, Address: 0x102c780 */
  beam_posi(pActwk, a2); /* Line 2306, Address: 0x102c790 */

  b_timer(pActwk); /* Line 2308, Address: 0x102c7a0 */
  if (pActwk->actfree[3]) /* Line 2309, Address: 0x102c7ac */
  {
    pActwk->actfree[3] = 0; /* Line 2311, Address: 0x102c7bc */
    pActwk->r_no0 = 6; /* Line 2312, Address: 0x102c7c4 */

    pActwk->actfree[1] = 15; /* Line 2314, Address: 0x102c7d0 */
  }
  kemuri_disp(pActwk); /* Line 2316, Address: 0x102c7dc */
} /* Line 2317, Address: 0x102c7e8 */




static void egg7beam_kemuri2(sprite_status* pActwk, sprite_status* a2) { /* Line 2322, Address: 0x102c800 */
  b_timer(pActwk); /* Line 2323, Address: 0x102c80c */
  if (pActwk->actfree[3] == 0) kemuri_disp(pActwk); /* Line 2324, Address: 0x102c818 */
  else frameout(pActwk); /* Line 2325, Address: 0x102c840 */
} /* Line 2326, Address: 0x102c84c */


static void kemuri_disp(sprite_status* pActwk) { /* Line 2329, Address: 0x102c860 */
  static unsigned char pchg0[7] =
  {
    5, 0, 1, 2, 3, 4, 255
  };

  static unsigned char* kemuri_pchg[1] =
  {
    pchg0
  };

  patchg(pActwk, kemuri_pchg); /* Line 2340, Address: 0x102c86c */
  actionsub(pActwk); /* Line 2341, Address: 0x102c880 */
} /* Line 2342, Address: 0x102c88c */




void hahen73(sprite_status* pActwk) { /* Line 2347, Address: 0x102c8a0 */
  int_union ld0, ld1;
  short d0, d1;

  if (!(pActwk->r_no0 & 1)) /* Line 2351, Address: 0x102c8b4 */
  {
    pActwk->r_no0 |= 1; /* Line 2353, Address: 0x102c8cc */

    pActwk->actflg = 4; /* Line 2355, Address: 0x102c8dc */
    pActwk->sprpri = 5; /* Line 2356, Address: 0x102c8e8 */
    pActwk->sprhsize = 4; /* Line 2357, Address: 0x102c8f4 */
    pActwk->sprvsize = 4; /* Line 2358, Address: 0x102c900 */
    pActwk->sproffset = 17692; /* Line 2359, Address: 0x102c90c */
    pActwk->patbase = hahen73_pat; /* Line 2360, Address: 0x102c918 */

    ld0.l = random(); /* Line 2362, Address: 0x102c928 */
    ld0.l = ld0.w.l; /* Line 2363, Address: 0x102c934 */


    ld1.l = ld0.l; /* Line 2366, Address: 0x102c944 */
    ld0.l &= 32767; /* Line 2367, Address: 0x102c94c */
    ld1.w.l = ld1.l % 448; /* Line 2368, Address: 0x102c958 */

    pActwk->xspeed.w += ld1.w.l; /* Line 2370, Address: 0x102c974 */


    pActwk->yspeed.w = -384; /* Line 2373, Address: 0x102c988 */


    ((short*)pActwk)[27] = 16; /* Line 2376, Address: 0x102c994 */
    ld1.w.l = ld0.w.l; /* Line 2377, Address: 0x102c9a0 */
    ld1.w.l &= 15; /* Line 2378, Address: 0x102c9a8 */
    ((short*)pActwk)[27] += ld1.w.l; /* Line 2379, Address: 0x102c9b4 */


    ld0.w.l &= 3; /* Line 2382, Address: 0x102c9c8 */
    pActwk->patno = ld0.w.l; /* Line 2383, Address: 0x102c9d4 */
  } /* Line 2384, Address: 0x102c9e4 */
  else
  {
    pActwk->r_no0 |= 1; /* Line 2387, Address: 0x102c9ec */

    add_spd2(pActwk); /* Line 2389, Address: 0x102c9fc */

    d0 = pActwk->yposi.w.h; /* Line 2391, Address: 0x102ca08 */
    d1 = scra_v_posit.w.h; /* Line 2392, Address: 0x102ca18 */
    d1 += 232; /* Line 2393, Address: 0x102ca28 */
    d0 -= d1; /* Line 2394, Address: 0x102ca34 */
    if (d0 <= 0) /* Line 2395, Address: 0x102ca40 */
    {
      actionsub(pActwk); /* Line 2397, Address: 0x102ca50 */
    } /* Line 2398, Address: 0x102ca5c */
    else
    {
      frameout(pActwk); /* Line 2401, Address: 0x102ca64 */
    }
  }
} /* Line 2404, Address: 0x102ca70 */




void egg7jet(sprite_status* pActwk) { /* Line 2409, Address: 0x102ca90 */
  void(*tbl[2])(sprite_status*) = /* Line 2410, Address: 0x102ca9c */
  {
    &egg7jet_ini,
    &egg7jet_01
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 2416, Address: 0x102cab8 */
} /* Line 2417, Address: 0x102caf4 */




static void egg7jet_ini(sprite_status* pActwk) { /* Line 2422, Address: 0x102cb10 */
  pActwk->actflg = 4; /* Line 2423, Address: 0x102cb1c */
  pActwk->sprpri = 5; /* Line 2424, Address: 0x102cb28 */
  pActwk->sprhsize = 20; /* Line 2425, Address: 0x102cb34 */
  pActwk->sprvsize = 8; /* Line 2426, Address: 0x102cb40 */
  pActwk->sproffset = 8960; /* Line 2427, Address: 0x102cb4c */
  pActwk->patbase = egg7jet_pat; /* Line 2428, Address: 0x102cb58 */

  if (pActwk->userflag.b.h == 0) /* Line 2430, Address: 0x102cb68 */
  {
    ((short*)pActwk)[29] = -51; /* Line 2432, Address: 0x102cb80 */
    ((short*)pActwk)[30] = 26; /* Line 2433, Address: 0x102cb8c */
  } /* Line 2434, Address: 0x102cb98 */
  else
  {
    ((short*)pActwk)[29] = -48; /* Line 2437, Address: 0x102cba0 */
    ((short*)pActwk)[30] = -14; /* Line 2438, Address: 0x102cbac */
  }
  pActwk->r_no0 += 2; /* Line 2440, Address: 0x102cbb8 */

  egg7jet_01(pActwk); /* Line 2442, Address: 0x102cbc8 */
} /* Line 2443, Address: 0x102cbd4 */




static void egg7jet_01(sprite_status* pActwk) { /* Line 2448, Address: 0x102cbf0 */
  sprite_status* a2;
  short d0;

  a2 = &actwk[((short*)pActwk)[25]]; /* Line 2452, Address: 0x102cc04 */
  if (a2->actno == 0) /* Line 2453, Address: 0x102cc2c */
  {
    frameout(pActwk); /* Line 2455, Address: 0x102cc3c */
    return; /* Line 2456, Address: 0x102cc48 */
  }
  if (!(a2->actfree[2] & 8)) return; /* Line 2458, Address: 0x102cc50 */




  pActwk->cddat = a2->cddat; /* Line 2463, Address: 0x102cc64 */
  pActwk->xposi.w.h = a2->xposi.w.h; /* Line 2464, Address: 0x102cc70 */
  pActwk->yposi.w.h = a2->yposi.w.h; /* Line 2465, Address: 0x102cc7c */

  d0 = ((short*)pActwk)[29]; /* Line 2467, Address: 0x102cc88 */
  if (pActwk->cddat & 1) /* Line 2468, Address: 0x102cc98 */
  {
    d0 *= -1; /* Line 2470, Address: 0x102ccb0 */
  }
  pActwk->xposi.w.h += d0; /* Line 2472, Address: 0x102ccbc */
  d0 = ((short*)pActwk)[30]; /* Line 2473, Address: 0x102cccc */
  pActwk->yposi.w.h += d0; /* Line 2474, Address: 0x102ccdc */
  patchg(pActwk, egg7jet_pchg); /* Line 2475, Address: 0x102ccec */
  actionsub(pActwk); /* Line 2476, Address: 0x102cd00 */
} /* Line 2477, Address: 0x102cd0c */




void msnc_bara(sprite_status* pActwk) { /* Line 2482, Address: 0x102cd30 */
  void(*tbl[2])(sprite_status*) = /* Line 2483, Address: 0x102cd3c */
  {
    &msnc_bara_ini,
    &msnc_bara_01
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 2489, Address: 0x102cd58 */
  if (QuickReturn) /* Line 2490, Address: 0x102cd94 */
  {
    QuickReturn = 0; /* Line 2492, Address: 0x102cda4 */
    return; /* Line 2493, Address: 0x102cdac */
  }
  actionsub(pActwk); /* Line 2495, Address: 0x102cdb4 */
} /* Line 2496, Address: 0x102cdc0 */




static void msnc_bara_ini(sprite_status* pActwk) { /* Line 2501, Address: 0x102cdd0 */
  pActwk->actflg = 4; /* Line 2502, Address: 0x102cddc */
  pActwk->sprpri = 1; /* Line 2503, Address: 0x102cde8 */
  pActwk->sprhsize = 8; /* Line 2504, Address: 0x102cdf4 */
  pActwk->sprvsize = 8; /* Line 2505, Address: 0x102ce00 */
  pActwk->sproffset = 892; /* Line 2506, Address: 0x102ce0c */
  pActwk->patbase = msnc_bara_pat; /* Line 2507, Address: 0x102ce18 */

  msnc_bara_01(pActwk); /* Line 2509, Address: 0x102ce28 */
} /* Line 2510, Address: 0x102ce34 */




static void msnc_bara_01(sprite_status* pActwk) { /* Line 2515, Address: 0x102ce50 */
  add_spd2(pActwk); /* Line 2516, Address: 0x102ce5c */
  if (pActwk->yposi.w.h >= 624) /* Line 2517, Address: 0x102ce68 */
  {
    frameout(pActwk); /* Line 2519, Address: 0x102ce84 */
    QuickReturn = 1; /* Line 2520, Address: 0x102ce90 */
  }
} /* Line 2522, Address: 0x102ce9c */




static void add_spd3(sprite_status* pActwk) { /* Line 2527, Address: 0x102ceb0 */
  short d0;

  d0 = ((short*)pActwk)[27]; /* Line 2530, Address: 0x102cec0 */
  pActwk->yspeed.w += d0; /* Line 2531, Address: 0x102ced0 */

  d0 = ((short*)pActwk)[26]; /* Line 2533, Address: 0x102cee0 */
  pActwk->xspeed.w += d0; /* Line 2534, Address: 0x102cef0 */

  if (((short*)pActwk)[26] == 0) /* Line 2536, Address: 0x102cf00 */
  {
    add_spd(pActwk); /* Line 2538, Address: 0x102cf18 */
    return; /* Line 2539, Address: 0x102cf24 */
  }
  if (((short*)pActwk)[26] >= 0) /* Line 2541, Address: 0x102cf2c */
  {
    d0 = ((short*)pActwk)[28]; /* Line 2543, Address: 0x102cf44 */
    if (d0 <= pActwk->xspeed.w) /* Line 2544, Address: 0x102cf54 */
    {
      pActwk->xspeed.w = d0; /* Line 2546, Address: 0x102cf78 */
    }
    add_spd(pActwk); /* Line 2548, Address: 0x102cf80 */
  } /* Line 2549, Address: 0x102cf8c */
  else
  {
    d0 = ((short*)pActwk)[28]; /* Line 2552, Address: 0x102cf94 */
    if (d0 >= pActwk->xspeed.w) /* Line 2553, Address: 0x102cfa4 */
    {
      pActwk->xspeed.w = d0; /* Line 2555, Address: 0x102cfc8 */
    }
    add_spd(pActwk); /* Line 2557, Address: 0x102cfd0 */
  }
} /* Line 2559, Address: 0x102cfdc */




void hari_spdadd(sprite_status* pActwk) { /* Line 2564, Address: 0x102cff0 */
  add_spd2(pActwk); /* Line 2565, Address: 0x102cffc */
} /* Line 2566, Address: 0x102d008 */

static void add_spd2(sprite_status* pActwk) { /* Line 2568, Address: 0x102d020 */
  short d0;

  d0 = ((short*)pActwk)[26]; /* Line 2571, Address: 0x102d030 */
  pActwk->xspeed.w += d0; /* Line 2572, Address: 0x102d040 */
  d0 = ((short*)pActwk)[27]; /* Line 2573, Address: 0x102d050 */
  pActwk->yspeed.w += d0; /* Line 2574, Address: 0x102d060 */

  add_spd(pActwk); /* Line 2576, Address: 0x102d070 */
} /* Line 2577, Address: 0x102d07c */


static void add_spd(sprite_status* pActwk) { /* Line 2580, Address: 0x102d090 */
  int ld0;

  ld0 = pActwk->xspeed.w; /* Line 2583, Address: 0x102d09c */
  ld0 <<= 8; /* Line 2584, Address: 0x102d0ac */
  pActwk->xposi.l += ld0; /* Line 2585, Address: 0x102d0b0 */
  ld0 = pActwk->yspeed.w; /* Line 2586, Address: 0x102d0c0 */
  ld0 <<= 8; /* Line 2587, Address: 0x102d0d0 */
  pActwk->yposi.l += ld0; /* Line 2588, Address: 0x102d0d4 */
} /* Line 2589, Address: 0x102d0e4 */




static void w_timer(sprite_status* pActwk) { /* Line 2594, Address: 0x102d100 */
  --((short*)pActwk)[23]; /* Line 2595, Address: 0x102d108 */
  if (((short*)pActwk)[23] == 0) /* Line 2596, Address: 0x102d118 */
  {
    ++pActwk->actfree[3]; /* Line 2598, Address: 0x102d130 */
  }
} /* Line 2600, Address: 0x102d140 */




static void b_timer(sprite_status* pActwk) { /* Line 2605, Address: 0x102d150 */
  --pActwk->actfree[1]; /* Line 2606, Address: 0x102d158 */
  if (pActwk->actfree[1] == 0) /* Line 2607, Address: 0x102d168 */
  {
    ++pActwk->actfree[3]; /* Line 2609, Address: 0x102d17c */
  }
} /* Line 2611, Address: 0x102d18c */




static void event_timer(sprite_status* pActwk, short* pTimer, void(**func)(sprite_status*)) { /* Line 2616, Address: 0x102d1a0 */
  short d0;

  d0 = (unsigned short)pActwk->actfree[3]; /* Line 2619, Address: 0x102d1b8 */
  d0 = pTimer[d0]; /* Line 2620, Address: 0x102d1d4 */
  if (d0 != ((short*)pActwk)[23]) /* Line 2621, Address: 0x102d1f4 */
  {
    ++((short*)pActwk)[23]; /* Line 2623, Address: 0x102d214 */
  } /* Line 2624, Address: 0x102d224 */
  else
  {
    ++((short*)pActwk)[23]; /* Line 2627, Address: 0x102d22c */

    d0 = (unsigned short)pActwk->actfree[3]; /* Line 2629, Address: 0x102d23c */
    ++pActwk->actfree[3]; /* Line 2630, Address: 0x102d258 */
    func[d0](pActwk); /* Line 2631, Address: 0x102d268 */
  }
} /* Line 2633, Address: 0x102d28c */




static void make_bara(sprite_status* pActwk) { /* Line 2638, Address: 0x102d2a0 */
  sprite_status* pNewActwk;
  int_union ld0, ld1;
  short d0, d3;

  d3 = 9; /* Line 2643, Address: 0x102d2b4 */
  do
  {
    if (actwkchk2(pActwk, &pNewActwk) != 0) return; /* Line 2646, Address: 0x102d2c0 */
    d0 = d3; /* Line 2647, Address: 0x102d2d8 */
    d0 = d0 % 5; /* Line 2648, Address: 0x102d2e0 */
    pNewActwk->patno = (unsigned short)d0; /* Line 2649, Address: 0x102d304 */

    ((short*)pNewActwk)[25] = (unsigned short)(pActwk - actwk); /* Line 2651, Address: 0x102d314 */
    pNewActwk->actno = 49; /* Line 2652, Address: 0x102d350 */
    pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 2653, Address: 0x102d35c */
    pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 2654, Address: 0x102d36c */

    ld0.l = random(); /* Line 2656, Address: 0x102d37c */
    ld0.l = ld0.w.l; /* Line 2657, Address: 0x102d388 */


    ld1.l = ld0.l; /* Line 2660, Address: 0x102d398 */
    ld1.l |= -32768; /* Line 2661, Address: 0x102d3a0 */
    ld1.w.l = ld1.l % 640; /* Line 2662, Address: 0x102d3b0 */
    pNewActwk->xspeed.w = ld1.w.l; /* Line 2663, Address: 0x102d3cc */


    pNewActwk->yspeed.w = -512; /* Line 2666, Address: 0x102d3d8 */


    ((short*)pNewActwk)[27] = 12; /* Line 2669, Address: 0x102d3e4 */
    ld1.w.l = ld0.w.l; /* Line 2670, Address: 0x102d3f0 */
    ld1.w.l &= 15; /* Line 2671, Address: 0x102d3f8 */
    ((short*)pNewActwk)[27] += ld1.w.l; /* Line 2672, Address: 0x102d404 */
  } while (d3--); /* Line 2673, Address: 0x102d418 */

} /* Line 2675, Address: 0x102d430 */




static void make_ele(sprite_status* pActwk) { /* Line 2680, Address: 0x102d450 */
  sprite_status* pNewActwk;

  if (actwkchk2(pActwk, &pNewActwk) == 0) /* Line 2683, Address: 0x102d45c */
  {
    ((short*)pNewActwk)[25] = (unsigned short)(pActwk - actwk); /* Line 2685, Address: 0x102d474 */
    pNewActwk->actno = 48; /* Line 2686, Address: 0x102d4b0 */
  }
} /* Line 2688, Address: 0x102d4bc */




static void make_msnc(sprite_status* pActwk) { /* Line 2693, Address: 0x102d4d0 */
  sprite_status* pNewActwk;

  if (actwkchk2(pActwk, &pNewActwk) == 0) /* Line 2696, Address: 0x102d4dc */
  {
    ((short*)pNewActwk)[25] = (unsigned short)(pActwk - actwk); /* Line 2698, Address: 0x102d4f4 */
    ((short*)pActwk)[25] = (unsigned short)(pNewActwk - actwk); /* Line 2699, Address: 0x102d530 */
    pNewActwk->actno = 47; /* Line 2700, Address: 0x102d56c */
    pNewActwk->xposi.w.h = 3120; /* Line 2701, Address: 0x102d578 */
    pNewActwk->yposi.w.h = 461; /* Line 2702, Address: 0x102d584 */
  }
} /* Line 2704, Address: 0x102d590 */




static void make_jet(sprite_status* pActwk) { /* Line 2709, Address: 0x102d5a0 */
  sprite_status* pNewActwk;

  if (actwkchk2(pActwk, &pNewActwk) == 0) /* Line 2712, Address: 0x102d5ac */
  {
    ((short*)pNewActwk)[25] = (unsigned short)(pActwk - actwk); /* Line 2714, Address: 0x102d5c4 */
    pNewActwk->actno = 45; /* Line 2715, Address: 0x102d600 */
    pNewActwk->userflag.b.h = 0; /* Line 2716, Address: 0x102d60c */
    pNewActwk->mstno.b.h = 0; /* Line 2717, Address: 0x102d614 */
    if (actwkchk2(pActwk, &pNewActwk) == 0) /* Line 2718, Address: 0x102d61c */
    {
      ((short*)pNewActwk)[25] = (unsigned short)(pActwk - actwk); /* Line 2720, Address: 0x102d634 */
      pNewActwk->actno = 45; /* Line 2721, Address: 0x102d670 */
      pNewActwk->userflag.b.h = 1; /* Line 2722, Address: 0x102d67c */
      pNewActwk->mstno.b.h = 1; /* Line 2723, Address: 0x102d688 */
    }
  }
} /* Line 2726, Address: 0x102d694 */




static void make_beam(sprite_status* pActwk) { /* Line 2731, Address: 0x102d6b0 */
  sprite_status* pNewActwk;
  sprite_status* a3;
  short d2;

  d2 = 3; /* Line 2736, Address: 0x102d6c4 */
  a3 = pActwk; /* Line 2737, Address: 0x102d6d0 */
  do
  {
    if (actwkchk2(pActwk, &pNewActwk) != 0) break; /* Line 2740, Address: 0x102d6d4 */
    ((short*)pNewActwk)[25] = (unsigned short)(a3 - actwk); /* Line 2741, Address: 0x102d6ec */
    ((short*)pNewActwk)[31] = (unsigned short)(pActwk - actwk); /* Line 2742, Address: 0x102d724 */

    pNewActwk->actno = 46; /* Line 2744, Address: 0x102d760 */
    a3 = pNewActwk; /* Line 2745, Address: 0x102d76c */
    if (d2 == 3) goto label1; /* Line 2746, Address: 0x102d770 */
    if (d2 == 0) /* Line 2747, Address: 0x102d784 */
    {

      pNewActwk->userflag.b.l = 1; /* Line 2750, Address: 0x102d794 */
    }
    ((short*)pNewActwk)[29] = 2; /* Line 2752, Address: 0x102d7a0 */
    ((short*)pNewActwk)[30] = 32; /* Line 2753, Address: 0x102d7ac */
    continue; /* Line 2754, Address: 0x102d7b8 */
label1:
    ((short*)pNewActwk)[29] = 0; /* Line 2756, Address: 0x102d7c0 */
    ((short*)pNewActwk)[30] = 52; /* Line 2757, Address: 0x102d7c8 */
  } while (d2--); /* Line 2758, Address: 0x102d7d4 */

} /* Line 2760, Address: 0x102d7ec */




static void make_kemuri(sprite_status* pActwk) { /* Line 2765, Address: 0x102d810 */
  sprite_status* pNewActwk;

  if (actwkchk2(pActwk, &pNewActwk) == 0) /* Line 2768, Address: 0x102d81c */
  {
    ((short*)pNewActwk)[25] = (unsigned short)(pActwk - actwk); /* Line 2770, Address: 0x102d834 */
    pNewActwk->actno = 46; /* Line 2771, Address: 0x102d870 */
    pNewActwk->userflag.b.h = 1; /* Line 2772, Address: 0x102d87c */
    ((short*)pNewActwk)[29] = 2; /* Line 2773, Address: 0x102d888 */
    ((short*)pNewActwk)[30] = 16; /* Line 2774, Address: 0x102d894 */
  }
} /* Line 2776, Address: 0x102d8a0 */




static void make_bakuha(sprite_status* pActwk) { /* Line 2781, Address: 0x102d8b0 */
  sprite_status* pNewActwk;

  if (actwkchk2(pActwk, &pNewActwk) == 0) /* Line 2784, Address: 0x102d8bc */
  {
    ((short*)pNewActwk)[25] = (unsigned short)(pActwk - actwk); /* Line 2786, Address: 0x102d8d4 */
    pNewActwk->actno = 46; /* Line 2787, Address: 0x102d910 */
    pNewActwk->userflag.b.h = 2; /* Line 2788, Address: 0x102d91c */
    pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 2789, Address: 0x102d928 */
    pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 2790, Address: 0x102d938 */

    soundset(158); /* Line 2792, Address: 0x102d948 */
  }
} /* Line 2794, Address: 0x102d954 */




static void make_hahen(sprite_status* pActwk) { /* Line 2799, Address: 0x102d970 */
  sprite_status* pNewActwk;
  sprite_status* a2;

  if (actwkchk2(pActwk, &pNewActwk) == 0) /* Line 2803, Address: 0x102d980 */
  {
    pNewActwk->actno = 55; /* Line 2805, Address: 0x102d998 */
    pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 2806, Address: 0x102d9a4 */
    pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 2807, Address: 0x102d9b4 */
    pNewActwk->xposi.w.h += 2; /* Line 2808, Address: 0x102d9c4 */
    pNewActwk->yposi.w.h += 16; /* Line 2809, Address: 0x102d9d4 */
    a2 = &actwk[((short*)pActwk)[31]]; /* Line 2810, Address: 0x102d9e4 */
    pNewActwk->xspeed.w = a2->xspeed.w; /* Line 2811, Address: 0x102da0c */
  }
} /* Line 2813, Address: 0x102da18 */
