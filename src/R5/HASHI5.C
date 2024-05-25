#include "..\EQU.H"
#include "HASHI5.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\RIDECHK.H"

static void hashi5_init(sprite_status* pActwk);
static void hashi5_move(sprite_status* pActwk);
static void hashi5_move2(sprite_status* pActwk);
static void hashi5_posiget1p(sprite_status* pActwk);
static void hashi5_rideplayset1p(sprite_status* pActwk);
static void hashi5_posiset(sprite_status* pActwk);
static int hashi5_ridechk1p(sprite_status* pActwk);

static sprite_pattern hashi5_pat0 = {
  1,
  { { -8, -8, 0, 429 } }
};
static sprite_pattern hashi5_pat1;
static sprite_pattern hashi5_pat2 = {
  1,
  { { -72, -8, 0, 430 } }
};
sprite_pattern* hashi5pat[3] = {
  &hashi5_pat0,
  &hashi5_pat1,
  &hashi5_pat2
};
static unsigned char hashitbl[272] = {
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   2,  4,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   2,  4,  4,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   2,  4,  6,  4,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   2,  4,  6,  6,  4,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   2,  4,  6,  8,  6,  4,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   2,  4,  6,  8,  8,  6,  4,  2,  0,  0,  0,  0,  0,  0,  0,  0,
   2,  4,  6,  8, 10,  8,  6,  4,  2,  0,  0,  0,  0,  0,  0,  0,
   2,  4,  6,  8, 10, 10,  8,  6,  4,  2,  0,  0,  0,  0,  0,  0,
   2,  4,  6,  8, 10, 12, 10,  8,  6,  4,  2,  0,  0,  0,  0,  0,
   2,  4,  6,  8, 10, 12, 12, 10,  8,  6,  4,  2,  0,  0,  0,  0,
   2,  4,  6,  8, 10, 12, 14, 12, 10,  8,  6,  4,  2,  0,  0,  0,
   2,  4,  6,  8, 10, 12, 14, 14, 12, 10,  8,  6,  4,  2,  0,  0,
   2,  4,  6,  8, 10, 12, 14, 16, 14, 12, 10,  8,  6,  4,  2,  0,
   2,  4,  6,  8, 10, 12, 14, 16, 16, 14, 12, 10,  8,  6,  4,  2
};
static unsigned char hashitbl2[256] = {
  255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  181, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  126, 219, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   97, 181, 236, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   74, 147, 205, 243, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   62, 126, 176, 219, 246, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   56, 109, 157, 197, 228, 248, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   49,  97, 142, 181, 212, 236, 251, 255,   0,   0,   0,   0,   0,   0,   0,   0,
   43,  86, 126, 162, 193, 219, 238, 251, 255,   0,   0,   0,   0,   0,   0,   0,
   37,  74, 115, 147, 176, 205, 225, 243, 252, 255,   0,   0,   0,   0,   0,   0,
   31,  68, 103, 136, 167, 189, 212, 231, 244, 253, 255,   0,   0,   0,   0,   0,
   31,  62,  92, 126, 152, 176, 201, 219, 234, 246, 253, 255,   0,   0,   0,   0,
   25,  56,  86, 115, 142, 167, 189, 209, 225, 238, 248, 254, 255,   0,   0,   0,
   25,  56,  80, 109, 131, 157, 176, 197, 216, 228, 241, 248, 254, 255,   0,   0,
   25,  49,  74, 103, 126, 147, 167, 189, 205, 219, 231, 243, 249, 254, 255,   0,
   25,  49,  74,  97, 120, 142, 162, 181, 197, 212, 225, 236, 244, 251, 254, 255
};




























































void hashi5(sprite_status* pActwk) { /* Line 127, Address: 0x1021d90 */
  void(*hashi5_tbl[3])(sprite_status*) = { /* Line 128, Address: 0x1021d9c */
    &hashi5_init,
    &hashi5_move,
    &hashi5_move2
  };

  hashi5_tbl[pActwk->r_no0 / 2](pActwk); /* Line 134, Address: 0x1021dc0 */
  actionsub(pActwk); /* Line 135, Address: 0x1021dfc */
} /* Line 136, Address: 0x1021e08 */








static void hashi5_init(sprite_status* pActwk) { /* Line 145, Address: 0x1021e20 */
  sprite_status* pNewactwk;
  int i;


  short xofsettbl[8] = { 48, 32, 16, 0, -16, -32, -48, -64 }; /* Line 150, Address: 0x1021e30 */

  pActwk->r_no0 += 2; /* Line 152, Address: 0x1021e64 */
  pActwk->actflg |= 4; /* Line 153, Address: 0x1021e74 */
  pActwk->sprpri = 3; /* Line 154, Address: 0x1021e84 */
  pActwk->sproffset = 17152; /* Line 155, Address: 0x1021e90 */
  pActwk->patbase = hashi5pat; /* Line 156, Address: 0x1021e9c */
  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 157, Address: 0x1021eac */
  ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 158, Address: 0x1021ebc */
  pActwk->sprhsize = 64; /* Line 159, Address: 0x1021ecc */
  pActwk->sprvsize = 8; /* Line 160, Address: 0x1021ed8 */
  pActwk->patno = 1; /* Line 161, Address: 0x1021ee4 */

  for (i = 0; i < 8; ++i) { /* Line 163, Address: 0x1021ef0 */

    if (actwkchk(&pNewactwk) == 0) { /* Line 165, Address: 0x1021efc */
      pActwk->actfree[i] = (char)(pNewactwk - actwk); /* Line 166, Address: 0x1021f10 */
      pNewactwk->actno = 47; /* Line 167, Address: 0x1021f50 */
      pNewactwk->r_no0 = 4; /* Line 168, Address: 0x1021f5c */
      ((short*)pNewactwk)[29] = pActwk->xposi.w.h; /* Line 169, Address: 0x1021f68 */
      ((short*)pNewactwk)[27] = pActwk->yposi.w.h; /* Line 170, Address: 0x1021f78 */
      pNewactwk->yposi.w.h = pActwk->yposi.w.h; /* Line 171, Address: 0x1021f88 */
      pNewactwk->actflg |= 4; /* Line 172, Address: 0x1021f98 */
      pNewactwk->sprpri = 3; /* Line 173, Address: 0x1021fa8 */
      pNewactwk->sproffset = 17152; /* Line 174, Address: 0x1021fb4 */
      pNewactwk->patbase = hashi5pat; /* Line 175, Address: 0x1021fc0 */
      pNewactwk->sprvsize = 8; /* Line 176, Address: 0x1021fd0 */
      pNewactwk->sprhsize = 8; /* Line 177, Address: 0x1021fdc */
      ((short*)pNewactwk)[28] = pActwk - actwk; /* Line 178, Address: 0x1021fe8 */
      pNewactwk->actfree[21] = 255; /* Line 179, Address: 0x1022020 */

      pNewactwk->actfree[18] = 7 - i; /* Line 181, Address: 0x102202c */
      pNewactwk->xposi.w.h = xofsettbl[7 - i] + pActwk->xposi.w.h; /* Line 182, Address: 0x1022040 */
    }

  } /* Line 185, Address: 0x1022080 */
} /* Line 186, Address: 0x1022090 */








static void hashi5_move(sprite_status* pActwk) { /* Line 195, Address: 0x10220b0 */
  pActwk->actfree[19] = 0; /* Line 196, Address: 0x10220bc */
  if (hashi5_ridechk1p(pActwk) != 0) { /* Line 197, Address: 0x10220c4 */
    hashi5_posiget1p(pActwk); /* Line 198, Address: 0x10220d8 */
  }
  if (pActwk->actfree[19]) { /* Line 200, Address: 0x10220e4 */
    if (pActwk->actfree[16] != 64) { /* Line 201, Address: 0x10220f4 */
      pActwk->actfree[16] += 4; /* Line 202, Address: 0x102210c */
    }
    hashi5_posiset(pActwk); /* Line 204, Address: 0x102211c */

    if (pActwk->actfree[19]) { /* Line 206, Address: 0x1022128 */
      hashi5_rideplayset1p(pActwk); /* Line 207, Address: 0x1022138 */
    }
  } /* Line 209, Address: 0x1022144 */
  else {


    if (pActwk->actfree[16]) { /* Line 213, Address: 0x102214c */
      pActwk->actfree[16] -= 4; /* Line 214, Address: 0x102215c */
      hashi5_posiset(pActwk); /* Line 215, Address: 0x102216c */
    }
  }

  frameout_s(pActwk); /* Line 219, Address: 0x1022178 */
} /* Line 220, Address: 0x1022184 */








static void hashi5_move2(sprite_status* pActwk) { /* Line 229, Address: 0x10221a0 */
  if (actwk[((short*)pActwk)[28]].actno != 47) frameout(pActwk); /* Line 230, Address: 0x10221ac */
  if (actwk[((short*)pActwk)[28]].actfree[21]) frameout(pActwk); /* Line 231, Address: 0x10221f4 */
} /* Line 232, Address: 0x1022234 */








static void hashi5_posiget1p(sprite_status* pActwk) { /* Line 241, Address: 0x1022250 */
  unsigned short wD0;

  if (!(actwk[0].cddat & 2)) { /* Line 244, Address: 0x102225c */
    wD0 = actwk[0].xposi.w.h - pActwk->xposi.w.h + 72; /* Line 245, Address: 0x1022274 */
    if (!(wD0 & 32768)) { /* Line 246, Address: 0x10222a4 */
      if (wD0 < 128) { /* Line 247, Address: 0x10222b4 */

        pActwk->actfree[19] = wD0 >> 4; /* Line 249, Address: 0x10222c4 */
        return; /* Line 250, Address: 0x10222d8 */
      }
    }
  }

  pActwk->actfree[19] = 0; /* Line 255, Address: 0x10222e0 */
} /* Line 256, Address: 0x10222e8 */








static void hashi5_rideplayset1p(sprite_status* pActwk) { /* Line 265, Address: 0x1022300 */
  unsigned char bD0;

  bD0 = pActwk->actfree[19]; /* Line 268, Address: 0x102230c */
  actwk[0].yposi.w.h = actwk[pActwk->actfree[bD0]].yposi.w.h - 8 - (short)(unsigned short)actwk[0].sprvsize; /* Line 269, Address: 0x1022318 */
} /* Line 270, Address: 0x1022384 */








static void hashi5_posiset(sprite_status* pActwk) { /* Line 279, Address: 0x10223a0 */
  sprite_status* pSubactwk;
  unsigned short Sin, Cos;
  int_union lD0;
  short wD2;
  unsigned char bD5;
  unsigned char* pA2;
  unsigned char* pA3;

  wD2 = (unsigned short)pActwk->actfree[19]; /* Line 288, Address: 0x10223c0 */

  sinset(pActwk->actfree[16], (short*)&Sin, (short*)&Cos); /* Line 290, Address: 0x10223dc */
  bD5 = hashitbl[wD2 + 128]; /* Line 291, Address: 0x10223f4 */
  pA3 = &hashitbl2[(wD2 + 128 & 15) * 16]; /* Line 292, Address: 0x1022414 */
  pA2 = pActwk->actfree; /* Line 293, Address: 0x1022434 */

  for ( ; wD2 >= 0; --wD2) { /* Line 295, Address: 0x102243c */
    pSubactwk = &actwk[*pA2++]; /* Line 296, Address: 0x1022444 */
    lD0.l = 0; /* Line 297, Address: 0x102246c */
    lD0.b.b4 = *pA3++; /* Line 298, Address: 0x1022470 */
    lD0.l = (lD0.w.l + 1) * bD5 * Sin; /* Line 299, Address: 0x1022480 */
    pSubactwk->yposi.w.h = ((short*)pSubactwk)[27] + lD0.w.h; /* Line 300, Address: 0x10224a8 */
  } /* Line 301, Address: 0x10224d0 */

  lD0.l = 0; /* Line 303, Address: 0x10224ec */
  lD0.b.b4 = pActwk->actfree[19]; /* Line 304, Address: 0x10224f0 */
  lD0.b.b4 = -(lD0.b.b4 - 7); /* Line 305, Address: 0x10224fc */
  if (lD0.b.b4 >= 0) { /* Line 306, Address: 0x102251c */
    wD2 = lD0.w.l; /* Line 307, Address: 0x1022530 */
    lD0.w.l *= 16; /* Line 308, Address: 0x102253c */
    pA3 = &hashitbl2[lD0.w.l + wD2]; /* Line 309, Address: 0x1022548 */
    if (--wD2 < 0) return; /* Line 310, Address: 0x102256c */

    for ( ; wD2 >= 0; --wD2) { /* Line 312, Address: 0x1022590 */
      pSubactwk = &actwk[*pA2++]; /* Line 313, Address: 0x1022598 */
      lD0.l = 0; /* Line 314, Address: 0x10225c0 */
      lD0.w.l = (unsigned short)(*--pA3) + 1; /* Line 315, Address: 0x10225c4 */
      lD0.l = (lD0.w.l + 1) * bD5 * Sin; /* Line 316, Address: 0x10225e4 */
      pSubactwk->yposi.w.h = ((short*)pSubactwk)[27] + lD0.w.h; /* Line 317, Address: 0x102260c */
    } /* Line 318, Address: 0x1022634 */
  }
} /* Line 320, Address: 0x1022650 */









static int hashi5_ridechk1p(sprite_status* pActwk) { /* Line 330, Address: 0x1022680 */
  short wD0, wD1, wD2;


  if (actwk[0].r_no0 != 6) { /* Line 334, Address: 0x1022698 */
    if (!editmode.b.h) { /* Line 335, Address: 0x10226b0 */
      wD1 = 72; /* Line 336, Address: 0x10226c0 */
      wD2 = 128; /* Line 337, Address: 0x10226cc */

      if (actwk[0].yspeed.w >= 0) { /* Line 339, Address: 0x10226d8 */
        wD0 = wD1 + (actwk[0].xposi.w.h - pActwk->xposi.w.h); /* Line 340, Address: 0x10226f0 */
        if (wD0 >= 0) { /* Line 341, Address: 0x1022730 */
          if (wD0 < wD2) { /* Line 342, Address: 0x1022740 */

            wD0 = pActwk->yposi.w.h - 8; /* Line 344, Address: 0x102275c */

            wD2 = actwk[0].yposi.w.h; /* Line 346, Address: 0x1022780 */
            wD1 = wD2 + (short)actwk[0].sprvsize + 4; /* Line 347, Address: 0x1022790 */
            if ((unsigned short)wD0 <= (unsigned short)wD1) { /* Line 348, Address: 0x10227c4 */
              wD0 -= wD1; /* Line 349, Address: 0x10227e0 */
              if ((unsigned short)wD0 >= 65520) { /* Line 350, Address: 0x10227ec */
                if (actwk[0].r_no0 < 6) { /* Line 351, Address: 0x1022804 */
                  actwk[0].yposi.w.h = wD2 + wD0 + 3; /* Line 352, Address: 0x102281c */

                  ride_on_set(pActwk, &actwk[0]); /* Line 354, Address: 0x1022844 */
                  return 1; /* Line 355, Address: 0x1022858 */
                }
              }
            }
          }
        }
      }
    }
  }

  if (actwk[0].actfree[19] == pActwk - actwk) { /* Line 365, Address: 0x1022864 */
    actwk[0].actfree[14] = 0; /* Line 366, Address: 0x10228a0 */
    actwk[0].cddat &= 247; /* Line 367, Address: 0x10228a8 */
  }

  return 0; /* Line 370, Address: 0x10228bc */
} /* Line 371, Address: 0x10228c0 */
