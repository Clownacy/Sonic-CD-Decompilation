#include "..\EQU.H"
#include "TOBIRA4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

static sprite_pattern pat0 = {
  1,
  { { -8, -64, 0, 512 } }
};
static sprite_pattern pat1 = {
  1,
  { { -8, -32, 0, 513 } }
};
static sprite_pattern pat2 = {
  1,
  { { -64, -8, 0, 514 } }
};
sprite_pattern* tobira4pat[3] = {
  &pat0,
  &pat1,
  &pat2
};















































void tobira4(sprite_status* pActwk) { /* Line 71, Address: 0x101cf50 */
  void(*tbl[4])(sprite_status*) = /* Line 72, Address: 0x101cf5c */
  {
    &tobira4_init,
    &tobira4_move,
    &tobira4_chek,
    &tobira4_clse
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 80, Address: 0x101cf88 */
  actionsub(pActwk); /* Line 81, Address: 0x101cfc4 */
  frameout_s(pActwk); /* Line 82, Address: 0x101cfd0 */
} /* Line 83, Address: 0x101cfdc */




void tobira4_init(sprite_status* pActwk) { /* Line 88, Address: 0x101cff0 */
  unsigned char d0, d1;
  unsigned char tbl[20] = /* Line 90, Address: 0x101d000 */
  {
    64,  8, 128, 2,
    64,  8, 128, 2,
     8, 32,  64, 1,
     8, 64, 128, 0,
     8, 64, 128, 0
  };

  pActwk->r_no0 += 2; /* Line 99, Address: 0x101d034 */
  pActwk->actflg |= 4; /* Line 100, Address: 0x101d044 */
  pActwk->sproffset = 17472; /* Line 101, Address: 0x101d054 */
  pActwk->sprpri = 2; /* Line 102, Address: 0x101d060 */
  pActwk->patbase = tobira4pat; /* Line 103, Address: 0x101d06c */
  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 104, Address: 0x101d07c */
  ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 105, Address: 0x101d08c */

  d1 = d0 = pActwk->userflag.b.h; /* Line 107, Address: 0x101d09c */
  d1 &= 15; /* Line 108, Address: 0x101d0ac */
  pActwk->actfree[6] = d1; /* Line 109, Address: 0x101d0b4 */
  d0 >>= 4; /* Line 110, Address: 0x101d0bc */
  d0 &= 15; /* Line 111, Address: 0x101d0c4 */
  pActwk->actfree[7] = d0; /* Line 112, Address: 0x101d0cc */
  d0 <<= 2; /* Line 113, Address: 0x101d0d4 */
  pActwk->sprhsize = tbl[d0]; /* Line 114, Address: 0x101d0dc */
  pActwk->sprvsize = tbl[d0 + 1]; /* Line 115, Address: 0x101d0f0 */
  pActwk->actfree[17] = tbl[d0 + 2]; /* Line 116, Address: 0x101d108 */
  pActwk->patno = tbl[d0 + 3]; /* Line 117, Address: 0x101d120 */
} /* Line 118, Address: 0x101d138 */




void tobira4_move(sprite_status* pActwk) { /* Line 123, Address: 0x101d150 */
  unsigned char d0;

  d0 = pActwk->actfree[6]; /* Line 126, Address: 0x101d160 */
  if (!(switchflag[d0] & 128)) /* Line 127, Address: 0x101d16c */
  {
    pActwk->actfree[18] = 255; /* Line 129, Address: 0x101d190 */
  } /* Line 130, Address: 0x101d19c */
  else
  {
    pActwk->actfree[18] = 0; /* Line 133, Address: 0x101d1a4 */
  }

  if (pActwk->actfree[7] != 4) /* Line 136, Address: 0x101d1ac */
  {
    if (pActwk->actfree[16]) /* Line 138, Address: 0x101d1c4 */
    {
      pActwk->actfree[18] = 0; /* Line 140, Address: 0x101d1d4 */
    }
  }
  ((short*)pActwk)[30] = actwk[0].xposi.w.h; /* Line 143, Address: 0x101d1dc */
  ((short*)pActwk)[33] = actwk[0].yposi.w.h; /* Line 144, Address: 0x101d1ec */
  tobira4_cnt(pActwk); /* Line 145, Address: 0x101d1fc */
  hitchk(pActwk, &actwk[0]); /* Line 146, Address: 0x101d208 */

  if (pActwk->actfree[7] != 4) /* Line 148, Address: 0x101d21c */
  {
    if (pActwk->actfree[16] == pActwk->actfree[17]) /* Line 150, Address: 0x101d234 */
    {
      pActwk->r_no0 += 2; /* Line 152, Address: 0x101d254 */
    }
  }
} /* Line 155, Address: 0x101d264 */




void cl_type1(sprite_status* pActwk) { /* Line 160, Address: 0x101d280 */
  sprite_status* pPlayerwk;
  short d0;

  pPlayerwk = &actwk[0]; /* Line 164, Address: 0x101d290 */
  d0 = pActwk->yposi.w.h; /* Line 165, Address: 0x101d298 */
  if (d0 < ((short*)pActwk)[33]) /* Line 166, Address: 0x101d2a8 */
  {
    d0 = pPlayerwk->sprvsize; /* Line 168, Address: 0x101d2cc */
    d0 += pPlayerwk->yposi.w.h; /* Line 169, Address: 0x101d2dc */
    if (d0 >= pActwk->yposi.w.h) return; /* Line 170, Address: 0x101d2ec */
    d0 -= pActwk->yposi.w.h; /* Line 171, Address: 0x101d310 */
    d0 *= -1; /* Line 172, Address: 0x101d324 */
    if (d0 < 16) return; /* Line 173, Address: 0x101d330 */
  } /* Line 174, Address: 0x101d344 */
  else
  {
    d0 = -pPlayerwk->sprvsize; /* Line 177, Address: 0x101d34c */
    d0 += pPlayerwk->yposi.w.h; /* Line 178, Address: 0x101d368 */
    if (d0 < pPlayerwk->yposi.w.h) return; /* Line 179, Address: 0x101d378 */
    d0 -= pPlayerwk->yposi.w.h; /* Line 180, Address: 0x101d398 */
    if (d0 < 8) return; /* Line 181, Address: 0x101d3a8 */
  }
  pActwk->r_no0 += 2; /* Line 183, Address: 0x101d3bc */
} /* Line 184, Address: 0x101d3cc */




void cl_type2(sprite_status* pActwk) { /* Line 189, Address: 0x101d3e0 */
  sprite_status* pPlayerwk;
  short d0;

  pPlayerwk = &actwk[0]; /* Line 193, Address: 0x101d3f0 */
  d0 = pActwk->xposi.w.h; /* Line 194, Address: 0x101d3f8 */
  if (d0 < ((short*)pActwk)[30]) /* Line 195, Address: 0x101d408 */
  {
    d0 = pPlayerwk->sprhs; /* Line 197, Address: 0x101d42c */
    d0 += pPlayerwk->xposi.w.h; /* Line 198, Address: 0x101d43c */
    if (d0 >= pActwk->xposi.w.h) return; /* Line 199, Address: 0x101d44c */
    d0 -= pActwk->xposi.w.h; /* Line 200, Address: 0x101d470 */
    d0 *= -1; /* Line 201, Address: 0x101d484 */
    if (d0 < 8) return; /* Line 202, Address: 0x101d490 */
  } /* Line 203, Address: 0x101d4a4 */
  else
  {
    d0 = -pPlayerwk->sprhs; /* Line 206, Address: 0x101d4ac */
    d0 += pPlayerwk->xposi.w.h; /* Line 207, Address: 0x101d4c8 */
    if (d0 < pActwk->xposi.w.h) return; /* Line 208, Address: 0x101d4d8 */
    d0 -= pActwk->xposi.w.h; /* Line 209, Address: 0x101d4fc */
    if (d0 < 8) return; /* Line 210, Address: 0x101d510 */
  }
  pActwk->r_no0 += 2; /* Line 212, Address: 0x101d524 */
} /* Line 213, Address: 0x101d534 */




void tobira4_chek(sprite_status* pActwk) { /* Line 218, Address: 0x101d550 */
  void(*tbl[5])(sprite_status*) = /* Line 219, Address: 0x101d55c */
  {
    &cl_type1,
    &cl_type1,
    &cl_type2,
    &cl_type2,
    &cl_type2
  };

  tbl[pActwk->actfree[7]](pActwk); /* Line 228, Address: 0x101d588 */
  hitchk(pActwk, &actwk[0]); /* Line 229, Address: 0x101d5ac */
} /* Line 230, Address: 0x101d5c0 */




void tobira4_clse(sprite_status* pActwk) { /* Line 235, Address: 0x101d5d0 */
  pActwk->actfree[18] = 255; /* Line 236, Address: 0x101d5dc */
  tobira4_cnt(pActwk); /* Line 237, Address: 0x101d5e8 */
  if (pActwk->actfree[16] == 0) /* Line 238, Address: 0x101d5f4 */
  {
    pActwk->r_no0 = 2; /* Line 240, Address: 0x101d608 */
  }
  hitchk(pActwk, &actwk[0]); /* Line 242, Address: 0x101d614 */
} /* Line 243, Address: 0x101d628 */




void type1(sprite_status* pActwk) { /* Line 248, Address: 0x101d640 */
  short d0;

  tobira4_sub(pActwk); /* Line 251, Address: 0x101d650 */
  d0 = (unsigned short)pActwk->actfree[16]; /* Line 252, Address: 0x101d65c */
  d0 *= -1; /* Line 253, Address: 0x101d678 */
  d0 += ((short*)pActwk)[29]; /* Line 254, Address: 0x101d684 */
  pActwk->xposi.w.h = d0; /* Line 255, Address: 0x101d698 */
} /* Line 256, Address: 0x101d6a0 */




void type2(sprite_status* pActwk) { /* Line 261, Address: 0x101d6c0 */
  short d0;

  tobira4_sub(pActwk); /* Line 264, Address: 0x101d6d0 */
  d0 = (unsigned short)pActwk->actfree[16]; /* Line 265, Address: 0x101d6dc */
  d0 += ((short*)pActwk)[29]; /* Line 266, Address: 0x101d6f8 */
  pActwk->xposi.w.h = d0; /* Line 267, Address: 0x101d70c */
} /* Line 268, Address: 0x101d714 */




void type3(sprite_status* pActwk) { /* Line 273, Address: 0x101d730 */
  short d0;

  tobira4_sub(pActwk); /* Line 276, Address: 0x101d740 */
  d0 = (unsigned short)pActwk->actfree[16]; /* Line 277, Address: 0x101d74c */
  d0 *= -1; /* Line 278, Address: 0x101d768 */
  d0 += ((short*)pActwk)[27]; /* Line 279, Address: 0x101d774 */
  pActwk->yposi.w.h = d0; /* Line 280, Address: 0x101d788 */
} /* Line 281, Address: 0x101d790 */




void type4(sprite_status* pActwk) { /* Line 286, Address: 0x101d7b0 */
  short d0;

  tobira4_sub(pActwk); /* Line 289, Address: 0x101d7c0 */
  d0 = (unsigned short)pActwk->actfree[16]; /* Line 290, Address: 0x101d7cc */
  d0 += ((short*)pActwk)[27]; /* Line 291, Address: 0x101d7e8 */
  pActwk->yposi.w.h = d0; /* Line 292, Address: 0x101d7fc */
} /* Line 293, Address: 0x101d804 */




void tobira4_cnt(sprite_status* pActwk) { /* Line 298, Address: 0x101d820 */
  void(*tbl[5])(sprite_status*) = /* Line 299, Address: 0x101d82c */
  {
    &type1,
    &type2,
    &type3,
    &type4,
    &type3
  };

  tbl[pActwk->actfree[7]](pActwk); /* Line 308, Address: 0x101d858 */
} /* Line 309, Address: 0x101d87c */




void tobira4_sub(sprite_status* pActwk) { /* Line 314, Address: 0x101d890 */
  if (pActwk->actfree[18]) /* Line 315, Address: 0x101d898 */
  {
    if (pActwk->actfree[16] >= 8) /* Line 317, Address: 0x101d8a8 */
    {
      pActwk->actfree[16] -= 8; /* Line 319, Address: 0x101d8c0 */
      return; /* Line 320, Address: 0x101d8d0 */
    }
    pActwk->actfree[16] = 0; /* Line 322, Address: 0x101d8d8 */
  } /* Line 323, Address: 0x101d8e0 */
  else
  {
    pActwk->actfree[16] += 8; /* Line 326, Address: 0x101d8e8 */
    if (pActwk->actfree[16] < pActwk->actfree[17]) return; /* Line 327, Address: 0x101d8f8 */



    pActwk->actfree[16] = pActwk->actfree[17]; /* Line 331, Address: 0x101d91c */
  }
} /* Line 333, Address: 0x101d92c */
