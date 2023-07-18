// Addresses correspond to R11A.ELF
#include "EQU.C"
#include "EMIE1.H"

void(*em1_tbl)(act_info*)[5] = {
  &emie1_init,
  &emie1_matu,
  &emie1_dakii,
  &emie1_tobii,
  &emie1_tobim
};
tagPALETTEENTRY zone1colora[0];
char* em_pchg[0];
spr_array* emie1pat[0];
tagPALETTEENTRY emie1_clr[16] = {
  {   0,   0,   0, 1 },
  {   0,   0,   0, 1 },
  { 128,  32,  96, 1 },
  { 160,  64, 128, 1 },
  { 224,  96, 224, 1 },
  { 224, 160, 224, 1 },
  { 224, 224, 224, 1 },
  { 160, 160, 160, 1 },
  { 128, 128, 128, 1 },
  {  64,  64,  64, 1 },
  { 224, 160, 128, 1 },
  { 192,  96,   0, 1 },
  {  32, 192,   0, 1 },
  {   0, 128,   0, 1 },
  {  96,   0, 128, 1 },
  { 224,   0,   0, 1 }
};
void(*ht1_tbl)(act_info*)[2] = {
  &heart1_init,
  &heart1_move
};









void emie1(act_info* pActwk) { /* Line 146, Address: 0x10052b0 */
  if (ta_flag) { /* Line 147, Address: 0x10052bc */
    emie1clrsetx(zone1colora); /* Line 148, Address: 0x10052cc */
  } else { /* Line 149, Address: 0x10052dc */
    em1_tbl[pActwk->r_no0 / 2](pActwk); /* Line 150, Address: 0x10052e4 */
    heartset(pActwk); /* Line 151, Address: 0x1005328 */

    actionsub(pActwk); /* Line 153, Address: 0x1005334 */
    frameout_s(pActwk); /* Line 154, Address: 0x1005340 */

    if (pActwk->actno != 47) { /* Line 156, Address: 0x100534c */
      emie1clrsetx(zone1colora); /* Line 157, Address: 0x1005364 */
    }
  }
} /* Line 160, Address: 0x1005374 */





void emie1_init(act_info* pActwk) { /* Line 166, Address: 0x1005390 */
  short iScd, xwk;

  pActwk->actflg |= 4; /* Line 169, Address: 0x10053a4 */
  pActwk->sproffset = 9072; /* Line 170, Address: 0x10053b4 */
  pActwk->sprpri = 1; /* Line 171, Address: 0x10053c0 */
  pActwk->patbase = emie1pat; /* Line 172, Address: 0x10053cc */

  pActwk->sprhsize = 12; /* Line 174, Address: 0x10053dc */
  pActwk->sprvsize = 16; /* Line 175, Address: 0x10053e8 */
  *(short*)&pActwk->actfree[12] = pActwk->xposi.w.h; /* Line 176, Address: 0x10053f4 */

  emie1clrset(); /* Line 178, Address: 0x1005404 */

  while ((iScd = emycol_d(pActwk)) != 0) { /* Line 180, Address: 0x100540c */
    pActwk->yposi.w.h += iScd; /* Line 181, Address: 0x1005414 */
  } /* Line 182, Address: 0x1005424 */

  setdirect(pActwk, &actwk[0]); /* Line 184, Address: 0x1005450 */

  xwk = actwk[0].xposi.w.h; /* Line 186, Address: 0x1005464 */
  if ((xwk -= pActwk->xposi.w.h) < 0) { /* Line 187, Address: 0x1005474 */
    xwk = -xwk; /* Line 188, Address: 0x10054a0 */
  }

  if (xwk < 112) { /* Line 191, Address: 0x10054bc */
    pActwk->r_no0 += 2; /* Line 192, Address: 0x10054d0 */
  }

  pActwk->mstno.b.h = 5; /* Line 195, Address: 0x10054e0 */
  empatchg(pActwk, &em_pchg); /* Line 196, Address: 0x10054ec */
} /* Line 197, Address: 0x1005500 */




/* TODO: Reverify flow. Each else block usually causes a branch. Lots of whitespace at the end, too. */
void emie1_matu(act_info* pActwk) { /* Line 203, Address: 0x1005520 */
  short lenwk;
  unsigned char dakiflgwk;

  setdirect(pActwk, &actwk[0]); /* Line 207, Address: 0x1005534 */

  if ((lenwk = actwk[0].xposi.w.h - pActwk->xposi.w.h) < 0) { /* Line 209, Address: 0x1005548 */
    lenwk = -lenwk; /* Line 210, Address: 0x1005594 */
  }

  dakiflgwk = pActwk->actfree[20]; /* Line 213, Address: 0x10055b0 */

  if ((dakiflgwk & 4) || actwk[0].xspeed.w == 0 || lenwk >= 16) { /* Line 215, Address: 0x10055bc */



    if (dakiflgwk & 4) { /* Line 219, Address: 0x10055f0 */

      if (lenwk < 32) { /* Line 221, Address: 0x1005600 */


        pActwk->xspeed.w = 0; /* Line 224, Address: 0x1005614 */
        pActwk->yposi.w.h += emycol_d(pActwk); /* Line 225, Address: 0x100561c */
        pActwk->mstno.b.h = 1; /* Line 226, Address: 0x1005638 */
        empatchg(pActwk, &em_pchg); /* Line 227, Address: 0x1005644 */
        return; /* Line 228, Address: 0x1005658 */
      }

      pActwk->actfree[20] = pActwk->actfree[20] & 251; /* Line 231, Address: 0x1005660 */
    }




    if (pActwk->cddat & 1) /* Line 237, Address: 0x1005670 */
      pActwk->xspeed.w -= 16; /* Line 238, Address: 0x1005688 */
    else /* Line 239, Address: 0x1005698 */
      pActwk->xspeed.w += 16; /* Line 240, Address: 0x10056a0 */


    if (pActwk->xspeed.w >= 513) /* Line 243, Address: 0x10056b0 */
      pActwk->xspeed.w = 512; /* Line 244, Address: 0x10056cc */
    else if (pActwk->xspeed.w < -512) /* Line 245, Address: 0x10056d8 */
      pActwk->xspeed.w = -512; /* Line 246, Address: 0x10056fc */




    if (pActwk->xspeed.w >= 0) { /* Line 251, Address: 0x1005708 */

      if (pActwk->xposi.w.h < *(short*)&pActwk->actfree[12] + 144) { /* Line 253, Address: 0x1005720 */



        lenwk = emycol_d(pActwk); /* Line 257, Address: 0x1005750 */

        if (lenwk < 7 && lenwk >= -7) { /* Line 259, Address: 0x1005764 */
          pActwk->yposi.w.h += lenwk; /* Line 260, Address: 0x100578c */
          speedsetx(pActwk); /* Line 261, Address: 0x100579c */
          dakicheck(pActwk); /* Line 262, Address: 0x10057a8 */

          pActwk->mstno.b.h = 2; /* Line 264, Address: 0x10057b4 */
          empatchg(pActwk, &em_pchg); /* Line 265, Address: 0x10057c0 */
          return; /* Line 266, Address: 0x10057d4 */
        }
      }
    }
    else {
      if ((*(short*)&pActwk->actfree[12] + -304) < pActwk->xposi.w.h) { /* Line 271, Address: 0x10057dc */



        lenwk = emycol_d(pActwk); /* Line 275, Address: 0x100580c */

        if (lenwk < 7 && lenwk >= -7) { /* Line 277, Address: 0x1005820 */
          pActwk->yposi.w.h += lenwk; /* Line 278, Address: 0x1005848 */
          speedsetx(pActwk); /* Line 279, Address: 0x1005858 */
          dakicheck(pActwk); /* Line 280, Address: 0x1005864 */

          pActwk->mstno.b.h = 2; /* Line 282, Address: 0x1005870 */
          empatchg(pActwk, &em_pchg); /* Line 283, Address: 0x100587c */
          return; /* Line 284, Address: 0x1005890 */
        }
      }
    }
  } else if (dakiflgwk & 64) { /* Line 289, Address: 0x1005898 */


      pActwk->actfree[20] |= 4; /* Line 291, Address: 0x10058a8 */
      pActwk->xspeed.w = 0; /* Line 292, Address: 0x10058b8 */


      pActwk->yposi.w.h += emycol_d(pActwk); /* Line 295, Address: 0x10058c0 */
      pActwk->mstno.b.h = 1; /* Line 296, Address: 0x10058dc */
      empatchg(pActwk, em_pchg); /* Line 297, Address: 0x10058e8 */
      return; /* Line 298, Address: 0x10058fc */
  }



  pActwk->xspeed.w = 0; /* Line 303, Address: 0x1005904 */

  if (dakiflgwk & 128) { /* Line 305, Address: 0x100590c */


    if ((dakiflgwk & 64) == 0) { /* Line 308, Address: 0x100591c */
      if (pActwk->actfree[21] >= 3) { /* Line 309, Address: 0x100592c */

        if ((pActwk->actfree[16] + 4) >= 256) { /* Line 311, Address: 0x1005944 */
          pActwk->actfree[21] = 0; /* Line 312, Address: 0x1005968 */
        }


        pActwk->actfree[16] += 4; /* Line 316, Address: 0x1005970 */
        pActwk->mstno.b.h = 4; /* Line 317, Address: 0x1005980 */
        empatchg(pActwk, em_pchg); /* Line 318, Address: 0x100598c */
        return; /* Line 319, Address: 0x10059a0 */
      }
      pActwk->yspeed.w = -768; /* Line 323, Address: 0x10059a8 */
      pActwk->actfree[20] |= 64; /* Line 324, Address: 0x10059b4 */
    }




    speedsety(pActwk); /* Line 328, Address: 0x10059c4 */
    pActwk->yspeed.w += 64; /* Line 329, Address: 0x10059d0 */

    if (pActwk->yspeed.w < 0) { /* Line 331, Address: 0x10059e0 */
      pActwk->patno = 6; /* Line 332, Address: 0x10059f8 */
    } /* Line 333, Address: 0x1005a04 */
    else pActwk->patno = 4; /* Line 334, Address: 0x1005a0c */


    if (emycol_d(pActwk) < 0) { /* Line 337, Address: 0x1005a18 */

      pActwk->yspeed.w = 0; /* Line 339, Address: 0x1005a34 */
      pActwk->actfree[20] &= 191; /* Line 340, Address: 0x1005a3c */
      ++pActwk->actfree[21]; /* Line 341, Address: 0x1005a4c */
    }
  } /* Line 343, Address: 0x1005a5c */
  else {
    pActwk->yposi.w.h += emycol_d(pActwk); /* Line 345, Address: 0x1005a64 */
    pActwk->mstno.b.h = 1; /* Line 346, Address: 0x1005a80 */
    empatchg(pActwk, &em_pchg); /* Line 347, Address: 0x1005a8c */
  }



} /* Line 352, Address: 0x1005aa0 */





void emie1_dakii(act_info* pActwk) { /* Line 358, Address: 0x1005ac0 */



  actwk[0].actfree[2] |= 1; /* Line 362, Address: 0x1005acc */

  actwk[0].mstno.b.h = 5; /* Line 364, Address: 0x1005ae0 */
  emie_play(pActwk, &actwk[0]); /* Line 365, Address: 0x1005aec */

  setdirect(pActwk, &actwk[0]); /* Line 367, Address: 0x1005b00 */

  if (actwk[0].cddat & 1) { /* Line 369, Address: 0x1005b14 */
    pActwk->xposi.w.h = actwk[0].xposi.w.h + 12; /* Line 370, Address: 0x1005b2c */
  } else { /* Line 371, Address: 0x1005b50 */
    pActwk->xposi.w.h = actwk[0].xposi.w.h + -12; /* Line 372, Address: 0x1005b58 */
  }

  pActwk->yposi.w.h = actwk[0].yposi.w.h; /* Line 375, Address: 0x1005b7c */

  swdata = swdata1; /* Line 377, Address: 0x1005b8c */
  jumpchk_d(); /* Line 378, Address: 0x1005ba4 */
  if ((actwk[0].actfree[2] & 1) == 0) { /* Line 379, Address: 0x1005bac */

    pActwk->actfree[20] &= 254; /* Line 381, Address: 0x1005bc4 */
    pActwk->r_no0 = 6; /* Line 382, Address: 0x1005bd4 */
  } else if (pltime >= (9 | 12800)) { /* Line 383, Address: 0x1005be0 */

    pljumpset(); /* Line 385, Address: 0x1005c04 */
    pActwk->actfree[20] &= 254; /* Line 386, Address: 0x1005c0c */
    pActwk->r_no0 = 2; /* Line 387, Address: 0x1005c1c */
  } else { /* Line 388, Address: 0x1005c28 */
    pActwk->mstno.b.h = 3; /* Line 389, Address: 0x1005c30 */
    empatchg(pActwk, &em_pchg); /* Line 390, Address: 0x1005c3c */
  }
} /* Line 392, Address: 0x1005c50 */





void emie1_tobii(act_info* pActwk) { /* Line 398, Address: 0x1005c60 */
  short lenwk;

  pActwk->patno = 6; /* Line 401, Address: 0x1005c70 */

  if ((lenwk = pActwk->xposi.w.h - *(short*)&pActwk->actfree[12]) < 0) { /* Line 403, Address: 0x1005c7c */

    lenwk = -lenwk; /* Line 405, Address: 0x1005cc8 */
  }

  if (lenwk >= 128) { /* Line 408, Address: 0x1005ce4 */
    pActwk->xspeed.w = 0; /* Line 409, Address: 0x1005cf8 */
  } else { /* Line 410, Address: 0x1005d00 */
    if (pActwk->cddat & 1) { /* Line 411, Address: 0x1005d08 */

      pActwk->xspeed.w = 128; /* Line 413, Address: 0x1005d20 */
    } else { /* Line 414, Address: 0x1005d2c */
      pActwk->xspeed.w = -128; /* Line 415, Address: 0x1005d34 */
    }
  }

  pActwk->yspeed.w = -768; /* Line 419, Address: 0x1005d40 */
  pActwk->r_no0 += 2; /* Line 420, Address: 0x1005d4c */

  emie1_tobim(pActwk); /* Line 422, Address: 0x1005d5c */
} /* Line 423, Address: 0x1005d68 */





void emie1_tobim(act_info* pActwk) { /* Line 429, Address: 0x1005d80 */
  speedset(pActwk); /* Line 430, Address: 0x1005d8c */
  pActwk->yspeed.w += 64; /* Line 431, Address: 0x1005d98 */
  if (pActwk->yspeed.w < 0) pActwk->patno = 7; /* Line 432, Address: 0x1005dc0 */


  if (emycol_d(pActwk) >= 0) return; /* Line 435, Address: 0x1005dcc */

  pActwk->xspeed.w = 0; /* Line 437, Address: 0x1005de8 */
  pActwk->yspeed.w = 0; /* Line 438, Address: 0x1005df0 */

  if (pActwk->actfree[16] + 16 < 256) { /* Line 440, Address: 0x1005df8 */
    pActwk->actfree[16] += 16; /* Line 441, Address: 0x1005e1c */
  } /* Line 442, Address: 0x1005e2c */
  else {

    pActwk->actfree[16] += 16; /* Line 445, Address: 0x1005e34 */
    pActwk->r_no0 = 2; /* Line 446, Address: 0x1005e44 */
  }
} /* Line 448, Address: 0x1005e50 */
















void emie_play(act_info* pEmiewk, act_info* pSonicwk) { /* Line 465, Address: 0x1005e60 */
  if (pEmiewk->xspeed.w != 0) { /* Line 466, Address: 0x1005e70 */
    speedsetx(pSonicwk); /* Line 467, Address: 0x1005e80 */
    pSonicwk->yposi.w.h += emycol_d(pSonicwk); /* Line 468, Address: 0x1005e8c */

    if (pSonicwk->xspeed.w < 0) { /* Line 470, Address: 0x1005ea8 */

      if ((pSonicwk->xspeed.w + 64) < 0) { /* Line 472, Address: 0x1005ec0 */
        pSonicwk->xspeed.w += 64; /* Line 473, Address: 0x1005edc */
      } else { /* Line 474, Address: 0x1005eec */
        pSonicwk->xspeed.w = 0; /* Line 475, Address: 0x1005ef4 */
      }
    } /* Line 477, Address: 0x1005efc */
    else {
      if ((pSonicwk->xspeed.w + -16) >= 0) { /* Line 479, Address: 0x1005f04 */
        pSonicwk->xspeed.w -= 64; /* Line 480, Address: 0x1005f20 */
      } else { /* Line 481, Address: 0x1005f30 */
        pSonicwk->xspeed.w = 0; /* Line 482, Address: 0x1005f38 */
      }
    }
  }
} /* Line 486, Address: 0x1005f40 */













void setdirect(act_info* pEmiewk, act_info* pSonicwk) { /* Line 500, Address: 0x1005f50 */
  if (pEmiewk->xposi.w.h < pSonicwk->xposi.w.h) { /* Line 501, Address: 0x1005f5c */

    pEmiewk->cddat &= 254; /* Line 503, Address: 0x1005f88 */
    pEmiewk->actflg &= 254; /* Line 504, Address: 0x1005f98 */
  } /* Line 505, Address: 0x1005fa8 */
  else {
    pEmiewk->cddat |= 1; /* Line 507, Address: 0x1005fb0 */
    pEmiewk->actflg |= 1; /* Line 508, Address: 0x1005fc0 */
  }
} /* Line 510, Address: 0x1005fd0 */











void speedset(act_info* pActwk) { /* Line 522, Address: 0x1005fe0 */
  speedsetx(pActwk); /* Line 523, Address: 0x1005fec */
  speedsety(pActwk); /* Line 524, Address: 0x1005ff8 */
} /* Line 525, Address: 0x1006004 */


void speedsetx(act_info* pActwk) { /* Line 528, Address: 0x1006020 */
  pActwk->xposi.l += pActwk->xspeed.w << 8; /* Line 529, Address: 0x1006028 */
} /* Line 530, Address: 0x100604c */


void speedsety(act_info* pActwk) { /* Line 533, Address: 0x1006060 */
  pActwk->yposi.l += pActwk->yspeed.w << 8; /* Line 534, Address: 0x1006068 */
} /* Line 535, Address: 0x100608c */












void jumpchk_d() { /* Line 548, Address: 0x10060a0 */

  if ((swdata.b.h & 112) == 0) return; /* Line 550, Address: 0x10060a8 */




  pljumpset(); /* Line 555, Address: 0x10060c0 */
} /* Line 556, Address: 0x10060c8 */


void pljumpset() { /* Line 559, Address: 0x10060e0 */
  short sinwk, coswk;

  actwk[0].actfree[2] = 0; /* Line 562, Address: 0x10060e8 */
  sinset(pActwk->direc.b.h + -64, &sinwk, &coswk); /* Line 563, Address: 0x10060f0 */
  coswk = (coswk * 1664) >> 8; /* Line 564, Address: 0x1006118 */
  actwk[0].xspeed.w += coswk; /* Line 565, Address: 0x1006148 */
  sinwk = (sinwk * 1664) >> 8; /* Line 566, Address: 0x1006160 */
  actwk[0].yspeed += sinwk; /* Line 567, Address: 0x1006190 */

  actwk[0].cddat |= 2; /* Line 569, Address: 0x10061a8 */
  actwk[0].cddat &= 223; /* Line 570, Address: 0x10061bc */
  actwk[0].actfree[18] = 1; /* Line 571, Address: 0x10061d0 */
  actwk[0].actfree[14] = 0; /* Line 572, Address: 0x10061dc */

  if (actwk[0].cddat & 4) { /* Line 574, Address: 0x10061e4 */
    actwk[0].sprvsize = 19; /* Line 577, Address: 0x10061fc */
    actwk[0].sprhs = 9; /* Line 578, Address: 0x1006208 */
    actwk[0].cddat |= 16; /* Line 579, Address: 0x1006214 */
  } /* Line 580, Address: 0x1006228 */
  else {
    actwk[0].sprvsize = 14; /* Line 581, Address: 0x1006230 */
    actwk[0].sprhs = 7; /* Line 582, Address: 0x100623c */
    actwk[0].yposi.w.h += 5; /* Line 583, Address: 0x1006248 */
    actwk[0].cddat |= 4; /* Line 584, Address: 0x100625c */
    actwk[0].mstno.b.h = 2; /* Line 585, Address: 0x1006270 */
  }
} /* Line 587, Address: 0x100627c */












void dakicheck(act_info* pActwk) { /* Line 599, Address: 0x1006290 */
  short lenwk;




  if (pActwk->xspeed.w >= 0) { /* Line 605, Address: 0x10062a0 */

    if (pActwk->xposi.w.h >= (*(short*)&pActwk->actfree[12] + 144)) return; /* Line 607, Address: 0x10062b8 */




  } /* Line 612, Address: 0x10062e8 */
  else {
    if (*(short*)&pActwk->actfree[12] + -304 >= pActwk->xposi.w.h) return; /* Line 614, Address: 0x10062f0 */
  }





  if (pltime >= (9 | 12800)) return; /* Line 621, Address: 0x1006320 */



  if (editmode.b.h != 0) return; /* Line 625, Address: 0x100633c */



  if (pActwk->cddat & 1) { /* Line 629, Address: 0x100634c */

    if ((lenwk = pActwk->xposi.w.h - actwk[0].xposi.w.h) < 0) return; /* Line 631, Address: 0x1006364 */



  } /* Line 635, Address: 0x10063b0 */
  else if ((lenwk = actwk[0].xposi.w.h - pActwk->xposi.w.h) < 0) return; /* Line 636, Address: 0x10063b8 */





  if (lenwk < 12 || lenwk >= 24) { /* Line 642, Address: 0x1006404 */
    return; /* Line 643, Address: 0x100642c */
  }

  lenwk = actwk[0].yposi.w.h - pActwk->yposi.w.h + 8; /* Line 646, Address: 0x1006434 */
  if (lenwk < 0 || lenwk >= 16) { /* Line 647, Address: 0x100646c */

    return; /* Line 649, Address: 0x1006490 */
  }

  if ((lenwk = actwk[0].xspeed.w) < 0) { /* Line 652, Address: 0x1006498 */
    lenwk = -lenwk; /* Line 653, Address: 0x10064b8 */
  }

  if (actwk[0].cddat & 6 /* Line 656, Address: 0x10064d4 */
      || actwk[0].actfree[6] != 0
      || lenwk >= 1664
      || plpower_b != 0
      || plpower_a != 0
      || plpower_m != 0) {
    pActwk->r_no0 = 6; /* Line 662, Address: 0x1006540 */
  } /* Line 663, Address: 0x100654c */
  else {


    pActwk->actfree[20] |= 129; /* Line 667, Address: 0x1006554 */
    pActwk->xspeed.w = pActwk->yspeed.w = 0; /* Line 668, Address: 0x1006564 */
    pActwk->patno = 7; /* Line 669, Address: 0x100657c */
    pActwk->r_no0 = 4; /* Line 670, Address: 0x1006588 */




    sub_sync(124); /* Line 675, Address: 0x1006594 */
  }
} /* Line 677, Address: 0x10065a0 */












void empatchg(act_info* pActwk, char** pPattbl) { /* Line 690, Address: 0x10065c0 */
  char *pPatdat, patnowk;

  if (pActwk->mstno.b.h != pActwk->mstno.b.l) { /* Line 693, Address: 0x10065d4 */

    pActwk->mstno.b.l = pActwk->mstno.b.h; /* Line 695, Address: 0x10065fc */
    pActwk->patcnt = 0; /* Line 696, Address: 0x100660c */
    pActwk->pattim = 0; /* Line 697, Address: 0x1006614 */
  }

  if (--pActwk->pattim <= 0) { /* Line 700, Address: 0x100661c */
    pPatdat = pPattbl[pActwk->mstno.b.l]; /* Line 701, Address: 0x1006648 */
    if ((patnowk = pPatdat[pActwk->patcnt]) < 0) { /* Line 702, Address: 0x1006668 */

      pActwk->patcnt = 0; /* Line 704, Address: 0x1006694 */
      patnowk = pPatdat[pActwk->patcnt]; /* Line 705, Address: 0x100669c */
    }


    pActwk->patno = patnowk % 64; /* Line 709, Address: 0x10066b8 */


    pActwk->actflg &= 252; /* Line 712, Address: 0x10066d0 */
    pActwk->actflg |= (pActwk->cddat ^ ((patnowk << 3) | (patnowk >> 5))) % 4; /* Line 713, Address: 0x10066e0 */



    pActwk->pattim = pPatdat[pActwk->patcnt + 1]; /* Line 717, Address: 0x1006724 */


    pActwk->patcnt += 2; /* Line 720, Address: 0x1006744 */
  }
} /* Line 722, Address: 0x1006754 */





















void emie1clrset() { /* Line 744, Address: 0x1006770 */
  emie1clrsetx(emie1_clr); /* Line 745, Address: 0x1006778 */
} /* Line 746, Address: 0x1006788 */











void emie1clrsetx(tagPALETTEENTRY* pPalet) { /* Line 758, Address: 0x10067a0 */
  tagPALETTEENTRY* pColorwk;
  short i;


  pColorwk = lpcolorwk + 16; /* Line 763, Address: 0x10067b0 */

  for (i = 0; i < 16; ++i) { /* Line 765, Address: 0x10067bc */
    *pColorwk = *pPalet; /* Line 766, Address: 0x10067c8 */
    ++pColorwk; /* Line 767, Address: 0x10067ec */
    ++pPalet; /* Line 768, Address: 0x10067f0 */
  } /* Line 769, Address: 0x10067fc */
} /* Line 770, Address: 0x100681c */











void heartset(act_info* pActwk) { /* Line 782, Address: 0x1006830 */
  act_info* pHeartact;
  short wk;

  if (pActwk->actfree[20] & 1) { /* Line 786, Address: 0x1006840 */

    wk = pActwk->actfree[17] + 16; /* Line 788, Address: 0x1006858 */
    pActwk->actfree[17] += 16; /* Line 789, Address: 0x1006880 */
    if (wk < 256) return; /* Line 790, Address: 0x1006890 */


  } else { /* Line 793, Address: 0x10068a4 */
    wk = pActwk->actfree[17] + 6; /* Line 794, Address: 0x10068ac */
    pActwk->actfree[17] += 6; /* Line 795, Address: 0x10068d4 */
    if (wk < 256) return; /* Line 796, Address: 0x10068e4 */
  }



  if (actwkchk(&pHeartact) != 0) return; /* Line 801, Address: 0x10068f8 */





  pHeartact->actno = 48; /* Line 807, Address: 0x100690c */
  if (pActwk->cddat & 1) { /* Line 808, Address: 0x1006918 */
    wk = -10; /* Line 809, Address: 0x1006930 */
  } else { /* Line 810, Address: 0x100693c */
    wk = 8; /* Line 811, Address: 0x1006944 */
  }

  if (pActwk->actfree[20] & 1) { /* Line 814, Address: 0x1006950 */
    wk = -wk; /* Line 815, Address: 0x1006968 */
  }

  pHeartact->xposi.w.h = pActwk->xposi.w.h + wk; /* Line 818, Address: 0x1006984 */
  pHeartact->yposi.w.h = pActwk->yposi.w.h + -12; /* Line 819, Address: 0x10069b0 */
} /* Line 820, Address: 0x10069d4 */




















void heart1(act_info* pActwk) { /* Line 841, Address: 0x10069f0 */
  ht1_tbl[pActwk->r_no0 / 2](pActwk); /* Line 842, Address: 0x10069fc */
  actionsub(pActwk); /* Line 843, Address: 0x1006a40 */
  frameout_s(pActwk); /* Line 844, Address: 0x1006a4c */
} /* Line 845, Address: 0x1006a58 */





void heart1_init(act_info* pActwk) { /* Line 851, Address: 0x1006a70 */
  pActwk->r_no0 += 2; /* Line 852, Address: 0x1006a7c */
  pActwk->actflg |= 4; /* Line 853, Address: 0x1006a8c */
  pActwk->sproffset = 880; /* Line 854, Address: 0x1006a9c */
  pActwk->patbase = emie1pat; /* Line 855, Address: 0x1006aa8 */
  pActwk->patno = 8; /* Line 856, Address: 0x1006ab8 */
  pActwk->yspeed.w = -96; /* Line 857, Address: 0x1006ac4 */
  pActwk->sprpri = 3; /* Line 858, Address: 0x1006ad0 */

  heart1_move(pActwk); /* Line 860, Address: 0x1006adc */
} /* Line 861, Address: 0x1006ae8 */





void heart1_move(act_info* pActwk) { /* Line 867, Address: 0x1006b00 */
  short sinwk, coswk;

  if (pActwk->actfree[18] == 0) { /* Line 870, Address: 0x1006b0c */
    sinset(pActwk->actfree[16] * 3, &sinwk, &coswk); /* Line 871, Address: 0x1006b1c */
    pActwk->xspeed.w = sinwk * 4; /* Line 872, Address: 0x1006b44 */
  }


  speedset(pActwk); /* Line 876, Address: 0x1006b64 */
  if (++pActwk->actfree[16] == 20) { /* Line 877, Address: 0x1006b70 */
    ++pActwk->patno; /* Line 878, Address: 0x1006b94 */
  } else if (pActwk->actfree[16] == 110) { /* Line 879, Address: 0x1006ba4 */
     ++pActwk->patno; /* Line 880, Address: 0x1006bc4 */
    pActwk->xspeed = pActwk->yspeed = 0; /* Line 881, Address: 0x1006bd4 */
    pActwk->actfree[18] = 1; /* Line 882, Address: 0x1006bec */
  } else if (pActwk->actfree[16] == 120) { /* Line 883, Address: 0x1006bf8 */
    frameout(pActwk); /* Line 884, Address: 0x1006c18 */
  }
} /* Line 886, Address: 0x1006c24 */

