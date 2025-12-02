#include "..\EQU.H"
#include "NOKOGIRI.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"

#if defined(R83)
  #define SPRITE_NOKOGIRI_BASE 404
#else
  #define SPRITE_NOKOGIRI_BASE 425
#endif

static char p00[4] = { 1, 0, 1, -1 };
static char p01[4] = { 1, 2, 3, -1 };
static char p02[4] = { 1, 4, 5, -1 };
static char p03[4] = { 1, 6, 7, -1 };
static char p04[4] = { 1, 8, 9, -1 };
static char p05[4] = { 1, 10, 11, -1 };
static char p06[4] = { 1, 12, 13, -1 };
static char p07[4] = { 1, 14, 15, -1 };
static char p08[4] = { 1, 16, 17, -1 };
static char* pchg[10] =
{
  p00,
  p01,
  p02,
  p03,
  p04,
  p05,
  p06,
  p07,
  p08,
  p08
};
static sprite_pattern pat00 = { 1, { { -32, -34, 0, SPRITE_NOKOGIRI_BASE } } };
static sprite_pattern pat01 = { 1, { { -32, -34, 0, SPRITE_NOKOGIRI_BASE + 1 } } };
static sprite_pattern pat02 = { 1, { { -43, -43, 0, SPRITE_NOKOGIRI_BASE + 2 } } };
static sprite_pattern pat03 = { 1, { { -43, -43, 0, SPRITE_NOKOGIRI_BASE + 3 } } };
static sprite_pattern pat04 = { 1, { { -52, -54, 0, SPRITE_NOKOGIRI_BASE + 4 } } };
static sprite_pattern pat05 = { 1, { { -52, -54, 0, SPRITE_NOKOGIRI_BASE + 5 } } };
static sprite_pattern pat06 = { 1, { { -63, -63, 0, SPRITE_NOKOGIRI_BASE + 6 } } };
static sprite_pattern pat07 = { 1, { { -63, -63, 0, SPRITE_NOKOGIRI_BASE + 7 } } };
static sprite_pattern pat08 = { 1, { { -72, -74, 0, SPRITE_NOKOGIRI_BASE + 8 } } };
static sprite_pattern pat09 = { 1, { { -72, -74, 0, SPRITE_NOKOGIRI_BASE + 9 } } };
static sprite_pattern pat10 = { 1, { { -83, -83, 0, SPRITE_NOKOGIRI_BASE + 10 } } };
static sprite_pattern pat11 = { 1, { { -83, -83, 0, SPRITE_NOKOGIRI_BASE + 11 } } };
static sprite_pattern pat12 = { 1, { { -92, -94, 0, SPRITE_NOKOGIRI_BASE + 12 } } };
static sprite_pattern pat13 = { 1, { { -92, -94, 0, SPRITE_NOKOGIRI_BASE + 13 } } };
static sprite_pattern pat14 = { 1, { { -103, -103, 0, SPRITE_NOKOGIRI_BASE + 14 } } };
static sprite_pattern pat15 = { 1, { { -103, -103, 0, SPRITE_NOKOGIRI_BASE + 15 } } };
static sprite_pattern pat16 = { 1, { { -112, -114, 0, SPRITE_NOKOGIRI_BASE + 16 } } };
static sprite_pattern pat17 = { 1, { { -112, -114, 0, SPRITE_NOKOGIRI_BASE + 17 } } };
sprite_pattern* pat_nokogiri[20] =
{
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05,
  &pat06,
  &pat07,
  &pat08,
  &pat09,
  &pat10,
  &pat11,
  &pat12,
  &pat13,
  &pat14,
  &pat15,
  &pat16,
  &pat17
};
static sprite_pattern pat_bar0 = { 1, { { -41, -43, 0, SPRITE_NOKOGIRI_BASE + 18 } } };
sprite_pattern* pat_bar[1] = { &pat_bar0 };









void nokogiri(sprite_status* actionwk) { /* Line 86, Address: 0x1023350 */
  if (actionwk->userflag.b.l != 0) /* Line 87, Address: 0x102335c */
  {
    bar(actionwk); /* Line 89, Address: 0x1023374 */
    return; /* Line 90, Address: 0x1023380 */
  }
  switch (actionwk->r_no0) /* Line 92, Address: 0x1023388 */
  {
    case 0:
      act_init(actionwk); /* Line 95, Address: 0x10233d4 */
    case 2:
      act_open(actionwk); /* Line 97, Address: 0x10233e0 */
      break; /* Line 98, Address: 0x10233ec */
    case 4:
      act_opend(actionwk); /* Line 100, Address: 0x10233f4 */
      break; /* Line 101, Address: 0x1023400 */
    case 6:
      act_close(actionwk); /* Line 103, Address: 0x1023408 */
      break; /* Line 104, Address: 0x1023414 */
    case 8:
      act_closed(actionwk); /* Line 106, Address: 0x102341c */
      break;
  }
  patchg(actionwk, (unsigned char**)pchg); /* Line 109, Address: 0x1023428 */
  actionsub(actionwk); /* Line 110, Address: 0x102343c */
  frameout_s00(actionwk, ((short*)actionwk)[29]); /* Line 111, Address: 0x1023448 */
} /* Line 112, Address: 0x102345c */

void act_init(sprite_status* actionwk) { /* Line 114, Address: 0x1023470 */
  sprite_status* a1;
  short d0, d1;

  ((short*)actionwk)[29] = actionwk->xposi.w.h; /* Line 118, Address: 0x1023484 */
  actionwk->actflg |= 4; /* Line 119, Address: 0x1023494 */
  actionwk->sprpri = 3; /* Line 120, Address: 0x10234a4 */
  actionwk->sproffset = 17174; /* Line 121, Address: 0x10234b0 */
  actionwk->patbase = pat_nokogiri; /* Line 122, Address: 0x10234bc */
  actionwk->colino = 169; /* Line 123, Address: 0x10234cc */
  actionwk->sprhsize = 80; /* Line 124, Address: 0x10234d8 */
  actionwk->sprvsize = 80; /* Line 125, Address: 0x10234e4 */

  ((int*)actionwk)[12] = 65536; /* Line 127, Address: 0x10234f0 */
  ((int*)actionwk)[13] = 65536; /* Line 128, Address: 0x10234fc */

  if (actionwk->userflag.b.h & 1) /* Line 130, Address: 0x1023508 */
  {
    ((int*)actionwk)[12] = -((int*)actionwk)[12]; /* Line 132, Address: 0x1023524 */

    actionwk->actflg |= 1; /* Line 134, Address: 0x1023538 */
    actionwk->cddat |= 1; /* Line 135, Address: 0x1023548 */
  }


  if (actionwk->userflag.b.h & 2) /* Line 139, Address: 0x1023558 */
  {
    ((int*)actionwk)[13] = -((int*)actionwk)[13]; /* Line 141, Address: 0x1023574 */

    actionwk->actflg |= 2; /* Line 143, Address: 0x1023588 */
    actionwk->cddat |= 2; /* Line 144, Address: 0x1023598 */
  }

  ((short*)actionwk)[23] = 60; /* Line 147, Address: 0x10235a8 */
  actionwk->r_no0 = 8; /* Line 148, Address: 0x10235b4 */
  if (actionwk->userflag.b.h < 0) /* Line 149, Address: 0x10235c0 */
  {
    actionwk->mstno.b.h = 9; /* Line 151, Address: 0x10235d8 */
    actionwk->r_no0 = 4; /* Line 152, Address: 0x10235e4 */
  }

  if (actwkchk2(actionwk, &a1) != 0) /* Line 155, Address: 0x10235f0 */
  {
    frameout(actionwk); /* Line 157, Address: 0x1023608 */
    return; /* Line 158, Address: 0x1023614 */
  }
  ((unsigned short*)actionwk)[31] = a1 - actwk; /* Line 160, Address: 0x102361c */
  ((unsigned short*)a1)[23] = actionwk - actwk; /* Line 161, Address: 0x1023650 */
  a1->actno = actionwk->actno; /* Line 162, Address: 0x1023684 */
  a1->actflg = actionwk->actflg; /* Line 163, Address: 0x1023694 */
  a1->sproffset = actionwk->sproffset; /* Line 164, Address: 0x10236a4 */
  a1->userflag.b.h = actionwk->userflag.b.h; /* Line 165, Address: 0x10236b4 */
  a1->userflag.b.l = -1; /* Line 166, Address: 0x10236c4 */
  a1->sprpri = actionwk->sprpri - 1; /* Line 167, Address: 0x10236d0 */
  a1->xposi.w.h = actionwk->xposi.w.h; /* Line 168, Address: 0x10236ec */
  a1->yposi.w.h = actionwk->yposi.w.h + 1; /* Line 169, Address: 0x10236fc */
  if (actionwk->userflag.b.h & 128) /* Line 170, Address: 0x1023720 */
  {
    d0 = 80; /* Line 172, Address: 0x102373c */
    d1 = 79; /* Line 173, Address: 0x1023748 */
    if (actionwk->userflag.b.h & 1) d0 = -(d0 - 1); /* Line 174, Address: 0x1023754 */
    if (actionwk->userflag.b.h & 2) d1 = -(d1 - 1); /* Line 175, Address: 0x1023790 */
    a1->xposi.w.h -= d0; /* Line 176, Address: 0x10237cc */
    a1->yposi.w.h -= d1; /* Line 177, Address: 0x10237dc */
  } /* Line 178, Address: 0x10237ec */
  else
  {
    if (actionwk->userflag.b.h & 1) /* Line 181, Address: 0x10237f4 */
    {
      --a1->yposi.w.h; /* Line 183, Address: 0x1023810 */
      ++a1->xposi.w.h; /* Line 184, Address: 0x1023820 */
    }
    if (actionwk->userflag.b.h & 2) /* Line 186, Address: 0x1023830 */
    {
      --a1->yposi.w.h; /* Line 188, Address: 0x102384c */
      --a1->xposi.w.h; /* Line 189, Address: 0x102385c */
    }
  }
} /* Line 192, Address: 0x102386c */

void act_open(sprite_status* actionwk) { /* Line 194, Address: 0x1023890 */
  if (--((short*)actionwk)[23] == 0) /* Line 195, Address: 0x102389c */
  {
    ++actionwk->mstno.b.h; /* Line 197, Address: 0x10238c4 */
    ((short*)actionwk)[23] = 9; /* Line 198, Address: 0x10238d4 */
    if (--((short*)actionwk)[28] == 0) /* Line 199, Address: 0x10238e0 */
    {
      actionwk->r_no0 += 2; /* Line 201, Address: 0x1023908 */
      ((short*)actionwk)[23] = 60; /* Line 202, Address: 0x1023918 */
    }
  }

  actionwk->xposi.l += ((int*)actionwk)[12]; /* Line 206, Address: 0x1023924 */
  actionwk->yposi.l += ((int*)actionwk)[13]; /* Line 207, Address: 0x102393c */
  _soundset(actionwk); /* Line 208, Address: 0x1023954 */
} /* Line 209, Address: 0x1023960 */

void act_opend(sprite_status* actionwk) { /* Line 211, Address: 0x1023970 */
  if (--((short*)actionwk)[23] == 0) /* Line 212, Address: 0x102397c */
  {
    actionwk->r_no0 += 2; /* Line 214, Address: 0x10239a4 */
    ((short*)actionwk)[28] = 9; /* Line 215, Address: 0x10239b4 */
    ((short*)actionwk)[23] = 1; /* Line 216, Address: 0x10239c0 */
  }
  _soundset(actionwk); /* Line 218, Address: 0x10239cc */
} /* Line 219, Address: 0x10239d8 */

void act_close(sprite_status* actionwk) { /* Line 221, Address: 0x10239f0 */
  if (--((short*)actionwk)[23] == 0) /* Line 222, Address: 0x10239fc */
  {
    --actionwk->mstno.b.h; /* Line 224, Address: 0x1023a24 */
    ((short*)actionwk)[23] = 9; /* Line 225, Address: 0x1023a34 */
    if (--((short*)actionwk)[28] == 0) /* Line 226, Address: 0x1023a40 */
    {
      actionwk->r_no0 += 2; /* Line 228, Address: 0x1023a68 */
      ((short*)actionwk)[23] = 60; /* Line 229, Address: 0x1023a78 */
    }
  }

  actionwk->xposi.l -= ((int*)actionwk)[12]; /* Line 233, Address: 0x1023a84 */
  actionwk->yposi.l -= ((int*)actionwk)[13]; /* Line 234, Address: 0x1023a9c */
  _soundset(actionwk); /* Line 235, Address: 0x1023ab4 */
} /* Line 236, Address: 0x1023ac0 */

void act_closed(sprite_status* actionwk) { /* Line 238, Address: 0x1023ad0 */
  if (--((short*)actionwk)[23] == 0) /* Line 239, Address: 0x1023adc */
  {
    actionwk->r_no0 -= 6; /* Line 241, Address: 0x1023b04 */
    ((short*)actionwk)[28] = 9; /* Line 242, Address: 0x1023b14 */
    ((short*)actionwk)[23] = 1; /* Line 243, Address: 0x1023b20 */
  }
  _soundset(actionwk); /* Line 245, Address: 0x1023b2c */
} /* Line 246, Address: 0x1023b38 */

void _soundset(sprite_status* actionwk) { /* Line 248, Address: 0x1023b50 */
  short d0;

  if ((char)actionwk->actflg >= 0) return; /* Line 251, Address: 0x1023b60 */
  ++((short*)actionwk)[30]; /* Line 252, Address: 0x1023b80 */
  d0 = ((short*)actionwk)[30]; /* Line 253, Address: 0x1023b90 */
  d0 &= 31; /* Line 254, Address: 0x1023ba0 */
  if (d0 != 0) return; /* Line 255, Address: 0x1023bac */
  soundset(177); /* Line 256, Address: 0x1023bbc */
} /* Line 257, Address: 0x1023bc8 */

void bar(sprite_status* actionwk) { /* Line 259, Address: 0x1023be0 */
  short ano;

  ano = ((short*)actionwk)[23]; /* Line 262, Address: 0x1023bf0 */
  if (actwk[ano].actno != 39) /* Line 263, Address: 0x1023c00 */
  {
    frameout(actionwk); /* Line 265, Address: 0x1023c34 */
    return; /* Line 266, Address: 0x1023c40 */
  }
  if (actionwk->r_no0) /* Line 268, Address: 0x1023c48 */
  {
    actionsub(actionwk); /* Line 270, Address: 0x1023c58 */
    return; /* Line 271, Address: 0x1023c64 */
  }

  actionwk->r_no0 += 2; /* Line 274, Address: 0x1023c6c */
  actionwk->actflg |= 4; /* Line 275, Address: 0x1023c7c */
  actionwk->patbase = pat_bar; /* Line 276, Address: 0x1023c8c */
  actionwk->sprhsize = 32; /* Line 277, Address: 0x1023c9c */
  actionwk->sprvsize = 32; /* Line 278, Address: 0x1023ca8 */
} /* Line 279, Address: 0x1023cb4 */
