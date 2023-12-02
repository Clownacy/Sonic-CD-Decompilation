#include "..\EQU.H"
#include "KUZURE.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

extern void soundset(short ReqNo);

unsigned char* tblb[];
spr_array* patbase_kuzure_b[];
unsigned char* tbla[];
spr_array* patbase_kuzure_a[];
spr_array* patc[];
spr_array* patd[];






























































void kuzureru_tikei(act_info* pActwk) { /* Line 77, Address: 0x101f240 */
  void(*act_tbl[4])(act_info*) = /* Line 78, Address: 0x101f24c */
  {
    &acta_init,
    &acta_check,
    &actb_wait,
    &actb_down
  };

  act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 86, Address: 0x101f278 */
  actionsub(pActwk); /* Line 87, Address: 0x101f2b4 */
  if (pActwk->r_no0 < 4) frameout_s(pActwk); /* Line 88, Address: 0x101f2c0 */
} /* Line 89, Address: 0x101f2e4 */






void acta_init(act_info* pActwk) { /* Line 96, Address: 0x101f300 */
  spr_array** pPB_kuzure;
  short_union id_no;
  unsigned char** pTbltbl;
  unsigned char* pTbl;
  char userflag;
  char block_x;
  char block_y;

  pActwk->r_no0 += 2; /* Line 105, Address: 0x101f320 */
  pActwk->actflg |= 4; /* Line 106, Address: 0x101f330 */
  pActwk->sprpri = 3; /* Line 107, Address: 0x101f340 */
  pActwk->sproffset = 17598; /* Line 108, Address: 0x101f34c */

  pPB_kuzure = patbase_kuzure_a; /* Line 110, Address: 0x101f358 */
  pTbltbl = tbla; /* Line 111, Address: 0x101f360 */
  userflag = pActwk->userflag.b.h; /* Line 112, Address: 0x101f368 */
  if (userflag < 0) /* Line 113, Address: 0x101f378 */
  {
    pPB_kuzure = patbase_kuzure_b; /* Line 115, Address: 0x101f388 */
    pTbltbl = tblb; /* Line 116, Address: 0x101f390 */
  }
  pActwk->patbase = pPB_kuzure; /* Line 118, Address: 0x101f398 */
  if (userflag & 16) /* Line 119, Address: 0x101f3a0 */
  {
    pActwk->actflg |= 1; /* Line 121, Address: 0x101f3b4 */
    pActwk->cddat |= 1; /* Line 122, Address: 0x101f3c4 */
  }
  id_no.b.h = 0; /* Line 124, Address: 0x101f3d4 */
  id_no.b.l = (unsigned char)userflag & 15; /* Line 125, Address: 0x101f3d8 */
  pActwk->patno = id_no.b.l; /* Line 126, Address: 0x101f3ec */
  pTbl = pTbltbl[id_no.w]; /* Line 127, Address: 0x101f3f8 */

  block_x = pTbl++[0]; /* Line 129, Address: 0x101f40c */
  block_x = (block_x + 1) << 3; /* Line 130, Address: 0x101f420 */
  pActwk->sprhs = block_x; /* Line 131, Address: 0x101f440 */
  pActwk->sprhsize = block_x; /* Line 132, Address: 0x101f448 */

  block_y = pTbl++[0]; /* Line 134, Address: 0x101f450 */
  if (block_y < 0) block_y = -block_y; /* Line 135, Address: 0x101f464 */
  block_y = ((block_y + 1) << 3) + 2; /* Line 136, Address: 0x101f490 */
  pActwk->sprvsize = block_y; /* Line 137, Address: 0x101f4b4 */


} /* Line 140, Address: 0x101f4bc */






void acta_check(act_info* pActwk) { /* Line 147, Address: 0x101f4e0 */
  act_info* pPlayerwk;

  pPlayerwk = &actwk[0]; /* Line 150, Address: 0x101f4f0 */
  if (ridechk(pActwk, pPlayerwk)) /* Line 151, Address: 0x101f4f8 */
  {
    ride_on_clr(pActwk, pPlayerwk); /* Line 153, Address: 0x101f510 */
    soundset(163); /* Line 154, Address: 0x101f520 */
    pActwk->r_no0 += 2; /* Line 155, Address: 0x101f52c */
    if (pActwk->userflag.b.h < 0) actb_init_b(pActwk); /* Line 156, Address: 0x101f53c */
    else actb_init_b(pActwk); /* Line 157, Address: 0x101f568 */
  }
} /* Line 159, Address: 0x101f574 */






void actb_wait(act_info* pActwk) { /* Line 166, Address: 0x101f590 */
  act_info* pPlayerwk;

  --((short*)pActwk)[23]; /* Line 169, Address: 0x101f5a0 */
  if (((short*)pActwk)[23] == 0) /* Line 170, Address: 0x101f5b0 */
  {
    pActwk->r_no0 += 2; /* Line 172, Address: 0x101f5c8 */
  }
  if (pActwk->actfree[20]) /* Line 174, Address: 0x101f5d8 */
  {
    pPlayerwk = &actwk[0]; /* Line 176, Address: 0x101f5e8 */
    if (ridechk(pActwk, pPlayerwk)) /* Line 177, Address: 0x101f5f0 */
    {
      if (((short*)pActwk)[23] == 0) /* Line 179, Address: 0x101f608 */
      {
        ride_on_clr(pActwk, pPlayerwk); /* Line 181, Address: 0x101f620 */
      }
    }
  }
} /* Line 185, Address: 0x101f630 */






void actb_down(act_info* pActwk) { /* Line 192, Address: 0x101f650 */
  act_info* pPlayerwk;
  short yposi;

  pActwk->yposi.l += ((int*)pActwk)[12]; /* Line 196, Address: 0x101f664 */
  ((int*)pActwk)[12] += 16384; /* Line 197, Address: 0x101f67c */

  yposi = pActwk->yposi.w.h; /* Line 199, Address: 0x101f68c */
  pPlayerwk = &actwk[0]; /* Line 200, Address: 0x101f69c */
  yposi -= pPlayerwk->yposi.w.h; /* Line 201, Address: 0x101f6a4 */
  if (yposi >= 513) frameout(pActwk); /* Line 202, Address: 0x101f6b4 */
} /* Line 203, Address: 0x101f6d4 */







void actb_init_a(act_info* pActwk) { /* Line 211, Address: 0x101f6f0 */
  act_info* pActwk_w;
  act_info* pPlayerwk;
  unsigned char** pTbltbl;
  unsigned char* pTbla;
  char patno;
  char userflag;
  short time_x;
  short time_y;
  short posi_x;
  short posi_y;
  short posi_x_start;
  short posi_x_step;
  short reverse_flag;
  short count0x;
  short_union count_x;
  short_union count_y;
  short_union tmp;


  userflag = pActwk->userflag.b.h; /* Line 231, Address: 0x101f720 */
  if (userflag & 16) reverse_flag = 1; /* Line 232, Address: 0x101f730 */
  else reverse_flag = 0; /* Line 233, Address: 0x101f758 */
  pTbltbl = tbla; /* Line 234, Address: 0x101f75c */
  pTbla = pTbltbl[userflag & 15]; /* Line 235, Address: 0x101f768 */
  tmp.w = 0; /* Line 236, Address: 0x101f784 */
  tmp.b.l = pTbla++[0]; /* Line 237, Address: 0x101f788 */
  count0x = tmp.w; /* Line 238, Address: 0x101f798 */
  tmp.w *= 8; /* Line 239, Address: 0x101f7a0 */
  time_x = -16; /* Line 240, Address: 0x101f7ac */
  if (reverse_flag == 0) /* Line 241, Address: 0x101f7b8 */
  {
    tmp.w = -tmp.w; /* Line 243, Address: 0x101f7c8 */
    time_x = -time_x; /* Line 244, Address: 0x101f7d4 */
  }
  tmp.w += pActwk->xposi.w.h; /* Line 246, Address: 0x101f7e0 */
  posi_x_start = tmp.w; /* Line 247, Address: 0x101f7f4 */
  posi_x_step = time_x; /* Line 248, Address: 0x101f7fc */
  count_y.w = 0; /* Line 249, Address: 0x101f800 */
  count_y.b.l = pTbla++[0]; /* Line 250, Address: 0x101f804 */
  posi_y = count_y.w; /* Line 251, Address: 0x101f814 */
  posi_y *= 8; /* Line 252, Address: 0x101f820 */
  posi_y += pActwk->yposi.w.h; /* Line 253, Address: 0x101f82c */
  time_y = 9; /* Line 254, Address: 0x101f840 */
  pActwk->actfree[21] = pActwk->actno; /* Line 255, Address: 0x101f84c */
  do
  {
    count_x.w = count0x; /* Line 258, Address: 0x101f85c */
    posi_x = posi_x_start; /* Line 259, Address: 0x101f864 */
    time_x = time_y; /* Line 260, Address: 0x101f870 */
    do
    {
      if (actwkchk(&pActwk_w) != 0) /* Line 263, Address: 0x101f878 */
      {
        pPlayerwk = &actwk[0]; /* Line 265, Address: 0x101f88c */
        if (ridechk(pActwk, pPlayerwk)) ride_on_clr(pActwk, pPlayerwk); /* Line 266, Address: 0x101f894 */
        frameout(pActwk); /* Line 267, Address: 0x101f8bc */
        return; /* Line 268, Address: 0x101f8c8 */
      }
      patno = pTbla++[0]; /* Line 270, Address: 0x101f8d0 */
      if (patno >= 0) /* Line 271, Address: 0x101f8e4 */
      {
        pActwk_w->patno = patno; /* Line 273, Address: 0x101f8f4 */
        pActwk_w->actflg |= 4; /* Line 274, Address: 0x101f8fc */
        pActwk_w->sprpri = 3; /* Line 275, Address: 0x101f90c */
        pActwk_w->sproffset = 17598; /* Line 276, Address: 0x101f918 */
        pActwk_w->patbase = patc; /* Line 277, Address: 0x101f924 */
        ((int*)pActwk)[12] = 2; /* Line 278, Address: 0x101f934 */
        pActwk_w->actno = pActwk->actfree[21]; /* Line 279, Address: 0x101f940 */
        pActwk_w->r_no0 = pActwk->r_no0; /* Line 280, Address: 0x101f950 */
        if (reverse_flag) /* Line 281, Address: 0x101f960 */
        {
          pActwk_w->actflg |= 1; /* Line 283, Address: 0x101f968 */
          pActwk_w->cddat |= 1; /* Line 284, Address: 0x101f978 */
        }
        if (count_y.w == 0) /* Line 286, Address: 0x101f988 */
        {
          pActwk_w->actfree[20] = 255; /* Line 288, Address: 0x101f99c */
          pActwk_w->sprhs = 8; /* Line 289, Address: 0x101f9a8 */
          pActwk_w->sprhsize = 8; /* Line 290, Address: 0x101f9b4 */
          pActwk_w->sprvsize = 9; /* Line 291, Address: 0x101f9c0 */
        }
        pActwk_w->yposi.w.h = posi_y; /* Line 293, Address: 0x101f9cc */
        pActwk_w->xposi.w.h = posi_x; /* Line 294, Address: 0x101f9d4 */
        ((short*)pActwk_w)[23] = time_x; /* Line 295, Address: 0x101f9dc */
      }
      posi_x += posi_x_step; /* Line 297, Address: 0x101f9e4 */
      time_x += 12; /* Line 298, Address: 0x101f9f4 */
    } while (--count_x.w >= 0); /* Line 299, Address: 0x101fa00 */

    posi_y -= 16; /* Line 301, Address: 0x101fa24 */
    time_y += 5; /* Line 302, Address: 0x101fa30 */
  } while (--count_y.w >= 0); /* Line 303, Address: 0x101fa3c */

  frameout(pActwk); /* Line 305, Address: 0x101fa60 */
} /* Line 306, Address: 0x101fa6c */







void actb_init_b(act_info* pActwk) { /* Line 314, Address: 0x101faa0 */
  act_info* pActwk_w;
  act_info* pPlayerwk;
  unsigned char** pTbltbl;
  unsigned char* pTblb;
  char userflag;
  unsigned char sprvsize;
  short time_w;
  short d3;
  short d4;
  short_union d5;
  short d6;
  short xspeed;

  userflag = pActwk->userflag.b.h; /* Line 328, Address: 0x101fad0 */
  pTbltbl = tblb; /* Line 329, Address: 0x101fae0 */
  pTblb = tblb[userflag & 31]; /* Line 330, Address: 0x101faec */
  d5.b.l = pTblb++[0]; /* Line 331, Address: 0x101fb0c */
  sprvsize = pTblb++[0]; /* Line 332, Address: 0x101fb1c */
  ++sprvsize; /* Line 333, Address: 0x101fb2c */
  sprvsize <<= 3; /* Line 334, Address: 0x101fb34 */
  sprvsize += 2; /* Line 335, Address: 0x101fb44 */
  d5.w &= 255; /* Line 336, Address: 0x101fb4c */
  d4 = d5.w; /* Line 337, Address: 0x101fb58 */
  d4 <<= 3; /* Line 338, Address: 0x101fb64 */
  d4 = -d4; /* Line 339, Address: 0x101fb70 */
  d3 = 16; /* Line 340, Address: 0x101fb7c */
  d6 = 1; /* Line 341, Address: 0x101fb88 */
  if ((userflag & 64) == 0) /* Line 342, Address: 0x101fb94 */
  {
    userflag <<= 2; /* Line 344, Address: 0x101fba8 */
    if (userflag < 0) /* Line 345, Address: 0x101fbb4 */
    {
      pTblb += d5.w; /* Line 347, Address: 0x101fbc4 */
      d4 = -d4; /* Line 348, Address: 0x101fbd4 */
      d3 = -d3; /* Line 349, Address: 0x101fbe0 */
      d6 = -d6; /* Line 350, Address: 0x101fbec */
    }
  } /* Line 352, Address: 0x101fbf8 */
  else
  {
    pPlayerwk = &actwk[0]; /* Line 355, Address: 0x101fc00 */
    xspeed = pPlayerwk->xspeed.w; /* Line 356, Address: 0x101fc08 */
    if (userflag & 32) xspeed = -xspeed; /* Line 357, Address: 0x101fc14 */
    if (xspeed < 0) /* Line 358, Address: 0x101fc34 */
    {
      pTblb += d5.w; /* Line 360, Address: 0x101fc44 */
      d4 = -d4; /* Line 361, Address: 0x101fc54 */
      d3 = -d3; /* Line 362, Address: 0x101fc60 */
      d6 = -d6; /* Line 363, Address: 0x101fc6c */
    }
  }
  d4 += pActwk->xposi.w.h; /* Line 366, Address: 0x101fc78 */

  time_w = 9; /* Line 368, Address: 0x101fc8c */
  pActwk->actfree[21] = pActwk->actno; /* Line 369, Address: 0x101fc98 */
  do
  {
    if (actwkchk(&pActwk_w) != 0) /* Line 372, Address: 0x101fca8 */
    {
      pPlayerwk = &actwk[0]; /* Line 374, Address: 0x101fcbc */
      if (ridechk(pActwk, pPlayerwk)) ride_on_clr(pActwk, pPlayerwk); /* Line 375, Address: 0x101fcc4 */
      frameout(pActwk); /* Line 376, Address: 0x101fcec */
      return; /* Line 377, Address: 0x101fcf8 */
    }
    pActwk_w->sprpri = 3; /* Line 379, Address: 0x101fd00 */
    pActwk_w->sproffset = 17598; /* Line 380, Address: 0x101fd0c */
    pActwk_w->actflg |= 4; /* Line 381, Address: 0x101fd18 */
    pActwk_w->patbase = patd; /* Line 382, Address: 0x101fd28 */
    ((int*)pActwk)[12] = 2; /* Line 383, Address: 0x101fd38 */
    pActwk_w->actno = pActwk->actfree[21]; /* Line 384, Address: 0x101fd44 */
    pActwk_w->r_no0 = pActwk->r_no0; /* Line 385, Address: 0x101fd54 */
    pActwk_w->yposi.w.h = pActwk->yposi.w.h; /* Line 386, Address: 0x101fd64 */
    pActwk_w->actfree[20] = 255; /* Line 387, Address: 0x101fd74 */
    pActwk_w->sprhs = 8; /* Line 388, Address: 0x101fd80 */
    pActwk_w->sprhsize = 8; /* Line 389, Address: 0x101fd8c */
    pActwk_w->sprvsize = sprvsize; /* Line 390, Address: 0x101fd98 */

    pActwk_w->patno = pTblb[0]; /* Line 392, Address: 0x101fda0 */
    pTblb += d6; /* Line 393, Address: 0x101fdac */
    pActwk_w->xposi.w.h = d4; /* Line 394, Address: 0x101fdb8 */
    d4 += d3; /* Line 395, Address: 0x101fdc0 */
    ((short*)pActwk_w)[23] = time_w; /* Line 396, Address: 0x101fdcc */
    time_w += 12; /* Line 397, Address: 0x101fdd4 */
  } while (--d5.w >= 0); /* Line 398, Address: 0x101fde0 */

  frameout(pActwk); /* Line 400, Address: 0x101fe04 */
} /* Line 401, Address: 0x101fe10 */
