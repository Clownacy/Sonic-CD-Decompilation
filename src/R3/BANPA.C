#include "..\EQU.H"
#include "BANPA.H"

static sprite_pattern bmp00 = {
  1,
  { { 224, 240, 0, 315 } }
};
sprite_pattern* banpa_pat[1] = { &bmp00 };





















void banpa(sprite_status* bumperwk) { /* Line 30, Address: 0x101a590 */
  void(*act_tbl[2])(sprite_status*) = { &act_init, &act_move }; /* Line 31, Address: 0x101a59c */

  act_tbl[bumperwk->r_no0 / 2](bumperwk); /* Line 33, Address: 0x101a5b8 */
  actionsub(bumperwk); /* Line 34, Address: 0x101a5f4 */
  frameout_s00(bumperwk, ((short*)bumperwk)[33]); /* Line 35, Address: 0x101a600 */
} /* Line 36, Address: 0x101a614 */



static void act_init(sprite_status* bumperwk) { /* Line 40, Address: 0x101a630 */
  ((short*)bumperwk)[33] = bumperwk->xposi.w.h; /* Line 41, Address: 0x101a638 */

  bumperwk->r_no0 += 2; /* Line 43, Address: 0x101a648 */
  bumperwk->patbase = banpa_pat; /* Line 44, Address: 0x101a658 */

  bumperwk->actflg = 4; /* Line 46, Address: 0x101a668 */
  bumperwk->sprhsize = 32; /* Line 47, Address: 0x101a674 */
  bumperwk->sprvsize = 16; /* Line 48, Address: 0x101a680 */
  bumperwk->sprpri = 1; /* Line 49, Address: 0x101a68c */
  bumperwk->colino = 231; /* Line 50, Address: 0x101a698 */

  ((short*)bumperwk)[26] = 192; /* Line 52, Address: 0x101a6a4 */
  ((short*)bumperwk)[25] = 96; /* Line 53, Address: 0x101a6b0 */
  if (!((unsigned char)bumperwk->userflag.b.h & 128)) { /* Line 54, Address: 0x101a6bc */
    ((short*)bumperwk)[26] = 160; /* Line 55, Address: 0x101a6d8 */
    ((short*)bumperwk)[25] = 80; /* Line 56, Address: 0x101a6e4 */
  }
  if (bumperwk->userflag.b.h & 64) /* Line 58, Address: 0x101a6f0 */
    *(int*)&bumperwk->actfree[0] = 1; /* Line 59, Address: 0x101a70c */
  else
    *(int*)&bumperwk->actfree[0] = -1; /* Line 61, Address: 0x101a724 */
} /* Line 62, Address: 0x101a734 */



static void act_move(sprite_status* bumperwk) { /* Line 66, Address: 0x101a740 */
  if (bumperwk->colicnt != 0) { /* Line 67, Address: 0x101a74c */
    if ((char)bumperwk->actflg < 0) soundset(181); /* Line 68, Address: 0x101a760 */

    bumperwk->colicnt = 0; /* Line 70, Address: 0x101a78c */


    if ((unsigned short)(actwk[0].yposi.w.h - bumperwk->yposi.w.h + 8) < 16) { /* Line 73, Address: 0x101a794 */
      actwk[0].xspeed.w = 0; /* Line 74, Address: 0x101a7d0 */
    } /* Line 75, Address: 0x101a7d8 */
    else {


      if ((unsigned short)(actwk[0].xposi.w.h - bumperwk->xposi.w.h + 24) < 48) { /* Line 79, Address: 0x101a7e0 */
        if (actwk[0].yposi.w.h >= bumperwk->yposi.w.h) /* Line 80, Address: 0x101a81c */
          actwk[0].yspeed.w = 1792; /* Line 81, Address: 0x101a848 */
        else
          actwk[0].yspeed.w = -1792; /* Line 83, Address: 0x101a85c */
      } /* Line 84, Address: 0x101a868 */
      else {

        if (actwk[0].xposi.w.h >= bumperwk->xposi.w.h) actwk[0].xspeed.w = 1267; /* Line 87, Address: 0x101a870 */
        else actwk[0].xspeed.w = -1267; /* Line 88, Address: 0x101a8b0 */
        if (actwk[0].yposi.w.h >= bumperwk->yposi.w.h) actwk[0].yspeed.w = 1267; /* Line 89, Address: 0x101a8bc */
        else actwk[0].yspeed.w = -1267; /* Line 90, Address: 0x101a8fc */
      }

      actwk[0].cddat |= 2; /* Line 93, Address: 0x101a908 */
      actwk[0].cddat &= 207; /* Line 94, Address: 0x101a91c */
    }
  }
  if (bumperwk->userflag.b.h < 0) /* Line 97, Address: 0x101a930 */
    bumperwk->xposi.l += *(int*)&bumperwk->actfree[0]; /* Line 98, Address: 0x101a948 */
  else
    bumperwk->yposi.l += *(int*)&bumperwk->actfree[0]; /* Line 100, Address: 0x101a96c */

  if (--((unsigned short*)bumperwk)[25] == 0) { /* Line 102, Address: 0x101a988 */
    ((unsigned short*)bumperwk)[25] = ((unsigned short*)bumperwk)[26]; /* Line 103, Address: 0x101a9a8 */

    *(int*)&bumperwk->actfree[0] = -*(int*)&bumperwk->actfree[0]; /* Line 105, Address: 0x101a9b8 */
  }
} /* Line 107, Address: 0x101a9d0 */
