#include "EQU.H"
#include "IO.H"









void SWdataSet(ushort_union sw1, ushort_union sw2) { /* Line 12, Address: 0x1002310 */
  swdata1.w = sw1.w; /* Line 13, Address: 0x100231c */
  swdata2.w = sw2.w; /* Line 14, Address: 0x1002328 */

} /* Line 16, Address: 0x1002334 */




int random() { /* Line 21, Address: 0x1002340 */
  int_union lD0, lD1;
  unsigned short w;

  lD1.l = ranum; /* Line 25, Address: 0x1002348 */
  if (ranum == 0) lD1.l = 711800410; /* Line 26, Address: 0x1002354 */
  lD0.l = lD1.l; /* Line 27, Address: 0x1002370 */
  if (lD1.l < 0) { /* Line 28, Address: 0x1002378 */
    lD1.l *= 4; /* Line 29, Address: 0x1002384 */
    lD1.l |= -2147483648; /* Line 30, Address: 0x1002390 */
  } /* Line 31, Address: 0x10023a0 */
  else {
    lD1.l *= 4; /* Line 33, Address: 0x10023a8 */
  }
  lD1.l += lD0.l; /* Line 35, Address: 0x10023b4 */
  if (lD1.l < 0) { /* Line 36, Address: 0x10023c4 */
    lD1.l *= 8; /* Line 37, Address: 0x10023d0 */
    lD1.l |= -2147483648; /* Line 38, Address: 0x10023dc */
  } /* Line 39, Address: 0x10023ec */
  else {
    lD1.l *= 8; /* Line 41, Address: 0x10023f4 */
  }
  lD1.l += lD0.l; /* Line 43, Address: 0x1002400 */
  lD0.w.l += lD1.w.l; /* Line 44, Address: 0x1002410 */

  w = lD1.w.h; /* Line 46, Address: 0x1002420 */
  lD1.w.h = lD1.w.l; /* Line 47, Address: 0x1002428 */
  lD1.w.l = w; /* Line 48, Address: 0x1002430 */

  lD0.w.l += lD1.w.l; /* Line 50, Address: 0x1002434 */
  lD1.w.l = lD0.w.l; /* Line 51, Address: 0x1002444 */

  w = lD1.w.h; /* Line 53, Address: 0x100244c */
  lD1.w.h = lD1.w.l; /* Line 54, Address: 0x1002454 */
  lD1.w.l = w; /* Line 55, Address: 0x100245c */

  ranum = lD1.l; /* Line 57, Address: 0x1002460 */
  return lD0.l; /* Line 58, Address: 0x100246c */
} /* Line 59, Address: 0x1002470 */


void scrinit() {
  vscroll.l = 0; /* Line 63, Address: 0x1002480 */
  hscroll.l = 0; /* Line 64, Address: 0x1002488 */
} /* Line 65, Address: 0x1002490 */
