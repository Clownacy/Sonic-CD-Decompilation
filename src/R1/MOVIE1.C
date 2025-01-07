#include "..\EQU.H"
#include "MOVIE1.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"

#if defined(R11B)
  #define SPRITE_MOVIE_BASE 528
#elif defined(R11C) || defined(R11D)
  #define SPRITE_MOVIE_BASE 509
#elif defined(R12A) || defined(R12B)
  #define SPRITE_MOVIE_BASE 519
#elif defined(R12C) || defined(R12D)
  #define SPRITE_MOVIE_BASE 510
#else
  #define SPRITE_MOVIE_BASE 543
#endif

unsigned char movie1_pchg00[6] = { 0, 2, 1, 3, 1, 255 };
unsigned char movie1_pchg01[58] =
{
  0,
  4, 4, 1, 4,
  4, 1, 4, 4,
  1, 4, 4, 1,
  4, 4, 1, 1,
  4, 4, 1, 1,
  4, 4, 1, 1,
  4, 4, 1, 1,
  5, 5, 1, 5,
  5, 1, 5, 5,
  1, 5, 5, 1,
  5, 5, 1, 1,
  5, 5, 1, 1,
  5, 5, 1, 1,
  5, 5, 1, 1,
  255
};
unsigned char* movie1_pchg[2] =
{
  movie1_pchg00,
  movie1_pchg01
};
sprite_pattern spr_movie1 =
{
  1,
  { { -12, -12, 0, SPRITE_MOVIE_BASE } }
};
sprite_pattern spr_movie2 =
{
  1,
  { { -8, -4, 0, SPRITE_MOVIE_BASE + 1 } }
};
sprite_pattern spr_movie3 =
{
  1,
  { { -8, -4, 0, SPRITE_MOVIE_BASE + 2 } }
};
sprite_pattern spr_movie4 =
{
  1,
  { { -20, -24, 0, SPRITE_MOVIE_BASE + 3 } }
};
sprite_pattern spr_movie5 =
{
  1,
  { { -20, -24, 0, SPRITE_MOVIE_BASE + 4 } }
};
sprite_pattern spr_movie0 =
{
  0,
  { { -20, -24, 0, SPRITE_MOVIE_BASE + 4 } }
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
    1,   0,   0,   5,
  -18, -10,  10, -10,
   10,  15,   0, -18,
   20, -10,  18,  22,
    8,  23,  25,  13,
  -10,  28,  -3, -25,
   30,  10,  20,  32,
  -10,   2,  35,  13,
  -10,  40, -10,  10,
  -1
};






















































void movie1(sprite_status* pActwk) { /* Line 152, Address: 0x1029530 */
  void(*tbl_m[5])(sprite_status*) = /* Line 153, Address: 0x102953c */
  {
    &mm_init,
    &mm_wait,
    &mm_die,
    &m_baku,
    &mm1wait
  };

  if (pActwk->userflag.b.h) /* Line 162, Address: 0x1029568 */
    sub(pActwk); /* Line 163, Address: 0x1029578 */
  else
  {
    tbl_m[pActwk->r_no0 / 2](pActwk); /* Line 166, Address: 0x102958c */
    actionsub(pActwk); /* Line 167, Address: 0x10295c8 */
    if (pActwk->r_no0 <= 2) /* Line 168, Address: 0x10295d4 */
    {
      if (frameout_s(pActwk) != 0) return; /* Line 170, Address: 0x10295ec */
      divdevset(4); /* Line 171, Address: 0x1029600 */
    }
  }
} /* Line 174, Address: 0x102960c */




void die(sprite_status* pActwk) { /* Line 179, Address: 0x1029620 */
  frameout(pActwk); /* Line 180, Address: 0x102962c */
} /* Line 181, Address: 0x1029638 */




void mm_init(sprite_status* pActwk) { /* Line 186, Address: 0x1029650 */
  sprite_status* subactwk;

  if (projector_flag) /* Line 189, Address: 0x102965c */
  {
    die(pActwk); /* Line 191, Address: 0x102966c */
    return; /* Line 192, Address: 0x1029678 */
  }
  divdevset(5); /* Line 194, Address: 0x1029680 */

  pActwk->r_no0 += 2; /* Line 196, Address: 0x102968c */
  pActwk->actflg |= 4; /* Line 197, Address: 0x102969c */
  pActwk->sprpri = 4; /* Line 198, Address: 0x10296ac */
  pActwk->sprhs = 12; /* Line 199, Address: 0x10296b8 */
  pActwk->sprhsize = 12; /* Line 200, Address: 0x10296c4 */
  pActwk->sprvsize = 12; /* Line 201, Address: 0x10296d0 */
  pActwk->colino = 251; /* Line 202, Address: 0x10296dc */

  if (stageno.b.l) pActwk->sproffset = 9135; /* Line 204, Address: 0x10296e8 */
  else pActwk->sproffset = 1027; /* Line 205, Address: 0x102970c */

  pActwk->patbase = pat_movie; /* Line 207, Address: 0x1029718 */
  ((char**)pActwk)[12] = tbl0; /* Line 208, Address: 0x1029728 */

  if (actwkchk(&subactwk) != 0) /* Line 210, Address: 0x1029738 */
  {
    die(pActwk); /* Line 212, Address: 0x102974c */
    return; /* Line 213, Address: 0x1029758 */
  }
  subactwk->actno = pActwk->actno; /* Line 215, Address: 0x1029760 */
  subactwk->xposi.w.h = pActwk->xposi.w.h - 21; /* Line 216, Address: 0x1029770 */
  subactwk->yposi.w.h = pActwk->yposi.w.h - 7; /* Line 217, Address: 0x1029794 */
  subactwk->userflag.b.h = -1; /* Line 218, Address: 0x10297b8 */
  ((short*)subactwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 219, Address: 0x10297c4 */

  if (actwkchk(&subactwk) != 0) /* Line 221, Address: 0x1029804 */
  {
    die(pActwk); /* Line 223, Address: 0x1029818 */
    return; /* Line 224, Address: 0x1029824 */
  }
  subactwk->actno = pActwk->actno; /* Line 226, Address: 0x102982c */
  subactwk->xposi.w.h = pActwk->xposi.w.h - 88; /* Line 227, Address: 0x102983c */
  subactwk->yposi.w.h = pActwk->yposi.w.h - 4; /* Line 228, Address: 0x1029860 */
  subactwk->userflag.b.h = 1; /* Line 229, Address: 0x1029884 */
  ((short*)subactwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 230, Address: 0x1029890 */

  if (actwkchk(&subactwk) != 0) /* Line 232, Address: 0x10298d0 */
  {
    die(pActwk); /* Line 234, Address: 0x10298e4 */
    return; /* Line 235, Address: 0x10298f0 */
  }
  subactwk->actno = 36; /* Line 237, Address: 0x10298f8 */
  subactwk->xposi.w.h = pActwk->xposi.w.h - 88; /* Line 238, Address: 0x1029904 */
  subactwk->yposi.w.h = pActwk->yposi.w.h - 24; /* Line 239, Address: 0x1029928 */
  subactwk->userflag.b.h = -128; /* Line 240, Address: 0x102994c */
  ((short*)subactwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 241, Address: 0x1029958 */

  if (actwkchk(&subactwk) != 0) /* Line 243, Address: 0x1029998 */
  {
    die(pActwk); /* Line 245, Address: 0x10299ac */
    return; /* Line 246, Address: 0x10299b8 */
  }
  subactwk->actno = 36; /* Line 248, Address: 0x10299c0 */
  subactwk->xposi.w.h = pActwk->xposi.w.h - 100; /* Line 249, Address: 0x10299cc */
  subactwk->yposi.w.h = pActwk->yposi.w.h + 4; /* Line 250, Address: 0x10299f0 */
  subactwk->userflag.b.h = -127; /* Line 251, Address: 0x1029a14 */
  ((short*)subactwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 252, Address: 0x1029a20 */
} /* Line 253, Address: 0x1029a60 */



void mm_wait(sprite_status* pActwk) { /* Line 257, Address: 0x1029a70 */
  if (pActwk->colicnt) /* Line 258, Address: 0x1029a7c */
  {
    pActwk->colino = 0; /* Line 260, Address: 0x1029a8c */
    pActwk->colicnt = 0; /* Line 261, Address: 0x1029a94 */
    pActwk->r_no0 += 2; /* Line 262, Address: 0x1029a9c */
  }
  hitchk(pActwk, &actwk[0]); /* Line 264, Address: 0x1029aac */
} /* Line 265, Address: 0x1029ac0 */



void mm_die(sprite_status* pActwk) { /* Line 269, Address: 0x1029ad0 */
  pActwk->r_no0 += 2; /* Line 270, Address: 0x1029adc */
  pActwk->patno = 1; /* Line 271, Address: 0x1029aec */
  pActwk->actfree[21] = 255; /* Line 272, Address: 0x1029af8 */
  divdevset(4); /* Line 273, Address: 0x1029b04 */
  if (hitchk(pActwk, &actwk[0])) ride_on_clr(pActwk, &actwk[0]); /* Line 274, Address: 0x1029b10 */
} /* Line 275, Address: 0x1029b40 */



void m_baku(sprite_status* pActwk) { /* Line 279, Address: 0x1029b50 */
  char* temp;
  unsigned char timeb;
  char xx, yy;
  sprite_status* subactwk;

  temp = ((char**)pActwk)[12]; /* Line 285, Address: 0x1029b6c */
  if (*temp >= 0) /* Line 286, Address: 0x1029b74 */
  {
    ((unsigned short*)pActwk)[23] += 256; /* Line 288, Address: 0x1029b88 */
    timeb = ((unsigned short*)pActwk)[23] >> 8; /* Line 289, Address: 0x1029b98 */
    if (timeb != *temp) return; /* Line 290, Address: 0x1029bb0 */

    ++temp; /* Line 292, Address: 0x1029bc8 */
    xx = *temp; /* Line 293, Address: 0x1029bcc */
    ++temp; /* Line 294, Address: 0x1029bd8 */
    yy = *temp; /* Line 295, Address: 0x1029bdc */
    ++temp; /* Line 296, Address: 0x1029be8 */
    ((char**)pActwk)[12] = temp; /* Line 297, Address: 0x1029bec */
    if (actwkchk(&subactwk) != 0) return; /* Line 298, Address: 0x1029bf4 */

    subactwk->actno = 24; /* Line 300, Address: 0x1029c08 */
    subactwk->r_no1 = 1; /* Line 301, Address: 0x1029c14 */
    subactwk->xposi.w.h = pActwk->xposi.w.h; /* Line 302, Address: 0x1029c20 */
    subactwk->yposi.w.h = pActwk->yposi.w.h; /* Line 303, Address: 0x1029c30 */
    subactwk->xposi.w.h += (unsigned short)xx; /* Line 304, Address: 0x1029c40 */
    subactwk->yposi.w.h += (unsigned short)yy; /* Line 305, Address: 0x1029c60 */
    soundset(158); /* Line 306, Address: 0x1029c80 */


    return; /* Line 309, Address: 0x1029c8c */
  }

  pActwk->r_no0 += 2; /* Line 312, Address: 0x1029c94 */
  ((short*)pActwk)[23] = 60; /* Line 313, Address: 0x1029ca4 */

} /* Line 315, Address: 0x1029cb0 */



void mm1wait(sprite_status* pActwk) { /* Line 319, Address: 0x1029cd0 */
  --((unsigned short*)pActwk)[23]; /* Line 320, Address: 0x1029cdc */
  if (!((unsigned short*)pActwk)[23]) /* Line 321, Address: 0x1029cec */
  {
    projector_flag = 255; /* Line 323, Address: 0x1029cfc */
    die(pActwk); /* Line 324, Address: 0x1029d08 */
  }
} /* Line 326, Address: 0x1029d14 */



void sub(sprite_status* pActwk) { /* Line 330, Address: 0x1029d30 */
  short subact;

  subact = ((short*)pActwk)[33]; /* Line 333, Address: 0x1029d40 */
  if (actwk[subact].actno != 46) /* Line 334, Address: 0x1029d50 */
  {
    die(pActwk); /* Line 336, Address: 0x1029d84 */
    return; /* Line 337, Address: 0x1029d90 */
  }
  if (actwk[subact].actfree[21]) /* Line 339, Address: 0x1029d98 */
  {
    die(pActwk); /* Line 341, Address: 0x1029dc4 */
    return; /* Line 342, Address: 0x1029dd0 */
  }
  if (pActwk->r_no0) /* Line 344, Address: 0x1029dd8 */
  {
    s_move(pActwk); /* Line 346, Address: 0x1029de8 */
    return; /* Line 347, Address: 0x1029df4 */
  }
  s_init(pActwk); /* Line 349, Address: 0x1029dfc */
} /* Line 350, Address: 0x1029e08 */



void s_init(sprite_status* pActwk) { /* Line 354, Address: 0x1029e20 */
  pActwk->r_no0 += 2; /* Line 355, Address: 0x1029e2c */
  pActwk->actflg |= 4; /* Line 356, Address: 0x1029e3c */
  pActwk->sprpri = 4; /* Line 357, Address: 0x1029e4c */

  if (!stageno.b.l) /* Line 359, Address: 0x1029e58 */
    pActwk->sproffset = 1027; /* Line 360, Address: 0x1029e68 */
  else
    pActwk->sproffset = 9135; /* Line 362, Address: 0x1029e7c */

  pActwk->patbase = pat_movie; /* Line 364, Address: 0x1029e88 */
  if (pActwk->userflag.b.h < 0) /* Line 365, Address: 0x1029e98 */
  {

    pActwk->sprhs = 8; /* Line 368, Address: 0x1029eb0 */
    pActwk->sprhsize = 8; /* Line 369, Address: 0x1029ebc */
    pActwk->sprvsize = 4; /* Line 370, Address: 0x1029ec8 */
    pActwk->mstno.b.h = 0; /* Line 371, Address: 0x1029ed4 */
  } /* Line 372, Address: 0x1029edc */
  else
  {

    pActwk->sprhs = 20; /* Line 376, Address: 0x1029ee4 */
    pActwk->sprhsize = 20; /* Line 377, Address: 0x1029ef0 */
    pActwk->sprvsize = 24; /* Line 378, Address: 0x1029efc */
    pActwk->mstno.b.h = 1; /* Line 379, Address: 0x1029f08 */
  }
  s_move(pActwk); /* Line 381, Address: 0x1029f14 */
} /* Line 382, Address: 0x1029f20 */



void s_move(sprite_status* pActwk) { /* Line 386, Address: 0x1029f30 */

  patchg(pActwk, movie1_pchg); /* Line 388, Address: 0x1029f3c */
  actionsub(pActwk); /* Line 389, Address: 0x1029f50 */
} /* Line 390, Address: 0x1029f5c */
