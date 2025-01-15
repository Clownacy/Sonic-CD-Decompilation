#include "..\EQU.H"
#include "ET4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"
#include "..\SCORE.H"
#include "PLAYSUB4.H"

#if defined(R41B)
  #define SPRITE_ET4_BASE 459
#elif defined(R42B)
  #define SPRITE_ET4_BASE 473
#else
  #define SPRITE_ET4_BASE 431
#endif

static void m_init(sprite_status* pActwk);
static void m_wait(sprite_status* pActwk);
static void m_die(sprite_status* pActwk);
static void m1wait(sprite_status* pActwk);
static void a_hover(sprite_status* pActwk);

static char p_a[6] = { 3, 3, 4, 5, 6, -1 };
static char* pchg[1] = { p_a };
static sprite_pattern et_pat00 = {
  1,
  { { -40, 16, 0, SPRITE_ET4_BASE } }
};
static sprite_pattern et_pat01 = {
  1,
  { { -40, 16, 0, SPRITE_ET4_BASE + 1 } }
};
static sprite_pattern et_pat02 = {
  1,
  { { -40, -32, 0, SPRITE_ET4_BASE + 2 } }
};
static sprite_pattern et_pat03 = {
  1,
  { { -40, -32, 0, SPRITE_ET4_BASE + 3 } }
};
static sprite_pattern et_pat04 = {
  1,
  { { -40, -32, 0, SPRITE_ET4_BASE + 4 } }
};
static sprite_pattern et_pat05 = {
  1,
  { { -40, -32, 0, SPRITE_ET4_BASE + 5 } }
};
static sprite_pattern et_pat06 = {
  1,
  { { -40, -32, 0, SPRITE_ET4_BASE + 6 } }
};
static sprite_pattern et_pat07;
sprite_pattern* pat_et[8] = {
  &et_pat00,
  &et_pat01,
  &et_pat02,
  &et_pat03,
  &et_pat04,
  &et_pat05,
  &et_pat06,
  &et_pat07
};
static void(*et_jmp_tbl[4])(sprite_status*) = {
  &m_init,
  &m_wait,
  &m_die,
  &m1wait
};
static char tbl0[64] = {
    1,   0,   0,   2, -40, -20,   3,  28,
   10,   4,  18, -18,   5, -18, -10,   6,
    8,  -8,   8, -18,  14,  10, -10,  10,
   12,  30, -10,  15,   0, -18,  18,  20,
  -10,  20, -10,  18,  22,   8,  23,  25,
   13, -10,  26,  23, -22,  28,  -3, -25,
   30,  10,  20,  32, -10,   2,  34,  30,
   -8,  35,  13, -10,  40, -10,  10,  -1
};
















































































































void et(sprite_status* pActwk) { /* Line 193, Address: 0x1021b90 */
  et_jmp_tbl[pActwk->r_no0 / 2](pActwk); /* Line 194, Address: 0x1021b9c */
  actionsub(pActwk); /* Line 195, Address: 0x1021be0 */

  if (pActwk->r_no0 <= 2) { /* Line 197, Address: 0x1021bec */
    frameout_s(pActwk); /* Line 198, Address: 0x1021c04 */
  }
} /* Line 200, Address: 0x1021c10 */






static void m_init(sprite_status* pActwk) { /* Line 207, Address: 0x1021c20 */
  unsigned char patnowk;
  unsigned short tbl0sproffset[3][4] = { /* Line 209, Address: 0x1021c30 */
    {
      1104,
      1104,
      0,
      0
    }, {
      1104,
      1104,
      0,
      0
    }, {
      0,
      0,
      0,
      0
    }
  };


  pActwk->r_no0 += 2; /* Line 229, Address: 0x1021c64 */
  pActwk->actflg |= 4; /* Line 230, Address: 0x1021c74 */
  pActwk->sprpri = 4; /* Line 231, Address: 0x1021c84 */
  pActwk->sprhs = pActwk->sprhsize = 34; /* Line 232, Address: 0x1021c90 */
  pActwk->sprvsize = 32; /* Line 233, Address: 0x1021ca8 */

  pActwk->sproffset = tbl0sproffset[stageno.b.l][time_flag]; /* Line 235, Address: 0x1021cb4 */

  pActwk->patbase = pat_et; /* Line 237, Address: 0x1021cec */
  ((char**)pActwk)[12] = tbl0; /* Line 238, Address: 0x1021cfc */
  ((short*)pActwk)[26] = pActwk->yposi.w.h; /* Line 239, Address: 0x1021d0c */
  ((short*)pActwk)[23] = 4; /* Line 240, Address: 0x1021d1c */
  ((short*)pActwk)[27] = 1; /* Line 241, Address: 0x1021d28 */

  patnowk = 0; /* Line 243, Address: 0x1021d34 */

  if (!generate_flag) { /* Line 245, Address: 0x1021d38 */
    patnowk += 2; /* Line 246, Address: 0x1021d48 */
  }


  if (time_flag == 0) { /* Line 250, Address: 0x1021d50 */
    ++patnowk; /* Line 251, Address: 0x1021d64 */
  }


  pActwk->patno = patnowk; /* Line 255, Address: 0x1021d6c */

  if (!generate_flag && time_flag == 0) { /* Line 257, Address: 0x1021d74 */
    pActwk->colino = 250; /* Line 258, Address: 0x1021d98 */
    pActwk->yposi.w.h -= 16; /* Line 259, Address: 0x1021da4 */
  }


  m_wait(pActwk); /* Line 263, Address: 0x1021db4 */
} /* Line 264, Address: 0x1021dc0 */






static void m_wait(sprite_status* pActwk) { /* Line 271, Address: 0x1021de0 */
  if (!generate_flag && time_flag == 0) { /* Line 272, Address: 0x1021dec */
    a_hover(pActwk); /* Line 273, Address: 0x1021e10 */
    if (pActwk->colicnt) { /* Line 274, Address: 0x1021e1c */
      pActwk->colino = pActwk->colicnt = 0; /* Line 275, Address: 0x1021e2c */
      ((short*)pActwk)[23] = 0; /* Line 276, Address: 0x1021e40 */
      pActwk->patno = 7; /* Line 277, Address: 0x1021e48 */
      pActwk->r_no0 += 2; /* Line 278, Address: 0x1021e54 */
      generate_flag = 1; /* Line 279, Address: 0x1021e64 */
      scoreup(150); /* Line 280, Address: 0x1021e70 */
      if (hitchk(pActwk, &actwk[0]) == 0) return; /* Line 281, Address: 0x1021e7c */
      ride_on_clr(pActwk, &actwk[0]); /* Line 282, Address: 0x1021e98 */



      return; /* Line 286, Address: 0x1021eac */
    }
    hitchk(pActwk, &actwk[0]); /* Line 288, Address: 0x1021eb4 */
    patchg(pActwk, (unsigned char**)pchg); /* Line 289, Address: 0x1021ec8 */
  }



} /* Line 294, Address: 0x1021edc */






static void m_die(sprite_status* pActwk) { /* Line 301, Address: 0x1021ef0 */
  char *pTbl, timewk;
  short xwk, ywk;
  sprite_status* pNewact;

  pTbl = ((char**)pActwk)[12]; /* Line 306, Address: 0x1021f0c */
  timewk = *pTbl; /* Line 307, Address: 0x1021f14 */
  ++pTbl; /* Line 308, Address: 0x1021f20 */

  if (timewk < 0) { /* Line 310, Address: 0x1021f24 */

    pActwk->r_no0 += 2; /* Line 312, Address: 0x1021f34 */
    pActwk->actfree[0] = 8; /* Line 313, Address: 0x1021f44 */
  } /* Line 314, Address: 0x1021f50 */
  else if (++pActwk->actfree[0] == timewk) { /* Line 315, Address: 0x1021f58 */
    xwk = *pTbl; /* Line 316, Address: 0x1021f80 */
    ++pTbl; /* Line 317, Address: 0x1021f94 */
    ywk = *pTbl; /* Line 318, Address: 0x1021f98 */
    ++pTbl; /* Line 319, Address: 0x1021fac */
    ((char**)pActwk)[12] = pTbl; /* Line 320, Address: 0x1021fb0 */

    if (actwkchk(&pNewact) == 0) { /* Line 322, Address: 0x1021fb8 */
      pNewact->actno = 24; /* Line 323, Address: 0x1021fcc */
      pNewact->r_no1 = 1; /* Line 324, Address: 0x1021fd8 */
      pNewact->xposi.w.h = pActwk->xposi.w.h + xwk; /* Line 325, Address: 0x1021fe4 */
      pNewact->yposi.w.h = pActwk->yposi.w.h + ywk; /* Line 326, Address: 0x1022010 */
      soundset(158); /* Line 327, Address: 0x102203c */
    }
  }



} /* Line 333, Address: 0x1022048 */






static void m1wait(sprite_status* pActwk) { /* Line 340, Address: 0x1022070 */
  if (--pActwk->actfree[0] == 0) { /* Line 341, Address: 0x102207c */
    pActwk->r_no0 -= 6; /* Line 342, Address: 0x102209c */
    pActwk->yposi.w.h = ((short*)pActwk)[26]; /* Line 343, Address: 0x10220ac */
    soundset(217); /* Line 344, Address: 0x10220bc */
  }
} /* Line 346, Address: 0x10220c8 */













static void a_hover(sprite_status* pActwk) { /* Line 360, Address: 0x10220e0 */
  short timewk;

  ++((short*)pActwk)[23]; /* Line 363, Address: 0x10220ec */

  timewk = ((short*)pActwk)[23]; /* Line 365, Address: 0x10220fc */
  if (!(timewk & 7)) { /* Line 366, Address: 0x102210c */
    pActwk->yposi.w.h += ((short*)pActwk)[27]; /* Line 367, Address: 0x1022120 */
  }

  timewk = ((short*)pActwk)[23]; /* Line 370, Address: 0x1022138 */
  if (!(timewk & 31)) { /* Line 371, Address: 0x1022148 */
    ((short*)pActwk)[27] *= -1; /* Line 372, Address: 0x102215c */
  }
} /* Line 374, Address: 0x102216c */
