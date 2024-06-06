#include "..\..\TYPES.H"
#include "LPL_TYPES.H"
#include "SPM_EQU.H"
#include "SPS_EQU.H"
#include "PLS.H"

void(*player_acttbl[3])() =
{
  &play0,
  &play1,
  &play2
};
static unsigned char keyBuf[256];
extern pad_status*(*sPeriPadGet)(unsigned int);




































void player() { /* Line 51, Address: 0x1008570 */
  player_acttbl[playwk.ACT_NO](); /* Line 52, Address: 0x1008578 */
} /* Line 53, Address: 0x10085a0 */











void play0() {
  playwk.x_posi.w.h = -40; /* Line 66, Address: 0x10085b0 */
  playwk.y_posi.w.h = 24; /* Line 67, Address: 0x10085bc */
  playwk.z_posi.w.h = 64; /* Line 68, Address: 0x10085c8 */
  playwk.k_kaku = 0; /* Line 69, Address: 0x10085d4 */

  zoomwk.xscale = 2048; /* Line 71, Address: 0x10085dc */
  zoomwk.yscale = 1024; /* Line 72, Address: 0x10085e8 */
  playwk.k_speed.w.h = 0; /* Line 73, Address: 0x10085f4 */

  rotflg = 1; /* Line 75, Address: 0x10085fc */
  zoomflg = 1; /* Line 76, Address: 0x1008608 */
  rotspeed.w.h = 2; /* Line 77, Address: 0x1008614 */
  ++playwk.ACT_NO; /* Line 78, Address: 0x1008620 */
} /* Line 79, Address: 0x1008634 */











void play1() { /* Line 91, Address: 0x1008640 */
  short iD0;
  short iD5;
  short iD6;
  pad_status* padStatus;












  padStatus = sPeriPadGet(1); /* Line 108, Address: 0x1008658 */
  if (padStatus->On & 2) /* Line 109, Address: 0x1008670 */
    keyBuf[67] = 1; /* Line 110, Address: 0x1008680 */
  else
    keyBuf[67] = 0; /* Line 112, Address: 0x1008694 */
  if (padStatus->On & 4) /* Line 113, Address: 0x100869c */
    keyBuf[88] = 1; /* Line 114, Address: 0x10086ac */
  else
    keyBuf[88] = 0; /* Line 116, Address: 0x10086c0 */


  if (swdata1.b.h & 16) /* Line 119, Address: 0x10086c8 */
  {
    comflag_s |= 64; /* Line 121, Address: 0x10086e0 */
    playwk.ACT_NO = 0; /* Line 122, Address: 0x10086f4 */
    return; /* Line 123, Address: 0x10086fc */
  }

  if (comflag_m & 16) /* Line 126, Address: 0x1008704 */
    playwk.ACT_NO = 2; /* Line 127, Address: 0x100871c */



  check_Bbtn(); /* Line 131, Address: 0x1008728 */

  check_Cbtn(); /* Line 133, Address: 0x1008730 */

  iD5 = playwk.z_posi.w.h; /* Line 135, Address: 0x1008738 */
  iD5 >>= 6; /* Line 136, Address: 0x1008748 */
  iD6 = -iD5; /* Line 137, Address: 0x1008754 */

  if (swdata1.b.h & 4) /* Line 139, Address: 0x1008770 */
  {
    playwk.x_posi.w.h += 8; /* Line 141, Address: 0x1008788 */
    iD5 += playwk.x_posi.w.h; /* Line 142, Address: 0x100879c */
  }

  if (swdata1.b.h & 8) /* Line 145, Address: 0x10087b0 */
  {
    playwk.x_posi.w.h -= 8; /* Line 147, Address: 0x10087c8 */
    iD6 += playwk.x_posi.w.h; /* Line 148, Address: 0x10087dc */
  }

  if (swdata1.b.h & 1) /* Line 151, Address: 0x10087f0 */
  {
    playwk.y_posi.w.h += 8; /* Line 153, Address: 0x1008808 */
    iD5 += playwk.y_posi.w.h; /* Line 154, Address: 0x100881c */
  }

  if (swdata1.b.h & 2) /* Line 157, Address: 0x1008830 */
  {
    playwk.y_posi.w.h -= 8; /* Line 159, Address: 0x1008848 */
    iD6 += playwk.y_posi.w.h; /* Line 160, Address: 0x100885c */
  }


  iD0 = playwk.z_posi.w.h + 336; /* Line 164, Address: 0x1008870 */
  if (iD0 <= playwk.x_posi.w.h) /* Line 165, Address: 0x1008894 */
    playwk.x_posi.w.h = iD0; /* Line 166, Address: 0x10088b8 */

  iD0 = -playwk.z_posi.w.h; /* Line 168, Address: 0x10088c0 */
  iD0 -= 336; /* Line 169, Address: 0x10088e4 */
  if (iD0 >= playwk.x_posi.w.h) /* Line 170, Address: 0x10088f0 */
    playwk.x_posi.w.h = iD0; /* Line 171, Address: 0x1008914 */

  iD0 = playwk.z_posi.w.h + 336; /* Line 173, Address: 0x100891c */
  if (iD0 <= playwk.y_posi.w.h) /* Line 174, Address: 0x1008940 */
    playwk.y_posi.w.h = iD0; /* Line 175, Address: 0x1008964 */

  iD0 = -playwk.z_posi.w.h - 336; /* Line 177, Address: 0x100896c */
  if (iD0 >= playwk.y_posi.w.h) /* Line 178, Address: 0x1008994 */
    playwk.y_posi.w.h = iD0; /* Line 179, Address: 0x10089b8 */

  playwk.k_kaku += rotspeed.w.h; /* Line 181, Address: 0x10089c0 */
  playwk.k_kaku &= 511; /* Line 182, Address: 0x10089dc */
} /* Line 183, Address: 0x10089f0 */




void check_Bbtn() {
  if (keyBuf[88] == 0) /* Line 189, Address: 0x1008a10 */
  {
    push_flg_s &= 239; /* Line 191, Address: 0x1008a24 */
    return; /* Line 192, Address: 0x1008a38 */
  }

  if (rotspeed.l != 0) /* Line 195, Address: 0x1008a40 */
  {
    if (push_flg_s & 16) goto label1; /* Line 197, Address: 0x1008a50 */

    rotspeed.l = 0; /* Line 199, Address: 0x1008a68 */
    rotflg = -rotflg; /* Line 200, Address: 0x1008a70 */
    push_flg_s |= 16; /* Line 201, Address: 0x1008a8c */
    return; /* Line 202, Address: 0x1008aa0 */
  }




  if (push_flg_s & 16) /* Line 208, Address: 0x1008aa8 */
  {
    push_flg_s |= 16; /* Line 210, Address: 0x1008ac0 */
    return; /* Line 211, Address: 0x1008ad4 */
  }

label1:
  if ((short)rotflg >= 0) /* Line 215, Address: 0x1008adc */
    rotspeed.l += 32767 + 1; /* Line 216, Address: 0x1008afc */
  else
    rotspeed.l -= 32768; /* Line 218, Address: 0x1008b1c */

  push_flg_s |= 16; /* Line 220, Address: 0x1008b30 */
} /* Line 221, Address: 0x1008b44 */




void check_Cbtn() {
  if (keyBuf[67] == 0) /* Line 227, Address: 0x1008b50 */
  {
    push_flg_s &= 223; /* Line 229, Address: 0x1008b64 */
    return; /* Line 230, Address: 0x1008b78 */
  }

  if (zoomflg <= 0) /* Line 233, Address: 0x1008b80 */
  {
    if (push_flg_s & 32) goto label1; /* Line 235, Address: 0x1008b98 */

  } /* Line 237, Address: 0x1008bb0 */
  else
  {

    if (!(push_flg_s & 32)) goto label1; /* Line 241, Address: 0x1008bb8 */
  }


  zoomflg = 1; /* Line 245, Address: 0x1008bd0 */
  if (playwk.z_posi.w.h <= 1792) /* Line 246, Address: 0x1008bdc */
    playwk.z_posi.w.h += 8; /* Line 247, Address: 0x1008bf8 */
  push_flg_s |= 32; /* Line 248, Address: 0x1008c0c */
  return; /* Line 249, Address: 0x1008c20 */

label1:
  zoomflg = -1; /* Line 252, Address: 0x1008c28 */
  if (playwk.z_posi.w.h >= -112) /* Line 253, Address: 0x1008c34 */
    playwk.z_posi.w.h -= 8; /* Line 254, Address: 0x1008c50 */

  push_flg_s |= 32; /* Line 256, Address: 0x1008c64 */
} /* Line 257, Address: 0x1008c78 */














void play2() {
  if (swdata1.b.h & 16) /* Line 273, Address: 0x1008c80 */
  {
    comflag_s |= 64; /* Line 275, Address: 0x1008c98 */
    playwk.ACT_NO = 0; /* Line 276, Address: 0x1008cac */
  }

  if (!(comflag_m & 16)) /* Line 279, Address: 0x1008cb4 */
    playwk.ACT_NO = 1; /* Line 280, Address: 0x1008ccc */
  playwk.k_kaku += rotspeed.w.h; /* Line 281, Address: 0x1008cd8 */
  playwk.k_kaku &= 511; /* Line 282, Address: 0x1008cf4 */
} /* Line 283, Address: 0x1008d08 */
