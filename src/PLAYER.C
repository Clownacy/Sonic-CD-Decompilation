#include "EQU.H"
#include "PLAYER.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "DIRCOL.H"
#include "DUMMY.H"
#include "EDIT.H"
#include "FCOL.H"
#include "ETC.H"

extern void sub_sync(short ReqNo); extern void playsp(); extern short pcol(act_info* pActwk); extern void da_set(); extern void plairset(); extern void soundset(short ReqNo); extern short playdieset(act_info* pActwk);

unsigned int WaveClear;
unsigned char Brake_Sw, Brake_Req;
extern spr_array* sncpat[];
extern unsigned char mapwka[8][64];
extern void(*WaveAllStop)();
extern unsigned char* playchg[60];
extern unsigned char plchg00[8], plchg01[8], plchg49[8], plchg53[8], plchg03[8], plchg02[8], plchg54[8], plchg35[6], plchg04[8], plchg39[7], plchg33[6], plchg34[6];
unsigned char* playcg;
spr_array** playpat;

void bye_chk() { /* Line 23, Address: 0x1007500 */
  if (actwk[0].mstno.b.h != 5) { byecnt0.w = 0; return; } /* Line 24, Address: 0x1007508 */

  if (byecnt0.w == 0) byecnt0.b.l = 1; /* Line 26, Address: 0x1007534 */


  if (byecnt0.w < 10800) return; /* Line 29, Address: 0x1007558 */
  byecnt0.w = 0; /* Line 30, Address: 0x1007574 */
  actwk[0].mstno.b.h = 43; /* Line 31, Address: 0x100757c */
  actwk[0].sproffset |= 32768; /* Line 32, Address: 0x1007588 */
  actwk[0].sprpri = 0; /* Line 33, Address: 0x100759c */
  pl_suu = 1; /* Line 34, Address: 0x10075a4 */
  actwk[0].yspeed.w = -1280; /* Line 35, Address: 0x10075b0 */
  actwk[0].xspeed.w = 256; /* Line 36, Address: 0x10075bc */
  if (actwk[0].cddat & 1) actwk[0].xspeed.w = -actwk[0].xspeed.w; /* Line 37, Address: 0x10075c8 */

  actwk[0].mspeed.w = 0; /* Line 39, Address: 0x1007604 */
  sub_sync(121); /* Line 40, Address: 0x100760c */
} /* Line 41, Address: 0x1007618 */





void play00(act_info* actionwk) { /* Line 47, Address: 0x1007630 */
  unsigned char d0;

  Brake_Req = 0; /* Line 50, Address: 0x1007640 */

  if (actionwk != &actwk[0]) return; /* Line 52, Address: 0x1007648 */

  if (ta_flag == 0 && editmode.b.h != 0) { edit(&actwk[0]); return; } /* Line 54, Address: 0x100765c */

  d0 = actwk[0].actfree[0]; /* Line 56, Address: 0x10076a0 */
  if (d0 != 0) { /* Line 57, Address: 0x10076ac */
    ++d0; /* Line 58, Address: 0x10076b8 */
    if (actwk[0].cddat & 4) { /* Line 59, Address: 0x10076c0 */
      if (d0 >= 45) d0 = 45; /* Line 60, Address: 0x10076d8 */
    } /* Line 61, Address: 0x10076f0 */
    else if (d0 >= 30) d0 = 30; /* Line 62, Address: 0x10076f8 */


    actwk[0].actfree[0] = d0; /* Line 65, Address: 0x1007710 */
  }


  switch (actwk[0].r_no0) { /* Line 69, Address: 0x1007718 */
    case 0:
      play00init(); /* Line 71, Address: 0x1007764 */
      break; /* Line 72, Address: 0x100776c */
    case 2:
      play00move(); /* Line 74, Address: 0x1007774 */
      break; /* Line 75, Address: 0x100777c */
    case 4:
      play00damage(); /* Line 77, Address: 0x1007784 */
      break; /* Line 78, Address: 0x100778c */
    case 6:
      play00die(); /* Line 80, Address: 0x1007794 */
      break; /* Line 81, Address: 0x100779c */
    case 8:
      play00erase(); /* Line 83, Address: 0x10077a4 */
      break;
  }


  actwk[0].patbase = sncpat; /* Line 88, Address: 0x10077ac */

  if (Brake_Req == 0) Brake_Sw = 0; /* Line 90, Address: 0x10077bc */
} /* Line 91, Address: 0x10077d8 */






void muteki_set() {
  if (actwk[12].actno != 0) return; /* Line 99, Address: 0x10077f0 */
  plpower_a = 1; /* Line 100, Address: 0x1007804 */
  actwk[12].actno = actwk[13].actno = actwk[14].actno = actwk[15].actno = 3; /* Line 101, Address: 0x1007810 */

  actwk[12].mstno.b.h = 5; /* Line 103, Address: 0x1007840 */
  actwk[13].mstno.b.h = 6; /* Line 104, Address: 0x100784c */
  actwk[14].mstno.b.h = 7; /* Line 105, Address: 0x1007858 */
  actwk[15].mstno.b.h = 8; /* Line 106, Address: 0x1007864 */

} /* Line 108, Address: 0x1007870 */









void test_mapwrt() {} /* Line 118, Address: 0x1007880 */





void play00init() {
  actwk[0].r_no0 += 2; /* Line 125, Address: 0x1007890 */
  actwk[0].sprvsize = 19; /* Line 126, Address: 0x10078a4 */
  actwk[0].sprhs = 9; /* Line 127, Address: 0x10078b0 */
  if (chibi_flag != 0) { /* Line 128, Address: 0x10078bc */
    actwk[0].sprvsize = 10; /* Line 129, Address: 0x10078d0 */
    actwk[0].sprhs = 5; /* Line 130, Address: 0x10078dc */
  }


  actwk[0].sproffset = 1920; /* Line 134, Address: 0x10078e8 */
  actwk[0].sprpri = 2; /* Line 135, Address: 0x10078f4 */
  actwk[0].sprhsize = 24; /* Line 136, Address: 0x1007900 */
  actwk[0].actflg = 4; /* Line 137, Address: 0x100790c */
  plmaxspdwk = 1536; /* Line 138, Address: 0x1007918 */
  pladdspdwk = 12; /* Line 139, Address: 0x1007924 */
  plretspdwk = 128; /* Line 140, Address: 0x1007930 */
} /* Line 141, Address: 0x100793c */




void mizuki_set() { /* Line 146, Address: 0x1007950 */
 short d2, d3;
 unsigned int d1;
 act_info* new_actwk;

  if (stageno.b.h != 0) return; /* Line 151, Address: 0x1007964 */
  if (gametimer.b.l & 1) return; /* Line 152, Address: 0x100797c */
  d2 = actwk[0].sprvsize; /* Line 153, Address: 0x1007998 */
  d2 += actwk[0].yposi.w.h; /* Line 154, Address: 0x10079ac */
  d3 = actwk[0].xposi.w.h; /* Line 155, Address: 0x10079c0 */
  d1 = mapno_chk(d2, d3); /* Line 156, Address: 0x10079d0 */
  if ((d1 & 255) != 47) return; /* Line 157, Address: 0x10079e4 */
  if (actwk[0].xposi.w.h >= 5568) return; /* Line 158, Address: 0x10079f4 */

  if (actwk[0].actfree[2] == 0) return; /* Line 160, Address: 0x1007a10 */
  if (actwkchk(&new_actwk) != 0) return; /* Line 161, Address: 0x1007a24 */
  new_actwk->actno = 14; /* Line 162, Address: 0x1007a38 */
  new_actwk->xposi.w.h = actwk[0].xposi.w.h; /* Line 163, Address: 0x1007a44 */
  new_actwk->yposi.w.h = actwk[0].yposi.w.h; /* Line 164, Address: 0x1007a54 */
  if (actwk[0].xspeed.w < 0) /* Line 165, Address: 0x1007a64 */
    new_actwk->actflg = new_actwk->cddat = 1; /* Line 166, Address: 0x1007a7c */
  else
    new_actwk->actflg = new_actwk->cddat = 0; /* Line 168, Address: 0x1007a9c */
} /* Line 169, Address: 0x1007ab0 */




unsigned int mapno_chk(short d2, short d3) { /* Line 174, Address: 0x1007ad0 */
  unsigned int d1;

  d1 = 33; /* Line 177, Address: 0x1007ae0 */
  d1 += mapwka[d2 >> 8][d3 >> 8]; /* Line 178, Address: 0x1007ae4 */
  return d1; /* Line 179, Address: 0x1007b24 */
} /* Line 180, Address: 0x1007b28 */









void scr_h() { /* Line 190, Address: 0x1007b40 */
  short d0, d1;

  d0 = scra_hline; /* Line 193, Address: 0x1007b4c */
  if ((d1 = actwk[0].mspeed.w) < 0) d1 = -d1; /* Line 194, Address: 0x1007b5c */

  if (d1 < 1536 || ((actwk[0].actfree[2] & 2) && actwk[0].xposi.w.h < 6912)) { /* Line 196, Address: 0x1007b98 */


    if (d0 >= 161) d0 -= 2; /* Line 199, Address: 0x1007be0 */
    if (d0 < 160) d0 += 2; /* Line 200, Address: 0x1007c00 */
  } /* Line 201, Address: 0x1007c20 */
  else if (actwk[0].mspeed.w < 0) { /* Line 202, Address: 0x1007c28 */
    d0 += 2; /* Line 203, Address: 0x1007c40 */
    if (d0 >= 225) d0 = 224; /* Line 204, Address: 0x1007c4c */
  } else { /* Line 205, Address: 0x1007c6c */
    d0 -= 2; /* Line 206, Address: 0x1007c74 */
    if (d0 < 96) d0 = 96; /* Line 207, Address: 0x1007c80 */
  }


  scra_hline = d0; /* Line 211, Address: 0x1007ca0 */
} /* Line 212, Address: 0x1007ca8 */




void play00move() { /* Line 217, Address: 0x1007cc0 */
  scr_h(); /* Line 218, Address: 0x1007cc8 */
  mizuki_set(); /* Line 219, Address: 0x1007cd0 */
  if (debugflag.w != 0 && swdata1.b.l & 16) { /* Line 220, Address: 0x1007cd8 */
    editmode.b.h = 1; /* Line 221, Address: 0x1007d08 */
    return; /* Line 222, Address: 0x1007d14 */
  }

  if (plautoflag == 0) swdata.w = swdata1.w; /* Line 225, Address: 0x1007d1c */
  else swdata.b.l |= swdata1.b.l & 128; /* Line 226, Address: 0x1007d48 */




  if (actwk[0].actfree[2] & 1) { /* Line 231, Address: 0x1007d70 */
    if (stageno.b.h == 6) backto_cnt = 0, plpower_a = 0; /* Line 232, Address: 0x1007d88 */
    else backto_chk(); /* Line 233, Address: 0x1007dbc */
  } else { /* Line 234, Address: 0x1007dc4 */
    switch (actwk[0].cddat & 6) { /* Line 235, Address: 0x1007dcc */
      case 0:
        play00walk(); /* Line 237, Address: 0x1007e10 */
        break; /* Line 238, Address: 0x1007e18 */
      case 2:
        play00jump(); /* Line 240, Address: 0x1007e20 */
        break; /* Line 241, Address: 0x1007e28 */
      case 4:
        ball00walk(); /* Line 243, Address: 0x1007e30 */
        break; /* Line 244, Address: 0x1007e38 */
      case 6:
        ball00jump(); /* Line 246, Address: 0x1007e40 */
        break;
    }


    playsp(); /* Line 251, Address: 0x1007e48 */
  }

  playpowercnt(); /* Line 254, Address: 0x1007e50 */
  playposiwkset(); /* Line 255, Address: 0x1007e58 */

  plwaterchk(); /* Line 257, Address: 0x1007e60 */
  actwk[0].actfree[12] = dirstk[0]; /* Line 258, Address: 0x1007e68 */
  actwk[0].actfree[13] = dirstk[2]; /* Line 259, Address: 0x1007e78 */
  if (watercoliflag != 0 && actwk[0].mstno.b.h == 0) { /* Line 260, Address: 0x1007e88 */
    actwk[0].mstno.b.h = actwk[0].mstno.b.l; /* Line 261, Address: 0x1007eb4 */
  }
  patchgmain(); /* Line 263, Address: 0x1007ec4 */
  if (actwk[0].actfree[2] >= 0 && actwk[0].mstno.b.h != 43) { /* Line 264, Address: 0x1007ecc */

    pcol(&actwk[0]); /* Line 266, Address: 0x1007f08 */
  }
  loopchk(); /* Line 268, Address: 0x1007f18 */
} /* Line 269, Address: 0x1007f20 */






void playpowercnt() { /* Line 276, Address: 0x1007f30 */
  unsigned short d0;
  unsigned short cal;

  if (backto_cnt < 157) { /* Line 280, Address: 0x1007f40 */
    d0 = ((unsigned short*)actwk)[26]; /* Line 281, Address: 0x1007f5c */
    if (d0 != 0) { /* Line 282, Address: 0x1007f68 */
      --((unsigned short*)actwk)[26]; /* Line 283, Address: 0x1007f74 */
      if (d0 & 4) { /* Line 284, Address: 0x1007f88 */
        d0 >>= 3; /* Line 285, Address: 0x1007f98 */
        if ((actwk[0].actfree[2] & 64) == 0) /* Line 286, Address: 0x1007fa0 */
          actionsub(&actwk[0]); /* Line 287, Address: 0x1007fb8 */
      } else d0 >>= 3; /* Line 288, Address: 0x1007fc8 */
    } /* Line 289, Address: 0x1007fd8 */
    else if ((actwk[0].actfree[2] & 64) == 0) { /* Line 290, Address: 0x1007fe0 */
      actionsub(&actwk[0]); /* Line 291, Address: 0x1007ff8 */
    }
  }


  if (plpower_m != 0) { /* Line 296, Address: 0x1008008 */
    d0 = ((unsigned short*)actwk)[27]; /* Line 297, Address: 0x100801c */
    if (d0 != 0) { /* Line 298, Address: 0x1008028 */
      cal = d0 + -1; /* Line 299, Address: 0x1008034 */
      --((unsigned short*)actwk)[27]; /* Line 300, Address: 0x1008044 */
      if (cal == 0) { /* Line 301, Address: 0x1008058 */
        if (plpower_s == 0 && boss_sound == 0) { /* Line 302, Address: 0x1008064 */
          if (time_flag == 0) { /* Line 303, Address: 0x100808c */
            sub_sync(14); /* Line 304, Address: 0x10080a0 */
          }

          da_set(); /* Line 307, Address: 0x10080ac */
        }

        plpower_m = 0; /* Line 310, Address: 0x10080b4 */
      }
    }
  }


  if (plpower_s != 0) { /* Line 316, Address: 0x10080bc */
    d0 = ((unsigned short*)actwk)[28]; /* Line 317, Address: 0x10080d0 */
    if (d0 != 0) { /* Line 318, Address: 0x10080dc */
      cal = d0 + -1; /* Line 319, Address: 0x10080e8 */
      --((unsigned short*)actwk)[28]; /* Line 320, Address: 0x10080f8 */
      if (cal == 0) { /* Line 321, Address: 0x100810c */
        plmaxspdwk = 1536; /* Line 322, Address: 0x1008118 */
        pladdspdwk = 12; /* Line 323, Address: 0x1008124 */
        plretspdwk = 128; /* Line 324, Address: 0x1008130 */
        if (plpower_m == 0 && boss_sound == 0) { /* Line 325, Address: 0x100813c */
          if (time_flag == 0) { /* Line 326, Address: 0x1008164 */
            sub_sync(14); /* Line 327, Address: 0x1008178 */
          }

          da_set(); /* Line 330, Address: 0x1008184 */
        }

        plpower_s = 0; /* Line 333, Address: 0x100818c */
      }
    }
  }
} /* Line 337, Address: 0x1008194 */





void playposiwkset() {
  playposiwk[plposiwkadr.w / 2] = actwk[0].xposi.w.h; /* Line 344, Address: 0x10081b0 */
  playposiwk[plposiwkadr.w / 2 + 1] = actwk[0].yposi.w.h; /* Line 345, Address: 0x10081f0 */
  plposiwkadr.b.l += 4; /* Line 346, Address: 0x1008234 */
} /* Line 347, Address: 0x1008248 */




void plwaterchk() { /* Line 352, Address: 0x1008250 */
  unsigned char gavage = 129; /* Line 353, Address: 0x100825c */
  act_info* new_actwk;

  if (stageno.b.h != 2) return; /* Line 356, Address: 0x1008264 */

  if (stageno.b.l == 1 && actwk[0].xposi.w.h < 200) return; /* Line 358, Address: 0x1008280 */

  if (waterposi < actwk[0].yposi.w.h) { /* Line 360, Address: 0x10082b8 */
    if (actwk[0].cddat & 64) return; /* Line 361, Address: 0x10082e4 */
    actwk[0].cddat |= 64; /* Line 362, Address: 0x10082fc */
    plairset(); /* Line 363, Address: 0x1008310 */
    actwk[7].actno = 33; /* Line 364, Address: 0x1008318 */
    actwk[7].userflag.b.h = gavage; /* Line 365, Address: 0x1008324 */
    plmaxspdwk = 768; /* Line 366, Address: 0x100832c */
    pladdspdwk = 6; /* Line 367, Address: 0x1008338 */
    plretspdwk = 64; /* Line 368, Address: 0x1008344 */
    actwk[0].xspeed.w /= 2; /* Line 369, Address: 0x1008350 */
    actwk[0].yspeed.w /= 4; /* Line 370, Address: 0x1008378 */
    if (actwk[0].yspeed.w == 0) return; else goto label1; /* Line 371, Address: 0x10083a0 */
  }

  if (actwk[0].yspeed.w > 0) return; /* Line 374, Address: 0x10083c0 */
  if ((actwk[0].cddat & 64) == 0) return; /* Line 375, Address: 0x10083d8 */
  actwk[0].cddat &= 191; /* Line 376, Address: 0x10083f0 */
  plmaxspdwk = 1536; /* Line 377, Address: 0x1008404 */
  pladdspdwk = 12; /* Line 378, Address: 0x1008410 */
  plretspdwk = 128; /* Line 379, Address: 0x100841c */
  actwk[0].yspeed.w = actwk[0].yspeed.w << 1; /* Line 380, Address: 0x1008428 */
  if (actwk[0].yspeed.w == 0) return; /* Line 381, Address: 0x100843c */
  if (actwk[0].yspeed.w < -4096) actwk[0].yspeed.w = -4096; /* Line 382, Address: 0x1008454 */

label1:
  if (actwkchk(&new_actwk) != 0) return; /* Line 385, Address: 0x100847c */
  new_actwk->actno = 11; /* Line 386, Address: 0x1008490 */
  new_actwk->xposi.w.h = actwk[0].xposi.w.h; /* Line 387, Address: 0x100849c */
} /* Line 388, Address: 0x10084ac */




void playsave() {
  lpKeepWork->plflag_sb = plflag; /* Line 394, Address: 0x10084c0 */
  lpKeepWork->plxposi_sb = actwk[0].xposi.w.h; /* Line 395, Address: 0x10084d4 */
  lpKeepWork->plyposi_sb = actwk[0].yposi.w.h; /* Line 396, Address: 0x10084e8 */
  lpKeepWork->plmspd_sb = actwk[0].mspeed.w; /* Line 397, Address: 0x10084fc */
  lpKeepWork->plxspd_sb = actwk[0].xspeed.w; /* Line 398, Address: 0x1008510 */
  lpKeepWork->plyspd_sb = actwk[0].yspeed.w; /* Line 399, Address: 0x1008524 */
  lpKeepWork->cddat_sb = actwk[0].cddat; /* Line 400, Address: 0x1008538 */
  lpKeepWork->cddat_sb &= 247; /* Line 401, Address: 0x100854c */
  lpKeepWork->cddat_sb &= 191; /* Line 402, Address: 0x1008560 */
  lpKeepWork->water_flag_sb = water_flag; /* Line 403, Address: 0x1008574 */
  lpKeepWork->scralim_down_sb = scralim_down; /* Line 404, Address: 0x1008588 */
  lpKeepWork->scra_h_posit_sb = scra_h_posit.w.h; /* Line 405, Address: 0x100859c */
  lpKeepWork->scra_v_posit_sb = scra_v_posit.w.h; /* Line 406, Address: 0x10085b0 */
  lpKeepWork->scrb_h_posit_sb = scrb_h_posit.w.h; /* Line 407, Address: 0x10085c4 */
  lpKeepWork->scrb_v_posit_sb = scrb_v_posit.w.h; /* Line 408, Address: 0x10085d8 */
  lpKeepWork->scrc_h_posit_sb = scrc_h_posit.w.h; /* Line 409, Address: 0x10085ec */
  lpKeepWork->scrc_v_posit_sb = scrc_v_posit.w.h; /* Line 410, Address: 0x1008600 */
  lpKeepWork->scrz_h_posit_sb = scrz_h_posit.w.h; /* Line 411, Address: 0x1008614 */
  lpKeepWork->scrz_v_posit_sb = scrz_v_posit.w.h; /* Line 412, Address: 0x1008628 */
  lpKeepWork->waterposi_m_sb = waterposi_m; /* Line 413, Address: 0x100863c */
  lpKeepWork->water_flag_sb = water_flag; /* Line 414, Address: 0x1008650 */
  lpKeepWork->waterflag_sb = waterflag; /* Line 415, Address: 0x1008664 */
  lpKeepWork->plring_s = plring; /* Line 416, Address: 0x1008678 */
  plring_s = plring; /* Line 417, Address: 0x100868c */
  lpKeepWork->plring_f2_s = plring_f2; /* Line 418, Address: 0x100869c */
  plring_f2_s = plring_f2; /* Line 419, Address: 0x10086b0 */
  if (pltime.l >= (5 | 1)) lpKeepWork->pltime_sb = 5; /* Line 420, Address: 0x10086c0 */
  else lpKeepWork->pltime_sb = pltime.l; /* Line 421, Address: 0x10086f4 */

  lpKeepWork->chibi_sb = chibi_flag; /* Line 423, Address: 0x1008708 */
} /* Line 424, Address: 0x100871c */





void backto_chk() { /* Line 430, Address: 0x1008730 */
  short d0, d1, d2;
  char cal;


  if (lpKeepWork->TimeWarp == 0) return; /* Line 435, Address: 0x1008748 */

  if (stageno.w == -255) { /* Line 437, Address: 0x100875c */
    if (time_flag == 0 || time_flag == 2) { /* Line 438, Address: 0x1008778 */
      if (actwk[0].xposi.w.h < 2304) { /* Line 439, Address: 0x10087a4 */
        backto_cnt = 0; /* Line 440, Address: 0x10087c0 */
        time_item = 0; /* Line 441, Address: 0x10087c8 */
        plpower_a = 0; /* Line 442, Address: 0x10087d0 */
        return; /* Line 443, Address: 0x10087d8 */
      }
    }
  }

  if (actwk[0].actfree[0] != 0) return; /* Line 448, Address: 0x10087e0 */
  if (time_item == 0) return; /* Line 449, Address: 0x10087f4 */
  d1 = 1536; /* Line 450, Address: 0x100880c */
  d0 = actwk[0].mspeed.w; /* Line 451, Address: 0x1008818 */
  if (d0 < 0) d0 = -d0; /* Line 452, Address: 0x1008828 */
  if (backto_cnt == 0) backto_cnt = 1; /* Line 453, Address: 0x1008854 */
  if ((d2 = backto_cnt) >= 165) { /* Line 454, Address: 0x1008878 */
    if (plflag != 2) { /* Line 455, Address: 0x100889c */
      cal = time_flag; /* Line 456, Address: 0x10088b4 */
      cal += time_item; /* Line 457, Address: 0x10088c4 */
      if (cal < 0) cal = 0; /* Line 458, Address: 0x10088f0 */
      else if (cal >= 3) cal = 2; /* Line 459, Address: 0x100890c */
      time_flag = cal | 128; /* Line 460, Address: 0x100892c */
      playsave(); /* Line 461, Address: 0x1008944 */
    }





    gameflag.b.h = 1; /* Line 468, Address: 0x100894c */
    fadeout_s(); /* Line 469, Address: 0x1008958 */
    return; /* Line 470, Address: 0x1008960 */
  }
  if (d2 >= 157) { /* Line 472, Address: 0x1008968 */
    if (plflag == 2) return; /* Line 473, Address: 0x100897c */
    scroll_start.b.h = 1; /* Line 474, Address: 0x1008994 */
    cal = time_flag; /* Line 475, Address: 0x10089a0 */
    if (cal == 0) { /* Line 476, Address: 0x10089b0 */
      sub_sync(130); /* Line 477, Address: 0x10089c0 */
    }

    cal += time_item; /* Line 480, Address: 0x10089cc */
    if (cal < 0) cal = 0; /* Line 481, Address: 0x10089f8 */
    else if (cal >= 3) cal = 2; /* Line 482, Address: 0x1008a14 */
    time_flag = cal | 128; /* Line 483, Address: 0x1008a34 */
    playsave(); /* Line 484, Address: 0x1008a4c */
    plflag = 2; /* Line 485, Address: 0x1008a54 */
    return; /* Line 486, Address: 0x1008a60 */
  }

  if (d2 < 90) { /* Line 489, Address: 0x1008a68 */
    if (d0 >= d1) { muteki_set(); return; } /* Line 490, Address: 0x1008a7c */
    backto_cnt = 0; /* Line 491, Address: 0x1008aa8 */
    plpower_a = 0; /* Line 492, Address: 0x1008ab0 */
    return; /* Line 493, Address: 0x1008ab8 */
  }
  if (d0 < d1) { /* Line 495, Address: 0x1008ac0 */
    backto_cnt = 0; /* Line 496, Address: 0x1008adc */
    time_item = 0; /* Line 497, Address: 0x1008ae4 */
    plpower_a = 0; /* Line 498, Address: 0x1008aec */
  }
} /* Line 500, Address: 0x1008af4 */





void play00walk() { /* Line 506, Address: 0x1008b20 */
  bye_chk(); /* Line 507, Address: 0x1008b28 */
  if (actwk[0].mstno.b.h == 43) { /* Line 508, Address: 0x1008b30 */
    if (chibi_flag != 0) { /* Line 509, Address: 0x1008b4c */
      if (actwk[0].patno != 121) return; /* Line 510, Address: 0x1008b60 */
    } /* Line 511, Address: 0x1008b78 */
    else if (actwk[0].patno < 23) return; /* Line 512, Address: 0x1008b80 */

    limitchk(); /* Line 514, Address: 0x1008b98 */
    speedset(&actwk[0]); /* Line 515, Address: 0x1008ba0 */
    return; /* Line 516, Address: 0x1008bb0 */
  }
  chk11(); /* Line 518, Address: 0x1008bb8 */
  backto_chk(); /* Line 519, Address: 0x1008bc0 */
  if (jumpchk() != 0) return; /* Line 520, Address: 0x1008bc8 */
  keispd(); /* Line 521, Address: 0x1008bdc */
  levermove(); /* Line 522, Address: 0x1008be4 */
  ballchk(); /* Line 523, Address: 0x1008bec */
  limitchk(); /* Line 524, Address: 0x1008bf4 */
  speedset2(&actwk[0]); /* Line 525, Address: 0x1008bfc */
  fcol(&actwk[0]); /* Line 526, Address: 0x1008c0c */
  fallchk(); /* Line 527, Address: 0x1008c1c */
} /* Line 528, Address: 0x1008c24 */





void play00jump() { /* Line 534, Address: 0x1008c40 */
  if (watercoliflag == 0 && actwk[0].mstno.b.h != 21 && actwk[0].yspeed.w >= 0) { /* Line 535, Address: 0x1008c48 */
    actwk[0].mstno.b.h = 0; /* Line 536, Address: 0x1008c90 */
  }
  chk11(); /* Line 538, Address: 0x1008c98 */
  backto_chk(); /* Line 539, Address: 0x1008ca0 */
  jumpchk2(); /* Line 540, Address: 0x1008ca8 */
  jumpmove(); /* Line 541, Address: 0x1008cb0 */
  limitchk(); /* Line 542, Address: 0x1008cb8 */
  speedset(&actwk[0]); /* Line 543, Address: 0x1008cc0 */
  if (actwk[0].cddat & 64) actwk[0].yspeed.w -= 40; /* Line 544, Address: 0x1008cd0 */

  direcchg(); /* Line 546, Address: 0x1008cfc */

  jumpcolchk(); /* Line 548, Address: 0x1008d04 */
} /* Line 549, Address: 0x1008d0c */




void ball00walk() { /* Line 554, Address: 0x1008d20 */
  chk11(); /* Line 555, Address: 0x1008d28 */
  backto_chk(); /* Line 556, Address: 0x1008d30 */
  if (jumpchk() != 0) return; /* Line 557, Address: 0x1008d38 */
  keispd2(); /* Line 558, Address: 0x1008d4c */
  balllmove(); /* Line 559, Address: 0x1008d54 */
  limitchk(); /* Line 560, Address: 0x1008d5c */
  if (actwk[0].actfree[0] == 0) speedset2(&actwk[0]); /* Line 561, Address: 0x1008d64 */

  fcol(&actwk[0]); /* Line 563, Address: 0x1008d88 */
  fallchk(); /* Line 564, Address: 0x1008d98 */
} /* Line 565, Address: 0x1008da0 */




void ball00jump() { /* Line 570, Address: 0x1008db0 */
  chk11(); /* Line 571, Address: 0x1008db8 */
  backto_chk(); /* Line 572, Address: 0x1008dc0 */
  jumpchk2(); /* Line 573, Address: 0x1008dc8 */
  jumpmove(); /* Line 574, Address: 0x1008dd0 */
  limitchk(); /* Line 575, Address: 0x1008dd8 */

  speedset(&actwk[0]); /* Line 577, Address: 0x1008de0 */
  if (actwk[0].cddat & 64) actwk[0].yspeed.w -= 40; /* Line 578, Address: 0x1008df0 */

  direcchg(); /* Line 580, Address: 0x1008e1c */

  jumpcolchk(); /* Line 582, Address: 0x1008e24 */
} /* Line 583, Address: 0x1008e2c */




void chk11() { /* Line 588, Address: 0x1008e40 */
  short d0;
  char mapdata;
  char chk11tbl[5] = { 6, 7, 8, 73, 76 }; /* Line 591, Address: 0x1008e4c */

  if (time_flag != 1) return; /* Line 593, Address: 0x1008e78 */
  if (stageno.b.l != 0) return; /* Line 594, Address: 0x1008e90 */
  d0 = ((actwk[0].yposi.w.h >> 1) & 896) + (short)(actwk[0].xposi.b.b1 & 127); /* Line 595, Address: 0x1008ea8 */

  mapdata = mapwka[d0 / 128][d0 & 63]; /* Line 597, Address: 0x1008ef8 */
  for (d0 = 0; d0 < 5; ++d0) { /* Line 598, Address: 0x1008f44 */
    if (mapdata == chk11tbl[d0]) { /* Line 599, Address: 0x1008f50 */
      actwk[0].actfree[2] |= 2; /* Line 600, Address: 0x1008f78 */
      return; /* Line 601, Address: 0x1008f8c */
    }
  } /* Line 603, Address: 0x1008f94 */
  if ((actwk[0].actfree[2] & 2) == 0) return; /* Line 604, Address: 0x1008fb4 */
  actwk[0].actfree[2] &= 253; /* Line 605, Address: 0x1008fcc */
  if (actwk[0].yspeed.w >= 0) return; /* Line 606, Address: 0x1008fe0 */
  if (actwk[0].yspeed.w >= 63488) return; /* Line 607, Address: 0x1008ff8 */
  actwk[0].xspeed.w = 1536; /* Line 608, Address: 0x1009018 */
  if ((actwk[0].cddat & 1) == 0) return; /* Line 609, Address: 0x1009024 */
  actwk[0].xspeed.w = -actwk[0].xspeed.w; /* Line 610, Address: 0x100903c */
} /* Line 611, Address: 0x1009060 */






void levermove() { /* Line 618, Address: 0x1009080 */
  short d0;
  short d1;
  short d2;
  unsigned char ride_number;
  int sin_data;
  int cos_data;
  short sin_tmp;
  short cos_tmp;




  if (mizuflag != 0) goto label12; /* Line 631, Address: 0x10090a0 */
  if (((unsigned short*)actwk)[33] != 0) goto label10; /* Line 632, Address: 0x10090b4 */
  if (swdata.b.h & 4) plwalk_l(); /* Line 633, Address: 0x10090c8 */
  if (swdata.b.h & 8) plwalk_r(); /* Line 634, Address: 0x10090e8 */

  if (actwk[0].direc.b.h + 32 & 192) goto label10; /* Line 636, Address: 0x1009108 */
  if (actwk[0].mspeed.w != 0 && actwk[0].actfree[0] == 0) goto label10; /* Line 637, Address: 0x1009128 */

  if (actwk[0].mspeed.w == 0) { /* Line 639, Address: 0x1009154 */
    actwk[0].cddat &= 223; /* Line 640, Address: 0x100916c */
    actwk[0].mstno.b.h = 5; /* Line 641, Address: 0x1009180 */
  }
  if ((actwk[0].cddat & 8) == 0) goto label1; /* Line 643, Address: 0x100918c */

  ride_number = actwk[0].actfree[19]; /* Line 645, Address: 0x10091a4 */
  if (actwk[ride_number].cddat < 0) goto label4; /* Line 646, Address: 0x10091b0 */
  if (actwk[ride_number].actno == 30) { /* Line 647, Address: 0x10091e8 */
    actwk[0].mstno.b.h = 0; /* Line 648, Address: 0x1009218 */
    goto label10; /* Line 649, Address: 0x1009220 */
  }

  d1 = actwk[ride_number].sprhsize; /* Line 652, Address: 0x1009228 */
  d2 = d1 * 2 + -4; /* Line 653, Address: 0x1009254 */
  d1 = d1 + actwk[0].xposi.w.h - actwk[ride_number].xposi.w.h; /* Line 654, Address: 0x1009274 */
  if (d1 < 4) goto label3; /* Line 655, Address: 0x10092cc */
  if (d1 >= d2) goto label2; /* Line 656, Address: 0x10092e0 */
  goto label4; /* Line 657, Address: 0x10092fc */

label1:
  d1 = emycol_d(&actwk[0]); /* Line 660, Address: 0x1009304 */
  if (d1 < 12) goto label4; /* Line 661, Address: 0x100931c */
  soundset(171); /* Line 662, Address: 0x1009330 */
  if (WaveClear != 0) WaveAllStop(), WaveClear = 0; /* Line 663, Address: 0x100933c */
  actwk[0].actfree[0] = 0; /* Line 664, Address: 0x1009364 */
  actwk[0].mspeed.w = 0; /* Line 665, Address: 0x100936c */
  if (actwk[0].actfree[12] == 3) { /* Line 666, Address: 0x1009374 */

label2:
    if (actwk[0].cddat & 1) actwk[0].mstno.b.h = 50; /* Line 669, Address: 0x100938c */
    else actwk[0].mstno.b.h = 6; /* Line 670, Address: 0x10093b8 */
    goto label10; /* Line 671, Address: 0x10093c4 */
  }

  if (actwk[0].actfree[13] == 3) { /* Line 674, Address: 0x10093cc */

label3:
    if ((actwk[0].cddat & 1) == 0) actwk[0].mstno.b.h = 50; /* Line 677, Address: 0x10093e4 */
    else actwk[0].mstno.b.h = 6; /* Line 678, Address: 0x1009410 */
    goto label10; /* Line 679, Address: 0x100941c */
  }


label4:
  if (scr_cnt & 15) ++scr_cnt, scr_cnt &= 207; /* Line 684, Address: 0x1009424 */
  if (scr_cnt & 128) goto label7; /* Line 685, Address: 0x1009464 */
  if ((scr_cnt & 64) || (swdata.b.h & 2)) goto label8; /* Line 686, Address: 0x100947c */
  if ((scr_cnt &= 15) == 0) { /* Line 687, Address: 0x10094ac */
    if (swdata.b.l & 1) { scr_cnt = 1; goto label11; } /* Line 688, Address: 0x10094d0 */
  } else {
    if (swdata.b.l & 1) { scr_cnt |= 128; goto label11; } /* Line 690, Address: 0x10094fc */
  }

  if ((swdata.b.h & 1) == 0) goto label6; /* Line 693, Address: 0x1009530 */
  actwk[0].mstno.b.h = 7; /* Line 694, Address: 0x1009548 */
  if (actwk[0].actfree[0] == 0) goto label5; /* Line 695, Address: 0x1009554 */
  actwk[0].mstno.b.h = 0; /* Line 696, Address: 0x1009568 */
  d0 = 100; /* Line 697, Address: 0x1009570 */
  d1 = d2 = plmaxspdwk; /* Line 698, Address: 0x100957c */
  if (d1 & 32768) d1 *= 2, d1 |= -32768; else d1 = d1 * 2; /* Line 699, Address: 0x1009594 */
  if (plpower_s != 0) d2 /= 2, d1 -= d2; /* Line 700, Address: 0x10095d8 */
  if (actwk[0].cddat & 1) d0 = -d0, d1 = -d1; /* Line 701, Address: 0x1009618 */

  actwk[0].mspeed.w += d0; /* Line 703, Address: 0x1009668 */
  d0 = actwk[0].mspeed.w; /* Line 704, Address: 0x100967c */
  if (actwk[0].cddat & 1) { /* Line 705, Address: 0x100968c */
    if (d0 < d1) d0 = d1; /* Line 706, Address: 0x10096a4 */
  } else { /* Line 707, Address: 0x10096c8 */
    if (d0 > d1) d0 = d1; /* Line 708, Address: 0x10096d0 */
  }
  actwk[0].mspeed.w = d0; /* Line 710, Address: 0x10096f4 */
  return; /* Line 711, Address: 0x10096fc */

label5:
  if ((swdata.b.l & 112) == 0) goto label11; /* Line 714, Address: 0x1009704 */
  actwk[0].actfree[0] = 1; /* Line 715, Address: 0x100971c */
  soundset(156); /* Line 716, Address: 0x1009728 */
  WaveClear = 1; /* Line 717, Address: 0x1009734 */

  goto label11; /* Line 719, Address: 0x1009740 */

label6:
  if (actwk[0].actfree[0] != 30) { /* Line 722, Address: 0x1009748 */
    soundset(171); /* Line 723, Address: 0x1009760 */
    if (WaveClear != 0) WaveAllStop(), WaveClear = 0; /* Line 724, Address: 0x100976c */
    actwk[0].actfree[0] = 0; /* Line 725, Address: 0x1009794 */
    actwk[0].mspeed.w = 0; /* Line 726, Address: 0x100979c */
    goto label8; /* Line 727, Address: 0x10097a4 */
  }
  actwk[0].actfree[0] = 0; /* Line 729, Address: 0x10097ac */
  soundset(145); /* Line 730, Address: 0x10097b4 */
  WaveClear = 0; /* Line 731, Address: 0x10097c0 */
  goto label10; /* Line 732, Address: 0x10097c8 */



label7:
  if (swdata.b.h & 1) { /* Line 737, Address: 0x10097d0 */
    actwk[0].mstno.b.h = 7; /* Line 738, Address: 0x10097e8 */
    if (scra_vline != 200) scra_vline += 2; /* Line 739, Address: 0x10097f4 */
    goto label11; /* Line 740, Address: 0x1009824 */
  }
label8:
  if (scr_cnt & 64) goto label9; /* Line 743, Address: 0x100982c */
  if ((scr_cnt &= 15) != 0) { /* Line 744, Address: 0x1009844 */
    if (swdata.b.l & 2) { scr_cnt = 1; goto label11; } /* Line 745, Address: 0x1009868 */
  }
  else if (swdata.b.l & 2) { scr_cnt |= 64; goto label11; } /* Line 747, Address: 0x1009894 */


  if ((swdata.b.h & 2) == 0) goto label10; /* Line 750, Address: 0x10098c8 */
  actwk[0].mstno.b.h = 8; /* Line 751, Address: 0x10098e0 */
  if (actwk[0].actfree[0] != 0) goto label11; /* Line 752, Address: 0x10098ec */
  if ((swdata.b.l & 112) == 0) goto label11; /* Line 753, Address: 0x1009900 */
  actwk[0].actfree[0] = 1; /* Line 754, Address: 0x1009918 */
  actwk[0].mspeed.w = 22; /* Line 755, Address: 0x1009924 */
  if (actwk[0].cddat & 1) actwk[0].mspeed.w = -actwk[0].mspeed.w; /* Line 756, Address: 0x1009930 */
  soundset(156); /* Line 757, Address: 0x100996c */
  WaveClear = 1; /* Line 758, Address: 0x100997c */
  ballset(); /* Line 759, Address: 0x1009988 */
  goto label11; /* Line 760, Address: 0x1009994 */

label9:
  if (swdata.b.h & 2) { /* Line 763, Address: 0x100999c */
    actwk[0].mstno.b.h = 8; /* Line 764, Address: 0x10099b4 */
    if (scra_vline == 8) scra_vline -= 2; /* Line 765, Address: 0x10099c0 */
    goto label11; /* Line 766, Address: 0x10099f0 */
  }
label10:
  if (scra_vline == 96) { /* Line 769, Address: 0x10099f8 */
    if ((scr_cnt & 15) == 0) scr_cnt = 0; /* Line 770, Address: 0x1009a14 */
    goto label11; /* Line 771, Address: 0x1009a34 */
  }
  if (scra_vline < 96) scra_vline += 4; /* Line 773, Address: 0x1009a3c */
  scra_vline -= 2; /* Line 774, Address: 0x1009a6c */



label11:
  if ((swdata.b.h & 12) == 0 && actwk[0].mspeed.w != 0) { /* Line 779, Address: 0x1009a80 */

    if (actwk[0].mspeed.w > 0) { /* Line 781, Address: 0x1009ab0 */

      if ((actwk[0].mspeed.w -= pladdspdwk) < 0) actwk[0].mspeed.w = 0; /* Line 783, Address: 0x1009ac8 */
    } /* Line 784, Address: 0x1009b04 */
    else {
      if ((actwk[0].mspeed.w += pladdspdwk) >= 0) actwk[0].mspeed.w = 0; /* Line 786, Address: 0x1009b0c */
    }
  }
label12:
  sinset(actwk[0].direc.b.h, &sin_tmp, &cos_tmp); /* Line 790, Address: 0x1009b48 */
  sin_data = sin_tmp; /* Line 791, Address: 0x1009b68 */
  cos_data = cos_tmp; /* Line 792, Address: 0x1009b74 */

  cos_data *= actwk[0].mspeed.w; /* Line 794, Address: 0x1009b84 */
  cos_data >>= 8; /* Line 795, Address: 0x1009b98 */
  actwk[0].xspeed.w = cos_data; /* Line 796, Address: 0x1009ba0 */
  sin_data *= actwk[0].mspeed.w; /* Line 797, Address: 0x1009bb0 */
  sin_data >>= 8; /* Line 798, Address: 0x1009bc4 */
  actwk[0].yspeed.w = sin_data; /* Line 799, Address: 0x1009bc8 */

  lmovecol(); /* Line 801, Address: 0x1009bd8 */
} /* Line 802, Address: 0x1009be0 */


void lmovecol() { /* Line 805, Address: 0x1009c10 */
  short add_speed = 0; /* Line 806, Address: 0x1009c24 */
  char add_dir;
  char tmp_dir;
  unsigned char sonic_dir;

  if (actwk[0].direc.b.h < -64 || actwk[0].mspeed.w == 0) return; /* Line 811, Address: 0x1009c28 */
  add_dir = 64; /* Line 812, Address: 0x1009c64 */
  if (actwk[0].mspeed.w > 0) add_dir = -add_dir; /* Line 813, Address: 0x1009c70 */

  sonic_dir = actwk[0].direc.b.h + add_dir; /* Line 815, Address: 0x1009ca4 */
  tmp_dir = sonic_dir; /* Line 816, Address: 0x1009cc8 */
  if ((add_speed = (char)dircolm(&actwk[0], &tmp_dir)) >= 0) return; /* Line 817, Address: 0x1009ccc */
  sonic_dir = tmp_dir; /* Line 818, Address: 0x1009d10 */
  if (add_speed & 32768) add_speed <<= 8, add_speed |= -32768; else add_speed <<= 8; /* Line 819, Address: 0x1009d18 */
  sonic_dir = sonic_dir + 32 & 192; /* Line 820, Address: 0x1009d5c */
  switch (sonic_dir) { /* Line 821, Address: 0x1009d70 */

    case 0:
      actwk[0].yspeed.w += add_speed; /* Line 824, Address: 0x1009da8 */
      break; /* Line 825, Address: 0x1009dbc */

    case 64:
      actwk[0].xspeed.w -= add_speed; /* Line 828, Address: 0x1009dc4 */
      actwk[0].cddat |= 32; /* Line 829, Address: 0x1009dd8 */
      actwk[0].mspeed.w = 0; /* Line 830, Address: 0x1009dec */
      break; /* Line 831, Address: 0x1009df4 */

    case 128:
      actwk[0].yspeed.w -= add_speed; /* Line 834, Address: 0x1009dfc */
      break; /* Line 835, Address: 0x1009e10 */

    case 192:
      actwk[0].xspeed.w += add_speed; /* Line 838, Address: 0x1009e18 */
      actwk[0].cddat |= 32; /* Line 839, Address: 0x1009e2c */
      actwk[0].mspeed.w = 0; /* Line 840, Address: 0x1009e40 */
      break;
  }


} /* Line 845, Address: 0x1009e48 */




void plwalk_l() { /* Line 850, Address: 0x1009e70 */
  short cal_speed;

  if (actwk[0].actfree[0] != 0) return; /* Line 853, Address: 0x1009e7c */
  cal_speed = actwk[0].mspeed.w; /* Line 854, Address: 0x1009e90 */
  if (cal_speed <= 0) { /* Line 855, Address: 0x1009ea0 */

    if ((actwk[0].cddat & 1) == 0) { /* Line 857, Address: 0x1009eb0 */
      actwk[0].cddat |= 1; /* Line 858, Address: 0x1009ec8 */
      actwk[0].cddat &= 223; /* Line 859, Address: 0x1009edc */
      actwk[0].mstno.b.l = 1; /* Line 860, Address: 0x1009ef0 */
    }

    if (cal_speed > -plmaxspdwk) { /* Line 863, Address: 0x1009efc */
      cal_speed -= pladdspdwk; /* Line 864, Address: 0x1009f24 */
      if (!(cal_speed > -plmaxspdwk)) cal_speed = -plmaxspdwk; /* Line 865, Address: 0x1009f38 */
    }

    actwk[0].mspeed.w = cal_speed; /* Line 868, Address: 0x1009f84 */
    actwk[0].mstno.b.h = 0; /* Line 869, Address: 0x1009f8c */
  } /* Line 870, Address: 0x1009f94 */
  else {
    if ((cal_speed -= plretspdwk) < 0) cal_speed = -128; /* Line 872, Address: 0x1009f9c */

    actwk[0].mspeed.w = cal_speed; /* Line 874, Address: 0x1009fd4 */
    if (actwk[0].direc.b.h + 32 & 192) return; /* Line 875, Address: 0x1009fdc */
    if (cal_speed < 1024) return; /* Line 876, Address: 0x1009ffc */
    actwk[0].mstno.b.h = 13; /* Line 877, Address: 0x100a010 */
    actwk[0].cddat &= 254; /* Line 878, Address: 0x100a01c */

    if (Brake_Sw == 0) { /* Line 880, Address: 0x100a030 */
      soundset(144); /* Line 881, Address: 0x100a044 */
      Brake_Sw = 1; /* Line 882, Address: 0x100a050 */
    }
    Brake_Req = 1; /* Line 884, Address: 0x100a05c */
  }
} /* Line 886, Address: 0x100a068 */



void plwalk_r() { /* Line 890, Address: 0x100a080 */
  short cal_speed;

  if (actwk[0].actfree[0] != 0) return; /* Line 893, Address: 0x100a08c */
  cal_speed = actwk[0].mspeed.w; /* Line 894, Address: 0x100a0a0 */
  if (cal_speed >= 0) { /* Line 895, Address: 0x100a0b0 */

    if (actwk[0].cddat & 1) { /* Line 897, Address: 0x100a0c0 */
      actwk[0].cddat &= 254; /* Line 898, Address: 0x100a0d8 */
      actwk[0].cddat &= 223; /* Line 899, Address: 0x100a0ec */
      actwk[0].mstno.b.l = 1; /* Line 900, Address: 0x100a100 */
    }

    if (cal_speed < plmaxspdwk) { /* Line 903, Address: 0x100a10c */
      cal_speed += pladdspdwk; /* Line 904, Address: 0x100a130 */
      if (cal_speed >= plmaxspdwk) cal_speed = plmaxspdwk; /* Line 905, Address: 0x100a144 */
    }

    actwk[0].mspeed.w = cal_speed; /* Line 908, Address: 0x100a178 */
    actwk[0].mstno.b.h = 0; /* Line 909, Address: 0x100a180 */
  } /* Line 910, Address: 0x100a188 */
  else {
    if ((cal_speed += plretspdwk) >= 0) cal_speed = 128; /* Line 912, Address: 0x100a190 */
    actwk[0].mspeed.w = cal_speed; /* Line 913, Address: 0x100a1c8 */
    if (actwk[0].direc.b.h + 32 & 192) return; /* Line 914, Address: 0x100a1d0 */
    if (cal_speed >= -1023) return; /* Line 915, Address: 0x100a1f0 */
    actwk[0].mstno.b.h = 13; /* Line 916, Address: 0x100a204 */
    actwk[0].cddat |= 1; /* Line 917, Address: 0x100a210 */

    if (Brake_Sw == 0) { /* Line 919, Address: 0x100a224 */
      soundset(144); /* Line 920, Address: 0x100a238 */
      Brake_Sw = 1; /* Line 921, Address: 0x100a244 */
    }
    Brake_Req = 1; /* Line 923, Address: 0x100a250 */
  }
} /* Line 925, Address: 0x100a25c */







void balllmove() { /* Line 933, Address: 0x100a270 */
  short d0;
  short d1;
  short d2;
  int sin_data;
  int cos_data;
  short sin_tmp;
  short cos_tmp;


  if (mizuflag != 0) goto label3; /* Line 943, Address: 0x100a28c */
  if (((unsigned short*)actwk)[33] == 0) { /* Line 944, Address: 0x100a2a0 */
    if (swdata.b.h & 4) ballwalk_l(); /* Line 945, Address: 0x100a2b4 */
    if (swdata.b.h & 8) ballwalk_r(); /* Line 946, Address: 0x100a2d4 */
  }

  if (actwk[0].actfree[0] == 0) goto label1; /* Line 949, Address: 0x100a2f4 */
  d0 = 75; /* Line 950, Address: 0x100a308 */
  d1 = d2 = plmaxspdwk; /* Line 951, Address: 0x100a314 */
  if (d1 & 32768) d1 <<= 1, d1 |= -32768; else d1 <<= 1; /* Line 952, Address: 0x100a32c */
  if (plpower_s != 0) d2 /= 2, d1 -= d2; /* Line 953, Address: 0x100a370 */
  if (actwk[0].cddat & 1) d0 = -d0, d1 = -d1; /* Line 954, Address: 0x100a3b0 */

  actwk[0].mspeed.w += d0; /* Line 956, Address: 0x100a400 */
  d0 = actwk[0].mspeed.w; /* Line 957, Address: 0x100a414 */
  if (actwk[0].cddat & 1) { /* Line 958, Address: 0x100a424 */
    if (d0 < d1) d0 = d1; /* Line 959, Address: 0x100a43c */
  } /* Line 960, Address: 0x100a460 */
  else if (d1 < d0) d0 = d1; /* Line 961, Address: 0x100a468 */


  actwk[0].mspeed.w = d0; /* Line 964, Address: 0x100a48c */
  if ((swdata.b.h & 2) != 0) return; /* Line 965, Address: 0x100a494 */

  if (actwk[0].actfree[0] != 45) { /* Line 967, Address: 0x100a4ac */
    soundset(171); /* Line 968, Address: 0x100a4c4 */
    if (WaveClear != 0) WaveAllStop(), WaveClear = 0; /* Line 969, Address: 0x100a4d0 */
    actwk[0].actfree[0] = 0; /* Line 970, Address: 0x100a4f8 */
    actwk[0].mspeed.w = actwk[0].xspeed.w = actwk[0].yspeed.w = 0; /* Line 971, Address: 0x100a500 */
    goto label2; /* Line 972, Address: 0x100a528 */
  }
  actwk[0].actfree[0] = 0; /* Line 974, Address: 0x100a530 */
  soundset(145); /* Line 975, Address: 0x100a538 */
  WaveClear = 0; /* Line 976, Address: 0x100a544 */
  if ((actwk[0].cddat & 1) == 0) ballwalk_r(); /* Line 977, Address: 0x100a54c */
  else ballwalk_l(); /* Line 978, Address: 0x100a574 */

label1:
  d0 = actwk[0].mspeed.w; /* Line 981, Address: 0x100a57c */
  if (d0 != 0) { /* Line 982, Address: 0x100a58c */

    if (d0 > 0) { /* Line 984, Address: 0x100a59c */

      d0 = d0 - pladdspdwk / 2; /* Line 986, Address: 0x100a5ac */
      if (d0 < 0) d0 = 0; /* Line 987, Address: 0x100a5f0 */
      actwk[0].mspeed.w = d0; /* Line 988, Address: 0x100a604 */
    } /* Line 989, Address: 0x100a60c */
    else {
      d0 = d0 + pladdspdwk / 2; /* Line 991, Address: 0x100a614 */
      if (d0 > 0) d0 = 0; /* Line 992, Address: 0x100a658 */
      actwk[0].mspeed.w = d0; /* Line 993, Address: 0x100a66c */
    }
  }



  if (actwk[0].mspeed.w != 0) goto label3; /* Line 999, Address: 0x100a674 */



  soundset(171); /* Line 1003, Address: 0x100a68c */
  if (WaveClear != 0) WaveAllStop(), WaveClear = 0; /* Line 1004, Address: 0x100a698 */

label2:
  actwk[0].cddat &= 251; /* Line 1007, Address: 0x100a6c0 */
  if (chibi_flag != 0) { /* Line 1008, Address: 0x100a6d4 */
    actwk[0].sprvsize = 10; /* Line 1009, Address: 0x100a6e8 */
    actwk[0].sprhs = 5; /* Line 1010, Address: 0x100a6f4 */
    actwk[0].yposi.w.h -= 2; /* Line 1011, Address: 0x100a700 */
  } else { /* Line 1012, Address: 0x100a714 */
    actwk[0].sprvsize = 19; /* Line 1013, Address: 0x100a71c */
    actwk[0].sprhs = 9; /* Line 1014, Address: 0x100a728 */
    actwk[0].yposi.w.h -= 5; /* Line 1015, Address: 0x100a734 */
  }
  actwk[0].mstno.b.h = 5; /* Line 1017, Address: 0x100a748 */

label3:
  sinset(actwk[0].direc.b.h, &sin_tmp, &cos_tmp); /* Line 1020, Address: 0x100a754 */
  sin_data = sin_tmp; /* Line 1021, Address: 0x100a770 */
  cos_data = cos_tmp; /* Line 1022, Address: 0x100a77c */

  sin_data *= actwk[0].mspeed.w; /* Line 1024, Address: 0x100a788 */
  sin_data = sin_data >> 8; /* Line 1025, Address: 0x100a79c */
  actwk[0].yspeed.w = sin_data; /* Line 1026, Address: 0x100a7a0 */
  cos_data *= actwk[0].mspeed.w; /* Line 1027, Address: 0x100a7b0 */
  cos_data = cos_data >> 8; /* Line 1028, Address: 0x100a7c4 */
  if (cos_data >= 4097) cos_data = 4096; /* Line 1029, Address: 0x100a7c8 */
  if (cos_data < -4096) cos_data = -4096; /* Line 1030, Address: 0x100a7d8 */
  actwk[0].xspeed.w = cos_data; /* Line 1031, Address: 0x100a7e8 */

  lmovecol(); /* Line 1033, Address: 0x100a7f8 */
} /* Line 1034, Address: 0x100a800 */



void ballwalk_l() { /* Line 1038, Address: 0x100a830 */
  short cal_speed;

  if ((cal_speed = actwk[0].mspeed.w) <= 0) { /* Line 1041, Address: 0x100a838 */

    actwk[0].cddat |= 1; /* Line 1043, Address: 0x100a858 */
    actwk[0].mstno.b.h = 2; /* Line 1044, Address: 0x100a86c */
  } /* Line 1045, Address: 0x100a878 */
  else {
    cal_speed = cal_speed - plretspdwk / 4; /* Line 1047, Address: 0x100a880 */
    if (cal_speed < 0) cal_speed = -128; /* Line 1048, Address: 0x100a8c4 */
    actwk[0].mspeed.w = cal_speed; /* Line 1049, Address: 0x100a8e0 */
  }
} /* Line 1051, Address: 0x100a8e8 */


void ballwalk_r() { /* Line 1054, Address: 0x100a900 */
  short cal_speed;

  if ((cal_speed = actwk[0].mspeed.w) >= 0) { /* Line 1057, Address: 0x100a908 */

    actwk[0].cddat &= 254; /* Line 1059, Address: 0x100a928 */
    actwk[0].mstno.b.h = 2; /* Line 1060, Address: 0x100a93c */
  } /* Line 1061, Address: 0x100a948 */
  else {
    cal_speed = cal_speed + plretspdwk / 4; /* Line 1063, Address: 0x100a950 */
    if (cal_speed > 0) cal_speed = 128; /* Line 1064, Address: 0x100a994 */
    actwk[0].mspeed.w = cal_speed; /* Line 1065, Address: 0x100a9b0 */
  }
} /* Line 1067, Address: 0x100a9b8 */



void jumpmove() { /* Line 1071, Address: 0x100a9d0 */
  short cal_speed;
  short cmp_speed;





  cal_speed = actwk[0].xspeed.w; /* Line 1079, Address: 0x100a9dc */
  if (time_flag == 1 && stageno.w == 0) { /* Line 1080, Address: 0x100a9ec */

    if (actwk[0].xposi.w.h < 1736 || actwk[0].xposi.w.h >= 2112) { /* Line 1082, Address: 0x100aa1c */
      if (actwk[0].actfree[2] & 2) goto label2; else goto label1; /* Line 1083, Address: 0x100aa54 */
    } else {
      return; /* Line 1085, Address: 0x100aa74 */
    }
  }
label1:
  cal_speed = actwk[0].xspeed.w; /* Line 1089, Address: 0x100aa7c */
  if (swdata.b.h & 4) { /* Line 1090, Address: 0x100aa8c */
    actwk[0].cddat |= 1; /* Line 1091, Address: 0x100aaa4 */
    cal_speed -= pladdspdwk * 2; /* Line 1092, Address: 0x100aab8 */
    cmp_speed = -plmaxspdwk; /* Line 1093, Address: 0x100aae8 */
    if (!(cal_speed > cmp_speed)) cal_speed = cmp_speed; /* Line 1094, Address: 0x100ab0c */
  }

  if (swdata.b.h & 8) { /* Line 1097, Address: 0x100ab30 */
    actwk[0].cddat &= 254; /* Line 1098, Address: 0x100ab48 */
    cal_speed += pladdspdwk * 2; /* Line 1099, Address: 0x100ab5c */
    if (cal_speed >= plmaxspdwk) cal_speed = plmaxspdwk; /* Line 1100, Address: 0x100ab8c */
  }

label2:
  actwk[0].xspeed.w = cal_speed; /* Line 1104, Address: 0x100abc0 */

  if (scra_vline < 96) scra_vline += 2; /* Line 1106, Address: 0x100abc8 */
  else if (scra_vline >= 97) scra_vline -= 2; /* Line 1107, Address: 0x100ac00 */
  if ((unsigned short)actwk[0].yspeed.w < 64512) return; /* Line 1108, Address: 0x100ac30 */
  cal_speed = actwk[0].xspeed.w; /* Line 1109, Address: 0x100ac50 */
  if (cal_speed / 32 == 0) return; /* Line 1110, Address: 0x100ac60 */
  if (cal_speed > 0) { /* Line 1111, Address: 0x100ac88 */

    cal_speed = cal_speed - cal_speed / 32; /* Line 1113, Address: 0x100ac98 */
    if (cal_speed < 0) cal_speed = 0; /* Line 1114, Address: 0x100acd4 */
  } /* Line 1115, Address: 0x100ace8 */
  else {
    cal_speed = cal_speed - cal_speed / 32; /* Line 1117, Address: 0x100acf0 */
    if (cal_speed >= 0) cal_speed = 0; /* Line 1118, Address: 0x100ad2c */
  }
  actwk[0].xspeed.w = cal_speed; /* Line 1120, Address: 0x100ad40 */
} /* Line 1121, Address: 0x100ad48 */




void hedcolchk() { /* Line 1126, Address: 0x100ad60 */
  short tmp_d0, tmp_d1, tmp_d3;
  unsigned char cal_direc;

  cal_direc = actwk[0].direc.b.h + 32 & 192; /* Line 1130, Address: 0x100ad6c */
  if (cal_direc == 0) { /* Line 1131, Address: 0x100ad8c */
    if (dircol_u(&actwk[0], &tmp_d0, &tmp_d1, &tmp_d3) < 0) { /* Line 1132, Address: 0x100ad98 */
      actwk[0].mspeed.w = actwk[0].xspeed.w = actwk[0].yspeed.w = 0; /* Line 1133, Address: 0x100adc4 */
      actwk[0].mstno.b.h = 11; /* Line 1134, Address: 0x100adec */
    }
  }
} /* Line 1137, Address: 0x100adf8 */




void limitchk() { /* Line 1142, Address: 0x100ae10 */
  short cal_limit_l, cal_limit_r, position_wk;
  int cal_position, cal_speed;

  cal_position = actwk[0].xposi.l; /* Line 1146, Address: 0x100ae2c */
  cal_speed = actwk[0].xspeed.w; /* Line 1147, Address: 0x100ae34 */
  if (cal_speed & -2147483648) cal_speed <<= 8, cal_speed |= -2147483648; else cal_speed <<= 8; /* Line 1148, Address: 0x100ae44 */
  cal_position += cal_speed; /* Line 1149, Address: 0x100ae6c */
  position_wk = cal_position >> 16; /* Line 1150, Address: 0x100ae70 */
  cal_limit_l = scralim_left + 16; /* Line 1151, Address: 0x100ae84 */
  cal_limit_r = scralim_right + 304; /* Line 1152, Address: 0x100aea8 */
  if (bossstart == 0) cal_limit_r += 56; /* Line 1153, Address: 0x100aecc */
  if (position_wk < cal_limit_l) { /* Line 1154, Address: 0x100aeec */

    actwk[0].xposi.w.h = cal_limit_l; /* Line 1156, Address: 0x100af08 */
    actwk[0].xposi.w.l = actwk[0].xspeed.w = actwk[0].mspeed.w = 0; /* Line 1157, Address: 0x100af10 */
  }
  if (position_wk >= cal_limit_r) { /* Line 1159, Address: 0x100af38 */

    actwk[0].xposi.w.h = cal_limit_r; /* Line 1161, Address: 0x100af54 */
    actwk[0].xposi.w.l = actwk[0].xspeed.w = actwk[0].mspeed.w = 0; /* Line 1162, Address: 0x100af5c */
  }

  if (scralim_down + 224 >= actwk[0].yposi.w.h) return; /* Line 1165, Address: 0x100af84 */

  if (actwk[0].mstno.b.h != 43) playdieset(&actwk[0]); /* Line 1167, Address: 0x100afb4 */
  else actwk[0].r_no0 = 6; /* Line 1168, Address: 0x100afe8 */
} /* Line 1169, Address: 0x100aff4 */




void ballchk() { /* Line 1174, Address: 0x100b020 */
  if (mizuflag != 0) return; /* Line 1175, Address: 0x100b028 */

  if (actwk[0].mspeed.w < 128 && actwk[0].mspeed.w >= -127) return; /* Line 1177, Address: 0x100b03c */
  if ((swdata.b.h & 12) || (swdata.b.h & 2) == 0) return; /* Line 1178, Address: 0x100b074 */
  ballset(); /* Line 1179, Address: 0x100b0ac */
} /* Line 1180, Address: 0x100b0b4 */


void ballset() {
  if ((actwk[0].cddat & 4) == 0) { /* Line 1184, Address: 0x100b0d0 */

    actwk[0].cddat |= 4; /* Line 1186, Address: 0x100b0e8 */
    if (chibi_flag != 0) { /* Line 1187, Address: 0x100b0fc */
      actwk[0].sprvsize = 8; /* Line 1188, Address: 0x100b110 */
      actwk[0].sprhs = 5; /* Line 1189, Address: 0x100b11c */
      actwk[0].yposi.w.h += 2; /* Line 1190, Address: 0x100b128 */
    } /* Line 1191, Address: 0x100b13c */
    else {
      actwk[0].sprvsize = 14; /* Line 1193, Address: 0x100b144 */
      actwk[0].sprhs = 7; /* Line 1194, Address: 0x100b150 */
      actwk[0].yposi.w.h += 5; /* Line 1195, Address: 0x100b15c */
    }
  }

  actwk[0].mstno.b.h = 2; /* Line 1199, Address: 0x100b170 */
  if (actwk[0].mspeed.w >= 0 && actwk[0].mspeed.w >= 512) /* Line 1200, Address: 0x100b17c */
    actwk[0].mspeed.w = 512; /* Line 1201, Address: 0x100b1b0 */
} /* Line 1202, Address: 0x100b1bc */




unsigned char jumpchk() { /* Line 1207, Address: 0x100b1d0 */
  char cal_char;
  unsigned char cal_direc, ret_flag;
  int cal_jump, sin_data, cos_data;
  short sin_tmp, cos_tmp;

  cal_direc = 0; /* Line 1213, Address: 0x100b1e4 */
  cal_jump = 0; /* Line 1214, Address: 0x100b1e8 */
  ret_flag = 0; /* Line 1215, Address: 0x100b1ec */

  if (actwk[0].actfree[0] != 0) return ret_flag; /* Line 1217, Address: 0x100b1f0 */
  if ((swdata.b.h & 3) && actwk[0].mspeed.w == 0) return ret_flag; /* Line 1218, Address: 0x100b210 */

  if ((swdata.b.l & 112) == 0) return ret_flag; /* Line 1220, Address: 0x100b24c */
  if ((actwk[0].cddat & 8) && frip_spd(&cal_jump, &cal_direc) == 0) goto label1; /* Line 1221, Address: 0x100b270 */


  cal_direc = actwk[0].direc.b.h + 128; /* Line 1224, Address: 0x100b2a4 */
  cal_char = cal_direc; /* Line 1225, Address: 0x100b2c0 */
  if (dircol2(&actwk[0], &cal_char) < 6) return ret_flag; /* Line 1226, Address: 0x100b2c8 */
  cal_jump = 1664; /* Line 1227, Address: 0x100b2fc */
  if (actwk[0].cddat & 64) cal_jump = 896; /* Line 1228, Address: 0x100b304 */
  cal_direc = actwk[0].direc.b.h + -64; /* Line 1229, Address: 0x100b324 */

label1:
  sinset(cal_direc, &sin_tmp, &cos_tmp); /* Line 1232, Address: 0x100b340 */
  sin_data = sin_tmp; /* Line 1233, Address: 0x100b354 */
  cos_data = cos_tmp; /* Line 1234, Address: 0x100b360 */

  cos_data *= cal_jump; /* Line 1236, Address: 0x100b36c */
  cos_data = cos_data >> 8; /* Line 1237, Address: 0x100b374 */
  actwk[0].xspeed.w += cos_data; /* Line 1238, Address: 0x100b378 */
  sin_data *= cal_jump; /* Line 1239, Address: 0x100b394 */
  sin_data = sin_data >> 8; /* Line 1240, Address: 0x100b39c */
  actwk[0].yspeed.w += sin_data; /* Line 1241, Address: 0x100b3a0 */
  actwk[0].cddat |= 2; /* Line 1242, Address: 0x100b3bc */
  actwk[0].cddat &= 223; /* Line 1243, Address: 0x100b3d0 */
  ret_flag = 255; /* Line 1244, Address: 0x100b3e4 */

  actwk[0].actfree[18] = 1; /* Line 1246, Address: 0x100b3ec */
  actwk[0].actfree[14] = 0; /* Line 1247, Address: 0x100b3f8 */
  scr_cnt = 0; /* Line 1249, Address: 0x100b400 */
  soundset(146); /* Line 1250, Address: 0x100b408 */

  if (actwk[0].cddat & 4) { /* Line 1252, Address: 0x100b414 */
    actwk[0].cddat |= 16; /* Line 1253, Address: 0x100b42c */
    return ret_flag; /* Line 1254, Address: 0x100b440 */
  }

  if (chibi_flag != 0) { /* Line 1256, Address: 0x100b44c */
    actwk[0].sprvsize = 8; /* Line 1257, Address: 0x100b460 */
    actwk[0].sprhs = 5; /* Line 1258, Address: 0x100b46c */
    actwk[0].yposi.w.h += 2; /* Line 1259, Address: 0x100b478 */
  } else { /* Line 1260, Address: 0x100b48c */
    actwk[0].sprvsize = 14; /* Line 1261, Address: 0x100b494 */
    actwk[0].sprhs = 7; /* Line 1262, Address: 0x100b4a0 */
    actwk[0].yposi.w.h += 5; /* Line 1263, Address: 0x100b4ac */
  }
  actwk[0].cddat |= 4; /* Line 1265, Address: 0x100b4c0 */
  actwk[0].mstno.b.h = 2; /* Line 1266, Address: 0x100b4d4 */
  return ret_flag; /* Line 1267, Address: 0x100b4e0 */
} /* Line 1268, Address: 0x100b4e4 */


void jumpchk2() { /* Line 1271, Address: 0x100b500 */
  short cal_speed;

  if (actwk[0].actfree[2] != 0) { /* Line 1274, Address: 0x100b508 */
    cal_speed = -1024; /* Line 1275, Address: 0x100b51c */
    if (actwk[0].cddat & 64) cal_speed = -512; /* Line 1276, Address: 0x100b528 */
    if (!(cal_speed > actwk[0].yspeed.w)) return; /* Line 1277, Address: 0x100b54c */
    if (swdata.b.h & 112) return; /* Line 1278, Address: 0x100b570 */
    actwk[0].actfree[0] = 0; /* Line 1279, Address: 0x100b588 */
    actwk[0].yspeed.w = cal_speed; /* Line 1280, Address: 0x100b590 */


    return; /* Line 1283, Address: 0x100b598 */
  }
  if (actwk[0].yspeed.w < -4032) actwk[0].yspeed.w = -4032; /* Line 1285, Address: 0x100b5a0 */

} /* Line 1287, Address: 0x100b5c8 */




void keispd() { /* Line 1292, Address: 0x100b5e0 */
  unsigned char cal_direc;
  int sin_data;
  short sin_tmp, cos_tmp;

  if (actwk[0].actfree[0] != 0) return; /* Line 1297, Address: 0x100b5f0 */
  cal_direc = actwk[0].direc.b.h + 96; /* Line 1298, Address: 0x100b604 */
  if (cal_direc >= 192) return; /* Line 1299, Address: 0x100b620 */
  cal_direc = actwk[0].direc.b.h; /* Line 1300, Address: 0x100b630 */

  sinset(actwk[0].direc.b.h, &sin_tmp, &cos_tmp); /* Line 1302, Address: 0x100b63c */
  sin_data = sin_tmp; /* Line 1303, Address: 0x100b658 */

  sin_data *= 32; /* Line 1305, Address: 0x100b664 */
  sin_data = sin_data >> 8; /* Line 1306, Address: 0x100b668 */
  if (actwk[0].mspeed.w == 0) return; /* Line 1307, Address: 0x100b66c */
  if (actwk[0].mspeed.w > 0) { /* Line 1308, Address: 0x100b684 */
    if (sin_data != 0) actwk[0].mspeed.w += sin_data;; /* Line 1309, Address: 0x100b69c */
  } else { /* Line 1310, Address: 0x100b6c0 */
    actwk[0].mspeed.w += sin_data; /* Line 1311, Address: 0x100b6c8 */
  }
} /* Line 1313, Address: 0x100b6e4 */


void keispd2() { /* Line 1316, Address: 0x100b700 */
  unsigned char cal_direc;
  int sin_data;
  short sin_tmp, cos_tmp;

  if (actwk[0].actfree[0] != 0) return; /* Line 1321, Address: 0x100b710 */
  cal_direc = actwk[0].direc.b.h + 96; /* Line 1322, Address: 0x100b724 */
  if (cal_direc >= 192) return; /* Line 1323, Address: 0x100b740 */
  cal_direc = actwk[0].direc.b.h; /* Line 1324, Address: 0x100b750 */

  sinset(actwk[0].direc.b.h, &sin_tmp, &cos_tmp); /* Line 1326, Address: 0x100b75c */
  sin_data = sin_tmp; /* Line 1327, Address: 0x100b778 */

  sin_data *= 80; /* Line 1329, Address: 0x100b784 */
  sin_data = sin_data >> 8; /* Line 1330, Address: 0x100b790 */
  if (actwk[0].mspeed.w >= 0) { /* Line 1331, Address: 0x100b794 */
    if (sin_data < 0) sin_data /= 4; /* Line 1332, Address: 0x100b7ac */
    actwk[0].mspeed.w += sin_data; /* Line 1333, Address: 0x100b7d0 */
  } else { /* Line 1334, Address: 0x100b7ec */
    if (sin_data >= 0) sin_data /= 4; /* Line 1335, Address: 0x100b7f4 */
    actwk[0].mspeed.w += sin_data; /* Line 1336, Address: 0x100b818 */
  }
} /* Line 1338, Address: 0x100b834 */




void fallchk() {
  if (actwk[0].actfree[14] != 0) return; /* Line 1344, Address: 0x100b850 */
    if ((actwk[0].direc.b.h + 32 & 192) == 0) return; /* Line 1347, Address: 0x100b878 */
  if (((unsigned short*)actwk)[33] == 0) { /* Line 1345, Address: 0x100b864 */
    if (actwk[0].mspeed.w < 641 || actwk[0].mspeed.w >= -640) { /* Line 1348, Address: 0x100b898 */
      return; /* Line 1349, Address: 0x100b8d0 */
    }
    actwk[0].mspeed.w = 0; /* Line 1350, Address: 0x100b8d8 */
    actwk[0].cddat |= 2; /* Line 1351, Address: 0x100b8e0 */
    ((short*)actwk)[33] = 30; /* Line 1352, Address: 0x100b8f4 */
  } else { /* Line 1353, Address: 0x100b900 */
    --((unsigned short*)actwk)[33]; /* Line 1354, Address: 0x100b908 */
  }
} /* Line 1356, Address: 0x100b91c */




void direcchg() { /* Line 1361, Address: 0x100b930 */
  char cal_direc;

  if ((actwk[0].actfree[2] & 2) != 0) return; /* Line 1364, Address: 0x100b938 */
  if ((cal_direc = actwk[0].direc.b.h) == 0) return; /* Line 1365, Address: 0x100b950 */
  if (cal_direc < 0) { /* Line 1366, Address: 0x100b970 */
    if ((cal_direc += 2) > 0) cal_direc = 0; /* Line 1367, Address: 0x100b980 */
  } else { /* Line 1368, Address: 0x100b9a8 */
    if ((cal_direc -= 2) < 0) cal_direc = 0; /* Line 1369, Address: 0x100b9b0 */
  }
  actwk[0].direc.b.h = cal_direc; /* Line 1371, Address: 0x100b9d8 */
} /* Line 1372, Address: 0x100b9e0 */







void jumpcolchk() { /* Line 1380, Address: 0x100b9f0 */
  short chk_d0, chk_d1, tmp_d3;
  char chk_d2, chk_d3;
  unsigned char cal_direc;

  cal_direc = atan_sonic(actwk[0].xspeed.w, actwk[0].yspeed.w); /* Line 1385, Address: 0x100ba04 */
  debugwork.b.b1 = cal_direc; /* Line 1386, Address: 0x100ba24 */
  cal_direc -= 32; /* Line 1387, Address: 0x100ba2c */
  debugwork.b.b2 = cal_direc; /* Line 1388, Address: 0x100ba34 */
  cal_direc &= 192; /* Line 1389, Address: 0x100ba3c */
  debugwork.b.b3 = cal_direc; /* Line 1390, Address: 0x100ba44 */
  switch (cal_direc) { /* Line 1391, Address: 0x100ba4c */

    case 0:
      chk_d1 = dircol_l2(&actwk[0]); /* Line 1394, Address: 0x100ba84 */
      if (chk_d1 < 0) { /* Line 1395, Address: 0x100ba98 */
        actwk[0].xposi.w.h -= chk_d1; /* Line 1396, Address: 0x100baac */
        actwk[0].xspeed.w = 0; /* Line 1397, Address: 0x100bac4 */
      }
      chk_d1 = dircol_r2(&actwk[0]); /* Line 1399, Address: 0x100bacc */
      if (chk_d1 < 0) { /* Line 1400, Address: 0x100bae0 */
        actwk[0].xposi.w.h += chk_d1; /* Line 1401, Address: 0x100baf4 */
        actwk[0].xspeed.w = 0; /* Line 1402, Address: 0x100bb0c */
      }
      dircol_d(&actwk[0], &chk_d0, &chk_d1, &tmp_d3); /* Line 1404, Address: 0x100bb14 */
      chk_d3 = tmp_d3; /* Line 1405, Address: 0x100bb30 */
      debugwork.b.b4 = chk_d1; /* Line 1406, Address: 0x100bb44 */
      if (chk_d1 >= 0) return; /* Line 1407, Address: 0x100bb54 */
      chk_d2 = -(actwk[0].yspeed.b.h + 8); /* Line 1408, Address: 0x100bb68 */
      if ((char)chk_d1 < chk_d2 && (char)chk_d0 < chk_d2) return; /* Line 1409, Address: 0x100bb90 */

      actwk[0].yposi.w.h += chk_d1; /* Line 1411, Address: 0x100bbe0 */
      actwk[0].direc.b.h = chk_d3; /* Line 1412, Address: 0x100bbf8 */
      jumpcolsub(); /* Line 1413, Address: 0x100bc00 */
      actwk[0].mstno.b.h = 0; /* Line 1414, Address: 0x100bc08 */
      if (chk_d3 + 32 & 64) { /* Line 1415, Address: 0x100bc10 */

        actwk[0].xspeed.w = 0; /* Line 1417, Address: 0x100bc28 */
        if (actwk[0].yspeed.w >= 4033) actwk[0].yspeed.w = 4032; /* Line 1418, Address: 0x100bc30 */
      } else { /* Line 1419, Address: 0x100bc58 */
        if ((chk_d3 + 16 & 32) == 0) { /* Line 1420, Address: 0x100bc60 */

          actwk[0].yspeed.w = 0; /* Line 1422, Address: 0x100bc78 */
          actwk[0].mspeed.w = actwk[0].xspeed.w; /* Line 1423, Address: 0x100bc80 */
          return; /* Line 1424, Address: 0x100bc90 */
        }
        actwk[0].yspeed.w /= 2; /* Line 1426, Address: 0x100bc98 */
      }

      actwk[0].mspeed.w = actwk[0].yspeed.w; /* Line 1429, Address: 0x100bcc0 */
      if (chk_d3 < 0) actwk[0].mspeed.w = -actwk[0].mspeed.w; /* Line 1430, Address: 0x100bcd0 */
      break; /* Line 1431, Address: 0x100bd04 */


    case 64:
      chk_d1 = dircol_l2(&actwk[0]); /* Line 1435, Address: 0x100bd0c */
      if (chk_d1 < 0) { /* Line 1436, Address: 0x100bd20 */
        actwk[0].xposi.w.h -= chk_d1; /* Line 1437, Address: 0x100bd34 */
        actwk[0].xspeed.w = 0; /* Line 1438, Address: 0x100bd4c */
        actwk[0].mspeed.w = actwk[0].yspeed.w; /* Line 1439, Address: 0x100bd54 */
        return; /* Line 1440, Address: 0x100bd64 */
      }
      dircol_u(&actwk[0], &chk_d0, &chk_d1, &tmp_d3); /* Line 1442, Address: 0x100bd6c */
      if (chk_d1 < 0) { /* Line 1443, Address: 0x100bd88 */
        actwk[0].yposi.w.h -= chk_d1; /* Line 1444, Address: 0x100bd9c */
        if (actwk[0].yspeed.w < 0) actwk[0].yspeed.w = 0; /* Line 1445, Address: 0x100bdb4 */
        return; /* Line 1446, Address: 0x100bdd4 */
      }

      if (actwk[0].yspeed.w < 0) return; /* Line 1449, Address: 0x100bddc */
      dircol_d(&actwk[0], &chk_d0, &chk_d1, &tmp_d3); /* Line 1450, Address: 0x100bdf4 */
      chk_d3 = tmp_d3; /* Line 1451, Address: 0x100be10 */
      if (chk_d1 >= 0) return; /* Line 1452, Address: 0x100be24 */
      actwk[0].yposi.w.h += chk_d1; /* Line 1453, Address: 0x100be38 */
      actwk[0].direc.b.h = chk_d3; /* Line 1454, Address: 0x100be50 */
      jumpcolsub(); /* Line 1455, Address: 0x100be58 */
      actwk[0].mstno.b.h = 0; /* Line 1456, Address: 0x100be60 */
      actwk[0].yspeed.w = 0; /* Line 1457, Address: 0x100be68 */
      actwk[0].mspeed.w = actwk[0].xspeed.w; /* Line 1458, Address: 0x100be70 */
      break; /* Line 1459, Address: 0x100be80 */


    case 128:
      chk_d1 = dircol_l2(&actwk[0]); /* Line 1463, Address: 0x100be88 */
      if (chk_d1 < 0) { /* Line 1464, Address: 0x100be9c */
        actwk[0].xposi.w.h -= chk_d1; /* Line 1465, Address: 0x100beb0 */
        actwk[0].xspeed.w = 0; /* Line 1466, Address: 0x100bec8 */
      }
      chk_d1 = dircol_r2(&actwk[0]); /* Line 1468, Address: 0x100bed0 */
      if (chk_d1 < 0) { /* Line 1469, Address: 0x100bee4 */
        actwk[0].xposi.w.h += chk_d1; /* Line 1470, Address: 0x100bef8 */
        actwk[0].mspeed.w = 0; /* Line 1471, Address: 0x100bf10 */
      }

      dircol_u(&actwk[0], &chk_d0, &chk_d1, &tmp_d3); /* Line 1474, Address: 0x100bf18 */
      chk_d3 = tmp_d3; /* Line 1475, Address: 0x100bf34 */
      if (chk_d1 >= 0) return; /* Line 1476, Address: 0x100bf48 */
      actwk[0].yposi.w.h -= chk_d1; /* Line 1477, Address: 0x100bf5c */
      if ((chk_d3 + 32 & 64) == 0) { /* Line 1478, Address: 0x100bf74 */
        actwk[0].yspeed.w = 0; /* Line 1479, Address: 0x100bf8c */
        return; /* Line 1480, Address: 0x100bf94 */
      }
      actwk[0].direc.b.h = chk_d3; /* Line 1482, Address: 0x100bf9c */
      jumpcolsub0(); /* Line 1483, Address: 0x100bfa4 */
      actwk[0].mspeed.w = actwk[0].yspeed.w; /* Line 1484, Address: 0x100bfac */
      if (chk_d3 < 0) actwk[0].mspeed.w = -actwk[0].mspeed.w; /* Line 1485, Address: 0x100bfbc */
      break; /* Line 1486, Address: 0x100bff0 */


    case 192:
      chk_d1 = dircol_r2(&actwk[0]); /* Line 1490, Address: 0x100bff8 */
      if (chk_d1 < 0) { /* Line 1491, Address: 0x100c00c */
        actwk[0].xposi.w.h += chk_d1; /* Line 1492, Address: 0x100c020 */
        actwk[0].xspeed.w = 0; /* Line 1493, Address: 0x100c038 */
        actwk[0].mspeed.w = actwk[0].xspeed.w; /* Line 1494, Address: 0x100c040 */
        return; /* Line 1495, Address: 0x100c050 */
      }
      dircol_u(&actwk[0], &chk_d0, &chk_d1, &tmp_d3); /* Line 1497, Address: 0x100c058 */
      if (chk_d1 < 0) { /* Line 1498, Address: 0x100c074 */
        actwk[0].yposi.w.h -= chk_d1; /* Line 1499, Address: 0x100c088 */
        if (actwk[0].yspeed.w < 0) actwk[0].yspeed.w = 0; /* Line 1500, Address: 0x100c0a0 */
        return; /* Line 1501, Address: 0x100c0c0 */
      }

      if (actwk[0].yspeed.w < 0) return; /* Line 1504, Address: 0x100c0c8 */
      dircol_d(&actwk[0], &chk_d0, &chk_d1, &tmp_d3); /* Line 1505, Address: 0x100c0e0 */
      chk_d3 = tmp_d3; /* Line 1506, Address: 0x100c0fc */
      if (chk_d1 >= 0) return; /* Line 1507, Address: 0x100c110 */
      actwk[0].yposi.w.h += chk_d1; /* Line 1508, Address: 0x100c124 */
      actwk[0].direc.b.h = chk_d3; /* Line 1509, Address: 0x100c13c */
      jumpcolsub(); /* Line 1510, Address: 0x100c144 */
      actwk[0].mstno.b.h = 0; /* Line 1511, Address: 0x100c14c */
      actwk[0].yspeed.w = 0; /* Line 1512, Address: 0x100c154 */
      actwk[0].mspeed.w = actwk[0].xspeed.w; /* Line 1513, Address: 0x100c15c */
      break;
  }



} /* Line 1519, Address: 0x100c16c */


void jumpcolsub() { /* Line 1522, Address: 0x100c190 */


  actwk[0].cddat &= 205; /* Line 1525, Address: 0x100c198 */
  if (actwk[0].cddat & 4) { /* Line 1526, Address: 0x100c1ac */
    actwk[0].cddat &= 251; /* Line 1527, Address: 0x100c1c4 */
    if (chibi_flag != 0) { /* Line 1528, Address: 0x100c1d8 */
      actwk[0].sprvsize = 10; /* Line 1529, Address: 0x100c1ec */
      actwk[0].sprhs = 5; /* Line 1530, Address: 0x100c1f8 */
      actwk[0].yposi.w.h -= 2; /* Line 1531, Address: 0x100c204 */
    } else { /* Line 1532, Address: 0x100c218 */
      actwk[0].sprvsize = 19; /* Line 1533, Address: 0x100c220 */
      actwk[0].sprhs = 9; /* Line 1534, Address: 0x100c22c */
      actwk[0].yposi.w.h -= 5; /* Line 1535, Address: 0x100c238 */
    }
    actwk[0].mstno.b.h = 0; /* Line 1537, Address: 0x100c24c */
    soundset(171); /* Line 1538, Address: 0x100c254 */
    if (WaveClear != 0) WaveAllStop(), WaveClear = 0; /* Line 1539, Address: 0x100c260 */
  }

  actwk[0].actfree[18] = 0; /* Line 1542, Address: 0x100c288 */
  emyscorecnt = 0; /* Line 1543, Address: 0x100c290 */
} /* Line 1544, Address: 0x100c298 */


void jumpcolsub0() {
  actwk[0].cddat &= 205; /* Line 1548, Address: 0x100c2b0 */
  actwk[0].actfree[18] = 0; /* Line 1549, Address: 0x100c2c4 */
  emyscorecnt = 0; /* Line 1550, Address: 0x100c2cc */
} /* Line 1551, Address: 0x100c2d4 */



void play00damage() { /* Line 1555, Address: 0x100c2e0 */
  speedset2(&actwk[0]); /* Line 1556, Address: 0x100c2e8 */
  actwk[0].yspeed.w += 48; /* Line 1557, Address: 0x100c2f8 */
  if (actwk[0].cddat & 64) actwk[0].yspeed.w -= 32; /* Line 1558, Address: 0x100c30c */
  playsp(); /* Line 1559, Address: 0x100c338 */
  play00damage_sub(); /* Line 1560, Address: 0x100c340 */
  limitchk(); /* Line 1561, Address: 0x100c348 */
  playposiwkset(); /* Line 1562, Address: 0x100c350 */
  patchgmain(); /* Line 1563, Address: 0x100c358 */
  actionsub(&actwk[0]); /* Line 1564, Address: 0x100c360 */
} /* Line 1565, Address: 0x100c370 */


void play00damage_sub() { /* Line 1568, Address: 0x100c380 */
  if (scralim_down + 224 < actwk[0].yposi.w.h) { /* Line 1569, Address: 0x100c388 */
    playdieset(&actwk[0]); /* Line 1570, Address: 0x100c3b8 */
    return; /* Line 1571, Address: 0x100c3c8 */
  }
  jumpcolchk(); /* Line 1573, Address: 0x100c3d0 */
  if (actwk[0].cddat & 2) return; /* Line 1574, Address: 0x100c3d8 */
  actwk[0].yspeed.w = actwk[0].xspeed.w = actwk[0].mspeed.w = 0; /* Line 1575, Address: 0x100c3f0 */
  actwk[0].mstno.b.h = 0; /* Line 1576, Address: 0x100c418 */
  actwk[0].r_no0 -= 2; /* Line 1577, Address: 0x100c420 */
  ((short*)actwk)[26] = 120; /* Line 1578, Address: 0x100c434 */
} /* Line 1579, Address: 0x100c440 */



void play00die() { /* Line 1583, Address: 0x100c450 */
  play00die_sub(); /* Line 1584, Address: 0x100c458 */
  speedset(&actwk[0]); /* Line 1585, Address: 0x100c460 */
  playposiwkset(); /* Line 1586, Address: 0x100c470 */
  patchgmain(); /* Line 1587, Address: 0x100c478 */
  actionsub(&actwk[0]); /* Line 1588, Address: 0x100c480 */
} /* Line 1589, Address: 0x100c490 */


void play00die_sub() { /* Line 1592, Address: 0x100c4a0 */
  act_info* new_actwk;

  if (scralim_down + 256 >= actwk[0].yposi.w.h) return; /* Line 1595, Address: 0x100c4a8 */
  actwk[0].yspeed.w = -56; /* Line 1596, Address: 0x100c4d8 */
  actwk[0].r_no0 += 2; /* Line 1597, Address: 0x100c4e4 */
  pltime_f = 0; /* Line 1598, Address: 0x100c4f8 */
  ++pl_suu_f; /* Line 1599, Address: 0x100c500 */
  if ((char)--pl_suu < 0) pl_suu = 0; /* Line 1600, Address: 0x100c514 */

  if (actwk[0].mstno.b.h == 43 || ta_flag == 0) { /* Line 1602, Address: 0x100c54c */
    actwkchk(&new_actwk); /* Line 1603, Address: 0x100c57c */
    new_actwk->actno = 59; /* Line 1604, Address: 0x100c588 */
    ((short*)actwk)[31] = 480; /* Line 1605, Address: 0x100c594 */
    if (pl_suu == 0) return; /* Line 1606, Address: 0x100c5a0 */
  } else { /* Line 1607, Address: 0x100c5b4 */
    pl_suu = 0; /* Line 1608, Address: 0x100c5bc */
  }
  actwk[0].actfree[16] = 60; /* Line 1610, Address: 0x100c5c4 */
} /* Line 1611, Address: 0x100c5d0 */



void play00erase() { /* Line 1615, Address: 0x100c5e0 */
  if (((unsigned short*)actwk)[31] == 0) return; /* Line 1616, Address: 0x100c5e8 */
  --actwk[0].actfree[16]; /* Line 1617, Address: 0x100c5fc */
  if (((unsigned short*)actwk)[31] != 0) return; /* Line 1618, Address: 0x100c610 */
  gameflag.w = 1; /* Line 1619, Address: 0x100c624 */




  flagwkclr(); /* Line 1624, Address: 0x100c630 */
  flowercnt[0] = flowercnt[1] = flowercnt[2] = tv_flag = 0; /* Line 1625, Address: 0x100c638 */
  if (markerno == 0 && time_flag == 1) play_start &= 253; /* Line 1626, Address: 0x100c664 */


  if (pl_suu != 0) { /* Line 1629, Address: 0x100c6a4 */
    if (time_flag == 1) { /* Line 1630, Address: 0x100c6b8 */
      if (markerno != 0) plflag = 1; /* Line 1631, Address: 0x100c6d0 */
    } else { /* Line 1632, Address: 0x100c6f0 */
      plflag = 0; /* Line 1633, Address: 0x100c6f8 */
    }
  }
  sub_sync(14); /* Line 1636, Address: 0x100c700 */

} /* Line 1638, Address: 0x100c70c */








void loopchk() { /* Line 1647, Address: 0x100c720 */
  short index;
  unsigned char mapdata;

  if (stageno.b.h != 3 && stageno.b.h != 5 && stageno.b.h != 2 && stageno.b.h != 0) return; /* Line 1651, Address: 0x100c730 */


  index = (actwk[0].yposi.w.h >> 1 & 896) + ((short)actwk[0].xposi.b.b1 & 127); /* Line 1654, Address: 0x100c79c */

  mapdata = mapwka[index / 128][index & 63]; /* Line 1656, Address: 0x100c7e4 */
  if (mapdata == ballmapno) { /* Line 1657, Address: 0x100c82c */
    if (stageno.b.h != 0 || (actwk[0].yposi.w.h & 255) >= 144) { /* Line 1658, Address: 0x100c844 */
      ballset(); return; /* Line 1659, Address: 0x100c87c */
    }
  }
  else {
    if (mapdata == ballmapno2) { ballset(); return; } /* Line 1663, Address: 0x100c88c */
  }

  if (mapdata != loopmapno && mapdata != loopmapno2) { /* Line 1666, Address: 0x100c8b4 */
    actwk[0].actflg &= 191; /* Line 1667, Address: 0x100c8e4 */
    return; /* Line 1668, Address: 0x100c8f8 */
  }
  if (mapdata == loopmapno2) { /* Line 1670, Address: 0x100c900 */

    if (stageno.b.h == 5) { st7_x(); return; } /* Line 1672, Address: 0x100c918 */
    if (actwk[0].cddat & 2) { /* Line 1673, Address: 0x100c944 */
      actwk[0].actflg &= 191; /* Line 1674, Address: 0x100c95c */
      return; /* Line 1675, Address: 0x100c970 */
    }
  }

  if (actwk[0].xposi.b.b2 < 44) { /* Line 1679, Address: 0x100c978 */
    actwk[0].actflg &= 191; /* Line 1680, Address: 0x100c994 */
    return; /* Line 1681, Address: 0x100c9a8 */
  }

  if (actwk[0].xposi.b.b4 >= 224) { /* Line 1684, Address: 0x100c9b0 */
    actwk[0].actflg |= 64; /* Line 1685, Address: 0x100c9cc */
    return; /* Line 1686, Address: 0x100c9e0 */
  }

  if ((actwk[0].actflg & 64) == 0) { /* Line 1689, Address: 0x100c9e8 */
    if (actwk[0].direc.b.h != 0 && actwk[0].direc.b.h < 129) { /* Line 1690, Address: 0x100ca00 */
      actwk[0].actflg |= 64; /* Line 1691, Address: 0x100ca34 */
    return; /* Line 1692, Address: 0x100ca48 */
  }
  if (actwk[0].direc.b.h < 129) return; /* Line 1695, Address: 0x100ca50 */

  actwk[0].actflg &= 191; /* Line 1696, Address: 0x100ca6c */
} /* Line 1697, Address: 0x100ca80 */



void st7_x() { /* Line 1701, Address: 0x100caa0 */
  short y_position;


  if (actwk[0].yspeed.w >= 0) { /* Line 1705, Address: 0x100caa8 */
    y_position = actwk[0].yposi.w.h; /* Line 1706, Address: 0x100cac0 */
    if ((actwk[0].xposi.w.h & 255) < 128) { /* Line 1707, Address: 0x100cae4 */

      if (y_position < 56) actwk[0].actflg |= 64; /* Line 1709, Address: 0x100cb04 */
      else if (y_position >= 128) actwk[0].actflg &= 191; /* Line 1710, Address: 0x100cb34 */
    } /* Line 1711, Address: 0x100cb5c */
    else if (y_position < 56) actwk[0].actflg &= 191; /* Line 1712, Address: 0x100cb64 */
    else if (y_position >= 128) actwk[0].actflg |= 64; /* Line 1713, Address: 0x100cb94 */
  }
} /* Line 1715, Address: 0x100cbbc */





void patchgmain() { /* Line 1721, Address: 0x100cbd0 */
  char pat_index;
  unsigned char* pat_pointer;

  if (actwk[0].mstno.b.h != actwk[0].mstno.b.l) { /* Line 1725, Address: 0x100cbe0 */
    actwk[0].mstno.b.l = actwk[0].mstno.b.h; /* Line 1726, Address: 0x100cc08 */
    actwk[0].patcnt = actwk[0].pattim = 0; /* Line 1727, Address: 0x100cc18 */
  }

  pat_index = little_patchg(actwk[0].mstno.b.h); /* Line 1730, Address: 0x100cc2c */
  pat_pointer = playchg[pat_index]; /* Line 1731, Address: 0x100cc44 */
  if (*pat_pointer >= 128) { playrunchg(*pat_pointer); return; } /* Line 1732, Address: 0x100cc60 */

  actwk[0].actflg = (actwk[0].actflg & 252) | (actwk[0].cddat & 1); /* Line 1734, Address: 0x100cc88 */
  if (--actwk[0].pattim >= 0) return; /* Line 1735, Address: 0x100ccb8 */
  actwk[0].pattim = *pat_pointer; /* Line 1736, Address: 0x100cce8 */
  patchgmain2(pat_pointer); /* Line 1737, Address: 0x100ccf4 */
} /* Line 1738, Address: 0x100cd00 */


void patchgmain2(unsigned char* pat_pointer) { /* Line 1741, Address: 0x100cd20 */
  unsigned char pat_no;

  if ((pat_no = pat_pointer[actwk[0].patcnt + 1]) < 253) { /* Line 1744, Address: 0x100cd2c */
    actwk[0].patno = pat_no; /* Line 1745, Address: 0x100cd5c */
    ++actwk[0].patcnt; /* Line 1746, Address: 0x100cd64 */
  } /* Line 1747, Address: 0x100cd78 */
  else {

    switch (pat_no) { /* Line 1750, Address: 0x100cd80 */
      case 255:
        actwk[0].patcnt = 1; /* Line 1752, Address: 0x100cdb0 */
        actwk[0].patno = *pat_pointer; /* Line 1753, Address: 0x100cdbc */
        break; /* Line 1754, Address: 0x100cdcc */
      case 254:
        actwk[0].patno = pat_pointer[actwk[0].patcnt + 1 /* Line 1756, Address: 0x100cdd4 */
                       - pat_pointer[actwk[0].patcnt + 2]];
        actwk[0].patcnt = actwk[0].patcnt /* Line 1758, Address: 0x100ce1c */
                        - (pat_pointer[actwk[0].patcnt + 2] - 1);
        break; /* Line 1760, Address: 0x100ce5c */
      case 253:
        actwk[0].mstno.b.h = pat_pointer[actwk[0].patcnt + 2]; /* Line 1762, Address: 0x100ce64 */
        break;
    }
  }


} /* Line 1768, Address: 0x100ce88 */



void playrunchg(unsigned char pat_no) {  /* Line 1772, Address: 0x100cea0 */
  unsigned char direction, cal_data, chara_data;
  unsigned char* pat_pointer;
  short cal_speed;

  if ((char)--actwk[0].pattim >= 0) return; /* Line 1777, Address: 0x100cec0 */
  if (pat_no != 255) { playrunchg2(pat_no); return; } /* Line 1778, Address: 0x100cef0 */
  if (chibi_flag != 0) { little_runchg(); return; } /* Line 1779, Address: 0x100cf18 */

  cal_data = 0; /* Line 1781, Address: 0x100cf3c */
  direction = actwk[0].direc.b.h; /* Line 1782, Address: 0x100cf40 */
  chara_data = actwk[0].cddat & 1; /* Line 1783, Address: 0x100cf4c */
  if (chara_data == 0) direction = 255 - direction; /* Line 1784, Address: 0x100cf64 */
  if ((actwk[0].actfree[2] & 2) == 0) direction += 16; /* Line 1785, Address: 0x100cf84 */
  else direction += 8; /* Line 1786, Address: 0x100cfac */
  if (direction < 0) cal_data = 3; /* Line 1787, Address: 0x100cfb4 */

  actwk[0].actflg &= 252; /* Line 1789, Address: 0x100cfd4 */
  chara_data ^= cal_data; /* Line 1790, Address: 0x100cfe8 */
  actwk[0].actflg |= chara_data; /* Line 1791, Address: 0x100cff0 */
  if ((actwk[0].cddat & 32) == 0) { playrunchg3(253); return; } /* Line 1792, Address: 0x100d004 */

  if ((cal_speed = actwk[0].mspeed.w) < 0) cal_speed = -cal_speed; /* Line 1794, Address: 0x100d030 */

  if (actwk[0].actfree[2] & 2) { /* Line 1796, Address: 0x100d06c */
    direction >>= 4, direction &= 15; /* Line 1797, Address: 0x100d084 */
    direction *= 2; /* Line 1798, Address: 0x100d094 */
    direction &= 14; /* Line 1799, Address: 0x100d09c */
    pat_pointer = plchg53; /* Line 1800, Address: 0x100d0a4 */
  } else { /* Line 1801, Address: 0x100d0ac */
    direction >>= 4; /* Line 1802, Address: 0x100d0b4 */
    direction &= 6; /* Line 1803, Address: 0x100d0bc */
    if (cal_speed >= 2560) pat_pointer = plchg49; /* Line 1804, Address: 0x100d0c4 */
    else if (cal_speed >= 1536) pat_pointer = plchg01; /* Line 1805, Address: 0x100d0e8 */
    else {
      pat_pointer = plchg00; /* Line 1807, Address: 0x100d10c */
      direction = direction + direction / 2; /* Line 1808, Address: 0x100d114 */
    }
  }

  cal_speed = 2048 - cal_speed; /* Line 1812, Address: 0x100d140 */
  if (cal_speed < 0) cal_speed = 0; /* Line 1813, Address: 0x100d160 */
  cal_speed /= 256; /* Line 1814, Address: 0x100d174 */
  actwk[0].pattim = cal_speed; /* Line 1815, Address: 0x100d194 */
  patchgmain2(pat_pointer); /* Line 1816, Address: 0x100d1a0 */
  actwk[0].xposi.w.h += actwk[0].xposi.w.h + direction * 2; /* Line 1817, Address: 0x100d1ac */
}  /* Line 1818, Address: 0x100d1d0 */


void playrunchg2(unsigned char pat_no) { /* Line 1821, Address: 0x100d200 */
  unsigned char direction;
  unsigned char* pat_pointer;
  short cal_speed;

  if (pat_no != 254) { playrunchg3(pat_no); return; } /* Line 1826, Address: 0x100d218 */
  if ((cal_speed = actwk[0].mspeed.w) < 0) cal_speed = -cal_speed; /* Line 1827, Address: 0x100d240 */
  if (chibi_flag != 0) pat_pointer = plchg35; /* Line 1828, Address: 0x100d27c */
  else {
    if (actwk[0].actfree[2] & 2) { /* Line 1830, Address: 0x100d2a0 */
      direction = actwk[0].direc.b.h; /* Line 1831, Address: 0x100d2b8 */
      direction = direction + 16 & 192; /* Line 1832, Address: 0x100d2c8 */
      if (direction != 0) pat_pointer = plchg54; /* Line 1833, Address: 0x100d2dc */
      else pat_pointer = plchg03; /* Line 1834, Address: 0x100d2f8 */
    } /* Line 1835, Address: 0x100d300 */
    else if (cal_speed < 1536) pat_pointer = plchg02; /* Line 1836, Address: 0x100d308 */
    else pat_pointer = plchg03; /* Line 1837, Address: 0x100d32c */
  }


  cal_speed = 1024 - cal_speed; /* Line 1841, Address: 0x100d334 */
  if (cal_speed < 0) cal_speed = 0; /* Line 1842, Address: 0x100d354 */
  cal_speed /= 256; /* Line 1843, Address: 0x100d368 */
  actwk[0].pattim = cal_speed; /* Line 1844, Address: 0x100d388 */
  actwk[0].actflg &= 252; /* Line 1845, Address: 0x100d394 */
  actwk[0].actflg |= actwk[0].cddat & 1; /* Line 1846, Address: 0x100d3a8 */
  patchgmain2(pat_pointer); /* Line 1847, Address: 0x100d3d0 */
} /* Line 1848, Address: 0x100d3dc */


void playrunchg3(unsigned char pat_no) { /* Line 1851, Address: 0x100d400 */
  unsigned char* pat_pointer;
  short cal_speed;

  if (pat_no != 253) { playetc_chg(); return; } /* Line 1855, Address: 0x100d414 */
  if ((cal_speed = actwk[0].mspeed.w) >= 0) cal_speed = -cal_speed; /* Line 1856, Address: 0x100d438 */
  cal_speed += 2048; /* Line 1857, Address: 0x100d474 */
  if (cal_speed < 0) cal_speed = 0; /* Line 1858, Address: 0x100d480 */
  actwk[0].pattim = cal_speed; /* Line 1860, Address: 0x100d4a0 */
  cal_speed >>= 6; /* Line 1859, Address: 0x100d494 */
  if (chibi_flag != 0) pat_pointer = plchg39; /* Line 1861, Address: 0x100d4ac */
  else pat_pointer = plchg04; /* Line 1862, Address: 0x100d4d0 */
  actwk[0].actflg &= 252; /* Line 1863, Address: 0x100d4d8 */
  actwk[0].actflg |= actwk[0].cddat & 1; /* Line 1864, Address: 0x100d4ec */
  patchgmain2(pat_pointer); /* Line 1865, Address: 0x100d514 */
} /* Line 1866, Address: 0x100d520 */


void playetc_chg() { /* Line 1869, Address: 0x100d540 */
  char pat_index;
  unsigned char* pat_pointer;

  pat_index = little_patchg(actwk[0].mstno.b.h); /* Line 1873, Address: 0x100d550 */
  pat_pointer = playchg[pat_index]; /* Line 1874, Address: 0x100d568 */

  actwk[0].patno = pat_pointer[actwk[0].patcnt + 1]; /* Line 1876, Address: 0x100d584 */
  actwk[0].pattim = 0; /* Line 1877, Address: 0x100d5a4 */
} /* Line 1878, Address: 0x100d5ac */



void little_runchg() { /* Line 1882, Address: 0x100d5d0 */
  unsigned char direction;
  unsigned char* pat_pointer;
  short cal_speed;

  direction = actwk[0].direc.b.h; /* Line 1887, Address: 0x100d5e4 */
  if ((actwk[0].cddat & 1) == 0) direction = 255 - direction; /* Line 1888, Address: 0x100d5f0 */
  direction += 16; /* Line 1889, Address: 0x100d61c */

  actwk[0].actflg &= 252; /* Line 1891, Address: 0x100d624 */
  actwk[0].actflg |= actwk[0].cddat & 1; /* Line 1892, Address: 0x100d638 */
  if ((direction += 48) >= 96) { /* Line 1893, Address: 0x100d660 */
    actwk[0].cddat |= 4; /* Line 1894, Address: 0x100d67c */
    actwk[0].sprvsize = 10; /* Line 1895, Address: 0x100d690 */
    actwk[0].sprhs = 5; /* Line 1896, Address: 0x100d69c */
    playrunchg2(254); /* Line 1897, Address: 0x100d6a8 */
    return; /* Line 1898, Address: 0x100d6b4 */
  }

  if ((cal_speed = actwk[0].mspeed.w) < 0) cal_speed = -cal_speed; /* Line 1901, Address: 0x100d6bc */
  if (cal_speed >= 1536) pat_pointer = plchg34; /* Line 1902, Address: 0x100d6f8 */
  else pat_pointer = plchg33; /* Line 1903, Address: 0x100d71c */
  cal_speed = 2048 - cal_speed; /* Line 1904, Address: 0x100d724 */
  if (cal_speed < 0) cal_speed = 0; /* Line 1905, Address: 0x100d744 */
  cal_speed /= 256; /* Line 1906, Address: 0x100d758 */
  actwk[0].pattim = cal_speed; /* Line 1907, Address: 0x100d778 */
  patchgmain2(pat_pointer); /* Line 1908, Address: 0x100d784 */
} /* Line 1909, Address: 0x100d790 */



char little_patchg(char pat_index) { /* Line 1913, Address: 0x100d7b0 */
  char tbl[80] = /* Line 1914, Address: 0x100d7b8 */
  {
    33, 24, 35, 35, 39, 31, 38, 40, 32,  9,
    10, 11, 12, 36, 14, 15, 40, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 37, 37, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 48, 44, 45, 46, 47,  0,  0,
     0,  0,  0,  0,  0,  0, 57,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0
  };

  if (chibi_flag != 0) return tbl[pat_index]; /* Line 1926, Address: 0x100d7ec */
  return pat_index; /* Line 1927, Address: 0x100d81c */
} /* Line 1928, Address: 0x100d820 */


























void playwrt() {} /* Line 1955, Address: 0x100d830 */





unsigned char frip_spd(int* cal_jump, unsigned char* cal_direc) { /* Line 1961, Address: 0x100d840 */
  short cal_x;
  char ride_no;

  ride_no = actwk[0].actfree[19]; /* Line 1965, Address: 0x100d858 */
  if (actwk[ride_no].actno != 30) return 255; /* Line 1966, Address: 0x100d868 */


  actwk[ride_no].mstno.b.h = 1; /* Line 1969, Address: 0x100d8a8 */
  *cal_direc = atan_sonic( /* Line 1970, Address: 0x100d8d0 */
    actwk[ride_no].xposi.w.h - actwk[0].xposi.w.h,
    actwk[ride_no].yposi.w.h + 24 - actwk[0].yposi.w.h
  );
  cal_x = (actwk[0].xposi.w.h - actwk[ride_no].xposi.w.h) + actwk[ride_no].sprhsize; /* Line 1974, Address: 0x100d978 */

  if ((actwk[ride_no].cddat & 1) == 0) cal_x = 64 - cal_x; /* Line 1976, Address: 0x100d9fc */

  *cal_jump = -((cal_x * 512) / 64) + -2560; /* Line 1978, Address: 0x100da50 */
  return 0; /* Line 1979, Address: 0x100da8c */
} /* Line 1980, Address: 0x100da90 */
