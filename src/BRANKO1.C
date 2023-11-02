#include "EQU.H"
#include "BRANKO1.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "DUMMY.H"
#include "ETC.H"
#include "RIDECHK.H"

spr_array pat0 = {
  1,
  { { -8, -8, 0, 515 } }
};
spr_array pat1 = {
  1,
  { { -8, -8, 0, 516 } }
};
spr_array pat2 = {
  1,
  { { -8, -8, 0, 517 } }
};
spr_array* branko1pat[3] = {
  &pat0,
  &pat1,
  &pat2
};
void(*branko1_move_tbl[2])(act_info*) = {
  &branko1_init,
  &branko1_move
};
brankodata branko1_initbl[8] = {
  { -16384,  8,  512, -512 },
  { -16384,  2,  256, -256 },
  { -16384, -2, -512,  256 },
  { -24576,  3,  384, -384 },
  { -32768, -2, -256,  256 },
  { -32768,  2,  256, -256 },
  { -32768, -1, -256,    0 },
  { -32768,  1,  256,    0 }
};































































void branko1(act_info* pActwk) { /* Line 103, Address: 0x1028580 */
  branko1_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 104, Address: 0x102858c */
  actionsub(pActwk); /* Line 105, Address: 0x10285d0 */
  frameout_s00(pActwk, ((short*)pActwk)[29]); /* Line 106, Address: 0x10285dc */
} /* Line 107, Address: 0x10285f0 */
























void branko1_init(act_info* pActwk) { /* Line 132, Address: 0x1028600 */
  int i;
  unsigned char knum;
  act_info* pNewact;

  pActwk->r_no0 += 2; /* Line 137, Address: 0x1028614 */
  pActwk->actflg |= 4; /* Line 138, Address: 0x1028624 */
  pActwk->sprpri = 3; /* Line 139, Address: 0x1028634 */
  pActwk->patbase = branko1pat; /* Line 140, Address: 0x1028640 */

  pa_set(); /* Line 142, Address: 0x1028650 */

  pActwk->sprhsize = 24; /* Line 144, Address: 0x1028658 */
  pActwk->sprvsize = 8; /* Line 145, Address: 0x1028664 */

  if (pActwk->actfree[18] == 0) { /* Line 147, Address: 0x1028670 */
    ((unsigned short*)pActwk)[29] = pActwk->xposi.w.h; /* Line 148, Address: 0x1028684 */
    ((unsigned short*)pActwk)[27] = pActwk->yposi.w.h; /* Line 149, Address: 0x1028694 */
    pActwk->actfree[5] = i = (unsigned char)(pActwk->userflag.b.h & 15); /* Line 150, Address: 0x10286a4 */

    for ( ; i > 0; --i) { /* Line 152, Address: 0x10286cc */
      if (actwkchk(&pNewact) == 0) { /* Line 153, Address: 0x10286d4 */

        pNewact->actno = 41; /* Line 155, Address: 0x10286e8 */
        ((unsigned short*)pNewact)[29] = ((unsigned short*)pActwk)[29]; /* Line 156, Address: 0x10286f4 */

        ((unsigned short*)pNewact)[27] = ((unsigned short*)pActwk)[27]; /* Line 158, Address: 0x1028704 */

        pNewact->userflag.b.h = pActwk->userflag.b.h; /* Line 160, Address: 0x1028714 */
        pNewact->actfree[5] = pActwk->actfree[5]; /* Line 161, Address: 0x1028724 */
        pNewact->actfree[18] = i; /* Line 162, Address: 0x1028734 */

        if (pActwk->actfree[5] == i) { /* Line 164, Address: 0x102873c */

          pNewact->patno = 1; /* Line 166, Address: 0x1028754 */
        } /* Line 167, Address: 0x1028760 */
        else {
          pNewact->patno = 2; /* Line 169, Address: 0x1028768 */
        }
      }
    } /* Line 172, Address: 0x1028774 */
  }


  knum = (unsigned char)(pActwk->userflag.b.h & 112) >> 4; /* Line 176, Address: 0x1028788 */
  ((short*)pActwk)[31] = branko1_initbl[knum].angle; /* Line 177, Address: 0x10287a8 */
  ((short*)pActwk)[33] = branko1_initbl[knum].accel; /* Line 178, Address: 0x10287c4 */
  ((short*)pActwk)[28] = branko1_initbl[knum].area1; /* Line 179, Address: 0x10287e0 */
  ((short*)pActwk)[30] = branko1_initbl[knum].area2; /* Line 180, Address: 0x10287fc */

  branko1_move(pActwk); /* Line 182, Address: 0x1028818 */
} /* Line 183, Address: 0x1028824 */





void branko1_move(act_info* pActwk) { /* Line 189, Address: 0x1028840 */
  int xwk, ywk;

  xwk = pActwk->xposi.l; /* Line 192, Address: 0x1028854 */
  ywk = pActwk->yposi.l; /* Line 193, Address: 0x102885c */
  branko1_posiset(pActwk); /* Line 194, Address: 0x1028864 */
  if (pActwk->actfree[5] == pActwk->actfree[18]) { /* Line 195, Address: 0x1028870 */
    pActwk->xspeed.w = (pActwk->xposi.l - xwk) >> 8; /* Line 196, Address: 0x1028890 */
    pActwk->yspeed.w = (pActwk->yposi.l - ywk) >> 8; /* Line 197, Address: 0x10288b0 */
    branko1_ridechk(pActwk); /* Line 198, Address: 0x10288d0 */
  }
} /* Line 200, Address: 0x10288dc */












/* TODO: lines 245 & 246: Why shift 4 bytes right two times? */
void branko1_posiset(act_info* pActwk) { /* Line 214, Address: 0x1028900 */
  short spdwk, sinwk, coswk;
  unsigned int lSinwk, lCoswk;
  ushort_union direc;

  if (pActwk->actfree[19] == 0) { /* Line 219, Address: 0x1028918 */
    spdwk = ((short*)pActwk)[26] + ((short*)pActwk)[33]; /* Line 220, Address: 0x102892c */

    ((short*)pActwk)[26] = spdwk; /* Line 222, Address: 0x1028960 */
    ((short*)pActwk)[31] += spdwk; /* Line 223, Address: 0x1028968 */
    if (((short*)pActwk)[28] == spdwk) { /* Line 224, Address: 0x1028978 */
      pActwk->actfree[19] = 255; /* Line 225, Address: 0x1028998 */
    }
  } /* Line 227, Address: 0x10289a4 */
  else {
    spdwk = ((short*)pActwk)[26] - ((short*)pActwk)[33]; /* Line 229, Address: 0x10289ac */

    ((short*)pActwk)[26] = spdwk; /* Line 231, Address: 0x10289e0 */
    ((short*)pActwk)[31] += spdwk; /* Line 232, Address: 0x10289e8 */
    if (((short*)pActwk)[30] == spdwk) { /* Line 233, Address: 0x10289f8 */
      pActwk->actfree[19] = 0; /* Line 234, Address: 0x1028a18 */
    }
  }



  direc.w = ((unsigned short*)pActwk)[31]; /* Line 240, Address: 0x1028a20 */
  sinset(direc.b.h, &sinwk, &coswk); /* Line 241, Address: 0x1028a2c */
  spdwk = ((char*)pActwk)[64] << 4; /* Line 242, Address: 0x1028a40 */
  lSinwk = sinwk * spdwk; /* Line 243, Address: 0x1028a6c */
  lCoswk = coswk * spdwk; /* Line 244, Address: 0x1028a84 */
  sinwk = (short)((int)lSinwk >> 4) >> 4; /* Line 245, Address: 0x1028a9c */
  coswk = (short)((int)lCoswk >> 4) >> 4; /* Line 246, Address: 0x1028ac0 */
  pActwk->yposi.w.h = coswk + ((short*)pActwk)[27]; /* Line 247, Address: 0x1028ae4 */
  pActwk->xposi.w.h = sinwk + ((short*)pActwk)[29]; /* Line 248, Address: 0x1028b14 */
} /* Line 249, Address: 0x1028b44 */










void branko1_ridechk(act_info* pActwk) { /* Line 260, Address: 0x1028b60 */
  act_info* pPlayerwk;
  int i;

  for (i = 0, pPlayerwk = &actwk[0]; i < 2; ++i) {  ; /* Line 264, Address: 0x1028b74 */
    pActwk->sprvsize = 8; /* Line 265, Address: 0x1028b88 */


    if (ridechk(pActwk, pPlayerwk) == 0) { /* Line 268, Address: 0x1028b94 */
      pActwk->sprvsize = 12; /* Line 269, Address: 0x1028bb4 */

      if (ridechk(pActwk, pPlayerwk) == 0) goto label1; /* Line 271, Address: 0x1028bc0 */
    }




    pActwk->sprvsize = 8; /* Line 277, Address: 0x1028be0 */
    if (pActwk->yposi.w.h >= pPlayerwk->yposi.w.h) { /* Line 278, Address: 0x1028bec */



      pPlayerwk->yposi.w.h = pActwk->yposi.w.h - ((char*)pActwk)[23] - ((char*)pPlayerwk)[23] + 2; /* Line 282, Address: 0x1028c14 */
    }





label1:
    pActwk->sprvsize = 8; /* Line 290, Address: 0x1028c68 */
    pPlayerwk = &actwk[1]; /* Line 291, Address: 0x1028c74 */
  } /* Line 292, Address: 0x1028c7c */
} /* Line 293, Address: 0x1028c8c */
