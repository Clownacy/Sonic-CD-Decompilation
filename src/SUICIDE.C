#include "EQU.H"
#include "SUICIDE.H"
#include "ACTION.H"
#include "ACTSET.H"

extern void soundset(short ReqNo);




























short enemy_suicide(act_info* pActwk) { /* Line 35, Address: 0x1013ea0 */
  short xposi, yposi;

  if (generate_flag == 0) /* Line 38, Address: 0x1013eb4 */
    return 0; /* Line 39, Address: 0x1013ec8 */
  if (time_flag == 1) /* Line 40, Address: 0x1013ed4 */
  {
    if (pActwk->userflag.b.h == 0) /* Line 42, Address: 0x1013eec */
      return 0; /* Line 43, Address: 0x1013f04 */
  }
  xposi = pActwk->xposi.w.h; /* Line 45, Address: 0x1013f10 */
  yposi = pActwk->yposi.w.h; /* Line 46, Address: 0x1013f20 */
  frameout(pActwk); /* Line 47, Address: 0x1013f30 */
  pActwk->xposi.w.h = xposi; /* Line 48, Address: 0x1013f3c */
  pActwk->yposi.w.h = yposi; /* Line 49, Address: 0x1013f44 */
  pActwk->actno = 24; /* Line 50, Address: 0x1013f4c */
  if (pActwk->actflg < 0) soundset(158); /* Line 51, Address: 0x1013f58 */
  return -1; /* Line 52, Address: 0x1013f78 */
} /* Line 53, Address: 0x1013f7c */












short friend_suicide(act_info* pActwk) { /* Line 66, Address: 0x1013fa0 */
  if (pActwk->userflag.b.h < 0) /* Line 67, Address: 0x1013fac */
    return 0; /* Line 68, Address: 0x1013fc4 */
  if (time_flag < 2) /* Line 69, Address: 0x1013fd0 */
  {
    if (projector_flag) /* Line 71, Address: 0x1013fe8 */
      return 0; /* Line 72, Address: 0x1013ff8 */
    frameout_s(pActwk); /* Line 73, Address: 0x1014004 */
    return -1; /* Line 74, Address: 0x1014010 */
  }
  if (generate_flag) /* Line 76, Address: 0x101401c */
    return 0; /* Line 77, Address: 0x101402c */
  frameout(pActwk); /* Line 78, Address: 0x1014038 */
  return -1; /* Line 79, Address: 0x1014044 */
} /* Line 80, Address: 0x1014048 */
