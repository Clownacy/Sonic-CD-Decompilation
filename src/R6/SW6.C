#include "..\EQU.H"
#include "SW6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\FCOL.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"

sprite_pattern pat0_sw6 =
{
  1,
  { { -16, -8, 0, 307 } }
};
sprite_pattern pat1_sw6 =
{
  1,
  { { -16, -4, 0, 308 } }
};
sprite_pattern* pat_sw6[2] =
{
  &pat0_sw6,
  &pat1_sw6
};














































void sw6(sprite_status* pActwk) { /* Line 70, Address: 0x1016de0 */
  if (pActwk->r_no0 == 0) /* Line 71, Address: 0x1016dec */
    act_init(pActwk); /* Line 72, Address: 0x1016e00 */
  else
    act_move(pActwk); /* Line 74, Address: 0x1016e14 */
} /* Line 75, Address: 0x1016e20 */











void act_init(sprite_status* pActwk) { /* Line 87, Address: 0x1016e30 */
  pActwk->r_no0 += 2; /* Line 88, Address: 0x1016e3c */
  pActwk->actflg |= 4; /* Line 89, Address: 0x1016e4c */
  pActwk->sprpri = 1; /* Line 90, Address: 0x1016e5c */
  pActwk->sprhs = 16; /* Line 91, Address: 0x1016e68 */
  pActwk->sprhsize = 16; /* Line 92, Address: 0x1016e74 */
  pActwk->sproffset = 922; /* Line 93, Address: 0x1016e80 */
  pActwk->patbase = pat_sw6; /* Line 94, Address: 0x1016e8c */

  pActwk->sprvsize = 8; /* Line 96, Address: 0x1016e9c */
  pActwk->actfree[18] = pActwk->userflag.b.h; /* Line 97, Address: 0x1016ea8 */

  ((short*)pActwk)[33] = 0; /* Line 99, Address: 0x1016eb8 */
  act_move(pActwk); /* Line 100, Address: 0x1016ec0 */
} /* Line 101, Address: 0x1016ecc */











void act_move(sprite_status* pActwk) { /* Line 113, Address: 0x1016ee0 */
  unsigned char addr_off;

  addr_off = pActwk->actfree[18]; /* Line 116, Address: 0x1016ef0 */
  pActwk->actfree[21] = pActwk->actfree[20]; /* Line 117, Address: 0x1016efc */


  if (hitchk(pActwk, &actwk[0]) != 0) /* Line 120, Address: 0x1016f0c */
  {

    pActwk->actfree[20] = 255; /* Line 123, Address: 0x1016f30 */
    switchflag[addr_off] |= 128; /* Line 124, Address: 0x1016f3c */
    switchflag[addr_off] |= 64; /* Line 125, Address: 0x1016f58 */
  } /* Line 126, Address: 0x1016f74 */
  else
  {

    pActwk->actfree[20] = 0; /* Line 130, Address: 0x1016f7c */
    switchflag[addr_off] &= 127; /* Line 131, Address: 0x1016f84 */
  }


  if (((unsigned short*)pActwk)[33] == 255) /* Line 135, Address: 0x1016fa0 */
  {
    if ((char)pActwk->actflg < 0) /* Line 137, Address: 0x1016fb8 */
      soundset(191); /* Line 138, Address: 0x1016fd8 */

    switchflag[addr_off] = bchg(5, switchflag[addr_off]); /* Line 140, Address: 0x1016fe4 */
    actwk[0].yposi.w.h += 8; /* Line 141, Address: 0x1017018 */
    pActwk->yposi.w.h += 4; /* Line 142, Address: 0x101702c */
    ++pActwk->patno; /* Line 143, Address: 0x101703c */
    pActwk->sprvsize -= 4; /* Line 144, Address: 0x101704c */
  }

  if (((unsigned short*)pActwk)[33] == 65280) /* Line 147, Address: 0x101705c */
  {
    actwk[0].yposi.w.h -= 8; /* Line 149, Address: 0x1017074 */
    pActwk->yposi.w.h -= 4; /* Line 150, Address: 0x1017088 */
    --pActwk->patno; /* Line 151, Address: 0x1017098 */
    pActwk->sprvsize += 4; /* Line 152, Address: 0x10170a8 */
  }
  actionsub(pActwk); /* Line 154, Address: 0x10170b8 */
  frameout_s(pActwk); /* Line 155, Address: 0x10170c4 */
} /* Line 156, Address: 0x10170d0 */
