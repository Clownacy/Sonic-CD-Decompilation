#include "..\EQU.H"
#include "MOVIE3.H"

static unsigned char pchg00[6] = { 0, 2, 1, 3, 1, 255 };
static unsigned char pchg01[58] = {
  0, 4, 4, 1, 4, 4, 1, 4, 4, 1,
  4, 4, 1, 4, 4, 1, 1, 4, 4, 1,
  1, 4, 4, 1, 1, 4, 4, 1, 1, 5,
  5, 1, 5, 5, 1, 5, 5, 1, 5, 5,
  1, 5, 5, 1, 1, 5, 5, 1, 1, 5,
  5, 1, 1, 5, 5, 1, 1, 255
};
static unsigned char* pchg[2] = {
  pchg00,
  pchg01
};
static sprite_pattern mov00 = { 1, { { -12, -12, 0, 316 } } };
static sprite_pattern pat00 = { 1, { { -16, -20, 0, 0 } } };
static sprite_pattern mov01 = { 1, { { -8, -4, 0, 317 } } };
static sprite_pattern mov02 = { 1, { { -8, -4, 0, 318 } } };
static sprite_pattern mov03 = { 1, { { -20, -24, 0, 319 } } };
static sprite_pattern mov04 = { 1, { { -20, -24, 0, 320 } } };
sprite_pattern* pat_movie[6] = {
  &mov00,
  &pat00,
  &mov01,
  &mov02,
  &mov03,
  &mov04
};
static char tbl0[37] = {
    1,   0,   0,
    5, -18, -10,
   10, -10,  10,
   15,   0, -18,
   20, -10,  18,
   22,   8,  23,
   25,  13, -10,
   28,  -3, -25,
   30,  10,  20,
   32, -10,   2,
   35,  13, -10,
   40, -10,  10,
   -1
};









void movie(sprite_status* moviewk) { /* Line 55, Address: 0x102e7e0 */
  void(*act_tbl[5])(sprite_status*) = { &m_init, &m_wait, &m_die, &m_baku, &m1wait }; /* Line 56, Address: 0x102e7ec */

  if (moviewk->userflag.b.h != 0) { sub(moviewk); return; } /* Line 58, Address: 0x102e818 */

  act_tbl[moviewk->r_no0 / 2](moviewk); /* Line 60, Address: 0x102e844 */
  actionsub(moviewk); /* Line 61, Address: 0x102e880 */
  if (moviewk->r_no0 >= 3) return; /* Line 62, Address: 0x102e88c */
  frameout_s(moviewk); /* Line 63, Address: 0x102e8a4 */
  if (moviewk->actno == 0) divdevset(4); /* Line 64, Address: 0x102e8b0 */
} /* Line 65, Address: 0x102e8d0 */



static void die(sprite_status* moviewk) { /* Line 69, Address: 0x102e8e0 */
  frameout(moviewk); /* Line 70, Address: 0x102e8ec */
} /* Line 71, Address: 0x102e8f8 */


static void m_init(sprite_status* moviewk) { /* Line 74, Address: 0x102e910 */
  sprite_status* new_actwk;

  if (projector_flag != 0) { die(moviewk); return; } /* Line 77, Address: 0x102e91c */
  divdevset(5); /* Line 78, Address: 0x102e944 */

  moviewk->r_no0 += 2; /* Line 80, Address: 0x102e950 */
  moviewk->actflg |= 4; /* Line 81, Address: 0x102e960 */
  moviewk->sprpri = 4; /* Line 82, Address: 0x102e970 */
  moviewk->sprhs = moviewk->sprhsize = moviewk->sprvsize = 12; /* Line 83, Address: 0x102e97c */
  moviewk->colino = 251; /* Line 84, Address: 0x102e9a0 */

  moviewk->patbase = pat_movie; /* Line 86, Address: 0x102e9ac */
  ((char**)moviewk)[12] = tbl0; /* Line 87, Address: 0x102e9bc */

  if (actwkchk(&new_actwk) != 0) { die(moviewk); return; } /* Line 89, Address: 0x102e9cc */
  new_actwk->actno = moviewk->actno; /* Line 90, Address: 0x102e9f4 */
  new_actwk->xposi.w.h = moviewk->xposi.w.h - 21; /* Line 91, Address: 0x102ea04 */
  new_actwk->yposi.w.h = moviewk->yposi.w.h - 7; /* Line 92, Address: 0x102ea28 */
  new_actwk->userflag.b.h = -1; /* Line 93, Address: 0x102ea4c */
  ((unsigned short*)new_actwk)[33] = moviewk - actwk; /* Line 94, Address: 0x102ea58 */

  if (actwkchk(&new_actwk) != 0) { die(moviewk); return; } /* Line 96, Address: 0x102ea8c */
  new_actwk->actno = moviewk->actno; /* Line 97, Address: 0x102eab4 */
  new_actwk->xposi.w.h = moviewk->xposi.w.h - 88; /* Line 98, Address: 0x102eac4 */
  new_actwk->yposi.w.h = moviewk->yposi.w.h - 4; /* Line 99, Address: 0x102eae8 */
  new_actwk->userflag.b.h = 1; /* Line 100, Address: 0x102eb0c */
  ((unsigned short*)new_actwk)[33] = moviewk - actwk; /* Line 101, Address: 0x102eb18 */

  if (actwkchk(&new_actwk) != 0) { die(moviewk); return; } /* Line 103, Address: 0x102eb4c */
  new_actwk->actno = 57; /* Line 104, Address: 0x102eb74 */
  new_actwk->xposi.w.h = moviewk->xposi.w.h - 88; /* Line 105, Address: 0x102eb80 */
  new_actwk->yposi.w.h = moviewk->yposi.w.h - 24; /* Line 106, Address: 0x102eba4 */
  new_actwk->userflag.b.h = -128; /* Line 107, Address: 0x102ebc8 */
  ((unsigned short*)new_actwk)[33] = moviewk- actwk; /* Line 108, Address: 0x102ebd4 */

  if (actwkchk(&new_actwk) != 0) { die(moviewk); return; } /* Line 110, Address: 0x102ec08 */
  new_actwk->actno = 57; /* Line 111, Address: 0x102ec30 */
  new_actwk->xposi.w.h = moviewk->xposi.w.h - 98; /* Line 112, Address: 0x102ec3c */
  new_actwk->yposi.w.h = moviewk->yposi.w.h; /* Line 113, Address: 0x102ec60 */
  new_actwk->userflag.b.h = -127; /* Line 114, Address: 0x102ec80 */
  ((unsigned short*)new_actwk)[33] = moviewk - actwk; /* Line 115, Address: 0x102ec8c */
} /* Line 116, Address: 0x102ecc0 */



static void m_wait(sprite_status* moviewk) { /* Line 120, Address: 0x102ecd0 */
  if (moviewk->colicnt != 0) { /* Line 121, Address: 0x102ecdc */
    moviewk->colino = moviewk->colicnt = 0; /* Line 122, Address: 0x102ecf0 */
    moviewk->r_no0 += 2; /* Line 123, Address: 0x102ed04 */
  }
  hitchk(moviewk, &actwk[0]); /* Line 125, Address: 0x102ed14 */
} /* Line 126, Address: 0x102ed28 */



static void m_die(sprite_status* moviewk) { /* Line 130, Address: 0x102ed40 */
  moviewk->r_no0 += 2; /* Line 131, Address: 0x102ed4c */
  moviewk->patno = 1; /* Line 132, Address: 0x102ed5c */
  moviewk->actfree[21] = 255; /* Line 133, Address: 0x102ed68 */
  divdevset(4); /* Line 134, Address: 0x102ed74 */

  if (hitchk(moviewk, &actwk[0]) != 0) ride_on_clr(moviewk, &actwk[0]); /* Line 136, Address: 0x102ed80 */
  m_baku(moviewk); /* Line 137, Address: 0x102edb8 */
} /* Line 138, Address: 0x102edc4 */



static void m_baku(sprite_status* moviewk) { /* Line 142, Address: 0x102ede0 */
  char *data_tbl, time_limit, x_add, y_add;
  sprite_status* new_actwk;

  data_tbl = ((char**)moviewk)[12]; /* Line 146, Address: 0x102edfc */
  if ((time_limit = data_tbl[0]) < 0) { /* Line 147, Address: 0x102ee04 */
    moviewk->r_no0 += 2; /* Line 148, Address: 0x102ee20 */
    ((short*)moviewk)[23] = 60; /* Line 149, Address: 0x102ee30 */
    return; /* Line 150, Address: 0x102ee3c */
  }

  if (++moviewk->actfree[0] != time_limit) return; /* Line 153, Address: 0x102ee44 */

  x_add = data_tbl[1], y_add = data_tbl[2]; /* Line 155, Address: 0x102ee6c */
  ((char**)moviewk)[12] = data_tbl + 3; /* Line 156, Address: 0x102ee84 */

  if (actwkchk(&new_actwk) != 0) return; /* Line 158, Address: 0x102ee90 */
  new_actwk->actno = 24; /* Line 159, Address: 0x102eea4 */
  new_actwk->r_no1 = 1; /* Line 160, Address: 0x102eeb0 */
  new_actwk->xposi.w.h = moviewk->xposi.w.h + x_add; /* Line 161, Address: 0x102eebc */
  new_actwk->yposi.w.h = moviewk->yposi.w.h + y_add; /* Line 162, Address: 0x102eef0 */
  soundset(158); /* Line 163, Address: 0x102ef24 */
} /* Line 164, Address: 0x102ef30 */



static void m1wait(sprite_status* moviewk) { /* Line 168, Address: 0x102ef50 */
  if (--((short*)moviewk)[23] == 0) { /* Line 169, Address: 0x102ef5c */
    projector_flag = 255; /* Line 170, Address: 0x102ef84 */
    die(moviewk); /* Line 171, Address: 0x102ef90 */
  }
} /* Line 173, Address: 0x102ef9c */



static void sub(sprite_status* moviewk) { /* Line 177, Address: 0x102efb0 */
  sprite_status* parent;

  parent = &actwk[((unsigned short*)moviewk)[33]]; /* Line 180, Address: 0x102efc0 */
  if (parent->actno != 56) { die(moviewk); return; } /* Line 181, Address: 0x102efe4 */
  if (parent->actfree[21] != 0) { die(moviewk); return; } /* Line 182, Address: 0x102f00c */

  if (moviewk->r_no0 == 0) { s_init(moviewk); return; } /* Line 184, Address: 0x102f030 */
  s_move(moviewk); /* Line 185, Address: 0x102f058 */
} /* Line 186, Address: 0x102f064 */



static void s_init(sprite_status* moviewk) { /* Line 190, Address: 0x102f080 */
  moviewk->r_no0 += 2; /* Line 191, Address: 0x102f088 */
  moviewk->actflg |= 4; /* Line 192, Address: 0x102f098 */
  moviewk->sprpri = 4; /* Line 193, Address: 0x102f0a8 */

  moviewk->patbase = pat_movie; /* Line 195, Address: 0x102f0b4 */
  if (moviewk->userflag.b.h < 0) { /* Line 196, Address: 0x102f0c4 */
    moviewk->sprhs = moviewk->sprhsize = 8; /* Line 197, Address: 0x102f0dc */
    moviewk->sprvsize = 4; /* Line 198, Address: 0x102f0f4 */
    moviewk->mstno.b.h = 0; /* Line 199, Address: 0x102f100 */
  } else { /* Line 200, Address: 0x102f108 */
    moviewk->sprhs = moviewk->sprhsize = 20; /* Line 201, Address: 0x102f110 */
    moviewk->sprvsize = 24; /* Line 202, Address: 0x102f128 */
    moviewk->mstno.b.h = 1; /* Line 203, Address: 0x102f134 */
  }
} /* Line 205, Address: 0x102f140 */



static void s_move(sprite_status* moviewk) { /* Line 209, Address: 0x102f150 */
  patchg(moviewk, pchg); /* Line 210, Address: 0x102f15c */
  actionsub(moviewk); /* Line 211, Address: 0x102f170 */
} /* Line 212, Address: 0x102f17c */
