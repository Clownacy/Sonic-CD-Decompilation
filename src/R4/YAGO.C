#include "..\EQU.H"
#include "YAGO.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\SUICIDE.H"
#include "PLAYSUB4.H"

#if defined(R41A)
  #define SPRITE_YAGO_BASE 490
#elif defined(R41B)
  #define SPRITE_YAGO_BASE 451
#elif defined(R41C)
  #define SPRITE_YAGO_BASE 468
#elif defined(R41D)
  #define SPRITE_YAGO_BASE 458
#elif defined(R42A)
  #define SPRITE_YAGO_BASE 496
#elif defined(R42B)
  #define SPRITE_YAGO_BASE 449
#else
  #define SPRITE_YAGO_BASE 453
#endif

static void act_disp(sprite_status* pActwk);
static void yago_e(sprite_status* pActwk);
static void act_init(sprite_status* pActwk);
static void act_fall(sprite_status* pActwk);
static void act_lr(sprite_status* pActwk);
static void act_rev(sprite_status* pActwk);
static void act_rev1(sprite_status* pActwk);
static void act_jet(sprite_status* pActwk);
static void act_jet1(sprite_status* pActwk);
static void act_jet2(sprite_status* pActwk);
static void act_fall1(sprite_status* pActwk);
static void yago_b(sprite_status* pActwk);
static void act_init_(sprite_status* pActwk);
static void act_fall_(sprite_status* pActwk);
static void act_jet1_(sprite_status* pActwk);
static void act_jet2_(sprite_status* pActwk);

static unsigned char pat_chg0[4] = { 9, 0, 1, 255 };
static unsigned char* pat_chg[1] = { pat_chg0 };
static sprite_pattern spr_yago_e_00 =
{
  1,
  { { -24, -12, 0, SPRITE_YAGO_BASE + 2 } }
};
static sprite_pattern spr_yago_e_01 =
{
  1,
  { { -24, -12, 0, SPRITE_YAGO_BASE + 3 } }
};
static sprite_pattern spr_yago_b_00 =
{
  1,
  { { -24, -12, 0, SPRITE_YAGO_BASE } }
};
static sprite_pattern spr_yago_b_01 =
{
  1,
  { { -24, -12, 0, SPRITE_YAGO_BASE + 1 } }
};
sprite_pattern* pat_yago_e[2] =
{
  &spr_yago_e_00,
  &spr_yago_e_01
};
sprite_pattern* pat_yago_b[2] =
{
  &spr_yago_b_00,
  &spr_yago_b_01
};














































































void yago(sprite_status* pActwk) { /* Line 152, Address: 0x10205f0 */
  if (!pActwk->userflag.b.h) /* Line 153, Address: 0x10205fc */
    yago_e(pActwk); /* Line 154, Address: 0x102060c */
  else
    yago_b(pActwk); /* Line 156, Address: 0x1020620 */
} /* Line 157, Address: 0x102062c */



static void act_disp(sprite_status* pActwk) { /* Line 161, Address: 0x1020640 */
  patchg(pActwk, pat_chg); /* Line 162, Address: 0x102064c */
  actionsub(pActwk); /* Line 163, Address: 0x1020660 */
  frameout_s00(pActwk, ((short*)pActwk)[33]); /* Line 164, Address: 0x102066c */
} /* Line 165, Address: 0x1020680 */



static void yago_e(sprite_status* pActwk) { /* Line 169, Address: 0x1020690 */
  static void(*act_tbl[9])(sprite_status*) =
  {
    &act_init,
    &act_fall,
    &act_lr,
    &act_rev,
    &act_rev1,
    &act_jet,
    &act_jet1,
    &act_jet2,
    &act_fall1
  };

  if (!enemy_suicide(pActwk)) /* Line 183, Address: 0x102069c */
    act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 184, Address: 0x10206b0 */
} /* Line 185, Address: 0x10206f4 */



static void act_init(sprite_status* pActwk) { /* Line 189, Address: 0x1020710 */
  ((short*)pActwk)[33] = pActwk->xposi.w.h; /* Line 190, Address: 0x102071c */
  pActwk->r_no0 += 2; /* Line 191, Address: 0x102072c */
  pActwk->actflg = 4; /* Line 192, Address: 0x102073c */
  pActwk->colino = 47; /* Line 193, Address: 0x1020748 */
  pActwk->sprpri = 1; /* Line 194, Address: 0x1020754 */
  pActwk->sprhsize = 24; /* Line 195, Address: 0x1020760 */
  pActwk->sprvsize = 12; /* Line 196, Address: 0x102076c */

  pActwk->sproffset = 9200; /* Line 198, Address: 0x1020778 */
  pActwk->patbase = pat_yago_e; /* Line 199, Address: 0x1020784 */
  act_fall(pActwk); /* Line 200, Address: 0x1020794 */
} /* Line 201, Address: 0x10207a0 */



static void act_fall(sprite_status* pActwk) { /* Line 205, Address: 0x10207b0 */
  pActwk->yposi.l += 65536; /* Line 206, Address: 0x10207bc */
  if (emycol_d(pActwk) - 5 >= 0) /* Line 207, Address: 0x10207d0 */
  {
    act_disp(pActwk); /* Line 209, Address: 0x10207f0 */
  } /* Line 210, Address: 0x10207fc */
  else
  {

    pActwk->r_no0 += 2; /* Line 214, Address: 0x1020804 */
    *(int*)&pActwk->actfree[0] = 5242880; /* Line 215, Address: 0x1020814 */
    *(int*)&pActwk->actfree[4] = -16384; /* Line 216, Address: 0x1020824 */
    act_disp(pActwk); /* Line 217, Address: 0x1020834 */
  }
} /* Line 219, Address: 0x1020840 */



static void act_lr(sprite_status* pActwk) { /* Line 223, Address: 0x1020850 */
  short temp;

  *(int*)&pActwk->actfree[0] += -16384; /* Line 226, Address: 0x1020860 */
  if ((long int)*(int*)&pActwk->actfree[0] >= 0) /* Line 227, Address: 0x1020878 */
  {
    pActwk->xposi.l += *(int*)&pActwk->actfree[4]; /* Line 229, Address: 0x1020894 */
    pActwk->yposi.w.h += emycol_d(pActwk) - 5; /* Line 230, Address: 0x10208b0 */
    if (pActwk->actflg & 1) /* Line 231, Address: 0x10208e0 */
      temp = emycol_r(pActwk, pActwk->sprhs); /* Line 232, Address: 0x10208f8 */
    else
      temp = emycol_l(pActwk, -(char)pActwk->sprhs); /* Line 234, Address: 0x102091c */
    if (temp - 5 >= 0) /* Line 235, Address: 0x1020950 */
    {
      temp = pActwk->xposi.w.h - actwk[0].xposi.w.h; /* Line 237, Address: 0x1020964 */
      if (pActwk->actflg & 1) /* Line 238, Address: 0x1020998 */
        temp *= -1; /* Line 239, Address: 0x10209b0 */

      if ((unsigned short)temp > 80) /* Line 241, Address: 0x10209bc */
      {
        temp -= 16; /* Line 243, Address: 0x10209d0 */
        temp -= 64; /* Line 244, Address: 0x10209dc */
        act_disp(pActwk); /* Line 245, Address: 0x10209e8 */
        return; /* Line 246, Address: 0x10209f4 */
      }


      temp -= 16; /* Line 250, Address: 0x10209fc */
      temp -= 64; /* Line 251, Address: 0x1020a08 */

      pActwk->r_no0 += 6; /* Line 253, Address: 0x1020a14 */
      ((short*)pActwk)[27] = 7; /* Line 254, Address: 0x1020a24 */
      act_disp(pActwk); /* Line 255, Address: 0x1020a30 */
      return; /* Line 256, Address: 0x1020a3c */
    }
  }


  pActwk->r_no0 += 2; /* Line 261, Address: 0x1020a44 */
  ((short*)pActwk)[27] = 31; /* Line 262, Address: 0x1020a54 */
  act_disp(pActwk); /* Line 263, Address: 0x1020a60 */
} /* Line 264, Address: 0x1020a6c */



static void act_rev(sprite_status* pActwk) { /* Line 268, Address: 0x1020a80 */
  --((short*)pActwk)[27]; /* Line 269, Address: 0x1020a8c */
  if (((short*)pActwk)[27]) /* Line 270, Address: 0x1020a9c */
  {
    act_disp(pActwk); /* Line 272, Address: 0x1020aac */
    return; /* Line 273, Address: 0x1020ab8 */
  }

  pActwk->r_no0 += 2; /* Line 276, Address: 0x1020ac0 */
  ((short*)pActwk)[27] = 31; /* Line 277, Address: 0x1020ad0 */
  *(int*)&pActwk->actfree[0] = 5242880; /* Line 278, Address: 0x1020adc */
  *(int*)&pActwk->actfree[4] *= -1; /* Line 279, Address: 0x1020aec */
  pActwk->actflg ^= 1; /* Line 280, Address: 0x1020b04 */
  pActwk->cddat ^= 1; /* Line 281, Address: 0x1020b14 */
  act_disp(pActwk); /* Line 282, Address: 0x1020b24 */
} /* Line 283, Address: 0x1020b30 */



static void act_rev1(sprite_status* pActwk) { /* Line 287, Address: 0x1020b40 */
  --((short*)pActwk)[27]; /* Line 288, Address: 0x1020b4c */
  if (((short*)pActwk)[27]) /* Line 289, Address: 0x1020b5c */
  {
    act_disp(pActwk); /* Line 291, Address: 0x1020b6c */
    return; /* Line 292, Address: 0x1020b78 */
  }

  pActwk->r_no0 -= 4; /* Line 295, Address: 0x1020b80 */
  act_disp(pActwk); /* Line 296, Address: 0x1020b90 */
} /* Line 297, Address: 0x1020b9c */



static void act_jet(sprite_status* pActwk) { /* Line 301, Address: 0x1020bb0 */
  --((short*)pActwk)[27]; /* Line 302, Address: 0x1020bbc */
  if (((short*)pActwk)[27]) /* Line 303, Address: 0x1020bcc */
  {
    act_disp(pActwk); /* Line 305, Address: 0x1020bdc */
    return; /* Line 306, Address: 0x1020be8 */
  }

  pActwk->r_no0 += 2; /* Line 309, Address: 0x1020bf0 */
  ((short*)pActwk)[27] = 31; /* Line 310, Address: 0x1020c00 */
  act_disp(pActwk); /* Line 311, Address: 0x1020c0c */
} /* Line 312, Address: 0x1020c18 */



static void act_jet1(sprite_status* pActwk) { /* Line 316, Address: 0x1020c30 */
  pActwk->yposi.l += 8192; /* Line 317, Address: 0x1020c3c */
  --((short*)pActwk)[27]; /* Line 318, Address: 0x1020c4c */
  if (((short*)pActwk)[27]) /* Line 319, Address: 0x1020c5c */
  {
    act_disp(pActwk); /* Line 321, Address: 0x1020c6c */
    return; /* Line 322, Address: 0x1020c78 */
  }

  pActwk->r_no0 += 2; /* Line 325, Address: 0x1020c80 */
  ((int*)pActwk)[15] = -294912; /* Line 326, Address: 0x1020c90 */
  if (pActwk->actflg & 1) /* Line 327, Address: 0x1020ca0 */
    ((int*)pActwk)[15] *= -1; /* Line 328, Address: 0x1020cb8 */

  ((int*)pActwk)[14] = -98304; /* Line 330, Address: 0x1020cc8 */
  act_disp(pActwk); /* Line 331, Address: 0x1020cd8 */
} /* Line 332, Address: 0x1020ce4 */



static void act_jet2(sprite_status* pActwk) { /* Line 336, Address: 0x1020d00 */
  short temp;

  pActwk->xposi.l += ((int*)pActwk)[15]; /* Line 339, Address: 0x1020d10 */
  if (pActwk->actflg & 1) /* Line 340, Address: 0x1020d28 */
    temp = emycol_r(pActwk, pActwk->sprhs); /* Line 341, Address: 0x1020d40 */
  else
    temp = emycol_l(pActwk, -(char)pActwk->sprhs); /* Line 343, Address: 0x1020d64 */
  if (temp - 5 >= 0) /* Line 344, Address: 0x1020d98 */
  {
    pActwk->yposi.l += ((int*)pActwk)[14]; /* Line 346, Address: 0x1020dac */
    if (((int*)pActwk)[14] < 0) /* Line 347, Address: 0x1020dc4 */
      ((int*)pActwk)[14] += 8192; /* Line 348, Address: 0x1020dd4 */

    frameout_s(pActwk); /* Line 350, Address: 0x1020de4 */
    act_disp(pActwk); /* Line 351, Address: 0x1020df0 */
    return; /* Line 352, Address: 0x1020dfc */
  }

  pActwk->r_no0 = 6; /* Line 355, Address: 0x1020e04 */

  ((short*)pActwk)[27] = 31; /* Line 357, Address: 0x1020e10 */
  act_disp(pActwk); /* Line 358, Address: 0x1020e1c */
} /* Line 359, Address: 0x1020e28 */



static void act_fall1(sprite_status* pActwk) { /* Line 363, Address: 0x1020e40 */
  short temp;

  pActwk->yposi.l += 65536; /* Line 366, Address: 0x1020e50 */
  if ((temp = emycol_d(pActwk) - 5) >= 0) /* Line 367, Address: 0x1020e64 */
  {
    act_disp(pActwk); /* Line 369, Address: 0x1020ea4 */
    return; /* Line 370, Address: 0x1020eb0 */
  }

  pActwk->r_no0 = 6; /* Line 373, Address: 0x1020eb8 */
  pActwk->yposi.w.h += temp; /* Line 374, Address: 0x1020ec4 */
  ((short*)pActwk)[27] = 31; /* Line 375, Address: 0x1020ed4 */
  act_disp(pActwk); /* Line 376, Address: 0x1020ee0 */
} /* Line 377, Address: 0x1020eec */



static void yago_b(sprite_status* pActwk) { /* Line 381, Address: 0x1020f00 */
  static void(*act_tbl[9])(sprite_status*) =
  {
    &act_init_,
    &act_fall_,
    &act_lr,
    &act_rev,
    &act_rev1,
    &act_jet,
    &act_jet1_,
    &act_jet2_,
    &act_fall1
  };

  if (!enemy_suicide(pActwk)) /* Line 395, Address: 0x1020f0c */
    act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 396, Address: 0x1020f20 */
} /* Line 397, Address: 0x1020f64 */



static void act_init_(sprite_status* pActwk) { /* Line 401, Address: 0x1020f80 */
  ((short*)pActwk)[33] = pActwk->xposi.w.h; /* Line 402, Address: 0x1020f8c */
  pActwk->r_no0 += 2; /* Line 403, Address: 0x1020f9c */
  pActwk->actflg = 4; /* Line 404, Address: 0x1020fac */
  pActwk->colino = 47; /* Line 405, Address: 0x1020fb8 */
  pActwk->sprpri = 1; /* Line 406, Address: 0x1020fc4 */
  pActwk->sprhsize = 24; /* Line 407, Address: 0x1020fd0 */
  pActwk->sprvsize = 12; /* Line 408, Address: 0x1020fdc */

  pActwk->sproffset = 9200; /* Line 410, Address: 0x1020fe8 */
  pActwk->patbase = pat_yago_b; /* Line 411, Address: 0x1020ff4 */
  act_fall_(pActwk); /* Line 412, Address: 0x1021004 */
} /* Line 413, Address: 0x1021010 */



static void act_fall_(sprite_status* pActwk) { /* Line 417, Address: 0x1021020 */
  short temp;

  pActwk->yposi.l += 65536; /* Line 420, Address: 0x1021030 */
  if ((temp = emycol_d(pActwk)) - 5 >= 0) /* Line 421, Address: 0x1021044 */
  {
    act_disp(pActwk); /* Line 423, Address: 0x1021074 */
  } /* Line 424, Address: 0x1021080 */
  else
  {

    pActwk->r_no0 += 2; /* Line 428, Address: 0x1021088 */
    pActwk->yposi.w.h += temp - 5; /* Line 429, Address: 0x1021098 */
    *(int*)&pActwk->actfree[0] = 5242880; /* Line 430, Address: 0x10210bc */
    *(int*)&pActwk->actfree[4] = -16384; /* Line 431, Address: 0x10210cc */
    act_disp(pActwk); /* Line 432, Address: 0x10210dc */
  }
} /* Line 434, Address: 0x10210e8 */



static void act_jet1_(sprite_status* pActwk) { /* Line 438, Address: 0x1021100 */
  pActwk->yposi.l += 10240; /* Line 439, Address: 0x102110c */
  --((short*)pActwk)[27]; /* Line 440, Address: 0x102111c */
  if (((short*)pActwk)[27]) /* Line 441, Address: 0x102112c */
  {
    act_disp(pActwk); /* Line 443, Address: 0x102113c */
    return; /* Line 444, Address: 0x1021148 */
  }

  pActwk->r_no0 += 2; /* Line 447, Address: 0x1021150 */
  ((int*)pActwk)[15] = -65536; /* Line 448, Address: 0x1021160 */
  if (pActwk->actflg & 1) /* Line 449, Address: 0x102116c */
    ((int*)pActwk)[15] *= -1; /* Line 450, Address: 0x1021184 */

  ((int*)pActwk)[14] = -98304; /* Line 452, Address: 0x1021194 */
  act_disp(pActwk); /* Line 453, Address: 0x10211a4 */
} /* Line 454, Address: 0x10211b0 */



static void act_jet2_(sprite_status* pActwk) { /* Line 458, Address: 0x10211c0 */
  short temp;

  pActwk->xposi.l += ((int*)pActwk)[15]; /* Line 461, Address: 0x10211d0 */
  if (pActwk->actflg & 1) /* Line 462, Address: 0x10211e8 */
    temp = emycol_r(pActwk, pActwk->sprhs); /* Line 463, Address: 0x1021200 */
  else
    temp = emycol_l(pActwk, -(char)pActwk->sprhs); /* Line 465, Address: 0x1021224 */
  if (temp >= 0) /* Line 466, Address: 0x1021258 */
  {
    pActwk->yposi.l += ((int*)pActwk)[14]; /* Line 468, Address: 0x1021268 */
    ((int*)pActwk)[14] += 4096; /* Line 469, Address: 0x1021280 */
    if (((int*)pActwk)[14] < 0) /* Line 470, Address: 0x1021290 */
    {
      act_disp(pActwk); /* Line 472, Address: 0x10212a0 */
      return; /* Line 473, Address: 0x10212ac */
    }
    if (emycol_d(pActwk) - 5 < 0) /* Line 475, Address: 0x10212b4 */
    {

      pActwk->r_no0 = 4; /* Line 478, Address: 0x10212d4 */
      act_disp(pActwk); /* Line 479, Address: 0x10212e0 */
      return; /* Line 480, Address: 0x10212ec */
    }
    act_disp(pActwk); /* Line 482, Address: 0x10212f4 */
    return; /* Line 483, Address: 0x1021300 */
  }

  pActwk->r_no0 += 2; /* Line 486, Address: 0x1021308 */

  ((short*)pActwk)[27] = 31; /* Line 488, Address: 0x1021318 */
  act_disp(pActwk); /* Line 489, Address: 0x1021324 */
} /* Line 490, Address: 0x1021330 */
