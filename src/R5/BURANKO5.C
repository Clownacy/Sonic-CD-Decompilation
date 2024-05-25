#include "..\EQU.H"
#include "BURANKO5.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\RIDECHK.H"

static void c_init(sprite_status* pActwk);
static void c_move(sprite_status* pActwk);
static void middle(sprite_status* pActwk);
static void radius(sprite_status* pActwk);

static sprite_pattern pat_buranko5_00 = {
  1,
  { { -8, -8, 0, 403 } }
};
static sprite_pattern pat_buranko5_01 = {
  1,
  { { -8, -8, 0, 404 } }
};
static sprite_pattern pat_buranko5_02 = {
  1,
  { { -32, -8, 0, 405 } }
};
sprite_pattern* pat_buranko5[3] = {
  &pat_buranko5_00,
  &pat_buranko5_01,
  &pat_buranko5_02
};



















































void buranko5(sprite_status* pActwk) { /* Line 81, Address: 0x1026ae0 */
  if (!pActwk->userflag.b.l) { /* Line 82, Address: 0x1026aec */

    if (pActwk->r_no0) { /* Line 84, Address: 0x1026afc */
      c_move(pActwk); /* Line 85, Address: 0x1026b0c */
      return; /* Line 86, Address: 0x1026b18 */
    }
    c_init(pActwk); /* Line 88, Address: 0x1026b20 */
  } /* Line 89, Address: 0x1026b2c */
  else {
    if (pActwk->userflag.b.l & 128) { /* Line 91, Address: 0x1026b34 */

      radius(pActwk); /* Line 93, Address: 0x1026b50 */
    } /* Line 94, Address: 0x1026b5c */
    else {

      middle(pActwk); /* Line 97, Address: 0x1026b64 */
    }
  }
} /* Line 100, Address: 0x1026b70 */








static void c_init(sprite_status* pActwk) { /* Line 109, Address: 0x1026b80 */
  sprite_status* pNewactwk;
  short wD6;
  int i;

  short tbl0[6] = { /* Line 114, Address: 0x1026b94 */
    5,      0,
    5, -32768,
    7,  16384
  };

  pActwk->r_no0 += 2; /* Line 120, Address: 0x1026bc8 */
  pActwk->actflg |= 4; /* Line 121, Address: 0x1026bd8 */
  pActwk->sprhs = 8; /* Line 122, Address: 0x1026be8 */
  pActwk->sprhsize = 8; /* Line 123, Address: 0x1026bf4 */
  pActwk->sprvsize = 8; /* Line 124, Address: 0x1026c00 */
  pActwk->sprpri = 3; /* Line 125, Address: 0x1026c0c */
  pActwk->sproffset = 856; /* Line 126, Address: 0x1026c18 */
  pActwk->patbase = pat_buranko5; /* Line 127, Address: 0x1026c24 */
  ((short*)pActwk)[29] = tbl0[pActwk->userflag.b.h & 254]; /* Line 128, Address: 0x1026c34 */
  ((short*)pActwk)[25] = tbl0[(pActwk->userflag.b.h & 254) + 1]; /* Line 129, Address: 0x1026c5c */
  ((short*)pActwk)[27] = 256; /* Line 130, Address: 0x1026c88 */
  if (pActwk->userflag.b.h & 1) { /* Line 131, Address: 0x1026c94 */
    *(int*)&pActwk->actfree[4] *= -1; /* Line 132, Address: 0x1026cb0 */
    *(int*)&pActwk->actfree[8] *= -1; /* Line 133, Address: 0x1026cc8 */
  }

  wD6 = ((short*)pActwk)[29]; /* Line 136, Address: 0x1026ce0 */
  for (i = 0; wD6 >= 0; --wD6, ++i) { /* Line 137, Address: 0x1026cf0 */

    if (actwkchk2(pActwk, &pNewactwk) != 0) { /* Line 139, Address: 0x1026cfc */
      frameout(pActwk); /* Line 140, Address: 0x1026d14 */
      return; /* Line 141, Address: 0x1026d20 */
    }
    pActwk->actfree[i + 14] = pNewactwk - actwk; /* Line 143, Address: 0x1026d28 */
    pNewactwk->userflag.b.l = 1; /* Line 144, Address: 0x1026d64 */
    ((short*)pNewactwk)[23] = pActwk - actwk; /* Line 145, Address: 0x1026d70 */
    pNewactwk->actno = pActwk->actno; /* Line 146, Address: 0x1026da8 */
    pNewactwk->xposi.w.h = pActwk->xposi.w.h; /* Line 147, Address: 0x1026db8 */
    pNewactwk->yposi.w.h = pActwk->yposi.w.h; /* Line 148, Address: 0x1026dc8 */
    pNewactwk->actflg = pActwk->actflg; /* Line 149, Address: 0x1026dd8 */
    pNewactwk->patbase = pActwk->patbase; /* Line 150, Address: 0x1026de8 */
  } /* Line 151, Address: 0x1026df8 */
  pNewactwk->userflag.b.l = -1; /* Line 152, Address: 0x1026e18 */
} /* Line 153, Address: 0x1026e24 */








static void c_move(sprite_status* pActwk) { /* Line 162, Address: 0x1026e40 */
  sprite_status* pMainactwk;
  int lD3, lD4, lD5, lD6;
  int_union lD0, lD1;
  short wD6;
  unsigned short Sin, Cos;
  int i;

  lD6 = *(int*)&pActwk->actfree[0] + *(int*)&pActwk->actfree[8]; /* Line 170, Address: 0x1026e68 */

  if ((lD5 = *(int*)&pActwk->actfree[4]) != 0) { /* Line 172, Address: 0x1026e84 */
    lD1.l = lD6; /* Line 173, Address: 0x1026e98 */
    if (lD0.l = lD5, lD5 < 0) { /* Line 174, Address: 0x1026e9c */
      lD1.l = -lD1.l; /* Line 175, Address: 0x1026ea8 */
      lD0.l = -lD0.l; /* Line 176, Address: 0x1026eb4 */
    }

    if (lD1.l < 0) { /* Line 179, Address: 0x1026ec0 */
      lD6 = 0; /* Line 180, Address: 0x1026ecc */
      *(int*)&pActwk->actfree[8] *= -1; /* Line 181, Address: 0x1026ed0 */
    } /* Line 182, Address: 0x1026ee8 */
    else {
      if (lD1.l > lD0.l) { /* Line 184, Address: 0x1026ef0 */
        lD6 = lD5; /* Line 185, Address: 0x1026f04 */
        *(int*)&pActwk->actfree[8] *= -1; /* Line 186, Address: 0x1026f08 */
      }
    }
  }
  *(int*)&pActwk->actfree[0] = lD6; /* Line 190, Address: 0x1026f20 */

  wD6 = ((short*)pActwk)[29] - 1; /* Line 192, Address: 0x1026f2c */
  lD5 = pActwk->xposi.l; /* Line 193, Address: 0x1026f50 */
  lD4 = pActwk->yposi.l; /* Line 194, Address: 0x1026f58 */
  lD1.l = 0; /* Line 195, Address: 0x1026f60 */
  lD0.l = 0; /* Line 196, Address: 0x1026f64 */
  sinset(pActwk->actfree[1], (short*)&Sin, (short*)&Cos); /* Line 197, Address: 0x1026f68 */
  lD1.w.h = Cos; /* Line 198, Address: 0x1026f80 */
  lD0.w.h = Sin; /* Line 199, Address: 0x1026f88 */
  lD1.l /= 16; /* Line 200, Address: 0x1026f90 */
  lD0.l /= 16; /* Line 201, Address: 0x1026fb0 */

  for (i = 0; wD6 >= 0; --wD6) { /* Line 203, Address: 0x1026fd0 */

    pMainactwk = &actwk[pActwk->actfree[i++ + 14]]; /* Line 205, Address: 0x1026fdc */
    pMainactwk->xposi.l = lD5 += lD1.l; /* Line 206, Address: 0x1027010 */
    pMainactwk->yposi.l = lD4 += lD0.l; /* Line 207, Address: 0x102701c */
  } /* Line 208, Address: 0x1027028 */
  pMainactwk = &actwk[pActwk->actfree[i + 14]]; /* Line 209, Address: 0x1027044 */
  lD3 = lD5 + lD1.l, pMainactwk->xposi.l = lD3; /* Line 210, Address: 0x1027070 */
  pMainactwk->xposi.l = lD5 + lD1.l; /* Line 211, Address: 0x102707c */
  pMainactwk->yposi.l = lD4 + lD0.l; /* Line 212, Address: 0x1027088 */
  pMainactwk->xspeed.w = (short)(lD5 - lD3) >> 8; /* Line 213, Address: 0x1027094 */
  actionsub(pActwk); /* Line 214, Address: 0x10270b8 */
  frameout_s(pActwk); /* Line 215, Address: 0x10270c4 */
} /* Line 216, Address: 0x10270d0 */








static void middle(sprite_status* pActwk) { /* Line 225, Address: 0x1027100 */
  if (pActwk->r_no0) { /* Line 226, Address: 0x102710c */

    if (actwk[pActwk->actfree[0]].actno == 42) /* Line 228, Address: 0x102711c */
      actionsub(pActwk); /* Line 229, Address: 0x1027154 */
    else
      frameout(pActwk); /* Line 231, Address: 0x1027168 */
    return; /* Line 232, Address: 0x1027174 */
  }


  pActwk->r_no0 += 2; /* Line 236, Address: 0x102717c */
  pActwk->patno = 1; /* Line 237, Address: 0x102718c */
  pActwk->sprhs = 8; /* Line 238, Address: 0x1027198 */
  pActwk->sprhsize = 8; /* Line 239, Address: 0x10271a4 */
  pActwk->sprvsize = 8; /* Line 240, Address: 0x10271b0 */
  pActwk->sprpri = 3; /* Line 241, Address: 0x10271bc */
  pActwk->sproffset = 856; /* Line 242, Address: 0x10271c8 */

} /* Line 244, Address: 0x10271d4 */








static void radius(sprite_status* pActwk) { /* Line 253, Address: 0x10271f0 */
  short wSp, wD0;
  unsigned char bD0;

  if (!pActwk->r_no0) { /* Line 257, Address: 0x1027208 */

    pActwk->r_no0 += 2; /* Line 259, Address: 0x1027218 */
    pActwk->patno = 2; /* Line 260, Address: 0x1027228 */
    pActwk->sprhs = 32; /* Line 261, Address: 0x1027234 */
    pActwk->sprhsize = 32; /* Line 262, Address: 0x1027240 */
    pActwk->sprvsize = 8; /* Line 263, Address: 0x102724c */
    pActwk->sprpri = 2; /* Line 264, Address: 0x1027258 */
    pActwk->sproffset = 17180; /* Line 265, Address: 0x1027264 */
  }


  wSp = pActwk->xspeed.w; /* Line 269, Address: 0x1027270 */
  pActwk->xspeed.w = 0; /* Line 270, Address: 0x1027280 */
  pActwk->sprvsize = 10; /* Line 271, Address: 0x1027288 */
  if (ridechk(pActwk, &actwk[0])) /* Line 272, Address: 0x1027294 */
    bD0 = 255; /* Line 273, Address: 0x10272b0 */
  else
    bD0 = 0; /* Line 275, Address: 0x10272c0 */
  pActwk->xspeed.w = wSp; /* Line 276, Address: 0x10272c4 */
  pActwk->sprvsize = 8; /* Line 277, Address: 0x10272cc */
  if (bD0) { /* Line 278, Address: 0x10272d8 */
    if (ridechk(pActwk, &actwk[0])) { /* Line 279, Address: 0x10272e0 */

      wD0 = 2; /* Line 281, Address: 0x10272fc */
      if (colrevflag) { /* Line 282, Address: 0x1027308 */
        wD0 *= -1; /* Line 283, Address: 0x1027318 */
      }
      actwk[0].xposi.w.h += wD0; /* Line 285, Address: 0x1027324 */
    }
  }


  if (actwk[pActwk->actfree[0]].actno == 42) /* Line 290, Address: 0x1027338 */
    actionsub(pActwk); /* Line 291, Address: 0x1027370 */
  else
    frameout(pActwk); /* Line 293, Address: 0x1027384 */
} /* Line 294, Address: 0x1027390 */
