#include "..\EQU.H"
#include "KDAI6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"

void(*kdai6_tbl[2])(sprite_status*) =
{
  &kdai6_init,
  &kdai6_move
};
void(*move_tbl[4])(sprite_status*) =
{
  &kd_mv_right,
  &kd_mv_left,
  &kd_mv_up,
  &kd_mv_down
};
unsigned char kdpat0[8] = { 9, 0, 1, 2, 3, 4, 5, 255 };
unsigned char* kdai6pchg[1] = { kdpat0 };
sprite_pattern kdai6pat0 =
{
  1,
  { { -24, -16, 0, 314 } }
};
sprite_pattern kdai6pat1 =
{
  1,
  { { -24, -16, 0, 315 } }
};
sprite_pattern kdai6pat2 =
{
  1,
  { { -24, -16, 0, 316 } }
};
sprite_pattern kdai6pat3 =
{
  1,
  { { -24, -16, 0, 317 } }
};
sprite_pattern kdai6pat4 =
{
  1,
  { { -24, -16, 0, 318 } }
};
sprite_pattern kdai6pat5 =
{
  1,
  { { -24, -16, 0, 319 } }
};
sprite_pattern* kdai6pat[6] =
{
  &kdai6pat0,
  &kdai6pat1,
  &kdai6pat2,
  &kdai6pat3,
  &kdai6pat4,
  &kdai6pat5
};


















void kdai6(sprite_status* pActwk) { /* Line 80, Address: 0x1017c60 */
  kdai6_tbl[pActwk->r_no0 / 2](pActwk); /* Line 81, Address: 0x1017c6c */
  actionsub(pActwk); /* Line 82, Address: 0x1017cb0 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 83, Address: 0x1017cbc */
} /* Line 84, Address: 0x1017cd0 */



short kdai6_ridechk(sprite_status* pActwk) { /* Line 88, Address: 0x1017ce0 */
  ridechk(pActwk, &actwk[0]); /* Line 89, Address: 0x1017cec */
} /* Line 90, Address: 0x1017d00 */











void kdai6_init(sprite_status* pActwk) { /* Line 102, Address: 0x1017d10 */
  pActwk->actflg |= 4; /* Line 103, Address: 0x1017d18 */
  pActwk->sprpri = 1; /* Line 104, Address: 0x1017d28 */
  pActwk->sproffset = 17258; /* Line 105, Address: 0x1017d34 */
  pActwk->patbase = kdai6pat; /* Line 106, Address: 0x1017d40 */
  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 107, Address: 0x1017d50 */
  ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 108, Address: 0x1017d60 */
  pActwk->sprvsize = 12; /* Line 109, Address: 0x1017d70 */
  pActwk->sprhsize = 16; /* Line 110, Address: 0x1017d7c */
  pActwk->r_no0 += 2; /* Line 111, Address: 0x1017d88 */
} /* Line 112, Address: 0x1017d98 */











void kdai6_move(sprite_status* pActwk) { /* Line 124, Address: 0x1017db0 */
  short iD0;
  sprite_status* pPlaywk;


  pPlaywk = &actwk[0]; /* Line 129, Address: 0x1017dc4 */
  dai6_move(pActwk); /* Line 130, Address: 0x1017dcc */

  patchg(pActwk, kdai6pchg); /* Line 132, Address: 0x1017dd8 */

  iD0 = kdai6_ridechk(pActwk); /* Line 134, Address: 0x1017dec */
  if (iD0 == 0) return; /* Line 135, Address: 0x1017e00 */




  pPlaywk->cddat |= 1; /* Line 140, Address: 0x1017e10 */
  pPlaywk->actflg &= 252; /* Line 141, Address: 0x1017e1c */
  pPlaywk->actflg |= 1; /* Line 142, Address: 0x1017e28 */
  if (!(pPlaywk->actfree[2] & 1)) /* Line 143, Address: 0x1017e34 */
  {
    pPlaywk->mstno.b.h = 45; /* Line 145, Address: 0x1017e48 */
    pPlaywk->actfree[1] = 0; /* Line 146, Address: 0x1017e50 */
    iD0 = pPlaywk->xposi.w.h - pActwk->xposi.w.h; /* Line 147, Address: 0x1017e54 */
    if (iD0 < 0) /* Line 148, Address: 0x1017e84 */
    {
      iD0 = -iD0; /* Line 150, Address: 0x1017e94 */
      pPlaywk->actfree[1] = 128; /* Line 151, Address: 0x1017eb0 */
    }

    pPlaywk->actfree[15] = iD0; /* Line 154, Address: 0x1017eb8 */
  }

  pPlaywk->actfree[2] |= 1; /* Line 157, Address: 0x1017ec0 */
  if ((unsigned int)pPlaywk->r_no0 >= 6) return; /* Line 158, Address: 0x1017ecc */

  kaiten_play(pActwk); /* Line 160, Address: 0x1017ee0 */
} /* Line 161, Address: 0x1017eec */











short kdai6_rangecheck(sprite_status* pActwk) { /* Line 173, Address: 0x1017f10 */
  short iD0;

  iD0 = (short)(unsigned short)actwk[0].sprvsize + actwk[0].yposi.w.h; /* Line 176, Address: 0x1017f1c */
  iD0 -= pActwk->yposi.w.h; /* Line 177, Address: 0x1017f5c */
  if (iD0 < 0) return 0; /* Line 178, Address: 0x1017f70 */
  if (iD0 < 16) return 0; /* Line 179, Address: 0x1017f8c */
  return -1; /* Line 180, Address: 0x1017fac */
} /* Line 181, Address: 0x1017fb0 */











void kaiten_play(sprite_status* pActwk) { /* Line 193, Address: 0x1017fc0 */
  unsigned char tbl[16] = /* Line 194, Address: 0x1017fd8 */
  {
    0, 0, 0, 1, 1, 2, 2, 2,
    3, 3, 3, 4, 4, 5, 5, 5
  };
  unsigned char byD0, byD1;
  short iSin, iCos;
  sprite_status* pPlaywk;
  int_union lD0;

  pPlaywk = &actwk[0]; /* Line 204, Address: 0x101800c */
  pPlaywk->actfree[1] += 4; /* Line 205, Address: 0x1018014 */
  sinset(pPlaywk->actfree[1], &iSin, &iCos); /* Line 206, Address: 0x1018020 */
  byD0 = pPlaywk->actfree[15]; /* Line 207, Address: 0x1018034 */
  lD0.w.l = (unsigned short)byD0; /* Line 208, Address: 0x101803c */
  lD0.l = lD0.w.l * iCos; /* Line 209, Address: 0x101804c */
  lD0.l >>= 8; /* Line 210, Address: 0x101806c */
  pPlaywk->xposi.w.h = pActwk->xposi.w.h + lD0.w.l; /* Line 211, Address: 0x1018078 */

  byD0 = pPlaywk->actfree[1]; /* Line 213, Address: 0x10180a4 */
  byD1 = byD0; /* Line 214, Address: 0x10180ac */
  byD0 &= 240; /* Line 215, Address: 0x10180b0 */
  byD0 >>= 4; /* Line 216, Address: 0x10180b8 */
  pPlaywk->patcnt = tbl[byD0]; /* Line 217, Address: 0x10180c0 */
  if (!(byD1 & 63)) /* Line 218, Address: 0x10180d0 */
    ++pPlaywk->actfree[15]; /* Line 219, Address: 0x10180e0 */

  swdata.w = swdata1.w; /* Line 221, Address: 0x10180ec */
  if (pPlaywk->actno != 1) /* Line 222, Address: 0x10180fc */
    swdata.w = swdata2.w; /* Line 223, Address: 0x1018110 */

  k_move(pActwk); /* Line 225, Address: 0x1018120 */
  jumpchk_d(pActwk); /* Line 226, Address: 0x101812c */
} /* Line 227, Address: 0x1018138 */











void k_move(sprite_status* pActwk) { /* Line 239, Address: 0x1018160 */
  sprite_status* pPlaywk;

  pPlaywk = &actwk[0]; /* Line 242, Address: 0x101816c */
  if (pPlaywk->xposi.w.h - pActwk->xposi.w.h < 0) /* Line 243, Address: 0x1018174 */
  {

    if (swdata.b.h & 4) /* Line 246, Address: 0x101819c */
    {
      ++pPlaywk->actfree[15]; /* Line 248, Address: 0x10181b4 */
      return; /* Line 249, Address: 0x10181c0 */
    }
    if (swdata.b.h & 8) /* Line 251, Address: 0x10181c8 */
    {
      --pPlaywk->actfree[15]; /* Line 253, Address: 0x10181e0 */
      if (((char*)pPlaywk)[61] < 0) /* Line 254, Address: 0x10181ec */
        pPlaywk->actfree[15] = 0; /* Line 255, Address: 0x1018200 */
    }
  } /* Line 257, Address: 0x1018204 */
  else {


    if (swdata.b.h & 8) /* Line 261, Address: 0x101820c */
    {
      ++pPlaywk->actfree[15]; /* Line 263, Address: 0x1018224 */
      return; /* Line 264, Address: 0x1018230 */
    }
    if (swdata.b.h & 4) /* Line 266, Address: 0x1018238 */
    {
      --pPlaywk->actfree[15]; /* Line 268, Address: 0x1018250 */
      if (((char*)pPlaywk)[61] < 0) /* Line 269, Address: 0x101825c */
        pPlaywk->actfree[15] = 0; /* Line 270, Address: 0x1018270 */
    }
  }
} /* Line 273, Address: 0x1018274 */











void jumpchk_d(sprite_status* pActwk) { /* Line 285, Address: 0x1018290 */
  sprite_status* pPlaywk;
  short iSin, iCos;
  unsigned char byD0;
  int_union lD1;

  pPlaywk = &actwk[0]; /* Line 291, Address: 0x10182a4 */
  byD0 = pActwk->actno; /* Line 292, Address: 0x10182ac */
  if (!(swdata.b.l & 112)) return; /* Line 293, Address: 0x10182b8 */
  pPlaywk->actfree[2] = 0; /* Line 294, Address: 0x10182d0 */

  byD0 = pPlaywk->direc.b.h; /* Line 296, Address: 0x10182d4 */
  byD0 -= 64; /* Line 297, Address: 0x10182dc */
  sinset(byD0, &iSin, &iCos); /* Line 298, Address: 0x10182e4 */
  lD1.l = iCos * 1664; /* Line 299, Address: 0x10182f8 */
  lD1.l >>= 8; /* Line 300, Address: 0x101831c */
  pPlaywk->xspeed.w += lD1.w.l; /* Line 301, Address: 0x1018328 */
  lD1.l = iSin * 1664; /* Line 302, Address: 0x1018338 */
  lD1.l >>= 8; /* Line 303, Address: 0x101835c */
  pPlaywk->yspeed.w += lD1.w.l; /* Line 304, Address: 0x1018368 */

  pPlaywk->cddat |= 2; /* Line 306, Address: 0x1018378 */
  pPlaywk->cddat &= 223; /* Line 307, Address: 0x1018384 */
  pPlaywk->actfree[18] = 1; /* Line 308, Address: 0x1018390 */
  pPlaywk->actfree[14] = 0; /* Line 309, Address: 0x1018398 */

  if (chibi_flag != 0) /* Line 311, Address: 0x101839c */
  {
    pPlaywk->sprvsize = 10; /* Line 313, Address: 0x10183b0 */
    pPlaywk->sprhs = 5; /* Line 314, Address: 0x10183b8 */
  } /* Line 315, Address: 0x10183c0 */
  else
  {

    pPlaywk->sprvsize = 19; /* Line 319, Address: 0x10183c8 */
    pPlaywk->sprhs = 9; /* Line 320, Address: 0x10183d0 */
  }

  if (pPlaywk->cddat & 4) /* Line 323, Address: 0x10183d8 */
  {
    pPlaywk->cddat |= 16; /* Line 325, Address: 0x10183ec */
    return; /* Line 326, Address: 0x10183f8 */
  }
  if (chibi_flag != 0) /* Line 328, Address: 0x1018400 */
  {
    pPlaywk->sprvsize = 10; /* Line 330, Address: 0x1018414 */
    pPlaywk->sprhs = 5; /* Line 331, Address: 0x101841c */
  } /* Line 332, Address: 0x1018424 */
  else
  {

    pPlaywk->sprvsize = 14; /* Line 336, Address: 0x101842c */
    pPlaywk->sprhs = 7; /* Line 337, Address: 0x1018434 */
    pPlaywk->yposi.w.h += 5; /* Line 338, Address: 0x101843c */
  }

  pPlaywk->cddat |= 4; /* Line 341, Address: 0x1018448 */
  pPlaywk->mstno.b.h = 2; /* Line 342, Address: 0x1018454 */
} /* Line 343, Address: 0x101845c */


















void dai6_move(sprite_status* pActwk) { /* Line 362, Address: 0x1018480 */
  move_tbl[pActwk->userflag.b.h](pActwk); /* Line 363, Address: 0x101848c */
} /* Line 364, Address: 0x10184bc */











void kd_mv_up(sprite_status* pActwk) { /* Line 376, Address: 0x10184d0 */
  short iD0;

  iD0 = kd_dair6_sub2(pActwk); /* Line 379, Address: 0x10184e0 */
  iD0 = -iD0 + ((short*)pActwk)[27]; /* Line 380, Address: 0x10184f4 */
  pActwk->yposi.w.h = iD0; /* Line 381, Address: 0x1018524 */
} /* Line 382, Address: 0x101852c */











void kd_mv_down(sprite_status* pActwk) { /* Line 394, Address: 0x1018540 */
  short iD0;

  iD0 = kd_dair6_sub2(pActwk); /* Line 397, Address: 0x1018550 */
  pActwk->yposi.w.h = iD0 + ((short*)pActwk)[27]; /* Line 398, Address: 0x1018564 */
} /* Line 399, Address: 0x1018590 */











void kd_mv_right(sprite_status* pActwk) { /* Line 411, Address: 0x10185b0 */
  short iD0;
  int lXsv;
  int_union lD0;

  lXsv = pActwk->xposi.l; /* Line 416, Address: 0x10185c4 */
  iD0 = kd_dair6_sub2(pActwk); /* Line 417, Address: 0x10185cc */
  pActwk->xposi.w.h = iD0 + ((short*)pActwk)[29]; /* Line 418, Address: 0x10185e0 */

  lD0.l = pActwk->xposi.l - lXsv; /* Line 420, Address: 0x101860c */
  lD0.l >>= 8; /* Line 421, Address: 0x101861c */
  pActwk->xspeed.w = lD0.w.l; /* Line 422, Address: 0x1018628 */
} /* Line 423, Address: 0x1018634 */











void kd_mv_left(sprite_status* pActwk) { /* Line 435, Address: 0x1018650 */
  short iD0;
  int lXsv;
  int_union lD0;

  lXsv = pActwk->xposi.l; /* Line 440, Address: 0x1018664 */
  iD0 = kd_dair6_sub2(pActwk); /* Line 441, Address: 0x101866c */
  pActwk->xposi.w.h = -iD0 + ((short*)pActwk)[29]; /* Line 442, Address: 0x1018680 */

  lD0.l = pActwk->xposi.l - lXsv; /* Line 444, Address: 0x10186b0 */
  lD0.l >>= 8; /* Line 445, Address: 0x10186c0 */
  pActwk->xspeed.w = lD0.w.l; /* Line 446, Address: 0x10186cc */
} /* Line 447, Address: 0x10186d8 */











short kd_dair6_sub2(sprite_status* pActwk) { /* Line 459, Address: 0x10186f0 */
  short iSin;
  short iCos;
  unsigned short wD0;


  wD0 = gametimer.w & 255; /* Line 465, Address: 0x1018700 */
  sinset(wD0, &iSin, &iCos); /* Line 466, Address: 0x101871c */

  iSin += iSin; /* Line 468, Address: 0x1018730 */
  iSin += iSin; /* Line 469, Address: 0x1018740 */
  iSin /= 16; /* Line 470, Address: 0x1018750 */




  ++pActwk->actfree[16]; /* Line 475, Address: 0x1018770 */
  return iSin; /* Line 476, Address: 0x1018780 */
} /* Line 477, Address: 0x1018784 */
