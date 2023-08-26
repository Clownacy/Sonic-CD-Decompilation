#include "EQU.H"
#include "ET1.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "PLAYSUB.H"
#include "RIDECHK.H"
#include "SCORE.H"

extern void soundset(short ReqNo);

spr_array tpat00 = {
  1,
  { { -40, 16, 0, 481 } }
};
spr_array tpat01 = {
  1,
  { { -40, 16, 0, 482 } }
};
spr_array tpat07 = {
  1,
  { { 0, 0, 0, 0 } }
};
spr_array tpat02 = {
  2,
  {
    { -24, -32, 0, 488 },
    { -40, -32, 0, 489 }
  }
};
spr_array tpat03 = {
  3,
  {
    { -22, -8, 0, 490 },
    { -24, -32, 0, 488 },
    { -40, -32, 0, 489 }
  }
};
spr_array tpat04 = {
  4,
  {
    { -22, -8, 0, 491 },
    { -24, -32, 0, 494 },
    { -24, -32, 0, 488 },
    { -40, -32, 0, 489 }
  }
};
spr_array tpat05 = {
  4,
  {
    { -22, -8, 0, 492 },
    { -24, -32, 0, 494 },
    { -24, -32, 0, 488 },
    { -40, -32, 0, 489 }
  }
};
spr_array tpat06 = {
  4,
  {
    { -22, -8, 0, 493 },
    { -24, -32, 0, 496 },
    { -24, -32, 0, 488 },
    { -40, -32, 0, 489 }
  }
};
spr_array* pat_et[8] = {
  &tpat00,
  &tpat01,
  &tpat02,
  &tpat03,
  &tpat04,
  &tpat05,
  &tpat06,
  &tpat07
};
unsigned short tbl0sproffset[11] = {
  1087, 1033,    0,    0,
  1108, 1024,    0,    0,
     0,    0,    0
};
char tbl0[64] = {
    1,   0,   0,   2,
  -40, -20,   3,  28,
   10,   4,  18, -18,
    5, -18, -10,   6,
    8,  -8,   8, -18,
   14,  10, -10,  10,
   12,  30, -10,  15,
    0, -18,  18,  20,
  -10,  20, -10,  18,
   22,   8,  23,  25,
   13, -10,  26,  23,
  -22,  28,  -3, -25,
   30,  10,  20,  32,
  -10,   2,  34,  30,
   -8,  35,  13, -10,
   40, -10,  10,  -1
};
char pchg0[6] = { 3, 3, 4, 5, 6, -1 };
char* pchg[1] = { pchg0 };















































void et(act_info* actionwk) { /* Line 147, Address: 0x1020fd0 */
  switch (actionwk->r_no0) { /* Line 148, Address: 0x1020fdc */

    case 0:
      m_init(actionwk); /* Line 151, Address: 0x102101c */
    case 2:
      m_wait(actionwk); /* Line 153, Address: 0x1021028 */
      break; /* Line 154, Address: 0x1021034 */
    case 4:
      m_die(actionwk); /* Line 156, Address: 0x102103c */
      break; /* Line 157, Address: 0x1021048 */
    case 6:
      m1wait(actionwk); /* Line 159, Address: 0x1021050 */
      break;
  }
  actionsub(actionwk); /* Line 162, Address: 0x102105c */
  if (actionwk->r_no0 < 3) { /* Line 163, Address: 0x1021068 */
    frameout_s(actionwk); /* Line 164, Address: 0x1021080 */
  }
} /* Line 166, Address: 0x102108c */


void m_init(act_info* actionwk) { /* Line 169, Address: 0x10210a0 */
  unsigned short* a1;
  unsigned short d0;

  actionwk->r_no0 += 2; /* Line 173, Address: 0x10210b0 */
  actionwk->actflg |= 4; /* Line 174, Address: 0x10210c0 */
  actionwk->sprpri = 4; /* Line 175, Address: 0x10210d0 */
  actionwk->sprhs = 34; /* Line 176, Address: 0x10210dc */
  actionwk->sprhsize = 34; /* Line 177, Address: 0x10210e8 */
  actionwk->sprvsize = 32; /* Line 178, Address: 0x10210f4 */

  a1 = tbl0sproffset; /* Line 180, Address: 0x1021100 */
  d0 = (stageno.w + 1) * 4 + time_flag; /* Line 181, Address: 0x1021108 */
  actionwk->sproffset = a1[d0]; /* Line 182, Address: 0x102113c */





  actionwk->patbase = pat_et; /* Line 188, Address: 0x1021154 */

  *(short*)&actionwk->actfree[2] = 0; /* Line 190, Address: 0x1021164 */
  *(short*)&actionwk->actfree[6] = actionwk->yposi.w.h; /* Line 191, Address: 0x102116c */
  *(short*)&actionwk->actfree[0] = 4; /* Line 192, Address: 0x102117c */
  *(short*)&actionwk->actfree[8] = 1; /* Line 193, Address: 0x1021188 */

  d0 = 0; /* Line 195, Address: 0x1021194 */
  if (generate_flag == 0) d0 += 2; /* Line 196, Address: 0x1021198 */
  if (time_flag == 0) ++d0; /* Line 197, Address: 0x10211b4 */
  actionwk->patno = d0; /* Line 198, Address: 0x10211d0 */
  if (generate_flag == 0 && time_flag == 0) { /* Line 199, Address: 0x10211dc */

    actionwk->colino = 250; /* Line 201, Address: 0x1021204 */
    actionwk->yposi.w.h -= 16; /* Line 202, Address: 0x1021210 */
  }
} /* Line 204, Address: 0x1021220 */

void m_wait(act_info* actionwk) { /* Line 206, Address: 0x1021240 */
  int d0;
  act_info* a1;

  if (generate_flag != 0 || time_flag != 0) return; /* Line 210, Address: 0x1021254 */
  a_hover(actionwk); /* Line 211, Address: 0x1021284 */

  if (actionwk->colicnt != 0) { /* Line 213, Address: 0x1021290 */
    actionwk->colino = 0; /* Line 214, Address: 0x10212a4 */
    *(short*)&actionwk->actfree[0] = 0; /* Line 215, Address: 0x10212ac */
    actionwk->patno = 7; /* Line 216, Address: 0x10212b4 */
    actionwk->r_no0 += 2; /* Line 217, Address: 0x10212c0 */
    generate_flag = 1; /* Line 218, Address: 0x10212d0 */
    d0 = 150; /* Line 219, Address: 0x10212dc */
    scoreup(d0); /* Line 220, Address: 0x10212e0 */
    a1 = &actwk[0]; /* Line 221, Address: 0x10212ec */
    if (hitchk(actionwk, a1) != 0) ride_on_clr(actionwk, a1); /* Line 222, Address: 0x10212f4 */
    return; /* Line 223, Address: 0x102131c */
  }
  hitchk(actionwk, &actwk[0]); /* Line 225, Address: 0x1021324 */
  patchg(actionwk, (unsigned char**)pchg); /* Line 226, Address: 0x1021338 */
} /* Line 227, Address: 0x102134c */

void m_die(act_info* actionwk) { /* Line 229, Address: 0x1021370 */
  act_info* a1;
  char d0;
  short d5, d6, a6;

  a6 = *(short*)&actionwk->actfree[2]; /* Line 234, Address: 0x102138c */
  d0 = tbl0[a6++]; /* Line 235, Address: 0x102139c */
  if (d0 < 0) { /* Line 236, Address: 0x10213cc */

    actionwk->r_no0 += 2; /* Line 238, Address: 0x10213dc */
    actionwk->actfree[0] = 8; /* Line 239, Address: 0x10213ec */
    return; /* Line 240, Address: 0x10213f8 */
  }
  ++actionwk->actfree[0]; /* Line 242, Address: 0x1021400 */
  if (actionwk->actfree[0] != d0) return; /* Line 243, Address: 0x1021410 */
  d6 = tbl0[a6++]; /* Line 244, Address: 0x1021430 */
  d5 = tbl0[a6++]; /* Line 245, Address: 0x1021468 */
  *(short*)&actionwk->actfree[2] = a6; /* Line 246, Address: 0x10214a0 */
  if (actwkchk(&a1) != 0) return; /* Line 247, Address: 0x10214a8 */
  a1->actno = 24; /* Line 248, Address: 0x10214bc */
  a1->r_no1 = 1; /* Line 249, Address: 0x10214c8 */
  a1->xposi = actionwk->xposi; /* Line 250, Address: 0x10214d4 */
  a1->yposi = actionwk->yposi; /* Line 251, Address: 0x10214ec */
  a1->xposi.w.h += d6; /* Line 252, Address: 0x1021504 */
  a1->yposi.w.h += d5; /* Line 253, Address: 0x1021514 */
  baku_init(a1); /* Line 254, Address: 0x1021524 */
  soundset(158); /* Line 255, Address: 0x1021530 */
} /* Line 256, Address: 0x102153c */

void m1wait(act_info* actionwk) { /* Line 258, Address: 0x1021560 */
  if (--actionwk->actfree[0] != 0) return; /* Line 259, Address: 0x102156c */
  actionwk->r_no0 -= 6; /* Line 260, Address: 0x1021588 */
  actionwk->yposi.w.h = *(short*)&actionwk->actfree[6]; /* Line 261, Address: 0x1021598 */
  soundset(217); /* Line 262, Address: 0x10215a8 */
} /* Line 263, Address: 0x10215b4 */

void a_hover(act_info* actionwk) { /* Line 265, Address: 0x10215d0 */
  unsigned short d0;

  ++*(short*)&actionwk->actfree[0]; /* Line 268, Address: 0x10215dc */
  d0 = actionwk->actfree[0]; /* Line 269, Address: 0x10215ec */
  d0 %= 8; /* Line 270, Address: 0x10215f8 */
  if (d0 == 0) { /* Line 271, Address: 0x1021600 */

    d0 = *(short*)&actionwk->actfree[8]; /* Line 273, Address: 0x102160c */
    actionwk->yposi.w.h += d0; /* Line 274, Address: 0x1021618 */
  }
  d0 = *(short*)&actionwk->actfree[0]; /* Line 276, Address: 0x1021630 */
  d0 %= 32; /* Line 277, Address: 0x102163c */
  if (d0 == 0) *(short*)&actionwk->actfree[8] = -*(short*)&actionwk->actfree[8]; /* Line 278, Address: 0x1021644 */
} /* Line 279, Address: 0x1021674 */
