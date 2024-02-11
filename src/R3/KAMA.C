#include "..\EQU.H"
#include "KAMA.H"

static unsigned char bCarry;
static unsigned char jmp_flg;
void(*kama_tbl[7])(sprite_status*) = { &kama_init, &kama_fall, &kama_wait, &kama_atck, &kama_pati, &kama_move, &kama_reve };
void(*wpkama_tbl[3])(sprite_status*) = { &wpkama_init, &wpkama_wait, &wpkama_move };
unsigned char kama_pchg0[6] = { 7, 0, 1, 2, 3, 255 };
unsigned char kama_pchg1[4] = { 7, 5, 6, 255 };
unsigned char kama_pchg2[4] = { 7, 0, 4, 255 };
unsigned char kama_pchg3[4] = { 7, 7, 4, 255 };
unsigned char kama_pchg4[3] = { 7, 0, 255 };
unsigned char* kama_pchg[5] = { kama_pchg0, kama_pchg1, kama_pchg2, kama_pchg3, kama_pchg4 };
sprite_pattern kama_patA =
{
  3,
  { { -18, -20, 0, 471 }, { -12, -4, 0, 472 }, { -2, 4, 0, 473 } }
};
sprite_pattern kama_patB =
{
  3,
  { { -18, -19, 0, 474 }, { -12, -3, 0, 475 }, { -2, 4, 0, 476 } }
};
sprite_pattern kama_patC =
{
  3,
  { { -18, -20, 0, 477 }, { -12, -4, 0, 478 }, { -2, 4, 0, 479 } }
};
sprite_pattern kama_patD =
{
  3,
  { { -18, -19, 0, 480 }, { -12, -3, 0, 481 }, { -2, 4, 0, 482 } }
};
sprite_pattern kama_patE =
{
  3,
  { { -18, -19, 0, 483 }, { -12, -3, 0, 484 }, { -2, 4, 0, 485 } }
};
sprite_pattern kama_patF =
{
  4,
  { { -18, -19, 0, 486 }, { -24, -12, 0, 487 }, { -12, -4, 0, 488 }, { -2, 4, 0, 489 } }
};
sprite_pattern kama_patG =
{
  3,
  { { -18, -19, 0, 490 }, { -24, -11, 0, 491 }, { -12, -3, 0, 492 }, { -2, 4, 0, 493 } }
};
sprite_pattern kama_patH =
{
  3,
  { { -18, -20, 0, 494 }, { -12, -4, 0, 495 }, { -2, 4, 0, 496 } }
};
sprite_pattern* kamapat[8] = { &kama_patA, &kama_patB, &kama_patC, &kama_patD, &kama_patE, &kama_patF, &kama_patG, &kama_patH };
sprite_pattern bkama_patA =
{
  3,
  { { -18, -20, 0, 497 }, { -12, -4, 0, 498 }, { -2, 4, 0, 499 } }
};
sprite_pattern bkama_patB =
{
  3,
  { { -18, -19, 0, 500 }, { -12, -3, 0, 501 }, { -2, 4, 0, 502 } }
};
sprite_pattern bkama_patC =
{
  3,
  { { -18, -20, 0, 503 }, { -12, -4, 0, 504 }, { -2, 4, 0, 505 } }
};
sprite_pattern bkama_patD =
{
  3,
  { { -18, -19, 0, 506 }, { -12, -3, 0, 507 }, { -2, 4, 0, 508 } }
};
sprite_pattern bkama_patE =
{
  3,
  { { -18, -19, 0, 509 }, { -12, -3, 0, 510 }, { -2, 4, 0, 511 } }
};
sprite_pattern bkama_patF =
{
  3,
  { { -18, -20, 0, 512 }, { -12, -4, 0, 513 }, { -2, 4, 0, 514 } }
};
sprite_pattern bkama_patG =
{
  3,
  { { -18, -19, 0, 515 }, { -12, -3, 0, 516 }, { -2, 4, 0, 517 } }
};
sprite_pattern bkama_patH =
{
  3,
  { { -18, -20, 0, 518 }, { -12, -4, 0, 519 }, { -2, 4, 0, 520 } }
};
sprite_pattern* bkamapat[8] = { &bkama_patA, &bkama_patB, &bkama_patC, &bkama_patD, &bkama_patE, &bkama_patF, &bkama_patG, &bkama_patH };
unsigned char wpkama_pchg0[8] = { 3, 0, 1, 2, 3, 4, 5, 255 };
unsigned char wpkama_pchg1[8] = { 0, 0, 1, 2, 3, 4, 5, 255 };
unsigned char* wpkama_pchg[2] = { wpkama_pchg0, wpkama_pchg1 };
sprite_pattern bu0 = { 1, { { -8, -8, 0, 465 } } };
sprite_pattern bu1 = { 1, { { -8, -8, 0, 466 } } };
sprite_pattern bu2 = { 1, { { -8, -8, 0, 467 } } };
sprite_pattern bu3 = { 1, { { -8, -8, 0, 468 } } };
sprite_pattern bu4 = { 1, { { -8, -8, 0, 469 } } };
sprite_pattern bu5 = { 1, { { -8, -8, 0, 470 } } };
sprite_pattern* wpkamapat[6] = { &bu0, &bu1, &bu2, &bu3, &bu4, &bu5 };


void ene_kama(sprite_status* pActwk) { /* Line 108, Address: 0x1025bd0 */
  unsigned char byRwk;

  if (pActwk->xposi.w.h == 4800 && pActwk->yposi.w.h == 890) /* Line 111, Address: 0x1025be0 */
  {

    jmp_flg = 0; /* Line 114, Address: 0x1025c18 */
  }
  if (enemy_suicide(pActwk) == -1) return; /* Line 116, Address: 0x1025c20 */

  byRwk = pActwk->r_no0 / 2; /* Line 118, Address: 0x1025c40 */
  kama_tbl[byRwk](pActwk); /* Line 119, Address: 0x1025c6c */

  frameout_s(pActwk); /* Line 121, Address: 0x1025c90 */
} /* Line 122, Address: 0x1025c9c */











void kama_init(sprite_status* pActwk) { /* Line 134, Address: 0x1025cb0 */
  ((char*)pActwk)[50] = pActwk->userflag.b.h; /* Line 135, Address: 0x1025cbc */
  if (((char*)pActwk)[50] >= 0) /* Line 136, Address: 0x1025ccc */
  {
    pActwk->patno = 1; /* Line 138, Address: 0x1025ce4 */
    pActwk->patbase = kamapat; /* Line 139, Address: 0x1025cf0 */
  } /* Line 140, Address: 0x1025d00 */
  else
  {

    pActwk->patno = 2; /* Line 144, Address: 0x1025d08 */
    pActwk->patbase = bkamapat; /* Line 145, Address: 0x1025d14 */
  }

  pActwk->actflg = 4; /* Line 148, Address: 0x1025d24 */
  pActwk->sprpri = 3; /* Line 149, Address: 0x1025d30 */
  pActwk->sprhsize = 16; /* Line 150, Address: 0x1025d3c */
  pActwk->sprvsize = 20; /* Line 151, Address: 0x1025d48 */
  pActwk->sproffset = 9202; /* Line 152, Address: 0x1025d54 */
  pActwk->yspeed.w = 256; /* Line 153, Address: 0x1025d60 */
  pActwk->colino = 6; /* Line 154, Address: 0x1025d6c */
  pActwk->r_no0 += 2; /* Line 155, Address: 0x1025d78 */

  kama_fall(pActwk); /* Line 157, Address: 0x1025d88 */
} /* Line 158, Address: 0x1025d94 */





void kama_disp(sprite_status* pActwk) { /* Line 164, Address: 0x1025db0 */
  patchg(pActwk, kama_pchg); /* Line 165, Address: 0x1025dbc */
  actionsub(pActwk); /* Line 166, Address: 0x1025dd0 */
  jmp_flg = 1; /* Line 167, Address: 0x1025ddc */
} /* Line 168, Address: 0x1025de8 */










void kama_fall(sprite_status* pActwk) { /* Line 179, Address: 0x1025e00 */
  short iD1;

  movement(pActwk); /* Line 182, Address: 0x1025e10 */
  iD1 = emycol_d(pActwk); /* Line 183, Address: 0x1025e1c */
  if (iD1 < 0) /* Line 184, Address: 0x1025e30 */
    pActwk->r_no0 += 2; /* Line 185, Address: 0x1025e40 */

  kama_disp(pActwk); /* Line 187, Address: 0x1025e50 */
} /* Line 188, Address: 0x1025e5c */











void kama_wait(sprite_status* pActwk) { /* Line 200, Address: 0x1025e70 */
  short iD0, iD1;
  sprite_status* pPlaywk;

  if (pActwk->actflg & 128) /* Line 204, Address: 0x1025e88 */
  {
    pActwk->actflg &= 254; /* Line 206, Address: 0x1025ea0 */
    pActwk->cddat &= 254; /* Line 207, Address: 0x1025eb0 */

    pPlaywk = &actwk[0]; /* Line 209, Address: 0x1025ec0 */
    iD0 = pActwk->xposi.w.h; /* Line 210, Address: 0x1025ec8 */
    bCarry = CCset(iD0, pPlaywk->xposi.w.h); /* Line 211, Address: 0x1025ed8 */
    iD0 -= pPlaywk->xposi.w.h; /* Line 212, Address: 0x1025efc */
    if (bCarry == 1) /* Line 213, Address: 0x1025f0c */
    {
      iD0 = -iD0; /* Line 215, Address: 0x1025f24 */
      pActwk->actflg |= 1; /* Line 216, Address: 0x1025f40 */
      pActwk->cddat |= 1; /* Line 217, Address: 0x1025f50 */
    }

    if ((char)pActwk->actflg < 0) /* Line 220, Address: 0x1025f60 */
    {
      iD1 = pActwk->yposi.w.h; /* Line 222, Address: 0x1025f80 */
      bCarry = CCset(iD1, pPlaywk->yposi.w.h); /* Line 223, Address: 0x1025f90 */
      iD1 -= pPlaywk->yposi.w.h; /* Line 224, Address: 0x1025fb4 */
      if (bCarry == 1) /* Line 225, Address: 0x1025fc4 */
        iD1 = -iD1; /* Line 226, Address: 0x1025fdc */

      if (iD1 < 96) /* Line 228, Address: 0x1025ff8 */
      {

        pActwk->mstno.b.h = 2; /* Line 231, Address: 0x102600c */
        set_wpkama(pActwk); /* Line 232, Address: 0x1026018 */
        ((short*)pActwk)[24] = 160; /* Line 233, Address: 0x1026024 */
        pActwk->r_no0 += 2; /* Line 234, Address: 0x1026030 */
        kama_atck(pActwk); /* Line 235, Address: 0x1026040 */
        return; /* Line 236, Address: 0x102604c */
      }
    }
  }

  pActwk->mstno.b.h = 1; /* Line 241, Address: 0x1026054 */
  kama_disp(pActwk); /* Line 242, Address: 0x1026060 */
} /* Line 243, Address: 0x102606c */











void kama_atck(sprite_status* pActwk) { /* Line 255, Address: 0x1026090 */
  --((unsigned short*)pActwk)[24]; /* Line 256, Address: 0x102609c */
  if (((unsigned short*)pActwk)[24] != 0) /* Line 257, Address: 0x10260ac */
    kama_disp(pActwk); /* Line 258, Address: 0x10260c0 */
  else
  {

    pActwk->mstno.b.h = 3; /* Line 262, Address: 0x10260d4 */
    ((unsigned short*)pActwk)[24] = 60; /* Line 263, Address: 0x10260e0 */
    pActwk->r_no0 += 2; /* Line 264, Address: 0x10260ec */
    kama_pati(pActwk); /* Line 265, Address: 0x10260fc */
  }
} /* Line 267, Address: 0x1026108 */











void kama_pati(sprite_status* pActwk) { /* Line 279, Address: 0x1026120 */
  --((unsigned short*)pActwk)[24]; /* Line 280, Address: 0x102612c */
  if (((unsigned short*)pActwk)[24] != 0) /* Line 281, Address: 0x102613c */
    kama_disp(pActwk); /* Line 282, Address: 0x1026150 */
  else
  {

    pActwk->r_no0 += 2; /* Line 286, Address: 0x1026164 */
    kama_move(pActwk); /* Line 287, Address: 0x1026174 */
  }
} /* Line 289, Address: 0x1026180 */











void kama_move(sprite_status* pActwk) { /* Line 301, Address: 0x1026190 */
  short iD0, iD1;

  if (pActwk->userflag.b.h >= 0) /* Line 304, Address: 0x10261a4 */
    iD0 = 256; /* Line 305, Address: 0x10261bc */
  else
    iD0 = 128; /* Line 307, Address: 0x10261d0 */

  pActwk->mstno.b.h = 0; /* Line 309, Address: 0x10261dc */
  if (!(pActwk->cddat & 1)) /* Line 310, Address: 0x10261e4 */
    iD0 = -iD0; /* Line 311, Address: 0x10261fc */

  pActwk->xspeed.w = iD0; /* Line 313, Address: 0x1026218 */

  movement(pActwk); /* Line 315, Address: 0x1026220 */

  iD1 = dircol_l2(pActwk); /* Line 317, Address: 0x102622c */
  if (iD1 >= 0) /* Line 318, Address: 0x1026240 */
  {
    iD1 = dircol_r2(pActwk); /* Line 320, Address: 0x1026250 */
    if (iD1 >= 0) /* Line 321, Address: 0x1026264 */
    {
      iD1 = emycol_d(pActwk); /* Line 323, Address: 0x1026274 */
      if (iD1 == 0) /* Line 324, Address: 0x1026288 */
      {
        kama_disp(pActwk); /* Line 326, Address: 0x1026298 */
        return; /* Line 327, Address: 0x10262a4 */
      }
      if (iD1 < 7 && iD1 >= -6) /* Line 329, Address: 0x10262ac */
      {
        pActwk->yposi.w.h += iD1; /* Line 331, Address: 0x10262d4 */
        kama_disp(pActwk); /* Line 332, Address: 0x10262e4 */
        return; /* Line 333, Address: 0x10262f0 */
      }
    }
  }

  ((short*)pActwk)[24] = 72; /* Line 338, Address: 0x10262f8 */
  pActwk->mstno.b.h = 3; /* Line 339, Address: 0x1026304 */
  pActwk->r_no0 += 2; /* Line 340, Address: 0x1026310 */
  kama_reve(pActwk); /* Line 341, Address: 0x1026320 */
} /* Line 342, Address: 0x102632c */











void kama_reve(sprite_status* pActwk) { /* Line 354, Address: 0x1026350 */
  --((unsigned short*)pActwk)[24]; /* Line 355, Address: 0x102635c */
  if (((unsigned short*)pActwk)[24] == 0) /* Line 356, Address: 0x102636c */
  {
    pActwk->actflg = bchg(0, pActwk->actflg); /* Line 358, Address: 0x1026380 */
    pActwk->cddat = bchg(0, pActwk->cddat); /* Line 359, Address: 0x102639c */
    pActwk->r_no0 -= 2; /* Line 360, Address: 0x10263b8 */
  }
  kama_disp(pActwk); /* Line 362, Address: 0x10263c8 */
} /* Line 363, Address: 0x10263d4 */











void movement(sprite_status* pActwk) { /* Line 375, Address: 0x10263f0 */
  int lD0 = 0; /* Line 376, Address: 0x10263fc */

  lD0 = pActwk->xspeed.w; /* Line 378, Address: 0x1026400 */
  if (-2147483648 & lD0) lD0 <<= 8, lD0 |= -2147483648; else lD0 <<= 8; /* Line 379, Address: 0x1026410 */
  pActwk->xposi.l += lD0; /* Line 380, Address: 0x1026438 */

  lD0 = pActwk->yspeed.w; /* Line 382, Address: 0x1026448 */
  if (-2147483648 & lD0) lD0 <<= 8, lD0 |= -2147483648; else lD0 <<= 8; /* Line 383, Address: 0x1026458 */
  pActwk->yposi.l += lD0; /* Line 384, Address: 0x1026480 */
} /* Line 385, Address: 0x1026490 */











void set_wpkama(sprite_status* pActwk) { /* Line 397, Address: 0x10264a0 */
  sprite_status* pActfree;

  if (pActwk->userflag.b.h >= 0) /* Line 400, Address: 0x10264ac */
  {

    if (actwkchk(&pActfree) == 0) /* Line 403, Address: 0x10264c4 */
    {
      pActfree->actno = 37; /* Line 405, Address: 0x10264d8 */

      ((unsigned short*)pActfree)[26] = pActwk - actwk; /* Line 407, Address: 0x10264e4 */

      ((short*)pActfree)[24] = 64; /* Line 409, Address: 0x1026518 */
      pActfree->userflag.b.h = pActwk->userflag.b.h; /* Line 410, Address: 0x1026524 */

      pActfree->actfree[4] = pActwk->actflg; /* Line 412, Address: 0x1026534 */

      pActfree->yposi.w.h = pActwk->yposi.w.h - 4; /* Line 414, Address: 0x1026544 */
      if (!(pActwk->actflg & 1)) /* Line 415, Address: 0x1026568 */
        pActfree->xposi.w.h = pActwk->xposi.w.h - 17; /* Line 416, Address: 0x1026580 */
      else
        pActfree->xposi.w.h = pActwk->xposi.w.h + 17; /* Line 418, Address: 0x10265ac */
    }

    if (actwkchk(&pActfree) == 0) /* Line 421, Address: 0x10265d0 */
    {
      pActfree->actno = 37; /* Line 423, Address: 0x10265e4 */

      ((unsigned short*)pActfree)[26] = pActwk - actwk; /* Line 425, Address: 0x10265f0 */

      ((short*)pActfree)[24] = 20; /* Line 427, Address: 0x1026624 */
      pActfree->userflag.b.h = pActwk->userflag.b.h; /* Line 428, Address: 0x1026630 */

      pActfree->actfree[4] = pActwk->actflg; /* Line 430, Address: 0x1026640 */

      pActfree->yposi.w.h = pActwk->yposi.w.h - 6; /* Line 432, Address: 0x1026650 */
      if (!(pActwk->actflg & 1)) /* Line 433, Address: 0x1026674 */
        pActfree->xposi.w.h = pActwk->xposi.w.h - 9; /* Line 434, Address: 0x102668c */
      else
        pActfree->xposi.w.h = pActwk->xposi.w.h + 9; /* Line 436, Address: 0x10266b8 */
    }
  }
} /* Line 439, Address: 0x10266dc */






















void tama_kama(sprite_status* pActwk) { /* Line 462, Address: 0x10266f0 */
  jmp_flg = 0; /* Line 463, Address: 0x10266fc */
  wpkama_tbl[pActwk->r_no0 / 2](pActwk); /* Line 464, Address: 0x1026704 */
  actionsub(pActwk); /* Line 465, Address: 0x1026748 */
  frameout_s00(pActwk, ((short*)pActwk)[27]); /* Line 466, Address: 0x1026754 */
  jmp_flg = 0; /* Line 467, Address: 0x1026768 */
} /* Line 468, Address: 0x1026770 */











void wpkama_init(sprite_status* pActwk) { /* Line 480, Address: 0x1026780 */
  short iD1;

  pActwk->actflg = 4; /* Line 483, Address: 0x102678c */
  pActwk->sprpri = 1; /* Line 484, Address: 0x1026798 */
  pActwk->sprhs = 4; /* Line 485, Address: 0x10267a4 */
  pActwk->sprvsize = 4; /* Line 486, Address: 0x10267b0 */
  pActwk->sproffset = 9202; /* Line 487, Address: 0x10267bc */
  pActwk->patbase = wpkamapat; /* Line 488, Address: 0x10267c8 */
  ((short*)pActwk)[27] = pActwk->xposi.w.h; /* Line 489, Address: 0x10267d8 */

  iD1 = 768; /* Line 491, Address: 0x10267e8 */

  if (!(pActwk->actfree[4] & 1)) /* Line 493, Address: 0x10267f4 */
  {
    pActwk->actflg |= 1; /* Line 495, Address: 0x102680c */
    pActwk->cddat |= 1; /* Line 496, Address: 0x102681c */
    iD1 = -iD1; /* Line 497, Address: 0x102682c */
  }

  pActwk->xspeed.w = iD1; /* Line 500, Address: 0x1026848 */
  pActwk->r_no0 += 2; /* Line 501, Address: 0x1026850 */
} /* Line 502, Address: 0x1026860 */












void wpkama_wait(sprite_status* pActwk) { /* Line 515, Address: 0x1026870 */
  unsigned short wD0;
  sprite_status* pActfree;

  --((unsigned short*)pActwk)[24]; /* Line 519, Address: 0x1026884 */
  if (((unsigned short*)pActwk)[24] == 0) /* Line 520, Address: 0x1026894 */
  {
    pActwk->r_no0 += 2; /* Line 522, Address: 0x10268a8 */
    pActwk->colino = 135; /* Line 523, Address: 0x10268b8 */
    ((short*)pActwk)[28] = 60; /* Line 524, Address: 0x10268c4 */
  }

  wD0 = ((unsigned short*)pActwk)[26]; /* Line 527, Address: 0x10268d0 */
  pActfree = &actwk[wD0]; /* Line 528, Address: 0x10268dc */
  if (pActfree->actno != 36) /* Line 529, Address: 0x10268f8 */
    frameout(pActwk); /* Line 530, Address: 0x102690c */
  else

    patchg(pActwk, wpkama_pchg); /* Line 533, Address: 0x1026920 */
  jmp_flg = 1; /* Line 534, Address: 0x1026934 */
} /* Line 535, Address: 0x1026940 */












void wpkama_move(sprite_status* pActwk) { /* Line 548, Address: 0x1026960 */
  sprite_status* pPlaywk;

  movement(pActwk); /* Line 551, Address: 0x1026970 */
  pActwk->yspeed.w += ((short*)pActwk)[23]; /* Line 552, Address: 0x102697c */

  if (pActwk->patno == 0) /* Line 554, Address: 0x1026994 */
  {
    if (pActwk->actflg & 128) /* Line 556, Address: 0x10269a8 */
      soundset(185); /* Line 557, Address: 0x10269c0 */
  }

  pPlaywk = &actwk[0]; /* Line 560, Address: 0x10269cc */
  if (wpkama_colicheck(pActwk, pPlaywk) != 0) /* Line 561, Address: 0x10269d4 */
    wpkama_reve(pActwk, pPlaywk); /* Line 562, Address: 0x10269f4 */
  wpkama_disp(pActwk); /* Line 563, Address: 0x1026a04 */
} /* Line 564, Address: 0x1026a10 */












void wpkama_disp(sprite_status* pActwk) { /* Line 577, Address: 0x1026a30 */
  --((unsigned short*)pActwk)[28]; /* Line 578, Address: 0x1026a3c */
  if (((unsigned short*)pActwk)[28] == 0) /* Line 579, Address: 0x1026a4c */
  {
    ++((unsigned short*)pActwk)[28]; /* Line 581, Address: 0x1026a60 */
    pActwk->colino = 0; /* Line 582, Address: 0x1026a70 */
  }

  patchg(pActwk, wpkama_pchg); /* Line 585, Address: 0x1026a78 */
  jmp_flg = 1; /* Line 586, Address: 0x1026a8c */
} /* Line 587, Address: 0x1026a98 */












short wpkama_colicheck(sprite_status* pActwk, sprite_status* pPlaywk) { /* Line 600, Address: 0x1026ab0 */
  unsigned char byFlg;
  short iD0, iD1;

  if (plpower_m == 0) /* Line 604, Address: 0x1026acc */
  {
    if (!(pPlaywk->cddat & 4)) /* Line 606, Address: 0x1026ae0 */
      return 0; /* Line 607, Address: 0x1026af8 */
  }

  iD0 = pPlaywk->xposi.w.h - pActwk->xposi.w.h; /* Line 610, Address: 0x1026b04 */
  iD1 = 28; /* Line 611, Address: 0x1026b38 */
  iD0 += iD1; /* Line 612, Address: 0x1026b44 */
  if (iD0 < 0) return 0; /* Line 613, Address: 0x1026b50 */
  iD1 += iD1; /* Line 614, Address: 0x1026b6c */
  byFlg = CCset(iD0, iD1); /* Line 615, Address: 0x1026b78 */
  if (byFlg == 0) return 0; /* Line 616, Address: 0x1026b94 */

  iD0 = pPlaywk->yposi.w.h - pActwk->yposi.w.h; /* Line 618, Address: 0x1026bac */
  iD1 = 28; /* Line 619, Address: 0x1026be0 */
  iD0 += iD1; /* Line 620, Address: 0x1026bec */
  if (iD0 < 0) return 0; /* Line 621, Address: 0x1026bf8 */
  iD1 += iD1; /* Line 622, Address: 0x1026c14 */
  byFlg = CCset(iD0, iD1); /* Line 623, Address: 0x1026c20 */
  if (byFlg == 0) return 0; /* Line 624, Address: 0x1026c3c */

  return 1; /* Line 626, Address: 0x1026c54 */
} /* Line 627, Address: 0x1026c58 */













void wpkama_reve(sprite_status* pActwk, sprite_status* pPlaywk) { /* Line 641, Address: 0x1026c80 */
  pActwk->colino = 0; /* Line 642, Address: 0x1026c8c */
  pActwk->mstno.b.h = 1; /* Line 643, Address: 0x1026c94 */

  pActwk->xspeed.w += pPlaywk->xspeed.w; /* Line 645, Address: 0x1026ca0 */
  pActwk->yspeed.w = -2048; /* Line 646, Address: 0x1026cb8 */
  ((short*)pActwk)[23] = 64; /* Line 647, Address: 0x1026cc4 */
} /* Line 648, Address: 0x1026cd0 */
