#include "..\EQU.H"
#include "GA3.H"

static sprite_pattern spat_b3 = {
  1,
  { { -16, -10, 0, 529 } }
};
static sprite_pattern spat_b4 = {
  1,
  { { -16, -8, 0, 530 } }
};
static sprite_pattern spat_b5 = {
  1,
  { { -16, -10, 0, 531 } }
};
static sprite_pattern spat_e3 = {
  1,
  { { -16, -12, 0, 532 } }
};
static sprite_pattern spat_e4 = {
  1,
  { { -16, -8, 0, 533 } }
};
static sprite_pattern spat_e5 = {
  1,
  { { -16, -8, 0, 534 } }
};
static sprite_pattern spat_0 = {
  1,
  { { -12, -12, 0, 535 } }
};
static sprite_pattern spat_1 = {
  1,
  { { -12, -12, 0, 536 } }
};
static sprite_pattern spat_2 = {
  1,
  { { -12, -16, 0, 537 } }
};
sprite_pattern* pat_b_ga[6] = {
  &spat_0,
  &spat_1,
  &spat_2,
  &spat_b3,
  &spat_b4,
  &spat_b5
};
sprite_pattern* pat_e_ga[6] = {
  &spat_0,
  &spat_1,
  &spat_2,
  &spat_e3,
  &spat_e4,
  &spat_e5
};
static char pchg0[4] = { 29, 0, 1, 1 };
static char pchg1[3] = { 49, 2, 2 };
static char pchg2[6] = { 4, 3, 4, 5, 4, -1 };
static char* pchg[3] = {
  pchg0,
  pchg1,
  pchg2
};
static char ringchg0[6] = { 5, 4, 5, 6, 7, -1 };
static char* ringchg[1] = { ringchg0 };
extern sprite_pattern* ringpat[];





























void ga(sprite_status* actionwk) { /* Line 96, Address: 0x101d910 */
  if (actionwk->userflag.b.h - 1 < 0) /* Line 97, Address: 0x101d91c */
    eb_ga0(actionwk); /* Line 98, Address: 0x101d938 */
  else
    eb_ga1(actionwk); /* Line 100, Address: 0x101d94c */
} /* Line 101, Address: 0x101d958 */

void eb_ga0(sprite_status* actionwk) { /* Line 103, Address: 0x101d970 */


  if (enemy_suicide(actionwk) == -1) return; /* Line 106, Address: 0x101d97c */



  switch (actionwk->r_no0) { /* Line 110, Address: 0x101d99c */

    case 0:
      m_init(actionwk); /* Line 113, Address: 0x101d9e8 */
    case 2:
      m_wait(actionwk); /* Line 115, Address: 0x101d9f4 */
      break; /* Line 116, Address: 0x101da00 */
    case 4:
      m_appear0(actionwk); /* Line 118, Address: 0x101da08 */
      break; /* Line 119, Address: 0x101da14 */
    case 6:
      m_appear1(actionwk); /* Line 121, Address: 0x101da1c */
      break; /* Line 122, Address: 0x101da28 */
    case 8:
      m_move(actionwk); /* Line 124, Address: 0x101da30 */
      break;
  }
  actionsub(actionwk); /* Line 127, Address: 0x101da3c */
  frameout_s(actionwk); /* Line 128, Address: 0x101da48 */
} /* Line 129, Address: 0x101da54 */

static void m_init(sprite_status* actionwk) { /* Line 131, Address: 0x101da70 */
  actionwk->r_no0 += 2; /* Line 132, Address: 0x101da78 */
  actionwk->actflg |= 4; /* Line 133, Address: 0x101da88 */
  actionwk->patno = 0; /* Line 134, Address: 0x101da98 */
  actionwk->sprpri = 1; /* Line 135, Address: 0x101daa0 */
  actionwk->sprhsize = 16; /* Line 136, Address: 0x101daac */
  actionwk->sprvsize = 8; /* Line 137, Address: 0x101dab8 */
  actionwk->sproffset = 42017; /* Line 138, Address: 0x101dac4 */
  ((short*)actionwk)[23] = 61; /* Line 139, Address: 0x101dad0 */
  if (actionwk->userflag.b.h & 128) /* Line 140, Address: 0x101dadc */
    actionwk->patbase = pat_b_ga; /* Line 141, Address: 0x101daf8 */
  else {

    actionwk->patbase = pat_e_ga; /* Line 144, Address: 0x101db10 */
    actionwk->actfree[21] = 255; /* Line 145, Address: 0x101db20 */
  }
} /* Line 147, Address: 0x101db2c */

static void m_wait(sprite_status* actionwk) { /* Line 149, Address: 0x101db40 */
  if (--((short*)actionwk)[23] == 0) { /* Line 150, Address: 0x101db48 */

    actionwk->r_no0 += 2; /* Line 152, Address: 0x101db70 */
    ((short*)actionwk)[23] = 61; /* Line 153, Address: 0x101db80 */
  }
} /* Line 155, Address: 0x101db8c */

void m_appear0(sprite_status* actionwk) { /* Line 157, Address: 0x101dba0 */
  if (--((short*)actionwk)[23] == 0) { /* Line 158, Address: 0x101dbac */

    actionwk->colino = 37; /* Line 160, Address: 0x101dbd4 */
    actionwk->r_no0 += 2; /* Line 161, Address: 0x101dbe0 */
    ++actionwk->mstno.b.h; /* Line 162, Address: 0x101dbf0 */
    ((short*)actionwk)[23] = 51; /* Line 163, Address: 0x101dc00 */
  }
  m_disp(actionwk); /* Line 165, Address: 0x101dc0c */
} /* Line 166, Address: 0x101dc18 */

void m_disp(sprite_status* actionwk) { /* Line 168, Address: 0x101dc30 */
  patchg(actionwk, pchg); /* Line 169, Address: 0x101dc3c */
  actionsub(actionwk); /* Line 170, Address: 0x101dc50 */
} /* Line 171, Address: 0x101dc5c */

void m_appear1(sprite_status* actionwk) { /* Line 173, Address: 0x101dc70 */
  if (--((short*)actionwk)[23] == 0) { /* Line 174, Address: 0x101dc7c */

    actionwk->colino = 38; /* Line 176, Address: 0x101dca4 */
    actionwk->r_no0 += 2; /* Line 177, Address: 0x101dcb0 */
    ++actionwk->mstno.b.h; /* Line 178, Address: 0x101dcc0 */
    ((int*)actionwk)[13] = 32768; /* Line 179, Address: 0x101dcd0 */
    ((short*)actionwk)[23] = 32; /* Line 180, Address: 0x101dcdc */
    ((int*)actionwk)[12] = -32768; /* Line 181, Address: 0x101dce8 */
    if (actionwk->userflag.b.h < 0) { /* Line 182, Address: 0x101dcf4 */
      ((short*)actionwk)[23] = 48; /* Line 183, Address: 0x101dd0c */
      ((int*)actionwk)[12] = -16384; /* Line 184, Address: 0x101dd18 */
    }
    if (actionwk->xposi.w.h - actwk[0].xposi.w.h < 0) { /* Line 186, Address: 0x101dd24 */

      ((int*)actionwk)[12] = -((int*)actionwk)[12]; /* Line 188, Address: 0x101dd50 */

      actionwk->actflg |= 1; /* Line 190, Address: 0x101dd64 */
      actionwk->cddat |= 1; /* Line 191, Address: 0x101dd74 */
    }
  }
  m_disp(actionwk); /* Line 194, Address: 0x101dd84 */
} /* Line 195, Address: 0x101dd90 */

void m_move(sprite_status* actionwk) { /* Line 197, Address: 0x101dda0 */
  sprite_status* a1;

  actionwk->xposi.l += ((int*)actionwk)[12]; /* Line 200, Address: 0x101ddac */
  actionwk->yposi.l += ((int*)actionwk)[13]; /* Line 201, Address: 0x101ddc4 */
  if (--((short*)actionwk)[23] == 0) { /* Line 202, Address: 0x101dddc */

    ((short*)actionwk)[23] = 65; /* Line 204, Address: 0x101de04 */
    if (actionwk->userflag.b.h < 0) { /* Line 205, Address: 0x101de10 */

      ((short*)actionwk)[23] = 97; /* Line 207, Address: 0x101de28 */
    }
    ((int*)actionwk)[13] = -((int*)actionwk)[13]; /* Line 209, Address: 0x101de34 */

    if (actionwk->actfree[21] != 0) { /* Line 211, Address: 0x101de48 */

      if (actwkchk(&a1) == 0) { /* Line 213, Address: 0x101de5c */
        a1->actno = actionwk->actno; /* Line 214, Address: 0x101de70 */
        a1->xposi.l = actionwk->xposi.l; /* Line 215, Address: 0x101de80 */
        a1->yposi.l = actionwk->yposi.l; /* Line 216, Address: 0x101de90 */
        a1->userflag.b.h = 1; /* Line 217, Address: 0x101dea0 */
      }
    }
  }
  m_disp(actionwk); /* Line 221, Address: 0x101deac */
} /* Line 222, Address: 0x101deb8 */






void eb_ga1(sprite_status* actionwk) { /* Line 229, Address: 0x101ded0 */
  switch (actionwk->r_no0) { /* Line 230, Address: 0x101dedc */

    case 0:
      s_init(actionwk); /* Line 233, Address: 0x101df10 */
    case 2:
      s_fall(actionwk); /* Line 235, Address: 0x101df1c */
      break; /* Line 236, Address: 0x101df28 */
    case 4:
      s_die(actionwk); /* Line 238, Address: 0x101df30 */
      return; /* Line 239, Address: 0x101df3c */
  }
  actionsub(actionwk); /* Line 241, Address: 0x101df44 */
} /* Line 242, Address: 0x101df50 */

static void s_init(sprite_status* actionwk) { /* Line 244, Address: 0x101df60 */
  actionwk->r_no0 += 2; /* Line 245, Address: 0x101df68 */
  actionwk->actflg |= 4; /* Line 246, Address: 0x101df78 */
  actionwk->sprpri = 1; /* Line 247, Address: 0x101df88 */

  actionwk->sprhs = 6; /* Line 249, Address: 0x101df94 */
  actionwk->sprhsize = 6; /* Line 250, Address: 0x101dfa0 */
  actionwk->sprvsize = 6; /* Line 251, Address: 0x101dfac */
  actionwk->sproffset = 42926; /* Line 252, Address: 0x101dfb8 */
  actionwk->patbase = ringpat; /* Line 253, Address: 0x101dfc4 */
  actionwk->sprhsize = 6; /* Line 254, Address: 0x101dfd4 */
  ((short*)actionwk)[23] = 180; /* Line 255, Address: 0x101dfe0 */
} /* Line 256, Address: 0x101dfec */

void s_fall(sprite_status* actionwk) { /* Line 258, Address: 0x101e000 */
  if (--((short*)actionwk)[23] == 0) { /* Line 259, Address: 0x101e00c */

    s_die(actionwk); /* Line 261, Address: 0x101e034 */
    return; /* Line 262, Address: 0x101e040 */
  }










  actionwk->yposi.l += 65536; /* Line 274, Address: 0x101e048 */
  patchg(actionwk, ringchg); /* Line 275, Address: 0x101e05c */
} /* Line 276, Address: 0x101e070 */

void s_die(sprite_status* actionwk) { /* Line 278, Address: 0x101e080 */
  frameout(actionwk); /* Line 279, Address: 0x101e08c */
} /* Line 280, Address: 0x101e098 */
