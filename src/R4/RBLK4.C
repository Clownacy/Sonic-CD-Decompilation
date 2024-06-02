#include "..\EQU.H"
#include "RBLK4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\FCOL.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"

static void rblk4_init(sprite_status* pActwk);
static void rblk4_wait(sprite_status* pActwk);
static void rblk4_move(sprite_status* pActwk);
static void rblk4_push(sprite_status* pActwk);
static void rblk4_ract_init(sprite_status* pActwk);
static void rblk4_ract_move(sprite_status* pActwk);

static sprite_pattern pat00 =
{
  2,
  {
    { -8, -8, 0, 506 },
    { -48, -48, 0, 507 }
  }
};
static sprite_pattern pat01 =
{
  2,
  {
    { -8, -8, 0, 508 },
    { -48, -16, 0, 509 }
  }
};
static sprite_pattern pat02 =
{
  2,
  {
    { -8, -8, 0, 510 },
    { -16, -16, 0, 511 }
  }
};
static sprite_pattern pat03 =
{
  2,
  {
    { -8, -8, 0, 512 },
    { -16, -48, 0, 513 }
  }
};
static sprite_pattern pat04 =
{
  2,
  {
    { -8, -8, 0, 514 },
    { -48, -48, 0, 515 }
  }
};
static sprite_pattern pat05 =
{
  2,
  {
    { -8, -8, 0, 516 },
    { -48, -24, 0, 517 }
  }
};
static sprite_pattern pat06 =
{
  2,
  {
    { -8, -8, 0, 518 },
    { -24, -48, 0, 519 }
  }
};
static sprite_pattern pat07 =
{
  2,
  {
    { -8, -8, 0, 520 },
    { -48, -48, 0, 521 }
  }
};
static sprite_pattern pat08 =
{
  1,
  { { -32, -32, 0, 522 } }
};
sprite_pattern* rblk4pat[9] =
{
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05,
  &pat06,
  &pat07,
  &pat08
};





















































void rblk4(sprite_status* pActwk) { /* Line 150, Address: 0x10244f0 */
  void(*tbl[4])(sprite_status*) = /* Line 151, Address: 0x10244fc */
  {
    &rblk4_init,
    &rblk4_wait,
    &rblk4_move,
    &rblk4_push
  };

  if (pActwk->actfree[18] == 255) /* Line 159, Address: 0x1024528 */
  {
    rblk4_ract(pActwk); /* Line 161, Address: 0x1024540 */
  } /* Line 162, Address: 0x102454c */
  else
  {
    tbl[pActwk->r_no0 / 2](pActwk); /* Line 165, Address: 0x1024554 */
    actionsub(pActwk); /* Line 166, Address: 0x1024590 */
    frameout_s(pActwk); /* Line 167, Address: 0x102459c */
  }
} /* Line 169, Address: 0x10245a8 */




static void rblk4_init(sprite_status* pActwk) { /* Line 174, Address: 0x10245c0 */
  sprite_status* pNewActwk;

  pActwk->r_no0 += 2; /* Line 177, Address: 0x10245cc */
  pActwk->actflg |= 4; /* Line 178, Address: 0x10245dc */
  pActwk->sprpri = 3; /* Line 179, Address: 0x10245ec */
  pActwk->patbase = rblk4pat; /* Line 180, Address: 0x10245f8 */
  pActwk->sproffset = 17152; /* Line 181, Address: 0x1024608 */
  pActwk->sprvsize = 64; /* Line 182, Address: 0x1024614 */
  pActwk->sprhsize = 64; /* Line 183, Address: 0x1024620 */

  pActwk->patno = pActwk->userflag.b.h & 3; /* Line 185, Address: 0x102462c */
  pActwk->actfree[19] = pActwk->patno; /* Line 186, Address: 0x102464c */

  if (actwkchk(&pNewActwk) != 0) /* Line 188, Address: 0x102465c */
  {
    frameout_s0(pActwk); /* Line 190, Address: 0x1024670 */
    return; /* Line 191, Address: 0x102467c */
  }
  pNewActwk->actno = 61; /* Line 193, Address: 0x1024684 */
  ((short*)pNewActwk)[29] = pActwk->xposi.w.h; /* Line 194, Address: 0x1024690 */
  ((short*)pNewActwk)[28] = (unsigned short)(pActwk - actwk); /* Line 195, Address: 0x10246a0 */
  pNewActwk->actfree[18] = 255; /* Line 196, Address: 0x10246dc */
  pNewActwk->actfree[19] = 0; /* Line 197, Address: 0x10246e8 */
  ((short*)pActwk)[26] = (unsigned short)(pNewActwk - actwk); /* Line 198, Address: 0x10246f0 */

  if (actwkchk(&pNewActwk) != 0) /* Line 200, Address: 0x102472c */
  {
    frameout_s0(pActwk); /* Line 202, Address: 0x1024740 */
    return; /* Line 203, Address: 0x102474c */
  }
  pNewActwk->actno = 61; /* Line 205, Address: 0x1024754 */
  ((short*)pNewActwk)[29] = pActwk->xposi.w.h; /* Line 206, Address: 0x1024760 */
  ((short*)pNewActwk)[28] = (unsigned short)(pActwk - actwk); /* Line 207, Address: 0x1024770 */
  pNewActwk->actfree[18] = 255; /* Line 208, Address: 0x10247ac */
  pNewActwk->actfree[19] = 1; /* Line 209, Address: 0x10247b8 */
  ((short*)pActwk)[28] = (unsigned short)(pNewActwk - actwk); /* Line 210, Address: 0x10247c4 */
} /* Line 211, Address: 0x1024800 */




static void rblk4_wait(sprite_status* pActwk) { /* Line 216, Address: 0x1024810 */
  sprite_status* pActwk_y;
  sprite_status* pPlayerwk;
  char* a4;
  short d0;
  short d1;
  unsigned char d3;

  pActwk_y = &actwk[((short*)pActwk)[26]]; /* Line 224, Address: 0x1024834 */
  if (!(pActwk_y->actfree[20] & 128)) return; /* Line 225, Address: 0x102485c */

  pPlayerwk = &actwk[0]; /* Line 227, Address: 0x1024870 */
  if (pActwk->actfree[19] < 2) /* Line 228, Address: 0x1024878 */
  {
    d0 = pActwk->xposi.w.h; /* Line 230, Address: 0x1024890 */
    d1 = pPlayerwk->xposi.w.h + (short)(pPlayerwk->sprhsize + 2); /* Line 231, Address: 0x10248a0 */
  } /* Line 232, Address: 0x10248dc */
  else
  {
    d1 = pActwk->xposi.w.h; /* Line 235, Address: 0x10248e4 */
    d0 = pPlayerwk->xposi.w.h + (short)-((char)pPlayerwk->sprhsize + 2); /* Line 236, Address: 0x10248f4 */
  }
  if (d0 < d1) return; /* Line 238, Address: 0x1024940 */
  d0 -= d1; /* Line 239, Address: 0x102495c */


  a4 = dirstk; /* Line 242, Address: 0x1024968 */
  *a4 = 0; /* Line 243, Address: 0x1024970 */
  scdchk(pActwk, pActwk->yposi.w.h + d0, pActwk->xposi.w.h, 16, 0, 13, a4); /* Line 244, Address: 0x1024974 */

  d3 = dirstk[0]; /* Line 246, Address: 0x10249bc */
  if (d3 & 1) d3 = 0; /* Line 247, Address: 0x10249c8 */

  if (d1 >= 0) /* Line 249, Address: 0x10249dc */
  {
    if (d1 >= 16) /* Line 251, Address: 0x10249ec */
    {
      pActwk->r_no0 += 2; /* Line 253, Address: 0x1024a00 */
      pActwk->actfree[16] = 16; /* Line 254, Address: 0x1024a10 */
      pActwk->actfree[17] = 0; /* Line 255, Address: 0x1024a1c */
      return; /* Line 256, Address: 0x1024a24 */
    }
  }
  pPlayerwk = &actwk[((short*)pActwk)[28]]; /* Line 259, Address: 0x1024a2c */
  if (pPlayerwk->actfree[20]) /* Line 260, Address: 0x1024a54 */
  {
    pActwk->r_no0 = 6; /* Line 262, Address: 0x1024a60 */
    pActwk->actfree[16] = 16; /* Line 263, Address: 0x1024a6c */
    pActwk->actfree[17] = 0; /* Line 264, Address: 0x1024a78 */
  }
} /* Line 266, Address: 0x1024a80 */




static void rblk4_move(sprite_status* pActwk) { /* Line 271, Address: 0x1024ab0 */
  unsigned char d0;
  unsigned char rkpchg0[16] = /* Line 273, Address: 0x1024ac0 */
  {
    0, 4, 1, 255,
    1, 5, 2, 255,
    2, 5, 1, 255,
    3, 6, 2, 255
  };

  d0 = pActwk->actfree[19]; /* Line 281, Address: 0x1024af4 */
  d0 *= 4; /* Line 282, Address: 0x1024b00 */
  d0 = d0 + pActwk->actfree[17]; /* Line 283, Address: 0x1024b10 */
  d0 = rkpchg0[d0]; /* Line 284, Address: 0x1024b2c */
  if (d0 & 128) /* Line 285, Address: 0x1024b3c */
  {
    pActwk->actfree[19] = pActwk->patno; /* Line 287, Address: 0x1024b4c */
    pActwk->r_no0 -= 2; /* Line 288, Address: 0x1024b5c */
    return; /* Line 289, Address: 0x1024b6c */
  }
  pActwk->patno = d0; /* Line 291, Address: 0x1024b74 */
  --pActwk->actfree[16]; /* Line 292, Address: 0x1024b7c */
  if (pActwk->actfree[16]) return; /* Line 293, Address: 0x1024b8c */



  soundset(191); /* Line 297, Address: 0x1024b9c */
  pActwk->actfree[16] = 4; /* Line 298, Address: 0x1024ba8 */
  ++pActwk->actfree[17]; /* Line 299, Address: 0x1024bb4 */
} /* Line 300, Address: 0x1024bc4 */




static void rblk4_push(sprite_status* pActwk) { /* Line 305, Address: 0x1024be0 */
  sprite_status* pPlayerwk;
  short sd0, sd1;
  unsigned char d0;
  unsigned char pspchg0[16] = /* Line 309, Address: 0x1024bf8 */
  {
    0, 7, 3, 255,
    1, 4, 2, 255,
    2, 4, 1, 255,
    3, 7, 0, 255
  };

  d0 = pActwk->actfree[19]; /* Line 317, Address: 0x1024c2c */
  d0 *= 4; /* Line 318, Address: 0x1024c38 */
  d0 = d0 + pActwk->actfree[17]; /* Line 319, Address: 0x1024c48 */
  d0 = pspchg0[d0]; /* Line 320, Address: 0x1024c64 */
  if (d0 & 128) /* Line 321, Address: 0x1024c74 */
  {
    pActwk->actfree[19] = pActwk->patno; /* Line 323, Address: 0x1024c84 */
    pActwk->r_no0 = 2; /* Line 324, Address: 0x1024c94 */
    return; /* Line 325, Address: 0x1024ca0 */
  }
  pActwk->patno = d0; /* Line 327, Address: 0x1024ca8 */

  pPlayerwk = &actwk[0]; /* Line 329, Address: 0x1024cb0 */
  sd0 = pActwk->yposi.w.h; /* Line 330, Address: 0x1024cb8 */
  sd1 = pActwk->sprvsize; /* Line 331, Address: 0x1024cc8 */
  sd0 -= sd1; /* Line 332, Address: 0x1024cdc */
  sd1 = pPlayerwk->sprvsize; /* Line 333, Address: 0x1024ce8 */
  sd0 -= sd1; /* Line 334, Address: 0x1024cf8 */
  pPlayerwk->yposi.w.h = sd0; /* Line 335, Address: 0x1024d04 */

  --pActwk->actfree[16]; /* Line 337, Address: 0x1024d08 */
  if (pActwk->actfree[16]) return; /* Line 338, Address: 0x1024d18 */




  pActwk->actfree[16] = 8; /* Line 343, Address: 0x1024d28 */
  ++pActwk->actfree[17]; /* Line 344, Address: 0x1024d34 */
  if (pActwk->actfree[17] == 1) /* Line 345, Address: 0x1024d44 */
  {
    pPlayerwk->xposi.w.h = pActwk->xposi.w.h; /* Line 347, Address: 0x1024d5c */
    return; /* Line 348, Address: 0x1024d68 */
  }
  if (pActwk->actfree[17] == 2) /* Line 350, Address: 0x1024d70 */
  {
    sd0 = 16; /* Line 352, Address: 0x1024d88 */
    if (pActwk->actfree[19] & 2) /* Line 353, Address: 0x1024d94 */
    {
      sd0 *= -1; /* Line 355, Address: 0x1024dac */
    }
    sd0 += pActwk->xposi.w.h; /* Line 357, Address: 0x1024db8 */
    pPlayerwk->xposi.w.h = sd0; /* Line 358, Address: 0x1024dcc */
  }
} /* Line 360, Address: 0x1024dd0 */




void rblk4_ract(sprite_status* pActwk) { /* Line 365, Address: 0x1024df0 */
  void(*tbl[2])(sprite_status*) = /* Line 366, Address: 0x1024dfc */
  {
    &rblk4_ract_init,
    &rblk4_ract_move
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 372, Address: 0x1024e18 */
  actionsub(pActwk); /* Line 373, Address: 0x1024e54 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 374, Address: 0x1024e60 */
} /* Line 375, Address: 0x1024e74 */




static void rblk4_ract_init(sprite_status* pActwk) { /* Line 380, Address: 0x1024e90 */
  unsigned char d0, d1;

  pActwk->r_no0 += 2; /* Line 383, Address: 0x1024ea4 */
  pActwk->actflg |= 4; /* Line 384, Address: 0x1024eb4 */
  pActwk->sprpri = 3; /* Line 385, Address: 0x1024ec4 */
  pActwk->patbase = rblk4pat; /* Line 386, Address: 0x1024ed0 */
  pActwk->sproffset = 17152; /* Line 387, Address: 0x1024ee0 */
  pActwk->patno = 8; /* Line 388, Address: 0x1024eec */

  d0 = 32; /* Line 390, Address: 0x1024ef8 */
  d1 = 16; /* Line 391, Address: 0x1024f00 */
  if (pActwk->actfree[19]) /* Line 392, Address: 0x1024f08 */
  {
    d0 = 16; /* Line 394, Address: 0x1024f18 */
    d1 = 16; /* Line 395, Address: 0x1024f20 */
  }
  pActwk->sprhsize = d0; /* Line 397, Address: 0x1024f28 */
  pActwk->sprvsize = d1; /* Line 398, Address: 0x1024f30 */

  rblk4_ract_move(pActwk); /* Line 400, Address: 0x1024f38 */
} /* Line 401, Address: 0x1024f44 */




static void rblk4_ract_move(sprite_status* pActwk) { /* Line 406, Address: 0x1024f60 */
  sprite_status* pRideact;
  char* a2;
  unsigned char d0;
  char xyofset_tbl1[8] = /* Line 410, Address: 0x1024f78 */
  {
    -16, 0,
    -16, 0,
     16, 0,
     16, 0
  };
  char xyofset_tbl2[8] = /* Line 417, Address: 0x1024fac */
  {
    0, -32,
    0,  32,
    0,  32,
    0, -32
  };

  pRideact = &actwk[((short*)pActwk)[28]]; /* Line 425, Address: 0x1024fe0 */
  d0 = pRideact->patno; /* Line 426, Address: 0x1025008 */
  if (d0 >= 4) /* Line 427, Address: 0x1025010 */
  {
    ride_on_clr(pActwk, &actwk[0]); /* Line 429, Address: 0x1025020 */
    return; /* Line 430, Address: 0x1025034 */
  }
  d0 = d0 + d0; /* Line 432, Address: 0x102503c */
  a2 = &xyofset_tbl1[d0]; /* Line 433, Address: 0x1025050 */
  if (pActwk->actfree[19]) /* Line 434, Address: 0x102505c */
  {
    a2 = &xyofset_tbl2[d0]; /* Line 436, Address: 0x102506c */
  }
  pActwk->xposi.w.h = pRideact->xposi.w.h + (short)*a2++; /* Line 438, Address: 0x1025078 */
  pActwk->yposi.w.h = pRideact->yposi.w.h + (short)*a2++; /* Line 439, Address: 0x10250b4 */

  hitchk(pActwk, &actwk[0]); /* Line 441, Address: 0x10250f0 */
  if (pActwk->actfree[19] == 0) /* Line 442, Address: 0x1025104 */
  {
    if (pActwk->cddat & 8) pActwk->actfree[20] = 255; /* Line 444, Address: 0x1025118 */
    else pActwk->actfree[20] = 0; /* Line 445, Address: 0x1025144 */
  } /* Line 446, Address: 0x102514c */
  else
  {
    if (!(pActwk->cddat & 32)) /* Line 449, Address: 0x1025154 */
    {
      pActwk->actfree[20] = 0; /* Line 451, Address: 0x102516c */
      pActwk->actfree[21] = 0; /* Line 452, Address: 0x1025174 */
      return; /* Line 453, Address: 0x102517c */
    }
    if (pActwk->actfree[21] == 0) /* Line 455, Address: 0x1025184 */
    {
      pActwk->actfree[20] = 255; /* Line 457, Address: 0x1025198 */
      pActwk->actfree[21] = 255; /* Line 458, Address: 0x10251a4 */
      pActwk->cddat &= 223; /* Line 459, Address: 0x10251b0 */
    }
  }
} /* Line 462, Address: 0x10251c0 */
