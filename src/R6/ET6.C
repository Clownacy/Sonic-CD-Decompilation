#include "..\EQU.H"
#include "ET6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"
#include "..\SCORE.H"

static void m_init(sprite_status* actionwk);
static void m_wait(sprite_status* actionwk);

static sprite_pattern tpat00 = {
  1,
  { { -40, 15, 0, 419 } }
};
static sprite_pattern tpat01 = {
  1,
  { { -40, 16, 0, 420 } }
};
static sprite_pattern tpat07 = {
  1,
  { { 0, 0, 0, 0 } }
};
static sprite_pattern tpat02 = {
  2,
  { {
    { -24, -32, 0, 426 },
    { -40, -32, 0, 427 }
  } }
};
static sprite_pattern tpat03 = {
  3,
  { {
    { -22, -8, 0, 428 },
    { -24, -32, 0, 426 },
    { -40, -32, 0, 427 }
  } }
};
static sprite_pattern tpat04 = {
  4,
  { {
    { -22, -8, 0, 429 },
    { -24, -32, 0, 432 },
    { -24, -32, 0, 426 },
    { -40, -32, 0, 427 }
  } }
};
static sprite_pattern tpat05 = {
  4,
  { {
    { -22, -8, 0, 430 },
    { -24, -32, 0, 433 },
    { -24, -32, 0, 426 },
    { -40, -32, 0, 427 }
  } }
};
static sprite_pattern tpat06 = {
  4,
  { {
    { -22, -8, 0, 431 },
    { -24, -32, 0, 434 },
    { -24, -32, 0, 426 },
    { -40, -32, 0, 427 }
  } }
};
sprite_pattern* pat_et[8] = {
  &tpat00,
  &tpat01,
  &tpat02,
  &tpat03,
  &tpat04,
  &tpat05,
  &tpat06
};
static unsigned short tbl0sproffset[11] = {
  1087, 1033, 0, 0,
  1108, 1024, 0, 0,
     0,    0, 0
};
static char tbl0[64] = {
    1,   0,   0,   2, -40, -20,   3,  28,  10,   4,
   18, -18,   5, -18, -10,   6,   8,  -8,   8, -18,
   14,  10, -10,  10,  12,  30, -10,  15,   0, -18,
   18,  20, -10,  20, -10,  18,  22,   8,  23,  25,
   13, -10,  26,  23, -22,  28,  -3, -25,  30,  10,
   20,  32, -10,   2,  34,  30,  -8,  35,  13, -10,
   40, -10,  10,  -1
};
static char pchg0[6] = { 3, 3, 4, 5, 6, -1 };
static char* pchg[1] = { pchg0 };




















































void et(sprite_status* actionwk) { /* Line 144, Address: 0x101af70 */
  switch (actionwk->r_no0) { /* Line 145, Address: 0x101af7c */

    case 0:
      m_init(actionwk); /* Line 148, Address: 0x101afbc */
    case 2:
      m_wait(actionwk); /* Line 150, Address: 0x101afc8 */
      break; /* Line 151, Address: 0x101afd4 */
    case 4:
      m_die(actionwk); /* Line 153, Address: 0x101afdc */
      break; /* Line 154, Address: 0x101afe8 */
    case 6:
      m1wait(actionwk); /* Line 156, Address: 0x101aff0 */
  }

  actionsub(actionwk); /* Line 159, Address: 0x101affc */
  if (actionwk->r_no0 <= 2) { /* Line 160, Address: 0x101b008 */
    frameout_s(actionwk); /* Line 161, Address: 0x101b020 */
  }
} /* Line 163, Address: 0x101b02c */


static void m_init(sprite_status* actionwk) { /* Line 166, Address: 0x101b040 */
  unsigned short* a1;
  unsigned short d0;

  actionwk->r_no0 += 2; /* Line 170, Address: 0x101b050 */
  actionwk->actflg |= 4; /* Line 171, Address: 0x101b060 */
  actionwk->sprpri = 4; /* Line 172, Address: 0x101b070 */
  actionwk->sprhs = 34; /* Line 173, Address: 0x101b07c */
  actionwk->sprhsize = 34; /* Line 174, Address: 0x101b088 */
  actionwk->sprvsize = 32; /* Line 175, Address: 0x101b094 */

  a1 = tbl0sproffset; /* Line 177, Address: 0x101b0a0 */
  d0 = ((stageno.w + 1) << 2) + (unsigned short)time_flag; /* Line 178, Address: 0x101b0a8 */
  actionwk->sproffset = a1[d0]; /* Line 179, Address: 0x101b0dc */





  actionwk->patbase = pat_et; /* Line 185, Address: 0x101b0f4 */

  ((short*)actionwk)[24] = 0; /* Line 187, Address: 0x101b104 */
  ((short*)actionwk)[26] = actionwk->yposi.w.h; /* Line 188, Address: 0x101b10c */
  ((short*)actionwk)[23] = 4; /* Line 189, Address: 0x101b11c */
  ((short*)actionwk)[27] = 1; /* Line 190, Address: 0x101b128 */

  d0 = 0; /* Line 192, Address: 0x101b134 */
  if (generate_flag == 0) d0 += 2; /* Line 193, Address: 0x101b138 */
  if (time_flag == 0) ++d0; /* Line 194, Address: 0x101b154 */
  actionwk->patno = d0; /* Line 195, Address: 0x101b170 */
  if (generate_flag == 0 && time_flag == 0) { /* Line 196, Address: 0x101b17c */

    actionwk->colino = 250; /* Line 198, Address: 0x101b1a4 */
    actionwk->yposi.w.h -= 16; /* Line 199, Address: 0x101b1b0 */
  }
} /* Line 201, Address: 0x101b1c0 */

static void m_wait(sprite_status* actionwk) { /* Line 203, Address: 0x101b1e0 */
  int d0;
  sprite_status* a1;

  if (generate_flag != 0 || time_flag != 0) return; /* Line 207, Address: 0x101b1f4 */
  a_hover(actionwk); /* Line 208, Address: 0x101b224 */

  if (actionwk->colicnt != 0) { /* Line 210, Address: 0x101b230 */
    actionwk->colino = 0; /* Line 211, Address: 0x101b244 */
    ((short*)actionwk)[23] = 0; /* Line 212, Address: 0x101b24c */
    actionwk->patno = 7; /* Line 213, Address: 0x101b254 */
    actionwk->r_no0 += 2; /* Line 214, Address: 0x101b260 */
    generate_flag = 1; /* Line 215, Address: 0x101b270 */
    d0 = 150; /* Line 216, Address: 0x101b27c */
    scoreup(d0); /* Line 217, Address: 0x101b280 */
    a1 = &actwk[0]; /* Line 218, Address: 0x101b28c */
    if (hitchk(actionwk, a1)) ride_on_clr(actionwk, a1); /* Line 219, Address: 0x101b294 */
    return; /* Line 220, Address: 0x101b2bc */
  }
  hitchk(actionwk, &actwk[0]); /* Line 222, Address: 0x101b2c4 */
  patchg(actionwk, (unsigned char**)pchg); /* Line 223, Address: 0x101b2d8 */
} /* Line 224, Address: 0x101b2ec */

void m_die(sprite_status* actionwk) { /* Line 226, Address: 0x101b310 */
  sprite_status* a1;
  char d0;
  short d5, d6, a6;

  a6 = ((short*)actionwk)[24]; /* Line 231, Address: 0x101b32c */
  d0 = tbl0[a6++]; /* Line 232, Address: 0x101b33c */
  if (d0 < 0) { /* Line 233, Address: 0x101b36c */

    actionwk->r_no0 += 2; /* Line 235, Address: 0x101b37c */
    ((char*)actionwk)[46] = 8; /* Line 236, Address: 0x101b38c */
    return; /* Line 237, Address: 0x101b398 */
  }
  ++((char*)actionwk)[46]; /* Line 239, Address: 0x101b3a0 */
  if (((char*)actionwk)[46] != d0) return; /* Line 240, Address: 0x101b3b0 */
  d5 = tbl0[a6++]; /* Line 241, Address: 0x101b3d0 */
  d6 = tbl0[a6++]; /* Line 242, Address: 0x101b408 */
  ((short*)actionwk)[24] = a6; /* Line 243, Address: 0x101b440 */
  if (actwkchk(&a1) != 0) return; /* Line 244, Address: 0x101b448 */
  a1->actno = 24; /* Line 245, Address: 0x101b45c */
  a1->r_no1 = 1; /* Line 246, Address: 0x101b468 */
  a1->xposi = actionwk->xposi; /* Line 247, Address: 0x101b474 */
  a1->yposi = actionwk->yposi; /* Line 248, Address: 0x101b48c */
  a1->xposi.w.h += d5; /* Line 249, Address: 0x101b4a4 */
  a1->yposi.w.h += d6; /* Line 250, Address: 0x101b4b4 */
  baku_init(a1); /* Line 251, Address: 0x101b4c4 */
  soundset(158); /* Line 252, Address: 0x101b4d0 */
} /* Line 253, Address: 0x101b4dc */

void m1wait(sprite_status* actionwk) { /* Line 255, Address: 0x101b500 */
  if (--actionwk->actfree[0]) return; /* Line 256, Address: 0x101b50c */
  actionwk->r_no0 -= 6; /* Line 257, Address: 0x101b528 */
  actionwk->yposi.w.h = ((short*)actionwk)[26]; /* Line 258, Address: 0x101b538 */
  soundset(217); /* Line 259, Address: 0x101b548 */
} /* Line 260, Address: 0x101b554 */

void a_hover(sprite_status* actionwk) { /* Line 262, Address: 0x101b570 */
  unsigned short d0;

  ++((unsigned short*)actionwk)[23]; /* Line 265, Address: 0x101b57c */
  d0 = ((unsigned short*)actionwk)[23]; /* Line 266, Address: 0x101b58c */
  d0 &= 7; /* Line 267, Address: 0x101b598 */
  if (d0 == 0) { /* Line 268, Address: 0x101b5a0 */

    d0 = ((unsigned short*)actionwk)[27]; /* Line 270, Address: 0x101b5ac */
    actionwk->yposi.w.h += d0; /* Line 271, Address: 0x101b5b8 */
  }
  d0 = ((unsigned short*)actionwk)[23]; /* Line 273, Address: 0x101b5d0 */
  d0 &= 31; /* Line 274, Address: 0x101b5dc */
  if (d0 == 0) ((short*)actionwk)[27] = -((short*)actionwk)[27]; /* Line 275, Address: 0x101b5e4 */
} /* Line 276, Address: 0x101b614 */
