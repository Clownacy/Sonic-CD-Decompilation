#include "..\EQU.H"
#include "HAGURUMA.H"
#include "..\ACTSET.H"

static void hagurumainit(sprite_status* wheelwk);
static void hagurumamove(sprite_status* wheelwk);
static void hagurumasub(sprite_status* wheelwk);









void haguruma(sprite_status* wheelwk) { /* Line 17, Address: 0x101c660 */
  void(*haguruma_move_tbl[2])(sprite_status*) = { &hagurumainit, &hagurumamove }; /* Line 18, Address: 0x101c66c */
  haguruma_move_tbl[wheelwk->r_no0 / 2](wheelwk); /* Line 19, Address: 0x101c688 */
} /* Line 20, Address: 0x101c6c4 */


void hagurumainit(sprite_status* wheelwk) { /* Line 23, Address: 0x101c6e0 */
  wheelwk->r_no0 += 2; /* Line 24, Address: 0x101c6ec */
  wheelwk->actflg |= 4; /* Line 25, Address: 0x101c6fc */
  ((short*)wheelwk)[27] = wheelwk->xposi.w.h; /* Line 26, Address: 0x101c70c */
  ((short*)wheelwk)[26] = wheelwk->yposi.w.h; /* Line 27, Address: 0x101c71c */
  wheelwk->actfree[10] = 24; /* Line 28, Address: 0x101c72c */
  wheelwk->actfree[14] = 72; /* Line 29, Address: 0x101c738 */
  if (wheelwk->userflag.b.h & 15) { /* Line 30, Address: 0x101c744 */
    wheelwk->actfree[10] = 16; /* Line 31, Address: 0x101c760 */
    wheelwk->actfree[14] = 48; /* Line 32, Address: 0x101c76c */
  }
  ((short*)wheelwk)[29] = (short)(wheelwk->userflag.b.h & -16) * 8; /* Line 34, Address: 0x101c778 */

  wheelwk->direc.b.h = wheelwk->cddat << 6 & 192; /* Line 36, Address: 0x101c7b4 */
  hagurumamove(wheelwk); /* Line 37, Address: 0x101c7d8 */
} /* Line 38, Address: 0x101c7e4 */


void hagurumamove(sprite_status* wheelwk) { /* Line 41, Address: 0x101c800 */
  hagurumasub(wheelwk); /* Line 42, Address: 0x101c80c */
  frameout_s(wheelwk); /* Line 43, Address: 0x101c818 */
} /* Line 44, Address: 0x101c824 */


void hagurumasub(sprite_status* wheelwk) { /* Line 47, Address: 0x101c840 */
  unsigned short cal_posi;

  cal_posi = actwk[0].xposi.w.h - ((short*)wheelwk)[27] + (short)wheelwk->actfree[14]; /* Line 50, Address: 0x101c84c */

  if (cal_posi < (unsigned short)(wheelwk->actfree[14] * 2)) { /* Line 52, Address: 0x101c890 */
    cal_posi = actwk[0].yposi.w.h - ((short*)wheelwk)[26] + (short)wheelwk->actfree[14]; /* Line 53, Address: 0x101c8b8 */

    if (cal_posi < (unsigned short)(wheelwk->actfree[14] * 2)) { /* Line 55, Address: 0x101c8fc */
      if (!(actwk[0].cddat & 2)) goto label1; /* Line 56, Address: 0x101c924 */

      wheelwk->actfree[16] = 0; /* Line 58, Address: 0x101c93c */
      return; /* Line 59, Address: 0x101c944 */
    }
  }
  if (wheelwk->actfree[16]) /* Line 62, Address: 0x101c94c */
    actwk[0].actfree[14] = wheelwk->actfree[16] = 0; /* Line 63, Address: 0x101c95c */
  return; /* Line 64, Address: 0x101c970 */

label1:
  if (!wheelwk->actfree[16]) { /* Line 67, Address: 0x101c978 */
    wheelwk->actfree[16] = 1; /* Line 68, Address: 0x101c988 */
    if (!(actwk[0].cddat & 4)) actwk[0].mstno.b.h = 0; /* Line 69, Address: 0x101c994 */
    actwk[0].cddat &= 223; /* Line 70, Address: 0x101c9b4 */
    actwk[0].mstno.b.l = 1; /* Line 71, Address: 0x101c9c8 */
    actwk[0].actfree[14] = 1; /* Line 72, Address: 0x101c9d4 */
  }
  if (((short*)wheelwk)[29] < 0) { /* Line 74, Address: 0x101c9e0 */
    if (actwk[0].mspeed.w > -1024) actwk[0].mspeed.w = -1024; /* Line 75, Address: 0x101c9f8 */
    else if (actwk[0].mspeed.w < -3840) actwk[0].mspeed.w = -3840; /* Line 76, Address: 0x101ca28 */
    return; /* Line 77, Address: 0x101ca50 */
  }
  if (actwk[0].mspeed.w < 1024) actwk[0].mspeed.w = 1024; /* Line 79, Address: 0x101ca58 */
  else if (actwk[0].mspeed.w > 3840) actwk[0].mspeed.w = 3840; /* Line 80, Address: 0x101ca88 */
} /* Line 81, Address: 0x101cab0 */
