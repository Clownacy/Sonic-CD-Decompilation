// Addresses correspond to R11*.ELF (except R11A.ELF), R12*.ELF
#include "EQU.C"
#include "TAKI.H"

char shibukichg0[4] = { 4, 0, 1, -1 };
unsigned char* shibukichg = { shibukichg0 };
spr_array shibuki0 = {
  .cnt = 1,
  .spra = {
    { 160, -16, 0, 448 }
  }
};
spr_array shibuki1 = {
  .cnt = 1,
  .spra = {
    { 160, -16, 0, 449 }
  }
};
spr_array* shibukipat[2] = {
  &shibuki0,
  &shibuki1
};
void(*taki_move_tbl)(act_info*)[2] = {
  &taki_init
  &taki_move
};










































































void taki(act_info* pActwk) { /* Line 101, Address: 0x101d6e0 */
  taki_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 102, Address: 0x101d6ec */
  patchg(pActwk, shibukichg); /* Line 103, Address: 0x101d730 */
  actionsub(pActwk); /* Line 104, Address: 0x101d744 */
} /* Line 105, Address: 0x101d750 */





void taki_init(act_info* pActwk) { /* Line 111, Address: 0x101d760 */
  pActwk->r_no0 += 2; /* Line 112, Address: 0x101d768 */
  pActwk->patbase = shibukipat; /* Line 113, Address: 0x101d778 */
  pActwk->actflg = 4; /* Line 114, Address: 0x101d788 */
  pActwk->sprpri = 1; /* Line 115, Address: 0x101d794 */
  pActwk->sprhsize = 16; /* Line 116, Address: 0x101d7a0 */
  pActwk->sproffset = 954; /* Line 117, Address: 0x101d7ac */
  pActwk->yposi.w.h &= -16; /* Line 118, Address: 0x101d7b8 */

  *(short*)&pActwk->actfree[0] = pActwk->yposi.w.h + 384; /* Line 120, Address: 0x101d7cc */

} /* Line 122, Address: 0x101d7f0 */





void taki_move(act_info* pActwk) { /* Line 128, Address: 0x101d800 */
  unsigned short blkno;
  short i, xoffs;

  if (pActwk->yposi.w.h + 4 >= *(short*)&pActwk->actfree[0]) { /* Line 132, Address: 0x101d818 */

    frameout(pActwk); /* Line 134, Address: 0x101d848 */
    return; /* Line 135, Address: 0x101d854 */
  }

  pActwk->yposi.w.h += 4; /* Line 138, Address: 0x101d85c */
  blkno = 8194; /* Line 139, Address: 0x101d86c */
  xoffs = pActwk->xposi.w.h + -96; /* Line 140, Address: 0x101d874 */

  if (pActwk->yposi.w.h % 16) return; /* Line 142, Address: 0x101d898 */



  for (i = 0; i < 12; ++i, xoffs += 16) { /* Line 146, Address: 0x101d8b4 */
    block_wrt(blkno, xoffs, pActwk->yposi.w.h); /* Line 147, Address: 0x101d8c0 */
  } /* Line 148, Address: 0x101d8dc */
} /* Line 149, Address: 0x101d908 */













void jisin_set(act_info* pActwk) { /* Line 163, Address: 0x101d930 */
  return; /* Line 164, Address: 0x101d938 */

} /* Line 166, Address: 0x101d940 */













void jisin(act_info* pActwk) { /* Line 180, Address: 0x101d950 */
  return; /* Line 181, Address: 0x101d958 */

} /* Line 183, Address: 0x101d960 */
