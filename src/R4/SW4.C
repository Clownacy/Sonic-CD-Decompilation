#include "..\EQU.H"
#include "SW4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"

#if defined(R41A) || defined(R42A)
  #define SPRITE_SW4_BASE 438
#elif defined(R41B)
  #define SPRITE_SW4_BASE 492
#elif defined(R41C) || defined(R41D)
  #define SPRITE_SW4_BASE 476
#elif defined(R42B)
  #define SPRITE_SW4_BASE 489
#elif defined(R42C) || defined(R42D)
  #define SPRITE_SW4_BASE 486
#else
  #define SPRITE_SW4_BASE 472
#endif

static void act_init(sprite_status* pActwk);
static void act_move(sprite_status* pActwk);
static short hosei(sprite_status* pActwk, sprite_status* pActwk2);

static sprite_pattern pat00 =
{
  1,
  { { -16, -8, 0, SPRITE_SW4_BASE } }
};
static sprite_pattern pat01 =
{
  1,
  { { -16, -4, 0, SPRITE_SW4_BASE + 1 } }
};
sprite_pattern* pat_sw[2] =
{
  &pat00,
  &pat01
};

















void sw4(sprite_status* pActwk) { /* Line 58, Address: 0x1016910 */
  if (pActwk->r_no0) act_move(pActwk); /* Line 59, Address: 0x101691c */
  else act_init(pActwk); /* Line 60, Address: 0x1016940 */
} /* Line 61, Address: 0x101694c */




static void act_init(sprite_status* pActwk) { /* Line 66, Address: 0x1016960 */
  pActwk->r_no0 += 2; /* Line 67, Address: 0x101696c */
  pActwk->actflg |= 4; /* Line 68, Address: 0x101697c */
  pActwk->sprpri = 3; /* Line 69, Address: 0x101698c */
  pActwk->sprhsize = 16; /* Line 70, Address: 0x1016998 */
  pActwk->sproffset = 1290; /* Line 71, Address: 0x10169a4 */
  pActwk->patbase = pat_sw; /* Line 72, Address: 0x10169b0 */
  pActwk->sprvsize = 10; /* Line 73, Address: 0x10169c0 */

  ((short*)pActwk)[32] = (unsigned short)pActwk->userflag.b.h; /* Line 75, Address: 0x10169cc */

  pActwk->actfree[20] = 0; /* Line 77, Address: 0x10169ec */
  pActwk->actfree[21] = 0; /* Line 78, Address: 0x10169f4 */

  act_move(pActwk); /* Line 80, Address: 0x10169fc */
} /* Line 81, Address: 0x1016a08 */




static void act_move(sprite_status* pActwk) { /* Line 86, Address: 0x1016a20 */
  sprite_status* pActwk_a1;
  sprite_status* pPlayerwk;
  unsigned char* a4;
  short d0, d1, d3, d4;
  short z;

  d0 = ((short*)pActwk)[28]; /* Line 93, Address: 0x1016a4c */
  if (d0) /* Line 94, Address: 0x1016a5c */
  {
    pActwk_a1 = &actwk[d0]; /* Line 96, Address: 0x1016a64 */
    d1 = pActwk->xposi.w.h; /* Line 97, Address: 0x1016a84 */
    d0 = ((char*)pActwk)[60]; /* Line 98, Address: 0x1016a94 */
    d0 += pActwk_a1->xposi.w.h; /* Line 99, Address: 0x1016aac */
    pActwk->xposi.w.h = d0; /* Line 100, Address: 0x1016abc */
    d0 -= d1; /* Line 101, Address: 0x1016ac4 */
    d0 <<= 8; /* Line 102, Address: 0x1016ad0 */
    pActwk->xspeed.w = d0; /* Line 103, Address: 0x1016adc */
    d0 = ((char*)pActwk)[61]; /* Line 104, Address: 0x1016ae4 */
    d0 += pActwk_a1->yposi.w.h; /* Line 105, Address: 0x1016afc */
    pActwk->yposi.w.h = d0; /* Line 106, Address: 0x1016b0c */
  }
  pActwk->actfree[20] = pActwk->actfree[21]; /* Line 108, Address: 0x1016b14 */
  d3 = pActwk->xposi.w.h; /* Line 109, Address: 0x1016b24 */
  d4 = pActwk->yposi.w.h; /* Line 110, Address: 0x1016b34 */
  pPlayerwk = &actwk[0]; /* Line 111, Address: 0x1016b44 */
  if (hitchk(pActwk, pPlayerwk)) /* Line 112, Address: 0x1016b4c */
  {
    z = hosei(pActwk, pPlayerwk); /* Line 114, Address: 0x1016b64 */
  } /* Line 115, Address: 0x1016b7c */
  else
  {
    z = 1; /* Line 118, Address: 0x1016b84 */
  }
  a4 = &switchflag[((short*)pActwk)[32]]; /* Line 120, Address: 0x1016b90 */
  if (z == 0) pActwk->actfree[21] = 255; /* Line 121, Address: 0x1016bac */
  else pActwk->actfree[21] = 0; /* Line 122, Address: 0x1016bd0 */
  if (z) /* Line 123, Address: 0x1016bd8 */
  {
    *a4 &= 127; /* Line 125, Address: 0x1016be0 */
  } /* Line 126, Address: 0x1016bec */
  else
  {
    hosei(pActwk, pPlayerwk); /* Line 129, Address: 0x1016bf4 */
    *a4 |= 128; /* Line 130, Address: 0x1016c04 */
    *a4 |= 64; /* Line 131, Address: 0x1016c10 */
  }

  if (pActwk->actfree[20] == 0 && pActwk->actfree[21] == 255) /* Line 134, Address: 0x1016c1c */
  {
    if (pActwk->actflg & 128) /* Line 136, Address: 0x1016c48 */
    {
      soundset(191); /* Line 138, Address: 0x1016c60 */
    }
    *a4 ^= 32; /* Line 140, Address: 0x1016c6c */
    pPlayerwk->yposi.w.h += 8; /* Line 141, Address: 0x1016c78 */
    if (((short*)pActwk)[28]) /* Line 142, Address: 0x1016c84 */
    {
      ((char*)pActwk)[61] += 4; /* Line 144, Address: 0x1016c94 */
    } /* Line 145, Address: 0x1016ca4 */
    else
    {
      pActwk->yposi.w.h += 4; /* Line 148, Address: 0x1016cac */
    }
    pActwk->patno = 1; /* Line 150, Address: 0x1016cbc */
    pActwk->sprvsize -= 4; /* Line 151, Address: 0x1016cc8 */
  }

  if (pActwk->actfree[20] == 255 && pActwk->actfree[21] == 0) /* Line 154, Address: 0x1016cd8 */
  {
    pPlayerwk->yposi.w.h -= 8; /* Line 156, Address: 0x1016d04 */
    if (((short*)pActwk)[28]) /* Line 157, Address: 0x1016d10 */
    {
      ((char*)pActwk)[61] -= 4; /* Line 159, Address: 0x1016d20 */
    } /* Line 160, Address: 0x1016d30 */
    else
    {
      pActwk->yposi.w.h -= 4; /* Line 163, Address: 0x1016d38 */
    }
    pActwk->patno = 0; /* Line 165, Address: 0x1016d48 */
    pActwk->sprvsize += 4; /* Line 166, Address: 0x1016d50 */
  }
  actionsub(pActwk); /* Line 168, Address: 0x1016d60 */
  d0 = ((short*)pActwk)[28]; /* Line 169, Address: 0x1016d6c */
  if (d0 == 0) /* Line 170, Address: 0x1016d7c */
  {
    frameout_s(pActwk); /* Line 172, Address: 0x1016d8c */
    return; /* Line 173, Address: 0x1016d98 */
  }
  pActwk_a1 = &actwk[d0]; /* Line 175, Address: 0x1016da0 */
  d0 = ((short*)pActwk_a1)[29]; /* Line 176, Address: 0x1016dc0 */
  d0 &= -128; /* Line 177, Address: 0x1016dcc */
  d1 = scra_h_posit.w.h; /* Line 178, Address: 0x1016ddc */
  d1 -= 128; /* Line 179, Address: 0x1016dec */
  d1 &= -128; /* Line 180, Address: 0x1016df8 */
  d0 -= d1; /* Line 181, Address: 0x1016e08 */
  if ((unsigned short)d0 > 640) frameout_s0(pActwk); /* Line 182, Address: 0x1016e14 */
} /* Line 183, Address: 0x1016e34 */




static short hosei(sprite_status* pActwk, sprite_status* pActwk2) { /* Line 188, Address: 0x1016e70 */
  short d0, d1;
  short z;

  d0 = pActwk->yposi.w.h; /* Line 192, Address: 0x1016e88 */
  d1 = pActwk->sprvsize; /* Line 193, Address: 0x1016e98 */
  d0 -= d1; /* Line 194, Address: 0x1016eac */
  d1 = pActwk2->sprvsize; /* Line 195, Address: 0x1016eb8 */
  d0 -= d1; /* Line 196, Address: 0x1016ecc */
  ++d0; /* Line 197, Address: 0x1016ed8 */
  pActwk2->yposi.w.h = d0; /* Line 198, Address: 0x1016ee4 */
  if (d0) z = 0; /* Line 199, Address: 0x1016eec */
  else z = 1; /* Line 200, Address: 0x1016f00 */
  return z; /* Line 201, Address: 0x1016f0c */
} /* Line 202, Address: 0x1016f10 */
