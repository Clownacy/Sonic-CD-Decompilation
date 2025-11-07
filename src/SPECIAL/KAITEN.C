#include "..\TYPES.H"
#include "COMMON.H"
#include "SPS_EQU.H"
#include "KAITEN.H"





































void scalinit(void) { /* Line 42, Address: 0x1009180 */
  int_union lD0;

  lD0.l = zoomwk.h * zoomwk.cz; /* Line 45, Address: 0x1009184 */
  lD0.l >>= 8; /* Line 46, Address: 0x10091ac */
  zoomwk.hcz.w.h = lD0.w.l; /* Line 47, Address: 0x10091b8 */
  lD0.l = zoomwk.h * zoomwk.sz; /* Line 48, Address: 0x10091c4 */
  lD0.l >>= 8; /* Line 49, Address: 0x10091ec */
  zoomwk.hsz.w.h = lD0.w.l; /* Line 50, Address: 0x10091f8 */
} /* Line 51, Address: 0x1009204 */











void scal(sprite_status_sp* pActwk) { /* Line 63, Address: 0x1009210 */
  int_union lD0, lD1, lD2, lD3, lD4;
  lD0.l = 0; /* Line 65, Address: 0x1009218 */
  lD1.l = 0; /* Line 66, Address: 0x100921c */
  lD2.l = 0; /* Line 67, Address: 0x1009220 */

  lD0.w.l = actwk[0].x_posi.w.h - pActwk->x_posi.w.h; /* Line 69, Address: 0x1009224 */
  lD1.w.l = actwk[0].y_posi.w.h - pActwk->y_posi.w.h; /* Line 70, Address: 0x1009254 */

  lD2.w.l = zoomwk.h + zoomwk.i; /* Line 72, Address: 0x1009284 */
  lD3.l = lD0.w.l * zoomwk.sz; /* Line 73, Address: 0x10092b4 */
  lD3.l >>= 8; /* Line 74, Address: 0x10092d8 */
  lD2.l -= lD3.l; /* Line 75, Address: 0x10092e4 */
  lD3.l = lD1.w.l * zoomwk.cz; /* Line 76, Address: 0x10092f4 */
  lD3.l >>= 8; /* Line 77, Address: 0x1009318 */
  lD2.l += lD3.l; /* Line 78, Address: 0x1009324 */
  if ((long int)lD2.l == 0) { /* Line 79, Address: 0x1009334 */
    lD2.l = 1; /* Line 80, Address: 0x1009348 */
  }
  lD3.l = zoomwk.hcz.w.h * lD0.w.l; /* Line 82, Address: 0x1009350 */
  lD4.l = zoomwk.hsz.w.h * lD1.w.l; /* Line 83, Address: 0x1009374 */
  lD3.l += lD4.l; /* Line 84, Address: 0x1009398 */
  lD3.w.l = lD3.l / lD2.l; /* Line 85, Address: 0x10093a8 */
  lD3.w.l += 256; /* Line 86, Address: 0x10093d0 */
  pActwk->sx_posi.w.h = lD3.w.l; /* Line 87, Address: 0x10093dc */
  lD3.l = zoomwk.h * pActwk->z_posi.w.h; /* Line 88, Address: 0x10093e8 */
  lD3.l >>= 3; /* Line 89, Address: 0x1009410 */
  lD3.w.l = lD3.l / lD2.l; /* Line 90, Address: 0x100941c */
  lD3.w.l += 256; /* Line 91, Address: 0x1009444 */
  pActwk->sy_posi.w.h = lD3.w.l; /* Line 92, Address: 0x1009450 */
} /* Line 93, Address: 0x100945c */











void cal_kaiten(void) { /* Line 105, Address: 0x1009470 */
  short i;
  short iD6;
  int lsv1, lsv2, lsv3, lsv4;
  int_union lD0, lD1, lD2, lD3, lD4, lD5;
  short* ptv_adr;


  ptv_adr = (short*)&tv_adr[0]; /* Line 113, Address: 0x1009490 */

  lD0.w.l = (unsigned short)zoomwk.x << 3; /* Line 115, Address: 0x100949c */
  lD1.w.l = (unsigned short)zoomwk.y << 3; /* Line 116, Address: 0x10094bc */

  lD2.w.l = -3; /* Line 118, Address: 0x10094dc */
  iD6 = 8; /* Line 119, Address: 0x10094e4 */

  lD3.l = zoomwk.cx * zoomwk.sz; /* Line 121, Address: 0x10094f4 */
  lD3.l >>= 5; /* Line 122, Address: 0x100951c */
  zoomwk.cxsz.w.h = lD3.w.l; /* Line 123, Address: 0x1009528 */
  lD3.l = zoomwk.cx * zoomwk.cz; /* Line 124, Address: 0x1009534 */
  lD3.l >>= 5; /* Line 125, Address: 0x100955c */
  zoomwk.cxcz.w.h = lD3.w.l; /* Line 126, Address: 0x1009568 */

  lD3.l = zoomwk.h * zoomwk.sx; /* Line 128, Address: 0x1009574 */
  lD3.l = lD3.w.l * zoomwk.sz; /* Line 129, Address: 0x100959c */
  lD3.l >>= 5; /* Line 130, Address: 0x10095c0 */
  zoomwk.hsxsz = lD3.l; /* Line 131, Address: 0x10095cc */

  lD3.l = zoomwk.h * zoomwk.sx; /* Line 133, Address: 0x10095d8 */
  lD3.l = lD3.w.l * zoomwk.cz; /* Line 134, Address: 0x1009600 */
  lD3.l >>= 5; /* Line 135, Address: 0x1009624 */
  zoomwk.hsxcz = lD3.l; /* Line 136, Address: 0x1009630 */
  lD3.l = zoomwk.h * zoomwk.cx; /* Line 137, Address: 0x100963c */
  zoomwk.hcx = lD3.l; /* Line 138, Address: 0x1009664 */

  lD3.l = -zoomwk.cz << 7; /* Line 140, Address: 0x1009670 */
  lsv1 = lD3.l << 3; /* Line 141, Address: 0x100968c */
  lD3.l = -zoomwk.sz << 7; /* Line 142, Address: 0x1009694 */
  lsv2 = lD3.l << 3; /* Line 143, Address: 0x10096b0 */
  lD3.l = zoomwk.cz * 127; /* Line 144, Address: 0x10096b8 */
  lsv3 = lD3.l << 3; /* Line 145, Address: 0x10096d4 */
  lD3.l = zoomwk.sz * 127; /* Line 146, Address: 0x10096dc */
  lsv4 = lD3.l << 3; /* Line 147, Address: 0x10096f8 */

  lD4.l = zoomwk.sx * zoomwk.sz; /* Line 149, Address: 0x1009700 */
  lD4.l >>= 5; /* Line 150, Address: 0x1009728 */
  lD3.l = lD4.l * (zoomwk.h + zoomwk.i); /* Line 151, Address: 0x1009734 */
  lD3.l >>= iD6; /* Line 152, Address: 0x1009764 */
  zoomwk.hisxsz.w.h = lD3.w.l; /* Line 153, Address: 0x1009778 */
  lD4.l = zoomwk.sx * zoomwk.cz; /* Line 154, Address: 0x1009784 */
  lD4.l >>= 5; /* Line 155, Address: 0x10097ac */
  lD3.l = lD4.l * (zoomwk.h + zoomwk.i); /* Line 156, Address: 0x10097b8 */
  lD3.l >>= iD6; /* Line 157, Address: 0x10097e8 */
  zoomwk.hisxcz.w.h = lD3.w.l; /* Line 158, Address: 0x10097fc */


  for (i = 0; i < 3; ++i) { /* Line 161, Address: 0x1009808 */

    *ptv_adr++ = 0; /* Line 163, Address: 0x1009814 */
    *ptv_adr++ = -8; /* Line 164, Address: 0x1009820 */
    *ptv_adr++ = 0; /* Line 165, Address: 0x1009830 */
    *ptv_adr++ = 0; /* Line 166, Address: 0x100983c */
  } /* Line 167, Address: 0x1009848 */



  for (i = 0; i < 93; ++i, --lD2.w.l) { /* Line 171, Address: 0x1009868 */

    lD3.l = zoomwk.sx * lD2.w.l; /* Line 173, Address: 0x1009874 */
    lD3.l += zoomwk.hcx; /* Line 174, Address: 0x1009898 */
    lD3.l >>= 5; /* Line 175, Address: 0x10098ac */
    if ((long int)lD3.l == 0) { /* Line 176, Address: 0x10098b8 */
      lD3.l = 1; /* Line 177, Address: 0x10098cc */
    }
    lD5.l = zoomwk.cxsz.w.h * lD2.w.l; /* Line 179, Address: 0x10098d4 */
    lD4.l = zoomwk.hsxsz + (lsv1 - lD5.l); /* Line 180, Address: 0x10098f8 */
    lD4.l >>= iD6; /* Line 181, Address: 0x1009910 */
    lD4.l *= zoomwk.z; /* Line 182, Address: 0x1009924 */
    lD4.w.l = lD4.l / lD3.l; /* Line 183, Address: 0x1009940 */
    lD4.w.l += lD0.w.l; /* Line 184, Address: 0x1009968 */
    lD4.w.l -= zoomwk.hisxsz.w.h; /* Line 185, Address: 0x1009978 */
    *ptv_adr++ = lD4.w.l; /* Line 186, Address: 0x100998c */

    lD5.l = zoomwk.cxcz.w.h * lD2.w.l; /* Line 188, Address: 0x100999c */
    lD4.l = lsv2 + lD5.l - zoomwk.hsxcz; /* Line 189, Address: 0x10099c0 */
    lD4.l >>= iD6; /* Line 190, Address: 0x10099d8 */
    lD4.l *= zoomwk.z; /* Line 191, Address: 0x10099ec */
    lD4.w.l = lD4.l / lD3.l; /* Line 192, Address: 0x1009a08 */
    lD4.w.l += lD1.w.l; /* Line 193, Address: 0x1009a30 */
    lD4.w.l += zoomwk.hisxcz.w.h; /* Line 194, Address: 0x1009a40 */
    *ptv_adr++ = lD4.w.l; /* Line 195, Address: 0x1009a54 */

    lD5.l = zoomwk.cxsz.w.h * lD2.w.l; /* Line 197, Address: 0x1009a64 */
    lD4.l = zoomwk.hsxsz + (lsv3 - lD5.l); /* Line 198, Address: 0x1009a88 */
    lD4.l >>= iD6; /* Line 199, Address: 0x1009aa0 */
    lD4.l *= zoomwk.z; /* Line 200, Address: 0x1009ab4 */
    lD4.w.l = lD4.l / lD3.l; /* Line 201, Address: 0x1009ad0 */
    lD4.w.l += lD0.w.l; /* Line 202, Address: 0x1009af8 */
    lD4.w.l -= zoomwk.hisxsz.w.h; /* Line 203, Address: 0x1009b08 */
    lD4.w.l -= *(ptv_adr - 2); /* Line 204, Address: 0x1009b1c */
    *ptv_adr++ = lD4.w.l; /* Line 205, Address: 0x1009b2c */

    lD5.l = zoomwk.cxcz.w.h * lD2.w.l; /* Line 207, Address: 0x1009b40 */
    lD4.l = lsv4 + lD5.l - zoomwk.hsxcz; /* Line 208, Address: 0x1009b64 */
    lD4.l >>= iD6; /* Line 209, Address: 0x1009b7c */
    lD4.l *= zoomwk.z; /* Line 210, Address: 0x1009b90 */
    lD4.w.l = lD4.l / lD3.l; /* Line 211, Address: 0x1009bac */
    lD4.w.l += lD1.w.l; /* Line 212, Address: 0x1009bd4 */
    lD4.w.l += zoomwk.hisxcz.w.h; /* Line 213, Address: 0x1009be4 */
    lD4.w.l -= *(ptv_adr - 2); /* Line 214, Address: 0x1009bf8 */
    *ptv_adr++ = lD4.w.l; /* Line 215, Address: 0x1009c08 */
  } /* Line 216, Address: 0x1009c1c */
} /* Line 217, Address: 0x1009c48 */











void kaiten_init(void) {
  zoomwk.h = 128; /* Line 230, Address: 0x1009c70 */
  zoomwk.i = -64; /* Line 231, Address: 0x1009c7c */
} /* Line 232, Address: 0x1009c88 */











void init_3dpara(void) { /* Line 244, Address: 0x1009c90 */
  zoomwk.sx = k_sin(zoomwk.ax); /* Line 245, Address: 0x1009c98 */
  zoomwk.cx = k_cos(zoomwk.ax); /* Line 246, Address: 0x1009cb0 */
  zoomwk.sz = k_sin(zoomwk.az); /* Line 247, Address: 0x1009cc8 */
  zoomwk.cz = k_cos(zoomwk.az); /* Line 248, Address: 0x1009ce0 */
  zoomwk.msz = k_sin(zoomwk.az + 256); /* Line 249, Address: 0x1009cf8 */
  zoomwk.mcz = k_cos(zoomwk.az + 256); /* Line 250, Address: 0x1009d24 */
} /* Line 251, Address: 0x1009d50 */











void kaiten(void) { /* Line 263, Address: 0x1009d60 */
  cal_kaiten(); /* Line 264, Address: 0x1009d68 */
} /* Line 265, Address: 0x1009d70 */











short k_sin(short iD3) { /* Line 277, Address: 0x1009d80 */
  short sin_tbl[128] = { /* Line 278, Address: 0x1009d8c */
      0,   3,   6,   9,  12,  15,  18,  22,  25,  28,  31,  34,  37,  40,  43,  47,
     50,  53,  56,  59,  62,  65,  68,  71,  74,  77,  80,  83,  86,  89,  92,  95,
     98, 101, 104, 106, 109, 112, 115, 118, 121, 123, 126, 129, 132, 134, 137, 140,
    142, 145, 147, 150, 153, 155, 158, 160, 162, 165, 167, 170, 172, 174, 177, 179,
    181, 183, 185, 188, 190, 192, 194, 196, 198, 200, 202, 204, 206, 208, 209, 211,
    213, 215, 216, 218, 220, 221, 223, 224, 226, 227, 229, 230, 231, 233, 234, 235,
    236, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 247, 248, 249, 250, 250,
    251, 251, 252, 252, 253, 253, 254, 254, 254, 255, 255, 255, 255, 255, 255, 256,
  };
  short iD4;


  iD3 &= 511; /* Line 291, Address: 0x1009dc0 */
  iD4 = iD3; /* Line 292, Address: 0x1009dcc */
  if (iD3 & 128) { /* Line 293, Address: 0x1009dd8 */
    iD4 = ~iD4; /* Line 294, Address: 0x1009df0 */
  }
  iD4 &= 127; /* Line 296, Address: 0x1009e0c */
  iD4 = sin_tbl[iD4]; /* Line 297, Address: 0x1009e18 */
  if (iD3 & 256) { /* Line 298, Address: 0x1009e34 */
    iD4 = -iD4; /* Line 299, Address: 0x1009e4c */
  }
  return iD4; /* Line 301, Address: 0x1009e68 */
} /* Line 302, Address: 0x1009e6c */

short k_cos(short iD3) { /* Line 304, Address: 0x1009e80 */
  return k_sin(iD3 + 128); /* Line 305, Address: 0x1009e8c */
} /* Line 306, Address: 0x1009eac */
