#include "..\EQU.H"
#include "IWA5ROLL.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\RIDECHK.H"

static void iwa5roll_init(sprite_status* pActwk);
static void iwa5roll_move(sprite_status* pActwk);

static sprite_pattern pat_iwa5roll_00 = {
  1,
  { { -8, -8, 0, 429 } }
};
sprite_pattern* pat_iwa5roll[1] = { &pat_iwa5roll_00 };






















































void iwa5roll(sprite_status* pActwk) { /* Line 70, Address: 0x1026550 */
  if (pActwk->r_no0) iwa5roll_move(pActwk); /* Line 71, Address: 0x102655c */
  else iwa5roll_init(pActwk); /* Line 72, Address: 0x1026580 */
} /* Line 73, Address: 0x102658c */








static void iwa5roll_init(sprite_status* pActwk) { /* Line 82, Address: 0x10265a0 */
  sprite_status* pNewactwk;
  short wD1, wD3, wD4, wD5, wD6;
  short wA5;
  short iwa5roll_tbl[6] = { /* Line 86, Address: 0x10265c4 */
    128, 1,
    192, 1,
    256, 1
  };

  wD1 = iwa5roll_tbl[time_flag * 2]; /* Line 92, Address: 0x10265f8 */
  wA5 = iwa5roll_tbl[time_flag * 2 + 1]; /* Line 93, Address: 0x102661c */
  if (pActwk->userflag.b.h) wD1 *= -1; /* Line 94, Address: 0x1026644 */

  ((short*)pActwk)[29] = wD1; /* Line 96, Address: 0x1026660 */

  wD6 = 3; /* Line 98, Address: 0x1026668 */
  wD5 = 0; /* Line 99, Address: 0x1026674 */
  wD4 = 0; /* Line 100, Address: 0x1026678 */
  wD3 = 0; /* Line 101, Address: 0x102667c */
  pNewactwk = pActwk; /* Line 102, Address: 0x1026680 */
  goto label1; /* Line 103, Address: 0x1026688 */


  do {
    wD5 = 0;  /* Line 107, Address: 0x1026690 */
    wD3 = wD4; /* Line 108, Address: 0x1026694 */

    do {
      if (actwkchk(&pNewactwk) != 0) break; /* Line 111, Address: 0x102669c */


label1:
      ((short*)pNewactwk)[23] = pActwk - actwk; /* Line 115, Address: 0x10266b0 */
      pNewactwk->actflg |= 4; /* Line 116, Address: 0x10266e8 */
      pNewactwk->r_no0 = 2; /* Line 117, Address: 0x10266f8 */
      pNewactwk->sprpri = 3; /* Line 118, Address: 0x1026704 */
      pNewactwk->sprhs = 8; /* Line 119, Address: 0x1026710 */
      pNewactwk->sprhsize = 8; /* Line 120, Address: 0x102671c */
      pNewactwk->sprvsize = 8; /* Line 121, Address: 0x1026728 */
      pNewactwk->sproffset = 17152; /* Line 122, Address: 0x1026734 */
      pNewactwk->patbase = pat_iwa5roll; /* Line 123, Address: 0x1026740 */
      pNewactwk->actno = pActwk->actno; /* Line 124, Address: 0x1026750 */
      pNewactwk->xposi.w.h = pActwk->xposi.w.h; /* Line 125, Address: 0x1026760 */
      pNewactwk->yposi.w.h = pActwk->yposi.w.h; /* Line 126, Address: 0x1026770 */
      ((int*)pNewactwk)[12] = pActwk->xposi.l; /* Line 127, Address: 0x1026780 */
      ((int*)pNewactwk)[13] = pActwk->yposi.l; /* Line 128, Address: 0x1026790 */
      ((short*)pNewactwk)[29] = ((short*)pActwk)[29]; /* Line 129, Address: 0x10267a0 */

      ((short*)pNewactwk)[28] = wD3; /* Line 131, Address: 0x10267b0 */
      wD3 += 2048; /* Line 132, Address: 0x10267b8 */
    } while (++wD5 <= wA5); /* Line 133, Address: 0x10267c4 */
    wD4 += 16384; /* Line 134, Address: 0x10267f4 */
  } while (--wD6 >= 0); /* Line 135, Address: 0x1026800 */


  ((short*)pActwk)[23] = 0; /* Line 138, Address: 0x1026824 */
} /* Line 139, Address: 0x102682c */








static void iwa5roll_move(sprite_status* pActwk) { /* Line 148, Address: 0x1026860 */
  unsigned char bD0;
  short Sp;
  unsigned short Sin, Cos;
  int_union lD0, lD1;
  int_union lD4, lD5;
  int lD3;

  if (((short*)pActwk)[23]) { /* Line 156, Address: 0x1026878 */
    if (actwk[((short*)pActwk)[23]].actno != 39) { /* Line 157, Address: 0x1026888 */
      frameout(pActwk); /* Line 158, Address: 0x10268c4 */
      return; /* Line 159, Address: 0x10268d0 */
    }
  }

  ((short*)pActwk)[28] += ((short*)pActwk)[29]; /* Line 163, Address: 0x10268d8 */
  lD1.l = 0; /* Line 164, Address: 0x10268f0 */
  lD0.l = 0; /* Line 165, Address: 0x10268f4 */
  sinset(pActwk->actfree[11], (short*)&Sin, (short*)&Cos); /* Line 166, Address: 0x10268f8 */
  lD1.w.h = Cos; /* Line 167, Address: 0x1026910 */
  lD0.w.h = Sin; /* Line 168, Address: 0x1026918 */
  lD5.l = lD1.l / 4 + lD1.l / 8; /* Line 169, Address: 0x1026920 */
  lD4.l = lD0.l / 4 + lD0.l / 8; /* Line 170, Address: 0x1026960 */
  lD5.l += ((int*)pActwk)[12]; /* Line 171, Address: 0x10269a0 */
  lD4.l += ((int*)pActwk)[13]; /* Line 172, Address: 0x10269b4 */
  lD3 = pActwk->xposi.l; /* Line 173, Address: 0x10269c8 */
  pActwk->xposi.l = lD5.l; /* Line 174, Address: 0x10269d0 */
  pActwk->yposi.l = lD4.l; /* Line 175, Address: 0x10269dc */
  lD5.l = lD5.l - lD3 >> 8; /* Line 176, Address: 0x10269e8 */
  pActwk->xspeed.w = lD5.w.l; /* Line 177, Address: 0x10269f8 */

  Sp = pActwk->xspeed.w; /* Line 179, Address: 0x1026a04 */
  pActwk->xspeed.w = 0; /* Line 180, Address: 0x1026a14 */
  pActwk->sprvsize = 10; /* Line 181, Address: 0x1026a1c */
  if (hitchk(pActwk, &actwk[0])) bD0 = 255; /* Line 182, Address: 0x1026a28 */
  else bD0 = 0; /* Line 183, Address: 0x1026a54 */
  pActwk->xspeed.w = Sp; /* Line 184, Address: 0x1026a58 */
  pActwk->sprvsize = 8; /* Line 185, Address: 0x1026a60 */
  if (bD0) hitchk(pActwk, &actwk[0]); /* Line 186, Address: 0x1026a6c */

  actionsub(pActwk); /* Line 188, Address: 0x1026a88 */

  if (!((short*)pActwk)[23]) { /* Line 190, Address: 0x1026a94 */
    frameout_s00(pActwk, ((short*)pActwk)[25]); /* Line 191, Address: 0x1026aa4 */
  }
} /* Line 193, Address: 0x1026ab8 */
