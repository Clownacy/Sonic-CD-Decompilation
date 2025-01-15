#include "..\EQU.H"
#include "BRUNKO4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\RIDECHK.H"

#if defined(R42A)
  #define SPRITE_BRUNKO4_BASE 476
#else
  #define SPRITE_BRUNKO4_BASE 470
#endif

static void brunko4_ridechk(sprite_status* pActwk);
static void brunko_init(sprite_status* pActwk);
static void brunko_move(sprite_status* pActwk);
static void brunko4_posiset(sprite_status* pActwk);

static sprite_pattern pat0 =
{
  1,
  { { -8, -8, 0, SPRITE_BRUNKO4_BASE } }
};
static sprite_pattern pat1 =
{
  1,
  { { -32, -8, 0, SPRITE_BRUNKO4_BASE + 1 } }
};
static sprite_pattern pat2 =
{
  1,
  { { -8, -8, 0, SPRITE_BRUNKO4_BASE + 2 } }
};
sprite_pattern* brunko4pat[3] =
{
  &pat0,
  &pat1,
  &pat2
};


























































void brunko4(sprite_status* pActwk) { /* Line 98, Address: 0x1022080 */
  short wD0, wD1;
  static void(*tbl[2])(sprite_status*) =
  {
    &brunko_init,
    &brunko_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 106, Address: 0x1022094 */
  actionsub(pActwk); /* Line 107, Address: 0x10220d8 */


  wD0 = ((short*)pActwk)[29] & -128; /* Line 110, Address: 0x10220e4 */
  wD1 = (scra_h_posit.w.h - 128) & -128; /* Line 111, Address: 0x102210c */
  wD0 -= wD1; /* Line 112, Address: 0x1022138 */
  if ((unsigned short)wD0 <= 640) return; /* Line 113, Address: 0x1022144 */
  frameout(pActwk); /* Line 114, Address: 0x1022158 */
} /* Line 115, Address: 0x1022164 */



static void brunko4_ridechk(sprite_status* pActwk) { /* Line 119, Address: 0x1022180 */
  if (ridechk(pActwk, &actwk[0])) /* Line 120, Address: 0x102218c */
  {

    actwk[0].yposi.w.h = (pActwk->yposi.w.h - (short)pActwk->sprvsize) - (short)actwk[0].sprvsize + 2; /* Line 123, Address: 0x10221a8 */
  }
} /* Line 125, Address: 0x10221fc */




static void brunko_init(sprite_status* pActwk) { /* Line 130, Address: 0x1022210 */
  sprite_status* subActwk;
  unsigned char id;
  int i;

  pActwk->r_no0 += 2; /* Line 135, Address: 0x1022224 */
  pActwk->actflg |= 4; /* Line 136, Address: 0x1022234 */
  pActwk->sprpri = 4; /* Line 137, Address: 0x1022244 */
  pActwk->patbase = brunko4pat; /* Line 138, Address: 0x1022250 */
  pActwk->sproffset = 832; /* Line 139, Address: 0x1022260 */
  if (pActwk->patno == 1) /* Line 140, Address: 0x102226c */
    pActwk->sproffset += 16384; /* Line 141, Address: 0x1022284 */

  pActwk->sprhsize = 32; /* Line 143, Address: 0x1022294 */
  pActwk->sprvsize = 10; /* Line 144, Address: 0x10222a0 */
  pActwk->actfree[16] = 192; /* Line 145, Address: 0x10222ac */

  if (pActwk->actfree[18] == 6) /* Line 147, Address: 0x10222b8 */
  {
    if (actwkchk2(pActwk, &subActwk) == 0) /* Line 149, Address: 0x10222d0 */
    {
      subActwk->actno = 39; /* Line 151, Address: 0x10222e8 */
      ((short*)subActwk)[28] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 152, Address: 0x10222f4 */
      ((char*)subActwk)[61] = -16; /* Line 153, Address: 0x1022334 */
      subActwk->actfree[14] = 16; /* Line 154, Address: 0x1022340 */
      subActwk->userflag.b.h = (unsigned char)(pActwk->userflag.b.h & 15); /* Line 155, Address: 0x102234c */
    }
  }

  if (!pActwk->actfree[18]) /* Line 159, Address: 0x1022374 */
  {
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 161, Address: 0x1022384 */
    ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 162, Address: 0x1022394 */

    id = 6; /* Line 164, Address: 0x10223a4 */
    for (i = 0; i < 6; ++i) /* Line 165, Address: 0x10223ac */
    {
      if (actwkchk(&subActwk) == 0) /* Line 167, Address: 0x10223b8 */
      {
        subActwk->actno = 41; /* Line 169, Address: 0x10223cc */
        ((short*)subActwk)[29] = ((short*)pActwk)[29]; /* Line 170, Address: 0x10223d8 */
        ((short*)subActwk)[27] = ((short*)pActwk)[27]; /* Line 171, Address: 0x10223e8 */
        subActwk->userflag.b.h = pActwk->userflag.b.h; /* Line 172, Address: 0x10223f8 */
        subActwk->actfree[18] = id; /* Line 173, Address: 0x1022408 */
        subActwk->patno = 2; /* Line 174, Address: 0x1022410 */
        if (id == 6) /* Line 175, Address: 0x102241c */
          subActwk->patno = 1; /* Line 176, Address: 0x102242c */
      }

      --id; /* Line 179, Address: 0x1022438 */
    } /* Line 180, Address: 0x1022440 */
  }
  brunko_move(pActwk); /* Line 182, Address: 0x1022450 */
} /* Line 183, Address: 0x102245c */



static void brunko_move(sprite_status* pActwk) { /* Line 187, Address: 0x1022480 */
  int_union xposi_bak, yposi_bak;
  int xposi_f, yposi_f;
  int i;

  xposi_bak.l = pActwk->xposi.l; /* Line 192, Address: 0x1022498 */
  yposi_bak.l = pActwk->yposi.l; /* Line 193, Address: 0x10224a4 */
  brunko4_posiset(pActwk); /* Line 194, Address: 0x10224b0 */
  if (pActwk->actfree[18] == 6) /* Line 195, Address: 0x10224bc */
  {
    xposi_bak.l = pActwk->xposi.l - xposi_bak.l; /* Line 197, Address: 0x10224d4 */
    yposi_bak.l = pActwk->yposi.l - yposi_bak.l; /* Line 198, Address: 0x10224e8 */
    xposi_f = xposi_bak.l & 0x80000000; /* Line 199, Address: 0x10224fc */
    yposi_f = yposi_bak.l & 0x80000000; /* Line 200, Address: 0x1022508 */
    for (i = 0; i < 8; ++i) /* Line 201, Address: 0x1022514 */
      xposi_bak.l = xposi_bak.l >> 1 | xposi_f; /* Line 202, Address: 0x1022520 */
    for (i = 0; i < 8; ++i) /* Line 203, Address: 0x1022540 */
      yposi_bak.l = yposi_bak.l >> 1 | yposi_f; /* Line 204, Address: 0x102254c */
    pActwk->xspeed.w = xposi_bak.w.l; /* Line 205, Address: 0x102256c */
    pActwk->yspeed.w = yposi_bak.w.l; /* Line 206, Address: 0x1022578 */
    brunko4_ridechk(pActwk); /* Line 207, Address: 0x1022584 */
  }
} /* Line 209, Address: 0x1022590 */



static void brunko4_posiset(sprite_status* pActwk) { /* Line 213, Address: 0x10225b0 */
  short_union temp;
  unsigned short sin, cos, sinf, cosf, wD3, wD4;
  unsigned char bD0;
  int i;

  temp.b.h = ((char*)pActwk)[62]; /* Line 219, Address: 0x10225d4 */
  temp.b.l = ((char*)pActwk)[63]; /* Line 220, Address: 0x10225e0 */
  if (!(pActwk->userflag.b.h & 16)) /* Line 221, Address: 0x10225ec */
    temp.w -= 128; /* Line 222, Address: 0x1022608 */
  else
    temp.w += 256; /* Line 224, Address: 0x102261c */
  pActwk->actfree[16] = temp.b.h; /* Line 225, Address: 0x1022628 */
  pActwk->actfree[17] = temp.b.l; /* Line 226, Address: 0x1022634 */



  sinset(pActwk->actfree[16], (short*)&sin, (short*)&cos); /* Line 230, Address: 0x1022640 */
  wD3 = wD4 = 0; /* Line 231, Address: 0x1022658 */
  bD0 = pActwk->actfree[18]; /* Line 232, Address: 0x1022664 */
  if (bD0) /* Line 233, Address: 0x1022670 */
  {
    do
    {
      wD3 += sin; /* Line 237, Address: 0x1022678 */
      wD4 += cos; /* Line 238, Address: 0x1022684 */
    } while (--bD0 != 0); /* Line 239, Address: 0x1022690 */
  }

  sinf = wD3 & 32768; /* Line 242, Address: 0x10226a8 */
  cosf = wD4 & 32768; /* Line 243, Address: 0x10226b8 */
  for (i = 4; i > 0; --i) /* Line 244, Address: 0x10226c8 */
    wD3 = wD3 >> 1 | sinf; /* Line 245, Address: 0x10226d4 */
  for (i = 4; i > 0; --i) /* Line 246, Address: 0x10226f8 */
    wD4 = wD4 >> 1 | cosf; /* Line 247, Address: 0x1022704 */
  wD3 += ((unsigned short*)pActwk)[27]; /* Line 248, Address: 0x1022728 */
  wD4 += ((unsigned short*)pActwk)[29]; /* Line 249, Address: 0x1022738 */
  pActwk->yposi.w.h = wD3; /* Line 250, Address: 0x1022748 */
  pActwk->xposi.w.h = wD4; /* Line 251, Address: 0x1022750 */
} /* Line 252, Address: 0x1022758 */
