#include "..\EQU.H"
#include "SHOOT5.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"

static void shooterinit(sprite_status* pActwk);
static void shootermove(sprite_status* pActwk);
static void shootermove2(sprite_status* pActwk);
static void shootermove3(sprite_status* pActwk);

short shooterposi_0[21] =
{
    40,
  9808, 208,
  9808, 240,
  9888, 272,
  9760, 304,
  9888, 336,
  9760, 368,
  9888, 400,
  9760, 432,
  9904, 488,
  9904, 520
};
short shooterposi_1[19] =
{
     36,
  10320, 496,
  10320, 528,
  10416, 560,
  10288, 592,
  10416, 624,
  10288, 656,
  10416, 688,
  10288, 720,
  10416, 752
};
short shooterposi_2[15] =
{
    28,
  2944, 672,
  2944, 728,
  2976, 752,
  2848, 784,
  2976, 816,
  2848, 848,
  2976, 880
};
short shooterposi_3[31] =
{
    60,
  9840, 264,
  9840, 288,
  9920, 320,
  9792, 352,
  9920, 384,
  9792, 416,
  9920, 448,
  9792, 480,
  9920, 512,
  9792, 544,
  9920, 576,
  9792, 608,
  9920, 640,
  9792, 672,
  9920, 752
};
short shooterposi_4[25] =
{
     48,
  10288, 296,
  10432, 368,
  10304, 400,
  10432, 432,
  10304, 464,
  10432, 496,
  10304, 528,
  10432, 560,
  10304, 592,
  10432, 624,
  10304, 656,
  10432, 752
};
short shooterposi_5[19] =
{
    36,
  6480, 488,
  6480, 528,
  6576, 560,
  6448, 592,
  6576, 624,
  6448, 656,
  6576, 688,
  6448, 720,
  6576, 752
};
short shooterposi_6[19] =
{
    36,
  6512, 488,
  6512, 528,
  6592, 560,
  6464, 592,
  6592, 624,
  6464, 656,
  6592, 688,
  6464, 720,
  6592, 752
};
short shooterposi_7[5] =
{
     8,
  1424, 200,
  1424, 376
};
short shooterposi_8[5] =
{
     8,
  1424, 200,
  1424, 376
};
short shooterposi_9[5] =
{
     8,
  1424, 376,
  1424, 200
};
short shooterposi_0a[5] =
{
     8,
  5744, 296,
  5744, 400
};
short shooterposi_0b[5] =
{
     8,
  5744, 400,
  5744, 296
};
short shooterposi_0c[5] =
{
     8,
  7088, 520,
  7088, 600
};
short shooterposi_0d[5] =
{
     8,
  7088, 600,
  7088, 520
};
short shooterposi_0e[5] =
{
     8,
  7120, 520,
  7120, 600
};
short shooterposi_0f[5] =
{
     8,
  7120, 600,
  7120, 520
};
short shooterposi_10[43] =
{
    84,
  6912, 112,
  6768, 112,
  6752, 128,
  6736, 160,
  6752, 192,
  6768, 208,
  6800, 208,
  6816, 224,
  6832, 256,
  6832, 296,
  6856, 344,
  6832, 392,
  6856, 440,
  6832, 488,
  6856, 536,
  6832, 584,
  6856, 632,
  6832, 680,
  6856, 728,
  6832, 776,
  6832, 856
};
short shooterposi_11[43] =
{
    84,
  6832, 856,
  6832, 776,
  6856, 728,
  6832, 680,
  6856, 632,
  6832, 584,
  6856, 536,
  6832, 488,
  6856, 440,
  6832, 392,
  6856, 344,
  6832, 296,
  6832, 256,
  6816, 224,
  6800, 208,
  6768, 208,
  6752, 192,
  6736, 160,
  6752, 128,
  6768, 112,
  6912, 112
};
short shooterposi_12[15] =
{
    28,
  5008, 672,
  5008, 736,
  5024, 752,
  4896, 784,
  5024, 816,
  4896, 848,
  5024, 880
};
short shooterposi_13[41] =
{
    80,
  6832, 856,
  6832, 760,
  6856, 712,
  6832, 664,
  6856, 616,
  6832, 568,
  6832, 504,
  6856, 456,
  6832, 408,
  6856, 360,
  6832, 312,
  6832, 256,
  6816, 224,
  6800, 208,
  6768, 208,
  6752, 192,
  6736, 160,
  6752, 128,
  6768, 112,
  6912, 112
};
short shooterposi_14[41] =
{
    80,
  6912, 112,
  6768, 112,
  6752, 128,
  6736, 160,
  6752, 192,
  6768, 208,
  6800, 208,
  6816, 224,
  6832, 256,
  6832, 312,
  6856, 360,
  6832, 408,
  6856, 456,
  6832, 504,
  6832, 568,
  6856, 616,
  6832, 664,
  6856, 712,
  6832, 760,
  6832, 856
};
short shooterposi_15[19] =
{
    36,
  6480, 488,
  6480, 528,
  6576, 544,
  6448, 576,
  6576, 608,
  6448, 640,
  6576, 672,
  6448, 704,
  6576, 736
};
short* shooterpositbl[22] =
{
  shooterposi_0,
  shooterposi_1,
  shooterposi_2,
  shooterposi_3,
  shooterposi_4,
  shooterposi_5,
  shooterposi_6,
  shooterposi_7,
  shooterposi_8,
  shooterposi_9,
  shooterposi_0a,
  shooterposi_0b,
  shooterposi_0c,
  shooterposi_0d,
  shooterposi_0e,
  shooterposi_0f,
  shooterposi_10,
  shooterposi_11,
  shooterposi_12,
  shooterposi_13,
  shooterposi_14,
  shooterposi_15
};














































void shooter(sprite_status* pActwk) { /* Line 357, Address: 0x101c0b0 */
  sprite_status* pPlayerwk;
  short d0, d1, d2;
  void(*shooter_move_tbl[4])(sprite_status*) = /* Line 360, Address: 0x101c0cc */
  {
    &shooterinit,
    &shootermove,
    &shootermove2,
    &shootermove3
  };

  if (time_flag & 128) /* Line 368, Address: 0x101c0f8 */
  {
    d0 = (unsigned short)pActwk->cdsts; /* Line 370, Address: 0x101c110 */
    if (d0) /* Line 371, Address: 0x101c12c */
    {
      d0 *= 3; /* Line 373, Address: 0x101c134 */
      d1 = (unsigned short)time_flag; /* Line 374, Address: 0x101c144 */
      d1 &= 127; /* Line 375, Address: 0x101c160 */
      d2 = time_item; /* Line 376, Address: 0x101c16c */
      d2 *= -1; /* Line 377, Address: 0x101c184 */
      d1 += d2; /* Line 378, Address: 0x101c190 */
      if (d1 < 0) /* Line 379, Address: 0x101c19c */
      {
        d1 = 0; /* Line 381, Address: 0x101c1ac */
      } /* Line 382, Address: 0x101c1b0 */
      else
      {
        if ((unsigned short)d1 >= 3) /* Line 385, Address: 0x101c1b8 */
        {
          d1 = 2; /* Line 387, Address: 0x101c1cc */
        }
      }
      d0 += d1; /* Line 390, Address: 0x101c1d8 */
      flagwork[d0] &= 127; /* Line 391, Address: 0x101c1e4 */
    }
  }
  if (!(pActwk->userflag.b.h & 128)) goto label2; /* Line 394, Address: 0x101c204 */
  if (colrevflag) goto label1; /* Line 395, Address: 0x101c220 */
  if (!(pActwk->userflag.b.h & 1)) goto label2; /* Line 396, Address: 0x101c230 */
  goto label3; /* Line 397, Address: 0x101c24c */
label1:
  if (!(pActwk->userflag.b.h & 1)) goto label3; /* Line 399, Address: 0x101c254 */
label2:
  pPlayerwk = &actwk[0]; /* Line 401, Address: 0x101c270 */
  if (pPlayerwk->mstno.b.h == 43) return; /* Line 402, Address: 0x101c278 */
  if (pPlayerwk->r_no0 >= 6) return; /* Line 403, Address: 0x101c290 */
  shooter_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 404, Address: 0x101c2a4 */

  if (pActwk->r_no0 >= 4) return; /* Line 406, Address: 0x101c2e0 */
label3:
  frameout_s(pActwk); /* Line 408, Address: 0x101c2f8 */


} /* Line 411, Address: 0x101c304 */




static void shooterinit(sprite_status* pActwk) { /* Line 416, Address: 0x101c330 */
  short* a2;
  short d0;

  pActwk->actflg = 4; /* Line 420, Address: 0x101c344 */
  pActwk->sprpri = 1; /* Line 421, Address: 0x101c350 */
  pActwk->sprhsize = 16; /* Line 422, Address: 0x101c35c */

  pActwk->r_no0 += 2; /* Line 424, Address: 0x101c368 */
  d0 = (unsigned short)pActwk->userflag.b.h; /* Line 425, Address: 0x101c378 */
  d0 &= 127; /* Line 426, Address: 0x101c398 */
  a2 = shooterpositbl[d0]; /* Line 427, Address: 0x101c3a4 */
  ((short*)pActwk)[31] = *a2++; /* Line 428, Address: 0x101c3c0 */
  ((short**)pActwk)[16] = a2; /* Line 429, Address: 0x101c3d4 */
  ((short*)pActwk)[29] = *a2++; /* Line 430, Address: 0x101c3dc */
  ((short*)pActwk)[30] = *a2++; /* Line 431, Address: 0x101c3f0 */

  shootermove(pActwk); /* Line 433, Address: 0x101c404 */
} /* Line 434, Address: 0x101c410 */




static void shootermove(sprite_status* pActwk) { /* Line 439, Address: 0x101c430 */
  sprite_status* pPlayerwk;
  short d0, d1;

  pPlayerwk = &actwk[0]; /* Line 443, Address: 0x101c448 */
  d0 = pPlayerwk->xposi.w.h; /* Line 444, Address: 0x101c450 */
  d0 -= pActwk->xposi.w.h; /* Line 445, Address: 0x101c45c */
  d0 += 16; /* Line 446, Address: 0x101c470 */
  if ((unsigned short)d0 >= 32) return; /* Line 447, Address: 0x101c47c */
  d1 = pPlayerwk->yposi.w.h; /* Line 448, Address: 0x101c490 */
  d1 -= pActwk->yposi.w.h; /* Line 449, Address: 0x101c49c */
  d1 += 16; /* Line 450, Address: 0x101c4b0 */
  if ((unsigned short)d1 >= 32) return; /* Line 451, Address: 0x101c4bc */
  if (pPlayerwk->actfree[2]) return; /* Line 452, Address: 0x101c4d0 */
  if (pPlayerwk->r_no0 == 4) /* Line 453, Address: 0x101c4dc */
  {
    pPlayerwk->r_no0 -= 2; /* Line 455, Address: 0x101c4f0 */
    ((short*)pPlayerwk)[26] = 120; /* Line 456, Address: 0x101c4fc */
  }
  pActwk->r_no0 += 2; /* Line 458, Address: 0x101c504 */
  pPlayerwk->actfree[2] = 129; /* Line 459, Address: 0x101c514 */
  pPlayerwk->mstno.b.h = 2; /* Line 460, Address: 0x101c51c */
  pPlayerwk->mspeed.w = 2560; /* Line 461, Address: 0x101c524 */
  pPlayerwk->xspeed.w = 0; /* Line 462, Address: 0x101c52c */
  pPlayerwk->yspeed.w = 0; /* Line 463, Address: 0x101c530 */
  pActwk->cddat &= 223; /* Line 464, Address: 0x101c534 */
  pPlayerwk->cddat &= 223; /* Line 465, Address: 0x101c544 */
  pPlayerwk->cddat |= 2; /* Line 466, Address: 0x101c550 */
  pPlayerwk->xposi.w.h = pActwk->xposi.w.h; /* Line 467, Address: 0x101c55c */
  pPlayerwk->yposi.w.h = pActwk->yposi.w.h; /* Line 468, Address: 0x101c568 */
  pActwk->actfree[8] = 0; /* Line 469, Address: 0x101c574 */
  soundset(145); /* Line 470, Address: 0x101c57c */
} /* Line 471, Address: 0x101c588 */




static void shootermove2(sprite_status* pActwk) { /* Line 476, Address: 0x101c5b0 */
  shooterspdset(pActwk); /* Line 477, Address: 0x101c5bc */
  pActwk->r_no0 += 2; /* Line 478, Address: 0x101c5c8 */
  soundset(145); /* Line 479, Address: 0x101c5d8 */
} /* Line 480, Address: 0x101c5e4 */




static void shootermove3(sprite_status* pActwk) { /* Line 485, Address: 0x101c600 */
  sprite_status* pPlayerwk;
  short* a2;
  int d0, d2, d3;
  unsigned char d1;

  pPlayerwk = &actwk[0]; /* Line 491, Address: 0x101c624 */
  --((char*)pActwk)[51]; /* Line 492, Address: 0x101c62c */
  if (((char*)pActwk)[51] < 0) /* Line 493, Address: 0x101c63c */
  {



    pPlayerwk->xposi.w.h = ((short*)pActwk)[29]; /* Line 498, Address: 0x101c654 */
    pPlayerwk->yposi.w.h = ((short*)pActwk)[30]; /* Line 499, Address: 0x101c660 */
    d1 = pActwk->actfree[17]; /* Line 500, Address: 0x101c66c */
    d1 = (char)d1 + 4; /* Line 501, Address: 0x101c678 */
    if (d1 >= pActwk->actfree[16]) /* Line 502, Address: 0x101c694 */
    {


      d1 = 0; /* Line 506, Address: 0x101c6b0 */
      goto label1; /* Line 507, Address: 0x101c6b4 */
    }
    pActwk->actfree[17] = d1; /* Line 509, Address: 0x101c6bc */
    a2 = ((short**)pActwk)[16]; /* Line 510, Address: 0x101c6c4 */
    a2 += d1 / 2; /* Line 511, Address: 0x101c6cc */
    ((short*)pActwk)[29] = *a2++; /* Line 512, Address: 0x101c6f0 */
    ((short*)pActwk)[30] = *a2++; /* Line 513, Address: 0x101c704 */
    shooterspdset(pActwk); /* Line 514, Address: 0x101c718 */
    return; /* Line 515, Address: 0x101c724 */
  }
  d2 = pPlayerwk->xposi.l; /* Line 517, Address: 0x101c72c */
  d3 = pPlayerwk->yposi.l; /* Line 518, Address: 0x101c730 */
  d0 = pPlayerwk->xspeed.w; /* Line 519, Address: 0x101c734 */
  d0 <<= 8; /* Line 520, Address: 0x101c740 */
  d2 += d0; /* Line 521, Address: 0x101c744 */
  d0 = pPlayerwk->yspeed.w; /* Line 522, Address: 0x101c748 */
  d0 <<= 8; /* Line 523, Address: 0x101c754 */
  d3 += d0; /* Line 524, Address: 0x101c758 */
  pPlayerwk->xposi.l = d2; /* Line 525, Address: 0x101c75c */
  pPlayerwk->yposi.l = d3; /* Line 526, Address: 0x101c760 */
  return; /* Line 527, Address: 0x101c764 */
label1:
  pPlayerwk->yposi.w.h &= 2047; /* Line 529, Address: 0x101c76c */
  pActwk->r_no0 = 0; /* Line 530, Address: 0x101c778 */
  pPlayerwk->actfree[2] = 0; /* Line 531, Address: 0x101c780 */
  pActwk->r_no1 = 2; /* Line 532, Address: 0x101c784 */

} /* Line 534, Address: 0x101c790 */




void shooterspdset(sprite_status* pActwk) { /* Line 539, Address: 0x101c7c0 */
  sprite_status* pPlayerwk;
  int_union ld0, ld1;
  short d2, d3, tmp;

  pPlayerwk = &actwk[0]; /* Line 544, Address: 0x101c7d8 */
  ld0.l = 0; /* Line 545, Address: 0x101c7e0 */
  if (!pPlayerwk->mspeed.w) goto label1; /* Line 546, Address: 0x101c7e4 */
  d2 = pPlayerwk->mspeed.w; /* Line 547, Address: 0x101c7f0 */
  d3 = pPlayerwk->mspeed.w; /* Line 548, Address: 0x101c7fc */
  goto label2; /* Line 549, Address: 0x101c808 */

label1:
    d2 = d3 = 2560; /* Line 552, Address: 0x101c810 */
label2:
  ld0.w.l = ((short*)pActwk)[29]; /* Line 554, Address: 0x101c82c */
  if (ld0.w.l < pPlayerwk->xposi.w.h) /* Line 555, Address: 0x101c838 */
  {
    ld0.w.l -= pPlayerwk->xposi.w.h; /* Line 557, Address: 0x101c85c */
    ld0.w.l *= -1; /* Line 558, Address: 0x101c86c */
    d2 *= -1; /* Line 559, Address: 0x101c878 */
  } /* Line 560, Address: 0x101c884 */
  else
  {
    ld0.w.l -= pPlayerwk->xposi.w.h; /* Line 563, Address: 0x101c88c */
  }
  ld1.l = 0; /* Line 565, Address: 0x101c89c */
  ld1.w.l = ((short*)pActwk)[30]; /* Line 566, Address: 0x101c8a0 */
  if (ld1.w.l < pPlayerwk->yposi.w.h) /* Line 567, Address: 0x101c8ac */
  {
    ld1.w.l -= pPlayerwk->yposi.w.h; /* Line 569, Address: 0x101c8d0 */
    ld1.w.l *= -1; /* Line 570, Address: 0x101c8e0 */
    d3 *= -1; /* Line 571, Address: 0x101c8ec */
  } /* Line 572, Address: 0x101c8f8 */
  else
  {
    ld1.w.l -= pPlayerwk->yposi.w.h; /* Line 575, Address: 0x101c900 */
  }
  if ((unsigned short)ld1.w.l >= (unsigned short)ld0.w.l) /* Line 577, Address: 0x101c910 */
  {
    ld1.l = 0; /* Line 579, Address: 0x101c934 */
    ld1.w.l = ((short*)pActwk)[30]; /* Line 580, Address: 0x101c938 */
    ld1.w.l -= pPlayerwk->yposi.w.h; /* Line 581, Address: 0x101c944 */
    tmp = ld1.w.h; /* Line 582, Address: 0x101c954 */
    ld1.w.h = ld1.w.l; /* Line 583, Address: 0x101c960 */
    ld1.w.l = tmp; /* Line 584, Address: 0x101c968 */
    ld1.w.l = ld1.l / d3; /* Line 585, Address: 0x101c96c */

    ld0.l = 0; /* Line 587, Address: 0x101c998 */
    ld0.w.l = ((short*)pActwk)[29]; /* Line 588, Address: 0x101c99c */
    ld0.w.l -= pPlayerwk->xposi.w.h; /* Line 589, Address: 0x101c9a8 */
    if (ld0.w.l) /* Line 590, Address: 0x101c9b8 */
    {
      tmp = ld0.w.h; /* Line 592, Address: 0x101c9c4 */
      ld0.w.h = ld0.w.l; /* Line 593, Address: 0x101c9d0 */
      ld0.w.l = tmp; /* Line 594, Address: 0x101c9d8 */
      ld0.w.l = ld0.l / ld1.w.l; /* Line 595, Address: 0x101c9dc */
    }
    pPlayerwk->xspeed.w = ld0.w.l; /* Line 597, Address: 0x101ca0c */
    pPlayerwk->yspeed.w = d3; /* Line 598, Address: 0x101ca14 */
    if (ld1.w.l < 0) /* Line 599, Address: 0x101ca18 */
    {
      ld1.w.l *= -1; /* Line 601, Address: 0x101ca2c */
    }
    ((short*)pActwk)[25] = ld1.w.l; /* Line 603, Address: 0x101ca38 */
  } /* Line 604, Address: 0x101ca44 */
  else
  {
    ld0.l = 0; /* Line 607, Address: 0x101ca4c */
    ld0.w.l = ((short*)pActwk)[29]; /* Line 608, Address: 0x101ca50 */
    ld0.w.l -= pPlayerwk->xposi.w.h; /* Line 609, Address: 0x101ca5c */
    tmp = ld0.w.h; /* Line 610, Address: 0x101ca6c */
    ld0.w.h = ld0.w.l; /* Line 611, Address: 0x101ca78 */
    ld0.w.l = tmp; /* Line 612, Address: 0x101ca80 */
    ld0.w.l = ld0.l / d2; /* Line 613, Address: 0x101ca84 */

    ld1.l = 0; /* Line 615, Address: 0x101cab0 */
    ld1.w.l = ((short*)pActwk)[30]; /* Line 616, Address: 0x101cab4 */
    ld1.w.l -= pPlayerwk->yposi.w.h; /* Line 617, Address: 0x101cac0 */
    if (ld1.w.l) /* Line 618, Address: 0x101cad0 */
    {
      tmp = ld1.w.h; /* Line 620, Address: 0x101cadc */
      ld1.w.h = ld1.w.l; /* Line 621, Address: 0x101cae8 */
      ld1.w.l = tmp; /* Line 622, Address: 0x101caf0 */
      ld1.w.l = ld1.l / ld0.w.l; /* Line 623, Address: 0x101caf4 */
    }
    pPlayerwk->yspeed.w = ld1.w.l; /* Line 625, Address: 0x101cb24 */
    pPlayerwk->xspeed.w = d2; /* Line 626, Address: 0x101cb2c */
    if (ld0.w.l < 0) /* Line 627, Address: 0x101cb30 */
    {
      ld0.w.l *= -1; /* Line 629, Address: 0x101cb44 */
    }
    ((short*)pActwk)[25] = ld0.w.l; /* Line 631, Address: 0x101cb50 */
  }
} /* Line 633, Address: 0x101cb5c */
