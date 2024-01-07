#include "EQU.H"
#include "SAVE.H"











void playloadb() { /* Line 14, Address: 0x1005e30 */
  sprite_status* pActwk;

  pActwk = &actwk[0]; /* Line 17, Address: 0x1005e38 */
  pActwk->xposi.w.h = lpKeepWork->plxposi_sb; /* Line 18, Address: 0x1005e40 */
  pActwk->yposi.w.h = lpKeepWork->plyposi_sb; /* Line 19, Address: 0x1005e50 */
  pActwk->cddat = lpKeepWork->cddat_sb; /* Line 20, Address: 0x1005e60 */
  pActwk->mspeed.w = lpKeepWork->plmspd_sb; /* Line 21, Address: 0x1005e70 */
  pActwk->xspeed.w = lpKeepWork->plxspd_sb; /* Line 22, Address: 0x1005e80 */
  pActwk->yspeed.w = lpKeepWork->plyspd_sb; /* Line 23, Address: 0x1005e90 */

  plring = lpKeepWork->plring_s; /* Line 25, Address: 0x1005ea0 */
  plring_s = lpKeepWork->plring_s; /* Line 26, Address: 0x1005eb4 */
  plring_f2 = lpKeepWork->plring_f2_s; /* Line 27, Address: 0x1005ec8 */
  plring_f2_s = lpKeepWork->plring_f2_s; /* Line 28, Address: 0x1005edc */

  pltime.l = lpKeepWork->pltime_sb; /* Line 30, Address: 0x1005ef0 */
  water_flag = lpKeepWork->water_flag_sb; /* Line 31, Address: 0x1005f04 */
  scralim_down = lpKeepWork->scralim_down_sb; /* Line 32, Address: 0x1005f18 */
  scralim_n_down = lpKeepWork->scralim_down_sb; /* Line 33, Address: 0x1005f2c */
  scra_h_posit.w.h = lpKeepWork->scra_h_posit_sb; /* Line 34, Address: 0x1005f40 */
  scra_v_posit.w.h = lpKeepWork->scra_v_posit_sb; /* Line 35, Address: 0x1005f54 */
  scrb_h_posit.w.h = lpKeepWork->scrb_h_posit_sb; /* Line 36, Address: 0x1005f68 */
  scrb_v_posit.w.h = lpKeepWork->scrb_v_posit_sb; /* Line 37, Address: 0x1005f7c */
  scrc_h_posit.w.h = lpKeepWork->scrc_h_posit_sb; /* Line 38, Address: 0x1005f90 */
  scrc_v_posit.w.h = lpKeepWork->scrc_v_posit_sb; /* Line 39, Address: 0x1005fa4 */
  scrz_h_posit.w.h = lpKeepWork->scrz_h_posit_sb; /* Line 40, Address: 0x1005fb8 */
  scrz_v_posit.w.h = lpKeepWork->scrz_v_posit_sb; /* Line 41, Address: 0x1005fcc */

  if (stageno.b.h == 6) { /* Line 43, Address: 0x1005fe0 */
    chibi_flag = lpKeepWork->chibi_sb; /* Line 44, Address: 0x1005ffc */
  }
  if ((char)plflag < 0) { /* Line 46, Address: 0x1006010 */
    scralim_left = lpKeepWork->plxposi_sb - 160; /* Line 47, Address: 0x1006030 */
  }


} /* Line 51, Address: 0x1006058 */


void playload() { /* Line 54, Address: 0x1006070 */
  sprite_status* pActwk;
  pActwk = &actwk[0]; /* Line 56, Address: 0x100607c */

  if (plflag == 2) { /* Line 58, Address: 0x1006084 */

    playloadb(); /* Line 60, Address: 0x100609c */
  } /* Line 61, Address: 0x10060a4 */
  else {

    plflag = plflag_s; /* Line 64, Address: 0x10060ac */
    pActwk->xposi.w.h = plxposi_s; /* Line 65, Address: 0x10060bc */
    pActwk->yposi.w.h = plyposi_s; /* Line 66, Address: 0x10060c8 */
    plring = 0; /* Line 67, Address: 0x10060d4 */
    plring_f2 = 0; /* Line 68, Address: 0x10060dc */
    pltime.l = pltime_s; /* Line 69, Address: 0x10060e4 */
    pltime.b.b4 = 59; /* Line 70, Address: 0x10060f4 */
    --pltime.b.b3; /* Line 71, Address: 0x1006100 */
    water_flag = water_flag_s; /* Line 72, Address: 0x1006114 */
    scralim_down = scralim_down_s; /* Line 73, Address: 0x1006124 */
    scralim_n_down = scralim_down_s; /* Line 74, Address: 0x1006134 */
    scra_h_posit.w.h = scra_h_posit_s; /* Line 75, Address: 0x1006144 */
    scra_v_posit.w.h = scra_v_posit_s; /* Line 76, Address: 0x1006154 */
    scrb_h_posit.w.h = scrb_h_posit_s; /* Line 77, Address: 0x1006164 */
    scrb_v_posit.w.h = scrb_v_posit_s; /* Line 78, Address: 0x1006174 */
    scrc_h_posit.w.h = scrc_h_posit_s; /* Line 79, Address: 0x1006184 */
    scrc_v_posit.w.h = scrc_v_posit_s; /* Line 80, Address: 0x1006194 */
    scrz_h_posit.w.h = scrz_h_posit_s; /* Line 81, Address: 0x10061a4 */
    scrz_v_posit.w.h = scrz_v_posit_s; /* Line 82, Address: 0x10061b4 */

    if (stageno.b.h == 6) { /* Line 84, Address: 0x10061c4 */
      chibi_flag = chibi_s; /* Line 85, Address: 0x10061e0 */
    }

    if (stageno.b.h == 2) { /* Line 88, Address: 0x10061f0 */
      waterposi_m = waterposi_m_s; /* Line 89, Address: 0x100620c */
      water_flag = water_flag_s; /* Line 90, Address: 0x100621c */
      waterflag = waterflag_s; /* Line 91, Address: 0x100622c */
    }

    if ((char)plflag < 0) { /* Line 94, Address: 0x100623c */
      scralim_left = plxposi_s - 160; /* Line 95, Address: 0x100625c */
    }
  }

} /* Line 99, Address: 0x1006280 */
