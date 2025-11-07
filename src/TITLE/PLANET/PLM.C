#include "..\..\TYPES.H"
#include "LPL_TYPES.H"
#include "SPM_EQU.H"
#include "PLM.H"
#include "ACTM.H"
#include "ETC.H"

static short fpat0[8] = { 0, 0, -24, 8, -48, -8, -34, 20 };
static short fpat1[8] = { 0, 0, -16, -24, -16, 24, -32, 0 };
static short fpat2[12] = { 0, 0, -16, -22, -40, -28, -32, 16, -16, 24, -48, -5 };
static ini_pats flick_ini_tbl[4] =
{
  { 4, fpat0 },
  { 4, fpat1 },
  { 6, fpat2 },
  { 6, fpat2 }
};
static short spat0[6] = { 0, 0, 32, 0, -32, 0 };
static ini_pats star_ini_tbl[5] =
{
  { 3, spat0 },
  { 3, spat0 },
  { 2, spat0 },
  { 1, spat0 },
  { 3, spat0 }
};
static short upat0[4] = { 0, 0, 16, 48 };
static ini_pats ufo_ini_tbl[5] =
{
  { 1, upat0 },
  { 2, upat0 },
  { 1, upat0 },
  { 2, upat0 },
  { 1, upat0 }
};
void(*sprinit_tbl[6])(void) =
{
  &flick_set,
  &star_set,
  &ufo_set,
  &eggman_set,
  &metals_set,
  &tails_set
};
short actset_tbl[12] =
{
  300, 600,
  360, 660,
  420, 720,
  480, 780,
  540, 840,
  600, 900
};
extern sprite_patterns_title flicky_tbl;
extern sprite_patterns_title flicky_tbl1;
extern sprite_patterns_title flicky_tbl3;


















































































void sprinit(void) { /* Line 139, Address: 0x10070c0 */
  int_union lD0;
  short i, iD0, iD5;

  if (!(music_selflg & 1)) /* Line 143, Address: 0x10070d4 */
  {

    for (i = 0; i < 6; ++i) /* Line 146, Address: 0x10070ec */
    {
      if (--actset_tm[i] < 0) /* Line 148, Address: 0x10070f8 */
      {
        iD5 = 5 - i; /* Line 150, Address: 0x1007134 */
        iD0 = iD5; /* Line 151, Address: 0x1007154 */
        iD0 += iD0; /* Line 152, Address: 0x100715c */
        actset_tm[i] = actset_tbl[iD0]; /* Line 153, Address: 0x1007168 */

        lD0.l = random() & 65535; /* Line 155, Address: 0x10071a0 */
        lD0.w.l = lD0.l % actset_tbl[iD0 + 1]; /* Line 156, Address: 0x10071b0 */
        actset_tm[i] += lD0.w.l; /* Line 157, Address: 0x10071fc */

        sprinit_tbl[iD5](); /* Line 159, Address: 0x1007224 */
        break; /* Line 160, Address: 0x1007248 */
      }
    } /* Line 162, Address: 0x1007250 */
  }

} /* Line 165, Address: 0x1007270 */












void flick_set(void) { /* Line 178, Address: 0x1007290 */
  short i;
  short iD3, iD5, iD6, iD7;
  sprite_status_lpl* pActwk;
  int_union lD0;
  ini_pats* pFoffset;

  if (!(actset_flg & 1)) /* Line 185, Address: 0x10072b0 */
  {

    actset_flg |= 1; /* Line 188, Address: 0x10072c8 */
    actset_wk = 1; /* Line 189, Address: 0x10072dc */
  } /* Line 190, Address: 0x10072e8 */
  else if (!(actset_flg & 2)) /* Line 191, Address: 0x10072f0 */
  {

    actset_flg |= 2; /* Line 194, Address: 0x1007308 */
    actset_wk = 2; /* Line 195, Address: 0x100731c */
  } /* Line 196, Address: 0x1007328 */
  else
    return; /* Line 198, Address: 0x1007330 */

  lD0.l = random(); /* Line 200, Address: 0x1007338 */
  iD7 = lD0.w.l; /* Line 201, Address: 0x1007344 */

  if (iD7 < 0) /* Line 203, Address: 0x1007350 */
    iD5 = 328; /* Line 204, Address: 0x1007360 */
  else
    iD5 = -6; /* Line 206, Address: 0x1007374 */

  lD0.l = random() & 32767; /* Line 208, Address: 0x1007380 */
  lD0.w.l = lD0.l % 160; /* Line 209, Address: 0x1007390 */
  iD6 = lD0.w.l + 16; /* Line 210, Address: 0x10073ac */


  lD0.l = iD7 & 32767; /* Line 213, Address: 0x10073cc */
  lD0.w.l = lD0.l % 4; /* Line 214, Address: 0x10073dc */
  pFoffset = &flick_ini_tbl[lD0.w.l]; /* Line 215, Address: 0x1007408 */

  if (actset_wk & 1) /* Line 217, Address: 0x1007424 */
    iD3 = 0; /* Line 218, Address: 0x100743c */
  else
    iD3 = 1; /* Line 220, Address: 0x1007448 */

  for (i = 0; i < flick_ini_tbl[lD0.w.l].number; ++i) /* Line 222, Address: 0x1007454 */
  {
    if (get_actwk(&pActwk) != 0) break; /* Line 224, Address: 0x1007460 */



    f_actset(pActwk, pFoffset, iD5, iD6, iD7, i, flick_ini_tbl[lD0.w.l].number - 1); /* Line 228, Address: 0x1007474 */
  } /* Line 229, Address: 0x10074c8 */
  actset_wk = 0; /* Line 230, Address: 0x1007510 */
} /* Line 231, Address: 0x1007518 */























void f_actset(sprite_status_lpl* pActwk, ini_pats* pFoffset, short initx, short inity, short iReverse, short iNormal, short max) { /* Line 255, Address: 0x1007540 */
  int_union lD0;
  short iD0;

  pActwk->CGBASE = 0; /* Line 259, Address: 0x1007568 */
  pActwk->ACT_FLG = actset_wk; /* Line 260, Address: 0x1007570 */
  pActwk->XPOSI.w.h = initx; /* Line 261, Address: 0x1007580 */
  pActwk->YPOSI.w.h = inity; /* Line 262, Address: 0x100758c */
  pActwk->X_WIDE = 48; /* Line 263, Address: 0x1007598 */
  pActwk->Y_WIDE = 4; /* Line 264, Address: 0x10075a4 */



  if (iNormal != max) goto label1; /* Line 268, Address: 0x10075b0 */ // 76a8

  lD0.l = random() & 32767; /* Line 270, Address: 0x10075d0 */
  lD0.w.l = lD0.l % 3; /* Line 271, Address: 0x10075e0 */
  if (lD0.w.l != 0) /* Line 272, Address: 0x10075fc */ // 76a8
  {
    if (lD0.w.l != 1) /* Line 274, Address: 0x1007610 */ // 766c
    {

      pActwk->SPR_FLG |= 2; /* Line 277, Address: 0x1007628 */
      pActwk->X_SPEED.l = 81920; /* Line 278, Address: 0x1007638 */
      pActwk->Y_SPEED.l = 57344; /* Line 279, Address: 0x1007648 */
      pActwk->PAT_ADR = &flicky_tbl3; /* Line 280, Address: 0x1007654 */
    } /* Line 281, Address: 0x1007664 */ // 76d0
    else
    {

      pActwk->SPR_FLG |= 1; /* Line 285, Address: 0x100766c */
      pActwk->X_SPEED.l = 40960; /* Line 286, Address: 0x100767c */
      pActwk->Y_SPEED.l = 0; /* Line 287, Address: 0x1007688 */
      pActwk->PAT_ADR = &flicky_tbl1; /* Line 288, Address: 0x1007690 */
    }
  } /* Line 290, Address: 0x10076a0 */ // 76d0
  else
  {
label1:
    pActwk->X_SPEED.l = 81920; /* Line 294, Address: 0x10076a8 */
    pActwk->Y_SPEED.l = 0; /* Line 295, Address: 0x10076b8 */
    pActwk->PAT_ADR = &flicky_tbl; /* Line 296, Address: 0x10076c0 */
  }

  pActwk->SPR_TIMER = pActwk->PAT_ADR->aPatDat[0].timer; /* Line 299, Address: 0x10076d0 */

  pActwk->SPR_FLG |= 8; /* Line 301, Address: 0x10076e4 */
  pActwk->ACT_NO = 1; /* Line 302, Address: 0x10076f4 */
  iD0 = pFoffset->inipat[iNormal * 2]; /* Line 303, Address: 0x1007700 */
  if (iReverse < 0) /* Line 304, Address: 0x100772c */
  {
    pActwk->SPR_FLG |= 128; /* Line 306, Address: 0x1007740 */
    pActwk->SPR_FLG &= 247; /* Line 307, Address: 0x1007750 */
    iD0 = -iD0; /* Line 308, Address: 0x1007760 */
    pActwk->X_SPEED.l = -(long int)pActwk->X_SPEED.l; /* Line 309, Address: 0x100777c */
  }
  pActwk->XPOSI.w.h += iD0; /* Line 311, Address: 0x10077a0 */
  pActwk->YPOSI.w.h += pFoffset->inipat[iNormal * 2 + 1]; /* Line 312, Address: 0x10077b0 */
} /* Line 313, Address: 0x10077e8 */











void star_set(void) { /* Line 325, Address: 0x1007800 */
  short i, iD1, iD3, iD5, iD6, iD7;
  int_union lD0;
  sprite_status_lpl* pActwk;
  ini_pats* pSoffset;

  if (colorno <= 10) return; /* Line 331, Address: 0x1007824 */
  if (colorno >= 24) return; /* Line 332, Address: 0x1007840 */


  if (!(actset_flg & 1)) /* Line 335, Address: 0x100785c */
  {

    actset_flg |= 1; /* Line 338, Address: 0x1007874 */
    actset_wk = 1; /* Line 339, Address: 0x1007888 */
  } /* Line 340, Address: 0x1007894 */
  else if (!(actset_flg & 2)) /* Line 341, Address: 0x100789c */
  {

    actset_flg |= 2; /* Line 344, Address: 0x10078b4 */
    actset_wk = 2; /* Line 345, Address: 0x10078c8 */
  } /* Line 346, Address: 0x10078d4 */
  else
    return; /* Line 348, Address: 0x10078dc */

  lD0.l = random(); /* Line 350, Address: 0x10078e4 */
  iD7 = lD0.w.l; /* Line 351, Address: 0x10078f0 */
  iD3 = 0; /* Line 352, Address: 0x10078fc */

  lD0.l = random() & 32767; /* Line 354, Address: 0x1007900 */
  lD0.w.l = lD0.l % 128; /* Line 355, Address: 0x1007910 */
  iD5 = lD0.w.l; /* Line 356, Address: 0x100793c */

  if (iD5 <= 128) /* Line 358, Address: 0x1007948 */
    iD3 = 1; /* Line 359, Address: 0x100795c */

  iD6 = 0; /* Line 361, Address: 0x1007968 */
  if (actset_wk & 1) /* Line 362, Address: 0x100796c */
    iD1 = 0; /* Line 363, Address: 0x1007984 */
  else
    iD1 = 1; /* Line 365, Address: 0x1007990 */

  lD0.l = iD7 & 32767; /* Line 367, Address: 0x100799c */
  lD0.w.l = lD0.l % 5; /* Line 368, Address: 0x10079ac */
  pSoffset = &star_ini_tbl[lD0.w.l]; /* Line 369, Address: 0x10079c8 */


  for (i = 0; i < star_ini_tbl[lD0.w.l].number; ++i) /* Line 372, Address: 0x10079e4 */
  {
    if (get_actwk(&pActwk) != 0) break; /* Line 374, Address: 0x10079f0 */

    s_actset(pActwk, pSoffset, iD3, iD5, iD6, i); /* Line 376, Address: 0x1007a04 */
  } /* Line 377, Address: 0x1007a24 */
  actset_wk = 0; /* Line 378, Address: 0x1007a6c */
} /* Line 379, Address: 0x1007a74 */


















void s_actset(sprite_status_lpl* pActwk, ini_pats* pSoffset, short iD3, short iD5, short iD6, short i) { /* Line 398, Address: 0x1007aa0 */
  int_union lD0;

  pActwk->ACT_NO = 2; /* Line 401, Address: 0x1007ac0 */
  pActwk->CGBASE = 0; /* Line 402, Address: 0x1007acc */
  pActwk->ACT_FLG = actset_wk; /* Line 403, Address: 0x1007ad4 */

  pActwk->XPOSI.w.h = iD5; /* Line 405, Address: 0x1007ae4 */
  pActwk->YPOSI.w.h = iD6; /* Line 406, Address: 0x1007af0 */

  pActwk->X_SPEED.l = 0x20000; /* Line 408, Address: 0x1007afc */
  if (iD3 != 0) /* Line 409, Address: 0x1007b08 */
    pActwk->X_SPEED.l = -0x20000; /* Line 410, Address: 0x1007b1c */
  lD0.l = random() & 32767; /* Line 411, Address: 0x1007b28 */
  lD0.w.h = lD0.l % 128; /* Line 412, Address: 0x1007b38 */
  lD0.l &= 2147418112; /* Line 413, Address: 0x1007b64 */
  lD0.l >>= 4; /* Line 414, Address: 0x1007b74 */
  pActwk->Y_SPEED.l = lD0.l + 0x40000; /* Line 415, Address: 0x1007b80 */

  lD0.l = random() & 32767; /* Line 417, Address: 0x1007b94 */


  lD0.w.l = lD0.l % 240; /* Line 420, Address: 0x1007ba4 */

  pActwk->XPOSI.w.h += lD0.w.l; /* Line 422, Address: 0x1007bc0 */



  pActwk->YPOSI.w.h += pSoffset->inipat[i]; /* Line 426, Address: 0x1007bd4 */
} /* Line 427, Address: 0x1007c04 */











void ufo_set(void) { /* Line 439, Address: 0x1007c20 */
  sprite_status_lpl* pActwk;
  ini_pats* pUoffset;
  int_union lD0;
  short i;
  short iD1, iD5, iD6, iD7;
  short iNum;

  if (!(actset_flg & 1)) /* Line 447, Address: 0x1007c44 */
  {

    actset_flg |= 1; /* Line 450, Address: 0x1007c5c */
    actset_wk = 1; /* Line 451, Address: 0x1007c70 */
  } /* Line 452, Address: 0x1007c7c */
  else if (!(actset_flg & 2)) /* Line 453, Address: 0x1007c84 */
  {

    actset_flg |= 2; /* Line 456, Address: 0x1007c9c */
    actset_wk = 2; /* Line 457, Address: 0x1007cb0 */
  } /* Line 458, Address: 0x1007cbc */
  else
    return; /* Line 460, Address: 0x1007cc4 */

  lD0.l = random(); /* Line 462, Address: 0x1007ccc */
  iD7 = lD0.w.l; /* Line 463, Address: 0x1007cd8 */


  if (iD7 < 0) /* Line 466, Address: 0x1007ce4 */
    iD5 = 328; /* Line 467, Address: 0x1007cf4 */
  else
    iD5 = -6; /* Line 469, Address: 0x1007d08 */

  lD0.l = random() & 32767; /* Line 471, Address: 0x1007d14 */
  lD0.w.l = lD0.l % 160; /* Line 472, Address: 0x1007d24 */
  iD6 = lD0.w.l + 16; /* Line 473, Address: 0x1007d40 */

  if (actset_wk & 1) /* Line 475, Address: 0x1007d60 */
    iD1 = 0; /* Line 476, Address: 0x1007d78 */
  else
    iD1 = 1; /* Line 478, Address: 0x1007d84 */

  lD0.l = iD7 & 32767; /* Line 480, Address: 0x1007d90 */
  lD0.w.l = lD0.l % 5; /* Line 481, Address: 0x1007da0 */

  pUoffset = &ufo_ini_tbl[lD0.w.l]; /* Line 483, Address: 0x1007dbc */
  iNum = pUoffset->number; /* Line 484, Address: 0x1007dd8 */

  for (i = 0; i < iNum; ++i) /* Line 486, Address: 0x1007de4 */
  {
    if (get_actwk(&pActwk) != 0) break; /* Line 488, Address: 0x1007df0 */

    pActwk->CGBASE = 0; /* Line 490, Address: 0x1007e04 */
    pActwk->ACT_FLG = actset_wk; /* Line 491, Address: 0x1007e0c */
    pActwk->XPOSI.w.h = iD5; /* Line 492, Address: 0x1007e1c */
    pActwk->YPOSI.w.h = iD6; /* Line 493, Address: 0x1007e24 */

    pActwk->X_WIDE = 40; /* Line 495, Address: 0x1007e2c */
    pActwk->Y_WIDE = 6; /* Line 496, Address: 0x1007e38 */

    pActwk->X_SPEED.l = 0x20000; /* Line 498, Address: 0x1007e44 */
    pActwk->Y_SPEED.l = 0; /* Line 499, Address: 0x1007e50 */
    pActwk->SPR_FLG |= 8; /* Line 500, Address: 0x1007e58 */

    pActwk->ACT_NO = 4; /* Line 502, Address: 0x1007e68 */
    lD0.w.l = pUoffset->inipat[i * 2]; /* Line 503, Address: 0x1007e74 */
    if (iD7 < 0) /* Line 504, Address: 0x1007e94 */
    {
      pActwk->SPR_FLG |= 128; /* Line 506, Address: 0x1007ea4 */
      pActwk->SPR_FLG &= 247; /* Line 507, Address: 0x1007eb4 */
      lD0.w.l = -lD0.w.l; /* Line 508, Address: 0x1007ec4 */
      pActwk->X_SPEED.l = -(long int)pActwk->X_SPEED.l; /* Line 509, Address: 0x1007ee0 */
      pActwk->Y_SPEED.l = -(long int)pActwk->Y_SPEED.l; /* Line 510, Address: 0x1007f04 */
    }

    pActwk->XPOSI.w.h += lD0.w.l; /* Line 513, Address: 0x1007f28 */
    pActwk->YPOSI.w.h += pUoffset->inipat[i * 2 + 1]; /* Line 514, Address: 0x1007f3c */
  } /* Line 515, Address: 0x1007f6c */
  actset_wk = 0; /* Line 516, Address: 0x1007f94 */
} /* Line 517, Address: 0x1007f9c */











void eggman_set(void) { /* Line 529, Address: 0x1007fd0 */
  sprite_status_lpl* pActwk;
  int_union lD0;
  short iD5, iD6;
  short iD7;

  if (actset_flg & 3) return; /* Line 535, Address: 0x1007fe4 */
  actset_flg |= 3; /* Line 536, Address: 0x1007ffc */
  actset_wk = 3; /* Line 537, Address: 0x1008010 */

  iD7 = random(); /* Line 539, Address: 0x100801c */


  if (iD7 < 0) /* Line 542, Address: 0x1008034 */
    iD5 = -6; /* Line 543, Address: 0x1008044 */
  else
    iD5 = 328; /* Line 545, Address: 0x1008058 */
  lD0.l = random() & 32767; /* Line 546, Address: 0x1008064 */
  iD6 = lD0.l % 64; /* Line 547, Address: 0x1008074 */
  iD6 += 128; /* Line 548, Address: 0x10080a4 */


  if (get_actwk(&pActwk) == 0) /* Line 551, Address: 0x10080b0 */
  {
    pActwk->CGBASE = 0; /* Line 553, Address: 0x10080c4 */
    pActwk->ACT_FLG = actset_wk; /* Line 554, Address: 0x10080cc */
    pActwk->XPOSI.w.h = iD5; /* Line 555, Address: 0x10080dc */
    pActwk->YPOSI.w.h = iD6; /* Line 556, Address: 0x10080e4 */
    pActwk->X_WIDE = 40; /* Line 557, Address: 0x10080ec */
    pActwk->Y_WIDE = 10; /* Line 558, Address: 0x10080f8 */
    pActwk->X_SPEED.l = -81920; /* Line 559, Address: 0x1008104 */
    pActwk->Y_SPEED.l = -32768; /* Line 560, Address: 0x1008114 */

    pActwk->ACT_NO = 3; /* Line 562, Address: 0x1008120 */
    if (iD7 < 0) /* Line 563, Address: 0x100812c */
    {
      pActwk->SPR_FLG |= 128; /* Line 565, Address: 0x100813c */
      pActwk->X_SPEED.l *= -1; /* Line 566, Address: 0x100814c */
    }
  }
  actset_wk = 0; /* Line 569, Address: 0x100815c */
} /* Line 570, Address: 0x1008164 */











void metals_set(void) { /* Line 582, Address: 0x1008180 */
  sprite_status_lpl* pActwk;
  int_union lD0;
  short iD5, iD6;
  short iD7;

  if (actset_flg & 3) return; /* Line 588, Address: 0x1008194 */
  actset_flg |= 3; /* Line 589, Address: 0x10081ac */
  actset_wk = 3; /* Line 590, Address: 0x10081c0 */

  iD7 = random(); /* Line 592, Address: 0x10081cc */


  lD0.l = random() & 32767; /* Line 595, Address: 0x10081e4 */
  iD5 = lD0.l % 256; /* Line 596, Address: 0x10081f4 */

  if (iD7 < 0) /* Line 598, Address: 0x1008224 */
    iD6 = 0; /* Line 599, Address: 0x1008234 */
  else
    iD6 = 192; /* Line 601, Address: 0x1008240 */



  if (get_actwk(&pActwk) == 0) /* Line 605, Address: 0x100824c */
  {
    pActwk->CGBASE = 0; /* Line 607, Address: 0x1008260 */
    pActwk->ACT_FLG = actset_wk; /* Line 608, Address: 0x1008268 */
    pActwk->XPOSI.w.h = iD5; /* Line 609, Address: 0x1008278 */
    pActwk->YPOSI.w.h = iD6; /* Line 610, Address: 0x1008280 */
    pActwk->X_WIDE = 40; /* Line 611, Address: 0x1008288 */
    pActwk->Y_WIDE = 4; /* Line 612, Address: 0x1008294 */
    pActwk->X_SPEED.l = 0x40000; /* Line 613, Address: 0x10082a0 */
    pActwk->Y_SPEED.l = 327680; /* Line 614, Address: 0x10082ac */
    pActwk->SPR_FLG |= 8; /* Line 615, Address: 0x10082b8 */

    pActwk->ACT_NO = 5; /* Line 617, Address: 0x10082c8 */

    if (pActwk->XPOSI.w.h >= 128) /* Line 619, Address: 0x10082d4 */
    {
      pActwk->SPR_FLG |= 128; /* Line 621, Address: 0x10082f0 */
      pActwk->X_SPEED.l = -(long int)pActwk->X_SPEED.l; /* Line 622, Address: 0x1008300 */
    }

    if (pActwk->YPOSI.w.h >= 100) /* Line 625, Address: 0x1008324 */
    {
      pActwk->SPR_FLG &= 247; /* Line 627, Address: 0x1008340 */
      pActwk->Y_SPEED.l = -(long int)pActwk->Y_SPEED.l; /* Line 628, Address: 0x1008350 */
    }
  }
  actset_wk = 0; /* Line 631, Address: 0x1008374 */
} /* Line 632, Address: 0x100837c */











void tails_set(void) { /* Line 644, Address: 0x10083a0 */
  sprite_status_lpl* pActwk;
  int_union lD0;
  short iD5, iD6;
  short iD7;

  if (actset_flg & 3) return; /* Line 650, Address: 0x10083b4 */
  actset_flg |= 3; /* Line 651, Address: 0x10083cc */
  actset_wk = 3; /* Line 652, Address: 0x10083e0 */

  iD7 = random(); /* Line 654, Address: 0x10083ec */


  if (iD7 < 0) /* Line 657, Address: 0x1008404 */
    iD5 = 328; /* Line 658, Address: 0x1008414 */
  else
    iD5 = -6; /* Line 660, Address: 0x1008428 */

  lD0.l = random() & 32767; /* Line 662, Address: 0x1008434 */
  iD6 = lD0.l % 160; /* Line 663, Address: 0x1008444 */
  iD6 += 32; /* Line 664, Address: 0x1008464 */


  if (get_actwk(&pActwk) == 0) /* Line 667, Address: 0x1008470 */
  {
    pActwk->CGBASE = 0; /* Line 669, Address: 0x1008484 */
    pActwk->ACT_FLG = actset_wk; /* Line 670, Address: 0x100848c */
    pActwk->XPOSI.w.h = iD5; /* Line 671, Address: 0x100849c */
    pActwk->YPOSI.w.h = iD6; /* Line 672, Address: 0x10084a4 */
    pActwk->X_WIDE = 36; /* Line 673, Address: 0x10084ac */
    pActwk->Y_WIDE = 2; /* Line 674, Address: 0x10084b8 */
    pActwk->X_SPEED.l = 0x20000; /* Line 675, Address: 0x10084c4 */
    pActwk->Y_SPEED.l = 0; /* Line 676, Address: 0x10084d0 */

    pActwk->ACT_NO = 6; /* Line 678, Address: 0x10084d8 */
    if (iD7 < 0) /* Line 679, Address: 0x10084e4 */
    {
      pActwk->SPR_FLG |= 128; /* Line 681, Address: 0x10084f4 */
      pActwk->X_SPEED.l = -(long int)pActwk->X_SPEED.l; /* Line 682, Address: 0x1008504 */
      pActwk->Y_SPEED.l = -(long int)pActwk->Y_SPEED.l; /* Line 683, Address: 0x1008528 */
    }
  }
  actset_wk = 0; /* Line 686, Address: 0x100854c */
} /* Line 687, Address: 0x1008554 */
