#include "..\EQU.H"
#include "AWA.H"

unsigned char awachg0[5] = { 14, 0, 1, 2, 252 };
unsigned char awachg1[6] = { 14, 1, 2, 3, 4, 252 };
unsigned char awachg2[7] = { 14, 2, 3, 4, 5, 6, 252 };
unsigned char awachg4[2] = { 4, 252 };
unsigned char awachg5[5] = { 4, 6, 7, 8, 252 };
unsigned char awachg6[5] = { 15, 19, 20, 21, 255 };
unsigned char* awachg[7] = {
  awachg0,
  awachg1,
  awachg2,
  awachg4,
  awachg4,
  awachg5,
  awachg6
};
extern sprite_pattern* awapat[];
extern unsigned char awasintbl[];



















































































void awa(sprite_status* pActwk) { /* Line 104, Address: 0x101cf70 */
  void(*awa_move_tbl[6])(sprite_status*) = { /* Line 105, Address: 0x101cf7c */
    &awainit,
    &awamove,
    &awamove2,
    &awamove3,
    &awamove4,
    &awamaster
  };

  awa_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 114, Address: 0x101cfb0 */
} /* Line 115, Address: 0x101cfec */








void awainit(sprite_status* pActwk) { /* Line 124, Address: 0x101d000 */
  pActwk->r_no0 += 2; /* Line 125, Address: 0x101d00c */
  pActwk->patbase = awapat; /* Line 126, Address: 0x101d01c */
  pActwk->sproffset = 33930; /* Line 127, Address: 0x101d02c */
  pActwk->actflg = 132; /* Line 128, Address: 0x101d038 */
  pActwk->sprhsize = 16; /* Line 129, Address: 0x101d044 */
  pActwk->sprpri = 1; /* Line 130, Address: 0x101d050 */
  if (pActwk->userflag.b.h & 128) { /* Line 131, Address: 0x101d05c */

    pActwk->r_no0 += 8; /* Line 133, Address: 0x101d078 */
    pActwk->actfree[8] = pActwk->userflag.b.h & 127; /* Line 134, Address: 0x101d088 */
    pActwk->actfree[9] = pActwk->userflag.b.h & 127; /* Line 135, Address: 0x101d0a8 */
    pActwk->mstno.b.h = 6; /* Line 136, Address: 0x101d0c8 */
    awamaster(pActwk); /* Line 137, Address: 0x101d0d4 */
  } /* Line 138, Address: 0x101d0e0 */
  else {


    pActwk->mstno.b.h = pActwk->userflag.b.h; /* Line 142, Address: 0x101d0e8 */
    ((short*)pActwk)[26] = pActwk->xposi.w.h; /* Line 143, Address: 0x101d0f8 */
    pActwk->yspeed.w = -136; /* Line 144, Address: 0x101d108 */
    pActwk->direc.b.h = random() & 255; /* Line 145, Address: 0x101d114 */
    awamove(pActwk); /* Line 146, Address: 0x101d130 */
  }
} /* Line 148, Address: 0x101d13c */








void awamove(sprite_status* pActwk) { /* Line 157, Address: 0x101d150 */
  patchg(pActwk, awachg); /* Line 158, Address: 0x101d15c */
  if (pActwk->patno == 6) pActwk->actfree[4] = 1; /* Line 159, Address: 0x101d170 */

  awamove2(pActwk); /* Line 161, Address: 0x101d194 */
} /* Line 162, Address: 0x101d1a0 */








void awamove2(sprite_status* pActwk) { /* Line 171, Address: 0x101d1b0 */
  if (waterposi >= pActwk->yposi.w.h) { /* Line 172, Address: 0x101d1bc */


    pActwk->r_no0 = 6; /* Line 175, Address: 0x101d1e8 */
    pActwk->mstno.b.h += 3; /* Line 176, Address: 0x101d1f4 */
    awamove3(pActwk); /* Line 177, Address: 0x101d204 */
    return; /* Line 178, Address: 0x101d210 */
  }


  pActwk->xposi.w.h = (char)awasintbl[pActwk->direc.b.h++ & 127] + ((short*)pActwk)[26]; /* Line 182, Address: 0x101d218 */

  if (pActwk->actfree[4]) { /* Line 184, Address: 0x101d280 */
    if (awacoli(pActwk) != 0) { /* Line 185, Address: 0x101d290 */
      plairset(); /* Line 186, Address: 0x101d2a4 */
      soundset(173); /* Line 187, Address: 0x101d2ac */

      actwk[0].xspeed.w = 0; /* Line 189, Address: 0x101d2b8 */
      actwk[0].yspeed.w = 0; /* Line 190, Address: 0x101d2c0 */
      actwk[0].mspeed.w = 0; /* Line 191, Address: 0x101d2c8 */
      actwk[0].mstno.b.h = 21; /* Line 192, Address: 0x101d2d0 */
      ((short*)&actwk[0])[33] = 35; /* Line 193, Address: 0x101d2dc */
      ((short*)&actwk[0])[32] = 0; /* Line 194, Address: 0x101d2e8 */
      actwk[0].cddat &= 223; /* Line 195, Address: 0x101d2f0 */
      actwk[0].cddat &= 239; /* Line 196, Address: 0x101d304 */

      if (actwk[0].cddat & 4) { /* Line 198, Address: 0x101d318 */
        actwk[0].cddat &= 251; /* Line 199, Address: 0x101d330 */
        actwk[0].sprvsize = 19; /* Line 200, Address: 0x101d344 */
        actwk[0].sprhs = 9; /* Line 201, Address: 0x101d350 */
        actwk[0].yposi.w.h -= 5; /* Line 202, Address: 0x101d35c */
      }
      pActwk->r_no0 = 6; /* Line 204, Address: 0x101d370 */
      pActwk->mstno.b.h += 3; /* Line 205, Address: 0x101d37c */
      awamove3(pActwk); /* Line 206, Address: 0x101d38c */
      return; /* Line 207, Address: 0x101d398 */
    }
  }

  speedset2(pActwk); /* Line 211, Address: 0x101d3a0 */
  if (pActwk->actflg & 128) actionsub(pActwk); /* Line 212, Address: 0x101d3ac */
  else
    frameout(pActwk); /* Line 214, Address: 0x101d3d8 */
} /* Line 215, Address: 0x101d3e4 */








void awamove3(sprite_status* pActwk) { /* Line 224, Address: 0x101d400 */
  patchg(pActwk, awachg); /* Line 225, Address: 0x101d40c */

  if (pActwk->actflg & 128) actionsub(pActwk); /* Line 227, Address: 0x101d420 */
  else frameout(pActwk); /* Line 228, Address: 0x101d44c */
} /* Line 229, Address: 0x101d458 */








void awamove4(sprite_status* pActwk) { /* Line 238, Address: 0x101d470 */
  frameout(pActwk); /* Line 239, Address: 0x101d47c */
} /* Line 240, Address: 0x101d488 */








void awamaster(sprite_status* pActwk) { /* Line 249, Address: 0x101d4a0 */
  unsigned char awatbl[18] = { /* Line 250, Address: 0x101d4b4 */
    0, 1, 0,
    0, 0, 0,
    1, 0, 0,
    0, 0, 1,
    0, 1, 0,
    0, 1, 0
  };
  sprite_status* pNewactwk;
  unsigned char bD0;
  short wD1;

  if (!((unsigned short*)pActwk)[29]) { /* Line 262, Address: 0x101d4e8 */
    if (waterposi >= pActwk->yposi.w.h) { /* Line 263, Address: 0x101d4f8 */
      awafoutchk(pActwk); /* Line 264, Address: 0x101d524 */
      return; /* Line 265, Address: 0x101d530 */
    }
    if (!(pActwk->actflg & 128)) { /* Line 267, Address: 0x101d538 */
      awafoutchk(pActwk); /* Line 268, Address: 0x101d550 */
      return; /* Line 269, Address: 0x101d55c */
    }
    if (--((short*)pActwk)[30] >= 0) goto label3; /* Line 271, Address: 0x101d564 */

    ((short*)pActwk)[29] = 1; /* Line 273, Address: 0x101d58c */

    do {
      wD1 = random(); /* Line 276, Address: 0x101d598 */
      bD0 = wD1 & 7; /* Line 277, Address: 0x101d5b0 */
    } while (bD0 >= 6); /* Line 278, Address: 0x101d5c4 */

    ((short*)pActwk)[28] = bD0; /* Line 280, Address: 0x101d5d4 */
    wD1 &= 12; /* Line 281, Address: 0x101d5dc */

    pActwk->actfree[18] = wD1; /* Line 283, Address: 0x101d5e8 */
    if (--pActwk->actfree[8] & 128) { /* Line 284, Address: 0x101d5f4 */
      pActwk->actfree[8] = pActwk->actfree[9]; /* Line 285, Address: 0x101d618 */
      pActwk->actfree[12] |= 128; /* Line 286, Address: 0x101d628 */
    }

    goto label1; /* Line 289, Address: 0x101d638 */
  }
  if (--((short*)pActwk)[30] >= 0) goto label3; /* Line 291, Address: 0x101d640 */


label1:
  ((short*)pActwk)[30] = random() & 31; /* Line 295, Address: 0x101d668 */

  if (pActwk->actflg & 128) { /* Line 297, Address: 0x101d684 */
    if (actwkchk(&pNewactwk) == 0) { /* Line 298, Address: 0x101d69c */
      pNewactwk->actno = 32; /* Line 299, Address: 0x101d6b0 */
      pNewactwk->xposi.w.h = pActwk->xposi.w.h + ((random() & 15) - 8); /* Line 300, Address: 0x101d6bc */
      pNewactwk->yposi.w.h = pActwk->yposi.w.h; /* Line 301, Address: 0x101d700 */
      pNewactwk->userflag.b.h = awatbl[pActwk->actfree[18] + pActwk->actfree[10]]; /* Line 302, Address: 0x101d710 */

      if (pActwk->actfree[12] & 128) { /* Line 304, Address: 0x101d73c */
        if ((random() & 3) == 0) { /* Line 305, Address: 0x101d754 */
          if (pActwk->actfree[12] & 64) goto label2; /* Line 306, Address: 0x101d768 */

          pActwk->actfree[12] |= 64; /* Line 308, Address: 0x101d780 */
          pNewactwk->userflag.b.h = 2; /* Line 309, Address: 0x101d790 */
        }

        if (!pActwk->actfree[10]) { /* Line 312, Address: 0x101d79c */
          if (!(pActwk->actfree[12] & 64)) { /* Line 313, Address: 0x101d7ac */
            pActwk->actfree[12] |= 64; /* Line 314, Address: 0x101d7c4 */
            pNewactwk->userflag.b.h = 2; /* Line 315, Address: 0x101d7d4 */
          }
        }
      }
    }
  }


label2:
  if (--pActwk->actfree[10] & 128) { /* Line 324, Address: 0x101d7e0 */
    ((short*)pActwk)[30] += (random() & 127) + 128; /* Line 325, Address: 0x101d804 */
    ((short*)pActwk)[29] = 0; /* Line 326, Address: 0x101d82c */
  }

label3:
  patchg(pActwk, awachg); /* Line 330, Address: 0x101d834 */
  awafoutchk(pActwk); /* Line 331, Address: 0x101d848 */
} /* Line 332, Address: 0x101d854 */




void awafoutchk(sprite_status* pActwk) { /* Line 337, Address: 0x101d870 */
  if (!(pActwk->actflg & 128)) { /* Line 338, Address: 0x101d87c */
    if ((pActwk->xposi.w.h & 65408) - (scra_h_posit.w.h - 128 & 65408) >= 641) { /* Line 339, Address: 0x101d894 */
      frameout(pActwk); /* Line 340, Address: 0x101d8d0 */
      return; /* Line 341, Address: 0x101d8dc */
    }
  }

  if (waterposi < pActwk->yposi.w.h) actionsub(pActwk); /* Line 345, Address: 0x101d8e4 */
  else pActwk->actflg &= 127; /* Line 346, Address: 0x101d924 */
} /* Line 347, Address: 0x101d934 */









int awacoli(sprite_status* pActwk) { /* Line 357, Address: 0x101d950 */
  if (!(actwk[0].actfree[2] & 128)) { /* Line 358, Address: 0x101d958 */
    if (pActwk->xposi.w.h - 16 < actwk[0].xposi.w.h) { /* Line 359, Address: 0x101d970 */
      if (pActwk->xposi.w.h + 16 >= actwk[0].xposi.w.h) { /* Line 360, Address: 0x101d9a0 */
        if (pActwk->yposi.w.h < actwk[0].yposi.w.h) { /* Line 361, Address: 0x101d9d0 */
          if (pActwk->yposi.w.h + 16 >= actwk[0].yposi.w.h) return 1; /* Line 362, Address: 0x101d9fc */
        }
      }
    }
  }
  return 0; /* Line 367, Address: 0x101da38 */
} /* Line 368, Address: 0x101da3c */
