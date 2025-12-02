#include "..\EQU.H"
#include "MOVIE4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"
#include "PLAYSUB4.H"

#if defined(R42B)
  #define SPRITE_MOVIE4_BASE 457
#else
  #define SPRITE_MOVIE4_BASE 487
#endif

unsigned char movie1_pchg00[6] = { 0, 2, 1, 3, 1, 255 };
unsigned char movie1_pchg01[58] =
{
  0, 4, 4, 1, 4, 4, 1, 4, 4, 1,
  4, 4, 1, 4, 4, 1, 1, 4, 4, 1,
  1, 4, 4, 1, 1, 4, 4, 1, 1, 5,
  5, 1, 5, 5, 1, 5, 5, 1, 5, 5,
  1, 5, 5, 1, 1, 5, 5, 1, 1, 5,
  5, 1, 1, 5, 5, 1, 1, 255
};
unsigned char* movie1_pchg[2] =
{
  movie1_pchg00,
  movie1_pchg01
};
sprite_pattern spr_movie1 =
{
  1,
  { { -12, -12, 0, SPRITE_MOVIE4_BASE } }
};
sprite_pattern spr_movie2 =
{
  1,
  { { -8, -4, 0, SPRITE_MOVIE4_BASE + 1 } }
};
sprite_pattern spr_movie3 =
{
  1,
  { { -8, -4, 0, SPRITE_MOVIE4_BASE + 2 } }
};
sprite_pattern spr_movie4 =
{
  1,
  { { -20, -24, 0, SPRITE_MOVIE4_BASE + 3 } }
};
sprite_pattern spr_movie5 =
{
  1,
  { { -20, -24, 0, SPRITE_MOVIE4_BASE + 4 } }
};
sprite_pattern spr_movie0 =
{
  0,
  { { -20, -24, 0, SPRITE_MOVIE4_BASE + 4 } }
};
sprite_pattern* pat_movie[6] =
{
  &spr_movie1,
  &spr_movie0,
  &spr_movie2,
  &spr_movie3,
  &spr_movie4,
  &spr_movie5
};
char tbl0[37] =
{
    1,   0,   0,
    5, -18, -10,
   10, -10,  10,
   15,   0, -18,
   20, -10,  18,
   22,   8,  23,
   25,  13, -10,
   28,  -3, -25,
   30,  10,  20,
   32, -10,   2,
   35,  13, -10,
   40, -10,  10,
   -1
};











































































void movie4(sprite_status* pActwk) { /* Line 160, Address: 0x1022340 */
  void(*tbl_m[5])(sprite_status*) = /* Line 161, Address: 0x102234c */
  {
    &mm_init,
    &mm_wait,
    &mm_die,
    &m_baku,
    &mm1wait
  };

  if (pActwk->userflag.b.h) /* Line 170, Address: 0x1022378 */
    sub(pActwk); /* Line 171, Address: 0x1022388 */
  else
  {
    tbl_m[pActwk->r_no0 / 2](pActwk); /* Line 174, Address: 0x102239c */
    actionsub(pActwk); /* Line 175, Address: 0x10223d8 */
    if (pActwk->r_no0 <= 2) /* Line 176, Address: 0x10223e4 */
      frameout_s(pActwk); /* Line 177, Address: 0x10223fc */
  }
} /* Line 179, Address: 0x1022408 */




void die(sprite_status* pActwk) { /* Line 184, Address: 0x1022420 */
  frameout(pActwk); /* Line 185, Address: 0x102242c */
} /* Line 186, Address: 0x1022438 */




void mm_init(sprite_status* pActwk) { /* Line 191, Address: 0x1022450 */
  sprite_status* subactwk;

  if (projector_flag) /* Line 194, Address: 0x102245c */
  {
    die(pActwk); /* Line 196, Address: 0x102246c */
    return; /* Line 197, Address: 0x1022478 */
  }


  pActwk->r_no0 += 2; /* Line 201, Address: 0x1022480 */
  pActwk->actflg |= 4; /* Line 202, Address: 0x1022490 */
  pActwk->sprpri = 4; /* Line 203, Address: 0x10224a0 */
  pActwk->sprhs = 12; /* Line 204, Address: 0x10224ac */
  pActwk->sprhsize = 12; /* Line 205, Address: 0x10224b8 */
  pActwk->sprvsize = 12; /* Line 206, Address: 0x10224c4 */
  pActwk->colino = 251; /* Line 207, Address: 0x10224d0 */
  pActwk->sproffset = 944; /* Line 208, Address: 0x10224dc */
  pActwk->patbase = pat_movie; /* Line 209, Address: 0x10224e8 */
  ((char**)pActwk)[12] = tbl0; /* Line 210, Address: 0x10224f8 */

  if (actwkchk(&subactwk) != 0) /* Line 212, Address: 0x1022508 */
  {
    die(pActwk); /* Line 214, Address: 0x102251c */
    return; /* Line 215, Address: 0x1022528 */
  }
  subactwk->actno = pActwk->actno; /* Line 217, Address: 0x1022530 */
  subactwk->xposi.w.h = pActwk->xposi.w.h - 21; /* Line 218, Address: 0x1022540 */
  subactwk->yposi.w.h = pActwk->yposi.w.h - 7; /* Line 219, Address: 0x1022564 */
  subactwk->userflag.b.h = -1; /* Line 220, Address: 0x1022588 */
  ((short*)subactwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 221, Address: 0x1022594 */

  if (actwkchk(&subactwk) != 0) /* Line 223, Address: 0x10225d4 */
  {
    die(pActwk); /* Line 225, Address: 0x10225e8 */
    return; /* Line 226, Address: 0x10225f4 */
  }
  subactwk->actno = pActwk->actno; /* Line 228, Address: 0x10225fc */
  subactwk->xposi.w.h = pActwk->xposi.w.h - 88; /* Line 229, Address: 0x102260c */
  subactwk->yposi.w.h = pActwk->yposi.w.h - 4; /* Line 230, Address: 0x1022630 */
  subactwk->userflag.b.h = 1; /* Line 231, Address: 0x1022654 */
  ((short*)subactwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 232, Address: 0x1022660 */

  if (actwkchk(&subactwk) != 0) /* Line 234, Address: 0x10226a0 */
  {
    die(pActwk); /* Line 236, Address: 0x10226b4 */
    return; /* Line 237, Address: 0x10226c0 */
  }
  subactwk->actno = 47; /* Line 239, Address: 0x10226c8 */
  subactwk->xposi.w.h = pActwk->xposi.w.h - 76; /* Line 240, Address: 0x10226d4 */
  subactwk->yposi.w.h = pActwk->yposi.w.h - 28; /* Line 241, Address: 0x10226f8 */
  subactwk->userflag.b.h = -128; /* Line 242, Address: 0x102271c */
  ((short*)subactwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 243, Address: 0x1022728 */

  if (actwkchk(&subactwk) != 0) /* Line 245, Address: 0x1022768 */
  {
    die(pActwk); /* Line 247, Address: 0x102277c */
    return; /* Line 248, Address: 0x1022788 */
  }
  subactwk->actno = 47; /* Line 250, Address: 0x1022790 */
  subactwk->xposi.w.h = pActwk->xposi.w.h - 84; /* Line 251, Address: 0x102279c */
  subactwk->yposi.w.h = pActwk->yposi.w.h - 17; /* Line 252, Address: 0x10227c0 */
  subactwk->userflag.b.h = -127; /* Line 253, Address: 0x10227e4 */
  ((short*)subactwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 254, Address: 0x10227f0 */
} /* Line 255, Address: 0x1022830 */



void mm_wait(sprite_status* pActwk) { /* Line 259, Address: 0x1022840 */
  if (pActwk->colicnt) /* Line 260, Address: 0x102284c */
  {
    pActwk->colino = 0; /* Line 262, Address: 0x102285c */
    pActwk->colicnt = 0; /* Line 263, Address: 0x1022864 */
    pActwk->r_no0 += 2; /* Line 264, Address: 0x102286c */
  }
  hitchk(pActwk, &actwk[0]); /* Line 266, Address: 0x102287c */
} /* Line 267, Address: 0x1022890 */



void mm_die(sprite_status* pActwk) { /* Line 271, Address: 0x10228a0 */
  pActwk->r_no0 += 2; /* Line 272, Address: 0x10228ac */
  pActwk->patno = 1; /* Line 273, Address: 0x10228bc */
  pActwk->actfree[21] = 255; /* Line 274, Address: 0x10228c8 */

  if (hitchk(pActwk, &actwk[0])) ride_on_clr(pActwk, &actwk[0]); /* Line 276, Address: 0x10228d4 */
} /* Line 277, Address: 0x1022904 */



void m_baku(sprite_status* pActwk) { /* Line 281, Address: 0x1022920 */
  char* temp;
  unsigned char timeb;
  char xx, yy;
  sprite_status* subactwk;

  temp = ((char**)pActwk)[12]; /* Line 287, Address: 0x102293c */
  if (*temp >= 0) /* Line 288, Address: 0x1022944 */
  {
    ((unsigned short*)pActwk)[23] += 256; /* Line 290, Address: 0x1022958 */
    timeb = ((unsigned short*)pActwk)[23] >> 8; /* Line 291, Address: 0x1022968 */
    if (timeb == *temp) /* Line 292, Address: 0x1022980 */
    {
      ++temp; /* Line 294, Address: 0x1022998 */
      xx = *temp; /* Line 295, Address: 0x102299c */
      ++temp; /* Line 296, Address: 0x10229a8 */
      yy = *temp; /* Line 297, Address: 0x10229ac */
      ++temp; /* Line 298, Address: 0x10229b8 */
      ((char**)pActwk)[12] = temp; /* Line 299, Address: 0x10229bc */
      if (actwkchk(&subactwk) == 0) /* Line 300, Address: 0x10229c4 */
      {
        subactwk->actno = 24; /* Line 302, Address: 0x10229d8 */
        subactwk->r_no1 = 1; /* Line 303, Address: 0x10229e4 */
        subactwk->xposi.w.h = pActwk->xposi.w.h; /* Line 304, Address: 0x10229f0 */
        subactwk->yposi.w.h = pActwk->yposi.w.h; /* Line 305, Address: 0x1022a00 */
        subactwk->xposi.w.h += (unsigned short)xx; /* Line 306, Address: 0x1022a10 */
        subactwk->yposi.w.h += (unsigned short)yy; /* Line 307, Address: 0x1022a30 */
        soundset(158); /* Line 308, Address: 0x1022a50 */
      }
    }
  } /* Line 311, Address: 0x1022a5c */
  else
  {
    pActwk->r_no0 += 2; /* Line 314, Address: 0x1022a64 */
    ((short*)pActwk)[23] = 60; /* Line 315, Address: 0x1022a74 */
  }
} /* Line 317, Address: 0x1022a80 */



void mm1wait(sprite_status* pActwk) { /* Line 321, Address: 0x1022aa0 */
  --((unsigned short*)pActwk)[23]; /* Line 322, Address: 0x1022aac */
  if (!((unsigned short*)pActwk)[23]) /* Line 323, Address: 0x1022abc */
  {
    projector_flag = 255; /* Line 325, Address: 0x1022acc */
    die(pActwk); /* Line 326, Address: 0x1022ad8 */
  }
} /* Line 328, Address: 0x1022ae4 */



void sub(sprite_status* pActwk) { /* Line 332, Address: 0x1022b00 */
  short subact;

  subact = ((short*)pActwk)[33]; /* Line 335, Address: 0x1022b10 */
  if (actwk[subact].actno != 82) /* Line 336, Address: 0x1022b20 */
  {
    die(pActwk); /* Line 338, Address: 0x1022b54 */
    return; /* Line 339, Address: 0x1022b60 */
  }
  if (actwk[subact].actfree[21]) /* Line 341, Address: 0x1022b68 */
  {
    die(pActwk); /* Line 343, Address: 0x1022b94 */
    return; /* Line 344, Address: 0x1022ba0 */
  }
  if (pActwk->r_no0) /* Line 346, Address: 0x1022ba8 */
  {
    s_move(pActwk); /* Line 348, Address: 0x1022bb8 */
    return; /* Line 349, Address: 0x1022bc4 */
  }
  s_init(pActwk); /* Line 351, Address: 0x1022bcc */
} /* Line 352, Address: 0x1022bd8 */



void s_init(sprite_status* pActwk) { /* Line 356, Address: 0x1022bf0 */
  pActwk->r_no0 += 2; /* Line 357, Address: 0x1022bfc */
  pActwk->actflg |= 4; /* Line 358, Address: 0x1022c0c */
  pActwk->sprpri = 4; /* Line 359, Address: 0x1022c1c */
  pActwk->sproffset = 944; /* Line 360, Address: 0x1022c28 */
  pActwk->patbase = pat_movie; /* Line 361, Address: 0x1022c34 */
  if (pActwk->userflag.b.h < 0) /* Line 362, Address: 0x1022c44 */
  {

    pActwk->sprhs = 8; /* Line 365, Address: 0x1022c5c */
    pActwk->sprhsize = 8; /* Line 366, Address: 0x1022c68 */
    pActwk->sprvsize = 4; /* Line 367, Address: 0x1022c74 */
    pActwk->mstno.b.h = 0; /* Line 368, Address: 0x1022c80 */
  } /* Line 369, Address: 0x1022c88 */
  else
  {

    pActwk->sprhs = 20; /* Line 373, Address: 0x1022c90 */
    pActwk->sprhsize = 20; /* Line 374, Address: 0x1022c9c */
    pActwk->sprvsize = 24; /* Line 375, Address: 0x1022ca8 */
    pActwk->mstno.b.h = 1; /* Line 376, Address: 0x1022cb4 */
  }
  s_move(pActwk); /* Line 378, Address: 0x1022cc0 */
} /* Line 379, Address: 0x1022ccc */



void s_move(sprite_status* pActwk) { /* Line 383, Address: 0x1022ce0 */

  patchg(pActwk, movie1_pchg); /* Line 385, Address: 0x1022cec */
  actionsub(pActwk); /* Line 386, Address: 0x1022d00 */
} /* Line 387, Address: 0x1022d0c */
