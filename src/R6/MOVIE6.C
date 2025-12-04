#include "..\EQU.H"
#include "MOVIE6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"
#include "SCR61A.H"

static void die(sprite_status* moviewk);
static void m_init(sprite_status* moviewk);
static void m_wait(sprite_status* moviewk);
static void m_die(sprite_status* moviewk);
static void m_baku(sprite_status* moviewk);
static void m1wait(sprite_status* moviewk);
static void sub(sprite_status* moviewk);
static void s_init(sprite_status* moviewk);
static void s_move(sprite_status* moviewk);

static unsigned char pchg00[6] = { 0, 2, 1, 3, 1, 255 };
static unsigned char pchg01[58] = { 0, 4, 4, 1, 4, 4, 1, 4, 4, 1, 4, 4, 1, 4, 4, 1, 1, 4, 4, 1, 1, 4, 4, 1, 1, 4, 4, 1, 1, 5, 5, 1, 5, 5, 1, 5, 5, 1, 5, 5, 1, 5, 5, 1, 1, 5, 5, 1, 1, 5, 5, 1, 1, 5, 5, 1, 1, 255 };
static unsigned char* pchg[2] = { pchg00, pchg01 };
static sprite_pattern mov00 = { 1, { { -12, -12, 0, 302 } } };
static sprite_pattern pat00 = { 1, { { -16, -20, 0, 0 } } };
static sprite_pattern mov01 = { 1, { { -8, -4, 0, 303 } } };
static sprite_pattern mov02 = { 1, { { -8, -4, 0, 304 } } };
static sprite_pattern mov03 = { 1, { { -20, -24, 0, 305 } } };
static sprite_pattern mov04 = { 1, { { -20, -24, 0, 306 } } };
sprite_pattern* pat_movie[6] = { &mov00, &pat00, &mov01, &mov02, &mov03, &mov04 };
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










void movie(sprite_status* moviewk) { /* Line 55, Address: 0x101bfe0 */
  void(*act_tbl[5])(sprite_status*) = { &m_init, &m_wait, &m_die, &m_baku, &m1wait }; /* Line 56, Address: 0x101bfec */

  if (moviewk->userflag.b.h != 0) { sub(moviewk); return; } /* Line 58, Address: 0x101c018 */

  act_tbl[moviewk->r_no0 / 2](moviewk); /* Line 60, Address: 0x101c044 */
  actionsub(moviewk); /* Line 61, Address: 0x101c080 */
  if (moviewk->r_no0 > 2) return; /* Line 62, Address: 0x101c08c */
  frameout_s(moviewk); /* Line 63, Address: 0x101c0a4 */
  if (moviewk->actno == 0) divdevset(4); /* Line 64, Address: 0x101c0b0 */
} /* Line 65, Address: 0x101c0d0 */



static void die(sprite_status* moviewk) { /* Line 69, Address: 0x101c0e0 */
  frameout(moviewk); /* Line 70, Address: 0x101c0ec */
} /* Line 71, Address: 0x101c0f8 */


static void m_init(sprite_status* moviewk) { /* Line 74, Address: 0x101c110 */
  sprite_status* new_actwk;

  if (projector_flag != 0) { die(moviewk); return; } /* Line 77, Address: 0x101c11c */
  divdevset(5); /* Line 78, Address: 0x101c144 */

  moviewk->r_no0 += 2; /* Line 80, Address: 0x101c150 */
  moviewk->actflg |= 4; /* Line 81, Address: 0x101c160 */
  moviewk->sprpri = 4; /* Line 82, Address: 0x101c170 */
  moviewk->sprhs = moviewk->sprhsize = moviewk->sprvsize = 12; /* Line 83, Address: 0x101c17c */
  moviewk->colino = 251; /* Line 84, Address: 0x101c1a0 */

  moviewk->patbase = pat_movie; /* Line 86, Address: 0x101c1ac */
  ((char**)moviewk)[12] = tbl0; /* Line 87, Address: 0x101c1bc */

  if (actwkchk(&new_actwk) != 0) { die(moviewk); return; } /* Line 89, Address: 0x101c1cc */
  new_actwk->actno = moviewk->actno; /* Line 90, Address: 0x101c1f4 */
  new_actwk->xposi.w.h = moviewk->xposi.w.h - 21; /* Line 91, Address: 0x101c204 */
  new_actwk->yposi.w.h = moviewk->yposi.w.h - 7; /* Line 92, Address: 0x101c228 */
  new_actwk->userflag.b.h = -1; /* Line 93, Address: 0x101c24c */
  ((unsigned short*)new_actwk)[33] = moviewk - actwk; /* Line 94, Address: 0x101c258 */

  if (actwkchk(&new_actwk) != 0) { die(moviewk); return; } /* Line 96, Address: 0x101c28c */
  new_actwk->actno = moviewk->actno; /* Line 97, Address: 0x101c2b4 */
  new_actwk->xposi.w.h = moviewk->xposi.w.h - 72; /* Line 98, Address: 0x101c2c4 */
  new_actwk->yposi.w.h = moviewk->yposi.w.h - 4; /* Line 99, Address: 0x101c2e8 */
  new_actwk->userflag.b.h = 1; /* Line 100, Address: 0x101c30c */
  ((unsigned short*)new_actwk)[33] = moviewk - actwk; /* Line 101, Address: 0x101c318 */

  if (actwkchk(&new_actwk) != 0) { die(moviewk); return; } /* Line 103, Address: 0x101c34c */
  new_actwk->actno = 41; /* Line 104, Address: 0x101c374 */
  new_actwk->xposi.w.h = moviewk->xposi.w.h - 72; /* Line 105, Address: 0x101c380 */
  new_actwk->yposi.w.h = moviewk->yposi.w.h - 24; /* Line 106, Address: 0x101c3a4 */
  new_actwk->userflag.b.h = -128; /* Line 107, Address: 0x101c3c8 */
  ((unsigned short*)new_actwk)[33] = moviewk - actwk; /* Line 108, Address: 0x101c3d4 */

  if (actwkchk(&new_actwk) != 0) { die(moviewk); return; } /* Line 110, Address: 0x101c408 */
  new_actwk->actno = 41; /* Line 111, Address: 0x101c430 */
  new_actwk->xposi.w.h = moviewk->xposi.w.h - 84; /* Line 112, Address: 0x101c43c */
  new_actwk->yposi.w.h = moviewk->yposi.w.h + 7; /* Line 113, Address: 0x101c460 */
  new_actwk->userflag.b.h = -127; /* Line 114, Address: 0x101c484 */
  ((unsigned short*)new_actwk)[33] = moviewk - actwk; /* Line 115, Address: 0x101c490 */
} /* Line 116, Address: 0x101c4c4 */



static void m_wait(sprite_status* moviewk) { /* Line 120, Address: 0x101c4e0 */
  if (moviewk->colicnt != 0) { /* Line 121, Address: 0x101c4ec */
    moviewk->colino = moviewk->colicnt = 0; /* Line 122, Address: 0x101c500 */
    moviewk->r_no0 += 2; /* Line 123, Address: 0x101c514 */
  }
  hitchk(moviewk, &actwk[0]); /* Line 125, Address: 0x101c524 */
} /* Line 126, Address: 0x101c538 */



static void m_die(sprite_status* moviewk) { /* Line 130, Address: 0x101c550 */
  moviewk->r_no0 += 2; /* Line 131, Address: 0x101c55c */
  moviewk->patno = 1; /* Line 132, Address: 0x101c56c */
  moviewk->actfree[21] = 255; /* Line 133, Address: 0x101c578 */
  divdevset(4); /* Line 134, Address: 0x101c584 */

  if (hitchk(moviewk, &actwk[0]) != 0) ride_on_clr(moviewk, &actwk[0]); /* Line 136, Address: 0x101c590 */
  m_baku(moviewk); /* Line 137, Address: 0x101c5c8 */
} /* Line 138, Address: 0x101c5d4 */



static void m_baku(sprite_status* moviewk) { /* Line 142, Address: 0x101c5f0 */
  char *data_tbl, time_limit, x_add, y_add;
  sprite_status* new_actwk;

  data_tbl = ((char**)moviewk)[12]; /* Line 146, Address: 0x101c60c */
  if ((time_limit = data_tbl[0]) < 0) { /* Line 147, Address: 0x101c614 */
    moviewk->r_no0 += 2; /* Line 148, Address: 0x101c630 */
    ((short*)moviewk)[23] = 60; /* Line 149, Address: 0x101c640 */
    return; /* Line 150, Address: 0x101c64c */
  }

  if (++moviewk->actfree[0] != time_limit) return; /* Line 153, Address: 0x101c654 */

  x_add = data_tbl[1], y_add = data_tbl[2]; /* Line 155, Address: 0x101c67c */
  ((char**)moviewk)[12] = data_tbl + 3; /* Line 156, Address: 0x101c694 */

  if (actwkchk(&new_actwk) != 0) return; /* Line 158, Address: 0x101c6a0 */
  new_actwk->actno = 24; /* Line 159, Address: 0x101c6b4 */
  new_actwk->r_no1 = 1; /* Line 160, Address: 0x101c6c0 */
  new_actwk->xposi.w.h = moviewk->xposi.w.h + (short)x_add; /* Line 161, Address: 0x101c6cc */
  new_actwk->yposi.w.h = moviewk->yposi.w.h + (short)y_add; /* Line 162, Address: 0x101c700 */
  soundset(158); /* Line 163, Address: 0x101c734 */
} /* Line 164, Address: 0x101c740 */



static void m1wait(sprite_status* moviewk) { /* Line 168, Address: 0x101c760 */
  if (--((short*)moviewk)[23] == 0) { /* Line 169, Address: 0x101c76c */
    projector_flag = 255; /* Line 170, Address: 0x101c794 */
    die(moviewk); /* Line 171, Address: 0x101c7a0 */
  }
} /* Line 173, Address: 0x101c7ac */



static void sub(sprite_status* moviewk) { /* Line 177, Address: 0x101c7c0 */
  sprite_status* parent;

  parent = &actwk[((unsigned short*)moviewk)[33]]; /* Line 180, Address: 0x101c7d0 */
  if (parent->actno != 47) { die(moviewk); return; } /* Line 181, Address: 0x101c7f4 */
  if (parent->actfree[21] != 0) { die(moviewk); return; } /* Line 182, Address: 0x101c81c */

  if (moviewk->r_no0 == 0) s_init(moviewk); /* Line 184, Address: 0x101c840 */
  else s_move(moviewk); /* Line 185, Address: 0x101c868 */
} /* Line 186, Address: 0x101c874 */



static void s_init(sprite_status* moviewk) { /* Line 190, Address: 0x101c890 */
  moviewk->r_no0 += 2; /* Line 191, Address: 0x101c898 */
  moviewk->actflg |= 4; /* Line 192, Address: 0x101c8a8 */
  moviewk->sprpri = 4; /* Line 193, Address: 0x101c8b8 */

  moviewk->patbase = pat_movie; /* Line 195, Address: 0x101c8c4 */
  if (moviewk->userflag.b.h < 0) { /* Line 196, Address: 0x101c8d4 */
    moviewk->sprhs = moviewk->sprhsize = 8; /* Line 197, Address: 0x101c8ec */
    moviewk->sprvsize = 4; /* Line 198, Address: 0x101c904 */
    moviewk->mstno.b.h = 0; /* Line 199, Address: 0x101c910 */
  } else { /* Line 200, Address: 0x101c918 */
    moviewk->sprhs = moviewk->sprhsize = 20; /* Line 201, Address: 0x101c920 */
    moviewk->sprvsize = 24; /* Line 202, Address: 0x101c938 */
    moviewk->mstno.b.h = 1; /* Line 203, Address: 0x101c944 */
  }
} /* Line 205, Address: 0x101c950 */



static void s_move(sprite_status* moviewk) { /* Line 209, Address: 0x101c960 */
  patchg(moviewk, pchg); /* Line 210, Address: 0x101c96c */
  actionsub(moviewk); /* Line 211, Address: 0x101c980 */
} /* Line 212, Address: 0x101c98c */
