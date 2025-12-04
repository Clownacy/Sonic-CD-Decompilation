#include "..\EQU.H"
#include "KABASIRA.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static void act_init(sprite_status* pActwk);
static void act_init_sub(sprite_status* pActwk);
static void act_move(sprite_status* pActwk);
static unsigned int kabasira_area(sprite_status* pActwk, sprite_status* pPlayerwk, short* pX, short* pY);

static unsigned char pchg_00[18] = { 15, 4, 5, 6, 7, 8, 9, 10, 11, 10, 11, 0, 1, 2, 3, 4, 5, 255 };
static unsigned char pchg_01[130] = {
  0, 4, 12, 4, 12, 4, 12, 4, 12, 5,
  12, 5, 12, 5, 12, 5, 12, 4, 12, 4,
  12, 4, 12, 4, 12, 5, 12, 5, 12, 5,
  12, 5, 12, 6, 12, 6, 12, 6, 12, 6,
  12, 7, 12, 7, 12, 7, 12, 7, 12, 8,
  12, 8, 12, 8, 12, 8, 12, 9, 12, 9,
  12, 9, 12, 9, 12, 10, 12, 10, 12, 10,
  12, 10, 12, 11, 12, 11, 12, 11, 12, 11,
  12, 10, 12, 10, 12, 10, 12, 10, 12, 11,
  12, 11, 12, 11, 12, 11, 12, 0, 12, 0,
  12, 0, 12, 0, 12, 1, 12, 1, 12, 1,
  12, 1, 12, 2, 12, 2, 12, 2, 12, 2,
  12, 3, 12, 3, 12, 3, 12, 3, 12, 255
};
static unsigned char pchg_02[130] = {
  0, 2, 12, 12, 12, 2, 12, 12, 12, 3,
  12, 12, 12, 3, 12, 12, 12, 4, 12, 12,
  12, 4, 12, 12, 12, 5, 12, 12, 12, 5,
  12, 12, 12, 4, 12, 12, 12, 4, 12, 12,
  12, 5, 12, 12, 12, 5, 12, 12, 12, 6,
  12, 12, 12, 6, 12, 12, 12, 7, 12, 12,
  12, 7, 12, 12, 12, 8, 12, 12, 12, 8,
  12, 12, 12, 9, 12, 12, 12, 9, 12, 12,
  12, 10, 12, 12, 12, 10, 12, 12, 12, 11,
  12, 12, 12, 11, 12, 12, 12, 10, 12, 12,
  12, 10, 12, 12, 12, 11, 12, 12, 12, 11,
  12, 12, 12, 0, 12, 12, 12, 0, 12, 12,
  12, 1, 12, 12, 12, 1, 12, 12, 12, 255
};
static unsigned char pchg_03[130] = {
  0, 0, 12, 12, 12, 12, 12, 12, 12, 1,
  12, 12, 12, 12, 12, 12, 12, 2, 12, 12,
  12, 12, 12, 12, 12, 3, 12, 12, 12, 12,
  12, 12, 12, 4, 12, 12, 12, 12, 12, 12,
  12, 5, 12, 12, 12, 12, 12, 12, 12, 4,
  12, 12, 12, 12, 12, 12, 12, 5, 12, 12,
  12, 12, 12, 12, 12, 6, 12, 12, 12, 12,
  12, 12, 12, 7, 12, 12, 12, 12, 12, 12,
  12, 8, 12, 12, 12, 12, 12, 12, 12, 9,
  12, 12, 12, 12, 12, 12, 12, 10, 12, 12,
  12, 12, 12, 12, 12, 11, 12, 12, 12, 12,
  12, 12, 12, 10, 12, 12, 12, 12, 12, 12,
  12, 11, 12, 12, 12, 12, 12, 12, 12, 255
};
static unsigned char pchg_04[18] = { 7, 4, 5, 6, 7, 8, 9, 10, 11, 10, 11, 0, 1, 2, 3, 4, 5, 255 };
static unsigned char pchg_05[66] = {
  0, 5, 12, 5, 12, 4, 12, 4, 12, 5,
  12, 5, 12, 6, 12, 6, 12, 7, 12, 7,
  12, 8, 12, 8, 12, 9, 12, 9, 12, 10,
  12, 10, 12, 11, 12, 11, 12, 10, 12, 10,
  12, 11, 12, 11, 12, 0, 12, 0, 12, 1,
  12, 1, 12, 2, 12, 2, 12, 3, 12, 3,
  12, 4, 12, 4, 12, 255
};
static unsigned char pchg_06[66] = {
  0, 4, 12, 12, 12, 5, 12, 12, 12, 4,
  12, 12, 12, 5, 12, 12, 12, 6, 12, 12,
  12, 7, 12, 12, 12, 8, 12, 12, 12, 9,
  12, 12, 12, 10, 12, 12, 12, 11, 12, 12,
  12, 10, 12, 12, 12, 11, 12, 12, 12, 0,
  12, 12, 12, 1, 12, 12, 12, 2, 12, 12,
  12, 3, 12, 12, 12, 255
};
static unsigned char pchg_07[66] = {
  0, 3, 12, 12, 12, 4, 12, 12, 12, 5,
  12, 12, 12, 4, 12, 12, 12, 5, 12, 12,
  12, 6, 12, 12, 12, 7, 12, 12, 12, 8,
  12, 12, 12, 9, 12, 12, 12, 10, 12, 12,
  12, 11, 12, 12, 12, 10, 12, 12, 12, 11,
  12, 12, 12, 0, 12, 12, 12, 1, 12, 12,
  12, 2, 12, 12, 12, 255
};
static unsigned char pchg_08[4] = { 0, 13, 12, 255 };
static unsigned char* pchg[9] = {
  pchg_00,
  pchg_01,
  pchg_02,
  pchg_03,
  pchg_04,
  pchg_05,
  pchg_06,
  pchg_07,
  pchg_08
};
static sprite_pattern pat00 = {
  2,
  { {
    { -8, -8, 0, 468 },
    { -8, -6, 0, 481 }
  } }
};
static sprite_pattern pat01 = {
  2,
  { {
    { -8, -8, 0, 469 },
    { -8, -6, 0, 482 }
  } }
};
static sprite_pattern pat02 = {
  2,
  { {
    { -8, -8, 0, 470 },
    { -12, -6, 0, 483 }
  } }
};
static sprite_pattern pat03 = {
  2,
  { {
    { -8, -8, 0, 471 },
    { -12, -6, 0, 484 }
  } }
};
static sprite_pattern pat04 = {
  2,
  { {
    { -10, -5, 0, 485 },
    { -8, -8, 0, 472 }
  } }
};
static sprite_pattern pat05 = {
  2,
  { {
    { -10, -5, 0, 486 },
    { -8, -8, 0, 473 }
  } }
};
static sprite_pattern pat06 = {
  2,
  { {
    { -12, -6, 0, 487 },
    { -8, -8, 0, 474 }
  } }
};
static sprite_pattern pat07 = {
  2,
  { {
    { -12, -6, 0, 488 },
    { -8, -8, 0, 475 }
  } }
};
static sprite_pattern pat08 = {
  2,
  { {
    { -8, -6, 0, 489 },
    { -8, -8, 0, 476 }
  } }
};
static sprite_pattern pat09 = {
  2,
  { {
    { -8, -6, 0, 490 },
    { -8, -8, 0, 477 }
  } }
};
static sprite_pattern pat0a = {
  2,
  { {
    { -1, -5, 0, 491 },
    { -8, -8, 0, 478 }
  } }
};
static sprite_pattern pat0b = {
  2,
  { {
    { -1, -5, 0, 492 },
    { -8, -8, 0, 479 }
  } }
};
static sprite_pattern pat0c;
static sprite_pattern pat0d = {
  2,
  { {
    { -10, -5, 0, 493 },
    { -8, -8, 0, 480 }
  } }
};
sprite_pattern* pat_kabasira[14] = {
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05,
  &pat06,
  &pat07,
  &pat08,
  &pat09,
  &pat0a,
  &pat0b,
  &pat0c,
  &pat0d
};
static void(*kabasira_act_tbl[2])(sprite_status*) = {
  &act_init,
  &act_move
};



























































































































































































































































































void kabasira(sprite_status* pActwk) { /* Line 496, Address: 0x102a210 */
  sprite_status* pMainact;
  short xsv, ysv, len;
  if (pActwk->userflag.b.l < 0) { /* Line 499, Address: 0x102a22c */
    if (pActwk->userflag.b.l == -1) { /* Line 500, Address: 0x102a244 */

      pMainact = &actwk[((short*)pActwk)[33]]; /* Line 502, Address: 0x102a260 */
      if (pMainact->actno == 34) goto label1; /* Line 503, Address: 0x102a288 */

      frameout(pActwk); /* Line 505, Address: 0x102a29c */
      return; /* Line 506, Address: 0x102a2a8 */
    }




    pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 512, Address: 0x102a2b0 */
    pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 513, Address: 0x102a2cc */

    if (pActwk->colicnt) { /* Line 515, Address: 0x102a2e8 */
      xsv = pActwk->xposi.w.h; /* Line 516, Address: 0x102a2f8 */
      ysv = pActwk->yposi.w.h; /* Line 517, Address: 0x102a308 */
      frameout(pActwk); /* Line 518, Address: 0x102a318 */
      pActwk->xposi.w.h = xsv; /* Line 519, Address: 0x102a324 */
      pActwk->yposi.w.h = ysv; /* Line 520, Address: 0x102a32c */
      pActwk->actno = 24; /* Line 521, Address: 0x102a334 */
      pActwk->r_no1 = 1; /* Line 522, Address: 0x102a340 */
      soundset(158); /* Line 523, Address: 0x102a34c */
    } /* Line 524, Address: 0x102a358 */
    else {
      if ((len = actwk[0].yposi.w.h - pActwk->yposi.w.h) < 0) { /* Line 526, Address: 0x102a360 */
        len *= -1; /* Line 527, Address: 0x102a3ac */
      }


      if (len > 224) { /* Line 531, Address: 0x102a3b8 */

        frameout(pActwk); /* Line 533, Address: 0x102a3cc */
      } else { /* Line 534, Address: 0x102a3d8 */
        patchg(pActwk, pchg); /* Line 535, Address: 0x102a3e0 */
        actionsub(pActwk); /* Line 536, Address: 0x102a3f4 */
        frameout_s(pActwk); /* Line 537, Address: 0x102a400 */
      }
    }

    return; /* Line 541, Address: 0x102a40c */
  }


  if (enemy_suicide(pActwk)) return; /* Line 545, Address: 0x102a414 */




label1:
  kabasira_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 551, Address: 0x102a428 */
  patchg(pActwk, pchg); /* Line 552, Address: 0x102a46c */
  actionsub(pActwk); /* Line 553, Address: 0x102a480 */
  frameout_s(pActwk); /* Line 554, Address: 0x102a48c */
} /* Line 555, Address: 0x102a498 */





static void act_init(sprite_status* pActwk) { /* Line 561, Address: 0x102a4c0 */
  short anglewk1, anglewk2, xangle, yangle;
  unsigned char mstnowk;
  int i;
  sprite_status* pNewact;

  pActwk->colino = 49; /* Line 567, Address: 0x102a4e4 */
  ((short*)pActwk)[24] = pActwk->xposi.w.h; /* Line 568, Address: 0x102a4f0 */
  ((short*)pActwk)[26] = pActwk->yposi.w.h; /* Line 569, Address: 0x102a500 */
  ((short*)pActwk)[23] = -32768; /* Line 570, Address: 0x102a510 */
  ((short*)pActwk)[25] = -32768; /* Line 571, Address: 0x102a51c */

  if (!pActwk->userflag.b.h) { /* Line 573, Address: 0x102a528 */
    ((short*)pActwk)[29] = 512; /* Line 574, Address: 0x102a538 */
    ((short*)pActwk)[30] = 256; /* Line 575, Address: 0x102a544 */
    pActwk->mstno.b.h = 4; /* Line 576, Address: 0x102a550 */
    anglewk1 = 4096; /* Line 577, Address: 0x102a55c */
    anglewk2 = 2048; /* Line 578, Address: 0x102a568 */
  } else { /* Line 579, Address: 0x102a574 */
    ((short*)pActwk)[29] = 256; /* Line 580, Address: 0x102a57c */
    ((short*)pActwk)[30] = 128; /* Line 581, Address: 0x102a588 */
    pActwk->mstno.b.h = 0; /* Line 582, Address: 0x102a594 */
    anglewk1 = 8192; /* Line 583, Address: 0x102a59c */
    anglewk2 = 4096; /* Line 584, Address: 0x102a5a8 */
  }

  act_init_sub(pActwk); /* Line 587, Address: 0x102a5b4 */

  xangle = 0; /* Line 589, Address: 0x102a5c0 */
  yangle = 0; /* Line 590, Address: 0x102a5c4 */
  mstnowk = 0; /* Line 591, Address: 0x102a5c8 */

  for (i = 0; i < 3; ++i) { /* Line 593, Address: 0x102a5cc */

    if (actwkchk2(pActwk, &pNewact) != 0) { /* Line 595, Address: 0x102a5d8 */

      frameout(pActwk); /* Line 597, Address: 0x102a5f0 */
      return; /* Line 598, Address: 0x102a5fc */
    }

    ((short*)pNewact)[33] = pActwk - actwk; /* Line 601, Address: 0x102a604 */
    ++mstnowk; /* Line 602, Address: 0x102a63c */
    pNewact->mstno.b.h = (unsigned char)(mstnowk + pActwk->mstno.b.h); /* Line 603, Address: 0x102a644 */
    xangle -= anglewk1; /* Line 604, Address: 0x102a670 */
    yangle -= anglewk2; /* Line 605, Address: 0x102a67c */
    ((short*)pNewact)[27] = xangle; /* Line 606, Address: 0x102a688 */
    ((short*)pNewact)[28] = yangle; /* Line 607, Address: 0x102a690 */
    pNewact->userflag.b.l = -1; /* Line 608, Address: 0x102a698 */
    pNewact->actno = pActwk->actno; /* Line 609, Address: 0x102a6a4 */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 610, Address: 0x102a6b4 */
    pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 611, Address: 0x102a6c4 */
    *(int*)&pNewact->actfree[0] = *(int*)&pActwk->actfree[0]; /* Line 612, Address: 0x102a6d4 */

    *(int*)&pNewact->actfree[4] = *(int*)&pActwk->actfree[4]; /* Line 614, Address: 0x102a6ec */

    ((short*)pNewact)[29] = ((short*)pActwk)[29]; /* Line 616, Address: 0x102a704 */

    ((short*)pNewact)[30] = ((short*)pActwk)[30]; /* Line 618, Address: 0x102a714 */

    act_init_sub(pNewact); /* Line 620, Address: 0x102a724 */
  } /* Line 621, Address: 0x102a730 */
} /* Line 622, Address: 0x102a740 */





static void act_init_sub(sprite_status* pActwk) { /* Line 628, Address: 0x102a770 */
  pActwk->r_no0 = 2; /* Line 629, Address: 0x102a778 */
  pActwk->actflg |= 4; /* Line 630, Address: 0x102a784 */
  pActwk->sprpri = 3; /* Line 631, Address: 0x102a794 */
  pActwk->sprhs = 12; /* Line 632, Address: 0x102a7a0 */
  pActwk->sprhsize = 12; /* Line 633, Address: 0x102a7ac */
  pActwk->sprvsize = 8; /* Line 634, Address: 0x102a7b8 */
  pActwk->sproffset = 9158; /* Line 635, Address: 0x102a7c4 */
  pActwk->patbase = pat_kabasira; /* Line 636, Address: 0x102a7d0 */
} /* Line 637, Address: 0x102a7e0 */





static void act_move(sprite_status* pActwk) { /* Line 643, Address: 0x102a7f0 */
  sprite_status* pTamaact;
  short xlen, ylen, anglewk;
  int_union sinwk, coswk;

  sinwk.l = coswk.l = 0; /* Line 648, Address: 0x102a800 */

  if (!pActwk->userflag.b.h && pActwk->userflag.b.l >= 0) { /* Line 650, Address: 0x102a808 */
    if (((short*)pActwk)[31]) { /* Line 651, Address: 0x102a830 */
      --((short*)pActwk)[31]; /* Line 652, Address: 0x102a840 */
    } /* Line 653, Address: 0x102a850 */
    else {
      if (kabasira_area(pActwk, &actwk[0], &xlen, &ylen) != 0) { /* Line 655, Address: 0x102a858 */

        ((short*)pActwk)[31] = 240; /* Line 657, Address: 0x102a87c */
        if (actwkchk(&pTamaact) == 0) { /* Line 658, Address: 0x102a888 */
          pTamaact->mstno.b.h = 8; /* Line 659, Address: 0x102a89c */
          pTamaact->userflag.b.l = -2; /* Line 660, Address: 0x102a8a8 */
          pTamaact->colino = 241; /* Line 661, Address: 0x102a8b4 */
          pTamaact->actno = pActwk->actno; /* Line 662, Address: 0x102a8c0 */
          pTamaact->xposi.w.h = pActwk->xposi.w.h; /* Line 663, Address: 0x102a8d0 */
          pTamaact->yposi.w.h = pActwk->yposi.w.h; /* Line 664, Address: 0x102a8e0 */
          act_init_sub(pTamaact); /* Line 665, Address: 0x102a8f0 */
          sinset(atan_sonic(xlen, ylen), &sinwk.w.l, &coswk.w.l); /* Line 666, Address: 0x102a8fc */
          sinwk.l = (unsigned int)sinwk.l >> 16 & 65535 | sinwk.l << 16 & -65536; /* Line 667, Address: 0x102a920 */
          coswk.l = (unsigned int)coswk.l >> 16 & 65535 | coswk.l << 16 & -65536; /* Line 668, Address: 0x102a944 */
          sinwk.l >>= 7; /* Line 669, Address: 0x102a968 */
          coswk.l >>= 7; /* Line 670, Address: 0x102a974 */
          *(int*)&pTamaact->actfree[4] = sinwk.l; /* Line 671, Address: 0x102a980 */
          *(int*)&pTamaact->actfree[0] = coswk.l; /* Line 672, Address: 0x102a990 */

          if (coswk.l < 0) { /* Line 674, Address: 0x102a9a0 */
            pTamaact->actflg ^= 1; /* Line 675, Address: 0x102a9ac */
            pTamaact->cddat ^= 1; /* Line 676, Address: 0x102a9bc */
          }


          if (pActwk->actflg & 128) { /* Line 680, Address: 0x102a9cc */
            soundset(160); /* Line 681, Address: 0x102a9e4 */
          }
        }
      }
    }
  }




  anglewk = ((short*)pActwk)[27] + ((short*)pActwk)[29]; /* Line 691, Address: 0x102a9f0 */

  ((short*)pActwk)[27] = anglewk; /* Line 693, Address: 0x102aa24 */
  anglewk = (unsigned short)anglewk >> 8; /* Line 694, Address: 0x102aa2c */
  sinwk.l = coswk.l = 0; /* Line 695, Address: 0x102aa48 */
  sinset(anglewk, &sinwk.w.l, &coswk.w.l); /* Line 696, Address: 0x102aa50 */
  sinwk.l = (unsigned int)sinwk.l >> 16 & 65535 | sinwk.l << 16 & -65536; /* Line 697, Address: 0x102aa64 */
  sinwk.l >>= 4; /* Line 698, Address: 0x102aa88 */
  pActwk->xposi.l = sinwk.l + *(int*)&pActwk->actfree[0]; /* Line 699, Address: 0x102aa94 */

  anglewk = ((short*)pActwk)[28] + ((short*)pActwk)[30]; /* Line 701, Address: 0x102aab0 */

  ((short*)pActwk)[28] = anglewk; /* Line 703, Address: 0x102aae4 */
  anglewk = (unsigned short)anglewk >> 8; /* Line 704, Address: 0x102aaec */
  sinwk.l = coswk.l = 0; /* Line 705, Address: 0x102ab08 */
  sinset(anglewk, &sinwk.w.l, &coswk.w.l); /* Line 706, Address: 0x102ab10 */
  coswk.l = (unsigned int)coswk.l >> 16 & 65535 | coswk.l << 16 & -65536; /* Line 707, Address: 0x102ab24 */
  coswk.l >>= 2; /* Line 708, Address: 0x102ab48 */
  pActwk->yposi.l = coswk.l + *(int*)&pActwk->actfree[4]; /* Line 709, Address: 0x102ab54 */
} /* Line 710, Address: 0x102ab70 */

















static unsigned int kabasira_area(sprite_status* pActwk, sprite_status* pPlayerwk, short* pX, short* pY) { /* Line 728, Address: 0x102ab90 */
  *pY = pPlayerwk->yposi.w.h - pActwk->yposi.w.h; /* Line 729, Address: 0x102aba4 */
  if ((unsigned short)(*pY + 96) >= 192) { /* Line 730, Address: 0x102abd8 */
    return 0; /* Line 731, Address: 0x102ac00 */
  }

  *pX = pPlayerwk->xposi.w.h - pActwk->xposi.w.h; /* Line 734, Address: 0x102ac0c */
  if ((unsigned short)(*pX + 120) >= 240) { /* Line 735, Address: 0x102ac40 */
    return 0; /* Line 736, Address: 0x102ac68 */
  }

  return 1; /* Line 739, Address: 0x102ac74 */
} /* Line 740, Address: 0x102ac78 */
