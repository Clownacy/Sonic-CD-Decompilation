#include "..\EQU.H"
#include "KOWASI5.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"

static void m_init(sprite_status* pActwk);
static void m_wait(sprite_status* pActwk);
static void m_down(sprite_status* pActwk);
static void m_make(sprite_status* pActwk);

static sprite_pattern pat00 = {
  1,
  { { -8, -24, 0, 487 } }
};
static sprite_pattern pat01 = {
  1,
  { { -8, -24, 0, 488 } }
};
static sprite_pattern pat02 = {
  1,
  { { -8, -8, 0, 489 } }
};
static sprite_pattern pat03 = {
  1,
  { { -8, -8, 0, 490 } }
};
static sprite_pattern pat04 = {
  1,
  { { -8, -8, 0, 491 } }
};
static sprite_pattern pat05 = {
  1,
  { { -8, -8, 0, 492 } }
};
sprite_pattern* pat_kowasi[6] = {
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05
};
static void(*kowasi_act_tbl[3])(sprite_status*) = {
  &m_init,
  &m_wait,
  &m_down
};





























































void kowasi(sprite_status* pActwk) { /* Line 111, Address: 0x1024720 */
  kowasi_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 112, Address: 0x102472c */
} /* Line 113, Address: 0x1024770 */





static void m_init(sprite_status* pActwk) { /* Line 119, Address: 0x1024780 */
  pActwk->r_no0 += 2; /* Line 120, Address: 0x102478c */
  pActwk->actflg |= 4; /* Line 121, Address: 0x102479c */
  pActwk->sprpri = 1; /* Line 122, Address: 0x10247ac */
  pActwk->sprhs = pActwk->sprhsize = 8; /* Line 123, Address: 0x10247b8 */
  pActwk->sprvsize = 8; /* Line 124, Address: 0x10247d0 */
  pActwk->colino = 243; /* Line 125, Address: 0x10247dc */
  pActwk->sproffset = 17575; /* Line 126, Address: 0x10247e8 */
  pActwk->patbase = pat_kowasi; /* Line 127, Address: 0x10247f4 */

  pActwk->patno = pActwk->userflag.b.h & 1; /* Line 129, Address: 0x1024804 */
  if (pActwk->userflag.b.h == 2) { /* Line 130, Address: 0x1024824 */
    pActwk->actflg |= 1; /* Line 131, Address: 0x1024840 */
    pActwk->cddat |= 1; /* Line 132, Address: 0x1024850 */
  }


  m_wait(pActwk); /* Line 136, Address: 0x1024860 */
} /* Line 137, Address: 0x102486c */





static void m_wait(sprite_status* pActwk) { /* Line 143, Address: 0x1024880 */
  if (pActwk->colicnt) { /* Line 144, Address: 0x102488c */
    pActwk->colino = pActwk->colicnt = 0; /* Line 145, Address: 0x102489c */
    pActwk->r_no0 += 2; /* Line 146, Address: 0x10248b0 */
    ((short*)pActwk)[23] = actwk[0].xspeed.w; /* Line 147, Address: 0x10248c0 */
    ((short*)pActwk)[25] = actwk[0].yspeed.w; /* Line 148, Address: 0x10248d0 */
    if (hitchk(pActwk, &actwk[0])) { /* Line 149, Address: 0x10248e0 */
      ride_on_clr(pActwk, &actwk[0]); /* Line 150, Address: 0x10248fc */
    }


    m_make(pActwk); /* Line 154, Address: 0x1024910 */
    return; /* Line 155, Address: 0x102491c */
  }


  hitchk(pActwk, &actwk[0]); /* Line 159, Address: 0x1024924 */
  actionsub(pActwk); /* Line 160, Address: 0x1024938 */
  frameout_s(pActwk); /* Line 161, Address: 0x1024944 */
} /* Line 162, Address: 0x1024950 */





static void m_down(sprite_status* pActwk) { /* Line 168, Address: 0x1024960 */
  *(int*)&pActwk->actfree[4] += 16384; /* Line 169, Address: 0x102496c */
  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 170, Address: 0x1024984 */
  pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 171, Address: 0x10249a0 */
  if (actwk[0].yposi.w.h - pActwk->yposi.w.h <= -224) { /* Line 172, Address: 0x10249bc */

    frameout(pActwk); /* Line 174, Address: 0x10249ec */
  } else { /* Line 175, Address: 0x10249f8 */
    actionsub(pActwk); /* Line 176, Address: 0x1024a00 */
  }
} /* Line 178, Address: 0x1024a0c */





static void m_make(sprite_status* pActwk) { /* Line 184, Address: 0x1024a20 */
  unsigned char* pPat;
  short* pPosiy;
  int* pSpeed;
  int spdwk;
  int i;
  sprite_status* pNewact;
  static int tbl0speed[6] = {
    -194180, -84144,
    -252434,      0,
    -194180,  84144
  };
  static unsigned char tbl0pat[6] = {
    2, 3, 4, 5, 5, 5
  };
  static short tbl0dposiy[3] = {
    -16, 0, 16
  };

  soundset(176); /* Line 203, Address: 0x1024a40 */

  pPosiy = tbl0dposiy; /* Line 205, Address: 0x1024a4c */
  pPat = tbl0pat; /* Line 206, Address: 0x1024a54 */
  pSpeed = tbl0speed; /* Line 207, Address: 0x1024a5c */

  if (pActwk->userflag.b.h & 1) { /* Line 209, Address: 0x1024a64 */
    pPat += 3; /* Line 210, Address: 0x1024a80 */
  }


  actwk[0].xspeed.w >>= 1; /* Line 214, Address: 0x1024a84 */

  pNewact = pActwk; /* Line 216, Address: 0x1024a98 */
  for (i = 0; i < 3; ++i) { /* Line 217, Address: 0x1024aa0 */

    if (i != 0) { /* Line 219, Address: 0x1024aac */
      if (actwkchk(&pNewact) != 0) break; /* Line 220, Address: 0x1024ab4 */



      pNewact->actno = pActwk->actno; /* Line 224, Address: 0x1024ac8 */
      pNewact->r_no0 = pActwk->r_no0; /* Line 225, Address: 0x1024ad8 */
      pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 226, Address: 0x1024ae8 */
      pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 227, Address: 0x1024af8 */
      pNewact->actflg = pActwk->actflg; /* Line 228, Address: 0x1024b08 */
      pNewact->sprpri = pActwk->sprpri; /* Line 229, Address: 0x1024b18 */
      pNewact->patbase = pActwk->patbase; /* Line 230, Address: 0x1024b28 */
      pNewact->sproffset = pActwk->sproffset; /* Line 231, Address: 0x1024b38 */
    }


    pNewact->patno = *pPat++; /* Line 235, Address: 0x1024b48 */
    pNewact->sprhs = pNewact->sprhsize = pNewact->sprvsize = 8; /* Line 236, Address: 0x1024b5c */
    pNewact->yposi.w.h += *pPosiy++; /* Line 237, Address: 0x1024b80 */
    spdwk = *pSpeed++; /* Line 238, Address: 0x1024b9c */
    *(int*)&pNewact->actfree[4] = *pSpeed++; /* Line 239, Address: 0x1024ba8 */

    if (actwk[0].xspeed.w < 0) { /* Line 241, Address: 0x1024bc0 */
      spdwk *= -1; /* Line 242, Address: 0x1024bd8 */
    }


    *(int*)&pNewact->actfree[0] = spdwk; /* Line 246, Address: 0x1024bdc */
  } /* Line 247, Address: 0x1024be8 */


  m_down(pActwk); /* Line 250, Address: 0x1024bf8 */
} /* Line 251, Address: 0x1024c04 */
