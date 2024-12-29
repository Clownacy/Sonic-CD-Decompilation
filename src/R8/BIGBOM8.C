#include "..\EQU.H"
#include "BIGBOM8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\PLAYSUB.H"

static sprite_pattern pat000 =
{
  3,
  {
    { -4, -44, 0, 482 },
    { -28, 3, 0, 483 },
    { -20, -20, 0, 484 }
  }
};
static sprite_pattern pat001 =
{
  3,
  {
    { -4, -46, 0, 485 },
    { -20, 3, 0, 486 },
    { -20, -22, 0, 487 }
  }
};
static sprite_pattern pat002 =
{
  3,
  {
    { -4, -44, 0, 488 },
    { -20, 3, 0, 489 },
    { -20, -20, 0, 490 }
  }
};
static sprite_pattern pat003 =
{
  3,
  {
    { -4, -46, 0, 491 },
    { -12, 3, 0, 492 },
    { -20, -22, 0, 493 }
  }
};
static sprite_pattern pat004 =
{
  2,
  {
    { -28, 3, 0, 494 },
    { -20, -20, 0, 495 }
  }
};
sprite_pattern* pat_bigbom[5] =
{
  &pat000,
  &pat001,
  &pat002,
  &pat003,
  &pat004
};
static sprite_pattern pat100 =
{
  1,
  { { -4, -12, 0, 496 } }
};
static sprite_pattern pat101 =
{
  1,
  { { -4, -12, 0, 497 } }
};
sprite_pattern* pat1[2] =
{
  &pat100,
  &pat101
};
static sprite_pattern pat200 =
{
  1,
  { { -16, -8, 0, 498 } }
};
static sprite_pattern pat201 =
{
  1,
  { { -16, -16, 0, 499 } }
};
static sprite_pattern pat202 =
{
  1,
  { { -16, -16, 0, 500 } }
};
static sprite_pattern pat203 =
{
  1,
  { { -24, -24, 0, 501 } }
};
static sprite_pattern pat204 =
{
  1,
  { { -24, -24, 0, 502 } }
};
sprite_pattern* pat2[5] =
{
  &pat200,
  &pat201,
  &pat202,
  &pat203,
  &pat204
};
static sprite_pattern pat300 =
{
  1,
  { { -8, -8, 0, 503 } }
};
static sprite_pattern pat301 =
{
  1,
  { { -8, -8, 0, 504 } }
};
sprite_pattern* pat3[2] =
{
  &pat300,
  &pat301
};





































































void bigbom(sprite_status* pActwk) { /* Line 192, Address: 0x1026f00 */
  void(*tbl[5])(sprite_status*) = /* Line 193, Address: 0x1026f0c */
  {
    &bigbom0,
    &bigbom1,
    &bigbom2,
    &bigbom3,
    &bigbom4
  };

  tbl[pActwk->userflag.b.h / 2](pActwk); /* Line 202, Address: 0x1026f38 */
} /* Line 203, Address: 0x1026f78 */









































void bigbom0(sprite_status* pActwk) { /* Line 245, Address: 0x1026f90 */
  void(*tbl[7])(sprite_status*) = /* Line 246, Address: 0x1026f9c */
  {
    &m_move0,
    &m_move1,
    &m_move2,
    &m_move3,
    &m_move4,
    &m_move5,
    &m_move6
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 257, Address: 0x1026fc8 */
  if (pActwk->userflag.b.l != 2) /* Line 258, Address: 0x1027004 */
  {
    frameout_s00(pActwk, ((short*)pActwk)[24]); /* Line 260, Address: 0x1027020 */
  }
} /* Line 262, Address: 0x1027034 */




void m_move0(sprite_status* pActwk) { /* Line 267, Address: 0x1027050 */
  sprite_status* pNewActwk;

  ((short*)pActwk)[24] = pActwk->xposi.w.h; /* Line 270, Address: 0x102705c */

  if (actwkchk(&pNewActwk) != 0) /* Line 272, Address: 0x102706c */
  {
    frameout_s0(pActwk); /* Line 274, Address: 0x1027080 */
  } /* Line 275, Address: 0x102708c */
  else
  {
    pNewActwk->actno = pActwk->actno; /* Line 278, Address: 0x1027094 */
    pNewActwk->userflag.b.h = 2; /* Line 279, Address: 0x10270a4 */
    pNewActwk->userflag.b.l = pActwk->userflag.b.l; /* Line 280, Address: 0x10270b0 */
    pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 281, Address: 0x10270c0 */
    pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 282, Address: 0x10270d0 */
    ((short*)pNewActwk)[33] = (unsigned short)(pActwk - actwk); /* Line 283, Address: 0x10270e0 */

    ((short*)pActwk)[32] = (unsigned short)(pNewActwk - actwk); /* Line 285, Address: 0x102711c */
    pActwk->r_no0 += 2; /* Line 286, Address: 0x1027158 */

    m_move1(pActwk); /* Line 288, Address: 0x1027168 */
  }
} /* Line 290, Address: 0x1027174 */




void m_move1(sprite_status* pActwk) { /* Line 295, Address: 0x1027190 */

} /* Line 297, Address: 0x1027194 */




void m_move2(sprite_status* pActwk) { /* Line 302, Address: 0x10271a0 */
  ((short*)pActwk)[23] = 30; /* Line 303, Address: 0x10271ac */
  pActwk->r_no0 += 2; /* Line 304, Address: 0x10271b8 */

  m_move3(pActwk); /* Line 306, Address: 0x10271c8 */
} /* Line 307, Address: 0x10271d4 */




void m_move3(sprite_status* pActwk) { /* Line 312, Address: 0x10271f0 */
  sprite_status* pObj1wk;
  sprite_status* pNewActwk;

  --((short*)pActwk)[23]; /* Line 316, Address: 0x1027200 */
  if (((short*)pActwk)[23] == 0) /* Line 317, Address: 0x1027210 */
  {

    pObj1wk = &actwk[((short*)pActwk)[32]]; /* Line 320, Address: 0x1027228 */
    pObj1wk->r_no0 += 2; /* Line 321, Address: 0x1027250 */

    if (actwkchk(&pNewActwk) != 0) /* Line 323, Address: 0x102725c */
    {
      frameout(pActwk); /* Line 325, Address: 0x1027270 */
    } /* Line 326, Address: 0x102727c */
    else
    {
      pNewActwk->actno = pActwk->actno; /* Line 329, Address: 0x1027284 */
      pNewActwk->userflag.b.h = 4; /* Line 330, Address: 0x1027294 */

      ((short*)pNewActwk)[33] = (unsigned short)(pActwk - actwk); /* Line 332, Address: 0x10272a0 */
      pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 333, Address: 0x10272dc */
      pNewActwk->yposi.w.h = pActwk->yposi.w.h - 31; /* Line 334, Address: 0x10272ec */
      pObj1wk = &actwk[((short*)pActwk)[32]]; /* Line 335, Address: 0x1027310 */
      if (pObj1wk->actflg & 1) /* Line 336, Address: 0x1027338 */
      {
        pNewActwk->actflg ^= 1; /* Line 338, Address: 0x102734c */
        pNewActwk->cddat ^= 1; /* Line 339, Address: 0x102735c */
      }
      pActwk->r_no0 += 2; /* Line 341, Address: 0x102736c */
    }
  }
} /* Line 344, Address: 0x102737c */




void m_move4(sprite_status* pActwk) { /* Line 349, Address: 0x1027390 */

} /* Line 351, Address: 0x1027394 */




void m_move5(sprite_status* pActwk) { /* Line 356, Address: 0x10273a0 */
  ((short*)pActwk)[23] = 0; /* Line 357, Address: 0x10273ac */
  pActwk->r_no0 += 2; /* Line 358, Address: 0x10273b4 */

  m_move6(pActwk); /* Line 360, Address: 0x10273c4 */
} /* Line 361, Address: 0x10273d0 */




void m_move6(sprite_status* pActwk) { /* Line 366, Address: 0x10273e0 */
  sprite_status* pObj1wk;
  sprite_status* pNewActwk;
  sprite_status* pAct1;

  ++((short*)pActwk)[23]; /* Line 371, Address: 0x10273f0 */

  if (((short*)pActwk)[23] == 32) /* Line 373, Address: 0x1027400 */
  {
    pObj1wk = &actwk[((short*)pActwk)[32]]; /* Line 375, Address: 0x102741c */
    pObj1wk->r_no0 += 2; /* Line 376, Address: 0x1027444 */
  }

  if (((short*)pActwk)[23] == 30) /* Line 379, Address: 0x1027450 */
  {
    if (actwkchk(&pNewActwk) != 0) /* Line 381, Address: 0x102746c */
    {
      frameout(pActwk); /* Line 383, Address: 0x1027480 */
      return; /* Line 384, Address: 0x102748c */
    }


    pNewActwk->actno = pActwk->actno; /* Line 388, Address: 0x1027494 */
    pNewActwk->userflag.b.h = 6; /* Line 389, Address: 0x10274a4 */
    pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 390, Address: 0x10274b0 */
    pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 391, Address: 0x10274c0 */
  }


  if (((short*)pActwk)[23] == 31) /* Line 395, Address: 0x10274d0 */
  {
    make_fire(pActwk, &pAct1); /* Line 397, Address: 0x10274ec */
    *(int*)&pAct1->actfree[0] = -65536; /* Line 398, Address: 0x10274fc */
    *(int*)&pAct1->actfree[4] = -270336; /* Line 399, Address: 0x102750c */
    make_fire(pActwk, &pAct1); /* Line 400, Address: 0x1027520 */
    *(int*)&pAct1->actfree[0] = -0x20000; /* Line 401, Address: 0x1027530 */
    *(int*)&pAct1->actfree[4] = -335872; /* Line 402, Address: 0x1027540 */
    make_fire(pActwk, &pAct1); /* Line 403, Address: 0x1027554 */
    *(int*)&pAct1->actfree[0] = -196608; /* Line 404, Address: 0x1027564 */
    *(int*)&pAct1->actfree[4] = -401408; /* Line 405, Address: 0x1027574 */
    make_fire(pActwk, &pAct1); /* Line 406, Address: 0x1027588 */
    *(int*)&pAct1->actfree[0] = 65536; /* Line 407, Address: 0x1027598 */
    *(int*)&pAct1->actfree[4] = -270336; /* Line 408, Address: 0x10275a8 */
    make_fire(pActwk, &pAct1); /* Line 409, Address: 0x10275bc */
    *(int*)&pAct1->actfree[0] = 0x20000; /* Line 410, Address: 0x10275cc */
    *(int*)&pAct1->actfree[4] = -335872; /* Line 411, Address: 0x10275dc */
    make_fire(pActwk, &pAct1); /* Line 412, Address: 0x10275f0 */
    *(int*)&pAct1->actfree[0] = 196608; /* Line 413, Address: 0x1027600 */
    *(int*)&pAct1->actfree[4] = -401408; /* Line 414, Address: 0x1027610 */
    make_fire(pActwk, &pAct1); /* Line 415, Address: 0x1027624 */
    *(int*)&pAct1->actfree[0] = 0; /* Line 416, Address: 0x1027634 */
    *(int*)&pAct1->actfree[4] = -204800; /* Line 417, Address: 0x1027640 */
  }

  if (((short*)pActwk)[23] == 40) /* Line 420, Address: 0x1027654 */
  {
    frameout(pActwk); /* Line 422, Address: 0x1027670 */
  }
} /* Line 424, Address: 0x102767c */


void make_fire(sprite_status* pActwk, sprite_status** pNewActwk) { /* Line 427, Address: 0x1027690 */
  if (actwkchk(pNewActwk) != 0) /* Line 428, Address: 0x10276a0 */
  {
    frameout_s0(pActwk); /* Line 430, Address: 0x10276b4 */
  } /* Line 431, Address: 0x10276c0 */
  else
  {
    (*pNewActwk)->actno = pActwk->actno; /* Line 434, Address: 0x10276c8 */
    (*pNewActwk)->userflag.b.h = 8; /* Line 435, Address: 0x10276dc */
    (*pNewActwk)->userflag.b.l = pActwk->userflag.b.l; /* Line 436, Address: 0x10276ec */
    (*pNewActwk)->xposi.w.h = pActwk->xposi.w.h; /* Line 437, Address: 0x1027700 */
    (*pNewActwk)->yposi.w.h = pActwk->yposi.w.h; /* Line 438, Address: 0x1027714 */
    *(int*)&(*pNewActwk)->actfree[8] = 0; /* Line 439, Address: 0x1027728 */
    *(int*)&(*pNewActwk)->actfree[12] = 8192; /* Line 440, Address: 0x1027738 */
  }
} /* Line 442, Address: 0x102774c */


























void bigbom1(sprite_status* pActwk) { /* Line 469, Address: 0x1027760 */
  sprite_status* pMainwk;

  void(*tbl[13])(sprite_status*) = /* Line 472, Address: 0x1027770 */
  {
    &s0_init,
    &s0_fall,
    &s0_wait,
    &s0_move_const0,
    &s0_move_const,
    &s0_prio_const,
    &s0_move0,
    &s0_move,
    &s0_stop,
    &s0_stop0,
    &s0_move1,
    &s0_stop1,
    &s0_die
  };



  tbl[pActwk->r_no0 / 2](pActwk); /* Line 491, Address: 0x102779c */
  pMainwk = &actwk[((short*)pActwk)[33]]; /* Line 492, Address: 0x10277d8 */
  if (pMainwk->actno == 35) /* Line 493, Address: 0x1027800 */
  {
    pMainwk->xposi.w.h = pActwk->xposi.w.h; /* Line 495, Address: 0x1027814 */
    pMainwk->yposi.w.h = pActwk->yposi.w.h; /* Line 496, Address: 0x1027820 */
    actionsub(pActwk); /* Line 497, Address: 0x102782c */
  } /* Line 498, Address: 0x1027838 */
  else
  {
    frameout(pActwk); /* Line 501, Address: 0x1027840 */
  }
} /* Line 503, Address: 0x102784c */




void s0_init(sprite_status* pActwk) { /* Line 508, Address: 0x1027860 */
  pActwk->actflg |= 4; /* Line 509, Address: 0x102786c */
  pActwk->sprpri = 1; /* Line 510, Address: 0x102787c */
  pActwk->sproffset = 33600; /* Line 511, Address: 0x1027888 */
  pActwk->patbase = pat_bigbom; /* Line 512, Address: 0x1027894 */
  pActwk->sprhsize = 20; /* Line 513, Address: 0x10278a4 */
  pActwk->sprvsize = 26; /* Line 514, Address: 0x10278b0 */
  pActwk->actfree[19] = 166; /* Line 515, Address: 0x10278bc */
  pActwk->r_no0 += 2; /* Line 516, Address: 0x10278c8 */

  s0_fall(pActwk); /* Line 518, Address: 0x10278d8 */
} /* Line 519, Address: 0x10278e4 */




void s0_fall(sprite_status* pActwk) { /* Line 524, Address: 0x1027900 */
  short d1;

  pActwk->yposi.l += 65536; /* Line 527, Address: 0x1027910 */
  d1 = emycol_d(pActwk); /* Line 528, Address: 0x1027924 */
  if (d1 < 0) /* Line 529, Address: 0x1027938 */
  {
    pActwk->yposi.w.h += d1; /* Line 531, Address: 0x1027948 */
    if (pActwk->userflag.b.l != 2) /* Line 532, Address: 0x1027958 */
    {
      pActwk->r_no0 = 12; /* Line 534, Address: 0x1027974 */
      pActwk->colino = 166; /* Line 535, Address: 0x1027980 */
    } /* Line 536, Address: 0x102798c */
    else
    {
      pActwk->r_no0 += 2; /* Line 539, Address: 0x1027994 */
      pActwk->actflg ^= 1; /* Line 540, Address: 0x10279a4 */
      pActwk->cddat ^= 1; /* Line 541, Address: 0x10279b4 */
    }
  }
} /* Line 544, Address: 0x10279c4 */




void s0_wait(sprite_status* pActwk) { /* Line 549, Address: 0x10279e0 */
  sprite_status* pPlayerwk;
  short d0;

  pPlayerwk = &actwk[0]; /* Line 553, Address: 0x10279f4 */
  if (s0_check(pActwk, pPlayerwk)) /* Line 554, Address: 0x10279fc */
  {
    d0 = pPlayerwk->xposi.w.h; /* Line 556, Address: 0x1027a14 */
    d0 -= pActwk->xposi.w.h; /* Line 557, Address: 0x1027a20 */
    if (d0 >= 0) /* Line 558, Address: 0x1027a34 */
    {
      pActwk->r_no0 += 2; /* Line 560, Address: 0x1027a44 */
      s0_move_const0(pActwk); /* Line 561, Address: 0x1027a54 */
    }
  }
} /* Line 564, Address: 0x1027a60 */




void s0_move_const0(sprite_status* pActwk) { /* Line 569, Address: 0x1027a80 */
  pActwk->r_no0 += 2; /* Line 570, Address: 0x1027a8c */
  ((int*)pActwk)[12] = 163840; /* Line 571, Address: 0x1027a9c */
  ((short*)pActwk)[23] = 230; /* Line 572, Address: 0x1027aac */
  ((short*)pActwk)[26] = 18; /* Line 573, Address: 0x1027ab8 */
  pActwk->patno = 3; /* Line 574, Address: 0x1027ac4 */

  s0_move_const(pActwk); /* Line 576, Address: 0x1027ad0 */
} /* Line 577, Address: 0x1027adc */




void s0_move_const(sprite_status* pActwk) { /* Line 582, Address: 0x1027af0 */
  unsigned char bd0;
  short tbl[4] = { 25, 15, 25, 18 }; /* Line 584, Address: 0x1027afc */




  bd0 = 0; /* Line 589, Address: 0x1027b28 */
  if (prio_flag == 0) /* Line 590, Address: 0x1027b2c */
  {
    bd0 = pActwk->actfree[19]; /* Line 592, Address: 0x1027b40 */
  }
  pActwk->colino = bd0; /* Line 594, Address: 0x1027b4c */

  pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 596, Address: 0x1027b54 */

  --((short*)pActwk)[26]; /* Line 598, Address: 0x1027b6c */
  if (((short*)pActwk)[26] < 0) /* Line 599, Address: 0x1027b7c */
  {
    ++pActwk->patno; /* Line 601, Address: 0x1027b94 */
    pActwk->patno &= 3; /* Line 602, Address: 0x1027ba4 */
    ((short*)pActwk)[26] = tbl[pActwk->patno]; /* Line 603, Address: 0x1027bb4 */
  }
  --((short*)pActwk)[23]; /* Line 605, Address: 0x1027bd4 */
  if (((short*)pActwk)[23] < 0) /* Line 606, Address: 0x1027be4 */
  {
    pActwk->r_no0 += 2; /* Line 608, Address: 0x1027bfc */
  }
} /* Line 610, Address: 0x1027c0c */




void s0_prio_const(sprite_status* pActwk) { /* Line 615, Address: 0x1027c20 */
  unsigned char bd0;

  bd0 = 0; /* Line 618, Address: 0x1027c30 */
  if (prio_flag == 0) /* Line 619, Address: 0x1027c34 */
  {
    bd0 = pActwk->actfree[19]; /* Line 621, Address: 0x1027c48 */
  }
  pActwk->colino = bd0; /* Line 623, Address: 0x1027c54 */

  if (prio_flag == 0) /* Line 625, Address: 0x1027c5c */
  {
    if (s0_check(pActwk, &actwk[0])) /* Line 627, Address: 0x1027c70 */
    {
      pActwk->r_no0 = 16; /* Line 629, Address: 0x1027c8c */
    }
  }
} /* Line 632, Address: 0x1027c98 */




void s0_move0(sprite_status* pActwk) { /* Line 637, Address: 0x1027cb0 */
  pActwk->r_no0 += 2; /* Line 638, Address: 0x1027cbc */
  ((int*)pActwk)[12] = -40960; /* Line 639, Address: 0x1027ccc */
  ((short*)pActwk)[23] = 0; /* Line 640, Address: 0x1027cdc */
  ((short*)pActwk)[26] = 0; /* Line 641, Address: 0x1027ce4 */
  pActwk->patno = 3; /* Line 642, Address: 0x1027cec */

  s0_move(pActwk); /* Line 644, Address: 0x1027cf8 */
} /* Line 645, Address: 0x1027d04 */




void s0_move(sprite_status* pActwk) { /* Line 650, Address: 0x1027d20 */
  short d0, d1;
  short tbl[4] = { 25, 15, 25, 18 }; /* Line 652, Address: 0x1027d34 */




  pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 657, Address: 0x1027d60 */

  d1 = emycol_d(pActwk); /* Line 659, Address: 0x1027d78 */
  pActwk->yposi.w.h += d1; /* Line 660, Address: 0x1027d8c */

  --((short*)pActwk)[23]; /* Line 662, Address: 0x1027d9c */
  if (((short*)pActwk)[23] < 0) /* Line 663, Address: 0x1027dac */
  {
    ((int*)pActwk)[12] *= -1; /* Line 665, Address: 0x1027dc4 */
    pActwk->actflg ^= 1; /* Line 666, Address: 0x1027dd4 */
    pActwk->cddat ^= 1; /* Line 667, Address: 0x1027de4 */
    d0 = 204; /* Line 668, Address: 0x1027df4 */
    if (pActwk->userflag.b.l) /* Line 669, Address: 0x1027e00 */
    {
      d0 = 25; /* Line 671, Address: 0x1027e10 */
    }
    ((short*)pActwk)[23] = d0; /* Line 673, Address: 0x1027e1c */
  }
  --((short*)pActwk)[26]; /* Line 675, Address: 0x1027e24 */
  if (((short*)pActwk)[26] < 0) /* Line 676, Address: 0x1027e34 */
  {
    ++pActwk->patno; /* Line 678, Address: 0x1027e4c */
    pActwk->patno &= 3; /* Line 679, Address: 0x1027e5c */
    ((short*)pActwk)[26] = tbl[pActwk->patno]; /* Line 680, Address: 0x1027e6c */
  }
  if (pActwk->patno == 0) /* Line 682, Address: 0x1027e8c */
  {
    if (s0_check(pActwk, &actwk[0])) /* Line 684, Address: 0x1027ea0 */
    {
      to_s0_stop(pActwk); /* Line 686, Address: 0x1027ebc */
    }
  }
} /* Line 689, Address: 0x1027ec8 */




short s0_check(sprite_status* pActwk, sprite_status* pPlayerwk) { /* Line 694, Address: 0x1027ee0 */
  short d0;
  short carry;

  d0 = pPlayerwk->yposi.w.h; /* Line 698, Address: 0x1027ef4 */
  d0 -= pActwk->yposi.w.h; /* Line 699, Address: 0x1027f04 */
  d0 += 160; /* Line 700, Address: 0x1027f18 */
  if ((unsigned short)d0 < 240) /* Line 701, Address: 0x1027f24 */
  {
    d0 = pPlayerwk->xposi.w.h; /* Line 703, Address: 0x1027f38 */
    d0 -= pActwk->xposi.w.h; /* Line 704, Address: 0x1027f48 */
    d0 += 96; /* Line 705, Address: 0x1027f5c */
    if ((unsigned short)d0 < 192) carry = 1; /* Line 706, Address: 0x1027f68 */
    else carry = 0; /* Line 707, Address: 0x1027f90 */
  } /* Line 708, Address: 0x1027f94 */
  else
  {
    carry = 0; /* Line 711, Address: 0x1027f9c */
  }
  return carry; /* Line 713, Address: 0x1027fa0 */
} /* Line 714, Address: 0x1027fa4 */




void to_s0_stop(sprite_status* pActwk) { /* Line 719, Address: 0x1027fc0 */
  pActwk->r_no0 += 2; /* Line 720, Address: 0x1027fcc */

  s0_stop(pActwk); /* Line 722, Address: 0x1027fdc */
} /* Line 723, Address: 0x1027fe8 */




void s0_stop(sprite_status* pActwk) { /* Line 728, Address: 0x1028000 */
  sprite_status* pMainwk;

  pActwk->r_no0 += 2; /* Line 731, Address: 0x1028010 */
  pMainwk = &actwk[((short*)pActwk)[33]]; /* Line 732, Address: 0x1028020 */
  pMainwk->r_no0 += 2; /* Line 733, Address: 0x1028048 */

  s0_stop0(pActwk); /* Line 735, Address: 0x1028054 */
} /* Line 736, Address: 0x1028060 */




void s0_stop0(sprite_status* pActwk) { /* Line 741, Address: 0x1028080 */
  unsigned char bd0;

  if (pActwk->userflag.b.l == 2) /* Line 744, Address: 0x102808c */
  {
    bd0 = 0; /* Line 746, Address: 0x10280a8 */
    if (prio_flag == 0) /* Line 747, Address: 0x10280ac */
    {
      bd0 = pActwk->actfree[19]; /* Line 749, Address: 0x10280c0 */
    }
    pActwk->colino = bd0; /* Line 751, Address: 0x10280cc */
  }
} /* Line 753, Address: 0x10280d4 */




void s0_move1(sprite_status* pActwk) { /* Line 758, Address: 0x10280f0 */
  pActwk->patno = 4; /* Line 759, Address: 0x10280fc */
  pActwk->r_no0 += 2; /* Line 760, Address: 0x1028108 */

  s0_stop1(pActwk); /* Line 762, Address: 0x1028118 */
} /* Line 763, Address: 0x1028124 */




void s0_stop1(sprite_status* pActwk) { /* Line 768, Address: 0x1028140 */
  s0_stop0(pActwk); /* Line 769, Address: 0x102814c */
} /* Line 770, Address: 0x1028158 */




void s0_die(sprite_status* pActwk) { /* Line 775, Address: 0x1028170 */
  frameout(pActwk); /* Line 776, Address: 0x102817c */
} /* Line 777, Address: 0x1028188 */

















void bigbom2(sprite_status* pActwk) { /* Line 795, Address: 0x10281a0 */
  void(*tbl[4])(sprite_status*) = /* Line 796, Address: 0x10281ac */
  {
    &s1_init,
    &s1_wait,
    &s1_move,
    &s1_die
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 804, Address: 0x10281d8 */
  actionsub(pActwk); /* Line 805, Address: 0x1028214 */
} /* Line 806, Address: 0x1028220 */




void s1_init(sprite_status* pActwk) { /* Line 811, Address: 0x1028230 */
  pActwk->r_no0 += 2; /* Line 812, Address: 0x102823c */
  pActwk->actflg |= 4; /* Line 813, Address: 0x102824c */
  pActwk->sprpri = 2; /* Line 814, Address: 0x102825c */

  pActwk->sproffset = 832; /* Line 816, Address: 0x1028268 */
  pActwk->patbase = pat1; /* Line 817, Address: 0x1028274 */
  pActwk->sprhsize = 4; /* Line 818, Address: 0x1028284 */
  pActwk->sprvsize = 12; /* Line 819, Address: 0x1028290 */
  ((short*)pActwk)[23] = 60; /* Line 820, Address: 0x102829c */

  s1_wait(pActwk); /* Line 822, Address: 0x10282a8 */
} /* Line 823, Address: 0x10282b4 */




void s1_wait(sprite_status* pActwk) { /* Line 828, Address: 0x10282d0 */
  static unsigned char pat00[4] = { 2, 0, 1, 255 };
  static unsigned char* pchg1[1] = { pat00 };








  --((short*)pActwk)[23]; /* Line 839, Address: 0x10282dc */
  if (((short*)pActwk)[23] == 0) /* Line 840, Address: 0x10282ec */
  {
    ((short*)pActwk)[23] = 76; /* Line 842, Address: 0x1028304 */
    pActwk->r_no0 += 2; /* Line 843, Address: 0x1028310 */
  }
  patchg(pActwk, pchg1); /* Line 845, Address: 0x1028320 */
} /* Line 846, Address: 0x1028334 */




void s1_move(sprite_status* pActwk) { /* Line 851, Address: 0x1028350 */
  static unsigned char pat00[4] = { 2, 0, 1, 255 };
  static unsigned char* pchg1[1] = { pat00 };








  pActwk->yposi.l += 20480; /* Line 862, Address: 0x102835c */
  --((short*)pActwk)[23]; /* Line 863, Address: 0x102836c */
  if (((short*)pActwk)[23] < 0) /* Line 864, Address: 0x102837c */
  {
    pActwk->r_no0 += 2; /* Line 866, Address: 0x1028394 */
  }
  patchg(pActwk, pchg1); /* Line 868, Address: 0x10283a4 */
} /* Line 869, Address: 0x10283b8 */




void s1_die(sprite_status* pActwk) { /* Line 874, Address: 0x10283d0 */
  sprite_status* pMainwk;

  pMainwk = &actwk[((short*)pActwk)[33]]; /* Line 877, Address: 0x10283e0 */
  if (pMainwk->actno == 35) /* Line 878, Address: 0x1028408 */
  {
    pMainwk->r_no0 += 2; /* Line 880, Address: 0x102841c */
  }
  frameout(pActwk); /* Line 882, Address: 0x1028428 */
} /* Line 883, Address: 0x1028434 */











void bigbom3(sprite_status* pActwk) { /* Line 895, Address: 0x1028450 */
  void(*tbl[2])(sprite_status*) = /* Line 896, Address: 0x102845c */
  {
    &s2_init,
    &s2_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 902, Address: 0x1028478 */
  actionsub(pActwk); /* Line 903, Address: 0x10284b4 */
} /* Line 904, Address: 0x10284c0 */




void s2_init(sprite_status* pActwk) { /* Line 909, Address: 0x10284d0 */
  pActwk->r_no0 += 2; /* Line 910, Address: 0x10284dc */
  pActwk->actflg |= 4; /* Line 911, Address: 0x10284ec */
  pActwk->sprpri = 1; /* Line 912, Address: 0x10284fc */
  pActwk->sproffset = 34432; /* Line 913, Address: 0x1028508 */
  pActwk->patbase = pat2; /* Line 914, Address: 0x1028514 */
  ((short*)pActwk)[23] = 40; /* Line 915, Address: 0x1028524 */

  s2_move(pActwk); /* Line 917, Address: 0x1028530 */
} /* Line 918, Address: 0x102853c */




void s2_move(sprite_status* pActwk) { /* Line 923, Address: 0x1028550 */
  static unsigned char pat00[7] = { 3, 0, 1, 2, 3, 4, 255 };
  static unsigned char* pchg2[1] = { pat00 };








  --((short*)pActwk)[23]; /* Line 934, Address: 0x102855c */
  if (((short*)pActwk)[23] == 0) /* Line 935, Address: 0x102856c */
  {
    frameout(pActwk); /* Line 937, Address: 0x1028584 */
  } /* Line 938, Address: 0x1028590 */
  else
  {
    patchg(pActwk, pchg2); /* Line 941, Address: 0x1028598 */
  }
} /* Line 943, Address: 0x10285ac */

















void bigbom4(sprite_status* pActwk) { /* Line 961, Address: 0x10285c0 */
  void(*tbl[2])(sprite_status*) = /* Line 962, Address: 0x10285cc */
  {
    &s3_init,
    &s3_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 968, Address: 0x10285e8 */
  actionsub(pActwk); /* Line 969, Address: 0x1028624 */
} /* Line 970, Address: 0x1028630 */




void s3_init(sprite_status* pActwk) { /* Line 975, Address: 0x1028640 */
  pActwk->r_no0 += 2; /* Line 976, Address: 0x102864c */
  pActwk->actflg |= 4; /* Line 977, Address: 0x102865c */
  pActwk->sprpri = 1; /* Line 978, Address: 0x102866c */
  pActwk->sprhsize = 8; /* Line 979, Address: 0x1028678 */
  pActwk->sprvsize = 8; /* Line 980, Address: 0x1028684 */
  pActwk->sproffset = 33600; /* Line 981, Address: 0x1028690 */
  pActwk->patbase = pat3; /* Line 982, Address: 0x102869c */
  pActwk->colino = 167; /* Line 983, Address: 0x10286ac */
  pActwk->actfree[19] = 167; /* Line 984, Address: 0x10286b8 */

  s3_move(pActwk); /* Line 986, Address: 0x10286c4 */
} /* Line 987, Address: 0x10286d0 */




void s3_move(sprite_status* pActwk) { /* Line 992, Address: 0x10286e0 */
  sprite_status* pPlayerwk;
  short d0;
  unsigned char bd0;
  static unsigned char pat00[4] = { 1, 0, 1, 255 };
  static unsigned char* pchg3[1] = { pat00 };








  if (pActwk->userflag.b.l == 2) /* Line 1006, Address: 0x10286f8 */
  {
    bd0 = 0; /* Line 1008, Address: 0x1028714 */
    if (prio_flag == 0) /* Line 1009, Address: 0x1028718 */
    {
      bd0 = pActwk->actfree[19]; /* Line 1011, Address: 0x102872c */
    }
    pActwk->colino = bd0; /* Line 1013, Address: 0x1028738 */
  }

  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 1016, Address: 0x1028740 */
  pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 1017, Address: 0x102875c */
  *(int*)&pActwk->actfree[0] += *(int*)&pActwk->actfree[8]; /* Line 1018, Address: 0x1028778 */
  *(int*)&pActwk->actfree[4] += *(int*)&pActwk->actfree[12]; /* Line 1019, Address: 0x102879c */

  pPlayerwk = &actwk[0]; /* Line 1021, Address: 0x10287c0 */
  d0 = pActwk->yposi.w.h; /* Line 1022, Address: 0x10287c8 */
  d0 -= pPlayerwk->yposi.w.h; /* Line 1023, Address: 0x10287d8 */
  if (d0 >= 224) /* Line 1024, Address: 0x10287e8 */
  {
    frameout(pActwk); /* Line 1026, Address: 0x10287fc */
  } /* Line 1027, Address: 0x1028808 */
  else
  {
    patchg(pActwk, pchg3); /* Line 1030, Address: 0x1028810 */
  }
} /* Line 1032, Address: 0x1028824 */
