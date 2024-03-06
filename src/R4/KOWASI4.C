#include "..\EQU.H"
#include "KOWASI4.H"

void m_init(sprite_status* pActwk);
void m_wait(sprite_status* pActwk);
void m_down(sprite_status* pActwk);
void m_make(sprite_status* pActwk);

static sprite_pattern pat00 = {
  1,
  { { -16, -16, 0, 484 } }
};
static sprite_pattern pat01 = {
  1,
  { { -8, -8, 0, 485 } }
};
sprite_pattern* pat_kowasi4[2] = {
  &pat00,
  &pat01
};
static void(*kowasi4_act_tbl[3])(sprite_status*) = {
  &m_init,
  &m_wait,
  &m_down
};




































































void kowasi4(sprite_status* pActwk) { /* Line 94, Address: 0x102a820 */
  kowasi4_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 95, Address: 0x102a82c */
} /* Line 96, Address: 0x102a870 */





static void m_init(sprite_status* pActwk) { /* Line 102, Address: 0x102a880 */
  pActwk->r_no0 += 2; /* Line 103, Address: 0x102a88c */
  pActwk->actflg |= 4; /* Line 104, Address: 0x102a89c */
  pActwk->sprpri = 1; /* Line 105, Address: 0x102a8ac */
  pActwk->sprhs = pActwk->sprhsize = pActwk->sprvsize = 16; /* Line 106, Address: 0x102a8b8 */
  pActwk->colino = 243; /* Line 107, Address: 0x102a8dc */
  pActwk->sproffset = 17252; /* Line 108, Address: 0x102a8e8 */
  pActwk->patbase = pat_kowasi4; /* Line 109, Address: 0x102a8f4 */

  m_wait(pActwk); /* Line 111, Address: 0x102a904 */
} /* Line 112, Address: 0x102a910 */





static void m_wait(sprite_status* pActwk) { /* Line 118, Address: 0x102a920 */
  if (pActwk->colicnt) { /* Line 119, Address: 0x102a92c */
    pActwk->colino = pActwk->colicnt = 0; /* Line 120, Address: 0x102a93c */
    pActwk->r_no0 += 2; /* Line 121, Address: 0x102a950 */
    ((short*)pActwk)[23] = actwk[0].xspeed.w; /* Line 122, Address: 0x102a960 */
    ((short*)pActwk)[25] = actwk[0].yspeed.w; /* Line 123, Address: 0x102a970 */
    if (hitchk(pActwk, &actwk[0]) != 0) { /* Line 124, Address: 0x102a980 */
      ride_on_clr(pActwk, &actwk[0]); /* Line 125, Address: 0x102a99c */
    }


    m_make(pActwk); /* Line 129, Address: 0x102a9b0 */
    return; /* Line 130, Address: 0x102a9bc */
  }


  hitchk(pActwk, &actwk[0]); /* Line 134, Address: 0x102a9c4 */
  actionsub(pActwk); /* Line 135, Address: 0x102a9d8 */
  frameout_s(pActwk); /* Line 136, Address: 0x102a9e4 */
} /* Line 137, Address: 0x102a9f0 */





static void m_down(sprite_status* pActwk) { /* Line 143, Address: 0x102aa00 */
  *(int*)&pActwk->actfree[4] += 16384; /* Line 144, Address: 0x102aa0c */
  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 145, Address: 0x102aa24 */
  pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 146, Address: 0x102aa40 */
  if (actwk[0].yposi.w.h - pActwk->yposi.w.h < -223) { /* Line 147, Address: 0x102aa5c */

    frameout(pActwk); /* Line 149, Address: 0x102aa8c */
  } else { /* Line 150, Address: 0x102aa98 */
    actionsub(pActwk); /* Line 151, Address: 0x102aaa0 */
  }
} /* Line 153, Address: 0x102aaac */





static void m_make(sprite_status* pActwk) { /* Line 159, Address: 0x102aac0 */
  short tbl0dposi[8] = { /* Line 160, Address: 0x102aae4 */
    -8, -8,
    16,  0,
     0, 16,
    16, 16
  };
  int tbl0speed[24] = { /* Line 166, Address: 0x102ab18 */
     -84144, -393216,   84144, -393216,
    -189326, -262144,  189326, -262144,
    -252434,  -84144, -189326, -189326,
    -252434,   84144, -189326,  189326,
     252434,  -84144,  189326, -189326,
     252434,   84144,  189326,  189326
  };
  short* pPosi;
  short spdwk1, spdwk2;
  short yspdwk;
  int* pSpeed;
  int i;
  sprite_status* pNewact;

  soundset(176); /* Line 181, Address: 0x102ab4c */

  pPosi = tbl0dposi; /* Line 183, Address: 0x102ab58 */
  pSpeed = tbl0speed; /* Line 184, Address: 0x102ab5c */
  spdwk1 = spdwk2 = ((short*)pActwk)[23]; /* Line 185, Address: 0x102ab60 */
  if (spdwk1 < 0) { /* Line 186, Address: 0x102ab78 */
    spdwk1 = -spdwk1; /* Line 187, Address: 0x102ab88 */
  }


  if ((yspdwk = ((short*)pActwk)[25]) < 0) { /* Line 191, Address: 0x102ab94 */
    yspdwk = -yspdwk; /* Line 192, Address: 0x102abb4 */
  }


  if (spdwk1 <= yspdwk) { /* Line 196, Address: 0x102abc0 */
    pSpeed += 8; /* Line 197, Address: 0x102abdc */
    if (spdwk2 < 0) { /* Line 198, Address: 0x102abe0 */
      pSpeed += 8; /* Line 199, Address: 0x102abf0 */
    }
  }


  actwk[0].xspeed.w = actwk[0].yspeed.w = actwk[0].mspeed.w = 0; /* Line 204, Address: 0x102abf4 */
  pNewact = pActwk; /* Line 205, Address: 0x102ac1c */
  for (i = 0; i < 4; ++i) { /* Line 206, Address: 0x102ac24 */
    if (i != 0) { /* Line 207, Address: 0x102ac30 */
      if (actwkchk(&pNewact) != 0) break; /* Line 208, Address: 0x102ac38 */


      pNewact->actno = pActwk->actno; /* Line 211, Address: 0x102ac4c */
      pNewact->r_no0 = pActwk->r_no0; /* Line 212, Address: 0x102ac5c */
      pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 213, Address: 0x102ac6c */
      pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 214, Address: 0x102ac7c */
      pNewact->actflg = pActwk->actflg; /* Line 215, Address: 0x102ac8c */
      pNewact->sprpri = pActwk->sprpri; /* Line 216, Address: 0x102ac9c */
      pNewact->patbase = pActwk->patbase; /* Line 217, Address: 0x102acac */
      pNewact->sproffset = pActwk->sproffset; /* Line 218, Address: 0x102acbc */
    }


    pNewact->patno = 1; /* Line 222, Address: 0x102accc */
    pNewact->sprhs = pNewact->sprhsize = pNewact->sprvsize = 8; /* Line 223, Address: 0x102acd8 */
    pNewact->xposi.w.h += *pPosi++; /* Line 224, Address: 0x102acfc */
    pNewact->yposi.w.h += *pPosi++; /* Line 225, Address: 0x102ad18 */
    *(int*)&pActwk->actfree[0] = *pSpeed++; /* Line 226, Address: 0x102ad34 */
    *(int*)&pActwk->actfree[4] = *pSpeed++; /* Line 227, Address: 0x102ad4c */
  } /* Line 228, Address: 0x102ad64 */


  m_down(pActwk); /* Line 231, Address: 0x102ad74 */
} /* Line 232, Address: 0x102ad80 */
