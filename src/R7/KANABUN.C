#include "..\EQU.H"
#include "KANABUN.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static sprite_pattern pat_e00 = {
  1,
  { { -16, -16, 128, 415 } }
};
static sprite_pattern pat_e01 = {
  1,
  { { -16, -16, 128, 416 } }
};
static sprite_pattern pat_e02 = {
  1,
  { { -12, -12, 128, 417 } }
};
static sprite_pattern pat_e03 = {
  1,
  { { -12, -12, 128, 418 } }
};
static sprite_pattern pat_e04 = {
  1,
  { { -12, -12, 0, 419 } }
};
static sprite_pattern pat_e05 = {
  1,
  { { -12, -12, 0, 420 } }
};
static sprite_pattern pat_e06 = {
  1,
  { { -12, -12, 0, 421 } }
};
static sprite_pattern pat_e07 = {
  1,
  { { -12, -12, 0, 422 } }
};
sprite_pattern* pat_kanabun_e[8] = {
  &pat_e00,
  &pat_e01,
  &pat_e02,
  &pat_e03,
  &pat_e04,
  &pat_e05,
  &pat_e06,
  &pat_e07
};
static sprite_pattern pat_b00 = {
  1,
  { { -16, -16, 128, 407 } }
};
static sprite_pattern pat_b01 = {
  1,
  { { -16, -16, 128, 408 } }
};
static sprite_pattern pat_b02 = {
  1,
  { { -12, -12, 128, 409 } }
};
static sprite_pattern pat_b03 = {
  1,
  { { -12, -12, 128, 410 } }
};
static sprite_pattern pat_b04 = {
  1,
  { { -12, -12, 0, 411 } }
};
static sprite_pattern pat_b05 = {
  1,
  { { -12, -12, 0, 412 } }
};
static sprite_pattern pat_b06 = {
  1,
  { { -12, -12, 0, 413 } }
};
static sprite_pattern pat_b07 = {
  1,
  { { -12, -12, 0, 414 } }
};
sprite_pattern* pat_kanabun_b[8] = {
  &pat_b00,
  &pat_b01,
  &pat_b02,
  &pat_b03,
  &pat_b04,
  &pat_b05,
  &pat_b06,
  &pat_b07
};
static unsigned char pchg_e00[66] = {
  1, 6, 7, 6, 7, 6, 7, 6, 7, 4,
  5, 4, 5, 4, 5, 4, 5, 2, 3, 2,
  3, 2, 3, 2, 3, 0, 1, 0, 1, 0,
  1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
  1, 2, 3, 2, 3, 2, 3, 2, 3, 4,
  5, 4, 5, 4, 5, 4, 5, 6, 7, 6,
  7, 6, 7, 6, 7, 255
};
static unsigned char* pchg_e[1] = { pchg_e00 };
static unsigned char pchg_b00[66] = {
  3, 6, 7, 6, 7, 6, 7, 6, 7, 4,
  5, 4, 5, 4, 5, 4, 5, 2, 3, 2,
  3, 2, 3, 2, 3, 0, 1, 0, 1, 0,
  1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
  1, 2, 3, 2, 3, 2, 3, 2, 3, 4,
  5, 4, 5, 4, 5, 4, 5, 6, 7, 6,
  7, 6, 7, 6, 7, 255
};
static unsigned char* pchg_b[1] = { pchg_b00 };
static char tbl0[4] = { 47, 48, 48, 0 };
















































































void kanabun(sprite_status* pActwk) { /* Line 194, Address: 0x1022260 */
  int_union poswk;
  int spdwk;
  short sinwk, coswk;

  if (enemy_suicide(pActwk)) return; /* Line 199, Address: 0x1022270 */



  if (!pActwk->r_no0) { /* Line 203, Address: 0x1022284 */

    pActwk->r_no0 += 2; /* Line 205, Address: 0x1022294 */
    pActwk->actflg |= 4; /* Line 206, Address: 0x10222a4 */
    pActwk->sprpri = 3; /* Line 207, Address: 0x10222b4 */
    pActwk->sproffset = 9193; /* Line 208, Address: 0x10222c0 */
    pActwk->sprhs = 16; /* Line 209, Address: 0x10222cc */
    pActwk->sprhsize = 16; /* Line 210, Address: 0x10222d8 */
    pActwk->sprvsize = 16; /* Line 211, Address: 0x10222e4 */
    ((short*)pActwk)[31] = pActwk->xposi.w.h; /* Line 212, Address: 0x10222f0 */
    ((short*)pActwk)[26] = pActwk->yposi.w.h; /* Line 213, Address: 0x1022300 */
    ((short*)pActwk)[25] = -32768; /* Line 214, Address: 0x1022310 */

    if (!pActwk->userflag.b.h) { /* Line 216, Address: 0x102231c */
      pActwk->patbase = pat_kanabun_e; /* Line 217, Address: 0x102232c */
      *(unsigned char***)&pActwk->actfree[12] = pchg_e; /* Line 218, Address: 0x102233c */
      ((short*)pActwk)[28] = -512; /* Line 219, Address: 0x1022350 */
      ((int*)pActwk)[16] = -16384; /* Line 220, Address: 0x102235c */
    } else { /* Line 221, Address: 0x1022368 */
      pActwk->patbase = pat_kanabun_b; /* Line 222, Address: 0x1022370 */
      *(unsigned char***)&pActwk->actfree[12] = pchg_b; /* Line 223, Address: 0x1022380 */
      ((short*)pActwk)[28] = -256; /* Line 224, Address: 0x1022394 */
      ((int*)pActwk)[16] = -16384; /* Line 225, Address: 0x10223a0 */
    }
  }


  poswk.l = spdwk = pActwk->xposi.l + ((int*)pActwk)[16]; /* Line 230, Address: 0x10223ac */
  poswk.l = (unsigned int)poswk.l >> 16 & 65535 | poswk.l << 16 & -65536; /* Line 231, Address: 0x10223c4 */

  if ((poswk.w.l -= ((short*)pActwk)[31]) < 0) { /* Line 233, Address: 0x10223e8 */
    poswk.w.l *= -1; /* Line 234, Address: 0x1022414 */
  }


  if (poswk.w.l > 64) { /* Line 238, Address: 0x1022420 */
    ((int*)pActwk)[16] *= -1; /* Line 239, Address: 0x1022438 */
    spdwk += ((int*)pActwk)[16]; /* Line 240, Address: 0x1022448 */
    pActwk->actflg ^= 1; /* Line 241, Address: 0x1022454 */
    pActwk->cddat ^= 1; /* Line 242, Address: 0x1022464 */
    ((short*)pActwk)[27] = 0; /* Line 243, Address: 0x1022474 */
    pActwk->mstno.w = 255; /* Line 244, Address: 0x102247c */
  }


  pActwk->xposi.l = spdwk; /* Line 248, Address: 0x1022488 */
  poswk.w.l = ((short*)pActwk)[27] + ((short*)pActwk)[28]; /* Line 249, Address: 0x1022490 */

  ((short*)pActwk)[27] = poswk.w.l; /* Line 251, Address: 0x10224c0 */
  poswk.w.l = (unsigned short)poswk.w.l >> 8; /* Line 252, Address: 0x10224cc */
  sinset(poswk.w.l, &sinwk, &coswk); /* Line 253, Address: 0x10224e8 */
  poswk.w.l = sinwk; /* Line 254, Address: 0x1022500 */
  poswk.l = (unsigned int)poswk.l >> 16 & 65535 | poswk.l << 16 & -65536; /* Line 255, Address: 0x1022508 */
  poswk.l >>= 2; /* Line 256, Address: 0x102252c */
  poswk.l += *(int*)&pActwk->actfree[4]; /* Line 257, Address: 0x1022538 */
  pActwk->yposi.l = poswk.l; /* Line 258, Address: 0x1022550 */

  patchg(pActwk, *(unsigned char***)&pActwk->actfree[12]); /* Line 260, Address: 0x102255c */
  pActwk->colino = tbl0[pActwk->patno >> 1]; /* Line 261, Address: 0x1022574 */
  actionsub(pActwk); /* Line 262, Address: 0x102259c */
  frameout_s00(pActwk, ((short*)pActwk)[31]); /* Line 263, Address: 0x10225a8 */
} /* Line 264, Address: 0x10225bc */
