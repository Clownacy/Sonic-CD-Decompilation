#include "..\EQU.H"
#include "WALL4.H"
#include "..\ACTION.H"
#include "..\RIDECHK.H"

#if defined(R42A)
  #define SPRITE_WALL4_BASE 470
#else
  #define SPRITE_WALL4_BASE 492
#endif

sprite_pattern wall4_pat0 = {
  1,
  { { -64, -64, 0, SPRITE_WALL4_BASE } }
};
sprite_pattern* pat_wall4[1] = { &wall4_pat0 };































































void wall4(sprite_status* pActwk) { /* Line 80, Address: 0x10204e0 */
  void(*wall4_acttbl[4])(sprite_status*) = { /* Line 81, Address: 0x10204ec */
    &wall4_init,
    &wall4_sense,
    &wall4_wait,
    &wall4_down
  };

  wall4_acttbl[pActwk->r_no0 / 2](pActwk); /* Line 88, Address: 0x1020518 */
  hitchk(pActwk, &actwk[0]); /* Line 89, Address: 0x1020554 */
  actionsub(pActwk); /* Line 90, Address: 0x1020568 */
  frameout_s_(pActwk); /* Line 91, Address: 0x1020574 */
} /* Line 92, Address: 0x1020580 */








void wall4_init(sprite_status* pActwk) { /* Line 101, Address: 0x1020590 */
  pActwk->actflg |= 4; /* Line 102, Address: 0x1020598 */
  pActwk->sprpri = 3; /* Line 103, Address: 0x10205a8 */

  pActwk->sprhs = 64; /* Line 105, Address: 0x10205b4 */
  pActwk->sprhsize = 64; /* Line 106, Address: 0x10205c0 */
  pActwk->sprvsize = 64; /* Line 107, Address: 0x10205cc */
  pActwk->sproffset = 17514; /* Line 108, Address: 0x10205d8 */
  pActwk->patbase = pat_wall4; /* Line 109, Address: 0x10205e4 */

  ((unsigned short*)pActwk)[24] = time_flag + pActwk->cdsts * 3; /* Line 111, Address: 0x10205f4 */

  if (!(flagwork[((unsigned short*)pActwk)[24]] & 1)) { /* Line 113, Address: 0x1020624 */

    if (pActwk->userflag.b.h) ((short*)pActwk)[23] = 32; /* Line 115, Address: 0x1020650 */
    else ((short*)pActwk)[23] = 16; /* Line 116, Address: 0x1020674 */



    pActwk->r_no0 = (pActwk->userflag.b.h + 1) * 2; /* Line 120, Address: 0x1020680 */
  } /* Line 121, Address: 0x10206a4 */
  else {

    if (pActwk->userflag.b.h) pActwk->yposi.w.h += 128; /* Line 124, Address: 0x10206ac */
    else pActwk->yposi.w.h += 64; /* Line 125, Address: 0x10206d4 */
    pActwk->r_no0 += 4; /* Line 126, Address: 0x10206e4 */
  }
} /* Line 128, Address: 0x10206f4 */








void wall4_sense(sprite_status* pActwk) { /* Line 137, Address: 0x1020700 */
  if ((unsigned short)(actwk[0].yposi.w.h - pActwk->yposi.w.h) < 128) { /* Line 138, Address: 0x1020708 */
    if ((unsigned short)(actwk[0].xposi.w.h - pActwk->xposi.w.h - 160) < 32) { /* Line 139, Address: 0x1020740 */
      pActwk->actfree[21] = 255; /* Line 140, Address: 0x102077c */
      pActwk->r_no0 += 2; /* Line 141, Address: 0x1020788 */
    }
  }
} /* Line 144, Address: 0x1020798 */








void wall4_wait(sprite_status* pActwk) { /* Line 153, Address: 0x10207b0 */
  if (pActwk->actfree[21]) { /* Line 154, Address: 0x10207b8 */

    flagwork[((unsigned short*)pActwk)[24]] |= 1; /* Line 156, Address: 0x10207c8 */
    pActwk->r_no0 += 2; /* Line 157, Address: 0x10207ec */
  }
} /* Line 159, Address: 0x10207fc */








void wall4_down(sprite_status* pActwk) { /* Line 168, Address: 0x1020810 */
  pActwk->yposi.l += 0x40000; /* Line 169, Address: 0x1020818 */
  if (!(--((short*)pActwk)[23])) { /* Line 170, Address: 0x102082c */
    pActwk->actfree[21] = 0; /* Line 171, Address: 0x102084c */
    pActwk->r_no0 -= 2; /* Line 172, Address: 0x1020854 */
  }
} /* Line 174, Address: 0x1020864 */








void frameout_s_(sprite_status* pActwk) { /* Line 183, Address: 0x1020870 */
  if (pActwk->userflag.b.h != 1) { /* Line 184, Address: 0x102087c */
    if ((pActwk->xposi.w.h & 65408) - (scra_h_posit.w.h - 128 & 65408) > 640) { /* Line 185, Address: 0x1020898 */
      flagwork[((unsigned short*)pActwk)[24]] &= 127; /* Line 186, Address: 0x10208d4 */
      frameout(pActwk); /* Line 187, Address: 0x10208f8 */
    }
  }
} /* Line 190, Address: 0x1020904 */
