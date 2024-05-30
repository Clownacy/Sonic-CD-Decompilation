#include "..\EQU.H"
#include "TENTOU.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\FCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\SUICIDE.H"

static unsigned char bCarry;
void(*tentou_tbl[6])(sprite_status*) = {
  &ten_a_init,
  &ten_a_fall,
  &ten_a_wait,
  &ten_a_lr,
  &ten_a_up,
  &ten_a_gake
};
void(*tentou1_tbl[5])(sprite_status*) = {
  &ten_b_init,
  &ten_b_fall,
  &ten_b_wait,
  &ten_b_blink,
  &ten_b_die
};
unsigned char pchg0_0[5] = { 3, 0, 1, 2, 255 };
unsigned char* pchg0[1] = { pchg0_0 };
sprite_pattern ten_b_tentou0 = {
  1,
  { { -24, -24, 0, 521 } }
};
sprite_pattern ten_b_tentou1 = {
  1,
  { { -24, -24, 0, 522 } }
};
sprite_pattern ten_b_tentou2 = {
  1,
  { { -24, -24, 0, 523 } }
};
sprite_pattern* pat_ten_b_tentou[3] = {
  &ten_b_tentou0,
  &ten_b_tentou1,
  &ten_b_tentou2
};
sprite_pattern e_tentou0 = {
  1,
  { { -24, -24, 0, 524 } }
};
sprite_pattern e_tentou1 = {
  1,
  { { -24, -24, 0, 525 } }
};
sprite_pattern e_tentou2 = {
  1,
  { { -24, -24, 0, 526 } }
};
sprite_pattern* pat_e_tentou[3] = {
  &e_tentou0,
  &e_tentou1,
  &e_tentou2
};
unsigned char pchg1_0[4] = { 1, 0, 1, 255 };
unsigned char* pchg1[1] = { pchg1_0 };
sprite_pattern bomten_b_0 = {
  1,
  { { -8, -8, 0, 527 } }
};
sprite_pattern bomten_b_1 = {
  1,
  { { -8, -8, 0, 528 } }
};
sprite_pattern* tentou_bomten_b_pat[2] = {
  &bomten_b_0,
  &bomten_b_1
};















void tentou(sprite_status* pActwk) { /* Line 92, Address: 0x1023d50 */
  if (pActwk->userflag.b.h - 1 >= 0) /* Line 93, Address: 0x1023d5c */
  {
    tentou1(pActwk); /* Line 95, Address: 0x1023d78 */
    return; /* Line 96, Address: 0x1023d84 */
  }
  if (enemy_suicide(pActwk) == -1) return; /* Line 98, Address: 0x1023d8c */

  tentou_tbl[pActwk->r_no0 / 2](pActwk); /* Line 100, Address: 0x1023dac */
  patchg(pActwk, pchg0); /* Line 101, Address: 0x1023df0 */
  actionsub(pActwk); /* Line 102, Address: 0x1023e04 */
  frameout_s(pActwk); /* Line 103, Address: 0x1023e10 */
} /* Line 104, Address: 0x1023e1c */











void ten_a_init(sprite_status* pActwk) { /* Line 116, Address: 0x1023e30 */
  pActwk->r_no0 += 2; /* Line 117, Address: 0x1023e3c */
  pActwk->actflg |= 132; /* Line 118, Address: 0x1023e4c */
  pActwk->sprpri = 1; /* Line 119, Address: 0x1023e5c */
  pActwk->colino = 6; /* Line 120, Address: 0x1023e68 */
  pActwk->sprhsize = 14; /* Line 121, Address: 0x1023e74 */
  pActwk->sprvsize = 14; /* Line 122, Address: 0x1023e80 */
  pActwk->sproffset = 42090; /* Line 123, Address: 0x1023e8c */
  if (pActwk->userflag.w >= 0) /* Line 124, Address: 0x1023e98 */
  {
    pActwk->patbase = pat_e_tentou; /* Line 126, Address: 0x1023eb0 */
    pActwk->actfree[21] = 255; /* Line 127, Address: 0x1023ec0 */
  } /* Line 128, Address: 0x1023ecc */
  else
    pActwk->patbase = pat_ten_b_tentou; /* Line 130, Address: 0x1023ed4 */
  ten_a_fall(pActwk); /* Line 131, Address: 0x1023ee4 */
} /* Line 132, Address: 0x1023ef0 */











void ten_a_fall(sprite_status* pActwk) { /* Line 144, Address: 0x1023f00 */
  short iD1;

  pActwk->yposi.l += 65536; /* Line 147, Address: 0x1023f10 */
  iD1 = emycol_d(pActwk); /* Line 148, Address: 0x1023f24 */
  iD1 -= 8; /* Line 149, Address: 0x1023f38 */
  if (iD1 <= 0) /* Line 150, Address: 0x1023f44 */
  {
    pActwk->yposi.w.h -= iD1; /* Line 152, Address: 0x1023f54 */
    *(int*)&pActwk->actfree[8] = pActwk->yposi.l; /* Line 153, Address: 0x1023f64 */
    *(int*)&pActwk->actfree[4] = 12288; /* Line 154, Address: 0x1023f78 */
    ((short*)pActwk)[29] = 8; /* Line 155, Address: 0x1023f88 */
    pActwk->r_no0 += 2; /* Line 156, Address: 0x1023f94 */
    if ((long int)*(int*)&pActwk->actfree[0] != 0) /* Line 157, Address: 0x1023fa4 */
      pActwk->r_no0 += 2; /* Line 158, Address: 0x1023fc0 */
  }
} /* Line 160, Address: 0x1023fd0 */



int abs(int i) { /* Line 164, Address: 0x1023ff0 */
  if (i >= 0) /* Line 165, Address: 0x1023ff8 */
    return i; /* Line 166, Address: 0x1024004 */

  return -i; /* Line 168, Address: 0x1024010 */
} /* Line 169, Address: 0x1024018 */











void ten_a_wait(sprite_status* pActwk) { /* Line 181, Address: 0x1024030 */
  sprite_status* pPlaywk = &actwk[0]; /* Line 182, Address: 0x1024048 */
  short iD0, iD1;

  ten_a_hover(pActwk); /* Line 185, Address: 0x1024050 */

  iD0 = pActwk->yposi.w.h - pPlaywk->yposi.w.h; /* Line 187, Address: 0x102405c */
  iD0 = abs(iD0); /* Line 188, Address: 0x102408c */
  if (iD0 <= 80) /* Line 189, Address: 0x10240ac */
  {





    iD0 = pActwk->xposi.w.h - pPlaywk->xposi.w.h; /* Line 196, Address: 0x10240c0 */
    iD1 = iD0; /* Line 197, Address: 0x10240f0 */
    iD0 = abs(iD0); /* Line 198, Address: 0x10240f8 */
    if (iD0 <= 80) /* Line 199, Address: 0x1024118 */
    {





      pActwk->r_no0 += 2; /* Line 206, Address: 0x102412c */
      *(int*)&pActwk->actfree[0] = 4294918144; /* Line 207, Address: 0x102413c */
      if (iD1 >= 0) /* Line 208, Address: 0x1024150 */
      {
        pActwk->actflg ^= 1; /* Line 210, Address: 0x1024160 */
        pActwk->cddat ^= 1; /* Line 211, Address: 0x1024170 */
        *(int*)&pActwk->actfree[0] = -(long int)*(int*)&pActwk->actfree[0]; /* Line 212, Address: 0x1024180 */
      }
    }
  }
} /* Line 216, Address: 0x10241ac */











void ten_a_lr(sprite_status* pActwk) { /* Line 228, Address: 0x10241d0 */
  short iD1;
  sprite_status* pActfree;

  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 232, Address: 0x10241e0 */
  pActwk->yposi.l = *(int*)&pActwk->actfree[8]; /* Line 233, Address: 0x10241fc */

  if (*(int*)&pActwk->actfree[0] >= 0) /* Line 235, Address: 0x1024210 */
    iD1 = emycol_r(pActwk, pActwk->sprhs); /* Line 236, Address: 0x1024224 */
  else
    iD1 = emycol_l(pActwk, pActwk->sprhs); /* Line 238, Address: 0x1024248 */

  if (iD1 >= 0) /* Line 240, Address: 0x1024264 */
  {
    iD1 = emycol_d(pActwk); /* Line 242, Address: 0x1024274 */
    if (iD1 < 16) /* Line 243, Address: 0x1024288 */
    {
      iD1 -= 8; /* Line 245, Address: 0x102429c */
      pActwk->yposi.w.h += iD1; /* Line 246, Address: 0x10242a8 */
      *(int*)&pActwk->actfree[8] = pActwk->yposi.l; /* Line 247, Address: 0x10242b8 */
      ten_a_hover(pActwk); /* Line 248, Address: 0x10242cc */
      if (pActwk->actfree[21] != 0) /* Line 249, Address: 0x10242d8 */
      {
        ((unsigned short*)pActwk)[29] &= 127; /* Line 251, Address: 0x10242ec */
        if (((unsigned short*)pActwk)[29] == 0) /* Line 252, Address: 0x10242fc */
        {
          if (actwkchk(&pActfree) == 0) /* Line 254, Address: 0x1024310 */
          {
            pActfree->actno = pActwk->actno; /* Line 256, Address: 0x1024324 */
            pActfree->xposi.l = pActwk->xposi.l; /* Line 257, Address: 0x1024334 */
            pActfree->yposi.l = pActwk->yposi.l; /* Line 258, Address: 0x1024344 */
            pActfree->yposi.w.h += 16; /* Line 259, Address: 0x1024354 */
            pActfree->userflag.b.h = 1; /* Line 260, Address: 0x1024364 */
          }
        }
      }
    } /* Line 264, Address: 0x1024370 */
    else
    {

      pActwk->r_no0 += 4; /* Line 268, Address: 0x1024378 */
      ten_a_hover(pActwk); /* Line 269, Address: 0x1024388 */
      *(int*)&pActwk->actfree[8] = pActwk->yposi.l; /* Line 270, Address: 0x1024394 */
    }
  } /* Line 272, Address: 0x10243a8 */
  else
  {

    pActwk->r_no0 += 2; /* Line 276, Address: 0x10243b0 */
  }
} /* Line 278, Address: 0x10243c0 */











void ten_a_up(sprite_status* pActwk) { /* Line 290, Address: 0x10243e0 */
  pActwk->yposi.l -= 32768; /* Line 291, Address: 0x10243e8 */
} /* Line 292, Address: 0x10243f8 */











void ten_a_gake(sprite_status* pActwk) { /* Line 304, Address: 0x1024410 */
  char cwk, cRwk;
  short iD1, iD3, iD4;

  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 308, Address: 0x1024430 */
  iD3 = pActwk->xposi.w.h; /* Line 309, Address: 0x102444c */
  iD4 = pActwk->sprhsize; /* Line 310, Address: 0x102445c */
  iD3 -= iD4; /* Line 311, Address: 0x1024470 */
  if ((long int)*(int*)&pActwk->actfree[0] > 0) /* Line 312, Address: 0x102447c */
    iD3 += iD4 + iD4; /* Line 313, Address: 0x1024498 */
  iD1 = emycol_d2(pActwk, iD3); /* Line 314, Address: 0x10244c0 */
  if (iD1 >= 16) /* Line 315, Address: 0x10244d8 */
  {

    cwk = 2; /* Line 318, Address: 0x10244ec */
    cwk = -cwk * 4; /* Line 319, Address: 0x10244f8 */
    cRwk = pActwk->r_no0; /* Line 320, Address: 0x1024518 */
    cRwk = cRwk + cwk; /* Line 321, Address: 0x1024528 */
    pActwk->r_no0 = cRwk; /* Line 322, Address: 0x102454c */
  }
} /* Line 324, Address: 0x1024554 */











void ten_a_hover(sprite_status* pActwk) { /* Line 336, Address: 0x1024580 */
  unsigned short wD0;

  ++((short*)pActwk)[29]; /* Line 339, Address: 0x102458c */
  pActwk->yposi.l += *(int*)&pActwk->actfree[4]; /* Line 340, Address: 0x102459c */
  wD0 = ((unsigned short*)pActwk)[29]; /* Line 341, Address: 0x10245b8 */
  wD0 &= 15; /* Line 342, Address: 0x10245c4 */
  if (wD0 != 0) return; /* Line 343, Address: 0x10245cc */
  *(int*)&pActwk->actfree[4] = -(long int)*(int*)&pActwk->actfree[4]; /* Line 344, Address: 0x10245d8 */
} /* Line 345, Address: 0x1024604 */











void ten_a_range(sprite_status* pActwk) { /* Line 357, Address: 0x1024620 */
  short iD0;
  sprite_status* pPlaywk = &actwk[0]; /* Line 359, Address: 0x1024634 */

  iD0 = pPlaywk->yposi.w.h; /* Line 361, Address: 0x102463c */
  iD0 -= pActwk->yposi.w.h; /* Line 362, Address: 0x1024648 */
  iD0 += 256; /* Line 363, Address: 0x102465c */
  bCarry = CCset(iD0, 512); /* Line 364, Address: 0x1024668 */
  iD0 -= 512; /* Line 365, Address: 0x1024684 */
  if (bCarry == 1) /* Line 366, Address: 0x1024690 */
  {
    iD0 = pPlaywk->yposi.w.h - pActwk->yposi.w.h; /* Line 368, Address: 0x10246a8 */
    iD0 += 256; /* Line 369, Address: 0x10246d8 */
    iD0 -= 512; /* Line 370, Address: 0x10246e4 */
  }
} /* Line 372, Address: 0x10246f0 */





























void tentou1(sprite_status* pActwk) { /* Line 402, Address: 0x1024710 */
  unsigned char byRwk;

  byRwk = pActwk->r_no0 / 2; /* Line 405, Address: 0x1024720 */
  tentou1_tbl[byRwk](pActwk); /* Line 406, Address: 0x102474c */
  actionsub(pActwk); /* Line 407, Address: 0x1024770 */
} /* Line 408, Address: 0x102477c */












void ten_b_init(sprite_status* pActwk) { /* Line 421, Address: 0x1024790 */
  pActwk->r_no0 += 2; /* Line 422, Address: 0x102479c */
  pActwk->actflg |= 4; /* Line 423, Address: 0x10247ac */
  pActwk->sprpri = 2; /* Line 424, Address: 0x10247bc */
  pActwk->colino = 139; /* Line 425, Address: 0x10247c8 */
  pActwk->sprhs = 6; /* Line 426, Address: 0x10247d4 */
  pActwk->sprhsize = 6; /* Line 427, Address: 0x10247e0 */
  pActwk->sprvsize = 6; /* Line 428, Address: 0x10247ec */
  pActwk->sproffset = 1173; /* Line 429, Address: 0x10247f8 */
  pActwk->patbase = tentou_bomten_b_pat; /* Line 430, Address: 0x1024804 */
  ten_b_fall(pActwk); /* Line 431, Address: 0x1024814 */
} /* Line 432, Address: 0x1024820 */











void ten_b_fall(sprite_status* pActwk) { /* Line 444, Address: 0x1024830 */
  short iD1;

  if (pActwk->colicnt != 0) /* Line 447, Address: 0x1024840 */
  {
    ten_b_die(pActwk); /* Line 449, Address: 0x1024854 */
    return; /* Line 450, Address: 0x1024860 */
  }
  pActwk->yposi.l += 65536; /* Line 452, Address: 0x1024868 */
  iD1 = emycol_d(pActwk); /* Line 453, Address: 0x102487c */
  if (iD1 < 0) /* Line 454, Address: 0x1024890 */
  {
    pActwk->yposi.w.h += iD1; /* Line 456, Address: 0x10248a0 */
    ((short*)pActwk)[23] = 120; /* Line 457, Address: 0x10248b0 */
    pActwk->r_no0 += 2; /* Line 458, Address: 0x10248bc */
  }
} /* Line 460, Address: 0x10248cc */











void ten_b_wait(sprite_status* pActwk) { /* Line 472, Address: 0x10248e0 */
  if (pActwk->colicnt != 0) /* Line 473, Address: 0x10248ec */
  {
    ten_b_die(pActwk); /* Line 475, Address: 0x1024900 */
    return; /* Line 476, Address: 0x102490c */
  }
  --((short*)pActwk)[23]; /* Line 478, Address: 0x1024914 */
  if (((short*)pActwk)[23] == 0) /* Line 479, Address: 0x1024924 */
  {
    ((short*)pActwk)[23] = 120; /* Line 481, Address: 0x102493c */
    pActwk->r_no0 += 2; /* Line 482, Address: 0x1024948 */
  }
} /* Line 484, Address: 0x1024958 */











void ten_b_blink(sprite_status* pActwk) { /* Line 496, Address: 0x1024970 */
  if (pActwk->colicnt != 0) /* Line 497, Address: 0x102497c */
  {
    ten_b_die(pActwk); /* Line 499, Address: 0x1024990 */
    return; /* Line 500, Address: 0x102499c */
  }
  --((short*)pActwk)[23]; /* Line 502, Address: 0x10249a4 */
  if (((short*)pActwk)[23] == 0) /* Line 503, Address: 0x10249b4 */
  {
    pActwk->r_no0 += 2; /* Line 505, Address: 0x10249cc */
  }
  patchg(pActwk, pchg1); /* Line 507, Address: 0x10249dc */
} /* Line 508, Address: 0x10249f0 */











void ten_b_die(sprite_status* pActwk) { /* Line 520, Address: 0x1024a00 */
  pActwk->actno = 24; /* Line 521, Address: 0x1024a0c */
  pActwk->r_no0 = 0; /* Line 522, Address: 0x1024a18 */
  pActwk->r_no1 = 1; /* Line 523, Address: 0x1024a20 */
  if ((char)pActwk->actflg < 0) /* Line 524, Address: 0x1024a2c */
    soundset(158); /* Line 525, Address: 0x1024a4c */
} /* Line 526, Address: 0x1024a58 */
