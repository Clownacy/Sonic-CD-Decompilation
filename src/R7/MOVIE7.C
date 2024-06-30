#include "..\EQU.H"
#include "MOVIE7.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"

static void die(sprite_status* pActwk);
static void m_init(sprite_status* pActwk);
static void m_wait(sprite_status* pActwk);
static void m_die(sprite_status* pActwk);
static void m_baku(sprite_status* pActwk);
static void m1wait(sprite_status* pActwk);
static void sub(sprite_status* pActwk);
static void s_init(sprite_status* pActwk);
static void s_move(sprite_status* pActwk);

unsigned char movie1_pchg00[6] = { 0, 2, 1, 3, 1, 255 };
unsigned char movie1_pchg01[58] = {
  0, 4, 4, 1, 4, 4, 1, 4, 4, 1,
  4, 4, 1, 4, 4, 1, 1, 4, 4, 1,
  1, 4, 4, 1, 1, 4, 4, 1, 1, 5,
  5, 1, 5, 5, 1, 5, 5, 1, 5, 5,
  1, 5, 5, 1, 1, 5, 5, 1, 1, 5,
  5, 1, 1, 5, 5, 1, 1, 255
};
unsigned char* movie1_pchg[2] = {
  movie1_pchg00,
  movie1_pchg01
};
sprite_pattern spr_movie1 = {
  1,
  { { -12, -12, 0, 447 } }
};
sprite_pattern spr_movie2 = {
  1,
  { { -8, -4, 0, 448 } }
};
sprite_pattern spr_movie3 = {
  1,
  { { -8, -4, 0, 449 } }
};
sprite_pattern spr_movie4 = {
  1,
  { { -20, -24, 0, 450 } }
};
sprite_pattern spr_movie5 = {
  1,
  { { -20, -24, 0, 451 } }
};
sprite_pattern spr_movie0 = {
  0,
  { { -20, -24, 0, 451 } }
};
sprite_pattern* pat_movie[6] = {
  &spr_movie1,
  &spr_movie0,
  &spr_movie2,
  &spr_movie3,
  &spr_movie4,
  &spr_movie5
};
char tbl0[37] = {
    1,   0,   0,   5, -18, -10, 10, -10, 10, 15,
    0, -18,  20, -10,  18, 22, 8, 23, 25, 13,
  -10,  28,  -3, -25,  30, 10, 20, 32, -10, 2,
   35,  13, -10,  40, -10, 10, -1
};

























































































void movie(sprite_status* pActwk) { /* Line 159, Address: 0x10214c0 */
  void(*tbl_m[5])(sprite_status*) = /* Line 160, Address: 0x10214cc */
  {
    &m_init,
    &m_wait,
    &m_die,
    &m_baku,
    &m1wait
  };

  if (pActwk->userflag.b.h) /* Line 169, Address: 0x10214f8 */
    sub(pActwk); /* Line 170, Address: 0x1021508 */
  else
  {
    tbl_m[pActwk->r_no0 / 2](pActwk); /* Line 173, Address: 0x102151c */
    actionsub(pActwk); /* Line 174, Address: 0x1021558 */
    if (pActwk->r_no0 <= 2) /* Line 175, Address: 0x1021564 */
      frameout_s(pActwk); /* Line 176, Address: 0x102157c */
  }
} /* Line 178, Address: 0x1021588 */




void die(sprite_status* pActwk) { /* Line 183, Address: 0x10215a0 */
  frameout(pActwk); /* Line 184, Address: 0x10215ac */
} /* Line 185, Address: 0x10215b8 */




void m_init(sprite_status* pActwk) { /* Line 190, Address: 0x10215d0 */
  sprite_status* subactwk;

  if (projector_flag) /* Line 193, Address: 0x10215dc */
  {
    die(pActwk); /* Line 195, Address: 0x10215ec */
    return; /* Line 196, Address: 0x10215f8 */
  }
  divdevset(5); /* Line 198, Address: 0x1021600 */

  pActwk->r_no0 += 2; /* Line 200, Address: 0x102160c */
  pActwk->actflg |= 4; /* Line 201, Address: 0x102161c */
  pActwk->sprpri = 4; /* Line 202, Address: 0x102162c */
  pActwk->sprhs = 12; /* Line 203, Address: 0x1021638 */
  pActwk->sprhsize = 12; /* Line 204, Address: 0x1021644 */
  pActwk->sprvsize = 12; /* Line 205, Address: 0x1021650 */
  pActwk->colino = 251; /* Line 206, Address: 0x102165c */
  pActwk->sproffset = 1199; /* Line 207, Address: 0x1021668 */
  pActwk->patbase = pat_movie; /* Line 208, Address: 0x1021674 */
  ((char**)pActwk)[12] = tbl0; /* Line 209, Address: 0x1021684 */

  if (actwkchk(&subactwk) != 0) /* Line 211, Address: 0x1021694 */
  {
    die(pActwk); /* Line 213, Address: 0x10216a8 */
    return; /* Line 214, Address: 0x10216b4 */
  }
  subactwk->actno = pActwk->actno; /* Line 216, Address: 0x10216bc */
  subactwk->xposi.w.h = pActwk->xposi.w.h - 21; /* Line 217, Address: 0x10216cc */
  subactwk->yposi.w.h = pActwk->yposi.w.h - 7; /* Line 218, Address: 0x10216f0 */
  subactwk->userflag.b.h = -1; /* Line 219, Address: 0x1021714 */
  ((short*)subactwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 220, Address: 0x1021720 */

  if (actwkchk(&subactwk) != 0) /* Line 222, Address: 0x1021760 */
  {
    die(pActwk); /* Line 224, Address: 0x1021774 */
    return; /* Line 225, Address: 0x1021780 */
  }
  subactwk->actno = pActwk->actno; /* Line 227, Address: 0x1021788 */
  subactwk->xposi.w.h = pActwk->xposi.w.h - 88; /* Line 228, Address: 0x1021798 */
  subactwk->yposi.w.h = pActwk->yposi.w.h - 4; /* Line 229, Address: 0x10217bc */
  subactwk->userflag.b.h = 1; /* Line 230, Address: 0x10217e0 */
  ((short*)subactwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 231, Address: 0x10217ec */

  if (actwkchk(&subactwk) != 0) /* Line 233, Address: 0x102182c */
  {
    die(pActwk); /* Line 235, Address: 0x1021840 */
    return; /* Line 236, Address: 0x102184c */
  }
  subactwk->actno = 40; /* Line 238, Address: 0x1021854 */
  subactwk->xposi.w.h = pActwk->xposi.w.h - 88; /* Line 239, Address: 0x1021860 */
  subactwk->yposi.w.h = pActwk->yposi.w.h - 24; /* Line 240, Address: 0x1021884 */
  subactwk->userflag.b.h = -128; /* Line 241, Address: 0x10218a8 */
  ((short*)subactwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 242, Address: 0x10218b4 */

  if (actwkchk(&subactwk) != 0) /* Line 244, Address: 0x10218f4 */
  {
    die(pActwk); /* Line 246, Address: 0x1021908 */
    return; /* Line 247, Address: 0x1021914 */
  }
  subactwk->actno = 40; /* Line 249, Address: 0x102191c */
  subactwk->xposi.w.h = pActwk->xposi.w.h - 98; /* Line 250, Address: 0x1021928 */
  subactwk->yposi.w.h = (int)pActwk->yposi.w.h; /* Line 251, Address: 0x102194c */
  subactwk->userflag.b.h = -127; /* Line 252, Address: 0x102196c */
  ((short*)subactwk)[33] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 253, Address: 0x1021978 */
} /* Line 254, Address: 0x10219b8 */



void m_wait(sprite_status* pActwk) { /* Line 258, Address: 0x10219d0 */
  if (pActwk->colicnt) /* Line 259, Address: 0x10219dc */
  {
    pActwk->colino = 0; /* Line 261, Address: 0x10219ec */
    pActwk->colicnt = 0; /* Line 262, Address: 0x10219f4 */
    pActwk->r_no0 += 2; /* Line 263, Address: 0x10219fc */
  }
  hitchk(pActwk, &actwk[0]); /* Line 265, Address: 0x1021a0c */
} /* Line 266, Address: 0x1021a20 */



void m_die(sprite_status* pActwk) { /* Line 270, Address: 0x1021a30 */
  pActwk->r_no0 += 2; /* Line 271, Address: 0x1021a3c */
  pActwk->patno = 1; /* Line 272, Address: 0x1021a4c */
  pActwk->actfree[21] = 255; /* Line 273, Address: 0x1021a58 */
  divdevset(4); /* Line 274, Address: 0x1021a64 */
  if (hitchk(pActwk, &actwk[0])) ride_on_clr(pActwk, &actwk[0]); /* Line 275, Address: 0x1021a70 */
} /* Line 276, Address: 0x1021aa0 */



void m_baku(sprite_status* pActwk) { /* Line 280, Address: 0x1021ab0 */
  char* temp;
  unsigned char timeb;
  char xx, yy;
  sprite_status* subactwk;

  temp = ((char**)pActwk)[12]; /* Line 286, Address: 0x1021acc */
  if (*temp >= 0) /* Line 287, Address: 0x1021ad4 */
  {
    ((unsigned short*)pActwk)[23] += 256; /* Line 289, Address: 0x1021ae8 */
    timeb = ((unsigned short*)pActwk)[23] >> 8; /* Line 290, Address: 0x1021af8 */
    if (timeb == *temp) /* Line 291, Address: 0x1021b10 */
    {
      ++temp; /* Line 293, Address: 0x1021b28 */
      xx = *temp; /* Line 294, Address: 0x1021b2c */
      ++temp; /* Line 295, Address: 0x1021b38 */
      yy = *temp; /* Line 296, Address: 0x1021b3c */
      ++temp; /* Line 297, Address: 0x1021b48 */
      ((char**)pActwk)[12] = temp; /* Line 298, Address: 0x1021b4c */
      if (actwkchk(&subactwk) == 0) /* Line 299, Address: 0x1021b54 */
      {
        subactwk->actno = 24; /* Line 301, Address: 0x1021b68 */
        subactwk->r_no1 = 1; /* Line 302, Address: 0x1021b74 */
        subactwk->xposi.w.h = pActwk->xposi.w.h; /* Line 303, Address: 0x1021b80 */
        subactwk->yposi.w.h = pActwk->yposi.w.h; /* Line 304, Address: 0x1021b90 */
        subactwk->xposi.w.h += (unsigned short)xx; /* Line 305, Address: 0x1021ba0 */
        subactwk->yposi.w.h += (unsigned short)yy; /* Line 306, Address: 0x1021bc0 */
        soundset(158); /* Line 307, Address: 0x1021be0 */
      }
    }
  } /* Line 310, Address: 0x1021bec */
  else
  {
    pActwk->r_no0 += 2; /* Line 313, Address: 0x1021bf4 */
    ((unsigned short*)pActwk)[23] = 60; /* Line 314, Address: 0x1021c04 */
  }
} /* Line 316, Address: 0x1021c10 */



void m1wait(sprite_status* pActwk) { /* Line 320, Address: 0x1021c30 */
  --((unsigned short*)pActwk)[23]; /* Line 321, Address: 0x1021c3c */
  if (!((unsigned short*)pActwk)[23]) /* Line 322, Address: 0x1021c4c */
  {
    projector_flag = 255; /* Line 324, Address: 0x1021c5c */
    die(pActwk); /* Line 325, Address: 0x1021c68 */
  }
} /* Line 327, Address: 0x1021c74 */



void sub(sprite_status* pActwk) { /* Line 331, Address: 0x1021c90 */
  short subact;

  subact = ((short*)pActwk)[33]; /* Line 334, Address: 0x1021ca0 */
  if (actwk[subact].actno != 39) /* Line 335, Address: 0x1021cb0 */
  {
    die(pActwk); /* Line 337, Address: 0x1021ce4 */
    return; /* Line 338, Address: 0x1021cf0 */
  }
  if (actwk[subact].actfree[21]) /* Line 340, Address: 0x1021cf8 */
  {
    die(pActwk); /* Line 342, Address: 0x1021d24 */
    return; /* Line 343, Address: 0x1021d30 */
  }
  if (pActwk->r_no0) /* Line 345, Address: 0x1021d38 */
  {
    s_move(pActwk); /* Line 347, Address: 0x1021d48 */
    return; /* Line 348, Address: 0x1021d54 */
  }
  s_init(pActwk); /* Line 350, Address: 0x1021d5c */
} /* Line 351, Address: 0x1021d68 */



void s_init(sprite_status* pActwk) { /* Line 355, Address: 0x1021d80 */
  pActwk->r_no0 += 2; /* Line 356, Address: 0x1021d8c */
  pActwk->actflg |= 4; /* Line 357, Address: 0x1021d9c */
  pActwk->sprpri = 4; /* Line 358, Address: 0x1021dac */
  pActwk->sproffset = 1199; /* Line 359, Address: 0x1021db8 */
  pActwk->patbase = pat_movie; /* Line 360, Address: 0x1021dc4 */
  if (pActwk->userflag.b.h < 0) /* Line 361, Address: 0x1021dd4 */
  {

    pActwk->sprhs = 8; /* Line 364, Address: 0x1021dec */
    pActwk->sprhsize = 8; /* Line 365, Address: 0x1021df8 */
    pActwk->sprvsize = 4; /* Line 366, Address: 0x1021e04 */
    pActwk->mstno.b.h = 0; /* Line 367, Address: 0x1021e10 */
  } /* Line 368, Address: 0x1021e18 */
  else
  {

    pActwk->sprhs = 20; /* Line 372, Address: 0x1021e20 */
    pActwk->sprhsize = 20; /* Line 373, Address: 0x1021e2c */
    pActwk->sprvsize = 24; /* Line 374, Address: 0x1021e38 */
    pActwk->mstno.b.h = 1; /* Line 375, Address: 0x1021e44 */
  }
  s_move(pActwk); /* Line 377, Address: 0x1021e50 */
} /* Line 378, Address: 0x1021e5c */



void s_move(sprite_status* pActwk) { /* Line 382, Address: 0x1021e70 */

  patchg(pActwk, movie1_pchg); /* Line 384, Address: 0x1021e7c */
  actionsub(pActwk); /* Line 385, Address: 0x1021e90 */
} /* Line 386, Address: 0x1021e9c */
