#include "EQU.H"
#include "ENEMY.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "DIRCOL.H"
#include "DUMMY.H"
#include "ETC.H"
#include "PLAYSUB.H"
#include "SUICIDE.H"

extern void soundset(short ReqNo);

unsigned char ari_pchg00[4] = { 3, 0, 1, 255 };
unsigned char ari_pchg01[4] = { 7, 2, 3, 255 };
unsigned char* ari_pchg[2] =
{
  ari_pchg00,
  ari_pchg01
};
spr_array ari0 =
{
  3,
  {
    { -12, -19, 0, 370 },
    {  -8,   4, 0, 371 },
    {  14,  -4, 0, 372 }
  }
};
spr_array ari1 =
{
  3,
  {
    { -12, -20, 0, 373 },
    {  -8,   4, 0, 374 },
    {  18,  -4, 0, 375 }
  }
};
spr_array ari2 =
{
  3,
  {
    { -12, -19, 0, 376 },
    {  -8,   4, 0, 377 },
    {  14,  -4, 0, 378 }
  }
};
spr_array ari3 =
{
  3,
  {
    { -12, -20, 0, 379 },
    {  -8,   4, 0, 380 },
    {  18,  -4, 0, 381 }
  }
};
spr_array* ari_pat[4] =
{
  &ari0,
  &ari1,
  &ari2,
  &ari3
};
unsigned char chou_pchg00[7] = { 7, 0, 0, 1, 2, 1, 255 };
unsigned char chou_pchg01[7] = { 3, 0, 0, 1, 2, 1, 255 };
unsigned char* chou_pchg[2] =
{
  chou_pchg00,
  chou_pchg01
};
spr_array chou1e =
{
  1,
  { { -16, -16, 0, 394 } }
};
spr_array chou2e =
{
  1,
  { { -16, -8, 0, 395 } }
};
spr_array chou3e =
{
  1,
  { { -16, -16, 0, 396 } }
};
spr_array chou1b =
{
  1,
  { { -16, -16, 0, 397 } }
};
spr_array chou2b =
{
  1,
  { { -16, -8, 0, 398 } }
};
spr_array chou3b =
{
  1,
  { { -16, -16, 0, 399 } }
};
spr_array* e_chou_pat[3] =
{
  &chou1e,
  &chou2e,
  &chou3e
};
spr_array* b_chou_pat[3] =
{
  &chou1b,
  &chou2b,
  &chou3b
};
unsigned char pchg_e_0[4] = { 1, 0, 1, 255 };
unsigned char pchg_e_1[5] = { 6, 2, 3, 4, 252 };
unsigned char* pchg_e[2] =
{
  pchg_e_0,
  pchg_e_1
};
unsigned char pchg_b_0[4] = { 4, 0, 1, 255 };
unsigned char pchg_b_1[5] = { 14, 2, 3, 4, 252 };
unsigned char* pchg_b[2] =
{
  pchg_b_0,
  pchg_b_1
};
spr_array ka1e =
{
  1,
  { { -16, -12, 0, 400 } }
};
spr_array ka2e =
{
  1,
  { { -16, -4, 0, 401 } }
};
spr_array ka3e =
{
  1,
  { { -16, -16, 0, 402 } }
};
spr_array ka4e =
{
  1,
  { { -8, -16, 0, 403 } }
};
spr_array ka5e =
{
  1,
  { { -12, -16, 0, 404 } }
};
spr_array* e_ka_pat[5] =
{
  &ka1e,
  &ka2e,
  &ka3e,
  &ka4e,
  &ka5e
};
spr_array ka1b =
{
  1,
  { { -16, -12, 0, 405 } }
};
spr_array ka2b =
{
  1,
  { { -16, -4, 0, 406 } }
};
spr_array ka3b =
{
  1,
  { { -16, -16, 0, 407 } }
};
spr_array ka4b =
{
  1,
  { { -8, -16, 0, 408 } }
};
spr_array ka5b =
{
  1,
  { { -12, -16, 0, 409 } }
};
spr_array* b_ka_pat[5] =
{
  &ka1b,
  &ka2b,
  &ka3b,
  &ka4b,
  &ka5b
};
unsigned char e_kamem_pchg00[4] = { 29, 0, 1, 255 };
unsigned char e_kamem_pchg01[3] = { 59, 2, 252 };
unsigned char* e_kamem_pchg[2] =
{
  e_kamem_pchg00,
  e_kamem_pchg01
};
unsigned char b_kamem_pchg00[18] =
{
  5,
  0, 1,
  0, 1,
  0, 1,
  0, 1,
  0, 1,
  0, 1,
  0, 1,
  0, 1,
  252
};
unsigned char b_kamem_pchg01[3] = { 11, 2, 252 };
unsigned char* b_kamem_pchg[2] =
{
  b_kamem_pchg00,
  b_kamem_pchg01
};
spr_array kamem_pat00e =
{
  1,
  { { -16, -15, 0, 410 } }
};
spr_array kamem_pat00b =
{
  1,
  { { -16, -16, 0, 411 } }
};
spr_array kamem_pat01 =
{
  1,
  { { -16, -14, 0, 412 } }
};
spr_array kamem_pat02 =
{
  1,
  { { -17, -16, 0, 413 } }
};
spr_array* e_kamem_pat[3] =
{
  &kamem_pat00e,
  &kamem_pat01,
  &kamem_pat02
};
spr_array* b_kamem_pat[3] =
{
  &kamem_pat00b,
  &kamem_pat01,
  &kamem_pat02
};
unsigned char tama_pchg00[6] = { 2, 0, 1, 2, 3, 255 };
unsigned char* tama_pchg[1] = { tama_pchg00 };
spr_array tama_pat00 =
{
  1,
  { { -4, -4, 0, 414 } }
};
spr_array tama_pat01 =
{
  1,
 { { -4, -4, 0, 415 } }
};
spr_array tama_pat02 =
{
  1,
  { { -8, -8, 0, 416 } }
};
spr_array tama_pat03 =
{
  1,
  { { -8, -8, 0, 417 } }
};
spr_array* tama_pat[4] =
{
  &tama_pat00,
  &tama_pat01,
  &tama_pat02,
  &tama_pat03
};
unsigned char e_tagame_pchg00[3] = { 89, 6, 252 };
unsigned char e_tagame_pchg01[20] =
{
  7,
  0, 0,
  0, 1,
  0, 1,
  2, 3,
  5, 5,
  5, 5,
  4, 5,
  4, 5,
  4, 5,
  255
};
unsigned char* e_tagame_pchg[2] =
{
  e_tagame_pchg00,
  e_tagame_pchg01
};
unsigned char b_tagame_pchg00[3] = { 89, 6, 252 };
unsigned char b_tagame_pchg01[25] = {
  4,
  0, 0,
  0, 0,
  0, 0,
  0, 0,
  2, 2,
  3, 3,
  4, 4,
  4, 4,
  4, 4,
  4, 4,
  4, 4,
  4,
  255
};
unsigned char* b_tagame_pchg[2] =
{
  b_tagame_pchg00,
  b_tagame_pchg01
};
spr_array tagame_pat00 =
{
  2,
  {
    { -16, -10, 0, 418 },
    { -16, -22, 0, 419 }
  }
};
spr_array tagame_pat01 =
{
  2,
  {
    { -16, -10, 0, 420 },
    { -16, -22, 0, 421 }
  }
};
spr_array tagame_pat02 =
{
  1,
  { { -16, -16, 0, 422 } }
};
spr_array tagame_pat03e =
{
  1,
  { { -16, -16, 0, 423 } }
};
spr_array tagame_pat04e =
{
  2,
  {
    { -16, -22, 0, 424 },
    { -16, -2, 0, 425 }
  }
};
spr_array tagame_pat05e =
{
  2,
  {
    { -16, -22, 0, 426 },
    { -16, -2, 0, 427 }
  }
};
spr_array tagame_pat03b =
{
  1,
  { { -16, -16, 0, 428 } }
};
spr_array tagame_pat04b =
{
  2,
  {
    { -16, -22, 0, 429 },
    { -16, -2, 0, 430 }
  }
};
spr_array tagame_pat05b =
{
  2,
  {
    { -16, -22, 0, 431 },
    { -16, -2, 0, 432 }
  }
};
spr_array tagame_pat06 =
{
  1,
  { { -16, -16, 0, 433 } }
};
spr_array* e_tagame_pat[7] =
{
  &tagame_pat00,
  &tagame_pat01,
  &tagame_pat02,
  &tagame_pat03e,
  &tagame_pat04e,
  &tagame_pat05e,
  &tagame_pat06
};
spr_array* b_tagame_pat[7] =
{
  &tagame_pat00,
  &tagame_pat01,
  &tagame_pat02,
  &tagame_pat03b,
  &tagame_pat04b,
  &tagame_pat05b,
  &tagame_pat06
};











































































































void ene_ari(act_info* pActwk) { /* Line 516, Address: 0x1004c00 */
  void(*tbl[3])(act_info*) = /* Line 517, Address: 0x1004c0c */
  {
    &ari_init,
    &ari_fall,
    &ari_move
  };

  if (enemy_suicide(pActwk) != 0) return; /* Line 524, Address: 0x1004c30 */
  tbl[pActwk->r_no0 / 2](pActwk); /* Line 525, Address: 0x1004c44 */
  actionsub(pActwk); /* Line 526, Address: 0x1004c80 */
  frameout_s00(pActwk, *(short*)&pActwk->actfree[4]); /* Line 527, Address: 0x1004c8c */
} /* Line 528, Address: 0x1004ca0 */




void ari_init(act_info* pActwk) { /* Line 533, Address: 0x1004cb0 */
  short c;

  pActwk->actflg |= 4; /* Line 536, Address: 0x1004cc0 */
  pActwk->sprpri = 4; /* Line 537, Address: 0x1004cd0 */
  pActwk->patbase = ari_pat; /* Line 538, Address: 0x1004cdc */
  pActwk->sprhs = 24; /* Line 539, Address: 0x1004cec */
  pActwk->sprhsize = 24; /* Line 540, Address: 0x1004cf8 */
  pActwk->sprvsize = 19; /* Line 541, Address: 0x1004d04 */
  pActwk->colino = 41; /* Line 542, Address: 0x1004d10 */
  *(short*)&pActwk->actfree[4] = pActwk->xposi.w.h; /* Line 543, Address: 0x1004d1c */
  pa_set(pActwk, 2); /* Line 544, Address: 0x1004d2c */

  if (pActwk->userflag.b.h) /* Line 546, Address: 0x1004d3c */
  {
    *(int*)&pActwk->actfree[0] = -1; /* Line 548, Address: 0x1004d54 */
    pActwk->mstno.b.h = 0; /* Line 549, Address: 0x1004d64 */
  } /* Line 550, Address: 0x1004d6c */
  else
  {
    *(int*)&pActwk->actfree[0] = -32768; /* Line 553, Address: 0x1004d74 */
    pActwk->mstno.b.h = 1; /* Line 554, Address: 0x1004d84 */
  }


  ++pActwk->yposi.l; /* Line 558, Address: 0x1004d90 */
  c = emycol_d(pActwk); /* Line 559, Address: 0x1004da4 */
  if (c < 0) /* Line 560, Address: 0x1004db8 */
  {
    pActwk->r_no0 += 2; /* Line 562, Address: 0x1004dc8 */
  }
} /* Line 564, Address: 0x1004dd8 */




void ari_fall(act_info* pActwk) { /* Line 569, Address: 0x1004df0 */
  short c;

  ++pActwk->yposi.l; /* Line 572, Address: 0x1004e00 */
  c = emycol_d(pActwk); /* Line 573, Address: 0x1004e14 */
  if (c < 0) /* Line 574, Address: 0x1004e28 */
  {
    pActwk->r_no0 += 2; /* Line 576, Address: 0x1004e38 */
  }
} /* Line 578, Address: 0x1004e48 */




void ari_move(act_info* pActwk) { /* Line 583, Address: 0x1004e60 */
  short xpos;
  short xpos_m;
  short c;
  int spd_x;

  do
  {
    spd_x = *(int*)&pActwk->actfree[0]; /* Line 591, Address: 0x1004e7c */
    pActwk->xposi.l += spd_x; /* Line 592, Address: 0x1004e88 */
    xpos = pActwk->xposi.w.h; /* Line 593, Address: 0x1004e9c */
    xpos_m = *(short*)&pActwk->actfree[4]; /* Line 594, Address: 0x1004eac */
    xpos -= xpos_m; /* Line 595, Address: 0x1004ebc */
    if (xpos < 0) xpos = -xpos; /* Line 596, Address: 0x1004ee0 */
    if (xpos < 128) /* Line 597, Address: 0x1004f0c */
    {
      c = emycol_d(pActwk); /* Line 599, Address: 0x1004f20 */
      if (c >= -7) /* Line 600, Address: 0x1004f34 */
      {
        if (c < 8) /* Line 602, Address: 0x1004f48 */
        {
          pActwk->yposi.w.h += c; /* Line 604, Address: 0x1004f5c */
          patchg(pActwk, ari_pchg); /* Line 605, Address: 0x1004f88 */
          break; /* Line 606, Address: 0x1004f9c */
        }
      }
    }
    spd_x = *(int*)&pActwk->actfree[0]; /* Line 610, Address: 0x1004fa4 */
    *(int*)&pActwk->actfree[0] = -spd_x; /* Line 611, Address: 0x1004fb0 */
    pActwk->actflg = pActwk->actflg ^ 1; /* Line 612, Address: 0x1004fc0 */
    pActwk->cddat = pActwk->cddat ^ 1; /* Line 613, Address: 0x1004fdc */
  } while (1); /* Line 614, Address: 0x1004ff8 */
} /* Line 615, Address: 0x1005000 */























void ene_chou(act_info* pActwk) { /* Line 639, Address: 0x1005020 */
  if (enemy_suicide(pActwk) != 0) return; /* Line 640, Address: 0x100502c */
  if (pActwk->r_no0 == 0) chou_init(pActwk); /* Line 641, Address: 0x1005040 */
  else chou_move(pActwk); /* Line 642, Address: 0x1005068 */
} /* Line 643, Address: 0x1005074 */




void chou_init(act_info* pActwk) { /* Line 648, Address: 0x1005090 */
  pActwk->r_no0 += 2; /* Line 649, Address: 0x100509c */
  pActwk->actflg |= 4; /* Line 650, Address: 0x10050ac */
  pActwk->sprpri = 3; /* Line 651, Address: 0x10050bc */
  pActwk->colino = 42; /* Line 652, Address: 0x10050c8 */
  pActwk->sprhs = 16; /* Line 653, Address: 0x10050d4 */
  pActwk->sprhsize = 16; /* Line 654, Address: 0x10050e0 */
  pActwk->sprvsize = 16; /* Line 655, Address: 0x10050ec */
  *(short*)&pActwk->actfree[0] = pActwk->xposi.w.h; /* Line 656, Address: 0x10050f8 */
  *(short*)&pActwk->actfree[4] = pActwk->yposi.w.h; /* Line 657, Address: 0x1005108 */
  *(short*)&pActwk->actfree[2] = -32768; /* Line 658, Address: 0x1005118 */
  pa_set(pActwk, 1); /* Line 659, Address: 0x1005124 */
  if (pActwk->userflag.b.h == 0) /* Line 660, Address: 0x1005134 */
  {
    *(int*)&pActwk->actfree[6] = -32768; /* Line 662, Address: 0x100514c */
    *(short*)&pActwk->actfree[12] = -512; /* Line 663, Address: 0x1005158 */
    *(short*)&pActwk->actfree[14] = 3; /* Line 664, Address: 0x1005164 */
    pActwk->mstno.b.h = 0; /* Line 665, Address: 0x1005170 */
    pActwk->patbase = e_chou_pat; /* Line 666, Address: 0x1005178 */
  } /* Line 667, Address: 0x1005188 */
  else
  {
    *(int*)&pActwk->actfree[6] = -16384; /* Line 670, Address: 0x1005190 */
    *(short*)&pActwk->actfree[12] = -256; /* Line 671, Address: 0x100519c */
    *(short*)&pActwk->actfree[14] = 4; /* Line 672, Address: 0x10051a8 */
    pActwk->mstno.b.h = 1; /* Line 673, Address: 0x10051b4 */
    pActwk->patbase = b_chou_pat; /* Line 674, Address: 0x10051c0 */
  }
} /* Line 676, Address: 0x10051d0 */




void chou_move(act_info* pActwk) { /* Line 681, Address: 0x10051e0 */
  short xpos;
  short shift;
  short sSin, sCos;
  int_union lSin;

  pActwk->xposi.l += *(int*)&pActwk->actfree[6]; /* Line 687, Address: 0x10051f4 */
  xpos = pActwk->xposi.w.h; /* Line 688, Address: 0x100520c */
  xpos -= *(short*)&pActwk->actfree[0]; /* Line 689, Address: 0x100521c */
  if (xpos < 0) xpos = -xpos; /* Line 690, Address: 0x1005230 */
  if (xpos >= 128) /* Line 691, Address: 0x100524c */
  {
    pActwk->xposi.l += *(int*)&pActwk->actfree[6]; /* Line 694, Address: 0x1005270 */
    *(short*)&pActwk->actfree[10] = 0; /* Line 697, Address: 0x10052c0 */
    ((int*)pActwk)[13] *= -1; /* Line 693, Address: 0x1005260 */
    pActwk->actflg = pActwk->actflg ^ 1; /* Line 695, Address: 0x1005288 */
    pActwk->cddat = pActwk->cddat ^ 1; /* Line 696, Address: 0x10052a4 */
  }
  *(short*)&pActwk->actfree[10] += *(short*)&pActwk->actfree[12]; /* Line 699, Address: 0x10052c8 */
  sinset(pActwk->actfree[11], &sSin, &sCos); /* Line 700, Address: 0x10052e0 */
  lSin.w.h = sSin; /* Line 701, Address: 0x10052f8 */
  lSin.w.l = 0; /* Line 702, Address: 0x1005300 */
  shift = *(short*)&pActwk->actfree[14]; /* Line 703, Address: 0x1005304 */
  while (shift-- != 0) lSin.l /= 2; /* Line 704, Address: 0x1005314 */
  lSin.l += *(int*)&pActwk->actfree[2]; /* Line 705, Address: 0x1005354 */
  pActwk->yposi.l = lSin.l; /* Line 706, Address: 0x1005368 */

  patchg(pActwk, chou_pchg); /* Line 708, Address: 0x1005374 */
  actionsub(pActwk); /* Line 709, Address: 0x1005388 */
  frameout_s00(pActwk, *(short*)&pActwk->actfree[0]); /* Line 710, Address: 0x1005394 */
} /* Line 711, Address: 0x10053a8 */
































void ene_ka(act_info* pActwk) { /* Line 744, Address: 0x10053c0 */
  void(*tbl[5])(act_info*) = /* Line 745, Address: 0x10053cc */
  {
    &ka_init,
    &ka_move,
    &ka_turn,
    &ka_down,
    &ka_stop
  };

  if (enemy_suicide(pActwk) != 0) return; /* Line 754, Address: 0x10053f8 */
  tbl[pActwk->r_no0 / 2](pActwk); /* Line 755, Address: 0x100540c */
  actionsub(pActwk); /* Line 756, Address: 0x1005448 */
  frameout_s00(pActwk, *(short*)&pActwk->actfree[0]); /* Line 757, Address: 0x1005454 */
} /* Line 758, Address: 0x1005468 */




void ka_init(act_info* pActwk) { /* Line 763, Address: 0x1005480 */
  pActwk->r_no0 += 2; /* Line 764, Address: 0x100548c */
  pActwk->actflg |= 4; /* Line 765, Address: 0x100549c */
  pActwk->sprpri = 3; /* Line 766, Address: 0x10054ac */
  pActwk->sprhs = 16; /* Line 767, Address: 0x10054b8 */
  pActwk->sprhsize = 16; /* Line 768, Address: 0x10054c4 */
  pActwk->sprvsize = 16; /* Line 769, Address: 0x10054d0 */
  pActwk->colino = 43; /* Line 770, Address: 0x10054dc */
  *(short*)&pActwk->actfree[0] = pActwk->xposi.w.h; /* Line 771, Address: 0x10054e8 */
  pa_set(pActwk, 0); /* Line 772, Address: 0x10054f8 */

  if (pActwk->userflag.b.h == 0) /* Line 774, Address: 0x1005508 */
  {
    pActwk->patbase = e_ka_pat; /* Line 776, Address: 0x1005520 */
    *(unsigned char***)&pActwk->actfree[6] = pchg_e; /* Line 777, Address: 0x1005530 */
    *(int*)&pActwk->actfree[2] = -1; /* Line 778, Address: 0x1005540 */
  } /* Line 779, Address: 0x100554c */
  else
  {
    pActwk->patbase = b_ka_pat; /* Line 782, Address: 0x1005554 */
    *(unsigned char***)&pActwk->actfree[6] = pchg_b; /* Line 783, Address: 0x1005564 */
    *(int*)&pActwk->actfree[2] = -32768; /* Line 784, Address: 0x1005574 */
  }
  ka_move(pActwk); /* Line 786, Address: 0x1005580 */
} /* Line 787, Address: 0x100558c */




void ka_move(act_info* pActwk) { /* Line 792, Address: 0x10055a0 */
  act_info* pPlayerwk;
  short d0;

  if (editmode.w == 0) /* Line 796, Address: 0x10055b4 */
  {
    pPlayerwk = &actwk[0]; /* Line 798, Address: 0x10055cc */
    d0 = pPlayerwk->yposi.w.h; /* Line 799, Address: 0x10055d4 */
    d0 -= pActwk->yposi.w.h; /* Line 800, Address: 0x10055e0 */
    d0 += 48; /* Line 801, Address: 0x10055f4 */
    if (d0 < 112) /* Line 802, Address: 0x1005600 */
    {
      d0 = pPlayerwk->xposi.w.h; /* Line 804, Address: 0x1005614 */
      d0 -= pActwk->xposi.w.h; /* Line 805, Address: 0x1005620 */
      d0 += 48; /* Line 806, Address: 0x1005634 */
      if (d0 < 96) /* Line 807, Address: 0x1005640 */
      {
        pActwk->r_no0 += 2; /* Line 809, Address: 0x1005654 */
        pActwk->mstno.b.h = 1; /* Line 810, Address: 0x1005664 */
        return; /* Line 811, Address: 0x1005670 */
      }
    }
  }
  do
  {
    pActwk->xposi.l += *(int*)&pActwk->actfree[2]; /* Line 817, Address: 0x1005678 */
    d0 = pActwk->xposi.w.h; /* Line 818, Address: 0x1005690 */
    d0 -= *(short*)&pActwk->actfree[0]; /* Line 819, Address: 0x10056a0 */
    if (d0 < 0) d0 = -d0; /* Line 820, Address: 0x10056b4 */
    if (d0 < 128) break; /* Line 821, Address: 0x10056d0 */
    ((int*)pActwk)[12] *= -1; /* Line 822, Address: 0x10056e4 */
    pActwk->actflg = pActwk->actflg ^ 1; /* Line 823, Address: 0x10056f4 */
    pActwk->cddat = pActwk->cddat ^ 1; /* Line 824, Address: 0x1005710 */
  } while (1); /* Line 825, Address: 0x100572c */
  patchg(pActwk, *(unsigned char***)&pActwk->actfree[6]); /* Line 826, Address: 0x1005734 */
} /* Line 827, Address: 0x1005748 */




void ka_turn(act_info* pActwk) { /* Line 832, Address: 0x1005760 */
  patchg(pActwk, *(unsigned char***)&pActwk->actfree[6]); /* Line 833, Address: 0x100576c */

} /* Line 835, Address: 0x1005780 */




void ka_down(act_info* pActwk) { /* Line 840, Address: 0x1005790 */
  short c;

  pActwk->yposi.w.h += 6; /* Line 843, Address: 0x10057a0 */
  c = emycol_d(pActwk); /* Line 844, Address: 0x10057b0 */
  if (c < -7) /* Line 845, Address: 0x10057c4 */
  {
    c += 8; /* Line 847, Address: 0x10057d8 */
    pActwk->yposi.w.h += c; /* Line 848, Address: 0x10057e4 */
    pActwk->r_no0 += 2; /* Line 849, Address: 0x10057f4 */
    if ((char)pActwk->actflg < 0) soundset(167); /* Line 850, Address: 0x1005804 */
  }
} /* Line 852, Address: 0x1005830 */




void ka_stop(act_info* pActwk) { /* Line 857, Address: 0x1005850 */
  if ((char)pActwk->actflg < 0) return; /* Line 858, Address: 0x100585c */
  frameout_s0(pActwk); /* Line 859, Address: 0x100587c */
} /* Line 860, Address: 0x1005888 */







































void ene_kamemusi(act_info* pActwk) { /* Line 900, Address: 0x10058a0 */
  void(*tbl[6])(act_info*) = /* Line 901, Address: 0x10058ac */
  {
    &kamemusi_init,
    &kamemusi_fall,
    &kamemusi_move,
    &kamemusi_stop,
    &kamemusi_stop1,
    &kamemusi_tama
  };

  if (pActwk->userflag.b.h == 1) /* Line 911, Address: 0x10058e0 */
  {
    tama(pActwk); /* Line 913, Address: 0x10058fc */
    return; /* Line 914, Address: 0x1005908 */
  }

  if (enemy_suicide(pActwk) != 0) return; /* Line 917, Address: 0x1005910 */
  tbl[pActwk->r_no0 / 2](pActwk); /* Line 918, Address: 0x1005924 */
  actionsub(pActwk); /* Line 919, Address: 0x1005960 */
  frameout_s00(pActwk, *(short*)&pActwk->actfree[0]); /* Line 920, Address: 0x100596c */

} /* Line 922, Address: 0x1005980 */




void kamemusi_init(act_info* pActwk) { /* Line 927, Address: 0x1005990 */
  pActwk->r_no0 += 2; /* Line 928, Address: 0x100599c */
  pActwk->actflg |= 4; /* Line 929, Address: 0x10059ac */
  pActwk->sprpri = 4; /* Line 930, Address: 0x10059bc */
  pActwk->colino = 44; /* Line 931, Address: 0x10059c8 */
  pActwk->sprhs = 16; /* Line 932, Address: 0x10059d4 */
  pActwk->sprhsize = 16; /* Line 933, Address: 0x10059e0 */
  pActwk->sprvsize = 15; /* Line 934, Address: 0x10059ec */
  *(short*)&pActwk->actfree[0] = pActwk->xposi.w.h; /* Line 935, Address: 0x10059f8 */
  pa_set(pActwk, 4); /* Line 936, Address: 0x1005a08 */

  if ((pActwk->userflag).b.h == 0) /* Line 938, Address: 0x1005a18 */
  {
    pActwk->patbase = e_kamem_pat; /* Line 940, Address: 0x1005a30 */
    *(unsigned char***)&pActwk->actfree[6] = e_kamem_pchg; /* Line 941, Address: 0x1005a40 */
    ((int*)pActwk)[12] = -40960; /* Line 942, Address: 0x1005a50 */
  } /* Line 943, Address: 0x1005a60 */
  else
  {
    pActwk->patbase = b_kamem_pat; /* Line 946, Address: 0x1005a68 */
    *(unsigned char***)&pActwk->actfree[6] = b_kamem_pchg; /* Line 947, Address: 0x1005a78 */
    *(int*)&pActwk->actfree[2] = -20480; /* Line 948, Address: 0x1005a88 */
  }
  kamemusi_fall(pActwk); /* Line 950, Address: 0x1005a94 */
} /* Line 951, Address: 0x1005aa0 */




void kamemusi_fall(act_info* pActwk) { /* Line 956, Address: 0x1005ab0 */
  short d1;

  ++pActwk->yposi.l; /* Line 959, Address: 0x1005ac0 */
  d1 = emycol_d(pActwk); /* Line 960, Address: 0x1005ad4 */
  if (d1 < 0) pActwk->r_no0 += 2; /* Line 961, Address: 0x1005ae8 */
} /* Line 962, Address: 0x1005b08 */




void kamemusi_move(act_info* pActwk) { /* Line 967, Address: 0x1005b20 */
  short d0, d1;

  do
  {
    if (editmode.w == 0) /* Line 972, Address: 0x1005b34 */
    {
      if (pActwk->userflag.b.h == 0) /* Line 974, Address: 0x1005b4c */
      {
        if (((short*)pActwk)[28]) /* Line 976, Address: 0x1005b64 */
        {
          --*(short*)&pActwk->actfree[10]; /* Line 978, Address: 0x1005b74 */
        } /* Line 979, Address: 0x1005b84 */
        else
        {
          if (area(pActwk) != 0) /* Line 982, Address: 0x1005b8c */
          {
            pActwk->r_no0 += 2; /* Line 984, Address: 0x1005ba0 */
            break; /* Line 985, Address: 0x1005bb0 */
          }
        }
      }
    }
    pActwk->xposi.l += *(int*)&pActwk->actfree[2]; /* Line 990, Address: 0x1005bb8 */
    d0 = pActwk->xposi.w.h; /* Line 991, Address: 0x1005bd0 */
    d0 -= *(short*)&pActwk->actfree[0]; /* Line 992, Address: 0x1005be0 */
    if (d0 < 0) d0 = -d0; /* Line 993, Address: 0x1005bf4 */
    if (d0 < 128) /* Line 994, Address: 0x1005c10 */
    {
      d1 = emycol_d(pActwk); /* Line 996, Address: 0x1005c24 */
      if (d1 >= -7 && d1 < 8) /* Line 997, Address: 0x1005c38 */
      {
        pActwk->yposi.w.h += d1; /* Line 999, Address: 0x1005c60 */
        patchg(pActwk, *(unsigned char***)&pActwk->actfree[6]); /* Line 1000, Address: 0x1005c70 */
        break; /* Line 1001, Address: 0x1005c84 */
      }
    }
    ((int*)pActwk)[12] *= -1; /* Line 1004, Address: 0x1005c8c */
    pActwk->actflg ^= 1; /* Line 1005, Address: 0x1005c9c */
    pActwk->cddat ^= 1; /* Line 1006, Address: 0x1005cac */
  } while (1); /* Line 1007, Address: 0x1005cbc */
} /* Line 1008, Address: 0x1005cc4 */

short area(act_info* pActwk) { /* Line 1010, Address: 0x1005ce0 */
  act_info* pPlayerwk;
  short d0, d1;
  short carry_flag;

  pPlayerwk = &actwk[0]; /* Line 1015, Address: 0x1005cf8 */
  d0 = pPlayerwk->yposi.w.h; /* Line 1016, Address: 0x1005d00 */
  d0 -= pActwk->yposi.w.h; /* Line 1017, Address: 0x1005d0c */
  d0 += 80; /* Line 1018, Address: 0x1005d20 */
  if (d0 < 160) /* Line 1019, Address: 0x1005d2c */
  {
    carry_flag = 1; /* Line 1021, Address: 0x1005d40 */
    d0 = pPlayerwk->xposi.w.h; /* Line 1022, Address: 0x1005d4c */
    d0 -= pActwk->xposi.w.h; /* Line 1023, Address: 0x1005d58 */
    d1 = d0; /* Line 1024, Address: 0x1005d6c */
    d1 += 80; /* Line 1025, Address: 0x1005d74 */
    if (d1 < 160) carry_flag = 1; /* Line 1026, Address: 0x1005d80 */
    else carry_flag = 0; /* Line 1027, Address: 0x1005da8 */
  } /* Line 1028, Address: 0x1005dac */
  else
  {
    carry_flag = 0; /* Line 1031, Address: 0x1005db4 */
  }
  return carry_flag; /* Line 1033, Address: 0x1005db8 */
} /* Line 1034, Address: 0x1005dbc */




void kamemusi_stop(act_info* pActwk) { /* Line 1039, Address: 0x1005de0 */
  pActwk->r_no0 += 2; /* Line 1040, Address: 0x1005dec */
  pActwk->mstno.b.h = 1; /* Line 1041, Address: 0x1005dfc */

  kamemusi_stop1(pActwk); /* Line 1043, Address: 0x1005e08 */
} /* Line 1044, Address: 0x1005e14 */




void kamemusi_stop1(act_info* pActwk) { /* Line 1049, Address: 0x1005e30 */
  patchg(pActwk, *(unsigned char***)&pActwk->actfree[6]); /* Line 1050, Address: 0x1005e3c */

} /* Line 1052, Address: 0x1005e50 */




void kamemusi_tama(act_info* pActwk) { /* Line 1057, Address: 0x1005e60 */
  act_info* pTama1wk;
  act_info* pTama2wk;

  pActwk->r_no0 = 4; /* Line 1061, Address: 0x1005e6c */
  pActwk->mstno.b.h = 0; /* Line 1062, Address: 0x1005e78 */
  *(short*)&pActwk->actfree[10] = 120; /* Line 1063, Address: 0x1005e80 */

  if (pActwk->userflag.b.h == 0) /* Line 1065, Address: 0x1005e8c */
  {
    if (actwkchk(&pTama1wk) == 0) /* Line 1067, Address: 0x1005ea4 */
    {
      if (pActwk->actflg & 128) /* Line 1069, Address: 0x1005eb8 */
      {
        soundset(160); /* Line 1071, Address: 0x1005ed0 */
      }
      kamemusi_tama_init(pActwk, pTama1wk); /* Line 1073, Address: 0x1005edc */
      pTama1wk->actfree[21] = 0; /* Line 1074, Address: 0x1005eec */
      if (actwkchk(&pTama2wk) == 0) /* Line 1075, Address: 0x1005ef4 */
      {
        kamemusi_tama_init(pActwk, pTama2wk); /* Line 1077, Address: 0x1005f08 */
        pTama2wk->actfree[21] = 255; /* Line 1078, Address: 0x1005f18 */
      }
    }
  }
} /* Line 1082, Address: 0x1005f24 */

void kamemusi_tama_init(act_info* pActwk, act_info* pTamawk) { /* Line 1084, Address: 0x1005f40 */
  pTamawk->actno = pActwk->actno; /* Line 1085, Address: 0x1005f4c */
  pTamawk->userflag.b.h = 1; /* Line 1086, Address: 0x1005f5c */
  pTamawk->sproffset = pActwk->sproffset; /* Line 1087, Address: 0x1005f68 */
  pTamawk->sprpri = pActwk->sprpri + 1; /* Line 1088, Address: 0x1005f78 */
  pTamawk->xposi.w.h = pActwk->xposi.w.h; /* Line 1089, Address: 0x1005f94 */
  pTamawk->yposi.w.h = pActwk->yposi.w.h + -10; /* Line 1090, Address: 0x1005fa4 */

  pTamawk->actflg |= 128; /* Line 1092, Address: 0x1005fc8 */
} /* Line 1093, Address: 0x1005fd8 */
































void tama(act_info* pActwk) { /* Line 1126, Address: 0x1005ff0 */
  void(*tbl[2])(act_info*) = /* Line 1127, Address: 0x1005ffc */
  {
    &tama_init,
    &tama_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 1133, Address: 0x1006018 */
  actionsub(pActwk); /* Line 1134, Address: 0x1006054 */
} /* Line 1135, Address: 0x1006060 */




void tama_init(act_info* pActwk) { /* Line 1140, Address: 0x1006070 */
  pActwk->r_no0 += 2; /* Line 1141, Address: 0x1006078 */
  pActwk->actflg |= 4; /* Line 1142, Address: 0x1006088 */
  pActwk->actflg |= 128; /* Line 1143, Address: 0x1006098 */
  pActwk->colino = 173; /* Line 1144, Address: 0x10060a8 */
  pActwk->sprhs = 8; /* Line 1145, Address: 0x10060b4 */
  pActwk->sprhsize = 8; /* Line 1146, Address: 0x10060c0 */
  pActwk->sprvsize = 8; /* Line 1147, Address: 0x10060cc */
  pActwk->patbase = tama_pat; /* Line 1148, Address: 0x10060d8 */
  *(int*)&pActwk->actfree[8] = 0; /* Line 1149, Address: 0x10060e8 */
  *(int*)&pActwk->actfree[12] = 8192; /* Line 1150, Address: 0x10060f4 */

  if (pActwk->actfree[21] == 0) /* Line 1152, Address: 0x1006104 */
  {
    *(int*)&pActwk->actfree[0] = 2; /* Line 1154, Address: 0x1006118 */
    *(int*)&pActwk->actfree[4] = -4; /* Line 1155, Address: 0x1006128 */
  } /* Line 1156, Address: 0x1006138 */
  else
  {
    *(int*)&pActwk->actfree[0] = -2; /* Line 1159, Address: 0x1006140 */
    *(int*)&pActwk->actfree[4] = -4; /* Line 1160, Address: 0x1006150 */
  }
} /* Line 1162, Address: 0x1006160 */




void tama_move(act_info* pActwk) { /* Line 1167, Address: 0x1006170 */
  short d1;

  if ((pActwk->actflg & 128) == 0) /* Line 1170, Address: 0x1006180 */
  {
    frameout(pActwk); /* Line 1172, Address: 0x1006198 */
    return; /* Line 1173, Address: 0x10061a4 */
  }
  d1 = emycol_d(pActwk); /* Line 1175, Address: 0x10061ac */
  if (d1 < 0) /* Line 1176, Address: 0x10061c0 */
  {
    frameout(pActwk); /* Line 1178, Address: 0x10061d0 */
    return; /* Line 1179, Address: 0x10061dc */
  }

  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 1182, Address: 0x10061e4 */
  pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 1183, Address: 0x1006200 */
  *(int*)&pActwk->actfree[0] += *(int*)&pActwk->actfree[8]; /* Line 1184, Address: 0x100621c */
  *(int*)&pActwk->actfree[4] += *(int*)&pActwk->actfree[12]; /* Line 1185, Address: 0x1006240 */

  patchg(pActwk, tama_pchg); /* Line 1187, Address: 0x1006264 */
} /* Line 1188, Address: 0x1006278 */
































void ene_tagame_a(act_info* pActwk) { /* Line 1221, Address: 0x1006290 */
  void(*tbl[5])(act_info*) = /* Line 1222, Address: 0x100629c */
  {
    &tagame_init,
    &tagame_wait,
    &tagame_wait1,
    &tagame_jump,
    &tagame_jump1
  };

  if (enemy_suicide(pActwk) != 0) return; /* Line 1231, Address: 0x10062c8 */
  tbl[pActwk->r_no0 / 2](pActwk); /* Line 1232, Address: 0x10062dc */
  actionsub(pActwk); /* Line 1233, Address: 0x1006318 */
  frameout_s00(pActwk, *(short*)&pActwk->actfree[0]); /* Line 1234, Address: 0x1006324 */
} /* Line 1235, Address: 0x1006338 */




void tagame_init(act_info* pActwk) { /* Line 1240, Address: 0x1006350 */
  pActwk->r_no0 += 2; /* Line 1241, Address: 0x100635c */
  pActwk->actflg |= 4; /* Line 1242, Address: 0x100636c */
  pActwk->sprpri = 3; /* Line 1243, Address: 0x100637c */
  pActwk->colino = 173; /* Line 1244, Address: 0x1006388 */
  pActwk->sprhs = 16; /* Line 1245, Address: 0x1006394 */
  pActwk->sprhsize = 16; /* Line 1246, Address: 0x10063a0 */
  pActwk->sprvsize = 22; /* Line 1247, Address: 0x10063ac */
  *(short*)&pActwk->actfree[0] = pActwk->xposi.w.h; /* Line 1248, Address: 0x10063b8 */
  *(short*)&pActwk->actfree[2] = pActwk->yposi.w.h; /* Line 1249, Address: 0x10063c8 */
  pa_set(pActwk, 3); /* Line 1250, Address: 0x10063d8 */

  if (pActwk->userflag.b.h == 0) /* Line 1252, Address: 0x10063e8 */
  {
    pActwk->patbase = e_tagame_pat; /* Line 1254, Address: 0x1006400 */
    *(unsigned char***)&pActwk->actfree[18] = e_tagame_pchg; /* Line 1255, Address: 0x1006410 */
    *(int*)&pActwk->actfree[14] = 4096; /* Line 1257, Address: 0x1006430 */
    ((int*)pActwk)[13] = -245760; /* Line 1256, Address: 0x1006420 */
  } /* Line 1258, Address: 0x100643c */
  else
  {
    pActwk->patbase = b_tagame_pat; /* Line 1261, Address: 0x1006444 */
    *(unsigned char***)&pActwk->actfree[18] = b_tagame_pchg; /* Line 1262, Address: 0x1006454 */
    *(int*)&pActwk->actfree[14] = 4096; /* Line 1264, Address: 0x1006470 */
    ((int*)pActwk)[13] = -196608; /* Line 1263, Address: 0x1006464 */
  }
  tagame_wait(pActwk); /* Line 1266, Address: 0x100647c */
} /* Line 1267, Address: 0x1006488 */




void tagame_wait(act_info* pActwk) { /* Line 1272, Address: 0x10064a0 */
  pActwk->r_no0 += 2; /* Line 1273, Address: 0x10064a8 */
  pActwk->mstno.w = 255; /* Line 1274, Address: 0x10064b8 */
  pActwk->colino = 0; /* Line 1275, Address: 0x10064c4 */
  pActwk->yposi.w.h = *(short*)&pActwk->actfree[2]; /* Line 1276, Address: 0x10064cc */
} /* Line 1277, Address: 0x10064dc */




void tagame_wait1(act_info* pActwk) { /* Line 1282, Address: 0x10064f0 */
  patchg(pActwk, *(unsigned char***)&pActwk->actfree[18]); /* Line 1283, Address: 0x10064fc */

} /* Line 1285, Address: 0x1006510 */




void tagame_jump(act_info* pActwk) { /* Line 1290, Address: 0x1006520 */
  pActwk->r_no0 += 2; /* Line 1291, Address: 0x100652c */
  pActwk->mstno.w = 511; /* Line 1292, Address: 0x100653c */
  pActwk->colino = 46; /* Line 1293, Address: 0x1006548 */
  pActwk->yposi.w.h = *(short*)&pActwk->actfree[2]; /* Line 1294, Address: 0x1006554 */
  *(int*)&pActwk->actfree[10] = *(int*)&pActwk->actfree[6]; /* Line 1295, Address: 0x1006564 */
  if ((char)pActwk->actflg < 0) /* Line 1296, Address: 0x1006574 */
  {
    soundset(162); /* Line 1298, Address: 0x1006594 */
  }
  tagame_jump1(pActwk); /* Line 1300, Address: 0x10065a0 */
} /* Line 1301, Address: 0x10065ac */




void tagame_jump1(act_info* pActwk) { /* Line 1306, Address: 0x10065c0 */
  pActwk->yposi.l += *(int*)&pActwk->actfree[10]; /* Line 1307, Address: 0x10065cc */
  *(int*)&pActwk->actfree[10] += *(int*)&pActwk->actfree[14]; /* Line 1308, Address: 0x10065e4 */

  if (pActwk->yposi.w.h > ((short*)pActwk)[24]) /* Line 1310, Address: 0x10065fc */
  {
    pActwk->r_no0 = 2; /* Line 1312, Address: 0x1006628 */
    if ((char)pActwk->actflg < 0) /* Line 1313, Address: 0x1006634 */
    {
      soundset(162); /* Line 1315, Address: 0x1006654 */
    }
  }
  patchg(pActwk, *(unsigned char***)&pActwk->actfree[18]); /* Line 1318, Address: 0x1006660 */
} /* Line 1319, Address: 0x1006674 */




void ene_tama(act_info* pActwk) { /* Line 1324, Address: 0x1006690 */
} /* Line 1325, Address: 0x1006694 */
