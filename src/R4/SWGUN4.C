#include "..\EQU.H"
#include "SWGUN4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"
#include "..\RING.H"
#include "..\SCORE.H"
#include "PLAYSUB4.H"

static void swgun4_init(sprite_status* pActwk);
static void swgun4_move(sprite_status* pActwk);
static void swgun4_move1(sprite_status* pActwk);
static void switch_move(sprite_status* pActwk);
static void hariset(sprite_status* pActwk);
static void awaset(sprite_status* pActwk);
static void ring4set(sprite_status* pActwk);
static void bp1000(sprite_status* pActwk);
static void ring4_init(sprite_status* pActwk);
static void ring4_move(sprite_status* pActwk);
static void ring4_get(sprite_status* pActwk);
static void ring4_die(sprite_status* pActwk);
static void ring4_erase(sprite_status* pActwk);
static void tensu4_init(sprite_status* pActwk);
static void tensu4_move(sprite_status* pActwk);

static sprite_pattern pat0 =
{
  1,
  { { -16, -8, 0, 481 } }
};
static sprite_pattern pat1 =
{
  1,
  { { -16, 0, 0, 482 } }
};
static sprite_pattern pat2 =
{
  1,
  { { -16, 0, 0, 483 } }
};
sprite_pattern* swgun4pat[3] =
{
  &pat0,
  &pat1,
  &pat2
};





































void swgun4(sprite_status* pActwk) { /* Line 86, Address: 0x102a8c0 */
  void(*tbl[3])(sprite_status*) = /* Line 87, Address: 0x102a8cc */
  {
    &swgun4_init,
    &swgun4_move,
    &swgun4_move1
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 94, Address: 0x102a8f0 */
  actionsub(pActwk); /* Line 95, Address: 0x102a92c */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 96, Address: 0x102a938 */
} /* Line 97, Address: 0x102a94c */




static void swgun4_init(sprite_status* pActwk) { /* Line 102, Address: 0x102a960 */
  sprite_status* pNewActwk;
  short* a2;
  short i;
  unsigned char d1;
  short tbl[12] = /* Line 107, Address: 0x102a978 */
  {
       0,    0,
     -64,   64,
    -128,  128,
      64,  -64,
      96, -128,
     128, -128
  };

  pActwk->r_no0 += 2; /* Line 117, Address: 0x102a9ac */
  pActwk->actflg |= 4; /* Line 118, Address: 0x102a9bc */
  pActwk->sproffset = 1290; /* Line 119, Address: 0x102a9cc */
  pActwk->sprpri = 3; /* Line 120, Address: 0x102a9d8 */
  pActwk->patbase = swgun4pat; /* Line 121, Address: 0x102a9e4 */
  pActwk->sprhsize = 14; /* Line 122, Address: 0x102a9f4 */
  pActwk->sprvsize = 8; /* Line 123, Address: 0x102aa00 */

  if (pActwk->actfree[10] == 0) /* Line 125, Address: 0x102aa0c */
  {
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 127, Address: 0x102aa20 */
    ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 128, Address: 0x102aa30 */
    ((short*)pActwk)[31] = (unsigned short)(pActwk - actwk); /* Line 129, Address: 0x102aa40 */

    d1 = 1; /* Line 131, Address: 0x102aa7c */
    for (i = 0; i <= 4; ++i) /* Line 132, Address: 0x102aa84 */
    {
      if (actwkchk(&pNewActwk) == 0) /* Line 134, Address: 0x102aa90 */
      {
        pNewActwk->actno = 63; /* Line 136, Address: 0x102aaa4 */

        ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 138, Address: 0x102aab0 */

        ((short*)pNewActwk)[31] = (unsigned short)(pActwk - actwk); /* Line 140, Address: 0x102aac0 */
        pNewActwk->actfree[10] = d1; /* Line 141, Address: 0x102aafc */
        a2 = &tbl[d1 * 2]; /* Line 142, Address: 0x102ab04 */
        pNewActwk->xposi.w.h = pActwk->xposi.w.h + *a2++; /* Line 143, Address: 0x102ab18 */
        pNewActwk->yposi.w.h = pActwk->yposi.w.h + *a2++; /* Line 144, Address: 0x102ab50 */
        ((short*)pNewActwk)[27] = pNewActwk->yposi.w.h; /* Line 145, Address: 0x102ab88 */
      }
      ++d1; /* Line 147, Address: 0x102ab98 */
    } /* Line 148, Address: 0x102aba0 */
  }
} /* Line 150, Address: 0x102abc0 */




static void swgun4_move(sprite_status* pActwk) { /* Line 155, Address: 0x102abe0 */
  sprite_status* a1;
  short d0;

  switch_move(pActwk); /* Line 159, Address: 0x102abf4 */

  a1 = &actwk[((short*)pActwk)[31]]; /* Line 161, Address: 0x102ac00 */
  d0 = ((short*)a1)[32]; /* Line 162, Address: 0x102ac28 */
  if (d0 == 0) return; /* Line 163, Address: 0x102ac34 */



  if (pActwk->actfree[4] == 0) /* Line 167, Address: 0x102ac44 */
  {
    soundset(191); /* Line 169, Address: 0x102ac58 */
    pActwk->actfree[4] = 255; /* Line 170, Address: 0x102ac64 */
  }

  if ((unsigned short)((unsigned short)pActwk->actfree[5] + 16) < 256) /* Line 173, Address: 0x102ac70 */
  {
    pActwk->actfree[5] += 16; /* Line 175, Address: 0x102ac98 */
    return; /* Line 176, Address: 0x102aca8 */
  }
  pActwk->actfree[5] += 16; /* Line 178, Address: 0x102acb0 */

  pActwk->r_no0 += 2; /* Line 180, Address: 0x102acc0 */
  ride_on_clr(pActwk, &actwk[0]); /* Line 181, Address: 0x102acd0 */
  pActwk->actfree[15] = pActwk->actfree[14] = 0; /* Line 182, Address: 0x102ace4 */
  pActwk->patno = 2; /* Line 183, Address: 0x102acf8 */
} /* Line 184, Address: 0x102ad04 */




static void swgun4_move1(sprite_status* pActwk) { /* Line 189, Address: 0x102ad20 */
  sprite_status* a1;
  void(*tbl[4])(sprite_status*) = /* Line 191, Address: 0x102ad30 */
  {
    &hariset,
    &bp1000,
    &awaset,
    &ring4set
  };

  a1 = &actwk[((short*)pActwk)[31]]; /* Line 199, Address: 0x102ad5c */
  tbl[a1->actfree[11]](pActwk); /* Line 200, Address: 0x102ad84 */
} /* Line 201, Address: 0x102ada4 */




static void switch_move(sprite_status* pActwk) { /* Line 206, Address: 0x102adc0 */
  sprite_status* pPlayerwk;
  sprite_status* pActwk_m;
  unsigned short d0, d1;
  short r;
  unsigned char tbl[42] = /* Line 211, Address: 0x102ade0 */
  {
    2, 1, 0, 3, 3, 2,
    1, 0, 3, 3, 2, 2,
    0, 3, 3, 2, 2, 1,
    2, 2, 1, 0, 3, 3,
    3, 2, 2, 1, 0, 3,
    3, 3, 2, 2, 1, 0,
    0, 0, 0, 0, 0, 0
  };

  pActwk->actfree[6] = pActwk->actfree[7]; /* Line 222, Address: 0x102ae14 */

  pPlayerwk = &actwk[0]; /* Line 224, Address: 0x102ae24 */
  r = hitchk_u(pActwk, pPlayerwk); /* Line 225, Address: 0x102ae2c */
  if (r) /* Line 226, Address: 0x102ae44 */
  {
    pActwk->actfree[7] = 255; /* Line 228, Address: 0x102ae4c */
  } /* Line 229, Address: 0x102ae58 */
  else
  {
    pActwk->actfree[7] = 0; /* Line 232, Address: 0x102ae60 */
    goto label1; /* Line 233, Address: 0x102ae68 */
  }
  if (pPlayerwk->yspeed.w < 0) goto label1; /* Line 235, Address: 0x102ae70 */
  if (pActwk->actfree[4]) goto label1; /* Line 236, Address: 0x102ae84 */
  pActwk_m = &actwk[((short*)pActwk)[31]]; /* Line 237, Address: 0x102ae94 */
  ((short*)pActwk_m)[32] = (unsigned short)(pActwk - actwk); /* Line 238, Address: 0x102aebc */


  d0 = pActwk->actfree[10]; /* Line 241, Address: 0x102aef4 */
  d0 *= 6; /* Line 242, Address: 0x102af04 */
  d1 = pltime.b.b3; /* Line 243, Address: 0x102af14 */
  d1 &= 255; /* Line 244, Address: 0x102af28 */
  d1 /= 10; /* Line 245, Address: 0x102af30 */
  d1 &= 7; /* Line 246, Address: 0x102af4c */
  d0 += d1; /* Line 247, Address: 0x102af54 */
  pActwk->actfree[11] = tbl[d0]; /* Line 248, Address: 0x102af5c */

  pActwk_m->actfree[11] = pActwk->actfree[11]; /* Line 250, Address: 0x102af70 */


label1:
  if (pActwk->actfree[6] == 0 && pActwk->actfree[7] == 255) /* Line 254, Address: 0x102af7c */
  {
    pPlayerwk->yposi.w.h += 8; /* Line 256, Address: 0x102afa8 */
    pActwk->yposi.w.h += 4; /* Line 257, Address: 0x102afb4 */
    pActwk->patno = 1; /* Line 258, Address: 0x102afc4 */
    pActwk->sprvsize -= 4; /* Line 259, Address: 0x102afd0 */
  }

  if (pActwk->actfree[6] == 255 && pActwk->actfree[7] == 0) /* Line 262, Address: 0x102afe0 */
  {
    pPlayerwk->yposi.w.h -= 8; /* Line 264, Address: 0x102b00c */
    pActwk->yposi.w.h -= 4; /* Line 265, Address: 0x102b018 */
    pActwk->patno = 0; /* Line 266, Address: 0x102b028 */
    pActwk->sprvsize += 4; /* Line 267, Address: 0x102b030 */
  }
} /* Line 269, Address: 0x102b040 */




static void hariset(sprite_status* pActwk) { /* Line 274, Address: 0x102b070 */
  sprite_status* pMaster;
  sprite_status* pSlave;
  sprite_status* pNewActwk;

  if (pActwk->actfree[14]) /* Line 279, Address: 0x102b084 */
  {
    frameout(pActwk); /* Line 281, Address: 0x102b094 */
    return; /* Line 282, Address: 0x102b0a0 */
  }
  pMaster = &actwk[((short*)pActwk)[31]]; /* Line 284, Address: 0x102b0a8 */
  pSlave = &actwk[((short*)pMaster)[32]]; /* Line 285, Address: 0x102b0d0 */
  if (pActwk != pSlave) /* Line 286, Address: 0x102b0f4 */
  {
    if (pActwk->actfree[10] != 4) /* Line 288, Address: 0x102b100 */
    {
      if (actwkchk(&pNewActwk) == 0) /* Line 290, Address: 0x102b118 */
      {
        pNewActwk->actno = 34; /* Line 292, Address: 0x102b12c */
        pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 293, Address: 0x102b138 */

        ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 295, Address: 0x102b148 */
        pNewActwk->yposi.w.h = ((short*)pActwk)[27]; /* Line 296, Address: 0x102b158 */
      }
    }
  }
  ++pActwk->actfree[14]; /* Line 300, Address: 0x102b168 */
} /* Line 301, Address: 0x102b178 */




static void awaset(sprite_status* pActwk) { /* Line 306, Address: 0x102b190 */
  sprite_status* pMaster;
  sprite_status* pSlave;
  sprite_status* pNewActwk;

  pMaster = &actwk[((short*)pActwk)[31]]; /* Line 311, Address: 0x102b1a4 */
  pSlave = &actwk[((short*)pMaster)[32]]; /* Line 312, Address: 0x102b1cc */
  if (pActwk == pSlave) /* Line 313, Address: 0x102b1f0 */
  {
    if ((unsigned short)((unsigned short)pActwk->actfree[14] + 1) > 255) /* Line 315, Address: 0x102b1fc */
    {
      frameout(pActwk); /* Line 317, Address: 0x102b224 */
    }
    ++pActwk->actfree[14]; /* Line 319, Address: 0x102b230 */
    return; /* Line 320, Address: 0x102b240 */
  }
  if ((unsigned short)((unsigned short)pActwk->actfree[15] + 4) <= 255) /* Line 322, Address: 0x102b248 */
  {
    pActwk->actfree[15] += 4; /* Line 324, Address: 0x102b270 */
    return; /* Line 325, Address: 0x102b280 */
  }
  pActwk->actfree[15] += 4; /* Line 327, Address: 0x102b288 */
  if (actwkchk(&pNewActwk) == 0) /* Line 328, Address: 0x102b298 */
  {
    pNewActwk->actno = 32; /* Line 330, Address: 0x102b2ac */
    pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 331, Address: 0x102b2b8 */
    pNewActwk->yposi.w.h = ((short*)pActwk)[27]; /* Line 332, Address: 0x102b2c8 */
    pNewActwk->userflag.b.h = 2; /* Line 333, Address: 0x102b2d8 */
  }
  ++pActwk->actfree[14]; /* Line 335, Address: 0x102b2e4 */
  if (pActwk->actfree[14] >= 2) /* Line 336, Address: 0x102b2f4 */
  {
    frameout(pActwk); /* Line 338, Address: 0x102b30c */
  }
} /* Line 340, Address: 0x102b318 */




static void ring4set(sprite_status* pActwk) { /* Line 345, Address: 0x102b330 */
  sprite_status* pMaster;
  sprite_status* pNewActwk;
  short d0;
  char tbl[22] = /* Line 349, Address: 0x102b344 */
  {
    -32, 0, 32, 64, 96, 127, 96, 64, 32, 0, -32,
    -32, 0, 32, 64, 96, 127, 96, 64, 32, 0, -32
  };



  pMaster = &actwk[((short*)pActwk)[31]]; /* Line 357, Address: 0x102b378 */
  if (pActwk != pMaster) /* Line 358, Address: 0x102b3a0 */
  {
    frameout(pActwk); /* Line 360, Address: 0x102b3ac */
    return; /* Line 361, Address: 0x102b3b8 */
  }
  if ((unsigned short)pActwk->actfree[14] + 16 < 256) /* Line 363, Address: 0x102b3c0 */
  {
    pActwk->actfree[14] += 16; /* Line 365, Address: 0x102b3e0 */
    return; /* Line 366, Address: 0x102b3f0 */
  }
  pActwk->actfree[14] += 16; /* Line 368, Address: 0x102b3f8 */
  if (pActwk->actfree[15] >= 21) /* Line 369, Address: 0x102b408 */
  {
    frameout(pActwk); /* Line 371, Address: 0x102b420 */
    return; /* Line 372, Address: 0x102b42c */
  }

  if (actwkchk(&pNewActwk) == 0) /* Line 375, Address: 0x102b434 */
  {
    pNewActwk->actno = 64; /* Line 377, Address: 0x102b448 */
    d0 = pActwk->yposi.w.h; /* Line 378, Address: 0x102b454 */
    d0 -= 384; /* Line 379, Address: 0x102b464 */
    pNewActwk->yposi.w.h = d0; /* Line 380, Address: 0x102b470 */
    d0 = tbl[pActwk->actfree[15]]; /* Line 381, Address: 0x102b478 */
    d0 += pActwk->xposi.w.h; /* Line 382, Address: 0x102b49c */
    pNewActwk->xposi.w.h = d0; /* Line 383, Address: 0x102b4b0 */
  }
  ++pActwk->actfree[15]; /* Line 385, Address: 0x102b4b8 */
} /* Line 386, Address: 0x102b4c8 */




static void bp1000(sprite_status* pActwk) { /* Line 391, Address: 0x102b4e0 */
  sprite_status* pMaster;
  sprite_status* pSlave;
  sprite_status* pNewActwk;

  if (pActwk->actfree[14]) /* Line 396, Address: 0x102b4f4 */
  {
    frameout(pActwk); /* Line 398, Address: 0x102b504 */
    return; /* Line 399, Address: 0x102b510 */
  }
  pMaster = &actwk[((short*)pActwk)[31]]; /* Line 401, Address: 0x102b518 */
  pSlave = &actwk[((short*)pMaster)[32]]; /* Line 402, Address: 0x102b540 */
  if (pMaster != pSlave) /* Line 403, Address: 0x102b564 */
  {
    scoreup(100); /* Line 405, Address: 0x102b56c */
    if (actwkchk(&pNewActwk) == 0) /* Line 406, Address: 0x102b578 */
    {
      pNewActwk->actno = 65; /* Line 408, Address: 0x102b58c */
      pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 409, Address: 0x102b598 */
      pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 410, Address: 0x102b5a8 */
    }
  }
  ++pActwk->actfree[14]; /* Line 413, Address: 0x102b5b8 */
} /* Line 414, Address: 0x102b5c8 */











static sprite_pattern ringsp0 =
{
  1,
  { { -8, -8, 0, 362 } }
};
static sprite_pattern ringsp1 =
{
  1,
  { { -8, -8, 0, 363 } }
};
static sprite_pattern ringsp2 =
{
  1,
  { { -4, -8, 0, 364 } }
};
static sprite_pattern ringsp3 =
{
  1,
  { { -8, -8, 0, 365 } }
};
static sprite_pattern ringsp4 =
{
  1,
  { { -8, -8, 0, 366 } }
};
static sprite_pattern ringsp5 =
{
  1,
  { { -8, -8, 0, 367 } }
};
static sprite_pattern ringsp6 =
{
  1,
  { { -8, -8, 0, 368 } }
};
static sprite_pattern ringsp7 =
{
  1,
  { { -8, -8, 0, 369 } }
};
static sprite_pattern ringsp8;
static sprite_pattern* ringpat[9] =
{
  &ringsp0,
  &ringsp1,
  &ringsp2,
  &ringsp3,
  &ringsp4,
  &ringsp5,
  &ringsp6,
  &ringsp7,
  &ringsp8
};
static unsigned char pchg0[6] = { 5, 4, 5, 6, 7, 252 };
static unsigned char* ringchg[1] = { pchg0 };


void ring4(sprite_status* pActwk) { /* Line 483, Address: 0x102b5e0 */
  void(*tbl[5])(sprite_status*) = /* Line 484, Address: 0x102b5ec */
  {
    &ring4_init,
    &ring4_move,
    &ring4_get,
    &ring4_die,
    &ring4_erase
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 493, Address: 0x102b618 */
} /* Line 494, Address: 0x102b654 */




static void ring4_init(sprite_status* pActwk) { /* Line 499, Address: 0x102b670 */






  pActwk->r_no0 += 2; /* Line 506, Address: 0x102b67c */
  pActwk->sprvsize = 8; /* Line 507, Address: 0x102b68c */
  pActwk->sprhs = 8; /* Line 508, Address: 0x102b698 */
  pActwk->patbase = ringpat; /* Line 509, Address: 0x102b6a4 */
  pActwk->sproffset = 42926; /* Line 510, Address: 0x102b6b4 */
  pActwk->actflg |= 4; /* Line 511, Address: 0x102b6c0 */
  pActwk->sprpri = 3; /* Line 512, Address: 0x102b6d0 */
  pActwk->colino = 71; /* Line 513, Address: 0x102b6dc */
  pActwk->sprhsize = 8; /* Line 514, Address: 0x102b6e8 */
  ((short*)pActwk)[30] = 2048; /* Line 515, Address: 0x102b6f4 */
  pActwk->yspeed.w = 256; /* Line 516, Address: 0x102b700 */
  pActwk->actfree[16] = 255; /* Line 517, Address: 0x102b70c */
  pActwk->actfree[17] = 48; /* Line 518, Address: 0x102b718 */

  ring4_move(pActwk); /* Line 520, Address: 0x102b724 */
} /* Line 521, Address: 0x102b730 */




static void ring4_move(sprite_status* pActwk) { /* Line 526, Address: 0x102b740 */
  short d0, d1;

  speedset2(pActwk); /* Line 529, Address: 0x102b754 */
  pActwk->yspeed.w += 24; /* Line 530, Address: 0x102b760 */

  if (pActwk->actfree[17]) /* Line 532, Address: 0x102b770 */
  {
    --pActwk->actfree[17]; /* Line 534, Address: 0x102b780 */
    if (pActwk->actfree[17]) goto label1; /* Line 535, Address: 0x102b790 */
  }



  d1 = emycol_d(pActwk); /* Line 540, Address: 0x102b7a0 */
  if (d1 < 0) /* Line 541, Address: 0x102b7b4 */
  {
    pActwk->yposi.w.h += d1; /* Line 543, Address: 0x102b7c4 */
    d0 = pActwk->yspeed.w; /* Line 544, Address: 0x102b7d4 */
    d0 >>= 2; /* Line 545, Address: 0x102b7e4 */
    pActwk->yspeed.w -= d0; /* Line 546, Address: 0x102b7f0 */
    pActwk->yspeed.w *= -1; /* Line 547, Address: 0x102b800 */
  }
label1:
  d0 = ((short*)pActwk)[29]; /* Line 550, Address: 0x102b810 */
  d0 += ((short*)pActwk)[30]; /* Line 551, Address: 0x102b820 */
  ((short*)pActwk)[29] = d0; /* Line 552, Address: 0x102b834 */
  d0 >>= 12; /* Line 553, Address: 0x102b83c */
  d0 &= 3; /* Line 554, Address: 0x102b848 */
  pActwk->patno = d0; /* Line 555, Address: 0x102b854 */
  ((short*)pActwk)[30] -= 8; /* Line 556, Address: 0x102b860 */

  --pActwk->actfree[16]; /* Line 558, Address: 0x102b870 */
  if (pActwk->actfree[16] == 0) /* Line 559, Address: 0x102b880 */
  {
    ring4_erase(pActwk); /* Line 561, Address: 0x102b894 */
    return; /* Line 562, Address: 0x102b8a0 */
  }
  d0 = scralim_down; /* Line 564, Address: 0x102b8a8 */
  d0 += 224; /* Line 565, Address: 0x102b8b8 */
  if (d0 < pActwk->yposi.w.h) /* Line 566, Address: 0x102b8c4 */
  {
    ring4_erase(pActwk); /* Line 568, Address: 0x102b8e8 */
    return; /* Line 569, Address: 0x102b8f4 */
  }
  actionsub(pActwk); /* Line 571, Address: 0x102b8fc */
} /* Line 572, Address: 0x102b908 */




static void ring4_get(sprite_status* pActwk) { /* Line 577, Address: 0x102b920 */
  pActwk->r_no0 += 2; /* Line 578, Address: 0x102b92c */
  pActwk->colino = 0; /* Line 579, Address: 0x102b93c */
  pActwk->sprpri = 1; /* Line 580, Address: 0x102b944 */
  ringgetsub(); /* Line 581, Address: 0x102b950 */

  ring4_die(pActwk); /* Line 583, Address: 0x102b958 */
} /* Line 584, Address: 0x102b964 */




static void ring4_die(sprite_status* pActwk) { /* Line 589, Address: 0x102b980 */
  patchg(pActwk, ringchg); /* Line 590, Address: 0x102b98c */
  actionsub(pActwk); /* Line 591, Address: 0x102b9a0 */
} /* Line 592, Address: 0x102b9ac */




static void ring4_erase(sprite_status* pActwk) { /* Line 597, Address: 0x102b9c0 */
  frameout(pActwk); /* Line 598, Address: 0x102b9cc */
} /* Line 599, Address: 0x102b9d8 */
















static sprite_pattern pat00 =
{
  1,
  { { -8, -4, 0, 484 } }
};
sprite_pattern* tensu4pat[1] = { &pat00 };




void tensu4(sprite_status* pActwk) { /* Line 626, Address: 0x102b9f0 */
  void(*tbl[2])(sprite_status*) = /* Line 627, Address: 0x102b9fc */
  {
    &tensu4_init,
    &tensu4_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 633, Address: 0x102ba18 */
  actionsub(pActwk); /* Line 634, Address: 0x102ba54 */
} /* Line 635, Address: 0x102ba60 */




static void tensu4_init(sprite_status* pActwk) { /* Line 640, Address: 0x102ba70 */
  pActwk->r_no0 += 2; /* Line 641, Address: 0x102ba7c */
  pActwk->patbase = tensu4pat; /* Line 642, Address: 0x102ba8c */
  pActwk->sproffset = 878; /* Line 643, Address: 0x102ba9c */
  pActwk->actflg = 4; /* Line 644, Address: 0x102baa8 */
  pActwk->sprpri = 1; /* Line 645, Address: 0x102bab4 */
  pActwk->sprhsize = 8; /* Line 646, Address: 0x102bac0 */
  pActwk->yspeed.w = -768; /* Line 647, Address: 0x102bacc */

  tensu4_move(pActwk); /* Line 649, Address: 0x102bad8 */
} /* Line 650, Address: 0x102bae4 */




static void tensu4_move(sprite_status* pActwk) { /* Line 655, Address: 0x102bb00 */
  if (pActwk->yspeed.w >= 0) /* Line 656, Address: 0x102bb0c */
  {
    frameout(pActwk); /* Line 658, Address: 0x102bb24 */
  } /* Line 659, Address: 0x102bb30 */
  else
  {
    speedset2(pActwk); /* Line 662, Address: 0x102bb38 */
    pActwk->yspeed.w += 24; /* Line 663, Address: 0x102bb44 */
  }
} /* Line 665, Address: 0x102bb54 */
