#include "..\..\TYPES.H"
#include "LPL_TYPES.H"
#include "SPM_EQU.H"
#include "SPS_EQU.H"
#include "KAITEN.H"
#include "ETC.H"









































void kaiten0() { /* Line 48, Address: 0x1004620 */
  zoomwk.az = playwk.k_kaku; /* Line 49, Address: 0x1004628 */
  zoomwk.x = playwk.x_posi.w.h; /* Line 50, Address: 0x1004638 */
  zoomwk.y = playwk.y_posi.w.h; /* Line 51, Address: 0x1004648 */
  zoomwk.z = playwk.z_posi.w.h; /* Line 52, Address: 0x1004658 */
  k_3d(); /* Line 53, Address: 0x1004668 */


} /* Line 56, Address: 0x1004670 */














void kaiten_init() {} /* Line 71, Address: 0x1004680 */




































void k_3d() { /* Line 108, Address: 0x1004690 */
  int_union lD0, lD1;
  short i;
  short* ptv_adr;

  k_wk.k_msx = 128; /* Line 113, Address: 0x10046a0 */
  k_wk.k_msy = 112; /* Line 114, Address: 0x10046ac */
  k_wk.k_rx = 128; /* Line 115, Address: 0x10046b8 */
  k_wk.k_ry = 112; /* Line 116, Address: 0x10046c4 */


  lD0.l = 0; /* Line 119, Address: 0x10046d0 */
  lD0.w.l = zoomwk.z + 128; /* Line 120, Address: 0x10046d4 */
  lD0.l = lD0.w.l; /* Line 121, Address: 0x10046f4 */
  if (lD0.l & 0x80000000) lD0.l <<= 8, lD0.l |= 0x80000000; else lD0.l <<= 8; /* Line 122, Address: 0x1004704 */
  lD0.w.l = lD0.l / 128; /* Line 123, Address: 0x1004748 */
  k_wk.k_s = lD0.w.l; /* Line 124, Address: 0x1004770 */

  lD0.l = 0; /* Line 126, Address: 0x100477c */
  lD0.w.l = zoomwk.z + 128; /* Line 127, Address: 0x1004780 */
  lD0.l = lD0.w.l; /* Line 128, Address: 0x10047a0 */
  lD1.l = 32768; /* Line 129, Address: 0x10047b0 */
  lD1.w.l = lD1.l / lD0.l; /* Line 130, Address: 0x10047b8 */
  k_wk.k_s2 = lD0.w.l; /* Line 131, Address: 0x10047e0 */


  k_wk.k_cos = cos_planet(zoomwk.az); /* Line 134, Address: 0x10047ec */

  k_wk.k_sin = sin_planet(zoomwk.az); /* Line 136, Address: 0x1004804 */


  lD0.l = k_wk.k_cos * k_wk.k_s; /* Line 139, Address: 0x100481c */

  lD0.l >>= 5; /* Line 141, Address: 0x1004844 */
  k_wk.k_dx = lD0.w.l; /* Line 142, Address: 0x1004850 */


  lD0.l = k_wk.k_sin * k_wk.k_s; /* Line 145, Address: 0x100485c */

  lD0.l >>= 5; /* Line 147, Address: 0x1004884 */
  k_wk.k_dy = lD0.w.l; /* Line 148, Address: 0x1004890 */


  lD0.w.l = zoomwk.x - k_wk.k_rx; /* Line 151, Address: 0x100489c */
  k_wk.k_x_rx = lD0.w.l; /* Line 152, Address: 0x10048cc */

  lD0.w.l = zoomwk.y - k_wk.k_ry; /* Line 154, Address: 0x10048d8 */
  k_wk.k_y_ry = lD0.w.l; /* Line 155, Address: 0x1004908 */

  k_wk.k_y_ry += 88; /* Line 157, Address: 0x1004914 */
  lD0.l = calc_xt_r(); /* Line 158, Address: 0x1004928 */
  lD0.l >>= 3; /* Line 159, Address: 0x1004934 */
  k_wk.k_xt_c = lD0.w.l; /* Line 160, Address: 0x1004940 */
  lD0.l = calc_yt_r(); /* Line 161, Address: 0x1004954 */
  lD0.l >>= 3; /* Line 162, Address: 0x1004960 */
  k_wk.k_yt_c = lD0.w.l; /* Line 163, Address: 0x100496c */





  lD0.l = k_wk.k_cos << 7; /* Line 169, Address: 0x1004980 */
  lD0.l >>= 8; /* Line 170, Address: 0x1004998 */

  lD0.w.l += k_wk.k_xt_c; /* Line 172, Address: 0x10049a4 */
  k_wk.k_msx = lD0.w.l; /* Line 173, Address: 0x10049c0 */


  lD0.l = k_wk.k_sin << 7; /* Line 176, Address: 0x10049cc */
  lD0.l >>= 8; /* Line 177, Address: 0x10049e4 */

  lD0.w.l += k_wk.k_yt_c; /* Line 179, Address: 0x10049f0 */
  k_wk.k_msy = lD0.w.l; /* Line 180, Address: 0x1004a0c */


  k_wk.k_x_rx = zoomwk.x - k_wk.k_rx; /* Line 183, Address: 0x1004a18 */
  k_wk.k_y_ry = zoomwk.y - k_wk.k_ry; /* Line 184, Address: 0x1004a4c */

  ptv_adr = tv_adr; /* Line 186, Address: 0x1004a80 */

  for (i = 0; i < 176; ++i) { /* Line 188, Address: 0x1004a88 */

    lD0.l = calc_xt_r(); /* Line 190, Address: 0x1004a94 */
    lD0.l = calc_xt_s(lD0.l); /* Line 191, Address: 0x1004aa0 */
    *ptv_adr++ = lD0.w.l; /* Line 192, Address: 0x1004ab0 */

    lD0.l = calc_yt_r(); /* Line 194, Address: 0x1004ac0 */
    lD0.l = calc_yt_s(lD0.l); /* Line 195, Address: 0x1004acc */
    *ptv_adr++ = lD0.w.l; /* Line 196, Address: 0x1004adc */

    *ptv_adr++ = k_wk.k_dx; /* Line 198, Address: 0x1004aec */
    *ptv_adr++ = k_wk.k_dy; /* Line 199, Address: 0x1004b00 */
    ++k_wk.k_y_ry; /* Line 200, Address: 0x1004b14 */
  } /* Line 201, Address: 0x1004b28 */
} /* Line 202, Address: 0x1004b48 */











int calc_xt_r() { /* Line 214, Address: 0x1004b60 */
  int_union lD0, lD1, lD2;


  lD1.l = k_wk.k_cos * k_wk.k_x_rx; /* Line 218, Address: 0x1004b64 */

  lD2.l = k_wk.k_sin * k_wk.k_y_ry; /* Line 220, Address: 0x1004b8c */

  lD1.l -= lD2.l; /* Line 222, Address: 0x1004bb4 */


  lD0.l = 0; /* Line 225, Address: 0x1004bc4 */
  lD0.w.l = k_wk.k_rx; /* Line 226, Address: 0x1004bc8 */
  lD0.l = lD0.w.l; /* Line 227, Address: 0x1004bd4 */
  if (lD0.l & 0x80000000) lD0.l <<= 8, lD0.l |= 0x80000000; else lD0.l <<= 8; /* Line 228, Address: 0x1004be4 */
  lD0.l += lD1.l; /* Line 229, Address: 0x1004c28 */
  lD0.l >>= 5; /* Line 230, Address: 0x1004c38 */
  return lD0.l; /* Line 231, Address: 0x1004c44 */
} /* Line 232, Address: 0x1004c48 */











int calc_xt_s(int scale) { /* Line 244, Address: 0x1004c60 */
  int_union lD0, lD1, lD2;

  lD0.l = k_wk.k_s * scale; /* Line 247, Address: 0x1004c68 */
  lD0.l >>= 8; /* Line 248, Address: 0x1004c84 */

  lD2.l = k_wk.k_msx * k_wk.k_s; /* Line 250, Address: 0x1004c90 */

  lD1.w.l = k_wk.k_msx; /* Line 252, Address: 0x1004cb8 */
  lD1.l = lD1.w.l; /* Line 253, Address: 0x1004cc4 */
  if (lD1.l & 0x80000000) lD1.l <<= 8, lD1.l |= 0x80000000; else lD1.l <<= 8; /* Line 254, Address: 0x1004cd4 */


  lD1.l -= lD2.l; /* Line 257, Address: 0x1004d18 */
  lD1.l >>= 5; /* Line 258, Address: 0x1004d28 */


  lD0.l += lD1.l; /* Line 261, Address: 0x1004d34 */
  return lD0.l; /* Line 262, Address: 0x1004d44 */
} /* Line 263, Address: 0x1004d48 */











int calc_yt_r() { /* Line 275, Address: 0x1004d60 */
  int_union lD0, lD1, lD2;


  lD1.l = k_wk.k_x_rx * k_wk.k_sin; /* Line 279, Address: 0x1004d64 */


  lD2.l = k_wk.k_y_ry * k_wk.k_cos; /* Line 282, Address: 0x1004d8c */


  lD2.l += lD1.l; /* Line 285, Address: 0x1004db4 */


  lD0.l = 0; /* Line 288, Address: 0x1004dc4 */
  lD0.w.l = k_wk.k_ry; /* Line 289, Address: 0x1004dc8 */
  lD0.l = lD0.w.l; /* Line 290, Address: 0x1004dd4 */
  if (lD0.l & 0x80000000) lD0.l <<= 8, lD0.l |= 0x80000000; else lD0.l <<= 8; /* Line 291, Address: 0x1004de4 */

  lD0.l += lD2.l; /* Line 293, Address: 0x1004e28 */
  lD0.l >>= 5; /* Line 294, Address: 0x1004e38 */
  return lD0.l; /* Line 295, Address: 0x1004e44 */
} /* Line 296, Address: 0x1004e48 */











int calc_yt_s(int scale) { /* Line 308, Address: 0x1004e60 */
  int_union lD0, lD1, lD2;


  lD0.l = k_wk.k_s * scale; /* Line 312, Address: 0x1004e68 */
  lD0.l >>= 8; /* Line 313, Address: 0x1004e84 */

  lD2.l = k_wk.k_msy * k_wk.k_s; /* Line 315, Address: 0x1004e90 */

  lD1.w.l = k_wk.k_msy; /* Line 317, Address: 0x1004eb8 */
  lD1.l = lD1.w.l; /* Line 318, Address: 0x1004ec4 */
  if (lD1.l & 0x80000000) lD1.l <<= 8, lD1.l |= 0x80000000; else lD1.l <<= 8; /* Line 319, Address: 0x1004ed4 */


  lD1.l -= lD2.l; /* Line 322, Address: 0x1004f18 */
  lD1.l >>= 5; /* Line 323, Address: 0x1004f28 */


  lD0.l += lD1.l; /* Line 326, Address: 0x1004f34 */
  return lD0.l; /* Line 327, Address: 0x1004f44 */
} /* Line 328, Address: 0x1004f48 */
