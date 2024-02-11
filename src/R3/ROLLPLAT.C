#include "..\EQU.H"
#include "ROLLPLAT.H"

static unsigned char pchg00[6] = { 3, 1, 2, 3, 0, 255 };
static unsigned char pchg01[6] = { 3, 3, 2, 1, 0, 255 };
unsigned char* pchg[2] = { pchg00, pchg01 };
static sprite_pattern kpat00 = { 1, { { -16, -8, 0, 316 } } };
static sprite_pattern kpat01 = { 1, { { -16, -16, 0, 317 } } };
static sprite_pattern kpat02 = { 1, { { -16, -16, 0, 318 } } };
static sprite_pattern kpat03 = { 1, { { -16, -16, 0, 319 } } };
sprite_pattern* kaitenban_pat[4] = { &kpat00, &kpat01, &kpat02, &kpat03 };















void kaitenban(sprite_status* banwk) { /* Line 27, Address: 0x102f6c0 */
  void(*act_tbl[2])(sprite_status*) = { &act_init, &act_move }; /* Line 28, Address: 0x102f6cc */

  act_tbl[banwk->r_no0 / 2](banwk); /* Line 30, Address: 0x102f6e8 */
  actionsub(banwk); /* Line 31, Address: 0x102f724 */
  frameout_s(banwk); /* Line 32, Address: 0x102f730 */
} /* Line 33, Address: 0x102f73c */



static void act_init(sprite_status* banwk) { /* Line 37, Address: 0x102f750 */
  sprite_status* new_actwk;

  banwk->r_no0 += 2; /* Line 40, Address: 0x102f75c */
  banwk->actflg |= 4; /* Line 41, Address: 0x102f76c */
  banwk->sprpri = 3; /* Line 42, Address: 0x102f77c */
  banwk->sprhsize = 16; /* Line 43, Address: 0x102f788 */
  banwk->sprvsize = 16; /* Line 44, Address: 0x102f794 */

  banwk->patbase = kaitenban_pat; /* Line 46, Address: 0x102f7a0 */
  ((short*)banwk)[25] = -2; /* Line 47, Address: 0x102f7b0 */
  if (banwk->userflag.b.h == -1) { /* Line 48, Address: 0x102f7bc */
    ((short*)banwk)[23] = 128; /* Line 49, Address: 0x102f7d8 */
    banwk->actfree[20] = banwk->actfree[21] = 255; /* Line 50, Address: 0x102f7e4 */
  }
  if (actwkchk(&new_actwk) == 0) { /* Line 52, Address: 0x102f7fc */
    ((unsigned short*)banwk)[24] = new_actwk - actwk; /* Line 53, Address: 0x102f810 */
    ((unsigned short*)new_actwk)[29] = banwk - actwk; /* Line 54, Address: 0x102f844 */
    new_actwk->actno = banwk->actno; /* Line 55, Address: 0x102f878 */
    new_actwk->userflag.b.h = 1; /* Line 56, Address: 0x102f888 */
    new_actwk->xposi.w.h = 896; /* Line 57, Address: 0x102f894 */
    new_actwk->yposi.w.h = 1272; /* Line 58, Address: 0x102f8a0 */
  }
  act_move(banwk); /* Line 60, Address: 0x102f8ac */
} /* Line 61, Address: 0x102f8b8 */



static void act_move(sprite_status* banwk) { /* Line 65, Address: 0x102f8d0 */
  act_check(banwk); /* Line 66, Address: 0x102f8dc */

  if (((short*)banwk)[23] != 0) { /* Line 68, Address: 0x102f8e8 */
    --((short*)banwk)[23]; /* Line 69, Address: 0x102f900 */
    patchg(banwk, pchg); /* Line 70, Address: 0x102f910 */
  }
} /* Line 72, Address: 0x102f924 */


static void act_check(sprite_status* banwk) { /* Line 75, Address: 0x102f940 */
  short tbl[3] = { 1176, 1200, 1224 }; /* Line 76, Address: 0x102f950 */
  short cal_d0;
  sprite_status* new_actwk;

  if ((unsigned short)(banwk->yposi.w.h - actwk[0].yposi.w.h + 16) >= 32) /* Line 80, Address: 0x102f974 */
  { banwk->actfree[20] = 0; return; } /* Line 81, Address: 0x102f9b0 */
  if ((unsigned short)(banwk->xposi.w.h - actwk[0].xposi.w.h + 16) >= 32) /* Line 82, Address: 0x102f9c0 */
  { banwk->actfree[20] = 0; return; } /* Line 83, Address: 0x102f9fc */
  if (banwk->actfree[20] != 0) return; /* Line 84, Address: 0x102fa0c */
  banwk->actfree[20] = 255; /* Line 85, Address: 0x102fa20 */
  if (actwk[0].yspeed.w >= 0) banwk->mstno.w = 255; /* Line 86, Address: 0x102fa2c */
  else banwk->mstno.w = 511; /* Line 87, Address: 0x102fa58 */

  cal_d0 = ((short*)banwk)[23]; /* Line 89, Address: 0x102fa64 */
  ((short*)banwk)[23] = 128; /* Line 90, Address: 0x102fa74 */
  if (cal_d0 != 0) return; /* Line 91, Address: 0x102fa80 */


  if (((short*)banwk)[25] != 4) { /* Line 94, Address: 0x102fa90 */
    ((short*)banwk)[25] += 2; /* Line 95, Address: 0x102faac */
    ((short*)banwk)[28] = ((short*)banwk)[27]; /* Line 96, Address: 0x102fabc */

    ((short*)banwk)[27] = ((short*)banwk)[26]; /* Line 98, Address: 0x102facc */

    if (actwkchk(&new_actwk) == 0) { /* Line 100, Address: 0x102fadc */
      ((unsigned short*)banwk)[26] = new_actwk - actwk; /* Line 101, Address: 0x102faf0 */
      ((unsigned short*)new_actwk)[29] = banwk - actwk; /* Line 102, Address: 0x102fb24 */
      new_actwk->actno = banwk->actno; /* Line 103, Address: 0x102fb58 */
      new_actwk->xposi.w.h = 896; /* Line 104, Address: 0x102fb68 */
      new_actwk->yposi.w.h = tbl[((short*)banwk)[25] / 2]; /* Line 105, Address: 0x102fb74 */
    }

    if (((short*)banwk)[25] == 4) /* Line 108, Address: 0x102fbb0 */
      actwk[((unsigned short*)banwk)[24]].r_no0 = 4; /* Line 109, Address: 0x102fbcc */
    return; /* Line 110, Address: 0x102fbf8 */
  }

  ((short*)banwk)[25] = -2; /* Line 113, Address: 0x102fc00 */
  actwk[((unsigned short*)banwk)[26]].r_no0 = 4; /* Line 114, Address: 0x102fc0c */
  actwk[((unsigned short*)banwk)[27]].r_no0 = 4; /* Line 115, Address: 0x102fc38 */
  actwk[((unsigned short*)banwk)[28]].r_no0 = 4; /* Line 116, Address: 0x102fc64 */
  actwk[((unsigned short*)banwk)[24]].r_no0 = 6; /* Line 117, Address: 0x102fc90 */
} /* Line 118, Address: 0x102fcbc */
