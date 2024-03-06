#include "..\EQU.H"
#include "HARID4.H"

void act_init(sprite_status* pActwk);
void act_wait(sprite_status* pActwk);
void act_slide(sprite_status* pActwk);
void act_slide1(sprite_status* pActwk);
void act_down(sprite_status* pActwk);
void act_down1(sprite_status* pActwk);
void act_stop(sprite_status* pActwk);

static sprite_pattern pat00 = {
  2,
  {
    { -16, -64, 0, 445 },
    { -16, 32, 0, 444 }
  }
};
static sprite_pattern pat01;
sprite_pattern* pat_harid4[2] = {
  &pat00,
  &pat01
};
static void(*hari4_act_tbl[7])(sprite_status*) = {
  &act_init,
  &act_wait,
  &act_slide,
  &act_slide1,
  &act_down,
  &act_down1,
  &act_stop
};






















































































void harid4(sprite_status* pActwk) { /* Line 119, Address: 0x101cf50 */
  if (pActwk->userflag.b.h & 128) { /* Line 120, Address: 0x101cf5c */

    if (actwk[((short*)pActwk)[33]].actno != 50) { /* Line 122, Address: 0x101cf78 */
      frameout(pActwk); /* Line 123, Address: 0x101cfb4 */
    }

    actionsub(pActwk); /* Line 126, Address: 0x101cfc0 */
  } /* Line 127, Address: 0x101cfcc */
  else {
    if (pActwk->r_no0 == 0 || pActwk->actflg & 128) { /* Line 129, Address: 0x101cfd4 */

      hari4_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 131, Address: 0x101d000 */
      hitchk(pActwk, &actwk[0]); /* Line 132, Address: 0x101d044 */
    }


    actionsub(pActwk); /* Line 136, Address: 0x101d058 */
    frameout_s(pActwk); /* Line 137, Address: 0x101d064 */
  }
} /* Line 139, Address: 0x101d070 */





static void act_init(sprite_status* pActwk) { /* Line 145, Address: 0x101d080 */
  int xacwk;
  sprite_status* pNewact;

  pActwk->r_no0 += 2; /* Line 149, Address: 0x101d090 */
  pActwk->actflg |= 4; /* Line 150, Address: 0x101d0a0 */
  pActwk->sprpri = 3; /* Line 151, Address: 0x101d0b0 */
  pActwk->sprhs = 16; /* Line 152, Address: 0x101d0bc */
  pActwk->sprhsize = 16; /* Line 153, Address: 0x101d0c8 */
  pActwk->sprvsize = 64; /* Line 154, Address: 0x101d0d4 */
  pActwk->sproffset = 928; /* Line 155, Address: 0x101d0e0 */
  pActwk->patbase = pat_harid4; /* Line 156, Address: 0x101d0ec */

  if (waterposi_m >= pActwk->yposi.w.h) { /* Line 158, Address: 0x101d0fc */
    xacwk = 12288; /* Line 159, Address: 0x101d128 */
  } else { /* Line 160, Address: 0x101d12c */
    xacwk = 4096; /* Line 161, Address: 0x101d134 */
  }
  ((int*)pActwk)[14] = xacwk; /* Line 163, Address: 0x101d138 */

  if (actwkchk2(pActwk, &pNewact) == 0) { /* Line 165, Address: 0x101d140 */
    pNewact->actno = pActwk->actno; /* Line 166, Address: 0x101d158 */
    pNewact->userflag.b.h = -1; /* Line 167, Address: 0x101d168 */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 168, Address: 0x101d174 */
    pNewact->yposi.w.h = pActwk->yposi.w.h + 48; /* Line 169, Address: 0x101d184 */
    ((short*)pNewact)[33] = pActwk - actwk; /* Line 170, Address: 0x101d1a8 */
    ((short*)pActwk)[32] = pNewact - actwk; /* Line 171, Address: 0x101d1e0 */
    pNewact->colino = 176; /* Line 172, Address: 0x101d218 */
    pNewact->actflg = pActwk->actflg; /* Line 173, Address: 0x101d224 */
    pNewact->sprpri = pActwk->sprpri; /* Line 174, Address: 0x101d234 */
    pNewact->sprhs = 16; /* Line 175, Address: 0x101d244 */
    pNewact->sprhsize = 16; /* Line 176, Address: 0x101d250 */
    pNewact->sprvsize = 16; /* Line 177, Address: 0x101d25c */
    pNewact->sproffset = 928; /* Line 178, Address: 0x101d268 */
    pNewact->patbase = pat_harid4; /* Line 179, Address: 0x101d274 */
    pNewact->patno = 1; /* Line 180, Address: 0x101d284 */
  }


} /* Line 184, Address: 0x101d290 */





static void act_wait(sprite_status* pActwk) { /* Line 190, Address: 0x101d2b0 */
  short wk;

  wk = actwk[0].yposi.w.h - pActwk->yposi.w.h; /* Line 193, Address: 0x101d2bc */
  wk -= 64; /* Line 194, Address: 0x101d2f0 */
  if ((unsigned short)wk >= 128) return; /* Line 195, Address: 0x101d2fc */



  wk = actwk[0].xposi.w.h - pActwk->xposi.w.h; /* Line 199, Address: 0x101d310 */
  wk += 16; /* Line 200, Address: 0x101d344 */
  if ((unsigned short)wk >= 32) return; /* Line 201, Address: 0x101d350 */




  pActwk->r_no0 += 2; /* Line 206, Address: 0x101d364 */
  pActwk->yspeed.w = 256; /* Line 207, Address: 0x101d374 */
  ((short*)pActwk)[27] = 20; /* Line 208, Address: 0x101d380 */
} /* Line 209, Address: 0x101d38c */





static void act_slide(sprite_status* pActwk) { /* Line 215, Address: 0x101d3a0 */
  int spdwk;

  spdwk = *(int*)&pActwk->actfree[0]; /* Line 218, Address: 0x101d3ac */
  pActwk->yposi.l += spdwk; /* Line 219, Address: 0x101d3b8 */
  actwk[((short*)pActwk)[32]].yposi.l += spdwk; /* Line 220, Address: 0x101d3c8 */
  *(int*)&pActwk->actfree[0] += 8192; /* Line 221, Address: 0x101d3fc */

  if (--((short*)pActwk)[27] < 0) { /* Line 223, Address: 0x101d414 */
    pActwk->r_no0 += 2; /* Line 224, Address: 0x101d43c */
    *(int*)&pActwk->actfree[0] = 0; /* Line 225, Address: 0x101d44c */
    ((short*)pActwk)[27] = 30; /* Line 226, Address: 0x101d458 */
  }
} /* Line 228, Address: 0x101d464 */





static void act_slide1(sprite_status* pActwk) { /* Line 234, Address: 0x101d480 */
  if (--((short*)pActwk)[27] < 0) { /* Line 235, Address: 0x101d488 */
    pActwk->r_no0 += 2; /* Line 236, Address: 0x101d4b0 */
  }
} /* Line 238, Address: 0x101d4c0 */





static void act_down(sprite_status* pActwk) { /* Line 244, Address: 0x101d4d0 */
  int spdwk;
  short ret;

  spdwk = *(int*)&pActwk->actfree[0]; /* Line 248, Address: 0x101d4e4 */
  pActwk->yposi.l += spdwk; /* Line 249, Address: 0x101d4f0 */
  actwk[((short*)pActwk)[32]].yposi.w.l += spdwk; /* Line 250, Address: 0x101d500 */
  *(int*)&pActwk->actfree[0] += ((int*)pActwk)[14]; /* Line 251, Address: 0x101d534 */

  if ((ret = emycol_d(pActwk)) < 0) { /* Line 253, Address: 0x101d554 */
    pActwk->r_no0 += 2; /* Line 254, Address: 0x101d580 */
    pActwk->yposi.w.h += ret; /* Line 255, Address: 0x101d590 */
    pActwk->yspeed.w = 0; /* Line 256, Address: 0x101d5a0 */
    *(int*)&pActwk->actfree[4] = 32; /* Line 257, Address: 0x101d5a8 */

    frameout(&actwk[((short*)pActwk)[32]]); /* Line 259, Address: 0x101d5b8 */
  }
} /* Line 261, Address: 0x101d5e8 */





static void act_down1(sprite_status* pActwk) { /* Line 267, Address: 0x101d600 */
  int spdwk;

  spdwk = *(int*)&pActwk->actfree[0]; /* Line 270, Address: 0x101d60c */
  pActwk->yposi.l += spdwk; /* Line 271, Address: 0x101d618 */

  if ((*(int*)&pActwk->actfree[4] -= spdwk) < 0) { /* Line 273, Address: 0x101d628 */
    pActwk->r_no0 += 2; /* Line 274, Address: 0x101d648 */
  }
} /* Line 276, Address: 0x101d658 */





static void act_stop(sprite_status* pActwk) { /* Line 282, Address: 0x101d670 */

  pActwk = pActwk; /* Line 284, Address: 0x101d678 */
} /* Line 285, Address: 0x101d680 */
