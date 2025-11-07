#include "..\..\TYPES.H"
#include "LPL_TYPES.H"
#include "SPM_EQU.H"
#include "ASCIISET.H"
#include "ACTM.H"

static void ascchk(sprite_status_lpl* pActwk);
static void set_music(sprite_status_lpl* pActwk);
static void ascset(sprite_status_lpl* pActwk);
static void ascchg(sprite_status_lpl* pActwk);
static void ascspr_init(sprite_status_lpl* pActwk, sprite_status_lpl* pAscwk);
static void ascspr_set(sprite_status_lpl* pActwk, sprite_status_lpl* pAscwk);
static void ascspr_chk(sprite_status_lpl* pActwk, sprite_status_lpl* pAscwk);
static void ascspr_exit(sprite_status_lpl* pActwk, sprite_status_lpl* pAscwk);

static unsigned char bit_SPACE;
static unsigned char space_flg;
extern short ascii_xposi_tbl[];
extern sprite_patterns_title* asciispr_tbl[];










































void sprascii(void) { /* Line 62, Address: 0x10005d0 */
  sprite_status_lpl* pAsciiWk;
  static void(*ascsprtbl[3])(sprite_status_lpl*) = {
    &ascchk,
    &ascset,
    &ascchg
  };



  bit_SPACE = 0; /* Line 72, Address: 0x10005dc */

  pAsciiWk = &actwk[17]; /* Line 74, Address: 0x10005e4 */
  ascsprtbl[pAsciiWk->ACT_NO](pAsciiWk); /* Line 75, Address: 0x10005ec */
} /* Line 76, Address: 0x1000614 */






static void ascchk(sprite_status_lpl* pActwk) { /* Line 83, Address: 0x1000630 */
  if (!(swdata1.b.h & 32)) { /* Line 84, Address: 0x100063c */


    if (push_flg & 32) { /* Line 87, Address: 0x1000654 */

      if (!(music_selflg & 1)) { /* Line 89, Address: 0x100066c */

        push_flg &= 223; /* Line 91, Address: 0x1000684 */
      } /* Line 92, Address: 0x1000698 */
      else if (!(music_selflg & 4)) { /* Line 93, Address: 0x10006a0 */

        push_flg &= 223; /* Line 95, Address: 0x10006b8 */
        set_music(pActwk); /* Line 96, Address: 0x10006cc */
        return; /* Line 97, Address: 0x10006d8 */
      }
    }
  }
  else {

    push_flg |= 32; /* Line 103, Address: 0x10006e0 */
  }

  if (!(swdata1.b.h & 16)) { /* Line 106, Address: 0x10006f4 */

    if (push_flg & 16) { /* Line 108, Address: 0x100070c */

      if (!(music_selflg & 1)) { /* Line 110, Address: 0x1000724 */
        push_flg &= 239; /* Line 111, Address: 0x100073c */
      } /* Line 112, Address: 0x1000750 */
      else if (!(music_selflg & 4)) { /* Line 113, Address: 0x1000758 */

        push_flg &= 239; /* Line 115, Address: 0x1000770 */
        set_music(pActwk); /* Line 116, Address: 0x1000784 */
        return; /* Line 117, Address: 0x1000790 */
      }
    }
  }
  else {

    push_flg |= 16; /* Line 123, Address: 0x1000798 */
  }

  if (!(swdata1.b.h & 64)) { /* Line 126, Address: 0x10007ac */


    if (push_flg & 64) { /* Line 129, Address: 0x10007c4 */

      if (!(music_selflg & 1)) { /* Line 131, Address: 0x10007dc */

        music_selflg |= 1; /* Line 133, Address: 0x10007f4 */
        music_selflg |= 4; /* Line 134, Address: 0x1000808 */
        push_flg &= 191; /* Line 135, Address: 0x100081c */
      } /* Line 136, Address: 0x1000830 */
      else if (!(music_selflg & 4)) { /* Line 137, Address: 0x1000838 */

        push_flg &= 191; /* Line 139, Address: 0x1000850 */
        set_music(pActwk); /* Line 140, Address: 0x1000864 */
        return; /* Line 141, Address: 0x1000870 */
      }
    }
    if (music_selflg & 4) { /* Line 144, Address: 0x1000878 */

      if (chk_actwk() == 0) { /* Line 146, Address: 0x1000890 */

        comflag_m |= 16; /* Line 148, Address: 0x10008a0 */
        music_selflg &= 251; /* Line 149, Address: 0x10008b4 */
        pActwk->ACT_NO = 1; /* Line 150, Address: 0x10008c8 */
      }
    }

  } /* Line 154, Address: 0x10008d4 */
  else {

    push_flg |= 64; /* Line 157, Address: 0x10008dc */
  }


  if (bit_SPACE == 0) { /* Line 161, Address: 0x10008f0 */

    if (space_flg & 1) { /* Line 163, Address: 0x1000904 */

      if (!(music_selflg & 1)) { /* Line 165, Address: 0x100091c */

        music_selflg |= 1; /* Line 167, Address: 0x1000934 */
        music_selflg |= 4; /* Line 168, Address: 0x1000948 */
        space_flg = 0; /* Line 169, Address: 0x100095c */
      } /* Line 170, Address: 0x1000964 */
      else if (!(music_selflg & 4)) { /* Line 171, Address: 0x100096c */

        space_flg = 0; /* Line 173, Address: 0x1000984 */
        set_music(pActwk); /* Line 174, Address: 0x100098c */
        return; /* Line 175, Address: 0x1000998 */
      }
    }
    if (music_selflg & 4) { /* Line 178, Address: 0x10009a0 */

      if (chk_actwk() == 0) { /* Line 180, Address: 0x10009b8 */

        comflag_m |= 16; /* Line 182, Address: 0x10009c8 */
        music_selflg &= 251; /* Line 183, Address: 0x10009dc */
        pActwk->ACT_NO = 1; /* Line 184, Address: 0x10009f0 */
      }
    }
  } /* Line 187, Address: 0x10009fc */
  else {

    space_flg |= 1; /* Line 190, Address: 0x1000a04 */
  }



} /* Line 195, Address: 0x1000a18 */






static void set_music(sprite_status_lpl* pActwk) { /* Line 202, Address: 0x1000a30 */
  short MusicNo, PlanetNo;

  actset_flg = 0; /* Line 205, Address: 0x1000a40 */
  MusicNo = pActwk->EXE_NO; /* Line 206, Address: 0x1000a48 */
  comdata_m4 = MusicNo; /* Line 207, Address: 0x1000a58 */
  PlanetNo = ascii_xposi_tbl[MusicNo * 2]; /* Line 208, Address: 0x1000a60 */
  if (PlanetNo != 3) lplanet_no = PlanetNo; /* Line 209, Address: 0x1000a88 */
  comdata_m5 = PlanetNo; /* Line 210, Address: 0x1000aa4 */
  comflag_m &= 239; /* Line 211, Address: 0x1000aac */
  comflag_m |= 32; /* Line 212, Address: 0x1000ac0 */

} /* Line 214, Address: 0x1000ad4 */






static void ascset(sprite_status_lpl* pActwk) { /* Line 221, Address: 0x1000af0 */
  sprite_status_lpl* pFreeAct;

  if (get_actwk(&pFreeAct) == 0) { /* Line 224, Address: 0x1000afc */

    pActwk->XPOSI.w.h = pFreeAct - actwk; /* Line 226, Address: 0x1000b10 */
    music_selflg |= 2; /* Line 227, Address: 0x1000b48 */
    pActwk->ACT_NO = 2; /* Line 228, Address: 0x1000b5c */
  }

} /* Line 231, Address: 0x1000b68 */






static void ascchg(sprite_status_lpl* pActwk) { /* Line 238, Address: 0x1000b80 */

} /* Line 240, Address: 0x1000b84 */






void set_asciicg(void) { /* Line 247, Address: 0x1000b90 */
  sprite_status_lpl* pStringwk;

  if (music_selflg & 2) { /* Line 250, Address: 0x1000b98 */

    pStringwk = &actwk[actwk[17].XPOSI.w.h]; /* Line 252, Address: 0x1000bb0 */
    pStringwk->ACT_NO = 7; /* Line 253, Address: 0x1000bd8 */
    music_selflg &= 253; /* Line 254, Address: 0x1000be0 */
    if (!(actset_flg & 1)) { /* Line 255, Address: 0x1000bf4 */

      actset_flg |= 1; /* Line 257, Address: 0x1000c0c */
      pStringwk->ACT_FLG = 1; /* Line 258, Address: 0x1000c20 */
      return; /* Line 259, Address: 0x1000c28 */
    }

    pStringwk->ACT_FLG = 2; /* Line 262, Address: 0x1000c30 */
    actset_flg |= 2; /* Line 263, Address: 0x1000c38 */
  }


} /* Line 267, Address: 0x1000c4c */






void ascii_sprite(sprite_status_lpl* pActwk) { /* Line 274, Address: 0x1000c60 */
  static void(*acttbl[4])(sprite_status_lpl*, sprite_status_lpl*) = {
    &ascspr_init,
    &ascspr_set,
    &ascspr_chk,
    &ascspr_exit
  };

  acttbl[pActwk->EXE_NO](pActwk, &actwk[17]); /* Line 282, Address: 0x1000c6c */

} /* Line 284, Address: 0x1000ca0 */







static void ascspr_init(sprite_status_lpl* pActwk, sprite_status_lpl* pAscwk) { /* Line 292, Address: 0x1000cb0 */
  pActwk->PAT_NO = 0; /* Line 293, Address: 0x1000cbc */
  pActwk->PAT_ADR = asciispr_tbl[pAscwk->EXE_NO]; /* Line 294, Address: 0x1000cc4 */
  if (pAscwk->XPOSI.b.b3 & 1) { /* Line 295, Address: 0x1000cec */

    pActwk->XPOSI.w.h = -128; /* Line 297, Address: 0x1000d08 */
    pActwk->X_SPEED.l = 0x200000; /* Line 298, Address: 0x1000d14 */
    pActwk->SPR_FLG |= 8; /* Line 299, Address: 0x1000d20 */
  } /* Line 300, Address: 0x1000d30 */
  else {

    pActwk->XPOSI.w.h = 256; /* Line 303, Address: 0x1000d38 */
    pActwk->X_SPEED.l = -0x200000; /* Line 304, Address: 0x1000d44 */
    pActwk->SPR_FLG &= 247; /* Line 305, Address: 0x1000d50 */
  }
  pActwk->SPR_FLG |= 32; /* Line 307, Address: 0x1000d60 */
  pActwk->YPOSI.w.h = 208; /* Line 308, Address: 0x1000d70 */
  pActwk->X_OFFSET = ascii_xposi_tbl[pAscwk->EXE_NO * 2 + 1]; /* Line 309, Address: 0x1000d7c */
  pActwk->CGBASE -= 8192; /* Line 310, Address: 0x1000dac */
  pActwk->EXE_NO = 1; /* Line 311, Address: 0x1000dbc */
  pAscwk->ACT_NO = 0; /* Line 312, Address: 0x1000dc8 */

} /* Line 314, Address: 0x1000dd0 */







static void ascspr_set(sprite_status_lpl* pActwk, sprite_status_lpl* pAscwk) { /* Line 322, Address: 0x1000de0 */
  pActwk->XPOSI.l += pActwk->X_SPEED.l; /* Line 323, Address: 0x1000de8 */
  if (!(pActwk->SPR_FLG & 8) && pActwk->XPOSI.w.h < pActwk->X_OFFSET /* Line 324, Address: 0x1000e00 */
      || (pActwk->SPR_FLG & 8) && pActwk->XPOSI.w.h >= pActwk->X_OFFSET) {

    pActwk->X_SPEED.l = 0; /* Line 327, Address: 0x1000e88 */
    pActwk->XPOSI.w.h = pActwk->X_OFFSET; /* Line 328, Address: 0x1000e90 */
    pActwk->EXE_NO = 2; /* Line 329, Address: 0x1000ea0 */
  }

} /* Line 332, Address: 0x1000eac */







static void ascspr_chk(sprite_status_lpl* pActwk, sprite_status_lpl* pAscwk) { /* Line 340, Address: 0x1000ec0 */
  if (swdata1.b.h & 8) { /* Line 341, Address: 0x1000ec8 */

    pActwk->EXE_NO = 3; /* Line 343, Address: 0x1000ee0 */
    pActwk->X_SPEED.l = 0x200000; /* Line 344, Address: 0x1000eec */
    pActwk->SPR_FLG |= 8; /* Line 345, Address: 0x1000ef8 */
  }
  if (swdata1.b.h & 4) { /* Line 347, Address: 0x1000f08 */

    pActwk->X_SPEED.l = -0x200000; /* Line 349, Address: 0x1000f20 */
    pActwk->EXE_NO = 3; /* Line 350, Address: 0x1000f2c */
    pActwk->SPR_FLG &= 247; /* Line 351, Address: 0x1000f38 */
  }

} /* Line 354, Address: 0x1000f48 */







static void ascspr_exit(sprite_status_lpl* pActwk, sprite_status_lpl* pAscwk) { /* Line 362, Address: 0x1000f60 */
  pActwk->XPOSI.l += pActwk->X_SPEED.l; /* Line 363, Address: 0x1000f6c */
  if (!(pActwk->SPR_FLG & 8)) { /* Line 364, Address: 0x1000f84 */

    if (pActwk->XPOSI.w.h < -127) { /* Line 366, Address: 0x1000f9c */

      music_selflg |= 4; /* Line 368, Address: 0x1000fb8 */
      pAscwk->XPOSI.b.b3 &= -2; /* Line 369, Address: 0x1000fcc */
      actset_flg ^= pActwk->ACT_FLG; /* Line 370, Address: 0x1000fe0 */
      pActwk->SPR_FLG |= 16; /* Line 371, Address: 0x1000ffc */
      if (++pAscwk->EXE_NO > 31) pAscwk->EXE_NO = 0; /* Line 372, Address: 0x100100c */
    }
  } /* Line 374, Address: 0x1001038 */
  else {

    if (pActwk->XPOSI.w.h >= 288) { /* Line 377, Address: 0x1001040 */

      music_selflg |= 4; /* Line 379, Address: 0x100105c */
      pAscwk->XPOSI.b.b3 |= 1; /* Line 380, Address: 0x1001070 */
      actset_flg ^= pActwk->ACT_FLG; /* Line 381, Address: 0x1001080 */
      pActwk->SPR_FLG |= 16; /* Line 382, Address: 0x100109c */
      if ((short)--pAscwk->EXE_NO < 0) pAscwk->EXE_NO = 31; /* Line 383, Address: 0x10010ac */
    }
  }

} /* Line 387, Address: 0x10010e4 */
