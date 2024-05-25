#include "..\EQU.H"
#include "..\DIRCOL.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"

typedef struct {
  short dx;
  short dy;
  int sx;
  int sy;
}
init_data;

static void m_init(sprite_status* pActwk);
static void m_wait(sprite_status* pActwk);
static void m_fall(sprite_status* pActwk);

static sprite_pattern pat00 =
{
  1,
  { { -16, -16, 128, 450 } }
};
static sprite_pattern pat01 =
{
  1,
  { { -8, -8, 0, 451 } }
};
static sprite_pattern pat02 =
{
  1,
  { { -8, -8, 0, 452 } }
};
static sprite_pattern pat03 =
{
  1,
  { { -8, -8, 0, 453 } }
};
static sprite_pattern pat04 =
{
  1,
  { { -8, -8, 0, 454 } }
};
sprite_pattern* pat_iwa5[5] =
{
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04
};
































void iwa5(sprite_status* pActwk) { /* Line 85, Address: 0x1020a20 */
  void(*tbl[3])(sprite_status*) = /* Line 86, Address: 0x1020a2c */
  {
    &m_init,
    &m_wait,
    &m_fall
  };

  if (pActwk->userflag.b.h & 128) /* Line 93, Address: 0x1020a50 */
  {
    *(int*)&pActwk->actfree[4] += 16384; /* Line 95, Address: 0x1020a6c */
    pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 96, Address: 0x1020a84 */
    pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 97, Address: 0x1020aa0 */
    actionsub(pActwk); /* Line 98, Address: 0x1020abc */

    if (actwk[0].yposi.w.h - pActwk->yposi.w.h <= -224) /* Line 100, Address: 0x1020ac8 */
      frameout(pActwk); /* Line 101, Address: 0x1020af8 */
  } /* Line 102, Address: 0x1020b04 */
  else
  {
    tbl[pActwk->r_no0 / 2](pActwk); /* Line 105, Address: 0x1020b0c */
    actionsub(pActwk); /* Line 106, Address: 0x1020b48 */
    frameout_s(pActwk); /* Line 107, Address: 0x1020b54 */
  }
} /* Line 109, Address: 0x1020b60 */




static void m_init(sprite_status* pActwk) { /* Line 114, Address: 0x1020b70 */
  pActwk->r_no0 += 2; /* Line 115, Address: 0x1020b7c */
  pActwk->actflg |= 4; /* Line 116, Address: 0x1020b8c */
  pActwk->patno = 0; /* Line 117, Address: 0x1020b9c */
  pActwk->sprpri = 3; /* Line 118, Address: 0x1020ba4 */
  pActwk->sprhs = 16; /* Line 119, Address: 0x1020bb0 */
  pActwk->sprhsize = 16; /* Line 120, Address: 0x1020bbc */
  pActwk->sprvsize = 16; /* Line 121, Address: 0x1020bc8 */
  pActwk->sproffset = 17202; /* Line 122, Address: 0x1020bd4 */
  pActwk->patbase = pat_iwa5; /* Line 123, Address: 0x1020be0 */

  m_wait(pActwk); /* Line 125, Address: 0x1020bf0 */
} /* Line 126, Address: 0x1020bfc */




static void m_wait(sprite_status* pActwk) { /* Line 131, Address: 0x1020c10 */
  sprite_status* pPlayerwk;
  short d0;
  short carry_flag;

  pPlayerwk = &actwk[0]; /* Line 136, Address: 0x1020c28 */
  if (pActwk->userflag.b.h) /* Line 137, Address: 0x1020c30 */
  {

    d0 = pPlayerwk->yposi.w.h; /* Line 140, Address: 0x1020c40 */
    d0 -= pActwk->yposi.w.h; /* Line 141, Address: 0x1020c4c */
    d0 -= 8; /* Line 142, Address: 0x1020c60 */
    if ((unsigned short)d0 < 88) /* Line 143, Address: 0x1020c6c */
    {
      carry_flag = 1; /* Line 145, Address: 0x1020c80 */
      d0 = pPlayerwk->xposi.w.h; /* Line 146, Address: 0x1020c8c */
      d0 -= pActwk->xposi.w.h; /* Line 147, Address: 0x1020c98 */
      d0 += 8; /* Line 148, Address: 0x1020cac */
      if ((unsigned short)d0 < 16) /* Line 149, Address: 0x1020cb8 */
      {
        carry_flag = 1; /* Line 151, Address: 0x1020ccc */
      } /* Line 152, Address: 0x1020cd8 */
      else
      {
        carry_flag = 0; /* Line 155, Address: 0x1020ce0 */
      }
    } /* Line 157, Address: 0x1020ce4 */
    else
    {
      carry_flag = 0; /* Line 160, Address: 0x1020cec */
    }
    if (carry_flag) /* Line 162, Address: 0x1020cf0 */
    {
      pActwk->r_no0 += 2; /* Line 164, Address: 0x1020cf8 */
      pActwk->colino = 248; /* Line 165, Address: 0x1020d08 */
    }
  }
  hitchk(pActwk, pPlayerwk); /* Line 168, Address: 0x1020d14 */
} /* Line 169, Address: 0x1020d24 */




static void m_fall(sprite_status* pActwk) { /* Line 174, Address: 0x1020d40 */
  sprite_status* pPlayerwk;
  sprite_status* pNewActwk;
  short a6;
  short d0, d1;
  unsigned char d6;
  init_data tbl0[4] = /* Line 180, Address: 0x1020d60 */
  {
    { -8, -8,  -65536, -262144 },
    {  8, -8,   65536, -262144 },
    { -8,  8, -131072, -196608 },
    {  8,  8,  131072, -196608 }
  };

  if (pActwk->colicnt == 0) /* Line 188, Address: 0x1020d94 */
  {

    pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 191, Address: 0x1020da8 */
    *(int*)&pActwk->actfree[4] += 16384; /* Line 192, Address: 0x1020dc4 */
    if (emycol_d(pActwk) >= 0) /* Line 193, Address: 0x1020ddc */
    {

      pPlayerwk = &actwk[0]; /* Line 196, Address: 0x1020df8 */
      d0 = pPlayerwk->yposi.w.h; /* Line 197, Address: 0x1020e00 */
      d0 -= pActwk->yposi.w.h; /* Line 198, Address: 0x1020e0c */
      if (d0 <= -224) /* Line 199, Address: 0x1020e20 */
      {
        frameout(pActwk); /* Line 201, Address: 0x1020e34 */
      }
      return; /* Line 203, Address: 0x1020e40 */
    }
  }
  a6 = 0; /* Line 206, Address: 0x1020e48 */
  d6 = 3; /* Line 207, Address: 0x1020e4c */
  do
  {
    if (actwkchk(&pNewActwk) != 0) break; /* Line 210, Address: 0x1020e54 */



    pNewActwk->sprpri = 3; /* Line 214, Address: 0x1020e68 */
    pNewActwk->userflag.b.h = -1; /* Line 215, Address: 0x1020e74 */
    pNewActwk->sprhs = 8; /* Line 216, Address: 0x1020e80 */
    pNewActwk->sprhsize = 8; /* Line 217, Address: 0x1020e8c */
    pNewActwk->sprvsize = 8; /* Line 218, Address: 0x1020e98 */
    pNewActwk->actno = pActwk->actno; /* Line 219, Address: 0x1020ea4 */
    pNewActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 220, Address: 0x1020eb4 */
    pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 221, Address: 0x1020ec4 */
    pNewActwk->actflg = pActwk->actflg; /* Line 222, Address: 0x1020ed4 */
    pNewActwk->patbase = pActwk->patbase; /* Line 223, Address: 0x1020ee4 */
    pNewActwk->sproffset = pActwk->sproffset; /* Line 224, Address: 0x1020ef4 */
    d0 = tbl0[a6].dx; /* Line 225, Address: 0x1020f04 */
    d1 = tbl0[a6].dy; /* Line 226, Address: 0x1020f28 */
    pNewActwk->xposi.w.h += d0; /* Line 227, Address: 0x1020f4c */
    pNewActwk->yposi.w.h += d1; /* Line 228, Address: 0x1020f5c */
    *(int*)&pNewActwk->actfree[0] = tbl0[a6].sx; /* Line 229, Address: 0x1020f6c */
    *(int*)&pNewActwk->actfree[4] = tbl0[a6].sy; /* Line 230, Address: 0x1020f94 */
    ++a6; /* Line 231, Address: 0x1020fbc */
    pNewActwk->patno = d6 + 1; /* Line 232, Address: 0x1020fc8 */
  } while (d6--); /* Line 233, Address: 0x1020fdc */

  pActwk->actno = 24; /* Line 235, Address: 0x1020ff0 */
  pActwk->r_no0 = 0; /* Line 236, Address: 0x1020ffc */
  pActwk->r_no1 = 1; /* Line 237, Address: 0x1021004 */
  pActwk->colino = 0; /* Line 238, Address: 0x1021010 */
  if (pActwk->actflg & 128) /* Line 239, Address: 0x1021018 */
  {
    soundset(158); /* Line 241, Address: 0x1021030 */
  }
} /* Line 243, Address: 0x102103c */
