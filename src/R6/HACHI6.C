#include "..\EQU.H"
#include "HACHI6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static void act_init(sprite_status* actionwk);
static void act_move(sprite_status* actionwk);
static short act_check(sprite_status* actionwk, sprite_status* pw);

static sprite_pattern pat00 =
{
  1,
  { { -24, -19, 0, 441 } }
};
static sprite_pattern pat01 =
{
  1,
  { { -24, -15, 0, 442 } }
};
static sprite_pattern pat02 =
{
  1,
  { { -16, -23, 0, 443 } }
};
static sprite_pattern pat03 =
{
  1,
  { { -16, -19, 0, 444 } }
};
static sprite_pattern pat04 =
{
  1,
  { { -24, -19, 0, 445 } }
};
static sprite_pattern pat05 =
{
  1,
  { { -24, -15, 0, 446 } }
};
static sprite_pattern pat06 =
{
  1,
  { { -8, -8, 0, 447 } }
};
static sprite_pattern pat07 =
{
  1,
  { { -8, -8, 0, 448 } }
};
static sprite_pattern pat08 =
{
  1,
  { { -8, -8, 0, 449 } }
};
static sprite_pattern pat09 =
{
  1,
  { { -8, -8, 0, 450 } }
};
sprite_pattern* pat_hachi6_e[4] =
{
  &pat00,
  &pat01,
  &pat02,
  &pat03
};
sprite_pattern* pat_hachi6_b[2] =
{
  &pat04,
  &pat05
};
sprite_pattern* pat_tama[4] =
{
  &pat06,
  &pat07,
  &pat08,
  &pat09
};
static char pchg00[4] = { 1, 0, 1, -1 };
static char pchg01[4] = { 1, 2, 3, -1 };
static char* pchg[2] =
{
  pchg00,
  pchg01
};
char pchg_tama0[4] = { 1, 2, 3, -1 };
char* pchg_tama[1] = { pchg_tama0 };













void hachi6(sprite_status* actionwk) { /* Line 104, Address: 0x101bfe0 */
  void(*act_tbl[10])(sprite_status*) = /* Line 105, Address: 0x101bfec */
  {
    act_init,
    act_move,
    act_move1,
    act_rev,
    act_rev1,
    act_rev2,
    act_shot,
    act_shot1,
    act_shot2,
    act_shot3
  };

  if (actionwk->userflag.b.h < 0) /* Line 119, Address: 0x101c020 */
  {
    tama(actionwk); /* Line 121, Address: 0x101c038 */
    return; /* Line 122, Address: 0x101c044 */
  }
  if (enemy_suicide(actionwk) == -1) return; /* Line 124, Address: 0x101c04c */
  act_tbl[actionwk->r_no0 / 2](actionwk); /* Line 125, Address: 0x101c06c */
  patchg(actionwk, (unsigned char**)pchg); /* Line 126, Address: 0x101c0a8 */
  actionsub(actionwk); /* Line 127, Address: 0x101c0bc */
  frameout_s(actionwk); /* Line 128, Address: 0x101c0c8 */
} /* Line 129, Address: 0x101c0d4 */

static void act_init(sprite_status* actionwk) { /* Line 131, Address: 0x101c0f0 */
  actionwk->r_no0 += 2; /* Line 132, Address: 0x101c0fc */
  actionwk->actflg |= 4; /* Line 133, Address: 0x101c10c */
  actionwk->sprpri = 1; /* Line 134, Address: 0x101c11c */
  actionwk->sprhs = 24; /* Line 135, Address: 0x101c128 */
  actionwk->sprhsize = 24; /* Line 136, Address: 0x101c134 */
  actionwk->sprvsize = 12; /* Line 137, Address: 0x101c140 */
  actionwk->sproffset = 42071; /* Line 138, Address: 0x101c14c */
  actionwk->colino = 49; /* Line 139, Address: 0x101c158 */
  ((short*)actionwk)[26] = -8; /* Line 140, Address: 0x101c164 */

  if (actionwk->userflag.b.h == 0) /* Line 142, Address: 0x101c170 */
  {
    actionwk->patbase = pat_hachi6_e; /* Line 144, Address: 0x101c188 */
    ((int*)actionwk)[12] = -65536; /* Line 145, Address: 0x101c198 */
  } /* Line 146, Address: 0x101c1a4 */
  else
  {
    actionwk->patbase = pat_hachi6_b; /* Line 149, Address: 0x101c1ac */
    ((int*)actionwk)[12] = -32768; /* Line 150, Address: 0x101c1bc */
  }

  act_move(actionwk); /* Line 153, Address: 0x101c1c8 */
} /* Line 154, Address: 0x101c1d4 */

static void act_move(sprite_status* actionwk) { /* Line 156, Address: 0x101c1f0 */
  actionwk->r_no0 += 2; /* Line 157, Address: 0x101c1f8 */
  if (actionwk->userflag.b.h == 0) /* Line 158, Address: 0x101c208 */
    ((short*)actionwk)[23] = 512; /* Line 159, Address: 0x101c220 */
  else
    ((short*)actionwk)[23] = 1024; /* Line 161, Address: 0x101c234 */
} /* Line 162, Address: 0x101c240 */

void act_move1(sprite_status* actionwk) { /* Line 164, Address: 0x101c250 */
  actionwk->xposi.l += ((int*)actionwk)[12]; /* Line 165, Address: 0x101c25c */
  if (actionwk->userflag.b.h == 0) /* Line 166, Address: 0x101c274 */
  {
    if (((short*)actionwk)[27] != 0) /* Line 168, Address: 0x101c28c */
    {
      --((short*)actionwk)[27]; /* Line 170, Address: 0x101c2a4 */
    } /* Line 171, Address: 0x101c2b4 */
    else
    {

      if (act_check(actionwk, &actwk[0])) /* Line 175, Address: 0x101c2bc */
      {
        actionwk->r_no0 = 12; /* Line 177, Address: 0x101c2d8 */
        return; /* Line 178, Address: 0x101c2e4 */
      }
    }
  }

  if (--((short*)actionwk)[23] == 0) /* Line 183, Address: 0x101c2ec */
    actionwk->r_no0 = 6; /* Line 184, Address: 0x101c314 */

} /* Line 186, Address: 0x101c320 */

static short act_check(sprite_status* actionwk, sprite_status* pw) { /* Line 188, Address: 0x101c330 */
  char d1;
  char d2;
  short d0w;

  d0w = pw->yposi.w.h; /* Line 193, Address: 0x101c348 */
  d0w -= actionwk->yposi.w.h; /* Line 194, Address: 0x101c358 */
  if (d0w < -96 || d0w > 96) return 0; /* Line 195, Address: 0x101c36c */
  if ((short)(pw->xposi.w.h - actionwk->xposi.w.h) >= 0) d1 = -1; /* Line 196, Address: 0x101c3a0 */
  else d1 = 0; /* Line 197, Address: 0x101c3f0 */


  d0w = pw->xposi.w.h; /* Line 200, Address: 0x101c3f4 */
  d0w -= actionwk->xposi.w.h; /* Line 201, Address: 0x101c404 */
  if (d0w < -120 || d0w > 120) return 0; /* Line 202, Address: 0x101c418 */
  if (actionwk->actflg & 1) d2 = -1; /* Line 203, Address: 0x101c44c */
  else d2 = 0; /* Line 204, Address: 0x101c478 */
  d2 ^= d1; /* Line 205, Address: 0x101c47c */
  if (d2 != 0) /* Line 206, Address: 0x101c488 */
  {
    ((int*)actionwk)[12] = -((int*)actionwk)[12]; /* Line 208, Address: 0x101c498 */
    ((short*)actionwk)[26] = -((short*)actionwk)[26]; /* Line 209, Address: 0x101c4ac */
    actionwk->actflg ^= 1; /* Line 210, Address: 0x101c4d0 */
    actionwk->cddat ^= 1; /* Line 211, Address: 0x101c4e0 */
  }
  return -1; /* Line 213, Address: 0x101c4f0 */
} /* Line 214, Address: 0x101c4f4 */

void act_rev(sprite_status* actionwk) { /* Line 216, Address: 0x101c510 */
  actionwk->r_no0 += 2; /* Line 217, Address: 0x101c518 */
  ((short*)actionwk)[23] = 30; /* Line 218, Address: 0x101c528 */
} /* Line 219, Address: 0x101c534 */

void act_rev1(sprite_status* actionwk) { /* Line 221, Address: 0x101c540 */
  if (--((short*)actionwk)[23] >= 0) return; /* Line 222, Address: 0x101c548 */
  actionwk->r_no0 += 2; /* Line 223, Address: 0x101c570 */
  ((short*)actionwk)[23] = 30; /* Line 224, Address: 0x101c580 */
  ((int*)actionwk)[12] = -((int*)actionwk)[12]; /* Line 225, Address: 0x101c58c */
  ((short*)actionwk)[26] = -((short*)actionwk)[26]; /* Line 226, Address: 0x101c5a0 */
  actionwk->actflg ^= 1; /* Line 227, Address: 0x101c5c4 */
  actionwk->cddat ^= 1; /* Line 228, Address: 0x101c5d4 */
} /* Line 229, Address: 0x101c5e4 */

void act_rev2(sprite_status* actionwk) { /* Line 231, Address: 0x101c5f0 */
  if (--((short*)actionwk)[23] >= 0) return; /* Line 232, Address: 0x101c5f8 */
  actionwk->r_no0 = 2; /* Line 233, Address: 0x101c620 */
} /* Line 234, Address: 0x101c62c */

void act_shot(sprite_status* actionwk) { /* Line 236, Address: 0x101c640 */
  actionwk->r_no0 += 2; /* Line 237, Address: 0x101c64c */
  ((short*)actionwk)[23] = 30; /* Line 238, Address: 0x101c65c */
  act_shot1(actionwk); /* Line 239, Address: 0x101c668 */
} /* Line 240, Address: 0x101c674 */

void act_shot1(sprite_status* actionwk) { /* Line 242, Address: 0x101c690 */
  if (--((short*)actionwk)[23] >= 0) return; /* Line 243, Address: 0x101c698 */
  actionwk->r_no0 += 2; /* Line 244, Address: 0x101c6c0 */
  ((short*)actionwk)[23] = 30; /* Line 245, Address: 0x101c6d0 */
  actionwk->mstno.b.h = 1; /* Line 246, Address: 0x101c6dc */
  actionwk->colino = 50; /* Line 247, Address: 0x101c6e8 */

  actionwk->sprvsize = 16; /* Line 249, Address: 0x101c6f4 */
  actionwk->sprhs = 16; /* Line 250, Address: 0x101c700 */
  actionwk->sprhsize = 16; /* Line 251, Address: 0x101c70c */
  actionwk->xposi.w.h += ((short*)actionwk)[26]; /* Line 252, Address: 0x101c718 */
  actionwk->yposi.w.h += 4; /* Line 253, Address: 0x101c730 */
} /* Line 254, Address: 0x101c740 */

void act_shot2(sprite_status* actionwk) { /* Line 256, Address: 0x101c750 */
  sprite_status* a1;

  if (--((short*)actionwk)[23] >= 0) return; /* Line 259, Address: 0x101c75c */
  actionwk->r_no0 += 2; /* Line 260, Address: 0x101c784 */
  ((short*)actionwk)[23] = 30; /* Line 261, Address: 0x101c794 */
  if (actwkchk(&a1) != 0) return; /* Line 262, Address: 0x101c7a0 */
  a1->actno = actionwk->actno; /* Line 263, Address: 0x101c7b4 */
  a1->userflag.b.h = -1; /* Line 264, Address: 0x101c7c4 */
  a1->actflg = actionwk->actflg; /* Line 265, Address: 0x101c7d0 */
  a1->sproffset = actionwk->sproffset; /* Line 266, Address: 0x101c7e0 */
  a1->patbase = pat_tama; /* Line 267, Address: 0x101c7f0 */
  a1->sprpri = 1; /* Line 268, Address: 0x101c800 */

  a1->sprvsize = 16; /* Line 270, Address: 0x101c80c */
  a1->sprhs = 16; /* Line 271, Address: 0x101c818 */
  a1->sprhsize = 16; /* Line 272, Address: 0x101c824 */
  a1->colino = 179; /* Line 273, Address: 0x101c830 */
  a1->yposi.w.h = actionwk->yposi.w.h + 23; /* Line 274, Address: 0x101c83c */
  ((int*)a1)[13] = 131072; /* Line 275, Address: 0x101c860 */

  a1->xposi.w.h = actionwk->xposi.w.h; /* Line 277, Address: 0x101c86c */
  if (actionwk->actflg & 1) /* Line 278, Address: 0x101c87c */
  {
    a1->xposi.w.h += 7; /* Line 280, Address: 0x101c894 */
    ((int*)a1)[12] = 131072; /* Line 281, Address: 0x101c8a4 */
  } /* Line 282, Address: 0x101c8b0 */
  else
  {
    a1->xposi.w.h -= 7; /* Line 285, Address: 0x101c8b8 */
    ((int*)a1)[12] = -131072; /* Line 286, Address: 0x101c8c8 */
  }
  if ((char)actionwk->actflg < 0) soundset(160); /* Line 288, Address: 0x101c8d4 */
} /* Line 289, Address: 0x101c900 */

void act_shot3(sprite_status* actionwk) { /* Line 291, Address: 0x101c910 */
  if (--((short*)actionwk)[23] >= 0) return; /* Line 292, Address: 0x101c918 */
  actionwk->r_no0 = 2; /* Line 293, Address: 0x101c940 */
  ((short*)actionwk)[27] = 60; /* Line 294, Address: 0x101c94c */
  actionwk->mstno.b.h = 0; /* Line 295, Address: 0x101c958 */
  actionwk->colino = 49; /* Line 296, Address: 0x101c960 */

  actionwk->sprvsize = 12; /* Line 298, Address: 0x101c96c */
  actionwk->sprhs = 24; /* Line 299, Address: 0x101c978 */
  actionwk->sprhsize = 24; /* Line 300, Address: 0x101c984 */
  actionwk->yposi.w.h -= 4; /* Line 301, Address: 0x101c990 */
} /* Line 302, Address: 0x101c9a0 */




void tama(sprite_status* actionwk) { /* Line 307, Address: 0x101c9b0 */
  switch (actionwk->r_no0) { /* Line 308, Address: 0x101c9bc */

    case 0:
      tam_move(actionwk); /* Line 311, Address: 0x101c9fc */
    case 2:
      tam_move1(actionwk); /* Line 313, Address: 0x101ca08 */
      break; /* Line 314, Address: 0x101ca14 */
    case 4:
      tam_move2(actionwk); /* Line 316, Address: 0x101ca1c */
      break; /* Line 317, Address: 0x101ca28 */
    case 6:
      tam_move3(actionwk); /* Line 319, Address: 0x101ca30 */
      break;
  }
  actionsub(actionwk); /* Line 322, Address: 0x101ca3c */
  frameout_s(actionwk); /* Line 323, Address: 0x101ca48 */
} /* Line 324, Address: 0x101ca54 */

void tam_move(sprite_status* actionwk) { /* Line 326, Address: 0x101ca70 */
  actionwk->r_no0 += 2; /* Line 327, Address: 0x101ca78 */
  ((short*)actionwk)[23] = 3; /* Line 328, Address: 0x101ca88 */
} /* Line 329, Address: 0x101ca94 */

void tam_move1(sprite_status* actionwk) { /* Line 331, Address: 0x101caa0 */
  if (--((short*)actionwk)[23] > 0) return; /* Line 332, Address: 0x101caa8 */
  actionwk->r_no0 += 2; /* Line 333, Address: 0x101cad0 */
  actionwk->patno = 1; /* Line 334, Address: 0x101cae0 */
  ((short*)actionwk)[23] = 10; /* Line 335, Address: 0x101caec */
} /* Line 336, Address: 0x101caf8 */

void tam_move2(sprite_status* actionwk) { /* Line 338, Address: 0x101cb10 */
  actionwk->xposi.l += ((int*)actionwk)[12]; /* Line 339, Address: 0x101cb18 */
  actionwk->yposi.l += ((int*)actionwk)[13]; /* Line 340, Address: 0x101cb30 */
  if (--((short*)actionwk)[23] > 0) return; /* Line 341, Address: 0x101cb48 */
  actionwk->r_no0 += 2; /* Line 342, Address: 0x101cb70 */
} /* Line 343, Address: 0x101cb80 */

void tam_move3(sprite_status* actionwk) { /* Line 345, Address: 0x101cb90 */
  if ((char)actionwk->actflg >= 0) /* Line 346, Address: 0x101cb9c */
  {
    frameout(actionwk); /* Line 348, Address: 0x101cbbc */
    return; /* Line 349, Address: 0x101cbc8 */
  }
  actionwk->xposi.l += ((int*)actionwk)[12]; /* Line 351, Address: 0x101cbd0 */
  actionwk->yposi.l += ((int*)actionwk)[13]; /* Line 352, Address: 0x101cbe8 */
  patchg(actionwk, (unsigned char**)pchg_tama); /* Line 353, Address: 0x101cc00 */
} /* Line 354, Address: 0x101cc14 */
