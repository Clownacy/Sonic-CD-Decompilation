#include "..\EQU.H"
#include "BOSS_4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\LOADER2.H"
#include "COL4A.H"
#include "PLAYSUB4.H"

typedef struct {
  char E4A_VEC;
  char E4A_ETC;
  short E4A_X;
  short E4A_Y;
}
E4A;

static unsigned int egg4air_ini(sprite_status* pActwk);
static void make_airhead(sprite_status* pActwk);
static unsigned int egg4air_01(sprite_status* pActwk);
static void egg4air_01_next(sprite_status* pActwk, E4A* pEscRoot);
static void egg4air_yure(sprite_status* pActwk);
static void egg4air_yurenai(sprite_status* pActwk);
static void egg4air_hitchk(sprite_status* pActwk);
static unsigned int egg4air_02(sprite_status* pActwk);
static unsigned int egg4air_03(sprite_status* pActwk);
static void egg4air_bom(sprite_status* pActwk);
static void e4a_03_far(sprite_status* pActwk);
static void e4a_03_most_near(sprite_status* pActwk);
static void e4a_03_near(sprite_status* pActwk);
static void e4a_03_normal(sprite_status* pActwk);
static void egg4_make_bom(sprite_status* pActwk);
static unsigned int egg4air_04(sprite_status* pActwk);
static void egg4airhead_ini(sprite_status* pActwk);
static void egg4airhead_01(sprite_status* pActwk);
static void egg4airhead_02(sprite_status* pActwk);
static void make_gate(sprite_status* pActwk);

static unsigned char air_pchg0[4] = { 3, 0, 1, 255 };
static unsigned char air_pchg1[4] = { 3, 2, 3, 255 };
static unsigned char air_pchg2[4] = { 3, 4, 5, 255 };
static unsigned char air_pchg3[4] = { 0, 6, 1, 255 };
static unsigned char air_pchg4[4] = { 0, 7, 3, 255 };
static unsigned char air_pchg5[4] = { 0, 8, 5, 255 };
static unsigned char* egg4air_pchg[6] = {
  air_pchg0,
  air_pchg1,
  air_pchg2,
  air_pchg3,
  air_pchg4,
  air_pchg5
};
static sprite_pattern air_pat00 = {
  1,
  { { -36, -28, 0, 439 } }
};
static sprite_pattern air_pat01 = {
  1,
  { { -36, -28, 0, 440 } }
};
static sprite_pattern air_pat02 = {
  1,
  { { -36, -28, 0, 441 } }
};
static sprite_pattern air_pat03 = {
  1,
  { { -36, -28, 0, 442 } }
};
static sprite_pattern air_pat04 = {
  1,
  { { -36, -28, 0, 443 } }
};
static sprite_pattern air_pat05 = {
  1,
  { { -36, -28, 0, 444 } }
};
static sprite_pattern air_pat06 = {
  1,
  { { -36, -28, 0, 445 } }
};
static sprite_pattern air_pat07 = {
  1,
  { { -36, -28, 0, 446 } }
};
static sprite_pattern air_pat08 = {
  1,
  { { -36, -28, 0, 447 } }
};
sprite_pattern* egg4air_pat[9] = {
  &air_pat00,
  &air_pat01,
  &air_pat02,
  &air_pat03,
  &air_pat04,
  &air_pat05,
  &air_pat06,
  &air_pat07,
  &air_pat08
};
static unsigned int(*e4a_act_tbl[5])(sprite_status*) = {
  &egg4air_ini,
  &egg4air_01,
  &egg4air_02,
  &egg4air_03,
  &egg4air_04
};
static E4A egg4_air_tbl1[19] = {
  { 5, 0, 1232, 1056 },
  { 7, 0, 1248, 1072 },
  { 5, 0, 1248, 1120 },
  { 0, 2, 1596, 1120 },
  { 5, 0, 1596, 1312 },
  { 1, 0, 1376, 1312 },
  { 5, 0, 1376, 1496 },
  { 7, 0, 1396, 1516 },
  { 5, 0, 1396, 2176 },
  { 5, 0, 1396,  296 },
  { 7, 0, 1528,  428 },
  { 0, 0, 1652,  428 },
  { 7, 0, 1732,  508 },
  { 5, 0, 1732,  624 },
  { 7, 0, 1764,  656 },
  { 5, 1, 1764,  688 },
  { 5, 0, 1764,  748 },
  { 6, 0, 1696,  816 },
  { 1, 0, 1232,  816 }
};
static E4A egg4_air_tbl2[3] = {
  { 0, 0, 1952, 688 },
  { 7, 0, 2000, 736 },
  { 0, 3, 2168, 736 }
};
static E4A egg4_air_tbl3[4] = {
  { 2, 0, 1596, 1088 },
  { 0, 0, 1856, 1088 },
  { 4, 0, 1956,  988 },
  { 0, 3, 2168,  988 }
};
static unsigned char head_pchg0[3] = { 255, 0, 255 };
static unsigned char head_pchg1[6] = { 3, 2, 1, 3, 1, 255 };
static unsigned char* egg4airhead_pchg[2] = {
  head_pchg0,
  head_pchg1
};
static sprite_pattern head_pat0 = {
  1,
  { { -12, -28, 0, 448 } }
};
static sprite_pattern head_pat1 = {
  1,
  { { -12, -28, 0, 449 } }
};
static sprite_pattern head_pat2 = {
  1,
  { { -12, -44, 0, 450 } }
};
static sprite_pattern head_pat3 = {
  1,
  { { -12, -44, 0, 451 } }
};
sprite_pattern* egg4airhead_pat[4] = {
  &head_pat0,
  &head_pat1,
  &head_pat2,
  &head_pat3
};
static void(*e4ahead_act_tbl[3])(sprite_status*) = {
  &egg4airhead_ini,
  &egg4airhead_01,
  &egg4airhead_02
};









































































































































void egg4air(sprite_status* pActwk) { /* Line 309, Address: 0x1020920 */
  if (e4a_act_tbl[pActwk->r_no0 / 2 ](pActwk) != 0) { /* Line 310, Address: 0x102092c */
    if (pActwk->actfree[3]) { /* Line 311, Address: 0x1020978 */

      --pActwk->actfree[3]; /* Line 313, Address: 0x1020988 */
      pActwk->mstno.b.h += 3; /* Line 314, Address: 0x1020998 */
      patchg(pActwk, egg4air_pchg); /* Line 315, Address: 0x10209a8 */
      pActwk->mstno.b.h -= 3; /* Line 316, Address: 0x10209bc */
    } /* Line 317, Address: 0x10209cc */
    else patchg(pActwk, egg4air_pchg); /* Line 318, Address: 0x10209d4 */


    actionsub(pActwk); /* Line 321, Address: 0x10209e8 */
  }
} /* Line 323, Address: 0x10209f4 */






static unsigned int egg4air_ini(sprite_status* pActwk) { /* Line 330, Address: 0x1020a10 */
  pActwk->colino = 61; /* Line 331, Address: 0x1020a1c */
  pActwk->colicnt = 5; /* Line 332, Address: 0x1020a28 */

  pActwk->cddat = 1; /* Line 334, Address: 0x1020a34 */
  pActwk->r_no0 = 8; /* Line 335, Address: 0x1020a40 */
  pActwk->actflg = 4; /* Line 336, Address: 0x1020a4c */
  pActwk->sprpri = 6; /* Line 337, Address: 0x1020a58 */
  pActwk->sprhsize = 36; /* Line 338, Address: 0x1020a64 */
  pActwk->sprvsize = 56; /* Line 339, Address: 0x1020a70 */
  pActwk->sproffset = 798; /* Line 340, Address: 0x1020a7c */
  pActwk->patbase = egg4air_pat; /* Line 341, Address: 0x1020a88 */

  ((int*)pActwk)[16] = 114688; /* Line 343, Address: 0x1020a98 */
  ((int*)pActwk)[4] = 81000; /* Line 344, Address: 0x1020aa8 */

  colorset2(5); /* Line 346, Address: 0x1020ab8 */
  make_airhead(pActwk); /* Line 347, Address: 0x1020ac4 */

  return 1; /* Line 349, Address: 0x1020ad0 */
} /* Line 350, Address: 0x1020ad4 */





static void make_airhead(sprite_status* pActwk) { /* Line 356, Address: 0x1020af0 */
  sprite_status* pNewact;

  if (actwkchk(&pNewact) == 0) { /* Line 359, Address: 0x1020afc */
    ((short*)pActwk)[26] = pNewact - actwk; /* Line 360, Address: 0x1020b10 */
    ((short*)pNewact)[26] = pActwk - actwk; /* Line 361, Address: 0x1020b48 */
    pNewact->actno = 75; /* Line 362, Address: 0x1020b80 */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 363, Address: 0x1020b8c */
    pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 364, Address: 0x1020b9c */
  }
} /* Line 366, Address: 0x1020bac */






static unsigned int egg4air_01(sprite_status* pActwk) { /* Line 373, Address: 0x1020bc0 */
  E4A* pEscRoot;
  int flg;
  int spdwk;

  pActwk->yposi.w.h -= ((short*)pActwk)[30]; /* Line 378, Address: 0x1020bd8 */

  egg4air_hitchk(pActwk); /* Line 380, Address: 0x1020bf0 */

  if (pActwk->r_no1 & 128) { /* Line 382, Address: 0x1020bfc */
    pEscRoot = egg4_air_tbl2; /* Line 383, Address: 0x1020c14 */
  } else if (pActwk->r_no1 & 64) { /* Line 384, Address: 0x1020c20 */
    pEscRoot = egg4_air_tbl3; /* Line 385, Address: 0x1020c40 */
  } else { /* Line 386, Address: 0x1020c4c */
    pEscRoot = egg4_air_tbl1; /* Line 387, Address: 0x1020c54 */
  }


  pEscRoot += pActwk->r_no1 & 63; /* Line 391, Address: 0x1020c60 */

  switch (pEscRoot->E4A_VEC) { /* Line 393, Address: 0x1020c80 */

    case 0:
      pActwk->mstno.b.h = 1; /* Line 396, Address: 0x1020cb4 */
      pActwk->cddat &= 254; /* Line 397, Address: 0x1020cc0 */
      pActwk->xposi.l += ((int*)pActwk)[16]; /* Line 398, Address: 0x1020cd0 */

      if (pActwk->xposi.w.h < pEscRoot->E4A_X) { /* Line 400, Address: 0x1020ce8 */
        egg4air_yure(pActwk); /* Line 401, Address: 0x1020d10 */
      } else { /* Line 402, Address: 0x1020d1c */
        egg4air_01_next(pActwk, pEscRoot); /* Line 403, Address: 0x1020d24 */
      }

      break; /* Line 406, Address: 0x1020d34 */


    case 1:
      pActwk->mstno.b.h = 1; /* Line 410, Address: 0x1020d3c */
      pActwk->cddat |= 1; /* Line 411, Address: 0x1020d48 */
      pActwk->xposi.l -= ((int*)pActwk)[16]; /* Line 412, Address: 0x1020d58 */

      if (pActwk->xposi.w.h > pEscRoot->E4A_X) { /* Line 414, Address: 0x1020d70 */
        egg4air_yure(pActwk); /* Line 415, Address: 0x1020d98 */
      } else { /* Line 416, Address: 0x1020da4 */
        egg4air_01_next(pActwk, pEscRoot); /* Line 417, Address: 0x1020dac */
      }

      break; /* Line 420, Address: 0x1020dbc */


    case 2:
      pActwk->mstno.b.h = 0; /* Line 424, Address: 0x1020dc4 */
      pActwk->yposi.l += ((int*)pActwk)[16]; /* Line 425, Address: 0x1020dcc */

      if (pActwk->yposi.w.h < pEscRoot->E4A_Y) { /* Line 427, Address: 0x1020de4 */
        egg4air_yurenai(pActwk); /* Line 428, Address: 0x1020e0c */
        break; /* Line 429, Address: 0x1020e18 */
      } else if (pEscRoot->E4A_Y != 2176) { /* Line 430, Address: 0x1020e20 */
        pActwk->yposi.w.h = pEscRoot->E4A_Y; /* Line 431, Address: 0x1020e38 */
      } else { /* Line 432, Address: 0x1020e44 */
        pActwk->yposi.w.h = 128; /* Line 433, Address: 0x1020e4c */
      }

      egg4air_01_next(pActwk, pEscRoot); /* Line 436, Address: 0x1020e58 */


      break; /* Line 439, Address: 0x1020e68 */


    case 3:
      pActwk->mstno.b.h = 2; /* Line 443, Address: 0x1020e70 */
      pActwk->cddat |= 1; /* Line 444, Address: 0x1020e7c */

      flg = 0; /* Line 446, Address: 0x1020e8c */

      spdwk = ((int*)pActwk)[4]; /* Line 448, Address: 0x1020e90 */
      pActwk->yposi.l += spdwk; /* Line 449, Address: 0x1020e98 */
      if (pActwk->yposi.w.h >= pEscRoot->E4A_Y) { /* Line 450, Address: 0x1020ea8 */
        pActwk->yposi.w.h = pEscRoot->E4A_Y; /* Line 451, Address: 0x1020ed0 */
        ++flg; /* Line 452, Address: 0x1020edc */
      }


      pActwk->xposi.l -= spdwk; /* Line 456, Address: 0x1020ee0 */
      if (pActwk->xposi.w.h <= pEscRoot->E4A_X) { /* Line 457, Address: 0x1020ef0 */
        pActwk->xposi.w.h = pEscRoot->E4A_X; /* Line 458, Address: 0x1020f18 */
        ++flg; /* Line 459, Address: 0x1020f24 */
      }


      if (flg == 2) { /* Line 463, Address: 0x1020f28 */
        egg4air_01_next(pActwk, pEscRoot); /* Line 464, Address: 0x1020f34 */
      } else { /* Line 465, Address: 0x1020f44 */
        egg4air_yurenai(pActwk); /* Line 466, Address: 0x1020f4c */
      }

      break; /* Line 469, Address: 0x1020f58 */


    case 4:
      pActwk->mstno.b.h = 2; /* Line 473, Address: 0x1020f60 */
      pActwk->cddat &= 254; /* Line 474, Address: 0x1020f6c */

      flg = 0; /* Line 476, Address: 0x1020f7c */

      spdwk = ((int*)pActwk)[4]; /* Line 478, Address: 0x1020f80 */
      pActwk->yposi.l += spdwk; /* Line 479, Address: 0x1020f88 */
      if (pActwk->yposi.w.h >= pEscRoot->E4A_Y) { /* Line 480, Address: 0x1020f98 */
        pActwk->yposi.w.h = pEscRoot->E4A_Y; /* Line 481, Address: 0x1020fc0 */
        ++flg; /* Line 482, Address: 0x1020fcc */
      }


      pActwk->xposi.l += spdwk; /* Line 486, Address: 0x1020fd0 */
      if (pActwk->xposi.w.h >= pEscRoot->E4A_X) { /* Line 487, Address: 0x1020fe0 */
        pActwk->xposi.w.h = pEscRoot->E4A_X; /* Line 488, Address: 0x1021008 */
        ++flg; /* Line 489, Address: 0x1021014 */
      }


      if (flg == 2) { /* Line 493, Address: 0x1021018 */
        egg4air_01_next(pActwk, pEscRoot); /* Line 494, Address: 0x1021024 */
      } else { /* Line 495, Address: 0x1021034 */
        egg4air_yurenai(pActwk); /* Line 496, Address: 0x102103c */
      }

      break; /* Line 499, Address: 0x1021048 */


    case 5:
      pActwk->mstno.b.h = 0; /* Line 503, Address: 0x1021050 */
      pActwk->yposi.l -= ((int*)pActwk)[16]; /* Line 504, Address: 0x1021058 */

      if (pActwk->yposi.w.h > pEscRoot->E4A_Y) { /* Line 506, Address: 0x1021070 */
        egg4air_yurenai(pActwk); /* Line 507, Address: 0x1021098 */
        break; /* Line 508, Address: 0x10210a4 */
      } else if (pEscRoot->E4A_Y != 65344) { /* Line 509, Address: 0x10210ac */
        pActwk->yposi.w.h = pEscRoot->E4A_Y; /* Line 510, Address: 0x10210c4 */
      } else { /* Line 511, Address: 0x10210d0 */
        pActwk->yposi.w.h = 1856; /* Line 512, Address: 0x10210d8 */
      }

      egg4air_01_next(pActwk, pEscRoot); /* Line 515, Address: 0x10210e4 */


      break; /* Line 518, Address: 0x10210f4 */


    case 6:
      pActwk->mstno.b.h = 2; /* Line 522, Address: 0x10210fc */
      pActwk->cddat |= 1; /* Line 523, Address: 0x1021108 */

      flg = 0; /* Line 525, Address: 0x1021118 */

      spdwk = ((int*)pActwk)[16]; /* Line 527, Address: 0x102111c */
      pActwk->yposi.l -= spdwk; /* Line 528, Address: 0x1021124 */
      if (pActwk->yposi.w.h <= pEscRoot->E4A_Y) { /* Line 529, Address: 0x1021134 */
        pActwk->yposi.w.h = pEscRoot->E4A_Y; /* Line 530, Address: 0x102115c */
        ++flg; /* Line 531, Address: 0x1021168 */
      }


      pActwk->xposi.l -= spdwk; /* Line 535, Address: 0x102116c */
      if (pActwk->xposi.w.h <= pEscRoot->E4A_X) { /* Line 536, Address: 0x102117c */
        pActwk->xposi.w.h = pEscRoot->E4A_X; /* Line 537, Address: 0x10211a4 */
        ++flg; /* Line 538, Address: 0x10211b0 */
      }


      if (flg == 2) { /* Line 542, Address: 0x10211b4 */
        egg4air_01_next(pActwk, pEscRoot); /* Line 543, Address: 0x10211c0 */
      } else { /* Line 544, Address: 0x10211d0 */
        egg4air_yurenai(pActwk); /* Line 545, Address: 0x10211d8 */
      }

      break; /* Line 548, Address: 0x10211e4 */


    case 7:
      flg = 0; /* Line 552, Address: 0x10211ec */

      spdwk = ((int*)pActwk)[16]; /* Line 554, Address: 0x10211f0 */
      pActwk->yposi.l -= spdwk; /* Line 555, Address: 0x10211f8 */
      if (pActwk->yposi.w.h <= pEscRoot->E4A_Y) { /* Line 556, Address: 0x1021208 */
        pActwk->yposi.w.h = pEscRoot->E4A_Y; /* Line 557, Address: 0x1021230 */
        ++flg; /* Line 558, Address: 0x102123c */
      }


      pActwk->xposi.l += spdwk; /* Line 562, Address: 0x1021240 */
      if (pActwk->xposi.w.h >= pEscRoot->E4A_X) { /* Line 563, Address: 0x1021250 */
        pActwk->xposi.w.h = pEscRoot->E4A_X; /* Line 564, Address: 0x1021278 */
        ++flg; /* Line 565, Address: 0x1021284 */
      }


      pActwk->mstno.b.h = 2; /* Line 569, Address: 0x1021288 */
      pActwk->cddat &= 254; /* Line 570, Address: 0x1021294 */
      if (flg == 2) { /* Line 571, Address: 0x10212a4 */
        egg4air_01_next(pActwk, pEscRoot); /* Line 572, Address: 0x10212b0 */
      } else { /* Line 573, Address: 0x10212c0 */
        egg4air_yurenai(pActwk); /* Line 574, Address: 0x10212c8 */
      }

      break;
  }




  return 1; /* Line 583, Address: 0x10212d4 */
} /* Line 584, Address: 0x10212dc */




static void egg4air_01_next(sprite_status* pActwk, E4A* pEscRoot) { /* Line 589, Address: 0x1021300 */
  short actidx;

  if (!pEscRoot->E4A_ETC || pActwk->colicnt) { /* Line 592, Address: 0x1021310 */

    ++pActwk->r_no1; /* Line 594, Address: 0x1021330 */
    if ((pActwk->r_no1 & 63) > 18) { /* Line 595, Address: 0x1021340 */
      pActwk->r_no1 &= 192; /* Line 596, Address: 0x102135c */
    }
  } /* Line 598, Address: 0x102136c */
  else {
    if (pEscRoot->E4A_ETC == 1) { /* Line 600, Address: 0x1021374 */

      pActwk->r_no1 = 128; /* Line 602, Address: 0x1021390 */

      if ((actidx = ((short*)pActwk)[26]) != 0) { /* Line 604, Address: 0x102139c */
        if ((actidx = ((short*)&actwk[actidx])[27]) != 0) { /* Line 605, Address: 0x10213bc */
          actwk[actidx].actfree[21] = 1; /* Line 606, Address: 0x10213f8 */
        }
      }
    } else if (pEscRoot->E4A_ETC == 2) { /* Line 609, Address: 0x1021420 */

      pActwk->r_no1 = 64; /* Line 611, Address: 0x1021444 */

      if ((actidx = ((short*)pActwk)[26]) != 0) { /* Line 613, Address: 0x1021450 */
        if ((actidx = ((short*)&actwk[actidx])[28]) != 0) { /* Line 614, Address: 0x1021470 */
          actwk[actidx].actfree[21] = 1; /* Line 615, Address: 0x10214ac */
        }
      }
    } else { /* Line 618, Address: 0x10214d4 */

      ((int*)pActwk)[16] = 229376; /* Line 620, Address: 0x10214dc */
      pActwk->r_no0 = 4; /* Line 621, Address: 0x10214ec */
      pActwk->mstno.b.h = 0; /* Line 622, Address: 0x10214f8 */
    }
  }
} /* Line 625, Address: 0x1021500 */





static void egg4air_yure(sprite_status* pActwk) { /* Line 631, Address: 0x1021510 */
  short sinwk, coswk;

  pActwk->actfree[5] += 2; /* Line 634, Address: 0x102151c */
  sinset(pActwk->actfree[5], &sinwk, &coswk); /* Line 635, Address: 0x102152c */
  sinwk >>= 5; /* Line 636, Address: 0x1021544 */
  ((short*)pActwk)[30] = sinwk; /* Line 637, Address: 0x1021550 */
  pActwk->yposi.w.h += sinwk; /* Line 638, Address: 0x102155c */
} /* Line 639, Address: 0x1021570 */





static void egg4air_yurenai(sprite_status* pActwk) { /* Line 645, Address: 0x1021580 */
  pActwk->yposi.w.h += ((short*)pActwk)[30]; /* Line 646, Address: 0x1021588 */
} /* Line 647, Address: 0x10215a0 */





static void egg4air_hitchk(sprite_status* pActwk) { /* Line 653, Address: 0x10215b0 */
  short actidx;

  if (pActwk->actfree[2] && !(--pActwk->actfree[2])) { /* Line 656, Address: 0x10215c0 */
    ((int*)pActwk)[16] = 114688; /* Line 657, Address: 0x10215ec */
    ((int*)pActwk)[4] = 81000; /* Line 658, Address: 0x10215fc */
  }


  if (!pActwk->colicnt) return; /* Line 662, Address: 0x102160c */




  if (pActwk->actfree[1]) { /* Line 667, Address: 0x102161c */

    if (--pActwk->actfree[1] == 0) { /* Line 669, Address: 0x102162c */
      pActwk->colino = 61; /* Line 670, Address: 0x102164c */
    }

    return; /* Line 673, Address: 0x1021658 */
  }

  if (!pActwk->colino) { /* Line 676, Address: 0x1021660 */




    soundset(172); /* Line 681, Address: 0x1021670 */


    if ((actidx = ((short*)pActwk)[26]) != 0) { /* Line 684, Address: 0x102167c */
      actwk[actidx].actfree[0] = 40; /* Line 685, Address: 0x102169c */
      pActwk->actfree[2] = 70; /* Line 686, Address: 0x10216c4 */
      ((int*)pActwk)[16] = 294912; /* Line 687, Address: 0x10216d0 */
      ((int*)pActwk)[4] = 208000; /* Line 688, Address: 0x10216e0 */

      pActwk->actfree[3] = 16; /* Line 690, Address: 0x10216f0 */
      if (pActwk->colicnt == 1) { /* Line 691, Address: 0x10216fc */

        pActwk->r_no0 = 6; /* Line 693, Address: 0x1021714 */
        pActwk->colicnt = 0; /* Line 694, Address: 0x1021720 */
      } /* Line 695, Address: 0x1021728 */
      else pActwk->actfree[1] = 30; /* Line 696, Address: 0x1021730 */
    }
  }
} /* Line 699, Address: 0x102173c */






static unsigned int egg4air_02(sprite_status* pActwk) { /* Line 706, Address: 0x1021750 */
  short actidx;

  pActwk->yposi.l += ((int*)pActwk)[16]; /* Line 709, Address: 0x1021760 */
  ((int*)pActwk)[16] += 12288; /* Line 710, Address: 0x1021778 */

  if (pActwk->yposi.w.h >= 1408) { /* Line 712, Address: 0x1021788 */
    if ((actidx = ((short*)pActwk)[26]) != 0) { /* Line 713, Address: 0x10217a4 */
      actwk[actidx].r_no0 += 2; /* Line 714, Address: 0x10217c4 */
    }



    frameout(pActwk); /* Line 719, Address: 0x10217f0 */
    return 0; /* Line 720, Address: 0x10217fc */
  }

  return 1; /* Line 723, Address: 0x1021808 */
} /* Line 724, Address: 0x102180c */






static unsigned int egg4air_03(sprite_status* pActwk) { /* Line 731, Address: 0x1021820 */
  int_union xwk, ywk;

  egg4air_bom(pActwk); /* Line 734, Address: 0x102182c */

  xwk.l = ywk.l = 0; /* Line 736, Address: 0x1021838 */
  xwk.w.l = actwk[0].xposi.w.h - pActwk->xposi.w.h; /* Line 737, Address: 0x1021840 */
  if (xwk.w.l < 0) { /* Line 738, Address: 0x1021870 */
    xwk.w.l = -xwk.w.l; /* Line 739, Address: 0x1021884 */
  }


  ywk.w.l = actwk[0].yposi.w.h - pActwk->yposi.w.h; /* Line 743, Address: 0x10218a0 */
  if (ywk.w.l < 0) { /* Line 744, Address: 0x10218d0 */
    ywk.w.l = -ywk.w.l; /* Line 745, Address: 0x10218e4 */
  }


  xwk.l *= xwk.l; /* Line 749, Address: 0x1021900 */
  ywk.l *= ywk.l; /* Line 750, Address: 0x1021910 */
  xwk.l += ywk.l; /* Line 751, Address: 0x1021920 */

  if (pActwk->actfree[4] & 32) { /* Line 753, Address: 0x1021930 */

    if ((long int)xwk.l >= 20736) { /* Line 755, Address: 0x1021948 */
      e4a_03_far(pActwk); /* Line 756, Address: 0x1021960 */
      return 1; /* Line 757, Address: 0x102196c */
    }
    pActwk->actfree[4] &= 223; /* Line 759, Address: 0x1021978 */
  }



  if ((long int)xwk.l >= 69696) { /* Line 764, Address: 0x1021988 */
    e4a_03_far(pActwk); /* Line 765, Address: 0x10219a8 */
  } else if ((long int)xwk.l < 7744) { /* Line 766, Address: 0x10219b4 */
    e4a_03_most_near(pActwk); /* Line 767, Address: 0x10219d4 */
  } else if ((long int)xwk.l < 18496) { /* Line 768, Address: 0x10219e0 */
    e4a_03_near(pActwk); /* Line 769, Address: 0x1021a00 */
  } else { /* Line 770, Address: 0x1021a0c */
    e4a_03_normal(pActwk); /* Line 771, Address: 0x1021a14 */
  }

  return 1; /* Line 774, Address: 0x1021a20 */
} /* Line 775, Address: 0x1021a24 */





static void egg4air_bom(sprite_status* pActwk) { /* Line 781, Address: 0x1021a40 */
  short actidx;

  if ((actidx = ((short*)pActwk)[26]) != 0) { /* Line 784, Address: 0x1021a50 */
    actwk[actidx].actfree[0] = 30; /* Line 785, Address: 0x1021a70 */
  }

  if (!pActwk->actfree[0]) { /* Line 788, Address: 0x1021a98 */
    pActwk->actfree[0] = 32; /* Line 789, Address: 0x1021aa8 */
    egg4_make_bom(pActwk); /* Line 790, Address: 0x1021ab4 */
  }


  --pActwk->actfree[0]; /* Line 794, Address: 0x1021ac0 */
} /* Line 795, Address: 0x1021ad0 */





static void e4a_03_far(sprite_status* pActwk) { /* Line 801, Address: 0x1021af0 */

  pActwk->actfree[4] |= 32; /* Line 803, Address: 0x1021afc */

  pActwk->yposi.w.h -= ((short*)pActwk)[30]; /* Line 805, Address: 0x1021b0c */
  pActwk->mstno.b.h = 0; /* Line 806, Address: 0x1021b24 */
  egg4air_yure(pActwk); /* Line 807, Address: 0x1021b2c */
} /* Line 808, Address: 0x1021b38 */





static void e4a_03_most_near(sprite_status* pActwk) { /* Line 814, Address: 0x1021b50 */
  if ((long int)(int)pActwk->yspeed.w > 2048 || (long int)(int)pActwk->xspeed.w > 2048) { /* Line 815, Address: 0x1021b5c */


    ((int*)pActwk)[16] = 0x100000; /* Line 818, Address: 0x1021ba4 */
    ((int*)pActwk)[4] = 741000; /* Line 819, Address: 0x1021bb0 */
  } else {/* Line 820, Address: 0x1021bc0 */
    ((int*)pActwk)[16] = 524288; /* Line 821, Address: 0x1021bc8 */
    ((int*)pActwk)[4] = 370000; /* Line 822, Address: 0x1021bd4 */
  }


  egg4air_01(pActwk); /* Line 826, Address: 0x1021be4 */
} /* Line 827, Address: 0x1021bf0 */





static void e4a_03_near(sprite_status* pActwk) { /* Line 833, Address: 0x1021c00 */
  ((int*)pActwk)[16] = 196608; /* Line 834, Address: 0x1021c0c */
  ((int*)pActwk)[4] = 139000; /* Line 835, Address: 0x1021c18 */


  egg4air_01(pActwk); /* Line 838, Address: 0x1021c28 */
} /* Line 839, Address: 0x1021c34 */





static void e4a_03_normal(sprite_status* pActwk) { /* Line 845, Address: 0x1021c50 */
  ((int*)pActwk)[16] = 114688; /* Line 846, Address: 0x1021c5c */
  ((int*)pActwk)[4] = 81000; /* Line 847, Address: 0x1021c6c */


  egg4air_01(pActwk); /* Line 850, Address: 0x1021c7c */
} /* Line 851, Address: 0x1021c88 */





static void egg4_make_bom(sprite_status* pActwk) { /* Line 857, Address: 0x1021ca0 */
  sprite_status* pNewact;

  if (actwkchk(&pNewact) == 0) { /* Line 860, Address: 0x1021cac */
    pNewact->r_no1 = 1; /* Line 861, Address: 0x1021cc0 */
    pNewact->actno = 24; /* Line 862, Address: 0x1021ccc */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 863, Address: 0x1021cd8 */
    pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 864, Address: 0x1021ce8 */
    soundset(158); /* Line 865, Address: 0x1021cf8 */
  }
} /* Line 867, Address: 0x1021d04 */






static unsigned int egg4air_04(sprite_status* pActwk) { /* Line 874, Address: 0x1021d20 */
  if (actwk[0].xposi.w.h >= 1144) { /* Line 875, Address: 0x1021d28 */
    pActwk->r_no0 = 2; /* Line 876, Address: 0x1021d44 */

    bossstart = 4; /* Line 878, Address: 0x1021d50 */
    ((int*)pActwk)[4] = 208000; /* Line 879, Address: 0x1021d5c */
  }


  return 1; /* Line 883, Address: 0x1021d6c */
} /* Line 884, Address: 0x1021d70 */



























































void egg4airhead(sprite_status* pActwk) { /* Line 944, Address: 0x1021d80 */
  e4ahead_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 945, Address: 0x1021d8c */
} /* Line 946, Address: 0x1021dd0 */





static void egg4airhead_ini(sprite_status* pActwk) { /* Line 952, Address: 0x1021de0 */
  pActwk->r_no0 += 2; /* Line 953, Address: 0x1021dec */
  pActwk->actflg = 4; /* Line 954, Address: 0x1021dfc */
  pActwk->sprpri = 6; /* Line 955, Address: 0x1021e08 */
  pActwk->sprhsize = 36; /* Line 956, Address: 0x1021e14 */
  pActwk->sprvsize = 56; /* Line 957, Address: 0x1021e20 */
  pActwk->sproffset = 798; /* Line 958, Address: 0x1021e2c */
  pActwk->patbase = egg4airhead_pat; /* Line 959, Address: 0x1021e38 */
  make_gate(pActwk); /* Line 960, Address: 0x1021e48 */
} /* Line 961, Address: 0x1021e54 */





static void egg4airhead_01(sprite_status* pActwk) { /* Line 967, Address: 0x1021e70 */
  short actidx;

  if (pActwk->actfree[0]) { /* Line 970, Address: 0x1021e80 */
    if (!(--pActwk->actfree[0])) { /* Line 971, Address: 0x1021e90 */

      pActwk->mstno.b.h = 0; /* Line 973, Address: 0x1021eac */
      pActwk->patno = 0; /* Line 974, Address: 0x1021eb4 */
      pActwk->patcnt = 0; /* Line 975, Address: 0x1021ebc */
      pActwk->pattim = 0; /* Line 976, Address: 0x1021ec4 */
      pActwk->pattimm = 0; /* Line 977, Address: 0x1021ecc */
    } /* Line 978, Address: 0x1021ed4 */
    else pActwk->mstno.b.h = 1; /* Line 979, Address: 0x1021edc */
  }



  if ((actidx = ((short*)pActwk)[26]) != 0) { /* Line 984, Address: 0x1021ee8 */
    pActwk->xposi.w.h = actwk[actidx].xposi.w.h; /* Line 985, Address: 0x1021f08 */
    pActwk->yposi.w.h = actwk[actidx].yposi.w.h; /* Line 986, Address: 0x1021f34 */
    pActwk->cddat = actwk[actidx].cddat; /* Line 987, Address: 0x1021f60 */
  }

  patchg(pActwk, egg4airhead_pchg); /* Line 990, Address: 0x1021f8c */
  actionsub(pActwk); /* Line 991, Address: 0x1021fa0 */
} /* Line 992, Address: 0x1021fac */





static void egg4airhead_02(sprite_status* pActwk) { /* Line 998, Address: 0x1021fc0 */
  short actidx;

  if (actwk[0].xposi.w.h >= 2112 && actwk[0].yposi.w.h >= 1360) { /* Line 1001, Address: 0x1021fd0 */
    bossflag = 4; /* Line 1002, Address: 0x1022008 */

    if ((actidx = ((short*)pActwk)[27]) != 0) { /* Line 1004, Address: 0x1022014 */
      if (actwk[actidx].actno) { /* Line 1005, Address: 0x1022034 */
        frameout(&actwk[actidx]); /* Line 1006, Address: 0x1022060 */
      }
    }


    if ((actidx = ((short*)pActwk)[28]) != 0) { /* Line 1011, Address: 0x1022088 */
      if (actwk[actidx].actno) { /* Line 1012, Address: 0x10220a8 */
        frameout(&actwk[actidx]); /* Line 1013, Address: 0x10220d4 */
      }
    }


    frameout(pActwk); /* Line 1018, Address: 0x10220fc */
  }
} /* Line 1020, Address: 0x1022108 */





static void make_gate(sprite_status* pActwk) { /* Line 1026, Address: 0x1022120 */
  sprite_status* pNewact;

  if (actwkchk(&pNewact) == 0) { /* Line 1029, Address: 0x102212c */
    ((short*)pActwk)[27] = pNewact - actwk; /* Line 1030, Address: 0x1022140 */
    pNewact->actno = 71; /* Line 1031, Address: 0x1022178 */
    pNewact->userflag.b.h = 1; /* Line 1032, Address: 0x1022184 */
    pNewact->xposi.w.h = 1888; /* Line 1033, Address: 0x1022190 */
    pNewact->yposi.w.h = 704; /* Line 1034, Address: 0x102219c */

    if (actwkchk(&pNewact) == 0) { /* Line 1036, Address: 0x10221a8 */
      ((short*)pActwk)[28] = pNewact - actwk; /* Line 1037, Address: 0x10221bc */
      pNewact->actno = 71; /* Line 1038, Address: 0x10221f4 */
      pNewact->userflag.b.h = 1; /* Line 1039, Address: 0x1022200 */
      pNewact->xposi.w.h = 1728; /* Line 1040, Address: 0x102220c */
      pNewact->yposi.w.h = 1120; /* Line 1041, Address: 0x1022218 */
    }
  }


} /* Line 1046, Address: 0x1022224 */
