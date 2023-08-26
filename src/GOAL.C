#include "EQU.H"
#include "GOAL.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "DIRCOL.H"
#include "PLAYSUB.H"

extern void soundset(short ReqNo);
extern void colorset2(int ColorNo);
extern void sub_sync(short ReqNo);

void(*gene_tbl[6])(act_info*) = {
  &gene_init,
  &gene_move0,
  &gene_move1,
  &goal_move2,
  &goal_move3,
  &kira_move
};
extern spr_array* genepat[];
extern unsigned char* genechg[];
extern map_info mapinittbl;
void(*bring2_tbl[3])(act_info*) = {
  &bring2init,
  &bring2move0,
  &bring2move1
};
extern spr_array* bring2pat[];
extern unsigned char* bring2chg[];
void(*bigring_tbl[3])(act_info*) = {
  &bring_init,
  &bring_move0,
  &bring_move1
};
extern spr_array* bringpat[];
extern unsigned char* bringchg[];
void(*mosugu_tbl[3])(act_info*, act_info*) = {
  &mosug_init,
  &mosug_move0,
  &mosug_move1
};
extern spr_array* goalpat[];
void(*goal_tbl[5])(act_info*) = {
  &goal_init,
  &goal_move0,
  &goal_move1,
  &goal_move2,
  &goal_move3
};
extern unsigned char* goalchg[];












































void gene(act_info* pActwk) { /* Line 95, Address: 0x100f280 */
  gene_tbl[pActwk->r_no0 / 2](pActwk); /* Line 96, Address: 0x100f28c */
  if (pActwk->r_no0 == 0) return; /* Line 97, Address: 0x100f2d0 */

  if (pActwk->r_no0 != 10) { /* Line 99, Address: 0x100f2e4 */

    if (pActwk->r_no0 >= 6) return; /* Line 101, Address: 0x100f2fc */
  }

  actionsub(pActwk); /* Line 104, Address: 0x100f314 */
} /* Line 105, Address: 0x100f320 */











void gene_init(act_info* pActwk) { /* Line 117, Address: 0x100f330 */
  pActwk->actflg |= 4; /* Line 118, Address: 0x100f33c */
  pActwk->r_no0 += 2; /* Line 119, Address: 0x100f34c */
  pActwk->sprpri = 4; /* Line 120, Address: 0x100f35c */
  pActwk->patbase = genepat; /* Line 121, Address: 0x100f368 */
  pActwk->sproffset = 9345; /* Line 122, Address: 0x100f378 */
  pActwk->sprhs = 32; /* Line 123, Address: 0x100f384 */
  pActwk->sprhsize = 32; /* Line 124, Address: 0x100f390 */
  pActwk->sprvsize = 24; /* Line 125, Address: 0x100f39c */
  gene_move0(pActwk); /* Line 126, Address: 0x100f3a8 */
} /* Line 127, Address: 0x100f3b4 */











void gene_move0(act_info* pActwk) { /* Line 139, Address: 0x100f3d0 */
  short coli;
  short iD0, iD1;

  patchg(pActwk, genechg); /* Line 143, Address: 0x100f3e8 */
  coli = gene_coli(pActwk, &actwk[0]); /* Line 144, Address: 0x100f3fc */
  if (coli == 0) return; /* Line 145, Address: 0x100f418 */

  pltime_f = 0; /* Line 147, Address: 0x100f428 */
  pActwk->patno = 2; /* Line 148, Address: 0x100f430 */
  pActwk->actfree[0] = 120; /* Line 149, Address: 0x100f43c */
  pActwk->r_no0 += 2; /* Line 150, Address: 0x100f448 */

  iD0 = actwk[0].xposi.w.h; /* Line 152, Address: 0x100f458 */
  iD1 = actwk[0].sprhs; /* Line 153, Address: 0x100f468 */
  iD1 += 32; /* Line 154, Address: 0x100f47c */
  iD0 -= pActwk->xposi.w.h; /* Line 155, Address: 0x100f488 */
  iD0 += iD1; /* Line 156, Address: 0x100f49c */
  if (iD0 < 0) goto label1; /* Line 157, Address: 0x100f4a8 */
  iD1 += iD1; /* Line 158, Address: 0x100f4b8 */
  if (iD0 >= iD1) goto label1; /* Line 159, Address: 0x100f4c4 */

  iD0 = actwk[0].yspeed.w; /* Line 161, Address: 0x100f4e0 */
  iD0 = -iD0; /* Line 162, Address: 0x100f4f0 */
  iD0 = iD0 >> 2; /* Line 163, Address: 0x100f4fc */
  actwk[0].yspeed.w = iD0; /* Line 164, Address: 0x100f508 */
  return; /* Line 165, Address: 0x100f510 */
label1:
  iD0 = actwk[0].xspeed.w; /* Line 167, Address: 0x100f518 */
  iD0 = -iD0; /* Line 168, Address: 0x100f528 */
  iD0 = iD0 >> 2; /* Line 169, Address: 0x100f534 */
  actwk[0].xspeed.w = iD0; /* Line 170, Address: 0x100f540 */
} /* Line 171, Address: 0x100f548 */











void gene_move1(act_info* pActwk) { /* Line 183, Address: 0x100f570 */
  act_info* pActfree;
  short iD0, iD1, ret;
  unsigned short wOff;
  unsigned char bywk;
  char tbl[16] = { /* Line 188, Address: 0x100f590 */
      0,   0,
     32,  -8,
    -32,   0,
    -24,  -8,
     24,   8,
    -16,   8,
     16,   8,
     -8,  -8
  };

  bywk = pActwk->actfree[0]; /* Line 199, Address: 0x100f5c4 */
  iD0 = bywk; /* Line 200, Address: 0x100f5d0 */
  --iD0; /* Line 201, Address: 0x100f5dc */
  pActwk->actfree[0] = iD0; /* Line 202, Address: 0x100f5e8 */
  if (iD0 >= 0) { /* Line 203, Address: 0x100f5f4 */
    iD1 = iD0; /* Line 204, Address: 0x100f604 */
    iD1 %= 4; /* Line 205, Address: 0x100f60c */
    if (iD1 != 0) return; /* Line 206, Address: 0x100f618 */
    iD0 = iD0 >> 2; /* Line 207, Address: 0x100f628 */
    iD0 %= 8; /* Line 208, Address: 0x100f634 */
    iD0 += iD0; /* Line 209, Address: 0x100f640 */
    wOff = iD0; /* Line 210, Address: 0x100f64c */
    ret = actwkchk(&pActfree); /* Line 211, Address: 0x100f650 */
    if (ret != 0) return; /* Line 212, Address: 0x100f66c */
    soundset(158); /* Line 213, Address: 0x100f67c */
    pActfree->actno = 24; /* Line 214, Address: 0x100f688 */
    pActfree->r_no1 = 1; /* Line 215, Address: 0x100f694 */
    pActfree->xposi.w.h = pActwk->xposi.w.h; /* Line 216, Address: 0x100f6a0 */
    pActfree->yposi.w.h = pActwk->yposi.w.h; /* Line 217, Address: 0x100f6b0 */
    iD0 = tbl[wOff]; /* Line 218, Address: 0x100f6c0 */
    pActfree->xposi.w.h += iD0; /* Line 219, Address: 0x100f6dc */
    iD0 = tbl[wOff + 1]; /* Line 220, Address: 0x100f6ec */
    pActfree->yposi.w.h += iD0; /* Line 221, Address: 0x100f70c */
  } /* Line 222, Address: 0x100f71c */
  else {
    kira_set(pActwk); /* Line 224, Address: 0x100f724 */
    pActwk->r_no0 += 2; /* Line 225, Address: 0x100f730 */
    pActwk->actfree[0] = 60; /* Line 226, Address: 0x100f740 */
  } /* Line 227, Address: 0x100f74c */
}










void kira_set(act_info* pActwk) { /* Line 239, Address: 0x100f770 */
  int i, ret, iColor;
  short iD1;
  act_info* pActfree;
  short tbl[11] = { 0, /* Line 243, Address: 0x100f78c */
    -128, 128, -256, 256, -384,  384, -512, 512, -640, 640 };

  iColor = mapinittbl.colorno1; /* Line 246, Address: 0x100f7b8 */
  colorset2(iColor); /* Line 247, Address: 0x100f7c4 */

  for (i = 0, iD1 = 0; i < 7; ++i, ++iD1) { /* Line 249, Address: 0x100f7d0 */

    ret = actwkchk(&pActfree); /* Line 251, Address: 0x100f7e0 */
    if (ret != 0) break; /* Line 252, Address: 0x100f7fc */
    pActfree->actno = 21; /* Line 253, Address: 0x100f804 */
    pActfree->actflg |= 4; /* Line 254, Address: 0x100f810 */
    pActfree->xposi.w.h = pActwk->xposi.w.h; /* Line 255, Address: 0x100f820 */
    pActfree->yposi.w.h = pActwk->yposi.w.h; /* Line 256, Address: 0x100f830 */
    pActfree->r_no0 = 10; /* Line 257, Address: 0x100f840 */
    pActfree->patbase = genepat; /* Line 258, Address: 0x100f84c */
    pActfree->sproffset = 0; /* Line 259, Address: 0x100f85c */
    pActfree->mstno.b.h = 1; /* Line 260, Address: 0x100f864 */
    pActfree->yspeed.w = -1536; /* Line 261, Address: 0x100f870 */
    pActfree->xspeed.w = tbl[iD1]; /* Line 262, Address: 0x100f87c */
  } /* Line 263, Address: 0x100f898 */
} /* Line 264, Address: 0x100f8b4 */











void kira_move(act_info* pActwk) { /* Line 276, Address: 0x100f8e0 */
  short ret;

  patchg(pActwk, genechg); /* Line 279, Address: 0x100f8f0 */
  speedset(pActwk); /* Line 280, Address: 0x100f904 */
  ret = emycol_d(pActwk); /* Line 281, Address: 0x100f910 */
  if (ret < 0) { /* Line 282, Address: 0x100f924 */

    pActwk->actno = 31; /* Line 284, Address: 0x100f934 */
    pActwk->userflag.b.h = 1; /* Line 285, Address: 0x100f940 */
    pActwk->r_no0 = 0; /* Line 286, Address: 0x100f94c */
  }
} /* Line 288, Address: 0x100f954 */













short gene_coli(act_info* pActwk, act_info* pPlaywk) { /* Line 302, Address: 0x100f970 */
  short iD0, iD1;

  if ((pPlaywk->cddat & 4) == 0) return 0; /* Line 305, Address: 0x100f984 */
  iD0 = pPlaywk->sprhs; /* Line 306, Address: 0x100f9a8 */
  iD0 += 32; /* Line 307, Address: 0x100f9bc */
  iD1 = pPlaywk->xposi.w.h - pActwk->xposi.w.h; /* Line 308, Address: 0x100f9c8 */
  iD1 += iD0; /* Line 309, Address: 0x100f9fc */
  if (iD1 < 0) return 0; /* Line 310, Address: 0x100fa08 */
  iD0 += iD0; /* Line 311, Address: 0x100fa24 */
  if (iD1 >= iD0) return 0; /* Line 312, Address: 0x100fa30 */

  iD0 = pPlaywk->sprvsize; /* Line 314, Address: 0x100fa58 */
  iD0 += 28; /* Line 315, Address: 0x100fa6c */
  iD1 = pPlaywk->yposi.w.h - pActwk->yposi.w.h; /* Line 316, Address: 0x100fa78 */
  iD1 += iD0; /* Line 317, Address: 0x100faac */
  if (iD1 < 0) return 0; /* Line 318, Address: 0x100fab8 */
  iD0 += iD0; /* Line 319, Address: 0x100fad4 */
  if (iD1 >= iD0) return 0; /* Line 320, Address: 0x100fae0 */
  return 1; /* Line 321, Address: 0x100fb08 */
} /* Line 322, Address: 0x100fb0c */


















void bring2(act_info* pActwk) { /* Line 341, Address: 0x100fb20 */
  bring2_tbl[pActwk->r_no0 / 2](pActwk); /* Line 342, Address: 0x100fb2c */
  actionsub(pActwk); /* Line 343, Address: 0x100fb70 */
} /* Line 344, Address: 0x100fb7c */











void bring2init(act_info* pActwk) { /* Line 356, Address: 0x100fb90 */
  pActwk->actflg |= 4; /* Line 357, Address: 0x100fb9c */
  pActwk->r_no0 += 2; /* Line 358, Address: 0x100fbac */
  pActwk->sproffset = 1007; /* Line 359, Address: 0x100fbbc */
  pActwk->patbase = bring2pat; /* Line 360, Address: 0x100fbc8 */
  bring2move0(pActwk); /* Line 361, Address: 0x100fbd8 */
} /* Line 362, Address: 0x100fbe4 */











void bring2move0(act_info* pActwk) { /* Line 374, Address: 0x100fc00 */
  patchg(pActwk, bring2chg); /* Line 375, Address: 0x100fc0c */
} /* Line 376, Address: 0x100fc20 */











void bring2move1(act_info* pActwk) { /* Line 388, Address: 0x100fc30 */
  frameout(pActwk); /* Line 389, Address: 0x100fc3c */
} /* Line 390, Address: 0x100fc48 */


















void bigring(act_info* pActwk) { /* Line 409, Address: 0x100fc60 */
  if (pActwk->userflag.b.h != 0) { /* Line 410, Address: 0x100fc6c */

    bring2(pActwk); /* Line 412, Address: 0x100fc84 */
    return; /* Line 413, Address: 0x100fc90 */
  }
  if (plring < 50) { /* Line 415, Address: 0x100fc98 */

    frameout_s(pActwk); /* Line 417, Address: 0x100fcb4 */
    return; /* Line 418, Address: 0x100fcc0 */
  }

  bigring_tbl[pActwk->r_no0 / 2](pActwk); /* Line 421, Address: 0x100fcc8 */
  if (pActwk->r_no0 == 4) return; /* Line 422, Address: 0x100fd0c */
  actionsub(pActwk); /* Line 423, Address: 0x100fd24 */
} /* Line 424, Address: 0x100fd30 */











void bring_init(act_info* pActwk) { /* Line 436, Address: 0x100fd40 */
  if (clrspflg_save == 127 || ta_flag != 0) { /* Line 437, Address: 0x100fd4c */

    frameout(pActwk); /* Line 439, Address: 0x100fd78 */
    return; /* Line 440, Address: 0x100fd84 */
  }

  pActwk->r_no0 += 2; /* Line 443, Address: 0x100fd8c */
  pActwk->actflg |= 4; /* Line 444, Address: 0x100fd9c */
  pActwk->sproffset = 9352; /* Line 445, Address: 0x100fdac */
  pActwk->patbase = bringpat; /* Line 446, Address: 0x100fdb8 */
  pActwk->sprhs = 32; /* Line 447, Address: 0x100fdc8 */
  pActwk->sprhsize = 32; /* Line 448, Address: 0x100fdd4 */
  pActwk->sprvsize = 32; /* Line 449, Address: 0x100fde0 */
  bring_move0(pActwk); /* Line 450, Address: 0x100fdec */
} /* Line 451, Address: 0x100fdf8 */











void bring_move0(act_info* pActwk) { /* Line 463, Address: 0x100fe10 */
  act_info *pActfree, *pPlaywk;
  short iD0, ret;
  do {
    pPlaywk = &actwk[0]; /* Line 467, Address: 0x100fe28 */
    ret = bring_coli(pActwk, pPlaywk); /* Line 468, Address: 0x100fe30 */
    if (ret == 0) { /* Line 469, Address: 0x100fe48 */
      bring_move1(pActwk); return; /* Line 470, Address: 0x100fe58 */
    }


    special_flag = 1; /* Line 474, Address: 0x100fe6c */
    pActwk->r_no0 += 2; /* Line 475, Address: 0x100fe78 */
    iD0 = scra_h_posit.w.h; /* Line 476, Address: 0x100fe88 */
    iD0 += 336; /* Line 477, Address: 0x100fe98 */
    pPlaywk->xposi.w.h = iD0; /* Line 478, Address: 0x100fea4 */
    plautoflag |= 1; /* Line 479, Address: 0x100fea8 */
    swdata.w = 2056; /* Line 480, Address: 0x100febc */
    pPlaywk->xspeed.w = 0; /* Line 481, Address: 0x100fec8 */
    pPlaywk->mspeed.w = 0; /* Line 482, Address: 0x100fecc */
    scroll_start.b.h = 1; /* Line 483, Address: 0x100fed0 */
    soundset(175); /* Line 484, Address: 0x100fedc */
    ret = actwkchk(&pActfree); /* Line 485, Address: 0x100fee8 */
  } while (ret != 0); /* Line 486, Address: 0x100ff04 */
  pActfree->actno = 20; /* Line 487, Address: 0x100ff14 */
  pActfree->xposi.w.h = pActwk->xposi.w.h; /* Line 488, Address: 0x100ff20 */
  pActfree->yposi.w.h = pActwk->yposi.w.h; /* Line 489, Address: 0x100ff30 */
  pActfree->userflag.b.h = 1; /* Line 490, Address: 0x100ff40 */

} /* Line 492, Address: 0x100ff4c */











void bring_move1(act_info* pActwk) { /* Line 504, Address: 0x100ff70 */
  patchg(pActwk, bringchg); /* Line 505, Address: 0x100ff7c */
} /* Line 506, Address: 0x100ff90 */













short bring_coli(act_info* pActwk, act_info* pPlaywk) { /* Line 520, Address: 0x100ffa0 */
  short iD0, iD1;

  iD0 = pPlaywk->sprhs; /* Line 523, Address: 0x100ffb4 */
  iD0 += 16; /* Line 524, Address: 0x100ffc8 */
  iD1 = pPlaywk->xposi.w.h - pActwk->xposi.w.h; /* Line 525, Address: 0x100ffd4 */
  iD1 += iD0; /* Line 526, Address: 0x1010008 */
  if (iD1 < 0) return 0; /* Line 527, Address: 0x1010014 */
  iD0 += iD0; /* Line 528, Address: 0x1010030 */
  if (iD1 >= iD0) return 0; /* Line 529, Address: 0x101003c */
  iD0 = pPlaywk->sprvsize; /* Line 530, Address: 0x1010064 */
  iD0 += 32; /* Line 531, Address: 0x1010078 */
  iD1 = pPlaywk->yposi.w.h - pActwk->yposi.w.h; /* Line 532, Address: 0x1010084 */
  iD1 += iD0; /* Line 533, Address: 0x10100b8 */
  if (iD1 < 0) return 0; /* Line 534, Address: 0x10100c4 */
  iD0 += iD0; /* Line 535, Address: 0x10100e0 */
  if (iD1 >= iD0) return 0; /* Line 536, Address: 0x10100ec */
  return 1; /* Line 537, Address: 0x1010114 */
} /* Line 538, Address: 0x1010118 */


















void mosugu(act_info* pActwk) { /* Line 557, Address: 0x1010130 */
  mosugu_tbl[pActwk->r_no0 / 2](pActwk, &actwk[0]); /* Line 558, Address: 0x101013c */
  if (stageno.b.l != 2) /* Line 559, Address: 0x1010188 */
    actionsub(pActwk); /* Line 560, Address: 0x10101a4 */
  frameout_s(pActwk); /* Line 561, Address: 0x10101b0 */
} /* Line 562, Address: 0x10101bc */











void mosug_init(act_info* pActwk, act_info* pPlaywk) { /* Line 574, Address: 0x10101d0 */
  if (stageno.b.l == 513 && time_flag == 1) { /* Line 575, Address: 0x10101e0 */

    if (pActwk->userflag.b.h == 0) { /* Line 577, Address: 0x1010214 */

      pActwk->userflag.b.h = 1; /* Line 579, Address: 0x101022c */

      return; /* Line 581, Address: 0x1010238 */
    }

    if (divdevwk[0] != 0) return; /* Line 584, Address: 0x1010240 */
  }


  pActwk->r_no0 += 2; /* Line 588, Address: 0x1010258 */
  pActwk->actflg |= 4; /* Line 589, Address: 0x1010268 */
  pActwk->sprpri = 4; /* Line 590, Address: 0x1010278 */
  pActwk->patbase = goalpat; /* Line 591, Address: 0x1010284 */
  pActwk->sprhs = 16; /* Line 592, Address: 0x1010294 */
  pActwk->sprhsize = 16; /* Line 593, Address: 0x10102a0 */
  pActwk->sprvsize = 32; /* Line 594, Address: 0x10102ac */
  pActwk->patno = 5; /* Line 595, Address: 0x10102b8 */
  offset_set(pActwk); /* Line 596, Address: 0x10102c4 */



  pActwk->sproffset %= 32768; /* Line 600, Address: 0x10102d0 */

  mosug_move0(pActwk, pPlaywk); /* Line 602, Address: 0x10102e0 */
} /* Line 603, Address: 0x10102f0 */












void mosug_move0(act_info* pActwk, act_info* pPlaywk) { /* Line 616, Address: 0x1010300 */
  short iD0;
  short iD1;

  iD0 = pPlaywk->xposi.w.h + pPlaywk->sprhsize; /* Line 620, Address: 0x1010314 */
  iD1 = pActwk->xposi.w.h - pActwk->sprhsize; /* Line 621, Address: 0x1010344 */
  if (iD0 >= iD1) { /* Line 622, Address: 0x1010374 */

    if ((pPlaywk->sproffset & 32768) == 0) { /* Line 624, Address: 0x1010390 */
      pPlaywk->sproffset &= 32768; /* Line 625, Address: 0x10103a8 */
    }
  }
  if (pPlaywk->xspeed.w < 0) { /* Line 628, Address: 0x10103b8 */

    pPlaywk->sproffset %= 32768; /* Line 630, Address: 0x10103d0 */
  }

  if (stageno.w == 1280 && scralim_left >= 11352 && pPlaywk->yposi.w.h >= 620 && pPlaywk->yposi.w.h < 653) { /* Line 633, Address: 0x10103e0 */

    pPlaywk->sproffset %= 32768; /* Line 635, Address: 0x1010450 */
  }



  iD0 = pPlaywk->yposi.w.h - pActwk->yposi.w.h; /* Line 640, Address: 0x1010460 */
  iD0 += 128; /* Line 641, Address: 0x1010494 */
  if (iD0 < 0) return; /* Line 642, Address: 0x10104a0 */

  if (iD0 >= 256) return; /* Line 644, Address: 0x10104b0 */

  if (pPlaywk->xposi.w.h < pActwk->xposi.w.h) return; /* Line 646, Address: 0x10104c4 */

  if (plflag == 2) return; /* Line 648, Address: 0x10104f0 */




  pActwk->r_no0 += 2; /* Line 653, Address: 0x1010508 */
  scralim_left = scra_h_posit.w.h; /* Line 654, Address: 0x1010518 */
  scralim_n_left = scra_h_posit.w.h; /* Line 655, Address: 0x1010528 */
  backto_cnt = 0; /* Line 656, Address: 0x1010538 */
  time_item = 0; /* Line 657, Address: 0x1010540 */
  plpower_a = 0; /* Line 658, Address: 0x1010548 */

} /* Line 660, Address: 0x1010550 */












void mosug_move1(act_info* pActwk, act_info* pPlaywk) { /* Line 673, Address: 0x1010570 */
  short iD0;
  short iD1;

  iD0 = pPlaywk->xposi.w.h - pPlaywk->sprhsize; /* Line 677, Address: 0x1010584 */
  iD1 = pActwk->xposi.w.h + pActwk->sprhsize; /* Line 678, Address: 0x10105b4 */
  if (iD1 < iD0) { /* Line 679, Address: 0x10105e4 */

    if (pPlaywk->sproffset & 32768) { /* Line 681, Address: 0x1010600 */
      pPlaywk->sproffset %= 32768; /* Line 682, Address: 0x1010618 */
    }
  }
} /* Line 685, Address: 0x1010628 */











void offset_set(act_info* pActwk) { /* Line 697, Address: 0x1010640 */
  short tbl[56] = { /* Line 698, Address: 0x1010650 */
     858, 1271, 1271, 1271,
     897, 1271, 1271, 1271,
     768,  768,  768,  768,
     768,  768,  768,  768,
    1266, 1266, 1266, 1266,
    1266, 1266, 1266, 1266,
     698,  716,  691,  689,
     698,  716,  691,  689,
     596,  556,  660,  568,
     632,  650,  700,  664,
     942,  942,  942,  942,
     942,  942,  942,  942,
     544,  545,  588,  566,
     574,  586,  605,  582
  };
  short iD0;
  short iD1;
  short_union stagewk;

  stagewk = stageno; /* Line 718, Address: 0x1010684 */
  stagewk.b.l = stagewk.b.l << 7; /* Line 719, Address: 0x1010690 */
  stagewk.w = stagewk.w >> 4; /* Line 720, Address: 0x101069c */
  iD0 = stagewk.b.l; /* Line 721, Address: 0x10106a8 */
  iD1 = time_flag; /* Line 722, Address: 0x10106bc */
  if (iD1 == 2) /* Line 723, Address: 0x10106d0 */
    iD1 += generate_flag; /* Line 724, Address: 0x10106e4 */
  iD1 += iD1; /* Line 725, Address: 0x10106fc */
  iD0 += iD1; /* Line 726, Address: 0x1010708 */
  pActwk->sproffset = tbl[iD0 / 2]; /* Line 727, Address: 0x1010714 */
  if (stageno.b.h != 3) /* Line 728, Address: 0x1010748 */
    pActwk->sproffset |= 32768; /* Line 729, Address: 0x1010764 */
} /* Line 730, Address: 0x1010774 */





















void goal(act_info* pActwk) { /* Line 752, Address: 0x1010790 */
  goal_tbl[pActwk->r_no0 / 2](pActwk); /* Line 753, Address: 0x101079c */
  actionsub(pActwk); /* Line 754, Address: 0x10107e0 */
} /* Line 755, Address: 0x10107ec */











void goal_init(act_info* pActwk) { /* Line 767, Address: 0x1010800 */
  pActwk->r_no0 += 2; /* Line 768, Address: 0x101080c */
  pActwk->actflg |= 4; /* Line 769, Address: 0x101081c */
  pActwk->sprhs = 24; /* Line 770, Address: 0x101082c */
  pActwk->sprhsize = 24; /* Line 771, Address: 0x1010838 */
  pActwk->sprvsize = 32; /* Line 772, Address: 0x1010844 */
  pActwk->sprpri = 4; /* Line 773, Address: 0x1010850 */
  pActwk->sproffset = 1084; /* Line 774, Address: 0x101085c */
  if (stageno.b.h != 0) /* Line 775, Address: 0x1010868 */
    pActwk->sproffset |= 128; /* Line 776, Address: 0x1010880 */
  pActwk->patbase = goalpat; /* Line 777, Address: 0x1010890 */
  goal_move0(pActwk); /* Line 778, Address: 0x10108a0 */
} /* Line 779, Address: 0x10108ac */











void goal_move0(act_info* pActwk) { /* Line 791, Address: 0x10108c0 */
  act_info* pPlaywk;
  short iD0;

  pPlaywk = &actwk[0]; /* Line 795, Address: 0x10108d4 */
  iD0 = pPlaywk->yposi.w.h - pActwk->yposi.w.h; /* Line 796, Address: 0x10108dc */
  iD0 += 128; /* Line 797, Address: 0x101090c */
  if (iD0 < 0) return; /* Line 798, Address: 0x1010918 */
  if (iD0 >= 256) return; /* Line 799, Address: 0x1010928 */
  if (pActwk->xposi.w.h >= pPlaywk->xposi.w.h) return; /* Line 800, Address: 0x101093c */
  scralim_left = scra_h_posit.w.h; /* Line 801, Address: 0x1010964 */
  scralim_n_left = scra_h_posit.w.h; /* Line 802, Address: 0x1010974 */
  pltime_f = 0; /* Line 803, Address: 0x1010984 */
  pActwk->actfree[0] = 120; /* Line 804, Address: 0x101098c */
  pActwk->patno = 0; /* Line 805, Address: 0x1010998 */
  pActwk->r_no0 += 2; /* Line 806, Address: 0x10109a0 */
  plpower_s = 0; /* Line 807, Address: 0x10109b0 */
  plpower_m = 0; /* Line 808, Address: 0x10109b8 */
  soundset(157); /* Line 809, Address: 0x10109c0 */
} /* Line 810, Address: 0x10109cc */











void goal_move1(act_info* pActwk) { /* Line 822, Address: 0x10109f0 */
  patchg(pActwk, goalchg); /* Line 823, Address: 0x10109fc */
  --pActwk->actfree[0]; /* Line 824, Address: 0x1010a10 */
  if (pActwk->actfree[0] != 0) return; /* Line 825, Address: 0x1010a20 */
  pActwk->r_no0 += 2; /* Line 826, Address: 0x1010a34 */
  pActwk->patno = 3; /* Line 827, Address: 0x1010a44 */
  pActwk->actfree[0] = 60; /* Line 828, Address: 0x1010a50 */
} /* Line 829, Address: 0x1010a5c */











void goal_move2(act_info* pActwk) { /* Line 841, Address: 0x1010a70 */
  act_info* pActfree;
  short iD0;
  char cTime;
  unsigned short timebonustbl[21] = { /* Line 845, Address: 0x1010a84 */
    50000, 50000, 10000,  5000,  4000,  4000,  3000,  3000,  2000,  2000,
     2000,  2000,  1000,  1000,  1000,  1000,   500,   500,   500,   500, 0
  };

  cTime = pActwk->actfree[0] + -1; /* Line 850, Address: 0x1010ab0 */
  pActwk->actfree[0] = cTime; /* Line 851, Address: 0x1010ad4 */
  if (cTime != 0) return; /* Line 852, Address: 0x1010adc */
  if (time_flag == 0) { /* Line 853, Address: 0x1010aec */
    sub_sync(130); /* Line 854, Address: 0x1010b00 */
  }
  sub_sync(107); /* Line 856, Address: 0x1010b0c */

  plautoflag |= 1; /* Line 858, Address: 0x1010b18 */
  swdata.w = 2056; /* Line 859, Address: 0x1010b2c */
  if (stageno.w == 1282) { /* Line 860, Address: 0x1010b38 */
    swdata.w = 0; /* Line 861, Address: 0x1010b54 */
  }
  pActwk->actfree[0] = 180; /* Line 863, Address: 0x1010b5c */
  pActwk->r_no0 += 2; /* Line 864, Address: 0x1010b68 */



  if (actwkchk(&pActfree) != 0) { /* Line 868, Address: 0x1010b78 */

    pActfree = &actwk[127]; /* Line 870, Address: 0x1010b8c */
    frameout(pActfree); /* Line 871, Address: 0x1010b98 */
  }

  pActfree->actno = 58; /* Line 874, Address: 0x1010ba4 */
  *(short*)&pActfree->actfree[8] = 16; /* Line 875, Address: 0x1010bb0 */

  bonus_f = 1; /* Line 877, Address: 0x1010bbc */
  iD0 = pltime.b.b3 + pltime.b.b2 * 60; /* Line 878, Address: 0x1010bc8 */
  iD0 /= 15; /* Line 879, Address: 0x1010c08 */
  if (iD0 >= 21) { /* Line 880, Address: 0x1010c28 */
    iD0 = 20; /* Line 881, Address: 0x1010c3c */
  }

  iD0 += iD0; /* Line 884, Address: 0x1010c48 */
  timebonus = timebonustbl[iD0 / 2]; /* Line 885, Address: 0x1010c54 */
  iD0 = plring; /* Line 886, Address: 0x1010c88 */
  ringbonus = iD0 * 100; /* Line 887, Address: 0x1010c98 */
} /* Line 888, Address: 0x1010cc4 */










void goal_move3(act_info* pActwk) { /* Line 900, Address: 0x1010ce0 */

  pActwk->xposi.w.h = pActwk->xposi.w.h; /* Line 902, Address: 0x1010ce8 */
} /* Line 903, Address: 0x1010cf8 */












void genecolor() { /* Line 915, Address: 0x1010d10 */
  palette_entry colortbl[16] = { /* Line 916, Address: 0x1010d20 */
    {  32,  32, 160, 1 }, {   0,   0,   0, 1 }, {  64,  64,  96, 1 }, {  96,  96, 160, 1 },
    { 128, 128, 192, 1 }, { 160, 160, 224, 1 }, { 224, 224, 224, 1 }, { 128, 224, 160, 1 },
    {  96, 160, 128, 1 }, {  64,  96,  96, 1 }, {  32,  64,  64, 1 }, {   0,  32,  32, 1 },
    { 224, 224,   0, 1 }, { 160, 160,   0, 1 }, {  64,  64,   0, 1 }, { 224,   0,   0, 1 }};
  short i;
  palette_entry *lpPeSrc, *lpPeDest;

  lpPeSrc = colortbl; /* Line 924, Address: 0x1010d54 */
  lpPeDest = lpcolorwk + 16; /* Line 925, Address: 0x1010d58 */
  for (i = 0; i < 16; ++i) { /* Line 926, Address: 0x1010d64 */
    *lpPeDest++ = *lpPeSrc++; /* Line 927, Address: 0x1010d70 */
  } /* Line 928, Address: 0x1010da0 */
} /* Line 929, Address: 0x1010dc0 */
