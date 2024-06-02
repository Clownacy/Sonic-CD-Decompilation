#include "..\EQU.H"
#include "WALLS.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

static void main_init(sprite_status* pActwk);
static void main_move(sprite_status* pActwk);
static void opt_check(sprite_status* pActwk);

static sprite_pattern pat00 = {
  1,
  { { -16, -16, 0, 446 } }
};
static sprite_pattern pat01 = {
  1,
  { { -32, -16, 0, 447 } }
};
static sprite_pattern pat02 = {
  1,
  { { -48, -16, 0, 448 } }
};
static sprite_pattern pat03 = {
  1,
  { { -64, -16, 0, 449 } }
};
static sprite_pattern pat04;
sprite_pattern* pat_walls[5] = {
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04
};
static unsigned char patno_tbl[9][8] = {
  { 2, 1, 1, 2, 2, 1, 1, 2 },
  { 0, 3, 1, 2, 2, 1, 3, 0 },
  { 3, 0, 0, 3, 3, 0, 0, 3 },
  { 1, 2, 0, 0, 0, 0, 2, 1 },
  { 2, 1, 1, 2, 1, 2, 2, 1 },
  { 0, 3, 2, 0, 2, 0, 0, 3 },
  { 3, 0, 0, 0, 0, 0, 0, 3 },
  { 2, 1, 1, 2, 3, 0, 0, 3 },
  { 1, 2, 1, 1, 1, 1, 2, 1 }
};
static int data_tbl[8] = {
  60, 0,  48, 131072,
  60, 0, 192, -32768
};






















































































































void walls(sprite_status* pActwk) { /* Line 168, Address: 0x101da50 */
  if (pActwk->userflag.b.h & 128) { /* Line 169, Address: 0x101da5c */

    opt_check(pActwk); /* Line 171, Address: 0x101da78 */
    return; /* Line 172, Address: 0x101da84 */
  } else if (!pActwk->r_no0) { /* Line 173, Address: 0x101da8c */
    main_init(pActwk); /* Line 174, Address: 0x101da9c */
  }

  main_move(pActwk); /* Line 177, Address: 0x101daa8 */

} /* Line 179, Address: 0x101dab4 */





static void main_init(sprite_status* pActwk) { /* Line 185, Address: 0x101dad0 */
  unsigned char *pOptwk, *pPatno, patnowk;
  int i, j;
  sprite_status* pNewact;

  pActwk->r_no0 += 2; /* Line 190, Address: 0x101daf0 */
  ((short*)pActwk)[26] = pActwk->xposi.w.h; /* Line 191, Address: 0x101db00 */
  pActwk->actflg |= 4; /* Line 192, Address: 0x101db10 */
  pActwk->sprpri = 3; /* Line 193, Address: 0x101db20 */
  pActwk->sprhs = 16; /* Line 194, Address: 0x101db2c */
  pActwk->sprhsize = 16; /* Line 195, Address: 0x101db38 */
  pActwk->sprvsize = 16; /* Line 196, Address: 0x101db44 */
  pActwk->sproffset = 17514; /* Line 197, Address: 0x101db50 */
  pActwk->patbase = pat_walls; /* Line 198, Address: 0x101db5c */
  pActwk->patno = 4; /* Line 199, Address: 0x101db6c */
  ((short*)pActwk)[27] = pActwk - actwk; /* Line 200, Address: 0x101db78 */
  ((short*)pActwk)[23] = 192; /* Line 201, Address: 0x101dbb0 */
  ((int*)pActwk)[12] = -32768; /* Line 202, Address: 0x101dbbc */

  pOptwk = &pActwk->actfree[14]; /* Line 204, Address: 0x101dbc8 */
  pPatno = patno_tbl[pActwk->userflag.b.h + 1]; /* Line 205, Address: 0x101dbd0 */

  for (i = 3; i >= 0; --i) { /* Line 207, Address: 0x101dbf4 */

    for (j = 1; j >= 0; --j) { /* Line 209, Address: 0x101dc00 */

      if (actwkchk2(pActwk, &pNewact) != 0) { /* Line 211, Address: 0x101dc0c */
        frameout(pActwk); /* Line 212, Address: 0x101dc24 */
        return; /* Line 213, Address: 0x101dc30 */
      }


      *pOptwk++ = pNewact - actwk; /* Line 217, Address: 0x101dc38 */
      pNewact->userflag.b.h = (j - 2) & 255; /* Line 218, Address: 0x101dc70 */
      pNewact->yposi.w.h = pActwk->yposi.w.h - 48 + (short)(i * 32); /* Line 219, Address: 0x101dc88 */

      pNewact->patno = patnowk = *--pPatno; /* Line 221, Address: 0x101dcc4 */
      pNewact->sprhsize = pNewact->sprhs = (patnowk + 1) * 16; /* Line 222, Address: 0x101dcd8 */
      if (j != 0) { /* Line 223, Address: 0x101dcfc */
        pNewact->xposi.w.h = pActwk->xposi.w.h + 64 - (short)(patnowk * 16); /* Line 224, Address: 0x101dd04 */

      } else { /* Line 226, Address: 0x101dd44 */
        pNewact->xposi.w.h = pActwk->xposi.w.h - 64 + (short)(patnowk * 16); /* Line 227, Address: 0x101dd4c */
      }

      ((short*)pNewact)[27] = pActwk - actwk; /* Line 230, Address: 0x101dd8c */
      pNewact->actno = pActwk->actno; /* Line 231, Address: 0x101ddc4 */
      pNewact->actflg = pActwk->actflg; /* Line 232, Address: 0x101ddd4 */
      pNewact->sprpri = pActwk->sprpri; /* Line 233, Address: 0x101dde4 */
      pNewact->sprvsize = pActwk->sprvsize; /* Line 234, Address: 0x101ddf4 */
      pNewact->sproffset = pActwk->sproffset; /* Line 235, Address: 0x101de04 */
      pNewact->patbase = pActwk->patbase; /* Line 236, Address: 0x101de14 */
    } /* Line 237, Address: 0x101de24 */
  } /* Line 238, Address: 0x101de30 */

  main_move(pActwk); /* Line 240, Address: 0x101de3c */
} /* Line 241, Address: 0x101de48 */





static void main_move(sprite_status* pActwk) { /* Line 247, Address: 0x101de70 */
  unsigned char* pOptwk;
  int i;
  int spdwk;
  sprite_status* pChildact;

  pOptwk = &pActwk->actfree[14]; /* Line 253, Address: 0x101de8c */
  spdwk = ((int*)pActwk)[12]; /* Line 254, Address: 0x101de94 */

  for (i = 3; i >= 0; --i) { /* Line 256, Address: 0x101de9c */

    pChildact = &actwk[*pOptwk++]; /* Line 258, Address: 0x101dea8 */
    pChildact->xposi.l -= spdwk; /* Line 259, Address: 0x101ded0 */
    pChildact->xspeed.w = -(spdwk >> 8); /* Line 260, Address: 0x101dedc */

    pChildact = &actwk[*pOptwk++]; /* Line 262, Address: 0x101def0 */
    pChildact->xposi.l += spdwk; /* Line 263, Address: 0x101df18 */
    pChildact->xspeed.w = spdwk >> 8; /* Line 264, Address: 0x101df24 */
  } /* Line 265, Address: 0x101df34 */

  if (--((short*)pActwk)[23] == 0) { /* Line 267, Address: 0x101df40 */
    ((short*)pActwk)[23] = data_tbl[((short*)pActwk)[28] / 4]; /* Line 268, Address: 0x101df68 */

    ((int*)pActwk)[12] = data_tbl[((short*)pActwk)[28] / 4 + 1]; /* Line 270, Address: 0x101dfb4 */

    ((short*)pActwk)[28] += 8; /* Line 272, Address: 0x101dffc */
    ((short*)pActwk)[28] &= 31; /* Line 273, Address: 0x101e00c */
  }


  frameout_s00(pActwk, ((short*)pActwk)[26]); /* Line 277, Address: 0x101e01c */
} /* Line 278, Address: 0x101e030 */





static void opt_check(sprite_status* pActwk) { /* Line 284, Address: 0x101e050 */
  if (actwk[((short*)pActwk)[27]].actno != 51) { /* Line 285, Address: 0x101e05c */
    frameout(pActwk); /* Line 286, Address: 0x101e098 */
  } else { /* Line 287, Address: 0x101e0a4 */
    hitchk(pActwk, &actwk[0]); /* Line 288, Address: 0x101e0ac */
    actionsub(pActwk); /* Line 289, Address: 0x101e0c0 */
  }
} /* Line 291, Address: 0x101e0cc */
