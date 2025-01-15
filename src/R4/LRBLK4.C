#include "..\EQU.H"
#include "LRBLK4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\RIDECHK.H"

#if defined(R41B)
  #define SPRITE_LRBLK4_BASE 497
#elif defined(R41C)
  #define SPRITE_LRBLK4_BASE 485
#elif defined(R42A)
  #define SPRITE_LRBLK4_BASE 504
#elif defined(R42B)
  #define SPRITE_LRBLK4_BASE 519
#else
  #define SPRITE_LRBLK4_BASE 491
#endif

typedef struct {
  unsigned char cnt;
  unsigned char dummy;
  short speed;
}
move_data;

static void lrblk4_foutchk(sprite_status* pActwk);
static void lrblk4_type1(sprite_status* pActwk);
static void type1_init(sprite_status* pActwk);
static void type1_move(sprite_status* pActwk);
static void lrblk4_type2(sprite_status* pActwk);
static void type2_init(sprite_status* pActwk);
static void type2_move(sprite_status* pActwk);
static void lrblk4_type3(sprite_status* pActwk);
static void type3_init(sprite_status* pActwk);
static void type3_move(sprite_status* pActwk);
static void lrblk4_type4(sprite_status* pActwk);
static void type4_init(sprite_status* pActwk);
static void type4_move(sprite_status* pActwk);
static void lrblk4_type5(sprite_status* pActwk);
static void type5_init(sprite_status* pActwk);
static void type5_move(sprite_status* pActwk);
static void type5_end(sprite_status* pActwk);
static void lrblk4_type6(sprite_status* pActwk);
static void type6_init(sprite_status* pActwk);
static void type6_move(sprite_status* pActwk);
static void lrblk4_type8(sprite_status* pActwk);
static void type8_init(sprite_status* pActwk);
static void type8_move(sprite_status* pActwk);

static sprite_pattern pat10 =
{
  1,
  { { -64, -16, 0, SPRITE_LRBLK4_BASE } }
};
static sprite_pattern pat11 =
{
  1,
  { { -48, -16, 0, SPRITE_LRBLK4_BASE + 1 } }
};
static sprite_pattern pat20 =
{
  1,
  { { -32, -16, 0, SPRITE_LRBLK4_BASE + 2 } }
};
static sprite_pattern pat30 =
{
  1,
  { { -32, -32, 0, SPRITE_LRBLK4_BASE + 3 } }
};
static sprite_pattern pat50 =
{
  1,
  { { -32, -32, 0, SPRITE_LRBLK4_BASE + 4 } }
};
static sprite_pattern pat60 =
{
  1,
  { { -16, -16, 0, SPRITE_LRBLK4_BASE + 5 } }
};
static sprite_pattern pat61 =
{
  1,
  { { -32, -16, 0, SPRITE_LRBLK4_BASE + 6 } }
};
static sprite_pattern pat62 =
{
  1,
  { { -48, -16, 0, SPRITE_LRBLK4_BASE + 7 } }
};
static sprite_pattern pat63 =
{
  1,
  { { -64, -16, 0, SPRITE_LRBLK4_BASE + 8 } }
};
sprite_pattern* lrblk4pat1[2] =
{
  &pat10,
  &pat11
};
sprite_pattern* lrblk4pat2[1] = { &pat20 };
sprite_pattern* lrblk4pat3[1] = { &pat30 };
sprite_pattern* lrblk4pat5[1] = { &pat50 };
sprite_pattern* lrblk4pat6[4] =
{
  &pat60,
  &pat61,
  &pat62,
  &pat63
};
sprite_pattern* lrblk4pat8[2] =
{
  &pat10,
  &pat11
};














void lrblk4(sprite_status* pActwk) { /* Line 130, Address: 0x1021a90 */
  void(*tbl[9])(sprite_status*) = /* Line 131, Address: 0x1021a9c */
  {
    &lrblk4_type1,
    &lrblk4_type1,
    &lrblk4_type2,
    &lrblk4_type3,
    &lrblk4_type4,
    &lrblk4_type5,
    &lrblk4_type6,
    &lrblk4_type1,
    &lrblk4_type8
  };









  tbl[pActwk->userflag.b.h](pActwk); /* Line 152, Address: 0x1021ac8 */
} /* Line 153, Address: 0x1021af0 */




static void lrblk4_foutchk(sprite_status* pActwk) { /* Line 158, Address: 0x1021b00 */
  short d0, d1;

  d0 = ((short*)pActwk)[29]; /* Line 161, Address: 0x1021b14 */
  d0 &= -128; /* Line 162, Address: 0x1021b24 */
  d1 = scra_h_posit.w.h; /* Line 163, Address: 0x1021b34 */
  d1 -= 128; /* Line 164, Address: 0x1021b44 */
  d1 &= -128; /* Line 165, Address: 0x1021b50 */
  d0 -= d1; /* Line 166, Address: 0x1021b60 */
  if ((unsigned short)d0 > 640) /* Line 167, Address: 0x1021b6c */
  {
    d0 = (unsigned short)pActwk->cdsts; /* Line 169, Address: 0x1021b80 */
    if (d0) /* Line 170, Address: 0x1021b9c */
    {
      d0 *= 3; /* Line 172, Address: 0x1021ba4 */
      d0 += (unsigned short)time_flag; /* Line 173, Address: 0x1021bb4 */
      flagwork[d0] &= 127; /* Line 174, Address: 0x1021bd4 */
    }
    frameout(pActwk); /* Line 176, Address: 0x1021bf4 */
  }
} /* Line 178, Address: 0x1021c00 */




static void lrblk4_type1(sprite_status* pActwk) { /* Line 183, Address: 0x1021c20 */
  void(*tbl[2])(sprite_status*) = /* Line 184, Address: 0x1021c2c */
  {
    &type1_init,
    &type1_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 190, Address: 0x1021c48 */
  actionsub(pActwk); /* Line 191, Address: 0x1021c84 */
  lrblk4_foutchk(pActwk); /* Line 192, Address: 0x1021c90 */
} /* Line 193, Address: 0x1021c9c */




static void type1_init(sprite_status* pActwk) { /* Line 198, Address: 0x1021cb0 */
  sprite_status* pNewActwk;
  short i;
  unsigned short d0;
  unsigned char d1;

  pActwk->r_no0 += 2; /* Line 204, Address: 0x1021cc8 */
  pActwk->actflg |= 4; /* Line 205, Address: 0x1021cd8 */
  pActwk->sproffset = 17514; /* Line 206, Address: 0x1021ce8 */
  pActwk->sprpri = 3; /* Line 207, Address: 0x1021cf4 */
  pActwk->patbase = lrblk4pat1; /* Line 208, Address: 0x1021d00 */
  ((short*)pActwk)[27] = pActwk->xposi.w.h; /* Line 209, Address: 0x1021d10 */
  pActwk->sprhsize = 48; /* Line 210, Address: 0x1021d20 */
  pActwk->sprvsize = 16; /* Line 211, Address: 0x1021d2c */
  pActwk->patno = 1; /* Line 212, Address: 0x1021d38 */

  if (pActwk->actfree[18]) /* Line 214, Address: 0x1021d44 */
  {
    type1_move(pActwk); /* Line 216, Address: 0x1021d54 */
    return; /* Line 217, Address: 0x1021d60 */
  }

  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 220, Address: 0x1021d68 */
  if (pActwk->actfree[19] == 0) /* Line 221, Address: 0x1021d78 */
  {
    d1 = 1; /* Line 223, Address: 0x1021d8c */
    for (i = 0; i <= 4; ++i) /* Line 224, Address: 0x1021d94 */
    {
      if (actwkchk(&pNewActwk) == 0) /* Line 226, Address: 0x1021da0 */
      {
        pNewActwk->actno = 36; /* Line 228, Address: 0x1021db4 */
        pNewActwk->userflag.b.h = 1; /* Line 229, Address: 0x1021dc0 */
        pNewActwk->actfree[19] = d1; /* Line 230, Address: 0x1021dcc */
        pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 231, Address: 0x1021dd4 */

        pNewActwk->actfree[16] = (char)(d1 * 32) + 16; /* Line 233, Address: 0x1021de4 */
        d0 = d1; /* Line 234, Address: 0x1021e0c */
        d0 *= 96; /* Line 235, Address: 0x1021e14 */
        d0 += pActwk->yposi.w.h; /* Line 236, Address: 0x1021e24 */
        pNewActwk->yposi.w.h = d0; /* Line 237, Address: 0x1021e38 */
      }

      ++d1; /* Line 240, Address: 0x1021e40 */
    } /* Line 241, Address: 0x1021e48 */
  }
  if (actwkchk(&pNewActwk) == 0) /* Line 243, Address: 0x1021e68 */
  {
    pNewActwk->actno = 36; /* Line 245, Address: 0x1021e7c */
    pNewActwk->userflag.b.h = 1; /* Line 246, Address: 0x1021e88 */
    pNewActwk->actfree[18] = 1; /* Line 247, Address: 0x1021e94 */

    ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 249, Address: 0x1021ea0 */
    pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 250, Address: 0x1021eb0 */
    pNewActwk->xposi.w.h = pActwk->xposi.w.h + 224; /* Line 251, Address: 0x1021ec0 */
    pNewActwk->actfree[16] = pActwk->actfree[16]; /* Line 252, Address: 0x1021ee4 */
  }
  type1_move(pActwk); /* Line 254, Address: 0x1021ef4 */
} /* Line 255, Address: 0x1021f00 */




static void type1_move(sprite_status* pActwk) { /* Line 260, Address: 0x1021f20 */
  short d0, d1, stk;

  stk = pActwk->xposi.w.h; /* Line 263, Address: 0x1021f30 */
  sinset(pActwk->actfree[16], &d0, &d1); /* Line 264, Address: 0x1021f40 */
  d0 >>= 3; /* Line 265, Address: 0x1021f58 */
  ++pActwk->actfree[16]; /* Line 266, Address: 0x1021f64 */
  d0 += ((short*)pActwk)[27]; /* Line 267, Address: 0x1021f74 */
  pActwk->xposi.w.h = d0; /* Line 268, Address: 0x1021f88 */
  d1 = stk; /* Line 269, Address: 0x1021f94 */
  d0 -= d1; /* Line 270, Address: 0x1021f98 */
  d0 <<= 8; /* Line 271, Address: 0x1021fa8 */
  pActwk->xspeed.w = d0; /* Line 272, Address: 0x1021fb4 */
  hitchk(pActwk, &actwk[0]); /* Line 273, Address: 0x1021fc0 */
} /* Line 274, Address: 0x1021fd4 */




static void lrblk4_type2(sprite_status* pActwk) { /* Line 279, Address: 0x1021ff0 */
  void(*tbl[2])(sprite_status*) = /* Line 280, Address: 0x1021ffc */
  {
    &type2_init,
    &type2_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 286, Address: 0x1022018 */
  actionsub(pActwk); /* Line 287, Address: 0x1022054 */
  lrblk4_foutchk(pActwk); /* Line 288, Address: 0x1022060 */
} /* Line 289, Address: 0x102206c */




static void type2_init(sprite_status* pActwk) { /* Line 294, Address: 0x1022080 */
  sprite_status* pNewActwk;

  pActwk->r_no0 += 2; /* Line 297, Address: 0x102208c */
  pActwk->actflg |= 4; /* Line 298, Address: 0x102209c */
  pActwk->sproffset = 17514; /* Line 299, Address: 0x10220ac */
  pActwk->sprpri = 3; /* Line 300, Address: 0x10220b8 */
  pActwk->patbase = lrblk4pat2; /* Line 301, Address: 0x10220c4 */
  pActwk->sprhsize = 32; /* Line 302, Address: 0x10220d4 */
  pActwk->sprvsize = 16; /* Line 303, Address: 0x10220e0 */

  if (pActwk->actfree[18]) /* Line 305, Address: 0x10220ec */
  {
    type2_move(pActwk); /* Line 307, Address: 0x10220fc */
    return; /* Line 308, Address: 0x1022108 */
  }

  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 311, Address: 0x1022110 */

  ((short*)pActwk)[27] = pActwk->xposi.w.h - 32; /* Line 313, Address: 0x1022120 */

  if (actwkchk(&pNewActwk) == 0) /* Line 315, Address: 0x1022144 */
  {
    pNewActwk->actno = 36; /* Line 317, Address: 0x1022158 */
    pNewActwk->userflag.b.h = 2; /* Line 318, Address: 0x1022164 */
    pNewActwk->actfree[18] = 1; /* Line 319, Address: 0x1022170 */

    ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 321, Address: 0x102217c */
    pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 322, Address: 0x102218c */
    pNewActwk->xposi.w.h = pActwk->xposi.w.h + 64; /* Line 323, Address: 0x102219c */
    ((short*)pNewActwk)[27] = pNewActwk->xposi.w.h + 32; /* Line 324, Address: 0x10221c0 */
    pNewActwk->actfree[16] = pActwk->actfree[16] - 128; /* Line 325, Address: 0x10221e4 */
  }
  type2_move(pActwk); /* Line 327, Address: 0x1022200 */
} /* Line 328, Address: 0x102220c */




static void type2_move(sprite_status* pActwk) { /* Line 333, Address: 0x1022220 */
  short d0, d1, stk;

  stk = pActwk->xposi.w.h; /* Line 336, Address: 0x1022230 */
  sinset(pActwk->actfree[16], &d0, &d1); /* Line 337, Address: 0x1022240 */
  d0 >>= 3; /* Line 338, Address: 0x1022258 */
  ++pActwk->actfree[16]; /* Line 339, Address: 0x1022264 */
  d0 += ((short*)pActwk)[27]; /* Line 340, Address: 0x1022274 */
  pActwk->xposi.w.h = d0; /* Line 341, Address: 0x1022288 */
  d1 = stk; /* Line 342, Address: 0x1022294 */
  d0 -= d1; /* Line 343, Address: 0x1022298 */
  d0 <<= 8; /* Line 344, Address: 0x10222a8 */
  pActwk->xspeed.w = d0; /* Line 345, Address: 0x10222b4 */
  hitchk(pActwk, &actwk[0]); /* Line 346, Address: 0x10222c0 */
} /* Line 347, Address: 0x10222d4 */




static void lrblk4_type3(sprite_status* pActwk) { /* Line 352, Address: 0x10222f0 */
  void(*tbl[2])(sprite_status*) = /* Line 353, Address: 0x10222fc */
  {
    &type3_init,
    &type3_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 359, Address: 0x1022318 */
  actionsub(pActwk); /* Line 360, Address: 0x1022354 */
  lrblk4_foutchk(pActwk); /* Line 361, Address: 0x1022360 */
} /* Line 362, Address: 0x102236c */




static void type3_init(sprite_status* pActwk) { /* Line 367, Address: 0x1022380 */
  sprite_status* pNewActwk;
  short* a2;
  short i;
  unsigned char d0, d1;
  short tbl[18] = /* Line 372, Address: 0x102239c */
  {
       0,    0, -128,
    -144,    0, -128,
     144,    0, -128,
       0,   64,  128,
    -144,   64,  128,
     144,   64,  128
  };

  pActwk->r_no0 += 2; /* Line 382, Address: 0x10223d0 */
  pActwk->actflg |= 4; /* Line 383, Address: 0x10223e0 */
  pActwk->sproffset = 17514; /* Line 384, Address: 0x10223f0 */
  pActwk->sprpri = 3; /* Line 385, Address: 0x10223fc */
  pActwk->patbase = lrblk4pat3; /* Line 386, Address: 0x1022408 */
  pActwk->sprhsize = 32; /* Line 387, Address: 0x1022418 */
  pActwk->sprvsize = 32; /* Line 388, Address: 0x1022424 */

  if (pActwk->actfree[18] == 0) /* Line 390, Address: 0x1022430 */
  {
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 392, Address: 0x1022444 */
    d1 = 1; /* Line 393, Address: 0x1022454 */
    for (i = 0; i <= 4; ++i) /* Line 394, Address: 0x102245c */
    {
      if (actwkchk(&pNewActwk) == 0) /* Line 396, Address: 0x1022468 */
      {
        pNewActwk->actno = 36; /* Line 398, Address: 0x102247c */
        pNewActwk->userflag.b.h = 3; /* Line 399, Address: 0x1022488 */
        pNewActwk->actfree[18] = d1; /* Line 400, Address: 0x1022494 */
        ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 401, Address: 0x102249c */
        pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 402, Address: 0x10224ac */
        pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 403, Address: 0x10224bc */
      }
      ++d1; /* Line 405, Address: 0x10224cc */
    } /* Line 406, Address: 0x10224d4 */
  }
  d0 = pActwk->actfree[18] * 6; /* Line 408, Address: 0x10224f4 */
  a2 = &tbl[d0 / 2]; /* Line 409, Address: 0x1022514 */
  pActwk->xposi.w.h += *a2++; /* Line 410, Address: 0x102253c */
  pActwk->yposi.w.h += *a2++; /* Line 411, Address: 0x1022558 */
  pActwk->xspeed.w = *a2++; /* Line 412, Address: 0x1022574 */
} /* Line 413, Address: 0x1022588 */




static void type3_move(sprite_status* pActwk) { /* Line 418, Address: 0x10225b0 */
  sprite_status* pPlayerwk;
  int ld0;
  short d0;

  ld0 = pActwk->xspeed.w; /* Line 423, Address: 0x10225c8 */
  ld0 <<= 8; /* Line 424, Address: 0x10225d8 */
  pActwk->xposi.l += ld0; /* Line 425, Address: 0x10225dc */


  if (pActwk->xspeed.w < 0) /* Line 428, Address: 0x10225ec */
  {
    d0 = ((short*)pActwk)[29]; /* Line 430, Address: 0x1022604 */
    if ((unsigned short)d0 >= (unsigned short)pActwk->xposi.w.h) /* Line 431, Address: 0x1022614 */
    {
      d0 -= pActwk->xposi.w.h; /* Line 433, Address: 0x1022638 */
      if ((unsigned short)d0 >= 224) /* Line 434, Address: 0x102264c */
      {
        d0 = ((short*)pActwk)[29]; /* Line 436, Address: 0x1022660 */
        d0 += 224; /* Line 437, Address: 0x1022670 */
        pActwk->xposi.w.h = d0; /* Line 438, Address: 0x102267c */
      }
    }
  } /* Line 441, Address: 0x1022684 */
  else
  {
    d0 = pActwk->xposi.w.h; /* Line 444, Address: 0x102268c */
    if ((unsigned short)d0 >= (unsigned short)((short*)pActwk)[29]) /* Line 445, Address: 0x102269c */
    {
      d0 -= ((short*)pActwk)[29]; /* Line 447, Address: 0x10226c0 */
      if ((unsigned short)d0 >= 224) /* Line 448, Address: 0x10226d4 */
      {
        d0 = ((short*)pActwk)[29]; /* Line 450, Address: 0x10226e8 */
        d0 -= 224; /* Line 451, Address: 0x10226f8 */
        pActwk->xposi.w.h = d0; /* Line 452, Address: 0x1022704 */
      }
    }
  }

  if (pActwk->actflg & 128) /* Line 457, Address: 0x102270c */
  {
    pPlayerwk = &actwk[0]; /* Line 459, Address: 0x1022724 */
    d0 = pPlayerwk->yposi.w.h; /* Line 460, Address: 0x102272c */
    if ((unsigned short)d0 < (unsigned short)pActwk->yposi.w.h) /* Line 461, Address: 0x1022738 */
    {
      d0 -= pActwk->yposi.w.h; /* Line 463, Address: 0x102275c */
      d0 *= -1; /* Line 464, Address: 0x1022770 */
    } /* Line 465, Address: 0x102277c */
    else
    {
      d0 -= pActwk->yposi.w.h; /* Line 468, Address: 0x1022784 */
    }
    if ((unsigned short)d0 < 64) /* Line 470, Address: 0x1022798 */
    {
      hitchk(pActwk, pPlayerwk); /* Line 472, Address: 0x10227ac */
    }
  }
} /* Line 475, Address: 0x10227bc */




static void lrblk4_type4(sprite_status* pActwk) { /* Line 480, Address: 0x10227e0 */
  void(*tbl[2])(sprite_status*) = /* Line 481, Address: 0x10227ec */
  {
    &type4_init,
    &type4_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 487, Address: 0x1022808 */
  actionsub(pActwk); /* Line 488, Address: 0x1022844 */
  lrblk4_foutchk(pActwk); /* Line 489, Address: 0x1022850 */
} /* Line 490, Address: 0x102285c */




static void type4_init(sprite_status* pActwk) { /* Line 495, Address: 0x1022870 */
  sprite_status* pNewActwk;

  pActwk->r_no0 += 2; /* Line 498, Address: 0x102287c */
  pActwk->actflg |= 4; /* Line 499, Address: 0x102288c */
  pActwk->sproffset = 17514; /* Line 500, Address: 0x102289c */
  pActwk->sprpri = 3; /* Line 501, Address: 0x10228a8 */

  pActwk->sprhsize = 64; /* Line 503, Address: 0x10228b4 */
  pActwk->sprvsize = 64; /* Line 504, Address: 0x10228c0 */
  if (pActwk->actfree[19]) /* Line 505, Address: 0x10228cc */
  {
    pActwk->patbase = lrblk4pat8; /* Line 507, Address: 0x10228dc */
    pActwk->sprvsize = 16; /* Line 508, Address: 0x10228ec */
  }

  if (pActwk->actfree[18] == 0) /* Line 511, Address: 0x10228f8 */
  {
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 513, Address: 0x102290c */
    if (actwkchk(&pNewActwk) == 0) /* Line 514, Address: 0x102291c */
    {
      pNewActwk->actno = 36; /* Line 516, Address: 0x1022930 */
      pNewActwk->userflag.b.h = 4; /* Line 517, Address: 0x102293c */
      pNewActwk->actfree[18] = 1; /* Line 518, Address: 0x1022948 */
      pNewActwk->actfree[19] = pActwk->actfree[19]; /* Line 519, Address: 0x1022954 */
      ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 520, Address: 0x1022964 */

      pNewActwk->xposi.w.h = ((short*)pActwk)[29] + 128; /* Line 522, Address: 0x1022974 */
      pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 523, Address: 0x1022998 */

      pActwk->xposi.w.h = ((short*)pActwk)[29] - 128; /* Line 525, Address: 0x10229a8 */
    }
  }
  pActwk->xspeed.w = -512; /* Line 528, Address: 0x10229cc */
} /* Line 529, Address: 0x10229d8 */




static void type4_move(sprite_status* pActwk) { /* Line 534, Address: 0x10229f0 */
  short d0;

  pActwk->xposi.l += pActwk->xspeed.w << 8; /* Line 537, Address: 0x1022a00 */
  hitchk(pActwk, &actwk[0]); /* Line 538, Address: 0x1022a24 */
  d0 = ((short*)pActwk)[29]; /* Line 539, Address: 0x1022a38 */
  if (d0 >= pActwk->xposi.w.h) /* Line 540, Address: 0x1022a48 */
  {
    d0 -= pActwk->xposi.w.h; /* Line 542, Address: 0x1022a6c */
    if (d0 == 256) /* Line 543, Address: 0x1022a80 */
    {
      pActwk->xposi.w.h = ((short*)pActwk)[29] + 256; /* Line 545, Address: 0x1022a94 */
    }
  }
} /* Line 548, Address: 0x1022ab8 */




static void lrblk4_type5(sprite_status* pActwk) { /* Line 553, Address: 0x1022ad0 */
  void(*tbl[3])(sprite_status*) = /* Line 554, Address: 0x1022adc */
  {
    &type5_init,
    &type5_move,
    &type5_end
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 561, Address: 0x1022b00 */
  actionsub(pActwk); /* Line 562, Address: 0x1022b3c */
  lrblk4_foutchk(pActwk); /* Line 563, Address: 0x1022b48 */
} /* Line 564, Address: 0x1022b54 */




static void type5_init(sprite_status* pActwk) { /* Line 569, Address: 0x1022b70 */
  sprite_status* pNewActwk;
  unsigned char* a1;
  short i;
  unsigned short d0;
  unsigned char d1;
  unsigned char tbl[14] = /* Line 575, Address: 0x1022b8c */
  {
      0,   0,
     64,   1,
    128,   2,
    192,   3,
    128,   4,
     64,   5,
      0,   0
  };

  pActwk->r_no0 += 2; /* Line 586, Address: 0x1022bc0 */
  pActwk->actflg |= 4; /* Line 587, Address: 0x1022bd0 */
  pActwk->sproffset = 17514; /* Line 588, Address: 0x1022be0 */
  pActwk->sprpri = 3; /* Line 589, Address: 0x1022bec */
  pActwk->patbase = lrblk4pat5; /* Line 590, Address: 0x1022bf8 */
  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 591, Address: 0x1022c08 */
  pActwk->sprhsize = 32; /* Line 592, Address: 0x1022c18 */
  pActwk->sprvsize = 32; /* Line 593, Address: 0x1022c24 */

  if (pActwk->actfree[18] == 0) /* Line 595, Address: 0x1022c30 */
  {
    d1 = 1; /* Line 597, Address: 0x1022c44 */
    for (i = 0; i <= 3; ++i) /* Line 598, Address: 0x1022c4c */
    {
      if (actwkchk(&pNewActwk) == 0) /* Line 600, Address: 0x1022c58 */
      {
        pNewActwk->actno = 36; /* Line 602, Address: 0x1022c6c */
        pNewActwk->userflag.b.h = 5; /* Line 603, Address: 0x1022c78 */
        pNewActwk->actfree[18] = d1; /* Line 604, Address: 0x1022c84 */
        pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 605, Address: 0x1022c8c */
        d0 = d1; /* Line 606, Address: 0x1022c9c */
        d0 *= 64; /* Line 607, Address: 0x1022ca4 */
        pNewActwk->yposi.w.h = pActwk->yposi.w.h + (short)d0; /* Line 608, Address: 0x1022cac */
      }
      ++d1; /* Line 610, Address: 0x1022ce0 */
    } /* Line 611, Address: 0x1022ce8 */
  }
  a1 = &tbl[pActwk->actfree[18] * 2]; /* Line 613, Address: 0x1022d08 */
  pActwk->xposi.w.h += (unsigned short)*a1++; /* Line 614, Address: 0x1022d20 */
  pActwk->actfree[17] = *a1++; /* Line 615, Address: 0x1022d48 */
} /* Line 616, Address: 0x1022d5c */




static void type5_move(sprite_status* pActwk) { /* Line 621, Address: 0x1022d80 */
  move_data* a1;
  short d0;







  move_data type5_mvtbl[6] = /* Line 631, Address: 0x1022d94 */
  {
    { 128, 0,  128 },
    { 128, 0,  128 },
    { 128, 0,  128 },
    { 128, 0, -128 },
    { 128, 0, -128 },
    { 128, 0, -128 }
  };







label1:
  if (pActwk->actfree[16] == 0) /* Line 648, Address: 0x1022dc8 */
  {
    a1 = &type5_mvtbl[pActwk->actfree[17]]; /* Line 650, Address: 0x1022ddc */
    pActwk->actfree[16] = a1->cnt; /* Line 651, Address: 0x1022df4 */
    ((short*)pActwk)[26] = a1->speed; /* Line 652, Address: 0x1022e00 */
  } /* Line 653, Address: 0x1022e0c */
  else
  {
    d0 = ((short*)pActwk)[26]; /* Line 656, Address: 0x1022e14 */
    pActwk->xspeed.w = d0; /* Line 657, Address: 0x1022e24 */
    pActwk->xposi.l += d0 << 8; /* Line 658, Address: 0x1022e2c */
    --pActwk->actfree[16]; /* Line 659, Address: 0x1022e48 */
    if (pActwk->actfree[16] == 0) /* Line 660, Address: 0x1022e58 */
    {
      ++pActwk->actfree[17]; /* Line 662, Address: 0x1022e6c */
      if (pActwk->actfree[17] != 6) goto label1; /* Line 663, Address: 0x1022e7c */



      pActwk->actfree[17] = 0; /* Line 667, Address: 0x1022e94 */
      goto label1; /* Line 668, Address: 0x1022e9c */
    }
  }
  type5_end(pActwk); /* Line 671, Address: 0x1022ea4 */
} /* Line 672, Address: 0x1022eb0 */




static void type5_end(sprite_status* pActwk) { /* Line 677, Address: 0x1022ed0 */
  hitchk(pActwk, &actwk[0]); /* Line 678, Address: 0x1022edc */
} /* Line 679, Address: 0x1022ef0 */




static void lrblk4_type6(sprite_status* pActwk) { /* Line 684, Address: 0x1022f00 */
  void(*tbl[2])(sprite_status*) = /* Line 685, Address: 0x1022f0c */
  {
    &type6_init,
    &type6_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 691, Address: 0x1022f28 */
  actionsub(pActwk); /* Line 692, Address: 0x1022f64 */
  lrblk4_foutchk(pActwk); /* Line 693, Address: 0x1022f70 */
} /* Line 694, Address: 0x1022f7c */




static void type6_init(sprite_status* pActwk) { /* Line 699, Address: 0x1022f90 */
  sprite_status* pNewActwk;
  uint_union dw;
  short i;
  short d0;
  unsigned char bd0;
  unsigned char d1;

  pActwk->r_no0 += 2; /* Line 707, Address: 0x1022fac */
  pActwk->actflg |= 4; /* Line 708, Address: 0x1022fbc */
  pActwk->sproffset = 17514; /* Line 709, Address: 0x1022fcc */
  pActwk->sprpri = 3; /* Line 710, Address: 0x1022fd8 */
  pActwk->patbase = lrblk4pat6; /* Line 711, Address: 0x1022fe4 */
  pActwk->sprvsize = 16; /* Line 712, Address: 0x1022ff4 */

  if (pActwk->actfree[18] == 0) /* Line 714, Address: 0x1023000 */
  {
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 716, Address: 0x1023014 */
    d1 = 1; /* Line 717, Address: 0x1023024 */
    for (i = 0; i <= 2; ++i) /* Line 718, Address: 0x102302c */
    {
      if (actwkchk(&pNewActwk) == 0) /* Line 720, Address: 0x1023038 */
      {
        pNewActwk->actno = 36; /* Line 722, Address: 0x102304c */
        pNewActwk->userflag.b.h = 6; /* Line 723, Address: 0x1023058 */
        pNewActwk->actfree[18] = d1; /* Line 724, Address: 0x1023064 */
        ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 725, Address: 0x102306c */
        d0 = (char)d1 * 16; /* Line 726, Address: 0x102307c */
        d0 *= -1; /* Line 727, Address: 0x10230a0 */
        d0 += pActwk->xposi.w.h; /* Line 728, Address: 0x10230ac */
        pNewActwk->xposi.w.h = d0; /* Line 729, Address: 0x10230c0 */
        dw.l = d1; /* Line 730, Address: 0x10230c8 */
        dw.l <<= 5; /* Line 731, Address: 0x10230d0 */
        d0 = dw.w.l; /* Line 732, Address: 0x10230dc */
        d0 += pActwk->yposi.w.h; /* Line 733, Address: 0x10230e8 */
        pNewActwk->yposi.w.h = d0; /* Line 734, Address: 0x10230fc */
      }
      ++d1; /* Line 736, Address: 0x1023104 */
    } /* Line 737, Address: 0x102310c */
  }
  bd0 = pActwk->actfree[18]; /* Line 739, Address: 0x102312c */
  pActwk->patno = bd0; /* Line 740, Address: 0x1023138 */
  ++bd0; /* Line 741, Address: 0x1023140 */
  pActwk->actfree[17] = bd0; /* Line 742, Address: 0x1023148 */
  bd0 = pActwk->actfree[18]; /* Line 743, Address: 0x1023150 */
  d1 = 0; /* Line 744, Address: 0x102315c */
  for (i = 0; i <= (short)(unsigned short)bd0; ++i) /* Line 745, Address: 0x1023160 */
  {
    d1 += 16; /* Line 747, Address: 0x102316c */
  } /* Line 748, Address: 0x1023174 */
  pActwk->sprhsize = d1; /* Line 749, Address: 0x10231a8 */
  d0 = pActwk->xposi.w.h; /* Line 750, Address: 0x10231b0 */
  d0 += (unsigned short)d1; /* Line 751, Address: 0x10231c0 */
  ((short*)pActwk)[27] = d0; /* Line 752, Address: 0x10231d8 */
  pActwk->actfree[16] = 128; /* Line 753, Address: 0x10231e0 */

  type6_move(pActwk); /* Line 755, Address: 0x10231ec */
} /* Line 756, Address: 0x10231f8 */




static void type6_move(sprite_status* pActwk) { /* Line 761, Address: 0x1023220 */
  short d0, d1, d3, stk;
  unsigned char d2;

  stk = pActwk->xposi.w.h; /* Line 765, Address: 0x1023238 */
  sinset(pActwk->actfree[16], &d0, &d1); /* Line 766, Address: 0x1023248 */

  d3 = 0; /* Line 768, Address: 0x1023260 */
  d2 = pActwk->actfree[17]; /* Line 769, Address: 0x1023264 */
  if (d2) /* Line 770, Address: 0x1023270 */
  {
    do
    {
      d3 += d0; /* Line 774, Address: 0x1023278 */
      --d2; /* Line 775, Address: 0x1023288 */
    } while (d2 != 0); /* Line 776, Address: 0x1023290 */
  }

  d3 >>= 4; /* Line 779, Address: 0x102329c */
  d0 = d3; /* Line 780, Address: 0x10232a8 */
  d0 += ((short*)pActwk)[27]; /* Line 781, Address: 0x10232ac */
  pActwk->xposi.w.h = d0; /* Line 782, Address: 0x10232c0 */

  d1 = stk; /* Line 784, Address: 0x10232cc */
  d0 -= d1; /* Line 785, Address: 0x10232d0 */
  d0 <<= 8; /* Line 786, Address: 0x10232e0 */
  pActwk->xspeed.w = d0; /* Line 787, Address: 0x10232ec */
  ++pActwk->actfree[16]; /* Line 788, Address: 0x10232f8 */
  hitchk(pActwk, &actwk[0]); /* Line 789, Address: 0x1023308 */
} /* Line 790, Address: 0x102331c */




static void lrblk4_type8(sprite_status* pActwk) { /* Line 795, Address: 0x1023340 */
  void(*tbl[2])(sprite_status*) = /* Line 796, Address: 0x102334c */
  {
    &type8_init,
    &type8_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 802, Address: 0x1023368 */
  actionsub(pActwk); /* Line 803, Address: 0x10233a4 */
  lrblk4_foutchk(pActwk); /* Line 804, Address: 0x10233b0 */
} /* Line 805, Address: 0x10233bc */




static void type8_init(sprite_status* pActwk) { /* Line 810, Address: 0x10233d0 */
  sprite_status* pNewActwk;
  short d0;

  pActwk->r_no0 += 2; /* Line 814, Address: 0x10233e0 */
  pActwk->actflg |= 4; /* Line 815, Address: 0x10233f0 */
  pActwk->sproffset = 17514; /* Line 816, Address: 0x1023400 */
  pActwk->sprpri = 3; /* Line 817, Address: 0x102340c */
  pActwk->patbase = lrblk4pat8; /* Line 818, Address: 0x1023418 */
  pActwk->sprhsize = 64; /* Line 819, Address: 0x1023428 */
  pActwk->sprvsize = 16; /* Line 820, Address: 0x1023434 */

  if (pActwk->actfree[18] == 0) /* Line 822, Address: 0x1023440 */
  {
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 824, Address: 0x1023454 */
    if (actwkchk(&pNewActwk) == 0) /* Line 825, Address: 0x1023464 */
    {
      pNewActwk->actno = 36; /* Line 827, Address: 0x1023478 */
      pNewActwk->userflag.b.h = 4; /* Line 828, Address: 0x1023484 */
      pNewActwk->actfree[19] = 8; /* Line 829, Address: 0x1023490 */
      pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 830, Address: 0x102349c */
      pNewActwk->yposi.w.h = pActwk->yposi.w.h - 96; /* Line 831, Address: 0x10234ac */
    }
    if (actwkchk(&pNewActwk) == 0) /* Line 833, Address: 0x10234d0 */
    {
      pNewActwk->actno = 36; /* Line 835, Address: 0x10234e4 */
      pNewActwk->userflag.b.h = 8; /* Line 836, Address: 0x10234f0 */
      pNewActwk->actfree[18] = 1; /* Line 837, Address: 0x10234fc */
      ((short*)pNewActwk)[29] = ((short*)pActwk)[29]; /* Line 838, Address: 0x1023508 */
      d0 = ((short*)pActwk)[29]; /* Line 839, Address: 0x1023518 */
      d0 -= 128; /* Line 840, Address: 0x1023528 */
      pNewActwk->xposi.w.h = d0; /* Line 841, Address: 0x1023534 */
      pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 842, Address: 0x102353c */
      d0 = ((short*)pActwk)[29]; /* Line 843, Address: 0x102354c */
      d0 += 128; /* Line 844, Address: 0x102355c */
      pActwk->xposi.w.h = d0; /* Line 845, Address: 0x1023568 */
    }
  }
  pActwk->xspeed.w = 512; /* Line 848, Address: 0x1023570 */
} /* Line 849, Address: 0x102357c */




static void type8_move(sprite_status* pActwk) { /* Line 854, Address: 0x1023590 */
  short d0;

  pActwk->xposi.l += pActwk->xspeed.w << 8; /* Line 857, Address: 0x10235a0 */
  hitchk(pActwk, &actwk[0]); /* Line 858, Address: 0x10235c4 */
  d0 = pActwk->xposi.w.h; /* Line 859, Address: 0x10235d8 */
  if (d0 >= ((short*)pActwk)[29]) /* Line 860, Address: 0x10235e8 */
  {
    d0 -= ((short*)pActwk)[29]; /* Line 862, Address: 0x102360c */
    if (d0 == 256) /* Line 863, Address: 0x1023620 */
    {
      pActwk->xposi.w.h = ((short*)pActwk)[29] - 256; /* Line 865, Address: 0x1023634 */
    }
  }
} /* Line 868, Address: 0x1023658 */
