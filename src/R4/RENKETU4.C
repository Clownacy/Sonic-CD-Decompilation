#include "..\EQU.H"
#include "RENKETU4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\RIDECHK.H"

#if defined(R41C)
  #define SPRITE_RENKETU4_BASE 445
#elif defined(R41D)
  #define SPRITE_RENKETU4_BASE 431
#elif defined(R42C) || defined(R42D)
  #define SPRITE_RENKETU4_BASE 512
#else
  #define SPRITE_RENKETU4_BASE 496
#endif

sprite_pattern renketu4_pat0 = {
  1,
  { { -32, -8, 0, SPRITE_RENKETU4_BASE } }
};
sprite_pattern renketu4_pat1 = {
  1,
  { { -8, -8, 0, SPRITE_RENKETU4_BASE + 1 } }
};
sprite_pattern* renketu4pat[2] = {
  &renketu4_pat0,
  &renketu4_pat1
};

















































void renketu4(sprite_status* pActwk) { /* Line 79, Address: 0x1025cc0 */
  unsigned short xwk1;
  unsigned short xwk2;
  void(*renketu4_acttbl[2])(sprite_status*) = { /* Line 82, Address: 0x1025cd4 */
    &renketu4_init,
    &renketu4_move
  };

  renketu4_acttbl[pActwk->r_no0 / 2](pActwk); /* Line 87, Address: 0x1025cf0 */
  actionsub(pActwk); /* Line 88, Address: 0x1025d2c */

  xwk1 = ((unsigned short*)pActwk)[29] & 65408; /* Line 90, Address: 0x1025d38 */
  xwk2 = (unsigned short)scra_h_posit.w.h - 128 & 65408; /* Line 91, Address: 0x1025d50 */
  if ((unsigned short)(xwk1 - xwk2) > 640) { /* Line 92, Address: 0x1025d70 */
    frameout(pActwk); /* Line 93, Address: 0x1025d90 */
  }
} /* Line 95, Address: 0x1025d9c */








void renketu4_ridechk(sprite_status* pActwk) { /* Line 104, Address: 0x1025dc0 */
  if (ridechk(pActwk, &actwk[0])) { /* Line 105, Address: 0x1025dcc */

    actwk[0].yposi.w.h = pActwk->yposi.w.h - (short)pActwk->sprvsize - (short)actwk[0].sprvsize + 2; /* Line 107, Address: 0x1025de8 */
  }

} /* Line 110, Address: 0x1025e3c */








void renketu4_init(sprite_status* pActwk) { /* Line 119, Address: 0x1025e50 */
  char renketu4_tbl[18] = { /* Line 120, Address: 0x1025e60 */
     32, 0,
      0, 0,
    -32, 0,
     24, 1,
     16, 1,
      8, 1,
     -8, 1,
    -16, 1,
    -24, 1
  };
  sprite_status* pNewactwk;
  unsigned char i;


  pActwk->r_no0 += 2; /* Line 135, Address: 0x1025e94 */
  pActwk->actflg |= 4; /* Line 136, Address: 0x1025ea4 */

  if (stageno.b.l == 2) /* Line 138, Address: 0x1025eb4 */
    pActwk->sproffset = 17408; /* Line 139, Address: 0x1025ed0 */
  else
    pActwk->sproffset = 17216; /* Line 141, Address: 0x1025ee4 */

  pActwk->patbase = renketu4pat; /* Line 143, Address: 0x1025ef0 */
  pActwk->sprhsize = 32; /* Line 144, Address: 0x1025f00 */
  pActwk->sprvsize = 8; /* Line 145, Address: 0x1025f0c */

  if (!pActwk->actfree[18]) { /* Line 147, Address: 0x1025f18 */
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 148, Address: 0x1025f28 */
    ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 149, Address: 0x1025f38 */

    for (i = 1; i <= 8; ++i) { /* Line 151, Address: 0x1025f48 */
      if (actwkchk(&pNewactwk) == 0) { /* Line 152, Address: 0x1025f58 */
        pNewactwk->actno = 62; /* Line 153, Address: 0x1025f6c */
        pNewactwk->userflag.b.h = pActwk->userflag.b.h; /* Line 154, Address: 0x1025f78 */
        pNewactwk->actfree[18] = i; /* Line 155, Address: 0x1025f88 */
        ((short*)pNewactwk)[29] = ((short*)pActwk)[29]; /* Line 156, Address: 0x1025f90 */
        ((short*)pNewactwk)[27] = ((short*)pActwk)[27]; /* Line 157, Address: 0x1025fa0 */
      }
    } /* Line 159, Address: 0x1025fb0 */
  }

  pActwk->actfree[21] = renketu4_tbl[pActwk->actfree[18] * 2]; /* Line 162, Address: 0x1025fc8 */
  pActwk->patno = renketu4_tbl[pActwk->actfree[18] * 2 + 1]; /* Line 163, Address: 0x1025fe8 */

  pActwk->sprpri = 1; /* Line 165, Address: 0x102600c */
  if (pActwk->patno) { /* Line 166, Address: 0x1026018 */
    pActwk->sprpri = 3; /* Line 167, Address: 0x1026028 */
    pActwk->sproffset -= 16384; /* Line 168, Address: 0x1026034 */
  }

  if (pActwk->userflag.b.h & 16) /* Line 171, Address: 0x1026044 */
    ((short*)pActwk)[26] = -256; /* Line 172, Address: 0x1026060 */
  else
    ((short*)pActwk)[26] = 256; /* Line 174, Address: 0x1026074 */

  renketu4_move(pActwk); /* Line 176, Address: 0x1026080 */
} /* Line 177, Address: 0x102608c */








void renketu4_move(sprite_status* pActwk) { /* Line 186, Address: 0x10260a0 */
  unsigned short wD0, wD1;
  int_union lD0, lD1, lD4, lD5;
  short wk;

  swchk(pActwk); /* Line 191, Address: 0x10260b0 */

  ((short*)pActwk)[33] += ((short*)pActwk)[26]; /* Line 193, Address: 0x10260bc */

  sinset(pActwk->actfree[21], (short*)&wD0, (short*)&wD1); /* Line 195, Address: 0x10260d4 */

  lD0.l = (short)wD0 * 6 >> 4; /* Line 197, Address: 0x10260ec */
  lD1.l = (short)wD1 * 6 >> 4; /* Line 198, Address: 0x1026114 */
  wk = lD0.w.h; /* Line 199, Address: 0x102613c */
  lD0.w.h = lD0.w.l; /* Line 200, Address: 0x1026148 */
  lD0.w.l = wk; /* Line 201, Address: 0x1026150 */
  wk = lD1.w.h; /* Line 202, Address: 0x1026154 */
  lD1.w.h = lD1.w.l; /* Line 203, Address: 0x1026160 */
  lD1.w.l = wk; /* Line 204, Address: 0x1026168 */

  lD4.w.l = lD5.w.l = 0; /* Line 206, Address: 0x102616c */
  lD4.w.h = ((short*)pActwk)[27]; /* Line 207, Address: 0x102617c */
  lD5.w.h = ((short*)pActwk)[29]; /* Line 208, Address: 0x1026188 */
  lD0.l += lD4.l; /* Line 209, Address: 0x1026194 */
  lD1.l += lD5.l; /* Line 210, Address: 0x10261a4 */

  pActwk->yspeed.w = (lD0.l - pActwk->yposi.l) << 8 >> 16; /* Line 212, Address: 0x10261b4 */
  pActwk->xspeed.w = (lD1.l - pActwk->xposi.l) << 8 >> 16; /* Line 213, Address: 0x10261dc */
  pActwk->yposi.l = lD0.l; /* Line 214, Address: 0x1026204 */
  pActwk->xposi.l = lD1.l; /* Line 215, Address: 0x1026210 */

  if (!pActwk->patno) renketu4_ridechk(pActwk); /* Line 217, Address: 0x102621c */

} /* Line 219, Address: 0x1026238 */








void swchk(sprite_status* pActwk) { /* Line 228, Address: 0x1026250 */
  if (!(pActwk->userflag.b.h & 128)) { /* Line 229, Address: 0x1026258 */
    if (switchflag[pActwk->userflag.b.h & 15] & 128) { /* Line 230, Address: 0x1026274 */
      if (pActwk->actfree[19]) return; /* Line 231, Address: 0x10262a8 */
      ((short*)pActwk)[26] *= -1; /* Line 232, Address: 0x10262b8 */
      pActwk->actfree[19] = 1; /* Line 233, Address: 0x10262c8 */
      return; /* Line 234, Address: 0x10262d4 */
    }
    pActwk->actfree[19] = 0; /* Line 236, Address: 0x10262dc */
  }

} /* Line 239, Address: 0x10262e4 */
