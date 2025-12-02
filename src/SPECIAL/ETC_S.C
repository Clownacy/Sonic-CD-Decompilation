#include "..\TYPES.H"
#include "COMMON.H"
#include "SPS_EQU.H"
#include "ETC_S.H"
#include "ENS.H"

unsigned short sincostbl[130] = {
    255, 65535,  1024, 65528,  2047, 65504,  3069, 65464,  4088, 65408,  5104, 65337,  6117,
  65250,  7126, 65147,  8129, 65030,  9126, 64897, 10117, 64750, 11101, 64589, 12078, 64414,
  13046, 64224, 14005, 64022, 14955, 63807, 15895, 63579, 16825, 63340, 17744, 63088, 18651,
  62826, 19548, 62553, 20432, 62270, 21304, 61977, 22164, 61674, 23011, 61363, 23845, 61044,
  24666, 60717, 25474, 60383, 26268, 60041, 27049, 59694, 27816, 59340, 28569, 58981, 29309,
  58617, 30034, 58249, 30747, 57876, 31445, 57499, 32130, 57120, 32801, 56737, 33459, 56351,
  34103, 55964, 34734, 55574, 35352, 55183, 35957, 54791, 36549, 54398, 37128, 54004, 37695,
  53610, 38249, 53216, 38791, 52822, 39322, 52429, 39840, 52036, 40347, 51644, 40842, 51253,
  41327, 50863, 41800, 50475, 42262, 50089, 42714, 49704, 43156, 49321, 43587, 48940, 44009,
  48561, 44420, 48185, 44823, 47811, 45216, 47439, 45600, 47071, 45975, 46704, 46341, 46341
};
unsigned short acostbl[65] = {
  255, 256, 256, 256, 256, 256, 257, 257, 257, 258,
  259, 259, 260, 261, 262, 262, 263, 264, 265, 267,
  268, 269, 270, 272, 273, 274, 276, 277, 279, 281,
  282, 284, 286, 288, 289, 291, 293, 295, 297, 299,
  301, 304, 306, 308, 310, 312, 315, 317, 320, 322,
  324, 327, 329, 332, 334, 337, 340, 342, 345, 348,
  350, 353, 356, 359, 362
};



void ufo_dec() {
  --ufoleft; /* Line 32, Address: 0x10040a0 */
} /* Line 33, Address: 0x10040b4 */



void ring_add(unsigned short iD0) { /* Line 37, Address: 0x10040c0 */
  ringno += iD0; /* Line 38, Address: 0x10040c8 */
  if (ringno <= 999) return; /* Line 39, Address: 0x10040e0 */
  ringno = 999; /* Line 40, Address: 0x10040f8 */
} /* Line 41, Address: 0x1004104 */



void time_dec() { /* Line 45, Address: 0x1004110 */
  if (spgmmode & 2) /* Line 46, Address: 0x1004118 */
  {
    time_time_attack(); /* Line 48, Address: 0x1004130 */
    return; /* Line 49, Address: 0x1004138 */
  }
  --tcnt20; /* Line 51, Address: 0x1004140 */
  if (tcnt20 == 0) /* Line 52, Address: 0x1004154 */
  {
    tcnt20 = 20; /* Line 54, Address: 0x1004168 */
    dec(); /* Line 55, Address: 0x1004174 */
  }


  if (tdecflg != 0) /* Line 59, Address: 0x100417c */
  {
    --tdecflg; /* Line 61, Address: 0x1004190 */
    dec(); /* Line 62, Address: 0x10041a4 */
  }
} /* Line 64, Address: 0x10041ac */



void dec() { /* Line 68, Address: 0x10041c0 */
  if (time_stop != 0) return; /* Line 69, Address: 0x10041c8 */
  if (game_start != 0) return; /* Line 70, Address: 0x10041dc */
  if (--spe_time.l < 0) /* Line 71, Address: 0x10041f0 */
  {
    spe_time.l = 0; /* Line 73, Address: 0x100420c */
    tdecflg = 0; /* Line 74, Address: 0x1004214 */
    pldeadflg = 1; /* Line 75, Address: 0x100421c */
  }

  tufo_initial(); /* Line 78, Address: 0x1004228 */
  if ((long int)spe_time.l >= 15) return; /* Line 79, Address: 0x1004230 */
  se_no.b.b1 = 223; /* Line 80, Address: 0x100424c */
} /* Line 81, Address: 0x1004258 */



void time_time_attack() {
  if (time_stop != 0) return; /* Line 86, Address: 0x1004270 */
  if (game_start != 0) return; /* Line 87, Address: 0x1004284 */
  spe_time.b.b4 += 3; /* Line 88, Address: 0x1004298 */
  if ((unsigned char)spe_time.b.b4 < 60) return; /* Line 89, Address: 0x10042ac */

  spe_time.b.b4 -= 60; /* Line 91, Address: 0x10042c8 */
  ++spe_time.b.b3; /* Line 92, Address: 0x10042dc */
  if ((unsigned char)spe_time.b.b3 < 60) return; /* Line 93, Address: 0x10042f0 */

  spe_time.b.b3 -= 60; /* Line 95, Address: 0x100430c */
  ++spe_time.b.b2; /* Line 96, Address: 0x1004320 */
  if ((unsigned char)spe_time.b.b2 < 10) return; /* Line 97, Address: 0x1004334 */

  spe_time.l = 604987; /* Line 99, Address: 0x1004350 */
  pldeadflg = 1; /* Line 100, Address: 0x1004360 */
} /* Line 101, Address: 0x100436c */





















void angleget(short iXtget, short iYtget, short iXbase, short iYbase, unsigned char* iAngle, unsigned char* iDirflg) { /* Line 123, Address: 0x1004380 */
  short iD1, iD2, iD3;
  short iwk;
  int lD1;

  iD2 = 0; /* Line 128, Address: 0x10043b0 */
  iD3 = iXtget; /* Line 129, Address: 0x10043b4 */
  iD3 ^= iXbase; /* Line 130, Address: 0x10043c0 */
  iXtget -= iXbase; /* Line 131, Address: 0x10043d0 */

  if (iXtget < 0) /* Line 133, Address: 0x10043e0 */
  {
    if ((unsigned short)iD3 & 32768) goto label2; /* Line 135, Address: 0x10043f4 */

label1:
    iD2 |= 1; /* Line 138, Address: 0x1004408 */
    iXtget = -iXtget; /* Line 139, Address: 0x1004414 */
  } /* Line 140, Address: 0x1004430 */
  else
    if ((unsigned short)iD3 & 32768) goto label1; /* Line 142, Address: 0x1004438 */

label2:
  iYtget -= iYbase; /* Line 145, Address: 0x100444c */
  if (iYtget < 0) /* Line 146, Address: 0x100445c */

    if (iYbase >= 0) /* Line 148, Address: 0x1004470 */
    {
      iD2 |= 2; /* Line 150, Address: 0x1004484 */
      iYtget = -iYtget; /* Line 151, Address: 0x1004490 */
    }
  if (iYtget >= iXtget) /* Line 153, Address: 0x10044ac */
  {
    iD2 |= 4; /* Line 155, Address: 0x10044d0 */
    iwk = iXtget; /* Line 156, Address: 0x10044dc */
    iXtget = iYtget; /* Line 157, Address: 0x10044e8 */
    iYtget = iwk; /* Line 158, Address: 0x10044f0 */
  }
  lD1 = iYtget; /* Line 160, Address: 0x10044f4 */
  lD1 <<= 6; /* Line 161, Address: 0x1004500 */
  if (iXtget == 0) /* Line 162, Address: 0x1004504 */
  {
    lD1 = 0; /* Line 164, Address: 0x1004518 */
  } /* Line 165, Address: 0x100451c */
  else
    lD1 /= iXtget; /* Line 167, Address: 0x1004524 */

  iD1 = lD1 & 255; /* Line 169, Address: 0x1004544 */
  if ((unsigned short)iD1 >= 64) /* Line 170, Address: 0x1004558 */
    iD1 = 63; /* Line 171, Address: 0x100456c */

  *iAngle = iD1; /* Line 173, Address: 0x1004578 */
  *iDirflg = iD2; /* Line 174, Address: 0x1004584 */
} /* Line 175, Address: 0x1004590 */



















void speedget(unsigned char bAngle, unsigned char bDirflg, short iBaseSpd, int* lXspeed, int* lYspeed) { /* Line 195, Address: 0x10045b0 */
  int lwk;
  int_union lD0, lD1;

  lD0.l = 0; /* Line 199, Address: 0x10045cc */
  lD1.l = 0; /* Line 200, Address: 0x10045d0 */
  lD1.w.l = bAngle; /* Line 201, Address: 0x10045d4 */

  lD1.w.l *= 2; /* Line 203, Address: 0x10045e0 */

  if (lD1.w.l == 0) /* Line 205, Address: 0x10045ec */
  {
    lD0.l = 0; /* Line 207, Address: 0x1004600 */
    lD1.w.l = (unsigned short)iBaseSpd; /* Line 208, Address: 0x1004604 */
  } /* Line 209, Address: 0x1004618 */
  else
  {

    lD0.w.l = sincostbl[lD1.w.l++]; /* Line 213, Address: 0x1004620 */
    lD1.w.l = sincostbl[lD1.w.l]; /* Line 214, Address: 0x100464c */

    lD0.l = iBaseSpd * lD0.w.l; /* Line 216, Address: 0x1004670 */
    lD0.l = (long int)((unsigned int)lD0.l >> 16) & 65535 | (long int)((unsigned int)lD0.l << 16) & (unsigned int)65535 << 16; /* Line 217, Address: 0x1004690 */
    lD1.l = iBaseSpd * lD1.w.l; /* Line 218, Address: 0x10046d0 */
    lD1.l = (long int)((unsigned int)lD1.l >> 16) & 65535 | (long int)((unsigned int)lD1.l << 16) & (unsigned int)65535 << 16; /* Line 219, Address: 0x10046f0 */
  }

  if (bDirflg & 4) /* Line 222, Address: 0x1004730 */
  {
    lwk = lD0.l; /* Line 224, Address: 0x1004744 */
    lD0.l = lD1.l; /* Line 225, Address: 0x1004748 */
    lD1.l = lwk; /* Line 226, Address: 0x1004750 */
  }

  if (bDirflg & 2) /* Line 229, Address: 0x1004754 */
    lD0.l = -(long int)lD0.l; /* Line 230, Address: 0x1004768 */

  lD0.l = (long int)((unsigned int)lD0.l >> 16) & 65535 | (long int)((unsigned int)lD0.l << 16) & (unsigned int)65535 << 16; /* Line 232, Address: 0x1004784 */
  lD0.w.l = 0; /* Line 233, Address: 0x10047c4 */
  lD0.l >>= 8; /* Line 234, Address: 0x10047c8 */
  if (bDirflg & 1) /* Line 235, Address: 0x10047d4 */
    lD1.w.l = -lD1.w.l; /* Line 236, Address: 0x10047e8 */

  lD1.l = (long int)((unsigned int)lD1.l >> 16) & 65535 | (long int)((unsigned int)lD1.l << 16) & (unsigned int)65535 << 16; /* Line 238, Address: 0x1004804 */
  lD1.w.l = 0; /* Line 239, Address: 0x1004844 */
  lD1.l >>= 8; /* Line 240, Address: 0x1004848 */

  *lXspeed = lD1.l; /* Line 242, Address: 0x1004854 */
  *lYspeed = lD0.l; /* Line 243, Address: 0x1004860 */
} /* Line 244, Address: 0x100486c */






















int dstnsget(unsigned char bAngle, unsigned char bDirflg, short iXposi, short iYposi, short iXbase, short iYbase) { /* Line 267, Address: 0x1004880 */
  short iD0, iD1, iD2;
  int lD0;

  iD1 = bAngle; /* Line 271, Address: 0x10048ac */

  iD0 = acostbl[iD1]; /* Line 273, Address: 0x10048bc */
  if (bDirflg & 4) /* Line 274, Address: 0x10048e0 */
  {
    iD1 = iYbase; /* Line 276, Address: 0x10048f4 */
    iD2 = iYposi; /* Line 277, Address: 0x1004900 */
  } /* Line 278, Address: 0x100490c */
  else
  {

    iD1 = iXbase; /* Line 282, Address: 0x1004914 */
    iD2 = iXposi; /* Line 283, Address: 0x1004920 */
  }

  iD1 -= iD2; /* Line 286, Address: 0x100492c */
  if (iD1 < 0) /* Line 287, Address: 0x1004938 */
    iD1 = -iD1; /* Line 288, Address: 0x1004948 */

  lD0 = iD0 * iD1; /* Line 290, Address: 0x1004964 */
  lD0 >>= 8; /* Line 291, Address: 0x1004978 */
  return lD0; /* Line 292, Address: 0x100497c */
} /* Line 293, Address: 0x1004980 */











int random() { /* Line 305, Address: 0x10049a0 */
  int_union lD0, lD1;

  lD1.l = ranum; /* Line 308, Address: 0x10049a4 */
  if ((long int)lD1.l == 0) /* Line 309, Address: 0x10049b0 */
    lD1.l = 711800410; /* Line 310, Address: 0x10049c4 */

  lD0.l = lD1.l; /* Line 312, Address: 0x10049d0 */
  if ((long int)lD1.l & (long int)32768 << 16) lD1.l *= 4, lD1.l |= 0x80000000; else lD1.l *= 4; /* Line 313, Address: 0x10049d8 */
  lD1.l += lD0.l; /* Line 314, Address: 0x1004a28 */
  if ((long int)lD1.l & (long int)32768 << 16) lD1.l *= 8, lD1.l |= 0x80000000; else lD1.l *= 8; /* Line 315, Address: 0x1004a38 */
  lD1.l += lD0.l; /* Line 316, Address: 0x1004a88 */
  lD0.w.l = lD1.w.l; /* Line 317, Address: 0x1004a98 */
  lD1.l = (long int)((unsigned int)lD1.l >> 16) & 65535 | (long int)((unsigned int)lD1.l << 16) & (unsigned int)65535 << 16; /* Line 318, Address: 0x1004aa0 */
  lD0.w.l += lD1.w.l; /* Line 319, Address: 0x1004ae0 */
  lD1.w.l = lD0.w.l; /* Line 320, Address: 0x1004af0 */
  lD1.l = (long int)((unsigned int)lD1.l >> 16) & 65535 | (long int)((unsigned int)lD1.l << 16) & (unsigned int)65535 << 16; /* Line 321, Address: 0x1004af8 */
  ranum = lD1.l; /* Line 322, Address: 0x1004b38 */
  return lD0.l; /* Line 323, Address: 0x1004b44 */
} /* Line 324, Address: 0x1004b48 */
