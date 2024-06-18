#include "..\EQU.H"
#include "TOBIRA6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

void(*tobira_tbl[4])(sprite_status*) =
{
  &tobira6_init,
  &tobira6_move,
  &tobira6_chek,
  &tobira6_clse
};
sprite_pattern tpat0 =
{
  1,
  { { -8, -32, 0, 309 } }
};
sprite_pattern tpat1 =
{
  1,
  { { -32, -32, 0, 310 } }
};
sprite_pattern* tobira6pat[2] = {
  &tpat0,
  &tpat1
};












































void tobira6(sprite_status* pActwk) { /* Line 72, Address: 0x10170f0 */
  tobira_tbl[pActwk->r_no0 / 2](pActwk); /* Line 73, Address: 0x10170fc */
  actionsub(pActwk); /* Line 74, Address: 0x1017140 */
  frameout_s(pActwk); /* Line 75, Address: 0x101714c */
} /* Line 76, Address: 0x1017158 */



void tobira6_ridechk(sprite_status* pActwk) { /* Line 80, Address: 0x1017170 */
  ride_on_chk(pActwk, &actwk[0]); /* Line 81, Address: 0x101717c */
} /* Line 82, Address: 0x1017190 */











void tobira6_init(sprite_status* pActwk) { /* Line 94, Address: 0x10171a0 */
  pActwk->r_no0 += 2; /* Line 95, Address: 0x10171ac */
  pActwk->actflg |= 4; /* Line 96, Address: 0x10171bc */
  pActwk->sprpri = 3; /* Line 97, Address: 0x10171cc */
  pActwk->patbase = tobira6pat; /* Line 98, Address: 0x10171d8 */
  ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 99, Address: 0x10171e8 */

  pActwk->sproffset = 928; /* Line 101, Address: 0x10171f8 */
  pActwk->sprvsize = 32; /* Line 102, Address: 0x1017204 */
  pActwk->sprhsize = 8; /* Line 103, Address: 0x1017210 */
  if (stageno.b.l == 2) /* Line 104, Address: 0x101721c */
  {
    pActwk->sproffset = 816; /* Line 106, Address: 0x1017238 */
    pActwk->sprhsize = 32; /* Line 107, Address: 0x1017244 */
    pActwk->patno = 1; /* Line 108, Address: 0x1017250 */
  }


  pActwk->actfree[6] = pActwk->userflag.b.h & 15; /* Line 112, Address: 0x101725c */
  ((char*)pActwk)[64] = -1; /* Line 113, Address: 0x101727c */
  tobira6_move(pActwk); /* Line 114, Address: 0x1017288 */
} /* Line 115, Address: 0x1017294 */











void tobira6_move(sprite_status* pActwk) { /* Line 127, Address: 0x10172b0 */
  unsigned char byD0;

  byD0 = pActwk->actfree[6]; /* Line 130, Address: 0x10172c0 */
  if (switchflag[byD0] & 128) /* Line 131, Address: 0x10172cc */
    pActwk->actfree[18] = 0; /* Line 132, Address: 0x10172f0 */


  ((short*)pActwk)[30] = actwk[0].xposi.w.h; /* Line 135, Address: 0x10172f8 */
  ((short*)pActwk)[33] = actwk[0].yposi.w.h; /* Line 136, Address: 0x1017308 */

  tobira6_cnt(pActwk); /* Line 138, Address: 0x1017318 */
  tobira6_ridechk(pActwk); /* Line 139, Address: 0x1017324 */

  if (pActwk->actfree[16] == 64) /* Line 141, Address: 0x1017330 */
    pActwk->r_no0 += 2; /* Line 142, Address: 0x1017348 */

} /* Line 144, Address: 0x1017358 */











void tobira6_chek(sprite_status* pActwk) { /* Line 156, Address: 0x1017370 */
  short iD0;

  iD0 = pActwk->xposi.w.h - ((short*)pActwk)[30]; /* Line 159, Address: 0x101737c */
  if (iD0 < 0) /* Line 160, Address: 0x10173b0 */
  {

    iD0 = actwk[0].sprhs; /* Line 163, Address: 0x10173c0 */
    iD0 += actwk[0].xposi.w.h; /* Line 164, Address: 0x10173d4 */
    iD0 -= pActwk->xposi.w.h; /* Line 165, Address: 0x10173e8 */
    if (iD0 >= 0) return; /* Line 166, Address: 0x10173fc */

    iD0 = -iD0; /* Line 168, Address: 0x101740c */
    if (iD0 < (short)pActwk->sprhsize) return; /* Line 169, Address: 0x1017428 */

  } /* Line 171, Address: 0x1017450 */
  else
  {

    iD0 = actwk[0].sprhs; /* Line 175, Address: 0x1017458 */
    iD0 = -iD0; /* Line 176, Address: 0x101746c */
    iD0 += actwk[0].xposi.w.h; /* Line 177, Address: 0x1017488 */
    iD0 -= pActwk->xposi.w.h; /* Line 178, Address: 0x101749c */
    if (iD0 < 0) return; /* Line 179, Address: 0x10174b0 */

    if (iD0 < (short)pActwk->sprhsize) return; /* Line 181, Address: 0x10174c0 */
  }


  pActwk->r_no0 += 2; /* Line 185, Address: 0x10174e8 */
} /* Line 186, Address: 0x10174f8 */











void tobira6_clse(sprite_status* pActwk) { /* Line 198, Address: 0x1017510 */
  pActwk->actfree[18] = 255; /* Line 199, Address: 0x101751c */
  tobira6_cnt(pActwk); /* Line 200, Address: 0x1017528 */
  if (pActwk->actfree[16] == 0) /* Line 201, Address: 0x1017534 */
    pActwk->r_no0 = 2; /* Line 202, Address: 0x1017548 */
  tobira6_ridechk(pActwk); /* Line 203, Address: 0x1017554 */
} /* Line 204, Address: 0x1017560 */












void tobira6_cnt(sprite_status* pActwk) { /* Line 217, Address: 0x1017570 */
  ushort_union wD0;
  short iD0;

  wD0.w = 0; /* Line 221, Address: 0x1017580 */
  tobira6_sub(pActwk); /* Line 222, Address: 0x1017584 */
  wD0.b.l = pActwk->actfree[16]; /* Line 223, Address: 0x1017590 */
  iD0 = -wD0.w; /* Line 224, Address: 0x101759c */
  iD0 += ((short*)pActwk)[27]; /* Line 225, Address: 0x10175b8 */
  pActwk->yposi.w.h = iD0; /* Line 226, Address: 0x10175cc */
} /* Line 227, Address: 0x10175d4 */












void tobira6_sub(sprite_status* pActwk) { /* Line 240, Address: 0x10175f0 */
  if (pActwk->actfree[18] != 0) /* Line 241, Address: 0x10175f8 */
  {
    pActwk->actfree[16] -= 4; /* Line 243, Address: 0x101760c */
    if (((char*)pActwk)[62] >= 0) return; /* Line 244, Address: 0x101761c */

    ((char*)pActwk)[62] = 0; /* Line 246, Address: 0x1017634 */
    return; /* Line 247, Address: 0x101763c */
  }


  pActwk->actfree[16] += 4; /* Line 251, Address: 0x1017644 */
  if (pActwk->actfree[16] >= 64) /* Line 252, Address: 0x1017654 */
  {
    pActwk->actfree[16] = 64; /* Line 254, Address: 0x101766c */
  }
} /* Line 256, Address: 0x1017678 */
