#include "..\EQU.H"
#include "HACHI8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\SUICIDE.H"

extern void patchg(sprite_status* patchgwk, unsigned char** pat_dat);

static void ball(sprite_status* actionwk);
static void ball_move(sprite_status* actionwk);

static char p00[4] = { 2, 0, 1, -1 };
static char* pchg[1] = { p00 };
static sprite_pattern body_pat0 =
{
  1,
  { { -19, -20, 0, 469 } }
};
static sprite_pattern body_pat1 =
{
  1,
  { { -19, -20, 0, 470 } }
};
static sprite_pattern kusari_00 =
{
  1,
  { { -8, -8, 0, 471 } }
};
static sprite_pattern ball_pat0 =
{
  1,
  { { -12, -12, 0, 472 } }
};
static sprite_pattern kusari_01 =
{
  1,
  { { -8, -8, 0, 473 } }
};
static sprite_pattern ball_pat1 =
{
  1,
  { { -12, -12, 0, 474 } }
};
sprite_pattern* pat_hachi8_e[4] =
{
  &body_pat0,
  &body_pat1,
  &kusari_00,
  &ball_pat0
};
sprite_pattern* pat_hachi8_b[4] =
{
  &body_pat0,
  &body_pat1,
  &kusari_01,
  &ball_pat1
};











void hachi8(sprite_status* actionwk) { /* Line 70, Address: 0x1024480 */
  if (actionwk->userflag.b.l == 0) /* Line 71, Address: 0x102448c */
  {
    body(actionwk); /* Line 73, Address: 0x10244a4 */
    return; /* Line 74, Address: 0x10244b0 */
  }
  if (actionwk->userflag.b.l > 0) /* Line 76, Address: 0x10244b8 */
  {
    kusari(actionwk); /* Line 78, Address: 0x10244d0 */
    return; /* Line 79, Address: 0x10244dc */
  }
  ball(actionwk); /* Line 81, Address: 0x10244e4 */
} /* Line 82, Address: 0x10244f0 */

void body(sprite_status* actionwk) { /* Line 84, Address: 0x1024500 */
  sprite_status* a1;

  if (enemy_suicide(actionwk) == -1) return; /* Line 87, Address: 0x102450c */

  if (actionwk->r_no0 != 0) /* Line 89, Address: 0x102452c */
  {
    body_move(actionwk); /* Line 91, Address: 0x1024540 */
    return; /* Line 92, Address: 0x102454c */
  }

  actionwk->r_no0 += 2; /* Line 95, Address: 0x1024554 */
  actionwk->actflg |= 4; /* Line 96, Address: 0x1024564 */
  actionwk->sprpri = 3; /* Line 97, Address: 0x1024574 */
  actionwk->sprhs = 16; /* Line 98, Address: 0x1024580 */
  actionwk->sprhsize = 16; /* Line 99, Address: 0x102458c */
  actionwk->sprvsize = 16; /* Line 100, Address: 0x1024598 */
  actionwk->colino = 46; /* Line 101, Address: 0x10245a4 */
  actionwk->sproffset = 9301; /* Line 102, Address: 0x10245b0 */
  ((short*)actionwk)[30] = actionwk->xposi.w.h; /* Line 103, Address: 0x10245bc */
  ((short*)actionwk)[31] = actionwk->yposi.w.h; /* Line 104, Address: 0x10245cc */
  ((short*)actionwk)[26] = 0; /* Line 105, Address: 0x10245dc */
  if (actionwk->userflag.b.h == 0) /* Line 106, Address: 0x10245e4 */
  {
    actionwk->patbase = pat_hachi8_e; /* Line 108, Address: 0x10245fc */
    *(int*)&actionwk->actfree[0] = -65536; /* Line 109, Address: 0x102460c */
    ((short*)actionwk)[25] = 128; /* Line 110, Address: 0x102461c */
    ((short*)actionwk)[28] = 1024; /* Line 111, Address: 0x1024628 */
    ((short*)actionwk)[29] = 3; /* Line 112, Address: 0x1024634 */
  } /* Line 113, Address: 0x1024640 */
  else
  {
    actionwk->patbase = pat_hachi8_b; /* Line 116, Address: 0x1024648 */
    *(int*)&actionwk->actfree[0] = -32768; /* Line 117, Address: 0x1024658 */
    ((short*)actionwk)[25] = 256; /* Line 118, Address: 0x1024668 */
    ((short*)actionwk)[28] = 768; /* Line 119, Address: 0x1024674 */
    ((short*)actionwk)[29] = 4; /* Line 120, Address: 0x1024680 */
  }

  if (actwkchk2(actionwk, &a1) != 0) /* Line 123, Address: 0x102468c */
  {
    frameout(actionwk); /* Line 125, Address: 0x10246a4 */
    return; /* Line 126, Address: 0x10246b0 */
  }
  a1->actno = actionwk->actno; /* Line 128, Address: 0x10246b8 */
  ((unsigned short*)actionwk)[32] = a1 - actwk; /* Line 129, Address: 0x10246c8 */
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 130, Address: 0x10246fc */
  a1->actflg = actionwk->actflg; /* Line 131, Address: 0x1024730 */
  a1->sproffset = actionwk->sproffset; /* Line 132, Address: 0x1024740 */
  a1->patbase = actionwk->patbase; /* Line 133, Address: 0x1024750 */
  a1->userflag.b.h = actionwk->userflag.b.h; /* Line 134, Address: 0x1024760 */
  a1->userflag.b.l = -1; /* Line 135, Address: 0x1024770 */
  a1->xposi.w.h = actionwk->xposi.w.h; /* Line 136, Address: 0x102477c */
  a1->yposi.w.h = actionwk->yposi.w.h; /* Line 137, Address: 0x102478c */


  if (actionwk->userflag.b.h != 0) /* Line 140, Address: 0x102479c */
  {
    body_move(actionwk); /* Line 142, Address: 0x10247b4 */
    return; /* Line 143, Address: 0x10247c0 */
  }
  if (actwkchk2(actionwk, &a1) != 0) /* Line 145, Address: 0x10247c8 */
  {
    frameout(actionwk); /* Line 147, Address: 0x10247e0 */
    return; /* Line 148, Address: 0x10247ec */
  }

  a1->actno = actionwk->actno; /* Line 151, Address: 0x10247f4 */
  ((unsigned short*)actionwk)[33] = a1 - actwk; /* Line 152, Address: 0x1024804 */
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 153, Address: 0x1024838 */
  a1->actflg = actionwk->actflg; /* Line 154, Address: 0x102486c */
  a1->sproffset = actionwk->sproffset; /* Line 155, Address: 0x102487c */
  a1->patbase = actionwk->patbase; /* Line 156, Address: 0x102488c */
  a1->userflag.b.h = actionwk->userflag.b.h; /* Line 157, Address: 0x102489c */
  a1->userflag.b.l = -2; /* Line 158, Address: 0x10248ac */
  a1->xposi.w.h = actionwk->xposi.w.h; /* Line 159, Address: 0x10248b8 */
  a1->yposi.w.h = actionwk->yposi.w.h; /* Line 160, Address: 0x10248c8 */
} /* Line 161, Address: 0x10248d8 */

void body_move(sprite_status* actionwk) { /* Line 163, Address: 0x10248f0 */
  unsigned short d0, sin, cos;
  int d0l;
  short t;

  actionwk->xposi.l += *(int*)&actionwk->actfree[0]; /* Line 168, Address: 0x1024908 */
  --((short*)actionwk)[26]; /* Line 169, Address: 0x1024924 */
  t = ((short*)actionwk)[26]; /* Line 170, Address: 0x1024934 */
  if (t < 0) /* Line 171, Address: 0x1024944 */
  {
    ((int*)actionwk)[13] = ((short*)actionwk)[25]; /* Line 173, Address: 0x1024954 */

    *(int*)&actionwk->actfree[0] = -*(int*)&actionwk->actfree[0]; /* Line 175, Address: 0x102496c */

    actionwk->actflg ^= 1; /* Line 177, Address: 0x1024988 */
    actionwk->cddat ^= 1; /* Line 178, Address: 0x1024998 */
  }

  actionwk->yposi.w.h = ((short*)actionwk)[31]; /* Line 181, Address: 0x10249a8 */
  actionwk->yposi.w.l = 0; /* Line 182, Address: 0x10249b8 */
  ((short*)actionwk)[27] += ((short*)actionwk)[28]; /* Line 183, Address: 0x10249c0 */

  d0 = ((short*)actionwk)[27] >> 8; /* Line 185, Address: 0x10249d8 */
  sinset(d0, (short*)&sin, (short*)&cos); /* Line 186, Address: 0x10249f4 */
  d0l = sin << 16; /* Line 187, Address: 0x1024a08 */
  d0l >>= ((short*)actionwk)[29]; /* Line 188, Address: 0x1024a14 */
  actionwk->yposi.l += d0l; /* Line 189, Address: 0x1024a28 */
  patchg(actionwk, (unsigned char**)pchg); /* Line 190, Address: 0x1024a38 */
  actionsub(actionwk); /* Line 191, Address: 0x1024a4c */
  frameout_s00(actionwk, ((short*)actionwk)[30]); /* Line 192, Address: 0x1024a58 */
} /* Line 193, Address: 0x1024a6c */



















static void ball(sprite_status* actionwk) { /* Line 213, Address: 0x1024a90 */
  sprite_status* a1;
  short i, d6;

  if (actionwk->r_no0 != 0) /* Line 217, Address: 0x1024aa4 */
  {
    ball_move(actionwk); /* Line 219, Address: 0x1024ab8 */
    return; /* Line 220, Address: 0x1024ac4 */
  }

  actionwk->r_no0 += 2; /* Line 223, Address: 0x1024acc */
  actionwk->sprhs = 12; /* Line 224, Address: 0x1024adc */
  actionwk->sprhsize = 12; /* Line 225, Address: 0x1024ae8 */
  actionwk->sprvsize = 12; /* Line 226, Address: 0x1024af4 */
  actionwk->sprpri = 2; /* Line 227, Address: 0x1024b00 */
  actionwk->patno = 3; /* Line 228, Address: 0x1024b0c */
  actionwk->colino = 175; /* Line 229, Address: 0x1024b18 */
  if (actionwk->userflag.b.l == -1) /* Line 230, Address: 0x1024b24 */
  {
    ((short*)actionwk)[23] = 2048; /* Line 232, Address: 0x1024b40 */
    ((short*)actionwk)[25] = 8; /* Line 233, Address: 0x1024b4c */
    ((short*)actionwk)[26] = 9; /* Line 234, Address: 0x1024b58 */
  } /* Line 235, Address: 0x1024b64 */
  else
  {
    ((short*)actionwk)[23] = 4096; /* Line 238, Address: 0x1024b6c */
    ((short*)actionwk)[25] = 8; /* Line 239, Address: 0x1024b78 */
    ((short*)actionwk)[26] = 3; /* Line 240, Address: 0x1024b84 */
  }

  d6 = ((short*)actionwk)[26]; /* Line 243, Address: 0x1024b90 */


  for (i = 0; i <= d6; ++i) /* Line 246, Address: 0x1024ba0 */
  {
    if (actwkchk2(actionwk, &a1) != 0) /* Line 248, Address: 0x1024bac */
    {

      frameout(actionwk); /* Line 251, Address: 0x1024bc4 */
      return; /* Line 252, Address: 0x1024bd0 */
    }

    a1->actno = actionwk->actno; /* Line 255, Address: 0x1024bd8 */
    actionwk->actfree[i + 8] = a1 - actwk; /* Line 256, Address: 0x1024be8 */
    ((unsigned short*)a1)[33] = ((unsigned short*)actionwk)[33]; /* Line 257, Address: 0x1024c2c */

    a1->actflg = actionwk->actflg; /* Line 259, Address: 0x1024c3c */
    a1->sproffset = actionwk->sproffset; /* Line 260, Address: 0x1024c4c */
    a1->patbase = actionwk->patbase; /* Line 261, Address: 0x1024c5c */
    a1->userflag.b.h = actionwk->userflag.b.h; /* Line 262, Address: 0x1024c6c */
    a1->userflag.b.l = 1; /* Line 263, Address: 0x1024c7c */
    a1->xposi.w.h = actionwk->xposi.w.h; /* Line 264, Address: 0x1024c88 */
    a1->yposi.w.h = actionwk->yposi.w.h; /* Line 265, Address: 0x1024c98 */
  } /* Line 266, Address: 0x1024ca8 */
  ball_move(actionwk); /* Line 267, Address: 0x1024cd0 */
} /* Line 268, Address: 0x1024cdc */

static void ball_move(sprite_status* actionwk) { /* Line 270, Address: 0x1024d00 */
  int_union d2, d3;
  short d0, d6, i, ano;
  unsigned short sin, cos;
  int d4, d5;

  ((short*)actionwk)[24] += ((short*)actionwk)[25]; /* Line 276, Address: 0x1024d24 */

  d6 = ((short*)actionwk)[23]; /* Line 278, Address: 0x1024d3c */
  ((short*)actionwk)[23] += ((short*)actionwk)[24]; /* Line 279, Address: 0x1024d4c */












  if ((((short*)actionwk)[25] >= 0 /* Line 292, Address: 0x1024d64 */
        && ((unsigned short*)actionwk)[24] < 16384
        && ((unsigned short*)actionwk)[23] >= 16384)
      ||
      (((short*)actionwk)[25] < 0
        && ((unsigned short*)actionwk)[24] >= 16384
        && ((unsigned short*)actionwk)[23] < 16384))
  {
    ((short*)actionwk)[25] = -((short*)actionwk)[25]; /* Line 300, Address: 0x1024df4 */
  }


  d6 = ((short*)actionwk)[26]; /* Line 304, Address: 0x1024e18 */
  ano = ((unsigned short*)actionwk)[33]; /* Line 305, Address: 0x1024e28 */
  d5 = actwk[ano].yposi.l + 786432; /* Line 306, Address: 0x1024e38 */
  d4 = actwk[ano].xposi.l; /* Line 307, Address: 0x1024e64 */
  d0 = ((short*)actionwk)[23] >> 8; /* Line 308, Address: 0x1024e88 */
  sinset(d0, (short*)&sin, (short*)&cos); /* Line 309, Address: 0x1024eac */
  d3.l = sin; /* Line 310, Address: 0x1024ec0 */
  d2.l = cos; /* Line 311, Address: 0x1024ecc */
  d3.l = (unsigned int)d3.l >> 16 & 65535 | d3.l << 16 & -65536; /* Line 312, Address: 0x1024ed8 */
  d2.l = (unsigned int)d2.l >> 16 & 65535 | d2.l << 16 & -65536; /* Line 313, Address: 0x1024efc */
  d3.w.l = 0; /* Line 314, Address: 0x1024f20 */
  d2.w.l = 0; /* Line 315, Address: 0x1024f24 */
  d3.l >>= 5; /* Line 316, Address: 0x1024f28 */
  d2.l >>= 5; /* Line 317, Address: 0x1024f34 */


  for (i = 0; i <= d6; ++i) /* Line 320, Address: 0x1024f40 */
  {
    d5 += d3.l; /* Line 322, Address: 0x1024f4c */
    d4 += d2.l; /* Line 323, Address: 0x1024f54 */
    ano = actionwk->actfree[i + 8]; /* Line 324, Address: 0x1024f5c */
    actwk[ano].yposi.l = d5; /* Line 325, Address: 0x1024f80 */
    actwk[ano].xposi.l = d4; /* Line 326, Address: 0x1024fa4 */
  } /* Line 327, Address: 0x1024fc8 */
  d5 += d3.l; /* Line 328, Address: 0x1024ff0 */
  d4 += d2.l; /* Line 329, Address: 0x1024ff8 */
  actionwk->yposi.l = d5; /* Line 330, Address: 0x1025000 */
  actionwk->xposi.l = d4; /* Line 331, Address: 0x1025008 */
  kusari_move(actionwk); /* Line 332, Address: 0x1025010 */
} /* Line 333, Address: 0x102501c */

void kusari(sprite_status* actionwk) { /* Line 335, Address: 0x1025050 */
  if (actionwk->r_no0 != 0) /* Line 336, Address: 0x102505c */
  {
    kusari_move(actionwk); /* Line 338, Address: 0x1025070 */
    return; /* Line 339, Address: 0x102507c */
  }

  actionwk->r_no0 += 2; /* Line 342, Address: 0x1025084 */
  actionwk->sprhs = 8; /* Line 343, Address: 0x1025094 */
  actionwk->sprhsize = 8; /* Line 344, Address: 0x10250a0 */
  actionwk->sprvsize = 8; /* Line 345, Address: 0x10250ac */
  actionwk->sprpri = 3; /* Line 346, Address: 0x10250b8 */
  actionwk->patno = 2; /* Line 347, Address: 0x10250c4 */
  kusari_move(actionwk); /* Line 348, Address: 0x10250d0 */
} /* Line 349, Address: 0x10250dc */

void kusari_move(sprite_status* actionwk) { /* Line 351, Address: 0x10250f0 */
  short ano;

  ano = ((unsigned short*)actionwk)[33]; /* Line 354, Address: 0x1025100 */
  if (actwk[ano].actno != 46) /* Line 355, Address: 0x1025110 */
  {
    frameout(actionwk); /* Line 357, Address: 0x1025144 */
    return; /* Line 358, Address: 0x1025150 */
  }
  actionsub(actionwk); /* Line 360, Address: 0x1025158 */
} /* Line 361, Address: 0x1025164 */
