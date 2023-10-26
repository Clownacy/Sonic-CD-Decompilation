#include "EQU.H"
#include "ACTION.H"

extern void(*act_tbl[1])(act_info*);
extern void(*sMemSet)(void*, unsigned char, int);
extern void(*EAsprset)(short, short, unsigned short, unsigned short, unsigned short);
extern bmp_info SprBmp[700];
































void action() { /* Line 40, Address: 0x1001260 */
  act_info* pActwk;
  int i;

  pActwk = &actwk[0]; /* Line 44, Address: 0x1001270 */
  for (i = 0; i < 128; ++i, ++pActwk) { /* Line 45, Address: 0x1001278 */
    if (pActwk->actno) { /* Line 46, Address: 0x1001284 */






      act_tbl[pActwk->actno - 1](pActwk); /* Line 53, Address: 0x1001290 */
    }

  } /* Line 56, Address: 0x10012bc */
} /* Line 57, Address: 0x10012d0 */







void speedset(act_info* pActwk) { /* Line 65, Address: 0x10012f0 */
  int_union xpos, ypos;
  short_union spd;

  xpos.l = pActwk->xposi.l; /* Line 69, Address: 0x10012f8 */
  ypos.l = pActwk->yposi.l; /* Line 70, Address: 0x1001304 */
  spd.w = pActwk->xspeed.w; /* Line 71, Address: 0x1001310 */
  xpos.l += spd.w << 8; /* Line 72, Address: 0x100131c */
  spd.w = pActwk->yspeed.w; /* Line 73, Address: 0x1001338 */
  if (pActwk->actfree[2] & 8) goto label2; /* Line 74, Address: 0x1001344 */
  if (spd.w >= 0) goto label1; /* Line 75, Address: 0x100135c */
  if ((pActwk->actfree[2] & 2) == 0) goto label1; /* Line 76, Address: 0x1001370 */
  if (pActwk->yspeed.w < -2048) goto label2; /* Line 77, Address: 0x1001388 */
label1:
  if (pActwk->actfree[2] & 4) goto label2; /* Line 79, Address: 0x10013a4 */
  pActwk->yspeed.w += 56; /* Line 80, Address: 0x10013bc */
label2:
  if (pActwk->yspeed.w < 0) goto label3; /* Line 82, Address: 0x10013cc */
  if (pActwk->yspeed.w < 4096) goto label3; /* Line 83, Address: 0x10013e4 */
  pActwk->yspeed.w = 4096; /* Line 84, Address: 0x1001400 */
label3:
  ypos.l += spd.w << 8; /* Line 86, Address: 0x100140c */
  pActwk->xposi.l = xpos.l; /* Line 87, Address: 0x1001428 */
  pActwk->yposi.l = ypos.l; /* Line 88, Address: 0x1001434 */
} /* Line 89, Address: 0x1001440 */







void speedset2(act_info* pActwk) { /* Line 97, Address: 0x1001450 */
  int_union xpos, ypos;
  int spd;
  int actwkno;
  short d1;

  xpos.l = pActwk->xposi.l; /* Line 103, Address: 0x1001464 */
  ypos.l = pActwk->yposi.l; /* Line 104, Address: 0x1001470 */
  spd = pActwk->xspeed.w; /* Line 105, Address: 0x100147c */
  if (pActwk->cddat & 8) { /* Line 106, Address: 0x100148c */

    d1 = 0; /* Line 108, Address: 0x10014a4 */
    actwkno = pActwk->actfree[19]; /* Line 109, Address: 0x10014a8 */
    if (actwk[actwkno].actno == 30) { /* Line 110, Address: 0x10014b4 */

      d1 = -256; /* Line 112, Address: 0x10014e0 */


      if (actwk[actwkno].cddat & 1) d1 = -d1; /* Line 115, Address: 0x10014ec */

      spd += d1; /* Line 117, Address: 0x1001534 */
    }
  }
  spd = spd << 8; /* Line 120, Address: 0x1001540 */
  xpos.l += spd; /* Line 121, Address: 0x1001544 */
  spd = pActwk->yspeed.w; /* Line 122, Address: 0x1001550 */
  spd = spd << 8; /* Line 123, Address: 0x1001560 */
  ypos.l += spd; /* Line 124, Address: 0x1001564 */
  pActwk->xposi.l = xpos.l; /* Line 125, Address: 0x1001570 */
  pActwk->yposi.l = ypos.l; /* Line 126, Address: 0x100157c */
} /* Line 127, Address: 0x1001588 */







void actionsub(act_info* pActwk) { /* Line 135, Address: 0x10015a0 */
  int i;
  unsigned short flag;
  short hsiz, vsiz;
  short xpos, ypos;
  unsigned char pri;

  if (lpKeepWork->GamePass != 0) return; /* Line 142, Address: 0x10015c4 */

  pActwk->actflg %= 128; /* Line 144, Address: 0x10015d8 */
  flag = pActwk->actflg; /* Line 145, Address: 0x10015e8 */
  flag &= 12; /* Line 146, Address: 0x10015f8 */
  if (flag) { /* Line 147, Address: 0x1001600 */

    hsiz = pActwk->sprhsize; /* Line 149, Address: 0x1001608 */
    xpos = pActwk->xposi.w.h; /* Line 150, Address: 0x1001624 */
    xpos -= scra_h_posit.w.h; /* Line 151, Address: 0x1001634 */
    if (xpos + hsiz < 0) return; /* Line 152, Address: 0x1001648 */
    if (xpos - hsiz >= 320) return; /* Line 153, Address: 0x1001664 */

    vsiz = pActwk->sprvsize; /* Line 155, Address: 0x1001684 */
    ypos = pActwk->yposi.w.h; /* Line 156, Address: 0x10016a0 */
    if (scra_v_posit.w.h < 256) { /* Line 157, Address: 0x10016b0 */

      if (ypos >= 2048) ypos -= 2048; /* Line 159, Address: 0x10016cc */
    } /* Line 160, Address: 0x10016ec */
    else if (scra_v_posit.w.h >= 1792) { /* Line 161, Address: 0x10016f4 */

      if (ypos < 256) ypos += 2048; /* Line 163, Address: 0x1001710 */
    }
    ypos -= scra_v_posit.w.h; /* Line 165, Address: 0x1001730 */
    if (ypos + vsiz < 0) return; /* Line 166, Address: 0x1001744 */
    if (ypos - vsiz >= 224) return; /* Line 167, Address: 0x1001760 */
  }

  pri = pActwk->sprpri; /* Line 170, Address: 0x1001780 */
  i = pbuffer[pri].cnt; /* Line 171, Address: 0x100178c */
  if (i < 63) { /* Line 172, Address: 0x10017a4 */

    pbuffer[pri].pActwk[i] = pActwk; /* Line 174, Address: 0x10017b0 */
    pbuffer[pri].cnt += 1; /* Line 175, Address: 0x10017d4 */
  }
} /* Line 177, Address: 0x10017f4 */







void frameout(act_info* pActwk) { /* Line 185, Address: 0x1001820 */

  sMemSet(pActwk, 0, 68); /* Line 187, Address: 0x100182c */
} /* Line 188, Address: 0x1001848 */









void patset() { /* Line 198, Address: 0x1001860 */
  act_info* pActwk;
  unsigned char flag;
  short i;
  short act;
  short xposi, yposi;
  short patno;
  short cnt;
  spr_array* patadr;
  spr_array** patbase;
  spr_info* sprdat;
  int_union *pScrHposi, *pScrVposi;
  int_union* patsettbl[8] = /* Line 210, Address: 0x100188c */
  {
    0,
    &scra_h_posit,
    &scrb_h_posit,
    &scrc_h_posit,
    0,
    &scra_v_posit,
    &scrb_v_posit,
    &scrc_v_posit
  };

  if (lpKeepWork->GamePass != 0) return; /* Line 222, Address: 0x10018c0 */

  linkdata = 0; /* Line 224, Address: 0x10018d4 */
  for (i = 0; i < 8; ++i) { /* Line 225, Address: 0x10018dc */

    if (pbuffer[i].cnt == 0) continue; /* Line 227, Address: 0x10018e8 */
    act = 0; /* Line 228, Address: 0x100190c */
    do {

      pActwk = pbuffer[i].pActwk[act]; /* Line 231, Address: 0x1001910 */
      if (pActwk->actno && pActwk->patbase != 0) { /* Line 232, Address: 0x100193c */
        flag = pActwk->actflg >> 2; /* Line 233, Address: 0x1001954 */
        flag %= 4; /* Line 234, Address: 0x1001968 */
        if (flag) { /* Line 235, Address: 0x1001970 */

          pScrHposi = patsettbl[flag]; /* Line 237, Address: 0x1001978 */
          pScrVposi = patsettbl[flag + 4]; /* Line 238, Address: 0x100198c */
          xposi = pActwk->xposi.w.h; /* Line 239, Address: 0x10019a0 */
          xposi -= pScrHposi->w.h; /* Line 240, Address: 0x10019ac */
          xposi += 128; /* Line 241, Address: 0x10019c0 */
          yposi = pActwk->yposi.w.h; /* Line 242, Address: 0x10019cc */
          if (pScrVposi->w.h < 256) { /* Line 243, Address: 0x10019d8 */

            if (yposi >= 2048) yposi -= 2048; /* Line 245, Address: 0x10019f0 */
          } /* Line 246, Address: 0x1001a10 */
          else if (pScrVposi->w.h >= 1792) { /* Line 247, Address: 0x1001a18 */

            if (yposi < 256) yposi += 2048; /* Line 249, Address: 0x1001a30 */
          }
          yposi -= pScrVposi->w.h; /* Line 251, Address: 0x1001a50 */
          yposi += 128; /* Line 252, Address: 0x1001a60 */
        } /* Line 253, Address: 0x1001a6c */
        else {

          xposi = pActwk->xposi.w.h; /* Line 256, Address: 0x1001a74 */
          yposi = pActwk->yposi.w.h; /* Line 257, Address: 0x1001a80 */
        }

        patbase = pActwk->patbase; /* Line 260, Address: 0x1001a8c */
        patno = pActwk->patno; /* Line 261, Address: 0x1001a94 */
        patadr = patbase[patno]; /* Line 262, Address: 0x1001aa0 */
        cnt = patadr->cnt; /* Line 263, Address: 0x1001abc */
        sprdat = &patadr->spra[0]; /* Line 264, Address: 0x1001acc */
        if (pActwk->actflg & 32) { /* Line 265, Address: 0x1001ad4 */
          cnt = 1; /* Line 266, Address: 0x1001ae8 */
        }
        if (cnt > 0) { /* Line 268, Address: 0x1001af4 */
          spatset(xposi, yposi, pActwk, sprdat, cnt); /* Line 269, Address: 0x1001b04 */
        }
        pActwk->actflg |= 128; /* Line 271, Address: 0x1001b20 */
      }
      ++act; /* Line 273, Address: 0x1001b2c */
    } /* Line 274, Address: 0x1001b38 */
    while (--pbuffer[i].cnt > 0);
  } /* Line 276, Address: 0x1001b64 */

  for (i = linkdata; i < 80; ++i) { /* Line 278, Address: 0x1001b84 */
    EAsprset(0, 0, 0, i, 0); /* Line 279, Address: 0x1001ba8 */
  } /* Line 280, Address: 0x1001bcc */
} /* Line 281, Address: 0x1001bec */










void spatset(short xposi, short yposi, act_info* pActwk, spr_info* sprdat, short cnt) { /* Line 292, Address: 0x1001c20 */
  unsigned char flag;
  short x, y;
  unsigned short reverse;

  flag = pActwk->actflg; /* Line 297, Address: 0x1001c4c */
  flag %= 4; /* Line 298, Address: 0x1001c58 */
  while (cnt > 0) { /* Line 299, Address: 0x1001c60 */
    if (sprdat->index) { /* Line 300, Address: 0x1001c68 */
      if (linkdata >= 80) return; /* Line 301, Address: 0x1001c78 */

      switch (flag) { /* Line 303, Address: 0x1001c90 */
        case 0:
          x = xposi + sprdat->xoff; /* Line 305, Address: 0x1001cc8 */
          y = yposi + sprdat->yoff; /* Line 306, Address: 0x1001d00 */
          break; /* Line 307, Address: 0x1001d38 */
        case 1:
          x = xposi + (-(sprdat->xoff) - (short)(unsigned short)SprBmp[sprdat->index].xs); /* Line 309, Address: 0x1001d40 */
          y = yposi + sprdat->yoff; /* Line 310, Address: 0x1001db8 */
          break; /* Line 311, Address: 0x1001df0 */
        case 2:
          x = xposi + sprdat->xoff; /* Line 313, Address: 0x1001df8 */
          y = yposi + (-(sprdat->yoff) - (short)(unsigned short)SprBmp[sprdat->index].ys); /* Line 314, Address: 0x1001e30 */
          break; /* Line 315, Address: 0x1001ea8 */
        case 3:
          x = xposi + (-(sprdat->xoff) - (short)(unsigned short)SprBmp[sprdat->index].xs); /* Line 317, Address: 0x1001eb0 */
          y = yposi + (-(sprdat->yoff) - (short)(unsigned short)SprBmp[sprdat->index].ys); /* Line 318, Address: 0x1001f28 */
          break;
      }
      reverse = 0; /* Line 321, Address: 0x1001fa0 */
      if (pActwk->sproffset & 32768 || (sprdat->etc & 128) != 0) { /* Line 322, Address: 0x1001fa4 */
        reverse |= 32768; /* Line 323, Address: 0x1001fd4 */
      }
      if (((flag & 1) != 0) ^ ((sprdat->etc & 8) != 0)) { /* Line 325, Address: 0x1001fdc */
        ++reverse; /* Line 326, Address: 0x1002008 */
      }
      if (((flag & 2) != 0) ^ ((sprdat->etc & 16) != 0)) { /* Line 328, Address: 0x1002010 */
        reverse += 2; /* Line 329, Address: 0x100203c */
      }

      EAsprset(x, y, sprdat->index, linkdata, reverse); /* Line 332, Address: 0x1002044 */
      ++linkdata; /* Line 333, Address: 0x1002074 */
    }
    ++sprdat; /* Line 335, Address: 0x1002088 */
    --cnt; /* Line 336, Address: 0x1002094 */
  }
} /* Line 338, Address: 0x10020b4 */









int scronchk(act_info* pActwk) { /* Line 348, Address: 0x10020e0 */
  short xposi, yposi;

  xposi = pActwk->xposi.w.h; /* Line 351, Address: 0x10020f0 */
  xposi -= scra_h_posit.w.h; /* Line 352, Address: 0x1002100 */
  if (xposi < 0 || xposi >= 320) return -1; /* Line 353, Address: 0x1002114 */
  yposi = pActwk->yposi.w.h; /* Line 354, Address: 0x1002144 */
  yposi -= scra_v_posit.w.h; /* Line 355, Address: 0x1002154 */
  if (yposi < 0 || yposi >= 224) return -1; /* Line 356, Address: 0x1002168 */
  return 0; /* Line 357, Address: 0x1002198 */
} /* Line 358, Address: 0x100219c */







int scronchk2(act_info* pActwk) { /* Line 366, Address: 0x10021b0 */
  short xposi, yposi;
  short hsize;

  hsize = pActwk->sprhsize; /* Line 370, Address: 0x10021c4 */
  xposi = pActwk->xposi.w.h; /* Line 371, Address: 0x10021d8 */
  xposi -= scra_h_posit.w.h; /* Line 372, Address: 0x10021e8 */
  xposi += hsize; /* Line 373, Address: 0x10021fc */
  if (xposi < 0) return -1; /* Line 374, Address: 0x1002208 */
  hsize += hsize; /* Line 375, Address: 0x1002224 */
  xposi -= hsize; /* Line 376, Address: 0x1002230 */
  if (xposi >= 320) return -1; /* Line 377, Address: 0x100223c */
  yposi = pActwk->yposi.w.h; /* Line 378, Address: 0x100225c */
  yposi -= scra_v_posit.w.h; /* Line 379, Address: 0x100226c */
  if (yposi < 0 || yposi >= 224) return -1; /* Line 380, Address: 0x1002280 */
  return 0; /* Line 381, Address: 0x10022b0 */
} /* Line 382, Address: 0x10022b4 */
