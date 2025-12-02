#include "..\EQU.H"
#include "TOBIRA.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"

#if defined(R82)
  #define SPRITE_TOBIRA_BASE 432
#elif defined(R83)
  #define SPRITE_TOBIRA_BASE 500
#else
  #define SPRITE_TOBIRA_BASE 464
#endif

static char pchg00[4] = { 2, 0, 1, -1 };
static char* pchg[1] = { pchg00 };
static sprite_pattern pat00 =
{
  1,
  { { -8, -16, 0, SPRITE_TOBIRA_BASE } }
};
static sprite_pattern pat01 =
{
  1,
  { { -8, -16, 0, SPRITE_TOBIRA_BASE + 1 } }
};
static sprite_pattern pat02 =
{
  1,
  { { -8, -16, 0, SPRITE_TOBIRA_BASE + 2 } }
};
static sprite_pattern pat03 =
{
  1,
  { { -16, -16, 0, SPRITE_TOBIRA_BASE + 3 } }
};
static sprite_pattern pat04 =
{
  1,
  { { -16, -16, 0, SPRITE_TOBIRA_BASE + 4 } }
};
sprite_pattern* pat_tobira0[2] =
{
  &pat00,
  &pat00
};
sprite_pattern* pat_tobira1[2] =
{
  &pat01,
  &pat02
};
sprite_pattern* pat_tobira2[2] =
{
  &pat03,
  &pat04
};





void tobira(sprite_status* actionwk) { /* Line 63, Address: 0x1023cd0 */
  short a;
  a = ((short*)actionwk)[23]; /* Line 65, Address: 0x1023ce0 */
  if (a != 0) /* Line 66, Address: 0x1023cf0 */
  {
    slave(actionwk, ((short*)actionwk)[23]); /* Line 68, Address: 0x1023d00 */
    return; /* Line 69, Address: 0x1023d14 */
  }
  master(actionwk); /* Line 71, Address: 0x1023d1c */
} /* Line 72, Address: 0x1023d28 */

void master(sprite_status* actionwk) { /* Line 74, Address: 0x1023d40 */
  switch (actionwk->r_no0) /* Line 75, Address: 0x1023d4c */
  {
    case 0:
      m_init(actionwk); /* Line 78, Address: 0x1023d98 */
      break; /* Line 79, Address: 0x1023da4 */
    case 2:
      m_closed(actionwk); /* Line 81, Address: 0x1023dac */
      break; /* Line 82, Address: 0x1023db8 */
    case 4:
      m_open(actionwk); /* Line 84, Address: 0x1023dc0 */
      break; /* Line 85, Address: 0x1023dcc */
    case 6:
      m_opend(actionwk); /* Line 87, Address: 0x1023dd4 */
      break; /* Line 88, Address: 0x1023de0 */
    case 8:
      m_close(actionwk); /* Line 90, Address: 0x1023de8 */
      break;
  }
} /* Line 93, Address: 0x1023df4 */

void m_init(sprite_status* actionwk) { /* Line 95, Address: 0x1023e10 */
  short d0, d1;
  sprite_status* a1;

  actionwk->r_no0 += 2; /* Line 99, Address: 0x1023e1c */
  ((short*)actionwk)[25] = actionwk->yposi.w.h - 16; /* Line 100, Address: 0x1023e2c */


  if (actionwk->userflag.b.h == 0) actionwk->patbase = pat_tobira0; /* Line 103, Address: 0x1023e50 */
  if (actionwk->userflag.b.h == 1) actionwk->patbase = pat_tobira1; /* Line 104, Address: 0x1023e78 */
  if (actionwk->userflag.b.h == 2) actionwk->patbase = pat_tobira2; /* Line 105, Address: 0x1023ea4 */
  if (actwkchk2(actionwk, &a1) != 0) /* Line 106, Address: 0x1023ed0 */
  {
    frameout(actionwk); /* Line 108, Address: 0x1023ee8 */
    return; /* Line 109, Address: 0x1023ef4 */
  }
  a1->actno = actionwk->actno; /* Line 111, Address: 0x1023efc */
  a1->xposi.w.h = actionwk->xposi.w.h; /* Line 112, Address: 0x1023f0c */
  a1->patbase = actionwk->patbase; /* Line 113, Address: 0x1023f1c */
  ((unsigned short*)a1)[23] = actionwk - actwk; /* Line 114, Address: 0x1023f2c */
  ((unsigned short*)actionwk)[24] = a1 - actwk; /* Line 115, Address: 0x1023f60 */
  d0 = d1 = 0; /* Line 116, Address: 0x1023f94 */
  ini_com(actionwk, a1, &d0, &d1); /* Line 117, Address: 0x1023fa4 */
  a1->yposi.w.h -= d0; /* Line 118, Address: 0x1023fbc */
  ((short*)a1)[26] -= d0; /* Line 119, Address: 0x1023fd0 */
  ((short*)a1)[27] -= d1; /* Line 120, Address: 0x1023fe4 */
  a1 = actionwk; /* Line 121, Address: 0x1023ff8 */
  ini_com(actionwk, a1, &d0, &d1); /* Line 122, Address: 0x1024000 */
  a1->yposi.w.h += d0; /* Line 123, Address: 0x1024018 */
  ((short*)a1)[26] += d0; /* Line 124, Address: 0x102402c */
  ((short*)a1)[27] += d1; /* Line 125, Address: 0x1024040 */
} /* Line 126, Address: 0x1024054 */

void ini_com(sprite_status* actionwk, sprite_status* a1, short* d0, short* d1) { /* Line 128, Address: 0x1024070 */
  a1->actflg |= 4; /* Line 129, Address: 0x1024084 */
  a1->sprpri = 3; /* Line 130, Address: 0x1024094 */
  a1->sproffset = 1150; /* Line 131, Address: 0x10240a0 */
  a1->sprhsize = 8; /* Line 132, Address: 0x10240ac */
  a1->sprvsize = 16; /* Line 133, Address: 0x10240b8 */
  a1->yposi.w.h = ((short*)actionwk)[25]; /* Line 134, Address: 0x10240c4 */
  ((short*)a1)[26] = ((short*)actionwk)[25]; /* Line 135, Address: 0x10240d4 */
  ((short*)a1)[27] = ((short*)actionwk)[25]; /* Line 136, Address: 0x10240e4 */
  *d0 = 16; /* Line 137, Address: 0x10240f4 */
  *d1 = 49; /* Line 138, Address: 0x1024100 */
} /* Line 139, Address: 0x102410c */

void m_closed(sprite_status* actionwk) { /* Line 141, Address: 0x1024120 */
  short d0, d4, d5;

  ms_hitchk(actionwk); /* Line 144, Address: 0x1024138 */
  if (actionwk->actfree[21] != 0) /* Line 145, Address: 0x1024144 */
  {
    actionwk->actfree[21] = 0; /* Line 147, Address: 0x1024158 */
  } /* Line 148, Address: 0x1024160 */
  else
  {
    d0 = actionwk->userflag.b.h; /* Line 151, Address: 0x1024168 */
    if (d0 == 0) goto label1; /* Line 152, Address: 0x1024180 */
    d4 = 8; /* Line 153, Address: 0x1024190 */
    d5 = 64; /* Line 154, Address: 0x102419c */
    if (d0 != 1) /* Line 155, Address: 0x10241a8 */
    {
      d4 = -72; /* Line 157, Address: 0x10241bc */
      d5 = 64; /* Line 158, Address: 0x10241c8 */
    }
    if (m_area(actionwk, d4, d5) == 0) goto label1; /* Line 160, Address: 0x10241d4 */
  }

  actionwk->r_no0 += 2; /* Line 163, Address: 0x10241f8 */
label1:
  ms_end(actionwk); /* Line 165, Address: 0x1024208 */
} /* Line 166, Address: 0x1024214 */

void ms_end(sprite_status* actionwk) { /* Line 168, Address: 0x1024230 */
  short ano;

  patchg(actionwk, (unsigned char**)pchg); /* Line 171, Address: 0x1024240 */
  ano = ((unsigned short*)actionwk)[24]; /* Line 172, Address: 0x1024254 */
  actwk[ano].patno = actionwk->patno; /* Line 173, Address: 0x1024264 */

  actionsub(&actwk[ano]); /* Line 175, Address: 0x1024290 */
  actionsub(actionwk); /* Line 176, Address: 0x10242b8 */
  frameout_s(actionwk); /* Line 177, Address: 0x10242c4 */
} /* Line 178, Address: 0x10242d0 */

void m_open(sprite_status* actionwk) { /* Line 180, Address: 0x10242f0 */
  short ano;

  ms_hitchk(actionwk); /* Line 183, Address: 0x1024300 */

  ano = ((unsigned short*)actionwk)[24]; /* Line 185, Address: 0x102430c */
  actionwk->yposi.w.h += 2; /* Line 186, Address: 0x102431c */
  actwk[ano].yposi.w.h -= 2; /* Line 187, Address: 0x102432c */
  if (((short*)actionwk)[27] <= actionwk->yposi.w.h) /* Line 188, Address: 0x1024358 */
  {
    actionwk->r_no0 += 2; /* Line 190, Address: 0x1024384 */
    actionwk->yposi.w.h = ((short*)actionwk)[27]; /* Line 191, Address: 0x1024394 */
    actwk[ano].yposi.w.h = ((short*)&actwk[ano])[27]; /* Line 192, Address: 0x10243a4 */
  }

  ms_end(actionwk); /* Line 195, Address: 0x10243ec */
} /* Line 196, Address: 0x10243f8 */

void m_opend(sprite_status* actionwk) { /* Line 198, Address: 0x1024410 */
  short d0, d4, d5;

  ms_hitchk(actionwk); /* Line 201, Address: 0x1024428 */

  d0 = actionwk->userflag.b.h; /* Line 203, Address: 0x1024434 */
  if (d0 != 0) /* Line 204, Address: 0x102444c */
  {
    d4 = -40; /* Line 206, Address: 0x102445c */
    d5 = 112; /* Line 207, Address: 0x1024468 */
    if (d0 != 1) /* Line 208, Address: 0x1024474 */
    {
      d4 = -72; /* Line 210, Address: 0x1024488 */
      d5 = 112; /* Line 211, Address: 0x1024494 */
    }
    if (m_area(actionwk, d4, d5) == 0) actionwk->r_no0 += 2; /* Line 213, Address: 0x10244a0 */
  }

  ms_end(actionwk); /* Line 216, Address: 0x10244d4 */
} /* Line 217, Address: 0x10244e0 */

void m_close(sprite_status* actionwk) { /* Line 219, Address: 0x1024500 */
  short ano;

  ms_hitchk(actionwk); /* Line 222, Address: 0x1024510 */

  ano = ((unsigned short*)actionwk)[24]; /* Line 224, Address: 0x102451c */
  actionwk->yposi.w.h -= 2; /* Line 225, Address: 0x102452c */
  actwk[ano].yposi.w.h += 2; /* Line 226, Address: 0x102453c */

  if (((short*)actionwk)[26] >= actionwk->yposi.w.h) /* Line 228, Address: 0x1024568 */
  {
    actionwk->r_no0 = 2; /* Line 230, Address: 0x1024594 */
    actionwk->yposi.w.h = ((short*)actionwk)[26]; /* Line 231, Address: 0x10245a0 */
    actwk[ano].yposi.w.h = ((short*)&actwk[ano])[26]; /* Line 232, Address: 0x10245b0 */
  }
  ms_end(actionwk); /* Line 234, Address: 0x10245f8 */
} /* Line 235, Address: 0x1024604 */

short ms_hitchk(sprite_status* actionwk) { /* Line 237, Address: 0x1024620 */
  short ano;

  ano = ((unsigned short*)actionwk)[24]; /* Line 240, Address: 0x1024630 */
  hitchk(&actwk[ano], &actwk[0]); /* Line 241, Address: 0x1024640 */
  hitchk(actionwk, &actwk[0]); /* Line 242, Address: 0x1024670 */
} /* Line 243, Address: 0x1024684 */


short m_area(sprite_status* actionwk, short d4, short d5) { /* Line 246, Address: 0x10246a0 */
  short d0;

  d0 = actwk[0].xposi.w.h - actionwk->xposi.w.h - d4; /* Line 249, Address: 0x10246b4 */
  if ((unsigned short)d5 <= (unsigned short)d0) return 0; /* Line 250, Address: 0x10246f8 */
  d0 = actwk[0].yposi.w.h - ((short*)actionwk)[25] + 48; /* Line 251, Address: 0x1024724 */

  if ((unsigned short)d0 >= 96) return 0; /* Line 253, Address: 0x102475c */
  return 1; /* Line 254, Address: 0x102477c */
} /* Line 255, Address: 0x1024780 */

void slave(sprite_status* actionwk, short ano) { /* Line 257, Address: 0x1024790 */
  if (actwk[ano].actno != 41) /* Line 258, Address: 0x10247a0 */
  {
    frameout(actionwk); /* Line 260, Address: 0x10247d8 */
  }
} /* Line 262, Address: 0x10247e4 */
