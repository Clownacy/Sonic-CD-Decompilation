#include "..\EQU.H"
#include "BRANKO7.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\RIDECHK.H"

#if defined(R73C) || defined(R73D)
  #define SPRITE_BRANKO7_BASE 403
#else
  #define SPRITE_BRANKO7_BASE 404
#endif

static void branko7_ridechk(sprite_status* pActwk);
static void branko7_init(sprite_status* pActwk);
static void branko7_move(sprite_status* pActwk);
static void branko7_posiset(sprite_status* pActwk);
static void branko7_posiset2(sprite_status* pActwk, unsigned char dirwk);

static short branko7_initbl[32] = {
  -16384,  2,  256, -256,
  -16384,  2,  256, -256,
  -16384, -2, -256,  256,
  -24576,  3,  384, -384,
  -32768, -2, -256,  256,
  -32768,  2,  256, -256,
  -32768, -1, -256,    0,
  -32768,  1,  256,    0
};
static sprite_pattern pat0 = {
  1,
  { { -8, -8, 0, SPRITE_BRANKO7_BASE } }
};
static sprite_pattern pat1 = {
  1,
  { { -32, -8, 0, SPRITE_BRANKO7_BASE + 1 } }
};
static sprite_pattern pat2 = {
  1,
  { { -8, -8, 0, SPRITE_BRANKO7_BASE + 2 } }
};
sprite_pattern* branko7pat[3] = {
  &pat0,
  &pat1,
  &pat2
};
static void(*branko7_act_tbl[2])(sprite_status*) = {
  &branko7_init,
  &branko7_move
};


































































void branko7(sprite_status* pActwk) { /* Line 117, Address: 0x1020da0 */
  branko7_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 118, Address: 0x1020dac */
  actionsub(pActwk); /* Line 119, Address: 0x1020df0 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 120, Address: 0x1020dfc */
} /* Line 121, Address: 0x1020e10 */





void branko7_ridechk(sprite_status* pActwk) { /* Line 127, Address: 0x1020e20 */
  pActwk->sprvsize = 8; /* Line 128, Address: 0x1020e2c */

  if (!hitchk(pActwk, &actwk[0])) { /* Line 130, Address: 0x1020e38 */
    pActwk->sprvsize = 12; /* Line 131, Address: 0x1020e54 */

    if (!hitchk(pActwk, &actwk[0])) { /* Line 133, Address: 0x1020e60 */
      pActwk->sprvsize = 8; /* Line 134, Address: 0x1020e7c */
      return; /* Line 135, Address: 0x1020e88 */
    }
  }


  pActwk->sprvsize = 8; /* Line 140, Address: 0x1020e90 */

  if (pActwk->yposi.w.h >= actwk[0].yposi.w.h) { /* Line 142, Address: 0x1020e9c */
    actwk[0].yposi.w.h = pActwk->yposi.w.h - (short)(char)pActwk->sprvsize - (short)(char)actwk[0].sprvsize + 2; /* Line 143, Address: 0x1020ec8 */
  }



} /* Line 148, Address: 0x1020f34 */





void branko7_init(sprite_status* pActwk) { /* Line 154, Address: 0x1020f50 */
  int flagwk, flagcnt;
  sprite_status* pNewact;
  short* pIniTbl;

  pActwk->r_no0 += 2; /* Line 159, Address: 0x1020f68 */
  pActwk->actflg |= 4; /* Line 160, Address: 0x1020f78 */
  pActwk->sprpri = 3; /* Line 161, Address: 0x1020f88 */
  pActwk->patbase = branko7pat; /* Line 162, Address: 0x1020f94 */
  pActwk->sproffset = 870; /* Line 163, Address: 0x1020fa4 */
  pActwk->sprhsize = 32; /* Line 164, Address: 0x1020fb0 */
  pActwk->sprvsize = 8; /* Line 165, Address: 0x1020fbc */

  if (!pActwk->actfree[18]) { /* Line 167, Address: 0x1020fc8 */
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 168, Address: 0x1020fd8 */
    ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 169, Address: 0x1020fe8 */

    flagwk = flagcnt = 0; /* Line 171, Address: 0x1020ff8 */
    flagwk = pActwk->userflag.b.h & 15; /* Line 172, Address: 0x1021000 */
    pActwk->actfree[5] = flagwk; /* Line 173, Address: 0x1021014 */

    for (flagcnt = flagwk - 1; flagcnt >= 0; --flagcnt, --flagwk) { /* Line 175, Address: 0x1021020 */

      if (actwkchk(&pNewact) == 0) { /* Line 177, Address: 0x102102c */
        pNewact->actno = 32; /* Line 178, Address: 0x1021040 */
        ((short*)pNewact)[29] = ((short*)pActwk)[29]; /* Line 179, Address: 0x102104c */

        ((short*)pNewact)[27] = ((short*)pActwk)[27]; /* Line 181, Address: 0x102105c */

        pNewact->userflag.b.h = pActwk->userflag.b.h; /* Line 183, Address: 0x102106c */
        pNewact->actfree[5] = pActwk->actfree[5]; /* Line 184, Address: 0x102107c */
        pNewact->actfree[18] = flagwk; /* Line 185, Address: 0x102108c */
        pNewact->patno = 2; /* Line 186, Address: 0x1021098 */

        if (pActwk->actfree[5] == flagwk) { /* Line 188, Address: 0x10210a4 */
          pNewact->patno = 1; /* Line 189, Address: 0x10210b8 */
          pNewact->colino = 169; /* Line 190, Address: 0x10210c4 */
        }
      }
    } /* Line 193, Address: 0x10210d0 */
  }


  flagwk = pActwk->userflag.b.h & 240; /* Line 197, Address: 0x10210e0 */
  flagwk >>= 1; /* Line 198, Address: 0x10210f4 */
  pIniTbl = &branko7_initbl[flagwk / 2]; /* Line 199, Address: 0x10210f8 */
  ((short*)pActwk)[31] = *pIniTbl++; /* Line 200, Address: 0x1021120 */
  ((short*)pActwk)[33] = *pIniTbl++; /* Line 201, Address: 0x1021134 */
  ((short*)pActwk)[28] = *pIniTbl++; /* Line 202, Address: 0x1021148 */
  ((short*)pActwk)[30] = *pIniTbl++; /* Line 203, Address: 0x102115c */

  branko7_move(pActwk); /* Line 205, Address: 0x1021170 */
} /* Line 206, Address: 0x102117c */





void branko7_move(sprite_status* pActwk) { /* Line 212, Address: 0x10211a0 */
  int lXpos, lYpos;

  lXpos = pActwk->xposi.l; /* Line 215, Address: 0x10211b4 */
  lYpos = pActwk->yposi.l; /* Line 216, Address: 0x10211bc */

  branko7_posiset(pActwk); /* Line 218, Address: 0x10211c4 */

  if (pActwk->actfree[5] == pActwk->actfree[18]) { /* Line 220, Address: 0x10211d0 */
    pActwk->xspeed.w = pActwk->xposi.l - lXpos >> 8; /* Line 221, Address: 0x10211f0 */
    pActwk->yspeed.w = pActwk->yposi.l - lYpos >> 8; /* Line 222, Address: 0x1021210 */
    branko7_ridechk(pActwk); /* Line 223, Address: 0x1021230 */
  }
} /* Line 225, Address: 0x102123c */





void branko7_posiset(sprite_status* pActwk) { /* Line 231, Address: 0x1021260 */
  short spdwk;

  if (!pActwk->actfree[19]) { /* Line 234, Address: 0x1021270 */
    spdwk = ((short*)pActwk)[26] + ((short*)pActwk)[33]; /* Line 235, Address: 0x1021280 */

    ((short*)pActwk)[26] = spdwk; /* Line 237, Address: 0x10212b4 */
    ((short*)pActwk)[31] += spdwk; /* Line 238, Address: 0x10212bc */
    if (spdwk == ((short*)pActwk)[28]) { /* Line 239, Address: 0x10212cc */
      pActwk->actfree[19] = 1; /* Line 240, Address: 0x10212ec */
    }
  } /* Line 242, Address: 0x10212f8 */
  else {
    spdwk = ((short*)pActwk)[26] - ((short*)pActwk)[33]; /* Line 244, Address: 0x1021300 */

    ((short*)pActwk)[26] = spdwk; /* Line 246, Address: 0x1021334 */
    ((short*)pActwk)[31] += spdwk; /* Line 247, Address: 0x102133c */
    if (spdwk == ((short*)pActwk)[30]) { /* Line 248, Address: 0x102134c */
      pActwk->actfree[19] = 0; /* Line 249, Address: 0x102136c */
    }
  }


  branko7_posiset2(pActwk, ((char*)pActwk)[63]); /* Line 254, Address: 0x1021374 */
} /* Line 255, Address: 0x102138c */





void branko7_posiset2(sprite_status* pActwk, unsigned char dirwk) { /* Line 261, Address: 0x10213a0 */
  short usrwk;
  int_union sinwk, coswk;

  sinwk.l = coswk.l = 0; /* Line 265, Address: 0x10213b4 */
  sinset(dirwk, &sinwk.w.l, &coswk.w.l); /* Line 266, Address: 0x10213bc */
  usrwk = ((char*)pActwk)[64]; /* Line 267, Address: 0x10213d0 */
  usrwk <<= 4; /* Line 268, Address: 0x10213e8 */
  sinwk.l *= usrwk; /* Line 269, Address: 0x10213f4 */
  coswk.l *= usrwk; /* Line 270, Address: 0x1021408 */

  sinwk.l >>= 4; /* Line 272, Address: 0x102141c */
  sinwk.w.l >>= 4; /* Line 273, Address: 0x1021428 */
  coswk.l >>= 4; /* Line 274, Address: 0x1021434 */
  coswk.w.l >>= 4; /* Line 275, Address: 0x1021440 */
  pActwk->yposi.w.h = coswk.w.l + ((short*)pActwk)[27]; /* Line 276, Address: 0x102144c */
  pActwk->xposi.w.h = sinwk.w.l + ((short*)pActwk)[29]; /* Line 277, Address: 0x102147c */
} /* Line 278, Address: 0x10214ac */
