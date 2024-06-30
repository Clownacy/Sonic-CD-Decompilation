#include "..\EQU.H"
#include "HARI73.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"
#include "BOSS_7.H"
#include "COLI7.H"

static void hari73_init(sprite_status* pActwk);
static void hari73_move(sprite_status* pActwk);
static void msnc_hit(sprite_status* pActwk);
static void hari73_tobi(sprite_status* pActwk);
static short act_search(sprite_status** ppActwk, unsigned char bD0);

static sprite_pattern hari73_pat0 = {
  1,
  { { -16, -16, 0, 419 } }
};
static sprite_pattern hari73_pat1 = {
  1,
  { { -4, -16, 0, 420 } }
};
sprite_pattern* hari73_pat[2] = {
  &hari73_pat0,
  &hari73_pat1
};














































void hari73(sprite_status* pActwk) { /* Line 74, Address: 0x1028aa0 */
  void(*hari73_acttbl[3])(sprite_status*) = { /* Line 75, Address: 0x1028aac */
    &hari73_init,
    &hari73_move,
    &hari73_tobi
  };

  hari73_acttbl[pActwk->r_no0 / 2](pActwk); /* Line 81, Address: 0x1028ad0 */
} /* Line 82, Address: 0x1028b0c */








static void hari73_init(sprite_status* pActwk) { /* Line 91, Address: 0x1028b20 */
  sprite_status* pNewactwk;

  pActwk->r_no0 += 2; /* Line 94, Address: 0x1028b2c */
  pActwk->actflg |= 4; /* Line 95, Address: 0x1028b3c */
  pActwk->sprpri = 3; /* Line 96, Address: 0x1028b4c */
  pActwk->sproffset = 1276; /* Line 97, Address: 0x1028b58 */
  pActwk->patbase = hari73_pat; /* Line 98, Address: 0x1028b64 */
  pActwk->sprhs = 16; /* Line 99, Address: 0x1028b74 */
  pActwk->sprhsize = 16; /* Line 100, Address: 0x1028b80 */
  pActwk->sprvsize = 12; /* Line 101, Address: 0x1028b8c */
  if (!act_search(&pNewactwk, 47)) { /* Line 102, Address: 0x1028b98 */
    ((short*)pActwk)[23] = pNewactwk - actwk; /* Line 103, Address: 0x1028bb0 */


    if (pActwk->xposi.w.h - (short)pActwk->sprhsize - pNewactwk->xposi.w.h - (short)pNewactwk->sprhsize >= 0) { /* Line 106, Address: 0x1028be8 */
      hari73_move(pActwk); /* Line 107, Address: 0x1028c44 */
      return; /* Line 108, Address: 0x1028c50 */
    }
  }


  frameout(pActwk); /* Line 113, Address: 0x1028c58 */
} /* Line 114, Address: 0x1028c64 */








static void hari73_move(sprite_status* pActwk) { /* Line 123, Address: 0x1028c80 */
  short wD0;
  sprite_status* pNewactwk;

  if (((short*)pActwk)[23]) { /* Line 127, Address: 0x1028c94 */
    pNewactwk = &actwk[((short*)pActwk)[23]]; /* Line 128, Address: 0x1028ca4 */
    wD0 = pActwk->xposi.w.h - pNewactwk->xposi.w.h; /* Line 129, Address: 0x1028ccc */
    if (pActwk->xposi.w.h < pNewactwk->xposi.w.h) { /* Line 130, Address: 0x1028cfc */
      wD0 *= -1; /* Line 131, Address: 0x1028d24 */
    }
    if ((short)pActwk->sprhsize > wD0) { /* Line 133, Address: 0x1028d30 */
      msnc_hit(pActwk); /* Line 134, Address: 0x1028d58 */
      return; /* Line 135, Address: 0x1028d64 */
    }
  }

  if (hitchk(pActwk, &actwk[0])) { /* Line 139, Address: 0x1028d6c */
    actwk[0].colino = 0; /* Line 140, Address: 0x1028d88 */
    pActwk->actfree[11] = 0; /* Line 141, Address: 0x1028d90 */
    if (actwk[0].cddat & 8) { /* Line 142, Address: 0x1028d98 */
      pActwk->actfree[11] = 1; /* Line 143, Address: 0x1028db0 */

      if (!plpower_m) { /* Line 145, Address: 0x1028dbc */
        if (actwk[0].r_no0 != 4) { /* Line 146, Address: 0x1028dcc */
          if (!actwk[0].actfree[6]) { /* Line 147, Address: 0x1028de4 */
            actwk[0].yposi.l -= actwk[0].yspeed.w << 8; /* Line 148, Address: 0x1028df4 */
            playdamageset(&actwk[0], pActwk); /* Line 149, Address: 0x1028e1c */
            ride_on_clr(pActwk, &actwk[0]); /* Line 150, Address: 0x1028e30 */
          }
        }
      }
    }
  }

  actionsub(pActwk); /* Line 157, Address: 0x1028e44 */
  frameout_s(pActwk); /* Line 158, Address: 0x1028e50 */
} /* Line 159, Address: 0x1028e5c */


static void msnc_hit(sprite_status* pActwk) { /* Line 162, Address: 0x1028e80 */
  int i;
  short wD4;
  sprite_status* pNewactwk;

  short spd_tbl[16] = { /* Line 167, Address: 0x1028e94 */
    576, -512, 6, 16,
    544, -512, 0, 18,
    512, -512, 6, 20,
    480, -512, 10, 16
  };


  soundset(163); /* Line 175, Address: 0x1028ec8 */

  wD4 = -12; /* Line 177, Address: 0x1028ed4 */

  for (i = 0; i < 16; i += 4) { /* Line 179, Address: 0x1028ee0 */
    if (actwkchk(&pNewactwk) != 0) break; /* Line 180, Address: 0x1028eec */
    pNewactwk->actno = 50; /* Line 181, Address: 0x1028f00 */
    pNewactwk->r_no0 = 4; /* Line 182, Address: 0x1028f0c */
    pNewactwk->patno = 1; /* Line 183, Address: 0x1028f18 */

    pNewactwk->actflg = 4; /* Line 185, Address: 0x1028f24 */
    pNewactwk->sprpri = 5; /* Line 186, Address: 0x1028f30 */
    pNewactwk->sprhsize = 4; /* Line 187, Address: 0x1028f3c */
    pNewactwk->sprvsize = 16; /* Line 188, Address: 0x1028f48 */
    pNewactwk->sproffset = 1276; /* Line 189, Address: 0x1028f54 */
    pNewactwk->patbase = hari73_pat; /* Line 190, Address: 0x1028f60 */

    pNewactwk->xposi.w.h = pActwk->xposi.w.h + wD4; /* Line 192, Address: 0x1028f70 */
    pNewactwk->yposi.w.h = pActwk->yposi.w.h; /* Line 193, Address: 0x1028f9c */

    pNewactwk->xspeed.w = spd_tbl[i]; /* Line 195, Address: 0x1028fac */
    pNewactwk->yspeed.w = spd_tbl[i + 1]; /* Line 196, Address: 0x1028fc0 */
    ((short*)pNewactwk)[26] = spd_tbl[i + 2]; /* Line 197, Address: 0x1028fd8 */
    ((short*)pNewactwk)[27] = spd_tbl[i + 3]; /* Line 198, Address: 0x1028ff0 */
    wD4 += 8; /* Line 199, Address: 0x1029008 */
  } /* Line 200, Address: 0x1029014 */

  if (pActwk->actfree[11]) { /* Line 202, Address: 0x1029024 */
    ride_on_clr(pActwk, &actwk[0]); /* Line 203, Address: 0x1029034 */
  }
  frameout(pActwk); /* Line 205, Address: 0x1029048 */
} /* Line 206, Address: 0x1029054 */








static void hari73_tobi(sprite_status* pActwk) { /* Line 215, Address: 0x1029070 */
  hari_spdadd(pActwk); /* Line 216, Address: 0x102907c */

  ++pActwk->actfree[10]; /* Line 218, Address: 0x1029088 */
  pActwk->actfree[10] &= 3; /* Line 219, Address: 0x1029098 */
  if (pActwk->actfree[10] & 2) { /* Line 220, Address: 0x10290a8 */
    actionsub(pActwk); /* Line 221, Address: 0x10290c0 */
  }
  frameout_s(pActwk); /* Line 223, Address: 0x10290cc */
} /* Line 224, Address: 0x10290d8 */








static short act_search(sprite_status** ppActwk, unsigned char bD0) { /* Line 233, Address: 0x10290f0 */
  int i;


  for (i = 2; i < 128; ++i) { /* Line 237, Address: 0x1029100 */
    if (bD0 == actwk[i].actno) { /* Line 238, Address: 0x102910c */
      *ppActwk = &actwk[i]; /* Line 239, Address: 0x102913c */
      return 0; /* Line 240, Address: 0x102915c */
    }
  } /* Line 242, Address: 0x1029168 */
  return -1; /* Line 243, Address: 0x1029178 */
} /* Line 244, Address: 0x102917c */
