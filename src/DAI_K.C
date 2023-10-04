#include "EQU.H"
#include "DAI_K.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "ETC.H"
#include "PLAYSUB.H"
#include "RIDECHK.H"

extern void soundset(short ReqNo);

spr_array k_daipat0 = {
  1,
  { { -16, -8, 0, 478 } }
};
spr_array k_daipat1 = {
  1,
  { { -16, -8, 0, 479 } }
};
spr_array k_daipat2 = {
  1,
  { { -16, -8, 0, 480 } }
};
spr_array* k_daipat[3] = {
  &k_daipat0,
  &k_daipat1,
  &k_daipat2
};
char k_daichg0[5] = { 1, 0, 1, 2, -1 };
char* k_daichg = k_daichg0;
void(*dai_k_move_tbl[2])(act_info*) = {
  &dai_k_init,
  &dai_k_move
};





























































































void dai_k(act_info* pActwk) { /* Line 127, Address: 0x1002090, Func Offset */
  dai_k_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 128, Address: 0x100209c, Func Offset */

  if (!time_stop) { /* Line 130, Address: 0x10020e0, Func Offset */
    patchg(pActwk, (unsigned char**)&k_daichg); /* Line 131, Address: 0x10020f0, Func Offset */
  }

  actionsub(pActwk); /* Line 134, Address: 0x1002104, Func Offset */
  frameout_s(pActwk); /* Line 135, Address: 0x1002110, Func Offset */
} /* Line 136, Address: 0x100211c, Func Offset */






void dai_k_init(act_info* pActwk) { /* Line 143, Address: 0x1002130 */
  pActwk->r_no0 += 2; /* Line 144, Address: 0x100213c */
  pActwk->actflg = 4; /* Line 145, Address: 0x100214c */
  pActwk->sprpri = 4; /* Line 146, Address: 0x1002158 */
  pActwk->patbase = k_daipat; /* Line 147, Address: 0x1002164 */




  pActwk->sprhsize = 16; /* Line 152, Address: 0x1002174 */
  pActwk->sprvsize = 8; /* Line 153, Address: 0x1002180 */
  dai_k_move(pActwk); /* Line 154, Address: 0x100218c */
} /* Line 155, Address: 0x1002198 */





void dai_k_move(act_info* pActwk) { /* Line 161, Address: 0x10021b0 */
  short lenwk, sinwk, coswk;
  static unsigned char pattbl[16] = { 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5 };

  if (!(pActwk->actflg & 128)) return; /* Line 165, Address: 0x10021c0 */



  if (!ride_on_chk(pActwk, actwk)) return; /* Line 169, Address: 0x10021d8 */



  if (!(actwk[0].actfree[2] & 1)) { /* Line 173, Address: 0x10021f4 */
    actwk[0].actfree[2] |= 1; /* Line 174, Address: 0x100220c */
    actwk[0].mstno.b.h = 45; /* Line 175, Address: 0x1002220 */
    lenwk = actwk[0].xposi.w.h - pActwk->xposi.w.h; /* Line 176, Address: 0x100222c */

    if (lenwk >= 0) { /* Line 178, Address: 0x1002260 */
      actwk[0].actfree[1] = 0; /* Line 179, Address: 0x1002270 */
    } else { /* Line 180, Address: 0x1002278 */
      actwk[0].actfree[1] = 128; /* Line 181, Address: 0x1002280 */
      lenwk = -lenwk; /* Line 182, Address: 0x100228c */
    }

    actwk[0].actfree[15] = (unsigned short)lenwk; /* Line 185, Address: 0x10022a8 */
  }


  if (actwk[0].r_no0 >= 6) return; /* Line 189, Address: 0x10022b4 */




  actwk[0].actfree[1] += 8; /* Line 194, Address: 0x10022cc */
  sinset(actwk[0].actfree[1], &sinwk, &coswk); /* Line 195, Address: 0x10022e0 */
  actwk[0].xposi.w.h = pActwk->xposi.w.h + ((unsigned int)(actwk[0].actfree[15] * coswk) >> 8); /* Line 196, Address: 0x10022f8 */



  actwk[0].patcnt = pattbl[actwk[0].actfree[1] >> 4]; /* Line 200, Address: 0x100233c */

  if (!(actwk[0].actfree[1] & 63)) { /* Line 202, Address: 0x1002364 */
    ++actwk[0].actfree[15]; /* Line 203, Address: 0x100237c */
  }

  swdata = swdata1; /* Line 206, Address: 0x1002390 */
  k_move(pActwk, &actwk[0]); /* Line 207, Address: 0x10023a8 */
  jumpchk_d(pActwk, &actwk[0]); /* Line 208, Address: 0x10023bc */
} /* Line 209, Address: 0x10023d0 */













void k_move(act_info* pActwk, act_info* pSonicwk) { /* Line 223, Address: 0x10023f0 */
  if (pSonicwk->xposi.w.h >= pActwk->xposi.w.h) { /* Line 224, Address: 0x10023fc */


    if (swdata.b.h & 8) { /* Line 227, Address: 0x1002428 */
      ++pSonicwk->actfree[15]; /* Line 228, Address: 0x1002440 */
    } /* Line 229, Address: 0x1002450 */
    else if ((swdata.b.h & 4) && pSonicwk->actfree[15]) { /* Line 230, Address: 0x1002470 */
      --pSonicwk->actfree[15]; /* Line 231, Address: 0x1002480 */
    }

  } /* Line 234, Address: 0x1002490 */
  else {

    if (swdata.b.h & 4) { /* Line 237, Address: 0x1002498 */
      ++pSonicwk->actfree[15]; /* Line 238, Address: 0x10024b0 */
    } /* Line 239, Address: 0x10024c0 */
    else if ((swdata.b.h & 8) && pSonicwk->actfree[15]) { /* Line 240, Address: 0x10024e0 */
      --pSonicwk->actfree[15]; /* Line 241, Address: 0x10024f0 */
    }

  }
} /* Line 245, Address: 0x1002500 */













void jumpchk_d(act_info* pActwk, act_info* pSonicwk) { /* Line 259, Address: 0x1002510 */
  short jumpwk, sinwk, coswk;

  if (!(swdata.b.l & 112)) return; /* Line 262, Address: 0x1002524 */




  pSonicwk->actfree[2] = 0; /* Line 267, Address: 0x100253c */
  if (pActwk->cddat & 64) { /* Line 268, Address: 0x1002544 */
    jumpwk = 896; /* Line 269, Address: 0x100255c */
  } else { /* Line 270, Address: 0x1002568 */
    jumpwk = 1664; /* Line 271, Address: 0x1002570 */
  }

  sinset(pSonicwk->direc.b.h + -64, &sinwk, &coswk); /* Line 274, Address: 0x100257c */
  pSonicwk->xspeed.w += (coswk * jumpwk) >> 8; /* Line 275, Address: 0x10025a4 */
  pSonicwk->yspeed.w += (sinwk * jumpwk) >> 8; /* Line 276, Address: 0x10025d8 */

  pSonicwk->cddat |= 2; /* Line 278, Address: 0x100260c */
  pSonicwk->cddat &= 223; /* Line 279, Address: 0x100261c */
  pSonicwk->actfree[18] = 1; /* Line 280, Address: 0x100262c */
  pSonicwk->actfree[14] = 0; /* Line 281, Address: 0x1002638 */

  soundset(160); /* Line 283, Address: 0x1002640 */






























  if (pSonicwk->cddat & 4) { /* Line 314, Address: 0x100264c */
    if (chibi_flag) { /* Line 315, Address: 0x1002664 */
      pSonicwk->sprvsize = 10; /* Line 316, Address: 0x1002674 */
      pSonicwk->sprhs = 5; /* Line 317, Address: 0x1002680 */
    } else { /* Line 318, Address: 0x100268c */
      pSonicwk->sprvsize = 19; /* Line 319, Address: 0x1002694 */
      pSonicwk->sprhs = 9; /* Line 320, Address: 0x10026a0 */
    }

    pSonicwk->cddat |= 16; /* Line 323, Address: 0x10026ac */
  } else { /* Line 324, Address: 0x10026bc */
    if (chibi_flag) { /* Line 325, Address: 0x10026c4 */
      pSonicwk->sprvsize = 10; /* Line 326, Address: 0x10026d4 */
      pSonicwk->sprhs = 5; /* Line 327, Address: 0x10026e0 */
    } else { /* Line 328, Address: 0x10026ec */
      pSonicwk->sprvsize = 14; /* Line 329, Address: 0x10026f4 */
      pSonicwk->sprhs = 7; /* Line 330, Address: 0x1002700 */
    }

    pSonicwk->cddat |= 4; /* Line 333, Address: 0x100270c */
    pSonicwk->mstno.b.h = 2; /* Line 334, Address: 0x100271c */
  }


} /* Line 338, Address: 0x1002728 */
