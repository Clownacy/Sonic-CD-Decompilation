#include "EQU.H"
#include "SCRCHK.H"







































void scrchk() { /* Line 42, Address: 0x1017a10 */
  short sD1;

  switch (stageno.b.h) { /* Line 45, Address: 0x1017a1c */
    case 0:
      zone1chk(); break; /* Line 47, Address: 0x1017a54 */
    case 1:
      zone3chk(); break;/* Line 49, Address: 0x1017a64 */
    case 2:
      zone4chk(); break; /* Line 51, Address: 0x1017a74 */
    case 3:
      zone5chk(); break; /* Line 53, Address: 0x1017a84 */
    case 4:
      zone6chk(); break; /* Line 55, Address: 0x1017a94 */
    case 5:
      zone7chk(); break; /* Line 57, Address: 0x1017aa4 */
    case 6:
      zone8chk(); break; /* Line 59, Address: 0x1017ab4 */
  }


  if (actwk[0].mstno.b.h == 43) { /* Line 63, Address: 0x1017abc */
    scralim_down = scra_v_posit.w.h; /* Line 64, Address: 0x1017ad8 */
    scralim_n_down = scra_v_posit.w.h; /* Line 65, Address: 0x1017ae8 */
  }
  sD1 = 4; /* Line 67, Address: 0x1017af8 */
  if (scralim_n_down == scralim_down) return; /* Line 68, Address: 0x1017b04 */



  if (scralim_n_down < scralim_down) { /* Line 72, Address: 0x1017b2c */

    sD1 = -sD1; /* Line 74, Address: 0x1017b58 */
    if (scralim_n_down < scra_v_posit.w.h) { /* Line 75, Address: 0x1017b64 */
      scralim_down = scra_v_posit.w.h & 65534; /* Line 76, Address: 0x1017b90 */
    }

    scralim_down += sD1; /* Line 79, Address: 0x1017bb4 */
    limmoveflag = 1; /* Line 80, Address: 0x1017bc8 */

    return; /* Line 82, Address: 0x1017bd4 */
  }

  if ((unsigned short)(scra_v_posit.w.h + 8) >= (unsigned short)scralim_down) { /* Line 85, Address: 0x1017bdc */

    if (actwk[0].cddat & 2) { /* Line 87, Address: 0x1017c14 */
      sD1 *= 4; /* Line 88, Address: 0x1017c2c */
    }
  }

  scralim_down += sD1; /* Line 92, Address: 0x1017c38 */
  limmoveflag = 1; /* Line 93, Address: 0x1017c4c */
} /* Line 94, Address: 0x1017c58 */



void zone1chk() { /* Line 98, Address: 0x1017c70 */
  switch (stageno.b.l) { /* Line 99, Address: 0x1017c78 */
    case 0:
      zone11chk(); break; /* Line 101, Address: 0x1017cb0 */
    case 1:
      zone12chk(); break; /* Line 103, Address: 0x1017cc0 */
    case 2:
      zone13chk(); break; /* Line 105, Address: 0x1017cd0 */
  }


} /* Line 109, Address: 0x1017cd8 */


void zone11chk() { /* Line 112, Address: 0x1017cf0*/
  if (time_flag != 1) { /* Line 113, Address: 0x1017cf8*/
    zone12chk(); /* Line 114, Address: 0x1017d10*/
  } /* Line 115, Address: 0x1017d18*/
  else {
    if (actwk[0].xposi.w.h >= 7190) { /* Line 117, Address: 0x1017d20*/
      if (actwk[0].xposi.w.h < 8646) { /* Line 118, Address: 0x1017d3c*/
        scra_vline = 136; /* Line 119, Address: 0x1017d58*/
      }
    }

    scralim_n_down = 1808; /* Line 123, Address: 0x1017d64*/
    if (scra_h_posit.w.h >= 2112) { /* Line 124, Address: 0x1017d70*/



      if (pltime_f != 0 && scralim_left < 2080) { /* Line 128, Address: 0x1017d8c*/

        scralim_left = scralim_n_left = 2080; /* Line 130, Address: 0x1017dbc*/

      }
      if (scra_h_posit.w.h >= 3584) { /* Line 133, Address: 0x1017dd8*/
        scralim_n_down = 784; /* Line 134, Address: 0x1017df4*/
      } /* Line 135, Address: 0x1017e00*/
      else {
        scralim_n_down = 1040; /* Line 137, Address: 0x1017e08*/
      }
    }
  }
} /* Line 141, Address: 0x1017e14*/


void zone12chk() {
  scralim_n_down = 784; /* Line 145, Address: 0x1017e30 */

} /* Line 147, Address: 0x1017e3c */


void zone13chk() { /* Line 150, Address: 0x1017e50*/
  if (bossflag) return; /* Line 151, Address: 0x1017e58*/
  scralim_n_down = 784; /* Line 152, Address: 0x1017e68*/
  bossclr_scr(3440, 784); /* Line 153, Address: 0x1017e74*/
} /* Line 154, Address: 0x1017e84*/


void zone3chk() { /* Line 157, Address: 0x1017ea0 */
  switch (stageno.b.l) { /* Line 158, Address: 0x1017ea8 */
    case 0:
      zone31chk(); break; /* Line 160, Address: 0x1017ee0 */
    case 1:
      zone31chk(); break; /* Line 162, Address: 0x1017ef0 */
    case 2:
      zone33chk(); break; /* Line 164, Address: 0x1017f00 */
  }


} /* Line 168, Address: 0x1017f08 */


void zone31chk() {
  scralim_n_down = 1296; /* Line 172, Address: 0x1017f20*/

} /* Line 174, Address: 0x1017f2c*/


void zone33chk() { /* Line 177, Address: 0x1017f40 */
  if (bossflag) { /* Line 178, Address: 0x1017f48 */
    bossclr_scrset(96); /* Line 179, Address: 0x1017f58 */
  } /* Line 180, Address: 0x1017f64 */
  else {
    scralim_n_down = 1296; /* Line 182, Address: 0x1017f6c */
  }

} /* Line 185, Address: 0x1017f78 */


void zone6chk() { /* Line 188, Address: 0x1017f90 */
  unsigned short wD0, wD1;

  if ((bossflag & 16) == 0) { /* Line 191, Address: 0x1017fa0 */
    scralim_n_down = 1808; /* Line 192, Address: 0x1017fb8 */
    return; /* Line 193, Address: 0x1017fc4 */
  }

  if (bossclr_scr(2976, 464) == 0) { /* Line 196, Address: 0x1017fcc */




    if (actwk[0].yposi.w.h < 665) { /* Line 201, Address: 0x1017fe4 */

      wD0 = 464; /* Line 203, Address: 0x1018000 */
    } /* Line 204, Address: 0x1018008 */
    else if (actwk[0].yposi.w.h < 1177) { /* Line 205, Address: 0x1018010 */

      wD0 = 976; /* Line 207, Address: 0x101802c */
    } /* Line 208, Address: 0x1018034 */
    else {

      wD0 = 1488; /* Line 211, Address: 0x101803c */
    }

    wD1 = wD0; /* Line 214, Address: 0x1018044 */
    scralim_n_down = wD0; /* Line 215, Address: 0x1018048 */
    wD0 -= scralim_down; /* Line 216, Address: 0x1018050 */
    if (wD0 < 0) { /* Line 217, Address: 0x1018064 */
      wD0 = -wD0; /* Line 218, Address: 0x101807c */
    }
    if (wD0 < 3) { /* Line 220, Address: 0x1018098 */
      scralim_down = wD1; /* Line 221, Address: 0x10180a8 */
    }
  }
} /* Line 224, Address: 0x10180b0 */


void zone5chk() { /* Line 227, Address: 0x10180d0 */
  switch (stageno.b.l) { /* Line 228, Address: 0x10180d8 */
    case 0:
      zone51chk(); break; /* Line 230, Address: 0x1018110 */
    case 1:
      zone51chk(); break; /* Line 232, Address: 0x1018120 */
    case 2:
      zone53chk(); break; /* Line 234, Address: 0x1018130 */
  }


} /* Line 238, Address: 0x1018138 */

void zone51chk() {
  scralim_n_down = 784; /* Line 241, Address: 0x1018150 */

} /* Line 243, Address: 0x101815c */

void zone53chk() { /* Line 245, Address: 0x1018170 */
  if (bossclr_scr(3600, 504) == 0) { /* Line 246, Address: 0x1018178 */



    if (bossflag) { /* Line 250, Address: 0x1018190 */

      scralim_down = 504; /* Line 252, Address: 0x10181a0 */
      scralim_n_down = 504; /* Line 253, Address: 0x10181ac */

    } /* Line 255, Address: 0x10181b8 */
    else {
      scralim_n_down = 800; /* Line 257, Address: 0x10181c0 */
    }
  }
} /* Line 260, Address: 0x10181cc */



void zone8chk() { /* Line 264, Address: 0x10181e0 */
  switch (stageno.b.l) { /* Line 265, Address: 0x10181e8 */
    case 0:
      zone81chk(); break; /* Line 267, Address: 0x1018220 */
    case 1:
      zone81chk(); break; /* Line 269, Address: 0x1018230 */
    case 2:
      zone83chk(); break; /* Line 271, Address: 0x1018240 */
  }


} /* Line 275, Address: 0x1018248 */


void zone81chk() {
  scralim_n_down = 1808; /* Line 279, Address: 0x1018260 */

} /* Line 281, Address: 0x101826c */


void zone83chk() { /* Line 284, Address: 0x1018280 */
  if (bossflag) {
    scralim_up = scralim_n_up = scralim_down = scralim_n_down = 268; /* Line 286, Address: 0x1018290 */


  } /* Line 289, Address: 0x10182cc */
  else {
    scralim_n_down = 784; /* Line 291, Address: 0x10182d4 */
  }

} /* Line 294, Address: 0x10182e0 */




void zone4chk() { /* Line 299, Address: 0x10182f0 */
  switch (stageno.b.l) { /* Line 300, Address: 0x10182f8 */
    case 0:
      zone41chk(); break; /* Line 302, Address: 0x1018330 */
    case 1:
      zone42chk(); break; /* Line 304, Address: 0x1018340 */
    case 2:
      zone43chk(); break; /* Line 306, Address: 0x1018350 */
  }


} /* Line 310, Address: 0x1018358 */



void zone41chk() {
  scralim_n_down = 1296; /* Line 315, Address: 0x1018370 */

} /* Line 317, Address: 0x101837c */

void zone42chk() {
  if (actwk[0].mstno.b.h == 43 || actwk[0].cddat >= 6) { /* Line 320, Address: 0x1018390 */

    scralim_down = 1808; /* Line 322, Address: 0x10183c4 */
    scralim_n_down = 1808; /* Line 323, Address: 0x10183d0 */
  } /* Line 324, Address: 0x10183dc */
  else {

    scralim_down = 2048; /* Line 327, Address: 0x10183e4 */
    scralim_n_down = 2048; /* Line 328, Address: 0x10183f0 */
    if (scra_h_posit.w.h >= 512) { /* Line 329, Address: 0x10183fc */
      scralim_down = 1808; /* Line 330, Address: 0x1018418 */
      scralim_n_down = 1808; /* Line 331, Address: 0x1018424 */
    }
  }

} /* Line 335, Address: 0x1018430 */

void zone43chk() { /* Line 337, Address: 0x1018440 */
  if (bossclr_scr(2808, 1216) == 0) { /* Line 338, Address: 0x1018448 */


    if (bossflag) { /* Line 341, Address: 0x1018460 */

      scralim_down = 1264; /* Line 343, Address: 0x1018470 */
      scralim_n_down = 1264; /* Line 344, Address: 0x101847c */
    }
  }
} /* Line 347, Address: 0x1018488 */




void zone7chk() { /* Line 352, Address: 0x10184a0 */
  switch (stageno.b.l) { /* Line 353, Address: 0x10184a8 */
    case 0:
      zone71chk(); break; /* Line 355, Address: 0x10184e0 */
    case 1:
      zone72chk(); break; /* Line 357, Address: 0x10184f0 */
    case 2:
      zone73chk(); break; /* Line 359, Address: 0x1018500 */
  }


} /* Line 363, Address: 0x1018508 */



void zone71chk() {
  scralim_n_down = 1296; /* Line 368, Address: 0x1018520 */

} /* Line 370, Address: 0x101852c */

void zone72chk() {
  scralim_n_down = 1808; /* Line 373, Address: 0x1018540 */

} /* Line 375, Address: 0x101854c */

void zone73chk() { /* Line 377, Address: 0x1018560 */
  unsigned short wD1;

  if (actwk[0].xposi.w.h < 2352) { /* Line 380, Address: 0x1018568 */
    scralim_n_down = 528; /* Line 381, Address: 0x1018584 */
    return; /* Line 382, Address: 0x1018590 */
  }

  if (actwk[0].xposi.w.h >= 3520) { /* Line 385, Address: 0x1018598 */

    scralim_n_down = 528; /* Line 387, Address: 0x10185b4 */
  } /* Line 388, Address: 0x10185c0 */
  else {

    scralim_n_down = 288; /* Line 391, Address: 0x10185c8 */
    wD1 = 288 - scralim_down; /* Line 392, Address: 0x10185d4 */
    if (wD1 < 0) { /* Line 393, Address: 0x10185f4 */
      wD1 = -wD1; /* Line 394, Address: 0x101860c */
    }
    if (wD1 < 4) { /* Line 396, Address: 0x1018628 */
      scralim_down = 288; /* Line 397, Address: 0x1018638 */
    }
  }
} /* Line 400, Address: 0x1018644 */










int bossclr_scr(unsigned short wD0, unsigned short wD1) { /* Line 411, Address: 0x1018660 */
  if (actwk[0].xposi.w.h >= wD0) { /* Line 412, Address: 0x1018670 */
    return bossclr_scrset(wD1); /* Line 413, Address: 0x10186a0 */
  }
  return 0; /* Line 415, Address: 0x10186b4 */
} /* Line 416, Address: 0x10186b8 */


int bossclr_scrset(unsigned short wD1) { /* Line 419, Address: 0x10186d0 */
  unsigned short wD0;

  scralim_n_down = wD1; /* Line 422, Address: 0x10186dc */
  if (wD1 < 0) { /* Line 424, Address: 0x1018700 */
  wD1 -= scralim_down; /* Line 423, Address: 0x10186e8 */
    wD1 = -wD1; /* Line 425, Address: 0x101871c */
  }
  if (wD1 < 4) { /* Line 427, Address: 0x101873c */
    scralim_down = scralim_n_down; /* Line 428, Address: 0x1018750 */
  }
  wD0 = actwk[0].xposi.w.h + -160; /* Line 430, Address: 0x1018760 */
  if (scralim_left > (short)wD0) { /* Line 431, Address: 0x101877c */
    return 1; /* Line 432, Address: 0x10187a8 */
  }
  if (scralim_right < wD0) { /* Line 434, Address: 0x10187b4 */
    wD0 = scralim_right; /* Line 435, Address: 0x10187e0 */
  }
  scralim_left = wD0; /* Line 437, Address: 0x10187ec */
  scralim_n_left = wD0; /* Line 438, Address: 0x10187f4 */
  return 1; /* Line 439, Address: 0x10187fc */
} /* Line 440, Address: 0x1018800 */
