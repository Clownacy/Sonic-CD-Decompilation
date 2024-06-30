#include "..\EQU.H"
#include "WALL73.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

static short move_blk(sprite_status* pActwk);

static unsigned char wall7_tbl0[12] = {
  11, 16,
  32, 16,
  48, 16,
  64, 16,
  11, 32,
  11, 48
};
extern sprite_pattern* pat_wall7[];
















































void wall73(sprite_status* pActwk) { /* Line 66, Address: 0x1022400 */
  if (!pActwk->r_no0) { /* Line 67, Address: 0x102240c */

    pActwk->r_no0 += 2; /* Line 69, Address: 0x102241c */
    pActwk->actflg |= 4; /* Line 70, Address: 0x102242c */
    pActwk->sprpri = 3; /* Line 71, Address: 0x102243c */
    pActwk->sproffset = 17676; /* Line 72, Address: 0x1022448 */
    pActwk->patbase = pat_wall7; /* Line 73, Address: 0x1022454 */
    pActwk->patno = pActwk->userflag.b.h; /* Line 74, Address: 0x1022464 */

    pActwk->sprhs = wall7_tbl0[pActwk->userflag.b.h * 2]; /* Line 76, Address: 0x1022474 */
    pActwk->sprhsize = wall7_tbl0[pActwk->userflag.b.h * 2]; /* Line 77, Address: 0x10224a0 */
    pActwk->sprvsize = wall7_tbl0[pActwk->userflag.b.h * 2 + 1]; /* Line 78, Address: 0x10224cc */
  }

  if (pActwk->userflag.b.l) { /* Line 81, Address: 0x10224fc */
    if (move_blk(pActwk)) return; /* Line 82, Address: 0x102250c */
  }
  if (hitchk(pActwk, &actwk[0])) /* Line 84, Address: 0x1022520 */
    actwk[0].colino = 0; /* Line 85, Address: 0x102253c */
  actionsub(pActwk); /* Line 86, Address: 0x1022544 */
  frameout_s(pActwk); /* Line 87, Address: 0x1022550 */
} /* Line 88, Address: 0x102255c */








static short move_blk(sprite_status* pActwk) { /* Line 97, Address: 0x1022570 */
  short wD0, wD1;
  char bD0;

  if (!(bossflag & 128)) /* Line 101, Address: 0x1022588 */
    return 0; /* Line 102, Address: 0x10225a0 */
  if (!((short*)pActwk)[23]) { /* Line 103, Address: 0x10225ac */

    wD0 = 32; /* Line 105, Address: 0x10225bc */
    wD1 = 512; /* Line 106, Address: 0x10225c8 */
    if (pActwk->userflag.b.l & 128) { /* Line 107, Address: 0x10225d4 */
      wD0 *= -1; /* Line 108, Address: 0x10225f0 */
      wD1 *= -1; /* Line 109, Address: 0x10225fc */
    }

    pActwk->yspeed.w = wD1; /* Line 112, Address: 0x1022608 */
    ((short*)pActwk)[23] = pActwk->yposi.w.h + wD0; /* Line 113, Address: 0x1022610 */
  }

  pActwk->yposi.l += pActwk->yspeed.w << 8; /* Line 116, Address: 0x102263c */

  if (((short*)pActwk)[23] != pActwk->yposi.w.h) { /* Line 118, Address: 0x1022660 */
    return 0; /* Line 119, Address: 0x1022688 */
  }
  ((short*)pActwk)[23] = 0; /* Line 121, Address: 0x1022694 */


  bD0 = (pActwk->userflag.b.l & 15) - 1; /* Line 124, Address: 0x102269c */
  if (!bD0) { /* Line 125, Address: 0x10226c4 */

    bossflag &= 127; /* Line 127, Address: 0x10226cc */
    if (pActwk->userflag.b.l & 64) { /* Line 128, Address: 0x10226e0 */

      pActwk->userflag.b.l = 0; /* Line 130, Address: 0x10226fc */
      return 0; /* Line 131, Address: 0x1022704 */
    }


    frameout(pActwk); /* Line 135, Address: 0x1022710 */
    return -1; /* Line 136, Address: 0x102271c */
  }



  pActwk->userflag.b.l &= -16; /* Line 141, Address: 0x1022728 */
  pActwk->userflag.b.l += bD0; /* Line 142, Address: 0x102273c */
  if (pActwk->userflag.b.l & 32) /* Line 143, Address: 0x102274c */
    return 0; /* Line 144, Address: 0x1022768 */
  if (pActwk->userflag.b.l & 16) { /* Line 145, Address: 0x1022774 */

    if (++pActwk->patno == 1) { /* Line 147, Address: 0x1022790 */
      pActwk->patno = 4; /* Line 148, Address: 0x10227b4 */
    }
    pActwk->yposi.w.h -= 16; /* Line 150, Address: 0x10227c0 */
  } /* Line 151, Address: 0x10227d0 */
  else {

    if (--pActwk->patno == 3) { /* Line 154, Address: 0x10227d8 */
      pActwk->patno = 0; /* Line 155, Address: 0x10227fc */
    }
    pActwk->yposi.w.h += 16; /* Line 157, Address: 0x1022804 */
  }

  pActwk->sprhs = wall7_tbl0[pActwk->patno * 2]; /* Line 160, Address: 0x1022814 */
  pActwk->sprhsize = wall7_tbl0[pActwk->patno * 2]; /* Line 161, Address: 0x102283c */
  pActwk->sprvsize = wall7_tbl0[pActwk->patno * 2 + 1]; /* Line 162, Address: 0x1022864 */

  return 0; /* Line 164, Address: 0x1022890 */

} /* Line 166, Address: 0x1022894 */
