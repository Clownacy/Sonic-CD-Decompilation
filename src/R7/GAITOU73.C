#include "..\EQU.H"
#include "GAITOU73.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"

static void gaitou73_ini(sprite_status* pActwk);
static void gaitou73_01(sprite_status* pActwk);
static short get_x(sprite_status* pActwk);
static void gaitou73_02(sprite_status* pActwk);

static sprite_pattern pat0 = {
  1,
  { { -24, -12, 128, 417 } }
};
static sprite_pattern pat1 = {
  1,
  { { -8, -112, 128, 418 } }
};
sprite_pattern* gaitou73_pat[2] = {
  &pat0,
  &pat1
};
static void(*gaitou_act_tbl[3])(sprite_status*) = {
  &gaitou73_ini,
  &gaitou73_01,
  &gaitou73_02
};


































































void gaitou73(sprite_status* pActwk) { /* Line 94, Address: 0x1021f60 */
  gaitou_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 95, Address: 0x1021f6c */
  actionsub(pActwk); /* Line 96, Address: 0x1021fb0 */
} /* Line 97, Address: 0x1021fbc */





static void gaitou73_ini(sprite_status* pActwk) { /* Line 103, Address: 0x1021fd0 */
  sprite_status* pNewact;

  pActwk->actflg = 4; /* Line 106, Address: 0x1021fdc */
  pActwk->sprpri = 0; /* Line 107, Address: 0x1021fe8 */
  pActwk->sproffset = 17692; /* Line 108, Address: 0x1021ff0 */
  pActwk->patbase = gaitou73_pat; /* Line 109, Address: 0x1021ffc */

  if (!pActwk->userflag.b.h) { /* Line 111, Address: 0x102200c */
    if (actwkchk2(pActwk, &pNewact) == 0) { /* Line 112, Address: 0x102201c */
      pNewact->actno = 54; /* Line 113, Address: 0x1022034 */
      pNewact->userflag.b.h = 1; /* Line 114, Address: 0x1022040 */
      ((short*)pNewact)[25] = pActwk - actwk; /* Line 115, Address: 0x102204c */
      ((short*)pActwk)[25] = pNewact - actwk; /* Line 116, Address: 0x1022084 */
    }


    pActwk->sprhsize = 24; /* Line 120, Address: 0x10220bc */
    pActwk->sprvsize = 12; /* Line 121, Address: 0x10220c8 */
    pActwk->r_no0 = 2; /* Line 122, Address: 0x10220d4 */
  } /* Line 123, Address: 0x10220e0 */
  else {
    pActwk->patno = 1; /* Line 125, Address: 0x10220e8 */
    pActwk->sprhsize = 8; /* Line 126, Address: 0x10220f4 */
    pActwk->sprvsize = 112; /* Line 127, Address: 0x1022100 */
    pActwk->r_no0 = 4; /* Line 128, Address: 0x102210c */
  }
} /* Line 130, Address: 0x1022118 */





static void gaitou73_01(sprite_status* pActwk) { /* Line 136, Address: 0x1022130 */
  ((short*)pActwk)[26] = get_x(pActwk); /* Line 137, Address: 0x102213c */
  ((short*)pActwk)[27] = 352 - (scra_v_posit.w.h - 352) / 3; /* Line 138, Address: 0x1022150 */


  if (((short*)pActwk)[27] + 12 >= scra_v_posit.w.h) { /* Line 141, Address: 0x1022194 */

    pActwk->xposi.w.h = ((short*)pActwk)[26]; /* Line 143, Address: 0x10221c4 */
    pActwk->yposi.w.h = ((short*)pActwk)[27]; /* Line 144, Address: 0x10221d4 */
    pActwk->patno = 0; /* Line 145, Address: 0x10221e4 */
    pActwk->sprhsize = 24; /* Line 146, Address: 0x10221ec */
    pActwk->sprvsize = 12; /* Line 147, Address: 0x10221f8 */
  } /* Line 148, Address: 0x1022204 */
  else {
    pActwk->xposi.w.h = ((short*)pActwk)[26]; /* Line 150, Address: 0x102220c */
    pActwk->yposi.w.h = ((short*)pActwk)[27]; /* Line 151, Address: 0x102221c */
    pActwk->yposi.w.h += 348; /* Line 152, Address: 0x102222c */

    pActwk->patno = 1; /* Line 154, Address: 0x102223c */
    pActwk->sprhsize = 8; /* Line 155, Address: 0x1022248 */
    pActwk->sprvsize = 112; /* Line 156, Address: 0x1022254 */
  }
} /* Line 158, Address: 0x1022260 */


static short get_x(sprite_status* pActwk) { /* Line 161, Address: 0x1022270 */
  short wk1, wk2;

  wk1 = (unsigned int)scra_h_posit.w.h / 320; /* Line 164, Address: 0x102227c */
  wk2 = (unsigned int)scra_h_posit.w.h % 320; /* Line 165, Address: 0x10222b4 */

  if (wk1 > 48) { /* Line 167, Address: 0x10222e0 */
    wk1 = 0; /* Line 168, Address: 0x10222f4 */
  }

  wk1 = ((wk1 + 1) * 320) + 256; /* Line 171, Address: 0x10222f8 */
  wk2 = wk2 * 256 / 320; /* Line 172, Address: 0x1022324 */

  return wk1 - wk2; /* Line 174, Address: 0x1022358 */
} /* Line 175, Address: 0x1022374 */





static void gaitou73_02(sprite_status* pActwk) { /* Line 181, Address: 0x1022390 */
  sprite_status* pBptr;

  pBptr = &actwk[((short*)pActwk)[25]]; /* Line 184, Address: 0x102239c */
  pActwk->xposi.w.h = ((short*)pBptr)[26]; /* Line 185, Address: 0x10223c4 */
  pActwk->yposi.w.h = ((short*)pBptr)[27]; /* Line 186, Address: 0x10223d0 */
  pActwk->yposi.w.h += 124; /* Line 187, Address: 0x10223dc */
} /* Line 188, Address: 0x10223ec */
