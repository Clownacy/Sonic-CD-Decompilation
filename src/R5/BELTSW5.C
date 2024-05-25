#include "..\EQU.H"
#include "BELTSW5.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"

static void beltsw5_init(sprite_status* pActwk);
static void beltsw5_move1(sprite_status* pActwk);
static void beltsw5_move2(sprite_status* pActwk);
static void beltsw5_move3(sprite_status* pActwk);

static sprite_pattern beltsw5_pat0 = {
  1,
  { { -4, -16, 0, 406 } }
};
static sprite_pattern beltsw5_pat1 = {
  1,
  { { -8, -36, 0, 407 } }
};
static sprite_pattern beltsw5_pat2 = {
  1,
  { { -28, -16, 0, 408 } }
};
sprite_pattern* beltsw5pat[3] = {
  &beltsw5_pat0,
  &beltsw5_pat1,
  &beltsw5_pat2
};









































void beltsw5(sprite_status* pActwk) { /* Line 70, Address: 0x101d420 */
  void(*beltsw5_move_tbl[4])(sprite_status*) = { /* Line 71, Address: 0x101d42c */
    &beltsw5_init,
    &beltsw5_move1,
    &beltsw5_move2,
    &beltsw5_move3
  };

  beltsw5_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 78, Address: 0x101d458 */
  actionsub(pActwk); /* Line 79, Address: 0x101d494 */
  frameout_s(pActwk); /* Line 80, Address: 0x101d4a0 */
} /* Line 81, Address: 0x101d4ac */








static void beltsw5_init(sprite_status* pActwk) { /* Line 90, Address: 0x101d4c0 */
  pActwk->r_no0 += 2; /* Line 91, Address: 0x101d4cc */
  pActwk->actflg |= 4; /* Line 92, Address: 0x101d4dc */
  pActwk->sprpri = 3; /* Line 93, Address: 0x101d4ec */
  pActwk->sprhsize = 24; /* Line 94, Address: 0x101d4f8 */
  pActwk->sprvsize = 24; /* Line 95, Address: 0x101d504 */
  pActwk->sproffset = 18327; /* Line 96, Address: 0x101d510 */
  pActwk->patbase = beltsw5pat; /* Line 97, Address: 0x101d51c */

  if (colrevflag & 1) pActwk->patno = 2; /* Line 99, Address: 0x101d52c */
  pActwk->actfree[18] = colrevflag; /* Line 100, Address: 0x101d550 */
  beltsw5_move1(pActwk); /* Line 101, Address: 0x101d560 */
} /* Line 102, Address: 0x101d56c */








static void beltsw5_move1(sprite_status* pActwk) { /* Line 111, Address: 0x101d580 */
  short wD0;

  if (!editmode.b.h) { /* Line 114, Address: 0x101d590 */
    wD0 = actwk[0].yposi.w.h - pActwk->yposi.w.h; /* Line 115, Address: 0x101d5a0 */
    if ((unsigned short)actwk[0].yposi.w.h < (unsigned short)pActwk->yposi.w.h) wD0 *= -1; /* Line 116, Address: 0x101d5d4 */
    if ((unsigned short)wD0 < 16) { /* Line 117, Address: 0x101d60c */
      wD0 = actwk[0].xposi.w.h - pActwk->xposi.w.h; /* Line 118, Address: 0x101d620 */
      if ((unsigned short)actwk[0].xposi.w.h < (unsigned short)pActwk->xposi.w.h) wD0 *= -1; /* Line 119, Address: 0x101d654 */
      if ((unsigned short)wD0 < 8) { /* Line 120, Address: 0x101d68c */
        colrevflag ^= 1; /* Line 121, Address: 0x101d6a0 */
        pActwk->r_no0 += 2; /* Line 122, Address: 0x101d6b4 */

        if (pActwk->actflg & 128) soundset(191); /* Line 124, Address: 0x101d6c4 */
        return; /* Line 125, Address: 0x101d6e8 */
      }
    }
  }

  if (colrevflag != pActwk->actfree[18]) { /* Line 130, Address: 0x101d6f0 */
    pActwk->actfree[19] = 255; /* Line 131, Address: 0x101d710 */
    pActwk->r_no0 += 2; /* Line 132, Address: 0x101d71c */
  }

  pActwk->actfree[18] = colrevflag; /* Line 135, Address: 0x101d72c */
} /* Line 136, Address: 0x101d73c */








static void beltsw5_move2(sprite_status* pActwk) { /* Line 145, Address: 0x101d750 */
  ++pActwk->actfree[16]; /* Line 146, Address: 0x101d758 */
  if (pActwk->actfree[16] == 7) { /* Line 147, Address: 0x101d768 */
    pActwk->patno = 1; /* Line 148, Address: 0x101d780 */
  } /* Line 149, Address: 0x101d78c */
  else {

    if (pActwk->actfree[16] == 14) { /* Line 152, Address: 0x101d794 */
      pActwk->actfree[16] = 0; /* Line 153, Address: 0x101d7ac */
      pActwk->patno = 0; /* Line 154, Address: 0x101d7b4 */
      if (colrevflag & 1) pActwk->patno = 2; /* Line 155, Address: 0x101d7bc */

      pActwk->r_no0 += 2; /* Line 157, Address: 0x101d7e0 */
      pActwk->actfree[19] = 0; /* Line 158, Address: 0x101d7f0 */
    }
  }
} /* Line 161, Address: 0x101d7f8 */








static void beltsw5_move3(sprite_status* pActwk) { /* Line 170, Address: 0x101d810 */
  short wD0;

  wD0 = actwk[0].yposi.w.h - pActwk->yposi.w.h; /* Line 173, Address: 0x101d81c */
  if ((unsigned short)actwk[0].yposi.w.h < (unsigned short)pActwk->yposi.w.h) wD0 *= -1; /* Line 174, Address: 0x101d850 */
  if ((unsigned short)wD0 < 32) { /* Line 175, Address: 0x101d888 */
    wD0 = actwk[0].xposi.w.h - pActwk->xposi.w.h; /* Line 176, Address: 0x101d89c */
    if ((unsigned short)actwk[0].xposi.w.h < (unsigned short)pActwk->xposi.w.h) wD0 *= -1; /* Line 177, Address: 0x101d8d0 */
    if ((unsigned short)wD0 < 16) return; /* Line 178, Address: 0x101d908 */
  }



  pActwk->r_no0 = 2; /* Line 183, Address: 0x101d91c */
  pActwk->actfree[18] = colrevflag; /* Line 184, Address: 0x101d928 */
} /* Line 185, Address: 0x101d938 */
