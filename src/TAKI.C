#include "EQU.H"
#include "TAKI.H"
#include "ACTION.H"
#include "PLAYSUB.H"

extern void block_wrt(unsigned short BlockNo, unsigned short xOffs, unsigned short yOffs);

static char shibukichg0[4] = { 4, 0, 1, -1 };
unsigned char* shibukichg = { (unsigned char*)shibukichg0 };
static sprite_pattern shibuki0 = {
  1,
  { { -96, -16, 0, 448 } }
};
static sprite_pattern shibuki1 = {
  1,
  { { -96, -16, 0, 449 } }
};
sprite_pattern* shibukipat[2] = {
  &shibuki0,
  &shibuki1
};
static void(*taki_move_tbl[2])(sprite_status*) = {
  &taki_init,
  &taki_move
};











































































void taki(sprite_status* pActwk) { /* Line 101, Address: 0x101d6e0 */
  taki_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 102, Address: 0x101d6ec */
  patchg(pActwk, &shibukichg); /* Line 103, Address: 0x101d730 */
  actionsub(pActwk); /* Line 104, Address: 0x101d744 */
} /* Line 105, Address: 0x101d750 */





static void taki_init(sprite_status* pActwk) { /* Line 111, Address: 0x101d760 */
  pActwk->r_no0 += 2; /* Line 112, Address: 0x101d768 */
  pActwk->patbase = shibukipat; /* Line 113, Address: 0x101d778 */
  pActwk->actflg = 4; /* Line 114, Address: 0x101d788 */
  pActwk->sprpri = 1; /* Line 115, Address: 0x101d794 */
  pActwk->sprhsize = 16; /* Line 116, Address: 0x101d7a0 */
  pActwk->sproffset = 954; /* Line 117, Address: 0x101d7ac */
  pActwk->yposi.w.h &= -16; /* Line 118, Address: 0x101d7b8 */

  ((short*)pActwk)[23] = pActwk->yposi.w.h + 384; /* Line 120, Address: 0x101d7cc */

} /* Line 122, Address: 0x101d7f0 */





static void taki_move(sprite_status* pActwk) { /* Line 128, Address: 0x101d800 */
  unsigned short blkno;
  short i, xoffs;

  if (pActwk->yposi.w.h + 4 >= ((short*)pActwk)[23]) { /* Line 132, Address: 0x101d818 */

    frameout(pActwk); /* Line 134, Address: 0x101d848 */
    return; /* Line 135, Address: 0x101d854 */
  }

  pActwk->yposi.w.h += 4; /* Line 138, Address: 0x101d85c */
  blkno = 8194; /* Line 139, Address: 0x101d86c */
  xoffs = pActwk->xposi.w.h - 96; /* Line 140, Address: 0x101d874 */

  if (pActwk->yposi.w.h & 15) return; /* Line 142, Address: 0x101d898 */



  for (i = 0; i < 12; ++i, xoffs += 16) { /* Line 146, Address: 0x101d8b4 */
    block_wrt(blkno, xoffs, pActwk->yposi.w.h); /* Line 147, Address: 0x101d8c0 */
  } /* Line 148, Address: 0x101d8dc */
} /* Line 149, Address: 0x101d908 */













void jisin_set(sprite_status* pActwk) { /* Line 163, Address: 0x101d930 */
  pActwk = pActwk; /* Line 164, Address: 0x101d938 */

} /* Line 166, Address: 0x101d940 */













void jisin(sprite_status* pActwk) { /* Line 180, Address: 0x101d950 */
  pActwk = pActwk; /* Line 181, Address: 0x101d958 */

} /* Line 183, Address: 0x101d960 */
