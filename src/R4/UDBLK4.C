#include "..\EQU.H"
#include "UDBLK4.H"

typedef struct {
  unsigned char kakudo;
  char xofst;
}
kakudo_xofst;

typedef struct {
  char xofs;
  char yofs;
  short yspd;
}
xofs_yofs_yspd;

void sin_move(sprite_status* pActwk, short d2, short d3);
void udblk4_type1(sprite_status* pActwk);
void type1_init(sprite_status* pActwk);
void type1_move(sprite_status* pActwk);
void udblk4_type2();
void udblk4_type3(sprite_status* pActwk);
void type3_init(sprite_status* pActwk);
void type3_move(sprite_status* pActwk);
void udblk4_type4(sprite_status* pActwk);
void type4_coset(sprite_status* pActwk, sprite_status* pNewActwk, unsigned char d0, short d1);
void type4_init(sprite_status* pActwk);
void type4_move(sprite_status* pActwk);
void udblk4_type5(sprite_status* pActwk);
void type5_coset(sprite_status* pActwk, sprite_status* pNewActwk, unsigned char d0, short d1, unsigned char d2, short d3);
void type5_init(sprite_status* pActwk);
void type5_move(sprite_status* pActwk);
void udblk4_type6(sprite_status* pActwk);
void type6_init(sprite_status* pActwk);
void type6_move(sprite_status* pActwk);
void udblk4_type7(sprite_status* pActwk);
void type7_coset(sprite_status* pActwk, sprite_status* pNewActwk, unsigned char d0, short d1, unsigned char d2);
void type7_init(sprite_status* pActwk);
void type7_move(sprite_status* pActwk);
void udblk4_type8(sprite_status* pActwk);
void type8_init(sprite_status* pActwk);
void type8_move(sprite_status* pActwk);
void udblk4_type9(sprite_status* pActwk);
void type9_init(sprite_status* pActwk);
void type9_move(sprite_status* pActwk);
void udblk4_typeA(sprite_status* pActwk);
void typeA_init(sprite_status* pActwk);
void typeA_move(sprite_status* pActwk);
void udblk4_typeB(sprite_status* pActwk);
void typeB_init(sprite_status* pActwk);
void typeB_move(sprite_status* pActwk);

static sprite_pattern pat00 =
{
  1,
  { { -16, -64, 0, 523 } }
};
static sprite_pattern pat01 =
{
  1,
  { { -32, -96, 0, 524 } }
};
static sprite_pattern pat02 =
{
  1,
  { { -16, -48, 0, 525 } }
};
static sprite_pattern pat03 =
{
  1,
  { { -16, -64, 0, 526 } }
};
static sprite_pattern pat04 =
{
  1,
  { { -16, -32, 0, 527 } }
};
static sprite_pattern pat05 =
{
  1,
  { { -16, -96, 0, 528 } }
};
static sprite_pattern pat06 =
{
  1,
  { { -32, -48, 0, 529 } }
};
static sprite_pattern pat07 =
{
  1,
  { { -16, -16, 0, 530 } }
};
sprite_pattern* udblk4pat1[1] = { &pat00 };
sprite_pattern* udblk4pat3[1] = { &pat01 };
sprite_pattern* udblk4pat4[1] = { &pat02 };
sprite_pattern* udblk4pat5[1] = { &pat03 };
sprite_pattern* udblk4pat7[1] = { &pat03 };
sprite_pattern* udblk4pat8[1] = { &pat04 };
sprite_pattern* udblk4pat6[2] =
{
  &pat05,
  &pat06
};
sprite_pattern* udblk4pat9[2] =
{
  &pat05,
  &pat06
};
sprite_pattern* udblk4patA[1] = { &pat07 };



















































void udblk4(sprite_status* pActwk) { /* Line 161, Address: 0x102c9f0 */
  void(*tbl[12])(sprite_status*) = /* Line 162, Address: 0x102c9fc */
  {
    &udblk4_type1,
    &udblk4_type1,
    &udblk4_type2,
    &udblk4_type3,
    &udblk4_type4,
    &udblk4_type5,
    &udblk4_type6,
    &udblk4_type7,
    &udblk4_type8,
    &udblk4_type9,
    &udblk4_typeA,
    &udblk4_typeB
  };

  tbl[pActwk->userflag.b.h](pActwk); /* Line 178, Address: 0x102ca30 */
} /* Line 179, Address: 0x102ca58 */




static void sin_move(sprite_status* pActwk, short d2, short d3) { /* Line 184, Address: 0x102ca70 */
  int_union ld0;
  int stk;
  short d0, d1;

  if (pActwk->yspeed.w < 0) /* Line 189, Address: 0x102ca88 */
  {
    ride_on_chk(pActwk, &actwk[0]); /* Line 191, Address: 0x102caa0 */
  }
  stk = pActwk->yposi.l; /* Line 193, Address: 0x102cab4 */
  sinset(pActwk->actfree[16], &d0, &d1); /* Line 194, Address: 0x102cabc */
  d1 = d0; /* Line 195, Address: 0x102cad4 */
  d0 <<= d2; /* Line 196, Address: 0x102cadc */
  d1 <<= d3; /* Line 197, Address: 0x102caec */
  d0 += d1; /* Line 198, Address: 0x102cafc */
  d0 >>= 8; /* Line 199, Address: 0x102cb0c */

  ++pActwk->actfree[16]; /* Line 201, Address: 0x102cb18 */
  d0 += ((short*)pActwk)[27]; /* Line 202, Address: 0x102cb28 */
  pActwk->yposi.w.h = d0; /* Line 203, Address: 0x102cb3c */
  ld0.w.h = d0; /* Line 204, Address: 0x102cb48 */
  ld0.w.l = 0; /* Line 205, Address: 0x102cb50 */
  ld0.l -= stk; /* Line 206, Address: 0x102cb54 */
  ld0.l >>= 8; /* Line 207, Address: 0x102cb60 */
  pActwk->yspeed.w = ld0.w.l; /* Line 208, Address: 0x102cb6c */

  if (pActwk->yspeed.w >= 0) /* Line 210, Address: 0x102cb78 */
  {
    ride_on_chk(pActwk, &actwk[0]); /* Line 212, Address: 0x102cb90 */
  }
} /* Line 214, Address: 0x102cba4 */




static void udblk4_type1(sprite_status* pActwk) { /* Line 219, Address: 0x102cbc0 */
  void(*tbl[2])(sprite_status*) = /* Line 220, Address: 0x102cbcc */
  {
    &type1_init,
    &type1_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 226, Address: 0x102cbe8 */
  actionsub(pActwk); /* Line 227, Address: 0x102cc24 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 228, Address: 0x102cc30 */
} /* Line 229, Address: 0x102cc44 */




static void type1_init(sprite_status* pActwk) { /* Line 234, Address: 0x102cc60 */
  sprite_status* pNewActwk;
  short i;
  unsigned char d0, d1;
  kakudo_xofst tbl[7] = /* Line 238, Address: 0x102cc78 */
  {
    { 192,   0 },
    { 168, 224 },
    { 144, 192 },
    { 120, 160 },
    { 216,  32 },
    { 240,  64 },
    {   8,  96 }
  };

  pActwk->r_no0 += 2; /* Line 249, Address: 0x102ccac */
  pActwk->actflg |= 4; /* Line 250, Address: 0x102ccbc */
  pActwk->sproffset = 17514; /* Line 251, Address: 0x102cccc */
  pActwk->sprpri = 3; /* Line 252, Address: 0x102ccd8 */
  pActwk->patbase = udblk4pat1; /* Line 253, Address: 0x102cce4 */
  ((short*)pActwk)[27] = pActwk->yposi.w.h + 64; /* Line 254, Address: 0x102ccf4 */
  pActwk->sprhsize = 16; /* Line 255, Address: 0x102cd18 */
  pActwk->sprvsize = 64; /* Line 256, Address: 0x102cd24 */

  if (pActwk->actfree[18] == 0) /* Line 258, Address: 0x102cd30 */
  {
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 260, Address: 0x102cd44 */
    d1 = 1; /* Line 261, Address: 0x102cd54 */
    for (i = 0; i < 6; ++i) /* Line 262, Address: 0x102cd5c */
    {
      if (actwkchk(&pNewActwk) == 0) /* Line 264, Address: 0x102cd68 */
      {
        pNewActwk->actno = 35; /* Line 266, Address: 0x102cd7c */
        pNewActwk->userflag.b.h = 1; /* Line 267, Address: 0x102cd88 */
        pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 268, Address: 0x102cd94 */
        pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 269, Address: 0x102cda4 */
        ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 270, Address: 0x102cdb4 */
        pNewActwk->actfree[18] = d1; /* Line 271, Address: 0x102cdc4 */
      }
      ++d1; /* Line 273, Address: 0x102cdcc */
    } /* Line 274, Address: 0x102cdd4 */
  }
  d0 = pActwk->actfree[18]; /* Line 276, Address: 0x102cdf4 */
  pActwk->actfree[16] = tbl[d0].kakudo; /* Line 277, Address: 0x102ce00 */
  pActwk->xposi.w.h += tbl[d0].xofst; /* Line 278, Address: 0x102ce18 */
  type1_move(pActwk); /* Line 279, Address: 0x102ce40 */
} /* Line 280, Address: 0x102ce4c */




static void type1_move(sprite_status* pActwk) { /* Line 285, Address: 0x102ce70 */
  sin_move(pActwk, 6, 0); /* Line 286, Address: 0x102ce7c */
} /* Line 287, Address: 0x102ce90 */




static void udblk4_type2(sprite_status* pActwk) { /* Line 292, Address: 0x102cea0 */

} /* Line 294, Address: 0x102cea4 */




static void udblk4_type3(sprite_status* pActwk) { /* Line 299, Address: 0x102ceb0 */
  void(*tbl[2])(sprite_status*) = /* Line 300, Address: 0x102cebc */
  {
    &type3_init,
    &type3_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 306, Address: 0x102ced8 */
  actionsub(pActwk); /* Line 307, Address: 0x102cf14 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 308, Address: 0x102cf20 */
} /* Line 309, Address: 0x102cf34 */




static void type3_init(sprite_status* pActwk) { /* Line 314, Address: 0x102cf50 */
  pActwk->r_no0 += 2; /* Line 315, Address: 0x102cf5c */
  pActwk->actflg |= 4; /* Line 316, Address: 0x102cf6c */
  pActwk->sproffset = 17514; /* Line 317, Address: 0x102cf7c */
  pActwk->sprpri = 3; /* Line 318, Address: 0x102cf88 */
  pActwk->patbase = udblk4pat3; /* Line 319, Address: 0x102cf94 */
  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 320, Address: 0x102cfa4 */
  ((short*)pActwk)[27] = pActwk->yposi.w.h - 80; /* Line 321, Address: 0x102cfb4 */
  pActwk->sprhsize = 32; /* Line 322, Address: 0x102cfd8 */
  pActwk->sprvsize = 96; /* Line 323, Address: 0x102cfe4 */
  pActwk->actfree[16] = 64; /* Line 324, Address: 0x102cff0 */

  type3_move(pActwk); /* Line 326, Address: 0x102cffc */
} /* Line 327, Address: 0x102d008 */




static void type3_move(sprite_status* pActwk) { /* Line 332, Address: 0x102d020 */
  sin_move(pActwk, 6, 4); /* Line 333, Address: 0x102d02c */
} /* Line 334, Address: 0x102d040 */




static void udblk4_type4(sprite_status* pActwk) { /* Line 339, Address: 0x102d050 */
  void(*tbl[2])(sprite_status*) = /* Line 340, Address: 0x102d05c */
  {
    &type4_init,
    &type4_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 346, Address: 0x102d078 */
  actionsub(pActwk); /* Line 347, Address: 0x102d0b4 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 348, Address: 0x102d0c0 */
} /* Line 349, Address: 0x102d0d4 */




static void type4_coset(sprite_status* pActwk, sprite_status* pNewActwk, unsigned char d0, short d1) { /* Line 354, Address: 0x102d0f0 */
  pNewActwk->actno = 35; /* Line 355, Address: 0x102d104 */
  pNewActwk->userflag.b.h = 4; /* Line 356, Address: 0x102d110 */
  pNewActwk->actfree[18] = d0; /* Line 357, Address: 0x102d11c */
  pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 358, Address: 0x102d128 */
  pNewActwk->xposi.w.h = pActwk->xposi.w.h + d1; /* Line 359, Address: 0x102d138 */
  ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 360, Address: 0x102d168 */
} /* Line 361, Address: 0x102d178 */




static void type4_init(sprite_status* pActwk) { /* Line 366, Address: 0x102d190 */
  sprite_status* pNewActwk;

  pActwk->r_no0 += 2; /* Line 369, Address: 0x102d19c */
  pActwk->actflg |= 4; /* Line 370, Address: 0x102d1ac */
  pActwk->sproffset = 17514; /* Line 371, Address: 0x102d1bc */
  pActwk->sprpri = 3; /* Line 372, Address: 0x102d1c8 */
  pActwk->patbase = udblk4pat4; /* Line 373, Address: 0x102d1d4 */
  ((short*)pActwk)[27] = pActwk->yposi.w.h + 48; /* Line 374, Address: 0x102d1e4 */
  pActwk->sprhsize = 18; /* Line 375, Address: 0x102d208 */
  pActwk->sprvsize = 48; /* Line 376, Address: 0x102d214 */
  pActwk->actfree[16] = 192; /* Line 377, Address: 0x102d220 */

  if (pActwk->actfree[18] == 0) /* Line 379, Address: 0x102d22c */
  {

    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 382, Address: 0x102d240 */
  }
  if (actwkchk(&pNewActwk) == 0) /* Line 384, Address: 0x102d250 */
  {

    pNewActwk->actno = 34; /* Line 387, Address: 0x102d264 */

    pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 389, Address: 0x102d270 */
    pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 390, Address: 0x102d280 */
    ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 391, Address: 0x102d290 */

    ((short*)pNewActwk)[28] = (unsigned short)(pActwk - actwk); /* Line 393, Address: 0x102d2a0 */
    pNewActwk->actfree[15] = 64; /* Line 394, Address: 0x102d2dc */
    pNewActwk->userflag.b.h = 1; /* Line 395, Address: 0x102d2e8 */
  }
  if (pActwk->actfree[18] == 0) /* Line 397, Address: 0x102d2f4 */
  {
    if (actwkchk(&pNewActwk) == 0) /* Line 399, Address: 0x102d308 */
    {
      type4_coset(pActwk, pNewActwk, 1, -80); /* Line 401, Address: 0x102d31c */
    }
    if (actwkchk(&pNewActwk) == 0) /* Line 403, Address: 0x102d334 */
    {
      type4_coset(pActwk, pNewActwk, 2, 80); /* Line 405, Address: 0x102d348 */
    }
  }

  type4_move(pActwk); /* Line 409, Address: 0x102d360 */
} /* Line 410, Address: 0x102d36c */




static void type4_move(sprite_status* pActwk) { /* Line 415, Address: 0x102d380 */
  short stk;
  short d0, d1;

  stk = pActwk->yposi.w.h; /* Line 419, Address: 0x102d390 */
  sinset(pActwk->actfree[16], &d0, &d1); /* Line 420, Address: 0x102d3a0 */
  d0 *= 3; /* Line 421, Address: 0x102d3b8 */
  d0 >>= 4; /* Line 422, Address: 0x102d3c8 */
  d0 += ((short*)pActwk)[27]; /* Line 423, Address: 0x102d3d4 */
  pActwk->yposi.w.h = d0; /* Line 424, Address: 0x102d3e8 */
  ++pActwk->actfree[16]; /* Line 425, Address: 0x102d3f4 */
  d1 = stk; /* Line 426, Address: 0x102d404 */
  d0 -= d1; /* Line 427, Address: 0x102d408 */
  d0 <<= 8; /* Line 428, Address: 0x102d418 */
  pActwk->yspeed.w = d0; /* Line 429, Address: 0x102d424 */
  d1 = ((short*)pActwk)[28]; /* Line 430, Address: 0x102d430 */
  if (d1) /* Line 431, Address: 0x102d43c */
  {
    actwk[d1].yspeed.w = d0; /* Line 433, Address: 0x102d448 */
  }
  ride_on_chk(pActwk, &actwk[0]); /* Line 435, Address: 0x102d474 */
} /* Line 436, Address: 0x102d488 */




static void udblk4_type5(sprite_status* pActwk) { /* Line 441, Address: 0x102d4a0 */
  void(*tbl[2])(sprite_status*) = /* Line 442, Address: 0x102d4ac */
  {
    &type5_init,
    &type5_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 448, Address: 0x102d4c8 */
  actionsub(pActwk); /* Line 449, Address: 0x102d504 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 450, Address: 0x102d510 */
} /* Line 451, Address: 0x102d524 */




static void type5_coset(sprite_status* pActwk, sprite_status* pNewActwk, unsigned char d0, short d1, unsigned char d2, short d3) { /* Line 456, Address: 0x102d540 */
  pNewActwk->actno = 35; /* Line 457, Address: 0x102d55c */
  pNewActwk->userflag.b.h = 5; /* Line 458, Address: 0x102d568 */
  pNewActwk->actfree[18] = d0; /* Line 459, Address: 0x102d574 */
  pNewActwk->actfree[16] = d2; /* Line 460, Address: 0x102d580 */

  pNewActwk->xposi.w.h = pActwk->xposi.w.h + d1; /* Line 462, Address: 0x102d58c */

  pNewActwk->yposi.w.h = pActwk->yposi.w.h + d3; /* Line 464, Address: 0x102d5bc */
  ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 465, Address: 0x102d5ec */
} /* Line 466, Address: 0x102d5fc */




static void type5_init(sprite_status* pActwk) { /* Line 471, Address: 0x102d610 */
  sprite_status* pNewActwk;

  pActwk->r_no0 += 2; /* Line 474, Address: 0x102d61c */
  pActwk->actflg |= 4; /* Line 475, Address: 0x102d62c */
  pActwk->sproffset = 17514; /* Line 476, Address: 0x102d63c */
  pActwk->sprpri = 3; /* Line 477, Address: 0x102d648 */
  pActwk->patbase = udblk4pat5; /* Line 478, Address: 0x102d654 */
  ((short*)pActwk)[27] = pActwk->yposi.w.h + 64; /* Line 479, Address: 0x102d664 */
  pActwk->sprhsize = 20; /* Line 480, Address: 0x102d688 */
  pActwk->sprvsize = 65; /* Line 481, Address: 0x102d694 */

  if (pActwk->actfree[18] == 0) /* Line 483, Address: 0x102d6a0 */
  {
    
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 486, Address: 0x102d6b4 */
    pActwk->actfree[16] = 0; /* Line 487, Address: 0x102d6c4 */
    if (actwkchk(&pNewActwk) == 0) /* Line 488, Address: 0x102d6cc */
    {
      type5_coset(pActwk, pNewActwk, 1, 32, 240, -32); /* Line 490, Address: 0x102d6e0 */
    }
    if (actwkchk(&pNewActwk) == 0) /* Line 492, Address: 0x102d700 */
    {
      type5_coset(pActwk, pNewActwk, 1, 64, 224, -64); /* Line 494, Address: 0x102d714 */
    }
    if (actwkchk(&pNewActwk) == 0) /* Line 496, Address: 0x102d734 */
    {
      type5_coset(pActwk, pNewActwk, 1, 96, 208, -96); /* Line 498, Address: 0x102d748 */
    }
  }

  type5_move(pActwk); /* Line 502, Address: 0x102d768 */
} /* Line 503, Address: 0x102d774 */




static void type5_move(sprite_status* pActwk) { /* Line 508, Address: 0x102d790 */
  sin_move(pActwk, 6, 0); /* Line 509, Address: 0x102d79c */
} /* Line 510, Address: 0x102d7b0 */




static void udblk4_type6(sprite_status* pActwk) { /* Line 515, Address: 0x102d7c0 */
  if (pActwk->r_no0) type6_move(pActwk); /* Line 516, Address: 0x102d7cc */
  else type6_init(pActwk); /* Line 517, Address: 0x102d7f0 */
} /* Line 518, Address: 0x102d7fc */




static void type6_init(sprite_status* pActwk) { /* Line 523, Address: 0x102d810 */
  sprite_status* pNewActwk;
  short i, d1;
  kakudo_xofst tbl[7] = /* Line 526, Address: 0x102d824 */
  {
    {   0,   0 },
    {  32, 224 },
    {  64, 192 },
    {  96, 160 },
    {  32,  32 },
    {  64,  64 },
    {  96,  96 }
  };

  pActwk->r_no0 += 2; /* Line 537, Address: 0x102d858 */
  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 538, Address: 0x102d868 */
  d1 = 0; /* Line 539, Address: 0x102d878 */
  for (i = 0; i < 7; ++i) /* Line 540, Address: 0x102d87c */
  {
    if (actwkchk(&pNewActwk) == 0) /* Line 542, Address: 0x102d888 */
    {
      pNewActwk->actno = 35; /* Line 544, Address: 0x102d89c */
      pNewActwk->userflag.b.h = 9; /* Line 545, Address: 0x102d8a8 */
      pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 546, Address: 0x102d8b4 */
      ((short*)pNewActwk)[28] = (unsigned short)(pActwk - actwk); /* Line 547, Address: 0x102d8c4 */
      pNewActwk->actfree[19] = 255; /* Line 548, Address: 0x102d900 */
      pNewActwk->actfree[16] = tbl[d1].kakudo; /* Line 549, Address: 0x102d90c */
      pNewActwk->xposi.w.h = pActwk->xposi.w.h + tbl[d1].xofst; /* Line 550, Address: 0x102d928 */
    }
    ++d1; /* Line 552, Address: 0x102d970 */
  } /* Line 553, Address: 0x102d97c */
  type6_move(pActwk); /* Line 554, Address: 0x102d99c */
} /* Line 555, Address: 0x102d9a8 */




static void type6_move(sprite_status* pActwk) { /* Line 560, Address: 0x102d9c0 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 561, Address: 0x102d9cc */
} /* Line 562, Address: 0x102d9e0 */




static void udblk4_type7(sprite_status* pActwk) { /* Line 567, Address: 0x102d9f0 */
  void(*tbl[2])(sprite_status*) = /* Line 568, Address: 0x102d9fc */
  {
    &type7_init,
    &type7_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 574, Address: 0x102da18 */
  actionsub(pActwk); /* Line 575, Address: 0x102da54 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 576, Address: 0x102da60 */
} /* Line 577, Address: 0x102da74 */




static void type7_coset(sprite_status* pActwk, sprite_status* pNewActwk, unsigned char d0, short d1, unsigned char d2) { /* Line 582, Address: 0x102da90 */
  pNewActwk->actno = 35; /* Line 583, Address: 0x102daa8 */
  pNewActwk->userflag.b.h = 7; /* Line 584, Address: 0x102dab4 */
  pNewActwk->actfree[18] = d0; /* Line 585, Address: 0x102dac0 */
  pNewActwk->actfree[16] = d2; /* Line 586, Address: 0x102dacc */
  pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 587, Address: 0x102dad8 */

  pNewActwk->xposi.w.h = pActwk->xposi.w.h + d1; /* Line 589, Address: 0x102dae8 */
  ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 590, Address: 0x102db18 */
} /* Line 591, Address: 0x102db28 */




static void type7_init(sprite_status* pActwk) { /* Line 596, Address: 0x102db40 */
  sprite_status* pNewActwk;

  pActwk->r_no0 += 2; /* Line 599, Address: 0x102db4c */
  pActwk->actflg |= 4; /* Line 600, Address: 0x102db5c */
  pActwk->sproffset = 17514; /* Line 601, Address: 0x102db6c */
  pActwk->sprpri = 3; /* Line 602, Address: 0x102db78 */
  pActwk->patbase = udblk4pat7; /* Line 603, Address: 0x102db84 */
  ((short*)pActwk)[27] = pActwk->yposi.w.h + 64; /* Line 604, Address: 0x102db94 */
  pActwk->sprhsize = 16; /* Line 605, Address: 0x102dbb8 */
  pActwk->sprvsize = 64; /* Line 606, Address: 0x102dbc4 */

  if (pActwk->actfree[18] == 0) /* Line 608, Address: 0x102dbd0 */
  {

    ((short*)pActwk)[29] = pActwk->xposi.w.h + 48; /* Line 611, Address: 0x102dbe4 */
    pActwk->actfree[16] = 192; /* Line 612, Address: 0x102dc08 */
    if (actwkchk(&pNewActwk) == 0) /* Line 613, Address: 0x102dc14 */
    {
      type7_coset(pActwk, pNewActwk, 1, 32, 224); /* Line 615, Address: 0x102dc28 */
    }
    if (actwkchk(&pNewActwk) == 0) /* Line 617, Address: 0x102dc44 */
    {
      type7_coset(pActwk, pNewActwk, 1, 64, 0); /* Line 619, Address: 0x102dc58 */
    }
    if (actwkchk(&pNewActwk) == 0) /* Line 621, Address: 0x102dc74 */
    {
      type7_coset(pActwk, pNewActwk, 1, 96, 32); /* Line 623, Address: 0x102dc88 */
    }
  }

  type7_move(pActwk); /* Line 627, Address: 0x102dca4 */
} /* Line 628, Address: 0x102dcb0 */




static void type7_move(sprite_status* pActwk) { /* Line 633, Address: 0x102dcc0 */
  sin_move(pActwk, 6, 0); /* Line 634, Address: 0x102dccc */
} /* Line 635, Address: 0x102dce0 */




static void udblk4_type8(sprite_status* pActwk) { /* Line 640, Address: 0x102dcf0 */
  short d0;
  void(*tbl[2])(sprite_status*) = /* Line 642, Address: 0x102dd00 */
  {
    &type8_init,
    &type8_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 648, Address: 0x102dd1c */
  actionsub(pActwk); /* Line 649, Address: 0x102dd58 */

  d0 = ((short*)pActwk)[28]; /* Line 651, Address: 0x102dd64 */
  if (d0) /* Line 652, Address: 0x102dd74 */
  {
    if (actwk[d0].actno != 35) /* Line 654, Address: 0x102dd7c */
    {
      frameout_s0(pActwk); /* Line 656, Address: 0x102ddb0 */
    }
  } /* Line 658, Address: 0x102ddbc */
  else
  {
    frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 661, Address: 0x102ddc4 */
  }
} /* Line 663, Address: 0x102ddd8 */




static void type8_init(sprite_status* pActwk) { /* Line 668, Address: 0x102ddf0 */
  sprite_status* pNewActwk;
  short i;
  short d0;
  unsigned char d1;

  pActwk->r_no0 += 2; /* Line 674, Address: 0x102de08 */
  pActwk->actflg |= 4; /* Line 675, Address: 0x102de18 */
  pActwk->sproffset = 17514; /* Line 676, Address: 0x102de28 */
  pActwk->sprpri = 3; /* Line 677, Address: 0x102de34 */
  pActwk->patbase = udblk4pat8; /* Line 678, Address: 0x102de40 */
  ((short*)pActwk)[27] = pActwk->yposi.w.h - 32; /* Line 679, Address: 0x102de50 */
  pActwk->sprhsize = 32; /* Line 680, Address: 0x102de74 */
  pActwk->sprvsize = 48; /* Line 681, Address: 0x102de80 */
  if (pActwk->actfree[19] == 0) /* Line 682, Address: 0x102de8c */
  {
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 684, Address: 0x102dea0 */
  }

  if (pActwk->actfree[18] == 0) /* Line 687, Address: 0x102deb0 */
  {
    if (actwkchk(&pNewActwk) == 0) /* Line 689, Address: 0x102dec4 */
    {
      pNewActwk->actno = 35; /* Line 691, Address: 0x102ded8 */
      pNewActwk->actfree[18] = 1; /* Line 692, Address: 0x102dee4 */
      pNewActwk->userflag.b.h = 8; /* Line 693, Address: 0x102def0 */
      pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 694, Address: 0x102defc */
      ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 695, Address: 0x102df0c */
      pNewActwk->yposi.w.h = pActwk->yposi.w.h + 160; /* Line 696, Address: 0x102df1c */
      pNewActwk->actfree[16] = pActwk->actfree[16]; /* Line 697, Address: 0x102df40 */
      pNewActwk->actfree[19] = pActwk->actfree[19]; /* Line 698, Address: 0x102df50 */
      if (pActwk->actfree[19] == 0) /* Line 699, Address: 0x102df60 */
      {
        d1 = 1; /* Line 701, Address: 0x102df74 */
        for (i = 0; i < 2; ++i) /* Line 702, Address: 0x102df7c */
        {
          if (actwkchk(&pNewActwk) == 0) /* Line 704, Address: 0x102df88 */
          {
            pNewActwk->actno = 35; /* Line 706, Address: 0x102df9c */
            pNewActwk->userflag.b.h = 8; /* Line 707, Address: 0x102dfa8 */
            pNewActwk->actfree[19] = d1; /* Line 708, Address: 0x102dfb4 */
            pNewActwk->actfree[16] = 128; /* Line 709, Address: 0x102dfbc */
            d0 = -64; /* Line 710, Address: 0x102dfc8 */
            if (d1 != 1) d0 = -d0; /* Line 711, Address: 0x102dfd4 */
            pNewActwk->xposi.w.h = pActwk->xposi.w.h + d0; /* Line 712, Address: 0x102dff0 */
            pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 713, Address: 0x102e01c */
            ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 714, Address: 0x102e02c */
          }
          ++d1; /* Line 716, Address: 0x102e03c */
        } /* Line 717, Address: 0x102e044 */
      }
    }
  }

  type8_move(pActwk); /* Line 722, Address: 0x102e064 */
} /* Line 723, Address: 0x102e070 */




static void type8_move(sprite_status* pActwk) { /* Line 728, Address: 0x102e090 */
  short_union tmp;
  short stk;
  short d0, d1;

  stk = pActwk->yposi.w.h; /* Line 733, Address: 0x102e0a0 */
  sinset(pActwk->actfree[16], &d0, &d1); /* Line 734, Address: 0x102e0b0 */
  d0 = d0 * 2 >> 4; /* Line 735, Address: 0x102e0c8 */

  tmp.b.h = pActwk->actfree[16]; /* Line 737, Address: 0x102e0e8 */
  tmp.b.l = pActwk->actfree[17]; /* Line 738, Address: 0x102e0f4 */
  tmp.w += 128; /* Line 739, Address: 0x102e100 */
  pActwk->actfree[16] = tmp.b.h; /* Line 740, Address: 0x102e10c */
  pActwk->actfree[17] = tmp.b.l; /* Line 741, Address: 0x102e118 */

  pActwk->yposi.w.h = ((short*)pActwk)[27] + d0; /* Line 743, Address: 0x102e124 */
  d0 -= stk; /* Line 744, Address: 0x102e154 */
  d0 <<= 8; /* Line 745, Address: 0x102e160 */
  pActwk->yspeed.w = d0; /* Line 746, Address: 0x102e16c */
  ride_on_chk(pActwk, &actwk[0]); /* Line 747, Address: 0x102e178 */
} /* Line 748, Address: 0x102e18c */




static void udblk4_type9(sprite_status* pActwk) { /* Line 753, Address: 0x102e1a0 */
  short d0;
  void(*tbl[2])(sprite_status*) = /* Line 755, Address: 0x102e1b0 */
  {
    &type9_init,
    &type9_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 761, Address: 0x102e1cc */
  actionsub(pActwk); /* Line 762, Address: 0x102e208 */

  d0 = ((short*)pActwk)[28]; /* Line 764, Address: 0x102e214 */
  if (d0) /* Line 765, Address: 0x102e224 */
  {
    if (actwk[d0].actno == 0) /* Line 767, Address: 0x102e22c */
    {
      frameout_s0(pActwk); /* Line 769, Address: 0x102e25c */
    }
  } /* Line 771, Address: 0x102e268 */
  else
  {
    frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 774, Address: 0x102e270 */
  }
} /* Line 776, Address: 0x102e284 */




static void type9_init(sprite_status* pActwk) { /* Line 781, Address: 0x102e2a0 */
  sprite_status* pNewActwk;
  short d1;
  unsigned char d0;

  pActwk->r_no0 += 2; /* Line 786, Address: 0x102e2b4 */
  pActwk->actflg |= 4; /* Line 787, Address: 0x102e2c4 */
  pActwk->sproffset = 17514; /* Line 788, Address: 0x102e2d4 */
  pActwk->sprpri = 3; /* Line 789, Address: 0x102e2e0 */
  pActwk->patbase = udblk4pat9; /* Line 790, Address: 0x102e2ec */
  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 791, Address: 0x102e2fc */
  ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 792, Address: 0x102e30c */
  pActwk->sprhsize = 16; /* Line 793, Address: 0x102e31c */
  pActwk->sprvsize = 32; /* Line 794, Address: 0x102e328 */

  if (pActwk->actfree[18] == 0) /* Line 796, Address: 0x102e334 */
  {
    if (actwkchk(&pNewActwk) == 0) /* Line 798, Address: 0x102e348 */
    {
      pNewActwk->actno = 35; /* Line 800, Address: 0x102e35c */
      pNewActwk->actfree[18] = 1; /* Line 801, Address: 0x102e368 */
      pNewActwk->userflag.b.h = 9; /* Line 802, Address: 0x102e374 */
      pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 803, Address: 0x102e380 */
      d1 = 128; /* Line 804, Address: 0x102e390 */
      d0 = pActwk->actfree[16]; /* Line 805, Address: 0x102e39c */
      if (pActwk->actfree[19] & 128) /* Line 806, Address: 0x102e3a8 */
      {
        d1 = 160; /* Line 808, Address: 0x102e3c0 */
        d0 -= 128; /* Line 809, Address: 0x102e3cc */
      }
      pNewActwk->actfree[16] = d0; /* Line 811, Address: 0x102e3d4 */
      pNewActwk->yposi.w.h = pActwk->yposi.w.h + d1; /* Line 812, Address: 0x102e3dc */
    }
  }
} /* Line 815, Address: 0x102e408 */




static void type9_move(sprite_status* pActwk) { /* Line 820, Address: 0x102e420 */
  sin_move(pActwk, 5, 0); /* Line 821, Address: 0x102e42c */
} /* Line 822, Address: 0x102e440 */




static void udblk4_typeA(sprite_status* pActwk) { /* Line 827, Address: 0x102e450 */
  short d0;
  void(*tbl[2])(sprite_status*) = /* Line 829, Address: 0x102e460 */
  {
    &typeA_init,
    &typeA_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 835, Address: 0x102e47c */
  actionsub(pActwk); /* Line 836, Address: 0x102e4b8 */

  d0 = ((short*)pActwk)[28]; /* Line 838, Address: 0x102e4c4 */
  if (d0) /* Line 839, Address: 0x102e4d4 */
  {
    if (actwk[d0].actno == 0) /* Line 841, Address: 0x102e4dc */
    {
      frameout_s0(pActwk); /* Line 843, Address: 0x102e50c */
    }
  } /* Line 845, Address: 0x102e518 */
  else
  {
    frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 848, Address: 0x102e520 */
  }
} /* Line 850, Address: 0x102e534 */




static void typeA_init(sprite_status* pActwk) { /* Line 855, Address: 0x102e550 */
  sprite_status* pNewActwk;
  short i;
  unsigned char d1;
  kakudo_xofst tbl[7] = /* Line 859, Address: 0x102e564 */
  {
    {   0,   0 },
    { 224, 224 },
    { 192, 192 },
    { 160, 160 },
    { 224,  32 },
    { 192,  64 },
    { 160,  96 }
  };

  pActwk->r_no0 += 2; /* Line 870, Address: 0x102e598 */
  pActwk->actflg |= 4; /* Line 871, Address: 0x102e5a8 */
  pActwk->sproffset = 17514; /* Line 872, Address: 0x102e5b8 */
  pActwk->sprpri = 3; /* Line 873, Address: 0x102e5c4 */
  pActwk->patbase = udblk4patA; /* Line 874, Address: 0x102e5d0 */
  ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 875, Address: 0x102e5e0 */
  pActwk->sprhsize = 16; /* Line 876, Address: 0x102e5f0 */
  pActwk->sprvsize = 16; /* Line 877, Address: 0x102e5fc */

  if (pActwk->actfree[18] == 0) /* Line 879, Address: 0x102e608 */
  {
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 881, Address: 0x102e61c */
    d1 = 1; /* Line 882, Address: 0x102e62c */
    for (i = 0; i < 6; ++i) /* Line 883, Address: 0x102e634 */
    {
      if (actwkchk(&pNewActwk) == 0) /* Line 885, Address: 0x102e640 */
      {
        pNewActwk->actno = 35; /* Line 887, Address: 0x102e654 */
        pNewActwk->userflag.b.h = 10; /* Line 888, Address: 0x102e660 */
        pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 889, Address: 0x102e66c */
        ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 890, Address: 0x102e67c */
        pNewActwk->actfree[18] = d1; /* Line 891, Address: 0x102e68c */
        pNewActwk->actfree[16] = tbl[d1].kakudo; /* Line 892, Address: 0x102e694 */

        pNewActwk->xposi.w.h = pActwk->xposi.w.h + tbl[d1].xofst; /* Line 894, Address: 0x102e6ac */
      }
      ++d1; /* Line 896, Address: 0x102e6f0 */
    } /* Line 897, Address: 0x102e6f8 */
  }
  typeA_move(pActwk); /* Line 899, Address: 0x102e718 */
} /* Line 900, Address: 0x102e724 */




static void typeA_move(sprite_status* pActwk) { /* Line 905, Address: 0x102e740 */
  sin_move(pActwk, 5, 4); /* Line 906, Address: 0x102e74c */
} /* Line 907, Address: 0x102e760 */




static void udblk4_typeB(sprite_status* pActwk) { /* Line 912, Address: 0x102e770 */
  short d0;
  void(*tbl[2])(sprite_status*) = /* Line 914, Address: 0x102e780 */
  {
    &typeB_init,
    &typeB_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 920, Address: 0x102e79c */
  actionsub(pActwk); /* Line 921, Address: 0x102e7d8 */

  d0 = ((short*)pActwk)[28]; /* Line 923, Address: 0x102e7e4 */
  if (d0) /* Line 924, Address: 0x102e7f4 */
  {
    if (actwk[d0].actno == 0) /* Line 926, Address: 0x102e7fc */
    {
      frameout_s0(pActwk); /* Line 928, Address: 0x102e82c */
    }
  } /* Line 930, Address: 0x102e838 */
  else
  {
    frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 933, Address: 0x102e840 */
  }
} /* Line 935, Address: 0x102e854 */




static void typeB_init(sprite_status* pActwk) { /* Line 940, Address: 0x102e870 */
  sprite_status* pNewActwk;
  xofs_yofs_yspd* a1;
  short i;
  unsigned char d1;
  xofs_yofs_yspd tbl[6] = /* Line 945, Address: 0x102e888 */
  {
    {    0,    0,  128 },
    {    0, -128,  128 },
    {  -80,   32, -256 },
    {  -80,  -96, -256 },
    {   80,   32, -256 },
    {   80,  -96, -256 }
  };









  pActwk->r_no0 += 2; /* Line 963, Address: 0x102e8bc */
  pActwk->actflg |= 4; /* Line 964, Address: 0x102e8cc */
  pActwk->sproffset = 17514; /* Line 965, Address: 0x102e8dc */
  pActwk->sprpri = 3; /* Line 966, Address: 0x102e8e8 */
  pActwk->patbase = udblk4pat9; /* Line 967, Address: 0x102e8f4 */
  pActwk->sprhsize = 16; /* Line 968, Address: 0x102e904 */
  pActwk->sprvsize = 32; /* Line 969, Address: 0x102e910 */
  pActwk->patno = 0; /* Line 970, Address: 0x102e91c */

  if (pActwk->actfree[18] == 0) /* Line 972, Address: 0x102e924 */
  {
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 974, Address: 0x102e938 */
    ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 975, Address: 0x102e948 */
    d1 = 1; /* Line 976, Address: 0x102e958 */
    for (i = 0; i < 5; ++i) /* Line 977, Address: 0x102e960 */
    {
      if (actwkchk(&pNewActwk) == 0) /* Line 979, Address: 0x102e96c */
      {
        pNewActwk->actno = 35; /* Line 981, Address: 0x102e980 */
        pNewActwk->userflag.b.h = 11; /* Line 982, Address: 0x102e98c */
        pNewActwk->actfree[18] = d1; /* Line 983, Address: 0x102e998 */
        ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 984, Address: 0x102e9a0 */
        ((short*)pNewActwk)[27] = ((short*)pActwk)[27]; /* Line 985, Address: 0x102e9b0 */
      }
      ++d1; /* Line 987, Address: 0x102e9c0 */
    } /* Line 988, Address: 0x102e9c8 */
  }
  a1 = &tbl[pActwk->actfree[18]]; /* Line 990, Address: 0x102e9e8 */
  pActwk->xposi.w.h = ((short*)pActwk)[29] + a1->xofs; /* Line 991, Address: 0x102ea00 */
  pActwk->yposi.w.h = ((short*)pActwk)[27] + a1->yofs; /* Line 992, Address: 0x102ea38 */
  pActwk->yspeed.w += a1->yspd; /* Line 993, Address: 0x102ea70 */
} /* Line 994, Address: 0x102ea84 */




static void typeB_move(sprite_status* pActwk) { /* Line 999, Address: 0x102eaa0 */
  short d0;

  pActwk->yposi.l += pActwk->yspeed.w << 8; /* Line 1002, Address: 0x102eaac */


  if (pActwk->yspeed.w < 0) /* Line 1005, Address: 0x102ead4 */
  {
    d0 = ((short*)pActwk)[27]; /* Line 1007, Address: 0x102eaec */
    if (d0 < pActwk->yposi.w.h) return; /* Line 1008, Address: 0x102eafc */
    d0 -= pActwk->yposi.w.h; /* Line 1009, Address: 0x102eb20 */
    if (d0 < 128) return; /* Line 1010, Address: 0x102eb34 */
    pActwk->yposi.w.h = ((short*)pActwk)[27] + 128; /* Line 1011, Address: 0x102eb48 */
  } /* Line 1012, Address: 0x102eb6c */
  else
  {
    d0 = pActwk->xposi.w.h; /* Line 1015, Address: 0x102eb74 */
    if (d0 < ((short*)pActwk)[27]) return; /* Line 1016, Address: 0x102eb84 */
    d0 -= ((short*)pActwk)[27]; /* Line 1017, Address: 0x102eba8 */
    if (d0 < 128) return; /* Line 1018, Address: 0x102ebbc */
    pActwk->yposi.w.h = ((short*)pActwk)[27] - 128; /* Line 1019, Address: 0x102ebd0 */
  }
} /* Line 1021, Address: 0x102ebf4 */
