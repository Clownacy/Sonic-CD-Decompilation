#include "..\EQU.H"
#include "FUNSUI4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"
#include "PLAYSUB4.H"

static void funsui4_init(sprite_status* pActwk);
static void funsui4_move(sprite_status* pActwk);
static void sibuki_set(sprite_status* pActwk);
static void sibuki_init(sprite_status* pActwk);
static void sibuki_move(sprite_status* pActwk);

unsigned char pchg0[7] = { 0, 0, 1, 2, 3, 4, 255 };
unsigned char pchg1[6] = { 0, 5, 6, 7, 8, 255 };
unsigned char* funsui4pchg[2] =
{
  pchg0,
  pchg1
};
static sprite_pattern pat0 =
{
  2,
  { {
    { -56, -80, 0, 498 },
    { -32, -64, 0, 503 }
  } }
};
static sprite_pattern pat1 =
{
  2,
  { {
    { -56, -80, 0, 499 },
    { -32, -64, 0, 504 }
  } }
};
static sprite_pattern pat2 =
{
  2,
  { {
    { -56, -80, 0, 500 },
    { -32, -64, 0, 505 }
  } }
};
static sprite_pattern pat3 =
{
  2,
  { {
    { -56, -80, 0, 501 },
    { -32, -64, 0, 506 }
  } }
};
static sprite_pattern pat4 =
{
  2,
  { {
    { -56, -80, 0, 502 },
    { -32, -64, 0, 507 }
  } }
};
static sprite_pattern pat5 =
{
  1,
  { { -16, -16, 0, 508 } }
};
static sprite_pattern pat6 =
{
  1,
  { { -16, -16, 0, 509 } }
};
static sprite_pattern pat7 =
{
  1,
  { { -16, -16, 0, 510 } }
};
static sprite_pattern pat8 =
{
  1,
  { { -16, -16, 0, 511 } }
};
sprite_pattern* funsui4pat[9] =
{
  &pat0,
  &pat1,
  &pat2,
  &pat3,
  &pat4,
  &pat5,
  &pat6,
  &pat7,
  &pat8
};


















































void funsui4(sprite_status* pActwk) { /* Line 143, Address: 0x10263c0 */
  void(*tbl[3])(sprite_status*) = /* Line 144, Address: 0x10263cc */
  {
    &funsui4_init,
    &funsui4_move,
    &sibuki_move
  };

  if (pActwk->userflag.b.h == -1) /* Line 151, Address: 0x10263f0 */
  {
    sibuki(pActwk); /* Line 153, Address: 0x102640c */
  } /* Line 154, Address: 0x1026418 */
  else
  {
    tbl[pActwk->r_no0 / 2](pActwk); /* Line 157, Address: 0x1026420 */
    actionsub(pActwk); /* Line 158, Address: 0x102645c */
    frameout_s(pActwk); /* Line 159, Address: 0x1026468 */
  }
} /* Line 161, Address: 0x1026474 */




static void funsui4_init(sprite_status* pActwk) { /* Line 166, Address: 0x1026490 */
  lpcolorwk[55].peRed = 96; /* Line 167, Address: 0x102649c */
  lpcolorwk[55].peGreen = 64; /* Line 168, Address: 0x10264ac */
  lpcolorwk[55].peBlue = 96; /* Line 169, Address: 0x10264bc */
  lpcolorwk[55].peFlags = 1; /* Line 170, Address: 0x10264cc */

  lpcolorwk[56].peRed = 160; /* Line 172, Address: 0x10264dc */
  lpcolorwk[56].peGreen = 128; /* Line 173, Address: 0x10264ec */
  lpcolorwk[56].peBlue = 160; /* Line 174, Address: 0x10264fc */
  lpcolorwk[56].peFlags = 1; /* Line 175, Address: 0x102650c */

  lpcolorwk[57].peRed = 224; /* Line 177, Address: 0x102651c */
  lpcolorwk[57].peGreen = 224; /* Line 178, Address: 0x102652c */
  lpcolorwk[57].peBlue = 224; /* Line 179, Address: 0x102653c */
  lpcolorwk[57].peFlags = 1; /* Line 180, Address: 0x102654c */

  pActwk->r_no0 += 2; /* Line 182, Address: 0x102655c */
  pActwk->actflg |= 4; /* Line 183, Address: 0x102656c */
  pActwk->sproffset = 25344; /* Line 184, Address: 0x102657c */
  pActwk->sprpri = 1; /* Line 185, Address: 0x1026588 */
  pActwk->patbase = funsui4pat; /* Line 186, Address: 0x1026594 */
  pActwk->sprhsize = 32; /* Line 187, Address: 0x10265a4 */
  pActwk->sprvsize = 60; /* Line 188, Address: 0x10265b0 */

  funsui4_move(pActwk); /* Line 190, Address: 0x10265bc */
} /* Line 191, Address: 0x10265c8 */




static void funsui4_move(sprite_status* pActwk) { /* Line 196, Address: 0x10265e0 */
  sibuki_set(pActwk); /* Line 197, Address: 0x10265ec */
  patchg(pActwk, funsui4pchg); /* Line 198, Address: 0x10265f8 */
  pActwk->yposi.w.h = waterposi - 48; /* Line 199, Address: 0x102660c */
  ridechk(pActwk, &actwk[0]); /* Line 200, Address: 0x1026630 */
} /* Line 201, Address: 0x1026644 */




static void sibuki_set(sprite_status* pActwk) { /* Line 206, Address: 0x1026660 */
  sprite_status* pNewActwk;
  short* a2;
  unsigned char d0;

  short tbl[32] = /* Line 211, Address: 0x1026674 */
  {
    -40, -72, -32, -128,
      8, -72,  32, -128,
     40, -72,  64, -128,
     -8, -72, -64, -128,
    -40, -72,   0, -128,
     -8, -72,   0, -128,
      8, -72,   0, -128,
     40, -72,   0, -128
  };


  if ((unsigned short)pActwk->actfree[17] + 16 < 256) /* Line 224, Address: 0x10266a8 */
  {
    pActwk->actfree[17] += 16; /* Line 226, Address: 0x10266c8 */
    return; /* Line 227, Address: 0x10266d8 */
  }
  pActwk->actfree[17] += 16; /* Line 229, Address: 0x10266e0 */

  if (actwkchk(&pNewActwk) == 0) /* Line 231, Address: 0x10266f0 */
  {
    pNewActwk->actno = pActwk->actno; /* Line 233, Address: 0x1026704 */
    pNewActwk->userflag.b.h = -1; /* Line 234, Address: 0x1026714 */
    pNewActwk->patno = 5; /* Line 235, Address: 0x1026720 */
    d0 = pActwk->actfree[16] & 3; /* Line 236, Address: 0x102672c */
    pNewActwk->actfree[16] = d0; /* Line 237, Address: 0x1026744 */
    d0 <<= 3; /* Line 238, Address: 0x102674c */
    a2 = &tbl[d0 / 2]; /* Line 239, Address: 0x1026754 */
    pNewActwk->xposi.w.h = pActwk->xposi.w.h + *a2++; /* Line 240, Address: 0x102677c */
    pNewActwk->yposi.w.h = pActwk->yposi.w.h + *a2++; /* Line 241, Address: 0x10267b4 */
    pNewActwk->xspeed.w = *a2++; /* Line 242, Address: 0x10267ec */
    pNewActwk->yspeed.w = *a2++; /* Line 243, Address: 0x1026800 */

    ++pActwk->actfree[16]; /* Line 245, Address: 0x1026814 */
  }
} /* Line 247, Address: 0x1026824 */




void sibuki(sprite_status* pActwk) { /* Line 252, Address: 0x1026840 */
  if (pActwk->r_no0) sibuki_move(pActwk); /* Line 253, Address: 0x102684c */
  else sibuki_init(pActwk); /* Line 254, Address: 0x1026870 */
} /* Line 255, Address: 0x102687c */




static void sibuki_init(sprite_status* pActwk) { /* Line 260, Address: 0x1026890 */
  pActwk->r_no0 += 2; /* Line 261, Address: 0x102689c */
  pActwk->actflg |= 4; /* Line 262, Address: 0x10268ac */
  pActwk->sproffset = 25344; /* Line 263, Address: 0x10268bc */
  pActwk->sprpri = 3; /* Line 264, Address: 0x10268c8 */
  pActwk->patbase = funsui4pat; /* Line 265, Address: 0x10268d4 */
  pActwk->sprhsize = 16; /* Line 266, Address: 0x10268e4 */
  pActwk->sprvsize = 16; /* Line 267, Address: 0x10268f0 */
  pActwk->mstno.b.h = 1; /* Line 268, Address: 0x10268fc */

  sibuki_move(pActwk); /* Line 270, Address: 0x1026908 */
} /* Line 271, Address: 0x1026914 */




static void sibuki_move(sprite_status* pActwk) { /* Line 276, Address: 0x1026930 */
  int d0;

  if ((unsigned short)pActwk->actfree[17] + 2 > 255) /* Line 279, Address: 0x1026940 */
  {
    pActwk->actfree[17] += 2; /* Line 281, Address: 0x1026960 */
    frameout(pActwk); /* Line 282, Address: 0x1026970 */
    return; /* Line 283, Address: 0x102697c */
  }
  pActwk->actfree[17] += 2; /* Line 285, Address: 0x1026984 */

  d0 = pActwk->xspeed.w; /* Line 287, Address: 0x1026994 */
  d0 <<= 8; /* Line 288, Address: 0x10269a4 */
  pActwk->xposi.l += d0; /* Line 289, Address: 0x10269a8 */
  d0 = pActwk->yspeed.w; /* Line 290, Address: 0x10269b8 */
  d0 <<= 8; /* Line 291, Address: 0x10269c8 */
  pActwk->yposi.l += d0; /* Line 292, Address: 0x10269cc */
  pActwk->yspeed.w += 8; /* Line 293, Address: 0x10269dc */
  patchg(pActwk, funsui4pchg); /* Line 294, Address: 0x10269ec */
  actionsub(pActwk); /* Line 295, Address: 0x1026a00 */
  frameout_s(pActwk); /* Line 296, Address: 0x1026a0c */
} /* Line 297, Address: 0x1026a18 */
