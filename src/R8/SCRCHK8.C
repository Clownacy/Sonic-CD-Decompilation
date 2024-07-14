#include "..\EQU.H"
#include "SCRCHK8.H"

static void zone8chk();





































void scrchk() { /* Line 42, Address: 0x101c410 */
  short ywk, limwk;

  zone8chk(); /* Line 45, Address: 0x101c420 */

  ywk = 4; /* Line 47, Address: 0x101c428 */

  if ((limwk = scralim_n_down - scralim_down) > 0) { /* Line 49, Address: 0x101c434 */

    if ((limwk = scra_v_posit.w.h + 8) >= scralim_down && (actwk[0].cddat & 2)) { /* Line 51, Address: 0x101c480 */

      ywk *= 4; /* Line 53, Address: 0x101c4e8 */
    }


    scralim_down += ywk; /* Line 57, Address: 0x101c4f4 */
    limmoveflag = 1; /* Line 58, Address: 0x101c508 */
  } else if (limwk < 0) { /* Line 59, Address: 0x101c514 */
    ywk *= -1; /* Line 60, Address: 0x101c52c */

    if ((limwk = scra_v_posit.w.h) > scralim_n_down) { /* Line 62, Address: 0x101c538 */
      scralim_down = limwk & 65534; /* Line 63, Address: 0x101c56c */
    }


    scralim_down += ywk; /* Line 67, Address: 0x101c588 */
    limmoveflag = 1; /* Line 68, Address: 0x101c59c */
  }
} /* Line 70, Address: 0x101c5a8 */






static void zone8chk() {
  switch (stageno.b.l) { /* Line 78, Address: 0x101c5c0 */
    case 0:
    case 1:
      scralim_n_down = 1808; /* Line 81, Address: 0x101c5f8 */
      break; /* Line 82, Address: 0x101c604 */

    case 2:
      if (!bossflag) { /* Line 85, Address: 0x101c60c */
        scralim_n_down = 784; /* Line 86, Address: 0x101c61c */
      } /* Line 87, Address: 0x101c628 */
      else {
        scralim_down = scralim_n_down = 268; /* Line 89, Address: 0x101c630 */
      }
      break;
  }



} /* Line 96, Address: 0x101c64c */
