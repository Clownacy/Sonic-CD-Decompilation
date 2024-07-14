#include "..\EQU.H"
#include "BOSS_8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\IO.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SCORE.H"

extern void colchg_boss8(unsigned char* a3, unsigned char* a4);
extern void fadein_boss8();
extern void colorset2(int ColorNo);

typedef struct {
  short xOffs;
  short yOffs;
  short xDst;
  short yDst;
  short ColiNo;
}
hane_offs;

typedef struct {
  unsigned char r_no;
  unsigned char Dummy;
  short param;
}
egg8act;

typedef struct {
  int X_Speed;
  int Y_Speed;
  char Roll_Speed;
  char Dummy;
}
egg8spd;

static void egg8_ini(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_scrset(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_open1(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_wait(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_move_r(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_move_l(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_move_d(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_move_u(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_move_c(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_move_escu(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_hane_roll(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_hane_stop(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_hane_chg1(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_hane_chg2(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_hane_chg3(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_hane_fire(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_hane_reset(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_spin_d(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_spin_l(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_spin_r(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_target(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8target_ini(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8target_roll(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8target_move(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_targetreset(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_tobi_d(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_tobi(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_tobi_u(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_dead(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_esc(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_esc2(sprite_status* pActwk, sprite_status* pMecawk);
static void egg8_warai_chk(sprite_status* pActwk);
static void egg8_colichk(sprite_status* pActwk, sprite_status* pPlayerwk, sprite_status* pMecawk);
static void next_action(sprite_status* pActwk);
static void egg8meca_ini(sprite_status* pActwk, sprite_status* pEggwk);
static void egg8meca_normal(sprite_status* pActwk, sprite_status* pEggwk);
static void egg8meca_spin(sprite_status* pActwk, sprite_status* pEggwk);
static void egg8meca_chg1(sprite_status* pActwk, sprite_status* pEggwk);
static void egg8meca_chg2(sprite_status* pActwk, sprite_status* pEggwk);
static void egg8meca_chg3(sprite_status* pActwk, sprite_status* pEggwk);
static void egg8meca_fire(sprite_status* pActwk, sprite_status* pEggwk);
static void egg8meca_hane_reset(sprite_status* pActwk, sprite_status* pEggwk);
static void egg8meca_dead(sprite_status* pActwk, sprite_status* pEggwk);
static void egg8meca_tobi(sprite_status* pActwk, sprite_status* pEggwk);
static void hane_ctrl(sprite_status* pActwk);
static void hane_stop(sprite_status* pActwk);
static void hane_roll(sprite_status* pActwk);
static void futa_roll(sprite_status* pActwk);
static int egg8hane_ini(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk);
static int egg8hane_demo(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk);
static int egg8hane_normal(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk);
static int egg8hane_fire1(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk);
static int egg8hane_wait(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk);
static int egg8hane_kill(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk);
static void hane_no_reset(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk);
static void egg8hane_posiset(sprite_status* pActwk, sprite_status* pMecawk);
static void hane_offs_set(sprite_status* pActwk, sprite_status* pMecawk);
static void hane_rol_l(sprite_status* pActwk);
static void hane_rol_r(sprite_status* pActwk);
static void rol_sound(sprite_status* pActwk);
static unsigned int egg8hibana_ini(sprite_status* pActwk);
static unsigned int egg8hibana_1(sprite_status* pActwk);
static void make_meca(sprite_status* pActwk);
static void make_hane(sprite_status* pActwk);
static void make_hibana(sprite_status* pActwk);
static void egg8_spd_set(sprite_status* pActwk, sprite_status* pMecawk);
static void tobi_set(sprite_status* pActwk);
static void bom_set(sprite_status* pActwk);

static unsigned char egg8_pchg0[3] = { 255, 2, 255 };
static unsigned char egg8_pchg1[6] = { 3, 5, 6, 5, 7, 255 };
static unsigned char egg8_pchg2[6] = { 15, 8, 0, 1, 2, 255 };
static unsigned char egg8_pchg3[3] = { 255, 4, 255 };
static unsigned char egg8_pchg4[4] = { 7, 2, 3, 255 };
static unsigned char egg8_pchg5[3] = { 255, 8, 255 };
static unsigned char* egg8_pchg[6] = {
  egg8_pchg0,
  egg8_pchg1,
  egg8_pchg2,
  egg8_pchg3,
  egg8_pchg4,
  egg8_pchg5
};
static sprite_pattern egg8_pat0 = { 2, { { -12, -28, 0, 451 }, { -24, -28, 0, 443 } } };
static sprite_pattern egg8_pat1 = { 2, { { -12, -28, 0, 451 }, { -24, -28, 0, 444 } } };
static sprite_pattern egg8_pat2 = { 2, { { -12, -28, 0, 451 }, { -24, -28, 0, 445 } } };
static sprite_pattern egg8_pat3 = { 2, { { -12, -28, 0, 451 }, { -24, -28, 0, 446 } } };
static sprite_pattern egg8_pat4 = { 1, { { -24, -28, 0, 447 } } };
static sprite_pattern egg8_pat5 = { 2, { { -12, -28, 0, 451 }, { -24, -28, 0, 448 } } };
static sprite_pattern egg8_pat6 = { 2, { { -12, -28, 0, 451 }, { -24, -44, 0, 449 } } };
static sprite_pattern egg8_pat7 = { 2, { { -12, -28, 0, 451 }, { -24, -44, 0, 450 } } };
static sprite_pattern egg8_pat8 = { 1, { { -12, -28, 0, 451 } } };
sprite_pattern* egg8_pat[9] = {
  &egg8_pat0,
  &egg8_pat1,
  &egg8_pat2,
  &egg8_pat3,
  &egg8_pat4,
  &egg8_pat5,
  &egg8_pat6,
  &egg8_pat7,
  &egg8_pat8
};
static void(*egg8_act_tbl[28])(sprite_status*, sprite_status*) = {
  &egg8_ini,
  &egg8_scrset,
  &egg8_open1,
  &egg8_wait,
  &egg8_move_r,
  &egg8_move_l,
  &egg8_move_d,
  &egg8_move_u,
  &egg8_move_c,
  &egg8_move_escu,
  &egg8_hane_roll,
  &egg8_hane_stop,
  &egg8_hane_chg1,
  &egg8_hane_chg2,
  &egg8_hane_chg3,
  &egg8_hane_fire,
  &egg8_hane_reset,
  &egg8_spin_r,
  &egg8_spin_l,
  &egg8_target,
  &egg8_targetreset,
  &egg8_spin_d,
  &egg8_tobi_d,
  &egg8_tobi,
  &egg8_tobi_u,
  &egg8_dead,
  &egg8_esc,
  &egg8_esc2
};








































































































































































































































































































































































void egg8(sprite_status* pActwk) { /* Line 532, Address: 0x101cac0 */
  sprite_status *pPlayerwk, *pMecawk;
  short idx;

  pPlayerwk = &actwk[0]; /* Line 536, Address: 0x101cad8 */

  if ((idx = ((short*)pActwk)[25]) != 0) { /* Line 538, Address: 0x101cae0 */
    pMecawk = &actwk[idx]; /* Line 539, Address: 0x101cb00 */
    pMecawk->actfree[2] &= 159; /* Line 540, Address: 0x101cb20 */
  }



  egg8_warai_chk(pActwk); /* Line 545, Address: 0x101cb2c */

  if (pActwk->actfree[18] && --pActwk->actfree[18] == 0) { /* Line 547, Address: 0x101cb38 */
    pActwk->mstno.b.h = 0; /* Line 548, Address: 0x101cb68 */
  }


  egg8_colichk(pActwk, pPlayerwk, pMecawk); /* Line 552, Address: 0x101cb70 */

  if (pActwk->actfree[2] & 1) { /* Line 554, Address: 0x101cb84 */
    next_action(pActwk); /* Line 555, Address: 0x101cb9c */
  }
  pActwk->actfree[2] &= 254; /* Line 557, Address: 0x101cba8 */


  egg8_act_tbl[pActwk->r_no0 / 2](pActwk, pMecawk); /* Line 560, Address: 0x101cbb8 */
  patchg(pActwk, egg8_pchg); /* Line 561, Address: 0x101cc00 */

  colchg_boss8(&pActwk->actfree[19], &pActwk->actfree[20]); /* Line 563, Address: 0x101cc14 */

  pMecawk = &actwk[((short*)pActwk)[25]]; /* Line 565, Address: 0x101cc2c */


  if (!(pMecawk->actfree[18] / 2 & 1)) { /* Line 568, Address: 0x101cc54 */
    actionsub(pActwk); /* Line 569, Address: 0x101cc80 */
  }
} /* Line 571, Address: 0x101cc8c */






static void egg8_ini(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 578, Address: 0x101ccb0 */
  pActwk->r_no0 = 2; /* Line 579, Address: 0x101ccb8 */
  pActwk->actflg = 4; /* Line 580, Address: 0x101ccc4 */
  pActwk->sprpri = 5; /* Line 581, Address: 0x101ccd0 */
  pActwk->sprhsize = 24; /* Line 582, Address: 0x101ccdc */
  pActwk->sprvsize = 16; /* Line 583, Address: 0x101cce8 */
  pActwk->sproffset = 990; /* Line 584, Address: 0x101ccf4 */
  pActwk->patbase = egg8_pat; /* Line 585, Address: 0x101cd00 */

  pActwk->actfree[16] = 4; /* Line 587, Address: 0x101cd10 */
  pActwk->yposi.w.h -= 256; /* Line 588, Address: 0x101cd1c */
} /* Line 589, Address: 0x101cd2c */






static void egg8_scrset(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 596, Address: 0x101cd40 */
  short limwk;

  scralim_right = scralim_n_right = 3680; /* Line 599, Address: 0x101cd54 */
  if ((limwk = actwk[0].xposi.w.h - 160) >= scralim_left) { /* Line 600, Address: 0x101cd70 */
    if (actwk[0].xposi.w.h >= 3840) { /* Line 601, Address: 0x101cdc0 */

      bossflag = bossstart = 8; /* Line 603, Address: 0x101cddc */
      make_meca(pActwk); /* Line 604, Address: 0x101cdf4 */

      pMecawk = &actwk[((short*)pActwk)[25]]; /* Line 606, Address: 0x101ce00 */
      egg8_spd_set(pActwk, pMecawk); /* Line 607, Address: 0x101ce2c */

      pActwk->actfree[2] &= 253; /* Line 609, Address: 0x101ce3c */
      pActwk->r_no0 = 4; /* Line 610, Address: 0x101ce4c */

      limwk = 3680; /* Line 612, Address: 0x101ce58 */
    }


    scralim_left = scralim_n_left = limwk; /* Line 616, Address: 0x101ce64 */
  }


} /* Line 620, Address: 0x101ce74 */






static void egg8_open1(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 627, Address: 0x101ce90 */
  switch (pActwk->actfree[3]) { /* Line 628, Address: 0x101cea0 */
    case 1:
      if (++((short*)pActwk)[23] == 240) { /* Line 630, Address: 0x101ced8 */

        pActwk->yposi.w.h += 256; /* Line 632, Address: 0x101cf04 */

        sub_sync(104); /* Line 634, Address: 0x101cf14 */
        bossstart |= 128; /* Line 635, Address: 0x101cf20 */

        pActwk->actfree[0] = 0; /* Line 637, Address: 0x101cf34 */
        pActwk->actfree[1] = 0; /* Line 638, Address: 0x101cf3c */
        ++pActwk->actfree[3]; /* Line 639, Address: 0x101cf44 */
        pActwk->mstno.b.h = 2; /* Line 640, Address: 0x101cf54 */
      }

      break; /* Line 643, Address: 0x101cf60 */

    case 2:
      if ((unsigned short)pActwk->actfree[0] % 3 == 0) { /* Line 646, Address: 0x101cf68 */
        fadein_boss8(); /* Line 647, Address: 0x101cf8c */
      }


      ++pActwk->actfree[0]; /* Line 651, Address: 0x101cf94 */
      if (pActwk->actfree[0] == 63) { /* Line 652, Address: 0x101cfa4 */

        ++pActwk->actfree[3]; /* Line 654, Address: 0x101cfbc */
        pActwk->mstno.b.h = 0; /* Line 655, Address: 0x101cfcc */
        pActwk->actfree[0] = 0; /* Line 656, Address: 0x101cfd4 */
      }

      break; /* Line 659, Address: 0x101cfdc */

    case 3:
      if (++pActwk->actfree[0] == 40) { /* Line 662, Address: 0x101cfe4 */

        pActwk->actfree[2] |= 1; /* Line 664, Address: 0x101d008 */
        pActwk->actfree[0] = 0; /* Line 665, Address: 0x101d018 */

        pActwk->actfree[2] |= 8; /* Line 667, Address: 0x101d020 */
        pActwk->colino = 50; /* Line 668, Address: 0x101d030 */
        pActwk->colicnt = 2; /* Line 669, Address: 0x101d03c */
        pMecawk->colino = 51; /* Line 670, Address: 0x101d048 */
        pMecawk->colicnt = 2; /* Line 671, Address: 0x101d054 */
      }

      break; /* Line 674, Address: 0x101d060 */

    default:
      pActwk->mstno.b.h = 5; /* Line 677, Address: 0x101d068 */
      ++pActwk->actfree[3]; /* Line 678, Address: 0x101d074 */


      colorset2(7); /* Line 681, Address: 0x101d084 */
      colorset2(8); /* Line 682, Address: 0x101d090 */
      colorset2(9); /* Line 683, Address: 0x101d09c */
      break;
  }



} /* Line 689, Address: 0x101d0a8 */






static void egg8_wait(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 696, Address: 0x101d0c0 */
  unsigned char wk;

  ++pActwk->actfree[0]; /* Line 699, Address: 0x101d0cc */
  wk = pActwk->actfree[14]; /* Line 700, Address: 0x101d0dc */
  if (pActwk->actfree[0] == wk) { /* Line 701, Address: 0x101d0e8 */

    pActwk->actfree[0] = 0; /* Line 703, Address: 0x101d100 */
    pActwk->actfree[2] |= 1; /* Line 704, Address: 0x101d108 */
  }
} /* Line 706, Address: 0x101d118 */






static void egg8_move_r(sprite_status* pActwk, sprite_status* pMecawk) {  /* Line 713, Address: 0x101d130 */
  pActwk->xposi.l += ((int*)pActwk)[14]; /* Line 714, Address: 0x101d138 */
  if (pActwk->xposi.w.h >= ((short*)pActwk)[30]) { /* Line 715, Address: 0x101d150 */

    pActwk->xposi.w.h = ((short*)pActwk)[30]; /* Line 717, Address: 0x101d17c */
    pActwk->actfree[2] |= 1; /* Line 718, Address: 0x101d18c */
  }
} /* Line 720, Address: 0x101d19c */






static void egg8_move_l(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 727, Address: 0x101d1b0 */
  pActwk->xposi.l -= ((int*)pActwk)[14]; /* Line 728, Address: 0x101d1b8 */
  if (pActwk->xposi.w.h <= ((short*)pActwk)[30]) { /* Line 729, Address: 0x101d1d0 */

    pActwk->xposi.w.h = ((short*)pActwk)[30]; /* Line 731, Address: 0x101d1fc */
    pActwk->actfree[2] |= 1; /* Line 732, Address: 0x101d20c */
  }
} /* Line 734, Address: 0x101d21c */






static void egg8_move_d(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 741, Address: 0x101d230 */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 742, Address: 0x101d238 */
  if (pActwk->yposi.w.h >= ((short*)pActwk)[30]) { /* Line 743, Address: 0x101d250 */

    pActwk->yposi.w.h = ((short*)pActwk)[30]; /* Line 745, Address: 0x101d27c */
    pActwk->actfree[2] |= 1; /* Line 746, Address: 0x101d28c */
  }
} /* Line 748, Address: 0x101d29c */






static void egg8_move_u(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 755, Address: 0x101d2b0 */
  pActwk->yposi.l -= ((int*)pActwk)[4]; /* Line 756, Address: 0x101d2b8 */
  if (pActwk->yposi.w.h <= ((short*)pActwk)[30]) { /* Line 757, Address: 0x101d2d0 */

    pActwk->yposi.w.h = ((short*)pActwk)[30]; /* Line 759, Address: 0x101d2fc */
    pActwk->actfree[2] |= 1; /* Line 760, Address: 0x101d30c */
  }
} /* Line 762, Address: 0x101d31c */






static void egg8_move_c(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 769, Address: 0x101d330 */
  short xOfs;
  char sw;

  sw = 110; /* Line 773, Address: 0x101d340 */

  if (!pActwk->actfree[3]) { /* Line 775, Address: 0x101d34c */

    pActwk->actfree[3] = 2; /* Line 777, Address: 0x101d35c */

    if (pActwk->xposi.w.h <= 3840) { /* Line 779, Address: 0x101d368 */

      sw = 114; /* Line 781, Address: 0x101d384 */
    } else { /* Line 782, Address: 0x101d390 */
      sw = 108; /* Line 783, Address: 0x101d398 */
    }
  } else { /* Line 785, Address: 0x101d3a4 */
    if (!(pActwk->actfree[3] & 1)) { /* Line 786, Address: 0x101d3ac */

      pActwk->xposi.l -= ((int*)pActwk)[14]; /* Line 788, Address: 0x101d3c4 */

      if ((xOfs = ((short*)pActwk)[26]) < pActwk->xposi.w.h) return; /* Line 790, Address: 0x101d3dc */


    } /* Line 793, Address: 0x101d410 */
    else {
      pActwk->xposi.l += ((int*)pActwk)[14]; /* Line 795, Address: 0x101d418 */

      if ((xOfs = ((short*)pActwk)[26]) > pActwk->xposi.w.h) return; /* Line 797, Address: 0x101d430 */
    }





    pActwk->xposi.w.h = xOfs; /* Line 804, Address: 0x101d464 */


    if (!((short*)pActwk)[30]) { /* Line 807, Address: 0x101d46c */

      pActwk->actfree[2] |= 1; /* Line 809, Address: 0x101d47c */
    } else if (!(--((short*)pActwk)[30])) { /* Line 810, Address: 0x101d48c */
      sw = 99; /* Line 811, Address: 0x101d4b4 */
    } else {/* Line 812, Address: 0x101d4c0 */
      if (!(pActwk->actfree[3] & 1)) { /* Line 813, Address: 0x101d4c8 */
        sw = 114; /* Line 814, Address: 0x101d4e0 */
      } else { /* Line 815, Address: 0x101d4ec */
        sw = 108; /* Line 816, Address: 0x101d4f4 */
      }

      pActwk->actfree[3] ^= 1; /* Line 819, Address: 0x101d500 */
    }
  }

  switch (sw) { /* Line 823, Address: 0x101d510 */

    case 108:
      pActwk->actfree[3] &= 254; /* Line 826, Address: 0x101d544 */
      ((short*)pActwk)[26] = 3716; /* Line 827, Address: 0x101d554 */
      break; /* Line 828, Address: 0x101d560 */


    case 114:
      pActwk->actfree[3] |= 1; /* Line 832, Address: 0x101d568 */
      ((short*)pActwk)[26] = 3964; /* Line 833, Address: 0x101d578 */
      break; /* Line 834, Address: 0x101d584 */


    case 99:
      pActwk->actfree[3] ^= 1; /* Line 838, Address: 0x101d58c */
      ((short*)pActwk)[26] = 3840; /* Line 839, Address: 0x101d59c */
      break;
  }



} /* Line 845, Address: 0x101d5a8 */






static void egg8_move_escu(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 852, Address: 0x101d5c0 */
  if (!pActwk->actfree[3]) { /* Line 853, Address: 0x101d5d0 */
    egg8_hane_chg3(pActwk, pMecawk); /* Line 854, Address: 0x101d5e0 */
    pActwk->actfree[2] &= 254; /* Line 855, Address: 0x101d5f0 */
    pActwk->actfree[3] = 1; /* Line 856, Address: 0x101d600 */
  }


  pActwk->yposi.l -= 81920; /* Line 860, Address: 0x101d60c */
  if (pActwk->yposi.w.h <= ((short*)pActwk)[30]) { /* Line 861, Address: 0x101d624 */

    pActwk->yposi.w.h = ((short*)pActwk)[30]; /* Line 863, Address: 0x101d650 */
    pActwk->actfree[2] |= 1; /* Line 864, Address: 0x101d660 */
  }
} /* Line 866, Address: 0x101d670 */






static void egg8_hane_roll(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 873, Address: 0x101d680 */
  if (!(pMecawk->actfree[16] & 64)) { /* Line 874, Address: 0x101d68c */
    pMecawk->actfree[2] |= 16; /* Line 875, Address: 0x101d6a4 */
    pMecawk->actfree[3] = 0; /* Line 876, Address: 0x101d6b4 */
    pMecawk->actfree[1] = 0; /* Line 877, Address: 0x101d6bc */
  }


  pActwk->actfree[2] |= 1; /* Line 881, Address: 0x101d6c4 */
} /* Line 882, Address: 0x101d6d4 */






static void egg8_hane_stop(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 889, Address: 0x101d6e0 */
  if (!pActwk->actfree[3]) { /* Line 890, Address: 0x101d6ec */

    ++pActwk->actfree[3]; /* Line 892, Address: 0x101d6fc */
    pMecawk->actfree[2] |= 16; /* Line 893, Address: 0x101d70c */
    pMecawk->actfree[16] &= 127; /* Line 894, Address: 0x101d71c */
    pMecawk->actfree[3] = 0; /* Line 895, Address: 0x101d72c */
    pMecawk->actfree[1] = 0; /* Line 896, Address: 0x101d734 */

    if (pActwk->actfree[16] == 2) { /* Line 898, Address: 0x101d73c */

      pMecawk->actfree[12] = 8; /* Line 900, Address: 0x101d754 */
    } else { /* Line 901, Address: 0x101d760 */
      pMecawk->actfree[12] = 4; /* Line 902, Address: 0x101d768 */
    }
  }


  if (pMecawk->actfree[16] & 128) { /* Line 907, Address: 0x101d774 */

    pActwk->actfree[2] |= 1; /* Line 909, Address: 0x101d78c */
  }
} /* Line 911, Address: 0x101d79c */






static void egg8_hane_chg1(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 918, Address: 0x101d7b0 */
  pMecawk->actfree[3] = 0; /* Line 919, Address: 0x101d7bc */
  pMecawk->actfree[0] = 0; /* Line 920, Address: 0x101d7c4 */
  pMecawk->actfree[1] = 0; /* Line 921, Address: 0x101d7cc */
  pMecawk->actfree[16] |= 160; /* Line 922, Address: 0x101d7d4 */
  pMecawk->actfree[16] &= 191; /* Line 923, Address: 0x101d7e4 */
  pMecawk->r_no0 = 4; /* Line 924, Address: 0x101d7f4 */

  pActwk->actfree[0] = 0; /* Line 926, Address: 0x101d800 */
  pActwk->actfree[1] = 0; /* Line 927, Address: 0x101d808 */
  pActwk->actfree[2] |= 1; /* Line 928, Address: 0x101d810 */
} /* Line 929, Address: 0x101d820 */






static void egg8_hane_chg2(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 936, Address: 0x101d830 */
  soundset(201); /* Line 937, Address: 0x101d840 */

  pMecawk->actfree[3] = 0; /* Line 939, Address: 0x101d84c */
  pMecawk->actfree[0] = 0; /* Line 940, Address: 0x101d854 */
  pMecawk->actfree[1] = 0; /* Line 941, Address: 0x101d85c */
  pMecawk->r_no0 = 6; /* Line 942, Address: 0x101d864 */

  pActwk->actfree[2] |= 1; /* Line 944, Address: 0x101d870 */
} /* Line 945, Address: 0x101d880 */






static void egg8_hane_chg3(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 952, Address: 0x101d890 */
  pMecawk->actfree[3] = 0; /* Line 953, Address: 0x101d89c */
  pMecawk->actfree[0] = 0; /* Line 954, Address: 0x101d8a4 */
  pMecawk->actfree[1] = 0; /* Line 955, Address: 0x101d8ac */
  pMecawk->r_no0 = 8; /* Line 956, Address: 0x101d8b4 */

  pActwk->actfree[2] |= 1; /* Line 958, Address: 0x101d8c0 */
} /* Line 959, Address: 0x101d8d0 */






static void egg8_hane_fire(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 966, Address: 0x101d8e0 */
  switch (pActwk->actfree[3]) { /* Line 967, Address: 0x101d8f0 */

    case 1:
      ((short*)pActwk)[30] = 316; /* Line 970, Address: 0x101d91c */
      egg8_move_u(pActwk, pMecawk); /* Line 971, Address: 0x101d928 */

      if (pActwk->actfree[2] & 1) { /* Line 973, Address: 0x101d938 */

        ++pActwk->actfree[3]; /* Line 975, Address: 0x101d950 */
      }

      pActwk->actfree[2] &= 254; /* Line 978, Address: 0x101d960 */
      break; /* Line 979, Address: 0x101d970 */


    case 2:
      if (pMecawk->actfree[19] == pActwk->actfree[16] * 2) { /* Line 983, Address: 0x101d978 */

        pActwk->actfree[2] |= 1; /* Line 985, Address: 0x101d99c */
      }
      break; /* Line 987, Address: 0x101d9ac */


    default:
      ++pActwk->actfree[3]; /* Line 991, Address: 0x101d9b4 */
      pMecawk->actfree[3] = 0; /* Line 992, Address: 0x101d9c4 */
      pMecawk->actfree[0] = 0; /* Line 993, Address: 0x101d9cc */
      pMecawk->actfree[1] = 0; /* Line 994, Address: 0x101d9d4 */
      pMecawk->r_no0 = 10; /* Line 995, Address: 0x101d9dc */
      pMecawk->actfree[19] = 0; /* Line 996, Address: 0x101d9e8 */
      pMecawk->actfree[20] = 0; /* Line 997, Address: 0x101d9f0 */
      break;
  }
} /* Line 1000, Address: 0x101d9f8 */






static void egg8_hane_reset(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1007, Address: 0x101da10 */
  pMecawk->actfree[3] = 0; /* Line 1008, Address: 0x101da1c */
  pMecawk->actfree[0] = 0; /* Line 1009, Address: 0x101da24 */
  pMecawk->actfree[1] = 0; /* Line 1010, Address: 0x101da2c */
  pMecawk->r_no0 = 12; /* Line 1011, Address: 0x101da34 */

  pActwk->actfree[2] |= 1; /* Line 1013, Address: 0x101da40 */
} /* Line 1014, Address: 0x101da50 */






static void egg8_spin_d(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1021, Address: 0x101da60 */
  int tateini = 0; /* Line 1022, Address: 0x101da74 */

  if (!pActwk->actfree[3]) { /* Line 1024, Address: 0x101da78 */

    if (pActwk->actfree[16] == 4) { /* Line 1026, Address: 0x101da88 */

      pMecawk->actfree[12] = 8; /* Line 1028, Address: 0x101daa0 */


      tateini = 1; /* Line 1031, Address: 0x101daac */
    } /* Line 1032, Address: 0x101dab0 */
    else {
      if (actwk[0].xposi.w.h < pActwk->xposi.w.h) { /* Line 1034, Address: 0x101dab8 */

        pMecawk->actfree[12] = 8; /* Line 1036, Address: 0x101dae4 */


        ((short*)pActwk)[30] = 3964; /* Line 1039, Address: 0x101daf0 */
        pActwk->actfree[3] = 1; /* Line 1040, Address: 0x101dafc */
      } /* Line 1041, Address: 0x101db08 */
      else {
        if (pActwk->actfree[16] != 3) { /* Line 1043, Address: 0x101db10 */

          pMecawk->actfree[12] = 4; /* Line 1045, Address: 0x101db28 */
        } /* Line 1046, Address: 0x101db34 */
        else {
          pMecawk->actfree[12] = 0; /* Line 1048, Address: 0x101db3c */
        }


        ((short*)pActwk)[30] = 3716; /* Line 1052, Address: 0x101db44 */
        pActwk->actfree[3] = 2; /* Line 1053, Address: 0x101db50 */
      }
    }
  }

  if (pActwk->actfree[3] == 3) { /* Line 1058, Address: 0x101db5c */

    tateini = 2; /* Line 1060, Address: 0x101db74 */
  } else if (pActwk->actfree[3]) { /* Line 1061, Address: 0x101db78 */
    if (pActwk->actfree[3] == 1) { /* Line 1062, Address: 0x101db90 */

      egg8_move_r(pActwk, pMecawk); /* Line 1064, Address: 0x101dba8 */
    } /* Line 1065, Address: 0x101dbb8 */
    else {
      egg8_move_l(pActwk, pMecawk); /* Line 1067, Address: 0x101dbc0 */
    }


    if (pActwk->actfree[2] & 1) { /* Line 1071, Address: 0x101dbd0 */
      tateini = 1; /* Line 1072, Address: 0x101dbe8 */
    }

    pActwk->actfree[2] &= 254; /* Line 1075, Address: 0x101dbec */
  }

  switch (tateini) { /* Line 1078, Address: 0x101dbfc */

    case 1:
      pMecawk->actfree[2] |= 16; /* Line 1081, Address: 0x101dc1c */
      pMecawk->actfree[16] &= 127; /* Line 1082, Address: 0x101dc2c */
      pMecawk->actfree[3] = 0; /* Line 1083, Address: 0x101dc3c */
      pMecawk->actfree[1] = 0; /* Line 1084, Address: 0x101dc44 */

      ((short*)pActwk)[30] = 416; /* Line 1086, Address: 0x101dc4c */
      pActwk->actfree[3] = 3; /* Line 1087, Address: 0x101dc58 */

    case 2:
      egg8_move_d(pActwk, pMecawk); /* Line 1090, Address: 0x101dc64 */

      if (pActwk->actfree[2] & 1) { /* Line 1092, Address: 0x101dc74 */

        pActwk->actfree[3] = 0; /* Line 1094, Address: 0x101dc8c */
      }
      break;
  }



} /* Line 1101, Address: 0x101dc94 */






static void egg8_spin_l(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1108, Address: 0x101dcb0 */
  egg8_spin_r(pActwk, pMecawk); /* Line 1109, Address: 0x101dcc0 */
} /* Line 1110, Address: 0x101dcd0 */






























static short spin_tbl1[32] = {
  26, -4, 26, 6,
  26, -6, 26, 4,
  26, -4, 26, 6,
  26, -6, 26, 4,
  26, -4, 26, 6,
  26, -6, 26, 4,
  26, -4, 26, 6,
  26, -6, 26, 4
};
static short spin_tbl3[32] = {
  26, -4, 26, 6,
  26, -6, 26, 4,
  26, -4, 26, 6,
  26, -6, 26, 4,
  26, -4, 26, 6,
  26, -6, 26, 4,
  26, -4, 26, 6,
  21, 15, 26, 22
};
static short* spin_tbl[5] = {
  0,
  spin_tbl1,
  spin_tbl1,
  spin_tbl3,
  spin_tbl1
};

static void egg8_spin_r(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1169, Address: 0x101dce0 */
  short *pSpinTbl, xwk, ywk;
  unsigned char hanecntwk, para0wk;

  if ((char)pActwk->actfree[3] >= 5) { /* Line 1173, Address: 0x101dd04 */

    pMecawk->r_no0 = 2; /* Line 1175, Address: 0x101dd28 */
    pMecawk->actfree[3] = 0; /* Line 1176, Address: 0x101dd34 */
    pMecawk->actfree[1] = 0; /* Line 1177, Address: 0x101dd3c */

    pActwk->actfree[3] = 0; /* Line 1179, Address: 0x101dd44 */
    pActwk->actfree[0] = 0; /* Line 1180, Address: 0x101dd4c */
    pActwk->actfree[1] = 0; /* Line 1181, Address: 0x101dd54 */
    pActwk->actfree[2] |= 1; /* Line 1182, Address: 0x101dd5c */
  } else if (pActwk->actfree[3] & 128) { /* Line 1183, Address: 0x101dd6c */

    if (++pActwk->actfree[0] == 60) { /* Line 1185, Address: 0x101dd8c */
      pActwk->actfree[0] = 0; /* Line 1186, Address: 0x101ddb0 */
      pActwk->actfree[3] &= 127; /* Line 1187, Address: 0x101ddb8 */
    }


  } else { /* Line 1191, Address: 0x101ddc8 */
    if (!pActwk->actfree[3]) { /* Line 1192, Address: 0x101ddd0 */

      pActwk->actfree[0] = 0; /* Line 1194, Address: 0x101dde0 */
      pActwk->actfree[15] = 0; /* Line 1195, Address: 0x101dde8 */

      if ((pActwk->actfree[16] == 4 /* Line 1197, Address: 0x101ddf0 */
            && actwk[0].xposi.w.h >= pActwk->xposi.w.h)
          ||
          (pActwk->actfree[16] != 4
            && pActwk->xposi.w.h < 3840)) {
        pActwk->actfree[1] = 0; /* Line 1202, Address: 0x101de68 */
        pActwk->actfree[3] = 2; /* Line 1203, Address: 0x101de70 */
      } /* Line 1204, Address: 0x101de7c */
      else {
        pActwk->actfree[1] = 7; /* Line 1206, Address: 0x101de84 */
        pActwk->actfree[3] = 1; /* Line 1207, Address: 0x101de90 */
      }


      pMecawk->r_no0 = 14; /* Line 1211, Address: 0x101de9c */
      pMecawk->actfree[3] = 0; /* Line 1212, Address: 0x101dea8 */
      pMecawk->actfree[1] = 0; /* Line 1213, Address: 0x101deb0 */
    }


    if (++pActwk->actfree[0] == 20) { /* Line 1217, Address: 0x101deb8 */

      ++((char*)pActwk)[61]; /* Line 1219, Address: 0x101dedc */

      if (!(((char*)pActwk)[61] & 1)) { /* Line 1221, Address: 0x101deec */
        sub_sync(126); /* Line 1222, Address: 0x101df08 */
      }


      pActwk->actfree[0] = 0; /* Line 1226, Address: 0x101df14 */


      pSpinTbl = spin_tbl[pActwk->actfree[16]]; /* Line 1229, Address: 0x101df1c */
      pSpinTbl += (pActwk->actfree[1] & 15) * 2; /* Line 1230, Address: 0x101df3c */

      xwk = *pSpinTbl++; /* Line 1232, Address: 0x101df58 */
      ywk = *pSpinTbl++; /* Line 1233, Address: 0x101df6c */

      if (pActwk->actfree[3] & 1) { /* Line 1235, Address: 0x101df80 */

        pMecawk->actfree[2] |= 64; /* Line 1237, Address: 0x101df98 */
        xwk *= -1; /* Line 1238, Address: 0x101dfa8 */
        ywk *= -1; /* Line 1239, Address: 0x101dfb4 */
      } /* Line 1240, Address: 0x101dfc0 */
      else {
        pMecawk->actfree[2] |= 32; /* Line 1242, Address: 0x101dfc8 */
      }


      pActwk->xposi.w.h += xwk; /* Line 1246, Address: 0x101dfd8 */
      pActwk->yposi.w.h += ywk; /* Line 1247, Address: 0x101dfe8 */

      hanecntwk = pActwk->actfree[16]; /* Line 1249, Address: 0x101dff8 */
      para0wk = ((char*)pActwk)[61]; /* Line 1250, Address: 0x101e004 */

      if ((hanecntwk == 4 && (para0wk == 4 || para0wk == 12)) /* Line 1252, Address: 0x101e010 */
          ||
          (hanecntwk != 4 && (para0wk == 4 || para0wk == 8))) {
        if ((char)pActwk->actfree[3] >= 3) { /* Line 1255, Address: 0x101e070 */

          pActwk->actfree[3] = 133; /* Line 1257, Address: 0x101e094 */


          if (pActwk->actfree[3] & 1) { /* Line 1260, Address: 0x101e0a0 */

            --pActwk->actfree[1]; /* Line 1262, Address: 0x101e0b8 */
          } /* Line 1263, Address: 0x101e0c8 */
          else {
            ++pActwk->actfree[1]; /* Line 1265, Address: 0x101e0d0 */
          }
        } else if (pActwk->actfree[3] == 1) { /* Line 1267, Address: 0x101e0e0 */

          pActwk->actfree[3] = 132; /* Line 1269, Address: 0x101e100 */
        } /* Line 1270, Address: 0x101e10c */
        else {
          pActwk->actfree[3] = 131; /* Line 1272, Address: 0x101e114 */
        }
      } /* Line 1274, Address: 0x101e120 */
      else {
        if (pActwk->actfree[3] & 1) { /* Line 1276, Address: 0x101e128 */

          --pActwk->actfree[1]; /* Line 1278, Address: 0x101e140 */
        } /* Line 1279, Address: 0x101e150 */
        else {
          ++pActwk->actfree[1]; /* Line 1281, Address: 0x101e158 */
        }
      }
    }
  }


} /* Line 1288, Address: 0x101e168 */






static void egg8_target(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1295, Address: 0x101e190 */
  if (!pActwk->actfree[3]) { /* Line 1296, Address: 0x101e1a0 */

    egg8target_ini(pActwk, pMecawk); /* Line 1298, Address: 0x101e1b0 */
  }


  if (!(pActwk->actfree[3] & 2)) { /* Line 1302, Address: 0x101e1c0 */

    egg8target_roll(pActwk, pMecawk); /* Line 1304, Address: 0x101e1d8 */
  }


  if (!(pActwk->actfree[3] & 4)) { /* Line 1308, Address: 0x101e1e8 */

    egg8target_move(pActwk, pMecawk); /* Line 1310, Address: 0x101e200 */
  }

  if (pActwk->actfree[3] == 7) { /* Line 1313, Address: 0x101e210 */

    pActwk->actfree[2] |= 1; /* Line 1315, Address: 0x101e228 */
  }
} /* Line 1317, Address: 0x101e238 */





static void egg8target_ini(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1323, Address: 0x101e250 */
  short xPos, xSav;
  int_union xwk, ywk;

  pActwk->actfree[3] |= 1; /* Line 1327, Address: 0x101e264 */
  xwk.w.l = xSav = xPos = actwk[0].xposi.w.h - pActwk->xposi.w.h; /* Line 1328, Address: 0x101e274 */

  if (xSav < 0) { /* Line 1330, Address: 0x101e2c4 */
    xPos *= -1; /* Line 1331, Address: 0x101e2d4 */
  }


  pMecawk->actfree[2] |= 16; /* Line 1335, Address: 0x101e2e0 */
  pMecawk->actfree[16] &= 127; /* Line 1336, Address: 0x101e2f0 */
  pMecawk->actfree[3] = 0; /* Line 1337, Address: 0x101e300 */
  pMecawk->actfree[1] = 0; /* Line 1338, Address: 0x101e308 */

  if (xPos < 64) { /* Line 1340, Address: 0x101e310 */

    xwk.l = xwk.w.l; /* Line 1342, Address: 0x101e324 */
    xwk.l = xwk.l * 16 / 90 * 4096; /* Line 1343, Address: 0x101e334 */
    ((int*)pActwk)[14] = xwk.l; /* Line 1344, Address: 0x101e35c */

    ywk.l = (380 - pActwk->yposi.w.h) * 16 / 90 * 4096; /* Line 1346, Address: 0x101e368 */
    ((int*)pActwk)[4] = ywk.l; /* Line 1347, Address: 0x101e3a4 */

    if (pActwk->actfree[16] != 2) { /* Line 1349, Address: 0x101e3b0 */

      pMecawk->actfree[12] = 4; /* Line 1351, Address: 0x101e3c8 */
    } /* Line 1352, Address: 0x101e3d4 */
    else {
      pMecawk->actfree[12] = 6; /* Line 1354, Address: 0x101e3dc */
    }
  } /* Line 1356, Address: 0x101e3e8 */
  else {
    if (xSav >= 0) { /* Line 1358, Address: 0x101e3f0 */

      xwk.w.l -= 16; /* Line 1360, Address: 0x101e400 */
    } else { /* Line 1361, Address: 0x101e40c */
      xwk.w.l += 16; /* Line 1362, Address: 0x101e414 */
    }


    xwk.l = xwk.w.l; /* Line 1366, Address: 0x101e420 */
    xwk.l = xwk.l * 16 / 90 * 4096; /* Line 1367, Address: 0x101e430 */
    ((int*)pActwk)[14] = xwk.l; /* Line 1368, Address: 0x101e458 */

    ywk.l = (394 - pActwk->yposi.w.h) * 16 / 90 * 4096; /* Line 1370, Address: 0x101e464 */
    ((int*)pActwk)[4] = ywk.l; /* Line 1371, Address: 0x101e4a0 */

    if (pActwk->actfree[16] != 2 && xSav >= 0) { /* Line 1373, Address: 0x101e4ac */
      pMecawk->actfree[12] = 2; /* Line 1374, Address: 0x101e4d4 */
    } /* Line 1375, Address: 0x101e4e0 */
    else {
      pMecawk->actfree[12] = 6; /* Line 1377, Address: 0x101e4e8 */
    }
  }
} /* Line 1380, Address: 0x101e4f4 */





static void egg8target_roll(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1386, Address: 0x101e510 */
  if (pMecawk->actfree[16] & 128) { /* Line 1387, Address: 0x101e51c */

    pActwk->actfree[3] |= 2; /* Line 1389, Address: 0x101e534 */
  }
} /* Line 1391, Address: 0x101e544 */





static void egg8target_move(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1397, Address: 0x101e550 */
  short ywk;

  if (!(pMecawk->actfree[12] & 3)) { /* Line 1400, Address: 0x101e560 */
    ywk = 380; /* Line 1401, Address: 0x101e578 */
  } else { /* Line 1402, Address: 0x101e584 */
    ywk = 394; /* Line 1403, Address: 0x101e58c */
  }


  pActwk->xposi.l += ((int*)pActwk)[14]; /* Line 1407, Address: 0x101e598 */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 1408, Address: 0x101e5b0 */

  if (pActwk->yposi.w.h >= ywk) { /* Line 1410, Address: 0x101e5c8 */

    pActwk->yposi.w.h = ywk; /* Line 1412, Address: 0x101e5ec */
    ((int*)pActwk)[14] *= -1; /* Line 1413, Address: 0x101e5f4 */
    ((int*)pActwk)[4] *= -1; /* Line 1414, Address: 0x101e604 */
    pActwk->actfree[3] |= 4; /* Line 1415, Address: 0x101e614 */
  }
} /* Line 1417, Address: 0x101e624 */






static void egg8_targetreset(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1424, Address: 0x101e640 */
  pActwk->xposi.l += ((int*)pActwk)[14]; /* Line 1425, Address: 0x101e650 */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 1426, Address: 0x101e668 */

  if (pActwk->yposi.w.h <= 316) { /* Line 1428, Address: 0x101e680 */

    pActwk->yposi.w.h = 316; /* Line 1430, Address: 0x101e69c */
    pActwk->actfree[3] = 0; /* Line 1431, Address: 0x101e6a8 */
    pActwk->actfree[2] |= 1; /* Line 1432, Address: 0x101e6b0 */

    egg8_spd_set(pActwk, pMecawk); /* Line 1434, Address: 0x101e6c0 */
  }
} /* Line 1436, Address: 0x101e6d0 */






static void egg8_tobi_d(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1443, Address: 0x101e6e0 */
  if (pActwk->actfree[3] == 0 || pActwk->actfree[3] > 5) { /* Line 1444, Address: 0x101e6f0 */

    if (pActwk->xposi.w.h > actwk[0].xposi.w.h) { /* Line 1446, Address: 0x101e71c */

      ((short*)pActwk)[30] = 3964; /* Line 1448, Address: 0x101e748 */
      pActwk->actfree[3] = 1; /* Line 1449, Address: 0x101e754 */
    } /* Line 1450, Address: 0x101e760 */
    else {
      ((short*)pActwk)[30] = 3716; /* Line 1452, Address: 0x101e768 */
      pActwk->actfree[3] = 2; /* Line 1453, Address: 0x101e774 */
    }
  }

  if (pActwk->actfree[3] == 1) { /* Line 1457, Address: 0x101e780 */

    egg8_move_r(pActwk, pMecawk); /* Line 1459, Address: 0x101e798 */
  } else if (pActwk->actfree[3] == 2) { /* Line 1460, Address: 0x101e7a8 */

    egg8_move_l(pActwk, pMecawk); /* Line 1462, Address: 0x101e7c8 */
  }

  if (pActwk->actfree[3] == 1 || pActwk->actfree[3] == 2) { /* Line 1465, Address: 0x101e7d8 */

    if (!(pActwk->actfree[2] & 1)) return; /* Line 1467, Address: 0x101e808 */



    pActwk->actfree[2] &= 254; /* Line 1471, Address: 0x101e820 */


    pMecawk->actfree[2] |= 16; /* Line 1474, Address: 0x101e830 */
    pMecawk->actfree[16] &= 127; /* Line 1475, Address: 0x101e840 */
    pMecawk->actfree[12] = 8; /* Line 1476, Address: 0x101e850 */
    pMecawk->actfree[3] = 0; /* Line 1477, Address: 0x101e85c */
    pMecawk->actfree[1] = 0; /* Line 1478, Address: 0x101e864 */

    pActwk->actfree[3] = 3; /* Line 1480, Address: 0x101e86c */
  }

  if (pActwk->actfree[3] == 3) { /* Line 1483, Address: 0x101e878 */

    if (!(pMecawk->actfree[16] & 128)) return; /* Line 1485, Address: 0x101e890 */




    ((short*)pActwk)[30] = 312; /* Line 1490, Address: 0x101e8a8 */

    pActwk->actfree[3] = 4; /* Line 1492, Address: 0x101e8b4 */
  }





  if (pActwk->actfree[3] == 4 || pActwk->actfree[3] > 5) { /* Line 1499, Address: 0x101e8c0 */

    egg8_move_d(pActwk, pMecawk); /* Line 1501, Address: 0x101e8f0 */

    if (!(pActwk->actfree[2] & 1)) return; /* Line 1503, Address: 0x101e900 */



    pActwk->actfree[2] &= 254; /* Line 1507, Address: 0x101e918 */


    pActwk->actfree[3] = 5; /* Line 1510, Address: 0x101e928 */
    ((short*)pActwk)[26] = 0; /* Line 1511, Address: 0x101e934 */
    ((short*)pActwk)[27] = -104; /* Line 1512, Address: 0x101e93c */
    ((short*)pActwk)[23] = 16384; /* Line 1513, Address: 0x101e948 */
  }

  if (pActwk->actfree[3] == 5) { /* Line 1516, Address: 0x101e954 */

    tobi_set(pActwk); /* Line 1518, Address: 0x101e96c */
    pActwk->xposi.w.h -= ((short*)pActwk)[26]; /* Line 1519, Address: 0x101e978 */
    ((short*)pActwk)[26] = 0; /* Line 1520, Address: 0x101e990 */

    if (((short*)pActwk)[23] == -32768) { /* Line 1522, Address: 0x101e998 */

      pActwk->actfree[3] = 0; /* Line 1524, Address: 0x101e9b4 */
      pActwk->actfree[2] |= 1; /* Line 1525, Address: 0x101e9bc */

      soundset(180); /* Line 1527, Address: 0x101e9cc */
    }
  }


} /* Line 1532, Address: 0x101e9d8 */






static void egg8_tobi(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1539, Address: 0x101e9f0 */
  short xwk;

  if ((char)pActwk->actfree[3] < 5) { /* Line 1542, Address: 0x101ea04 */
    if (!pActwk->actfree[3]) { /* Line 1543, Address: 0x101ea28 */

      ((short*)pActwk)[27] = 0; /* Line 1545, Address: 0x101ea38 */
      ((short*)pActwk)[23] = 0; /* Line 1546, Address: 0x101ea40 */

      if (pActwk->xposi.w.h < 3840) { /* Line 1548, Address: 0x101ea48 */

        ((short*)pActwk)[26] = -41; /* Line 1550, Address: 0x101ea64 */
        pActwk->actfree[3] = 2; /* Line 1551, Address: 0x101ea70 */
      } /* Line 1552, Address: 0x101ea7c */
      else {
        ((short*)pActwk)[26] = 41; /* Line 1554, Address: 0x101ea84 */
        pActwk->actfree[3] = 1; /* Line 1555, Address: 0x101ea90 */
      }


      pMecawk->r_no0 = 18; /* Line 1559, Address: 0x101ea9c */
      pMecawk->actfree[10] = 2; /* Line 1560, Address: 0x101eaa8 */
      pMecawk->actfree[3] = 0; /* Line 1561, Address: 0x101eab4 */
      pMecawk->actfree[1] = 0; /* Line 1562, Address: 0x101eabc */
    }


    tobi_set(pActwk); /* Line 1566, Address: 0x101eac4 */

    if (((short*)pActwk)[23] != -32768) return; /* Line 1568, Address: 0x101ead0 */




    soundset(180); /* Line 1573, Address: 0x101eaec */

    ((short*)pActwk)[27] = 0; /* Line 1575, Address: 0x101eaf8 */
    ((short*)pActwk)[23] = 0; /* Line 1576, Address: 0x101eb00 */

    if (pActwk->actfree[3] & 1) { /* Line 1578, Address: 0x101eb08 */

      ((short*)pActwk)[26] = 41; /* Line 1580, Address: 0x101eb20 */

      if ((xwk = pActwk->xposi.w.h - 3716) < 0) { /* Line 1582, Address: 0x101eb2c */
        xwk *= -1; /* Line 1583, Address: 0x101eb68 */
      }
    } /* Line 1585, Address: 0x101eb74 */
    else {
      ((short*)pActwk)[26] = -41; /* Line 1587, Address: 0x101eb7c */

      if ((xwk = pActwk->xposi.w.h - 3964) < 0) { /* Line 1589, Address: 0x101eb88 */
        xwk *= -1; /* Line 1590, Address: 0x101ebc4 */
      }
    }



    if (xwk >= 41) return; /* Line 1596, Address: 0x101ebd0 */




    ((short*)pActwk)[26] *= -1; /* Line 1601, Address: 0x101ebe4 */
    if (pActwk->actfree[3] < 3) { /* Line 1602, Address: 0x101ebf4 */
      if (pActwk->actfree[3] != 1) { /* Line 1603, Address: 0x101ec0c */

        pActwk->actfree[3] = 3; /* Line 1605, Address: 0x101ec24 */
      } /* Line 1606, Address: 0x101ec30 */
      else {
        pActwk->actfree[3] = 4; /* Line 1608, Address: 0x101ec38 */
      }

      return; /* Line 1611, Address: 0x101ec44 */
    }
  }


  pActwk->actfree[3] = 0; /* Line 1616, Address: 0x101ec4c */
  pActwk->actfree[2] |= 1; /* Line 1617, Address: 0x101ec54 */

  pMecawk->r_no0 = 2; /* Line 1619, Address: 0x101ec64 */
  pMecawk->actfree[3] = 0; /* Line 1620, Address: 0x101ec70 */
  pMecawk->actfree[1] = 0; /* Line 1621, Address: 0x101ec78 */
  pMecawk->actfree[14] = 0; /* Line 1622, Address: 0x101ec80 */
} /* Line 1623, Address: 0x101ec88 */






static void egg8_tobi_u(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1630, Address: 0x101eca0 */
  if (!pActwk->actfree[3]) { /* Line 1631, Address: 0x101ecac */

    pActwk->actfree[3] = 1; /* Line 1633, Address: 0x101ecbc */
    ((short*)pActwk)[26] = 0; /* Line 1634, Address: 0x101ecc8 */
    ((short*)pActwk)[27] = 0; /* Line 1635, Address: 0x101ecd0 */
    ((short*)pActwk)[23] = 0; /* Line 1636, Address: 0x101ecd8 */
  }


  tobi_set(pActwk); /* Line 1640, Address: 0x101ece0 */
  pActwk->xposi.w.h -= ((short*)pActwk)[26]; /* Line 1641, Address: 0x101ecec */
  ((short*)pActwk)[26] = 0; /* Line 1642, Address: 0x101ed04 */

  if (((short*)pActwk)[23] >= 16384) { /* Line 1644, Address: 0x101ed0c */

    pActwk->actfree[3] = 0; /* Line 1646, Address: 0x101ed28 */
    pActwk->actfree[2] |= 1; /* Line 1647, Address: 0x101ed30 */
    pActwk->actfree[0] = 0; /* Line 1648, Address: 0x101ed40 */
    pActwk->actfree[1] = 0; /* Line 1649, Address: 0x101ed48 */
    ((short*)pActwk)[27] = 0; /* Line 1650, Address: 0x101ed50 */
  }
} /* Line 1652, Address: 0x101ed58 */






static void egg8_dead(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1659, Address: 0x101ed70 */
  sprite_status* pNewact;

  if (!pActwk->actfree[0]) { /* Line 1662, Address: 0x101ed80 */

    pActwk->mstno.b.h = 3; /* Line 1664, Address: 0x101ed90 */
    pActwk->actfree[18] = 0; /* Line 1665, Address: 0x101ed9c */

    pMecawk->r_no0 = 16; /* Line 1667, Address: 0x101eda4 */
    pMecawk->patno = 3; /* Line 1668, Address: 0x101edb0 */
    pActwk->colino = 0; /* Line 1669, Address: 0x101edbc */
    pActwk->colicnt = 0; /* Line 1670, Address: 0x101edc4 */
    pMecawk->colino = 0; /* Line 1671, Address: 0x101edcc */
    pMecawk->colicnt = 0; /* Line 1672, Address: 0x101edd4 */
    pActwk->actfree[2] &= 247; /* Line 1673, Address: 0x101eddc */
  }


  if (++pActwk->actfree[0] >= 90) { /* Line 1677, Address: 0x101edec */

    if (actwkchk(&pNewact) != 0) return; /* Line 1679, Address: 0x101ee10 */
    pNewact->actno = 67; /* Line 1680, Address: 0x101ee24 */
    pNewact->xposi.w.h = 3656; /* Line 1681, Address: 0x101ee30 */
    pNewact->yposi.w.h = 460; /* Line 1682, Address: 0x101ee3c */


    pActwk->r_no0 = 52; /* Line 1685, Address: 0x101ee48 */



  } else { /* Line 1689, Address: 0x101ee54 */
    bom_set(pActwk); /* Line 1690, Address: 0x101ee5c */
  }
} /* Line 1692, Address: 0x101ee68 */






static void egg8_esc(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1699, Address: 0x101ee80 */
  unsigned char dirwk;
  short sinwk, coswk;

  if (!pActwk->actfree[3]) { /* Line 1703, Address: 0x101ee90 */

    scoreup(100); /* Line 1705, Address: 0x101eea0 */

    pActwk->actfree[1] = 0; /* Line 1707, Address: 0x101eeac */
    ((short*)pActwk)[27] = 0; /* Line 1708, Address: 0x101eeb4 */
    ++pActwk->actfree[3]; /* Line 1709, Address: 0x101eebc */
  }


  ++pActwk->actfree[0]; /* Line 1713, Address: 0x101eecc */
  bom_set(pActwk); /* Line 1714, Address: 0x101eedc */

  if ((unsigned short)pActwk->actfree[0] % 60 == 0) { /* Line 1716, Address: 0x101eee8 */
    make_hibana(pActwk); /* Line 1717, Address: 0x101ef0c */
  }


  pActwk->yposi.w.h -= ((short*)pActwk)[27]; /* Line 1721, Address: 0x101ef18 */
  pActwk->yposi.l += 16384; /* Line 1722, Address: 0x101ef30 */

  dirwk = pActwk->actfree[1]; /* Line 1724, Address: 0x101ef40 */
  pActwk->actfree[1] += 3; /* Line 1725, Address: 0x101ef4c */
  sinset(dirwk, &sinwk, &coswk); /* Line 1726, Address: 0x101ef5c */

  sinwk = sinwk * 4 >> 8; /* Line 1728, Address: 0x101ef70 */
  ((short*)pActwk)[27] = sinwk; /* Line 1729, Address: 0x101ef90 */
  pActwk->yposi.w.h += sinwk; /* Line 1730, Address: 0x101ef9c */

  pActwk->xposi.l += ((int*)pActwk)[14]; /* Line 1732, Address: 0x101efb0 */

  if (pActwk->xposi.w.h >= 4064) { /* Line 1734, Address: 0x101efc8 */

    colorset2(11); /* Line 1736, Address: 0x101efe4 */

    pActwk->r_no0 = 54; /* Line 1738, Address: 0x101eff0 */
    pActwk->actfree[0] = 0; /* Line 1739, Address: 0x101effc */
    bossstart = 0; /* Line 1740, Address: 0x101f004 */
  }
} /* Line 1742, Address: 0x101f00c */






static void egg8_esc2(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 1749, Address: 0x101f020 */
  ++pActwk->actfree[0]; /* Line 1750, Address: 0x101f02c */
  bom_set(pActwk); /* Line 1751, Address: 0x101f03c */
} /* Line 1752, Address: 0x101f048 */






static void egg8_warai_chk(sprite_status* pActwk) { /* Line 1759, Address: 0x101f060 */
  if (!pActwk->mstno.b.h) { /* Line 1760, Address: 0x101f068 */
    if (((short*)&actwk[0])[26] || actwk[0].r_no0 == 6) { /* Line 1761, Address: 0x101f078 */


      pActwk->actfree[18] = 120; /* Line 1764, Address: 0x101f0a0 */
      pActwk->mstno.b.h = 4; /* Line 1765, Address: 0x101f0ac */
    }
  }


} /* Line 1770, Address: 0x101f0b8 */















static void egg8_colichk(sprite_status* pActwk, sprite_status* pPlayerwk, sprite_status* pMecawk) { /* Line 1786, Address: 0x101f0d0 */
  unsigned char hane_patno;

  if (!(pActwk->actfree[2] & 8)) return; /* Line 1789, Address: 0x101f0e8 */



  pMecawk->actfree[17] = 255; /* Line 1793, Address: 0x101f100 */

  if (pMecawk->actfree[18]) { /* Line 1795, Address: 0x101f10c */

    if (--pMecawk->actfree[18] != 0) return; /* Line 1797, Address: 0x101f11c */


  } else if (!pActwk->colino || !pMecawk->colino) { /* Line 1800, Address: 0x101f13c */

    if (pActwk->r_no0 != 30) { /* Line 1802, Address: 0x101f164 */
      pActwk->colino = 0; /* Line 1803, Address: 0x101f17c */
      pActwk->colicnt = 0; /* Line 1804, Address: 0x101f184 */
      pMecawk->colino = 0; /* Line 1805, Address: 0x101f18c */
      pMecawk->colicnt = 0; /* Line 1806, Address: 0x101f194 */

      make_hibana(pActwk); /* Line 1808, Address: 0x101f19c */
      pActwk->actfree[18] = 150; /* Line 1809, Address: 0x101f1a8 */
      pActwk->mstno.b.h = 1; /* Line 1810, Address: 0x101f1b4 */

      pMecawk->actfree[18] = 120; /* Line 1812, Address: 0x101f1c0 */
      pActwk->actfree[17] = 0; /* Line 1813, Address: 0x101f1cc */
      pActwk->actfree[3] = 0; /* Line 1814, Address: 0x101f1d4 */
      pActwk->actfree[2] |= 1; /* Line 1815, Address: 0x101f1dc */

      soundset(172); /* Line 1817, Address: 0x101f1ec */


      --pActwk->actfree[16]; /* Line 1820, Address: 0x101f1f8 */
      egg8_spd_set(pActwk, pMecawk); /* Line 1821, Address: 0x101f208 */

      hane_patno = pMecawk->actfree[11]; /* Line 1823, Address: 0x101f218 */
      switch (pActwk->actfree[16]) { /* Line 1824, Address: 0x101f224 */

        case 0:
          pActwk->r_no0 = 50; /* Line 1827, Address: 0x101f264 */
          pActwk->actfree[2] &= 254; /* Line 1828, Address: 0x101f270 */
          pActwk->actfree[0] = 0; /* Line 1829, Address: 0x101f280 */
          pActwk->actfree[1] = 0; /* Line 1830, Address: 0x101f288 */


          pMecawk->actfree[17] = 0; /* Line 1833, Address: 0x101f290 */
          break; /* Line 1834, Address: 0x101f298 */

        case 3:
          if (pPlayerwk->xposi.w.h < pActwk->xposi.w.h) { /* Line 1837, Address: 0x101f2a0 */

            if (hane_patno < 4) { /* Line 1839, Address: 0x101f2cc */

              pMecawk->actfree[17] = 2; /* Line 1841, Address: 0x101f2dc */
            } else if (hane_patno < 8) { /* Line 1842, Address: 0x101f2e8 */

              pMecawk->actfree[17] = 1; /* Line 1844, Address: 0x101f300 */
            } else if (hane_patno < 12) { /* Line 1845, Address: 0x101f30c */

              pMecawk->actfree[17] = 0; /* Line 1847, Address: 0x101f324 */
            } else { /* Line 1848, Address: 0x101f32c */

              pMecawk->actfree[17] = 3; /* Line 1850, Address: 0x101f334 */
            }
          } /* Line 1852, Address: 0x101f340 */
          else {
            if (hane_patno >= 13 || hane_patno == 0) { /* Line 1854, Address: 0x101f348 */

              pMecawk->actfree[17] = 2; /* Line 1856, Address: 0x101f364 */
            } else if (hane_patno < 5) { /* Line 1857, Address: 0x101f370 */

              pMecawk->actfree[17] = 1; /* Line 1859, Address: 0x101f388 */
            } else if (hane_patno < 9) { /* Line 1860, Address: 0x101f394 */

              pMecawk->actfree[17] = 0; /* Line 1862, Address: 0x101f3ac */
            } else { /* Line 1863, Address: 0x101f3b4 */

              pMecawk->actfree[17] = 3; /* Line 1865, Address: 0x101f3bc */
            }
          }

          break; /* Line 1869, Address: 0x101f3c8 */

        case 2:
          if (pPlayerwk->xposi.w.h < pActwk->xposi.w.h) { /* Line 1872, Address: 0x101f3d0 */

            if (hane_patno >= 13 || hane_patno < 3) { /* Line 1874, Address: 0x101f3fc */

              pMecawk->actfree[17] = 2; /* Line 1876, Address: 0x101f41c */
            } else if (hane_patno < 8) { /* Line 1877, Address: 0x101f428 */

              pMecawk->actfree[17] = 1; /* Line 1879, Address: 0x101f440 */
            } else { /* Line 1880, Address: 0x101f44c */

              pMecawk->actfree[17] = 0; /* Line 1882, Address: 0x101f454 */
            }
          } /* Line 1884, Address: 0x101f45c */
          else {
            if (hane_patno >= 12 || hane_patno == 0) { /* Line 1886, Address: 0x101f464 */

              pMecawk->actfree[17] = 2; /* Line 1888, Address: 0x101f480 */
            } else if (hane_patno < 5) { /* Line 1889, Address: 0x101f48c */

              pMecawk->actfree[17] = 1; /* Line 1891, Address: 0x101f4a4 */
            } else { /* Line 1892, Address: 0x101f4b0 */

              pMecawk->actfree[17] = 0; /* Line 1894, Address: 0x101f4b8 */
            }
          }

          break; /* Line 1898, Address: 0x101f4c0 */




        case 1:
          if (pPlayerwk->xposi.w.h >= pActwk->xposi.w.h) { /* Line 1904, Address: 0x101f4c8 */

            pMecawk->actfree[17] = 0; /* Line 1906, Address: 0x101f4f4 */
          } /* Line 1907, Address: 0x101f4fc */
          else {
            pMecawk->actfree[17] = 1; /* Line 1909, Address: 0x101f504 */
          }

          break; /* Line 1912, Address: 0x101f510 */

        default:
          pActwk->actfree[16] = 0; /* Line 1915, Address: 0x101f518 */
          break;
      }

      return; /* Line 1919, Address: 0x101f520 */
    }
  }


  pActwk->colino = 50; /* Line 1924, Address: 0x101f528 */
  pActwk->colicnt = 2; /* Line 1925, Address: 0x101f534 */
  pMecawk->colino = 51; /* Line 1926, Address: 0x101f540 */
  pMecawk->colicnt = 2; /* Line 1927, Address: 0x101f54c */
} /* Line 1928, Address: 0x101f558 */













































































































































































































































































































static egg8act egg8acttbl1[13] = {
  { 18, 0, 316 },
  { 20, 0,   0 },
  { 16, 0,   2 },
  { 30, 0,   0 },
  { 32, 0,   0 },
  {  6, 0, 120 },
  { 20, 0,   0 },
  { 16, 0,   2 },
  { 44, 0,   0 },
  { 46, 0,   0 },
  { 48, 0,   0 },
  { 20, 0,   0 },
  {  0, 0,   0 }
};
static egg8act egg8acttbl2[23] = {
  { 18, 0, 316 },
  { 20, 0,   0 },
  { 16, 0,   2 },
  { 22, 0,   0 },
  { 24, 0,   0 },
  {  6, 0,  60 },
  { 20, 0,   0 },
  { 30, 0,   0 },
  { 32, 0,   0 },
  {  6, 0, 120 },
  { 20, 0,   0 },
  { 38, 0,   0 },
  { 26, 0,   0 },
  {  6, 0,  60 },
  { 28, 0,   0 },
  { 40, 0,   0 },
  { 20, 0,   0 },
  { 38, 0,   0 },
  { 26, 0,   0 },
  {  6, 0,  60 },
  { 28, 0,   0 },
  { 40, 0,   0 },
  {  0, 0,   0 }
};
static egg8act egg8acttbl3[29] = {
  { 18, 0, 316 },
  { 20, 0,   0 },
  { 16, 0,   2 },
  { 42, 0,   0 },
  { 34, 0,   0 },
  { 20, 0,   0 },
  { 14, 0, 348 },
  {  6, 0, 120 },
  { 16, 0,   2 },
  { 22, 0,   0 },
  { 24, 0,   0 },
  {  6, 0,  40 },
  { 20, 0,   0 },
  { 30, 0,   0 },
  { 32, 0,   0 },
  {  6, 0, 120 },
  { 20, 0,   0 },
  { 38, 0,   0 },
  { 26, 0,   0 },
  {  6, 0,  90 },
  { 28, 0,   0 },
  { 40, 0,   0 },
  { 20, 0,   0 },
  { 38, 0,   0 },
  { 26, 0,   0 },
  {  6, 0,  90 },
  { 28, 0,   0 },
  { 40, 0,   0 },
  {  0, 0,   0 }
};
static egg8act egg8acttbl4[29] = {
  { 18, 0, 316 },
  { 20, 0,   0 },
  { 16, 0,   2 },
  { 42, 0,   0 },
  { 34, 0,   0 },
  { 20, 0,   0 },
  { 14, 0, 348 },
  {  6, 0, 120 },
  { 16, 0,   2 },
  { 22, 0,   0 },
  { 24, 0,   0 },
  {  6, 0,  40 },
  { 20, 0,   0 },
  { 30, 0,   0 },
  { 32, 0,   0 },
  {  6, 0, 120 },
  { 20, 0,   0 },
  { 38, 0,   0 },
  { 26, 0,   0 },
  {  6, 0, 120 },
  { 28, 0,   0 },
  { 40, 0,   0 },
  { 20, 0,   0 },
  { 38, 0,   0 },
  { 26, 0,   0 },
  {  6, 0, 120 },
  { 28, 0,   0 },
  { 40, 0,   0 },
  {  0, 0,   0 }
};
static egg8act* egg8acttbl[5] = {
  0,
  egg8acttbl1,
  egg8acttbl2,
  egg8acttbl3,
  egg8acttbl4
};

static void next_action(sprite_status* pActwk) { /* Line 2340, Address: 0x101f570 */
  egg8act* pEggactTbl;
  unsigned char tblno, tblidx;

  do {
    tblno = pActwk->actfree[16]; /* Line 2345, Address: 0x101f584 */
    tblidx = pActwk->actfree[17]; /* Line 2346, Address: 0x101f590 */
    pEggactTbl = &egg8acttbl[tblno][tblidx]; /* Line 2347, Address: 0x101f59c */

    if (!pEggactTbl->r_no) { /* Line 2349, Address: 0x101f5c0 */
      pActwk->actfree[17] = 0; /* Line 2350, Address: 0x101f5cc */
    }
  } while (!pEggactTbl->r_no); /* Line 2352, Address: 0x101f5d4 */


  ++pActwk->actfree[17]; /* Line 2355, Address: 0x101f5e0 */
  pActwk->r_no0 = pEggactTbl->r_no; /* Line 2356, Address: 0x101f5f0 */
  ((short*)pActwk)[30] = pEggactTbl->param; /* Line 2357, Address: 0x101f5fc */
  pActwk->actfree[3] = 0; /* Line 2358, Address: 0x101f608 */
} /* Line 2359, Address: 0x101f610 */


























static sprite_pattern meca_pat0 = { 1, { { -36, -60, 0, 452 } } };
static sprite_pattern meca_pat1 = { 1, { { -36, -60, 0, 453 } } };
static sprite_pattern meca_pat2 = { 1, { { -36, -60, 0, 454 } } };
static sprite_pattern meca_pat3 = { 1, { { -36, -36, 0, 455 } } };
sprite_pattern* egg8meca_pat[4] = {
  &meca_pat0,
  &meca_pat1,
  &meca_pat2,
  &meca_pat3
};
static void(*meca_act_tbl[10])(sprite_status*, sprite_status*) = {
  &egg8meca_ini,
  &egg8meca_normal,
  &egg8meca_chg1,
  &egg8meca_chg2,
  &egg8meca_chg3,
  &egg8meca_fire,
  &egg8meca_hane_reset,
  &egg8meca_spin,
  &egg8meca_dead,
  &egg8meca_tobi
};

void egg8meca(sprite_status* pActwk) { /* Line 2409, Address: 0x101f630 */
  sprite_status* pEggwk;

  pEggwk = &actwk[((short*)pActwk)[25]]; /* Line 2412, Address: 0x101f640 */

  meca_act_tbl[pActwk->r_no0 / 2](pActwk, pEggwk); /* Line 2414, Address: 0x101f668 */


  if (!(pActwk->actfree[18] / 2 & 1)) { /* Line 2417, Address: 0x101f6b0 */
    actionsub(pActwk); /* Line 2418, Address: 0x101f6e0 */
  }
} /* Line 2420, Address: 0x101f6ec */






static void egg8meca_ini(sprite_status* pActwk, sprite_status* pEggwk) { /* Line 2427, Address: 0x101f700 */
  pActwk->r_no0 = 2; /* Line 2428, Address: 0x101f70c */
  pActwk->actflg = 4; /* Line 2429, Address: 0x101f718 */
  pActwk->sprpri = 5; /* Line 2430, Address: 0x101f724 */
  pActwk->sprhsize = 36; /* Line 2431, Address: 0x101f730 */
  pActwk->sprvsize = 36; /* Line 2432, Address: 0x101f73c */
  pActwk->sproffset = 9182; /* Line 2433, Address: 0x101f748 */
  pActwk->patbase = egg8meca_pat; /* Line 2434, Address: 0x101f754 */
  ((short*)pActwk)[30] = 0; /* Line 2435, Address: 0x101f764 */
  pActwk->actfree[17] = 255; /* Line 2436, Address: 0x101f76c */
  make_hane(pActwk); /* Line 2437, Address: 0x101f778 */
  pActwk->actfree[16] |= 160; /* Line 2438, Address: 0x101f784 */
  pActwk->actfree[16] &= 191; /* Line 2439, Address: 0x101f794 */
} /* Line 2440, Address: 0x101f7a4 */






static void egg8meca_normal(sprite_status* pActwk, sprite_status* pEggwk) { /* Line 2447, Address: 0x101f7c0 */
  pActwk->xposi.w.h = pEggwk->xposi.w.h; /* Line 2448, Address: 0x101f7d0 */
  pActwk->yposi.w.h = pEggwk->yposi.w.h; /* Line 2449, Address: 0x101f7e0 */
  hane_ctrl(pActwk); /* Line 2450, Address: 0x101f7f0 */
} /* Line 2451, Address: 0x101f7fc */






static void egg8meca_spin(sprite_status* pActwk, sprite_status* pEggwk) { /* Line 2458, Address: 0x101f810 */
  pActwk->xposi.w.h = pEggwk->xposi.w.h; /* Line 2459, Address: 0x101f820 */
  pActwk->yposi.w.h = pEggwk->yposi.w.h; /* Line 2460, Address: 0x101f830 */
  futa_roll(pActwk); /* Line 2461, Address: 0x101f840 */
} /* Line 2462, Address: 0x101f84c */






static void egg8meca_chg1(sprite_status* pActwk, sprite_status* pEggwk) { /* Line 2469, Address: 0x101f860 */
  switch (pActwk->actfree[3]) { /* Line 2470, Address: 0x101f868 */

    case 0:
      pActwk->actfree[10] = 1; /* Line 2473, Address: 0x101f890 */
      ((short*)pActwk)[30] = 0; /* Line 2474, Address: 0x101f89c */
      pActwk->actfree[3] = 1; /* Line 2475, Address: 0x101f8a4 */

    case 1:
      if (((short*)pActwk)[30] <= 170) break; /* Line 2478, Address: 0x101f8b0 */



    default:
      ++pActwk->actfree[3]; /* Line 2483, Address: 0x101f8cc */

      if (pActwk->actfree[3] == 2) { /* Line 2485, Address: 0x101f8dc */

        pActwk->actfree[10] = 3; /* Line 2487, Address: 0x101f8f4 */
      } else if (pActwk->actfree[3] == 6) { /* Line 2488, Address: 0x101f900 */

        pActwk->actfree[10] = 4; /* Line 2490, Address: 0x101f920 */
      }
      break;
  }



  if ((((short*)pActwk)[30] += 8) >= 256) { /* Line 2497, Address: 0x101f92c */

    ((short*)pActwk)[30] = 256; /* Line 2499, Address: 0x101f958 */
    pActwk->actfree[3] = 0; /* Line 2500, Address: 0x101f964 */
    pActwk->r_no0 = 2; /* Line 2501, Address: 0x101f96c */
    pActwk->actfree[10] = 4; /* Line 2502, Address: 0x101f978 */
  }
} /* Line 2504, Address: 0x101f984 */






static void egg8meca_chg2(sprite_status* pActwk, sprite_status* pEggwk) { /* Line 2511, Address: 0x101f990 */
  if (!pActwk->actfree[3]) { /* Line 2512, Address: 0x101f998 */

    pActwk->actfree[10] = 1; /* Line 2514, Address: 0x101f9a8 */
    ++pActwk->actfree[3]; /* Line 2515, Address: 0x101f9b4 */
  }


  if ((((short*)pActwk)[30] += 16) >= 236) { /* Line 2519, Address: 0x101f9c4 */
    pActwk->actfree[10] = 2; /* Line 2520, Address: 0x101f9f0 */
  }


  if (((short*)pActwk)[30] >= 256) { /* Line 2524, Address: 0x101f9fc */

    ((short*)pActwk)[30] = 256; /* Line 2526, Address: 0x101fa18 */
    pActwk->actfree[3] = 0; /* Line 2527, Address: 0x101fa24 */
    pActwk->r_no0 = 2; /* Line 2528, Address: 0x101fa2c */
  }
} /* Line 2530, Address: 0x101fa38 */






static void egg8meca_chg3(sprite_status* pActwk, sprite_status* pEggwk) { /* Line 2537, Address: 0x101fa50 */
  pActwk->xposi.w.h = pEggwk->xposi.w.h; /* Line 2538, Address: 0x101fa5c */
  pActwk->yposi.w.h = pEggwk->yposi.w.h; /* Line 2539, Address: 0x101fa6c */

  if (!pActwk->actfree[3]) { /* Line 2541, Address: 0x101fa7c */

    pActwk->actfree[10] = 2; /* Line 2543, Address: 0x101fa8c */
    ++pActwk->actfree[3]; /* Line 2544, Address: 0x101fa98 */
  }


  if ((((short*)pActwk)[30] -= 6) < 236) { /* Line 2548, Address: 0x101faa8 */
    pActwk->actfree[10] = 1; /* Line 2549, Address: 0x101fad4 */
  }


  if (((short*)pActwk)[30] <= 0) { /* Line 2553, Address: 0x101fae0 */

    ((short*)pActwk)[30] = 0; /* Line 2555, Address: 0x101faf8 */
    pActwk->actfree[3] = 0; /* Line 2556, Address: 0x101fb00 */
    pActwk->r_no0 = 2; /* Line 2557, Address: 0x101fb08 */
    pActwk->actfree[10] = 0; /* Line 2558, Address: 0x101fb14 */
  }
} /* Line 2560, Address: 0x101fb1c */






static void egg8meca_fire(sprite_status* pActwk, sprite_status* pEggwk) { /* Line 2567, Address: 0x101fb30 */
  pActwk->xposi.w.h = pEggwk->xposi.w.h; /* Line 2568, Address: 0x101fb40 */
  pActwk->yposi.w.h = pEggwk->yposi.w.h; /* Line 2569, Address: 0x101fb50 */

  if (pEggwk->actfree[16] == pActwk->actfree[19]) { /* Line 2571, Address: 0x101fb60 */

    pActwk->actfree[21] = (actwk[0].xposi.w.h + (short)actwk[0].pattim & 3) * 8; /* Line 2573, Address: 0x101fb80 */

    pActwk->r_no0 = 2; /* Line 2575, Address: 0x101fbbc */
    pActwk->actfree[2] |= 16; /* Line 2576, Address: 0x101fbc8 */
  } else { /* Line 2577, Address: 0x101fbd8 */
    hane_roll(pActwk); /* Line 2578, Address: 0x101fbe0 */
  }
} /* Line 2580, Address: 0x101fbec */






static void egg8meca_hane_reset(sprite_status* pActwk, sprite_status* pEggwk) { /* Line 2587, Address: 0x101fc00 */
  pActwk->xposi.w.h = pEggwk->xposi.w.h; /* Line 2588, Address: 0x101fc0c */
  pActwk->yposi.w.h = pEggwk->yposi.w.h; /* Line 2589, Address: 0x101fc1c */

  if (pActwk->actfree[3] != 1) { /* Line 2591, Address: 0x101fc2c */

    pActwk->actfree[2] |= 8; /* Line 2593, Address: 0x101fc44 */
    ++pActwk->actfree[3]; /* Line 2594, Address: 0x101fc54 */
    ((short*)pActwk)[30] = -256; /* Line 2595, Address: 0x101fc64 */
    pActwk->actfree[16] |= 160; /* Line 2596, Address: 0x101fc70 */
    pActwk->actfree[16] &= 191; /* Line 2597, Address: 0x101fc80 */
  }


  if ((((short*)pActwk)[30] += 6) >= 0) { /* Line 2601, Address: 0x101fc90 */

    pActwk->actfree[2] &= 247; /* Line 2603, Address: 0x101fcb8 */
    ((short*)pActwk)[30] = 0; /* Line 2604, Address: 0x101fcc8 */
    pActwk->actfree[0] = 0; /* Line 2605, Address: 0x101fcd0 */
    pActwk->actfree[3] = 0; /* Line 2606, Address: 0x101fcd8 */
    pActwk->r_no0 = 2; /* Line 2607, Address: 0x101fce0 */
  }
} /* Line 2609, Address: 0x101fcec */






static void egg8meca_dead(sprite_status* pActwk, sprite_status* pEggwk) { /* Line 2616, Address: 0x101fd00 */
  pActwk->xposi.w.h = pEggwk->xposi.w.h; /* Line 2617, Address: 0x101fd0c */
  pActwk->yposi.w.h = pEggwk->yposi.w.h; /* Line 2618, Address: 0x101fd1c */
} /* Line 2619, Address: 0x101fd2c */






static void egg8meca_tobi(sprite_status* pActwk, sprite_status* pEggwk) { /* Line 2626, Address: 0x101fd40 */
  short wk;

  pActwk->xposi.w.h = pEggwk->xposi.w.h; /* Line 2629, Address: 0x101fd50 */
  pActwk->yposi.w.h = pEggwk->yposi.w.h; /* Line 2630, Address: 0x101fd60 */

  if ((wk = 416 - pEggwk->yposi.w.h) > 36) { /* Line 2632, Address: 0x101fd70 */
    wk = 36; /* Line 2633, Address: 0x101fdb4 */
  }


  ((short*)pActwk)[30] = (wk << 8) / 36; /* Line 2637, Address: 0x101fdc0 */
} /* Line 2638, Address: 0x101fdf4 */













static void hane_ctrl(sprite_status* pActwk) { /* Line 2652, Address: 0x101fe10 */
  unsigned char FlagWk;

  FlagWk = pActwk->actfree[2]; /* Line 2655, Address: 0x101fe20 */
  pActwk->actfree[2] &= 239; /* Line 2656, Address: 0x101fe2c */

  if (!(FlagWk & 16)) { /* Line 2658, Address: 0x101fe3c */
    if (!(pActwk->actfree[16] & 64)) { /* Line 2659, Address: 0x101fe4c */
      hane_stop(pActwk); /* Line 2660, Address: 0x101fe64 */
    } else { /* Line 2661, Address: 0x101fe70 */
      hane_roll(pActwk); /* Line 2662, Address: 0x101fe78 */
    }
  } /* Line 2664, Address: 0x101fe84 */
  else {
    pActwk->actfree[1] = 0; /* Line 2666, Address: 0x101fe8c */
    pActwk->actfree[16] &= 95; /* Line 2667, Address: 0x101fe94 */

    if (!(pActwk->actfree[16] & 64)) { /* Line 2669, Address: 0x101fea4 */
      pActwk->actfree[16] ^= 64; /* Line 2670, Address: 0x101febc */
      hane_roll(pActwk); /* Line 2671, Address: 0x101fecc */
    } else { /* Line 2672, Address: 0x101fed8 */
      pActwk->actfree[16] ^= 64; /* Line 2673, Address: 0x101fee0 */
      hane_stop(pActwk); /* Line 2674, Address: 0x101fef0 */
    }
  }

} /* Line 2678, Address: 0x101fefc */





static void hane_stop(sprite_status* pActwk) { /* Line 2684, Address: 0x101ff10 */
  if (!(pActwk->actfree[16] & 128)) { /* Line 2685, Address: 0x101ff18 */
    if (pActwk->actfree[16] & 32) { /* Line 2686, Address: 0x101ff30 */

      if (pActwk->actfree[11] != pActwk->actfree[12]) goto label1; /* Line 2688, Address: 0x101ff48 */

      pActwk->actfree[16] |= 128; /* Line 2690, Address: 0x101ff68 */
      pActwk->patno = 0; /* Line 2691, Address: 0x101ff78 */
      return; /* Line 2692, Address: 0x101ff80 */
    }


    pActwk->patno = 1; /* Line 2696, Address: 0x101ff88 */

    if (++pActwk->actfree[1] == 10) { /* Line 2698, Address: 0x101ff94 */
      pActwk->actfree[16] |= 32; /* Line 2699, Address: 0x101ffb8 */
      pActwk->actfree[1] = 0; /* Line 2700, Address: 0x101ffc8 */
    }


label1:
    if (++pActwk->actfree[0] >= pActwk->actfree[13]) { /* Line 2705, Address: 0x101ffd0 */
      pActwk->actfree[0] = 0; /* Line 2706, Address: 0x1020000 */
      pActwk->actfree[2] |= 64; /* Line 2707, Address: 0x1020008 */
    }
  }




} /* Line 2714, Address: 0x1020018 */





static void hane_roll(sprite_status* pActwk) { /* Line 2720, Address: 0x1020030 */
  if (!(pActwk->actfree[16] & 32)) { /* Line 2721, Address: 0x102003c */

    pActwk->patno = 1; /* Line 2723, Address: 0x1020054 */

    if (++pActwk->actfree[1] != 10) return; /* Line 2725, Address: 0x1020060 */




    pActwk->actfree[1] = 0; /* Line 2730, Address: 0x1020084 */
    pActwk->actfree[16] |= 32; /* Line 2731, Address: 0x102008c */
  }


  futa_roll(pActwk); /* Line 2735, Address: 0x102009c */


  if (++pActwk->actfree[0] >= pActwk->actfree[13]) { /* Line 2738, Address: 0x10200a8 */
    pActwk->actfree[0] = 0; /* Line 2739, Address: 0x10200d8 */
    pActwk->actfree[2] |= 64; /* Line 2740, Address: 0x10200e0 */
  }
} /* Line 2742, Address: 0x10200f0 */





static void futa_roll(sprite_status* pActwk) { /* Line 2748, Address: 0x1020100 */
  ++pActwk->actfree[1]; /* Line 2749, Address: 0x1020108 */

  if (pActwk->actfree[1] == 6) { /* Line 2751, Address: 0x1020118 */

    pActwk->patno = 2; /* Line 2753, Address: 0x1020130 */
  } else if (pActwk->actfree[1] == 12) { /* Line 2754, Address: 0x102013c */

    pActwk->actfree[1] = 0; /* Line 2756, Address: 0x102015c */
    pActwk->patno = 1; /* Line 2757, Address: 0x1020164 */
  }


} /* Line 2761, Address: 0x1020170 */





























































































































static sprite_pattern hane0_1_pat00 = { 1, { { -24, -24, 0, 456 } } };
static sprite_pattern hane0_1_pat01 = { 2, { { -30, -34, 0, 457 }, { -30, -2, 0, 458 } } };
static sprite_pattern hane0_1_pat02 = { 2, { { -32, -32, 0, 459 }, { -32, 0, 0, 460 } } };
static sprite_pattern hane0_1_pat03 = { 2, { { -32, -36, 0, 461 }, { -16, -4, 0, 462 } } };
static sprite_pattern hane0_1_pat04 = { 1, { { -16, -24, 0, 463 } } };
sprite_pattern* egg8hane0_pat1[16] = {
  &hane0_1_pat00,
  &hane0_1_pat01,
  &hane0_1_pat02,
  &hane0_1_pat03,
  &hane0_1_pat04,
  &hane0_1_pat03,
  &hane0_1_pat02,
  &hane0_1_pat01,
  &hane0_1_pat00,
  &hane0_1_pat01,
  &hane0_1_pat02,
  &hane0_1_pat03,
  &hane0_1_pat04,
  &hane0_1_pat03,
  &hane0_1_pat02,
  &hane0_1_pat01
};
static sprite_pattern hane0_2_pat00 = { 1, { { -24, -24, 0, 464 } } };
static sprite_pattern hane0_2_pat01 = { 1, { { -30, -34, 0, 465 } } };
static sprite_pattern hane0_2_pat02 = { 1, { { -32, -32, 0, 466 } } };
static sprite_pattern hane0_2_pat03 = { 1, { { -40, -36, 0, 467 } } };
static sprite_pattern hane0_2_pat04 = { 1, { { -40, -24, 0, 468 } } };
sprite_pattern* egg8hane0_pat2[16] = {
  &hane0_2_pat00,
  &hane0_2_pat01,
  &hane0_2_pat02,
  &hane0_2_pat03,
  &hane0_2_pat04,
  &hane0_2_pat03,
  &hane0_2_pat02,
  &hane0_2_pat01,
  &hane0_2_pat00,
  &hane0_2_pat01,
  &hane0_2_pat02,
  &hane0_2_pat03,
  &hane0_2_pat04,
  &hane0_2_pat03,
  &hane0_2_pat02,
  &hane0_2_pat01
};
static sprite_pattern hane0_3_pat00 = { 2, { { -8, 32, 0, 470 }, { -24, -24, 0, 469 } } };
static sprite_pattern hane0_3_pat01 = { 2, { { -26, 28, 0, 470 }, { -30, -34, 0, 471 } } };
static sprite_pattern hane0_3_pat02 = { 2, { { -39, 24, 0, 470 }, { -32, -32, 0, 472 } } };
static sprite_pattern hane0_3_pat03 = { 2, { { -46, 8, 0, 470 }, { -40, -36, 0, 473 } } };
static sprite_pattern hane0_3_pat04 = { 2, { { -48, -8, 0, 470 }, { -40, -24, 0, 474 } } };
sprite_pattern* egg8hane0_pat3[16] = {
  &hane0_3_pat00,
  &hane0_3_pat01,
  &hane0_3_pat02,
  &hane0_3_pat03,
  &hane0_3_pat04,
  &hane0_3_pat03,
  &hane0_3_pat02,
  &hane0_3_pat01,
  &hane0_3_pat00,
  &hane0_3_pat01,
  &hane0_3_pat02,
  &hane0_3_pat03,
  &hane0_3_pat04,
  &hane0_3_pat03,
  &hane0_3_pat02,
  &hane0_3_pat01
};
static sprite_pattern hane1_pat00 = { 1, { { -16, -32, 0, 475 } } };
static sprite_pattern hane1_pat01 = { 1, { { -32, -16, 0, 476 } } };
sprite_pattern* egg8hane1_pat[16] = {
  &hane1_pat00,
  0,
  0,
  0,
  &hane1_pat01,
  0,
  0,
  0,
  &hane1_pat00,
  0,
  0,
  0,
  &hane1_pat01,
  0,
  0,
  0
};
static sprite_pattern hane2_1_pat00 = { 1, { { -8, -32, 0, 477 } } };
static sprite_pattern hane2_1_pat01 = { 1, { { -20, -32, 0, 478 } } };
static sprite_pattern hane2_1_pat02 = { 1, { { -30, -28, 0, 479 } } };
static sprite_pattern hane2_1_pat03 = { 1, { { -37, -24, 0, 480 } } };
static sprite_pattern hane2_1_pat04 = { 1, { { -40, -8, 0, 481 } } };
sprite_pattern* egg8hane2_pat1[16] = {
  &hane2_1_pat00,
  &hane2_1_pat01,
  &hane2_1_pat02,
  &hane2_1_pat03,
  &hane2_1_pat04,
  &hane2_1_pat03,
  &hane2_1_pat02,
  &hane2_1_pat01,
  &hane2_1_pat00,
  &hane2_1_pat01,
  &hane2_1_pat02,
  &hane2_1_pat03,
  &hane2_1_pat04,
  &hane2_1_pat03,
  &hane2_1_pat02,
  &hane2_1_pat01
};
static sprite_pattern hane2_2_pat00 = { 1, { { -8, -32, 0, 482 } } };
static sprite_pattern hane2_2_pat01 = { 1, { { -16, -32, 0, 483 } } };
static sprite_pattern hane2_2_pat02 = { 1, { { -28, -28, 0, 484 } } };
static sprite_pattern hane2_2_pat03 = { 1, { { -32, -24, 0, 485 } } };
static sprite_pattern hane2_2_pat04 = { 1, { { -32, -8, 0, 486 } } };
sprite_pattern* egg8hane2_pat2[16] = {
  &hane2_2_pat00,
  &hane2_2_pat01,
  &hane2_2_pat02,
  &hane2_2_pat03,
  &hane2_2_pat04,
  &hane2_2_pat03,
  &hane2_2_pat02,
  &hane2_2_pat01,
  &hane2_2_pat00,
  &hane2_2_pat01,
  &hane2_2_pat02,
  &hane2_2_pat03,
  &hane2_2_pat04,
  &hane2_2_pat03,
  &hane2_2_pat02,
  &hane2_2_pat01
};
static sprite_pattern** hane_base_tbl[6] = {
  egg8hane0_pat1,
  egg8hane0_pat2,
  egg8hane0_pat3,
  egg8hane1_pat,
  egg8hane2_pat1,
  egg8hane2_pat2
};
static int(*hane_act_tbl[6])(sprite_status*, sprite_status*, sprite_status*) = {
  &egg8hane_ini,
  &egg8hane_demo,
  &egg8hane_normal,
  &egg8hane_fire1,
  &egg8hane_wait,
  &egg8hane_kill
};

void egg8hane(sprite_status* pActwk) { /* Line 3039, Address: 0x1020180 */
  sprite_status *pMecawk, *pEggwk;
  int ret;

  pMecawk = &actwk[((short*)pActwk)[25]]; /* Line 3043, Address: 0x1020198 */
  pEggwk = &actwk[((short*)pMecawk)[25]]; /* Line 3044, Address: 0x10201c0 */

  if (!(pMecawk->actfree[17] & 128)) { /* Line 3046, Address: 0x10201e4 */
    hane_no_reset(pActwk, pMecawk, pEggwk); /* Line 3047, Address: 0x10201f8 */
  }




  while ((ret = hane_act_tbl[pActwk->r_no0 / 2](pActwk, pMecawk, pEggwk)) < 0); /* Line 3053, Address: 0x102020c */

  if (ret == 0) return; /* Line 3055, Address: 0x1020264 */



  if (pActwk->patno < 4) { /* Line 3059, Address: 0x102026c */

    pActwk->actflg &= 252; /* Line 3061, Address: 0x1020284 */
  } else if (pActwk->patno < 8) { /* Line 3062, Address: 0x1020294 */

    pActwk->actflg |= 2; /* Line 3064, Address: 0x10202b4 */
    pActwk->actflg &= 254; /* Line 3065, Address: 0x10202c4 */
  } else if (pActwk->patno < 12) { /* Line 3066, Address: 0x10202d4 */

    pActwk->actflg |= 3; /* Line 3068, Address: 0x10202f4 */
  } else { /* Line 3069, Address: 0x1020304 */

    pActwk->actflg &= 253; /* Line 3071, Address: 0x102030c */
    pActwk->actflg |= 1; /* Line 3072, Address: 0x102031c */
  }


  actionsub(pActwk); /* Line 3076, Address: 0x102032c */
} /* Line 3077, Address: 0x1020338 */






static int egg8hane_ini(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk) { /* Line 3084, Address: 0x1020360 */
  pActwk->r_no0 = 2; /* Line 3085, Address: 0x1020374 */
  pActwk->actflg = 4; /* Line 3086, Address: 0x1020380 */
  pActwk->sprpri = 5; /* Line 3087, Address: 0x102038c */
  pActwk->sprhsize = 32; /* Line 3088, Address: 0x1020398 */
  pActwk->sprvsize = 32; /* Line 3089, Address: 0x10203a4 */
  pActwk->sproffset = 8736; /* Line 3090, Address: 0x10203b0 */
  pActwk->patbase = egg8hane0_pat1; /* Line 3091, Address: 0x10203bc */

  if (egg8hane_normal(pActwk, pMecawk, pEggwk) < 0) { /* Line 3093, Address: 0x10203cc */
    return -1; /* Line 3094, Address: 0x10203e8 */
  }

  pActwk->colino = 0; /* Line 3097, Address: 0x10203f4 */
  pActwk->colicnt = 0; /* Line 3098, Address: 0x10203fc */

  return 1; /* Line 3100, Address: 0x1020404 */
} /* Line 3101, Address: 0x1020408 */






static int egg8hane_demo(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk) { /* Line 3108, Address: 0x1020420 */
  egg8hane_posiset(pActwk, pMecawk); /* Line 3109, Address: 0x1020434 */

  if (pEggwk->r_no0 == 4) { /* Line 3111, Address: 0x1020444 */
    pActwk->colino = 0; /* Line 3112, Address: 0x102045c */
    pActwk->colicnt = 0; /* Line 3113, Address: 0x1020464 */
  } /* Line 3114, Address: 0x102046c */
  else {
    pActwk->r_no0 = 4; /* Line 3116, Address: 0x1020474 */
  }

  return 1; /* Line 3119, Address: 0x1020480 */
} /* Line 3120, Address: 0x1020484 */






static int egg8hane_normal(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk) { /* Line 3127, Address: 0x10204a0 */
  if (pActwk->actfree[2] & 8) { /* Line 3128, Address: 0x10204b0 */
    pActwk->actfree[3] = 0; /* Line 3129, Address: 0x10204c8 */
    pActwk->r_no0 = 10; /* Line 3130, Address: 0x10204d0 */
    return -1; /* Line 3131, Address: 0x10204dc */
  }


  if (pMecawk->r_no0 == 10 && pActwk->patno == 0) { /* Line 3135, Address: 0x10204e8 */
    pActwk->actfree[3] = 0; /* Line 3136, Address: 0x1020514 */
    pActwk->r_no0 = 6; /* Line 3137, Address: 0x102051c */
    ++pMecawk->actfree[19]; /* Line 3138, Address: 0x1020528 */
    return 1; /* Line 3139, Address: 0x1020538 */
  }


  pActwk->patbase = hane_base_tbl[pMecawk->actfree[10]]; /* Line 3143, Address: 0x1020544 */

  if (pMecawk->actfree[2] & 64) { /* Line 3145, Address: 0x102056c */
    hane_rol_l(pActwk); /* Line 3146, Address: 0x1020584 */
  } else if (pMecawk->actfree[2] & 32) { /* Line 3147, Address: 0x1020590 */
    hane_rol_r(pActwk); /* Line 3148, Address: 0x10205b0 */
  }


  if (!pActwk->actfree[14]) { /* Line 3152, Address: 0x10205bc */
    pMecawk->actfree[11] = pActwk->patno; /* Line 3153, Address: 0x10205cc */
  }


  egg8hane_posiset(pActwk, pMecawk); /* Line 3157, Address: 0x10205dc */
  return 1; /* Line 3158, Address: 0x10205ec */
} /* Line 3159, Address: 0x10205f0 */
















static char reset_tbl_1mai[2] = { 8, -1 };
static char reset_tbl_2mai[2] = { 8, 12 };
static char reset_tbl_3mai[4] = { 4, 8, 12, -1 };
static char reset_tbl_4mai[4] = { 0, 4, 8, 12 };
static char* reset_pattbl[5] = {
  0,
  reset_tbl_1mai,
  reset_tbl_2mai,
  reset_tbl_3mai,
  reset_tbl_4mai
};

static int egg8hane_fire1(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk) { /* Line 3188, Address: 0x1020600 */
  short PosWk;
  char* pResetTbl;
  int lwk;
  static short hane_fire_tbl[16] = {
    3776,
    3904,
    3968,
    3712,
    3712,
    3776,
    3840,
    3904,
    3968,
    3904,
    3840,
    3712,
    3760,
    3920,
    3792,
    3856
  };





  switch (pActwk->actfree[3]) { /* Line 3215, Address: 0x1020620 */

    case 0:
      ++pActwk->actfree[3]; /* Line 3218, Address: 0x1020654 */

      if (pEggwk->actfree[16] == 1) { /* Line 3220, Address: 0x1020664 */
        pActwk->patbase = egg8hane0_pat2; /* Line 3221, Address: 0x102067c */
      }

    case 1:
      pActwk->yposi.l -= 65536; /* Line 3225, Address: 0x102068c */
      if (pActwk->yposi.w.h <= 224) { /* Line 3226, Address: 0x10206a0 */

        ++pActwk->actfree[3]; /* Line 3228, Address: 0x10206bc */
        ++pMecawk->actfree[20]; /* Line 3229, Address: 0x10206cc */
      }

      break; /* Line 3232, Address: 0x10206dc */


    case 2:
      if (pEggwk->actfree[16] <= pMecawk->actfree[20]) { /* Line 3236, Address: 0x10206e4 */

        pActwk->actfree[0] = 0; /* Line 3238, Address: 0x1020708 */
        ++pActwk->actfree[3]; /* Line 3239, Address: 0x1020710 */
      }

      break; /* Line 3242, Address: 0x1020720 */


    case 3:
      if (++pActwk->actfree[0] == (pActwk->actfree[14] + 1) * 30) { /* Line 3246, Address: 0x1020728 */

        pActwk->sprpri = 3; /* Line 3248, Address: 0x1020764 */
        ++pActwk->actfree[3]; /* Line 3249, Address: 0x1020770 */
        pActwk->actfree[0] = 0; /* Line 3250, Address: 0x1020780 */

        pActwk->patno = 0; /* Line 3252, Address: 0x1020788 */

        if (pEggwk->actfree[16] >= 3) { /* Line 3254, Address: 0x1020790 */
          pActwk->patbase = egg8hane2_pat2; /* Line 3255, Address: 0x10207a8 */


          pActwk->xposi.w.h = hane_fire_tbl[pMecawk->actfree[21] / 2 + pActwk->actfree[14]]; /* Line 3258, Address: 0x10207b8 */

          ((int*)pActwk)[14] = 0; /* Line 3260, Address: 0x1020808 */
          ((int*)pActwk)[4] = 229376; /* Line 3261, Address: 0x1020810 */
        } else { /* Line 3262, Address: 0x1020820 */
          pActwk->patbase = egg8hane0_pat2; /* Line 3263, Address: 0x1020828 */

          if (pEggwk->actfree[16] != 2) { /* Line 3265, Address: 0x1020838 */

            if (actwk[0].xposi.w.h < 3840) { /* Line 3267, Address: 0x1020850 */

              pActwk->patno = 3; /* Line 3269, Address: 0x102086c */

              lwk = 4088; /* Line 3271, Address: 0x1020878 */
              lwk -= actwk[0].xposi.w.h; /* Line 3272, Address: 0x102087c */
              lwk *= -27146; /* Line 3273, Address: 0x1020890 */
              lwk >>= 16; /* Line 3274, Address: 0x1020898 */
              lwk &= 65535; /* Line 3275, Address: 0x102089c */
              lwk += 480; /* Line 3276, Address: 0x10208a0 */
              pActwk->yposi.w.h = lwk; /* Line 3277, Address: 0x10208a4 */

              pActwk->xposi.w.h = 4040; /* Line 3279, Address: 0x10208b4 */
              ((int*)pActwk)[14] = -211897; /* Line 3280, Address: 0x10208c0 */
              ((int*)pActwk)[4] = 87759; /* Line 3281, Address: 0x10208d0 */
            } /* Line 3282, Address: 0x10208e0 */
            else {
              pActwk->patno = 13; /* Line 3284, Address: 0x10208e8 */

              lwk = actwk[0].xposi.w.h; /* Line 3286, Address: 0x10208f4 */
              lwk -= 3592; /* Line 3287, Address: 0x1020904 */
              lwk *= -27146; /* Line 3288, Address: 0x1020908 */
              lwk >>= 16; /* Line 3289, Address: 0x1020910 */
              lwk &= 65535; /* Line 3290, Address: 0x1020914 */
              lwk += 480; /* Line 3291, Address: 0x1020918 */
              pActwk->yposi.w.h = lwk; /* Line 3292, Address: 0x102091c */

              pActwk->xposi.w.h = 3640; /* Line 3294, Address: 0x102092c */
              ((int*)pActwk)[14] = 211897; /* Line 3295, Address: 0x1020938 */
              ((int*)pActwk)[4] = 87759; /* Line 3296, Address: 0x1020948 */
            }
          } else if (!pActwk->actfree[14]) { /* Line 3298, Address: 0x1020958 */

            pActwk->xposi.w.h = hane_fire_tbl[pMecawk->actfree[21] / 2 + pActwk->actfree[14]]; /* Line 3300, Address: 0x1020970 */

            ((int*)pActwk)[14] = 0; /* Line 3302, Address: 0x10209c0 */
            ((int*)pActwk)[4] = 229376; /* Line 3303, Address: 0x10209c8 */
          } else { /* Line 3304, Address: 0x10209d8 */

            pActwk->xposi.w.h = actwk[0].xposi.w.h; /* Line 3306, Address: 0x10209e0 */
            ((int*)pActwk)[14] = 0; /* Line 3307, Address: 0x10209f0 */
            ((int*)pActwk)[4] = 229376; /* Line 3308, Address: 0x10209f8 */
          }
        }
      }

      break; /* Line 3313, Address: 0x1020a08 */


    case 4:
      pActwk->xposi.l += ((int*)pActwk)[14]; /* Line 3317, Address: 0x1020a10 */
      pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 3318, Address: 0x1020a28 */

      if (pActwk->patno != 0) { /* Line 3320, Address: 0x1020a40 */

        PosWk = 464; /* Line 3322, Address: 0x1020a54 */
      } else if (pActwk->patbase == egg8hane2_pat2) { /* Line 3323, Address: 0x1020a60 */
        PosWk = 448; /* Line 3324, Address: 0x1020a80 */
      } else { /* Line 3325, Address: 0x1020a8c */

        PosWk = 440; /* Line 3327, Address: 0x1020a94 */
      }


      if (pActwk->yposi.w.h >= PosWk) { /* Line 3331, Address: 0x1020aa0 */

        pActwk->yposi.w.h = PosWk; /* Line 3333, Address: 0x1020ac4 */
        ++pActwk->actfree[3]; /* Line 3334, Address: 0x1020acc */
        pActwk->actfree[0] = 0; /* Line 3335, Address: 0x1020adc */

        soundset(180); /* Line 3337, Address: 0x1020ae4 */
      }

      break; /* Line 3340, Address: 0x1020af0 */


    case 5:
      if (++pActwk->actfree[0] == 30) { /* Line 3344, Address: 0x1020af8 */

        pActwk->sprpri = 5; /* Line 3346, Address: 0x1020b1c */
        ++pActwk->actfree[3]; /* Line 3347, Address: 0x1020b28 */
        pActwk->colino = 0; /* Line 3348, Address: 0x1020b38 */
        pActwk->colicnt = 0; /* Line 3349, Address: 0x1020b40 */
        pActwk->actfree[0] = 0; /* Line 3350, Address: 0x1020b48 */
      }

      break; /* Line 3353, Address: 0x1020b50 */


    case 6:
      if (++pActwk->actfree[0] == 60) { /* Line 3357, Address: 0x1020b58 */

        ++pMecawk->actfree[19]; /* Line 3359, Address: 0x1020b7c */

        pActwk->actfree[0] = 0; /* Line 3361, Address: 0x1020b8c */
        pActwk->actfree[3] = 0; /* Line 3362, Address: 0x1020b94 */
        pActwk->r_no0 = 8; /* Line 3363, Address: 0x1020b9c */

        pResetTbl = reset_pattbl[pEggwk->actfree[16]]; /* Line 3365, Address: 0x1020ba8 */

        if (!pActwk->actfree[14]) { /* Line 3367, Address: 0x1020bc8 */
          pMecawk->actfree[11] = pResetTbl[0]; /* Line 3368, Address: 0x1020bd8 */
        }

        pActwk->patno = pResetTbl[pActwk->actfree[14]]; /* Line 3371, Address: 0x1020be4 */
        pMecawk->actfree[10] = 0; /* Line 3372, Address: 0x1020c00 */


      } else if (!(pActwk->actfree[0] / 2 & 1)) { /* Line 3375, Address: 0x1020c08 */

        return 1; /* Line 3377, Address: 0x1020c44 */
      }

      return 0; /* Line 3380, Address: 0x1020c50 */
  }




  return 1; /* Line 3386, Address: 0x1020c5c */
} /* Line 3387, Address: 0x1020c60 */






static int egg8hane_wait(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk) { /* Line 3394, Address: 0x1020c80 */
  if (pActwk->actfree[2] & 8) { /* Line 3395, Address: 0x1020c90 */
    frameout(pActwk); return 0; /* Line 3396, Address: 0x1020ca8 */
  }

  if (pMecawk->actfree[2] & 8) { /* Line 3399, Address: 0x1020cc0 */

    pActwk->r_no0 = 4; /* Line 3401, Address: 0x1020cd8 */
  }

  return 0; /* Line 3404, Address: 0x1020ce4 */
} /* Line 3405, Address: 0x1020ce8 */






static int egg8hane_kill(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk) { /* Line 3412, Address: 0x1020d00 */
  if (!pActwk->actfree[3]) { /* Line 3413, Address: 0x1020d0c */

    pActwk->colino = 0; /* Line 3415, Address: 0x1020d1c */
    pActwk->colicnt = 0; /* Line 3416, Address: 0x1020d24 */

    ((int*)pActwk)[14] = 65536; /* Line 3418, Address: 0x1020d2c */
    ((int*)pActwk)[4] = -196608; /* Line 3419, Address: 0x1020d38 */

    if (pActwk->patno > 8) { /* Line 3421, Address: 0x1020d44 */
      ((int*)pActwk)[14] *= -1; /* Line 3422, Address: 0x1020d5c */
    }


    pActwk->actfree[0] = 0; /* Line 3426, Address: 0x1020d6c */
    pActwk->actfree[1] = 0; /* Line 3427, Address: 0x1020d74 */
    ++pActwk->actfree[3]; /* Line 3428, Address: 0x1020d7c */

    if (pActwk->patbase != egg8hane1_pat) { /* Line 3430, Address: 0x1020d8c */

      pActwk->patbase = egg8hane0_pat3; /* Line 3432, Address: 0x1020da4 */
    } /* Line 3433, Address: 0x1020db4 */
    else {
      pActwk->patbase = egg8hane2_pat1; /* Line 3435, Address: 0x1020dbc */
    }
  }


  pActwk->xposi.l += ((int*)pActwk)[14]; /* Line 3440, Address: 0x1020dcc */
  pActwk->yposi.l += ((int*)pActwk)[4]; /* Line 3441, Address: 0x1020de4 */
  ((int*)pActwk)[4] += 12288; /* Line 3442, Address: 0x1020dfc */

  if (pActwk->yposi.w.h >= 480) { /* Line 3444, Address: 0x1020e0c */
    frameout(pActwk); return 0; /* Line 3445, Address: 0x1020e28 */
  }

  if (++pActwk->actfree[0] == 4) { /* Line 3448, Address: 0x1020e40 */
    pActwk->actfree[0] = 0; /* Line 3449, Address: 0x1020e64 */

    if (++pActwk->patno > 15) { /* Line 3451, Address: 0x1020e6c */
      pActwk->patno = 0; /* Line 3452, Address: 0x1020e90 */
    }
  }


  ++pActwk->actfree[1]; /* Line 3457, Address: 0x1020e98 */



  if (pActwk->actfree[1] / 2 & 1) { /* Line 3461, Address: 0x1020ea8 */

    return 0; /* Line 3463, Address: 0x1020ed8 */
  }
  return 1; /* Line 3465, Address: 0x1020ee4 */

} /* Line 3467, Address: 0x1020ee8 */











































static char hane_reset_tbl_2mai[12];
static char hane_reset_tbl_3mai[16];
static char* hane_no_reset_tbl[4] = {
  0,
  0,
  hane_reset_tbl_2mai,
  hane_reset_tbl_3mai
};

static void hane_no_reset(sprite_status* pActwk, sprite_status* pMecawk, sprite_status* pEggwk) { /* Line 3520, Address: 0x1020f00 */
  char* pResetTbl;
  int HaneNum, KillNo;

  if (pMecawk->actfree[17] == pActwk->actfree[14]) { /* Line 3524, Address: 0x1020f1c */

    pActwk->actfree[2] |= 8; /* Line 3526, Address: 0x1020f3c */
    return; /* Line 3527, Address: 0x1020f4c */
  }


  if (pEggwk->actfree[16] == 1) { /* Line 3531, Address: 0x1020f54 */

    pActwk->actfree[14] = 0; /* Line 3533, Address: 0x1020f6c */
    return; /* Line 3534, Address: 0x1020f74 */
  }


  HaneNum = pEggwk->actfree[16]; /* Line 3538, Address: 0x1020f7c */
  KillNo = pMecawk->actfree[17]; /* Line 3539, Address: 0x1020f88 */
  pResetTbl = hane_no_reset_tbl[HaneNum] + KillNo * 4; /* Line 3540, Address: 0x1020f94 */

  pActwk->actfree[14] = pResetTbl[pActwk->actfree[14]]; /* Line 3542, Address: 0x1020fb0 */
} /* Line 3543, Address: 0x1020fcc */














static void egg8hane_posiset(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 3558, Address: 0x1020ff0 */
  hane_offs_set(pActwk, pMecawk); /* Line 3559, Address: 0x1021000 */
  pActwk->xposi.w.h = pMecawk->xposi.w.h + ((short*)pActwk)[26]; /* Line 3560, Address: 0x1021010 */
  pActwk->yposi.w.h = pMecawk->yposi.w.h + ((short*)pActwk)[27]; /* Line 3561, Address: 0x1021044 */
} /* Line 3562, Address: 0x1021078 */





























static hane_offs hane0_offs_tbl1[16] = {
  {   0, -40,   0, -36, 180 },
  {  19, -36,  18, -31, 181 },
  {  31, -32,  25, -25, 182 },
  {  38, -16,  31, -18, 183 },
  {  40,   0,  36,   0, 184 },
  {  38,  16,  31,  18, 183 },
  {  31,  32,  25,  25, 182 },
  {  19,  36,  18,  31, 181 },
  {   0,  40,   0,  36, 180 },
  { -19,  36, -18,  31, 181 },
  { -31,  32, -25,  25, 182 },
  { -38,  16, -31,  18, 183 },
  { -40,   0, -36,   0, 184 },
  { -38, -16, -31, -18, 183 },
  { -31, -32, -25, -25, 182 },
  { -19, -36, -18, -31, 181 }
};
static hane_offs hane1_offs_tbl[16] = {
  {   0, -32,   0, -36, 185 },
  {   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0 },
  {  32,   0,  36,   0, 186 },
  {   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0 },
  {   0,  32,   0,  36, 185 },
  {   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0 },
  { -32,   0, -36,   0, 186 },
  {   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0 },
  {   0,   0,   0,   0,   0 }
};
static hane_offs hane2_offs_tbl[16] = {
  {   0, -32,   0, -36, 187 },
  {  12, -29,  18, -31, 188 },
  {  23, -23,  25, -25, 189 },
  {  29, -12,  31, -18, 190 },
  {  32,   0,  36,   0, 191 },
  {  29,  12,  31,  18, 190 },
  {  23,  23,  25,  25, 189 },
  {  12,  29,  18,  31, 188 },
  {   0,  32,   0,  36, 187 },
  { -12,  29, -18,  31, 188 },
  { -23,  23, -25,  25, 189 },
  { -29,  12, -31,  18, 190 },
  { -32,   0, -36,   0, 191 },
  { -29, -12, -31, -18, 190 },
  { -23, -23, -25, -25, 189 },
  { -12, -29, -18, -31, 188 }
};
static hane_offs* hane_offs_tbl[6] = {
  hane0_offs_tbl1,
  hane0_offs_tbl1,
  hane0_offs_tbl1,
  hane1_offs_tbl,
  hane2_offs_tbl,
  hane2_offs_tbl
};

static void hane_offs_set(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 3655, Address: 0x1021090 */
  hane_offs* pOffsTbl;
  short hankeiwk;

  pOffsTbl = hane_offs_tbl[pMecawk->actfree[10]] + pActwk->patno; /* Line 3659, Address: 0x10210a4 */

  hankeiwk = ((short*)pMecawk)[30]; /* Line 3661, Address: 0x10210e0 */
  ((short*)pActwk)[26] = (pOffsTbl->xDst * hankeiwk >> 8) + pOffsTbl->xOffs; /* Line 3662, Address: 0x10210f0 */

  ((short*)pActwk)[27] = (pOffsTbl->yDst * hankeiwk >> 8) + pOffsTbl->yOffs; /* Line 3664, Address: 0x102112c */

  pActwk->colino = pOffsTbl->ColiNo; /* Line 3666, Address: 0x1021168 */
  pActwk->colicnt = 2; /* Line 3667, Address: 0x1021178 */
} /* Line 3668, Address: 0x1021184 */













static void hane_rol_l(sprite_status* pActwk) { /* Line 3682, Address: 0x10211a0 */
  if ((char)--pActwk->patno < 0) { /* Line 3683, Address: 0x10211ac */
    pActwk->patno = 15; /* Line 3684, Address: 0x10211d8 */
  }

  rol_sound(pActwk); /* Line 3687, Address: 0x10211e4 */
} /* Line 3688, Address: 0x10211f0 */


static void hane_rol_r(sprite_status* pActwk) { /* Line 3691, Address: 0x1021200 */
  if (++pActwk->patno >= 16) { /* Line 3692, Address: 0x102120c */
    pActwk->patno = 0; /* Line 3693, Address: 0x1021230 */
  }

  rol_sound(pActwk); /* Line 3696, Address: 0x1021238 */
} /* Line 3697, Address: 0x1021244 */


static void rol_sound(sprite_status* pActwk) { /* Line 3700, Address: 0x1021260 */
  if (!pActwk->actfree[14] && (pActwk->patno & 3) != 2) { /* Line 3701, Address: 0x102126c */
    soundset(186); /* Line 3702, Address: 0x1021298 */
  }
} /* Line 3704, Address: 0x10212a4 */



































static short hibana0[6] = { -16, 0, -16, -8, -4, 0 };
static short hibana1[6] = { 4, 0, 16, -8, 8, 0 };
static short* hibana_offs_tbl[2] = {
  hibana0,
  hibana1
};
static sprite_pattern hibana_pat0 = { 1, { { -8, -4, 0, 487 } } };
static sprite_pattern hibana_pat1 = { 1, { { -8, -4, 0, 488 } } };
sprite_pattern* egg8hibana_pat[2] = {
  &hibana_pat0,
  &hibana_pat1
};
static unsigned int(*hibana_act_tbl[2])(sprite_status*) = {
  &egg8hibana_ini,
  &egg8hibana_1
};

void egg8hibana(sprite_status* pActwk) { /* Line 3757, Address: 0x10212c0 */
  if (hibana_act_tbl[pActwk->r_no0 / 2](pActwk) != 0) { /* Line 3758, Address: 0x10212cc */
    actionsub(pActwk); /* Line 3759, Address: 0x1021318 */
  }
} /* Line 3761, Address: 0x1021324 */





static unsigned int egg8hibana_ini(sprite_status* pActwk) { /* Line 3767, Address: 0x1021340 */
  pActwk->r_no0 += 2; /* Line 3768, Address: 0x102134c */
  pActwk->actflg = 4; /* Line 3769, Address: 0x102135c */
  pActwk->sprpri = 4; /* Line 3770, Address: 0x1021368 */
  pActwk->sprhsize = 8; /* Line 3771, Address: 0x1021374 */
  pActwk->sprvsize = 8; /* Line 3772, Address: 0x1021380 */
  pActwk->sproffset = 990; /* Line 3773, Address: 0x102138c */
  pActwk->patbase = egg8hibana_pat; /* Line 3774, Address: 0x1021398 */

  egg8hibana_1(pActwk); /* Line 3776, Address: 0x10213a8 */
} /* Line 3777, Address: 0x10213b4 */





static unsigned int egg8hibana_1(sprite_status* pActwk) { /* Line 3783, Address: 0x10213d0 */
  sprite_status* pMecawk;
  short* pOffsTbl;

  pMecawk = &actwk[((short*)pActwk)[25]]; /* Line 3787, Address: 0x10213e4 */
  pActwk->xposi.w.h = pMecawk->xposi.w.h; /* Line 3788, Address: 0x102140c */
  pActwk->yposi.w.h = pMecawk->yposi.w.h; /* Line 3789, Address: 0x1021418 */

  pOffsTbl = hibana_offs_tbl[pActwk->actfree[10]] + pActwk->actfree[3] / 2; /* Line 3791, Address: 0x1021424 */
  pActwk->xposi.w.h += *pOffsTbl++; /* Line 3792, Address: 0x1021470 */
  pActwk->yposi.w.h += *pOffsTbl; /* Line 3793, Address: 0x102148c */

  if (++pActwk->actfree[0] == 150) { /* Line 3795, Address: 0x10214a0 */
    frameout(pActwk); return 0; /* Line 3796, Address: 0x10214c4 */
  }

  if (++pActwk->actfree[1] == 4) { /* Line 3799, Address: 0x10214dc */
    if ((pActwk->actfree[3] += 4) > 8) { /* Line 3800, Address: 0x1021500 */
      pActwk->actfree[3] = 0; /* Line 3801, Address: 0x1021524 */
    }


    pActwk->actfree[1] = 0; /* Line 3805, Address: 0x102152c */

    if (++pActwk->patno > 2) { /* Line 3807, Address: 0x1021534 */
      pActwk->patno = 0; /* Line 3808, Address: 0x1021558 */
    }
  }


  if (pActwk->patno == 2) { /* Line 3813, Address: 0x1021560 */
    return 0; /* Line 3814, Address: 0x1021578 */
  }
  return 1; /* Line 3816, Address: 0x1021584 */

} /* Line 3818, Address: 0x1021588 */
















static void make_meca(sprite_status* pActwk) { /* Line 3835, Address: 0x10215a0 */
  sprite_status* pNewact;

  if (actwkchk2(pActwk, &pNewact) == 0) { /* Line 3838, Address: 0x10215ac */
    ((short*)pNewact)[25] = pActwk - actwk; /* Line 3839, Address: 0x10215c4 */
    ((short*)pActwk)[25] = pNewact - actwk; /* Line 3840, Address: 0x10215fc */
    pNewact->actno = 65; /* Line 3841, Address: 0x1021634 */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 3842, Address: 0x1021640 */
    pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 3843, Address: 0x1021650 */
  }


} /* Line 3847, Address: 0x1021660 */












static void make_hane(sprite_status* pActwk) { /* Line 3860, Address: 0x1021670 */
  sprite_status* pNewact;
  unsigned char hanecnt, hanepat;

  hanecnt = hanepat = 0; /* Line 3864, Address: 0x1021684 */


  do {
    if (actwkchk2(pActwk, &pNewact) != 0) return; /* Line 3868, Address: 0x1021690 */



    ((short*)pNewact)[25] = pActwk - actwk; /* Line 3872, Address: 0x10216a8 */
    pNewact->actfree[14] = hanecnt; /* Line 3873, Address: 0x10216e0 */
    pNewact->actno = 64; /* Line 3874, Address: 0x10216e8 */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 3875, Address: 0x10216f4 */
    pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 3876, Address: 0x1021704 */
    pNewact->patno = hanepat; /* Line 3877, Address: 0x1021714 */
    ++hanecnt; /* Line 3878, Address: 0x102171c */
    hanepat += 4; /* Line 3879, Address: 0x1021724 */
  } while (hanecnt != 4); /* Line 3880, Address: 0x102172c */
} /* Line 3881, Address: 0x102173c */












static void make_hibana(sprite_status* pActwk) { /* Line 3894, Address: 0x1021760 */
  unsigned char cnt;
  sprite_status* pNewact;

  cnt = 0; /* Line 3898, Address: 0x1021770 */

  do {
    if (actwkchk(&pNewact) != 0) break; /* Line 3901, Address: 0x1021774 */



    ((short*)pNewact)[25] = pActwk - actwk; /* Line 3905, Address: 0x1021788 */
    pNewact->actno = 66; /* Line 3906, Address: 0x10217c0 */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 3907, Address: 0x10217cc */
    pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 3908, Address: 0x10217dc */
    pNewact->actfree[10] = cnt++; /* Line 3909, Address: 0x10217ec */

  } while (cnt != 2); /* Line 3911, Address: 0x1021800 */


} /* Line 3914, Address: 0x1021810 */


















static void egg8_spd_set(sprite_status* pActwk, sprite_status* pMecawk) { /* Line 3933, Address: 0x1021830 */
  egg8spd spd_tbl[5] = { /* Line 3934, Address: 0x102183c */
    {  81920,     0, 4, 0 },
    { 114688, 65536, 2, 0 },
    { 106496, 57344, 3, 0 },
    {  98304, 49152, 4, 0 },
    {  90112, 40960, 5, 0 }
  };
















  ((int*)pActwk)[14] = spd_tbl[pActwk->actfree[16]].X_Speed; /* Line 3957, Address: 0x1021868 */

  ((int*)pActwk)[4] = spd_tbl[pActwk->actfree[16]].Y_Speed; /* Line 3959, Address: 0x1021890 */

  pMecawk->actfree[13] = spd_tbl[pActwk->actfree[16]].Roll_Speed; /* Line 3961, Address: 0x10218b8 */

} /* Line 3963, Address: 0x10218e0 */












static void tobi_set(sprite_status* pActwk) { /* Line 3976, Address: 0x10218f0 */
  short sinwk, coswk;

  pActwk->xposi.w.h -= ((short*)pActwk)[26]; /* Line 3979, Address: 0x10218fc */
  pActwk->yposi.w.h -= ((short*)pActwk)[27]; /* Line 3980, Address: 0x1021914 */

  if ((((unsigned short*)pActwk)[23] += 560) >= 32768) { /* Line 3982, Address: 0x102192c */
    ((unsigned short*)pActwk)[23] = 32768; /* Line 3983, Address: 0x1021954 */
  }


  sinset(pActwk->actfree[1], &sinwk, &coswk); /* Line 3987, Address: 0x1021960 */

  if (!(pActwk->actfree[3] & 1)) { /* Line 3989, Address: 0x1021978 */
    coswk *= -1; /* Line 3990, Address: 0x1021990 */
  }


  coswk = coswk * 41 >> 8; /* Line 3994, Address: 0x102199c */
  sinwk = sinwk * -104 >> 8; /* Line 3995, Address: 0x10219c8 */
  ((short*)pActwk)[26] = coswk; /* Line 3996, Address: 0x10219f8 */
  ((short*)pActwk)[27] = sinwk; /* Line 3997, Address: 0x1021a04 */
  pActwk->xposi.w.h += coswk; /* Line 3998, Address: 0x1021a10 */
  pActwk->yposi.w.h += sinwk; /* Line 3999, Address: 0x1021a24 */
} /* Line 4000, Address: 0x1021a38 */












static void bom_set(sprite_status* pActwk) { /* Line 4013, Address: 0x1021a50 */
  sprite_status* pNewact;
  int rnd;
  int_union wk1, wk2;

  if (pActwk->actfree[0] % 2 == 0) { /* Line 4018, Address: 0x1021a60 */

    if (actwkchk(&pNewact) == 0) { /* Line 4020, Address: 0x1021a90 */
      pNewact->actno = 24; /* Line 4021, Address: 0x1021aa4 */
      pNewact->r_no1 = 255; /* Line 4022, Address: 0x1021ab0 */
      pNewact->userflag.b.l = -1; /* Line 4023, Address: 0x1021abc */


      rnd = random(); /* Line 4026, Address: 0x1021ac8 */
      wk2.l = (short)((long int)rnd & 65535); /* Line 4027, Address: 0x1021ad4 */
      wk1.l = (short)(((long int)rnd & 4294901760) >> 16); /* Line 4028, Address: 0x1021af4 */
      pNewact->xposi.w.h = wk1.l % 128 + 3840; /* Line 4029, Address: 0x1021b20 */
      pNewact->yposi.w.h = wk2.l % 80 + 384; /* Line 4030, Address: 0x1021b54 */

      soundset(158); /* Line 4032, Address: 0x1021b78 */
    }
  }


} /* Line 4037, Address: 0x1021b84 */
