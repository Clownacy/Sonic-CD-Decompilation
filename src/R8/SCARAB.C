#include "..\EQU.H"
#include "SCARAB.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"
#include "..\SUICIDE.H"

static void c_init(sprite_status* pActwk);
static void c_wait(sprite_status* pActwk);
static void c_make(sprite_status* pActwk);
static void ini_e_i(sprite_status* pActwk, sprite_status* pNewact);
static void c_move(sprite_status* pActwk);
static void enemy(sprite_status* pActwk);
static void e_init(sprite_status* pActwk);
static void e_move(sprite_status* pActwk);
static void turn(sprite_status* pActwk);
static void e1_check(sprite_status* pActwk);
static void e1_chk_patchg(sprite_status* pActwk);
static void e1_catch(sprite_status* pActwk);
static void e1_keep(sprite_status* pActwk);
static void e1_wait(sprite_status* pActwk);
static void iteminit(sprite_status* pActwk);
static void itemmove(sprite_status* pActwk);
static void itemmove2(sprite_status* pActwk);
static void itemmove3(sprite_status* pActwk);
static void itemget(sprite_status* pActwk);
static void ride_on_chk_i(sprite_status* pActwk, sprite_status* pPlayerwk);

static unsigned char pchg_n00[4] = { 9, 0, 1, 255 };
static unsigned char* pchg_n[1] = { pchg_n00 };
static unsigned char pchg_o00[4] = { 19, 0, 1, 255 };
static unsigned char* pchg_o[1] = { pchg_o00 };
static sprite_pattern pat00 = {
  1,
  { { -32, -12, 0, 402 } }
};
static sprite_pattern pat01 = {
  1,
  { { -32, -12, 0, 403 } }
};
static sprite_pattern pat02 = {
  1,
  { { -40, -12, 0, 404 } }
};
static sprite_pattern pat03 = {
  1,
  { { -24, -12, 0, 405 } }
};
static sprite_pattern pat04 = {
  1,
  { { -32, -12, 0, 406 } }
};
static sprite_pattern pat05 = {
  1,
  { { -32, -12, 0, 407 } }
};
sprite_pattern* pat_scarab[6] = {
  &pat00,
  &pat01,
  &pat02,
  &pat03,
  &pat04,
  &pat05
};
static void(*c_act_tbl[3])(sprite_status*) = {
  &c_init,
  &c_wait,
  &c_move
};
static void(*item_move_tbl[5])(sprite_status*) = {
  &iteminit,
  &itemmove,
  &itemget,
  &itemmove2,
  &itemmove3
};
static void(*e_act_tbl[2])(sprite_status*) = {
  &e_init,
  &e_move
};
static void(*e_move_tbl[3])(sprite_status*) = {
  &e1_check,
  &e1_keep,
  &e1_wait
};
extern sprite_pattern* itempat[];
extern unsigned char* itemchg[];







































































































































void scarab(sprite_status* pActwk) { /* Line 226, Address: 0x10207f0 */
  if ((unsigned char)pActwk->userflag.b.h == 2) { /* Line 227, Address: 0x10207fc */

    if (actwk[((short*)pActwk)[23]].actno != 47) { /* Line 229, Address: 0x1020818 */

      frameout(pActwk); return; /* Line 231, Address: 0x1020854 */
    }

    item_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 234, Address: 0x1020868 */
  } else if ((unsigned char)pActwk->userflag.b.h < 2) { /* Line 235, Address: 0x10208ac */

    enemy(pActwk); /* Line 237, Address: 0x10208d0 */
  } else { /* Line 238, Address: 0x10208dc */

    c_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 240, Address: 0x10208e4 */
  }
} /* Line 242, Address: 0x1020928 */





static void c_init(sprite_status* pActwk) { /* Line 248, Address: 0x1020940 */
  unsigned char flgwk;

  pActwk->r_no0 += 2; /* Line 251, Address: 0x1020950 */
  flgwk = pActwk->cdsts; /* Line 252, Address: 0x1020960 */
  flgwk = (time_flag & 127) + flgwk * 3; /* Line 253, Address: 0x102096c */
  *(unsigned char**)&pActwk->actfree[0] = &flagwork[flgwk]; /* Line 254, Address: 0x1020994 */

  c_wait(pActwk); /* Line 256, Address: 0x10209b0 */
} /* Line 257, Address: 0x10209bc */





static void c_wait(sprite_status* pActwk) { /* Line 263, Address: 0x10209d0 */
  unsigned short xwk, ywk;

  xwk = actwk[0].xposi.w.h - pActwk->xposi.w.h + 320; /* Line 266, Address: 0x10209e4 */
  ywk = actwk[0].yposi.w.h - pActwk->yposi.w.h + 320; /* Line 267, Address: 0x1020a14 */

  if (ywk < 640 && xwk < 640) { /* Line 269, Address: 0x1020a44 */
    c_make(pActwk); /* Line 270, Address: 0x1020a64 */
  } else { /* Line 271, Address: 0x1020a70 */
    frameout_s(pActwk); /* Line 272, Address: 0x1020a78 */
  }
} /* Line 274, Address: 0x1020a84 */





static void c_make(sprite_status* pActwk) { /* Line 280, Address: 0x1020aa0 */
  unsigned char *pFlagWork, flg;
  sprite_status* pNewact;

  pActwk->r_no0 += 2; /* Line 284, Address: 0x1020ab4 */
  pFlagWork = *(unsigned char**)&pActwk->actfree[0]; /* Line 285, Address: 0x1020ac4 */

  if (!(*pFlagWork & 1)) { /* Line 287, Address: 0x1020ad0 */
    if (actwkchk2(pActwk, &pNewact) != 0) { /* Line 288, Address: 0x1020ae4 */
      frameout_s0(pActwk); return; /* Line 289, Address: 0x1020afc */
    }

    ini_e_i(pActwk, pNewact); /* Line 292, Address: 0x1020b10 */
    ((short*)pActwk)[25] = pNewact - actwk; /* Line 293, Address: 0x1020b20 */
    pNewact->userflag.b.h = (unsigned char)(pActwk->userflag.b.h & 1); /* Line 294, Address: 0x1020b58 */

    if (pActwk->userflag.b.h & 16) { /* Line 296, Address: 0x1020b80 */
      pNewact->userflag.b.l = -1; /* Line 297, Address: 0x1020b9c */
    } else { /* Line 298, Address: 0x1020ba8 */
      pNewact->userflag.b.l = 0; /* Line 299, Address: 0x1020bb0 */
    }
  }


  if (!(*pFlagWork & 2)) { /* Line 304, Address: 0x1020bb8 */
    flg = pActwk->userflag.b.l; /* Line 305, Address: 0x1020bcc */

    if ((flg & 128) || flg > 7) { /* Line 307, Address: 0x1020bd8 */

      *pFlagWork |= 2; /* Line 309, Address: 0x1020bf8 */
    } /* Line 310, Address: 0x1020c04 */
    else {

      if (actwkchk2(pActwk, &pNewact) != 0) { /* Line 313, Address: 0x1020c0c */
        frameout_s0(pActwk); return; /* Line 314, Address: 0x1020c24 */
      }

      ini_e_i(pActwk, pNewact); /* Line 317, Address: 0x1020c38 */
      ((short*)pActwk)[26] = pNewact - actwk; /* Line 318, Address: 0x1020c48 */
      pNewact->userflag.b.h = 2; /* Line 319, Address: 0x1020c80 */
      pNewact->userflag.b.l = flg; /* Line 320, Address: 0x1020c8c */
      pNewact->yposi.w.h -= 4; /* Line 321, Address: 0x1020c94 */

      if (pActwk->userflag.b.h & 16) { /* Line 323, Address: 0x1020ca4 */
        pNewact->xposi.w.h += 24; /* Line 324, Address: 0x1020cc0 */
      } else { /* Line 325, Address: 0x1020cd0 */
        pNewact->xposi.w.h -= 24; /* Line 326, Address: 0x1020cd8 */
      }
    }
  }

} /* Line 331, Address: 0x1020ce8 */





static void ini_e_i(sprite_status* pActwk, sprite_status* pNewact) { /* Line 337, Address: 0x1020d00 */
  ((short*)pNewact)[23] = pActwk - actwk; /* Line 338, Address: 0x1020d0c */
  pNewact->actno = 47; /* Line 339, Address: 0x1020d44 */
  pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 340, Address: 0x1020d50 */
  pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 341, Address: 0x1020d60 */




  ((short*)pNewact)[27] = -1; /* Line 346, Address: 0x1020d70 */
} /* Line 347, Address: 0x1020d7c */





static void c_move(sprite_status* pActwk) { /* Line 353, Address: 0x1020d90 */
  unsigned char* pFlagWork;
  short idx;
  sprite_status* pChildAct;
  ushort_union flagwk;

  pFlagWork = *(unsigned char**)&pActwk->actfree[0]; /* Line 359, Address: 0x1020da8 */

  if (!(*pFlagWork & 1)) { /* Line 361, Address: 0x1020db4 */
    if ((idx = ((short*)pActwk)[25]) != 0) { /* Line 362, Address: 0x1020dc8 */
      pChildAct = &actwk[idx]; /* Line 363, Address: 0x1020de8 */

      if (pChildAct->actno != 47) { /* Line 365, Address: 0x1020e08 */

        *pFlagWork |= 1; /* Line 367, Address: 0x1020e1c */
        ((short*)pActwk)[25] = 0; /* Line 368, Address: 0x1020e28 */

        if ((idx = ((short*)pActwk)[26]) != 0) { /* Line 370, Address: 0x1020e30 */
          pChildAct = &actwk[idx]; /* Line 371, Address: 0x1020e50 */
          pChildAct->xspeed.w = 0; /* Line 372, Address: 0x1020e70 */
        }





        if ((idx = ((short*)pChildAct)[27]) >= 0) { /* Line 379, Address: 0x1020e74 */
          pChildAct = &actwk[idx]; /* Line 380, Address: 0x1020e90 */
          pChildAct->actfree[2] &= 254; /* Line 381, Address: 0x1020eb0 */
        }
      }
    }
  }








  if (!(*pFlagWork & 2)) { /* Line 394, Address: 0x1020ebc */
    if ((idx = ((short*)pActwk)[26]) != 0) { /* Line 395, Address: 0x1020ed0 */
      pChildAct = &actwk[idx]; /* Line 396, Address: 0x1020ef0 */

      if (pChildAct->actno != 47) { /* Line 398, Address: 0x1020f10 */

        *pFlagWork |= 2; /* Line 400, Address: 0x1020f24 */
        ((short*)pActwk)[26] = 0; /* Line 401, Address: 0x1020f30 */
      }
    }
  }






  if (*pFlagWork & 1) { /* Line 411, Address: 0x1020f38 */
    flagwk.b.h = 255; /* Line 412, Address: 0x1020f4c */
  } else { /* Line 413, Address: 0x1020f54 */
    flagwk.b.h = 0; /* Line 414, Address: 0x1020f5c */
  }

  if (*pFlagWork & 2) { /* Line 417, Address: 0x1020f60 */
    flagwk.b.l = 255; /* Line 418, Address: 0x1020f74 */
  } else { /* Line 419, Address: 0x1020f7c */
    flagwk.b.l = 0; /* Line 420, Address: 0x1020f84 */
  }

  if (flagwk.w == 65535) { /* Line 423, Address: 0x1020f88 */
    frameout(pActwk); return; /* Line 424, Address: 0x1020f9c */
  }

  flagwk.w == 0; /* Line 427, Address: 0x1020fb0 */



  if (!(((short*)pActwk)[25] | (((short*)pActwk)[26]))) { /* Line 431, Address: 0x1020fc0 */
    frameout_s0(pActwk); /* Line 432, Address: 0x1020fec */
  }
} /* Line 434, Address: 0x1020ff8 */






















static void enemy(sprite_status* pActwk) { /* Line 457, Address: 0x1021020 */
  sprite_status* pCtrlact;

  if (pActwk->userflag.b.l == 1) { /* Line 460, Address: 0x1021030 */

    if (actwk[((short*)pActwk)[23]].actno != 47) { /* Line 462, Address: 0x102104c */

      frameout(pActwk); return; /* Line 464, Address: 0x1021088 */
    }

    if (pActwk->r_no0) { /* Line 467, Address: 0x102109c */
      actionsub(pActwk); /* Line 468, Address: 0x10210ac */
    } /* Line 469, Address: 0x10210b8 */
    else {
      pActwk->r_no0 += 2; /* Line 471, Address: 0x10210c0 */
      pActwk->sprpri = 3; /* Line 472, Address: 0x10210d0 */
    }
  } else { /* Line 474, Address: 0x10210dc */
    pCtrlact = &actwk[((short*)pActwk)[23]]; /* Line 475, Address: 0x10210e4 */

    if (pCtrlact->actno != 47) { /* Line 477, Address: 0x102110c */
      frameout(pActwk); return; /* Line 478, Address: 0x1021120 */
    }

    if (!enemy_suicide(pActwk)) { /* Line 481, Address: 0x1021134 */



      e_act_tbl[pActwk->r_no0 / 2](pActwk); /* Line 485, Address: 0x1021148 */
      actionsub(pActwk); /* Line 486, Address: 0x102118c */
      frameout_s(pActwk); /* Line 487, Address: 0x1021198 */

      if (!pActwk->actno) { /* Line 489, Address: 0x10211a4 */
        ((short*)pCtrlact)[25] = 0; /* Line 490, Address: 0x10211b4 */
      }
    }
  }

} /* Line 495, Address: 0x10211b8 */





static void e_init(sprite_status* pActwk) { /* Line 501, Address: 0x10211d0 */
  sprite_status* pNewact;

  pActwk->r_no0 += 2; /* Line 504, Address: 0x10211dc */
  pActwk->actflg |= 4; /* Line 505, Address: 0x10211ec */
  pActwk->sprhs = pActwk->sprhsize = 32; /* Line 506, Address: 0x10211fc */
  pActwk->sprvsize = 11; /* Line 507, Address: 0x1021214 */
  pActwk->colino = 240; /* Line 508, Address: 0x1021220 */
  pActwk->sprpri = 1; /* Line 509, Address: 0x102122c */
  pActwk->sproffset = 9279; /* Line 510, Address: 0x1021238 */
  pActwk->patbase = pat_scarab; /* Line 511, Address: 0x1021244 */
  ((short*)pActwk)[24] = pActwk->xposi.w.h; /* Line 512, Address: 0x1021254 */
  ((short*)pActwk)[28] = 60; /* Line 513, Address: 0x1021264 */
  pActwk->yposi.w.h += emycol_d(pActwk); /* Line 514, Address: 0x1021270 */


  if (actwkchk2(pActwk, &pNewact) != 0) { /* Line 517, Address: 0x102128c */
    frameout_s0(pActwk); return; /* Line 518, Address: 0x10212a4 */
  }

  pNewact->actno = 47; /* Line 521, Address: 0x10212b8 */
  pNewact->userflag.b.l = 1; /* Line 522, Address: 0x10212c4 */
  pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 523, Address: 0x10212d0 */
  pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 524, Address: 0x10212e0 */
  pNewact->actflg = pActwk->actflg; /* Line 525, Address: 0x10212f0 */
  pNewact->sprhs = pActwk->sprhs; /* Line 526, Address: 0x1021300 */
  pNewact->sprhsize = pActwk->sprhsize; /* Line 527, Address: 0x1021310 */
  pNewact->sprvsize = pActwk->sprvsize; /* Line 528, Address: 0x1021320 */
  pNewact->sproffset = pActwk->sproffset; /* Line 529, Address: 0x1021330 */
  pNewact->patbase = pActwk->patbase; /* Line 530, Address: 0x1021340 */
  ((short*)pActwk)[32] = pNewact - actwk; /* Line 531, Address: 0x1021350 */
  ((short*)pNewact)[23] = pActwk - actwk; /* Line 532, Address: 0x1021388 */

  if (pActwk->userflag.b.l) { /* Line 534, Address: 0x10213c0 */

    pActwk->actflg |= 1; /* Line 536, Address: 0x10213d0 */
    pNewact->actflg |= 1; /* Line 537, Address: 0x10213e0 */
    pActwk->cddat |= 1; /* Line 538, Address: 0x10213f0 */
    pNewact->cddat |= 1; /* Line 539, Address: 0x1021400 */
  }


  if (!pActwk->userflag.b.h) { /* Line 543, Address: 0x1021410 */

    ((unsigned char***)pActwk)[15] = pchg_n; /* Line 545, Address: 0x1021420 */
    *(int*)&pActwk->actfree[4] = 24576; /* Line 546, Address: 0x1021430 */
  } /* Line 547, Address: 0x1021440 */
  else {
    ((unsigned char***)pActwk)[15] = pchg_o; /* Line 549, Address: 0x1021448 */
    *(int*)&pActwk->actfree[4] = 12288; /* Line 550, Address: 0x1021458 */
  }

  e_move(pActwk); /* Line 553, Address: 0x1021468 */
} /* Line 554, Address: 0x1021474 */










static void e_move(sprite_status* pActwk) { /* Line 565, Address: 0x1021490 */
  short xSav, ySav, wk;
  sprite_status* pSubact;

  ySav = pActwk->yposi.w.h; /* Line 569, Address: 0x10214ac */
  xSav = pActwk->xposi.w.h; /* Line 570, Address: 0x10214bc */

  if (((short*)pActwk)[28] >= 0) { /* Line 572, Address: 0x10214cc */
    pActwk->xposi.l += *(int*)&pActwk->actfree[4]; /* Line 573, Address: 0x10214e4 */

    if ((wk = pActwk->xposi.w.h - ((short*)pActwk)[24]) < 0) { /* Line 575, Address: 0x1021500 */
      wk *= -1; /* Line 576, Address: 0x102154c */
    }


    if (wk >= 64) { /* Line 580, Address: 0x1021558 */
      turn(pActwk); /* Line 581, Address: 0x102156c */
    }


    wk = emycol_d(pActwk); /* Line 585, Address: 0x1021578 */
    if (wk + 7 >= 14) { /* Line 586, Address: 0x102158c */

      turn(pActwk); /* Line 588, Address: 0x10215a4 */
    } /* Line 589, Address: 0x10215b0 */
    else {
      pActwk->yposi.w.h += wk; /* Line 591, Address: 0x10215b8 */
    }
  }




  xSav -= pActwk->xposi.w.h; /* Line 598, Address: 0x10215c8 */
  ySav -= pActwk->yposi.w.h; /* Line 599, Address: 0x10215dc */

  pSubact = &actwk[((short*)pActwk)[23]]; /* Line 601, Address: 0x10215f0 */
  if ((wk = ((short*)pSubact)[26]) != 0) { /* Line 602, Address: 0x1021618 */
    pSubact = &actwk[wk]; /* Line 603, Address: 0x1021634 */
    pSubact->xposi.w.h -= xSav; /* Line 604, Address: 0x1021654 */
    pSubact->yposi.w.h -= ySav; /* Line 605, Address: 0x1021660 */
    pSubact->xspeed.w = -xSav << 8; /* Line 606, Address: 0x102166c */
  }





  if ((wk = ((short*)pActwk)[27]) >= 0) { /* Line 613, Address: 0x1021688 */
    pSubact = &actwk[wk]; /* Line 614, Address: 0x10216a8 */
    pSubact->xposi.w.h -= xSav; /* Line 615, Address: 0x10216c8 */
    pSubact->yposi.w.h -= ySav; /* Line 616, Address: 0x10216d4 */
  }


  e_move_tbl[pActwk->r_no1 / 2](pActwk); /* Line 620, Address: 0x10216e0 */
  pSubact = &actwk[((short*)pActwk)[32]]; /* Line 621, Address: 0x1021724 */
  pSubact->xposi.w.h = pActwk->xposi.w.h; /* Line 622, Address: 0x102174c */
  pSubact->yposi.w.h = pActwk->yposi.w.h; /* Line 623, Address: 0x1021758 */
  pSubact->patno = pActwk->patno + 3; /* Line 624, Address: 0x1021764 */
} /* Line 625, Address: 0x102177c */





static void turn(sprite_status* pActwk) { /* Line 631, Address: 0x10217a0 */
  pActwk->xposi.l -= *(int*)&pActwk->actfree[4]; /* Line 632, Address: 0x10217a8 */
  *(int*)&pActwk->actfree[4] *= -1; /* Line 633, Address: 0x10217c4 */
} /* Line 634, Address: 0x10217dc */





static void e1_check(sprite_status* pActwk) { /* Line 640, Address: 0x10217f0 */
  if (!pActwk->colicnt) goto label1; /* Line 641, Address: 0x10217fc */
  if (actwk[0].r_no0 == 4 /* Line 642, Address: 0x102180c */
      || actwk[0].r_no0 == 6
      || ((short*)&actwk[0])[26]
      || ((short*)&actwk[((short*)pActwk)[23]])[26]) {
    pActwk->colicnt = 0; /* Line 646, Address: 0x1021880 */
    goto label1; /* Line 647, Address: 0x1021888 */
  }
  e1_catch(pActwk); /* Line 649, Address: 0x1021890 */
  return; /* Line 650, Address: 0x102189c */



label1:
    e1_chk_patchg(pActwk); /* Line 655, Address: 0x10218a4 */
} /* Line 656, Address: 0x10218b0 */





static void e1_chk_patchg(sprite_status* pActwk) { /* Line 662, Address: 0x10218c0 */
  if (--((short*)pActwk)[28] >= 0) { /* Line 663, Address: 0x10218cc */

    patchg(pActwk, ((unsigned char***)pActwk)[15]); /* Line 665, Address: 0x10218f4 */
  } /* Line 666, Address: 0x1021908 */
  else if (((short*)pActwk)[28] <= -30) { /* Line 667, Address: 0x1021910 */
    ((short*)pActwk)[28] = 60; /* Line 668, Address: 0x102192c */
  }



} /* Line 673, Address: 0x1021938 */





static void e1_catch(sprite_status* pActwk) { /* Line 679, Address: 0x1021950 */
  ((short*)pActwk)[27] = &actwk[0] - actwk; /* Line 680, Address: 0x1021958 */
  actwk[0].actfree[2] |= 1; /* Line 681, Address: 0x1021994 */
  actwk[0].cddat |= 4; /* Line 682, Address: 0x10219a8 */
  actwk[0].mstno.b.h = 2; /* Line 683, Address: 0x10219bc */
  actwk[0].sprvsize = 14; /* Line 684, Address: 0x10219c8 */
  actwk[0].sprhs = 7; /* Line 685, Address: 0x10219d4 */
  actwk[0].yposi.w.h = pActwk->yposi.w.h - 3; /* Line 686, Address: 0x10219e0 */

  if (!pActwk->userflag.b.l) { /* Line 688, Address: 0x1021a04 */

    actwk[0].xposi.w.h = pActwk->xposi.w.h - 24; /* Line 690, Address: 0x1021a14 */
  } /* Line 691, Address: 0x1021a38 */
  else {
    actwk[0].xposi.w.h = pActwk->xposi.w.h + 24; /* Line 693, Address: 0x1021a40 */
  }

  pActwk->r_no1 += 2; /* Line 696, Address: 0x1021a64 */
  ((short*)pActwk)[29] = 120; /* Line 697, Address: 0x1021a74 */
  pActwk->colino = 240, pActwk->colicnt = 0; /* Line 698, Address: 0x1021a80 */
} /* Line 699, Address: 0x1021a94 */





static void e1_keep(sprite_status* pActwk) { /* Line 705, Address: 0x1021aa0 */
  sprite_status* pPlayerwk;

  if (--((short*)pActwk)[29] != 0) { /* Line 708, Address: 0x1021ab0 */
    pActwk->colino = 240, pActwk->colicnt = 0; /* Line 709, Address: 0x1021ad8 */
    e1_chk_patchg(pActwk); /* Line 710, Address: 0x1021aec */
  } /* Line 711, Address: 0x1021af8 */
  else {
    pPlayerwk = &actwk[((short*)pActwk)[27]]; /* Line 713, Address: 0x1021b00 */



    ((short*)pActwk)[27] = -1; /* Line 717, Address: 0x1021b28 */
    pPlayerwk->actfree[2] &= 254; /* Line 718, Address: 0x1021b34 */
    pPlayerwk->yspeed.w = 0; /* Line 719, Address: 0x1021b40 */

    if (!pActwk->userflag.b.h) { /* Line 721, Address: 0x1021b44 */

      pPlayerwk->xspeed.w = -2560; /* Line 723, Address: 0x1021b54 */
    } /* Line 724, Address: 0x1021b5c */
    else {
      pPlayerwk->xspeed.w = -1280; /* Line 726, Address: 0x1021b64 */
    }

    if (!pActwk->userflag.b.l) { /* Line 729, Address: 0x1021b6c */

      pPlayerwk->cddat |= 1; /* Line 731, Address: 0x1021b7c */
    } /* Line 732, Address: 0x1021b88 */
    else {
      pPlayerwk->xspeed.w *= -1; /* Line 734, Address: 0x1021b90 */
      pPlayerwk->cddat &= 254; /* Line 735, Address: 0x1021b9c */
    }

    ((short*)pPlayerwk)[33] = 15; /* Line 738, Address: 0x1021ba8 */
    pPlayerwk->mspeed.w = pPlayerwk->xspeed.w; /* Line 739, Address: 0x1021bb0 */
    pPlayerwk->direc.b.h = 0; /* Line 740, Address: 0x1021bb8 */
    pPlayerwk->cddat &= 223; /* Line 741, Address: 0x1021bbc */

    pActwk->r_no1 += 2; /* Line 743, Address: 0x1021bc8 */
    pActwk->colino = pActwk->colicnt = 0; /* Line 744, Address: 0x1021bd8 */
    pActwk->patno = 2; /* Line 745, Address: 0x1021bec */
    ((short*)pActwk)[29] = 30; /* Line 746, Address: 0x1021bf8 */
  }
} /* Line 748, Address: 0x1021c04 */





static void e1_wait(sprite_status* pActwk) { /* Line 754, Address: 0x1021c20 */
  if (!(--((short*)pActwk)[29])) { /* Line 755, Address: 0x1021c28 */

    pActwk->r_no1 = 0; /* Line 757, Address: 0x1021c48 */
    pActwk->mstno.b.l = -1; /* Line 758, Address: 0x1021c50 */
    pActwk->colino = 240, pActwk->colicnt = 0; /* Line 759, Address: 0x1021c5c */
  }
} /* Line 761, Address: 0x1021c70 */








static void iteminit(sprite_status* pActwk) { /* Line 770, Address: 0x1021c80 */
  pActwk->r_no0 += 2; /* Line 771, Address: 0x1021c8c */
  pActwk->sprvsize = 14; /* Line 772, Address: 0x1021c9c */
  pActwk->sprhs = 14; /* Line 773, Address: 0x1021ca8 */
  pActwk->patbase = itempat; /* Line 774, Address: 0x1021cb4 */
  pActwk->sproffset = 1448; /* Line 775, Address: 0x1021cc4 */
  pActwk->actflg = 4; /* Line 776, Address: 0x1021cd0 */
  pActwk->sprpri = 2; /* Line 777, Address: 0x1021cdc */
  pActwk->sprhsize = 15; /* Line 778, Address: 0x1021ce8 */
  pActwk->colino = 198; /* Line 779, Address: 0x1021cf4 */
  pActwk->mstno.b.h = pActwk->userflag.b.l; /* Line 780, Address: 0x1021d00 */
  pActwk->yposi.w.h += emycol_d(pActwk); /* Line 781, Address: 0x1021d10 */

  itemmove(pActwk); /* Line 783, Address: 0x1021d2c */
} /* Line 784, Address: 0x1021d38 */





static void itemmove(sprite_status* pActwk) { /* Line 790, Address: 0x1021d50 */
  short col;

  if (!(pActwk->actflg & 128)) { /* Line 793, Address: 0x1021d60 */
    itemmove3(pActwk); /* Line 794, Address: 0x1021d78 */
  } else { /* Line 795, Address: 0x1021d84 */
    if (pActwk->r_no1) { /* Line 796, Address: 0x1021d8c */
      speedset(pActwk); /* Line 797, Address: 0x1021d9c */

      if ((col = emycol_d(pActwk)) < 0) { /* Line 799, Address: 0x1021da8 */
        pActwk->yposi.w.h += col; /* Line 800, Address: 0x1021dd4 */
        pActwk->yspeed.w = 0; /* Line 801, Address: 0x1021de4 */
        pActwk->r_no1 = 0; /* Line 802, Address: 0x1021dec */
      }
    } /* Line 804, Address: 0x1021df4 */
    else {






      ride_on_chk_i(pActwk, &actwk[0]); /* Line 812, Address: 0x1021dfc */
    }


    itemmove2(pActwk); /* Line 816, Address: 0x1021e10 */
  }
} /* Line 818, Address: 0x1021e1c */





static void itemmove2(sprite_status* pActwk) { /* Line 824, Address: 0x1021e30 */
  if (!time_stop) { /* Line 825, Address: 0x1021e3c */
    patchg(pActwk, itemchg); /* Line 826, Address: 0x1021e4c */
  }

  itemmove3(pActwk); /* Line 829, Address: 0x1021e60 */
} /* Line 830, Address: 0x1021e6c */





static void itemmove3(sprite_status* pActwk) { /* Line 836, Address: 0x1021e80 */
  sprite_status* pCtrlact;

  actionsub(pActwk); /* Line 839, Address: 0x1021e90 */
  pCtrlact = &actwk[((short*)pActwk)[23]]; /* Line 840, Address: 0x1021e9c */
  frameout_s(pActwk); /* Line 841, Address: 0x1021ec4 */

  if (!pActwk->actno) { /* Line 843, Address: 0x1021ed0 */
    ((short*)pCtrlact)[26] = 0; /* Line 844, Address: 0x1021ee0 */
  }


} /* Line 848, Address: 0x1021ee4 */





static void itemget(sprite_status* pActwk) { /* Line 854, Address: 0x1021f00 */
  sprite_status *pCtrlact, *pNewact;
  short idx;

  pCtrlact = &actwk[((short*)pActwk)[23]]; /* Line 858, Address: 0x1021f14 */

  if ((idx = ((short*)pCtrlact)[25]) != 0) { /* Line 860, Address: 0x1021f3c */
    actwk[idx].colicnt = 1; /* Line 861, Address: 0x1021f58 */
  }


  ride_on_chk_i(pActwk, &actwk[0]); /* Line 865, Address: 0x1021f80 */
  ride_on_clr(pActwk, &actwk[0]); /* Line 866, Address: 0x1021f94 */

  soundset(150); /* Line 868, Address: 0x1021fa8 */
  pActwk->r_no0 += 4; /* Line 869, Address: 0x1021fb4 */
  pActwk->colino = 0; /* Line 870, Address: 0x1021fc4 */

  if (actwkchk(&pNewact) == 0) { /* Line 872, Address: 0x1021fcc */
    pNewact->actno = 26; /* Line 873, Address: 0x1021fe0 */
    pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 874, Address: 0x1021fec */
    pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 875, Address: 0x1021ffc */
    pNewact->mstno.b.h = pActwk->mstno.b.h; /* Line 876, Address: 0x102200c */

    if (actwkchk(&pNewact) == 0) { /* Line 878, Address: 0x102201c */
      pNewact->actno = 24; /* Line 879, Address: 0x1022030 */
      pNewact->xposi.w.h = pActwk->xposi.w.h; /* Line 880, Address: 0x102203c */
      pNewact->yposi.w.h = pActwk->yposi.w.h; /* Line 881, Address: 0x102204c */
      pNewact->r_no1 = 1; /* Line 882, Address: 0x102205c */
      pNewact->userflag.b.h = 1; /* Line 883, Address: 0x1022068 */
    }
  }

  frameout(pActwk); /* Line 887, Address: 0x1022074 */
} /* Line 888, Address: 0x1022080 */





static void ride_on_chk_i(sprite_status* pActwk, sprite_status* pPlayerwk) { /* Line 894, Address: 0x10220a0 */
  pActwk->actno = 25; /* Line 895, Address: 0x10220b0 */
  ride_on_chk(pActwk, pPlayerwk); /* Line 896, Address: 0x10220bc */
  pActwk->actno = 47; /* Line 897, Address: 0x10220cc */
} /* Line 898, Address: 0x10220d8 */
