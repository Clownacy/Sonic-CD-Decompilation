#include "..\EQU.H"
#include "PLAYSP3.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\FCOL.H"
#include "..\LOADER2.H"
#include "SCR31A.H"

static short fcol3a[17] = { 15, 316, 326, 411, 430, 131, 132, 137, 138, 119, 118, 128, 127, 126, 125, 124, 130 };
static short fcol3b[3] = { 1, 325, 326 };
static short fcol3c[17] = { 15, 316, 326, 0, 0, 131, 132, 137, 138, 119, 118, 128, 127, 126, 125, 124, 130 };
static short fcol3d[17] = { 15, 316, 326, 357, 358, 131, 132, 137, 138, 119, 118, 128, 127, 126, 125, 124, 130 };
static short* fcol_tbl[4] = { fcol3b, fcol3a, fcol3d, fcol3c };
static unsigned char bump_sound_off;



void playsp() { /* Line 18, Address: 0x101e0b0 */
  if (actwk[0].mstno.b.h != 43) boyo(); /* Line 19, Address: 0x101e0b8 */
} /* Line 20, Address: 0x101e0dc */



void boyo() { /* Line 24, Address: 0x101e0f0 */
  unsigned char direc_speed;

  direc_speed = (char)atan_sonic(actwk[0].xspeed.w, actwk[0].yspeed.w); /* Line 27, Address: 0x101e0fc */

  direc_speed = direc_speed - 32 & 192; /* Line 29, Address: 0x101e124 */
  switch (direc_speed) { /* Line 30, Address: 0x101e138 */

    case 0:
      if (!bycol_sub0(actwk[0].xposi.w.h - (short)actwk[0].sprhs, actwk[0].yposi.w.h + (short)actwk[0].sprvsize)) { /* Line 33, Address: 0x101e170 */

        bycol_sub0(actwk[0].xposi.w.h + (short)actwk[0].sprhs, actwk[0].yposi.w.h + (short)actwk[0].sprvsize); /* Line 35, Address: 0x101e1e0 */
      }
      break; /* Line 37, Address: 0x101e248 */

    case 128:
      if (!bycol_sub0(actwk[0].xposi.w.h - (short)actwk[0].sprhs, actwk[0].yposi.w.h - (short)actwk[0].sprvsize)) { /* Line 40, Address: 0x101e250 */

        bycol_sub0(actwk[0].xposi.w.h + (short)actwk[0].sprhs, actwk[0].yposi.w.h - (short)actwk[0].sprvsize); /* Line 42, Address: 0x101e2c0 */
      }
      break; /* Line 44, Address: 0x101e328 */

    case 192:
      if (!bycol_sub0(actwk[0].xposi.w.h + (short)actwk[0].sprhs, actwk[0].yposi.w.h - (short)(actwk[0].sprvsize - 6))) { /* Line 47, Address: 0x101e330 */


        bycol_sub0(actwk[0].xposi.w.h + (short)actwk[0].sprhs, actwk[0].yposi.w.h + (short)actwk[0].sprvsize); /* Line 50, Address: 0x101e3ac */
      }
      break; /* Line 52, Address: 0x101e414 */

    case 64:
      if (!bycol_sub0(actwk[0].xposi.w.h - (short)actwk[0].sprhs, actwk[0].yposi.w.h - (short)(actwk[0].sprvsize - 6))) { /* Line 55, Address: 0x101e41c */


        bycol_sub0(actwk[0].xposi.w.h - (short)actwk[0].sprhs, actwk[0].yposi.w.h + (short)actwk[0].sprvsize); /* Line 58, Address: 0x101e498 */
      }
      break;
  }


} /* Line 64, Address: 0x101e500 */



















char bycol_sub0(short cal_x, short cal_y) { /* Line 84, Address: 0x101e520 */
  void(*jump_no[16])(short, short, short, short) = { /* Line 85, Address: 0x101e544 */
    &bob, &bob, &bob_s, &bob_s, &bob5, &bob0, &bob1, &bob1,
    &bob4, &bob3, &bob3, &bob3, &bob2, &bob0, &bob0, &bob_s0
  };
  unsigned char now_time;
  short block_no, block_back, *fcol3, i;

  block_no = block_back = scramapad(&actwk[0], cal_x, cal_y); /* Line 92, Address: 0x101e578 */
  if ((block_no &= 2047) == 0) { bump_sound_off = 1; return 0; } /* Line 93, Address: 0x101e5a8 */
  if ((now_time = time_flag & 127) == 2) /* Line 94, Address: 0x101e5e4 */
    now_time = now_time + generate_flag; /* Line 95, Address: 0x101e610 */
  fcol3 = fcol_tbl[now_time]; /* Line 96, Address: 0x101e62c */
  for (i = 0; i <= *fcol3; ++i) if (block_no == fcol3[i + 1]) goto label1; /* Line 97, Address: 0x101e644 */
  bump_sound_off = 1; /* Line 98, Address: 0x101e6ac */
  return 0; /* Line 99, Address: 0x101e6b8 */

label1:
  if (actwk[0].r_no0 == 4) { /* Line 102, Address: 0x101e6c4 */
    actwk[0].r_no0 -= 2; /* Line 103, Address: 0x101e6dc */
    ((short*)&actwk[0])[26] = 120; /* Line 104, Address: 0x101e6f0 */
  }
  col_y.b.h = 0; /* Line 106, Address: 0x101e6fc */
  jump_no[i](i, cal_x, cal_y, block_back); /* Line 107, Address: 0x101e704 */
  if (i >= 2) { /* Line 108, Address: 0x101e730 */
    if (bump_sound_off) { /* Line 109, Address: 0x101e744 */
      if (i == 2 || i == 3) soundset(190); /* Line 110, Address: 0x101e754 */
      else soundset(181); /* Line 111, Address: 0x101e790 */
    }
    bump_sound_off = 0; /* Line 113, Address: 0x101e79c */
  }
  if (col_y.b.h != 0) return 0; /* Line 115, Address: 0x101e7a4 */
  return 1; /* Line 116, Address: 0x101e7c8 */
} /* Line 117, Address: 0x101e7cc */


void bob(short i, short cal_x, short cal_y, short block_back) { /* Line 120, Address: 0x101e7f0 */
  short tmp_sin, tmp_cos, tmp_x, tmp_y;
  int cal_sin, cal_cos;
  sprite_status* new_actwk;

  cal_y = (unsigned short)cal_y & 65520; /* Line 125, Address: 0x101e818 */
  if (i == 0) cal_y += 16; /* Line 126, Address: 0x101e834 */
  cal_x = (unsigned short)cal_x & 65520; /* Line 127, Address: 0x101e854 */
  if (!(block_back & 2048)) cal_x += 16; /* Line 128, Address: 0x101e870 */
  tmp_x = cal_x, tmp_y = cal_y; /* Line 129, Address: 0x101e894 */
  sinset((char)atan_sonic(cal_x - actwk[0].xposi.w.h, cal_y - actwk[0].yposi.w.h), &tmp_sin, &tmp_cos); /* Line 130, Address: 0x101e8ac */

  cal_sin = tmp_sin * -1792 >> 8; /* Line 132, Address: 0x101e920 */
  cal_cos = tmp_cos * -1792 >> 8; /* Line 133, Address: 0x101e93c */
  actwk[0].xspeed.w = cal_cos; /* Line 134, Address: 0x101e958 */
  actwk[0].yspeed.w = cal_sin; /* Line 135, Address: 0x101e968 */
  actwk[0].cddat |= 2; /* Line 136, Address: 0x101e978 */
  actwk[0].cddat &= 207; /* Line 137, Address: 0x101e98c */
  actwk[0].actfree[18] = 0; /* Line 138, Address: 0x101e9a0 */
  if (actwkchk(&new_actwk) == 0) { /* Line 139, Address: 0x101e9a8 */
    new_actwk->actno = 41; /* Line 140, Address: 0x101e9bc */
    new_actwk->xposi.w.h = tmp_x; /* Line 141, Address: 0x101e9c8 */
    new_actwk->yposi.w.h = tmp_y; /* Line 142, Address: 0x101e9d0 */
  }

  block_wrt(0, tmp_x, tmp_y); /* Line 145, Address: 0x101e9d8 */
  block_wrt(0, tmp_x -= 16, tmp_y); /* Line 146, Address: 0x101e9ec */
  block_wrt(0, tmp_x, tmp_y -= 16); /* Line 147, Address: 0x101ea14 */
  block_wrt(0, tmp_x += 16, tmp_y); /* Line 148, Address: 0x101ea3c */
  sub_sync(146); /* Line 149, Address: 0x101ea64 */
} /* Line 150, Address: 0x101ea70 */


void bob_s(short i, short cal_x, short cal_y, short block_back) { /* Line 153, Address: 0x101ea90 */
  short tmp_sin, tmp_cos;
  int cal_sin, cal_cos;

  cal_y = (unsigned short)cal_y & 65528; /* Line 157, Address: 0x101eab0 */
  cal_x = (unsigned short)cal_x & 65528; /* Line 158, Address: 0x101eacc */
  sinset((char)atan_sonic(cal_x - actwk[0].xposi.w.h, cal_y - actwk[0].yposi.w.h), &tmp_sin, &tmp_cos); /* Line 159, Address: 0x101eae8 */

  cal_sin = tmp_sin * -1792 >> 9; /* Line 161, Address: 0x101eb5c */
  cal_cos = tmp_cos * -1792 >> 9; /* Line 162, Address: 0x101eb78 */
  actwk[0].xspeed.w = cal_cos; /* Line 163, Address: 0x101eb94 */
  actwk[0].yspeed.w = cal_sin; /* Line 164, Address: 0x101eba4 */
  bob_j(); /* Line 165, Address: 0x101ebb4 */
  block_back = block_back, i = i; /* Line 166, Address: 0x101ebbc */
} /* Line 167, Address: 0x101ebcc */


void bob_j() {
  actwk[0].cddat |= 2; /* Line 171, Address: 0x101ebf0 */
  actwk[0].cddat &= 207; /* Line 172, Address: 0x101ec04 */
  actwk[0].actfree[18] = 0; /* Line 173, Address: 0x101ec18 */
} /* Line 174, Address: 0x101ec20 */


void bob0(short i, short cal_x, short cal_y, short block_back) { /* Line 177, Address: 0x101ec30 */
  if (actwk[0].yspeed.w >= 0) actwk[0].yspeed.w = -1792; /* Line 178, Address: 0x101ec48 */
  else actwk[0].yspeed.w = 1792; /* Line 179, Address: 0x101ec74 */
  bob_j(); /* Line 180, Address: 0x101ec80 */
  i = i, cal_x = cal_x, cal_y = cal_y, block_back = block_back; /* Line 181, Address: 0x101ec88 */
} /* Line 182, Address: 0x101eca8 */


void bob1(short i, short cal_x, short cal_y, short block_back) { /* Line 185, Address: 0x101ecc0 */
  if (actwk[0].xspeed.w >= 0) actwk[0].xspeed.w = -1792; /* Line 186, Address: 0x101ecd8 */
  else actwk[0].xspeed.w = 1792; /* Line 187, Address: 0x101ed04 */
  bob_j(); /* Line 188, Address: 0x101ed10 */
  i = i, cal_x = cal_x, cal_y = cal_y, block_back = block_back; /* Line 189, Address: 0x101ed18 */
} /* Line 190, Address: 0x101ed38 */


void bob_s0(short i, short cal_x, short cal_y, short block_back) { /* Line 193, Address: 0x101ed50 */
  short tmp_sin, tmp_cos;
  int cal_sin, cal_cos;

  cal_y = (unsigned short)cal_y & 65528; /* Line 197, Address: 0x101ed70 */
  cal_x = (unsigned short)cal_x & 65528; /* Line 198, Address: 0x101ed8c */
  sinset((char)atan_sonic(cal_x - actwk[0].xposi.w.h, cal_y - actwk[0].yposi.w.h), &tmp_sin, &tmp_cos); /* Line 199, Address: 0x101eda8 */

  cal_sin = tmp_sin * -1792 >> 8; /* Line 201, Address: 0x101ee1c */
  cal_cos = tmp_cos * -1792 >> 8; /* Line 202, Address: 0x101ee38 */
  actwk[0].xspeed.w = cal_cos; /* Line 203, Address: 0x101ee54 */
  actwk[0].yspeed.w = cal_sin; /* Line 204, Address: 0x101ee64 */
  bob_j(); /* Line 205, Address: 0x101ee74 */
  block_back = block_back, i = i; /* Line 206, Address: 0x101ee7c */
} /* Line 207, Address: 0x101ee8c */


void bob2(short i, short cal_x, short cal_y, short block_back) { /* Line 210, Address: 0x101eeb0 */
  if (((unsigned short)cal_x & 15) < 8) { /* Line 211, Address: 0x101eec8 */
    if (block_back & 2048) bob0(i, cal_x, cal_y, block_back); /* Line 212, Address: 0x101eee4 */
    else bob1(i, cal_x, cal_y, block_back); /* Line 213, Address: 0x101ef1c */
  } else { /* Line 214, Address: 0x101ef34 */
    if (block_back & 2048) bob1(i, cal_x, cal_y, block_back); /* Line 215, Address: 0x101ef3c */
    else bob0(i, cal_x, cal_y, block_back); /* Line 216, Address: 0x101ef74 */
  }
} /* Line 218, Address: 0x101ef8c */


void bob3(short i, short cal_x, short cal_y, short block_back) { /* Line 221, Address: 0x101efa0 */
  static unsigned char bydcol0[16] = {
    1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6
  };
  static unsigned char bydcol1[16] = {
    6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 11, 11
  };
  static unsigned char bydcol2[16] = {
    11, 12, 12, 12, 13, 13, 13, 14, 14, 14, 15, 15, 15, 16, 16, 16
  };
  unsigned char* tbl[3] = { bydcol0, bydcol1, bydcol2 }; /* Line 231, Address: 0x101efc8 */
  unsigned char* bydcol;
  unsigned char cal_direc;
  short tmp_sin, tmp_cos;
  int cal_sin, cal_cos;

  if ((i -= 9) >= 0) { /* Line 237, Address: 0x101efec */
    bydcol = tbl[i]; /* Line 238, Address: 0x101f010 */
    cal_y = (unsigned short)cal_y & 15; /* Line 239, Address: 0x101f028 */
    cal_x = (unsigned short)cal_x & 15; /* Line 240, Address: 0x101f044 */
    if (!(block_back & 2048)) cal_x = 15 - cal_x; /* Line 241, Address: 0x101f060 */
    if (cal_y < (short)bydcol[cal_x]) { col_y.b.h = 1; return; } /* Line 242, Address: 0x101f098 */
  }

  cal_direc = atan_sonic(actwk[0].xspeed.w, actwk[0].yspeed.w); /* Line 245, Address: 0x101f0e4 */
  cal_direc = -(char)(cal_direc + 128); /* Line 246, Address: 0x101f104 */
  cal_direc -= 32; /* Line 247, Address: 0x101f128 */
  if (block_back & 2048) cal_direc += 64; /* Line 248, Address: 0x101f130 */
  sinset(cal_direc, &tmp_sin, &tmp_cos); /* Line 249, Address: 0x101f150 */
  cal_sin = tmp_sin * -1792 >> 8; /* Line 250, Address: 0x101f164 */
  cal_cos = tmp_cos * -1792 >> 8; /* Line 251, Address: 0x101f180 */
  actwk[0].xspeed.w = cal_cos; /* Line 252, Address: 0x101f19c */
  actwk[0].yspeed.w = cal_sin; /* Line 253, Address: 0x101f1ac */
  bob_j(); /* Line 254, Address: 0x101f1bc */
} /* Line 255, Address: 0x101f1c4 */


void bob4(short i, short cal_x, short cal_y, short block_back) { /* Line 258, Address: 0x101f1f0 */
  if (((unsigned short)cal_x & 15) < 8) { /* Line 259, Address: 0x101f208 */
    if (block_back & 2048) bob1(i, cal_x, cal_y, block_back); /* Line 260, Address: 0x101f224 */
    else bob3(i, cal_x, cal_y, block_back); /* Line 261, Address: 0x101f25c */
  } else { /* Line 262, Address: 0x101f274 */
    if (block_back & 2048) bob0(i, cal_x, cal_y, block_back); /* Line 263, Address: 0x101f27c */
    else bob3(i, cal_x, cal_y, block_back); /* Line 264, Address: 0x101f2b4 */
  }
} /* Line 266, Address: 0x101f2cc */


void bob5(short i, short cal_x, short cal_y, short block_back) { /* Line 269, Address: 0x101f2e0 */
  if (((unsigned short)cal_x & 15) < 8) { /* Line 270, Address: 0x101f2f8 */
    if (block_back & 2048) bob0(i, cal_x, cal_y, block_back); /* Line 271, Address: 0x101f314 */
    else bob_s0(i, cal_x, cal_y, block_back); /* Line 272, Address: 0x101f34c */
  } else { /* Line 273, Address: 0x101f364 */
    if (block_back & 2048) bob_s0(i, cal_x, cal_y, block_back); /* Line 274, Address: 0x101f36c */
    else bob0(i, cal_x, cal_y, block_back); /* Line 275, Address: 0x101f3a4 */
  }
} /* Line 277, Address: 0x101f3bc */


void bob6(short i, short cal_x, short cal_y, short block_back) { /* Line 280, Address: 0x101f3d0 */
  if (((unsigned short)cal_y & 15) < 8) { /* Line 281, Address: 0x101f3e8 */
    if (block_back & 2048) bob1(i, cal_x, cal_y, block_back); /* Line 282, Address: 0x101f404 */
    else bob_s0(i, cal_x, cal_y, block_back); /* Line 283, Address: 0x101f43c */
  } else { /* Line 284, Address: 0x101f454 */
    if (block_back & 2048) bob_s0(i, cal_x, cal_y, block_back); /* Line 285, Address: 0x101f45c */
    else bob1(i, cal_x, cal_y, block_back); /* Line 286, Address: 0x101f494 */
  }
} /* Line 288, Address: 0x101f4ac */
