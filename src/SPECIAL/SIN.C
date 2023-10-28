#include "SIN.H"

static short sin_tbl[128] = {
    0,   3,   6,   9,  12,  15,  18,  22,  25,  28,  31,  34,  37,  40,  43,  47,
   50,  53,  56,  59,  62,  65,  68,  71,  74,  77,  80,  83,  86,  89,  92,  95,
   98, 101, 104, 106, 109, 112, 115, 118, 121, 123, 126, 129, 132, 134, 137, 140,
  142, 145, 147, 150, 153, 155, 158, 160, 162, 165, 167, 170, 172, 174, 177, 179,
  181, 183, 185, 188, 190, 192, 194, 196, 198, 200, 202, 204, 206, 208, 209, 211,
  213, 215, 216, 218, 220, 221, 223, 224, 226, 227, 229, 230, 231, 233, 234, 235,
  236, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 247, 248, 249, 250, 250,
  251, 251, 252, 252, 253, 253, 254, 254, 254, 255, 255, 255, 255, 255, 255, 256,
};




















short sp_sin(unsigned short angle) { /* Line 33, Address: 0x100cc10 */
  short wD4;

  angle &= 511; /* Line 36, Address: 0x100cc1c */
  wD4 = angle; /* Line 37, Address: 0x100cc28 */
  if (wD4 & 128) { /* Line 38, Address: 0x100cc34 */
    wD4 = ~wD4; /* Line 39, Address: 0x100cc48 */
  }
  wD4 &= 127; /* Line 41, Address: 0x100cc64 */
  wD4 = sin_tbl[wD4]; /* Line 42, Address: 0x100cc70 */
  if (angle & 256) /* Line 43, Address: 0x100cc94 */
    wD4 = -wD4; /* Line 44, Address: 0x100cca8 */
  return wD4; /* Line 45, Address: 0x100ccc4 */
} /* Line 46, Address: 0x100ccc8 */











short sp_cos(unsigned short angle) { /* Line 58, Address: 0x100cce0 */
  angle += 128; /* Line 59, Address: 0x100ccec */
  return sp_sin(angle); /* Line 60, Address: 0x100ccf8 */
} /* Line 61, Address: 0x100cd04 */
