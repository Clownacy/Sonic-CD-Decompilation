#include "..\..\TYPES.H"
#include "LPL_TYPES.H"
#include "SPM_EQU.H"
#include "ETC.H"























void sync() {} /* Line 28, Address: 0x10032e0 */






void swclear() {
  swdata1.w = 65280; /* Line 36, Address: 0x10032f0 */
} /* Line 37, Address: 0x10032fc */






int random() { /* Line 44, Address: 0x1003310 */
  int_union lD0, lD1;

  if ((lD1.l = ranum) == 0) lD1.l = 711800410; /* Line 47, Address: 0x1003314 */
  lD0.l = lD1.l; /* Line 48, Address: 0x1003334 */
  lD1.l <<= 2; /* Line 49, Address: 0x100333c */
  lD1.l += lD0.l; /* Line 50, Address: 0x1003348 */
  lD1.l <<= 3; /* Line 51, Address: 0x1003358 */
  lD1.l += lD0.l; /* Line 52, Address: 0x1003364 */
  lD0.w.l = lD1.w.l; /* Line 53, Address: 0x1003374 */
  lD1.l = lD1.l & 65535 | (lD1.l & 65535); /* Line 54, Address: 0x100337c */
  lD0.w.l += lD1.w.l; /* Line 55, Address: 0x10033bc */
  lD1.w.l = lD0.w.l; /* Line 56, Address: 0x10033cc */
  lD1.l = lD1.l & 65535 | (lD1.l & 65535); /* Line 57, Address: 0x10033d4 */
  ranum = lD1.l; /* Line 58, Address: 0x1003414 */
  return lD0.l; /* Line 59, Address: 0x1003420 */
} /* Line 60, Address: 0x1003424 */






short cos_planet(short sDir) { /* Line 67, Address: 0x1003430 */
  return sin_planet(sDir + 128); /* Line 68, Address: 0x100343c */
} /* Line 69, Address: 0x100345c */






short sin_planet(short sDir) { /* Line 76, Address: 0x1003470 */
  short sDirWk;
  static short sin_tbl[128] =
  {
      0,   3,   6,   9,  12,  15,  18,  22,  25,  28,  31,  34,  37,  40,  43,  47,
     50,  53,  56,  59,  62,  65,  68,  71,  74,  77,  80,  83,  86,  89,  92,  95,
     98, 101, 104, 106, 109, 112, 115, 118, 121, 123, 126, 129, 132, 134, 137, 140,
    142, 145, 147, 150, 153, 155, 158, 160, 162, 165, 167, 170, 172, 174, 177, 179,
    181, 183, 185, 188, 190, 192, 194, 196, 198, 200, 202, 204, 206, 208, 209, 211,
    213, 215, 216, 218, 220, 221, 223, 224, 226, 227, 229, 230, 231, 233, 234, 235,
    236, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 247, 248, 249, 250, 250,
    251, 251, 252, 252, 253, 253, 254, 254, 254, 255, 255, 255, 255, 255, 255, 256
  };

  sDir &= 511; /* Line 90, Address: 0x100347c */
  sDirWk = sDir; /* Line 91, Address: 0x1003488 */
  if (sDir & 128) sDirWk = ~sDirWk; /* Line 92, Address: 0x1003494 */
  sDirWk &= 127; /* Line 93, Address: 0x10034c8 */
  sDirWk = sin_tbl[sDirWk]; /* Line 94, Address: 0x10034d4 */
  if (sDir & 256) sDirWk = -sDirWk; /* Line 95, Address: 0x10034f8 */
  return sDirWk; /* Line 96, Address: 0x100352c */
} /* Line 97, Address: 0x1003530 */







void unlze(unsigned char* pSrc, unsigned char* pDst) { /* Line 105, Address: 0x1003540 */
  short_union sp;
  short sD5, sD4, sD3, sD2, sD1, sD0;
  unsigned char CarryFlg, XFlg;

  sp.b.l = *pSrc++; /* Line 110, Address: 0x100356c */
  sp.b.h = *pSrc++; /* Line 111, Address: 0x1003580 */
  sD5 = sp.w; /* Line 112, Address: 0x1003594 */
  sD4 = 15; /* Line 113, Address: 0x10035a0 */

  while (1)
  {
    CarryFlg = sD5 & 1; /* Line 117, Address: 0x10035ac */
    XFlg = 0; /* Line 118, Address: 0x10035c0 */
    sD5 = (unsigned short)sD5 >> 1; /* Line 119, Address: 0x10035c4 */
    if (--sD4 < 0) /* Line 120, Address: 0x10035e0 */
    {
      sp.b.l = *pSrc++; /* Line 122, Address: 0x1003604 */
      sp.b.h = *pSrc++; /* Line 123, Address: 0x1003618 */
      sD5 = sp.w; /* Line 124, Address: 0x100362c */
      sD4 = 15; /* Line 125, Address: 0x1003638 */
    }

    if (CarryFlg != 0) /* Line 128, Address: 0x1003644 */
    {
      *pDst++ = *pSrc++; /* Line 130, Address: 0x1003650 */
      continue; /* Line 131, Address: 0x1003670 */
    }

    sD3 = 0; /* Line 134, Address: 0x1003678 */
    CarryFlg = sD5 & 1; /* Line 135, Address: 0x100367c */
    XFlg = 0; /* Line 136, Address: 0x1003690 */
    if (--sD4 < 0) /* Line 137, Address: 0x1003694 */
    {
      sp.b.l = *pSrc++; /* Line 139, Address: 0x10036b8 */
      sp.b.h = *pSrc++; /* Line 140, Address: 0x10036cc */
      sD5 = sp.w; /* Line 141, Address: 0x10036e0 */
      sD4 = 15; /* Line 142, Address: 0x10036ec */
    }

    if (CarryFlg == 0) /* Line 145, Address: 0x10036f8 */
    {
      sD5 = (unsigned short)sD5 >> 1; /* Line 147, Address: 0x1003704 */
      if (--sD4 < 0) /* Line 148, Address: 0x1003720 */
      {
        sp.b.l = *pSrc++; /* Line 150, Address: 0x1003744 */
        sp.b.h = *pSrc++; /* Line 151, Address: 0x1003758 */
        sD5 = sp.w; /* Line 152, Address: 0x100376c */
        sD4 = 15; /* Line 153, Address: 0x1003778 */
      }

      CarryFlg = (sD3 & 32768) >> 15; /* Line 156, Address: 0x1003784 */
      sD3 = (unsigned short)sD3 << 1 | XFlg; /* Line 157, Address: 0x100379c */
      XFlg = CarryFlg; /* Line 158, Address: 0x10037c0 */
      ++sD3; /* Line 159, Address: 0x10037c4 */
      sD2 = -1; /* Line 160, Address: 0x10037d0 */
      sD2 = sD2 & 65280 | *pSrc++; /* Line 161, Address: 0x10037dc */
    } /* Line 162, Address: 0x1003810 */
    else
    {

      sD0 = *pSrc++; /* Line 166, Address: 0x1003818 */
      sD1 = *pSrc++; /* Line 167, Address: 0x1003834 */
      sD2 = -1; /* Line 168, Address: 0x1003850 */
      sD2 = sD2 & 65280 | (sD1 & 255); /* Line 169, Address: 0x100385c */
      sD2 = (unsigned short)sD2 << 5; /* Line 170, Address: 0x1003888 */
      sD2 = sD2 & 65280 | (sD0 & 255); /* Line 171, Address: 0x10038a4 */
      if (!(sD1 & 7)) /* Line 172, Address: 0x10038d0 */
      {

        if ((sD1 = *pSrc++) == 0) return; /* Line 175, Address: 0x10038e4 */
        if (sD1 == 1) continue; /* Line 176, Address: 0x1003918 */
        sD3 = sD1; /* Line 177, Address: 0x100392c */
      } /* Line 178, Address: 0x1003934 */
      else
      {
        sD3 = sD1 + 1; /* Line 181, Address: 0x100393c */
      }
    }

    do
    {
      sD0 = pDst[sD2]; /* Line 187, Address: 0x1003958 */
      *pDst++ = (unsigned char)sD0; /* Line 188, Address: 0x1003978 */
    } while (--sD3 >= 0); /* Line 189, Address: 0x100398c */
  } /* Line 190, Address: 0x10039b0 */
} /* Line 191, Address: 0x10039b8 */
