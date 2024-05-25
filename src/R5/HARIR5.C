#include "..\EQU.H"
#include "HARIR5.H"
#include "..\ACTION.H"
#include "..\RIDECHK.H"
#include "COLI5.H"

static void harir3_init(sprite_status* pActwk);
static void harir3_move(sprite_status* pActwk);
static void harir3_kind(sprite_status* pActwk);
static void harir3_ymv1(sprite_status* pActwk);
static void harir3_ymv2(sprite_status* pActwk);
static void harir3_xmv1(sprite_status* pActwk);
static void harir3_xmv2(sprite_status* pActwk);
static void harir3_sub(sprite_status* pActwk);

static sprite_pattern harir5_pat1 = {
  1,
  { { -16, -16, 0, 417 } }
};
static sprite_pattern harir5_pat2 = {
  1,
  { { -16, -16, 0, 418 } }
};
static sprite_pattern harir5_pat3 = {
  1,
  { { -16, -16, 0, 419 } }
};
static sprite_pattern harir5_pat4 = {
  1,
  { { -16, -16, 0, 420 } }
};
sprite_pattern* harir5pat[4] = {
  &harir5_pat1,
  &harir5_pat2,
  &harir5_pat3,
  &harir5_pat4
};
























































void harir5(sprite_status* pActwk) { /* Line 94, Address: 0x1023fa0 */
  sprite_status* pRideactwk;

  void(*harir3_acttbl[2])(sprite_status*) = { /* Line 97, Address: 0x1023fb0 */
    &harir3_init,
    &harir3_move
  };

  harir3_acttbl[pActwk->r_no0 / 2](pActwk); /* Line 102, Address: 0x1023fcc */
  actionsub(pActwk); /* Line 103, Address: 0x1024008 */

  if (((short*)pActwk)[28]) { /* Line 105, Address: 0x1024014 */
    pRideactwk = &actwk[((short*)pActwk)[28]]; /* Line 106, Address: 0x1024024 */
    pActwk->xposi.w.h = pRideactwk->xposi.w.h + (short)(char)pActwk->actfree[14]; /* Line 107, Address: 0x102404c */
    pActwk->yposi.w.h = pRideactwk->yposi.w.h + (short)(char)pActwk->actfree[15]; /* Line 108, Address: 0x102408c */
  }

  if ((unsigned short)( /* Line 111, Address: 0x10240cc */
      (((unsigned short*)pActwk)[29] & 65408) - ((unsigned short)(scra_h_posit.w.h - 128) & 65408)
      ) > 640) {
    if (pActwk->cdsts) { /* Line 114, Address: 0x1024114 */
      flagwork[time_flag + pActwk->cdsts * 3] &= 127; /* Line 115, Address: 0x1024124 */
    }
    frameout(pActwk); /* Line 117, Address: 0x1024160 */
  }
} /* Line 119, Address: 0x102416c */








static void harir3_init(sprite_status* pActwk) { /* Line 128, Address: 0x1024180 */
  unsigned char bD0;


  unsigned char harir3sztbl[12] = { /* Line 132, Address: 0x1024190 */
    18, 12,   0,
    18, 12, 131,
    10, 14, 130,
    10, 14, 130
  };

  pActwk->r_no0 += 2; /* Line 139, Address: 0x10241c4 */
  pActwk->actflg |= 4; /* Line 140, Address: 0x10241d4 */
  pActwk->sproffset = 1099; /* Line 141, Address: 0x10241e4 */
  pActwk->sprpri = 3; /* Line 142, Address: 0x10241f0 */
  pActwk->patbase = harir5pat; /* Line 143, Address: 0x10241fc */

  ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 145, Address: 0x102420c */
  ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 146, Address: 0x102421c */

  bD0 = pActwk->userflag.b.h & 3; /* Line 148, Address: 0x102422c */
  pActwk->patno = bD0; /* Line 149, Address: 0x1024248 */
  pActwk->sprhsize = harir3sztbl[bD0 * 3]; /* Line 150, Address: 0x1024250 */
  pActwk->sprvsize = harir3sztbl[bD0 * 3 + 1]; /* Line 151, Address: 0x102426c */
  pActwk->colino = harir3sztbl[bD0 * 3 + 2]; /* Line 152, Address: 0x102428c */

  harir3_move(pActwk); /* Line 154, Address: 0x10242ac */
} /* Line 155, Address: 0x10242b8 */








static void harir3_move(sprite_status* pActwk) { /* Line 164, Address: 0x10242d0 */
  harir3_kind(pActwk); /* Line 165, Address: 0x10242dc */


  if (pActwk->patno) { /* Line 168, Address: 0x10242e8 */
    hitchk(pActwk, &actwk[0]); /* Line 169, Address: 0x10242f8 */
  } /* Line 170, Address: 0x102430c */
  else {



    if (hitchk(pActwk, &actwk[0])) { /* Line 175, Address: 0x1024314 */
      if (pActwk->cddat & 8) { /* Line 176, Address: 0x1024330 */
        if (!plpower_a) { /* Line 177, Address: 0x1024348 */
          if (!plpower_m) { /* Line 178, Address: 0x1024358 */
            if (actwk[0].r_no0 < 4) { /* Line 179, Address: 0x1024368 */
              if (!((short*)&actwk[0])[26]) { /* Line 180, Address: 0x1024380 */
                actwk[0].yposi.l -= actwk[0].yspeed.w << 8; /* Line 181, Address: 0x1024390 */
                playdamageset(&actwk[0], pActwk); /* Line 182, Address: 0x10243b8 */
              }
            }
          }
        }
      }
    }
  }

} /* Line 191, Address: 0x10243cc */








static void harir3_kind(sprite_status* pActwk) { /* Line 200, Address: 0x10243e0 */
  void(*harir3_kndtbl[4])(sprite_status*) = { /* Line 201, Address: 0x10243ec */
    &harir3_ymv1,
    &harir3_ymv2,
    &harir3_xmv1,
    &harir3_xmv2
  };

  if (pActwk->userflag.b.h & 4) /* Line 208, Address: 0x1024418 */
    harir3_kndtbl[pActwk->userflag.b.h & 3](pActwk); /* Line 209, Address: 0x1024434 */
} /* Line 210, Address: 0x1024460 */








static void harir3_ymv1(sprite_status* pActwk) { /* Line 219, Address: 0x1024470 */
  harir3_sub(pActwk); /* Line 220, Address: 0x102447c */
  pActwk->yposi.w.h = (short)(unsigned short)pActwk->actfree[17] + ((short*)pActwk)[27]; /* Line 221, Address: 0x1024488 */
} /* Line 222, Address: 0x10244c8 */








static void harir3_ymv2(sprite_status* pActwk) { /* Line 231, Address: 0x10244e0 */
  harir3_sub(pActwk); /* Line 232, Address: 0x10244ec */
  pActwk->yposi.w.h = -(short)(unsigned short)pActwk->actfree[17] + ((short*)pActwk)[27]; /* Line 233, Address: 0x10244f8 */
} /* Line 234, Address: 0x102453c */







static void harir3_xmv1(sprite_status* pActwk) { /* Line 242, Address: 0x1024550 */
  harir3_sub(pActwk); /* Line 243, Address: 0x102455c */
  pActwk->xposi.w.h = -(short)(unsigned short)pActwk->actfree[17] + ((short*)pActwk)[29]; /* Line 244, Address: 0x1024568 */
} /* Line 245, Address: 0x10245ac */







static void harir3_xmv2(sprite_status* pActwk) { /* Line 253, Address: 0x10245c0 */
  harir3_sub(pActwk); /* Line 254, Address: 0x10245cc */
  pActwk->xposi.w.h = (short)(unsigned short)pActwk->actfree[17] + ((short*)pActwk)[29]; /* Line 255, Address: 0x10245d8 */
} /* Line 256, Address: 0x1024618 */








static void harir3_sub(sprite_status* pActwk) { /* Line 265, Address: 0x1024630 */
  if (pActwk->actfree[16]) { /* Line 266, Address: 0x1024638 */
    if (--pActwk->actfree[16]) return; /* Line 267, Address: 0x1024648 */
  }

  if (pActwk->actfree[18]) { /* Line 270, Address: 0x1024664 */
    if (pActwk->actfree[17] >= 8) { /* Line 271, Address: 0x1024674 */
      pActwk->actfree[17] -= 8; /* Line 272, Address: 0x102468c */
      return; /* Line 273, Address: 0x102469c */
    }
    pActwk->actfree[17] = 0; /* Line 275, Address: 0x10246a4 */
    pActwk->actfree[18] = 0; /* Line 276, Address: 0x10246ac */
    pActwk->actfree[16] = 60; /* Line 277, Address: 0x10246b4 */
  } /* Line 278, Address: 0x10246c0 */
  else {


    pActwk->actfree[17] += 8; /* Line 282, Address: 0x10246c8 */
    if (pActwk->actfree[17] >= 32) { /* Line 283, Address: 0x10246d8 */
      pActwk->actfree[17] = 32; /* Line 284, Address: 0x10246f0 */
      pActwk->actfree[18] = 1; /* Line 285, Address: 0x10246fc */
      pActwk->actfree[16] = 60; /* Line 286, Address: 0x1024708 */
    }
  }
} /* Line 289, Address: 0x1024714 */
