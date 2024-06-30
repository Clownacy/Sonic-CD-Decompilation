#include "..\EQU.H"
#include "TEKKYU7J.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"

static void tekkyu7(sprite_status* pActwk);
static void tekkyu7_init(sprite_status* pActwk);
static void tekkyu7_move(sprite_status* pActwk);
static void tekkyu7_stop(sprite_status* pActwk);
static void tekkyu7_jump(sprite_status* pActwk);

static sprite_pattern tekkyu7j_pat0 = {
  1,
  { { -16, -16, 0, 406 } }
};
static sprite_pattern tekkyu7j_pat1 = {
  1,
  { { -16, 0, 0, 407 } }
};
static sprite_pattern tekkyu7j_pat2 = {
  1,
  { { -16, -16, 0, 408 } }
};
static sprite_pattern tekkyu7j_pat3 = {
  1,
  { { 0, -16, 0, 409 } }
};
sprite_pattern* pat_tekkyu7j[4] = {
  &tekkyu7j_pat0,
  &tekkyu7j_pat1,
  &tekkyu7j_pat2,
  &tekkyu7j_pat3
};
extern sprite_pattern* pat_tekkyu7[];























































void tekkyu7j(sprite_status* pActwk) { /* Line 90, Address: 0x101ff50 */
  sprite_status* pNewactwk;

  if (pActwk->userflag.b.l) { /* Line 93, Address: 0x101ff5c */
    tekkyu7(pActwk); /* Line 94, Address: 0x101ff6c */
  } /* Line 95, Address: 0x101ff78 */
  else {

    if (!pActwk->r_no0) { /* Line 98, Address: 0x101ff80 */

      pActwk->r_no0 += 2; /* Line 100, Address: 0x101ff90 */
      pActwk->actflg |= 4; /* Line 101, Address: 0x101ffa0 */
      pActwk->sprpri = 1; /* Line 102, Address: 0x101ffb0 */
      pActwk->sproffset = 910; /* Line 103, Address: 0x101ffbc */
      pActwk->patbase = pat_tekkyu7j; /* Line 104, Address: 0x101ffc8 */
      pActwk->patno = pActwk->userflag.b.h; /* Line 105, Address: 0x101ffd8 */
      ((short*)pActwk)[23] = 150; /* Line 106, Address: 0x101ffe8 */
      pActwk->sprhs = 16; /* Line 107, Address: 0x101fff4 */
      pActwk->sprhsize = 16; /* Line 108, Address: 0x1020000 */
      pActwk->sprvsize = 16; /* Line 109, Address: 0x102000c */
    }

    if (!(--((short*)pActwk)[23])) { /* Line 112, Address: 0x1020018 */
      ((short*)pActwk)[23] = 150; /* Line 113, Address: 0x1020038 */
      if (actwkchk(&pNewactwk) == 0) { /* Line 114, Address: 0x1020044 */
        pNewactwk->actno = pActwk->actno; /* Line 115, Address: 0x1020058 */
        pNewactwk->userflag.b.h = pActwk->userflag.b.h; /* Line 116, Address: 0x1020068 */
        pNewactwk->userflag.b.l = -1; /* Line 117, Address: 0x1020078 */
        pNewactwk->xposi.w.h = pActwk->xposi.w.h; /* Line 118, Address: 0x1020084 */
        pNewactwk->yposi.w.h = pActwk->yposi.w.h; /* Line 119, Address: 0x1020094 */
      }
    }
    actionsub(pActwk); /* Line 122, Address: 0x10200a4 */
    frameout_s(pActwk); /* Line 123, Address: 0x10200b0 */
  }
} /* Line 125, Address: 0x10200bc */








static void tekkyu7(sprite_status* pActwk) { /* Line 134, Address: 0x10200d0 */
  void(*tekkyu7_acttbl[4])(sprite_status*) = { /* Line 135, Address: 0x10200dc */
    &tekkyu7_init,
    &tekkyu7_move,
    &tekkyu7_stop,
    &tekkyu7_jump
  };

  tekkyu7_acttbl[pActwk->r_no0 / 2](pActwk); /* Line 142, Address: 0x1020108 */
  actionsub(pActwk); /* Line 143, Address: 0x1020144 */
} /* Line 144, Address: 0x1020150 */








void tekkyu7_init(sprite_status* pActwk) { /* Line 153, Address: 0x1020160 */
  short wD0;

  pActwk->r_no0 += 2; /* Line 156, Address: 0x1020170 */
  pActwk->actflg |= 4; /* Line 157, Address: 0x1020180 */
  pActwk->sprpri = 4; /* Line 158, Address: 0x1020190 */
  pActwk->colino = 181; /* Line 159, Address: 0x102019c */
  pActwk->sprhs = 16; /* Line 160, Address: 0x10201a8 */
  pActwk->sprhsize = 16; /* Line 161, Address: 0x10201b4 */
  pActwk->sprvsize = 16; /* Line 162, Address: 0x10201c0 */
  pActwk->sproffset = 902; /* Line 163, Address: 0x10201cc */
  pActwk->patbase = pat_tekkyu7; /* Line 164, Address: 0x10201d8 */
  ((short*)pActwk)[25] = 32; /* Line 165, Address: 0x10201e8 */

  ((int*)pActwk)[13] = 32768; /* Line 167, Address: 0x10201f4 */
  pActwk->actfree[21] = 0; /* Line 168, Address: 0x1020200 */
  if (!(pActwk->userflag.b.h & 1)) { /* Line 169, Address: 0x1020208 */
    pActwk->actfree[21] = 255; /* Line 170, Address: 0x1020224 */
    ((int*)pActwk)[13] *= -1; /* Line 171, Address: 0x1020230 */
  }
  pActwk->actfree[0] = 0; /* Line 173, Address: 0x1020240 */
  wD0 = pActwk->xposi.w.h; /* Line 174, Address: 0x1020248 */
  if (pActwk->userflag.b.h < 2) { /* Line 175, Address: 0x1020258 */
    pActwk->actfree[0] = 1; /* Line 176, Address: 0x1020274 */
    wD0 = pActwk->yposi.w.h; /* Line 177, Address: 0x1020280 */
  }
  ((short*)pActwk)[24] = wD0; /* Line 179, Address: 0x1020290 */

  tekkyu7_move(pActwk); /* Line 181, Address: 0x1020298 */
} /* Line 182, Address: 0x10202a4 */








void tekkyu7_move(sprite_status* pActwk) { /* Line 191, Address: 0x10202c0 */
  if (pActwk->actfree[0]) /* Line 192, Address: 0x10202c8 */
    pActwk->yposi.l += ((int*)pActwk)[13]; /* Line 193, Address: 0x10202d8 */
  else
    pActwk->xposi.l += ((int*)pActwk)[13]; /* Line 195, Address: 0x10202f8 */
  if (!(--((short*)pActwk)[25])) { /* Line 196, Address: 0x1020310 */
    pActwk->r_no0 += 2; /* Line 197, Address: 0x1020330 */
    ((short*)pActwk)[25] = 30; /* Line 198, Address: 0x1020340 */
  }
} /* Line 200, Address: 0x102034c */








void tekkyu7_stop(sprite_status* pActwk) { /* Line 209, Address: 0x1020360 */
  if (!(--((short*)pActwk)[25])) { /* Line 210, Address: 0x1020368 */
    pActwk->r_no0 += 2; /* Line 211, Address: 0x1020388 */
    ((int*)pActwk)[13] = 393216; /* Line 212, Address: 0x1020398 */
    ((int*)pActwk)[14] = -16384; /* Line 213, Address: 0x10203a4 */
    if (!(pActwk->userflag.b.h & 1)) { /* Line 214, Address: 0x10203b0 */
      ((int*)pActwk)[13] *= -1; /* Line 215, Address: 0x10203cc */
      ((int*)pActwk)[14] *= -1; /* Line 216, Address: 0x10203dc */
    }
  }
} /* Line 219, Address: 0x10203ec */








void tekkyu7_jump(sprite_status* pActwk) { /* Line 228, Address: 0x1020400 */
  short wD0;
  unsigned char bD0;

  ((int*)pActwk)[13] += ((int*)pActwk)[14]; /* Line 232, Address: 0x1020414 */
  if (pActwk->actfree[0]) { /* Line 233, Address: 0x102042c */
    pActwk->yposi.l += ((int*)pActwk)[13]; /* Line 234, Address: 0x102043c */
    wD0 = pActwk->yposi.w.h; /* Line 235, Address: 0x1020454 */
  } /* Line 236, Address: 0x1020464 */
  else {
    pActwk->xposi.l += ((int*)pActwk)[13]; /* Line 238, Address: 0x102046c */
    wD0 = pActwk->xposi.w.h; /* Line 239, Address: 0x1020484 */
  }
  bD0 = 0; /* Line 241, Address: 0x1020494 */
  if (wD0 < ((short*)pActwk)[24]) /* Line 242, Address: 0x1020498 */
    bD0 = 255; /* Line 243, Address: 0x10204bc */
  if (pActwk->actfree[21] != bD0) /* Line 244, Address: 0x10204c4 */
    frameout(pActwk); /* Line 245, Address: 0x10204dc */
} /* Line 246, Address: 0x10204e8 */
