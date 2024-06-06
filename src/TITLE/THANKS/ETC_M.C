#include "..\..\TYPES.H"
#include "ETC_M.H"

extern int ranum;





















int random() { /* Line 26, Address: 0x1001530 */
  int_union d0, d1;
  short tmp;

  d1.l = ranum; /* Line 30, Address: 0x1001538 */
  if (d1.l == 0) /* Line 31, Address: 0x1001544 */
  {
    d1.l = 711800410; /* Line 33, Address: 0x1001550 */
  }
  d0.l = d1.l; /* Line 35, Address: 0x100155c */
  d1.l <<= 2; /* Line 36, Address: 0x1001564 */
  d1.l += d0.l; /* Line 37, Address: 0x1001570 */
  d1.l <<= 3; /* Line 38, Address: 0x1001580 */
  d1.l += d0.l; /* Line 39, Address: 0x100158c */
  d0.l = d1.l; /* Line 40, Address: 0x100159c */
  tmp = d1.w.h; /* Line 41, Address: 0x10015a4 */
  d1.w.h = d1.w.l; /* Line 42, Address: 0x10015b0 */
  d0.w.l = tmp; /* Line 43, Address: 0x10015b8 */
  d0.w.l += d1.w.l; /* Line 44, Address: 0x10015bc */
  d1.w.l = d0.w.l; /* Line 45, Address: 0x10015cc */
  tmp = d1.w.h; /* Line 46, Address: 0x10015d4 */
  d1.w.h = d1.w.l; /* Line 47, Address: 0x10015e0 */
  d0.w.l = tmp; /* Line 48, Address: 0x10015e8 */
  ranum = d1.l; /* Line 49, Address: 0x10015ec */

  return d0.l; /* Line 51, Address: 0x10015f8 */
} /* Line 52, Address: 0x10015fc */






short cosign(short d3) { /* Line 59, Address: 0x1001610 */
  d3 += 128; /* Line 60, Address: 0x100161c */
  return sign(d3); /* Line 61, Address: 0x1001628 */
} /* Line 62, Address: 0x1001634 */


short sign(short d3) { /* Line 65, Address: 0x1001650 */
  short sin_tbl[128] = /* Line 66, Address: 0x100165c */
  {
      0,   3,   6,   9,  12,  15,  18,  22,  25,  28,  31,  34,  37,  40,  43,  47,
     50,  53,  56,  59,  62,  65,  68,  71,  74,  77,  80,  83,  86,  89,  92,  95,
     98, 101, 104, 106, 109, 112, 115, 118, 121, 123, 126, 129, 132, 134, 137, 140,
    142, 145, 147, 150, 153, 155, 158, 160, 162, 165, 167, 170, 172, 174, 177, 179,
    181, 183, 185, 188, 190, 192, 194, 196, 198, 200, 202, 204, 206, 208, 209, 211,
    213, 215, 216, 218, 220, 221, 223, 224, 226, 227, 229, 230, 231, 233, 234, 235,
    236, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 247, 248, 249, 250, 250,
    251, 251, 252, 252, 253, 253, 254, 254, 254, 255, 255, 255, 255, 255, 255, 256
  };
  short d4;

  d3 &= 511; /* Line 79, Address: 0x1001690 */
  d4 = d3; /* Line 80, Address: 0x100169c */
  if (d3 & 128) /* Line 81, Address: 0x10016a8 */
  {
    d4 = ~d4; /* Line 83, Address: 0x10016c0 */
  }
  d4 &= 127; /* Line 85, Address: 0x10016dc */
  d4 += d4; /* Line 86, Address: 0x10016e8 */
  d4 = sin_tbl[d4 / 2]; /* Line 87, Address: 0x10016f4 */
  if (d3 & 256) /* Line 88, Address: 0x1001728 */
  {
    d4 *= -1; /* Line 90, Address: 0x1001740 */
  }
  d3 = d4; /* Line 92, Address: 0x100174c */

  return d3; /* Line 94, Address: 0x1001750 */
} /* Line 95, Address: 0x1001754 */
