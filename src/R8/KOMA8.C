#include "..\EQU.H"
#include "KOMA8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\PLAYSUB.H"

#if defined(R82)
  #define SPRITE_KOMA8_BASE 313
#elif defined(R83)
  #define SPRITE_KOMA8_BASE 306
#else
  #define SPRITE_KOMA8_BASE 304
#endif

static void koma_init(sprite_status* komawk);
static void koma_move(sprite_status* komawk);
static void koma_move2(sprite_status* komawk);

static unsigned char komachg0[4] = { 8, 0, 1, 255 };
static unsigned char* komachg[1] = { komachg0 };
static sprite_pattern kom00 = {
  1,
  { { -8, -8, 0, SPRITE_KOMA8_BASE } }
};
static sprite_pattern kom01 = {
  1,
  { { -8, -8, 0, SPRITE_KOMA8_BASE + 1 } }
};
sprite_pattern* koma8pat[2] = {
  &kom00,
  &kom01
};









void koma8(sprite_status* komawk) { /* Line 43, Address: 0x1025b30 */
  void(*tbl[3])(sprite_status*) = { &koma_init, &koma_move, &koma_move2 }; /* Line 44, Address: 0x1025b3c */
  tbl[komawk->r_no0 / 2](komawk); /* Line 45, Address: 0x1025b60 */
  frameout_s00(komawk, ((short*)komawk)[29]); /* Line 46, Address: 0x1025b9c */
} /* Line 47, Address: 0x1025bb0 */



static void koma_init(sprite_status* komawk) { /* Line 51, Address: 0x1025bc0 */
  sprite_status* sprwk;

  komawk->r_no0 += 2; /* Line 54, Address: 0x1025bcc */
  komawk->actflg |= 4; /* Line 55, Address: 0x1025bdc */
  komawk->sprpri = 4; /* Line 56, Address: 0x1025bec */
  komawk->patbase = koma8pat; /* Line 57, Address: 0x1025bf8 */
  komawk->sprhsize = 8; /* Line 58, Address: 0x1025c08 */
  komawk->sprvsize = 6; /* Line 59, Address: 0x1025c14 */
  ((short*)komawk)[29] = komawk->xposi.w.h; /* Line 60, Address: 0x1025c20 */
  komawk->xspeed.w = 256; /* Line 61, Address: 0x1025c30 */
  pa_set(); /* Line 62, Address: 0x1025c3c */
  if (actwkchk2(komawk, &sprwk) != 0) { frameout(komawk); return; }; /* Line 63, Address: 0x1025c44 */
  sprwk->actno = 10; /* Line 64, Address: 0x1025c70 */
  sprwk->xposi.w.h = komawk->xposi.w.h; /* Line 65, Address: 0x1025c7c */
  sprwk->yposi.w.h = komawk->yposi.w.h - 16; /* Line 66, Address: 0x1025c8c */
  sprwk->actfree[15] = 240; /* Line 67, Address: 0x1025cb0 */
  ((unsigned short*)sprwk)[28] = komawk - actwk; /* Line 68, Address: 0x1025cbc */
  sprwk->userflag.b.h = komawk->userflag.b.h & 15; /* Line 69, Address: 0x1025cf0 */

  ((short*)komawk)[31] = 80; /* Line 71, Address: 0x1025d14 */
  if (komawk->userflag.b.h < 0) ((short*)komawk)[31] = 64; /* Line 72, Address: 0x1025d20 */
  koma_move(komawk); /* Line 73, Address: 0x1025d44 */
} /* Line 74, Address: 0x1025d50 */


static void koma_move(sprite_status* komawk) { /* Line 77, Address: 0x1025d60 */
  short colli_data;

  if ((colli_data = emycol_d(komawk)) < 0) { /* Line 80, Address: 0x1025d70 */
    komawk->yposi.w.h += colli_data; /* Line 81, Address: 0x1025d9c */
    ((short*)komawk)[27] = komawk->yposi.w.h; /* Line 82, Address: 0x1025dac */
    komawk->r_no0 += 2; /* Line 83, Address: 0x1025dbc */
  } else { /* Line 84, Address: 0x1025dcc */
    ++komawk->yposi.w.h; /* Line 85, Address: 0x1025dd4 */
  }
} /* Line 87, Address: 0x1025de4 */


static void koma_move2(sprite_status* komawk) { /* Line 90, Address: 0x1025e00 */
  short colli_data, pos_data;

  if (komawk->xspeed.w >= 0) colli_data = emycol_r(komawk, 32); /* Line 93, Address: 0x1025e14 */
  else colli_data = emycol_l(komawk, 232); /* Line 94, Address: 0x1025e4c */
  if (colli_data < 7) goto label1; /* Line 95, Address: 0x1025e64 */

  if ((pos_data = komawk->xposi.w.h - ((short*)komawk)[29]) < 0) /* Line 97, Address: 0x1025e78 */
    pos_data = -pos_data; /* Line 98, Address: 0x1025ec4 */
  if (pos_data >= ((short*)komawk)[31]) goto label1; /* Line 99, Address: 0x1025ee0 */

  if ((colli_data = emycol_d(komawk)) < -7) goto label1; /* Line 101, Address: 0x1025f04 */
  if (colli_data > 7) goto label1; /* Line 102, Address: 0x1025f34 */
  komawk->yposi.w.h += colli_data; /* Line 103, Address: 0x1025f48 */
  goto label2; /* Line 104, Address: 0x1025f58 */
label1:
    komawk->xspeed.w = -komawk->xspeed.w; /* Line 106, Address: 0x1025f60 */
label2:
  speedset2(komawk); /* Line 108, Address: 0x1025f84 */
  patchg(komawk, komachg); /* Line 109, Address: 0x1025f90 */
  actionsub(komawk); /* Line 110, Address: 0x1025fa4 */
} /* Line 111, Address: 0x1025fb0 */
