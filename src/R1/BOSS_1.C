#include "..\EQU.H"
#include "BOSS_1.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\ETC.H"
#include "..\GOAL.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SCORE.H"
#include "COL1C.H"

unsigned char egg1_pchg0[3] = { 59, 0, 255 };
unsigned char egg1_pchg1[4] = { 7, 2, 3, 255 };
unsigned char egg1_pchg2[6] = { 3, 1, 5, 4, 6, 255 };
unsigned char egg1_pchg3[4] = { 3, 7, 8, 255 };
unsigned char egg1_pchg4[4] = { 3, 9, 10, 255 };
unsigned char* egg1_pchg[5] =
{
  egg1_pchg0,
  egg1_pchg1,
  egg1_pchg2,
  egg1_pchg3,
  egg1_pchg4
};
sprite_pattern spr_egg1_pat0 =
{
  1,
  { { -28, -24, 0, 512 } }
};
sprite_pattern spr_egg1_pat1 =
{
  1,
  { { -28, -40, 0, 513 } }
};
sprite_pattern spr_egg1_pat2 =
{
  1,
  { { -28, -24, 0, 514 } }
};
sprite_pattern spr_egg1_pat3 =
{
  1,
  { { -28, -24, 0, 515 } }
};
sprite_pattern spr_egg1_pat4 =
{
  1,
  { { -28, -40, 0, 516 } }
};
sprite_pattern spr_egg1_pat5 =
{
  1,
  { { -28, -24, 0, 517 } }
};
sprite_pattern spr_egg1_pat6 =
{
  1,
  { { -28, -24, 0, 518 } }
};
sprite_pattern spr_egg1_pat7 =
{
  1,
  { { -28, -24, 0, 519 } }
};
sprite_pattern spr_egg1_pat8 =
{
  1,
  { { -28, -24, 0, 520 } }
};
sprite_pattern spr_egg1_pat9 =
{
  1,
  { { -28, -24, 0, 521 } }
};
sprite_pattern spr_egg1_pat10 =
{
  1,
  { { -28, -24, 0, 522 } }
};
sprite_pattern* egg1_pat[11] =
{
  &spr_egg1_pat0,
  &spr_egg1_pat1,
  &spr_egg1_pat2,
  &spr_egg1_pat3,
  &spr_egg1_pat4,
  &spr_egg1_pat5,
  &spr_egg1_pat6,
  &spr_egg1_pat7,
  &spr_egg1_pat8,
  &spr_egg1_pat9,
  &spr_egg1_pat10
};
sprite_pattern spr_egg1body_pat0 =
{
  2,
  {
    {   0,   8, 0, 511 },
    { -36, -31, 0, 498 }
  }
};
sprite_pattern* egg1body_pat[1] = { &spr_egg1body_pat0 };
sprite_pattern spr_egg1leg1_pat0 =
{
  1,
  { { -8, -8, 0, 499 } }
};
sprite_pattern* egg1leg1_pat[1] = { &spr_egg1leg1_pat0 };
sprite_pattern spr_egg1leg2_pat0 =
{
  1,
  { { -12, -20, 0, 500 } }
};
sprite_pattern* egg1leg2_pat[1] = { &spr_egg1leg2_pat0 };
sprite_pattern spr_egg1leg3_pat0 =
{
  1,
  { { -32, -20, 0, 501 } }
};
sprite_pattern* egg1leg3_pat[1] = { &spr_egg1leg3_pat0 };
sprite_pattern spr_egg1arm1_pat0 =
{
  1,
  { { -24, -12, 0, 502 } }
};
sprite_pattern* egg1arm1_pat[1] = { &spr_egg1arm1_pat0 };
sprite_pattern spr_egg1arm2_pat0 =
{
  1,
  { { -8, -8, 0, 503 } }
};
sprite_pattern* egg1arm2_pat[1] = { &spr_egg1arm2_pat0 };
sprite_pattern spr_egg1arm3_pat10 =
{
  2,
  {
    { -14, -8, 0, 504 },
    {  10, -8, 0, 523 }
  }
};
sprite_pattern spr_egg1arm3_pat11 =
{
  2,
  {
    {  -6, -8, 0, 505 },
    {  10, -8, 0, 523 }
  }
};
sprite_pattern spr_egg1arm3_pat12 =
{
  2,
  {
    {  2, -8, 0, 506 },
    { 10, -8, 0, 523 }
  }
};
sprite_pattern* egg1arm3_pat1[3] =
{
  &spr_egg1arm3_pat10,
  &spr_egg1arm3_pat11,
  &spr_egg1arm3_pat12
};
sprite_pattern spr_egg1arm3_pat20 =
{
  1,
  { { -14, -8, 0, 507 } }
};
sprite_pattern spr_egg1arm3_pat21 =
{
  1,
  { { -6, -8, 0, 508 } }
};
sprite_pattern spr_egg1arm3_pat22 =
{
  1,
  { { 2, -8, 0, 509 } }
};
sprite_pattern* egg1arm3_pat2[3] =
{
  &spr_egg1arm3_pat20,
  &spr_egg1arm3_pat21,
  &spr_egg1arm3_pat22
};
sprite_pattern spr_egg1arm4_pat0 =
{
  1,
  { { -20, -16, 0, 510 } }
};
sprite_pattern* egg1arm4_pat[1] = { &spr_egg1arm4_pat0 };
extern short scr_dir_tbl[6];




















































































































































































































































































































































































































































void egg1(sprite_status* pActwk) { /* Line 628, Address: 0x1027730 */
  int(*tbl[8])(sprite_status*) = /* Line 629, Address: 0x102773c */
  {
    &egg1_ini,
    &egg1_01,
    &egg1_02,
    &egg1_03,
    &egg1_04,
    &egg1_05,
    &egg1_06,
    &egg1_wait
  };

  egg1_anime(pActwk); /* Line 641, Address: 0x1027770 */
  egg1_jisin(pActwk); /* Line 642, Address: 0x102777c */
  egg1_warai_chk(pActwk); /* Line 643, Address: 0x1027788 */
  egg1_hit_chk(pActwk); /* Line 644, Address: 0x1027794 */
  if (tbl[pActwk->r_no0 / 2](pActwk) != 0) /* Line 645, Address: 0x10277a0 */
  {
    patchg(pActwk, egg1_pchg); /* Line 647, Address: 0x10277e4 */
    actionsub(pActwk); /* Line 648, Address: 0x10277f8 */
  }
} /* Line 650, Address: 0x1027804 */






void egg1_anime(sprite_status* pActwk) { /* Line 657, Address: 0x1027820 */
  if (!pActwk->actfree[0]) return; /* Line 658, Address: 0x1027828 */
  --pActwk->actfree[0]; /* Line 659, Address: 0x1027838 */
  if (pActwk->actfree[0]) return; /* Line 660, Address: 0x1027848 */
  pActwk->patno = 0; /* Line 661, Address: 0x1027858 */
  pActwk->patcnt = 0; /* Line 662, Address: 0x1027860 */
  pActwk->pattim = 0; /* Line 663, Address: 0x1027868 */
  pActwk->pattimm = 0; /* Line 664, Address: 0x1027870 */
  pActwk->mstno.b.h = 0; /* Line 665, Address: 0x1027878 */
} /* Line 666, Address: 0x1027880 */


void egg1_jisin(sprite_status* pActwk) { /* Line 669, Address: 0x1027890 */
  short temp0 = 784; /* Line 670, Address: 0x10278a0 */
  short temp1 = 1; /* Line 671, Address: 0x10278ac */

  if (bossflag) /* Line 673, Address: 0x10278b8 */
  {
    temp0 = 256; /* Line 675, Address: 0x10278c8 */
    if (pActwk->actfree[11]) /* Line 676, Address: 0x10278d4 */
    {
      --pActwk->actfree[11]; /* Line 678, Address: 0x10278e4 */
      if (pActwk->actfree[11] & 1) temp1 *= -1; /* Line 679, Address: 0x10278f4 */

      temp0 += temp1; /* Line 681, Address: 0x1027918 */
    }
  }
  scralim_down = temp0; /* Line 684, Address: 0x1027924 */
  scralim_n_down = temp0; /* Line 685, Address: 0x102792c */
} /* Line 686, Address: 0x1027934 */



void sonic_hajiku(short subact) { /* Line 690, Address: 0x1027950 */
  short temp1 = 1024, temp2 = -1024; /* Line 691, Address: 0x1027960 */

  actwk[0].mspeed.w = 1024; /* Line 693, Address: 0x1027978 */
  if (!(actwk[0].cddat & 2)) /* Line 694, Address: 0x1027984 */
  {
    actwk[0].direc.b.h ^= -128; /* Line 696, Address: 0x102799c */
    temp2 = 0; /* Line 697, Address: 0x10279b4 */
  }
  if (actwk[0].xposi.w.h < actwk[subact].xposi.w.h) temp1 *= -1; /* Line 699, Address: 0x10279b8 */
  actwk[0].xspeed.w = temp1; /* Line 700, Address: 0x1027a10 */
  actwk[0].yspeed.w = temp2; /* Line 701, Address: 0x1027a18 */
} /* Line 702, Address: 0x1027a20 */


void egg1_coliude(short subact, sprite_status* pActwk) { /* Line 705, Address: 0x1027a40 */

  actwk[subact].actfree[2] |= 16; /* Line 707, Address: 0x1027a50 */
  sonic_hajiku(subact); /* Line 708, Address: 0x1027a80 */
  egg1coli_set(pActwk); /* Line 709, Address: 0x1027a8c */
  soundset(152); /* Line 710, Address: 0x1027a98 */
  egg1_warai_chk(pActwk); /* Line 711, Address: 0x1027aa4 */
} /* Line 712, Address: 0x1027ab0 */


void egg1_hit_chk(sprite_status* pActwk) { /* Line 715, Address: 0x1027ac0 */
  short subact;

  if (!pActwk->actfree[10]) /* Line 718, Address: 0x1027ad0 */
  {
    if (!(pActwk->actfree[2] & 8)) return; /* Line 720, Address: 0x1027ae0 */

    if (!pActwk->colino) /* Line 722, Address: 0x1027af8 */
    {
      egg1_coli((unsigned short)(unsigned char)(pActwk - actwk), pActwk); /* Line 724, Address: 0x1027b08 */
      return; /* Line 725, Address: 0x1027b4c */
    }

    subact = ((short*)pActwk)[26]; /* Line 728, Address: 0x1027b54 */
    subact = ((short*)&actwk[subact])[26]; /* Line 729, Address: 0x1027b64 */
    subact = ((short*)&actwk[subact])[26]; /* Line 730, Address: 0x1027b90 */
    if (!actwk[subact].colino) /* Line 731, Address: 0x1027bbc */
    {
      egg1_coli(subact, pActwk); /* Line 733, Address: 0x1027be8 */
      return; /* Line 734, Address: 0x1027bf8 */
    }
    subact = ((short*)&actwk[subact])[26]; /* Line 736, Address: 0x1027c00 */
    if (!actwk[subact].colino) /* Line 737, Address: 0x1027c2c */
    {
      egg1_coli(subact, pActwk); /* Line 739, Address: 0x1027c58 */
      return; /* Line 740, Address: 0x1027c68 */
    }
    subact = ((short*)pActwk)[26]; /* Line 742, Address: 0x1027c70 */
    subact = ((short*)&actwk[subact])[27]; /* Line 743, Address: 0x1027c80 */
    subact = ((short*)&actwk[subact])[26]; /* Line 744, Address: 0x1027cac */
    if (!actwk[subact].colino) /* Line 745, Address: 0x1027cd8 */
    {
      egg1_coli(subact, pActwk); /* Line 747, Address: 0x1027d04 */
      return; /* Line 748, Address: 0x1027d14 */
    }
    subact = ((short*)&actwk[subact])[26]; /* Line 750, Address: 0x1027d1c */
    if (!actwk[subact].colino) /* Line 751, Address: 0x1027d48 */
    {
      egg1_coli(subact, pActwk); /* Line 753, Address: 0x1027d74 */
      return; /* Line 754, Address: 0x1027d84 */
    }
    if (pActwk->actfree[1] == 3) /* Line 756, Address: 0x1027d8c */
    {

      subact = ((short*)pActwk)[27]; /* Line 759, Address: 0x1027da4 */
      subact = ((short*)&actwk[subact])[27]; /* Line 760, Address: 0x1027db4 */
      subact = ((short*)&actwk[subact])[26]; /* Line 761, Address: 0x1027de0 */
      subact = ((short*)&actwk[subact])[26]; /* Line 762, Address: 0x1027e0c */
      if (!actwk[subact].colino) /* Line 763, Address: 0x1027e38 */
      {
        egg1_coliude(subact, pActwk); /* Line 765, Address: 0x1027e64 */
        return; /* Line 766, Address: 0x1027e74 */
      }

      subact = ((short*)pActwk)[27]; /* Line 769, Address: 0x1027e7c */
      subact = ((short*)&actwk[subact])[26]; /* Line 770, Address: 0x1027e8c */
      subact = ((short*)&actwk[subact])[26]; /* Line 771, Address: 0x1027eb8 */
      subact = ((short*)&actwk[subact])[26]; /* Line 772, Address: 0x1027ee4 */
      if (!actwk[subact].colino) /* Line 773, Address: 0x1027f10 */
      {
        egg1_coliude(subact, pActwk); /* Line 775, Address: 0x1027f3c */
        return; /* Line 776, Address: 0x1027f4c */
      }
    }
    if (pActwk->actfree[1] != 2) return; /* Line 779, Address: 0x1027f54 */


    subact = ((short*)pActwk)[27]; /* Line 782, Address: 0x1027f6c */
    subact = ((short*)&actwk[subact])[26]; /* Line 783, Address: 0x1027f7c */
    subact = ((short*)&actwk[subact])[26]; /* Line 784, Address: 0x1027fa8 */
    subact = ((short*)&actwk[subact])[26]; /* Line 785, Address: 0x1027fd4 */
    if (actwk[subact].colino) return; /* Line 786, Address: 0x1028000 */

    egg1_coliude(subact, pActwk); /* Line 788, Address: 0x102802c */
    return; /* Line 789, Address: 0x102803c */
  }





  --pActwk->actfree[10]; /* Line 796, Address: 0x1028044 */
  if (!pActwk->actfree[10]) /* Line 797, Address: 0x1028054 */
    egg1coli_set(pActwk); /* Line 798, Address: 0x1028064 */

} /* Line 800, Address: 0x1028074 */





void egg1_warai_chk(sprite_status* pActwk) { /* Line 806, Address: 0x1028090 */

  if (!pActwk->mstno.b.h) /* Line 808, Address: 0x1028098 */
  {
    if (*(short*)&actwk[1].patno != 0 || actwk[0].r_no0 == 6) /* Line 810, Address: 0x10280a8 */
    {

      pActwk->patno = 0; /* Line 813, Address: 0x10280d8 */
      pActwk->patcnt = 0; /* Line 814, Address: 0x10280e0 */
      pActwk->pattim = 0; /* Line 815, Address: 0x10280e8 */
      pActwk->pattimm = 0; /* Line 816, Address: 0x10280f0 */
      pActwk->mstno.b.h = 1; /* Line 817, Address: 0x10280f8 */
      pActwk->actfree[0] = 60; /* Line 818, Address: 0x1028104 */
    }
  }
} /* Line 821, Address: 0x1028110 */





void egg1_coli(short subact, sprite_status* pActwk) { /* Line 827, Address: 0x1028120 */

  pActwk->actfree[10] = 20; /* Line 829, Address: 0x1028130 */


  sonic_hajiku(subact); /* Line 832, Address: 0x102813c */


  pActwk->patno = 0; /* Line 835, Address: 0x1028148 */
  pActwk->patcnt = 0; /* Line 836, Address: 0x1028150 */
  pActwk->pattim = 0; /* Line 837, Address: 0x1028158 */
  pActwk->pattimm = 0; /* Line 838, Address: 0x1028160 */
  pActwk->mstno.b.h = 2; /* Line 839, Address: 0x1028168 */
  pActwk->actfree[0] = 120; /* Line 840, Address: 0x1028174 */
  --pActwk->actfree[1]; /* Line 841, Address: 0x1028180 */
  if (!pActwk->actfree[1]) /* Line 842, Address: 0x1028190 */
  {

    pActwk->patno = 0; /* Line 845, Address: 0x10281a0 */
    pActwk->patcnt = 0; /* Line 846, Address: 0x10281a8 */
    pActwk->pattim = 0; /* Line 847, Address: 0x10281b0 */
    pActwk->pattimm = 0; /* Line 848, Address: 0x10281b8 */
    pActwk->mstno.b.h = 2; /* Line 849, Address: 0x10281c0 */
    pActwk->actfree[0] = 0; /* Line 850, Address: 0x10281cc */

    pActwk->actfree[2] &= 247; /* Line 852, Address: 0x10281d4 */
    pActwk->r_no1 = 0; /* Line 853, Address: 0x10281e4 */

    pActwk->r_no0 = 6; /* Line 855, Address: 0x10281ec */
    pActwk->colino = 0; /* Line 856, Address: 0x10281f8 */
    pActwk->colicnt = 0; /* Line 857, Address: 0x1028200 */
    actwk[((short*)pActwk)[27]].r_no0 = 4; /* Line 858, Address: 0x1028208 */

    subact = ((short*)pActwk)[26]; /* Line 860, Address: 0x1028238 */
    actwk[subact].r_no0 = 14; /* Line 861, Address: 0x1028244 */
    subact = ((short*)&actwk[subact])[26]; /* Line 862, Address: 0x1028270 */

    actwk[subact].r_no0 = 24; /* Line 864, Address: 0x102829c */
    subact = ((short*)&actwk[subact])[26]; /* Line 865, Address: 0x10282c8 */
    actwk[subact].r_no0 = 14; /* Line 866, Address: 0x10282f4 */
    actwk[subact].colino = 0; /* Line 867, Address: 0x1028320 */
    actwk[subact].colicnt = 0; /* Line 868, Address: 0x1028348 */
    subact = ((short*)&actwk[subact])[26]; /* Line 869, Address: 0x1028370 */
    actwk[subact].r_no0 = 12; /* Line 870, Address: 0x102839c */
    actwk[subact].colino = 0; /* Line 871, Address: 0x10283c8 */
    actwk[subact].colicnt = 0; /* Line 872, Address: 0x10283f0 */
    subact = ((short*)&actwk[((short*)pActwk)[26]])[27]; /* Line 873, Address: 0x1028418 */

    actwk[subact].r_no0 = 24; /* Line 875, Address: 0x1028448 */
    subact = ((short*)&actwk[subact])[26]; /* Line 876, Address: 0x1028474 */
    actwk[subact].r_no0 = 14; /* Line 877, Address: 0x10284a0 */
    actwk[subact].colino = 0; /* Line 878, Address: 0x10284cc */
    actwk[subact].colicnt = 0; /* Line 879, Address: 0x10284f4 */
    subact = ((short*)&actwk[subact])[26]; /* Line 880, Address: 0x102851c */
    actwk[subact].r_no0 = 12; /* Line 881, Address: 0x1028548 */
    actwk[subact].colino = 0; /* Line 882, Address: 0x1028574 */
    actwk[subact].colicnt = 0; /* Line 883, Address: 0x102859c */
  } /* Line 884, Address: 0x10285c4 */
  else
  {
    if (pActwk->actfree[1] != 2) /* Line 887, Address: 0x10285cc */
    {

      subact = ((short*)pActwk)[27]; /* Line 890, Address: 0x10285e4 */
      actwk[subact].actfree[2] |= 64; /* Line 891, Address: 0x10285f0 */
      egg1coli_set_body(pActwk); /* Line 892, Address: 0x1028620 */
    } /* Line 893, Address: 0x102862c */
    else
    {


      subact = ((short*)pActwk)[27]; /* Line 898, Address: 0x1028634 */
      actwk[subact].actfree[2] |= 32; /* Line 899, Address: 0x1028640 */
      egg1coli_set_arm_l(pActwk); /* Line 900, Address: 0x1028670 */
    }
  }

} /* Line 904, Address: 0x102867c */


void egg1coli_set_body(sprite_status* pActwk) { /* Line 907, Address: 0x1028690 */
  short subact;

  pActwk->colino = 252; /* Line 910, Address: 0x102869c */
  pActwk->colicnt = 2; /* Line 911, Address: 0x10286a8 */

  subact = ((short*)&actwk[((short*)&actwk[((short*)pActwk)[26]])[26]])[26]; /* Line 913, Address: 0x10286b4 */
  actwk[subact].colino = 189; /* Line 914, Address: 0x102870c */
  actwk[subact].colicnt = 2; /* Line 915, Address: 0x1028734 */
  subact = ((short*)&actwk[subact])[26]; /* Line 916, Address: 0x102875c */
  actwk[subact].colino = 190; /* Line 917, Address: 0x1028788 */
  actwk[subact].colicnt = 2; /* Line 918, Address: 0x10287b0 */

  subact = ((short*)&actwk[((short*)&actwk[((short*)pActwk)[26]])[27]])[26]; /* Line 920, Address: 0x10287d8 */
  actwk[subact].colino = 189; /* Line 921, Address: 0x1028830 */
  actwk[subact].colicnt = 2; /* Line 922, Address: 0x1028858 */
  subact = ((short*)&actwk[subact])[26]; /* Line 923, Address: 0x1028880 */
  actwk[subact].colino = 190; /* Line 924, Address: 0x10288ac */
  actwk[subact].colicnt = 2; /* Line 925, Address: 0x10288d4 */
} /* Line 926, Address: 0x10288fc */


void egg1coli_set_arm(short subact) { /* Line 929, Address: 0x1028910 */
  subact = ((short*)&actwk[((short*)&actwk[subact])[26]])[26]; /* Line 930, Address: 0x1028918 */
  actwk[subact].colino = 255; /* Line 931, Address: 0x1028968 */
  actwk[subact].colicnt = 2; /* Line 932, Address: 0x1028994 */
} /* Line 933, Address: 0x10289c0 */


void egg1coli_set_arm_l(sprite_status* pActwk) { /* Line 936, Address: 0x10289d0 */
  egg1coli_set_arm(((short*)&actwk[((short*)pActwk)[27]])[26]); /* Line 937, Address: 0x10289dc */
  egg1coli_set_body(pActwk); /* Line 938, Address: 0x1028a10 */
} /* Line 939, Address: 0x1028a1c */


void egg1coli_set_arm_r(sprite_status* pActwk) { /* Line 942, Address: 0x1028a30 */
  egg1coli_set_arm(((short*)&actwk[((short*)pActwk)[27]])[27]); /* Line 943, Address: 0x1028a3c */
  egg1coli_set_arm_l(pActwk); /* Line 944, Address: 0x1028a70 */
} /* Line 945, Address: 0x1028a7c */


void egg1coli_set(sprite_status* pActwk) { /* Line 948, Address: 0x1028a90 */
  if (pActwk->actfree[1] == 3) /* Line 949, Address: 0x1028a9c */
    egg1coli_set_arm_r(pActwk); /* Line 950, Address: 0x1028ab4 */
  if (pActwk->actfree[1] == 2) /* Line 951, Address: 0x1028ac0 */
    egg1coli_set_arm_l(pActwk); /* Line 952, Address: 0x1028ad8 */
  if (pActwk->actfree[1] == 1) /* Line 953, Address: 0x1028ae4 */
    egg1coli_set_body(pActwk); /* Line 954, Address: 0x1028afc */
} /* Line 955, Address: 0x1028b08 */




int egg1_ini(sprite_status* pActwk) { /* Line 960, Address: 0x1028b20 */
  divdevset(4); /* Line 961, Address: 0x1028b2c */
  bossstart = 1; /* Line 962, Address: 0x1028b38 */

  pActwk->cddat = 0; /* Line 964, Address: 0x1028b44 */
  pActwk->r_no0 = 2; /* Line 965, Address: 0x1028b4c */
  pActwk->actflg = 4; /* Line 966, Address: 0x1028b58 */
  pActwk->sprpri = 6; /* Line 967, Address: 0x1028b64 */
  pActwk->sprhsize = 20; /* Line 968, Address: 0x1028b70 */
  pActwk->sprvsize = 8; /* Line 969, Address: 0x1028b7c */
  pActwk->sproffset = 1021; /* Line 970, Address: 0x1028b88 */
  pActwk->patbase = egg1_pat; /* Line 971, Address: 0x1028b94 */

  pActwk->mstno.b.h = 1; /* Line 973, Address: 0x1028ba4 */
  pActwk->patno = 0; /* Line 974, Address: 0x1028bb0 */
  pActwk->patcnt = 0; /* Line 975, Address: 0x1028bb8 */
  pActwk->pattim = 0; /* Line 976, Address: 0x1028bc0 */
  pActwk->pattimm = 0; /* Line 977, Address: 0x1028bc8 */

  pActwk->xposi.w.h = 3154; /* Line 979, Address: 0x1028bd0 */
  pActwk->yposi.w.h = 120; /* Line 980, Address: 0x1028bdc */

  colorset2(5); /* Line 982, Address: 0x1028be8 */
  return 1; /* Line 983, Address: 0x1028bf4 */
} /* Line 984, Address: 0x1028bf8 */



















int make_act(sprite_status* pActwk, sprite_status** subActwk) { /* Line 1004, Address: 0x1028c10 */
  int ret;
  sprite_status* ppActwk;

  if (actwkchk(&ppActwk) == 0) /* Line 1008, Address: 0x1028c24 */
  {
    *subActwk = ppActwk; /* Line 1010, Address: 0x1028c38 */
    ppActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 1011, Address: 0x1028c44 */
    ppActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 1012, Address: 0x1028c54 */
    ret = 0; /* Line 1013, Address: 0x1028c64 */
  } /* Line 1014, Address: 0x1028c68 */
  else
    ret = 1; /* Line 1016, Address: 0x1028c70 */
  return ret; /* Line 1017, Address: 0x1028c74 */
} /* Line 1018, Address: 0x1028c78 */


void egg1_make_act(sprite_status* pActwk) { /* Line 1021, Address: 0x1028c90 */
  sprite_status *subActwk, *disActwk, *bodyActwk;
  short subact;


  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1026, Address: 0x1028ca8 */
  ((short*)pActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1027, Address: 0x1028cc0 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 1028, Address: 0x1028d00 */
  subActwk->sprpri = 6; /* Line 1029, Address: 0x1028d40 */
  subActwk->actno = 43; /* Line 1030, Address: 0x1028d4c */
  disActwk = subActwk; /* Line 1031, Address: 0x1028d58 */
  bodyActwk = subActwk; /* Line 1032, Address: 0x1028d60 */



  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1036, Address: 0x1028d68 */
  ((short*)disActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1037, Address: 0x1028d80 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(disActwk - actwk); /* Line 1038, Address: 0x1028dbc */
  subActwk->sprpri = 6; /* Line 1039, Address: 0x1028df8 */
  subActwk->actno = 44; /* Line 1040, Address: 0x1028e04 */
  disActwk = subActwk; /* Line 1041, Address: 0x1028e10 */


  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1044, Address: 0x1028e18 */
  ((short*)disActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1045, Address: 0x1028e30 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(disActwk - actwk); /* Line 1046, Address: 0x1028e6c */
  subActwk->sprpri = 3; /* Line 1047, Address: 0x1028ea8 */
  subActwk->actno = 45; /* Line 1048, Address: 0x1028eb4 */
  disActwk = subActwk; /* Line 1049, Address: 0x1028ec0 */


  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1052, Address: 0x1028ec8 */
  ((short*)disActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1053, Address: 0x1028ee0 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(disActwk - actwk); /* Line 1054, Address: 0x1028f1c */
  subActwk->sprpri = 2; /* Line 1055, Address: 0x1028f58 */
  subActwk->actno = 46; /* Line 1056, Address: 0x1028f64 */

  disActwk = bodyActwk; /* Line 1058, Address: 0x1028f70 */
  ((short*)subActwk)[26] = (unsigned short)(unsigned char)(bodyActwk - actwk); /* Line 1059, Address: 0x1028f74 */



  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1063, Address: 0x1028fb0 */
  ((short*)disActwk)[27] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1064, Address: 0x1028fc8 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(disActwk - actwk); /* Line 1065, Address: 0x1029004 */
  subActwk->sprpri = 7; /* Line 1066, Address: 0x1029040 */
  subActwk->actno = 44; /* Line 1067, Address: 0x102904c */
  subActwk->actfree[2] |= 4; /* Line 1068, Address: 0x1029058 */
  disActwk = subActwk; /* Line 1069, Address: 0x1029068 */


  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1072, Address: 0x102906c */
  ((short*)disActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1073, Address: 0x1029084 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(disActwk - actwk); /* Line 1074, Address: 0x10290c0 */
  subActwk->sprpri = 6; /* Line 1075, Address: 0x10290fc */
  subActwk->actno = 45; /* Line 1076, Address: 0x1029108 */
  subActwk->actfree[2] |= 4; /* Line 1077, Address: 0x1029114 */
  disActwk = subActwk; /* Line 1078, Address: 0x1029124 */


  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1081, Address: 0x1029128 */
  ((short*)disActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1082, Address: 0x1029140 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(disActwk - actwk); /* Line 1083, Address: 0x102917c */
  subActwk->sprpri = 5; /* Line 1084, Address: 0x10291b8 */
  subActwk->actno = 46; /* Line 1085, Address: 0x10291c4 */
  subActwk->actfree[2] |= 4; /* Line 1086, Address: 0x10291d0 */


  disActwk = bodyActwk; /* Line 1089, Address: 0x10291e0 */
  ((short*)subActwk)[26] = (unsigned short)(unsigned char)(bodyActwk - actwk); /* Line 1090, Address: 0x10291e4 */



  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1094, Address: 0x1029220 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(bodyActwk - actwk); /* Line 1095, Address: 0x1029238 */
  ((short*)&actwk[((short*)disActwk)[25]])[27] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1096, Address: 0x1029274 */

  subActwk->sprpri = 3; /* Line 1098, Address: 0x10292d4 */
  subActwk->actno = 47; /* Line 1099, Address: 0x10292e0 */
  disActwk = subActwk; /* Line 1100, Address: 0x10292ec */


  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1103, Address: 0x10292f0 */
  ((short*)disActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1104, Address: 0x1029308 */
  subActwk->actfree[0] = 128; /* Line 1105, Address: 0x1029344 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(disActwk - actwk); /* Line 1106, Address: 0x1029350 */
  ((short*)disActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1107, Address: 0x102938c */
  subActwk->sprpri = 5; /* Line 1108, Address: 0x10293c8 */
  subActwk->actno = 48; /* Line 1109, Address: 0x10293d4 */
  disActwk = subActwk; /* Line 1110, Address: 0x10293e0 */


  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1113, Address: 0x10293e8 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(disActwk - actwk); /* Line 1114, Address: 0x1029400 */
  ((short*)disActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1115, Address: 0x102943c */
  subActwk->sprpri = 4; /* Line 1116, Address: 0x1029478 */
  subActwk->patbase = egg1arm3_pat1; /* Line 1117, Address: 0x1029484 */
  subActwk->actno = 49; /* Line 1118, Address: 0x1029494 */
  disActwk = subActwk; /* Line 1119, Address: 0x10294a0 */


  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1122, Address: 0x10294a8 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(disActwk - actwk); /* Line 1123, Address: 0x10294c0 */
  ((short*)disActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1124, Address: 0x10294fc */
  subActwk->sprpri = 3; /* Line 1125, Address: 0x1029538 */
  subActwk->actno = 50; /* Line 1126, Address: 0x1029544 */
  disActwk = subActwk; /* Line 1127, Address: 0x1029550 */
  ((short*)subActwk)[26] = (unsigned short)(unsigned char)(bodyActwk - actwk); /* Line 1128, Address: 0x1029558 */



  subact = ((short*)disActwk)[25]; /* Line 1132, Address: 0x1029594 */
  subact = ((short*)&actwk[subact])[25]; /* Line 1133, Address: 0x10295a0 */
  subact = ((short*)&actwk[subact])[25]; /* Line 1134, Address: 0x10295cc */


  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1137, Address: 0x10295f8 */
  ((short*)&actwk[subact])[27] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1138, Address: 0x1029610 */
  ((short*)subActwk)[25] = subact; /* Line 1139, Address: 0x102966c */
  subActwk->sprpri = 7; /* Line 1140, Address: 0x1029674 */
  subActwk->actno = 48; /* Line 1141, Address: 0x1029680 */
  subActwk->actfree[2] |= 4; /* Line 1142, Address: 0x102968c */
  disActwk = subActwk; /* Line 1143, Address: 0x102969c */


  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1146, Address: 0x10296a4 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(disActwk - actwk); /* Line 1147, Address: 0x10296bc */
  ((short*)disActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1148, Address: 0x10296f8 */
  subActwk->sprpri = 7; /* Line 1149, Address: 0x1029734 */
  subActwk->patbase = egg1arm3_pat2; /* Line 1150, Address: 0x1029740 */
  subActwk->actno = 49; /* Line 1151, Address: 0x1029750 */
  subActwk->actfree[2] |= 4; /* Line 1152, Address: 0x102975c */
  disActwk = subActwk; /* Line 1153, Address: 0x102976c */


  if (make_act(pActwk, &subActwk) != 0) return; /* Line 1156, Address: 0x1029774 */
  ((short*)subActwk)[25] = (unsigned short)(unsigned char)(disActwk - actwk); /* Line 1157, Address: 0x102978c */
  ((short*)disActwk)[26] = (unsigned short)(unsigned char)(subActwk - actwk); /* Line 1158, Address: 0x10297c8 */
  subActwk->sprpri = 6; /* Line 1159, Address: 0x1029804 */
  subActwk->actno = 50; /* Line 1160, Address: 0x1029810 */
  subActwk->actfree[2] |= 4; /* Line 1161, Address: 0x102981c */
  disActwk = subActwk; /* Line 1162, Address: 0x102982c */

  ((short*)subActwk)[26] = (unsigned short)(unsigned char)(bodyActwk - actwk); /* Line 1164, Address: 0x1029834 */

  pActwk->actfree[1] = 3; /* Line 1166, Address: 0x1029870 */
  egg1coli_set(pActwk); /* Line 1167, Address: 0x102987c */
} /* Line 1168, Address: 0x1029888 */




int egg1_01(sprite_status* pActwk) { /* Line 1173, Address: 0x10298b0 */
  scralim_right = 2752; /* Line 1174, Address: 0x10298b8 */
  scralim_n_right = 2752; /* Line 1175, Address: 0x10298c4 */

  if (actwk[0].xposi.w.h < 2666) return 1; /* Line 1177, Address: 0x10298d0 */
  if (actwk[0].xposi.w.h - 160 < scralim_left) return 1; /* Line 1178, Address: 0x10298f8 */

  if (actwk[0].xposi.w.h >= 2912) /* Line 1180, Address: 0x1029934 */
  {
    pActwk->r_no0 = 12; /* Line 1182, Address: 0x1029950 */
    scralim_right = 2752; /* Line 1183, Address: 0x102995c */
    scralim_n_right = 2752; /* Line 1184, Address: 0x1029968 */
    scralim_left = 2752; /* Line 1185, Address: 0x1029974 */
    scralim_n_left = 2752; /* Line 1186, Address: 0x1029980 */
  } /* Line 1187, Address: 0x102998c */
  else
  {
    scralim_left = actwk[0].xposi.w.h - 160; /* Line 1190, Address: 0x1029994 */
    scralim_n_left = actwk[0].xposi.w.h - 160; /* Line 1191, Address: 0x10299b8 */
  }
  return 1; /* Line 1193, Address: 0x10299dc */
} /* Line 1194, Address: 0x10299e0 */




int egg1_06(sprite_status* pActwk) { /* Line 1199, Address: 0x10299f0 */

  scra_vline += 6; /* Line 1201, Address: 0x10299fc */
  if (scra_vline >= 200) /* Line 1202, Address: 0x1029a10 */
  {

    sub_sync(103); /* Line 1205, Address: 0x1029a2c */

    bossflag = 1; /* Line 1207, Address: 0x1029a38 */
    pActwk->r_no0 = 14; /* Line 1208, Address: 0x1029a44 */
  }
  return 1; /* Line 1210, Address: 0x1029a50 */
} /* Line 1211, Address: 0x1029a54 */




int egg1_wait(sprite_status* pActwk) { /* Line 1216, Address: 0x1029a70 */
  ++pActwk->actfree[1]; /* Line 1217, Address: 0x1029a7c */
  if (pActwk->actfree[1] == 60) /* Line 1218, Address: 0x1029a8c */
  {
    pActwk->actfree[1] = 0; /* Line 1220, Address: 0x1029aa4 */
    pActwk->r_no0 = 4; /* Line 1221, Address: 0x1029aac */
    pActwk->xposi.w.h = 3026; /* Line 1222, Address: 0x1029ab8 */
    pActwk->yposi.w.h = 120; /* Line 1223, Address: 0x1029ac4 */
    egg1_make_act(pActwk); /* Line 1224, Address: 0x1029ad0 */
  }
  return 1; /* Line 1226, Address: 0x1029adc */
} /* Line 1227, Address: 0x1029ae0 */







int egg1_02(sprite_status* pActwk) { /* Line 1235, Address: 0x1029af0 */
  short subact;
  short egg1acttbl[20] = /* Line 1237, Address: 0x1029b00 */
  {
     2,  0,
     4,  0,
     6,  0,
     8,  5,
    10,  6,
    12, 10,
     8, 10,
    16, 50,
    10, 10,
    -1, -1
  };


  subact = ((short*)pActwk)[26]; /* Line 1252, Address: 0x1029b34 */
  if (!(actwk[subact].actfree[2] & 1)) /* Line 1253, Address: 0x1029b44 */
    return 1; /* Line 1254, Address: 0x1029b78 */
  actwk[subact].actfree[2] &= 254; /* Line 1255, Address: 0x1029b84 */
  if (pActwk->r_no1 == 2) /* Line 1256, Address: 0x1029bb0 */
  {

    pActwk->mstno.w = 0; /* Line 1259, Address: 0x1029bc8 */
    pActwk->patno = 0; /* Line 1260, Address: 0x1029bd0 */
    pActwk->patcnt = 0; /* Line 1261, Address: 0x1029bd8 */
    pActwk->pattim = 0; /* Line 1262, Address: 0x1029be0 */
    pActwk->pattimm = 0; /* Line 1263, Address: 0x1029be8 */

    pActwk->actfree[1] = 3; /* Line 1265, Address: 0x1029bf0 */
    pActwk->actfree[2] |= 8; /* Line 1266, Address: 0x1029bfc */
    egg1coli_set(pActwk); /* Line 1267, Address: 0x1029c0c */
    subact = ((short*)pActwk)[26]; /* Line 1268, Address: 0x1029c18 */
  }

  pActwk->r_no1 += 2; /* Line 1271, Address: 0x1029c28 */
  actwk[subact].actfree[2] &= 253; /* Line 1272, Address: 0x1029c38 */
  while (egg1acttbl[pActwk->r_no1] < 0) /* Line 1273, Address: 0x1029c64 */
    pActwk->r_no1 = 6; /* Line 1274, Address: 0x1029c6c */
  actwk[subact].r_no0 = egg1acttbl[pActwk->r_no1]; /* Line 1275, Address: 0x1029ca0 */
  actwk[subact].actfree[3] = egg1acttbl[pActwk->r_no1 + 1]; /* Line 1276, Address: 0x1029ce0 */
  return 1; /* Line 1277, Address: 0x1029d24 */
} /* Line 1278, Address: 0x1029d28 */




int egg1_03(sprite_status* pActwk) { /* Line 1283, Address: 0x1029d40 */
  short subact;

  ++pActwk->actfree[1]; /* Line 1286, Address: 0x1029d50 */

  bom_set(pActwk); /* Line 1288, Address: 0x1029d60 */

  if (pActwk->actfree[1] == 94) /* Line 1290, Address: 0x1029d6c */
  {

    ((short*)pActwk)[33] = pActwk->xposi.w.h; /* Line 1293, Address: 0x1029d84 */
    pActwk->yspeed.w = pActwk->yposi.w.h; /* Line 1294, Address: 0x1029d94 */

    pActwk->mstno.b.h = 3; /* Line 1296, Address: 0x1029da4 */
    pActwk->patno = 0; /* Line 1297, Address: 0x1029db0 */
    pActwk->patcnt = 0; /* Line 1298, Address: 0x1029db8 */
    pActwk->pattim = 0; /* Line 1299, Address: 0x1029dc0 */
    pActwk->pattimm = 0; /* Line 1300, Address: 0x1029dc8 */
    subact = ((short*)pActwk)[26]; /* Line 1301, Address: 0x1029dd0 */
    actwk[subact].actfree[2] |= 1; /* Line 1302, Address: 0x1029de0 */
  }
  if (pActwk->actfree[1] >= 120) /* Line 1304, Address: 0x1029e0c */
  {
    pActwk->actfree[1] = 0; /* Line 1306, Address: 0x1029e24 */
    pActwk->r_no0 = 8; /* Line 1307, Address: 0x1029e2c */
    pActwk->sprhsize = 32; /* Line 1308, Address: 0x1029e38 */
    pActwk->sprvsize = 32; /* Line 1309, Address: 0x1029e44 */
    scoreup(100); /* Line 1310, Address: 0x1029e50 */
  }
  return 1; /* Line 1312, Address: 0x1029e5c */
} /* Line 1313, Address: 0x1029e60 */




int egg1_04(sprite_status* pActwk) { /* Line 1318, Address: 0x1029e80 */
  int ret = 1; /* Line 1319, Address: 0x1029e98 */
  unsigned short sin, cos;
  int_union sinl, cosl;
  short xposi_bak, yposi_bak;

  if (pActwk->r_no1 != 0) /* Line 1324, Address: 0x1029e9c */
  {
    pActwk->yposi.w.h -= ((short*)pActwk)[31]; /* Line 1326, Address: 0x1029eb0 */

    pActwk->actfree[1] += 3; /* Line 1328, Address: 0x1029ec8 */
    sinset(pActwk->actfree[1], (short*)&sin, (short*)&cos); /* Line 1329, Address: 0x1029ed8 */
    sinl.l = sin; /* Line 1330, Address: 0x1029ef0 */
    cosl.l = cos; /* Line 1331, Address: 0x1029efc */
    sinl.w.l /= 32; /* Line 1332, Address: 0x1029f08 */
    ((short*)pActwk)[31] = sinl.w.l; /* Line 1333, Address: 0x1029f28 */
    pActwk->yposi.w.h += sinl.w.l; /* Line 1334, Address: 0x1029f34 */

    pActwk->xposi.l += 163840; /* Line 1336, Address: 0x1029f48 */
    if (pActwk->xposi.w.h >= 3200) /* Line 1337, Address: 0x1029f60 */
    {

      pActwk->actfree[1] = 0; /* Line 1340, Address: 0x1029f7c */
      if (generate_flag == 0) /* Line 1341, Address: 0x1029f84 */
        sub_sync(17); /* Line 1342, Address: 0x1029f98 */
      else
        sub_sync(16); /* Line 1344, Address: 0x1029fac */
      genecolor(); /* Line 1345, Address: 0x1029fb8 */

      bossflag = 0; /* Line 1347, Address: 0x1029fc0 */
      bossstart = 0; /* Line 1348, Address: 0x1029fc8 */
      pActwk->r_no0 = 10; /* Line 1349, Address: 0x1029fd0 */
      ret = egg1_05(pActwk); /* Line 1350, Address: 0x1029fdc */
    }
  } /* Line 1352, Address: 0x1029fec */
  else
  {

    ++pActwk->actfree[1]; /* Line 1356, Address: 0x1029ff4 */


    xposi_bak = pActwk->xposi.w.h; /* Line 1359, Address: 0x102a004 */
    yposi_bak = pActwk->yposi.w.h; /* Line 1360, Address: 0x102a014 */
    pActwk->xposi.w.h = ((short*)pActwk)[33]; /* Line 1361, Address: 0x102a024 */
    pActwk->yposi.w.h = pActwk->yspeed.w; /* Line 1362, Address: 0x102a034 */
    bom_set(pActwk); /* Line 1363, Address: 0x102a044 */
    pActwk->xposi.w.h = xposi_bak; /* Line 1364, Address: 0x102a050 */
    pActwk->yposi.w.h = yposi_bak; /* Line 1365, Address: 0x102a058 */

    pActwk->xposi.l += 32768; /* Line 1367, Address: 0x102a060 */
    pActwk->yposi.l -= 131072; /* Line 1368, Address: 0x102a074 */
    if (pActwk->yposi.w.h <= 344) /* Line 1369, Address: 0x102a088 */
    {
      ++pActwk->r_no1; /* Line 1371, Address: 0x102a0a4 */
      pActwk->patno = 0; /* Line 1372, Address: 0x102a0b4 */
      pActwk->patcnt = 0; /* Line 1373, Address: 0x102a0bc */
      pActwk->pattim = 0; /* Line 1374, Address: 0x102a0c4 */
      pActwk->pattimm = 0; /* Line 1375, Address: 0x102a0cc */
      pActwk->mstno.b.h = 4; /* Line 1376, Address: 0x102a0d4 */
      pActwk->actfree[1] = 64; /* Line 1377, Address: 0x102a0e0 */
      ((short*)pActwk)[31] = 8; /* Line 1378, Address: 0x102a0ec */
    }
  }
  return ret; /* Line 1381, Address: 0x102a0f8 */
} /* Line 1382, Address: 0x102a0fc */




int egg1_05(sprite_status* pActwk) { /* Line 1387, Address: 0x102a120 */
  short temp0, temp1;
  int ret = 1; /* Line 1389, Address: 0x102a138 */

  temp0 = scr_dir_tbl[1]; /* Line 1391, Address: 0x102a13c */
  temp1 = scr_dir_tbl[2]; /* Line 1392, Address: 0x102a14c */
  scralim_right += 6; /* Line 1393, Address: 0x102a15c */
  scralim_n_right += 6; /* Line 1394, Address: 0x102a170 */
  if (temp1 > scralim_right) /* Line 1395, Address: 0x102a184 */
    ret = 0; /* Line 1396, Address: 0x102a1a8 */
  else
  {
    scralim_right = temp1; /* Line 1399, Address: 0x102a1b4 */
    scralim_n_right = temp1; /* Line 1400, Address: 0x102a1bc */
    ret = 0; /* Line 1401, Address: 0x102a1c4 */
    frameout(pActwk); /* Line 1402, Address: 0x102a1c8 */
  }
  return ret; /* Line 1404, Address: 0x102a1d4 */
} /* Line 1405, Address: 0x102a1d8 */





void egg1body(sprite_status* pActwk) { /* Line 1411, Address: 0x102a200 */
  int(*tbl[9])(sprite_status*) = /* Line 1412, Address: 0x102a20c */
  {
    &egg1body_ini,
    &egg1body_01,
    &egg1body_02,
    &egg1body_03,
    &egg1body_04,
    &egg1body_05,
    &egg1body_06,
    &egg1body_07,
    &egg1body_08
  };

  if (tbl[pActwk->r_no0 / 2](pActwk) == 0) return; /* Line 1425, Address: 0x102a238 */
  actionsub(pActwk); /* Line 1426, Address: 0x102a27c */
} /* Line 1427, Address: 0x102a288 */



void spd_normal(sprite_status* pActwk) { /* Line 1431, Address: 0x102a2a0 */
  short subact1, subact2;

  subact1 = ((short*)pActwk)[26]; /* Line 1434, Address: 0x102a2b0 */
  actwk[subact1].actfree[21] = 2; /* Line 1435, Address: 0x102a2c0 */
  subact1 = ((short*)&actwk[subact1])[26]; /* Line 1436, Address: 0x102a2e8 */
  ((int*)&actwk[subact1])[16] = 32768; /* Line 1437, Address: 0x102a314 */
  ((int*)&actwk[subact1])[4] = 16384; /* Line 1438, Address: 0x102a33c */
  subact1 = ((short*)&actwk[subact1])[26]; /* Line 1439, Address: 0x102a364 */
  ((int*)&actwk[subact1])[16] = 16384; /* Line 1440, Address: 0x102a390 */
  ((int*)&actwk[subact1])[4] = 32768; /* Line 1441, Address: 0x102a3b8 */

  subact1 = ((short*)pActwk)[27]; /* Line 1443, Address: 0x102a3e0 */
  actwk[subact1].actfree[21] = 2; /* Line 1444, Address: 0x102a3f0 */
  subact1 = ((short*)&actwk[subact1])[26]; /* Line 1445, Address: 0x102a418 */
  ((int*)&actwk[subact1])[16] = 32768; /* Line 1446, Address: 0x102a444 */
  ((int*)&actwk[subact1])[4] = 16384; /* Line 1447, Address: 0x102a46c */
  subact1 = ((short*)&actwk[subact1])[26]; /* Line 1448, Address: 0x102a494 */
  ((int*)&actwk[subact1])[16] = 16384; /* Line 1449, Address: 0x102a4c0 */
  ((int*)&actwk[subact1])[4] = 32768; /* Line 1450, Address: 0x102a4e8 */

  subact1 = ((short*)pActwk)[25]; /* Line 1452, Address: 0x102a510 */
  subact2 = ((short*)&actwk[subact1])[27]; /* Line 1453, Address: 0x102a520 */
  subact1 = ((short*)&actwk[subact2])[27]; /* Line 1454, Address: 0x102a54c */
  if (subact1) /* Line 1455, Address: 0x102a578 */
  {
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1457, Address: 0x102a580 */
    actwk[subact1].actfree[2] &= 127; /* Line 1458, Address: 0x102a5ac */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1459, Address: 0x102a5d8 */
    actwk[subact1].actfree[2] &= 127; /* Line 1460, Address: 0x102a604 */
  }

  subact1 = ((short*)&actwk[subact2])[26]; /* Line 1463, Address: 0x102a630 */
  if (subact1) /* Line 1464, Address: 0x102a65c */
  {
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1466, Address: 0x102a664 */
    actwk[subact1].actfree[2] &= 127; /* Line 1467, Address: 0x102a690 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1468, Address: 0x102a6bc */
    actwk[subact1].actfree[2] &= 127; /* Line 1469, Address: 0x102a6e8 */
  }
} /* Line 1471, Address: 0x102a714 */



int egg1body_ini(sprite_status* pActwk) { /* Line 1475, Address: 0x102a730 */
  pActwk->cddat = 0; /* Line 1476, Address: 0x102a73c */
  pActwk->r_no0 = 2; /* Line 1477, Address: 0x102a744 */
  pActwk->actflg = 4; /* Line 1478, Address: 0x102a750 */
  pActwk->sprhsize = 36; /* Line 1479, Address: 0x102a75c */
  pActwk->sprvsize = 32; /* Line 1480, Address: 0x102a768 */
  pActwk->sproffset = 857; /* Line 1481, Address: 0x102a774 */
  pActwk->patbase = egg1body_pat; /* Line 1482, Address: 0x102a780 */
  spd_normal(pActwk); /* Line 1483, Address: 0x102a790 */
  return 1; /* Line 1484, Address: 0x102a79c */
} /* Line 1485, Address: 0x102a7a0 */




int egg1body_08(sprite_status* pActwk) { /* Line 1490, Address: 0x102a7b0 */
  --pActwk->actfree[3]; /* Line 1491, Address: 0x102a7bc */
  if (!pActwk->actfree[3]) /* Line 1492, Address: 0x102a7cc */
  {
    spd_normal(pActwk); /* Line 1494, Address: 0x102a7dc */
    pActwk->actfree[2] |= 1; /* Line 1495, Address: 0x102a7e8 */
    pActwk->actfree[2] &= 253; /* Line 1496, Address: 0x102a7f8 */
  }
  return 1; /* Line 1498, Address: 0x102a808 */
} /* Line 1499, Address: 0x102a80c */




void bup_set(sprite_status* legActwk) { /* Line 1504, Address: 0x102a820 */
  short subact;

  legActwk->actfree[2] |= 32; /* Line 1507, Address: 0x102a82c */
  subact = ((short*)legActwk)[26]; /* Line 1508, Address: 0x102a83c */
  actwk[subact].actfree[2] |= 32; /* Line 1509, Address: 0x102a84c */
  subact = ((short*)&actwk[subact])[26]; /* Line 1510, Address: 0x102a878 */
  actwk[subact].actfree[2] |= 32; /* Line 1511, Address: 0x102a8a4 */
} /* Line 1512, Address: 0x102a8d0 */




void bup_clr(sprite_status* legActwk) { /* Line 1517, Address: 0x102a8e0 */
  short subact;

  legActwk->actfree[2] &= 223; /* Line 1520, Address: 0x102a8ec */
  subact = ((short*)legActwk)[26]; /* Line 1521, Address: 0x102a8fc */
  actwk[subact].actfree[2] &= 223; /* Line 1522, Address: 0x102a90c */
  subact = ((short*)&actwk[subact])[26]; /* Line 1523, Address: 0x102a938 */
  actwk[subact].actfree[2] &= 223; /* Line 1524, Address: 0x102a964 */
} /* Line 1525, Address: 0x102a990 */




void grd_set(sprite_status* legActwk) { /* Line 1530, Address: 0x102a9a0 */
  short subact;

  legActwk->actfree[2] |= 16; /* Line 1533, Address: 0x102a9ac */
  subact = ((short*)legActwk)[26]; /* Line 1534, Address: 0x102a9bc */
  actwk[subact].actfree[2] |= 16; /* Line 1535, Address: 0x102a9cc */
  subact = ((short*)&actwk[subact])[26]; /* Line 1536, Address: 0x102a9f8 */
  actwk[subact].actfree[2] |= 16; /* Line 1537, Address: 0x102aa24 */
} /* Line 1538, Address: 0x102aa50 */




void grd_clr(sprite_status* legActwk) { /* Line 1543, Address: 0x102aa60 */
  short subact;

  legActwk->actfree[2] &= 239; /* Line 1546, Address: 0x102aa6c */
  subact = ((short*)legActwk)[26]; /* Line 1547, Address: 0x102aa7c */
  actwk[subact].actfree[2] &= 239; /* Line 1548, Address: 0x102aa8c */
  subact = ((short*)&actwk[subact])[26]; /* Line 1549, Address: 0x102aab8 */
  actwk[subact].actfree[2] &= 239; /* Line 1550, Address: 0x102aae4 */
} /* Line 1551, Address: 0x102ab10 */




int egg1body_01(sprite_status* pActwk) { /* Line 1556, Address: 0x102ab20 */
  short subact;

  subact = ((short*)pActwk)[27]; /* Line 1559, Address: 0x102ab30 */
  actwk[subact].r_no0 = 16; /* Line 1560, Address: 0x102ab40 */
  subact = ((short*)&actwk[subact])[26]; /* Line 1561, Address: 0x102ab68 */
  actwk[subact].r_no0 = 4; /* Line 1562, Address: 0x102ab94 */
  subact = ((short*)&actwk[subact])[26]; /* Line 1563, Address: 0x102abbc */
  actwk[subact].r_no0 = 10; /* Line 1564, Address: 0x102abe8 */

  subact = ((short*)pActwk)[26]; /* Line 1566, Address: 0x102ac10 */
  bup_set(&actwk[subact]); /* Line 1567, Address: 0x102ac20 */
  if (!(actwk[subact].actfree[2] & 16)) /* Line 1568, Address: 0x102ac48 */
  {
    pActwk->yposi.l += 98304; /* Line 1570, Address: 0x102ac7c */
    subact = ((short*)pActwk)[25]; /* Line 1571, Address: 0x102ac94 */
    actwk[subact].yposi.l += 98304; /* Line 1572, Address: 0x102aca4 */
  } /* Line 1573, Address: 0x102acd8 */
  else
    pActwk->actfree[2] |= 1; /* Line 1575, Address: 0x102ace0 */
  return 1; /* Line 1576, Address: 0x102acf0 */
} /* Line 1577, Address: 0x102acf4 */




int egg1body_02(sprite_status* pActwk) { /* Line 1582, Address: 0x102ad10 */
  short subact;

  subact = ((short*)pActwk)[27]; /* Line 1585, Address: 0x102ad20 */
  actwk[subact].actfree[2] &= 254; /* Line 1586, Address: 0x102ad30 */
  subact = ((short*)pActwk)[26]; /* Line 1587, Address: 0x102ad5c */
  if (!(actwk[subact].actfree[2] & 1)) /* Line 1588, Address: 0x102ad6c */
  {
    actwk[subact].actfree[2] &= 254; /* Line 1590, Address: 0x102ada0 */
    return 1; /* Line 1591, Address: 0x102adcc */
  }
  actwk[subact].actfree[2] &= 254; /* Line 1593, Address: 0x102add8 */
  if (actwk[subact].r_no0 == 12) /* Line 1594, Address: 0x102ae04 */
  {

    actwk[subact].r_no0 = 10; /* Line 1597, Address: 0x102ae38 */
    return 1; /* Line 1598, Address: 0x102ae60 */
  }
  if (actwk[subact].r_no0 == 10) /* Line 1600, Address: 0x102ae6c */
  {

    actwk[subact].r_no0 = 14; /* Line 1603, Address: 0x102aea0 */
    return 1; /* Line 1604, Address: 0x102aec8 */
  }

  actwk[subact].r_no0 = 2; /* Line 1607, Address: 0x102aed4 */
  bup_clr(&actwk[subact]); /* Line 1608, Address: 0x102aefc */
  grd_clr(&actwk[subact]); /* Line 1609, Address: 0x102af24 */

  subact = ((short*)pActwk)[27]; /* Line 1611, Address: 0x102af4c */
  actwk[subact].r_no0 = 8; /* Line 1612, Address: 0x102af5c */
  bup_set(&actwk[subact]); /* Line 1613, Address: 0x102af84 */
  grd_set(&actwk[subact]); /* Line 1614, Address: 0x102afac */
  subact = ((short*)&actwk[subact])[26]; /* Line 1615, Address: 0x102afd4 */
  actwk[subact].r_no0 = 2; /* Line 1616, Address: 0x102b000 */
  subact = ((short*)&actwk[subact])[26]; /* Line 1617, Address: 0x102b028 */
  actwk[subact].r_no0 = 4; /* Line 1618, Address: 0x102b054 */

  pActwk->actfree[2] |= 1; /* Line 1620, Address: 0x102b07c */
  return 1; /* Line 1621, Address: 0x102b08c */
} /* Line 1622, Address: 0x102b090 */




int egg1body_03(sprite_status* pActwk) { /* Line 1627, Address: 0x102b0b0 */
  short subact;

  if (!(pActwk->actfree[2] & 2)) /* Line 1630, Address: 0x102b0c0 */
  {
    pActwk->actfree[2] |= 2; /* Line 1632, Address: 0x102b0d8 */
    armset_2(pActwk); /* Line 1633, Address: 0x102b0e8 */
  }
  subact = ((short*)pActwk)[26]; /* Line 1635, Address: 0x102b0f4 */
  if (!(actwk[subact].actfree[2] & 1)) /* Line 1636, Address: 0x102b104 */
    return 1; /* Line 1637, Address: 0x102b138 */
  subact = ((short*)pActwk)[27]; /* Line 1638, Address: 0x102b144 */
  if (!(actwk[subact].actfree[2] & 1)) /* Line 1639, Address: 0x102b154 */
    return 1; /* Line 1640, Address: 0x102b188 */

  pActwk->actfree[2] &= 253; /* Line 1642, Address: 0x102b194 */
  pActwk->actfree[2] |= 64; /* Line 1643, Address: 0x102b1a4 */
  pActwk->actfree[2] |= 1; /* Line 1644, Address: 0x102b1b4 */
  return 1; /* Line 1645, Address: 0x102b1c4 */
} /* Line 1646, Address: 0x102b1c8 */




int egg1body_04(sprite_status* pActwk) { /* Line 1651, Address: 0x102b1e0 */
  short subact1;
  short subact2;
  short subact3;
  short subact4;

  if (!(pActwk->actfree[2] & 64)) /* Line 1657, Address: 0x102b1fc */
  {

    subact1 = ((short*)pActwk)[26]; /* Line 1660, Address: 0x102b214 */
    subact2 = ((short*)pActwk)[27]; /* Line 1661, Address: 0x102b224 */
  } /* Line 1662, Address: 0x102b234 */
  else
  {

    subact1 = ((short*)pActwk)[27]; /* Line 1666, Address: 0x102b23c */
    subact2 = ((short*)pActwk)[26]; /* Line 1667, Address: 0x102b250 */
  }
  if (!(actwk[subact1].actfree[2] & 1)) /* Line 1669, Address: 0x102b260 */
    return 1; /* Line 1670, Address: 0x102b294 */
  if (!(actwk[subact2].actfree[2] & 1)) /* Line 1671, Address: 0x102b2a0 */
    return 1; /* Line 1672, Address: 0x102b2d4 */

  subact3 = ((short*)&actwk[subact1])[26]; /* Line 1674, Address: 0x102b2e0 */
  subact3 = ((short*)&actwk[subact3])[26]; /* Line 1675, Address: 0x102b30c */
  subact4 = ((short*)&actwk[subact2])[26]; /* Line 1676, Address: 0x102b338 */
  actwk[subact1].actfree[2] &= 254; /* Line 1677, Address: 0x102b364 */
  actwk[subact3].actfree[2] &= 254; /* Line 1678, Address: 0x102b390 */
  actwk[subact2].actfree[2] &= 254; /* Line 1679, Address: 0x102b3bc */
  actwk[subact4].actfree[2] &= 254; /* Line 1680, Address: 0x102b3e8 */

  if (pActwk->xposi.w.h <= 2904) /* Line 1682, Address: 0x102b414 */
  {

    pActwk->actfree[3] = 1; /* Line 1685, Address: 0x102b430 */
  }

  --pActwk->actfree[3]; /* Line 1688, Address: 0x102b43c */
  if (!pActwk->actfree[3]) /* Line 1689, Address: 0x102b44c */
  {
    pActwk->actfree[2] |= 1; /* Line 1691, Address: 0x102b45c */
    pActwk->actfree[2] &= 253; /* Line 1692, Address: 0x102b46c */
    return 1; /* Line 1693, Address: 0x102b47c */
  }

  if (pActwk->actfree[2] & 64) /* Line 1696, Address: 0x102b488 */
  {
    pActwk->actfree[2] ^= 64; /* Line 1698, Address: 0x102b4a0 */


    subact1 = ((short*)pActwk)[26]; /* Line 1701, Address: 0x102b4b0 */
    actwk[subact1].r_no0 = 8; /* Line 1702, Address: 0x102b4c0 */
    bup_set(&actwk[subact1]); /* Line 1703, Address: 0x102b4e8 */
    grd_set(&actwk[subact1]); /* Line 1704, Address: 0x102b510 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1705, Address: 0x102b538 */
    actwk[subact1].r_no0 = 6; /* Line 1706, Address: 0x102b564 */

    subact1 = ((short*)pActwk)[27]; /* Line 1708, Address: 0x102b58c */
    actwk[subact1].r_no0 = 2; /* Line 1709, Address: 0x102b59c */
    bup_clr(&actwk[subact1]); /* Line 1710, Address: 0x102b5c4 */
    grd_clr(&actwk[subact1]); /* Line 1711, Address: 0x102b5ec */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1712, Address: 0x102b614 */
    actwk[subact1].r_no0 = 8; /* Line 1713, Address: 0x102b640 */

    armset_1(pActwk); /* Line 1715, Address: 0x102b668 */
  } /* Line 1716, Address: 0x102b674 */
  else
  {
    pActwk->actfree[2] ^= 64; /* Line 1719, Address: 0x102b67c */


    subact1 = ((short*)pActwk)[26]; /* Line 1722, Address: 0x102b68c */
    actwk[subact1].r_no0 = 2; /* Line 1723, Address: 0x102b69c */
    bup_clr(&actwk[subact1]); /* Line 1724, Address: 0x102b6c4 */
    grd_clr(&actwk[subact1]); /* Line 1725, Address: 0x102b6ec */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1726, Address: 0x102b714 */
    actwk[subact1].r_no0 = 8; /* Line 1727, Address: 0x102b740 */

    subact1 = ((short*)pActwk)[27]; /* Line 1729, Address: 0x102b768 */
    actwk[subact1].r_no0 = 8; /* Line 1730, Address: 0x102b77c */
    bup_set(&actwk[subact1]); /* Line 1731, Address: 0x102b7a4 */
    grd_set(&actwk[subact1]); /* Line 1732, Address: 0x102b7cc */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1733, Address: 0x102b7f4 */
    actwk[subact1].r_no0 = 6; /* Line 1734, Address: 0x102b824 */

    armset_2(pActwk); /* Line 1736, Address: 0x102b84c */
  }
  return 1; /* Line 1738, Address: 0x102b858 */
} /* Line 1739, Address: 0x102b860 */




void armset_1(sprite_status* pActwk) { /* Line 1744, Address: 0x102b880 */
  short subact1, subact2;

  subact1 = ((short*)pActwk)[25]; /* Line 1747, Address: 0x102b890 */
  subact2 = ((short*)&actwk[subact1])[27]; /* Line 1748, Address: 0x102b8a0 */
  subact1 = ((short*)&actwk[subact2])[27]; /* Line 1749, Address: 0x102b8cc */
  if (subact1) /* Line 1750, Address: 0x102b8f8 */
  {
    actwk[subact1].r_no0 = 2; /* Line 1752, Address: 0x102b900 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1753, Address: 0x102b928 */
    actwk[subact1].r_no0 = 8; /* Line 1754, Address: 0x102b954 */
    actwk[subact1].patno = 0; /* Line 1755, Address: 0x102b97c */
  }

  subact1 = ((short*)&actwk[subact2])[26]; /* Line 1758, Address: 0x102b9a0 */
  if (subact1) /* Line 1759, Address: 0x102b9cc */
  {
    actwk[subact1].r_no0 = 6; /* Line 1761, Address: 0x102b9d4 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1762, Address: 0x102b9fc */
    actwk[subact1].r_no0 = 6; /* Line 1763, Address: 0x102ba28 */
    actwk[subact1].patno = 0; /* Line 1764, Address: 0x102ba50 */
  }
} /* Line 1766, Address: 0x102ba74 */



void armset_2(sprite_status* pActwk) { /* Line 1770, Address: 0x102ba90 */
  short subact1, subact2;

  subact1 = ((short*)pActwk)[25]; /* Line 1773, Address: 0x102baa0 */
  subact2 = ((short*)&actwk[subact1])[27]; /* Line 1774, Address: 0x102bab0 */
  subact1 = ((short*)&actwk[subact2])[27]; /* Line 1775, Address: 0x102badc */
  if (subact1) /* Line 1776, Address: 0x102bb08 */
  {
    actwk[subact1].r_no0 = 6; /* Line 1778, Address: 0x102bb10 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1779, Address: 0x102bb38 */
    actwk[subact1].r_no0 = 6; /* Line 1780, Address: 0x102bb64 */
    actwk[subact1].patno = 0; /* Line 1781, Address: 0x102bb8c */
  }

  subact1 = ((short*)&actwk[subact2])[26]; /* Line 1784, Address: 0x102bbb0 */
  if (subact1) /* Line 1785, Address: 0x102bbdc */
  {
    actwk[subact1].r_no0 = 2; /* Line 1787, Address: 0x102bbe4 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1788, Address: 0x102bc0c */
    actwk[subact1].r_no0 = 8; /* Line 1789, Address: 0x102bc38 */
    actwk[subact1].patno = 0; /* Line 1790, Address: 0x102bc60 */
  }
} /* Line 1792, Address: 0x102bc84 */



void armset_3(sprite_status* pActwk) { /* Line 1796, Address: 0x102bca0 */
  short subact1, subact2;

  subact1 = ((short*)pActwk)[25]; /* Line 1799, Address: 0x102bcb0 */
  subact2 = ((short*)&actwk[subact1])[27]; /* Line 1800, Address: 0x102bcc0 */
  subact1 = ((short*)&actwk[subact2])[27]; /* Line 1801, Address: 0x102bcec */
  if (subact1) /* Line 1802, Address: 0x102bd18 */
  {
    actwk[subact1].r_no0 = 2; /* Line 1804, Address: 0x102bd20 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1805, Address: 0x102bd48 */
    actwk[subact1].r_no0 = 10; /* Line 1806, Address: 0x102bd74 */
    actwk[subact1].patno = 1; /* Line 1807, Address: 0x102bd9c */
  }

  subact1 = ((short*)&actwk[subact2])[26]; /* Line 1810, Address: 0x102bdc4 */
  if (subact1) /* Line 1811, Address: 0x102bdf0 */
  {
    actwk[subact1].r_no0 = 2; /* Line 1813, Address: 0x102bdf8 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1814, Address: 0x102be20 */
    actwk[subact1].r_no0 = 10; /* Line 1815, Address: 0x102be4c */
    actwk[subact1].patno = 1; /* Line 1816, Address: 0x102be74 */
  }
} /* Line 1818, Address: 0x102be9c */


void spd_up(sprite_status* pActwk) { /* Line 1821, Address: 0x102beb0 */
  short subact1, subact2;

  subact1 = ((short*)pActwk)[26]; /* Line 1824, Address: 0x102bec0 */
  actwk[subact1].actfree[21] = 8; /* Line 1825, Address: 0x102bed0 */
  subact1 = ((short*)&actwk[subact1])[26]; /* Line 1826, Address: 0x102bef8 */
  ((int*)&actwk[subact1])[16] = 65536; /* Line 1827, Address: 0x102bf24 */
  ((int*)&actwk[subact1])[4] = 32768; /* Line 1828, Address: 0x102bf4c */
  subact1 = ((short*)&actwk[subact1])[26]; /* Line 1829, Address: 0x102bf74 */
  ((int*)&actwk[subact1])[16] = 49152; /* Line 1830, Address: 0x102bfa0 */
  ((int*)&actwk[subact1])[4] = 98304; /* Line 1831, Address: 0x102bfc8 */

  subact1 = ((short*)pActwk)[27]; /* Line 1833, Address: 0x102bff4 */
  actwk[subact1].actfree[21] = 8; /* Line 1834, Address: 0x102c004 */
  subact1 = ((short*)&actwk[subact1])[26]; /* Line 1835, Address: 0x102c02c */
  ((int*)&actwk[subact1])[16] = 65536; /* Line 1836, Address: 0x102c058 */
  ((int*)&actwk[subact1])[4] = 32768; /* Line 1837, Address: 0x102c080 */
  subact1 = ((short*)&actwk[subact1])[26]; /* Line 1838, Address: 0x102c0a8 */
  ((int*)&actwk[subact1])[16] = 49152; /* Line 1839, Address: 0x102c0d4 */
  ((int*)&actwk[subact1])[4] = 98304; /* Line 1840, Address: 0x102c0fc */

  subact1 = ((short*)pActwk)[25]; /* Line 1842, Address: 0x102c128 */
  subact2 = ((short*)&actwk[subact1])[27]; /* Line 1843, Address: 0x102c138 */
  subact1 = ((short*)&actwk[subact2])[27]; /* Line 1844, Address: 0x102c164 */
  if (subact1) /* Line 1845, Address: 0x102c190 */
  {
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1847, Address: 0x102c198 */
    actwk[subact1].actfree[2] |= 128; /* Line 1848, Address: 0x102c1c4 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1849, Address: 0x102c1f0 */
    actwk[subact1].actfree[2] |= 128; /* Line 1850, Address: 0x102c21c */
  }

  subact1 = ((short*)&actwk[subact2])[26]; /* Line 1853, Address: 0x102c248 */
  if (subact1) /* Line 1854, Address: 0x102c274 */
  {
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1856, Address: 0x102c27c */
    actwk[subact1].actfree[2] |= 128; /* Line 1857, Address: 0x102c2a8 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1858, Address: 0x102c2d4 */
    actwk[subact1].actfree[2] |= 128; /* Line 1859, Address: 0x102c300 */
  }
} /* Line 1861, Address: 0x102c32c */





int egg1body_05(sprite_status* pActwk) { /* Line 1867, Address: 0x102c340 */
  short subact1;
  short subact2;
  short subact3;
  short subact4;

  if (!(pActwk->actfree[2] & 64)) /* Line 1873, Address: 0x102c35c */
  {

    subact1 = ((short*)pActwk)[26]; /* Line 1876, Address: 0x102c374 */
    subact2 = ((short*)pActwk)[27]; /* Line 1877, Address: 0x102c388 */
  } /* Line 1878, Address: 0x102c398 */
  else
  {

    subact1 = ((short*)pActwk)[27]; /* Line 1882, Address: 0x102c3a0 */
    subact2 = ((short*)pActwk)[26]; /* Line 1883, Address: 0x102c3b0 */
  }

  if (!(actwk[subact1].actfree[2] & 1)) /* Line 1886, Address: 0x102c3c0 */
    return 1; /* Line 1887, Address: 0x102c3f4 */
  if (!(actwk[subact2].actfree[2] & 1)) /* Line 1888, Address: 0x102c400 */
    return 1; /* Line 1889, Address: 0x102c434 */

  if (!(pActwk->actfree[2] & 2)) /* Line 1891, Address: 0x102c440 */
  {
    pActwk->actfree[2] |= 2; /* Line 1893, Address: 0x102c458 */
    spd_normal(pActwk); /* Line 1894, Address: 0x102c468 */
  } /* Line 1895, Address: 0x102c474 */
  else
  {

    subact3 = ((short*)&actwk[subact1])[26]; /* Line 1899, Address: 0x102c47c */
    subact3 = ((short*)&actwk[subact3])[26]; /* Line 1900, Address: 0x102c4a8 */
    subact4 = ((short*)&actwk[subact2])[26]; /* Line 1901, Address: 0x102c4d4 */
    actwk[subact1].actfree[2] &= 254; /* Line 1902, Address: 0x102c500 */
    actwk[subact3].actfree[2] &= 254; /* Line 1903, Address: 0x102c52c */
    actwk[subact2].actfree[2] &= 254; /* Line 1904, Address: 0x102c558 */
    actwk[subact4].actfree[2] &= 254; /* Line 1905, Address: 0x102c584 */

    if (pActwk->xposi.w.h >= 2976) /* Line 1907, Address: 0x102c5b0 */
      pActwk->actfree[3] = 1; /* Line 1908, Address: 0x102c5cc */

    --pActwk->actfree[3]; /* Line 1910, Address: 0x102c5d8 */
    if (!pActwk->actfree[3]) /* Line 1911, Address: 0x102c5e8 */
    {
      pActwk->actfree[2] &= 253; /* Line 1913, Address: 0x102c5f8 */
      pActwk->actfree[2] |= 1; /* Line 1914, Address: 0x102c608 */
      return 1; /* Line 1915, Address: 0x102c618 */
    }
  }


  if (pActwk->actfree[2] & 64) /* Line 1920, Address: 0x102c624 */
  {
    pActwk->actfree[2] ^= 64; /* Line 1922, Address: 0x102c63c */


    subact1 = ((short*)pActwk)[26]; /* Line 1925, Address: 0x102c64c */
    actwk[subact1].r_no0 = 22; /* Line 1926, Address: 0x102c65c */
    bup_set(&actwk[subact1]); /* Line 1927, Address: 0x102c684 */
    grd_set(&actwk[subact1]); /* Line 1928, Address: 0x102c6ac */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1929, Address: 0x102c6d4 */
    actwk[subact1].r_no0 = 8; /* Line 1930, Address: 0x102c700 */

    subact1 = ((short*)pActwk)[27]; /* Line 1932, Address: 0x102c728 */
    actwk[subact1].r_no0 = 18; /* Line 1933, Address: 0x102c738 */
    bup_clr(&actwk[subact1]); /* Line 1934, Address: 0x102c760 */
    grd_clr(&actwk[subact1]); /* Line 1935, Address: 0x102c788 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1936, Address: 0x102c7b0 */
    actwk[subact1].r_no0 = 6; /* Line 1937, Address: 0x102c7dc */

    armset_2(pActwk); /* Line 1939, Address: 0x102c804 */
  } /* Line 1940, Address: 0x102c810 */
  else
  {
    pActwk->actfree[2] ^= 64; /* Line 1943, Address: 0x102c818 */


    subact1 = ((short*)pActwk)[26]; /* Line 1946, Address: 0x102c828 */
    actwk[subact1].r_no0 = 18; /* Line 1947, Address: 0x102c838 */
    bup_clr(&actwk[subact1]); /* Line 1948, Address: 0x102c860 */
    grd_clr(&actwk[subact1]); /* Line 1949, Address: 0x102c888 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1950, Address: 0x102c8b0 */
    actwk[subact1].r_no0 = 6; /* Line 1951, Address: 0x102c8e0 */

    subact1 = ((short*)pActwk)[27]; /* Line 1953, Address: 0x102c908 */
    actwk[subact1].r_no0 = 22; /* Line 1954, Address: 0x102c91c */
    bup_set(&actwk[subact1]); /* Line 1955, Address: 0x102c944 */
    grd_set(&actwk[subact1]); /* Line 1956, Address: 0x102c96c */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 1957, Address: 0x102c998 */
    actwk[subact1].r_no0 = 8; /* Line 1958, Address: 0x102c9c8 */

    armset_1(pActwk); /* Line 1960, Address: 0x102c9f0 */
  }
  return 1; /* Line 1962, Address: 0x102c9fc */
} /* Line 1963, Address: 0x102ca00 */




int egg1body_06(sprite_status* pActwk) { /* Line 1968, Address: 0x102ca20 */
  short subact1;
  short subact2;
  short subact3;
  short subact4;

  if (!(pActwk->actfree[2] & 64)) /* Line 1974, Address: 0x102ca3c */
  {

    subact1 = ((short*)pActwk)[26]; /* Line 1977, Address: 0x102ca54 */
    subact2 = ((short*)pActwk)[27]; /* Line 1978, Address: 0x102ca68 */
  } /* Line 1979, Address: 0x102ca78 */
  else
  {

    subact1 = ((short*)pActwk)[27]; /* Line 1983, Address: 0x102ca80 */
    subact2 = ((short*)pActwk)[26]; /* Line 1984, Address: 0x102ca94 */
  }

  if (!(pActwk->actfree[2] & 2)) /* Line 1987, Address: 0x102caa4 */
  {
    pActwk->actfree[2] |= 2; /* Line 1989, Address: 0x102cabc */
    spd_up(pActwk); /* Line 1990, Address: 0x102cacc */
  }
  if (actwk[subact1].r_no0 == 4) /* Line 1992, Address: 0x102cad8 */
  {

    subact3 = ((short*)&actwk[subact1])[26]; /* Line 1995, Address: 0x102cb0c */
    actwk[subact3].r_no0 = 10; /* Line 1996, Address: 0x102cb38 */
    subact3 = ((short*)&actwk[subact2])[26]; /* Line 1997, Address: 0x102cb60 */
    actwk[subact3].r_no0 = 12; /* Line 1998, Address: 0x102cb8c */
  }

  if (!(actwk[subact1].actfree[2] & 1)) /* Line 2001, Address: 0x102cbb4 */
    return 1; /* Line 2002, Address: 0x102cbe8 */

  if (!(actwk[subact2].actfree[2] & 1)) /* Line 2004, Address: 0x102cbf4 */
    return 1; /* Line 2005, Address: 0x102cc28 */

  subact3 = ((short*)&actwk[subact1])[26]; /* Line 2007, Address: 0x102cc34 */
  subact3 = ((short*)&actwk[subact3])[26]; /* Line 2008, Address: 0x102cc60 */
  subact4 = ((short*)&actwk[subact2])[26]; /* Line 2009, Address: 0x102cc8c */
  actwk[subact1].actfree[2] &= 254; /* Line 2010, Address: 0x102ccb8 */
  actwk[subact3].actfree[2] &= 254; /* Line 2011, Address: 0x102cce4 */
  actwk[subact2].actfree[2] &= 254; /* Line 2012, Address: 0x102cd10 */
  actwk[subact4].actfree[2] &= 254; /* Line 2013, Address: 0x102cd3c */

  --pActwk->actfree[3]; /* Line 2015, Address: 0x102cd68 */
  if (!pActwk->actfree[3]) /* Line 2016, Address: 0x102cd78 */
  {
    pActwk->actfree[2] |= 1; /* Line 2018, Address: 0x102cd88 */
    pActwk->actfree[2] &= 253; /* Line 2019, Address: 0x102cd98 */
    return 1; /* Line 2020, Address: 0x102cda8 */
  }


  if (pActwk->actfree[2] & 64) /* Line 2024, Address: 0x102cdb4 */
  {
    pActwk->actfree[2] ^= 64; /* Line 2026, Address: 0x102cdcc */


    subact1 = ((short*)pActwk)[26]; /* Line 2029, Address: 0x102cddc */
    actwk[subact1].actfree[2] &= 253; /* Line 2030, Address: 0x102cdec */
    bup_set(&actwk[subact1]); /* Line 2031, Address: 0x102ce18 */
    grd_set(&actwk[subact1]); /* Line 2032, Address: 0x102ce40 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 2033, Address: 0x102ce68 */
    actwk[subact1].r_no0 = 10; /* Line 2034, Address: 0x102ce94 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 2035, Address: 0x102cebc */
    actwk[subact1].r_no0 = 2; /* Line 2036, Address: 0x102cee8 */

    subact1 = ((short*)pActwk)[27]; /* Line 2038, Address: 0x102cf10 */
    actwk[subact1].actfree[2] &= 253; /* Line 2039, Address: 0x102cf20 */
    actwk[subact1].r_no0 = 2; /* Line 2040, Address: 0x102cf4c */
    bup_clr(&actwk[subact1]); /* Line 2041, Address: 0x102cf74 */
    grd_clr(&actwk[subact1]); /* Line 2042, Address: 0x102cf9c */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 2043, Address: 0x102cfc4 */
    actwk[subact1].r_no0 = 12; /* Line 2044, Address: 0x102cff4 */

    armset_3(pActwk); /* Line 2046, Address: 0x102d01c */

  } /* Line 2048, Address: 0x102d028 */
  else
  {
    pActwk->actfree[2] ^= 64; /* Line 2051, Address: 0x102d030 */


    subact1 = ((short*)pActwk)[26]; /* Line 2054, Address: 0x102d040 */
    actwk[subact1].actfree[2] &= 253; /* Line 2055, Address: 0x102d054 */
    actwk[subact1].r_no0 = 2; /* Line 2056, Address: 0x102d080 */
    bup_clr(&actwk[subact1]); /* Line 2057, Address: 0x102d0a8 */
    grd_clr(&actwk[subact1]); /* Line 2058, Address: 0x102d0d0 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 2059, Address: 0x102d0f8 */
    actwk[subact1].r_no0 = 12; /* Line 2060, Address: 0x102d128 */

    subact1 = ((short*)pActwk)[27]; /* Line 2062, Address: 0x102d150 */
    actwk[subact1].actfree[2] &= 253; /* Line 2063, Address: 0x102d164 */
    bup_set(&actwk[subact1]); /* Line 2064, Address: 0x102d190 */
    grd_set(&actwk[subact1]); /* Line 2065, Address: 0x102d1b8 */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 2066, Address: 0x102d1e0 */
    actwk[subact1].r_no0 = 10; /* Line 2067, Address: 0x102d20c */
    subact1 = ((short*)&actwk[subact1])[26]; /* Line 2068, Address: 0x102d234 */
    actwk[subact1].r_no0 = 2; /* Line 2069, Address: 0x102d260 */

    armset_3(pActwk); /* Line 2071, Address: 0x102d288 */
  }

  return 1; /* Line 2074, Address: 0x102d294 */
} /* Line 2075, Address: 0x102d298 */




int egg1body_07(sprite_status* pActwk) { /* Line 2080, Address: 0x102d2c0 */
  int ret = 1; /* Line 2081, Address: 0x102d2d4 */
  short subact;

  if (!(pActwk->actfree[2] & 1)) /* Line 2084, Address: 0x102d2d8 */
  {
    if (emycol_d(pActwk) > 0) /* Line 2086, Address: 0x102d2f0 */
    {
      subact = ((short*)pActwk)[25]; /* Line 2088, Address: 0x102d30c */
      pActwk->yposi.w.h += 2; /* Line 2089, Address: 0x102d31c */
      actwk[subact].yposi.w.h += 2; /* Line 2090, Address: 0x102d32c */
    }
  } /* Line 2092, Address: 0x102d358 */
  else
  {

    ret = 0; /* Line 2096, Address: 0x102d360 */
    frameout(pActwk); /* Line 2097, Address: 0x102d364 */
  }
  return ret; /* Line 2099, Address: 0x102d370 */
} /* Line 2100, Address: 0x102d374 */




void arm_bom(sprite_status* pActwk) { /* Line 2105, Address: 0x102d390 */
  sprite_status* subActwk;

  if (actwkchk(&subActwk) == 0) /* Line 2108, Address: 0x102d39c */
  {
    subActwk->r_no1 = 255; /* Line 2110, Address: 0x102d3b0 */
    subActwk->actno = 24; /* Line 2111, Address: 0x102d3bc */
    subActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 2112, Address: 0x102d3c8 */
    subActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 2113, Address: 0x102d3d8 */
    soundset(158); /* Line 2114, Address: 0x102d3e8 */
  }
} /* Line 2116, Address: 0x102d3f4 */







void egg1arm1(sprite_status* pActwk) { /* Line 2124, Address: 0x102d410 */
  int(*tbl[3])(sprite_status*) = /* Line 2125, Address: 0x102d41c */
  {
    &egg1arm1_ini,
    &egg1arm1_01,
    &egg1arm1_02
  };

  if (tbl[pActwk->r_no0 / 2](pActwk) == 0) return; /* Line 2132, Address: 0x102d440 */
  actionsub(pActwk); /* Line 2133, Address: 0x102d484 */
} /* Line 2134, Address: 0x102d490 */



int egg1arm1_ini(sprite_status* pActwk) { /* Line 2138, Address: 0x102d4a0 */
  int ret = 1; /* Line 2139, Address: 0x102d4b0 */

  pActwk->cddat = 0; /* Line 2141, Address: 0x102d4b4 */
  pActwk->actflg = 4; /* Line 2142, Address: 0x102d4bc */
  pActwk->sprhsize = 16; /* Line 2143, Address: 0x102d4c8 */
  pActwk->sprvsize = 12; /* Line 2144, Address: 0x102d4d4 */
  pActwk->sproffset = 9049; /* Line 2145, Address: 0x102d4e0 */
  pActwk->patbase = egg1arm1_pat; /* Line 2146, Address: 0x102d4ec */
  pActwk->r_no0 = 2; /* Line 2147, Address: 0x102d4fc */
  ret = egg1arm1_01(pActwk); /* Line 2148, Address: 0x102d508 */
  return ret; /* Line 2149, Address: 0x102d518 */
} /* Line 2150, Address: 0x102d51c */



int egg1arm1_01(sprite_status* pActwk) { /* Line 2154, Address: 0x102d530 */
  short subact;

  subact = ((short*)pActwk)[25]; /* Line 2157, Address: 0x102d53c */
  pActwk->xposi.w.h = actwk[subact].xposi.w.h + 24; /* Line 2158, Address: 0x102d54c */
  pActwk->yposi.w.h = actwk[subact].yposi.w.h - 12; /* Line 2159, Address: 0x102d58c */

  if (pActwk->actfree[2] & 64) /* Line 2161, Address: 0x102d5cc */
  {
    pActwk->actfree[2] &= 191; /* Line 2163, Address: 0x102d5e4 */

    subact = ((short*)pActwk)[26]; /* Line 2165, Address: 0x102d5f4 */
    actwk[subact].r_no0 = 10; /* Line 2166, Address: 0x102d604 */
    ((short*)pActwk)[26] = 0; /* Line 2167, Address: 0x102d62c */
    subact = ((short*)pActwk)[27]; /* Line 2168, Address: 0x102d634 */
    subact = ((short*)&actwk[subact])[26]; /* Line 2169, Address: 0x102d644 */
    return 1; /* Line 2170, Address: 0x102d670 */
  }
  if (pActwk->actfree[2] & 32) /* Line 2172, Address: 0x102d67c */
  {
    pActwk->actfree[2] &= 223; /* Line 2174, Address: 0x102d694 */

    subact = ((short*)pActwk)[27]; /* Line 2176, Address: 0x102d6a4 */
    actwk[subact].r_no0 = 10; /* Line 2177, Address: 0x102d6b4 */
    ((short*)pActwk)[27] = 0; /* Line 2178, Address: 0x102d6dc */
    actwk[subact].patno = 0; /* Line 2179, Address: 0x102d6e4 */
    return 1; /* Line 2180, Address: 0x102d708 */
  }
  return 1; /* Line 2182, Address: 0x102d714 */
} /* Line 2183, Address: 0x102d718 */




int egg1arm1_02(sprite_status* pActwk) { /* Line 2188, Address: 0x102d730 */
  int ret = 1; /* Line 2189, Address: 0x102d740 */

  if (!(pActwk->actfree[2] & 2)) /* Line 2191, Address: 0x102d744 */
  {

    ((int*)pActwk)[16] = -65536; /* Line 2194, Address: 0x102d75c */
    ((int*)pActwk)[4] = -131072; /* Line 2195, Address: 0x102d768 */
  } /* Line 2196, Address: 0x102d774 */
  else
  {

    ((int*)pActwk)[16] -= 1536; /* Line 2200, Address: 0x102d77c */
    ((int*)pActwk)[4] += 6144; /* Line 2201, Address: 0x102d78c */
  }
  pActwk->actfree[2] |= 2; /* Line 2203, Address: 0x102d79c */
  pActwk->xposi.l += ((int*)pActwk)[16]; /* Line 2204, Address: 0x102d7ac */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 2205, Address: 0x102d7c4 */

  if (pActwk->yposi.w.h >= 576) /* Line 2207, Address: 0x102d7dc */
  {
    ret = 0; /* Line 2209, Address: 0x102d7f8 */
    frameout(pActwk); /* Line 2210, Address: 0x102d7fc */
  } /* Line 2211, Address: 0x102d808 */
  else
    tenmetu(); /* Line 2213, Address: 0x102d810 */
  return ret; /* Line 2214, Address: 0x102d818 */
} /* Line 2215, Address: 0x102d81c */






void egg1arm2(sprite_status* pActwk) { /* Line 2222, Address: 0x102d830 */
  int(*tbl[6])(sprite_status*) = /* Line 2223, Address: 0x102d83c */
  {
    &egg1arm2_ini,
    &egg1arm2_01,
    &egg1arm2_02,
    &egg1arm2_03,
    &egg1arm2_04,
    &egg1arm2_05
  };

  if (tbl[pActwk->r_no0 / 2](pActwk) != 0) /* Line 2233, Address: 0x102d870 */
  {
    if (!(pActwk->actfree[2] & 4)) /* Line 2235, Address: 0x102d8b4 */
      actionsub(pActwk); /* Line 2236, Address: 0x102d8cc */
  }
} /* Line 2238, Address: 0x102d8d8 */



int egg1arm2_ini(sprite_status* pActwk) { /* Line 2242, Address: 0x102d8f0 */
  pActwk->cddat = 0; /* Line 2243, Address: 0x102d8fc */
  pActwk->actflg = 4; /* Line 2244, Address: 0x102d904 */
  pActwk->sprhsize = 8; /* Line 2245, Address: 0x102d910 */
  pActwk->sprvsize = 8; /* Line 2246, Address: 0x102d91c */
  pActwk->sproffset = 9049; /* Line 2247, Address: 0x102d928 */
  pActwk->patbase = egg1arm2_pat; /* Line 2248, Address: 0x102d934 */
  pActwk->r_no0 = 6; /* Line 2249, Address: 0x102d944 */
  egg1arm2_01(pActwk); /* Line 2250, Address: 0x102d950 */
  return 1; /* Line 2251, Address: 0x102d95c */
} /* Line 2252, Address: 0x102d960 */




int egg1arm2_01(sprite_status* pActwk) { /* Line 2257, Address: 0x102d970 */
  ((char*)pActwk)[46] -= 2; /* Line 2258, Address: 0x102d97c */
  if (((char*)pActwk)[46] > 0) /* Line 2259, Address: 0x102d98c */
    egg1arm2_set(pActwk); /* Line 2260, Address: 0x102d9a4 */
  else
  {
    pActwk->r_no0 = 4; /* Line 2263, Address: 0x102d9b8 */
    ((char*)pActwk)[46] = 0; /* Line 2264, Address: 0x102d9c4 */
    pActwk->actfree[2] |= 1; /* Line 2265, Address: 0x102d9cc */
    egg1arm2_set(pActwk); /* Line 2266, Address: 0x102d9dc */
  }
  return 1; /* Line 2268, Address: 0x102d9e8 */
} /* Line 2269, Address: 0x102d9ec */




int egg1arm2_03(sprite_status* pActwk) { /* Line 2274, Address: 0x102da00 */
  ((char*)pActwk)[46] += 2; /* Line 2275, Address: 0x102da0c */
  if (((char*)pActwk)[46] < 48) /* Line 2276, Address: 0x102da1c */
    egg1arm2_set(pActwk); /* Line 2277, Address: 0x102da38 */
  else
  {
    pActwk->r_no0 = 8; /* Line 2280, Address: 0x102da4c */
    ((char*)pActwk)[46] = 48; /* Line 2281, Address: 0x102da58 */
    pActwk->actfree[2] |= 1; /* Line 2282, Address: 0x102da64 */
    egg1arm2_set(pActwk); /* Line 2283, Address: 0x102da74 */
  }
  return 1; /* Line 2285, Address: 0x102da80 */
} /* Line 2286, Address: 0x102da84 */



int egg1arm2_02(sprite_status* pActwk) { /* Line 2290, Address: 0x102daa0 */
  egg1arm2_set(pActwk); /* Line 2291, Address: 0x102daac */
  return 1; /* Line 2292, Address: 0x102dab8 */
} /* Line 2293, Address: 0x102dabc */


int egg1arm2_04(sprite_status* pActwk) { /* Line 2296, Address: 0x102dad0 */
  egg1arm2_set(pActwk); /* Line 2297, Address: 0x102dadc */
  return 1; /* Line 2298, Address: 0x102dae8 */
} /* Line 2299, Address: 0x102daec */



int egg1arm2_05(sprite_status* pActwk) { /* Line 2303, Address: 0x102db00 */
  int ret = 1; /* Line 2304, Address: 0x102db14 */
  short subact;

  if (!(pActwk->actfree[2] & 2)) /* Line 2307, Address: 0x102db18 */
  {
    pActwk->actfree[2] |= 2; /* Line 2309, Address: 0x102db30 */

    ((int*)pActwk)[16] = 65536; /* Line 2311, Address: 0x102db40 */
    ((int*)pActwk)[4] = -131072; /* Line 2312, Address: 0x102db4c */
    subact = ((short*)pActwk)[26]; /* Line 2313, Address: 0x102db58 */
    actwk[subact].r_no0 = 4; /* Line 2314, Address: 0x102db68 */
  } /* Line 2315, Address: 0x102db90 */
  else
  {

    ((int*)pActwk)[16] += 1536; /* Line 2319, Address: 0x102db98 */
    ((int*)pActwk)[4] += 7936; /* Line 2320, Address: 0x102dba8 */
  }
  pActwk->xposi.l += ((int*)pActwk)[16]; /* Line 2322, Address: 0x102dbb8 */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 2323, Address: 0x102dbd0 */

  if (pActwk->yposi.l >= 576) /* Line 2325, Address: 0x102dbe8 */
  {
    ret = 0; /* Line 2327, Address: 0x102dbfc */
    frameout(pActwk); /* Line 2328, Address: 0x102dc00 */
  } /* Line 2329, Address: 0x102dc0c */
  else
    tenmetu(); /* Line 2331, Address: 0x102dc14 */
  return ret; /* Line 2332, Address: 0x102dc1c */
} /* Line 2333, Address: 0x102dc20 */



void egg1arm2_set(sprite_status* pActwk) { /* Line 2337, Address: 0x102dc40 */
  short subact;
  unsigned short sin, cos;
  int_union sinl, cosl;

  subact = ((short*)pActwk)[25]; /* Line 2342, Address: 0x102dc50 */
  pActwk->xposi.w.h = actwk[subact].xposi.w.h; /* Line 2343, Address: 0x102dc60 */
  pActwk->yposi.w.h = actwk[subact].yposi.w.h; /* Line 2344, Address: 0x102dc8c */

  sinset(pActwk->actfree[0] + 64, (short*)&sin, (short*)&cos); /* Line 2346, Address: 0x102dcb8 */
  sinl.l = sin; /* Line 2347, Address: 0x102dcdc */
  cosl.l = cos; /* Line 2348, Address: 0x102dce8 */
  sinl.w.l /= 16; /* Line 2349, Address: 0x102dcf4 */
  cosl.w.l /= 16; /* Line 2350, Address: 0x102dd14 */
  pActwk->xposi.w.h += cosl.w.l; /* Line 2351, Address: 0x102dd34 */
  pActwk->yposi.w.h += sinl.w.l; /* Line 2352, Address: 0x102dd48 */

  if (pActwk->actfree[2] & 4) /* Line 2354, Address: 0x102dd5c */
    pActwk->xposi.w.h -= 10; /* Line 2355, Address: 0x102dd74 */
} /* Line 2356, Address: 0x102dd84 */






void egg1arm3(sprite_status* pActwk) { /* Line 2363, Address: 0x102dda0 */
  int(*tbl[6])(sprite_status*) = /* Line 2364, Address: 0x102ddac */
  {
    &egg1arm3_ini,
    &egg1arm3_01,
    &egg1arm3_02,
    &egg1arm3_03,
    &egg1arm3_04,
    &egg1arm3_05
  };

  if (tbl[pActwk->r_no0 / 2](pActwk) != 0) /* Line 2374, Address: 0x102dde0 */
  {
    actionsub(pActwk); /* Line 2376, Address: 0x102de24 */
  }

} /* Line 2379, Address: 0x102de30 */



int egg1arm3_ini(sprite_status* pActwk) { /* Line 2383, Address: 0x102de40 */
  pActwk->cddat = 0; /* Line 2384, Address: 0x102de4c */
  pActwk->actflg = 4; /* Line 2385, Address: 0x102de54 */
  pActwk->sprhsize = 32; /* Line 2386, Address: 0x102de60 */
  pActwk->sprvsize = 8; /* Line 2387, Address: 0x102de6c */
  pActwk->sproffset = 9049; /* Line 2388, Address: 0x102de78 */
  pActwk->r_no0 = 2; /* Line 2389, Address: 0x102de84 */
  egg1arm3_01(pActwk); /* Line 2390, Address: 0x102de90 */
  return 1; /* Line 2391, Address: 0x102de9c */
} /* Line 2392, Address: 0x102dea0 */




int egg1arm3_01(sprite_status* pActwk) { /* Line 2397, Address: 0x102deb0 */
  short subact;

  subact = ((short*)pActwk)[25]; /* Line 2400, Address: 0x102debc */
  pActwk->xposi.w.h = ((short*)pActwk)[29] + (actwk[subact].xposi.w.h - 36); /* Line 2401, Address: 0x102decc */

  pActwk->yposi.w.h = (int)actwk[subact].yposi.w.h; /* Line 2403, Address: 0x102df20 */

  if (!(pActwk->actfree[2] & 128)) /* Line 2405, Address: 0x102df5c */
  {
    if (actwk[0].yposi.w.h <= pActwk->yposi.w.h) /* Line 2407, Address: 0x102df74 */
    {

      if (((short*)pActwk)[31] > -8) /* Line 2410, Address: 0x102dfa0 */
        ((int*)pActwk)[15] -= 65536; /* Line 2411, Address: 0x102dfbc */
    } /* Line 2412, Address: 0x102dfd0 */
    else
    {

      if (((short*)pActwk)[31] < 8) /* Line 2416, Address: 0x102dfd8 */
        ((int*)pActwk)[15] += 65536; /* Line 2417, Address: 0x102dff4 */
    }
    pActwk->yposi.w.h += ((short*)pActwk)[31]; /* Line 2419, Address: 0x102e008 */
    return 1; /* Line 2420, Address: 0x102e020 */
  }
} /* Line 2422, Address: 0x102e024 */




int egg1arm3_03(sprite_status* pActwk) { /* Line 2427, Address: 0x102e040 */
  int ret = 1; /* Line 2428, Address: 0x102e050 */

  if (((short*)pActwk)[29] > 0) /* Line 2430, Address: 0x102e054 */
    ((int*)pActwk)[14] -= 32768; /* Line 2431, Address: 0x102e06c */
  ret = egg1arm3_01(pActwk); /* Line 2432, Address: 0x102e07c */
  return ret; /* Line 2433, Address: 0x102e08c */
} /* Line 2434, Address: 0x102e090 */




int egg1arm3_04(sprite_status* pActwk) { /* Line 2439, Address: 0x102e0b0 */
  int ret = 1; /* Line 2440, Address: 0x102e0c0 */

  if (((short*)pActwk)[29] < 16) /* Line 2442, Address: 0x102e0c4 */
    ((int*)pActwk)[14] += 32768; /* Line 2443, Address: 0x102e0e0 */
  ret = egg1arm3_01(pActwk); /* Line 2444, Address: 0x102e0f4 */
  return ret; /* Line 2445, Address: 0x102e104 */
} /* Line 2446, Address: 0x102e108 */




int egg1arm3_05(sprite_status* pActwk) { /* Line 2451, Address: 0x102e120 */
  short subact;

  if (((short*)pActwk)[29] < 8) /* Line 2454, Address: 0x102e12c */
    ((int*)pActwk)[14] += 32768; /* Line 2455, Address: 0x102e148 */
  else
    pActwk->patno = 1; /* Line 2457, Address: 0x102e164 */
  subact = ((short*)pActwk)[25]; /* Line 2458, Address: 0x102e170 */
  pActwk->xposi.w.h = ((short*)pActwk)[29] + (actwk[subact].xposi.w.h - 36); /* Line 2459, Address: 0x102e180 */
  pActwk->yposi.w.h = (int)actwk[subact].yposi.w.h; /* Line 2460, Address: 0x102e1d4 */

  if (((short*)pActwk)[31] < 8) /* Line 2462, Address: 0x102e210 */
    ((int*)pActwk)[15] += 65536; /* Line 2463, Address: 0x102e22c */
  pActwk->yposi.w.h += ((short*)pActwk)[31]; /* Line 2464, Address: 0x102e240 */
  return 1; /* Line 2465, Address: 0x102e258 */
} /* Line 2466, Address: 0x102e25c */




int egg1arm3_02(sprite_status* pActwk) { /* Line 2471, Address: 0x102e270 */
  int ret = 1; /* Line 2472, Address: 0x102e284 */
  short subact;

  if (!(pActwk->actfree[2] & 2)) /* Line 2475, Address: 0x102e288 */
  {
    pActwk->actfree[2] |= 2; /* Line 2477, Address: 0x102e2a0 */

    pActwk->actfree[1] = 1; /* Line 2479, Address: 0x102e2b0 */
    pActwk->actfree[0] = 0; /* Line 2480, Address: 0x102e2bc */
    ((int*)pActwk)[16] = 0; /* Line 2481, Address: 0x102e2c4 */
    ((int*)pActwk)[4] = 65536; /* Line 2482, Address: 0x102e2cc */
    subact = ((short*)pActwk)[26]; /* Line 2483, Address: 0x102e2d8 */
    actwk[subact].r_no0 = 4; /* Line 2484, Address: 0x102e2e8 */
  } /* Line 2485, Address: 0x102e310 */
  else
  {

    ((int*)pActwk)[16] -= 1568; /* Line 2489, Address: 0x102e318 */
    ((int*)pActwk)[4] += 4640; /* Line 2490, Address: 0x102e328 */
  }
  pActwk->xposi.l += ((int*)pActwk)[16]; /* Line 2492, Address: 0x102e338 */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 2493, Address: 0x102e350 */

  if (pActwk->yposi.w.h >= 576) /* Line 2495, Address: 0x102e368 */
  {
    ret = 0; /* Line 2497, Address: 0x102e384 */
    frameout(pActwk); /* Line 2498, Address: 0x102e388 */
  } /* Line 2499, Address: 0x102e394 */
  else
  {
    ++pActwk->actfree[0]; /* Line 2502, Address: 0x102e39c */
    if (((short*)pActwk)[23] % 7 == 0) /* Line 2503, Address: 0x102e3ac */
      arm_bom(pActwk); /* Line 2504, Address: 0x102e3d0 */
    tenmetu(); /* Line 2505, Address: 0x102e3dc */
  }
  return ret; /* Line 2507, Address: 0x102e3e4 */
} /* Line 2508, Address: 0x102e3e8 */






void egg1arm4(sprite_status* pActwk) { /* Line 2515, Address: 0x102e400 */
  int(*tbl[3])(sprite_status*) = /* Line 2516, Address: 0x102e40c */
  {
    &egg1arm4_ini,
    &egg1arm4_01,
    &egg1arm4_02
  };

  if (tbl[pActwk->r_no0 / 2](pActwk) == 0) return; /* Line 2523, Address: 0x102e430 */
  actionsub(pActwk); /* Line 2524, Address: 0x102e474 */
} /* Line 2525, Address: 0x102e480 */



int egg1arm4_ini(sprite_status* pActwk) { /* Line 2529, Address: 0x102e490 */
  pActwk->cddat = 0; /* Line 2530, Address: 0x102e498 */
  pActwk->actflg = 4; /* Line 2531, Address: 0x102e4a0 */
  pActwk->sprhsize = 12; /* Line 2532, Address: 0x102e4ac */
  pActwk->sprvsize = 16; /* Line 2533, Address: 0x102e4b8 */
  pActwk->sproffset = 9049; /* Line 2534, Address: 0x102e4c4 */
  pActwk->patbase = egg1arm4_pat; /* Line 2535, Address: 0x102e4d0 */
  pActwk->r_no0 = 2; /* Line 2536, Address: 0x102e4e0 */
  return 1; /* Line 2537, Address: 0x102e4ec */
} /* Line 2538, Address: 0x102e4f0 */



int egg1arm4_01(sprite_status* pActwk) { /* Line 2542, Address: 0x102e500 */
  short subact;


  subact = ((short*)pActwk)[25]; /* Line 2546, Address: 0x102e50c */
  pActwk->xposi.w.h = actwk[subact].xposi.w.h - 12; /* Line 2547, Address: 0x102e51c */
  pActwk->yposi.w.h = actwk[subact].yposi.w.h; /* Line 2548, Address: 0x102e55c */

  if (actwk[subact].patno) /* Line 2550, Address: 0x102e588 */
  {
    if (actwk[subact].patno != 1) /* Line 2552, Address: 0x102e5b4 */
      pActwk->xposi.w.h += 8; /* Line 2553, Address: 0x102e5e8 */
    else
      pActwk->xposi.w.h += 16; /* Line 2555, Address: 0x102e600 */
  }

  if (pActwk->actfree[2] & 16) /* Line 2558, Address: 0x102e610 */
    pActwk->xposi.w.h -= 4; /* Line 2559, Address: 0x102e628 */
  pActwk->actfree[2] &= 239; /* Line 2560, Address: 0x102e638 */
  return 1; /* Line 2561, Address: 0x102e648 */































} /* Line 2593, Address: 0x102e64c */




int egg1arm4_02(sprite_status* pActwk) { /* Line 2598, Address: 0x102e660 */
  int ret = 1; /* Line 2599, Address: 0x102e670 */

  if (!(pActwk->actfree[2] & 2)) /* Line 2601, Address: 0x102e674 */
  {
    pActwk->actfree[2] |= 2; /* Line 2603, Address: 0x102e68c */

    pActwk->actfree[1] = 0; /* Line 2605, Address: 0x102e69c */

    pActwk->colino = 0; /* Line 2607, Address: 0x102e6a4 */
    pActwk->colicnt = 0; /* Line 2608, Address: 0x102e6ac */

    ((int*)pActwk)[16] = 0; /* Line 2610, Address: 0x102e6b4 */
    ((int*)pActwk)[4] = -98304; /* Line 2611, Address: 0x102e6bc */
  } /* Line 2612, Address: 0x102e6cc */
  else
  {

    ((int*)pActwk)[16] -= 1280; /* Line 2616, Address: 0x102e6d4 */
    ((int*)pActwk)[4] += 6144; /* Line 2617, Address: 0x102e6e4 */
  }
  pActwk->xposi.l += ((int*)pActwk)[16]; /* Line 2619, Address: 0x102e6f4 */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 2620, Address: 0x102e70c */

  if (pActwk->yposi.w.h >= 576) /* Line 2622, Address: 0x102e724 */
  {
    ret = 0; /* Line 2624, Address: 0x102e740 */
    frameout(pActwk); /* Line 2625, Address: 0x102e744 */
  } /* Line 2626, Address: 0x102e750 */
  else
    tenmetu(); /* Line 2628, Address: 0x102e758 */
  return ret; /* Line 2629, Address: 0x102e760 */
} /* Line 2630, Address: 0x102e764 */









void egg1leg1(sprite_status* pActwk) { /* Line 2640, Address: 0x102e780 */
  int(*tbl[13])(sprite_status*) = /* Line 2641, Address: 0x102e78c */
  {
    &egg1leg1_ini,
    &egg1leg1_01,
    &egg1leg1_02,
    &egg1leg1_03,
    &egg1leg1_04,
    &egg1leg1_05,
    &egg1leg1_06,
    &egg1leg1_07,
    &egg1leg1_08,
    &egg1leg1_09,
    &egg1leg1_10,
    &egg1leg1_11,
    &egg1leg1_12
  };

  if (tbl[pActwk->r_no0 / 2](pActwk) == 0) return; /* Line 2658, Address: 0x102e7b8 */
  actionsub(pActwk); /* Line 2659, Address: 0x102e7fc */
} /* Line 2660, Address: 0x102e808 */



int egg1leg1_ini(sprite_status* pActwk) { /* Line 2664, Address: 0x102e820 */
  pActwk->cddat = 0; /* Line 2665, Address: 0x102e828 */
  pActwk->actflg = 4; /* Line 2666, Address: 0x102e830 */
  pActwk->sprhsize = 8; /* Line 2667, Address: 0x102e83c */
  pActwk->sprvsize = 8; /* Line 2668, Address: 0x102e848 */
  pActwk->sproffset = 9049; /* Line 2669, Address: 0x102e854 */
  pActwk->patbase = egg1leg1_pat; /* Line 2670, Address: 0x102e860 */


  pActwk->r_no0 = 12; /* Line 2673, Address: 0x102e870 */
  pActwk->actfree[0] = 88; /* Line 2674, Address: 0x102e87c */
  pActwk->actfree[21] = 2; /* Line 2675, Address: 0x102e888 */
  return 1; /* Line 2676, Address: 0x102e894 */
} /* Line 2677, Address: 0x102e898 */




int egg1leg1_01(sprite_status* pActwk) { /* Line 2682, Address: 0x102e8b0 */
  short subact;

  subact = ((short*)pActwk)[26]; /* Line 2685, Address: 0x102e8c0 */
  subact = ((short*)&actwk[subact])[26]; /* Line 2686, Address: 0x102e8d0 */
  if (actwk[subact].r_no0 != 6) /* Line 2687, Address: 0x102e8fc */
  {
    if (actwk[subact].r_no0 != 8) /* Line 2689, Address: 0x102e930 */
    {
      actwk[subact].actfree[2] &= 254; /* Line 2691, Address: 0x102e964 */
      actwk[subact].r_no0 = 6; /* Line 2692, Address: 0x102e990 */
    }
  }
  if (((char*)pActwk)[46] > 0) /* Line 2695, Address: 0x102e9b8 */
  {
    pActwk->actfree[0] = pActwk->actfree[0] - ((char*)pActwk)[67]; /* Line 2697, Address: 0x102e9d0 */

    if (((char*)pActwk)[46] > 0) /* Line 2699, Address: 0x102e9fc */
    {

      egg1leg1_set(pActwk); /* Line 2702, Address: 0x102ea14 */
      return 1; /* Line 2703, Address: 0x102ea20 */
    }
  }
  pActwk->actfree[0] = 0; /* Line 2706, Address: 0x102ea2c */
  if (actwk[subact].r_no0 != 8) /* Line 2707, Address: 0x102ea34 */
  {
    if (!(actwk[subact].actfree[2] & 1)) /* Line 2709, Address: 0x102ea68 */
    {

      actwk[subact].actfree[2] &= 254; /* Line 2712, Address: 0x102ea9c */
      egg1leg1_set(pActwk); /* Line 2713, Address: 0x102eac8 */
      return 1; /* Line 2714, Address: 0x102ead4 */
    }
    actwk[subact].actfree[2] &= 254; /* Line 2716, Address: 0x102eae0 */
  }

  pActwk->r_no0 = 4; /* Line 2719, Address: 0x102eb0c */
  egg1leg1_set(pActwk); /* Line 2720, Address: 0x102eb18 */
  return 1; /* Line 2721, Address: 0x102eb24 */
} /* Line 2722, Address: 0x102eb28 */




int egg1leg1_02(sprite_status* pActwk) { /* Line 2727, Address: 0x102eb40 */
  short subact;

  subact = ((short*)pActwk)[26]; /* Line 2730, Address: 0x102eb50 */
  subact = ((short*)&actwk[subact])[26]; /* Line 2731, Address: 0x102eb60 */
  pActwk->actfree[0] = pActwk->actfree[0] + ((char*)pActwk)[67]; /* Line 2732, Address: 0x102eb8c */
  if (((char*)pActwk)[46] >= 88) /* Line 2733, Address: 0x102ebb8 */
  {

    pActwk->actfree[0] = 88; /* Line 2736, Address: 0x102ebd4 */
    pActwk->r_no0 = 6; /* Line 2737, Address: 0x102ebe0 */
    actwk[subact].r_no0 = 2; /* Line 2738, Address: 0x102ebec */
  }
  egg1leg1_set(pActwk); /* Line 2740, Address: 0x102ec14 */
  return 1; /* Line 2741, Address: 0x102ec20 */
} /* Line 2742, Address: 0x102ec24 */




int egg1leg1_03(sprite_status* pActwk) { /* Line 2747, Address: 0x102ec40 */
  short subact;

  subact = ((short*)pActwk)[26]; /* Line 2750, Address: 0x102ec50 */
  subact = ((short*)&actwk[subact])[26]; /* Line 2751, Address: 0x102ec60 */
  if (actwk[subact].actfree[2] & 16) /* Line 2752, Address: 0x102ec8c */
    pActwk->actfree[2] |= 1; /* Line 2753, Address: 0x102ecc0 */
  egg1leg1_set(pActwk); /* Line 2754, Address: 0x102ecd0 */
  return 1; /* Line 2755, Address: 0x102ecdc */
} /* Line 2756, Address: 0x102ece0 */




int egg1leg1_04(sprite_status* pActwk) { /* Line 2761, Address: 0x102ed00 */
  if (!(pActwk->actfree[2] & 1)) /* Line 2762, Address: 0x102ed0c */
  {
    pActwk->actfree[0] = pActwk->actfree[0] - ((char*)pActwk)[67]; /* Line 2764, Address: 0x102ed24 */
    if (((char*)pActwk)[46] < 24) /* Line 2765, Address: 0x102ed50 */
    {

      pActwk->actfree[0] = 24; /* Line 2768, Address: 0x102ed6c */
      pActwk->actfree[2] |= 1; /* Line 2769, Address: 0x102ed78 */
    }
  }

  egg1leg1_set(pActwk); /* Line 2773, Address: 0x102ed88 */
  return 1; /* Line 2774, Address: 0x102ed94 */
} /* Line 2775, Address: 0x102ed98 */




int egg1leg1_05(sprite_status* pActwk) { /* Line 2780, Address: 0x102edb0 */
  short subact;

  subact = ((short*)pActwk)[26]; /* Line 2783, Address: 0x102edc0 */
  subact = ((short*)&actwk[subact])[26]; /* Line 2784, Address: 0x102edd0 */
  if (actwk[subact].r_no0 != 8) /* Line 2785, Address: 0x102edfc */
    actwk[subact].r_no0 = 6; /* Line 2786, Address: 0x102ee30 */
  else
  {

    if (((char*)pActwk)[46] == 0) /* Line 2790, Address: 0x102ee60 */
    {

      if (actwk[subact].actfree[2] & 1) /* Line 2793, Address: 0x102ee78 */
      {
        actwk[subact].actfree[2] &= 254; /* Line 2795, Address: 0x102eeac */
        pActwk->actfree[2] |= 1; /* Line 2796, Address: 0x102eed8 */
      } /* Line 2797, Address: 0x102eee8 */
      else
        actwk[subact].actfree[2] &= 254; /* Line 2799, Address: 0x102eef0 */
      egg1leg1_set(pActwk); /* Line 2800, Address: 0x102ef1c */
    }
  }
  if (((char*)pActwk)[46] != 0) /* Line 2803, Address: 0x102ef28 */
    pActwk->actfree[0] = pActwk->actfree[0] - ((char*)pActwk)[67]; /* Line 2804, Address: 0x102ef40 */
  egg1leg1_set(pActwk); /* Line 2805, Address: 0x102ef6c */
  return 1; /* Line 2806, Address: 0x102ef78 */
} /* Line 2807, Address: 0x102ef7c */




int egg1leg1_06(sprite_status* pActwk) { /* Line 2812, Address: 0x102ef90 */
  short subact;

  subact = ((short*)pActwk)[26]; /* Line 2815, Address: 0x102efa0 */
  subact = ((short*)&actwk[subact])[26]; /* Line 2816, Address: 0x102efb0 */
  if (actwk[subact].r_no0 != 4) /* Line 2817, Address: 0x102efdc */
    actwk[subact].r_no0 = 2; /* Line 2818, Address: 0x102f010 */
  else
  {

    if (((char*)pActwk)[46] >= 88) /* Line 2822, Address: 0x102f040 */
    {

      if (actwk[subact].actfree[2] & 1) /* Line 2825, Address: 0x102f05c */
        pActwk->actfree[2] |= 1; /* Line 2826, Address: 0x102f090 */
      actwk[subact].actfree[2] &= 254; /* Line 2827, Address: 0x102f0a0 */
      egg1leg1_set(pActwk); /* Line 2828, Address: 0x102f0cc */
      return 1; /* Line 2829, Address: 0x102f0d8 */
    }
  }

  if (((char*)pActwk)[46] < 88) /* Line 2833, Address: 0x102f0e4 */
    pActwk->actfree[0] = pActwk->actfree[0] + ((char*)pActwk)[67]; /* Line 2834, Address: 0x102f100 */
  egg1leg1_set(pActwk); /* Line 2835, Address: 0x102f12c */
  return 1; /* Line 2836, Address: 0x102f138 */
} /* Line 2837, Address: 0x102f13c */




int egg1leg1_07(sprite_status* pActwk) { /* Line 2842, Address: 0x102f150 */
  int ret = 1; /* Line 2843, Address: 0x102f164 */
  short subact;

  if (((char*)pActwk)[46] < 24) /* Line 2846, Address: 0x102f168 */
  {

    pActwk->actfree[0] = pActwk->actfree[0] + ((char*)pActwk)[67]; /* Line 2849, Address: 0x102f184 */
    subact = ((short*)pActwk)[26]; /* Line 2850, Address: 0x102f1b0 */
    subact = ((short*)&actwk[subact])[26]; /* Line 2851, Address: 0x102f1c0 */
    actwk[subact].actfree[2] |= 128; /* Line 2852, Address: 0x102f1ec */
    subact = ((short*)pActwk)[25]; /* Line 2853, Address: 0x102f218 */
    subact = ((short*)&actwk[subact])[27]; /* Line 2854, Address: 0x102f228 */
    subact = ((short*)&actwk[subact])[26]; /* Line 2855, Address: 0x102f254 */
    subact = ((short*)&actwk[subact])[26]; /* Line 2856, Address: 0x102f280 */
    actwk[subact].actfree[2] |= 128; /* Line 2857, Address: 0x102f2ac */
    ret = egg1leg1_06(pActwk); /* Line 2858, Address: 0x102f2d8 */
    return ret; /* Line 2859, Address: 0x102f2e8 */
  }
  if (((char*)pActwk)[46] > 24) /* Line 2861, Address: 0x102f2f4 */
  {

    pActwk->actfree[0] = pActwk->actfree[0] - ((char*)pActwk)[67]; /* Line 2864, Address: 0x102f310 */
    ret = egg1leg1_05(pActwk); /* Line 2865, Address: 0x102f33c */
    return ret; /* Line 2866, Address: 0x102f34c */
  }

  subact = ((short*)pActwk)[26]; /* Line 2869, Address: 0x102f358 */
  subact = ((short*)&actwk[subact])[26]; /* Line 2870, Address: 0x102f368 */
  if (actwk[subact].actfree[2] & 1) /* Line 2871, Address: 0x102f394 */
    pActwk->actfree[2] |= 1; /* Line 2872, Address: 0x102f3c8 */
  egg1leg1_set(pActwk); /* Line 2873, Address: 0x102f3d8 */
  return ret; /* Line 2874, Address: 0x102f3e4 */
} /* Line 2875, Address: 0x102f3e8 */




int egg1leg1_08(sprite_status* pActwk) { /* Line 2880, Address: 0x102f400 */
  short subact;

  subact = ((short*)pActwk)[25]; /* Line 2883, Address: 0x102f40c */
  subact = ((short*)&actwk[subact])[26]; /* Line 2884, Address: 0x102f41c */
  pActwk->xposi.w.h = actwk[subact].xposi.w.h - 10; /* Line 2885, Address: 0x102f448 */
  pActwk->yposi.w.h = actwk[subact].yposi.w.h; /* Line 2886, Address: 0x102f488 */
  pActwk->actfree[0] = actwk[subact].actfree[0]; /* Line 2887, Address: 0x102f4b4 */
  pActwk->actfree[1] = actwk[subact].actfree[1]; /* Line 2888, Address: 0x102f4e0 */
  return 1; /* Line 2889, Address: 0x102f50c */
} /* Line 2890, Address: 0x102f510 */




int egg1leg1_09(sprite_status* pActwk) { /* Line 2895, Address: 0x102f520 */
  short subact;

  subact = ((short*)pActwk)[26]; /* Line 2898, Address: 0x102f530 */
  subact = ((short*)&actwk[subact])[26]; /* Line 2899, Address: 0x102f540 */
  if (actwk[subact].r_no0 != 6) /* Line 2900, Address: 0x102f56c */
  {
    if (actwk[subact].r_no0 != 8) /* Line 2902, Address: 0x102f5a0 */
    {
      actwk[subact].actfree[2] &= 254; /* Line 2904, Address: 0x102f5d4 */
      actwk[subact].r_no0 = 6; /* Line 2905, Address: 0x102f600 */
    } /* Line 2906, Address: 0x102f628 */
    else
    {

      if (((char*)pActwk)[46] != 32) /* Line 2910, Address: 0x102f630 */
      {
        pActwk->actfree[0] = pActwk->actfree[0] - ((char*)pActwk)[67]; /* Line 2912, Address: 0x102f64c */
        if (pActwk->actfree[0] <= 0) /* Line 2913, Address: 0x102f678 */
        {
          pActwk->actfree[0] = 32; /* Line 2915, Address: 0x102f68c */
          actwk[subact].actfree[2] &= 254; /* Line 2916, Address: 0x102f698 */
          pActwk->r_no0 = 20; /* Line 2917, Address: 0x102f6c4 */
        }
      } /* Line 2919, Address: 0x102f6d0 */
      else
      {

        pActwk->actfree[0] = 32; /* Line 2923, Address: 0x102f6d8 */
        actwk[subact].actfree[2] &= 254; /* Line 2924, Address: 0x102f6e4 */
        pActwk->r_no0 = 20; /* Line 2925, Address: 0x102f710 */
      }
    }
  }
  egg1leg1_set(pActwk); /* Line 2929, Address: 0x102f71c */
  return 1; /* Line 2930, Address: 0x102f728 */
} /* Line 2931, Address: 0x102f72c */




int egg1leg1_10(sprite_status* pActwk) { /* Line 2936, Address: 0x102f740 */
  short subact;

  subact = ((short*)pActwk)[26]; /* Line 2939, Address: 0x102f750 */
  subact = ((short*)&actwk[subact])[26]; /* Line 2940, Address: 0x102f760 */
  pActwk->actfree[0] = pActwk->actfree[0] + ((char*)pActwk)[67]; /* Line 2941, Address: 0x102f78c */
  if (((char*)pActwk)[46] >= 48) /* Line 2942, Address: 0x102f7b8 */
  {

    pActwk->actfree[0] = 48; /* Line 2945, Address: 0x102f7d4 */
    pActwk->r_no0 = 6; /* Line 2946, Address: 0x102f7e0 */
    actwk[subact].r_no0 = 2; /* Line 2947, Address: 0x102f7ec */
  }
  egg1leg1_set(pActwk); /* Line 2949, Address: 0x102f814 */
  return 1; /* Line 2950, Address: 0x102f820 */
} /* Line 2951, Address: 0x102f824 */




int egg1leg1_11(sprite_status* pActwk) { /* Line 2956, Address: 0x102f840 */
  short subact;

  if (!(pActwk->actfree[2] & 1)) /* Line 2959, Address: 0x102f850 */
  {
    subact = pActwk->actfree[6]; /* Line 2961, Address: 0x102f868 */
    subact = actwk[subact].actfree[6]; /* Line 2962, Address: 0x102f87c */
    if (actwk[subact].r_no0 != 2) /* Line 2963, Address: 0x102f8ac */
    {
      if (actwk[subact].r_no0 == 4) /* Line 2965, Address: 0x102f8e0 */
      {

        pActwk->actfree[0] = pActwk->actfree[0] + ((char*)pActwk)[67]; /* Line 2968, Address: 0x102f914 */
        if (((char*)pActwk)[46] >= 80) /* Line 2969, Address: 0x102f940 */
        {
          pActwk->actfree[2] |= 1; /* Line 2971, Address: 0x102f95c */
        }
        egg1leg1_set(pActwk); /* Line 2973, Address: 0x102f96c */
        return 1; /* Line 2974, Address: 0x102f978 */
      }

      actwk[subact].r_no0 = 2; /* Line 2977, Address: 0x102f984 */
    }
  }
  egg1leg1_set(pActwk); /* Line 2980, Address: 0x102f9ac */
  return 1; /* Line 2981, Address: 0x102f9b8 */
} /* Line 2982, Address: 0x102f9bc */








void egg1leg1_set(sprite_status* pActwk) { /* Line 2991, Address: 0x102f9d0 */
  unsigned short sin, cos;
  short sin2, cos2;
  int_union sinl, cosl;
  short subact;

  sinset(pActwk->actfree[0], (short*)&sin, (short*)&cos); /* Line 2997, Address: 0x102f9e8 */
  sinl.l = sin; /* Line 2998, Address: 0x102fa00 */
  cosl.l = cos; /* Line 2999, Address: 0x102fa0c */
  sinl.w.l /= 16; /* Line 3000, Address: 0x102fa18 */
  cosl.w.l /= 16; /* Line 3001, Address: 0x102fa38 */

  if (pActwk->actfree[2] & 16) /* Line 3003, Address: 0x102fa58 */
  {
    if (!(pActwk->actfree[2] & 32)) /* Line 3005, Address: 0x102fa70 */
    {

      subact = ((short*)pActwk)[25]; /* Line 3008, Address: 0x102fa88 */
      cos2 = cosl.w.l + (actwk[subact].xposi.w.h + 12); /* Line 3009, Address: 0x102fa98 */
      if (pActwk->actfree[2] & 4) /* Line 3010, Address: 0x102fae8 */
        cos2 -= 10; /* Line 3011, Address: 0x102fb00 */
      pActwk->xposi.w.h = cos2; /* Line 3012, Address: 0x102fb0c */
      pActwk->yposi.w.h = sinl.w.l + (actwk[subact].yposi.w.h + 20); /* Line 3013, Address: 0x102fb14 */
    } /* Line 3014, Address: 0x102fb64 */
    else
    {
      if (!(pActwk->actfree[2] & 2)) /* Line 3017, Address: 0x102fb6c */
      {
        pActwk->actfree[2] |= 2; /* Line 3019, Address: 0x102fb84 */
        ((short*)pActwk)[29] = cosl.w.l; /* Line 3020, Address: 0x102fb94 */
        ((short*)pActwk)[31] = sinl.w.l; /* Line 3021, Address: 0x102fba0 */
      }

      cos2 = cosl.w.l - ((short*)pActwk)[29]; /* Line 3024, Address: 0x102fbac */
      sin2 = sinl.w.l - ((short*)pActwk)[31]; /* Line 3025, Address: 0x102fbdc */

      ((short*)pActwk)[29] = cosl.w.l; /* Line 3027, Address: 0x102fc0c */
      ((short*)pActwk)[31] = sinl.w.l; /* Line 3028, Address: 0x102fc18 */

      subact = ((short*)pActwk)[25]; /* Line 3030, Address: 0x102fc24 */
      actwk[subact].xposi.w.h -= cos2; /* Line 3031, Address: 0x102fc34 */
      actwk[subact].yposi.w.h -= sin2; /* Line 3032, Address: 0x102fc60 */
      subact = ((short*)&actwk[subact])[25]; /* Line 3033, Address: 0x102fc8c */
      actwk[subact].xposi.w.h -= cos2; /* Line 3034, Address: 0x102fcb8 */
      actwk[subact].yposi.w.h -= sin2; /* Line 3035, Address: 0x102fce4 */
    }
  } /* Line 3037, Address: 0x102fd10 */
  else
  {
    pActwk->actfree[2] &= 253; /* Line 3040, Address: 0x102fd18 */

    subact = ((short*)pActwk)[25]; /* Line 3042, Address: 0x102fd28 */
    cos2 = cosl.w.l + (actwk[subact].xposi.w.h + 12); /* Line 3043, Address: 0x102fd38 */
    if (pActwk->actfree[2] & 4) /* Line 3044, Address: 0x102fd88 */
      cos2 -= 10; /* Line 3045, Address: 0x102fda0 */
    pActwk->xposi.w.h = cos2; /* Line 3046, Address: 0x102fdac */
    pActwk->yposi.w.h = sinl.w.l + (actwk[subact].yposi.w.h + 20); /* Line 3047, Address: 0x102fdb4 */
  }
} /* Line 3049, Address: 0x102fe04 */




int egg1leg1_12(sprite_status* pActwk) { /* Line 3054, Address: 0x102fe20 */
  int ret = 1; /* Line 3055, Address: 0x102fe30 */

  if (!(pActwk->actfree[2] & 2)) /* Line 3057, Address: 0x102fe34 */
  {
    pActwk->actfree[2] |= 2; /* Line 3059, Address: 0x102fe4c */
    if (pActwk->actfree[2] & 16) /* Line 3060, Address: 0x102fe5c */
    {
      ((int*)pActwk)[16] = 0; /* Line 3062, Address: 0x102fe74 */
      ((int*)pActwk)[4] = -163840; /* Line 3063, Address: 0x102fe7c */
    } /* Line 3064, Address: 0x102fe8c */
    else
    {
      ((int*)pActwk)[16] = 0; /* Line 3067, Address: 0x102fe94 */
      ((int*)pActwk)[4] = -163840; /* Line 3068, Address: 0x102fe9c */
    }
  } /* Line 3070, Address: 0x102feac */
  else
  {

    if (pActwk->actfree[2] & 16) /* Line 3074, Address: 0x102feb4 */
    {
      ((int*)pActwk)[16] = (long int)((int*)pActwk)[16] - 1536; /* Line 3076, Address: 0x102fecc */
      ((int*)pActwk)[4] = (long int)((int*)pActwk)[4] + 6240; /* Line 3077, Address: 0x102fef0 */
    } /* Line 3078, Address: 0x102ff14 */
    else
    {
      ((int*)pActwk)[16] = (long int)((int*)pActwk)[16] + 1536; /* Line 3081, Address: 0x102ff1c */
      ((int*)pActwk)[4] = (long int)((int*)pActwk)[4] + 6240; /* Line 3082, Address: 0x102ff40 */
    }
  }

  pActwk->xposi.l += ((int*)pActwk)[16]; /* Line 3086, Address: 0x102ff64 */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 3087, Address: 0x102ff7c */

  if (pActwk->yposi.w.h >= 576) /* Line 3089, Address: 0x102ff94 */
  {
    ret = 0; /* Line 3091, Address: 0x102ffb0 */
    frameout(pActwk); /* Line 3092, Address: 0x102ffb4 */
  } /* Line 3093, Address: 0x102ffc0 */
  else
    tenmetu(); /* Line 3095, Address: 0x102ffc8 */
  return ret; /* Line 3096, Address: 0x102ffd0 */
} /* Line 3097, Address: 0x102ffd4 */





void egg1leg2(sprite_status* pActwk) { /* Line 3103, Address: 0x102fff0 */
  int(*tbl[8])(sprite_status*) = /* Line 3104, Address: 0x102fffc */
  {
    &egg1leg2_ini,
    &egg1leg2_01,
    &egg1leg2_02,
    &egg1leg2_03,
    &egg1leg2_04,
    &egg1leg2_05,
    &egg1leg2_06,
    &egg1leg2_07
  };

  if (tbl[pActwk->r_no0 / 2](pActwk) == 0) return; /* Line 3116, Address: 0x1030030 */
  actionsub(pActwk); /* Line 3117, Address: 0x1030074 */
} /* Line 3118, Address: 0x1030080 */



int egg1leg2_ini(sprite_status* pActwk) { /* Line 3122, Address: 0x1030090 */
  pActwk->cddat = 0; /* Line 3123, Address: 0x1030098 */
  pActwk->r_no0 = 2; /* Line 3124, Address: 0x10300a0 */
  pActwk->actflg = 4; /* Line 3125, Address: 0x10300ac */
  pActwk->sprvsize = 8; /* Line 3126, Address: 0x10300b8 */
  pActwk->sprhsize = 20; /* Line 3127, Address: 0x10300c4 */
  pActwk->sproffset = 9049; /* Line 3128, Address: 0x10300d0 */
  pActwk->patbase = egg1leg2_pat; /* Line 3129, Address: 0x10300dc */
  ((int*)pActwk)[16] = 32768; /* Line 3130, Address: 0x10300ec */
  ((int*)pActwk)[4] = 16384; /* Line 3131, Address: 0x10300f8 */
  return 1; /* Line 3132, Address: 0x1030104 */
} /* Line 3133, Address: 0x1030108 */




int egg1leg2_01(sprite_status* pActwk) { /* Line 3138, Address: 0x1030120 */
  short subact;

  subact = ((short*)pActwk)[25]; /* Line 3141, Address: 0x103012c */
  pActwk->xposi.w.h = actwk[subact].xposi.w.h + 4; /* Line 3142, Address: 0x103013c */
  pActwk->yposi.w.h = actwk[subact].yposi.w.h + 16; /* Line 3143, Address: 0x103017c */
  return 1; /* Line 3144, Address: 0x10301bc */
} /* Line 3145, Address: 0x10301c0 */




int egg1leg2_02(sprite_status* pActwk) { /* Line 3150, Address: 0x10301d0 */
  short subact;

  subact = ((short*)pActwk)[25]; /* Line 3153, Address: 0x10301dc */
  subact = ((short*)&actwk[subact])[25]; /* Line 3154, Address: 0x10301ec */
  subact = ((short*)&actwk[subact])[26]; /* Line 3155, Address: 0x1030218 */
  subact = ((short*)&actwk[subact])[26]; /* Line 3156, Address: 0x1030244 */
  pActwk->xposi.w.h = actwk[subact].xposi.w.h - 10; /* Line 3157, Address: 0x1030270 */
  pActwk->yposi.w.h = actwk[subact].yposi.w.h; /* Line 3158, Address: 0x10302b0 */
  return 1; /* Line 3159, Address: 0x10302dc */
} /* Line 3160, Address: 0x10302e0 */




int egg1leg2_03(sprite_status* pActwk) { /* Line 3165, Address: 0x10302f0 */
  int xs;

  if (((short*)pActwk)[29] < 8) /* Line 3168, Address: 0x1030300 */
  {
    ((int*)pActwk)[14] = ((int*)pActwk)[14] + ((int*)pActwk)[16]; /* Line 3170, Address: 0x103031c */
    if (pActwk->actfree[2] & 16) /* Line 3171, Address: 0x1030338 */
    {
      xs = ((int*)pActwk)[16]; /* Line 3173, Address: 0x1030350 */
      xs = -xs; /* Line 3174, Address: 0x1030358 */
      leg2_set(xs, 0, pActwk); /* Line 3175, Address: 0x103035c */
      return 1; /* Line 3176, Address: 0x1030370 */
    }
  }
  leg2_set2(pActwk); /* Line 3179, Address: 0x103037c */
  return 1; /* Line 3180, Address: 0x1030388 */
} /* Line 3181, Address: 0x103038c */




int egg1leg2_04(sprite_status* pActwk) { /* Line 3186, Address: 0x10303a0 */
  ((short*)pActwk)[31] = 0; /* Line 3187, Address: 0x10303ac */
  if (((short*)pActwk)[29] > -8) /* Line 3188, Address: 0x10303b4 */
  {
    ((int*)pActwk)[14] = ((int*)pActwk)[14] - ((int*)pActwk)[16]; /* Line 3190, Address: 0x10303d0 */
    if (pActwk->actfree[2] & 16) /* Line 3191, Address: 0x10303ec */
    {
      leg2_set(((int*)pActwk)[16], 0, pActwk); /* Line 3193, Address: 0x1030404 */
      return 1; /* Line 3194, Address: 0x103041c */
    }
  }
  leg2_set2(pActwk); /* Line 3197, Address: 0x1030428 */
  return 1; /* Line 3198, Address: 0x1030434 */
} /* Line 3199, Address: 0x1030438 */




int egg1leg2_05(sprite_status* pActwk) { /* Line 3204, Address: 0x1030450 */
  int xs, ys;

  if (((short*)pActwk)[29] > -8) /* Line 3207, Address: 0x1030464 */
  {
    ((int*)pActwk)[14] = ((int*)pActwk)[14] - ((int*)pActwk)[16]; /* Line 3209, Address: 0x1030480 */
    xs = ((int*)pActwk)[16]; /* Line 3210, Address: 0x103049c */
  } /* Line 3211, Address: 0x10304a4 */
  else
    xs = 0; /* Line 3213, Address: 0x10304ac */
  if (((short*)pActwk)[31] > -4) /* Line 3214, Address: 0x10304b0 */
  {
    ((int*)pActwk)[15] = ((int*)pActwk)[15] - ((int*)pActwk)[4]; /* Line 3216, Address: 0x10304cc */
    ys = ((int*)pActwk)[4]; /* Line 3217, Address: 0x10304e8 */
  } /* Line 3218, Address: 0x10304f0 */
  else
    ys = 0; /* Line 3220, Address: 0x10304f8 */
  if (pActwk->actfree[2] & 16) /* Line 3221, Address: 0x10304fc */
    leg2_set(xs, ys, pActwk); /* Line 3222, Address: 0x1030514 */
  else
    leg2_set2(pActwk); /* Line 3224, Address: 0x1030530 */
  return 1; /* Line 3225, Address: 0x103053c */
} /* Line 3226, Address: 0x1030540 */




int egg1leg2_06(sprite_status* pActwk) { /* Line 3231, Address: 0x1030560 */
  int xs, ys;

  if (((short*)pActwk)[29] > -8) /* Line 3234, Address: 0x1030574 */
  {
    ((int*)pActwk)[14] = ((int*)pActwk)[14] - ((int*)pActwk)[16]; /* Line 3236, Address: 0x1030590 */
    xs = ((int*)pActwk)[16]; /* Line 3237, Address: 0x10305ac */
  } /* Line 3238, Address: 0x10305b4 */
  else
    xs = 0; /* Line 3240, Address: 0x10305bc */
  if (((short*)pActwk)[31] < 4) /* Line 3241, Address: 0x10305c0 */
  {
    ((int*)pActwk)[15] = ((int*)pActwk)[15] + ((int*)pActwk)[4]; /* Line 3243, Address: 0x10305dc */
    ys = ((int*)pActwk)[4]; /* Line 3244, Address: 0x10305f8 */
  } /* Line 3245, Address: 0x1030600 */
  else
    ys = 0; /* Line 3247, Address: 0x1030608 */
  if (pActwk->actfree[2] & 16) /* Line 3248, Address: 0x103060c */
  {
    ys = -ys; /* Line 3250, Address: 0x1030624 */
    leg2_set(xs, ys, pActwk); /* Line 3251, Address: 0x1030628 */
  } /* Line 3252, Address: 0x103063c */
  else
    leg2_set2(pActwk); /* Line 3254, Address: 0x1030644 */
  return 1; /* Line 3255, Address: 0x1030650 */
} /* Line 3256, Address: 0x1030654 */






void leg2_set(int xs, int ys, sprite_status* pActwk) { /* Line 3263, Address: 0x1030670 */
  short subact;

  if (pActwk->actfree[2] & 32) /* Line 3266, Address: 0x1030684 */
  {
    subact = ((short*)pActwk)[25]; /* Line 3268, Address: 0x103069c */
    actwk[subact].xposi.l += xs; /* Line 3269, Address: 0x10306ac */
    actwk[subact].yposi.l += ys; /* Line 3270, Address: 0x10306dc */
    subact = ((short*)&actwk[subact])[25]; /* Line 3271, Address: 0x103070c */
    actwk[subact].xposi.l += xs; /* Line 3272, Address: 0x1030738 */
    actwk[subact].yposi.l += ys; /* Line 3273, Address: 0x1030768 */
    subact = ((short*)&actwk[subact])[25]; /* Line 3274, Address: 0x1030798 */
    actwk[subact].xposi.l += xs; /* Line 3275, Address: 0x10307c4 */
    actwk[subact].yposi.l += ys; /* Line 3276, Address: 0x10307f4 */
  }
} /* Line 3278, Address: 0x1030824 */




void leg2_set2(sprite_status* pActwk) { /* Line 3283, Address: 0x1030840 */
  short subact;

  subact = ((short*)pActwk)[25]; /* Line 3286, Address: 0x103084c */
  pActwk->xposi.w.h = ((short*)pActwk)[29] + (actwk[subact].xposi.w.h + 4); /* Line 3287, Address: 0x103085c */
  pActwk->yposi.w.h = ((short*)pActwk)[31] + (actwk[subact].yposi.w.h + 16); /* Line 3288, Address: 0x10308b0 */
} /* Line 3289, Address: 0x1030904 */




int egg1leg2_07(sprite_status* pActwk) { /* Line 3294, Address: 0x1030920 */
  int ret = 1; /* Line 3295, Address: 0x1030930 */

  if (!(pActwk->actfree[2] & 2)) /* Line 3297, Address: 0x1030934 */
   {

    pActwk->actfree[2] |= 2; /* Line 3300, Address: 0x103094c */
    if (!(pActwk->actfree[2] & 16)) /* Line 3301, Address: 0x103095c */
    {
      ((int*)pActwk)[16] = 0; /* Line 3303, Address: 0x1030974 */
      ((int*)pActwk)[4] = -131072; /* Line 3304, Address: 0x103097c */
    } /* Line 3305, Address: 0x1030988 */
    else
    {
      ((int*)pActwk)[16] = 0; /* Line 3308, Address: 0x1030990 */
      ((int*)pActwk)[4] = -131072; /* Line 3309, Address: 0x1030998 */
    }
  } /* Line 3311, Address: 0x10309a4 */
  else
  {

    if (!(pActwk->actfree[2] & 16)) /* Line 3315, Address: 0x10309ac */
    {
      ((int*)pActwk)[16] -= 1536; /* Line 3317, Address: 0x10309c4 */
      ((int*)pActwk)[4] += 6752; /* Line 3318, Address: 0x10309d4 */
    } /* Line 3319, Address: 0x10309e4 */
    else
    {
      ((int*)pActwk)[16] += 1536; /* Line 3322, Address: 0x10309ec */
      ((int*)pActwk)[4] += 6752; /* Line 3323, Address: 0x10309fc */
    }
  }
  pActwk->xposi.l += ((int*)pActwk)[16]; /* Line 3326, Address: 0x1030a0c */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 3327, Address: 0x1030a24 */
  if (pActwk->yposi.w.h >= 576) /* Line 3328, Address: 0x1030a3c */
  {
    ret = 0; /* Line 3330, Address: 0x1030a58 */
    frameout(pActwk); /* Line 3331, Address: 0x1030a5c */
  } /* Line 3332, Address: 0x1030a68 */
  else
    tenmetu(); /* Line 3334, Address: 0x1030a70 */
  return ret; /* Line 3335, Address: 0x1030a78 */
} /* Line 3336, Address: 0x1030a7c */








void egg1leg3(sprite_status* pActwk) { /* Line 3345, Address: 0x1030a90 */
  int(*tbl[7])(sprite_status*) = /* Line 3346, Address: 0x1030a9c */
  {
    &egg1leg3_ini,
    &egg1leg3_01,
    &egg1leg3_02,
    &egg1leg3_03,
    &egg1leg3_04,
    &egg1leg3_05,
    &egg1leg3_06
  };

  if (tbl[pActwk->r_no0 / 2](pActwk) == 0) return; /* Line 3357, Address: 0x1030ac8 */
  actionsub(pActwk); /* Line 3358, Address: 0x1030b0c */
} /* Line 3359, Address: 0x1030b18 */



void leg3_set_not_grd(sprite_status* pActwk) { /* Line 3363, Address: 0x1030b30 */
  short subact;

  subact = ((short*)pActwk)[25]; /* Line 3366, Address: 0x1030b3c */
  pActwk->xposi.w.h = ((short*)pActwk)[29] + (actwk[subact].xposi.w.h - 11); /* Line 3367, Address: 0x1030b4c */
  pActwk->yposi.w.h = ((short*)pActwk)[31] + (actwk[subact].yposi.w.h + 14); /* Line 3368, Address: 0x1030ba0 */
} /* Line 3369, Address: 0x1030bf4 */



int egg1leg3_ini(sprite_status* pActwk) { /* Line 3373, Address: 0x1030c10 */
  pActwk->cddat = 0; /* Line 3374, Address: 0x1030c1c */
  pActwk->actflg = 4; /* Line 3375, Address: 0x1030c24 */
  pActwk->sprhsize = 32; /* Line 3376, Address: 0x1030c30 */
  pActwk->sprvsize = 20; /* Line 3377, Address: 0x1030c3c */
  pActwk->sproffset = 9049; /* Line 3378, Address: 0x1030c48 */
  pActwk->patbase = egg1leg3_pat; /* Line 3379, Address: 0x1030c54 */

  ((int*)pActwk)[16] = 16384; /* Line 3381, Address: 0x1030c64 */
  ((int*)pActwk)[4] = 32768; /* Line 3382, Address: 0x1030c70 */

  pActwk->r_no0 = 4; /* Line 3384, Address: 0x1030c7c */
  pActwk->actfree[2] |= 1; /* Line 3385, Address: 0x1030c88 */
  ((short*)pActwk)[29] = -8; /* Line 3386, Address: 0x1030c98 */
  ((short*)pActwk)[31] = 16; /* Line 3387, Address: 0x1030ca4 */
  leg3_set_not_grd(pActwk); /* Line 3388, Address: 0x1030cb0 */
  return 1; /* Line 3389, Address: 0x1030cbc */
} /* Line 3390, Address: 0x1030cc0 */



void leg3_on_the_ground(sprite_status* pActwk) { /* Line 3394, Address: 0x1030cd0 */
  short subact;

  pActwk->actfree[2] |= 16; /* Line 3397, Address: 0x1030cdc */
  subact = ((short*)pActwk)[25]; /* Line 3398, Address: 0x1030cec */
  actwk[subact].actfree[2] |= 16; /* Line 3399, Address: 0x1030cfc */
  subact = ((short*)&actwk[subact])[25]; /* Line 3400, Address: 0x1030d28 */
  actwk[subact].actfree[2] |= 16; /* Line 3401, Address: 0x1030d54 */

  subact = ((short*)&actwk[subact])[25]; /* Line 3403, Address: 0x1030d80 */
  subact = ((short*)&actwk[subact])[25]; /* Line 3404, Address: 0x1030dac */
  actwk[subact].actfree[11] = 8; /* Line 3405, Address: 0x1030dd8 */


} /* Line 3408, Address: 0x1030e00 */




int egg1leg3_01(sprite_status* pActwk) { /* Line 3413, Address: 0x1030e10 */
  ((int*)pActwk)[14] = ((int*)pActwk)[14] - ((int*)pActwk)[16]; /* Line 3414, Address: 0x1030e1c */
  ((int*)pActwk)[15] = ((int*)pActwk)[15] + ((int*)pActwk)[4]; /* Line 3415, Address: 0x1030e38 */



  if (pActwk->actfree[2] & 16) /* Line 3419, Address: 0x1030e54 */
  {
    if (pActwk->actfree[2] & 128) /* Line 3421, Address: 0x1030e6c */
    {

      if (((short*)pActwk)[31] < 12) /* Line 3424, Address: 0x1030e84 */
      {

        leg3_set(pActwk); /* Line 3427, Address: 0x1030ea0 */
        if (0 >= emycol_d(pActwk)) /* Line 3428, Address: 0x1030eac */
        {
          leg3_on_the_ground(pActwk); /* Line 3430, Address: 0x1030ecc */
        }

        return 1; /* Line 3433, Address: 0x1030ed8 */
      }
      else
      {

        pActwk->actfree[2] |= 1; /* Line 3438, Address: 0x1030ee4 */
        pActwk->r_no0 = 4; /* Line 3439, Address: 0x1030ef4 */
        return 1; /* Line 3440, Address: 0x1030f00 */
      }
    }
  }

  if (((short*)pActwk)[31] < 16) /* Line 3445, Address: 0x1030f0c */
  {

    leg3_set(pActwk); /* Line 3448, Address: 0x1030f28 */
    if (0 >= emycol_d(pActwk)) /* Line 3449, Address: 0x1030f34 */
    {
      leg3_on_the_ground(pActwk); /* Line 3451, Address: 0x1030f54 */
      sub_sync(126); /* Line 3452, Address: 0x1030f60 */
    }
  } /* Line 3454, Address: 0x1030f6c */
  else
  {

    pActwk->actfree[2] |= 1; /* Line 3458, Address: 0x1030f74 */
    pActwk->r_no0 = 4; /* Line 3459, Address: 0x1030f84 */
  }
  return 1; /* Line 3461, Address: 0x1030f90 */
} /* Line 3462, Address: 0x1030f94 */




int egg1leg3_03(sprite_status* pActwk) { /* Line 3467, Address: 0x1030fb0 */
  ((int*)pActwk)[14] = ((int*)pActwk)[14] + ((int*)pActwk)[16]; /* Line 3468, Address: 0x1030fbc */
  ((int*)pActwk)[15] = ((int*)pActwk)[15] - ((int*)pActwk)[4]; /* Line 3469, Address: 0x1030fd8 */
  if (((int*)pActwk)[15] <= 0) /* Line 3470, Address: 0x1030ff4 */
  {

    ((short*)pActwk)[29] = 0; /* Line 3473, Address: 0x1031004 */
    ((short*)pActwk)[28] = 0; /* Line 3474, Address: 0x103100c */
    ((short*)pActwk)[31] = 0; /* Line 3475, Address: 0x1031014 */
    ((short*)pActwk)[30] = 0; /* Line 3476, Address: 0x103101c */
    pActwk->actfree[2] |= 1; /* Line 3477, Address: 0x1031024 */
    pActwk->r_no0 = 8; /* Line 3478, Address: 0x1031034 */
  }
  leg3_set(pActwk); /* Line 3480, Address: 0x1031040 */
  return 1; /* Line 3481, Address: 0x103104c */
} /* Line 3482, Address: 0x1031050 */




int egg1leg3_02(sprite_status* pActwk) { /* Line 3487, Address: 0x1031060 */


  if (!(pActwk->actfree[2] & 16)) /* Line 3490, Address: 0x103106c */
  {
    leg3_set_not_grd(pActwk); /* Line 3492, Address: 0x1031084 */
    if (0 >= emycol_d(pActwk)) /* Line 3493, Address: 0x1031090 */
    {













      leg3_on_the_ground(pActwk); /* Line 3508, Address: 0x10310b0 */
      sub_sync(126); /* Line 3509, Address: 0x10310bc */
    }
  }
  return 1; /* Line 3512, Address: 0x10310c8 */
} /* Line 3513, Address: 0x10310cc */




int egg1leg3_04(sprite_status* pActwk) { /* Line 3518, Address: 0x10310e0 */
  leg3_set_not_grd(pActwk); /* Line 3519, Address: 0x10310ec */
  return 1; /* Line 3520, Address: 0x10310f8 */
} /* Line 3521, Address: 0x10310fc */




int egg1leg3_05(sprite_status* pActwk) { /* Line 3526, Address: 0x1031110 */
  short subact;

  subact = ((short*)pActwk)[25]; /* Line 3529, Address: 0x103111c */
  subact = ((short*)&actwk[subact])[25]; /* Line 3530, Address: 0x103112c */
  subact = ((short*)&actwk[subact])[25]; /* Line 3531, Address: 0x1031158 */
  subact = ((short*)&actwk[subact])[26]; /* Line 3532, Address: 0x1031184 */
  subact = ((short*)&actwk[subact])[26]; /* Line 3533, Address: 0x10311b0 */
  subact = ((short*)&actwk[subact])[26]; /* Line 3534, Address: 0x10311dc */
  pActwk->xposi.w.h = actwk[subact].xposi.w.h - 10; /* Line 3535, Address: 0x1031208 */
  pActwk->yposi.w.h = actwk[subact].yposi.w.h; /* Line 3536, Address: 0x1031248 */
  ((short*)pActwk)[29] = ((short*)&actwk[subact])[29]; /* Line 3537, Address: 0x1031274 */
  ((short*)pActwk)[31] = ((short*)&actwk[subact])[31]; /* Line 3538, Address: 0x10312a0 */
  return 1; /* Line 3539, Address: 0x10312cc */
} /* Line 3540, Address: 0x10312d0 */



void leg3_set(sprite_status* pActwk) { /* Line 3544, Address: 0x10312e0 */
  short subact;
  int xs, ys;

  if (!(pActwk->actfree[2] & 16)) /* Line 3548, Address: 0x10312f8 */
  {
    leg3_set_not_grd(pActwk); /* Line 3550, Address: 0x1031310 */
  } /* Line 3551, Address: 0x103131c */
  else
    if (pActwk->actfree[2] & 32) /* Line 3553, Address: 0x1031324 */
    {

      xs = ((int*)pActwk)[16]; /* Line 3556, Address: 0x103133c */
      ys = ((int*)pActwk)[4]; /* Line 3557, Address: 0x1031344 */

      if (pActwk->r_no0 != 6) /* Line 3559, Address: 0x103134c */
      {
        xs = -xs; /* Line 3561, Address: 0x1031364 */
        ys = -ys; /* Line 3562, Address: 0x1031368 */
      }



      subact = ((short*)pActwk)[25]; /* Line 3567, Address: 0x103136c */
      actwk[subact].xposi.l -= xs; /* Line 3568, Address: 0x103137c */
      actwk[subact].yposi.l += ys; /* Line 3569, Address: 0x10313a8 */
      subact = ((short*)&actwk[subact])[25]; /* Line 3570, Address: 0x10313d4 */
      actwk[subact].xposi.l -= xs; /* Line 3571, Address: 0x1031400 */
      actwk[subact].yposi.l += ys; /* Line 3572, Address: 0x103142c */
      subact = ((short*)&actwk[subact])[25]; /* Line 3573, Address: 0x1031458 */
      actwk[subact].xposi.l -= xs; /* Line 3574, Address: 0x1031484 */
      actwk[subact].yposi.l += ys; /* Line 3575, Address: 0x10314b0 */
      subact = ((short*)&actwk[subact])[25]; /* Line 3576, Address: 0x10314dc */
      actwk[subact].xposi.l -= xs; /* Line 3577, Address: 0x1031508 */
      actwk[subact].yposi.l += ys; /* Line 3578, Address: 0x1031534 */
    }
} /* Line 3580, Address: 0x1031560 */




int egg1leg3_06(sprite_status* pActwk) { /* Line 3585, Address: 0x1031580 */
  int ret = 1; /* Line 3586, Address: 0x1031590 */

  if (!(pActwk->actfree[2] & 2)) /* Line 3588, Address: 0x1031594 */
  {
    pActwk->actfree[2] |= 2; /* Line 3590, Address: 0x10315ac */

    if (pActwk->actfree[2] & 16) /* Line 3592, Address: 0x10315bc */
    {
      ((int*)pActwk)[16] = 0; /* Line 3594, Address: 0x10315d4 */
      ((int*)pActwk)[4] = -143360; /* Line 3595, Address: 0x10315dc */
    } /* Line 3596, Address: 0x10315ec */
    else
    {
      ((int*)pActwk)[16] = 0; /* Line 3599, Address: 0x10315f4 */
      ((int*)pActwk)[4] = -143360; /* Line 3600, Address: 0x10315fc */
    }
  } /* Line 3602, Address: 0x103160c */
  else
  {

    if (!(pActwk->actfree[2] & 16)) /* Line 3606, Address: 0x1031614 */
    {
      ((int*)pActwk)[16] = (long int)((int*)pActwk)[16] - 1632; /* Line 3608, Address: 0x103162c */
      ((int*)pActwk)[4] = (long int)((int*)pActwk)[4] + 5728; /* Line 3609, Address: 0x1031650 */
    } /* Line 3610, Address: 0x1031674 */
    else
    {
      ((int*)pActwk)[16] = (long int)((int*)pActwk)[16] + 1632; /* Line 3613, Address: 0x103167c */
      ((int*)pActwk)[4] = (long int)((int*)pActwk)[4] + 5728; /* Line 3614, Address: 0x10316a0 */
    }
  }

  pActwk->xposi.l += ((int*)pActwk)[16]; /* Line 3618, Address: 0x10316c4 */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 3619, Address: 0x10316dc */
  if (pActwk->yposi.w.h >= 576) /* Line 3620, Address: 0x10316f4 */
  {
    ret = 0; /* Line 3622, Address: 0x1031710 */
    frameout(pActwk); /* Line 3623, Address: 0x1031714 */
  } /* Line 3624, Address: 0x1031720 */
  else
    tenmetu(); /* Line 3626, Address: 0x1031728 */
  return ret; /* Line 3627, Address: 0x1031730 */
} /* Line 3628, Address: 0x1031734 */





void bom_set(sprite_status* pActwk) { /* Line 3634, Address: 0x1031750 */
  short temp;
  sprite_status* subActwk;




  short bom_tbl[20] = /* Line 3641, Address: 0x1031760 */
  {
    -48, -16,
     48,  16,
    -16, -16,
     16,  16,
    -32,   0,
     48, -16,
    -48,  16,
    -16,  16,
     16, -16,
     32,   0
  };




  if (pActwk->actfree[1] % 4 == 0) /* Line 3658, Address: 0x1031794 */
  {
    temp = (short)(pActwk->actfree[1] / 4) % 10 * 2; /* Line 3660, Address: 0x10317c4 */
    if (actwkchk(&subActwk) == 0) /* Line 3661, Address: 0x1031818 */
    {
      subActwk->r_no1 = 255; /* Line 3663, Address: 0x103182c */

      subActwk->actno = 24; /* Line 3665, Address: 0x1031838 */
      subActwk->xposi.w.h = pActwk->xposi.w.h + bom_tbl[temp]; /* Line 3666, Address: 0x1031844 */
      subActwk->yposi.w.h = pActwk->yposi.w.h + bom_tbl[temp + 1]; /* Line 3667, Address: 0x1031884 */
      soundset(158); /* Line 3668, Address: 0x10318c8 */
    }
  }
} /* Line 3671, Address: 0x10318d4 */












void tenmetu() {} /* Line 3684, Address: 0x10318f0 */
