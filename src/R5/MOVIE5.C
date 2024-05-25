#include "..\EQU.H"
#include "MOVIE5.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"

static void m_init(sprite_status* pActwk);
static void m_wait(sprite_status* pActwk);
static void m_die(sprite_status* pActwk);
static void m_baku(sprite_status* pActwk);
static void m1wait(sprite_status* pActwk);
static void s_init(sprite_status* pActwk);
static void s_move(sprite_status* pActwk);

static char tbl0[37] = {
    1,   0,   0,   5, -18, -10,  10, -10,  10,  15,
    0, -18,  20, -10,  18,  22,   8,  23,  25,  13,
  -10,  28,  -3, -25,  30,  10,  20,  32, -10,   2,
   35,  13, -10,  40, -10,  10,  -1
};
static sprite_pattern movie_pat00 = {
  1,
  { { -12, -12, 0, 445 } }
};
static sprite_pattern movie_pat01;
static sprite_pattern movie_pat02 = {
  1,
  { { -8, -4, 0, 446 } }
};
static sprite_pattern movie_pat03 = {
  1,
  { { -8, -4, 0, 447 } }
};
static sprite_pattern movie_pat04 = {
  1,
  { { -20, -24, 0, 448 } }
};
static sprite_pattern movie_pat05 = {
  1,
  { { -20, -24, 0, 449 } }
};
sprite_pattern* pat_movie[6] = {
  &movie_pat00,
  &movie_pat01,
  &movie_pat02,
  &movie_pat03,
  &movie_pat04,
  &movie_pat05
};
static void(*movie_act_tbl[5])(sprite_status*) = {
  &m_init,
  &m_wait,
  &m_die,
  &m_baku,
  &m1wait
};
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













































































void movie(sprite_status* pActwk) { /* Line 149, Address: 0x101d950 */
  if (pActwk->userflag.b.h) { /* Line 150, Address: 0x101d960 */
    sprite_status* pMainwk;

    pMainwk = &actwk[((short*)pActwk)[33]]; /* Line 153, Address: 0x101d970 */
    if (pMainwk->actno != 44 || pMainwk->actfree[21]) { /* Line 154, Address: 0x101d998 */
      frameout(pActwk); /* Line 155, Address: 0x101d9b8 */
      return; /* Line 156, Address: 0x101d9c4 */
    }

    if (pActwk->r_no0) { /* Line 159, Address: 0x101d9cc */
      s_move(pActwk); /* Line 160, Address: 0x101d9dc */
    } else { /* Line 161, Address: 0x101d9e8 */
      s_init(pActwk); /* Line 162, Address: 0x101d9f0 */
    }
  } else { /* Line 164, Address: 0x101d9fc */
    movie_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 165, Address: 0x101da04 */
    actionsub(pActwk); /* Line 166, Address: 0x101da48 */
    if (pActwk->r_no0 < 3) { /* Line 167, Address: 0x101da54 */
      frameout_s(pActwk); /* Line 168, Address: 0x101da6c */
    }
  }
} /* Line 171, Address: 0x101da78 */





static void m_init(sprite_status* pActwk) { /* Line 177, Address: 0x101da90 */
  sprite_status* pNewact;

  if (projector_flag) { /* Line 180, Address: 0x101da9c */
    frameout(pActwk); /* Line 181, Address: 0x101daac */
    return; /* Line 182, Address: 0x101dab8 */
  }




  pActwk->r_no0 += 2; /* Line 188, Address: 0x101dac0 */
  pActwk->actflg |= 4; /* Line 189, Address: 0x101dad0 */
  pActwk->sprhs = 12; /* Line 190, Address: 0x101dae0 */
  pActwk->sprhsize = 12; /* Line 191, Address: 0x101daec */
  pActwk->sprvsize = 12; /* Line 192, Address: 0x101daf8 */
  pActwk->colino = 251; /* Line 193, Address: 0x101db04 */
  pActwk->sproffset = 950; /* Line 194, Address: 0x101db10 */
  pActwk->patbase = pat_movie; /* Line 195, Address: 0x101db1c */
  ((char**)pActwk)[12] = tbl0; /* Line 196, Address: 0x101db2c */




  if (actwkchk(&pNewact) != 0) { /* Line 201, Address: 0x101db3c */
    frameout(pActwk); /* Line 202, Address: 0x101db50 */
    return; /* Line 203, Address: 0x101db5c */
  }

  pNewact->actno = pActwk->actno; /* Line 206, Address: 0x101db64 */
  pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 207, Address: 0x101db74 */
  pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 208, Address: 0x101db84 */
  pNewact->xposi.w.h -= 21; /* Line 209, Address: 0x101db94 */
  pNewact->yposi.w.h -= 7; /* Line 210, Address: 0x101dba4 */
  pNewact->userflag.b.h = -1; /* Line 211, Address: 0x101dbb4 */
  ((short*)pNewact)[33] = pActwk - actwk; /* Line 212, Address: 0x101dbc0 */




  if (actwkchk(&pNewact) != 0) { /* Line 217, Address: 0x101dbf8 */
    frameout(pActwk); /* Line 218, Address: 0x101dc0c */
    return; /* Line 219, Address: 0x101dc18 */
  }

  pNewact->actno = pActwk->actno; /* Line 222, Address: 0x101dc20 */
  pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 223, Address: 0x101dc30 */
  pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 224, Address: 0x101dc40 */
  pNewact->xposi.w.h -= 88; /* Line 225, Address: 0x101dc50 */
  pNewact->yposi.w.h -= 4; /* Line 226, Address: 0x101dc60 */
  pNewact->userflag.b.h = 1; /* Line 227, Address: 0x101dc70 */
  ((short*)pNewact)[33] = pActwk - actwk; /* Line 228, Address: 0x101dc7c */




  if (actwkchk(&pNewact) != 0) { /* Line 233, Address: 0x101dcb4 */
    frameout(pActwk); /* Line 234, Address: 0x101dcc8 */
    return; /* Line 235, Address: 0x101dcd4 */
  }

  pNewact->actno = 45; /* Line 238, Address: 0x101dcdc */
  pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 239, Address: 0x101dce8 */
  pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 240, Address: 0x101dcf8 */
  pNewact->xposi.w.h -= 88; /* Line 241, Address: 0x101dd08 */
  pNewact->yposi.w.h -= 24; /* Line 242, Address: 0x101dd18 */
  pNewact->userflag.b.h = -128; /* Line 243, Address: 0x101dd28 */
  ((short*)pNewact)[33] = pActwk - actwk; /* Line 244, Address: 0x101dd34 */




  if (actwkchk(&pNewact) != 0) { /* Line 249, Address: 0x101dd6c */
    frameout(pActwk); /* Line 250, Address: 0x101dd80 */
    return; /* Line 251, Address: 0x101dd8c */
  }

  pNewact->actno = 45; /* Line 254, Address: 0x101dd94 */
  pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 255, Address: 0x101dda0 */
  pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 256, Address: 0x101ddb0 */
  pNewact->xposi.w.h -= 100; /* Line 257, Address: 0x101ddc0 */
  pNewact->yposi.w.h += 4; /* Line 258, Address: 0x101ddd0 */
  pNewact->userflag.b.h = -127; /* Line 259, Address: 0x101dde0 */
  ((short*)pNewact)[33] = pActwk - actwk; /* Line 260, Address: 0x101ddec */

  m_wait(pActwk); /* Line 262, Address: 0x101de24 */
} /* Line 263, Address: 0x101de30 */





static void m_wait(sprite_status* pActwk) { /* Line 269, Address: 0x101de40 */
  if (pActwk->colicnt) { /* Line 270, Address: 0x101de4c */
    pActwk->colino = 0; /* Line 271, Address: 0x101de5c */
    pActwk->colicnt = 0; /* Line 272, Address: 0x101de64 */
    pActwk->r_no0 += 2; /* Line 273, Address: 0x101de6c */
  }


  hitchk(pActwk, &actwk[0]); /* Line 277, Address: 0x101de7c */
} /* Line 278, Address: 0x101de90 */





static void m_die(sprite_status* pActwk) { /* Line 284, Address: 0x101dea0 */
  pActwk->r_no0 += 2; /* Line 285, Address: 0x101deac */
  pActwk->patno = 1; /* Line 286, Address: 0x101debc */
  pActwk->actfree[21] = 1; /* Line 287, Address: 0x101dec8 */



  if (hitchk(pActwk, &actwk[0])) {; /* Line 291, Address: 0x101ded4 */
    ride_on_clr(pActwk, &actwk[0]); /* Line 292, Address: 0x101def0 */
  }


  m_baku(pActwk); /* Line 296, Address: 0x101df04 */
} /* Line 297, Address: 0x101df10 */





static void m_baku(sprite_status* pActwk) { /* Line 303, Address: 0x101df20 */
  char *pTbl, timewk;
  short xwk, ywk;
  sprite_status* pNewact;

  pTbl = ((char**)pActwk)[12]; /* Line 308, Address: 0x101df3c */
  if ((timewk = *pTbl++) >= 0) { /* Line 309, Address: 0x101df44 */
    if (++pActwk->actfree[0] == timewk) { /* Line 310, Address: 0x101df68 */
      xwk = *pTbl++; /* Line 311, Address: 0x101df90 */
      ywk = *pTbl++; /* Line 312, Address: 0x101dfac */
      ((char**)pActwk)[12] = pTbl; /* Line 313, Address: 0x101dfc8 */
      if (actwkchk(&pNewact) == 0) { /* Line 314, Address: 0x101dfd0 */
        pNewact->actno = 24; /* Line 315, Address: 0x101dfe4 */
        pNewact->r_no1 = 1; /* Line 316, Address: 0x101dff0 */
        pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 317, Address: 0x101dffc */
        pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 318, Address: 0x101e00c */
        pNewact->xposi.w.h += xwk; /* Line 319, Address: 0x101e01c */
        pNewact->yposi.w.h += ywk; /* Line 320, Address: 0x101e02c */
        soundset(158); /* Line 321, Address: 0x101e03c */
      }
    }


  } /* Line 326, Address: 0x101e048 */
  else {
    pActwk->r_no0 += 2; /* Line 328, Address: 0x101e050 */
    ((short*)pActwk)[23] = 60; /* Line 329, Address: 0x101e060 */
  }
} /* Line 331, Address: 0x101e06c */





static void m1wait(sprite_status* pActwk) { /* Line 337, Address: 0x101e090 */
  if (!(--((short*)pActwk)[23])) { /* Line 338, Address: 0x101e09c */
    projector_flag = 1; /* Line 339, Address: 0x101e0bc */
    frameout(pActwk); /* Line 340, Address: 0x101e0c8 */
  }
} /* Line 342, Address: 0x101e0d4 */



























static void s_init(sprite_status* pActwk) { /* Line 370, Address: 0x101e0f0 */
  pActwk->r_no0 += 2; /* Line 371, Address: 0x101e0fc */
  pActwk->actflg |= 4; /* Line 372, Address: 0x101e10c */
  pActwk->sprpri = 4; /* Line 373, Address: 0x101e11c */
  pActwk->sproffset = 950; /* Line 374, Address: 0x101e128 */
  pActwk->patbase = pat_movie; /* Line 375, Address: 0x101e134 */

  if (pActwk->userflag.b.h & 128) { /* Line 377, Address: 0x101e144 */

    pActwk->sprhs = pActwk->sprhsize = 8; /* Line 379, Address: 0x101e160 */
    pActwk->sprvsize = 4; /* Line 380, Address: 0x101e178 */
    pActwk->mstno.b.h = 0; /* Line 381, Address: 0x101e184 */
  } /* Line 382, Address: 0x101e18c */
  else {
    pActwk->sprhs = pActwk->sprhsize = 20; /* Line 384, Address: 0x101e194 */
    pActwk->sprvsize = 24; /* Line 385, Address: 0x101e1ac */
    pActwk->mstno.b.h = 1; /* Line 386, Address: 0x101e1b8 */
  }

  s_move(pActwk); /* Line 389, Address: 0x101e1c4 */
} /* Line 390, Address: 0x101e1d0 */





static void s_move(sprite_status* pActwk) { /* Line 396, Address: 0x101e1e0 */
  patchg(pActwk, pchg); /* Line 397, Address: 0x101e1ec */
  actionsub(pActwk); /* Line 398, Address: 0x101e200 */
} /* Line 399, Address: 0x101e20c */
