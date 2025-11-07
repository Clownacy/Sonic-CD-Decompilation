#include "..\EQU.H"
#include "EMIE8.H"
#include "..\ACTION.H"
#include "..\IMPFUNCS.H"
#include "..\PLAYSUB.H"

static void emie8_ini(sprite_status* pActwk);
static void emie8_wait(sprite_status* pActwk);
static void emie8_l(sprite_status* pActwk);
static void emie8_j(sprite_status* pActwk);
static void emie8_j2(sprite_status* pActwk);
static void emie8_l2(sprite_status* pActwk);
static void add_spd(sprite_status* pActwk);
static void snc_ctrl(sprite_status* pActwk);
static void emie8_snc_r(sprite_status* pActwk, sprite_status* pPlayerwk);
static void emie8_snc_l(sprite_status* pActwk, sprite_status* pPlayerwk);
static void emie8_snc_w(sprite_status* pActwk, sprite_status* pPlayerwk);
static void emie8_snc_pata(sprite_status* pActwk, sprite_status* pPlayerwk);
static void flash_out8(void);
static void emie8_jisin(sprite_status* pActwk);

static unsigned char pchg0[8] = { 3, 0, 1, 2, 3, 4, 5, 255 };
unsigned char* emie8_pchg[1] = { pchg0 };
static sprite_pattern pat00 = {
  1,
  { { -16, -20, 0, 513 } }
};
static sprite_pattern pat01 = {
  1,
  { { -16, -20, 0, 514 } }
};
static sprite_pattern pat02 = {
  1,
  { { -16, -20, 0, 515 } }
};
static sprite_pattern pat03 = {
  1,
  { { -16, -20, 0, 516 } }
};
static sprite_pattern pat04 = {
  1,
  { { -16, -20, 0, 517 } }
};
static sprite_pattern pat05 = {
  1,
  { { -16, -20, 0, 518 } }
};
static sprite_pattern pat06 = {
  1,
  { { -16, -20, 0, 519 } }
};
static sprite_pattern pat07 = {
  1,
  { { -16, -20, 0, 520 } }
};
sprite_pattern* emie8_pat[8] = {
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05,
  &pat06,
  &pat07
};
static void(*emie8_act_tbl[8])(sprite_status*) = {
  &emie8_ini,
  &emie8_wait,
  &emie8_l,
  &emie8_j,
  &emie8_j2,
  &emie8_j,
  &emie8_j2,
  &emie8_l2
};
static void(*snc_act_tbl[4])(sprite_status*, sprite_status*) = {
  &emie8_snc_r,
  &emie8_snc_l,
  &emie8_snc_w,
  &emie8_snc_pata
};
































































void emie8(sprite_status* pActwk) { /* Line 146, Address: 0x1029820 */
  snc_ctrl(pActwk); /* Line 147, Address: 0x102982c */
  emie8_jisin(pActwk); /* Line 148, Address: 0x1029838 */
  emie8_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 149, Address: 0x1029844 */
  actionsub(pActwk); /* Line 150, Address: 0x1029888 */
} /* Line 151, Address: 0x1029894 */





static void emie8_ini(sprite_status* pActwk) { /* Line 157, Address: 0x10298b0 */
  pActwk->actflg |= 4; /* Line 158, Address: 0x10298bc */
  pActwk->sprpri = 1; /* Line 159, Address: 0x10298cc */
  pActwk->sprhsize = 16; /* Line 160, Address: 0x10298d8 */
  pActwk->sprvsize = 20; /* Line 161, Address: 0x10298e4 */

  pActwk->sproffset = 8736; /* Line 163, Address: 0x10298f0 */
  pActwk->patbase = emie8_pat; /* Line 164, Address: 0x10298fc */
  pActwk->r_no0 += 2; /* Line 165, Address: 0x102990c */
  plautoflag |= 1; /* Line 166, Address: 0x102991c */

  emie8_wait(pActwk); /* Line 168, Address: 0x1029930 */
} /* Line 169, Address: 0x102993c */





static void emie8_wait(sprite_status* pActwk) { /* Line 175, Address: 0x1029950 */
  if (bossstart) return; /* Line 176, Address: 0x102995c */




  pActwk->r_no0 += 2; /* Line 181, Address: 0x102996c */
  pActwk->xspeed.w = 320; /* Line 182, Address: 0x102997c */

  emie8_l(pActwk); /* Line 184, Address: 0x1029988 */
} /* Line 185, Address: 0x1029994 */





static void emie8_l(sprite_status* pActwk) { /* Line 191, Address: 0x10299b0 */
  patchg(pActwk, emie8_pchg); /* Line 192, Address: 0x10299bc */
  add_spd(pActwk); /* Line 193, Address: 0x10299d0 */
  if (pActwk->xposi.w.h < 3744) return; /* Line 194, Address: 0x10299dc */




  pActwk->r_no0 += 2; /* Line 199, Address: 0x10299f8 */
  emie8_j(pActwk); /* Line 200, Address: 0x1029a08 */
} /* Line 201, Address: 0x1029a14 */





static void emie8_j(sprite_status* pActwk) { /* Line 207, Address: 0x1029a30 */
  pActwk->patno = 6; /* Line 208, Address: 0x1029a3c */
  pActwk->xspeed.w = 0; /* Line 209, Address: 0x1029a48 */
  pActwk->yspeed.w = -768; /* Line 210, Address: 0x1029a50 */
  pActwk->r_no0 += 2; /* Line 211, Address: 0x1029a5c */
  emie8_j2(pActwk); /* Line 212, Address: 0x1029a6c */
} /* Line 213, Address: 0x1029a78 */





static void emie8_j2(sprite_status* pActwk) { /* Line 219, Address: 0x1029a90 */
  add_spd(pActwk); /* Line 220, Address: 0x1029a9c */
  if ((pActwk->yspeed.w += 64) >= 0) { /* Line 221, Address: 0x1029aa8 */
    pActwk->patno = 7; /* Line 222, Address: 0x1029ad0 */
  }


  if (pActwk->yposi.w.h < 460) return; /* Line 226, Address: 0x1029adc */




  pActwk->yposi.w.h = 460; /* Line 231, Address: 0x1029af8 */
  pActwk->xspeed.w = 320; /* Line 232, Address: 0x1029b04 */
  pActwk->yspeed.w = 0; /* Line 233, Address: 0x1029b10 */
  pActwk->r_no0 += 2; /* Line 234, Address: 0x1029b18 */
  pActwk->mstno.w = 1; /* Line 235, Address: 0x1029b28 */
} /* Line 236, Address: 0x1029b34 */





static void emie8_l2(sprite_status* pActwk) { /* Line 242, Address: 0x1029b50 */
  sMemSet(clchgtim, 127, sizeof(clchgtim)); /* Line 243, Address: 0x1029b5c */

  add_spd(pActwk); /* Line 245, Address: 0x1029b7c */

  if (pActwk->xposi.w.h >= 3808) { /* Line 247, Address: 0x1029b88 */
    if (++pActwk->actfree[0] >= 8) { /* Line 248, Address: 0x1029ba4 */
      pActwk->actfree[0] = 0; /* Line 249, Address: 0x1029bc8 */

      if (++pActwk->actfree[1] >= 8) { /* Line 251, Address: 0x1029bd0 */

        time_flag |= 128; /* Line 253, Address: 0x1029bf4 */
        gameflag.w = 2; /* Line 254, Address: 0x1029c08 */
        stageno.w = 1792; /* Line 255, Address: 0x1029c14 */
        return; /* Line 256, Address: 0x1029c20 */
      }

      flash_out8(); /* Line 259, Address: 0x1029c28 */
    }
  }


  patchg(pActwk, emie8_pchg); /* Line 264, Address: 0x1029c30 */
} /* Line 265, Address: 0x1029c44 */
















static void add_spd(sprite_status* pActwk) { /* Line 282, Address: 0x1029c60 */
  pActwk->xposi.l += pActwk->xspeed.w << 8; /* Line 283, Address: 0x1029c68 */
  pActwk->yposi.l += pActwk->yspeed.w << 8; /* Line 284, Address: 0x1029c8c */
} /* Line 285, Address: 0x1029cb0 */





















static void snc_ctrl(sprite_status* pActwk) { /* Line 307, Address: 0x1029cc0 */
  snc_act_tbl[pActwk->actfree[3] / 2](pActwk, &actwk[0]); /* Line 308, Address: 0x1029ccc */
} /* Line 309, Address: 0x1029d18 */





static void emie8_snc_r(sprite_status* pActwk, sprite_status* pPlayerwk) { /* Line 315, Address: 0x1029d30 */
  swdata.w = 2056; /* Line 316, Address: 0x1029d40 */
  if (pPlayerwk->xposi.w.h < 3984) return; /* Line 317, Address: 0x1029d4c */




  pActwk->actfree[3] += 2; /* Line 322, Address: 0x1029d68 */
  emie8_snc_l(pActwk, pPlayerwk); /* Line 323, Address: 0x1029d78 */
} /* Line 324, Address: 0x1029d88 */





static void emie8_snc_l(sprite_status* pActwk, sprite_status* pPlayerwk) { /* Line 330, Address: 0x1029da0 */
  swdata.w = 1028; /* Line 331, Address: 0x1029db0 */
  if (pPlayerwk->xposi.w.h > 3952) return; /* Line 332, Address: 0x1029dbc */




  pActwk->actfree[3] += 2; /* Line 337, Address: 0x1029dd8 */
  swdata.w = 0; /* Line 338, Address: 0x1029de8 */
  emie8_snc_w(pActwk, pPlayerwk); /* Line 339, Address: 0x1029df0 */
} /* Line 340, Address: 0x1029e00 */





static void emie8_snc_w(sprite_status* pActwk, sprite_status* pPlayerwk) { /* Line 346, Address: 0x1029e10 */
  if (pActwk->r_no0 >= 6) { /* Line 347, Address: 0x1029e1c */

    pActwk->actfree[3] += 2; /* Line 349, Address: 0x1029e34 */
    pPlayerwk->mstno.b.h = 5; /* Line 350, Address: 0x1029e44 */
  }
} /* Line 352, Address: 0x1029e50 */





static void emie8_snc_pata(sprite_status* pActwk, sprite_status* pPlayerwk) { /* Line 358, Address: 0x1029e60 */

  pActwk = pActwk; /* Line 360, Address: 0x1029e6c */
  if (pPlayerwk->patcnt < 16) { /* Line 361, Address: 0x1029e74 */
    pPlayerwk->patcnt = 16; /* Line 362, Address: 0x1029e8c */
  }
} /* Line 364, Address: 0x1029e98 */












static void flash_out8(void) { /* Line 377, Address: 0x1029eb0 */
  PALETTEENTRY* lpColwk;
  int i;

  lpColwk = lpcolorwk; /* Line 381, Address: 0x1029ebc */

  for (i = 0; i < 64; ++i) { /* Line 383, Address: 0x1029ec4 */

    if (lpColwk->peRed != 224) { /* Line 385, Address: 0x1029ed0 */
      lpColwk->peRed += 32; /* Line 386, Address: 0x1029ee4 */
    }
    if (lpColwk->peGreen != 224) { /* Line 388, Address: 0x1029ef0 */
      lpColwk->peGreen += 32; /* Line 389, Address: 0x1029f04 */
    }
    if (lpColwk->peBlue != 224) { /* Line 391, Address: 0x1029f10 */
      lpColwk->peBlue += 32; /* Line 392, Address: 0x1029f24 */
    }
    ++lpColwk; /* Line 394, Address: 0x1029f30 */
  } /* Line 395, Address: 0x1029f34 */
} /* Line 396, Address: 0x1029f44 */












static void emie8_jisin(sprite_status* pActwk) { /* Line 409, Address: 0x1029f60 */
  short wk;

  --pActwk->actfree[4]; /* Line 412, Address: 0x1029f6c */
  wk = -2; /* Line 413, Address: 0x1029f7c */


  if (pActwk->actfree[4] / 2 & 1) { /* Line 416, Address: 0x1029f88 */
    wk = -4; /* Line 417, Address: 0x1029fb8 */
  }
  scralim_down += wk; /* Line 419, Address: 0x1029fc4 */
  scralim_n_down += wk; /* Line 420, Address: 0x1029fd8 */
} /* Line 421, Address: 0x1029fec */
