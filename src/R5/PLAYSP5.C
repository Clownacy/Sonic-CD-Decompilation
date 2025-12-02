#include "..\EQU.H"
#include "PLAYSP5.H"
#include "..\DIRCOL.H"
#include "..\FCOL.H"

short belt_a[51] = {
   44,   1,   2,   3,   4,   5,   6,   7,   8,   9,
   14,  15,  17,  18,  19,  35,  36,  37,  38,  39,
   49,  61,  62,  63,  64,  71,  72,  73,  74, 400,
  403, 404, 405, 406, 407, 408, 409, 410, 411, 413,
  415, 422, 423, 424, 448, 450,   0,   0,   0,   0,
    0
};
short belt_b[51] = {
   49,   1,   2,   3,   4,   5,   6,   7,   8,   9,
   10,  11,  14,  15,  17,  18,  19,  35,  36,  37,
   38,  39,  49,  59,  60,  61,  62,  63,  64,  71,
   72,  73,  74, 400, 403, 404, 405, 406, 407, 408,
  409, 410, 411, 413, 415, 422, 423, 424, 483, 484,
  485
};
short belt_c[61] = {
   51,   1,   2,   3,   4,   5,   6,   7,   8,   9,
   10,  11,  12,  13,  14,  15,  17,  18,  19,  35,
   36,  37,  38,  39,  49,  61,  62,  63,  64,  71,
   72,  73,  74,  75, 400, 403, 404, 405, 406, 407,
  408, 409, 410, 411, 413, 414, 415, 423, 424, 487,
  488, 490, 493,   0,   0,   0,   0,   0,   0,   0,
    0
};
short belt_d[51] = {
   49,   1,   2,   3,   4,   5,   6,   7,   8,   9,
   10,  11,  14,  15,  17,  18,  19,  35,  36,  37,
   38,  39,  49,  61,  62,  63,  64,  71,  72,  73,
   74,  75, 400, 403, 404, 405, 406, 407, 408, 409,
  410, 411, 413, 414, 415, 423, 424, 488, 489, 491,
  500
};
short* belt_tbl[4] = {
  belt_b,
  belt_a,
  belt_d,
  belt_c
};

































void playsp(void) { /* Line 78, Address: 0x1017d60 */
  belt(); /* Line 79, Address: 0x1017d68 */
} /* Line 80, Address: 0x1017d70 */





void belt(void) { /* Line 86, Address: 0x1017d80 */
  short wD0, wD2, wD3;

  if (bossflag) return; /* Line 89, Address: 0x1017d94 */

  wD3 = actwk[0].xposi.w.h - (short)(unsigned short)actwk[0].sprhs; /* Line 91, Address: 0x1017da4 */
  wD2 = actwk[0].yposi.w.h + (short)(unsigned short)actwk[0].sprvsize + 2; /* Line 92, Address: 0x1017de4 */
  wD0 = scramapad(&actwk[0], wD3, wD2) & 2047; /* Line 93, Address: 0x1017e28 */
  if (belt_chk(wD0) == 0) { /* Line 94, Address: 0x1017e5c */
    wD3 = actwk[0].xposi.w.h + (short)(unsigned short)actwk[0].sprhs; /* Line 95, Address: 0x1017e70 */

    wD0 = scramapad(&actwk[0], wD3, wD2) & 2047; /* Line 97, Address: 0x1017eb0 */
    if (belt_chk(wD0) == 0) return; /* Line 98, Address: 0x1017ee4 */
  }
  belt_effect(); /* Line 100, Address: 0x1017ef8 */
} /* Line 101, Address: 0x1017f00 */





void belt_effect(void) { /* Line 107, Address: 0x1017f20 */
  int lD0;
  char bD1;
  short wD1;

  switch (time_flag) { /* Line 112, Address: 0x1017f30 */
    case 0:
      lD0 = 32768; /* Line 114, Address: 0x1017f58 */
      break; /* Line 115, Address: 0x1017f5c */
    case 1:
      lD0 = 65536; /* Line 117, Address: 0x1017f64 */
      break; /* Line 118, Address: 0x1017f68 */
    default:
      lD0 = 0x20000; /* Line 120, Address: 0x1017f70 */
      break;
  }

  bD1 = -64; /* Line 124, Address: 0x1017f74 */
  if (colrevflag) { /* Line 125, Address: 0x1017f7c */
    lD0 = -lD0; /* Line 126, Address: 0x1017f8c */
    bD1 = -bD1; /* Line 127, Address: 0x1017f90 */
  }

  actwk[0].xposi.l += lD0; /* Line 130, Address: 0x1017fac */
  if ((wD1 = dircol(&actwk[0], &bD1)) < 0) { /* Line 131, Address: 0x1017fc0 */
    if (colrevflag) wD1 *= -1; /* Line 132, Address: 0x1017ff4 */

    actwk[0].xposi.w.h += wD1; /* Line 134, Address: 0x1018010 */
  }

} /* Line 137, Address: 0x1018024 */









int belt_chk(short wD0) { /* Line 147, Address: 0x1018040 */
  unsigned char bD1;
  short* pBelt;
  short i, wD6;

  bD1 = time_flag & 127; /* Line 152, Address: 0x1018058 */
  if (bD1 == 2) bD1 += generate_flag; /* Line 153, Address: 0x1018070 */

  pBelt = belt_tbl[bD1]; /* Line 155, Address: 0x1018090 */
  wD6 = *pBelt; /* Line 156, Address: 0x10180a8 */

  for (i = 1; wD6 >= 0; --wD6) { /* Line 158, Address: 0x10180b4 */
    if (wD0 == pBelt[i++]) return 1; /* Line 159, Address: 0x10180c8 */
  } /* Line 160, Address: 0x1018114 */
  return 0; /* Line 161, Address: 0x1018130 */
} /* Line 162, Address: 0x1018134 */
