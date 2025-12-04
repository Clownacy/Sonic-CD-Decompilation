#include "..\EQU.H"
#include "HASIRA5.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"

static void m_init(sprite_status* pActwk);
static void m_wait(sprite_status* pActwk);
static void m_down(sprite_status* pActwk);

static sprite_pattern pat00 =
{
  3,
  { {
    { -16, -32, 0, 509 },
    { -16, 24, 0, 510 },
    { -16, -48, 0, 511 }
  } }
};
static sprite_pattern pat01 =
{
  1,
  { { -16, -12, 0, 512 } }
};
static sprite_pattern pat02 =
{
  1,
  { { -8, -8, 0, 513 } }
};
static sprite_pattern pat03 =
{
  1,
  { { -8, -8, 0, 514 } }
};
static sprite_pattern pat04 =
{
  1,
  { { -8, -8, 0, 515 } }
};
static sprite_pattern pat05 =
{
  1,
  { { -8, -8, 0, 516 } }
};
static sprite_pattern pat06 =
{
  1,
  { { -16, -12, 0, 517 } }
};
static sprite_pattern pat07 =
{
  1,
  { { -8, -8, 0, 518 } }
};
sprite_pattern* pat_hasira5[8] =
{
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05,
  &pat06,
  &pat07
};
static unsigned char tbl0patno[8] = { 2, 5, 3, 5, 4, 5, 7, 5 };
static short tbl0dposi[16] =
{
   -8, -24,  16,   0,
    0,  16,  16,  16,
    0,  32,  16,  32,
    0,  48,  16,  48
};
static int tbl0speed[16] =
{
   -77101, -131072,   77101, -131072,
  -163840,  -98304,  163840,  -98304,
  -327680,   32768,  327680,   32768,
  -163840,   65536,  163840,   65536
};











































void hasira5(sprite_status* pActwk) { /* Line 125, Address: 0x10253a0 */
  void(*tbl[3])(sprite_status*) = /* Line 126, Address: 0x10253ac */
  {
    &m_init,
    &m_wait,
    &m_down
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 133, Address: 0x10253d0 */
  actionsub(pActwk); /* Line 134, Address: 0x102540c */
  frameout_s(pActwk); /* Line 135, Address: 0x1025418 */
} /* Line 136, Address: 0x1025424 */




static void m_init(sprite_status* pActwk) { /* Line 141, Address: 0x1025440 */
  pActwk->r_no0 += 2; /* Line 142, Address: 0x102544c */
  pActwk->actflg |= 4; /* Line 143, Address: 0x102545c */
  pActwk->sprpri = 4; /* Line 144, Address: 0x102546c */
  pActwk->sprhs = 16; /* Line 145, Address: 0x1025478 */
  pActwk->sprhsize = 16; /* Line 146, Address: 0x1025484 */
  pActwk->sprvsize = 48; /* Line 147, Address: 0x1025490 */
  pActwk->colino = 238; /* Line 148, Address: 0x102549c */
  pActwk->sproffset = 17515; /* Line 149, Address: 0x10254a8 */
  pActwk->patbase = pat_hasira5; /* Line 150, Address: 0x10254b4 */

  m_wait(pActwk); /* Line 152, Address: 0x10254c4 */
} /* Line 153, Address: 0x10254d0 */




static void m_wait(sprite_status* pActwk) { /* Line 158, Address: 0x10254e0 */
  short* a6;
  int* a5;
  unsigned char* a4;
  sprite_status* a1;
  sprite_status* pPlayerwk;
  unsigned char d6;


  pPlayerwk = &actwk[0]; /* Line 167, Address: 0x1025500 */
  d6 = pActwk->colicnt; /* Line 168, Address: 0x1025508 */
  if (d6) /* Line 169, Address: 0x1025514 */
  {
    pActwk->colicnt = 0; /* Line 171, Address: 0x102551c */
    pPlayerwk->xspeed.w >>= 1; /* Line 172, Address: 0x1025524 */
    pPlayerwk->mspeed.w >>= 1; /* Line 173, Address: 0x1025530 */
    if (hitchk(pActwk, pPlayerwk)) /* Line 174, Address: 0x102553c */
    {
      ride_on_clr(pActwk, pPlayerwk); /* Line 176, Address: 0x1025554 */
    }
  } else /* Line 178, Address: 0x1025564 */
  {
    hitchk(pActwk, pPlayerwk); /* Line 180, Address: 0x102556c */
    return; /* Line 181, Address: 0x102557c */
  }

  soundset(176); /* Line 184, Address: 0x1025584 */
  pActwk->r_no0 += 2; /* Line 185, Address: 0x1025590 */
  pActwk->colino = 0; /* Line 186, Address: 0x10255a0 */
  a6 = tbl0dposi; /* Line 187, Address: 0x10255a8 */
  a5 = tbl0speed; /* Line 188, Address: 0x10255b0 */
  a4 = tbl0patno; /* Line 189, Address: 0x10255b8 */
  d6 = 7; /* Line 190, Address: 0x10255c0 */
  a1 = pActwk; /* Line 191, Address: 0x10255c8 */
  do
  {
    if (d6 != 7) /* Line 194, Address: 0x10255d0 */
    {
      if (actwkchk(&a1) != 0) break; /* Line 196, Address: 0x10255e0 */
      a1->actno = pActwk->actno; /* Line 197, Address: 0x10255f4 */
      a1->r_no0 = pActwk->r_no0; /* Line 198, Address: 0x1025604 */
      a1->xposi.w.h = pActwk->xposi.w.h; /* Line 199, Address: 0x1025614 */
      a1->yposi.w.h = pActwk->yposi.w.h; /* Line 200, Address: 0x1025624 */
      a1->actflg = pActwk->actflg; /* Line 201, Address: 0x1025634 */
      a1->sprpri = pActwk->sprpri; /* Line 202, Address: 0x1025644 */
      a1->patbase = pActwk->patbase; /* Line 203, Address: 0x1025654 */
      a1->sproffset = pActwk->sproffset; /* Line 204, Address: 0x1025664 */
    }
    a1->sprhs = 16; /* Line 206, Address: 0x1025674 */
    a1->sprhsize = 16; /* Line 207, Address: 0x1025680 */
    a1->sprvsize = 12; /* Line 208, Address: 0x102568c */
    a1->xposi.w.h += *a6++; /* Line 209, Address: 0x1025698 */
    a1->yposi.w.h += *a6++; /* Line 210, Address: 0x10256b4 */
    *(int*)&a1->actfree[0] = *a5++; /* Line 211, Address: 0x10256d0 */
    *(int*)&a1->actfree[4] = *a5++; /* Line 212, Address: 0x10256e8 */
    a1->patno = *a4++; /* Line 213, Address: 0x1025700 */
  } while (d6--); /* Line 214, Address: 0x1025714 */


  m_down(pActwk); /* Line 217, Address: 0x1025728 */
} /* Line 218, Address: 0x1025734 */




static void m_down(sprite_status* pActwk) { /* Line 223, Address: 0x1025760 */
  sprite_status* pPlayerwk;
  short d0;

  *(int*)&pActwk->actfree[4] += 16384; /* Line 227, Address: 0x1025774 */
  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 228, Address: 0x102578c */
  pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 229, Address: 0x10257a8 */
  pPlayerwk = &actwk[0]; /* Line 230, Address: 0x10257c4 */
  d0 = pPlayerwk->yposi.w.h; /* Line 231, Address: 0x10257cc */
  d0 -= pActwk->yposi.w.h; /* Line 232, Address: 0x10257d8 */
  if (d0 > -224) actionsub(pActwk); /* Line 233, Address: 0x10257ec */
  else frameout(pActwk); /* Line 234, Address: 0x1025814 */
} /* Line 235, Address: 0x1025820 */
