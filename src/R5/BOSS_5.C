#include "..\EQU.H"
#include "BOSS_5.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\GOAL.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"
#include "..\SCORE.H"
#include "SCR53C.H"

static int egg5_ini(sprite_status* pActwk);
static int egg5_1(sprite_status* pActwk);
static int egg5_esc(sprite_status* pActwk);
static int egg5meca1_ini(sprite_status* pActwk);
static int egg5meca1_scrset(sprite_status* pActwk);
static int egg5meca1_scrreset(sprite_status* pActwk);
static int egg5meca1_normal(sprite_status* pActwk);
static int egg5meca2_ini(sprite_status* pActwk);
static int egg5meca2_ue(sprite_status* pActwk);
static int egg5meca2_down1(sprite_status* pActwk);
static int egg5meca2_down2(sprite_status* pActwk);
static int egg5meca2_kezu(sprite_status* pActwk);
static int egg5meca2_esc(sprite_status* pActwk);
static int egg5meca2_end(sprite_status* pActwk);
static void my_rideonchk(sprite_status* pActwk);
static void egg5meca3_ini(sprite_status* pActwk);
static void egg5meca3_1(sprite_status* pActwk);
static void egg5pipe_ini(sprite_status* pActwk);
static void egg5pipe_1(sprite_status* pActwk);
static int egg5catch_ini(sprite_status* pActwk);
static int egg5catch_1st(sprite_status* pActwk);
static int egg5catch_return(sprite_status* pActwk);
static int egg5catch_wait(sprite_status* pActwk);
static int egg5catch_go1(sprite_status* pActwk);
static int egg5catch_go2(sprite_status* pActwk);
static int egg5catch_fire(sprite_status* pActwk);
static void lever_on(sprite_status* pActwk);
static void lever_off(sprite_status* pActwk);
static int egg5bomb_ini(sprite_status* pActwk);
static int egg5bomb_1(sprite_status* pActwk);
static int egg5bomb_2(sprite_status* pActwk);
static int egg5bomb_3(sprite_status* pActwk);
static int egg5bomb_4(sprite_status* pActwk);
static int egg5bomb2_ini(sprite_status* pActwk);
static int egg5bomb2_1(sprite_status* pActwk);
static int egg5bomb2_2(sprite_status* pActwk);
static int egg5bomb_hit(sprite_status* pActwk);
static int egg5hibana_ini(sprite_status* pActwk);
static int egg5hibana_1(sprite_status* pActwk);
static int egg5hibana_2(sprite_status* pActwk);
static int hibana_delchk(sprite_status* pActwk);
static void egg5hari_ini(sprite_status* pActwk);
static void egg5hari_1(sprite_status* pActwk);
static void egg5hari_2(sprite_status* pActwk);
static void egg5hari_3(sprite_status* pActwk);
static void egg5hari_4(sprite_status* pActwk);
static void egg5hari_chk(sprite_status* pActwk);
static void egg5belt_ini(sprite_status* pActwk);
static void egg5belt_0(sprite_status* pActwk);
static void egg5belt_1(sprite_status* pActwk);
static void egg5belt_2(sprite_status* pActwk);
static void egg5belt_3(sprite_status* pActwk);
static int belt_spdset(sprite_status* pActwk);
static void belt_hitpnt(short subact, sprite_status* pActwk);
static void belt_sncspd(int wD6, sprite_status* pActwk);
static void belt_sncxmax(short subact);
static void belt_anime(sprite_status* pActwk);
static void set_belt_col(sprite_status* pActwk);
static int chk_belt_on();
static int egg5bakuha_ini(sprite_status* pActwk);
static int egg5bakuha_1(sprite_status* pActwk);
static int frameout_sp4(sprite_status* pActwk);
static void bom_set(sprite_status* pActwk);
static void make_meca2(sprite_status* pActwk);
static void make_egg5(sprite_status* pActwk);
static void make_catch(sprite_status* pActwk);
static void make_pipe(sprite_status* pActwk);
static void make_meca3(sprite_status* pActwk);
static void make_bomb(sprite_status* pActwk);
static void make_bomb2(sprite_status* pActwk);
static void make_belt(sprite_status* pActwk);
static void chg_mstno(unsigned char num, sprite_status* pActwk);
static void chg_mstno2(unsigned char num, short subact);
static int frameout_chk(sprite_status* pActwk);

extern void colorset2(int ColorNo);

static unsigned char egg5_pchg0[4] = { 19, 0, 1, 255 };
static unsigned char egg5_pchg1[6] = { 3, 2, 4, 3, 5, 255 };
static unsigned char egg5_pchg2[6] = { 3, 6, 8, 7, 9, 255 };
static unsigned char egg5_pchg3[10] = { 2, 10, 13, 12, 15, 11, 14, 12, 15, 255 };
static unsigned char* egg5_pchg[4] =
{
  egg5_pchg0,
  egg5_pchg1,
  egg5_pchg2,
  egg5_pchg3
};
static unsigned char egg5catch_pchg0[3] = { 255, 0, 255 };
static unsigned char egg5catch_pchg1[4] = { 5, 1, 2, 255 };
static unsigned char* egg5catch_pchg[2] =
{
  egg5catch_pchg0,
  egg5catch_pchg1
};
static unsigned char egg5hibana_pchg0[7] = { 3, 0, 1, 2, 3, 4, 255 };
static unsigned char* egg5hibana_pchg[1] = { egg5hibana_pchg0 };
static unsigned char egg5bakuha_pat0[12] =
{
  3, 0, 5, 6, 3, 4,
  0, 1, 2, 3, 4, 252
};
static unsigned char* egg5bakuha_pchg[1] = { egg5bakuha_pat0 };
static sprite_pattern spr_egg5_pat00 =
{
  1,
  { { -24, -28, 0, 422 } }
};
static sprite_pattern spr_egg5_pat01 =
{
  1,
  { { -24, -28, 0, 423 } }
};
static sprite_pattern spr_egg5_pat02 =
{
  1,
  { { -24, -48, 0, 424 } }
};
static sprite_pattern spr_egg5_pat03 =
{
  1,
  { { -24, -48, 0, 425 } }
};
static sprite_pattern spr_egg5_pat04 =
{
  1,
  { { -24, -32, 0, 426 } }
};
static sprite_pattern spr_egg5_pat05 =
{
  1,
  { { -24, -32, 0, 427 } }
};
static sprite_pattern spr_egg5_pat06 =
{
  1,
  { { -24, -44, 0, 428 } }
};
static sprite_pattern spr_egg5_pat07 =
{
  1,
  { { -24, -44, 0, 429 } }
};
static sprite_pattern spr_egg5_pat08 =
{
  1,
  { { -24, -28, 0, 430 } }
};
static sprite_pattern spr_egg5_pat09 =
{
  1,
  { { -24, -28, 0, 431 } }
};
static sprite_pattern spr_egg5_pat10 =
{
  1,
  { { -32, -52, 0, 432 } }
};
static sprite_pattern spr_egg5_pat11 =
{
  1,
  { { -32, -48, 0, 433 } }
};
static sprite_pattern spr_egg5_pat12 =
{
  1,
  { { -32, -50, 0, 434 } }
};
static sprite_pattern spr_egg5_pat13 =
{
  1,
  { { -32, -36, 0, 435 } }
};
static sprite_pattern spr_egg5_pat14 =
{
  1,
  { { -32, -32, 0, 436 } }
};
static sprite_pattern spr_egg5_pat15 =
{
  1,
  { { -32, -34, 0, 437 } }
};
sprite_pattern* egg5_pat[16] =
{
  &spr_egg5_pat00,
  &spr_egg5_pat01,
  &spr_egg5_pat02,
  &spr_egg5_pat03,
  &spr_egg5_pat04,
  &spr_egg5_pat05,
  &spr_egg5_pat06,
  &spr_egg5_pat07,
  &spr_egg5_pat08,
  &spr_egg5_pat09,
  &spr_egg5_pat10,
  &spr_egg5_pat11,
  &spr_egg5_pat12,
  &spr_egg5_pat13,
  &spr_egg5_pat14,
  &spr_egg5_pat15
};
static sprite_pattern spr_egg5meca1_pat0 =
{
  1,
  { { -32, -24, 0, 438 } }
};
sprite_pattern* egg5meca1_pat[1] = { &spr_egg5meca1_pat0 };
static sprite_pattern spr_egg5meca2_pat0 =
{
  1,
  { { -32, -24, 0, 439 } }
};
static sprite_pattern spr_egg5meca2_pat1 =
{
  1,
  { { -32, -24, 0, 440 } }
};
static sprite_pattern spr_egg5meca2_pat2 =
{
  1,
  { { -32, -24, 0, 441 } }
};
static sprite_pattern spr_egg5meca2_pat3 =
{
  1,
  { { -32, -24, 0, 442 } }
};
static sprite_pattern spr_egg5meca2_pat4 =
{
  1,
  { { -32, -24, 0, 443 } }
};
static sprite_pattern spr_egg5meca2_pat5 =
{
  1,
  { { -32, -24, 0, 444 } }
};
sprite_pattern* egg5meca2_pat[6] =
{
  &spr_egg5meca2_pat0,
  &spr_egg5meca2_pat1,
  &spr_egg5meca2_pat2,
  &spr_egg5meca2_pat3,
  &spr_egg5meca2_pat4,
  &spr_egg5meca2_pat5
};
static sprite_pattern spr_egg5meca3_pat0 =
{
  1,
  { { -16, -8, 0, 445 } }
};
sprite_pattern* egg5meca3_pat[1] = { &spr_egg5meca3_pat0 };
static sprite_pattern spr_egg5pipe_pat0 =
{
  1,
  { { -28, -32, 0, 446 } }
};
static sprite_pattern spr_egg5pipe_pat1 =
{
  1,
  { { -28, -32, 0, 447 } }
};
static sprite_pattern spr_egg5pipe_pat2 =
{
  1,
  { { -28, -32, 0, 448 } }
};
static sprite_pattern spr_egg5pipe_pat3 =
{
  1,
  { { -28, -32, 0, 449 } }
};
sprite_pattern* egg5pipe_pat[4] =
{
  &spr_egg5pipe_pat0,
  &spr_egg5pipe_pat1,
  &spr_egg5pipe_pat2,
  &spr_egg5pipe_pat3
};
static sprite_pattern spr_egg5catch_pat0 =
{
  1,
  { { -16, -12, 0, 450 } }
};
static sprite_pattern spr_egg5catch_pat1 =
{
  1,
  { { -16, -12, 0, 451 } }
};
static sprite_pattern spr_egg5catch_pat2 =
{
  1,
  { { -16, -12, 0, 452 } }
};
sprite_pattern* egg5catch_pat[3] =
{
  &spr_egg5catch_pat0,
  &spr_egg5catch_pat1,
  &spr_egg5catch_pat2
};
static sprite_pattern spr_egg5bomb_pat0 =
{
  1,
  { { -12, -12, 0, 453 } }
};
static sprite_pattern spr_egg5bomb_pat1 =
{
  1,
  { { -8, -8, 0, 454 } }
};
sprite_pattern* egg5bomb_pat[2] =
{
  &spr_egg5bomb_pat0,
  &spr_egg5bomb_pat1
};
static sprite_pattern spr_egg5hibana_pat0 =
{
  1,
  { { 0, 0, 0, 455 } }
};
static sprite_pattern spr_egg5hibana_pat1 =
{
  1,
  { { 0, 0, 0, 456 } }
};
static sprite_pattern spr_egg5hibana_pat2 =
{
  1,
  { { 0, 0, 0, 457 } }
};
static sprite_pattern spr_egg5hibana_pat3 =
{
  1,
  { { 0, 0, 0, 458 } }
};
static sprite_pattern spr_egg5hibana_pat4 =
{
  1,
  { { 0, 0, 0, 459 } }
};
sprite_pattern* egg5hibana_pat[5] =
{
  &spr_egg5hibana_pat0,
  &spr_egg5hibana_pat1,
  &spr_egg5hibana_pat2,
  &spr_egg5hibana_pat3,
  &spr_egg5hibana_pat4
};
static sprite_pattern spr_egg5hari_pat0 =
{
  1,
  { { -16, -32, 0, 460 } }
};
sprite_pattern* egg5hari_pat[1] = { &spr_egg5hari_pat0 };
extern short scr_dir_tbl[6];
static int bomb2_tbl[24] =
{
   4, -12,  40960, -229376, 0, 12288,
   4,  -8,  81920, -114688, 0,  6144,
  -4, -12, -40960, -229376, 0, 12288,
  -4,  -8, -81920, -114688, 0,  6144
};
extern sprite_pattern* bakupat[7];






































































































































































































































































































void egg5(sprite_status* pActwk) { /* Line 671, Address: 0x1023e50 */
  static int(*act_tbl[3])(sprite_status*) =
  {
    &egg5_ini,
    &egg5_1,
    &egg5_esc
  };

  if (act_tbl[pActwk->r_no0 / 2](pActwk) != 0) /* Line 679, Address: 0x1023e5c */
  {
    if (pActwk->mstno.b.h) /* Line 681, Address: 0x1023ea8 */
      patchg(pActwk, egg5_pchg); /* Line 682, Address: 0x1023eb8 */
    actionsub(pActwk); /* Line 683, Address: 0x1023ecc */
  } /* Line 684, Address: 0x1023ed8 */
  else
    frameout(pActwk); /* Line 686, Address: 0x1023ee0 */
} /* Line 687, Address: 0x1023eec */


static int egg5_ini(sprite_status* pActwk) { /* Line 690, Address: 0x1023f00 */
  int ret;

  pActwk->r_no0 += 2; /* Line 693, Address: 0x1023f10 */
  pActwk->actflg = 4; /* Line 694, Address: 0x1023f20 */
  pActwk->sprpri = 5; /* Line 695, Address: 0x1023f2c */
  pActwk->sprhsize = 16; /* Line 696, Address: 0x1023f38 */
  pActwk->sprvsize = 16; /* Line 697, Address: 0x1023f44 */
  pActwk->sproffset = 700; /* Line 698, Address: 0x1023f50 */
  pActwk->patbase = egg5_pat; /* Line 699, Address: 0x1023f5c */
  make_catch(pActwk); /* Line 700, Address: 0x1023f6c */
  ret = egg5_1(pActwk); /* Line 701, Address: 0x1023f78 */
  return ret; /* Line 702, Address: 0x1023f88 */
} /* Line 703, Address: 0x1023f8c */


static int egg5_1(sprite_status* pActwk) { /* Line 706, Address: 0x1023fa0 */
  short subact;
  int ret;

  if (!(pActwk->actfree[2] & 4)) /* Line 710, Address: 0x1023fb4 */
  {
    subact = ((short*)pActwk)[25]; /* Line 712, Address: 0x1023fcc */
    pActwk->yposi.w.h = actwk[subact].yposi.w.h; /* Line 713, Address: 0x1023fdc */
    if (actwk[subact].patno >= 4) /* Line 714, Address: 0x1024008 */
    {


      if (!pActwk->actfree[0]) /* Line 718, Address: 0x102403c */
      {

        chg_mstno(2, pActwk); /* Line 721, Address: 0x102404c */
        pActwk->actfree[0] = 68; /* Line 722, Address: 0x102405c */
      } /* Line 723, Address: 0x1024068 */
      else
      {
        --pActwk->actfree[0]; /* Line 726, Address: 0x1024070 */
        if (pActwk->actfree[0] == 20) /* Line 727, Address: 0x1024080 */
        {

          chg_mstno(0, pActwk); /* Line 730, Address: 0x1024098 */
        }
      }
    }
    return 1; /* Line 734, Address: 0x10240a8 */
  }

  pActwk->sprpri = 3; /* Line 737, Address: 0x10240b4 */
  pActwk->actfree[0] = 0; /* Line 738, Address: 0x10240c0 */
  pActwk->r_no0 += 2; /* Line 739, Address: 0x10240c8 */
  chg_mstno(3, pActwk); /* Line 740, Address: 0x10240d8 */
  pActwk->yposi.w.h += 6; /* Line 741, Address: 0x10240e8 */
  scoreup(100); /* Line 742, Address: 0x10240f8 */
  ret = egg5_esc(pActwk); /* Line 743, Address: 0x1024104 */
  return ret; /* Line 744, Address: 0x1024114 */
} /* Line 745, Address: 0x1024118 */


static int egg5_esc(sprite_status* pActwk) { /* Line 748, Address: 0x1024130 */
  int ret = 1; /* Line 749, Address: 0x102413c */

  pActwk->xposi.l += 73728; /* Line 751, Address: 0x1024140 */
  if (pActwk->xposi.w.h >= 3616) /* Line 752, Address: 0x1024158 */
    ret = 0; /* Line 753, Address: 0x1024174 */
  return ret; /* Line 754, Address: 0x1024178 */
} /* Line 755, Address: 0x102417c */







void egg5meca1(sprite_status* pActwk) { /* Line 763, Address: 0x1024190 */
  short subact;
  static int(*act_tbl[4])(sprite_status*) =
  {
    &egg5meca1_ini,
    &egg5meca1_scrset,
    &egg5meca1_scrreset,
    &egg5meca1_normal
  };

  if (act_tbl[pActwk->r_no0 / 2](pActwk) != 0) /* Line 773, Address: 0x10241a0 */
  {
    subact = ((short*)pActwk)[26]; /* Line 775, Address: 0x10241ec */
    if (!(actwk[subact].actfree[2] & 8)) /* Line 776, Address: 0x10241fc */
      actionsub(pActwk); /* Line 777, Address: 0x1024230 */
  }
} /* Line 779, Address: 0x102423c */


static int egg5meca1_ini(sprite_status* pActwk) { /* Line 782, Address: 0x1024250 */
  int ret;

  colorset2(6); /* Line 785, Address: 0x1024260 */
  pActwk->r_no0 += 2; /* Line 786, Address: 0x102426c */
  pActwk->actflg = 4; /* Line 787, Address: 0x102427c */
  pActwk->sprpri = 4; /* Line 788, Address: 0x1024288 */
  pActwk->sprhsize = 32; /* Line 789, Address: 0x1024294 */
  pActwk->sprvsize = 24; /* Line 790, Address: 0x10242a0 */
  pActwk->sproffset = 8892; /* Line 791, Address: 0x10242ac */
  pActwk->patbase = egg5meca1_pat; /* Line 792, Address: 0x10242b8 */
  make_meca2(pActwk); /* Line 793, Address: 0x10242c8 */
  ret = egg5meca1_scrset(pActwk); /* Line 794, Address: 0x10242d4 */
  return ret; /* Line 795, Address: 0x10242e4 */
} /* Line 796, Address: 0x10242e8 */



static int egg5meca1_scrset(sprite_status* pActwk) { /* Line 800, Address: 0x1024300 */
  short wD0;

  if (!(pActwk->actfree[2] & 2)) /* Line 803, Address: 0x1024310 */
  {
    if (scra_vline > 200) /* Line 805, Address: 0x1024328 */
    {
      bossflag = 5; /* Line 807, Address: 0x1024344 */
      pActwk->actfree[2] |= 2; /* Line 808, Address: 0x1024350 */
    }

    scra_vline += 6; /* Line 811, Address: 0x1024360 */
  }

  scralim_right = 3264; /* Line 814, Address: 0x1024374 */
  scralim_n_right = 3264; /* Line 815, Address: 0x1024380 */
  wD0 = actwk[0].xposi.w.h - 160; /* Line 816, Address: 0x102438c */
  if (wD0 >= scralim_left) /* Line 817, Address: 0x10243b0 */
  {
    if (actwk[0].xposi.w.h >= 3424) /* Line 819, Address: 0x10243d4 */
    {

      pActwk->actfree[2] &= 253; /* Line 822, Address: 0x10243f0 */
      sub_sync(103); /* Line 823, Address: 0x1024400 */
      bossstart = 5; /* Line 824, Address: 0x102440c */
      pActwk->r_no0 = 6; /* Line 825, Address: 0x1024418 */
      scralim_right = 3264; /* Line 826, Address: 0x1024424 */
      scralim_n_right = 3264; /* Line 827, Address: 0x1024430 */
      wD0 = 3264; /* Line 828, Address: 0x102443c */
    }

    scralim_left = wD0; /* Line 831, Address: 0x1024448 */
    scralim_n_left = wD0; /* Line 832, Address: 0x1024450 */
  }
  return 1; /* Line 834, Address: 0x1024458 */
} /* Line 835, Address: 0x102445c */



static int egg5meca1_scrreset(sprite_status* pActwk) { /* Line 839, Address: 0x1024470 */
  short wD0, wD1, wD2, wD3;

  wD0 = scr_dir_tbl[1]; /* Line 842, Address: 0x102448c */
  wD1 = scr_dir_tbl[2]; /* Line 843, Address: 0x102449c */
  wD2 = scr_dir_tbl[3]; /* Line 844, Address: 0x10244ac */
  wD3 = scr_dir_tbl[4]; /* Line 845, Address: 0x10244bc */
  scralim_right += 6; /* Line 846, Address: 0x10244cc */
  scralim_n_right += 6; /* Line 847, Address: 0x10244e0 */
  if (wD1 <= scralim_right) /* Line 848, Address: 0x10244f4 */
  {

    bossstart = 0; /* Line 851, Address: 0x1024518 */
    scralim_right = wD1; /* Line 852, Address: 0x1024520 */
    scralim_n_right = wD1; /* Line 853, Address: 0x1024528 */
    if (!generate_flag) /* Line 854, Address: 0x1024530 */
      sub_sync(26); /* Line 855, Address: 0x1024540 */
    else
      sub_sync(25); /* Line 857, Address: 0x1024554 */
    genecolor(); /* Line 858, Address: 0x1024560 */
    pActwk->r_no0 = 6; /* Line 859, Address: 0x1024568 */
  }
  return 1; /* Line 861, Address: 0x1024574 */
} /* Line 862, Address: 0x1024578 */


static int egg5meca1_normal(sprite_status* pActwk) { /* Line 865, Address: 0x10245a0 */
  short subact;
  short wD0;

  subact = ((short*)pActwk)[26]; /* Line 869, Address: 0x10245b0 */
  if (actwk[subact].actfree[2] & 128) /* Line 870, Address: 0x10245c0 */
    pActwk->actfree[20] = 8; /* Line 871, Address: 0x10245f4 */
  actwk[subact].actfree[2] &= 127; /* Line 872, Address: 0x1024600 */


  if (pActwk->actfree[20]) /* Line 875, Address: 0x102462c */
  {
    --pActwk->actfree[20]; /* Line 877, Address: 0x102463c */
    wD0 = 2; /* Line 878, Address: 0x102464c */
    if (pActwk->actfree[20] & 2) /* Line 879, Address: 0x1024658 */
      wD0 *= -1; /* Line 880, Address: 0x1024670 */
    scralim_down += wD0; /* Line 881, Address: 0x102467c */
    scralim_n_down += wD0; /* Line 882, Address: 0x1024690 */
  }
  return 1; /* Line 884, Address: 0x10246a4 */
} /* Line 885, Address: 0x10246a8 */







void egg5meca2(sprite_status* pActwk) { /* Line 893, Address: 0x10246c0 */
  short subact;
  static int(*act_tbl[7])(sprite_status*) =
  {
    &egg5meca2_ini,
    &egg5meca2_ue,
    &egg5meca2_down1,
    &egg5meca2_down2,
    &egg5meca2_kezu,
    &egg5meca2_esc,
    &egg5meca2_end
  };

  if (act_tbl[pActwk->r_no0 / 2](pActwk) != 0) /* Line 906, Address: 0x10246d0 */
  {
    if (!(pActwk->actfree[2] & 8)) /* Line 908, Address: 0x102471c */
    {

      pActwk->xposi.w.h = 3536; /* Line 911, Address: 0x1024734 */
      ++pActwk->actfree[1]; /* Line 912, Address: 0x1024740 */

      if (pActwk->actfree[1] & 2) /* Line 914, Address: 0x1024750 */
      {
        subact = ((short*)pActwk)[27]; /* Line 916, Address: 0x1024768 */
        if (((short*)&actwk[subact])[27] >= 1024) /* Line 917, Address: 0x1024778 */
        {
          if (((short*)&actwk[subact])[27] >= 1280) /* Line 919, Address: 0x10247b0 */
          {
            ++pActwk->xposi.w.h; /* Line 921, Address: 0x10247e8 */
            if (!(pActwk->actfree[10] & 1)) /* Line 922, Address: 0x10247f8 */
            {
              pActwk->actfree[10] ^= 1; /* Line 924, Address: 0x1024810 */
              actionsub(pActwk); /* Line 925, Address: 0x1024820 */
              return; /* Line 926, Address: 0x102482c */
            }
            pActwk->actfree[10] ^= 1; /* Line 928, Address: 0x1024834 */
            pActwk->xposi.w.h -= 2; /* Line 929, Address: 0x1024844 */
            actionsub(pActwk); /* Line 930, Address: 0x1024854 */
            return; /* Line 931, Address: 0x1024860 */
          }

          if (pActwk->actfree[10] & 1) /* Line 934, Address: 0x1024868 */
            --pActwk->xposi.w.h; /* Line 935, Address: 0x1024880 */
          pActwk->actfree[10] ^= 1; /* Line 936, Address: 0x1024890 */
        }
      }

      actionsub(pActwk); /* Line 940, Address: 0x10248a0 */
    }
  }
} /* Line 943, Address: 0x10248ac */


static int egg5meca2_ini(sprite_status* pActwk) { /* Line 946, Address: 0x10248c0 */
  int ret;

  pActwk->r_no0 += 2; /* Line 949, Address: 0x10248d0 */
  pActwk->actflg = 4; /* Line 950, Address: 0x10248e0 */
  pActwk->sprpri = 4; /* Line 951, Address: 0x10248ec */
  pActwk->sprhsize = 32; /* Line 952, Address: 0x10248f8 */
  pActwk->sprvsize = 112; /* Line 953, Address: 0x1024904 */
  pActwk->sproffset = 8892; /* Line 954, Address: 0x1024910 */
  pActwk->patbase = egg5meca2_pat; /* Line 955, Address: 0x102491c */
  make_egg5(pActwk); /* Line 956, Address: 0x102492c */
  make_meca3(pActwk); /* Line 957, Address: 0x1024938 */
  make_pipe(pActwk); /* Line 958, Address: 0x1024944 */
  make_belt(pActwk); /* Line 959, Address: 0x1024950 */
  pActwk->colino = 62; /* Line 960, Address: 0x102495c */
  pActwk->colicnt = 2; /* Line 961, Address: 0x1024968 */
  ((short*)pActwk)[33] = 2400; /* Line 962, Address: 0x1024974 */
  ret = egg5meca2_ue(pActwk); /* Line 963, Address: 0x1024980 */
  return ret; /* Line 964, Address: 0x1024990 */
} /* Line 965, Address: 0x1024994 */



static int egg5meca2_ue(sprite_status* pActwk) { /* Line 969, Address: 0x10249b0 */
  if (!pActwk->colino) /* Line 970, Address: 0x10249bc */
  {
    soundset(172); /* Line 972, Address: 0x10249cc */
    pActwk->r_no0 = 4; /* Line 973, Address: 0x10249d8 */
    pActwk->colicnt = 0; /* Line 974, Address: 0x10249e4 */
  }
  return 1; /* Line 976, Address: 0x10249ec */
} /* Line 977, Address: 0x10249f0 */




static int egg5meca2_down1(sprite_status* pActwk) { /* Line 982, Address: 0x1024a00 */
  int ret = 1; /* Line 983, Address: 0x1024a10 */

  ++pActwk->actfree[0]; /* Line 985, Address: 0x1024a14 */
  if (pActwk->actfree[0] != 60) /* Line 986, Address: 0x1024a24 */
  {
    if (!(pActwk->actfree[0] & 1)) /* Line 988, Address: 0x1024a3c */
    {
      if (!(pActwk->actfree[0] & 2)) /* Line 990, Address: 0x1024a54 */
        pActwk->yposi.w.h -= 2; /* Line 991, Address: 0x1024a6c */
      else
        pActwk->yposi.w.h += 2; /* Line 993, Address: 0x1024a84 */
    }
  } /* Line 995, Address: 0x1024a94 */
  else
  {

    pActwk->actfree[0] = 0; /* Line 999, Address: 0x1024a9c */
    pActwk->r_no0 += 2; /* Line 1000, Address: 0x1024aa4 */
    ((int*)pActwk)[4] = 77824; /* Line 1001, Address: 0x1024ab4 */
    chg_mstno2(1, ((short*)pActwk)[26]); /* Line 1002, Address: 0x1024ac4 */
    ((short*)pActwk)[30] = 648; /* Line 1003, Address: 0x1024ad8 */
    ((short*)pActwk)[29] = 640; /* Line 1004, Address: 0x1024ae4 */
    ret = egg5meca2_down2(pActwk); /* Line 1005, Address: 0x1024af0 */
  }
  return ret; /* Line 1007, Address: 0x1024b00 */
} /* Line 1008, Address: 0x1024b04 */










static int egg5meca2_down2(sprite_status* pActwk) { /* Line 1019, Address: 0x1024b20 */






  if (pActwk->actfree[3] == 1) /* Line 1026, Address: 0x1024b2c */
  {

    if (pActwk->yposi.w.h < ((short*)pActwk)[29]) /* Line 1029, Address: 0x1024b44 */
    {

      soundset(180); /* Line 1032, Address: 0x1024b70 */
      ++pActwk->actfree[3]; /* Line 1033, Address: 0x1024b7c */
    } /* Line 1034, Address: 0x1024b8c */
    else
      pActwk->yposi.l -= 32768; /* Line 1036, Address: 0x1024b94 */
    return 1; /* Line 1037, Address: 0x1024ba4 */
  }



  if (pActwk->yposi.w.h >= ((short*)pActwk)[30]) /* Line 1042, Address: 0x1024bb0 */
  {

    soundset(180); /* Line 1045, Address: 0x1024bdc */
    pActwk->actfree[2] |= 128; /* Line 1046, Address: 0x1024be8 */
    make_hibana2(pActwk); /* Line 1047, Address: 0x1024bf8 */
    if (pActwk->actfree[3]) /* Line 1048, Address: 0x1024c04 */
    {

      if (!pActwk->patno) /* Line 1051, Address: 0x1024c14 */
      {
        soundset(196); /* Line 1053, Address: 0x1024c24 */

        ++pActwk->patno; /* Line 1055, Address: 0x1024c30 */
        chg_mstno2(0, ((short*)pActwk)[26]); /* Line 1056, Address: 0x1024c40 */
      }

      pActwk->r_no0 = 8; /* Line 1059, Address: 0x1024c54 */
      pActwk->actfree[3] = 0; /* Line 1060, Address: 0x1024c60 */
      return 1; /* Line 1061, Address: 0x1024c68 */
    }
    ++pActwk->actfree[3]; /* Line 1063, Address: 0x1024c74 */
  } /* Line 1064, Address: 0x1024c84 */
  else
    pActwk->yposi.l += 77824; /* Line 1066, Address: 0x1024c8c */
  return 1; /* Line 1067, Address: 0x1024ca4 */
} /* Line 1068, Address: 0x1024ca8 */



static int egg5meca2_kezu(sprite_status* pActwk) { /* Line 1072, Address: 0x1024cc0 */
  short subact;
  short wD0;
  short meca2_ytbl[4] = /* Line 1075, Address: 0x1024cd4 */
  {
    0,
    8,
    8,
    8
  };

  my_rideonchk(pActwk); /* Line 1083, Address: 0x1024d00 */
  if (((short*)pActwk)[33] % 6 == 0) /* Line 1084, Address: 0x1024d0c */
  {
    if (!(pActwk->actfree[2] & 2)) /* Line 1086, Address: 0x1024d30 */
      make_hibana1(); /* Line 1087, Address: 0x1024d48 */
    pActwk->actfree[2] |= 2; /* Line 1088, Address: 0x1024d50 */
  } /* Line 1089, Address: 0x1024d60 */
  else
    pActwk->actfree[2] &= 253; /* Line 1091, Address: 0x1024d68 */

  if (((short*)pActwk)[33] <= 0) /* Line 1093, Address: 0x1024d78 */
  {

    pActwk->actfree[2] |= 4; /* Line 1096, Address: 0x1024d90 */
    subact = ((short*)pActwk)[26]; /* Line 1097, Address: 0x1024da0 */
    actwk[subact].actfree[2] |= 4; /* Line 1098, Address: 0x1024db0 */
    pActwk->r_no0 = 10; /* Line 1099, Address: 0x1024ddc */
    ++pActwk->patno; /* Line 1100, Address: 0x1024de8 */




    subact = ((short*)pActwk)[25]; /* Line 1105, Address: 0x1024df8 */
    actwk[subact].r_no0 = 4; /* Line 1106, Address: 0x1024e08 */
    return 1; /* Line 1107, Address: 0x1024e30 */
  }
  if (((short*)pActwk)[33] != 1800) /* Line 1109, Address: 0x1024e3c */
  {
    if (((short*)pActwk)[33] != 1200) /* Line 1111, Address: 0x1024e58 */
    {
      if (((short*)pActwk)[33] != 600) /* Line 1113, Address: 0x1024e74 */
        return 1; /* Line 1114, Address: 0x1024e90 */
    }
  }

  make_hibana2(pActwk); /* Line 1118, Address: 0x1024e9c */
  wD0 = meca2_ytbl[pActwk->patno]; /* Line 1119, Address: 0x1024ea8 */
  ((short*)pActwk)[30] = pActwk->yposi.w.h + wD0; /* Line 1120, Address: 0x1024ec8 */
  wD0 /= 2; /* Line 1121, Address: 0x1024ef4 */
  ((short*)pActwk)[29] = pActwk->yposi.w.h + wD0; /* Line 1122, Address: 0x1024f14 */
  pActwk->r_no0 = 6; /* Line 1123, Address: 0x1024f40 */
  ++pActwk->patno; /* Line 1124, Address: 0x1024f4c */
  return 1; /* Line 1125, Address: 0x1024f5c */
} /* Line 1126, Address: 0x1024f60 */




static int egg5meca2_esc(sprite_status* pActwk) { /* Line 1131, Address: 0x1024f80 */
  my_rideonchk(pActwk); /* Line 1132, Address: 0x1024f8c */
  ++pActwk->actfree[0]; /* Line 1133, Address: 0x1024f98 */
  if (pActwk->actfree[0] == 60) /* Line 1134, Address: 0x1024fa8 */
  {

    pActwk->actfree[0] = 0; /* Line 1137, Address: 0x1024fc0 */
    pActwk->actfree[1] = 0; /* Line 1138, Address: 0x1024fc8 */
    pActwk->r_no0 = 12; /* Line 1139, Address: 0x1024fd0 */




    return 1; /* Line 1144, Address: 0x1024fdc */
  }

  if (pActwk->actfree[0] % 18 == 0) /* Line 1147, Address: 0x1024fe8 */
    make_hibana2(pActwk); /* Line 1148, Address: 0x1025008 */
  return 1; /* Line 1149, Address: 0x1025014 */
} /* Line 1150, Address: 0x1025018 */




static int egg5meca2_end(sprite_status* pActwk) { /* Line 1155, Address: 0x1025030 */
  if (pActwk->actfree[0] >= 120) /* Line 1156, Address: 0x102503c */
  {

    pActwk->actfree[2] |= 8; /* Line 1159, Address: 0x1025054 */
    return 1; /* Line 1160, Address: 0x1025064 */
  }
  my_rideonchk(pActwk); /* Line 1162, Address: 0x1025070 */
  ++pActwk->actfree[0]; /* Line 1163, Address: 0x102507c */
  bom_set(pActwk); /* Line 1164, Address: 0x102508c */
  if (!(pActwk->actfree[0] & 2)) /* Line 1165, Address: 0x1025098 */
  {

    pActwk->actfree[2] |= 8; /* Line 1168, Address: 0x10250b0 */
    return 1; /* Line 1169, Address: 0x10250c0 */
  }

  pActwk->actfree[2] &= 247; /* Line 1172, Address: 0x10250cc */
  return 1; /* Line 1173, Address: 0x10250dc */
} /* Line 1174, Address: 0x10250e0 */


static void my_rideonchk(sprite_status* pActwk) { /* Line 1177, Address: 0x10250f0 */
  ride_on_chk(pActwk, &actwk[0]); /* Line 1178, Address: 0x10250fc */
} /* Line 1179, Address: 0x1025110 */







void egg5meca3(sprite_status* pActwk) { /* Line 1187, Address: 0x1025120 */
  short subact;
  static void(*act_tbl[2])(sprite_status*) =
  {
    &egg5meca3_ini,
    &egg5meca3_1
  };


  act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1196, Address: 0x1025130 */
  subact = ((short*)pActwk)[25]; /* Line 1197, Address: 0x1025174 */
  if (!(actwk[subact].actfree[2] & 8)) /* Line 1198, Address: 0x1025184 */
    actionsub(pActwk); /* Line 1199, Address: 0x10251b8 */
} /* Line 1200, Address: 0x10251c4 */


static void egg5meca3_ini(sprite_status* pActwk) { /* Line 1203, Address: 0x10251e0 */
  pActwk->r_no0 += 2; /* Line 1204, Address: 0x10251ec */
  pActwk->actflg = 4; /* Line 1205, Address: 0x10251fc */
  pActwk->sprpri = 5; /* Line 1206, Address: 0x1025208 */
  pActwk->sprhsize = 16; /* Line 1207, Address: 0x1025214 */
  pActwk->sprvsize = 16; /* Line 1208, Address: 0x1025220 */
  pActwk->sproffset = 8892; /* Line 1209, Address: 0x102522c */
  pActwk->patbase = egg5meca3_pat; /* Line 1210, Address: 0x1025238 */
  egg5meca3_1(pActwk); /* Line 1211, Address: 0x1025248 */
} /* Line 1212, Address: 0x1025254 */


static void egg5meca3_1(sprite_status* pActwk) { /* Line 1215, Address: 0x1025270 */
  short subact;

  subact = ((short*)pActwk)[25]; /* Line 1218, Address: 0x102527c */
  pActwk->xposi.w.h = actwk[subact].xposi.w.h; /* Line 1219, Address: 0x102528c */
  pActwk->yposi.w.h = actwk[subact].yposi.w.h; /* Line 1220, Address: 0x10252b8 */
} /* Line 1221, Address: 0x10252e4 */







void egg5pipe(sprite_status* pActwk) { /* Line 1229, Address: 0x1025300 */
  short subact;
  static void(*act_tbl[2])(sprite_status*) =
  {
    &egg5pipe_ini,
    &egg5pipe_1
  };


  act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1238, Address: 0x1025310 */
  subact = ((short*)pActwk)[25]; /* Line 1239, Address: 0x1025354 */
  if (!(actwk[subact].actfree[2] & 8)) /* Line 1240, Address: 0x1025364 */
    actionsub(pActwk); /* Line 1241, Address: 0x1025398 */
} /* Line 1242, Address: 0x10253a4 */


static void egg5pipe_ini(sprite_status* pActwk) { /* Line 1245, Address: 0x10253c0 */
  pActwk->r_no0 += 2; /* Line 1246, Address: 0x10253cc */
  pActwk->actflg = 4; /* Line 1247, Address: 0x10253dc */
  pActwk->sprpri = 4; /* Line 1248, Address: 0x10253e8 */
  pActwk->sprhsize = 8; /* Line 1249, Address: 0x10253f4 */
  pActwk->sprvsize = 48; /* Line 1250, Address: 0x1025400 */
  pActwk->sproffset = 8892; /* Line 1251, Address: 0x102540c */
  pActwk->patbase = egg5pipe_pat; /* Line 1252, Address: 0x1025418 */
  egg5pipe_1(pActwk); /* Line 1253, Address: 0x1025428 */
} /* Line 1254, Address: 0x1025434 */


static void egg5pipe_1(sprite_status* pActwk) { /* Line 1257, Address: 0x1025450 */
  short subact;
  short temp;

  subact = ((short*)pActwk)[25]; /* Line 1261, Address: 0x1025460 */
  temp = (actwk[subact].yposi.w.h - pActwk->yposi.w.h) / 32; /* Line 1262, Address: 0x1025470 */
  temp &= 255; /* Line 1263, Address: 0x10254d8 */
  pActwk->patno = temp; /* Line 1264, Address: 0x10254e4 */
} /* Line 1265, Address: 0x10254f0 */







void egg5catch(sprite_status* pActwk) { /* Line 1273, Address: 0x1025510 */
  static int(*act_tbl[7])(sprite_status*) =
  {
    &egg5catch_ini,
    &egg5catch_1st,
    &egg5catch_return,
    &egg5catch_wait,
    &egg5catch_go1,
    &egg5catch_go2,
    egg5catch_fire
  };

  if (act_tbl[pActwk->r_no0 / 2](pActwk) != 0) /* Line 1285, Address: 0x102551c */
  {
    patchg(pActwk, egg5catch_pchg); /* Line 1287, Address: 0x1025568 */
    actionsub(pActwk); /* Line 1288, Address: 0x102557c */
  } /* Line 1289, Address: 0x1025588 */
  else
    frameout(pActwk); /* Line 1291, Address: 0x1025590 */
} /* Line 1292, Address: 0x102559c */


static int egg5catch_ini(sprite_status* pActwk) { /* Line 1295, Address: 0x10255b0 */
  int ret;

  pActwk->r_no0 += 2; /* Line 1298, Address: 0x10255c0 */
  pActwk->actflg = 4; /* Line 1299, Address: 0x10255d0 */
  pActwk->sprpri = 4; /* Line 1300, Address: 0x10255dc */
  pActwk->sprhsize = 16; /* Line 1301, Address: 0x10255e8 */
  pActwk->sprvsize = 12; /* Line 1302, Address: 0x10255f4 */
  pActwk->sproffset = 700; /* Line 1303, Address: 0x1025600 */
  pActwk->patbase = egg5catch_pat; /* Line 1304, Address: 0x102560c */
  ret = egg5catch_1st(pActwk); /* Line 1305, Address: 0x102561c */
  return ret; /* Line 1306, Address: 0x102562c */
} /* Line 1307, Address: 0x1025630 */



static int egg5catch_1st(sprite_status* pActwk) { /* Line 1311, Address: 0x1025650 */
  short subact;
  int ret = 1; /* Line 1313, Address: 0x1025664 */

  subact = ((short*)pActwk)[25]; /* Line 1315, Address: 0x1025668 */
  subact = ((short*)&actwk[subact])[25]; /* Line 1316, Address: 0x1025678 */
  if (actwk[subact].r_no0 != 2) /* Line 1317, Address: 0x10256a4 */
  {

    pActwk->r_no0 = 4; /* Line 1320, Address: 0x10256d8 */
    ret = egg5catch_return(pActwk); /* Line 1321, Address: 0x10256e4 */
  }
  return ret; /* Line 1323, Address: 0x10256f4 */
} /* Line 1324, Address: 0x10256f8 */



static int egg5catch_return(sprite_status* pActwk) { /* Line 1328, Address: 0x1025710 */
  if (pActwk->xposi.w.h < 3520) /* Line 1329, Address: 0x1025718 */
    pActwk->xposi.l += 122880; /* Line 1330, Address: 0x1025734 */
  else
    pActwk->r_no0 = 6; /* Line 1332, Address: 0x1025754 */
  return 1; /* Line 1333, Address: 0x1025760 */
} /* Line 1334, Address: 0x1025764 */



static int egg5catch_wait(sprite_status* pActwk) { /* Line 1338, Address: 0x1025770 */
  short subact;
  int ret = 1; /* Line 1340, Address: 0x1025784 */

  subact = ((short*)pActwk)[25]; /* Line 1342, Address: 0x1025788 */
  subact = ((short*)&actwk[subact])[25]; /* Line 1343, Address: 0x1025798 */
  if (((short*)&actwk[subact])[33] <= 210) /* Line 1344, Address: 0x10257c4 */
    ret = 0; /* Line 1345, Address: 0x10257fc */
  else
  {
    ++pActwk->actfree[0]; /* Line 1348, Address: 0x1025808 */
    if (pActwk->actfree[0] == 180) /* Line 1349, Address: 0x1025818 */
    {

      pActwk->actfree[0] = 0; /* Line 1352, Address: 0x1025830 */
      soundset(203); /* Line 1353, Address: 0x1025838 */
      pActwk->r_no0 = 8; /* Line 1354, Address: 0x1025844 */
      lever_on(pActwk); /* Line 1355, Address: 0x1025850 */
      make_bomb(pActwk); /* Line 1356, Address: 0x102585c */
      chg_mstno(1, pActwk); /* Line 1357, Address: 0x1025868 */
    }
  }
  return ret; /* Line 1360, Address: 0x1025878 */
} /* Line 1361, Address: 0x102587c */



static int egg5catch_go1(sprite_status* pActwk) { /* Line 1365, Address: 0x10258a0 */
  pActwk->xposi.l -= 49152; /* Line 1366, Address: 0x10258a8 */
  if (pActwk->xposi.w.h <= 3488) /* Line 1367, Address: 0x10258bc */
    pActwk->r_no0 = 10; /* Line 1368, Address: 0x10258d8 */
  return 1; /* Line 1369, Address: 0x10258e4 */
} /* Line 1370, Address: 0x10258e8 */



static int egg5catch_go2(sprite_status* pActwk) { /* Line 1374, Address: 0x1025900 */
  if (actwk[0].xposi.w.h < pActwk->xposi.w.h) /* Line 1375, Address: 0x102590c */
  {
    if (pActwk->xposi.w.h > 3296) /* Line 1377, Address: 0x1025938 */
    {
      pActwk->xposi.l -= 49152; /* Line 1379, Address: 0x1025954 */
      return 1; /* Line 1380, Address: 0x1025968 */
    }
  }




  soundset(196); /* Line 1387, Address: 0x1025974 */
  lever_off(pActwk); /* Line 1388, Address: 0x1025980 */
  pActwk->r_no0 = 12; /* Line 1389, Address: 0x102598c */
  return 1; /* Line 1390, Address: 0x1025998 */
} /* Line 1391, Address: 0x102599c */



static int egg5catch_fire(sprite_status* pActwk) { /* Line 1395, Address: 0x10259b0 */
  ++pActwk->actfree[0]; /* Line 1396, Address: 0x10259bc */
  if (pActwk->actfree[0] == 30) /* Line 1397, Address: 0x10259cc */
  {

    lever_on(pActwk); /* Line 1400, Address: 0x10259e4 */
    pActwk->actfree[2] |= 64; /* Line 1401, Address: 0x10259f0 */
    chg_mstno(0, pActwk); /* Line 1402, Address: 0x1025a00 */
    return 1; /* Line 1403, Address: 0x1025a10 */
  }
  if (pActwk->actfree[0] == 120) /* Line 1405, Address: 0x1025a1c */
  {

    pActwk->actfree[0] = 0; /* Line 1408, Address: 0x1025a34 */
    pActwk->r_no0 = 4; /* Line 1409, Address: 0x1025a3c */
    lever_off(pActwk); /* Line 1410, Address: 0x1025a48 */
  }
  return 1; /* Line 1412, Address: 0x1025a54 */
} /* Line 1413, Address: 0x1025a58 */


static void lever_on(sprite_status* pActwk) { /* Line 1416, Address: 0x1025a70 */
  short subact;

  subact = ((short*)pActwk)[25]; /* Line 1419, Address: 0x1025a80 */
  if (!actwk[subact].mstno.b.h) /* Line 1420, Address: 0x1025a90 */
  {
    chg_mstno2(0, subact); /* Line 1422, Address: 0x1025abc */
    actwk[subact].patno = 1; /* Line 1423, Address: 0x1025acc */
  }
} /* Line 1425, Address: 0x1025af4 */


static void lever_off(sprite_status* pActwk) { /* Line 1428, Address: 0x1025b10 */
  short subact;

  subact = ((short*)pActwk)[25]; /* Line 1431, Address: 0x1025b20 */
  if (!actwk[subact].mstno.b.h) /* Line 1432, Address: 0x1025b30 */
  {
    chg_mstno2(0, subact); /* Line 1434, Address: 0x1025b5c */
    actwk[subact].patno = 0; /* Line 1435, Address: 0x1025b6c */
  }
} /* Line 1437, Address: 0x1025b90 */







void egg5bomb(sprite_status* pActwk) { /* Line 1445, Address: 0x1025bb0 */
  int ret;
  static int(*act_tbl[5])(sprite_status*) =
  {
    &egg5bomb_ini,
    &egg5bomb_1,
    &egg5bomb_2,
    &egg5bomb_3,
    &egg5bomb_4
  };


  ret = act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1457, Address: 0x1025bc0 */
  if (ret != 0) /* Line 1458, Address: 0x1025c08 */
  {
    if (ret != 99) /* Line 1460, Address: 0x1025c10 */
      actionsub(pActwk); /* Line 1461, Address: 0x1025c1c */
  } /* Line 1462, Address: 0x1025c28 */
  else
    frameout(pActwk); /* Line 1464, Address: 0x1025c30 */
} /* Line 1465, Address: 0x1025c3c */


static int egg5bomb_ini(sprite_status* pActwk) { /* Line 1468, Address: 0x1025c50 */
  int ret;

  pActwk->r_no0 += 2; /* Line 1471, Address: 0x1025c60 */
  pActwk->actflg = 4; /* Line 1472, Address: 0x1025c70 */
  pActwk->sprpri = 4; /* Line 1473, Address: 0x1025c7c */
  pActwk->sprhsize = 12; /* Line 1474, Address: 0x1025c88 */
  pActwk->sprvsize = 12; /* Line 1475, Address: 0x1025c94 */
  pActwk->sproffset = 8892; /* Line 1476, Address: 0x1025ca0 */
  pActwk->patbase = egg5bomb_pat; /* Line 1477, Address: 0x1025cac */
  pActwk->colino = 253; /* Line 1478, Address: 0x1025cbc */
  pActwk->colicnt = 2; /* Line 1479, Address: 0x1025cc8 */
  ((short*)pActwk)[30] = -3; /* Line 1480, Address: 0x1025cd4 */
  ((unsigned short*)pActwk)[27] = 49152; /* Line 1481, Address: 0x1025ce0 */
  ret = egg5bomb_1(pActwk); /* Line 1482, Address: 0x1025cec */
  return ret; /* Line 1483, Address: 0x1025cfc */
} /* Line 1484, Address: 0x1025d00 */



static int egg5bomb_1(sprite_status* pActwk) { /* Line 1488, Address: 0x1025d20 */
  short subact;
  int ret = 1; /* Line 1490, Address: 0x1025d34 */

  subact = ((short*)pActwk)[25]; /* Line 1492, Address: 0x1025d38 */
  pActwk->xposi.w.h = actwk[subact].xposi.w.h; /* Line 1493, Address: 0x1025d48 */
  if (actwk[subact].r_no0 == 10) /* Line 1494, Address: 0x1025d74 */
  {
    pActwk->r_no0 += 2; /* Line 1496, Address: 0x1025da8 */
    ret = egg5bomb_2(pActwk); /* Line 1497, Address: 0x1025db8 */
  }
  return ret; /* Line 1499, Address: 0x1025dc8 */
} /* Line 1500, Address: 0x1025dcc */



static int egg5bomb_2(sprite_status* pActwk) { /* Line 1504, Address: 0x1025df0 */
  short subact;
  short sin, cos;
  int temp;
  int ret = 1; /* Line 1508, Address: 0x1025e08 */

  subact = ((short*)pActwk)[25]; /* Line 1510, Address: 0x1025e0c */
  pActwk->xposi.w.h = actwk[subact].xposi.w.h; /* Line 1511, Address: 0x1025e1c */
  if (actwk[subact].actfree[2] & 64) /* Line 1512, Address: 0x1025e48 */
  {
    actwk[subact].actfree[2] &= 191; /* Line 1514, Address: 0x1025e7c */

    pActwk->r_no0 += 2; /* Line 1516, Address: 0x1025ea8 */
    ret = egg5bomb_3(pActwk); /* Line 1517, Address: 0x1025eb8 */
  } /* Line 1518, Address: 0x1025ec8 */
  else
  {
    actwk[subact].actfree[2] &= 191; /* Line 1521, Address: 0x1025ed0 */
    pActwk->yposi.w.h -= ((short*)pActwk)[30]; /* Line 1522, Address: 0x1025efc */
    ((unsigned short*)pActwk)[27] += 1152; /* Line 1523, Address: 0x1025f14 */
    sinset(pActwk->actfree[9], &sin, &cos); /* Line 1524, Address: 0x1025f24 */
    temp = sin; /* Line 1525, Address: 0x1025f3c */

    temp *= 3; /* Line 1527, Address: 0x1025f48 */
    temp >>= 8; /* Line 1528, Address: 0x1025f50 */
    sin = (unsigned short)temp; /* Line 1529, Address: 0x1025f54 */
    ((short*)pActwk)[30] = sin; /* Line 1530, Address: 0x1025f64 */
    pActwk->yposi.w.h += sin; /* Line 1531, Address: 0x1025f70 */
  }
  return ret; /* Line 1533, Address: 0x1025f84 */
} /* Line 1534, Address: 0x1025f88 */



static int egg5bomb_3(sprite_status* pActwk) { /* Line 1538, Address: 0x1025fb0 */
  short subact;
  int ret = 1; /* Line 1540, Address: 0x1025fc4 */

  if (pActwk->colicnt > 2) /* Line 1542, Address: 0x1025fc8 */
    ret = egg5bomb_hit(pActwk); /* Line 1543, Address: 0x1025fe0 */
  else
  {
    subact = ((short*)pActwk)[25]; /* Line 1546, Address: 0x1025ff8 */
    if (actwk[subact].actfree[2] & 4) /* Line 1547, Address: 0x1026008 */
      ret = 0; /* Line 1548, Address: 0x102603c */
    else
    {
      pActwk->yposi.l += 139264; /* Line 1551, Address: 0x1026048 */
      if (pActwk->yposi.w.h >= 696) /* Line 1552, Address: 0x1026060 */
      {

        soundset(180); /* Line 1555, Address: 0x102607c */
        ret = egg5bomb_4(pActwk); /* Line 1556, Address: 0x1026088 */
      }
    }
  }
  return ret; /* Line 1560, Address: 0x1026098 */
} /* Line 1561, Address: 0x102609c */



static int egg5bomb_4(sprite_status* pActwk) { /* Line 1565, Address: 0x10260c0 */
  short subact;
  int ret = 1; /* Line 1567, Address: 0x10260d4 */

  if (pActwk->colicnt > 2) /* Line 1569, Address: 0x10260d8 */
    ret = egg5bomb_hit(pActwk); /* Line 1570, Address: 0x10260f0 */
  else
  {
    subact = ((short*)pActwk)[25]; /* Line 1573, Address: 0x1026108 */
    if (actwk[subact].actfree[2] & 4) /* Line 1574, Address: 0x1026118 */
      ret = 0; /* Line 1575, Address: 0x102614c */
    else
    {
      ++pActwk->actfree[0]; /* Line 1578, Address: 0x1026158 */
      if (pActwk->actfree[0] == 8) /* Line 1579, Address: 0x1026168 */
      {

        make_bomb2(pActwk); /* Line 1582, Address: 0x1026180 */
        ret = 0; /* Line 1583, Address: 0x102618c */
      }
    }
  }
  return ret; /* Line 1587, Address: 0x1026190 */
} /* Line 1588, Address: 0x1026194 */







void egg5bomb2(sprite_status* pActwk) { /* Line 1596, Address: 0x10261b0 */
  int ret;
  static int(*act_tbl[3])(sprite_status*) =
  {
    &egg5bomb2_ini,
    &egg5bomb2_1,
    &egg5bomb2_2
  };


  ret = act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1606, Address: 0x10261c0 */
  if (ret != 0) /* Line 1607, Address: 0x1026208 */
  {
    if (ret != 99) /* Line 1609, Address: 0x1026210 */
      actionsub(pActwk); /* Line 1610, Address: 0x102621c */
  } /* Line 1611, Address: 0x1026228 */
  else
    frameout(pActwk); /* Line 1613, Address: 0x1026230 */
} /* Line 1614, Address: 0x102623c */














static int egg5bomb2_ini(sprite_status* pActwk) { /* Line 1629, Address: 0x1026250 */
  int ret;
  short wD0;

  pActwk->r_no0 += 2; /* Line 1633, Address: 0x1026264 */
  pActwk->actflg = 4; /* Line 1634, Address: 0x1026274 */
  pActwk->sprpri = 1; /* Line 1635, Address: 0x1026280 */
  pActwk->sprhsize = 8; /* Line 1636, Address: 0x102628c */
  pActwk->sprvsize = 8; /* Line 1637, Address: 0x1026298 */
  pActwk->sproffset = 8892; /* Line 1638, Address: 0x10262a4 */
  pActwk->patbase = egg5bomb_pat; /* Line 1639, Address: 0x10262b0 */
  pActwk->colino = 253; /* Line 1640, Address: 0x10262c0 */
  pActwk->colicnt = 2; /* Line 1641, Address: 0x10262cc */
  pActwk->patno = 1; /* Line 1642, Address: 0x10262d8 */

  wD0 = pActwk->userflag.b.h; /* Line 1644, Address: 0x10262e4 */
  wD0 *= 6; /* Line 1645, Address: 0x10262fc */
  pActwk->xposi.w.h += bomb2_tbl[wD0++]; /* Line 1646, Address: 0x1026310 */
  pActwk->yposi.w.h += bomb2_tbl[wD0++]; /* Line 1647, Address: 0x1026354 */
  *(int*)&pActwk->actfree[16] = bomb2_tbl[wD0++]; /* Line 1648, Address: 0x1026398 */
  ((int*)pActwk)[4] = bomb2_tbl[wD0]; /* Line 1649, Address: 0x10263d0 */

  ret = egg5bomb2_1(pActwk); /* Line 1651, Address: 0x10263f4 */
  return ret; /* Line 1652, Address: 0x1026404 */
} /* Line 1653, Address: 0x1026408 */


static int egg5bomb2_1(sprite_status* pActwk) { /* Line 1656, Address: 0x1026420 */
  int ret = 1; /* Line 1657, Address: 0x1026430 */

  if (pActwk->colicnt > 2) /* Line 1659, Address: 0x1026434 */
    ret = egg5bomb_hit(pActwk); /* Line 1660, Address: 0x102644c */
  else
  {
    ++pActwk->actfree[0]; /* Line 1663, Address: 0x1026464 */
    if (pActwk->actfree[0] == 4) /* Line 1664, Address: 0x1026474 */
    {

      pActwk->actfree[0] = 0; /* Line 1667, Address: 0x102648c */
      pActwk->r_no0 += 2; /* Line 1668, Address: 0x1026494 */
      ret = egg5bomb2_2(pActwk); /* Line 1669, Address: 0x10264a4 */
    }
  }
  return ret; /* Line 1672, Address: 0x10264b4 */
} /* Line 1673, Address: 0x10264b8 */


static int egg5bomb2_2(sprite_status* pActwk) { /* Line 1676, Address: 0x10264d0 */
  short subact;
  int ret = 1; /* Line 1678, Address: 0x10264e8 */
  short wD0;

  if (pActwk->colicnt > 2) /* Line 1681, Address: 0x10264ec */
    ret = egg5bomb_hit(pActwk); /* Line 1682, Address: 0x1026504 */
  else
  {
    subact = ((short*)pActwk)[25]; /* Line 1685, Address: 0x102651c */
    if (actwk[subact].actfree[2] & 4) /* Line 1686, Address: 0x102652c */
      ret = 0; /* Line 1687, Address: 0x1026560 */
    else
    {
      pActwk->xposi.l += *(int*)&pActwk->actfree[16]; /* Line 1690, Address: 0x102656c */
      pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 1691, Address: 0x1026588 */
      wD0 = pActwk->userflag.b.h; /* Line 1692, Address: 0x10265a0 */
      wD0 *= 6; /* Line 1693, Address: 0x10265b8 */
      wD0 += 4; /* Line 1694, Address: 0x10265cc */
      *(int*)&pActwk->actfree[16] += bomb2_tbl[wD0++]; /* Line 1695, Address: 0x10265d8 */
      ((int*)pActwk)[4] += bomb2_tbl[wD0]; /* Line 1696, Address: 0x102661c */

      if (pActwk->yposi.w.h >= 712) /* Line 1698, Address: 0x1026648 */
        ret = 0; /* Line 1699, Address: 0x1026664 */
      if (!pActwk->colino) /* Line 1700, Address: 0x1026668 */
        ret = 0; /* Line 1701, Address: 0x1026678 */
    }
  }
  return ret; /* Line 1704, Address: 0x102667c */
} /* Line 1705, Address: 0x1026680 */


static int egg5bomb_hit(sprite_status* pActwk) { /* Line 1708, Address: 0x10266a0 */
  short xback, yback;

  xback = pActwk->xposi.w.h; /* Line 1711, Address: 0x10266b4 */
  yback = pActwk->yposi.w.h; /* Line 1712, Address: 0x10266c4 */
  frameout(pActwk); /* Line 1713, Address: 0x10266d4 */
  pActwk->r_no1 = 255; /* Line 1714, Address: 0x10266e0 */
  pActwk->actno = 24; /* Line 1715, Address: 0x10266ec */
  pActwk->xposi.w.h = xback; /* Line 1716, Address: 0x10266f8 */
  pActwk->yposi.w.h = yback; /* Line 1717, Address: 0x1026700 */
  soundset(158); /* Line 1718, Address: 0x1026708 */
  return 99; /* Line 1719, Address: 0x1026714 */
} /* Line 1720, Address: 0x1026718 */







void egg5hibana(sprite_status* pActwk) { /* Line 1728, Address: 0x1026730 */
  static int(*act_tbl[3])(sprite_status*) =
  {
    &egg5hibana_ini,
    &egg5hibana_1,
    &egg5hibana_2
  };

  if (act_tbl[pActwk->r_no0 / 2](pActwk) != 0) /* Line 1736, Address: 0x102673c */
  {
    patchg(pActwk, egg5hibana_pchg); /* Line 1738, Address: 0x1026788 */
    actionsub(pActwk); /* Line 1739, Address: 0x102679c */
  } /* Line 1740, Address: 0x10267a8 */
  else
    frameout(pActwk); /* Line 1742, Address: 0x10267b0 */
} /* Line 1743, Address: 0x10267bc */


static int egg5hibana_ini(sprite_status* pActwk) { /* Line 1746, Address: 0x10267d0 */
  int ret;

  pActwk->r_no0 += 2; /* Line 1749, Address: 0x10267e0 */
  pActwk->actflg = 4; /* Line 1750, Address: 0x10267f0 */
  pActwk->sprpri = 2; /* Line 1751, Address: 0x10267fc */
  pActwk->sprhsize = 8; /* Line 1752, Address: 0x1026808 */
  pActwk->sprvsize = 4; /* Line 1753, Address: 0x1026814 */
  pActwk->sproffset = 8892; /* Line 1754, Address: 0x1026820 */
  pActwk->patbase = egg5hibana_pat; /* Line 1755, Address: 0x102682c */
  *(int*)&pActwk->actfree[16] = -131072; /* Line 1756, Address: 0x102683c */
  ((int*)pActwk)[4] = -131072; /* Line 1757, Address: 0x102684c */
  if (!pActwk->actfree[3]) /* Line 1758, Address: 0x1026858 */
    ret = egg5hibana_1(pActwk); /* Line 1759, Address: 0x1026868 */
  else
  {
    pActwk->r_no0 += 2; /* Line 1762, Address: 0x1026880 */
    ret = egg5hibana_2(pActwk); /* Line 1763, Address: 0x1026890 */
  }
  return ret; /* Line 1765, Address: 0x10268a0 */
} /* Line 1766, Address: 0x10268a4 */



static int egg5hibana_1(sprite_status* pActwk) { /* Line 1770, Address: 0x10268c0 */
  int ret = 1; /* Line 1771, Address: 0x10268d0 */

  *(int*)&pActwk->actfree[16] -= 4096; /* Line 1773, Address: 0x10268d4 */
  pActwk->xposi.l += *(int*)&pActwk->actfree[16]; /* Line 1774, Address: 0x10268ec */
  if (pActwk->xposi.w.h <= 3448) /* Line 1775, Address: 0x1026908 */
    ret = 0; /* Line 1776, Address: 0x1026924 */
  else
    ret = hibana_delchk(pActwk); /* Line 1778, Address: 0x1026930 */
  return ret; /* Line 1779, Address: 0x1026940 */
} /* Line 1780, Address: 0x1026944 */



static int egg5hibana_2(sprite_status* pActwk) { /* Line 1784, Address: 0x1026960 */
  int ret;

  *(int*)&pActwk->actfree[16] -= 4096; /* Line 1787, Address: 0x1026970 */
  ((int*)pActwk)[4] += 8192; /* Line 1788, Address: 0x1026988 */
  pActwk->xposi.l += *(int*)&pActwk->actfree[16]; /* Line 1789, Address: 0x1026998 */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 1790, Address: 0x10269b4 */
  ret = hibana_delchk(pActwk); /* Line 1791, Address: 0x10269cc */
  return ret; /* Line 1792, Address: 0x10269dc */
} /* Line 1793, Address: 0x10269e0 */


static int hibana_delchk(sprite_status* pActwk) { /* Line 1796, Address: 0x1026a00 */
  int ret = 1; /* Line 1797, Address: 0x1026a10 */

  if (frameout_chk(pActwk) != 0) /* Line 1799, Address: 0x1026a14 */
    ret = 0; /* Line 1800, Address: 0x1026a28 */
  return ret; /* Line 1801, Address: 0x1026a2c */
} /* Line 1802, Address: 0x1026a30 */





















void egg5hari(sprite_status* pActwk) { /* Line 1824, Address: 0x1026a50 */
  static void(*act_tbl[5])(sprite_status*) =
  {
    &egg5hari_ini,
    &egg5hari_1,
    &egg5hari_2,
    &egg5hari_3,
    &egg5hari_4
  };

  act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1834, Address: 0x1026a5c */
  actionsub(pActwk); /* Line 1835, Address: 0x1026aa0 */
} /* Line 1836, Address: 0x1026aac */


static void egg5hari_ini(sprite_status* pActwk) { /* Line 1839, Address: 0x1026ac0 */
  pActwk->r_no0 += 2; /* Line 1840, Address: 0x1026acc */
  pActwk->actflg = 4; /* Line 1841, Address: 0x1026adc */
  pActwk->sprpri = 4; /* Line 1842, Address: 0x1026ae8 */
  pActwk->sprhsize = 32; /* Line 1843, Address: 0x1026af4 */
  pActwk->sprvsize = 32; /* Line 1844, Address: 0x1026b00 */
  pActwk->sproffset = 17084; /* Line 1845, Address: 0x1026b0c */
  pActwk->patbase = egg5hari_pat; /* Line 1846, Address: 0x1026b18 */
  pActwk->colino = 191; /* Line 1847, Address: 0x1026b28 */
  pActwk->colicnt = 2; /* Line 1848, Address: 0x1026b34 */
  egg5hari_1(pActwk); /* Line 1849, Address: 0x1026b40 */
} /* Line 1850, Address: 0x1026b4c */


static void egg5hari_1(sprite_status* pActwk) { /* Line 1853, Address: 0x1026b60 */
  if (actwk[0].xposi.w.h >= 3152) /* Line 1854, Address: 0x1026b6c */
  {

    divdevset(); /* Line 1857, Address: 0x1026b88 */
    pActwk->r_no0 += 2; /* Line 1858, Address: 0x1026b90 */
    egg5hari_2(pActwk); /* Line 1859, Address: 0x1026ba0 */
  }
} /* Line 1861, Address: 0x1026bac */


static void egg5hari_2(sprite_status* pActwk) { /* Line 1864, Address: 0x1026bc0 */
  pActwk->yposi.l -= 131072; /* Line 1865, Address: 0x1026bcc */
  if (pActwk->yposi.w.h > 672) /* Line 1866, Address: 0x1026be0 */
    egg5hari_chk(pActwk); /* Line 1867, Address: 0x1026bfc */
  else
  {

    pActwk->yposi.w.h = 672; /* Line 1871, Address: 0x1026c10 */
    pActwk->r_no0 += 2; /* Line 1872, Address: 0x1026c1c */
    egg5hari_3(pActwk); /* Line 1873, Address: 0x1026c2c */
  }
} /* Line 1875, Address: 0x1026c38 */


static void egg5hari_3(sprite_status* pActwk) { /* Line 1878, Address: 0x1026c50 */
  pActwk->xposi.l += 131072; /* Line 1879, Address: 0x1026c5c */
  if (pActwk->xposi.w.h < 3280) /* Line 1880, Address: 0x1026c70 */
    egg5hari_chk(pActwk); /* Line 1881, Address: 0x1026c8c */
  else
  {

    pActwk->r_no0 += 2; /* Line 1885, Address: 0x1026ca0 */
    pActwk->xposi.w.h = 3280; /* Line 1886, Address: 0x1026cb0 */
    egg5hari_4(pActwk); /* Line 1887, Address: 0x1026cbc */
  }
} /* Line 1889, Address: 0x1026cc8 */


static void egg5hari_4(sprite_status* pActwk) { /* Line 1892, Address: 0x1026ce0 */
  egg5hari_chk(pActwk); /* Line 1893, Address: 0x1026cec */
} /* Line 1894, Address: 0x1026cf8 */


static void egg5hari_chk(sprite_status* pActwk) { /* Line 1897, Address: 0x1026d10 */
  pActwk->sprhsize = 12; /* Line 1898, Address: 0x1026d1c */
  pActwk->sprvsize = 30; /* Line 1899, Address: 0x1026d28 */
  my_rideonchk(pActwk); /* Line 1900, Address: 0x1026d34 */
  pActwk->sprhsize = 32; /* Line 1901, Address: 0x1026d40 */
  pActwk->sprvsize = 32; /* Line 1902, Address: 0x1026d4c */
} /* Line 1903, Address: 0x1026d58 */







void egg5belt(sprite_status* pActwk) { /* Line 1911, Address: 0x1026d70 */
  static void(*act_tbl[5])(sprite_status*) =
  {
    &egg5belt_ini,
    &egg5belt_0,
    &egg5belt_1,
    &egg5belt_2,
    &egg5belt_3
  };

  act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1921, Address: 0x1026d7c */
  actionsub(pActwk); /* Line 1922, Address: 0x1026dc0 */
} /* Line 1923, Address: 0x1026dcc */


static void egg5belt_ini(sprite_status* pActwk) { /* Line 1926, Address: 0x1026de0 */
  pActwk->r_no0 += 2; /* Line 1927, Address: 0x1026dec */
  set_belt_col(pActwk); /* Line 1928, Address: 0x1026dfc */
} /* Line 1929, Address: 0x1026e08 */


static void egg5belt_0(sprite_status* pActwk) { /* Line 1932, Address: 0x1026e20 */
  short subact;

  subact = ((short*)pActwk)[25]; /* Line 1935, Address: 0x1026e30 */
  if (actwk[subact].r_no0 != 2) /* Line 1936, Address: 0x1026e40 */
  {

    pActwk->r_no0 += 2; /* Line 1939, Address: 0x1026e74 */
    egg5belt_1(pActwk); /* Line 1940, Address: 0x1026e84 */
  }
} /* Line 1942, Address: 0x1026e90 */



static void egg5belt_1(sprite_status* pActwk) { /* Line 1946, Address: 0x1026eb0 */
  short wD1 = 0; /* Line 1947, Address: 0x1026ec0 */

  ++pActwk->actfree[1]; /* Line 1949, Address: 0x1026ec4 */

  if (pActwk->actfree[1] & 1) /* Line 1951, Address: 0x1026ed4 */
    belt_anime(pActwk); /* Line 1952, Address: 0x1026eec */

  if (actwk[0].xposi.w.h > 3464) /* Line 1954, Address: 0x1026ef8 */
  {
    actwk[0].xposi.w.h -= 4; /* Line 1956, Address: 0x1026f14 */
    if (actwk[0].xspeed.w >= 0) /* Line 1957, Address: 0x1026f28 */
      actwk[0].xspeed.w = 0; /* Line 1958, Address: 0x1026f40 */
  } /* Line 1959, Address: 0x1026f48 */
  else
    ++wD1; /* Line 1961, Address: 0x1026f50 */








  if (wD1 == 1) /* Line 1970, Address: 0x1026f5c */
  {

    ((short*)pActwk)[27] = 192; /* Line 1973, Address: 0x1026f70 */
    pActwk->r_no0 += 2; /* Line 1974, Address: 0x1026f7c */
  }
} /* Line 1976, Address: 0x1026f8c */



static void egg5belt_2(sprite_status* pActwk) { /* Line 1980, Address: 0x1026fa0 */
  short subact;
  int wD6;

  subact = ((short*)pActwk)[25]; /* Line 1984, Address: 0x1026fb4 */
  if (actwk[subact].actfree[2] & 4) /* Line 1985, Address: 0x1026fc4 */
  {

    ((short*)pActwk)[27] -= 16; /* Line 1988, Address: 0x1026ff8 */
    if (((short*)pActwk)[27] <= 0) /* Line 1989, Address: 0x1027008 */
    {

      pActwk->r_no0 += 2; /* Line 1992, Address: 0x1027020 */

      return; /* Line 1994, Address: 0x1027030 */
    }
  }


  wD6 = chk_belt_on(); /* Line 1999, Address: 0x1027038 */
  if (!(actwk[subact].actfree[2] & 4)) /* Line 2000, Address: 0x1027044 */
    wD6 = belt_spdset(pActwk); /* Line 2001, Address: 0x1027078 */

  belt_sncspd(wD6, pActwk); /* Line 2003, Address: 0x1027088 */
  belt_sncxmax(subact); /* Line 2004, Address: 0x1027098 */




  belt_hitpnt(subact, pActwk); /* Line 2009, Address: 0x10270a4 */
  ++pActwk->actfree[1]; /* Line 2010, Address: 0x10270b4 */

  if (pActwk->actfree[1] & 1) /* Line 2012, Address: 0x10270c4 */
    belt_anime(pActwk); /* Line 2013, Address: 0x10270dc */
} /* Line 2014, Address: 0x10270e8 */


static void egg5belt_3(sprite_status* pActwk) { /* Line 2017, Address: 0x1027100 */

  pActwk + 1; /* Line 2019, Address: 0x1027108 */
} /* Line 2020, Address: 0x102710c */





static int belt_spdset(sprite_status* pActwk) { /* Line 2026, Address: 0x1027120 */
  int wD6;

  wD6 = chk_belt_on(); /* Line 2029, Address: 0x1027130 */
  if (wD6 <= 0) /* Line 2030, Address: 0x102713c */
  {
    if (wD6 == 0) /* Line 2032, Address: 0x1027144 */
    {
      if (actwk[0].xspeed.w < ((short*)pActwk)[27]) /* Line 2034, Address: 0x102714c */
      {


        ((short*)pActwk)[27] -= 7; /* Line 2038, Address: 0x1027178 */
        goto label1; /* Line 2039, Address: 0x1027188 */
      }

      if (actwk[0].xspeed.w != ((short*)pActwk)[27]) /* Line 2042, Address: 0x1027190 */
      {


        ((short*)pActwk)[27] += 8; /* Line 2046, Address: 0x10271b8 */
      }

      goto label1; /* Line 2049, Address: 0x10271c8 */
    }



    ((short*)pActwk)[27] = 192; /* Line 2054, Address: 0x10271d0 */

    goto label1; /* Line 2056, Address: 0x10271dc */
  }



  --((short*)pActwk)[27]; /* Line 2061, Address: 0x10271e4 */


label1:
  if (((short*)pActwk)[27] <= 192) /* Line 2065, Address: 0x10271f4 */
    ((short*)pActwk)[27] = 192; /* Line 2066, Address: 0x1027210 */
  else
  {

    if (((short*)pActwk)[27] >= 1488) /* Line 2070, Address: 0x1027224 */
      ((short*)pActwk)[27] = 1488; /* Line 2071, Address: 0x1027240 */
  }
  return wD6; /* Line 2073, Address: 0x102724c */
} /* Line 2074, Address: 0x1027250 */





static void belt_hitpnt(short subact, sprite_status* pActwk) { /* Line 2080, Address: 0x1027270 */
  ((short*)pActwk)[28] += ((short*)pActwk)[27]; /* Line 2081, Address: 0x102727c */
  if (((short*)pActwk)[28] >= 1488) /* Line 2082, Address: 0x1027294 */
  {

    --((short*)&actwk[subact])[33]; /* Line 2085, Address: 0x10272b0 */
    ((short*)pActwk)[28] -= 1488; /* Line 2086, Address: 0x10272e0 */
  }
} /* Line 2088, Address: 0x10272f0 */





static void belt_sncspd(int wD6, sprite_status* pActwk) { /* Line 2094, Address: 0x1027300 */
  int_union wD0;

  if (wD6 == 1) /* Line 2097, Address: 0x102730c */
  {


    if (!(pActwk->actfree[2] & 16)) /* Line 2101, Address: 0x102731c */
    {
      actwk[0].xspeed.w -= ((short*)pActwk)[29]; /* Line 2103, Address: 0x1027334 */
      actwk[0].yspeed.w -= ((short*)pActwk)[30]; /* Line 2104, Address: 0x1027350 */
    }
    pActwk->actfree[2] |= 16; /* Line 2106, Address: 0x102736c */
  } /* Line 2107, Address: 0x102737c */
  else
  {


    pActwk->actfree[2] &= 239; /* Line 2112, Address: 0x1027384 */
    ((short*)pActwk)[29] = actwk[0].xspeed.w; /* Line 2113, Address: 0x1027394 */
    ((short*)pActwk)[30] = actwk[0].yspeed.w; /* Line 2114, Address: 0x10273a4 */

    if (wD6 >= 0) /* Line 2116, Address: 0x10273b4 */
    {

      wD0.l = 0; /* Line 2119, Address: 0x10273c0 */
      wD0.w.l = ((short*)pActwk)[27]; /* Line 2120, Address: 0x10273c4 */



      if (wD0.w.l - actwk[0].xspeed.w > 768) /* Line 2124, Address: 0x10273d0 */
      {
        wD0.l = 0; /* Line 2126, Address: 0x10273fc */
        wD0.l = actwk[0].xspeed.w + 768; /* Line 2127, Address: 0x1027400 */
      }

      wD0.l <<= 8; /* Line 2130, Address: 0x1027418 */
      actwk[0].xposi.l -= wD0.l; /* Line 2131, Address: 0x1027424 */
    }
  }
} /* Line 2134, Address: 0x102743c */





static void belt_sncxmax(short subact) { /* Line 2140, Address: 0x1027450 */
  if (!(actwk[subact].actfree[2] & 4)) /* Line 2141, Address: 0x1027458 */
  {
    if (actwk[0].xposi.w.h >= 3464) /* Line 2143, Address: 0x1027490 */
      actwk[0].xposi.w.h = 3464; /* Line 2144, Address: 0x10274ac */
  }
} /* Line 2146, Address: 0x10274b8 */







static void belt_anime(sprite_status* pActwk) { /* Line 2154, Address: 0x10274d0 */
  unsigned char wD0;

  if (((short*)pActwk)[27] > 1024) /* Line 2157, Address: 0x10274e0 */
  {

    wD0 = 1; /* Line 2160, Address: 0x10274fc */
  } /* Line 2161, Address: 0x1027504 */
  else
  {
    if (((short*)pActwk)[27] > 768) /* Line 2164, Address: 0x102750c */
    {

      wD0 = 1; /* Line 2167, Address: 0x1027528 */
    } /* Line 2168, Address: 0x1027530 */
    else
    {
      if (((short*)pActwk)[27] > 512) /* Line 2171, Address: 0x1027538 */
      {

        wD0 = 2; /* Line 2174, Address: 0x1027554 */
      } /* Line 2175, Address: 0x102755c */
      else
      {

        wD0 = 4; /* Line 2179, Address: 0x1027564 */
      }
    }
  }

  ++pActwk->actfree[0]; /* Line 2184, Address: 0x102756c */
  if (wD0 <= pActwk->actfree[0]) /* Line 2185, Address: 0x102757c */
  {
    pActwk->actfree[0] = 0; /* Line 2187, Address: 0x1027598 */
    set_belt_col(pActwk); /* Line 2188, Address: 0x10275a0 */
  }
} /* Line 2190, Address: 0x10275ac */





static void set_belt_col(sprite_status* pActwk) { /* Line 2196, Address: 0x10275c0 */
  PALETTEENTRY* pColorwk;
  char bA3;
  PALETTEENTRY belt_col_tblD[9] = /* Line 2199, Address: 0x10275d0 */
  {
    { 224, 224, 192, 1 }, {  96,  96,  64, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224, 192, 1 },
    {  96,  96,  64, 1 }, {  96,  96,  64, 1 }, {   0,   0,   0, 1 }, { 224, 224, 192, 1 }
  };
  PALETTEENTRY belt_col_tblC[9] = /* Line 2204, Address: 0x1027604 */
  {
    {   0,  32,   0, 1 }, {   0, 128,   0, 1 }, {  32, 192,  96, 1 },
    {   0, 128,   0, 1 }, {  32, 192,  96, 1 }, {   0,  32,   0, 1 },
    {  32, 192,  96, 1 }, {   0,  32,   0, 1 }, {   0, 128,   0, 1 }
  };




  ((char*)pActwk)[66] += 3; /* Line 2214, Address: 0x1027638 */
  if (((char*)pActwk)[66] >= 9) /* Line 2215, Address: 0x1027648 */
    ((char*)pActwk)[66] = 0; /* Line 2216, Address: 0x1027664 */

  bA3 = ((char*)pActwk)[66]; /* Line 2218, Address: 0x102766c */
  pColorwk = &lpcolorwk[42]; /* Line 2219, Address: 0x102767c */
  if (!generate_flag) /* Line 2220, Address: 0x1027688 */
  {
    *pColorwk = belt_col_tblD[bA3]; /* Line 2222, Address: 0x1027698 */
    ++pColorwk; /* Line 2223, Address: 0x10276cc */
    ++bA3; /* Line 2224, Address: 0x10276d0 */
    *pColorwk = belt_col_tblD[bA3]; /* Line 2225, Address: 0x10276dc */
    ++pColorwk; /* Line 2226, Address: 0x1027710 */
    ++bA3; /* Line 2227, Address: 0x1027714 */
    *pColorwk = belt_col_tblD[bA3]; /* Line 2228, Address: 0x1027720 */
  } /* Line 2229, Address: 0x1027754 */
  else
  {
    *pColorwk = belt_col_tblC[bA3]; /* Line 2232, Address: 0x102775c */
    ++pColorwk; /* Line 2233, Address: 0x1027790 */
    ++bA3; /* Line 2234, Address: 0x1027794 */
    *pColorwk = belt_col_tblC[bA3]; /* Line 2235, Address: 0x10277a0 */
    ++pColorwk; /* Line 2236, Address: 0x10277d4 */
    ++bA3; /* Line 2237, Address: 0x10277d8 */
    *pColorwk = belt_col_tblC[bA3]; /* Line 2238, Address: 0x10277e4 */
  }
} /* Line 2240, Address: 0x1027818 */








static int chk_belt_on() {
  if (actwk[0].mstno.b.h != 26) /* Line 2250, Address: 0x1027830 */
  {
    if (actwk[0].mstno.b.h != 25) /* Line 2252, Address: 0x102784c */
    {
      if (actwk[0].mstno.b.h != 24) /* Line 2254, Address: 0x1027868 */
      {
        if (!(actwk[0].cddat & 128)) /* Line 2256, Address: 0x1027884 */
        {
          if (actwk[0].cddat & 2) /* Line 2258, Address: 0x102789c */
            return 1; /* Line 2259, Address: 0x10278b4 */
          else
            return 0; /* Line 2261, Address: 0x10278c0 */
        }
      }
    }
  }
  return -1; /* Line 2266, Address: 0x10278cc */
} /* Line 2267, Address: 0x10278d0 */





void egg5bakuha(sprite_status* pActwk) { /* Line 2273, Address: 0x10278e0 */
  static int(*act_tbl[3])(sprite_status*) =
  {
    &egg5bakuha_ini,
    &egg5bakuha_1,
    &frameout_sp4
  };

  if (act_tbl[pActwk->r_no0 / 2](pActwk) != 0) /* Line 2281, Address: 0x10278ec */
  {
    patchg(pActwk, egg5bakuha_pchg); /* Line 2283, Address: 0x1027938 */
    actionsub(pActwk); /* Line 2284, Address: 0x102794c */
  } /* Line 2285, Address: 0x1027958 */
  else
    frameout(pActwk); /* Line 2287, Address: 0x1027960 */
} /* Line 2288, Address: 0x102796c */


static int egg5bakuha_ini(sprite_status* pActwk) { /* Line 2291, Address: 0x1027980 */
  int ret;

  pActwk->r_no0 += 2; /* Line 2294, Address: 0x1027990 */
  pActwk->actflg = 4; /* Line 2295, Address: 0x10279a0 */
  pActwk->sprpri = 3; /* Line 2296, Address: 0x10279ac */
  pActwk->sprhsize = 16; /* Line 2297, Address: 0x10279b8 */
  pActwk->sprvsize = 16; /* Line 2298, Address: 0x10279c4 */
  pActwk->sproffset = 1664; /* Line 2299, Address: 0x10279d0 */
  pActwk->patbase = bakupat; /* Line 2300, Address: 0x10279dc */
  ret = egg5bakuha_1(pActwk); /* Line 2301, Address: 0x10279ec */
  return ret; /* Line 2302, Address: 0x10279fc */
} /* Line 2303, Address: 0x1027a00 */


static int egg5bakuha_1(sprite_status* pActwk) { /* Line 2306, Address: 0x1027a20 */
  pActwk->yposi.l -= 196608; /* Line 2307, Address: 0x1027a28 */
  return 1; /* Line 2308, Address: 0x1027a3c */
} /* Line 2309, Address: 0x1027a40 */


static int frameout_sp4(sprite_status* pActwk) { /* Line 2312, Address: 0x1027a50 */
  pActwk + 1; /* Line 2313, Address: 0x1027a58 */
  return 0; /* Line 2314, Address: 0x1027a5c */
} /* Line 2315, Address: 0x1027a60 */






void make_hibana1() { /* Line 2322, Address: 0x1027a70 */
  sprite_status* ppActwk;

  if (actwkchk(&ppActwk) == 0) /* Line 2325, Address: 0x1027a78 */
  {

    ppActwk->actno = 32; /* Line 2328, Address: 0x1027a8c */
    ppActwk->xposi.w.h = 3560; /* Line 2329, Address: 0x1027a98 */
    ppActwk->yposi.w.h = 696; /* Line 2330, Address: 0x1027aa4 */
  }
} /* Line 2332, Address: 0x1027ab0 */


void make_hibana2(sprite_status* pActwk) { /* Line 2335, Address: 0x1027ac0 */
  sprite_status* ppActwk;
  short wD4;
  int i, j;
  short hibana_tbl[16] = /* Line 2339, Address: 0x1027ad8 */
  {
    -24,  0,
     -6,  0,
      6,  0,
     24,  0,
    -12, -8,
     12, -8,
    -12,  8,
      12, 8
  };
  short hibana_ytbl[6] = /* Line 2350, Address: 0x1027b0c */
  {
    52,
    52,
    44,
    32,
    28,
    28
  };

  wD4 = hibana_ytbl[pActwk->patno]; /* Line 2360, Address: 0x1027b40 */
  j = 0; /* Line 2361, Address: 0x1027b60 */
  for (i = 0; i < 8; ++i) /* Line 2362, Address: 0x1027b64 */
  {
    if (actwkchk(&ppActwk) == 0) /* Line 2364, Address: 0x1027b70 */
    {
      ppActwk->actfree[3] = 1; /* Line 2366, Address: 0x1027b84 */
      ((short*)ppActwk)[25] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 2367, Address: 0x1027b90 */
      ppActwk->actno = 32; /* Line 2368, Address: 0x1027bd0 */
      ppActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 2369, Address: 0x1027bdc */
      ppActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 2370, Address: 0x1027bec */
      ppActwk->xposi.w.h += hibana_tbl[j++]; /* Line 2371, Address: 0x1027bfc */
      ppActwk->yposi.w.h += wD4 + hibana_tbl[j++]; /* Line 2372, Address: 0x1027c20 */
    } /* Line 2373, Address: 0x1027c60 */
    else
      i = 99; /* Line 2375, Address: 0x1027c68 */
  } /* Line 2376, Address: 0x1027c6c */
} /* Line 2377, Address: 0x1027c7c */






static void bom_set(sprite_status* pActwk) { /* Line 2384, Address: 0x1027ca0 */
  sprite_status* ppActwk;
  unsigned char wD2, wD3;
  short bom_tbl[8] = /* Line 2387, Address: 0x1027cb4 */
  {
    -16, -8,
    -32,  8,
    -16, 24,
     32, 8
  };


  if (pActwk->actfree[0] % 4 == 0) /* Line 2396, Address: 0x1027ce8 */
  {

    wD3 = pActwk->actfree[0]; /* Line 2399, Address: 0x1027d18 */
    wD3 /= 4; /* Line 2400, Address: 0x1027d24 */
    wD3 %= 4; /* Line 2401, Address: 0x1027d38 */
    wD2 = wD3 * 2; /* Line 2402, Address: 0x1027d4c */
    if (actwkchk(&ppActwk) == 0) /* Line 2403, Address: 0x1027d5c */
    {

      ppActwk->actfree[0] = wD3; /* Line 2406, Address: 0x1027d70 */
      ppActwk->actno = 35; /* Line 2407, Address: 0x1027d78 */
      ppActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 2408, Address: 0x1027d84 */
      ppActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 2409, Address: 0x1027d94 */
      ppActwk->xposi.w.h += bom_tbl[wD2++]; /* Line 2410, Address: 0x1027da4 */
      ppActwk->yposi.w.h += bom_tbl[wD2]; /* Line 2411, Address: 0x1027dd0 */
      soundset(158); /* Line 2412, Address: 0x1027df0 */
    }
  }
} /* Line 2415, Address: 0x1027dfc */


static void make_meca2(sprite_status* pActwk) { /* Line 2418, Address: 0x1027e20 */
  sprite_status* ppActwk;

  if (actwkchk(&ppActwk) == 0) /* Line 2421, Address: 0x1027e2c */
  {
    ((short*)ppActwk)[25] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 2423, Address: 0x1027e40 */
    ((short*)pActwk)[26] = (unsigned short)(unsigned char)(ppActwk - actwk); /* Line 2424, Address: 0x1027e80 */
    ppActwk->actno = 52; /* Line 2425, Address: 0x1027ec0 */
    ppActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 2426, Address: 0x1027ecc */
    ppActwk->yposi.w.h = pActwk->yposi.w.h + 56; /* Line 2427, Address: 0x1027edc */
  }
} /* Line 2429, Address: 0x1027f00 */


static void make_egg5(sprite_status* pActwk) { /* Line 2432, Address: 0x1027f10 */
  sprite_status* ppActwk;

  if (actwkchk(&ppActwk) == 0) /* Line 2435, Address: 0x1027f1c */
  {
    ((short*)ppActwk)[25] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 2437, Address: 0x1027f30 */
    ((short*)pActwk)[26] = (unsigned short)(unsigned char)(ppActwk - actwk); /* Line 2438, Address: 0x1027f70 */
    ppActwk->actno = 50; /* Line 2439, Address: 0x1027fb0 */
    ppActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 2440, Address: 0x1027fbc */
    ppActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 2441, Address: 0x1027fcc */
  }
} /* Line 2443, Address: 0x1027fdc */


static void make_catch(sprite_status* pActwk) { /* Line 2446, Address: 0x1027ff0 */
  sprite_status* ppActwk;

  if (actwkchk(&ppActwk) == 0) /* Line 2449, Address: 0x1027ffc */
  {
    ((short*)ppActwk)[25] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 2451, Address: 0x1028010 */
    ((short*)pActwk)[26] = (unsigned short)(unsigned char)(ppActwk - actwk); /* Line 2452, Address: 0x1028050 */
    ppActwk->actno = 55; /* Line 2453, Address: 0x1028090 */
    ppActwk->xposi.w.h = pActwk->xposi.w.h - 128; /* Line 2454, Address: 0x102809c */
    ppActwk->yposi.w.h = pActwk->yposi.w.h - 68; /* Line 2455, Address: 0x10280c0 */
  }
} /* Line 2457, Address: 0x10280e4 */


static void make_pipe(sprite_status* pActwk) { /* Line 2460, Address: 0x1028100 */
  sprite_status* ppActwk;

  if (actwkchk(&ppActwk) == 0) /* Line 2463, Address: 0x102810c */
  {
    ((short*)ppActwk)[25] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 2465, Address: 0x1028120 */
    ppActwk->actno = 54; /* Line 2466, Address: 0x1028160 */
    ppActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 2467, Address: 0x102816c */
    ppActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 2468, Address: 0x102817c */
  }
} /* Line 2470, Address: 0x102818c */


static void make_meca3(sprite_status* pActwk) { /* Line 2473, Address: 0x10281a0 */
  sprite_status* ppActwk;

  if (actwkchk(&ppActwk) == 0) /* Line 2476, Address: 0x10281ac */
  {
    ((short*)ppActwk)[25] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 2478, Address: 0x10281c0 */
    ppActwk->actno = 53; /* Line 2479, Address: 0x1028200 */
    ppActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 2480, Address: 0x102820c */
    ppActwk->yposi.w.h = pActwk->yposi.w.h + 56; /* Line 2481, Address: 0x102821c */
  }
} /* Line 2483, Address: 0x1028240 */


static void make_bomb(sprite_status* pActwk) { /* Line 2486, Address: 0x1028250 */
  sprite_status* ppActwk;

  if (actwkchk(&ppActwk) == 0) /* Line 2489, Address: 0x102825c */
  {
    ((short*)ppActwk)[25] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 2491, Address: 0x1028270 */
    ppActwk->actno = 56; /* Line 2492, Address: 0x10282b0 */
    ppActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 2493, Address: 0x10282bc */
    ppActwk->yposi.w.h = pActwk->yposi.w.h + 24; /* Line 2494, Address: 0x10282cc */
  }
} /* Line 2496, Address: 0x10282f0 */


static void make_bomb2(sprite_status* pActwk) { /* Line 2499, Address: 0x1028300 */
  sprite_status* ppActwk;
  int i;

  for (i = 3; i >= 0; --i) /* Line 2503, Address: 0x1028310 */
  {
    if (actwkchk(&ppActwk) == 0) /* Line 2505, Address: 0x102831c */
    {
      ((short*)ppActwk)[25] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 2507, Address: 0x1028330 */
      ppActwk->actno = 57; /* Line 2508, Address: 0x1028370 */
      ppActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 2509, Address: 0x102837c */
      ppActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 2510, Address: 0x102838c */
      ppActwk->userflag.b.h = i; /* Line 2511, Address: 0x102839c */
    } /* Line 2512, Address: 0x10283ac */
    else
      i = -99; /* Line 2514, Address: 0x10283b4 */
  } /* Line 2515, Address: 0x10283b8 */
} /* Line 2516, Address: 0x10283c4 */


static void make_belt(sprite_status* pActwk) { /* Line 2519, Address: 0x10283e0 */
  sprite_status* ppActwk;

  if (actwkchk(&ppActwk) == 0) /* Line 2522, Address: 0x10283ec */
  {
    ((short*)ppActwk)[25] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 2524, Address: 0x1028400 */
    ((short*)pActwk)[27] = (unsigned short)(unsigned char)(ppActwk - actwk); /* Line 2525, Address: 0x1028440 */
    ppActwk->actno = 34; /* Line 2526, Address: 0x1028480 */
  }
} /* Line 2528, Address: 0x102848c */









static void chg_mstno(unsigned char num, sprite_status* pActwk) { /* Line 2538, Address: 0x10284a0 */
  chg_mstno2(num, (unsigned short)(unsigned char)(pActwk - actwk)); /* Line 2539, Address: 0x10284b0 */
} /* Line 2540, Address: 0x10284f4 */

static void chg_mstno2(unsigned char num, short subact) { /* Line 2542, Address: 0x1028510 */
  actwk[subact].mstno.b.h = num; /* Line 2543, Address: 0x102851c */
  actwk[subact].patno = 0; /* Line 2544, Address: 0x1028548 */
  actwk[subact].patcnt = 0; /* Line 2545, Address: 0x1028570 */
  actwk[subact].pattim = 0; /* Line 2546, Address: 0x1028598 */
  actwk[subact].pattimm = 0; /* Line 2547, Address: 0x10285c0 */
} /* Line 2548, Address: 0x10285e8 */









static int frameout_chk(sprite_status* pActwk) { /* Line 2558, Address: 0x1028600 */
  int ret = -1; /* Line 2559, Address: 0x1028610 */
  short wD3;
  short_union wD0;



  wD0.w = 0; /* Line 2565, Address: 0x1028614 */
  pActwk->sprhsize = wD0.b.l; /* Line 2566, Address: 0x1028618 */
  wD3 = pActwk->xposi.w.h - scra_h_posit.w.h; /* Line 2567, Address: 0x1028624 */
  if (wD0.w + wD3 >= 0) /* Line 2568, Address: 0x1028658 */
  {
    if (wD3 - wD0.w < 320) /* Line 2570, Address: 0x1028678 */
    {
      wD0.w = 0; /* Line 2572, Address: 0x102869c */
      pActwk->sprvsize = wD0.b.l; /* Line 2573, Address: 0x10286a0 */
      wD3 = pActwk->yposi.w.h - scra_v_posit.w.h; /* Line 2574, Address: 0x10286ac */
      if (wD0.w + wD3 >= 0) /* Line 2575, Address: 0x10286e0 */
      {
        if (wD3 - wD0.w < 224) /* Line 2577, Address: 0x1028700 */
          ret = 0; /* Line 2578, Address: 0x1028724 */
      }
    }
  }
  return ret; /* Line 2582, Address: 0x1028728 */
} /* Line 2583, Address: 0x102872c */
