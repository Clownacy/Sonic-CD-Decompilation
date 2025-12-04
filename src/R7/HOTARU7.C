#include "..\EQU.H"
#include "HOTARU7.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static void a_init(sprite_status* pActwk);
static void a_wait(sprite_status* pActwk);
static void a_make(sprite_status* pActwk);
static void ini_b(sprite_status* pActwk, sprite_status* pNewact);
static void a_move(sprite_status* pActwk);
static void b_init(sprite_status* pActwk);
static void b_fly(sprite_status* pActwk);
static void b_near(sprite_status* pActwk);
static void b_fix(sprite_status* pActwk);
static void b_fix1(sprite_status* pActwk);
static void b_start(sprite_status* pActwk);
static void b_com(sprite_status* pActwk);
static void b_com1(sprite_status* pActwk);
static void b_kill_v(sprite_status* pActwk);
static void b_die_v(sprite_status* pActwk, sprite_status* pMainwk);
static void b_light(sprite_status* pActwk);
static void b_up(sprite_status* pActwk);
static void b_up1(sprite_status* pActwk);
static void b_make_c(sprite_status* pActwk);
static void c_init(sprite_status* pActwk);
static void c_move(sprite_status* pActwk);
static unsigned int area(sprite_status* pActwk, sprite_status* pPlayerwk, unsigned short Ypos, unsigned short Ylen, unsigned short Xpos, unsigned short Xlen);

static short tbl_hotaru7[8] = { 36, 60, 8, -68, 56, -56, 80, 16 };
static unsigned char pchg_e00[12] = { 9, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 252 };
static unsigned char pchg_e01[14] = { 3, 4, 2, 2, 2, 4, 4, 2, 2, 4, 4, 4, 2, 252 };
static unsigned char pchg_e02[12] = { 9, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 252 };
static unsigned char pchg_e03[4] = { 9, 3, 4, 255 };
static unsigned char* pchg_hotaru7_e[4] = {
  pchg_e00,
  pchg_e01,
  pchg_e02,
  pchg_e03
};
static unsigned char pchg_b00[12] = { 19, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 252 };
static unsigned char pchg_b01[14] = { 9, 4, 2, 2, 2, 4, 4, 2, 2, 4, 4, 4, 2, 252 };
static unsigned char pchg_b02[12] = { 19, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 252 };
static unsigned char pchg_b03[4] = { 19, 3, 4, 255 };
static unsigned char* pchg_hotaru7_b[4] = {
  pchg_b00,
  pchg_b01,
  pchg_b02,
  pchg_b03
};
static unsigned char pchg_tama00[5] = { 1, 0, 1, 2, 255 };
static unsigned char* pchg_tama[1] = { pchg_tama00 };
static sprite_pattern pat_e00 = {
  1,
  { { -20, -12, 32, 508 } }
};
static sprite_pattern pat_e01 = {
  1,
  { { -12, -20, 32, 509 } }
};
static sprite_pattern pat_e02 = {
  1,
  { { -12, -20, 32, 510 } }
};
static sprite_pattern pat_e03 = {
  2,
  { {
    { -12, -20, 32, 511 },
    { -11, -7, 32, 521 }
  } }
};
static sprite_pattern pat_e04 = {
  2,
  { {
    { -12, -20, 32, 512 },
    { -11, -7, 32, 521 }
  } }
};
sprite_pattern* pat_hotaru7_e[5] = {
  &pat_e00,
  &pat_e01,
  &pat_e02,
  &pat_e03,
  &pat_e04
};
static sprite_pattern pat_b00 = {
  1,
  { { -20, -12, 32, 513 } }
};
static sprite_pattern pat_b01 = {
  1,
  { { -12, -20, 32, 514 } }
};
static sprite_pattern pat_b02 = {
  1,
  { { -12, -20, 32, 515 } }
};
static sprite_pattern pat_b03 = {
  2,
  { {
    { -12, -20, 32, 516 },
    { -11, -7, 32, 521 }
  } }
};
static sprite_pattern pat_b04 = {
  2,
  { {
    { -12, -20, 32, 517 },
    { -11, -7, 32, 521 }
  } }
};
sprite_pattern* pat_hotaru7_b[5] = {
  &pat_b00,
  &pat_b01,
  &pat_b02,
  &pat_b03,
  &pat_b04
};
static sprite_pattern pat_tama00 = {
  1,
  { { -12, -12, 0, 518 } }
};
static sprite_pattern pat_tama01 = {
  1,
  { { -12, -12, 0, 519 } }
};
static sprite_pattern pat_tama02 = {
  1,
  { { -12, -12, 0, 520 } }
};
sprite_pattern* pat_tama[3] = {
  &pat_tama00,
  &pat_tama01,
  &pat_tama02
};
static void(*a_act_tbl[4])(sprite_status*) = {
  &a_init,
  &a_wait,
  &a_make,
  &a_move
};
static void(*b_act_tbl[11])(sprite_status*) = {
  &b_init,
  &b_fly,
  &b_near,
  &b_fix,
  &b_fix1,
  &b_start,
  &b_com,
  &b_light,
  &b_com,
  &b_up,
  &b_up1
};
static void(*c_act_tbl[3])(sprite_status*) = {
  &c_init,
  &c_move,
  &frameout
};


























































































































































void hotaru7(sprite_status* pActwk) { /* Line 315, Address: 0x10288e0 */
  switch (pActwk->userflag.b.l) { /* Line 316, Address: 0x10288f8 */
    sprite_status* pMainact;
    sprite_status* pBact1;
    sprite_status* pBact2;

    case -1:
      pMainact = &actwk[((short*)pActwk)[23]]; /* Line 322, Address: 0x1028928 */
      if (pMainact->actno != 35 || pMainact->cdsts != pActwk->actfree[12]) /* Line 323, Address: 0x1028950 */

        frameout(pActwk); /* Line 325, Address: 0x1028980 */
      else {

        if (!enemy_suicide(pActwk)) { /* Line 328, Address: 0x1028994 */
          b_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 329, Address: 0x10289a8 */
        }
      }
      break; /* Line 332, Address: 0x10289ec */





    case -2:
      pBact1 = &actwk[((short*)pActwk)[24]]; /* Line 339, Address: 0x10289f4 */
      pBact2 = &actwk[((short*)pActwk)[23]]; /* Line 340, Address: 0x1028a1c */

      if (pBact1->actno != 35 || pBact2->actno != 35 /* Line 342, Address: 0x1028a44 */
          || pBact1->r_no0 != 16 || pBact2->r_no0 != 16)
        frameout(pActwk); /* Line 344, Address: 0x1028a94 */
      else {

        c_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 347, Address: 0x1028aa8 */
      }
      break; /* Line 349, Address: 0x1028aec */


    default:
      a_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 353, Address: 0x1028af4 */
      break;
  }
} /* Line 356, Address: 0x1028b38 */





void a_init(sprite_status* pActwk) { /* Line 362, Address: 0x1028b60 */
  unsigned short flagwk;
  unsigned char* pFlagwork;
  int idx;

  pActwk->r_no0 += 2; /* Line 367, Address: 0x1028b78 */
  flagwk = pActwk->cdsts; /* Line 368, Address: 0x1028b88 */
  idx = time_flag + flagwk * 3; /* Line 369, Address: 0x1028b98 */
  pFlagwork = &flagwork[idx]; /* Line 370, Address: 0x1028bb4 */
  *(unsigned char**)&pActwk->actfree[0] = &flagwork[idx]; /* Line 371, Address: 0x1028bc0 */

  idx = pActwk->userflag.b.h & 12; /* Line 373, Address: 0x1028bd8 */
  *(short**)&pActwk->actfree[4] = &tbl_hotaru7[idx / 2]; /* Line 374, Address: 0x1028bec */

  if (pActwk->userflag.b.h & 1) { /* Line 376, Address: 0x1028c20 */
    pActwk->userflag.b.h = 1; /* Line 377, Address: 0x1028c3c */
  } else { /* Line 378, Address: 0x1028c48 */
    pActwk->userflag.b.h = 0; /* Line 379, Address: 0x1028c50 */
  }

  if (stageno.b.l != 2) { /* Line 382, Address: 0x1028c58 */
    pActwk->sproffset = 33885; /* Line 383, Address: 0x1028c74 */
  } else { /* Line 384, Address: 0x1028c80 */
    pActwk->sproffset = 33568; /* Line 385, Address: 0x1028c88 */
  }

  a_wait(pActwk); /* Line 388, Address: 0x1028c94 */
} /* Line 389, Address: 0x1028ca0 */





void a_wait(sprite_status* pActwk) { /* Line 395, Address: 0x1028cc0 */
  if (area(pActwk, &actwk[0], 65296, 480, 65296, 480) != 0) /* Line 396, Address: 0x1028ccc */
  {

    pActwk->r_no0 += 2; /* Line 399, Address: 0x1028cf8 */
  }

  frameout_s(pActwk); /* Line 402, Address: 0x1028d08 */
} /* Line 403, Address: 0x1028d14 */





void a_make(sprite_status* pActwk) { /* Line 409, Address: 0x1028d30 */
  unsigned char* pFlagWork;
  sprite_status* pNewact;
  short* pTbl;

  pActwk->r_no0 += 2; /* Line 414, Address: 0x1028d44 */
  pFlagWork = *(unsigned char**)&pActwk->actfree[0]; /* Line 415, Address: 0x1028d54 */

  if (!(*pFlagWork & 1)) { /* Line 417, Address: 0x1028d60 */
    if (actwkchk2(pActwk, &pNewact) != 0) /* Line 418, Address: 0x1028d74 */
    { frameout_s0(pActwk); return; } /* Line 419, Address: 0x1028d8c */


    ((short*)pActwk)[28] = pNewact - actwk; /* Line 422, Address: 0x1028da0 */

    ini_b(pActwk, pNewact); /* Line 424, Address: 0x1028dd8 */
    pTbl = *(short**)&pActwk->actfree[4]; /* Line 425, Address: 0x1028de8 */
    pNewact->xposi.w.h += *pTbl++; /* Line 426, Address: 0x1028df4 */
    pNewact->yposi.w.h += *pTbl; /* Line 427, Address: 0x1028e10 */
  }


  if (!(*pFlagWork & 2)) { /* Line 431, Address: 0x1028e24 */
    if (actwkchk2(pActwk, &pNewact) != 0) /* Line 432, Address: 0x1028e38 */
    { frameout_s0(pActwk); return; } /* Line 433, Address: 0x1028e50 */


    ((short*)pActwk)[27] = pNewact - actwk; /* Line 436, Address: 0x1028e64 */

    ini_b(pActwk, pNewact); /* Line 438, Address: 0x1028e9c */
    pTbl = *(short**)&pActwk->actfree[4]; /* Line 439, Address: 0x1028eac */
    pNewact->xposi.w.h -= *pTbl++; /* Line 440, Address: 0x1028eb8 */
    pNewact->yposi.w.h -= *pTbl; /* Line 441, Address: 0x1028ed4 */
  }


} /* Line 445, Address: 0x1028ee8 */





void ini_b(sprite_status* pActwk, sprite_status* pNewact) { /* Line 451, Address: 0x1028f00 */
  ((short*)pNewact)[23] = pActwk - actwk; /* Line 452, Address: 0x1028f0c */
  pNewact->actno = pActwk->actno; /* Line 453, Address: 0x1028f44 */
  pNewact->userflag.b.h = pActwk->userflag.b.h; /* Line 454, Address: 0x1028f54 */
  pNewact->userflag.b.l = -1; /* Line 455, Address: 0x1028f64 */
  pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 456, Address: 0x1028f70 */
  pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 457, Address: 0x1028f80 */
  pNewact->sproffset = pActwk->sproffset; /* Line 458, Address: 0x1028f90 */
  pNewact->actfree[12] = pActwk->cdsts; /* Line 459, Address: 0x1028fa0 */
} /* Line 460, Address: 0x1028fb0 */





void a_move(sprite_status* pActwk) { /* Line 466, Address: 0x1028fc0 */
  unsigned char* pFlagWork;
  sprite_status* pChildact;
  short idx;

  pFlagWork = *(unsigned char**)&pActwk->actfree[0]; /* Line 471, Address: 0x1028fd8 */

  if (!(*pFlagWork & 1)) { /* Line 473, Address: 0x1028fe4 */
    idx = ((short*)pActwk)[28]; /* Line 474, Address: 0x1028ff8 */
    if (idx) { /* Line 475, Address: 0x1029008 */
      pChildact = &actwk[idx]; /* Line 476, Address: 0x1029010 */
      if (pChildact->actno != pActwk->actno) { /* Line 477, Address: 0x1029030 */

        *pFlagWork |= 1; /* Line 479, Address: 0x102904c */
        ((short*)pActwk)[28] = 0; /* Line 480, Address: 0x1029058 */
      }
    }
  }






  if (!(*pFlagWork & 2)) { /* Line 490, Address: 0x1029060 */
    idx = ((short*)pActwk)[27]; /* Line 491, Address: 0x1029074 */
    if (idx) { /* Line 492, Address: 0x1029084 */
      pChildact = &actwk[idx]; /* Line 493, Address: 0x102908c */
      if (pChildact->actno != pActwk->actno) { /* Line 494, Address: 0x10290ac */

        *pFlagWork |= 2; /* Line 496, Address: 0x10290c8 */
        ((short*)pActwk)[27] = 0; /* Line 497, Address: 0x10290d4 */
      }
    }
  }






  if (*pFlagWork == 131) /* Line 507, Address: 0x10290dc */
    frameout(pActwk); /* Line 508, Address: 0x10290f0 */
  else
  {
    if (*(int*)&pActwk->actfree[8] == 0) /* Line 511, Address: 0x1029104 */
      frameout_s0(pActwk); /* Line 512, Address: 0x1029118 */
  }
} /* Line 514, Address: 0x1029124 */








void b_init(sprite_status* pActwk) { /* Line 523, Address: 0x1029140 */
  pActwk->r_no0 += 2; /* Line 524, Address: 0x1029148 */
  pActwk->actflg |= 4; /* Line 525, Address: 0x1029158 */
  pActwk->sprpri = 1; /* Line 526, Address: 0x1029168 */
  pActwk->sprhs = pActwk->sprhsize = 20; /* Line 527, Address: 0x1029174 */
  pActwk->sprvsize = 12; /* Line 528, Address: 0x102918c */
  pActwk->colino = 50; /* Line 529, Address: 0x1029198 */
  ((short*)pActwk)[24] = pActwk->xposi.w.h; /* Line 530, Address: 0x10291a4 */

  if (!pActwk->userflag.b.h) { /* Line 532, Address: 0x10291b4 */

    pActwk->patbase = pat_hotaru7_e; /* Line 534, Address: 0x10291c4 */
    *(unsigned char***)&pActwk->actfree[8] = pchg_hotaru7_e; /* Line 535, Address: 0x10291d4 */
    *(int*)&pActwk->actfree[4] = -65536; /* Line 536, Address: 0x10291e8 */
  } /* Line 537, Address: 0x10291f8 */
  else {
    pActwk->patbase = pat_hotaru7_b; /* Line 539, Address: 0x1029200 */
    *(unsigned char***)&pActwk->actfree[8] = pchg_hotaru7_b; /* Line 540, Address: 0x1029210 */
    *(int*)&pActwk->actfree[4] = -32768; /* Line 541, Address: 0x1029224 */
  }


  if (actwk[0].xposi.w.h >= pActwk->xposi.w.h) { /* Line 545, Address: 0x1029234 */
    *(int*)&pActwk->actfree[4] *= -1; /* Line 546, Address: 0x1029260 */
    pActwk->actflg ^= 1; /* Line 547, Address: 0x1029278 */
    pActwk->cddat ^= 1; /* Line 548, Address: 0x1029288 */
  }


} /* Line 552, Address: 0x1029298 */





void b_fly(sprite_status* pActwk) { /* Line 558, Address: 0x10292b0 */
  short xPos, idx;
  sprite_status *pMainwk, *pSubwk;

  pActwk->xposi.l += *(int*)&pActwk->actfree[4]; /* Line 562, Address: 0x10292cc */

  xPos = pActwk->xposi.w.h - ((short*)pActwk)[24]; /* Line 564, Address: 0x10292e8 */
  if (xPos < 0) { /* Line 565, Address: 0x102931c */
    xPos *= -1; /* Line 566, Address: 0x102932c */
  }


  if ((long int)(int)xPos >= 80) { /* Line 570, Address: 0x1029338 */
    pActwk->xposi.l -= *(int*)&pActwk->actfree[4]; /* Line 571, Address: 0x1029354 */
    *(int*)&pActwk->actfree[4] *= -1; /* Line 572, Address: 0x1029370 */
    pActwk->actflg ^= 1; /* Line 573, Address: 0x1029388 */
    pActwk->cddat ^= 1; /* Line 574, Address: 0x1029398 */
  }


  if (area(pActwk, &actwk[0], 65480, 112, 65456, 160) != 0) { /* Line 578, Address: 0x10293a8 */



    pMainwk = &actwk[((short*)pActwk)[23]]; /* Line 582, Address: 0x10293d4 */

    idx = ((short*)pMainwk)[28]; /* Line 584, Address: 0x10293fc */
    if (idx) { /* Line 585, Address: 0x1029408 */
      pSubwk = &actwk[idx]; /* Line 586, Address: 0x1029410 */
      pSubwk->r_no0 = 4; /* Line 587, Address: 0x1029430 */
    }


    idx = ((short*)pMainwk)[27]; /* Line 591, Address: 0x1029438 */
    if (idx) { /* Line 592, Address: 0x1029444 */
      pSubwk = &actwk[idx]; /* Line 593, Address: 0x102944c */
      pSubwk->r_no0 = 4; /* Line 594, Address: 0x102946c */
    }
  }




  b_com1(pActwk); /* Line 601, Address: 0x1029474 */
} /* Line 602, Address: 0x1029480 */





void b_near(sprite_status* pActwk) { /* Line 608, Address: 0x10294a0 */
  sprite_status *pMainwk, *pSubwk1, *pSubwk2;
  short idx, xwk, ywk;
  unsigned int flag1, flag2;
  int speedwk;

  idx = ((short*)pActwk)[23]; /* Line 614, Address: 0x10294d0 */
  pMainwk = &actwk[idx]; /* Line 615, Address: 0x10294e0 */

  if ((idx = ((short*)pMainwk)[28]) != 0) { /* Line 617, Address: 0x1029500 */
    pSubwk1 = &actwk[idx]; /* Line 618, Address: 0x102951c */

    if ((idx = ((short*)pMainwk)[27]) != 0) { /* Line 620, Address: 0x102953c */
      pSubwk2 = &actwk[idx]; /* Line 621, Address: 0x1029558 */
      flag1 = 0; /* Line 622, Address: 0x1029578 */

      xwk = (pSubwk1->xposi.w.h + pSubwk2->xposi.w.h >> 1) - scra_h_posit.w.h; /* Line 624, Address: 0x102957c */


      if (xwk < 152) { /* Line 627, Address: 0x10295c0 */

        pSubwk1->actflg |= 1; /* Line 629, Address: 0x10295d4 */
        pSubwk2->actflg |= 1; /* Line 630, Address: 0x10295e0 */
        pSubwk1->cddat |= 1; /* Line 631, Address: 0x10295ec */
        pSubwk2->cddat |= 1; /* Line 632, Address: 0x10295f8 */

        if ((speedwk = *(int*)&pActwk->actfree[4]) < 0) { /* Line 634, Address: 0x1029604 */
          speedwk = -speedwk; /* Line 635, Address: 0x1029618 */
        }


        pSubwk1->xposi.l += speedwk; /* Line 639, Address: 0x102961c */
        pSubwk2->xposi.l += speedwk; /* Line 640, Address: 0x1029628 */
      } else if (xwk > 168) { /* Line 641, Address: 0x1029634 */

        pSubwk1->actflg &= 254; /* Line 643, Address: 0x1029650 */
        pSubwk2->actflg &= 254; /* Line 644, Address: 0x102965c */
        pSubwk1->cddat &= 254; /* Line 645, Address: 0x1029668 */
        pSubwk2->cddat &= 254; /* Line 646, Address: 0x1029674 */

        if ((speedwk = *(int*)&pActwk->actfree[4]) < 0) { /* Line 648, Address: 0x1029680 */
          speedwk = -speedwk; /* Line 649, Address: 0x1029694 */
        }


        pSubwk1->xposi.l -= speedwk; /* Line 653, Address: 0x1029698 */
        pSubwk2->xposi.l -= speedwk; /* Line 654, Address: 0x10296a4 */
      } else { /* Line 655, Address: 0x10296b0 */
        flag1 = 1; /* Line 656, Address: 0x10296b8 */
      }


      flag2 = 0; /* Line 660, Address: 0x10296bc */

      ywk = (pSubwk1->yposi.w.h + pSubwk2->yposi.w.h >> 1) - scra_v_posit.w.h; /* Line 662, Address: 0x10296c0 */


      if (ywk < 104) { /* Line 665, Address: 0x1029704 */

        if ((speedwk = *(int*)&pActwk->actfree[4]) < 0) { /* Line 667, Address: 0x1029718 */
          speedwk = -speedwk; /* Line 668, Address: 0x102972c */
        }


        pSubwk1->yposi.l += speedwk; /* Line 672, Address: 0x1029730 */
        pSubwk2->yposi.l += speedwk; /* Line 673, Address: 0x102973c */
      } else if (ywk > 120) { /* Line 674, Address: 0x1029748 */

        if ((speedwk = *(int*)&pActwk->actfree[4]) < 0) { /* Line 676, Address: 0x1029764 */
          speedwk = -speedwk; /* Line 677, Address: 0x1029778 */
        }


        pSubwk1->yposi.l -= speedwk; /* Line 681, Address: 0x102977c */
        pSubwk2->yposi.l -= speedwk; /* Line 682, Address: 0x1029788 */
      } else { /* Line 683, Address: 0x1029794 */
        flag2 = 1; /* Line 684, Address: 0x102979c */
      }


      if (flag1 != 0 && flag2 != 0) { /* Line 688, Address: 0x10297a0 */
        pSubwk1->r_no0 = pSubwk2->r_no0 = 6; /* Line 689, Address: 0x10297b0 */
      }


      b_com1(pActwk); /* Line 693, Address: 0x10297c0 */
      return; /* Line 694, Address: 0x10297cc */
    }
  }


  pActwk->r_no0 += 2; /* Line 699, Address: 0x10297d4 */
  b_fix(pActwk); /* Line 700, Address: 0x10297e4 */
} /* Line 701, Address: 0x10297f0 */





void b_fix(sprite_status* pActwk) { /* Line 707, Address: 0x1029830 */
  short hwk, vwk;

  pActwk->r_no0 += 2; /* Line 710, Address: 0x1029844 */
  pActwk->sprhs = pActwk->sprhsize = 12; /* Line 711, Address: 0x1029854 */
  pActwk->sprvsize = 20; /* Line 712, Address: 0x102986c */
  pActwk->colino = 51; /* Line 713, Address: 0x1029878 */

  pActwk->actflg = 1; /* Line 715, Address: 0x1029884 */
  hwk = pActwk->xposi.w.h - scra_h_posit.w.h + 128; /* Line 716, Address: 0x1029890 */
  vwk = pActwk->yposi.w.h - scra_v_posit.w.h + 128; /* Line 717, Address: 0x10298c8 */



  pActwk->xposi.w.h = hwk; /* Line 721, Address: 0x1029900 */
  pActwk->yposi.w.h = vwk; /* Line 722, Address: 0x1029908 */

  b_fix1(pActwk); /* Line 724, Address: 0x1029910 */
} /* Line 725, Address: 0x102991c */





void b_fix1(sprite_status* pActwk) { /* Line 731, Address: 0x1029940 */
  patchg(pActwk, *(unsigned char***)&pActwk->actfree[8]); /* Line 732, Address: 0x102994c */
  actionsub(pActwk); /* Line 733, Address: 0x1029964 */
} /* Line 734, Address: 0x1029970 */





void b_start(sprite_status* pActwk) { /* Line 740, Address: 0x1029980 */
  short xwk, ywk;

  pActwk->r_no0 += 2; /* Line 743, Address: 0x1029994 */
  pActwk->mstno.w = 511; /* Line 744, Address: 0x10299a4 */

  pActwk->actflg = 4; /* Line 746, Address: 0x10299b0 */


  xwk = pActwk->xposi.w.h - 128 + scra_h_posit.w.h; /* Line 749, Address: 0x10299bc */
  ywk = pActwk->yposi.w.h - 128 + scra_v_posit.w.h; /* Line 750, Address: 0x10299f4 */

  pActwk->xposi.w.h = xwk; /* Line 752, Address: 0x1029a2c */
  pActwk->yposi.w.h = ywk; /* Line 753, Address: 0x1029a34 */

  b_com(pActwk); /* Line 755, Address: 0x1029a3c */
} /* Line 756, Address: 0x1029a48 */





void b_com(sprite_status* pActwk) { /* Line 762, Address: 0x1029a60 */
  patchg(pActwk, *(unsigned char***)&pActwk->actfree[8]); /* Line 763, Address: 0x1029a6c */
  b_com1(pActwk); /* Line 764, Address: 0x1029a84 */
} /* Line 765, Address: 0x1029a90 */





void b_com1(sprite_status* pActwk) { /* Line 771, Address: 0x1029aa0 */
  sprite_status* pMainwk;

  actionsub(pActwk); /* Line 774, Address: 0x1029ab0 */
  pMainwk = &actwk[((short*)pActwk)[23]]; /* Line 775, Address: 0x1029abc */
  frameout_s(pActwk); /* Line 776, Address: 0x1029ae4 */

  if (!pActwk->actno) { /* Line 778, Address: 0x1029af0 */
    b_die_v(pActwk, pMainwk); /* Line 779, Address: 0x1029b00 */
  }
} /* Line 781, Address: 0x1029b10 */





void b_kill_v(sprite_status* pActwk) { /* Line 787, Address: 0x1029b30 */
  sprite_status* pMainwk;

  pMainwk = &actwk[((short*)pActwk)[23]]; /* Line 790, Address: 0x1029b40 */
  frameout(pActwk); /* Line 791, Address: 0x1029b68 */
  b_die_v(pActwk, pMainwk); /* Line 792, Address: 0x1029b74 */
} /* Line 793, Address: 0x1029b84 */


void b_die_v(sprite_status* pActwk, sprite_status* pMainwk) { /* Line 796, Address: 0x1029ba0 */
  short idx;

  idx = ((short*)pMainwk)[28]; /* Line 799, Address: 0x1029bb0 */
  if (idx == (short)(pActwk - actwk)) { /* Line 800, Address: 0x1029bc0 */
    ((short*)pMainwk)[28] = 0; /* Line 801, Address: 0x1029c08 */
  } else { /* Line 802, Address: 0x1029c10 */
    ((short*)pMainwk)[27] = 0; /* Line 803, Address: 0x1029c18 */
  }
} /* Line 805, Address: 0x1029c20 */





void b_light(sprite_status* pActwk) { /* Line 811, Address: 0x1029c30 */
  pActwk->r_no0 += 2; /* Line 812, Address: 0x1029c3c */
  pActwk->mstno.w = 767; /* Line 813, Address: 0x1029c4c */
  if (!pActwk->userflag.b.h) { /* Line 814, Address: 0x1029c58 */
    b_make_c(pActwk); /* Line 815, Address: 0x1029c68 */
  }


  b_com(pActwk); /* Line 819, Address: 0x1029c74 */
} /* Line 820, Address: 0x1029c80 */





void b_up(sprite_status* pActwk) { /* Line 826, Address: 0x1029c90 */
  pActwk->r_no0 += 2; /* Line 827, Address: 0x1029c9c */
  pActwk->mstno.w = 1023; /* Line 828, Address: 0x1029cac */
  b_com(pActwk); /* Line 829, Address: 0x1029cb8 */
} /* Line 830, Address: 0x1029cc4 */





void b_up1(sprite_status* pActwk) { /* Line 836, Address: 0x1029ce0 */
  pActwk->yposi.w.h -= 2; /* Line 837, Address: 0x1029cec */
  if (!(pActwk->actflg & 128)) { /* Line 838, Address: 0x1029cfc */
    if ((long int)(actwk[0].yposi.w.h - pActwk->yposi.w.h) > 160) { /* Line 839, Address: 0x1029d14 */
      b_kill_v(pActwk); /* Line 840, Address: 0x1029d4c */
      return; /* Line 841, Address: 0x1029d58 */
    }
  }


  b_com(pActwk); /* Line 846, Address: 0x1029d60 */
} /* Line 847, Address: 0x1029d6c */





void b_make_c(sprite_status* pActwk) { /* Line 853, Address: 0x1029d80 */
  short idx1, idx2, xPos, xWk, yPos, yWk;
  sprite_status *pMainwk, *pSubwk1, *pSubwk2, *pNewact;
  int i;

  pMainwk = &actwk[((short*)pActwk)[23]]; /* Line 858, Address: 0x1029db0 */
  idx1 = ((short*)pMainwk)[28]; /* Line 859, Address: 0x1029dd8 */
  idx2 = ((short*)pMainwk)[27]; /* Line 860, Address: 0x1029de0 */
  if (!idx1 || !idx2) { /* Line 861, Address: 0x1029dec */

    return; /* Line 863, Address: 0x1029e00 */
  }

  pSubwk1 = &actwk[idx1]; /* Line 866, Address: 0x1029e08 */
  pSubwk2 = &actwk[idx2]; /* Line 867, Address: 0x1029e2c */
  if (pActwk == pSubwk1) { /* Line 868, Address: 0x1029e4c */




    if (!(pSubwk1->actflg & 128) || !(pSubwk2->actflg & 128)) { /* Line 873, Address: 0x1029e58 */

      return; /* Line 875, Address: 0x1029e80 */
    }

    xPos = pSubwk1->xposi.w.h; /* Line 878, Address: 0x1029e88 */
    yPos = pSubwk1->yposi.w.h; /* Line 879, Address: 0x1029e94 */
    xWk = pSubwk2->xposi.w.h; /* Line 880, Address: 0x1029ea0 */
    yWk = pSubwk2->yposi.w.h; /* Line 881, Address: 0x1029eac */
    xWk = xWk - xPos >> 2; /* Line 882, Address: 0x1029eb8 */
    yWk = yWk - yPos >> 2; /* Line 883, Address: 0x1029ee0 */
    yPos += 7; /* Line 884, Address: 0x1029f08 */
    for (i = 0; i < 3; ++i) { /* Line 885, Address: 0x1029f14 */
      if (actwkchk(&pNewact) != 0) return; /* Line 886, Address: 0x1029f20 */



      ((short*)pNewact)[24] = pSubwk1 - actwk; /* Line 890, Address: 0x1029f34 */

      ((short*)pNewact)[23] = pSubwk2 - actwk; /* Line 892, Address: 0x1029f68 */

      pNewact->actno = pSubwk1->actno; /* Line 894, Address: 0x1029f9c */
      pNewact->userflag.b.h = pSubwk1->userflag.b.h; /* Line 895, Address: 0x1029fa8 */
      pNewact->userflag.b.l = -2; /* Line 896, Address: 0x1029fb4 */
      pNewact->sproffset = pSubwk1->sproffset; /* Line 897, Address: 0x1029fc0 */
      xPos += xWk; /* Line 898, Address: 0x1029fcc */
      yPos += yWk; /* Line 899, Address: 0x1029fd8 */
      pNewact->xposi.w.h = xPos; /* Line 900, Address: 0x1029fe4 */
      pNewact->yposi.w.h = yPos; /* Line 901, Address: 0x1029fec */
    } /* Line 902, Address: 0x1029ff4 */
  }

} /* Line 905, Address: 0x102a004 */








void c_init(sprite_status* pActwk) { /* Line 914, Address: 0x102a040 */
  pActwk->r_no0 += 2; /* Line 915, Address: 0x102a04c */
  pActwk->actflg |= 4; /* Line 916, Address: 0x102a05c */
  pActwk->sprpri = 2; /* Line 917, Address: 0x102a06c */
  pActwk->sprhs = pActwk->sprhsize = 12; /* Line 918, Address: 0x102a078 */
  pActwk->sprvsize = 12; /* Line 919, Address: 0x102a090 */
  pActwk->colino = 180; /* Line 920, Address: 0x102a09c */
  pActwk->patbase = pat_tama; /* Line 921, Address: 0x102a0a8 */
  c_move(pActwk); /* Line 922, Address: 0x102a0b8 */
} /* Line 923, Address: 0x102a0c4 */





void c_move(sprite_status* pActwk) { /* Line 929, Address: 0x102a0e0 */
  patchg(pActwk, pchg_tama); /* Line 930, Address: 0x102a0ec */
  actionsub(pActwk); /* Line 931, Address: 0x102a100 */
} /* Line 932, Address: 0x102a10c */
























unsigned int area(sprite_status* pActwk, sprite_status* pPlayerwk, unsigned short Ypos, unsigned short Ylen, unsigned short Xpos, unsigned short Xlen) { /* Line 957, Address: 0x102a120 */
  unsigned short len;

  len = (unsigned short)pPlayerwk->yposi.w.h - (unsigned short)pActwk->yposi.w.h - Ypos; /* Line 960, Address: 0x102a140 */
  if (len >= Ylen) { /* Line 961, Address: 0x102a178 */
    return 0; /* Line 962, Address: 0x102a190 */
  }

  len = (unsigned short)pPlayerwk->xposi.w.h - (unsigned short)pActwk->xposi.w.h - Xpos; /* Line 965, Address: 0x102a19c */
  if (len >= Xlen) { /* Line 966, Address: 0x102a1d4 */
    return 0; /* Line 967, Address: 0x102a1ec */
  }

  return 1; /* Line 970, Address: 0x102a1f8 */
} /* Line 971, Address: 0x102a1fc */
