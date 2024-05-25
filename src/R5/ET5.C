#include "..\EQU.H"
#include "ET5.H"
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

static sprite_pattern et_pat00 = {
  1,
  { { -40, 16, 0, 422 } }
};
static sprite_pattern et_pat01 = {
  1,
  { { -40, 16, 0, 423 } }
};
static sprite_pattern et_pat02 = {
  1,
  { { -40, -32, 0, 424 } }
};
static sprite_pattern et_pat03 = {
  1,
  { { -40, -32, 0, 425 } }
};
static sprite_pattern et_pat04 = {
  1,
  { { -40, -32, 0, 426 } }
};
static sprite_pattern et_pat05 = {
  1,
  { { -40, -32, 0, 427 } }
};
static sprite_pattern et_pat06 = {
  1,
  { { -40, -32, 0, 428 } }
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
static char p_a[6] = { 3, 3, 4, 5, 6, -1 };
static char* pchg[1] = { p_a };
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









































































void et(sprite_status* pActwk) { /* Line 140, Address: 0x1028260 */
  void(*et_jmp_tbl[4])(sprite_status*) = { /* Line 141, Address: 0x102826c */
    &m_init,
    &m_wait,
    &m_die,
    &m1wait
  };

  et_jmp_tbl[pActwk->r_no0 / 2](pActwk); /* Line 148, Address: 0x1028298 */
  actionsub(pActwk); /* Line 149, Address: 0x10282d4 */

  if (pActwk->r_no0 < 3) /* Line 151, Address: 0x10282e0 */
    frameout_s(pActwk); /* Line 152, Address: 0x10282f8 */
} /* Line 153, Address: 0x1028304 */








static void m_init(sprite_status* pActwk) { /* Line 162, Address: 0x1028320 */
  unsigned char patnowk;
  unsigned short tbl0sproffset[3][4] = { /* Line 164, Address: 0x1028330 */
    {
      1234,
      1234,
      0,
      0
    }, {
      1234,
      1234,
      0,
      0
    }, {
      0,
      0,
      0,
      0
    }
  };


  pActwk->r_no0 += 2; /* Line 184, Address: 0x1028364 */
  pActwk->actflg |= 4; /* Line 185, Address: 0x1028374 */
  pActwk->sprpri = 4; /* Line 186, Address: 0x1028384 */
  pActwk->sprhs = pActwk->sprhsize = 34; /* Line 187, Address: 0x1028390 */
  pActwk->sprvsize = 32; /* Line 188, Address: 0x10283a8 */

  pActwk->sproffset = tbl0sproffset[stageno.b.l][time_flag]; /* Line 190, Address: 0x10283b4 */

  pActwk->patbase = pat_et; /* Line 192, Address: 0x10283ec */
  ((char**)pActwk)[12] = tbl0; /* Line 193, Address: 0x10283fc */
  ((short*)pActwk)[26] = pActwk->yposi.w.h; /* Line 194, Address: 0x102840c */
  ((short*)pActwk)[23] = 4; /* Line 195, Address: 0x102841c */
  ((short*)pActwk)[27] = 1; /* Line 196, Address: 0x1028428 */

  patnowk = 0; /* Line 198, Address: 0x1028434 */

  if (!generate_flag) { /* Line 200, Address: 0x1028438 */
    patnowk += 2; /* Line 201, Address: 0x1028448 */
  }

  if (!time_flag) { /* Line 204, Address: 0x1028450 */
    ++patnowk; /* Line 205, Address: 0x1028460 */
  }

  pActwk->patno = patnowk; /* Line 208, Address: 0x1028468 */

  if (!generate_flag && time_flag == 0) { /* Line 210, Address: 0x1028470 */
    pActwk->colino = 250; /* Line 211, Address: 0x1028494 */
    pActwk->yposi.w.h -= 16; /* Line 212, Address: 0x10284a0 */
  }


  m_wait(pActwk); /* Line 216, Address: 0x10284b0 */
} /* Line 217, Address: 0x10284bc */








static void m_wait(sprite_status* pActwk) { /* Line 226, Address: 0x10284d0 */
  if (!generate_flag && time_flag == 0) { /* Line 227, Address: 0x10284dc */
    a_hover(pActwk); /* Line 228, Address: 0x1028500 */
    if (pActwk->colicnt) { /* Line 229, Address: 0x102850c */
      pActwk->colino = pActwk->colicnt = 0; /* Line 230, Address: 0x102851c */
      ((short*)pActwk)[23] = 0; /* Line 231, Address: 0x1028530 */
      pActwk->patno = 7; /* Line 232, Address: 0x1028538 */
      pActwk->r_no0 += 2; /* Line 233, Address: 0x1028544 */
      generate_flag = 1; /* Line 234, Address: 0x1028554 */
      scoreup(150); /* Line 235, Address: 0x1028560 */
      if (hitchk(pActwk, &actwk[0])) { /* Line 236, Address: 0x102856c */
        ride_on_clr(pActwk, &actwk[0]); /* Line 237, Address: 0x1028588 */
      }

    } /* Line 240, Address: 0x102859c */
    else {
      hitchk(pActwk, &actwk[0]); /* Line 242, Address: 0x10285a4 */
      patchg(pActwk, (unsigned char**)pchg); /* Line 243, Address: 0x10285b8 */
    }
  }

} /* Line 247, Address: 0x10285cc */








static void m_die(sprite_status* pActwk) { /* Line 256, Address: 0x10285e0 */
  char *pTbl, timewk;
  short xwk, ywk;
  sprite_status* pNewact;

  pTbl = ((char**)pActwk)[12]; /* Line 261, Address: 0x10285fc */
  timewk = *pTbl; /* Line 262, Address: 0x1028604 */
  ++pTbl; /* Line 263, Address: 0x1028610 */

  if (timewk < 0) { /* Line 265, Address: 0x1028614 */

    pActwk->r_no0 += 2; /* Line 267, Address: 0x1028624 */
    pActwk->actfree[0] = 8; /* Line 268, Address: 0x1028634 */
  } /* Line 269, Address: 0x1028640 */
  else {
    if (++pActwk->actfree[0] == timewk) { /* Line 271, Address: 0x1028648 */
      xwk = *pTbl; /* Line 272, Address: 0x1028670 */
      ++pTbl; /* Line 273, Address: 0x1028684 */
      ywk = *pTbl; /* Line 274, Address: 0x1028688 */
      ++pTbl; /* Line 275, Address: 0x102869c */
      ((char**)pActwk)[12] = pTbl; /* Line 276, Address: 0x10286a0 */

      if (actwkchk(&pNewact) == 0) { /* Line 278, Address: 0x10286a8 */
        pNewact->actno = 24; /* Line 279, Address: 0x10286bc */
        pNewact->r_no1 = 1; /* Line 280, Address: 0x10286c8 */
        pNewact->xposi.w.h = pActwk->xposi.w.h + xwk; /* Line 281, Address: 0x10286d4 */
        pNewact->yposi.w.h = pActwk->yposi.w.h + ywk; /* Line 282, Address: 0x1028700 */
        soundset(158); /* Line 283, Address: 0x102872c */
      }
    }
  }

} /* Line 288, Address: 0x1028738 */








static void m1wait(sprite_status* pActwk) { /* Line 297, Address: 0x1028760 */
  if (--pActwk->actfree[0] == 0) { /* Line 298, Address: 0x102876c */
    pActwk->r_no0 -= 6; /* Line 299, Address: 0x102878c */
    pActwk->yposi.w.h = ((short*)pActwk)[26]; /* Line 300, Address: 0x102879c */
    soundset(217); /* Line 301, Address: 0x10287ac */
  }
} /* Line 303, Address: 0x10287b8 */








static void a_hover(sprite_status* pActwk) { /* Line 312, Address: 0x10287d0 */
  short timewk;

  ++((short*)pActwk)[23]; /* Line 315, Address: 0x10287dc */

  timewk = ((short*)pActwk)[23]; /* Line 317, Address: 0x10287ec */
  if (!(timewk & 7)) /* Line 318, Address: 0x10287fc */
    pActwk->yposi.w.h += ((short*)pActwk)[27]; /* Line 319, Address: 0x1028810 */

  timewk = ((short*)pActwk)[23]; /* Line 321, Address: 0x1028828 */
  if (!(timewk & 31)) /* Line 322, Address: 0x1028838 */
    ((short*)pActwk)[27] *= -1; /* Line 323, Address: 0x102884c */
} /* Line 324, Address: 0x102885c */
