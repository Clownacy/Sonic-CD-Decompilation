#include "..\EQU.H"
#include "KUMO.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static void kumo_init(sprite_status* pActwk);
static void kumo_jump(sprite_status* pActwk);
static void kumo_jump1(sprite_status* pActwk);
static void kumo_move(sprite_status* pActwk);
static void kumo_move1(sprite_status* pActwk);
static short kumo_check(sprite_status* pActwk0, sprite_status* pActwk1);
static void kumo_tama(sprite_status* pActwk);
static void kumo_tama1(sprite_status* pActwk);
static void tama(sprite_status* pActwk);

static unsigned char pchg_e_00[4] = { 7, 1, 2, 255 };
static unsigned char pchg_b_00[4] = { 15, 1, 2, 255 };
static unsigned char pchg_tama_00[4] = { 2, 0, 1, 255 };
static unsigned char* pchg_e[1] = { pchg_e_00 };
static unsigned char* pchg_b[1] = { pchg_b_00 };
static unsigned char* pchg_tama[1] = { pchg_tama_00 };
static sprite_pattern kumo_e_pat00 = {
  1,
  { { -28, -25, 0, 409 } }
};
static sprite_pattern kumo_e_pat01 = {
  1,
  { { -28, -17, 0, 410 } }
};
static sprite_pattern kumo_e_pat02 = {
  1,
  { { -28, -13, 0, 411 } }
};
static sprite_pattern kumo_b_pat00 = {
  1,
  { { -28, -25, 0, 412 } }
};
static sprite_pattern kumo_b_pat01 = {
  1,
  { { -28, -17, 0, 413 } }
};
static sprite_pattern kumo_b_pat02 = {
  1,
  { { -28, -13, 0, 414 } }
};
static sprite_pattern tama_pat00 = {
  1,
  { { -12, -8, 0, 415 } }
};
static sprite_pattern tama_pat01 = {
  1,
  { { -12, -8, 0, 416 } }
};
sprite_pattern* pat_kumo_e[3] = {
  &kumo_e_pat00,
  &kumo_e_pat01,
  &kumo_e_pat02
};
sprite_pattern* pat_kumo_b[3] = {
  &kumo_b_pat00,
  &kumo_b_pat01,
  &kumo_b_pat02
};
sprite_pattern* pat_tama[2] = {
  &tama_pat00,
  &tama_pat01
};










































































void kumo(sprite_status* pActwk) { /* Line 146, Address: 0x1020110 */
  void(*kumo_move_tbl[7])(sprite_status*) = { /* Line 147, Address: 0x102011c */
    kumo_init,
    kumo_jump,
    kumo_jump1,
    kumo_move,
    kumo_move1,
    kumo_tama,
    kumo_tama1
  };

  if (pActwk->userflag.b.h & 128) { /* Line 157, Address: 0x1020148 */

    tama(pActwk); /* Line 159, Address: 0x1020164 */
    return; /* Line 160, Address: 0x1020170 */
  }

  if (enemy_suicide(pActwk)) return; /* Line 163, Address: 0x1020178 */
  kumo_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 164, Address: 0x102018c */
  actionsub(pActwk); /* Line 165, Address: 0x10201c8 */
  frameout_s(pActwk); /* Line 166, Address: 0x10201d4 */
} /* Line 167, Address: 0x10201e0 */








static void kumo_init(sprite_status* pActwk) { /* Line 176, Address: 0x10201f0 */
  pActwk->r_no0 += 2; /* Line 177, Address: 0x10201fc */
  pActwk->actflg |= 4; /* Line 178, Address: 0x102020c */
  pActwk->sprpri = 3; /* Line 179, Address: 0x102021c */
  pActwk->sproffset = 9236; /* Line 180, Address: 0x1020228 */
  pActwk->sprhs = 24; /* Line 181, Address: 0x1020234 */
  pActwk->sprhsize = 24; /* Line 182, Address: 0x1020240 */
  pActwk->sprvsize = 24; /* Line 183, Address: 0x102024c */
  pActwk->colino = 53; /* Line 184, Address: 0x1020258 */

  if (!pActwk->userflag.b.h) { /* Line 186, Address: 0x1020264 */
    pActwk->patbase = pat_kumo_e; /* Line 187, Address: 0x1020274 */
    ((unsigned char***)pActwk)[12] = pchg_e; /* Line 188, Address: 0x1020284 */
    ((int*)pActwk)[13] = -524288; /* Line 189, Address: 0x1020294 */
  } /* Line 190, Address: 0x10202a0 */
  else {
    pActwk->patbase = pat_kumo_b; /* Line 192, Address: 0x10202a8 */
    ((unsigned char***)pActwk)[12] = pchg_b; /* Line 193, Address: 0x10202b8 */
    ((int*)pActwk)[13] = -327680; /* Line 194, Address: 0x10202c8 */
  }

  if (pActwk->userflag.b.l) { /* Line 197, Address: 0x10202d4 */
    pActwk->actflg |= 1; /* Line 198, Address: 0x10202e4 */
    pActwk->cddat |= 1; /* Line 199, Address: 0x10202f4 */
  }

  pActwk->r_no0 += 2; /* Line 202, Address: 0x1020304 */
  kumo_jump1(pActwk); /* Line 203, Address: 0x1020314 */
} /* Line 204, Address: 0x1020320 */








static void kumo_jump(sprite_status* pActwk) { /* Line 213, Address: 0x1020330 */
  pActwk->r_no0 += 2; /* Line 214, Address: 0x102033c */
  pActwk->patno = 0; /* Line 215, Address: 0x102034c */
  pActwk->yposi.w.h -= 8; /* Line 216, Address: 0x1020354 */
  ((int*)pActwk)[14] = ((int*)pActwk)[13]; /* Line 217, Address: 0x1020364 */
  kumo_jump1(pActwk); /* Line 218, Address: 0x1020374 */
} /* Line 219, Address: 0x1020380 */








static void kumo_jump1(sprite_status* pActwk) { /* Line 228, Address: 0x1020390 */
  short wD1;

  ((int*)pActwk)[14] += 16384; /* Line 231, Address: 0x10203a0 */
  pActwk->yposi.l += ((int*)pActwk)[14]; /* Line 232, Address: 0x10203b0 */
  if ((wD1 = emycol_d(pActwk)) < 0) { /* Line 233, Address: 0x10203c8 */
    pActwk->yposi.w.h += wD1; /* Line 234, Address: 0x10203f4 */
    pActwk->r_no0 += 2; /* Line 235, Address: 0x1020404 */
    pActwk->patno = 1; /* Line 236, Address: 0x1020414 */
    pActwk->yposi.w.h += 8; /* Line 237, Address: 0x1020420 */
  }

} /* Line 240, Address: 0x1020430 */








static void kumo_move(sprite_status* pActwk) { /* Line 249, Address: 0x1020450 */
  pActwk->r_no0 += 2; /* Line 250, Address: 0x102045c */
  pActwk->colino = 54; /* Line 251, Address: 0x102046c */
  ((short*)pActwk)[23] = 180; /* Line 252, Address: 0x1020478 */
  kumo_move1(pActwk); /* Line 253, Address: 0x1020484 */
} /* Line 254, Address: 0x1020490 */








static void kumo_move1(sprite_status* pActwk) { /* Line 263, Address: 0x10204a0 */
  if (!pActwk->userflag.b.h) { /* Line 264, Address: 0x10204ac */
    if (kumo_check(pActwk, &actwk[0])) { /* Line 265, Address: 0x10204bc */
      pActwk->r_no0 += 2; /* Line 266, Address: 0x10204d8 */
      pActwk->patno = 1; /* Line 267, Address: 0x10204e8 */
      ((short*)pActwk)[23] = 60; /* Line 268, Address: 0x10204f4 */
      return; /* Line 269, Address: 0x1020500 */
    }
  }

  if (--((short*)pActwk)[23] == 0) { /* Line 273, Address: 0x1020508 */
    pActwk->r_no0 -= 6; /* Line 274, Address: 0x1020530 */
  }
  patchg(pActwk, ((unsigned char***)pActwk)[12]); /* Line 276, Address: 0x1020540 */
} /* Line 277, Address: 0x1020554 */


static short kumo_check(sprite_status* pActwk0, sprite_status* pActwk1) { /* Line 280, Address: 0x1020570 */
  short wD0, wD1;

  if (pActwk1->yposi.w.h - pActwk0->yposi.w.h + 80 < 160) { /* Line 283, Address: 0x1020584 */
    wD0 = pActwk1->xposi.w.h - pActwk0->xposi.w.h; /* Line 284, Address: 0x10205b8 */
    wD1 = wD0 - 80; /* Line 285, Address: 0x10205ec */
    if (wD0 + 80 < 160) { /* Line 286, Address: 0x1020608 */
      if (wD0 < 0) wD0 = -1; /* Line 287, Address: 0x1020620 */
      else wD0 = 0; /* Line 288, Address: 0x1020644 */
      if (pActwk0->actflg & 1) wD1 = 0; /* Line 289, Address: 0x1020648 */
      else wD1 = -1; /* Line 290, Address: 0x102066c */
      if (!(wD0 ^ wD1)) { /* Line 291, Address: 0x1020678 */
        pActwk0->actflg ^= 1; /* Line 292, Address: 0x1020694 */
        pActwk0->cddat ^= 1; /* Line 293, Address: 0x10206a4 */
        return -1; /* Line 294, Address: 0x10206b4 */
      }
    }
  }

  return 0; /* Line 299, Address: 0x10206c0 */
} /* Line 300, Address: 0x10206c4 */








static void kumo_tama(sprite_status* pActwk) { /* Line 309, Address: 0x10206e0 */
  if (!(--((short*)pActwk)[23])) { /* Line 310, Address: 0x10206e8 */
    pActwk->r_no0 += 2; /* Line 311, Address: 0x1020708 */
  }
} /* Line 313, Address: 0x1020718 */








static void kumo_tama1(sprite_status* pActwk) { /* Line 322, Address: 0x1020730 */
  sprite_status* pNewactwk;
  short wD0;
  int lD1;

  if (actwkchk(&pNewactwk) == 0) { /* Line 327, Address: 0x1020744 */
    pNewactwk->actno = pActwk->actno; /* Line 328, Address: 0x1020758 */
    pNewactwk->userflag.b.h = -1; /* Line 329, Address: 0x1020768 */
    pNewactwk->xposi.w.h = pActwk->xposi.w.h; /* Line 330, Address: 0x1020774 */
    pNewactwk->yposi.w.h = pActwk->yposi.w.h; /* Line 331, Address: 0x1020784 */
    pNewactwk->actflg = pActwk->actflg; /* Line 332, Address: 0x1020794 */
    pNewactwk->sprpri = 1; /* Line 333, Address: 0x10207a4 */
    pNewactwk->sproffset = pActwk->sproffset; /* Line 334, Address: 0x10207b0 */
    pNewactwk->sprhs = 12; /* Line 335, Address: 0x10207c0 */
    pNewactwk->sprhsize = 12; /* Line 336, Address: 0x10207cc */
    pNewactwk->sprvsize = 8; /* Line 337, Address: 0x10207d8 */
    pNewactwk->colino = 247; /* Line 338, Address: 0x10207e4 */
    pNewactwk->patbase = pat_tama; /* Line 339, Address: 0x10207f0 */
    wD0 = 24; /* Line 340, Address: 0x1020800 */
    lD1 = 196608; /* Line 341, Address: 0x102080c */
    if (pNewactwk->actflg & 1) { /* Line 342, Address: 0x1020810 */
      wD0 *= -1; /* Line 343, Address: 0x1020828 */
      lD1 *= -1; /* Line 344, Address: 0x1020834 */
    }

    pNewactwk->xposi.w.h += wD0; /* Line 347, Address: 0x1020838 */
    ((int*)pNewactwk)[14] = lD1; /* Line 348, Address: 0x1020848 */
    if (pActwk->actflg & 128) { /* Line 349, Address: 0x1020850 */
      soundset(160); /* Line 350, Address: 0x1020868 */
    }
  }
  pActwk->r_no0 -= 10; /* Line 353, Address: 0x1020874 */
} /* Line 354, Address: 0x1020884 */








static void tama(sprite_status* pActwk) { /* Line 363, Address: 0x10208a0 */
  if (!((short*)pActwk)[23]) { /* Line 364, Address: 0x10208ac */
    if (pActwk->colicnt) { /* Line 365, Address: 0x10208bc */
      pActwk->colicnt = 0; /* Line 366, Address: 0x10208cc */
      if (actwk[0].r_no0 != 4) { /* Line 367, Address: 0x10208d4 */
        if (actwk[0].r_no0 != 6) { /* Line 368, Address: 0x10208ec */
          if (!((short*)&actwk[0])[26]) { /* Line 369, Address: 0x1020904 */

            ((short*)pActwk)[23] = 120; /* Line 371, Address: 0x1020914 */
            goto label1; /* Line 372, Address: 0x1020920 */
          }
        }
      }
    }

    pActwk->xposi.l += ((int*)pActwk)[14]; /* Line 378, Address: 0x1020928 */
    patchg(pActwk, pchg_tama); /* Line 379, Address: 0x1020940 */
    actionsub(pActwk); /* Line 380, Address: 0x1020954 */
    frameout_s(pActwk); /* Line 381, Address: 0x1020960 */
    return; /* Line 382, Address: 0x102096c */
  }

label1:
  if (!(--((short*)pActwk)[23])) { /* Line 386, Address: 0x1020974 */
    frameout(pActwk); /* Line 387, Address: 0x1020994 */
    return; /* Line 388, Address: 0x10209a0 */
  }
  pActwk->xposi.w.h = actwk[0].xposi.w.h; /* Line 390, Address: 0x10209a8 */
  pActwk->yposi.w.h = actwk[0].yposi.w.h; /* Line 391, Address: 0x10209b8 */
  actwk[0].xspeed.w = 0; /* Line 392, Address: 0x10209c8 */
  actwk[0].mspeed.w = 0; /* Line 393, Address: 0x10209d0 */

  patchg(pActwk, pchg_tama); /* Line 395, Address: 0x10209d8 */
  actionsub(pActwk); /* Line 396, Address: 0x10209ec */
  frameout_s(pActwk); /* Line 397, Address: 0x10209f8 */
} /* Line 398, Address: 0x1020a04 */
