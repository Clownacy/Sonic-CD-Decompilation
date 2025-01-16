#include "..\EQU.H"
#include "TEKKYU.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"

#if defined(R41A) || defined(R42A)
  #define SPRITE_TEKKYU_BASE 467
#elif defined(R42C) || defined(R42D)
  #define SPRITE_TEKKYU_BASE 472
#else
  #define SPRITE_TEKKYU_BASE 493
#endif

static void tekkyu_main(sprite_status* pActwk);
static void act_init(sprite_status* pActwk);
static void act_move(sprite_status* pActwk);
static void tekkyu_opt(sprite_status* pActwk);
static void opt_act_init(sprite_status* pActwk);
static void opt_act_move(sprite_status* pActwk);

static sprite_pattern tekkyu_pat00 = {
  1,
  { { -8, -8, 0, SPRITE_TEKKYU_BASE } }
};
sprite_pattern* pat_tekkyu[1] = { &tekkyu_pat00 };
sprite_pattern** pat_tyuusin = { pat_tekkyu };
static void(*act_tbl[2])(sprite_status*) = {
  &act_init,
  &act_move
};
static sprite_pattern kusari_pat00 = {
  1,
  { { -8, -8, 0, SPRITE_TEKKYU_BASE + 1 } }
};
sprite_pattern* pat_kusari[1] = { &kusari_pat00 };
static sprite_pattern tekkyu1_pat00 = {
  1,
  { { -16, -16, 0, SPRITE_TEKKYU_BASE + 2 } }
};
sprite_pattern* pat_tekkyu1[1] = { &tekkyu1_pat00 };
static void(*opt_act_tbl[2])(sprite_status*) = {
  &opt_act_init,
  &opt_act_move
};


























































void tekkyu(sprite_status* pActwk) { /* Line 104, Address: 0x101eec0 */
  if (pActwk->userflag.b.h & 128) { /* Line 105, Address: 0x101eecc */
    tekkyu_opt(pActwk); /* Line 106, Address: 0x101eee8 */
  } else { /* Line 107, Address: 0x101eef4 */
    tekkyu_main(pActwk); /* Line 108, Address: 0x101eefc */
  }
} /* Line 110, Address: 0x101ef08 */





static void tekkyu_main(sprite_status* pActwk) { /* Line 116, Address: 0x101ef20 */
  act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 117, Address: 0x101ef2c */
  actionsub(pActwk); /* Line 118, Address: 0x101ef70 */
  frameout_s(pActwk); /* Line 119, Address: 0x101ef7c */
} /* Line 120, Address: 0x101ef88 */





static void act_init(sprite_status* pActwk) { /* Line 126, Address: 0x101efa0 */
  sprite_status* pNewact;
  short* pActidx;
  int i;

  pActwk->r_no0 += 2; /* Line 131, Address: 0x101efb4 */
  pActwk->actflg |= 4; /* Line 132, Address: 0x101efc4 */
  pActwk->sprpri = 3; /* Line 133, Address: 0x101efd4 */
  pActwk->sprhsize = 8; /* Line 134, Address: 0x101efe0 */
  pActwk->sprvsize = 8; /* Line 135, Address: 0x101efec */
  pActwk->patbase = pat_tyuusin; /* Line 136, Address: 0x101eff8 */
  pActwk->sproffset = 872; /* Line 137, Address: 0x101f008 */

  if (pActwk->userflag.b.h == 0) { /* Line 139, Address: 0x101f014 */
    ((short*)pActwk)[24] = 256; /* Line 140, Address: 0x101f02c */
  } else { /* Line 141, Address: 0x101f038 */
    ((short*)pActwk)[24] = -256; /* Line 142, Address: 0x101f040 */
  }

  pActidx = &((short*)pActwk)[25]; /* Line 145, Address: 0x101f04c */
  for (i = 0; i < 6; ++i) { /* Line 146, Address: 0x101f054 */
    if (actwkchk(&pNewact) != 0) { /* Line 147, Address: 0x101f060 */
      frameout(pActwk); /* Line 148, Address: 0x101f074 */
      return; /* Line 149, Address: 0x101f080 */
    }

    *pActidx++ = pNewact - actwk; /* Line 152, Address: 0x101f088 */
    pNewact->actno = pActwk->actno; /* Line 153, Address: 0x101f0c4 */
    pNewact->userflag.b.h = -1; /* Line 154, Address: 0x101f0d4 */
    pNewact->sprhsize = 8; /* Line 155, Address: 0x101f0e0 */
    pNewact->sprvsize = 8; /* Line 156, Address: 0x101f0ec */
    ((short*)pNewact)[33] = pActwk - actwk; /* Line 157, Address: 0x101f0f8 */
  } /* Line 158, Address: 0x101f130 */

  pNewact->userflag.b.h = -2; /* Line 160, Address: 0x101f140 */
  act_move(pActwk); /* Line 161, Address: 0x101f14c */
} /* Line 162, Address: 0x101f158 */





static void act_move(sprite_status* pActwk) { /* Line 168, Address: 0x101f170 */
  int_union ldSin, ldCos;
  int sinsv1, sinsv2, cossv1, cossv2;
  sprite_status* pSubact;

  ((short*)pActwk)[23] += ((short*)pActwk)[24]; /* Line 173, Address: 0x101f190 */

  sinset(pActwk->actfree[1], &ldSin.w.h, &ldCos.w.h); /* Line 175, Address: 0x101f1a8 */
  ldSin.w.l = ldCos.w.l = 0; /* Line 176, Address: 0x101f1c0 */

  ldSin.l >>= 2; /* Line 178, Address: 0x101f1d0 */
  ldCos.l >>= 2; /* Line 179, Address: 0x101f1dc */
  sinsv1 = ldSin.l; /* Line 180, Address: 0x101f1e8 */
  cossv1 = ldCos.l; /* Line 181, Address: 0x101f1ec */

  ldSin.l >>= 1; /* Line 183, Address: 0x101f1f0 */
  ldCos.l >>= 1; /* Line 184, Address: 0x101f1fc */
  sinsv2 = ldSin.l; /* Line 185, Address: 0x101f208 */
  cossv2 = ldCos.l; /* Line 186, Address: 0x101f20c */

  ldSin.l >>= 1; /* Line 188, Address: 0x101f210 */
  ldCos.l >>= 1; /* Line 189, Address: 0x101f21c */

  pSubact = &actwk[((short*)pActwk)[25]]; /* Line 191, Address: 0x101f228 */
  *(int*)&pSubact->actfree[4] = pActwk->yposi.l + ldSin.l; /* Line 192, Address: 0x101f250 */
  *(int*)&pSubact->actfree[0] = pActwk->xposi.l + ldCos.l; /* Line 193, Address: 0x101f268 */

  pSubact = &actwk[((short*)pActwk)[26]]; /* Line 195, Address: 0x101f280 */
  *(int*)&pSubact->actfree[4] = pActwk->yposi.l + sinsv2; /* Line 196, Address: 0x101f2a8 */
  *(int*)&pSubact->actfree[0] = pActwk->xposi.l + cossv2; /* Line 197, Address: 0x101f2bc */

  pSubact = &actwk[((short*)pActwk)[27]]; /* Line 199, Address: 0x101f2d0 */
  *(int*)&pSubact->actfree[4] = pActwk->yposi.l + ldSin.l + sinsv2; /* Line 200, Address: 0x101f2f8 */
  *(int*)&pSubact->actfree[0] = pActwk->xposi.l + ldCos.l + cossv2; /* Line 201, Address: 0x101f314 */

  pSubact = &actwk[((short*)pActwk)[28]]; /* Line 203, Address: 0x101f330 */
  *(int*)&pSubact->actfree[4] = pActwk->yposi.l + sinsv1; /* Line 204, Address: 0x101f358 */
  *(int*)&pSubact->actfree[0] = pActwk->xposi.l + cossv1; /* Line 205, Address: 0x101f36c */

  pSubact = &actwk[((short*)pActwk)[29]]; /* Line 207, Address: 0x101f380 */
  *(int*)&pSubact->actfree[4] = pActwk->yposi.l + ldSin.l + sinsv1; /* Line 208, Address: 0x101f3a8 */
  *(int*)&pSubact->actfree[0] = pActwk->xposi.l + ldCos.l + cossv1; /* Line 209, Address: 0x101f3c4 */

  pSubact = &actwk[((short*)pActwk)[30]]; /* Line 211, Address: 0x101f3e0 */
  *(int*)&pSubact->actfree[4] = pActwk->yposi.l + sinsv2 + sinsv1; /* Line 212, Address: 0x101f408 */
  *(int*)&pSubact->actfree[0] = pActwk->xposi.l + cossv2 + cossv1; /* Line 213, Address: 0x101f420 */
} /* Line 214, Address: 0x101f438 */



































static void tekkyu_opt(sprite_status* pActwk) { /* Line 250, Address: 0x101f460 */
  opt_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 251, Address: 0x101f46c */
  if (actwk[((short*)pActwk)[33]].actno != 54) { /* Line 252, Address: 0x101f4b0 */

    frameout(pActwk); /* Line 254, Address: 0x101f4ec */
  } else { /* Line 255, Address: 0x101f4f8 */
    actionsub(pActwk); /* Line 256, Address: 0x101f500 */
  }
} /* Line 258, Address: 0x101f50c */





static void opt_act_init(sprite_status* pActwk) { /* Line 264, Address: 0x101f520 */
  pActwk->r_no0 += 2; /* Line 265, Address: 0x101f52c */
  pActwk->actflg |= 4; /* Line 266, Address: 0x101f53c */

  if (pActwk->userflag.b.h == -1) { /* Line 268, Address: 0x101f54c */
    pActwk->sprpri = 3; /* Line 269, Address: 0x101f568 */
    pActwk->patbase = pat_kusari; /* Line 270, Address: 0x101f574 */
    pActwk->sproffset = 872; /* Line 271, Address: 0x101f584 */
  } /* Line 272, Address: 0x101f590 */
  else {
    pActwk->sprpri = 2; /* Line 274, Address: 0x101f598 */
    pActwk->patbase = pat_tekkyu1; /* Line 275, Address: 0x101f5a4 */
    pActwk->sproffset = 880; /* Line 276, Address: 0x101f5b4 */
    pActwk->colino = 169; /* Line 277, Address: 0x101f5c0 */
  }

  opt_act_move(pActwk); /* Line 280, Address: 0x101f5cc */
} /* Line 281, Address: 0x101f5d8 */





static void opt_act_move(sprite_status* pActwk) { /* Line 287, Address: 0x101f5f0 */
  pActwk->xposi.w.h = ((short*)pActwk)[24]; /* Line 288, Address: 0x101f5f8 */
  pActwk->yposi.w.h = ((short*)pActwk)[26]; /* Line 289, Address: 0x101f608 */
} /* Line 290, Address: 0x101f618 */
