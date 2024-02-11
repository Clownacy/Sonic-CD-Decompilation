#include "..\EQU.H"
#include "BOSS_3.H"

static sprite_pattern segg3_01 =
{
  1,
  { { -24, -56, 0, 571 } }
};
static sprite_pattern segg3_02 =
{
  1,
  { { -24, -56, 0, 572 } }
};
static sprite_pattern segg3_03 =
{
  1,
  { { -24, -56, 0, 573 } }
};
static sprite_pattern segg3_04 =
{
  1,
  { { -24, -56, 0, 574 } }
};
static sprite_pattern segg3_05 =
{
  1,
  { { -32, -64, 0, 575 } }
};
static sprite_pattern segg3_06 =
{
  1,
  { { -24, -64, 0, 576 } }
};
static sprite_pattern segg3_07 =
{
  1,
  { { -24, -56, 0, 577 } }
};
static sprite_pattern segg3_08 =
{
  1,
  { { -24, -56, 0, 578 } }
};
static sprite_pattern segg3_09 =
{
  1,
  { { 0, -56, 0, 579 } }
};
static sprite_pattern segg3_10 =
{
  1,
  { { 0, -56, 0, 580 } }
};
static sprite_pattern segg3_11 =
{
  1,
  { { -48, -16, 0, 581 } }
};
static sprite_pattern segg3_12 =
{
  1,
  { { -48, -16, 0, 582 } }
};
static sprite_pattern segg3_13 =
{
  1,
  { { -64, -48, 0, 583 } }
};
static sprite_pattern segg3_14 =
{
  1,
  { { -64, -48, 0, 584 } }
};
static sprite_pattern segg3_15 =
{
  1,
  { { -64, -32, 0, 585 } }
};
static sprite_pattern segg3_16 =
{
  1,
  { { -64, -32, 0, 586 } }
};
static sprite_pattern segg3_17 =
{
  1,
  { { -64, -32, 0, 587 } }
};
static sprite_pattern segg3_18 =
{
  1,
  { { -64, -32, 0, 588 } }
};
static sprite_pattern segg3_19 =
{
  1,
  { { -64, -16, 0, 589 } }
};
static sprite_pattern segg3_20 =
{
  1,
  { { -16, -16, 0, 590 } }
};
static sprite_pattern segg3_21 =
{
  1,
  { { -16, -16, 0, 591 } }
};
static sprite_pattern segg3_22 =
{
  1,
  { { -16, -16, 0, 592 } }
};
static sprite_pattern segg3_23 =
{
  2,
  {
    { -24, -16, 0, 613 },
    { -24, -16, 0, 614 }
  }
};
static sprite_pattern segg3_24 =
{
  2,
  {
    { -24, -16, 0, 613 },
    { -24, -16, 0, 615 }
  }
};
static sprite_pattern segg3_25 =
{
  2,
  {
    { -24, -16, 0, 613 },
    { -24, -24, 0, 616 }
  }
};
static sprite_pattern segg3_26 =
{
  2,
  {
    { -24, -16, 0, 613 },
    { -24, -16, 0, 617 }
  }
};
static sprite_pattern segg3_27 =
{
  2,
  {
    { -24, -16, 0, 613 },
    { -24, -24, 0, 618 }
  }
};
static sprite_pattern segg3_28 =
{
  1,
  { { -8, -8, 0, 598 } }
};
static sprite_pattern segg3_29 =
{
  1,
  { { -12, -12, 0, 599 } }
};
static sprite_pattern segg3_B1 =
{
  2,
  {
    { -64, -48, 0, 601 },
    { -48, -32, 0, 600 }
  }
};
static sprite_pattern segg3_B2 =
{
  2,
  {
    { -64, -48, 0, 603 },
    { -48, -32, 0, 602 }
  }
};
static sprite_pattern segg3_B3 =
{
  2,
  {
    { -64, -16, 0, 605 },
    { -48, -32, 0, 604 }
  }
};
static sprite_pattern segg3_B4 =
{
  2,
  {
    { -64, -16, 0, 607 },
    { -48, -32, 0, 606 }
  }
};
static sprite_pattern segg3_B5 =
{
  2,
  {
    { -64, -16, 0, 609 },
    { -48, -32, 0, 608 }
  }
};
static sprite_pattern segg3_B6 =
{
  2,
  {
    { -64, -16, 0, 611 },
    { -48, -32, 0, 610 }
  }
};
static sprite_pattern segg3_B7 =
{
  1,
  { { -64, -16, 0, 612 } }
};
sprite_pattern* egg3_pat[10] =
{
  &segg3_01,
  &segg3_02,
  &segg3_03,
  &segg3_04,
  &segg3_05,
  &segg3_06,
  &segg3_07,
  &segg3_08,
  &segg3_09,
  &segg3_10,
};
sprite_pattern* egg3dai_s_pat[2] =
{
  &segg3_11,
  &segg3_12
};
sprite_pattern* egg3dai_l_pat[7] =
{
  &segg3_B1,
  &segg3_B2,
  &segg3_B3,
  &segg3_B4,
  &segg3_B5,
  &segg3_B6,
  &segg3_B7
};
sprite_pattern* egg3haguruma_pat[3] =
{
  &segg3_20,
  &segg3_21,
  &segg3_22
};
sprite_pattern* egg3cannon_pat[5] =
{
  &segg3_23,
  &segg3_24,
  &segg3_25,
  &segg3_26,
  &segg3_27
};
sprite_pattern* egg3punchbom_pat[2] =
{
  &segg3_28,
  &segg3_29
};
static char pchg0[8] = { 9, 0, 1, 0, 3, 2, 3, -1 };
static char pchg1[4] = { 7, 4, 5, -1 };
static char pchg2[3] = { 127, 6, -1 };
static char pchg3[3] = { 127, 7, -1 };
static char pchg4[4] = { 7, 8, 9, -1 };
char* egg3_pchg[5] =
{
  pchg0,
  pchg1,
  pchg2,
  pchg3,
  pchg4
};
static char schg0[3] = { 127, 0, -1 };
static char schg1[4] = { 0, 0, 1, -1 };
char* egg3dai_s_pchg[2] =
{
  schg0,
  schg1
};
static char hchg0[5] = { 2, 0, 2, 1, -1 };
static char hchg1[5] = { 2, 0, 1, 2, -1 };
char* egg3haguruma_pchg[2] =
{
  hchg0,
  hchg1
};
char bomtbl_dai[22] =
{
    4,  10,
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
char bomtbl_cannon[8] =
{
    1,   3,
    0,   0,
  -32,   0,
   32,   0
};
char bomtbl_ctrl[8] =
{
    1,   3,
    0, -56,
  -32, -56,
   32, -56
};
char bomtbl_ctrl2[6] =
{
    1,   2,
  -16, -56,
   16, -56
};
extern int(*sRandom)();
extern sprite_pattern* bakupat[];
extern char* bakuchg[];
















void egg3dai_s(sprite_status* actionwk) { /* Line 344, Address: 0x102baa0 */
  switch (actionwk->r_no0) /* Line 345, Address: 0x102baac */
  {
    case 0:
      egg3dai_s_ini(actionwk); /* Line 348, Address: 0x102baec */
    case 2:
      egg3dai_s_chk(actionwk); /* Line 350, Address: 0x102baf8 */
      break; /* Line 351, Address: 0x102bb04 */
    case 4:
      egg3dai_s_up(actionwk); /* Line 353, Address: 0x102bb0c */
      break; /* Line 354, Address: 0x102bb18 */
    case 6:
      egg3dai_s_bom(actionwk); /* Line 356, Address: 0x102bb20 */
      break;
  }
} /* Line 359, Address: 0x102bb2c */

void egg3dai_s_ini(sprite_status* actionwk) { /* Line 361, Address: 0x102bb40 */
  sprite_status* a1;

  actionwk->r_no0 = 2; /* Line 364, Address: 0x102bb4c */
  actionwk->actflg = 4; /* Line 365, Address: 0x102bb58 */
  actionwk->sprpri = 4; /* Line 366, Address: 0x102bb64 */
  actionwk->sprhsize = 48; /* Line 367, Address: 0x102bb70 */
  actionwk->sprvsize = 16; /* Line 368, Address: 0x102bb7c */
  actionwk->sproffset = 798; /* Line 369, Address: 0x102bb88 */
  actionwk->patbase = egg3dai_s_pat; /* Line 370, Address: 0x102bb94 */
  ((int*)actionwk)[13] = -163840; /* Line 371, Address: 0x102bba4 */
  ((short*)actionwk)[25] = actionwk->yposi.w.h - 48; /* Line 372, Address: 0x102bbb4 */
  actionwk->colino = 62; /* Line 373, Address: 0x102bbd8 */
  actionwk->colicnt = 2; /* Line 374, Address: 0x102bbe4 */

  if (actwkchk(&a1) != 0) return; /* Line 376, Address: 0x102bbf0 */
  ((unsigned short*)a1)[28] = actionwk - actwk; /* Line 377, Address: 0x102bc04 */
  a1->actno = 50; /* Line 378, Address: 0x102bc38 */
  a1->xposi.w.h = actionwk->xposi.w.h - 48; /* Line 379, Address: 0x102bc44 */
  a1->yposi.w.h = actionwk->yposi.w.h; /* Line 380, Address: 0x102bc68 */
  ((unsigned short*)actionwk)[28] = a1 - actwk; /* Line 381, Address: 0x102bc78 */
} /* Line 382, Address: 0x102bcac */

void egg3dai_s_chk(sprite_status* actionwk) { /* Line 384, Address: 0x102bcc0 */
  if (!actionwk->colino) /* Line 385, Address: 0x102bccc */
  {
    soundset(172); /* Line 387, Address: 0x102bcdc */
    actionwk->r_no0 = 4; /* Line 388, Address: 0x102bce8 */
    actionwk->actfree[2] |= 4; /* Line 389, Address: 0x102bcf4 */
    actionwk->mstno.b.h = 1; /* Line 390, Address: 0x102bd04 */
    actionwk->colicnt = 0; /* Line 391, Address: 0x102bd10 */
  }
  actionsub(actionwk); /* Line 393, Address: 0x102bd18 */
} /* Line 394, Address: 0x102bd24 */

void egg3dai_s_up(sprite_status* actionwk) { /* Line 396, Address: 0x102bd40 */
  jaba_s_chk(actionwk); /* Line 397, Address: 0x102bd4c */
  ++actionwk->actfree[0]; /* Line 398, Address: 0x102bd58 */
  if (actionwk->actfree[0] >= 16) /* Line 399, Address: 0x102bd68 */
  {
    actionwk->mstno.b.h = 0; /* Line 401, Address: 0x102bd80 */
    patchg(actionwk, egg3dai_s_pchg); /* Line 402, Address: 0x102bd88 */
  }

  actionwk->yposi.l += ((int*)actionwk)[13]; /* Line 405, Address: 0x102bd9c */
  if (actionwk->yposi.w.h <= ((short*)actionwk)[25]) /* Line 406, Address: 0x102bdb4 */
  {
    actionwk->actfree[2] &= 251; /* Line 408, Address: 0x102bde0 */
    actionwk->yposi.w.h = ((short*)actionwk)[25]; /* Line 409, Address: 0x102bdf0 */
    actionwk->r_no0 = 6; /* Line 410, Address: 0x102be00 */
  }
  actionsub(actionwk); /* Line 412, Address: 0x102be0c */
} /* Line 413, Address: 0x102be18 */

void egg3dai_s_bom(sprite_status* actionwk) { /* Line 415, Address: 0x102be30 */
  jaba_s_chk(actionwk); /* Line 416, Address: 0x102be3c */
  if (((short*)actionwk)[33] < 121) /* Line 417, Address: 0x102be48 */
  {
    bom_set_dai(actionwk); /* Line 419, Address: 0x102be64 */
    actionsub(actionwk); /* Line 420, Address: 0x102be70 */
  }

  if (actionwk->actfree[2] & 2) /* Line 423, Address: 0x102be7c */
  {
    frameout(&actwk[((short*)actionwk)[28]]); /* Line 425, Address: 0x102be94 */
    frameout(actionwk); /* Line 426, Address: 0x102bec0 */
  }
} /* Line 428, Address: 0x102becc */


void jaba_s_chk(sprite_status* actionwk) { /* Line 431, Address: 0x102bee0 */
  sprite_status* a1;

  if (actionwk->actfree[2] & 2) return; /* Line 434, Address: 0x102beec */

  a1 = &actwk[0]; /* Line 436, Address: 0x102bf04 */
  if (actionwk->xposi.w.h < 1152 || actionwk->yposi.w.h >= 1308) return; /* Line 437, Address: 0x102bf10 */
  actionwk->actfree[2] |= 2; /* Line 438, Address: 0x102bf50 */
  sub_sync(103); /* Line 439, Address: 0x102bf60 */

  if (actwkchk(&a1) != 0) return; /* Line 441, Address: 0x102bf6c */
  a1->actno = 63; /* Line 442, Address: 0x102bf80 */
  a1->r_no0 = 6; /* Line 443, Address: 0x102bf8c */
  a1->xposi.w.h = 1056; /* Line 444, Address: 0x102bf98 */
  a1->yposi.w.h = 1344; /* Line 445, Address: 0x102bfa4 */
} /* Line 446, Address: 0x102bfb0 */





void egg3flash(sprite_status* actionwk) { /* Line 452, Address: 0x102bfc0 */
  int d0;

  if (actionwk->actfree[1] == 0) return; /* Line 455, Address: 0x102bfd0 */



  if (actionwk->actfree[1] >> 1 & 1) /* Line 459, Address: 0x102bfe4 */
  {
    d0 = 5; /* Line 461, Address: 0x102c000 */
    actionwk->patno |= 1; /* Line 462, Address: 0x102c004 */
  } /* Line 463, Address: 0x102c014 */
  else
  {
    d0 = 6; /* Line 466, Address: 0x102c01c */
    actionwk->patno &= 254; /* Line 467, Address: 0x102c020 */
  }

  --actionwk->actfree[1]; /* Line 470, Address: 0x102c030 */
  colorset2(d0); /* Line 471, Address: 0x102c040 */
} /* Line 472, Address: 0x102c04c */

void egg3dai_l(sprite_status* actionwk) { /* Line 474, Address: 0x102c060 */
  if (actionwk->actfree[17]) /* Line 475, Address: 0x102c06c */
  {

    if ((unsigned char)scra_vline < 176) /* Line 478, Address: 0x102c07c */
    {
      scra_vline += 6; /* Line 480, Address: 0x102c098 */
      if ((unsigned char)scra_vline >= 178) /* Line 481, Address: 0x102c0ac */
      {
        scra_vline = 178; /* Line 483, Address: 0x102c0c8 */
      }
    }
  }
  switch (actionwk->r_no0) /* Line 487, Address: 0x102c0d4 */
  {
    case 0:
      egg3dai_l_ini(actionwk); /* Line 490, Address: 0x102c12c */
      break; /* Line 491, Address: 0x102c138 */
    case 2:
      egg3dai_l_demo(actionwk); /* Line 493, Address: 0x102c140 */
      break; /* Line 494, Address: 0x102c14c */
    case 4:
      egg3dai_l_chk(actionwk); /* Line 496, Address: 0x102c154 */
      break; /* Line 497, Address: 0x102c160 */
    case 6:
      egg3dai_l_up(actionwk); /* Line 499, Address: 0x102c168 */
      break; /* Line 500, Address: 0x102c174 */
    case 8:
      egg3dai_l_bom(actionwk); /* Line 502, Address: 0x102c17c */
      break; /* Line 503, Address: 0x102c188 */
    case 10:
      egg3dai_l_end(actionwk); /* Line 505, Address: 0x102c190 */
      break;
  }
  if (actionwk->actfree[2] & 1) return; /* Line 508, Address: 0x102c19c */
  egg3flash(actionwk); /* Line 509, Address: 0x102c1b4 */
  actionsub(actionwk); /* Line 510, Address: 0x102c1c0 */
} /* Line 511, Address: 0x102c1cc */

void egg3dai_l_ini(sprite_status* actionwk) { /* Line 513, Address: 0x102c1e0 */
  sprite_status* a1;

  colorset2(6); /* Line 516, Address: 0x102c1ec */
  actionwk->r_no0 = 2; /* Line 517, Address: 0x102c1f8 */
  actionwk->actflg = 4; /* Line 518, Address: 0x102c204 */
  actionwk->sprpri = 4; /* Line 519, Address: 0x102c210 */
  actionwk->sprhsize = 80; /* Line 520, Address: 0x102c21c */
  actionwk->sprvsize = 16; /* Line 521, Address: 0x102c228 */
  actionwk->sproffset = 798; /* Line 522, Address: 0x102c234 */
  actionwk->patbase = egg3dai_l_pat; /* Line 523, Address: 0x102c240 */


  if (actwkchk2(actionwk, &a1) != 0) return; /* Line 526, Address: 0x102c250 */
  ((unsigned short*)actionwk)[29] = a1 - actwk; /* Line 527, Address: 0x102c268 */
  ((unsigned short*)a1)[28] = actionwk - actwk; /* Line 528, Address: 0x102c29c */
  a1->actno = 51; /* Line 529, Address: 0x102c2d0 */
  a1->xposi.w.h = actionwk->xposi.w.h; /* Line 530, Address: 0x102c2dc */
  a1->yposi.w.h = actionwk->yposi.w.h - 48; /* Line 531, Address: 0x102c2ec */

  if (actwkchk2(actionwk, &a1) != 0) return; /* Line 533, Address: 0x102c310 */
  ((unsigned short*)actionwk)[28] = a1 - actwk; /* Line 534, Address: 0x102c328 */
  ((unsigned short*)a1)[28] = actionwk - actwk; /* Line 535, Address: 0x102c35c */
  a1->actno = 50; /* Line 536, Address: 0x102c390 */
  a1->xposi.w.h = actionwk->xposi.w.h - 64; /* Line 537, Address: 0x102c39c */
  a1->yposi.w.h = actionwk->yposi.w.h; /* Line 538, Address: 0x102c3c0 */

  if (actwkchk2(actionwk, &a1) != 0) return; /* Line 540, Address: 0x102c3d0 */
  ((unsigned short*)a1)[28] = actionwk - actwk; /* Line 541, Address: 0x102c3e8 */
  a1->actno = 61; /* Line 542, Address: 0x102c41c */
  a1->xposi.w.h = actionwk->xposi.w.h; /* Line 543, Address: 0x102c428 */
} /* Line 544, Address: 0x102c438 */

void egg3dai_l_demo(sprite_status* actionwk) { /* Line 546, Address: 0x102c450 */
  sprite_status* a1;
  short d0, d1, d2;

  a1 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 550, Address: 0x102c468 */
  a1->mstno.b.h = 1; /* Line 551, Address: 0x102c48c */

  a1 = &actwk[0]; /* Line 553, Address: 0x102c494 */
  d1 = 448; /* Line 554, Address: 0x102c49c */
  d2 = 220; /* Line 555, Address: 0x102c4a8 */
  d0 = a1->yposi.w.h; /* Line 556, Address: 0x102c4b4 */
  if (d0 >= d1) goto label2; /* Line 557, Address: 0x102c4c0 */
  if (d0 >= d2) /* Line 558, Address: 0x102c4dc */
  {
label1:
    if (((short*)actionwk)[25] == d0) /* Line 561, Address: 0x102c4f8 */
      actionwk->actfree[2] &= 251; /* Line 562, Address: 0x102c518 */
    else
      actionwk->actfree[2] |= 4; /* Line 564, Address: 0x102c530 */
    ((short*)actionwk)[25] = d0; /* Line 565, Address: 0x102c540 */
    actionwk->yposi.w.h = d0; /* Line 566, Address: 0x102c548 */
    return; /* Line 567, Address: 0x102c550 */
  }

  d0 = d2; /* Line 570, Address: 0x102c558 */
  goto label1; /* Line 571, Address: 0x102c560 */
label2:
  actionwk->yposi.w.h = d1; /* Line 573, Address: 0x102c568 */
  actionwk->actfree[2] &= 251; /* Line 574, Address: 0x102c570 */
  actionwk->r_no0 = 4; /* Line 575, Address: 0x102c580 */
  ((int*)actionwk)[13] = -163840; /* Line 576, Address: 0x102c58c */
  ((short*)actionwk)[25] = actionwk->yposi.w.h - 72; /* Line 577, Address: 0x102c59c */
  actionwk->colino = 63; /* Line 578, Address: 0x102c5c0 */
  actionwk->colicnt = 4; /* Line 579, Address: 0x102c5cc */

  a1 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 581, Address: 0x102c5d8 */
  a1->mstno.b.h = 0; /* Line 582, Address: 0x102c5fc */
} /* Line 583, Address: 0x102c600 */








short jabaopen_chk(sprite_status* actionwk) { /* Line 592, Address: 0x102c620 */
  short jabaopen_tbl[4] = { 496, 424, 352, 272 }; /* Line 593, Address: 0x102c630 */
  short d0, d1;

  if (actionwk->actfree[16] >= 4) return 1; /* Line 596, Address: 0x102c65c */
  d0 = actionwk->actfree[16]; /* Line 597, Address: 0x102c680 */

  d0 = jabaopen_tbl[d0]; /* Line 599, Address: 0x102c694 */

  d1 = actwk[0].yposi.w.h; /* Line 601, Address: 0x102c6b0 */
  if (d0 < d1) return 1; /* Line 602, Address: 0x102c6c0 */
  if (d1 < 128) return 1; /* Line 603, Address: 0x102c6e8 */

  d1 = actwk[0].xposi.w.h; /* Line 605, Address: 0x102c708 */
  if (d1 < 832) return 1; /* Line 606, Address: 0x102c718 */
  if (d1 >= 961) return 1; /* Line 607, Address: 0x102c738 */

  return 0; /* Line 609, Address: 0x102c758 */
} /* Line 610, Address: 0x102c75c */

void egg3dai_l_chk(sprite_status* actionwk) { /* Line 612, Address: 0x102c770 */
  if (jabaopen_chk(actionwk) == 0) jaba_open(actionwk); /* Line 613, Address: 0x102c77c */

  if (actionwk->colino == 0) egg3dai_l_hit(actionwk); /* Line 615, Address: 0x102c7a4 */
} /* Line 616, Address: 0x102c7c4 */

void jaba_open(sprite_status* actionwk) { /* Line 618, Address: 0x102c7e0 */
  sprite_status* a1;
  short jabapos_tbl[4] = { 528, 456, 384, 304 }; /* Line 620, Address: 0x102c7ec */


  if (actwkchk(&a1) != 0) return; /* Line 623, Address: 0x102c818 */
  a1->actno = 63; /* Line 624, Address: 0x102c82c */
  a1->xposi.w.h = 896; /* Line 625, Address: 0x102c838 */
  a1->yposi.w.h = jabapos_tbl[actionwk->actfree[16]++]; /* Line 626, Address: 0x102c844 */
} /* Line 627, Address: 0x102c86c */

void egg3dai_l_hit(sprite_status* actionwk) { /* Line 629, Address: 0x102c880 */
  switch (actionwk->actfree[17]) /* Line 630, Address: 0x102c88c */
  {
    case 0:

    case 1:
      hitact2(actionwk); /* Line 635, Address: 0x102c8c0 */
      break; /* Line 636, Address: 0x102c8cc */
    case 2:
      hitact3(actionwk); /* Line 638, Address: 0x102c8d4 */
  }

  ++actionwk->actfree[17]; /* Line 641, Address: 0x102c8e0 */
} /* Line 642, Address: 0x102c8f0 */








void hitact2(sprite_status* actionwk) { /* Line 651, Address: 0x102c900 */
  sprite_status* a1;


  a1 = &actwk[((unsigned short*)actionwk)[29]]; /* Line 655, Address: 0x102c910 */
  a1->r_no0 = 4; /* Line 656, Address: 0x102c934 */
  a1->mstno.b.h = 1; /* Line 657, Address: 0x102c93c */
  ((int*)a1)[13] = -360448; /* Line 658, Address: 0x102c944 */
  egg3dai_l_hit2(actionwk); /* Line 659, Address: 0x102c950 */
} /* Line 660, Address: 0x102c95c */

void hitact3(sprite_status* actionwk) { /* Line 662, Address: 0x102c970 */
  sprite_status* a1;

  actionwk->patno = 4; /* Line 665, Address: 0x102c980 */

  a1 = &actwk[((unsigned short*)actionwk)[29]]; /* Line 667, Address: 0x102c98c */
  a1->r_no0 = 6; /* Line 668, Address: 0x102c9b0 */
  a1->actfree[0] = 0; /* Line 669, Address: 0x102c9b8 */
  ((short*)a1)[25] = actionwk->yposi.w.h - 64; /* Line 670, Address: 0x102c9bc */

  actionwk->patno = 2; /* Line 672, Address: 0x102c9dc */
  a1->sproffset = 1020; /* Line 673, Address: 0x102c9e8 */
  a1->mstno.w = 768; /* Line 674, Address: 0x102c9f0 */
  egg3dai_l_hit2(actionwk); /* Line 675, Address: 0x102c9f8 */
} /* Line 676, Address: 0x102ca04 */

void egg3dai_l_hit2(sprite_status* actionwk) { /* Line 678, Address: 0x102ca20 */
  soundset(172); /* Line 679, Address: 0x102ca2c */
  ((short*)actionwk)[33] = 0; /* Line 680, Address: 0x102ca38 */
  actionwk->r_no0 = 6; /* Line 681, Address: 0x102ca40 */
  actionwk->actfree[1] = 16; /* Line 682, Address: 0x102ca4c */
  if (actionwk->colicnt != 1) /* Line 683, Address: 0x102ca58 */
  {
    egg3dai_l_up(actionwk); /* Line 685, Address: 0x102ca70 */
    return; /* Line 686, Address: 0x102ca7c */
  }
  scoreup(100); /* Line 688, Address: 0x102ca84 */
  actionwk->colino = 0; /* Line 689, Address: 0x102ca90 */
  ((short*)actionwk)[25] = actionwk->yposi.w.h - 112; /* Line 690, Address: 0x102ca98 */
  if (!generate_flag) sub_sync(20); /* Line 691, Address: 0x102cabc */
  else sub_sync(19); /* Line 692, Address: 0x102cae0 */

  egg3dai_l_up(actionwk); /* Line 694, Address: 0x102caec */
} /* Line 695, Address: 0x102caf8 */

void jaba_last(sprite_status* actionwk) { /* Line 697, Address: 0x102cb10 */
  if (actionwk->actfree[16] != 3) return; /* Line 698, Address: 0x102cb1c */
  if (jabaopen_chk(actionwk) != 0) return; /* Line 699, Address: 0x102cb34 */
  bossflag = 3; /* Line 700, Address: 0x102cb48 */
  jaba_open(actionwk); /* Line 701, Address: 0x102cb54 */
} /* Line 702, Address: 0x102cb60 */

void egg3dai_l_up(sprite_status* actionwk) { /* Line 704, Address: 0x102cb70 */
  switch (actionwk->actfree[17] - 1) /* Line 705, Address: 0x102cb7c */
  {
    case 0:
      bom_set_cannon(actionwk); /* Line 708, Address: 0x102cbb4 */
      break; /* Line 709, Address: 0x102cbc0 */
    case 1:
      bom_set_ctrl(actionwk); /* Line 711, Address: 0x102cbc8 */
      break; /* Line 712, Address: 0x102cbd4 */
    case 2:
      bom_set_ctrl2(actionwk); /* Line 714, Address: 0x102cbdc */
      break;
  }

  actionwk->actfree[2] |= 4; /* Line 718, Address: 0x102cbe8 */
  jaba_last(actionwk); /* Line 719, Address: 0x102cbf8 */
  actionwk->yposi.l += ((int*)actionwk)[13]; /* Line 720, Address: 0x102cc04 */
  if (actionwk->yposi.w.h > ((short*)actionwk)[25]) return; /* Line 721, Address: 0x102cc1c */

  actionwk->actfree[2] &= 251; /* Line 723, Address: 0x102cc48 */
  actionwk->yposi.w.h = ((short*)actionwk)[25]; /* Line 724, Address: 0x102cc58 */
  if (actionwk->colicnt != 1) /* Line 725, Address: 0x102cc68 */
  {
    actionwk->actfree[0] = 0; /* Line 727, Address: 0x102cc80 */
    actionwk->colino = 63; /* Line 728, Address: 0x102cc88 */
    actionwk->r_no0 = 4; /* Line 729, Address: 0x102cc94 */
    ((short*)actionwk)[25] = actionwk->yposi.w.h - 72; /* Line 730, Address: 0x102cca0 */
  } /* Line 731, Address: 0x102ccc4 */
  else
  {
    genecolor(); /* Line 734, Address: 0x102cccc */
    actionwk->actfree[0] = 0; /* Line 735, Address: 0x102ccd4 */
    actionwk->r_no0 = 8; /* Line 736, Address: 0x102ccdc */
    ((short*)actionwk)[25] = actionwk->yposi.w.h - 16; /* Line 737, Address: 0x102cce8 */
  }
} /* Line 739, Address: 0x102cd0c */

void egg3dai_l_bom(sprite_status* actionwk) { /* Line 741, Address: 0x102cd20 */
  bom_set_dai(actionwk); /* Line 742, Address: 0x102cd2c */
  jaba_last(actionwk); /* Line 743, Address: 0x102cd38 */
  ++actionwk->actfree[0]; /* Line 744, Address: 0x102cd44 */
  if (actionwk->actfree[0] == 4) /* Line 745, Address: 0x102cd54 */
  {
    actionwk->patno = 6; /* Line 747, Address: 0x102cd6c */
  }

  actionwk->yposi.l += ((int*)actionwk)[13]; /* Line 750, Address: 0x102cd78 */
  if (actionwk->yposi.w.h > ((short*)actionwk)[25]) return; /* Line 751, Address: 0x102cd90 */
  actionwk->r_no0 = 10; /* Line 752, Address: 0x102cdbc */
} /* Line 753, Address: 0x102cdc8 */

void egg3dai_l_end(sprite_status* actionwk) { /* Line 755, Address: 0x102cde0 */
  sprite_status* a1;

  bom_set_dai(actionwk); /* Line 758, Address: 0x102cdf0 */
  jaba_last(actionwk); /* Line 759, Address: 0x102cdfc */
  if (!(actionwk->actfree[2] & 1)) return; /* Line 760, Address: 0x102ce08 */
  if (actionwk->actfree[16] == 4) /* Line 761, Address: 0x102ce20 */
  {
    a1 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 763, Address: 0x102ce38 */
    frameout(a1); /* Line 764, Address: 0x102ce5c */
    frameout(actionwk); /* Line 765, Address: 0x102ce68 */
  }
} /* Line 767, Address: 0x102ce74 */

void bom_set_dai(sprite_status* actionwk) { /* Line 769, Address: 0x102ce90 */
  sprite_status* a1;

  ++((short*)actionwk)[33]; /* Line 772, Address: 0x102cea0 */
  if (((short*)actionwk)[33] != 120) /* Line 773, Address: 0x102ceb0 */
  {
    if (((short*)actionwk)[33] < 120) /* Line 775, Address: 0x102cecc */
      bom_set(actionwk, bomtbl_dai); /* Line 776, Address: 0x102cee8 */
  } /* Line 777, Address: 0x102cefc */
  else
  {
    actionwk->actfree[2] |= 1; /* Line 780, Address: 0x102cf04 */
    a1 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 781, Address: 0x102cf14 */
    a1->actfree[2] |= 1; /* Line 782, Address: 0x102cf38 */
  }
} /* Line 784, Address: 0x102cf44 */

void bom_set_cannon(sprite_status* actionwk) { /* Line 786, Address: 0x102cf60 */
  ++((short*)actionwk)[33]; /* Line 787, Address: 0x102cf6c */
  if (((short*)actionwk)[33] < 4) /* Line 788, Address: 0x102cf7c */
    bom_set(actionwk, bomtbl_cannon); /* Line 789, Address: 0x102cf98 */

} /* Line 791, Address: 0x102cfac */

void bom_set_ctrl(sprite_status* actionwk) { /* Line 793, Address: 0x102cfc0 */
  ++((short*)actionwk)[33]; /* Line 794, Address: 0x102cfcc */
  if (((short*)actionwk)[33] < 4) /* Line 795, Address: 0x102cfdc */
    bom_set(actionwk, bomtbl_ctrl); /* Line 796, Address: 0x102cff8 */

} /* Line 798, Address: 0x102d00c */

void bom_set_ctrl2(sprite_status* actionwk) { /* Line 800, Address: 0x102d020 */
  ++((short*)actionwk)[33]; /* Line 801, Address: 0x102d02c */
  if (((short*)actionwk)[33] >= 3) return; /* Line 802, Address: 0x102d03c */
  bom_set(actionwk, bomtbl_ctrl2); /* Line 803, Address: 0x102d058 */
} /* Line 804, Address: 0x102d06c */

void bom_set(sprite_status* actionwk, char* tbl) { /* Line 806, Address: 0x102d080 */
  short d0, d2;
  char* a2;
  sprite_status* a1;

  a2 = tbl; /* Line 811, Address: 0x102d09c */
  d2 = ((short*)actionwk)[33]; /* Line 812, Address: 0x102d0a0 */
  d0 = a2[0]; /* Line 813, Address: 0x102d0b0 */
  if (d2 % d0 != 0) return; /* Line 814, Address: 0x102d0c4 */
  d2 /= d0; /* Line 815, Address: 0x102d0f0 */
  d2 %= a2[1]; /* Line 816, Address: 0x102d10c */
  d2 += d2; /* Line 817, Address: 0x102d134 */
  if (actwkchk(&a1) != 0) return; /* Line 818, Address: 0x102d140 */
  a1->xposi.w.h = actionwk->xposi.w.h + a2[d2 + 2]; /* Line 819, Address: 0x102d154 */
  a1->yposi.w.h = actionwk->yposi.w.h + a2[d2 + 3]; /* Line 820, Address: 0x102d19c */








  a1->actno = 24; /* Line 829, Address: 0x102d1e4 */
  a1->r_no1 = 255; /* Line 830, Address: 0x102d1f0 */
  soundset(158); /* Line 831, Address: 0x102d1fc */
} /* Line 832, Address: 0x102d208 */

void egg3(sprite_status* actionwk) { /* Line 834, Address: 0x102d230 */
  switch (actionwk->r_no0) /* Line 835, Address: 0x102d23c */
  {
    case 0:
      egg3_ini(actionwk); /* Line 838, Address: 0x102d288 */
    case 2:
      egg3_norm(actionwk); /* Line 840, Address: 0x102d294 */
      break; /* Line 841, Address: 0x102d2a0 */
    case 4:
      egg3_tobi(actionwk); /* Line 843, Address: 0x102d2a8 */
      break; /* Line 844, Address: 0x102d2b4 */
    case 6:
      egg3_esc1(actionwk); /* Line 846, Address: 0x102d2bc */
      break; /* Line 847, Address: 0x102d2c8 */
    case 8:
      egg3_esc2(actionwk); /* Line 849, Address: 0x102d2d0 */
      break;
  }
  if ((char)actionwk->actflg <= 0) /* Line 852, Address: 0x102d2dc */
    patchg(actionwk, egg3_pchg); /* Line 853, Address: 0x102d2fc */
  actionsub(actionwk); /* Line 854, Address: 0x102d310 */
} /* Line 855, Address: 0x102d31c */

void egg3_ini(sprite_status* actionwk) { /* Line 857, Address: 0x102d330 */
  actionwk->r_no0 = 2; /* Line 858, Address: 0x102d338 */
  actionwk->actflg = 4; /* Line 859, Address: 0x102d344 */
  actionwk->sprpri = 6; /* Line 860, Address: 0x102d350 */
  actionwk->sprhsize = 16; /* Line 861, Address: 0x102d35c */
  actionwk->sprvsize = 16; /* Line 862, Address: 0x102d368 */
  actionwk->sproffset = 798; /* Line 863, Address: 0x102d374 */
  actionwk->patbase = egg3_pat; /* Line 864, Address: 0x102d380 */
  ((short*)actionwk)[25] = actionwk->yposi.w.h - 16; /* Line 865, Address: 0x102d390 */
} /* Line 866, Address: 0x102d3b4 */

void egg3_norm(sprite_status* actionwk) { /* Line 868, Address: 0x102d3c0 */
  sprite_status* a1;

  a1 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 871, Address: 0x102d3cc */
  actionwk->yposi.w = a1->yposi.w; /* Line 872, Address: 0x102d3f0 */
} /* Line 873, Address: 0x102d40c */

void egg3_tobi(sprite_status* actionwk) { /* Line 875, Address: 0x102d420 */
  sprite_status* a1;

  actionwk->yposi.l += ((int*)actionwk)[13]; /* Line 878, Address: 0x102d42c */
  ((int*)actionwk)[13] += 12288; /* Line 879, Address: 0x102d444 */
  a1 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 880, Address: 0x102d454 */
  if (actionwk->yposi.w.h < a1->yposi.w.h) return; /* Line 881, Address: 0x102d478 */

  actionwk->yposi.w.h = a1->yposi.w.h; /* Line 883, Address: 0x102d4a0 */
  actionwk->r_no0 = 2; /* Line 884, Address: 0x102d4ac */
  if (a1->actfree[17] != 2) /* Line 885, Address: 0x102d4b8 */
  {
    actionwk->mstno.w = 1; /* Line 887, Address: 0x102d4cc */
  } /* Line 888, Address: 0x102d4d8 */
  else
  {
    a1->patno = 2; /* Line 891, Address: 0x102d4e0 */
    actionwk->sproffset = 1020; /* Line 892, Address: 0x102d4e8 */
    actionwk->mstno.w = 768; /* Line 893, Address: 0x102d4f4 */
  }
} /* Line 895, Address: 0x102d500 */

void egg3_esc1(sprite_status* actionwk) { /* Line 897, Address: 0x102d510 */
  actionwk->yposi.l += -262144; /* Line 898, Address: 0x102d518 */
  if (actionwk->yposi.w.h <= ((short*)actionwk)[25]) /* Line 899, Address: 0x102d52c */
  {
    actionwk->mstno.w = 1024; /* Line 901, Address: 0x102d558 */
    actionwk->sprpri = 3; /* Line 902, Address: 0x102d564 */
    actionwk->yposi.w.h = ((short*)actionwk)[25]; /* Line 903, Address: 0x102d570 */
    actionwk->r_no0 = 8; /* Line 904, Address: 0x102d580 */
    ((short*)actionwk)[25] = actionwk->xposi.w.h + 560; /* Line 905, Address: 0x102d58c */
  }
} /* Line 907, Address: 0x102d5b0 */

void egg3_esc2(sprite_status* actionwk) { /* Line 909, Address: 0x102d5c0 */
  actionwk->xposi.l += 262144; /* Line 910, Address: 0x102d5cc */
  if (actionwk->xposi.w.h < ((short*)actionwk)[25]) return; /* Line 911, Address: 0x102d5e0 */

  frameout(actionwk); /* Line 913, Address: 0x102d60c */
} /* Line 914, Address: 0x102d618 */

void egg3haguruma(sprite_status* actionwk) { /* Line 916, Address: 0x102d630 */
  sprite_status* a1;

  if (actionwk->r_no0 == 0) /* Line 919, Address: 0x102d640 */
  {

    actionwk->r_no0 += 2; /* Line 922, Address: 0x102d654 */
    actionwk->actflg = 4; /* Line 923, Address: 0x102d664 */
    actionwk->sprpri = 3; /* Line 924, Address: 0x102d670 */
    actionwk->sprhsize = 16; /* Line 925, Address: 0x102d67c */
    actionwk->sprvsize = 16; /* Line 926, Address: 0x102d688 */
    actionwk->sproffset = 798; /* Line 927, Address: 0x102d694 */
    actionwk->patbase = egg3haguruma_pat; /* Line 928, Address: 0x102d6a0 */
  }

  if (actionwk->actfree[2] & 1) return; /* Line 931, Address: 0x102d6b0 */
  a1 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 932, Address: 0x102d6c8 */
  actionwk->yposi.w.h = a1->yposi.w.h; /* Line 933, Address: 0x102d6ec */
  if (a1->actfree[2] & 4) /* Line 934, Address: 0x102d6f8 */
  {
    patchg(actionwk, egg3haguruma_pchg); /* Line 936, Address: 0x102d70c */
  }
  actionsub(actionwk); /* Line 938, Address: 0x102d720 */
} /* Line 939, Address: 0x102d72c */

void egg3cannon(sprite_status* actionwk) { /* Line 941, Address: 0x102d740 */
  sprite_status* a2;

  a2 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 944, Address: 0x102d750 */
  actionwk->yposi.w.h = a2->yposi.w.h + 32; /* Line 945, Address: 0x102d774 */
  if (a2->actfree[17]) /* Line 946, Address: 0x102d794 */
  {
    frameout(actionwk); /* Line 948, Address: 0x102d7a0 */
    return; /* Line 949, Address: 0x102d7ac */
  }

  switch (actionwk->r_no0) /* Line 952, Address: 0x102d7b4 */
  {
    case 0:
      egg3cannon_ini(actionwk); /* Line 955, Address: 0x102d7e8 */
      break; /* Line 956, Address: 0x102d7f4 */
    case 2:
      egg3cannon_01(actionwk); /* Line 958, Address: 0x102d7fc */
      break; /* Line 959, Address: 0x102d808 */
    case 4:
      egg3cannon_fire(actionwk); /* Line 961, Address: 0x102d810 */
      break;
  }
  actionsub(actionwk); /* Line 964, Address: 0x102d81c */
} /* Line 965, Address: 0x102d828 */

void egg3cannon_ini(sprite_status* actionwk) { /* Line 967, Address: 0x102d840 */
  actionwk->r_no0 += 2; /* Line 968, Address: 0x102d848 */
  actionwk->actflg = 4; /* Line 969, Address: 0x102d858 */
  actionwk->sprpri = 4; /* Line 970, Address: 0x102d864 */
  actionwk->sprhsize = 24; /* Line 971, Address: 0x102d870 */
  actionwk->sprvsize = 16; /* Line 972, Address: 0x102d87c */
  actionwk->sproffset = 1148; /* Line 973, Address: 0x102d888 */
  actionwk->patbase = egg3cannon_pat; /* Line 974, Address: 0x102d894 */
} /* Line 975, Address: 0x102d8a4 */

void egg3cannon_01(sprite_status* actionwk) { /* Line 977, Address: 0x102d8b0 */
  sprite_status *a1, *a2;
  int d0;
  short d1;

  a2 = &actwk[((unsigned short*)actionwk)[28]]; /* Line 982, Address: 0x102d8c8 */
  if (actwk[0].yposi.w.h >= 1024) return; /* Line 983, Address: 0x102d8ec */
  if (a2->actfree[16]) return; /* Line 984, Address: 0x102d908 */
  ++actionwk->actfree[0]; /* Line 985, Address: 0x102d914 */
  if (actionwk->actfree[0] >= 120) /* Line 986, Address: 0x102d924 */
  {

    actionwk->actfree[0] = 0; /* Line 989, Address: 0x102d93c */
    actionwk->r_no0 = 4; /* Line 990, Address: 0x102d944 */

    if (actwkchk(&a1) != 0) return; /* Line 992, Address: 0x102d950 */
    a1->actno = 62; /* Line 993, Address: 0x102d964 */
    a1->xposi.w.h = actionwk->xposi.w.h; /* Line 994, Address: 0x102d970 */
    a1->yposi.w.h = actionwk->yposi.w.h + 8; /* Line 995, Address: 0x102d980 */
    d0 = (unsigned int)(d0 = sRandom() << 45) >> 45; /* Line 996, Address: 0x102d9a4 */
    d0 %= 1024; /* Line 997, Address: 0x102d9bc */
    d1 = 12; /* Line 998, Address: 0x102d9dc */
    if (actionwk->patcnt == 0) /* Line 999, Address: 0x102d9e8 */
    {
      d0 = -d0; /* Line 1001, Address: 0x102d9fc */
      d1 = -d1; /* Line 1002, Address: 0x102da00 */
    }
    a1->xposi.w.h += d1; /* Line 1004, Address: 0x102da1c */
    a1->xspeed.w = d0; /* Line 1005, Address: 0x102da2c */
    a1->yspeed.w = 768; /* Line 1006, Address: 0x102da3c */

    a1->actfree[0] = 0; /* Line 1008, Address: 0x102da48 */
    a1->pattim = 0; /* Line 1009, Address: 0x102da50 */
  }
} /* Line 1011, Address: 0x102da58 */

void egg3cannon_fire(sprite_status* actionwk) { /* Line 1013, Address: 0x102da80 */
  unsigned char cannon_chg_tbl[8] = { 0, 1, 0, 2, 0, 3, 0, 4 }; /* Line 1014, Address: 0x102da8c */
  unsigned char d0;


  --actionwk->pattim; /* Line 1018, Address: 0x102dac0 */
  if ((char)actionwk->pattim > 0) return; /* Line 1019, Address: 0x102dad8 */
  d0 = actionwk->patcnt; /* Line 1020, Address: 0x102daf8 */
  ++d0; /* Line 1021, Address: 0x102db04 */
  if (d0 == 4) /* Line 1022, Address: 0x102db0c */
  {
    actionwk->r_no0 = 2; /* Line 1024, Address: 0x102db1c */
  } /* Line 1025, Address: 0x102db28 */
  else
    if (d0 == 8) /* Line 1027, Address: 0x102db30 */
    {
      d0 = 0; /* Line 1029, Address: 0x102db40 */
      actionwk->r_no0 = 2; /* Line 1030, Address: 0x102db44 */
    } /* Line 1031, Address: 0x102db50 */
    else
      actionwk->pattim = 2; /* Line 1033, Address: 0x102db58 */

  actionwk->patcnt = d0; /* Line 1035, Address: 0x102db64 */
  actionwk->patno = cannon_chg_tbl[d0]; /* Line 1036, Address: 0x102db6c */
} /* Line 1037, Address: 0x102db80 */

void punchbom(sprite_status* actionwk) { /* Line 1039, Address: 0x102db90 */
  switch (actionwk->r_no0) /* Line 1040, Address: 0x102db9c */
  {
    case 0:
      punchbom_ini(actionwk); /* Line 1043, Address: 0x102dbf4 */
    case 2:
      punchbom_mov(actionwk); /* Line 1045, Address: 0x102dc00 */
      break; /* Line 1046, Address: 0x102dc0c */
    case 4:
      punchbom_kem(actionwk); /* Line 1048, Address: 0x102dc14 */
      break; /* Line 1049, Address: 0x102dc20 */
    case 6:
      punchbom_del(actionwk); /* Line 1051, Address: 0x102dc28 */
      break; /* Line 1052, Address: 0x102dc34 */
    case 8:
      punchbom_kemini(actionwk); /* Line 1054, Address: 0x102dc3c */
      break; /* Line 1055, Address: 0x102dc48 */
    case 10:
      punchbom_fireini(actionwk); /* Line 1057, Address: 0x102dc50 */
      break;
  }
} /* Line 1060, Address: 0x102dc5c */

void punchbom_ini(sprite_status* actionwk) { /* Line 1062, Address: 0x102dc70 */
  actionwk->r_no0 = 2; /* Line 1063, Address: 0x102dc78 */
  actionwk->actflg = 4; /* Line 1064, Address: 0x102dc84 */
  actionwk->sprpri = 5; /* Line 1065, Address: 0x102dc90 */
  actionwk->sprhsize = 8; /* Line 1066, Address: 0x102dc9c */
  actionwk->sprvsize = 8; /* Line 1067, Address: 0x102dca8 */
  actionwk->sproffset = 1148; /* Line 1068, Address: 0x102dcb4 */
  actionwk->patbase = egg3punchbom_pat; /* Line 1069, Address: 0x102dcc0 */
  actionwk->colino = 215; /* Line 1070, Address: 0x102dcd0 */

  ((short*)actionwk)[30] = 0; /* Line 1072, Address: 0x102dcdc */
  ((short*)actionwk)[31] = 32; /* Line 1073, Address: 0x102dce4 */
  ((short*)actionwk)[32] = 1536; /* Line 1074, Address: 0x102dcf0 */
} /* Line 1075, Address: 0x102dcfc */

void punchbom_mov(sprite_status* actionwk) { /* Line 1077, Address: 0x102dd10 */
  short d1;

  if (actionwk->colicnt) /* Line 1080, Address: 0x102dd20 */
  {
    punchbom_hit(actionwk); /* Line 1082, Address: 0x102dd30 */
    return; /* Line 1083, Address: 0x102dd3c */
  }
  ++actionwk->actfree[0]; /* Line 1085, Address: 0x102dd44 */
  if (actionwk->actfree[0] >= 240) /* Line 1086, Address: 0x102dd54 */
  {
    punchbom_kemini(actionwk); /* Line 1088, Address: 0x102dd6c */
    return; /* Line 1089, Address: 0x102dd78 */
  }
  ++actionwk->pattim; /* Line 1091, Address: 0x102dd80 */

  if (actionwk->pattim >> 1 & 1) actionwk->patno = 1; /* Line 1093, Address: 0x102dd90 */
  else actionwk->patno = 0; /* Line 1094, Address: 0x102ddc0 */

  add_spd3(actionwk); /* Line 1096, Address: 0x102ddc8 */

  if (actionwk->actfree[1] >> 1 & 1) /* Line 1098, Address: 0x102ddd4 */
  {

    if (actionwk->yspeed.w >= 0) /* Line 1101, Address: 0x102ddf0 */
    {
      d1 = emycol_d(actionwk); /* Line 1103, Address: 0x102de08 */
      if (d1 <= 0) /* Line 1104, Address: 0x102de1c */
      {
        actionwk->yposi.w.h += d1; /* Line 1106, Address: 0x102de2c */
        actionwk->yspeed.w = -actionwk->yspeed.w; /* Line 1107, Address: 0x102de3c */
      }
    } /* Line 1109, Address: 0x102de60 */
    else
    {
      d1 = emycol_u(actionwk); /* Line 1112, Address: 0x102de68 */
      if (d1 <= 0) /* Line 1113, Address: 0x102de7c */
      {
        actionwk->yposi.w.h -= d1; /* Line 1115, Address: 0x102de8c */
        actionwk->yspeed.w = -actionwk->yspeed.w; /* Line 1116, Address: 0x102de9c */
      }
    }
  }
  if (actionwk->xspeed.w > 0) /* Line 1120, Address: 0x102dec0 */
  {
    d1 = emycol_r(actionwk, actionwk->sprhs); /* Line 1122, Address: 0x102ded8 */
    if (d1 <= 0) /* Line 1123, Address: 0x102def4 */
    {
      actionwk->xposi.w.h += d1; /* Line 1125, Address: 0x102df04 */
      actionwk->xspeed.w = -actionwk->xspeed.w; /* Line 1126, Address: 0x102df14 */
    }
  } /* Line 1128, Address: 0x102df38 */
  else
  {
    d1 = emycol_l(actionwk, actionwk->sprhs); /* Line 1131, Address: 0x102df40 */
    if (d1 <= 0) /* Line 1132, Address: 0x102df5c */
    {
      actionwk->xposi.w.h -= d1; /* Line 1134, Address: 0x102df6c */
      actionwk->xspeed.w = -actionwk->xspeed.w; /* Line 1135, Address: 0x102df7c */
    }
  }
  actionsub(actionwk); /* Line 1138, Address: 0x102dfa0 */
} /* Line 1139, Address: 0x102dfac */




void punchbom_hit(sprite_status* actionwk) { /* Line 1144, Address: 0x102dfc0 */
  sprite_status* a1;
  unsigned char d;
  int d0l, d1l;
  short d0, d1, d2;

  a1 = &actwk[0]; /* Line 1150, Address: 0x102dfe0 */
  actionwk->colicnt = 0; /* Line 1151, Address: 0x102dfe8 */
  d1 = actionwk->xposi.w.h - a1->xposi.w.h; /* Line 1152, Address: 0x102dff0 */
  d2 = actionwk->yposi.w.h - a1->yposi.w.h; /* Line 1153, Address: 0x102e01c */
  d = atan_sonic(d1, d2); /* Line 1154, Address: 0x102e04c */
  sinset(d, &d0, &d1); /* Line 1155, Address: 0x102e064 */
  d1l = d1 * -1792; /* Line 1156, Address: 0x102e078 */
  a1->xspeed.w = d1l >> 8; /* Line 1157, Address: 0x102e090 */
  d0l = d0 * -1792; /* Line 1158, Address: 0x102e0a0 */
  a1->yspeed.w = d1l >> 8; /* Line 1159, Address: 0x102e0b8 */
  a1->cddat |= 2; /* Line 1160, Address: 0x102e0c8 */
  a1->cddat &= 239; /* Line 1161, Address: 0x102e0d4 */
  a1->cddat &= 223; /* Line 1162, Address: 0x102e0e0 */
  a1->actfree[18] = 0; /* Line 1163, Address: 0x102e0ec */
  actionwk->mstno.b.h = 1; /* Line 1164, Address: 0x102e0f0 */
  if (actionwk->cdsts) /* Line 1165, Address: 0x102e0fc */
    if (flagwork[actionwk->cdsts] < 138) /* Line 1166, Address: 0x102e10c */
      ++flagwork[actionwk->cdsts]; /* Line 1167, Address: 0x102e138 */

  a1->cddat &= 247; /* Line 1169, Address: 0x102e15c */
  punchbom_kemini(actionwk); /* Line 1170, Address: 0x102e168 */
} /* Line 1171, Address: 0x102e174 */

void punchbom_kemini(sprite_status* actionwk) { /* Line 1173, Address: 0x102e1a0 */
  soundset(158); /* Line 1174, Address: 0x102e1ac */
  actionwk->mstno.w = 256; /* Line 1175, Address: 0x102e1b8 */
  actionwk->r_no0 = 4; /* Line 1176, Address: 0x102e1c4 */
  punchbom_bomset(actionwk); /* Line 1177, Address: 0x102e1d0 */
} /* Line 1178, Address: 0x102e1dc */

void punchbom_fireini(sprite_status* actionwk) { /* Line 1180, Address: 0x102e1f0 */
  actionwk->mstno.w = 1; /* Line 1181, Address: 0x102e1fc */
  actionwk->r_no0 = 4; /* Line 1182, Address: 0x102e208 */
  punchbom_bomset(actionwk); /* Line 1183, Address: 0x102e214 */
} /* Line 1184, Address: 0x102e220 */

void punchbom_bomset(sprite_status* actionwk) { /* Line 1186, Address: 0x102e230 */
  actionwk->colino = 0; /* Line 1187, Address: 0x102e23c */
  actionwk->actflg = 4; /* Line 1188, Address: 0x102e244 */
  actionwk->sprpri = 1; /* Line 1189, Address: 0x102e250 */
  actionwk->sprhsize = 16; /* Line 1190, Address: 0x102e25c */
  actionwk->sprvsize = 16; /* Line 1191, Address: 0x102e268 */
  actionwk->sproffset = 1664; /* Line 1192, Address: 0x102e274 */
  actionwk->patbase = bakupat; /* Line 1193, Address: 0x102e280 */
  punchbom_kem(actionwk); /* Line 1194, Address: 0x102e290 */
} /* Line 1195, Address: 0x102e29c */

void punchbom_kem(sprite_status* actionwk) { /* Line 1197, Address: 0x102e2b0 */
  patchg(actionwk, bakuchg); /* Line 1198, Address: 0x102e2bc */
  actionsub(actionwk); /* Line 1199, Address: 0x102e2d0 */
} /* Line 1200, Address: 0x102e2dc */

void punchbom_del(sprite_status* actionwk) { /* Line 1202, Address: 0x102e2f0 */
  frameout(actionwk); /* Line 1203, Address: 0x102e2fc */
} /* Line 1204, Address: 0x102e308 */

void add_spd3(sprite_status* actionwk) { /* Line 1206, Address: 0x102e320 */
  short d0;

  actionwk->yspeed.w += ((short*)actionwk)[31]; /* Line 1209, Address: 0x102e330 */
  actionwk->xspeed.w += ((short*)actionwk)[30]; /* Line 1210, Address: 0x102e348 */
  if (((short*)actionwk)[31] == 0) /* Line 1211, Address: 0x102e360 */
  {
    add_spd(actionwk); /* Line 1213, Address: 0x102e378 */
    return; /* Line 1214, Address: 0x102e384 */
  }
  if (((short*)actionwk)[31] > 0) /* Line 1216, Address: 0x102e38c */
  {
    d0 = ((short*)actionwk)[32]; /* Line 1218, Address: 0x102e3a4 */
    if (actionwk->yspeed.w < d0) /* Line 1219, Address: 0x102e3b4 */
    {
      add_spd(actionwk); /* Line 1221, Address: 0x102e3d8 */
    } /* Line 1222, Address: 0x102e3e4 */
    else
    {
      actionwk->yspeed.w = d0; /* Line 1225, Address: 0x102e3ec */
      add_spd(actionwk); /* Line 1226, Address: 0x102e3f4 */
    }
  } /* Line 1228, Address: 0x102e400 */
  else
  {
    d0 = ((short*)actionwk)[32]; /* Line 1231, Address: 0x102e408 */
    if (actionwk->yspeed.w > d0) /* Line 1232, Address: 0x102e418 */
    {
      add_spd(actionwk); /* Line 1234, Address: 0x102e43c */
    } /* Line 1235, Address: 0x102e448 */
    else
    {
      actionwk->yspeed.w = d0; /* Line 1238, Address: 0x102e450 */
      add_spd(actionwk); /* Line 1239, Address: 0x102e458 */
    }
  }
} /* Line 1242, Address: 0x102e464 */

void add_spd2(sprite_status* actionwk) { /* Line 1244, Address: 0x102e480 */
  actionwk->yspeed.w += ((short*)actionwk)[31]; /* Line 1245, Address: 0x102e48c */
  actionwk->xspeed.w += ((short*)actionwk)[30]; /* Line 1246, Address: 0x102e4a4 */
  add_spd(actionwk); /* Line 1247, Address: 0x102e4bc */
} /* Line 1248, Address: 0x102e4c8 */

void add_spd(sprite_status* actionwk) { /* Line 1250, Address: 0x102e4e0 */
  int d0;

  d0 = actionwk->xspeed.w; /* Line 1253, Address: 0x102e4ec */
  actionwk->xposi.l += d0 << 8; /* Line 1254, Address: 0x102e4fc */
  d0 = actionwk->yspeed.w; /* Line 1255, Address: 0x102e510 */
  actionwk->yposi.l += d0 << 8; /* Line 1256, Address: 0x102e520 */
} /* Line 1257, Address: 0x102e534 */
