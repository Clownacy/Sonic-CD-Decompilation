#include "EQU.H"
#include "TREE.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "PLAYSUB.H"

void(*hoshi_tbl[2])(act_info*, act_info*) = { &hoshi_init, &hoshi_move };
void(*k0_tbl[2])(act_info*, act_info*) = { &k0_init, &k0_move };
void(*kasoku_tbl[2])(act_info*, act_info*) = { &kasoku_init, &kasoku_move };
spr_array hoshipat0 = {
  1, { { -24, -20, 0, 392 } }
};
spr_array hoshipat1 = {
  1, { { -12, -12, 0, 393 } }
};
spr_array* hoshipat[2] = { &hoshipat0, &hoshipat1 };
unsigned char kasokuchg0[12] = { 0, 4, 4, 3, 3, 3, 5, 5, 2, 2, 2, 255 };
unsigned char kasokuchg1[6] = { 2, 4, 7, 5, 6, 255 };
unsigned char kasokuchg2[6] = { 2, 8, 0, 9, 0, 255 };
unsigned char* kasokuchg[3] = { kasokuchg0, kasokuchg1, kasokuchg2 };
spr_array kasokupat_a = {
  1, { { -24, -24, 0, 382 } }
};
spr_array kasokupat_b = {
  1, { { -35, -24, 0, 383 } }
};
spr_array kasokupat_c = {
  1, { { -40, -24, 0, 384 } }
};
spr_array kasokupat_d = {
  1, { { -43, -24, 0, 385 } }
};
spr_array kasokupat_e = {
  1, { { -40, -24, 0, 386 } }
};
spr_array kasokupat_f = {
  1, { { -40, -24, 0, 387 } }
};
spr_array kasokupat_g = {
  1, { { -40, -24, 0, 387 } }
};
spr_array kasokupat_h = {
  1, { { -40, -24, 0, 388 } }
};
spr_array kasokupat_i = {
  1, { { -28, -24, 0, 389 } }
};
spr_array kasokupat_j = {
  1, { { -28, -24, 0, 390 } }
};
spr_array* kasokupat[10] = { &kasokupat_a, &kasokupat_b, &kasokupat_c, &kasokupat_d, &kasokupat_e, &kasokupat_f, &kasokupat_g, &kasokupat_h, &kasokupat_i, &kasokupat_j };

void hoshi(act_info* pActwk) { /* Line 53, Address: 0x101ae10 */
  short iXposi;

  hoshi_tbl[pActwk->r_no0 / 2](pActwk, &actwk[0]); /* Line 56, Address: 0x101ae20 */
  actionsub(pActwk); /* Line 57, Address: 0x101ae6c */
  iXposi = ((unsigned short*)pActwk)[23]; /* Line 58, Address: 0x101ae78 */
  frameout_s00(pActwk, iXposi); /* Line 59, Address: 0x101ae88 */
} /* Line 60, Address: 0x101ae98 */

















void hoshi_init(act_info* pActwk, act_info* pPlaywk) { /* Line 81, Address: 0x101aeb0 */
  act_info* pActfree;
  short i, iXwork, iLp, iOffset;
  short tbl0[4] = { 64, 128, -64, -128 }; /* Line 84, Address: 0x101aed0 */
  short tbl1[3] = { 0, 96, -96 }; /* Line 85, Address: 0x101aefc */

  iXwork = pPlaywk->xposi.w.h; /* Line 87, Address: 0x101af20 */
  pActwk->actflg |= 4; /* Line 88, Address: 0x101af30 */
  pActwk->patbase = hoshipat; /* Line 89, Address: 0x101af40 */
  pActwk->sproffset = 17444; /* Line 90, Address: 0x101af50 */
  pActwk->sprhsize = 24; /* Line 91, Address: 0x101af5c */
  pActwk->sprvsize = 20; /* Line 92, Address: 0x101af68 */
  iXwork = pActwk->xposi.w.h; /* Line 93, Address: 0x101af74 */
  pActfree = pActwk; /* Line 94, Address: 0x101af84 */
  if (pActwk->userflag.b.h & 1) iLp = 2; /* Line 95, Address: 0x101af8c */
  else iLp = 4; /* Line 96, Address: 0x101afbc */
  pActwk->userflag.b.h &= -2; /* Line 97, Address: 0x101afc8 */

  iOffset = 0; /* Line 99, Address: 0x101afdc */

  for (i = 0; i < iLp; ++i, ++iOffset) /* Line 101, Address: 0x101afe0 */
  {
    if (i > 0) /* Line 103, Address: 0x101afec */
      actwkchk(&pActfree); /* Line 104, Address: 0x101affc */
    pActfree->r_no0 += 2; /* Line 105, Address: 0x101b008 */
    pActfree->actno = 44; /* Line 106, Address: 0x101b018 */
    pActfree->xposi.w.h = iXwork; /* Line 107, Address: 0x101b024 */
    pActfree->yposi.w.h = pActwk->yposi.w.h; /* Line 108, Address: 0x101b02c */
    ((short*)pActfree)[23] = iXwork; /* Line 109, Address: 0x101b03c */
    pActfree->patbase = pActwk->patbase; /* Line 110, Address: 0x101b044 */
    pActfree->sproffset = pActwk->sproffset; /* Line 111, Address: 0x101b054 */
    pActfree->sprhsize = pActwk->sprhsize; /* Line 112, Address: 0x101b064 */
    pActfree->sprvsize = pActwk->sprvsize; /* Line 113, Address: 0x101b074 */
    pActfree->actflg |= 4; /* Line 114, Address: 0x101b084 */
    pActfree->xposi.w.h += tbl0[iOffset]; /* Line 115, Address: 0x101b094 */
    ((short*)pActfree)[24] = pActfree->xposi.w.h; /* Line 116, Address: 0x101b0b8 */
  } /* Line 117, Address: 0x101b0c8 */

  iLp = 3; /* Line 119, Address: 0x101b0fc */
  iOffset = 0; /* Line 120, Address: 0x101b108 */

  for (i = 0; i < iLp; ++i, ++iOffset) /* Line 122, Address: 0x101b10c */
  {
    actwkchk(&pActfree); /* Line 124, Address: 0x101b118 */
    pActfree->r_no0 += 2; /* Line 125, Address: 0x101b124 */
    pActfree->actno = 44; /* Line 126, Address: 0x101b134 */
    pActfree->userflag.b.h = 1; /* Line 127, Address: 0x101b140 */
    pActfree->patno = 1; /* Line 128, Address: 0x101b14c */
    pActfree->sprpri = 4; /* Line 129, Address: 0x101b158 */
    pActfree->xposi.w.h = iXwork; /* Line 130, Address: 0x101b164 */
    ((short*)pActfree)[23] = iXwork; /* Line 131, Address: 0x101b16c */
    pActfree->yposi.w.h = pActwk->yposi.w.h; /* Line 132, Address: 0x101b174 */
    pActfree->patbase = pActwk->patbase; /* Line 133, Address: 0x101b184 */
    pActfree->sproffset = pActwk->sproffset; /* Line 134, Address: 0x101b194 */
    pActfree->sprhsize = 12; /* Line 135, Address: 0x101b1a4 */
    pActfree->sprvsize = 12; /* Line 136, Address: 0x101b1b0 */
    pActfree->actflg |= 4; /* Line 137, Address: 0x101b1bc */
    pActfree->xposi.w.h += tbl1[iOffset]; /* Line 138, Address: 0x101b1cc */
  } /* Line 139, Address: 0x101b1f0 */
} /* Line 140, Address: 0x101b224 */














void hoshi_move(act_info* pActwk, act_info* pPlaywk) { /* Line 155, Address: 0x101b250 */
  short iXwork = 0; /* Line 156, Address: 0x101b260 */

  if (pActwk->userflag.b.h != 0) return; /* Line 158, Address: 0x101b264 */
  if (pPlaywk->actfree[2] & 2) /* Line 159, Address: 0x101b27c */
  {
    iXwork = pPlaywk->xposi.w.h; /* Line 161, Address: 0x101b294 */
    iXwork &= 255; /* Line 162, Address: 0x101b2a4 */
    if (pPlaywk->xposi.w.h < ((short*)pActwk)[23]) /* Line 163, Address: 0x101b2b0 */
      iXwork = 255 - iXwork; /* Line 164, Address: 0x101b2dc */

    if (iXwork >= 192) /* Line 166, Address: 0x101b2fc */
    {
      if (iXwork >= 240) iXwork = 0; /* Line 168, Address: 0x101b310 */
      else iXwork = 191; /* Line 169, Address: 0x101b330 */
    }

    iXwork >>= 1; /* Line 172, Address: 0x101b33c */
    if (pPlaywk->xposi.w.h < ((short*)pActwk)[23]) /* Line 173, Address: 0x101b348 */
      iXwork = -iXwork; /* Line 174, Address: 0x101b374 */

  }
  iXwork += ((unsigned short*)pActwk)[24]; /* Line 177, Address: 0x101b380 */
  pActwk->xposi.w.h = iXwork; /* Line 178, Address: 0x101b39c */
} /* Line 179, Address: 0x101b3a4 */












void kasoku0(act_info* pActwk) { /* Line 192, Address: 0x101b3c0 */
  k0_tbl[pActwk->r_no0 / 2](pActwk, &actwk[0]); /* Line 193, Address: 0x101b3cc */
  frameout_s(pActwk); /* Line 194, Address: 0x101b418 */
} /* Line 195, Address: 0x101b424 */





















void k0_init(act_info* pActwk, act_info* pPlaywk) { /* Line 217, Address: 0x101b440 */
  pActwk->r_no0 += 2; /* Line 218, Address: 0x101b450 */
  pActwk->actflg |= 4; /* Line 219, Address: 0x101b460 */
  k0_move(pActwk, pPlaywk); /* Line 220, Address: 0x101b470 */
} /* Line 221, Address: 0x101b480 */














void k0_move(act_info* pActwk, act_info* pPlaywk) { /* Line 236, Address: 0x101b490 */
  short iD0;

  if (pPlaywk->mstno.b.h == 43) return; /* Line 239, Address: 0x101b4a0 */
  iD0 = pActwk->yposi.w.h - pPlaywk->yposi.w.h; /* Line 240, Address: 0x101b4bc */
  iD0 += 64; /* Line 241, Address: 0x101b4f0 */
  if (iD0 >= 128) return; /* Line 242, Address: 0x101b4fc */

  iD0 = pActwk->xposi.w.h - pPlaywk->xposi.w.h; /* Line 244, Address: 0x101b510 */
  iD0 += 32; /* Line 245, Address: 0x101b544 */
  if (iD0 >= 64) return; /* Line 246, Address: 0x101b550 */

  if (pPlaywk->xspeed.w >= 0) return; /* Line 248, Address: 0x101b564 */
  if (pActwk->xposi.w.h < pPlaywk->xposi.w.h) return; /* Line 249, Address: 0x101b57c */

  pPlaywk->xposi.w.h = pActwk->xposi.w.h; /* Line 251, Address: 0x101b5a8 */
  pPlaywk->xspeed.w = 0; /* Line 252, Address: 0x101b5b8 */
  pPlaywk->mspeed.w = 0; /* Line 253, Address: 0x101b5c0 */
  pPlaywk->mstno.b.h = 55; /* Line 254, Address: 0x101b5c8 */
  pPlaywk->actfree[18] = 1; /* Line 255, Address: 0x101b5d4 */
  pPlaywk->actfree[14] = 0; /* Line 256, Address: 0x101b5e0 */
  pActwk->sprvsize = 14; /* Line 257, Address: 0x101b5e8 */
  pActwk->sprhs = 7; /* Line 258, Address: 0x101b5f4 */
  pActwk->yposi.w.h += 5; /* Line 259, Address: 0x101b600 */
  pPlaywk->cddat |= 4; /* Line 260, Address: 0x101b610 */


  pActwk->userflag.b.l = 0; /* Line 263, Address: 0x101b620 */
} /* Line 264, Address: 0x101b628 */












void kasoku(act_info* pActwk) { /* Line 277, Address: 0x101b640 */
  short iXwork;

  if (pActwk->userflag.b.l != 0) /* Line 280, Address: 0x101b650 */
  {
    kasoku0(pActwk); /* Line 282, Address: 0x101b668 */
    return; /* Line 283, Address: 0x101b674 */
  }
  kasoku_tbl[pActwk->r_no0 / 2](pActwk, &actwk[0]); /* Line 285, Address: 0x101b67c */
  actionsub(pActwk); /* Line 286, Address: 0x101b6c8 */
  iXwork = ((unsigned short*)pActwk)[23]; /* Line 287, Address: 0x101b6d4 */
  frameout_s00(pActwk, iXwork); /* Line 288, Address: 0x101b6e4 */
} /* Line 289, Address: 0x101b6f4 */




















void kasoku_init(act_info* pActwk, act_info* pPlaywk) { /* Line 310, Address: 0x101b710 */
  pActwk->r_no0 += 2; /* Line 311, Address: 0x101b720 */
  pActwk->actflg |= 4; /* Line 312, Address: 0x101b730 */
  pActwk->sprpri = 1; /* Line 313, Address: 0x101b740 */
  pActwk->patbase = kasokupat; /* Line 314, Address: 0x101b74c */
  pActwk->sproffset = 1089; /* Line 315, Address: 0x101b75c */
  pActwk->sprhsize = 32; /* Line 316, Address: 0x101b768 */
  pActwk->sprvsize = 32; /* Line 317, Address: 0x101b774 */
  ((short*)pActwk)[23] = pActwk->xposi.w.h; /* Line 318, Address: 0x101b780 */
  if (pActwk->userflag.b.h != 0) /* Line 319, Address: 0x101b790 */
  {
    pActwk->actflg |= 1; /* Line 321, Address: 0x101b7a8 */
    pActwk->cddat |= 1; /* Line 322, Address: 0x101b7b8 */
  }
  kasoku_move(pActwk, pPlaywk); /* Line 324, Address: 0x101b7c8 */
} /* Line 325, Address: 0x101b7d8 */














void kasoku_move(act_info* pActwk, act_info* pPlaywk) { /* Line 340, Address: 0x101b7f0 */
  short iD0, iD1, iD2;
  int lD0wk;


  if (pActwk->actfree[4] != 0) /* Line 345, Address: 0x101b810 */
  {
    pActwk->mstno.b.h = 1; /* Line 347, Address: 0x101b824 */
    if ((pPlaywk->actfree[2] & 2) == 0) /* Line 348, Address: 0x101b830 */
      ++pActwk->mstno.b.h; /* Line 349, Address: 0x101b848 */

    patchg(pActwk, kasokuchg); /* Line 351, Address: 0x101b858 */
  } /* Line 352, Address: 0x101b86c */
  else
  {
    pActwk->patno = 0; /* Line 355, Address: 0x101b874 */
    iD1 = 0; /* Line 356, Address: 0x101b87c */
    if ((pPlaywk->actfree[2] & 2) == 0) goto label1; /* Line 357, Address: 0x101b880 */
  }

  iD0 = pPlaywk->xposi.w.h & 255; /* Line 360, Address: 0x101b898 */
  if (pActwk->userflag.b.h != 0) /* Line 361, Address: 0x101b8bc */
    iD0 = 255 - iD0; /* Line 362, Address: 0x101b8d4 */

  if (iD0 >= 192) /* Line 364, Address: 0x101b8f4 */
    if (iD0 >= 240) iD0 = 0; /* Line 365, Address: 0x101b908 */
    else iD0 = 191; /* Line 366, Address: 0x101b928 */

  lD0wk = iD0; /* Line 368, Address: 0x101b934 */
  iD1 = iD0; /* Line 369, Address: 0x101b93c */
  if (pActwk->actfree[4] == 0) /* Line 370, Address: 0x101b944 */
  {
    lD0wk /= 48; /* Line 372, Address: 0x101b958 */
    pActwk->patno = lD0wk & 255; /* Line 373, Address: 0x101b970 */
  }

  iD1 >>= 2; /* Line 376, Address: 0x101b980 */
  iD2 = iD1 >> 1; /* Line 377, Address: 0x101b98c */
  iD1 += iD2; /* Line 378, Address: 0x101b9a8 */
  if (pActwk->userflag.b.h != 0) iD1 = -iD1; /* Line 379, Address: 0x101b9b4 */
label1:
  pActwk->xposi.w.h = ((short*)pActwk)[23] + iD1; /* Line 381, Address: 0x101b9d8 */

  if (pActwk->actfree[4] != 0) /* Line 383, Address: 0x101ba04 */
    --pActwk->actfree[4]; /* Line 384, Address: 0x101ba18 */




  iD1 = pActwk->sprhsize; /* Line 389, Address: 0x101ba28 */
  iD0 = pPlaywk->xposi.w.h - pActwk->xposi.w.h; /* Line 390, Address: 0x101ba3c */
  iD0 += iD1; /* Line 391, Address: 0x101ba70 */
  if (iD0 < 0) return; /* Line 392, Address: 0x101ba7c */
  iD1 += iD1; /* Line 393, Address: 0x101ba8c */
  if (iD0 >= iD1) return; /* Line 394, Address: 0x101ba98 */

  iD1 = pActwk->sprvsize; /* Line 396, Address: 0x101bab4 */
  iD0 = pPlaywk->yposi.w.h - pActwk->yposi.w.h; /* Line 397, Address: 0x101bac8 */
  iD0 += iD1; /* Line 398, Address: 0x101bafc */
  if (iD0 < 0) return; /* Line 399, Address: 0x101bb08 */
  iD1 += iD1; /* Line 400, Address: 0x101bb18 */
  if (iD0 >= iD1) return; /* Line 401, Address: 0x101bb24 */
  if (pPlaywk->mstno.b.h == 43) return; /* Line 402, Address: 0x101bb40 */

  if (pActwk->actfree[4] == 0) /* Line 404, Address: 0x101bb5c */
    pActwk->actfree[4] = 60; /* Line 405, Address: 0x101bb70 */

  if (pPlaywk->yspeed.w < 0) /* Line 407, Address: 0x101bb7c */
  {
    pPlaywk->yspeed.w = -3072; /* Line 409, Address: 0x101bb94 */
  } /* Line 410, Address: 0x101bba0 */
  else
  {
    pPlaywk->yspeed.w = 3072; /* Line 413, Address: 0x101bba8 */
  }
}
