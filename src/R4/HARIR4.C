#include "..\EQU.H"
#include "HARIR4.H"

sprite_pattern harir4_pat0 = {
  1,
  { { -16, -16, 0, 443 } }
};
sprite_pattern harir4_pat1 = {
  1,
  { { -16, -16, 0, 444 } }
};
sprite_pattern* harir4pat[2] = {
  &harir4_pat0,
  &harir4_pat1
};




























































void harir4(sprite_status* pActwk) { /* Line 76, Address: 0x101d940 */
  sprite_status* pRideactwk;

  void(*harir4_acttbl[2])(sprite_status*) = { /* Line 79, Address: 0x101d950 */
    &harir4_init,
    &harir4_move
  };

  harir4_acttbl[pActwk->r_no0 / 2](pActwk); /* Line 84, Address: 0x101d96c */
  actionsub(pActwk); /* Line 85, Address: 0x101d9a8 */


  if (((short*)pActwk)[28]) { /* Line 88, Address: 0x101d9b4 */
    pRideactwk = &actwk[((short*)pActwk)[28]]; /* Line 89, Address: 0x101d9c4 */
    if (!pRideactwk->actno) { /* Line 90, Address: 0x101d9ec */
      frameout(pActwk); /* Line 91, Address: 0x101d9f8 */
    } /* Line 92, Address: 0x101da04 */
    else {

      pActwk->xposi.w.h = pRideactwk->xposi.w.h + pActwk->actfree[14]; /* Line 95, Address: 0x101da0c */
      pActwk->yposi.w.h = pRideactwk->yposi.w.h + pActwk->actfree[15]; /* Line 96, Address: 0x101da40 */
    }
  }
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 99, Address: 0x101da74 */
} /* Line 100, Address: 0x101da88 */








void harir4_ridechk(sprite_status* pActwk) { /* Line 109, Address: 0x101daa0 */
  if (pActwk->patno) { /* Line 110, Address: 0x101daac */
    hitchk(pActwk, &actwk[0]); /* Line 111, Address: 0x101dabc */
    return; /* Line 112, Address: 0x101dad0 */
  }


  if (hitchk(pActwk, &actwk[0]) != 0) { /* Line 116, Address: 0x101dad8 */
    if (pActwk->cddat & 8) { /* Line 117, Address: 0x101daf4 */
      if (!plpower_a) { /* Line 118, Address: 0x101db0c */
        if (!plpower_m) { /* Line 119, Address: 0x101db1c */
          if (actwk[0].r_no0 < 4) { /* Line 120, Address: 0x101db2c */
            if (!((short*)&actwk[0])[26]) { /* Line 121, Address: 0x101db44 */
              actwk[0].yposi.l -= actwk[0].yspeed.w << 8; /* Line 122, Address: 0x101db54 */
              playdamageset(&actwk[0], pActwk); /* Line 123, Address: 0x101db7c */
            }
          }
        }
      }
    }
  }


} /* Line 132, Address: 0x101db90 */








void harir4_init(sprite_status* pActwk) { /* Line 141, Address: 0x101dba0 */
  pActwk->r_no0 += 2; /* Line 142, Address: 0x101dbac */
  pActwk->actflg |= 4; /* Line 143, Address: 0x101dbbc */
  pActwk->sproffset = 928; /* Line 144, Address: 0x101dbcc */
  pActwk->sprpri = 4; /* Line 145, Address: 0x101dbd8 */
  pActwk->patbase = harir4pat; /* Line 146, Address: 0x101dbe4 */
  if (!((short*)pActwk)[29]) { /* Line 147, Address: 0x101dbf4 */
    ((short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 148, Address: 0x101dc04 */
  }
  ((short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 150, Address: 0x101dc14 */
  pActwk->sprhsize = 18; /* Line 151, Address: 0x101dc24 */
  pActwk->sprvsize = 12; /* Line 152, Address: 0x101dc30 */
  if (pActwk->userflag.b.h) { /* Line 153, Address: 0x101dc3c */
    pActwk->patno = 1; /* Line 154, Address: 0x101dc4c */
    pActwk->colino = 131; /* Line 155, Address: 0x101dc58 */
  }

  harir4_move(pActwk); /* Line 158, Address: 0x101dc64 */
} /* Line 159, Address: 0x101dc70 */








void harir4_move(sprite_status* pActwk) { /* Line 168, Address: 0x101dc80 */
  if (pActwk->userflag.b.h != 1) { /* Line 169, Address: 0x101dc8c */
    harir4_sub(pActwk); /* Line 170, Address: 0x101dca8 */
    pActwk->yposi.w.h = pActwk->actfree[17] + ((short*)pActwk)[27]; /* Line 171, Address: 0x101dcb4 */
  }

  harir4_ridechk(pActwk); /* Line 174, Address: 0x101dce4 */
} /* Line 175, Address: 0x101dcf0 */








void harir4_sub(sprite_status* pActwk) { /* Line 184, Address: 0x101dd00 */
  if (pActwk->actfree[16]) { /* Line 185, Address: 0x101dd0c */
    if (--pActwk->actfree[16]) return; /* Line 186, Address: 0x101dd1c */
    if (pActwk->actflg & 128) soundset(183); /* Line 187, Address: 0x101dd38 */
  }

  if (pActwk->actfree[18]) { /* Line 190, Address: 0x101dd5c */


    if (pActwk->actfree[17] < 8) { /* Line 193, Address: 0x101dd6c */
      pActwk->actfree[17] = 0; /* Line 194, Address: 0x101dd84 */
      pActwk->actfree[18] = 0; /* Line 195, Address: 0x101dd8c */
      pActwk->actfree[16] = 60; /* Line 196, Address: 0x101dd94 */
    } /* Line 197, Address: 0x101dda0 */
    else pActwk->actfree[17] -= 8; /* Line 198, Address: 0x101dda8 */
  } /* Line 199, Address: 0x101ddb8 */
  else {
    if ((char)(pActwk->actfree[17] += 8) >= 32) { /* Line 201, Address: 0x101ddc0 */
      pActwk->actfree[17] = 32; /* Line 202, Address: 0x101ddf0 */
      pActwk->actfree[18] = 1; /* Line 203, Address: 0x101ddfc */
      pActwk->actfree[16] = 60; /* Line 204, Address: 0x101de08 */
    }
  }
} /* Line 207, Address: 0x101de14 */
