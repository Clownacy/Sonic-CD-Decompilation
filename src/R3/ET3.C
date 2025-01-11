#include "..\EQU.H"
#include "ET3.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"
#include "..\SCORE.H"

#if defined(R31A)
  #define SPRITE_ET_BASE 562
#elif defined(R31B) || defined(R32A)
  #define SPRITE_ET_BASE 556
#elif defined(R33C) || defined(R33D)
  #define SPRITE_ET_BASE 560
#else
  #define SPRITE_ET_BASE 509
#endif

static void m_init(sprite_status* actionwk);
static void m_wait(sprite_status* actionwk);

static sprite_pattern tpat00 =
{
  1,
  { { -40, 16, 0, SPRITE_ET_BASE } }
};
static sprite_pattern tpat01 =
{
  1,
  { { -40, 16, 0, SPRITE_ET_BASE + 1 } }
};
static sprite_pattern tpat07 =
{
  1,
  { { 0, 0, 0, 0 } }
};
static sprite_pattern tpat02 =
{
  1,
  { { -24, -32, 0, SPRITE_ET_BASE + 7 } }
};
static sprite_pattern tpat03 =
{
  3,
  {
    { -22, -8, 0, SPRITE_ET_BASE + 9 },
    { -24, -32, 0, SPRITE_ET_BASE + 7 },
    { -40, -32, 0, SPRITE_ET_BASE + 8 }
  }
};
static sprite_pattern tpat04 =
{
  4,
  {
    { -22, -8, 0, SPRITE_ET_BASE + 10 },
    { -24, -32, 0, SPRITE_ET_BASE + 13 },
    { -24, -32, 0, SPRITE_ET_BASE + 7 },
    { -40, -32, 0, SPRITE_ET_BASE + 8 }
  }
};
static sprite_pattern tpat05 =
{
  4,
  {
    { -22, -8, 0, SPRITE_ET_BASE + 11 },
    { -24, -32, 0, SPRITE_ET_BASE + 14 },
    { -24, -32, 0, SPRITE_ET_BASE + 7 },
    { -40, -32, 0, SPRITE_ET_BASE + 8 }
  }
};
static sprite_pattern tpat06 =
{
  4,
  {
    { -22, -8, 0, SPRITE_ET_BASE + 12 },
    { -24, -32, 0, SPRITE_ET_BASE + 15 },
    { -24, -32, 0, SPRITE_ET_BASE + 7 },
    { -40, -32, 0, SPRITE_ET_BASE + 8 }
  }
};
sprite_pattern* pat_et[8] =
{
  &tpat00,
  &tpat01,
  &tpat02,
  &tpat03,
  &tpat04,
  &tpat05,
  &tpat06,
  &tpat07
};
static unsigned short tbl0sproffset[11] = { 1087, 1033, 0, 0, 1108, 1024, 0, 0, 0, 0, 0 };
static char tbl0[64] =
{
    1,   0,
    0,   2,
  -40, -20,
    3,  28,
   10,   4,
   18, -18,
    5, -18,
  -10,   6,
    8,  -8,
    8, -18,
   14,  10,
  -10,  10,
   12,  30,
  -10,  15,
    0, -18,
   18,  20,
  -10,  20,
  -10,  18,
   22,   8,
   23,  25,
   13, -10,
   26,  23,
  -22,  28,
   -3, -25,
   30,  10,
   20,  32,
  -10,   2,
   34,  30,
   -8,  35,
   13, -10,
   40, -10,
   10,  -1
};
static char pchg0[6] = { 3, 3, 4, 5, 6, -1 };
static char* pchg[1] = { pchg0 };














void et(sprite_status* actionwk) { /* Line 145, Address: 0x101c880 */
  switch (actionwk->r_no0) /* Line 146, Address: 0x101c88c */
  {
    case 0:
      m_init(actionwk); /* Line 149, Address: 0x101c8cc */
    case 2:
      m_wait(actionwk); /* Line 151, Address: 0x101c8d8 */
      break; /* Line 152, Address: 0x101c8e4 */
    case 4:
      m_die(actionwk); /* Line 154, Address: 0x101c8ec */
      break; /* Line 155, Address: 0x101c8f8 */
    case 6:
      m1wait(actionwk); /* Line 157, Address: 0x101c900 */
      break;
  }
  actionsub(actionwk); /* Line 160, Address: 0x101c90c */
  if (actionwk->r_no0 <= 2) /* Line 161, Address: 0x101c918 */
    frameout_s(actionwk); /* Line 162, Address: 0x101c930 */

} /* Line 164, Address: 0x101c93c */


static void m_init(sprite_status* actionwk) { /* Line 167, Address: 0x101c950 */
  unsigned short* a1;
  unsigned short d0;

  actionwk->r_no0 += 2; /* Line 171, Address: 0x101c960 */
  actionwk->actflg |= 4; /* Line 172, Address: 0x101c970 */
  actionwk->sprpri = 4; /* Line 173, Address: 0x101c980 */
  actionwk->sprhs = 34; /* Line 174, Address: 0x101c98c */
  actionwk->sprhsize = 34; /* Line 175, Address: 0x101c998 */
  actionwk->sprvsize = 32; /* Line 176, Address: 0x101c9a4 */

  a1 = tbl0sproffset; /* Line 178, Address: 0x101c9b0 */
  d0 = (stageno.w + 1 << 2) + (unsigned short)time_flag; /* Line 179, Address: 0x101c9b8 */
  actionwk->sproffset = a1[d0]; /* Line 180, Address: 0x101c9ec */





  actionwk->patbase = pat_et; /* Line 186, Address: 0x101ca04 */

  ((short*)actionwk)[24] = 0; /* Line 188, Address: 0x101ca14 */
  ((short*)actionwk)[26] = actionwk->yposi.w.h; /* Line 189, Address: 0x101ca1c */
  ((short*)actionwk)[23] = 4; /* Line 190, Address: 0x101ca2c */
  ((short*)actionwk)[27] = 1; /* Line 191, Address: 0x101ca38 */

  d0 = 0; /* Line 193, Address: 0x101ca44 */
  if (generate_flag == 0) d0 += 2; /* Line 194, Address: 0x101ca48 */
  if (time_flag == 0) ++d0; /* Line 195, Address: 0x101ca64 */
  actionwk->patno = d0; /* Line 196, Address: 0x101ca80 */
  if (generate_flag == 0 && time_flag == 0) /* Line 197, Address: 0x101ca8c */
  {
    actionwk->colino = 250; /* Line 199, Address: 0x101cab4 */
    actionwk->yposi.w.h -= 16; /* Line 200, Address: 0x101cac0 */
  }
} /* Line 202, Address: 0x101cad0 */

static void m_wait(sprite_status* actionwk) { /* Line 204, Address: 0x101caf0 */
  int d0;
  sprite_status* a1;

  if (generate_flag != 0 || time_flag != 0) return; /* Line 208, Address: 0x101cb04 */
  a_hover(actionwk); /* Line 209, Address: 0x101cb34 */

  if (actionwk->colicnt == 0) goto label1; /* Line 211, Address: 0x101cb40 */
  actionwk->colino = 0; /* Line 212, Address: 0x101cb54 */
  ((short*)actionwk)[23] = 0; /* Line 213, Address: 0x101cb5c */
  actionwk->patno = 7; /* Line 214, Address: 0x101cb64 */
  actionwk->r_no0 += 2; /* Line 215, Address: 0x101cb70 */
  generate_flag = 1; /* Line 216, Address: 0x101cb80 */
  d0 = 150; /* Line 217, Address: 0x101cb8c */
  scoreup(d0); /* Line 218, Address: 0x101cb90 */
  a1 = &actwk[0]; /* Line 219, Address: 0x101cb9c */
  if (hitchk(actionwk, a1)) ride_on_clr(actionwk, a1); /* Line 220, Address: 0x101cba4 */
  return; /* Line 221, Address: 0x101cbcc */
label1:
  hitchk(actionwk, &actwk[0]); /* Line 223, Address: 0x101cbd4 */
  patchg(actionwk, (unsigned char**)pchg); /* Line 224, Address: 0x101cbe8 */
} /* Line 225, Address: 0x101cbfc */

void m_die(sprite_status* actionwk) { /* Line 227, Address: 0x101cc20 */
  sprite_status* a1;
  char d0;
  short d5, d6, a6;

  a6 = ((short*)actionwk)[24]; /* Line 232, Address: 0x101cc3c */
  d0 = tbl0[a6++]; /* Line 233, Address: 0x101cc4c */
  if (d0 < 0) /* Line 234, Address: 0x101cc7c */
  {
    actionwk->r_no0 += 2; /* Line 236, Address: 0x101cc8c */
    ((char*)actionwk)[46] = 8; /* Line 237, Address: 0x101cc9c */
    return; /* Line 238, Address: 0x101cca8 */
  }
  ++((char*)actionwk)[46]; /* Line 240, Address: 0x101ccb0 */
  if (((char*)actionwk)[46] != d0) return; /* Line 241, Address: 0x101ccc0 */
  d5 = tbl0[a6++]; /* Line 242, Address: 0x101cce0 */
  d6 = tbl0[a6++]; /* Line 243, Address: 0x101cd18 */
  ((short*)actionwk)[24] = a6; /* Line 244, Address: 0x101cd50 */
  if (actwkchk(&a1) != 0) return; /* Line 245, Address: 0x101cd58 */
  a1->actno = 24; /* Line 246, Address: 0x101cd6c */
  a1->r_no1 = 1; /* Line 247, Address: 0x101cd78 */
  a1->xposi = actionwk->xposi; /* Line 248, Address: 0x101cd84 */
  a1->yposi = actionwk->yposi; /* Line 249, Address: 0x101cd9c */
  a1->xposi.w.h += d5; /* Line 250, Address: 0x101cdb4 */
  a1->yposi.w.h += d6; /* Line 251, Address: 0x101cdc4 */
  baku_init(a1); /* Line 252, Address: 0x101cdd4 */
  soundset(158); /* Line 253, Address: 0x101cde0 */
} /* Line 254, Address: 0x101cdec */

void m1wait(sprite_status* actionwk) { /* Line 256, Address: 0x101ce10 */
  if (--actionwk->actfree[0]) return; /* Line 257, Address: 0x101ce1c */
  actionwk->r_no0 -= 6; /* Line 258, Address: 0x101ce38 */
  actionwk->yposi.w.h = ((short*)actionwk)[26]; /* Line 259, Address: 0x101ce48 */
  soundset(217); /* Line 260, Address: 0x101ce58 */
} /* Line 261, Address: 0x101ce64 */

void a_hover(sprite_status* actionwk) { /* Line 263, Address: 0x101ce80 */
  unsigned short d0;

  ++((unsigned short*)actionwk)[23]; /* Line 266, Address: 0x101ce8c */
  d0 = ((unsigned short*)actionwk)[23]; /* Line 267, Address: 0x101ce9c */
  d0 &= 7; /* Line 268, Address: 0x101cea8 */
  if (d0 == 0) /* Line 269, Address: 0x101ceb0 */
  {
    d0 = ((unsigned short*)actionwk)[27]; /* Line 271, Address: 0x101cebc */
    actionwk->yposi.w.h += d0; /* Line 272, Address: 0x101cec8 */
  }
  d0 = ((unsigned short*)actionwk)[23]; /* Line 274, Address: 0x101cee0 */
  d0 &= 31; /* Line 275, Address: 0x101ceec */
  if (d0 == 0) ((short*)actionwk)[27] = -((short*)actionwk)[27]; /* Line 276, Address: 0x101cef4 */
} /* Line 277, Address: 0x101cf24 */
