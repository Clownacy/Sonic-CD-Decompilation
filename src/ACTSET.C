#include "EQU.C"
#include "ACSET.H"

aset_info* pAsetadr_w;
asetz_info* pAsetadrz_w;
asetz_info asettblz[1] = {
  { -1, 0, 0, 0 }
};
aset_info asettbl[1] {
  { 420, 944, 153, 02, 224, 0 }
};
aset_info* pAsetadr_dummy;
unsigned char dummyarea[0];
























void flagwkclr() { /* Line 38, Address: 0x1000000 */
  flagworkcnt = flagworkcnt2 = 1; /* Line 39, Address: 0x1000008 */
  sMemSet(flagwork, 0, 766); /* Line 40, Address: 0x1000020 */
} /* Line 41, Address: 0x1000040 */





void actsetchk() { /* Line 47, Address: 0x1000050 */
  if (actset_rno.w == 0) actsetinit(); /* Line 48, Address: 0x1000058 */
  else actset(); /* Line 49, Address: 0x1000080 */
} /* Line 50, Address: 0x1000088 */





void actsetinit() { /* Line 56, Address: 0x10000a0 */
  short scra_h;
  unsigned char cnt;

  actset_rno.w += 2; /* Line 60, Address: 0x10000b0 */


  pAsetadr_dummy = dummyarea; /* Line 63, Address: 0x10000c4 */
  asetadr = asetadr2 = pAsetadr_w = asettbl; /* Line 64, Address: 0x10000d4 */
  asetadrz2 = pAsetadrz_w = asettblz; /* Line 65, Address: 0x10000f4 */

  flagworkcnt = flagworkcnt2 = 1; /* Line 67, Address: 0x1000114 */
  cnt = 0; /* Line 68, Address: 0x100012c */
  scra_h = scra_h_posit.w.h; /* Line 69, Address: 0x1000130 */

  if (scra_h >= 128) scra_h -= 128; /* Line 71, Address: 0x1000140 */
  else scra_h = 0; /* Line 72, Address: 0x1000168 */
  scra_h &= -128; /* Line 73, Address: 0x100016c */



  while (pAsetadr_w->x < scra_h) { /* Line 77, Address: 0x100017c */
    if (pAsetadr_w->a & 128) { /* Line 78, Address: 0x10001a0 */

      cnt = flagworkcnt; /* Line 80, Address: 0x10001bc */
      ++flagworkcnt; /* Line 81, Address: 0x10001c8 */
    }
    ++pAsetadr_w; /* Line 83, Address: 0x10001dc */
  } /* Line 84, Address: 0x10001f0 */
  asetadr = pAsetadr_w; /* Line 85, Address: 0x10001f8 */

  pAsetadr_w = asetadr2; /* Line 87, Address: 0x1000208 */
  if (scra_h >= 128) { /* Line 88, Address: 0x1000218 */

    scra_h -= 128; /* Line 90, Address: 0x100022c */


    while (pAsetadr_w->x < scra_h) { /* Line 93, Address: 0x1000238 */
      if (pAsetadr_w->a & 128) { /* Line 94, Address: 0x100025c */

        ++flagworkcnt2; /* Line 96, Address: 0x1000278 */
      }
      ++pAsetadr_w; /* Line 98, Address: 0x100028c */
    } /* Line 99, Address: 0x10002a0 */
  }
  asetadr2 = pAsetadr_w; /* Line 101, Address: 0x10002a8 */
  asetposi = -1; /* Line 102, Address: 0x10002b8 */

  actset(); /* Line 104, Address: 0x10002c4 */
} /* Line 105, Address: 0x10002cc */





void actset() { /* Line 111, Address: 0x10002f0 */
  short scra_h;
  unsigned short index;
  unsigned char cnt;


  cnt = 0; /* Line 117, Address: 0x1000300 */
  scra_h = scra_h_posit.w.h & -128; /* Line 118, Address: 0x1000304 */
  if (asetposi == scra_h) return; /* Line 119, Address: 0x100032c */


  if (scra_h < asetposi) { /* Line 122, Address: 0x100034c */

    asetposi = scra_h; /* Line 124, Address: 0x1000370 */
    pAsetadr_w = asetadr2; /* Line 125, Address: 0x1000378 */
    scra_h -= 128; /* Line 126, Address: 0x1000388 */
    if (scra_h >= 0) /* Line 127, Address: 0x1000394 */



















label1:
      if (scra_h < (pAsetadr_w - 1)->x) { /* Line 148, Address: 0x10003a4 */
        --pAsetadr_w; /* Line 149, Address: 0x10003d4 */
        if (pAsetadr_w->a & 128) { /* Line 150, Address: 0x10003e8 */

          --flagworkcnt2; /* Line 152, Address: 0x1000404 */
          cnt = flagworkcnt2; /* Line 153, Address: 0x1000418 */
        }
        if (actnoset(cnt, &index) == 0) { /* Line 155, Address: 0x1000424 */






          --pAsetadr_w; /* Line 162, Address: 0x100043c */
          goto label1; /* Line 163, Address: 0x1000450 */
        } else if (pAsetadr_w->a & 128) { /* Line 164, Address: 0x1000458 */

          ++flagworkcnt2; /* Line 166, Address: 0x1000474 */
          flagwork[index] %= 128; /* Line 167, Address: 0x1000488 */
        }
        ++pAsetadr_w; /* Line 169, Address: 0x10004a8 */
      }
    asetadr2 = pAsetadr_w; /* Line 171, Address: 0x10004bc */

    pAsetadr_w = asetadr; /* Line 173, Address: 0x10004cc */
    scra_h += 768; /* Line 174, Address: 0x10004dc */












    while ((pAsetadr_w - 1)->x >= scra_h) { /* Line 187, Address: 0x10004e8 */
      if ((pAsetadr_w - 1)->a & 128) { /* Line 188, Address: 0x1000518 */

        --flagworkcnt; /* Line 190, Address: 0x1000534 */
      }
      --pAsetadr_w; /* Line 192, Address: 0x1000548 */
    } /* Line 193, Address: 0x100055c */
    asetadr = pAsetadr_w; /* Line 194, Address: 0x1000564 */
  } /* Line 195, Address: 0x1000574 */


  else {
    asetposi = scra_h; /* Line 199, Address: 0x100057c */
    pAsetadr_w = asetadr; /* Line 200, Address: 0x1000584 */
    scra_h += 640; /* Line 201, Address: 0x1000594 */











label2:
    if (pAsetadr_w->x < scra_h) { /* Line 214, Address: 0x10005a0 */
      if (pAsetadr_w->a & 128) { /* Line 215, Address: 0x10005c4 */

        cnt = flagworkcnt; /* Line 217, Address: 0x10005e0 */
        ++flagworkcnt; /* Line 218, Address: 0x10005ec */
      }
      if (actnoset(cnt, &index) == 0) goto label2; /* Line 220, Address: 0x1000600 */







      if (pAsetadr_w->a & 128) { /* Line 228, Address: 0x1000618 */

        --flagworkcnt; /* Line 230, Address: 0x1000634 */
        flagwork[index] %= 128; /* Line 231, Address: 0x1000648 */
      }
    }
    asetadr = pAsetadr_w; /* Line 234, Address: 0x1000668 */

    pAsetadr_w = asetadr2; /* Line 236, Address: 0x1000678 */
    scra_h -= 768; /* Line 237, Address: 0x1000688 */
    if (scra_h >= 0) { /* Line 238, Address: 0x1000694 */













      while (pAsetadr_w->x < scra_h) { /* Line 252, Address: 0x10006a4 */
        if (pAsetadr_w->a & 128) { /* Line 253, Address: 0x10006c8 */

          ++flagworkcnt2; /* Line 255, Address: 0x10006e4 */
        }
        ++pAsetadr_w; /* Line 257, Address: 0x10006f8 */
      } /* Line 258, Address: 0x100070c */
    }
    asetadr2 = pAsetadr_w; /* Line 260, Address: 0x1000714 */
  }
} /* Line 262, Address: 0x1000724 */









int tm_setchk(unsigned char cnt, unsigned short* pIndex) { /* Line 272, Address: 0x1000740 */
  unsigned short tflag;
  unsigned char time;

  tflag = time_flag % 128; /* Line 276, Address: 0x1000760 */
  *pIndex = tflag + cnt * 3; /* Line 277, Address: 0x1000778 */
  time = pAsetadr_w->c; /* Line 278, Address: 0x10007a0 */
  time = (time >> 5) % 8; /* Line 279, Address: 0x10007b0 */
  switch (tflag) { /* Line 280, Address: 0x10007c4 */

    case 0: return (time & 1) != 0; /* Line 282, Address: 0x10007f0 */
    case 1: return (time & 2) != 0; /* Line 283, Address: 0x100081c */
    case 2: return (time & 4) != 0; /* Line 284, Address: 0x1000848 */
  }

  while (true); /* Line 287, Address: 0x1000874 */

} /* Line 289, Address: 0x1000890 */








int actnoset(unsigned char cnt, unsigned short* pIndex) { /* Line 298, Address: 0x10008b0 */
  act_info* pActwk;
  short zflag;
  unsigned char revflg;
  unsigned char an;

  if (tm_setchk(cnt, pIndex) != 0) { /* Line 304, Address: 0x10008d0 */

    if (pAsetadr_w->a & 128) { /* Line 306, Address: 0x10008e8 */

      zflag = (flagwork[*pIndex] & 128) == 0; /* Line 308, Address: 0x1000904 */
      flagwork[*pIndex] |= 128; /* Line 309, Address: 0x1000950 */
      if (zflag == 0) { /* Line 310, Address: 0x1000974 */

        ++pAsetadr_w; /* Line 312, Address: 0x1000984 */
        return 0; /* Line 313, Address: 0x1000998 */
      }
    }
  }
  else {

    ++pAsetadr_w; /* Line 319, Address: 0x10009a4 */
    return 0; /* Line 320, Address: 0x10009b8 */
  }

  if (actwkchk(&pActwk) != 0) return -1; /* Line 323, Address: 0x10009c4 */

  pActwk->xposi.w.h = pAsetadr_w->x; /* Line 325, Address: 0x10009e4 */
  pActwk->yposi.w.h = pAsetadr_w->y; /* Line 326, Address: 0x10009f8 */
  revflg = (pAsetadr_w->y >> 14) % 4; /* Line 327, Address: 0x1000a1c */
  pActwk->actflg = revflg; /* Line 328, Address: 0x1000a44 */
  pActwk->cddat = revflg; /* Line 329, Address: 0x1000a4c */
  an = pAsetadr_w->a; /* Line 330, Address: 0x1000a54 */
  if (an != 0) { /* Line 331, Address: 0x1000a64 */

    an %= 128; /* Line 333, Address: 0x1000a74 */
    pActwk->cdsts = cnt; /* Line 334, Address: 0x1000a7c */
  }
  pActwk->actno = an; /* Line 336, Address: 0x1000a88 */
























  pActwk->userflag.b.h = pAsetadr_w->b; /* Line 361, Address: 0x1000a90 */
  pActwk->userflag.b.l = pAsetadr_w->d; /* Line 362, Address: 0x1000aa4 */
  ++pAsetadr_w; /* Line 363, Address: 0x1000ab8 */







  return 0; /* Line 371, Address: 0x1000acc */
} /* Line 372, Address: 0x1000ad0 */







int actwkchk(act_info** ppActwk) { /* Line 380, Address: 0x1000af0 */
  short i;
  act_info* pActwk;

  pActwk = &actwk[32]; /* Line 384, Address: 0x1000b00 */
  for (i = 0; i < 96; ++i, ++pActwk) { /* Line 385, Address: 0x1000b08 */


    if (pActwk->actno == 0) { /* Line 388, Address: 0x1000b14 */

      *ppActwk = pActwk; /* Line 390, Address: 0x1000b24 */
      return 0; /* Line 391, Address: 0x1000b2c */
    }
  } /* Line 393, Address: 0x1000b38 */
  return -1; /* Line 394, Address: 0x1000b5c */
} /* Line 395, Address: 0x1000b60 */







int actwkchk2(act_info* pActwk, act_info** ppNewActwk) { /* Line 403, Address: 0x1000b80 */
  act_info* pNextActwk;
  act_info* pLastActwk;


  pNextActwk = pActwk + 1; /* Line 408, Address: 0x1000b94 */
  pLastActwk = &actwk[127]; /* Line 409, Address: 0x1000b9c */



  while (pLastActwk >= pNextActwk) { /* Line 413, Address: 0x1000ba4 */
    if (pNextActwk->actno == 0) { /* Line 414, Address: 0x1000bb0 */

      *ppNewActwk = pNextActwk; /* Line 416, Address: 0x1000bc0 */
      return 0; /* Line 417, Address: 0x1000bc8 */
    }
    ++pNextActwk; /* Line 419, Address: 0x1000bd4 */
  } /* Line 420, Address: 0x1000bd8 */
  return -1; /* Line 421, Address: 0x1000be0 */
} /* Line 422, Address: 0x1000be4 */







int frameout_s(act_info* pActwk) { /* Line 430, Address: 0x1000c00 */
  frameout_s00(pActwk, pActwk->xposi.w.h); /* Line 431, Address: 0x1000c0c */
} /* Line 432, Address: 0x1000c20 */








int frameout_s00(act_info* pActwk, short xposi) { /* Line 441, Address: 0x1000c30 */
  short scra_h;
  unsigned short index;
  short_union tflag;
  short zflag;

  if (pActwk->actflg & 128) { /* Line 447, Address: 0x1000c50 */

    if (time_flag & 128) == 0) return 0; /* Line 449, Address: 0x1000c68 */
  }
  else {

    xposi &= -128; /* Line 453, Address: 0x1000c8c */
    scra_h = scra_h_posit->w.h; /* Line 454, Address: 0x1000c9c */
    scra_h -= 128; /* Line 455, Address: 0x1000cac */
    scra_h &= -128; /* Line 456, Address: 0x1000cb8 */
    xposi -= scra_h; /* Line 457, Address: 0x1000cc8 */
    if (xposi < 641) { /* Line 458, Address: 0x1000cd4 */

      if (time_flag & 128) == 0) return 0; /* Line 460, Address: 0x1000cec */
    }
  }

  index = pActwk->cdsts; /* Line 464, Address: 0x1000d10 */
  if (index != 0) { /* Line 465, Address: 0x1000d20 */

    index *= 3; /* Line 467, Address: 0x1000d28 */
    tflag.b.h = 0; /* Line 468, Address: 0x1000d34 */
    tflag.b.l = time_flag; /* Line 469, Address: 0x1000d38 */
    zflag = (tflag.b.l & 128) == 0; /* Line 470, Address: 0x1000d44 */
    tflag.w &= -129; /* Line 471, Address: 0x1000d7c */
    if (zflag == 0) { /* Line 472, Address: 0x1000d8c */

      tflag.w -= time_item; /* Line 474, Address: 0x1000d9c */
      if (tflag.w < 0) tflag.w = 0; /* Line 475, Address: 0x1000dcc */
      else if (tflag.w >= 3) tflag.w = 2; /* Line 476, Address: 0x1000dec */
    }
    index += tflag.w; /* Line 478, Address: 0x1000e0c */
    flagwork[index] %= 128; /* Line 479, Address: 0x1000e1c */
  }
  frameout(pActwk); /* Line 481, Address: 0x1000e38 */
  return -1; /* Line 482, Address: 0x1000e44 */
} /* Line 483, Address: 0x1000e48 */







int frameout_s0(act_info* pActwk) { /* Line 491, Address: 0x1000e70 */
  unsigned short index;
  short_union tflag;
  short zflag;

  index = pActwk->cdsts; /* Line 496, Address: 0x1000e88 */
  if (index != 0) { /* Line 497, Address: 0x1000e98 */

    index *= 3; /* Line 499, Address: 0x1000ea0 */
    tflag.b.h = 0; /* Line 500, Address: 0x1000eac */
    tflag.b.l = time_flag; /* Line 501, Address: 0x1000eb0 */
    zflag = (tflag.b.l & 128) == 0; /* Line 502, Address: 0x1000ebc */
    tflag.w &= -129; /* Line 503, Address: 0x1000ef4 */
    if (zflag == 0) { /* Line 504, Address: 0x1000f04 */

      tflag.w -= time_item; /* Line 506, Address: 0x1000f14 */
      if (tflag.w < 0) tflag.w = 0; /* Line 507, Address: 0x1000f44 */
      else if (tflag.w >= 3) tflag.w = 2; /* Line 508, Address: 0x1000f64 */
    }
    index += tflag.w; /* Line 510, Address: 0x1000f84 */
    flagwork[index] %= 128; /* Line 511, Address: 0x1000f94 */
  }
  frameout(pActwk); /* Line 513, Address: 0x1000fb0 */
  return -1; /* Line 514, Address: 0x1000fbc */
} /* Line 515, Address: 0x1000fc0 */
