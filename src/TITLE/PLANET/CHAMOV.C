#include "..\..\TYPES.H"
#include "LPL_TYPES.H"
#include "SPM_EQU.H"
#include "CHAMOV.H"

void(*flicky_acttbl[4])(sprite_status_lpl*) =
{
  &flickyinit,
  &flickymove,
  &flickyslow,
  &flickydown
};
extern sprite_patterns_title flicky_tbl1;
extern sprite_patterns_title flicky_tbl2;
extern sprite_patterns_title flicky_tbl3;
void(*star_acttbl[2])(sprite_status_lpl*) =
{
  &starinit,
  &starmove
};
extern sprite_patterns_title star_tbl;
void(*ufo_acttbl[4])(sprite_status_lpl*) =
{
  &ufoinit,
  &ufomode,
  &ufomove1,
  &ufomove2
};
extern sprite_patterns_title ufo_tbl;
extern sprite_patterns_title ufo_tbl1;
extern sprite_patterns_title ufo_tbl2;
void(*eggm_acttbl[2])(sprite_status_lpl*) =
{
  &eggminit,
  &eggmmove
};
extern sprite_patterns_title eggm_tbl;
extern sprite_patterns_title eggm_tbl2;
void(*msnc_acttbl[5])(sprite_status_lpl*) =
{
  &msncinit,
  &msncstart,
  &msncfloat,
  &msncdush,
  &msncexit
};
extern sprite_patterns_title msnc_tbl;
extern sprite_patterns_title msnc_tbl2;
void(*tails_acttbl[4])(sprite_status_lpl*) =
{
  &tailsinit,
  &tailsmove,
  &tailsmove1,
  &ufomove2
};
extern sprite_patterns_title tails_tbl;
extern sprite_patterns_title tails_up_tbl;
extern sprite_patterns_title tails_down_tbl;

























void spr_kill(sprite_status_lpl* pActwk) { /* Line 84, Address: 0x10010f0 */
  actset_flg = actset_flg ^ pActwk->ACT_FLG; /* Line 85, Address: 0x10010f8 */
  pActwk->SPR_FLG |= 16; /* Line 86, Address: 0x1001114 */
} /* Line 87, Address: 0x1001124 */











void spr_kills(sprite_status_lpl* pActwk) { /* Line 99, Address: 0x1001130 */
  short i;
  unsigned short wD0;

  wD0 = pActwk->ACT_NO; /* Line 103, Address: 0x1001140 */
  pActwk->ACT_NO = 0; /* Line 104, Address: 0x100114c */
  pActwk->SPR_FLG |= 16; /* Line 105, Address: 0x1001154 */
  for (i = 0; i < 16; ++i) /* Line 106, Address: 0x1001164 */
  {
    if (actwk[i].ACT_NO == wD0) return; /* Line 108, Address: 0x1001170 */

  } /* Line 110, Address: 0x10011a4 */
  actset_flg = actset_flg ^ pActwk->ACT_FLG; /* Line 111, Address: 0x10011c4 */
} /* Line 112, Address: 0x10011e0 */












short killchk(sprite_status_lpl* pActwk) { /* Line 125, Address: 0x1001200 */
  if (pActwk->XPOSI.w.h < -79) /* Line 126, Address: 0x1001208 */
    return 1; /* Line 127, Address: 0x1001224 */
  if (pActwk->XPOSI.w.h >= 400) /* Line 128, Address: 0x1001230 */
    return 1; /* Line 129, Address: 0x100124c */
  if (pActwk->YPOSI.w.h < -4) /* Line 130, Address: 0x1001258 */
    return 1; /* Line 131, Address: 0x1001274 */
  if (pActwk->YPOSI.w.h >= 224) /* Line 132, Address: 0x1001280 */
    return 1; /* Line 133, Address: 0x100129c */

  return 0; /* Line 135, Address: 0x10012a8 */
} /* Line 136, Address: 0x10012ac */














short chk_another(unsigned short wD0, sprite_status_lpl* pActwk, sprite_status_lpl** ppActwk) { /* Line 151, Address: 0x10012c0 */
  short i;
  sprite_status_lpl* pActfind;

  pActfind = actwk; /* Line 155, Address: 0x10012d8 */
  for (i = 0; i < 16; ++i, ++pActfind) /* Line 156, Address: 0x10012e0 */
  {
    if (pActfind->ACT_NO == wD0) /* Line 158, Address: 0x10012ec */
      if (pActfind - actwk != pActwk - actwk) /* Line 159, Address: 0x1001304 */
      {
        *ppActwk = pActfind; /* Line 161, Address: 0x1001358 */
        return 1; /* Line 162, Address: 0x1001360 */
      }
  } /* Line 164, Address: 0x100136c */
  return 0; /* Line 165, Address: 0x1001390 */
} /* Line 166, Address: 0x1001394 */











void sinmove(sprite_status_lpl* pActwk) { /* Line 178, Address: 0x10013b0 */
  short iD0, iD3;
  int_union lD0, lD3;

  if (killchk(pActwk) != 0) /* Line 182, Address: 0x10013c4 */
  {
    spr_kills(pActwk); /* Line 184, Address: 0x10013e0 */
    return; /* Line 185, Address: 0x10013ec */
  }

  pActwk->YPOSI.w.h -= pActwk->Y_OFFSET; /* Line 188, Address: 0x10013f4 */

  iD3 = sin_planet(pActwk->SIN_CNT); /* Line 190, Address: 0x100140c */
  iD0 = pActwk->Y_WIDE; /* Line 191, Address: 0x1001424 */
  lD3.l = iD3 * iD0; /* Line 192, Address: 0x1001434 */
  lD3.l >>= 8; /* Line 193, Address: 0x100144c */
  pActwk->Y_OFFSET = lD3.w.l; /* Line 194, Address: 0x1001458 */
  pActwk->YPOSI.w.h += lD3.w.l; /* Line 195, Address: 0x1001464 */

  lD0.l = random() & 32767; /* Line 197, Address: 0x1001478 */
  lD0.w.l = lD0.l / pActwk->X_WIDE; /* Line 198, Address: 0x1001488 */
  pActwk->SIN_CNT += lD0.w.l; /* Line 199, Address: 0x10014bc */
  if (pActwk->SIN_CNT >= 511) /* Line 200, Address: 0x10014d0 */
    pActwk->SIN_CNT -= 511; /* Line 201, Address: 0x10014ec */

  lD0.l = pActwk->X_SPEED.l; /* Line 203, Address: 0x10014fc */
  if (music_selflg != 0) /* Line 204, Address: 0x1001508 */
    lD0.l <<= 3; /* Line 205, Address: 0x100151c */
  pActwk->XPOSI.l += lD0.l; /* Line 206, Address: 0x1001528 */

  pActwk->YPOSI.l += pActwk->Y_SPEED.l; /* Line 208, Address: 0x100153c */
} /* Line 209, Address: 0x1001554 */


















void flicky_ctrl(sprite_status_lpl* pActwk) { /* Line 228, Address: 0x1001570 */
  flicky_acttbl[pActwk->EXE_NO](pActwk); /* Line 229, Address: 0x100157c */
} /* Line 230, Address: 0x10015a8 */











void flickyinit(sprite_status_lpl* pActwk) { /* Line 242, Address: 0x10015c0 */
  pActwk->CGBASE += 16384; /* Line 243, Address: 0x10015c8 */
  pActwk->PAT_NO = 0; /* Line 244, Address: 0x10015d8 */

  pActwk->X_OFFSET = 0; /* Line 246, Address: 0x10015e0 */
  pActwk->Y_OFFSET = 0; /* Line 247, Address: 0x10015e8 */

  if (pActwk->SPR_FLG & 2) /* Line 249, Address: 0x10015f0 */
  {
    pActwk->EXE_NO = 3; /* Line 251, Address: 0x1001608 */
    return; /* Line 252, Address: 0x1001614 */
  }

  if (pActwk->SPR_FLG & 1) /* Line 255, Address: 0x100161c */
  {
    pActwk->EXE_NO = 2; /* Line 257, Address: 0x1001634 */
  } /* Line 258, Address: 0x1001640 */
  else
    pActwk->EXE_NO = 1; /* Line 260, Address: 0x1001648 */
} /* Line 261, Address: 0x1001654 */











void flickymove(sprite_status_lpl* pActwk) { /* Line 273, Address: 0x1001660 */
  if (killchk(pActwk) != 0) /* Line 274, Address: 0x100166c */
  {
    spr_kills(pActwk); /* Line 276, Address: 0x1001688 */
  } /* Line 277, Address: 0x1001694 */
  else
    fnormalmove(pActwk); /* Line 279, Address: 0x100169c */
} /* Line 280, Address: 0x10016a8 */











void flickyslow(sprite_status_lpl* pActwk) { /* Line 292, Address: 0x10016c0 */
  if (killchk(pActwk) != 0) /* Line 293, Address: 0x10016cc */
  {
    spr_kills(pActwk); /* Line 295, Address: 0x10016e8 */
    return; /* Line 296, Address: 0x10016f4 */
  }
  fnormalmove(pActwk); /* Line 298, Address: 0x10016fc */
  fslowmove(pActwk); /* Line 299, Address: 0x1001708 */
} /* Line 300, Address: 0x1001714 */











void flickydown(sprite_status_lpl* pActwk) { /* Line 312, Address: 0x1001730 */
  if (killchk(pActwk) != 0) /* Line 313, Address: 0x100173c */
  {
    spr_kills(pActwk); /* Line 315, Address: 0x1001758 */
    return; /* Line 316, Address: 0x1001764 */
  }
  fnormalmove(pActwk); /* Line 318, Address: 0x100176c */
  fdownmove(pActwk); /* Line 319, Address: 0x1001778 */
} /* Line 320, Address: 0x1001784 */











void fnormalmove(sprite_status_lpl* pActwk) { /* Line 332, Address: 0x10017a0 */
  int_union lD0, lD3;

  if (pActwk->SPR_FLG & 2) /* Line 335, Address: 0x10017ac */
  {
    if (pActwk->Y_SPEED.l > 0) goto label1; /* Line 337, Address: 0x10017c4 */
  }


  pActwk->YPOSI.w.h -= pActwk->Y_OFFSET; /* Line 341, Address: 0x10017d4 */

  lD3.w.l = sin_planet(pActwk->SIN_CNT); /* Line 343, Address: 0x10017ec */
  lD3.l = lD3.w.l << 2; /* Line 344, Address: 0x1001800 */
  lD3.l >>= 8; /* Line 345, Address: 0x1001814 */
  pActwk->Y_OFFSET = lD3.w.l; /* Line 346, Address: 0x1001820 */
  pActwk->YPOSI.w.h += lD3.w.l; /* Line 347, Address: 0x100182c */

  lD0.l = random() & 32767; /* Line 349, Address: 0x1001840 */
  lD0.w.l %= 48; /* Line 350, Address: 0x1001850 */
  pActwk->SIN_CNT += lD0.w.l; /* Line 351, Address: 0x100186c */
  if (pActwk->SIN_CNT >= 511) /* Line 352, Address: 0x1001880 */
    pActwk->SIN_CNT -= 511; /* Line 353, Address: 0x100189c */
label1:
  lD0.l = pActwk->X_SPEED.l; /* Line 355, Address: 0x10018ac */
  if (music_selflg != 0) /* Line 356, Address: 0x10018b8 */
    lD0.l <<= 3; /* Line 357, Address: 0x10018cc */

  pActwk->XPOSI.l += lD0.l; /* Line 359, Address: 0x10018d8 */
  lD0.l = pActwk->Y_SPEED.l; /* Line 360, Address: 0x10018ec */
  pActwk->YPOSI.l += lD0.l; /* Line 361, Address: 0x10018f8 */
} /* Line 362, Address: 0x100190c */











void fslowmove(sprite_status_lpl* pActwk) { /* Line 374, Address: 0x1001920 */
  short iD0;
  sprite_status_lpl* pActflicky;


  if (chk_another(pActwk->ACT_NO, pActwk, &pActflicky) != 0) /* Line 379, Address: 0x1001930 */
  {

    iD0 = pActwk->XPOSI.w.h - pActflicky->XPOSI.w.h; /* Line 382, Address: 0x1001958 */
    if (iD0 < 0) /* Line 383, Address: 0x100198c */
      iD0 = -iD0; /* Line 384, Address: 0x100199c */

    if (iD0 < 72) goto label1; /* Line 386, Address: 0x10019b8 */
  }

  pActwk->PAT_ADR = &flicky_tbl2; /* Line 389, Address: 0x10019cc */
  pActwk->PAT_NO = 0; /* Line 390, Address: 0x10019dc */
  if (pActwk->X_SPEED.l < 0) /* Line 391, Address: 0x10019e4 */
    pActwk->X_SPEED.l = -196608; /* Line 392, Address: 0x10019f4 */
  else
    pActwk->X_SPEED.l = 196608; /* Line 394, Address: 0x1001a08 */
  return; /* Line 395, Address: 0x1001a14 */
label1:
  if (iD0 < 33) /* Line 397, Address: 0x1001a1c */
  {
    pActwk->PAT_ADR = &flicky_tbl1; /* Line 399, Address: 0x1001a30 */
    pActwk->PAT_NO = 0; /* Line 400, Address: 0x1001a40 */
    if (pActwk->X_SPEED.l < 0) /* Line 401, Address: 0x1001a48 */
      pActwk->X_SPEED.l = -40960; /* Line 402, Address: 0x1001a58 */
    else
      pActwk->X_SPEED.l = 40960; /* Line 404, Address: 0x1001a70 */
  }
} /* Line 406, Address: 0x1001a7c */











void fdownmove(sprite_status_lpl* pActwk) { /* Line 418, Address: 0x1001a90 */
  short iD0;
  sprite_status_lpl* pActflicky;


  if (chk_another(pActwk->ACT_NO, pActwk, &pActflicky) == 0) goto label1; /* Line 423, Address: 0x1001aa0 */


  iD0 = pActwk->YPOSI.w.h - pActflicky->YPOSI.w.h; /* Line 426, Address: 0x1001ac8 */
  if (iD0 <= 0) /* Line 427, Address: 0x1001afc */
    iD0 = 0; /* Line 428, Address: 0x1001b0c */

  if (iD0 >= 58) /* Line 430, Address: 0x1001b10 */
  {
label1:
    pActwk->PAT_ADR = &flicky_tbl2; /* Line 433, Address: 0x1001b24 */
    pActwk->PAT_NO = 0; /* Line 434, Address: 0x1001b34 */
    pActwk->Y_SPEED.l = -45056; /* Line 435, Address: 0x1001b3c */
    return; /* Line 436, Address: 0x1001b4c */
  }
  if (iD0 < 9) /* Line 438, Address: 0x1001b54 */
  {
    pActwk->PAT_ADR = &flicky_tbl3; /* Line 440, Address: 0x1001b68 */
    pActwk->PAT_NO = 0; /* Line 441, Address: 0x1001b78 */
    pActwk->Y_SPEED.l = 57344; /* Line 442, Address: 0x1001b80 */
  }
} /* Line 444, Address: 0x1001b8c */

















void star_ctrl(sprite_status_lpl* pActwk) { /* Line 462, Address: 0x1001ba0 */
  star_acttbl[pActwk->EXE_NO](pActwk); /* Line 463, Address: 0x1001bac */
} /* Line 464, Address: 0x1001bd8 */











void starinit(sprite_status_lpl* pActwk) { /* Line 476, Address: 0x1001bf0 */
  pActwk->CGBASE += 16384; /* Line 477, Address: 0x1001bf8 */
  pActwk->PAT_NO = 0; /* Line 478, Address: 0x1001c08 */
  pActwk->PAT_ADR = &star_tbl; /* Line 479, Address: 0x1001c10 */
  pActwk->SPR_TIMER = star_tbl.aPatDat[0].timer; /* Line 480, Address: 0x1001c20 */

  pActwk->X_OFFSET = 0; /* Line 482, Address: 0x1001c30 */
  pActwk->Y_OFFSET = 0; /* Line 483, Address: 0x1001c38 */
  pActwk->EXE_NO = 1; /* Line 484, Address: 0x1001c40 */
} /* Line 485, Address: 0x1001c4c */











void starmove(sprite_status_lpl* pActwk) { /* Line 497, Address: 0x1001c60 */
  int_union lD0;

  if (killchk(pActwk) != 0) /* Line 500, Address: 0x1001c6c */
  {
    spr_kills(pActwk); /* Line 502, Address: 0x1001c88 */
    return; /* Line 503, Address: 0x1001c94 */
  }

  lD0.l = random() & 32767; /* Line 506, Address: 0x1001c9c */
  lD0.w.l = lD0.l % 40; /* Line 507, Address: 0x1001cac */
  pActwk->SIN_CNT += lD0.w.l; /* Line 508, Address: 0x1001cc8 */
  if (pActwk->SIN_CNT >= 511) /* Line 509, Address: 0x1001cdc */
    pActwk->SIN_CNT -= 511; /* Line 510, Address: 0x1001cf8 */
  pActwk->XPOSI.l += pActwk->X_SPEED.l; /* Line 511, Address: 0x1001d08 */
  pActwk->YPOSI.l += pActwk->Y_SPEED.l; /* Line 512, Address: 0x1001d20 */
} /* Line 513, Address: 0x1001d38 */



















void ufo_ctrl(sprite_status_lpl* pActwk) { /* Line 533, Address: 0x1001d50 */
  ufo_acttbl[pActwk->EXE_NO](pActwk); /* Line 534, Address: 0x1001d5c */
} /* Line 535, Address: 0x1001d88 */











void ufoinit(sprite_status_lpl* pActwk) { /* Line 547, Address: 0x1001da0 */
  int_union lD0, lD1;

  pActwk->CGBASE += 16384; /* Line 550, Address: 0x1001dac */
  pActwk->PAT_NO = 0; /* Line 551, Address: 0x1001dbc */
  pActwk->PAT_ADR = &ufo_tbl; /* Line 552, Address: 0x1001dc4 */
  pActwk->SPR_TIMER = ufo_tbl.aPatDat[0].timer; /* Line 553, Address: 0x1001dd4 */

  pActwk->X_OFFSET = 0; /* Line 555, Address: 0x1001de4 */
  pActwk->Y_OFFSET = 0; /* Line 556, Address: 0x1001dec */
  lD0.l = random() & 32767; /* Line 557, Address: 0x1001df4 */
  lD1.l = lD0.l; /* Line 558, Address: 0x1001e04 */
  lD0.w.l = lD0.l % 5 + 1; /* Line 559, Address: 0x1001e0c */
  pActwk->timer1 = lD0.w.l; /* Line 560, Address: 0x1001e2c */



  lD1.w.l = lD1.l % 64; /* Line 564, Address: 0x1001e3c */
  pActwk->timer2 = lD1.w.l; /* Line 565, Address: 0x1001e68 */

  pActwk->EXE_NO = 2; /* Line 567, Address: 0x1001e78 */
} /* Line 568, Address: 0x1001e84 */











void ufomode(sprite_status_lpl* pActwk) { /* Line 580, Address: 0x1001ea0 */
  if (pActwk->timer1 == 3) /* Line 581, Address: 0x1001eac */
  {
    umset1(pActwk); /* Line 583, Address: 0x1001ec4 */
  } /* Line 584, Address: 0x1001ed0 */
  else
  {
    uendset(pActwk); /* Line 587, Address: 0x1001ed8 */
    umset2(pActwk); /* Line 588, Address: 0x1001ee4 */
  }
  if ((char)pActwk->timer1 >= 0) /* Line 590, Address: 0x1001ef0 */
    --pActwk->timer1; /* Line 591, Address: 0x1001f10 */
} /* Line 592, Address: 0x1001f20 */











void uendset(sprite_status_lpl* pActwk) { /* Line 604, Address: 0x1001f30 */
  short iD1;
  int_union lD0;

  lD0.l = random() & 32767; /* Line 608, Address: 0x1001f40 */
  lD0.w.l = lD0.l % 32 + 64; /* Line 609, Address: 0x1001f50 */

  if (pActwk->SPR_FLG & 128) /* Line 611, Address: 0x1001f80 */
    iD1 = pActwk->XPOSI.w.h - lD0.w.l; /* Line 612, Address: 0x1001f98 */
  else
    iD1 = pActwk->XPOSI.w.h + lD0.w.l; /* Line 614, Address: 0x1001fd0 */
  pActwk->END_XPOSI = iD1; /* Line 615, Address: 0x1002000 */
} /* Line 616, Address: 0x1002008 */











void umset1(sprite_status_lpl* pActwk) { /* Line 628, Address: 0x1002020 */
  pActwk->EXE_NO = 2; /* Line 629, Address: 0x1002028 */
  pActwk->X_SPEED.l = 0; /* Line 630, Address: 0x1002034 */
  pActwk->Y_SPEED.l = 0; /* Line 631, Address: 0x100203c */
  pActwk->PAT_ADR = &ufo_tbl; /* Line 632, Address: 0x1002044 */
  pActwk->PAT_NO = 0; /* Line 633, Address: 0x1002054 */
  pActwk->timer2 = 24; /* Line 634, Address: 0x100205c */
} /* Line 635, Address: 0x1002068 */











void umset2(sprite_status_lpl* pActwk) { /* Line 647, Address: 0x1002080 */
  int_union lD0, lD1, lD7;

  pActwk->EXE_NO = 3; /* Line 650, Address: 0x100208c */
  lD0.l = random() & 32767; /* Line 651, Address: 0x1002098 */
  lD1.l = lD0.l; /* Line 652, Address: 0x10020a8 */
  lD0.w.h = lD0.l % 64; /* Line 653, Address: 0x10020b0 */
  lD0.w.l = 0; /* Line 654, Address: 0x10020dc */
  lD0.l >>=4; /* Line 655, Address: 0x10020e0 */
  lD0.l += 131072; /* Line 656, Address: 0x10020ec */
  pActwk->X_SPEED.l = lD0.l; /* Line 657, Address: 0x10020fc */

  if (!(pActwk->SPR_FLG & 8)) /* Line 659, Address: 0x1002108 */
    pActwk->X_SPEED.l = -pActwk->X_SPEED.l; /* Line 660, Address: 0x1002120 */

  lD7.l = pActwk->Y_SPEED.l; /* Line 662, Address: 0x1002144 */
  lD1.w.h = lD1.l % 96; /* Line 663, Address: 0x1002150 */
  lD1.w.l = 0; /* Line 664, Address: 0x100216c */
  lD1.l >>= 4; /* Line 665, Address: 0x1002170 */
  pActwk->Y_SPEED.l = lD1.l; /* Line 666, Address: 0x100217c */
  pActwk->Y_SPEED.w.h += 5; /* Line 667, Address: 0x1002188 */

  lD0.l = random() & 32767; /* Line 669, Address: 0x1002198 */
  lD0.w.l = lD0.l % 56; /* Line 670, Address: 0x10021a8 */

  if (lD7.l > 0) /* Line 672, Address: 0x10021c4 */
  {

    pActwk->Y_SPEED.l = -pActwk->Y_SPEED.l; /* Line 675, Address: 0x10021d0 */
    pActwk->END_YPOSI = lD0.w.l + 32; /* Line 676, Address: 0x10021f4 */

    pActwk->PAT_ADR = &ufo_tbl2; /* Line 678, Address: 0x1002214 */
    pActwk->PAT_NO = 0; /* Line 679, Address: 0x1002224 */
  } /* Line 680, Address: 0x100222c */
  else
  {

    pActwk->END_YPOSI = lD0.w.l + 160; /* Line 684, Address: 0x1002234 */

    pActwk->PAT_ADR = &ufo_tbl1; /* Line 686, Address: 0x1002254 */
    pActwk->PAT_NO = 0; /* Line 687, Address: 0x1002264 */
  }
} /* Line 689, Address: 0x100226c */











void ufomove2(sprite_status_lpl* pActwk) { /* Line 701, Address: 0x1002280 */
  int_union lD0, lD1;

  if (killchk(pActwk) != 0) /* Line 704, Address: 0x100228c */
  {
    spr_kills(pActwk); /* Line 706, Address: 0x10022a8 */
    return; /* Line 707, Address: 0x10022b4 */
  }
  lD0.l = pActwk->X_SPEED.l; /* Line 709, Address: 0x10022bc */
  if (music_selflg != 0) /* Line 710, Address: 0x10022c8 */
    lD0.l <<= 3; /* Line 711, Address: 0x10022dc */

  pActwk->XPOSI.l += lD0.l; /* Line 713, Address: 0x10022e8 */
  lD0.w.l = pActwk->XPOSI.w.h; /* Line 714, Address: 0x10022fc */

  if (pActwk->X_SPEED.l < 0) /* Line 716, Address: 0x1002308 */
  {
    if (lD0.w.l <= pActwk->END_XPOSI && (char)pActwk->timer1 >= 0) /* Line 718, Address: 0x1002318 */
      pActwk->EXE_NO = 1; /* Line 719, Address: 0x1002360 */
  } /* Line 720, Address: 0x100236c */
  else
  {
    if (lD0.w.l >= pActwk->END_XPOSI && (char)pActwk->timer1 >= 0) /* Line 723, Address: 0x1002374 */
      pActwk->EXE_NO = 1; /* Line 724, Address: 0x10023bc */
  }


  pActwk->YPOSI.l += pActwk->Y_SPEED.l; /* Line 728, Address: 0x10023c8 */


  lD1.w.l = pActwk->YPOSI.w.h; /* Line 731, Address: 0x10023e0 */

  if (pActwk->Y_SPEED.l < 0) /* Line 733, Address: 0x10023ec */
  {
    if (lD1.w.l <= pActwk->END_YPOSI && (char)pActwk->timer1 >= 0) /* Line 735, Address: 0x10023fc */
      pActwk->EXE_NO = 1; /* Line 736, Address: 0x1002444 */
  } /* Line 737, Address: 0x1002450 */
  else
  {
    if (lD1.w.l >= pActwk->END_YPOSI && (char)pActwk->timer1 >= 0) /* Line 740, Address: 0x1002458 */
      pActwk->EXE_NO = 1; /* Line 741, Address: 0x10024a0 */
  }
} /* Line 743, Address: 0x10024ac */











void ufomove1(sprite_status_lpl* pActwk) { /* Line 755, Address: 0x10024c0 */
  if ((long int)pActwk->X_SPEED.l == 0) /* Line 756, Address: 0x10024cc */
    pActwk->X_WIDE = 72; /* Line 757, Address: 0x10024e4 */
  else
    pActwk->X_WIDE = 40; /* Line 759, Address: 0x10024f8 */

  sinmove(pActwk); /* Line 761, Address: 0x1002504 */

  --pActwk->timer2; /* Line 763, Address: 0x1002510 */
  if (pActwk->timer2 <= 0) /* Line 764, Address: 0x1002520 */
    pActwk->EXE_NO = 1; /* Line 765, Address: 0x1002534 */
} /* Line 766, Address: 0x1002540 */
















void eggm_ctrl(sprite_status_lpl* pActwk) { /* Line 783, Address: 0x1002550 */
  eggm_acttbl[pActwk->EXE_NO](pActwk); /* Line 784, Address: 0x100255c */
} /* Line 785, Address: 0x1002588 */











void eggminit(sprite_status_lpl* pActwk) { /* Line 797, Address: 0x10025a0 */
  pActwk->CGBASE += 16384; /* Line 798, Address: 0x10025a8 */
  pActwk->PAT_NO = 0; /* Line 799, Address: 0x10025b8 */
  pActwk->PAT_ADR = &eggm_tbl; /* Line 800, Address: 0x10025c0 */
  pActwk->SPR_TIMER = eggm_tbl.aPatDat[0].timer; /* Line 801, Address: 0x10025d0 */

  pActwk->X_OFFSET = 0; /* Line 803, Address: 0x10025e0 */
  pActwk->Y_OFFSET = 0; /* Line 804, Address: 0x10025e8 */
  pActwk->timer1 = 3; /* Line 805, Address: 0x10025f0 */
  pActwk->EXE_NO = 1; /* Line 806, Address: 0x10025fc */
} /* Line 807, Address: 0x1002608 */











void eggmmove(sprite_status_lpl* pActwk) { /* Line 819, Address: 0x1002620 */
  int_union lD0, lD1;

  if (pActwk->timer1 > 0) /* Line 822, Address: 0x100262c */
  {
    if (--pActwk->timer1 > 0) /* Line 824, Address: 0x1002640 */
    {
      sinmove(pActwk); /* Line 826, Address: 0x1002660 */
      return; /* Line 827, Address: 0x100266c */
    }
    pActwk->PAT_ADR = &eggm_tbl; /* Line 829, Address: 0x1002674 */
  }

  lD0.l = random() & 32767; /* Line 832, Address: 0x1002684 */
  lD1.l = lD0.l; /* Line 833, Address: 0x1002694 */
  lD0.w.l = lD0.l % 16; /* Line 834, Address: 0x100269c */
  if (lD0.w.l == 0) /* Line 835, Address: 0x10026c8 */
  {
    lD1.w.l = lD1.l % 16 + 32; /* Line 837, Address: 0x10026dc */
    pActwk->timer1 = lD1.w.l; /* Line 838, Address: 0x100270c */
    pActwk->PAT_ADR = &eggm_tbl2; /* Line 839, Address: 0x100271c */
  }

  sinmove(pActwk); /* Line 842, Address: 0x100272c */
} /* Line 843, Address: 0x1002738 */



















void msnc_ctrl(sprite_status_lpl* pActwk) { /* Line 863, Address: 0x1002750 */
  msnc_acttbl[pActwk->EXE_NO](pActwk); /* Line 864, Address: 0x100275c */
} /* Line 865, Address: 0x1002788 */











void msncinit(sprite_status_lpl* pActwk) { /* Line 877, Address: 0x10027a0 */
  pActwk->CGBASE += 16384; /* Line 878, Address: 0x10027a8 */
  pActwk->PAT_NO = 0; /* Line 879, Address: 0x10027b8 */
  pActwk->PAT_ADR = &msnc_tbl; /* Line 880, Address: 0x10027c0 */
  pActwk->SPR_TIMER = msnc_tbl.aPatDat[0].timer; /* Line 881, Address: 0x10027d0 */
  pActwk->EXE_NO = 1; /* Line 882, Address: 0x10027e0 */
} /* Line 883, Address: 0x10027ec */











void msncstart(sprite_status_lpl* pActwk) { /* Line 895, Address: 0x1002800 */
  int_union lD0, lD1;

  if (killchk(pActwk) != 0) /* Line 898, Address: 0x100280c */
  {
    spr_kill(pActwk); /* Line 900, Address: 0x1002828 */
    return; /* Line 901, Address: 0x1002834 */
  }
  lD0.l = pActwk->X_SPEED.l; /* Line 903, Address: 0x100283c */
  lD1.l = pActwk->Y_SPEED.l; /* Line 904, Address: 0x1002848 */
  if (music_selflg != 0) /* Line 905, Address: 0x1002854 */
  {
    pActwk->X_SPEED.l = 1572864; /* Line 907, Address: 0x1002868 */
    pActwk->Y_SPEED.l = 0; /* Line 908, Address: 0x1002874 */
    if (pActwk->SPR_FLG & 128) /* Line 909, Address: 0x100287c */
      pActwk->X_SPEED.l = -pActwk->X_SPEED.l; /* Line 910, Address: 0x1002894 */
    pActwk->EXE_NO = 4; /* Line 911, Address: 0x10028b8 */
    return; /* Line 912, Address: 0x10028c4 */
  }

  pActwk->XPOSI.l += lD0.l; /* Line 915, Address: 0x10028cc */
  pActwk->YPOSI.l += lD1.l; /* Line 916, Address: 0x10028e0 */
  if (pActwk->SPR_FLG & 128) /* Line 917, Address: 0x10028f4 */
  {
    if (pActwk->XPOSI.w.h < 129) /* Line 919, Address: 0x100290c */
    {
      pActwk->XPOSI.w.h = 128; /* Line 921, Address: 0x1002928 */
      pActwk->X_SPEED.l = 0; /* Line 922, Address: 0x1002934 */
    }
  } /* Line 924, Address: 0x100293c */
  else
  {

    if (pActwk->XPOSI.w.h >= 128) /* Line 928, Address: 0x1002944 */
    {
      pActwk->XPOSI.w.h = 128; /* Line 930, Address: 0x1002960 */
      pActwk->X_SPEED.l = 0; /* Line 931, Address: 0x100296c */
    }
  }

  if (!(pActwk->SPR_FLG & 8)) /* Line 935, Address: 0x1002974 */
  {
    if (pActwk->YPOSI.w.h < 101) /* Line 937, Address: 0x100298c */
    {
      pActwk->YPOSI.w.h = 100; /* Line 939, Address: 0x10029a8 */
      pActwk->Y_SPEED.l = 0; /* Line 940, Address: 0x10029b4 */
    }
  } /* Line 942, Address: 0x10029bc */
  else
  {
    if (pActwk->YPOSI.w.h >= 100) /* Line 945, Address: 0x10029c4 */
    {
      pActwk->YPOSI.w.h = 100; /* Line 947, Address: 0x10029e0 */
      pActwk->Y_SPEED.l = 0; /* Line 948, Address: 0x10029ec */
    }
  }

  if (pActwk->XPOSI.w.h != 128) return; /* Line 952, Address: 0x10029f4 */
  if (pActwk->YPOSI.w.h != 100) return; /* Line 953, Address: 0x1002a10 */
  pActwk->timer1 = 64; /* Line 954, Address: 0x1002a2c */
  pActwk->timer2 = 8; /* Line 955, Address: 0x1002a38 */
  pActwk->EXE_NO = 2; /* Line 956, Address: 0x1002a44 */
} /* Line 957, Address: 0x1002a50 */











void msncfloat(sprite_status_lpl* pActwk) { /* Line 969, Address: 0x1002a60 */
  int_union lD0;

  if (music_selflg == 0) /* Line 972, Address: 0x1002a6c */
  {
    if ((char)pActwk->timer1 < 0) /* Line 974, Address: 0x1002a80 */
    {
      sinmove(pActwk); /* Line 976, Address: 0x1002aa0 */
      return; /* Line 977, Address: 0x1002aac */
    }
    if ((char)pActwk->timer2 == 0) /* Line 979, Address: 0x1002ab4 */
    {
      pActwk->timer2 = 24; /* Line 981, Address: 0x1002ad4 */
      lD0.l = (long int)(random() & 1); /* Line 982, Address: 0x1002ae0 */
      if (lD0.l == 0) pActwk->SPR_FLG &= 127; /* Line 983, Address: 0x1002b00 */
      else pActwk->SPR_FLG |= 128; /* Line 984, Address: 0x1002b24 */
    }
    --pActwk->timer2; /* Line 986, Address: 0x1002b34 */
    if ((char)--pActwk->timer1 >= 0) /* Line 987, Address: 0x1002b44 */
    {
      sinmove(pActwk); /* Line 989, Address: 0x1002b70 */
      return; /* Line 990, Address: 0x1002b7c */
    }
  }

  pActwk->timer1 = 48; /* Line 994, Address: 0x1002b84 */
  pActwk->X_WIDE = 256; /* Line 995, Address: 0x1002b90 */
  pActwk->Y_WIDE = 2; /* Line 996, Address: 0x1002b9c */
  pActwk->PAT_ADR = &msnc_tbl2; /* Line 997, Address: 0x1002ba8 */
  pActwk->PAT_NO = 0; /* Line 998, Address: 0x1002bb8 */
  pActwk->X_SPEED.l = -65536; /* Line 999, Address: 0x1002bc0 */
  if (pActwk->SPR_FLG & 128) /* Line 1000, Address: 0x1002bcc */
    pActwk->X_SPEED.l = (long int)-pActwk->X_SPEED.l; /* Line 1001, Address: 0x1002be4 */

  pActwk->EXE_NO = 3; /* Line 1003, Address: 0x1002c08 */
} /* Line 1004, Address: 0x1002c14 */











void msncdush(sprite_status_lpl* pActwk) { /* Line 1016, Address: 0x1002c30 */
  if (music_selflg == 0) /* Line 1017, Address: 0x1002c3c */
  {
    if ((char)--pActwk->timer1 > 0) /* Line 1019, Address: 0x1002c50 */
    {
      sinmove(pActwk); /* Line 1021, Address: 0x1002c7c */
      return; /* Line 1022, Address: 0x1002c88 */
    }
  }

  pActwk->X_WIDE = 0; /* Line 1026, Address: 0x1002c90 */
  pActwk->Y_WIDE = 0; /* Line 1027, Address: 0x1002c98 */
  pActwk->X_SPEED.l = 1572864; /* Line 1028, Address: 0x1002ca0 */
  if (pActwk->SPR_FLG & 128) /* Line 1029, Address: 0x1002cac */
    pActwk->X_SPEED.l = -pActwk->X_SPEED.l; /* Line 1030, Address: 0x1002cc4 */
  pActwk->EXE_NO = 4; /* Line 1031, Address: 0x1002ce8 */
} /* Line 1032, Address: 0x1002cf4 */











void msncexit(sprite_status_lpl* pActwk) { /* Line 1044, Address: 0x1002d10 */
  int_union lD0, lD1;

  if (killchk(pActwk) != 0) /* Line 1047, Address: 0x1002d1c */
  {
    spr_kill(pActwk); /* Line 1049, Address: 0x1002d38 */
    return; /* Line 1050, Address: 0x1002d44 */
  }
  lD0.l = pActwk->X_SPEED.l; /* Line 1052, Address: 0x1002d4c */
  lD1.l = pActwk->Y_SPEED.l; /* Line 1053, Address: 0x1002d58 */
  if (music_selflg != 0) /* Line 1054, Address: 0x1002d64 */
  {
    lD0.l *= 2; /* Line 1056, Address: 0x1002d78 */
    lD1.l *= 2; /* Line 1057, Address: 0x1002d84 */
  }
  pActwk->XPOSI.l += lD0.l; /* Line 1059, Address: 0x1002d90 */
  pActwk->YPOSI.l += lD1.l; /* Line 1060, Address: 0x1002da4 */
} /* Line 1061, Address: 0x1002db8 */


















void tails_ctrl(sprite_status_lpl* pActwk) { /* Line 1080, Address: 0x1002dd0 */
  tails_acttbl[pActwk->EXE_NO](pActwk); /* Line 1081, Address: 0x1002ddc */
} /* Line 1082, Address: 0x1002e08 */











void tailsinit(sprite_status_lpl* pActwk) { /* Line 1094, Address: 0x1002e20 */
  int_union lD0, lD1;

  pActwk->CGBASE += 16384; /* Line 1097, Address: 0x1002e2c */
  pActwk->PAT_NO = 0; /* Line 1098, Address: 0x1002e3c */
  pActwk->PAT_ADR = &tails_tbl; /* Line 1099, Address: 0x1002e44 */
  pActwk->SPR_TIMER = tails_tbl.aPatDat[0].timer; /* Line 1100, Address: 0x1002e54 */

  lD0.l = random() & 32767; /* Line 1102, Address: 0x1002e64 */
  lD1.l = lD0.l; /* Line 1103, Address: 0x1002e74 */
  lD0.w.l = lD0.l % 5 + 1; /* Line 1104, Address: 0x1002e7c */
  pActwk->timer1 = lD0.w.l; /* Line 1105, Address: 0x1002e9c */
  lD1.w.l = lD1.l % 48; /* Line 1106, Address: 0x1002eac */
  pActwk->timer2 = lD1.w.l; /* Line 1107, Address: 0x1002ec8 */
  pActwk->EXE_NO = 2; /* Line 1108, Address: 0x1002ed8 */
} /* Line 1109, Address: 0x1002ee4 */











void tailsmove(sprite_status_lpl* pActwk) { /* Line 1121, Address: 0x1002f00 */
  uendset(pActwk); /* Line 1122, Address: 0x1002f0c */
  if (pActwk->timer1 == 3) /* Line 1123, Address: 0x1002f18 */
    tsset1(pActwk); /* Line 1124, Address: 0x1002f30 */
  else
    tsset2(pActwk); /* Line 1126, Address: 0x1002f44 */
  if ((char)pActwk->timer1 >= 0) /* Line 1127, Address: 0x1002f50 */
    --pActwk->timer1; /* Line 1128, Address: 0x1002f70 */
} /* Line 1129, Address: 0x1002f80 */











void tsset1(sprite_status_lpl* pActwk) { /* Line 1141, Address: 0x1002f90 */
  pActwk->X_SPEED.l = 131072; /* Line 1142, Address: 0x1002f98 */
  pActwk->Y_SPEED.l = 0; /* Line 1143, Address: 0x1002fa4 */
  pActwk->PAT_NO = 0; /* Line 1144, Address: 0x1002fac */
  pActwk->PAT_ADR = &tails_tbl; /* Line 1145, Address: 0x1002fb4 */
  if (pActwk->SPR_FLG & 128) /* Line 1146, Address: 0x1002fc4 */
  {
    pActwk->X_SPEED.l = -pActwk->X_SPEED.l; /* Line 1148, Address: 0x1002fdc */
    pActwk->Y_SPEED.l = -pActwk->Y_SPEED.l; /* Line 1149, Address: 0x1003000 */
  }

  pActwk->timer2 = 24; /* Line 1152, Address: 0x1003024 */
  pActwk->EXE_NO = 2; /* Line 1153, Address: 0x1003030 */
} /* Line 1154, Address: 0x100303c */











void tsset2(sprite_status_lpl* pActwk) { /* Line 1166, Address: 0x1003050 */
  int_union lD0, lD1, lD7;

  pActwk->EXE_NO = 3; /* Line 1169, Address: 0x100305c */
  lD0.l = random() & 32767; /* Line 1170, Address: 0x1003068 */
  lD1.l = lD0.l; /* Line 1171, Address: 0x1003078 */
  lD0.w.h = lD0.l % 16; /* Line 1172, Address: 0x1003080 */
  lD0.w.l = 0; /* Line 1173, Address: 0x10030ac */
  lD0.l >>= 4; /* Line 1174, Address: 0x10030b0 */
  lD0.l += 131072; /* Line 1175, Address: 0x10030bc */
  pActwk->X_SPEED.l = lD0.l; /* Line 1176, Address: 0x10030cc */
  if (pActwk->SPR_FLG & 128) /* Line 1177, Address: 0x10030d8 */
    pActwk->X_SPEED.l = -pActwk->X_SPEED.l; /* Line 1178, Address: 0x10030f0 */

  lD7.l = pActwk->Y_SPEED.l; /* Line 1180, Address: 0x1003114 */
  lD1.w.h = lD1.l % 40; /* Line 1181, Address: 0x1003120 */
  lD1.w.l = 0; /* Line 1182, Address: 0x100313c */
  lD1.l >>= 4; /* Line 1183, Address: 0x1003140 */
  pActwk->Y_SPEED.l = lD1.l; /* Line 1184, Address: 0x100314c */
  ++pActwk->Y_SPEED.w.h; /* Line 1185, Address: 0x1003158 */

  lD0.l = random() & 32767; /* Line 1187, Address: 0x1003168 */
  lD0.w.l = lD0.l % 56; /* Line 1188, Address: 0x1003178 */

  if (lD7.l == 0) /* Line 1190, Address: 0x1003194 */
  {
    if (pActwk->YPOSI.w.h >= 101) goto label1; else goto label2; /* Line 1192, Address: 0x10031a0 */
  }

  if (lD7.l > 0) /* Line 1195, Address: 0x10031c4 */
  {
label1:
    pActwk->Y_SPEED.l = (long int)-pActwk->Y_SPEED.l; /* Line 1198, Address: 0x10031d0 */
    pActwk->END_YPOSI = lD0.w.h + 32; /* Line 1199, Address: 0x10031f4 */
    pActwk->PAT_ADR = &tails_down_tbl; /* Line 1200, Address: 0x1003214 */
    pActwk->PAT_NO = 0; /* Line 1201, Address: 0x1003224 */
    return; /* Line 1202, Address: 0x100322c */
  }

label2:
  pActwk->END_YPOSI = lD0.w.l + 160; /* Line 1206, Address: 0x1003234 */
  pActwk->PAT_ADR = &tails_up_tbl; /* Line 1207, Address: 0x1003254 */
  pActwk->PAT_NO = 0; /* Line 1208, Address: 0x1003264 */

} /* Line 1210, Address: 0x100326c */











void tailsmove1(sprite_status_lpl* pActwk) { /* Line 1222, Address: 0x1003280 */
  sinmove(pActwk); /* Line 1223, Address: 0x100328c */
  if ((char)--pActwk->timer2 <= 0) /* Line 1224, Address: 0x1003298 */
    pActwk->EXE_NO = 1; /* Line 1225, Address: 0x10032c4 */
} /* Line 1226, Address: 0x10032d0 */
