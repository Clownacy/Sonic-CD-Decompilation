#include "..\EQU.H"
#include "SCRCHK4.H"























void scrchk() { /* Line 26, Address: 0x101c090 */
  short wD1;
  int_union temp1, temp2;

  zone4chk(); /* Line 30, Address: 0x101c09c */
  wD1 = 4; /* Line 31, Address: 0x101c0a4 */
  if (scralim_n_down != scralim_down) /* Line 32, Address: 0x101c0b0 */
  {
    if (scralim_n_down < scralim_down) /* Line 34, Address: 0x101c0d8 */
    {
      wD1 *= -1; /* Line 36, Address: 0x101c104 */
      if (scra_v_posit.w.h >= scralim_n_down) /* Line 37, Address: 0x101c110 */
      {
        scralim_down = scra_v_posit.w.h; /* Line 39, Address: 0x101c13c */
        scralim_down &= -2; /* Line 40, Address: 0x101c14c */
      }
      scralim_down += wD1; /* Line 42, Address: 0x101c164 */
      limmoveflag = 1; /* Line 43, Address: 0x101c178 */
      return; /* Line 44, Address: 0x101c184 */
    }


    temp1.w.l = scra_v_posit.w.h + 8; /* Line 48, Address: 0x101c18c */
    temp2.w.l = scralim_down; /* Line 49, Address: 0x101c1ac */
    if (temp1.l >= temp2.l) /* Line 50, Address: 0x101c1b8 */
    {
      if (actwk[0].cddat & 2) /* Line 52, Address: 0x101c1cc */
        wD1 *= 4; /* Line 53, Address: 0x101c1e4 */
    }
    scralim_down = wD1; /* Line 55, Address: 0x101c1f0 */
    limmoveflag = 1; /* Line 56, Address: 0x101c1f8 */
  }
} /* Line 58, Address: 0x101c204 */



void zone4chk() { /* Line 62, Address: 0x101c220 */
  void(*tbl[3])() = /* Line 63, Address: 0x101c228 */
  {
    &zone41chk,
    &zone42chk,
    &zone43chk
  };

  tbl[stageno.b.l](); /* Line 70, Address: 0x101c24c */
} /* Line 71, Address: 0x101c270 */



void zone41chk() {
  scralim_n_down = 1296; /* Line 76, Address: 0x101c280 */
} /* Line 77, Address: 0x101c28c */


void zone42chk() { /* Line 80, Address: 0x101c2a0 */
  int_union temp;

  if (actwk[0].mstno.b.h != 43) /* Line 83, Address: 0x101c2a4 */
  {
    if (actwk[0].r_no0 < 6) /* Line 85, Address: 0x101c2c0 */
    {
      scralim_down = 2048; /* Line 87, Address: 0x101c2d8 */
      scralim_n_down = 2048; /* Line 88, Address: 0x101c2e4 */
      temp.l = 0; /* Line 89, Address: 0x101c2f0 */
      temp.w.h = scra_h_posit.w.h; /* Line 90, Address: 0x101c2f4 */
      if (temp.l < 512) return; /* Line 91, Address: 0x101c300 */
    }
  }

  scralim_down = 1808; /* Line 95, Address: 0x101c310 */
  scralim_n_down = 1808; /* Line 96, Address: 0x101c31c */
} /* Line 97, Address: 0x101c328 */


void zone43chk() { /* Line 100, Address: 0x101c340 */
  if (bossclr_scr(2808, 1216) == 0) /* Line 101, Address: 0x101c348 */
  {
    if (bossflag) /* Line 103, Address: 0x101c360 */
    {

      scralim_down = 1264; /* Line 106, Address: 0x101c370 */
      scralim_n_down = 1264; /* Line 107, Address: 0x101c37c */
    }
  }
} /* Line 110, Address: 0x101c388 */


int bossclr_scr(short XPosi, short DownLim) { /* Line 113, Address: 0x101c3a0 */
  int ret = 0; /* Line 114, Address: 0x101c3b4 */

  if (XPosi <= actwk[0].xposi.w.h) /* Line 116, Address: 0x101c3b8 */
    ret = bossclr_scrset(DownLim); /* Line 117, Address: 0x101c3e0 */
  return ret; /* Line 118, Address: 0x101c3f0 */
} /* Line 119, Address: 0x101c3f4 */


int bossclr_scrset(short DownLim) { /* Line 122, Address: 0x101c410 */
  short temp;

  scralim_n_down = DownLim; /* Line 125, Address: 0x101c41c */
  DownLim -= scralim_down; /* Line 126, Address: 0x101c428 */
  if (DownLim < 0) /* Line 127, Address: 0x101c43c */
    DownLim *= -1; /* Line 128, Address: 0x101c450 */

  if (DownLim < 4) /* Line 130, Address: 0x101c45c */
    scralim_down = scralim_n_down; /* Line 131, Address: 0x101c474 */

  temp = actwk[0].xposi.w.h - 160; /* Line 133, Address: 0x101c484 */
  if (temp >= scralim_left) /* Line 134, Address: 0x101c4a8 */
  {
    if (temp > scralim_right) /* Line 136, Address: 0x101c4cc */
      temp = scralim_right; /* Line 137, Address: 0x101c4f0 */
    
    scralim_left = temp; /* Line 139, Address: 0x101c500 */
    scralim_n_left = temp; /* Line 140, Address: 0x101c508 */
  }
  return 1; /* Line 142, Address: 0x101c510 */
} /* Line 143, Address: 0x101c514 */
