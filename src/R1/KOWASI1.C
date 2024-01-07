#include "..\EQU.H"
#include "KOWASI1.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"
extern void soundset(short ReqNo);

sprite_pattern spr_kowasi00 =
{
  1,
  { { -16, -24, 0, 434 } }
};
sprite_pattern spr_kowasi01 =
{
  1,
  { { -16, -24, 0, 435 } }
};
sprite_pattern spr_kowasi02 =
{
  1,
  { { -16, -24, 0, 436 } }
};
sprite_pattern spr_kowasi03 =
{
  1,
  { { -16, -24, 0, 437 } }
};
sprite_pattern spr_kowasi04 =
{
  1,
  { { -16, -24, 0, 438 } }
};
sprite_pattern spr_kowasi05 =
{
  1,
  { { -16, -24, 0, 439 } }
};
sprite_pattern spr_kowasi06 =
{
  1,
  { { -16, -24, 0, 440 } }
};
sprite_pattern spr_kowasi07 =
{
  1,
  { { -16, -24, 0, 441 } }
};
sprite_pattern spr_kowasi08 =
{
  1,
  { { -8, -8, 0, 442 } }
};
sprite_pattern spr_kowasi09 =
{
  1,
  { { -8, -8, 0, 443 } }
};
sprite_pattern spr_kowasi0a =
{
  1,
  { { -8, -8, 0, 444 } }
};
sprite_pattern spr_kowasi0b =
{
  1,
  { { -8, -8, 0, 445 } }
};
sprite_pattern spr_kowasi0c =
{
  1,
  { { -8, -8, 0, 446 } }
};
sprite_pattern spr_kowasi0d =
{
  1,
  { { -8, -8, 0, 447 } }
};
sprite_pattern* pat_kowasi[14] =
{
  &spr_kowasi00,
  &spr_kowasi01,
  &spr_kowasi02,
  &spr_kowasi03,
  &spr_kowasi04,
  &spr_kowasi05,
  &spr_kowasi06,
  &spr_kowasi07,
  &spr_kowasi08,
  &spr_kowasi09,
  &spr_kowasi0a,
  &spr_kowasi0b,
  &spr_kowasi0c,
  &spr_kowasi0d
};

void kowasi(sprite_status* pActwk) {  /* Line 96, Address: 0x101ece0 */
  void(*tbl[3])(sprite_status*) =  /* Line 97, Address: 0x101ecec */
  {
    &m_init,
    &m_wait,
    &m_down
  };

  tbl[pActwk->r_no0 / 2](pActwk);  /* Line 104, Address: 0x101ed10 */
} /* Line 105, Address: 0x101ed4c */







void m_init(sprite_status* pActwk) { /* Line 113, Address: 0x101ed60 */
  pActwk->r_no0 += 2; /* Line 114, Address: 0x101ed6c */
  pActwk->actflg |= 4; /* Line 115, Address: 0x101ed7c */
  pActwk->sprpri = 1; /* Line 116, Address: 0x101ed8c */
  pActwk->sprhs = 16; /* Line 117, Address: 0x101ed98 */
  pActwk->sprhsize = 16; /* Line 118, Address: 0x101eda4 */
  pActwk->sprvsize = 24; /* Line 119, Address: 0x101edb0 */
  pActwk->colino = 239; /* Line 120, Address: 0x101edbc */
  pActwk->sproffset = 50366; /* Line 121, Address: 0x101edc8 */
  pActwk->patbase = pat_kowasi; /* Line 122, Address: 0x101edd4 */
  pActwk->patno = pActwk->userflag.b.h; /* Line 123, Address: 0x101ede4 */

  m_wait(pActwk); /* Line 125, Address: 0x101edf4 */
} /* Line 126, Address: 0x101ee00 */







void m_wait(sprite_status* pActwk) { /* Line 134, Address: 0x101ee10 */
  sprite_status* pActwk_w;
  sprite_status* pPlayerwk;
  unsigned char* pTbl0pat;
  short* pTbl0dposi;
  int* pTbl0speed;
  int speedx;
  int i;

  unsigned char tbl0pat[64] = /* Line 143, Address: 0x101ee34 */
  {
     8,  9,  8, 12, 13, 12,  0,  0,
     8,  9,  8, 10, 11, 10,  0,  0,
    10, 11, 10, 10, 11, 10,  0,  0,
    10, 11, 10, 12, 13, 12,  0,  0,
     9,  8,  9, 13, 12, 13,  0,  0,
     9,  8,  9, 11, 10, 11,  0,  0,
    11, 10, 11, 11, 10, 11,  0,  0,
    11, 10, 11, 13, 12, 13,  0,  0
  };



  short tbl0dposi[12] = /* Line 157, Address: 0x101ee68 */
  {
     -8, -16,
      0,  16,
      0,  32,
     16,   0,
     16,  16,
     16,  32
  };




  int tbl0speed[12] = /* Line 170, Address: 0x101ee9c */
  {
    -194180,  -84144,
    -252434,       0,
    -194180,   84144,
    -194180, -113595,
    -223307,       0,
    -194180,  113595
  };


  pPlayerwk = &actwk[0]; /* Line 181, Address: 0x101eed0 */
  if (pActwk->colicnt) /* Line 182, Address: 0x101eed8 */
  {
    pActwk->colino = pActwk->colicnt = 0; /* Line 184, Address: 0x101eee8 */
    pActwk->r_no0 += 2; /* Line 185, Address: 0x101eefc */
    ((short*)pActwk)[23] = pPlayerwk->xspeed.w; /* Line 186, Address: 0x101ef0c */
    ((short*)pActwk)[25] = pPlayerwk->yspeed.w; /* Line 187, Address: 0x101ef18 */
  } /* Line 188, Address: 0x101ef24 */
  else
  {
    hitchk(pActwk, pPlayerwk); /* Line 191, Address: 0x101ef2c */
    actionsub(pActwk); /* Line 192, Address: 0x101ef3c */
    frameout_s(pActwk); /* Line 193, Address: 0x101ef48 */
    return; /* Line 194, Address: 0x101ef54 */
  }

  soundset(176); /* Line 197, Address: 0x101ef5c */
  pPlayerwk = &actwk[0]; /* Line 198, Address: 0x101ef68 */
  pPlayerwk->xspeed.w /= 2; /* Line 199, Address: 0x101ef70 */
  pTbl0pat = &tbl0pat[pActwk->userflag.b.h * 8]; /* Line 200, Address: 0x101ef90 */

  pActwk_w = pActwk; /* Line 202, Address: 0x101efac */
  pTbl0dposi = tbl0dposi; /* Line 203, Address: 0x101efb4 */
  pTbl0speed = tbl0speed; /* Line 204, Address: 0x101efb8 */
  for (i = 0; i < 6; ++i) /* Line 205, Address: 0x101efbc */
  {
    if (i != 0) /* Line 207, Address: 0x101efc8 */
    {
      if (actwkchk(&pActwk_w) != 0) break; /* Line 209, Address: 0x101efd0 */
      pActwk_w->actno = pActwk->actno; /* Line 210, Address: 0x101efe4 */
      pActwk_w->r_no0 = pActwk->r_no0; /* Line 211, Address: 0x101eff4 */
      pActwk_w->xposi.w.h = pActwk->xposi.w.h; /* Line 212, Address: 0x101f004 */
      pActwk_w->yposi.w.h = pActwk->yposi.w.h; /* Line 213, Address: 0x101f014 */
      pActwk_w->actflg = pActwk->actflg; /* Line 214, Address: 0x101f024 */
      pActwk_w->sprpri = pActwk->sprpri; /* Line 215, Address: 0x101f034 */
      pActwk_w->patbase = pActwk->patbase; /* Line 216, Address: 0x101f044 */
      pActwk_w->sproffset = pActwk->sproffset; /* Line 217, Address: 0x101f054 */
    }
    pActwk_w->sprhs = 8; /* Line 219, Address: 0x101f064 */
    pActwk_w->sprhsize = 8; /* Line 220, Address: 0x101f070 */
    pActwk_w->sprvsize = 8; /* Line 221, Address: 0x101f07c */
    pActwk_w->patno = *pTbl0pat++; /* Line 222, Address: 0x101f088 */
    pActwk_w->xposi.w.h += *pTbl0dposi++; /* Line 223, Address: 0x101f09c */
    pActwk_w->yposi.w.h += *pTbl0dposi++; /* Line 224, Address: 0x101f0b8 */
    speedx = *pTbl0speed++; /* Line 225, Address: 0x101f0d4 */
    *(int*)&pActwk_w->actfree[4] = *pTbl0speed++; /* Line 226, Address: 0x101f0e0 */
    if (pPlayerwk->xspeed.w < 0) speedx = -speedx; /* Line 227, Address: 0x101f0f8 */
    *(int*)&pActwk_w->actfree[0] = speedx; /* Line 228, Address: 0x101f110 */
  } /* Line 229, Address: 0x101f11c */
  m_down(pActwk); /* Line 230, Address: 0x101f12c */
} /* Line 231, Address: 0x101f138 */






void m_down(sprite_status* pActwk) { /* Line 238, Address: 0x101f160 */
  sprite_status* pPlayerwk;
  short y;

  *(int*)&pActwk->actfree[4] += 16384; /* Line 242, Address: 0x101f174 */
  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 243, Address: 0x101f18c */
  pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 244, Address: 0x101f1a8 */
  pPlayerwk = &actwk[0]; /* Line 245, Address: 0x101f1c4 */
  y = pPlayerwk->yposi.w.h; /* Line 246, Address: 0x101f1cc */
  y -= pActwk->yposi.w.h; /* Line 247, Address: 0x101f1d8 */
  if (y >= -223) actionsub(pActwk); /* Line 248, Address: 0x101f1ec */
  else frameout(pActwk); /* Line 249, Address: 0x101f214 */
} /* Line 250, Address: 0x101f220 */
