#include "..\EQU.H"
#include "TEKKYU4.H"

sprite_pattern tekkyu4_pat0 = {
  1,
  { { -16, -16, 0, 469 } }
};
sprite_pattern* pat_tekkyu4[1] = { &tekkyu4_pat0 };

































































void tekkyu4(sprite_status* pActwk) { /* Line 74, Address: 0x1024f00 */
  sprite_status* pMainactwk;

  void(*tekkyu4_acttbl[2])(sprite_status*) = { /* Line 77, Address: 0x1024f10 */
    &tekkyu4init,
    &tekkyu4move
  };


  if (((short*)pActwk)[33]) { /* Line 83, Address: 0x1024f2c */
    pMainactwk = &actwk[((short*)pActwk)[33]]; /* Line 84, Address: 0x1024f3c */
    if (pMainactwk->actno != 56) { /* Line 85, Address: 0x1024f64 */
      frameout(pActwk); /* Line 86, Address: 0x1024f78 */
    } /* Line 87, Address: 0x1024f84 */
    else {


      tekkyu4_acttbl[pActwk->r_no0 / 2](pActwk); /* Line 91, Address: 0x1024f8c */
    }
  }





} /* Line 99, Address: 0x1024fc8 */








void tekkyu4init(sprite_status* pActwk) { /* Line 108, Address: 0x1024fe0 */
  sprite_status *pNewactwk1, *pNewactwk2, *pNewactwk3;
  short wD0;

  ((short*)pActwk)[28] = pActwk->xposi.w.h; /* Line 112, Address: 0x1024ff0 */

  if (actwkchk(&pNewactwk3) != 0) { /* Line 114, Address: 0x1025000 */
    frameout(pActwk); /* Line 115, Address: 0x1025014 */
    return; /* Line 116, Address: 0x1025020 */
  }

  pNewactwk3->actno = pActwk->actno; /* Line 119, Address: 0x1025028 */
  pNewactwk3->r_no0 = 2; /* Line 120, Address: 0x1025038 */
  ((short*)pNewactwk3)[33] = pActwk - actwk; /* Line 121, Address: 0x1025044 */

  if (actwkchk(&pNewactwk2) != 0) { /* Line 123, Address: 0x102507c */
    frameout(pActwk); /* Line 124, Address: 0x1025090 */
    return; /* Line 125, Address: 0x102509c */
  }

  pNewactwk2->actno = pActwk->actno; /* Line 128, Address: 0x10250a4 */
  pNewactwk2->r_no0 = 2; /* Line 129, Address: 0x10250b4 */
  ((short*)pNewactwk2)[33] = pActwk - actwk; /* Line 130, Address: 0x10250c0 */

  if (actwkchk(&pNewactwk1) != 0) { /* Line 132, Address: 0x10250f8 */
    frameout(pActwk); /* Line 133, Address: 0x102510c */
    return; /* Line 134, Address: 0x1025118 */
  }

  pNewactwk1->actno = pActwk->actno; /* Line 137, Address: 0x1025120 */
  pNewactwk1->r_no0 = 2; /* Line 138, Address: 0x1025130 */
  ((short*)pNewactwk1)[33] = pActwk - actwk; /* Line 139, Address: 0x102513c */

  wD0 = -2048; /* Line 141, Address: 0x1025174 */

  if (pActwk->userflag.b.h & 128) wD0 = -wD0; /* Line 143, Address: 0x1025180 */

  ((short*)pNewactwk1)[25] = wD0; /* Line 145, Address: 0x10251a8 */
  ((short*)pNewactwk2)[25] = wD0 * 2; /* Line 146, Address: 0x10251c0 */
  ((short*)pNewactwk3)[25] = wD0 * 3; /* Line 147, Address: 0x10251dc */

  ((short*)pActwk)[26] = 256; /* Line 149, Address: 0x10251fc */
  if (pActwk->userflag.b.h & 128) ((short*)pActwk)[26] *= -1; /* Line 150, Address: 0x1025208 */

  if ((wD0 = pActwk->userflag.b.h) & 128) wD0 = -wD0; /* Line 152, Address: 0x1025234 */

  ((short*)pActwk)[27] = wD0 & 127; /* Line 154, Address: 0x1025274 */

  pActwk->sprpri = 1; /* Line 156, Address: 0x1025290 */
  pNewactwk1->sprpri = 2; /* Line 157, Address: 0x102529c */
  pNewactwk2->sprpri = 3; /* Line 158, Address: 0x10252a8 */
  pNewactwk3->sprpri = 4; /* Line 159, Address: 0x10252b4 */

  act_init_sub(pActwk, pActwk); /* Line 161, Address: 0x10252c0 */
  act_init_sub(pActwk, pNewactwk1); /* Line 162, Address: 0x10252d0 */
  act_init_sub(pActwk, pNewactwk2); /* Line 163, Address: 0x10252e0 */
  act_init_sub(pActwk, pNewactwk3); /* Line 164, Address: 0x10252f0 */
} /* Line 165, Address: 0x1025300 */


void act_init_sub(sprite_status* pActwk, sprite_status* pNewactwk) { /* Line 168, Address: 0x1025320 */
  pNewactwk->actflg |= 4; /* Line 169, Address: 0x102532c */
  pNewactwk->colino = 169; /* Line 170, Address: 0x102533c */
  pNewactwk->sprhs = 16; /* Line 171, Address: 0x1025348 */
  pNewactwk->sprhsize = 16; /* Line 172, Address: 0x1025354 */
  pNewactwk->sprvsize = 16; /* Line 173, Address: 0x1025360 */
  pNewactwk->sproffset = 880; /* Line 174, Address: 0x102536c */
  pNewactwk->patbase = pat_tekkyu4; /* Line 175, Address: 0x1025378 */
  pNewactwk->r_no0 = 2; /* Line 176, Address: 0x1025388 */
  ((short*)pNewactwk)[23] = pActwk->xposi.w.h; /* Line 177, Address: 0x1025394 */
  ((short*)pNewactwk)[24] = pActwk->yposi.w.h; /* Line 178, Address: 0x10253a4 */
  ((short*)pNewactwk)[26] = ((short*)pActwk)[26]; /* Line 179, Address: 0x10253b4 */
  ((short*)pNewactwk)[27] = ((short*)pActwk)[27]; /* Line 180, Address: 0x10253c4 */
} /* Line 181, Address: 0x10253d4 */








void tekkyu4move(sprite_status* pActwk) { /* Line 190, Address: 0x10253e0 */
  unsigned short wD0, wD1;

  ((unsigned short*)pActwk)[25] += ((unsigned short*)pActwk)[26]; /* Line 193, Address: 0x10253ec */


  sinset(((short*)pActwk)[25] >> 8, &wD0, &wD1); /* Line 196, Address: 0x1025404 */





  wD0 = (short)wD0 >> ((unsigned short*)pActwk)[27]; /* Line 202, Address: 0x102542c */
  wD1 = (short)wD1 >> ((unsigned short*)pActwk)[27]; /* Line 203, Address: 0x1025458 */




  pActwk->xposi.w.h = ((short*)pActwk)[23] + (short)wD1; /* Line 208, Address: 0x1025484 */
  pActwk->yposi.w.h = ((short*)pActwk)[24] + (short)wD0; /* Line 209, Address: 0x10254bc */

  actionsub(pActwk); /* Line 211, Address: 0x10254f4 */

  if (!((short*)pActwk)[33]) frameout_s(pActwk); /* Line 213, Address: 0x1025500 */

} /* Line 215, Address: 0x102551c */
