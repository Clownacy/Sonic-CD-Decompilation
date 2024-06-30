#include "..\EQU.H"
#include "ET7.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"
#include "..\SCORE.H"

static void m_init(sprite_status* pActwk);
static void m_wait(sprite_status* pActwk);
static void m_die(sprite_status* pActwk);
static void m1wait(sprite_status* pActwk);
static void a_hover(sprite_status* pActwk);

static char p_a[6] = { 3, 3, 4, 5, 6, -1 };
static char* pchg[1] = { p_a };
static sprite_pattern et_pat00 = {
  1,
  { { -40, 16, 0, 455 } }
};
static sprite_pattern et_pat01 = {
  1,
  { { -40, 16, 0, 456 } }
};
static sprite_pattern et_pat02 = {
  1,
  { { -40, -32, 0, 457 } }
};
static sprite_pattern et_pat03 = {
  1,
  { { -40, -32, 0, 458 } }
};
static sprite_pattern et_pat04 = {
  1,
  { { -40, -32, 0, 459 } }
};
static sprite_pattern et_pat05 = {
  1,
  { { -40, -32, 0, 460 } }
};
static sprite_pattern et_pat06 = {
  1,
  { { -40, -32, 0, 461 } }
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

























































































































void et(sprite_status* pActwk) { /* Line 194, Address: 0x1021c70 */
  et_jmp_tbl[pActwk->r_no0 / 2](pActwk); /* Line 195, Address: 0x1021c7c */
  actionsub(pActwk); /* Line 196, Address: 0x1021cc0 */



  if (pActwk->r_no0 <= 2) { /* Line 200, Address: 0x1021ccc */
    frameout_s(pActwk); /* Line 201, Address: 0x1021ce4 */
  }
} /* Line 203, Address: 0x1021cf0 */






static void m_init(sprite_status* pActwk) { /* Line 210, Address: 0x1021d00 */
  unsigned char patnowk;
  unsigned short tbl0sproffset[3][4] = { /* Line 212, Address: 0x1021d10 */
    {
      942,
      942,
        0,
        0
    }, {
      942,
      942,
        0,
        0
    }, {
        0,
        0,
        0,
        0
    }
  };


  pActwk->r_no0 += 2; /* Line 232, Address: 0x1021d44 */
  pActwk->actflg |= 4; /* Line 233, Address: 0x1021d54 */
  pActwk->sprpri = 4; /* Line 234, Address: 0x1021d64 */
  pActwk->sprhs = pActwk->sprhsize = 34; /* Line 235, Address: 0x1021d70 */
  pActwk->sprvsize = 32; /* Line 236, Address: 0x1021d88 */

  pActwk->sproffset = tbl0sproffset[stageno.b.l][time_flag]; /* Line 238, Address: 0x1021d94 */

  pActwk->patbase = pat_et; /* Line 240, Address: 0x1021dcc */
  ((char**)pActwk)[12] = tbl0; /* Line 241, Address: 0x1021ddc */
  ((short*)pActwk)[26] = pActwk->yposi.w.h; /* Line 242, Address: 0x1021dec */
  ((short*)pActwk)[23] = 4; /* Line 243, Address: 0x1021dfc */
  ((short*)pActwk)[27] = 1; /* Line 244, Address: 0x1021e08 */

  patnowk = 0; /* Line 246, Address: 0x1021e14 */

  if (!generate_flag) { /* Line 248, Address: 0x1021e18 */
    patnowk += 2; /* Line 249, Address: 0x1021e28 */
  }


  if (time_flag == 0) { /* Line 253, Address: 0x1021e30 */
    ++patnowk; /* Line 254, Address: 0x1021e44 */
  }


  pActwk->patno = patnowk; /* Line 258, Address: 0x1021e4c */

  if (!generate_flag && time_flag == 0) { /* Line 260, Address: 0x1021e54 */
    pActwk->colino = 250; /* Line 261, Address: 0x1021e78 */
    pActwk->yposi.w.h -= 16; /* Line 262, Address: 0x1021e84 */
  }


  m_wait(pActwk); /* Line 266, Address: 0x1021e94 */
} /* Line 267, Address: 0x1021ea0 */






static void m_wait(sprite_status* pActwk) { /* Line 274, Address: 0x1021ec0 */
  if (!generate_flag && time_flag == 0) { /* Line 275, Address: 0x1021ecc */
    a_hover(pActwk); /* Line 276, Address: 0x1021ef0 */
    if (pActwk->colicnt) { /* Line 277, Address: 0x1021efc */
      pActwk->colino = pActwk->colicnt = 0; /* Line 278, Address: 0x1021f0c */
      ((short*)pActwk)[23] = 0; /* Line 279, Address: 0x1021f20 */
      pActwk->patno = 7; /* Line 280, Address: 0x1021f28 */
      pActwk->r_no0 += 2; /* Line 281, Address: 0x1021f34 */
      generate_flag = 1; /* Line 282, Address: 0x1021f44 */
      scoreup(150); /* Line 283, Address: 0x1021f50 */
      if (hitchk(pActwk, &actwk[0])) { /* Line 284, Address: 0x1021f5c */
        ride_on_clr(pActwk, &actwk[0]); /* Line 285, Address: 0x1021f78 */
      }


    } /* Line 289, Address: 0x1021f8c */
    else {
      hitchk(pActwk, &actwk[0]); /* Line 291, Address: 0x1021f94 */
      patchg(pActwk, (unsigned char**)pchg); /* Line 292, Address: 0x1021fa8 */
    }
  }


} /* Line 297, Address: 0x1021fbc */






static void m_die(sprite_status* pActwk) { /* Line 304, Address: 0x1021fd0 */
  char *pTbl, timewk;
  short xwk, ywk;
  sprite_status* pNewact;

  pTbl = ((char**)pActwk)[12]; /* Line 309, Address: 0x1021fec */
  timewk = *pTbl; /* Line 310, Address: 0x1021ff4 */
  ++pTbl; /* Line 311, Address: 0x1022000 */

  if (timewk < 0) { /* Line 313, Address: 0x1022004 */

    pActwk->r_no0 += 2; /* Line 315, Address: 0x1022014 */
    pActwk->actfree[0] = 8; /* Line 316, Address: 0x1022024 */
  } else { /* Line 317, Address: 0x1022030 */
    if (++pActwk->actfree[0] == timewk) { /* Line 318, Address: 0x1022038 */
      xwk = *pTbl; /* Line 319, Address: 0x1022060 */
      ++pTbl; /* Line 320, Address: 0x1022074 */
      ywk = *pTbl; /* Line 321, Address: 0x1022078 */
      ++pTbl; /* Line 322, Address: 0x102208c */
      ((char**)pActwk)[12] = pTbl; /* Line 323, Address: 0x1022090 */

      if (actwkchk(&pNewact) == 0) { /* Line 325, Address: 0x1022098 */
        pNewact->actno = 24; /* Line 326, Address: 0x10220ac */
        pNewact->r_no1 = 1; /* Line 327, Address: 0x10220b8 */
        pNewact->xposi.w.h = pActwk->xposi.w.h + xwk; /* Line 328, Address: 0x10220c4 */
        pNewact->yposi.w.h = pActwk->yposi.w.h + ywk; /* Line 329, Address: 0x10220f0 */
        soundset(158); /* Line 330, Address: 0x102211c */
      }
    }
  }


} /* Line 336, Address: 0x1022128 */






static void m1wait(sprite_status* pActwk) { /* Line 343, Address: 0x1022150 */
  if (--pActwk->actfree[0] == 0) { /* Line 344, Address: 0x102215c */
    pActwk->r_no0 -= 6; /* Line 345, Address: 0x102217c */
    pActwk->yposi.w.h = ((short*)pActwk)[26]; /* Line 346, Address: 0x102218c */
    soundset(217); /* Line 347, Address: 0x102219c */
  }
} /* Line 349, Address: 0x10221a8 */













static void a_hover(sprite_status* pActwk) { /* Line 363, Address: 0x10221c0 */
  short timewk;

  ++((short*)pActwk)[23]; /* Line 366, Address: 0x10221cc */

  timewk = ((short*)pActwk)[23]; /* Line 368, Address: 0x10221dc */
  if (!(timewk & 7)) { /* Line 369, Address: 0x10221ec */
    pActwk->yposi.w.h += ((short*)pActwk)[27]; /* Line 370, Address: 0x1022200 */
  }

  timewk = ((short*)pActwk)[23]; /* Line 373, Address: 0x1022218 */
  if (!(timewk & 31)) { /* Line 374, Address: 0x1022228 */
    ((short*)pActwk)[27] *= -1; /* Line 375, Address: 0x102223c */
  }
} /* Line 377, Address: 0x102224c */
