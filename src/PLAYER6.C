#include "EQU.H"
#include "PLAYER6.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "DIRCOL.H"
#include "DUMMY.H"
#include "EDIT.H"
#include "FCOL.H"
#include "ETC.H"

extern void sub_sync(short ReqNo); extern short playdamageset(sprite_status* pActwk, sprite_status* pColliAct); extern void soundset(short ReqNo); extern short pcol(sprite_status* pActwk); extern void da_set(); extern short playdieset(sprite_status* pActwk);

static unsigned int WaveClear;
static unsigned char Brake_Sw, Brake_Req;
extern spr_array* sncpat[];
extern unsigned char mapwka[8][64];
static short tate[2] = { 426, -1 }, yoko[2] = { 449, -1 }, naname[9] = { 444, 475, 468, 465, 419, 409, 408, 418, -1 };
extern void(*WaveAllStop)();
extern unsigned char *playchg[60], plchg00[8], plchg01[8], plchg49[8], plchg53[8], plchg03[8], plchg02[8], plchg54[8], plchg35[6], plchg04[8], plchg39[7], plchg33[6], plchg34[6];
unsigned char* playcg;
spr_array** playpat;

void bye_chk() { /* Line 23, Address: 0x1020870 */
  if (actwk[0].mstno.b.h != 5) { byecnt0.w = 0; return; } /* Line 24, Address: 0x1020878 */

  if (byecnt0.w == 0) byecnt0.b.l = 1; /* Line 26, Address: 0x10208a4 */


  if (byecnt0.w < 10800) return; /* Line 29, Address: 0x10208c8 */
  byecnt0.w = 0; /* Line 30, Address: 0x10208e4 */
  actwk[0].mstno.b.h = 43; /* Line 31, Address: 0x10208ec */
  actwk[0].sproffset |= 32768; /* Line 32, Address: 0x10208f8 */
  actwk[0].sprpri = 0; /* Line 33, Address: 0x102090c */
  pl_suu = 1; /* Line 34, Address: 0x1020914 */
  actwk[0].yspeed.w = -1280; /* Line 35, Address: 0x1020920 */
  actwk[0].xspeed.w = 256; /* Line 36, Address: 0x102092c */
  if (actwk[0].cddat & 1) actwk[0].xspeed.w = -actwk[0].xspeed.w; /* Line 37, Address: 0x1020938 */

  actwk[0].mspeed.w = 0; /* Line 39, Address: 0x1020974 */
  sub_sync(121); /* Line 40, Address: 0x102097c */
} /* Line 41, Address: 0x1020988 */





void play00(sprite_status* actionwk) { /* Line 47, Address: 0x10209a0 */
  unsigned char d0;

  Brake_Req = 0; /* Line 50, Address: 0x10209b0 */

  if (actwk[0].actno != 32) return; /* Line 52, Address: 0x10209b8 */

  if (ta_flag == 0 && editmode.b.h != 0) { edit(&actwk[0]); return; } /* Line 54, Address: 0x10209cc */

  d0 = actwk[0].actfree[0]; /* Line 56, Address: 0x1020a10 */
  if (d0 != 0) /* Line 57, Address: 0x1020a1c */
    ++d0; /* Line 58, Address: 0x1020a28 */
  if (actwk[0].cddat & 4) { /* Line 59, Address: 0x1020a30 */
    if (d0 >= 45) d0 = 45; /* Line 60, Address: 0x1020a48 */
  } /* Line 61, Address: 0x1020a60 */
  else if (d0 >= 30) d0 = 30; /* Line 62, Address: 0x1020a68 */


  actwk[0].actfree[0] = d0; /* Line 65, Address: 0x1020a80 */



  switch (actwk[0].r_no0) { /* Line 69, Address: 0x1020a88 */
    case 0:
      play00init(); /* Line 71, Address: 0x1020ad4 */
      break; /* Line 72, Address: 0x1020adc */
    case 2:
      play00move(); /* Line 74, Address: 0x1020ae4 */
      break; /* Line 75, Address: 0x1020aec */
    case 4:
      play00damage(); /* Line 77, Address: 0x1020af4 */
      break; /* Line 78, Address: 0x1020afc */
    case 6:
      play00die(); /* Line 80, Address: 0x1020b04 */
      break; /* Line 81, Address: 0x1020b0c */
    case 8:
      play00erase(); /* Line 83, Address: 0x1020b14 */
      break;
  }


  actwk[0].patbase = sncpat; /* Line 88, Address: 0x1020b1c */

  if (Brake_Req == 0) Brake_Sw = 0; /* Line 90, Address: 0x1020b2c */
} /* Line 91, Address: 0x1020b48 */






void muteki_set() {
  if (actwk[12].actno != 0) return; /* Line 99, Address: 0x1020b60 */
  plpower_a = 1; /* Line 100, Address: 0x1020b74 */
  actwk[12].actno = actwk[13].actno = actwk[14].actno = actwk[15].actno = 3; /* Line 101, Address: 0x1020b80 */

  actwk[12].mstno.b.h = 5; /* Line 103, Address: 0x1020bb0 */
  actwk[13].mstno.b.h = 6; /* Line 104, Address: 0x1020bbc */
  actwk[14].mstno.b.h = 7; /* Line 105, Address: 0x1020bc8 */
  actwk[15].mstno.b.h = 8; /* Line 106, Address: 0x1020bd4 */

} /* Line 108, Address: 0x1020be0 */









void test_mapwrt() {} /* Line 118, Address: 0x1020bf0 */





void play00init() {
  actwk[0].r_no0 += 2; /* Line 125, Address: 0x1020c00 */
  actwk[0].sprvsize = 19; /* Line 126, Address: 0x1020c14 */
  actwk[0].sprhs = 9; /* Line 127, Address: 0x1020c20 */
  if (chibi_flag != 0) { /* Line 128, Address: 0x1020c2c */
    actwk[0].sprvsize = 10; /* Line 129, Address: 0x1020c40 */
    actwk[0].sprhs = 5; /* Line 130, Address: 0x1020c4c */
  }


  actwk[0].sproffset = 1920; /* Line 134, Address: 0x1020c58 */
  actwk[0].sprpri = 2; /* Line 135, Address: 0x1020c64 */
  actwk[0].sprhsize = 24; /* Line 136, Address: 0x1020c70 */
  actwk[0].actflg = 4; /* Line 137, Address: 0x1020c7c */
  plmaxspdwk = 1536; /* Line 138, Address: 0x1020c88 */
  pladdspdwk = 12; /* Line 139, Address: 0x1020c94 */
  plretspdwk = 128; /* Line 140, Address: 0x1020ca0 */
} /* Line 141, Address: 0x1020cac */




void mizuki_set() { /* Line 146, Address: 0x1020cc0 */
 short d2, d3;
 unsigned int d1;
 sprite_status* new_actwk;

  if (stageno.b.h != 0) return; /* Line 151, Address: 0x1020cd4 */
  if (gametimer.b.l & 3) return; /* Line 152, Address: 0x1020cec */
  d2 = actwk[0].sprvsize; /* Line 153, Address: 0x1020d08 */
  d2 += actwk[0].yposi.w.h; /* Line 154, Address: 0x1020d1c */
  d3 = actwk[0].xposi.w.h; /* Line 155, Address: 0x1020d30 */
  d1 = mapno_chk(d2, d3); /* Line 156, Address: 0x1020d40 */
  if (d1 != 47) return; /* Line 157, Address: 0x1020d54 */
  if (actwk[0].xposi.w.h >= 5568) return; /* Line 158, Address: 0x1020d64 */

  if (actwk[0].actfree[2] == 0) return; /* Line 160, Address: 0x1020d80 */
  if (actwkchk(&new_actwk) != 0) return; /* Line 161, Address: 0x1020d94 */
  new_actwk->actno = 14; /* Line 162, Address: 0x1020da8 */
  new_actwk->xposi.w.h = actwk[0].xposi.w.h; /* Line 163, Address: 0x1020db4 */
  new_actwk->yposi.w.h = actwk[0].yposi.w.h; /* Line 164, Address: 0x1020dc4 */
  if (actwk[0].xspeed.w < 0) /* Line 165, Address: 0x1020dd4 */
    new_actwk->actflg = new_actwk->cddat = 1; /* Line 166, Address: 0x1020dec */
  else
    new_actwk->actflg = new_actwk->cddat = 0; /* Line 168, Address: 0x1020e0c */
} /* Line 169, Address: 0x1020e20 */




unsigned int mapno_chk(short d2, short d3) { /* Line 174, Address: 0x1020e40 */
  unsigned int d1;

  d1 = 33; /* Line 177, Address: 0x1020e50 */
  d1 = mapwka[d2 >> 8][d3 >> 8]; /* Line 178, Address: 0x1020e54 */
  return d1; /* Line 179, Address: 0x1020e94 */
} /* Line 180, Address: 0x1020e98 */



void kuru2() { /* Line 184, Address: 0x1020eb0 */
  unsigned short tmp_xposi;

  if (actwk[0].mstno.b.h == 43 || actwk[0].r_no0 >= 4 || actwk[0].actfree[2] & 8) /* Line 187, Address: 0x1020ec0 */
    return; /* Line 188, Address: 0x1020f0c */

  if (scramapad(&actwk[0], actwk[0].xposi.w.h, actwk[0].yposi.w.h) % 2048 != 259) return; /* Line 190, Address: 0x1020f14 */


  actwk[0].actfree[2] |= 8; /* Line 193, Address: 0x1020f4c */
  actwk[0].xspeed.w = 0; /* Line 194, Address: 0x1020f60 */
  actwk[0].yspeed.w = actwk[0].yspeed.w < 0 ? -512 : 512; /* Line 195, Address: 0x1020f68 */
  actwk[0].actfree[1] = 64; /* Line 196, Address: 0x1020fa0 */
  tmp_xposi = actwk[0].xposi.w.h; /* Line 197, Address: 0x1020fac */
  tmp_xposi = (tmp_xposi & -16) + 8; /* Line 198, Address: 0x1020fb8 */
  *(short*)&actwk[0].actfree[20] = actwk[0].xposi.w.h = tmp_xposi; /* Line 199, Address: 0x1020fcc */

  actwk[0].mstno.b.h = 2; /* Line 201, Address: 0x1020fdc */
  actwk[0].cddat |= 4; /* Line 202, Address: 0x1020fe8 */
  actwk[0].sprvsize = 14; /* Line 203, Address: 0x1020ffc */
  actwk[0].sprhs = 7; /* Line 204, Address: 0x1021008 */
} /* Line 205, Address: 0x1021014 */



void bura() { /* Line 209, Address: 0x1021030 */
  unsigned short tmp_yposi;

  if (actwk[0].mstno.b.h == 43 || plflag == 2 || actwk[0].actfree[2] & 5) /* Line 212, Address: 0x102103c */
    return; /* Line 213, Address: 0x1021088 */

  if (scramapad(&actwk[0], actwk[0].xposi.w.h, actwk[0].yposi.w.h) % 2048 != 345) return; /* Line 215, Address: 0x1021090 */


  if (backto_cnt != 0) { /* Line 218, Address: 0x10210dc */
    plpower_a = 0; /* Line 219, Address: 0x10210f4 */
    if (backto_cnt >= 90) time_item = 0; /* Line 220, Address: 0x10210fc */
    backto_cnt = 0; /* Line 221, Address: 0x1021120 */
  }

  actwk[0].cddat &= 251; /* Line 224, Address: 0x1021128 */
  actwk[0].xspeed.w = actwk[0].yspeed.w = actwk[0].mspeed.w = 0; /* Line 225, Address: 0x102113c */
  actwk[0].mstno.b.h = 44; /* Line 226, Address: 0x1021164 */
  actwk[0].actfree[2] |= 4; /* Line 227, Address: 0x1021170 */
  actwk[0].pattimm = 7; /* Line 228, Address: 0x1021184 */
  tmp_yposi = actwk[0].yposi.w.h; /* Line 229, Address: 0x1021190 */
  tmp_yposi = (tmp_yposi - 24 & -16) + 24; /* Line 230, Address: 0x102119c */
  actwk[0].yposi.w.h = tmp_yposi; /* Line 231, Address: 0x10211b4 */
} /* Line 232, Address: 0x10211bc */






void sibi2() { /* Line 239, Address: 0x10211d0 */
  short block_no, i;
  short* block_tbl;
  short* tbl[3] = { tate, yoko, naname }; /* Line 242, Address: 0x10211e0 */

  if (actwk[0].mstno.b.h == 43 || actwk[0].r_no0 >= 4 /* Line 244, Address: 0x1021204 */
      || plpower_a != 0 || plpower_m != 0
      || actwk[0].actfree[6] != 0 || st6clrchg == 0)
    return; /* Line 247, Address: 0x102128c */

  block_tbl = tbl[st6clrchg - 1]; /* Line 249, Address: 0x1021294 */
  block_no = scramapad(&actwk[0], actwk[0].xposi.w.h, actwk[0].yposi.w.h); /* Line 250, Address: 0x10212b4 */
  block_no %= 2048; /* Line 251, Address: 0x10212dc */
  i = 0; /* Line 252, Address: 0x10212e8 */
  while (block_tbl[i] >= 0) { /* Line 253, Address: 0x10212ec */
    if (block_no == block_tbl[i++]) { /* Line 254, Address: 0x10212f4 */
      playdamageset(&actwk[0], &actwk[0]); break; /* Line 255, Address: 0x1021334 */
    }
  } /* Line 257, Address: 0x1021354 */
} /* Line 258, Address: 0x102137c */


/* TODO: Recheck the weird assembly for lines 275 and 278. */
void sibi() { /* Line 262, Address: 0x10213a0 */
  short block_no, i;
  short* block_tbl;
  short tbl[3] = { 579, 580, 581 }; /* Line 265, Address: 0x10213b4 */
  short tbl0[3] = { 647, 648, 649 }; /* Line 266, Address: 0x10213d8 */

  if (actwk[0].mstno.b.h == 43 || plpower_a != 0 || plpower_m != 0) return; /* Line 268, Address: 0x10213fc */
  if (actwk[0].xposi.w.h >= 2432 && actwk[0].xposi.w.h < 2592) return; /* Line 269, Address: 0x1021440 */

  if (bossflag & 128 || actwk[0].actfree[6] != 0) return; /* Line 271, Address: 0x1021478 */
  if (stageno.b.l == 2) { /* Line 272, Address: 0x10214a8 */
    if (actwk[0].xposi.w.h < 2576) goto label1; /* Line 273, Address: 0x10214c4 */
    if (boss_sound == 0) return; /* Line 274, Address: 0x10214e0 */
    if (generate_flag == 0) goto label1; /* Line 275, Address: 0x10214f4 */
  } /* Line 276, Address: 0x1021504 */
  else {
    if (time_flag == 2) generate_flag < 1; /* Line 278, Address: 0x102150c */
  }

label1:
  block_no = scramapad(&actwk[0], actwk[0].xposi.w.h, actwk[0].yposi.w.h); /* Line 282, Address: 0x1021538 */
  block_no %= 2048; /* Line 283, Address: 0x1021560 */
  if (time_flag != 2 || generate_flag != 0) block_tbl = tbl; /* Line 284, Address: 0x102156c */
  else block_tbl = tbl0; /* Line 285, Address: 0x10215a0 */
  for (i = 0; i < 3; ++i) { /* Line 286, Address: 0x10215a4 */
    if (block_tbl[i] == block_no) { /* Line 287, Address: 0x10215b0 */
      playdamageset(&actwk[0], &actwk[0]); break; /* Line 288, Address: 0x10215dc */
    }
  } /* Line 290, Address: 0x10215fc */
} /* Line 291, Address: 0x102161c */



void bfloor() { /* Line 295, Address: 0x1021640 */
  unsigned char counter;

  if (actwk[0].mstno.b.h == 43 || bossflag != 0) return; /* Line 298, Address: 0x102164c */
  if (time_flag < 2) { /* Line 299, Address: 0x1021680 */
    if (time_flag != 0) counter = 90; /* Line 300, Address: 0x1021698 */
    else counter = 60; /* Line 301, Address: 0x10216b8 */
    if (clchgcnt[3] == counter) return; /* Line 302, Address: 0x10216c0 */
  }

  if (scramapad(&actwk[0], actwk[0].xposi.w.h - actwk[0].sprhs, actwk[0].yposi.w.h + actwk[0].sprvsize + 2) == 543) goto label1; /* Line 305, Address: 0x10216d8 */


  if (scramapad(&actwk[0], actwk[0].xposi.w.h - actwk[0].sprhs, actwk[0].yposi.w.h + actwk[0].sprvsize + 2) != 543) return; /* Line 308, Address: 0x1021764 */


label1:
  actwk[0].yspeed.w = -5632; /* Line 312, Address: 0x10217f0 */
  actwk[0].cddat |= 2; /* Line 313, Address: 0x10217fc */
  actwk[0].cddat &= 239; /* Line 314, Address: 0x1021810 */
  actwk[0].cddat &= 223; /* Line 315, Address: 0x1021824 */
  actwk[0].actfree[18] = 0; /* Line 316, Address: 0x1021838 */
  if (actwk[0].cddat & 4) return; /* Line 317, Address: 0x1021840 */
  actwk[0].cddat |= 4; /* Line 318, Address: 0x1021858 */
  actwk[0].sprvsize = 14; /* Line 319, Address: 0x102186c */
  actwk[0].sprhs = 5; /* Line 320, Address: 0x1021878 */
  actwk[0].yposi.w.h += 5; /* Line 321, Address: 0x1021884 */
  actwk[0].mstno.b.h = 2; /* Line 322, Address: 0x1021898 */
  soundset(218); /* Line 323, Address: 0x10218a4 */
} /* Line 324, Address: 0x10218b0 */





void scr_h() {} /* Line 330, Address: 0x10218d0 */



void play00move() { /* Line 334, Address: 0x10218e0 */
  scr_h(); /* Line 335, Address: 0x10218e8 */
  mizuki_set(); /* Line 336, Address: 0x10218f0 */
  if (debugflag.w != 0 && swdata1.b.l & 16) { /* Line 337, Address: 0x10218f8 */
    editmode.b.h = 1; /* Line 338, Address: 0x1021928 */
    return; /* Line 339, Address: 0x1021934 */
  }

  if (plautoflag == 0) swdata = swdata1; /* Line 342, Address: 0x102193c */
  else swdata.b.l |= swdata1.b.l & 128; /* Line 343, Address: 0x1021968 */

  if (actwk[0].actfree[2] & 1) { /* Line 345, Address: 0x1021990 */
    backto_chk(); /* Line 346, Address: 0x10219a8 */
  } else { /* Line 347, Address: 0x10219b0 */
    switch (actwk[0].cddat & 6) { /* Line 348, Address: 0x10219b8 */
      case 0:
        play00walk(); /* Line 350, Address: 0x10219fc */
        break; /* Line 351, Address: 0x1021a04 */
      case 2:
        play00jump(); /* Line 353, Address: 0x1021a0c */
        break; /* Line 354, Address: 0x1021a14 */
      case 4:
        ball00walk(); /* Line 356, Address: 0x1021a1c */
        break; /* Line 357, Address: 0x1021a24 */
      case 6:
        ball00jump(); /* Line 359, Address: 0x1021a2c */
        break;
    }


    bfloor(); /* Line 364, Address: 0x1021a34 */
    sibi(); /* Line 365, Address: 0x1021a3c */
    sibi2(); /* Line 366, Address: 0x1021a44 */
    bura(); /* Line 367, Address: 0x1021a4c */
    kuru2(); /* Line 368, Address: 0x1021a54 */
  }

  playpowercnt(); /* Line 371, Address: 0x1021a5c */
  playposiwkset(); /* Line 372, Address: 0x1021a64 */

  actwk[0].actfree[12] = dirstk[0]; /* Line 374, Address: 0x1021a6c */
  actwk[0].actfree[13] = dirstk[2]; /* Line 375, Address: 0x1021a7c */

  patchgmain(); /* Line 377, Address: 0x1021a8c */
  if (actwk[0].actfree[2] >= 0 && actwk[0].mstno.b.h != 43) { /* Line 378, Address: 0x1021a94 */

    pcol(&actwk[0]); /* Line 380, Address: 0x1021ad0 */
  }
  loopchk(); /* Line 382, Address: 0x1021ae0 */
} /* Line 383, Address: 0x1021ae8 */






void playpowercnt() { /* Line 390, Address: 0x1021b00 */
  unsigned short d0;
  unsigned short cal;

  if (backto_cnt < 157) { /* Line 394, Address: 0x1021b10 */
    d0 = *(short*)&actwk[0].actfree[6]; /* Line 395, Address: 0x1021b2c */
    if (d0 != 0) { /* Line 396, Address: 0x1021b38 */
      --*(short*)&actwk[0].actfree[6]; /* Line 397, Address: 0x1021b44 */
      if (d0 & 4) { /* Line 398, Address: 0x1021b58 */
        d0 = d0 >> 3; /* Line 399, Address: 0x1021b68 */
        if ((actwk[0].actfree[2] & 64) == 0) /* Line 400, Address: 0x1021b70 */
          actionsub(&actwk[0]); /* Line 401, Address: 0x1021b88 */
      } else d0 = d0 >> 3; /* Line 402, Address: 0x1021b98 */
    } /* Line 403, Address: 0x1021ba8 */
    else if ((actwk[0].actfree[2] & 64) == 0) { /* Line 404, Address: 0x1021bb0 */
      actionsub(&actwk[0]); /* Line 405, Address: 0x1021bc8 */
    }
  }


  if (plpower_m != 0) { /* Line 410, Address: 0x1021bd8 */
    d0 = *(short*)&actwk[0].actfree[8]; /* Line 411, Address: 0x1021bec */
    if (d0 != 0) { /* Line 412, Address: 0x1021bf8 */
      cal = d0 - 1; /* Line 413, Address: 0x1021c04 */
      --*(short*)&actwk[0].actfree[8]; /* Line 414, Address: 0x1021c14 */
      if (cal == 0) { /* Line 415, Address: 0x1021c28 */
        if (plpower_s == 0 && boss_sound == 0) { /* Line 416, Address: 0x1021c34 */
          if (time_flag == 0) { /* Line 417, Address: 0x1021c5c */
            sub_sync(14); /* Line 418, Address: 0x1021c70 */
          }

          da_set(); /* Line 421, Address: 0x1021c7c */
        }

        plpower_m = 0; /* Line 424, Address: 0x1021c84 */
      }
    }
  }


  if (plpower_s != 0) { /* Line 430, Address: 0x1021c8c */
    d0 = *(short*)&actwk[0].actfree[10]; /* Line 431, Address: 0x1021ca0 */
    if (d0 != 0) { /* Line 432, Address: 0x1021cac */
      cal = d0 - 1; /* Line 433, Address: 0x1021cb8 */
      --*(short*)&actwk[0].actfree[10]; /* Line 434, Address: 0x1021cc8 */
      if (cal == 0) { /* Line 435, Address: 0x1021cdc */
        plmaxspdwk = 1536; /* Line 436, Address: 0x1021ce8 */
        pladdspdwk = 12; /* Line 437, Address: 0x1021cf4 */
        plretspdwk = 128; /* Line 438, Address: 0x1021d00 */
        if (plpower_m == 0 && boss_sound == 0) { /* Line 439, Address: 0x1021d0c */
          if (time_flag == 0) { /* Line 440, Address: 0x1021d34 */
            sub_sync(14); /* Line 441, Address: 0x1021d48 */
          }

          da_set(); /* Line 444, Address: 0x1021d54 */
        }

        plpower_s = 0; /* Line 447, Address: 0x1021d5c */
      }
    }
  }
} /* Line 451, Address: 0x1021d64 */





void playposiwkset() {
  playposiwk[plposiwkadr.w / 2] = actwk[0].xposi.w.h; /* Line 458, Address: 0x1021d80 */
  playposiwk[plposiwkadr.w / 2] = actwk[0].yposi.w.h; /* Line 459, Address: 0x1021dc0 */
  plposiwkadr.b.l += 4; /* Line 460, Address: 0x1021e04 */
} /* Line 461, Address: 0x1021e18 */





void plwaterchk() {} /* Line 467, Address: 0x1021e20 */




void playsave() {
  lpKeepWork->plflag_sb = plflag; /* Line 473, Address: 0x1021e30 */
  lpKeepWork->plxposi_sb = actwk[0].xposi.w.h; /* Line 474, Address: 0x1021e44 */
  lpKeepWork->plyposi_sb = actwk[0].yposi.w.h; /* Line 475, Address: 0x1021e58 */
  lpKeepWork->plmspd_sb = actwk[0].mspeed.w; /* Line 476, Address: 0x1021e6c */
  lpKeepWork->plxspd_sb = actwk[0].xspeed.w; /* Line 477, Address: 0x1021e80 */
  lpKeepWork->plyspd_sb = actwk[0].yspeed.w; /* Line 478, Address: 0x1021e94 */
  lpKeepWork->cddat_sb = actwk[0].cddat; /* Line 479, Address: 0x1021ea8 */
  lpKeepWork->cddat_sb &= 247; /* Line 480, Address: 0x1021ebc */
  lpKeepWork->water_flag_sb = water_flag; /* Line 481, Address: 0x1021ed0 */
  lpKeepWork->scralim_down_sb = scralim_down; /* Line 482, Address: 0x1021ee4 */
  lpKeepWork->scra_h_posit_sb = scra_h_posit.w.h; /* Line 483, Address: 0x1021ef8 */
  lpKeepWork->scra_v_posit_sb = scra_v_posit.w.h; /* Line 484, Address: 0x1021f0c */
  lpKeepWork->scrb_h_posit_sb = scrb_h_posit.w.h; /* Line 485, Address: 0x1021f20 */
  lpKeepWork->scrb_v_posit_sb = scrb_v_posit.w.h; /* Line 486, Address: 0x1021f34 */
  lpKeepWork->scrc_h_posit_sb = scrc_h_posit.w.h; /* Line 487, Address: 0x1021f48 */
  lpKeepWork->scrc_v_posit_sb = scrc_v_posit.w.h; /* Line 488, Address: 0x1021f5c */
  lpKeepWork->scrz_h_posit_sb = scrz_h_posit.w.h; /* Line 489, Address: 0x1021f70 */
  lpKeepWork->scrz_v_posit_sb = scrz_v_posit.w.h; /* Line 490, Address: 0x1021f84 */
  lpKeepWork->waterposi_m_sb = waterposi_m; /* Line 491, Address: 0x1021f98 */
  lpKeepWork->water_flag_sb = water_flag; /* Line 492, Address: 0x1021fac */
  lpKeepWork->waterflag_sb = waterflag; /* Line 493, Address: 0x1021fc0 */
  lpKeepWork->plring_s = plring; /* Line 494, Address: 0x1021fd4 */
  plring_s = plring; /* Line 495, Address: 0x1021fe8 */
  lpKeepWork->plring_f2_s = plring_f2; /* Line 496, Address: 0x1021ff8 */
  plring_f2_s = plring_f2; /* Line 497, Address: 0x102200c */
  if (pltime.l >= (5 | 1)) lpKeepWork->pltime_sb = 5; /* Line 498, Address: 0x102201c */
  else lpKeepWork->pltime_sb = pltime.l; /* Line 499, Address: 0x1022050 */

} /* Line 501, Address: 0x1022064 */





void backto_chk() { /* Line 507, Address: 0x1022070 */
  short d0, d1, d2;
  char cal;

  if (lpKeepWork->TimeWarp == 0) return; /* Line 511, Address: 0x1022088 */

  if (actwk[0].actfree[0] != 0) return; /* Line 513, Address: 0x102209c */
  if (time_item == 0) return; /* Line 514, Address: 0x10220b0 */
  d1 = 1536; /* Line 515, Address: 0x10220c8 */
  d0 = actwk[0].mspeed.w; /* Line 516, Address: 0x10220d4 */
  if (d0 < 0) d0 = -d0; /* Line 517, Address: 0x10220e4 */
  if (backto_cnt == 0) backto_cnt = 1; /* Line 518, Address: 0x1022110 */
  if ((d2 = backto_cnt) >= 165) { /* Line 519, Address: 0x1022134 */
    if (plflag != 2) { /* Line 520, Address: 0x1022158 */
      cal = time_flag; /* Line 521, Address: 0x1022170 */
      cal += time_item; /* Line 522, Address: 0x1022180 */
      if (cal < 0) cal = 0; /* Line 523, Address: 0x10221ac */
      else if (cal >= 3) cal = 2; /* Line 524, Address: 0x10221c8 */
      time_flag = cal | 128; /* Line 525, Address: 0x10221e8 */
      playsave(); /* Line 526, Address: 0x1022200 */
    }
    gameflag.b.h = 1; /* Line 528, Address: 0x1022208 */
    fadeout_s(); /* Line 529, Address: 0x1022214 */
    return; /* Line 530, Address: 0x102221c */
  }
  if (d2 >= 157) { /* Line 532, Address: 0x1022224 */
    if (plflag == 2) return; /* Line 533, Address: 0x1022238 */
    scroll_start.b.h = 1; /* Line 534, Address: 0x1022250 */
    cal = time_flag; /* Line 535, Address: 0x102225c */
    if (cal == 0) /* Line 536, Address: 0x102226c */
      sub_sync(130); /* Line 537, Address: 0x102227c */


    cal += time_item; /* Line 540, Address: 0x1022288 */
    if (cal < 0) cal = 0; /* Line 541, Address: 0x10222b4 */
    else if (cal >= 3) cal = 2; /* Line 542, Address: 0x10222d0 */
    time_flag = cal | 128; /* Line 543, Address: 0x10222f0 */
    playsave(); /* Line 544, Address: 0x1022308 */
    plflag = 2; /* Line 545, Address: 0x1022310 */
    return; /* Line 546, Address: 0x102231c */
  }

  if (d2 < 90) { /* Line 549, Address: 0x1022324 */
    if (d0 >= d1) { muteki_set(); return; } /* Line 550, Address: 0x1022338 */
    backto_cnt = 0; /* Line 551, Address: 0x1022364 */
    plpower_a = 0; /* Line 552, Address: 0x102236c */
    return; /* Line 553, Address: 0x1022374 */
  }
  if (d0 < d1) { /* Line 555, Address: 0x102237c */
    backto_cnt = 0; /* Line 556, Address: 0x1022398 */
    time_item = 0; /* Line 557, Address: 0x10223a0 */
    plpower_a = 0; /* Line 558, Address: 0x10223a8 */
  }
} /* Line 560, Address: 0x10223b0 */





void play00walk() { /* Line 566, Address: 0x10223d0 */
  if (kusya_flag != 0) { /* Line 567, Address: 0x10223d8 */
    if (actwk[0].mstno.b.h == 5) return; /* Line 568, Address: 0x10223ec */
    kusya_flag = 0; /* Line 569, Address: 0x1022408 */
  }
  bye_chk(); /* Line 571, Address: 0x1022410 */
  if (actwk[0].mstno.b.h == 43) { /* Line 572, Address: 0x1022418 */
    if (chibi_flag != 0) { /* Line 573, Address: 0x1022434 */
      if (actwk[0].patno != 121) return; /* Line 574, Address: 0x1022448 */
    } /* Line 575, Address: 0x1022460 */
    else if (actwk[0].patno < 23) return; /* Line 576, Address: 0x1022468 */

    limitchk(); /* Line 578, Address: 0x1022480 */
    speedset(&actwk[0]); /* Line 579, Address: 0x1022488 */
    return; /* Line 580, Address: 0x1022498 */
  }
  chk11(); /* Line 582, Address: 0x10224a0 */
  backto_chk(); /* Line 583, Address: 0x10224a8 */
  if (jumpchk() != 0) return; /* Line 584, Address: 0x10224b0 */
  keispd(); /* Line 585, Address: 0x10224c4 */
  levermove(); /* Line 586, Address: 0x10224cc */
  ballchk(); /* Line 587, Address: 0x10224d4 */
  limitchk(); /* Line 588, Address: 0x10224dc */
  speedset2(&actwk[0]); /* Line 589, Address: 0x10224e4 */
  fcol(&actwk[0]); /* Line 590, Address: 0x10224f4 */
  fallchk(); /* Line 591, Address: 0x1022504 */
} /* Line 592, Address: 0x102250c */





void play00jump() { /* Line 598, Address: 0x1022520 */
  if (actwk[0].yspeed.w >= 0 && actwk[0].mstno.b.h != 44) /* Line 599, Address: 0x1022528 */
    actwk[0].mstno.b.h = 0; /* Line 600, Address: 0x102255c */
  if (actwk[0].actfree[2] & 4) { /* Line 601, Address: 0x1022564 */
    buramove(); jumpcolchk(); return; /* Line 602, Address: 0x102257c */
  }
  chk11(); /* Line 604, Address: 0x1022594 */
  backto_chk(); /* Line 605, Address: 0x102259c */
  jumpchk2(); /* Line 606, Address: 0x10225a4 */
  jumpmove(); /* Line 607, Address: 0x10225ac */
  limitchk(); /* Line 608, Address: 0x10225b4 */
  speedset(&actwk[0]); /* Line 609, Address: 0x10225bc */
  if (actwk[0].cddat & 64) actwk[0].yspeed.w -= 40; /* Line 610, Address: 0x10225cc */

  direcchg(); /* Line 612, Address: 0x10225f8 */

  jumpcolchk(); /* Line 614, Address: 0x1022600 */
} /* Line 615, Address: 0x1022608 */




void ball00walk() { /* Line 620, Address: 0x1022620 */
  chk11(); /* Line 621, Address: 0x1022628 */
  backto_chk(); /* Line 622, Address: 0x1022630 */
  if (jumpchk() != 0) return; /* Line 623, Address: 0x1022638 */
  keispd2(); /* Line 624, Address: 0x102264c */
  balllmove(); /* Line 625, Address: 0x1022654 */
  limitchk(); /* Line 626, Address: 0x102265c */
  if (actwk[0].actfree[0] == 0) speedset2(&actwk[0]); /* Line 627, Address: 0x1022664 */

  fcol(&actwk[0]); /* Line 629, Address: 0x1022688 */
  fallchk(); /* Line 630, Address: 0x1022698 */
} /* Line 631, Address: 0x10226a0 */




void ball00jump() { /* Line 636, Address: 0x10226b0 */
  if (actwk[0].actfree[2] & 8) { /* Line 637, Address: 0x10226b8 */
    kuru2move(); /* Line 638, Address: 0x10226d0 */
    backto_chk(); /* Line 639, Address: 0x10226d8 */
    jumpcolchk(); /* Line 640, Address: 0x10226e0 */
    return; /* Line 641, Address: 0x10226e8 */
  }
  if (actwk[0].actfree[2] & 4) { /* Line 643, Address: 0x10226f0 */
    buramove(); /* Line 644, Address: 0x1022708 */
    backto_chk(); /* Line 645, Address: 0x1022710 */
    jumpcolchk(); /* Line 646, Address: 0x1022718 */
    return; /* Line 647, Address: 0x1022720 */
  }

  chk11(); /* Line 650, Address: 0x1022728 */
  backto_chk(); /* Line 651, Address: 0x1022730 */
  jumpchk2(); /* Line 652, Address: 0x1022738 */
  jumpmove(); /* Line 653, Address: 0x1022740 */
  limitchk(); /* Line 654, Address: 0x1022748 */

  speedset(&actwk[0]); /* Line 656, Address: 0x1022750 */
  if (actwk[0].cddat & 64) actwk[0].yspeed.w -= 40; /* Line 657, Address: 0x1022760 */

  direcchg(); /* Line 659, Address: 0x102278c */

  jumpcolchk(); /* Line 661, Address: 0x1022794 */
} /* Line 662, Address: 0x102279c */


void kuru2move() { /* Line 666, Address: 0x10227b0 */
  short tmp_sin;
  short tmp_cos;

  if (actwk[0].actfree[2] & 16) { /* Line 669, Address: 0x10227bc */
    if ((actwk[0].actfree[1] % 128) == 0) { /* Line 670, Address: 0x10227d4 */
      actwk[0].mspeed.w = actwk[0].actfree[1] < 0 ? -3072 : 3072; /* Line 671, Address: 0x10227ec */

      actwk[0].sproffset %= 32768; /* Line 673, Address: 0x102282c */
      actwk[0].actfree[2] &= 231; /* Line 674, Address: 0x1022840 */
      *(short*)&actwk[0].actfree[20] = 0; /* Line 675, Address: 0x1022854 */
      return; /* Line 676, Address: 0x102285c */
    }
  }
  else if (swdata.b.l & 112) actwk[0].actfree[2] |= 16; /* Line 679, Address: 0x1022864 */

  if ((actwk[0].actfree[1] += 8) >= 0) actwk[0].sproffset |= 32768; /* Line 681, Address: 0x1022890 */
  else actwk[0].sproffset %= 32768; /* Line 682, Address: 0x10228dc */

  sinset(actwk[0].actfree[2], &tmp_sin, &tmp_cos); /* Line 684, Address: 0x10228f0 */
  tmp_cos = (tmp_cos * 23) / 256; /* Line 685, Address: 0x1022908 */
  actwk[0].xposi.w.h = *(short*)&actwk[0].actfree[20] + tmp_cos; /* Line 686, Address: 0x1022948 */

  actwk[0].yposi.l += actwk[0].yspeed.w << 8; /* Line 688, Address: 0x1022978 */

  if (scramapad(&actwk[0], *(short*)&actwk[0].actfree[20], actwk[0].yposi.w.h) % 2048) /* Line 690, Address: 0x10229a0 */
    actwk[0].yspeed.w = -actwk[0].yspeed.w; /* Line 691, Address: 0x10229d8 */
} /* Line 692, Address: 0x10229fc */



void buramove() { /* Line 696, Address: 0x1022a10 */
  if (scramapad(&actwk[0], actwk[0].xposi.w.h, actwk[0].yposi.w.h - 24) % 2048 == 345 || swdata.b.l & 112) { /* Line 697, Address: 0x1022a18 */


    actwk[0].actfree[2] &= 251; /* Line 700, Address: 0x1022a7c */
    actwk[0].yposi.w.h += 16; /* Line 701, Address: 0x1022a90 */
    actwk[0].sprvsize = 19; /* Line 702, Address: 0x1022aa4 */
    actwk[0].sprhs = 9; /* Line 703, Address: 0x1022ab0 */
    return; /* Line 704, Address: 0x1022abc */
  }

  if (swdata.b.h & 4) { /* Line 707, Address: 0x1022ac4 */
    actwk[0].cddat |= 1; /* Line 708, Address: 0x1022adc */
    actwk[0].actflg |= 1; /* Line 709, Address: 0x1022af0 */
    actwk[0].xposi.w.h -= 2; /* Line 710, Address: 0x1022b04 */
  } else if (swdata.b.h & 8) { /* Line 711, Address: 0x1022b18 */
    actwk[0].cddat &= 254; /* Line 712, Address: 0x1022b38 */
    actwk[0].actflg &= 254; /* Line 713, Address: 0x1022b4c */
    actwk[0].xposi.w.h += 2; /* Line 714, Address: 0x1022b60 */
  } else return; /* Line 715, Address: 0x1022b74 */
  if (--actwk[0].pattimm >= 0) return; /* Line 716, Address: 0x1022b84 */
  actwk[0].pattimm = 7; /* Line 717, Address: 0x1022bb4 */
  if (++actwk[0].patcnt >= 4) actwk[0].patcnt = 0; /* Line 718, Address: 0x1022bc0 */
} /* Line 719, Address: 0x1022bf0 */



void chk11() { /* Line 723, Address: 0x1022c00 */
  short d0;
  char mapdata;
  char chk11tbl[7] = { 6, 7, 8, 68, 69, 70, 73 }; /* Line 726, Address: 0x1022c0c */

  if (time_flag != 1) return; /* Line 728, Address: 0x1022c38 */
  if (stageno.b.l != 0) return; /* Line 729, Address: 0x1022c50 */
  d0 = ((actwk[0].yposi.w.h >> 1) & 896) + (actwk[0].xposi.b.b1 % 127); /* Line 730, Address: 0x1022c68 */

  mapdata = mapwka[d0 / 128][d0 % 64]; /* Line 732, Address: 0x1022cb8 */
  for (d0 = 0; d0 < 7; ++d0) { /* Line 733, Address: 0x1022d04 */
    if (mapdata == chk11tbl[d0]) { /* Line 734, Address: 0x1022d10 */
      actwk[0].actfree[2] |= 2; /* Line 735, Address: 0x1022d38 */
      return; /* Line 736, Address: 0x1022d4c */
    }
  } /* Line 738, Address: 0x1022d54 */
  if ((actwk[0].actfree[2] & 2) == 0) return; /* Line 739, Address: 0x1022d74 */
  actwk[0].actfree[2] &= 253; /* Line 740, Address: 0x1022d8c */
  if (actwk[0].yspeed.w >= 0) return; /* Line 741, Address: 0x1022da0 */
  if (actwk[0].yspeed.w >= 63488) return; /* Line 742, Address: 0x1022db8 */
  actwk[0].xspeed.w = 1536; /* Line 743, Address: 0x1022dd8 */
  if (actwk[0].cddat == 0) return; /* Line 744, Address: 0x1022de4 */
  actwk[0].xspeed.w = -actwk[0].xspeed.w; /* Line 745, Address: 0x1022dfc */
} /* Line 746, Address: 0x1022e20 */






void levermove() { /* Line 753, Address: 0x1022e40 */
  short d0;
  short d1;
  short d2;
  unsigned char ride_number;
  int sin_data;
  int cos_data;
  short sin_tmp;
  short cos_tmp;




  if (mizuflag != 0) goto label7; /* Line 766, Address: 0x1022e60 */
  if (actwk[0].actfree[20] != 0) goto label5; /* Line 767, Address: 0x1022e74 */
  if (swdata.b.h & 4) plwalk_l(); /* Line 768, Address: 0x1022e88 */
  if (swdata.b.h & 8) plwalk_r(); /* Line 769, Address: 0x1022ea8 */

  if (actwk[0].direc.b.h + 32 & 192) goto label5; /* Line 771, Address: 0x1022ec8 */
  if (actwk[0].mspeed.w != 0 && actwk[0].actfree[0] == 0) goto label5; /* Line 772, Address: 0x1022ee8 */

  if (actwk[0].mspeed.w == 0) { /* Line 774, Address: 0x1022f14 */
    actwk[0].cddat &= 223; /* Line 775, Address: 0x1022f2c */
    actwk[0].mstno.b.h = 5; /* Line 776, Address: 0x1022f40 */
  }
  if (actwk[0].cddat & 8) { /* Line 778, Address: 0x1022f4c */

    ride_number = actwk[0].actfree[19]; /* Line 780, Address: 0x1022f64 */
    if (actwk[ride_number].cddat < 0) { /* Line 781, Address: 0x1022f70 */
      if (actwk[ride_number].actno == 30) { /* Line 782, Address: 0x1022fa8 */
        actwk[0].mstno.b.h = 0; /* Line 783, Address: 0x1022fd8 */
        goto label5; /* Line 784, Address: 0x1022fe0 */
      }

      d0 = actwk[0].sprhsize; /* Line 787, Address: 0x1022fe8 */
      d2 = d0 * 2 - 4; /* Line 788, Address: 0x1023014 */
      d0 += actwk[0].xposi.w.h - actwk[ride_number].yposi.w.h; /* Line 789, Address: 0x1023034 */
      if (d0 < 4) goto label2; /* Line 790, Address: 0x102308c */
      if (d0 >= d2) goto label1; /* Line 791, Address: 0x10230a0 */
    } /* Line 792, Address: 0x10230bc */
  }
  else {
    d0 = emycol_d(&actwk[0]); /* Line 795, Address: 0x10230c4 */
    if (d0 >= 12) { /* Line 796, Address: 0x10230dc */
      if (actwk[0].actfree[12] == 3) { /* Line 797, Address: 0x10230f0 */

label1:
        if (actwk[0].cddat & 1) actwk[0].mstno.b.h = 50; /* Line 800, Address: 0x1023108 */
        else actwk[0].mstno.b.h = 6; /* Line 801, Address: 0x1023134 */
        goto label5; /* Line 802, Address: 0x1023140 */
      }

      if (actwk[0].actfree[13] == 3) { /* Line 805, Address: 0x1023148 */

label2:
        if ((actwk[0].cddat & 1) == 0) actwk[0].mstno.b.h = 50; /* Line 808, Address: 0x1023160 */
        else actwk[0].mstno.b.h = 6; /* Line 809, Address: 0x102318c */
        goto label5; /* Line 810, Address: 0x1023198 */
      }
    }
  }

  if (scr_cnt % 16) ++scr_cnt, scr_cnt &= 207; /* Line 815, Address: 0x10231a0 */
  if (scr_cnt & 128) goto label3; /* Line 816, Address: 0x10231e0 */
  if ((scr_cnt & 64) || (swdata.b.h & 2)) goto label4; /* Line 817, Address: 0x10231f8 */
  if ((scr_cnt %= 16) == 0) { /* Line 818, Address: 0x1023228 */
    if (swdata.b.l & 1) { scr_cnt = 1; goto label6; } /* Line 819, Address: 0x102324c */
  } else {
    if (swdata.b.l & 1) { scr_cnt |= 128; goto label6; } /* Line 821, Address: 0x1023278 */
  }

  if (swdata.b.h & 1) { /* Line 824, Address: 0x10232ac */
    actwk[0].mstno.b.h = 7; /* Line 825, Address: 0x10232c4 */
    if (actwk[0].actfree[0] != 0) { /* Line 826, Address: 0x10232d0 */
      actwk[0].mstno.b.h = 0; /* Line 827, Address: 0x10232e4 */
      d1 = 100; /* Line 828, Address: 0x10232ec */
      d0 = d2 = plmaxspdwk; /* Line 829, Address: 0x10232f8 */
      d0 = d0 & 32768 ? d0 * 2 | -32768 : d0 * 2; /* Line 830, Address: 0x1023310 */
      if (plpower_s != 0) d0 -= d2 /= 2; /* Line 831, Address: 0x1023354 */
      if (actwk[0].cddat & 1) d1 = -d1, d0 = -d0; /* Line 832, Address: 0x1023394 */

      actwk[0].mspeed.w += d1; /* Line 834, Address: 0x10233e4 */
      d1 = actwk[0].mspeed.w; /* Line 835, Address: 0x10233f8 */
      if (actwk[0].cddat & 1) { /* Line 836, Address: 0x1023408 */
        if (d1 < d0) d1 = d0; /* Line 837, Address: 0x1023420 */
      } /* Line 838, Address: 0x1023444 */
      else if (d0 < d1) d1 = d0; /* Line 839, Address: 0x102344c */

      actwk[0].mspeed.w = d1; /* Line 841, Address: 0x1023470 */
      return; /* Line 842, Address: 0x1023478 */
    }

    if (swdata.b.l & 112) { /* Line 845, Address: 0x1023480 */
      actwk[0].actfree[0] = 1; /* Line 846, Address: 0x1023498 */
      soundset(156); /* Line 847, Address: 0x10234a4 */
      WaveClear = 1; /* Line 848, Address: 0x10234b0 */
    }
    goto label6; /* Line 850, Address: 0x10234bc */
  }

  if (actwk[0].actfree[0] != 30) { /* Line 853, Address: 0x10234c4 */
    soundset(171); /* Line 854, Address: 0x10234dc */
    if (WaveClear != 0) WaveAllStop(), WaveClear = 0; /* Line 855, Address: 0x10234e8 */
    actwk[0].actfree[0] = 0; /* Line 856, Address: 0x1023510 */
    actwk[0].mspeed.w = 0; /* Line 857, Address: 0x1023518 */
    goto label4; /* Line 858, Address: 0x1023520 */
  }
  actwk[0].actfree[0] = 0; /* Line 860, Address: 0x1023528 */
  soundset(145); /* Line 861, Address: 0x1023530 */
  WaveClear = 0; /* Line 862, Address: 0x102353c */
  goto label5; /* Line 863, Address: 0x1023544 */



label3:
  if (swdata.b.h & 1) { /* Line 868, Address: 0x102354c */
    actwk[0].mstno.b.h = 7; /* Line 869, Address: 0x1023564 */
    if (scra_vline != 200) scra_vline += 2; /* Line 870, Address: 0x1023570 */
    goto label6; /* Line 871, Address: 0x10235a0 */
  }
label4:
  if (scr_cnt & 64) { /* Line 874, Address: 0x10235a8 */
    if ((scr_cnt %= 16) == 0) { /* Line 875, Address: 0x10235c0 */
      if (swdata.b.l & 2) { scr_cnt = 1; goto label6; } /* Line 876, Address: 0x10235e4 */
    } else {
      if (swdata.b.l & 2) { scr_cnt |= 64; goto label6; } /* Line 878, Address: 0x1023610 */
    }

    if (swdata.b.h & 2) { /* Line 881, Address: 0x1023644 */
      actwk[0].mstno.b.h = 8; /* Line 882, Address: 0x102365c */
      if (actwk[0].actfree[0] != 0) goto label6; /* Line 883, Address: 0x1023668 */
      if ((swdata.b.l & 112) == 0) goto label6; /* Line 884, Address: 0x102367c */
      actwk[0].actfree[0] = 1; /* Line 885, Address: 0x1023694 */
      actwk[0].mspeed.w = 22; /* Line 886, Address: 0x10236a0 */
      if (actwk[0].cddat & 1) actwk[0].mspeed.w = -actwk[0].mspeed.w; /* Line 887, Address: 0x10236ac */
      soundset(156); /* Line 888, Address: 0x10236e8 */
      WaveClear = 1; /* Line 889, Address: 0x10236f8 */
      ballset(); /* Line 890, Address: 0x1023704 */
      goto label6; /* Line 891, Address: 0x1023710 */
    }
  }
  if ((swdata.b.h & 2) == 0) { /* Line 894, Address: 0x1023718 */
    actwk[0].mstno.b.h = 8; /* Line 895, Address: 0x1023730 */
    if (scra_vline != 8) scra_vline -= 2; /* Line 896, Address: 0x102373c */
    goto label6; /* Line 897, Address: 0x102376c */
  }
label5:
  if (scra_vline == 96) { /* Line 900, Address: 0x1023774 */
    if (scr_cnt % 16 == 0) scr_cnt = 0; /* Line 901, Address: 0x1023790 */
  } /* Line 902, Address: 0x10237b0 */
  else {
    if (scra_vline < 96) scra_vline += 4; /* Line 904, Address: 0x10237b8 */
    scra_vline -= 2; /* Line 905, Address: 0x10237e8 */
  }


label6:
  if ((swdata.b.h & 12) == 0 && actwk[0].mspeed.w != 0) { /* Line 910, Address: 0x10237fc */

    if (actwk[0].mspeed.w >= 0) { /* Line 912, Address: 0x102382c */

      if ((actwk[0].mspeed.w -= pladdspdwk) < 0) actwk[0].mspeed.w = 0; /* Line 914, Address: 0x1023844 */
    } /* Line 915, Address: 0x1023880 */
    else {
      if ((actwk[0].mspeed.w += pladdspdwk) >= 0) actwk[0].mspeed.w = 0;; /* Line 917, Address: 0x1023888 */
    }
  }
label7:
  sinset(actwk[0].direc.b.h, &sin_tmp, &cos_tmp); /* Line 921, Address: 0x10238c4 */
  sin_data = sin_tmp; /* Line 922, Address: 0x10238e4 */
  cos_data = cos_tmp; /* Line 923, Address: 0x10238f0 */

  cos_data *= actwk[0].mspeed.w; /* Line 925, Address: 0x10238fc */
  cos_data = cos_data >> 8; /* Line 926, Address: 0x1023914 */

  actwk[0].xspeed.w = cos_data; /* Line 928, Address: 0x102391c */
  sin_data *= actwk[0].mspeed.w; /* Line 929, Address: 0x102392c */
  sin_data = sin_data >> 8; /* Line 930, Address: 0x1023940 */

  actwk[0].yspeed.w = sin_data; /* Line 932, Address: 0x1023944 */

  lmovecol(); /* Line 934, Address: 0x1023954 */
} /* Line 935, Address: 0x1023960 */


void lmovecol() { /* Line 938, Address: 0x1023990 */
  short add_speed = 0; /* Line 939, Address: 0x10239a4 */
  char add_dir;
  char tmp_dir;
  unsigned char sonic_dir;

  if (actwk[0].direc.b.h < -64 || actwk[0].mspeed.w == 0) return; /* Line 944, Address: 0x10239a8 */
  add_dir = 64; /* Line 945, Address: 0x10239e4 */
  if (actwk[0].mspeed.w > 0) add_dir = -add_dir; /* Line 946, Address: 0x10239f0 */

  sonic_dir = actwk[0].direc.b.h + add_dir; /* Line 948, Address: 0x1023a24 */
  tmp_dir = sonic_dir; /* Line 949, Address: 0x1023a48 */
  if ((add_speed = (char)dircolm(&actwk[0], &tmp_dir)) >=0) return; /* Line 950, Address: 0x1023a4c */
  sonic_dir = tmp_dir; /* Line 951, Address: 0x1023a90 */
  add_speed = (add_speed & 32768) ? (add_speed << 8) | -32768 : add_speed << 8; /* Line 952, Address: 0x1023a98 */
  sonic_dir = sonic_dir + 32 & 192; /* Line 953, Address: 0x1023adc */
  switch (sonic_dir) { /* Line 954, Address: 0x1023af0 */

    case 0:
      actwk[0].yspeed.w += add_speed; /* Line 957, Address: 0x1023b28 */
      break; /* Line 958, Address: 0x1023b3c */

    case 64:
      actwk[0].xspeed.w -= add_speed; /* Line 961, Address: 0x1023b44 */
      actwk[0].cddat |= 32; /* Line 962, Address: 0x1023b58 */
      actwk[0].mspeed.w = 0; /* Line 963, Address: 0x1023b6c */
      break; /* Line 964, Address: 0x1023b74 */

    case 128:
      actwk[0].yspeed.w -= add_speed; /* Line 967, Address: 0x1023b7c */
      break; /* Line 968, Address: 0x1023b90 */

    case 192:
      actwk[0].xspeed.w += add_speed; /* Line 971, Address: 0x1023b98 */
      actwk[0].cddat |= 32; /* Line 972, Address: 0x1023bac */
      actwk[0].mspeed.w = 0; /* Line 973, Address: 0x1023bc0 */
      break;
  }


} /* Line 978, Address: 0x1023bc8 */




void plwalk_l() { /* Line 983, Address: 0x1023bf0 */
  short cal_speed;

  if (actwk[0].actfree[0] != 0) return; /* Line 986, Address: 0x1023bfc */
  cal_speed = actwk[0].mspeed.w; /* Line 987, Address: 0x1023c10 */
  if (cal_speed <= 0) { /* Line 988, Address: 0x1023c20 */

    if ((actwk[0].cddat & 1) == 0) { /* Line 990, Address: 0x1023c30 */
      actwk[0].cddat |= 1; /* Line 991, Address: 0x1023c48 */
      actwk[0].cddat &= 223; /* Line 992, Address: 0x1023c5c */
      actwk[0].mstno.b.l = 1; /* Line 993, Address: 0x1023c70 */
    }

    if (-plmaxspdwk < cal_speed) { /* Line 996, Address: 0x1023c7c */
      cal_speed -= pladdspdwk; /* Line 997, Address: 0x1023ca4 */
      if (-plmaxspdwk >= cal_speed) cal_speed = -plmaxspdwk; /* Line 998, Address: 0x1023cb8 */
    }

    actwk[0].mspeed.w = cal_speed; /* Line 1001, Address: 0x1023d04 */
    actwk[0].mstno.b.h = 0; /* Line 1002, Address: 0x1023d0c */
  } /* Line 1003, Address: 0x1023d14 */
  else {
    if ((cal_speed -= plretspdwk) < 0) cal_speed = -128; /* Line 1005, Address: 0x1023d1c */

    actwk[0].mspeed.w = cal_speed; /* Line 1007, Address: 0x1023d54 */
    if (actwk[0].direc.b.h + 32 & 192) return; /* Line 1008, Address: 0x1023d5c */
    if (cal_speed < 1024) return; /* Line 1009, Address: 0x1023d7c */
    actwk[0].mstno.b.h = 13; /* Line 1010, Address: 0x1023d90 */
    actwk[0].cddat &= 254; /* Line 1011, Address: 0x1023d9c */

    if (Brake_Sw == 0) { /* Line 1013, Address: 0x1023db0 */
      soundset(144); /* Line 1014, Address: 0x1023dc4 */
      Brake_Sw = 1; /* Line 1015, Address: 0x1023dd0 */
    }
    Brake_Req = 1; /* Line 1017, Address: 0x1023ddc */
  }
} /* Line 1019, Address: 0x1023de8 */



void plwalk_r() { /* Line 1023, Address: 0x1023e00 */
  short cal_speed;

  if (actwk[0].actfree[0] != 0) return; /* Line 1026, Address: 0x1023e0c */
  cal_speed = actwk[0].mspeed.w; /* Line 1027, Address: 0x1023e20 */
  if (cal_speed >= 0) { /* Line 1028, Address: 0x1023e30 */

    if (actwk[0].cddat & 1) { /* Line 1030, Address: 0x1023e40 */
      actwk[0].cddat &= 254; /* Line 1031, Address: 0x1023e58 */
      actwk[0].cddat &= 223; /* Line 1032, Address: 0x1023e6c */
      actwk[0].mstno.b.l = 1; /* Line 1033, Address: 0x1023e80 */
    }

    if (cal_speed < plmaxspdwk) { /* Line 1036, Address: 0x1023e8c */
      cal_speed += pladdspdwk; /* Line 1037, Address: 0x1023eb0 */
      if (cal_speed >= plmaxspdwk) cal_speed = plmaxspdwk; /* Line 1038, Address: 0x1023ec4 */
    }

    actwk[0].mspeed.w = cal_speed; /* Line 1041, Address: 0x1023ef8 */
    actwk[0].mstno.b.h = 0; /* Line 1042, Address: 0x1023f00 */
  } /* Line 1043, Address: 0x1023f08 */
  else {
    if ((cal_speed += plretspdwk) >= 0) cal_speed = 128; /* Line 1045, Address: 0x1023f10 */
    actwk[0].mspeed.w = cal_speed; /* Line 1046, Address: 0x1023f48 */
    if (actwk[0].direc.b.h + 32 & 192) return; /* Line 1047, Address: 0x1023f50 */
    if (cal_speed >= -1023) return; /* Line 1048, Address: 0x1023f70 */
    actwk[0].mstno.b.h = 13; /* Line 1049, Address: 0x1023f84 */
    actwk[0].cddat |= 1; /* Line 1050, Address: 0x1023f90 */

    if (Brake_Sw == 0) { /* Line 1052, Address: 0x1023fa4 */
      soundset(144); /* Line 1053, Address: 0x1023fb8 */
      Brake_Sw = 1; /* Line 1054, Address: 0x1023fc4 */
    }
    Brake_Req = 1; /* Line 1056, Address: 0x1023fd0 */
  }
} /* Line 1058, Address: 0x1023fdc */







void balllmove() { /* Line 1066, Address: 0x1023ff0 */
  short d0;
  short d1;
  short d2;
  int sin_data;
  int cos_data;
  short sin_tmp;
  short cos_tmp;


  if (mizuflag != 0) goto label3; /* Line 1076, Address: 0x102400c */
  if (*(short*)&actwk[0].actfree[20] == 0) { /* Line 1077, Address: 0x1024020 */
    if (swdata.b.h & 4) ballwalk_l(); /* Line 1078, Address: 0x1024034 */
    else if (swdata.b.h & 8) ballwalk_r(); /* Line 1079, Address: 0x1024054 */
  }

  if (actwk[0].actfree[0] == 0) goto label1; /* Line 1082, Address: 0x1024074 */
  d0 = 50; /* Line 1083, Address: 0x1024088 */
  d1 = d2 = plmaxspdwk; /* Line 1084, Address: 0x1024094 */
  d1 = (d1 & 32768) ? (d1 << 1) | -32768 : d1 << 1; /* Line 1085, Address: 0x10240ac */
  if (plpower_s != 0) d1 -= d2 /= 2; /* Line 1086, Address: 0x10240f0 */
  if (actwk[0].cddat & 1) d0 = -d0, d1 = -d1; /* Line 1087, Address: 0x1024130 */

  actwk[0].mspeed.w += d0; /* Line 1089, Address: 0x1024180 */
  d0 = actwk[0].mspeed.w; /* Line 1090, Address: 0x1024194 */
  if (actwk[0].cddat & 1) { /* Line 1091, Address: 0x10241a4 */
    if (d0 < d1) d0 = d1; /* Line 1092, Address: 0x10241bc */
  } /* Line 1093, Address: 0x10241e0 */
  else if (d1 < d0) d0 = d1; /* Line 1094, Address: 0x10241e8 */


  actwk[0].mspeed.w = d0; /* Line 1097, Address: 0x102420c */
  if (swdata.b.h & 2 != 0) return; /* Line 1098, Address: 0x1024214 */

  if (actwk[0].actfree[0] != 45) { /* Line 1100, Address: 0x102422c */
    soundset(171); /* Line 1101, Address: 0x1024244 */
    if (WaveClear != 0) WaveAllStop(), WaveClear = 0; /* Line 1102, Address: 0x1024250 */
    actwk[0].actfree[0] = 0; /* Line 1103, Address: 0x1024278 */
    actwk[0].mspeed.w = actwk[0].xspeed.w = actwk[0].yspeed.w = 0; /* Line 1104, Address: 0x1024280 */
    goto label2; /* Line 1105, Address: 0x10242a8 */
  }
  actwk[0].actfree[0] = 0; /* Line 1107, Address: 0x10242b0 */
  soundset(145); /* Line 1108, Address: 0x10242b8 */
  WaveClear = 0; /* Line 1109, Address: 0x10242c4 */
  if ((actwk[0].cddat & 1) == 0) ballwalk_r(); /* Line 1110, Address: 0x10242cc */
  else ballwalk_l(); /* Line 1111, Address: 0x10242f4 */

label1:
  d0 = actwk[0].mspeed.w; /* Line 1114, Address: 0x10242fc */
  if (d0 != 0) { /* Line 1115, Address: 0x102430c */

    if (d0 > 0) { /* Line 1117, Address: 0x102431c */

      d0 -= pladdspdwk / 2; /* Line 1119, Address: 0x102432c */
      if (d0 < 0) d0 = 0; /* Line 1120, Address: 0x1024370 */
      actwk[0].mspeed.w = d0; /* Line 1121, Address: 0x1024384 */
    } /* Line 1122, Address: 0x102438c */
    else {
      d0 += pladdspdwk / 2; /* Line 1124, Address: 0x1024394 */
      if (d0 > 0) d0 = 0; /* Line 1125, Address: 0x10243d8 */
      actwk[0].mspeed.w = d0; /* Line 1126, Address: 0x10243ec */
    }
  }



  if (actwk[0].mspeed.w != 0) goto label3; /* Line 1132, Address: 0x10243f4 */

label2:
  actwk[0].cddat &= 251; /* Line 1135, Address: 0x102440c */
  if (chibi_flag != 0) { /* Line 1136, Address: 0x1024420 */
    actwk[0].sprvsize = 10; /* Line 1137, Address: 0x1024434 */
    actwk[0].sprhs = 5; /* Line 1138, Address: 0x1024440 */
  } else { /* Line 1139, Address: 0x102444c */
    actwk[0].sprvsize = 19; /* Line 1140, Address: 0x1024454 */
    actwk[0].sprhs = 9; /* Line 1141, Address: 0x1024460 */
    actwk[0].yposi.w.h -= 5; /* Line 1142, Address: 0x102446c */
  }
  actwk[0].mstno.b.h = 5; /* Line 1144, Address: 0x1024480 */

label3:
  sinset(actwk[0].direc.b.h, &sin_tmp, &cos_tmp); /* Line 1147, Address: 0x102448c */
  sin_data = sin_tmp; /* Line 1148, Address: 0x10244a8 */
  cos_data = cos_tmp; /* Line 1149, Address: 0x10244b4 */

  sin_data *= actwk[0].mspeed.w; /* Line 1151, Address: 0x10244c0 */
  sin_data = sin_data >> 8; /* Line 1152, Address: 0x10244d4 */

  actwk[0].yspeed.w = sin_data; /* Line 1154, Address: 0x10244d8 */
  cos_data *= actwk[0].mspeed.w; /* Line 1155, Address: 0x10244e8 */
  cos_data = cos_data >> 8; /* Line 1156, Address: 0x10244fc */
  if (cos_data >= 4097) cos_data = 4096; /* Line 1157, Address: 0x1024500 */
  if (cos_data < -4096) cos_data = -4096; /* Line 1158, Address: 0x1024510 */
  actwk[0].xspeed.w = cos_data; /* Line 1159, Address: 0x1024520 */

  lmovecol(); /* Line 1161, Address: 0x1024530 */
} /* Line 1162, Address: 0x1024538 */



void ballwalk_l() { /* Line 1166, Address: 0x1024560 */
  short cal_speed;

  if ((cal_speed = actwk[0].mspeed.w) <= 0) { /* Line 1169, Address: 0x1024568 */

    actwk[0].cddat |= 1; /* Line 1171, Address: 0x1024588 */
    actwk[0].mstno.b.h = 2; /* Line 1172, Address: 0x102459c */
  } /* Line 1173, Address: 0x10245a8 */
  else {
    cal_speed -= plretspdwk / 4; /* Line 1175, Address: 0x10245b0 */
    if (cal_speed < 0) cal_speed = -128; /* Line 1176, Address: 0x10245f4 */
    actwk[0].mspeed.w = cal_speed; /* Line 1177, Address: 0x1024610 */
  }
} /* Line 1179, Address: 0x1024618 */


void ballwalk_r() { /* Line 1182, Address: 0x1024630 */
  short cal_speed;

  if ((cal_speed = actwk[0].mspeed.w) >= 0) { /* Line 1185, Address: 0x1024638 */

    actwk[0].cddat &= 254; /* Line 1187, Address: 0x1024658 */
    actwk[0].mstno.b.h = 2; /* Line 1188, Address: 0x102466c */
  } /* Line 1189, Address: 0x1024678 */
  else {
    cal_speed -= plretspdwk / 4; /* Line 1191, Address: 0x1024680 */
    if (cal_speed > 0) cal_speed = 128; /* Line 1192, Address: 0x10246c4 */
    actwk[0].mspeed.w = cal_speed; /* Line 1193, Address: 0x10246e0 */
  }
} /* Line 1195, Address: 0x10246e8 */


void jumpmove() { /* Line 1199, Address: 0x1024700 */
  short cal_speed;
  short cmp_speed;






  cal_speed = actwk[0].xspeed.w; /* Line 1207, Address: 0x102470c */
  if (stageno.w == 0) { /* Line 1208, Address: 0x102471c */

    if (actwk[0].xposi.w.h < 1736 || actwk[0].xposi.w.h >= 2112) { /* Line 1210, Address: 0x1024734 */
      if (actwk[0].actfree[2] & 2) goto label1; /* Line 1211, Address: 0x102476c */
    }
    else {
      if (actwk[0].actfree[2] & 2) goto label1; /* Line 1214, Address: 0x102478c */
    }
  }


  cal_speed = actwk[0].xspeed.w; /* Line 1219, Address: 0x10247a4 */
  if (swdata.b.h & 4) { /* Line 1220, Address: 0x10247b4 */
    actwk[0].cddat |= 1; /* Line 1221, Address: 0x10247cc */
    cal_speed -= pladdspdwk * 2; /* Line 1222, Address: 0x10247e0 */
    cmp_speed = -plmaxspdwk; /* Line 1223, Address: 0x1024810 */
    if (cmp_speed >= cal_speed) cal_speed = cmp_speed; /* Line 1224, Address: 0x1024834 */
  }

  if (swdata.b.h & 8) { /* Line 1227, Address: 0x1024858 */
    actwk[0].cddat &= 254; /* Line 1228, Address: 0x1024870 */
    cal_speed += pladdspdwk * 2; /* Line 1229, Address: 0x1024884 */
    if (cal_speed >= plmaxspdwk) cal_speed = plmaxspdwk; /* Line 1230, Address: 0x10248b4 */
  }

label1:
  actwk[0].xspeed.w = cal_speed; /* Line 1234, Address: 0x10248e8 */

  if (scra_vline < 96) scra_vline += 2; /* Line 1236, Address: 0x10248f0 */
  else if (scra_vline >= 97) scra_vline -= 2; /* Line 1237, Address: 0x1024928 */
  if (actwk[0].yspeed.w < -1024) return; /* Line 1238, Address: 0x1024958 */
  cal_speed = actwk[0].xspeed.w; /* Line 1239, Address: 0x1024978 */
  if (cal_speed / 32 == 0) return; /* Line 1240, Address: 0x1024988 */
  if (cal_speed > 0) { /* Line 1241, Address: 0x10249b0 */

    cal_speed -= cal_speed / 32; /* Line 1243, Address: 0x10249c0 */
    if (cal_speed < 0) cal_speed = 0; /* Line 1244, Address: 0x10249fc */
  } /* Line 1245, Address: 0x1024a10 */
  else {
    cal_speed -= cal_speed / 32; /* Line 1247, Address: 0x1024a18 */
    if (cal_speed >= 0) cal_speed = 0; /* Line 1248, Address: 0x1024a54 */
  }
  actwk[0].xspeed.w = cal_speed; /* Line 1250, Address: 0x1024a68 */
} /* Line 1251, Address: 0x1024a70 */




void hedcolchk() { /* Line 1256, Address: 0x1024a90 */
  short tmp_d0, tmp_d1, tmp_d3;
  unsigned char cal_direc;

  cal_direc = actwk[0].direc.b.h + 32 & 192; /* Line 1260, Address: 0x1024a9c */
  if (cal_direc == 0) { /* Line 1261, Address: 0x1024abc */
    if (dircol_u(&actwk[0], &tmp_d0, &tmp_d1, &tmp_d3) < 0) { /* Line 1262, Address: 0x1024ac8 */

      actwk[0].mspeed.w = actwk[0].xspeed.w = actwk[0].yspeed.w = 0; /* Line 1264, Address: 0x1024af4 */
      actwk[0].mstno.b.h = 11; /* Line 1265, Address: 0x1024b1c */
    }
  }
} /* Line 1268, Address: 0x1024b28 */




void limitchk() { /* Line 1273, Address: 0x1024b40 */
  short cal_limit_l, cal_limit_r, position_wk;
  int cal_position, cal_speed;

  cal_position = actwk[0].xposi.l; /* Line 1277, Address: 0x1024b5c */
  cal_speed = actwk[0].xspeed.w; /* Line 1278, Address: 0x1024b64 */
  cal_speed = (cal_speed & -32768) ? (cal_speed << 8) | -32768 : cal_speed << 8; /* Line 1279, Address: 0x1024b74 */
  cal_position += cal_speed; /* Line 1280, Address: 0x1024b9c */
  position_wk = cal_position; /* Line 1281, Address: 0x1024ba0 */
  cal_limit_l = scralim_left + 16; /* Line 1282, Address: 0x1024bb4 */
  cal_limit_r = scralim_right + 304; /* Line 1283, Address: 0x1024bd8 */
  if (bossstart == 0) cal_limit_r += 56; /* Line 1284, Address: 0x1024bfc */
  if (position_wk < cal_limit_l) { /* Line 1285, Address: 0x1024c1c */

    actwk[0].xposi.w.h = cal_limit_l; /* Line 1287, Address: 0x1024c38 */
    actwk[0].xposi.w.l = actwk[0].xspeed.w = actwk[0].mspeed.w = 0; /* Line 1288, Address: 0x1024c40 */
  }
  if (position_wk >= cal_limit_r) { /* Line 1290, Address: 0x1024c68 */

    actwk[0].xposi.w.h = cal_limit_r; /* Line 1292, Address: 0x1024c84 */
    actwk[0].xposi.w.l = actwk[0].xspeed.w = actwk[0].mspeed.w = 0; /* Line 1293, Address: 0x1024c8c */
  }

  if (scralim_down + 224 >= actwk[0].yposi.w.h) return; /* Line 1296, Address: 0x1024cb4 */

  if (actwk[0].mstno.b.h != 43) playdieset(&actwk[0]); /* Line 1298, Address: 0x1024ce4 */
  else actwk[0].r_no0 = 6; /* Line 1299, Address: 0x1024d18 */
} /* Line 1300, Address: 0x1024d24 */




void ballchk() { /* Line 1305, Address: 0x1024d50 */
  if (mizuflag != 0) return; /* Line 1306, Address: 0x1024d58 */

  if (actwk[0].mspeed.w < 128 && actwk[0].mspeed.w >= -127) return; /* Line 1308, Address: 0x1024d6c */
  if ((swdata.b.h & 12) == 0 && (swdata.b.h & 2) == 0) return; /* Line 1309, Address: 0x1024da4 */
  ballset(); /* Line 1310, Address: 0x1024ddc */
} /* Line 1311, Address: 0x1024de4 */


void ballset() {
  if ((actwk[0].cddat & 4) == 0) { /* Line 1315, Address: 0x1024e00 */

    actwk[0].cddat |= 4; /* Line 1317, Address: 0x1024e18 */
    if (chibi_flag != 0) { /* Line 1318, Address: 0x1024e2c */
      actwk[0].sprvsize = 10; /* Line 1319, Address: 0x1024e40 */
      actwk[0].sprhs = 5; /* Line 1320, Address: 0x1024e4c */
    } /* Line 1321, Address: 0x1024e58 */
    else {
      actwk[0].sprvsize = 14; /* Line 1323, Address: 0x1024e60 */
      actwk[0].sprhs = 7; /* Line 1324, Address: 0x1024e6c */
      actwk[0].yposi.w.h += 5; /* Line 1325, Address: 0x1024e78 */
    }
  } else return; /* Line 1327, Address: 0x1024e8c */

  actwk[0].mstno.b.h = 2; /* Line 1329, Address: 0x1024e9c */
  if (actwk[0].mspeed.w == 0) actwk[0].mspeed.w = 512; /* Line 1330, Address: 0x1024ea8 */
} /* Line 1331, Address: 0x1024ecc */




unsigned char jumpchk() { /* Line 1336, Address: 0x1024ee0 */
  char cal_char;
  unsigned char cal_direc, ret_flag;
  int cal_jump, sin_data, cos_data;
  short sin_tmp, cos_tmp;

  cal_direc = 0; /* Line 1342, Address: 0x1024ef4 */
  cal_jump = 0; /* Line 1343, Address: 0x1024ef8 */
  ret_flag = 0; /* Line 1344, Address: 0x1024efc */

  if (actwk[0].actfree[0] != 0) return ret_flag; /* Line 1346, Address: 0x1024f00 */
  if ((swdata.b.h & 3) && actwk[0].mspeed.w == 0) return ret_flag; /* Line 1347, Address: 0x1024f20 */

  if ((swdata.b.l & 112) == 0) return ret_flag; /* Line 1349, Address: 0x1024f5c */
  if ((actwk[0].cddat & 8) && frip_spd(&cal_jump, &cal_direc) == 0) goto label1; /* Line 1350, Address: 0x1024f80 */


  cal_direc = actwk[0].direc.b.h + 128; /* Line 1353, Address: 0x1024fb4 */
  cal_char = cal_direc; /* Line 1354, Address: 0x1024fd0 */
  if (dircol2(&actwk[0], &cal_char) < 6) return ret_flag; /* Line 1355, Address: 0x1024fd8 */

  cal_jump = 1664; /* Line 1357, Address: 0x102500c */
  if (actwk[0].cddat & 64) cal_jump = 896; /* Line 1358, Address: 0x1025014 */
  cal_direc = actwk[0].direc.b.h - 64; /* Line 1359, Address: 0x1025034 */

label1:
  sinset(cal_direc, &sin_tmp, &cos_tmp); /* Line 1362, Address: 0x1025050 */
  sin_data = sin_tmp; /* Line 1363, Address: 0x1025064 */
  cos_data = cos_tmp; /* Line 1364, Address: 0x1025070 */

  cos_data *= cal_jump; /* Line 1366, Address: 0x102507c */
  cos_data = cos_data >> 8; /* Line 1367, Address: 0x1025084 */
  actwk[0].xspeed.w += cos_data; /* Line 1368, Address: 0x1025088 */
  sin_data *= cal_jump; /* Line 1369, Address: 0x10250a4 */
  sin_data = sin_data >> 8; /* Line 1370, Address: 0x10250ac */
  actwk[0].yspeed.w += sin_data; /* Line 1371, Address: 0x10250b0 */
  actwk[0].cddat |= 2; /* Line 1372, Address: 0x10250cc */
  actwk[0].cddat &= 223; /* Line 1373, Address: 0x10250e0 */
  ret_flag = 255; /* Line 1374, Address: 0x10250f4 */

  actwk[0].actfree[18] = 1; /* Line 1376, Address: 0x10250fc */
  scr_cnt = actwk[0].actfree[14] = 0; /* Line 1377, Address: 0x1025108 */


  soundset(146); /* Line 1380, Address: 0x1025118 */

  if (actwk[0].cddat & 4) { /* Line 1382, Address: 0x1025124 */
    actwk[0].cddat |= 16; /* Line 1383, Address: 0x102513c */
    return ret_flag; /* Line 1384, Address: 0x1025150 */
  }
  if (chibi_flag != 0) { /* Line 1386, Address: 0x102515c */
    actwk[0].sprvsize = 10; /* Line 1387, Address: 0x1025170 */
    actwk[0].sprhs = 5; /* Line 1388, Address: 0x102517c */
  } else { /* Line 1389, Address: 0x1025188 */
    actwk[0].sprvsize = 14; /* Line 1390, Address: 0x1025190 */
    actwk[0].sprhs = 7; /* Line 1391, Address: 0x102519c */
    actwk[0].yposi.w.h += 5; /* Line 1392, Address: 0x10251a8 */
  }
  actwk[0].cddat |= 4; /* Line 1394, Address: 0x10251bc */
  actwk[0].mstno.b.h = 2; /* Line 1395, Address: 0x10251d0 */
  return ret_flag; /* Line 1396, Address: 0x10251dc */
} /* Line 1397, Address: 0x10251e0 */


void jumpchk2() { /* Line 1400, Address: 0x1025200 */
  short cal_speed;

  if (actwk[0].actfree[2] != 0) { /* Line 1403, Address: 0x1025208 */
    cal_speed = -1024; /* Line 1404, Address: 0x102521c */
    if (actwk[0].cddat & 64) cal_speed = -512; /* Line 1405, Address: 0x1025228 */
    if (actwk[0].yspeed.w < cal_speed) { /* Line 1406, Address: 0x102524c */
      if ((swdata.b.h & 112) == 0) { /* Line 1407, Address: 0x1025270 */
        actwk[0].actfree[0] = 0; /* Line 1408, Address: 0x1025288 */
        actwk[0].yspeed.w = cal_speed; /* Line 1409, Address: 0x1025290 */
      }
    }
  }

} /* Line 1414, Address: 0x1025298 */




void keispd() { /* Line 1419, Address: 0x10252b0 */
  unsigned char cal_direc;
  int sin_data;
  short sin_tmp, cos_tmp;

  if (actwk[0].actfree[0] != 0) return; /* Line 1424, Address: 0x10252c0 */
  cal_direc = actwk[0].direc.b.h + 96; /* Line 1425, Address: 0x10252d4 */
  if (cal_direc >= 192) return; /* Line 1426, Address: 0x10252f0 */
  cal_direc = actwk[0].direc.b.h; /* Line 1427, Address: 0x1025300 */

  sinset(actwk[0].direc.b.h, &sin_tmp, &cos_tmp); /* Line 1429, Address: 0x102530c */
  sin_data = sin_tmp; /* Line 1430, Address: 0x1025328 */

  sin_data *= 32; /* Line 1432, Address: 0x1025334 */
  sin_data = sin_data >> 8; /* Line 1433, Address: 0x1025338 */
  if (actwk[0].mspeed.w == 0) return; /* Line 1434, Address: 0x102533c */
  if (actwk[0].mspeed.w > 0) { /* Line 1435, Address: 0x1025354 */
    if (sin_data != 0) actwk[0].mspeed.w += sin_data;; /* Line 1436, Address: 0x102536c */
  } else { /* Line 1437, Address: 0x1025390 */
    actwk[0].mspeed.w += sin_data; /* Line 1438, Address: 0x1025398 */
  }
} /* Line 1440, Address: 0x10253b4 */


void keispd2() { /* Line 1443, Address: 0x10253d0 */
  unsigned char cal_direc;
  int sin_data;
  short sin_tmp, cos_tmp;

  if (actwk[0].actfree[0] != 0) return; /* Line 1448, Address: 0x10253e0 */
  cal_direc = actwk[0].direc.b.h + 96; /* Line 1449, Address: 0x10253f4 */
  if (cal_direc >= 192) return; /* Line 1450, Address: 0x1025410 */
  cal_direc = actwk[0].direc.b.h; /* Line 1451, Address: 0x1025420 */

  sinset(actwk[0].direc.b.h, &sin_tmp, &cos_tmp); /* Line 1453, Address: 0x102542c */
  sin_data = sin_tmp; /* Line 1454, Address: 0x1025448 */

  sin_data *= 80; /* Line 1456, Address: 0x1025454 */
  sin_data = sin_data >> 8; /* Line 1457, Address: 0x1025460 */
  if (actwk[0].mspeed.w >= 0) { /* Line 1458, Address: 0x1025464 */
    if (sin_data < 0) sin_data /= 4; /* Line 1459, Address: 0x102547c */
    actwk[0].mspeed.w += sin_data; /* Line 1460, Address: 0x10254a0 */
  } else { /* Line 1461, Address: 0x10254bc */
    if (sin_data >= 0) sin_data /= 4; /* Line 1462, Address: 0x10254c4 */
    actwk[0].mspeed.w += sin_data; /* Line 1463, Address: 0x10254e8 */
  }
} /* Line 1465, Address: 0x1025504 */




void fallchk() {
  if (actwk[0].actfree[14] != 0) return; /* Line 1471, Address: 0x1025520 */
  if (*(short*)&actwk[0].actfree[20] == 0) { /* Line 1472, Address: 0x1025534 */
    if ((actwk[0].direc.b.h + 32 & 192) == 0) return; /* Line 1473, Address: 0x1025548 */
    if (actwk[0].mspeed.w < 641 || actwk[0].mspeed.w >= -640) /* Line 1474, Address: 0x1025568 */
      return; /* Line 1475, Address: 0x10255a0 */
    actwk[0].mspeed.w = 0; /* Line 1476, Address: 0x10255a8 */
    actwk[0].cddat |= 2; /* Line 1477, Address: 0x10255b0 */
    *(short*)&actwk[0].actfree[20] = 30; /* Line 1478, Address: 0x10255c4 */
  } else { /* Line 1479, Address: 0x10255d0 */
    --*(short*)&actwk[0].actfree[20]; /* Line 1480, Address: 0x10255d8 */
  }
} /* Line 1482, Address: 0x10255ec */




void direcchg() { /* Line 1487, Address: 0x1025600 */
  char cal_direc;

  if (actwk[0].actfree[2] & 2 != 0) return; /* Line 1490, Address: 0x1025608 */
  if ((cal_direc = actwk[0].direc.b.h) == 0) return; /* Line 1491, Address: 0x1025620 */
  if (cal_direc < 0) { /* Line 1492, Address: 0x1025640 */
    if ((cal_direc += 2) > 0) cal_direc = 0; /* Line 1493, Address: 0x1025650 */
  } else { /* Line 1494, Address: 0x1025678 */
    if ((cal_direc -= 2) < 0) cal_direc = 0; /* Line 1495, Address: 0x1025680 */
  }
  actwk[0].direc.b.h = cal_direc; /* Line 1497, Address: 0x10256a8 */
} /* Line 1498, Address: 0x10256b0 */







void jumpcolchk() { /* Line 1506, Address: 0x10256c0 */
  short chk_d0, chk_d1, tmp_d3;
  char chk_d2, chk_d3;
  unsigned char cal_direc;

  cal_direc = atan_sonic(actwk[0].xspeed.w, actwk[0].yspeed.w); /* Line 1511, Address: 0x10256d4 */

  debugwork.b.b1 = cal_direc; /* Line 1513, Address: 0x10256f4 */
  cal_direc -= 32; /* Line 1514, Address: 0x10256fc */
  debugwork.b.b2 = cal_direc; /* Line 1515, Address: 0x1025704 */
  cal_direc &= 192; /* Line 1516, Address: 0x102570c */
  debugwork.b.b3 = cal_direc; /* Line 1517, Address: 0x1025714 */
  switch (cal_direc) { /* Line 1518, Address: 0x102571c */

    case 0:
      chk_d1 = dircol_l2(&actwk[0]); /* Line 1521, Address: 0x1025754 */

      if (chk_d1 < 0) { /* Line 1523, Address: 0x1025768 */
        actwk[0].xposi.w.h -= chk_d1; /* Line 1524, Address: 0x102577c */
        actwk[0].xspeed.w = 0; /* Line 1525, Address: 0x1025794 */
      }
      chk_d1 = dircol_r2(&actwk[0]); /* Line 1527, Address: 0x102579c */

      if (chk_d1 < 0) { /* Line 1529, Address: 0x10257b0 */
        actwk[0].xposi.w.h += chk_d1; /* Line 1530, Address: 0x10257c4 */
        actwk[0].xspeed.w = 0; /* Line 1531, Address: 0x10257dc */
      }
      dircol_d(&actwk[0], &chk_d0, &chk_d1, &tmp_d3); /* Line 1533, Address: 0x10257e4 */
      chk_d3 = tmp_d3; /* Line 1534, Address: 0x1025800 */

      debugwork.b.b4 = chk_d1; /* Line 1536, Address: 0x1025814 */
      if (chk_d1 >= 0) break; /* Line 1537, Address: 0x1025824 */
      chk_d2 = -(actwk[0].yspeed.b.h + 8); /* Line 1538, Address: 0x1025838 */
      if ((char)chk_d1 >= chk_d2 && (char)chk_d1 < chk_d2) return; /* Line 1539, Address: 0x1025860 */

      actwk[0].yposi.w.h += chk_d1; /* Line 1541, Address: 0x10258b0 */
      actwk[0].direc.b.h = chk_d3; /* Line 1542, Address: 0x10258c8 */
      jumpcolsub(); /* Line 1543, Address: 0x10258d0 */
      actwk[0].mstno.b.h = 0; /* Line 1544, Address: 0x10258d8 */
      if (chk_d3 + 32 & 64) { /* Line 1545, Address: 0x10258e0 */

        actwk[0].xspeed.w = 0; /* Line 1547, Address: 0x10258f8 */
        if (actwk[0].yspeed.w >= 4033) actwk[0].yspeed.w = 4032; /* Line 1548, Address: 0x1025900 */
      } else { /* Line 1549, Address: 0x1025928 */
        if ((chk_d3 + 16 & 32) == 0) { /* Line 1550, Address: 0x1025930 */

          actwk[0].yspeed.w = 0; /* Line 1552, Address: 0x1025948 */
          actwk[0].mspeed.w = actwk[0].xspeed.w; /* Line 1553, Address: 0x1025950 */
          break; /* Line 1554, Address: 0x1025960 */
        }
        actwk[0].yspeed.w /= 2; /* Line 1556, Address: 0x1025968 */
      }

      actwk[0].mspeed.w = actwk[0].yspeed.w; /* Line 1559, Address: 0x1025990 */
      if (chk_d3 < 0) actwk[0].mspeed.w = -actwk[0].mspeed.w; /* Line 1560, Address: 0x10259a0 */
      break; /* Line 1561, Address: 0x10259d4 */


    case 64:
      chk_d1 = dircol_l2(&actwk[0]); /* Line 1565, Address: 0x10259dc */

      if (chk_d1 < 0) { /* Line 1567, Address: 0x10259f0 */
        actwk[0].xposi.w.h -= chk_d1; /* Line 1568, Address: 0x1025a04 */
        actwk[0].xspeed.w = 0; /* Line 1569, Address: 0x1025a1c */
        actwk[0].mspeed.w = actwk[0].yspeed.w; /* Line 1570, Address: 0x1025a24 */
        break; /* Line 1571, Address: 0x1025a34 */
      }
      dircol_u(&actwk[0], &chk_d0, &chk_d1, &tmp_d3); /* Line 1573, Address: 0x1025a3c */

      if (chk_d1 < 0) { /* Line 1575, Address: 0x1025a58 */
        actwk[0].yposi.w.h -= chk_d1; /* Line 1576, Address: 0x1025a6c */
        if (actwk[0].yspeed.w < 0) actwk[0].yspeed.w = 0; /* Line 1577, Address: 0x1025a84 */
        break; /* Line 1578, Address: 0x1025aa4 */
      }

      if (actwk[0].yspeed.w < 0) break; /* Line 1581, Address: 0x1025aac */
      dircol_d(&actwk[0], &chk_d0, &chk_d1, &tmp_d3); /* Line 1582, Address: 0x1025ac4 */
      chk_d3 = tmp_d3; /* Line 1583, Address: 0x1025ae0 */

      if (chk_d1 >= 0) break; /* Line 1585, Address: 0x1025af4 */
      actwk[0].yposi.w.h += chk_d1; /* Line 1586, Address: 0x1025b08 */
      actwk[0].direc.b.h = chk_d3; /* Line 1587, Address: 0x1025b20 */
      jumpcolsub(); /* Line 1588, Address: 0x1025b28 */
      actwk[0].mstno.b.h = 0; /* Line 1589, Address: 0x1025b30 */
      actwk[0].yspeed.w = 0; /* Line 1590, Address: 0x1025b38 */
      actwk[0].mspeed.w = actwk[0].xspeed.w; /* Line 1591, Address: 0x1025b40 */
      break; /* Line 1592, Address: 0x1025b50 */


    case 128:
      chk_d1 = dircol_l2(&actwk[0]); /* Line 1596, Address: 0x1025b58 */

      if (chk_d1 < 0) { /* Line 1598, Address: 0x1025b6c */
        actwk[0].xposi.w.h -= chk_d1; /* Line 1599, Address: 0x1025b80 */
        actwk[0].xspeed.w = 0; /* Line 1600, Address: 0x1025b98 */
      }
      chk_d1 = dircol_r2(&actwk[0]); /* Line 1602, Address: 0x1025ba0 */

      if (chk_d1 < 0) { /* Line 1604, Address: 0x1025bb4 */
        actwk[0].xposi.w.h += chk_d1; /* Line 1605, Address: 0x1025bc8 */
        actwk[0].mspeed.w = 0; /* Line 1606, Address: 0x1025be0 */
      }

      dircol_u(&actwk[0], &chk_d0, &chk_d1, &tmp_d3); /* Line 1609, Address: 0x1025be8 */
      chk_d3 = tmp_d3; /* Line 1610, Address: 0x1025c04 */

      if (chk_d1 >= 0) break; /* Line 1612, Address: 0x1025c18 */
      actwk[0].yposi.w.h -= chk_d1; /* Line 1613, Address: 0x1025c2c */
      if ((chk_d3 + 32 & 64) == 0) { /* Line 1614, Address: 0x1025c44 */
        actwk[0].yspeed.w = 0; /* Line 1615, Address: 0x1025c5c */
        break; /* Line 1616, Address: 0x1025c64 */
      }
      actwk[0].direc.b.h = chk_d3; /* Line 1618, Address: 0x1025c6c */
      jumpcolsub0(); /* Line 1619, Address: 0x1025c74 */
      actwk[0].mspeed.w = actwk[0].yspeed.w; /* Line 1620, Address: 0x1025c7c */
      if (chk_d3 < 0) actwk[0].mspeed.w = -actwk[0].mspeed.w; /* Line 1621, Address: 0x1025c8c */
      break; /* Line 1622, Address: 0x1025cc0 */


    case 192:
      chk_d1 = dircol_r2(&actwk[0]); /* Line 1626, Address: 0x1025cc8 */

      if (chk_d1 < 0) { /* Line 1628, Address: 0x1025cdc */
        actwk[0].xposi.w.h += chk_d1; /* Line 1629, Address: 0x1025cf0 */
        actwk[0].xspeed.w = 0; /* Line 1630, Address: 0x1025d08 */
        actwk[0].mspeed.w = actwk[0].xspeed.w; /* Line 1631, Address: 0x1025d10 */
        break; /* Line 1632, Address: 0x1025d20 */
      }
      dircol_u(&actwk[0], &chk_d0, &chk_d1, &tmp_d3); /* Line 1634, Address: 0x1025d28 */

      if (chk_d1 < 0) { /* Line 1636, Address: 0x1025d44 */
        actwk[0].yposi.w.h -= chk_d1; /* Line 1637, Address: 0x1025d58 */
        if (actwk[0].yspeed.w < 0) actwk[0].yspeed.w = 0; /* Line 1638, Address: 0x1025d70 */
        break; /* Line 1639, Address: 0x1025d90 */
      }

      if (actwk[0].yspeed.w) break; /* Line 1642, Address: 0x1025d98 */
      dircol_d(&actwk[0], &chk_d0, &chk_d1, &tmp_d3); /* Line 1643, Address: 0x1025db0 */
      chk_d3 = tmp_d3; /* Line 1644, Address: 0x1025dcc */

      if (chk_d1 >= 0) break; /* Line 1646, Address: 0x1025de0 */
      actwk[0].yposi.w.h += chk_d1; /* Line 1647, Address: 0x1025df4 */
      actwk[0].direc.b.h = chk_d3; /* Line 1648, Address: 0x1025e0c */
      jumpcolsub(); /* Line 1649, Address: 0x1025e14 */
      actwk[0].mstno.b.h = 0; /* Line 1650, Address: 0x1025e1c */
      actwk[0].yspeed.w = 0; /* Line 1651, Address: 0x1025e24 */
      actwk[0].mspeed.w = actwk[0].xspeed.w; /* Line 1652, Address: 0x1025e2c */
      break;
  }



} /* Line 1658, Address: 0x1025e3c */




void jumpcolsub() {
  actwk[0].cddat &= 205; /* Line 1664, Address: 0x1025e60 */
  if ((actwk[0].cddat & 4) == 0) return; /* Line 1665, Address: 0x1025e74 */
  actwk[0].cddat &= 251; /* Line 1666, Address: 0x1025e8c */
  if (chibi_flag != 0) { /* Line 1667, Address: 0x1025ea0 */
    actwk[0].sprvsize = 10; /* Line 1668, Address: 0x1025eb4 */
    actwk[0].sprhs = 5; /* Line 1669, Address: 0x1025ec0 */
  } else { /* Line 1670, Address: 0x1025ecc */
    actwk[0].sprvsize = 19; /* Line 1671, Address: 0x1025ed4 */
    actwk[0].sprhs = 9; /* Line 1672, Address: 0x1025ee0 */
    actwk[0].yposi.w.h -= 5; /* Line 1673, Address: 0x1025eec */
  }
  actwk[0].mstno.b.h = 0; /* Line 1675, Address: 0x1025f00 */


  actwk[0].actfree[18] = 0; /* Line 1678, Address: 0x1025f08 */
  emyscorecnt = 0; /* Line 1679, Address: 0x1025f10 */
} /* Line 1680, Address: 0x1025f18 */


void jumpcolsub0() {
  actwk[0].cddat &= 205; /* Line 1684, Address: 0x1025f20 */
  actwk[0].actfree[18] = 0; /* Line 1685, Address: 0x1025f34 */
  emyscorecnt = 0; /* Line 1686, Address: 0x1025f3c */
} /* Line 1687, Address: 0x1025f44 */



void play00damage() { /* Line 1691, Address: 0x1025f50 */
  speedset2(&actwk[0]); /* Line 1692, Address: 0x1025f58 */
  actwk[0].yspeed.w += 48; /* Line 1693, Address: 0x1025f68 */
  if (actwk[0].cddat & 64) actwk[0].yspeed.w -= 32; /* Line 1694, Address: 0x1025f7c */
  play00damage_sub(); /* Line 1695, Address: 0x1025fa8 */
  limitchk(); /* Line 1696, Address: 0x1025fb0 */
  playposiwkset(); /* Line 1697, Address: 0x1025fb8 */
  patchgmain(); /* Line 1698, Address: 0x1025fc0 */
  actionsub(&actwk[0]); /* Line 1699, Address: 0x1025fc8 */
} /* Line 1700, Address: 0x1025fd8 */


void play00damage_sub() { /* Line 1703, Address: 0x1025ff0 */
  if (scralim_down + 224 < actwk[0].yposi.w.h) { /* Line 1704, Address: 0x1025ff8 */
    playdieset(&actwk[0]); /* Line 1705, Address: 0x1026028 */
    return; /* Line 1706, Address: 0x1026038 */
  }
  jumpcolchk(); /* Line 1708, Address: 0x1026040 */
  if (actwk[0].cddat & 2) return; /* Line 1709, Address: 0x1026048 */
  actwk[0].yspeed.w = actwk[0].xspeed.w = actwk[0].mspeed.w = 0; /* Line 1710, Address: 0x1026060 */
  actwk[0].mstno.b.h = 0; /* Line 1711, Address: 0x1026088 */
  actwk[0].r_no0 = -2; /* Line 1712, Address: 0x1026090 */
  *(short*)&actwk[0].actfree[6] = 120; /* Line 1713, Address: 0x10260a4 */
} /* Line 1714, Address: 0x10260b0 */



void play00die() { /* Line 1718, Address: 0x10260c0 */
  play00die_sub(); /* Line 1719, Address: 0x10260c8 */
  speedset(&actwk[0]); /* Line 1720, Address: 0x10260d0 */
  playposiwkset(); /* Line 1721, Address: 0x10260e0 */
  patchgmain(); /* Line 1722, Address: 0x10260e8 */
  actionsub(&actwk[0]); /* Line 1723, Address: 0x10260f0 */
} /* Line 1724, Address: 0x1026100 */


void play00die_sub() { /* Line 1727, Address: 0x1026110 */
  sprite_status* new_actwk;

  if (scralim_down + 256 >= actwk[0].yposi.w.h) return; /* Line 1730, Address: 0x1026118 */
  actwk[0].yspeed.w = -56; /* Line 1731, Address: 0x1026148 */
  actwk[0].r_no0 += 2; /* Line 1732, Address: 0x1026154 */
  pltime_f = 0; /* Line 1733, Address: 0x1026168 */
  ++pl_suu_f; /* Line 1734, Address: 0x1026170 */
  if (pl_suu-- < 0) pl_suu = 0; /* Line 1735, Address: 0x1026184 */

  if (actwk[0].mstno.b.h == 43 || ta_flag == 0) { /* Line 1737, Address: 0x10261bc */
    actwkchk(&new_actwk); /* Line 1738, Address: 0x10261ec */
    new_actwk->actno = 59; /* Line 1739, Address: 0x10261f8 */
    *(short*)&actwk[0].actfree[16] = 480; /* Line 1740, Address: 0x1026204 */
    if (pl_suu == 0) return; /* Line 1741, Address: 0x1026210 */
  } else { /* Line 1742, Address: 0x1026224 */
    pl_suu = 0; /* Line 1743, Address: 0x102622c */
  }
  actwk[0].actfree[16] = 60; /* Line 1745, Address: 0x1026234 */
} /* Line 1746, Address: 0x1026240 */



void play00erase() { /* Line 1750, Address: 0x1026250 */
  if (*(short*)&actwk[0].actfree[16] == 0) return; /* Line 1751, Address: 0x1026258 */
  --actwk[0].actfree[16]; /* Line 1752, Address: 0x102626c */
  if (*(short*)&actwk[0].actfree[16] != 0) return; /* Line 1753, Address: 0x1026280 */
  gameflag.w = 1; /* Line 1754, Address: 0x1026294 */




  flagwkclr(); /* Line 1759, Address: 0x10262a0 */
  flowercnt[0] = flowercnt[1] = flowercnt[2] = tv_flag = 0; /* Line 1760, Address: 0x10262a8 */
  if (markerno == 0 && time_flag == 1) play_start &= 253; /* Line 1761, Address: 0x10262d4 */


  if (pl_suu != 0) { /* Line 1764, Address: 0x1026314 */
    if (time_flag == 1) { /* Line 1765, Address: 0x1026328 */
      if (markerno != 0) plflag = 1; /* Line 1766, Address: 0x1026340 */
    } else { /* Line 1767, Address: 0x1026360 */
      plflag = 0; /* Line 1768, Address: 0x1026368 */
    }
  }
  sub_sync(14); /* Line 1771, Address: 0x1026370 */

} /* Line 1773, Address: 0x102637c */









void loopchk() {} /* Line 1783, Address: 0x1026390 */



void st7_x() { /* Line 1787, Address: 0x10263a0 */
  short y_position;


  if (actwk[0].yspeed.w >= 0) { /* Line 1791, Address: 0x10263a8 */
    y_position = actwk[0].yposi.w.h; /* Line 1792, Address: 0x10263c0 */
    if (actwk[0].xposi.w.h < 128) { /* Line 1793, Address: 0x10263e4 */

      if (y_position < 56) actwk[0].actflg |= 64; /* Line 1795, Address: 0x1026404 */
      else if (y_position >= 128) actwk[0].actflg &= 191; /* Line 1796, Address: 0x1026434 */
    } /* Line 1797, Address: 0x102645c */
    else if (y_position < 56) actwk[0].actflg &= 191; /* Line 1798, Address: 0x1026464 */
    else if (y_position >= 128) actwk[0].actflg |= 64; /* Line 1799, Address: 0x1026494 */
  }
} /* Line 1801, Address: 0x10264bc */





void patchgmain() { /* Line 1807, Address: 0x10264d0 */
  char pat_index;
  unsigned char* pat_pointer;

  if (actwk[0].mstno.b.h != actwk[0].mstno.b.l) { /* Line 1811, Address: 0x10264e0 */
    actwk[0].mstno.b.l = actwk[0].mstno.b.h; /* Line 1812, Address: 0x1026508 */
    actwk[0].patcnt = actwk[0].pattim = 0; /* Line 1813, Address: 0x1026518 */
  }

  pat_index = little_patchg(actwk[0].mstno.b.h); /* Line 1816, Address: 0x102652c */
  pat_pointer = playchg[pat_index]; /* Line 1817, Address: 0x1026544 */
  if (*pat_pointer >= 128) { playrunchg(*pat_pointer); return; } /* Line 1818, Address: 0x1026560 */

  actwk[0].actflg = (actwk[0].actflg & 252) | (actwk[0].cddat & 1); /* Line 1820, Address: 0x1026588 */
  if (--actwk[0].pattim >= 0) return; /* Line 1821, Address: 0x10265b8 */
  actwk[0].pattim = *pat_pointer; /* Line 1822, Address: 0x10265e8 */
  patchgmain2(pat_pointer); /* Line 1823, Address: 0x10265f4 */
} /* Line 1824, Address: 0x1026600 */


void patchgmain2(unsigned char* pat_pointer) { /* Line 1827, Address: 0x1026620 */
  unsigned char pat_no;

  if ((pat_no = actwk[0].patcnt) < 253) { /* Line 1830, Address: 0x102662c */
    actwk[0].patno = pat_no; /* Line 1831, Address: 0x102665c */
    ++actwk[0].patcnt; /* Line 1832, Address: 0x1026664 */
  } /* Line 1833, Address: 0x1026678 */
  else {

    switch (pat_no) { /* Line 1836, Address: 0x1026680 */
      case 255:
        actwk[0].patcnt = 1; /* Line 1838, Address: 0x10266b0 */
        actwk[0].patno = *pat_pointer; /* Line 1839, Address: 0x10266bc */
        break; /* Line 1840, Address: 0x10266cc */
      case 254:
        actwk[0].patno = pat_pointer[actwk[0].patcnt /* Line 1842, Address: 0x10266d4 */
                       - pat_pointer[actwk[0].patcnt + 2]];
        actwk[0].patcnt = actwk[0].patcnt /* Line 1844, Address: 0x102671c */
                        - pat_pointer[actwk[0].patcnt + 2];
        break; /* Line 1846, Address: 0x102675c */
      case 253:
        actwk[0].mstno.b.h = pat_pointer[actwk[0].patcnt + 2]; /* Line 1848, Address: 0x1026764 */
        break;
    }
  }


} /* Line 1854, Address: 0x1026788 */



void playrunchg(unsigned char pat_no) { /* Line 1858, Address: 0x10267a0 */
  unsigned char direction, cal_data, chara_data;
  unsigned char* pat_pointer;
  short cal_speed;

  if (++actwk[0].pattim >= 0) return; /* Line 1863, Address: 0x10267c0 */
  if (pat_no != 255) { playrunchg2(pat_no); return; } /* Line 1864, Address: 0x10267f0 */
  if (chibi_flag != 0) { little_runchg(); return; } /* Line 1865, Address: 0x1026818 */

  cal_data = 0; /* Line 1867, Address: 0x102683c */
  direction = actwk[0].direc.b.h; /* Line 1868, Address: 0x1026840 */
  chara_data = actwk[0].cddat & 1; /* Line 1869, Address: 0x102684c */
  if (chara_data == 0) direction = 255 - direction; /* Line 1870, Address: 0x1026864 */
  if (actwk[0].actfree[2] == 0) direction += 16; /* Line 1871, Address: 0x1026884 */
  else direction += 8; /* Line 1872, Address: 0x10268ac */
  if (direction < 0) cal_data = 3; /* Line 1873, Address: 0x10268b4 */

  actwk[0].actflg &= 252; /* Line 1875, Address: 0x10268d4 */
  chara_data ^= cal_data; /* Line 1876, Address: 0x10268e8 */
  actwk[0].actflg |= chara_data; /* Line 1877, Address: 0x10268f0 */
  if ((actwk[0].cddat & 32) == 0) { playrunchg3(253); return; } /* Line 1878, Address: 0x1026904 */

  if ((cal_speed = actwk[0].mspeed.w) < 0) cal_speed = -cal_speed; /* Line 1880, Address: 0x1026930 */

  if (actwk[0].actfree[2] & 2) { /* Line 1882, Address: 0x102696c */
    direction = (direction >> 4) % 16; /* Line 1883, Address: 0x1026984 */
    direction *= 2; /* Line 1884, Address: 0x1026994 */
    direction &= 14; /* Line 1885, Address: 0x102699c */
    pat_pointer = plchg53; /* Line 1886, Address: 0x10269a4 */
  } else { /* Line 1887, Address: 0x10269ac */
    direction = direction >> 4; /* Line 1888, Address: 0x10269b4 */
    direction &= 6; /* Line 1889, Address: 0x10269bc */
    if (cal_speed >= 2561) pat_pointer = plchg49; /* Line 1890, Address: 0x10269c4 */
    else if (cal_speed >= 1537) pat_pointer = plchg01; /* Line 1891, Address: 0x10269e8 */
    else {
      pat_pointer = plchg00; /* Line 1893, Address: 0x1026a0c */
      direction += direction / 2; /* Line 1894, Address: 0x1026a14 */
    }
  }

  cal_speed = 2048 - cal_speed; /* Line 1898, Address: 0x1026a40 */
  if (cal_speed < 0) cal_speed = 0; /* Line 1899, Address: 0x1026a60 */
  cal_speed /= 256; /* Line 1900, Address: 0x1026a74 */
  actwk[0].pattim = cal_speed; /* Line 1901, Address: 0x1026a94 */
  patchgmain2(pat_pointer); /* Line 1902, Address: 0x1026aa0 */
  actwk[0].xposi.w.h += direction * 2; /* Line 1903, Address: 0x1026aac */
} /* Line 1904, Address: 0x1026ad0 */


void playrunchg2(unsigned char pat_no) { /* Line 1907, Address: 0x1026b00 */
  unsigned char direction;
  unsigned char* pat_pointer;
  short cal_speed;

  if (pat_no != 254) playrunchg3(pat_no); /* Line 1912, Address: 0x1026b18 */
  if ((cal_speed = actwk[0].mspeed.w) < 0) cal_speed = -cal_speed; /* Line 1913, Address: 0x1026b40 */
  if (chibi_flag != 0) pat_pointer = plchg35; /* Line 1914, Address: 0x1026b7c */
  else {
    if (actwk[0].actfree[2] & 2) { /* Line 1916, Address: 0x1026ba0 */
      direction = actwk[0].direc.b.h; /* Line 1917, Address: 0x1026bb8 */
      direction = direction + 16 & 192; /* Line 1918, Address: 0x1026bc8 */
      if (direction != 0) pat_pointer = plchg54; /* Line 1919, Address: 0x1026bdc */
      else pat_pointer = plchg03; /* Line 1920, Address: 0x1026bf8 */
    } /* Line 1921, Address: 0x1026c00 */
    else if (cal_speed < 1536) pat_pointer = plchg02; /* Line 1922, Address: 0x1026c08 */
    else pat_pointer = plchg03; /* Line 1923, Address: 0x1026c2c */
  }


  cal_speed = 1024 - cal_speed; /* Line 1927, Address: 0x1026c34 */
  if (cal_speed < 0) cal_speed = 0; /* Line 1928, Address: 0x1026c54 */
  cal_speed /= 256; /* Line 1929, Address: 0x1026c68 */
  actwk[0].pattim = cal_speed; /* Line 1930, Address: 0x1026c88 */
  actwk[0].actflg &= 252; /* Line 1931, Address: 0x1026c94 */
  actwk[0].actflg |= actwk[0].cddat & 1; /* Line 1932, Address: 0x1026ca8 */
  patchgmain2(pat_pointer); /* Line 1933, Address: 0x1026cd0 */
} /* Line 1934, Address: 0x1026cdc */


void playrunchg3(unsigned char pat_no) { /* Line 1937, Address: 0x1026d00 */
  unsigned char* pat_pointer;
  short cal_speed;

  if (pat_no != 253) { playetc_chg(); return; } /* Line 1941, Address: 0x1026d14 */
  if ((cal_speed = actwk[0].mspeed.w) >= 0) cal_speed = -cal_speed; /* Line 1942, Address: 0x1026d38 */
  cal_speed += 2048; /* Line 1943, Address: 0x1026d74 */
  if (cal_speed < 0) cal_speed = 0; /* Line 1944, Address: 0x1026d80 */
  cal_speed = cal_speed >> 6; /* Line 1945, Address: 0x1026d94 */
  actwk[0].pattim = cal_speed; /* Line 1946, Address: 0x1026da0 */
  if (chibi_flag != 0) pat_pointer = plchg39; /* Line 1947, Address: 0x1026dac */
  else pat_pointer = plchg04; /* Line 1948, Address: 0x1026dd0 */
  actwk[0].actflg &= 252; /* Line 1949, Address: 0x1026dd8 */
  actwk[0].actflg |= actwk[0].cddat & 1; /* Line 1950, Address: 0x1026dec */
  patchgmain2(pat_pointer); /* Line 1951, Address: 0x1026e14 */
} /* Line 1952, Address: 0x1026e20 */


void playetc_chg() { /* Line 1955, Address: 0x1026e40 */
  char pat_index;
  unsigned char* pat_pointer;

  pat_index = little_patchg(actwk[0].mstno.b.h); /* Line 1959, Address: 0x1026e50 */
  pat_pointer = playchg[pat_index]; /* Line 1960, Address: 0x1026e68 */

  actwk[0].patno = pat_pointer[actwk[0].patcnt + 1]; /* Line 1962, Address: 0x1026e84 */
  actwk[0].pattim = 0; /* Line 1963, Address: 0x1026ea4 */
} /* Line 1964, Address: 0x1026eac */



void little_runchg() { /* Line 1968, Address: 0x1026ed0 */
  unsigned char direction;
  unsigned char* pat_pointer;
  short cal_speed;

  direction = actwk[0].direc.b.h; /* Line 1973, Address: 0x1026ee4 */
  if (actwk[0].cddat == 0) direction = 255 - direction; /* Line 1974, Address: 0x1026ef0 */
  direction += 16; /* Line 1975, Address: 0x1026f1c */

  actwk[0].actflg &= 252; /* Line 1977, Address: 0x1026f24 */
  actwk[0].actflg |= actwk[0].cddat & 1; /* Line 1978, Address: 0x1026f38 */
  if ((direction += 48) >= 96) { /* Line 1979, Address: 0x1026f60 */
    actwk[0].cddat |= 4; /* Line 1980, Address: 0x1026f7c */
    actwk[0].sprvsize = 10; /* Line 1981, Address: 0x1026f90 */
    actwk[0].sprhs = 5; /* Line 1982, Address: 0x1026f9c */
    playrunchg2(254); /* Line 1983, Address: 0x1026fa8 */
    return; /* Line 1984, Address: 0x1026fb4 */
  }

  if ((cal_speed = actwk[0].mspeed.w) < 0) cal_speed = -cal_speed; /* Line 1987, Address: 0x1026fbc */
  if (cal_speed >= 1536) pat_pointer = plchg34; /* Line 1988, Address: 0x1026ff8 */
  else pat_pointer = plchg33; /* Line 1989, Address: 0x102701c */
  cal_speed = 2048 - cal_speed; /* Line 1990, Address: 0x1027024 */
  if (cal_speed < 0) cal_speed = 0; /* Line 1991, Address: 0x1027044 */
  cal_speed /= 256; /* Line 1992, Address: 0x1027058 */
  actwk[0].pattim = cal_speed; /* Line 1993, Address: 0x1027078 */
  patchgmain2(pat_pointer); /* Line 1994, Address: 0x1027084 */
} /* Line 1995, Address: 0x1027090 */



char little_patchg(char pat_index) { /* Line 1999, Address: 0x10270b0 */
  char tbl[80] = /* Line 2000, Address: 0x10270b8 */
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

  if (chibi_flag != 0) return tbl[pat_index]; /* Line 2012, Address: 0x10270ec */
  return pat_index; /* Line 2013, Address: 0x102711c */
} /* Line 2014, Address: 0x1027120 */


























void playwrt() {}/* Line 2041, Address: 0x1027130 */





unsigned char frip_spd(int* cal_jump, unsigned char* cal_direc) { /* Line 2047, Address: 0x1027140 */
  short cal_x;
  char ride_no;

  ride_no = actwk[0].actfree[19]; /* Line 2051, Address: 0x1027158 */
  if (actwk[ride_no].actno != 30) return 255; /* Line 2052, Address: 0x1027168 */

  actwk[ride_no].mstno.b.h = 1; /* Line 2054, Address: 0x10271a8 */
  *cal_direc = atan_sonic( /* Line 2055, Address: 0x10271d0 */
    actwk[ride_no].xposi.w.h - actwk[0].xposi.w.h,
    actwk[ride_no].yposi.w.h + 24 - actwk[0].yposi.w.h
  );
  cal_x = (actwk[0].xposi.w.h - actwk[ride_no].xposi.w.h) + actwk[ride_no].sprhsize; /* Line 2059, Address: 0x1027278 */

  if ((actwk[ride_no].cddat & 1) == 0) cal_x = 64 - cal_x; /* Line 2061, Address: 0x10272fc */

  *cal_jump = -((cal_x * 512) / 64) - 2560; /* Line 2063, Address: 0x1027350 */
  return 0; /* Line 2064, Address: 0x102738c */
} /* Line 2065, Address: 0x1027390 */
