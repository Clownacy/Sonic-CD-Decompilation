#include "..\EQU.H"
#include "DENDEN.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static void m_init(sprite_status* pActwk);
static void m_fall(sprite_status* pActwk);
static void m_move(sprite_status* pActwk);
static short m_check(sprite_status* pActwk);
static void sub(sprite_status* pActwk);

static sprite_pattern pat00 =
{
  1,
  { { -16, -24, 0, 456 } }
};
static sprite_pattern pat01 =
{
  2,
  { {
    { -16, -8, 0, 457 },
    { -16, -24, 0, 458 }
  } }
};
static sprite_pattern pat02 =
{
  2,
  { {
    { -16, -24, 0, 459 },
    { -16, -8, 0, 460 }
  } }
};
static sprite_pattern pat03 =
{
  3,
  { {
    { -16, -24, 0, 461 },
    { -16, -8, 0, 462 },
    { -16, -8, 0, 463 }
  } }
};
static sprite_pattern pat04 =
{
  1,
  { { -16, -16, 0, 464 } }
};
static sprite_pattern pat05 =
{
  2,
  { {
    { -16, -8, 0, 465 },
    { -16, -16, 0, 466 }
  } }
};
static sprite_pattern pat06 =
{
  1,
  { { -16, -20, 0, 467 } }
};
sprite_pattern* pat_denden_e[4] =
{
  &pat00,
  &pat01,
  &pat02,
  &pat03
};
sprite_pattern* pat_denden_b[2] =
{
  &pat04,
  &pat05
};
sprite_pattern* pat_none[1] = { &pat06 };
static unsigned char p00[4] = { 29, 0, 1, 255 };
static unsigned char p01[4] = { 29, 2, 3, 255 };
static unsigned char* pchg[2] =
{
  p00,
  p01
};























































void denden(sprite_status* pActwk) { /* Line 139, Address: 0x1021650 */
  void(*tbl[3])(sprite_status*) = /* Line 140, Address: 0x102165c */
  {
    &m_init,
    &m_fall,
    &m_move
  };

  if (pActwk->userflag.b.h & 128) /* Line 147, Address: 0x1021680 */
  {
    sub(pActwk); /* Line 149, Address: 0x102169c */
    return; /* Line 150, Address: 0x10216a8 */
  }

  if (enemy_suicide(pActwk)) return; /* Line 153, Address: 0x10216b0 */
  tbl[pActwk->r_no0 / 2](pActwk); /* Line 154, Address: 0x10216c4 */
  actionsub(pActwk); /* Line 155, Address: 0x1021700 */
  frameout_s00(pActwk, ((short*)pActwk)[23]); /* Line 156, Address: 0x102170c */

} /* Line 158, Address: 0x1021720 */




static void m_init(sprite_status* pActwk) { /* Line 163, Address: 0x1021730 */
  ((short*)pActwk)[23] = pActwk->xposi.w.h; /* Line 164, Address: 0x102173c */
  pActwk->actflg |= 4; /* Line 165, Address: 0x102174c */
  pActwk->sprpri = 3; /* Line 166, Address: 0x102175c */
  pActwk->sproffset = 9104; /* Line 167, Address: 0x1021768 */
  pActwk->sprhs = 16; /* Line 168, Address: 0x1021774 */
  pActwk->sprhsize = 16; /* Line 169, Address: 0x1021780 */
  pActwk->sprvsize = 15; /* Line 170, Address: 0x102178c */
  pActwk->colino = 47; /* Line 171, Address: 0x1021798 */
  ((int*)pActwk)[12] = -16384; /* Line 172, Address: 0x10217a4 */
  pActwk->r_no0 += 2; /* Line 173, Address: 0x10217b0 */

  if (pActwk->userflag.b.h) pActwk->patbase = pat_denden_b; /* Line 175, Address: 0x10217c0 */
  else pActwk->patbase = pat_denden_e; /* Line 176, Address: 0x10217e8 */

  m_fall(pActwk); /* Line 178, Address: 0x10217f8 */
} /* Line 179, Address: 0x1021804 */




static void m_fall(sprite_status* pActwk) { /* Line 184, Address: 0x1021820 */
  short d1;

  pActwk->yposi.l += 65536; /* Line 187, Address: 0x1021830 */
  d1 = emycol_d(pActwk); /* Line 188, Address: 0x1021844 */
  if (d1 < 0) /* Line 189, Address: 0x1021858 */
  {
    pActwk->yposi.w.h += d1; /* Line 191, Address: 0x1021868 */
    pActwk->r_no0 += 2; /* Line 192, Address: 0x1021878 */
  }
} /* Line 194, Address: 0x1021888 */




static void m_move(sprite_status* pActwk) { /* Line 199, Address: 0x10218a0 */
  sprite_status* pPlayerwk;
  sprite_status* pNewActwk;
  short d0, d1;

  pActwk->xposi.l += ((int*)pActwk)[12]; /* Line 204, Address: 0x10218b8 */
  d0 = pActwk->xposi.w.h; /* Line 205, Address: 0x10218d0 */
  d0 -= ((short*)pActwk)[23]; /* Line 206, Address: 0x10218e0 */
  if (d0 < 0) /* Line 207, Address: 0x10218f4 */
  {
    d0 *= -1; /* Line 209, Address: 0x1021904 */
  }
  if (d0 >= 80) goto label3; /* Line 211, Address: 0x1021910 */
  d1 = emycol_d(pActwk); /* Line 212, Address: 0x1021924 */
  d0 = d1; /* Line 213, Address: 0x1021938 */
  d0 += 7; /* Line 214, Address: 0x1021940 */
  if ((unsigned short)d0 >= 14) goto label3; /* Line 215, Address: 0x102194c */
  pActwk->yposi.w.h += d1; /* Line 216, Address: 0x1021960 */

  if (pActwk->userflag.b.h) goto label2; /* Line 218, Address: 0x1021970 */
  pPlayerwk = &actwk[0]; /* Line 219, Address: 0x1021980 */
  if (m_check(pActwk) == 0) goto label1; /* Line 220, Address: 0x1021988 */
  pActwk->mstno.b.h = 1; /* Line 221, Address: 0x10219a4 */
  if (((short*)pActwk)[33]) goto label2; /* Line 222, Address: 0x10219b0 */
  if (actwkchk(&pNewActwk) != 0) goto label2; /* Line 223, Address: 0x10219c0 */
  pNewActwk->actno = pActwk->actno; /* Line 224, Address: 0x10219d4 */
  pNewActwk->userflag.b.h = -1; /* Line 225, Address: 0x10219e4 */
  pNewActwk->userflag.b.l = pActwk->userflag.b.l; /* Line 226, Address: 0x10219f0 */
  pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 227, Address: 0x1021a00 */
  pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 228, Address: 0x1021a10 */
  pNewActwk->yposi.w.h -= 20; /* Line 229, Address: 0x1021a20 */
  pNewActwk->sproffset = pActwk->sproffset; /* Line 230, Address: 0x1021a30 */
  pNewActwk->patbase = pat_none; /* Line 231, Address: 0x1021a40 */
  pNewActwk->colino = 176; /* Line 232, Address: 0x1021a50 */
  ((short*)pNewActwk)[33] = (unsigned short)(pActwk - actwk); /* Line 233, Address: 0x1021a5c */
  ((short*)pActwk)[33] = (unsigned short)(pNewActwk - actwk); /* Line 234, Address: 0x1021a98 */
  if (pActwk->actflg & 128) /* Line 235, Address: 0x1021ad4 */
  {
    soundset(183); /* Line 237, Address: 0x1021aec */
  }
  goto label2; /* Line 239, Address: 0x1021af8 */
label1:
  pActwk->mstno.b.h = 0; /* Line 241, Address: 0x1021b00 */
  if (((short*)pActwk)[33] == 0) goto label2; /* Line 242, Address: 0x1021b08 */
  frameout(&actwk[((short*)pActwk)[33]]); /* Line 243, Address: 0x1021b20 */
  ((short*)pActwk)[33] = 0; /* Line 244, Address: 0x1021b50 */
label2:
  patchg(pActwk, pchg); /* Line 246, Address: 0x1021b58 */
  return; /* Line 247, Address: 0x1021b6c */
label3:
  ((int*)pActwk)[12] *= -1; /* Line 249, Address: 0x1021b74 */
  pActwk->actflg ^= 1; /* Line 250, Address: 0x1021b84 */
  pActwk->cddat ^= 1; /* Line 251, Address: 0x1021b94 */

} /* Line 253, Address: 0x1021ba4 */


static short m_check(sprite_status* pActwk) { /* Line 256, Address: 0x1021bc0 */
  sprite_status* pPlayerwk;
  short d0;
  short carry_flag;

  pPlayerwk = &actwk[0]; /* Line 261, Address: 0x1021bd4 */
  d0 = pPlayerwk->yposi.w.h; /* Line 262, Address: 0x1021bdc */
  d0 -= pActwk->yposi.w.h; /* Line 263, Address: 0x1021be8 */
  d0 += 120; /* Line 264, Address: 0x1021bfc */
  if ((unsigned short)d0 < 240) /* Line 265, Address: 0x1021c08 */
  {
    carry_flag = 1; /* Line 267, Address: 0x1021c1c */
    d0 = pPlayerwk->xposi.w.h; /* Line 268, Address: 0x1021c28 */
    d0 -= pActwk->xposi.w.h; /* Line 269, Address: 0x1021c34 */
    d0 += 120; /* Line 270, Address: 0x1021c48 */
    if ((unsigned short)d0 < 240) /* Line 271, Address: 0x1021c54 */
    {
      carry_flag = 1; /* Line 273, Address: 0x1021c68 */
    } /* Line 274, Address: 0x1021c74 */
    else
    {
      carry_flag = 0; /* Line 277, Address: 0x1021c7c */
    }
  } /* Line 279, Address: 0x1021c80 */
  else
  {
    carry_flag = 0; /* Line 282, Address: 0x1021c88 */
  }
  return carry_flag; /* Line 284, Address: 0x1021c8c */
} /* Line 285, Address: 0x1021c90 */




static void sub(sprite_status* pActwk) { /* Line 290, Address: 0x1021cb0 */
  sprite_status* pMainwk;

  pMainwk = &actwk[((short*)pActwk)[33]]; /* Line 293, Address: 0x1021cc0 */
  if (pMainwk->actno != 32) /* Line 294, Address: 0x1021ce8 */
  {
    frameout(pActwk); /* Line 296, Address: 0x1021cfc */
    return; /* Line 297, Address: 0x1021d08 */
  }
  if (pActwk->userflag.b.l != pMainwk->userflag.b.l) /* Line 299, Address: 0x1021d10 */
  {
    frameout(pActwk); /* Line 301, Address: 0x1021d34 */
    return; /* Line 302, Address: 0x1021d40 */
  }
  pActwk->xposi.w.h = pMainwk->xposi.w.h; /* Line 304, Address: 0x1021d48 */
  pActwk->yposi.w.h = pMainwk->yposi.w.h; /* Line 305, Address: 0x1021d54 */
  pActwk->yposi.w.h -= 20; /* Line 306, Address: 0x1021d60 */
  actionsub(pActwk); /* Line 307, Address: 0x1021d70 */
} /* Line 308, Address: 0x1021d7c */
