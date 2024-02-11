#include "..\EQU.H"















void sikake33(sprite_status* actionwk) { /* Line 17, Address: 0x102f190 */

  if (actionwk->userflag.b.h < 0) kaitenban(actionwk); /* Line 19, Address: 0x102f19c */
  else {
    if (actionwk->userflag.b.h == 0) light(actionwk); /* Line 21, Address: 0x102f1c8 */
    else stopper(actionwk); /* Line 22, Address: 0x102f1f4 */
  }
} /* Line 24, Address: 0x102f200 */
