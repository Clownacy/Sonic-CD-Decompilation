#include "..\EQU.H"
#include "KABUTO8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static void kabuto0(sprite_status* kabutowk); static void a_init(sprite_status* kabutowk); static void a_fall(sprite_status* kabutowk); static void a_move(sprite_status* kabutowk);
static void kabuto1(sprite_status* tunowk); static void b_init(sprite_status* tunowk); static void b_move(sprite_status* tunowk);





void kabuto(sprite_status* kabutowk) { /* Line 17, Address: 0x1022340 */
  if (kabutowk->userflag.b.l >= 0) kabuto0(kabutowk); /* Line 18, Address: 0x102234c */
  else kabuto1(kabutowk); /* Line 19, Address: 0x1022378 */
} /* Line 20, Address: 0x1022384 */


#if defined(R82)
  #define SPRITE_KABUTO8_BASE 309
#elif defined(R83)
  #define SPRITE_KABUTO8_BASE 302
#else
  #define SPRITE_KABUTO8_BASE 300
#endif

static sprite_pattern cub00 = {
  1,
  { { -24, -16, 0, SPRITE_KABUTO8_BASE } }
};
sprite_pattern* pat_kabuto[1] = { &cub00 };

static void kabuto0(sprite_status* kabutowk) { /* Line 37, Address: 0x10223a0 */
  void(*tbl[3])(sprite_status*) = { &a_init, &a_fall, &a_move }; /* Line 38, Address: 0x10223ac */
  if (enemy_suicide(kabutowk)) return; /* Line 39, Address: 0x10223d0 */
  tbl[kabutowk->r_no0 / 2](kabutowk); /* Line 40, Address: 0x10223e4 */
  actionsub(kabutowk); /* Line 41, Address: 0x1022420 */
  frameout_s00(kabutowk, ((short*)kabutowk)[26]); /* Line 42, Address: 0x102242c */
} /* Line 43, Address: 0x1022440 */



static void a_init(sprite_status* kabutowk) { /* Line 47, Address: 0x1022450 */
  sprite_status* new_actwk;

  ((short*)kabutowk)[26] = kabutowk->xposi.w.h; /* Line 50, Address: 0x102245c */

  kabutowk->actflg |= 4; /* Line 52, Address: 0x102246c */
  kabutowk->sprpri = 4; /* Line 53, Address: 0x102247c */

  kabutowk->patbase = pat_kabuto; /* Line 55, Address: 0x1022488 */
  kabutowk->sprhsize = 24; /* Line 56, Address: 0x1022498 */
  kabutowk->sprvsize = 14; /* Line 57, Address: 0x10224a4 */
  kabutowk->colino = 42; /* Line 58, Address: 0x10224b0 */
  ((int*)kabutowk)[12] = -20480; /* Line 59, Address: 0x10224bc */
  kabutowk->r_no0 += 2; /* Line 60, Address: 0x10224c8 */
  if (actwkchk2(kabutowk, &new_actwk) != 0) { /* Line 61, Address: 0x10224d8 */
    frameout(kabutowk); /* Line 62, Address: 0x10224f0 */
    return; /* Line 63, Address: 0x10224fc */
  }
  new_actwk->actno = kabutowk->actno; /* Line 65, Address: 0x1022504 */
  new_actwk->userflag.b.h = kabutowk->userflag.b.h; /* Line 66, Address: 0x1022514 */
  new_actwk->userflag.b.l = -1; /* Line 67, Address: 0x1022524 */
  new_actwk->xposi.w.h = kabutowk->xposi.w.h; /* Line 68, Address: 0x1022530 */
  new_actwk->yposi.w.h = kabutowk->yposi.w.h; /* Line 69, Address: 0x1022540 */
  ((unsigned short*)new_actwk)[33] = kabutowk - actwk; /* Line 70, Address: 0x1022550 */
  if (kabutowk->userflag.b.l != 0) { /* Line 71, Address: 0x1022584 */
    kabutowk->actflg |= 1; /* Line 72, Address: 0x102259c */
    kabutowk->cddat |= 1; /* Line 73, Address: 0x10225ac */
    new_actwk->actflg |= 1; /* Line 74, Address: 0x10225bc */
    new_actwk->cddat |= 1; /* Line 75, Address: 0x10225cc */
  }
  a_fall(kabutowk); /* Line 77, Address: 0x10225dc */
} /* Line 78, Address: 0x10225e8 */



static void a_fall(sprite_status* kabutowk) { /* Line 82, Address: 0x1022600 */
  short colli_data;

  kabutowk->yposi.l += 65536; /* Line 85, Address: 0x1022610 */
  if ((colli_data = emycol_d(kabutowk)) < 0) { /* Line 86, Address: 0x1022624 */
    kabutowk->yposi.w.h += colli_data; /* Line 87, Address: 0x1022650 */
    kabutowk->r_no0 += 2; /* Line 88, Address: 0x1022660 */
  }
} /* Line 90, Address: 0x1022670 */



static void a_move(sprite_status* kabutowk) { /* Line 94, Address: 0x1022690 */
  if ((char)kabutowk->actflg < 0 && !(++((short*)kabutowk)[27] & 31)) { /* Line 95, Address: 0x102269c */

    soundset(177); /* Line 97, Address: 0x10226e8 */
  }
  kabutowk->xposi.l += ((int*)kabutowk)[12]; /* Line 99, Address: 0x10226f4 */

  kabutowk->yposi.w.h += emycol_d(kabutowk); /* Line 101, Address: 0x102270c */

  if (--((short*)kabutowk)[23] < 0) { /* Line 103, Address: 0x1022728 */
    ((short*)kabutowk)[23] = 409; /* Line 104, Address: 0x1022750 */
    ((int*)kabutowk)[12] = -((int*)kabutowk)[12]; /* Line 105, Address: 0x102275c */
  }

} /* Line 108, Address: 0x1022770 */















static unsigned char p00[4] = { 2, 0, 1, 255 };
static unsigned char p01[4] = { 2, 2, 3, 255 };
static unsigned char* pchg[2] = { p00, p01 };
static sprite_pattern hea00 = {
  2,
  {
    { -8, -8, 0, SPRITE_KABUTO8_BASE + 2 },
    { -12, -16, 0, SPRITE_KABUTO8_BASE + 1 }
  }
};
static sprite_pattern hea01 = {
  2,
  {
    { -8, -8, 0, SPRITE_KABUTO8_BASE + 2 },
    { -12, -17, 16, SPRITE_KABUTO8_BASE + 1 }
  }
};
static sprite_pattern hea02 = {
  2,
  {
    { -4, -2, 0, SPRITE_KABUTO8_BASE + 3 },
    { -12, -16, 0, SPRITE_KABUTO8_BASE + 1 }
  }
};
static sprite_pattern hea03 = {
  2,
  {
    { -4, -2, 0, SPRITE_KABUTO8_BASE + 3 },
    { -12, -17, 16, SPRITE_KABUTO8_BASE + 1 }
  }
};
static sprite_pattern* pat[4] = { &hea00, &hea01, &hea02, &hea03 };

void kabuto1(sprite_status* tunowk) { /* Line 157, Address: 0x1022780 */
  void(*tbl[2])(sprite_status*) = { &b_init, &b_move }; /* Line 158, Address: 0x102278c */
  tbl[tunowk->r_no0 / 2](tunowk); /* Line 159, Address: 0x10227a8 */
  actionsub(tunowk); /* Line 160, Address: 0x10227e4 */
} /* Line 161, Address: 0x10227f0 */



static void b_init(sprite_status* tunowk) { /* Line 165, Address: 0x1022800 */
  tunowk->r_no0 += 2; /* Line 166, Address: 0x1022808 */
  tunowk->actflg |= 4; /* Line 167, Address: 0x1022818 */
  tunowk->sprpri = 3; /* Line 168, Address: 0x1022828 */
  tunowk->patbase = pat; /* Line 169, Address: 0x1022834 */
  tunowk->sprhsize = 12; /* Line 170, Address: 0x1022844 */
  tunowk->sprvsize = 16; /* Line 171, Address: 0x1022850 */
  tunowk->colino = 171; /* Line 172, Address: 0x102285c */
} /* Line 173, Address: 0x1022868 */



static void b_move(sprite_status* tunowk) { /* Line 177, Address: 0x1022880 */
  sprite_status* bodywk;

  bodywk = &actwk[((unsigned short*)tunowk)[33]]; /* Line 180, Address: 0x1022890 */
  if (bodywk->actno != 36) { frameout(tunowk); return; } /* Line 181, Address: 0x10228b4 */
  if (tunowk->userflag.b.h) goto label1; /* Line 182, Address: 0x10228dc */

  if (--((short*)tunowk)[23] < 0) { /* Line 184, Address: 0x10228ec */
    ((short*)tunowk)[23] = 60; /* Line 185, Address: 0x1022914 */
    tunowk->mstno.b.h ^= 1; /* Line 186, Address: 0x1022920 */
label1:
    ((short*)tunowk)[24] = -25; /* Line 188, Address: 0x1022930 */
    ((short*)tunowk)[25] = 0; /* Line 189, Address: 0x102293c */
    if (tunowk->mstno.b.h) { /* Line 190, Address: 0x1022944 */
      ((short*)tunowk)[24] = -19; /* Line 191, Address: 0x1022954 */
      ((short*)tunowk)[25] = -15; /* Line 192, Address: 0x1022960 */
    }
    if (tunowk->actflg & 1) { /* Line 194, Address: 0x102296c */
      ((short*)tunowk)[24] = -((short*)tunowk)[24]; /* Line 195, Address: 0x1022984 */
    }
  }

  tunowk->xposi.w.h = bodywk->xposi.w.h + ((short*)tunowk)[24]; /* Line 199, Address: 0x10229a8 */
  tunowk->yposi.w.h = bodywk->yposi.w.h + ((short*)tunowk)[25]; /* Line 200, Address: 0x10229d8 */

  patchg(tunowk, pchg); /* Line 202, Address: 0x1022a08 */
} /* Line 203, Address: 0x1022a1c */
