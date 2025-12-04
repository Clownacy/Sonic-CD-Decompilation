#include "..\EQU.H"
#include "PROPERA8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\PLAYSUB.H"

static void propera0(sprite_status* actionwk);
static void a_init(sprite_status* actionwk);
static void a_init_sub(sprite_status* actionwk);
static void a_fall(sprite_status* actionwk);
static void a_move(sprite_status* actionwk);
static void propera1(sprite_status* actionwk);
static void b_init(sprite_status* actionwk);
static void b_close(sprite_status* actionwk);
static void b_close1(sprite_status* actionwk);
static void b_closed(sprite_status* actionwk);
static void b_closed1(sprite_status* actionwk);
static void b_open(sprite_status* actionwk);
static void b_open1(sprite_status* actionwk);
static void b_opend(sprite_status* actionwk);
static void b_opend1(sprite_status* actionwk);

static char p00[4] = { 10, 0, 1, -1 };
static char p01[8] = { 2, 0, 1, 2, 3, 4, 5, -1 };
static char* pchg[1] = { p00 };
static char* pchg1[1] = { p01 };
static sprite_pattern pat00 = { 1, { { -8, -40, 0, 454 } } };
static sprite_pattern pat01 = { 1, { { -8, -40, 0, 455 } } };
static sprite_pattern pat02 = { 1, { { -32, -4, 0, 456 } } };
static sprite_pattern pat03 = { 1, { { -24, -4, 0, 457 } } };
static sprite_pattern pat04 = { 1, { { -16, -4, 0, 458 } } };
static sprite_pattern pat05 = { 1, { { -4, -4, 0, 459 } } };
static sprite_pattern pat06 = { 1, { { -16, -4, 0, 460 } } };
static sprite_pattern pat07 = { 1, { { -24, -4, 0, 461 } } };
static sprite_pattern pat08 = { 1, { { -16, -4, 0, 462 } } };
static sprite_pattern pat09 = { 1, { { -12, -4, 0, 463 } } };
sprite_pattern* pat_propera[2] = {
  &pat00,
  &pat01
};
sprite_pattern* pat_propera1[8] =
{
  &pat02,
  &pat03,
  &pat04,
  &pat05,
  &pat06,
  &pat07,
  &pat08,
  &pat09
};











void propera(sprite_status* actionwk) { /* Line 64, Address: 0x1023390 */
  if (actionwk->userflag.b.h == 0) /* Line 65, Address: 0x102339c */
  {
    propera0(actionwk); /* Line 67, Address: 0x10233b4 */
  } /* Line 68, Address: 0x10233c0 */
  else
    propera1(actionwk); /* Line 70, Address: 0x10233c8 */
} /* Line 71, Address: 0x10233d4 */

static void propera0(sprite_status* actionwk) { /* Line 73, Address: 0x10233f0 */
  switch (actionwk->r_no0) /* Line 74, Address: 0x10233fc */
  {
    case 0:
      a_init(actionwk); /* Line 77, Address: 0x1023430 */
      break; /* Line 78, Address: 0x102343c */
    case 2:
      a_fall(actionwk); /* Line 80, Address: 0x1023444 */
      break; /* Line 81, Address: 0x1023450 */
    case 4:
      a_move(actionwk); /* Line 83, Address: 0x1023458 */
      break;
  }
  patchg(actionwk, (unsigned char**)pchg); /* Line 86, Address: 0x1023464 */
  actionsub(actionwk); /* Line 87, Address: 0x1023478 */
  frameout_s00(actionwk, ((short*)actionwk)[26]); /* Line 88, Address: 0x1023484 */
} /* Line 89, Address: 0x1023498 */

static void a_init(sprite_status* actionwk) { /* Line 91, Address: 0x10234b0 */
  sprite_status *a1, *a2;

  ((short*)actionwk)[26] = actionwk->xposi.w.h; /* Line 94, Address: 0x10234c0 */

  actionwk->r_no0 += 2; /* Line 96, Address: 0x10234d0 */
  actionwk->actflg |= 4; /* Line 97, Address: 0x10234e0 */
  actionwk->sprpri = 4; /* Line 98, Address: 0x10234f0 */
  actionwk->sproffset = 874; /* Line 99, Address: 0x10234fc */
  ((short*)actionwk)[23] = 128; /* Line 100, Address: 0x1023508 */
  ((int*)actionwk)[12] = 65536; /* Line 101, Address: 0x1023514 */
  actionwk->patbase = pat_propera; /* Line 102, Address: 0x1023520 */
  actionwk->sprhs = 8; /* Line 103, Address: 0x1023530 */
  actionwk->sprhsize = 8; /* Line 104, Address: 0x102353c */
  actionwk->sprvsize = 46; /* Line 105, Address: 0x1023548 */

  if (actwkchk2(actionwk, &a1) != 0) /* Line 107, Address: 0x1023554 */
  {
    frameout(actionwk); /* Line 109, Address: 0x102356c */
    return; /* Line 110, Address: 0x1023578 */
  }

  a1->actno = actionwk->actno; /* Line 113, Address: 0x1023580 */
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 114, Address: 0x1023590 */
  a1->userflag.b.h = 1; /* Line 115, Address: 0x10235c4 */
  a2 = a1; /* Line 116, Address: 0x10235d0 */
  if (actwkchk2(actionwk, &a1) != 0) /* Line 117, Address: 0x10235d4 */
  {
    frameout(actionwk); /* Line 119, Address: 0x10235ec */
    return; /* Line 120, Address: 0x10235f8 */
  }

  a1->actno = actionwk->actno; /* Line 123, Address: 0x1023600 */
  ((unsigned short*)a1)[33] = actionwk - actwk; /* Line 124, Address: 0x1023610 */
  a1->userflag.b.h = -1; /* Line 125, Address: 0x1023644 */
  ((short*)a1)[32] = -44; /* Line 126, Address: 0x1023650 */
  ((short*)a2)[32] = 20; /* Line 127, Address: 0x102365c */
  a2->actflg |= 2; /* Line 128, Address: 0x1023664 */
  a2->cddat |= 2; /* Line 129, Address: 0x1023670 */

  a_init_sub(a1); /* Line 131, Address: 0x102367c */
  a_init_sub(a2); /* Line 132, Address: 0x1023688 */
  ((unsigned short*)a2)[33] = actionwk - actwk; /* Line 133, Address: 0x1023694 */
} /* Line 134, Address: 0x10236c4 */

static void a_init_sub(sprite_status* actionwk) { /* Line 136, Address: 0x10236e0 */
  actionwk->actflg |= 4; /* Line 137, Address: 0x10236e8 */
  actionwk->sproffset = 874; /* Line 138, Address: 0x10236f8 */
  actionwk->sprpri = 3; /* Line 139, Address: 0x1023704 */
  actionwk->patbase = pat_propera1; /* Line 140, Address: 0x1023710 */
  actionwk->sprhs = 32; /* Line 141, Address: 0x1023720 */
  actionwk->sprhsize = 32; /* Line 142, Address: 0x102372c */
  actionwk->sprvsize = 28; /* Line 143, Address: 0x1023738 */
} /* Line 144, Address: 0x1023744 */

static void a_fall(sprite_status* actionwk) { /* Line 146, Address: 0x1023750 */
  short d1;

  ++actionwk->yposi.w.h; /* Line 149, Address: 0x1023760 */
  d1 = emycol_d(actionwk); /* Line 150, Address: 0x1023770 */
  if (d1 < 0) /* Line 151, Address: 0x1023784 */
  {
    actionwk->yposi.w.h += d1; /* Line 153, Address: 0x1023794 */
    actionwk->r_no0 += 2; /* Line 154, Address: 0x10237a4 */
  }
} /* Line 156, Address: 0x10237b4 */

static void a_move(sprite_status* actionwk) { /* Line 158, Address: 0x10237d0 */
  short d1;

  actionwk->xposi.l += ((int*)actionwk)[12]; /* Line 161, Address: 0x10237e0 */
  d1 = emycol_d(actionwk); /* Line 162, Address: 0x10237f8 */
  actionwk->yposi.w.h += d1; /* Line 163, Address: 0x102380c */
  if (--((short*)actionwk)[23] != 0) return; /* Line 164, Address: 0x102381c */
  ((int*)actionwk)[12] = -((int*)actionwk)[12]; /* Line 165, Address: 0x1023844 */

  ((short*)actionwk)[23] = 128; /* Line 167, Address: 0x1023858 */
} /* Line 168, Address: 0x1023864 */











static void propera1(sprite_status* actionwk) { /* Line 180, Address: 0x1023880 */
  void(*tbl[9])(sprite_status*) = /* Line 181, Address: 0x1023890 */
  {
    &b_init,
    &b_close,
    &b_close1,
    &b_closed,
    &b_closed1,
    &b_open,
    &b_open1,
    &b_opend,
    &b_opend1
  };
  short ano;

  ano = ((short*)actionwk)[33]; /* Line 195, Address: 0x10238bc */
  if (actwk[ano].actno != 40) /* Line 196, Address: 0x10238cc */
  {
    frameout(actionwk); /* Line 198, Address: 0x1023900 */
    return; /* Line 199, Address: 0x102390c */
  }

  tbl[actionwk->r_no0 / 2](actionwk); /* Line 202, Address: 0x1023914 */
  actionwk->xposi.w.h = actwk[ano].xposi.w.h; /* Line 203, Address: 0x1023950 */
  actionwk->yposi.w.h = actwk[ano].yposi.w.h; /* Line 204, Address: 0x102397c */
  actionwk->yposi.w.h += ((short*)actionwk)[32]; /* Line 205, Address: 0x10239a8 */
  actionsub(actionwk); /* Line 206, Address: 0x10239c0 */
} /* Line 207, Address: 0x10239cc */

static void b_init(sprite_status* actionwk) { /* Line 209, Address: 0x10239e0 */
  if (actionwk->userflag.b.h < 0) /* Line 210, Address: 0x10239ec */
  {
    actionwk->r_no0 = 10; /* Line 212, Address: 0x1023a04 */
    b_open(actionwk); /* Line 213, Address: 0x1023a10 */
  } /* Line 214, Address: 0x1023a1c */
  else
  {
    actionwk->r_no0 = 2; /* Line 217, Address: 0x1023a24 */
    b_close(actionwk); /* Line 218, Address: 0x1023a30 */
  }
} /* Line 220, Address: 0x1023a3c */

static void b_close(sprite_status* actionwk) { /* Line 222, Address: 0x1023a50 */
  actionwk->patno = 6; /* Line 223, Address: 0x1023a5c */
  ((short*)actionwk)[23] = 5; /* Line 224, Address: 0x1023a68 */
  actionwk->colino = 0; /* Line 225, Address: 0x1023a74 */
  actionwk->r_no0 += 2; /* Line 226, Address: 0x1023a7c */
  b_close1(actionwk); /* Line 227, Address: 0x1023a8c */
} /* Line 228, Address: 0x1023a98 */

static void b_close1(sprite_status* actionwk) { /* Line 230, Address: 0x1023ab0 */
  if (--((short*)actionwk)[23] != 0) return; /* Line 231, Address: 0x1023abc */
  actionwk->r_no0 += 2; /* Line 232, Address: 0x1023ae4 */
  b_closed(actionwk); /* Line 233, Address: 0x1023af4 */
} /* Line 234, Address: 0x1023b00 */

static void b_closed(sprite_status* actionwk) { /* Line 236, Address: 0x1023b10 */
  actionwk->patno = 7; /* Line 237, Address: 0x1023b1c */
  ((short*)actionwk)[23] = 73; /* Line 238, Address: 0x1023b28 */
  actionwk->r_no0 += 2; /* Line 239, Address: 0x1023b34 */
  b_closed1(actionwk); /* Line 240, Address: 0x1023b44 */
} /* Line 241, Address: 0x1023b50 */

static void b_closed1(sprite_status* actionwk) { /* Line 243, Address: 0x1023b60 */
  if (--((short*)actionwk)[23] != 0) return; /* Line 244, Address: 0x1023b6c */
  actionwk->r_no0 += 2; /* Line 245, Address: 0x1023b94 */
  b_open(actionwk); /* Line 246, Address: 0x1023ba4 */
} /* Line 247, Address: 0x1023bb0 */

static void b_open(sprite_status* actionwk) { /* Line 249, Address: 0x1023bc0 */
  actionwk->patno = 6; /* Line 250, Address: 0x1023bc8 */
  ((short*)actionwk)[23] = 5; /* Line 251, Address: 0x1023bd4 */
  actionwk->r_no0 += 2; /* Line 252, Address: 0x1023be0 */

} /* Line 254, Address: 0x1023bf0 */

static void b_open1(sprite_status* actionwk) { /* Line 256, Address: 0x1023c00 */
  if (--((short*)actionwk)[23] != 0) return; /* Line 257, Address: 0x1023c0c */
  actionwk->r_no0 += 2; /* Line 258, Address: 0x1023c34 */
  b_opend(actionwk); /* Line 259, Address: 0x1023c44 */
} /* Line 260, Address: 0x1023c50 */

static void b_opend(sprite_status* actionwk) { /* Line 262, Address: 0x1023c60 */
  actionwk->mstno.w = 255; /* Line 263, Address: 0x1023c68 */
  ((short*)actionwk)[23] = 73; /* Line 264, Address: 0x1023c74 */
  actionwk->colino = 168; /* Line 265, Address: 0x1023c80 */
  actionwk->colicnt = 0; /* Line 266, Address: 0x1023c8c */
  actionwk->r_no0 += 2; /* Line 267, Address: 0x1023c94 */

} /* Line 269, Address: 0x1023ca4 */

static void b_opend1(sprite_status* actionwk) { /* Line 271, Address: 0x1023cb0 */
  if (--((short*)actionwk)[23] != 0) /* Line 272, Address: 0x1023cbc */
  {
    patchg(actionwk, (unsigned char**)pchg1); /* Line 274, Address: 0x1023ce4 */
    return; /* Line 275, Address: 0x1023cf8 */
  }
  actionwk->r_no0 -= 14; /* Line 277, Address: 0x1023d00 */
  b_close(actionwk); /* Line 278, Address: 0x1023d10 */
} /* Line 279, Address: 0x1023d1c */
